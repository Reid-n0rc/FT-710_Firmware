/*
 * FT-710 DISPLAY (T24 round 7): the DMAC channel set-ups, 0x20137080..0x20137E93, recreated from the image.
 *
 * Five peripheral channels move the SPI links' frames (docs/code/display/spi-links.md, "DMA"): 3 memory -> RSPI4
 * (DSP link transmit), 4 RSPI4 -> memory (DSP receive), 5 RSPI2 -> memory (SDR scope frames), 9 memory -> RSPI0 or 1,
 * 10 RSPI0 or 1 -> memory (PC link); channel 8 is a memory-to-memory copier. Each set-up follows the same steps
 * [fact: the code of each]: stop and reset the channel (CHCTRL CLREN, SWRST), mask its end interrupt at the GIC,
 * clear the driver's done flag, select the request source (DMARSn, two channels per register), clear CHCFG and
 * write its fields one by one in a fixed order, clear CHITVL and CHEXT, set the next-0 addresses and byte count,
 * then (some) the DCTRL priority bit, the ISR object, the GIC interrupt, and CHCTRL SETEN.
 *
 * Registers (RZ/A1H hardware manual, DMAC chapter): channel n < 8 at 0xE8200000 + 0x40 n, n >= 8 at
 * 0xE8200400 + 0x40 (n - 8): N0SA +0, N0DA +4, N0TB +8, CHCTRL +0x28, CHCFG +0x2C, CHITVL +0x30, CHEXT +0x34;
 * DCTRL 0xE8200300 (0..7) and 0xE8200700 (8..15); DMARSn 0xFCFE1000 + 4 (n / 2), the odd channel in bits 31..16.
 */
#include "display.h"
#include "norti.h"

#define DMAC_CH(n) (0xE8200000U + ((n) >= 8 ? 0x400U + 0x40U * ((n) - 8) : 0x40U * (n)))
#define DMAC_N0SA(n) REG32(DMAC_CH(n) + 0x00U)
#define DMAC_N0DA(n) REG32(DMAC_CH(n) + 0x04U)
#define DMAC_N0TB(n) REG32(DMAC_CH(n) + 0x08U)
#define DMAC_CHCTRL(n) REG32(DMAC_CH(n) + 0x28U)
#define DMAC_CHCFG(n) REG32(DMAC_CH(n) + 0x2CU)
#define DMAC_CHITVL(n) REG32(DMAC_CH(n) + 0x30U)
#define DMAC_CHEXT(n) REG32(DMAC_CH(n) + 0x34U)
#define DMAC_DCTRL_0_7 REG32(0xE8200300U)
#define DMAC_DCTRL_8_15 REG32(0xE8200700U)
#define DMAC_DMARS(n) REG32(0xFCFE1000U + 4U * ((n) / 2))

#define CHCTRL_SETEN 0x01U
#define CHCTRL_CLREN 0x02U
#define CHCTRL_STG 0x04U
#define CHCTRL_SWRST 0x08U

/* GIC ids of the channel end interrupts: DMAINT n = 0x29 + n [fact: the gic_disable_irq / gic_enable_irq
 * arguments, 0x2C for channel 3 .. 0x33 for 10] */
#define DMAINT(n) (0x29 + (n))

void gic_disable_irq(int id);   /* 0x201177A0 */

typedef void (*dmac_callback_t)(void);

extern volatile uint32_t dmac_done[5];        /* 0x20808A8C: channels 3, 4, 5, 9, 10 (set by dmac3_isr only) */
extern dmac_callback_t dmac_callback[5];      /* 0x20808AA0: channels 3, 4, 5, 9, 10 (3 is never called) */
extern const T_CISR dmac_cisr[5];             /* 0x204200B0: the end-interrupt ISR objects of 3, 4, 5, 9, 10 */

/* the CHCFG fields in the order the image writes them [fact: every set-up below, e.g. 0x201370D4..0x20137228] */
typedef struct
{
    uint8_t dds, sds, dad, sad, dms, rsel, sbe, dem, ren, rsw, tm, am, lvl, hien, loen, reqd, sel;
} dmac_chcfg_t;

