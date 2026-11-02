/* CAT auto information for the EX menu, recreated for T24 (docs/code/main/cat-ai.md).
 *
 * With AI on, cat_ai_poll asks cat_ai_ex for a changed EX-menu setting. cat_ai_ex_scan calls the 296 detectors of
 * the table ai_ex_detectors (0xFFF8E1A0) in turn until one sets the reply length ai_ex_len; the reply is then
 * "EX" + the item's 6-digit ID (ai_ex_ids, 0xFFF872B1, 8 characters each) + the value + ';' [fact: cat_ai_ex_scan
 * 0xFFFE6D7A]. Each detector compares one setting with its shadow byte and, on a change, keeps the new value and
 * formats it after the ID [fact: the detectors 0xFFFE6E3A..0xFFFEC46B].
 *
 * The detectors come in a few shapes, written once each as a macro below; the items with a shape of their own
 * follow the list. The shadow bytes form one block from 0x1B29A, one byte per detector in table order, with gaps
 * where an item keeps a 16-bit shadow elsewhere (0x1FF14, 0x1FF16, 0x1FF18) or a 12-byte one (MY CALL)
 * [fact: the addresses in the detectors]. */
#include <stdint.h>
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

#define AI_EX_DIGIT_LEN 10u     /* "EX" + ID + one digit + ';' */
#define AI_EX_TEXT_LEN  21u     /* "EX" + ID + 12 characters + ';' */
#define AI_EX_TEXT      12u

/* ai_ex_fmt_u8 0xFFFEC2E5: a byte as 2 digits (three_digits 0) or 3 digits (1), or, when is_signed, as a sign and
 * 2 digits; then ';'. Returns the reply length. Only 0 and 1 reach three_digits [fact: every caller passes a
 * constant 0 or 1]; for another value with is_signed 0 the original divides by uninitialised stack bytes. */
uint16_t ai_ex_fmt_u8(uint8_t v, uint8_t three_digits, uint8_t is_signed)
{
    uint8_t div, n, i, d;

    if (is_signed == 0u) {
        div = three_digits ? 100u : 10u;
        n = three_digits ? 3u : 2u;
        for (i = 0; i < n; i++) {
            d = (uint8_t)(v / div);
            v = (uint8_t)(v - d * div);
            div = (uint8_t)(div / 10u);
            ai_ex_frame[8 + i] = (uint8_t)nib2hex(d);
        }
        ai_ex_frame[8 + i] = ';';
        return (uint16_t)(i + 1u + 8u);
    }
    if (v & 0x80u) {
        ai_ex_frame[8] = '-';
        v = (uint8_t)-v;
    } else {
        ai_ex_frame[8] = '+';
    }
    div = 10u;
    for (i = 0; i < 2u; i++) {
        d = (uint8_t)(v / div);
        v = (uint8_t)(v - d * div);
        div = (uint8_t)(div / 10u);
        ai_ex_frame[9 + i] = (uint8_t)nib2hex(d);
    }
    ai_ex_frame[9 + i] = ';';
    return (uint16_t)(i + 1u + 9u);
}

/* ai_ex_fmt_u16_4 0xFFFEC3F8: a word as 4 digits + ';'; returns the reply length (13) */
uint16_t ai_ex_fmt_u16_4(uint16_t v)
{
    uint16_t div = 1000u;
    uint8_t i;

    for (i = 0; i < 4u; i++) {
        uint8_t d = (uint8_t)(v / div);

        v = (uint16_t)(v - (v / div) * div);
        div = (uint16_t)(div / 10u);
        ai_ex_frame[8 + i] = (uint8_t)nib2hex(d);
    }
    ai_ex_frame[8 + i] = ';';
    return (uint16_t)(i + 1u + 8u);
}

/* One digit + ';' (lists of up to 16 choices) */
static inline void ai_ex_put_digit(uint8_t v)
{
    ai_ex_frame[8] = (uint8_t)nib2hex(v);
    ai_ex_frame[9] = ';';
    ai_ex_len = AI_EX_DIGIT_LEN;
}

/* --- the common shapes: shadow compare on g_opstate.field; sh = the shadow byte (0x1B29A + sh) --- */

/* the value as 2 or 3 digits or signed (ai_ex_fmt_u8) */
#define AI_EX_U8(id, field, sh, three_digits, is_signed)                                                              \
    void ai_ex##id(void)                                                                                          \
    {                                                                                                             \
        if (ai_ex_shadow[sh] == (uint8_t)g_opstate.field)                                                         \
            return;                                                                                               \
        ai_ex_shadow[sh] = (uint8_t)g_opstate.field;                                                              \
        ai_ex_len = ai_ex_fmt_u8(ai_ex_shadow[sh], three_digits, is_signed);                                      \
    }

/* one digit (a list item) */
#define AI_EX_DIGIT(id, field, sh)                                                                                    \
    void ai_ex##id(void)                                                                                          \
    {                                                                                                             \
        if (ai_ex_shadow[sh] == (uint8_t)g_opstate.field)                                                         \
            return;                                                                                               \
        ai_ex_shadow[sh] = (uint8_t)g_opstate.field;                                                              \
        ai_ex_put_digit(ai_ex_shadow[sh]);                                                                        \
    }

