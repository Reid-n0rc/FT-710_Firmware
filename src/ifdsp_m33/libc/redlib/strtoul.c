/*
 * FT-710 IFDSP M33 (T24): strtoul, recreated from the image's C library (NXP Redlib, closed source) at 0x85CC0.
 * Sign, then _strtoul_core; errno is restored unless the core set ERANGE; a negated value above LONG_MAX gives ULONG_MAX and ERANGE [fact: 0x85CC0].
 */
#include "ctype.h"

extern int errno;
extern unsigned long _strtoul_core(const char *nptr, const char **endptr, unsigned int base);

unsigned long strtoul(const char *nptr, char **endptr, int base)
{
    int saved = errno;
    const unsigned char *s = (const unsigned char *)nptr;
    const char *end;
    unsigned int c;
    int neg;
    long v;

    do
    {
        c = *s++;
        if (c == 0)
        {
            neg = 0;
            s--;
            goto core;
        }
        neg = redlib_ctype_table[c] & _CT_SPACE;
    } while (neg);
    if (c != '+')
    {
        if (c == '-')
        {
            neg = 0x200;
        }
        else
        {
            neg = 0;
            s--;
        }
    }
core:
    errno = 0;
    v     = (long)_strtoul_core((const char *)s, &end, (unsigned int)base);
    if (endptr != 0)
    {
        *endptr = (char *)((end != (const char *)s) ? end : nptr);
    }
    if (errno != 34)
    {
        errno = saved;
        if (neg)
        {
            if (v < 0)
            {
                v     = -1;
                errno = 34;
            }
            else
            {
                v = -v;
            }
        }
    }
    return (unsigned long)v;
}
