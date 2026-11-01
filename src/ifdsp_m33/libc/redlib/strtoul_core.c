/*
 * FT-710 IFDSP M33 (T24): _strtoul_core, recreated from the image's C library (NXP Redlib, closed source) at 0x85C0C.
 * Skips white space, takes a 0x/0 prefix, accumulates in two 16-bit halves so that overflow can be seen; on overflow ULONG_MAX and errno 34 (ERANGE) [fact: 0x85C0C].
 */
#include "ctype.h"

extern int errno;
extern int _Cdigit_value(int c, int base);

unsigned long _strtoul_core(const char *nptr, const char **endptr, unsigned int base)
{
    const unsigned char *s = (const unsigned char *)nptr;
    unsigned int c;
    unsigned int lo;
    unsigned int hi;
    int any;
    int overflow;
    int d;

    do
    {
        c = *s++;
        if (c == 0)
        {
            goto nobase;
        }
    } while (redlib_ctype_table[c] & _CT_SPACE);
    if (c == '0')
    {
        c = *s++;
        if ((c & 0xDFu) == 'X')
        {
            if ((base & ~16u) == 0)
            {
                base = 16;
                c    = *s++;
                any  = 0;
            }
            else
            {
                any = 1;
            }
        }
        else
        {
            any = 1;
            if (base == 0)
            {
                base = 8;
            }
        }
    }
    else
    {
    nobase:
        if (base == 0)
        {
            base = 10;
        }
        any = 0;
    }
    lo       = 0;
    hi       = 0;
    overflow = 0;
    while ((d = _Cdigit_value((int)c, (int)base)) >= 0)
    {
        lo = lo * base + (unsigned int)d;
        hi = hi * base + (lo >> 16);
        if (hi > 0xFFFFu)
        {
            overflow = 1;
        }
        any = 1;
        c   = *s++;
        lo &= 0xFFFFu;
    }
    if (any)
    {
        nptr = (const char *)s - 1;
    }
    *endptr = nptr;
    if (overflow)
    {
        errno = 34;
        return 0xFFFFFFFFu;
    }
    return lo | (hi << 16);
}
