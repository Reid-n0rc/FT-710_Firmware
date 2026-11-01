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
