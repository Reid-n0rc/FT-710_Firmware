/* CAT command handlers of the MAIN image that read or change the radio state, recreated for T24
 * (docs/code/main/cat.md, docs/cat-commands-primary.md). cat_dispatch (app/cat_parse.c) calls each with the command
 * text (the mnemonic at text[0..1], parameters from text[2]) and set = 0 for the read form, 1 for the set form;
 * the mnemonic (and for some commands P1) is already echoed into cat_reply. A read leaves its answer in cat_reply
 * with the length in cat_reply_len; a refused set sets cat_error ("?;").
 *
 * Most sets first ask key_event_filter whether the front-panel key with the same function is allowed now (it
 * refuses during about 20 mode locks [doc: cat.md]); the key code is the image's [fact: each call's argument]. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "cat_cmds.h"
#include "cat_util.h"

static inline int is_cw(uint8_t m)
{
    return m == MODE_CW_L || m == MODE_CW_U;
}

/* the 90-byte record copy CC-RX writes as a byte loop (cat_MA 0xFFFAB3FD) */
static void vfo_rec_copy(struct vfo_rec *dst, const struct vfo_rec *src)
{
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    unsigned i;

    for (i = 0; i < sizeof *dst; i++)
        d[i] = s[i];
}

/* cat_FN 0xFFFA9C96: FN P1 = FUNC knob selection 0..2 */
void cat_FN(const uint8_t *text, uint8_t set)
{
    if (!set) {
        cat_reply[2] = g_opstate.fn_select == 1 ? '1' : g_opstate.fn_select == 2 ? '2' : '0';
        reply_done(3);
        return;
    }
    if (text[2] == '0')
        g_opstate.fn_select = 0;
    else if (text[2] == '1')
        g_opstate.fn_select = 1;
    else if (text[2] == '2')
        g_opstate.fn_select = 2;
    else
        cat_error = 1;
}

/* cat_KR 0xFFFAAD52: KR P1 = KEYER on/off, set only in CW (key 0xE0) */
void cat_KR(const uint8_t *text, uint8_t set)
{
    if (!set) {
        cat_reply[2] = (uint8_t)nib2hex(g_opstate.keyer_on);
        reply_done(3);
        return;
    }
    if (!key_allowed(0xE0, 0))
        return;
    if (vfo_mode_is_cw() == 0) {
        cat_error = 1;
        return;
    }
    if (text[2] == '1')
        g_opstate.keyer_on = 1;
    else if (text[2] == '0')
        g_opstate.keyer_on = 0;
    else
        cat_error = 1;
}

/* cat_MA 0xFFFAB3FD, cat_MB 0xFFFAB478: memory channel -> VFO-A / VFO-B (key 0x308 M>V), not while the TX lamp is
 * on */
static void mem_to_vfo(uint8_t side)
{
    const struct vfo_rec *ch = &memch[side == 0 ? g_mem_hdr.chan_a : g_mem_hdr.chan_b];

    if (!key_allowed(0x308, 0))
        return;
    if (g_ui.tx_lamp != 0) {
        cat_error = 1;
        return;
    }
    vfo_rec_copy(side == 0 ? &g_opstate.vfo_a : &g_opstate.vfo_b, ch);
    vfo_mark_edited(side);
    vfo_store_back(side);
    g_ui.freq_refresh_req = 1;
}

void cat_MA(void)
{
    mem_to_vfo(0);
}

void cat_MB(void)
{
    mem_to_vfo(1);
}

/* cat_MS 0xFFFAC4B6: MS P1 P2 = meter selection 0..5, P2 always 0 */
void cat_MS(const uint8_t *text, uint8_t set)
{
    uint8_t n;

    if (!set) {
        cat_reply[2] = (uint8_t)nib2hex(g_opstate.meter_sel);
        cat_reply[3] = '0';
        reply_done(4);
        return;
    }
    if (text[3] != '0') {
        cat_error = 1;
        return;
    }
    n = (uint8_t)hex2nib(text[2]);
    if (n > 5u) {
        cat_error = 1;
        return;
    }
    g_opstate.meter_sel = n;
}

/* cat_MX 0xFFFAC9AD: MX P1 = MOX; a set acts through the MOX/VOX key's handlers (key 0x302, kind 2) */
void cat_MX(const uint8_t *text, uint8_t set)
{
    uint8_t mox = g_ui.ptt_mox;
    char p1;

    if (!set) {
        cat_reply[2] = (uint8_t)nib2hex(g_ui.ptt_mox);
        reply_done(3);
        return;
    }
    if (!key_allowed(0x302, 2))
        return;
    p1 = hex2nib(text[2]);
    if (p1 == 0) {
        if (mox != 0) {
            key_mox_vox_press();
            key_mox_vox_short();
        }
    } else if (p1 == 1) {
        if (mox == 0)
            key_mox_vox_long();
    } else {
        cat_error = 1;
    }
}

/* cat_NB 0xFFFACC65: NB P1 P2 = noise blanker of VFO 0 (record flags2 bit 1; key 0x303) */
void cat_NB(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);

    if (!set) {
        cat_reply[3] = (uint8_t)nib2hex((uint8_t)((r->flags2 & 0x02u) >> 1));
        reply_done(4);
        return;
    }
    if (!key_allowed(0x303, 0))
        return;
    if (text[3] == '0')
        r->flags2 &= (uint8_t)~0x02u;
    else if (text[3] == '1')
        r->flags2 |= 0x02u;
    else
        cat_error = 1;
}

