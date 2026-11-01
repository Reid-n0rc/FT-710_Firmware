/*
 * FT-710 DISPLAY (T24 round 8): the SD card layer's set-up, 0x2013C928..0x2013E43B: the clock, the
 * initialisation (version 2, version 1 or MMC, the 1.8 V switch), the RCA, the CID check, the selection (CMD7,
 * the transfer state), the ACMDs (SCR, bus width, SD status), CMD6 and the speed switch (high speed, driver
 * strength, the UHS access modes), the identification, and the sector and partition access. Recreated from the
 * image's disassembly; Ghidra's C was the map.
 *
 * Like drivers/sd_card.c, this layer reaches the SDHI target only through the operation table of the handle
 * (include/sd.h). docs/code/display/filesystem.md "SD card protocol layer" describes the sequence.
 */
#include "sd.h"

extern const uint32_t sd_r1_err_cmd7[];          /* 0x20420224: R1 error bits per card type that CMD7 tests */

#define SD_R1_ERRORS 0x0FF98008U                 /* the R1 error bits the ACMDs test [fact: 0x2013D63C literal] */
#define SD_OCR_BUSY 0x80000000U                  /* OCR bit 31: power-up done */
#define SD_OCR_CCS 0x40000000U                   /* OCR bit 30: card capacity status */
#define SD_OCR_S18A 0x01000000U                  /* OCR bit 24: 1.8 V accepted */
#define SD_OCR_VOLTAGES 0x00FF8000U              /* OCR bits 23..15: 2.7..3.6 V */
#define SD_STATE(r1) ((r1) & 0x1E00U)            /* R1 CURRENT_STATE, bits 12..9 */
#define SD_STATE_STBY 0x0600U
#define SD_STATE_TRAN 0x0800U
#define SD_STATE_DATA 0x0A00U
#define SD_STATE_RCV 0x0C00U

/* 0x2013C928: (on, handle): on = 1 runs the clock in the context's mode (slot 0, its result), else stops it
 * (slot 1, 0) [fact] */
int sd_card_clock(int on, const sd_handle_t *h)
{
    if (on == 1)
    {
        return h->ops->set_clock(h->card->clock);
    }
    h->ops->clock_stop();
    return 0;
}

/* 0x2013C9D0: no CMD8 answer: a version 1 card (ACMD41 without HCS), or an MMC (CMD1) when CMD55 is not
 * answered. The ACMD41 inquiry (argument 0) gets three tries; then up to 1000 ACMD41 with its voltages, 1 ms
 * apart, until the busy bit is set (-1 otherwise). The MMC path: CMD1 0xFF8000 until busy (-9 when it is not
 * answered), then clock mode -1 and card type 1 [fact] */
int sd_init_v1_or_mmc(const sd_handle_t *h)
{
    for (int tries = 0; tries < 3; tries++)
    {
        uint32_t volt;

        if (h->ops->cmd(55, 0, 0, h->card) != 0)
        {
            for (uint32_t i = 0; i < 1000; i++)
            {
                if (h->ops->cmd(1, 0, SD_OCR_VOLTAGES, h->card) != 0)
                {
                    return -9;
                }
                h->ops->read_response(3, h->card);
                if (h->card->rsp.r1 & SD_OCR_BUSY)
                {
                    h->card->clock = -1;
                    h->card->card_type = 1;
                    return 0;
                }
                sd_delay_ms(1);
            }
            return -1;
        }
        h->ops->read_response(1, h->card);
        if (h->ops->cmd(41, 1, 0, h->card) != 0)
        {
            continue;
        }
        h->ops->read_response(3, h->card);
        volt = h->card->rsp.r1 & SD_OCR_VOLTAGES;
        if (volt == 0)
        {
            continue;
        }
        for (uint32_t i = 0; i < 1000; i++)
        {
            if (h->ops->cmd(55, 0, 0, h->card) == 0)
            {
                h->ops->read_response(1, h->card);
                if (h->ops->cmd(41, 1, volt, h->card) == 0)
                {
                    h->ops->read_response(3, h->card);
                    if (h->card->rsp.r1 & SD_OCR_BUSY)
                    {
                        return 0;
                    }
                }
            }
            sd_delay_ms(1);
        }
        return -1;
    }
    return -1;
}

