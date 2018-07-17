#include <stdint.h>

#include "exceptions.h"
#include "default_handlers.h"

#define __SECTION(v) __attribute__ ((section(v)))

typedef void (* vec_t)(void);

/* linker symbols */
extern void __stack_top();
extern void __vector_checksum();

/* cortex-m interrupt handlers */
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

/* lpc interrupt handlers */
const vec_t __chip_vectors[] __SECTION(".vectors.chip") = {
  _dac,
  _m0app,
  _gpdma,
  0,
  _flash_eeprom,
  _ethernet,
  _sdio,
  _lcd,
  _usb0,
  _usb1,
  _sctimer,
  _ritimer,
  _timer0,
  _timer1,
  _timer2,
  _timer3,
  _mcpwm,
  _adc0,
  _i2c0,
  _i2c1,
  _spi,
  _adc1,
  _ssp0,
  _ssp1,
  _uart0,
  _uart1,
  _uart2,
  _uart3,
  _i2s0,
  _i2s1,
  _spifi,
  _sgpio,
  _pin_int0,
  _pin_int1,
  _pin_int2,
  _pin_int3,
  _pin_int4,
  _pin_int5,
  _pin_int6,
  _pin_int7,
  _gint0,
  _gint1,
  _eventrouter,
  _can1,
  0,
  _adchs,
  _atimer,
  _rtc,
  0,
  _wwdt,
  _m0sub,
  _can0,
  _qei,
};
