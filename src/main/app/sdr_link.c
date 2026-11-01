/* The MAIN -> SDR unit register link on SCI5, recreated for T24 (docs/code/main/sdr-link.md): the SCI5 glue, the
 * frame layer (app/reglink.h, shared with the DSP link) and the register updaters whose value is a constant or one
 * menu setting. The shadows are filled by sdr_shadow_update from the replies. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "r_cg_sci.h"
#include "reglink.h"

#define SDR_REPLY_TIMER 2    /* soft timer of the reply timeout [fact: swtimer_start(2, 6), 0xFFFA31A8] */
#define SDR_RX_MAX      7u   /* a reply is at most "r" + 4 hex + 2 hex [fact: sdr_send_cmd 0xFFFB1B42] */

/* sdr_shadow (RAM 0x1B736, uint16 each): slot of each register [fact: the offset each updater compares] */
enum sdr_shadow_slot {
    SH_R03 = 2, SH_R04 = 3, SH_R0D = 9, SH_R0E = 10, SH_R12 = 12, SH_R13 = 13, SH_R15 = 15, SH_R1C = 21,
    SH_R23 = 28, SH_R24 = 29,
    SH_R18 = 17, SH_R19 = 18, SH_R1D = 22, SH_R1E = 23,   /* round 3 */
};

static const struct reglink sdr_link = {
    .frame = sdr_tx_frame, .reg = &sdr_tx_reg, .data = &sdr_tx_data, .shadow = sdr_shadow,
    .busy_write = &sdr_busy_write, .busy_read = &sdr_busy_read, .timer = SDR_REPLY_TIMER,
    .sum8 = sdr_sum8, .sum_ok = sdr_check_hex_sum, .send = sdr_send_cmd, .rx_ready = sdr_rx_ready,
    .rx_buf = sdr_rx_buf,
};

/* --- SCI5 glue (0xFFFB1AF8..0xFFFB1B4F) --- */

/* sdr_link_start 0xFFFB1AF8: no reply yet; start SCI5 (part of sci_start_all) */
void sdr_link_start(void)
{
    sdr_rx_done = 0;
    R_SCI5_Start();
}

/* sdr_rx_ready 0xFFFB1B06 */
uint8_t sdr_rx_ready(void)
{
    return sdr_rx_done;
}

/* sdr_rx_done_cb 0xFFFB1B15: SCI5's receive-end callback */
void sdr_rx_done_cb(void)
{
    sdr_rx_done = 1;
}

/* sdr_rx_buf 0xFFFB1B1F */
uint32_t sdr_rx_buf(void)
{
    return (uint32_t)(uintptr_t)sdr_rx_frame;
}

/* sdr_send_cmd 0xFFFB1B2B: send, then receive the reply (sci5_rx_byte_hook ends it early for ACK or "?") */
void sdr_send_cmd(uint32_t buf, uint16_t len)
{
    R_SCI5_Serial_Send((uint8_t *)(uintptr_t)buf, len);
    sdr_rx_done = 0;
    R_SCI5_Serial_Receive(sdr_rx_frame, SDR_RX_MAX);
}

/* --- frame layer --- */

/* sdr_sum8 0xFFFA31AE */
uint8_t sdr_sum8(const uint8_t *p, uint8_t n)
{
    return link_sum8(p, n);
}

/* sdr_check_hex_sum 0xFFFA31DB */
uint8_t sdr_check_hex_sum(const uint8_t *p, uint8_t n)
{
    return link_sum_ok(&sdr_link, p, n);
}

/* sdr_poll_reply 0xFFFA3083 */
uint8_t sdr_poll_reply(uint8_t kind, uint8_t **reply)
{
    return link_check_reply(&sdr_link, kind, reply);
}

/* sdr_send_frame 0xFFFA30F9 */
void sdr_send_frame(uint8_t kind)
{
    link_send_frame(&sdr_link, kind);
}

static inline void sdr_write_if_changed(uint16_t reg, enum sdr_shadow_slot slot, uint16_t value)
{
    link_write_if_changed(&sdr_link, sdr_send_frame, reg, slot, value);
}

/* --- register updaters (sdr-link.md "Register map") --- */

/* sdr_upd_r03 0xFFFA15A0: 0xE61D, with bit 5 set up to 60 MHz on VFO 1's TX side [fact: cmp #0x3B9ACA0] */
void sdr_upd_r03(void)
{
    uint32_t f = vfo_freq(1, 2);
    uint16_t v = 0xE61Du;

    if (f <= 60000000u)
        v |= 0x0020u;
    else
        v &= (uint16_t)~0x0020u;
    sdr_write_if_changed(0x03u, SH_R03, v);
}

