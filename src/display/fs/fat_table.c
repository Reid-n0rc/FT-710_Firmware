/*
 * FT-710 DISPLAY (T24 round 9): the FAT layer's cluster arithmetic and allocation table, 0x20144800..0x201449FF
 * and 0x2014919C..0x2014A0DF: errors, drive checks, cluster <-> sector, the FAT sectors (through the FAT cache or
 * the work buffer), FAT12/16/32 entries, chains, the cluster-use bitmap, the free-cluster search and allocation,
 * the next sector of a chain, the FSInfo update. Recreated from the image's disassembly.
 *
 * Callers pass a work buffer (fs_work_alloc) down; without a FAT cache its sector buffer at +0xC0C holds the FAT
 * sector [fact: fat_table_sector_get 0x20149230]. Entry values follow the FAT specification: 0 free, >= 0xFFF8
 * (FAT16) / 0x0FFFFFF8 (FAT32) end of chain; this layer returns 0x0FFFFFF7 (BAD) for a failed access.
 */
#include "fs.h"

#define FAT_BAD 0x0FFFFFF7u     /* returned for an access error [fact: mvn r0, #0xf0000008] */
#define FAT_EOC 0x0FFFFFFFu

int fs_task_ctx_get(void);
void fs_task_err_set(int err);
int fs_lock_b(const fs_drive_t *d);
int fs_unlock_b(const fs_drive_t *d);
int fs_sem_wait_1s(int id);
int fs_sem_signal(int id);
int fatcache_lookup(fs_drive_t *d, uint32_t sector);              /* 0x20143C48: slot 1.., 0 when not cached */
int fatcache_load(fs_drive_t *d, uint32_t sector, uint16_t *slot); /* 0x20143CBC */
void fatcache_touch(fs_drive_t *d, uint32_t slot);                /* 0x20143E10 */

extern fs_drive_t *fs_drive_list;          /* 0x20808BA0 */
extern int fs_last_error;                  /* 0x20808BA4 */
extern const uint8_t clmap_bit[8];         /* 0x20808BAC: 1 << n */

/* first sector of the data area: reserved, the FATs, the FAT12/16 root directory [fact: fat_clust2sect] */
static inline uint32_t fat_data_start(const fs_drive_t *d)
{
    return (uint32_t)(d->root_entries << 5) / d->bps + d->fat_size * d->nfats + d->rsv;
}

/* 0x201447F4: the last error of the layer [fact] */
int fs_last_error_get(void)
{
    return fs_last_error;
}

/* 0x20144800: records err (last error, the task's error, the file's +0x10 when given); -1 for an error, else 0 */
int fs_set_error(int err, uint8_t *file)
{
    fs_last_error = err;
    fs_task_err_set(err);
    if (file != 0)
    {
        *(int *)(file + 0x10) = err;
    }
    return err < 0 ? -1 : 0;
}

/* 0x20144834: the same without a file, -2 for an error [fact] */
int fs_set_error_m2(int err)
{
    fs_last_error = err;
    fs_task_err_set(err);
    return err < 0 ? -2 : 0;
}

/* 0x2014485C: records err and returns ret [fact] */
int fs_set_error_ret(int err, int ret)
{
    fs_last_error = err;
    fs_task_err_set(err);
    return ret;
}

/* 0x20144878: a file handle: -13 when null, -6 when not open (+0x442), else 0 [fact] */
int fs_file_check(const uint8_t *file)
{
    if (file == 0)
    {
        return -13;
    }
    return file[0x442] == 0 ? -6 : 0;
}

/* 0x20144898: the same for a directory handle (open flag +4) [fact] */
int fs_dir_check(const uint8_t *dir)
{
    if (dir == 0)
    {
        return -13;
    }
    return dir[4] == 0 ? -6 : 0;
}

/* 0x201448B8: 1 when sector is the first of its cluster (only asked with more than one sector per cluster) */
int fat_sector_is_cluster_first(const fs_drive_t *d, uint32_t sector)
{
    uint32_t spc = d->spc;

    if (spc > 1 && (sector - fat_data_start(d) + 1) % spc == 1)
    {
        return 1;
    }
    return 0;
}

/* 0x20144918: the drive of a letter in fs_drive_list (*out when given); -12 when there is none [fact] */
int fs_find_drive(int letter, fs_drive_t **out)
{
    fs_drive_t *d = fs_drive_list;

    do
    {
        if (d->letter == letter)
        {
            if (out != 0)
            {
                *out = d;
            }
            return 0;
        }
        d = d->next;
    } while (d != 0);
    return -12;
}

