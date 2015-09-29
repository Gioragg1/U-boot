/*
 * Copyright (c) 2009 Wind River Systems, Inc.
 * Tom Rix <Tom.Rix at windriver.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Derived from code on omapzoom, git://git.omapzoom.com/repo/u-boot.git
 *
 * Copyright (C) 2007-2009 Texas Instruments, Inc.
 */

#ifndef TWL4030_H
#define TWL4030_H

#include <common.h>
#include <i2c.h>

/* I2C chip addresses */

/* USB */
#define TWL4030_CHIP_USB				0x48
/* AUD */
#define TWL4030_CHIP_AUDIO_VOICE			0x49
#define TWL4030_CHIP_GPIO				0x49
#define TWL4030_CHIP_INTBR				0x49
#define TWL4030_CHIP_PIH				0x49
#define TWL4030_CHIP_TEST				0x49
/* AUX */
#define TWL4030_CHIP_KEYPAD				0x4a
#define TWL4030_CHIP_MADC				0x4a
#define TWL4030_CHIP_INTERRUPTS				0x4a
#define TWL4030_CHIP_LED				0x4a
#define TWL4030_CHIP_MAIN_CHARGE			0x4a
#define TWL4030_CHIP_PRECHARGE				0x4a
#define TWL4030_CHIP_PWM0				0x4a
#define TWL4030_CHIP_PWM1				0x4a
#define TWL4030_CHIP_PWMA				0x4a
#define TWL4030_CHIP_PWMB				0x4a
/* POWER */
#define TWL4030_CHIP_BACKUP				0x4b
#define TWL4030_CHIP_INT				0x4b
#define TWL4030_CHIP_PM_MASTER				0x4b
#define TWL4030_CHIP_PM_RECEIVER			0x4b
#define TWL4030_CHIP_RTC				0x4b
#define TWL4030_CHIP_SECURED_REG			0x4b

/* Register base addresses */

/* USB */
#define TWL4030_BASEADD_USB				0x0000
/* AUD */
#define TWL4030_BASEADD_AUDIO_VOICE			0x0000
#define TWL4030_BASEADD_GPIO				0x0098
#define TWL4030_BASEADD_INTBR				0x0085
#define TWL4030_BASEADD_PIH				0x0080
#define TWL4030_BASEADD_TEST				0x004C
/* AUX */
#define TWL4030_BASEADD_INTERRUPTS			0x00B9
#define TWL4030_BASEADD_LED				0x00EE
#define TWL4030_BASEADD_MADC				0x0000
#define TWL4030_BASEADD_MAIN_CHARGE			0x0074
#define TWL4030_BASEADD_PRECHARGE			0x00AA
#define TWL4030_BASEADD_PWM0				0x00F8
#define TWL4030_BASEADD_PWM1				0x00FB
#define TWL4030_BASEADD_PWMA				0x00EF
#define TWL4030_BASEADD_PWMB				0x00F1
#define TWL4030_BASEADD_KEYPAD				0x00D2
/* POWER */
#define TWL4030_BASEADD_BACKUP				0x0014
#define TWL4030_BASEADD_INT				0x002E
#define TWL4030_BASEADD_PM_MASTER			0x0036
#define TWL4030_BASEADD_PM_RECIEVER			0x005B
#define TWL4030_BASEADD_RTC				0x001C
#define TWL4030_BASEADD_SECURED_REG			0x0000

/*
 * Power Management Master
 */
