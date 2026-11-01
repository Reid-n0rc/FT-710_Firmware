/*
 * FT-710 DISPLAY (T24 round 9): the FAT layer's sector caches, 0x20143B70..0x20143FFF: the FAT cache (set-up,
 * lookup, load with write-back, ageing) and the directory cache's set-up and lookup. Recreated from the image's
 * disassembly.
 *
 * A cache lives in a caller's buffer, 4-byte aligned: one header word per slot (the first sector it holds, bit 31
 * dirty), then the slots' sectors, then one age per slot (16 bits; 1 the newest, 0 unused) [fact: the address
 * arithmetic of fatcache_load 0x20143CFC, fat_table_sector_get 0x201491FC, fatcache_touch 0x20143E34]. Lookups
 * return a 1-based sector index across the slots.
 */
#include "fs.h"

int fs_check_ready(void);
int fs_set_error(int err, uint8_t *file);
int fs_dev_op1(fs_drive_t *d, uint32_t sector, void *buf, uint32_t n);
int fs_dev_op2(fs_drive_t *d, uint32_t sector, const void *buf, uint32_t n);

/* 0x20143B70: (drive, buffer, size, sectors per slot): a FAT cache of as many slots as fit (0x206 bytes per sector:
 * the sector, a header word, an age), at most 0xFFFF, cleared; -24 when not even one fits [fact] */
int fs_fatcache_setup(fs_drive_t *d, uintptr_t buf, uint32_t size, int secs)
{
    int r = fs_check_ready();
    uint32_t slots;

    if (r != 0)
    {
        return r;
    }
    /* secs 0: the image divides by zero, which its __aeabi_uidivmod answers with 0, so -24 [fact: the emulation];
     * in C the quotient is undefined (GCC replaced "quotient 0" by "divisor > dividend"), hence the explicit test */
    if (size < (uint32_t)(secs * 0x206) || secs == 0)
    {
        return -24;
    }
    if (buf & 1)
    {
        buf++;
        size--;
    }
    if (buf & 2)
    {
        buf += 2;
        size -= 2;
    }
    slots = size / (uint32_t)(secs * 0x206);
    if (slots >= 0x10000)
    {
        slots = 0xFFFF;
    }
    else if (slots == 0)
    {
        return -24;
    }
    d->fat_cache_slots = (uint16_t)slots;
    d->fat_cache = (uint8_t *)buf;
    d->fat_cache_secs = (uint16_t)secs;
    fs_memset((void *)buf, 0, slots * secs * 0x206, d->bps);
    return 0;
}

/* 0x20143C1C: fs_fatcache_setup with one sector per slot, its result recorded [fact: mov r3, #1] */
int fs_fatcache_setup_a(fs_drive_t *d, uintptr_t buf, uint32_t size)
{
    return fs_set_error(fs_fatcache_setup(d, buf, size, 1), 0);
}

/* 0x20143C34: the same with the caller's sectors per slot [fact] */

int fs_fatcache_setup_b(fs_drive_t *d, uintptr_t buf, uint32_t size, int secs)
{
    return fs_set_error(fs_fatcache_setup(d, buf, size, secs), 0);
}

/* 0x20143C48: the 1-based index of a cached FAT sector, 0 when it is not cached [fact] */
uint32_t fatcache_lookup(const fs_drive_t *d, uint32_t sector)
{
    const uint32_t *hdr = (const uint32_t *)d->fat_cache;

    for (uint32_t i = 0; i < d->fat_cache_slots; i++)
    {
        uint32_t first = hdr[i] & 0x7FFFFFFF;

        if (first != 0 && first <= sector && sector < d->fat_cache_secs + first)
        {
            return (uint16_t)(i * d->fat_cache_secs + (sector - first) + 1);
        }
    }
    return 0;
}

/* 0x20143CBC: (drive, FAT sector, *index): replaces the oldest slot (the first whose age is the slot count, or an
 * unused one) by the run of sectors holding sector: a dirty slot is written back first (the sectors inside the
 * FAT; with two FATs and one sector per slot also to the second FAT), then the run is read; *index as
 * fatcache_lookup gives it [fact] */
