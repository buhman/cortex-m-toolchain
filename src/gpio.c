#include "registers/gpio.h"

void
gpio_init(void)
{
  /* lpcx board V3: RGB led
       blue: P6_9 = GPIO3[5] (FUNC0)
       green: P2_7 = GPIO0[7] (FUNC0)
       red: P6_11 = GPIO3[7] (FUNC0)
  */

  /* GPIO are input by default; set to output mode */
  GPIO->DIR[0] = (1 << 7);
  GPIO->DIR[3] = (1 << 5) | (1 << 7);
  /* reset all pins */
  GPIO->SET[0] = ~(0x0);
  GPIO->SET[3] = ~(0x0);
}
