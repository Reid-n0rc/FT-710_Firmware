/*
 * FT-710 DISPLAY (T24 rounds 7, 8): the SD format code, 0x2013E7E8..0x2013F9E3: the progress counters, the
 * layout from the CSD capacity, the MBR, boot sector, FSInfo, FAT and root directory writes, the format of a card
 * and of a drive. Recreated from the image (round 7: the partition-table helpers; round 8: the rest).
 *
 * The format code (sd_fat_format, docs/code/display/filesystem.md) fills one MBR partition entry from a geometry
 * block: sectors per track and heads, the first sector and the sector count, the FAT type. The CHS fields follow
 * the usual MBR rules: past cylinder 1023 (LBA 0xFB0400 = 1024 x 255 x 63 [inference: the constant]) the head is
 * 0xFE and sector/cylinder 0xFF [fact: the code].
 */
#include "sd.h"

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

/* ---- round 8: the format steps ---- */

/* 0x2014D148: words when dst is aligned and n == aligned_n, else bytes */
void fs_memset(void *dst, int c, uint32_t n, uint32_t aligned_n);
void fat_st_word(uint8_t *p, uint32_t v);        /* 0x2014D8EC: little-endian store */
void fat_st_dword(uint8_t *p, uint32_t v);       /* 0x2014D918 */
int fs_get_time_tm(uint32_t tm[6]);              /* 0x2014E1DC: {sec, min, hour, mday, mon, year} */
uint32_t csd_read_bl_len(const uint8_t *csd);
uint32_t csd_c_size(const uint8_t *csd);
uint32_t csd_c_size_mult(const uint8_t *csd);
int sd_cmd7_select(uint32_t rca, const sd_handle_t *h);
int sd_card_clock(int on, const sd_handle_t *h);
int sd_card_identify(const sd_handle_t *h);
int sd_read_csd_cid(const sd_handle_t *h);
int sd_selected_op(uint32_t rca, uint32_t len, uint32_t blocks, const sd_handle_t *h);
int sd_scr_bus_width(const sd_handle_t *h);
int sd_acmd6_set_bus_width(const sd_handle_t *h);
int sd_select_bus_speed(const sd_handle_t *h);
int sd_write_sectors(uint32_t sector, const uint8_t *buf, uint32_t n, const sd_handle_t *h);
int fs_check_ready(void);                        /* 0x2014A4A4 */
int fs_toupper(int c);                           /* 0x2014D35C */
int fs_find_drive(int letter, fs_drive_t **drive);   /* 0x20144918 */

extern const uint8_t fat_fmt_geom_table[11][0x2C];   /* 0x20420358: by card size, for standard-capacity cards */
extern const uint8_t fat_media_fat12[3];         /* 0x20420254: F8 FF FF */
extern const uint8_t fat_media_fat16[4];         /* 0x20420257: F8 FF FF FF */
extern const uint8_t fat_media_fat32[12];        /* 0x204202F3: F8 FF FF 0F FF FF FF 0F FF FF FF 0F */
extern const uint8_t fat_boot_fat16[0x3E];       /* 0x2042025B: FAT12/16 boot sector template */
extern const uint8_t fat_boot_fat32[0x5A];       /* 0x20420299: FAT32 boot sector template */
extern const uint8_t *const fsinfo_lead_sig;     /* 0x20808B4C: "RRaA" */
extern const uint8_t *const fsinfo_struct_sig;   /* 0x20808B50: "rrAa" */
extern fs_drive_t *fs_drive_list;                /* 0x20808BA0: the first drive record */

/* 0x2013E7E8: one sector written: the progress counter +0x2F4 down, not below 0 [fact] */
void sd_format_progress_dec(sd_card_t *c)
{
    if (c->progress != 0)
    {
        c->progress--;
    }
}

/* 0x2013E800: (sectors, card): both counters set [fact] */
void sd_format_progress_set(uint32_t n, sd_card_t *c)
{
    c->progress = n;
    c->progress_total = n;
}

/* the zeroed sector buffer [fact: every step starts with fs_memset(card + 1, 0, 0x200, 0)] */
static inline uint8_t *fmt_sector_clear(const sd_handle_t *h)
{
    fs_memset(h->card->sector, 0, 0x200, 0);
    return h->card->sector;
}

