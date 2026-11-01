/*
 * FT-710 DISPLAY (T24 round 4): the armcc soft-float double routines (fplib), 0x20164888..0x20165177, as
 * hand-written Thumb-2 assembly.
 *
 * The image calls these through the run-time ABI (__aeabi_dadd & co., RTABI section 4.1.2); they are hand-written
 * [inference: flag-setting instructions inside IT blocks, operands passed in the instruction stream after a bl
 * (fp_nan_handler), a tbb dispatch, none of which a C compiler emits], so C cannot recreate them as they are. The
 * instructions are the image's, in its order, with labels named after their original address; the whole range is
 * one section and every function in it is byte-identical to the image at its original address
 * (tools/equiv_display_emu.py, verdict "identical"). Eight 16-bit instructions are written as .inst.n because GNU
 * as picks another encoding of the same instruction (adds rd, rn, #imm3 versus adds rdn, #imm8).
 *
 * Found on the way [fact]: two A32 entry veneers ("add ip, pc, #1; bx ip") sit inside the range, at 0x20164C88 for
 * __aeabi_d2iz (called from 0x2011413C) and at 0x20164D4C for __aeabi_i2d (called from 0x201128D4); Ghidra's
 * function list does not have them. Each call of fp_nan_handler is followed by one data word (after alignment),
 * which fp_nan_handler reads through lr and skips. __aeabi_ddiv reads a 128-byte table at 0x20164C00 indexed by the
 * divisor's top bits (addw r6, pc, #0x140; ldrb r6, [r6, r5] at 0x20164A3C).
 */
        .syntax unified
        .cpu cortex-a9
        .thumb

        .section .text.fplib,"ax",%progbits
        .p2align 2
        .global __aeabi_dadd
        .type __aeabi_dadd, %function
        .thumb_func
__aeabi_dadd:                           @ 0x20164888: double r0:r1 + r2:r3 (IEEE round to nearest even); operands of opposite sign go to the dsub core
        push {r4, lr}    @ 20164888
        teq.w r1, r3    @ 2016488a
        it mi    @ 2016488e
        eormi.w r3, r3, #0x80000000    @ 20164890
        bmi.w L_20164fb4    @ 20164894
L_20164898:
        subs r4, r0, r2    @ 20164898
        sbcs.w ip, r1, r3    @ 2016489a
        bhs L_201648ac    @ 2016489e
        adds r2, r2, r4    @ 201648a0
        adc.w r3, r3, ip    @ 201648a2
        subs r0, r0, r4    @ 201648a6
        sbc.w r1, r1, ip    @ 201648a8
L_201648ac:
        ldr.w lr, L_201649d4    @ 201648ac
        lsr.w r4, r1, #0x14    @ 201648b0
        sub.w ip, r4, r3, lsr #20    @ 201648b4
        tst.w lr, r3, lsl #1    @ 201648b8
        it ne    @ 201648bc
        teqne.w lr, r4, lsl #21    @ 201648be
        beq L_201649ac    @ 201648c2
        bic.w r3, r3, lr    @ 201648c4
        rsbs.w lr, ip, #0x20    @ 201648c8
        bic.w r1, r1, r4, lsl #20    @ 201648cc
        orr.w r3, r3, #0x100000    @ 201648d0
        blo L_2016493c    @ 201648d4
        lsr.w lr, r2, ip    @ 201648d6
        adds.w r0, r0, lr    @ 201648da
        lsr.w lr, r3, ip    @ 201648de
        adc.w r1, r1, lr    @ 201648e2
        rsb.w lr, ip, #0x20    @ 201648e6
        lsl.w lr, r3, lr    @ 201648ea
        adds.w r0, r0, lr    @ 201648ee
        adcs.w r1, r1, #0    @ 201648f2
        cmp.w r1, #0x100000    @ 201648f6
        rsb.w lr, ip, #0x20    @ 201648fa
        bhs L_20164966    @ 201648fe
        add.w r1, r1, r4, lsl #20    @ 20164900
L_20164904:
        lsls.w r2, r2, lr    @ 20164904
        pop.w {r4, lr}    @ 20164908
        it pl    @ 2016490c
        bxpl lr    @ 2016490e
        .inst.n 0x1c40    @ 20164910: adds r0, r0, #1 (the encoding as in the image: as picks another)
        it lo    @ 20164912
        lslslo.w r2, r2, #1    @ 20164914
        it ne    @ 20164918
        bxne lr    @ 2016491a
L_2016491c:
        cmp r0, #0    @ 2016491c
        ite ne    @ 2016491e
        bicne.w r0, r0, #1    @ 20164920
        adceq.w r1, r1, #0    @ 20164924
L_20164928:
        lsl.w r3, r1, #1    @ 20164928
        cmn.w r3, #0x200000    @ 2016492c
        it lo    @ 20164930
        bxlo lr    @ 20164932
        sub.w r1, r1, #0x60000000    @ 20164934
        b.w fp_exception_stub    @ 20164938
L_2016493c:
        cmp r2, #1    @ 2016493c
        adc.w r2, r3, r3    @ 2016493e
        sub.w ip, ip, #0x20    @ 20164942
        rsbs.w lr, ip, #0x1f    @ 20164946
        itee lo    @ 2016494a
        movlo.w lr, #0    @ 2016494c
        lsrhs.w r3, r3, ip    @ 20164950
        addshs.w r0, r0, r3    @ 20164954
        adc.w r1, r1, r4, lsl #20    @ 20164958
        cmp.w r4, r1, lsr #20    @ 2016495c
        beq L_20164904    @ 20164960
        sub.w r1, r1, r4, lsl #20    @ 20164962
