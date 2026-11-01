/* The FUNC knob's setting pop-ups of the MAIN image (T24, UI track; docs/code/main/ui-keys.md). Each FUNC-knob
 * function has an entry that stores its pop-up code in g_ui.popup_code and a step function that (re)opens the pop-up
 * for the POP-UP TIME of that code and adds the knob's steps to one setting, clamped [fact: the pairs
 * 0xFFFC6FFE..0xFFFC7D41]. The settings are the ones the DISPLAY shows in the pop-up slot of that code
 * (docs/code/display/gui.md, #178).
 *
 * The step arithmetic is the image's: setting + steps (a signed byte) as a signed 16-bit value, then "if v >= max + 1:
 * max, else if v < min: min", and the low byte stored [fact: e.g. funcknob_peak_step 0xFFFC7084..0xFFFC70A9]. */
#include <stdint.h>
#include "main.h"
#include "ft710_state.h"

extern struct ui_state *g_ui_ptr_d58;          /* 0x25D58 = &g_ui */

uint8_t *scope_level_cur_ptr(void);
uint8_t *mic_gain_ptr(void);
uint8_t *moni_level_ptr(void);

/* pop-up codes (g_ui.popup_code) [fact: the constants of each pair] */
enum {
    POPUP_SCOPE_LEVEL = 0x1E, POPUP_PEAK = 0x1F, POPUP_COLOR = 0x0B, POPUP_CONTRAST = 0x22, POPUP_DIMMER = 0x23,
    POPUP_MIC_GAIN = 0x25, POPUP_PROC_LEVEL = 0x27, POPUP_AMC_LEVEL = 0x28, POPUP_VOX_GAIN = 0x29,
    POPUP_VOX_DELAY = 0x2A, POPUP_ANTI_VOX = 0x2B, POPUP_MONI_LEVEL = 0x2D, POPUP_CW_SPEED = 0x30,
    POPUP_CW_PITCH = 0x31, POPUP_BK_DELAY = 0x32, POPUP_AESS_LEVEL = 0x33, POPUP_NB_LEVEL = 0x38,
    POPUP_KEYER = 0x46, POPUP_AESS_CF = 0x58,
};

static void popup_show(uint8_t code)
{
    popup_open_timed(popup_duration_get(code));
}

/* setting + steps clamped to lo..hi as the image does it */
static uint8_t knob_add(uint8_t cur, int8_t steps, int16_t lo, int16_t hi)
{
    int16_t v = (int16_t)(cur + steps);
    /* compare and branch as the image does: GCC would fold the clamp into MAX/MIN, and with those the emulation
     * stored the setting unchanged where the original stored cur + steps (funcknob_peak_step, trial 0: 0 + 2 -> 2).
     * Open: whether rx62t's p-code for MAX #imm / MIN #imm is wrong; would be settled by rx_semcheck.py cases */
    if (v >= hi + 1) {
        __asm__ volatile("");
        v = hi;
    } else if (v < lo) {
        __asm__ volatile("");
        v = lo;
    }
    return (uint8_t)v;
}

/* the entry: pop-up code, then the step function [fact: each entry 0xFFFC6FFE, 0xFFFC7053, ...] */
#define FUNCKNOB_ENTRY(name, code)            \
    void name##_step(int8_t steps);           \
    void name(int8_t steps)                   \
    {                                         \
        g_ui_ptr_d58->popup_code = (code);    \
        name##_step(steps);                   \
    }