static inline int fmt_write(const sd_handle_t *h, uint32_t sector)
{
    return sd_write_sectors(sector, h->card->sector, 1, h);
}

/* 0x2013E80C (no Ghidra entry; the tail call of fat_format_volume): zero the root directory: 32 sectors after
 * the FATs for FAT12/16, one cluster for FAT32, each counted; -2 for another FAT type [fact] */
int fat_format_clear_root(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    uint32_t sector, n;
    int r = 0;

    fmt_sector_clear(h);
    if (g->fat_type == 12 || g->fat_type == 16)
    {
        n = 0x20;
    }
    else if (g->fat_type == 32)
    {
        n = g->spc;
    }
    else
    {
        return -2;
    }
    sector = g->start + g->reserved + g->fat_size * 2;
    for (uint32_t i = 0; i < n; i++, sector++)
    {
        r = fmt_write(h, sector);
        if (r != 0)
        {
            return r;
        }
        sd_format_progress_dec(h->card);
    }
    return r;
}

/* 0x2013E8D0: the two FATs: the first sector of each with the media entries, then zero sectors, counted;
 * -2 for another FAT type (the tests for type 0x40, a single FAT, cannot be reached) [fact] */
int fat_format_write_fats(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    uint32_t fat1, fat2 = 0, n;
    int r;

    fmt_sector_clear(h);
    if (g->fat_type == 12)
    {
        fs_memcpy(h->card->sector, fat_media_fat12, 3);
    }
    else if (g->fat_type == 16)
    {
        fs_memcpy(h->card->sector, fat_media_fat16, 4);
    }
    else if (g->fat_type == 32)
    {
        fs_memcpy(h->card->sector, fat_media_fat32, 12);
    }
    else
    {
        return -2;
    }
    fat1 = g->start + g->reserved;
    r = fmt_write(h, fat1);
    if (r != 0)
    {
        return r;
    }
    if ((uint8_t)g->fat_type != 0x40)
    {
        fat2 = g->start + g->reserved + g->fat_size;
        r = fmt_write(h, fat2);
        if (r != 0)
        {
            return r;
        }
    }
    sd_format_progress_dec(h->card);
    fmt_sector_clear(h);
    n = g->fat_size - 1;
    if ((uint8_t)g->fat_type == 0x40)
    {
        return r;
    }
    fat1++;
    fat2++;
    for (uint32_t i = 0; i < n; i++, fat1++, fat2++)
    {
        int e = fmt_write(h, fat1);

        if (e != 0)
        {
            return e;
        }
        r = fmt_write(h, fat2);
        if (r != 0)
        {
            return r;
        }
        sd_format_progress_dec(h->card);
    }
    return r;
}

/* the boot-sector signature 55 AA at offset 510 */
static inline void fmt_signature(uint8_t *s)
{
    s[510] = 0x55;
    s[511] = 0xAA;
}

/* 0x2013EA74: FAT32 FSInfo at sectors 1 and 7 of the partition (signatures through the pointers 0x20808B4C /
 * 0x20808B50, free count and next free 0xFFFFFFFF), then sectors 2 and 8 empty with the signature [fact] */
int fat32_format_write_fsinfo(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    uint8_t *s = fmt_sector_clear(h);
    uint32_t start;
    int r;

    fs_memcpy(s, fsinfo_lead_sig, 4);
    fs_memcpy(h->card->sector + 0x1E4, fsinfo_struct_sig, 4);
    fat_st_dword(h->card->sector + 0x1E8, 0xFFFFFFFFU);
    fat_st_dword(h->card->sector + 0x1EC, 0xFFFFFFFFU);
    fmt_signature(h->card->sector);
    start = g->start;
    r = fmt_write(h, start + 1);
    if (r != 0)
    {
        return r;
    }
    r = fmt_write(h, start + 7);
    if (r != 0)
    {
        return r;
    }
    fmt_sector_clear(h);
    fmt_signature(h->card->sector);
    start = g->start;
    r = fmt_write(h, start + 2);
    if (r != 0)
    {
        return r;
    }
    return fmt_write(h, start + 8);
}

