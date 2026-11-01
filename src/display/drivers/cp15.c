/*
 * FT-710 DISPLAY (T24 round 3): MMU and cache maintenance (CP15) of the image, 0x20100D0C..0x20101183, recreated in C
 * with inline CP15 accessors. In the image these are hand-written assembly (register-only, no stack frame for most,
 * conditional mcr) [inference: no compiler output looks like 0x20100F04..0x20100F18]; names and purposes as in
 * docs/code/display/boot-rtos.md ("Boot / MMU", "MMU", "L1 data cache maintenance", "CP15 cache control").
 *
 * The L1 translation table is at 0x2044C000, 4096 one-megabyte section entries [fact: literal 0x20101184]. The SCTLR
 * writes keep its should-be-zero / should-be-one bits: & ~0x84188380 | 0x00C50078 [fact: literals 0x20100D04,
 * 0x20100D08].
 *
 * Four functions have no name in Ghidra yet (FUN_...); the names used here are inferred from their CP15 operations
 * (src/display/aliases.tsv maps them to their addresses): mmu_disable 0x20100D0C, mmu_enable 0x20100D6C,
 * mmu_set_cacheable_ro 0x20100DC0, icache_invalidate_range 0x20100F84. Three are renamed after their operations
 * (below, before dcache_clean_invalidate_range).
 */
#include <stdint.h>

#define L1_TABLE ((volatile uint32_t *)0x2044C000)
#define SCTLR_SBZ 0x84188380U
#define SCTLR_SBO 0x00C50078U
#define SCTLR_M (1U << 0)
#define SCTLR_C (1U << 2)
#define SCTLR_Z (1U << 11)
#define SCTLR_I (1U << 12)

