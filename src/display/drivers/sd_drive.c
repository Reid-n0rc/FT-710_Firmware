/*
 * FT-710 DISPLAY (T24 round 8): the SD card as a file-system drive, 0x2013E43C..0x2013E7E7 and
 * 0x2013F9F4..0x2013FD8F: the volume mount, the drive's driver entry and its operations (attach, mount, unmount),
 * the card-change bookkeeping of the card monitor (poll, remount, unmount, write protect), the cluster-map state
 * and the SD mutex. Recreated from the image's disassembly.
 *
 * The file system calls a drive through its driver entry (sdhi_drv_init passes sd_driver_op the drive and an
 * operation code); docs/code/display/filesystem.md has the drive records and the card monitor.
 */
#include "norti.h"
#include "sd.h"

int sd_read_sectors(uint32_t sector, uint8_t *buf, uint32_t n, const sd_handle_t *h);
int sd_vol_read(const fs_drive_t *v, uint32_t sector, uint8_t *buf, uint32_t n, const sd_handle_t *h);
int sd_vol_write(const fs_drive_t *v, uint32_t sector, const uint8_t *buf, uint32_t n, const sd_handle_t *h);
int sd_check_card(const sd_handle_t *h);
int sd_card_identify(const sd_handle_t *h);
int sd_read_csd_cid(const sd_handle_t *h);
int sd_selected_op(uint32_t rca, uint32_t len, uint32_t blocks, const sd_handle_t *h);
int sd_cmd7_select(uint32_t rca, const sd_handle_t *h);
int sd_scr_bus_width(const sd_handle_t *h);
int sd_acmd6_set_bus_width(const sd_handle_t *h);
int sd_select_bus_speed(const sd_handle_t *h);
int sd_acmd13_read_status(const sd_handle_t *h);
int sd_card_clock(int on, const sd_handle_t *h);
int fat_find_volume(fs_drive_t *d, const uint8_t *mbr);    /* 0x201490F8 */
int fat_mount(fs_drive_t *d, const uint8_t *boot);         /* 0x20148FCC */
int fat32_fsinfo_read(fs_drive_t *d, const uint8_t *s);    /* 0x20148F40 */
void fs_cache_invalidate(fs_drive_t *d);                   /* 0x201446D0 */
int fs_drive_mount(fs_drive_t *d);                         /* 0x2014A9D4: driver op 7 */
int fs_drive_unmount(fs_drive_t *d);                       /* 0x2014AAF0 */
int fs_clmap_attach_scan(int letter, void *buf, uint32_t size);   /* 0x2014A304 */
void *clmap_buf_get(void);                                 /* 0x20132F6C */
ID os_create_tsk_named(const void *pk, const char *name);  /* 0x2014E5B0 */

/* the card monitor's state, 0x20808B58.. [fact: the literal 0x20808B58 and its offsets] */
extern ID sd_ins_tsk;                      /* 0x20808B58: the "SDInsCheck" task */
extern uint32_t sd_ins_state[];            /* 0x20808B5C: per drive, 1 = card seen */
extern fs_drive_t *sd_ins_drive[];         /* 0x20808B60: per drive */
extern uint32_t sd_clmap_mounted;          /* 0x20808B64 */
extern uint32_t sd_clmap_ready;            /* 0x20808B68 */
extern ID sd_mtx;                          /* 0x20808B6C */
extern const uint8_t sd_ins_ctsk[];        /* 0x2042053C: the task's creation packet */
extern const char sd_ins_name[];           /* 0x2013FA50: "SDInsCheck" */
extern const struct
{
    uint32_t w[3];
} sd_mtx_cmtx;                             /* 0x20420558: the mutex packet (TA_INHERIT) */

/* 0x2013F9F4 / 0x2013F9F8: interrupts and dispatch off / on around a drive flag update [fact: b itron_loc_cpu,
 * b itron_unl_cpu] */
void sd_lock(void)
{
    itron_loc_cpu();
}

void sd_unlock(void)
{
    itron_unl_cpu();
}

/* 0x2013E43C: (drive, handle): sector 0 (the MBR) into the card's buffer, the partition (fat_find_volume; -4), its
 * boot sector (fat_mount; -4 when negative), and for FAT32 the FSInfo sector (its result not used); the read errors
 * returned [fact] */
int sd_mount_volume(fs_drive_t *d, const sd_handle_t *h)
{
    int r = sd_read_sectors(0, h->card->sector, 1, h);

    if (r != 0)
    {
        return r;
    }
    if (fat_find_volume(d, h->card->sector) != 0)
    {
        return -4;
    }
    r = sd_read_sectors(d->first, h->card->sector, 1, h);
    if (r != 0)
    {
        return r;
    }
    if (fat_mount(d, h->card->sector) < 0)
    {
        return -4;
    }
    if (d->fat_type == 0x20)
    {
        r = sd_read_sectors(d->first + d->fsinfo, h->card->sector, 1, h);
        if (r != 0)
        {
            return r;
        }
        fat32_fsinfo_read(d, h->card->sector);
    }
    return 0;
}