/* an AGC delay: the menu index n is (n + 1) * 20 ms, 4 digits [fact: ai_ex010104 0xFFFE6F1F..0xFFFE6F23] */
#define AI_EX_DELAY(id, field, sh)                                                                                    \
    void ai_ex##id(void)                                                                                          \
    {                                                                                                             \
        if (ai_ex_shadow[sh] == (uint8_t)g_opstate.field)                                                         \
            return;                                                                                               \
        ai_ex_shadow[sh] = (uint8_t)g_opstate.field;                                                              \
        ai_ex_len = ai_ex_fmt_u16_4((uint16_t)((ai_ex_shadow[sh] + 1u) * 20u));                                   \
    }

/* EX06 PRESET1..5: each item of a row calls the row's shared detector with the preset number 1..5
 * [fact: ai_ex060101 0xFFFEC0C9 = mov #1, r1; bsr ai_ex_preset_name; rts] */
#define AI_EX_PRESET(id, field, n)                                                                                    \
    void ai_ex##id(void)                                                                                          \
    {                                                                                                             \
        ai_ex_preset_##field(n);                                                                                  \
    }

/* --- the shared detectors of the PRESET rows: presets[n - 1].field against ai_ex_preset_shadow[row][n - 1]
 * (0x1B555 + 5 * row + n - 1) [fact: ai_ex_preset_cat1_rate 0xFFFEA88C, ai_ex_preset_agc_fast_delay 0xFFFEAD00];
 * any other n changes nothing --- */

static inline int ai_ex_byte_changed(uint8_t *shadow, uint8_t v)
{
    if (*shadow == v)
        return 0;
    *shadow = v;
    return 1;
}

#define AI_EX_PRESET_CHANGED(field, row, n)                                                                           \
    ((n) >= 1u && (n) <= 5u && ai_ex_byte_changed(&ai_ex_preset_shadow[row][(n) - 1u], g_opstate.presets[(n) - 1u].field))

/* a digit row: the ';' is written on every call, also without a change [fact: 0xFFFEA9FD] */
#define AI_EX_PRESET_DIGIT(field, row)                                                                                \
    void ai_ex_preset_##field(uint8_t n)                                                                          \
    {                                                                                                             \
        if (AI_EX_PRESET_CHANGED(field, row, n)) {                                                                \
            ai_ex_frame[8] = (uint8_t)nib2hex(g_opstate.presets[n - 1u].field);                                                                 \
            ai_ex_len = AI_EX_DIGIT_LEN;                                                                          \
        }                                                                                                         \
        ai_ex_frame[9] = ';';                                                                                     \
    }

#define AI_EX_PRESET_U8(field, row, three_digits, is_signed)                                                          \
    void ai_ex_preset_##field(uint8_t n)                                                                          \
    {                                                                                                             \
        if (AI_EX_PRESET_CHANGED(field, row, n))                                                                  \
            ai_ex_len = ai_ex_fmt_u8(g_opstate.presets[n - 1u].field, three_digits, is_signed);                                                 \
    }

#define AI_EX_PRESET_DELAY(field, row)                                                                                \
    void ai_ex_preset_##field(uint8_t n)                                                                          \
    {                                                                                                             \
        if (AI_EX_PRESET_CHANGED(field, row, n))                                                                  \
            ai_ex_len = ai_ex_fmt_u16_4((uint16_t)((g_opstate.presets[n - 1u].field + 1u) * 20u));                                              \
    }

/* rows 0..16 = the preset's bytes after its name (struct preset) [fact: the shadow and offset of each detector] */
AI_EX_PRESET_DIGIT(cat1_rate, 0)
AI_EX_PRESET_DIGIT(cat1_tot, 1)
AI_EX_PRESET_DIGIT(cat1_cat3_stop_bit, 2)
AI_EX_PRESET_DELAY(agc_fast_delay, 3)
AI_EX_PRESET_DELAY(agc_mid_delay, 4)
AI_EX_PRESET_DELAY(agc_slow_delay, 5)
AI_EX_PRESET_U8(lcut_freq, 6, 0, 0)
AI_EX_PRESET_DIGIT(lcut_slope, 7)
AI_EX_PRESET_U8(hcut_freq, 8, 0, 0)
AI_EX_PRESET_DIGIT(hcut_slope, 9)
AI_EX_PRESET_U8(usb_out_level, 10, 1, 0)
AI_EX_PRESET_U8(rear_out_level, 11, 1, 0)
AI_EX_PRESET_DIGIT(tx_bpf_sel, 12)
AI_EX_PRESET_DIGIT(mod_source, 13)
AI_EX_PRESET_U8(usb_mod_gain, 14, 1, 0)
AI_EX_PRESET_U8(rear_mod_gain, 15, 1, 0)
AI_EX_PRESET_DIGIT(rptt_select, 16)

/* a 12-character text against its 12-byte shadow (CC-RX's strncmp, which compares all 12 bytes: lib/runtime.c) */
static inline int ai_ex_text_changed(char *shadow, const char *text)
{
    uint8_t i;

    if (strncmp(shadow, text, AI_EX_TEXT) == 0)
        return 0;
    for (i = 0; i < AI_EX_TEXT; i++)
        shadow[i] = text[i];
    return 1;
}

