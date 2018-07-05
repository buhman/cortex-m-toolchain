/**
 * clock generation unit (UM10503: chapter 13)
 *
 * switches clocks to individual peripherals on or off
 */

#include <stdint.h>

#pragma once

enum cgu_base_clk {
  /* Base clock for WDT oscillator, IRC input only */
  CLK_BASE_SAFE,
  /* Base USB clock for USB0, USB PLL input only */
  CLK_BASE_USB0,
  /* Base clock for SGPIO */
  CLK_BASE_PERIPH,
  /* Base USB clock for USB1 */
  CLK_BASE_USB1,
  /* Base clock for CPU core */
  CLK_BASE_M4,
  /* Base clock for SPIFI */
  CLK_BASE_SPIFI,
  /* Base clock for SPI */
  CLK_BASE_SPI,
  /* Base clock for PHY RX */
  CLK_BASE_PHY_RX,
  /* Base clock for PHY TX */
  CLK_BASE_PHY_TX,
  /* Base clock for APB1 group */
  CLK_BASE_APB1,
  /* Base clock for APB3 group */
  CLK_BASE_APB3,
  /* Base clock for LCD pixel clock */
  CLK_BASE_LCD,
  /* Base clock for ADCHS */
  CLK_BASE_ADCHS,
  /* Base clock for SDIO */
  CLK_BASE_SDIO,
  /* Base clock for SSP0 */
  CLK_BASE_SSP0,
  /* Base clock for SSP1 */
  CLK_BASE_SSP1,
  /* Base clock for UART0 */
  CLK_BASE_UART0,
  /* Base clock for UART1 */
  CLK_BASE_UART1,
  /* Base clock for UART2 */
  CLK_BASE_UART2,
  /* Base clock for UART3 */
  CLK_BASE_UART3,
  /* Base clock for CLKOUT pin */
  CLK_BASE_OUT,
  CLK_BASE_RESERVED0,
  CLK_BASE_RESERVED1,
  CLK_BASE_RESERVED2,
  CLK_BASE_RESERVED3,
  /* Base clock for audio PLL */
  CLK_BASE_APLL,
  /* Base clock for CGUOUT0 pin */
  CLK_BASE_CGU_OUT0,
  /* Base clock for CGUOUT1 pin */
  CLK_BASE_CGU_OUT1,
  CLK_BASE_LAST
};

enum clk_pll {
  CLK_PLL_USB,
  CLK_PLL_AUDIO,
  CLK_PLL_LAST
};

/* CGU clock dividers */
enum clk_idiv {
  CLK_IDIV_A,
  CLK_IDIV_B,
  CLK_IDIV_C,
  CLK_IDIV_D,
  CLK_IDIV_E,
  CLK_IDIV_LAST
};

/* PLL */
struct cgu_pll {
  /* PLL status register */
  volatile const uint32_t PLL_STAT;
  /* PLL control register */
  volatile uint32_t PLL_CTRL;
  /* PLL M-divider register */
  volatile uint32_t PLL_MDIV;
  /* PLL N/P-divider register */
  volatile uint32_t PLL_NP_DIV;
};

/* CGU */
struct cgu {
  volatile const uint32_t RESERVED0[5];
  /* Frequency monitor register */
  volatile uint32_t FREQ_MON;
  /* Crystal oscillator control register */
  volatile uint32_t XTAL_OSC_CTRL;
  /* USB and audio PLL blocks */
  struct cgu_pll PLL[CLK_PLL_LAST];
  /* PLL0 (audio)      */
  volatile uint32_t PLL0AUDIO_FRAC;
  /* PLL1 status register  */
  volatile const uint32_t PLL1_STAT;
  /* PLL1 control register */
  volatile uint32_t PLL1_CTRL;
  /* Integer divider A-E control registers */
  volatile uint32_t IDIV_CTRL[CLK_IDIV_LAST];
  /* Start of base clock registers */
  volatile uint32_t BASE_CTRL[CLK_BASE_LAST];
};

enum clk_sel {
  CLK_SEL_32K_OSC = 0x0,
  CLK_SEL_IRC = 0x1,
  CLK_SEL_ENET_RX_CLK = 0x2,
  CLK_SEL_ENET_TX_CLK = 0x3,
  CLK_SEL_GP_CLKIN = 0x4,
  CLK_SEL_XTAL_OSC = 0x6,
  CLK_SEL_PLL0USB = 0x7,
  CLK_SEL_PLL0AUDIO = 0x8,
  CLK_SEL_PLL1 = 0x9,
  CLK_SEL_IDIVA = 0xC,
  CLK_SEL_IDIVB = 0xD,
  CLK_SEL_IDIVC = 0xE,
  CLK_SEL_IDIVD = 0xF,
  CLK_SEL_IDIVE = 0x10,
};

#define CGU_BASE 0x40050000
#define CGU ((struct cgu *) CGU_BASE)
