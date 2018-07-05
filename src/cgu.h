#include <stdint.h>

#include "registers/cgu.h"

uint32_t
cgu_measure_frequency(enum clk_sel clock);

void
cgu_core_init(void);
