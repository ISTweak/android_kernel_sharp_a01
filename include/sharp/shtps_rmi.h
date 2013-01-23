/* include/sharp/shtps_rmi.h
 *
 * Copyright (C) 2011 SHARP CORPORATION
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __SHTPS_RMI_H__
#define __SHTPS_RMI_H__

#if (defined( CONFIG_MACH_DECKARD_AS35 ) || defined( FEATURE_SH_MODEL_AS35 ) )
	#define SHTPS_F01_RMI_CTRL_ADR	0x0035
	#define SHTPS_TOUCH_MAX_X		539
	#define SHTPS_TOUCH_MAX_Y		959
	#define SHTPS_LCD_MAX_X			539
	#define SHTPS_LCD_MAX_Y			959
	#define SHTPS_SENSOR_MAX_X		914
	#define SHTPS_SENSOR_MAX_Y		1625
#else
	#define SHTPS_F01_RMI_CTRL_ADR	0x0031
	#define SHTPS_TOUCH_MAX_X		539
	#define SHTPS_TOUCH_MAX_Y		959
	#define SHTPS_LCD_MAX_X			539
	#define SHTPS_LCD_MAX_Y			959
	#define SHTPS_SENSOR_MAX_X		1056
	#define SHTPS_SENSOR_MAX_Y		1863
#endif	/* #if (defined( CONFIG_MACH_DECKARD_AS35 ) || defined( FEATURE_SH_MODEL_AS35 ) ) */

#define SHTPS_FINGER_MAX		5

enum shtps_drag_threshold_mode {
	SHTPS_DRAG_THRESHOLD_1ST,
	SHTPS_DRAG_THRESHOLD_2ND
};

enum shtps_proc_mode {
	SHTPS_IN_IDLE,
	SHTPS_IN_NORMAL,
	SHTPS_IN_BOOTLOADER,
};

enum shtps_diag_mode {
	SHTPS_DIAGMODE_NONE,
	SHTPS_DIAGMODE_TOUCHINFO,
	SHTPS_DIAGMODE_TM,
};

enum shtps_diag_tm_mode {
	SHTPS_TMMODE_NONE,
	SHTPS_TMMODE_FRAMELINE,
	SHTPS_TMMODE_BASELINE,
};

struct shtps_platform_data {
	int (*setup)(struct device *);
	void (*teardown)(struct device *);
	int gpio_rst;
};

struct rmi_pdt {
	u8	queryBaseAddr;
	u8	commandBaseAddr;
	u8	controlBaseAddr;
	u8	dataBaseAddr;
	u8	interruptSrcCount;
	u8	functionNumber;
};

struct shtps_touch_state {
	u8				numOfFingers;
	u8				fingerStatus[SHTPS_FINGER_MAX];
	u8				dragStep[SHTPS_FINGER_MAX][2];
	u8				rezeroRequest;
	unsigned long	drag_timeout[SHTPS_FINGER_MAX][2];
};

#define F01_QUERY_MANUFACTURERID(data)	data[0]
#define F01_QUERY_NONCOMPLIANT(data)	((data[1] >> 1) & 0x01)
#define F01_QUERY_CUSTOMMAP(data)		(data[1] & 0x01)
#define F01_QUERY_PRODUCTINFO0(data)	(data[2] & 0x7F)
#define F01_QUERY_PRODUCTINFO1(data)	(data[3] & 0x7F)
#define F01_QUERY_DATACODEYEAR(data)	(data[4] & 0x1F)
#define F01_QUERY_DATACODEMONTH(data)	(data[5] & 0x0F)
#define F01_QUERY_DATACODEDAY(data)		(data[6] & 0x1F)
#define F01_QUERY_TESTID_HI(data)		(data[7] & 0x7F)
#define F01_QUERY_TESTID_LO(data)		(data[8] & 0x7F)
#define F01_QUERY_SERIALNUM_HI(data)	(data[9] & 0x7F)
#define F01_QUERY_SERIALNUM_LO(data)	(data[10]& 0x7F)
#define F01_QUERY_PRODUCTID(data)		data[11]

struct rmi_f01Query {
	u8	data[21];
};

struct rmi_f01 {
	u8					enable;
	u32					queryBase;
	u32					ctrlBase;
	u32					dataBase;
	u32					commandBase;
	struct rmi_f01Query	query;
};

#define F05_QUERY_NUMOFRCVEL(data)		(data[0] & 0x3F)
#define F05_QUERY_NUMOFTRANSEL(data)	(data[1] & 0x3F)
#define F05_QUERY_HAS16BIT(data)		((data[3] >> 7) & 0x01)
#define F05_QUERY_IMAGEWINDOWSIZE(data)	(data[4])

struct rmi_f05Query {
	u8	data[6];
};

struct rmi_f05 {
	u8					enable;
	u32					queryBase;
	u32					ctrlBase;
	u32					dataBase;
	u32					commandBase;
	struct rmi_f05Query	query;
};

