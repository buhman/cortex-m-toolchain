/* CONFIG */
#define GPDMA_ENABLE (1 << 0)

/* CHANNEL[n].CONTROL */
#define GPDMA_TRANSFERSIZE(n) ((n & 0xfff) << 0)
#define GPDMA_SRC_BURST_SIZE(n) ((n & 0x7) << 12)
#define GPDMA_DST_BURST_SIZE(n) ((n & 0x7) << 15)
#define GPDMA_SRC_WIDTH(n) ((n & 0x7) << 18)
#define GPDMA_DST_WIDTH(n) ((n & 0x7) << 21)
#define GPDMA_SRC_MASTER1 (1 << 24)
#define GPDMA_DST_MASTER1 (1 << 25)
#define GPDMA_SRC_INCR (1 << 26)
#define GPDMA_DST_INCR (1 << 27)
#define GPDMA_TC_INT_ENABLE (1 << 31)

/* CHANNEL[n].CONFIG */
#define GPDMA_SRC_PERIPH(n) ((n & 0xf) << 1)
#define GPDMA_DST_PERIPH(n) ((n & 0xf) << 6)
#define GPDMA_FLOW_CONTROL(n) ((n & 0x7) << 11)
#define GPDMA_IE (1 << 14)
#define GPDMA_ITC (1 << 15)
