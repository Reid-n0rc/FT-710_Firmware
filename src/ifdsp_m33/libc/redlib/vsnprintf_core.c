/*
 * FT-710 IFDSP M33 (T24): the printf core of the image's C library (NXP Redlib, closed source; 0x84EB0..0x85989,
 * 2,778 bytes), translated from the image instruction by instruction (T24 round 3).
 *
 * Interface [fact: callers sprintf 0x85A9C, snprintf 0x85B08, vsprintf 0x85B80 and the prologue 0x84EB0]:
 *   (stream, 64-bit character limit in r2:r3, format, va_list, hook). r1 is unused (the 64-bit limit is passed in an
 *   even register pair). Characters are counted in a 32-bit int and stored only while count < limit (64-bit signed
 *   compare of the sign-extended count, 0x84ED6..0x84EEA), through the stream: `if (--f->wcount < 0) fputc(c, f);
 *   else *f->ptr++ = c`.
 *
 * Format syntax [fact: the comparisons 0x84F0C..0x85130]: flags - + space # 0 (any order, repeated); width: digits or
 * `*` (a negative `*` width toggles `-`); precision: `.` digits or `.*` (a negative one means "no precision");
 * length: l, ll, L, q (64-bit), h, hh, j (64-bit), z, t (accepted, no effect); conversions d i o u x X p c s n and the
 * floating-point a A e E f g G, which go to the hook. Every other character after `%`, `%` itself and `F`, is printed
 * as itself, padded to the width (0x85140..0x851E6). A `%` at the end of the format ends it.
 *
 * Integer digits are produced least significant first into a 32-byte buffer, which is filled with 'U' first
 * (0x8546E..0x8547E); decimal digits by an open-coded 64-bit division by 10 (0x85770..0x857FA: the shift-and-add
 * quotient estimate with the +6 correction of Hacker's Delight `divu10`), so the core never calls __aeabi_uldivmod.
 *
 * The hook (sprintf & co. pass printf_float_none 0x872F5, which returns 0) is called for the floating-point
 * conversions as hook(conv, &double_arg, buf, flags, &prefix, &zeros, &lead, &trail) [fact: 0x85806..0x85822]; it
 * returns the number of characters it put in buf (in output order); a '<' or '>' in buf stands for `lead` - 1 or
 * `trail` - 1 zeros [fact: 0x85880..0x858E0]. The meaning of lead/trail is inferred from that use [inference].
 *
 * The local names are this project's; Redlib's own are not known. Open: whether Redlib's source writes the output
 * counter of a number as a separate local (as the image keeps it: `room` = limit - count, 0x85484) or GCC derived it;
 * would be settled by Redlib's source or its compiler (not available, see T24 "Redlib stand-ins").
 */
#include <stdarg.h>
#include <stddef.h>
#include "redlib_file.h"

extern int fputc(int c, redlib_file_t *f);
extern size_t strlen(const char *s);

/* format flags, as the image keeps them in one register (r9) [fact: the orr/tst masks] */
#define F_LEFT 0x001u  /* '-' */
#define F_PLUS 0x002u  /* '+' */
#define F_SPACE 0x004u /* ' ' */
#define F_ALT 0x008u   /* '#' */
#define F_PREC 0x010u  /* a precision was given */
#define F_LONG 0x020u  /* l */
#define F_LL 0x040u    /* ll L q j: 64-bit argument */
#define F_SHORT 0x080u /* h */
#define F_CHAR 0x100u  /* hh */
#define F_ZERO 0x200u  /* '0' */
#define F_FLOAT 0x400u /* a A e E f g G */

typedef int (*printf_hook_t)(int conv, void *arg, char *buf, unsigned int flags, const char **prefix, int *zeros,
                             int *lead, int *trail);

/* one character to the stream (the string streams of sprintf & co. or a FILE). The macros below evaluate their
 * argument only when the character is stored: pass them no side effects. */
#define EMIT(f, c)                          \
    do                                      \
    {                                       \
        if (--(f)->wcount < 0)              \
        {                                   \
            fputc((c), (f));                \
        }                                   \
        else                                \
        {                                   \
            *(f)->ptr++ = (unsigned char)(c); \
        }                                   \
    } while (0)

/* counted against the whole result: count < limit */
#define PUT(c)                    \
    do                            \
    {                             \
        if (count < limit)        \
        {                         \
            EMIT(f, (c));         \
        }                         \
        count++;                  \
    } while (0)

/* counted inside one number: k < room (= limit - count at its start) */
#define PUTK(c)                   \
    do                            \
    {                             \
        if (k < room)             \
        {                         \
            EMIT(f, (c));         \
        }                         \
        k++;                      \
    } while (0)

