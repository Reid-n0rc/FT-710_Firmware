/* The scope CAT command SS of the MAIN image (T24 round 4; docs/code/main/cat.md, docs/cat-commands-primary.md).
 * SS P1 P2 P3..P6: P1 is always 0, P2 the item 0..8, P3..P6 the value; a read answers "SS0" P2 and four value
 * characters [fact: cat_SS 0xFFFAE850, the reply length 10]. */
#include "cat_util.h"
#include "cat_cmds.h"

uint32_t scope_level_ptr(uint32_t freq, uint8_t side);   /* the scope reference-level byte for freq and side */
uint32_t scope_span_ptr(uint32_t freq);                  /* the scope span index for freq */
uint8_t FUN_fffc4f8f(void);                              /* RAM 0x1B4DF: 1 while SS00 = 5 is in force */
void FUN_fffc4f9e(uint8_t on);                           /* sets 0x1B4DF; on = 0 also copies ss00_value to 0x1B4E0 */

#define SS_LEVEL_ZERO 0x3Cu       /* the level byte for 0.0 dB; one step is 0.5 dB [fact: 0xFFFAE9B9, 0xFFFAEF55] */
#define SS_LEVEL_MAX  0x78u       /* +30.0 dB */

/* SS06's value: the display layout (3DSS, scope mode 0..2, waterfall size and expand) as one number 0..11
 * [fact: the read 0xFFFAEA92.., the set 0xFFFAEDE6..] */
static uint8_t ss06_layout(void)
{
    uint8_t mode = g_opstate.scope_mode;

    if (g_opstate.scope_3dss != 0)
        return mode == 0 ? 0 : mode == 1 ? 1 : 2;
    if (mode > 1)
        mode = 2;
    return (uint8_t)(3u + 3u * mode + (g_opstate.wf_size == 0 ? 0u : g_opstate.wf_size == 1 ? 1u : 2u));
}

static void ss06_set(uint8_t v)
{
    if (v <= 2u) {                          /* 3DSS with scope mode v */
        g_opstate.scope_3dss = 1;
        g_opstate.scope_mode = v;
        return;
    }
    if (v > 11u) {
        cat_error = 1;
        return;
    }
    /* 3..11: mode (v - 3) / 3, then expanded, normal or (refused) the third size */
    switch ((v - 3u) % 3u) {
    case 0:
        g_opstate.scope_3dss = 0;
        g_opstate.scope_mode = (uint8_t)((v - 3u) / 3u);
        g_opstate.wf_size = 2;
        g_opstate.scope_expand = 1;
        return;
    case 1:
        g_opstate.scope_3dss = 0;
        g_opstate.scope_mode = (uint8_t)((v - 3u) / 3u);
        g_opstate.wf_size = 1;
        g_opstate.scope_expand = 0;
        return;
    default:                                /* 5, 8, 11 */
        cat_error = 1;
        return;
    }
}

/* the read: cat_reply[4] = P2's value digit, [5..8] the rest */
static int ss_read(uint8_t item)
{
    uint8_t *lv;
    uint8_t v;

    switch (item) {
    case 0:
        cat_reply[4] = (uint8_t)nib2hex(FUN_fffc4f8f() == 1 ? 5u : g_opstate.ss00_value);
        break;
    case 1:
        cat_reply[4] = (uint8_t)nib2hex(g_opstate.ss01_peak);
        break;
    case 2:
        cat_reply[4] = (uint8_t)nib2hex(g_opstate.ss02_marker);
        break;
    case 3:
        cat_reply[4] = (uint8_t)nib2hex(g_opstate.ss03_value);
        break;
    case 4:                                 /* the level as a sign, two digits, '.', 0 or 5 (0.5 dB steps) */
        lv = (uint8_t *)scope_level_ptr(vfo_freq(g_ui.transmitting, 2), g_ui.transmitting);
        if (*lv < SS_LEVEL_ZERO) {
            cat_reply[4] = '-';
            v = (uint8_t)(SS_LEVEL_ZERO - *lv);
        } else {
            cat_reply[4] = '+';
            v = (uint8_t)(*lv - SS_LEVEL_ZERO);
        }
        put_dec(&cat_reply[5], (uint8_t)(v >> 1), 10);
        cat_reply[7] = '.';
        cat_reply[8] = (v & 1u) ? '5' : '0';
        return 1;
    case 5:
        cat_reply[4] = (uint8_t)nib2hex(*(uint8_t *)scope_span_ptr(vfo_freq(0, 2)));
        break;
    case 6:
        cat_reply[4] = (uint8_t)nib2hex(ss06_layout());
        break;
    case 7:                                 /* AF-FFT ATT, oscilloscope RX level, time, TX level */
        cat_reply[4] = (uint8_t)nib2hex(g_opstate.ss07_affft_att);
        cat_reply[5] = (uint8_t)nib2hex(g_opstate.osc_level_rx);
        cat_reply[6] = (uint8_t)nib2hex(g_opstate.osc_time);
        cat_reply[7] = (uint8_t)nib2hex(g_opstate.osc_level_tx);
        cat_reply[8] = '0';
        return 1;
    case 8:
        cat_reply[4] = (uint8_t)nib2hex(g_ui.ss08_value);
        break;
    default:
        cat_error = 1;
        return 0;
    }
    cat_reply[5] = '0';
    cat_reply[6] = '0';
    cat_reply[7] = '0';
    cat_reply[8] = '0';
    return 1;
}