static inline __attribute__((always_inline)) void dmac_set_chcfg(volatile uint32_t *cfg, const dmac_chcfg_t *c)
{
    *cfg = 0;
    reg_rmw32(cfg, c->dds, 16, 0xF0000);     /* destination data size */
    reg_rmw32(cfg, c->sds, 12, 0xF000);      /* source data size */
    reg_rmw32(cfg, c->dad, 21, 0x200000);    /* destination address fixed */
    reg_rmw32(cfg, c->sad, 20, 0x100000);    /* source address fixed */
    reg_rmw32(cfg, c->dms, 31, 0x80000000U); /* register mode */
    reg_rmw32(cfg, c->rsel, 28, 0x10000000);
    reg_rmw32(cfg, c->sbe, 27, 0x8000000);   /* sweep buffer */
    reg_rmw32(cfg, c->dem, 24, 0x1000000);   /* end interrupt masked */
    reg_rmw32(cfg, c->ren, 30, 0x40000000);
    reg_rmw32(cfg, c->rsw, 29, 0x20000000);
    reg_rmw32(cfg, c->tm, 22, 0x400000);     /* block transfer */
    reg_rmw32(cfg, c->am, 8, 0x700);         /* acknowledge mode */
    reg_rmw32(cfg, c->lvl, 6, 0x40);         /* level request */
    reg_rmw32(cfg, c->hien, 5, 0x20);
    reg_rmw32(cfg, c->loen, 4, 0x10);
    reg_rmw32(cfg, c->reqd, 3, 8);           /* request direction: destination */
    reg_rmw32(cfg, c->sel, 0, 7);            /* channel within the group */
}

#define DMAC_STOP_RESET(n)                                                                                         \
    do                                                                                                             \
    {                                                                                                              \
        DMAC_CHCTRL(n) |= CHCTRL_CLREN;                                                                            \
        DMAC_CHCTRL(n) |= CHCTRL_SWRST;                                                                            \
    } while (0)

/* 0x20137080: (source, RSPI4 SPDR, bytes): channel 3, memory -> RSPI4 (DMARS1 = 0x131 in bits 31..16): 16-bit
 * source, 8-bit destination, destination fixed, SPRI-paced; the ISR and its GIC id; not started [fact] */
void dmac3_rspi4_tx_setup(uint32_t src, uint32_t dst, uint32_t bytes)
{
    static const dmac_chcfg_t cfg = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 1, 3};
    DMAC_STOP_RESET(3);
    gic_disable_irq(DMAINT(3));
    dmac_done[0] = 0;
    DMAC_DMARS(3) = 0x1310000;
    dmac_set_chcfg(&DMAC_CHCFG(3), &cfg);
    DMAC_CHITVL(3) = 0;
    DMAC_CHEXT(3) = 0;
    DMAC_N0SA(3) = src;
    DMAC_N0DA(3) = dst;
    DMAC_N0TB(3) = bytes;
    reg_rmw32(&DMAC_DCTRL_0_7, 1, 0, 1);
    if (itron_acre_isr(0, &dmac_cisr[0]) > 0)
    {
        gic_enable_irq(DMAINT(3));
    }
}

/* 0x20137278: (RSPI2 SPDR, destination, bytes): channel 5, RSPI2 -> memory (DMARS2 |= 0x12A in bits 31..16): 8-bit,
 * source fixed, sweep buffer, request by the source; the ISR, its GIC id and the channel started [fact] */
void dmac5_rspi2_rx_setup(uint32_t src, uint32_t dst, uint32_t bytes)
{
    static const dmac_chcfg_t cfg = {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 5};
    DMAC_STOP_RESET(5);
    gic_disable_irq(DMAINT(5));
    dmac_done[2] = 0;
    DMAC_DMARS(5) |= 0x12A0000;
    dmac_set_chcfg(&DMAC_CHCFG(5), &cfg);
    DMAC_CHITVL(5) = 0;
    DMAC_CHEXT(5) = 0;
    DMAC_N0SA(5) = src;
    DMAC_N0DA(5) = dst;
    DMAC_N0TB(5) = bytes;
    reg_rmw32(&DMAC_DCTRL_0_7, 1, 0, 1);
    if (itron_acre_isr(0, &dmac_cisr[2]) > 0)
    {
        gic_enable_irq(DMAINT(5));
        reg_rmw32(&DMAC_CHCTRL(5), 1, 0, 1);
    }
}