static inline void ai_ex_put_text(const char *text)
{
    uint8_t i;

    for (i = 0; i < AI_EX_TEXT; i++)
        ai_ex_frame[8 + i] = (uint8_t)text[i];
    ai_ex_frame[8 + AI_EX_TEXT] = ';';
}

/* ai_ex_preset_name 0xFFFEA63A: EX060n01 PRESET n NAME, shadow ai_ex_preset_names[n - 1] (0x1B370 + 12 (n - 1)).
 * The original copies the text to the reply whenever ai_ex_len is not 0 after the compare, from a stack copy made
 * only on a change; ai_ex_len is 0 on entry (cat_ai_ex_scan zeroes it and stops at the first detector that sets it
 * [fact: 0xFFFE6D7E, 0xFFFE6DA3]), so that is the same as copying on a change. */
void ai_ex_preset_name(uint8_t n)
{
    if (n >= 1u && n <= 5u && ai_ex_text_changed(ai_ex_preset_names[n - 1u], g_opstate.presets[n - 1u].name)) {
        ai_ex_len = AI_EX_TEXT_LEN;
        ai_ex_put_text(g_opstate.presets[n - 1u].name);
    }
}

/* --- the detectors, in table order (ai_ex_detectors[0..295]) --- */
AI_EX_U8(010101, ex010101_af_treble_gain, 0x000, 0, 1)
AI_EX_U8(010102, ex010102_af_middle_tone_gain, 0x001, 0, 1)
AI_EX_U8(010103, ex010103_af_bass_gain, 0x002, 0, 1)
AI_EX_DELAY(010104, ex010104_agc_fast_delay, 0x003)
AI_EX_DELAY(010105, ex010105_agc_mid_delay, 0x004)
AI_EX_DELAY(010106, ex010106_agc_slow_dely, 0x005)
AI_EX_U8(010107, ex010107_lcut_freq, 0x006, 0, 0)
AI_EX_DIGIT(010108, ex010108_lcut_slope, 0x007)
AI_EX_U8(010109, ex010109_hcut_freq, 0x008, 0, 0)
AI_EX_DIGIT(010110, ex010110_hcut_slope, 0x009)
AI_EX_U8(010111, ex010111_usb_out_level, 0x00a, 1, 0)
AI_EX_U8(010112, ex010112_rear_out_level, 0x00b, 1, 0)
AI_EX_DIGIT(010113, ex010113_tx_bpf_sel, 0x00c)
AI_EX_DIGIT(010114, ex010114_mod_source, 0x00d)
AI_EX_U8(010115, ex010115_usb_mod_gain, 0x00e, 1, 0)
AI_EX_U8(010116, ex010116_rear_mod_gain, 0x00f, 1, 0)
AI_EX_DIGIT(010117, ex010117_rptt_select, 0x010)
AI_EX_U8(010118, ex010118_nar_width, 0x011, 0, 0)
AI_EX_DIGIT(010119, ex010119_cw_auto_mode, 0x012)
AI_EX_U8(010201, ex010201_af_treble_gain, 0x013, 0, 1)
AI_EX_U8(010202, ex010202_af_middle_tone_gain, 0x014, 0, 1)
AI_EX_U8(010203, ex010203_af_bass_gain, 0x015, 0, 1)
AI_EX_DELAY(010204, ex010204_agc_fast_delay, 0x016)
AI_EX_DELAY(010205, ex010205_agc_mid_delay, 0x017)
AI_EX_DELAY(010206, ex010206_agc_slow_delay, 0x018)
AI_EX_U8(010207, ex010207_lcut_freq, 0x019, 0, 0)
AI_EX_DIGIT(010208, ex010208_lcut_slope, 0x01a)
AI_EX_U8(010209, ex010209_hcut_freq, 0x01b, 0, 0)
AI_EX_DIGIT(010210, ex010210_hcut_slope, 0x01c)
AI_EX_U8(010211, ex010211_usb_out_level, 0x01d, 1, 0)
AI_EX_U8(010212, ex010212_rear_out_level, 0x01e, 1, 0)
AI_EX_DIGIT(010213, ex010213_tx_bpf_sel, 0x01f)
AI_EX_DIGIT(010214, ex010214_mod_source, 0x020)
AI_EX_U8(010215, ex010215_usb_mod_gain, 0x021, 1, 0)
AI_EX_U8(010216, ex010216_rear_mod_gain, 0x022, 1, 0)
AI_EX_DIGIT(010217, ex010217_rptt_select, 0x023)
AI_EX_U8(010301, ex010301_af_treble_gain, 0x024, 0, 1)
AI_EX_U8(010302, ex010302_af_middle_tone_gain, 0x025, 0, 1)
AI_EX_U8(010303, ex010303_af_bass_gain, 0x026, 0, 1)
AI_EX_DELAY(010304, ex010304_agc_fast_delay, 0x027)
AI_EX_DELAY(010305, ex010305_agc_mid_delay, 0x028)
AI_EX_DELAY(010306, ex010306_agc_slow_delay, 0x029)
AI_EX_U8(010307, ex010307_lcut_freq, 0x02a, 0, 0)
AI_EX_DIGIT(010308, ex010308_lcut_slope, 0x02b)
AI_EX_U8(010309, ex010309_hcut_freq, 0x02c, 0, 0)
AI_EX_DIGIT(010310, ex010310_hcut_slope, 0x02d)
AI_EX_U8(010311, ex010311_usb_out_level, 0x02e, 1, 0)
AI_EX_U8(010312, ex010312_rear_out_level, 0x02f, 1, 0)
AI_EX_DIGIT(010313, ex010313_mod_source, 0x030)
AI_EX_U8(010314, ex010314_usb_mod_gain, 0x031, 1, 0)
AI_EX_U8(010315, ex010315_rear_mod_gain, 0x032, 1, 0)
AI_EX_DIGIT(010316, ex010316_rptt_select, 0x033)
AI_EX_U8(010401, ex010401_af_treble_gain, 0x038, 0, 1)
AI_EX_U8(010402, ex010402_af_middle_tone_gain, 0x039, 0, 1)
AI_EX_U8(010403, ex010403_af_bass_gain, 0x03a, 0, 1)
AI_EX_DELAY(010404, ex010404_agc_fast_delay, 0x03b)
AI_EX_DELAY(010405, ex010405_agc_mid_delay, 0x03c)
AI_EX_DELAY(010406, ex010406_agc_slow_delay, 0x03d)
AI_EX_U8(010407, ex010407_lcut_freq, 0x03e, 0, 0)
AI_EX_DIGIT(010408, ex010408_lcut_slope, 0x03f)
AI_EX_U8(010409, ex010409_hcut_freq, 0x040, 0, 0)
AI_EX_DIGIT(010410, ex010410_hcut_slope, 0x041)
AI_EX_U8(010411, ex010411_usb_out_level, 0x042, 1, 0)
AI_EX_U8(010412, ex010412_rear_out_level, 0x043, 1, 0)
AI_EX_DIGIT(010413, ex010413_tx_bpf_sel, 0x044)
AI_EX_DIGIT(010414, ex010414_mod_source, 0x045)
AI_EX_U8(010415, ex010415_usb_mod_gain, 0x046, 1, 0)
AI_EX_U8(010416, ex010416_rear_mod_gain, 0x047, 1, 0)
AI_EX_DIGIT(010417, ex010417_rptt_select, 0x048)
AI_EX_U8(010418, ex010418_nar_width, 0x049, 0, 0)
AI_EX_DIGIT(010419, ex010419_psk_tone, 0x04a)
AI_EX_U8(010501, ex010501_af_treble_gain, 0x04b, 0, 1)
AI_EX_U8(010502, ex010502_af_middle_tone_gain, 0x04c, 0, 1)
AI_EX_U8(010503, ex010503_af_bass_gain, 0x04d, 0, 1)
AI_EX_DELAY(010504, ex010504_agc_fast_delay, 0x04e)
AI_EX_DELAY(010505, ex010505_agc_mid_delay, 0x04f)
AI_EX_DELAY(010506, ex010506_agc_slow_delay, 0x050)
AI_EX_U8(010507, ex010507_lcut_freq, 0x051, 0, 0)
AI_EX_DIGIT(010508, ex010508_lcut_slope, 0x052)
AI_EX_U8(010509, ex010509_hcut_freq, 0x053, 0, 0)
AI_EX_DIGIT(010510, ex010510_hcut_slope, 0x054)
AI_EX_U8(010511, ex010511_usb_out_level, 0x055, 1, 0)
AI_EX_U8(010512, ex010512_rear_out_level, 0x056, 1, 0)
AI_EX_DIGIT(010513, ex010513_rptt_select, 0x057)
AI_EX_U8(010514, ex010514_nar_width, 0x058, 0, 0)
AI_EX_DIGIT(010515, ex010515_mark_frequency, 0x059)
AI_EX_DIGIT(010516, ex010516_shift_frequency, 0x05a)
AI_EX_U8(020101, ex020101_af_treble_gain, 0x05c, 0, 1)
AI_EX_U8(020102, ex020102_af_middle_tone_gain, 0x05d, 0, 1)
AI_EX_U8(020103, ex020103_af_bass_gain, 0x05e, 0, 1)
AI_EX_DELAY(020104, ex020104_agc_fast_delay, 0x05f)
AI_EX_DELAY(020105, ex020105_agc_mid_delay, 0x060)
AI_EX_DELAY(020106, ex020106_agc_slow_delay, 0x061)
AI_EX_U8(020107, ex020107_lcut_freq, 0x062, 0, 0)
AI_EX_DIGIT(020108, ex020108_lcut_slope, 0x063)
AI_EX_U8(020109, ex020109_hcut_freq, 0x064, 0, 0)
AI_EX_DIGIT(020110, ex020110_hcut_slope, 0x065)
AI_EX_U8(020111, ex020111_usb_out_level, 0x066, 1, 0)
AI_EX_U8(020112, ex020112_rear_out_level, 0x067, 1, 0)
AI_EX_DIGIT(020113, ex020113_rptt_select, 0x068)
AI_EX_U8(020114, ex020114_nar_width, 0x069, 0, 0)
AI_EX_DIGIT(020115, ex020115_pc_keying, 0x06a)
AI_EX_DIGIT(020116, ex020116_cw_bk_in_type, 0x06b)
AI_EX_DIGIT(020117, ex020117_cw_wave_shape, 0x06c)
AI_EX_DIGIT(020118, ex020118_cw_freq_display, 0x06d)
AI_EX_DIGIT(020119, ex020119_qsk_delay_time, 0x06e)
AI_EX_DIGIT(020120, ex020120_cw_indicator, 0x06f)
AI_EX_DIGIT(020201, ex020201_keyer_type, 0x070)
AI_EX_DIGIT(020202, ex020202_keyer_dot_dash, 0x071)
AI_EX_U8(020203, ex020203_cw_weight, 0x072, 0, 0)
AI_EX_DIGIT(020204, ex020204_number_style, 0x073)
AI_EX_DIGIT(020206, ex020206_cw_memory_1, 0x074)
AI_EX_DIGIT(020207, ex020207_cw_memory_2, 0x075)
AI_EX_DIGIT(020208, ex020208_cw_memory_3, 0x076)
AI_EX_DIGIT(020209, ex020209_cw_memory_4, 0x077)
AI_EX_DIGIT(020210, ex020210_cw_memory_5, 0x078)
AI_EX_U8(020211, ex020211_repeat_interval, 0x079, 0, 0)
AI_EX_U8(030101, ex030101_beep_level, 0x07a, 1, 0)
AI_EX_DIGIT(030102, ex030102_rf_sql_vr, 0x07b)
AI_EX_DIGIT(030103, ex030103_tun_lin_port_select, 0x07c)
AI_EX_DIGIT(030104, ex030104_tuner_type_select, 0x07d)
AI_EX_DIGIT(030105, ex030105_cat_1_rate, 0x07e)
AI_EX_DIGIT(030106, ex030106_cat_1_time_out_timer, 0x07f)
AI_EX_DIGIT(030107, ex030107_cat_1_cat_3_stop_bit, 0x080)
AI_EX_DIGIT(030108, ex030108_cat_2_rate, 0x081)
AI_EX_DIGIT(030109, ex030109_cat_2_time_out_timer, 0x082)
AI_EX_DIGIT(030110, ex030110_cat_3_rate, 0x083)
AI_EX_DIGIT(030111, ex030111_cat_3_time_out_timer, 0x084)
AI_EX_DIGIT(030112, ex030112_qmb_ch, 0x085)
AI_EX_DIGIT(030113, ex030113_band_stack, 0x086)
AI_EX_DIGIT(030114, ex030114_mem_group, 0x087)
AI_EX_U8(030115, ex030115_tx_time_out_timer, 0x088, 0, 0)
AI_EX_DIGIT(030116, ex030116_mic_scan, 0x089)
AI_EX_DIGIT(030117, ex030117_mic_scan_resume, 0x08a)
AI_EX_U8(030118, ex030118_ref_freq_fine_adj, 0x08b, 0, 1)
AI_EX_U8(030119, ex030119_keyboard_language, 0x08c, 0, 0)
AI_EX_U8(030120, ex030120_mic_p1, 0x08d, 0, 0)
AI_EX_U8(030121, ex030121_mic_p2, 0x08e, 0, 0)
AI_EX_U8(030122, ex030122_mic_p3, 0x08f, 0, 0)
AI_EX_U8(030123, ex030123_mic_p4, 0x090, 0, 0)
AI_EX_U8(030124, ex030124_mic_up, 0x091, 0, 0)
AI_EX_U8(030125, ex030125_mic_down, 0x092, 0, 0)
AI_EX_DIGIT(030126, ex030126_scu_lan10, 0x093)
AI_EX_DIGIT(030201, ex030201_if_notch_width, 0x094)
AI_EX_DIGIT(030202, ex030202_nb_rejection, 0x095)
AI_EX_DIGIT(030203, ex030203_nb_width, 0x096)
AI_EX_DIGIT(030204, ex030204_apf_width, 0x097)
AI_EX_U8(030205, ex030205_contour_level, 0x098, 0, 1)
AI_EX_U8(030206, ex030206_contour_width, 0x099, 0, 0)
AI_EX_DIGIT(030301, ex030301_amc_release_time, 0x09a)
AI_EX_U8(030302, ex030302_prmtrc_eq1_freq, 0x09b, 0, 0)
AI_EX_U8(030303, ex030303_prmtrc_eq1_level, 0x09c, 0, 1)
AI_EX_U8(030304, ex030304_prmtrc_eq1_bwth, 0x09d, 0, 0)
AI_EX_U8(030305, ex030305_prmtrc_eq2_freq, 0x09e, 0, 0)
AI_EX_U8(030306, ex030306_prmtrc_eq2_level, 0x09f, 0, 1)
AI_EX_U8(030307, ex030307_prmtrc_eq2_bwth, 0x0a0, 0, 0)
AI_EX_U8(030308, ex030308_prmtrc_eq3_freq, 0x0a1, 0, 0)
AI_EX_U8(030309, ex030309_prmtrc_eq3_level, 0x0a2, 0, 1)
AI_EX_U8(030310, ex030310_prmtrc_eq3_bwth, 0x0a3, 0, 0)
AI_EX_U8(030311, ex030311_p_prmtrc_eq1_freq, 0x0a4, 0, 0)
AI_EX_U8(030312, ex030312_p_prmtrc_eq1_level, 0x0a5, 0, 1)
AI_EX_U8(030313, ex030313_p_prmtrc_eq1_bwth, 0x0a6, 0, 0)
AI_EX_U8(030314, ex030314_p_prmtrc_eq2_freq, 0x0a7, 0, 0)
AI_EX_U8(030315, ex030315_p_prmtrc_eq2_level, 0x0a8, 0, 1)
AI_EX_U8(030316, ex030316_p_prmtrc_eq2_bwth, 0x0a9, 0, 0)
AI_EX_U8(030317, ex030317_p_prmtrc_eq3_freq, 0x0aa, 0, 0)
AI_EX_U8(030318, ex030318_p_prmtrc_eq3_level, 0x0ab, 0, 1)
AI_EX_U8(030319, ex030319_p_prmtrc_eq3_bwth, 0x0ac, 0, 0)
AI_EX_U8(030401, ex030401_hf_max_power, 0x0ad, 1, 0)
AI_EX_U8(030402, ex030402_50m_max_power, 0x0ae, 1, 0)
AI_EX_U8(030403, ex030403_70m_max_power, 0x0af, 1, 0)
AI_EX_U8(030404, ex030404_am_max_power, 0x0b0, 1, 0)
AI_EX_DIGIT(030405, ex030405_vox_select, 0x0b1)
AI_EX_DIGIT(030406, ex030406_emergency_freq_tx, 0x0b2)
AI_EX_DIGIT(030407, ex030407_tx_inhitbit, 0x0b3)
AI_EX_DIGIT(030408, ex030408_meter_detector, 0x0b4)
AI_EX_DIGIT(030501, ex030501_ssb_cw_dial_step, 0x0b5)
AI_EX_DIGIT(030502, ex030502_rtty_psk_dial_step, 0x0b6)
AI_EX_DIGIT(030503, ex030503_ch_step, 0x0b7)
AI_EX_DIGIT(030504, ex030504_am_ch_step, 0x0b8)
AI_EX_DIGIT(030505, ex030505_fm_ch_step, 0x0b9)
AI_EX_DIGIT(030506, ex030506_main_steps_per_rev, 0x0ba)
AI_EX_DIGIT(040102, ex040102_my_call_time, 0x0c7)
AI_EX_DIGIT(040103, ex040103_pop_up_time, 0x0c8)
AI_EX_DIGIT(040104, ex040104_screen_saver, 0x0c9)
AI_EX_U8(040105, ex040105_led_dimmer, 0x0ca, 0, 0)
AI_EX_U8(040106, ex040106_mouse_pointer_speed, 0x0cb, 0, 0)
AI_EX_DIGIT(040201, ex040201_rbw, 0x0cc)
AI_EX_DIGIT(040202, ex040202_scope_ctr, 0x0cd)
AI_EX_DIGIT(040203, ex040203_2d_disp_sensitivity, 0x0ce)
AI_EX_DIGIT(040204, ex040204_3dss_disp_sensitivity, 0x0cf)
AI_EX_DIGIT(040301, ex040301_vmi_color_vfo_a, 0x0d0)
AI_EX_DIGIT(040302, ex040302_vmi_color_vfo_b, 0x0d1)
AI_EX_DIGIT(040303, ex040303_vmi_color_memory, 0x0d2)
AI_EX_DIGIT(040304, ex040304_vmi_color_clar, 0x0d3)
AI_EX_DIGIT(040401, ex040401_ext_display, 0x0d4)
AI_EX_DIGIT(040402, ex040402_pixel, 0x0d5)
AI_EX_PRESET(060101, name, 1)
AI_EX_PRESET(060102, cat1_rate, 1)
AI_EX_PRESET(060103, cat1_tot, 1)
AI_EX_PRESET(060104, cat1_cat3_stop_bit, 1)
AI_EX_PRESET(060105, agc_fast_delay, 1)
AI_EX_PRESET(060106, agc_mid_delay, 1)
AI_EX_PRESET(060107, agc_slow_delay, 1)
AI_EX_PRESET(060108, lcut_freq, 1)
AI_EX_PRESET(060109, lcut_slope, 1)
AI_EX_PRESET(060110, hcut_freq, 1)
AI_EX_PRESET(060111, hcut_slope, 1)
AI_EX_PRESET(060112, usb_out_level, 1)
AI_EX_PRESET(060113, rear_out_level, 1)
AI_EX_PRESET(060114, tx_bpf_sel, 1)
AI_EX_PRESET(060115, mod_source, 1)
AI_EX_PRESET(060116, usb_mod_gain, 1)
AI_EX_PRESET(060117, rear_mod_gain, 1)
AI_EX_PRESET(060118, rptt_select, 1)
AI_EX_PRESET(060201, name, 2)
AI_EX_PRESET(060202, cat1_rate, 2)
AI_EX_PRESET(060203, cat1_tot, 2)
AI_EX_PRESET(060204, cat1_cat3_stop_bit, 2)
AI_EX_PRESET(060205, agc_fast_delay, 2)
AI_EX_PRESET(060206, agc_mid_delay, 2)
AI_EX_PRESET(060207, agc_slow_delay, 2)
AI_EX_PRESET(060208, lcut_freq, 2)
AI_EX_PRESET(060209, lcut_slope, 2)
AI_EX_PRESET(060210, hcut_freq, 2)
AI_EX_PRESET(060211, hcut_slope, 2)
AI_EX_PRESET(060212, usb_out_level, 2)
AI_EX_PRESET(060213, rear_out_level, 2)
AI_EX_PRESET(060214, tx_bpf_sel, 2)
AI_EX_PRESET(060215, mod_source, 2)
AI_EX_PRESET(060216, usb_mod_gain, 2)
AI_EX_PRESET(060217, rear_mod_gain, 2)
AI_EX_PRESET(060218, rptt_select, 2)
AI_EX_PRESET(060301, name, 3)
AI_EX_PRESET(060302, cat1_rate, 3)
AI_EX_PRESET(060303, cat1_tot, 3)
AI_EX_PRESET(060304, cat1_cat3_stop_bit, 3)
AI_EX_PRESET(060305, agc_fast_delay, 3)
AI_EX_PRESET(060306, agc_mid_delay, 3)
AI_EX_PRESET(060307, agc_slow_delay, 3)
AI_EX_PRESET(060308, lcut_freq, 3)
AI_EX_PRESET(060309, lcut_slope, 3)
AI_EX_PRESET(060310, hcut_freq, 3)
AI_EX_PRESET(060311, hcut_slope, 3)
AI_EX_PRESET(060312, usb_out_level, 3)
AI_EX_PRESET(060313, rear_out_level, 3)
AI_EX_PRESET(060314, tx_bpf_sel, 3)
AI_EX_PRESET(060315, mod_source, 3)
AI_EX_PRESET(060316, usb_mod_gain, 3)
AI_EX_PRESET(060317, rear_mod_gain, 3)
AI_EX_PRESET(060318, rptt_select, 3)
AI_EX_PRESET(060401, name, 4)
AI_EX_PRESET(060402, cat1_rate, 4)
AI_EX_PRESET(060403, cat1_tot, 4)
AI_EX_PRESET(060404, cat1_cat3_stop_bit, 4)
AI_EX_PRESET(060405, agc_fast_delay, 4)
AI_EX_PRESET(060406, agc_mid_delay, 4)
AI_EX_PRESET(060407, agc_slow_delay, 4)
AI_EX_PRESET(060408, lcut_freq, 4)
AI_EX_PRESET(060409, lcut_slope, 4)
AI_EX_PRESET(060410, hcut_freq, 4)
AI_EX_PRESET(060411, hcut_slope, 4)
AI_EX_PRESET(060412, usb_out_level, 4)
AI_EX_PRESET(060413, rear_out_level, 4)
AI_EX_PRESET(060414, tx_bpf_sel, 4)
AI_EX_PRESET(060415, mod_source, 4)
AI_EX_PRESET(060416, usb_mod_gain, 4)
AI_EX_PRESET(060417, rear_mod_gain, 4)
AI_EX_PRESET(060418, rptt_select, 4)
AI_EX_PRESET(060501, name, 5)
AI_EX_PRESET(060502, cat1_rate, 5)
AI_EX_PRESET(060503, cat1_tot, 5)
AI_EX_PRESET(060504, cat1_cat3_stop_bit, 5)
AI_EX_PRESET(060505, agc_fast_delay, 5)
AI_EX_PRESET(060506, agc_mid_delay, 5)
AI_EX_PRESET(060507, agc_slow_delay, 5)
AI_EX_PRESET(060508, lcut_freq, 5)
AI_EX_PRESET(060509, lcut_slope, 5)
AI_EX_PRESET(060510, hcut_freq, 5)
AI_EX_PRESET(060511, hcut_slope, 5)
AI_EX_PRESET(060512, usb_out_level, 5)
AI_EX_PRESET(060513, rear_out_level, 5)
AI_EX_PRESET(060514, tx_bpf_sel, 5)
AI_EX_PRESET(060515, mod_source, 5)
AI_EX_PRESET(060516, usb_mod_gain, 5)
AI_EX_PRESET(060517, rear_mod_gain, 5)
AI_EX_PRESET(060518, rptt_select, 5)

