/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/************************************************************************/


//#ifdef WIN32

#include "sensor_raw.h"

/* Begin Include */
#include "sensor_BF2507_raw_param_common.c"
#include "sensor_BF2507_raw_param_prv_0.c"
#include "sensor_BF2507_raw_param_cap_0.c"
#include "sensor_BF2507_raw_param_video_0.c"

/* End Include */

//#endif


/************************************************************************/


/* IspToolVersion=R1.15.4802_P5 */


/* Capture Sizes:
	2592x1944,2592x1944
*/


/************************************************************************/


static struct sensor_raw_resolution_info_tab s_BF2507_trim_info=
{
	0x00,
	{
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
	}
};


/************************************************************************/


static struct sensor_raw_ioctrl s_BF2507_ioctrl=
{
	0,
	0,
	0
};


/************************************************************************/


static struct sensor_version_info s_BF2507_version_info=
{
	0x00030004,
	sizeof(struct sensor_version_info),
	0x00
};


/************************************************************************/


static uint32_t s_BF2507_libuse_info[]=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
};


/************************************************************************/


static struct sensor_raw_info s_BF2507_mipi_raw_info=
{
	&s_BF2507_version_info,
	{
		{s_BF2507_tune_info_common, sizeof(s_BF2507_tune_info_common)},
		{s_BF2507_tune_info_prv_0, sizeof(s_BF2507_tune_info_prv_0)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},
		{s_BF2507_tune_info_cap_0, sizeof(s_BF2507_tune_info_cap_0)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},
		{s_BF2507_tune_info_video_0, sizeof(s_BF2507_tune_info_video_0)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},

	},
	&s_BF2507_trim_info,
	&s_BF2507_ioctrl,
	(struct sensor_libuse_info *)s_BF2507_libuse_info,
	{
		&s_BF2507_fix_info_common,
		&s_BF2507_fix_info_prv_0,
		NULL,
		NULL,
		NULL,
		&s_BF2507_fix_info_cap_0,
		NULL,
		NULL,
		NULL,
		&s_BF2507_fix_info_video_0,
		NULL,
		NULL,
		NULL,

	},
	{
		{s_BF2507_common_tool_ui_input, sizeof(s_BF2507_common_tool_ui_input)},
		{s_BF2507_prv_0_tool_ui_input, sizeof(s_BF2507_prv_0_tool_ui_input)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},
		{s_BF2507_cap_0_tool_ui_input, sizeof(s_BF2507_cap_0_tool_ui_input)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},
		{s_BF2507_video_0_tool_ui_input, sizeof(s_BF2507_video_0_tool_ui_input)},
		{NULL, 0},
		{NULL, 0},
		{NULL, 0},

	}
};