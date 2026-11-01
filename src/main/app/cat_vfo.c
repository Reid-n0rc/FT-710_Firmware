/* The CAT commands of the MAIN image that read or set a VFO's frequency and state (T24 round 4; docs/code/main/
 * cat.md, radio-control.md): FA / FB, IF / OI, CF, MR, MW, MC. */
#include "cat_util.h"
#include "cat_cmds.h"

uint8_t freq_in_range(uint32_t hz);                      /* 1 = a frequency the radio tunes */
void vfo_mem_to_memtune(uint8_t side);                   /* memory channel -> memory tune (the VFO leaves MEMORY) */
uint32_t freq_clamp(uint8_t side, uint32_t hz);          /* sets g_ui.freq_rejected for a refused frequency */

/* u32 as 9 decimal digits, as the image prints it: each digit (v / place) through nib2hex [fact: cat_FA_FB
 * 0xFFFA9A21..0xFFFA9A4A] */
static void put_dec32(uint8_t *at, uint32_t v, uint32_t div)
{
    for (; div != 0; div /= 10u) {
        uint32_t n = v / div;

        v -= n * div;
        *at++ = (uint8_t)nib2hex((uint8_t)n);
    }
}

static int get_dec32(const uint8_t *p, unsigned n, uint32_t div, uint32_t *out)
{
    uint32_t v = 0;
    unsigned i;

    for (i = 0; i < n; i++) {
        if (p[i] < '0' || p[i] > '9') {
            cat_error = 1;
            return 0;
        }
        v += (uint32_t)(p[i] & 0x0Fu) * div;
        div /= 10u;
    }
    *out = v;
    return 1;
}

extern const uint8_t cat_mode_codes[];        /* 0xFFF806D0: the CAT mode character per mode index */
extern const uint8_t cat_vfo_state_codes[];   /* 0xFFF806DF: the CAT P7 character per VFO state */
extern const uint8_t cat_pms_names[][3];      /* 0xFFF806E9: names of the channels from 99 on */

/* the channel as three characters: 001..099, or the name of channel 99 + n [fact: add #-99, cat_IF_OI 0xFFFAA458;
 * cat_MR, cat_MC] */
static void put_channel(uint8_t *at, uint8_t ch)
{
    if (ch < 99u) {
        put_dec(at, (uint8_t)(ch + 1u), 100);
    } else {
        const uint8_t *nm = cat_pms_names[(uint8_t)(ch - 99u)];

        at[2] = nm[2];
        at[0] = nm[0];
        at[1] = nm[1];
    }
}

/* the clarifier offset (s16, big-endian) as sign and four digits */
static void put_clar_offset(uint8_t *at, const struct vfo_rec *r)
{
    uint16_t off = be16(r->clar_offset_be);

    if (r->clar_offset_be[0] & 0x80u) {
        at[0] = '-';
        off = (uint16_t)(~off + 1u);
    } else {
        at[0] = '+';
    }
    put_dec16(&at[1], off, 1000);
}

/* P6..P10 of IF / OI / MR at cat_reply[21..26]: mode, VFO state, tone mode (1 -> '2', 2 -> '1', else '0'), "00",
 * repeater shift (0 minus -> '2', 2 plus -> '1', else '0') */
static void put_info_tail(const struct vfo_rec *r, uint8_t state)
{
    uint8_t v;

    cat_reply[21] = cat_mode_codes[r->mode & 0x0Fu];
    cat_reply[22] = cat_vfo_state_codes[state];
    v = (uint8_t)((r->flags3 & 0x38u) >> 3);
    cat_reply[23] = v == 1 ? '2' : v == 2 ? '1' : '0';
    cat_reply[25] = '0';
    cat_reply[24] = '0';
    v = (uint8_t)((r->flags2 & 0x0Cu) >> 2);
    cat_reply[26] = v == 0 ? '2' : v == 2 ? '1' : '0';
}

/* cat_IF_OI 0xFFFAA39C: IF (VFO-A) / OI (VFO-B) information, 28 bytes: P1 channel (3), P2 frequency (9), P3 clarifier
 * offset (sign + 4), P4 RX / P5 TX clarifier, P6 mode, P7 VFO state, P8 tone mode, P9 "00", P10 repeater shift */
