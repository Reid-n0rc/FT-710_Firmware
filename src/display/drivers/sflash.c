/*
 * FT-710 DISPLAY (T24 round 4): the serial-flash driver on SPIBSC0 (W25Q128JV, docs/hardware.md), 0x20103BDC..
 * 0x20105073, recreated from the image. Used by the self-update code (docs/code/display/update.md).
 *
 * Three layers [fact: the call structure]:
 *  - SPIBSC register access and SPI-mode transfers (spibsc_*): the controller normally maps the flash at 0x18000000
 *    (external address space read mode); for commands it is switched to SPI operating mode, the transfer runs
 *    through SMENR/SMWDR/SMRDR in 1-, 2- or 4-byte units (8 with two flash chips in parallel, "dual"), and the
 *    previous DRCR/CMNCR are restored afterwards with a read-cache flush.
 *  - flash commands (sflash_*): RDSR polling, WREN, 64 KB block erase (0xD8), page program (0x02) with a buffer for
 *    partial pages, FAST_READ (0x0B), global unlock (0x98).
 *  - a small character-device protocol on the object 0x20810D90 (sflash_dev_write / sflash_dev_read): a 6-byte
 *    command 'r' / 'e' / 'p' + 1 byte + a 32-bit address, 'd' + digit (dual mode), 'b' (unlock), then data or one
 *    status byte. The update code talks to the flash through it (spiflash_write, spiflash_erase).
 *
 * Registers (RZ/A1H manual chapter 17, SPIBSC0 at 0x3FEFA000): CMNCR +0x00, DRCR +0x0C, DRCMR +0x10, DRENR +0x1C,
 * SMCR +0x20, SMCMR +0x24, SMADR +0x28, SMOPR +0x2C, SMENR +0x30, SMRDR0 +0x38, SMRDR1 +0x3C, SMWDR0 +0x40,
 * SMWDR1 +0x44, CMNSR +0x48.
 */
#include "display.h"
#include "norti.h"

#define CMNCR 0x00
#define DRCR 0x0C
#define SMCR 0x20
#define SMCMR 0x24
#define SMADR 0x28
#define SMOPR 0x2C
#define SMENR 0x30
#define SMRDR0 0x38
#define SMRDR1 0x3C
#define SMWDR0 0x40
#define SMWDR1 0x44
#define CMNSR 0x48
#define SPIBSC0_BASE 0x3FEFA000U
#define XIP_BASE 0x18000000U

/* the flash device object (0x20810D90) [fact: the offsets each function uses] */
typedef struct
{
    volatile uint8_t *base;  /* +0x00 SPIBSC register block (sflash_dev_open) */
    uint32_t dual;           /* +0x04 two chips in parallel: every command byte doubled, data in pairs ('d' command) */
    uint16_t mode;           /* +0x08 device state: 0 idle, 1 read pending, 2 erase status, 3 programming */
    uint16_t _r0a;
    uint32_t addr;           /* +0x0C flash address of the next read / program / erase */
    uint32_t error;          /* +0x10 set when a page program fails; refuses further commands */
    uint32_t no_merge;       /* +0x14 one-shot: do not merge the two chips' status bytes */
    uint32_t merge_and;      /* +0x18 merge the status pair with AND (command 0x70) instead of OR */
    uint32_t _r1c;
    uint32_t saved_cmncr;    /* +0x20 */
    uint32_t saved_drcr;     /* +0x24 */
    uint8_t last_cmd;        /* +0x28 first byte of the last command sent */
} sflash_dev_t;

extern sflash_dev_t sflash_dev;                  /* 0x20810D90 */
extern uint8_t sflash_page_buf[512];             /* 0x20810DBC: partial page waiting for more data */
extern int sflash_page_fill;                     /* 0x208000A0: bytes in sflash_page_buf */
extern uint32_t sflash_erase_stamp[2];           /* 0x208000A8: cycle stamp around each block erase */
/* SMENR.SPIDE per transfer size (index = bytes): single chip {-, 8, 16, -, 32 bit}, dual {.., 2: 8, 4: 16, 8: 32}
 * [fact: 0x2016525C, 0x20165269] */
