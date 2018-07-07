#include <stdint.h>
#include <cmsis_gcc.h>

#include "uart.h"
#include "cgu.h"
#include "scu.h"

#include "board/lpcx_v3.h"

/* DUI0552A: page 159 */
volatile uint32_t * const SYST_CSR = (uint32_t *)0xE000E010;
volatile uint32_t * const SYST_RVR = (uint32_t *)0xE000E014;
volatile uint32_t * const SYST_VCR = (uint32_t *)0xE000E018;
volatile uint32_t * const SYST_CALIB = (uint32_t *)0xE000E01C;

/* UM10503: page 463+ */
#define GPIO_BASE (0x400F4000)
volatile uint32_t * const GPIO_DIR0 = (uint32_t *)(GPIO_BASE + 0x2000);
volatile uint32_t * const GPIO_DIR3 = (uint32_t *)(GPIO_BASE + 0x200C);
volatile uint32_t * const GPIO_SET0 = (uint32_t *)(GPIO_BASE + 0x2200);
volatile uint32_t * const GPIO_SET3 = (uint32_t *)(GPIO_BASE + 0x220C);
volatile uint32_t * const GPIO_NOT0 = (uint32_t *)(GPIO_BASE + 0x2300);
volatile uint32_t * const GPIO_NOT3 = (uint32_t *)(GPIO_BASE + 0x230C);

#define CLKSOURCE (1 << 2)
#define TICKINT (1 << 1)
#define ENABLE (1 << 0)

#define LEN(a) (sizeof (a) / sizeof (struct pin_cfg))

void main(void)
{
  /* lpcx board V3: RGB led
       blue: P6_9 = GPIO3[5] (FUNC0)
       green: P2_7 = GPIO0[7] (FUNC0)
       red: P6_11 = GPIO3[7] (FUNC0)
  */

  /* GPIO are input by default; set to output mode */
  *GPIO_DIR0 = (1 << 7);
  *GPIO_DIR3 = (1 << 5) | (1 << 7);
  /* reset all pins */
  *GPIO_SET0 = ~(0x0);
  *GPIO_SET3 = ~(0x0);

  /* use core clock | generate systick ISR | enable counter */
  *SYST_CSR = CLKSOURCE | TICKINT | ENABLE;
  /* trigger ISR once every tick_rvr cycles */
  *SYST_RVR = 0x00FFFFFF;

  cgu_core_init();
  scu_board_init(lpcx_v3_board, LEN(lpcx_v3_board));
  uart_generic_init(UART0);

  __enable_irq();

  while (1) {
    __WFI();

    *GPIO_NOT0 = (1 << 7);

    UART0->THR = 'g';
  }
}
