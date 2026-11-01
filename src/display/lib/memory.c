/*
 * FT-710 DISPLAY (T24 round 3): the memory functions of the image's armcc C library, recreated in C. armcc's versions
 * are hand-scheduled (32-byte LDM/STM blocks, PLD, shift-merge loops for misaligned sources); the C here writes the same
 * bytes, which is what the differential emulation compares (tools/equiv_display_emu.py).
 *
 * All of them are the run-time ABI entry points (ARM IHI 0043, "__aeabi_memcpy" & co.: void, (dst, n, c) argument
 * order for memset). The image's 0x20155180, which Ghidra calls memcpy, is one of them too: it returns with r0 at the
 * end of the destination, not at its start [fact: its exits 0x20155180..0x20155253 return the advanced pointers], so
 * it is the void __aeabi_memcpy (= armcc __rt_memcpy) [inference: the AEABI entry has that contract; C memcpy must
 * return dst]. src/display/aliases.tsv maps the name.
 */
#include <stddef.h>
#include <stdint.h>

/* 0x20155180 (A32): any alignment */
void __aeabi_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d       = dst;
    const unsigned char *s = src;

    while (n-- != 0)
    {
        *d++ = *s++;
    }
}

/* 0x20155310 (A32): word-aligned dst and src */
void __aeabi_memcpy4(void *dst, const void *src, size_t n)
{
    __aeabi_memcpy(dst, src, n);
}

/* 0x2015525C (Thumb): (dst, n, c) */
void __aeabi_memset(void *dst, size_t n, int c)
{
    unsigned char *d = dst;

    while (n-- != 0)
    {
        *d++ = (unsigned char)c;
    }
}

/* 0x20155274 (Thumb) */
void __aeabi_memclr(void *dst, size_t n)
{
    __aeabi_memset(dst, n, 0);
}

/* 0x201552C0 (Thumb): word-aligned dst */
void __aeabi_memclr4(void *dst, size_t n)
{
    __aeabi_memset(dst, n, 0);
}
