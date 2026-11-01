/* The MAIN -> IF DSP register link on SCI4, recreated for T24 (docs/code/main/dsp-link.md): the frame layer
 * (app/reglink.h, shared with the SDR link) and the simple register setters of the poller's chain. The shadows are
 * filled by dsp_shadow_store from the replies. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
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
    /* round 3 [fact: the shadow address each setter compares, 0x1B634 + 2 x slot] */
    SH_TX_GAIN = 17 /* 0x20 */, SH_VOX_GAIN = 18 /* 0x21 */, SH_ANTIVOX = 19 /* 0x22 */,
    SH_PEQ_FREQ = 20 /* 0x25, 0x28, 0x2B */, SH_PEQ_LEVEL = 23 /* 0x26, 0x29, 0x2C */, SH_PEQ_BW = 26 /* 0x27, 0x2A, 0x2D */,
    SH_PROC = 29 /* 0x2E */, SH_TX_BPF = 30 /* 0x2F */, SH_R31 = 32, SH_R32 = 33, SH_AMC_RELEASE = 34 /* 0x33 */,
    SH_AMC_LEVEL = 35 /* 0x34 */, SH_CTCSS_ENC = 36 /* 0x35 */, SH_FM_FLAG = 40 /* 0x3A */, SH_R3B = 41,
    SH_DNR_R40 = 42 /* 0x40 */, SH_DNF = 43 /* 0x41 */, SH_CONTOUR = 44 /* 0x42 */, SH_CONTOUR_LEVEL = 45 /* 0x43 */,
    SH_CONTOUR_WIDTH = 46 /* 0x44 */, SH_APF = 47 /* 0x45 */, SH_AM_NOTCH = 60 /* 0x52 */, SH_CTCSS_DEC = 61 /* 0x53 */,
    SH_OSC = 68 /* 0x5D */, SH_RF_GAIN = 76 /* 0x67 */, SH_DNR_400B = 78, SH_DNR_400D = 79, SH_AESS = 80 /* 0x4020 */,
    SH_DNR_4022 = 81, SH_DNR_4023 = 82, SH_DNR_4025 = 83, SH_DNR_4026 = 84,
    SH_HCUT = 48 /* 0x46 */, SH_LCUT = 49 /* 0x47 */, SH_AGC_ON = 71 /* 0x62 */, SH_FREQ_RANGE = 72 /* 0x63 */,
    SH_AGC_DELAY = 75 /* 0x66 */,
    SH_TONE_FREQ = 50 /* 0x48, 0x4B, 0x4E */, SH_TONE_GAIN = 53 /* 0x49, 0x4C, 0x4F */, SH_TONE_Q = 56 /* 0x4A, 0x4D, 0x50 */,
};


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
        demod = DSP_DEMOD_LSB;
        break;
    case 1: case 9: case 13: case 14:
        demod = DSP_DEMOD_USB;
        break;
    case 2:
        demod = DSP_DEMOD_CW_L;
        break;
    case 4: case 5:
        demod = DSP_DEMOD_AM;
        break;
    case 6: case 7: case 10: case 11:
        demod = DSP_DEMOD_FM;
        break;
    default:
        demod = DSP_DEMOD_CW_U;
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

/* --- the TX audio, EQ, tone and DNR setters (round 3). Mode codes are enum radio_mode (enums_main.h). --- */

static inline int mode_fm(uint8_t m)          /* FM, FM-N, DATA-FM, DATA-FM-N */
{
    return m == MODE_FM || m == MODE_FM_N || m == MODE_DATA_FM || m == MODE_DATA_FM_N;
}

static inline int mode_cw(uint8_t m)
{
    return m == MODE_CW_L || m == MODE_CW_U;
}

static inline int mode_am(uint8_t m)
{
    return m == MODE_AM || m == MODE_AM_N;
}

/* a voice message is being played on the air: the TX audio registers go to their neutral values [fact: the same
 * test in dsp_set_tx_gain, _proc, _tx_bpf, _r31, _r32, _amc_*, _ctcss_enc, _fm_flag] */
static inline int msg_playing(void)
{
    return g_ui.audio_playing == 1 && g_ui.playlist_cmd != 0;
}

/* the per-mode block of a record whose flags the DSP setters read: SSB, CW, RTTY, DATA/PSK, AM; none in FM
 * [fact: the record offsets of dsp_set_dnf 0xFFF9E7C4 and dsp_set_contour 0xFFF9E871] */
static const struct mode_blk *dsp_mode_blk(const struct vfo_rec *r, uint8_t m)
{
    if (m == MODE_PSK || m == MODE_DATA_L || m == MODE_DATA_U)
        return &r->blk[3];
    if (mode_cw(m))
        return &r->blk[1];
    if (mode_am(m))
        return &r->blk[4];
    if (m == MODE_RTTY_L || m == MODE_RTTY_U)
        return &r->blk[2];
    if (m == MODE_LSB || m == MODE_USB)
        return &r->blk[0];
    return NULL;
}