/* 0x2013EBC0: the volume serial number from the clock (struct tm): high half day + (month + 1) << 8 + second << 8,
 * low half year + 1900 ORed with minute and hour << 8 (the image ORs where a date code would add) [fact] */
uint32_t fat_format_volume_id(void)
{
    uint32_t tm[9];
    uint32_t hi, lo;

    fs_get_time_tm(tm);
    hi = ((tm[3] | ((tm[4] + 1) << 8 & 0xFF00)) + (tm[0] << 8 & 0xFF00)) << 16;
    lo = (uint16_t)tm[1] | ((uint16_t)tm[2] << 8 & 0xFF00);
    return (uint16_t)(tm[5] + 1900) | lo | hi;
}

/* 0x2013EC30: the boot sector from the FAT12/16 template 0x2042025B or the FAT32 one 0x20420299 with the layout's
 * BPB fields and the volume id; FAT12 turns the type string's '6' into '2'; FAT32 also writes the backup at +6
 * [fact] */
int fat_format_write_boot(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    uint8_t *s = fmt_sector_clear(h);
    uint32_t start;
    int r;

    if (g->fat_type != 32)
    {
        fs_memcpy(s, fat_boot_fat16, 0x3E);
        s = h->card->sector;
        fat_st_word(s + 0x0B, g->bps);
        s[0x0D] = (uint8_t)g->spc;
        fat_st_word(h->card->sector + 0x0E, g->reserved);
        fat_st_word(h->card->sector + 0x16, (uint16_t)g->fat_size);
        fat_st_word(h->card->sector + 0x18, g->spt);
        fat_st_word(h->card->sector + 0x1A, g->heads);
        fat_st_dword(h->card->sector + 0x1C, g->start);
        if (g->count < 0x10000)
        {
            fat_st_word(h->card->sector + 0x13, (uint16_t)g->count);
        }
        else
        {
            fat_st_dword(h->card->sector + 0x20, g->count);
        }
        fat_st_dword(h->card->sector + 0x27, fat_format_volume_id());
        if (g->fat_type == 12)
        {
            h->card->sector[0x3A] = '2';
        }
        fmt_signature(h->card->sector);
        return fmt_write(h, g->start);
    }
    fs_memcpy(s, fat_boot_fat32, 0x5A);
    s = h->card->sector;
    fat_st_word(s + 0x0B, g->bps);
    s[0x0D] = (uint8_t)g->spc;
    fat_st_word(h->card->sector + 0x0E, g->reserved);
    fat_st_word(h->card->sector + 0x18, g->spt);
    fat_st_word(h->card->sector + 0x1A, g->heads);
    fat_st_dword(h->card->sector + 0x1C, g->start);
    fat_st_dword(h->card->sector + 0x20, g->count);
    fat_st_dword(h->card->sector + 0x24, g->fat_size);
    fat_st_dword(h->card->sector + 0x43, fat_format_volume_id());
    fmt_signature(h->card->sector);
    start = g->start;
    r = fmt_write(h, start);
    if (r != 0)
    {
        return r;
    }
    return fmt_write(h, start + 6);
}

/* 0x2013F088: the MBR, sector 0: one partition entry at 0x1BE (CHS start, type, CHS end, LBA start, size) [fact] */
int fat_format_write_mbr(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    uint8_t *e;

    fmt_sector_clear(h);
    e = h->card->sector + 0x1BE;
    mbr_chs_head(g, e + 1);
    mbr_chs_sector_cyl(g, e + 2);
    mbr_partition_type(g, e + 4);
    mbr_chs_end_head(g, e + 5);
    mbr_chs_end_sector_cyl(g, e + 6);
    fat_st_dword(e + 8, g->start);
    fat_st_dword(e + 12, g->count);
    fmt_signature(h->card->sector);
    return fmt_write(h, 0);
}

/* 0x2013F238: (card bytes, out): the parameter record of a standard-capacity card by its size in sectors, from
 * the eleven records 0x20420358.. (below 0x1000, 0x4000, 0x8000, ..., 0x3F0000 sectors, and the rest) [fact] */
