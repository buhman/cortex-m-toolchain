#include "registers/timer.h"
#include "bits/timer.h"

void
timer_delay(struct timer *const timer, uint32_t usec)
{
  /* interrupt on MR0 */
  timer->MCR = MR0I | MR0R;

  /* prescale 204MHz IRC @ 1µs */
  timer->PR = 204;

  /* timer match value */
  timer->MR[0] = usec;

  /* reset and enable counter */
  timer->PC = 0;
  timer->TC = 0;

  timer->TCR = CEN;
}
