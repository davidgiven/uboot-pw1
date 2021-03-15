/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: iomux_register.h

#ifndef _IOMUX_REGISTER_H_
#define _IOMUX_REGISTER_H_

//#include <mach/iomux-mx6sl.h>
//#include <mach/common.h>
//#include <mach/hardware.h>

//
// IOMUXC_GPR*
//
#define IOMUXC_GPR0           (0x020E0000)
#define IOMUXC_GPR1           (0x020E0004)
#define IOMUXC_GPR2           (0x020E0008)
#define IOMUXC_GPR3           (0x020E000C)
#define IOMUXC_GPR4           (0x020E0010)
#define IOMUXC_GPR5           (0x020E0014)
#define IOMUXC_GPR6           (0x020E0018)
#define IOMUXC_GPR7           (0x020E001C)
#define IOMUXC_GPR8           (0x020E0020)
#define IOMUXC_GPR9           (0x020E0024)
#define IOMUXC_GPR10          (0x020E0028)
#define IOMUXC_GPR11          (0x020E002C)
#define IOMUXC_GPR12          (0x020E0030)
#define IOMUXC_GPR13          (0x020E0034)

//
// IOMUXC_OBSERVE_MUX_*
//
#define IOMUXC_OBSERVE_MUX_0  (0x020E0038)
#define IOMUXC_OBSERVE_MUX_1  (0x020E003C)
#define IOMUXC_OBSERVE_MUX_2  (0x020E0040)
#define IOMUXC_OBSERVE_MUX_3  (0x020E0044)
#define IOMUXC_OBSERVE_MUX_4  (0x020E0048)