/* 0x20137490: channel 3's end: the done flag (the only ISR that sets it) [fact] */
void dmac3_isr(void)
{
    dmac_done[0] = 1;
}

/* 0x201374A0, 0x201376C4, 0x20137AEC, 0x20137D1C: channels 5, 4, 9, 10: the installed callback [fact] */
void dmac5_isr(void)
{
    dmac_callback[2]();
}

/* 0x201374AC: (RSPI4 SPDR, destination, bytes): channel 4, RSPI4 -> memory (DMARS2 |= 0x132 in bits 15..0): 8-bit
 * source, 16-bit destination, source fixed, sweep buffer; the ISR, its GIC id and the channel started [fact] */
void dmac4_rspi4_rx_setup(uint32_t src, uint32_t dst, uint32_t bytes)
{
    static const dmac_chcfg_t cfg = {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 4};
    DMAC_STOP_RESET(4);
    gic_disable_irq(DMAINT(4));
    dmac_done[1] = 0;
    DMAC_DMARS(4) |= 0x132;
    dmac_set_chcfg(&DMAC_CHCFG(4), &cfg);
    DMAC_CHITVL(4) = 0;
    DMAC_CHEXT(4) = 0;
    DMAC_N0SA(4) = src;
    DMAC_N0DA(4) = dst;
    DMAC_N0TB(4) = bytes;
    reg_rmw32(&DMAC_DCTRL_0_7, 1, 0, 1);
    if (itron_acre_isr(0, &dmac_cisr[1]) > 0)
    {
        gic_enable_irq(DMAINT(4));
        reg_rmw32(&DMAC_CHCTRL(4), 1, 0, 1);
    }
}

void dmac4_isr(void)
{
    dmac_callback[1]();
}

/* 0x201376D0: channel 8 as a memory copier: stop, reset, software trigger bit; source and destination size 7,
 * end interrupt masked, block transfer, AM 4 [fact] */
void dmac8_m2m_init(void)
{
    static const dmac_chcfg_t cfg = {7, 7, 0, 0, 0, 0, 0, 1, 0, 0, 1, 4, 1, 1, 0, 0, 0};

    DMAC_STOP_RESET(8);
    DMAC_CHCTRL(8) |= CHCTRL_STG;
    dmac_set_chcfg(&DMAC_CHCFG(8), &cfg);
    DMAC_CHITVL(8) = 0;
    DMAC_CHEXT(8) = 0;
    reg_rmw32(&DMAC_DCTRL_8_15, 1, 0, 1);
}

/* 0x201378B0: (destination, source, bytes): one copy on channel 8 [fact] */
void dmac8_m2m_start(uint32_t dst, uint32_t src, uint32_t bytes)
{
    DMAC_STOP_RESET(8);
    DMAC_CHCTRL(8) |= CHCTRL_STG;
    DMAC_N0SA(8) = src;
    DMAC_N0DA(8) = dst;
    DMAC_N0TB(8) = bytes;
    reg_rmw32(&DMAC_CHCTRL(8), 1, 0, 1);
}

/* 0x20137904 / 0x20137AF8: the end-interrupt ISR objects of channels 9 and 10 [fact] */
void dmac9_register_isr(void)
{
    itron_acre_isr(0, &dmac_cisr[3]);
}

/* 0x20137910: (RSPI0 if non-zero, else RSPI1): channel 9, memory -> RSPI SPDR (DMARS4 bits 31..16 = 0x121 or
 * 0x125), 8-bit, destination fixed, sweep buffer; GIC id on; addresses and start by the caller [fact] */
