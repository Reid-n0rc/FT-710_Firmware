/*
 * FT-710 IFDSP M33 (T24): fflush, recreated from the image's C library (NXP Redlib, closed source) at 0x85DF0.
 * NULL flushes all three standard streams [fact: 0x85DF0].
 */
#include "redlib_file.h"

int fflush(redlib_file_t *f)
{
    int r;

    if (f == 0)
    {
        r = 0;
        for (int i = 0; i < 3; i++)
        {
            if (_Cfflush1(&__redlib_streams[i]) != 0)
            {
                r = -1;
            }
        }
        return r;
    }
    return _Cfflush1(f);
}
