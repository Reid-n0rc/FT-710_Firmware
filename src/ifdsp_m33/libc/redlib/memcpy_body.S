/*
 * FT-710 IFDSP M33 (T24): the memcpy and memset loops of the image's C library (NXP Redlib, closed source; 0x878CC,
 * 0x87900). Hand-written assembly in the original [inference: conditional flag-setting `subshs` inside IT blocks, which
 * GCC does not emit]. The instructions are the image's, in its order [fact: 0x878CC..0x87931]. memcpy copies words
 * when destination and source are both even (`(d | s) & 1`, so a 2-byte aligned pair also takes the word loop), then
 * bytes; memset fills words from a 4-byte aligned start, then bytes. The linked memcpy/memset entries are the
 * tail calls in ../string.c. Open: Redlib's names for these loops; would be settled by the Redlib archive's symbols.
 */
    .syntax unified
    .thumb
    .section .text.memcpy_body,"ax",%progbits
    .p2align 1
    .global memcpy_body
    .type memcpy_body, %function
    .thumb_func
memcpy_body:
    orr.w r3, r0, r1    @ 0x878cc
    lsls r3, r3, #0x1f    @ 0x878d0
    mov r3, r0    @ 0x878d2
    bmi .L878f0    @ 0x878d4
    mov r3, r0    @ 0x878d6
    subs r2, #4    @ 0x878d8
.L878da:
    ittt hs    @ 0x878da
    ldrhs.w ip, [r1], #4    @ 0x878dc
    strhs.w ip, [r3], #4    @ 0x878e0
    subshs.w r2, r2, #4    @ 0x878e4
    bhs .L878da    @ 0x878e8
    adds r2, #4    @ 0x878ea
    it eq    @ 0x878ec
    bxeq lr    @ 0x878ee
.L878f0:
    subs r2, #1    @ 0x878f0
    itt hs    @ 0x878f2
    ldrbhs.w ip, [r1], #1    @ 0x878f4
    strbhs.w ip, [r3], #1    @ 0x878f8
    bhi .L878f0    @ 0x878fc
    bx lr    @ 0x878fe

    .section .text.memset_body,"ax",%progbits
    .p2align 1
    .global memset_body
    .type memset_body, %function
    .thumb_func
memset_body:
    mov r3, r0    @ 0x87900
    tst.w r3, #3    @ 0x87902
    bne .L87926    @ 0x87906
    and.w r1, r1, #0xff    @ 0x87908
    orr.w r1, r1, r1, lsl #8    @ 0x8790c
    orr.w r1, r1, r1, lsl #16    @ 0x87910
    subs r2, #4    @ 0x87914
.L87916:
    itt hs    @ 0x87916
    strhs.w r1, [r3], #4    @ 0x87918
    subshs.w r2, r2, #4    @ 0x8791c
    bhs .L87916    @ 0x87920
    add.w r2, r2, #4    @ 0x87922
.L87926:
    subs r2, #1    @ 0x87926
    itt hs    @ 0x87928
    strbhs.w r1, [r3], #1    @ 0x8792a
    bhs .L87926    @ 0x8792e
    bx lr    @ 0x87930

