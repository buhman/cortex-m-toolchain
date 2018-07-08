#include <stdint.h>
#include <cmsis_gcc.h>

#include "uart.h"
#include "cgu.h"
#include "scu.h"
#include "registers/gpio.h"
#include "gpio.h"
#include "timer.h"

#include "board/lpcx_v3.h"

/* DUI0552A: page 159 */
volatile uint32_t * const SYST_CSR = (uint32_t *)0xE000E010;
volatile uint32_t * const SYST_RVR = (uint32_t *)0xE000E014;
volatile uint32_t * const SYST_VCR = (uint32_t *)0xE000E018;
volatile uint32_t * const SYST_CALIB = (uint32_t *)0xE000E01C;

#define CLKSOURCE (1 << 2)
#define TICKINT (1 << 1)
#define ENABLE (1 << 0)

#define LEN(a) (sizeof (a) / sizeof (struct pin_cfg))

void main(void)
{
  /* use core clock | generate systick ISR | enable counter */
  *SYST_CSR = CLKSOURCE | TICKINT | ENABLE;
  /* trigger ISR once every tick_rvr cycles */
  //*SYST_RVR = 0x00FFFFFF;

  cgu_core_init();
  scu_board_init(lpcx_v3_board, LEN(lpcx_v3_board));
  //uart_generic_init(UART0);
  gpio_init();

  timer_delay(TIMER1, 50);

  __enable_irq();

  while (1) {
    __WFI();

    GPIO->NOT[3] = (1 << 5);

    //UART0->THR = 'g';
  }
}

void _systick(void)
{
  return;
}

void _timer1(void)
{
  TIMER0->IR = 0;

  GPIO->NOT[3] = (1 << 5);
}