/* 0x2013E50C (no Ghidra entry: driver op 7): mount. Power on (slot 9, its error), then three tries of: slot 8 (2),
 * identify, CSD and CID, block length 512, select, for an SD card the bus width, bus speed and SD status, the clock,
 * slot 16 for the speeds 2 and 3, the volume. Mounted: flags bit 7, and bit 5 from the write protect (slot 3),
 * under the CPU lock; else the last error [fact] */
int sd_drive_mount(fs_drive_t *d, const sd_handle_t *h)
{
    int r = h->ops->power_on();

    if (r != 0)
    {
        return r;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((r = h->ops->soft_reset(2)) != 0 || (r = sd_card_identify(h)) != 0 || (r = sd_read_csd_cid(h)) != 0 ||
            (r = sd_selected_op(h->card->rca, 0x200, 1, h)) != 0 || (r = sd_cmd7_select(h->card->rca, h)) != 0)
        {
            continue;
        }
        if (h->card->card_type != 1 &&
            ((r = sd_scr_bus_width(h)) != 0 || (r = sd_acmd6_set_bus_width(h)) != 0 ||
             (r = sd_select_bus_speed(h)) != 0 || (r = sd_acmd13_read_status(h)) != 0))
        {
            continue;
        }
        if ((r = sd_card_clock(1, h)) != 0)
        {
            continue;
        }
        if ((h->card->speed == 2 || h->card->speed == 3) && (r = h->ops->op16()) != 0)
        {
            continue;
        }
        r = sd_mount_volume(d, h);
        if (r == 0)
        {
            sd_lock();
            d->flags |= 0x80;
            if (h->ops->check_wp() != 0)
            {
                d->flags |= 0x20;
            }
            else
            {
                d->flags &= ~0x20;
            }
            sd_unlock();
            return r;
        }
    }
    return r;
}

/* 0x2013E6A0 (no Ghidra entry: driver op 8): unmount: slot 10, then the mounted bit cleared under the lock; 0
 * [fact] */
int sd_drive_unmount(fs_drive_t *d, const sd_handle_t *h)
{
    h->ops->op10();
    sd_lock();
    d->flags &= 0x7F;
    sd_unlock();
    return 0;
}

/* 0x2013E6D0 (no Ghidra entry: driver op 5): attach: open the target (slot 25) and start the card task for the
 * card's drive index (-8 when either fails), then the handle into the drive [fact] */
int sd_drive_attach(fs_drive_t *d, const sd_handle_t *h);

/* 0x2013E71C: the drive's driver entry: (drive, op, a, b, c, handle): 1 read and 2 write (a sector, b buffer,
 * c count; -6 unless the card is in, flags bit 6), 5 attach, 7 mount (-6 unless the card is in), 8 unmount,
 * 9 card check; -3 for the other codes [fact: the jump table 0x2013E740] */
int sd_driver_op(fs_drive_t *d, uint32_t op, uint32_t a, uint32_t b, uint32_t c, const sd_handle_t *h)
{
    switch (op)
    {
    case 1:
        return (d->flags & 0x40) ? sd_vol_read(d, a, (uint8_t *)b, c, h) : -6;
    case 2:
        return (d->flags & 0x40) ? sd_vol_write(d, a, (const uint8_t *)b, c, h) : -6;
    case 5:
        return sd_drive_attach(d, h);
    case 7:
        return (d->flags & 0x40) ? sd_drive_mount(d, h) : -6;
    case 8:
        return sd_drive_unmount(d, h);
    case 9:
        return sd_check_card(h);
    default:
        return -3;
    }
}

/* 0x2013F9FC: (drive, index): the drive into the monitor's table, its state cleared; the "SDInsCheck" task is
 * created (-1 when that fails) and started once [fact] */
int sd_card_task_start(fs_drive_t *d, uint32_t idx)
{
    sd_ins_drive[idx] = d;
    sd_ins_state[idx] = 0;
    if (sd_ins_tsk == 0)
    {
        ID id = os_create_tsk_named(sd_ins_ctsk, sd_ins_name);

        if (id <= 0)
        {
            return -1;
        }
        sd_ins_tsk = id;
        itron_act_tsk(id);
    }
    return 0;
}

int sd_drive_attach(fs_drive_t *d, const sd_handle_t *h)
{
    if (h->ops->open() != 0 || sd_card_task_start(d, h->card->drive) != 0)
    {
        return -8;
    }
    d->sd = h;
    return 0;
}

/* 0x2013FAF4: (index): -1 without a handle; card in and seen: 1 when mounted, else the cache cleared and the drive
 * mounted (1, or its error); otherwise a mounted drive is unmounted (0, or its error) [fact] */
