/*
 * FT-710 IFDSP M33 (T24): __aeabi_uldivmod and its helper, recreated from the image (NXP Redlib, closed source;
 * 0x87756..0x878CB). Hand-written assembly in the original [inference: flag tricks no compiler emits (`movs.w ip, #0`
 * before the push, `adcs` shift-subtract steps), and a sign fix-up tail driven by ip that only a signed entry
 * (__aeabi_ldivmod, not linked here) would use]. The instructions are the image's, in its order [fact: 0x87756];
 * local labels carry their original addresses. The helper divides r1:r0 by r2 (byte steps while r1 < r2 >> 8, then
 * bit steps) [fact: 0x87850]. Open: Redlib's name for the helper; would be settled by the Redlib archive's symbol table.
 */
    .syntax unified
    .thumb
    .section .text.__aeabi_uldivmod,"ax",%progbits
    .p2align 1
    .global __aeabi_uldivmod
    .type __aeabi_uldivmod, %function
    .thumb_func
__aeabi_uldivmod:
    movs.w ip, #0    @ 0x87756
    push {r4, r5, lr}    @ 0x8775a
    movs r4, r3    @ 0x8775c
    bne .L877a6    @ 0x8775e
    movs r2, r2    @ 0x87760
    beq .L87844    @ 0x87762
    cmp r1, r2    @ 0x87764
    blo .L87776    @ 0x87766
    mov r5, r0    @ 0x87768
    mov r0, r1    @ 0x8776a
    movs r1, #0    @ 0x8776c
    bl udiv64by32_helper    @ 0x8776e
    mov r4, r0    @ 0x87772
    mov r0, r5    @ 0x87774
.L87776:
    bl udiv64by32_helper    @ 0x87776
    mov r2, r1    @ 0x8777a
    mov r1, r4    @ 0x8777c
.L8777e:
    pop.w {r4, r5, lr}    @ 0x8777e
    tst.w ip, #-0x40000000    @ 0x87782
    it eq    @ 0x87786
    bxeq lr    @ 0x87788
    bpl .L87794    @ 0x8778a
    rsbs r1, r1, #0    @ 0x8778c
    rsbs r0, r0, #0    @ 0x8778e
    sbc.w r1, r1, #0    @ 0x87790
.L87794:
    lsls.w ip, ip, #2    @ 0x87794
    it lo    @ 0x87798
    bxlo lr    @ 0x8779a
    rsbs r3, r3, #0    @ 0x8779c
    rsbs r2, r2, #0    @ 0x8779e
    sbc.w r3, r3, #0    @ 0x877a0
    bx lr    @ 0x877a4
.L877a6:
    bmi .L8782e    @ 0x877a6
    lsrs r4, r3, #0x10    @ 0x877a8
    itt eq    @ 0x877aa
    lsleq r3, r3, #0x10    @ 0x877ac
    addeq.w ip, ip, #0x10    @ 0x877ae
    tst.w r3, #-0x1000000    @ 0x877b2
    itt eq    @ 0x877b6
    lsleq r3, r3, #8    @ 0x877b8
    addeq.w ip, ip, #8    @ 0x877ba
    tst.w r3, #-0x10000000    @ 0x877be
    itt eq    @ 0x877c2
    lsleq r3, r3, #4    @ 0x877c4
    addeq.w ip, ip, #4    @ 0x877c6
    tst.w r3, #-0x40000000    @ 0x877ca
    itt eq    @ 0x877ce
    addeq.w ip, ip, #2    @ 0x877d0
    lslseq.w r3, r3, #2    @ 0x877d4
    itt pl    @ 0x877d8
    addpl.w ip, ip, #1    @ 0x877da
    lslpl r3, r3, #1    @ 0x877de
    rsb.w lr, ip, #0x20    @ 0x877e0
    lsr.w r4, r2, lr    @ 0x877e4
    orrs r3, r4    @ 0x877e8
    lsl.w r2, r2, ip    @ 0x877ea
    lsl.w r5, r0, ip    @ 0x877ee
    lsr.w r0, r0, lr    @ 0x877f2
    lsl.w r4, r1, ip    @ 0x877f6
    orrs r0, r4    @ 0x877fa
    lsr.w r1, r1, lr    @ 0x877fc
    mov r4, r2    @ 0x87800
    mov r2, r3    @ 0x87802
    bl udiv64by32_helper    @ 0x87804
    umull.w r2, r3, r4, r0    @ 0x87808
    subs r2, r5, r2    @ 0x8780c
    sbcs.w r3, r1, r3    @ 0x8780e
    itt lo    @ 0x87812
    addlo r3, r3, r4    @ 0x87814
    sublo r0, #1    @ 0x87816
    rsb.w lr, ip, #0x20    @ 0x87818
    lsr.w r2, r2, ip    @ 0x8781c
    lsl.w r4, r3, lr    @ 0x87820
    orrs r2, r4    @ 0x87824
    lsr.w r3, r3, ip    @ 0x87826
    movs r1, #0    @ 0x8782a
    b .L8777e    @ 0x8782c
