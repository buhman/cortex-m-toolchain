#include <stdint.h>

#define __SECTION(v) __attribute__ ((section(v)))

typedef void (* vec_t)(void);

/* forward declarations */
extern void _dac(void);
extern void _m0app(void);
extern void _dma(void);
extern void _flash_eeprom(void);
extern void _ethernet(void);
extern void _sdio(void);
extern void _lcd(void);
extern void _usb0(void);
extern void _usb1(void);
extern void _sctimer(void);
extern void _ritimer(void);
extern void _timer0(void);
extern void _timer1(void);
extern void _timer2(void);
extern void _timer3(void);
extern void _mcpwm(void);
extern void _adc0(void);
extern void _i2c0(void);
extern void _i2c1(void);
extern void _spi(void);
extern void _adc1(void);
extern void _ssp0(void);
extern void _ssp1(void);
extern void _uart0(void);
extern void _uart1(void);
extern void _uart2(void);
extern void _uart3(void);
extern void _i2s0(void);
extern void _i2s1(void);
extern void _spifi(void);
extern void _sgpio(void);
extern void _pin_int0(void);
extern void _pin_int1(void);
extern void _pin_int2(void);
extern void _pin_int3(void);
extern void _pin_int4(void);
extern void _pin_int5(void);
extern void _pin_int6(void);
extern void _pin_int7(void);
extern void _gint0(void);
extern void _gint1(void);
extern void _eventrouter(void);
extern void _can1(void);
extern void _adchs(void);
extern void _atimer(void);
extern void _rtc(void);
extern void _wwdt(void);
extern void _m0sub(void);
extern void _can0(void);
extern void _qei(void);

/* cortex-m interrupt handlers */
const vec_t __chip_vectors[] __SECTION(".vectors.chip") = {
  _dac,
  _m0app,
  _dma,
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
