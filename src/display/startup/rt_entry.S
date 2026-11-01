/*
 * FT-710 DISPLAY (T24 round 4): the armcc start-up between reset_in_ram and main, 0x20100BC0..0x20100D0B
 * (__main, __scatterload, __decompress, __scatterload_zeroinit, __rt_lib_init, __rt_entry), as assembly.
 *
 * These are the ARM C library's hand-written scatter-loading routines and the linker-selected __rt_ glue [inference:
 * the Region$$Table walk with handler addresses relative to the table, the LZ decoder and the 16-byte zero fill are the
 * armcc library's scatter-load members]. The instructions are the image's, with labels named after their original
 * address; every function is byte-identical to the image at its original address (tools/equiv_display_emu.py).
 *
 *  - __main (A32): blx __scatterload, then blx __rt_entry (not reached: __scatterload ends in __rt_entry).
 *  - __scatterload: for each Region$$Table entry {load, exec, size, handler} calls the handler (r0 load, r1 exec,
 *    r2 size; __decompress or __scatterload_zeroinit), returning to the loop; at the table end calls __rt_entry.
 *  - __decompress: the armcc LZ decoder (a token byte: literal count in bits 0..1 or a following byte, match length
 *    in bits 4..7 or a following byte, match offset in one or two bytes); tools/ghidra/DisplaySetup.java
 *    re-implements it.
 *  - __scatterload_zeroinit: stores zeros, 16 bytes per pass, then 8, then 4.
 *  - __rt_lib_init: the locale (libspace +4, +0xC) and __cpp_initialize__aeabi_ (the C++ constructors).
 *  - __rt_entry: __user_setup_stackheap, __rt_lib_init, main, exit.
 */
        .syntax unified
        .cpu cortex-a9

        .section .text.rt_main,"ax",%progbits
        .arm
        .p2align 2
        .global __main
        .type __main, %function
__main:                                 @ 0x20100BC0 (A32)
        blx __scatterload       @ 20100bc0
        blx __rt_entry          @ 20100bc4
        .size __main, . - __main

        .thumb
        .section .text.rt_scatterload,"ax",%progbits
        .p2align 2
        .global __scatterload
        .type __scatterload, %function
        .thumb_func
__scatterload:                          @ 0x20100BC8
        adr r0, L_20100bf4    @ 20100bc8
        ldm.w r0, {sl, fp}    @ 20100bca
        add sl, r0    @ 20100bce
        add fp, r0    @ 20100bd0
        sub.w r7, sl, #1    @ 20100bd2
        cmp sl, fp    @ 20100bd6
        bne L_20100bde    @ 20100bd8
        bl __rt_entry    @ 20100bda
L_20100bde:
        subw.w lr, pc, #9    @ 20100bde
        ldm.w sl!, {r0, r1, r2, r3}    @ 20100be2
        tst.w r3, #1    @ 20100be6
        it ne    @ 20100bea
        subne r3, r7, r3    @ 20100bec
        orr.w r3, r3, #1    @ 20100bee
        bx r3    @ 20100bf2
L_20100bf4:
        .word 0x00327ab4    @ 20100bf4: Region$$Table start, relative to this word
        .word 0x00327b04    @ 20100bf8: Region$$Table end, relative
        .size __scatterload, . - __scatterload
        .global __decompress
        .type __decompress, %function
        .thumb_func
__decompress:                           @ 0x20100BFC
        ldrb.w r3, [r0], #1    @ 20100bfc
        add r2, r1    @ 20100c00
L_20100c02:
        ands.w r4, r3, #3    @ 20100c02
        it eq    @ 20100c06
        ldrbeq.w r4, [r0], #1    @ 20100c08
        asrs r5, r3, #4    @ 20100c0c
        it eq    @ 20100c0e
        ldrbeq.w r5, [r0], #1    @ 20100c10
        .inst.n 0x1e64    @ 20100c14: subs r4, r4, #1 (the encoding as in the image: as picks another)
        beq L_20100c24    @ 20100c16
L_20100c18:
        ldrb.w r6, [r0], #1    @ 20100c18
        .inst.n 0x1e64    @ 20100c1c: subs r4, r4, #1 (the encoding as in the image: as picks another)
        strb.w r6, [r1], #1    @ 20100c1e
        bne L_20100c18    @ 20100c22
