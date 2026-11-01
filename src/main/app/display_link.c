/* The MAIN <-> DISPLAY link on SCI1, recreated for T24 (docs/code/main/display-link.md): the SCI1 glue, the
 * ACK/NAK replies, the frame send path and the senders of the frames that are built in a staging buffer and go out
 * only when they changed.
 *
 * Every frame MAIN sends is built in displink_tx_frame (RAM 0x1456), ends with an 8-bit sum of the bytes before
 * it, and stays there until the DISPLAY ACKs it, so a NAK resends it unchanged [fact: displink_tx_start
 * 0xFFF9C5B2, displink_tx_resend 0xFFF96209]. */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"
#include "r_cg_sci.h"
#include "ft710_state.h"

#define DL_RX_MAX 0x204u   /* receive buffer size [fact: R_SCI1_Serial_Receive(0x9E86, 0x204)] */
#define ASCII_ACK 0x06u
#define ASCII_NAK 0x15u

/* --- SCI1 glue (0xFFFB1702..0xFFFB176A) --- */

/* displink_uart_start 0xFFFB1702 */
void displink_uart_start(void)
{
    displink_rx_flag = 0;
    R_SCI1_Start();
    R_SCI1_Serial_Receive(displink_rx_frame, DL_RX_MAX);
}

/* displink_rx_ready 0xFFFB171E */
uint8_t displink_rx_ready(void)
{
    return displink_rx_flag;
}

/* displink_rx_rearm 0xFFFB172D: frame handled; receive the next one */
void displink_rx_rearm(void)
{
    displink_rx_flag = 0;
    R_SCI1_Serial_Receive(displink_rx_frame, DL_RX_MAX);
}

/* displink_rx_done 0xFFFB1745: SCI1's receive-end callback */
void displink_rx_done(void)
{
    displink_rx_flag = 1;
}

/* displink_rx_buf 0xFFFB174F */
uint32_t displink_rx_buf(void)
{
    return (uint32_t)(uintptr_t)displink_rx_frame;
}

/* displink_uart_send 0xFFFB175B */
void displink_uart_send(uint8_t *buf, uint16_t len)
{
    R_SCI1_Serial_Send(buf, len);
}

/* sci1_tx_end 0xFFFB176B: SCI1.SSR.TEND, the last byte has left the shift register */
uint8_t sci1_tx_end(void)
{
    return (uint8_t)((SCI1_SSR >> 2) & 1u);
}

/* --- replies and the send path --- */

/* displink_rx_nak 0xFFF95469: a NAK frame from the DISPLAY needs nothing here */
void displink_rx_nak(void)
{
}

/* displink_send_ack 0xFFF95F26, displink_send_nak 0xFFF95F3F: one control byte from the stack. The SCI1 driver
 * keeps the pointer to it (gp_sci1_tx_address), so its place shows: the image has it in the last byte of a 4-byte
 * frame (mov.b #6, 3[r0] after sub #4, r0), and so does this code */
static inline void displink_send_ctrl(uint8_t code)
{
    uint8_t frame[4];

    frame[3] = code;
    displink_uart_send(&frame[3], 1);
    displink_tx_sent = 1;
}

void displink_send_ack(void)
{
    displink_send_ctrl(ASCII_ACK);
}

void displink_send_nak(void)
{
    displink_send_ctrl(ASCII_NAK);
}

/* displink_tx_resend 0xFFF96209: (re)send the frame in displink_tx_frame */
void displink_tx_resend(void)
{
    displink_uart_send(displink_tx_frame, displink_tx_len);
    displink_tx_sent = 1;
}

/* displink_put_sum 0xFFF9C5D8: the 8-bit sum of the first len - 1 bytes into the last one */
void displink_put_sum(uint8_t *frame, uint16_t len)
{
    uint8_t sum = 0;
    uint16_t i;

    len = (uint16_t)(len - 1u);
    for (i = 0; i < len; i++)
        sum = (uint8_t)(sum + frame[i]);
    frame[len] = sum;
}

/* displink_tx_start 0xFFF9C5B2: sum, mark the frame outstanding (no ACK yet), send */
void displink_tx_start(uint16_t len)
{
    displink_put_sum(displink_tx_frame, len);
    displink_tx_acked = 0;
    displink_tx_pending = 1;
    displink_tx_resend();
}

/* mem_zero 0xFFF9C655 */
void mem_zero(uint16_t n, uint8_t *p)
{
    while (n--)
        *p++ = 0;
}

/* displink_copy_if_changed 0xFFF9C667: 1 and copy all n bytes of src over dst when they differ anywhere, else 0 */
uint8_t displink_copy_if_changed(const uint8_t *src, uint8_t *dst, uint16_t n)
{
    uint16_t i;

    for (i = 0; i < n; i++) {
        if (dst[i] != src[i]) {
            for (i = 0; i < n; i++)
                dst[i] = src[i];
            return 1;
        }
    }
    return 0;
}

/* --- frame senders --- */

/* displink_tx_60_hello 0xFFF96225: the 0x60 hello reply, 0xB6 bytes */
void displink_tx_60_hello(void)
{
    displink_hello_sent = 1;
    displink_build_60();
    displink_tx_len = 0xB6;
    displink_tx_start(0xB6);
}

/* displink_tx_23 0xFFF98E39: frame 0x23 (0x37 bytes) on request; the request flag is UI +0x89 */
void displink_tx_23(void)
{
    g_ui_ptr[0x89] = 0;
    displink_build_23();
    displink_tx_len = 0x37;
    displink_tx_start(0x37);
}

/* displink_build_20 0xFFF9C454: the status frame 0x20 in the status staging buffer */
void displink_build_20(void)
{
    mem_zero(0x98, displink_stage_status);
    displink_stage_status[0] = 0x20;
    displink_build_status();
}

/* the senders of frames that go out only when their content changed: build into a staging buffer, copy over the
 * last frame sent if different, add the sum byte, send. len counts the sum byte */
static inline void displink_tx_if_changed(void (*build)(void), const uint8_t *stage, uint16_t len)
{
    build();
    if (displink_copy_if_changed(stage, displink_tx_frame, (uint16_t)(len - 1u)) != 1u)
        return;
    displink_tx_len = len;
    displink_tx_start(len);
}

