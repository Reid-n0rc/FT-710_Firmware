/* CAT auto information (AI), recreated for T24 round 6 (docs/code/main/cat.md "Auto information", cat-ai.md).
 *
 * cat_ai_poll runs at the end of every cat_parse. While a port has AI on and no port is sending, it asks the change
 * detectors in a fixed order for a changed item; the first one that finds a change formats its CAT answer into
 * cat_ai_buf (0x15E06) and returns the length, and the frame goes to every port with AI on [fact: cat_ai_poll
 * 0xFFFDD797]. Each detector keeps the last reported value in a shadow (ai_sh 0x187C3 and the variables in
 * main_ram.h) and builds the frame from a template in a local buffer first; only a change copies it out.
 *
 * Not recreated (they read an uninitialised stack word, so no C source can do the same): cat_ai_MG 0xFFFDFAE4 and
 * cat_ai_MX 0xFFFDFDA4 return their uninitialised length variable when nothing changed [fact: MG 0xFFFDFB85
 * `mov.w 4[r0], 2[r0]` with 4[r0] written only on a change; MX 0xFFFDFDEE `mov.w 2[r0], [r0]`]. */
#include "cat_util.h"
#include "fpu_conv.h"

_Static_assert(sizeof(struct ai_shadow) == 0x45, "ai_sh covers 0x187C3..0x18807");

uint8_t vfo_tuner_bit_get(void);                /* bit 2 of the TX VFO record's flags1 */
uint8_t max4_u8(const uint8_t *p);
uint8_t min4_u8(const uint8_t *p);
uint8_t band_of_freq(uint32_t hz);
uint8_t tx_band_of_freq(uint32_t hz);            /* TX band 0..10 of a frequency */
uint32_t bandmem_get(uint8_t which);
uint8_t msg_rec_play_state(void);               /* 1 while a message / voice recording runs */
uint8_t width_index_of_hz(uint8_t mode, uint16_t hz);
uint8_t meter_get_vdd(void);
uint8_t meter_get_idd(void);
uint8_t meter_get_alc(void);
uint8_t meter_get_swr(void);
uint8_t meter_get_po(void);
uint8_t meter_get_comp(void);
uint16_t cat_ai_MG(void);
uint16_t cat_ai_MX(void);
uint16_t cat_ai_ex(void);
uint16_t cat_ai_SS(uint8_t item);              /* the scope items SS0..SS8 (not recreated) */

#define AI_HOLD_TIMER 0x32

/* the frame out: n bytes to cat_ai_buf; returns n */
static inline uint16_t ai_send(const uint8_t *f, uint16_t n)
{
    uint16_t i;

    for (i = 0; i < n; i++)
        cat_ai_buf[i] = f[i];
    return n;
}

static inline void ai_template(uint8_t *f, const char *t, unsigned n)
{
    unsigned i;

    for (i = 0; i < n; i++)
        f[i] = (uint8_t)t[i];
}

/* a one-digit item "XX" + nib2hex(v) + ";" against its shadow */
static inline uint16_t ai_digit(char a, char b, uint8_t *shadow, uint8_t v)
{
    uint8_t f[4];

    if (*shadow == v)
        return 0;
    *shadow = v;
    f[0] = (uint8_t)a;
    f[1] = (uint8_t)b;
    f[2] = (uint8_t)nib2hex(v);
    f[3] = ';';
    return ai_send(f, 4);
}

/* the jitter filter of AG, RG, RM and SQ: the new value goes into a 4-entry history; the report is dropped while
 * the history alternates (entries 0 and 2 or 1 and 3 equal; RM and SQ: both pairs) [fact: cat_ai_AG 0xFFFDDF0A,
 * cat_ai_RM 0xFFFE09D7] */
static inline void ai_hist_push(uint8_t *idx, uint8_t *hist, uint8_t v)
{
    *idx = (uint8_t)(*idx + 1u);
    if (*idx > 3u)
        *idx = 0;
    hist[*idx] = v;
}

/* AG and RG: away from the ends (3..252) a change is reported only when it is not alternating and the last four
 * values spread by 3 or more */
static inline int ai_knob_steady(uint8_t *idx, uint8_t *hist, uint8_t v)
{
    ai_hist_push(idx, hist, v);
    if (v < 3u || v > 252u)
        return 1;
    if (hist[0] == hist[2] || hist[1] == hist[3])
        return 0;
    return (int)max4_u8(hist) - (int)min4_u8(hist) >= 3;
}

/* the per-mode block of VFO 0's record for its mode (cat_util.h mode_blk_index) */
static inline const struct mode_blk *ai_rx_blk(uint8_t *mode)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);

    *mode = vfo_mode(0);
    return &r->blk[mode_blk_index(*mode)];
}

/* cat_ai_FD 0xFFFDDB7E: FD0 P1 + 9 digits: the frequency the scope shows (TX frequency while the TX lamp is on,
 * else the dial (P1 0), the CURSOR start (1) or the FIX band memory (2)) */
uint16_t cat_ai_FD(void)
{
    uint8_t f[16];
    uint32_t hz;

    (void)band_of_freq(vfo_freq(0, 2));         /* computed and not used [fact: 0xFFFDDB8F] */
    ai_template(f, "FD000000000000;", 16);
    if (g_ui.tx_lamp == 1) {
        hz = g_ui.freq_tx;
    } else if (g_opstate.scope_mode == 0) {
        hz = g_ui.freq_dial;
        f[4] = '0';
    } else if (g_opstate.scope_mode == 1) {
        hz = g_ui.scope_cursor_start;
        f[4] = '1';
    } else {
        hz = bandmem_get(2);
        f[4] = '2';
    }
    if (ai_fd_freq == hz && g_opstate.scope_mode == ai_fd_scope_mode)
        return 0;
    ai_fd_freq = hz;
    ai_fd_scope_mode = g_opstate.scope_mode;
    put_dec32(&f[5], hz, 100000000u);
    f[14] = ';';
    return ai_send(f, 15);
}

/* cat_ai_AC 0xFFFDDCB5: AC0 P2 P3: the tuner; any change of its inputs rebuilds the frame, which is sent when it
 * differs from the last one sent */