void cat_IF_OI(uint8_t opposite)
{
    const struct vfo_rec *r;
    uint8_t ch, state, clar;

    if (opposite == 0) {
        r = &g_opstate.vfo_a;
        ch = g_mem_hdr.chan_a;
        state = g_opstate.vfo_state_a;
        clar = g_ui.clar_flags_a;
    } else {
        r = &g_opstate.vfo_b;
        ch = g_mem_hdr.chan_b;
        state = g_opstate.vfo_state_b;
        clar = g_ui.clar_flags_b;
    }
    put_channel(&cat_reply[2], ch);
    if (state == VFO_STATE_VFO || state == VFO_STATE_MEMTUNE || state == VFO_STATE_QMB) {
        cat_reply[2] = '0';
        cat_reply[3] = '0';
        cat_reply[4] = '0';
    }
    put_dec32(&cat_reply[5], vfo_freq(0, opposite), 100000000u);
    put_clar_offset(&cat_reply[14], r);
    switch (clar) {                         /* bit 0 RX, bit 1 TX; other values leave P4 P5 as they are */
    case 0:
        cat_reply[19] = '0';
        cat_reply[20] = '0';
        break;
    case 1:
        cat_reply[19] = '1';
        cat_reply[20] = '0';
        break;
    case 2:
        cat_reply[19] = '0';
        cat_reply[20] = '1';
        break;
    case 3:
        cat_reply[19] = '1';
        cat_reply[20] = '1';
        break;
    default:
        break;
    }
    put_info_tail(r, state);
    reply_done(27);
}

int strncmp(const char *a, const char *b, size_t n);      /* the image's C library (no stop at a shared NUL) */
uint8_t memch_valid(uint8_t ch, uint8_t **rec);            /* 1 = the channel holds a memory */

/* cat_MR 0xFFFABEA5: MR P1 = memory channel read: 001..099 or a name (P1L .. EMG, 34 names from channel 99 on; upper
 * case first); the answer is IF's layout from the channel record, with the active VFO's state as P7 and the
 * record's clarifier flags (flags1 bits 4 / 3); an empty channel or a frequency of 0 is refused. */
void cat_MR(const uint8_t *ctext, uint8_t set)
{
    uint8_t *text = (uint8_t *)ctext;       /* the ring slot; upper-cased in place */
    const struct vfo_rec *r;
    uint8_t *rec;
    uint8_t ch = 0, n, k;
    uint32_t hz = 0;

    (void)set;
    toupper_inplace((char *)&text[2]);
    toupper_inplace((char *)&text[3]);
    toupper_inplace((char *)&text[4]);
    if (text[2] == '0') {
        if (!get_dec(&text[2], 3, 100, &n))
            return;
        /* 001..099; for 000 or above 099 the image keeps an uninitialised stack byte as the channel [fact: no store
         * on that path, 0xFFFABEA5..]; 0 here, which is what the check's zeroed stack gives the original */
        if (n != 0 && n <= 99u)
            ch = (uint8_t)(n - 1u);
    } else {
        for (k = 0; k < 0x22u; k++) {
            if (strncmp((const char *)cat_pms_names[k], (const char *)&text[2], 3) == 0) {
                ch = (uint8_t)(k + 99u);
                break;
            }
        }
        if (ch < 99u) {
            cat_error = 1;
            return;
        }
    }
    if (!memch_valid(ch, &rec)) {
        cat_error = 1;
        return;
    }
    r = &memch[ch];
    put_channel(&cat_reply[2], ch);
    for (k = 0; k < 4; k++)
        hz = hz << 8 | r->freq_be[k];
    if (hz == 0) {
        cat_error = 1;
        return;
    }
    put_dec32(&cat_reply[5], hz, 100000000u);
    put_clar_offset(&cat_reply[14], r);
    cat_reply[19] = (r->flags1 & 0x10u) ? '1' : '0';
    cat_reply[20] = (r->flags1 & 0x08u) ? '1' : '0';
    put_info_tail(r, g_opstate.active_vfo == VFO_A ? g_opstate.vfo_state_a : g_opstate.vfo_state_b);
    reply_done(27);
}

