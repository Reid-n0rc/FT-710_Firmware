/*
 * FT-710 DISPLAY (T24 round 4): exception vectors, reset and the exception entries, 0x20100000..0x20100267
 * (hand-written A32 assembly; docs/code/display/boot-rtos.md section 1).
 *
 * The instructions are the image's, in its order, with labels named after their original address; the range is one
 * section and each function in it is byte-identical to the image at its original address
 * (tools/equiv_display_emu.py, verdict "identical"). What it does [fact: the code]:
 *  - vectors: eight branches; 0x20100028 holds the initial SP 0x2044C000.
 *  - Reset_Handler: SVC mode, IRQ/FIQ masked; cache and MMU off (dcache_invalidate_range, mmu_disable),
 *    cpg_early_init; if not running at its link address (XIP from the SPI flash window), copies the start-up part
 *    (0x20100000..0x20100BBF) to RAM and continues there in reset_in_ram.
 *  - reset_in_ram: spibsc0_init, boot_select_bank (the loader role), then copies the rest of the image in 32-byte
 *    blocks up to 0x2043FFFF (beyond the end of the file, 0x2042BC0F: the gap is loaded too), builds the flat L1 table,
 *    marks 0x20100000/4 MB and 0x20800000/2 MB cacheable, turns the MMU on, sets VBAR, clears SCTLR.V, sets the
 *    FIQ/ABT/UND/IRQ/SYS stacks (IRQ = SP - 0x40, SYS = IRQ - 0x240) and branches to __main in SYS mode.
 *  - SVC_Handler: reads the SVC number from the instruction (A32 or Thumb); svc #0 jumps to r0 in SVC mode (the
 *    kernel's IRQ exit uses it), any other number returns.
 *  - IRQ_Handler: returns at once if the interrupted code had IRQs masked; otherwise knl_irq_enter (task or nested),
 *    gic_dispatch (returns the handler), calls it, and leaves through svc #0 into knl_irq_exit + 8.
 *  - FIQ, undefined instruction, prefetch and data abort: endless loops.
 */
        .syntax unified
        .cpu cortex-a9
        .arm

        .section .text.vectors,"ax",%progbits
        .p2align 2
        .global vec_reset
        .type vec_reset, %function
vec_reset:                              @ 0x20100000
        b Reset_Handler    @ 20100000
        b Undef_Handler    @ 20100004
        b SVC_Handler    @ 20100008
        b PAbort_Handler    @ 2010000c
        b DAbort_Handler    @ 20100010
        nop    @ 20100014
        b IRQ_Handler    @ 20100018
        b FIQ_Handler    @ 2010001c
        nop    @ 20100020
        nop    @ 20100024
L_20100028:
        .word 0x2044c000    @ 20100028: initial SP of every mode before the per-mode set-up (top of ram_stack)
        .size vec_reset, . - vec_reset

        .global Reset_Handler
        .type Reset_Handler, %function
Reset_Handler:                          @ 0x2010002C
        mov r0, #0xd3    @ 2010002c
        msr cpsr_c, r0    @ 20100030
        ldr sp, L_20100028    @ 20100034
        mov r0, #0    @ 20100038
        bl dcache_invalidate_range    @ 2010003c
        bl mmu_disable    @ 20100040
        bl cpg_early_init    @ 20100044
        mov r4, pc    @ 20100048
        nop    @ 2010004c
        ldr r0, L_20100230    @ 20100050
        subs r0, r0, r4    @ 20100054
        beq L_201000e4    @ 20100058
        ldr r2, L_20100234    @ 2010005c
        ldr r3, L_20100238    @ 20100060
        sub r1, r2, r0    @ 20100064
L_20100068:
        ldm r1!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 20100068
        stm r2!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 2010006c
        cmp r2, r3    @ 20100070
        blt L_20100068    @ 20100074
        ldr lr, L_2010023c    @ 20100078
        bx lr    @ 2010007c
        .size Reset_Handler, . - Reset_Handler

        .global reset_in_ram
        .type reset_in_ram, %function
