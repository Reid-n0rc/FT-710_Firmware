/*
 * FT-710 DISPLAY (T24 round 4): the SD host interface (SDHI0) target layer, 0x2013FD98..0x201405F3, recreated from
 * the image: the hardware-dependent functions under the SD card driver (the Renesas SD driver's "sd_target" part
 * [inference: the operation table 0x20420564 the driver calls them through, and the command tables]); the card and
 * file-system side is in docs/code/display/filesystem.md. One 512-byte block moves per DMA transfer: channel 0 from
 * the SDHI data port to memory, channel 1 the other way, through a 32-byte aligned bounce buffer when the caller's
 * buffer is not cache-line aligned; the SDHI interrupt only sets event-flag bit 4, which the transfers wait for.
 *
 * Registers (RZ/A1H manual chapter 50, SDHI0 0xE804E000; DMAC chapter 9, 0xE8200000; tools/ghidra/sfr_rza1h.tsv).
 */
#include "display.h"
#include "norti.h"
#include "sd.h"

#define SDHI0 0xE804E000U
#define SD_CMD REG16(SDHI0 + 0x00)
#define SD_ARG0 REG16(SDHI0 + 0x04)
#define SD_ARG1 REG16(SDHI0 + 0x06)
#define SD_STOP REG16(SDHI0 + 0x08)
#define SD_SECCNT REG16(SDHI0 + 0x0A)
#define SD_INFO1 REG16(SDHI0 + 0x1C)
#define SD_INFO2 REG16(SDHI0 + 0x1E)
#define SD_CLK_CTRL REG16(SDHI0 + 0x24)
#define SD_SIZE REG16(SDHI0 + 0x26)
#define SD_OPTION REG16(SDHI0 + 0x28)
#define SOFT_RST REG16(SDHI0 + 0xE0)
#define EXT_SWAP REG16(SDHI0 + 0xF0)
#define DMAC_CH(n, off) REG32(0xE8200000U + 0x40U * (n) + (off))
#define N0SA 0x00
#define N0DA 0x04
#define N0TB 0x08
#define CHSTAT 0x24
#define CHCTRL 0x28
#define CHCFG 0x2C
#define CHITVL 0x30
#define CHEXT 0x34
#define ICDIPR75 REG32(0xE820152CU)
#define ICDISER(n) REG32(0xE8201100U + 4U * (n))
#define CPG_STBCR12 0xFCFE0444U

/* the image's own functions */
void sd_driver_op(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, void *hooks);   /* 0x2013E71C */
int gic_def_inh(int id, const void *def);        /* 0x2011762C */
int knl_int_disable(void);                       /* 0x2015686C */
void knl_int_restore(int psr);                   /* 0x2015688C */
ER os_create_flg_named(const void *pk, const char *name);   /* 0x2014E5E4 */
uint32_t sd_card_detect(void);                   /* 0x20101D94: P11_4 SD_CD */
void sd_power(int on);                           /* 0x20101D70 */
void dcache_invalidate_range(void *p, uint32_t n);
void dcache_clean_range(void *p, uint32_t n);

extern uint8_t sdhi_work;                        /* 0x2091CBA8 */
extern uint32_t *sd_drv_work;                    /* 0x20808B44 */
extern const void *sd_drv_ops;                   /* 0x20808B48 */
extern const void *const sdhi_ops[];             /* 0x20420564 */
extern int sdhi_irq_registered;                  /* 0x20808B70: -1 until gic_def_inh succeeded */
extern ID sdhi_flg;                              /* 0x20808B74 */
extern const uint8_t sdhi_cflg[];                /* 0x204205D8 */
extern const uint8_t sdhi_irq_def[];             /* 0x204205CC */
extern uint8_t sdhi_bounce[512];                 /* 0x2091CEC0 (32-byte aligned) */
extern const uint16_t sdhi_cmd_codes[];          /* 0x204205FC: SD_CMD value per command index */
extern const uint16_t sdhi_acmd_codes[];         /* 0x2042067C: the same for application commands */

