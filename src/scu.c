#include "registers/scu.h"
#include "scu.h"

void
scu_board_init(const struct pin_cfg board[], uint32_t length)
{
  uint32_t index = 0;

  while (index < length) {

    /* set function for [port][pin] */
    SCU->SFSP
      [board[index].port]
      [board[index].pin]
      = board[index].function;

    index++;
  }
}