/* cat_CF 0xFFFA7FA1: CF P1 P2 P3 P4.. = clarifier of the active (P1 = 0) or the other VFO (P1 = 1); P2 is not
 * checked. P3 = 0: P4 RX and P5 TX on/off ("000" after them), kept in the UI byte (bit 0 RX, bit 1 TX) and in record
 * flags1 bits 4 / 3; P3 = 1: the offset as sign and four digits (s16, Hz, big-endian in the record). A set is
 * refused by the CLAR key's filter (0x306), in SPLIT and while the VFO is locked. */
void cat_CF(const uint8_t *text, uint8_t set)
{
    struct vfo_rec *r;
    uint8_t *clar;
    uint8_t p3, ui, rf;
    uint16_t off;

    if (text[2] == '0') {
        r = g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_a : &g_opstate.vfo_b;
        clar = g_opstate.active_vfo == VFO_A ? &g_ui.clar_flags_a : &g_ui.clar_flags_b;
    } else if (text[2] == '1') {
        r = g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_b : &g_opstate.vfo_a;
        clar = g_opstate.active_vfo == VFO_A ? &g_ui.clar_flags_b : &g_ui.clar_flags_a;
    } else {
        cat_error = 1;
        return;
    }
    ui = *clar;
    p3 = (uint8_t)hex2nib(text[4]);
    if (p3 > 1u) {
        cat_error = 1;
        return;
    }
    if (!set) {
        cat_reply[3] = '0';
        cat_reply[4] = (uint8_t)nib2hex(p3);
        if (p3 == 0) {
            switch (ui) {                   /* other values leave P4 P5 as they are */
            case 0:
                cat_reply[5] = '0';
                cat_reply[6] = '0';
                break;
            case 1:
                cat_reply[5] = '1';
                cat_reply[6] = '0';
                break;
            case 2:
                cat_reply[5] = '0';
                cat_reply[6] = '1';
                break;
            case 3:
                cat_reply[5] = '1';
                cat_reply[6] = '1';
                break;
            default:
                break;
            }
            cat_reply[7] = '0';
            cat_reply[8] = '0';
            cat_reply[9] = '0';
        } else {
            off = be16(r->clar_offset_be);
            if (r->clar_offset_be[0] & 0x80u) {
                cat_reply[5] = '-';
                off = (uint16_t)(~off + 1u);
            } else {
                cat_reply[5] = '+';
            }
            put_dec16(&cat_reply[6], off, 1000);
        }
        reply_done(10);
        return;
    }
    if (!key_allowed(0x306, 0))
        return;
    if (g_opstate.split_on == 1 || vfo_tune_locked(g_opstate.active_vfo) == 1) {
        cat_error = 1;
        return;
    }
    if (p3 == 0) {
        if (text[7] != '0' || text[8] != '0' || text[9] != '0') {
            cat_error = 1;
            return;
        }
        ui = 0;
        rf = 0;
        if (text[5] == '1') {
            ui = 1;
            rf = 0x10;
        } else if (text[5] != '0') {
            cat_error = 1;
            return;
        }
        if (text[6] == '1') {
            ui |= 2u;
            rf |= 0x08u;
        } else if (text[6] != '0') {
            cat_error = 1;
            return;
        }
        *clar = ui;
        r->flags1 &= 0xE7u;
        r->flags1 |= rf;
    } else {
        if (!get_dec16(&text[6], 4, 1000, &off))
            return;
        if (text[5] == '-') {
            off = (uint16_t)(~off + 1u);
        } else if (text[5] != '+') {
            cat_error = 1;
            return;
        }
        put_be16(r->clar_offset_be, off);
    }
    g_ui.freq_refresh_req = 1;
}

/* cat_FA_FB 0xFFFA99BD: FA / FB P1 = the frequency of VFO-A / VFO-B in Hz, 9 digits. A read gives the TX frequency
 * while transmitting on the active VFO. A set is refused while a dialog or the keypad is open, outside the bands,
 * while the VFO is locked and when freq_clamp refuses it; in SPLIT both VFO states are taken from the saved VFO-A
 * state for the tune and put back afterwards [fact: 0xFFFA9B0C..0xFFFA9C8F]. */
