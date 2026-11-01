/*
 * FT-710 DISPLAY (T24 round 9): the FAT layer's volumes, 0x20148E80..0x201491A0 and 0x2014A4A4..0x2014AC2F: the
 * boot-sector and MBR recognition, the FSInfo sector, the layer's start and end, attaching, mounting, unmounting
 * and detaching a drive. Recreated from the image's disassembly.
 *
 * A drive is mounted by its driver: op 5 initialises it, op 7 mounts it (for the SD card sd_drive_mount, which
 * reads the MBR and the boot sector through sd_mount_volume and the functions here), op 8 unmounts it
 * [fact: the blx ip with r1 = 5, 7, 8 at 0x2014A6CC, 0x2014A728, 0x2014AB38]. Most functions end with
 * fs_set_error, whose result (0 or -1) they return.
 */
#include "fs.h"

int fs_set_error(int err, uint8_t *file);
int fs_set_error_m2(int err);
int fs_drive_sem_create(fs_drive_t *d);
int fs_drive_sem_delete(fs_drive_t *d);
void *fs_work_alloc(void);
int fs_work_free(void *blk);
int fs_mpf_create(void);
int fs_mpf_delete(void);
int fs_work_pool_create(void);
int fs_work_pool_delete(void);
int fs_sem_a_create(void);
int fs_sem_b_create(void);
int fs_sem1_create(void);
int fs_sem2_create(void);
int fs_sem_a_delete(void);
int fs_sem_b_delete(void);
int fs_sem1_delete(void);
int fs_sem2_delete(void);
int fs_count_free(int letter, uint32_t *free, uint32_t *total, void *work);   /* 0x2014B730 */
int memcmp(const void *a, const void *b, unsigned n);

extern fs_drive_t *fs_drive_list;          /* 0x20808BA0 */
extern void *fs_drives;                    /* 0x20808B90: the drive table fs_init got (0x450 bytes each) */
extern int16_t fs_ndrives;                 /* 0x20808B94 */
extern void *fs_files;                     /* 0x20808B98: the file table (0x24C bytes each) */
extern int16_t fs_nfiles;                  /* 0x20808B9C */

/* the type names of a boot sector: "EXFAT" at +3 (the OEM name), "FAT32" at +0x52, "FAT12" / "FAT16" at +0x36 (the
 * file-system type of the BPB) [fact: the compares at 0x20148FD8..0x20149040]; 0x40 stands for exFAT */
static inline int fat_type_of(const uint8_t *boot)
{
    if (memcmp(boot + 3, "EXFAT", 5) == 0)
    {
        return 0x40;
    }
    if (memcmp(boot + 0x52, "FAT32", 5) == 0)
    {
        return 0x20;
    }
    if (memcmp(boot + 0x36, "FAT12", 5) == 0)
    {
        return 0x0C;
    }
    if (memcmp(boot + 0x36, "FAT16", 5) == 0)
    {
        return 0x10;
    }
    return -1;
}

/* 0x20148E80 (no Ghidra entry: fat_find_volume's tail call for a sector 0 without a partition): a "superfloppy",
 * whose sector 0 is the boot sector: first sector 0 and the type from the names; 0, or -1 for exFAT and an
 * unknown type [fact] */
int fat_detect_superfloppy(fs_drive_t *d, const uint8_t *boot)
{
    d->first = 0;
    int t = fat_type_of(boot);
    if (t < 0)
    {
        return -1;
    }
    d->fat_type = (uint8_t)t;
    return d->fat_type == 0x40 ? -1 : 0;
}

/* 0x20148F40: FAT32 FSInfo: with its three signatures ("RRaA", "rrAa", 0x55 0xAA) the free count (0x1E8) and the
 * next free cluster (0x1EC); -1 otherwise [fact; the layout from the FAT specification] */
int fat32_fsinfo_read(fs_drive_t *d, const uint8_t *s)
{
    if (memcmp(s, "RRaA", 4) != 0 || memcmp(s + 0x1E4, "rrAa", 4) != 0 || s[0x1FE] != 0x55 || s[0x1FF] != 0xAA)
    {
        return -1;
    }
    d->free_count = fat_ld_dword(s + 0x1E8);
    d->next_free = fat_ld_dword(s + 0x1EC);
    return 0;
}

