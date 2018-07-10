#include <stdint.h>

#include "registers/timer.h"

void
timer_delay(struct timer *const timer, uint32_t usec);
