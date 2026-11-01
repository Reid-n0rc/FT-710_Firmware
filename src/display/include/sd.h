/*
 * FT-710 DISPLAY (T24 round 7): the SD card driver's card context and handle, as far as the recreated functions use
 * them (drivers/sdhi.c, drivers/sd_card.c). The layout is the image's [fact: the offsets each function loads, cited
 * there]; what the other bytes hold is not established.
 */
#ifndef SD_H
#define SD_H

#include <stdint.h>

typedef struct
{
    uint8_t _r0[0x201];
    uint8_t csd[16];          /* +0x201: CSD register, copied from the R2 response by CMD9 */
    uint8_t cid[16];          /* +0x211: CID register, from CMD2 / CMD10 */
    uint8_t _r1[0x2AA - 0x221];
    uint16_t rca;             /* +0x2AA: relative card address (argument bits 31..16) */
    uint16_t state_2ac;       /* +0x2AC: cleared by CMD0 */
    uint16_t _r2;
    union
    {
        uint32_t r1;          /* +0x2B0: short response */
        uint8_t r2[16];       /* +0x2B0: long response, RSP07 low byte first .. RSP00 (15 bytes; CMD2/9/10 copy 16) */
    } rsp;
    uint16_t addr_mode;       /* +0x2C0: 2 = block addressing (next block addr + 1), else bytes (+ 0x200) */
    uint16_t _r3[2];
    uint16_t card_type;       /* +0x2C6: 1 = MMC (docs/code/display/filesystem.md) */
} sd_card_t;

/* the SDHI operation table 0x20420564, the slots the card layer calls [fact: drivers/sdhi.c, the offsets of the
 * calls: +0x2C slot 11, +0x48 slot 18, +0x4C slot 19] */
typedef struct
{
    void (*op0_10[11])(void);
    void (*set_bus_width)(int mode);                              /* slot 11: sdhi_set_bus_width, 2 = 4 bits */
    void (*op12_17[6])(void);
    int (*cmd)(int cmd, int app, uint32_t arg, sd_card_t *c);     /* slot 18: sdhi_cmd */
    void (*read_response)(int type, sd_card_t *c);                /* slot 19: sdhi_read_response */
} sd_ops_t;

/* the driver's handle: the card context and the target's operation table [fact: sd_cmd0_go_idle 0x2013C96C loads
 * +0 and +4] */
typedef struct
{
    sd_card_t *card;
    const sd_ops_t *ops;
} sd_handle_t;

#endif
