/* SCI0..SCI5 interrupt handlers and Yaesu's callbacks (Renesas Code Generator r_cg_sci_user.c style), T24 MAIN.
 *
 * TXIn and RXIn are vectors (interrupt functions, RTE); TEIn and ERIn are group BL0 sources whose handlers
 * R_BSP_InterruptControl calls as ordinary functions (docs/code/main/sci.md "Interrupt wiring"). The callbacks and
 * the receive hooks are Yaesu's code: they hand finished frames to the CAT parser, the DISPLAY, DSP and SDR links.
 * Written from the disassembly: Ghidra's C of r_sci2_callback_transmitend, r_sci2_callback_receiveend and
 * sci5_rx_byte_hook leaves out their early returns (0xFFF93D91, 0xFFF93DAD, 0xFFF9498F/0xFFF94999/0xFFF949B3)
 * [fact: the rts instructions there]. */
#include "sci_cfg.h"

#define ISR __attribute__((interrupt))

/* TXIn: next byte into TDR; after the last one, TXI off and TEI on [fact: r_sci0_transmit_interrupt 0xFFF9340E] */
INLINE void sci_txi(const sci_cfg_t *c)
{
    if (*c->tx_count == 0u) {
        SCI_SCR(c) &= (uint8_t)~SCR_TIE;
        SCI_SCR(c) |= SCR_TEIE;
        return;
    }
    SCI_TDR(c) = **c->tx_address;
    (*c->tx_address)++;
    (*c->tx_count)--;
}

/* TEIn: TXD back to GPIO, TIE, TE and TEIE off, then the transmit-end callback
 * [fact: r_sci0_transmitend_interrupt 0xFFF9345A] */
INLINE void sci_tei(const sci_cfg_t *c)
{
    SFR8(c->txd_pmr) &= (uint8_t)~c->txd_bit;
    SCI_SCR(c) &= (uint8_t)~SCR_TIE;
    SCI_SCR(c) &= (uint8_t)~SCR_TE;
    SCI_SCR(c) &= (uint8_t)~SCR_TEIE;
}

/* RXIn: store the byte, let the channel's hook look at it (it may restart or resize the frame through the count,
 * length and pointer), advance; when the frame is complete, RIE and RE off and the receive-end callback. The second
 * test runs also when no byte was stored [fact: r_sci0_receive_interrupt 0xFFF9347F, compares 0xFFF93491/0xFFF934CF] */
#define SCI_RXI(c, hook, done)                                                                                        \
    do {                                                                                                              \
        if (*(c)->rx_count < *(c)->rx_length) {                                                                       \
            **(c)->rx_address = SCI_RDR(c);                                                                           \
            hook();                                                                                                   \
            (*(c)->rx_address)++;                                                                                     \
            (*(c)->rx_count)++;                                                                                       \
        }                                                                                                             \
        if (*(c)->rx_length <= *(c)->rx_count) {                                                                      \
            SCI_SCR(c) &= (uint8_t)~SCR_RIE;                                                                          \
            SCI_SCR(c) &= (uint8_t)~SCR_RE;                                                                           \
            done();                                                                                                   \
        }                                                                                                             \
    } while (0)

/* ERIn: the error callback first, then clear ORER, FER, PER (bits 5..3; bits 7..6 written as 1)
 * [fact: r_sci0_receiveerror_interrupt 0xFFF934F1] */
#define SCI_ERI(c, cb)                                                                                                \
    do {                                                                                                              \
        cb();                                                                                                         \
        SCI_SSR(c) = (uint8_t)((SCI_SSR(c) & 0xC7u) | 0xC0u);                                                         \
    } while (0)

/* ---- callbacks and receive hooks (Yaesu) ---- */

/* SCI0, CAT "Standard" port 2 [fact: 0xFFF93518, 0xFFF9351D, 0xFFF9352C, 0xFFF9352D] */
void r_sci0_callback_transmitend(void) { cat_tx_done_sci0(); }
void r_sci0_callback_receiveend(void) { cat_rx_complete(2, g_sci0_rx_length); }
void r_sci0_callback_receiveerror(void) {}
void r_sci0_rx_byte_hook(void)
{
    gp_sci0_rx_address = (uint8_t *)cat_rx_byte_hook(&g_sci0_rx_count, &g_sci0_rx_length, (char *)gp_sci0_rx_address, 5);
}