extern const uint8_t spibsc_spide_single[];      /* 0x2016525C */
extern const uint8_t spibsc_spide_dual[];        /* 0x20165269 */
/* SST26 block map: {index, size} pairs, 8 bytes each, entry 0 = {136 blocks, 8 MiB} [fact: 0x201651FC] */
typedef struct
{
    int16_t index;
    uint16_t _pad;
    uint32_t size;
} sst_block_t;
extern const sst_block_t sflash_sst_blocks[11];  /* 0x201651FC */

int progress_scale(int bar, double fraction);    /* 0x201140F4 */
void progress_set(int percent);                  /* 0x201140D0 */

uint32_t spibsc_reg_read32(sflash_dev_t *d, int off);
void spibsc_reg_write32(sflash_dev_t *d, uint32_t v, int off);
void spibsc_reg_write16(sflash_dev_t *d, uint16_t v, int off);
void spibsc_reg_write8(sflash_dev_t *d, uint8_t v, int off);
int sflash_dev_write(const uint8_t *cmd, uint32_t n);
int sflash_dev_read(uint8_t *buf, uint32_t n);
int sflash_dev_open(void);
int sflash_page_program(sflash_dev_t *d, const uint8_t *p, int n);
uint32_t sflash_cycle_stamp(uint32_t *s);

/* 0x20103BDC: size of block i of the SST26 map: 8 KiB at both ends, 32 KiB next to them, else 64 KiB [fact] */
uint32_t sflash_sst_block_size(int i)
{
    for (int k = 1; k < 11; k++)
    {
        if (sflash_sst_blocks[k].index == i)
        {
            return sflash_sst_blocks[k].size;
        }
    }
    return 0x10000;
}

/* a device command and its one status byte (1 if the command was refused) */
static inline uint32_t dev_command(uint8_t c0, uint8_t c1, uint32_t addr)
{
    uint8_t cmd[6];
    uint32_t st = 0xFF;

    cmd[0] = c0;
    cmd[1] = c1;
    cmd[2] = (uint8_t)addr;
    cmd[3] = (uint8_t)(addr >> 8);
    cmd[4] = (uint8_t)(addr >> 16);
    cmd[5] = (uint8_t)(addr >> 24);
    if (sflash_dev_write(cmd, 6) < 0)
    {
        return 1;
    }
    sflash_dev_read((uint8_t *)&st, 1);
    return st & 0xFF;
}

/* 0x20103C14: device command "bp" (global unlock) [fact] */
uint32_t sflash_cmd_bp(void)
{
    return dev_command('b', 'p', 0);
}

/* 0x20103C70: device command "er" (erase the block at addr) [fact] */
uint32_t sflash_cmd_erase(uint32_t addr)
{
    return dev_command('e', 'r', addr);
}

/* 0x20103CC8: sum of (byte + 1) & 0xFF over n bytes: the check spiflash_write compares after programming [fact] */
int sflash_checksum(const uint8_t *p, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (uint8_t)(p[i] + 1);
    }
    return sum;
}

/* 0x20103CFC: erase the whole SST26-type flash block by block (136 blocks, 8 MiB), with a progress bar and a
 * yield every 8 blocks [fact]; -1 on a refused command */
int sflash_erase_chip_sst(int bar)
{
    uint32_t addr = 0;
    int nblk = 0x88;

    if (bar)
    {
        progress_set(progress_scale(bar, 0.0));
    }
    sflash_dev_open();
    if ((int)sflash_cmd_bp() < 0)
    {
        return -1;
    }
    for (int i = 0; i < nblk; i++)
    {
        if ((int)sflash_cmd_erase(addr) < 0)
        {
            return -1;
        }
        addr += sflash_sst_block_size(i);
        if (bar)
        {
            progress_set(progress_scale(bar, (double)i / (double)nblk));
            if ((i & 7) == 0)
            {
                itron_rot_rdq(0);
            }
        }
    }
    return 0;
}

/* 0x20103DD0: (flash offset, data, n): device command "pr", the data, the status byte; then the checksum of the
 * XIP window at 0x18000000 + offset against the data's: 0x16 if they differ [fact] */
uint32_t spiflash_write(uint32_t off, const uint8_t *data, uint32_t n)
{
    int sum = sflash_checksum(data, n);
    uint8_t cmd[6];
    uint32_t st = 0xFF;

    cmd[0] = 'p';
    cmd[1] = 'r';
    cmd[2] = (uint8_t)off;
    cmd[3] = (uint8_t)(off >> 8);
    cmd[4] = (uint8_t)(off >> 16);
    cmd[5] = (uint8_t)(off >> 24);
    if (sflash_dev_write(cmd, 6) < 0 || sflash_dev_write(data, n) < 0)
    {
        return 1;
    }
    sflash_dev_read((uint8_t *)&st, 1);
    if (sflash_checksum((const uint8_t *)(XIP_BASE + off), n) != sum)
    {
        return 0x16;
    }
    return st & 0xFF;
}