/* 0x20148FCC: the BPB of a boot sector into the drive: the type, sectors per cluster, reserved sectors, FATs, root
 * entries, total sectors (16 or 32 bits), sectors per FAT, for FAT32 the 32-bit FAT size when the 16-bit one is 0,
 * the root cluster and the FSInfo sector; -1 for exFAT and an unknown type [fact] */
int fat_mount(fs_drive_t *d, const uint8_t *boot)
{
    int t = fat_type_of(boot);

    if (t < 0)
    {
        return -1;
    }
    d->fat_type = (uint8_t)t;
    if (d->fat_type == 0x40)
    {
        return -1;
    }
    d->spc = boot[0x0D];
    d->rsv = (uint16_t)fat_ld_word(boot + 0x0E);
    d->nfats = boot[0x10];
    d->root_entries = (uint16_t)fat_ld_word(boot + 0x11);
    d->sectors = fat_ld_word(boot + 0x13);
    if (d->sectors == 0)
    {
        d->sectors = fat_ld_dword(boot + 0x20);
    }
    d->fat_size = fat_ld_word(boot + 0x16);
    if (d->fat_type == 0x20)
    {
        if (d->fat_size == 0)
        {
            d->fat_size = fat_ld_dword(boot + 0x24);
        }
        d->root_cluster = fat_ld_dword(boot + 0x2C);
        d->fsinfo = (uint16_t)fat_ld_word(boot + 0x30);
    }
    return 0;
}

/* 0x201490F8: sector 0 of a device: -1 without the 0x55 0xAA signature; with a first partition entry (+0x1BE) that
 * starts somewhere, its start and the type from the partition type (7 exFAT, 1 FAT12, 4/6/0x0E FAT16, 0x0B/0x0C
 * FAT32); any other entry, or none, as a superfloppy [fact] */
int fat_find_volume(fs_drive_t *d, const uint8_t *mbr)
{
    if (mbr[0x1FE] != 0x55 || mbr[0x1FF] != 0xAA)
    {
        return -1;
    }
    const uint8_t *pe = mbr + 0x1BE;
    d->first = fat_ld_dword(pe + 8);
    if (d->first != 0)
    {
        int pt = (fs_char_t)pe[4];
        int t;

        if (pt == 7)
        {
            t = 0x40;
        }
        else if (pt == 1)
        {
            t = 0x0C;
        }
        else if (pt == 4 || pt == 6 || pt == 0x0E)
        {
            t = 0x10;
        }
        else if (pt == 0x0B || pt == 0x0C)
        {
            t = 0x20;
        }
        else
        {
            return fat_detect_superfloppy(d, mbr);
        }
        d->fat_type = (uint8_t)t;
        return 0;
    }
    return fat_detect_superfloppy(d, mbr);
}

/* 0x2014A4A4: -18 before fs_init, -17 without a drive, else 0 [fact] */
int fs_check_ready(void)
{
    if (fs_drives == 0)
    {
        return -18;
    }
    return fs_drive_list == 0 ? -17 : 0;
}

/* 0x2014A4D0: (drive table, drives, file table, files): clears both tables, keeps them, no drive yet; creates the
 * pools and semaphores (errors -30, -36, -33, -39, -42) [fact] */
int fs_init(void *drives, int16_t ndrives, void *files, int16_t nfiles)
{
    fs_memset(drives, 0, ndrives * 0x450, 0);
    fs_memset(files, 0, nfiles * 0x24C, 0);
    fs_drives = drives;
    fs_ndrives = ndrives;
    fs_files = files;
    fs_nfiles = nfiles;
    fs_drive_list = 0;
    fs_mpf_create();
    if (fs_work_pool_create() < 0)
    {
        return fs_set_error(-30, 0);
    }
    if (fs_sem_a_create() != 0)
    {
        return fs_set_error(-36, 0);
    }
    if (fs_sem_b_create() != 0)
    {
        return fs_set_error(-33, 0);
    }
    if (fs_sem1_create() != 0)
    {
        return fs_set_error(-39, 0);
    }
    if (fs_sem2_create() != 0)
    {
        return fs_set_error(-42, 0);
    }
    return fs_set_error(0, 0);
}

