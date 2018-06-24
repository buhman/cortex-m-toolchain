#!/usr/bin/env bash

printf "qemu waiting for gdb..\n"

set -e

qemu-system-arm -nographic -serial mon:stdio -M lm3s6965evb -cpu cortex-m3 -s -S -kernel kernel.elf
