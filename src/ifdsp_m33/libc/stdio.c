/*
 * FT-710 IFDSP M33 (T24): the formatted output the application uses (sprintf, snprintf, vsprintf), in place of the
 * image's C library (NXP Redlib, closed source: a 2.7 KB core at 0x84EB0 behind sprintf 0x85A9C, snprintf 0x85B08 and
 * vsprintf 0x85B80). Supports what the application's formats need: %d %i %u %x %X %c %s %%, the 0 flag and a width.
 * The image's stdio streams (stdin/stdout/stderr on the "no host" stubs) are not recreated: nothing writes to them
 * (docs/code/ifdsp/m33-platform.md section 9).
 */
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

typedef struct
{
    char *buf;
    size_t size; /* bytes the buffer holds, terminator included */
    size_t len;
} out_t;

static void put(out_t *o, char c)
{
    if (o->len + 1 < o->size)
    {
        o->buf[o->len] = c;
    }
    o->len++;
}

int vsnprintf(char *buf, size_t size, const char *fmt, va_list ap)
{
    out_t o = {buf, size, 0};
    char tmp[12];

    for (; *fmt; fmt++)
    {
        if (*fmt != '%')
        {
            put(&o, *fmt);
            continue;
        }
        char pad = ' ';
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
                neg = x < 0;
                v = neg ? -(unsigned long)x : (unsigned long)x;
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
                v = va_arg(ap, unsigned int);
                do
                {
                    tmp[sizeof(tmp) - 1 - n++] = digits[v & 15U];
                    v >>= 4;
                } while (v);
                break;
            }
            case 'c':
                tmp[sizeof(tmp) - 1] = (char)va_arg(ap, int);
                n = 1;
                break;
            case 's':
                s = va_arg(ap, const char *);
                if (s == NULL)
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
                fmt--;
                continue;
            default:
                put(&o, '%');
                put(&o, *fmt);
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
    if (o.size != 0)
    {
        o.buf[(o.len < o.size) ? o.len : o.size - 1] = 0;
    }
    return (int)o.len;
}

int vsprintf(char *buf, const char *fmt, va_list ap)
{
    return vsnprintf(buf, (size_t)-1, fmt, ap);
}

int sprintf(char *buf, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsprintf(buf, fmt, ap);
    va_end(ap);
    return n;
}

int snprintf(char *buf, size_t size, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsnprintf(buf, size, fmt, ap);
    va_end(ap);
    return n;
}
