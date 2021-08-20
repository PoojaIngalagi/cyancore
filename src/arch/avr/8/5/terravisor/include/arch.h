/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: arch.h
 * Description		: This file prototypes arch related functions and
 *			  defines inline-able arch functions.
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#pragma once
#define _ARCH_H_

#include <plat_arch.h>
#include <mmio.h>

/**
 * arch_early_setup - This needs to be called in early stages of boot
 */
void arch_early_setup();

/**
 * arch_setup - This needs to be called after inital setup is completed
 */
void arch_setup();

/**
 * arch_wfi - Wait for interrupt, with sleep mode
 */
void arch_wfi();

/**
 * arch_panic_handler - Executes when arch error occurs
 */
void arch_panic_handler();

#ifdef _MACHINE_CALL_H_
/**
 * arch_machine_call - Performs machine call
 *
 * Refer arch.c for more details.
 */
mret_t arch_machine_call(unsigned  int, unsigned int, unsigned  int, unsigned  int);
#endif

/**
 * arch_register_interrupt_handler - Registers interrtup handler
 * for arch specific interrupt vectors
 */
void arch_register_interrupt_handler(unsigned int, void (*)(void));

/**
 * arch_core_id - Returns code id (0, in case of AVR)
 */
static inline unsigned int arch_core_id()
{
	/* AVR only support uni core architecture */
	return 0;
}

/**
 * arch_ei - arch enable global interrupts
 */
static inline void arch_ei()
{
	asm volatile("sei");
}

/**
 * arch_di - arch disable global interrupts
 */
static inline void arch_di()
{
	asm volatile("cli");
}

/**
 * arch_wdt_reset - Reset watchdog timer
 */
static inline void arch_wdt_reset()
{
	asm volatile("wdr");
}

typedef struct arch_gpr
{
	uint8_t r0, r1, r2, r3, r4, r5, r6, r7,
		r8, r9, r10, r11, r12, r13, r14, r15,
		r16, r17, r18, r19, r20, r21, r22, r23,
		r24, r25, r26, r27, r28, r29, r30, r31;
} arch_gpr_t;


/**
 * arch_grp_readout - Get the values of general purpose registers
 *
 * @return - Struct pointer for registers on stack
 */
arch_gpr_t *arch_gpr_readout();