int sdhi_card_absent(void);
int sdhi_write_protected(void);
int sdhi_check_card(void);
int sdhi_flag_wait(FLGPTN ptn, int ms);
void sdhi_flag_set(FLGPTN ptn);
void sdhi_dma_read_start(void *dst, uint32_t src);
void sdhi_dma_read_wait(void);
void sdhi_dma_write_start(uint32_t dst, const void *src);
void sdhi_dma_write_wait(void);
int sdhi_send_cmd(int cmd, int app, uint32_t arg);
int sdhi_wait_info(int what);

/* The operation table 0x20420564 (26 slots) [fact]: 0 sdhi_wait_idle, 1 sdhi_clock_set_0x200, 2 sdhi_check_card,
 * 3 sdhi_check_wp, 4..7 constants, 8 sdhi_soft_reset, 9 sdhi_power_on, 10 0x20140470, 11 sdhi_set_bus_width,
 * 12..16 empty / constant, 17 sdhi_wait_info, 18 sdhi_cmd, 19 sdhi_read_response, 20 sd_cmd16_set_blocklen,
 * 21 sd_cmd12_stop, 22 sdhi_read_op, 23 0x20140998, 24 sdhi_write_op, 25 sdhi_open. */

/* 0x2013FD98: the drive's driver-init callback: clear the work byte, hook the operation table, and pass the
 * callback's five arguments on to the driver together with the hook block 0x20808B44 [fact: strb; the stack
 * argument forwarded, str r4 (0x20808B44) as the sixth] */
void sdhi_drv_init(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    sdhi_work = 0;
    sd_drv_work = (uint32_t *)&sdhi_work;
    sd_drv_ops = sdhi_ops;
    sd_driver_op(a, b, c, d, e, &sd_drv_work);
}

/* 0x2013FDE4, 0x2013FFDC: empty functions (no caller found) */
void sdhi_stub_2013fde4(void)
{
}

/* 0x2013FDE8: SDHI0 interrupt (GIC 303): the handler once (gic_def_inh), priority 0x38 in ICDIPR75 byte 3, enabled
 * in ICDISER9 bit 15 with interrupts masked [fact] */
int sdhi0_irq_enable(void)
{
    uint32_t pri = ICDIPR75 & 0x00FFFFFFU;
    int s;

    if (sdhi_irq_registered == -1)
    {
        if (gic_def_inh(0x12F, sdhi_irq_def) < 0)
        {
            return -1;
        }
        sdhi_irq_registered = 1;
    }
    ICDIPR75 = pri | 0x38000000U;
    s = knl_int_disable();
    ICDISER(9) = 0x8000;
    knl_int_restore(s);
    return 0;
}

/* 0x2013FE50: module clock on: STBCR12 bits 2..3 (SDHI00, SDHI01) cleared [fact] */
void sdhi0_clock_on(void)
{
    REG8(CPG_STBCR12) &= 0xF3;
}

void sdhi_stub_2013ffdc(void)
{
}

/* 0x2013FFEC: DMAC channel 0, one 512-byte block from the SDHI to memory (CHCFG 0x126260), software start [fact] */
void sdhi_dma_read_start(void *dst, uint32_t src)
{
    DMAC_CH(0, N0SA) = src;
    DMAC_CH(0, N0DA) = (uint32_t)(uintptr_t)dst;
    DMAC_CH(0, N0TB) = 0x200;
    DMAC_CH(0, CHCFG) = 0x126260;
    DMAC_CH(0, CHITVL) = 0;
    DMAC_CH(0, CHEXT) = 0;
    DMAC_CH(0, CHCTRL) |= 8;          /* SWRST */
    DMAC_CH(0, CHCTRL) |= 1;          /* SETEN */
}

/* 0x20140030: wait until channel 0 is neither enabled nor active (0x900000 polls at most), then reset it [fact] */
void sdhi_dma_read_wait(void)
{
    for (uint32_t i = 0; i < 0x900000 && (DMAC_CH(0, CHSTAT) & 5) != 0; i++)
    {
    }
    DMAC_CH(0, CHCTRL) |= 8;
}

