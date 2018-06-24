cortex-m-toolchain
------------------

Why? Because nobody wants to use a random Eclipse variant (or other
probably-even-worse "IDE").

usage
^^^^^

This currently depends on:

- gcc-arm-none-eabi_
- ninja_

.. _gcc-arm-none-eabi: https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
.. _ninja: https://ninja-build.org/

building:

.. code-block:: sh-session

  $ ninja

to run in qemu + debug (using the provided `.gdbinit`):

.. code-block:: sh-session

  $ ./qemu.sh
  ..
  $ arm-none-eabi-gdb