reset_in_ram:                           @ 0x20100080
        push {r0, r1, r2, r3}    @ 20100080
        bl spibsc0_init    @ 20100084
        pop {r0, r1, r2, r3}    @ 20100088
        push {r0, r1, r2, r3}    @ 2010008c
        bl boot_select_bank    @ 20100090
        pop {r0, r1, r2, r3}    @ 20100094
        ldr r3, L_20100240    @ 20100098
L_2010009c:
        ldm r1!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 2010009c
        stm r2!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 201000a0
        cmp r2, r3    @ 201000a4
        blt L_2010009c    @ 201000a8
        ldr r2, L_20100244    @ 201000ac
        ldr r3, L_20100248    @ 201000b0
        sub r1, r2, r0    @ 201000b4
L_201000b8:
        ldm r1!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 201000b8
        stm r2!, {r4, r5, r6, r7, r8, sb, sl, fp}    @ 201000bc
        cmp r2, r3    @ 201000c0
        blt L_201000b8    @ 201000c4
        b L_201000e0    @ 201000c8
        andeq r0, r0, r0    @ 201000cc
        andeq r0, r0, r0    @ 201000d0
        andeq r0, r0, r0    @ 201000d4
        andeq r0, r0, r0    @ 201000d8
        andeq r0, r0, r0    @ 201000dc
L_201000e0:
        nop    @ 201000e0
L_201000e4:
        bl mmu_l1_table_init    @ 201000e4
        ldr r0, L_2010024c    @ 201000e8
        mov r1, #0x400000    @ 201000ec
        bl mmu_set_cacheable    @ 201000f0
        mov r0, #0x20800000    @ 201000f4
        mov r1, #0x200000    @ 201000f8
        bl mmu_set_cacheable    @ 201000fc
        b L_20100128    @ 20100100
        mov r0, #0x60000000    @ 20100104
        mov r1, #0x300000    @ 20100108
        bl mmu_set_cacheable    @ 2010010c
        ldr r0, L_20100250    @ 20100110
        mov r1, #0x100000    @ 20100114
        bl mmu_set_cacheable    @ 20100118
        ldr r0, L_20100254    @ 2010011c
        mov r1, #0x100000    @ 20100120
        bl mmu_set_cacheable    @ 20100124
L_20100128:
        bl mmu_enable    @ 20100128
        ldr r0, L_20100258    @ 2010012c
        mcr p15, #0, r0, c12, c0, #0    @ 20100130
        mrc p15, #0, r0, c1, c0, #0    @ 20100134
        bic r0, r0, #0x2000    @ 20100138
        mcr p15, #0, r0, c1, c0, #0    @ 2010013c
        mov r0, #0xd1    @ 20100140
        msr cpsr_c, r0    @ 20100144
        ldr sp, L_20100028    @ 20100148
        mov r0, #0xd7    @ 2010014c
        msr cpsr_c, r0    @ 20100150
        ldr sp, L_20100028    @ 20100154
        mov r0, #0xdb    @ 20100158
        msr cpsr_c, r0    @ 2010015c
        ldr sp, L_20100028    @ 20100160
        mov r3, #0x40    @ 20100164
        sub r2, sp, r3    @ 20100168
        mov r0, #0xd2    @ 2010016c
        msr cpsr_c, r0    @ 20100170
        mov sp, r2    @ 20100174
        mov r3, #0x240    @ 20100178
        sub r2, sp, r3    @ 2010017c
        mov r0, #0xdf    @ 20100180
        msr cpsr_c, r0    @ 20100184
        mov sp, r2    @ 20100188
        b __main    @ 2010018c
L_20100190:
        b L_20100190    @ 20100190
        .size reset_in_ram, . - reset_in_ram

        .global SVC_Handler
        .type SVC_Handler, %function