void fat_format_geometry(uint32_t bytes, void *out)
{
    static const uint32_t below[10] = {0x1000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0xFC000,
                                       0x1F8000, 0x3F0000};
    uint32_t sectors = bytes >> 9;
    unsigned k = 0;

    while (k < 10 && sectors >= below[k])
    {
        k++;
    }
    fs_memcpy(out, fat_fmt_geom_table[k], 0x2C);
}

/* ceil(a / b) as the image computes it: the quotient, plus one for a remainder */
static inline uint32_t div_up(uint32_t a, uint32_t b)
{
    return a / b + (a % b != 0);
}

/* FAT32: the reserved sectors for the current FAT size: the first multiple of the boundary unit above both
 * FATs, less the FATs, one unit more when fewer than 9 are left; the system area after them [fact:
 * 0x2013F3E8.. and its copy in the loop] */
static inline void layout_reserved(fat_fmt_geom_t *g)
{
    uint32_t n = 1;
    uint16_t rsv;

    while (g->align * n <= g->fat_size * 2)
    {
        n++;
    }
    rsv = (uint16_t)(g->align * n - g->fat_size * 2);
    if (rsv < 9)
    {
        rsv += (uint16_t)g->align;
    }
    g->reserved = rsv;
    g->system = rsv + g->fat_size * 2;
}

/* FAT12/16: the system area with the 32 root directory sectors, and the hidden sectors that put the data area
 * on a boundary (one unit more unless that is exactly one unit) [fact: 0x2013F610..0x2013F66C] */
static inline void layout_start(fat_fmt_geom_t *g, uint32_t rsv)
{
    uint32_t start;

    g->system = rsv + g->fat_size * 2 + 0x20;
    start = g->align < g->system ? g->align * div_up(g->system, g->align) - g->system : g->align - g->system;
    g->start = start;
    if (start != g->align)
    {
        g->start = start + g->align;
    }
}

/* 0x2013F340: the format layout from the CSD. Version 2 (high capacity): (C_SIZE + 1) x 1024 sectors, the record
 * below or above 0x7E0000 sectors, -5 from 0x4000000 sectors (32 GB) up; FAT size, reserved sectors and clusters,
 * iterated until the FAT size fits the clusters; progress FAT + one cluster. Version 1: the capacity from
 * READ_BL_LEN, C_SIZE and C_SIZE_MULT, the table record, the FAT size (its quotient cut to 16 bits) and the hidden
 * sectors, iterated the same way; progress FAT + 32. Then the count less the boundary unit (version 2) or the
 * hidden sectors (version 1). -1 for another CSD structure [fact] */
int fat_format_layout(const sd_handle_t *h)
{
    sd_card_t *c = h->card;
    fat_fmt_geom_t *g = &c->fmt;
    const uint8_t *csd = c->csd;

    if (csd[0] >> 6 == 1)
    {
        uint32_t sectors = ((uint32_t)csd[7] << 16 | (uint32_t)csd[8] << 8 | csd[9]) * 0x400 + 0x400;
        uint32_t spc, bits, data;
        int type;

        fat_format_geometry_small(sectors, g);
        if (sectors >= 0x4000000)
        {
            return -5;
        }
        g->count = sectors;
        type = g->fat_type;
        if (type != 0x40)
        {
            spc = g->spc;
            bits = (uint32_t)g->bps << 3;
            g->fat_size = div_up(sectors / spc * type, bits);
            layout_reserved(g);
            data = sectors - g->start;
            g->clusters = (data - g->system) / spc + 1;
            g->fat_need = div_up(((data - g->system) / spc + 2) * type, bits);
            while (g->fat_size != g->fat_need)
            {
                if (g->fat_size < g->fat_need)
                {
                    g->system += g->align;
                    g->reserved += (uint16_t)g->align;
                }
                else
                {
                    g->fat_size--;
                    layout_reserved(g);
                }
                g->clusters = (data - g->system) / spc + 1;
                g->fat_need = div_up(((data - g->system) / spc + 2) * type, bits);
            }
            sd_format_progress_set(g->fat_size + spc, c);
        }
        g->count -= g->align;
        return 0;
    }
    if (csd[0] >> 6 == 0)
    {
        uint32_t bytes = (csd_c_size(csd) + 1) * csd_c_size_mult(csd) * csd_read_bl_len(csd);
        uint32_t sectors, spc, bits, rsv, q;
        int type;

        fat_format_geometry(bytes, g);
        sectors = bytes >> 9;
        g->count = sectors;
        spc = g->spc;
        q = sectors / spc;
        type = g->fat_type;
        bits = (uint32_t)g->bps << 3;
        g->fat_size = (uint16_t)(q * type / bits) + (q * type % bits != 0);
        rsv = g->reserved;
        layout_start(g, rsv);
        g->clusters = (sectors - g->start - g->system) / spc + 1;
        g->fat_need = div_up(((sectors - g->start - g->system) / spc + 2) * type, bits);
        while (g->fat_size != g->fat_need)
        {
            if (g->fat_size < g->fat_need)
            {
                g->start += g->align;
            }
            else
            {
                g->fat_size = g->fat_need;
                layout_start(g, rsv);
            }
            g->clusters = (sectors - g->start - g->system) / spc + 1;
            g->fat_need = div_up(((sectors - g->start - g->system) / spc + 2) * type, bits);
        }
        sd_format_progress_set(g->fat_size + 0x20, c);
        g->count -= g->start;
        return 0;
    }
    return -1;
}