/* 0x20103E74: (bar, offset, size): erase the 64 KiB blocks covering the range, progress and a yield every 16 */
int spiflash_erase(int bar, uint32_t off, uint32_t size)
{
    uint32_t nblk = (size + 0xFFFF) >> 16;

    if (bar)
    {
        progress_set(progress_scale(bar, 0.0));
    }
    sflash_dev_open();
    if ((int)sflash_cmd_bp() < 0)
    {
        return -1;
    }
    for (uint32_t i = 0; i < nblk; i++)
    {
        if ((int)sflash_cmd_erase(off) < 0)
        {
            return -1;
        }
        off += 0x10000;
        if (bar)
        {
            progress_set(progress_scale(bar, (double)(int)i / (double)nblk));
            if ((i & 0xF) == 0)
            {
                itron_rot_rdq(0);
            }
        }
    }
    return 0;
}

/* 0x20103F44: erase 256 blocks of 64 KiB (16 MiB), progress, a yield every 16 [fact] */
int sflash_erase_chip_uniform(int bar)
{
    uint32_t addr = 0;
    int nblk = 0x100;

    if (bar)
    {
        progress_set(progress_scale(bar, 0.0));
    }
    sflash_dev_open();
    if ((int)sflash_cmd_bp() < 0)
    {
        return -1;
    }
    for (int i = 0; i < nblk; i++)
    {
        if ((int)sflash_cmd_erase(addr) < 0)
        {
            return -1;
        }
        addr += 0x10000;
        if (bar)
        {
            progress_set(progress_scale(bar, (double)i / (double)nblk));
            if ((i & 0xF) == 0)
            {
                itron_rot_rdq(0);
            }
        }
    }
    return 0;
}

/* 0x20104000: manufacturer id: external reads switched to READ JEDEC ID (0x9F), one byte read at 0x18000000,
 * DRCMR/DRENR restored [fact] */
uint8_t sflash_read_mfr_id(void)
{
    volatile uint32_t *drcmr = &REG32(SPIBSC0_BASE + 0x10), *drenr = &REG32(SPIBSC0_BASE + 0x1C);
    volatile uint32_t cmr, enr;
    volatile uint8_t id;

    cmr = *drcmr;
    enr = *drenr;
    *drcmr = 0x9F0000;
    *drenr = 0x4000;
    id = REG8(XIP_BASE);
    *drcmr = cmr;
    *drenr = enr;
    return id;
}

/* 0x20104050: whole-chip erase: SST (JEDEC manufacturer 0xBF [inference]) by its block map, else uniform [fact] */
int sflash_erase_chip(int bar)
{
    if (sflash_read_mfr_id() != 0xBF)
    {
        return sflash_erase_chip_uniform(bar);
    }
    return sflash_erase_chip_sst(bar);
}

/* 0x20104078: (offset, n, buf): device command "rd" and the data; no caller in the image [fact] */
int spiflash_read(uint32_t off, uint32_t n, uint8_t *buf)
{
    uint8_t cmd[6];

    sflash_dev_open();
    cmd[0] = 'r';
    cmd[1] = 'd';
    cmd[2] = (uint8_t)off;
    cmd[3] = (uint8_t)(off >> 8);
    cmd[4] = (uint8_t)(off >> 16);
    cmd[5] = (uint8_t)(off >> 24);
    if (sflash_dev_write(cmd, 6) < 0)
    {
        return 1;
    }
    return sflash_dev_read(buf, n);
}

/* 0x20104104..0x2010414B: register access through the object */
uint32_t spibsc_reg_read32(sflash_dev_t *d, int off)
{
    return *(volatile uint32_t *)(d->base + off);
}

void spibsc_reg_write32(sflash_dev_t *d, uint32_t v, int off)
{
    *(volatile uint32_t *)(d->base + off) = v;
}

void spibsc_reg_write16(sflash_dev_t *d, uint16_t v, int off)
{
    *(volatile uint16_t *)(d->base + off) = v;
}