#define TWL4030_PM_MASTER_CFG_P1_TRANSITION		0x36
#define TWL4030_PM_MASTER_CFG_P2_TRANSITION		0x37
#define TWL4030_PM_MASTER_CFG_P3_TRANSITION		0x38
#define TWL4030_PM_MASTER_CFG_P123_TRANSITION		0x39
#define TWL4030_PM_MASTER_STS_BOOT			0x3A
#define TWL4030_PM_MASTER_CFG_BOOT			0x3B
#define TWL4030_PM_MASTER_SHUNDAN			0x3C
#define TWL4030_PM_MASTER_BOOT_BCI			0x3D
#define TWL4030_PM_MASTER_CFG_PWRANA1			0x3E
#define TWL4030_PM_MASTER_CFG_PWRANA2			0x3F
#define TWL4030_PM_MASTER_BGAP_TRIM			0x40
#define TWL4030_PM_MASTER_BACKUP_MISC_STS		0x41
#define TWL4030_PM_MASTER_BACKUP_MISC_CFG		0x42
#define TWL4030_PM_MASTER_BACKUP_MISC_TST		0x43
#define TWL4030_PM_MASTER_PROTECT_KEY			0x44
#define TWL4030_PM_MASTER_STS_HW_CONDITIONS		0x45
#define TWL4030_PM_MASTER_P1_SW_EVENTS			0x46
#define TWL4030_PM_MASTER_P2_SW_EVENTS			0x47
#define TWL4030_PM_MASTER_P3_SW_EVENTS			0x48
#define TWL4030_PM_MASTER_STS_P123_STATE		0x49
#define TWL4030_PM_MASTER_PB_CFG			0x4A
#define TWL4030_PM_MASTER_PB_WORD_MSB			0x4B
#define TWL4030_PM_MASTER_PB_WORD_LSB			0x4C
#define TWL4030_PM_MASTER_SEQ_ADD_W2P			0x52
#define TWL4030_PM_MASTER_SEQ_ADD_P2A			0x53
#define TWL4030_PM_MASTER_SEQ_ADD_A2W			0x54
#define TWL4030_PM_MASTER_SEQ_ADD_A2S			0x55
#define TWL4030_PM_MASTER_SEQ_ADD_S2A12			0x56
#define TWL4030_PM_MASTER_SEQ_ADD_S2A3			0x57
#define TWL4030_PM_MASTER_SEQ_ADD_WARM			0x58
#define TWL4030_PM_MASTER_MEMORY_ADDRESS		0x59
#define TWL4030_PM_MASTER_MEMORY_DATA			0x5A
#define TWL4030_PM_MASTER_SC_CONFIG			0x5B
#define TWL4030_PM_MASTER_SC_DETECT1			0x5C
#define TWL4030_PM_MASTER_SC_DETECT2			0x5D
#define TWL4030_PM_MASTER_WATCHDOG_CFG			0x5E
#define TWL4030_PM_MASTER_IT_CHECK_CFG			0x5F
#define TWL4030_PM_MASTER_VIBRATOR_CFG			0x60
#define TWL4030_PM_MASTER_DCDC_GLOBAL_CFG		0x61
#define TWL4030_PM_MASTER_VDD1_TRIM1			0x62
#define TWL4030_PM_MASTER_VDD1_TRIM2			0x63
#define TWL4030_PM_MASTER_VDD2_TRIM1			0x64
#define TWL4030_PM_MASTER_VDD2_TRIM2			0x65
#define TWL4030_PM_MASTER_VIO_TRIM1			0x66
#define TWL4030_PM_MASTER_VIO_TRIM2			0x67
#define TWL4030_PM_MASTER_MISC_CFG			0x68
#define TWL4030_PM_MASTER_LS_TST_A			0x69
#define TWL4030_PM_MASTER_LS_TST_B			0x6A
#define TWL4030_PM_MASTER_LS_TST_C			0x6B
#define TWL4030_PM_MASTER_LS_TST_D			0x6C
#define TWL4030_PM_MASTER_BB_CFG			0x6D
#define TWL4030_PM_MASTER_MISC_TST			0x6E
#define TWL4030_PM_MASTER_TRIM1				0x6F
/* P[1-3]_SW_EVENTS */
#define TWL4030_PM_MASTER_SW_EVENTS_STOPON_PWRON	(1 << 6)
#define TWL4030_PM_MASTER_SW_EVENTS_STOPON_SYSEN	(1 << 5)
#define TWL4030_PM_MASTER_SW_EVENTS_ENABLE_WARMRESET	(1 << 4)
#define TWL4030_PM_MASTER_SW_EVENTS_LVL_WAKEUP		(1 << 3)
#define TWL4030_PM_MASTER_SW_EVENTS_DEVACT		(1 << 2)
#define TWL4030_PM_MASTER_SW_EVENTS_DEVSLP		(1 << 1)
#define TWL4030_PM_MASTER_SW_EVENTS_DEVOFF		(1 << 0)