/* 0x2013F79C (Ghidra: fat_clear_root_dir): format the volume: the parameters cleared, the layout, MBR, boot
 * sector, FSInfo (FAT32), FATs, then the root directory zeroed as fat_format_clear_root does [fact] */
int fat_format_volume(const sd_handle_t *h)
{
    const fat_fmt_geom_t *g = &h->card->fmt;
    int r;

    fs_memset(&h->card->fmt, 0, 0x2C, 0);
    r = fat_format_layout(h);
    if (r != 0)
    {
        return r;
    }
    r = fat_format_write_mbr(h);
    if (r != 0)
    {
        return r;
    }
    if ((uint8_t)g->fat_type != 0x40)
    {
        r = fat_format_write_boot(h);
        if (r != 0)
        {
            return r;
        }
        if (g->fat_type == 32)
        {
            r = fat32_format_write_fsinfo(h);
            if (r != 0)
            {
                return r;
            }
        }
    }
    r = fat_format_write_fats(h);
    if (r != 0)
    {
        return r;
    }
    return fat_format_clear_root(h);
}

/* 0x2013F83C: (handle): power on (slot 9, its error), then three tries of: slot 8 (2), identify (an MMC: -5),
 * CSD and CID, block length 512, select, bus width, bus speed, clock, slot 16 for the speeds 2 and 3, the volume
 * format; the last error [fact] */
int sd_fat_format(const sd_handle_t *h)
{
    int r = h->ops->power_on();

    if (r != 0)
    {
        return r;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((r = h->ops->soft_reset(2)) != 0 || (r = sd_card_identify(h)) != 0)
        {
            continue;
        }
        if (h->card->card_type == 1)
        {
            return -5;
        }
        if ((r = sd_read_csd_cid(h)) != 0 || (r = sd_selected_op(h->card->rca, 0x200, 1, h)) != 0 ||
            (r = sd_cmd7_select(h->card->rca, h)) != 0 || (r = sd_scr_bus_width(h)) != 0 ||
            (r = sd_acmd6_set_bus_width(h)) != 0 || (r = sd_select_bus_speed(h)) != 0 ||
            (r = sd_card_clock(1, h)) != 0)
        {
            continue;
        }
        if ((h->card->speed == 2 || h->card->speed == 3) && (r = h->ops->op16()) != 0)
        {
            continue;
        }
        r = fat_format_volume(h);
        if (r == 0)
        {
            return 0;
        }
    }
    return r;
}

/* 0x2013F984: (drive letter): format the SD card of that drive: -8 while the file system is busy or when the drive
 * has no SD handle, -2 for an unknown letter [fact] */
int sd_format(char letter)
{
    fs_drive_t *d = fs_drive_list;

    if (fs_check_ready() != 0)
    {
        return -8;
    }
    if (fs_find_drive((uint8_t)fs_toupper(letter), &d) != 0)
    {
        return -2;
    }
    if (d->sd == 0)
    {
        return -8;
    }
    return sd_fat_format(d->sd);
}