/* 0x20140060: DMAC channel 1, memory to the SDHI (CHCFG 0x262269) [fact] */
void sdhi_dma_write_start(uint32_t dst, const void *src)
{
    DMAC_CH(1, N0SA) = (uint32_t)(uintptr_t)src;
    DMAC_CH(1, N0DA) = dst;
    DMAC_CH(1, N0TB) = 0x200;
    DMAC_CH(1, CHCFG) = 0x262269;
    DMAC_CH(1, CHITVL) = 0;
    DMAC_CH(1, CHEXT) = 0;
    DMAC_CH(1, CHCTRL) |= 8;
    DMAC_CH(1, CHCTRL) |= 1;
}

/* 0x201400A4 */
void sdhi_dma_write_wait(void)
{
    for (uint32_t i = 0; i < 0x900000 && (DMAC_CH(1, CHSTAT) & 5) != 0; i++)
    {
    }
    DMAC_CH(1, CHCTRL) |= 8;
}

/* 0x201400D4: the event flag "SDINT_INI" (once) [fact] */
int sdhi_init(void)
{
    ID id = sdhi_flg;

    if (id == 0)
    {
        id = os_create_flg_named(sdhi_cflg, "SDINT_INI");
        if (id < 1)
        {
            return -1;
        }
    }
    sdhi_flg = id;
    return 0;
}

/* 0x20140148 */
void sdhi_flag_set(FLGPTN ptn)
{
    itron_set_flg(sdhi_flg, ptn);
}

/* 0x20140158: (pattern, ms): wait for any of the bits for ms / 10 ticks, then clear them [fact] */
int sdhi_flag_wait(FLGPTN ptn, int ms)
{
    FLGPTN got;
    ER er = itron_twai_flg(sdhi_flg, ptn, TWF_ANDW, &got, ms / 10);

    itron_clr_flg(sdhi_flg, ~ptn);
    return er;
}

/* 0x201401AC: card absent: any of 32 samples of SD_CD high [fact] */
int sdhi_card_absent(void)
{
    uint32_t v = 0;

    for (uint32_t i = 0; i < 32; i++)
    {
        v = sd_card_detect() | v << 1;
    }
    return v != 0;
}

/* 0x201401DC: write protected: SD_INFO1.WP (bit 7) clear [fact] */
int sdhi_write_protected(void)
{
    return (SD_INFO1 & 0x80) == 0;
}

/* 0x20140210: read one block (DMA, bounce buffer if needed, cache invalidated before and after); -15 on timeout */
int sdhi_read_block(uint8_t *dst)
{
    uint8_t *p = dst;
    int er;

    EXT_SWAP = 0x100;
    if ((uintptr_t)dst & 0x1F)
    {
        p = sdhi_bounce;
    }
    dcache_invalidate_range(p, 0x200);
    sdhi_dma_read_start(p, SDHI0);
    er = sdhi_flag_wait(4, 500);
    sdhi_dma_read_wait();
    dcache_invalidate_range(p, 0x200);
    if (er != 0)
    {
        return -15;
    }
    if ((uintptr_t)dst & 0x1F)
    {
        for (int i = 0; i < 0x200; i++)
        {
            dst[i] = p[i];
        }
    }
    return 0;
}

/* 0x20140298: write one block (through the bounce buffer if needed, cache cleaned first); -16 on timeout */
int sdhi_write_block(const uint8_t *src)
{
    EXT_SWAP = 0x100;
    if ((uintptr_t)src & 0x1F)
    {
        for (int i = 0; i < 0x200; i++)
        {
            sdhi_bounce[i] = src[i];
        }
        src = sdhi_bounce;
    }
    dcache_clean_range((void *)src, 0x200);
    sdhi_dma_write_start(SDHI0, src);
    {
        int er = sdhi_flag_wait(4, 500);

        sdhi_dma_write_wait();
        return er != 0 ? -16 : 0;
    }
}

/* 0x2014030C: the SDHI interrupt's event: bit 4 */
void sdhi_flag_set_4(void)
{
    sdhi_flag_set(4);
}

/* 0x20140320: -6 if no card */
int sdhi_check_card(void)
{
    return sdhi_card_absent() ? -6 : 0;
}

/* 0x20140334: wait until the bus is free (SD_INFO2 CBSY clear, SCLKDIVEN set): -9 on an error bit, the card check's
 * error, -1 after 0x900000 polls; then the clock for mode -1/1 (0x101), 0 (0x140), 2 (0x100), else -8 [fact] */