//
// IOMUXC_SW_MUX_CTL_PAD_*
//
#define IOMUXC_SW_MUX_CTL_PAD_AUD_MCLK       (0x020E004C)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_RXC        (0x020E0050)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_RXD        (0x020E0054)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_RXFS       (0x020E0058)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_TXC        (0x020E005C)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_TXD        (0x020E0060)
#define IOMUXC_SW_MUX_CTL_PAD_AUD_TXFS       (0x020E0064)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI1_MISO    (0x020E0068)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI1_MOSI    (0x020E006C)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI1_SCLK    (0x020E0070)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI1_SS0     (0x020E0074)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI2_MISO    (0x020E0078)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI2_MOSI    (0x020E007C)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI2_SCLK    (0x020E0080)
#define IOMUXC_SW_MUX_CTL_PAD_ECSPI2_SS0     (0x020E0084)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_BDR0      (0x020E0088)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_BDR1      (0x020E008C)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D0        (0x020E0090)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D1        (0x020E0094)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D10       (0x020E0098)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D11       (0x020E009C)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D12       (0x020E00A0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D13       (0x020E00A4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D14       (0x020E00A8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D15       (0x020E00AC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D2        (0x020E00B0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D3        (0x020E00B4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D4        (0x020E00B8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D5        (0x020E00BC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D6        (0x020E00C0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D7        (0x020E00C4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D8        (0x020E00C8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_D9        (0x020E00CC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_GDCLK     (0x020E00D0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_GDOE      (0x020E00D4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_GDRL      (0x020E00D8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_GDSP      (0x020E00DC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRCOM    (0x020E00E0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRCTRL0  (0x020E00E4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRCTRL1  (0x020E00E8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRCTRL2  (0x020E00EC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRCTRL3  (0x020E00F0)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRINT    (0x020E00F4)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRSTAT   (0x020E00F8)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRWAKEUP (0x020E00FC)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDCE0     (0x020E0100)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDCE1     (0x020E0104)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDCE2     (0x020E0108)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDCE3     (0x020E010C)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDCLK     (0x020E0110)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDLE      (0x020E0114)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDOE      (0x020E0118)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_SDSHR     (0x020E011C)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_VCOM0     (0x020E0120)
#define IOMUXC_SW_MUX_CTL_PAD_EPDC_VCOM1     (0x020E0124)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_CRS_DV     (0x020E0128)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_MDC        (0x020E012C)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_MDIO       (0x020E0130)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_REF_CLK    (0x020E0134)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_RX_ER      (0x020E0138)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_RXD0       (0x020E013C)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_RXD1       (0x020E0140)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_TX_CLK     (0x020E0144)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_TX_EN      (0x020E0148)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_TXD0       (0x020E014C)
#define IOMUXC_SW_MUX_CTL_PAD_FEC_TXD1       (0x020E0150)
#define IOMUXC_SW_MUX_CTL_PAD_HSIC_DAT       (0x020E0154)
#define IOMUXC_SW_MUX_CTL_PAD_HSIC_STROBE    (0x020E0158)
#define IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL       (0x020E015C)
#define IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA       (0x020E0160)
#define IOMUXC_SW_MUX_CTL_PAD_I2C2_SCL       (0x020E0164)
#define IOMUXC_SW_MUX_CTL_PAD_I2C2_SDA       (0x020E0168)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL0       (0x020E016C)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL1       (0x020E0170)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL2       (0x020E0174)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL3       (0x020E0178)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL4       (0x020E017C)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL5       (0x020E0180)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL6       (0x020E0184)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_COL7       (0x020E0188)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0       (0x020E018C)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1       (0x020E0190)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2       (0x020E0194)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3       (0x020E0198)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4       (0x020E019C)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW5       (0x020E01A0)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW6       (0x020E01A4)
#define IOMUXC_SW_MUX_CTL_PAD_KEY_ROW7       (0x020E01A8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_CLK        (0x020E01AC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT0       (0x020E01B0)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT1       (0x020E01B4)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT10      (0x020E01B8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT11      (0x020E01BC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT12      (0x020E01C0)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT13      (0x020E01C4)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT14      (0x020E01C8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT15      (0x020E01CC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT16      (0x020E01D0)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT17      (0x020E01D4)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT18      (0x020E01D8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT19      (0x020E01DC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT2       (0x020E01E0)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT20      (0x020E01E4)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT21      (0x020E01E8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT22      (0x020E01EC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT23      (0x020E01F0)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT3       (0x020E01F4)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT4       (0x020E01F8)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT5       (0x020E01FC)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT6       (0x020E0200)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT7       (0x020E0204)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT8       (0x020E0208)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_DAT9       (0x020E020C)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_ENABLE     (0x020E0210)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_HSYNC      (0x020E0214)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_RESET      (0x020E0218)
#define IOMUXC_SW_MUX_CTL_PAD_LCD_VSYNC      (0x020E021C)
#define IOMUXC_SW_MUX_CTL_PAD_PWM1           (0x020E0220)
#define IOMUXC_SW_MUX_CTL_PAD_REF_CLK_24M    (0x020E0224)
#define IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K    (0x020E0228)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_CLK        (0x020E022C)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_CMD        (0x020E0230)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0       (0x020E0234)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1       (0x020E0238)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT2       (0x020E023C)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3       (0x020E0240)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT4       (0x020E0244)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT5       (0x020E0248)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT6       (0x020E024C)
#define IOMUXC_SW_MUX_CTL_PAD_SD1_DAT7       (0x020E0250)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_CLK        (0x020E0254)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_CMD        (0x020E0258)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT0       (0x020E025C)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT1       (0x020E0260)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2       (0x020E0264)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3       (0x020E0268)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT4       (0x020E026C)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT5       (0x020E0270)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT6       (0x020E0274)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_DAT7       (0x020E0278)
#define IOMUXC_SW_MUX_CTL_PAD_SD2_RST        (0x020E027C)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_CLK        (0x020E0280)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_CMD        (0x020E0284)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0       (0x020E0288)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1       (0x020E028C)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2       (0x020E0290)
#define IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3       (0x020E0294)
#define IOMUXC_SW_MUX_CTL_PAD_UART1_RXD      (0x020E0298)
#define IOMUXC_SW_MUX_CTL_PAD_UART1_TXD      (0x020E029C)
#define IOMUXC_SW_MUX_CTL_PAD_WDOG_B         (0x020E02A0)

