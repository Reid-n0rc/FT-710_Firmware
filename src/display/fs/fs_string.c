/*
 * FT-710 DISPLAY (T24 round 9): the file-system layer's byte, string and character-set helpers,
 * 0x2014CA90..0x2014D95B. Recreated from the image's disassembly (decomp/display/2014aec8_2014d38c.c and
 * 2014d3f8_2014e178.c for the shapes).
 *
 * The layer keeps its own copies of the C library string functions (case-insensitive compares, Shift-JIS aware
 * variants, UTF-16 variants) and of the little-endian field accessors of the on-disk structures. Its chars are
 * signed (include/fs.h).
 */
#include "fs.h"

extern const uint16_t sjis_ucs2_81[];   /* 0x20420756: UTF-16 of Shift-JIS 0x8140.. (lead bytes 0x81..0x9F) */
extern const uint16_t sjis_ucs2_e0[];   /* 0x204244D0: UTF-16 of Shift-JIS 0xE040.. (lead bytes 0xE0..0xFC) */
uint32_t __aeabi_uidivmod(uint32_t n, uint32_t d);

/* 0x2014CA90: 1 for a Shift-JIS lead byte, 0x81..0x9F or 0xE0..0xFC [fact] */
int sjis_is_lead(int c)
{
    return (unsigned)(c - 0x81) < 0x1F || (unsigned)(c - 0xE0) < 0x1D;
}

/* 0x2014CAB8: one Shift-JIS character to UTF-16 in the layer's byte order (high byte first in memory, so the
 * value is byte-swapped): printable ASCII as it is, '\' as U+00A5 (the yen sign of JIS X 0201), half-width kana
 * 0xA1..0xDF as U+FF61.., double-byte characters through the two tables; 0xFFFF for anything else [fact] */
uint32_t sjis_to_ucs2_char(const uint8_t *s)
{
    uint32_t c = s[0];

    if (c - 0x20 <= 0x5E)
    {
        return c == 0x5C ? 0xA500 : (c << 8) & 0xFF00;
    }
    if (c - 0x81 <= 0x1E)
    {
        uint32_t u = sjis_ucs2_81[(uint16_t)(s[1] + (c << 8) - 0x8140)];
        return (uint16_t)((u << 8) + (u >> 8));
    }
    if (c - 0xA1 <= 0x3E)
    {
        uint32_t u = (uint16_t)(c + 0xFEC0);
        return (uint16_t)(((u << 8) & 0xFF00) + (u >> 8));
    }
    if (c - 0xE0 <= 0x1C)
    {
        uint32_t u = sjis_ucs2_e0[(uint16_t)(s[1] + (c << 8) - 0xE040)];
        return (uint16_t)((u << 8) + (u >> 8));
    }
    return 0xFFFF;
}

/* 0x2014CB84: a Shift-JIS string to UTF-16 (sjis_to_ucs2_char per character), 0-terminated; returns its length in
 * characters, -99 at a character without a mapping (stored as 0xFFFF first); *wide = 1 when a double-byte
 * character occurs [fact] */
int sjis_to_ucs2_str(const uint8_t *s, uint8_t *out, uint8_t *wide)
{
    int n = 0;

    while (*s != 0)
    {
        uint32_t u;

        if (sjis_is_lead(*s))
        {
            u = sjis_to_ucs2_char(s);
            *wide = 1;
            s += 2;
        }
        else
        {
            u = sjis_to_ucs2_char(s);
            s += 1;
        }
        out[0] = (uint8_t)(u >> 8);
        out[1] = (uint8_t)u;
        out += 2;
        if (u == 0xFFFF)
        {
            return -99;
        }
        n++;
    }
    out[0] = 0;
    out[1] = 0;
    return n;
}

/* 0x2014CC1C: one UTF-16 character (low byte first) to Shift-JIS: 1 byte for U+0000, U+00A5 ('\'), U+203E ('~'),
 * half-width kana U+FF61..FF9F and printable ASCII; 2 bytes found by a linear search of the two tables; 0 when
 * none has it [fact] */
int ucs2_to_ascii_char(uint8_t *out, const uint8_t *w)
{
    uint32_t lo = w[0], hi = w[1];
    uint32_t u = (uint16_t)(lo + (hi << 8));

    if (u == 0)
    {
        out[0] = 0;
        return 1;
    }
    if (u == 0xA5)
    {
        out[0] = '\\';
        return 1;
    }
    if (u == 0x203E)
    {
        out[0] = '~';
        return 1;
    }
    if (hi == 0xFF && lo >= 0x61 && lo <= 0x9F)
    {
        out[0] = (uint8_t)(lo + 0x40);
        return 1;
    }
    if (u - 0x20 <= 0x5E)
    {
        out[0] = (uint8_t)lo;
        return 1;
    }
    for (uint16_t k = 0; k < 0x1EBD; k++)
    {
        if (sjis_ucs2_81[k] == u)
        {
            uint32_t c = k + 0x8140;
            out[0] = (uint8_t)(c >> 8);
            out[1] = (uint8_t)c;
            return 2;
        }
    }
    for (uint16_t k = 0; k < 0x1CBD; k++)
    {
        if (sjis_ucs2_e0[k] == u)
        {
            uint32_t c = k + 0xE040;
            out[0] = (uint8_t)(c >> 8);
            out[1] = (uint8_t)c;
            return 2;
        }
    }
    return 0;
}