/* 0x2013CBB8: CMD8 0x1AA answered with its echo (-9 otherwise); a CMD5 answer means SDIO (-5); the ACMD41
 * inquiry gets three tries, then up to 1000 ACMD41 with HCS and S18R (0x41000000) and the voltages, 1 ms apart,
 * each after the card check (its error), until busy is set. Returns 1 for a standard-capacity card, else 0, and
 * records S18A in flags bit 2 when slot 7 (0) agrees [fact] */
int sd_init_v2(const sd_handle_t *h)
{
    if (h->ops->cmd(8, 0, 0x1AA, h->card) != 0)
    {
        return -9;
    }
    h->ops->read_response(7, h->card);
    if (h->card->rsp.r1 != 0x1AA)
    {
        return -9;
    }
    if (h->ops->cmd(5, 0, 0, h->card) == 0)
    {
        return -5;
    }
    for (int tries = 0; tries < 3; tries++)
    {
        uint32_t volt;

        if (h->ops->cmd(55, 0, 0, h->card) != 0)
        {
            continue;
        }
        h->ops->read_response(1, h->card);
        if (h->ops->cmd(41, 1, 0, h->card) != 0)
        {
            continue;
        }
        h->ops->read_response(3, h->card);
        volt = h->card->rsp.r1 & SD_OCR_VOLTAGES;
        if (volt == 0)
        {
            continue;
        }
        for (uint32_t i = 0; i < 1000; i++)
        {
            int r = h->ops->check_card();

            if (r != 0)
            {
                return r;
            }
            if (h->ops->cmd(55, 0, 0, h->card) == 0)
            {
                h->ops->read_response(1, h->card);
                if (h->ops->cmd(41, 1, volt | 0x41000000U, h->card) == 0)
                {
                    h->ops->read_response(3, h->card);
                    if (h->card->rsp.r1 & SD_OCR_BUSY)
                    {
                        int refused;

                        if (!(h->card->rsp.r1 & SD_OCR_CCS))
                        {
                            return 1;
                        }
                        refused = h->ops->op7(0);
                        if ((h->card->rsp.r1 & SD_OCR_S18A) && refused == 0)
                        {
                            h->card->flags |= 4;
                        }
                        return 0;
                    }
                }
            }
            sd_delay_ms(1);
        }
        return -1;
    }
    return -1;
}

/* 0x2013CDE8: CMD11 (voltage switch to 1.8 V), three tries (-9); R1 error bits 0x2C80008 give -23; clock off, the
 * host's level (slot 4 must give 2, and 3 after the switch; -9 otherwise), slot 14, 10 ms, slot 5 (its error),
 * clock on, 1 ms. With this host's slot 4 (-9) it always ends in -9 [fact] */
int sd_cmd11_voltage_switch(const sd_handle_t *h)
{
    int r;

    if (sd_cmd_retry(h, 11, 0) != 0)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    if (h->card->rsp.r1 & 0x02C80008U)
    {
        return -23;
    }
    r = sd_card_clock(0, h);
    if (r != 0)
    {
        return r;
    }
    if (h->ops->op4() != 2)
    {
        return -9;
    }
    h->ops->op14();
    sd_delay_ms(10);
    r = h->ops->op5();
    if (r != 0)
    {
        return r;
    }
    r = sd_card_clock(1, h);
    if (r != 0)
    {
        return r;
    }
    sd_delay_ms(1);
    return h->ops->op4() != 3 ? -9 : 0;
}

/* 0x2013CF80 (no Ghidra entry: the tail call of sd_card_identify): CMD3. An SD card publishes its RCA in R6 (bits
 * 31..16; -8 for an error bit of 0xE000); an MMC is given RCA 1, and its R1 error bits 0xD80000 give -23 unless
 * they are bit 22 alone in state 2 (ident); -9 when CMD3 is not answered [fact] */
