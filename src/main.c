/* https://github.com/qemu/qemu/blob/master/hw/arm/stellaris.c#L1251 */
volatile unsigned int * const UART0 = (unsigned int *)0x4000C000;

void write_uart0(const char *str)
{
  while (*str != '\0') {
    *UART0 = (unsigned int)(*str);
    str++;
  }
}

void main(void)
{
  const char *works = "asdf foo!\n";

  write_uart0(works);
}