uint16_t cat_ai_AC(void)
{
    uint8_t type = g_opstate.ex030104_tuner_type_select;
    uint8_t c3d = g_ui.tune_cycle_3d, c3c = g_ui.tune_cycle_3c, cyc = g_ui.tune_cycle;
    uint8_t f[7];
    unsigned i;

    f[6] = g_ui.tuner_result;
    f[0] = 'A';
    f[1] = 'C';
    f[2] = '0';
    f[4] = '0';
    f[5] = ';';
    if (ai_sh.ac_tuner_type == type && ai_sh.ac_cycle_3d == c3d && ai_sh.ac_cycle_3c == c3c &&
        ai_sh.ac_cycle == cyc && ai_sh.ac_result == g_ui.tuner_result && ai_sh.ac_atu == g_ui.atu_state)
        return 0;
    ai_sh.ac_tuner_type = type;
    ai_sh.ac_cycle_3d = c3d;
    ai_sh.ac_cycle_3c = c3c;
    ai_sh.ac_cycle = cyc;
    ai_sh.ac_result = g_ui.tuner_result;
    ai_sh.ac_atu = g_ui.atu_state;
    if (type == 3) {                            /* TUNER TYPE SELECT 3 */
        f[3] = '2';
        if (cyc == 1)
            f[4] = '3';
        else if (cyc == 2)
            f[4] = g_ui.tuner_result == 2 ? '1' : g_ui.tuner_result == 3 ? '2' : '0';
        else
            f[4] = '0';
    } else {
        f[3] = '0';
        if (c3d == 2 || c3c == 2)
            f[4] = '3';
        else
            f[4] = vfo_tuner_bit_get() == 1 ? '1' : '0';
    }
    if (strncmp((const char *)ai_ac_last, (const char *)f, 6) == 0)
        return 0;
    ai_send(f, 6);
    for (i = 0; i < 6; i++)
        ai_ac_last[i] = f[i];
    return 6;
}

/* cat_ai_AG 0xFFFDDE79: AG0 + 3 digits, the AF gain (jitter filter) */
uint16_t cat_ai_AG(void)
{
    uint8_t v = g_ui.af_gain;
    uint8_t f[7];

    if (ai_sh.ag == v)
        return 0;
    ai_sh.ag = v;
    if (!ai_knob_steady(&ai_ag_idx, ai_ag_hist, v))
        return 0;
    ai_template(f, "AG0000;", 7);
    put_dec(&f[3], v, 100);
    return ai_send(f, 7);
}

/* cat_ai_AO 0xFFFDDFC3: AO + 3 digits, the AMC level */
uint16_t cat_ai_AO(void)
{
    uint8_t f[6];

    if (ai_sh.ao == g_opstate.amc_level)
        return 0;
    ai_sh.ao = g_opstate.amc_level;
    ai_template(f, "AO000;", 6);
    put_dec(&f[2], ai_sh.ao, 100);
    return ai_send(f, 6);
}

/* cat_ai_AS 0xFFFDE064: AS1 + the AESS level x 5 (which 1) or AS2 + 001 / 002 for the AESS mode 0 / 1 (which 2) */
uint16_t cat_ai_AS(uint8_t which)
{
    uint8_t f[7];
    uint8_t v;

    ai_template(f, "AS0000;", 7);
    if (which == 1) {
        v = *(const uint8_t *)aess_level_ptr();
        if (ai_sh.as_level == v)
            return 0;
        f[2] = '1';
        ai_sh.as_level = v;
        put_dec(&f[3], (uint8_t)(v * 5u), 100);
    } else if (which == 2) {
        v = *(const uint8_t *)aess_mode_ptr();
        if (ai_sh.as_mode == v)
            return 0;
        f[2] = '2';
        if (v == 0) {
            f[5] = '1';
        } else if (v == 1) {
            f[5] = '2';
        }
        ai_sh.as_mode = v;
    } else {
        return 0;
    }
    return ai_send(f, 7);
}

/* cat_ai_AV 0xFFFDE180: AV + 3 digits, the ANTI VOX level of the VOX source (EX030405 VOX SELECT) */
uint16_t cat_ai_AV(void)
{
    uint8_t sel = g_opstate.ex030405_vox_select;
    uint8_t v = sel == 0 ? g_opstate.antivox[0] : g_opstate.antivox[1];
    uint8_t f[6];

    if (ai_sh.av_select == sel && ai_sh.av_level == v)
        return 0;
    ai_sh.av_select = sel;
    ai_sh.av_level = v;
    ai_template(f, "AV000;", 6);
    put_dec(&f[2], v, 100);
    return ai_send(f, 6);
}

/* cat_ai_BC 0xFFFDE263: BC0 P2, the DNF bit (flags2 bit 7) of the RX mode's block; none in FM and DATA-FM */
uint16_t cat_ai_BC(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint8_t v;
    uint8_t f[5];

    if (mode_blk_index(m) == 5)
        return 0;
    v = b->flags2 & 0x80u;
    if (ai_sh.bc == v)
        return 0;
    ai_template(f, "BC00;", 5);
    if (v != 0)
        f[3] = '1';
    ai_sh.bc = v;
    return ai_send(f, 5);
}

/* cat_ai_BI 0xFFFDE332: BI P1, the BI bit (flags bit 1) of the RX mode's block; none in RTTY, DATA and PSK */
uint16_t cat_ai_BI(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint8_t bi = mode_blk_index(m);
    uint8_t v;
    uint8_t f[4];

    if (bi == 2 || bi == 3)
        return 0;
    v = b->flags & 0x02u;
    if (ai_sh.bi == v)
        return 0;
    f[0] = 'B';
    f[1] = 'I';
    f[2] = v != 0 ? '1' : '0';
    f[3] = ';';
    ai_sh.bi = v;
    return ai_send(f, 4);
}

/* cat_ai_BP 0xFFFDE3F1: BP00 + 00P3 (the manual notch on / off, flags bit 7) or BP01 + 3 digits (its frequency) */
uint16_t cat_ai_BP(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint8_t on = b->flags & 0x80u;
    uint16_t notch = be16(b->notch_be);
    uint8_t f[8];

    ai_template(f, "BP00000;", 8);
    if (ai_sh.bp_on == on) {
        if (ai_bp_notch == notch)
            return 0;
        f[2] = '0';
        f[3] = '1';
        ai_bp_notch = notch;
        put_dec16(&f[4], notch, 100);
    } else {
        f[2] = '0';
        ai_sh.bp_on = on;
        f[6] = on != 0 ? '1' : '0';
    }
    return ai_send(f, 8);
}

/* cat_ai_CF 0xFFFDE58A: CF P1 0 0 + the RX / TX clarifier on bits, or CF P1 0 1 + the offset (sign, 4 digits); side
 * 0 = the active VFO, any other = the other one */
