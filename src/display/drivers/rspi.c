/*
 * FT-710 DISPLAY (T24 round 6): the per-channel RSPI helpers, 0x2011E118..0x2011ED23 (part), recreated from the
 * image.
 *
 * The five RSPI channels (base 0xE800C800 + 0x800 n; SPCR +0, SPSR +3, SPBFCR +0x20) each have the same small set of
 * functions in the image, one copy per channel [fact: the literals of 0x2011E118..0x2011ED23]: the interrupt flags
 * the ISRs set and the drivers poll (receive done 0x20800418 + n, transmit done 0x2080041D + n), the receive ISRs
 * (channels 0 and 1 reset the receive buffer and count, 2..4 mask the receive interrupt), the transmit ISRs (mask
 * SPTIE), "enable SPTIE and wait", "wait for TEND", a short busy delay, and the GIC entry stubs of the generic
 * driver's ISRs (rspi_rx_isr / rspi_tx_isr with the channel). docs/code/display/spi-links.md describes what the
 * channels connect to. Register bit names are the RZ/A1H hardware manual's (RSPI chapter).
 */
#include "display.h"

#define RSPI_BASE(n) (0xE800C800U + 0x800U * (n))
#define RSPI_SPCR(n) (&REG8(RSPI_BASE(n)))
#define RSPI_SPSR(n) (&REG8(RSPI_BASE(n) + 3U))
#define RSPI_SPBFCR(n) (&REG8(RSPI_BASE(n) + 0x20U))

extern volatile uint8_t rspi_rx_done[5];   /* 0x20800418: set by the receive ISRs */
extern volatile uint8_t rspi_tx_done[5];   /* 0x2080041D: set by the transmit ISRs */
extern uint32_t rspi_rx_count[2];          /* 0x208DCE28: receive interrupts of channels 0 and 1 */

void rspi_rx_isr(int ch);    /* 0x2011F840 */
void rspi_tx_isr(int ch);    /* 0x2011F89C */

/* 0x2011E118 + 0x10 n: clear the receive-done flag [fact] */
#define RSPI_CLEAR_RX(n)                                                                                           \
    void rspi##n##_clear_rx_flag(void)                                                                             \
    {                                                                                                              \
        rspi_rx_done[n] = 0;                                                                                       \
    }

/* 0x2011E168..0x2011E1E0: clear the transmit-done flag [fact] */
#define RSPI_CLEAR_TX(n)                                                                                           \
    void rspi##n##_clear_tx_flag(void)                                                                             \
    {                                                                                                              \
        rspi_tx_done[n] = 0;                                                                                       \
    }

/* 0x2011E1F0, 0x2011E240: channels 0 and 1: pulse RXRST (SPBFCR bit 6) to empty the receive buffer, count, flag
 * [fact] */
#define RSPI_RX_ISR_RESET(n)                                                                                       \
    void rspi##n##_rx_isr(void)                                                                                    \
    {                                                                                                              \
        reg_rmw8(RSPI_SPBFCR(n), 1, 6, 0x40);                                                                      \
        reg_rmw8(RSPI_SPBFCR(n), 0, 6, 0x40);                                                                      \
        rspi_rx_count[n]++;                                                                                        \
        rspi_rx_done[n] = 1;                                                                                       \
    }

/* 0x2011E290 + 0x28 (n - 2): channels 2..4: SPRIE off (SPCR bit 7), flag [fact] */
#define RSPI_RX_ISR_MASK(n)                                                                                        \
    void rspi##n##_rx_isr(void)                                                                                    \
    {                                                                                                              \
        reg_rmw8(RSPI_SPCR(n), 0, 7, 0x80);                                                                        \
        rspi_rx_done[n] = 1;                                                                                       \
    }

/* 0x2011E308 + 0x28 n: SPTIE off (SPCR bit 5), flag [fact] */
#define RSPI_TX_ISR(n)                                                                                             \
    void rspi##n##_tx_isr(void)                                                                                    \
    {                                                                                                              \
        reg_rmw8(RSPI_SPCR(n), 0, 5, 0x20);                                                                        \
        rspi_tx_done[n] = 1;                                                                                       \
    }

/* 0x2011E3D0 + 0x16C n: SPTIE on, then wait until the transmit ISR has run [fact] */
#define RSPI_TX_WAIT(n)                                                                                            \
    void rspi##n##_tx_wait(void)                                                                                   \
    {                                                                                                              \
        reg_rmw8(RSPI_SPCR(n), 1, 5, 0x20);                                                                        \
        while (rspi_tx_done[n] == 0)                                                                               \
        {                                                                                                          \
        }                                                                                                          \
    }

/* 0x2011EB58 + 0x24 n: wait for TEND (SPSR bit 6) [fact] */
#define RSPI_WAIT_TEND(n)                                                                                          \
    void rspi##n##_wait_tend(void)                                                                                 \
    {                                                                                                              \
        while (reg_read8(RSPI_SPSR(n), 6, 0x40) == 0)                                                              \
        {                                                                                                          \
        }                                                                                                          \
    }

/* 0x2011EC0C + 0x28 n: count a volatile word down from 10 [fact] */
#define RSPI_DELAY(n)                                                                                              \
    void rspi##n##_delay(void)                                                                                     \
    {                                                                                                              \
        volatile int k;                                                                                            \
                                                                                                                   \
        for (k = 10; k > 0; k--)                                                                                   \
        {                                                                                                          \
        }                                                                                                          \
    }

/* 0x2011ECD4 + 0x10 n: the GIC entries of SPTI n and SPRI n: the generic ISRs with the channel [fact] */
#define RSPI_GIC_STUBS(n)                                                                                          \
    void rspi##n##_spti_isr(void)                                                                                  \
    {                                                                                                              \
        rspi_tx_isr(n);                                                                                            \
    }                                                                                                              \
    void rspi##n##_spri_isr(void)                                                                                  \
    {                                                                                                              \
        rspi_rx_isr(n);                                                                                            \
    }

#define RSPI_COMMON(n) RSPI_CLEAR_RX(n) RSPI_CLEAR_TX(n) RSPI_TX_ISR(n) RSPI_TX_WAIT(n) RSPI_WAIT_TEND(n)          \
    RSPI_DELAY(n) RSPI_GIC_STUBS(n)

RSPI_COMMON(0)
RSPI_COMMON(1)
RSPI_COMMON(2)
RSPI_COMMON(3)
RSPI_COMMON(4)
RSPI_RX_ISR_RESET(0)
RSPI_RX_ISR_RESET(1)
RSPI_RX_ISR_MASK(2)
RSPI_RX_ISR_MASK(3)
RSPI_RX_ISR_MASK(4)
