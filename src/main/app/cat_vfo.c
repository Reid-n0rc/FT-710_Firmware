/* The CAT commands of the MAIN image that read or set a VFO's frequency and state (T24 round 4; docs/code/main/
 * cat.md, radio-control.md): FA / FB. */
#include "cat_util.h"
#include "cat_cmds.h"

uint8_t freq_in_range(uint32_t hz);                      /* 1 = a frequency the radio tunes */
void vfo_mem_to_memtune(uint8_t side);                   /* memory channel -> memory tune (the VFO leaves MEMORY) */
uint32_t freq_clamp(uint8_t side, uint32_t hz);          /* sets g_ui.freq_rejected for a refused frequency */

/* u32 as 9 decimal digits, as the image prints it: each digit (v / place) through nib2hex [fact: cat_FA_FB
 * 0xFFFA99E6..] */
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

/* cat_IF_OI 0xFFFAA39C: IF (VFO-A) / OI (VFO-B) information, 28 bytes: P1 channel (3), P2 frequency (9), P3 clarifier
 * offset (sign + 4), P4 RX / P5 TX clarifier, P6 mode, P7 VFO state, P8 tone mode, P9 "00", P10 repeater shift */
void cat_IF_OI(uint8_t opposite)
{
    const struct vfo_rec *r;
    uint8_t ch, state, clar;
    uint16_t off;

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
    if (ch < 99u) {                         /* 001..099 */
        put_dec(&cat_reply[2], (uint8_t)(ch + 1u), 100);
    } else {                                /* the name of channel 99 + n, n in 8 bits [fact: add #0x9D, 0xFFFAA44E] */
        const uint8_t *nm = cat_pms_names[(uint8_t)(ch + 0x9Du)];

        cat_reply[4] = nm[2];
        cat_reply[2] = nm[0];
        cat_reply[3] = nm[1];
    }
    if (state == VFO_STATE_VFO || state == VFO_STATE_MEMTUNE || state == VFO_STATE_QMB) {
        cat_reply[2] = '0';
        cat_reply[3] = '0';
        cat_reply[4] = '0';
    }
    put_dec32(&cat_reply[5], vfo_freq(0, opposite), 100000000u);
    off = be16(r->clar_offset_be);
    if (r->clar_offset_be[0] & 0x80u) {     /* s16, printed as sign and magnitude */
        cat_reply[14] = '-';
        off = (uint16_t)(~off + 1u);
    } else {
        cat_reply[14] = '+';
    }
    put_dec16(&cat_reply[15], off, 1000);
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
    cat_reply[21] = cat_mode_codes[r->mode & 0x0Fu];
    cat_reply[22] = cat_vfo_state_codes[state];
    switch ((r->flags3 & 0x38u) >> 3) {     /* tone mode 1 -> '2', 2 -> '1', else '0' */
    case 1:
        cat_reply[23] = '2';
        break;
    case 2:
        cat_reply[23] = '1';
        break;
    default:
        cat_reply[23] = '0';
        break;
    }
    cat_reply[25] = '0';
    cat_reply[24] = '0';
    switch ((r->flags2 & 0x0Cu) >> 2) {     /* repeater shift 0 minus -> '2', 2 plus -> '1', else '0' */
    case 0:
        cat_reply[26] = '2';
        break;
    case 2:
        cat_reply[26] = '1';
        break;
    default:
        cat_reply[26] = '0';
        break;
    }
    reply_done(27);
}

/* cat_FA_FB 0xFFFA99BD: FA / FB P1 = the frequency of VFO-A / VFO-B in Hz, 9 digits. A read gives the TX frequency
 * while transmitting on the active VFO. A set is refused while a dialog or the keypad is open, outside the bands,
 * while the VFO is locked and when freq_clamp refuses it; in SPLIT both VFO states are taken from the saved VFO-A
 * state for the tune and put back afterwards [fact: 0xFFFA9AB6..0xFFFA9C8E]. */
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