/* Power Managment Receiver */
#define TWL4030_PM_RECEIVER_SC_CONFIG			0x5B
#define TWL4030_PM_RECEIVER_SC_DETECT1			0x5C
#define TWL4030_PM_RECEIVER_SC_DETECT2			0x5D
#define TWL4030_PM_RECEIVER_WATCHDOG_CFG		0x5E
#define TWL4030_PM_RECEIVER_IT_CHECK_CFG		0x5F
#define TWL4030_PM_RECEIVER_VIBRATOR_CFG		0x5F
#define TWL4030_PM_RECEIVER_DC_TO_DC_CFG		0x61
#define TWL4030_PM_RECEIVER_VDD1_TRIM1			0x62
#define TWL4030_PM_RECEIVER_VDD1_TRIM2			0x63
#define TWL4030_PM_RECEIVER_VDD2_TRIM1			0x64
#define TWL4030_PM_RECEIVER_VDD2_TRIM2			0x65
#define TWL4030_PM_RECEIVER_VIO_TRIM1			0x66
#define TWL4030_PM_RECEIVER_VIO_TRIM2			0x67
#define TWL4030_PM_RECEIVER_MISC_CFG			0x68
#define TWL4030_PM_RECEIVER_LS_TST_A			0x69
#define TWL4030_PM_RECEIVER_LS_TST_B			0x6A
#define TWL4030_PM_RECEIVER_LS_TST_C			0x6B
#define TWL4030_PM_RECEIVER_LS_TST_D			0x6C
#define TWL4030_PM_RECEIVER_BB_CFG			0x6D
#define TWL4030_PM_RECEIVER_MISC_TST			0x6E
#define TWL4030_PM_RECEIVER_TRIM1			0x6F
#define TWL4030_PM_RECEIVER_TRIM2			0x70
#define TWL4030_PM_RECEIVER_DC_DC_TIMEOUT		0x71
#define TWL4030_PM_RECEIVER_VAUX1_DEV_GRP		0x72
#define TWL4030_PM_RECEIVER_VAUX1_TYPE			0x73
#define TWL4030_PM_RECEIVER_VAUX1_REMAP			0x74
#define TWL4030_PM_RECEIVER_VAUX1_DEDICATED		0x75
#define TWL4030_PM_RECEIVER_VAUX2_DEV_GRP		0x76
#define TWL4030_PM_RECEIVER_VAUX2_TYPE			0x77
#define TWL4030_PM_RECEIVER_VAUX2_REMAP			0x78
#define TWL4030_PM_RECEIVER_VAUX2_DEDICATED		0x79
#define TWL4030_PM_RECEIVER_VAUX3_DEV_GRP		0x7A
#define TWL4030_PM_RECEIVER_VAUX3_TYPE			0x7B
#define TWL4030_PM_RECEIVER_VAUX3_REMAP			0x7C
#define TWL4030_PM_RECEIVER_VAUX3_DEDICATED		0x7D
#define TWL4030_PM_RECEIVER_VAUX4_DEV_GRP		0x7E
#define TWL4030_PM_RECEIVER_VAUX4_TYPE			0x7F
#define TWL4030_PM_RECEIVER_VAUX4_REMAP			0x80
#define TWL4030_PM_RECEIVER_VAUX4_DEDICATED		0x81
#define TWL4030_PM_RECEIVER_VMMC1_DEV_GRP		0x82
#define TWL4030_PM_RECEIVER_VMMC1_TYPE			0x83
#define TWL4030_PM_RECEIVER_VMMC1_REMAP			0x84
#define TWL4030_PM_RECEIVER_VMMC1_DEDICATED		0x85
#define TWL4030_PM_RECEIVER_VMMC2_DEV_GRP		0x86
#define TWL4030_PM_RECEIVER_VMMC2_TYPE			0x87
#define TWL4030_PM_RECEIVER_VMMC2_REMAP			0x88
#define TWL4030_PM_RECEIVER_VMMC2_DEDICATED		0x89
#define TWL4030_PM_RECEIVER_VPLL1_DEV_GRP		0x8A
#define TWL4030_PM_RECEIVER_VPLL1_TYPE			0x8B
#define TWL4030_PM_RECEIVER_VPLL1_REMAP			0x8C
#define TWL4030_PM_RECEIVER_VPLL1_DEDICATED		0x8D
#define TWL4030_PM_RECEIVER_VPLL2_DEV_GRP		0x8E
#define TWL4030_PM_RECEIVER_VPLL2_TYPE			0x8F
#define TWL4030_PM_RECEIVER_VPLL2_REMAP			0x90
#define TWL4030_PM_RECEIVER_VPLL2_DEDICATED		0x91
#define TWL4030_PM_RECEIVER_VSIM_DEV_GRP		0x92
#define TWL4030_PM_RECEIVER_VSIM_TYPE			0x93
#define TWL4030_PM_RECEIVER_VSIM_REMAP			0x94
#define TWL4030_PM_RECEIVER_VSIM_DEDICATED		0x95
#define TWL4030_PM_RECEIVER_VDAC_DEV_GRP		0x96
#define TWL4030_PM_RECEIVER_VDAC_TYPE			0x97
#define TWL4030_PM_RECEIVER_VDAC_REMAP			0x98
#define TWL4030_PM_RECEIVER_VDAC_DEDICATED		0x99
#define TWL4030_PM_RECEIVER_VINTANA1_DEV_GRP		0x9A
#define TWL4030_PM_RECEIVER_VINTANA1_TYP		0x9B
#define TWL4030_PM_RECEIVER_VINTANA1_REMAP		0x9C
#define TWL4030_PM_RECEIVER_VINTANA1_DEDICATED		0x9D
#define TWL4030_PM_RECEIVER_VINTANA2_DEV_GRP		0x9E
#define TWL4030_PM_RECEIVER_VINTANA2_TYPE		0x9F
#define TWL4030_PM_RECEIVER_VINTANA2_REMAP		0xA0
#define TWL4030_PM_RECEIVER_VINTANA2_DEDICATED		0xA1
#define TWL4030_PM_RECEIVER_VINTDIG_DEV_GRP		0xA2
#define TWL4030_PM_RECEIVER_VINTDIG_TYPE		0xA3
#define TWL4030_PM_RECEIVER_VINTDIG_REMAP		0xA4
#define TWL4030_PM_RECEIVER_VINTDIG_DEDICATED		0xA5
#define TWL4030_PM_RECEIVER_VIO_DEV_GRP			0xA6
#define TWL4030_PM_RECEIVER_VIO_TYPE			0xA7
#define TWL4030_PM_RECEIVER_VIO_REMAP			0xA8
#define TWL4030_PM_RECEIVER_VIO_CFG			0xA9
#define TWL4030_PM_RECEIVER_VIO_MISC_CFG		0xAA
#define TWL4030_PM_RECEIVER_VIO_TEST1			0xAB
#define TWL4030_PM_RECEIVER_VIO_TEST2			0xAC
#define TWL4030_PM_RECEIVER_VIO_OSC			0xAD
#define TWL4030_PM_RECEIVER_VIO_RESERVED		0xAE
#define TWL4030_PM_RECEIVER_VIO_VSEL			0xAF
#define TWL4030_PM_RECEIVER_VDD1_DEV_GRP		0xB0
#define TWL4030_PM_RECEIVER_VDD1_TYPE			0xB1
#define TWL4030_PM_RECEIVER_VDD1_REMAP			0xB2
#define TWL4030_PM_RECEIVER_VDD1_CFG			0xB3
#define TWL4030_PM_RECEIVER_VDD1_MISC_CFG		0xB4
#define TWL4030_PM_RECEIVER_VDD1_TEST1			0xB5
#define TWL4030_PM_RECEIVER_VDD1_TEST2			0xB6
#define TWL4030_PM_RECEIVER_VDD1_OSC			0xB7
#define TWL4030_PM_RECEIVER_VDD1_RESERVED		0xB8
#define TWL4030_PM_RECEIVER_VDD1_VSEL			0xB9
#define TWL4030_PM_RECEIVER_VDD1_VMODE_CFG		0xBA
#define TWL4030_PM_RECEIVER_VDD1_VFLOOR			0xBB
#define TWL4030_PM_RECEIVER_VDD1_VROOF			0xBC
#define TWL4030_PM_RECEIVER_VDD1_STEP			0xBD
#define TWL4030_PM_RECEIVER_VDD2_DEV_GRP		0xBE
#define TWL4030_PM_RECEIVER_VDD2_TYPE			0xBF
#define TWL4030_PM_RECEIVER_VDD2_REMAP			0xC0
#define TWL4030_PM_RECEIVER_VDD2_CFG			0xC1
#define TWL4030_PM_RECEIVER_VDD2_MISC_CFG		0xC2
#define TWL4030_PM_RECEIVER_VDD2_TEST1			0xC3
#define TWL4030_PM_RECEIVER_VDD2_TEST2			0xC4
#define TWL4030_PM_RECEIVER_VDD2_OSC			0xC5
#define TWL4030_PM_RECEIVER_VDD2_RESERVED		0xC6
#define TWL4030_PM_RECEIVER_VDD2_VSEL			0xC7
#define TWL4030_PM_RECEIVER_VDD2_VMODE_CFG		0xC8
#define TWL4030_PM_RECEIVER_VDD2_VFLOOR			0xC9
#define TWL4030_PM_RECEIVER_VDD2_VROOF			0xCA
#define TWL4030_PM_RECEIVER_VDD2_STEP			0xCB
#define TWL4030_PM_RECEIVER_VUSB1V5_DEV_GRP		0xCC
#define TWL4030_PM_RECEIVER_VUSB1V5_TYPE		0xCD
#define TWL4030_PM_RECEIVER_VUSB1V5_REMAP		0xCE
#define TWL4030_PM_RECEIVER_VUSB1V8_DEV_GRP		0xCF
#define TWL4030_PM_RECEIVER_VUSB1V8_TYPE		0xD0
#define TWL4030_PM_RECEIVER_VUSB1V8_REMAP		0xD1
#define TWL4030_PM_RECEIVER_VUSB3V1_DEV_GRP		0xD2
#define TWL4030_PM_RECEIVER_VUSB3V1_TYPE		0xD3
#define TWL4030_PM_RECEIVER_VUSB3V1_REMAP		0xD4
#define TWL4030_PM_RECEIVER_VUSBCP_DEV_GRP		0xD5
#define TWL4030_PM_RECEIVER_VUSBCP_TYPE			0xD6
#define TWL4030_PM_RECEIVER_VUSBCP_REMAP		0xD7
#define TWL4030_PM_RECEIVER_VUSB_DEDICATED1		0xD8
#define TWL4030_PM_RECEIVER_VUSB_DEDICATED2		0xD9
#define TWL4030_PM_RECEIVER_REGEN_DEV_GRP		0xDA
#define TWL4030_PM_RECEIVER_REGEN_TYPE			0xDB
#define TWL4030_PM_RECEIVER_REGEN_REMAP			0xDC
#define TWL4030_PM_RECEIVER_NRESPWRON_DEV_GRP		0xDD
#define TWL4030_PM_RECEIVER_NRESPWRON_TYPE		0xDE
#define TWL4030_PM_RECEIVER_NRESPWRON_REMAP		0xDF
#define TWL4030_PM_RECEIVER_CLKEN_DEV_GRP		0xE0
#define TWL4030_PM_RECEIVER_CLKEN_TYPE			0xE1
#define TWL4030_PM_RECEIVER_CLKEN_REMAP			0xE2
#define TWL4030_PM_RECEIVER_SYSEN_DEV_GRP		0xE3
#define TWL4030_PM_RECEIVER_SYSEN_TYPE			0xE4
#define TWL4030_PM_RECEIVER_SYSEN_REMAP			0xE5
#define TWL4030_PM_RECEIVER_HFCLKOUT_DEV_GRP		0xE6
#define TWL4030_PM_RECEIVER_HFCLKOUT_TYPE		0xE7
#define TWL4030_PM_RECEIVER_HFCLKOUT_REMAP		0xE8
#define TWL4030_PM_RECEIVER_32KCLKOUT_DEV_GRP		0xE9
#define TWL4030_PM_RECEIVER_32KCLKOUT_TYPE		0xEA
#define TWL4030_PM_RECEIVER_32KCLKOUT_REMAP		0xEB
#define TWL4030_PM_RECEIVER_TRITON_RESET_DEV_GRP	0xEC
#define TWL4030_PM_RECEIVER_TRITON_RESET_TYPE		0xED
#define TWL4030_PM_RECEIVER_TRITON_RESET_REMAP		0xEE
#define TWL4030_PM_RECEIVER_MAINREF_DEV_GRP		0xEF
#define TWL4030_PM_RECEIVER_MAINREF_TYPE		0xF0
#define TWL4030_PM_RECEIVER_MAINREF_REMAP		0xF1

