/*
 * FT-710 DISPLAY (T24 round 9): the FAT layer's capacity and free-space queries, 0x2014AF44..0x2014B8D3: the file
 * size, the split of a sector count into 4 GiB units and bytes, the volume size, the free-cluster counts of
 * FAT12, FAT16 and FAT32 and their wrappers. Recreated from the image's disassembly.
 *
 * Sizes come back as two words, *hi in units of 0x800000 sectors (4 GiB with 512-byte sectors) and *lo in bytes
 * [fact: fs_split_sectors 0x2014AFCC]; FAT12/16 counts always give *hi = 0.
 */
#include "fs.h"

int fs_check_ready(void);
int fs_set_error(int err, uint8_t *file);
int fs_file_check(const uint8_t *file);
int fs_find_drive(int letter, fs_drive_t **out);
int fs_drive_check_mounted(const fs_drive_t *d);
int fs_lock_b(const fs_drive_t *d);
int fs_unlock_b(const fs_drive_t *d);
int fat_table_sector_get(fs_drive_t *d, uint32_t n, uint8_t **p, uint8_t *work);
void *fs_work_alloc(void);
int fs_work_free(void *blk);

extern fs_drive_t *fs_drive_list;          /* 0x20808BA0 */

/* clusters + 2 the FAT can describe and the volume holds, the smaller of the two [fact: the three counters] */
static inline uint32_t fat_cluster_limit(const fs_drive_t *d, uint32_t fat_entries)
{
    uint32_t ncl = (d->sectors - ((uint32_t)(d->root_entries << 5) / d->bps + d->fat_size * d->nfats + d->rsv)) /
                   d->spc + 2;

    return ncl < fat_entries ? ncl : fat_entries;
}

/* 0x2014AF44: the 4-byte file size (+0x2C) to out; 0 [fact] */
int fs_file_size_copy(const uint8_t *file, void *out)
{
    fs_memcpy(out, file + 0x2C, 4);
    return 0;
}

/* 0x2014AF64: (file, *size): the file's size; -13 without an output [fact] */
int fs_fsize(uint8_t *file, void *size)
{
    int r = fs_check_ready();

    if (r == 0 && (r = fs_file_check(file)) == 0)
    {
        if (size == 0)
        {
            return fs_set_error(-13, file);
        }
        return fs_set_error(fs_file_size_copy(file, size), file);
    }
    return fs_set_error(r, 0);
}

/* 0x2014AFCC: (sectors, *hi, *lo, bytes per sector): whole units of 0x800000 / (bps / 512) sectors and the rest in
 * bytes [fact] */
void fs_split_sectors(uint32_t n, uint32_t *hi, uint32_t *lo, uint32_t bps)
{
    uint32_t unit = 0x800000u / (bps >> 9);

    if (n < unit)
    {
        *hi = 0;
        *lo = n * bps;
        return;
    }
    *hi = n / unit;
    *lo = (n % unit) * bps;
}

/* 0x2014B020: (letter, *hi, *lo): the data area of the drive, (clusters - 2) x sectors per cluster; -17 for no
 * such drive, -13 for an unknown type [fact] */
int fs_disk_total_calc(int letter, uint32_t *hi, uint32_t *lo)
{
    fs_drive_t *d = fs_drive_list;
    uint32_t lim;

    while (fs_toupper(letter) != d->letter)
    {
        d = d->next;
        if (d == 0)
        {
            return -17;
        }
    }
    switch ((fs_char_t)d->fat_type)
    {
    case 0x0C:
        lim = (uint32_t)(d->bps * d->fat_size * 2) / 3;
        break;
    case 0x10:
        lim = (d->bps >> 1) * d->fat_size;
        break;
    case 0x20:
        lim = (d->bps >> 2) * d->fat_size;
        break;
    default:
        return -13;
    }
    lim = fat_cluster_limit(d, lim);
    fs_split_sectors(d->spc * (lim - 2), hi, lo, d->bps);
    return 0;
}