SVC_Handler:                            @ 0x20100194
        push {ip, lr}    @ 20100194
        mrs lr, spsr    @ 20100198
        push {ip, lr}    @ 2010019c
        tst lr, #0x20    @ 201001a0
        ldr lr, [sp, #0xc]    @ 201001a4
        ldrhne lr, [lr, #-2]    @ 201001a8
        bicne lr, lr, #0xff00    @ 201001ac
        ldreq lr, [lr, #-4]    @ 201001b0
        biceq lr, lr, #0xff000000    @ 201001b4
        teq lr, #0    @ 201001b8
        bne L_201001c4    @ 201001bc
        bx r0    @ 201001c0
L_201001c4:
        push {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip}    @ 201001c4
        pop {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip}    @ 201001c8
        pop {ip, lr}    @ 201001cc
        msr spsr_fsxc, lr    @ 201001d0
        ldm sp!, {ip, pc} ^    @ 201001d4
        .size SVC_Handler, . - SVC_Handler

        .global IRQ_Handler
        .type IRQ_Handler, %function
IRQ_Handler:                            @ 0x201001D8
        sub lr, lr, #4    @ 201001d8
        push {ip, lr}    @ 201001dc
        mrs lr, spsr    @ 201001e0
        tst lr, #0x80    @ 201001e4
        ldmne sp!, {ip, pc} ^    @ 201001e8
        push {r0, r1, r2, r3, ip, lr}    @ 201001ec
        ldr ip, L_2010025c    @ 201001f0
        blx ip    @ 201001f4
        cmp r0, #0    @ 201001f8
        popeq {r0, r1, r2, r3, ip, lr}    @ 201001fc
        msreq spsr_fsxc, lr    @ 20100200
        ldmeq sp!, {ip, pc} ^    @ 20100204
        ldr ip, L_20100260    @ 20100208
        blx ip    @ 2010020c
        blx r0    @ 20100210
        ldr r0, L_20100264    @ 20100214
        svc #0    @ 20100218
        .size IRQ_Handler, . - IRQ_Handler

        .global FIQ_Handler
        .type FIQ_Handler, %function
FIQ_Handler:                            @ 0x2010021C
        b FIQ_Handler    @ 2010021c
        .size FIQ_Handler, . - FIQ_Handler

        .global Undef_Handler
        .type Undef_Handler, %function
Undef_Handler:                          @ 0x20100220
        b Undef_Handler    @ 20100220
        .size Undef_Handler, . - Undef_Handler

        .global PAbort_Handler
        .type PAbort_Handler, %function
PAbort_Handler:                         @ 0x20100224
        b PAbort_Handler    @ 20100224
        .size PAbort_Handler, . - PAbort_Handler

        .global DAbort_Handler
        .type DAbort_Handler, %function
DAbort_Handler:                         @ 0x20100228
        b DAbort_Handler    @ 20100228
        .word 0x20980000    @ 2010022c: NORTi kernel pool base, read by kernel_heap_init (docs/memory-maps.md, ram_hi)
L_20100230:
        .word 0x20100050    @ 20100230: link address of the "mov r4, pc" + 8: 0 when running where linked
L_20100234:
        .word 0x20100000    @ 20100234: first copy: destination start (image base)
L_20100238:
        .word 0x20100bc0    @ 20100238: first copy: end (the start-up part, up to __main)
L_2010023c:
        .word reset_in_ram    @ 2010023c
L_20100240:
        .word 0x2042883f    @ 20100240: second copy: end (continues the first; inside the Region$$Table stream area)
L_20100244:
        .word 0x20428840    @ 20100244: third copy: start
L_20100248:
        .word 0x2043ffff    @ 20100248: third copy: end (copies 0x20428840..0x2043FFFF, beyond the file end 0x2042BC10)
L_2010024c:
        .word 0x20100000    @ 2010024c: mmu_set_cacheable: image RAM, 4 MB
L_20100250:
        .word 0x60500000    @ 20100250: (branched over) .data_nc mirror, 1 MB
L_20100254:
        .word 0x60600000    @ 20100254: (branched over) 1 MB
L_20100258:
        .word 0x20100000    @ 20100258: VBAR: the vector table
L_2010025c:
        .word gic_dispatch    @ 2010025c
L_20100260:
        .word knl_irq_enter    @ 20100260
L_20100264:
        .word knl_irq_exit + 8    @ 20100264: its SVC-mode part, entered through svc #0 and SVC_Handler
        .size DAbort_Handler, . - DAbort_Handler
