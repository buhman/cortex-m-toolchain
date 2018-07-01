Out of the box, LPCXpresso boards contain no firmware. To do things like write
to the on-chip flash and do on-chip debugging, the "probe" MCU will need to be
programmed.

board configuration
^^^^^^^^^^^^^^^^^^^

There are two usb micro ports; the one labeled `Link` goes to the on-board
probe. Near this is a `DFULink` jumper (JP6); when shunted (out-of-box default),
the probe boots in "DFU mode".

This provides an implementation of DFU_;

.. _DFU: https://en.wikipedia.org/wiki/USB#Device_Firmware_Upgrade

probe firmware
^^^^^^^^^^^^^^

Contrast to what NXP documentation suggests, you can use generic open source
tooling for this like dfu-util_ (openmoko), contrast to lpcscrypt which is
a massively overcomplicated ratsnest of underdocumented wrapper scripts.

.. _dfu-util: http://dfu-util.sourceforge.net/

NXP's (binary blob) implementation of CMSIS-DAP (originally distributed with
lpcscrypt) is included in the `./probe` directory of this repository. To write
this:

.. code::

   dfu-util -d 1fc9:000c -D probe/LPC432x_IAP_CMSIS_DAP_V5_182.bin

When this is done, you should remove JP6. You can then use normal tools like
openocd to manipulate the board target.