.L8782e:
    subs r2, r0, r2    @ 0x8782e
    sbcs.w r3, r1, r3    @ 0x87830
    itt lo    @ 0x87834
    movlo r2, r0    @ 0x87836
    movlo r3, r1    @ 0x87838
    mov.w r1, #0    @ 0x8783a
    adc.w r0, r1, #0    @ 0x8783e
    b .L8777e    @ 0x87842
.L87844:
    movs r0, #0    @ 0x87844
    movs r1, #0    @ 0x87846
    pop.w {r4, r5, lr}    @ 0x87848
    b.w .L878ca    @ 0x8784c

    .global udiv64by32_helper
    .type udiv64by32_helper, %function
    .thumb_func
udiv64by32_helper:
    movs r3, #4    @ 0x87850
    cmp.w r1, r2, lsr #8    @ 0x87852
    bhs .L8786c    @ 0x87856
.L87858:
    lsls r1, r1, #8    @ 0x87858
    orr.w r1, r1, r0, lsr #24    @ 0x8785a
    lsls r0, r0, #8    @ 0x8785e
    subs r3, #1    @ 0x87860
    it eq    @ 0x87862
    bxeq lr    @ 0x87864
    cmp.w r1, r2, lsr #8    @ 0x87866
    blo .L87858    @ 0x8786a
.L8786c:
    adds r0, r0, r0    @ 0x8786c
.L8786e:
    adcs r1, r1    @ 0x8786e
    ite lo    @ 0x87870
    cmplo r1, r2    @ 0x87872
    subhs r1, r1, r2    @ 0x87874
    adcs r0, r0    @ 0x87876
    adcs r1, r1    @ 0x87878
    ite lo    @ 0x8787a
    cmplo r1, r2    @ 0x8787c
    subhs r1, r1, r2    @ 0x8787e
    adcs r0, r0    @ 0x87880
    adcs r1, r1    @ 0x87882
    ite lo    @ 0x87884
    cmplo r1, r2    @ 0x87886
    subhs r1, r1, r2    @ 0x87888
    adcs r0, r0    @ 0x8788a
    adcs r1, r1    @ 0x8788c
    ite lo    @ 0x8788e
    cmplo r1, r2    @ 0x87890
    subhs r1, r1, r2    @ 0x87892
    adcs r0, r0    @ 0x87894
    adcs r1, r1    @ 0x87896
    ite lo    @ 0x87898
    cmplo r1, r2    @ 0x8789a
    subhs r1, r1, r2    @ 0x8789c
    adcs r0, r0    @ 0x8789e
    adcs r1, r1    @ 0x878a0
    ite lo    @ 0x878a2
    cmplo r1, r2    @ 0x878a4
    subhs r1, r1, r2    @ 0x878a6
    adcs r0, r0    @ 0x878a8
    adcs r1, r1    @ 0x878aa
    ite lo    @ 0x878ac
    cmplo r1, r2    @ 0x878ae
    subhs r1, r1, r2    @ 0x878b0
    adcs r0, r0    @ 0x878b2
    adcs r1, r1    @ 0x878b4
    ite lo    @ 0x878b6
    cmplo r1, r2    @ 0x878b8
    subhs r1, r1, r2    @ 0x878ba
    adcs r0, r0    @ 0x878bc
    sub.w r3, r3, #1    @ 0x878be
    tst.w r3, #0xf    @ 0x878c2
    bne .L8786e    @ 0x878c6
    bx lr    @ 0x878c8
.L878ca:
    bx lr    @ 0x878ca

