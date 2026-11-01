/*
 * FT-710 IFDSP M33 (T24): _Cfclose, recreated from the image's C library (NXP Redlib, closed source) at 0x876AA.
 * Flush, close the host handle, free an allocated buffer, delete a tmpfile, clear the structure [fact: 0x876AA].
 */
#include "redlib_file.h"

extern int fflush(redlib_file_t *f);
extern void free(void *p);
extern void *memset(void *d, int c, unsigned int n);
extern int remove(const char *name);

int _Cfclose(redlib_file_t *f)
{
    unsigned int flags = f->flags;
    char name[32];

    if ((flags & 3u) == 0)
    {
        return -1;
    }
    if ((flags & 8u) == 0)
    {
        unsigned char *buf = f->base;
        int fd             = f->fd;
        fflush(f);
        __sys_close(fd);
        if (flags & RF_ALLOC)
        {
            free(buf);
        }
        if ((flags & 0xFFC00000u) == 0xAD800000u)
        {
            __sys_tmpnam(name, f->tmpid, 32);
            remove(name);
        }
    }
    memset(f, 0, sizeof(*f));
    return 0;
}