/* cat_NR 0xFFFACE21: NR P1 P2 = DNR on/off of VFO 0 (record dnr bit 4; key 0x304); P1 must be 0 */
void cat_NR(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[3] = (r->dnr & 0x10u) ? '1' : '0';
        reply_done(4);
        return;
    }
    if (!key_allowed(0x304, 0))
        return;
    if (text[3] == '1')
        r->dnr |= 0x10u;
    else if (text[3] == '0')
        r->dnr &= (uint8_t)~0x10u;
    else
        cat_error = 1;
}

/* cat_PA 0xFFFAD001: PA P1 P2 = preamp of VFO 0: CAT 0/1/2 = IPO / AMP1 / AMP2 = record flags5 bits 0..1 values
 * 0 / 2 / 3 */
void cat_PA(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t v;

    if (!set) {
        v = r->flags5 & 3u;
        cat_reply[2] = '0';
        cat_reply[3] = v == 2u ? '1' : v == 3u ? '2' : '0';
        reply_done(4);
        return;
    }
    if (text[3] == '0')
        v = 0;
    else if (text[3] == '1')
        v = 2;
    else if (text[3] == '2')
        v = 3;
    else {
        cat_error = 1;
        return;
    }
    r->flags5 &= (uint8_t)~3u;
    r->flags5 |= v;
}

/* cat_PS 0xFFFAD696: PS P1; reads "1" (a powered-off radio answers nothing, cat_parse); PS0 = restart request
 * with power command 0x10, PS1 = AUTO POWER ON and power_on_request */
void cat_PS(const uint8_t *text, uint8_t set)
{
    if (!set) {
        cat_reply[2] = '1';
        reply_done(3);
        return;
    }
    if (text[2] == '0') {
        g_ui.restart_req = 1;
        g_ui.power_cmd = 0x10;
    } else if (text[2] == '1') {
        g_opstate.auto_power_on = 1;
        power_on_request();
    } else {
        cat_error = 1;
    }
}

/* cat_RA 0xFFFAD718: RA P1 P2 = attenuator of VFO 0 (record flags3 bits 0..1); P1 must be 0 */
void cat_RA(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t n;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (set) {
        n = (uint8_t)hex2nib(text[3]);
        if (n < 4u) {
            r->flags3 &= (uint8_t)~3u;
            r->flags3 |= n;
        } else {
            cat_error = 1;
        }
        g_ui.freq_refresh_req = 1;              /* also after a refused value [fact: 0xFFFAD718] */
        return;
    }
    cat_reply[2] = '0';
    cat_reply[3] = (uint8_t)nib2hex(r->flags3 & 3u);
    reply_done(4);
}

/* cat_SC 0xFFFADCD6: SC P1 = scan: 0 off, 1 up, 2 down; a read reports the direction (FUN_fffe5d0e) */
void cat_SC(const uint8_t *text, uint8_t set)
{
    if (!set) {
        if (g_ui.scan_running == 1)
            cat_reply[2] = FUN_fffe5d0e() == 0 ? '1' : '2';
        else
            cat_reply[2] = '0';
        reply_done(3);
        return;
    }
    if (g_ui.tx_lamp != 0) {
        cat_error = 1;
        return;
    }
    if (text[2] == '0') {
        if (g_ui.scan_running == 1)
            scan_stop();
    } else if (text[2] == '1') {
        if (scan_allowed() == 1)
            scan_start_up();
    } else if (text[2] == '2') {
        if (scan_allowed() == 1)
            scan_start_down();
    } else {
        cat_error = 1;
    }
}

void func_display_open(void);
/* the first byte == c in buf[0..n), else buf itself [fact: mem_find_byte 0xFFFB012C returns it in R1; the decompile
 * shows void] */
const uint8_t *mem_find_byte(const uint8_t *buf, uint8_t c, uint16_t n);

/* cat_EM 0xFFFA9648: EM0 P2 P3 = text slot 1..5 (em_text_mem, 50 bytes ended by 0xFE; RAM only, no save). A read
 * answers the bytes before the 0xFE (none when there is none in the 50 or it is the first); a set stores the
 * characters up to the ';' (found in the first 50 bytes of the command, the length in 8 bits) and an 0xFE after
 * them [fact: the mem_find_byte calls 0xFFFA9681..0xFFFA97D7 (read) and 0xFFFA984C (set)] */
void cat_EM(const uint8_t *text, uint8_t set)
{
    uint8_t *slot;
    uint8_t n;
    unsigned i;

    if (!set) {
        if (text[2] != '0' || text[3] < '1' || text[3] > '5') {
            cat_error = 1;
            return;
        }
        slot = em_text_mem[text[3] - '1'];
        n = (uint8_t)(mem_find_byte(slot, 0xFE, 50) - slot);
        if (n != 0 && n <= 50u)
            for (i = 0; i < n; i++)
                cat_reply[4 + i] = slot[i];
        cat_reply[4 + n] = ';';
        cat_reply_len = (uint16_t)(n + 5u);
        return;
    }
    n = (uint8_t)((uint8_t)(uintptr_t)mem_find_byte(text, ';', 50) - (uint8_t)(uintptr_t)text - 4u);
    if (text[2] != '0' || text[3] < '1' || text[3] > '5') {
        cat_error = 1;
        return;
    }
    slot = em_text_mem[text[3] - '1'];
    for (i = 0; i < n; i++)
        slot[i] = text[4 + i];
    slot[n] = 0xFE;
}

/* cat_KM 0xFFFAA905: KM P1 P2 = keyer memory text 1..5 (keyer_text_mem, the texts keyer_task sends). A read answers
 * the stored characters (a length of 0 answers "KM;", the ';' over P1); a set stores len - 4 characters (filled to
 * 50 with spaces; the image does not limit the count) and ends the text with '}' unless the command has one in its
 * first 50 characters after the first, then saves the slot. Refused while the keyboard edits the same slot. */