/* displink_tx_20_status 0xFFF9C42A (0x99 bytes); the others use the common staging buffer 0x1741 */
void displink_tx_20_status(void) { displink_tx_if_changed(displink_build_20, displink_stage_status, 0x99); }
void displink_tx_70(void) { displink_tx_if_changed(displink_build_70, displink_stage, 0xE3); }   /* 0xFFF98925 */
void displink_tx_24(void) { displink_tx_if_changed(displink_build_24, displink_stage, 0x9F); }   /* 0xFFF9A17D */
void displink_tx_50(void) { displink_tx_if_changed(displink_build_50, displink_stage, 0xF5); }   /* 0xFFF9A2D1 */
void displink_tx_37(void) { displink_tx_if_changed(displink_build_37, displink_stage, 0x240); }  /* 0xFFF9AB2A */
void displink_tx_39(void) { displink_tx_if_changed(displink_build_39, displink_stage, 0xE9); }   /* 0xFFF9B69E */
void displink_tx_41(void) { displink_tx_if_changed(displink_build_41, displink_stage, 0x146); }  /* 0xFFF9BB23 */
void displink_tx_62(void) { displink_tx_if_changed(displink_build_62, displink_stage, 0x197); }  /* 0xFFF9C46D */

/* --- the link task (round 4) --- */

void freq_cache_update(void);
void FUN_fffc8b55(void);
void FUN_fffcf45c(void);
void FUN_fff9513c(void);
uint16_t displink_rx_len_of(uint8_t type);           /* the length of a received frame type, 0 = unknown */
uint8_t displink_check_sum(uint32_t frame, uint16_t len);
void displink_rx_dispatch(uint8_t *frame);
void displink_tx_poll(void);                         /* send the next queued frame, if any */
void displink_send_ack(void);
void displink_send_nak(void);
uint8_t FUN_fffc911e(void);
uint8_t FUN_fff9ccd3(void);
void FUN_fffc912d(uint8_t v);

#define TMR_DL_GAP     0x3B       /* 2 units after a frame has left SCI1 */
#define TMR_DL_ACK     0x3C       /* 30 units for the DISPLAY's ACK */
#define TMR_DL_24      0x2B       /* the delayed frame 0x24 request */

/* the next frame out: the queued data frame, or an ACK / NAK that is owed */
static void dl_send_next(void)
{
    displink_tx_poll();
    if (displink_tx_sent == 1)
        displink_ack_wait_start = 1;
}

static int dl_send_reply(void)
{
    if (displink_ack_req == 1) {
        displink_ack_req = 0;
        displink_send_ack();
        return 1;
    }
    if (displink_nak_req == 1) {
        displink_nak_req = 0;
        displink_send_nak();
        return 1;
    }
    return 0;
}

/* displink_task 0xFFF94D6F: main-loop task 14 (also the power-off loop). The frequency cache and three state
 * updates, then a received frame: copied out, NAK for an unknown type or a bad sum (ACK / NAK frames carry none),
 * else dispatched by type. The delayed 0x24 request; then the send side: wait for SCI1, a 2-unit gap after each
 * frame, ACK / NAK first, the next data frame and its 30-unit ACK window (display-link.md, the link state
 * diagram). With nothing pending, FUN_fffc911e / FUN_fff9ccd3 settle the frequencies. */
void displink_task(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;

    freq_cache_update();
    FUN_fffc8b55();
    FUN_fffcf45c();
    FUN_fff9513c();
    if (displink_rx_ready() == 1) {
        uint8_t *rx = (uint8_t *)(uintptr_t)displink_rx_buf();
        uint16_t len = displink_rx_len_of(rx[0]);
        unsigned i;
        int bad = 0;

        for (i = 0; i < len; i++)
            displink_rx_copy[i] = rx[i];
        displink_rx_rearm();
        if (len == 0) {
            displink_nak_req = 1;
            bad = 1;
        } else if (rx[0] != ASCII_ACK && rx[0] != ASCII_NAK &&
                   !displink_check_sum((uint32_t)(uintptr_t)displink_rx_copy, len)) {
            displink_nak_req = 1;
            bad = 1;
        }
        if (!bad)
            displink_rx_dispatch(displink_rx_copy);
    }
    if (ui->dl_req_24_later == 1 && swtimer_expired(TMR_DL_24) == 1) {
        ui->dl_req_24_later = 0;
        ui->dl_req_24 = 1;
    }
    if (displink_tx_sent == 1) {
        if (sci1_tx_end() == 0)
            return;
        displink_tx_sent = 0;
        displink_gap = 1;
        swtimer_start(TMR_DL_GAP, 2);
    }
    if (displink_gap == 1 && swtimer_expired(TMR_DL_GAP) == 1)
        displink_gap = 0;
    if (displink_ack_wait_start == 1) {
        displink_ack_wait_start = 0;
        displink_ack_wait = 1;
        swtimer_start(TMR_DL_ACK, 0x1E);
    }
    if (displink_gap == 1)
        return;
    if (displink_ack_wait == 0) {
        if (!dl_send_reply())
            dl_send_next();
    } else if (swtimer_expired(TMR_DL_ACK) == 1) {
        displink_ack_wait = 0;
        dl_send_next();
    } else {
        (void)dl_send_reply();
    }
    if (FUN_fffc911e() == 0) {
        if (FUN_fff9ccd3() == 0) {
            ui->freq_settled_a = 1;
            ui->freq_settled_b = 1;
        } else {
            ui->freq_settled_a = 0;
            ui->freq_settled_b = 0;
        }
        swtimer_start(0x4A, 100);
        FUN_fffc912d(1);
    }
}

/* dispreq_e7_task 0xFFFE2CD0: main-loop task 11: the DISPLAY's PlayList recorder / player status (E7, UI +0x488):
 * 1 recorded (the list again, one row up after a delete), 2 playback ended, 3 / 4 nothing, 5 an audio error: the
 * PlayList closes, a beep, and the dialog of the error (0x10..0x15, 0x18, 0x19, else 0x1A) */
void dispreq_e7_task(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr2;
    static const uint8_t err_dialog[8] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x18, 0x19};

    switch (ui->e7_status) {
    case 1:
        ui->e7_status = 0;
        if (ui->playlist_substate == 3 && ui->playlist_row != 0)
            ui->playlist_row--;
        ui->playlist_substate = 1;
        ui->playlist_req = 1;
        return;
    case 2:
        ui->e7_status = 0;
        if (ui->playlist_open == 1) {
            ui->playlist_playing = 0;
            if (ui->playlist_cmd != 0) {
                ui->playlist_cmd = 0;
                ui->playlist_req = 1;
                ui->playlist_substate = 1;
            }
        }
        return;
    case 3:
    case 4:
        ui->e7_status = 0;
        return;
    case 5:
        ui->e7_status = 0;
        ui->playlist_open = 0;
        ui->playlist_req = 0;
        ui->dvs_lm1_flag = 0;
        beep_request(3);
        ui->dialog_msg = ui->audio_error < 8u ? err_dialog[ui->audio_error] : 0x1A;
        ui->dialog_shown = 1;
        return;
    default:
        return;
    }
}

