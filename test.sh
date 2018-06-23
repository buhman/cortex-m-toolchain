set -ex

PATH="$PATH:/home/zack/gcc-arm-none-eabi-7-2017-q4-major/bin"

arm-none-eabi-gcc -c -mcpu=cortex-m3 -g start.c -o start.o
arm-none-eabi-gcc -c -mcpu=cortex-m3 -g vector_table.c -o vector_table.o
arm-none-eabi-gcc -c -mcpu=cortex-m3 -g main.c -o main.o

arm-none-eabi-ld -Map=test.map -T lm3s6965.ld start.o vector_table.o main.o -o test.elf
#arm-none-eabi-objcopy -O binary test.elf test.bin

qemu-system-arm -nographic -serial mon:stdio -M lm3s6965evb -cpu cortex-m3 -s -S -kernel test.elf
