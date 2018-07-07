#include <stdint.h>

#pragma once

struct gpio {
  /* byte pin registers */
  volatile uint8_t B[32][32];
  /* unused */
  uint32_t _pad_a[768];
  /* word pin registers */
  volatile uint32_t W[32][32];
  /* port direction register */
  volatile uint32_t DIR[32];
  /* port mask registers */
  volatile uint32_t MASK[32];
  /* port pin registers */
  volatile uint32_t PIN[32];
  /* masked port */
  volatile uint32_t MPIN[32];
  /* set port */
  volatile uint32_t SET[32];
  /* clear port */
  volatile uint32_t CLR[32];
  /* toggle port */
  volatile uint32_t NOT[32];
};

#define GPIO_BASE 0x400F4000
#define GPIO ((struct gpio *const) GPIO_BASE)
