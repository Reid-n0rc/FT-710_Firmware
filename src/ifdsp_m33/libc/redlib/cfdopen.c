/*
 * FT-710 IFDSP M33 (T24): _Cfdopen, recreated from the image's C library (NXP Redlib, closed source) at 0x875F0.
 * Close f, then open host handle fd on it with an fopen mode string [fact: 0x875F0].
 */
#include "redlib_file.h"

extern int fseek(redlib_file_t *f, long off, int whence);

redlib_file_t *_Cfdopen(int fd, const char *mode, redlib_file_t *f)
{
    unsigned int flags;
    unsigned int m;

    _Cfclose(f);
    switch (*mode)
    {
        case 'r':
            m     = 0;
            flags = RF_READ;
            break;
        case 'w':
            m     = 4;
            flags = RF_WRITE;
            break;
        case 'a':
            m     = 8;
            flags = RF_APPEND | RF_WRITE;
            break;
        default:
            return 0;
    }
    for (;;)
    {
        char c = *++mode;
        if (c == '+')
        {
            flags |= 3u;
            m |= 2u;
        }
        else if (c == 'b')
        {
            flags |= 4u;
            m |= 1u;
        }
        else
        {
            break;
        }
    }
    f->flags = flags;
    f->fd    = fd;
    if (m & 8u)
    {
        fseek(f, 0, 2);
    }
    return f;
}