//
// IOMUXC_SW_PAD_CTL_PAD_*
// IOMUXC_SW_PAD_CTL_GRP_*
//
#define IOMUXC_SW_PAD_CTL_PAD_AUD_MCLK       (0x020E02A4)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_RXC        (0x020E02A8)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_RXD        (0x020E02AC)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_RXFS       (0x020E02B0)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_TXC        (0x020E02B4)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_TXD        (0x020E02B8)
#define IOMUXC_SW_PAD_CTL_PAD_AUD_TXFS       (0x020E02BC)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A0        (0x020E02C0)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A1        (0x020E02C4)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A10       (0x020E02C8)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A11       (0x020E02CC)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A12       (0x020E02D0)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A13       (0x020E02D4)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A14       (0x020E02D8)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A15       (0x020E02DC)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A2        (0x020E02E0)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A3        (0x020E02E4)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A4        (0x020E02E8)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A5        (0x020E02EC)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A6        (0x020E02F0)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A7        (0x020E02F4)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A8        (0x020E02F8)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_A9        (0x020E02FC)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS       (0x020E0300)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_CS0       (0x020E0304)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_CS1       (0x020E0308)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0      (0x020E030C)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1      (0x020E0310)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2      (0x020E0314)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3      (0x020E0318)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS       (0x020E031C)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_RESET     (0x020E0320)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA0     (0x020E0324)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA1     (0x020E0328)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA2     (0x020E032C)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE0    (0x020E0330)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE1    (0x020E0334)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK_0   (0x020E0338)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT0    (0x020E033C)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDODT1    (0x020E0340)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0     (0x020E0344)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1     (0x020E0348)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2     (0x020E034C)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3     (0x020E0350)
#define IOMUXC_SW_PAD_CTL_PAD_DRAM_SDWE      (0x020E0354)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI1_MISO    (0x020E0358)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI1_MOSI    (0x020E035C)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI1_SCLK    (0x020E0360)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI1_SS0     (0x020E0364)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI2_MISO    (0x020E0368)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI2_MOSI    (0x020E036C)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI2_SCLK    (0x020E0370)
#define IOMUXC_SW_PAD_CTL_PAD_ECSPI2_SS0     (0x020E0374)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_BDR0      (0x020E0378)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_BDR1      (0x020E037C)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D0        (0x020E0380)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D1        (0x020E0384)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D10       (0x020E0388)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D11       (0x020E038C)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D12       (0x020E0390)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D13       (0x020E0394)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D14       (0x020E0398)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D15       (0x020E039C)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D2        (0x020E03A0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D3        (0x020E03A4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D4        (0x020E03A8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D5        (0x020E03AC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D6        (0x020E03B0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D7        (0x020E03B4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D8        (0x020E03B8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_D9        (0x020E03BC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_GDCLK     (0x020E03C0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_GDOE      (0x020E03C4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_GDRL      (0x020E03C8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_GDSP      (0x020E03CC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCOM    (0x020E03D0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCTRL0  (0x020E03D4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCTRL1  (0x020E03D8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCTRL2  (0x020E03DC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCTRL3  (0x020E03E0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRINT    (0x020E03E4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRSTAT   (0x020E03E8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRWAKEUP (0x020E03EC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDCE0     (0x020E03F0)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDCE1     (0x020E03F4)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDCE2     (0x020E03F8)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDCE3     (0x020E03FC)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDCLK     (0x020E0400)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDLE      (0x020E0404)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDOE      (0x020E0408)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_SDSHR     (0x020E040C)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_VCOM0     (0x020E0410)
#define IOMUXC_SW_PAD_CTL_PAD_EPDC_VCOM1     (0x020E0414)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_CRS_DV     (0x020E0418)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_MDC        (0x020E041C)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_MDIO       (0x020E0420)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_REF_CLK    (0x020E0424)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_RX_ER      (0x020E0428)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_RXD0       (0x020E042C)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_RXD1       (0x020E0430)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_TX_CLK     (0x020E0434)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_TX_EN      (0x020E0438)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_TXD0       (0x020E043C)
#define IOMUXC_SW_PAD_CTL_PAD_FEC_TXD1       (0x020E0440)
#define IOMUXC_SW_PAD_CTL_PAD_HSIC_DAT       (0x020E0444)
#define IOMUXC_SW_PAD_CTL_PAD_HSIC_STROBE    (0x020E0448)
#define IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL       (0x020E044C)
#define IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA       (0x020E0450)
#define IOMUXC_SW_PAD_CTL_PAD_I2C2_SCL       (0x020E0454)
#define IOMUXC_SW_PAD_CTL_PAD_I2C2_SDA       (0x020E0458)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD       (0x020E045C)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK       (0x020E0460)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI       (0x020E0464)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO       (0x020E0468)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS       (0x020E046C)
#define IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB     (0x020E0470)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL0       (0x020E0474)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL1       (0x020E0478)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL2       (0x020E047C)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL3       (0x020E0480)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL4       (0x020E0484)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL5       (0x020E0488)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL6       (0x020E048C)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_COL7       (0x020E0490)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0       (0x020E0494)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1       (0x020E0498)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2       (0x020E049C)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3       (0x020E04A0)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4       (0x020E04A4)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW5       (0x020E04A8)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW6       (0x020E04AC)
#define IOMUXC_SW_PAD_CTL_PAD_KEY_ROW7       (0x020E04B0)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_CLK        (0x020E04B4)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT0       (0x020E04B8)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT1       (0x020E04BC)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT10      (0x020E04C0)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT11      (0x020E04C4)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT12      (0x020E04C8)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT13      (0x020E04CC)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT14      (0x020E04D0)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT15      (0x020E04D4)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT16      (0x020E04D8)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT17      (0x020E04DC)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT18      (0x020E04E0)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT19      (0x020E04E4)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT2       (0x020E04E8)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT20      (0x020E04EC)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT21      (0x020E04F0)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT22      (0x020E04F4)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT23      (0x020E04F8)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT3       (0x020E04FC)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT4       (0x020E0500)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT5       (0x020E0504)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT6       (0x020E0508)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT7       (0x020E050C)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT8       (0x020E0510)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_DAT9       (0x020E0514)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_ENABLE     (0x020E0518)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_HSYNC      (0x020E051C)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_RESET      (0x020E0520)
#define IOMUXC_SW_PAD_CTL_PAD_LCD_VSYNC      (0x020E0524)
#define IOMUXC_SW_PAD_CTL_PAD_PWM1           (0x020E0528)
#define IOMUXC_SW_PAD_CTL_PAD_REF_CLK_24M    (0x020E052C)
#define IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K    (0x020E0530)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_CLK        (0x020E0534)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_CMD        (0x020E0538)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT0       (0x020E053C)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1       (0x020E0540)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT2       (0x020E0544)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT3       (0x020E0548)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT4       (0x020E054C)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT5       (0x020E0550)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT6       (0x020E0554)
#define IOMUXC_SW_PAD_CTL_PAD_SD1_DAT7       (0x020E0558)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_CLK        (0x020E055C)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_CMD        (0x020E0560)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT0       (0x020E0564)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT1       (0x020E0568)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT2       (0x020E056C)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3       (0x020E0570)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT4       (0x020E0574)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT5       (0x020E0578)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT6       (0x020E057C)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_DAT7       (0x020E0580)
#define IOMUXC_SW_PAD_CTL_PAD_SD2_RST        (0x020E0584)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_CLK        (0x020E0588)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_CMD        (0x020E058C)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0       (0x020E0590)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1       (0x020E0594)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2       (0x020E0598)
#define IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3       (0x020E059C)
#define IOMUXC_SW_PAD_CTL_PAD_UART1_RXD      (0x020E05A0)
#define IOMUXC_SW_PAD_CTL_PAD_UART1_TXD      (0x020E05A4)
#define IOMUXC_SW_PAD_CTL_PAD_WDOG_B         (0x020E05A8)
#define IOMUXC_SW_PAD_CTL_GRP_ADDDS          (0x020E05AC)
#define IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL    (0x020E05B0)
#define IOMUXC_SW_PAD_CTL_GRP_DDRPKE         (0x020E05B4)
#define IOMUXC_SW_PAD_CTL_GRP_DDRPK          (0x020E05B8)
#define IOMUXC_SW_PAD_CTL_GRP_DDRHYS         (0x020E05BC)
#define IOMUXC_SW_PAD_CTL_GRP_DDRMODE        (0x020E05C0)
#define IOMUXC_SW_PAD_CTL_GRP_B0DS           (0x020E05C4)
#define IOMUXC_SW_PAD_CTL_GRP_CTLDS          (0x020E05C8)
#define IOMUXC_SW_PAD_CTL_GRP_B1DS           (0x020E05CC)
#define IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE       (0x020E05D0)
#define IOMUXC_SW_PAD_CTL_GRP_B2DS           (0x020E05D4)
#define IOMUXC_SW_PAD_CTL_GRP_B3DS           (0x020E05D8)

