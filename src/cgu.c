/* core clock initialization procedure (UM10503: page 167)

   - select IRC as the BASE_M4_CLK source
   - enable the crystal oscillator
   - wait 250 µs
   - set the AUTOBLOCK bit
   - reconfigure PLL1
     - select the M and N divider values for the desired output freq
     - select the crystal oscillator as the clock source for PLL1
   - wait for PLL1 to lock
   - set PLL1 P-divider to divide-by-2 (DIRECT=0, PSEL=0)
   - select PLL1 as BASE_M4_CLK source
   - wait 50 µs
   - set the PLL1 P-divider to direct output mode (DIRECT=1)

   also: page 168, fig35
 */

/* lpcxpresso: Y1 (XTAL) is a 12.000MHz crystal */

/*
  PLL1_CTRL

  654 32109876 54 32 1 0 98 7 6543210
  110 00010000 00 00 1 0 00 1 0000000 (lpcopen)
      /17=204M
  001 00010111 00 00 1 0 00 1 0000000 (reset)
      /24=288M
  110 00010000 00 00 0 0 00 0 0000000
*/

#include "registers/cgu.h"
#include "bits/cgu.h"

#define RCNT (0x1ff)
#define IRC_CLK (12000000U)

uint32_t
cgu_measure_frequency(enum clk_sel clk)
{
  /* stop frequency counters */
  CGU->FREQ_MON &= ~MEAS;
  /* select clock and set counters */
  CGU->FREQ_MON = CLK_SEL(clk) | RCNT;
  /* start measurement */
  CGU->FREQ_MON |= MEAS;

  while (CGU->FREQ_MON & MEAS) {
    /* wait for completion */
  }

  return FCNT * (IRC_CLK / RCNT);
}

static inline void
_enable_crystal(void)
{
  volatile uint32_t delay = 1000;

  /* disable XTAL OSC bypass */
  CGU->XTAL_OSC_CTRL &= ~BYPASS;

  /* enable XTAL OSC (low) */
  CGU->XTAL_OSC_CTRL &= ~ENABLE;

  while(delay--) {
    /* 250us (fixme: use timer?) */
  }
}

void
cgu_core_init(void)
{
  volatile uint32_t delay;

  /* set M4 core clock to IRC */
  CGU->BASE_CTRL[CLK_BASE_M4] = CLK_SEL(CLK_SEL_IRC);

  _enable_crystal();

  CGU->BASE_CTRL[CLK_BASE_M4] |= AUTOBLOCK;

  /* 12MHz * (1) * (17) = 204 MHz */
  CGU->PLL1_CTRL = NSEL(0x0) | MSEL(0x10) ;
  /* select OSC for PLL input */
  CGU->PLL1_CTRL |= CLK_SEL(CLK_SEL_XTAL_OSC);

  while (CGU->PLL1_STAT & LOCK) {
    /* wait for PLL lock */
  }

  delay = 1000;
  while (delay--) {
    /* wait >>250µs @ 12MHz */
  }

  /* set 2xP post-divider */
  CGU->PLL1_CTRL &= ~DIRECT;
  CGU->PLL1_CTRL |= PSEL(0) | AUTOBLOCK;

  /* set M4 core clock to PLL1 */
  CGU->BASE_CTRL[CLK_BASE_M4] = CLK_SEL(CLK_SEL_PLL1);

  delay = 1700;
  while (delay--) {
    /* wait >>50µs @ 102MHz */
  }

  /* direct PLL output */
  CGU->PLL1_CTRL |= DIRECT;
}
