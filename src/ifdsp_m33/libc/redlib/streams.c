/*
 * FT-710 IFDSP M33 (T24): the three standard streams of the image's C library (NXP Redlib, closed source): stdin,
 * stdout, stderr at 0x88B78, 0x88BB4, 0x88BF0 [fact: stdio_init 0x84E38, fflush 0x85DF0].
 */
#include "redlib_file.h"

redlib_file_t __redlib_streams[3];