/* fs_drive_attach and fs_drive_mount: a FAT32 volume without a known free count gets one counted
 * (fs_count_free, -31 without a work buffer); the allocation hint starts at FSInfo's next free cluster, else 2.
 * Returns the count's result, or 0 */
static inline int fs_fat32_counts(fs_drive_t *d, int *err)
{
    uint32_t n[2];
    int r = 0;

    if (d->free_count == (uint32_t)-1)
    {
        void *w = fs_work_alloc();
        if (w == 0)
        {
            *err = -31;
            return 0;
        }
        r = fs_count_free(d->letter, n, n, w);
        fs_work_free(w);
    }
    if (d->next_free == (uint32_t)-1)
    {
        d->next_free = 2;
    }
    d->alloc_hint = d->next_free;
    return r;
}

/* 0x2014A5DC: (drive, letter, driver, its argument, removable, bytes per sector): a cleared record at the end of the
 * drive list, the driver's op 5; unless removable its op 7 (mount), clusters of at most 128 KB, the FAT32 counts.
 * Errors: -18 before fs_init, -45 without a semaphore, -16 for larger clusters, -53 / -31 [fact] */
int fs_drive_attach(fs_drive_t *d, int letter, int (*op)(fs_drive_t *, int, uint32_t, uint32_t, uint32_t),
                    uint32_t ctx, int removable, uint32_t bps)
{
    int r = 0;

    if (fs_check_ready() == -18)
    {
        return fs_set_error(-18, 0);
    }
    fs_memset(d, 0, 0x74, bps);
    d->letter = (fs_char_t)fs_toupper(letter);
    d->bps = bps;
    d->ctx = ctx;
    d->op = op;
    d->flags = 0;
    if (removable)
    {
        d->flags = 1;
    }
    d->root_cluster = 0;
    d->alloc_hint = 2;
    if (fs_drive_list == 0)
    {
        fs_drive_list = d;
    }
    else
    {
        fs_drive_t *p = fs_drive_list;
        while (p->next != 0)
        {
            p = p->next;
        }
        p->next = d;
    }
    d->next = 0;
    d->fat_cache_slots = 0;
    d->fat_cache_secs = 0;
    d->fat_cache = 0;
    d->dir_cache_slots = 0;
    d->dir_cache_secs = 0;
    d->dir_cache = 0;
    if ((r = d->op(d, 5, 0, 0, 1)) != 0)
    {
        return fs_set_error_m2(r);
    }
    r = fs_drive_sem_create(d);
    if (r < 0)
    {
        return fs_set_error(-45, 0);
    }
    if (removable)
    {
        return fs_set_error(r, 0);
    }
    if ((r = d->op(d, 7, 0, 0, 1)) != 0)
    {
        return fs_set_error_m2(r);
    }
    if ((fs_char_t)d->fat_type == 0x40)
    {
        return fs_set_error(r, 0);
    }
    if (d->bps * d->spc > 0x20000)
    {
        return fs_set_error(fs_drive_sem_delete(d) != 0 ? -53 : -16, 0);
    }
    if ((fs_char_t)d->fat_type == 0x20)
    {
        int err = 0;
        r = fs_fat32_counts(d, &err);
        if (err != 0)
        {
            return fs_set_error(fs_drive_sem_delete(d) != 0 ? -53 : err, 0);
        }
    }
    return fs_set_error(r, 0);
}

/* 0x2014A818: fs_drive_attach with 512-byte sectors [fact] */
int fs_drive_attach_512(fs_drive_t *d, int letter, int (*op)(fs_drive_t *, int, uint32_t, uint32_t, uint32_t),
                        uint32_t ctx, int removable)
{
    return fs_drive_attach(d, letter, op, ctx, removable, 0x200);
}

/* 0x2014A83C: the reverse of fs_init: the tables cleared, the drives' semaphores, the pools and the semaphores
 * deleted (errors -53, -48, -50, -49, -51, -52) [fact] */
