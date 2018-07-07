#include <stdint.h>

#define __SECTION(v) __attribute__ ((section(v)))

typedef void (* vec_t)(void);

/* linker symbols */
extern void __stack_top();
extern void __vector_checksum();

/* forward declarations */
extern void _start(void);
extern void _nmi(void);
extern void _hardfault(void);
extern void _memmanage(void);
extern void _busfault(void);
extern void _usagefault(void);
extern void _svc(void);
extern void _debugmonitor(void);
extern void _pendsv(void);
extern void _systick(void);

/* cortex-m/lpc interrupt handlers */
const vec_t __vectors[] __SECTION(".vectors.core") = {
  &__stack_top,
  _start,
  _nmi,
  _hardfault,
  _memmanage,
  _busfault,
  _usagefault,
  __vector_checksum,
  0,
  0,
  0,
  _svc,
  _debugmonitor,
  0,
  _pendsv,
  _systick
};
