/* The port lines of the TX/RX sequencer, recreated for T24 (docs/code/main/tx-protection.md "trx_sequencer"):
 * the RX (PB7) and TX (P73) lines, SEND_A (PA2) / SEND_B (PB4) keying, and the PTT source. trx_sequencer itself
 * is not recreated yet.
 *
 * SEND_A and SEND_B are held low while ETUN_TXINH_REQ (P14) is high or the TX line is low, so an external tuner can
 * inhibit transmission and SEND never comes before TX [fact: send_a_set 0xFFFB6FD2, send_b_set 0xFFFB7011]. */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"

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