/* Voltage Selection in PM Receiver Module */
#define TWL4030_PM_RECEIVER_VAUX2_VSEL_18		0x05
#define TWL4030_PM_RECEIVER_VAUX3_VSEL_28		0x03
#define TWL4030_PM_RECEIVER_VPLL2_VSEL_18		0x05
#define TWL4030_PM_RECEIVER_VDAC_VSEL_18		0x03
#define TWL4030_PM_RECEIVER_VMMC1_VSEL_30		0x02
#define TWL4030_PM_RECEIVER_VMMC1_VSEL_32		0x03

/* Device Selection in PM Receiver Module */
#define TWL4030_PM_RECEIVER_DEV_GRP_P1			0x20
#define TWL4030_PM_RECEIVER_DEV_GRP_ALL			0xE0

/* LED */
#define TWL4030_LED_LEDEN				0xEE
#define TWL4030_LED_LEDEN_LEDAON			(1 << 0)
#define TWL4030_LED_LEDEN_LEDBON			(1 << 1)
#define TWL4030_LED_LEDEN_LEDAPWM			(1 << 4)
#define TWL4030_LED_LEDEN_LEDBPWM			(1 << 5)

/* Keypad */
#define TWL4030_KEYPAD_KEYP_CTRL_REG			0xD2
#define TWL4030_KEYPAD_KEY_DEB_REG			0xD3
#define TWL4030_KEYPAD_LONG_KEY_REG1			0xD4
#define TWL4030_KEYPAD_LK_PTV_REG			0xD5
#define TWL4030_KEYPAD_TIME_OUT_REG1			0xD6
#define TWL4030_KEYPAD_TIME_OUT_REG2			0xD7
#define TWL4030_KEYPAD_KBC_REG				0xD8
#define TWL4030_KEYPAD_KBR_REG				0xD9
#define TWL4030_KEYPAD_KEYP_SMS				0xDA
#define TWL4030_KEYPAD_FULL_CODE_7_0			0xDB
#define TWL4030_KEYPAD_FULL_CODE_15_8			0xDC
#define TWL4030_KEYPAD_FULL_CODE_23_16			0xDD
#define TWL4030_KEYPAD_FULL_CODE_31_24			0xDE
#define TWL4030_KEYPAD_FULL_CODE_39_32			0xDF
#define TWL4030_KEYPAD_FULL_CODE_47_40			0xE0
#define TWL4030_KEYPAD_FULL_CODE_55_48			0xE1
#define TWL4030_KEYPAD_FULL_CODE_63_56			0xE2
#define TWL4030_KEYPAD_KEYP_ISR1			0xE3
#define TWL4030_KEYPAD_KEYP_IMR1			0xE4
#define TWL4030_KEYPAD_KEYP_ISR2			0xE5
#define TWL4030_KEYPAD_KEYP_IMR2			0xE6
#define TWL4030_KEYPAD_KEYP_SIR				0xE7
#define TWL4030_KEYPAD_KEYP_EDR				0xE8
#define TWL4030_KEYPAD_KEYP_SIH_CTRL			0xE9