int sdhi_wait_idle(int mode)
{
    uint32_t i = 0;
    uint16_t clk;

    for (;;)
    {
        uint16_t st = SD_INFO2;

        if ((st & 0x4000) == 0 && (st & 0x2000) != 0)
        {
            break;
        }
        if (st & 0x807F)
        {
            return -9;
        }
        {
            int er = sdhi_check_card();

            if (er != 0)
            {
                return er;
            }
        }
        if (++i > 0x8FFFFF)
        {
            return -1;
        }
    }
    if (i > 0x8FFFFF)
    {
        return -1;
    }
    if (mode == 0)
    {
        clk = 0x140;
    }
    else if (mode == 2)
    {
        clk = 0x100;
    }
    else if (mode == -1 || mode == 1)
    {
        clk = 0x101;
    }
    else
    {
        return -8;
    }
    SD_CLK_CTRL = clk;
    return 0;
}

/* 0x201403D8..0x2014040B: single register stores */
void sdhi_clock_set_0x200(void) { SD_CLK_CTRL = 0x200; }
void sdhi_set_block_size(uint16_t n) { SD_SIZE = n; }
void sdhi_set_sector_count(uint16_t n) { SD_SECCNT = n; }
void sdhi_set_stop(uint16_t v) { SD_STOP = v; }

/* 0x2014040C: -7 if write protected */
int sdhi_check_wp(void)
{
    return sdhi_write_protected() ? -7 : 0;
}

/* 0x20140420..0x2014043F: slots 4..7 of the operation table, constants [fact]. Open: what the driver asks through
 * them; would be settled by the call sites of those slots in sd_driver_op and the sd_* functions */
int sdhi_op4(void) { return -9; }
int sdhi_op5(void) { return -10; }
int sdhi_op6(void) { return 4; }
int sdhi_op7(void) { return 5; }

/* 0x20140440: SOFT_RST off and on */
int sdhi_soft_reset(void)
{
    SOFT_RST = 0;
    SOFT_RST = 1;
    return 0;
}

/* 0x2014045C */
int sdhi_power_on(void)
{
    sd_power(1);
    return 0;
}

/* 0x20140474: SD_OPTION: 4-bit bus for mode 2, else 1-bit (WIDTH) [fact] */
void sdhi_set_bus_width(int mode)
{
    SD_OPTION = mode == 2 ? 0x40EE : 0xC0EE;
}

/* 0x2014048C..0x2014049F: slots 12..16 of the operation table: empty, and -9 [fact] */
void sdhi_op12(void) { }
void sdhi_op13(void) { }
void sdhi_op14(void) { }
void sdhi_op15(void) { }
int sdhi_op16(void) { return -9; }

/* 0x201404A4: (1 response end, 2 access end: SD_INFO1; 3 buffer read ready, 4 buffer write ready: SD_INFO2) wait for
 * the bit and clear it (write ~bit); -1 on a timeout error (SD_INFO2 0x48) or after 0x900000 polls, the card check's
 * error, -2 for another argument [fact] */
int sdhi_wait_info(int what)
{
    volatile uint16_t *reg = &SD_INFO1;
    uint16_t bit;

    if (what == 1)
    {
        bit = 1;
    }
    else if (what == 2)
    {
        bit = 4;
    }
    else
    {
        reg = &SD_INFO2;
        if (what == 3)
        {
            bit = 0x200;
        }
        else if (what == 4)
        {
            bit = 0x100;
        }
        else
        {
            return -2;
        }
    }
    for (uint32_t i = 0; i < 0x900000; i++)
    {
        if ((bit & ~*reg) == 0)
        {
            *reg = (uint16_t)~bit;
            return 0;
        }
        if (SD_INFO2 & 0x48)
        {
            return -1;
        }
        {
            int er = sdhi_check_card();

            if (er != 0)
            {
                return er;
            }
        }
    }
    return -1;
}

/* 0x20140538: (cmd, application command?, argument): clear SD_INFO1 bits 0..2 and SD_INFO2 (but bit 11), the
 * argument, then the command code from the tables (CMD7 select 0x307 / deselect 0x507); -9 while busy [fact] */
