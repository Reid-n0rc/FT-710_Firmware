/*
 * FT-710 IFDSP M33 (T24): remove, recreated from the image's C library (NXP Redlib, closed source) at 0x87702.
 * strlen, then __sys_remove(name, len) [fact: 0x87702].
 */
#include "redlib_file.h"

extern unsigned int strlen(const char *s);

int remove(const char *name)
{
    return __sys_remove(name, (int)strlen(name));
}
