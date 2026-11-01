/* The SWR meter and the squelch of the MAIN image (T24 MAIN round 5; docs/code/main/tx-protection.md "High SWR",
 * docs/code/main/eeprom.md "cfg105"): swr_meter_protect (SWR, HI-SWR alarm, pinning; meter_task calls it every 5 ms)
 * and the two squelch decisions of af_mute_update. The other meters are in meters.c (UI track). The floating-point steps keep the image's
 * order of operations, so every intermediate value is the same single-precision number; a CC-RX "x >= c" compiled as
 * "not (x < c)" with BLT, which is false for a NaN as in C [fact: FCMP sets O for an unordered pair, RXv2 manual
 * p. 90; tools/rx_fpu_check.py]. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "fpu_conv.h"

uint8_t dsp_fm_noise(void);
uint16_t dsp_signal_level(void);
uint8_t blink_phase(int32_t which);
uint8_t meter_avg_swr(uint32_t pos);       /* FUN_fffb9422 (aliases.tsv) */
void meter_avg_swr_f(float swr);          /* FUN_fffb948b (aliases.tsv) */

#define TUNE_CYCLE_TUNING 2       /* g_ui.tune_cycle_3d during a tuner cycle: the SWR meter is pinned at 255 */

/* swr_meter_protect 0xFFFB7545: in TX, SWR = (1 + r) / (1 - r) with r = AN001 / AN002 (reflected / forward). Nine
 * passes outside [1, 5) raise the HI-SWR alarm (1 or 2 with the blink phase), nine good ones clear it. With both
 * readings <= 10 counts or SWR < 1 (r > 1) the meter is pinned: 255 while the tuner cycles, else 1. The position is
 * piecewise linear through the SWR 1.5 / 2.0 / 3.0 positions of the alignment items 017..019. */
void swr_meter_protect(void)
{
    float rvs = (float)g_ui.adc_mcup_rvs;
    float fwd = (float)g_ui.adc_mcup_for;
    float pos15 = (float)g_cfg105.a017_mt_swr_1_5_mtr_pos;
    float pos20 = (float)g_cfg105.a018_mt_swr_2_0_mtr_pos;
    float pos30 = (float)g_cfg105.a019_mt_swr_3_0_mtr_pos;
    float r = rvs / fwd;
    float swr = (r + 1.0f) / (1.0f - r);

    if (g_ui.transmitting == 0) {
        g_ui.hi_swr = 0;
        return;
    }
    /* no RF (both readings 0) gives 0 / 0, a NaN, which the image counts as in range [fact: 0xFFFB75C6 FCMP, BLT] */
    if (swr < 1.0f || (swr >= 5.0f && !is_nan(swr))) {
        if (swr_bad_count < 9)
            swr_bad_count++;
        else
            g_ui.hi_swr = blink_phase(1) == 0 ? 1 : 2;
        swr_good_count = 0;
    } else {
        if (swr_good_count < 9)
            swr_good_count++;
        else
            g_ui.hi_swr = 0;
        swr_bad_count = 0;
    }
    if (!(rvs > 10.0f || fwd > 10.0f) || swr < 1.0f) {
        g_ui.hi_swr = 0;
        swr = g_ui.tune_cycle_3d == TUNE_CYCLE_TUNING ? 255.0f : 1.0f;
    }
    meter_swr_f = swr;
    meter_avg_swr_f(swr);

    float slope, offset;
    if (swr <= 1.5f) {
        slope = pos15 / 1.5f;
        offset = -slope;
    } else if (swr <= 2.0f) {
        slope = (pos20 - pos15) / 0.5f;
        offset = slope * -2.0f + pos20;
    } else {
        slope = (pos30 - pos20) / 1.0f;
        offset = slope * -3.0f + pos30;
    }
    uint16_t pos = (uint16_t)ftou(slope * swr + offset);
    if (pos > 0xFF)
        pos = 0xFF;
    meter_swr_raw_val = (uint8_t)pos;
    meter_swr_val = meter_avg_swr((uint8_t)pos);
}