int sd_cmd3_relative_addr(const sd_handle_t *h)
{
    uint32_t r;

    if (h->card->card_type == 1)
    {
        if (sd_cmd_retry(h, 3, 0x10000) != 0)
        {
            return -9;
        }
        h->ops->read_response(1, h->card);
        h->card->rca = 1;
        r = h->card->rsp.r1;
        if ((r & 0xD80000U) == 0 || ((r & 0xD80000U) == 0x400000U && SD_STATE(r) == 0x400U))
        {
            return 0;
        }
        return -23;
    }
    if (sd_cmd_retry(h, 3, 0) != 0)
    {
        return -9;
    }
    h->ops->read_response(6, h->card);
    h->card->rca = (uint16_t)(h->card->rsp.r1 >> 16);
    return (h->card->rsp.r1 & 0xE000U) ? -8 : 0;
}

/* 0x2013D2D4 (no Ghidra entry: the tail call of sd_read_csd_cid): a CID the driver accepts: bytes 0..2
 * (manufacturer, OEM) not all zero and bytes 3..14 not all zero; -5 otherwise [fact] */
int sd_cid_check(const uint8_t *cid)
{
    if (cid[0] == 0 && cid[1] == 0 && cid[2] == 0)
    {
        return -5;
    }
    for (int k = 3; k < 15; k++)
    {
        if (cid[k] != 0)
        {
            return 0;
        }
    }
    return -5;
}

/* 0x2013D434: (RCA, handle): CMD7, three tries (-9); RCA 0 deselects (no response read), else R1 against the mask
 * table 0x20420224 by card type (-23) [fact] */
int sd_cmd7_select(uint32_t rca, const sd_handle_t *h)
{
    if (rca == 0)
    {
        return sd_cmd_retry(h, 7, 0);
    }
    if (sd_cmd_retry(h, 7, rca << 16) != 0)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    return (h->card->rsp.r1 & sd_r1_err_cmd7[h->card->card_type]) ? -23 : 0;
}

/* 0x2013D4FC: bring the card into the transfer state: CMD13 (its error); tran: 0; data: deselect (CMD7 0), then
 * select; stby: select with the RCA (its result); rcv: stop (slot 21), then CMD13 until tran with the card check
 * between (their errors), at most 0x20000 times (-1); another state: -9 [fact] */
int sd_select_card(const sd_handle_t *h)
{
    uint32_t st;
    int r = sd_cmd13_send_status(&st, h);

    if (r != 0)
    {
        return r;
    }
    switch (SD_STATE(st))
    {
    case SD_STATE_TRAN:
        return 0;
    case SD_STATE_DATA:
        r = sd_cmd7_select(0, h);
        if (r != 0)
        {
            return r;
        }
        return sd_cmd7_select(h->card->rca, h);
    case SD_STATE_STBY:
        return sd_cmd7_select(h->card->rca, h);
    case SD_STATE_RCV:
        break;
    default:
        return -9;
    }
    r = h->ops->stop(h->card);
    if (r != 0)
    {
        return r;
    }
    for (uint32_t i = 0; i < 0x20000; i++)
    {
        r = sd_cmd13_send_status(&st, h);
        if (r != 0)
        {
            return r;
        }
        if (SD_STATE(st) == SD_STATE_TRAN)
        {
            return 0;
        }
        r = h->ops->check_card();
        if (r != 0)
        {
            return r;
        }
    }
    return -1;
}

/* CMD55 with the RCA, then the application command `cmd` (argument 0); three tries of the pair (-9); an R1 error
 * bit after either gives -23 [fact: the common part of 0x2013D5F4 and 0x2013D818] */