/* sdr_upd_r04 0xFFFA15F3: constant 0xE519; it reads VFO 0's record pointer and does not use it [fact] */
void sdr_upd_r04(void)
{
    (void)vfo_rec_ptr(0);
    sdr_write_if_changed(0x04u, SH_R04, 0xE519u);
}

/* sdr_upd_r0d 0xFFFA18AE: 9 / 14 / 19 from the CW wave-shape setting (0x9AA1: 0, 1, other) */
void sdr_upd_r0d(void)
{
    uint8_t s = menu_cw_wave_shape;
    uint16_t v;

    if (s == 1u)
        v = 14;
    else if (s == 0u)
        v = 9;
    else
        v = 19;
    sdr_write_if_changed(0x0Du, SH_R0D, v);
}

/* constants [fact: the immediate of each updater] */
void sdr_upd_r0e(void) { sdr_write_if_changed(0x0Eu, SH_R0E, 0x1200u); }
void sdr_upd_r12(void) { sdr_write_if_changed(0x12u, SH_R12, 0x8000u); }
void sdr_upd_r13(void) { sdr_write_if_changed(0x13u, SH_R13, 0x8000u); }
void sdr_init_r15(void) { sdr_write_if_changed(0x15u, SH_R15, 0x2000u); }
void sdr_init_r24(void) { sdr_write_if_changed(0x24u, SH_R24, 0x0317u); }

/* sdr_upd_r1c 0xFFFA20AF: 2 / 5 / 10 from the NB REJECTION setting (0x9AD2: 0, other, 2) */
void sdr_upd_r1c(void)
{
    uint8_t s = menu_nb_rejection;
    uint16_t v;

    if (s == 2u)
        v = 10;
    else if (s == 0u)
        v = 2;
    else
        v = 5;
    sdr_write_if_changed(0x1Cu, SH_R1C, v);
}

/* sdr_upd_r23 0xFFFA2992: 0x7000 / 0x5000 / 0x8000 from the scope RBW setting (0x9B14: 1, 2, other) */
void sdr_upd_r23(void)
{
    uint8_t s = menu_scope_rbw;
    uint16_t v;

    if (s == 1u)
        v = 0x7000u;
    else if (s == 2u)
        v = 0x5000u;
    else
        v = 0x8000u;
    sdr_write_if_changed(0x23u, SH_R23, v);
}

/* sdr_shadow_update 0xFFFA2C9F: after an acknowledged write, the value goes into the shadow slot of its register;
 * register 0xFFFF has slot 38 (0x1B782) [fact: the compare chain 0xFFFA2C9F..0xFFFA2FF6, one register per slot] */
static const struct { uint16_t reg; uint8_t slot; } sdr_shadow_map[] = {
    {0xFFFF, 38}, {0x0001, 1}, {0x0003, 2}, {0x0004, 3}, {0x0008, 4}, {0x0009, 5}, {0x000A, 6}, {0x000B, 7},
    {0x000C, 8}, {0x000D, 9}, {0x000E, 10}, {0x000F, 11}, {0x0012, 12}, {0x0013, 13}, {0x0014, 14}, {0x0015, 15},
    {0x0016, 16}, {0x0018, 17}, {0x0019, 18}, {0x001A, 19}, {0x001B, 20}, {0x001C, 21}, {0x001D, 22}, {0x001E, 23},
    {0x001F, 24}, {0x0020, 25}, {0x0021, 26}, {0x0022, 27}, {0x0023, 28}, {0x0024, 29}, {0x0025, 30}, {0x0026, 31},
    {0x0027, 32}, {0x0030, 33}, {0x0031, 34}, {0x0032, 35}, {0x0033, 36}, {0x0037, 37}, {0x0000, 0},
};

void sdr_shadow_update(void)
{
    unsigned i;

    for (i = 0; i < sizeof sdr_shadow_map / sizeof sdr_shadow_map[0]; i++) {
        if (sdr_shadow_map[i].reg == sdr_tx_reg) {
            sdr_shadow[sdr_shadow_map[i].slot] = sdr_tx_data;
            return;
        }
    }
}

/* --- the receive frequency and passband (round 3) --- */

static inline uint16_t be16(const uint8_t *p)
{
    return (uint16_t)(p[0] << 8 | p[1]);
}

