#include <stdint.h>

typedef void (* vec_t)(void);

/* linker symbols */
extern uint32_t __stack_top;

/* core interrupt handlers */
extern void _start(void);

/* lpc interrupt handlers */

const vec_t __vectors[] __attribute__ ((section(".vectors"))) = {
  /* stack pointer */
  (vec_t)(&__stack_top),
  /* reset vector */
  _start,
  /* more vectors */
};

void default_handler(void) {
  while (1);
}