static inline int sd_app_cmd(const sd_handle_t *h, int cmd)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (h->ops->cmd(55, 0, (uint32_t)h->card->rca << 16, h->card) != 0)
        {
            continue;
        }
        h->ops->read_response(1, h->card);
        if (h->card->rsp.r1 & SD_R1_ERRORS)
        {
            return -23;
        }
        if (h->ops->cmd(cmd, 1, 0, h->card) == 0)
        {
            break;
        }
    }
    if (i >= 3)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    return (h->card->rsp.r1 & SD_R1_ERRORS) ? -23 : 0;
}

/* the data phase of a read command: buffer read ready (slot 17, 4), the PIO copy (slot 23), the access end
 * (slot 17, 2), each error returned [fact: 0x2013D6FC..0x2013D740, the same in 0x2013D920 and 0x2013DA24] */
static inline int sd_read_data(const sd_handle_t *h, uint8_t *dst, uint32_t len)
{
    int r = h->ops->wait_info(4);

    if (r != 0)
    {
        return r;
    }
    r = h->ops->read_buf(dst, len);
    if (r != 0)
    {
        return r;
    }
    return h->ops->wait_info(2);
}

/* 0x2013D5F4: ACMD51 (SEND_SCR): select, block length 8, the 8-byte SCR into +0x221 [fact] */
int sd_acmd51_read_scr(const sd_handle_t *h)
{
    uint8_t *scr = h->card->scr;
    int r = sd_select_card(h);

    if (r != 0)
    {
        return r;
    }
    r = h->ops->set_blocklen(8, 1, h->card);
    if (r != 0)
    {
        return r;
    }
    r = sd_app_cmd(h, 51);
    if (r != 0)
    {
        return r;
    }
    return sd_read_data(h, scr, 8);
}

/* 0x2013D744: ACMD6 (SET_BUS_WIDTH) with the width code +0x2AC: three tries of CMD55 + ACMD6 (-9), an R1 error bit
 * after CMD55 gives -23; then the host's bus width (slot 11), 0. The response to ACMD6 is read, not tested [fact] */
int sd_acmd6_set_bus_width(const sd_handle_t *h)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (h->ops->cmd(55, 0, (uint32_t)h->card->rca << 16, h->card) != 0)
        {
            continue;
        }
        h->ops->read_response(1, h->card);
        if (h->card->rsp.r1 & SD_R1_ERRORS)
        {
            return -23;
        }
        if (h->ops->cmd(6, 1, h->card->bus_width, h->card) == 0)
        {
            break;
        }
    }
    if (i >= 3)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    h->ops->set_bus_width(h->card->bus_width);
    return 0;
}

/* 0x2013D818: ACMD13 (SD_STATUS): select, block length 64, the 64 bytes into +0x229 [fact] */
int sd_acmd13_read_status(const sd_handle_t *h)
{
    uint8_t *st = h->card->sd_status;
    int r = sd_select_card(h);

    if (r != 0)
    {
        return r;
    }
    r = h->ops->set_blocklen(0x40, 1, h->card);
    if (r != 0)
    {
        return r;
    }
    r = sd_app_cmd(h, 13);
    if (r != 0)
    {
        return r;
    }
    return sd_read_data(h, st, 0x40);
}

/* 0x2013D968: (argument, handle): CMD6 (SWITCH_FUNC): select, block length 64, three tries (-9), R1 error bits
 * 0x82F80008 (-23), the 64-byte status into +0x269 [fact] */
int sd_cmd6_switch_func(uint32_t arg, const sd_handle_t *h)
{
    uint8_t *st = h->card->switch_status;
    int r = sd_select_card(h);

    if (r != 0)
    {
        return r;
    }
    r = h->ops->set_blocklen(0x40, 1, h->card);
    if (r != 0)
    {
        return r;
    }
    if (sd_cmd_retry(h, 6, arg) != 0)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    if (h->card->rsp.r1 & 0x82F80008U)
    {
        return -23;
    }
    return sd_read_data(h, st, 0x40);
}

/* the CMD6 status block (SD physical layer specification, "switch function status"), byte 0 the most
 * significant [fact: the offsets +0x269.. the functions below load] */