/* --- receive handlers (round 4) --- */

void enc2_step(int8_t steps);
void enc3_step(int8_t steps);
void FUN_fffc89ef(uint8_t steps);            /* encoder 4 while the keypad enters a number */
void FUN_fffc8a90(uint8_t steps);            /* encoder 5 while the keypad enters a number */
uint8_t FUN_fffc523a(uint8_t side, uint8_t restore, uint8_t v);   /* with (0, 0) stores v at 0x1B4E3 */
uint8_t key_dest_allowed(uint16_t key, uint8_t kind);
void enc_main_dial(uint8_t steps);
void ui_numentry_step(uint8_t steps);

/* encoder ids of frame 0xE1 [fact: the compare chain of displink_rx_E1_encoder 0xFFF9588B] */
enum { ENC_MAIN = 1, ENC_2 = 2, ENC_3 = 3, ENC_RF = 4, ENC_AF = 5, ENC_6 = 6 };

/* displink_rx_E1_encoder 0xFFF9588B: frame 0xE1 {type, encoder id, steps}: the main dial (1, and 6), the two
 * multi-function encoders (2, 3; 6 counts as 3, negated unless the DSP knob edits, while the FUNC panel is open),
 * RF/SQL (4) and AF (5), or the keypad's number entry; always answers ACK */
void displink_rx_E1_encoder(uint8_t *frame)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;

    if (ui->enc_blocked == 1)
        goto ack;
    ui->enc_ev_id = frame[1];
    if (ui->enc_ev_id == ENC_6 && ui->func_panel_open == 1) {
        ui->enc_ev_id = ENC_3;
        if (ui->dsp_knob_edit == 0)
            frame[2] = (uint8_t)(~frame[2] + 1u);
    }
    switch (ui->enc_ev_id) {
    case ENC_2:
        if (key_event_filter(0xFF1, 0) != 0)
            enc2_step((int8_t)frame[2]);
        break;
    case ENC_3:
        if (key_event_filter(0xFF2, 0) != 0)
            enc3_step((int8_t)frame[2]);
        break;
    case ENC_RF:
        if (ui->playlist_open == 1 &&
            (ui->playlist_cmd == 1 || ui->playlist_cmd == 2 || ui->playlist_cmd == 3))
            break;
        if (ui->numentry_mode != 0) {
            FUN_fffc89ef(frame[2]);
            break;
        }
        /* R3 = the step byte, loaded before the branch [fact: 0xFFF95A02] */
        (void)FUN_fffc523a(0, 0, frame[2]);
        if (key_dest_allowed(0, 1) == 1)
            ui->rf_gain = frame[2];
        break;
    case ENC_AF:
        if (ui->numentry_mode != 0)
            FUN_fffc8a90(frame[2]);
        else
            ui->af_gain = frame[2];
        break;
    case ENC_MAIN:
    case ENC_6:
        if (key_event_filter(0xFF0, 0) != 0) {
            ui->enc_ev_steps = frame[2];
            if (ui->numentry_mode == 0)
                enc_main_dial(ui->enc_ev_steps);
            else
                ui_numentry_step(ui->enc_ev_steps);
        }
        break;
    default:
        break;
    }
ack:
    displink_ack_req = 1;
}

/* --- the status block (round 4; display-link.md "0x97-byte radio status block") --- */

uint8_t FUN_fffc4f8f(void);                          /* 1 while SS00 = 5 is in force */
uint8_t dlstat_scope_mode(void);
uint8_t dlstat_vfo_side_flags(void);
uint8_t dlstat_screen_flags(void);
uint8_t dlstat_split_expand(void);
uint8_t dlstat_disp_sensitivity(void);
uint8_t dlstat_swr_tx_flags(void);
uint8_t dlstat_led_mask(void);
uint8_t dlstat_affft_overlay(void);
uint8_t dlstat_tx_bpf(const struct vfo_rec *r);
uint8_t dlstat_att_ipo_dnf(const struct vfo_rec *r);
uint8_t dlstat_dsp_flags_agc(const struct vfo_rec *r);
uint8_t dlstat_tx_vfo_flags(void);
uint8_t dlstat_tone_tuner(void);
uint8_t dlstat_peak(void);
uint8_t dlstat_span_center(uint8_t side);
void dlstat_default_width(uint8_t *at, const struct vfo_rec *r);  /* 2 bytes */
void dlstat_zero_in(uint8_t *at);                                 /* 4 bytes */
void dlstat_contour(uint8_t *at, const struct vfo_rec *r);        /* 2 bytes each */
void dlstat_notch(uint8_t *at, const struct vfo_rec *r);
void dlstat_width(uint8_t *at, const struct vfo_rec *r);
void dlstat_shift(uint8_t *at, const struct vfo_rec *r);
uint8_t dlstat_dsp_knob_flags(const struct vfo_rec *r);
uint8_t dlstat_voice_mem(void);
void dlstat_scope_settings(uint8_t *at);                          /* 6 bytes */
uint8_t dlstat_func_knob(void);
uint8_t dlstat_vfo_state_code(uint8_t side, uint8_t *chan);      /* also stores the side's channel */
uint8_t dlstat_vfo_flags48(uint8_t side);
void FUN_fff982aa(uint8_t side, uint8_t *freq5, uint8_t *prev);  /* the side's 5 frequency bytes */
void ui_numentry_to_bcd(void);
uint8_t dlstat_meter(void);
uint8_t dlstat_tuning_flags(const struct vfo_rec *r);
void disp_put_op_freq(uint8_t *at);                               /* 4 bytes each */
void disp_put_tx_freq(uint8_t *at);
void disp_put_dial_freq(uint8_t *at);
void disp_put_scope_start(uint8_t *at);

#define DLS_VFO_A    45u          /* the VFO-A section: mode, state, channel, flags, 5 frequency bytes, tag, clar */
#define DLS_VFO_LEN  25u          /* the VFO-B section follows; the two swap places when VFO-B is active */
#define DLS_TAIL     95u

