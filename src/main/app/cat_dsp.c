/* The CAT commands of the MAIN image that work on the DSP settings of a VFO record's per-mode block (T24 round 4;
 * docs/code/main/cat.md, radio-control.md "Per-mode block layout"): CO (CONTOUR / APF). */
#include "cat_util.h"
#include "cat_cmds.h"

/* blocks that have the APF flag (CO P2 = 2): CW, RTTY, DATA/PSK. In the others cat_CO points its APF pointer at a
 * local set to 0xFF (0xFFFA86B2; the pointers 0xFFFA890C, 0xFFFA8965, 0xFFFA897A) and refuses when the byte reads
 * 0xFF (0xFFFA8A81), so a real flags byte of 0xFF is refused too [fact] */
static int apf_flags_ok(uint8_t blk, const struct mode_blk *b)
{
    return (blk == 1 || blk == 2 || blk == 3) && b->flags != 0xFFu;
}

/* cat_CO 0xFFFA8698: CO P1 P2 P3..P6 on VFO 0's mode block; P1 is not checked. P2 = 0 CONTOUR on/off (flags bit 6),
 * 1 CONTOUR frequency 10..3200 Hz (stored / 10), 2 APF on/off (flags bit 5), 3 APF frequency -250..+250 Hz as
 * 00..50 (g_opstate.apf_freq = n - 25); a read answers 9 bytes */
void cat_CO(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t bi = mode_blk_index(vfo_mode(0));
    struct mode_blk *b = &r->blk[bi];
    uint16_t v;
    uint8_t n;

    if (!set) {
        switch (text[3]) {
        case '0':
            cat_reply[3] = '0';
            cat_reply[4] = '0';
            cat_reply[5] = '0';
            cat_reply[6] = '0';
            cat_reply[7] = (b->flags & 0x40u) ? '1' : '0';
            break;
        case '1':                               /* four digits of the value x 10 (16 bits), the last one '0' */
            cat_reply[3] = '1';
            put_dec16(&cat_reply[4], (uint16_t)(be16(b->contour_be) * 10u), 1000);
            cat_reply[7] = '0';
            break;
        case '2':
            cat_reply[3] = '2';
            cat_reply[4] = '0';
            cat_reply[5] = '0';
            cat_reply[6] = '0';
            cat_reply[7] = (b->flags & 0x20u) ? '1' : '0';
            break;
        case '3':
            cat_reply[3] = '3';
            cat_reply[4] = '0';
            cat_reply[5] = '0';
            put_dec(&cat_reply[6], (uint8_t)(g_opstate.apf_freq + 25u), 10);
            break;
        default:                                /* only the ';' [fact: 0xFFFA88C6] */
            break;
        }
        reply_done(8);
        return;
    }
    switch (text[3]) {
    case '0':
        if (text[7] == '0')
            b->flags &= (uint8_t)~0x40u;
        else if (text[7] == '1')
            b->flags |= 0x40u;
        else
            cat_error = 1;
        return;
    case '1':
        if (!get_dec16(&text[4], 4, 1000, &v))
            return;
        if (v < 10u || v > 3200u) {
            cat_error = 1;
            return;
        }
        put_be16(b->contour_be, (uint16_t)(v / 10u));
        g_ui.freq_refresh_req = 1;
        return;
    case '2':
        if (!apf_flags_ok(bi, b)) {
            cat_error = 1;
            return;
        }
        if (text[7] == '0')
            b->flags &= (uint8_t)~0x20u;
        else if (text[7] == '1')
            b->flags |= 0x20u;
        else
            cat_error = 1;
        return;
    case '3':
        if (text[4] != '0' || text[5] != '0') {
            cat_error = 1;
            return;
        }
        if (!get_dec(&text[6], 2, 10, &n))
            return;
        if (n > 50u) {
            cat_error = 1;
            return;
        }
        g_opstate.apf_freq = (uint8_t)(n - 25u);
        g_ui.freq_refresh_req = 1;
        return;
    default:
        cat_error = 1;
        return;
    }
}

uint8_t width_index_of_hz(uint8_t mode, uint16_t hz);   /* the WIDTH table index of hz for the mode */
uint16_t width_hz_of_index(uint8_t mode, uint8_t idx);  /* the width in Hz, 0xFFFF for an index out of the table */
void func_display_open(void);

/* the WIDTH of the mode's filter block (SSB 1..23, CW / RTTY / DATA / PSK 1..21; 0 = the default width, read as an
 * index above the range) or a fixed answer for AM 2, AM-N 1, FM / DATA-FM 3, FM-N / DATA-FM-N 2 [fact: the switch
 * of cat_SH 0xFFFAE2CA] */
static uint8_t sh_read_index(const struct vfo_rec *r, uint8_t m)
{
    const struct mode_blk *b;
    uint8_t idx, max = 21;

    switch (m) {
    case MODE_LSB: case MODE_USB:
        b = &r->blk[0];
        max = 23;
        break;
    case MODE_CW_L: case MODE_CW_U:
        b = &r->blk[1];
        break;
    case MODE_DATA_L: case MODE_DATA_U: case MODE_PSK:
        b = &r->blk[3];
        break;
    case MODE_RTTY_L: case MODE_RTTY_U:
        b = &r->blk[2];
        break;
    case MODE_AM: case MODE_FM_N: case MODE_DATA_FM_N:
        return 2;
    case MODE_AM_N:
        return 1;
    case MODE_FM: case MODE_DATA_FM:
        return 3;
    default:
        /* mode code 15: the image has no case and prints an uninitialised stack byte [fact: no store to the local
         * on that path, 0xFFFAE2CA]; 0 here, which is what the check's zeroed stack gives the original */
        return 0;
    }
    idx = (uint8_t)(width_index_of_hz(m, be16(b->width_be)) + 1u);
    return idx > max ? 0 : idx;
}