void cat_FA_FB(const uint8_t *text, uint8_t set, uint8_t vfo_b)
{
    struct vfo_rec *rec;
    uint8_t state_a, state_b;
    uint32_t hz;
    unsigned i;

    if (!set) {
        hz = vfo_b == 0 ? g_ui.freq_a : g_ui.freq_b;
        if (g_ui.transmitting == 1 && vfo_b == g_opstate.active_vfo)
            hz = g_ui.freq_tx;
        put_dec32(&cat_reply[2], hz, 100000000u);
        reply_done(11);
        return;
    }
    if (g_ui.dialog_shown == 1 || g_ui.keypad_open == 1) {
        cat_error = 1;
        return;
    }
    if (!get_dec32(&text[2], 9, 100000000u, &hz))
        return;
    if (freq_in_range(hz) == 0) {
        cat_error = 1;
        return;
    }
    state_a = g_opstate.vfo_state_a;
    state_b = g_opstate.vfo_state_b;
    if (g_opstate.split_on == 1) {
        g_opstate.vfo_state_a = g_opstate.split_saved_vfo_state_a;
        g_opstate.vfo_state_b = g_opstate.split_saved_vfo_state_a;
    }
    if (vfo_tune_locked(vfo_b) == 1)
        goto refused;
    if (vfo_b == 0) {
        if (g_opstate.vfo_state_a == VFO_STATE_MEMORY)
            vfo_mem_to_memtune(0);
    } else if (g_opstate.vfo_state_b == VFO_STATE_MEMORY) {
        vfo_mem_to_memtune(vfo_b);
    }
    g_ui.freq_clamp_result = freq_clamp(vfo_b, hz);
    if (g_ui.freq_rejected == 1)
        goto refused;
    if (g_opstate.split_on != 1) {          /* without SPLIT the states stay as the tune left them */
        state_a = g_opstate.vfo_state_a;
        state_b = g_opstate.vfo_state_b;
    }
    g_opstate.vfo_state_b = state_b;
    g_opstate.vfo_state_a = state_a;
    rec = vfo_b == 0 ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    for (i = 0; i < 4; i++)
        rec->freq_be[i] = (uint8_t)(hz >> (8u * (3u - i)));
    rec->clar_offset_be[0] = 0;
    rec->clar_offset_be[1] = 0;
    g_ui.freq_refresh_req = 1;
    vfo_mark_edited(vfo_b);
    vfo_store_back(vfo_b);
    return;
refused:
    g_opstate.vfo_state_a = state_a;
    g_opstate.vfo_state_b = state_b;
    cat_error = 1;
}

void memch_mark_used(uint8_t ch);

/* the channel of MR / MW text[2..4]: 001..099 or one of the 34 names (after toupper); 0xFF = refused */
static uint8_t parse_channel(const uint8_t *text)
{
    uint8_t n, k;

    if (text[2] == '0') {
        if (!get_dec(&text[2], 3, 100, &n))
            return 0xFF;
        if (n == 0 || n > 99u) {
            cat_error = 1;
            return 0xFF;
        }
        return (uint8_t)(n - 1u);
    }
    for (k = 0; k < 0x22u; k++)
        if (strncmp((const char *)cat_pms_names[k], (const char *)&text[2], 3) == 0)
            return (uint8_t)(k + 99u);
    cat_error = 1;
    return 0xFF;
}

/* cat_MW 0xFFFAC534: MW P1..P10 = memory channel write, IF's layout: channel, frequency (9 digits, in the bands),
 * clarifier (sign and four digits, checked but not stored: the offset and both clarifier flags are cleared), P4 P5
 * 0/1, mode (a CAT mode character), P7 '1', tone mode, "00", repeater shift. The channel becomes the active VFO's
 * memory channel before the rest is checked [fact: 0xFFFAC68A]. */
