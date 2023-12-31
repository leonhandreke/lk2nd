/* Copyright (c) 2013-2015, The Linux Foundation. All rights reserved.
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
 */

#include <stdint.h>
#include <debug.h>
#include <reg.h>
#include <mmc.h>
#include <clock.h>
#include <pm8x41.h>
#include <platform/clock.h>
#include <platform/iomap.h>
#include <platform/timer.h>
#include <rpm-smd.h>
#include <regulator.h>
#include <platform.h>

#define RPM_CE_CLK_TYPE    0x6563
#define CE2_CLK_ID         0x1
#define RPM_SMD_KEY_RATE   0x007A484B

#define MAX_LOOPS	500

uint32_t CE2_CLK[][8]=
{
	{
		RPM_CE_CLK_TYPE, CE2_CLK_ID,
		KEY_SOFTWARE_ENABLE, 4, GENERIC_DISABLE,
		RPM_SMD_KEY_RATE, 4, 0,
	},
	{
		RPM_CE_CLK_TYPE, CE2_CLK_ID,
		KEY_SOFTWARE_ENABLE, 4, GENERIC_ENABLE,
		RPM_SMD_KEY_RATE, 4, 176128,
	},
};

void hsusb_clock_init(void)
{
	int ret;
	struct clk *iclk, *cclk;

	ret = clk_get_set_enable("usb_iface_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb_iface_clk ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb_core_clk", 75000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb_core_clk ret = %d\n", ret);
		ASSERT(0);
	}

	/* Wait for the clocks to be stable since we are disabling soon after. */
	mdelay(1);

	iclk = clk_get("usb_iface_clk");
	cclk = clk_get("usb_core_clk");

	clk_disable(iclk);
	clk_disable(cclk);

	/* Wait for the clock disable to complete. */
	mdelay(1);

	/* Start the block reset for usb */
	writel(1, USB_HS_BCR);

	/* Wait for reset to complete. */
	mdelay(1);

	/* Take usb block out of reset */
	writel(0, USB_HS_BCR);

	/* Wait for the block to be brought out of reset. */
	mdelay(1);

	ret = clk_enable(iclk);

	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb_iface_clk after async ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_enable(cclk);

	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb_iface_clk after async ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb_phy_cfg_ahb2phy_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to enable usb_phy_cfg_ahb2phy_clk = %d\n", ret);
		ASSERT(0);
	}
}

void clock_init_mmc(uint32_t interface)
{
	char clk_name[64];
	int ret;

	snprintf(clk_name, sizeof(clk_name), "sdc%u_iface_clk", interface);

	/* enable interface clock */
	ret = clk_get_set_enable(clk_name, 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set sdc%u_iface_clk ret = %d\n", interface, ret);
		ASSERT(0);
	}
}

/* Configure MMC clock */
void clock_config_mmc(uint32_t interface, uint32_t freq)
{
	int ret = 0;
	char clk_name[64];

	snprintf(clk_name, sizeof(clk_name), "sdc%u_core_clk", interface);

	if(freq == MMC_CLK_400KHZ)
	{
		ret = clk_get_set_enable(clk_name, 400000, 1);
	}
	else if(freq == MMC_CLK_50MHZ)
	{
		ret = clk_get_set_enable(clk_name, 50000000, 1);
	}
	else if(freq == MMC_CLK_96MHZ)
	{
		ret = clk_get_set_enable(clk_name, 100000000, 1);
	}
	else if(freq == MMC_CLK_192MHZ)
	{
		if (platform_is_msm8992())
			ret = clk_get_set_enable(clk_name, 172000000, 1);
		else
			ret = clk_get_set_enable(clk_name, 192000000, 1);
	}
	else if(freq == MMC_CLK_200MHZ)
	{
		ret = clk_get_set_enable(clk_name, 200000000, 1);
	}
	else if(freq == MMC_CLK_400MHZ)
	{
		if (platform_is_msm8992())
			ret = clk_get_set_enable(clk_name, 344000000, 1);
		else
			ret = clk_get_set_enable(clk_name, 384000000, 1);
	}
	else
	{
		dprintf(CRITICAL, "sdc frequency (%u) is not supported\n", freq);
		ASSERT(0);
	}


	if(ret)
	{
		dprintf(CRITICAL, "failed to set sdc%u_core_clk ret = %d\n", interface, ret);
		ASSERT(0);
	}
}