uint16_t cat_ai_CF(uint8_t side)
{
    uint8_t s = side != 0;
    uint8_t other = (uint8_t)(s ^ (g_opstate.active_vfo != VFO_A));   /* 0 = VFO-A */
    const struct vfo_rec *r = other == 0 ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    uint8_t flags = other == 0 ? g_ui.clar_flags_a : g_ui.clar_flags_b;
    uint8_t rx = flags & 1u, tx = flags & 2u;
    uint16_t off = be16(r->clar_offset_be);
    uint8_t f[11];

    ai_template(f, "CF00000000;", 11);
    if (ai_sh.cf[s][0] != rx || ai_sh.cf[s][1] != tx) {
        ai_sh.cf[s][0] = rx;
        ai_sh.cf[s][1] = tx;
        f[2] = (uint8_t)('0' + s);
        f[4] = '0';
        if (rx != 0)
            f[5] = '1';
        if (tx != 0)
            f[6] = '1';
    } else if (ai_cf_offset[s] != off) {
        ai_cf_offset[s] = off;
        f[2] = (uint8_t)('0' + s);
        f[4] = '1';
        if (off & 0x8000u) {
            f[5] = '-';
            off = (uint16_t)(~off + 1u);
        } else {
            f[5] = '+';
        }
        put_dec16(&f[6], off, 1000);
    } else {
        return 0;
    }
    return ai_send(f, 11);
}

/* cat_ai_CN 0xFFFDE887: CN P1 0 + 3 digits, the tone number of VFO-A (P1 0) or VFO-B (1) */
uint16_t cat_ai_CN(void)
{
    uint8_t a = g_opstate.vfo_a.tone_num, b = g_opstate.vfo_b.tone_num;
    uint8_t f[8];

    ai_template(f, "CN00000;", 8);
    if (ai_sh.cn_a == a) {
        if (ai_sh.cn_b == b)
            return 0;
        ai_sh.cn_b = b;
        f[2] = '1';
        f[3] = '0';
        put_dec(&f[4], b, 100);
    } else {
        ai_sh.cn_a = a;
        f[2] = '0';
        f[3] = '0';
        put_dec(&f[4], a, 100);
    }
    return ai_send(f, 8);
}

/* cat_ai_CO 0xFFFDE9A8: CO0 P2 + 4 characters: CONTOUR on (P2 0), CONTOUR frequency (1), APF on (2), APF
 * frequency (3), first change first */
uint16_t cat_ai_CO(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint8_t flags = b->flags;
    uint16_t contour = be16(b->contour_be);
    uint8_t apf = (uint8_t)(g_opstate.apf_freq + 25);
    uint8_t f[9];

    ai_template(f, "CO000000;", 9);
    if (ai_sh.co_on != (flags & 0x40u)) {
        ai_sh.co_on = flags & 0x40u;
        f[3] = '0';
        if (flags & 0x40u)
            f[7] = '1';
    } else if (ai_co_contour != contour) {
        ai_co_contour = contour;
        f[3] = '1';
        put_dec16(&f[4], (uint16_t)(contour * 10u), 1000);
        f[7] = '0';                             /* the last digit is always written as 0 [fact: 0xFFFDEB5F] */
    } else if (ai_sh.co_apf_on != (flags & 0x20u)) {
        ai_sh.co_apf_on = flags & 0x20u;
        f[3] = '2';
        if (flags & 0x20u)
            f[7] = '1';
    } else if (ai_sh.co_apf != apf) {
        f[3] = '3';
        ai_sh.co_apf = apf;
        put_dec(&f[6], apf, 10);
    } else {
        return 0;
    }
    return ai_send(f, 9);
}

/* cat_ai_CS 0xFFFDEBD1: CS P1, CW SPOT */
uint16_t cat_ai_CS(void)
{
    return ai_digit('C', 'S', &ai_sh.cs, g_ui.cw_spot_on);
}

/* cat_ai_CT 0xFFFDEC32: CT0 P2, the tone mode (flags3 bits 3-5) of VFO-A, or of VFO-B when only that changed:
 * 0 -> '0', 1 -> '2', 2 -> '1', other values '0' */
uint16_t cat_ai_CT(void)
{
    uint8_t a = g_opstate.vfo_a.flags3 & 0x38u, b = g_opstate.vfo_b.flags3 & 0x38u;
    uint8_t v;
    uint8_t f[5];

    if (ai_sh.ct_a != a) {
        ai_sh.ct_a = a;
        v = a;
    } else if (ai_sh.ct_b != b) {
        ai_sh.ct_b = b;
        v = b;
    } else {
        return 0;
    }
    ai_template(f, "CT00;", 5);
    v >>= 3;
    if (v == 1)
        f[3] = '2';
    else if (v == 2)
        f[3] = '1';
    return ai_send(f, 5);
}

/* cat_ai_FA_FB 0xFFFDED19: FA or FB + 9 digits: VFO-A first, then VFO-B; while transmitting the active VFO reports
 * the TX frequency */
uint16_t cat_ai_FA_FB(void)
{
    uint32_t a = g_ui.freq_a, b = g_ui.freq_b, v;
    uint8_t f[12];

    if (g_ui.transmitting == 1) {
        if (g_opstate.active_vfo == VFO_A)
            a = g_ui.freq_tx;
        else
            b = g_ui.freq_tx;
    }
    ai_template(f, "FA000000000;", 12);
    if (ai_fa_freq == a) {
        if (ai_fb_freq == b)
            return 0;
        ai_fb_freq = b;
        f[1] = 'B';
        v = b;
    } else {
        ai_fa_freq = a;
        v = a;
    }
    put_dec32(&f[2], v, 100000000u);
    return ai_send(f, 12);
}

/* cat_ai_FN 0xFFFDEE2C: FN P1, the FINE / FAST selection */
uint16_t cat_ai_FN(void)
{
    return ai_digit('F', 'N', &ai_sh.fn, g_opstate.fn_select);
}

/* cat_ai_FT 0xFFFDEE96: FT P1, split: 0 -> '0', 1 and 2 -> '1', other values '0' */
uint16_t cat_ai_FT(void)
{
    uint8_t v = g_opstate.split_on;
    uint8_t f[4];

    if (ai_sh.ft == v)
        return 0;
    ai_sh.ft = v;
    f[0] = 'F';
    f[1] = 'T';
    f[2] = v == 1 || v == 2 ? '1' : '0';
    f[3] = ';';
    return ai_send(f, 4);
}

/* cat_ai_GT 0xFFFDEF13: GT0 P2, the AGC of the RX mode as cat_GT reads it (AUTO as 4, 5 or 6 by mode; 0 for the
 * mode code 15) */
uint16_t cat_ai_GT(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint8_t bi = mode_blk_index(m);
    uint8_t v = 0;
    uint8_t f[5];

    if (m <= MODE_PSK && (b->flags2 & 0x40u)) {
        v = (uint8_t)((b->flags2 & 0x30u) >> 4);
        if (v == 0)
            v = (bi == 1 || bi == 5) ? 4 : (bi == 2 || bi == 3) ? 5 : 6;
    }
    if (ai_sh.gt == v)
        return 0;
    ai_sh.gt = v;
    ai_template(f, "GT00;", 5);
    f[3] = (uint8_t)nib2hex(v);
    return ai_send(f, 5);
}