L_20100c24:
        cmp r5, #0    @ 20100c24
        beq L_20100c54    @ 20100c26
        ldrb.w r4, [r0], #1    @ 20100c28
        and.w r3, r3, #0xc    @ 20100c2c
        cmp r3, #0xc    @ 20100c30
        sub.w r4, r1, r4    @ 20100c32
        itet eq    @ 20100c36
        ldrbeq.w r3, [r0], #1    @ 20100c38
        subne.w r4, r4, r3, lsl #6    @ 20100c3c
        subeq.w r4, r4, r3, lsl #8    @ 20100c40
        add.w r3, r5, #1    @ 20100c44
L_20100c48:
        ldrb.w r6, [r4], #1    @ 20100c48
        .inst.n 0x1e5b    @ 20100c4c: subs r3, r3, #1 (the encoding as in the image: as picks another)
        strb.w r6, [r1], #1    @ 20100c4e
        bpl L_20100c48    @ 20100c52
L_20100c54:
        cmp r1, r2    @ 20100c54
        it lo    @ 20100c56
        ldrblo.w r3, [r0], #1    @ 20100c58
        blo L_20100c02    @ 20100c5c
        bx lr    @ 20100c5e
        .size __decompress, . - __decompress
        .global __scatterload_zeroinit
        .type __scatterload_zeroinit, %function
        .thumb_func
__scatterload_zeroinit:                 @ 0x20100C60
        movs r3, #0    @ 20100c60
        movs r4, #0    @ 20100c62
        movs r5, #0    @ 20100c64
        movs r6, #0    @ 20100c66
L_20100c68:
        subs r2, #0x10    @ 20100c68
        it hs    @ 20100c6a
        stmhs r1!, {r3, r4, r5, r6}    @ 20100c6c
        bhi L_20100c68    @ 20100c6e
        lsls r2, r2, #0x1d    @ 20100c70
        it hs    @ 20100c72
        stmhs r1!, {r4, r5}    @ 20100c74
        it mi    @ 20100c76
        strmi r3, [r1]    @ 20100c78
        bx lr    @ 20100c7a
        .size __scatterload_zeroinit, . - __scatterload_zeroinit

        .section .text.rt_entry,"ax",%progbits
        .p2align 2
        .global __rt_lib_init
        .type __rt_lib_init, %function
        .thumb_func
__rt_lib_init:                          @ 0x20100CB4
        push {r0, r1, r2, r3, r4, lr}    @ 20100cb4
        bl __rt_locale    @ 20100cb6
        movs r4, r0    @ 20100cba
        movs r0, #0    @ 20100cbc
        movs r1, #0    @ 20100cbe
        bl FUN_20163874    @ 20100cc0
        .inst.n 0x1c40    @ 20100cc4: adds r0, r0, #1 (the encoding as in the image: as picks another)
        str r0, [r4, #4]    @ 20100cc6
        movs r0, #0    @ 20100cc8
        movs r1, #0    @ 20100cca
        bl FUN_201638a0    @ 20100ccc
        str r0, [r4, #0xc]    @ 20100cd0
        bl __cpp_initialize__aeabi_    @ 20100cd2
        pop {r0, r1, r2, r3, r4, pc}    @ 20100cd6
        .size __rt_lib_init, . - __rt_lib_init
        .global __rt_lib_shutdown
        .type __rt_lib_shutdown, %function
        .thumb_func
__rt_lib_shutdown:                      @ 0x20100CD8
        push {r4, lr}    @ 20100cd8
        pop {r4, pc}    @ 20100cda
        .size __rt_lib_shutdown, . - __rt_lib_shutdown
        .global __rt_entry
        .type __rt_entry, %function
        .thumb_func
__rt_entry:                             @ 0x20100CDC
        bl __user_setup_stackheap    @ 20100cdc
        mov r1, r2    @ 20100ce0
        bl __rt_lib_init    @ 20100ce2
        blx main    @ 20100ce6
        bl exit    @ 20100cea
        push {r0, r1}    @ 20100cee
        bl __rt_lib_shutdown    @ 20100cf0
        pop {r0, r1}    @ 20100cf4
        bl _sys_exit    @ 20100cf6
        movs r0, r0    @ 20100cfa
        .word 0x000003ff    @ 20100cfc: Open: four words after __rt_entry, no reference found; would be settled by a literal/ADR scan for 0x20100CFC..0x20100D0B
        .word 0x00007fff    @ 20100d00
        .word 0x84188380    @ 20100d04
        .word 0x00c50078    @ 20100d08
        .size __rt_entry, . - __rt_entry