static inline uint16_t be16(const uint8_t *p)
{
    return (uint16_t)(p[0] << 8 | p[1]);
}

/* dsp_set_tx_gain 0xFFF9DBF7: reg 0x20, the modulation gain; the route table gives it, or 0xFFFF = the curve of
 * the MIC/USB/REAR gain, 0xFFFE = the curve of the level at 0x9DC2 */
void dsp_set_tx_gain(void)
{
    uint16_t v = dsp_route_param(0x20u);
    uint8_t gain = tx_mod_gain();

    if (v == 0xFFFFu)
        v = FUN_fffb34e4(gain);
    else if (v == 0xFFFEu)
        v = FUN_fffb350e(g_opstate.level_9dc2);
    if (msg_playing())
        v = 0;
    dsp_write_if_changed(0x20u, SH_TX_GAIN, v);
}

/* dsp_set_vox_gain 0xFFF9DC8A: reg 0x21 = -(VOX GAIN + curve(100 - modulation gain) + 29) */
void dsp_set_vox_gain(void)
{
    uint8_t gain = tx_mod_gain();
    uint16_t curve = FUN_fffb3538((uint8_t)(100u - gain));

    dsp_write_if_changed(0x21u, SH_VOX_GAIN, (uint16_t)-(uint16_t)(g_opstate.vox_gain + curve + 29u));
}

/* dsp_set_antivox 0xFFF9DCE4: reg 0x22 = -(ANTI VOX - curve(AF gain) + 50), the ANTI VOX of the VOX SELECT
 * (1, 2: the second); 0xFF with phones in */
void dsp_set_antivox(void)
{
    uint8_t select = g_opstate.ex030405_vox_select;
    uint8_t af = FUN_fffb3523(g_ui.af_gain);
    uint16_t v;

    if (ear_det()) {
        v = 0xFF;
    } else {
        uint8_t level = g_opstate.antivox[0];

        if ((uint8_t)(select - 1u) < 2u)
            level = g_opstate.antivox[1];
        v = (uint16_t)-(uint16_t)(level - af + 50u);
    }
    dsp_write_if_changed(0x22u, SH_ANTIVOX, v);
}

/* dsp_set_peq_freq 0xFFF9DD6A: regs 0x25/0x28/0x2B, band 1..3 of the parametric mic EQ: frequency, | 0x1000 while
 * the EQ is on. With the processor on (PROC level != 0) the "P-PRMTRC" set is used. Off in CW and DATA/RTTY/PSK,
 * while transmitting in the TX states 4 and 9..11 of 0x12041, with the LM1 flag, when the route table has 0 for the
 * register or the frequency is 0 */
void dsp_set_peq_freq(uint8_t band)
{
    uint8_t proc = g_opstate.proc_level;
    uint8_t on = g_opstate.proc_on;
    uint8_t m = vfo_mode(0);
    uint8_t t;
    uint16_t f, reg;
    unsigned slot;

    if ((uint8_t)(m - 2u) < 2u || (uint8_t)(m - 8u) < 7u)
        on = 0;
    t = FUN_fffb2dfe();
    if ((t == 4u || (uint8_t)(t - 9u) < 3u) && g_ui.transmitting != 0)
        on = 0;
    if (g_ui.dvs_lm1_flag != 0)
        on = 0;
    if (band == 2) {
        f = proc ? g_opstate.ex030317_p_prmtrc_eq3_freq : g_opstate.ex030308_prmtrc_eq3_freq;
        if (f != 0)
            f = (uint16_t)(f * 100u + 1400u);
        slot = SH_PEQ_FREQ + 2;
        reg = 0x2B;
    } else if (band == 1) {
        f = proc ? g_opstate.ex030314_p_prmtrc_eq2_freq : g_opstate.ex030305_prmtrc_eq2_freq;
        if (f != 0)
            f = (uint16_t)(f * 100u + 600u);
        slot = SH_PEQ_FREQ + 1;
        reg = 0x28;
    } else if (band == 0) {
        f = proc ? g_opstate.ex030311_p_prmtrc_eq1_freq : g_opstate.ex030302_prmtrc_eq1_freq;
        f = (uint16_t)(f * 100u);
        slot = SH_PEQ_FREQ;
        reg = 0x25;
    } else {
        return;
    }
    if (dsp_route_param(reg) == 0 || f == 0)
        on = 0;
    dsp_write_if_changed(reg, slot, on ? (uint16_t)(f | 0x1000u) : f);
}

/* a menu byte holding a signed value (-n as 0x80 | ...: two's complement of a byte) as the 16-bit register value */
static inline uint16_t s8_to_u16(uint8_t b)
{
    return (b & 0x80u) ? (uint16_t)-(uint16_t)(uint8_t)(-b) : b;
}

