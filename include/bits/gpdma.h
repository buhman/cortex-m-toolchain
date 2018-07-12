/* CHANNEL[n].CONTROL */
#define GPDMA_TRANSFERSIZE(n) ((n & 0xfff) << 0)
#define GPDMA_SBSIZE(n) ((n & 0x7) << 12)
#define GPDMA_DBSIZE(n) ((n & 0x7) << 15)
#define GPDMA_SWIDTH(n) ((n & 0x7) << 18)
#define GPDMA_DWIDTH(n) ((n & 0x7) << 21)
#define GPDMA_SRC_MASTER1 (1 << 24)
#define GPDMA_DEST_MASTER1 (1 << 25)
#define GPDMA_SI (1 << 26)
#define GPDMA_DI (1 << 27)
