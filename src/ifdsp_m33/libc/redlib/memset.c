/*
 * FT-710 IFDSP M33 (T24): memset, the linked entry of the image's C library (NXP Redlib) at 0x872C0: a tail call to the
 * fill loop in memcpy_body.S [fact: 0x872C0 is b.w 0x87900].
 */
#include <stddef.h>

extern void *memset_body(void *dst, int c, size_t n);

void *memset(void *dst, int c, size_t n)
{
    return memset_body(dst, c, n);
}
