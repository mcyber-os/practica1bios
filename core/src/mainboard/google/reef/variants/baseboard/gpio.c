/*
 * This file is part of the coreboot project.
 *
 * Copyright 2016 Google Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>

/*
 * Pad configuration in ramstage. The order largely follows the 'GPIO Muxing'
 * table found in EDS vol 1, but some pins aren't grouped functionally in
 * the table so those were moved for more logical grouping.
 */
static const struct pad_config gpio_table[] = {
	/* PCIE_WAKE[0:3]_N */
	PAD_CFG_GPI_SCI_LOW(GPIO_205, UP_20K, DEEP, EDGE_SINGLE), /* WLAN */
	PAD_CFG_GPI(GPIO_206, UP_20K, DEEP),	 /* Unused */
	PAD_CFG_GPI(GPIO_207, UP_20K, DEEP),	 /* Unused */
	PAD_CFG_GPI(GPIO_208, UP_20K, DEEP),	 /* Unused */

	/* EMMC interface */
	PAD_CFG_NF(GPIO_156, DN_20K, DEEP, NF1), /* EMMC_CLK */
	PAD_CFG_NF(GPIO_157, UP_20K, DEEP, NF1), /* EMMC_D0 */
	PAD_CFG_NF(GPIO_158, UP_20K, DEEP, NF1), /* EMMC_D1 */
	PAD_CFG_NF(GPIO_159, UP_20K, DEEP, NF1), /* EMMC_D2 */
	PAD_CFG_NF(GPIO_160, UP_20K, DEEP, NF1), /* EMMC_D3 */
	PAD_CFG_NF(GPIO_161, UP_20K, DEEP, NF1), /* EMMC_D4 */
	PAD_CFG_NF(GPIO_162, UP_20K, DEEP, NF1), /* EMMC_D5 */
	PAD_CFG_NF(GPIO_163, UP_20K, DEEP, NF1), /* EMMC_D6 */
	PAD_CFG_NF(GPIO_164, UP_20K, DEEP, NF1), /* EMMC_D7 */
	PAD_CFG_NF(GPIO_165, UP_20K, DEEP, NF1), /* EMMC_CMD */
	PAD_CFG_NF(GPIO_182, DN_20K, DEEP, NF1), /* EMMC_RCLK */

	/* SDIO -- unused. */
	PAD_CFG_GPI(GPIO_166, UP_20K, DEEP),	 /* SDIO_CLK */
	PAD_CFG_GPI(GPIO_167, UP_20K, DEEP),	 /* SDIO_D0 */
	/* Configure SDIO to enable power gating */
	PAD_CFG_NF(GPIO_168, UP_20K, DEEP, NF1),	/* SDIO_D1 */
	PAD_CFG_GPI(GPIO_169, UP_20K, DEEP),	 /* SDIO_D2 */
	PAD_CFG_GPI(GPIO_170, UP_20K, DEEP),	 /* SDIO_D3 */
	PAD_CFG_GPI(GPIO_171, UP_20K, DEEP),	 /* SDIO_CMD */

	/* SDCARD */
	/* Pull down clock by 20K */
	PAD_CFG_NF(GPIO_172, DN_20K, DEEP, NF1), /* SDCARD_CLK */
	PAD_CFG_NF(GPIO_173, UP_20K, DEEP, NF1), /* SDCARD_D0 */
	PAD_CFG_NF(GPIO_174, UP_20K, DEEP, NF1), /* SDCARD_D1 */
	PAD_CFG_NF(GPIO_175, UP_20K, DEEP, NF1), /* SDCARD_D2 */
	PAD_CFG_NF(GPIO_176, UP_20K, DEEP, NF1), /* SDCARD_D3 */
	/* Card detect is active LOW with external pull up. */
	PAD_CFG_NF(GPIO_177, NONE, DEEP, NF1), /* SDCARD_CD_N */
	PAD_CFG_NF(GPIO_178, UP_20K, DEEP, NF1), /* SDCARD_CMD */
	/* CLK feedback, internal signal, needs 20K pull down */
	PAD_CFG_NF(GPIO_179, DN_20K, DEEP, NF1), /* SDCARD_CLK_FB */
	/* No h/w write proect for uSD cards, pull down by 20K */
	PAD_CFG_NF(GPIO_186, DN_20K, DEEP, NF1), /* SDCARD_LVL_WP */
	/* EN_SD_SOCKET_PWR_L for SD slot power control. Default on. */
	PAD_CFG_GPO(GPIO_183, 0, DEEP),		 /* SDIO_PWR_DOWN_N */

	/* SMBus -- unused. */
	PAD_CFG_GPI(SMB_ALERTB, UP_20K, DEEP),	 /* SMB_ALERT _N */
	PAD_CFG_GPI(SMB_CLK, UP_20K, DEEP),	 /* SMB_CLK */
	PAD_CFG_GPI(SMB_DATA, UP_20K, DEEP),	 /* SMB_DATA */

	/* LPC */
	PAD_CFG_NF(LPC_ILB_SERIRQ, UP_20K, DEEP, NF1), /* LPC_SERIRQ */
	PAD_CFG_NF(LPC_CLKOUT0, NONE, DEEP, NF1), /* LPC_CLKOUT0 */
	PAD_CFG_GPI(LPC_CLKOUT1, UP_20K, DEEP),	 /* LPC_CLKOUT1 -- unused */
	PAD_CFG_NF(LPC_AD0, UP_20K, DEEP, NF1),	 /* LPC_AD0 */
	PAD_CFG_NF(LPC_AD1, UP_20K, DEEP, NF1),	 /* LPC_AD1 */
	PAD_CFG_NF(LPC_AD2, UP_20K, DEEP, NF1),	 /* LPC_AD2 */
	PAD_CFG_NF(LPC_AD3, UP_20K, DEEP, NF1),	 /* LPC_AD3 */
	PAD_CFG_NF(LPC_CLKRUNB, UP_20K, DEEP, NF1), /* LPC_CLKRUN_N */
	PAD_CFG_NF(LPC_FRAMEB, NATIVE, DEEP, NF1), /* LPC_FRAME_N */

	/* I2C0 - Audio */
	PAD_CFG_NF(GPIO_124, UP_2K, DEEP, NF1), /* LPSS_I2C0_SDA */
	PAD_CFG_NF(GPIO_125, UP_2K, DEEP, NF1), /* LPSS_I2C0_SCL */

	/* I2C1 - NFC with external pulls */
	PAD_CFG_NF(GPIO_126, NONE, DEEP, NF1), /* LPSS_I2C1_SDA */
	PAD_CFG_NF(GPIO_127, NONE, DEEP, NF1), /* LPSS_I2C1_SCL */

	/* I2C2 - TPM  */
	PAD_CFG_NF(GPIO_128, UP_2K, DEEP, NF1), /* LPSS_I2C2_SDA */
	PAD_CFG_NF(GPIO_129, UP_2K, DEEP, NF1), /* LPSS_I2C2_SCL */

	/* I2C3 - touch */
	PAD_CFG_NF(GPIO_130, UP_2K, DEEP, NF1), /* LPSS_I2C3_SDA */
	PAD_CFG_NF(GPIO_131, UP_2K, DEEP, NF1), /* LPSS_I2C3_SCL */

	/* I2C4 - trackpad */
	/* LPSS_I2C4_SDA */
	PAD_CFG_NF_IOSSTATE(GPIO_132, UP_2K, DEEP, NF1, HIZCRx1),
	/* LPSS_I2C4_SCL */
	PAD_CFG_NF_IOSSTATE(GPIO_133, UP_2K, DEEP, NF1, HIZCRx1),

	/* I2C5 -- pen with external pulls  */
	PAD_CFG_NF(GPIO_134, NONE, DEEP, NF1), /* LPSS_I2C5_SDA */
	PAD_CFG_NF(GPIO_135, NONE, DEEP, NF1), /* LPSS_I2C5_SCL */

	/* I2C6-7 -- unused. */
	PAD_CFG_GPI(GPIO_136, UP_20K, DEEP),	 /* LPSS_I2C6_SDA */
	PAD_CFG_GPI(GPIO_137, UP_20K, DEEP),	 /* LPSS_I2C6_SCL */
	PAD_CFG_GPI(GPIO_138, UP_20K, DEEP),	 /* LPSS_I2C7_SDA */
	PAD_CFG_GPI(GPIO_139, UP_20K, DEEP),	 /* LPSS_I2C7_SCL */

	/* Audio Amp - I2S6 */
	PAD_CFG_NF(GPIO_146, NATIVE, DEEP, NF2), /* ISH_GPIO_0 - I2S6_BCLK */
	PAD_CFG_NF(GPIO_147, NATIVE, DEEP, NF2), /* ISH_GPIO_1 - I2S6_WS_SYNC */
	PAD_CFG_GPI(GPIO_148, UP_20K, DEEP),	 /* ISH_GPIO_2 - unused */
	PAD_CFG_NF(GPIO_149, NATIVE, DEEP, NF2), /* ISH_GPIO_3 - I2S6_SDO */

	/* NFC Reset */
	PAD_CFG_GPO(GPIO_150, 1, DEEP),		 /* ISH_GPIO_4 */

	PAD_CFG_GPI(GPIO_151, UP_20K, DEEP),	 /* ISH_GPIO_5 - unused */

	/* Touch enable */
	PAD_CFG_GPO(GPIO_152, 1, DEEP),		 /* ISH_GPIO_6 */

	PAD_CFG_GPI(GPIO_153, UP_20K, DEEP),	 /* ISH_GPIO_7 - unused */
	PAD_CFG_GPI(GPIO_154, UP_20K, DEEP),	 /* ISH_GPIO_8 - unused */
	PAD_CFG_GPI(GPIO_155, UP_20K, DEEP),	 /* ISH_GPIO_9 - unused */

	/* PCIE_CLKREQ[0:3]_N */
	PAD_CFG_NF(GPIO_209, NONE, DEEP, NF1),	 /* WLAN with external pull */
	PAD_CFG_GPI(GPIO_210, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_211, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_212, UP_20K, DEEP),	 /* unused */

	/* OSC_CLK_OUT_[0:4] -- unused */
	PAD_CFG_GPI(OSC_CLK_OUT_0, UP_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_1, UP_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_2, UP_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_3, UP_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_4, UP_20K, DEEP),

	/* PMU Signals */
	PAD_CFG_GPI(PMU_AC_PRESENT, UP_20K, DEEP), /* PMU_AC_PRESENT - unused */
	PAD_CFG_NF(PMU_BATLOW_B, UP_20K, DEEP, NF1), /* PMU_BATLOW_N */
	PAD_CFG_NF(PMU_PLTRST_B, NONE, DEEP, NF1), /* PMU_PLTRST_N */
	PAD_CFG_NF(PMU_PWRBTN_B, UP_20K, DEEP, NF1), /* PMU_PWRBTN_N */
	PAD_CFG_NF(PMU_RESETBUTTON_B, NONE, DEEP, NF1), /* PMU_RSTBTN_N */
	PAD_CFG_NF_IOSSTATE(PMU_SLP_S0_B, NONE, DEEP, NF1, IGNORE), /* PMU_SLP_S0_N */
	PAD_CFG_NF(PMU_SLP_S3_B, NONE, DEEP, NF1), /* PMU_SLP_S3_N */
	PAD_CFG_NF(PMU_SLP_S4_B, NONE, DEEP, NF1), /* PMU_SLP_S4_N */
	PAD_CFG_NF(PMU_SUSCLK, NONE, DEEP, NF1), /* PMU_SUSCLK */
	PAD_CFG_GPO(PMU_WAKE_B, 1, DEEP),	 /* EN_PP3300_EMMC */
	PAD_CFG_NF(SUS_STAT_B, NONE, DEEP, NF1), /* SUS_STAT_N */
	PAD_CFG_NF(SUSPWRDNACK, NONE, DEEP, NF1), /* SUSPWRDNACK */

	/* DDI[0:1] SDA and SCL -- unused */
	PAD_CFG_GPI(GPIO_187, UP_20K, DEEP),	 /* HV_DDI0_DDC_SDA */
	PAD_CFG_GPI(GPIO_188, UP_20K, DEEP),	 /* HV_DDI0_DDC_SCL */
	PAD_CFG_GPI(GPIO_189, UP_20K, DEEP),	 /* HV_DDI1_DDC_SDA */
	PAD_CFG_GPI(GPIO_190, UP_20K, DEEP),	 /* HV_DDI1_DDC_SCL */

	/* MIPI I2C -- unused */
	PAD_CFG_GPI(GPIO_191, UP_20K, DEEP),	 /* MIPI_I2C_SDA */
	PAD_CFG_GPI(GPIO_192, UP_20K, DEEP),	 /* MIPI_I2C_SCL */

	/* Panel 0 control */
	PAD_CFG_NF(GPIO_193, NATIVE, DEEP, NF1), /* PNL0_VDDEN */
	PAD_CFG_NF(GPIO_194, NATIVE, DEEP, NF1), /* PNL0_BKLTEN */
	PAD_CFG_NF(GPIO_195, NATIVE, DEEP, NF1), /* PNL0_BKLTCTL */

	/* Panel 1 control -- unused */
	PAD_CFG_NF(GPIO_196, NATIVE, DEEP, NF1), /* PNL1_VDDEN */
	PAD_CFG_NF(GPIO_197, NATIVE, DEEP, NF1), /* PNL1_BKLTEN */
	PAD_CFG_NF(GPIO_198, NATIVE, DEEP, NF1), /* PNL1_BKLTCTL */

	/* Hot plug detect. */
	PAD_CFG_NF(GPIO_199, UP_20K, DEEP, NF2), /* HV_DDI1_HPD */
	PAD_CFG_NF(GPIO_200, UP_20K, DEEP, NF2), /* HV_DDI0_HPD */

	/* MDSI signals -- unused */
	PAD_CFG_GPI(GPIO_201, UP_20K, DEEP),	 /* MDSI_A_TE */
	PAD_CFG_GPI(GPIO_202, UP_20K, DEEP),	 /* MDSI_A_TE */

	/* USB overcurrent pins. */
	PAD_CFG_NF(GPIO_203, UP_20K, DEEP, NF1), /* USB_OC0_N */
	PAD_CFG_NF(GPIO_204, UP_20K, DEEP, NF1), /* USB_OC1_N */

	/* PMC SPI -- almost entirely unused */
	PAD_CFG_GPI(PMC_SPI_FS0, UP_20K, DEEP),
	PAD_CFG_NF(PMC_SPI_FS1, UP_20K, DEEP, NF2), /* HV_DDI2_HPD -- EDP HPD */
	PAD_CFG_GPI(PMC_SPI_FS2, UP_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_RXD, UP_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_TXD, UP_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_CLK, UP_20K, DEEP),

	/* PMIC Signals Unused signals related to an old PMIC interface */
	PAD_CFG_NF_IOSSTATE(PMIC_RESET_B, NATIVE, DEEP, NF1, IGNORE), /* PMIC_RESET_B */
	PAD_CFG_GPI(GPIO_213, NONE, DEEP),	 /* unused external pull */
	PAD_CFG_GPI(GPIO_214, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_215, UP_20K, DEEP),	 /* unused */
	PAD_CFG_NF(PMIC_THERMTRIP_B, UP_20K, DEEP, NF1), /* THERMTRIP_N */
	PAD_CFG_GPI(PMIC_STDBY, UP_20K, DEEP),	 /* unused */
	PAD_CFG_NF(PROCHOT_B, UP_20K, DEEP, NF1), /* PROCHOT_N */
	PAD_CFG_NF(PMIC_I2C_SCL, UP_1K, DEEP, NF1), /* PMIC_I2C_SCL */
	PAD_CFG_NF(PMIC_I2C_SDA, UP_1K, DEEP, NF1), /* PMIC_I2C_SDA */

	/* I2S1 -- largely unused */
	PAD_CFG_GPI(GPIO_74, UP_20K, DEEP),	 /* I2S1_MCLK */
	PAD_CFG_GPI(GPIO_75, UP_20K, DEEP),	 /* I2S1_BCLK -- PCH_WP */
	PAD_CFG_GPO(GPIO_76, 0, DEEP),	/* I2S1_WS_SYNC -- SPK_PA_EN */
	PAD_CFG_GPI(GPIO_77, UP_20K, DEEP),	 /* I2S1_SDI */
	PAD_CFG_GPI(GPIO_78, UP_20K, DEEP),	 /* I2S1_SDO */

	/* DMIC or I2S4 */
	/* AVS_DMIC_CLK_A1 */
	PAD_CFG_NF_IOSSTATE(GPIO_79, NATIVE, DEEP, NF1, IGNORE),
	/* AVS_DMIC_CLK_B1 */
	PAD_CFG_NF_IOSSTATE(GPIO_80, NATIVE, DEEP, NF1, IGNORE),
	PAD_CFG_NF(GPIO_81, NATIVE, DEEP, NF1),	/* AVS_DMIC_DATA_1 */
	PAD_CFG_GPI(GPIO_82, DN_20K, DEEP),	 /* unused -- strap */
	PAD_CFG_NF(GPIO_83, NATIVE, DEEP, NF1), /* AVS_DMIC_DATA_2 */

	/* I2S2 -- Headset amp */
	PAD_CFG_NF(GPIO_84, NATIVE, DEEP, NF1),	 /* AVS_I2S2_MCLK */
	PAD_CFG_NF(GPIO_85, NATIVE, DEEP, NF1),	 /* AVS_I2S2_BCLK */
	PAD_CFG_NF(GPIO_86, NATIVE, DEEP, NF1),	 /* AVS_I2S2_SW_SYNC */
	PAD_CFG_NF(GPIO_87, NATIVE, DEEP, NF1),	 /* AVS_I2S2_SDI */
	PAD_CFG_NF(GPIO_88, NATIVE, DEEP, NF1),	 /* AVS_I2S2_SDO */

	/* I2S3 -- largely unused. */
	PAD_CFG_GPI(GPIO_89, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_90, UP_20K, DEEP),	 /* GPS_HOST_WAKE */
	PAD_CFG_GPO(GPIO_91, 1, DEEP),		 /* GPS_EN */
	PAD_CFG_GPI(GPIO_92, DN_20K, DEEP),	 /* unused -- strap */

	/* Fast SPI */
	PAD_CFG_NF_IOSSTATE(GPIO_97, NATIVE, DEEP, NF1, IGNORE),	/* FST_SPI_CS0_B */
	PAD_CFG_GPI(GPIO_98, UP_20K, DEEP),				/* FST_SPI_CS1_B -- unused */
	PAD_CFG_NF_IOSSTATE(GPIO_99, NATIVE, DEEP, NF1, IGNORE),	/* FST_SPI_MOSI_IO0 */
	PAD_CFG_NF_IOSSTATE(GPIO_100, NATIVE, DEEP, NF1, IGNORE),	/* FST_SPI_MISO_IO1 */
	PAD_CFG_GPI(GPIO_101, UP_20K, DEEP),				/* FST_IO2 -- MEM_CONFIG0 */
	PAD_CFG_GPI(GPIO_102, UP_20K, DEEP),				/* FST_IO3 -- MEM_CONFIG1 */
	PAD_CFG_NF_IOSSTATE(GPIO_103, NATIVE, DEEP, NF1, IGNORE),	/* FST_SPI_CLK */
	PAD_CFG_NF_IOSSTATE(FST_SPI_CLK_FB, NATIVE, DEEP, NF1, IGNORE), /* FST_SPI_CLK_FB */
	PAD_CFG_NF_IOSSTATE(GPIO_106, NATIVE, DEEP, NF3, IGNORE),	/* FST_SPI_CS2_N */

	/* SIO_SPI_0 - Used for FP */
	PAD_CFG_NF(GPIO_104, NATIVE, DEEP, NF1),			/* SIO_SPI_0_CLK */
	PAD_CFG_NF(GPIO_105, NATIVE, DEEP, NF1),			/* SIO_SPI_0_FS0 */
	PAD_CFG_NF(GPIO_109, NATIVE, DEEP, NF1),			/* SIO_SPI_0_RXD */
	PAD_CFG_NF(GPIO_110, NATIVE, DEEP, NF1),			/* SIO_SPI_0_TXD */

	/* SIO_SPI_1 -- largely unused */
	PAD_CFG_GPI(GPIO_111, UP_20K, DEEP),	 /* SIO_SPI_1_CLK */
	PAD_CFG_GPI(GPIO_112, UP_20K, DEEP),	 /* SIO_SPI_1_FS0 */
	PAD_CFG_GPI(GPIO_113, UP_20K, DEEP),	 /* SIO_SPI_1_FS1 */
	/* Headset interrupt */
	PAD_CFG_GPI_APIC_LOW(GPIO_116, NONE, DEEP), /* SIO_SPI_1_RXD */
	PAD_CFG_GPI(GPIO_117, UP_20K, DEEP),	 /* SIO_SPI_1_TXD */

	/* SIO_SPI_2 -- unused */
	PAD_CFG_GPI(GPIO_118, UP_20K, DEEP),	 /* SIO_SPI_2_CLK */
	PAD_CFG_GPI(GPIO_119, UP_20K, DEEP),	 /* SIO_SPI_2_FS0 */
	PAD_CFG_GPI(GPIO_120, UP_20K, DEEP),	 /* SIO_SPI_2_FS1 */
	PAD_CFG_GPI(GPIO_121, UP_20K, DEEP),	 /* SIO_SPI_2_FS2 */
	/* WLAN_PE_RST - default to deasserted. */
	PAD_CFG_GPO(GPIO_122, 0, DEEP),		 /* SIO_SPI_2_RXD */
	PAD_CFG_GPI(GPIO_123, UP_20K, DEEP),	 /* SIO_SPI_2_TXD */

	/* Debug tracing. */
	PAD_CFG_GPI(GPIO_0, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_1, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_2, UP_20K, DEEP),
	PAD_CFG_GPI_SCI_HIGH(GPIO_3, DN_20K, DEEP, LEVEL),	 /* FP_INT */
	PAD_CFG_GPI(GPIO_4, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_5, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_6, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_7, UP_20K, DEEP),
	PAD_CFG_GPI(GPIO_8, UP_20K, DEEP),

	PAD_CFG_GPI_APIC_LOW(GPIO_9, NONE, DEEP), /* dTPM IRQ */
	PAD_CFG_GPI(GPIO_10, DN_20K, DEEP),	 /* Board phase enforcement */
	PAD_CFG_GPI_SCI_LOW(GPIO_11, NONE, DEEP, EDGE_SINGLE), /* EC SCI  */
	PAD_CFG_GPI(GPIO_12, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI_APIC_LOW(GPIO_13, NONE, DEEP), /* PEN_INT_ODL */
	PAD_CFG_GPI_APIC_HIGH(GPIO_14, DN_20K, DEEP), /* FP_INT */
	PAD_CFG_GPI_SCI_LOW(GPIO_15, NONE, DEEP, EDGE_SINGLE),	 /* TRACKPAD_INT_1V8_ODL */
	PAD_CFG_GPI(GPIO_16, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_17, UP_20K, DEEP),	 /* 1 vs 4 DMIC config */
	PAD_CFG_GPI_APIC_LOW(GPIO_18, NONE, DEEP), /* Trackpad IRQ */
	PAD_CFG_GPI(GPIO_19, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI_APIC_LOW(GPIO_20, UP_20K, DEEP), /* NFC IRQ */
	PAD_CFG_GPI_APIC_LOW(GPIO_21, NONE, DEEP), /* Touch IRQ */
	PAD_CFG_GPI_SCI_LOW(GPIO_22, NONE, DEEP, EDGE_SINGLE), /* EC wake */
	PAD_CFG_GPI(GPIO_23, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_24, NONE, DEEP),	 /* PEN_PDCT_ODL */
	PAD_CFG_GPI(GPIO_25, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_26, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI(GPIO_27, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPI_APIC_LOW(GPIO_28, NONE, DEEP), /* TPM IRQ */
	PAD_CFG_GPO(GPIO_29, 1, DEEP),		 /* FP reset */
	PAD_CFG_GPI_APIC_LOW(GPIO_30, NONE, DEEP), /* KB IRQ */
	PAD_CFG_GPO(GPIO_31, 0, DEEP),		 /* NFC FW DL */
	PAD_CFG_NF(GPIO_32, NONE, DEEP, NF5),	 /* SUS_CLK2 */
	PAD_CFG_GPI_APIC_LOW(GPIO_33, NONE, DEEP), /* PMIC IRQ */
	PAD_CFG_GPI(GPIO_34, UP_20K, DEEP),	 /* unused */
	PAD_CFG_GPO(GPIO_35, 0, DEEP),		 /* PEN_RESET - active high */
	PAD_CFG_GPO(GPIO_36, 0, DEEP),		 /* touch reset */
	PAD_CFG_GPI(GPIO_37, UP_20K, DEEP),	 /* unused */

	/* LPSS_UART[0:2] */
	PAD_CFG_GPI(GPIO_38, UP_20K, DEEP),	 /* LPSS_UART0_RXD - MEM_CONFIG2*/
	/* Next 2 are straps. */
	PAD_CFG_GPI(GPIO_39, DN_20K, DEEP),	 /* LPSS_UART0_TXD - unused */
	PAD_CFG_GPI(GPIO_40, DN_20K, DEEP),	 /* LPSS_UART0_RTS - unused */
	PAD_CFG_GPI(GPIO_41, NONE, DEEP),	 /* LPSS_UART0_CTS - EC_IN_RW */
	PAD_CFG_NF(GPIO_42, NATIVE, DEEP, NF1),	 /* LPSS_UART1_RXD */
	PAD_CFG_NF(GPIO_43, NATIVE, DEEP, NF1),	 /* LPSS_UART1_TXD */
	PAD_CFG_GPO(GPIO_44, 1, DEEP),	 /* GPS_RST_ODL */
	PAD_CFG_GPI(GPIO_45, UP_20K, DEEP),	 /* LPSS_UART1_CTS - MEM_CONFIG3 */
	PAD_CFG_NF(GPIO_46, NATIVE, DEEP, NF1),	 /* LPSS_UART2_RXD */
	PAD_CFG_NF(GPIO_47, NATIVE, DEEP, NF1),	 /* LPSS_UART2_TXD */
	PAD_CFG_GPI(GPIO_48, UP_20K, DEEP),	 /* LPSS_UART2_RTS - unused */
	PAD_CFG_GPI_SMI_LOW(GPIO_49, NONE, DEEP, EDGE_SINGLE), /* LPSS_UART2_CTS - EC_SMI_L */

	/* Camera interface -- completely unused. */
	PAD_CFG_GPI(GPIO_62, UP_20K, DEEP),	 /* GP_CAMERASB00 */
	PAD_CFG_GPI(GPIO_63, UP_20K, DEEP),	 /* GP_CAMERASB01 */
	PAD_CFG_GPI(GPIO_64, UP_20K, DEEP),	 /* GP_CAMERASB02 */
	PAD_CFG_GPI(GPIO_65, UP_20K, DEEP),	 /* GP_CAMERASB03 */
	PAD_CFG_GPI(GPIO_66, UP_20K, DEEP),	 /* GP_CAMERASB04 */
	PAD_CFG_GPI(GPIO_67, UP_20K, DEEP),	 /* GP_CAMERASB05 */
	PAD_CFG_GPI(GPIO_68, UP_20K, DEEP),	 /* GP_CAMERASB06 */
	PAD_CFG_GPI(GPIO_69, UP_20K, DEEP),	 /* GP_CAMERASB07 */
	PAD_CFG_GPI(GPIO_70, UP_20K, DEEP),	 /* GP_CAMERASB08 */
	PAD_CFG_GPI(GPIO_71, UP_20K, DEEP),	 /* GP_CAMERASB09 */
	PAD_CFG_GPI(GPIO_72, UP_20K, DEEP),	 /* GP_CAMERASB10 */
	PAD_CFG_GPI(GPIO_73, UP_20K, DEEP),	 /* GP_CAMERASB11 */
};

const struct pad_config * __attribute__((weak)) variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

/* GPIOs needed prior to ramstage. */
static const struct pad_config early_gpio_table[] = {
	PAD_CFG_GPI(GPIO_75, UP_20K, DEEP),	 /* I2S1_BCLK -- PCH_WP */
	/* I2C2 - TPM  */
	PAD_CFG_NF(GPIO_128, UP_2K, DEEP, NF1), /* LPSS_I2C2_SDA */
	PAD_CFG_NF(GPIO_129, UP_2K, DEEP, NF1), /* LPSS_I2C2_SCL */
	PAD_CFG_GPI_APIC_LOW(GPIO_28, NONE, DEEP), /* TPM IRQ */
	/* WLAN_PE_RST - default to deasserted just in case FSP misbehaves. */
	PAD_CFG_GPO(GPIO_122, 0, DEEP),		 /* SIO_SPI_2_RXD */
};

const struct pad_config * __attribute__((weak))
variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

/* GPIO settings before entering sleep. */
static const struct pad_config sleep_gpio_table[] = {
	PAD_CFG_GPO(GPIO_150, 0, DEEP),		/* NFC_RESET_ODL */
	PAD_CFG_GPI_APIC_LOW(GPIO_20, NONE, DEEP),	/* NFC_INT_L */
};

const struct pad_config * __attribute__((weak))
variant_sleep_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(sleep_gpio_table);
	return sleep_gpio_table;
}

static const struct cros_gpio cros_gpios[] = {
	CROS_GPIO_REC_AL(CROS_GPIO_VIRTUAL, GPIO_COMM_NW_NAME),
	CROS_GPIO_WP_AH(PAD_NW(GPIO_PCH_WP), GPIO_COMM_NW_NAME),
	CROS_GPIO_PE_AH(PAD_N(GPIO_SHIP_MODE), GPIO_COMM_N_NAME),
};

const struct cros_gpio * __attribute__((weak)) variant_cros_gpios(size_t *num)
{
	*num = ARRAY_SIZE(cros_gpios);
	return cros_gpios;
}