/*
 * FT-710 IFDSP M33 (T24): the printf core of the image's C library (NXP Redlib, closed source; 0x84EB0, 2778 bytes).
 * NOT YET RECREATED: this is a reduced stand-in with the original's interface, so that the program links and runs.
 *
 * Interface [fact: callers 0x85A9C, 0x85B08, 0x85B80 and the core's prologue 0x84EB0]: (stream, 64-bit limit in r2:r3,
 * format, va_list, hook); characters are counted in a 32-bit int, and stored while count < limit: `if (--f->wcount
 * < 0) fputc(c, f); else *f->ptr++ = c`. The original also parses the flags + - 0 space #, `*` width and precision,
 * the length modifiers l ll L q h hh j z t, and the conversions a c d e f g i n o p s u x X (the floating-point ones
 * through the hook) [fact: comparisons in 0x84EB0..0x85130]. This stand-in handles c d i u x X s % with the 0 flag
 * and a width, the conversions the application uses (docs/code/ifdsp/control-link.md, ipc.md).
 * Open: a full recreation; would be settled by translating 0x84EB0..0x85989 and checking it with tools/equiv_m33_emu.py
 * against the original (a format-string argument generator is needed for that check).
 */
#include <stdarg.h>
#include "redlib_file.h"

extern int fputc(int c, redlib_file_t *f);

typedef struct
{
    redlib_file_t *f;
    long long max;
    int n;
} out_t;

static void put(out_t *o, int c)
{
    if (o->n < o->max)
    {
        if (--o->f->wcount < 0)
        {
            fputc(c, o->f);
        }
        else
        {
            *o->f->ptr++ = (unsigned char)c;
        }
    }
    o->n++;
}

int vsnprintf_core(redlib_file_t *f, long long max, const char *fmt, va_list ap, int (*hook)(void))
{
    out_t o = {f, max, 0};
    char tmp[12];

    (void)hook;
    for (; *fmt; fmt++)
    {
        if (*fmt != '%')
        {
            put(&o, *fmt);
            continue;
        }
        char pad  = ' ';
        int width = 0;
        fmt++;
        if (*fmt == '0')
        {
            pad = '0';
            fmt++;
        }
        while (*fmt >= '0' && *fmt <= '9')
        {
            width = width * 10 + (*fmt++ - '0');
        }
        const char *s = tmp;
        int n = 0, neg = 0;
        unsigned long v;
        switch (*fmt)
        {
            case 'd':
            case 'i':
            {
                long x = va_arg(ap, int);
                neg    = x < 0;
                v      = neg ? -(unsigned long)x : (unsigned long)x;
                goto number10;
            }
            case 'u':
                v = va_arg(ap, unsigned int);
            number10:
                do
                {
                    tmp[sizeof(tmp) - 1 - n++] = (char)('0' + v % 10U);
                    v /= 10U;
                } while (v);
                break;
            case 'x':
            case 'X':
            {
                const char *digits = (*fmt == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
                v                  = va_arg(ap, unsigned int);
                do
                {
                    tmp[sizeof(tmp) - 1 - n++] = digits[v & 15U];
                    v >>= 4;
                } while (v);
                break;
            }
            case 'c':
                tmp[sizeof(tmp) - 1] = (char)va_arg(ap, int);
                n                    = 1;
                break;
            case 's':
                s = va_arg(ap, const char *);
                if (s == 0)
                {
                    s = "(null)";
                }
                while (s[n])
                {
                    n++;
                }
                break;
            case '%':
                put(&o, '%');
                continue;
            case 0:
                return o.n;
            default:
                continue;
        }
        if (*fmt != 's')
        {
            s = tmp + sizeof(tmp) - n;
        }
        if (neg && pad == '0')
        {
            put(&o, '-');
        }
        for (int k = n + neg; k < width; k++)
        {
            put(&o, pad);
        }
        if (neg && pad != '0')
        {
            put(&o, '-');
        }
        for (int k = 0; k < n; k++)
        {
            put(&o, s[k]);
        }
    }
    return o.n;
}