/* dsp_set_peq_level 0xFFF9DEE6: regs 0x26/0x29/0x2C, EQ band level, signed */
void dsp_set_peq_level(uint8_t band)
{
    uint8_t proc = g_opstate.proc_level;
    uint8_t level;

    if (band == 2)
        level = proc == 0 ? g_opstate.ex030309_prmtrc_eq3_level : g_opstate.ex030318_p_prmtrc_eq3_level;
    else if (band == 1)
        level = proc == 0 ? g_opstate.ex030306_prmtrc_eq2_level : g_opstate.ex030315_p_prmtrc_eq2_level;
    else if (band == 0)
        level = proc == 0 ? g_opstate.ex030303_prmtrc_eq1_level : g_opstate.ex030312_p_prmtrc_eq1_level;
    else
        return;
    dsp_write_if_changed((uint16_t)(0x26u + 3u * band), SH_PEQ_LEVEL + band, s8_to_u16(level));
}

/* dsp_set_peq_bw 0xFFF9DFD5: regs 0x27/0x2A/0x2D, EQ band width */
void dsp_set_peq_bw(uint8_t band)
{
    uint8_t proc = g_opstate.proc_level;
    uint8_t bw;

    if (band == 2)
        bw = proc == 0 ? g_opstate.ex030310_prmtrc_eq3_bwth : g_opstate.ex030319_p_prmtrc_eq3_bwth;
    else if (band == 1)
        bw = proc == 0 ? g_opstate.ex030307_prmtrc_eq2_bwth : g_opstate.ex030316_p_prmtrc_eq2_bwth;
    else if (band == 0)
        bw = proc == 0 ? g_opstate.ex030304_prmtrc_eq1_bwth : g_opstate.ex030313_p_prmtrc_eq1_bwth;
    else
        return;
    dsp_write_if_changed((uint16_t)(0x27u + 3u * band), SH_PEQ_BW + band, bw);
}

/* dsp_set_proc 0xFFF9E0AD: reg 0x2E, speech processor level | 0x1000, in LSB/USB only */
void dsp_set_proc(void)
{
    uint16_t v = vfo_mode(1) < 2u ? g_opstate.proc_level : 0u;

    if (msg_playing())
        v = 0;
    if (v != 0)
        v |= 0x1000u;
    dsp_write_if_changed(0x2Eu, SH_PROC, v);
}

/* dsp_set_tx_bpf 0xFFF9E12B: reg 0x2F = TX BPF SEL + 1 of the mode group (SSB 010113, AM 010213, DATA/PSK
 * 010413; the active preset's instead while PRESET is on), 1 in the other modes */
void dsp_set_tx_bpf(void)
{
    uint8_t m = vfo_mode(1);
    uint8_t sel = 0;
    uint16_t v;

    if (m == MODE_PSK || m == MODE_DATA_L || m == MODE_DATA_U)
        sel = g_opstate.preset_on == 0 ? g_opstate.ex010413_tx_bpf_sel : g_ui.preset_active.tx_bpf_sel;
    else if (mode_am(m))
        sel = g_opstate.preset_on == 0 ? g_opstate.ex010213_tx_bpf_sel : g_ui.preset_active.tx_bpf_sel;
    else if (m < 2u)
        sel = g_opstate.preset_on == 0 ? g_opstate.ex010113_tx_bpf_sel : g_ui.preset_active.tx_bpf_sel;
    v = (uint16_t)(sel + 1u);
    if (msg_playing())
        v = 0;
    dsp_write_if_changed(0x2Fu, SH_TX_BPF, v);
}

/* regs 0x31, 0x32, 0x3B: one constant per mode group: AM, FM, the others; no write for a mode code above 14 */
static void dsp_set_mode_const(uint16_t reg, unsigned slot, int16_t other, int16_t am, int16_t fm, int mute)
{
    uint8_t m = vfo_mode(1);
    int16_t v;

    if (mode_am(m))
        v = am;
    else if (mode_fm(m))
        v = fm;
    else if (m <= MODE_PSK)
        v = other;
    else
        return;
    if (mute && msg_playing())
        v = other;
    dsp_write_if_changed(reg, slot, (uint16_t)v);
}

/* dsp_set_r31 0xFFF9E26B, dsp_set_r32 0xFFF9E330, dsp_set_r3b 0xFFF9E6B9 */
void dsp_set_r31(void)
{
    dsp_set_mode_const(0x31u, SH_R31, -43, -54, -56, 1);
}

void dsp_set_r32(void)
{
    dsp_set_mode_const(0x32u, SH_R32, -43, -54, -56, 1);
}

void dsp_set_r3b(void)
{
    dsp_set_mode_const(0x3Bu, SH_R3B, -39, -50, -52, 0);
}

/* dsp_set_amc_release 0xFFF9E3F5: reg 0x33, AMC RELEASE TIME 0/1/2 -> 0x11/0x12/0x13, 0x0C in FM */
void dsp_set_amc_release(void)
{
    uint16_t v;

    if (g_opstate.ex030301_amc_release_time == 1)
        v = 0x12;
    else if (g_opstate.ex030301_amc_release_time == 0)
        v = 0x11;
    else
        v = 0x13;
    if (mode_fm(vfo_mode(1)))
        v = 0x0C;
    if (msg_playing())
        v = 0x11;
    dsp_write_if_changed(0x33u, SH_AMC_RELEASE, v);
}

