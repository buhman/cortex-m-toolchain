#include <stdint.h>

typedef void (* vec_t)(void);

/* linker symbols */
extern uint32_t __stack_top;

/* forward declarations */
extern void _start(void);
void default_handler(void);
void systick_handler(void);

/* cortex-m/lpc interrupt handlers */
const vec_t __vectors[] __attribute__ ((section(".vectors"))) = {
  /* stack pointer */
  (vec_t)(&__stack_top),
  /* reset vector */
  _start,
  /* NMI */
  0,
  /* hard fault */
  0,
  /* MPU fault */
  0,
  /* bus fault */
  0,
  /* usage fault */
  0,
  /* reserved */
  0,
  /* reserved */
  0,
  /* reserved */
  0,
  /* reserved */
  0,
  /* svcall */
  0,
  /* debug monitor */
  0,
  /* reserved */
  0,
  /* pendsv */
  0,
  /* systick */
  systick_handler
};

void default_handler(void)
{
  while (1);
}

void systick_handler(void)
{
  return;
}