void cat_MW(const uint8_t *ctext, uint8_t set)
{
    uint8_t *text = (uint8_t *)ctext;       /* the ring slot; upper-cased in place */
    uint8_t side, ch, mode, tone, shift;
    struct vfo_rec *r;
    uint32_t hz;
    unsigned i;

    (void)set;
    toupper_inplace((char *)&text[2]);
    toupper_inplace((char *)&text[3]);
    toupper_inplace((char *)&text[4]);
    side = g_opstate.active_vfo;
    ch = parse_channel(text);
    if (ch == 0xFF)
        return;
    if (ch > 0x75u) {                       /* the names past EMG */
        cat_error = 1;
        return;
    }
    if (side == VFO_A)
        g_mem_hdr.chan_a = ch;
    else
        g_mem_hdr.chan_b = ch;
    r = &memch[ch];
    if (!get_dec32(&text[5], 9, 100000000u, &hz))
        return;
    if (freq_in_range(hz) == 0) {
        cat_error = 1;
        return;
    }
    for (i = 15; i < 19; i++) {
        if (text[i] < '0' || text[i] > '9') {
            cat_error = 1;
            return;
        }
    }
    if ((text[14] != '-' && text[14] != '+') || (text[19] != '0' && text[19] != '1') ||
        (text[20] != '0' && text[20] != '1')) {
        cat_error = 1;
        return;
    }
    for (mode = 0; mode <= MODE_PSK; mode++)
        if (text[21] == cat_mode_codes[mode])
            break;
    if (mode > MODE_PSK || text[22] != '1') {
        cat_error = 1;
        return;
    }
    switch (text[23]) {                     /* '2' -> tone mode 1, '1' -> 2, '0' -> 0 */
    case '2':
        tone = 1;
        break;
    case '1':
        tone = 2;
        break;
    case '0':
        tone = 0;
        break;
    default:
        cat_error = 1;
        return;
    }
    if (text[24] != '0' || text[25] != '0') {
        cat_error = 1;
        return;
    }
    switch (text[26]) {                     /* '2' -> shift 0 (minus), '1' -> 2 (plus), '0' -> 1 (simplex) */
    case '2':
        shift = 0;
        break;
    case '1':
        shift = 2;
        break;
    case '0':
        shift = 1;
        break;
    default:
        cat_error = 1;
        return;
    }
    for (i = 0; i < 4; i++)
        r->freq_be[i] = (uint8_t)(hz >> (8u * (3u - i)));
    r->clar_offset_be[0] = 0;
    r->clar_offset_be[1] = 0;
    r->flags1 &= 0xE7u;
    r->mode = (uint8_t)((r->mode & 0xF0u) | mode);
    r->flags3 = (uint8_t)((r->flags3 & 0xC7u) | tone << 3);
    r->flags2 = (uint8_t)((r->flags2 & 0xF3u) | shift << 2);
    memch_mark_used(ch);
    eeprom_save_memch(ch);
    vfo_mark_edited(side);
    vfo_store_back(side);
}

void vm_toggle(void);                         /* the V/M key: VFO <-> memory */

/* the busy states in which VM is refused (scan, MIC key, tune cycle, dialog, TX lamp, DVS / message, KY sending,
 * keypad) [fact: the compare chain of cat_VM 0xFFFAFADB] */
static int vm_busy(void)
{
    return g_ui.scan_running == 1 || g_ui.mic_key_hold == 1 || g_ui.tune_cycle != 0 || g_ui.dialog_shown == 1 ||
           g_ui.tx_lamp != 0 || g_ui.dvs_armed == 1 || g_ui.dvs_busy == 1 || g_ui.msg_rec_active == 1 ||
           g_ui.dvs_state != 0 || g_ui.ky_send_0 == 1 || g_ui.ky_send_1 == 1 || g_ui.keypad_open == 1;
}

/* cat_VM 0xFFFAFADB: "VM;" = the V/M key; VM0 reads the active VFO's kind as two hex digits (00 VFO, 10 memory tune,
 * 11 memory 001..099, 20 PMS, 21 P1L..P9U, 51 60 m channels, 91 EMG); "VM000;" returns to the VFO (one V/M press,
 * and a second when the first did not reach the VFO). Gated by the V/M key's filter (0x309) and vm_busy. */