/* 0x2014B140: (letter, *hi, *lo): fs_disk_total_calc for a mounted drive, the result recorded; -13 without the
 * outputs [fact] */
int fs_disk_size(int letter, uint32_t *hi, uint32_t *lo)
{
    fs_drive_t *d = fs_drive_list;
    int r = fs_check_ready();

    if (r != 0)
    {
        return fs_set_error(r, 0);
    }
    if (hi == 0 || lo == 0)
    {
        return fs_set_error(-13, 0);
    }
    if ((r = fs_find_drive((uint8_t)fs_toupper(letter), &d)) != 0 || (r = fs_drive_check_mounted(d)) != 0)
    {
        return fs_set_error(r, 0);
    }
    return fs_set_error(fs_disk_total_calc(fs_toupper(letter), hi, lo), 0);
}

/* 0x2014B1E0: (drive, *hi, *lo, work, use the known count): FAT32 free space. With a known FSInfo count (and the
 * flag) that count; else the zero entries from cluster 2 counted, and the next-free hint (+0x40, +0x28) set to
 * the start of the longest free run (of the last when it is the longest); -13 when a FAT sector has no buffer
 * [fact] */
int fat32_count_free(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work, int known)
{
    uint32_t spc = d->spc;
    uint32_t nfree = 0, run = 0, best = 0, best_at = 0, run_at = 0;
    uint8_t *p = 0;

    if (known && d->free_count != (uint32_t)-1)
    {
        fs_split_sectors(d->free_count * spc, hi, lo, d->bps);
        return 0;
    }
    uint32_t lim = fat_cluster_limit(d, (d->bps >> 2) * d->fat_size);
    uint32_t last = (uint32_t)-1;
    uint32_t c = 2;
    if (c < lim)
    {
        do
        {
            uint32_t per = d->bps >> 2;
            uint32_t n = c / per, off = (c % per) << 2;

            if (last != n)
            {
                int r = fat_table_sector_get(d, n, &p, work);
                last = n;
                if (r != 0)
                {
                    return r;
                }
            }
            if (p == 0)
            {
                return -13;
            }
            if (fat_ld_dword(p + off) == 0)
            {
                if (run++ == 0)
                {
                    run_at = c;
                }
                nfree++;
            }
            else
            {
                if (best < run)
                {
                    best = run;
                    best_at = run_at;
                }
                run = 0;
            }
            c++;
        } while (c < lim);
        if (run < best)
        {
            d->next_free = best_at;
            d->alloc_hint = best_at;
            goto done;
        }
    }
    d->next_free = run_at;
    d->alloc_hint = run_at;
done:
    d->free_count = nfree;
    fs_split_sectors(d->spc * nfree, hi, lo, d->bps);
    return 0;
}

/* 0x2014B394: fat32_count_free under the FAT lock (-34) [fact] */
int fat32_count_free_locked(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work, int known)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    int r = fat32_count_free(d, hi, lo, work, known);
    fs_unlock_b(d);
    return r;
}

/* 0x2014B3E8: FAT16 free space: the zero entries from cluster 2; *hi 0, *lo in bytes [fact] */
int fat16_count_free(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    uint32_t nfree = 0, last = (uint32_t)-1;
    uint8_t *p = 0;
    uint32_t lim = fat_cluster_limit(d, (d->bps >> 1) * d->fat_size);

    for (uint32_t c = 2; c < lim; c++)
    {
        uint32_t per = d->bps >> 1;
        uint32_t n = c / per, off = (c % per) << 1;

        if (last != n)
        {
            int r = fat_table_sector_get(d, n, &p, work);
            last = n;
            if (r != 0)
            {
                return r;
            }
        }
        if (p == 0)
        {
            return -13;
        }
        if (fat_ld_word(p + off) == 0)
        {
            nfree++;
        }
    }
    *hi = 0;
    *lo = d->spc * d->bps * nfree;
    return 0;
}

/* 0x2014B500: fat16_count_free under the FAT lock [fact] */
int fat16_count_free_locked(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    int r = fat16_count_free(d, hi, lo, work);
    fs_unlock_b(d);
    return r;
}