/* Configure UART clock based on the UART block id*/
void clock_config_uart_dm(uint8_t id)
{
	int ret;
	char iclk[64];
	char cclk[64];

	snprintf(iclk, sizeof(iclk), "uart%u_iface_clk", id);
	snprintf(cclk, sizeof(cclk), "uart%u_core_clk", id);

	ret = clk_get_set_enable(iclk, 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set uart%u_iface_clk ret = %d\n", id, ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable(cclk, 7372800, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set uart%u_core_clk ret = %d\n", id, ret);
		ASSERT(0);
	}
}

/* Function to asynchronously reset CE (Crypto Engine).
 * Function assumes that all the CE clocks are off.
 */
static void ce_async_reset(uint8_t instance)
{
	if (instance == 2)
	{
		/* Start the block reset for CE */
		writel(1, GCC_CE2_BCR);
		udelay(2);
		/* Take CE block out of reset */
		writel(0, GCC_CE2_BCR);
		udelay(2);
	}
	else
	{
		dprintf(CRITICAL, "Unsupported CE instance: %u\n", instance);
		ASSERT(0);
	}
}

void clock_ce_enable(uint8_t instance)
{
	if (instance == 2)
		rpm_send_data(&CE2_CLK[GENERIC_ENABLE][0], 24, RPM_REQUEST_TYPE);
	else
	{
		dprintf(CRITICAL, "Unsupported CE instance: %u\n", instance);
		ASSERT(0);
	}
}

void clock_ce_disable(uint8_t instance)
{
	if (instance == 2)
		rpm_send_data(&CE2_CLK[GENERIC_DISABLE][0], 24, RPM_REQUEST_TYPE);
	else
	{
		dprintf(CRITICAL, "Unsupported CE instance: %u\n", instance);
		ASSERT(0);
	}
}

void clock_config_ce(uint8_t instance)
{
	/* Need to enable the clock before disabling since the clk_disable()
	 * has a check to default to nop when the clk_enable() is not called
	 * on that particular clock.
	 */
	clock_ce_enable(instance);

	clock_ce_disable(instance);

	ce_async_reset(instance);

	clock_ce_enable(instance);

}

void clock_usb30_gdsc_enable(void)
{
	uint32_t reg = readl(GCC_USB30_GDSCR);

	reg &= ~(0x1);

	writel(reg, GCC_USB30_GDSCR);
}

/* enables usb30 clocks */
void clock_usb30_init(void)
{
	int ret;

	ret = clk_get_set_enable("usb30_iface_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_iface_clk. ret = %d\n", ret);
		ASSERT(0);
	}

	clock_usb30_gdsc_enable();

	ret = clk_get_set_enable("usb30_master_clk", 125000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_master_clk. ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb30_phy_aux_clk", 1200000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_phy_aux_clk. ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb30_mock_utmi_clk", 60000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_mock_utmi_clk ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb30_sleep_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_sleep_clk ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("usb_phy_cfg_ahb2phy_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to enable usb_phy_cfg_ahb2phy_clk = %d\n", ret);
		ASSERT(0);
	}

	pm8x41_lnbb_clock_ctrl(1);
}

void clock_bumpup_pipe3_clk(void)
{
	int ret = 0;

	ret = clk_get_set_enable("usb30_pipe_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set usb30_pipe_clk. ret = %d\n", ret);
		ASSERT(0);
	}

	return;
}

void mdp_gdsc_ctrl(uint8_t enable)
{
	uint32_t reg = 0;
	reg = readl(MDP_GDSCR);
	if (enable) {
		if (!(reg & GDSC_POWER_ON_BIT)) {
			reg &=  ~(BIT(0) | GDSC_EN_FEW_WAIT_MASK);
			reg |= GDSC_EN_FEW_WAIT_256_MASK;
			writel(reg, MDP_GDSCR);
			while(!(readl(MDP_GDSCR) & (GDSC_POWER_ON_BIT)));
		} else {
			dprintf(INFO, "MDP GDSC already enabled\n");
		}
	} else {
		reg |= BIT(0);
		writel(reg, MDP_GDSCR);
		while(readl(MDP_GDSCR) & (GDSC_POWER_ON_BIT));
	}
}