/* --- the detectors with a shape of their own --- */

static inline const struct vfo_rec *ai_ex_active_vfo(void)
{
    return g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_a : &g_opstate.vfo_b;
}

/* ai_ex010317 0xFFFE7BE2: RPT SHIFT of the active VFO, flags2 bits 2-3 (shadow 0x1B2CE) */
void ai_ex010317(void)
{
    uint8_t shift = (uint8_t)((ai_ex_active_vfo()->flags2 >> 2) & 3u);

    if (ai_ex_shadow[0x034] == shift)
        return;
    ai_ex_shadow[0x034] = shift;
    ai_ex_put_digit(shift);
}

/* ai_ex010318 0xFFFE7C4C: RPT SHIFT (28MHz), steps of 10 kHz as 4 digits */
void ai_ex010318(void)
{
    if (ai_ex_shadow[0x035] == g_opstate.ex010318_rpt_shift_28mhz)
        return;
    ai_ex_shadow[0x035] = g_opstate.ex010318_rpt_shift_28mhz;
    ai_ex_len = ai_ex_fmt_u16_4((uint16_t)(ai_ex_shadow[0x035] * 10u));
}

/* a big-endian word of the menu block against its 16-bit shadow */
static inline int ai_ex_word_changed(uint16_t *shadow, const uint8_t be[2])
{
    uint16_t v = (uint16_t)(be[0] << 8 | be[1]);

    if (*shadow == v)
        return 0;
    *shadow = v;
    return 1;
}