/* dsp_set_amc_level 0xFFF9E480: reg 0x34, AMC OUTPUT LEVEL | 0x1000; 100 in FM, off in CW and RTTY */
void dsp_set_amc_level(void)
{
    uint8_t m = vfo_mode(1);
    uint16_t v;

    if (mode_cw(m) || m == MODE_RTTY_L || m == MODE_RTTY_U)
        v = 0;
    else if (mode_fm(m))
        v = 100;
    else
        v = g_opstate.amc_level;
    if (msg_playing())
        v = 0;
    if (v != 0)
        v |= 0x1000u;
    dsp_write_if_changed(0x34u, SH_AMC_LEVEL, v);
}

/* the record's tone mode (flags3 bits 3..5; 0 = off) */
static inline uint8_t tone_mode(const struct vfo_rec *r)
{
    return (uint8_t)((r->flags3 & 0x38u) >> 3);
}

/* dsp_set_ctcss_enc 0xFFF9E51C: reg 0x35, TX tone number + 1 | 0x1000 in FM with a tone mode */
void dsp_set_ctcss_enc(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(1);
    uint8_t mode3 = r->flags3;
    uint8_t m = vfo_mode(1);
    uint16_t v = 0;

    if (((mode3 & 0x38u) >> 3) != 0 && mode_fm(m))
        v = (uint16_t)((r->tone_num + 1u) | 0x1000u);
    if (msg_playing())
        v = 0;
    dsp_write_if_changed(0x35u, SH_CTCSS_ENC, v);
}

/* dsp_set_fm_flag 0xFFF9E644: reg 0x3A = 1 in FM */
void dsp_set_fm_flag(uint8_t which)
{
    uint16_t v = mode_fm(vfo_mode(which)) ? 1u : 0u;

    if (msg_playing())
        v = 0;
    dsp_write_if_changed(0x3Au, SH_FM_FLAG, v);
}

/* the DNR registers: per register a table of 16 values by DNR level (ROM 0xFFF87F1A, 0x20 bytes apart: 0x400B,
 * 0x400D, 0x4022, 0x4023, 0x4025, 0x40, 0x4026 [fact: the table address in each setter]), 0 with DNR off or in FM */
extern const int16_t dnr_tables[7][16];

enum dnr_table { DNR_400B, DNR_400D, DNR_4022, DNR_4023, DNR_4025, DNR_R40, DNR_4026 };

static void dsp_set_dnr(uint8_t which, uint16_t reg, unsigned slot, enum dnr_table t)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(which);
    uint8_t dnr = r->dnr;
    uint8_t m = vfo_mode(which);
    uint16_t v = 0;

    if ((dnr & 0x10u) != 0 && !mode_fm(m))
        v = (uint16_t)dnr_tables[t][dnr & 0x0Fu];
    dsp_write_if_changed(reg, slot, v);
}

/* dsp_set_dnr_r40 0xFFF9E750, _400b 0xFFF9FCD0, _400d 0xFFF9FD51, _4022 0xFFF9FE2A, _4023 0xFFF9FEAF, _4025
 * 0xFFF9FF30, _4026 0xFFF9FFB1 */
void dsp_set_dnr_r40(uint8_t which) { dsp_set_dnr(which, 0x40u, SH_DNR_R40, DNR_R40); }
void dsp_set_dnr_400b(uint8_t which) { dsp_set_dnr(which, 0x400Bu, SH_DNR_400B, DNR_400B); }
void dsp_set_dnr_400d(uint8_t which) { dsp_set_dnr(which, 0x400Du, SH_DNR_400D, DNR_400D); }
void dsp_set_dnr_4022(uint8_t which) { dsp_set_dnr(which, 0x4022u, SH_DNR_4022, DNR_4022); }
void dsp_set_dnr_4023(uint8_t which) { dsp_set_dnr(which, 0x4023u, SH_DNR_4023, DNR_4023); }
void dsp_set_dnr_4025(uint8_t which) { dsp_set_dnr(which, 0x4025u, SH_DNR_4025, DNR_4025); }
void dsp_set_dnr_4026(uint8_t which) { dsp_set_dnr(which, 0x4026u, SH_DNR_4026, DNR_4026); }

/* dsp_set_dnf 0xFFF9E7C4: reg 0x41, the BC (auto notch) bit of the mode's block */
void dsp_set_dnf(uint8_t which)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(which);
    const struct mode_blk *b = dsp_mode_blk(r, vfo_mode(which));

    dsp_write_if_changed(0x41u, SH_DNF, (b && (b->flags2 & 0x80u)) ? 1u : 0u);
}

/* dsp_set_contour 0xFFF9E871: reg 0x42, CONTOUR frequency x 10 Hz | 0x1000 while CONTOUR is on */
void dsp_set_contour(uint8_t which)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(which);
    const struct mode_blk *b = dsp_mode_blk(r, vfo_mode(which));
    uint16_t v = 0;

    if (b) {
        v = (uint16_t)(be16(b->contour_be) * 10u);
        if (b->flags & 0x40u)
            v |= 0x1000u;
    }
    dsp_write_if_changed(0x42u, SH_CONTOUR, v);
}