#define TWL4030_KEYPAD_CTRL_KBD_ON			(1 << 6)
#define TWL4030_KEYPAD_CTRL_RP_EN			(1 << 5)
#define TWL4030_KEYPAD_CTRL_TOLE_EN			(1 << 4)
#define TWL4030_KEYPAD_CTRL_TOE_EN			(1 << 3)
#define TWL4030_KEYPAD_CTRL_LK_EN			(1 << 2)
#define TWL4030_KEYPAD_CTRL_SOFTMODEN			(1 << 1)
#define TWL4030_KEYPAD_CTRL_SOFT_NRST			(1 << 0)

/* USB */
#define TWL4030_USB_VENDOR_ID_LO			0x00
#define TWL4030_USB_VENDOR_ID_HI			0x01
#define TWL4030_USB_PRODUCT_ID_LO			0x02
#define TWL4030_USB_PRODUCT_ID_HI			0x03
#define TWL4030_USB_FUNC_CTRL				0x04
#define TWL4030_USB_FUNC_CTRL_SET			0x05
#define TWL4030_USB_FUNC_CTRL_CLR			0x06
#define TWL4030_USB_IFC_CTRL				0x07
#define TWL4030_USB_IFC_CTRL_SET			0x08
#define TWL4030_USB_IFC_CTRL_CLR			0x09
#define TWL4030_USB_OTG_CTRL				0x0A
#define TWL4030_USB_OTG_CTRL_SET			0x0B
#define TWL4030_USB_OTG_CTRL_CLR			0x0C
#define TWL4030_USB_USB_INT_EN_RISE			0x0D
#define TWL4030_USB_USB_INT_EN_RISE_SET			0x0E
#define TWL4030_USB_USB_INT_EN_RISE_CLR			0x0F
#define TWL4030_USB_USB_INT_EN_FALL			0x10
#define TWL4030_USB_USB_INT_EN_FALL_SET			0x11
#define TWL4030_USB_USB_INT_EN_FALL_CLR			0x12
#define TWL4030_USB_USB_INT_STS				0x13
#define TWL4030_USB_USB_INT_LATCH			0x14
#define TWL4030_USB_DEBUG				0x15
#define TWL4030_USB_SCRATCH_REG				0x16
#define TWL4030_USB_SCRATCH_REG_SET			0x17
#define TWL4030_USB_SCRATCH_REG_CLR			0x18
#define TWL4030_USB_CARKIT_CTRL				0x19
#define TWL4030_USB_CARKIT_CTRL_SET			0x1A
#define TWL4030_USB_CARKIT_CTRL_CLR			0x1B
#define TWL4030_USB_CARKIT_INT_DELAY			0x1C
#define TWL4030_USB_CARKIT_INT_EN			0x1D
#define TWL4030_USB_CARKIT_INT_EN_SET			0x1E
#define TWL4030_USB_CARKIT_INT_EN_CLR			0x1F
#define TWL4030_USB_CARKIT_INT_STS			0x20
#define TWL4030_USB_CARKIT_INT_LATCH			0x21
#define TWL4030_USB_CARKIT_PLS_CTRL			0x22
#define TWL4030_USB_CARKIT_PLS_CTRL_SET			0x23
#define TWL4030_USB_CARKIT_PLS_CTRL_CLR			0x24
#define TWL4030_USB_TRANS_POS_WIDTH			0x25
#define TWL4030_USB_TRANS_NEG_WIDTH			0x26
#define TWL4030_USB_RCV_PLTY_RECOVERY			0x27
#define TWL4030_USB_MCPC_CTRL				0x30
#define TWL4030_USB_MCPC_CTRL_SET			0x31
#define TWL4030_USB_MCPC_CTRL_CLR			0x32
#define TWL4030_USB_MCPC_IO_CTRL			0x33
#define TWL4030_USB_MCPC_IO_CTRL_SET			0x34
#define TWL4030_USB_MCPC_IO_CTRL_CLR			0x35
#define TWL4030_USB_MCPC_CTRL2				0x36
#define TWL4030_USB_MCPC_CTRL2_SET			0x37
#define TWL4030_USB_MCPC_CTRL2_CLR			0x38
#define TWL4030_USB_OTHER_FUNC_CTRL			0x80
#define TWL4030_USB_OTHER_FUNC_CTRL_SET			0x81
#define TWL4030_USB_OTHER_FUNC_CTRL_CLR			0x82
#define TWL4030_USB_OTHER_IFC_CTRL			0x83
#define TWL4030_USB_OTHER_IFC_CTRL_SET			0x84
#define TWL4030_USB_OTHER_IFC_CTRL_CLR			0x85
#define TWL4030_USB_OTHER_INT_EN_RISE_SET		0x87
#define TWL4030_USB_OTHER_INT_EN_RISE_CLR		0x88
#define TWL4030_USB_OTHER_INT_EN_FALL			0x89
#define TWL4030_USB_OTHER_INT_EN_FALL_SET		0x8A
#define TWL4030_USB_OTHER_INT_EN_FALL_CLR		0x8B
#define TWL4030_USB_OTHER_INT_STS			0x8C
#define TWL4030_USB_OTHER_INT_LATCH			0x8D
#define TWL4030_USB_ID_STATUS				0x96
#define TWL4030_USB_CARKIT_SM_1_INT_EN			0x97
#define TWL4030_USB_CARKIT_SM_1_INT_EN_SET		0x98
#define TWL4030_USB_CARKIT_SM_1_INT_EN_CLR		0x99
#define TWL4030_USB_CARKIT_SM_1_INT_STS			0x9A
#define TWL4030_USB_CARKIT_SM_1_INT_LATCH		0x9B
#define TWL4030_USB_CARKIT_SM_2_INT_EN			0x9C
#define TWL4030_USB_CARKIT_SM_2_INT_EN_SET		0x9D
#define TWL4030_USB_CARKIT_SM_2_INT_EN_CLR		0x9E
#define TWL4030_USB_CARKIT_SM_2_INT_STS			0x9F
#define TWL4030_USB_CARKIT_SM_2_INT_LATCH		0xA0
#define TWL4030_USB_CARKIT_SM_CTRL			0xA1
#define TWL4030_USB_CARKIT_SM_CTRL_SET			0xA2
#define TWL4030_USB_CARKIT_SM_CTRL_CLR			0xA3
#define TWL4030_USB_CARKIT_SM_CMD			0xA4
#define TWL4030_USB_CARKIT_SM_CMD_SET			0xA5
#define TWL4030_USB_CARKIT_SM_CMD_CLR			0xA6
#define TWL4030_USB_CARKIT_SM_CMD_STS			0xA7
#define TWL4030_USB_CARKIT_SM_STATUS			0xA8
#define TWL4030_USB_CARKIT_SM_ERR_STATUS		0xAA
#define TWL4030_USB_CARKIT_SM_CTRL_STATE		0xAB
#define TWL4030_USB_POWER_CTRL				0xAC
#define TWL4030_USB_POWER_CTRL_SET			0xAD
#define TWL4030_USB_POWER_CTRL_CLR			0xAE
#define TWL4030_USB_OTHER_IFC_CTRL2			0xAF
#define TWL4030_USB_OTHER_IFC_CTRL2_SET			0xB0
#define TWL4030_USB_OTHER_IFC_CTRL2_CLR			0xB1
#define TWL4030_USB_REG_CTRL_EN				0xB2
#define TWL4030_USB_REG_CTRL_EN_SET			0xB3
#define TWL4030_USB_REG_CTRL_EN_CLR			0xB4
#define TWL4030_USB_REG_CTRL_ERROR			0xB5
#define TWL4030_USB_OTHER_FUNC_CTRL2			0xB8
#define TWL4030_USB_OTHER_FUNC_CTRL2_SET		0xB9
#define TWL4030_USB_OTHER_FUNC_CTRL2_CLR		0xBA
#define TWL4030_USB_CARKIT_ANA_CTRL			0xBB
#define TWL4030_USB_CARKIT_ANA_CTRL_SET			0xBC
#define TWL4030_USB_CARKIT_ANA_CTRL_CLR			0xBD
#define TWL4030_USB_VBUS_DEBOUNCE			0xC0
#define TWL4030_USB_ID_DEBOUNCE				0xC1
#define TWL4030_USB_TPH_DP_CON_MIN			0xC2
#define TWL4030_USB_TPH_DP_CON_MAX			0xC3
#define TWL4030_USB_TCR_DP_CON_MIN			0xC4
#define TWL4030_USB_TCR_DP_CON_MAX			0xC5
#define TWL4030_USB_TPH_DP_PD_SHORT			0xC6
#define TWL4030_USB_TPH_CMD_DLY				0xC7
#define TWL4030_USB_TPH_DET_RST				0xC8
#define TWL4030_USB_TPH_AUD_BIAS			0xC9
#define TWL4030_USB_TCR_UART_DET_MIN			0xCA
#define TWL4030_USB_TCR_UART_DET_MAX			0xCB
#define TWL4030_USB_TPH_ID_INT_PW			0xCD
#define TWL4030_USB_TACC_ID_INT_WAIT			0xCE
#define TWL4030_USB_TACC_ID_INT_PW			0xCF
#define TWL4030_USB_TPH_CMD_WAIT			0xD0
#define TWL4030_USB_TPH_ACK_WAIT			0xD1
#define TWL4030_USB_TPH_DP_DISC_DET			0xD2
#define TWL4030_USB_VBAT_TIMER				0xD3
#define TWL4030_USB_CARKIT_4W_DEBUG			0xE0
#define TWL4030_USB_CARKIT_5W_DEBUG			0xE1
#define TWL4030_USB_PHY_PWR_CTRL			0xFD
#define TWL4030_USB_PHY_CLK_CTRL			0xFE
#define TWL4030_USB_PHY_CLK_CTRL_STS			0xFF