/* the mode's offset applied to the dial frequency: added on the upper side, subtracted on the lower side (CW-L,
 * DATA-L, LSB) [fact: the sign handling of each branch of sdr_upd_r18_rx_freq 0xFFFA1C69] */
static inline uint32_t side_offset(uint32_t f, uint16_t off, int lower)
{
    return lower ? f - (uint32_t)(int32_t)(int16_t)off : f + (uint32_t)(int32_t)(int16_t)off;
}

/* the RTTY shift choices 0..3 (EX010516 SHIFT FREQUENCY) as the offset sdr_upd_r18_rx_freq uses */
static uint16_t rtty_shift_hz(uint8_t sel)
{
    return sel == 1 ? 105u : sel == 2 ? 215u : sel == 3 ? 425u : 85u;
}

/* sdr_upd_r18_rx_freq 0xFFFA1C69: regs 0x18 (high half) and 0x19 (low half) = the receive frequency in Hz: the dial
 * with the clarifier, plus the mode's offset: PSK and DATA the IF SHIFT (DATA also DATA SHIFT (SSB) x 10), CW the
 * IF SHIFT plus half of the filter width beyond the pitch window, RTTY the shift choice and the IF SHIFT, SSB
 * 1500 Hz plus the IF SHIFT. A new high half invalidates the low half's shadow, so both go out. */
void sdr_upd_r18_rx_freq(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    uint32_t f = vfo_freq_clar(0, 2);
    int16_t data_shift = (int16_t)be16(g_opstate.ex010420_data_shift_ssb_be);
    uint16_t off;

    if (m == MODE_PSK) {
        f = side_offset(f, be16(r->blk[3].shift_be), 0);
    } else if (m == MODE_CW_L || m == MODE_CW_U) {
        uint8_t width_be[2];
        uint16_t window = (uint16_t)(g_opstate.cw_pitch * 10u + 300u);

        off = be16(r->blk[1].shift_be);
        vfo_filter_width_hz(width_be);
        if (be16(width_be) >= window)
            off = (uint16_t)((int16_t)((int32_t)(be16(width_be) - window) / 2) + off);
        f = side_offset(f, off, m == MODE_CW_L);
    } else if (m == MODE_DATA_L || m == MODE_DATA_U) {
        off = (uint16_t)(data_shift * 10 + be16(r->blk[3].shift_be));
        f = side_offset(f, off, m == MODE_DATA_L);
    } else if (m == MODE_RTTY_L || m == MODE_RTTY_U) {
        int16_t shift = (int16_t)be16(r->blk[2].shift_be);

        if (m != MODE_RTTY_L)
            shift = (int16_t)-shift;
        off = (uint16_t)(rtty_shift_hz(g_opstate.ex010516_shift_frequency) + shift);
        f = side_offset(f, off, 1);
    } else if (m == MODE_LSB || m == MODE_USB) {
        off = (uint16_t)(be16(r->blk[0].shift_be) + 1500u);
        f = side_offset(f, off, m == MODE_LSB);
    }

    if ((uint16_t)(f >> 16) != sdr_shadow[SH_R18]) {
        sdr_tx_reg = 0x18;
        sdr_tx_data = (uint16_t)(f >> 16);
        sdr_send_frame(LINK_WRITE);
        sdr_shadow[SH_R19] = 0xFFFF;
        return;
    }
    sdr_write_if_changed(0x19u, SH_R19, (uint16_t)f);
}

/* the RTTY passband centre for MARK FREQUENCY 0 / other and the four SHIFT choices [fact: the constants of
 * 0xFFFA2478]; each is 1275 or 2125 Hz plus rtty_shift_hz of the same choice [inference: their differences] */
static uint16_t rtty_centre_hz(uint8_t mark, uint8_t sel)
{
    static const uint16_t low[4] = {0x550, 0x564, 0x5D2, 0x6A4}, high[4] = {0x8A2, 0x8B6, 0x924, 0x9F6};
    unsigned k = sel <= 3u ? sel : 0u;

    return mark == 0 ? low[k] : high[k];
}

static inline uint16_t psk_tone_hz(void)
{
    return g_opstate.ex010419_psk_tone == 1 ? 1500u : g_opstate.ex010419_psk_tone == 2 ? 2000u : 1000u;
}