/* one VFO section of the status block at s */
static void dls_vfo_section(uint8_t *s, uint8_t side, uint8_t *chan)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    const struct vfo_rec *r = side == 0 ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    unsigned i;

    s[0] = r->mode & 0x0Fu;
    s[1] = dlstat_vfo_state_code(side, chan);
    s[2] = *chan;
    s[3] = dlstat_vfo_flags48(side);
    if (side == 0 && ui->numentry_mode != 0) {      /* VFO-A while the keypad enters a frequency */
        ui_numentry_to_bcd();
        *chan = 5;
        for (i = 0; i < 5; i++)
            s[4 + i] = ui->numentry_bcd[i];
    } else {
        for (i = 0; i < 5; i++)
            dlstat_freq5[i] = 0;
        FUN_fff982aa(side, dlstat_freq5, &s[3]);
        for (i = 0; i < 5; i++)
            s[4 + i] = dlstat_freq5[i];
    }
    for (i = 0; i < 12; i++)
        s[9 + i] = (uint8_t)r->tag[i];
    s[21] = side == 0 ? ui->clar_flags_a : ui->clar_flags_b;
    s[22] = r->clar_offset_be[0];
    s[23] = r->clar_offset_be[1];
}

/* displink_build_status 0xFFF96455: the 0x97-byte radio status block at displink_stage_status + 1 (frames 0x20 and
 * 0x60); every byte is at a fixed offset, so the length is always 152 [fact: the offsets of 0xFFF96455..; the
 * meaning of each byte is the dlstat_* helper's, display-link.md] */
uint16_t displink_build_status(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_stage_status;
    const struct vfo_rec *r;
    uint8_t chan, side_b;
    uint16_t v;
    unsigned i;

    if (g_opstate.active_vfo == VFO_A) {
        dlstat_rec = &g_opstate.vfo_a;
        ui->status_side = VFO_A;
    } else {
        dlstat_rec = &g_opstate.vfo_b;
        ui->status_side = VFO_B;
    }
    r = dlstat_rec;
    side_b = g_opstate.active_vfo != VFO_A;
    f[1] = g_opstate.scope_flag_37;
    f[2] = dlstat_scope_mode();
    f[3] = dlstat_vfo_side_flags();
    f[4] = dlstat_screen_flags();
    f[5] = dlstat_split_expand();
    f[6] = dlstat_disp_sensitivity();
    f[7] = dlstat_swr_tx_flags();
    f[8] = dlstat_led_mask();
    f[9] = dlstat_affft_overlay();
    f[10] = dlstat_tx_bpf(r);
    f[11] = g_opstate.meter_sel & 7u;
    f[12] = dlstat_att_ipo_dnf(r);
    f[13] = dlstat_dsp_flags_agc(r);
    f[14] = dlstat_tx_vfo_flags();
    f[15] = dlstat_tone_tuner();
    f[16] = dlstat_peak();
    f[17] = dlstat_span_center(side_b);
    if (FUN_fffc4f8f() == 0)
        f[18] = (uint8_t)(g_opstate.ss00_value << 4 | (g_opstate.ss03_value & 0x0Fu));
    else
        f[18] = (uint8_t)((g_opstate.ss03_value & 0x5Fu) | 0x50u);
    dlstat_default_width(&f[19], r);
    chan = r->mode & 0x0Fu;
    if (chan == MODE_CW_U || chan == MODE_CW_L)
        dlstat_zero_in(&f[21]);
    dlstat_contour(&f[25], r);
    if (g_opstate.ex030205_contour_level < 0)
        f[25] |= 0x80u;
    dlstat_notch(&f[27], r);
    dlstat_width(&f[29], r);
    dlstat_shift(&f[31], r);
    f[33] = g_opstate.apf_freq;
    f[34] = (uint8_t)(g_opstate.cw_pitch + 30u);
    f[35] = dlstat_dsp_knob_flags(r);
    f[36] = dlstat_voice_mem();
    dlstat_scope_settings(&f[37]);
    f[43] = 0xFF;
    f[44] = ui->txw_on == 1 ? '-' : dlstat_func_knob();

    /* the two VFO sections */
    dlstat_pos_a = DLS_VFO_A;
    dlstat_pos_state_a = DLS_VFO_A + 1u;
    dls_vfo_section(&f[DLS_VFO_A], 0, &chan);
    dlstat_pos_b = DLS_VFO_A + DLS_VFO_LEN;
    dlstat_pos_state_b = DLS_VFO_A + DLS_VFO_LEN + 1u;
    dls_vfo_section(&f[DLS_VFO_A + DLS_VFO_LEN], 1, &chan);
    if (g_opstate.active_vfo == VFO_B) {
        dlstat_swap_a = &f[dlstat_pos_a];
        dlstat_swap_b = &f[dlstat_pos_b];
        for (v = (uint16_t)(dlstat_pos_b - dlstat_pos_a); v != 0; v--) {
            uint8_t t = *dlstat_swap_a;

            *dlstat_swap_a++ = *dlstat_swap_b;
            *dlstat_swap_b++ = t;
        }
    }
    if (g_opstate.split_on == 1) {
        f[dlstat_pos_state_a] = 9;
        f[dlstat_pos_state_b] = 10;
    }

    f[DLS_TAIL] = dlstat_meter();
    f[DLS_TAIL + 1] = dlstat_tuning_flags(r);
    f[DLS_TAIL + 8] = 0;
    f[DLS_TAIL + 9] = (uint8_t)((g_opstate.ex010516_shift_frequency & 3u) | g_opstate.ex010515_mark_frequency << 7);
    f[DLS_TAIL + 10] = (uint8_t)((g_opstate.ex010419_psk_tone & 3u) << 4);
    f[DLS_TAIL + 11] = g_opstate.key_speed;
    for (i = DLS_TAIL + 12; i <= DLS_TAIL + 17; i++)
        f[i] = 0;
    f[DLS_TAIL + 18] = (uint8_t)((g_opstate.osc_time & 7u) | (g_opstate.ss07_affft_att & 3u) << 5 | 0x18u);
    v = (uint16_t)((g_opstate.ex010420_data_shift_ssb_be[0] << 8 | g_opstate.ex010420_data_shift_ssb_be[1]) * 10u);
    f[DLS_TAIL + 20] = (uint8_t)(v >> 8);
    f[DLS_TAIL + 21] = (uint8_t)v;
    disp_put_op_freq(&f[117]);
    disp_put_tx_freq(&f[121]);
    disp_put_dial_freq(&f[125]);
    disp_put_scope_start(&f[129]);
    return 129 + 0x17;
}