/* ai_ex010319 0xFFFE7C8F: RPT SHIFT (50MHz), a big-endian word x 10 (shadow 0x1FF14) */
void ai_ex010319(void)
{
    if (ai_ex_word_changed(&ai_ex_shadow_rpt_shift_50, g_opstate.ex010319_rpt_shift_50mhz_be))
        ai_ex_len = ai_ex_fmt_u16_4((uint16_t)(ai_ex_shadow_rpt_shift_50 * 10u));
}

/* ai_ex010320 0xFFFE7CE1: tone mode of the active VFO, flags3 bits 3-5; the shadow keeps the masked byte */
void ai_ex010320(void)
{
    uint8_t mode = ai_ex_active_vfo()->flags3 & 0x38u;

    if (ai_ex_shadow[0x036] == mode)
        return;
    ai_ex_shadow[0x036] = mode;
    ai_ex_put_digit((uint8_t)((mode >> 3) & 7u));
}

/* ai_ex010321 0xFFFE7D53: the tone number of the active VFO, 3 digits */
void ai_ex010321(void)
{
    uint8_t tone = ai_ex_active_vfo()->tone_num;

    if (ai_ex_shadow[0x037] == tone)
        return;
    ai_ex_shadow[0x037] = tone;
    ai_ex_len = ai_ex_fmt_u8(ai_ex_shadow[0x037], 1, 0);
}