void spibsc_reg_write8(sflash_dev_t *d, uint8_t v, int off)
{
    *(volatile uint8_t *)(d->base + off) = v;
}

/* 0x2010414C: PMCCNTR [fact: mrc p15, 0, r0, c9, c13, 0] */
uint32_t pmu_ccnt_read(void)
{
    uint32_t v;

    __asm__ volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(v));
    return v;
}

/* 0x20104154: {delta, last} cycle stamp, the same as scif's pmu_cycle_stamp (a second copy) [fact] */
__attribute__((noinline)) uint32_t sflash_cycle_stamp(uint32_t *s)
{
    uint32_t now;

    __asm__ volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(now));
    s[0] = now - s[1];
    s[1] = now;
    return s[0];
}

/* 0x20104188: SSL negated (CMNSR.SSLF clear) [fact] */
int spibsc_ssl_negated(sflash_dev_t *d)
{
    return ~(spibsc_reg_read32(d, CMNSR) >> 1) & 1;
}

/* 0x201041A0: wait for CMNSR.TEND, 100000 polls; -1 on timeout [fact] */
int spibsc_wait_tend(sflash_dev_t *d)
{
    for (int i = 100000; i != 0; i--)
    {
        if (spibsc_reg_read32(d, CMNSR) & 1)
        {
            return 0;
        }
    }
    return -1;
}

/* 0x201041F4: idle check before leaving SPI mode: CMNSR must read 1 (TEND, SSL negated); else wait, and if still
 * not idle try to restart the controller and wait once more [fact] */
int spibsc_ensure_idle(sflash_dev_t *d)
{
    if (spibsc_reg_read32(d, CMNSR) == 1)
    {
        return 0;
    }
    if (spibsc_wait_tend(d) != 0)
    {
        return -1;
    }
    if (spibsc_reg_read32(d, CMNSR) != 1)
    {
        /* meant as SMCR = 1, then 0; the image passes value and offset the other way round, so it writes 0x20 to
         * CMNCR + 1 (an unaligned word store) and to CMNCR [fact: 0x20104230..0x2010424C] */
        spibsc_reg_write32(d, SMCR, 1);
        spibsc_reg_write32(d, SMCR, 0);
        spibsc_wait_tend(d);
        if (spibsc_reg_read32(d, CMNSR) != 1)
        {
            return -1;
        }
    }
    return 0;
}

/* start one SPI-mode transfer unit: no command, address or option phase, SPIDE as given, SMCR = dir (3: SPIE +
 * SPIWE, transmit; 7: SPIE + SPIWE + SPIRE, full duplex), SSLKP while more data follows or the caller keeps the
 * select asserted */
static inline int spibsc_start(sflash_dev_t *d, uint32_t spide, int keep, uint32_t dir)
{
    spibsc_reg_write32(d, 0, SMCMR);
    spibsc_reg_write32(d, 0, SMADR);
    spibsc_reg_write32(d, 0, SMOPR);
    spibsc_reg_write32(d, spide, SMENR);
    spibsc_reg_write32(d, keep ? 0x100 | dir : dir, SMCR);
    return spibsc_wait_tend(d);
}

/* 0x2010427C: (buf, n, keep): send n bytes in units of 4/2/1 (single) or 8/4/2 (dual; an odd count is an error,
 * -1), little-endian into SMWDR0 (and SMWDR1 for the first 4 of 8) [fact] */
int spibsc_xfer(sflash_dev_t *d, const uint8_t *p, uint32_t n, int keep)
{
    uint32_t spide = 0, w1 = 0, v;
    int more = 1;
    int ret = spibsc_wait_tend(d);

    while (ret >= 0)
    {
        uint32_t unit;

        if (n == 0)
        {
            return 0;
        }
        if (d->dual)
        {
            unit = n >= 8 ? 8 : n;
            if (unit & 1)
            {
                return -1;
            }
            if (unit == 6)
            {
                unit = 4;
            }
            spide = spibsc_spide_dual[unit] | (spide & ~0xFU);
            if (unit == 8)
            {
                w1 = p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24;
                p += 4;
            }
            v = p[0] | p[1] << 8;
            p += 2;
            if (unit >= 4)
            {
                v |= p[0] << 16 | (uint32_t)p[1] << 24;
                p += 2;
            }
        }
        else
        {
            unit = n >= 4 ? 4 : n == 3 ? 2 : n;
            spide = spibsc_spide_single[unit] | (spide & ~0xFU);
            v = *p++;
            if (unit >= 2)
            {
                v |= *p++ << 8;
                if (unit >= 3)
                {
                    v |= *p++ << 16;
                }
            }
            if (unit >= 4)
            {
                v |= (uint32_t)*p++ << 24;
            }
        }
        if (unit == 2)
        {
            spibsc_reg_write16(d, (uint16_t)v, SMWDR0);
        }
        else if (unit == 1)
        {
            spibsc_reg_write8(d, (uint8_t)v, SMWDR0);
        }
        else
        {
            spibsc_reg_write32(d, v, SMWDR0);
            if (unit == 8)
            {
                spibsc_reg_write32(d, w1, SMWDR1);
            }
        }
        n -= unit;
        if (n == 0)
        {
            more = 0;
        }
        ret = spibsc_start(d, spide, more || keep, 3);
    }
    return ret;
}

