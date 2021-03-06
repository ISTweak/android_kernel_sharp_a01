/* kernel/include/sharp/sh_android_usb_apis.h
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

#ifndef __SH_ANDROID_USB_APIS_H
#define __SH_ANDROID_USB_APIS_H

#define D_SH_ANDROID_USB_MODE_PATH	("/sys/devices/platform/android_usb")

#define D_SH_ANDROID_USB_MODE_CDC		"MODE_CDC"
#define D_SH_ANDROID_USB_MODE_MTP		"MODE_MTP"
#define D_SH_ANDROID_USB_MODE_MSC		"MODE_MSC"
#define D_SH_ANDROID_USB_MODE_RNDIS		"MODE_RNDIS"
#define D_SH_ANDROID_USB_MODE_CDC_2		"MODE_CDC_2"
#define D_SH_ANDROID_USB_MODE_WRMAX		(16)


#define D_SH_ANDROID_USB_MODE_N_CDC			(0)
#define D_SH_ANDROID_USB_MODE_N_MTP			(1)
#define D_SH_ANDROID_USB_MODE_N_MSC			(2)
#define D_SH_ANDROID_USB_MODE_N_RNDIS		(3)
#define D_SH_ANDROID_USB_MODE_N_CDC_2		(4)
#define D_SH_ANDROID_USB_MODE_N_NULL		(-1)

#define D_SH_ANDROID_USB_MODE_N_DEF			(D_SH_ANDROID_USB_MODE_N_MSC)

#define D_SH_ANDROID_USB_PID_NULL			(-1)

#endif /* __SH_ANDROID_USB_APIS_H */