/* ai_ex010420 0xFFFE82AE: DATA SHIFT (SSB), a big-endian word x 10 (shadow 0x1FF16) */
void ai_ex010420(void)
{
    if (ai_ex_word_changed(&ai_ex_shadow_data_shift, g_opstate.ex010420_data_shift_ssb_be))
        ai_ex_len = ai_ex_fmt_u16_4((uint16_t)(ai_ex_shadow_data_shift * 10u));
}

/* ai_ex010517 0xFFFE873C (POLARITY TX) is not recreated: it stores the setting in its shadow first and then compares
 * the shadow with an uninitialised stack byte (3[r0]), which on a difference goes to the shadow and the reply
 * [fact: 0xFFFE874A..0xFFFE8761]. See docs/code/main/cat-ai.md. */

/* ai_ex020205 0xFFFE8E1B: CONTEST NUMBER, a big-endian word (shadow 0x1FF18) */
void ai_ex020205(void)
{
    if (ai_ex_word_changed(&ai_ex_shadow_contest_number, g_opstate.ex020205_contest_number_be))
        ai_ex_len = ai_ex_fmt_u16_4(ai_ex_shadow_contest_number);
}

/* ai_ex040101 0xFFFEA16F: MY CALL, 12 characters (shadow 0x1B355, 12 bytes) */
void ai_ex040101(void)
{
    if (!ai_ex_text_changed((char *)&ai_ex_shadow[0x0BB], g_opstate.ex040101_my_call))
        return;
    ai_ex_put_text(g_opstate.ex040101_my_call);
    ai_ex_len = AI_EX_TEXT_LEN;
}