/* --- frame builders (round 4) --- */

uint8_t FUN_fffc2b2e(uint8_t first, uint8_t row);    /* the channel shown in a row of the memory list */
uint8_t memch_special_limit(void);
uint8_t memch_group_of(uint8_t ch);
void memch_label_fmt(uint8_t *at, uint8_t ch);       /* 5 characters: the channel's label */
void FUN_fff9c2f9(uint8_t *at, uint8_t ch);          /* 10 characters: the channel's frequency */
void FUN_fff9c1a1(uint8_t *lo, uint8_t *hi);         /* the channel range of the list */
uint8_t memch_valid(uint8_t ch, uint8_t **rec);
uint8_t dest_has_5mhz_channels(void);
uint8_t memch_dest_blocked(uint8_t ch);

static void dl41_fill(uint8_t c, unsigned n)
{
    while (n--)
        displink_stage[dl41_pos++] = c;
}

/* displink_build_41 0xFFF9BB50: frame 0x41, the memory-channel list: the selected row's state and the group /
 * row, the header, "GROUP n" (or ten spaces without memory groups), then four rows from the list's first channel:
 * {flags, label, frequency, mode name, tag} or dashes for an empty channel; the next channel wraps within the
 * list's range and skips the 60 m channels the destination does not have. dl41_pos is the image's write offset. */
void displink_build_41(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_stage;
    uint8_t sel, lim, g, ch, k, m, lo, hi;
    unsigned i;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    f[0] = 0x41;
    displink_copy_status();
    sel = FUN_fffc2b2e(ui->memlist_first, ui->memlist_row);
    lim = memch_special_limit();
    if (lim != 0 && sel >= lim)
        ui->memlist_sel_valid = 0;
    else
        ui->memlist_sel_valid = memch_valid(sel, &dl41_used_ptr) ? 0 : 1;
    dl41_pos = 0x98;
    f[0x98] = (uint8_t)(ui->memlist_sel_valid << 7 | ui->memlist_flag << 6);
    f[0x99] = (uint8_t)(ui->memlist_group << 4 | ui->memlist_row);
    dl41_pos = 0x9C;
    for (i = 0; i < 15; i++)
        f[dl41_pos + i] = dl41_header[i];
    dl41_pos += 15;
    if (g_opstate.ex030114_mem_group == 1) {
        g = memch_group_of(sel);
        f[dl41_pos + 0] = 'G';
        f[dl41_pos + 1] = 'R';
        f[dl41_pos + 2] = 'O';
        f[dl41_pos + 3] = 'U';
        f[dl41_pos + 4] = 'P';
        f[dl41_pos + 5] = ' ';
        dl41_pos += 6;
        if (g < 6u) {
            dl41_fill(' ', 2);
            f[dl41_pos++] = (uint8_t)(g + '0');
            f[dl41_pos++] = ' ';
        } else {
            for (i = 0; i < 4; i++)
                f[dl41_pos + i] = dl41_group_names[g - 6u][i];
            dl41_pos += 4;
        }
    } else {
        for (i = 0; i < 10; i++)
            f[dl41_pos + i] = ' ';
        dl41_pos += 10;
    }
    ch = ui->memlist_first;
    for (k = 0; k < 4; k++) {
        dl41_rec = &memch[ch];
        if (memch_valid(ch, &dl41_used_ptr)) {
            f[dl41_pos++] = (uint8_t)(dl41_rec->flags5 >> 7 | ((dl41_rec->flags1 >> 6) & 2u));
            memch_label_fmt(&f[dl41_pos], ch);
            dl41_pos += 5;
            FUN_fff9c2f9(&f[dl41_pos], ch);
            dl41_pos += 10;
            m = dl41_rec->mode & 0x0Fu;
            if (m > 13u)
                m = 14;
            for (i = 0; i < 8; i++)
                f[dl41_pos + i] = dl41_mode_names[m][i];
            dl41_pos += 8;
            for (i = 0; i < 12; i++)
                f[dl41_pos + i] = (uint8_t)dl41_rec->tag[i];
        } else {
            f[dl41_pos++] = 0;
            memch_label_fmt(&f[dl41_pos], ch);
            dl41_pos += 5;
            for (i = 0; i < 10; i++)
                f[dl41_pos + i] = (i == 2 || i == 6) ? '.' : '-';
            dl41_pos += 10;
            for (i = 0; i < 8; i++)
                f[dl41_pos + i] = '-';
            dl41_pos += 8;
            for (i = 0; i < 12; i++)
                f[dl41_pos + i] = '-';
        }
        dl41_pos += 12;
        FUN_fff9c1a1(&lo, &hi);
        if (hi != lo) {
            hi++;
            do {
                ch++;
                if (ch >= hi)
                    ch = lo;
            } while (ch > 0x74u && ch < 0x84u && (dest_has_5mhz_channels() != 1 || memch_dest_blocked(ch) != 0));
        }
    }
}

uint32_t ver_main(void);                  /* the address of a 6-byte version string "Vxx-yy" */
uint32_t ver_display(void);
uint32_t ver_dsp(void);
uint32_t ver_sdr(void);

/* a version string "Vxx-yy" as two packed bytes 0xXX 0xYY, through dl60_ver_tmp as the image does */
static void dl60_put_version(uint8_t *at, uint32_t ver)
{
    const uint8_t *v = (const uint8_t *)(uintptr_t)ver;
    unsigned i;
    uint8_t hi;

    for (i = 0; i < 6; i++)
        dl60_ver_tmp[i] = v[i];
    hi = (uint8_t)hex2nib(dl60_ver_tmp[1]);
    at[0] = (uint8_t)(hi << 4 | (uint8_t)hex2nib(dl60_ver_tmp[2]));
    hi = (uint8_t)hex2nib(dl60_ver_tmp[4]);
    at[1] = (uint8_t)(hi << 4 | (uint8_t)hex2nib(dl60_ver_tmp[5]));
}

/* displink_build_60 0xFFF96241: frame 0x60, the hello: the MAIN, DISPLAY, DSP and SDR versions, the boot error
 * (0xDB when none and the debug mode A008 is on; cleared after), the status block, MY CALL TIME, MY CALL and AUTO
 * POWER ON; built straight into displink_tx_frame */
