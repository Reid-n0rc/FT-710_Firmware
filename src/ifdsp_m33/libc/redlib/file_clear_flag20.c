/*
 * FT-710 IFDSP M33 (T24): file_clear_flag20, recreated from the image's C library (NXP Redlib, closed source) at 0x87470.
 * Resolves a pending seek before a write: flushes and moves the buffer to the target [fact: 0x87470]. Open: Redlib's name; would be settled by its symbol table.
 */
#include "redlib_file.h"

void file_clear_flag20(redlib_file_t *f)
{
    f->flags &= ~0x20u;
    if (f->pos != f->seekpos)
    {
        file_flush_write_buffer(f);
        f->flags   = (f->flags & ~0x3010u) | 0x10u;
        f->pos     = f->seekpos;
        f->hiwater = f->base;
        f->ptr     = f->base;
    }
    f->flags &= ~0x4040u;
}