/* 0x2010448C: (buf, n, keep): receive n bytes from SMRDR0/1 in the same units. With two chips the status
 * registers (after RDSR 0x05 or RDID 0x9F) come as byte pairs, which are merged into one byte each: by OR, or by AND
 * after command 0x70 [fact] */
int sflash_cmd_read(sflash_dev_t *d, uint8_t *p, uint32_t n, int keep)
{
    int more = 1, merge = 0;
    int ret = spibsc_wait_tend(d);

    if (ret < 0)
    {
        return ret;
    }
    if (d->dual && d->no_merge == 0 && (d->last_cmd == 0x05 || d->last_cmd == 0x9F))
    {
        merge = 1;
        n <<= 1;
    }
    d->merge_and = d->last_cmd == 0x70 ? 1 : 0;
    d->no_merge = 0;
    while (n != 0)
    {
        uint32_t unit;
        const uint8_t *tab;
        uint32_t r0, r1;
        uint8_t b0, b1, b2, b3, c0, c1, c2, c3;

        if (d->dual)
        {
            unit = n >= 8 ? 8 : n;
            if (unit & 1)
            {
                return -1;
            }
            tab = spibsc_spide_dual;
            if (unit == 6)
            {
                unit = 4;
            }
        }
        else
        {
            unit = n >= 4 ? 4 : n == 3 ? 2 : n;
            tab = spibsc_spide_single;
        }
        n -= unit;
        if (n == 0)
        {
            more = 0;
        }
        ret = spibsc_start(d, tab[unit], more || keep, 7);
        if (ret < 0)
        {
            return ret;
        }
        r0 = spibsc_reg_read32(d, SMRDR0);
        r1 = spibsc_reg_read32(d, SMRDR1);
        b0 = (uint8_t)r0, b1 = (uint8_t)(r0 >> 8), b2 = (uint8_t)(r0 >> 16), b3 = (uint8_t)(r0 >> 24);
        c0 = (uint8_t)r1, c1 = (uint8_t)(r1 >> 8), c2 = (uint8_t)(r1 >> 16), c3 = (uint8_t)(r1 >> 24);
        if (merge)
        {
            int and_ = d->merge_and != 0;

            if (unit == 8)
            {
                p[0] = and_ ? (c1 & c0) : (c1 | c0);
                p[1] = and_ ? (c2 & c3) : (c2 | c3);
                p[2] = and_ ? (b0 & b1) : (b0 | b1);
                p[3] = and_ ? (b2 & b3) : (b2 | b3);
                p += 4;
            }
            else if (unit == 2)
            {
                *p++ = and_ ? (b1 & b0) : (b1 | b0);
            }
            else if (unit == 4)
            {
                p[0] = and_ ? (b1 & b0) : (b1 | b0);
                p[1] = and_ ? (b2 & b3) : (b2 | b3);
                p += 2;
            }
        }
        else
        {
            if (unit == 8)
            {
                p[0] = c0;
                p[1] = c1;
                p[2] = c2;
                p[3] = c3;
                p += 4;
            }
            *p++ = b0;
            if (unit >= 2)
            {
                *p++ = b1;
            }
            if (unit >= 4)
            {
                *p++ = b2;
                *p++ = b3;
            }
        }
    }
    return 0;
}

