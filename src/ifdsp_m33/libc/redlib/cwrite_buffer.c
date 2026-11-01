/*
 * FT-710 IFDSP M33 (T24): _Cwrite_buffer, recreated from the image's C library (NXP Redlib, closed source) at 0x85D84.
 * Writes len bytes of a stream buffer to the host: first resolves a pending length (flag 0x100000 -> __sys_flen) and seek (0x20010 -> __sys_seek), then __sys_write; the position advances by the bytes written [fact: 0x85D84].
 */
#include "redlib_file.h"

int _Cwrite_buffer(const unsigned char *buf, int len, redlib_file_t *f)
{
    unsigned int flags = f->flags;
    int fd             = f->fd;
    int r;

    if (flags & 0x100000u)
    {
        flags |= 0x10u;
        f->pos = __sys_flen(fd);
    }
    if (flags & 0x20010u)
    {
        if (__sys_seek(fd, f->pos) < 0)
        {
            goto fail;
        }
        flags &= ~0x20000u;
        flags &= ~0x10u;
        f->flags = flags;
    }
    r      = __sys_write(fd, buf, len);
    f->pos = f->pos + (len - (int)((unsigned int)r & 0x7FFFFFFFu));
    if (r == 0)
    {
        return 0;
    }
fail:
    f->flags |= 0x80u;
    return -1;
}
