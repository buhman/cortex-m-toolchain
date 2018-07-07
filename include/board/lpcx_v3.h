#include "board/board.h"

#pragma once

/*
  JP11 switches FTDI TX between P6_4 and P2_0

  Both of these can be configured as U0_TXD, but P2_0 is also the ENET_MDC

  rxd: P2_1
  txd: P6_4
 */
static const struct pin_cfg lpcx_v3_board[] = {
  /* P2_1 function 1: U0_RXD */
  {2, 1, 0x1},
  /* P6_4 function 2: U0_TXD */
  {6, 4, 0x2},
};
