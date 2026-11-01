/*
 * FT-710 IFDSP M33 (T24): __sys_* stubs, recreated from the image's C library (NXP Redlib, closed source) at 0x87932.
 * The "no host" semihosting stubs: nothing is connected [fact: 0x87932..0x8795B].
 */
#include "redlib_file.h"

void __sys_appexit(void)
{
    for (;;)
    {
    }
}

int __sys_close(int fd)
{
    (void)fd;
    return -1;
}

int __sys_flen(int fd)
{
    (void)fd;
    return -1;
}

int __sys_istty(int fd)
{
    (void)fd;
    return -1;
}

int __sys_remove(const char *name, int len)
{
    (void)name;
    (void)len;
    return -1;
}

int __sys_seek(int fd, int pos)
{
    (void)fd;
    (void)pos;
    return -1;
}

int __sys_tmpnam(char *buf, int id, int len)
{
    (void)buf;
    (void)id;
    (void)len;
    return -1;
}

int __sys_write(int fd, const void *buf, int len)
{
    (void)fd;
    (void)buf;
    return len;
}