/* 0x2014CFF4: copies a 0-terminated UTF-16 string, returns its length in characters and sets *flag = 1 [fact] */
int fs_wstrcpy_len(const uint8_t *src, uint8_t *dst, uint8_t *flag)
{
    int n = 0;

    while (src[0] != 0 || src[1] != 0)
    {
        n++;
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    }
    dst[0] = 0;
    dst[1] = 0;
    *flag = 1;
    return n;
}

/* 0x2014D050: a UTF-16 short name (at most 12 characters) to upper-case 8-bit characters with the mapping of
 * ucs2_to_ascii_char; returns the count, or 0 with an empty result at a character outside it [fact] */
int fs_ucs2_to_ascii_upper(fs_char_t *out, const uint8_t *w)
{
    fs_char_t *p = out;
    int n = 0;

    for (int i = 0; i < 12; i++, p++, w += 2)
    {
        uint32_t lo = w[0], hi = w[1];
        uint32_t u = (uint16_t)(lo + (hi << 8));

        if (u == 0)
        {
            *p = 0;
            return n;
        }
        if (u == 0xA5)
        {
            *p = '\\';
        }
        else if (u == 0x203E)
        {
            *p = '~';
        }
        else if (hi == 0xFF && lo >= 0x61 && lo <= 0x9F)
        {
            *p = (fs_char_t)(lo + 0x40);
        }
        else if (u - 0x20 <= 0x5E)
        {
            *p = (fs_char_t)fs_toupper((fs_char_t)w[0]);
        }
        else
        {
            *out = 0;
            return 0;
        }
        n++;
    }
    return n;
}

/* 0x2014D128: byte copy [fact] */
void fs_memcpy(void *dst, const void *src, uint32_t n)
{
    uint8_t *d = dst;
    const uint8_t *s = src;

    for (; n != 0; n--)
    {
        *d++ = *s++;
    }
}

/* 0x2014D148: (dst, c, n, block): with dst word-aligned and n == block a word fill of block / 32 groups of eight
 * words (nothing for a block under 32 bytes), else a byte fill of n bytes [fact] */
void fs_memset(void *dst, int c, uint32_t n, uint32_t block)
{
    if (((uintptr_t)dst & 3) == 0 && n == block)
    {
        uint32_t w = (uint8_t)c;
        uint32_t *p = dst;

        w |= w << 8;
        w |= w << 16;
        for (uint32_t k = block >> 5; k != 0; k--)
        {
            p[0] = w;
            p[1] = w;
            p[2] = w;
            p[3] = w;
            p[4] = w;
            p[5] = w;
            p[6] = w;
            p[7] = w;
            p += 8;
        }
        return;
    }
    for (uint8_t *p = dst; n != 0; n--)
    {
        *p++ = (uint8_t)c;
    }
}

/* 0x2014D1C4: byte move. For an overlap with dst above src it copies backwards, but from src[n] down to src[1],
 * one byte above the area, so it moves the wrong bytes [fact: ldrb r2, [ip], #-1 with ip = src + n at
 * 0x2014D1EC]; forwards it is a plain copy */
void fs_memmove(uint8_t *dst, const uint8_t *src, uint32_t n)
{
    if (src < dst && dst < src + n)
    {
        const uint8_t *s = src + n;
        uint8_t *d = dst + n;

        for (; n != 0; n--)
        {
            *d-- = *s--;
        }
        return;
    }
    for (; n != 0; n--)
    {
        *dst++ = *src++;
    }
}

/* 0x2014D220: string length [fact] */
int fs_strlen(const fs_char_t *s)
{
    int n = 0;

    while (*s++ != 0)
    {
        n++;
    }
    return n;
}

/* 0x2014D248: length of a UTF-16 string in bytes [fact] */
int fs_wstrlen_bytes(const fs_wchar_t *s)
{
    int n = 0;

    while (*s++ != 0)
    {
        n++;
    }
    return n << 1;
}

/* 0x2014D270: string copy with the terminator [fact] */
void fs_strcpy(fs_char_t *dst, const fs_char_t *src)
{
    fs_char_t c;

    do
    {
        c = *src++;
        *dst++ = c;
    } while (c != 0);
}

