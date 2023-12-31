/* SPDX-License-Identifier: BSD-3-Clause */
#ifndef ABOOT_BOOT_H
#define ABOOT_BOOT_H

#include <bits.h>

enum boot_type {
	BOOT_ARM64	= BIT(0),
	BOOT_ANDROID	= BIT(1),
	BOOT_DOWNSTREAM	= BIT(2),
	BOOT_LK2ND	= IS_ENABLED(WITH_LK2ND) ? BIT(3) : 0,
	BOOT_ATAGS_COPY	= IS_ENABLED(WITH_LK2ND_DEVICE_2ND) ? BIT(4) : 0,
};

unsigned char *update_cmdline(const char *cmdline);

#if DEVICE_TREE
struct dt_update_handler {
	const char *name;
	int (*update_dt)(void *fdt, const char *cmdline, enum boot_type type);
};
#define DEV_TREE_UPDATE(func) \
	static const struct dt_update_handler _dt_update_##func \
		__SECTION(".dt_update") __USED = { #func, (func) }
#else
#define DEV_TREE_UPDATE(func)
#endif

#endif /* ABOOT_BOOT_H */