FUNCKNOB_ENTRY(funcknob_scope_level, POPUP_SCOPE_LEVEL)
FUNCKNOB_ENTRY(funcknob_peak, POPUP_PEAK)
FUNCKNOB_ENTRY(funcknob_contrast, POPUP_CONTRAST)
FUNCKNOB_ENTRY(funcknob_dimmer, POPUP_DIMMER)
FUNCKNOB_ENTRY(funcknob_mic_gain, POPUP_MIC_GAIN)
FUNCKNOB_ENTRY(funcknob_proc_level, POPUP_PROC_LEVEL)
FUNCKNOB_ENTRY(funcknob_amc_level, POPUP_AMC_LEVEL)
FUNCKNOB_ENTRY(funcknob_vox_gain, POPUP_VOX_GAIN)
FUNCKNOB_ENTRY(funcknob_vox_delay, POPUP_VOX_DELAY)
FUNCKNOB_ENTRY(funcknob_anti_vox, POPUP_ANTI_VOX)
FUNCKNOB_ENTRY(funcknob_moni_level, POPUP_MONI_LEVEL)
FUNCKNOB_ENTRY(funcknob_cw_speed, POPUP_CW_SPEED)
FUNCKNOB_ENTRY(funcknob_cw_pitch, POPUP_CW_PITCH)
FUNCKNOB_ENTRY(funcknob_bk_delay, POPUP_BK_DELAY)
FUNCKNOB_ENTRY(funcknob_aess_level, POPUP_AESS_LEVEL)
FUNCKNOB_ENTRY(funcknob_aess_cf, POPUP_AESS_CF)

/* funcknob_scope_level_step 0xFFFC7016: the current scope level (scope_level_cur_ptr) 0..120 [fact] */
void funcknob_scope_level_step(int8_t steps)
{
    popup_show(POPUP_SCOPE_LEVEL);
    uint8_t *p = scope_level_cur_ptr();
    *p = knob_add(*p, steps, 0, 120);
}

/* funcknob_peak_step 0xFFFC706B: PEAK (ss01_peak) 0..4 [fact] */
void funcknob_peak_step(int8_t steps)
{
    popup_show(POPUP_PEAK);
    g_opstate.ss01_peak = knob_add(g_opstate.ss01_peak, steps, 0, 4);
}

/* funcknob_color_popup 0xFFFC70AF: COLOR pop-up, its cursor on the current value [fact] */
void funcknob_color_popup(void)
{
    popup_show(POPUP_COLOR);
    g_ui_ptr_d58->popup_code = POPUP_COLOR;
    g_ui_ptr_d58->popup_cursor = g_opstate.ss03_value;
}

/* funcknob_contrast_step 0xFFFC70F3 / funcknob_dimmer_step 0xFFFC715D: TFT contrast / brightness 0..20, then the
 * DISPLAY frame 0x24 request [fact] */
void funcknob_contrast_step(int8_t steps)
{
    popup_show(POPUP_CONTRAST);
    g_opstate.tft_contrast = knob_add(g_opstate.tft_contrast, steps, 0, 20);
    g_ui_ptr_d58->dl_req_24 = 1;
}

void funcknob_dimmer_step(int8_t steps)
{
    popup_show(POPUP_DIMMER);
    g_opstate.tft_brightness = knob_add(g_opstate.tft_brightness, steps, 0, 20);
    g_ui_ptr_d58->dl_req_24 = 1;
}

/* funcknob_mic_gain_step 0xFFFC7506: the MIC GAIN of the current mode (mic_gain_ptr, none: nothing) 0..100 [fact] */
void funcknob_mic_gain_step(int8_t steps)
{
    popup_show(POPUP_MIC_GAIN);
    uint8_t *p = mic_gain_ptr();
    if (p != 0)
        *p = knob_add(*p, steps, 0, 100);
}

/* funcknob_proc_level_step 0xFFFC75D4, funcknob_amc_level_step 0xFFFC7631 (1..100), funcknob_vox_gain_step
 * 0xFFFC768C [fact] */
void funcknob_proc_level_step(int8_t steps)
{
    popup_show(POPUP_PROC_LEVEL);
    g_opstate.proc_level = knob_add(g_opstate.proc_level, steps, 0, 100);
}

void funcknob_amc_level_step(int8_t steps)
{
    popup_show(POPUP_AMC_LEVEL);
    g_opstate.amc_level = knob_add(g_opstate.amc_level, steps, 1, 100);
}

