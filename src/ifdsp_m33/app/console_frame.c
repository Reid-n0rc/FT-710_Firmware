/*
 * FT-710 IFDSP M33: checks on machine-mode frames (T24, recreated from the image 0x86014..0x8606A).
 * They sit after the HardFault handler in link order, so they are their own object in the image [fact: layout].
 */
#include <stdlib.h>
#include <string.h>
#include "console.h"

/* 1 if the string looks hexadecimal.
   Note [fact: 0x86014]: s advances while i counts up and the bound is strlen of the rest, so only about the first half
   of the characters is checked. For MAIN's frames ("rAAAAcc", 6 characters after the command) that is AAA. */
int is_hex_string(const char *s)
{
    for (size_t i = 0; i < strlen(s); i++)
    {
        char c = *s++;
        if (!(((unsigned)(c - '0') <= 9U) || ((unsigned)((c & ~0x20) - 'A') <= 5U)))
        {
            return 0;
        }
    }
    return 1;
}

/* 1 if the two hex digits after the first len characters are their 8-bit sum. */
int frame_checksum_ok(const char *frame, int len)
{
    const char *end = frame + len;
    uint8_t sum     = 0;

    while (frame != end)
    {
        sum += (uint8_t)*frame++;
    }
    return (uint8_t)strtoul(frame, NULL, 16) == sum;
}
