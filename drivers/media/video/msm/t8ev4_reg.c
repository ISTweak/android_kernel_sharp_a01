/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "t8ev4.h"

struct t8ev4_i2c_reg_conf t8ev4_prev_settings[] = {


{0x0114, 0x01}, 
{0x112,0xA},
{0x113,0xA},
{0x0202, 0x01},
{0x0203, 0x00},
{0x0204, 0x00},
{0x0205, 0x48},
{0x0301, 0x08},
{0x0303, 0x01},
{0x0305, 0x02 },
{0x0306, 0x02 },
{0x0307, 0x6E },
{0x030B, 0x01},
{0x0340, 0x04},
{0x0341, 0xBE},
{0x0342, 0x07},
{0x0343, 0x14},
{0x0344, 0x00},
{0x0345, 0x00},
{0x0346, 0x00},
{0x0347, 0x38},
{0x0348, 0x0C},
{0x0349, 0xCF},
{0x034A, 0x09},
{0x034B, 0x67},
{0x034C, 0x06},
{0x034D, 0x60},
{0x034E, 0x04},
{0x034F, 0x98},
{0x0401, 0x00},
{0x0405, 0x10},
{0x0408, 0x00},
{0x0409, 0x04},
{0x040A, 0x00},
{0x040B, 0x00},
{0x040C, 0x06},
{0x040D, 0x60},
{0x040E, 0x04},
{0x040F, 0x98},
{0x0820, 0x04},
{0x0821, 0x20},
{0x0806, 0xD0},
{0x0901, 0x22},
{0x0902, 0x00},
{0x30AA, 0x8B},
{0x30AC, 0x09 },
{0x30AD, 0x9A },
{0x3239, 0x00},
{0x323A, 0x33},
{0x323B, 0x48},
{0x3257, 0xC1},
{0x3259, 0x70},
{0x325A, 0x30},
{0x325B, 0xF0},
{0x325F, 0x70},
{0x3277, 0x80},
{0x3278, 0x80},
{0x3279, 0x80},
{0x327A, 0x80},
{0x0B00, 0x00},
{0x3280, 0x01},
{0x0B06, 0x00},
{0x32C4, 0x00},
{0x3237, 0x03},
{0x3238, 0x04},
{0x3301, 0x08},
{0x3302, 0x06},
{0x3304, 0x00},
{0x3305, 0x87},
{0x3306, 0x00},
{0x3307, 0x33},
{0x3308, 0x0C},
{0x330A, 0x20},
{0x3314, 0x5C},
{0x3320, 0x03},
{0x332C, 0xE0},
{0x332D, 0x4C},
{0x332E, 0x3F},
{0x3330, 0x0B},
{0x3336, 0x01},
{0x333F, 0x1F},
{0x3355, 0x00},
{0x3356, 0x20},
{0x336E, 0x21},
{0x337A, 0x5E},
{0x33A6, 0x00},
{0x33C5, 0x81},
{0x33CF, 0x66},
{0x3006, 0x00},
{0x3007, 0x01},
{0x3031, 0xCC},
{0x322A, 0x02},
{0x322B, 0x00},
{0x322C, 0x22},
{0x322D, 0x00},
{0x32C2, 0x89},
};

struct t8ev4_i2c_reg_conf t8ev4_snap_settings[] = {

{0x0114, 0x01},
{0x0112,  0xA},
{0x0113,  0xA},
{0x0202, 0x01},
{0x0203, 0x00},
{0x0204, 0x00},
{0x0205, 0x48},
{0x0301, 0x08},
{0x0303, 0x01},
{0x0305, 0x02 },
{0x0306, 0x00},
{0x0307, 0x6E },
{0x030B, 0x01},
{0x0340, 0x09},
{0x0341, 0xC4},
{0x0342, 0x0E},
{0x0343, 0x28},
{0x0344, 0x00},
{0x0345, 0x00},
{0x0346, 0x00},
{0x0347, 0x00},
{0x0348, 0x0C},
{0x0349, 0xCF},
{0x034A, 0x09},
{0x034B, 0x9F},
{0x034C, 0x0C},
{0x034D, 0xD0},
{0x034E, 0x09},
{0x034F, 0xA0},
{0x0401, 0x00},
{0x0405, 0x10},
{0x0408, 0x00},
{0x0409, 0x00},
{0x040A, 0x00},
{0x040B, 0x00},
{0x040C, 0x0C},
{0x040D, 0xD0},
{0x040E, 0x09},
{0x040F, 0xA0},
{0x0820, 0x04},
{0x0821, 0x20},
{0x0806, 0xD0},
{0x0901, 0x11},
{0x0902, 0x00},
{0x30AA, 0x8B},
{0x30AC, 0x09 },
{0x30AD, 0x9A },
{0x3239, 0x00},
{0x323A, 0x33},
{0x323B, 0x48},
{0x3257, 0xC1},
{0x3259, 0x70},
{0x325A, 0xA0},
{0x325B, 0xF0},
{0x325F, 0x70},
{0x3277, 0x80},
{0x3278, 0x80},
{0x3279, 0x80},
{0x327A, 0x80},
{0x0B00, 0x00},
{0x3280, 0x01},
{0x0B06, 0x00},
{0x32C4, 0x00},
{0x3237, 0x03},
{0x3238, 0x04},
{0x3301, 0x08},
{0x3302, 0x06},
{0x3304, 0x00},
{0x3305, 0x87},
{0x3306, 0x00},
{0x3307, 0x33},
{0x3308, 0x0C},
{0x330A, 0x20},
{0x3314, 0x5C},
{0x3320, 0x03},
{0x332C, 0xE0},
{0x332D, 0x4C},
{0x332E, 0x3F},
{0x3330, 0x0B},
{0x3336, 0x01},
{0x333F, 0x1F},
{0x3355, 0x00},
{0x3356, 0x20},
{0x336E, 0x21},
{0x337A, 0x5E},
{0x33A6, 0x00},
{0x33C5, 0x81},
{0x33CF, 0x66},
{0x3006, 0x00},
{0x3007, 0x01},
{0x3031, 0xCC},
{0x322A, 0x02},
{0x322B, 0x00},
{0x322C, 0x22},
{0x322D, 0x00},
{0x32C2, 0x89},
};

struct t8ev4_reg t8ev4_regs = {
	//.reg_init = &t8ev4_init_settings[0],
	//.reg_init_size = ARRAY_SIZE(t8ev4_init_settings),
	.reg_prev = &t8ev4_prev_settings[0],
	.reg_prev_size = ARRAY_SIZE(t8ev4_prev_settings),
	.reg_snap = &t8ev4_snap_settings[0],
	.reg_snap_size = ARRAY_SIZE(t8ev4_snap_settings),
};
