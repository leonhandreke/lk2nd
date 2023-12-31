/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __PLATFORM_DEBUG_H
#define __PLATFORM_DEBUG_H

#include <sys/types.h>
#include <stdarg.h>
#include <compiler.h>
#include <scm.h>

#if defined(__cplusplus)
extern "C" {
#endif

void debug_init(void);
unsigned log_copy(void *dst);

void debug_dump_regs(void);

void debug_dump_memory_bytes(void *mem, int len);
void debug_dump_memory_halfwords(void *mem, int len);
void debug_dump_memory_words(void *mem, int len);

void debug_set_trace_level(int trace_type, int level);

void platform_halt(void);

#if defined(__cplusplus)
}
#endif


#endif