/* --- the scan --- */

#define AI_EX_ITEMS     296u
#define AI_EX_ID_LEN    8u
#define AI_EX_HOLD_TIMER 0x32
#define AI_EX_HOLD_MS   200u

/* cat_ai_ex_scan 0xFFFE6D7A: the first changed item as "EX" + ID + value + ';' into out; returns its length, or 0
 * while the hold-off after an EX set runs (the scan itself runs then too, so the shadows follow the set) */
uint16_t cat_ai_ex_scan(uint8_t *out)
{
    uint16_t i;
    uint8_t j;

    ai_ex_len = 0;
    for (i = 0; i < AI_EX_ITEMS; i++) {
        ai_ex_detectors[i]();
        if (ai_ex_len != 0u) {
            for (j = 0; j < AI_EX_ID_LEN; j++)
                ai_ex_frame[j] = (uint8_t)ai_ex_ids[i][j];
            for (j = 0; j < ai_ex_len; j++)      /* SMOVF */
                out[j] = ai_ex_frame[j];
            break;
        }
    }
    if (ai_ex_held == 1u) {
        if (swtimer_expired(AI_EX_HOLD_TIMER) != 1u)
            return 0;
        ai_ex_held = 0;
    }
    return ai_ex_len;
}

/* cat_ai_ex_holdoff 0xFFFE6E26: after an EX set, no EX report for 200 ms (soft timer 0x32) */
void cat_ai_ex_holdoff(void)
{
    swtimer_start(AI_EX_HOLD_TIMER, AI_EX_HOLD_MS);
    ai_ex_held = 1;
}

/* cat_ai_ex 0xFFFDECEC: the AI detector of cat_ai_poll for the EX menu: the scan's frame into cat_ai_buf */
uint16_t cat_ai_ex(void)
{
    uint8_t frame[100];
    uint16_t n = cat_ai_ex_scan(frame);
    uint16_t i;

    if (n != 0u)
        for (i = 0; i < n; i++)
            cat_ai_buf[i] = frame[i];
    return n;
}
