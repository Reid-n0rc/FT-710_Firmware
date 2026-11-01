/* Meters and squelch of the MAIN image (T24 MAIN round 5; docs/code/main/tx-protection.md "High SWR",
 * docs/code/main/eeprom.md "cfg105"): the float code of meter_task's meters (supply, SWR with the HI-SWR alarm, PO,
 * COMP, S) and the two squelch decisions of af_mute_update. Each result goes through one of the image's smoothing
 * helpers (FUN_fffb92e7 ...) into the meter byte the DISPLAY link sends. The floating-point steps keep the image's
 * order of operations, so every intermediate value is the same single-precision number; a CC-RX "x >= c" compiled as
 * "not (x < c)" with BLT, which is false for a NaN as in C [fact: FCMP sets O for an unordered pair, RXv2 manual
 * p. 90; tools/rx_fpu_check.py]. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "fpu_conv.h"

uint8_t dsp_fm_noise(void);
uint16_t dsp_comp_level(void);
uint16_t dsp_signal_level(void);
uint8_t blink_phase(int32_t which);
uint8_t tx_band_of_freq(uint32_t freq);
void vdd_scale_calc(void);
uint8_t FUN_fffb92e7(uint32_t pos);       /* the meter smoothing helpers: position in, displayed value out */
uint8_t FUN_fffb9422(uint32_t pos);
void FUN_fffb948b(float swr);
uint8_t FUN_fffb94f9(uint32_t pos);
uint8_t FUN_fffb959c(uint32_t pos);

#define BAND_50MHZ 10             /* tx_band_of_freq: the 50 MHz band, 50 W [fact: 0xFFFB77B0] */
#define TMR_S_METER 0x2A          /* meter_s updates when it has expired [fact: 0xFFFB796E] */
#define TUNE_CYCLE_TUNING 2       /* g_ui.tune_cycle_3d during a tuner cycle: the SWR meter is pinned at 255 */

/* meter_vdd 0xFFFB747C: the supply meter, AN003 / 16 (a byte) times the scale vdd_scale_calc leaves in 0x20FC0 */
void meter_vdd(void)
{
    uint8_t raw = (uint8_t)(g_ui.adc_pa_vdd >> 4);
    vdd_scale_calc();
    uint16_t pos = (uint16_t)ftou((float)raw * vdd_scale);
    if (pos > 0xFF)
        pos = 0xFF;
    meter_vdd_val = FUN_fffb92e7((uint8_t)pos);
}

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
    swr_value = swr;
    FUN_fffb948b(swr);

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
    meter_swr_pos = (uint8_t)pos;
    meter_swr_val = FUN_fffb9422((uint8_t)pos);
}

/* the PO meter's segments: the first row whose watts bound is <= the power gives the position slope * W + offset
 * [fact: ROM 0xFFF88C74, 8 rows of {bound, slope, offset}, bounds 100 .. 0 W] */
struct meter_seg {
    float bound, slope, offset;
};
extern const struct meter_seg po_meter_segs[8];

/* meter_po 0xFFFB7772: forward power in watts from AN002, P = x^2 (Pmax - k s) / s^2 + k x with s the PO-meter
 * scale x 16 and k = 0.00694025, Pmax 50 W on 50 MHz else 100 W (eeprom.md "PO"), then the segment table */
void meter_po(void)
{
    const float k = 0.00694025f;      /* 0x3BE36B09 [fact: 0xFFFB7775] */
    const float zero = 0.0f;          /* the image subtracts and adds it [fact: 0xFFFB77CF, 0xFFFB77ED] */
    float x = (float)g_ui.adc_mcup_for;
    float s = (float)((uint32_t)g_ui.po_meter_scale << 4);
    float pmax = tx_band_of_freq(g_ui.freq_tx) == BAND_50MHZ ? 50.0f : 100.0f;
    float coef = (pmax - s * k - zero) / (s * s);
    float watts = x * coef * x + x * k + zero;

    float slope = 0.0f, offset = 0.0f;   /* not reached for a number: the last bound is 0 and watts >= 0; for a NaN
                                          * the image keeps two stack words, and the result is 0xFF either way */
    for (uint8_t i = 0; i < 8; i++) {
        if (!is_nan(watts) && watts >= po_meter_segs[i].bound) {    /* scale 0 and no power: 0 x inf */
            slope = po_meter_segs[i].slope;
            offset = po_meter_segs[i].offset;
            break;
        }
    }
    float pos = slope * watts + offset;
    if (pos > 255.0f)
        pos = 255.0f;
    meter_po_val = FUN_fffb94f9((uint8_t)ftou(pos));
}

/* meter_comp 0xFFFB7869: the processor's compression in dB from the DSP (high byte with PROC level 0, else the low
 * byte), positions 103 / 190 / 248 at 10 / 20 / 30 [fact: 0xFFFB786C..0xFFFB7875] */
void meter_comp(void)
{
    const float pos10 = 103.0f, pos20 = 190.0f, pos30 = 248.0f;
    uint16_t raw;
    if (g_opstate.proc_level == 0)
        raw = dsp_comp_level() >> 8;
    else
        raw = (uint8_t)dsp_comp_level();
    float db = (float)raw;

    float slope, offset;
    if (db <= 10.0f) {
        slope = pos10 / 10.0f;
        offset = 0.0f;
    } else if (db <= 20.0f) {
        slope = (pos20 - pos10) / 10.0f;
        offset = slope * -20.0f + pos20;
    } else {
        slope = (pos30 - pos20) / 10.0f;
        if (db <= 30.0f)
            offset = slope * -30.0f + pos30;
        else
            offset = slope * -31.0f + 255.0f;
    }
    uint16_t pos = (uint16_t)ftou(slope * db / 2.0f + offset);
    if (pos > 0xFF)
        pos = 0xFF;
    meter_comp_val = (uint8_t)pos;
}

/* the S meter's segments: the first row whose bound is >= (S+40 calibration - signal) gives slope and offset;
 * none: the row-9 values [fact: ROM 0xFFF88BFC, 10 rows of {slope, offset, bound}, read at 0xFFFB798E..0xFFFB79D0] */
extern const struct s_meter_seg { float slope, offset, bound; } s_meter_segs[10];

/* meter_s 0xFFFB7959: S meter from the DSP signal level against alignment item 041 (S-MTR +40), clamped to 0..255;
 * 0 while the TX lamp is on; only when soft timer 0x2A has expired */
void meter_s(void)
{
    float cal = (float)g_cfg105.a041_rx_s_mtr_40;
    uint8_t level = (uint8_t)dsp_signal_level();
    if (swtimer_expired(TMR_S_METER) == 0)
        return;
    float sig = (float)level;
    float below = cal - sig;
    float slope = s_meter_segs[9].slope, offset = s_meter_segs[9].offset;
    for (uint8_t i = 0; i < 10; i++) {
        if (below <= s_meter_segs[i].bound) {
            slope = s_meter_segs[i].slope;
            offset = s_meter_segs[i].offset;
            break;
        }
    }
    float pos = (cal - sig) * slope + offset;
    if (pos < 0.0f)
        pos = 0.0f;
    else if (pos > 255.0f)
        pos = 255.0f;
    if (g_ui.tx_lamp != 0) {
        meter_s_val = 0;
        return;
    }
    meter_s_val = FUN_fffb959c((uint8_t)ftou(pos));
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