/*
 * Convience functions to read and write from TWL4030
 *
 * chip_no is the i2c address, it must be one of the chip addresses
 *   defined at the top of this file with the prefix TWL4030_CHIP_
 *   examples are TWL4030_CHIP_PM_RECEIVER and TWL4030_CHIP_KEYPAD
 *
 * val is the data either written to or read from the twl4030
 *
 * reg is the register to act on, it must be one of the defines
 *   above and with the format TWL4030_<chip suffix>_<register name>
 *   examples are TWL4030_PM_RECEIVER_VMMC1_DEV_GRP and
 *   TWL4030_LED_LEDEN.
 */
static inline int twl4030_i2c_write_u8(u8 chip_no, u8 val, u8 reg)
{
	return i2c_write(chip_no, reg, 1, &val, 1);
}

static inline int twl4030_i2c_read_u8(u8 chip_no, u8 *val, u8 reg)
{
	return i2c_read(chip_no, reg, 1, val, 1);
}

/*
 * Power
 */

/*For setting VDD1  */
void twl4030_power_mpu_init(void);

/* For hardware resetting */
void twl4030_power_reset_init(void);
/* For setting device group and voltage */
void twl4030_pmrecv_vsel_cfg(u8 vsel_reg, u8 vsel_val,
			     u8 dev_grp, u8 dev_grp_sel);
/* For initializing power device */
void twl4030_power_init(void);
/* For initializing mmc power */
void twl4030_power_mmc_init(void);

/*
 * LED
 */
void twl4030_led_init(unsigned char ledon_mask);

/*
 * USB
 */
int twl4030_usb_ulpi_init(void);

#endif /* TWL4030_H */