void displink_build_60(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_tx_frame;
    unsigned i;

    mem_zero(0xB5, displink_tx_frame);
    f[0] = 0x60;
    dl60_put_version(&f[1], ver_main());
    dl60_put_version(&f[3], ver_display());
    dl60_put_version(&f[5], ver_dsp());
    dl60_put_version(&f[0x0B], ver_sdr());
    if (ui->boot_error == 0 && g_cfg105.a008_gn_dbg_mode_enable != 0)
        ui->boot_error = 0xDB;
    f[0x0D] = (uint8_t)(ui->boot_error >> 8);
    f[0x0E] = (uint8_t)ui->boot_error;
    ui->boot_error = 0;
    (void)displink_build_status();
    for (i = 0; i < 0x97u; i++)
        f[0x0F + i] = displink_stage_status[1 + i];
    f[0xA6] = g_opstate.ex040102_my_call_time;
    for (i = 0; i < 12; i++)
        f[0xA7 + i] = (uint8_t)g_opstate.ex040101_my_call[i];
    f[0xB3] = g_opstate.auto_power_on;
}

/* the FUNC-panel slots of frame 0x37: each writes {flag, function id, 8 characters} at its offset */
void dl37_slot_scope_level(uint16_t off);
void dl37_slot_peak(uint16_t off);
void dl37_slot_marker(uint16_t off);
void dl37_slot_color(uint16_t off);
void dl37_slot_contrast(uint16_t off);
void dl37_slot_dimmer(uint16_t off);
void dl37_slot_mgroup(uint16_t off);
void dl37_slot_mic_gain(uint16_t off);
void dl37_slot_mic_eq(uint16_t off);
void dl37_slot_proc_level(uint16_t off);
void dl37_slot_amc_level(uint16_t off);
void dl37_slot_vox_gain(uint16_t off);
void dl37_slot_vox_delay(uint16_t off);
void dl37_slot_anti_vox(uint16_t off);
void dl37_slot_rf_power(uint16_t off);
void dl37_slot_moni_level(uint16_t off);
void dl37_slot_keyer(uint16_t off);
void dl37_slot_bk_in(uint16_t off);
void dl37_slot_cw_speed(uint16_t off);
void dl37_slot_cw_pitch(uint16_t off);
void dl37_slot_bk_delay(uint16_t off);
void dl37_slot_message(uint16_t off);
void dl37_slot_record(uint16_t off);
void dl37_slot_play(uint16_t off);
void dl37_slot_txw(uint16_t off);
void dl37_slot_empty(uint16_t off);
void dl37_slot_aess(uint16_t off);
void dl37_slot_aess_cf(uint16_t off);
void dl37_slot_radio_setting(uint16_t off);
void dl37_slot_cw_setting(uint16_t off);
void dl37_slot_operation_setting(uint16_t off);
void dl37_slot_display_setting(uint16_t off);
void dl37_slot_extension_setting(uint16_t off);

/* the 42 slots of frame 0x37 in frame order, 10 bytes apart from byte 0x9B [fact: displink_build_37
 * 0xFFF9ABD8..0xFFF9ACF0]; slot 25 and the last nine are empty */
static void (*const dl37_slots[])(uint16_t) = {
    dl37_slot_scope_level, dl37_slot_peak, dl37_slot_marker, dl37_slot_color, dl37_slot_contrast,
    dl37_slot_dimmer, dl37_slot_mgroup, dl37_slot_mic_gain, dl37_slot_mic_eq, dl37_slot_proc_level,
    dl37_slot_amc_level, dl37_slot_vox_gain, dl37_slot_vox_delay, dl37_slot_anti_vox, dl37_slot_rf_power,
    dl37_slot_moni_level, dl37_slot_keyer, dl37_slot_bk_in, dl37_slot_cw_speed, dl37_slot_cw_pitch,
    dl37_slot_bk_delay, dl37_slot_message, dl37_slot_record, dl37_slot_play, dl37_slot_txw,
    dl37_slot_empty, dl37_slot_aess, dl37_slot_aess_cf, dl37_slot_radio_setting, dl37_slot_cw_setting,
    dl37_slot_operation_setting, dl37_slot_display_setting, dl37_slot_extension_setting,
    dl37_slot_empty, dl37_slot_empty, dl37_slot_empty, dl37_slot_empty, dl37_slot_empty,
    dl37_slot_empty, dl37_slot_empty, dl37_slot_empty, dl37_slot_empty,
};

#define DL37_FLAGS     0x98u      /* bit 7 always 1, bit 6 FUNC assigned, bit 5 always 0 */
#define DL37_FUNC_KNOB 0x99u
#define DL37_SLOT0     0x9Bu
#define DL37_SLOT_LEN  10u

uint8_t mode_block_byte1(const struct vfo_rec *r);  /* flags2 of the record's block for its mode */
uint8_t scope_span_index(uint8_t side);


/* displink_build_30 0xFFF98FB1: frame 0x30, the setting pop-up: byte 0x98 the pop-up code (0xFF none), then the
 * value the pop-up shows (meter, ATT, IPO/AMP, NB-like block bit 7, AGC, mode, span, AF-FFT, oscilloscope, SS03,
 * band, SS00), with the selection or the cursor where the pop-up has one */
