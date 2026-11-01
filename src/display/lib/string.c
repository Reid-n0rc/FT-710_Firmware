/*
 * FT-710 DISPLAY (T24 round 3): the string functions of the image's C library (armcc, ARM Compiler 5 C library;
 * docs/code/display/boot-rtos.md "C library string helpers"), recreated in C from the image. armcc's library has
 * word-at-a-time versions of some (strlen, strcpy, memcmp: aligned words, uqsub8 zero test); the C here gives the same
 * results and writes the same bytes, which is what the differential emulation checks (tools/equiv_display_emu.py), and
 * keeps the one place where the result depends on the path: memcmp returns -1/1 from the word loop and the byte
 * difference from the byte loop.
 *
 * Instruction sets [fact: src/display/modes.tsv]: strcpy, strlen, memcmp, strstr and tolower are Thumb in the image,
 * the others A32; all are built A32 here (the harness enters each in its own mode).
 */
#include <stddef.h>
#include <stdint.h>

/* armcc's ctype table accessor: returns a pointer to the pointer to the class table [fact: tolower 0x201549E4 reads
 * *(*__rt_ctype_table() + c)] */
extern const unsigned char **__rt_ctype_table(void);

/* bit 0x10 of the class byte = upper case [fact: tolower 0x201549E4 tests it (lsl #27)] */
int tolower(int c)
{
    return ((*__rt_ctype_table())[c] & 0x10) ? c + 0x20 : c;
}

/* strcasecmp 0x2014E208: compares tolower() of each byte (as unsigned char), stops after the NUL [fact] */
int strcasecmp(const char *a, const char *b)
{
    unsigned int ca, cb;

    do
    {
        unsigned char nb = (unsigned char)*b++;
        ca = (unsigned char)tolower((unsigned char)*a++);
        cb = (unsigned char)tolower(nb);
        if (ca != cb)
        {
            return (int)(ca - cb);
        }
    } while (ca != 0);
    return 0;
}

/* strncasecmp 0x2014E250 [fact] */
int strncasecmp(const char *a, const char *b, size_t n)
{
    while (n-- != 0)
    {
        unsigned char nb = (unsigned char)*b++;
        unsigned int ca = (unsigned char)tolower((unsigned char)*a++);
        unsigned int cb = (unsigned char)tolower(nb);
        if (ca != cb)
        {
            return (int)(ca - cb);
        }
        if (ca == 0)
        {
            return 0;
        }
    }
    return 0;
}

/* strncmp 0x2014E2A4 [fact] */
int strncmp(const char *a, const char *b, size_t n)
{
    while (n-- != 0)
    {
        unsigned int ca = (unsigned char)*a;
        if ((unsigned char)*b != ca)
        {
            return (int)(ca - (unsigned char)*b);
        }
        if (ca == 0)
        {
            return 0;
        }
        a++;
        b++;
    }
    return 0;
}

/* strncpy 0x2014E2E4: copies up to n bytes, pads the rest of n with NUL, returns dst [fact] */
char *strncpy(char *dst, const char *src, size_t n)
{
    char *d = dst;

    while (n != 0)
    {
        char c = *src++;
        *d++ = c;
        n--;
        if (c == 0)
        {
            while (n != 0)
            {
                *d++ = 0;
                n--;
            }
            break;
        }
    }
    return dst;
}

/* strtok_r 0x2014E320: (s, delims, &save): skips leading delimiters, cuts the token at the next one, 0 at the end; save
 * is 0 after the last token [fact] */
char *strtok_r(char *s, const char *delims, char **save)
{
    if (s == NULL && (s = *save) == NULL)
    {
        return NULL;
    }
    for (; *s != 0; s++)
    {
        const char *d;
        for (d = delims; *d != 0 && *d != *s; d++)
        {
        }
        if (*d == 0)
        {
            /* s starts a token: find its end */
            char *e = s;
            for (;;)
            {
                for (d = delims; *d != *e && *d != 0; d++)
                {
                }
                if (*d == *e)
                {
                    break; /* a delimiter, or the NUL (which matches the delimiter list's end) */
                }
                e++;
            }
            if (*e == 0)
            {
                *save = NULL;
            }
            else
            {
                *e    = 0;
                *save = e + 1;
            }
            return s;
        }
    }
    *save = NULL;
    return NULL;
}

