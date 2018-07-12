#include <stdint.h>

#pragma once

#define GPDMA_CHANNELS (8)

struct channel {
  /* source address */
  volatile uint32_t SRCADDR;
  /* destination address */
  volatile uint32_t DESTADDR;
  /* linked list item */
  volatile uint32_t LLI;
  /* control */
  volatile uint32_t CONTROL;
  /* configuration */
  volatile uint32_t CONFIG;
  volatile const uint32_t _pad_a[3];
};

struct gpdma {
  /* interrupt status */
  volatile const uint32_t INTSTAT;
  /* interrupt terminal count request status */
  volatile const uint32_t INTTCSTAT;
  /* interrupt terminal count request clear */
  volatile uint32_t INTTCCLEAR;
  /* interrupt error status */
  volatile const uint32_t INTERRSTAT;
  /* interrupt error clear */
  volatile uint32_t INTERRCLR;
  /* raw interrupt terminal count status */
  volatile const uint32_t RAWINTTCSTAT;
  /* raw error interrupt status */
  volatile const uint32_t RAWINTERRSTAT;
  /* enabled channels */
  volatile const uint32_t ENBLDCHNS;
  /* software burst request */
  volatile uint32_t SOFTBREQ;
  /* software single request */
  volatile uint32_t SOFTSREQ;
  /* software last burst request */
  volatile uint32_t SOFTLBREQ;
  /* software last single request */
  volatile uint32_t SOFTLSREQ;
  /* configuration */
  volatile uint32_t CONFIG;
  /* synchronization */
  volatile uint32_t SYNC;
  volatile const uint32_t _pad_a[50];
  /* channels */
  struct channel CHANNEL[GPDMA_CHANNELS];
};

#define GPDMA_BASE 0x40002000
#define GPDMA ((struct gpdma *const) GPDMA_BASE)