void cat_KM(const uint8_t *text, uint8_t set, uint16_t len)
{
    struct keyer_text *t;
    uint8_t slot = (uint8_t)hex2nib(text[2]);
    uint8_t n;
    unsigned i;

    if (!set) {
        if (text[2] < '1' || text[2] > '5') {
            cat_error = 1;
            return;
        }
        t = &keyer_text_mem[text[2] - '1'];
        n = t->len;
        for (i = 0; i < n; i++)
            cat_reply[3 + i] = t->text[i];
        if (n == 0) {
            cat_reply[2] = ';';
            cat_reply_len = 3;
            return;
        }
        cat_reply[3 + n] = ';';
        cat_reply_len = (uint16_t)(n + 4u);
        return;
    }
    if (g_ui.kbd_open == 1 && g_ui.kbd_target == 2 && slot == g_ui.msg_slot_idx + 1u) {
        cat_error = 1;
        return;
    }
    if (text[2] < '1' || text[2] > '5') {
        cat_error = 1;
        return;
    }
    n = (uint8_t)(len - 4u);
    t = &keyer_text_mem[text[2] - '1'];
    for (i = 0; i < sizeof t->text; i++)
        t->text[i] = ' ';
    for (i = 0; i < n; i++)
        t->text[i] = text[3 + i];
    if (mem_find_byte(&text[3], '}', 50) == &text[3])
        t->text[n] = '}';
    t->len = n;
    eeprom_save_msg(1, text[2] - '0');
}
/* a packed BCD byte as two characters. The image's code uses all of R2: declared uint32_t so that GCC passes the
 * byte zero-extended (with a uint8_t parameter GCC loads it with the sign-extending MOV.B, and a byte >= 0x80
 * printed differently: the check of cat_DT, round 4) */
void bcd_to_ascii2(uint8_t *out, uint32_t bcd);
uint8_t ascii2_to_bcd(const uint8_t *in);           /* two characters as a packed BCD byte */

/* cat_DT 0xFFFA9281: DT0 = date as yyyymmdd (the year must be 20yy; leap years by yy & 3, months of 30 and 31 days),
 * DT1 = time as hhmmss (the seconds are checked as digits and read as "00"); the clock bytes are packed BCD in the
 * UI block, copied to rtc_set and sent to the DISPLAY by the 0x65 request */
void cat_DT(const uint8_t *text, uint8_t set)
{
    uint8_t yy, mm, dd, days, hh, mi;
    unsigned i;

    if (!set) {
        if (text[2] == '0') {
            cat_reply[3] = '2';
            cat_reply[4] = '0';
            bcd_to_ascii2(&cat_reply[5], g_ui.rtc_yy);
            bcd_to_ascii2(&cat_reply[7], g_ui.rtc_mm);
            bcd_to_ascii2(&cat_reply[9], g_ui.rtc_dd);
            reply_done(11);
        } else if (text[2] == '1') {
            bcd_to_ascii2(&cat_reply[3], g_ui.rtc_hh);
            bcd_to_ascii2(&cat_reply[5], g_ui.rtc_min);
            cat_reply[8] = '0';
            cat_reply[7] = '0';
            reply_done(9);
        } else {
            cat_error = 1;
        }
        return;
    }
    if (text[2] == '0') {
        for (i = 3; i < 11; i++) {
            if (text[i] < '0' || text[i] > '9') {
                cat_error = 1;
                return;
            }
        }
        (void)get_dec(&text[3], 2, 10, &yy);
        if (yy != 20u) {
            cat_error = 1;
            return;
        }
        (void)get_dec(&text[5], 2, 10, &yy);
        (void)get_dec(&text[7], 2, 10, &mm);
        if (mm == 0 || mm > 12u) {
            cat_error = 1;
            return;
        }
        (void)get_dec(&text[9], 2, 10, &dd);
        if (mm == 2)
            days = (yy & 3u) == 0 ? 29 : 28;
        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
            days = 30;
        else
            days = 31;
        if (dd == 0 || dd > days) {
            cat_error = 1;
            return;
        }
        g_ui.rtc_yy = ascii2_to_bcd(&text[5]);
        g_ui.rtc_set[0] = g_ui.rtc_yy;
        g_ui.rtc_mm = ascii2_to_bcd(&text[7]);
        g_ui.rtc_set[1] = g_ui.rtc_mm;
        g_ui.rtc_dd = ascii2_to_bcd(&text[9]);
        g_ui.rtc_set[2] = g_ui.rtc_dd;
        g_ui.dl_req_65_clock = 1;
        return;
    }
    if (text[2] != '1') {
        cat_error = 1;
        return;
    }
    for (i = 3; i < 9; i++) {
        if (text[i] < '0' || text[i] > '9') {
            cat_error = 1;
            return;
        }
    }
    (void)get_dec(&text[3], 2, 10, &hh);
    (void)get_dec(&text[5], 2, 10, &mi);
    if (hh > 23u || mi > 59u) {
        cat_error = 1;
        return;
    }
    g_ui.rtc_hh = ascii2_to_bcd(&text[3]);
    g_ui.rtc_set[3] = g_ui.rtc_hh;
    g_ui.rtc_set[4] = ascii2_to_bcd(&text[5]);
    g_ui.rtc_min = g_ui.rtc_set[4];
    g_ui.dl_req_65_clock = 1;
}

/* SF0's characters and the FUNC knob function each stands for [fact: the two switches of cat_SF 0xFFFADEB6] */
static const uint8_t sf_chars[] = "123456789ABCDEFGH";
static const uint8_t sf_funcs[] = {0, 1, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 0x12, 0x13, 0x14};

