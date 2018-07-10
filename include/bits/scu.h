/* SFSP */

#define MODE_FUNC0 (0x0)
#define MODE_FUNC1 (0x1)
#define MODE_FUNC2 (0x2)
#define MODE_FUNC3 (0x3)
#define MODE_FUNC4 (0x4)
#define MODE_FUNC5 (0x5)
#define MODE_FUNC6 (0x6)
#define MODE_FUNC7 (0x7)

/* enable pull-down at pad */
#define MODE_EPD (1 << 3)
/* disable pull-up at pad */
#define MODE_EPUN (1 << 4)
/* fast slew rate */
#define MODE_EHS (1 << 5)
/* input buffer enable */
#define MODE_EZI (1 << 6)
/* disable input glitch filter */
#define MODE_ZIF (1 << 7)