/* Configure MDP clock */
void mdp_clock_enable(void)
{
	int ret;

	/* Set MDP clock to 240MHz */
	ret = clk_get_set_enable("mdp_ahb_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mdp_ahb_clk ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("mdss_mdp_clk_src", 300000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mdp_clk_src ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("mdss_vsync_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mdss vsync clk ret = %d\n", ret);
		ASSERT(0);
	}

	ret = clk_get_set_enable("mdss_mdp_clk", 0, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mdp_clk ret = %d\n", ret);
		ASSERT(0);
	}
}

void mdp_clock_disable(void)
{
	clk_disable(clk_get("mdss_vsync_clk"));
	clk_disable(clk_get("mdss_mdp_clk"));
	clk_disable(clk_get("mdss_mdp_clk_src"));
	clk_disable(clk_get("mdp_ahb_clk"));

}

void mmss_bus_clock_enable(void)
{
	int ret;
	/* Configure MMSSNOC AXI clock */
	ret = clk_get_set_enable("mmss_mmssnoc_axi_clk", 300000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mmssnoc_axi_clk ret = %d\n", ret);
		ASSERT(0);
	}

	/* Configure S0 AXI clock */
	ret = clk_get_set_enable("mmss_s0_axi_clk", 300000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mmss_s0_axi_clk ret = %d\n", ret);
		ASSERT(0);
	}

	/* Configure AXI clock */
	ret = clk_get_set_enable("mdss_axi_clk", 300000000, 1);
	if(ret)
	{
		dprintf(CRITICAL, "failed to set mdss_axi_clk ret = %d\n", ret);
		ASSERT(0);
	}
}

void mmss_bus_clock_disable(void)
{
	/* Disable MDSS AXI clock */
	clk_disable(clk_get("mdss_axi_clk"));

	/* Disable MMSSNOC S0AXI clock */
	clk_disable(clk_get("mmss_s0_axi_clk"));

	/* Disable MMSSNOC AXI clock */
	clk_disable(clk_get("mmss_mmssnoc_axi_clk"));
}

static void rcg_update_config(uint32_t reg)
{
	int i;

	for (i = 0; i < MAX_LOOPS; i++) {
		if (!(readl(reg) & BIT(0)))
			return;
		udelay(1);
	}

	dprintf(CRITICAL, "failed to update rcg config for reg = 0x%x\n", reg);
	ASSERT(0);
}

static void branch_clk_halt_check(uint32_t reg)
{
	int i;

	for (i = 0; i < MAX_LOOPS; i++) {
		if (!(readl(reg) & BIT(31)))
			return;
		udelay(1);
	}

	dprintf(CRITICAL, "failed to enable branch for reg = 0x%x\n", reg);
	ASSERT(0);
}

