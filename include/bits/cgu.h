/* FREQ_MON */
#define MEAS (1 << 23)
#define FCNT ((CGU->FREQ_MON >> 9) & 0x3ff)

/* XTAL_OSC_CTRL */
#define ENABLE (1 << 0)
#define BYPASS (1 << 1)

/* PLL1_STAT */
#define LOCK (1 << 0)

/* _CTRL */
#define DIRECT (1 << 7)
#define AUTOBLOCK (1 << 11)
#define PSEL(p) ((p & 0x3) << 8)
#define NSEL(n) ((n & 0x3) << 12)
#define MSEL(m) ((m & 0xff) << 16)
#define CLK_SEL(v) ((v & 0x1f) << 24)
