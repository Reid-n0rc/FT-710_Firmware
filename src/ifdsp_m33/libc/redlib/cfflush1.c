/*
 * FT-710 IFDSP M33 (T24): _Cfflush1, recreated from the image's C library (NXP Redlib, closed source) at 0x87716.
 * Flush one stream and re-seek to its logical position [fact: 0x87716].
 */
#include "redlib_file.h"

extern int fseek(redlib_file_t *f, long off, int whence);

int _Cfflush1(redlib_file_t *f)
{
    int r;
    int pos;

    if ((f->flags & 3u) == 0)
    {
        return 0;
    }
    if (f->flags & 0x20u)
    {
        pos = f->seekpos;
        file_clear_flag20(f);
    }
    else
    {
        pos = (int)(f->ptr + f->pos - f->base);
    }
    f->flags &= ~0x3000u;
    r = file_flush_write_buffer(f);
    fseek(f, pos, 0);
    return r;
}