/* 0x2014D288: copies at most n bytes and pads with 0 after the terminator [fact] */
void fs_strncpy(fs_char_t *dst, const fs_char_t *src, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        if (*src == 0)
        {
            *dst++ = 0;
        }
        else
        {
            *dst++ = *src++;
        }
    }
}

/* 0x2014D2CC: the UTF-16 version, n characters [fact] */
void fs_wstrncpy(uint8_t *dst, const uint8_t *src, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++, dst += 2)
    {
        if (src[0] == 0 && src[1] == 0)
        {
            dst[0] = 0;
            dst[1] = 0;
        }
        else
        {
            dst[0] = src[0];
            dst[1] = src[1];
            src += 2;
        }
    }
}

/* 0x2014D338: first occurrence of c (the terminator included), 0 when missing [fact] */
fs_char_t *fs_strchr(const fs_char_t *s, int c)
{
    fs_char_t ch = (fs_char_t)c;

    for (;; s++)
    {
        if (*s == ch)
        {
            return (fs_char_t *)s;
        }
        if (*s == 0)
        {
            return 0;
        }
    }
}

/* 0x2014D35C: 'a'..'z' to upper case, as a signed char [fact] */
int fs_toupper(int c)
{
    if ((unsigned)(c - 'a') <= 25)
    {
        c = (fs_char_t)(c - 0x20);
    }
    return c;
}

/* 0x2014D374: 'A'..'Z' to lower case [fact] */
int fs_tolower(int c)
{
    if ((unsigned)(c - 'A') <= 25)
    {
        c = (fs_char_t)(c + 0x20);
    }
    return c;
}

/* 0x2014D38C: case-insensitive compare; -1 / 1 when one string ends first, else the signed byte difference of the
 * upper-cased characters [fact] */
int fs_stricmp(const fs_char_t *a, const fs_char_t *b)
{
    for (;;)
    {
        int y = *b++;
        int x = *a++;

        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        int d = (fs_char_t)(fs_toupper(x) - fs_toupper(y));
        if (d != 0)
        {
            return d;
        }
    }
}

/* 0x2014D3F8: the UTF-16 version: characters below 0x100 compare upper-cased (the low byte as a signed char), the
 * others by their code difference [fact] */
int fs_wstricmp(const fs_wchar_t *a, const fs_wchar_t *b)
{
    int d;

    do
    {
        uint32_t x = *a, y = *b;
        const fs_char_t *pa = (const fs_char_t *)a, *pb = (const fs_char_t *)b;

        a++;
        b++;
        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        if ((pa[1] | pb[1]) != 0)
        {
            d = (int)(x - y);
        }
        else
        {
            d = fs_toupper(pa[0]) - fs_toupper(pb[0]);
        }
    } while (d == 0);
    return d;
}

/* 0x2014D48C: fs_stricmp over at most n characters [fact] */
int fs_strnicmp(const fs_char_t *a, const fs_char_t *b, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        int x = *a++;
        int y = *b++;

        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        int d = (fs_char_t)(fs_toupper(x) - fs_toupper(y));
        if (d != 0)
        {
            return d;
        }
    }
    return 0;
}

/* 0x2014D508: fs_wstricmp over at most n characters [fact] */
int fs_wstrnicmp(const fs_wchar_t *a, const fs_wchar_t *b, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        uint32_t x = *a, y = *b;
        const fs_char_t *pa = (const fs_char_t *)a, *pb = (const fs_char_t *)b;
        int d;

        a++;
        b++;
        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        if ((pa[1] | pb[1]) != 0)
        {
            d = (int)(x - y);
        }
        else
        {
            d = fs_toupper(pa[0]) - fs_toupper(pb[0]);
        }
        if (d != 0)
        {
            return d;
        }
    }
    return 0;
}

/* 0x2014D5B4: lower-cases 'A'..'Z' in place and steps over the trail byte of a Shift-JIS pair. The loop tests
 * the next byte only after the first, so an empty string looks at s[1] [fact: ldrb r0, [r4, #1]! at the end] */
fs_char_t *fs_strlwr_sjis(fs_char_t *s)
{
    uint8_t *p = (uint8_t *)s;

    do
    {
        if (sjis_is_lead(*p))
        {
            p++;
        }
        else if ((unsigned)(*p - 'A') <= 25)
        {
            *p += 0x20;
        }
    } while (*++p != 0);
    return s;
}

/* 0x2014D600: decimal digits to int, no sign and no checks [fact] */
int fs_atoi(const fs_char_t *s)
{
    int v = 0;

    while (*s != 0)
    {
        v = *s++ + v * 10 - '0';
    }
    return v;
}

/* 0x2014D630: writes v in radix r, most significant digit first (recursive), 'a'.. for digits from 10; returns
 * the end [fact] */
