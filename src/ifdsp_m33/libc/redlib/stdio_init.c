/*
 * FT-710 IFDSP M33 (T24): stdio_init, recreated from the image's C library (NXP Redlib, closed source) at 0x84E38.
 * Opens stdin/stdout/stderr on host handles 0/1/2, unbuffered [fact: 0x84E38]; __main calls it before main.
 */
#include <stddef.h>
#include "redlib_file.h"

extern int setvbuf(redlib_file_t *f, char *buf, int mode, size_t size);

void stdio_init(void)
{
    _Cfdopen(0, "r", &__redlib_streams[0]);
    setvbuf(&__redlib_streams[0], NULL, 0x400, 0x100);
    _Cfdopen(1, "w", &__redlib_streams[1]);
    setvbuf(&__redlib_streams[1], NULL, 0x400, 0x100);
    _Cfdopen(2, "w", &__redlib_streams[2]);
    setvbuf(&__redlib_streams[2], NULL, 0x400, 0x100);
}
