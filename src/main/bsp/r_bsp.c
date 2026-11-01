/* Renesas RX BSP pieces of the MAIN image, recreated for T24 (docs/code/main/bsp.md). */
#include <stdint.h>
#include "iodefine.h"

/* R_BSP_InterruptRequestEnable 0xFFF8FF82 / ..Disable 0xFFF8FFA3: set / clear bit (v & 7) of ICU.IER[v >> 3]
 * (0x87200 + v / 8) for vector v, as one BSET/BCLR on the byte [fact] */
void R_BSP_InterruptRequestEnable(uint32_t vector)
{
    volatile uint8_t *ier = (volatile uint8_t *)(0x87200u + (vector >> 3));
    *ier |= (uint8_t)(1u << (vector & 7u));
}

void R_BSP_InterruptRequestDisable(uint32_t vector)
{
    volatile uint8_t *ier = (volatile uint8_t *)(0x87200u + (vector >> 3));
    *ier &= (uint8_t)~(1u << (vector & 7u));
}

/* CC-RX intrinsic helpers 0xFFF9124C..0xFFF912B9: return a control register or a part of the accumulator; no
 * callers [fact: bsp.md] */
uint32_t get_bpsw(void)
{
    uint32_t v;
    __asm__ volatile("mvfc bpsw, %0" : "=r"(v));
    return v;
}

uint32_t get_bpc(void)
{
    uint32_t v;
    __asm__ volatile("mvfc bpc, %0" : "=r"(v));
    return v;
}

uint32_t get_extb(void)
{
    /* EXTB is an RXv2 control register that GNU as for RXv1 does not accept: MVFC EXTB, R1 as its encoding */
    register uint32_t v __asm__("r1");
    __asm__ volatile(".byte 0xfd, 0x6a, 0xd1" : "=r"(v));
    return v;
}

uint32_t get_acc_hi(void)
{
    uint32_t v;
    __asm__ volatile("mvfachi %0" : "=r"(v));
    return v;
}

uint32_t get_acc_mi(void)
{
    uint32_t v;
    __asm__ volatile("mvfacmi %0" : "=r"(v));
    return v;
}
