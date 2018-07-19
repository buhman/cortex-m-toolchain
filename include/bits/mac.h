/* CONFIG */
#define MAC_RX_ENABLE (1 << 2)
#define MAC_TX_ENABLE (1 << 3)
#define MAC_BACKOFF_LIMIT(n) ((n & 0x3) << 5)
#define MAC_DUPLEX_MODE (1 << 11)
#define MAC_LOOPBACK_MODE (1 << 12)
#define MAC_FAST_ETHERNET (1 << 14)
#define MAC_IFG(n) ((n & 0x7) << 17)

/* FRAME_FILTER */
#define MAC_PROMISCUOUS (1 << 0)
#define MAC_RECIEVE_ALL (1 << 31)

/* MII_ADDR */
#define MAC_MII_SET (1 << 0)
#define MAC_MII_BUSY (1 << 0)
#define MAC_MII_WRITE (1 << 1)
#define MAC_MII_CR(n) ((n & 0xf) << 2)
#define MAC_MII_GR(n) ((n & 0x1f) << 6)
#define MAC_MII_PA(n) ((n & 0x1f) << 11)