void displink_build_30(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    const struct vfo_rec *r;
    uint8_t *f = displink_stage;
    uint8_t v;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    f[0] = 0x30;
    displink_copy_status();
    f[0x98] = ui->popup_code;
    if (ui->popup_code == 0xFF)
        return;
    r = g_opstate.active_vfo == VFO_A ? &g_opstate.vfo_a : &g_opstate.vfo_b;
    switch (ui->popup_code) {
    case 0:                                 /* meter */
        f[0x99] = g_opstate.meter_sel;
        return;
    case 1:                                 /* ATT */
        f[0x99] = r->flags3 & 3u;
        f[0x9A] = ui->popup_sel;
        return;
    case 2:                                 /* IPO / AMP1 / AMP2: preamp 0 -> 0, else preamp - 1 */
        v = r->flags5 & 3u;
        f[0x99] = v == 0 ? 0 : (uint8_t)(v - 1u);
        f[0x9A] = ui->popup_sel;
        return;
    case 3:                                 /* the block's flags2 bit 7 (BC / DNF) */
        f[0x99] = (uint8_t)(mode_block_byte1(r) >> 7);
        f[0x9A] = ui->popup_sel;
        return;
    case 4:                                 /* AGC: 0 off, else speed + 1 */
        v = mode_block_byte1(r);
        f[0x99] = (v & 0x40u) == 0 ? 0 : (uint8_t)(((v >> 4) & 3u) + 1u);
        f[0x9A] = ui->popup_sel;
        return;
    case 5:                                 /* mode */
        f[0x99] = r->mode & 0x0Fu;
        f[0x9A] = 0;
        f[0x9B] = ui->popup_cursor;
        return;
    case 6:                                 /* span of the active side */
        f[0x99] = scope_span_index(g_opstate.active_vfo != VFO_A);
        return;
    case 7:
    case 8:
        f[0x99] = 0;
        return;
    case 9:
        f[0x99] = g_opstate.ss07_affft_att;
        return;
    case 10:                                /* oscilloscope: TX level, RX level, time */
        f[0x99] = (uint8_t)(g_opstate.osc_level_tx << 6 | g_opstate.osc_level_rx << 4 | g_opstate.osc_time);
        return;
    case 11:
        f[0x99] = g_opstate.ss03_value;
        f[0x9A] = 0;
        f[0x9B] = ui->popup_cursor;
        return;
    case 12:                                /* band */
        f[0x99] = ui->popup_band;
        f[0x9A] = 0;
        f[0x9B] = ui->popup_cursor;
        return;
    case 13:
        f[0x99] = FUN_fffc4f8f() == 0 ? g_opstate.ss00_value : 5u;
        return;
    default:
        return;
    }
}

extern const uint8_t dl39_type_rows[][25];          /* 0xFFF802C0: frame 0x39 bytes 0x98..0xB0 per type */
uint8_t FUN_fffe5783(void);
void displink_39_rtty_labels(void);                  /* fills g_ui.msg_text for type 2 */
void displink_39_keyer_texts(void);                  /* fills g_ui.msg_text for type 1 */

/* displink_build_39 0xFFF9B6C8: frame 0x39, the message-memory panel: the type's 25 ROM bytes, the type with the
 * state bits (0x08 msg_state_1d0, 0x04 playing, 0x10 / 0x20 DVS state 1 / 2), the active channel as a bit, the slot
 * while something records or plays, the CW MEMORY n bits, the play volume and level, the timer (big-endian) and,
 * for a type other than 0, the first 8 characters of the five texts */
void displink_build_39(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_stage;
    uint8_t v, k;
    unsigned i;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    f[0] = 0x39;
    displink_copy_status();
    v = ui->msgmem_type;
    for (i = 0; i < 25u; i++)
        f[0x98 + i] = dl39_type_rows[v][i];
    if (ui->msg_state_1d0 == 1)
        v |= 0x08u;
    if (ui->msg_playing == 1)
        v |= 0x04u;
    if (ui->dvs_state == 1)
        v |= 0x10u;
    else if (ui->dvs_state == 2)
        v |= 0x20u;
    f[0xB1] = v;
    f[0xB2] = FUN_fffe5783();
    f[0xB3] = (ui->msg_active == 1 && ui->msg_channel < 8u) ? (uint8_t)(1u << ui->msg_channel) : 0;
    v = 0;
    if (ui->dvs_busy == 0 &&
        (ui->dvs_state == 1 || ui->dvs_state == 2 || ui->msg_rec_active == 1 || ui->ky_send_0 == 1 ||
         ui->ky_send_1 == 1 || ui->msg_state_1d0 == 1 || ui->msg_playing == 1))
        v = ui->msg_slot;
    f[0xB4] = v;
    f[0xB5] = 0;
    v = 0;
    for (k = 0; k < 5; k++)                 /* CW MEMORY 1..5 = MESSAGE */
        if ((&g_opstate.ex020206_cw_memory_1)[k] == 1)
            v |= (uint8_t)(1u << k);
    f[0xB6] = v;
    f[0xB7] = g_opstate.play_volume;
    f[0xB8] = g_opstate.level_9dc2;
    f[0xB9] = 0;
    f[0xBA] = (uint8_t)(ui->msg_timer >> 8);
    f[0xBB] = (uint8_t)ui->msg_timer;
    for (i = 0xBC; i < 0xC0u; i++)
        f[i] = 0;
    if (ui->msgmem_type == 0)
        return;
    if (ui->msgmem_type == 2)
        displink_39_rtty_labels();
    else if (ui->msgmem_type == 1)
        displink_39_keyer_texts();
    for (k = 0; k < 5; k++)
        for (i = 0; i < 8u; i++)
            f[0xC0 + 8u * k + i] = ui->msg_text[k][i];
}

extern const uint8_t dialog_texts[];                 /* 0xFFF80000: 22-byte dialog lines */
void displink_70_msg(const uint8_t *text);           /* a message dialog of one line */
void displink_70_msg2(const uint8_t *text);          /* of two lines (text, text + 22) */
void displink_70_query(const uint8_t *text);         /* a yes/no question */

enum dl70_kind { DL70_MSG, DL70_MSG2, DL70_QUERY, DL70_BUTTONS2, DL70_BUTTONS0 };

/* the 27 dialogs of g_ui.dialog_msg: kind and the offset of the text in dialog_texts [fact: the switch of
 * displink_build_70 0xFFF98990 over the table 0xFFF8EFA4] */
static const struct { uint8_t kind; uint16_t text; } dl70_dialogs[27] = {
    {DL70_MSG, 0x000}, {DL70_BUTTONS2, 0x016}, {DL70_MSG2, 0x02C}, {DL70_QUERY, 0x058}, {DL70_QUERY, 0x06E},
    {DL70_MSG2, 0x084}, {DL70_QUERY, 0x0B0}, {DL70_BUTTONS0, 0x0C6}, {DL70_QUERY, 0x0DC}, {DL70_BUTTONS0, 0x0F2},
    {DL70_QUERY, 0x108}, {DL70_QUERY, 0x11E}, {DL70_QUERY, 0x134}, {DL70_QUERY, 0x14A}, {DL70_MSG, 0x160},
    {DL70_QUERY, 0x176}, {DL70_QUERY, 0x18C}, {DL70_QUERY, 0x1A2}, {DL70_QUERY, 0x1B8}, {DL70_QUERY, 0x1CE},
    {DL70_QUERY, 0x1E4}, {DL70_QUERY, 0x1FA}, {DL70_QUERY, 0x210}, {DL70_MSG, 0x252}, {DL70_QUERY, 0x176},
    {DL70_QUERY, 0x226}, {DL70_QUERY, 0x23C},
};

