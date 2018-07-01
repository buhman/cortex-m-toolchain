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

    If you're using Arch Linux, you can also install `arm-none-eabi-*` from
    `community` (same version as bleeding-edge-toolchain).

building:

.. code-block:: sh-session

  $ ninja

to run in qemu + debug (using the provided `.gdbinit`):

.. code-block:: sh-session

  $ ./qemu.sh
  ..
  $ arm-none-eabi-gdb -q -ix ./qemu.gdbinit

example hardware
^^^^^^^^^^^^^^^^

The following boards are being used/tested with this repository:

- lpcxpresso4367 (lpc4367)
- lpcxpresso18s37 (lpc18s37)

.. _lpcxpresso18s37: https://www.nxp.com/part/OM13076
.. _lpcxpresso4367: https://www.nxp.com/part/OM13088

These development boards require bootstrapping from DFU out of the box; this
process is documented in `lpcx bootstrappping`_.

.. _lpcx bootstrapping: doc/lpcx-bootstrapping.rst

on-chip debugging
^^^^^^^^^^^^^^^^^

I chose openocd_, somewhat arbitrarily; other likely-viable alternatives exist,
but I've found no issues with openocd itself. The first thing you'll need to do
is start the daemon:

.. code-block:: sh-session

  $ sudo openocd -f ./openocd.cfg

Write code to bank 0 and execute:

.. code-block:: sh-session

  $ telnet localhost 4444
  > halt
  > flash write_bank 0 kernel.bin 0x0
  > reset run

.. _openocd: http://openocd.org

debugging
^^^^^^^^^

I've been using `monitor` commands mostly (pass-through to openocd).

Here's an example of breaking at `main()`:

.. code-block:: sh-session

  $ arm-none-eabi-gdb -q -ix ./openocd.gdbinit
  (gdb) monitor reset halt
  (gdb) break main
  (gdb) continue

I also suggest trying gdb-dashboard_.

.. gdb-dashboard:: https://github.com/cyrus-and/gdb-dashboard

other
^^^^^

Clear flash bank 0:

.. code_block:: sh-session

  > flash erase_sector 0 0 last