L_20164966:
        add.w r1, r1, #0x100000    @ 20164966
        lsrs r1, r1, #1    @ 2016496a
        rrxs.w r0, r0    @ 2016496c
        add.w r1, r1, r4, lsl #20    @ 20164970
        blo L_20164994    @ 20164974
        adcs.w r0, r0, #0    @ 20164976
        it lo    @ 2016497a
        lslslo.w lr, r2, lr    @ 2016497c
        bne L_20164994    @ 20164980
        pop.w {r4, lr}    @ 20164982
        b L_2016491c    @ 20164986
        .inst.n 0x1c40    @ 20164988: adds r0, r0, #1 (the encoding as in the image: as picks another)
        it lo    @ 2016498a
        lslslo.w r2, r2, #1    @ 2016498c
        bne L_20164928    @ 20164990
        b L_2016491c    @ 20164992
L_20164994:
        pop.w {r4, lr}    @ 20164994
        lsl.w r3, r1, #1    @ 20164998
        cmn.w r3, #0x200000    @ 2016499c
        it lo    @ 201649a0
        bxlo lr    @ 201649a2
        sub.w r1, r1, #0x60000000    @ 201649a4
        b.w fp_exception_stub    @ 201649a8
L_201649ac:
        teq.w lr, r4, lsl #21    @ 201649ac
        beq L_201649c4    @ 201649b0
        tst.w r1, lr, lsr #1    @ 201649b2
        pop.w {r4, lr}    @ 201649b6
        itt eq    @ 201649ba
        andeq.w r1, r1, #0x80000000    @ 201649bc
        moveq r0, #0    @ 201649c0
        bx lr    @ 201649c2
L_201649c4:
        pop.w {r4, lr}    @ 201649c4
        push {r4, r5, r6, lr}    @ 201649c8
        bl fp_nan_handler    @ 201649ca
        nop    @ 201649ce
        .word 0x3ebefb64    @ 201649d0
L_201649d4:
        .word 0xffe00000    @ 201649d4
        .size __aeabi_dadd, . - __aeabi_dadd

        .global __aeabi_ddiv
        .type __aeabi_ddiv, %function
        .thumb_func
__aeabi_ddiv:                           @ 0x201649D8: double r0:r1 / r2:r3; quotient digits from the reciprocal byte table below
        push.w {r6, r7, r8, lr}    @ 201649d8
        push {r4, r5}    @ 201649dc
        ldr.w ip, L_20164c80    @ 201649de
        bics.w r4, ip, r1, lsr #4    @ 201649e2
        it ne    @ 201649e6
        bicsne.w r4, ip, r3, lsr #4    @ 201649e8
        beq.w L_20164bc8    @ 201649ec
        eor.w r5, r1, r3    @ 201649f0
        ands.w r4, ip, r1, lsr #4    @ 201649f4
        orr.w r4, r4, r5, lsr #31    @ 201649f8
        it ne    @ 201649fc
        andsne.w r5, ip, r3, lsr #4    @ 201649fe
        beq.w L_20164b94    @ 20164a02
        sub.w r4, r4, r5    @ 20164a06
        mov.w r5, #-0x80000000    @ 20164a0a
        orr.w r1, r5, r1, lsl #11    @ 20164a0e
        orr.w r3, r5, r3, lsl #11    @ 20164a12
        orr.w r1, r1, r0, lsr #21    @ 20164a16
        orr.w r3, r3, r2, lsr #21    @ 20164a1a
        add.w r4, r4, #0x3fc0000    @ 20164a1e
        cmp r1, r3    @ 20164a22
        add.w r4, r4, #0x20000    @ 20164a24
        lsl.w r0, r0, #0xb    @ 20164a28
        lsl.w r2, r2, #0xb    @ 20164a2c
        it eq    @ 20164a30
        cmpeq r0, r2    @ 20164a32
        beq.w L_20164b70    @ 20164a34
        lsr.w r5, r3, #0x18    @ 20164a38
        addw.w r6, pc, #0x140    @ 20164a3c
        ldrb r6, [r6, r5]    @ 20164a40
        lsr.w r5, r3, #0x10    @ 20164a42
        mul.w r7, r6, r5    @ 20164a46
        rsb.w r7, r7, #0x1000000    @ 20164a4a
        mul.w r7, r6, r7    @ 20164a4e
        lsr.w r7, r7, #0xf    @ 20164a52
        umull.w r6, r8, r7, r3    @ 20164a56
        rsbs r6, r6, #0    @ 20164a5a
        rsb.w r8, r8, #0x10000    @ 20164a5c
        umull.w ip, lr, r7, r6    @ 20164a60
        it lo    @ 20164a64
        sublo.w r8, r8, #1    @ 20164a66
        mla.w r6, r7, r8, lr    @ 20164a6a
        mov.w lr, #0    @ 20164a6e
        umull.w r8, ip, r6, r2    @ 20164a72
        umlal.w ip, lr, r6, r3    @ 20164a76
        rsbs.w ip, ip, #0    @ 20164a7a
        rsb.w lr, lr, #-0x80000000    @ 20164a7e
        it lo    @ 20164a82
        sublo.w lr, lr, #1    @ 20164a84
        umull.w r5, r8, r6, ip    @ 20164a88
        mov.w r7, #0    @ 20164a8c
        mov.w r5, #0    @ 20164a90
        umlal.w r8, r7, r6, lr    @ 20164a94
        umull.w ip, r6, r1, r8    @ 20164a98
        umull.w ip, lr, r0, r7    @ 20164a9c
        adds.w r6, r6, lr    @ 20164aa0
        adc.w r5, r5, #0    @ 20164aa4
        umlal.w r6, r5, r1, r7    @ 20164aa8
        adds.w lr, r5, #0x70000000    @ 20164aac
        ittt vc    @ 20164ab0
        subvc.w r4, r4, #0x10000    @ 20164ab2
        lslsvc.w r6, r6, #1    @ 20164ab6
        adcvc r5, r5    @ 20164aba
        adds.w r7, r6, #0x80    @ 20164abc
        adc.w r5, r5, #0    @ 20164ac0
        lsr.w r7, r7, #8    @ 20164ac4
        lsl.w r6, r6, #0x18    @ 20164ac8
        orr.w r7, r7, r5, lsl #24    @ 20164acc
        sub.w r6, r6, #0x6f000000    @ 20164ad0
        cmp.w r6, #0x10000000    @ 20164ad4
        lsr.w r5, r5, #8    @ 20164ad8
        bls L_20164b1e    @ 20164adc
