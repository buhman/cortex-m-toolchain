#include <stdint.h>

/* linker symbols */
extern uint32_t __data_start_rom;
extern uint32_t __data_start, __data_end;
extern uint32_t __bss_start, __bss_end;

/* */
extern void main(void);


void _start(void)
{
  /* on reset, the CPU jumps to *(0x4). At this point our RW data segments have
     not been relocated to RAM (there is no program loader; we are the program
     loader)

     objdump physically places our data segment in flash immediately after
     the text segment */

  uint32_t *src, *dst;

  /* copy data segment from flash to ram */

  src = &__data_start_rom;
  dst = &__data_start;

  while (dst != &__data_end) {
    *dst = *src;
    dst += 1;
    src += 1;
  }

  /* zero-initialize bss segment */

  dst = &__bss_start;
  while (dst != &__bss_end) {
    *dst++ = 0;
  }

  main();

  while (1);
}