int fatcache_load(fs_drive_t *d, uint32_t sector, uint16_t *index)
{
    uint32_t rsv = d->rsv, secs = d->fat_cache_secs;
    uint8_t *cache = d->fat_cache;
    uint32_t first = secs * ((sector - rsv) / secs) + rsv;
    uint32_t slots = d->fat_cache_slots;
    const uint16_t *age = (const uint16_t *)(cache + (d->bps * secs + 4) * slots);
    uint32_t k = 0;

    while (k < slots && age[k] != slots && age[k] != 0)
    {
        k = (uint16_t)(k + 1);
    }
    uint32_t *hdr = (uint32_t *)cache + k;
    uint8_t *data = cache + k * secs * d->bps + slots * 4;
    if (*hdr & 0x80000000u)
    {
        uint32_t old = *hdr & 0x7FFFFFFF;
        uint32_t n = 0;
        int r;

        for (uint32_t i = 0; i < secs; i = (uint16_t)(i + 1))
        {
            if (old + i < d->fat_size + rsv)
            {
                n = (uint16_t)(n + 1);
            }
        }
        r = fs_dev_op2(d, old, data, n);
        if (r != 0)
        {
            return r;
        }
        if (d->nfats == 2 && d->fat_cache_secs == 1)
        {
            r = fs_dev_op2(d, d->fat_size + (*hdr & 0x7FFFFFFF), data, 1);
            if (r != 0)
            {
                return r;
            }
        }
    }
    int r = fs_dev_op1(d, first, data, d->fat_cache_secs);
    if (r != 0)
    {
        return r;
    }
    *hdr = first;
    *index = (uint16_t)fatcache_lookup(d, sector);
    return 0;
}

/* 0x20143E10: slot becomes the newest (age 1); the slots younger than it (or all, when it was unused) age by one;
 * the scan stops at the first unused slot [fact] */
void fatcache_touch(fs_drive_t *d, uint32_t slot)
{
    uint32_t slots = d->fat_cache_slots;
    uint16_t *age = (uint16_t *)(d->fat_cache + (d->bps * d->fat_cache_secs + 4) * slots);
    uint32_t mine = age[slot - 1];

    for (uint32_t k = 1; k <= d->fat_cache_slots; k = (uint16_t)(k + 1), age++)
    {
        uint32_t a = *age;

        if (a != 0 && k != slot && (a < mine || mine == 0))
        {
            a = (uint16_t)(a + 1);
            *age = (uint16_t)a;
        }
        else if (k == slot)
        {
            *age = 1;
            continue;
        }
        if ((uint16_t)a == 0)
        {
            return;
        }
    }
}

/* 0x20143EAC: (drive, buffer, size, sectors per slot): a directory cache of as many slots as fit (0x208 bytes per
 * sector), at most 0x7FFF and at least 3; -28 otherwise; the result recorded [fact] */
int fs_dircache_setup(fs_drive_t *d, uintptr_t buf, uint32_t size, int secs)
{
    int r = fs_check_ready();
    uint32_t slots;

    if (r != 0)
    {
        return fs_set_error(r, 0);
    }
    if (buf != 0 && secs != 0 && (uint32_t)(secs * 0x208) <= size)
    {
        if (buf & 1)
        {
            buf++;
            size--;
        }
        if (buf & 2)
        {
            buf += 2;
            size -= 2;
        }
        slots = size / (uint32_t)(secs * 0x208);
        if (slots > 0x7FFF)
        {
            slots = 0x7FFF;
        }
        if (slots > 2)
        {
            d->dir_cache_slots = (uint16_t)slots;
            d->dir_cache = (uint8_t *)buf;
            d->dir_cache_secs = (uint16_t)secs;
            fs_memset((void *)buf, 0, slots * secs * 0x208, d->bps);
            return fs_set_error(0, 0);
        }
    }
    return fs_set_error(-28, 0);
}

/* 0x20143F78: the 1-based index of a cached directory sector, 0 when it is not cached; a slot's sector count is
 * its own 16-bit word after the data [fact] */
uint32_t dircache_lookup(const fs_drive_t *d, uint32_t sector)
{
    uint32_t slots = d->dir_cache_slots;
    const uint32_t *hdr = (const uint32_t *)d->dir_cache;
    const uint16_t *count = (const uint16_t *)(d->dir_cache + (d->bps * d->dir_cache_secs + 4) * slots);

    for (uint32_t i = 0; i < slots; i++)
    {
        uint32_t first = hdr[i];

        if (first != 0 && first <= sector && sector < count[i] + first)
        {
            return (uint16_t)(i * d->dir_cache_secs + (sector - first) + 1);
        }
    }
    return 0;
}
