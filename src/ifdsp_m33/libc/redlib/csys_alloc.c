/*
 * FT-710 IFDSP M33 (T24): _Csys_alloc, recreated from the image's C library (NXP Redlib, closed source) at 0x84E04.
 * malloc that stops the program on failure [fact: 0x84E04].
 */
#include <stddef.h>

extern void *malloc(size_t n);
extern int __sys_write(int fd, const void *buf, int len);
extern void __sys_appexit(void);

void *_Csys_alloc(size_t n)
{
    void *p = malloc(n);
    if (p == NULL)
    {
        __sys_write(0, "*** _Csys_alloc failed\n", 23);
        __sys_appexit();
    }
    return p;
}
