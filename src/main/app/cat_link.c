/* The CAT port glue of the MAIN image and the CAT handlers that do not touch the radio state, recreated for T24
 * (docs/code/main/cat.md, sci.md).
 *
 * CAT runs on three ports: 1 = SCI3, 2 = SCI0, any other = SCI2 [fact: cat_send_reply 0xFFFB1D12]. Received
 * commands wait in a ring of 60 slots of 0x6A bytes (cat_rx_complete pushes, cat_task pops); a handler writes its
 * reply into cat_reply with its length in cat_reply_len, or sets cat_error for the "?;" reply. */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"
#include "r_cg_sci.h"
#include "cat_cmds.h"

#define CAT_RING_SLOTS 60u
#define CAT_SLOT_SIZE  0x6Au
#define CAT_PORT_SCI3  1
#define CAT_PORT_SCI0  2

/* --- sums (cat_ext_SP and the E-commands) --- */

/* sum8 0xFFFB01AF: 8-bit sum of n bytes, 16-bit count */
uint8_t sum8(const uint8_t *p, uint16_t n)
{
    uint8_t sum = 0;
    uint16_t i;

    for (i = 0; i < n; i++)
        sum = (uint8_t)(sum + p[i]);
    return sum;
}

/* cat_checksum_ok 0xFFFB0182: 1 when the byte after the first n is their sum */
uint8_t cat_checksum_ok(const uint8_t *p, uint16_t n)
{
    return sum8(p, n) == p[n] ? 1u : 0u;
}

/* --- the receive ring --- */

/* cat_ring_head 0xFFFB1C91, cat_ring_tail 0xFFFB1CA0 */
uint8_t cat_ring_head(void)
{
    return cat_ring_in;
}

uint8_t cat_ring_tail(void)
{
    return cat_ring_out;
}

/* cat_ring_unpop 0xFFFB1CAF: put the last slot back (its port was still sending; cat_task retries) */
void cat_ring_unpop(void)
{
    if (cat_ring_out == 0u)
        cat_ring_out = CAT_RING_SLOTS - 1u;
    else
        cat_ring_out--;
}

/* cat_ring_pop 0xFFFB1CD2: the next slot; the tail wraps after 60 */
uint8_t *cat_ring_pop(void)
{
    uint8_t *slot = &cat_ring[cat_ring_out * CAT_SLOT_SIZE];

    cat_ring_out = (uint8_t)((cat_ring_out + 1u) % CAT_RING_SLOTS);
    return slot;
}

/* cat_e9_slot 0xFFFB1D06: the single slot for E1/E9 frames (flag, port, len, data) */
uint8_t *cat_e9_slot(void)
{
    return cat_e_slot;
}

/* --- sending --- */

/* cat_send_reply 0xFFFB1D12: send on a port and mark it busy until its transmit-end callback */
void cat_send_reply(int32_t port, uint8_t *buf, uint16_t len)
{
    if (port == CAT_PORT_SCI3) {
        R_SCI3_Serial_Send(buf, len);
        cat_tx_busy_sci3 = 1;
    } else if (port == CAT_PORT_SCI0) {
        R_SCI0_Serial_Send(buf, len);
        cat_tx_busy_sci0 = 1;
    } else {
        R_SCI2_Serial_Send(buf, len);
        cat_tx_busy_sci2 = 1;
    }
}

/* cat_tx_done_sci0 0xFFFB1D5B, _sci2 0xFFFB1D65, _sci3 0xFFFB1D6F: the transmit-end callbacks */
void cat_tx_done_sci0(void)
{
    cat_tx_busy_sci0 = 0;
}

void cat_tx_done_sci2(void)
{
    cat_tx_busy_sci2 = 0;
}

void cat_tx_done_sci3(void)
{
    cat_tx_busy_sci3 = 0;
}

/* cat_tx_busy 0xFFFB1D79 */
uint8_t cat_tx_busy(int32_t port)
{
    if (port == CAT_PORT_SCI3)
        return cat_tx_busy_sci3;
    if (port == CAT_PORT_SCI0)
        return cat_tx_busy_sci0;
    return cat_tx_busy_sci2;
}

/* --- replies and simple handlers --- */

/* cat_reply_error 0xFFFB0166: "?;" */
void cat_reply_error(void)
{
    cat_reply[0] = '?';
    cat_reply[1] = ';';
    cat_reply_len = 2;
}

/* cat_ID 0xFFFAA365: "ID0800;" (the two mnemonic bytes are already in the reply) [fact: the stored bytes] */
void cat_ID(void)
{
    cat_reply[2] = '0';
    cat_reply[3] = '8';
    cat_reply[4] = '0';
    cat_reply[5] = '0';
    cat_reply[6] = ';';
    cat_reply_len = 7;
}

/* cat_QI 0xFFFAD704, cat_QR 0xFFFAD709: QMB store / recall */
void cat_QI(void)
{
    qmb_store();
}

void cat_QR(void)
{
    qmb_recall();
}

/* cat_QS 0xFFFAD70E, cat_EN 0xFFFA9928, cat_FS 0xFFFA9D3D: answered with "?;" in this firmware [fact] */
void cat_QS(void)
{
    cat_error = 1;
}

void cat_EN(const uint8_t *text)
{
    cat_error = 1;
}

void cat_FS(const uint8_t *text, uint8_t set)
{
    cat_error = 1;
}

/* cat_ai_holdoff 0xFFFDDB6A: no auto-information frame for 200 ms after a CAT set (timer 0x32) */
void cat_ai_holdoff(void)
{
    swtimer_start(0x32, 200);
    cat_ai_held = 1;
}

/* cat_rand8 0xFFFB2718: TPU0.TCNT modulo 255 (the E8 obfuscation key) */
uint8_t cat_rand8(void)
{
    uint32_t t = TPU0_TCNT;

    return (uint8_t)(t % 255u);
}