L_20164ade:
        mov r0, r7    @ 20164ade
        bic.w ip, r4, #1    @ 20164ae0
        add.w r1, r5, r4, lsl #31    @ 20164ae4
        cmp.w ip, #0x7f00000    @ 20164ae8
        add.w r1, r1, ip, lsl #4    @ 20164aec
        bhi L_20164af8    @ 20164af0
        pop {r4, r5, r6, r7}    @ 20164af2
        pop.w {r8, pc}    @ 20164af4
L_20164af8:
        tst r4, r4    @ 20164af8
        itt pl    @ 20164afa
        addpl.w lr, r1, #0x100000    @ 20164afc
        teqpl.w lr, r4, lsl #31    @ 20164b00
        bmi L_20164b0c    @ 20164b04
        pop {r4, r5, r6, r7}    @ 20164b06
        pop.w {r8, pc}    @ 20164b08
L_20164b0c:
        tst r4, r4    @ 20164b0c
        bmi L_20164b82    @ 20164b0e
        pop {r4, r5, r6, r7}    @ 20164b10
        sub.w r1, r1, #0x60000000    @ 20164b12
        pop.w {r8, lr}    @ 20164b16
        b.w fp_exception_stub    @ 20164b1a
L_20164b1e:
        lsr.w r2, r2, #0xb    @ 20164b1e
        orr.w r2, r2, r3, lsl #21    @ 20164b22
        lsr.w r3, r3, #0xb    @ 20164b26
        umull.w r8, r6, r7, r2    @ 20164b2a
        lsr.w r0, r0, #0xb    @ 20164b2e
        orr.w r0, r0, r1, lsl #21    @ 20164b32
        mla.w r6, r7, r3, r6    @ 20164b36
        tst.w lr, lr    @ 20164b3a
        lsr.w r1, r1, #0xb    @ 20164b3e
        mla.w r6, r5, r2, r6    @ 20164b42
        it pl    @ 20164b46
        subpl.w r6, r6, r0, lsl #20    @ 20164b48
        subs.w r6, r6, r0, lsl #20    @ 20164b4c
        lsr.w lr, r2, #1    @ 20164b50
        orr.w lr, lr, r3, lsl #31    @ 20164b54
        adds.w lr, r8, lr    @ 20164b58
        adcs.w lr, r6, r3, lsr #1    @ 20164b5c
        bpl L_20164ade    @ 20164b60
        adds.w r8, r8, r2    @ 20164b62
        adcs r6, r3    @ 20164b66
        .inst.n 0x1c7f    @ 20164b68: adds r7, r7, #1 (the encoding as in the image: as picks another)
        adcs.w r5, r5, #0    @ 20164b6a
        b L_20164ade    @ 20164b6e
L_20164b70:
        mov.w r5, #0x100000    @ 20164b70
        mov.w r7, #0    @ 20164b74
        mov.w r6, #0    @ 20164b78
        mov.w r8, #0    @ 20164b7c
        b L_20164ade    @ 20164b80
L_20164b82:
        pop {r4, r5, r6, r7}    @ 20164b82
        mov.w r0, #0    @ 20164b84
        add.w r1, r1, #0x60000000    @ 20164b88
        and.w r1, r1, #0x80000000    @ 20164b8c
        pop.w {r8, pc}    @ 20164b90
L_20164b94:
        tst.w r1, ip, lsl #4    @ 20164b94
        and.w r5, ip, r3, lsr #4    @ 20164b98
        beq L_20164ba0    @ 20164b9c
        b L_20164bba    @ 20164b9e
L_20164ba0:
        tst.w r3, ip, lsl #4    @ 20164ba0
        beq.w L_20164bf2    @ 20164ba4
        mov.w r0, #0    @ 20164ba8
        pop {r4, r5, r6, r7}    @ 20164bac
        eor.w r1, r1, r3    @ 20164bae
        and.w r1, r1, #0x80000000    @ 20164bb2
        pop.w {r8, pc}    @ 20164bb6
L_20164bba:
        pop {r4, r5, r6, r7}    @ 20164bba
        pop.w {r8, lr}    @ 20164bbc
        eor.w r1, r1, r3    @ 20164bc0
        b.w fp_exception_stub    @ 20164bc4
