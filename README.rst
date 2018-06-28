cortex-m-toolchain
------------------

Why? Because nobody wants to use a random Eclipse variant (or other
probably-even-worse "IDE").

usage
^^^^^

This currently depends on:

- arm-none-eabi_
- ninja_

.. _arm-none-eabi: https://github.com/FreddieChopin/bleeding-edge-toolchain/releases/tag/180502
.. _ninja: https://ninja-build.org/

building:

.. code-block:: sh-session

  $ ninja

to run in qemu + debug (using the provided `.gdbinit`):

.. code-block:: sh-session

  $ ./qemu.sh
  ..
  $ arm-none-eabi-gdb -q -ix ./qemu.gdbinit

real hardware
^^^^^^^^^^^^^

I test on a lpc4367/lpcxpresso4367; none of this is likely to work
unmodified on anything else.

I chose openocd_, somewhat arbitrarily; likely-viable alternatives
exist, but I've found no issues with openocd itself yet. The first
thing you'll need to do is start the daemon:

.. code-block:: sh-session

  $ sudo openocd -f ./openocd.cfg

Write code to bank 0 and execute:

.. code-block:: sh-session

  $ telnet localhost 4444
  > halt
  > flash write_bank 0 kernel.bin 0x0
  > reset run

debugging
^^^^^^^^^

I've been using `monitor` commands mostly (pass-through to openocd).

Here's an example of breaking at `main()`:

.. code-block:: sh-session

  $ arm-none-eabi-gdb -q -ix ./openocd.gdbinit
  (gdb) monitor reset halt
  (gdb) break main
  (gdb) continue

other
^^^^^
  
Clear flash bank 0:

.. code_block:: sh-session
  
  > flash erase_sector 0 0 last

.. _openocd: http://openocd.org
.. _lpc4367: https://www.nxp.com/products/processors-and-microcontrollers/arm-based-processors-and-mcus/lpc-cortex-m-mcus/lpc4300-cortex-m4-m0/high-performance-32-bit-microcontroller-based-on-arm-cortex-m4-m0:LPC4367JET100
