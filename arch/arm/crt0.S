/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
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

#define DSB .byte 0x4f, 0xf0, 0x7f, 0xf5
#define ISB .byte 0x6f, 0xf0, 0x7f, 0xf5

.section ".text.boot"
.globl _start
_start:
	b	reset
	b	arm_undefined
	b	arm_syscall
	b	arm_prefetch_abort
	b	arm_data_abort
	b	arm_reserved
	b	arm_irq
	b	arm_fiq

reset:
	b	1f
	/* Some magic used by 32-bit Linux */
	.word	0x016f2818
	/*
	 * Technically supposed to be the start address but Linux has it 0
	 * and most bootloaders expect it to be like that.
	 * (Especially for the end address after it which is used as a size...)
	 */
	.word	0
	.word	(__data_end - _start)
1:
	/* Save boot args and address */
	adr	r6, _start
	adr	r7, lk_boot_args
	stm	r7, {r0-r3, r6}

#ifdef ENABLE_TRUSTZONE
	/*Add reference to TZ symbol so linker includes it in final image */
	ldr r7, =_binary_tzbsp_tzbsp_bin_start
#endif
	/* do some cpu setup */
#if ARM_WITH_CP15
        /* Read SCTLR */
	mrc		p15, 0, r0, c1, c0, 0
		/* XXX this is currently for arm926, revist with armv6 cores */
		/* new thumb behavior, low exception vectors, i/d cache disable, mmu disabled */
	bic		r0, r0, #(1<<15| 1<<13 | 1<<12)
	bic		r0, r0, #(1<<2 | 1<<0)
		/* disable alignment faults */
	bic		r0, r0, #(1<<1)
	/* Enable CP15 barriers by default */
#ifdef ARM_CORE_V8
	orr		r0, r0, #(1<<5)
#endif
        /* Write SCTLR */
	mcr		p15, 0, r0, c1, c0, 0
#ifdef ENABLE_TRUSTZONE
  /*nkazi: not needed ? Setting VBAR to location of new vector table : 0x80000      */
 ldr             r0, =0x00080000
 mcr             p15, 0, r0, c12, c0, 0
#endif
#endif

#if WITH_CPU_EARLY_INIT
	/* call platform/arch/etc specific init code */
#ifndef ENABLE_TRUSTZONE
	/* Not needed when TrustZone is the first bootloader that runs.*/
	bl __cpu_early_init
#endif
	/* declare return address as global to avoid using stack */
.globl _cpu_early_init_complete
	_cpu_early_init_complete:

#endif

#if (!ENABLE_NANDWRITE)
#if WITH_CPU_WARM_BOOT
	ldr 	r0, warm_boot_tag
	cmp 	r0, #1

	/* if set, warm boot */
	ldreq 	pc, =BASE_ADDR

	mov 	r0, #1
	str	r0, warm_boot_tag
#endif
#endif

	/* see if we need to relocate */
	mov		r0, pc
	sub		r0, r0, #(.Laddr - _start)
.Laddr:
	ldr		r1, =_start
	cmp		r0, r1
	beq		.Lstack_setup

	/* we need to relocate ourselves to the proper spot */
	ldr		r2, =__data_end	

.Lrelocate_loop:
	ldr		r3, [r0], #4
	str		r3, [r1], #4
	cmp		r1, r2
	bne		.Lrelocate_loop

	/* we're relocated, jump to the right address */
	ldr		r0, =.Lstack_setup
	bx		r0

.ltorg

.global lk_boot_args
.global lk_boot_addr
lk_boot_args:
	.word	0, 0, 0, 0
lk_boot_addr:
	.word	0

#if WITH_CPU_WARM_BOOT
warm_boot_tag:
	.word 0
#endif

.Lstack_setup:
	/* set up the stack for irq, fiq, abort, undefined, system/user, and lastly supervisor mode */
	mrs     r0, cpsr
	bic     r0, r0, #0x1f

	ldr		r2, =abort_stack_top
	orr     r1, r0, #0x12 // irq
	msr     cpsr_c, r1
	ldr		r13, =irq_save_spot		/* save a pointer to a temporary dumping spot used during irq delivery */
	    
	orr     r1, r0, #0x11 // fiq
	msr     cpsr_c, r1
	mov		sp, r2
	            
	orr     r1, r0, #0x17 // abort
	msr     cpsr_c, r1
	mov		sp, r2
	    
	orr     r1, r0, #0x1b // undefined
	msr     cpsr_c, r1
	mov		sp, r2
	    
	orr     r1, r0, #0x1f // system
	msr     cpsr_c, r1
	mov		sp, r2

	orr		r1, r0, #0x13 // supervisor
	msr		cpsr_c, r1
	mov		sp, r2

	/* copy the initialized data segment out of rom if necessary */
	ldr		r0, =__data_start_rom
	ldr		r1, =__data_start
	ldr		r2, =__data_end

	cmp		r0, r1
	beq		.L__do_bss

.L__copy_loop:
	cmp		r1, r2
	ldrlt	r3, [r0], #4
	strlt	r3, [r1], #4
	blt		.L__copy_loop

.L__do_bss:
	/* clear out the bss */
	ldr		r0, =__bss_start
	ldr		r1, =_end
	mov		r2, #0
.L__bss_loop:
	cmp		r0, r1
	strlt	r2, [r0], #4
	blt		.L__bss_loop

#ifdef ARM_CPU_CORTEX_A8
	DSB
	ISB
#endif

	bl		kmain
	b		.

.ltorg

.bss
.align 2
	/* the abort stack is for unrecoverable errors.
	 * also note the initial working stack is set to here.
	 * when the threading system starts up it'll switch to a new 
	 * dynamically allocated stack, so we don't need it for very long
	 */
abort_stack:
	.skip 4096
abort_stack_top:
