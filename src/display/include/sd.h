/*
 * FT-710 DISPLAY (T24 rounds 7, 8): the SD card driver's card context, handle and operation table, as far as the
 * recreated functions use them (drivers/sdhi.c, drivers/sd_card.c). The layout is the image's [fact: the offsets
 * each function loads, cited there]; what the other bytes hold is not established.
 */
#ifndef SD_H
#define SD_H

#include <stdint.h>
#include "fs.h"

/* the format parameters (card context +0x2C8): first a 0x2C-byte record from the capacity tables 0x20420300..
 * (fat_format_geometry*), then fat_format_layout's results [fact: the offsets app/fat_format.c loads] */
typedef struct
{
    uint16_t spt;             /* +0: sectors per track (MBR CHS) */
    uint16_t heads;           /* +2 */
    uint32_t align;           /* +4: the boundary unit the layout aligns the data area to, in sectors */
    uint32_t start;           /* +8: first sector of the partition (hidden sectors) */
    uint32_t count;           /* +0xC: the card's sectors, then the partition's */
    uint16_t spc;             /* +0x10: sectors per cluster (the boot sector takes the low byte) */
    uint16_t bps;             /* +0x12: bytes per sector */
    int8_t fat_type;          /* +0x14: 12, 16 or 32 (0x40 tested, not produced) */
    uint8_t _r0[3];
    uint32_t fat_size;        /* +0x18: sectors per FAT */
    uint16_t reserved;        /* +0x1C: reserved sectors */
    uint16_t _r1;
    uint32_t system;          /* +0x20: reserved + FATs (+ root directory for FAT12/16) */
    uint32_t clusters;        /* +0x24: data clusters + 1 */
    uint32_t fat_need;        /* +0x28: sectors per FAT those clusters need */
} fat_fmt_geom_t;

/* the card context (sd_card_identify 0x2013DFF0 clears +0x2C0..+0x2C6) */
typedef struct
{
    uint8_t drive;            /* +0: the drive index sd_card_task_start gets (sd_drive_attach) */
    uint8_t sector[512];      /* +1: the sector buffer of the mount and format code */
    uint8_t csd[16];          /* +0x201: CSD register, copied from the R2 response by CMD9 */
    uint8_t cid[16];          /* +0x211: CID register, from CMD2 / CMD10 */
    uint8_t scr[8];           /* +0x221: SCR register (ACMD51) */
    uint8_t sd_status[64];    /* +0x229: SD status (ACMD13) */
    uint8_t switch_status[64]; /* +0x269: the CMD6 status block, most significant byte first */
    uint8_t _r1;
    uint16_t rca;             /* +0x2AA: relative card address (argument bits 31..16) */
    uint16_t bus_width;       /* +0x2AC: ACMD6 argument, 2 = 4 bits (sd_scr_bus_width); CMD0 clears it */
    uint16_t _r2;
    union
    {
        uint32_t r1;          /* +0x2B0: short response */
        uint8_t r2[16];       /* +0x2B0: long response, RSP07 low byte first .. RSP00 (15 bytes; CMD2/9/10 copy 16) */
    } rsp;
    uint16_t flags;           /* +0x2C0: bit 0 standard capacity, bit 1 block addressing (CCS), bit 2 1.8 V
                               * accepted (S18A) [fact: sd_card_identify, sd_init_v2]; sdhi_read_op compares
                               * the whole halfword with 2 */
    uint16_t speed;           /* +0x2C2: the access mode the CMD6 switch selected (1..4); 2 and 3 make the
                               * transfers ask slot 16 first [fact: sd_read_sectors] */
    int16_t clock;            /* +0x2C4: the mode for the clock slot 0: 0 identification, 1 default, 2 high
                               * speed, -1 MMC [fact: sd_card_clock, the callers] */
    uint16_t card_type;       /* +0x2C6: 1 = MMC (docs/code/display/filesystem.md) */
    fat_fmt_geom_t fmt;       /* +0x2C8: the format parameters */
    uint32_t progress;        /* +0x2F4: format sectors still to write */
    uint32_t progress_total;  /* +0x2F8 */
} sd_card_t;

/* the SDHI operation table 0x20420564, 26 slots (drivers/sdhi.c lists the functions) [fact: the offsets of the
 * calls in drivers/sd_card.c] */
typedef struct
{
    int (*set_clock)(int mode);                                   /* 0: sdhi_wait_idle, the clock by mode */
    void (*clock_stop)(void);                                     /* 1: SD_CLK_CTRL = 0x200 */
    int (*check_card)(void);                                      /* 2: 0 while a card is in */
    int (*check_wp)(void);                                        /* 3: -7 when write protected */
    int (*op4)(void);                                             /* 4: -9 (the voltage switch's level) */
    int (*op5)(void);                                             /* 5: -10 */
    int (*op6)(int a);                                            /* 6: 4 (driver strength) */
    int (*op7)(int a);                                            /* 7: 5 (UHS support) */
    int (*soft_reset)(int a);                                     /* 8: sdhi_soft_reset (the callers pass 2) */
    int (*power_on)(void);                                        /* 9: sdhi_power_on */
    void (*op10)(void);                                           /* 10 */
    void (*set_bus_width)(int mode);                              /* 11: 2 = 4 bits */
    void (*op12)(int a);                                          /* 12: empty (high-speed timing) */
    void (*op13)(int a);                                          /* 13: empty */
    void (*op14)(void);                                           /* 14: empty (1.8 V signalling) */
    void (*op15)(int a);                                          /* 15: empty (UHS timing) */
    int (*op16)(void);                                            /* 16: -9 (tuning) */
    int (*wait_info)(int what);                                   /* 17: sdhi_wait_info */
    int (*cmd)(int cmd, int app, uint32_t arg, sd_card_t *c);     /* 18: sdhi_cmd */
    void (*read_response)(int type, sd_card_t *c);                /* 19: sdhi_read_response */
    int (*set_blocklen)(uint32_t len, uint32_t blocks, sd_card_t *c);   /* 20: sd_cmd16_set_blocklen */
    int (*stop)(sd_card_t *c);                                    /* 21: sd_cmd12_stop */
    int (*read)(uint32_t addr, uint8_t *buf, uint32_t n, sd_card_t *c); /* 22: sdhi_read_op */
    int (*read_buf)(uint8_t *buf, uint32_t len);                  /* 23: sdhi_read_buf_pio */
    int (*write)(uint32_t addr, const uint8_t *buf, uint32_t n, sd_card_t *c); /* 24: sdhi_write_op */
    int (*open)(void);                                            /* 25: sdhi_open */
} sd_ops_t;

/* the driver's handle: the card context and the target's operation table [fact: sd_cmd0_go_idle 0x2013C96C loads
 * +0 and +4] */
typedef struct
{
    sd_card_t *card;
    const sd_ops_t *ops;
} sd_handle_t;

/* the file system's drive record: include/fs.h (round 9; round 8 had the fields the SD drive code uses here) */

/* three tries of one command; 0 when one of them answered, else -9 [fact: the shape of every caller in
 * drivers/sd_card.c and drivers/sd_setup.c] */
static inline int sd_cmd_retry(const sd_handle_t *h, int cmd, uint32_t arg)
{
    for (int i = 0; i < 3; i++)
    {
        if (h->ops->cmd(cmd, 0, arg, h->card) == 0)
        {
            return 0;
        }
    }
    return -9;
}

int sd_cmd0_go_idle(const sd_handle_t *h);                       /* 0x2013C960 */
int sd_cmd2_all_send_cid(const sd_handle_t *h);                  /* 0x2013CEE8 */
int sd_cmd9_send_csd(const sd_handle_t *h);                      /* 0x2013D0BC */
int sd_cmd10_send_cid(const sd_handle_t *h);                     /* 0x2013D238 */
int sd_cmd13_send_status(uint32_t *status, const sd_handle_t *h);   /* 0x2013D398 */
int sd_csd_check(const uint8_t *csd);                            /* 0x2013D158 */
int mmc_csd_check(const uint8_t *csd);                           /* 0x2013D1C8 */
void sd_delay_ms(int ms);                                        /* 0x2013FD3C: itron_dly_tsk(ms / 10) */

#endif
