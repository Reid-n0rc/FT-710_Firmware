/*
 * FT-710 IFDSP M33 (T24): setvbuf, recreated from the image's C library (NXP Redlib, closed source) at 0x872F8.
 * Only for an open stream; _IONBF uses the one-character buffer at +0x24 [fact: 0x872F8].
 */
#include <stddef.h>
#include "redlib_file.h"

int setvbuf(redlib_file_t *f, char *buf, int mode, size_t size)
{
    if ((f->flags & 3u) == 0)
    {
        return 1;
    }
    if (mode != 0x200)
    {
        if (mode == 0x400)
        {
            size = 1;
            buf  = (char *)f->ch;
            goto set;
        }
        if (mode != 0x100)
        {
            return 1;
        }
    }
    if (size - 1u > 0xFFFFFEu)
    {
        return 1;
    }
set:
    f->base    = (unsigned char *)buf;
    f->ptr     = (unsigned char *)buf;
    f->bufsize = (int)size;
    f->flags   = (unsigned int)mode | f->flags;
    return 0;
}