#define F11_QUERY_NUMOFSENSORS(data)	(data[0] & 0x07)
#define F11_QUERY_CONFIGURABLE(data)	((data[1] >> 0x07) & 0x01)
#define F11_QUERY_HASSENSADJUST(data)	((data[1] >> 0x06) & 0x01)
#define F11_QUERY_HASGESTURES(data)		((data[1] >> 0x05) & 0x01)
#define F11_QUERY_HASABS(data)			((data[1] >> 0x04) & 0x01)
#define F11_QUERY_HASREL(data)			((data[1] >> 0x03) & 0x01)
#define F11_QUERY_NUMOFFINGERS(data)	(data[1] & 0x07)
#define F11_QUERY_NUMOFXELEC(data)		(data[2] & 0x1F)
#define F11_QUERY_NUMOFYELEC(data)		(data[3] & 0x1F)
#define F11_QUERY_MAXELEC(data)			(data[4] & 0x1F)
#define F11_QUERY_HASANCHORED(data)		((data[5] >> 0x02) & 0x01)
#define F11_QUERY_ABSDATASIZE(data)		(data[5] & 0x03)
#define F11_QUERY_HASPINCH(data)		((data[6] >> 0x06) & 0x01)
#define F11_QUERY_HASPRESS(data)		((data[6] >> 0x05) & 0x01)
#define F11_QUERY_HASFLICK(data)		((data[6] >> 0x04) & 0x01)
#define F11_QUERY_HASEARLYTAP(data)		((data[6] >> 0x03) & 0x01)
#define F11_QUERY_HASDOUBLETAP(data)	((data[6] >> 0x02) & 0x01)
#define F11_QUERY_HASTAPHOST(data)		((data[6] >> 0x01) & 0x01)
#define F11_QUERY_HASSINGLETAP(data)	(data[6] & 0x01)
#define F11_QUERY_HASISCROLLZONE(data)	((data[7] >> 0x04) & 0x01)
#define F11_QUERY_HASSCROLLZONE(data)	((data[7] >> 0x03) & 0x01)
#define F11_QUERY_HASTOUCHSHAPE(data)	((data[7] >> 0x02) & 0x01)
#define F11_QUERY_HASROTATE(data)		((data[7] >> 0x01) & 0x01)
#define F11_QUERY_HASPALMDET(data)		(data[7] & 0x01)
#define F11_QUERY_HASROTATE(data)		((data[7] >> 0x01) & 0x01)
#define F11_QUERY_HASLOS(data)			((data[8] >> 0x02) & 0x01)
#define F11_QUERY_HASFPROXIMITY(data)	((data[8] >> 0x01) & 0x01)
#define F11_QUERY_HASPEN(data)			(data[8] & 0x01)
#define F11_QUERY_HASGESTURE1(data)		(data[6])
#define F11_QUERY_HASGESTURE2(data)		(data[7] & 0x1F)

struct rmi_f11Query {
	u8	data[9];
};

struct rmi_f11 {
	u8					enable;
	u32					queryBase;
	u32					ctrlBase;
	u32					dataBase;
	u32					commandBase;
	struct rmi_f11Query	query;
};

#define F34_QUERY_BOOTLOADERID0(data)		data[0]
#define F34_QUERY_BOOTLOADERID1(data)		data[1]
#define F34_QUERY_UNLOCKED(data)			((data[2] >> 0x01) & 0x01)
#define F34_QUERY_BLOCKSIZE(data)			((data[3] & 0xff) | ((data[4] << 0x08) & 0xff00))
#define F34_QUERY_FIRMBLOCKCOUNT(data)		((data[5] & 0xff) | ((data[6] << 0x08) & 0xff00))
#define F34_QUERY_CONFIGBLOCKCOUNT(data)	((data[7] & 0xff) | ((data[8] << 0x08) & 0xff00))

struct rmi_f34Query {
	u8	data[9];
};

struct rmi_f34 {
	u8					enable;
	u32					queryBase;
	u32					dataBase;
	struct rmi_f34Query	query;
};

struct rmi_map {
	struct rmi_f01	fn01;
	struct rmi_f05	fn05;
	struct rmi_f11	fn11;
	struct rmi_f34	fn34;
};

//#define F11_DATA_FINGERSTATE0(data)		data[0]
#define F11_DATA_XPOS(data)				(((data[0] << 0x04) & 0x0FF0) | (data[2] & 0x0F))
#define F11_DATA_YPOS(data)				(((data[1] << 0x04) & 0x0FF0) | ((data[2] >> 0x04) & 0x0F))
#define F11_DATA_WX(data)				(data[3] & 0x0F)
#define F11_DATA_WY(data)				((data[3] >> 0x04) & 0x0F)
#define F11_DATA_Z(data)				data[4]

struct shtps_rmi_fingerState {
	u8	data[6];
};

#endif /* __SHTPS_RMI_H__ */