#define SW_MAX_CURRENT(s) ((uint32_t)(s)[0] << 8 | (s)[1])   /* mA */
#define SW_GROUP3_SUPPORT(s) ((s)[9])        /* driver strength */
#define SW_GROUP1_SUPPORT(s) ((s)[13])       /* access mode: bit 1 high speed, 2 SDR50, 3 SDR104, 4 DDR50 */
#define SW_GROUP4_SEL(s) ((s)[15] >> 4)      /* current limit */
#define SW_GROUP3_SEL(s) ((s)[15] & 0xF)     /* driver strength */
#define SW_GROUP1_SEL(s) ((s)[16] & 0xF)     /* 0xF: the function cannot be switched */
#define SW_VERSION(s) ((s)[17])              /* 1: the busy bytes are valid */
#define SW_GROUP4_BUSY(s) ((s)[23])
#define SW_GROUP3_BUSY(s) ((s)[25])
#define SW_GROUP1_BUSY(s) ((s)[29])
#define SW_MAX_MA 800                        /* 0x320 [fact: the cmp of all three switches] */

/* 0x2013DA6C (no Ghidra entry: tail-called by sd_select_bus_speed): high speed. CMD6 mode-0 inquiry; when group 1
 * offers function 1, up to 0x20000 rounds: inquiry 0x00FFFFF1 (0 when it needs more than 800 mA or cannot be
 * switched; again while busy), switch 0x80FFFFF1; switched: slot 12 (1), clock mode 2, 0; else the card check (its
 * error). -1 after the rounds [fact] */
int sd_switch_high_speed(const sd_handle_t *h)
{
    const uint32_t ask = 0x00FFFFF1U;
    int r = sd_cmd6_switch_func(0x00FFFFFFU, h);

    if (r != 0 || !(SW_GROUP1_SUPPORT(h->card->switch_status) & 2))
    {
        return r;
    }
    for (uint32_t i = 0; i < 0x20000; i++)
    {
        const uint8_t *s;

        r = sd_cmd6_switch_func(ask, h);
        if (r != 0)
        {
            return r;
        }
        s = h->card->switch_status;
        if (SW_MAX_CURRENT(s) > SW_MAX_MA)
        {
            return 0;
        }
        if (SW_VERSION(s) == 1 && (SW_GROUP1_BUSY(s) & 2))
        {
            continue;
        }
        if (SW_GROUP1_SEL(s) == 0xF)
        {
            return 0;
        }
        r = sd_cmd6_switch_func(ask | 0x80000000U, h);
        if (r != 0)
        {
            return r;
        }
        if (SW_GROUP1_SEL(h->card->switch_status) == 1)
        {
            h->ops->op12(1);
            h->card->clock = 2;
            return 0;
        }
        r = h->ops->check_card();
        if (r != 0)
        {
            return r;
        }
    }
    return -1;
}

/* 0x2013DB74 (no Ghidra entry: tail-called by sd_select_bus_speed): the fastest access mode a 1.8 V card offers,
 * with the current limit 0xFF3 nibbles of the argument. Slot 15 (0); CMD6 inquiry; the first function from group
 * 1's support: SDR104 (3), DDR50 (4), SDR50 (2), high speed (1, argument 0xFFFFF1), else 0. Up to 0x20000 rounds:
 * card check (its error), inquiry of the function; more than 800 mA or slot 7 refusing it steps down (high speed:
 * 0; SDR104 to DDR50 when offered; DDR50 to SDR50; else one function down); busy (group 1, or group 4 when not high
 * speed): again; not switchable: 0; switch with bit 31; switched to the function (and the current limit): slot 15
 * (function), speed and clock mode by function, 0. -1 after the rounds [fact] */