/* 0x20144950: -19 for a removable drive (flags bit 0) that is not mounted (bit 7) [fact] */
int fs_drive_check_mounted(const fs_drive_t *d)
{
    int f = d->flags;

    if ((f & 1) && !(f & 0x80))
    {
        return -19;
    }
    return 0;
}

/* 0x20144970: -58 when the drive is write-protected (flags bit 5) [fact] */
int fs_drive_check_writable(const fs_drive_t *d)
{
    uint32_t wp = (uint8_t)d->flags & 0x20;

    return wp ? -58 : 0;
}

/* 0x20144980: the first sector of a cluster, 0 for clusters 0 and 1 [fact] */
uint32_t fat_clust2sect(const fs_drive_t *d, uint32_t cl)
{
    if (cl < 2)
    {
        return 0;
    }
    return d->fat_size * d->nfats + (uint32_t)(d->root_entries << 5) / d->bps + (cl - 2) * d->spc + d->rsv;
}

/* 0x201449CC: the cluster of a data sector [fact] */
uint32_t fat_sect2clust(const fs_drive_t *d, uint32_t sector)
{
    return (sector - fat_data_start(d)) / d->spc + 2;
}

/* fs_dev_op1 / fs_dev_op2: the driver's read (1) or write (2) of n sectors under the device semaphore (1 s);
 * -46 / -47 when the semaphore fails, err when there is no drive or the driver fails [fact: 0x20144A10] */
static inline int fs_dev_rw(fs_drive_t *d, int cmd, uint32_t sector, void *buf, uint32_t n, int err)
{
    if (d != 0)
    {
        if (fs_sem_wait_1s(d->sem) != 0)
        {
            fs_set_error(-46, 0);
            return -46;
        }
        int r = d->op(d, cmd, sector, (uint32_t)buf, n);
        if (fs_sem_signal(d->sem) != 0)
        {
            fs_set_error(-47, 0);
            return -47;
        }
        if (r == 0)
        {
            fs_set_error(0, 0);
            return 0;
        }
    }
    fs_set_error(err, 0);
    return err;
}

int fs_dev_op1(fs_drive_t *d, uint32_t sector, void *buf, uint32_t n)       /* 0x20144A10: read, -8 */
{
    return fs_dev_rw(d, 1, sector, buf, n, -8);
}

int fs_dev_op2(fs_drive_t *d, uint32_t sector, const void *buf, uint32_t n) /* 0x20144AC0: write, -9 */
{
    return fs_dev_rw(d, 2, sector, (void *)buf, n, -9);
}

/* 0x2014919C: *p = FAT sector n (of the first FAT) in memory: through the FAT cache (loaded when missing), else
 * read into the work buffer; -11 past the FAT [fact] */
int fat_table_sector_get(fs_drive_t *d, uint32_t n, uint8_t **p, uint8_t *work)
{
    uint16_t slot;

    if (n >= d->fat_size)
    {
        return -11;
    }
    uint32_t sector = d->rsv + n;
    if (d->fat_cache == 0)
    {
        int r = fs_dev_op1(d, sector, work + 0xC0C, 1);
        if (r != 0)
        {
            return r;
        }
        *p = work + 0xC0C;
        return 0;
    }
    int s = fatcache_lookup(d, sector);
    if (s != 0)
    {
        slot = (uint16_t)s;
    }
    else
    {
        int r = fatcache_load(d, sector, &slot);
        if (r != 0)
        {
            return r;
        }
    }
    *p = d->fat_cache + (slot - 1) * d->bps + d->fat_cache_hdr * 4;
    slot = (uint16_t)((int)(slot - 1) / (int)d->fat_cache_slots + 1);
    fatcache_touch(d, slot);
    return 0;
}

/* 0x20149278: after a change of FAT sector n: marks its cache slot dirty (bit 31 of the slot's header word; -69
 * when it is not cached), or without a cache writes buf to the first FAT and, unless there is only one, to the
 * second; -11 past the FAT [fact] */