int fs_exit(void)
{
    fs_drive_t *d = fs_drive_list;

    if (fs_check_ready() == -18)
    {
        return fs_set_error(0, 0);
    }
    fs_memset(fs_drives, 0, fs_ndrives * 0x450, 0);
    fs_memset(fs_files, 0, fs_nfiles * 0x24C, 0);
    fs_drives = 0;
    fs_ndrives = 0;
    fs_files = 0;
    fs_nfiles = 0;
    for (; d != 0; d = d->next)
    {
        if (d->sem > 0 && fs_drive_sem_delete(d) != 0)
        {
            return fs_set_error(-53, 0);
        }
    }
    fs_drive_list = 0;
    fs_mpf_delete();
    if (fs_work_pool_delete() != 0)
    {
        return fs_set_error(-48, 0);
    }
    if (fs_sem_a_delete() != 0)
    {
        return fs_set_error(-50, 0);
    }
    if (fs_sem_b_delete() != 0)
    {
        return fs_set_error(-49, 0);
    }
    if (fs_sem1_delete() != 0)
    {
        return fs_set_error(-51, 0);
    }
    if (fs_sem2_delete() != 0)
    {
        return fs_set_error(-52, 0);
    }
    return fs_set_error(0, 0);
}

/* 0x2014A99C: the BPB fields of a drive zeroed before a mount [fact] */
void fs_vol_clear_geometry(fs_drive_t *d)
{
    d->first = 0;
    d->fat_type = 0;
    d->spc = 0;
    d->rsv = 0;
    d->nfats = 0;
    d->root_entries = 0;
    d->sectors = 0;
    d->fat_size = 0;
    d->root_cluster = 0;
    d->fsinfo = 0;
    d->free_count = 0;
    d->next_free = 0;
}

/* 0x2014A9D4: driver op 7 on a cleared geometry; clusters of more than 128 KB unmount it (-16); the FAT32 counts;
 * then mounted (bit 7) [fact] */
int fs_drive_mount(fs_drive_t *d)
{
    int r = fs_check_ready();

    if (r != 0)
    {
        return fs_set_error(r, 0);
    }
    d->alloc_hint = 2;
    fs_vol_clear_geometry(d);
    if ((r = d->op(d, 7, 0, 0, 1)) != 0)
    {
        return fs_set_error_m2(r);
    }
    if ((fs_char_t)d->fat_type != 0x40)
    {
        if (d->bps * d->spc > 0x20000)
        {
            d->flags &= ~0x80;
            return fs_set_error(-16, 0);
        }
        if ((fs_char_t)d->fat_type == 0x20)
        {
            int err = 0;
            r = fs_fat32_counts(d, &err);
            if (err != 0)
            {
                return fs_set_error(err, 0);
            }
        }
    }
    d->flags |= 0x80;
    return fs_set_error(r, 0);
}

/* 0x2014AAF0: a removable drive: driver op 8, not mounted any more; -16 for a fixed one [fact] */
int fs_drive_unmount(fs_drive_t *d)
{
    int r = fs_check_ready();

    if (r != 0)
    {
        return fs_set_error(r, 0);
    }
    if (!(d->flags & 1))
    {
        return fs_set_error(-16, 0);
    }
    if ((r = d->op(d, 8, 0, 0, 1)) != 0)
    {
        return fs_set_error_m2(r);
    }
    d->flags &= ~0x80;
    return fs_set_error(0, 0);
}

/* 0x2014AB74: a removable drive out of the list, its semaphore deleted; -13 without a drive, -16 for a fixed one,
 * -53 when the semaphore cannot be deleted [fact] */
int fs_drive_detach(fs_drive_t *d)
{
    if (d == 0)
    {
        return fs_set_error(-13, 0);
    }
    if (!(d->flags & 1))
    {
        return fs_set_error(-16, 0);
    }
    if (fs_drive_sem_delete(d) != 0)
    {
        return fs_set_error(-53, 0);
    }
    if (fs_drive_list == d)
    {
        fs_drive_list = d->next;
    }
    else
    {
        fs_drive_t *prev = fs_drive_list;
        for (fs_drive_t *p = prev->next; p != 0; prev = p, p = p->next)
        {
            if (p == d)
            {
                prev->next = p->next;
                break;
            }
        }
    }
    return fs_set_error(0, 0);
}