int sd_switch_uhs_speed(const sd_handle_t *h)
{
    const uint32_t high_speed = 0x00FFFFF1U;
    uint32_t arg, bit;
    uint8_t sup;
    int r;

    h->ops->op15(0);
    r = sd_cmd6_switch_func(0x00FFFFFFU, h);
    if (r != 0)
    {
        return r;
    }
    sup = SW_GROUP1_SUPPORT(h->card->switch_status);
    if (sup & 8)
    {
        bit = 8, arg = 0x00FF3FF3U;
    }
    else if (sup & 0x10)
    {
        bit = 0x10, arg = 0x00FF3FF4U;
    }
    else if (sup & 4)
    {
        bit = 4, arg = 0x00FF3FF2U;
    }
    else if (sup & 2)
    {
        bit = 2, arg = high_speed;
    }
    else
    {
        return 0;
    }
    for (uint32_t i = 0; i < 0x20000; i++)
    {
        const uint32_t fn = arg & 0xF;
        const uint8_t *s;
        int refused;

        r = h->ops->check_card();
        if (r != 0)
        {
            return r;
        }
        r = sd_cmd6_switch_func(arg, h);
        if (r != 0)
        {
            return r;
        }
        refused = h->ops->op7((int)fn);
        s = h->card->switch_status;
        if (SW_MAX_CURRENT(s) > SW_MAX_MA || refused != 0)
        {
            if (fn == 1)
            {
                return 0;
            }
            if (fn == 3 && (SW_GROUP1_SUPPORT(s) & 0x10))
            {
                bit = (bit << 25) >> 24;      /* SDR104 -> DDR50: the image's lsl #25, lsr #24 */
                arg += 1;
            }
            else if (fn == 4)
            {
                bit >>= 2;
                arg -= 2;
            }
            else
            {
                bit >>= 1;
                arg -= 1;
            }
            continue;
        }
        if (SW_VERSION(s) == 1 && (SW_GROUP1_BUSY(s) & bit))
        {
            continue;
        }
        if (arg != high_speed && SW_VERSION(s) == 1 && (SW_GROUP4_BUSY(s) & 8))
        {
            continue;
        }
        if (SW_GROUP1_SEL(s) == 0xF || SW_GROUP4_SEL(s) == 0xF)
        {
            return 0;
        }
        r = sd_cmd6_switch_func(arg | 0x80000000U, h);
        if (r != 0)
        {
            return r;
        }
        s = h->card->switch_status;
        if (SW_GROUP1_SEL(s) != fn)
        {
            continue;
        }
        if (arg != high_speed && ((arg >> 12) & 0xF) != SW_GROUP4_SEL(s))
        {
            continue;
        }
        switch (SW_GROUP1_SEL(s))
        {
        case 1:
            h->ops->op15(1);
            h->card->speed = 1;
            h->card->clock = 2;
            return 0;
        case 2:
            h->ops->op15(2);
            h->card->speed = 2;
            h->card->clock = 3;
            return 0;
        case 3:
            h->ops->op15(3);
            h->card->speed = 3;
            h->card->clock = 4;
            return 0;
        case 4:
            h->ops->op15(4);
            h->card->speed = 4;
            h->card->clock = 2;
            return 0;
        default:
            break;
        }
    }
    return -1;
}

/* 0x2013DE60 (Ghidra: sd_switch_status_check): driver strength type B (group 3 function 0) for a 1.8 V card.
 * Slot 13 (0); CMD6 inquiry; nothing to do (0) unless group 3 offers type B and slot 6 (0) agrees (this host's
 * slot 6 gives 4, so it returns 0 there). Up to 0x20000 rounds: card check, inquiry 0x00FFF0FF (0 above 800 mA;
 * again while busy; 0 when it cannot be switched), switch 0x80FFF0FF; switched: slot 13 (0), 0. -1 after the
 * rounds [fact] */