int sdhi_send_cmd(int cmd, int app, uint32_t arg)
{
    uint16_t code;

    SD_INFO1 &= 0xFFF8;
    SD_INFO2 &= 0x0800;
    SD_ARG1 = (uint16_t)(arg >> 16);
    SD_ARG0 = (uint16_t)arg;
    if (SD_INFO2 & 0x4000)
    {
        return -9;
    }
    if (app != 0)
    {
        code = sdhi_acmd_codes[cmd];
    }
    else if (cmd == 7)
    {
        code = arg == 0 ? 0x307 : 0x507;
    }
    else
    {
        code = sdhi_cmd_codes[cmd];
    }
    SD_CMD = code;
    return 0;
}

/* 0x201405E4: send, wait for the response; the SD_INFO2 error bits or -1 [fact] */
int sdhi_cmd(int cmd, int app, uint32_t arg)
{
    sdhi_send_cmd(cmd, app, arg);
    if (sdhi_wait_info(1) != 0)
    {
        return -1;
    }
    return SD_INFO2 & 0xFFFF807FU;
}

/* ---- round 7: the command layer above the target functions, 0x201405F4..0x20140BE7, and the DMA open ---- */

#define SD_RSP(n) REG16(SDHI0 + 0x0C + 2 * (n))   /* SD_RSP00..SD_RSP07 */
#define SD_BUF0 REG32(SDHI0 + 0x30)
#define CC_EXT_MODE REG16(SDHI0 + 0xD8)           /* bit 1: DMA mode */
#define DMARS0 REG32(0xFCFE1000U)
#define ICDIPR_REG(id) REG32(0xE8201400U + ((id) & ~3U))

/* the R1 status bits that count as an error, per card type [fact: the literals of the four users] */
extern const uint32_t sd_r1_err_cmd12[];   /* 0x20420234 */
extern const uint32_t sd_r1_err_cmd16[];   /* 0x2042023C */
extern const uint32_t sd_r1_err_read[];    /* 0x20420244 */
extern const uint32_t sd_r1_err_write[];   /* 0x2042024C */

/* the two DMA end interrupts of the SDHI channels [fact: 0x2013FE68 reads +0, +4, +8 and +0xC, +0x10, +0x14] */
typedef struct
{
    const void *def;          /* the handler definition for gic_def_inh */
    uint32_t intid;
    int8_t registered;        /* -1 until gic_def_inh succeeded */
    uint16_t state;           /* +0xA: cleared at open */
} sdhi_dma_irq_t;

extern sdhi_dma_irq_t sdhi_dma_irq[2];   /* 0x20808B78 */

int sdhi_init(void);

/* 0x201405F4: (response type, context): the response registers into the context: the 128-bit R2 (types other
 * than 1, 3, 6, 7) as 15 bytes from RSP07's low byte down to RSP00, else RSP01:RSP00 as one word [fact] */
void sdhi_read_response(int type, sd_card_t *c)
{
    if (type == 1 || type == 6 || type == 7 || type == 3)
    {
        uint32_t hi;

        c->rsp.r1 = 0;
        hi = SD_RSP(1);
        c->rsp.r1 = hi << 16;
        c->rsp.r1 |= SD_RSP(0);
        return;
    }
    c->rsp.r2[0] = (uint8_t)SD_RSP(7);
    for (int k = 6; k >= 0; k--)
    {
        uint16_t v = SD_RSP(k);

        c->rsp.r2[13 - 2 * k] = (uint8_t)(v >> 8);
        c->rsp.r2[14 - 2 * k] = (uint8_t)v;
    }
}

/* 0x201406B4: (block length, blocks, context): SD_SIZE, SD_SECCNT, SD_STOP (0x100: auto CMD12 for more than one
 * block), then CMD16 with three tries; -9 when it fails, -23 for an error bit in R1 [fact] */
int sd_cmd16_set_blocklen(uint32_t len, uint32_t blocks, sd_card_t *c)
{
    int i;

    sdhi_set_block_size(len);
    sdhi_set_sector_count(blocks);
    sdhi_set_stop(blocks == 1 ? 0 : 0x100);
    for (i = 0; i < 3; i++)
    {
        if (sdhi_cmd(16, 0, len) == 0)
        {
            break;
        }
    }
    if (i >= 3)
    {
        return -9;
    }
    sdhi_read_response(1, c);
    return (c->rsp.r1 & sd_r1_err_cmd16[c->card_type]) != 0 ? -23 : 0;
}

