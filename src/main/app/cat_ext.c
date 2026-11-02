/* The extended CAT commands of the MAIN image (cat_ext_mnemonics 0xFFF806BC, called by cat_dispatch_ext), recreated
 * for T24 round 6 (docs/code/main/cat.md, docs/cat-undocumented.md). */
#include "cat_util.h"
#include "cat_cmds.h"

uint16_t hex2word(const char *s);               /* 4 hex digits */
uint8_t hex2byte(const char *s);                /* 2 hex digits */
uint16_t dest_code_get(void);                   /* the region (destination) code, EEPROM 0x010F */
void dest_code_set(uint16_t code);

/* the codes a JP set stores in place of the one sent [fact: the compare chain 0xFFFA5600..0xFFFA5662]; the first
 * of each pair is also a code dest_code_get can return (displink_rx_F0_hello's 0xA983 / 0xB5A7 / 0xD950 / 0xA4C5
 * checks [inference]) */
static uint16_t jp_code_alias(uint16_t code)
{
    switch (code) {
    case 0x306F:
        return 0xD32D;
    case 0xB5A7:
        return 0xA983;
    case 0x9CF7:
        return 0x7753;
    case 0xA4C5:
        return 0xD950;
    case 0x50E2:
        return 0x315B;
    default:
        return code;
    }
}

/* cat_ext_JP 0xFFFA556B: JP0710 + the region code (4 hex digits), its complement (4) and the stamp of the EEPROM
 * header (5 bytes, 10 hex digits); a set (JP0710 + code + complement) checks the complement, maps the code
 * (jp_code_alias), stamps the header with the clock and stores the code. P1 must be 0710 */
void cat_ext_JP(const uint8_t *text, uint8_t set)
{
    uint8_t hi, lo, nhi, nlo, i;
    uint16_t code;

    if (hex2word((const char *)&text[2]) != 0x0710) {
        cat_error = 1;
        return;
    }
    if (set) {
        hi = hex2byte((const char *)&text[6]);
        lo = hex2byte((const char *)&text[8]);
        nhi = (uint8_t)~hex2byte((const char *)&text[10]);
        nlo = (uint8_t)~hex2byte((const char *)&text[12]);
        if (hi != nhi || lo != nlo) {
            cat_error = 1;
            return;
        }
        code = jp_code_alias((uint16_t)(hi << 8 | lo));
        g_ee_hdr.stamp[0] = g_ui.rtc_yy;
        g_ee_hdr.stamp[1] = g_ui.rtc_mm;
        g_ee_hdr.stamp[2] = g_ui.rtc_dd;
        g_ee_hdr.stamp[3] = g_ui.rtc_hh;
        g_ee_hdr.stamp[4] = g_ui.rtc_min;
        dest_code_set(code);
        return;
    }
    code = dest_code_get();
    hi = (uint8_t)(code >> 8);
    lo = (uint8_t)code;
    byte2hex((char *)&cat_reply[6], hi);
    byte2hex((char *)&cat_reply[8], lo);
    byte2hex((char *)&cat_reply[10], (uint8_t)~hi);
    byte2hex((char *)&cat_reply[12], (uint8_t)~lo);
    for (i = 0; i < 5u; i++)
        byte2hex((char *)&cat_reply[14 + 2 * i], g_ee_hdr.stamp[i]);
    reply_done(24);
}

void enc2_step(int8_t steps);                   /* the second encoder turned by n steps (ui-keys.md) */
void enc3_step(int8_t steps);                   /* the third (FUNC) encoder */

/* three decimal digits at p, through hex2nib; 0 with cat_error at a non-digit */
static int eo_digits(const uint8_t *p, uint16_t *out)
{
    uint16_t v = 0;
    uint8_t div = 100, i;

    for (i = 0; i < 3u; i++) {
        if (p[i] < '0' || p[i] > '9') {
            cat_error = 1;
            return 0;
        }
        v = (uint16_t)((uint8_t)hex2nib(p[i]) * div + v);
        div = (uint8_t)(div / 10u);
    }
    *out = v;
    return 1;
}

/* the encoder form of EO: P3 '+' or '-' and up to 127 steps (another P3 turns nothing); 0 with cat_error when the
 * count is out of range */
static int eo_encoder(char sign, uint8_t n, void (*step)(int8_t))
{
    if (sign == '+') {
        if (n > 0x7Fu) {
            cat_error = 1;
            return 0;
        }
        step((int8_t)n);
    } else if (sign == '-') {
        if ((int8_t)-n > 0) {
            cat_error = 1;
            return 0;
        }
        step((int8_t)-n);
    }
    return 1;
}

/* cat_ext_EO 0xFFFA5C90: EO P1 P2 P3 P4 P5..P7 (EO is in the 2211-A CAT manual only): close the pop-ups, then
 * P2 0: move VFO 0's frequency by P5..P7 x 1 Hz / 1 kHz / 1 MHz (P4 '0' / '1' / '2') up (P3 '+') or down ('-'),
 * clamped to 30 kHz .. 75 MHz; P2 1 / 2: turn encoder 2 / 3 by P5..P7 steps. P1 must be 0..2. A P4 other than
 * 0..2 moves by an undefined amount: the image adds an uninitialised stack word [fact: 0xFFFA5D7C..0xFFFA5DAC] */
void cat_ext_EO(const uint8_t *text, uint8_t set)
{
    uint8_t *rec = vfo_rec_ptr(0);
    uint32_t hz, delta = 0;
    uint16_t n;
    uint8_t i;

    if ((uint8_t)hex2nib(text[2]) > 2u) {
        cat_error = 1;
        return;
    }
    g_ui.numentry_mode = 0;
    g_ui.dialog_shown = 0;
    g_ui.dl_req_40 = 0;
    g_ui.zz_align_mode = 0;
    g_ui.playlist_open = 0;
    g_ui.msgmem_open = 0;
    g_ui.dl_req_37 = 0;
    g_ui.memlist_open = 0;
    if (text[3] == '0') {
        hz = vfo_freq(0, 2);
        if (!eo_digits(&text[6], &n))
            return;
        if (text[5] == '0')
            delta = n;
        else if (text[5] == '1')
            delta = (uint32_t)n * 1000u;
        else if (text[5] == '2')
            delta = (uint32_t)n * 1000000u;
        if (text[4] == '+') {
            hz += delta;
        } else if (text[4] == '-') {
            hz = hz < delta ? 0 : hz - delta;
        } else {
            cat_error = 1;
            return;
        }
        if (hz < 30000u)
            hz = 30000u;
        else if (hz > 75000000u)
            hz = 75000000u;
        for (i = 0; i < 4u; i++)                /* freq_be, big-endian */
            rec[0x4A + i] = (uint8_t)(hz >> (8u * (3u - i)));
    } else if (text[3] == '1') {
        if (!eo_digits(&text[6], &n) || !eo_encoder((char)text[4], (uint8_t)n, enc2_step))
            return;
    } else if (text[3] == '2') {
        if (!eo_digits(&text[6], &n))
            return;
        g_ui.numentry_mode = 0;
        g_ui.zz_align_mode = 0;
        g_ui.func_panel_open = 1;
        if (!eo_encoder((char)text[4], (uint8_t)n, enc3_step))
            return;
    }
    g_ui.freq_refresh_req = 1;
}