/* The AI file's own copies of cat_IF_OI's tables: the same bytes at 0xFFF87228 (mode characters), 0xFFF87237 (VFO
 * state characters) and 0xFFF87241 (channel names from 99 on) as at 0xFFF806D0.. [fact: cat_ai_IF_OI 0xFFFDF52E,
 * 0xFFFDF541, 0xFFFDF25E; cat_ai_MD 0xFFFDFAB8; the bytes compared], as CC-RX keeps a const table per file
 * [inference] */
extern const uint8_t ai_mode_codes[];
extern const uint8_t ai_vfo_state_codes[];
extern const uint8_t ai_pms_names[][3];

/* one field of IF / OI or RI against its shadow: any change marks the frame for sending */
static inline void ai_field(uint8_t *shadow, uint8_t v, uint16_t *len, uint16_t n)
{
    if (*shadow != v) {
        *shadow = v;
        *len = n;
    }
}

/* cat_ai_IF_OI 0xFFFDF13A: the 28-byte IF (side 0, VFO-A) or OI (side 1, VFO-B) answer as cat_IF_OI builds it,
 * when any of its fields changed: channel text, frequency, clarifier offset and bits, mode, VFO state, tone mode,
 * repeater shift */
uint16_t cat_ai_IF_OI(uint8_t side)
{
    const struct vfo_rec *r;
    struct ai_info_shadow *sh;
    uint8_t clar, state, ch, v;
    uint16_t len = 0, off;
    uint32_t hz;
    uint8_t f[28];
    uint8_t *text;
    unsigned i;

    ai_template(f, "IF0000000000000000000000000;", 28);
    if (side == 0) {
        r = &g_opstate.vfo_a;
        sh = &ai_if_a;
        clar = g_ui.clar_flags_a;
        state = g_opstate.vfo_state_a;
        ch = g_mem_hdr.chan_a;
        ai_if_chan_a = ch;                      /* written, never read [fact: no other access to 0x1B50B] */
    } else {
        r = &g_opstate.vfo_b;
        sh = &ai_if_b;
        f[0] = 'O';
        f[1] = 'I';
        clar = g_ui.clar_flags_b;
        state = g_opstate.vfo_state_b;
        ch = g_mem_hdr.chan_b;
        ai_if_chan_b = ch;                      /* [fact: no other access to 0x1B517] */
    }
    if (ch < 99u) {
        put_dec(&f[2], (uint8_t)(ch + 1u), 100);
    } else {
        f[4] = ai_pms_names[(uint8_t)(ch - 99u)][2];
        f[2] = ai_pms_names[(uint8_t)(ch - 99u)][0];
        f[3] = ai_pms_names[(uint8_t)(ch - 99u)][1];
    }
    if (state == VFO_STATE_VFO || state == VFO_STATE_MEMTUNE || state == VFO_STATE_QMB) {
        f[2] = '0';
        f[3] = '0';
        f[4] = '0';
    }
    text = ai_if_chan_text[side != 0];
    if (strncmp((const char *)text, (const char *)&f[2], 3) != 0) {
        for (i = 0; i < 3; i++)
            text[i] = f[2 + i];
        len = 28;
    }
    hz = vfo_freq(0, side);
    if (ai_if_freq[side != 0] != hz) {
        len = 28;
        ai_if_freq[side != 0] = hz;
    }
    put_dec32(&f[5], hz, 100000000u);
    off = be16(r->clar_offset_be);
    if (ai_if_offset[side != 0] != off) {
        len = 28;
        ai_if_offset[side != 0] = off;
    }
    put_clar_offset(&f[14], r);
    ai_field(&sh->clar, clar, &len, 28);
    if (clar == 1) {
        f[19] = '1';
    } else if (clar == 2) {
        f[20] = '1';
    } else if (clar == 3) {
        f[19] = '1';
        f[20] = '1';
    }
    v = r->mode & 0x0Fu;
    ai_field(&sh->mode, v, &len, 28);
    f[21] = ai_mode_codes[v];
    f[22] = ai_vfo_state_codes[state];
    ai_field(&sh->state, state, &len, 28);
    v = (uint8_t)((r->flags3 & 0x38u) >> 3);
    ai_field(&sh->tone, v, &len, 28);
    f[23] = v == 1 ? '2' : v == 2 ? '1' : '0';
    v = (uint8_t)((r->flags2 & 0x0Cu) >> 2);
    ai_field(&sh->shift, v, &len, 28);
    f[26] = v == 0 ? '2' : v == 2 ? '1' : '0';
    if (len != 0)
        ai_send(f, len);
    return len;
}

/* cat_ai_IS 0xFFFDF66F: IS00 + the IF shift of the RX mode's block (sign, 4 digits) */
uint16_t cat_ai_IS(void)
{
    uint8_t m;
    const struct mode_blk *b = ai_rx_blk(&m);
    uint16_t v = be16(b->shift_be);
    uint16_t len = 0;
    uint8_t f[10];

    ai_template(f, "IS0000000;", 10);
    if (ai_is_shift != v) {
        ai_is_shift = v;
        len = 10;
    }
    if (v & 0x8000u) {
        f[4] = '-';
        v = (uint16_t)(~v + 1u);
    } else {
        f[4] = '+';
    }
    put_dec16(&f[5], v, 1000);
    if (len != 0)
        ai_send(f, len);
    return len;
}

/* cat_ai_KP 0xFFFDF7B3: KP + 2 digits, the CW pitch */
uint16_t cat_ai_KP(void)
{
    uint8_t f[5];

    if (ai_sh.kp == g_opstate.cw_pitch)
        return 0;
    ai_sh.kp = g_opstate.cw_pitch;
    ai_template(f, "KP00;", 5);
    put_dec(&f[2], ai_sh.kp, 10);
    return ai_send(f, 5);
}

/* cat_ai_KR 0xFFFDF85C: KR P1, the keyer */
uint16_t cat_ai_KR(void)
{
    return ai_digit('K', 'R', &ai_sh.kr, g_opstate.keyer_on);
}

/* cat_ai_KS 0xFFFDF8D4: KS + 3 digits, the key speed */
uint16_t cat_ai_KS(void)
{
    uint8_t f[6];

    if (ai_sh.ks == g_opstate.key_speed)
        return 0;
    ai_sh.ks = g_opstate.key_speed;
    ai_template(f, "KS000;", 6);
    put_dec(&f[2], ai_sh.ks, 100);
    return ai_send(f, 6);
}

/* cat_ai_LK 0xFFFDF981: LK P1, the lock */
uint16_t cat_ai_LK(void)
{
    return ai_digit('L', 'K', &ai_sh.lk, g_opstate.lock_on);
}