/* 0x2010474C: send a command (and address): remembers its first byte; doubles every byte for two chips [fact] */
void sflash_cmd_write(sflash_dev_t *d, const uint8_t *p, uint32_t n, int keep)
{
    uint8_t twice[16];

    d->last_cmd = p[0];
    if (d->dual)
    {
        for (uint32_t i = 0; i < n; i++)
        {
            twice[2 * i] = p[i];
            twice[2 * i + 1] = p[i];
        }
        n <<= 1;
        p = twice;
    }
    spibsc_xfer(d, p, n, keep);
}

static inline void delay4(void)
{
    __asm__ volatile("nop\n\tnop\n\tnop\n\tnop");
}

/* 0x201047B4: RDSR (0x05) until BUSY and bit 7 are clear, 1000000 polls; -1 on timeout [fact] */
int sflash_wait_ready(sflash_dev_t *d)
{
    uint8_t cmd[4];
    uint32_t sr = 0;
    int i = 1000000;

    cmd[0] = 0x05;
    sflash_cmd_write(d, cmd, 1, 1);
    do
    {
        sflash_cmd_read(d, (uint8_t *)&sr, 1, 1);
        if ((sr & 0x81) == 0)
        {
            break;
        }
        delay4();
    } while (--i != 0);
    sflash_cmd_read(d, (uint8_t *)&sr, 1, 0);
    return i == 0 ? -1 : 0;
}

/* 0x20104848: RDSR until WEL (bit 1) is set and the device is not busy [fact] */
int sflash_wait_wel(sflash_dev_t *d)
{
    uint8_t cmd[4];
    uint32_t sr = 0;
    int i = 1000000;

    cmd[0] = 0x05;
    sflash_cmd_write(d, cmd, 1, 1);
    do
    {
        sflash_cmd_read(d, (uint8_t *)&sr, 1, 1);
        if ((sr & 2) != 0 && (sr & 0x81) == 0)
        {
            break;
        }
        delay4();
    } while (--i != 0);
    sflash_cmd_read(d, (uint8_t *)&sr, 1, 0);
    return i == 0 ? -1 : 0;
}

/* 0x201048E4: Read Status Register-2 (0x35) [fact for the command; register name: W25Q128 datasheet] */
uint32_t sflash_read_sr2(sflash_dev_t *d)
{
    uint8_t cmd[4];
    uint32_t sr = 0;

    cmd[0] = 0x35;
    sflash_cmd_write(d, cmd, 1, 1);
    sflash_cmd_read(d, (uint8_t *)&sr, 1, 1);
    sflash_cmd_read(d, (uint8_t *)&sr, 1, 0);
    return sr & 0xFF;
}

/* 0x20104944: CMNCR for SPI mode: 0x81FFF320, BSZ = 1 for two chips [fact] */
int spibsc_cmncr_set(sflash_dev_t *d)
{
    spibsc_reg_write32(d, d->dual ? 0x81FFF321U : 0x81FFF320U, CMNCR);
    return 0;
}

/* 0x20104968: leave external-read mode: save DRCR, set SSLN in DRCR, SMCR = 0, wait for TEND and SSL negated, save
 * CMNCR and set MD (SPI mode) [fact] */
int spibsc_enter_spi_mode(sflash_dev_t *d)
{
    d->saved_drcr = spibsc_reg_read32(d, DRCR);
    spibsc_reg_write32(d, 0x1000000, DRCR);
    spibsc_reg_write32(d, 0, SMCR);
    spibsc_wait_tend(d);
    if (spibsc_ssl_negated(d) == 0)
    {
        return -1;
    }
    d->saved_cmncr = spibsc_reg_read32(d, CMNCR);
    spibsc_reg_write32(d, spibsc_reg_read32(d, CMNCR) | 0x80000000U, CMNCR);
    spibsc_cmncr_set(d);
    return 0;
}

/* 0x20104A08: back to external-read mode: restore DRCR and CMNCR, flush the read cache (DRCR.RCF) [fact] */
int spibsc_exit_spi_mode(sflash_dev_t *d)
{
    spibsc_ensure_idle(d);
    spibsc_reg_write32(d, d->saved_drcr, DRCR);
    spibsc_reg_write32(d, d->saved_cmncr, CMNCR);
    spibsc_reg_write32(d, spibsc_reg_read32(d, DRCR) | 0x200, DRCR);
    spibsc_reg_read32(d, DRCR);
    return 0;
}