/* displink_build_70 0xFFF9894F: frame 0x70, the dialog: by g_ui.dialog_msg 0..26 a message, a two-line message, a
 * question, or a dialog with the selected button (byte 0x9A) whose bytes are built here */
void displink_build_70(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_stage;
    const uint8_t *t;
    unsigned i;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    f[0] = 0x70;
    displink_copy_status();
    if (ui->dialog_msg > 26u)
        return;
    t = &dialog_texts[dl70_dialogs[ui->dialog_msg].text];
    switch (dl70_dialogs[ui->dialog_msg].kind) {
    case DL70_MSG:
        displink_70_msg(t);
        return;
    case DL70_MSG2:
        displink_70_msg2(t);
        return;
    case DL70_QUERY:
        displink_70_query(t);
        return;
    default:                                /* style 3, buttons 2 or 0, the selected one, fixed bytes, one line */
        f[0x98] = 3;
        f[0x99] = dl70_dialogs[ui->dialog_msg].kind == DL70_BUTTONS2 ? 2 : 0;
        f[0x9A] = ui->dialog_button;
        f[0x9B] = 0;
        f[0x9C] = 0;
        f[0x9D] = 0xE6;
        f[0x9E] = 0;
        f[0x9F] = 0xB7;
        for (i = 0; i < 0x16u; i++)
            f[0xA0 + i] = t[i];
        return;
    }
}

/* the value texts of the setting pop-ups (frame 0x31), each written at its offset */
void popup_fmt_free_text(uint16_t off);
void popup_fmt_peak(uint16_t off);
void popup_fmt_contrast(uint16_t off);
void popup_fmt_dimmer(uint16_t off);
void popup_fmt_mgroup(uint16_t off);
void popup_fmt_mic_gain(uint16_t off);
void popup_fmt_mic_eq(uint16_t off);
void popup_fmt_proc_level(uint16_t off);
void popup_fmt_amc_level(uint16_t off);
void popup_fmt_vox_gain(uint16_t off);
void popup_fmt_vox_delay(uint16_t off);
void popup_fmt_anti_vox(uint16_t off);
void popup_fmt_rf_power(uint16_t off);
void popup_fmt_moni_level(uint16_t off);
void popup_fmt_bk_in(uint16_t off);
void popup_fmt_cw_speed(uint16_t off);
void popup_fmt_cw_pitch(uint16_t off);
void popup_fmt_bk_delay(uint16_t off);
void popup_fmt_aess_level(uint16_t off);
void popup_fmt_nb_level(uint16_t off);
void popup_fmt_dnr_level(uint16_t off);
void popup_fmt_dec_level(uint16_t off);
void popup_fmt_qmb(uint16_t off);
void popup_fmt_mem_scan(uint16_t off);
void popup_fmt_mem_type(uint16_t off);
void popup_fmt_keyer(uint16_t off);
void popup_fmt_mem_mode(uint16_t off);
void popup_fmt_aess_cf(uint16_t off);
void popup_fmt_scope_level(uint16_t off);

/* pop-up code -> its value text [fact: the compare chain of displink_build_31 0xFFF99297] */
static const struct { uint8_t code; void (*fmt)(uint16_t); } dl31_fmts[] = {
    {0x5E, popup_fmt_free_text}, {0x1F, popup_fmt_peak}, {0x22, popup_fmt_contrast}, {0x23, popup_fmt_dimmer},
    {0x24, popup_fmt_mgroup}, {0x25, popup_fmt_mic_gain}, {0x26, popup_fmt_mic_eq}, {0x27, popup_fmt_proc_level},
    {0x28, popup_fmt_amc_level}, {0x29, popup_fmt_vox_gain}, {0x2A, popup_fmt_vox_delay},
    {0x2B, popup_fmt_anti_vox}, {0x2C, popup_fmt_rf_power}, {0x2D, popup_fmt_moni_level}, {0x2F, popup_fmt_bk_in},
    {0x30, popup_fmt_cw_speed}, {0x31, popup_fmt_cw_pitch}, {0x32, popup_fmt_bk_delay},
    {0x33, popup_fmt_aess_level}, {0x38, popup_fmt_nb_level}, {0x39, popup_fmt_dnr_level},
    {0x3A, popup_fmt_dec_level}, {0x43, popup_fmt_qmb}, {0x44, popup_fmt_mem_scan}, {0x45, popup_fmt_mem_type},
    {0x46, popup_fmt_keyer}, {0x55, popup_fmt_mem_mode}, {0x58, popup_fmt_aess_cf}, {0x1E, popup_fmt_scope_level},
};

/* displink_build_31 0xFFF99297: frame 0x31, a value pop-up: byte 0x98 = pop-up code - 0x1E, nine spaces from 0x99,
 * then the pop-up's value text at 0x99 */
void displink_build_31(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    uint8_t *f = displink_stage;
    unsigned i;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    f[0] = 0x31;
    displink_copy_status();
    f[0x98] = (uint8_t)(ui->popup_code - 0x1Eu);
    for (i = 0x99; i <= 0xA1u; i++)
        f[i] = ' ';
    for (i = 0; i < sizeof dl31_fmts / sizeof dl31_fmts[0]; i++) {
        if (ui->popup_code == dl31_fmts[i].code) {
            dl31_fmts[i].fmt(0x99);
            return;
        }
    }
}

/* displink_build_37 0xFFF9AB57: frame 0x37, the FUNC panel: the status bytes, the flags, the FUNC knob function
 * and the 42 slot descriptions (the staging buffers 0x16A0 / 0x1741 cleared first) */
void displink_build_37(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr;
    unsigned k;

    mem_zero(0x98, displink_stage_status);
    mem_zero(0x24A, displink_stage);
    displink_stage[0] = 0x37;
    displink_copy_status();
    ui->dl37_bit7 = 1;
    ui->dl37_bit5 = 0;
    displink_stage[DL37_FLAGS] = (uint8_t)(ui->dl37_bit7 << 7 | ui->func_assigned << 6 | ui->dl37_bit5 << 5);
    displink_stage[DL37_FUNC_KNOB] = g_opstate.func_knob_sf;
    displink_stage[DL37_FUNC_KNOB + 1] = 0;
    for (k = 0; k < sizeof dl37_slots / sizeof dl37_slots[0]; k++)
        dl37_slots[k]((uint16_t)(DL37_SLOT0 + DL37_SLOT_LEN * k));
}