void dmac9_rspi_tx_setup(int rspi0)
{
    static const dmac_chcfg_t cfg = {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 1};
    DMAC_STOP_RESET(9);
    gic_disable_irq(DMAINT(9));
    dmac_done[3] = 0;
    DMAC_DMARS(9) &= 0xFFFF;
    DMAC_DMARS(9) |= rspi0 != 0 ? 0x1210000 : 0x1250000;
    dmac_set_chcfg(&DMAC_CHCFG(9), &cfg);
    DMAC_CHITVL(9) = 0;
    DMAC_CHEXT(9) = 0;
    gic_enable_irq(DMAINT(9));
}

void dmac9_isr(void)
{
    dmac_callback[3]();
}

void dmac10_register_isr(void)
{
    itron_acre_isr(0, &dmac_cisr[4]);
}

/* 0x20137B04: (RSPI0 if non-zero, else RSPI1; SPDR, destination, bytes): channel 10, RSPI -> memory (DMARS5 bits
 * 15..0 = 0x122 or 0x126), 8-bit, source fixed, sweep buffer; GIC id and the channel started [fact] */
void dmac10_rspi_rx_setup(int rspi0, uint32_t src, uint32_t dst, uint32_t bytes)
{
    static const dmac_chcfg_t cfg = {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 2};
    DMAC_STOP_RESET(10);
    gic_disable_irq(DMAINT(10));
    dmac_done[4] = 0;
    DMAC_DMARS(10) &= ~0xFFFFU;
    DMAC_DMARS(10) |= rspi0 != 0 ? 0x122 : 0x126;
    dmac_set_chcfg(&DMAC_CHCFG(10), &cfg);
    DMAC_CHITVL(10) = 0;
    DMAC_CHEXT(10) = 0;
    DMAC_N0SA(10) = src;
    DMAC_N0DA(10) = dst;
    DMAC_N0TB(10) = bytes;
    gic_enable_irq(DMAINT(10));
    reg_rmw32(&DMAC_CHCTRL(10), 1, 0, 1);
}

void dmac10_isr(void)
{
    dmac_callback[4]();
}

/* 0x20137D50..0x20137E93: channel enable (CHCTRL bit 0 = 1), disable (bit 0 = 0, read-modify-write), stop (bit 0
 * = 0, then CLREN), and the callback setters [fact] */
#define DMAC_ENABLE(n)                                                                                             \
    void dmac##n##_enable(void)                                                                                    \
    {                                                                                                              \
        reg_rmw32(&DMAC_CHCTRL(n), 1, 0, 1);                                                                       \
    }
#define DMAC_DISABLE(n)                                                                                            \
    void dmac##n##_disable(void)                                                                                   \
    {                                                                                                              \
        reg_rmw32(&DMAC_CHCTRL(n), 0, 0, 1);                                                                       \
    }
#define DMAC_STOP(n)                                                                                               \
    void dmac##n##_stop(void)                                                                                      \
    {                                                                                                              \
        reg_rmw32(&DMAC_CHCTRL(n), 0, 0, 1);                                                                       \
        reg_rmw32(&DMAC_CHCTRL(n), 1, 1, 2);                                                                       \
    }
#define DMAC_SET_CALLBACK(n, k)                                                                                    \
    void dmac##n##_set_callback(dmac_callback_t cb)                                                                \
    {                                                                                                              \
        dmac_callback[k] = cb;                                                                                     \
    }

DMAC_ENABLE(3)
DMAC_DISABLE(3)
DMAC_SET_CALLBACK(3, 0)
DMAC_ENABLE(5)
DMAC_DISABLE(5)
DMAC_SET_CALLBACK(5, 2)
DMAC_ENABLE(4)
DMAC_DISABLE(4)
DMAC_SET_CALLBACK(4, 1)
DMAC_ENABLE(9)
DMAC_STOP(9)
DMAC_SET_CALLBACK(9, 3)
DMAC_ENABLE(10)
DMAC_STOP(10)
DMAC_SET_CALLBACK(10, 4)