/* cat_ai_MD 0xFFFDF9EC: MD P1 + the mode character, of the active VFO (which 0) or the other one (1) */
uint16_t cat_ai_MD(uint8_t which)
{
    uint8_t a_side = g_opstate.active_vfo == VFO_A;
    uint8_t v;
    uint8_t f[5];

    if (which == 0)
        v = (a_side ? g_opstate.vfo_a.mode : g_opstate.vfo_b.mode) & 0x0Fu;
    else if (which == 1)
        v = (a_side ? g_opstate.vfo_b.mode : g_opstate.vfo_a.mode) & 0x0Fu;
    else
        return 0;
    if (ai_sh.md[which] == v)
        return 0;
    ai_sh.md[which] = v;
    f[0] = 'M';
    f[1] = 'D';
    f[2] = (uint8_t)('0' + which);
    f[3] = ai_mode_codes[v];
    f[4] = ';';
    return ai_send(f, 5);
}

/* cat_ai_ML 0xFFFDFBE4: ML0 + 00P2 (the monitor on, level != 0) or ML1 + 3 digits (the level) of the RX mode's
 * class; the level is undefined for the mode code 15 (the image reads an uninitialised stack byte, here 0) */
uint16_t cat_ai_ML(void)
{
    uint8_t m = vfo_mode(0);
    uint8_t lvl = 0, on;
    uint8_t f[7];

    switch (m) {
    case MODE_LSB: case MODE_USB:
        lvl = g_opstate.monitor[0];
        break;
    case MODE_CW_L: case MODE_CW_U:
        lvl = g_opstate.monitor[1];
        break;
    case MODE_RTTY_L: case MODE_RTTY_U:
        lvl = g_opstate.monitor[2];
        break;
    case MODE_DATA_L: case MODE_DATA_U: case MODE_PSK:
        lvl = g_opstate.monitor[3];
        break;
    case MODE_AM: case MODE_AM_N:
        lvl = g_opstate.monitor[4];
        break;
    case MODE_FM: case MODE_FM_N: case MODE_DATA_FM: case MODE_DATA_FM_N:
        lvl = g_opstate.monitor_fm;
        break;
    default:
        break;
    }
    on = lvl != 0;
    f[0] = 'M';
    f[1] = 'L';
    ai_template(&f[3], "000;", 4);
    if (ai_sh.ml_on == on) {
        if (ai_sh.ml_level == lvl)
            return 0;
        ai_sh.ml_level = lvl;
        f[2] = '1';
        put_dec(&f[3], lvl, 100);
    } else {
        f[2] = '0';
        ai_sh.ml_on = on;
        f[5] = (uint8_t)nib2hex(on);
    }
    return ai_send(f, 7);
}

/* cat_ai_MS 0xFFFDFD36: MS P1 0, the meter selection */
uint16_t cat_ai_MS(void)
{
    uint8_t f[5];

    if (ai_sh.ms == g_opstate.meter_sel)
        return 0;
    ai_sh.ms = g_opstate.meter_sel;
    ai_template(f, "MS00;", 5);
    f[2] = (uint8_t)nib2hex(ai_sh.ms);
    return ai_send(f, 5);
}

/* a two-character parameter "XX0" + nib2hex(v) + ";" against its shadow (NA, NB, NR, RA) */
static inline uint16_t ai_digit2(char a, char b, uint8_t *shadow, uint8_t v)
{
    uint8_t f[5];

    if (*shadow == v)
        return 0;
    *shadow = v;
    f[0] = (uint8_t)a;
    f[1] = (uint8_t)b;
    f[2] = '0';
    f[3] = (uint8_t)nib2hex(v);
    f[4] = ';';
    return ai_send(f, 5);
}

/* cat_ai_NA 0xFFFDFE0A: NA0 P2, the narrow filter value FUN_fffdfe0a's caller keeps for AI */
uint16_t cat_ai_NA(void)
{
    return ai_digit2('N', 'A', &ai_na, g_opstate.na_ai_value);
}

/* cat_ai_NB 0xFFFDFE7A: NB0 P2, NB on (flags2 bit 1 of VFO 0's record) */
uint16_t cat_ai_NB(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);

    return ai_digit2('N', 'B', &ai_sh.nb, (uint8_t)((r->flags2 & 2u) >> 1));
}

/* cat_ai_NL 0xFFFDFEE6: NL00 + 2 digits, the NB level */
uint16_t cat_ai_NL(void)
{
    uint8_t f[7];

    if (ai_sh.nl == g_opstate.nb_level)
        return 0;
    ai_sh.nl = g_opstate.nb_level;
    ai_template(f, "NL0000;", 7);
    put_dec(&f[4], ai_sh.nl, 10);
    return ai_send(f, 7);
}

/* cat_ai_NR 0xFFFDFF9C: NR0 P2, DNR on (dnr bit 4 of VFO 0's record) */
uint16_t cat_ai_NR(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);

    return ai_digit2('N', 'R', &ai_sh.nr, (uint8_t)((r->dnr & 0x10u) >> 4));
}

/* a repeater shift (flags2 bits 2-3: 0 minus, 1 simplex, 2 plus) as the CAT digit: 0 -> '2', 2 -> '1', else '0' */
static inline uint8_t ai_shift_char(uint8_t v)
{
    return v == 0 ? '2' : v == 2 ? '1' : '0';
}

/* cat_ai_OS 0xFFFE0016: OS0 P2, the repeater shift of the active VFO */
uint16_t cat_ai_OS(void)
{
    const struct vfo_rec *r = g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    uint8_t v = (uint8_t)((r->flags2 & 0x0Cu) >> 2);
    uint8_t f[5];

    if (ai_sh.os == v)
        return 0;
    ai_sh.os = v;
    f[0] = 'O';
    f[1] = 'S';
    f[2] = '0';
    f[3] = ai_shift_char(v);
    f[4] = ';';
    return ai_send(f, 5);
}

/* cat_ai_PA 0xFFFE00BE: PA0 P2, the preamp of VFO 0's record (flags5 bits 0-1: 2 AMP1 -> '1', 3 AMP2 -> '2', else
 * '0') */
uint16_t cat_ai_PA(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t v = r->flags5 & 3u;
    uint8_t f[5];

    if (ai_sh.pa == v)
        return 0;
    f[0] = 'P';
    f[1] = 'A';
    f[2] = '0';
    f[3] = v == 2 ? '1' : v == 3 ? '2' : '0';
    f[4] = ';';
    ai_sh.pa = v;
    return ai_send(f, 5);
}

