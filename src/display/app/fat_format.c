/*
 * FT-710 DISPLAY (T24 round 7): the SD format code's partition-table helpers, 0x2013EE64..0x2013F087 and
 * 0x2013F210, recreated from the image.
 *
 * The format code (sd_fat_format, docs/code/display/filesystem.md) fills one MBR partition entry from a geometry
 * block: sectors per track and heads, the first sector and the sector count, the FAT type. The CHS fields follow
 * the usual MBR rules: past cylinder 1023 (LBA 0xFB0400 = 1024 x 255 x 63 [inference: the constant]) the head is
 * 0xFE and sector/cylinder 0xFF [fact: the code].
 */
#include <stdint.h>

/* the geometry block [fact: the offsets the helpers load] */
typedef struct
{
    uint16_t spt;             /* +0: sectors per track */
    uint16_t heads;           /* +2 */
    uint32_t _r0;
    uint32_t start;           /* +8: first sector of the partition */
    uint32_t count;           /* +0xC: its sectors */
    uint32_t _r1;
    uint8_t fat_type;         /* +0x14: 12, 16 or 32 */
} fat_fmt_geom_t;

#define CHS_LBA_LIMIT 0xFB0400U

void fs_memcpy(void *dst, const void *src, uint32_t n);   /* 0x2014D128 */

extern const uint8_t fat_fmt_geom_small[0x2C];   /* 0x20420300: below 0x7E0000 sectors */
extern const uint8_t fat_fmt_geom_large[0x2C];   /* 0x2042032C */

/* the head of an LBA: (lba % (heads x spt)) / spt */
static inline uint8_t chs_head(const fat_fmt_geom_t *g, uint32_t lba, uint32_t limit_lba)
{
    if (limit_lba >= CHS_LBA_LIMIT)
    {
        return 0xFE;
    }
    return (uint8_t)(lba % ((uint32_t)g->heads * g->spt) / g->spt);
}

/* sector (bits 5..0, 1-based) and cylinder (bits 7..6 of the first byte: cylinder bits 9..8; the second byte its
 * low 8 bits) */
static inline void chs_sector_cyl(const fat_fmt_geom_t *g, uint32_t lba, uint32_t limit_lba, uint8_t *out)
{
    if (limit_lba >= CHS_LBA_LIMIT)
    {
        out[0] = 0xFF;
        out[1] = 0xFF;
        return;
    }
    {
        uint32_t sector = lba % g->spt + 1;
        uint32_t cyl = lba / ((uint32_t)g->heads * g->spt);

        out[0] = (uint8_t)((cyl >> 8) << 6 | sector);
        out[1] = (uint8_t)cyl;
    }
}

/* 0x2013EE64 / 0x2013EF9C: the start / end head; 0 when the geometry has no sectors or heads [fact] */
void mbr_chs_head(const fat_fmt_geom_t *g, uint8_t *out)
{
    *out = 0;
    if (g->spt != 0 && g->heads != 0)
    {
        *out = chs_head(g, g->start, g->start);
    }
}

void mbr_chs_end_head(const fat_fmt_geom_t *g, uint8_t *out)
{
    *out = 0;
    if (g->spt != 0 && g->heads != 0)
    {
        *out = chs_head(g, g->start + g->count - 1, g->count);
    }
}

/* 0x2013EEBC / 0x2013F000: the start / end sector and cylinder bytes (the end one tests the count against the
 * limit, not the end sector) [fact] */
void mbr_chs_sector_cyl(const fat_fmt_geom_t *g, uint8_t *out)
{
    out[0] = 0;
    out[1] = 0;
    if (g->spt != 0 && g->heads != 0)
    {
        chs_sector_cyl(g, g->start, g->start, out);
    }
}

void mbr_chs_end_sector_cyl(const fat_fmt_geom_t *g, uint8_t *out)
{
    out[0] = 0;
    out[1] = 0;
    if (g->spt != 0 && g->heads != 0)
    {
        chs_sector_cyl(g, g->start + g->count - 1, g->count, out);
    }
}

/* 0x2013EF3C: the partition type byte: FAT12/16 0x01 (below 0x7FA8 sectors), 0x04 (below 0x10000), 0x06; FAT32 0x0B
 * (CHS-addressable) or 0x0C (LBA); another FAT type leaves it [fact] */
void mbr_partition_type(const fat_fmt_geom_t *g, uint8_t *out)
{
    if (g->fat_type == 12 || g->fat_type == 16)
    {
        *out = g->count < 0x7FA8 ? 1 : g->count < 0x10000 ? 4 : 6;
    }
    else if (g->fat_type == 32)
    {
        *out = g->count < CHS_LBA_LIMIT ? 0xB : 0xC;
    }
}

/* 0x2013F210: (card sectors, out): one of the two 0x2C-byte format parameter blocks [fact] */
void fat_format_geometry_small(uint32_t sectors, void *out)
{
    fs_memcpy(out, sectors < 0x7E0000 ? fat_fmt_geom_small : fat_fmt_geom_large, 0x2C);
}