void funcknob_vox_gain_step(int8_t steps)
{
    popup_show(POPUP_VOX_GAIN);
    g_opstate.vox_gain = knob_add(g_opstate.vox_gain, steps, 0, 100);
}

/* funcknob_vox_delay_step 0xFFFC76E9 (0..33) / funcknob_anti_vox_step 0xFFFC7764 (0..100): the MIC or the DATA value
 * by VOX SELECT (EX030405) [fact] */
void funcknob_vox_delay_step(int8_t steps)
{
    popup_show(POPUP_VOX_DELAY);
    uint8_t *p = g_opstate.ex030405_vox_select == 0 ? &g_opstate.vox_delay[0] : &g_opstate.vox_delay[1];
    *p = knob_add(*p, steps, 0, 33);
}

void funcknob_anti_vox_step(int8_t steps)
{
    popup_show(POPUP_ANTI_VOX);
    uint8_t *p = g_opstate.ex030405_vox_select == 0 ? &g_opstate.antivox[0] : &g_opstate.antivox[1];
    *p = knob_add(*p, steps, 0, 100);
}

/* funcknob_moni_level_step 0xFFFC7923: the monitor level of the mode (moni_level_ptr) 0..100, then the frequency
 * refresh request [fact] */
void funcknob_moni_level_step(int8_t steps)
{
    popup_show(POPUP_MONI_LEVEL);
    uint8_t *p = moni_level_ptr();
    if (p != 0) {
        *p = knob_add(*p, steps, 0, 100);
        g_ui_ptr_d58->freq_refresh_req = 1;
    }
}

/* funcknob_keyer_step 0xFFFC7975: KEYER on with a positive step, off otherwise [fact] */
void funcknob_keyer_step(int8_t steps)
{
    popup_show(POPUP_KEYER);
    if (steps > 0) {
        if (g_opstate.keyer_on == 0)
            g_opstate.keyer_on = 1;
    } else if (g_opstate.keyer_on == 1) {
        g_opstate.keyer_on = 0;
    }
}

/* funcknob_cw_speed_step 0xFFFC7AA7 (4..60 wpm), funcknob_cw_pitch_step 0xFFFC7B02 (0..75), funcknob_bk_delay_step
 * 0xFFFC7B5F (0..33) [fact] */
void funcknob_cw_speed_step(int8_t steps)
{
    popup_show(POPUP_CW_SPEED);
    g_opstate.key_speed = knob_add(g_opstate.key_speed, steps, 4, 60);
}

void funcknob_cw_pitch_step(int8_t steps)
{
    popup_show(POPUP_CW_PITCH);
    g_opstate.cw_pitch = knob_add(g_opstate.cw_pitch, steps, 0, 75);
}

void funcknob_bk_delay_step(int8_t steps)
{
    popup_show(POPUP_BK_DELAY);
    g_opstate.cw_bkin_delay = knob_add(g_opstate.cw_bkin_delay, steps, 0, 33);
}

/* funcknob_aess_level_step 0xFFFC7BBC (0..20) / funcknob_aess_cf_step 0xFFFC7C15 (0..1): the AESS setting of the
 * mode, its pointer taken before the pop-up [fact] */
void funcknob_aess_level_step(int8_t steps)
{
    uint8_t *p = (uint8_t *)aess_level_ptr();
    popup_show(POPUP_AESS_LEVEL);
    *p = knob_add(*p, steps, 0, 20);
}

void funcknob_aess_cf_step(int8_t steps)
{
    uint8_t *p = (uint8_t *)aess_mode_ptr();
    popup_show(POPUP_AESS_CF);
    *p = knob_add(*p, steps, 0, 1);
}

/* funcknob_nb_level_step 0xFFFC7CFD: NB LEVEL 0..10 [fact] */
void funcknob_nb_level_step(int8_t steps)
{
    popup_show(POPUP_NB_LEVEL);
    g_opstate.nb_level = knob_add(g_opstate.nb_level, steps, 0, 10);
}
