/*
 * FT-710 IFDSP M33 (T24): _Cdigit_value, recreated from the image's C library (NXP Redlib, closed source) at 0x85BDC.
 * Value of one digit character in a base, or -1 [fact: 0x85BDC].
 */
#include "ctype.h"

int _Cdigit_value(int c, int base)
{
    unsigned int t = redlib_ctype_table[c];
    int v;

    if (t & _CT_DIGIT)
    {
        v = c - '0';
    }
    else if (t & _CT_LOWER)
    {
        v = c - 'a' + 10;
    }
    else if (t & _CT_UPPER)
    {
        v = c - 'A' + 10;
    }
    else
    {
        v = -1;
    }
    if (v >= base)
    {
        v = -1;
    }
    return v;
}