int fat_table_sector_dirty(fs_drive_t *d, uint32_t n, const uint8_t *buf)
{
    uint8_t *cache = d->fat_cache;

    if (n >= d->fat_size)
    {
        return -11;
    }
    uint32_t sector = d->rsv + n;
    if (cache == 0)
    {
        int r = fs_dev_op2(d, sector, buf, 1);
        if (r != 0)
        {
            return r;
        }
        if (d->nfats == 1)
        {
            return 0;
        }
        return fs_dev_op2(d, d->fat_size + sector, buf, 1);
    }
    int s = fatcache_lookup(d, sector);
    if (s == 0)
    {
        return -69;
    }
    uint32_t slot = (uint16_t)((s - 1) / (int)d->fat_cache_slots + 1);
    fatcache_touch(d, slot);
    ((uint32_t *)cache)[slot - 1] |= 0x80000000u;
    return 0;
}

/* 0x2014933C: a FAT32 entry; BAD on an access error (-9 for exFAT) [fact] */
uint32_t fat32_entry_get(fs_drive_t *d, uint32_t cl, uint8_t *work)
{
    uint32_t per = d->bps >> 2;
    uint32_t idx = cl % per;
    uint8_t *p;
    uint32_t w;

    if (fat_table_sector_get(d, cl / per, &p, work) != 0)
    {
        return d->fat_type == 0x40 ? (uint32_t)-9 : FAT_BAD;
    }
    w = ((uint32_t *)p)[idx];
    return fat_ld_dword((const uint8_t *)&w);
}

/* 0x201493B4: stores a FAT32 entry and marks its sector [fact] */
int fat32_entry_set(fs_drive_t *d, uint32_t cl, uint32_t v, uint8_t *work)
{
    uint32_t per = d->bps >> 2;
    uint32_t n = cl / per, idx = cl % per;
    uint8_t *p;
    int r = fat_table_sector_get(d, n, &p, work);

    if (r != 0)
    {
        return r;
    }
    ((uint32_t *)p)[idx] = fat_ld_dword((const uint8_t *)&v);
    return fat_table_sector_dirty(d, n, p);
}

/* 0x20149420: (drive, cluster, value, 'r' or 'w', work): reads or writes a FAT entry. FAT32 through the two
 * functions above; FAT16 one word; anything else as FAT12, 12 bits packed in 3 bytes per pair, which may
 * straddle two FAT sectors. Reads end-of-chain values as 0x0FFFFFFF, returns BAD on an access error [fact] */
uint32_t fat_entry_rw(fs_drive_t *d, uint32_t cl, uint32_t v, int mode, uint8_t *work)
{
    int type = (fs_char_t)d->fat_type;
    uint32_t n, val;
    int off;
    uint8_t *p, b[2];

    if (type == 0x20)
    {
        if (mode != 'w')
        {
            return fat32_entry_get(d, cl, work);
        }
        return fat32_entry_set(d, cl, v, work) != 0 ? FAT_BAD : 0;
    }
    if (type == 0x10)
    {
        uint32_t per = d->bps >> 1;
        n = cl / per;
        off = (cl % per) << 1;
    }
    else
    {
        uint32_t bps = d->bps, x = cl * 3;
        n = x / (bps << 1);
        off = (x >> 1) - bps * n;
    }
    if (fat_table_sector_get(d, n, &p, work) != 0)
    {
        return FAT_BAD;
    }
    if (d->fat_type == 0x10)
    {
        val = fat_ld_word(p + off);
        if (mode == 'w')
        {
            fat_st_word(p + off, (uint16_t)v);
            if (fat_table_sector_dirty(d, n, p) != 0)
            {
                return FAT_BAD;
            }
        }
        return val >= 0xFFF8 ? FAT_EOC : val;
    }
    b[0] = p[off];
    if (d->bps - 1 == (uint32_t)off)
    {
        n++;
        off = -1;
        if (fat_table_sector_get(d, n, &p, work) != 0)
        {
            return FAT_BAD;
        }
    }
    b[1] = p[off + 1];
    val = fat_ld_word(b);
    if (cl & 1)
    {
        if (mode == 'w')
        {
            fat_st_word(b, (uint16_t)((val & 0xF) | (v << 4)));
        }
        val >>= 4;
    }
    else if (mode == 'w')
    {
        fat_st_word(b, (val & 0xF000) | (v & 0xFFF));
    }
    if (mode == 'w')
    {
        p[off + 1] = b[1];
        if (off != -1)
        {
            p[off] = b[0];
        }
        else
        {
            if (fat_table_sector_dirty(d, n, p) != 0)
            {
                return FAT_BAD;
            }
            n--;
            if (fat_table_sector_get(d, n, &p, work) != 0)
            {
                return FAT_BAD;
            }
            p[d->bps - 1] = b[0];
        }
        if (fat_table_sector_dirty(d, n, p) != 0)
        {
            return FAT_BAD;
        }
    }
    val &= ~0xF000u;
    if (val >= 0xFF7)
    {
        val |= 0xF000;
    }
    return val >= 0xFFF8 ? FAT_EOC : val;
}

