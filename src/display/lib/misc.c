/*
 * FT-710 DISPLAY (T24 round 3): small helpers of the application and the armcc library, recreated from the image
 * (docs/code/display/boot-rtos.md "CP15 cache control and small helpers", "Small library helpers"; gui.md, input.md,
 * update.md for their users). Names and purposes as in docs/code/display/.
 */
#include <stddef.h>
#include <stdint.h>

extern void __aeabi_memcpy(void *dst, const void *src, size_t n);
extern size_t strlen(const char *s);

/* 0x201341CC: (a, b): a + b clamped to 0..255 [fact] */
unsigned int clamp_add_u8(int a, int b)
{
    int v = a + b;

    if (v < 0)
    {
        return 0;
    }
    if (v < 0x100)
    {
        return (unsigned int)v & 0xFF;
    }
    return 0xFF;
}

/* 0x20135448: one xorshift32 step (13, 17, 15) [fact] */
uint32_t xorshift32_step(uint32_t x)
{
    x ^= x << 13;
    x ^= x >> 17;
    return x ^ (x << 15);
}

/* 0x20135458: two BCD digits to binary, as a signed char [fact: the image sign-extends the byte (sxtb)] */
int bcd_to_bin(unsigned int v)
{
    return (signed char)((v & 0xF) + (unsigned char)(v >> 4) * 10);
}

/* 0x20135470: big-endian 16-bit load [fact] */
uint16_t be16_load(const uint8_t *p)
{
    return (uint16_t)(p[0] << 8 | p[1]);
}

/* 0x20135488: (v, dst): big-endian 16-bit store [fact] */
void be16_store(unsigned int v, uint8_t *dst)
{
    dst[0] = (uint8_t)(v >> 8);
    dst[1] = (uint8_t)v;
}

/* 0x201354BC: number of decimal digits of v (1..10) [fact] */
uint8_t u32_decimal_digits(uint32_t v)
{
    uint8_t n = 10;

    for (uint32_t p = 1000000000U; v < p; p /= 10)
    {
        n--;
    }
    return n;
}

/* 0x201354EC: removes trailing spaces; the length is kept in 8 bits [fact: and #0xFF after strlen] */
void str_rtrim(char *s)
{
    uint8_t n = (uint8_t)strlen(s);

    while (n != 0 && s[n - 1] == ' ')
    {
        s[n - 1] = 0;
        n--;
    }
}

/* 0x20157214: (this, dst, src, n): n / 4 words dst = ~src; reads the AF-FFT record [fact] */
void copy_inverted_words(void *self, uint32_t *dst, const uint32_t *src, uint32_t n)
{
    for (n >>= 2; n != 0; n--)
    {
        *dst++ = ~*src++;
    }
}

/* 0x201577F8: a second copy of copy_inverted_words (scope_history_push) [fact] */
void copy_inverted_words_b(void *self, uint32_t *dst, const uint32_t *src, uint32_t n)
{
    for (n >>= 2; n != 0; n--)
    {
        *dst++ = ~*src++;
    }
}

/* 0x201636CC: copies 5 bytes (encoder events, E1/E2 frames) [fact] */
void copy5(uint8_t *dst, const uint8_t *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
}

/* 0x201637F0: (dst, byte): fills 8 bytes (two words) with byte [fact] */
void fill8(uint32_t *dst, unsigned int c)
{
    uint32_t w = (c & 0xFF) | (c & 0xFF) << 8;

    w |= w << 16;
    dst[0] = w;
    dst[1] = w;
}

/* 0x20163864 (Thumb): 1 for '0'..'9' [fact] */
int is_decimal_digit(int c)
{
    return (unsigned int)(c - '0') < 10;
}

/* 0x201640EC, 0x20164104, 0x2016411C: (dst, src): copy 10, 0x20 or 0x30 bytes, return dst; firmware-object version and
 * name fields [fact] */
void *copy10(void *dst, const void *src)
{
    __aeabi_memcpy(dst, src, 10);
    return dst;
}

void *copy32(void *dst, const void *src)
{
    __aeabi_memcpy(dst, src, 0x20);
    return dst;
}

void *copy48(void *dst, const void *src)
{
    __aeabi_memcpy(dst, src, 0x30);
    return dst;
}