/* the squelch's last word: open below the threshold, close above threshold + hysteresis */
static void squelch_decide(float level, float open_below, float hysteresis)
{
    if (level < open_below) {
        g_ui.squelch_open = 1;
        if (af_mute_get() != 0)
            af_mute_set(0);
    } else if (open_below + hysteresis < level) {
        g_ui.squelch_open = 0;
        if (af_mute_get() == 0)
            af_mute_set(1);
    }
}

/* fm_noise_squelch 0xFFFB7CEC: FM modes (6, 7, 10, 11). The noise threshold follows the SQL knob (g_ui +0xA3): open
 * below 25, the THN (modes 7, 11) or THW (6, 10) alignment item below 50, a line from 5/4 THW - TI/4 falling by
 * (THW - TI) / 200 per step up to 249, then TI (alignment items 046..048). Leaving FM unmutes once. */
void fm_noise_squelch(void)
{
    uint8_t mode = vfo_mode(0);
    float thr;
    if (mode == 11 || mode == 7) {
        thr = (float)g_cfg105.a047_rx_fm_sql_thn;
    } else if (mode == 10 || mode == 6) {
        thr = (float)g_cfg105.a046_rx_fm_sql_thw;
    } else {
        uint8_t last = fm_sql_last_mode;
        if ((uint8_t)(last - 6) < 2 || (uint8_t)(last - 10) <= 1) {
            fm_sql_last_mode = mode;
            if (af_mute_get() != 0)
                af_mute_set(0);
        }
        return;
    }
    fm_sql_last_mode = mode;
    uint8_t knob = g_ui.rf_gain;
    float ti = (float)g_cfg105.a048_rx_fm_sql_ti;
    float slope = (thr - ti) / -200.0f;
    float offset = (thr * 5.0f - ti) / 4.0f;
    float open_below, hysteresis;
    if (knob <= 24) {
        open_below = 256.0f;
        hysteresis = 0.0f;
    } else if (knob <= 49) {
        open_below = thr;
        hysteresis = 30.0f;
    } else if (knob <= 249) {
        open_below = (float)knob * slope + offset;
        hysteresis = knob <= 99 ? 15.0f : knob <= 149 ? 22.0f : knob <= 199 ? 25.0f : 30.0f;
    } else {
        open_below = ti;
        hysteresis = 25.0f;
    }
    squelch_decide((float)dsp_fm_noise(), open_below, hysteresis);
}

/* signal_level_squelch 0xFFFB7E61: SSB/CW/AM/DATA modes (0..5, 8, 9, 12..14). The signal threshold runs from S-cal +
 * 110 at knob 24 to S-cal + 80 at knob 240 (S-cal = alignment item 041), hysteresis 6; below 25 always open. */
void signal_level_squelch(void)
{
    const float knob_hi = 240.0f, knob_lo = 24.0f;
    float cal = (float)g_cfg105.a041_rx_s_mtr_40;
    uint8_t mode = vfo_mode(0);
    if (!(mode < 6 || (uint8_t)(mode - 8) < 2 || (uint8_t)(mode - 12) <= 2))
        return;
    uint8_t knob = g_ui.rf_gain;
    float at_lo = cal + 110.0f, at_hi = cal + 80.0f;
    float slope = (at_hi - at_lo) / (knob_hi - knob_lo);
    float offset = (knob_hi * at_lo - knob_lo * at_hi) / (knob_hi - knob_lo);
    float open_below;
    if (knob <= 24)
        open_below = 256.0f;
    else if (knob <= 239)
        open_below = (float)knob * slope + offset;
    else
        open_below = at_hi;
    squelch_decide((float)(uint8_t)dsp_signal_level(), open_below, knob <= 24 ? 0.0f : 6.0f);
}