//
// IOMUXC_*_SELECT_INPUT
//
#define IOMUXC_ANALOG_USB_OTG_ID_SELECT_INPUT          (0x020E05DC)
#define IOMUXC_ANALOG_USB_UH1_ID_SELECT_INPUT          (0x020E05E0)
#define IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT     (0x020E05E4)
#define IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT     (0x020E05E8)
#define IOMUXC_AUDMUX_P4_INPUT_RXCLK_AMX_SELECT_INPUT  (0x020E05EC)
#define IOMUXC_AUDMUX_P4_INPUT_RXFS_AMX_SELECT_INPUT   (0x020E05F0)
#define IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT  (0x020E05F4)
#define IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT   (0x020E05F8)
#define IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT     (0x020E05FC)
#define IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT     (0x020E0600)
#define IOMUXC_AUDMUX_P5_INPUT_RXCLK_AMX_SELECT_INPUT  (0x020E0604)
#define IOMUXC_AUDMUX_P5_INPUT_RXFS_AMX_SELECT_INPUT   (0x020E0608)
#define IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT  (0x020E060C)
#define IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT   (0x020E0610)
#define IOMUXC_AUDMUX_P6_INPUT_DA_AMX_SELECT_INPUT     (0x020E0614)
#define IOMUXC_AUDMUX_P6_INPUT_DB_AMX_SELECT_INPUT     (0x020E0618)
#define IOMUXC_AUDMUX_P6_INPUT_RXCLK_AMX_SELECT_INPUT  (0x020E061C)
#define IOMUXC_AUDMUX_P6_INPUT_RXFS_AMX_SELECT_INPUT   (0x020E0620)
#define IOMUXC_AUDMUX_P6_INPUT_TXCLK_AMX_SELECT_INPUT  (0x020E0624)
#define IOMUXC_AUDMUX_P6_INPUT_TXFS_AMX_SELECT_INPUT   (0x020E0628)
#define IOMUXC_CCM_PMIC_VFUNCIONAL_READY_SELECT_INPUT  (0x020E062C)
#define IOMUXC_CSI_IPP_CSI_D_0_SELECT_INPUT            (0x020E0630)
#define IOMUXC_CSI_IPP_CSI_D_1_SELECT_INPUT            (0x020E0634)
#define IOMUXC_CSI_IPP_CSI_D_2_SELECT_INPUT            (0x020E0638)
#define IOMUXC_CSI_IPP_CSI_D_3_SELECT_INPUT            (0x020E063C)
#define IOMUXC_CSI_IPP_CSI_D_4_SELECT_INPUT            (0x020E0640)
#define IOMUXC_CSI_IPP_CSI_D_5_SELECT_INPUT            (0x020E0644)
#define IOMUXC_CSI_IPP_CSI_D_6_SELECT_INPUT            (0x020E0648)
#define IOMUXC_CSI_IPP_CSI_D_7_SELECT_INPUT            (0x020E064C)
#define IOMUXC_CSI_IPP_CSI_D_8_SELECT_INPUT            (0x020E0650)
#define IOMUXC_CSI_IPP_CSI_D_9_SELECT_INPUT            (0x020E0654)
#define IOMUXC_CSI_IPP_CSI_D_10_SELECT_INPUT           (0x020E0658)
#define IOMUXC_CSI_IPP_CSI_D_11_SELECT_INPUT           (0x020E065C)
#define IOMUXC_CSI_IPP_CSI_D_12_SELECT_INPUT           (0x020E0660)
#define IOMUXC_CSI_IPP_CSI_D_13_SELECT_INPUT           (0x020E0664)
#define IOMUXC_CSI_IPP_CSI_D_14_SELECT_INPUT           (0x020E0668)
#define IOMUXC_CSI_IPP_CSI_D_15_SELECT_INPUT           (0x020E066C)
#define IOMUXC_CSI_IPP_CSI_HSYNC_SELECT_INPUT          (0x020E0670)
#define IOMUXC_CSI_IPP_CSI_PIXCLK_SELECT_INPUT         (0x020E0674)
#define IOMUXC_CSI_IPP_CSI_VSYNC_SELECT_INPUT          (0x020E0678)
#define IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT     (0x020E067C)
#define IOMUXC_ECSPI1_IPP_IND_DATAREADY_B_SELECT_INPUT (0x020E0680)
#define IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT        (0x020E0684)
#define IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT        (0x020E0688)
#define IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT      (0x020E068C)
#define IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT      (0x020E0690)
#define IOMUXC_ECSPI1_IPP_IND_SS_B_2_SELECT_INPUT      (0x020E0694)
#define IOMUXC_ECSPI1_IPP_IND_SS_B_3_SELECT_INPUT      (0x020E0698)
#define IOMUXC_ECSPI2_IPP_CSPI_CLK_IN_SELECT_INPUT     (0x020E069C)
#define IOMUXC_ECSPI2_IPP_IND_MISO_SELECT_INPUT        (0x020E06A0)
#define IOMUXC_ECSPI2_IPP_IND_MOSI_SELECT_INPUT        (0x020E06A4)
#define IOMUXC_ECSPI2_IPP_IND_SS_B_0_SELECT_INPUT      (0x020E06A8)
#define IOMUXC_ECSPI2_IPP_IND_SS_B_1_SELECT_INPUT      (0x020E06AC)
#define IOMUXC_ECSPI3_IPP_CSPI_CLK_IN_SELECT_INPUT     (0x020E06B0)
#define IOMUXC_ECSPI3_IPP_IND_DATAREADY_B_SELECT_INPUT (0x020E06B4)
#define IOMUXC_ECSPI3_IPP_IND_MISO_SELECT_INPUT        (0x020E06B8)
#define IOMUXC_ECSPI3_IPP_IND_MOSI_SELECT_INPUT        (0x020E06BC)
#define IOMUXC_ECSPI3_IPP_IND_SS_B_0_SELECT_INPUT      (0x020E06C0)
#define IOMUXC_ECSPI3_IPP_IND_SS_B_1_SELECT_INPUT      (0x020E06C4)
#define IOMUXC_ECSPI3_IPP_IND_SS_B_2_SELECT_INPUT      (0x020E06C8)
#define IOMUXC_ECSPI3_IPP_IND_SS_B_3_SELECT_INPUT      (0x020E06CC)
#define IOMUXC_ECSPI4_IPP_CSPI_CLK_IN_SELECT_INPUT     (0x020E06D0)
#define IOMUXC_ECSPI4_IPP_IND_MISO_SELECT_INPUT        (0x020E06D4)
#define IOMUXC_ECSPI4_IPP_IND_MOSI_SELECT_INPUT        (0x020E06D8)
#define IOMUXC_ECSPI4_IPP_IND_SS_B_0_SELECT_INPUT      (0x020E06DC)
#define IOMUXC_ECSPI4_IPP_IND_SS_B_1_SELECT_INPUT      (0x020E06E0)
#define IOMUXC_ECSPI4_IPP_IND_SS_B_2_SELECT_INPUT      (0x020E06E4)
#define IOMUXC_EPDC_IPP_EPDC_PWRIRQ_SELECT_INPUT       (0x020E06E8)
#define IOMUXC_EPDC_IPP_EPDC_PWRSTAT_SELECT_INPUT      (0x020E06EC)
#define IOMUXC_FEC_FEC_COL_SELECT_INPUT                (0x020E06F0)
#define IOMUXC_FEC_FEC_MDI_SELECT_INPUT                (0x020E06F4)
#define IOMUXC_FEC_FEC_RDATA_0_SELECT_INPUT            (0x020E06F8)
#define IOMUXC_FEC_FEC_RDATA_1_SELECT_INPUT            (0x020E06FC)
#define IOMUXC_FEC_FEC_RX_CLK_SELECT_INPUT             (0x020E0700)
#define IOMUXC_FEC_FEC_RX_DV_SELECT_INPUT              (0x020E0704)
#define IOMUXC_FEC_FEC_RX_ER_SELECT_INPUT              (0x020E0708)
#define IOMUXC_FEC_FEC_TX_CLK_SELECT_INPUT             (0x020E070C)
#define IOMUXC_GPT_IPP_IND_CAPIN1_SELECT_INPUT         (0x020E0710)
#define IOMUXC_GPT_IPP_IND_CAPIN2_SELECT_INPUT         (0x020E0714)
#define IOMUXC_GPT_IPP_IND_CLKIN_SELECT_INPUT          (0x020E0718)
#define IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT            (0x020E071C)
#define IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT            (0x020E0720)
#define IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT            (0x020E0724)
#define IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT            (0x020E0728)
#define IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT            (0x020E072C)
#define IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT            (0x020E0730)
#define IOMUXC_KPP_IPP_IND_COL_0_SELECT_INPUT          (0x020E0734)
#define IOMUXC_KPP_IPP_IND_COL_1_SELECT_INPUT          (0x020E0738)
#define IOMUXC_KPP_IPP_IND_COL_2_SELECT_INPUT          (0x020E073C)
#define IOMUXC_KPP_IPP_IND_COL_3_SELECT_INPUT          (0x020E0740)
#define IOMUXC_KPP_IPP_IND_COL_4_SELECT_INPUT          (0x020E0744)
#define IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT          (0x020E0748)
#define IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT          (0x020E074C)
#define IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT          (0x020E0750)
#define IOMUXC_KPP_IPP_IND_ROW_0_SELECT_INPUT          (0x020E0754)
#define IOMUXC_KPP_IPP_IND_ROW_1_SELECT_INPUT          (0x020E0758)
#define IOMUXC_KPP_IPP_IND_ROW_2_SELECT_INPUT          (0x020E075C)
#define IOMUXC_KPP_IPP_IND_ROW_3_SELECT_INPUT          (0x020E0760)
#define IOMUXC_KPP_IPP_IND_ROW_4_SELECT_INPUT          (0x020E0764)
#define IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT          (0x020E0768)
#define IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT          (0x020E076C)
#define IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT          (0x020E0770)
#define IOMUXC_LCDIF_LCDIF_BUSY_SELECT_INPUT           (0x020E0774)
#define IOMUXC_LCDIF_LCDIF_RXDATA_0_SELECT_INPUT       (0x020E0778)
#define IOMUXC_LCDIF_LCDIF_RXDATA_1_SELECT_INPUT       (0x020E077C)
#define IOMUXC_LCDIF_LCDIF_RXDATA_2_SELECT_INPUT       (0x020E0780)
#define IOMUXC_LCDIF_LCDIF_RXDATA_3_SELECT_INPUT       (0x020E0784)
#define IOMUXC_LCDIF_LCDIF_RXDATA_4_SELECT_INPUT       (0x020E0788)
#define IOMUXC_LCDIF_LCDIF_RXDATA_5_SELECT_INPUT       (0x020E078C)
#define IOMUXC_LCDIF_LCDIF_RXDATA_6_SELECT_INPUT       (0x020E0790)
#define IOMUXC_LCDIF_LCDIF_RXDATA_7_SELECT_INPUT       (0x020E0794)
#define IOMUXC_LCDIF_LCDIF_RXDATA_8_SELECT_INPUT       (0x020E0798)
#define IOMUXC_LCDIF_LCDIF_RXDATA_9_SELECT_INPUT       (0x020E079C)
#define IOMUXC_LCDIF_LCDIF_RXDATA_10_SELECT_INPUT      (0x020E07A0)
#define IOMUXC_LCDIF_LCDIF_RXDATA_11_SELECT_INPUT      (0x020E07A4)
#define IOMUXC_LCDIF_LCDIF_RXDATA_12_SELECT_INPUT      (0x020E07A8)
#define IOMUXC_LCDIF_LCDIF_RXDATA_13_SELECT_INPUT      (0x020E07AC)
#define IOMUXC_LCDIF_LCDIF_RXDATA_14_SELECT_INPUT      (0x020E07B0)
#define IOMUXC_LCDIF_LCDIF_RXDATA_15_SELECT_INPUT      (0x020E07B4)
#define IOMUXC_LCDIF_LCDIF_RXDATA_16_SELECT_INPUT      (0x020E07B8)
#define IOMUXC_LCDIF_LCDIF_RXDATA_17_SELECT_INPUT      (0x020E07BC)
#define IOMUXC_LCDIF_LCDIF_RXDATA_18_SELECT_INPUT      (0x020E07C0)
#define IOMUXC_LCDIF_LCDIF_RXDATA_19_SELECT_INPUT      (0x020E07C4)
#define IOMUXC_LCDIF_LCDIF_RXDATA_20_SELECT_INPUT      (0x020E07C8)
#define IOMUXC_LCDIF_LCDIF_RXDATA_21_SELECT_INPUT      (0x020E07CC)
#define IOMUXC_LCDIF_LCDIF_RXDATA_22_SELECT_INPUT      (0x020E07D0)
#define IOMUXC_LCDIF_LCDIF_RXDATA_23_SELECT_INPUT      (0x020E07D4)
#define IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT            (0x020E07F0)
#define IOMUXC_SPDIF_TX_CLK2_SELECT_INPUT              (0x020E07F4)
#define IOMUXC_UART1_IPP_UART_RTS_B_SELECT_INPUT       (0x020E07F8)
#define IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT     (0x020E07FC)
#define IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT       (0x020E0800)
#define IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT     (0x020E0804)
#define IOMUXC_UART3_IPP_UART_RTS_B_SELECT_INPUT       (0x020E0808)
#define IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT     (0x020E080C)
#define IOMUXC_UART4_IPP_UART_RTS_B_SELECT_INPUT       (0x020E0810)
#define IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT     (0x020E0814)
#define IOMUXC_UART5_IPP_UART_RTS_B_SELECT_INPUT       (0x020E0818)
#define IOMUXC_UART5_IPP_UART_RXD_MUX_SELECT_INPUT     (0x020E081C)
#define IOMUXC_USB_IPP_IND_OTG2_OC_SELECT_INPUT        (0x020E0820)
#define IOMUXC_USB_IPP_IND_OTG_OC_SELECT_INPUT         (0x020E0824)
#define IOMUXC_USDHC1_IPP_CARD_DET_SELECT_INPUT        (0x020E0828)
#define IOMUXC_USDHC1_IPP_WP_ON_SELECT_INPUT           (0x020E082C)
#define IOMUXC_USDHC2_IPP_CARD_DET_SELECT_INPUT        (0x020E0830)
#define IOMUXC_USDHC2_IPP_WP_ON_SELECT_INPUT           (0x020E0834)
#define IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT        (0x020E0838)
#define IOMUXC_USDHC3_IPP_DAT4_IN_SELECT_INPUT         (0x020E083C)
#define IOMUXC_USDHC3_IPP_DAT5_IN_SELECT_INPUT         (0x020E0840)
#define IOMUXC_USDHC3_IPP_DAT6_IN_SELECT_INPUT         (0x020E0844)
#define IOMUXC_USDHC3_IPP_DAT7_IN_SELECT_INPUT         (0x020E0848)
#define IOMUXC_USDHC3_IPP_WP_ON_SELECT_INPUT           (0x020E084C)
#define IOMUXC_USDHC4_IPP_CARD_CLK_IN_SELECT_INPUT     (0x020E0850)
#define IOMUXC_USDHC4_IPP_CARD_DET_SELECT_INPUT        (0x020E0854)
#define IOMUXC_USDHC4_IPP_CMD_IN_SELECT_INPUT          (0x020E0858)
#define IOMUXC_USDHC4_IPP_DAT0_IN_SELECT_INPUT         (0x020E085C)
#define IOMUXC_USDHC4_IPP_DAT1_IN_SELECT_INPUT         (0x020E0860)
#define IOMUXC_USDHC4_IPP_DAT2_IN_SELECT_INPUT         (0x020E0864)
#define IOMUXC_USDHC4_IPP_DAT3_IN_SELECT_INPUT         (0x020E0868)
#define IOMUXC_USDHC4_IPP_DAT4_IN_SELECT_INPUT         (0x020E086C)
#define IOMUXC_USDHC4_IPP_DAT5_IN_SELECT_INPUT         (0x020E0870)
#define IOMUXC_USDHC4_IPP_DAT6_IN_SELECT_INPUT         (0x020E0874)
#define IOMUXC_USDHC4_IPP_DAT7_IN_SELECT_INPUT         (0x020E0878)
#define IOMUXC_USDHC4_IPP_WP_ON_SELECT_INPUT           (0x020E087C)
#define IOMUXC_WEIM_IPP_IND_DTACK_B_SELECT_INPUT       (0x020E0880)
#define IOMUXC_WEIM_IPP_IND_WAIT_B_SELECT_INPUT        (0x020E0884)

#endif // _IOMUX_REGISTER_H_
