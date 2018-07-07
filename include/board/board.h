#include <stdint.h>

#pragma once

struct pin_cfg {
  uint8_t port;
  uint8_t pin;
  uint32_t function;
};
