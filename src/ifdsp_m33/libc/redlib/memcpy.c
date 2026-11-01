/*
 * FT-710 IFDSP M33 (T24): memcpy, the linked entry of the image's C library (NXP Redlib) at 0x872BC: a tail call to the
 * copy loop in memcpy_body.S [fact: 0x872BC is b.w 0x878CC].
 */
#include <stddef.h>

extern void *memcpy_body(void *dst, const void *src, size_t n);

void *memcpy(void *dst, const void *src, size_t n)
{
    return memcpy_body(dst, src, n);
}