int sd_set_driver_strength(const sd_handle_t *h)
{
    const uint32_t ask = 0x00FFF0FFU;
    int r;

    h->ops->op13(0);
    r = sd_cmd6_switch_func(0x00FFFFFFU, h);
    if (r != 0 || !(SW_GROUP3_SUPPORT(h->card->switch_status) & 1))
    {
        return r;
    }
    if (h->ops->op6(0) != 0)
    {
        return 0;
    }
    for (uint32_t i = 0; i < 0x20000; i++)
    {
        const uint8_t *s;

        r = h->ops->check_card();
        if (r != 0)
        {
            return r;
        }
        r = sd_cmd6_switch_func(ask, h);
        if (r != 0)
        {
            return r;
        }
        s = h->card->switch_status;
        if (SW_MAX_CURRENT(s) > SW_MAX_MA)
        {
            return 0;
        }
        if (SW_VERSION(s) == 1 && (SW_GROUP3_BUSY(s) & 1))
        {
            continue;
        }
        if (SW_GROUP3_SEL(s) == 0xF)
        {
            return 0;
        }
        r = sd_cmd6_switch_func(ask | 0x80000000U, h);
        if (r != 0)
        {
            return r;
        }
        if (SW_GROUP3_SEL(h->card->switch_status) == ((ask >> 8) & 0xF))
        {
            h->ops->op13(0);
            return 0;
        }
    }
    return -1;
}

/* 0x2013DF88: the bus speed after identification: clock mode 1 (default speed); for an SCR spec of 1.10 or later
 * (SD_SPEC != 0) with CSD command class 10 (switch): a 1.8 V card sets the driver strength and then the UHS mode,
 * any other the high speed; 0 otherwise [fact] */
int sd_select_bus_speed(const sd_handle_t *h)
{
    sd_card_t *c = h->card;

    c->clock = 1;
    if (!(c->scr[0] & 0xF) || !(c->csd[4] & 0x40))
    {
        return 0;
    }
    if (c->flags & 4)
    {
        int r = sd_set_driver_strength(h);

        if (r != 0)
        {
            return r;
        }
        return sd_switch_uhs_speed(h);
    }
    return sd_switch_high_speed(h);
}

/* 0x2013DFF0: identify the card after the card check (its error): flags, speed, clock mode and card type cleared,
 * slot 12 (0), the identification clock, 1 ms, CMD0; then CMD8 / ACMD41 (sd_init_v2): a high-capacity card sets
 * flags bit 1 (and switches to 1.8 V when bit 2 is set), a standard-capacity one bit 0; no CMD8 answer (-9):
 * bit 0 and the version 1 / MMC path; then CMD2 and CMD3. Any other error is returned [fact] */
int sd_card_identify(const sd_handle_t *h)
{
    int r = h->ops->check_card();

    if (r != 0)
    {
        return r;
    }
    h->card->flags = 0;
    h->card->speed = 0;
    h->card->clock = 0;
    h->card->card_type = 0;
    h->ops->op12(0);
    r = sd_card_clock(1, h);
    if (r != 0)
    {
        return r;
    }
    sd_delay_ms(1);
    r = sd_cmd0_go_idle(h);
    if (r != 0)
    {
        return r;
    }
    r = sd_init_v2(h);
    if (r == 0)
    {
        h->card->flags |= 2;
        if (h->card->flags & 4)
        {
            r = sd_cmd11_voltage_switch(h);
            if (r != 0)
            {
                return r;
            }
        }
    }
    else if (r == 1)
    {
        h->card->flags |= 1;
    }
    else if (r == -9)
    {
        h->card->flags |= 1;
        r = sd_init_v1_or_mmc(h);
        if (r != 0)
        {
            return r;
        }
    }
    else
    {
        return r;
    }
    r = sd_cmd2_all_send_cid(h);
    if (r != 0)
    {
        return r;
    }
    return sd_cmd3_relative_addr(h);
}

/* 0x2013E124: CMD9 and the CSD check for the card type, CMD10 and the CID check [fact] */
int sd_read_csd_cid(const sd_handle_t *h)
{
    int r = sd_cmd9_send_csd(h);

    if (r != 0)
    {
        return r;
    }
    r = h->card->card_type == 1 ? mmc_csd_check(h->card->csd) : sd_csd_check(h->card->csd);
    if (r != 0)
    {
        return r;
    }
    r = sd_cmd10_send_cid(h);
    if (r != 0)
    {
        return r;
    }
    return sd_cid_check(h->card->cid);
}