/* cat_ai_PC 0xFFFE0143: PC + 3 digits, the RF power of the TX frequency's group (AM, TX bands 9 and 10, others) */
uint16_t cat_ai_PC(void)
{
    uint32_t hz = vfo_freq(0, 2);
    uint8_t m = vfo_mode(0);
    uint8_t band = tx_band_of_freq(hz);
    uint8_t v;
    uint8_t f[6];

    if (m == MODE_AM || m == MODE_AM_N)
        v = g_opstate.rf_power[3];
    else if (band == 9)
        v = g_opstate.rf_power[1];
    else if (band == 10)
        v = g_opstate.rf_power[2];
    else
        v = g_opstate.rf_power[0];
    if (ai_sh.pc == v)
        return 0;
    ai_sh.pc = v;
    ai_template(f, "PC000;", 6);
    put_dec(&f[2], v, 100);
    return ai_send(f, 6);
}

/* cat_ai_PL 0xFFFE024B: PL + 3 digits, the processor level */
uint16_t cat_ai_PL(void)
{
    uint8_t f[6];

    if (ai_sh.pl == g_opstate.proc_level)
        return 0;
    ai_sh.pl = g_opstate.proc_level;
    ai_template(f, "PL000;", 6);
    put_dec(&f[2], ai_sh.pl, 100);
    return ai_send(f, 6);
}

/* cat_ai_PR 0xFFFE02F4: PR0 P2 (processor level != 0) and PR1 P2 (proc_on); when both changed, PR1 */
uint16_t cat_ai_PR(void)
{
    uint8_t lvl_on = g_opstate.proc_level != 0;
    uint16_t len = 0;
    uint8_t f[5];

    ai_template(f, "PR00;", 5);
    if (ai_sh.pr_level_on != lvl_on) {
        ai_sh.pr_level_on = lvl_on;
        f[2] = '0';
        f[3] = (uint8_t)nib2hex(lvl_on);
        len = 5;
    }
    if (ai_sh.pr_on != g_opstate.proc_on) {
        ai_sh.pr_on = g_opstate.proc_on;
        f[2] = '1';
        f[3] = (uint8_t)nib2hex(g_opstate.proc_on);
        len = 5;
    }
    if (len != 0)
        ai_send(f, len);
    return len;
}

/* cat_ai_RA 0xFFFE0394: RA0 P2, the attenuator (flags3 bits 0-1 of VFO 0's record) */
uint16_t cat_ai_RA(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);

    return ai_digit2('R', 'A', &ai_sh.ra, r->flags3 & 3u);
}

/* cat_ai_RG 0xFFFE040B: RG0 + 3 digits, the RF gain (jitter filter); none while RF/SQL VR (EX030102) is not 0 */
uint16_t cat_ai_RG(void)
{
    uint8_t v = g_ui.rf_gain;
    uint8_t f[7];

    if (g_opstate.ex030102_rf_sql_vr != 0 || ai_sh.rg == v)
        return 0;
    ai_sh.rg = v;
    if (!ai_knob_steady(&ai_rg_idx, ai_rg_hist, v))
        return 0;
    ai_template(f, "RG0000;", 7);
    put_dec(&f[3], ai_sh.rg, 100);
    return ai_send(f, 7);
}

/* cat_ai_RI 0xFFFE057B: RI0 + 7 digits: HI-SWR, recording, TX lamp, (0), tuning, scan (0 off, 1 running, 2 paused
 * with the AF on), and lamp bit 4. The frame goes to cat_ai_buf as soon as a field changed, and is reported only
 * when it differs from the last one reported [fact: 0xFFFE0718..0xFFFE0747] */
uint16_t cat_ai_RI(void)
{
    uint8_t f[11];
    uint16_t len = 0;
    uint8_t v;
    unsigned i;

    ai_template(f, "RI00000000;", 11);
    v = g_ui.hi_swr != 0;
    ai_field(&ai_ri_hi_swr, v, &len, 11);
    f[3] = (uint8_t)nib2hex(v);
    v = msg_rec_play_state();
    ai_field(&ai_ri_msg, v, &len, 11);
    f[4] = (uint8_t)nib2hex(v);
    ai_field(&ai_ri_tx, g_ui.tx_lamp, &len, 11);
    f[5] = (uint8_t)nib2hex(g_ui.tx_lamp);
    v = g_ui.tune_cycle_3c == 2 || g_ui.tune_cycle_3d == 2 || g_ui.tune_cycle != 0;
    ai_field(&ai_ri_tune, v, &len, 11);
    f[7] = (uint8_t)nib2hex(v);
    if (g_ui.scan_running == 0)
        v = '0';
    else if (g_ui.scan_hold == 1 && !af_mute_get())
        v = '2';
    else
        v = '1';
    ai_field(&ai_ri_scan, v, &len, 11);
    f[8] = v;
    ai_field(&ai_ri_lamp, g_ui.lamp_map & 0x10u, &len, 11);
    f[9] = (g_ui.lamp_map & 0x10u) ? '1' : '0';
    if (len == 0)
        return 0;
    ai_send(f, len);
    if (strncmp((const char *)ai_ri_last, (const char *)f, 11) == 0)
        return 0;
    for (i = 0; i < len; i++)
        ai_ri_last[i] = f[i];
    return len;
}

/* cat_ai_RL 0xFFFE0839: RL0 + 2 digits, the DNR level (dnr bits 0-3 of VFO 0's record) */
uint16_t cat_ai_RL(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t v = r->dnr & 0x0Fu;
    uint8_t f[6];

    if (ai_sh.rl == v)
        return 0;
    ai_sh.rl = v;
    ai_template(f, "RL000;", 6);
    f[3] = (uint8_t)nib2hex((uint8_t)(v / 10u));
    f[4] = (uint8_t)nib2hex((uint8_t)(v % 10u));
    return ai_send(f, 6);
}

/* cat_ai_RM 0xFFFE08C7: RM0 + 3 digits + 000: the meter that METER selects while the TX lamp is on (1 COMP, 2 ALC,
 * 3 VDD, 4 IDD, 5 SWR, else PO), the S meter in receive (jitter filter) */
uint16_t cat_ai_RM(void)
{
    uint8_t v;
    uint8_t f[10];

    if (g_ui.tx_lamp != 1)
        v = meter_get_s();
    else if (g_opstate.meter_sel == 1)
        v = meter_get_comp();
    else if (g_opstate.meter_sel == 2)
        v = meter_get_alc();
    else if (g_opstate.meter_sel == 3)
        v = meter_get_vdd();
    else if (g_opstate.meter_sel == 4)
        v = meter_get_idd();
    else if (g_opstate.meter_sel == 5)
        v = meter_get_swr();
    else
        v = meter_get_po();
    if (ai_sh.rm == v)
        return 0;
    ai_sh.rm = v;
    ai_hist_push(&ai_rm_idx, ai_rm_hist, v);
    if (ai_rm_hist[0] == ai_rm_hist[2] && ai_rm_hist[1] == ai_rm_hist[3])
        return 0;
    ai_template(f, "RM0000000;", 10);
    put_dec(&f[3], v, 100);
    return ai_send(f, 10);
}

