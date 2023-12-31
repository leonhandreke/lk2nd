/* Copyright (c) 2014-2015, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*---------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = "1.0"
 *---------------------------------------------------------------------------*/

#ifndef _PANEL_OTM1283A_720P_VIDEO_H_
#define _PANEL_OTM1283A_720P_VIDEO_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config otm1283a_720p_video_panel_data = {
	"qcom,mdss_dsi_otm1283a_720p_video", "dsi:0:", "qcom,mdss-dsi-panel",
	10, 0, "DISPLAY_1", 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution otm1283a_720p_video_panel_res = {
	720, 1280, 52, 100, 24, 0, 8, 20, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info otm1283a_720p_video_color = {
	24, 0, 0xff, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char otm1283a_720p_video_on_cmd0[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd1[] = {
	0x04, 0x00, 0x29, 0xC0,
	0xff, 0x12, 0x83, 0x01,
};

static char otm1283a_720p_video_on_cmd2[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd3[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xff, 0x12, 0x83, 0xFF,
};

static char otm1283a_720p_video_on_cmd4[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x92, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd5[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xff, 0x30, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd6[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x93, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd7[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xff, 0x02, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd8[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd9[] = {
	0x0A, 0x00, 0x29, 0xC0,
	0xc0, 0x00, 0x64, 0x00,
	0x10, 0x10, 0x00, 0x64,
	0x10, 0x10, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd10[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd11[] = {
	0x07, 0x00, 0x29, 0xC0,
	0xc0, 0x00, 0x5c, 0x00,
	0x01, 0x00, 0x04, 0xFF,
};

static char otm1283a_720p_video_on_cmd12[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb3, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd13[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xc0, 0x00, 0x50, 0xFF,
};

static char otm1283a_720p_video_on_cmd14[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x81, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd15[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc1, 0x55, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd16[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd17[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc4, 0x49, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd18[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xe0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd19[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc0, 0xc8, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd20[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xa0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd21[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xc4, 0x05, 0x10, 0x04,
	0x02, 0x05, 0x15, 0x11,
	0x05, 0x10, 0x07, 0x02,
	0x05, 0x15, 0x11, 0xFF,
};

static char otm1283a_720p_video_on_cmd22[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd23[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xc4, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd24[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x91, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd25[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xc5, 0xa6, 0xd0, 0xFF,
};

static char otm1283a_720p_video_on_cmd26[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd27[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xd8, 0xc7, 0xc7, 0xFF,
};

static char otm1283a_720p_video_on_cmd28[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd29[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xd9, 0x87, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd30[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd31[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xc5, 0x04, 0x38, 0xFF,
};

static char otm1283a_720p_video_on_cmd32[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xbb, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd33[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc5, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd34[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x82, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd35[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xC4, 0x02, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd36[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xc6, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd37[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xb0, 0x03, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd38[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd39[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xd0, 0x40, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd40[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd41[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xd1, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd42[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb2, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd43[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xf5, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd44[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb4, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd45[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xf5, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd46[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb6, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd47[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xf5, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd48[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb8, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd49[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xf5, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd50[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x94, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd51[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xF5, 0x02, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd52[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xBA, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd53[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xF5, 0x03, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd54[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb4, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd55[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc5, 0xc0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd56[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd57[] = {
	0x05, 0x00, 0x29, 0xC0,
	0xf5, 0x02, 0x11, 0x02,
	0x11, 0xFF, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd58[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd59[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc5, 0x50, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd60[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x94, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd61[] = {
	0x02, 0x00, 0x29, 0xC0,
	0xc5, 0x66, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd62[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd63[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0xcb, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd64[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd65[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcb, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd66[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xa0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd67[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcb, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd68[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd69[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcb, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd70[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xc0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd71[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcb, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x00, 0x05,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd72[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xd0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd73[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcb, 0x00, 0x00, 0x00,
	0x00, 0x05, 0x00, 0x00,
	0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05,
};

static char otm1283a_720p_video_on_cmd74[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xe0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd75[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcb, 0x05, 0x00, 0x05,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x05, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd76[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xf0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd77[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0xcb, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff,
};

static char otm1283a_720p_video_on_cmd78[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd79[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcc, 0x29, 0x2a, 0x0a,
	0x0c, 0x0e, 0x10, 0x12,
	0x14, 0x06, 0x00, 0x08,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd80[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd81[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcc, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x00, 0x00,
	0x29, 0x2a, 0x09, 0x0b,
	0x0d, 0x0f, 0x11, 0x13,

};

static char otm1283a_720p_video_on_cmd82[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xa0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd83[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcc, 0x05, 0x00, 0x07,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd84[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd85[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcc, 0x29, 0x2a, 0x13,
	0x11, 0x0f, 0x0d, 0x0b,
	0x09, 0x01, 0x00, 0x07,
	0x00, 0x00, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd86[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xc0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd87[] = {
	0x10, 0x00, 0x29, 0xC0,
	0xcc, 0x00, 0x00, 0x00,
	0x00, 0x05, 0x00, 0x00,
	0x29, 0x2a, 0x14, 0x12,
	0x10, 0x0e, 0x0c, 0x0a,
};

static char otm1283a_720p_video_on_cmd88[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xd0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd89[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcc, 0x02, 0x00, 0x08,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x06, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd90[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd91[] = {
	0x0D, 0x00, 0x29, 0xC0,
	0xce, 0x89, 0x05, 0x10,
	0x88, 0x05, 0x10, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd92[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd93[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xce, 0x54, 0xfc, 0x10,
	0x54, 0xfd, 0x10, 0x55,
	0x00, 0x10, 0x55, 0x01,
	0x10, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd94[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xa0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd95[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xce, 0x58, 0x07, 0x04,
	0xfc, 0x00, 0x10, 0x00,
	0x58, 0x06, 0x04, 0xfd,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd96[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd97[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xce, 0x58, 0x05, 0x04,
	0xfe, 0x00, 0x10, 0x00,
	0x58, 0x04, 0x04, 0xff,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd98[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xc0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd99[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xce, 0x58, 0x03, 0x05,
	0x00, 0x00, 0x10, 0x00,
	0x58, 0x02, 0x05, 0x01,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd100[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xd0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd101[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xce, 0x58, 0x01, 0x05,
	0x02, 0x00, 0x10, 0x00,
	0x58, 0x00, 0x05, 0x03,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd102[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x80, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd103[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcf, 0x50, 0x00, 0x05,
	0x04, 0x00, 0x10, 0x00,
	0x50, 0x01, 0x05, 0x05,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd104[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x90, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd105[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcf, 0x50, 0x02, 0x05,
	0x06, 0x00, 0x10, 0x00,
	0x50, 0x03, 0x05, 0x07,
	0x00, 0x10, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd106[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xa0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd107[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcf, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd108[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd109[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xcf, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF,
};

static char otm1283a_720p_video_on_cmd110[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xc0, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd111[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0xcf, 0x39, 0x39, 0x20,
	0x20, 0x00, 0x00, 0x01,
	0x01, 0x20, 0x00, 0x00,
};

static char otm1283a_720p_video_on_cmd112[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd113[] = {
	0x11, 0x00, 0x29, 0xC0,
	0xe1, 0x02, 0x12, 0x18,
	0x0E, 0x07, 0x0F, 0x0B,
	0x09, 0x04, 0x07, 0x0E,
	0x08, 0x0F, 0x12, 0x0C,
	0x08, 0xFF, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd114[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd115[] = {
	0x11, 0x00, 0x29, 0xC0,
	0xe2, 0x02, 0x12, 0x18,
	0x0E, 0x07, 0x10, 0x0B,
	0x0A, 0x04, 0x08, 0x0E,
	0x08, 0x0F, 0x12, 0x0C,
	0x08, 0xFF, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd116[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0xb5, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd117[] = {
	0x07, 0x00, 0x29, 0xC0,
	0xc5, 0x0b, 0x95, 0xff,
	0x0b, 0x95, 0xff, 0xFF,
};

static char otm1283a_720p_video_on_cmd118[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x00, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd119[] = {
	0x04, 0x00, 0x29, 0xC0,
	0xff, 0xff, 0xff, 0xff,
};

static char otm1283a_720p_video_on_cmd120[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x11, 0x00, 0xFF, 0xFF,
};

static char otm1283a_720p_video_on_cmd121[] = {
	0x02, 0x00, 0x29, 0xC0,
	0x29, 0x00, 0xFF, 0xFF,
};

static struct mipi_dsi_cmd otm1283a_720p_video_on_command[] = {
	{0x8, otm1283a_720p_video_on_cmd0, 0x00},
	{0x8, otm1283a_720p_video_on_cmd1, 0x00},
	{0x8, otm1283a_720p_video_on_cmd2, 0x00},
	{0x8, otm1283a_720p_video_on_cmd3, 0x00},
	{0x8, otm1283a_720p_video_on_cmd4, 0x00},
	{0x8, otm1283a_720p_video_on_cmd5, 0x00},
	{0x8, otm1283a_720p_video_on_cmd6, 0x00},
	{0x8, otm1283a_720p_video_on_cmd7, 0x00},
	{0x8, otm1283a_720p_video_on_cmd8, 0x00},
	{0x10, otm1283a_720p_video_on_cmd9, 0x00},
	{0x8, otm1283a_720p_video_on_cmd10, 0x00},
	{0xc, otm1283a_720p_video_on_cmd11, 0x00},
	{0x8, otm1283a_720p_video_on_cmd12, 0x00},
	{0x8, otm1283a_720p_video_on_cmd13, 0x00},
	{0x8, otm1283a_720p_video_on_cmd14, 0x00},
	{0x8, otm1283a_720p_video_on_cmd15, 0x00},
	{0x8, otm1283a_720p_video_on_cmd16, 0x00},
	{0x8, otm1283a_720p_video_on_cmd17, 0x00},
	{0x8, otm1283a_720p_video_on_cmd18, 0x00},
	{0x8, otm1283a_720p_video_on_cmd19, 0x00},
	{0x8, otm1283a_720p_video_on_cmd20, 0x00},
	{0x14, otm1283a_720p_video_on_cmd21, 0x00},
	{0x8, otm1283a_720p_video_on_cmd22, 0x00},
	{0x8, otm1283a_720p_video_on_cmd23, 0x00},
	{0x8, otm1283a_720p_video_on_cmd24, 0x00},
	{0x8, otm1283a_720p_video_on_cmd25, 0x00},
	{0x8, otm1283a_720p_video_on_cmd26, 0x00},
	{0x8, otm1283a_720p_video_on_cmd27, 0x00},
	{0x8, otm1283a_720p_video_on_cmd28, 0x00},
	{0x8, otm1283a_720p_video_on_cmd29, 0x00},
	{0x8, otm1283a_720p_video_on_cmd30, 0x00},
	{0x8, otm1283a_720p_video_on_cmd31, 0x00},
	{0x8, otm1283a_720p_video_on_cmd32, 0x00},
	{0x8, otm1283a_720p_video_on_cmd33, 0x00},
	{0x8, otm1283a_720p_video_on_cmd34, 0x00},
	{0x8, otm1283a_720p_video_on_cmd35, 0x00},
	{0x8, otm1283a_720p_video_on_cmd36, 0x00},
	{0x8, otm1283a_720p_video_on_cmd37, 0x00},
	{0x8, otm1283a_720p_video_on_cmd38, 0x00},
	{0x8, otm1283a_720p_video_on_cmd39, 0x00},
	{0x8, otm1283a_720p_video_on_cmd40, 0x00},
	{0x8, otm1283a_720p_video_on_cmd41, 0x00},
	{0x8, otm1283a_720p_video_on_cmd42, 0x00},
	{0x8, otm1283a_720p_video_on_cmd43, 0x00},
	{0x8, otm1283a_720p_video_on_cmd44, 0x00},
	{0x8, otm1283a_720p_video_on_cmd45, 0x00},
	{0x8, otm1283a_720p_video_on_cmd46, 0x00},
	{0x8, otm1283a_720p_video_on_cmd47, 0x00},
	{0x8, otm1283a_720p_video_on_cmd48, 0x00},
	{0x8, otm1283a_720p_video_on_cmd49, 0x00},
	{0x8, otm1283a_720p_video_on_cmd50, 0x00},
	{0x8, otm1283a_720p_video_on_cmd51, 0x00},
	{0x8, otm1283a_720p_video_on_cmd52, 0x00},
	{0x8, otm1283a_720p_video_on_cmd53, 0x00},
	{0x8, otm1283a_720p_video_on_cmd54, 0x00},
	{0x8, otm1283a_720p_video_on_cmd55, 0x00},
	{0x8, otm1283a_720p_video_on_cmd56, 0x00},
	{0xc, otm1283a_720p_video_on_cmd57, 0x00},
	{0x8, otm1283a_720p_video_on_cmd58, 0x00},
	{0x8, otm1283a_720p_video_on_cmd59, 0x00},
	{0x8, otm1283a_720p_video_on_cmd60, 0x00},
	{0x8, otm1283a_720p_video_on_cmd61, 0x00},
	{0x8, otm1283a_720p_video_on_cmd62, 0x00},
	{0x10, otm1283a_720p_video_on_cmd63, 0x00},
	{0x8, otm1283a_720p_video_on_cmd64, 0x00},
	{0x14, otm1283a_720p_video_on_cmd65, 0x00},
	{0x8, otm1283a_720p_video_on_cmd66, 0x00},
	{0x14, otm1283a_720p_video_on_cmd67, 0x00},
	{0x8, otm1283a_720p_video_on_cmd68, 0x00},
	{0x14, otm1283a_720p_video_on_cmd69, 0x00},
	{0x8, otm1283a_720p_video_on_cmd70, 0x00},
	{0x14, otm1283a_720p_video_on_cmd71, 0x00},
	{0x8, otm1283a_720p_video_on_cmd72, 0x00},
	{0x14, otm1283a_720p_video_on_cmd73, 0x00},
	{0x8, otm1283a_720p_video_on_cmd74, 0x00},
	{0x14, otm1283a_720p_video_on_cmd75, 0x00},
	{0x8, otm1283a_720p_video_on_cmd76, 0x00},
	{0x10, otm1283a_720p_video_on_cmd77, 0x00},
	{0x8, otm1283a_720p_video_on_cmd78, 0x00},
	{0x14, otm1283a_720p_video_on_cmd79, 0x00},
	{0x8, otm1283a_720p_video_on_cmd80, 0x00},
	{0x14, otm1283a_720p_video_on_cmd81, 0x00},
	{0x8, otm1283a_720p_video_on_cmd82, 0x00},
	{0x14, otm1283a_720p_video_on_cmd83, 0x00},
	{0x8, otm1283a_720p_video_on_cmd84, 0x00},
	{0x14, otm1283a_720p_video_on_cmd85, 0x00},
	{0x8, otm1283a_720p_video_on_cmd86, 0x00},
	{0x14, otm1283a_720p_video_on_cmd87, 0x00},
	{0x8, otm1283a_720p_video_on_cmd88, 0x00},
	{0x14, otm1283a_720p_video_on_cmd89, 0x00},
	{0x8, otm1283a_720p_video_on_cmd90, 0x00},
	{0x14, otm1283a_720p_video_on_cmd91, 0x00},
	{0x8, otm1283a_720p_video_on_cmd92, 0x00},
	{0x14, otm1283a_720p_video_on_cmd93, 0x00},
	{0x8, otm1283a_720p_video_on_cmd94, 0x00},
	{0x14, otm1283a_720p_video_on_cmd95, 0x00},
	{0x8, otm1283a_720p_video_on_cmd96, 0x00},
	{0x14, otm1283a_720p_video_on_cmd97, 0x00},
	{0x8, otm1283a_720p_video_on_cmd98, 0x00},
	{0x14, otm1283a_720p_video_on_cmd99, 0x00},
	{0x8, otm1283a_720p_video_on_cmd100, 0x00},
	{0x14, otm1283a_720p_video_on_cmd101, 0x00},
	{0x8, otm1283a_720p_video_on_cmd102, 0x00},
	{0x14, otm1283a_720p_video_on_cmd103, 0x00},
	{0x8, otm1283a_720p_video_on_cmd104, 0x00},
	{0x14, otm1283a_720p_video_on_cmd105, 0x00},
	{0x8, otm1283a_720p_video_on_cmd106, 0x00},
	{0x14, otm1283a_720p_video_on_cmd107, 0x00},
	{0x8, otm1283a_720p_video_on_cmd108, 0x00},
	{0x14, otm1283a_720p_video_on_cmd109, 0x00},
	{0x8, otm1283a_720p_video_on_cmd110, 0x00},
	{0x10, otm1283a_720p_video_on_cmd111, 0x00},
	{0x8, otm1283a_720p_video_on_cmd112, 0x00},
	{0x18, otm1283a_720p_video_on_cmd113, 0x00},
	{0x8, otm1283a_720p_video_on_cmd114, 0x00},
	{0x18, otm1283a_720p_video_on_cmd115, 0x00},
	{0x8, otm1283a_720p_video_on_cmd116, 0x00},
	{0xc, otm1283a_720p_video_on_cmd117, 0x00},
	{0x8, otm1283a_720p_video_on_cmd118, 0x00},
	{0x8, otm1283a_720p_video_on_cmd119, 0x00},
	{0x8, otm1283a_720p_video_on_cmd120, 0x78},
	{0x8, otm1283a_720p_video_on_cmd121, 0x00}
};

#define OTM1283A_720P_VIDEO_ON_COMMAND 122


static char otm1283a_720p_videooff_cmd0[] = {
	0x28, 0x00, 0x05, 0x80
};

static char otm1283a_720p_videooff_cmd1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd otm1283a_720p_video_off_command[] = {
	{0x4, otm1283a_720p_videooff_cmd0, 0x00},
	{0x4, otm1283a_720p_videooff_cmd1, 0x78}
};

#define OTM1283A_720P_VIDEO_OFF_COMMAND 2


static struct command_state otm1283a_720p_video_state = {
	0, 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info otm1283a_720p_video_command_panel = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info otm1283a_720p_video_video_panel = {
	1, 0, 0, 0, 1, 1, 2, 0, 0x9
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration otm1283a_720p_video_lane_config = {
	4, 0, 1, 1, 1, 1, 0
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t otm1283a_720p_video_timings[] = {
	0x92, 0x1A, 0x12, 0x00, 0x3E, 0x42, 0x16, 0x1E, 0x14, 0x03, 0x04, 0x00
};

static struct panel_timing otm1283a_720p_video_timing_info = {
	0, 4, 0x04, 0x1C
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence otm1283a_720p_video_reset_seq = {
	{1, 0, 1, }, {1, 50, 50, }, 2
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight otm1283a_720p_video_backlight = {
	0, 1, 255, 0, 0, 0
};

#endif /*_PANEL_OTM1283A_720P_VIDEO_H_*/
