/*
 * FT-710 DISPLAY (T24 round 4): the 64-bit divisions of the armcc run-time library, as hand-written assembly.
 *
 * C cannot express these: they return two 64-bit values, the quotient in r0:r1 and the remainder in r2:r3 (RTABI
 * section 4.3.1). The armcc routine is itself hand-written [inference: conditional flag-setting pairs on clz results
 * (rsbsne/rsbseq) and a reciprocal table, which no compiler emits]. The instructions are the image's, in its order,
 * with labels named after their original address; each function is in its own section and is byte-identical to the
 * image when linked at its original address (tools/equiv_display_emu.py, verdict "identical").
 *
 * __aeabi_uldivmod (0x201556E0): normalise the divisor (clz), take a first reciprocal estimate of its top bits from
 * uldivmod_recip, refine it (two steps for a divisor of up to 32 bits, three when the numerator is longer), multiply,
 * then correct the quotient by at most three subtractions [inference: each umull/rsbs/umull group computes
 * x' = x * (2 - d * x), a Newton-Raphson step for 1/d]. Divisor 0 returns quotient 0 and the numerator as remainder
 * [fact: 0x2015596C].
 * __aeabi_ldivmod (0x20154984): signed; negates the negative operands, divides unsigned, then gives the quotient the
 * sign of n XOR d and the remainder the sign of n (truncating division, as C99 requires) [fact: 0x20154988..0x201549DC].
 */
        .syntax unified
        .cpu cortex-a9
        .arm

        .section .text.__aeabi_ldivmod,"ax",%progbits
        .global __aeabi_ldivmod
        .type __aeabi_ldivmod, %function
        .p2align 2
__aeabi_ldivmod:                        @ (r0:r1 n, r2:r3 d) -> r0:r1 n / d, r2:r3 n % d
                                        @ r4 bit 31 = sign of n, bit 30 = sign of n XOR sign of d
        push {r4, lr}    @ 20154984
        asrs r4, r1, #1    @ 20154988
        eor r4, r4, r3, lsr #1    @ 2015498c
        bpl L_201549a0    @ 20154990
        rsbs r0, r0, #0    @ 20154994
        rsb r1, r1, #0    @ 20154998
        sublo r1, r1, #1    @ 2015499c
L_201549a0:
        tst r3, r3    @ 201549a0
        bpl L_201549b4    @ 201549a4
        rsbs r2, r2, #0    @ 201549a8
        rsb r3, r3, #0    @ 201549ac
        sublo r3, r3, #1    @ 201549b0
L_201549b4:
        bl __aeabi_uldivmod    @ 201549b4
        tst r4, #0x40000000    @ 201549b8
        beq L_201549cc    @ 201549bc
        rsbs r0, r0, #0    @ 201549c0
        rsb r1, r1, #0    @ 201549c4
        sublo r1, r1, #1    @ 201549c8
L_201549cc:
        tst r4, #0x80000000    @ 201549cc
        beq L_201549e0    @ 201549d0
        rsbs r2, r2, #0    @ 201549d4
        rsb r3, r3, #0    @ 201549d8
        sublo r3, r3, #1    @ 201549dc
L_201549e0:
        pop {r4, pc}    @ 201549e0
        .size __aeabi_ldivmod, . - __aeabi_ldivmod

        .section .text.__aeabi_uldivmod,"ax",%progbits
        .global __aeabi_uldivmod
        .type __aeabi_uldivmod, %function
        .p2align 2