/* cat_ai_SC 0xFFFE0A60: SC P1, the scan: 0 off, 1 up, 2 down (FUN_fffe5d0e = 1 while the scan runs downward
 * [inference: cat_SC's P1 2]) */
uint16_t cat_ai_SC(void)
{
    uint8_t running = g_ui.scan_running;
    uint8_t down;
    uint8_t f[4];

    (void)vfo_rec_ptr(0);                       /* called, result unused [fact: 0xFFFE0A62] */
    down = (uint8_t)FUN_fffe5d0e();
    if (ai_sh.sc_running == running && down == ai_sh.sc_down)
        return 0;
    ai_sh.sc_running = running;
    f[0] = 'S';
    f[1] = 'C';
    f[2] = running == 1 ? (down == 0 ? '1' : '2') : '0';
    f[3] = ';';
    ai_sh.sc_down = down;
    return ai_send(f, 4);
}

/* cat_ai_SD 0xFFFE0AFF: SD + 2 digits, the CW break-in delay */
uint16_t cat_ai_SD(void)
{
    uint8_t f[5];

    if (ai_sh.sd == g_opstate.cw_bkin_delay)
        return 0;
    ai_sh.sd = g_opstate.cw_bkin_delay;
    ai_template(f, "SD00;", 5);
    put_dec(&f[2], ai_sh.sd, 10);
    return ai_send(f, 5);
}

/* the FUNC knob function (g_opstate.func_knob) as the SF0 character: 0 -> '1', 1 -> '2', 3..7 -> '3'..'7',
 * 9 -> '8', 10 -> '9', 11..15 -> 'A'..'E', 18..20 -> 'F'..'H', others '0' [fact: the switch at 0xFFFE0BE1] */
static inline uint8_t ai_funcknob_char(uint8_t v)
{
    if (v <= 1u)
        return (uint8_t)('1' + v);
    if (v >= 3u && v <= 7u)
        return (uint8_t)('0' + v);
    if (v == 9u || v == 10u)
        return (uint8_t)('8' + v - 9u);
    if (v >= 11u && v <= 15u)
        return (uint8_t)('A' + v - 11u);
    if (v >= 18u && v <= 20u)
        return (uint8_t)('F' + v - 18u);
    return '0';
}

/* cat_ai_SF 0xFFFE0BA1: SF0 P2 (which 0: the FUNC knob function) or SF1 P2 (which 1: the FUNC item 0x1D..0x21 ->
 * '1'..'5', else '0') */
uint16_t cat_ai_SF(uint8_t which)
{
    uint8_t f[5];
    uint8_t v;

    ai_template(f, "SF00;", 5);
    if (which == 0) {
        if (ai_sh.sf[0] == g_opstate.func_knob)
            return 0;
        ai_sh.sf[0] = g_opstate.func_knob;
        f[3] = ai_funcknob_char(g_opstate.func_knob);
    } else if (which == 1) {
        if (ai_sh.sf[1] == g_ui.func_knob_item)
            return 0;
        ai_sh.sf[1] = g_ui.func_knob_item;
        f[2] = '1';
        v = g_ui.func_knob_item;
        f[3] = v >= 0x1Du && v <= 0x21u ? (uint8_t)('1' + v - 0x1Du) : '0';
    } else {
        return 0;
    }
    return ai_send(f, 5);
}

/* cat_ai_SH 0xFFFE0D06: SH00 + 2 digits, the WIDTH index of the RX mode (width_index_of_hz + 1, 0 above the
 * mode's range; fixed for AM, FM and DATA-FM). The index is undefined for the mode code 15 (here 0) */
uint16_t cat_ai_SH(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    uint8_t v = 0, max = 0x15;
    const struct mode_blk *b = 0;
    uint8_t f[7];

    switch (m) {
    case MODE_LSB: case MODE_USB:
        b = &r->blk[0];
        max = 0x17;
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
        v = 2;
        break;
    case MODE_AM_N:
        v = 1;
        break;
    case MODE_FM: case MODE_DATA_FM:
        v = 3;
        break;
    default:
        break;
    }
    if (b) {
        v = (uint8_t)(width_index_of_hz(m, be16(b->width_be)) + 1u);
        if (v > max)
            v = 0;
    }
    if (ai_sh.sh == v)
        return 0;
    ai_sh.sh = v;
    ai_template(f, "SH0000;", 7);
    put_dec(&f[4], v, 10);
    return ai_send(f, 7);
}

/* cat_ai_SQ 0xFFFE0E99: SQ0 + 3 digits, the squelch as RF/SQL VR shows it: the RF gain knob in percent,
 * (rf_gain * 100 / 255 + 0.5) truncated, when EX030102 is not 0 (jitter filter) */
uint16_t cat_ai_SQ(void)
{
    uint8_t v;
    float pct;
    uint8_t f[7];

    if (g_opstate.ex030102_rf_sql_vr == 0)
        return 0;
    pct = (float)g_ui.rf_gain * 100.0f / 255.0f;
    v = (uint8_t)ftou(pct + 0.5f);
    if (ai_sh.sq == v)
        return 0;
    ai_sh.sq = v;
    ai_hist_push(&ai_sq_idx, ai_sq_hist, v);
    if (ai_sq_hist[0] == ai_sq_hist[2] && ai_sq_hist[1] == ai_sq_hist[3])
        return 0;
    ai_template(f, "SQ0000;", 7);
    put_dec(&f[3], v, 100);
    return ai_send(f, 7);
}

/* cat_ai_ST 0xFFFE1447: ST P1, split on (any value but 0 -> '1') */
uint16_t cat_ai_ST(void)
{
    uint8_t f[4];

    if (ai_sh.st == g_opstate.split_on)
        return 0;
    ai_sh.st = g_opstate.split_on;
    f[0] = 'S';
    f[1] = 'T';
    f[2] = g_opstate.split_on == 0 ? '0' : '1';
    f[3] = ';';
    return ai_send(f, 4);
}

/* cat_ai_TS 0xFFFE14B4: TS P1, the TX-watch swap (1 -> '1', else '0') */
uint16_t cat_ai_TS(void)
{
    uint8_t f[4];

    if (ai_ts == g_ui.txw_swap)
        return 0;
    ai_ts = g_ui.txw_swap;
    f[0] = 'T';
    f[1] = 'S';
    f[2] = g_ui.txw_swap == 1 ? '1' : '0';
    f[3] = ';';
    return ai_send(f, 4);
}