/* 64-bit unsigned argument of an integer conversion, cut to h / hh */
#define UNSIGNED_ARG()                                  \
    do                                                  \
    {                                                   \
        v = (flags & F_LL) ? va_arg(ap, unsigned long long) : va_arg(ap, unsigned int); \
        if (flags & F_SHORT)                            \
        {                                               \
            v = (unsigned short)v;                      \
        }                                               \
        else if (flags & F_CHAR)                        \
        {                                               \
            v = (unsigned char)v;                       \
        }                                               \
    } while (0)

int vsnprintf_core(redlib_file_t *f, long long limit, const char *fmt, va_list ap, printf_hook_t hook)
{
    int count = 0;

    for (;;)
    {
        unsigned int c = (unsigned char)*fmt++;
        if (c == 0)
        {
            return count;
        }
        if (c != '%')
        {
            PUT(c);
            continue;
        }

        /* flags */
        unsigned int flags = 0;
        for (;;)
        {
            c = (unsigned char)*fmt++;
            if (c == '+')
                flags |= F_PLUS;
            else if (c == '-')
                flags |= F_LEFT;
            else if (c == '0')
                flags |= F_ZERO;
            else if (c == ' ')
                flags |= F_SPACE;
            else if (c == '#')
                flags |= F_ALT;
            else
                break;
        }

        /* width */
        int width;
        if (c == '*')
        {
            width = va_arg(ap, int);
            if (width < 0)
            {
                width = (int)(0u - (unsigned int)width); /* INT_MIN stays negative: width 0 below */
                flags ^= F_LEFT;
            }
            c = (unsigned char)*fmt++;
        }
        else
        {
            width = 0;
            while ((unsigned char)(c - '0') < 10)
            {
                width = (int)((unsigned int)width * 10u + (c - '0')); /* wraps like the image's */
                c     = (unsigned char)*fmt++;
            }
        }
        if (width < 0)
        {
            width = 0;
        }

        /* precision */
        int prec = 0;
        if (c == '.')
        {
            c = (unsigned char)*fmt++;
            if (c == '*')
            {
                prec = va_arg(ap, int);
                c    = (unsigned char)*fmt++;
            }
            else
            {
                while ((unsigned char)(c - '0') < 10)
                {
                    prec = (int)((unsigned int)prec * 10u + (c - '0'));
                    c    = (unsigned char)*fmt++;
                }
            }
            if (prec < 0)
            {
                prec = 0;
            }
            else
            {
                flags |= F_PREC;
            }
        }

        /* length */
        if (c == 'l')
        {
            c = (unsigned char)*fmt++;
            if (c == 'l')
            {
                c = (unsigned char)*fmt++;
                flags |= F_LONG | F_LL;
            }
            else
            {
                flags |= F_LONG;
            }
        }
        if (c == 'L' || c == 'q')
        {
            flags |= F_LONG | F_LL;
            c = (unsigned char)*fmt++;
        }
        else if (c == 'h')
        {
            c = (unsigned char)*fmt++;
            if (c == 'h')
            {
                c = (unsigned char)*fmt++;
                flags |= F_CHAR;
            }
            else
            {
                flags |= F_SHORT;
            }
        }
        else if (c == 'j')
        {
            flags |= F_LL;
            c = (unsigned char)*fmt++;
        }
        else if (c == 'z' || c == 't')
        {
            c = (unsigned char)*fmt++;
        }

        unsigned long long v = 0;
        const char *digits   = 0; /* hex digit table; 0 for decimal and octal */
        const char *prefix   = 0;
        double dval;

        switch (c)
        {
            case 0:
                fmt--; /* the format ends after the '%' */
                continue;

            case 'c':
                c = (unsigned char)va_arg(ap, int);
                goto single;

            case 'n':
            {
                void *p = va_arg(ap, void *);
                if (flags & F_LL)
                    *(long long *)p = count;
                else if (flags & F_LONG)
                    *(int *)p = count;
                else if (flags & F_CHAR)
                    *(signed char *)p = (signed char)count;
                else if (flags & F_SHORT)
                    *(short *)p = (short)count;
                else
                    *(int *)p = count;
                continue;
            }

            case 's':
            {
                const char *s = va_arg(ap, const char *);
                if (s == 0)
                {
                    s = "(null)";
                }
                int len = (int)strlen(s);
                if ((flags & F_PREC) && prec <= len)
                {
                    len = prec;
                }
                int pad = width - len;
                if (!(flags & F_LEFT))
                {
                    int pc = (flags & F_ZERO) ? '0' : ' ';
                    while (--pad >= 0)
                        PUT(pc);
                }
                for (int i = 0; i < len; i++)
                    PUT(s[i]);
                if (flags & F_LEFT)
                {
                    while (--pad >= 0)
                        PUT(' ');
                }
                continue;
            }

            case 'd':
            case 'i':
            {
                long long sv = (flags & F_LL) ? va_arg(ap, long long) : va_arg(ap, int);
                if (flags & F_SHORT)
                    sv = (short)sv;
                else if (flags & F_CHAR)
                    sv = (signed char)sv;
                if (sv < 0)
                {
                    v      = -(unsigned long long)sv;
                    prefix = "-";
                }
                else
                {
                    v      = (unsigned long long)sv;
                    prefix = (flags & F_PLUS) ? "+" : (flags & F_SPACE) ? " " : "";
                }
                if (flags & F_PREC)
                    flags &= ~F_ZERO;
                break;
            }

            case 'o':
                UNSIGNED_ARG();
                prefix = (flags & F_ALT) ? "0" : "";
                if (flags & F_PREC)
                    flags &= ~F_ZERO;
                break;

            case 'u':
                UNSIGNED_ARG();
                if (flags & F_PREC)
                    flags &= ~F_ZERO;
                prefix = "";
                break;

            case 'x':
                UNSIGNED_ARG();
                prefix = (flags & F_ALT) ? "0x" : "";
                if (flags & F_PREC)
                    flags &= ~F_ZERO;
                digits = "0123456789abcdef";
                break;

            case 'X':
                UNSIGNED_ARG();
                prefix = (flags & F_ALT) ? "0X" : "";
                if (flags & F_PREC)
                    flags &= ~F_ZERO;
                digits = "0123456789ABCDEF";
                break;

            case 'p':
                v      = va_arg(ap, unsigned int);
                digits = "0123456789abcdef";
                prefix = "0x";
                break;

            case 'a':
            case 'A':
                if (!(flags & F_PREC))
                {
                    prec = 13;
                    flags |= F_PREC;
                }
                /* fall through */
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                dval = va_arg(ap, double);
                if (!(flags & F_PREC))
                {
                    prec = 6;
                }
                flags |= F_FLOAT; /* prefix stays NULL [fact: 0x851A0..0x851B2]: for the hook to set */
                break;

            default:
            single:
            {
                /* a single character (c, %, or an unknown conversion) padded to the width */
                int pad = width - 1;
                if (!(flags & F_LEFT))
                {
                    int pc = (flags & F_ZERO) ? '0' : ' ';
                    while (--pad >= 0)
                        PUT(pc);
                }
                PUT(c);
                if (flags & F_LEFT)
                {
                    while (--pad >= 0)
                        PUT(' ');
                }
                continue;
            }
        }

        /* a number: digits into buf, then [spaces] prefix [zero padding] [precision zeros] digits [spaces] */
        long long room = limit - count;
        long long k    = 0;
        int lead = -1, trail = -1;
        char buf[32];
        int n = 0;

        for (int i = 0; i < 32; i++)
        {
            buf[i] = 'U';
        }
        int zeros = (flags & (F_PREC | F_FLOAT)) ? prec : 1;

        switch (c)
        {
            case 'o':
                while (v)
                {
                    buf[n++] = (char)('0' + (v & 7));
                    v >>= 3;
                }
                break;
            case 'p':
            case 'x':
            case 'X':
                while (v)
                {
                    buf[n++] = digits[v & 15];
                    v >>= 4;
                }
                break;
            case 'd':
            case 'i':
            case 'u':
                while (v)
                {
                    /* q = v / 10 without a division (Hacker's Delight divu10) */
                    unsigned long long q = (v >> 1) + (v >> 2);
                    q += q >> 4;
                    q += q >> 8;
                    q += q >> 16;
                    q += q >> 32;
                    q >>= 3;
                    q += (v + 6 - q * 10) >> 4;
                    buf[n++] = (char)((unsigned int)v + '0' - (unsigned int)q * 10);
                    v        = q;
                }
                break;
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                n = hook((int)c, &dval, buf, flags, &prefix, &zeros, &lead, &trail);
                break;
            default:
                break;
        }

        if (!(flags & F_FLOAT))
        {
            zeros -= n;
            if (zeros < 0)
            {
                zeros = 0;
            }
        }
        else
        {
            zeros = 0;
            if (lead > 0)
            {
                zeros = lead - 1;
            }
            if (trail > 0)
            {
                zeros += trail - 1;
            }
        }
        int pad = width - (n + zeros) - (int)strlen(prefix);

        if (!(flags & (F_LEFT | F_ZERO)))
        {
            while (--pad >= 0)
                PUTK(' ');
        }
        while (*prefix)
        {
            char ch = *prefix++;
            PUTK(ch);
        }
        if (!(flags & F_LEFT))
        {
            int pc = (flags & F_ZERO) ? '0' : ' ';
            while (--pad >= 0)
                PUTK(pc);
        }
        if (!(flags & F_FLOAT))
        {
            while (--zeros >= 0)
                PUTK('0');
            for (int i = n; i > 0; i--)
                PUTK(buf[i - 1]);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                char ch = buf[i];
                if (ch == '<')
                {
                    while (--lead >= 0)
                        PUTK('0');
                }
                else if (ch == '>')
                {
                    while (--trail >= 0)
                        PUTK('0');
                }
                else
                {
                    PUTK(ch);
                }
            }
        }
        if (flags & F_LEFT)
        {
            while (--pad >= 0)
                PUTK(' ');
        }
        count += (int)k;
    }
}
