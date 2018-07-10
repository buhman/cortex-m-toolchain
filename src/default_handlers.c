#define __WEAK __attribute__ ((weak))
#define __WEAK_ALIAS(x) __attribute__ ((weak, alias (#x)))

void __default_handler(void);

void _dac(void) __WEAK_ALIAS(__default_handler);
void _m0app(void) __WEAK_ALIAS(__default_handler);
void _dma(void) __WEAK_ALIAS(__default_handler);
void _flash_eeprom(void) __WEAK_ALIAS(__default_handler);
void _ethernet(void) __WEAK_ALIAS(__default_handler);
void _sdio(void) __WEAK_ALIAS(__default_handler);
void _lcd(void) __WEAK_ALIAS(__default_handler);
void _usb0(void) __WEAK_ALIAS(__default_handler);
void _usb1(void) __WEAK_ALIAS(__default_handler);
void _sctimer(void) __WEAK_ALIAS(__default_handler);
void _ritimer(void) __WEAK_ALIAS(__default_handler);
void _timer0(void) __WEAK_ALIAS(__default_handler);
void _timer1(void) __WEAK_ALIAS(__default_handler);
void _timer2(void) __WEAK_ALIAS(__default_handler);
void _timer3(void) __WEAK_ALIAS(__default_handler);
void _mcpwm(void) __WEAK_ALIAS(__default_handler);
void _adc0(void) __WEAK_ALIAS(__default_handler);
void _i2c0(void) __WEAK_ALIAS(__default_handler);
void _i2c1(void) __WEAK_ALIAS(__default_handler);
void _spi(void) __WEAK_ALIAS(__default_handler);
void _adc1(void) __WEAK_ALIAS(__default_handler);
void _ssp0(void) __WEAK_ALIAS(__default_handler);
void _ssp1(void) __WEAK_ALIAS(__default_handler);
void _uart0(void) __WEAK_ALIAS(__default_handler);
void _uart1(void) __WEAK_ALIAS(__default_handler);
void _uart2(void) __WEAK_ALIAS(__default_handler);
void _uart3(void) __WEAK_ALIAS(__default_handler);
void _i2s0(void) __WEAK_ALIAS(__default_handler);
void _i2s1(void) __WEAK_ALIAS(__default_handler);
void _spifi(void) __WEAK_ALIAS(__default_handler);
void _sgpio(void) __WEAK_ALIAS(__default_handler);
void _pin_int0(void) __WEAK_ALIAS(__default_handler);
void _pin_int1(void) __WEAK_ALIAS(__default_handler);
void _pin_int2(void) __WEAK_ALIAS(__default_handler);
void _pin_int3(void) __WEAK_ALIAS(__default_handler);
void _pin_int4(void) __WEAK_ALIAS(__default_handler);
void _pin_int5(void) __WEAK_ALIAS(__default_handler);
void _pin_int6(void) __WEAK_ALIAS(__default_handler);
void _pin_int7(void) __WEAK_ALIAS(__default_handler);
void _gint0(void) __WEAK_ALIAS(__default_handler);
void _gint1(void) __WEAK_ALIAS(__default_handler);
void _eventrouter(void) __WEAK_ALIAS(__default_handler);
void _can1(void) __WEAK_ALIAS(__default_handler);
void _adchs(void) __WEAK_ALIAS(__default_handler);
void _atimer(void) __WEAK_ALIAS(__default_handler);
void _rtc(void) __WEAK_ALIAS(__default_handler);
void _wwdt(void) __WEAK_ALIAS(__default_handler);
void _m0sub(void) __WEAK_ALIAS(__default_handler);
void _can0(void) __WEAK_ALIAS(__default_handler);
void _qei(void) __WEAK_ALIAS(__default_handler);

void __default_handler(void)
{
  while (1);
}
