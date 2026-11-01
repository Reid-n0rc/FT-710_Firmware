/*
 * FT-710 IFDSP M33 (T24): strtoul, written for the same results as the image's C library (NXP Redlib, closed source;
 * the image has strtoul 0x85CC0 on a core 0x85C0C and a digit-value helper 0x85BDC). Not byte-identical.
 */
#include <limits.h>
#include <stdlib.h>
#include "ctype.h"

static int digit_value(int c)
{
    if (isdigit(c))
    {
        return c - '0';
    }
    if (isupper(c))
    {
        return c - 'A' + 10;
    }
    if (islower(c))
    {
        return c - 'a' + 10;
    }
    return 99;
}

unsigned long strtoul(const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long v = 0;
    int neg = 0, any = 0, overflow = 0;

    while (isspace(*s))
    {
        s++;
    }
    if (*s == '-' || *s == '+')
    {
        neg = (*s++ == '-');
    }
    if ((base == 0 || base == 16) && s[0] == '0' && (s[1] == 'x' || s[1] == 'X') && digit_value(s[2]) < 16)
    {
        s += 2;
        base = 16;
    }
    else if (base == 0)
    {
        base = (s[0] == '0') ? 8 : 10;
    }
    for (;; s++)
    {
        int d = digit_value((unsigned char)*s);
        if (d >= base)
        {
            break;
        }
        any = 1;
        if (v > (ULONG_MAX - (unsigned long)d) / (unsigned long)base)
        {
            overflow = 1;
        }
        v = v * (unsigned long)base + (unsigned long)d;
    }
    if (endptr)
    {
        *endptr = (char *)(any ? s : nptr);
    }
    if (overflow)
    {
        /* Open: whether Redlib also sets errno here; would be settled by emulating 0x85CC0 with an overflowing input */
        return ULONG_MAX;
    }
    return neg ? -v : v;
}
