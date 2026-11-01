/* The MAIN -> IF DSP register link on SCI4, recreated for T24 (docs/code/main/dsp-link.md): the frame layer
 * (app/reglink.h, shared with the SDR link) and the simple register setters of the poller's chain. The shadows are
 * filled by dsp_shadow_store from the replies. */
#include "main.h"
#include "main_ram.h"
#include "reglink.h"

#define DSP_REPLY_TIMER 3    /* soft timer of the reply timeout [fact: swtimer_start(3, 6), 0xFFFA0BFB] */

/* dsp_shadow (RAM 0x1B634, uint16 each): slot of each register [fact: the offset each setter compares] */
enum dsp_shadow_slot {
    SH_DEMOD = 5,  /* reg 0x06 */
    SH_R08 = 6, SH_R09 = 7, SH_R0A = 8, SH_R0C = 9, SH_R0D = 10, SH_R0E = 11, SH_R0F = 12,
    SH_R11 = 14, SH_R12 = 15, SH_R13 = 16,
    SH_R30 = 31,
    SH_R36 = 37, SH_R37 = 38, SH_R38 = 39,
    SH_R51 = 59, SH_R56 = 64, SH_AFFFT_ATT = 67 /* reg 0x5C */, SH_CW_PITCH = 70 /* reg 0x61 */,
    SH_R68 = 77,
};

/* vfo_mode() codes (docs/code/main/radio-control.md) [fact: the switch in dsp_set_demod 0xFFF9D9A7] */
enum dsp_demod { DEMOD_CW_U = 0, DEMOD_CW_L = 1, DEMOD_USB = 2, DEMOD_LSB = 3, DEMOD_AM = 8, DEMOD_FM = 9 };

static const struct reglink dsp_link = {
    .frame = dsp_tx_frame, .reg = &dsp_tx_reg, .data = &dsp_tx_data, .shadow = dsp_shadow,
    .busy_write = &dsp_busy_write, .busy_read = &dsp_busy_read, .timer = DSP_REPLY_TIMER,
    .sum8 = dsp_sum8, .sum_ok = dsp_reply_sum_ok, .send = sci4_send, .rx_ready = sci4_rx_ready, .rx_buf = sci4_rx_buf,
};

/* dsp_sum8 0xFFFA0C01 */
uint8_t dsp_sum8(const uint8_t *p, uint8_t n)
{
    return link_sum8(p, n);
}

/* dsp_reply_sum_ok 0xFFFA0C2E */
uint8_t dsp_reply_sum_ok(const uint8_t *p, uint8_t n)
{
    return link_sum_ok(&dsp_link, p, n);
}

/* dsp_check_reply 0xFFFA0AD6 */
uint8_t dsp_check_reply(uint8_t kind, uint8_t **reply)
{
    return link_check_reply(&dsp_link, kind, reply);
}

/* dsp_send_frame 0xFFFA0B4C */
void dsp_send_frame(uint8_t kind)
{
    link_send_frame(&dsp_link, kind);
}

static inline void dsp_write_if_changed(uint16_t reg, enum dsp_shadow_slot slot, uint16_t value)
{
    link_write_if_changed(&dsp_link, dsp_send_frame, reg, slot, value);
}

/* dsp_set_demod 0xFFF9D9A7: reg 6, the demodulator of VFO 0's mode */
void dsp_set_demod(void)
{
    uint16_t demod;

    switch (vfo_mode(0)) {
    case 0: case 8: case 12:
        demod = DEMOD_LSB;
        break;
    case 1: case 9: case 13: case 14:
        demod = DEMOD_USB;
        break;
    case 2:
        demod = DEMOD_CW_L;
        break;
    case 4: case 5:
        demod = DEMOD_AM;
        break;
    case 6: case 7: case 10: case 11:
        demod = DEMOD_FM;
        break;
    default:
        demod = DEMOD_CW_U;
        break;
    }
    dsp_write_if_changed(0x06u, SH_DEMOD, demod);
}

/* dsp_set_r08 .. dsp_set_r0e: the audio-route registers from dsp_route_param's tables (the argument is unused) */
void dsp_set_r08(uint8_t unused) { dsp_write_if_changed(0x08u, SH_R08, dsp_route_param(0x08u)); }
void dsp_set_r09(uint8_t unused) { dsp_write_if_changed(0x09u, SH_R09, dsp_route_param(0x09u)); }
void dsp_set_r0a(uint8_t unused) { dsp_write_if_changed(0x0Au, SH_R0A, dsp_route_param(0x0Au)); }
void dsp_set_r0d(uint8_t unused) { dsp_write_if_changed(0x0Du, SH_R0D, dsp_route_param(0x0Du)); }
void dsp_set_r0e(uint8_t unused) { dsp_write_if_changed(0x0Eu, SH_R0E, dsp_route_param(0x0Eu)); }

/* constant registers, written once after the DSP starts (the shadow then holds the value) [fact: the constants] */
void dsp_set_r0c(void) { dsp_write_if_changed(0x0Cu, SH_R0C, 0x0000u); }
void dsp_set_r0f(void) { dsp_write_if_changed(0x0Fu, SH_R0F, 0x002Bu); }
void dsp_set_r11(void) { dsp_write_if_changed(0x11u, SH_R11, 0xFFA2u); }
void dsp_set_r12(void) { dsp_write_if_changed(0x12u, SH_R12, 0x0008u); }
void dsp_set_r13(void) { dsp_write_if_changed(0x13u, SH_R13, 0xFFF8u); }
void dsp_set_r36(void) { dsp_write_if_changed(0x36u, SH_R36, 0x0000u); }
void dsp_set_r37(void) { dsp_write_if_changed(0x37u, SH_R37, 0x0000u); }
void dsp_set_r38(void) { dsp_write_if_changed(0x38u, SH_R38, 0x0000u); }
void dsp_set_r51(void) { dsp_write_if_changed(0x51u, SH_R51, 0x0000u); }
void dsp_set_r56(void) { dsp_write_if_changed(0x56u, SH_R56, 0x0020u); }
void dsp_set_r68(void) { dsp_write_if_changed(0x68u, SH_R68, 0x0094u); }

/* dsp_set_r30 0xFFF9E21F: reg 0x30 = 0xFF while VFO 1 is in an FM mode; never written back [fact] */
void dsp_set_r30(void)
{
    uint8_t mode = vfo_mode(1);

    if (mode == 11 || mode == 7 || mode == 10 || mode == 6)
        dsp_write_if_changed(0x30u, SH_R30, 0x00FFu);
}

/* dsp_set_affft_att 0xFFF9F57B: reg 0x5C = AF-FFT attenuator << 8 | 0x1000 */
void dsp_set_affft_att(void)
{
    dsp_write_if_changed(0x5Cu, SH_AFFFT_ATT, (uint16_t)(0x1000u | (uint16_t)(menu_affft_att << 8)));
}

/* dsp_set_cw_pitch 0xFFF9F638: reg 0x61 = (KEY PITCH + 30) * 10 Hz | 0x1000 */
void dsp_set_cw_pitch(void)
{
    dsp_write_if_changed(0x61u, SH_CW_PITCH, (uint16_t)((uint16_t)(menu_cw_pitch + 30u) * 10u | 0x1000u));
}
