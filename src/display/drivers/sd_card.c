/*
 * FT-710 DISPLAY (T24 round 7): the SD card layer's single commands and CSD checks, 0x2013C960..0x2013D437 and
 * 0x2013F15C..0x2013F20F (part), recreated from the image.
 *
 * The card layer reaches the SDHI target only through the operation table of the handle (include/sd.h; the
 * table is 0x20420564, drivers/sdhi.c): slot 18 sends a command and waits for its response, slot 19 copies the
 * response into the card context. Each command is tried three times; -9 when all fail [fact: the loops below].
 * docs/code/display/filesystem.md describes the card initialisation these belong to.
 */
#include "sd.h"

extern const uint32_t sd_r1_err_cmd13[];   /* 0x2042022C: R1 error bits per card type that CMD13 tests */

/* 0x2013C960: CMD0 (go idle) after clearing the bus width +0x2AC and setting the 1-bit bus (slot 11 with 0) [fact] */
int sd_cmd0_go_idle(const sd_handle_t *h)
{
    h->card->bus_width = 0;
    h->ops->set_bus_width(0);
    return sd_cmd_retry(h, 0, 0);
}

/* 0x2013CEE8: CMD2 (all send CID): the R2 response into the CID copy +0x211 [fact] */
int sd_cmd2_all_send_cid(const sd_handle_t *h)
{
    if (sd_cmd_retry(h, 2, 0) != 0)
    {
        return -9;
    }
    h->ops->read_response(2, h->card);
    for (uint8_t k = 0; k < 16; k++)
    {
        h->card->cid[k] = h->card->rsp.r2[k];
    }
    return 0;
}

/* 0x2013D0BC / 0x2013D238: CMD9 (send CSD) / CMD10 (send CID) to the card's RCA: the R2 response into +0x201 /
 * +0x211 [fact] */
int sd_cmd9_send_csd(const sd_handle_t *h)
{
    if (sd_cmd_retry(h, 9, (uint32_t)h->card->rca << 16) != 0)
    {
        return -9;
    }
    h->ops->read_response(2, h->card);
    for (int k = 0; k < 16; k++)
    {
        h->card->csd[k] = h->card->rsp.r2[k];
    }
    return 0;
}

int sd_cmd10_send_cid(const sd_handle_t *h)
{
    if (sd_cmd_retry(h, 10, (uint32_t)h->card->rca << 16) != 0)
    {
        return -9;
    }
    h->ops->read_response(2, h->card);
    for (int k = 0; k < 16; k++)
    {
        h->card->cid[k] = h->card->rsp.r2[k];
    }
    return 0;
}

/* 0x2013D398: (status out, handle): CMD13 (send status): -23 when R1 has an error bit for the card type, else the
 * status word out and 0 [fact] */
int sd_cmd13_send_status(uint32_t *status, const sd_handle_t *h)
{
    uint32_t r1;

    if (sd_cmd_retry(h, 13, (uint32_t)h->card->rca << 16) != 0)
    {
        return -9;
    }
    h->ops->read_response(1, h->card);
    r1 = h->card->rsp.r1;
    if (r1 & sd_r1_err_cmd13[h->card->card_type])
    {
        return -23;
    }
    *status = r1;
    return 0;
}

/* 0x2013D158: (CSD bytes, most significant first): an SD CSD the driver accepts: CSD_STRUCTURE 0/1, the reserved
 * bits 125..122 below 3, bit 119 and bit 103 clear, READ_BL_LEN at most 11, FILE_FORMAT below 2; -5 otherwise
 * [fact] */
int sd_csd_check(const uint8_t *csd)
{
    if ((csd[0] >> 6) < 2 && ((csd[0] & 0x3F) >> 2) < 3 && !(csd[1] & 0x80) && !(csd[3] & 0x80) &&
        (csd[5] & 0xF) < 12 && (csd[14] & 3) < 2)
    {
        return 0;
    }
    return -5;
}

/* 0x2013D1C8: the same for an MMC CSD: structure below 4, SPEC_VERS below 5, also WRITE_BL_LEN (byte 12) [fact] */
int mmc_csd_check(const uint8_t *csd)
{
    if ((csd[0] >> 6) < 4 && ((csd[0] & 0x3F) >> 2) < 5 && !(csd[1] & 0x80) && !(csd[3] & 0x80) &&
        (csd[5] & 0xF) < 12 && ((csd[12] & 0x1F) >> 2) < 8 && (csd[14] & 3) < 2)
    {
        return 0;
    }
    return -5;
}

/* 0x2013F15C: READ_BL_LEN as bytes: 10 -> 1024, 11 -> 2048, else 512 [fact] */
uint32_t csd_read_bl_len(const uint8_t *csd)
{
    switch (csd[5] & 0xF)
    {
    case 10: return 0x400;
    case 11: return 0x800;
    default: return 0x200;
    }
}

/* 0x2013F180: C_SIZE (CSD version 1, bits 73..62) [fact] */
uint32_t csd_c_size(const uint8_t *csd)
{
    return (((uint32_t)(csd[6] & 3) << 8 | csd[7]) << 8 | (csd[8] & 0xC0)) >> 6;
}

/* 0x2013F1A4: C_SIZE_MULT (bits 49..47) as the multiplier 4 << mult (the image tests 0..6 and returns 512 for 7)
 * [fact] */
uint32_t csd_c_size_mult(const uint8_t *csd)
{
    uint32_t mult = ((uint32_t)(csd[9] & 3) << 8 | (csd[10] & 0x80)) >> 7;

    return 4U << mult;
}