/* cat_ai_TX 0xFFFE1523: TX P1, the PTT source: 0 receive -> '0', 5 (CAT) -> '1', others '2' */
uint16_t cat_ai_TX(void)
{
    uint8_t src = ptt_source_get();
    uint8_t f[4];

    if (ai_sh.tx == src)
        return 0;
    f[0] = 'T';
    f[1] = 'X';
    f[2] = src == 0 ? '0' : src == 5 ? '1' : '2';
    f[3] = ';';
    ai_sh.tx = src;
    return ai_send(f, 4);
}

/* cat_ai_VD 0xFFFE1596: VD + 2 digits, the VOX delay of the VOX source (EX030405) */
uint16_t cat_ai_VD(void)
{
    uint8_t v = g_opstate.ex030405_vox_select == 0 ? g_opstate.vox_delay[0] : g_opstate.vox_delay[1];
    uint8_t f[5];

    if (ai_sh.vd == v)
        return 0;
    ai_sh.vd = v;
    ai_template(f, "VD00;", 5);
    put_dec(&f[2], v, 10);
    return ai_send(f, 5);
}

/* cat_ai_VG 0xFFFE165D: VG + 3 digits, the VOX gain */
uint16_t cat_ai_VG(void)
{
    uint8_t f[6];

    if (ai_sh.vg == g_opstate.vox_gain)
        return 0;
    ai_sh.vg = g_opstate.vox_gain;
    ai_template(f, "VG000;", 6);
    put_dec(&f[2], ai_sh.vg, 100);
    return ai_send(f, 6);
}

/* cat_ai_VS 0xFFFE170A: VS P1, the active VFO */
uint16_t cat_ai_VS(void)
{
    return ai_digit('V', 'S', &ai_sh.vs, g_opstate.active_vfo);
}

/* cat_ai_VX 0xFFFE1774: VX P1, VOX on; reported as 0 while VFO 1 is in CW or RTTY */
uint16_t cat_ai_VX(void)
{
    uint8_t m;
    uint8_t v;

    (void)vfo_rec_ptr(0);                       /* called, result unused [fact: 0xFFFE1776] */
    m = vfo_mode(1);
    v = (m == MODE_CW_L || m == MODE_CW_U || m == MODE_RTTY_L || m == MODE_RTTY_U) ? 0 : g_opstate.vox_on;
    return ai_digit('V', 'X', &ai_sh.vx, v);
}

/* cat_ai_poll 0xFFFDD797: with AI on at a port and all three ports idle, the first changed item in this order goes
 * to every port with AI on; nothing is sent while the hold-off after a set runs (timer 0x32, cat_ai_holdoff), but
 * the detectors run and keep their shadows */
void cat_ai_poll(void)
{
    uint16_t n;
    uint8_t k;

    if (g_ui.cat_ai_on[0] != 1 && g_ui.cat_ai_on[1] != 1 && g_ui.cat_ai_on[2] != 1)
        return;
    if (cat_tx_busy(1) != 0 || cat_tx_busy(2) != 0 || cat_tx_busy(3) != 0)
        return;
    n = cat_ai_AC();
    if (n == 0) n = cat_ai_AG();
    if (n == 0) n = cat_ai_AO();
    if (n == 0) n = cat_ai_AS(1);
    if (n == 0) n = cat_ai_AS(2);
    if (n == 0) n = cat_ai_AV();
    if (n == 0) n = cat_ai_BC();
    if (n == 0) n = cat_ai_BI();
    if (n == 0) n = cat_ai_BP();
    if (n == 0) n = cat_ai_CF(0);
    if (n == 0) n = cat_ai_CF(1);
    if (n == 0) n = cat_ai_CN();
    if (n == 0) n = cat_ai_CO();
    if (n == 0) n = cat_ai_CS();
    if (n == 0) n = cat_ai_CT();
    if (n == 0) n = cat_ai_ex();
    if (n == 0) n = cat_ai_FA_FB();
    if (n == 0) n = cat_ai_FN();
    if (n == 0) n = cat_ai_FT();
    if (n == 0) n = cat_ai_GT();
    if (n == 0) n = cat_ai_IF_OI(0);
    if (n == 0) n = cat_ai_IF_OI(1);
    if (n == 0) n = cat_ai_IS();
    if (n == 0) n = cat_ai_KP();
    if (n == 0) n = cat_ai_KR();
    if (n == 0) n = cat_ai_KS();
    if (n == 0) n = cat_ai_LK();
    if (n == 0) n = cat_ai_MD(0);
    if (n == 0) n = cat_ai_MD(1);
    if (n == 0) n = cat_ai_MG();
    if (n == 0) n = cat_ai_ML();
    if (n == 0) n = cat_ai_MS();
    if (n == 0) n = cat_ai_MX();
    if (n == 0) n = cat_ai_NA();
    if (n == 0) n = cat_ai_NB();
    if (n == 0) n = cat_ai_NL();
    if (n == 0) n = cat_ai_NR();
    if (n == 0) n = cat_ai_OS();
    if (n == 0) n = cat_ai_PA();
    if (n == 0) n = cat_ai_PC();
    if (n == 0) n = cat_ai_PL();
    if (n == 0) n = cat_ai_PR();
    if (n == 0) n = cat_ai_RA();
    if (n == 0) n = cat_ai_RG();
    if (n == 0) n = cat_ai_RI();
    if (n == 0) n = cat_ai_RL();
    if (n == 0) n = cat_ai_RM();
    if (n == 0) n = cat_ai_SC();
    if (n == 0) n = cat_ai_SD();
    if (n == 0) n = cat_ai_SF(0);
    if (n == 0) n = cat_ai_SF(1);
    if (n == 0) n = cat_ai_SH();
    if (n == 0) n = cat_ai_SQ();
    for (k = 0; k < 9u && n == 0; k++)        /* the nine scope items SS0..SS8 */
        n = cat_ai_SS(k);
    if (n == 0) n = cat_ai_ST();
    if (n == 0) n = cat_ai_TS();
    if (n == 0) n = cat_ai_TX();
    if (n == 0) n = cat_ai_VD();
    if (n == 0) n = cat_ai_VG();
    if (n == 0) n = cat_ai_VX();
    if (n == 0) n = cat_ai_VS();
    if (n == 0) n = cat_ai_FD();
    if (cat_ai_held == 1) {
        if (swtimer_expired(AI_HOLD_TIMER) != 1)
            return;
        cat_ai_held = 0;
    }
    if (n == 0)
        return;
    if (g_ui.cat_ai_on[0] == 1)
        cat_send_reply(1, cat_ai_buf, n);
    if (g_ui.cat_ai_on[1] == 1)
        cat_send_reply(2, cat_ai_buf, n);
    if (g_ui.cat_ai_on[2] == 1)
        cat_send_reply(3, cat_ai_buf, n);
}
