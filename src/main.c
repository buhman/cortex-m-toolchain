#include <stdint.h>
#include <cmsis_gcc.h>
#include <chip/irq.h>
#include <core_cm4.h>

#include "uart.h"
#include "cgu.h"
#include "scu.h"
#include "registers/gpio.h"
#include "gpio.h"
#include "registers/timer.h"
#include "timer.h"
#include "registers/gpdma.h"
#include "gpdma.h"

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

void
test_dma(void);

void
main(void)
{
  /* use core clock | generate systick ISR | enable counter */
  //*SYST_CSR = CLKSOURCE | TICKINT | ENABLE;
  /* trigger ISR once every tick_rvr cycles */
  //*SYST_RVR = 0x00FFFFFF;

  cgu_core_init();
  scu_board_init(lpcx_v3_board, LEN(lpcx_v3_board));
  uart_generic_init(UART0);
  uart_enable_interrupt(UART0);
  gpio_init();
  gpdma_init();

  timer_delay(TIMER0, 1000000);

  /* fixme: map uart to irqn */
  //NVIC_SetPriority(USART0_IRQn, 1);
  //NVIC_EnableIRQ(USART0_IRQn);

  //NVIC_SetPriority(TIMER0_IRQn, 1);
  //NVIC_EnableIRQ(TIMER0_IRQn);

  NVIC_SetPriority(GPDMA_IRQn, 1);
  NVIC_EnableIRQ(GPDMA_IRQn);

  UART0->THR = 'q';

  test_dma();

  while (1) {
  }
}

void
test_dma(void)
{
  uint8_t test1[128];
  uint8_t test2[128];

  /* populate test1 with something remotely interesting */
  {
    uint32_t index;

    index = 0;
    while (index < 128) {
      test1[index] = 255 - index;
      index++;
    }
  }

  /* populate test2 with something that is obviously not the same thing as test1 */
  {
    uint32_t index;

    index = 0;
    while (index < 128) {
      test2[index] = 0;
      index++;
    }
  }

  /* copy to test2 via dma transfer on channel 0 */
  gpdma_configure_channel(0, test1, test2, 128);

  __enable_irq();

  __WFI();

  /* nop */
  uint8_t nop;
  nop = 1;
  (void) nop;
}

void
_systick(void)
{
  return;
}

void
_uart0(void)
{
  uint32_t status0, status1;

  if (UART0->LSR & (1 << 0)) {
    UART0->THR = UART0->RBR & 0xff;
    GPIO->NOT[3] = (1 << 5);
  }

  /* observe IIR/LSR */
  status0 = UART0->IIR;
  status1 = UART0->LSR;
  (void)status0;
  (void)status1;

  return;
}

void
_timer0(void)
{
  TIMER0->IR = (1 << 0);

  GPIO->NOT[3] = (1 << 7);
}

/* fixme: add real logic */
void
_gpdma(void)
{
  uint8_t stat;

  /* read for gdb examination */
  stat = GPDMA->INTTCSTAT & (1 << 0);

  (void)stat;

  /* clear presumed interrupt */
  GPDMA->INTTCCLR = (1 << 0);
}
