/* The port lines of the TX/RX sequencer, recreated for T24 (docs/code/main/tx-protection.md "trx_sequencer"):
 * the RX (PB7) and TX (P73) lines, SEND_A (PA2) / SEND_B (PB4) keying, the PTT source (round 2), and the
 * sequencer's state machine trx_sequencer (round 3).
 *
 * SEND_A and SEND_B are held low while ETUN_TXINH_REQ (P14) is high or the TX line is low, so an external tuner can
 * inhibit transmission and SEND never comes before TX [fact: send_a_set 0xFFFB6FD2, send_b_set 0xFFFB7011]. */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

#define P14_ETUN_TXINH_REQ 0x10u
#define P73_TX             0x08u
#define PA2_SEND_A         0x04u
#define PB4_SEND_B         0x10u

/* ptt_source_get 0xFFFB6EC5: what keyed the transmitter (CAT TX reads 0 -> TX0, 5 -> TX1, else TX2) */
uint8_t ptt_source_get(void)
{
    return ptt_source;
}

/* tx_line_get 0xFFFB6FAC: P73 as output */
uint8_t tx_line_get(void)
{
    return (uint8_t)((PORT7_PODR >> 3) & 1u);
}

/* rx_line_get 0xFFFB721A: PB7 as output */
uint8_t rx_line_get(void)
{
    return (uint8_t)(PORTB_PODR >> 7);
}

/* send_a_get 0xFFFB6FBF: PA2 as output */
uint8_t send_a_get(void)
{
    return (uint8_t)((PORTA_PODR >> 2) & 1u);
}

static inline uint8_t send_inhibited(void)
{
    return (PORT1_PIDR & P14_ETUN_TXINH_REQ) != 0u || (PORT7_PODR & P73_TX) == 0u;
}

/* send_a_set 0xFFFB6FD2 */
void send_a_set(uint8_t on)
{
    if (send_inhibited())
        on = 0;
    PORTA_PODR = (uint8_t)((PORTA_PODR & (uint8_t)~PA2_SEND_A) | ((uint8_t)(on << 2) & PA2_SEND_A));
}

/* send_b_set 0xFFFB7011 */
void send_b_set(uint8_t on)
{
    if (send_inhibited())
        on = 0;
    PORTB_PODR = (uint8_t)((PORTB_PODR & (uint8_t)~PB4_SEND_B) | ((uint8_t)(on << 4) & PB4_SEND_B));
}

/* --- the sequencer (trx_sequencer 0xFFFB80F9; tx-protection.md "RX<->TX sequencer") --- */

#define P24_DATA_BUSY      0x10u
#define P70_INT_SP_SW      0x01u
#define PB2_EXT_SP_SW      0x04u
#define P80_EAR_SW         0x01u
#define PB7_RX             0x80u
#define SPK_ROUTE_ALL_OFF  4u         /* speaker_route's route 4 (peripherals.md "Speaker routing") */

enum trx_state {
    TRX_PTT = 0,            /* the arbiter saw a PTT request */
    TRX_TO_TX = 1,          /* switching to TX: timers 0x0C..0x10 */
    TRX_TX_DELAY = 2,       /* timer 0x11 */
    TRX_TX = 3,
    TRX_RELEASE = 4,
    TRX_SEND_OFF = 5,
    TRX_WAIT_ROUTE = 6,
    TRX_TO_RX = 7,
    TRX_RX = 8
};

/* PTT sources 7, 8 and 9 (ptt_source_select): no QSK delay for 7, and for 8/9 when the CW key is inserted outside
 * the keying classes 0 and 2 [fact: 0xFFFB813C..0xFFFB8170; tx-protection.md "RX->TX"] */
#define PTT_SRC_7          7u
#define PTT_SRC_8          8u
#define PTT_SRC_9          9u

static inline int cw_class_keys(uint8_t cls)
{
    return cls == 0u || cls == 2u;
}

/* the speaker switches of the current route, unless the route is "all off"; with phones in, only EAR_SW */
static void speakers_restore(void)
{
    if (spk_route != SPK_ROUTE_ALL_OFF) {
        if (!ear_det()) {
            PORT7_PODR |= P70_INT_SP_SW;
            PORTB_PODR |= PB2_EXT_SP_SW;
        }
        PORT8_PODR |= P80_EAR_SW;
    }
}

static void send_both(uint8_t on)
{
    send_a_set(on);
    send_b_set(on);
}

