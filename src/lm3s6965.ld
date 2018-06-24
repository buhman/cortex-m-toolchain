OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
  /* this is the only thing in here that is actually specific to lm3s6965 */
  /* https://github.com/qemu/qemu/blob/master/hw/arm/stellaris.c#L1289 */
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

ENTRY(_start)

SECTIONS
{
  /* code */
  .text : ALIGN(4)
  {
    /* vector table starts at VMA 0x0 */
    KEEP(*(.vectors))
    *(.text*)
  } > FLASH

  /* read-only data */
  .rodata : ALIGN(4)
  {
    *(.rodata*)
  } > FLASH

  __data_start_rom = .;

  /* initialized data */
  .data : ALIGN(4)
  {
    __data_start = .;
    *(.data)
    __data_end = .;
  } > RAM

  /* uninitialized data */
  .bss : ALIGN(4)
  {
    __bss_start = .;
    *(.bss)
    __bss_end = .;
  } > RAM

  /* stack */
  __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
