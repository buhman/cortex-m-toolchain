#define __WEAK __attribute__ ((weak))
#define __WEAK_ALIAS(x) __attribute__ ((weak, alias (#x)))

void __default(void);

void _nmi(void) __WEAK_ALIAS(__default);
void _hardfault(void) __WEAK_ALIAS(__default);
void _memmanage(void) __WEAK_ALIAS(__default);
void _busfault(void) __WEAK_ALIAS(__default);
void _usagefault(void) __WEAK_ALIAS(__default);
void _svc(void) __WEAK_ALIAS(__default);
void _debugmonitor(void) __WEAK_ALIAS(__default);
void _pendsv(void) __WEAK_ALIAS(__default);
void _systick(void) __WEAK_ALIAS(__default);

void __default(void)
{
  while (1);
}