int sd_card_remount(uint32_t idx)
{
    fs_drive_t *d = sd_ins_drive[idx];
    int r;

    if (d->sd == 0)
    {
        return -1;
    }
    if (d->sd->ops->check_card() == 0 && (sd_ins_drive[idx]->flags & 0x40))
    {
        if (sd_ins_drive[idx]->flags & 0x80)
        {
            return 1;
        }
        fs_cache_invalidate(sd_ins_drive[idx]);
        r = fs_drive_mount(sd_ins_drive[idx]);
        return r != 0 ? r : 1;
    }
    if (!(sd_ins_drive[idx]->flags & 0x80))
    {
        return 0;
    }
    r = fs_drive_unmount(sd_ins_drive[idx]);
    return r;
}

/* 0x2013FB8C: (mounted): the cluster map's card state, its ready flag cleared [fact] */
void sd_clmap_state_set(uint32_t mounted)
{
    sd_clmap_mounted = mounted;
    sd_clmap_ready = 0;
}

/* 0x2013FBA0: once per mount, at priority 6: the cluster map of drive I: (0x20000-byte buffer); ready when that
 * succeeded; its result, or 0 when there is nothing to do [fact] */
int sd_clmap_prepare(void)
{
    int r;

    if (sd_clmap_mounted == 0 || sd_clmap_ready != 0)
    {
        return 0;
    }
    itron_chg_pri(0, 6);
    r = fs_clmap_attach_scan('I', clmap_buf_get(), 0x20000);
    itron_chg_pri(0, 0);
    if (r == 0)
    {
        sd_clmap_ready = 1;
    }
    return r;
}

/* 0x2013FC10: the SD mutex from the packet 0x20420558 [fact] */
void sd_mutex_create(void)
{
    typeof(sd_mtx_cmtx) pk = sd_mtx_cmtx;

    sd_mtx = itron_acre_mtx(0, &pk);
}

/* 0x2013FC4C: (lock): lock (no timeout) or unlock the SD mutex [fact] */
void sd_mutex_lock(int lock)
{
    if (lock != 0)
    {
        itron_tloc_mtx(sd_mtx, -1);
        return;
    }
    itron_unl_mtx(sd_mtx);
}

/* 0x2013FC68: (index, state): the card monitor's step: -1 without a handle. Card in and seen: on a new insertion
 * (state bit 6 clear) a drive not yet mounted is mounted under the mutex (0x40 when that fails, then the cluster
 * map's state), 0xC0; else the state unchanged. Otherwise the drive's flags without bits 6, 7 (sign-extended),
 * and a mounted drive is unmounted (0 when that succeeds) [fact] */
int sd_card_poll(uint32_t idx, int state)
{
    fs_drive_t *d = sd_ins_drive[idx];
    int8_t f;

    if (d->sd == 0)
    {
        return -1;
    }
    if (d->sd->ops->check_card() == 0 && ((f = sd_ins_drive[idx]->flags) & 0x40))
    {
        if (state & 0x40)
        {
            return state;
        }
        if (!(f & 0x80))
        {
            int r;

            itron_tloc_mtx(sd_mtx, -1);
            fs_cache_invalidate(sd_ins_drive[idx]);
            r = fs_drive_mount(sd_ins_drive[idx]);
            itron_unl_mtx(sd_mtx);
            if (r != 0)
            {
                return 0x40;
            }
            sd_clmap_state_set(1);
        }
        return 0xC0;
    }
    f = sd_ins_drive[idx]->flags;
    state = f & ~0xC0;
    if (f & 0x80)
    {
        sd_clmap_state_set(0);
        if (fs_drive_unmount(sd_ins_drive[idx]) == 0)
        {
            state = 0;
        }
    }
    return state;
}

/* 0x2013FD3C: (ms) a task delay in 10 ms ticks [fact] */
void sd_delay_ms(int ms)
{
    itron_dly_tsk(ms / 10);
}

/* 0x2013FD50 (Ghidra's C shows fs_drive_unmount's body): (index): -1 without a handle, else fs_drive_unmount of
 * the drive [fact: the disassembly, b 0x2014AAF0] */
int sd_card_unmount(uint32_t idx)
{
    fs_drive_t *d = sd_ins_drive[idx];

    if (d->sd == 0)
    {
        return -1;
    }
    return fs_drive_unmount(d);
}

/* 0x2013FD70 (no Ghidra entry; called from 0x20103BC4): (index): the write-protect bit 5 of the drive's flags,
 * 0 without a handle [fact] */
int sd_card_write_protected(uint32_t idx)
{
    fs_drive_t *d = sd_ins_drive[idx];

    if (d->sd == 0)
    {
        return 0;
    }
    return ((uint8_t)d->flags >> 5) & 1;
}
