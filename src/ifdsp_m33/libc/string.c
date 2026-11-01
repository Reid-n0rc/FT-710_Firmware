/*
 * FT-710 IFDSP M33 (T24): the string functions the image uses, written for the same results as the image's C
 * library (NXP Redlib, closed source). The string functions are not byte-identical and are checked by differential
 * emulation (tools/equiv_m33_emu.py). memcpy and memset: redlib/memcpy.c, redlib/memset.c.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

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

size_t strlen(const char *s)
{
    const char *p = s;

    while (*p)
    {
        p++;
    }
    return (size_t)(p - s);
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
