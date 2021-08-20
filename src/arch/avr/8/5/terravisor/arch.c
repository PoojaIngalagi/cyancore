/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: arch.c
 * Description		: This file consists of architecture specific function that
 *			  cannot be inlined. Hence, present in c file.
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <stdint.h>
#include <string.h>
#include <status.h>
#include <machine_call.h>
#include <plat_arch.h>
#include <mmio.h>
#include <arch.h>

/**
 * arch_early_setup - This function is called in the early stages of boot
 *
 * @brief This function is responsible to clean reset cpu status/control registers.
 *
 */
void arch_early_setup()
{
	arch_di();
	MMIO8(MCUCR) = 0;
	MMIO8(SMCR) = 0;
	MMIO8(WDTCSR) = 0;
	return;
}

/**
 * arch_setup - This function is called after initial setup is done
 *
 * @brief This function is called after initial setup is done.
 */
void arch_setup()
{
	return;
}

/**
 * arch_wfi - wait for interrupt
 *
 * @brief This function should be called when the program needs to
 * wait for interrupt. This also ensures in lower power consumption
 * when compared to busy wait.
 */
void arch_wfi()
{
	/*
	 * For interruptable sleep
	 * Enable Idle mode
	 */
	MMIO8(SMCR) = 0x01;
	arch_ei();
	asm volatile("sleep");
}

/**
 * *mcall - pointer to machine call function
 *
 * @brief This function pointer emulates 'mcall' instruction in risc-v.
 * This method is intentionally created for this framework so
 * as to maintain consistency across all the cpu architectures.
 *
 * @param[in] code: machine call code
 * @param[in] a0: first argument
 * @param[in] a1: second argument
 * @param[in] a2: third argument
 * @param[out] ret: pointer to return of machine call.
 */
void (*mcall)(unsigned int, unsigned int, unsigned int, unsigned int, mret_t *);

/**
 * arch_machine_call - perform machine call
 *
 * @brief This function executes function pointed by mcall. As the
 * AVR core doesn't support multiple execution levels, this
 * function emulates the machine call to maintain consistency.
 *
 * @param[in] code: machine call code
 * @param[in] a0: first argument
 * @param[in] a1: second argument
 * @param[in] a2: third argument
 * @return status: returns struct which is result of machine call operation
 */
mret_t arch_machine_call(unsigned int code, unsigned int a0, unsigned int a1, unsigned int a2)
{
	mret_t ret;
	mcall(code, a0, a1, a2, &ret);
	return ret;
}

#define push(x)		asm volatile("push " #x)

/* Fixed memory block of 32 bytes on bss */
static uint8_t arch_gpr_mem[32];

/**
 * arch_grp_readout - Get the values of general purpose registers
 *
 * @return - Struct pointer for registers on stack
 */
arch_gpr_t *arch_gpr_readout()
{
	uint16_t sp;
	/*
	 * Save on stack first.
	 * This prevents from registers getting modified.
	 */
	push(r31); push(r30); push(r29);
	push(r28); push(r27); push(r26);
	push(r25); push(r24); push(r23);
	push(r22); push(r21); push(r20);
	push(r19); push(r18); push(r17);
	push(r16); push(r15); push(r14);
	push(r13); push(r12); push(r11);
	push(r10); push(r9); push(r8);
	push(r7); push(r6); push(r5);
	push(r4); push(r3); push(r2);
	push(r1); push(r0);

	/* Store current Stack pointer */
	sp = (uint16_t)(MMIO8(SPL));
	sp |= (uint16_t)(MMIO8(SPH) << 8);

	/*
	 * Copy Stack content to arch_grp_mem to preserve
	 * the content after context switch of function
	 *
	 * Also SP+1 is done as stack pointer pre-decrements
	 */
	memcpy((void *)arch_gpr_mem, (void *)(sp+1), 32);

	/* Set SP to original value when called by the function */
	sp += 32;
	/* Restore SP */
	MMIO8(SPL) = (uint8_t)(sp & 0xff);
	MMIO8(SPH) = (uint8_t)((sp & 0xff00) >> 8);

	/* Return the memory block */
	return (arch_gpr_t *)arch_gpr_mem;
}

#undef push
