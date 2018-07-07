#include <stdint.h>

#include "registers/uart.h"
#include "registers/cgu.h"
#include "bits/uart.h"
#include "bits/cgu.h"

static inline void
uart_set_divisor(struct uart *const uart, uint16_t divisor)
{
  /* enable divisor latch */
  uart->LCR |= DLAB;

  /* set latches */
  uart->DLL = DLLSB(divisor);
  uart->DLM = DLMSB(divisor);

  /* disable divisor latch */
  uart->LCR &= ~DLAB;
}

/* fixme: not sure what else to call this, but it's definitely not generic */
void
uart_generic_init(struct uart *const uart)
{
  /* disable transmit */
  uart->TER &= ~TXEN;

  /* enable uart fifo; reset tx+rx */
  uart->FCR = FIFOEN | RXFIFORES | TXFIFORES;

  /* set word length */
  uart->LCR = WLS_8BIT;

  /* 4800 @ 12MHz IRC */
  //uart_set_divisor(uart, 125);
  //uart->FDR = DIVADDVAL(1) | MULVAL(4);

  /* ~115200 @ 204MHz PLL */
  CGU->BASE_CTRL[CLK_BASE_UART0] = CLK_SEL(CLK_SEL_PLL1);
  uart_set_divisor(uart, 83);
  uart->FDR = DIVADDVAL(1) | MULVAL(3);

  /* enable transmit */
  uart->TER |= TXEN;
}