/* SCI1, DISPLAY link [fact: 0xFFF93845, 0xFFF93846, 0xFFF9384B] */
void r_sci1_callback_transmitend(void) {}
void r_sci1_callback_receiveend(void) { displink_rx_done(); }
void r_sci1_callback_receiveerror(void) {}

/* SCI2, TUNER/LINEAR jack: CAT port 3 in mode 2, tuner otherwise [fact: 0xFFF93D86, 0xFFF93D97, 0xFFF93DB3] */
void r_sci2_callback_transmitend(void)
{
    if (tunlin_port_mode() == 2u)
        cat_tx_done_sci2();
    else
        FUN_fffb1976();
}
void r_sci2_callback_receiveend(void)
{
    if (tunlin_port_mode() == 2u)
        cat_rx_complete(3, g_sci2_rx_length);
    else
        FUN_fffb1944();
}
void r_sci2_callback_receiveerror(void) {}

/* SCI3, CAT "Enhanced" port 1 [fact: 0xFFF94206, 0xFFF9420B, 0xFFF9421A, 0xFFF9421B] */
void r_sci3_callback_transmitend(void) { cat_tx_done_sci3(); }
void r_sci3_callback_receiveend(void) { cat_rx_complete(1, g_sci3_rx_length); }
void r_sci3_callback_receiveerror(void) {}
void sci3_rx_byte_hook(void)
{
    gp_sci3_rx_address = (uint8_t *)cat_rx_byte_hook(&g_sci3_rx_count, &g_sci3_rx_length, (char *)gp_sci3_rx_address, 4);
}

/* SCI4, IF DSP [fact: 0xFFF94535, 0xFFF94536, 0xFFF94547] */
void r_sci4_callback_transmitend(void) {}
void sci4_rx_frame_done(void)
{
    sci4_rx_set_ready();
    sci4_rx_set_len(g_sci4_rx_length);
}
void r_sci4_callback_receiveerror(void) {}

/* SCI5, SDR FPGA link [fact: 0xFFF9495B, 0xFFF9495C, 0xFFF94961] */
void r_sci5_callback_transmitend(void) {}
void r_sci5_callback_receiveend(void) { sdr_rx_done_cb(); }
void r_sci5_callback_receiveerror(void) {}

/* sci5_rx_byte_hook: the first byte of a reply sets the frame length: ACK 0x06 or '?' one byte, 'r' seven
 * (a register read reply); anything else is dropped (pointer and count back by one, so the count wraps to 0xFFFF
 * and the ISR's increment makes it 0) [fact: 0xFFF94962..0xFFF949B3; protocol in docs/code/main/sdr-link.md] */
void sci5_rx_byte_hook(void)
{
    uint8_t first;

    if (g_sci5_rx_count != 0u)
        return;
    first = *gp_sci5_rx_address;
    if (first == 0x06u || first == '?') {
        g_sci5_rx_length = 1u;
    } else if (first == 'r') {
        g_sci5_rx_length = 7u;
    } else {
        gp_sci5_rx_address--;
        g_sci5_rx_count--;
    }
}

/* ---- the handlers ---- */

#define SCI_HANDLERS(n, hook, done)                                                                                   \
    ISR void r_sci##n##_transmit_interrupt(void) { sci_txi(&SCI##n##_CFG); }                                          \
    void r_sci##n##_transmitend_interrupt(void) { sci_tei(&SCI##n##_CFG); r_sci##n##_callback_transmitend(); }        \
    ISR void r_sci##n##_receive_interrupt(void) { SCI_RXI(&SCI##n##_CFG, hook, done); }                               \
    void r_sci##n##_receiveerror_interrupt(void) { SCI_ERI(&SCI##n##_CFG, r_sci##n##_callback_receiveerror); }

SCI_HANDLERS(0, r_sci0_rx_byte_hook, r_sci0_callback_receiveend)
SCI_HANDLERS(1, displink_rx_frame_len, r_sci1_callback_receiveend)
SCI_HANDLERS(2, sci2_rx_byte_hook, r_sci2_callback_receiveend)
SCI_HANDLERS(3, sci3_rx_byte_hook, r_sci3_callback_receiveend)
SCI_HANDLERS(4, sci4_rx_frame_len, sci4_rx_frame_done)
SCI_HANDLERS(5, sci5_rx_byte_hook, r_sci5_callback_receiveend)