/* the 4-byte command {op, address bits 23..16, 15..8, 7..0} */
static inline void cmd_addr(uint8_t *c, uint8_t op, uint32_t a)
{
    c[0] = op;
    c[1] = (uint8_t)(a >> 16);
    c[2] = (uint8_t)(a >> 8);
    c[3] = (uint8_t)a;
}

/* 0x20104A64: FAST_READ (0x0B, one dummy byte) of n bytes at the object's address, which then advances (by n / 2
 * for two chips); SR2 is read first [fact] */
int sflash_fast_read(sflash_dev_t *d, uint8_t *buf, int n)
{
    uint8_t cmd[8];

    cmd_addr(cmd, 0x0B, d->addr);
    cmd[4] = 0xFF;
    cmd[5] = 0;
    cmd[6] = 0;
    cmd[7] = 8;
    if (spibsc_enter_spi_mode(d) != 0)
    {
        return -1;
    }
    sflash_read_sr2(d);
    sflash_cmd_write(d, cmd, 5, 1);
    sflash_cmd_read(d, buf, n, 0);
    if (d->dual)
    {
        n /= 2;
    }
    d->addr += n;
    spibsc_exit_spi_mode(&sflash_dev);
    return 0;
}

/* 0x20104B20: WREN, wait for WEL, 64 KB block erase (0xD8) at the object's address, wait ready; the erase time in
 * cycles is stamped around it [fact] */
int sflash_erase_block(sflash_dev_t *d)
{
    uint8_t wren[4], cmd[4];
    int ret;

    wren[0] = 0x06;
    cmd_addr(cmd, 0xD8, d->addr);
    ret = spibsc_enter_spi_mode(d);
    if (ret != 0)
    {
        return ret;
    }
    sflash_cmd_write(d, wren, 1, 0);
    ret = sflash_wait_wel(d);
    if (ret == 0)
    {
        sflash_cycle_stamp(sflash_erase_stamp);
        sflash_cmd_write(d, cmd, 4, 0);
        ret = sflash_wait_ready(d);
        sflash_cycle_stamp(sflash_erase_stamp);
        spibsc_exit_spi_mode(&sflash_dev);
    }
    return ret;
}

/* 0x20104BD8: program n bytes from the object's address on, in pages of 256 bytes (512 for two chips): each page
 * WREN, wait WEL, PP (0x02) + address, data, wait ready. A partial page waits in sflash_page_buf for the next call;
 * a page that starts with buffered bytes sends those first [fact] */
int sflash_page_program(sflash_dev_t *d, const uint8_t *p, int n)
{
    uint8_t cmd[4], wren[4];
    int page = (int)d->dual * 0x100 + 0x100;
    int ret;

    cmd[0] = 0x02;
    wren[0] = 0x06;
    ret = spibsc_enter_spi_mode(d);
    if (ret != 0)
    {
        return ret;
    }
    while (n != 0)
    {
        cmd[1] = (uint8_t)(d->addr >> 16);
        cmd[2] = (uint8_t)(d->addr >> 8);
        cmd[3] = (uint8_t)d->addr;
        sflash_cmd_write(d, wren, 1, 0);
        ret = sflash_wait_wel(d);
        if (ret != 0)
        {
            return ret;
        }
        if (sflash_page_fill == 0)
        {
            if (page <= n)
            {
                sflash_cmd_write(d, cmd, 4, 1);
                spibsc_xfer(d, p, page, 0);
                n -= page;
                p += page;
                d->addr += 0x100;
            }
        }
        else if (page <= sflash_page_fill + n)
        {
            int had;

            sflash_cmd_write(d, cmd, 4, 1);
            spibsc_xfer(d, sflash_page_buf, sflash_page_fill, 1);
            spibsc_xfer(d, p, page - sflash_page_fill, 0);
            had = sflash_page_fill;
            sflash_page_fill = 0;
            n -= page - had;
            p += page - had;
            d->addr += 0x100;
        }
        ret = sflash_wait_ready(d);
        if (d->error != 0)
        {
            break;
        }
        if (n < page)
        {
            for (; n != 0; n--)
            {
                sflash_page_buf[sflash_page_fill++] = *p++;
            }
        }
        if (ret != 0)
        {
            break;
        }
    }
    spibsc_exit_spi_mode(&sflash_dev);
    return ret;
}

/* 0x20104D9C: WREN, wait WEL, Global Block Unlock (0x98), wait ready [fact for the commands; the command name: W25Q128
 * datasheet] */
