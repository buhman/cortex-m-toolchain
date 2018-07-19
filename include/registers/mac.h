#include <stdint.h>

#pragma once

struct mac {
  /* operating modes */
  volatile uint32_t CONFIG;
  /* recieve frame filtering */
  volatile uint32_t FRAME_FILTER;
  /* recieve destination address filtering */
  struct {
    volatile uint32_t HIGH;
    volatile uint32_t LOW;
  } HASHTABLE;
  /* MII address bus */
  volatile uint32_t MII_ADDR;
  /* MII data bus */
  volatile uint32_t MII_DATA;
  /* flow control */
  volatile uint32_t FLOW_CTRL;
  /* vlan tag */
  volatile uint32_t VLAN_TAG;
  volatile const uint32_t _pad_a;
  /* per-module debug status */
  volatile const uint32_t DEBUG;
  /* remote wake-up frame filter */
  volatile uint32_t RWAKE_FRFLT;
  /* power management control/status */
  volatile uint32_t PMT_CTRL_STAT;
  volatile const uint32_t _pad_b[2];
  /* interrupt status */
  volatile const uint32_t INTR;
  /* interrupt mask */
  volatile uint32_t INTR_MASK;
  /* transmit source address */
  struct {
    volatile uint32_t HIGH;
    volatile uint32_t LOW;
  } ADDR0;
};

#define MAC_BASE 0x40010000
#define MAC ((struct mac *const) MAC_BASE