L_20164bc8:
        pop {r4, r5, r6, r7}    @ 20164bc8
        pop.w {r8, lr}    @ 20164bca
        push {r4, r5, r6, lr}    @ 20164bce
        bl fp_nan_handler    @ 20164bd0
        .word 0x3efc7e09    @ 20164bd4
        b.w L_20164bea    @ 20164bd8
        eor.w r1, r1, r3    @ 20164bdc
        mov.w r0, #0    @ 20164be0
        and.w r1, r1, #0x80000000    @ 20164be4
        bx lr    @ 20164be8
L_20164bea:
        eor.w r1, r1, r3    @ 20164bea
        b.w fp_exception_stub    @ 20164bee
L_20164bf2:
        pop {r4, r5, r6, r7}    @ 20164bf2
        pop.w {r8, lr}    @ 20164bf4
        mov.w r0, #0    @ 20164bf8
        ldr r1, L_20164c84    @ 20164bfc
        bx lr    @ 20164bfe
        .word 0xf9fbfdff    @ 20164c00
        .word 0xf2f4f5f7    @ 20164c04
        .word 0xebedeef0    @ 20164c08
        .word 0xe4e6e8e9    @ 20164c0c
        .word 0xdee0e1e3    @ 20164c10
        .word 0xd8dadbdd    @ 20164c14
        .word 0xd3d4d5d7    @ 20164c18
        .word 0xcdcfd0d1    @ 20164c1c
        .word 0xc8cacbcc    @ 20164c20
        .word 0xc4c5c6c7    @ 20164c24
        .word 0xbfc0c1c2    @ 20164c28
        .word 0xbbbcbdbe    @ 20164c2c
        .word 0xb7b8b9ba    @ 20164c30
        .word 0xb3b4b5b6    @ 20164c34
        .word 0xafb0b1b2    @ 20164c38
        .word 0xabacadae    @ 20164c3c
        .word 0xa8a8a9aa    @ 20164c40
        .word 0xa4a5a6a7    @ 20164c44
        .word 0xa1a2a3a3    @ 20164c48
        .word 0x9e9f9fa0    @ 20164c4c
        .word 0x9b9c9c9d    @ 20164c50
        .word 0x9899999a    @ 20164c54
        .word 0x95969797    @ 20164c58
        .word 0x93939495    @ 20164c5c
        .word 0x90919192    @ 20164c60
        .word 0x8e8e8f8f    @ 20164c64
        .word 0x8b8c8c8d    @ 20164c68
        .word 0x89898a8b    @ 20164c6c
        .word 0x87878888    @ 20164c70
        .word 0x84858586    @ 20164c74
        .word 0x82838384    @ 20164c78
        .word 0x80818182    @ 20164c7c
L_20164c80:
        .word 0x07ff0000    @ 20164c80
