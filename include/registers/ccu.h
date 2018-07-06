/**
 * clock control unit (UM10503: chapter 14)
 *
 * switches clocks to individual peripherals on or off
 */

#include <stdint.h>

#pragma once

/* CCU1 clocks */
typedef enum ccu1_clk {
  /* APB3 bus clock from CLK_BASE_APB3 */
  CLK_APB3_BUS = 0,
  /* I2C1 register/perigheral clock from CLK_BASE_APB3 */
  CLK_APB3_I2C1
  /* DAC peripheral clock from CLK_BASE_APB3 */,
  CLK_APB3_DAC,
  /* ADC0 register/perigheral clock from CLK_BASE_APB3 */
  CLK_APB3_ADC0,
  /* ADC1 register/perigheral clock from CLK_BASE_APB3 */
  CLK_APB3_ADC1,
  /* CAN0 register/perigheral clock from CLK_BASE_APB3 */
  CLK_APB3_CAN0,

  /* APB1 bus clock clock from CLK_BASE_APB1 */
  CLK_APB1_BUS = 32
  /* Motor controller register/perigheral clock from CLK_BASE_APB1 */,
  CLK_APB1_MOTOCON,
  /* I2C0 register/perigheral clock from CLK_BASE_APB1 */
  CLK_APB1_I2C0,
  /* I2S register/perigheral clock from CLK_BASE_APB1 */
  CLK_APB1_I2S,
  /* CAN1 register/perigheral clock from CLK_BASE_APB1 */
  CLK_APB1_CAN1,

  /* SPIFI SCKI input clock from CLK_BASE_SPIFI */
  CLK_SPIFI = 64,

  /* M3/M4 BUS core clock from CLK_BASE_M4 */
  CLK_M4_BUS = 96,
  /* SPIFI register clock from CLK_BASE_M4 */
  CLK_M4_SPIFI,
  /* GPIO register clock from CLK_BASE_M4 */
  CLK_M4_GPIO,
  /* LCD register clock from CLK_BASE_M4 */
  CLK_M4_LCD,
  /* ETHERNET register clock from CLK_BASE_M4 */
  CLK_M4_ETHERNET,
  /* USB0 register clock from CLK_BASE_M4 */
  CLK_M4_USB0,
  /* EMC clock from CLK_BASE_M4 */
  CLK_M4_EMC,
  /* SDIO register clock from CLK_BASE_M4 */
  CLK_M4_SDIO,
  /* DMA register clock from CLK_BASE_M4 */
  CLK_M4_DMA,
  /* M3/M4 CPU core clock from CLK_BASE_M4 */
  CLK_M4_MXCORE,

  /* SCT register clock from CLK_BASE_M4 */
  CLK_M4_SCT = 109,
  /* USB1 register clock from CLK_BASE_M4 */
  CLK_M4_USB1,
  /* ENC divider clock from CLK_BASE_M4 */
  CLK_M4_EMC_DIV,
  /* FLASHA bank clock from CLK_BASE_M4 */
  CLK_M4_FLASHA,
  /* FLASHB bank clock from CLK_BASE_M4 */
  CLK_M4_FLASHB,
  /* M0 app CPU core clock from CLK_BASE_M4 */
  CLK_M4_M0APP,
  /* ADCHS clock from CLK_BASE_ADCHS */
  CLK_M4_ADCHS,
  /* EEPROM clock from CLK_BASE_M4 */
  CLK_M4_EEPROM,
  /* WWDT register clock from CLK_BASE_M4 */

  CLK_M4_WWDT = 128,
  /* UART0 register clock from CLK_BASE_M4 */
  CLK_M4_UART0,
  /* UART1 register clock from CLK_BASE_M4 */
  CLK_M4_UART1,
  /* SSP0 register clock from CLK_BASE_M4 */
  CLK_M4_SSP0,
  /* TIMER0 register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_TIMER0,
  /* TIMER1 register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_TIMER1,
  /* SCU register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_SCU,
  /* CREG clock from CLK_BASE_M4 */
  CLK_M4_CREG,

  /* RITIMER register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_RITIMER = 160,
  /* UART3 register clock from CLK_BASE_M4 */
  CLK_M4_UART2,
  /* UART4 register clock from CLK_BASE_M4 */
  CLK_M4_UART3,
  /* TIMER2 register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_TIMER2,
  /* TIMER3 register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_TIMER3,
  /* SSP1 register clock from CLK_BASE_M4 */
  CLK_M4_SSP1,
  /* QEI register/perigheral clock from CLK_BASE_M4 */
  CLK_M4_QEI,

  /* Peripheral bus and M0 AHB clock from CLK_BASE_PERIPH */
  CLK_PERIPH_BUS = 192,
  /* M0 subsystem core clock from CLK_BASE_PERIPH */
  CLK_PERIPH_CORE = 194,
  /* SGPIO clock from CLK_BASE_PERIPH */
  CLK_PERIPH_SGPIO,

  /* USB0 clock from CLK_BASE_USB0 */
  CLK_USB0 = 224,
  /* USB1 clock from CLK_BASE_USB1 */
  CLK_USB1 = 256,
  /* SPI clock from CLK_BASE_SPI */
  CLK_SPI = 288,
  /* ADCHS clock from CLK_BASE_ADCHS */
  CLK_ADCHS = 320,

  CLK_CCU1_LAST
}

/* CCU2 clocks */
typedef enum ccu2_clk {
  /* Audio system (I2S) clock from CLK_BASE_APLL */
  CLK_AUDIO = 0,
  /* USART3 clock from CLK_BASE_UART3 */
  CLK_APB2_USART3 = 32,
  /* USART2 clock from CLK_BASE_UART2 */
  CLK_APB2_USART2 = 64,
  /* UART1 clock from CLK_BASE_UART1 */
  CLK_APB0_UART1 = 96,
  /* USART0 clock from CLK_BASE_UART0 */
  CLK_APB0_USART0 = 128,
  /* SSP1 clock from CLK_BASE_SSP1 */
  CLK_APB2_SSP1 = 160,
  /* SSP0 clock from CLK_BASE_SSP0 */
  CLK_APB0_SSP0 = 192,
  /* SDIO clock from CLK_BASE_SDIO */
  CLK_SDIO = 224,

  CLK_CCU2_LAST
};

/* per-clock configuration and status registers */
typedef struct cfg_stat {
  /* CCU clock configuration register */
  volatile uint32_t CFG;
  /* CCU clock status register */
  volatile const uint32_t STAT;
};

/* CCU1 */
typedef struct ccu1 {
  /* power mode register */
  volatile uint32_t PM;
  /* base clocks status register */
  volatile const uint32_t BASE_STAT;
  volatile const uint32_t RESERVED[62];
  /* clock registers */
  struct cfg_stat CLK[CLK_CCU1_LAST];
};

/* CCU2 */
typedef struct ccu2 {
  /* power mode register  */
  volatile uint32_t PM;
  /* base clocks status register */
  volatile const uint32_t BASE_STAT;
  volatile const uint32_t RESERVED[62];
  /* clock registers */
  struct cfg_stat CLK[CLK_CCU2_LAST];
};

/* register memory mapping */
#define CCU1_BASE 0x40051000
#define CCU1 ((struct ccu1 *const) CCU1_BASE)
#define CCU2_BASE 0x40052000
#define CCU2 ((struct ccu2 *const) CCU2_BASE)