__aeabi_uldivmod:                       @ (r0:r1 n, r2:r3 d) -> r0:r1 n / d, r2:r3 n % d (unsigned)
        push {r4, r5, r6, lr}    @ 201556e0
        mov r4, r3    @ 201556e4
        mov r5, r2    @ 201556e8
        mov r3, r1    @ 201556ec
        mov r2, r0    @ 201556f0
        cmp r4, #0    @ 201556f4
        movne ip, r4    @ 201556f8
        moveq ip, r5    @ 201556fc
        clz lr, ip    @ 20155700
        add r0, lr, #1    @ 20155704
        lsl ip, ip, r0    @ 20155708
        rsbsne lr, lr, #0x3f    @ 2015570c
        rsbseq lr, lr, #0x1f    @ 20155710
        bmi L_2015596c    @ 20155714
        cmp r3, #0    @ 20155718
        clzne r1, r3    @ 2015571c
        clzeq r1, r2    @ 20155720
        rsbsne r1, r1, #0x3f    @ 20155724
        rsbseq r1, r1, #0x1f    @ 20155728
        subs r6, r1, lr    @ 2015572c
        bmi L_20155980    @ 20155730
        rsbspl r0, r6, #4    @ 20155734
        bpl L_2015598c    @ 20155738
        sub r0, lr, #0x20    @ 2015573c
        cmp r0, #4    @ 20155740
        lsrle r1, r5, r0    @ 20155744
        orrle ip, ip, r1    @ 20155748
        adr r1, uldivmod_recip    @ 2015574c
        lsr ip, ip, #0x1c    @ 20155750
        cmp lr, #0x1f    @ 20155754
        ldr ip, [r1, ip, lsl #2]    @ 20155758
        subhi lr, lr, #0x20    @ 2015575c
        rsb r6, lr, #0x20    @ 20155760
        bhi L_2015588c    @ 20155764
        umull r0, r1, ip, r5    @ 20155768
        lsr r4, r0, lr    @ 2015576c
        lsl r1, r1, r6    @ 20155770
        lsl r0, r0, r6    @ 20155774
        orr r1, r1, r4    @ 20155778
        rsbs r0, r0, #0    @ 2015577c
        rsb r1, r1, #0    @ 20155780
        sublo r1, r1, #1    @ 20155784
        umull r0, r1, ip, r1    @ 20155788
        add ip, ip, r1    @ 2015578c
        umull r0, r1, ip, r5    @ 20155790
        lsr r4, r0, lr    @ 20155794
        lsl r1, r1, r6    @ 20155798
        lsl r0, r0, r6    @ 2015579c
        orr r1, r1, r4    @ 201557a0
        rsbs r0, r0, #0    @ 201557a4
        rsb r1, r1, #0    @ 201557a8
        sublo r1, r1, #1    @ 201557ac
        cmp r3, #0    @ 201557b0
        umull r0, r1, ip, r1    @ 201557b4
        add ip, ip, r1    @ 201557b8
        beq L_201557e8    @ 201557bc
        umull r0, r1, ip, r5    @ 201557c0
        lsr r4, r0, lr    @ 201557c4
        lsl r1, r1, r6    @ 201557c8
        lsl r0, r0, r6    @ 201557cc
        orr r1, r1, r4    @ 201557d0
        rsbs r0, r0, #0    @ 201557d4
        rsb r1, r1, #0    @ 201557d8
        sublo r1, r1, #1    @ 201557dc
        umull r0, r1, ip, r1    @ 201557e0
        add ip, ip, r1    @ 201557e4
L_201557e8:
        umull r1, r0, ip, r2    @ 201557e8
        mov r1, #0    @ 201557ec
        umlal r0, r1, ip, r3    @ 201557f0
        lsr r0, r0, lr    @ 201557f4
        lsl r4, r1, r6    @ 201557f8
        orr r0, r0, r4    @ 201557fc
        lsr r1, r1, lr    @ 20155800
        umull r6, r4, r0, r5    @ 20155804
        subs r2, r2, r6    @ 20155808
        mla r4, r1, r5, r4    @ 2015580c
        sbc r3, r3, r4    @ 20155810
        cmp r3, #1    @ 20155814
        cmplo r2, r5    @ 20155818
        poplo {r4, r5, r6, pc}    @ 2015581c
        umull r4, r6, ip, r2    @ 20155820
        mov r4, #0    @ 20155824
        umlal r6, r4, ip, r3    @ 20155828
        rsb ip, lr, #0x20    @ 2015582c
        lsr r6, r6, lr    @ 20155830
        lsl r3, r4, ip    @ 20155834
        orr r6, r6, r3    @ 20155838
        mov r3, #0    @ 2015583c
        lsr r4, r4, lr    @ 20155840
        umull lr, ip, r6, r5    @ 20155844
        adds r0, r0, r6    @ 20155848
        adc r1, r1, r4    @ 2015584c
        sub r2, r2, lr    @ 20155850
        cmp r2, r5    @ 20155854
        poplo {r4, r5, r6, pc}    @ 20155858
        adds r0, r0, #1    @ 2015585c
        adc r1, r1, #0    @ 20155860
        sub r2, r2, r5    @ 20155864
        subs ip, r2, r5    @ 20155868
        movhs r2, ip    @ 2015586c
        adcs r0, r0, #0    @ 20155870
        adc r1, r1, #0    @ 20155874
        subs ip, r2, r5    @ 20155878
        movhs r2, ip    @ 2015587c
        adcs r0, r0, #0    @ 20155880
        adc r1, r1, #0    @ 20155884
        pop {r4, r5, r6, pc}    @ 20155888
L_2015588c:                             @ divisor longer than 32 bits
        umull r1, r0, ip, r5    @ 2015588c
        mov r1, #0    @ 20155890
        umlal r0, r1, ip, r4    @ 20155894
        lsl r1, r1, r6    @ 20155898
        lsr r6, r0, lr    @ 2015589c
        orr r1, r1, r6    @ 201558a0
        rsb r6, lr, #0x20    @ 201558a4
        rsb r1, r1, #0    @ 201558a8
        lsl r0, r0, r6    @ 201558ac
        rsbs r0, r0, #0    @ 201558b0
        sublo r1, r1, #1    @ 201558b4
        umull r0, r1, ip, r1    @ 201558b8
        add ip, ip, r1    @ 201558bc
        umull r1, r0, ip, r5    @ 201558c0
        mov r1, #0    @ 201558c4
        umlal r0, r1, ip, r4    @ 201558c8
        lsl r1, r1, r6    @ 201558cc
        lsr r6, r0, lr    @ 201558d0
        orr r1, r1, r6    @ 201558d4
        rsb r6, lr, #0x20    @ 201558d8
        rsb r1, r1, #0    @ 201558dc
        lsl r0, r0, r6    @ 201558e0
        rsbs r0, r0, #0    @ 201558e4
        sublo r1, r1, #1    @ 201558e8
        umull r0, r1, ip, r1    @ 201558ec
        add ip, ip, r1    @ 201558f0
        sub ip, ip, #1    @ 201558f4
        umull r1, r0, ip, r2    @ 201558f8
        mov r1, #0    @ 201558fc
        umlal r0, r1, ip, r3    @ 20155900
        lsr r0, r1, lr    @ 20155904
        umull r6, r1, r0, r5    @ 20155908
        subs r2, r2, r6    @ 2015590c
        mla r1, r0, r4, r1    @ 20155910
        sbc r3, r3, r1    @ 20155914
        cmp r3, r4    @ 20155918
        cmpeq r2, r5    @ 2015591c
        movlo r1, #0    @ 20155920
        poplo {r4, r5, r6, pc}    @ 20155924
        umull r6, r1, ip, r2    @ 20155928
        mov r6, #0    @ 2015592c
        umlal r1, r6, ip, r3    @ 20155930
        mov r1, #0    @ 20155934
        lsr r6, r6, lr    @ 20155938
        umull lr, ip, r6, r5    @ 2015593c
        add r0, r0, r6    @ 20155940
        subs r2, r2, lr    @ 20155944
        mla lr, r6, r4, ip    @ 20155948
        sbc r3, r3, lr    @ 2015594c
        cmp r3, r4    @ 20155950
        cmpeq r2, r5    @ 20155954
        poplo {r4, r5, r6, pc}    @ 20155958
        add r0, r0, #1    @ 2015595c
        subs r2, r2, r5    @ 20155960
        sbc r3, r3, r4    @ 20155964
        pop {r4, r5, r6, pc}    @ 20155968
L_2015596c:                             @ divisor 0: quotient 0, remainder = numerator (the nop stands where an __aeabi_ldiv0 call could be)
        push {r2, r3}    @ 2015596c
        mov r1, #0    @ 20155970
        mov r0, #0    @ 20155974
        mov r0, r0    @ 20155978
        pop {r2, r3, r4, r5, r6, pc}    @ 2015597c
L_20155980:                             @ divisor longer than the numerator: quotient 0, remainder = numerator
        mov r1, #0    @ 20155980
        mov r0, #0    @ 20155984
        pop {r4, r5, r6, pc}    @ 20155988
L_2015598c:                             @ lengths differ by 4 bits or less: shift and subtract, one bit per pass
        rsb lr, r6, #0x20    @ 2015598c
        mov r0, #0    @ 20155990
        mov r1, #0    @ 20155994
        lsl r4, r4, r6    @ 20155998
        lsr ip, r5, lr    @ 2015599c
        lsl r5, r5, r6    @ 201559a0
        orr r4, r4, ip    @ 201559a4
L_201559a8:
        subs lr, r2, r5    @ 201559a8
        sbcs ip, r3, r4    @ 201559ac
        adc r0, r0, r0    @ 201559b0
        movhs r3, ip    @ 201559b4
        movhs r2, lr    @ 201559b8
        subs r6, r6, #1    @ 201559bc
        poplo {r4, r5, r6, pc}    @ 201559c0
        lsrs r4, r4, #1    @ 201559c4
        rrx r5, r5    @ 201559c8
        b L_201559a8    @ 201559cc
uldivmod_recip:                         @ 2^32 / (1 + k/16), k = the 4 bits after the leading 1 of the divisor
        .word 0xf0f0f0f0    @ 201559d0
        .word 0xe38e38e3    @ 201559d4
        .word 0xd79435e5    @ 201559d8
        .word 0xcccccccc    @ 201559dc
        .word 0xc30c30c3    @ 201559e0
        .word 0xba2e8ba2    @ 201559e4
        .word 0xb21642c8    @ 201559e8
        .word 0xaaaaaaaa    @ 201559ec
        .word 0xa3d70a3d    @ 201559f0
        .word 0x9d89d89d    @ 201559f4
        .word 0x97b425ed    @ 201559f8
        .word 0x92492492    @ 201559fc
        .word 0x8d3dcb08    @ 20155a00
        .word 0x88888888    @ 20155a04
        .word 0x84210842    @ 20155a08
        .word 0x80000000    @ 20155a0c
        .size __aeabi_uldivmod, . - __aeabi_uldivmod

/*
 * _ll_udiv10 (0x20155A10), moved here from lib/aeabi_div.c in T24 round 6: it returns the quotient n / 10 in r0:r1
 * and also the remainder in r2 (r3 = 0), which C cannot express, and the C library relies on it: _fp_digits adds
 * '0' to r2 right after the call (0x20155C8A, 0x20155CBA) [fact]. The C version returned only r0:r1; the check
 * compared only those, and the emulated boot of the hybrid image (tools/display_boot_emu.py) found the difference: a
 * snprintf of vk_key_name never ended. q = n - n/4 + ... >> 3 by shifts and adds, r = n - 10 q, one correction.
 */
        .section .text._ll_udiv10,"ax",%progbits
        .global _ll_udiv10
        .type _ll_udiv10, %function
        .p2align 2
_ll_udiv10:                             @ (r0:r1 n) -> r0:r1 n / 10, r2 n % 10, r3 0
        push {r4, r5, lr}    @ 20155a10
        subs r2, r0, #0xa    @ 20155a14
        lsr lr, r0, #2    @ 20155a18
        sbcs r3, r1, #0    @ 20155a1c
        orr lr, lr, r1, lsl #30    @ 20155a20
        subs r0, r0, lr    @ 20155a24
        sbc r1, r1, r1, lsr #2    @ 20155a28
        lsr lr, r0, #4    @ 20155a2c
        orr lr, lr, r1, lsl #28    @ 20155a30
        adds r0, r0, lr    @ 20155a34
        adc r1, r1, r1, lsr #4    @ 20155a38
        lsr lr, r0, #8    @ 20155a3c
        orr lr, lr, r1, lsl #24    @ 20155a40
        adds r0, r0, lr    @ 20155a44
        adc r1, r1, r1, lsr #8    @ 20155a48
        lsr lr, r0, #0x10    @ 20155a4c
        orr lr, lr, r1, lsl #16    @ 20155a50
        adds r0, r0, lr    @ 20155a54
        adc r1, r1, r1, lsr #16    @ 20155a58
        adds r0, r0, r1    @ 20155a5c
        adc r1, r1, #0    @ 20155a60
        lsr r0, r0, #3    @ 20155a64
        orr r0, r0, r1, lsl #29    @ 20155a68
        lsr r1, r1, #3    @ 20155a6c
        adds r5, r0, r0, lsl #2    @ 20155a70
        lsl r4, r1, #2    @ 20155a74
        orr r4, r4, r0, lsr #30    @ 20155a78
        adc r4, r4, r1    @ 20155a7c
        adds r5, r5, r5    @ 20155a80
        adc r4, r4, r4    @ 20155a84
        subs r2, r2, r5    @ 20155a88
        sbcs r3, r3, r4    @ 20155a8c
        mov r3, #0    @ 20155a90
        addmi r2, r2, #0xa    @ 20155a94
        popmi {r4, r5, pc}    @ 20155a98
        adds r0, r0, #1    @ 20155a9c
        adc r1, r1, #0    @ 20155aa0
        pop {r4, r5, pc}    @ 20155aa4
        .size _ll_udiv10, . - _ll_udiv10
