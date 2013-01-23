/* kernel/include/sharp/sh_android_usb_products.h
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

#ifndef __SH_ANDROID_USB_PRODUCTS_H
#define __SH_ANDROID_USB_PRODUCTS_H

#if defined( CONFIG_MACH_STR )
	#include "sh_android_usb_products_str.h"
#elif defined( CONFIG_MACH_RYK )
	#include "sh_android_usb_products_ryk.h"
#elif defined( CONFIG_MACH_DECKARD_AF20 )
	#include "sh_android_usb_products_deckard_af20.h"
#elif defined( CONFIG_MACH_DECKARD_AS35 )
	#include "sh_android_usb_products_deckard_as35.h"
#elif defined( CONFIG_MACH_DECKARD_AS50 )
	#include "sh_android_usb_products_deckard_as50.h"
#else /* CONFIG_MACH_LYNX_DC40 */
	#include "sh_android_usb_products_lynx_dc40.h"
#endif

#endif /* __SH_ANDROID_USB_PRODUCTS_H */
