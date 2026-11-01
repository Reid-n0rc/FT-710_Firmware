/*
 * FT-710 IFDSP M33 (T24): fseek, recreated from the image's C library (NXP Redlib, closed source) at 0x85E2C.
 * Returns 0, or 2 for a bad stream/whence/target and 1 when the host length is unknown; a target inside the buffer only moves the pointers, else the seek is left pending (flag 0x20, +0x28) [fact: 0x85E2C].
 */
#include "redlib_file.h"

extern long ftell(redlib_file_t *f);

int fseek(redlib_file_t *f, long off, int whence)
{
    unsigned int flags = f->flags;
    int r;
    int fd;

    if ((flags & 0x100003u) == 0)
    {
        return 2;
    }
    fd = f->fd;
    r  = __sys_istty(fd);
    if (r != 0)
    {
        return 2;
    }
    if (whence == 1)
    {
        off += ftell(f);
    }
    else if (whence == 2)
    {
        int len = __sys_flen(fd);
        unsigned char *end;
        int n;
        if (len < 0)
        {
            f->flags |= 0x80u;
            return 1;
        }
        end = f->ptr;
        n   = f->pos + (int)((end < f->hiwater) ? f->hiwater : end);
        n   = n - (int)f->base;
        if ((f->flags & 0x20u) && n < f->seekpos)
        {
            n = f->seekpos;
        }
        off += (n < len) ? len : n;
    }
    else if (whence != 0)
    {
        return 2;
    }
    if (off < 0)
    {
        return 2;
    }
    if (flags & 0x2000u)
    {
        if (f->hiwater < f->ptr)
        {
            f->hiwater = f->ptr;
        }
    }
    if (f->pos <= off)
    {
        unsigned char *end = (f->ptr < f->hiwater) ? f->hiwater : f->ptr;
        if (off <= (int)(end + f->pos - f->base) && off < f->pos + f->bufsize2)
        {
            off -= f->pos;
            if (flags & 2u)
            {
                f->wcount = off - f->bufsize2;
            }
            if (flags & 1u)
            {
                f->rcount = (int)(end - f->base) - off;
            }
            f->ptr = f->base + off;
            flags &= ~0x20u;
            goto done;
        }
    }
    f->rcount  = 0;
    f->wcount  = 0;
    flags |= 0x20u;
    f->seekpos = off;
done:
    flags &= ~0x83000u;
    flags &= ~0x40u;
    f->flags = flags;
    return r;
}