int sflash_global_unlock(sflash_dev_t *d)
{
    uint8_t ulk[4], wren[4];
    int ret;

    ulk[0] = 0x98;
    wren[0] = 0x06;
    ret = spibsc_enter_spi_mode(d);
    if (ret != 0)
    {
        return ret;
    }
    sflash_cmd_write(d, wren, 1, 0);
    ret = sflash_wait_wel(d);
    if (ret == 0)
    {
        sflash_cmd_write(d, ulk, 1, 0);
        ret = sflash_wait_ready(d);
        spibsc_exit_spi_mode(&sflash_dev);
    }
    return ret;
}

/* 0x20104E20: device read: in read mode the data (FAST_READ; an odd count rounded up for two chips, n returned, or
 * -3 on failure); after an erase or program command its status byte (a partial page is padded with 0xFF and
 * programmed first); -1 if the device has failed [fact] */
int sflash_dev_read(uint8_t *buf, uint32_t n)
{
    sflash_dev_t *d = &sflash_dev;
    int odd, ret;

    if (d->mode == 1)
    {
        odd = d->dual != 0 && (n & 1) != 0;
        if (odd)
        {
            n++;
        }
        ret = sflash_fast_read(d, buf, n);
        if (d->error != 0)
        {
            d->mode = 0;
            return -1;
        }
        if (odd)
        {
            n--;
            d->mode = 0;
        }
        if (ret != 0)
        {
            n = (uint32_t)-3;
            d->mode = 0;
        }
        return (int)n;
    }
    if (d->mode == 3)
    {
        if (sflash_page_fill != 0)
        {
            int page = (int)d->dual * 0x100 + 0x100;

            for (; sflash_page_fill < page; sflash_page_fill++)
            {
                sflash_page_buf[sflash_page_fill] = 0xFF;      /* pad the partial page and program it */
            }
            sflash_page_fill = 0;
            sflash_page_program(d, sflash_page_buf, page);
        }
    }
    else if (d->mode != 2)
    {
        d->mode = 0;
        d->error = 0;
        return 0;
    }
    d->mode = 0;
    *buf = (uint8_t)d->error;
    d->error = 0;
    return 1;
}

/* 0x20104F34: device command: 'r' + 1 + address = start a read, 'e' + 1 + address = erase the block, 'p' + 1 +
 * address [+ data] = start programming (more data follows in later calls while programming), 'd' + digit = dual
 * mode, 'b' = global unlock; -4 for an unknown or short command or a wrong state, -1 if the device has failed [fact] */
int sflash_dev_write(const uint8_t *c, uint32_t n)
{
    sflash_dev_t *d = &sflash_dev;
    uint32_t len = n;

    if (d->error != 0)
    {
        return -1;
    }
    if (d->mode == 1)
    {
        d->mode = 0;
        d->addr = 0;
    }
    else if (d->mode == 3)
    {
        sflash_page_program(d, c, len);
        return (int)n;
    }
    else if (d->mode != 0)
    {
        return -4;
    }
    switch (c[0])
    {
    case 'r':
        if (n < 6)
        {
            return -4;
        }
        d->mode = 1;
        d->addr = c[2] | c[3] << 8 | c[4] << 16 | (uint32_t)c[5] << 24;
        return (int)n;
    case 'e':
        if (n < 6)
        {
            return -4;
        }
        d->mode = 2;
        d->addr = c[2] | c[3] << 8 | c[4] << 16 | (uint32_t)c[5] << 24;
        return sflash_erase_block(d);
    case 'p':
        if (n < 6)
        {
            return -4;
        }
        d->mode = 3;
        d->addr = c[2] | c[3] << 8 | c[4] << 16 | (uint32_t)c[5] << 24;
        if (n < 7)
        {
            d->mode = 3;
            return (int)n;
        }
        sflash_page_program(d, c + 6, n - 6);
        return (int)n;
    case 'd':
        if (n < 2)
        {
            return -4;
        }
        d->dual = c[1] - '0';
        return (int)n;
    case 'b':
        sflash_global_unlock(d);
        return (int)n;
    default:
        return -4;
    }
}

/* 0x20105060: bind the device object to SPIBSC0 [fact] */
int sflash_dev_open(void)
{
    sflash_dev.base = &REG8(SPIBSC0_BASE);
    return 0;
}
