/*
 * Copyright (c) 2008, Google Inc.
 * All rights reserved.
 * Copyright (c) 2009-2013, The Linux Foundation. All rights reserved.
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
 *  * Neither the name of Google, Inc. nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
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

#include <debug.h>
#include <reg.h>

#include <kernel/thread.h>
#include <platform/debug.h>
#include <platform/iomap.h>
#include <platform/timer.h>
#include <qgic.h>
#include <i2c_qup.h>
#include <gsbi.h>
#include <uart_dm.h>
#include <mmu.h>
#include <arch/arm/mmu.h>
#include <board.h>
#include <target.h>

static uint32_t ticks_per_sec = 0;

/* LK memory - cacheable, write through */
#define LK_MEMORY         (MMU_MEMORY_TYPE_NORMAL_WRITE_THROUGH | \
                           MMU_MEMORY_AP_READ_WRITE)

/* Kernel region - cacheable, write through */
#define KERNEL_MEMORY     (MMU_MEMORY_TYPE_NORMAL_WRITE_THROUGH   | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

/* Scratch region - cacheable, write through */
#define SCRATCH_MEMORY    (MMU_MEMORY_TYPE_NORMAL_WRITE_THROUGH   | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

/* Peripherals - non-shared device */
#define IOMAP_MEMORY      (MMU_MEMORY_TYPE_DEVICE_NON_SHARED | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

/* IMEM: Must set execute never bit to avoid instruction prefetch from TZ */
#define IMEM_MEMORY       (MMU_MEMORY_TYPE_STRONGLY_ORDERED | \
                           MMU_MEMORY_AP_READ_WRITE | MMU_MEMORY_XN)

#define MSM_IOMAP_SIZE ((MSM_IOMAP_END - MSM_IOMAP_BASE)/MB)

mmu_section_t mmu_section_table[] = {
/*  Physical addr,    Virtual addr,    Size (in MB),   Flags */
	{MEMBASE, MEMBASE, (MEMSIZE / MB), LK_MEMORY},
	{BASE_ADDR, BASE_ADDR, 44, KERNEL_MEMORY},
	{SCRATCH_ADDR, SCRATCH_ADDR, 384, SCRATCH_MEMORY},
	{MSM_IOMAP_BASE, MSM_IOMAP_BASE, MSM_IOMAP_SIZE, IOMAP_MEMORY},
	{MSM_IMEM_BASE, MSM_IMEM_BASE, 1, IMEM_MEMORY},
	{MSM_SHARED_BASE, MSM_SHARED_BASE, 1, KERNEL_MEMORY},
};

#define CONVERT_ENDIAN_U32(val)                   \
    ((((uint32_t)(val) & 0x000000FF) << 24) |     \
     (((uint32_t)(val) & 0x0000FF00) << 8)  |     \
     (((uint32_t)(val) & 0x00FF0000) >> 8)  |     \
     (((uint32_t)(val) & 0xFF000000) >> 24))

#define CONVERT_ENDIAN_U16(val)              \
    ((((uint16_t)(val) & 0x00FF) << 8) |     \
     (((uint16_t)(val) & 0xFF00) >> 8))

/* Configuration Data Table */
#define CDT_MAGIC_NUMBER    0x43445400
struct cdt_header {
	uint32_t magic;		/* Magic number */
	uint16_t version;	/* Version number */
	uint32_t reserved1;
	uint32_t reserved2;
} __attribute__ ((packed));

void platform_init_timer(void);

/* CRCI - mmc slot mapping.
 * mmc slot numbering start from 1.
 * entry at index 0 is just dummy.
 */
uint8_t sdc_crci_map[5] = { 0, 1, 4, 2, 5 };

void platform_early_init(void)
{
	uint8_t gsbi_id = target_uart_gsbi();
	uart_dm_init(gsbi_id, GSBI_BASE(gsbi_id), GSBI_UART_DM_BASE(gsbi_id));
	qgic_init();
	platform_init_timer();
	board_init();
}

void platform_init(void)
{
	dprintf(INFO, "platform_init()\n");
}

static struct qup_i2c_dev *dev = NULL;

uint32_t eprom_read(uint16_t addr, uint8_t count)
{
	uint32_t ret = 0;
	if (!dev) {
		return ret;
	}
	/* Create a i2c_msg buffer, that is used to put the controller into
	 * read mode and then to read some data.
	 */
	struct i2c_msg msg_buf[] = {
		{EEPROM_I2C_ADDRESS, I2C_M_WR, 2, (void *)&addr},
		{EEPROM_I2C_ADDRESS, I2C_M_RD, count, (void *)&ret}
	};

	qup_i2c_xfer(dev, msg_buf, 2);
	return ret;
}

/* Read EEPROM to find out product id. Return 0 in case of failure */
uint32_t platform_id_read(void)
{
	uint32_t id = 0;
	uint16_t offset = 0;
	dev = qup_i2c_init(GSBI_ID_8, 100000, 24000000);
	if (!dev) {
		return id;
	}
	/* Check if EPROM is valid */
	if (CONVERT_ENDIAN_U32(eprom_read(0, 4)) == CDT_MAGIC_NUMBER) {
		/* Get offset for platform ID info from Meta Data block 0 */
		offset = eprom_read(CONVERT_ENDIAN_U16(0 +
						       sizeof(struct
							      cdt_header)), 2);
		/* Read platform ID */
		id = eprom_read(CONVERT_ENDIAN_U16(offset), 4);
		id = CONVERT_ENDIAN_U32(id);
		id = (id & 0x00FF0000) >> 16;
	}
	return id;
}

int platform_use_identity_mmu_mappings(void)
{
	/* Use only the mappings specified in this file. */
	return 0;
}

addr_t platform_get_virt_to_phys_mapping(addr_t virt_addr)
{
	/* Return same address as we are using 1-1 mapping. */
	return virt_addr;
}

addr_t platform_get_phys_to_virt_mapping(addr_t phys_addr)
{
	/* Return same address as we are using 1-1 mapping. */
	return phys_addr;
}

/* Setup memory for this platform */
void platform_init_mmu_mappings(void)
{
	uint32_t i;
	uint32_t sections;
	uint32_t table_size = ARRAY_SIZE(mmu_section_table);

	for (i = 0; i < table_size; i++) {
		sections = mmu_section_table[i].num_of_sections;

		while (sections--) {
			arm_mmu_map_section(mmu_section_table[i].paddress +
					    sections * MB,
					    mmu_section_table[i].vaddress +
					    sections * MB,
					    mmu_section_table[i].flags);
		}
	}
}

/* Do any platform specific cleanup just before kernel entry */
void platform_uninit(void)
{
	/* As a effect of enabling caches, display gets shutdown even before
	 * the splash screen shows up. Until we can speed up the splash screen
	 * display, add an artificial delay so that current user experience
	 * is not affected.
	 */
	mdelay(400);

#if DISPLAY_SPLASH_SCREEN
	display_shutdown();
#endif

	platform_uninit_timer();
}

/* Initialize DGT timer */
void platform_init_timer(void)
{
	/* disable timer */
	writel(0, DGT_ENABLE);

	/* DGT uses LPXO source which is 27MHz.
	 * Set clock divider to 4.
	 */
	writel(3, DGT_CLK_CTL);

	ticks_per_sec = 6750000;	/* (27 MHz / 4) */
}

/* Returns timer ticks per sec */
uint32_t platform_tick_rate(void)
{
	return ticks_per_sec;
}