/* 0x2014B54C: FAT12 free space, the entries unpacked as fat_entry_rw does (one may straddle two FAT sectors); the
 * limit is 16 bits [fact] */
int fat12_count_free(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    uint32_t nfree = 0, last = (uint32_t)-1;
    uint8_t *p = 0;
    uint8_t b[2];
    uint32_t lim = (uint16_t)((uint32_t)(d->bps * d->fat_size * 2) / 3);
    uint32_t ncl = (uint16_t)fat_cluster_limit(d, 0xFFFFFFFFu);

    if (ncl < lim)
    {
        lim = ncl;
    }
    for (uint32_t c = 2; c < lim; c = (uint16_t)(c + 1))
    {
        uint32_t bps = d->bps;
        uint32_t n = c * 3 / (bps << 1);
        int off = (c * 3 >> 1) - bps * n;
        uint32_t v;

        if (last != n)
        {
            int r = fat_table_sector_get(d, n, &p, work);
            last = n;
            if (r != 0)
            {
                return r;
            }
        }
        if (p == 0)
        {
            return -13;
        }
        b[0] = p[off];
        if (d->bps - 1 == (uint32_t)off)
        {
            last = n + 1;
            off = -1;
            int r = fat_table_sector_get(d, last, &p, work);
            if (r != 0)
            {
                return r;
            }
        }
        b[1] = p[off + 1];
        v = fat_ld_word(b);
        if (c & 1)
        {
            v >>= 4;
        }
        v &= ~0xF000u;
        if (v >= 0xFF7)
        {
            v |= 0xF000;
        }
        if (v == 0)
        {
            nfree++;
        }
    }
    *hi = 0;
    *lo = d->spc * d->bps * nfree;
    return 0;
}

/* 0x2014B6E4: fat12_count_free under the FAT lock [fact] */
int fat12_count_free_locked(fs_drive_t *d, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    int r = fat12_count_free(d, hi, lo, work);
    fs_unlock_b(d);
    return r;
}

/* 0x2014B730: (letter, *hi, *lo, work): free space of a drive by its type (FAT32 with the known count); the drive
 * lookup's error, -13 for an unknown type [fact] */
int fs_count_free(int letter, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    fs_drive_t *d = fs_drive_list;
    int r = fs_find_drive((uint8_t)fs_toupper(letter), &d);

    if (r != 0)
    {
        return r;
    }
    switch ((fs_char_t)d->fat_type)
    {
    case 0x0C:
        return fat12_count_free_locked(d, hi, lo, work);
    case 0x10:
        return fat16_count_free_locked(d, hi, lo, work);
    case 0x20:
        return fat32_count_free_locked(d, hi, lo, work, 1);
    default:
        return -13;
    }
}

/* 0x2014B7DC: fs_count_free for a mounted drive, the result recorded; -13 without the outputs [fact] */
int fs_disk_free_work(int letter, uint32_t *hi, uint32_t *lo, uint8_t *work)
{
    fs_drive_t *d = fs_drive_list;
    int r = fs_check_ready();

    if (r != 0)
    {
        return fs_set_error(r, 0);
    }
    if (hi == 0 || lo == 0)
    {
        return fs_set_error(-13, 0);
    }
    if ((r = fs_find_drive((uint8_t)fs_toupper(letter), &d)) != 0 || (r = fs_drive_check_mounted(d)) != 0)
    {
        return fs_set_error(r, 0);
    }
    return fs_set_error(fs_count_free(fs_toupper(letter), hi, lo, work), 0);
}

/* 0x2014B880: (letter, *hi, *lo): free space with a work buffer of its own; -31 without one [fact] */
int fs_disk_free(int letter, uint32_t *hi, uint32_t *lo)
{
    uint8_t *w = fs_work_alloc();

    if (w == 0)
    {
        return fs_set_error(-31, 0);
    }
    int r = fs_disk_free_work(letter, hi, lo, w);
    fs_work_free(w);
    return r;
}