/* cat_SF 0xFFFADEB6: SF P1 P2. P1 = 0: the FUNC knob function (g_opstate.func_knob, also kept in func_knob_sf);
 * P1 = 1: the DSP knob item 1..5 = UI knob item 0x1D..0x21 (a set opens the function display); a read of anything
 * else answers '0'. Another P1 reads only the ';' and is ignored by a set. */
void cat_SF(const uint8_t *text, uint8_t set)
{
    unsigned i;

    if (!set) {
        if (text[2] == '0') {
            cat_reply[3] = '0';
            for (i = 0; i < sizeof sf_funcs; i++) {
                if (g_opstate.func_knob == sf_funcs[i]) {
                    cat_reply[3] = sf_chars[i];
                    break;
                }
            }
        } else if (text[2] == '1') {
            uint8_t item = g_ui.func_knob_item;

            cat_reply[3] = item >= 0x1Du && item <= 0x21u ? (uint8_t)('1' + item - 0x1Du) : '0';
        }
        reply_done(4);
        return;
    }
    if (text[2] == '0') {
        for (i = 0; i < sizeof sf_funcs; i++) {
            if (text[3] == sf_chars[i]) {
                g_opstate.func_knob = sf_funcs[i];
                g_opstate.func_knob_sf = sf_funcs[i];
                return;
            }
        }
        cat_error = 1;
        return;
    }
    if (text[2] != '1')
        return;
    if (text[3] < '1' || text[3] > '5') {
        cat_error = 1;
        return;
    }
    /* '1'..'5' = items 0x1D..0x21 with the DSP knob functions 0, 1, 2, 3, 3 */
    g_ui.func_knob_item = (uint8_t)(0x1Du + (text[3] - '1'));
    g_ui.dsp_knob_func = text[3] == '5' ? 3u : (uint8_t)(text[3] - '1');
    func_display_open();
}

/* cat_SM 0xFFFAE64B: SM0 = S-meter 0..255 as three decimal digits */
void cat_SM(const uint8_t *text)
{
    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    put_dec(&cat_reply[3], meter_get_s(), 100);
    cat_reply[2] = '0';
    reply_done(6);
}

/* 0..255 <-> 0..100 in single precision, then + 0.5 and a conversion to unsigned that truncates: the image's
 * FTOU (RXv2, rounds towards 0 whatever FPSW.RM says; software manual p. 106) after FADD #0.5 [fact: 0xFFFAE717,
 * 0xFFFAE806]. Not a lrintf: GCC 13.3 for RX never inlines lrintf (it calls _lrintf at -O0 to -Os, also with
 * -ffast-math), and CC-RX's FTOU is a plain (unsigned) cast. In range (0.5 .. 255.5) a cast to int (GCC's FTOI; the
 * unsigned cast would call libgcc's __fixunssfsi) gives the same. */
static uint8_t scale_round(uint8_t v, float mul, float div)
{
    return (uint8_t)(int)((float)v * mul / div + 0.5f);
}

/* cat_SQ 0xFFFAE6CC: SQ P1 P2..P4 = squelch 000..100 (P1 is not checked); kept as 0..255 in cat_sq_level, and also
 * in the RF/SQL knob's byte g_ui.rf_gain when EX030102 RF/SQL VR is not 0 */
void cat_SQ(const uint8_t *text, uint8_t set)
{
    uint8_t v;

    if (!set) {
        v = g_opstate.ex030102_rf_sql_vr != 0 ? g_ui.rf_gain : cat_sq_level;
        put_dec(&cat_reply[3], scale_round(v, 100.0f, 255.0f), 100);
        cat_reply[2] = '0';
        reply_done(6);
        return;
    }
    if (!get_dec(&text[3], 3, 100, &v))
        return;
    if (v > 100u) {
        cat_error = 1;
        return;
    }
    cat_sq_level = scale_round(v, 255.0f, 100.0f);
    if (g_opstate.ex030102_rf_sql_vr != 0)
        g_ui.rf_gain = cat_sq_level;
}

/* cat_ST 0xFFFAF3B5: ST P1 = split on/off (split_toggle; key 0x305), not while the TX lamp is on */
void cat_ST(const uint8_t *text, uint8_t set)
{
    if (!set) {
        cat_reply[2] = g_opstate.split_on == 0 ? '0' : '1';
        reply_done(3);
        return;
    }
    if (!key_allowed(0x305, 0))
        return;
    if (g_ui.tx_lamp != 0) {
        cat_error = 1;
        return;
    }
    if (text[2] == '0') {
        if (g_opstate.split_on == 1)
            split_toggle();
    } else if (text[2] == '1') {
        if (g_opstate.split_on == 0)
            split_toggle();
    } else {
        cat_error = 1;
    }
}

/* cat_TX 0xFFFAF7B8: TX P1: read 0 = RX, 1 = keyed by CAT (PTT source 5), 2 = keyed otherwise; TX0/TX1 set the CAT
 * PTT request, refused while scanning or with the MIC key held */
void cat_TX(const uint8_t *text, uint8_t set)
{
    char p1;

    if (!set) {
        uint8_t src = ptt_source_get();

        cat_reply[2] = src == 0 ? '0' : src == 5 ? '1' : '2';
        reply_done(3);
        return;
    }
    if (g_ui.scan_running == 1 || g_ui.mic_key_hold == 1) {
        cat_error = 1;
        return;
    }
    p1 = hex2nib(text[2]);
    if (p1 == 0)
        g_ui.cat_tx_req = 0;
    else if (p1 == 1)
        g_ui.cat_tx_req = 1;
    else
        cat_error = 1;
}

