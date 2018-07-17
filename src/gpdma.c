#include "registers/gpdma.h"
#include "bits/gpdma.h"

void
gpdma_init(void)
{
  /* enable controller */
  GPDMA->CONFIG = GPDMA_ENABLE;
}


/*
  - only supports memory-memory transfers
  - assumes 32-bit-aligned transfers
*/
void
gpdma_configure_channel(uint8_t channel_number,
			void *src,
			void *dst,
			uint32_t len)
{
  struct channel *channel;

  channel = &GPDMA->CHANNEL[channel_number];

  /* reset interrupts */
  GPDMA->INTTCCLR = (1 << channel_number);
  GPDMA->INTERRCLR = (1 << channel_number);

  /* set source and destination address */
  channel->SRCADDR = (uint32_t)src;
  channel->DSTADDR = (uint32_t)dst;

  /* fixme: no next item */
  channel->LLI = 0;

  /* uses AHB master 0 */
  channel->CONTROL = 0
    | GPDMA_SRC_WIDTH(0x2) /* 32-bit */
    | GPDMA_DST_WIDTH(0x2) /* 32-bit */
    | GPDMA_SRC_BURST_SIZE(0x4) /* 32 transfers (128 bytes) */
    | GPDMA_DST_BURST_SIZE(0x4) /* 32 transfers (128 bytes) */
    | GPDMA_SRC_INCR
    | GPDMA_DST_INCR
    | GPDMA_TRANSFERSIZE(len / 4) /* number of transfers */
    | GPDMA_TC_INT_ENABLE; /* enable terminal count */

  channel->CONFIG = 0
    | GPDMA_ENABLE
    | GPDMA_IE /* interrupt error "mask" */
    | GPDMA_ITC /* terminal count interrupt "mask" */
    | GPDMA_FLOW_CONTROL(0x0); /* memory-to-memory */
}
