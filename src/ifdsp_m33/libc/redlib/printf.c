/*
 * FT-710 IFDSP M33 (T24): sprintf 0x85A9C, snprintf 0x85B08 and vsprintf 0x85B80, recreated from the image's C library
 * (NXP Redlib, closed source). Each one builds a string stream on the stack (flags 0xA, room 0x7FFFFFFF, pointer at
 * the buffer) and calls the printf core 0x84EB0 with a 64-bit character limit (sprintf/vsprintf: LLONG_MAX, snprintf:
 * size - 1, zero-extended) and the hook 0x872F5; then it terminates the string through the stream [fact: the three
 * functions]. snprintf(NULL, 0, ...) formats into a 4-byte local buffer and returns the length; snprintf(NULL, n > 0)
 * returns -1 [fact: 0x85B12..0x85B1A, 0x85B74].
 */
#include <stdarg.h>
#include <stddef.h>
#include "redlib_file.h"

extern void *memset(void *d, int c, size_t n);
extern int fputc(int c, redlib_file_t *f);
extern int vsnprintf_core(redlib_file_t *f, long long max, const char *fmt, va_list ap, int (*hook)(void));

/* The hook passed to the core as its last argument (0x872F5, Thumb) [fact: literal pools 0x85B04, 0x85B7C, 0x85BD8];
 * it returns 0 [fact: 0x872F4 movs r0, #0; bx lr]. Open: what the core calls it for (the floating-point conversions are
 * the likely case, Redlib's "no float" printf); would be settled by the hook's call sites in the core 0x84EB0. */
int printf_float_none(void)
{
    return 0;
}

int sprintf(char *buf, const char *fmt, ...)
{
    redlib_file_t f;
    va_list ap;
    int n;

    va_start(ap, fmt);
    memset(&f, 0, sizeof(f));
    f.flags  = 10;
    f.wcount = 0x7FFFFFFF;
    f.ptr    = (unsigned char *)buf;
    n        = vsnprintf_core(&f, 0x7FFFFFFFFFFFFFFFLL, fmt, ap, printf_float_none);
    if (--f.wcount < 0)
    {
        fputc(0, &f);
    }
    else
    {
        *f.ptr = 0;
    }
    va_end(ap);
    return n;
}

int snprintf(char *buf, size_t size, const char *fmt, ...)
{
    redlib_file_t f;
    char dummy[4];
    va_list ap;
    int n;

    if (buf == NULL)
    {
        if (size != 0)
        {
            return -1;
        }
        size = 1;
        buf  = dummy;
    }
    va_start(ap, fmt);
    memset(&f, 0, sizeof(f));
    f.flags  = 10;
    f.ptr    = (unsigned char *)buf;
    f.wcount = 0x7FFFFFFF;
    n        = vsnprintf_core(&f, size - 1, fmt, ap, printf_float_none);
    if (--f.wcount < 0)
    {
        fputc(0, &f);
    }
    else
    {
        *f.ptr = 0;
    }
    va_end(ap);
    return n;
}

int vsprintf(char *buf, const char *fmt, va_list ap)
{
    redlib_file_t f;
    int n;

    memset(&f, 0, sizeof(f));
    f.flags  = 10;
    f.wcount = 0x7FFFFFFF;
    f.ptr    = (unsigned char *)buf;
    n        = vsnprintf_core(&f, 0x7FFFFFFFFFFFFFFFLL, fmt, ap, printf_float_none);
    if (--f.wcount < 0)
    {
        fputc(0, &f);
    }
    else
    {
        *f.ptr = 0;
    }
    return n;
}