/* cat_VX 0xFFFAFFA0: VX P1 = VOX on/off (key 0x302); reads 0 and refuses a set in CW and RTTY */
void cat_VX(const uint8_t *text, uint8_t set)
{
    uint8_t m;

    (void)vfo_rec_ptr(0);
    m = vfo_mode(1);
    if (!set) {
        cat_reply[2] = (is_cw(m) || m == MODE_RTTY_L || m == MODE_RTTY_U) ? '0' : (uint8_t)nib2hex(g_opstate.vox_on);
        reply_done(3);
        return;
    }
    if (!key_allowed(0x302, 0))
        return;
    if (is_cw(m) || m == MODE_RTTY_L || m == MODE_RTTY_U) {
        cat_error = 1;
        return;
    }
    if (text[2] == '0')
        g_opstate.vox_on = 0;
    else if (text[2] == '1')
        g_opstate.vox_on = 1;
    else
        cat_error = 1;
}

/* cat_ZI 0xFFFB006E: ZI0 = ZIN/SPOT (key 0x307) in CW, not while scanning, with the MIC key held or in a tune
 * cycle */
void cat_ZI(const uint8_t *text)
{
    const struct vfo_rec *r;

    if (!key_allowed(0x307, 0))
        return;
    if (g_ui.scan_running == 1 || g_ui.mic_key_hold == 1 || g_ui.tune_cycle != 0) {
        cat_error = 1;
        return;
    }
    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    r = (const struct vfo_rec *)vfo_rec_ptr(g_ui.transmitting);
    if (!is_cw(r->mode & 0x0Fu)) {
        cat_error = 1;
        return;
    }
    key_zin_spot_short();
}

/* cat_LK 0xFFFAB09F: LK P1 = dial lock (key 0x300), with the lock pop-up 0x47 / 0x48 */
void cat_LK(const uint8_t *text, uint8_t set)
{
    if (!set) {
        cat_reply[2] = (uint8_t)nib2hex(g_opstate.lock_on);
        reply_done(3);
        return;
    }
    if (!key_allowed(0x300, 0))
        return;
    if (text[2] == '1') {
        g_opstate.lock_on = 1;
        setting_popup(0x47);
    } else if (text[2] == '0') {
        g_opstate.lock_on = 0;
        setting_popup(0x48);
    } else {
        cat_error = 1;
    }
}

/* cat_EX 0xFFFA9937: EX menu read / set through ex_command (docs/code/main/menu.md); a set holds the AI report off
 * when any port has AI on */
void cat_EX(const uint8_t *text, uint8_t set, uint16_t len)
{
    uint16_t n = 0;

    cat_error = ex_command((char *)text, set, len, cat_reply, &n);
    if (!set) {
        cat_reply_len = n;
        return;
    }
    if (g_ui.cat_ai_on[0] == 1 || g_ui.cat_ai_on[1] == 1 || g_ui.cat_ai_on[2] == 1)
        cat_ai_holdoff();
}

/* cat_AG 0xFFFA6867: AG0 nnn = AF gain 0..255 */
void cat_AG(const uint8_t *text, uint8_t set)
{
    uint8_t v;

    if (!set) {
        put_dec(&cat_reply[3], g_ui.af_gain, 100);
        reply_done(6);
        return;
    }
    if (get_dec(&text[3], 3, 100, &v))
        g_ui.af_gain = v;
}

/* cat_AI 0xFFFA6946: AI P1 = auto information on/off for the port the command came in on */
void cat_AI(const uint8_t *text, uint8_t set)
{
    if (!set) {
        if (cat_port == 3)
            cat_reply[2] = (uint8_t)nib2hex(g_ui.cat_ai_on[2]);
        else if (cat_port == 2)
            cat_reply[2] = (uint8_t)nib2hex(g_ui.cat_ai_on[1]);
        else if (cat_port == 1)
            cat_reply[2] = (uint8_t)nib2hex(g_ui.cat_ai_on[0]);
        reply_done(3);
        return;
    }
    if (text[2] > '1') {
        cat_error = 1;
        return;
    }
    if (cat_port == 3)
        g_ui.cat_ai_on[2] = (uint8_t)hex2nib(text[2]);
    else if (cat_port == 2)
        g_ui.cat_ai_on[1] = (uint8_t)hex2nib(text[2]);
    else if (cat_port == 1)
        g_ui.cat_ai_on[0] = (uint8_t)hex2nib(text[2]);
    if (text[2] == '1')
        cat_ai_holdoff();
}

/* cat_CS 0xFFFA8B98: CS P1 = CW SPOT tone (key 0x307, kind 2), not in split, only where keyer_mode_class allows */
void cat_CS(const uint8_t *text, uint8_t set)
{
    uint8_t *r;

    if (!set) {
        cat_reply[2] = g_ui.cw_spot_on == 1 ? '1' : '0';
        reply_done(3);
        return;
    }
    r = vfo_rec_ptr(1);
    if (!key_allowed(0x307, 2))
        return;
    if (g_opstate.split_on == 1 || keyer_mode_class(r) == 0) {
        cat_error = 1;
        return;
    }
    if (text[2] == '1') {
        g_ui.cw_spot_on = 1;
        beep_request(4);
    } else if (text[2] == '0') {
        if (g_ui.cw_spot_on == 1) {
            g_ui.cw_spot_on = 0;
            beep_stop();
        }
    } else {
        cat_error = 1;
    }
}