/* the passband centre in Hz of the mode (0 for AM and FM): PSK the PSK TONE (1000/1500/2000 Hz) + IF SHIFT, CW the
 * pitch window (pitch x 10 + 300 Hz) or the middle of window and filter width + IF SHIFT, DATA the DATA SHIFT (SSB)
 * x 10 + IF SHIFT, RTTY mark and shift + IF SHIFT, SSB 1500 Hz + IF SHIFT [fact: sdr_upd_r1e_passband 0xFFFA2478,
 * sdr_upd_r1d_notch 0xFFFA20F7]. sdr_upd_r1d_notch adds the DATA SHIFT x 10 to the PSK tone instead of the IF
 * SHIFT (psk_data_shift). */
static uint16_t passband_centre(const struct vfo_rec *r, uint8_t m, int psk_data_shift)
{
    int16_t data_shift = (int16_t)be16(g_opstate.ex010420_data_shift_ssb_be);

    if (m == MODE_PSK)
        return (uint16_t)((psk_data_shift ? (uint16_t)(data_shift * 10) : be16(r->blk[3].shift_be)) + psk_tone_hz());
    if (m == MODE_CW_L || m == MODE_CW_U) {
        uint8_t width_be[2];
        uint16_t window = (uint16_t)(g_opstate.cw_pitch * 10u + 300u);
        uint16_t c = be16(r->blk[1].shift_be);

        vfo_filter_width_hz(width_be);
        if (be16(width_be) < window)
            return (uint16_t)(c + window);
        return (uint16_t)((uint16_t)((uint32_t)(be16(width_be) + window) / 2u) + c);
    }
    if (m == MODE_DATA_L || m == MODE_DATA_U)
        return (uint16_t)(data_shift * 10 + be16(r->blk[3].shift_be));
    if (m == MODE_RTTY_L || m == MODE_RTTY_U)
        return (uint16_t)(be16(r->blk[2].shift_be) +
                          rtty_centre_hz(g_opstate.ex010515_mark_frequency, g_opstate.ex010516_shift_frequency));
    if (m == MODE_LSB || m == MODE_USB)
        return (uint16_t)(be16(r->blk[0].shift_be) + 1500u);
    return 0;
}

/* an offset in Hz as the SDR's signed 5 Hz steps (truncated toward 0), negated in the upper-side modes USB, CW-U,
 * DATA-U, RTTY-U, PSK */
static uint16_t sdr_steps(uint16_t hz, uint8_t m)
{
    uint16_t v = (uint16_t)((int16_t)hz / 5);

    if (m == MODE_USB || m == MODE_CW_U || m == MODE_DATA_U || m == MODE_RTTY_U || m == MODE_PSK)
        v = (uint16_t)-v;
    return v;
}

/* sdr_upd_r1e_passband 0xFFFA2478: reg 0x1E = the passband centre in 5 Hz steps */
void sdr_upd_r1e_passband(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);

    sdr_write_if_changed(0x1Eu, SH_R1E, sdr_steps(passband_centre(r, m, 0), m));
}

/* the mode block whose manual NOTCH the SDR applies: DATA/PSK, CW, RTTY, SSB; none in AM and FM */
static const struct mode_blk *notch_blk(const struct vfo_rec *r, uint8_t m)
{
    if (m == MODE_PSK || m == MODE_DATA_L || m == MODE_DATA_U)
        return &r->blk[3];
    if (m == MODE_CW_L || m == MODE_CW_U)
        return &r->blk[1];
    if (m == MODE_RTTY_L || m == MODE_RTTY_U)
        return &r->blk[2];
    if (m == MODE_LSB || m == MODE_USB)
        return &r->blk[0];
    return NULL;
}

/* sdr_upd_r1d_notch 0xFFFA20F7: reg 0x1D = (passband centre - NOTCH x 10 Hz) in 5 Hz steps, 12 bits when negative,
 * | 0x2000 (IF NOTCH WIDTH 0) or 0x1000; 0 while the notch is off or in AM/FM */
void sdr_upd_r1d_notch(void)
{
    const struct vfo_rec *r = (const struct vfo_rec *)vfo_rec_ptr(0);
    uint8_t m = vfo_mode(0);
    uint8_t width = g_opstate.ex030201_if_notch_width;
    const struct mode_blk *b = notch_blk(r, m);
    uint16_t v = 0;

    if (b)
        v = (uint16_t)(passband_centre(r, m, 1) - be16(b->notch_be) * 10u);
    v = sdr_steps(v, m);
    if (v & 0x8000u)
        v &= 0x0FFFu;
    if (b == NULL || (b->flags & 0x80u) == 0)
        v = 0;
    else
        v |= width == 0 ? 0x2000u : 0x1000u;
    sdr_write_if_changed(0x1Du, SH_R1D, v);
}