/* dsp_set_contour_level 0xFFF9E9A4: reg 0x43, CONTOUR LEVEL (signed) */
void dsp_set_contour_level(void)
{
    dsp_write_if_changed(0x43u, SH_CONTOUR_LEVEL, s8_to_u16((uint8_t)g_opstate.ex030205_contour_level));
}

/* dsp_set_contour_width 0xFFF9E9FA: reg 0x44 = 11 - CONTOUR WIDTH */
void dsp_set_contour_width(void)
{
    dsp_write_if_changed(0x44u, SH_CONTOUR_WIDTH, (uint16_t)(11u - g_opstate.ex030206_contour_width));
}

/* dsp_set_apf 0xFFF9EA39: reg 0x45, APF centre (KEY PITCH + 30 + APF offset) x 10 Hz, | (APF WIDTH + 2) << 12
 * while APF is on in CW */
void dsp_set_apf(uint8_t which)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(which);
    uint8_t offset = (uint8_t)g_opstate.apf_freq;
    uint8_t pitch = g_opstate.cw_pitch;
    uint8_t width = g_opstate.ex030204_apf_width;
    uint8_t m = vfo_mode(which);
    uint16_t v = (uint16_t)((uint16_t)(s8_to_u16(offset) + pitch + 30u) * 10u);

    if (mode_cw(m) && (r->blk[1].flags & 0x20u))
        v |= (uint16_t)((width + 2u) << 12);
    dsp_write_if_changed(0x45u, SH_APF, v);
}

/* dsp_set_am_notch 0xFFF9F430: reg 0x52, the manual NOTCH of the AM block x 10 Hz | 0x1000 (IF NOTCH WIDTH 0) or
 * 0x2000, in AM only */
void dsp_set_am_notch(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    uint16_t f = 0;
    uint8_t on = 0;

    if (mode_am(m)) {
        on = r->blk[4].flags & 0x80u;
        f = be16(r->blk[4].notch_be);
    }
    if (on == 0)
        f = 0;
    else
        f = (uint16_t)(f * 10u | (g_opstate.ex030201_if_notch_width == 0 ? 0x1000u : 0x2000u));
    dsp_write_if_changed(0x52u, SH_AM_NOTCH, f);
}

/* dsp_set_ctcss_dec 0xFFF9F4C8: reg 0x53, RX tone number + 1 | 0x1000 in FM with a tone mode; the tone mode in
 * use goes to g_ui.fm_tone_mode */
void dsp_set_ctcss_dec(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t tm = tone_mode(r);
    uint8_t m = vfo_mode(0);
    uint16_t v = 0;

    g_ui.fm_tone_mode = 0;
    if (tm != 0 && mode_fm(m)) {
        v = (uint16_t)((r->tone_num + 1u) | 0x1000u);
        g_ui.fm_tone_mode = tm;
    }
    dsp_write_if_changed(0x53u, SH_CTCSS_DEC, v);
}

/* dsp_set_osc 0xFFF9F5C6: reg 0x5D, oscilloscope level (RX or TX) << 8 | 0x1000 | time */
void dsp_set_osc(uint8_t tx)
{
    uint8_t level = tx == 0 ? g_opstate.osc_level_rx : g_opstate.osc_level_tx;

    dsp_write_if_changed(0x5Du, SH_OSC, (uint16_t)(level << 8 | 0x1000u | g_opstate.osc_time));
}

/* dsp_set_rf_gain 0xFFF9FC2A: reg 0x67, the RF gain curve (ROM 0xFFF805AC by gain / 4); 0xFF while the knob is
 * SQL (RF/SQL VR 1, or 2 in FM) */
extern const uint8_t rf_gain_curve[];

void dsp_set_rf_gain(void)
{
    uint16_t v = rf_gain_curve[g_ui.rf_gain >> 2];

    if (g_opstate.ex030102_rf_sql_vr == 1)
        v = 0xFF;
    else if (g_opstate.ex030102_rf_sql_vr == 2 && mode_fm(vfo_mode(0)))
        v = 0xFF;
    dsp_write_if_changed(0x67u, SH_RF_GAIN, v);
}

/* dsp_set_aess 0xFFF9FDD2: reg 0x4020, 0 with the AESS level 0, else 0x2000 | 700 or | 1000 Hz (the mode's AESS
 * byte) */
void dsp_set_aess(void)
{
    const uint8_t *level = (const uint8_t *)aess_level_ptr();
    const uint8_t *sel = (const uint8_t *)aess_mode_ptr();
    uint16_t v;

    if (*level == 0)
        v = 0;
    else if (*sel == 0)
        v = 0x2000u | 700u;
    else
        v = 0x2000u | 1000u;
    dsp_write_if_changed(0x4020u, SH_AESS, v);
}