/* cat_PR 0xFFFAD595: PR P1 P2: P1 0 = proc_level (0 or 50), 1 = proc_on; any other P1 does nothing */
void cat_PR(const uint8_t *text, uint8_t set)
{
    int p1_zero = text[2] == '0';

    if (!set) {
        if (p1_zero)
            cat_reply[3] = g_opstate.proc_level == 0 ? '0' : '1';
        else if (text[2] == '1')
            cat_reply[3] = g_opstate.proc_on == 0 ? '0' : '1';
        reply_done(4);
        return;
    }
    if (p1_zero) {
        if (text[3] == '0')
            g_opstate.proc_level = 0;
        else if (text[3] == '1')
            g_opstate.proc_level = 50;
        else
            cat_error = 1;
    } else if (text[2] == '1') {
        if (text[3] == '0')
            g_opstate.proc_on = 0;
        else if (text[3] == '1')
            g_opstate.proc_on = 1;
        else
            cat_error = 1;
    }
}

/* cat_KS 0xFFFAADEA: KS nnn = keyer speed 4..60 WPM, with pop-up 0x30 */
void cat_KS(const uint8_t *text, uint8_t set)
{
    uint8_t v;

    if (!set) {
        put_dec(&cat_reply[2], g_opstate.key_speed, 100);
        reply_done(5);
        return;
    }
    if (!get_dec(&text[2], 3, 100, &v))
        return;
    if (v < 4u || v > 60u) {
        cat_error = 1;
        return;
    }
    g_opstate.key_speed = v;
    setting_popup(0x30);
}

/* cat_NL 0xFFFACCE8: NL0 0nn = noise blanker level 0..10, with pop-up 0x38 */
void cat_NL(const uint8_t *text, uint8_t set)
{
    uint8_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[3] = '0';
        put_dec(&cat_reply[4], g_opstate.nb_level, 10);
        reply_done(6);
        return;
    }
    if (!get_dec(&text[4], 2, 10, &v))
        return;
    if (v > 10u) {
        cat_error = 1;
        return;
    }
    g_opstate.nb_level = v;
    setting_popup(0x38);
}

/* cat_RG 0xFFFAD7AE: RG0 nnn = RF gain; while the knob is SQL (RF/SQL VR != 0) the value is kept at 0x464D only */
void cat_RG(const uint8_t *text, uint8_t set)
{
    uint8_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (set) {
        if (!get_dec(&text[3], 3, 100, &v))
            return;
        if (g_opstate.ex030102_rf_sql_vr == 0)
            g_ui.rf_gain = v;
        rf_gain_alt = v;
        return;
    }
    put_dec(&cat_reply[3], g_opstate.ex030102_rf_sql_vr == 0 ? g_ui.rf_gain : rf_gain_alt, 100);
    reply_done(6);
}

/* cat_RL 0xFFFADA46: RL0 nn = DNR level 1..15 of VFO 0 (record dnr bits 0..3), with pop-up 0x39 */
void cat_RL(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (!set) {
        v = r->dnr & 0x0Fu;
        cat_reply[3] = (uint8_t)nib2hex((uint8_t)(v / 10u));
        cat_reply[4] = (uint8_t)nib2hex((uint8_t)(v % 10u));
        reply_done(5);
        return;
    }
    if (!get_dec(&text[3], 2, 10, &v))
        return;
    if (v == 0 || v > 15u) {
        cat_error = 1;
        return;
    }
    r->dnr &= 0xF0u;
    r->dnr |= v;
    setting_popup(0x39);
    g_ui.freq_refresh_req = 1;
}

/* a setting of two or three decimal digits from text[2]: the read form answers it the same way; a set in lo..hi
 * stores it and shows its pop-up [fact: cat_AO 0xFFFA6B6F, cat_VG 0xFFFAF9C0, cat_KP 0xFFFAAC36, cat_SD 0xFFFADD9A,
 * cat_PL 0xFFFAD467, cat_AV 0xFFFA6EDC] */
static void dec_setting(const uint8_t *text, uint8_t set, uint8_t *value, uint8_t div, uint8_t lo, uint8_t hi,
                        uint8_t popup)
{
    unsigned digits = div == 100u ? 3u : 2u;
    uint8_t v;

    if (!set) {
        put_dec(&cat_reply[2], *value, div);
        reply_done(2u + digits);
        return;
    }
    if (!get_dec(&text[2], digits, div, &v))
        return;
    if (v < lo || v > hi) {
        cat_error = 1;
        return;
    }
    *value = v;
    setting_popup(popup);
}

/* cat_AO 0xFFFA6B6F: AO nnn = AMC OUTPUT LEVEL 1..100 */
void cat_AO(const uint8_t *text, uint8_t set)
{
    dec_setting(text, set, &g_opstate.amc_level, 100, 1, 100, 0x28);
}

/* cat_VG 0xFFFAF9C0: VG nnn = VOX GAIN 0..100 */
void cat_VG(const uint8_t *text, uint8_t set)
{
    dec_setting(text, set, &g_opstate.vox_gain, 100, 0, 100, 0x29);
}

/* cat_PL 0xFFFAD467: PL nnn = speech processor level 1..100 */
void cat_PL(const uint8_t *text, uint8_t set)
{
    dec_setting(text, set, &g_opstate.proc_level, 100, 1, 100, 0x27);
}

/* cat_KP 0xFFFAAC36: KP nn = KEY PITCH index 0..75 */
void cat_KP(const uint8_t *text, uint8_t set)
{
    dec_setting(text, set, &g_opstate.cw_pitch, 10, 0, 75, 0x31);
}

/* cat_SD 0xFFFADD9A: SD nn = CW break-in delay index 0..33 */
void cat_SD(const uint8_t *text, uint8_t set)
{
    dec_setting(text, set, &g_opstate.cw_bkin_delay, 10, 0, 33, 0x32);
}