void cat_VM(const uint8_t *text, uint16_t len)
{
    uint8_t state, ch, code;

    if (len != 3 && text[2] != '0') {
        cat_error = 1;
        return;
    }
    if (g_opstate.active_vfo == VFO_A) {
        state = g_opstate.vfo_state_a;
        ch = g_mem_hdr.chan_a;
    } else {
        state = g_opstate.vfo_state_b;
        ch = g_mem_hdr.chan_b;
    }
    if (len == 4) {
        cat_reply[2] = '0';
        if (state == VFO_STATE_MEMORY)
            code = ch >= 0x84u ? 0x91 : ch >= 0x75u ? 0x51 : ch >= 99u ? 0x21 : 0x11;
        else if (state == VFO_STATE_MEMTUNE)
            code = 0x10;
        else if (state == VFO_STATE_PMS)
            code = 0x20;
        else
            code = 0;
        byte2hex((char *)&cat_reply[3], code);
        reply_done(5);
        return;
    }
    if (!key_allowed(0x309, 0))
        return;
    if (vm_busy()) {
        cat_error = 1;
        return;
    }
    if (len == 3) {
        vm_toggle();
        return;
    }
    if (text[3] != '0' || text[4] != '0') {
        cat_error = 1;
        return;
    }
    if (state != VFO_STATE_VFO) {
        vm_toggle();
        state = g_opstate.active_vfo == VFO_A ? g_opstate.vfo_state_a : g_opstate.vfo_state_b;
        if (state != VFO_STATE_VFO)
            vm_toggle();
    }
}

uint8_t dest_has_5mhz_channels(void);        /* 1 = the destination has the 60 m channels */
uint8_t memch_dest_blocked(uint8_t ch);       /* 1 = the destination does not allow channel ch */

static void rec_copy(struct vfo_rec *dst, const struct vfo_rec *src)
{
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    unsigned i;

    for (i = 0; i < sizeof *dst; i++)
        d[i] = s[i];
}

/* cat_MC 0xFFFAB4F3: MC P1 = the active VFO's memory channel (001..099 or a name). A set (not while the TX lamp is
 * on) recalls the channel: the 60 m channels only where the destination has them, EMG only with EX030406
 * EMERGENCY FREQ TX, an empty channel is refused. The VFO's record is kept as its memory-tune record, the channel
 * record is copied into it, and the state becomes MEMORY; the save is of channel 1 whatever the channel
 * [fact: eeprom_save_memch(1), 0xFFFAB7BD..0xFFFAB7BF]. */
void cat_MC(const uint8_t *ctext, uint8_t set)
{
    uint8_t *text = (uint8_t *)ctext;       /* the ring slot; upper-cased in place */
    struct vfo_rec *cur = (struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t side, ch;
    uint8_t *used;

    toupper_inplace((char *)&text[2]);
    toupper_inplace((char *)&text[3]);
    toupper_inplace((char *)&text[4]);
    side = g_opstate.active_vfo;
    if (!set) {
        put_channel(&cat_reply[2], side == VFO_A ? g_mem_hdr.chan_a : g_mem_hdr.chan_b);
        reply_done(5);
        return;
    }
    if (g_ui.tx_lamp != 0) {
        cat_error = 1;
        return;
    }
    ch = parse_channel(text);
    if (ch == 0xFF)
        return;
    if (ch > 0x74u && ch < 0x84u) {         /* the 60 m channels */
        if (dest_has_5mhz_channels() != 1 || memch_dest_blocked(ch) == 1) {
            cat_error = 1;
            return;
        }
    }
    if (g_opstate.ex030406_emergency_freq_tx == 0 && ch == 0x84u) {
        cat_error = 1;
        return;
    }
    if (!memch_valid(ch, &used)) {
        cat_error = 1;
        return;
    }
    if (side == VFO_A) {
        g_mem_hdr.chan_a = ch;
        g_opstate.vfo_state_a = VFO_STATE_MEMORY;
        rec_copy(&g_opstate.memtune_a, cur);
    } else {
        g_mem_hdr.chan_b = ch;
        g_opstate.vfo_state_b = VFO_STATE_MEMORY;
        rec_copy(&g_opstate.memtune_b, cur);
    }
    rec_copy(cur, &memch[ch]);
    eeprom_save_memch(1);
    g_ui.freq_refresh_req = 1;
}
