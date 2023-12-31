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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <debug.h>
#include <reg.h>
#include <platform/iomap.h>
#include <qgic.h>
#include <qtimer.h>
#include <platform/clock.h>
#include <mmu.h>
#include <arch/arm/mmu.h>
#include <smem.h>
#include <board.h>

#define MSM_IOMAP_SIZE ((MSM_IOMAP_END - MSM_IOMAP_BASE)/MB)

#define HLOS_MEMORY_START 0x0
#define HLOS_MEMORY_SIZE  0x63

/* LK memory - cacheable, write back */
#define LK_MEMORY         (MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | \
                           MMU_MEMORY_AP_READ_WRITE)

/* Peripherals - non-shared device */
#define IOMAP_MEMORY      (MMU_MEMORY_TYPE_DEVICE_SHARED | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

/* IMEM memory - cacheable, write through */
#define COMMON_MEMORY       (MMU_MEMORY_TYPE_NORMAL_WRITE_THROUGH | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

/* Scratch memory - cacheable, write back */
#define SCRATCH_MEMORY       (MMU_MEMORY_TYPE_NORMAL_WRITE_BACK_ALLOCATE | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)


static mmu_section_t mmu_section_table[] = {
/*       Physical addr,     Virtual addr,      Size (in MB),        Flags */
	{    MEMBASE,           MEMBASE,           (MEMSIZE / MB),      LK_MEMORY},
	{    MSM_IOMAP_BASE,    MSM_IOMAP_BASE,    MSM_IOMAP_SIZE,      IOMAP_MEMORY},
	{    SYSTEM_IMEM_BASE,  SYSTEM_IMEM_BASE,  1,                   COMMON_MEMORY},
	{    MSM_SHARED_BASE,   MSM_SHARED_BASE,   2,                   COMMON_MEMORY},
	{    HLOS_MEMORY_START, HLOS_MEMORY_START, HLOS_MEMORY_SIZE,    COMMON_MEMORY},
	{    SCRATCH_ADDR,      SCRATCH_ADDR,      (SCRATCH_SIZE / MB), SCRATCH_MEMORY},
	{    RPMB_SND_RCV_BUF,  RPMB_SND_RCV_BUF,  RPMB_SND_RCV_BUF_SZ,    IOMAP_MEMORY},
};

void platform_early_init(void)
{
	board_init();
	platform_clock_init();
	qgic_init();
	qtimer_init();
	scm_init();
}

void platform_init(void)
{
	dprintf(INFO, "platform_init()\n");
#if ENABLE_XPU_VIOLATION
	scm_xpu_err_fatal_init();
#endif
}

void platform_uninit(void)
{
#if DISPLAY_SPLASH_SCREEN
	display_shutdown();
#endif

	qtimer_uninit();
}

int platform_use_identity_mmu_mappings(void)
{
	/* Use only the mappings specified in this file. */
	return 0;
}

/* Setup memory for this platform */
void platform_init_mmu_mappings(void)
{
	uint32_t i;
	uint32_t sections;
	uint32_t table_size = ARRAY_SIZE(mmu_section_table);

	/* Configure the MMU page entries for memory read from the
	   mmu_section_table */
	for (i = 0; i < table_size; i++)
	{
		sections = mmu_section_table[i].num_of_sections;

		while (sections--)
		{
			arm_mmu_map_section(mmu_section_table[i].paddress +
								sections * MB,
								mmu_section_table[i].vaddress +
								sections * MB,
								mmu_section_table[i].flags);
		}
	}
}

addr_t platform_get_virt_to_phys_mapping(addr_t virt_addr)
{
	/* Using 1-1 mapping on this platform. */
	return virt_addr;
}

addr_t platform_get_phys_to_virt_mapping(addr_t phys_addr)
{
	/* Using 1-1 mapping on this platform. */
	return phys_addr;
}

uint32_t platform_get_sclk_count(void)
{
	return readl(MPM2_MPM_SLEEP_TIMETICK_COUNT_VAL);
}

int platform_is_msm8994(void)
{
	uint32_t platform = board_platform_id();
	if ((platform == APQ8094) || (platform == MSM8994))
		return 1;
	else
		return 0;
}

int platform_is_msm8992(void)
{
	int ret;

	uint32_t platform = board_platform_id();
	switch (platform) {
	case MSM8992:
	case APQ8092:
		ret = 1;
		break;
	default:
		ret = 0;
	}

	return ret;
}

addr_t get_bs_info_addr(void)
{
	if (platform_is_msm8994())
		return ((addr_t)BS_INFO_ADDR);
	else
		return ((addr_t)BS_INFO_ADDR2);
}
