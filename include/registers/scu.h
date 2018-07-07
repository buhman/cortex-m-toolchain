#include <stdint.h>

#pragma once

union sfs {
  struct {
    volatile uint32_t
      mode:3, /* pin function */
      epd:1,  /* enable pull-down resistor at pad */
      epun:1, /* disable pull-up resistor at pad*/
      ehs:1,  /* slew rate */
      ezi:1,  /* input buffer enable */
      zif:1,  /* input glitch filter */
      ehd:2;  /* drive strength */
  } b;
  volatile uint32_t w;
};

struct scu {
  /* port pin configuration registers */
  volatile union sfs SFSP[16][32];
  volatile const uint32_t _pad_a[256];
  /* CLK pin configuration registers */
  volatile uint32_t SFSCLK[4];
  volatile const uint32_t _pad_b[28];
  /* USB pin configuration register */
  volatile uint32_t SFSUSB;
  /* i2c0 pin configuration register */
  volatile uint32_t SFSI2C0;
  /* ADC pin select registers */
  volatile uint32_t ENAIO[3];
  volatile const uint32_t _pad_c[27];
  /* EMC delay */
  volatile uint32_t EMCDELAYCLK;
  volatile const uint32_t _pad_d[31];
  /* SD delay */
  volatile uint32_t SDDELAY;
  volatile const uint32_t _pad_e[31];
  /* pin interrupt select */
  volatile uint32_t PINTSEL[2];
};

#define SCU_BASE 0x40086000
#define SCU ((struct scu *const) SCU_BASE)