#define CP15_READ(op1, crn, crm, op2)                                                         \
    ({                                                                                        \
        uint32_t v_;                                                                          \
        __asm__ volatile("mrc p15, " #op1 ", %0, " #crn ", " #crm ", " #op2 : "=r"(v_));      \
        v_;                                                                                   \
    })
#define CP15_WRITE(op1, crn, crm, op2, v) \
    __asm__ volatile("mcr p15, " #op1 ", %0, " #crn ", " #crm ", " #op2 ::"r"(v) : "memory")
#define DSB() __asm__ volatile("dsb sy" ::: "memory")
#define ISB() __asm__ volatile("isb sy" ::: "memory")

static inline uint32_t sctlr_read(void) { return CP15_READ(0, c1, c0, 0); }
static inline void sctlr_write(uint32_t v) { CP15_WRITE(0, c1, c0, 0, v); }
static inline uint32_t ctr_line(void) { return 16U << (CP15_READ(1, c0, c0, 0) & 7); } /* CCSIDR line size */

/* 0x20100D0C: invalidate the TLB, the I-cache and the branch predictor, clear ACTLR bit 1, then SCTLR I, C, M off */
void mmu_disable(void)
{
    CP15_WRITE(0, c8, c7, 0, 0);  /* TLBIALL */
    DSB();
    CP15_WRITE(0, c7, c5, 0, 0);  /* ICIALLU */
    CP15_WRITE(0, c7, c5, 6, 0);  /* BPIALL */
    ISB();
    CP15_WRITE(0, c1, c0, 1, CP15_READ(0, c1, c0, 1) & ~2U); /* ACTLR */
    sctlr_write(sctlr_read() & ~(SCTLR_I | SCTLR_C | SCTLR_M));
}

/* 0x20100D48: the L1 table as flat 1-MB sections, VA = PA, attributes 0x10C02 [fact: literal 0x20101188] */
void mmu_l1_table_init(void)
{
    uint32_t e = 0x10C02;

    for (uint32_t n = 0x1000; n != 0; n--)
    {
        L1_TABLE[0x1000 - n] = e;
        e += 0x100000;
    }
}

/* 0x20100D6C: TTBR0 = table | 1, TTBCR = 0, DACR = 0x55555555 (all client), SCTLR M, Z, I, C on, ACTLR bit 1 on
 * [fact: literal 0x2010118C] */
void mmu_enable(void)
{
    CP15_WRITE(0, c2, c0, 0, 0x2044C000U | 1);
    CP15_WRITE(0, c2, c0, 2, 0);
    CP15_WRITE(0, c3, c0, 0, 0x55555555U);
    sctlr_write((sctlr_read() & ~SCTLR_SBZ) | SCTLR_SBO | SCTLR_M | SCTLR_Z | SCTLR_I | SCTLR_C);
    CP15_WRITE(0, c1, c0, 1, CP15_READ(0, c1, c0, 1) | 2U);
}

/* TLBIALL, then BPIALL (c7,c5,6: the branch predictor, not the I-cache as docs/code/display/boot-rtos.md had it) */
static void tlb_bp_flush(void)
{
    CP15_WRITE(0, c8, c7, 0, 0); /* TLBIALL */
    DSB();
    CP15_WRITE(0, c7, c5, 6, 0); /* BPIALL */
    DSB();
    ISB();
}

/* 0x20100DC0: (addr, size): the sections of the range cacheable (C = B = 1) and read-only (AP[2] = 1, AP = 3), S = 0
 * [fact: bic 0x10000, orr 0x8C00, orr 0xC] [inference: "read-only" from the AP encoding] */
void mmu_set_cacheable_ro(uint32_t addr, uint32_t size)
{
    uint32_t end = (addr + size + 0xFFFFF) >> 20;

    for (uint32_t i = addr >> 20; i != end; i++)
    {
        L1_TABLE[i] = (L1_TABLE[i] & ~0x1000CU) | 0x8C00U | 0xCU;
    }
    tlb_bp_flush();
}

/* 0x20100E24: (addr, size): the sections of the range cacheable read-write: AP = 3, C = B = 1, AP[2] = S = 0 [fact] */
void mmu_set_cacheable(uint32_t addr, uint32_t size)
{
    uint32_t end = (addr + size + 0xFFFFF) >> 20;

    for (uint32_t i = addr >> 20; i != end; i++)
    {
        L1_TABLE[i] = (L1_TABLE[i] & ~0x18C0CU) | 0xC00U | 0xCU;
    }
    tlb_bp_flush();
}

/* 0x20100E8C: (va, pa, size): new section base addresses for the range, attributes kept [fact] */
void mmu_map_range(uint32_t va, uint32_t pa, uint32_t size)
{
    uint32_t end = (va + size + 0xFFFFF) >> 20;

    pa &= ~0xFFFFFU;
    for (uint32_t i = va >> 20; i != end; i++)
    {
        L1_TABLE[i] = (L1_TABLE[i] & 0xFFFFFU) + pa;
        pa += 0x100000;
    }
    tlb_bp_flush();
}

/* 0x20100EFC: SCTLR I off, if it is on; returns the SCTLR value read (or written) [fact] */
uint32_t icache_disable(void)
{
    uint32_t v = sctlr_read();

    if (v & SCTLR_I)
    {
        v = ((v & ~SCTLR_SBZ) | SCTLR_SBO) & ~SCTLR_I;
        sctlr_write(v);
    }
    return v;
}

/* 0x20100F20: SCTLR C off, if it is on [fact] */
uint32_t dcache_disable(void)
{
    uint32_t v = sctlr_read();

    if (v & SCTLR_C)
    {
        v = ((v & ~SCTLR_SBZ) | SCTLR_SBO) & ~SCTLR_C;
        sctlr_write(v);
    }
    return v;
}

/* 0x20100F44: SCTLR I on [fact] */
uint32_t icache_enable(void)
{
    uint32_t v = (sctlr_read() & ~SCTLR_SBZ) | SCTLR_SBO | SCTLR_I;

    sctlr_write(v);
    return v;
}

/* 0x20100F64: SCTLR C on [fact] */
uint32_t dcache_enable(void)
{
    uint32_t v = (sctlr_read() & ~SCTLR_SBZ) | SCTLR_SBO | SCTLR_C;

    sctlr_write(v);
    return v;
}

/* 0x20100F84: (addr, size): ICIMVAU per cache line over the range, or ICIALLU when addr or size is 0; then BPIALL
 * [fact] */
void icache_invalidate_range(uint32_t addr, uint32_t size)
{
    if (addr != 0 && size != 0)
    {
        uint32_t line = ctr_line(), end = addr + size;
        for (addr &= ~(line - 1); addr < end; addr += line)
        {
            CP15_WRITE(0, c7, c5, 1, addr);
        }
    }
    else
    {
        CP15_WRITE(0, c7, c5, 0, addr);
    }
    CP15_WRITE(0, c7, c5, 6, addr);
    DSB();
    ISB();
}

/* a call in the image (bl 0x201010E0) [fact], so not inlined here either */
void dcache_setway_all(int op) __attribute__((noinline));

/* The data-cache range functions, with the CP15 operation each one issues [fact: the mcr encodings, ARMv7-A ARM
 * B4.2.1: c7,c6,1 DCIMVAC, c7,c10,1 DCCMVAC, c7,c14,1 DCCIMVAC]. Two of them do the opposite of their Ghidra names:
 * 0x20100FD8 ("dcache_invalidate_range") cleans and invalidates, 0x20101088 ("dcache_clean_invalidate_range") only
 * invalidates; each falls back to the matching set/way operation, and 0x2010101C ("dcache_invalidate_all") cleans and
 * invalidates by set/way. They carry their corrected names here (T24 round 3; src/display/aliases.tsv). */

/* 0x20100FD8: (addr, size): DCCIMVAC per line, or clean and invalidate by set/way when addr or size is 0 */
void dcache_clean_invalidate_range(uint32_t addr, uint32_t size)
{
    if (addr == 0 || size == 0)
    {
        dcache_setway_all(2);
        return;
    }
    uint32_t line = ctr_line(), end = addr + size;
    for (addr &= ~(line - 1); addr < end; addr += line)
    {
        CP15_WRITE(0, c7, c14, 1, addr);
    }
    DSB();
}

/* 0x2010101C: clean and invalidate the whole data cache by set/way */
void dcache_clean_invalidate_all(void)
{
    dcache_setway_all(2);
}

/* 0x20101030: (addr, size): DCCMVAC per line, or clean by set/way when addr or size is 0 */
void dcache_clean_range(uint32_t addr, uint32_t size)
{
    if (addr == 0 || size == 0)
    {
        dcache_setway_all(1);
        return;
    }
    uint32_t line = ctr_line(), end = addr + size;
    for (addr &= ~(line - 1); addr < end; addr += line)
    {
        CP15_WRITE(0, c7, c10, 1, addr);
    }
    DSB();
}

/* 0x20101088: (addr, size): DCIMVAC per line, or invalidate by set/way when addr or size is 0 */
void dcache_invalidate_range(uint32_t addr, uint32_t size)
{
    if (addr == 0 || size == 0)
    {
        dcache_setway_all(0);
        return;
    }
    uint32_t line = ctr_line(), end = addr + size;
    for (addr &= ~(line - 1); addr < end; addr += line)
    {
        CP15_WRITE(0, c7, c6, 1, addr);
    }
    DSB();
}

/* 0x201010E0: (op): every set and way of every data or unified cache level in CLIDR (up to the level of coherence):
 * op 0 (and below) invalidate (DCISW), 1 clean (DCCSW), 2 (and above) clean and invalidate (DCCISW) [fact: cmp op, #1;
 * mcrlt c7,c6,2 / mcreq c7,c10,2 / mcrgt c7,c14,2 at 0x20101148..0x20101154; docs/code/display/boot-rtos.md had 0 and
 * 2 the other way round until T24 round 3]. The ARM ARM's set/way loop: CSSELR = level, CCSIDR line size, ways (& 0x3FF, clz
 * for the shift) and sets (& 0x7FFF) [fact: literals 0x20100CFC, 0x20100D00]; CSSELR = 0 at the end. */
void dcache_setway_all(int op)
{
    uint32_t clidr = CP15_READ(1, c0, c0, 1);
    uint32_t loc2  = (clidr & 0x07000000U) >> 23; /* level of coherence * 2 */

    if (loc2 == 0)
    {
        CP15_WRITE(2, c0, c0, 0, 0);
        return;
    }
    for (uint32_t lvl2 = 0; (int)lvl2 < (int)loc2; lvl2 += 2)
    {
        uint32_t ctype = (clidr >> (lvl2 + (lvl2 >> 1))) & 7;
        if ((int)ctype < 1)
        {
            CP15_WRITE(2, c0, c0, 0, 0); /* no cache at this level: stop, without the DSB [fact: blt 0x20101178] */
            return;
        }
        if (ctype == 1)
        {
            continue; /* instruction cache only */
        }
        CP15_WRITE(2, c0, c0, 0, lvl2);
        ISB();
        uint32_t ccsidr = CP15_READ(1, c0, c0, 0);
        uint32_t lshift = (ccsidr & 7) + 4;
        uint32_t ways   = (ccsidr >> 3) & 0x3FF;
        uint32_t wshift = ways ? (uint32_t)__builtin_clz(ways) : 32;
        int32_t set     = (int32_t)((ccsidr >> 13) & 0x7FFF);
        do
        {
            int32_t way = (int32_t)ways;
            do
            {
                uint32_t sw = lvl2 | ((uint32_t)set << lshift) | (wshift < 32 ? (uint32_t)way << wshift : 0);
                if (op < 1)
                {
                    CP15_WRITE(0, c7, c6, 2, sw); /* DCISW */
                }
                else if (op == 1)
                {
                    CP15_WRITE(0, c7, c10, 2, sw); /* DCCSW */
                }
                else
                {
                    CP15_WRITE(0, c7, c14, 2, sw); /* DCCISW */
                }
            } while (--way >= 0);
        } while (--set >= 0);
    }
    DSB();
    CP15_WRITE(2, c0, c0, 0, 0);
}