/* trx_sequencer 0xFFFB80F9: one step of the RX->TX (states 0..3) and TX->RX (4..8) sequence per call */
void trx_sequencer(void)
{
    uint32_t freq = g_ui.freq_tx;
    uint8_t tx_delay = qsk_delay_ticks();                 /* EX020119 QSK DELAY TIME x 5 + 15 */
    uint8_t shape = g_opstate.ex020117_cw_wave_shape;
    uint8_t cls = tx_cw_keying_class();
    uint8_t d = (uint8_t)(shape * 2u + 4u);                /* TX->RX step: 2 x CW WAVE SHAPE + 4 ms */

    ptt_arbiter();
    if (tx_breakin_on() == 1) {
        if (ptt_source == PTT_SRC_7)
            tx_delay = 0;
        else if ((ptt_source == PTT_SRC_8 || ptt_source == PTT_SRC_9) && ckey_det() && !cw_class_keys(cls))
            tx_delay = 0;
    }

    switch (g_ui.trx_state) {
    case TRX_PTT:
        if (tx_freq_allowed(freq)) {
            g_ui.trx_state = TRX_TO_TX;
            swtimer_start(0x0C, 1);
            swtimer_start(0x0D, 1);
            swtimer_start(0x0E, 5);
            swtimer_start(0x0F, 1);
            swtimer_start(0x10, 3);
            swtimer_start(0x11, tx_delay);
        }
        g_ui.tx_ack_sdr = 0;
        g_ui.tx_ack_dsp = 0;
        break;

    case TRX_TO_TX:
        if (!(PORT2_PODR & P24_DATA_BUSY) && swtimer_expired(0x0C) == 1)
            PORT2_PODR |= P24_DATA_BUSY;
        if (!af_mute_get() && swtimer_expired(0x0D) == 1)
            af_mute_set(1);
        if (swtimer_expired(0x0E) == 1) {
            if (cls != 1u && cls != 3u) {                  /* speakers off, not in the CW modes */
                PORT7_PODR &= (uint8_t)~P70_INT_SP_SW;
                PORTB_PODR &= (uint8_t)~PB2_EXT_SP_SW;
                PORT8_PODR &= (uint8_t)~P80_EAR_SW;
            }
            if (g_ui.tx_ack_sdr == 1 && g_ui.tx_ack_dsp == 1) {   /* SDR and DSP have switched */
                speakers_restore();
                if (af_mute_get())
                    af_mute_set(0);
                g_ui.trx_state = TRX_TX_DELAY;
            }
        }
        if ((PORTB_PODR & PB7_RX) && swtimer_expired(0x0F) == 1)
            PORTB_PODR &= (uint8_t)~PB7_RX;                /* RX8 rail off */
        if (swtimer_expired(0x10) == 1)
            PORT7_PODR |= P73_TX;                          /* TX8 rail on */
        break;

    case TRX_TX_DELAY:
        if (swtimer_expired(0x11) == 1) {
            pc_key_last = 1;
            g_ui.trx_state = TRX_TX;
        }
        break;

    case TRX_TX:
        /* SEND_A/B follow ETUN_TXINH_REQ (P14): off when it rises, keyed again when it falls */
        if (pc_key_last != ((PORT1_PIDR >> 4) & 1u)) {
            if (((PORT1_PIDR >> 4) & 1u) == 1u) {
                send_both(0);
            } else if (ptt_source != PTT_SRC_7) {
                if (ptt_source == PTT_SRC_8 || ptt_source == PTT_SRC_9) {
                    if (!ckey_det() || cw_class_keys(cls))
                        send_both(1);
                } else if (pc_keying_active == 0 || tx_breakin_on() == 1) {
                    send_both(1);
                }
            }
            pc_key_last = (uint8_t)((PORT1_PIDR >> 4) & 1u);
        }
        break;

    case TRX_RELEASE:
        g_ui.trx_state = TRX_SEND_OFF;
        g_ui.tx_ack_sdr = 0;
        g_ui.tx_ack_dsp = 0;
        break;

    case TRX_SEND_OFF:
        send_both(0);
        g_ui.trx_state = TRX_WAIT_ROUTE;
        swtimer_start(0x12, d);
        swtimer_start(0x0C, (uint16_t)(d + 6u));
        swtimer_start(0x0D, (uint16_t)(g_ui.rx_unmute_delay_ms + d));   /* audio back last */
        swtimer_start(0x0E, (uint16_t)(d + 5u));
        swtimer_start(0x0F, (uint16_t)(d + 4u));
        swtimer_start(0x10, (uint16_t)(d + 3u));
        break;

    case TRX_WAIT_ROUTE:
        if (swtimer_expired(0x12) == 1 && g_ui.dsp_route_ready == 1) {
            if (!af_mute_get())
                af_mute_set(1);
            g_ui.trx_state = TRX_TO_RX;
        }
        break;

    case TRX_TO_RX:
        if (((PORT7_PODR >> 3) & 1u) == 1u && swtimer_expired(0x10) == 1)
            PORT7_PODR &= (uint8_t)~P73_TX;                /* TX8 rail off */
        if (!(PORTB_PODR & PB7_RX) && swtimer_expired(0x0F) == 1)
            PORTB_PODR |= PB7_RX;                          /* RX8 rail on */
        if (((PORT2_PODR >> 4) & 1u) == 1u && swtimer_expired(0x0C) == 1)
            PORT2_PODR &= (uint8_t)~P24_DATA_BUSY;
        if (swtimer_expired(0x0E) == 1)
            speakers_restore();
        if (swtimer_expired(0x0D) == 1) {
            if (af_mute_get() && g_ui.pb3_last == 0) {
                swtimer_start(0x2A, 0);
                af_mute_set(0);
            }
            g_ui.trx_state = TRX_RX;
        }
        break;

    default:                                               /* 8: RX, nothing to do */
        break;
    }
    pc_keying();
}
