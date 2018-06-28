interface cmsis-dap

#adapter_khz 500
adapter_khz 2000

# XXX: make SWD work as well
transport select jtag

set CHIPNAME lpc4367
set M4_JTAG_TAPID 0x4ba00477
set M0_JTAG_TAPID 0x0ba01477

# this creates a tap called $CHIPNAME.m4.cpu
jtag newtap $CHIPNAME.m4 cpu -irlen 4 -expected-id $M4_JTAG_TAPID
# fixme: probably not correct for m0
#jtag newtap $CHIPNAME.m0app tap -irlen 4 -expected-id $M0_JTAG_TAPID
#jtag newtap $CHIPNAME.m0sub tap -irlen 4 -expected-id $M0_JTAG_TAPID

# this creates a target called $CHIPNAME.m4 from the tap called $CHIPNAME.m4
target create $CHIPNAME.m4 cortex_m -chain-position $CHIPNAME.m4.cpu

targets $CHIPNAME.m4

# internal RC oscillator is 12MHz
set CCLK 12000

# 154KB ram
#set WORKAREASIZE 157696
# XXX: ram is not contigously mapped
set WORKAREASIZE 0x26800
# ram is statically mapped to at 0x10000000
$CHIPNAME.m4 configure -work-area-phys 0x10000000 -work-area-size $WORKAREASIZE -work-area-backup 0

# values are from:
#   UM10503: p37 3.3.3 "On-chip flash"
#  bankA @ 0x1A00 0000
#  bankB @ 0x1B00 0000
#  spifi @ 0x1400 0000

set FLASHNAME $CHIPNAME.flash
# flash bank <name> lpc2000 <base> <size> 0 0 <target#> <variant> <clock> [calc checksum]
#  fixme: 204000 is a magic mystery value
flash bank $FLASHNAME.a lpc2000 0x1A000000 0x80000 0 0 $CHIPNAME.m4 \
    lpc4300 204000 calc_checksum

flash bank $FLASHNAME.b lpc2000 0x1B000000 0x80000 0 0 $CHIPNAME.m4 \
    lpc4300 204000 calc_checksum