/* 0x2014969C / 0x20149824 / 0x20149844: the cluster-use bitmap: clear, set, test a cluster's bit [fact] */
void clmap_clear(fs_drive_t *d, uint32_t cl)
{
    d->clmap[cl >> 3] &= ~clmap_bit[cl & 7];
}

void clmap_set(fs_drive_t *d, uint32_t cl)
{
    d->clmap[cl >> 3] |= clmap_bit[cl & 7];
}

int clmap_test(const fs_drive_t *d, uint32_t cl)
{
    return d->clmap[cl >> 3] & clmap_bit[cl & 7];
}

/* 0x201496BC: frees the chain from cl: each entry 0, its bitmap bit cleared, the FAT32 free count up, the first
 * cluster kept as the freed hint when there is none; -61 for a bad chain [fact] */
int fat_chain_free(fs_drive_t *d, uint32_t cl, uint8_t *work)
{
    uint32_t c = cl;

    for (;;)
    {
        uint32_t next = fat_entry_rw(d, c, 0, 'r', work);

        if (next == FAT_BAD || c < 2)
        {
            return -61;
        }
        if (d->clmap != 0 && c < d->clmap_clusters)
        {
            clmap_clear(d, c);
        }
        if (fat_entry_rw(d, c, 0, 'w', work) == FAT_BAD)
        {
            return -61;
        }
        if (d->fat_type == 0x20)
        {
            d->free_count++;
        }
        if (next - 0x0FFFFFF8u <= 7)
        {
            if (d->freed_hint == 0)
            {
                d->freed_hint = cl;
            }
            return 0;
        }
        c = next;
    }
}

/* 0x20149788: fat_chain_free under the FAT lock (-34) [fact] */
int fat_chain_free_locked(fs_drive_t *d, uint32_t cl, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    int r = fat_chain_free(d, cl, work);
    fs_unlock_b(d);
    return r;
}

/* 0x201497CC: fat_entry_rw under the FAT lock, the result to *out [fact] */
int fat_entry_rw_locked(fs_drive_t *d, uint32_t *out, uint32_t cl, uint32_t v, int mode, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    *out = fat_entry_rw(d, cl, v, mode, work);
    fs_unlock_b(d);
    return 0;
}

/* 0x20149860: the first clear bitmap bit from the allocation hint up, then from cluster 2 up to the hint; on the
 * way a pending freed hint restarts the search there. Found: set it, *out, the hint after it; -99 when full */
int clmap_find_free(fs_drive_t *d, uint32_t *out)
{
    uint32_t c;

again:
    for (c = d->alloc_hint; c < d->clmap_clusters; c++)
    {
        if (!clmap_test(d, c))
        {
            goto found;
        }
        if (d->freed_hint != 0)
        {
            d->alloc_hint = d->freed_hint;
            d->freed_hint = 0;
            goto again;
        }
    }
wrap:
    if (d->alloc_hint <= 2)
    {
        return -99;
    }
    for (c = 2; c < d->alloc_hint; c++)
    {
        if (c >= d->clmap_clusters)
        {
            continue;
        }
        if (!clmap_test(d, c))
        {
            goto found;
        }
        if (d->freed_hint != 0)
        {
            d->alloc_hint = d->freed_hint;
            d->freed_hint = 0;
            goto wrap;
        }
    }
    return -99;
found:
    *out = c;
    d->alloc_hint = c + 1;
    clmap_set(d, c);
    return 0;
}

/* 0x20149940: a free FAT32 entry from the hint to the last cluster (the smaller of the FAT's entries and the
 * volume's clusters), then once from cluster 2 to the old hint; a pending freed hint restarts the search. A FAT
 * sector is fetched when the scan enters it; -99 when there is none [fact] */
