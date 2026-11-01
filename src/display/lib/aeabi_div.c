/*
 * FT-710 DISPLAY (T24 round 3): the integer division helpers of the image's armcc run-time library (run-time ABI,
 * ARM IHI 0043), recreated in C. armcc's versions are unrolled shift-and-subtract ladders (0x20155480..0x201556AB);
 * the C below computes the same quotient and remainder bit by bit, without a C division (which GCC would turn into a
 * call of these very functions). The quotient/remainder pairs come back in r0:r1, as the ABI has them, by returning a
 * 64-bit value (low word quotient, high word remainder).
 *
 * Division by zero: the image returns quotient 0 and the dividend as the remainder; its __aeabi_idiv0 hook is a nop
 * [fact: 0x2015569C push {r0, lr}; movs r0, #0; nop; pop {r1, pc}].
 */
#include <stdint.h>

/* unsigned 32-bit: (q, r) */
static uint64_t udivmod32(uint32_t n, uint32_t d)
{
    uint32_t q = 0;
    uint64_t r = 0; /* below 2 d, so 33 bits */

    if (d == 0)
    {
        return (uint64_t)n << 32;
    }
    for (int i = 31; i >= 0; i--)
    {
        r = (r << 1) | ((n >> i) & 1);
        if (r >= d)
        {
            r -= d;
            q |= 1U << i;
        }
    }
    return q | r << 32;
}

/* 0x20156260 (A32): __aeabi_uidivmod(n, d) -> q in r0, r in r1 */
uint64_t __aeabi_uidivmod(uint32_t n, uint32_t d)
{
    return udivmod32(n, d);
}

/* 0x20155480 (A32): __aeabi_idivmod(n, d) -> q in r0, r in r1, truncating toward zero (the remainder has the sign of
 * n) [fact: the sign fix-up 0x20155684..0x2015568C] */
uint64_t __aeabi_idivmod(int32_t n, int32_t d)
{
    if (d == 0)
    {
        return (uint64_t)(uint32_t)n << 32; /* the dividend as passed, also when negative [fact: emulation, trial 159] */
    }
    uint32_t un = n < 0 ? 0U - (uint32_t)n : (uint32_t)n;
    uint32_t ud = d < 0 ? 0U - (uint32_t)d : (uint32_t)d;
    uint64_t qr = udivmod32(un, ud);
    uint32_t q  = (uint32_t)qr, r = (uint32_t)(qr >> 32);

    if ((n ^ d) < 0)
    {
        q = 0U - q;
    }
    if (n < 0)
    {
        r = 0U - r;
    }
    return q | (uint64_t)r << 32;
}

/* 0x20155FEC (A32): __rt_udiv10(n) -> n / 10 in r0, n % 10 in r1: q = (n - n/4 + ...) >> 3 by shifts and adds, then one
 * correction step [fact] */
uint64_t __rt_udiv10(uint32_t n)
{
    uint32_t q = n - (n >> 2);
    int32_t r;

    q += q >> 4;
    q += q >> 8;
    q = (q + (q >> 16)) >> 3;
    r = (int32_t)(n - 10 - q * 10);
    if (r < 0)
    {
        r += 10;
    }
    else
    {
        q++;
    }
    return q | (uint64_t)(uint32_t)r << 32;
}

/* _ll_udiv10 (0x20155A10) is in lib/aeabi_ldiv.S: it also returns the remainder in r2 (T24 round 6) */
