#include "registers/timer.h"
#include "bits/timer.h"

void
timer_delay(struct timer *const timer, uint32_t usec)
{
  /* interrupt on MR0 */
  timer->MCR = MR1I | MR1R;

  /* prescale 204MHz IRC @ 1µs */
  timer->PR = 0; //204;

  (void)usec;

  /* timer match value */
  timer->MR[1] = 1046083 * 2;

  /* reset and enable counter */
  timer->PC = 0;
  timer->TC = 0;

  timer->TCR = CEN;
}