int fat32_find_free(fs_drive_t *d, uint32_t *out, uint8_t *work)
{
    int wrapped = 0;
    uint32_t val = 0;
    uint8_t *p = 0;
    uint32_t fatsz = d->fat_size;
    uint32_t lim = (d->bps >> 2) * fatsz;
    uint32_t ncl = (d->sectors - ((uint32_t)(d->root_entries << 5) / d->bps + fatsz * d->nfats + d->rsv)) / d->spc + 2;
    uint32_t c;

    if (ncl < lim)
    {
        lim = ncl;
    }
    for (;;)
    {
        uint32_t last;
restart:
        last = (uint32_t)-1;
        for (c = d->alloc_hint; c < lim; c++)
        {
            uint32_t per = d->bps >> 2;
            uint32_t n = c / per, idx = c % per;

            if (last != n)
            {
                int r = fat_table_sector_get(d, n, &p, work);
                if (r != 0)
                {
                    return r;
                }
                last = n;
            }
            if (p != 0)
            {
                val = fat_ld_dword(p + idx * 4);
            }
            if (val == 0)
            {
                *out = c;
                d->alloc_hint = c + 1;
                return 0;
            }
            if (d->freed_hint != 0)
            {
                d->alloc_hint = d->freed_hint;
                d->freed_hint = 0;
                goto restart;
            }
        }
        if (c != lim || ++wrapped != 1)
        {
            return -99;
        }
        lim = d->alloc_hint;
        d->alloc_hint = 2;
    }
}

/* 0x20149A80: FAT32 allocation: a free cluster from the bitmap (when enabled, +0x54) or the FAT scan, marked end
 * of chain, its bit set, the freed hint dropped when it is that cluster, the free count down, linked from prev
 * when given; the cluster, or 0 [fact] */
uint32_t fat32_alloc_cluster(fs_drive_t *d, uint32_t prev, uint8_t *work)
{
    const uint8_t *raw = (const uint8_t *)d;
    uint32_t cl;

    if (d->clmap != 0 && raw[0x54] != 0)
    {
        if (clmap_find_free(d, &cl) != 0)
        {
            if (d->clmap_clusters == *(const uint32_t *)(raw + 0x64) || fat32_find_free(d, &cl, work) != 0)
            {
                return 0;
            }
        }
    }
    else if (fat32_find_free(d, &cl, work) != 0)
    {
        return 0;
    }
    if (fat32_entry_set(d, cl, FAT_EOC, work) != 0)
    {
        return 0;
    }
    if (d->clmap != 0 && cl < d->clmap_clusters)
    {
        clmap_set(d, cl);
    }
    if (d->freed_hint == cl)
    {
        d->freed_hint = 0;
    }
    d->free_count--;
    if (prev == 0)
    {
        return cl;
    }
    return fat32_entry_set(d, prev, cl, work) == 0 ? cl : 0;
}

/* 0x20149B8C: (drive, previous cluster, work): a new cluster, end of chain 0xFFFF, linked from prev; FAT32
 * through fat32_alloc_cluster. FAT12/16 search the bitmap first (when enabled), else the FAT from the hint, then
 * once from cluster 2; 0 when the volume is full or on an error [fact] */
uint32_t fat_alloc_cluster(fs_drive_t *d, uint32_t prev, uint8_t *work)
{
    const uint8_t *raw = (const uint8_t *)d;
    int wrapped = 0;
    uint32_t lim, n, cl;

    if ((fs_char_t)d->fat_type == 0x20)
    {
        return fat32_alloc_cluster(d, prev, work);
    }
    if ((fs_char_t)d->fat_type == 0x10)
    {
        lim = (d->bps >> 1) * d->fat_size;
    }
    else
    {
        lim = (uint32_t)(d->bps * d->fat_size * 2) / 3;
    }
    n = (uint16_t)((d->sectors - fat_data_start(d)) / d->spc + 2);
    if (n < lim)
    {
        lim = n;
    }
    if (d->clmap != 0 && raw[0x54] != 0)
    {
        if (clmap_find_free(d, &cl) == 0)
        {
            if (fat_entry_rw(d, cl, 0xFFFF, 'w', work) != 0)
            {
                return 0;
            }
            if (d->freed_hint == cl)
            {
                d->freed_hint = 0;
            }
            if (prev != 0 && fat_entry_rw(d, prev, cl, 'w', work) == FAT_BAD)
            {
                return 0;
            }
            return cl;
        }
        if (d->clmap_clusters == *(const uint32_t *)(raw + 0x64))
        {
            return 0;
        }
    }
    for (;;)
    {
        for (cl = d->alloc_hint; cl < lim; cl++)
        {
            uint32_t e = fat_entry_rw(d, cl, 0, 'r', work);

            if (e == 0)
            {
                d->alloc_hint = cl + 1;
                if (fat_entry_rw(d, cl, 0xFFFF, 'w', work) != 0)
                {
                    return 0;
                }
                if (d->freed_hint == cl)
                {
                    d->freed_hint = 0;
                }
                if (d->clmap != 0 && cl < d->clmap_clusters)
                {
                    clmap_set(d, cl);
                }
                if (prev != 0 && fat_entry_rw(d, prev, cl, 'w', work) == FAT_BAD)
                {
                    return 0;
                }
                return cl;
            }
            if (e == FAT_BAD)
            {
                return 0;
            }
            if (d->freed_hint != 0)
            {
                d->alloc_hint = d->freed_hint;
                d->freed_hint = 0;
                cl = d->alloc_hint - 1;
                continue;
            }
        }
        if (cl != lim || wrapped++ != 0)
        {
            return 0;
        }
        lim = d->alloc_hint;
        d->alloc_hint = 2;
    }
}

