/*
 * FT-710 IFDSP M33 (T24): the string functions the image uses, written for the same results as the image's C
 * library (NXP Redlib, closed source). The string functions are not byte-identical and are checked by differential
 * emulation (tools/equiv_m33_emu.py). memcpy and memset are the image's two 4-byte entries (0x872BC, 0x872C0: b.w to
 * the loops at 0x878CC and 0x87900, recreated in redlib/memcpy_body.S) [fact].
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

extern void *memcpy_body(void *dst, const void *src, size_t n);
extern void *memset_body(void *dst, int c, size_t n);

/* The linked entry: a tail call to the copy loop (memcpy_body.S) [fact: 0x872BC is b.w 0x878CC]. */
void *memcpy(void *dst, const void *src, size_t n)
{
    return memcpy_body(dst, src, n);
}

/* The linked entry: a tail call to the fill loop [fact: 0x872C0 is b.w 0x87900]. */
void *memset(void *dst, int c, size_t n)
{
    return memset_body(dst, c, n);
}

size_t strlen(const char *s)
{
    const char *p = s;

    while (*p)
    {
        p++;
    }
    return (size_t)(p - s);
}

int strcmp(const char *a, const char *b)
{
    unsigned char ca, cb;

    do
    {
        ca = (unsigned char)*a++;
        cb = (unsigned char)*b++;
    } while (ca == cb && ca != 0);
    return ca - cb;
}

int strncmp(const char *a, const char *b, size_t n)
{
    for (; n != 0; n--)
    {
        unsigned char ca = (unsigned char)*a++;
        unsigned char cb = (unsigned char)*b++;
        if (ca != cb)
        {
            return ca - cb;
        }
        if (ca == 0)
        {
            break;
        }
    }
    return 0;
}

char *strncpy(char *dst, const char *src, size_t n)
{
    char *d = dst;

    for (; n != 0 && *src; n--)
    {
        *d++ = *src++;
    }
    for (; n != 0; n--)
    {
        *d++ = 0;
    }
    return dst;
}