/* cat_SH 0xFFFAE2CA: SH0 P2 P3P4 = WIDTH of VFO 0's mode as a table index (00 = the default: 3000 Hz in SSB, 500
 * in CW and RTTY, 3200 in DATA/PSK); P2 must be 0. A set opens the WIDTH function display (knob item 0x1E). */
void cat_SH(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    struct mode_blk *b;
    uint16_t hz, dflt;
    uint8_t idx, max;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (!set) {
        put_dec(&cat_reply[4], sh_read_index(r, m), 10);
        cat_reply[2] = '0';
        cat_reply[3] = '0';
        reply_done(6);
        return;
    }
    if (text[3] != '0') {
        cat_error = 1;
        return;
    }
    if (!get_dec(&text[4], 2, 10, &idx))
        return;
    if (m == MODE_CW_L || m == MODE_CW_U) {
        b = &r->blk[1];
        dflt = 500;
        max = 21;
    } else if (m == MODE_DATA_L || m == MODE_DATA_U || m == MODE_PSK) {
        b = &r->blk[3];
        dflt = 3200;
        max = 21;
    } else if (m == MODE_RTTY_L || m == MODE_RTTY_U) {
        b = &r->blk[2];
        dflt = 500;
        max = 21;
    } else if (m == MODE_LSB || m == MODE_USB) {
        b = &r->blk[0];
        dflt = 3000;
        max = 23;
    } else {
        cat_error = 1;
        return;
    }
    if (idx == 0) {
        hz = dflt;
    } else if (idx > max) {
        cat_error = 1;
        return;
    } else {
        hz = width_hz_of_index(m, (uint8_t)(idx - 1u));
    }
    if (hz == 0xFFFFu) {
        cat_error = 1;
        return;
    }
    put_be16(b->width_be, hz);
    g_ui.func_knob_item = 0x1E;
    g_ui.dsp_knob_func = 1;
    func_display_open();
    g_ui.freq_refresh_req = 1;
    vfo_mark_edited(g_opstate.active_vfo);
    vfo_store_back(g_opstate.active_vfo);
}

/* cat_GT 0xFFFA9F23: GT0 P2 = AGC of VFO 0's mode block (flags2 bit 6 on, bits 4..5 speed): 0 OFF, 1 FAST, 2 MID,
 * 3 SLOW, 4 AUTO (a set stores AUTO as on with speed 0). A read of AUTO answers what AUTO means in the mode: 4 in CW
 * and FM, 5 in RTTY and DATA/PSK, 6 in SSB and AM (dsp_set_agc: FAST, MID, SLOW) [fact: 0xFFFA9F23..0xFFFAA12F] */
void cat_GT(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    uint8_t bi = mode_blk_index(m);
    uint8_t *f2 = &r->blk[bi].flags2;
    uint8_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (!set) {
        if (m > MODE_PSK) {
            v = 0;          /* mode code 15: the image prints an uninitialised stack byte (as cat_SH) */
        } else if ((*f2 & 0x40u) == 0) {
            v = 0;
        } else {
            v = (uint8_t)((*f2 & 0x30u) >> 4);
            if (v == 0)
                v = (bi == 1 || bi == 5) ? 4 : (bi == 2 || bi == 3) ? 5 : 6;
        }
        cat_reply[3] = (uint8_t)nib2hex(v);
        reply_done(4);
        return;
    }
    v = (uint8_t)hex2nib(text[3]);
    if (v > 4u) {
        cat_error = 1;
        return;
    }
    *f2 &= 0x8Fu;
    if (v == 4u)
        *f2 |= 0x40u;
    else if (v != 0)
        *f2 |= (uint8_t)(0x40u | v << 4);
    g_ui.freq_refresh_req = 1;
    vfo_mark_edited(g_opstate.active_vfo);
    vfo_store_back(g_opstate.active_vfo);
}

/* cat_BP 0xFFFA7A71: BP0 P2 P3..P5 = manual NOTCH of VFO 0's mode block: P2 = 0 on/off (flags bit 7; P3 P4 must be
 * "00", else the command is ignored without an error [fact: 0xFFFA7CA2..0xFFFA7CAC]), 1 the frequency 001..320 (x 10 Hz). A
 * set marks the active VFO edited and stores it back. */
void cat_BP(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    struct mode_blk *b;
    uint16_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    b = &r->blk[mode_blk_index(m)];
    if (!set) {
        if (text[3] == '0') {
            cat_reply[4] = '0';
            cat_reply[5] = '0';
            cat_reply[6] = (b->flags & 0x80u) ? '1' : '0';
        } else {
            put_dec16(&cat_reply[4], be16(b->notch_be), 100);
        }
        reply_done(7);
        return;
    }
    if (text[3] == '0') {
        if (text[4] != '0' || text[5] != '0')
            return;
        if (text[6] == '0') {
            b->flags &= (uint8_t)~0x80u;
        } else if (text[6] == '1') {
            b->flags |= 0x80u;
        } else {
            cat_error = 1;
            return;
        }
    } else if (text[3] == '1') {
        if (!get_dec16(&text[4], 3, 100, &v))
            return;
        if (v == 0 || v > 320u) {
            cat_error = 1;
            return;
        }
        put_be16(b->notch_be, v);
    } else {
        cat_error = 1;
        return;
    }
    g_ui.freq_refresh_req = 1;
    vfo_mark_edited(g_opstate.active_vfo);
    vfo_store_back(g_opstate.active_vfo);
}