/* cat_AV 0xFFFA6EDC: AV nnn = ANTI VOX 0..100 of the VOX SELECT (0: the first, else the second), pop-up 0x2B */
void cat_AV(const uint8_t *text, uint8_t set)
{
    uint8_t *av = g_opstate.ex030405_vox_select == 0 ? &g_opstate.antivox[0] : &g_opstate.antivox[1];

    dec_setting(text, set, av, 100, 0, 100, 0x2B);
}

/* cat_CT 0xFFFA8C79: CT0 P2 = tone mode of the active VFO's record (flags3 bits 3..5): CAT 0 / 1 / 2 = 0 / 2 / 1 */
void cat_CT(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r;
    uint8_t v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    r = g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    if (set) {
        if (text[3] == '0') {
            r->flags3 &= 0xC7u;
        } else if (text[3] == '2') {
            r->flags3 &= 0xC7u;
            r->flags3 |= 0x08u;
        } else if (text[3] == '1') {
            r->flags3 &= 0xC7u;
            r->flags3 |= 0x10u;
        } else {
            cat_error = 1;
            return;
        }
        g_ui.freq_refresh_req = 1;
        return;
    }
    v = (uint8_t)((r->flags3 & 0x38u) >> 3);
    if (v == 0)
        cat_reply[3] = '0';
    else if (v == 1)
        cat_reply[3] = '2';
    else if (v == 2)
        cat_reply[3] = '1';
    else {
        cat_error = 1;
        return;
    }
    reply_done(4);
}

/* the per-mode block cat_BI works on: CW, AM, FM / DATA-FM, LSB / USB (and codes above PSK); none in DATA, RTTY,
 * PSK [fact: the compare chain of cat_BI 0xFFFA77EC] */
static struct mode_blk *bi_blk(struct vfo_rec *r, uint8_t m)
{
    if (is_cw(m))
        return &r->blk[1];
    if (m == MODE_AM || m == MODE_AM_N)
        return &r->blk[4];
    if (m == MODE_FM || m == MODE_FM_N || m == MODE_DATA_FM || m == MODE_DATA_FM_N)
        return &r->blk[5];
    if (m == MODE_DATA_L || m == MODE_DATA_U || m == MODE_RTTY_L || m == MODE_RTTY_U || m == MODE_PSK)
        return NULL;
    return &r->blk[0];
}

/* cat_BI 0xFFFA77EC: BI P1 = the BI flag (block flags bit 1) of VFO 1's mode block */
void cat_BI(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(1);
    struct mode_blk *b = bi_blk(r, vfo_mode(1));
    char p1;

    if (b == NULL) {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[2] = (b->flags & 0x02u) ? '1' : '0';
        reply_done(3);
        return;
    }
    p1 = hex2nib(text[2]);
    if (p1 == 0)
        b->flags &= (uint8_t)~0x02u;
    else if (p1 == 1)
        b->flags |= 0x02u;
    else
        cat_error = 1;
}

/* cat_VD 0xFFFAF874: VD nn = VOX DELAY index 0..33 of the VOX SELECT, pop-up 0x2A */
void cat_VD(const uint8_t *text, uint8_t set)
{
    uint8_t *vd = g_opstate.ex030405_vox_select == 0 ? &g_opstate.vox_delay[0] : &g_opstate.vox_delay[1];

    dec_setting(text, set, vd, 10, 0, 33, 0x2A);
}

/* the mode block whose BC (DNF) bit cat_BC works on: CW, AM, DATA/PSK, RTTY, LSB/USB (and codes above PSK); none
 * in FM and DATA-FM [fact: the compare chain of cat_BC 0xFFFA717F] */
static struct mode_blk *bc_blk(struct vfo_rec *r, uint8_t m)
{
    if (is_cw(m))
        return &r->blk[1];
    if (m == MODE_AM || m == MODE_AM_N)
        return &r->blk[4];
    if (m == MODE_FM || m == MODE_FM_N || m == MODE_DATA_FM || m == MODE_DATA_FM_N)
        return NULL;
    if (m == MODE_DATA_L || m == MODE_DATA_U || m == MODE_PSK)
        return &r->blk[3];
    if (m == MODE_RTTY_L || m == MODE_RTTY_U)
        return &r->blk[2];
    return &r->blk[0];
}

/* cat_BC 0xFFFA717F: BC0 P2 = BC (DNF, block flags2 bit 7) of VFO 0's mode block */
void cat_BC(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    struct mode_blk *b;
    char p2;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    b = bc_blk(r, m);
    if (b == NULL) {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[2] = '0';
        cat_reply[3] = (b->flags2 & 0x80u) ? '1' : '0';
        reply_done(4);
        return;
    }
    p2 = hex2nib(text[3]);
    if (p2 == 0)
        b->flags2 &= 0x7Fu;
    else if (p2 == 1)
        b->flags2 |= 0x80u;
    else
        cat_error = 1;
}

/* cat_GP 0xFFFAA21F: GP P1..P4 = the four GPO lines of the TUN/LIN port, only with TUN/LIN PORT SELECT = GPO;
 * a set takes 0/1 per line, not while scanning, with the MIC key held or in a tune cycle */