/* --- the SDR task (round 4) --- */

void sdr_bridge_mode(void);
uint8_t rx_line_get(void);
uint8_t tx_line_get(void);
void sdr_upd_r0a_demod(uint8_t tx);
void sdr_upd_r0b_band(uint8_t tx);
void sdr_upd_r0c_rtty_shift(void);
void sdr_upd_r0f_band(uint8_t tx);
void sdr_upd_r20_scope_freq(uint8_t tx);
void sdr_upd_r22_scope_span(uint8_t tx);
void sdr_upd_r25_tx_drive(uint8_t tx);
void sdr_upd_r26(uint8_t tx);
void sdr_upd_r27_scope_level(uint8_t tx);
void sdr_upd_r08_tx_freq(void);
void sdr_upd_r14_mode(void);
void sdr_upd_r16_filter(void);
void sdr_upd_r1a_nb_level(void);
void sdr_upd_r1b(void);
void sdr_upd_r1f_width(void);

/* one register updater; the pass ends at the first one that sends a write (sdr_busy_write) */
#define SDR_STEP(call)                  \
    do {                                \
        call;                           \
        if (sdr_busy_write != 0)        \
            return;                     \
    } while (0)

/* sdr_task 0xFFFA11ED: main-loop task 3. A pending write waits for its reply (and updates the shadow), the bridge
 * mode runs on request, a TX/RX change waits until the old switching line has dropped, then the register updaters
 * run in order until one writes (one write per pass; the RX-only registers are skipped while transmitting). After
 * the first full pass regs 0x15 and 0x24 are written once; a full pass in sequencer state 1 or 7 acknowledges the
 * TX/RX change to the sequencer (sdr-link.md). */
void sdr_task(void)
{
    uint8_t tx = g_ui.transmitting;
    uint8_t state = g_ui.trx_state;
    uint8_t *reply[2];

    if (sdr_busy_write == 1) {
        if (sdr_poll_reply('w', (uint8_t **)reply) != 1)
            return;
        sdr_shadow_update();
    }
    if (sdr_bridge_req == 1)
        sdr_bridge_mode();
    if (sdr_last_tx != tx) {
        if (tx == 1 && rx_line_get() != 0)
            return;
        if (tx == 0 && tx_line_get() != 0)
            return;
        sdr_last_tx = tx;
    }
    sdr_upd_r0a_demod(tx);
    if (sdr_busy_write != 0)
        return;
    SDR_STEP(sdr_upd_r0b_band(tx));
    SDR_STEP(sdr_upd_r0c_rtty_shift());
    SDR_STEP(sdr_upd_r0d());
    SDR_STEP(sdr_upd_r0f_band(tx));
    SDR_STEP(sdr_upd_r20_scope_freq(tx));
    SDR_STEP(sdr_upd_r22_scope_span(tx));
    SDR_STEP(sdr_upd_r23());
    SDR_STEP(sdr_upd_r25_tx_drive(tx));
    SDR_STEP(sdr_upd_r26(tx));
    SDR_STEP(sdr_upd_r27_scope_level(tx));
    SDR_STEP(sdr_upd_r03());
    SDR_STEP(sdr_upd_r08_tx_freq());
    SDR_STEP(sdr_upd_r0e());
    SDR_STEP(sdr_upd_r14_mode());
    if (tx == 0) {                          /* the RX-only registers */
        SDR_STEP(sdr_upd_r04());
        SDR_STEP(sdr_upd_r12());
        SDR_STEP(sdr_upd_r13());
        SDR_STEP(sdr_upd_r16_filter());
        SDR_STEP(sdr_upd_r18_rx_freq());
        SDR_STEP(sdr_upd_r1a_nb_level());
        SDR_STEP(sdr_upd_r1b());
        SDR_STEP(sdr_upd_r1c());
        SDR_STEP(sdr_upd_r1d_notch());
        SDR_STEP(sdr_upd_r1e_passband());
        SDR_STEP(sdr_upd_r1f_width());
    }
    if (sdr_synced == 0) {
        SDR_STEP(sdr_init_r15());
        SDR_STEP(sdr_init_r24());
        sdr_synced = 1;
    }
    if (state == 1 || state == 7)
        g_ui.tx_ack_sdr = 1;
}
