/*
 * FT-710 IFDSP M33 (T24): the string functions the image uses, written for the same results as the image's C
 * library (NXP Redlib, closed source; not byte-identical). Checked by differential emulation (tools/equiv_m33_emu.py).
 * The image reaches memcpy and memset through two 4-byte entries (0x872BC, 0x872C0: b.w to the bodies at 0x878CC and
 * 0x87900) [fact]; here each is one function.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void *memcpy(void *dst, const void *src, size_t n)
{
    uint8_t *d       = dst;
    const uint8_t *s = src;

    /* word copy when both are word aligned, as the image's body does [fact: 0x878CC] */
    if ((((uintptr_t)d | (uintptr_t)s) & 1U) == 0U)
    {
        for (; n >= 4U; n -= 4U, d += 4, s += 4)
        {
            *(uint32_t *)d = *(const uint32_t *)s;
        }
    }
    while (n--)
    {
        *d++ = *s++;
    }
    return dst;
}

void *memset(void *dst, int c, size_t n)
{
    uint8_t *d = dst;

    if (((uintptr_t)d & 3U) == 0U)
    {
        uint32_t w = (uint8_t)c;
        w |= w << 8;
        w |= w << 16;
        for (; n >= 4U; n -= 4U, d += 4)
        {
            *(uint32_t *)d = w;
        }
    }
    while (n--)
    {
        *d++ = (uint8_t)c;
    }
    return dst;
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
