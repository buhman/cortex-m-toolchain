#include <stdint.h>

/* UART */
struct uart {
  union {
    /* receive buffer register */
    volatile const uint32_t RBR;
    /* transmit holding register */
    volatile uint32_t THR;
    /* divisor latch LSB */
    volatile uint32_t DLL;
  };

  union {
    /* divisor latch MSB */
    volatile uint32_t DLM;
    /* interrupt enable register */
    volatile uint32_t IER;
  };

  union {
    /* interrupt ID register */
    volatile const uint32_t IIR;
    /* FIFO control register */
    volatile uint32_t FCR;
  };

  /* line control register */
  volatile uint32_t LCR;
  /* modem control register (UART1) */
  volatile uint32_t MCR;
  /* line status register */
  volatile const uint32_t LSR;
  /* modem status register (UART1) */
  volatile const uint32_t MSR;
  /* scratch pad register */
  volatile uint32_t SCR;
  /* auto-baud control register */
  volatile uint32_t ACR;
  /* IrDA control register (USART3) */
  volatile uint32_t ICR;
  /* fractional divider register */
  volatile uint32_t FDR;
  /* oversampling register */
  volatile uint32_t OSR;
  /* */
  uint32_t _pad_a[4];
  /* half-duplex enable */
  volatile uint32_t HDEN;
  /* */
  uint32_t _pad_b[1];
  /* smart card interface control */
  volatile uint32_t SCICTRL;
  /* RS-485/EIA-485 control */
  volatile uint32_t RS485CTRL;
  /* RS-485/EIA-485 address match */
  volatile uint32_t RS485ADRMATCH;
  /* RS-485/EIA-485 direction control delay. */
  volatile uint32_t RS485DLY;
  /* synchronous mode control */
  volatile uint32_t SYNCCTRL;
  /* transmit enable register */
  volatile uint32_t TER;
};

#define UART0_BASE 0x40081000
#define UART0 ((struct uart *const) UART0_BASE)
#define UART1_BASE 0x40082000
#define UART1 ((struct uart *const) UART1_BASE)
#define UART2_BASE 0x400C1000
#define UART2 ((struct uart *const) UART2_BASE)
#define UART3_BASE 0x400C2000
#define UART3 ((struct uart *const) UART3_BASE)