fs_char_t *fs_utoa_digits(uint32_t v, fs_char_t *out, uint32_t r)
{
    uint32_t q = v / r;
    int digit = (fs_char_t)(v % r);

    if (q != 0)
    {
        out = fs_utoa_digits(q, out, r);
    }
    *out = (fs_char_t)(digit < 10 ? digit + '0' : digit + 'a' - 10);
    return out + 1;
}

/* 0x2014D678: (value, buffer, radix 2..36): a '-' for a negative value in radix 10, the digits, a terminator;
 * an empty string for any other radix; returns the buffer [fact] */
fs_char_t *fs_itoa(int v, fs_char_t *buf, uint32_t r)
{
    fs_char_t *p = buf;

    if (r - 2 >= 35)
    {
        *buf = 0;
        return buf;
    }
    if (r == 10 && v < 0)
    {
        *p++ = '-';
        v = -v;
    }
    *fs_utoa_digits((uint32_t)v, p, r) = 0;
    return buf;
}

/* 0x2014D6C8: fs_stricmp, but after a Shift-JIS lead byte (of b) the trail byte compares exactly, and any
 * mismatch of a lead or trail byte gives -1 [fact] */
int fs_stricmp_sjis(const fs_char_t *a, const fs_char_t *b)
{
    int trail = 0;

    for (;;)
    {
        int x = *a++;
        int y = *b++;

        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        if (trail)
        {
            trail = 0;
            if (x != y)
            {
                return -1;
            }
        }
        else if (sjis_is_lead(y & 0xFF))
        {
            trail = 1;
            if (x != y)
            {
                return -1;
            }
        }
        else
        {
            int d = (fs_char_t)(fs_toupper(x) - fs_toupper(y));
            if (d != 0)
            {
                return d;
            }
        }
    }
}

/* 0x2014D770: fs_stricmp_sjis over at most n bytes [fact] */
int fs_strnicmp_sjis(const fs_char_t *a, const fs_char_t *b, uint32_t n)
{
    int trail = 0;

    for (uint32_t i = 0; i < n; i++)
    {
        int x = *a++;
        int y = *b++;

        if ((x | y) == 0)
        {
            return 0;
        }
        if (x == 0)
        {
            return -1;
        }
        if (y == 0)
        {
            return 1;
        }
        if (trail)
        {
            trail = 0;
            if (x != y)
            {
                return -1;
            }
        }
        else if (sjis_is_lead(y & 0xFF))
        {
            trail = 1;
            if (x != y)
            {
                return -1;
            }
        }
        else
        {
            int d = (fs_char_t)(fs_toupper(x) - fs_toupper(y));
            if (d != 0)
            {
                return d;
            }
        }
    }
    return 0;
}

/* 0x2014D834 / 0x2014D864: second copies of fs_atoi and fs_itoa (the same code at another address) [fact] */
int fs_atoi_2(const fs_char_t *s)
{
    int v = 0;

    while (*s != 0)
    {
        v = *s++ + v * 10 - '0';
    }
    return v;
}

fs_char_t *fs_itoa_2(int v, fs_char_t *buf, uint32_t r)
{
    fs_char_t *p = buf;

    if (r - 2 >= 35)
    {
        *buf = 0;
        return buf;
    }
    if (r == 10 && v < 0)
    {
        *p++ = '-';
        v = -v;
    }
    *fs_utoa_digits((uint32_t)v, p, r) = 0;
    return buf;
}

/* 0x2014D8B4: the signed byte sum of the two low bytes of a word (no caller found by Ghidra) [fact] */
int fs_byte_pair_sum(uint32_t v)
{
    return (fs_char_t)((fs_char_t)(v >> 8) + (uint8_t)v);
}

/* 0x2014D8C8: a 0-terminated UTF-16 string to little-endian bytes, the terminator included [fact] */
void fs_wstr_store_le(uint8_t *dst, const fs_wchar_t *s)
{
    fs_wchar_t c;

    do
    {
        c = *s;
        dst[0] = (uint8_t)c;
        dst[1] = (uint8_t)(c >> 8);
        dst += 2;
        c = *s++;
    } while (c != 0);
}

/* 0x2014D8EC / 0x2014D900 / 0x2014D918 / 0x2014D93C: little-endian 16- and 32-bit fields at any alignment (the
 * BPB and directory entries) [fact] */
void fat_st_word(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
}

uint32_t fat_ld_word(const uint8_t *p)
{
    return p[0] | ((p[1] << 8) & 0xFFFF);
}

void fat_st_dword(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16);
    p[3] = (uint8_t)(v >> 24);
}

uint32_t fat_ld_dword(const uint8_t *p)
{
    return p[0] | (p[1] << 8) | (p[2] << 16) | ((uint32_t)p[3] << 24);
}
