/*
 * FT-710 IFDSP M33 (T24): file_flush_write_buffer, recreated from the image's C library (NXP Redlib, closed source) at 0x87658.
 * Writes the dirty part of a write buffer (flag 0x10000) [fact: 0x87658]. Open: Redlib's name; would be settled by its symbol table.
 */
#include "redlib_file.h"

int file_flush_write_buffer(redlib_file_t *f)
{
    unsigned char *base = f->base;
    unsigned char *end  = f->ptr;
    unsigned char *hw   = f->hiwater;
    unsigned int flags  = f->flags;

    f->flags = flags & ~0x80000u;
    if ((flags & 0x82u) != 2u)
    {
        return -1;
    }
    if ((flags & 0x10000u) == 0)
    {
        return 0;
    }
    if (end < hw)
    {
        end = hw;
    }
    if (base != end && _Cwrite_buffer(base, end - base, f) != 0)
    {
        return -1;
    }
    f->hiwater = base;
    f->ptr     = base;
    f->wcount  = 0;
    f->flags &= ~0x10000u;
    return 0;
}