/* strstr 0x20155058 (Thumb) [fact] */
char *strstr(const char *hay, const char *needle)
{
    for (;; hay++)
    {
        const char *h = hay, *n = needle;
        while (*n != 0 && *h == *n)
        {
            h++;
            n++;
        }
        if (*n == 0)
        {
            return (char *)hay;
        }
        if (*h == 0)
        {
            return NULL;
        }
    }
}

/* memcmp 0x2015507C (Thumb): when both pointers are word-aligned, compares words while n >= 4 and returns -1 or 1
 * from the big-endian order of the first differing word; the rest byte by byte, returning the difference [fact] */
int memcmp(const void *pa, const void *pb, size_t n)
{
    const unsigned char *a = pa, *b = pb;

    if ((((uintptr_t)a | (uintptr_t)b) & 3) == 0)
    {
        while (n > 3)
        {
            uint32_t wa = *(const uint32_t *)a, wb = *(const uint32_t *)b;
            a += 4;
            b += 4;
            n -= 4;
            if (wa != wb)
            {
                return __builtin_bswap32(wa) <= __builtin_bswap32(wb) ? -1 : 1;
            }
        }
    }
    while (n != 0)
    {
        int d = (int)*a++ - (int)*b++;
        if (d != 0)
        {
            return d;
        }
        n--;
    }
    return 0;
}

/* strcpy 0x201550DC (Thumb) */
char *strcpy(char *dst, const char *src)
{
    char *d = dst;

    while ((*d++ = *src++) != 0)
    {
    }
    return dst;
}

/* strlen 0x20155122 (Thumb) */
size_t strlen(const char *s)
{
    const char *p = s;

    while (*p != 0)
    {
        p++;
    }
    return (size_t)(p - s);
}

/* strcat 0x2015515C */
char *strcat(char *dst, const char *src)
{
    char *d = dst;

    while (*d != 0)
    {
        d++;
    }
    while ((*d++ = *src++) != 0)
    {
    }
    return dst;
}

/* rrx: r0 = C:r0 >> 1, the last step of the image's strcmp word path */
static int rrx(uint32_t v, int carry)
{
    return (int)((uint32_t)carry << 31 | v >> 1);
}

/* strcmp 0x2015538C (A32). When a and b have the same alignment, the image compares bytes up to a word boundary,
 * then words while neither has a zero byte ((w - 0x01010101) & ~w & 0x80808080, literal 0x2015547C) and they are
 * equal; the result of the word path is not a byte difference but rrx(b' - a') of the first differing byte and the
 * bytes below it, shifted to the top (b' >= a' gives the carry), so negative when a < b [fact: 0x201553EC..0x20155448].
 * The byte paths return a - b [fact: 0x20155474]. */
int strcmp(const char *pa, const char *pb)
{
    const unsigned char *a = (const unsigned char *)pa, *b = (const unsigned char *)pb;
    unsigned int ca, cb;

    if ((((uintptr_t)a ^ (uintptr_t)b) & 3) == 0)
    {
        while ((uintptr_t)a & 3)
        {
            ca = *a++;
            cb = *b++;
            if (ca == 0 || ca != cb)
            {
                return (int)(ca - cb);
            }
        }
        uint32_t wa, wb, zero;
        do
        {
            wa = *(const uint32_t *)a;
            wb = *(const uint32_t *)b;
            a += 4;
            b += 4;
            zero = (wa - 0x01010101U) & ~wa & 0x80808080U;
        } while (zero == 0 && wa == wb);
        static const uint32_t zmask[3] = {0xFF0U, 0xFF00U, 0xFF0000U};
        for (int i = 0; i < 3; i++)
        {
            int sh   = 24 - 8 * i;
            uint32_t x = wb << sh, y = wa << sh;
            if (x != y)
            {
                return rrx(x - y, x >= y);
            }
            if (zero & zmask[i])
            {
                return 0;
            }
        }
        return wa == wb ? 0 : rrx(wb - wa, wb >= wa);
    }
    do
    {
        ca = *a++;
        cb = *b++;
    } while (ca != 0 && ca == cb);
    return (int)(ca - cb);
}
