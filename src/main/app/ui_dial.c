/* The tuning-step helpers of the MAIN image (T24, UI track; docs/code/main/ui-keys.md "Encoders"): the step of
 * the main dial in Hz for a VFO, from the digit-step and fast-step requests, the scan, the channel-step mode, the
 * FINE / FAST selection (g_opstate.fn_select) and the DIAL STEP / CH STEP menu items EX030501..EX030505.
 *
 * Mode groups of the 4-bit mode code (the low nibble of the VFO record's mode byte) as these functions sort them
 * [fact: the range tests below]: 0..3 and 8, 9, 12..14 take the SSB/CW or RTTY/PSK dial step, 4..5 and 6..7, 10..11
 * the AM / FM steps; which code is which mode is in docs/code/main/radio-control.md (the record's mode byte). */
#include <stdint.h>
#include "ft710_state.h"

extern struct ui_state *g_ui_ptr_d58;           /* 0x25D58 = &g_ui (src/main/data_symbols.tsv) */
extern uint8_t ch_step_x10_inhibit;             /* 0x1B4E5 */
extern uint8_t ch_step_x10_skipped;             /* 0x1B4E6 */
extern const uint16_t ch_step_table[4];         /* 0xFFF88514: CH STEP (EX030503) */
extern const uint16_t am_ch_step_table[6];      /* 0xFFF8851C: AM CH STEP (EX030504) */
extern const uint16_t fm_ch_step_table[6];      /* 0xFFF88528: FM CH STEP (EX030505) */

uint16_t dial_step_mode_hz(uint8_t mode);
uint32_t ch_step_hz(uint8_t mode);
uint32_t ch_step_scale(uint32_t step);

#define FN_FINE 1u        /* g_opstate.fn_select: FINE [inference: the steps 1 / 10 Hz it gives] */
#define FN_FAST 2u        /* x10 [fact: the multiplications] */

/* dial_step_hz 0xFFFC616E (side 0 = VFO-A, else VFO-B): 1 MHz or 1 kHz in digit-step mode, 100 kHz or 1 MHz with
 * the fast-step request, else while scanning or in channel-step mode the channel step for the AM / FM groups and
 * the dial step for the others; else the dial step, or the channel step when only that was requested [fact] */
uint32_t dial_step_hz(uint8_t side)
{
    uint8_t mode = side == 0 ? g_opstate.vfo_a.mode : g_opstate.vfo_b.mode;
    mode &= 0x0F;
    struct ui_state *ui = g_ui_ptr_d58;
    if (ui->digit_step_on == 1)
        return ui->digit_step_khz == 0 ? 1000000u : 1000u;
    if (ui->step_fast_req == 1)
        return g_ui_ptr_d58->step_fast_100k == 1 ? 100000u : 1000000u;
    ui = g_ui_ptr_d58;
    if (ui->scan_running == 1 || ui->ch_step_mode == 1) {
        if (mode == 6 || mode == 7 || mode == 10 || mode == 11 || mode == 4 || mode == 5)
            return ch_step_hz(mode);
        return dial_step_mode_hz(mode);
    }
    if (g_ui_ptr_d58->step_dial_req == 1)
        return dial_step_mode_hz(mode);
    if (g_ui_ptr_d58->step_ch_req == 1)
        return ch_step_hz(mode);
    return dial_step_mode_hz(mode);
}

/* 5 / 10 / 20 Hz by a DIAL STEP menu value (0, 1, other) */
static uint16_t dial_step_menu(uint8_t v)
{
    return v == 0 ? 5 : v == 1 ? 10 : 20;
}

/* dial_step_mode_hz 0xFFFC62AE (mode): FINE 1 Hz, else SSB/CW DIAL STEP (EX030501) or RTTY/PSK DIAL STEP (EX030502)
 * 5/10/20 Hz, x10 with FAST; the AM and FM groups 10 / 100 / 1000 Hz (FINE / normal / FAST) [fact]. Mode 15 belongs
 * to no group and the image returns an unset stack word (here 0, what the check's zeroed stack gives; Open: the
 * radio's value; a 4-bit mode code 15 would settle whether it occurs) */
uint16_t dial_step_mode_hz(uint8_t mode)
{
    uint16_t step = 0;
    uint8_t m = mode;
    if ((uint32_t)(m - 12) < 3 || (uint32_t)(m - 8) < 2) {
        if (g_opstate.fn_select == FN_FINE) {
            step = 1;
        } else {
            step = dial_step_menu(g_opstate.ex030502_rtty_psk_dial_step);
            if (g_opstate.fn_select == FN_FAST)
                step = (uint16_t)(step * 10);
        }
    } else if ((uint32_t)(m - 4) < 2 || (uint32_t)(m - 6) < 2 || (uint32_t)(m - 10) < 2) {
        if (g_opstate.fn_select == FN_FINE) {
            step = 10;
        } else {
            step = 100;
            if (g_opstate.fn_select == FN_FAST)
                step = (uint16_t)(step * 10);
        }
    } else if (m <= 3) {
        if (g_opstate.fn_select == FN_FINE) {
            step = 1;
        } else {
            step = dial_step_menu(g_opstate.ex030501_ssb_cw_dial_step);
            if (g_opstate.fn_select == FN_FAST)
                step = (uint16_t)(step * 10);
        }
    }
    return step;
}

/* ch_step_hz 0xFFFC63E6 (mode): the channel step of the mode's group, a menu value out of range taken as 0: AM
 * group AM CH STEP (6 entries), FM group FM CH STEP (6), the others CH STEP (4); mode 15: 0 [fact] */
uint32_t ch_step_hz(uint8_t mode)
{
    uint32_t m = mode;
    uint8_t v;
    if (m >= 4 && (uint32_t)(m - 4) < 2) {
        v = g_opstate.ex030504_am_ch_step;
        if (v >= 6)
            v = 0;
        return ch_step_scale(am_ch_step_table[v]);
    }
    if (m >= 4 && ((uint32_t)(m - 6) < 2 || ((uint32_t)(m - 8) >= 2 && (uint32_t)(m - 10) < 2))) {
        v = g_opstate.ex030505_fm_ch_step;
        if (v >= 6)
            v = 0;
        return ch_step_scale(fm_ch_step_table[v]);
    }
    if (m >= 4 && (uint32_t)(m - 8) >= 2 && m - 12 > 2)
        return 0;
    v = g_opstate.ex030503_ch_step;
    if (v >= 4)
        v = 0;
    return ch_step_scale(ch_step_table[v]);
}

/* FUN_fffc648c (step): x10 with FAST, unless 0x1B4E5 is 1, which leaves the step and sets 0x1B4E6 [fact] */
uint32_t ch_step_scale(uint32_t step)
{
    if (g_opstate.fn_select == FN_FAST) {
        if (ch_step_x10_inhibit == 1)
            ch_step_x10_skipped = 1;
        else
            step *= 10;
    }
    return step;
}
