/* Float helpers for the CC-RX code shapes (T24 MAIN round 5).
 *
 * FTOU: CC-RX converts a float to an unsigned integer with FTOU, an RXv2 instruction (RXv2 software manual
 * R01US0071EJ0100 p. 106: truncation towards 0; NaN or out of range: FFFFFFFFh for sign 0, 00000000h for sign 1,
 * Table 1.5). GCC for RX (-mcpu=rx600, RXv1) has no FTOU and calls libgcc's __fixunssfsi for an unsigned cast, which
 * differs for negative values (-5.0 gives FFFFFFFBh there and 0 with FTOU), so ftou() is written out with the signed
 * cast (FTOI) for the range they share.
 *
 * NaN: GCC for RX tests a float compare with the S flag alone (a < b: BN, a >= b: BPZ) [fact: the objects, e.g.
 * swr_meter_protect], so with a NaN "a >= b" is true; CC-RX's BLT / BGE also read O (FCMP sets it for an unordered
 * pair, p. 90). Where a NaN can reach a compare, the code tests it with is_nan() on the bits: GCC takes its own
 * compares as IEEE ones and drops a "v != v" next to them as redundant (round 5, swr_meter_protect). */
#ifndef FPU_CONV_H
#define FPU_CONV_H

#include <stdint.h>

static inline uint32_t float_bits(float v)
{
    union { float f; uint32_t u; } b = {v};
    return b.u;
}

static inline int is_nan(float v)
{
    return (float_bits(v) & 0x7FFFFFFFu) > 0x7F800000u;
}

static inline uint32_t ftou(float v)
{
    if (is_nan(v))
        return (float_bits(v) >> 31) ? 0 : 0xFFFFFFFFu;
    if (v >= 0.0f) {
        if (v < 2147483648.0f)
            return (uint32_t)(int32_t)v;
        if (v < 4294967296.0f)
            return (uint32_t)(int32_t)(v - 2147483648.0f) + 0x80000000u;   /* v - 2^31 is exact up here */
        return 0xFFFFFFFFu;
    }
    return 0;                              /* (-1, 0) truncates to 0; <= -1 and -inf are out of range */
}

#endif
