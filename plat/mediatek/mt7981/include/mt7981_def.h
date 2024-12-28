/*
 * Copyright (c) 2021, MediaTek Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MT7981_DEF_H
#define MT7981_DEF_H

#include "reg_base.h"

/* Special value used to verify platform parameters from BL2 to BL3-1 */
#define MT_BL31_PLAT_PARAM_VAL		0x0f1e2d3c4b5a6978ULL

/* CPU */
#define PRIMARY_CPU			0

/* MMU */
#define MTK_DEV_BASE			0x00200000
#define MTK_DEV_SIZE			0x1fe00000

/* GICv3 */
#define PLAT_ARM_GICD_BASE		GIC_BASE
#define PLAT_ARM_GICR_BASE		(GIC_BASE + 0x80000)

/* Int pol ctl */
#define NR_INT_POL_CTL			20

/* Watchdog */
#define WDT_BASE			CKSYS_TOPRGU_BASE

/* DDR_RESERVE */
#define MTK_DDR_RESERVE_MODE		(CKSYS_DRM_BASE + 0x0000)
#define MTK_DDR_RESERVE_ENABLE		0x0001
#define MTK_DDR_RESERVE_KEY		0x22000000

/* UART */
#define UART_BASE			UART0_BASE
#define UART_BAUDRATE			115200
#define UART_CLOCK			40000000
#define MTK_GPT_CLOCK_RATE		40000000 / 2
#define ARM_TIMER_CLOCK_RATE		13000000

/* EFUSE */
#define SGMII0_CAL_DATA			0x11F208c4
#define SGMII1_CAL_DATA			0x11F208c8

/* SGMII */
#define SGMII_PHY0_FTCTL		0x10060188
#define SGMII_PHY1_FTCTL		0x10070188

/* TRNG */
#define TRNG_SWRST_SET_REG		(INFRACFG_AO_BASE + 0x150)
#define TRNG_SWRST_CLR_REG		(INFRACFG_AO_BASE + 0x154)
#define RNG_SWRST_B			BIT(13)

/* TOP_CLOCK*/
#define CLK_CFG_0_SET			(CKSYS_CKCTRL_BASE + 0x004)
#define   CLK_NFI1X_SEL_S		(0)
#define   CLK_SPINFI_BCLK_SEL_S		(8)
#define   CLK_SPI_SEL_S			(16)

#define CLK_CFG_0_CLR			(CKSYS_CKCTRL_BASE + 0x008)
#define   CLK_NFI1X_SEL_MASK		GENMASK(2, 0)
#define   CLK_SPINFI_BCLK_SEL_MASK	GENMASK(10, 8)
#define   CLK_SPI_SEL_MASK		GENMASK(18, 16)

#define CLK_CFG_UPDATE			(CKSYS_CKCTRL_BASE + 0x1c0)
#define   NFI1X_CK_UPDATE		(1U << 0)
#define   SPINFI_CK_UPDATE		(1U << 1)
#define   SPI_CK_UPDATE			(1U << 2)

#ifndef __ASSEMBLER__
enum CLK_NFI1X_RATE{
	CLK_NFI1X_40MHz = 0,
	CLK_NFI1X_180MHz,
	CLK_NFI1X_156MHz,
	CLK_NFI1X_133MHz,
	CLK_NFI1X_104MHz,
	CLK_NFI1X_90MHz,
	CLK_NFI1X_78MHz,
	CLK_NFI1X_52MHz
};

enum CLK_SPINFI_RATE {
	CLK_SPINFI_20MHz = 0,
	CLK_SPINFI_40MHz,
	CLK_SPINFI_125MHz,
	CLK_SPINFI_104MHz,
	CLK_SPINFI_90MHz,
	CLK_SPINFI_78MHz,
	CLK_SPINFI_60MHz,
	CLK_SPINFI_52MHz
};

enum CLK_SPIM_RATE {
	CLK_SPIM_40MHz = 0,
	CLK_SPIM_208MHz,
	CLK_SPIM_180MHz,
	CLK_SPIM_156MHz,
	CLK_SPIM_133MHz,
	CLK_SPIM_125MHz,
	CLK_SPIM_104MHz,
	CLK_SPIM_76MHz
};
#endif

/* FIQ platform related define */
#define MT_IRQ_SEC_SGI_0		8
#define MT_IRQ_SEC_SGI_1		9
#define MT_IRQ_SEC_SGI_2		10
#define MT_IRQ_SEC_SGI_3		11
#define MT_IRQ_SEC_SGI_4		12
#define MT_IRQ_SEC_SGI_5		13
#define MT_IRQ_SEC_SGI_6		14
#define MT_IRQ_SEC_SGI_7		15

/* Define maximum page size for NAND devices */
#define PLATFORM_MTD_MAX_PAGE_SIZE	0x1000

#endif /* MT7981_DEF_H */