/* 0x2013E190: (RCA, length, blocks, handle): select the card, set the block length (slot 20), deselect [fact] */
int sd_selected_op(uint32_t rca, uint32_t len, uint32_t blocks, const sd_handle_t *h)
{
    int r = sd_cmd7_select(rca, h);

    if (r != 0)
    {
        return r;
    }
    r = h->ops->set_blocklen(len, blocks, h->card);
    if (r != 0)
    {
        return r;
    }
    return sd_cmd7_select(0, h);
}

/* 0x2013E1E4: read the SCR and take the bus width: 2 (4 bits) when SD_BUS_WIDTHS (SCR byte 1 bit 2) offers it,
 * else 0 [fact] */
int sd_scr_bus_width(const sd_handle_t *h)
{
    int r = sd_acmd51_read_scr(h);

    if (r != 0)
    {
        return r;
    }
    h->card->bus_width = (h->card->scr[1] & 4) ? 2 : 0;
    return 0;
}

/* 0x2013E230: (sector, buffer, count, handle): the card address (bytes unless flags bit 1), select, slot 16 for the
 * speeds 2 and 3 (its error), then the read (slot 22) [fact] */
int sd_read_sectors(uint32_t sector, uint8_t *buf, uint32_t n, const sd_handle_t *h)
{
    uint32_t addr = (h->card->flags & 2) ? sector : sector << 9;
    int r = sd_select_card(h);

    if (r != 0)
    {
        return r;
    }
    if (h->card->speed == 2 || h->card->speed == 3)
    {
        r = h->ops->op16();
        if (r != 0)
        {
            return r;
        }
    }
    return h->ops->read(addr, buf, n, h->card);
}

/* 0x2013E2B4: the same for a write (slot 24), after the write-protect check (slot 3: -7) [fact] */
int sd_write_sectors(uint32_t sector, const uint8_t *buf, uint32_t n, const sd_handle_t *h)
{
    uint32_t addr = sector;
    int r;

    if (h->ops->check_wp() != 0)
    {
        return -7;
    }
    if (!(h->card->flags & 2))
    {
        addr = sector << 9;
    }
    r = sd_select_card(h);
    if (r != 0)
    {
        return r;
    }
    if (h->card->speed == 2 || h->card->speed == 3)
    {
        r = h->ops->op16();
        if (r != 0)
        {
            return r;
        }
    }
    return h->ops->write(addr, buf, n, h->card);
}

/* 0x2013E350 (no Ghidra entry; driver op 9): the card check (slot 2) of the handle [fact] */
int sd_check_card(const sd_handle_t *h)
{
    return h->ops->check_card();
}

/* 0x2013E35C: (volume, sector, buffer, count, handle): a sector of the partition: -2 past its end, else up to
 * three reads at its first sector + sector, each after the card check (its error ends the tries) [fact] */
int sd_vol_read(const fs_drive_t *v, uint32_t sector, uint8_t *buf, uint32_t n, const sd_handle_t *h)
{
    int r = -2;

    if (sector >= v->sectors)
    {
        return -2;
    }
    for (int i = 0; i < 3; i++)
    {
        r = h->ops->check_card();
        if (r != 0)
        {
            break;
        }
        r = sd_read_sectors(v->first + sector, buf, n, h);
        if (r == 0)
        {
            break;
        }
    }
    return r;
}

/* 0x2013E3CC: the same for a write, one try [fact] */
int sd_vol_write(const fs_drive_t *v, uint32_t sector, const uint8_t *buf, uint32_t n, const sd_handle_t *h)
{
    int r;

    if (sector >= v->sectors)
    {
        return -2;
    }
    r = h->ops->check_card();
    if (r != 0)
    {
        return r;
    }
    return sd_write_sectors(v->first + sector, buf, n, h);
}
