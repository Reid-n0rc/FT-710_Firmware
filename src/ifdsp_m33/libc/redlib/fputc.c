/*
 * FT-710 IFDSP M33 (T24): fputc, recreated from the image's C library (NXP Redlib, closed source) at 0x874B0.
 * The slow path of character output (the printf core and the string functions write directly while the room count
 * at +8 stays >= 0): a string stream that ran out of room keeps counting; a write stream gets a buffer on first use
 * (256 bytes from _Csys_alloc, or the one-character buffer for a terminal without _IOFBF) and is written out at a
 * newline, when full, or at once when unbuffered [fact: 0x874B0].
 */
#include "redlib_file.h"

extern int fseek(redlib_file_t *f, long off, int whence);

int fputc(int ch, redlib_file_t *f)
{
    unsigned char c = (unsigned char)ch;
    unsigned int flags;
    unsigned int nf;
    unsigned char *p;
    unsigned char *base;
    int n;

    flags    = f->flags;
    f->flags = flags & ~0x80000u;
    if (flags & 0x20u)
    {
        file_clear_flag20(f);
    }
    flags = f->flags;
    if (f->wcount < -1 && (flags & 0x200u) == 0)
    {
        f->wcount = -2 - f->wcount;
        p         = f->ptr;
        f->flags  = flags | 0x12000u;
        f->ptr    = p + 1;
        *p        = c;
        return c;
    }
    if ((flags & 0x108Au) != 2u)
    {
        f->wcount = 0;
        f->flags  = flags | 0x80u;
        return -1;
    }
    if ((flags & 0xA010u) == 0x8000u)
    {
        fseek(f, 0, 2);
        if (f->flags & 0x20u)
        {
            file_clear_flag20(f);
        }
        flags = f->flags;
    }
    nf       = flags | 0x12000u;
    f->flags = nf;
    if ((flags & 0xF00u) == 0)
    {
        if (__sys_istty(f->fd) == 0 || (flags & 0x400u) == 0)
        {
            unsigned char *b = _Csys_alloc(0x100);
            f->bufsize       = 0x100;
            nf               = flags | 0x12800u;
            f->base          = b;
            f->ptr           = b;
            f->flags         = f->flags | nf;
        }
        else
        {
            f->base    = f->ch;
            f->ptr     = f->ch;
            f->bufsize = 1;
            nf         = flags | 0x12400u;
            f->flags   = nf;
        }
    }
    p    = f->ptr;
    base = f->base;
    if ((nf & 0x900u) == 0)
    {
        f->ptr = p + 1;
        *p     = c;
        n      = (int)(((f->ptr < f->hiwater) ? f->hiwater : f->ptr) - base);
        f->bufsize2 = f->bufsize;
        if ((nf & 0x400u) == 0 && c != '\n' && n < f->bufsize)
        {
            return c;
        }
        f->hiwater = base;
        f->ptr     = base;
        f->wcount  = 0;
        if (_Cwrite_buffer(base, n, f) == 0)
        {
            return c;
        }
    }
    else
    {
        n = (int)(((p < f->hiwater) ? f->hiwater : p) - base);
        if (n == 0 || _Cwrite_buffer(base, n, f) == 0)
        {
            f->hiwater  = base + 1;
            f->ptr      = base + 1;
            f->wcount   = f->bufsize - 1;
            f->bufsize2 = f->bufsize;
            *base       = c;
            return c;
        }
    }
    return -1;
}
