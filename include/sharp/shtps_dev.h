/* include/sharp/shtps_dev.h
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
#ifndef __SHTPS_DEV_H__
#define __SHTPS_DEV_H__

#if (defined( CONFIG_MACH_DECKARD_AF20 ) || defined( FEATURE_SH_MODEL_AF20 ) )

	struct msm_sh_spitps_platform_data {
		int  gpio_irq;
		int  gpio_hssp_clk;
		int  gpio_hssp_data;
		int  gpio_reset;
		int  gpio_standby;
		int  gpio_vcpin;
		int (*gpio_setup)(void);
		void (*gpio_teardown)(void);
	};

	#define	SH_TOUCH_I2C_DEVNAME	"SH_touchpanel"
	#define	SH_TOUCH_SPI_DEVNAME	"SH_touchpanel"

	#define	SH_TOUCH_IRQ			118
	#define	SH_TOUCH_HSSP_CLK		96
	#define	SH_TOUCH_HSSP_DATA		97
	#define	SH_TOUCH_RESET			55
	#define	SH_TOUCH_STBY			95
	#define	SH_TOUCH_VCPIN			177

	#define	SH_SENSOR_MAX_X			1025
	#define	SH_SENSOR_MAX_Y			1956
	#define	SH_SENSOR_MAX_X_V03		2303
	#define	SH_SENSOR_MAX_Y_V03		4351
	#define	SH_TOUCH_MAX_Z			255

	#define	SH_TOUCH_MAX_DISTANCE	1101
	#define	SH_TOUCH_MAX_DIAGONAL	1101
	#define SH_TOUCH_LCD_MAX_X		539
	#define SH_TOUCH_LCD_MAX_Y		959
	#define SH_TOUCH_LCD_V_MAX_X	539
	#define SH_TOUCH_LCD_V_MAX_Y	1030


	#define	FIRMDATA_SIZE			32768

	#define TPSIF_DEV_NAME			"shtpsif"
	#define	TPSIF_DEV_FULLNAME		"/dev/shtpsif"

	#define SH_TOUCH_IF_DEVNAME 	"shtpsif"
	#define SH_TOUCH_IF_DEVPATH 	"/dev/shtpsif"

	#define TPSDRV_IOC_MAGIC            0xE0

	#define	TPSDEV_ENABLE 				_IO  (TPSDRV_IOC_MAGIC, 0)
	#define	TPSDEV_DISABLE				_IO  (TPSDRV_IOC_MAGIC, 1)
	#define	TPSDEV_FW_VERSION			_IO  (TPSDRV_IOC_MAGIC, 2)
	#define	TPSDEV_FW_DOWNLOAD			_IO  (TPSDRV_IOC_MAGIC, 3)
	#define	TPSDEV_FW_UPDATE			_IO  (TPSDRV_IOC_MAGIC, 4)
	#define	TPSDEV_START_TESTMODE		_IOW (TPSDRV_IOC_MAGIC, 5, int)
	#define	TPSDEV_STOP_TESTMODE		_IO  (TPSDRV_IOC_MAGIC, 6)
	#define	TPSDEV_GET_SENSOR			_IOR (TPSDRV_IOC_MAGIC, 7, int)
	#define	TPSDEV_SET_FIRMPARAM		_IOW (TPSDRV_IOC_MAGIC, 8, int)
	#define	TPSDEV_CALIBRATION_PARAM	_IOW (TPSDRV_IOC_MAGIC, 9, int)
	#define	TPSDEV_SLEEP_ON				_IO  (TPSDRV_IOC_MAGIC, 10)
	#define	TPSDEV_SLEEP_OFF			_IO  (TPSDRV_IOC_MAGIC, 11)
	#define	TPSDEV_FW_UPDATE2			_IO  (TPSDRV_IOC_MAGIC, 12)

	#define	TPSDEV_UPDATE_START			_IOR (TPSDRV_IOC_MAGIC, 13, int)
	#define	TPSDEV_UPDATE_STOP			_IO  (TPSDRV_IOC_MAGIC, 14)
	#define	TPSDEV_GPIO_RESET			_IO  (TPSDRV_IOC_MAGIC, 15)
	#define	TPSDEV_GPIO_HSSPCLK			_IOW (TPSDRV_IOC_MAGIC, 16, int)
	#define	TPSDEV_GPIO_HSSPDATA		_IOW (TPSDRV_IOC_MAGIC, 17, int)
	#define	TPSDEV_GPIO_CLK_INOUT		_IOW (TPSDRV_IOC_MAGIC, 18, int)
	#define	TPSDEV_GPIO_DATA_INOUT		_IOW (TPSDRV_IOC_MAGIC, 19, int)
	#define	TPSDEV_RUN_CLOCK			_IOW (TPSDRV_IOC_MAGIC, 20, int)
	#define	TPSDEV_RECV_BYTE			_IOR (TPSDRV_IOC_MAGIC, 21, int)
	#define	TPSDEV_SEND_BYTE			_IOW (TPSDRV_IOC_MAGIC, 22, int)
	#define	TPSDEV_DETECT_HILO			_IOW (TPSDRV_IOC_MAGIC, 23, int)
	#define	TPSDEV_RECALIBRATION_IDAC	_IO  (TPSDRV_IOC_MAGIC, 24)
	#define TPSDEV_READ_REG				_IOWR(TPSDRV_IOC_MAGIC, 25, struct shtps_ioctl_param)
	#define TPSDEV_WRITE_REG			_IOW (TPSDRV_IOC_MAGIC, 26, struct shtps_ioctl_param)

	typedef struct
	{
		uint8_t bData;
		int nNumBits;
		uint8_t bReset;
	} Tps_send_data;

	typedef struct
	{
		uint16_t wPosX;						/* X Pos */
		uint16_t wPosY;						/* Y Pos */
		uint8_t  bSensData[180];			/* Sensor data */
		uint8_t  bCounter;					/* New Data Counter */
	} TpsSensorData;

	struct shtps_ioctl_param {
		int				size;
		unsigned char*	data;
	};

	enum shtps_drag_threshold_mode {
		TPS_DRAG_THRESHOLD_1ST,
		TPS_DRAG_THRESHOLD_2ND
	};

	void msm_spitps_flipchange(int nFlipState);
	void msm_tps_setsleep(int nIsSleep);
	void msm_tps_shutdown(void);
	void msm_tps_set_chargerarmor(int nMode);

