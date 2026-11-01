/*
 * FT-710 IFDSP M33 (T24): ftell, recreated from the image's C library (NXP Redlib, closed source) at 0x85F2C.
 * Not open: errno 33 and -1 [fact: 0x85F2C].
 */
#include "redlib_file.h"

extern int errno;

long ftell(redlib_file_t *f)
{
    unsigned int flags = f->flags;
    int p;

    if ((flags & 3u) == 0)
    {
        errno = 33;
        return -1;
    }
    if (flags & 0x80000u)
    {
        if (flags & 0x20u)
        {
            p = f->seekpos;
        }
        else
        {
            p = (int)(f->ptr + f->pos - f->base);
        }
        return p - 1;
    }
    if (flags & 0x20u)
    {
        return f->seekpos;
    }
    return (int)(f->ptr + f->pos - f->base);
}