void cat_GP(const uint8_t *text, uint8_t set)
{
    if (tunlin_port_mode() != TUNLIN_GPO) {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[2] = (uint8_t)nib2hex(gpo_a_get());
        cat_reply[3] = (uint8_t)nib2hex(gpo_b_get());
        cat_reply[4] = (uint8_t)nib2hex(gpo_c_get());
        cat_reply[5] = (uint8_t)nib2hex(gpo_d_get());
        reply_done(6);
        return;
    }
    if (g_ui.scan_running == 1 || g_ui.mic_key_hold == 1 || g_ui.tune_cycle != 0) {
        cat_error = 1;
        return;
    }
    if (text[2] > '1' || text[3] > '1' || text[4] > '1' || text[5] > '1') {
        cat_error = 1;
        return;
    }
    gpo_a_set((uint8_t)hex2nib(text[2]));
    gpo_b_set((uint8_t)hex2nib(text[3]));
    gpo_c_set((uint8_t)hex2nib(text[4]));
    gpo_d_set((uint8_t)hex2nib(text[5]));
}

/* the radio is busy for the dial-type commands: a tune cycle, a pop-up, the TX lamp, the voice recorder (armed,
 * busy, recording, state), a CW message being sent, the keypad [fact: the same chain in cat_UP 0xFFFA9155,
 * cat_DN 0xFFFA9029, cat_BA 0xFFFA7018] */
static int dial_busy(void)
{
    return g_ui.tune_cycle != 0 || g_ui.dialog_shown == 1 || g_ui.tx_lamp != 0 || g_ui.dvs_armed == 1 ||
           g_ui.dvs_busy == 1 || g_ui.msg_rec_active == 1 || g_ui.dvs_state != 0 || g_ui.ky_send_0 == 1 ||
           g_ui.ky_send_1 == 1 || g_ui.keypad_open == 1;
}

/* cat_UP 0xFFFA9155, cat_DN 0xFFFA9029: one step as the microphone UP / DOWN key (keys 0x348 / 0x34E), which also
 * ends the channel-step mode */
void cat_UP(void)
{
    if (!key_allowed(0x348, 0))
        return;
    if (dial_busy()) {
        cat_error = 1;
        return;
    }
    mic_up_key_press();
    g_ui.ch_step_mode = 0;
}

void cat_DN(void)
{
    if (!key_allowed(0x34E, 0))
        return;
    if (dial_busy()) {
        cat_error = 1;
        return;
    }
    mic_down_key_press();
    g_ui.ch_step_mode = 0;
}

/* cat_BA 0xFFFA7018: VFO-B -> VFO-A, not while busy (also with the message-memory screen open) or VFO-A's tuning
 * is locked */
void cat_BA(void)
{
    if (dial_busy() || g_ui.msgmem_open == 1) {
        cat_error = 1;
        return;
    }
    if (vfo_tune_locked(0) == 1) {
        cat_error = 1;
        return;
    }
    g_opstate.vfo_state_a = VFO_STATE_VFO;
    vfo_rec_copy(&g_opstate.vfo_a, &g_opstate.vfo_b);
    vfo_mark_edited(0);
    vfo_store_back(0);
    g_ui.freq_refresh_req = 1;
}

/* cat_AB 0xFFFA646D: VFO-A -> VFO-B, the mirror of cat_BA (round 6) */
void cat_AB(void)
{
    if (dial_busy() || g_ui.msgmem_open == 1) {
        cat_error = 1;
        return;
    }
    if (vfo_tune_locked(1) == 1) {
        cat_error = 1;
        return;
    }
    g_opstate.vfo_state_b = VFO_STATE_VFO;
    vfo_rec_copy(&g_opstate.vfo_b, &g_opstate.vfo_a);
    vfo_mark_edited(1);
    vfo_store_back(1);
    g_ui.freq_refresh_req = 1;
}

void vm_toggle(void);                           /* V/M: VFO <-> memory (radio-control.md) */

/* cat_AM 0xFFFA6A26, cat_BM 0xFFFA7928: VFO-A / VFO-B -> its memory channel (round 6). Refused for the channels
 * 0x75..0x84. By the VFO state: VFO stores the VFO record; MEMORY TUNE stores the band's current band-stack record;
 * QMB stores it and returns before the VFO updates; any other state (PMS after leaving it with vm_toggle) stores
 * the band-stack record and also loads it into the VFO [fact: the state chain 0xFFFA6A6C..0xFFFA6B3E]. The record
 * pointers are taken before vm_toggle runs. */
static void vfo_to_mem(uint8_t side)
{
    uint8_t ch = side == 0 ? g_mem_hdr.chan_a : g_mem_hdr.chan_b;
    struct vfo_rec *mem = &memch[ch];
    struct vfo_rec *vfo = side == 0 ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    const struct vfo_rec *stack = side == 0 ? &bandstack_a[bandstack_level_a[g_opstate.band_a]][g_opstate.band_a]
                                            : &bandstack_b[bandstack_level_b[g_opstate.band_b]][g_opstate.band_b];
    enum vfo_state state;

    if (ch >= 0x75u && ch <= 0x84u) {
        cat_error = 1;
        return;
    }
    state = side == 0 ? g_opstate.vfo_state_a : g_opstate.vfo_state_b;
    if (state == VFO_STATE_VFO) {
        vfo_rec_copy(mem, vfo);
    } else if (state == VFO_STATE_MEMTUNE) {
        vfo_rec_copy(mem, stack);
    } else if (state == VFO_STATE_QMB) {
        vfo_rec_copy(mem, stack);
        eeprom_save_memch(ch);
        return;
    } else {
        if (state == VFO_STATE_PMS)
            vm_toggle();
        vfo_rec_copy(mem, stack);
        vfo_rec_copy(vfo, stack);
    }
    vfo_mark_edited(g_opstate.active_vfo);
    vfo_store_back(g_opstate.active_vfo);
    g_ui.freq_refresh_req = 1;
    eeprom_save_memch(ch);
}

void cat_AM(void)
{
    vfo_to_mem(0);
}

void cat_BM(void)
{
    vfo_to_mem(1);
}
