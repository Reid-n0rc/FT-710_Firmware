/*
 * FT-710 DISPLAY (T24 round 4): context switch of the NORTi stand-in (rtos/norti.c), A32.
 *
 * A task's saved context is the callee-saved registers r4..r11 and lr on its own stack (AAPCS: the caller of
 * norti_switch keeps r0..r3 and ip itself); the stack pointer is kept in the task's control block. No VFP state:
 * the DISPLAY program is soft-float (src/display/Makefile).
 */
        .syntax unified
        .arm

/* void norti_switch(uint32_t **save, uint32_t *next): save the running context's SP in *save, continue next */
        .section .text.norti_switch,"ax",%progbits
        .global norti_switch
        .type norti_switch, %function
        .p2align 2
norti_switch:
        push {r4-r11, lr}
        str sp, [r0]
        mov sp, r1
        pop {r4-r11, pc}
        .size norti_switch, . - norti_switch

/* uint32_t *norti_stack_init(uint32_t *top, void (*entry)(void)): a first context that "returns" into entry with
 * zeroed r4..r11 and an 8-byte aligned stack */
        .section .text.norti_stack_init,"ax",%progbits
        .global norti_stack_init
        .type norti_stack_init, %function
        .p2align 2
norti_stack_init:
        bic r0, r0, #7
        str r1, [r0, #-4]!
        mov r2, #0
        mov r3, #8
1:      str r2, [r0, #-4]!
        subs r3, r3, #1
        bne 1b
        bx lr                           @ the pop of the 9 words leaves sp at the aligned top
        .size norti_stack_init, . - norti_stack_init