/* 0x2014074C: CMD12 (stop) with three tries; -9 when it fails or R1 has an error bit [fact] */
int sd_cmd12_stop(sd_card_t *c)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (sdhi_cmd(12, 0, 0) == 0)
        {
            break;
        }
    }
    if (i >= 3)
    {
        return -9;
    }
    sdhi_read_response(1, c);
    return (c->rsp.r1 & sd_r1_err_cmd12[c->card_type]) != 0 ? -9 : 0;
}

/* 0x201407BC: after an error: SOFT_RST with SD_CLK_CTRL and SD_OPTION kept. The image keeps them in r3 and ip across
 * sdhi_soft_reset (armcc knows the callee), which the recreated sdhi_soft_reset may change (abicheck) [fact] */
void sdhi_error_reset(void)
{
    uint16_t clk = SD_CLK_CTRL;
    uint16_t opt = SD_OPTION;

    sdhi_soft_reset();
    SD_CLK_CTRL = clk;
    SD_OPTION = opt;
}

/* 0x201407E0 / 0x201409EC: (card address, buffer, blocks, context): block length 512; DMA mode on; CMD17/18 (read)
 * or CMD24/25 (write) with three tries (-9; DMA mode stays on); R1 error bits (-22 read, -21 write); each block by
 * DMA (its error ends the loop, DMA mode off); DMA mode off; then the access end (-1 when it fails) [fact] */
#define SDHI_XFER_SECTORS(name, single, multi, mask, err, block)                                                   \
    int name(uint32_t addr, uint8_t *buf, uint32_t n, sd_card_t *c)                                                \
    {                                                                                                              \
        int r = sd_cmd16_set_blocklen(0x200, n, c);                                                                \
        int i;                                                                                                     \
                                                                                                                   \
        if (r != 0)                                                                                                \
        {                                                                                                          \
            return r;                                                                                              \
        }                                                                                                          \
        CC_EXT_MODE |= 2;                                                                                          \
        for (i = 0; i < 3; i++)                                                                                    \
        {                                                                                                          \
            if (sdhi_cmd(n == 1 ? (single) : (multi), 0, addr) == 0)                                               \
            {                                                                                                      \
                break;                                                                                             \
            }                                                                                                      \
        }                                                                                                          \
        if (i >= 3)                                                                                                \
        {                                                                                                          \
            return -9;                                                                                             \
        }                                                                                                          \
        sdhi_read_response(1, c);                                                                                  \
        if (c->rsp.r1 & (mask)[c->card_type])                                                                      \
        {                                                                                                          \
            return (err);                                                                                          \
        }                                                                                                          \
        for (uint16_t k = 0; k < n; k++, buf += 0x200)                                                             \
        {                                                                                                          \
            r = block(buf);                                                                                        \
            if (r != 0)                                                                                            \
            {                                                                                                      \
                CC_EXT_MODE &= ~2;                                                                                 \
                return r;                                                                                          \
            }                                                                                                      \
        }                                                                                                          \
        CC_EXT_MODE &= ~2;                                                                                         \
        return sdhi_wait_info(2) != 0 ? -1 : 0;                                                                    \
    }

SDHI_XFER_SECTORS(sdhi_read_sectors_cmd, 17, 18, sd_r1_err_read, -22, sdhi_read_block)
SDHI_XFER_SECTORS(sdhi_write_sectors_cmd, 24, 25, sd_r1_err_write, -21, sdhi_write_block)

/* 0x2014091C: slot 22 of the operation table, read: two blocks one command each (the second at addr + 1 or + 0x200
 * by the addressing), otherwise one command for all; sdhi_error_reset after an error [fact] */
int sdhi_read_op(uint32_t addr, uint8_t *buf, uint32_t n, sd_card_t *c)
{
    int r;

    if (n != 2)
    {
        r = sdhi_read_sectors_cmd(addr, buf, n, c);
    }
    else
    {
        r = sdhi_read_sectors_cmd(addr, buf, 1, c);
        if (r == 0)
        {
            r = sdhi_read_sectors_cmd(c->flags == 2 ? addr + 1 : addr + 0x200, buf + 0x200, 1, c);
        }
    }
    if (r != 0)
    {
        sdhi_error_reset();
    }
    return r;
}

