#include <stdint.h>

#pragma once

/* timer */
struct timer {
  /* interrupt register */
  volatile uint32_t IR;
  /* timer control register */
  volatile uint32_t TCR;
  /* timer counter */
  volatile uint32_t TC;
  /* prescale register */
  volatile uint32_t PR;
  /* prescale counter */
  volatile uint32_t PC;
  /* match control register */
  volatile uint32_t MCR;
  /* match register */
  volatile uint32_t MR[4];
  /* capture control register */
  volatile uint32_t CCR;
  /* capture register */
  volatile uint32_t CR[4];
  /* external match register */
  volatile uint32_t EMR;
  volatile uint32_t _pad_a[12];
  /* count control register */
  volatile uint32_t CTCR;
};

#define TIMER0_BASE 0x40084000
#define TIMER0 ((struct timer *const) TIMER0_BASE)
#define TIMER1_BASE 0x40085000
#define TIMER1 ((struct timer *const) TIMER1_BASE)
#define TIMER2_BASE 0x400C3000
#define TIMER2 ((struct timer *const) TIMER2_BASE)
#define TIMER3_BASE 0x400C4000
#define TIMER3 ((struct timer *const) TIMER3_BASE)
