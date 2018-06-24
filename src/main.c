#include <stdint.h>
#include <cmsis_gcc.h>

/* https://github.com/qemu/qemu/blob/master/hw/arm/stellaris.c#L1251 */
volatile uint32_t * const UART0 = (uint32_t *)0x4000C000;

/* http://infocenter.arm.com/help/topic/com.arm.doc.dui0552a/DUI0552A_cortex_m3_dgug.pdf
   page 159 4-33 */
volatile uint32_t * const SYST_CSR = (uint32_t *)0xE000E010;
volatile uint32_t * const SYST_RVR = (uint32_t *)0xE000E014;
volatile uint32_t * const SYST_VCR = (uint32_t *)0xE000E018;
volatile uint32_t * const SYST_CALIB = (uint32_t *)0xE000E01C;

#define CLKSOURCE (1 << 2)
#define TICKINT (1 << 1)
#define ENABLE (1 << 0)

void write_uart0(const char *str)
{
  while (*str != '\0') {
    *UART0 = (uint32_t)(*str);
    str++;
  }
}

void main(void)
{
  const char *works = "asdf foo!\n";

  write_uart0(works);

  /* use core clock | generate systick ISR | enable counter */
  uint32_t tick_csr = CLKSOURCE | TICKINT | ENABLE;
  /* trigger ISR once every tick_rvr cycles */
  uint32_t tick_rvr = 0x00FFFFFF;

  *SYST_CSR = tick_csr;
  *SYST_RVR = tick_rvr;

  __enable_irq();

  while (1) {
    __WFI();

    write_uart0("tick");
  }
}