#else

	#define SH_TOUCH_DEVNAME		"shtps_rmi"
	#define SH_TOUCH_IF_DEVNAME 	"shtpsif"
	#define SH_TOUCH_IF_DEVPATH 	"/dev/shtpsif"

	#if defined( CONFIG_MACH_DECKARD_AS35 )
		#define SHTPS_TM_TXNUM_MAX		19
		#define SHTPS_TM_RXNUM_MAX		11
	#else
		#define SHTPS_TM_TXNUM_MAX		20
		#define SHTPS_TM_RXNUM_MAX		11
	#endif	/* CONFIG_MACH_DECKARD_AS35 */

	#define TPS_IOC_MAGIC					0xE0

	#define TPSDEV_ENABLE					_IO  ( TPS_IOC_MAGIC,  1)
	#define TPSDEV_DISABLE					_IO  ( TPS_IOC_MAGIC,  2)
	#define TPSDEV_RESET					_IO  ( TPS_IOC_MAGIC,  3)
	#define TPSDEV_SOFT_RESET				_IO  ( TPS_IOC_MAGIC,  4)
	#define TPSDEV_GET_FW_VERSION			_IOR ( TPS_IOC_MAGIC,  5, unsigned short)
	#define TPSDEV_ENTER_BOOTLOADER			_IOR ( TPS_IOC_MAGIC,  6, struct shtps_bootloader_info)
	#define TPSDEV_LOCKDOWN_BOOTLOADER		_IOW ( TPS_IOC_MAGIC,  7, struct shtps_ioctl_param)
	#define TPSDEV_ERASE_FLASE				_IO  ( TPS_IOC_MAGIC,  8)
	#define TPSDEV_WRITE_IMAGE				_IOW ( TPS_IOC_MAGIC,  9, struct shtps_ioctl_param)
	#define TPSDEV_WRITE_CONFIG				_IOW ( TPS_IOC_MAGIC, 10, struct shtps_ioctl_param)
	#define TPSDEV_GET_TOUCHINFO			_IOR ( TPS_IOC_MAGIC, 11, struct shtps_touch_info)
	#define TPSDEV_GET_TOUCHINFO_UNTRANS	_IOR ( TPS_IOC_MAGIC, 12, struct shtps_touch_info)
	#define TPSDEV_SET_TOUCHMONITOR_MODE	_IOW ( TPS_IOC_MAGIC, 13, unsigned char)
	#define TPSDEV_READ_REG					_IOWR( TPS_IOC_MAGIC, 14, struct shtps_ioctl_param)
	#define TPSDEV_READ_ALL_REG				_IOR ( TPS_IOC_MAGIC, 15, struct shtps_ioctl_param)
	#define TPSDEV_WRITE_REG				_IOW ( TPS_IOC_MAGIC, 16, struct shtps_ioctl_param)
	#define TPSDEV_START_TM					_IOW ( TPS_IOC_MAGIC, 17, struct shtps_ioctl_param)
	#define TPSDEV_STOP_TM					_IO  ( TPS_IOC_MAGIC, 18)
	#define TPSDEV_GET_BASELINE				_IOR ( TPS_IOC_MAGIC, 19, unsigned short*)
	#define TPSDEV_GET_FRAMELINE			_IOR ( TPS_IOC_MAGIC, 20, unsigned char*)
	#define TPSDEV_START_FACETOUCHMODE		_IO  ( TPS_IOC_MAGIC, 21)
	#define TPSDEV_STOP_FACETOUCHMODE		_IO  ( TPS_IOC_MAGIC, 22)
	#define TPSDEV_POLL_FACETOUCHOFF		_IO  ( TPS_IOC_MAGIC, 23)
	#define TPSDEV_GET_FWSTATUS				_IOR ( TPS_IOC_MAGIC, 24, unsigned char)
	#define TPSDEV_GET_FWDATE				_IOR ( TPS_IOC_MAGIC, 25, unsigned short)
	#define TPSDEV_CALIBRATION_PARAM		_IOW ( TPS_IOC_MAGIC, 26, struct shtps_ioctl_param)
	#define TPSDEV_DEBUG_REQEVENT			_IOW ( TPS_IOC_MAGIC, 27, int)
	#define TPSDEV_SET_DRAGSTEP				_IOW ( TPS_IOC_MAGIC, 28, int)
	#define TPSDEV_SET_POLLINGINTERVAL		_IOW ( TPS_IOC_MAGIC, 29, int)
	#define TPSDEV_SET_FINGERFIXTIME		_IOW ( TPS_IOC_MAGIC, 30, int)
	#define TPSDEV_REZERO					_IO  ( TPS_IOC_MAGIC, 31)
	#define TPSDEV_ACK_FACETOUCHOFF			_IO  ( TPS_IOC_MAGIC, 32)
	#define TPSDEV_START_TM_F05				_IOW ( TPS_IOC_MAGIC, 33, int)
	#define TPSDEV_SET_DRAGSTEP_X			_IOW ( TPS_IOC_MAGIC, 34, int)
	#define TPSDEV_SET_DRAGSTEP_Y			_IOW ( TPS_IOC_MAGIC, 35, int)
	#define TPSDEV_LOGOUTPUT_ENABLE			_IOW ( TPS_IOC_MAGIC, 36, int)

	#define TPSDEV_FACETOUCHOFF_NOCHG	0x00
	#define TPSDEV_FACETOUCHOFF_DETECT	0x01

	#define TPSDEV_TOUCHINFO_MODE_LCDSIZE	0
	#define TPSDEV_TOUCHINFO_MODE_DEVSIZE	1

	struct shtps_ioctl_param {
		int				size;
		unsigned char*	data;
	};

	struct shtps_bootloader_info {
		unsigned long	block_size;
		unsigned long	program_block_num;
		unsigned long	config_block_num;
	};

	struct shtps_touch_info {
		struct fingers{
			unsigned char	state;
			unsigned short	x;
			unsigned short	y;
			unsigned char	wx;
			unsigned char	wy;
			unsigned char	z;
		} fingers[5];
		
		unsigned char		gs1;
		unsigned char		gs2;
		unsigned char		flick_x;
		unsigned char		flick_y;
		unsigned char		flick_time;
		unsigned char		finger_num;
	};

	/* -----------------------------------------------------------------------------------
	 */
	void msm_tps_setsleep(int on);

#endif	/* #if (defined( CONFIG_MACH_DECKARD_AF20 ) || defined( FEATURE_SH_MODEL_AF20 ) ) */
#endif
