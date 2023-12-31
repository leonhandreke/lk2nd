/* Copyright (c) 2011, 2014, 2017, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <dev/fbcon.h>
#include <msm_panel.h>
#include <platform/iomap.h>
#include <smem.h>

//TODO: Make a global PASS / FAIL define
#define PASS                        0
#define FAIL                        1

#define EFUSE_ENTRY(addr,off,s, m, sh,id) \
{\
	.start_address =addr,\
	.offset = off, \
	.size   = s,\
	.mask   = m,\
	.shift  = sh,\
	.board_id = id \
}

struct mdp_efuse_data {
	uint32_t start_address;
	uint32_t offset;
	uint32_t size;
	uint32_t mask;
	uint32_t shift;
	uint32_t board_id;
};

#ifdef SEC_CTRL_CORE_BASE
static struct mdp_efuse_data efuse_data[] __UNUSED = {
        EFUSE_ENTRY(SEC_CTRL_CORE_BASE, EFUSE_OFFSET, 4, 0x20000000, 0x1D, APQ8009),
};
#endif

int mdp_setup_dma_p_video_mode(unsigned short disp_width,
			       unsigned short disp_height,
			       unsigned short img_width,
			       unsigned short img_height,
			       unsigned short hsync_porch0_fp,
			       unsigned short hsync_porch0_bp,
			       unsigned short vsync_porch0_fp,
			       unsigned short vsync_porch0_bp,
			       unsigned short hsync_width,
			       unsigned short vsync_width,
			       unsigned long input_img_addr,
			       unsigned short img_width_full_size,
			       unsigned short pack_pattern,
			       unsigned char ystride);

void mdp_disable(void);
void mdp_shutdown(void);
void mdp_set_revision(int rev);
int mdp_get_revision(void);

/* defining no-op functions that are implemented only for mdp5 */
int mdp_edp_config(struct msm_panel_info *pinfo, struct fbcon_config *fb);
int mdp_edp_on(struct msm_panel_info *pinfo);
int mdp_edp_off(void);
bool display_efuse_check(void);
void efuse_display_enable(char *pbuf, uint16_t buf_size);
