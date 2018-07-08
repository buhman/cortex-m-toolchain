#define __WEAK __attribute__ ((weak))
#define __WEAK_ALIAS(x) __attribute__ ((weak, alias (#x)))

void __default_chip(void);

void _dac(void) __WEAK_ALIAS(__default_chip);
void _m0app(void) __WEAK_ALIAS(__default_chip);
void _dma(void) __WEAK_ALIAS(__default_chip);
void _flash_eeprom(void) __WEAK_ALIAS(__default_chip);
void _ethernet(void) __WEAK_ALIAS(__default_chip);
void _sdio(void) __WEAK_ALIAS(__default_chip);
void _lcd(void) __WEAK_ALIAS(__default_chip);
void _usb0(void) __WEAK_ALIAS(__default_chip);
void _usb1(void) __WEAK_ALIAS(__default_chip);
void _sctimer(void) __WEAK_ALIAS(__default_chip);
void _ritimer(void) __WEAK_ALIAS(__default_chip);
void _timer0(void) __WEAK_ALIAS(__default_chip);
void _timer1(void) __WEAK_ALIAS(__default_chip);
void _timer2(void) __WEAK_ALIAS(__default_chip);
void _timer3(void) __WEAK_ALIAS(__default_chip);
void _mcpwm(void) __WEAK_ALIAS(__default_chip);
void _adc0(void) __WEAK_ALIAS(__default_chip);
void _i2c0(void) __WEAK_ALIAS(__default_chip);
void _i2c1(void) __WEAK_ALIAS(__default_chip);
void _spi(void) __WEAK_ALIAS(__default_chip);
void _adc1(void) __WEAK_ALIAS(__default_chip);
void _ssp0(void) __WEAK_ALIAS(__default_chip);
void _ssp1(void) __WEAK_ALIAS(__default_chip);
void _uart0(void) __WEAK_ALIAS(__default_chip);
void _uart1(void) __WEAK_ALIAS(__default_chip);
void _uart2(void) __WEAK_ALIAS(__default_chip);
void _uart3(void) __WEAK_ALIAS(__default_chip);
void _i2s0(void) __WEAK_ALIAS(__default_chip);
void _i2s1(void) __WEAK_ALIAS(__default_chip);
void _spifi(void) __WEAK_ALIAS(__default_chip);
void _sgpio(void) __WEAK_ALIAS(__default_chip);
void _pin_int0(void) __WEAK_ALIAS(__default_chip);
void _pin_int1(void) __WEAK_ALIAS(__default_chip);
void _pin_int2(void) __WEAK_ALIAS(__default_chip);
void _pin_int3(void) __WEAK_ALIAS(__default_chip);
void _pin_int4(void) __WEAK_ALIAS(__default_chip);
void _pin_int5(void) __WEAK_ALIAS(__default_chip);
void _pin_int6(void) __WEAK_ALIAS(__default_chip);
void _pin_int7(void) __WEAK_ALIAS(__default_chip);
void _gint0(void) __WEAK_ALIAS(__default_chip);
void _gint1(void) __WEAK_ALIAS(__default_chip);
void _eventrouter(void) __WEAK_ALIAS(__default_chip);
void _can1(void) __WEAK_ALIAS(__default_chip);
void _adchs(void) __WEAK_ALIAS(__default_chip);
void _atimer(void) __WEAK_ALIAS(__default_chip);
void _rtc(void) __WEAK_ALIAS(__default_chip);
void _wwdt(void) __WEAK_ALIAS(__default_chip);
void _m0sub(void) __WEAK_ALIAS(__default_chip);
void _can0(void) __WEAK_ALIAS(__default_chip);
void _qei(void) __WEAK_ALIAS(__default_chip);

void __default_chip(void)
{
  while (1);
}