/* The first ten items of each mode group's menu (EX0101 SSB, EX0102 AM, EX0103 FM, EX0104 DATA, EX0105 RTTY,
 * EX0201 CW) have the same order, so one view serves all six [fact: the field offsets in structs_main.h, asserted
 * below]. */
struct af_menu {
    uint8_t treble_gain, middle_gain, bass_gain;
    uint8_t agc_fast_delay, agc_mid_delay, agc_slow_delay;
    uint8_t lcut_freq, lcut_slope, hcut_freq, hcut_slope;
};

#define AF_MENU_CHECK(g)                                                                                             \
    _Static_assert(offsetof(struct opstate, ex##g##10_hcut_slope) - offsetof(struct opstate, ex##g##01_af_treble_gain) \
                   == 9, "EX" #g " layout");                                                                         \
    _Static_assert(offsetof(struct opstate, ex##g##07_lcut_freq) - offsetof(struct opstate, ex##g##01_af_treble_gain) \
                   == 6, "EX" #g " layout");
AF_MENU_CHECK(0101)
AF_MENU_CHECK(0102)
AF_MENU_CHECK(0103)
AF_MENU_CHECK(0104)
AF_MENU_CHECK(0105)
AF_MENU_CHECK(0201)

/* the mode group's menu: PSK and DATA-L/U -> DATA, CW, AM, FM and DATA-FM -> FM, RTTY, LSB/USB -> SSB; none above
 * PSK [fact: the compare chain of dsp_set_hcut 0xFFF9EAE7, dsp_set_lcut, dsp_set_tone_gain] */
static const struct af_menu *af_menu_of(uint8_t m)
{
    const void *first;

    if (m == MODE_PSK || m == MODE_DATA_L || m == MODE_DATA_U)
        first = &g_opstate.ex010401_af_treble_gain;
    else if (mode_cw(m))
        first = &g_opstate.ex020101_af_treble_gain;
    else if (mode_am(m))
        first = &g_opstate.ex010201_af_treble_gain;
    else if (mode_fm(m))
        first = &g_opstate.ex010301_af_treble_gain;
    else if (m == MODE_RTTY_L || m == MODE_RTTY_U)
        first = &g_opstate.ex010501_af_treble_gain;
    else if (m == MODE_LSB || m == MODE_USB)
        first = &g_opstate.ex010101_af_treble_gain;
    else
        return NULL;
    return (const struct af_menu *)first;
}

/* a cut filter register: (freq - 1) x 50 + base Hz | (slope + 1) << 12, 0 when the cut is off (freq 0); the
 * active preset's values while PRESET is on */
static uint16_t cut_value(uint8_t freq, uint8_t slope, uint16_t base)
{
    if (freq == 0)
        return 0;
    return (uint16_t)((uint16_t)(slope + 1u) << 12 | (uint16_t)((freq - 1u) * 50u + base));
}

/* dsp_set_hcut 0xFFF9EAE7: reg 0x46, HCUT from 700 Hz */
void dsp_set_hcut(void)
{
    const struct af_menu *mn;
    uint8_t freq = 0, slope = 0;

    (void)vfo_rec_ptr(0);
    mn = af_menu_of(vfo_mode(0));
    if (mn) {
        freq = g_opstate.preset_on == 0 ? mn->hcut_freq : g_ui.preset_active.hcut_freq;
        slope = g_opstate.preset_on == 0 ? mn->hcut_slope : g_ui.preset_active.hcut_slope;
    }
    dsp_write_if_changed(0x46u, SH_HCUT, cut_value(freq, slope, 700u));
}

/* dsp_set_lcut 0xFFF9ED0E: reg 0x47, LCUT from 100 Hz */
void dsp_set_lcut(void)
{
    const struct af_menu *mn;
    uint8_t freq = 0, slope = 0;

    (void)vfo_rec_ptr(0);
    mn = af_menu_of(vfo_mode(0));
    if (mn) {
        freq = g_opstate.preset_on == 0 ? mn->lcut_freq : g_ui.preset_active.lcut_freq;
        slope = g_opstate.preset_on == 0 ? mn->lcut_slope : g_ui.preset_active.lcut_slope;
    }
    dsp_write_if_changed(0x47u, SH_LCUT, cut_value(freq, slope, 100u));
}

/* the AF tone triples: band 0 BASS regs 0x48..0x4A, 1 MIDDLE 0x4B..0x4D, any other TREBLE 0x4E..0x50 (frequency,
 * gain, Q) [fact: dsp_set_tone_freq 0xFFF9EF34, _gain 0xFFF9F0B1, _q 0xFFF9F291] */
static inline unsigned tone_band(uint8_t band)
{
    return band == 0 ? 0u : band == 1 ? 1u : 2u;
}

/* dsp_set_tone_freq 0xFFF9EF34: 200 / 400 / 1200 Hz | 0x1000, 0 for a mode code above PSK */
void dsp_set_tone_freq(uint8_t band)
{
    static const uint8_t hundreds[3] = {2, 4, 12};
    unsigned b = tone_band(band);
    uint16_t v = vfo_mode(0) <= MODE_PSK ? (uint16_t)(hundreds[b] * 100u) : 0u;

    if (v != 0)
        v |= 0x1000u;
    dsp_write_if_changed((uint16_t)(0x48u + 3u * b), SH_TONE_FREQ + b, v);
}

/* dsp_set_tone_gain 0xFFF9F0B1: the mode group's BASS / MIDDLE / TREBLE GAIN, signed */
void dsp_set_tone_gain(uint8_t band)
{
    const struct af_menu *mn = af_menu_of(vfo_mode(0));
    unsigned b = tone_band(band);
    uint8_t gain = 0;

    if (mn)
        gain = b == 0 ? mn->bass_gain : b == 1 ? mn->middle_gain : mn->treble_gain;
    dsp_write_if_changed((uint16_t)(0x49u + 3u * b), SH_TONE_GAIN + b, s8_to_u16(gain));
}

/* dsp_set_tone_q 0xFFF9F291: Q 2 / 1 / 1, 0 for a mode code above PSK */
void dsp_set_tone_q(uint8_t band)
{
    unsigned b = tone_band(band);
    uint16_t v = vfo_mode(0) <= MODE_PSK ? (b == 0 ? 2u : 1u) : 0u;

    dsp_write_if_changed((uint16_t)(0x4Au + 3u * b), SH_TONE_Q + b, v);
}

/* AGC: the mode block's flags2 holds AGC on (bit 6) and the speed (bits 4..5); the speed picks the FAST / MID /
 * SLOW DELAY of the mode group's menu (the preset's while PRESET is on). Speed 0 reads as SLOW in SSB and AM, as
 * MID in RTTY and DATA, as FAST in CW and FM [fact: the compare chains of dsp_set_agc 0xFFF9F681]. */
enum agc_speed { AGC_FAST, AGC_MID, AGC_SLOW };

static const uint8_t agc_speed_slow0[4] = {AGC_SLOW, AGC_FAST, AGC_MID, AGC_SLOW};   /* SSB, AM */
static const uint8_t agc_speed_mid0[4] = {AGC_MID, AGC_FAST, AGC_MID, AGC_SLOW};     /* RTTY, DATA/PSK */
static const uint8_t agc_speed_fast0[4] = {AGC_FAST, AGC_FAST, AGC_MID, AGC_SLOW};   /* CW, FM */

/* dsp_set_agc 0xFFF9F681: reg 0x62 = AGC on (forced on while timer 0x2A runs), and, once that register is
 * current, reg 0x66 = the AGC delay: (DELAY + 1) x 20 ms; while scanning or channel-stepping 200 (memory), 40 (AM,
 * FM) or 4; 20 while timer 0x2A runs */
void dsp_set_agc(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    const struct mode_blk *b;
    const uint8_t *menu;                           /* the group's EX..01 item */
    const uint8_t *speeds;
    uint8_t flags, delay = 0;
    uint16_t v;

    if (m == MODE_PSK || m == MODE_DATA_L || m == MODE_DATA_U) {
        b = &r->blk[3];
        menu = (const uint8_t *)&g_opstate.ex010401_af_treble_gain;
        speeds = agc_speed_mid0;
    } else if (mode_cw(m)) {
        b = &r->blk[1];
        menu = (const uint8_t *)&g_opstate.ex020101_af_treble_gain;
        speeds = agc_speed_fast0;
    } else if (mode_am(m)) {
        b = &r->blk[4];
        menu = (const uint8_t *)&g_opstate.ex010201_af_treble_gain;
        speeds = agc_speed_slow0;
    } else if (m == MODE_RTTY_L || m == MODE_RTTY_U) {
        b = &r->blk[2];
        menu = (const uint8_t *)&g_opstate.ex010501_af_treble_gain;
        speeds = agc_speed_mid0;
    } else if (m == MODE_LSB || m == MODE_USB) {
        b = &r->blk[0];
        menu = (const uint8_t *)&g_opstate.ex010101_af_treble_gain;
        speeds = agc_speed_slow0;
    } else {                                       /* FM, DATA-FM and codes above PSK */
        b = &r->blk[5];
        menu = (const uint8_t *)&g_opstate.ex010301_af_treble_gain;
        speeds = agc_speed_fast0;
    }
    flags = b->flags2;
    if (flags & 0x40u) {
        const struct af_menu *mn = (const struct af_menu *)menu;
        uint8_t s = speeds[(flags & 0x30u) >> 4];

        if (s == AGC_SLOW)
            delay = g_opstate.preset_on == 0 ? mn->agc_slow_delay : g_ui.preset_active.agc_slow_delay;
        else if (s == AGC_MID)
            delay = g_opstate.preset_on == 0 ? mn->agc_mid_delay : g_ui.preset_active.agc_mid_delay;
        else
            delay = g_opstate.preset_on == 0 ? mn->agc_fast_delay : g_ui.preset_active.agc_fast_delay;
    }

    v = (flags & 0x40u) ? 1u : 0u;
    if (swtimer_expired(0x2A) == 0)
        v = 1;
    if (dsp_shadow[SH_AGC_ON] != v) {
        dsp_write_if_changed(0x62u, SH_AGC_ON, v);
        return;
    }

    if (swtimer_expired(0x2A) == 0)
        delay = 0;
    if (g_ui.scan_running == 1 || g_ui.ch_step_mode == 1) {
        if (vfo_is_memory(g_opstate.active_vfo) == 1)
            v = 200;
        else if ((uint8_t)(m - MODE_AM) < 4u || m == MODE_DATA_FM || m == MODE_DATA_FM_N)
            v = 40;
        else
            v = 4;
    } else {
        v = (uint16_t)(delay * 20u + 20u);
    }
    dsp_write_if_changed(0x66u, SH_AGC_DELAY, v);
}

/* dsp_set_freq_range_param 0xFFF9FB6E: reg 99 = one of the alignment items 028..032 "IF-AGC 7/14/21/28/50": the
 * first of the five limits at ROM 0xFFF88598 that the frequency does not exceed picks it; above all five, 028 */
extern const uint32_t dsp_freq_ranges[5];

void dsp_set_freq_range_param(void)
{
    uint32_t f;
    uint8_t range = 0, i, v;

    (void)vfo_mode(0);
    f = vfo_freq(0, 2);
    for (i = 0; i <= 4u; i++) {
        if (f <= dsp_freq_ranges[i]) {
            range = i;
            break;
        }
    }
    if (range == 3)
        v = g_cfg105.a031_rx_if_agc_28;
    else if (range == 1)
        v = g_cfg105.a029_rx_if_agc_14;
    else if (range == 2)
        v = g_cfg105.a030_rx_if_agc_21;
    else if (range == 0)
        v = g_cfg105.a028_rx_if_agc_7;
    else
        v = g_cfg105.a032_rx_if_agc_50;
    dsp_write_if_changed(99u, SH_FREQ_RANGE, v);
}

/* dsp_shadow_store 0xFFFA037A: after an acknowledged write (or a read reply), the value goes into the shadow slot
 * of its register; the status registers 1..4 then run their filters [fact: the compare chain 0xFFFA037A..0xFFFA0AD5,
 * one register per slot] */
static const struct { uint16_t reg; uint8_t slot; } dsp_shadow_map[] = {
    {0x0000, 0}, {0x0001, 1}, {0x0002, 2}, {0x0003, 3}, {0x0004, 4}, {0x4026, 84}, {0x0008, 6}, {0x0009, 7},
    {0x000A, 8}, {0x000C, 9}, {0x000D, 10}, {0x000E, 11}, {0x000F, 12}, {0x0010, 13}, {0x0011, 14}, {0x0012, 15},
    {0x0013, 16}, {0x0020, 17}, {0x0021, 18}, {0x0022, 19}, {0x0025, 20}, {0x0026, 23}, {0x0027, 26}, {0x0028, 21},
    {0x0029, 24}, {0x002A, 27}, {0x002B, 22}, {0x002C, 25}, {0x002D, 28}, {0x002E, 29}, {0x002F, 30}, {0x0030, 31},
    {0x0031, 32}, {0x0032, 33}, {0x0033, 34}, {0x0034, 35}, {0x0035, 36}, {0x0036, 37}, {0x0037, 38}, {0x0038, 39},
    {0x003A, 40}, {0x003B, 41}, {0x0040, 42}, {0x0041, 43}, {0x0042, 44}, {0x0043, 45}, {0x0044, 46}, {0x0045, 47},
    {0x0046, 48}, {0x0047, 49}, {0x0048, 50}, {0x0049, 53}, {0x004A, 56}, {0x004B, 51}, {0x004C, 54}, {0x004D, 57},
    {0x004E, 52}, {0x004F, 55}, {0x0050, 58}, {0x0051, 59}, {0x0052, 60}, {0x0053, 61}, {0x0054, 62}, {0x0055, 63},
    {0x0056, 64}, {0x0057, 65}, {0x0058, 66}, {0x005C, 67}, {0x005D, 68}, {0x0060, 69}, {0x0061, 70}, {0x0062, 71},
    {0x0063, 72}, {0x0064, 73}, {0x0065, 74}, {0x0066, 75}, {0x0067, 76}, {0x0068, 77}, {0x400B, 78}, {0x400D, 79},
    {0x4020, 80}, {0x4022, 81}, {0x4023, 82}, {0x4025, 83}, {0x0006, 5},
};

void dsp_shadow_store(void)
{
    unsigned i;

    for (i = 0; i < sizeof dsp_shadow_map / sizeof dsp_shadow_map[0]; i++) {
        if (dsp_shadow_map[i].reg != dsp_tx_reg)
            continue;
        dsp_shadow[dsp_shadow_map[i].slot] = dsp_tx_data;
        switch (dsp_tx_reg) {
        case 1:
            dsp_status1_filter();
            break;
        case 2:
            dsp_status2_filter();
            break;
        case 3:
            dsp_status3_filter();
            break;
        case 4:
            dsp_status4_filter();
            break;
        default:
            break;
        }
        return;
    }
}