L_20164c84:
        .word 0x7ff80000    @ 20164c84
        .arm                            @ 20164c88: A32 entry veneer of __aeabi_d2iz (not in Ghidra's list)
        add ip, pc, #1
        bx ip
        .thumb
        .size __aeabi_ddiv, . - __aeabi_ddiv

        .global __aeabi_d2iz
        .type __aeabi_d2iz, %function
        .thumb_func
__aeabi_d2iz:                           @ 0x20164C90: double -> int32, truncating; out of range and NaN through fp_nan_handler
        lsl.w r3, r1, #1    @ 20164c90
        lsr.w r3, r3, #0x15    @ 20164c94
        sub.w r3, r3, #0x400    @ 20164c98
        rsbs.w r3, r3, #0x1e    @ 20164c9c
        it gt    @ 20164ca0
        rsbsgt.w ip, r3, #0x21    @ 20164ca2
        ble L_20164cc2    @ 20164ca6
        mov.w r2, #-0x80000000    @ 20164ca8
        orr.w r2, r2, r1, lsl #11    @ 20164cac
        orr.w r2, r2, r0, lsr #21    @ 20164cb0
        lsrs.w ip, r2, r3    @ 20164cb4
        eor.w ip, ip, r1, asr #31    @ 20164cb8
        sub.w r0, ip, r1, asr #31    @ 20164cbc
        bx lr    @ 20164cc0
L_20164cc2:
        cmp r3, #0x10    @ 20164cc2
        itt gt    @ 20164cc4
        movgt r0, #0    @ 20164cc6
        bxgt lr    @ 20164cc8
        add.w ip, r3, #0x3e0    @ 20164cca
        cmp.w ip, #-1    @ 20164cce
        beq L_20164cde    @ 20164cd2
L_20164cd4:
        mvn.w r2, #0x80000000    @ 20164cd4
        eor.w r0, r2, r1, asr #32    @ 20164cd8
        bx lr    @ 20164cdc
L_20164cde:
        push {r4, r5, r6, lr}    @ 20164cde
        bl fp_nan_handler    @ 20164ce0
        .word 0x80249249    @ 20164ce4
        movs r0, #0    @ 20164ce8
        bx lr    @ 20164cea
        b L_20164cd4    @ 20164cec
        movs r0, r0    @ 20164cee
        .size __aeabi_d2iz, . - __aeabi_d2iz

        .global __aeabi_d2uiz
        .type __aeabi_d2uiz, %function
        .thumb_func
__aeabi_d2uiz:                          @ 0x20164CF0: double -> uint32, truncating
        lsr.w r3, r1, #0x14    @ 20164cf0
        sub.w r3, r3, #0x400    @ 20164cf4
        rsbs.w r3, r3, #0x1e    @ 20164cf8
        it ge    @ 20164cfc
        rsbsge.w ip, r3, #0x20    @ 20164cfe
        blt L_20164d16    @ 20164d02
        mov.w r2, #-0x80000000    @ 20164d04
        orr.w r2, r2, r1, lsl #11    @ 20164d08
        orrs.w r2, r2, r0, lsr #21    @ 20164d0c
        lsrs.w r0, r2, r3    @ 20164d10
        bx lr    @ 20164d14
L_20164d16:
        tst r1, r1    @ 20164d16
        bmi L_20164d32    @ 20164d18
        cmp r3, #0x10    @ 20164d1a
        itt gt    @ 20164d1c
        movgt r0, #0    @ 20164d1e
        bxgt lr    @ 20164d20
        add.w ip, r3, #0x3e0    @ 20164d22
        cmp.w ip, #-1    @ 20164d26
        beq L_20164d38    @ 20164d2a
L_20164d2c:
        mov.w r0, #-1    @ 20164d2c
        bx lr    @ 20164d30
L_20164d32:
        mov.w r0, #0    @ 20164d32
        bx lr    @ 20164d36
L_20164d38:
        push {r4, r5, r6, lr}    @ 20164d38
        bl fp_nan_handler    @ 20164d3a
        nop    @ 20164d3e
        .word 0x80249249    @ 20164d40
        movs r0, #0    @ 20164d44
        bx lr    @ 20164d46
        b L_20164d2c    @ 20164d48
        movs r0, r0    @ 20164d4a
        .arm                            @ 20164d4c: A32 entry veneer of __aeabi_i2d (not in Ghidra's list)
        add ip, pc, #1
        bx ip
        .thumb
        .size __aeabi_d2uiz, . - __aeabi_d2uiz

        .global __aeabi_i2d
        .type __aeabi_i2d, %function
        .thumb_func
__aeabi_i2d:                            @ 0x20164D54: int32 -> double (exact)
        ands.w r2, r0, #0x80000000    @ 20164d54
        it mi    @ 20164d58
        rsbmi r0, r0, #0    @ 20164d5a
        clz.w r3, r0    @ 20164d5c
        lsls.w r1, r0, r3    @ 20164d60
        beq L_20164d7c    @ 20164d64
        rsb.w r3, r3, #0x1d    @ 20164d66
        add.w r3, r3, #0x400    @ 20164d6a
        lsl.w r0, r1, #0x15    @ 20164d6e
        add.w r2, r2, r3, lsl #20    @ 20164d72
        add.w r1, r2, r1, lsr #11    @ 20164d76
        bx lr    @ 20164d7a
L_20164d7c:
        mov.w r0, #0    @ 20164d7c
        bx lr    @ 20164d80
        .size __aeabi_i2d, . - __aeabi_i2d

        .global __aeabi_ui2d
        .type __aeabi_ui2d, %function
        .thumb_func
__aeabi_ui2d:                           @ 0x20164D82: uint32 -> double (exact)
        clz.w r3, r0    @ 20164d82
        lsls.w r1, r0, r3    @ 20164d86
        beq L_20164da2    @ 20164d8a
        rsb.w r3, r3, #0x1d    @ 20164d8c
        add.w r3, r3, #0x400    @ 20164d90
        lsl.w r0, r1, #0x15    @ 20164d94
        lsl.w r2, r3, #0x14    @ 20164d98
        add.w r1, r2, r1, lsr #11    @ 20164d9c
        bx lr    @ 20164da0
L_20164da2:
        mov.w r0, #0    @ 20164da2
        bx lr    @ 20164da6
        .size __aeabi_ui2d, . - __aeabi_ui2d

        .global __aeabi_dmul
        .type __aeabi_dmul, %function
        .thumb_func
__aeabi_dmul:                           @ 0x20164DA8: double r0:r1 * r2:r3
        ldr.w ip, L_20164ef4    @ 20164da8
        push {r4, r5, r6, lr}    @ 20164dac
        ands.w lr, ip, r1, lsr #4    @ 20164dae
        ittt ne    @ 20164db2
        andsne.w r5, ip, r3, lsr #4    @ 20164db4
        teqne.w lr, ip    @ 20164db8
        teqne.w r5, ip    @ 20164dbc
        beq.w L_20164ea2    @ 20164dc0
        eor.w r4, r1, r3    @ 20164dc4
        bic.w r3, r3, ip, lsl #5    @ 20164dc8
        orr.w lr, lr, r4, lsr #31    @ 20164dcc
        bic.w r1, r1, ip, lsl #5    @ 20164dd0
        orr.w r1, r1, #0x100000    @ 20164dd4
        orr.w r3, r3, #0x100000    @ 20164dd8
        add lr, r5    @ 20164ddc
        umull.w r4, ip, r1, r2    @ 20164dde
        umull.w r6, r5, r0, r3    @ 20164de2
        sub.w lr, lr, #0x3fc0000    @ 20164de6
        adds r6, r6, r4    @ 20164dea
        adcs.w r5, r5, ip    @ 20164dec
        umull.w r4, ip, r1, r3    @ 20164df0
        adc.w r3, ip, #0    @ 20164df4
        umull.w r1, ip, r0, r2    @ 20164df8
        adds.w r6, r6, ip    @ 20164dfc
        adcs r5, r4    @ 20164e00
        adcs.w r3, r3, #0    @ 20164e02
        tst r1, r1    @ 20164e06
        it ne    @ 20164e08
        orrne.w r6, r6, #1    @ 20164e0a
        tst.w r3, #0x200    @ 20164e0e
        bne L_20164e2c    @ 20164e12
        lsl.w r1, r3, #0xc    @ 20164e14
        lsl.w r0, r5, #0xc    @ 20164e18
        lsls r4, r6, #0xc    @ 20164e1c
        orr.w r1, r1, r5, lsr #20    @ 20164e1e
        orr.w r0, r0, r6, lsr #20    @ 20164e22
        mvn.w r2, #3    @ 20164e26
        b L_20164e42    @ 20164e2a
L_20164e2c:
        lsl.w r1, r3, #0xb    @ 20164e2c
        lsl.w r0, r5, #0xb    @ 20164e30
        lsls r4, r6, #0xb    @ 20164e34
        orr.w r1, r1, r5, lsr #21    @ 20164e36
        orr.w r0, r0, r6, lsr #21    @ 20164e3a
        mvn.w r2, #2    @ 20164e3e
L_20164e42:
        add.w r2, r2, lr, asr #16    @ 20164e42
        add.w r5, r1, r2, lsl #20    @ 20164e46
        eor.w r1, r5, lr, lsl #31    @ 20164e4a
        beq L_20164e66    @ 20164e4e
        lsls.w ip, r4, #1    @ 20164e50
        it ne    @ 20164e54
        bicne.w r4, r4, #0x80000000    @ 20164e56
        adcs.w r0, r0, #0    @ 20164e5a
        adc.w r1, r1, #0    @ 20164e5e
        bic.w r0, r0, r4, lsr #31    @ 20164e62
L_20164e66:
        movw.w ip, #0x7fe    @ 20164e66
        cmp r2, ip    @ 20164e6a
        bhs L_20164e70    @ 20164e6c
        pop {r4, r5, r6, pc}    @ 20164e6e
L_20164e70:
        cmp r0, r5    @ 20164e70
        ite ne    @ 20164e72
        movne.w r4, #0x40000000    @ 20164e74
        moveq.w r4, #-0x40000000    @ 20164e78
        cmp r6, #0    @ 20164e7c
        it eq    @ 20164e7e
        moveq r4, #0    @ 20164e80
        cmp.w lr, #0x4000000    @ 20164e82
        it ge    @ 20164e86
        subge.w r1, r1, #0x60000000    @ 20164e88
        pop.w {r4, r5, r6, lr}    @ 20164e8c
        bge.w fp_exception_stub    @ 20164e90
        mov.w r0, #0    @ 20164e94
        add.w r1, r1, #0x60000000    @ 20164e98
        and.w r1, r1, #0x80000000    @ 20164e9c
        bx lr    @ 20164ea0
L_20164ea2:
        teq.w lr, ip    @ 20164ea2
        and.w r5, ip, r3, lsr #4    @ 20164ea6
        it ne    @ 20164eaa
        teqne.w r5, ip    @ 20164eac
        beq L_20164ec0    @ 20164eb0
        mov.w r0, #0    @ 20164eb2
        eor.w lr, r1, r3    @ 20164eb6
        and.w r1, lr, #0x80000000    @ 20164eba
        pop {r4, r5, r6, pc}    @ 20164ebe
L_20164ec0:
        bl fp_nan_handler    @ 20164ec0
        .word 0x3e010089    @ 20164ec4
        b.w L_20164eda    @ 20164ec8
        b.w L_20164ee2    @ 20164ecc
        lsl.w ip, r3, #1    @ 20164ed0
        lsrs.w ip, ip, #0x15    @ 20164ed4
        beq L_20164eec    @ 20164ed8
L_20164eda:
        eor.w r1, r1, r3    @ 20164eda
        b.w fp_exception_stub    @ 20164ede
L_20164ee2:
        lsl.w ip, r1, #1    @ 20164ee2
        lsrs.w ip, ip, #0x15    @ 20164ee6
        bne L_20164eda    @ 20164eea
L_20164eec:
        mov.w r0, #0    @ 20164eec
        ldr r1, L_20164ef8    @ 20164ef0
        bx lr    @ 20164ef2
L_20164ef4:
        .word 0x07ff0000    @ 20164ef4
L_20164ef8:
        .word 0x7ff80000    @ 20164ef8
        .size __aeabi_dmul, . - __aeabi_dmul

        .global fp_nan_handler
        .type fp_nan_handler, %function
        .thumb_func
fp_nan_handler:                         @ 0x20164EFC: special operands: the word after the caller's bl holds a 3-bit action per operand class (NaN, infinity, ...): 0..3 return into the code after the word, 4..7 the tbb cases (default quiet NaN 0x7FF80000:0, the second operand, a signed zero)
        add.w lr, lr, #2    @ 20164efc
        bic.w lr, lr, #3    @ 20164f00
        ldr.w r6, [lr], #4    @ 20164f04
        tst r6, r6    @ 20164f08
        bmi L_20164f18    @ 20164f0a
        cmp r2, #1    @ 20164f0c
        adc.w r5, r3, r3    @ 20164f0e
        cmn.w r5, #0x200000    @ 20164f12
        bhi L_20164f3e    @ 20164f16
L_20164f18:
        cmp r0, #1    @ 20164f18
        adc.w ip, r1, r1    @ 20164f1a
        cmn.w ip, #0x200000    @ 20164f1e
        bhi L_20164f3e    @ 20164f22
        bne L_20164f44    @ 20164f24
        lsr.w ip, r1, #0x1f    @ 20164f26
        cmn.w r5, #0x200000    @ 20164f2a
        add.w ip, ip, ip, lsl #1    @ 20164f2e
        add.w ip, ip, #2    @ 20164f32
        it eq    @ 20164f36
        adceq.w ip, ip, r3, lsr #31    @ 20164f38
        b L_20164f48    @ 20164f3c
L_20164f3e:
        mov.w ip, #8    @ 20164f3e
        b L_20164f48    @ 20164f42
L_20164f44:
        lsr.w ip, r3, #0x1f    @ 20164f44
L_20164f48:
        add.w r5, ip, ip, lsl #1    @ 20164f48
        lsr.w r6, r6, r5    @ 20164f4c
        and.w r6, r6, #7    @ 20164f50
        subs.w ip, r6, #4    @ 20164f54
        bhs L_20164f68    @ 20164f58
        add.w ip, lr, r6, lsl #2    @ 20164f5a
        pop.w {r4, r5, r6, lr}    @ 20164f5e
        orr.w ip, ip, #1    @ 20164f62
        bx ip    @ 20164f66
L_20164f68:
        tbb.w [pc, ip]    @ 20164f68
        .word 0x02020b09    @ 20164f6c
        mov.w r1, #-0x80000000    @ 20164f70
        mov.w r0, #0    @ 20164f74
        sub.w r1, r1, #0x80000    @ 20164f78
        pop {r4, r5, r6, pc}    @ 20164f7c
        mov r1, r3    @ 20164f7e
        mov r0, r2    @ 20164f80
        cmp r0, #1    @ 20164f82
        adcs.w r4, r1, r1    @ 20164f84
        it ne    @ 20164f88
        rsbsne.w r4, r4, #0x200000    @ 20164f8a
        itt hi    @ 20164f8e
        movhi r0, #0    @ 20164f90
        andhi.w r1, r1, #0x80000000    @ 20164f92
        pop {r4, r5, r6, pc}    @ 20164f96
        .size fp_nan_handler, . - fp_nan_handler

        .global fp_exception_stub
        .type fp_exception_stub, %function
        .thumb_func
fp_exception_stub:                      @ 0x20164F98: overflow and underflow result: rebuilds the exponent of r0:r1 (rrx)
        lsrs r0, r1, #0x20    @ 20164f98
        sub.w r1, r0, #0x200000    @ 20164f9a
        rrx.w r1, r1    @ 20164f9e
        bx lr    @ 20164fa2
        .size fp_exception_stub, . - fp_exception_stub

        .global __aeabi_dsub
        .type __aeabi_dsub, %function
        .thumb_func
__aeabi_dsub:                           @ 0x20164FA4: double r0:r1 - r2:r3; also the core of dadd for operands of opposite sign
        push {r4, lr}    @ 20164fa4
        teq.w r1, r3    @ 20164fa6
        it mi    @ 20164faa
        eormi.w r3, r3, #0x80000000    @ 20164fac
        bmi.w L_20164898    @ 20164fb0
L_20164fb4:
        subs r4, r0, r2    @ 20164fb4
        sbcs.w ip, r1, r3    @ 20164fb6
        bhs L_20164fcc    @ 20164fba
        adds r2, r2, r4    @ 20164fbc
        eor.w ip, ip, #0x80000000    @ 20164fbe
        adc.w r3, r3, ip    @ 20164fc2
        subs r0, r0, r4    @ 20164fc6
        sbc.w r1, r1, ip    @ 20164fc8
L_20164fcc:
        ldr.w lr, L_20165174    @ 20164fcc
        lsr.w r4, r1, #0x14    @ 20164fd0
        sub.w ip, r4, r3, lsr #20    @ 20164fd4
        tst.w lr, r3, lsl #1    @ 20164fd8
        it ne    @ 20164fdc
        teqne.w lr, r4, lsl #21    @ 20164fde
        beq.w L_20165146    @ 20164fe2
        bic.w r3, r3, lr, asr #1    @ 20164fe6
        rsbs r2, r2, #0    @ 20164fea
        bic.w r1, r1, r4, lsl #20    @ 20164fec
        rsb.w r3, r3, lr, asr #1    @ 20164ff0
        it lo    @ 20164ff4
        .inst.n 0x1e5b    @ 20164ff6: sublo r3, r3, #1 (the encoding as in the image: as picks another)
        rsbs.w lr, ip, #0x20    @ 20164ff8
        blo L_2016504a    @ 20164ffc
        lsr.w lr, r2, ip    @ 20164ffe
        adds.w r0, r0, lr    @ 20165002
        asr.w lr, r3, ip    @ 20165006
        adc.w r1, r1, lr    @ 2016500a
        rsb.w lr, ip, #0x20    @ 2016500e
        lsl.w lr, r3, lr    @ 20165012
        adds.w r0, r0, lr    @ 20165016
        adcs.w r1, r1, #0    @ 2016501a
        rsb.w lr, ip, #0x20    @ 2016501e
        bmi L_20165078    @ 20165022
L_20165024:
        lsls.w r2, r2, lr    @ 20165024
        add.w r1, r1, r4, lsl #20    @ 20165028
        pop.w {r4, lr}    @ 2016502c
        it pl    @ 20165030
        bxpl lr    @ 20165032
        .inst.n 0x1c40    @ 20165034: adds r0, r0, #1 (the encoding as in the image: as picks another)
        itt ne    @ 20165036
        cmpne.w r2, #-0x80000000    @ 20165038
        bxne lr    @ 2016503c
        cmp r0, #0    @ 2016503e
        ite eq    @ 20165040
        .inst.n 0x1c49    @ 20165042: addeq r1, r1, #1 (the encoding as in the image: as picks another)
        bicne.w r0, r0, #1    @ 20165044
        bx lr    @ 20165048
L_2016504a:
        adds.w lr, r2, r2    @ 2016504a
        adc.w r2, r3, r3    @ 2016504e
        it ne    @ 20165052
        movne.w lr, #1    @ 20165054
        orr.w r2, lr, r2, lsl #1    @ 20165058
        sub.w ip, ip, #0x20    @ 2016505c
        rsbs.w lr, ip, #0x1e    @ 20165060
        bls L_20165110    @ 20165064
        asr.w lr, r3, ip    @ 20165066
        adds.w r0, r0, lr    @ 2016506a
        adcs.w r1, r1, #-1    @ 2016506e
        rsb.w lr, ip, #0x1e    @ 20165072
        bpl L_20165024    @ 20165076
L_20165078:
        add.w lr, lr, #1    @ 20165078
        lsls.w lr, r2, lr    @ 2016507c
        adcs r0, r0    @ 20165080
        adc.w r1, r1, r1    @ 20165082
        add.w ip, r1, r4, lsl #21    @ 20165086
        lsrs.w ip, ip, #0x15    @ 2016508a
        bls L_201650b2    @ 2016508e
        adds.w r0, r0, lr, lsr #31    @ 20165090
        add.w r1, r1, r4, lsl #20    @ 20165094
        it lo    @ 20165098
        cmplo.w lr, #-0x80000000    @ 2016509a
        pop.w {r4, lr}    @ 2016509e
        it ne    @ 201650a2
        bxne lr    @ 201650a4
        cmp r0, #0    @ 201650a6
        ite eq    @ 201650a8
        .inst.n 0x1c49    @ 201650aa: addeq r1, r1, #1 (the encoding as in the image: as picks another)
        bicne.w r0, r0, #1    @ 201650ac
        bx lr    @ 201650b0
L_201650b2:
        bhs L_20165116    @ 201650b2
        lsr.w ip, r4, #0xb    @ 201650b4
        adds.w r1, r1, #0x200000    @ 201650b8
        bic.w r4, r4, #0x800    @ 201650bc
        beq L_201650fa    @ 201650c0
        clz.w r2, r1    @ 201650c2
        subs r2, #0xb    @ 201650c6
        subs r4, r4, r2    @ 201650c8
        .inst.n 0x1ea4    @ 201650ca: subs r4, r4, #2 (the encoding as in the image: as picks another)
        rsbs.w r3, r2, #0x20    @ 201650cc
        lsls r1, r2    @ 201650d0
        lsrs.w r3, r0, r3    @ 201650d2
        orrs r1, r3    @ 201650d6
        lsls r0, r2    @ 201650d8
L_201650da:
        add.w r1, r1, ip, lsl #31    @ 201650da
        cmp r4, #0    @ 201650de
        add.w r1, r1, r4, lsl #20    @ 201650e0
        pop.w {r4, lr}    @ 201650e4
        it ge    @ 201650e8
        bxge lr    @ 201650ea
        add.w r1, r1, #0x60000000    @ 201650ec
        mov.w r0, #0    @ 201650f0
        and.w r1, r1, #0x80000000    @ 201650f4
        bx lr    @ 201650f8
L_201650fa:
        clz.w r3, r0    @ 201650fa
        lsls.w r1, r0, r3    @ 201650fe
        bne L_20165106    @ 20165102
        pop {r4, pc}    @ 20165104
L_20165106:
        subs r4, r4, r3    @ 20165106
        subs r4, #0x17    @ 20165108
        lsls r0, r1, #0x15    @ 2016510a
        lsrs r1, r1, #0xb    @ 2016510c
        b L_201650da    @ 2016510e
L_20165110:
        add.w r1, r1, r4, lsl #20    @ 20165110
        pop {r4, pc}    @ 20165114
L_20165116:
        asrs r1, r1, #1    @ 20165116
        add.w r1, r1, r4, lsl #20    @ 20165118
        pop.w {r4, lr}    @ 2016511c
        rrx.w r0, r0    @ 20165120
        b L_2016512c    @ 20165124
L_20165126:
        mov.w r1, #0    @ 20165126
        bx lr    @ 2016512a
L_2016512c:
        lsls r2, r1, #1    @ 2016512c
        it eq    @ 2016512e
        tsteq r0, r0    @ 20165130
        beq L_20165126    @ 20165132
        cmp.w r2, #0x200000    @ 20165134
        it hs    @ 20165138
        bxhs lr    @ 2016513a
        and.w r1, r1, #0x80000000    @ 2016513c
        mov.w r0, #0    @ 20165140
        bx lr    @ 20165144
L_20165146:
        teq.w lr, r4, lsl #21    @ 20165146
        beq L_2016515c    @ 2016514a
        tst.w r1, lr, lsr #1    @ 2016514c
        pop.w {r4, lr}    @ 20165150
        itt eq    @ 20165154
        moveq r1, #0    @ 20165156
        moveq r0, #0    @ 20165158
        bx lr    @ 2016515a
L_2016515c:
        pop.w {r4, lr}    @ 2016515c
        push {r4, r5, r6, lr}    @ 20165160
        bl fp_nan_handler    @ 20165162
        nop    @ 20165166
        .word 0x3ef6df40    @ 20165168
        eor.w r1, r3, #0x80000000    @ 2016516c
        mov r0, r2    @ 20165170
        bx lr    @ 20165172
L_20165174:
        .word 0xffe00000    @ 20165174
        .size __aeabi_dsub, . - __aeabi_dsub