/* SS04 set: P3 sign, P4 P5 = 00..30, P6 = '.', then 0 or 5 */
static void ss04_set(const uint8_t *text)
{
    uint8_t *lv = (uint8_t *)scope_level_ptr(vfo_freq(g_ui.transmitting, 2), g_ui.transmitting);
    uint8_t v;
    char sign;

    if (!get_dec(&text[5], 2, 10, &v))
        return;
    sign = (char)text[4];
    if (v > 30u || text[7] != '.' || (sign != '+' && sign != '-') || (text[8] != '0' && text[8] != '5')) {
        cat_error = 1;
        return;
    }
    if (sign == '-') {
        v = (uint8_t)((30u - v) * 2u);
        if (text[8] == '5')
            v--;
    } else {
        v = (uint8_t)((v + 30u) * 2u);
        if (text[8] == '5')
            v++;
    }
    if (v > SS_LEVEL_MAX) {
        cat_error = 1;
        return;
    }
    *lv = v;
}

/* SS07 set: P3 AF-FFT ATT 0..2, P4 RX level 0..2, P5 time 0..5, P6 TX level 0..2, then '0' */
static void ss07_set(const uint8_t *text)
{
    unsigned i;

    if (text[8] != '0') {
        cat_error = 1;
        return;
    }
    for (i = 4; i < 6; i++) {
        if (text[i] < '0' || text[i] > '2') {
            cat_error = 1;
            return;
        }
    }
    if (text[6] < '0' || text[6] > '5' || text[7] < '0' || text[7] > '2') {
        cat_error = 1;
        return;
    }
    g_opstate.ss07_affft_att = (uint8_t)hex2nib(text[4]);
    g_opstate.osc_level_rx = (uint8_t)hex2nib(text[5]);
    g_opstate.osc_time = (uint8_t)hex2nib(text[6]);
    g_opstate.osc_level_tx = (uint8_t)hex2nib(text[7]);
}

/* cat_SS 0xFFFAE850 */
void cat_SS(const uint8_t *text, uint8_t set)
{
    uint8_t item, v;

    if (text[2] != '0') {
        cat_error = 1;
        return;
    }
    item = (uint8_t)hex2nib(text[3]);
    if (!set) {
        if (ss_read(item)) {
            cat_reply[2] = '0';
            reply_done(9);
        }
        return;
    }
    if (item == 4) {
        ss04_set(text);
        return;
    }
    if (item == 7) {
        ss07_set(text);
        return;
    }
    if (item > 8u) {
        cat_error = 1;
        return;
    }
    /* the single-digit items: P4..P6 and the byte after must be '0' */
    if (text[5] != '0' || text[6] != '0' || text[7] != '0' || text[8] != '0') {
        cat_error = 1;
        return;
    }
    switch (item) {
    case 0:                                 /* 0..4, or 5 = the SS00 override (FUN_fffc4f9e) */
        v = (uint8_t)hex2nib(text[4]);
        if (v < 5u) {
            g_opstate.ss00_value = v;
            FUN_fffc4f9e(0);
        } else if (v == 5u) {
            FUN_fffc4f9e(1);
        } else {
            cat_error = 1;
        }
        return;
    case 1:
        v = (uint8_t)hex2nib(text[4]);
        if (v < 5u)
            g_opstate.ss01_peak = v;
        else
            cat_error = 1;
        return;
    case 2:
        v = (uint8_t)hex2nib(text[4]);
        if (v < 2u)
            g_opstate.ss02_marker = v;
        else
            cat_error = 1;
        return;
    case 3:
        v = (uint8_t)hex2nib(text[4]);
        if (v < 11u)
            g_opstate.ss03_value = v;
        else
            cat_error = 1;
        return;
    case 5: {                               /* span 0..9 of the band of VFO 0's frequency */
        uint8_t *span = (uint8_t *)scope_span_ptr(vfo_freq(0, 2));

        v = (uint8_t)hex2nib(text[4]);
        if (v < 10u)
            *span = v;
        else
            cat_error = 1;
        return;
    }
    case 6:
        ss06_set((uint8_t)hex2nib(text[4]));
        return;
    default:                                /* 8 */
        v = (uint8_t)hex2nib(text[4]);
        if (v < 2u)
            g_ui.ss08_value = v;
        else
            cat_error = 1;
        return;
    }
}
