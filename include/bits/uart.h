/* LCR */
#define WLS_8BIT (0x3 << 0)
#define SBS (1 << 2)
#define PE (1 << 3)
#define DLAB (1 << 7)

/* FCR */
#define FIFOEN (1 << 0)
#define RXFIFORES (1 << 1)
#define TXFIFORES (1 << 2)

/* TEN */
#define TXEN (1 << 0)

/* IER */
#define RBRIE (1 << 0)
#define RLSIE (1 << 2)

/* divisor helpers */
#define DLLSB(v) ((v >> 0) & 0xff)
#define DLMSB(v) ((v >> 8) & 0xff)

/* fractional divisor helpers */
#define DIVADDVAL(v) ((v & 0xf) << 0)
#define MULVAL(v) ((v & 0xf) << 4)