void mmss_dsi_clock_enable(uint32_t cfg_rcgr, uint32_t flags,
			uint8_t pclk0_m, uint8_t pclk0_n, uint8_t pclk0_d)
{
	int ret;

	if (flags & MMSS_DSI_CLKS_FLAG_DSI0) {
		/* Enable DSI0 branch clocks */

		/* Set the source for DSI0 byte RCG */
		writel(cfg_rcgr, DSI_BYTE0_CFG_RCGR);
		/* Set the update RCG bit */
		writel(0x1, DSI_BYTE0_CMD_RCGR);
		rcg_update_config(DSI_BYTE0_CMD_RCGR);
		/* Enable the branch clock */
		writel(0x1, DSI_BYTE0_CBCR);
		branch_clk_halt_check(DSI_BYTE0_CBCR);

		/* Set the source for DSI0 pixel RCG */
		writel(cfg_rcgr, DSI_PIXEL0_CFG_RCGR);
		/* Set the MND for DSI0 pixel clock */
		writel(pclk0_m, DSI_PIXEL0_M);
		writel(pclk0_n, DSI_PIXEL0_N);
		writel(pclk0_d, DSI_PIXEL0_D);
		/* Set the update RCG bit */
		writel(0x1, DSI_PIXEL0_CMD_RCGR);
		rcg_update_config(DSI_PIXEL0_CMD_RCGR);
		/* Enable the branch clock */
		writel(0x1, DSI_PIXEL0_CBCR);
		branch_clk_halt_check(DSI_PIXEL0_CBCR);

		ret = clk_get_set_enable("mdss_esc0_clk", 0, 1);
		if(ret)
		{
			dprintf(CRITICAL, "failed to set esc0_clk ret = %d\n", ret);
			ASSERT(0);
		}
	}

	if (flags & MMSS_DSI_CLKS_FLAG_DSI1) {
		/* Enable DSI1 branch clocks */

		/* Set the source for DSI1 byte RCG */
		writel(cfg_rcgr, DSI_BYTE1_CFG_RCGR);
		/* Set the update RCG bit */
		writel(0x1, DSI_BYTE1_CMD_RCGR);
		rcg_update_config(DSI_BYTE1_CMD_RCGR);
		/* Enable the branch clock */
		writel(0x1, DSI_BYTE1_CBCR);
		branch_clk_halt_check(DSI_BYTE1_CBCR);

		/* Set the source for DSI1 pixel RCG */
		writel(cfg_rcgr, DSI_PIXEL1_CFG_RCGR);
		/* Set the MND for DSI1 pixel clock */
		writel(pclk0_m, DSI_PIXEL1_M);
		writel(pclk0_n, DSI_PIXEL1_N);
		writel(pclk0_d, DSI_PIXEL1_D);
		/* Set the update RCG bit */
		writel(0x1, DSI_PIXEL1_CMD_RCGR);
		rcg_update_config(DSI_PIXEL1_CMD_RCGR);
		/* Enable the branch clock */
		writel(0x1, DSI_PIXEL1_CBCR);
		branch_clk_halt_check(DSI_PIXEL1_CBCR);

		ret = clk_get_set_enable("mdss_esc1_clk", 0, 1);
		if(ret)
		{
			dprintf(CRITICAL, "failed to set esc1_clk ret = %d\n", ret);
			ASSERT(0);
		}
	}
}

void mmss_dsi_clock_disable(uint32_t flags)
{
	if (flags & MMSS_DSI_CLKS_FLAG_DSI0) {
		clk_disable(clk_get("mdss_esc0_clk"));
		writel(0x0, DSI_BYTE0_CBCR);
		writel(0x0, DSI_PIXEL0_CBCR);
	}

	if (flags & MMSS_DSI_CLKS_FLAG_DSI1) {
		clk_disable(clk_get("mdss_esc1_clk"));
		writel(0x0, DSI_BYTE1_CBCR);
		writel(0x0, DSI_PIXEL1_CBCR);
	}
}

void hdmi_core_ahb_clk_enable(void)
{
	int ret;

	/* Configure hdmi ahb clock */
	ret = clk_get_set_enable("hdmi_ahb_clk", 0, 1);
	if(ret) {
		dprintf(CRITICAL, "failed to set hdmi_ahb_clk ret = %d\n", ret);
		ASSERT(0);
	}

	/* Configure hdmi core clock */
	ret = clk_get_set_enable("hdmi_core_clk", 19200000, 1);
	if(ret) {
		dprintf(CRITICAL, "failed to set hdmi_core_clk ret = %d\n", ret);
		ASSERT(0);
	}
}

void hdmi_pixel_clk_enable(uint32_t rate)
{
	int ret;

	/* Configure hdmi pixel clock */
	ret = clk_get_set_enable("hdmi_extp_clk", rate, 1);
	if(ret) {
		dprintf(CRITICAL, "failed to set hdmi_extp_clk ret = %d\n", ret);
		ASSERT(0);
	}
}

void hdmi_pixel_clk_disable(void)
{
	clk_disable(clk_get("hdmi_extp_clk"));
}

void hdmi_core_ahb_clk_disable(void)
{
	clk_disable(clk_get("hdmi_core_clk"));
	clk_disable(clk_get("hdmi_ahb_clk"));
}