/* 0x20140998: slot 23: read len / 4 words from SD_BUF0 into the buffer, low byte first; returns 0 [fact] */
int sdhi_read_buf_pio(uint8_t *buf, uint32_t len)
{
    for (int i = 0; i < (int)(len >> 2); i++)
    {
        uint32_t w = SD_BUF0;

        buf[0] = (uint8_t)w;
        buf[1] = (uint8_t)(w >> 8);
        buf[2] = (uint8_t)(w >> 16);
        buf[3] = (uint8_t)(w >> 24);
        buf += 4;
    }
    return 0;
}

/* 0x20140B50: slot 24, write: one command for all blocks, sdhi_error_reset after an error [fact] */
int sdhi_write_op(uint32_t addr, uint8_t *buf, uint32_t n, sd_card_t *c)
{
    int r = sdhi_write_sectors_cmd(addr, buf, n, c);

    if (r != 0)
    {
        sdhi_error_reset();
    }
    return r;
}

/* 0x2013FE68 (Ghidra: part of sdhi_open, its tail call): the DMA side: both interrupt states cleared, the DMARS0
 * request selects 0xC2 (channel 0) and 0xC1 (channel 1), each end interrupt's handler once (gic_def_inh) and its
 * priority 0x38 (the register read before the handler is set, as the image does), both channels reset (CHCTRL
 * SWRST), both interrupts enabled with interrupts masked; -1 when a handler fails [fact] */
int sdhi_dma_open(void)
{
    int s;

    sdhi_dma_irq[0].state = 0;
    sdhi_dma_irq[1].state = 0;
    DMARS0 &= ~0xFFU;
    DMARS0 |= 0xC2;
    DMARS0 &= ~0xFF0000U;
    DMARS0 |= 0xC10000;
    for (int k = 0; k < 2; k++)
    {
        uint32_t id = sdhi_dma_irq[k].intid;
        uint32_t pri = ICDIPR_REG(id) & ~(0xFFU << 8 * (id & 3));

        if (sdhi_dma_irq[k].registered == -1)
        {
            if (gic_def_inh(id, sdhi_dma_irq[k].def) < 0)
            {
                return -1;
            }
            sdhi_dma_irq[k].registered = 1;
        }
        id = sdhi_dma_irq[k].intid;
        ICDIPR_REG(id) = pri | 7U << (8 * (id & 3) + 3);
    }
    DMAC_CH(0, CHCTRL) |= 8;
    DMAC_CH(1, CHCTRL) |= 8;
    s = knl_int_disable();
    ICDISER(sdhi_dma_irq[0].intid >> 5) = 1U << (sdhi_dma_irq[0].intid & 0x1F);
    ICDISER(sdhi_dma_irq[1].intid >> 5) = 1U << (sdhi_dma_irq[1].intid & 0x1F);
    knl_int_restore(s);
    return 0;
}

/* 0x20140B68: slot 25, open: module clock, soft reset, the SDHI interrupt, the target init, the DMA side; the
 * first error is returned [fact] */
int sdhi_open(void)
{
    int r;

    sdhi0_clock_on();
    sdhi_soft_reset();
    r = sdhi0_irq_enable();
    if (r != 0)
    {
        return r;
    }
    r = sdhi_init();
    if (r != 0)
    {
        return r;
    }
    return sdhi_dma_open();
}

/* 0x20140B9C: the SDHI0 buffer interrupt: SD_INFO2 BRE (bit 8) -> event bit 1, else BWE (bit 9) -> bit 2, each
 * cleared by writing its complement [fact] */
void sdhi0_buf_isr(void)
{
    uint16_t v = SD_INFO2;

    if (v & 0x100)
    {
        SD_INFO2 = (uint16_t)~0x100U;
        sdhi_flag_set(1);
    }
    else if (v & 0x200)
    {
        SD_INFO2 = (uint16_t)~0x200U;
        sdhi_flag_set(2);
    }
}