/* 0x20149DEC: fat_alloc_cluster under the FAT lock (-34), the cluster to *out; returns the task's error [fact] */
int fat_alloc_cluster_locked(fs_drive_t *d, uint32_t prev, uint32_t *out, uint8_t *work)
{
    fs_set_error(0, 0);
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    *out = fat_alloc_cluster(d, prev, work);
    fs_unlock_b(d);
    return fs_task_ctx_get();
}

/* 0x20149E48: the next cluster of a chain under the FAT lock; 0 at the end (or on an error) [fact] */
int fat_next_cluster(fs_drive_t *d, uint32_t cl, uint32_t *out, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    *out = fat_entry_rw(d, cl, 0, 'r', work);
    if (*out > 0x0FFFFFF6u)
    {
        *out = 0;
    }
    fs_unlock_b(d);
    return 0;
}

/* 0x20149EB0: the sector after sector in its chain; at a cluster's end a new cluster is allocated and linked
 * (the writers), 0 when the volume is full [fact] */
int fat_next_sector_alloc(fs_drive_t *d, uint32_t sector, uint32_t *out, uint8_t *work)
{
    uint32_t spc = d->spc;
    uint32_t cl;

    if (spc > 1 && (sector - fat_data_start(d) + 1) % spc != 0)
    {
        *out = sector + 1;
        return 0;
    }
    int r = fat_alloc_cluster_locked(d, fat_sect2clust(d, sector), &cl, work);
    if (r != 0)
    {
        return r;
    }
    *out = cl == 0 ? 0 : fat_clust2sect(d, cl);
    return 0;
}

/* 0x20149F68: the same for reading: the next cluster of the chain, 0 at its end [fact] */
int fat_next_sector(fs_drive_t *d, uint32_t sector, uint32_t *out, uint8_t *work)
{
    uint32_t spc = d->spc;
    uint32_t cl;

    if (spc > 1 && (sector - fat_data_start(d) + 1) % spc != 0)
    {
        *out = sector + 1;
        return 0;
    }
    int r = fat_next_cluster(d, fat_sect2clust(d, sector), &cl, work);
    if (r != 0)
    {
        return r;
    }
    *out = cl == 0 ? 0 : fat_clust2sect(d, cl);
    return 0;
}

/* 0x2014A020: FAT32: the FSInfo sector read into the work buffer, its free count (0x1E8) and next free (0x1EC,
 * from the allocation hint, which also becomes +0x40) updated and written back; 0 for FAT12/16 [fact] */
int fat32_fsinfo_write(fs_drive_t *d, uint8_t *work)
{
    uint32_t sector = d->fsinfo;

    if (d->fat_type != 0x20)
    {
        return 0;
    }
    int r = fs_dev_op1(d, sector, work + 0xC0C, 1);
    if (r != 0)
    {
        return r;
    }
    fat_st_dword(work + 0xDF4, d->free_count);
    d->next_free = d->alloc_hint;
    fat_st_dword(work + 0xDF8, d->next_free);
    return fs_dev_op2(d, sector, work + 0xC0C, 1);
}

/* 0x2014A0A4: fat32_fsinfo_write under the FAT lock [fact] */
int fat32_fsinfo_write_locked(fs_drive_t *d, uint8_t *work)
{
    if (fs_lock_b(d) != 0)
    {
        return -34;
    }
    int r = fat32_fsinfo_write(d, work);
    fs_unlock_b(d);
    return r;
}
