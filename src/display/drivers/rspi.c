/*
 * FT-710 DISPLAY (T24 rounds 6 and 7): the RSPI driver, 0x2011D9A8..0x2011F93F, recreated from the image: the
 * per-channel helpers (round 6) and the driver core (round 7: channel set-up, open, start and stop, the PIO read and
 * write with their read bursts, the generic ISRs and waits).
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

int rspi_rx_isr(unsigned ch);    /* 0x2011F840 */
int rspi_tx_isr(unsigned ch);    /* 0x2011F89C */

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

/* ---- the driver core (round 7) ---- */

#include <stddef.h>
#include "norti.h"

#define CPG_STBCR10 0xFCFE043CU   /* module stop: bit 7 - n = RSPI n [fact: the rspiN_open literals] */

/* the register addresses of one channel, 11 words per channel [fact: 0x20166B4C, the offsets rspi_hw_config loads] */
typedef struct
{
    volatile uint8_t *spcr, *sppcr, *spbr, *spdcr, *spckd, *sslnd, *spnd, *spscr;
    volatile uint16_t *spcmd0;
    volatile uint8_t *spbfcr, *sslp;
} rspi_regaddr_t;

extern const rspi_regaddr_t rspi_regaddr[5];   /* 0x20166B4C */
extern const T_CISR rspi_cisr[5][2];           /* 0x20166A84: per channel SPTI, SPRI */
extern const uint32_t rspi_tx_trigger_bytes[4];   /* 0x20800424: SPBFCR.TXTRG -> bytes {1, 2, 4, 8} */
extern const uint32_t rspi_rx_trigger_bytes[8];   /* 0x20800434: SPBFCR.RXTRG -> bytes {1, 2, 4, 8, 16, 24, 32, 5} */

uint16_t reg_read16(volatile void *addr, uint32_t shift, uint32_t mask);   /* 0x20157184 */

/* register offsets from the channel base [fact: rspi_read 0x2011F2E0 (+0xB), 0x2011F2B8 (+0x20), 0x2011F3EC (+4)] */
#define SPDR 4
#define SPSR 3
#define SPDCR 0xB
#define SPBFCR 0x20
#define SPBFDR 0x22

/* 0x2011D9A8: (ch, mode): program a channel as master (mode 0) or slave (mode 1), SPE left off; 8-bit frames, MSB
 * first, CPOL 0 / CPHA 1, byte access to SPDR (SPDCR.SPLW = 1); master: SPBR 1 and BRDV 3, the SSL and next-access
 * delays on, SSL kept, TX trigger 2 and RX trigger 5, MSTR and SPTIE; slave: TX trigger 3, RX trigger 0, SPTIE and
 * SPRIE. Returns 0, or 0xFF for a mode other than 0/1 and for ch > 5 (ch 5 is accepted and reads past the table: the
 * test is "> 5") [fact: 0x2011D9AC] */
int rspi_hw_config(unsigned ch, unsigned mode)
{
    const rspi_regaddr_t *r;

    if (ch > 5)
    {
        return 0xFF;
    }
    r = &rspi_regaddr[ch];
    if (mode == 0)
    {
        reg_rmw8(r->spcr, 0, 6, 0x40);          /* SPE off */
        reg_rmw8(r->sppcr, 0, 5, 0x20);         /* MOIFE */
        reg_rmw8(r->sppcr, 0, 4, 0x10);         /* MOIFV */
        reg_rmw8(r->sppcr, 0, 0, 1);            /* SPLP: no loopback */
        reg_rmw8(r->spbr, 1, 0, 0xFF);
        reg_rmw8(r->spdcr, 0, 7, 0x80);         /* TXDMY */
        reg_rmw8(r->spdcr, 1, 5, 0x60);         /* SPLW: byte access */
        reg_rmw8(r->spckd, 0, 0, 7);
        reg_rmw8(r->sslnd, 0, 0, 7);
        reg_rmw8(r->spnd, 0, 0, 7);
        reg_rmw8(r->spscr, 0, 0, 3);
        reg_rmw16(r->spcmd0, 1, 15, 0x8000);    /* SCKDEN */
        reg_rmw16(r->spcmd0, 1, 14, 0x4000);    /* SLNDEN */
        reg_rmw16(r->spcmd0, 1, 13, 0x2000);    /* SPNDEN */
        reg_rmw16(r->spcmd0, 0, 12, 0x1000);    /* LSBF */
        reg_rmw16(r->spcmd0, 7, 8, 0xF00);      /* SPB: 8 bits */
        reg_rmw16(r->spcmd0, 1, 7, 0x80);       /* SSLKP */
        reg_rmw16(r->spcmd0, 3, 2, 0xC);        /* BRDV */
        reg_rmw16(r->spcmd0, 0, 1, 2);          /* CPOL */
        reg_rmw16(r->spcmd0, 1, 0, 1);          /* CPHA */
        reg_rmw8(r->spbfcr, 1, 7, 0x80);        /* TXRST */
        reg_rmw8(r->spbfcr, 1, 6, 0x40);        /* RXRST */
        reg_rmw8(r->spbfcr, 2, 4, 0x30);        /* TXTRG */
        reg_rmw8(r->spbfcr, 5, 0, 7);           /* RXTRG */
        reg_rmw8(r->spbfcr, 0, 7, 0x80);
        reg_rmw8(r->spbfcr, 0, 6, 0x40);
        reg_rmw8(r->sslp, 0, 0, 1);             /* SSL0P: active low */
        reg_rmw8(r->spcr, 0, 7, 0x80);          /* SPRIE */
        reg_rmw8(r->spcr, 0, 6, 0x40);          /* SPE */
        reg_rmw8(r->spcr, 1, 5, 0x20);          /* SPTIE */
        reg_rmw8(r->spcr, 1, 3, 8);             /* MSTR */
        reg_rmw8(r->spcr, 0, 2, 4);             /* MODFEN */
        return 0;
    }
    if (mode != 1)
    {
        return 0xFF;
    }
    reg_rmw8(r->spcr, 0, 6, 0x40);
    reg_rmw8(r->sppcr, 0, 5, 0x20);
    reg_rmw8(r->sppcr, 0, 4, 0x10);
    reg_rmw8(r->sppcr, 0, 0, 1);
    reg_rmw8(r->sslp, 0, 0, 1);
    reg_rmw8(r->spdcr, 0, 7, 0x80);
    reg_rmw8(r->spdcr, 1, 5, 0x60);
    reg_rmw16(r->spcmd0, 0, 15, 0x8000);
    reg_rmw16(r->spcmd0, 0, 14, 0x4000);
    reg_rmw16(r->spcmd0, 0, 13, 0x2000);
    reg_rmw16(r->spcmd0, 0, 12, 0x1000);
    reg_rmw16(r->spcmd0, 7, 8, 0xF00);
    reg_rmw16(r->spcmd0, 0, 7, 0x80);
    reg_rmw16(r->spcmd0, 0, 2, 0xC);
    reg_rmw16(r->spcmd0, 0, 1, 2);
    reg_rmw16(r->spcmd0, 1, 0, 1);
    reg_rmw8(r->spbfcr, 1, 7, 0x80);
    reg_rmw8(r->spbfcr, 1, 6, 0x40);
    reg_rmw8(r->spbfcr, 3, 4, 0x30);
    reg_rmw8(r->spbfcr, 0, 0, 7);
    reg_rmw8(r->spbfcr, 0, 7, 0x80);
    reg_rmw8(r->spbfcr, 0, 6, 0x40);
    reg_rmw8(r->spcr, 1, 7, 0x80);              /* SPRIE */
    reg_rmw8(r->spcr, 0, 6, 0x40);
    reg_rmw8(r->spcr, 1, 5, 0x20);              /* SPTIE */
    reg_rmw8(r->spcr, 0, 4, 0x10);              /* SPEIE */
    reg_rmw8(r->spcr, 0, 3, 8);                 /* slave */
    reg_rmw8(r->spcr, 0, 2, 4);
    return 0;
}

/* 0x2011DEA0: an empty function between rspi_hw_config and rspi0_open (bx lr), no caller [fact] */
void rspi_nop_2011dea0(void)
{
}

/* 0x2011DEA4 + 0x7C n (0x2011E09C for 4: ch 3 is 8 bytes longer): module clock on (STBCR10 bit 7 - n, then the
 * dummy read), the SPTI and SPRI ISR objects, the GIC ids SPTI and SPRI (ch 3 also its SPEI 0x117, which has no
 * ISR), then rspi_hw_config: ch 1 as master, the others as slave; 0xFF when an ISR object fails [fact] */
#define RSPI_OPEN_START(n)                                                                                         \
    volatile uint8_t dummy;                                                                                        \
                                                                                                                   \
    reg_rmw8(&REG8(CPG_STBCR10), 0, 7 - (n), 0x80U >> (n));                                                        \
    dummy = REG8(CPG_STBCR10);                                                                                     \
    (void)dummy;                                                                                                   \
    if (itron_acre_isr(0, &rspi_cisr[n][0]) <= 0 || itron_acre_isr(0, &rspi_cisr[n][1]) <= 0)                      \
    {                                                                                                              \
        return 0xFF;                                                                                               \
    }

/* GIC ids: SPEI 0x10E + 3 n, SPRI + 1, SPTI + 2 (R01UH0403EJ0700 Table 7.3) [fact: the gic_enable_irq arguments] */
#define RSPI_OPEN(n, mode)                                                                                         \
    int rspi##n##_open(void)                                                                                       \
    {                                                                                                              \
        RSPI_OPEN_START(n)                                                                                         \
        gic_enable_irq(0x110 + 3 * (n));                                                                           \
        gic_enable_irq(0x10F + 3 * (n));                                                                           \
        return rspi_hw_config(n, mode);                                                                            \
    }

RSPI_OPEN(0, 1)
RSPI_OPEN(1, 0)
RSPI_OPEN(2, 1)
RSPI_OPEN(4, 1)

int rspi3_open(void)
{
    RSPI_OPEN_START(3)
    gic_enable_irq(0x119);
    gic_enable_irq(0x118);
    gic_enable_irq(0x117);
    return rspi_hw_config(3, 1);
}

/* 0x2011EFC8, 0x2011F040: the open of channels 0 and 1 without rspi_hw_config; returns 0; no caller [fact] */
#define RSPI_OPEN_IRQ_ONLY(n)                                                                                      \
    int rspi##n##_open_irq_only(void)                                                                              \
    {                                                                                                              \
        RSPI_OPEN_START(n)                                                                                         \
        gic_enable_irq(0x110 + 3 * (n));                                                                           \
        gic_enable_irq(0x10F + 3 * (n));                                                                           \
        return 0;                                                                                                  \
    }

RSPI_OPEN_IRQ_ONLY(0)
RSPI_OPEN_IRQ_ONLY(1)

/* 0x2011E3FC (ch 0, 2, 4: 328 bytes; 1, 3: 320): (bytes, fewer than the trigger): clock in `bytes` by writing dummy
 * 0xFF words: TX trigger by the access size (SPLW 3: 2, 2: 1, else 0), SPRIE on; per access wait for the transmit
 * interrupt (rspiN_tx_wait) and clear its flag; then, with fewer bytes than the RX trigger, poll SPBFDR.R until they
 * are in and run the receive ISR's part directly, else wait for the receive ISR's flag; restore TXTRG [fact] */
#define RSPI_READ_BURST(n)                                                                                         \
    void rspi##n##_read_burst(uint32_t bytes, int short_read)                                                      \
    {                                                                                                              \
        uint8_t txtrg = reg_read8(RSPI_SPBFCR(n), 4, 0x30);                                                        \
        uint8_t splw = reg_read8(&REG8(RSPI_BASE(n) + SPDCR), 5, 0x60);                                            \
        uint32_t left;                                                                                             \
                                                                                                                   \
        reg_rmw8(RSPI_SPBFCR(n), splw == 3 ? 2 : splw == 2 ? 1 : 0, 4, 0x30);                                      \
        reg_rmw8(RSPI_SPCR(n), 1, 7, 0x80);                                                                        \
        for (left = bytes; left != 0;)                                                                             \
        {                                                                                                          \
            rspi##n##_tx_wait();                                                                                   \
            rspi##n##_clear_tx_flag();                                                                             \
            if (splw == 3)                                                                                         \
            {                                                                                                      \
                REG32(RSPI_BASE(n) + SPDR) = 0xFFFFFFFFU;                                                          \
                left -= 4;                                                                                         \
            }                                                                                                      \
            else if (splw == 2)                                                                                    \
            {                                                                                                      \
                REG16(RSPI_BASE(n) + SPDR) = 0xFFFF;                                                               \
                left -= 2;                                                                                         \
            }                                                                                                      \
            else                                                                                                   \
            {                                                                                                      \
                REG8(RSPI_BASE(n) + SPDR) = 0xFF;                                                                  \
                left -= 1;                                                                                         \
            }                                                                                                      \
        }                                                                                                          \
        if (short_read == 1)                                                                                       \
        {                                                                                                          \
            while (reg_read16(&REG16(RSPI_BASE(n) + SPBFDR), 0, 0x3F) < bytes)                                     \
            {                                                                                                      \
            }                                                                                                      \
            rspi##n##_rx_isr();                                                                                    \
        }                                                                                                          \
        else                                                                                                       \
        {                                                                                                          \
            while (rspi_rx_done[n] == 0)                                                                           \
            {                                                                                                      \
            }                                                                                                      \
        }                                                                                                          \
        reg_rmw8(RSPI_SPBFCR(n), txtrg, 4, 0x30);                                                                  \
    }

RSPI_READ_BURST(0)
RSPI_READ_BURST(1)
RSPI_READ_BURST(2)
RSPI_READ_BURST(3)
RSPI_READ_BURST(4)

/* 0x2011ED24: (ch, SPBR, BRDV, loopback): the master set-up of rspi_hw_config with the bit rate and loopback as
 * parameters, SPCKD 7 and SPRIE on; no argument check, no caller [fact] */
void rspi_hw_config_master(unsigned ch, unsigned spbr, unsigned brdv, unsigned loopback)
{
    const rspi_regaddr_t *r = &rspi_regaddr[ch];

    reg_rmw8(r->spcr, 0, 6, 0x40);
    reg_rmw8(r->sppcr, 0, 5, 0x20);
    reg_rmw8(r->sppcr, 0, 4, 0x10);
    reg_rmw8(r->sppcr, loopback, 0, 1);
    reg_rmw8(r->spbr, spbr, 0, 0xFF);
    reg_rmw8(r->spdcr, 0, 7, 0x80);
    reg_rmw8(r->spdcr, 1, 5, 0x60);
    reg_rmw8(r->spckd, 7, 0, 7);
    reg_rmw8(r->sslnd, 0, 0, 7);
    reg_rmw8(r->spnd, 0, 0, 7);
    reg_rmw8(r->spscr, 0, 0, 3);
    reg_rmw16(r->spcmd0, 1, 15, 0x8000);
    reg_rmw16(r->spcmd0, 1, 14, 0x4000);
    reg_rmw16(r->spcmd0, 1, 13, 0x2000);
    reg_rmw16(r->spcmd0, 0, 12, 0x1000);
    reg_rmw16(r->spcmd0, 7, 8, 0xF00);
    reg_rmw16(r->spcmd0, 1, 7, 0x80);
    reg_rmw16(r->spcmd0, brdv, 2, 0xC);
    reg_rmw16(r->spcmd0, 0, 1, 2);
    reg_rmw16(r->spcmd0, 1, 0, 1);
    reg_rmw8(r->spbfcr, 1, 7, 0x80);
    reg_rmw8(r->spbfcr, 1, 6, 0x40);
    reg_rmw8(r->spbfcr, 3, 4, 0x30);
    reg_rmw8(r->spbfcr, 0, 0, 7);
    reg_rmw8(r->spbfcr, 0, 7, 0x80);
    reg_rmw8(r->spbfcr, 0, 6, 0x40);
    reg_rmw8(r->sslp, 0, 0, 1);
    reg_rmw8(r->spcr, 1, 7, 0x80);
    reg_rmw8(r->spcr, 0, 6, 0x40);
    reg_rmw8(r->spcr, 1, 5, 0x20);
    reg_rmw8(r->spcr, 1, 3, 8);
    reg_rmw8(r->spcr, 0, 2, 4);
}

/* 0x2011F0CC: open channel 0..4; -1 for another [fact] */
int rspi_open(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi0_open(); break;
    case 1: rspi1_open(); break;
    case 2: rspi2_open(); break;
    case 3: rspi3_open(); break;
    case 4: rspi4_open(); break;
    default: return -1;
    }
    return 0;
}

/* 0x2011F128 / 0x2011F19C: SPCR.SPE (bit 6) on / off [fact] */
void rspi_spe_set(volatile uint8_t *spcr)
{
    reg_rmw8(spcr, 1, 6, 0x40);
}

void rspi_spe_clear(volatile uint8_t *spcr)
{
    reg_rmw8(spcr, 0, 6, 0x40);
}

/* 0x2011F138: SPE on for channel 0..4; -1 for another [fact] */
int rspi_start(unsigned ch)
{
    if (ch > 4)
    {
        return -1;
    }
    rspi_spe_set(RSPI_SPCR(ch));
    return 0;
}

/* 0x2011F1AC: SPE off, then the channel's short delay; -1 for a channel above 4 [fact] */
int rspi_stop(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi_spe_clear(RSPI_SPCR(0)); rspi0_delay(); break;
    case 1: rspi_spe_clear(RSPI_SPCR(1)); rspi1_delay(); break;
    case 2: rspi_spe_clear(RSPI_SPCR(2)); rspi2_delay(); break;
    case 3: rspi_spe_clear(RSPI_SPCR(3)); rspi3_delay(); break;
    case 4: rspi_spe_clear(RSPI_SPCR(4)); rspi4_delay(); break;
    default: return -1;
    }
    return 0;
}

/* 0x2011F230: the register base of channel 1..4, else channel 0's [fact] */
uintptr_t rspi_base(unsigned ch)
{
    return ch < 5 ? RSPI_BASE(ch) : RSPI_BASE(0);
}

/* 0x2011F278 (Ghidra: rspi_read; the body behind the checks of 0x2011F494): (ch, buffer, accesses, RX trigger or
 * 0xFF = keep): read `count` SPDR accesses of the SPLW size into the buffer, in bursts of at most the RX trigger's
 * bytes (rspiN_read_burst clocks them in); the trigger must be a multiple of the access size (-1 otherwise); the old
 * RXTRG is restored; returns 0 or -1 [fact] */
int rspi_read_pio(unsigned ch, void *buf, uint32_t count, uint32_t rxtrg)
{
    uint32_t *p32 = NULL;
    uint16_t *p16 = NULL;
    uint8_t *p8 = NULL;
    uint8_t saved = 0;
    uintptr_t base = rspi_base(ch);
    uint32_t unit, trg;
    uint8_t splw;
    int ret;

    if (rxtrg != 0xFF)
    {
        saved = reg_read8(&REG8(base + SPBFCR), 0, 7);
        reg_rmw8(&REG8(base + SPBFCR), rxtrg, 0, 7);
    }
    splw = reg_read8(&REG8(base + SPDCR), 5, 0x60);
    if (splw == 3)
    {
        unit = 4;
        p32 = buf;
    }
    else if (splw == 2)
    {
        unit = 2;
        p16 = buf;
    }
    else
    {
        unit = 1;
        p8 = buf;
    }
    trg = rspi_rx_trigger_bytes[reg_read8(&REG8(base + SPBFCR), 0, 7)];
    if (trg < unit || trg % unit != 0)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
        while (count != 0)
        {
            uint32_t n = count * unit;
            int short_read = n < trg;

            if (!short_read)
            {
                n = trg;
            }
            switch (ch)
            {
            case 0: rspi0_read_burst(n, short_read); break;
            case 1: rspi1_read_burst(n, short_read); break;
            case 2: rspi2_read_burst(n, short_read); break;
            case 3: rspi3_read_burst(n, short_read); break;
            case 4: rspi4_read_burst(n, short_read); break;
            }
            for (; n >= unit; n -= unit, count--)
            {
                if (splw == 3)
                {
                    *p32++ = REG32(base + SPDR);
                }
                else if (splw == 2)
                {
                    *p16++ = REG16(base + SPDR);
                }
                else
                {
                    *p8++ = REG8(base + SPDR);
                }
            }
            switch (ch)
            {
            case 0: rspi0_clear_rx_flag(); break;
            case 1: rspi1_clear_rx_flag(); break;
            case 2: rspi2_clear_rx_flag(); break;
            case 3: rspi3_clear_rx_flag(); break;
            case 4: rspi4_clear_rx_flag(); break;
            }
        }
    }
    if (rxtrg != 0xFF)
    {
        reg_rmw8(&REG8(base + SPBFCR), saved, 0, 7);
    }
    return ret;
}

/* 0x2011F494 (Ghidra: FUN_2011f494): rspi_read(ch, buffer, accesses, RX trigger): -1 for a channel above 4 or a
 * trigger other than 0..7 and 0xFF.., 0 for no access, else rspi_read_pio; no caller [fact] */
int rspi_read(unsigned ch, void *buf, uint32_t count, uint32_t rxtrg)
{
    if (ch >= 5 || rxtrg - 8 < 0xF7)
    {
        return -1;
    }
    if (count == 0)
    {
        return 0;
    }
    return rspi_read_pio(ch, buf, count, rxtrg);
}

/* 0x2011F4D4 (no Ghidra entry: counted into rspi_write): (ch, buffer, accesses, TX trigger or 0xFF = keep): write
 * `count` SPDR accesses of the SPLW size from the buffer; per chunk of at most the TX trigger's bytes wait for the
 * transmit interrupt (rspiN_tx_wait), and after each access read and drop SPDR when SPSR.SPRF is set; restore TXTRG;
 * returns 0 or -1 (trigger not a multiple of the access size) [fact: 0x2011F4D4..0x2011F714] */
int rspi_write_pio(unsigned ch, const void *buf, uint32_t count, uint32_t txtrg)
{
    const uint32_t *p32 = NULL;
    const uint16_t *p16 = NULL;
    const uint8_t *p8 = NULL;
    uint8_t saved = 0;
    uintptr_t base = rspi_base(ch);
    uint32_t unit, trg;
    uint8_t splw;
    int ret;

    if (txtrg != 0xFF)
    {
        saved = reg_read8(&REG8(base + SPBFCR), 4, 0x30);
        reg_rmw8(&REG8(base + SPBFCR), txtrg, 4, 0x30);
    }
    splw = reg_read8(&REG8(base + SPDCR), 5, 0x60);
    if (splw == 3)
    {
        unit = 4;
        p32 = buf;
    }
    else if (splw == 2)
    {
        unit = 2;
        p16 = buf;
    }
    else
    {
        unit = 1;
        p8 = buf;
    }
    trg = rspi_tx_trigger_bytes[reg_read8(&REG8(base + SPBFCR), 4, 0x30)];
    if (trg < unit || trg % unit != 0)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
        while (count != 0)
        {
            uint32_t n;

            switch (ch)
            {
            case 0: rspi0_tx_wait(); break;
            case 1: rspi1_tx_wait(); break;
            case 2: rspi2_tx_wait(); break;
            case 3: rspi3_tx_wait(); break;
            case 4: rspi4_tx_wait(); break;
            }
            n = count * unit < trg ? count * unit : trg;
            for (; n >= unit; n -= unit, count--)
            {
                volatile uint32_t drop;

                if (splw == 3)
                {
                    REG32(base + SPDR) = *p32++;
                }
                else if (splw == 2)
                {
                    REG16(base + SPDR) = *p16++;
                }
                else
                {
                    REG8(base + SPDR) = *p8++;
                }
                if (reg_read8(&REG8(base + SPSR), 7, 0x80) == 1)
                {
                    if (splw == 3)
                    {
                        drop = REG32(base + SPDR);
                    }
                    else if (splw == 2)
                    {
                        drop = REG16(base + SPDR);
                    }
                    else
                    {
                        drop = REG8(base + SPDR);
                    }
                    (void)drop;
                }
            }
            switch (ch)
            {
            case 0: rspi0_clear_tx_flag(); break;
            case 1: rspi1_clear_tx_flag(); break;
            case 2: rspi2_clear_tx_flag(); break;
            case 3: rspi3_clear_tx_flag(); break;
            case 4: rspi4_clear_tx_flag(); break;
            }
        }
    }
    if (txtrg != 0xFF)
    {
        reg_rmw8(&REG8(base + SPBFCR), saved, 4, 0x30);
    }
    return ret;
}

/* 0x2011F718: rspi_write(ch, buffer, accesses, TX trigger): -1 for a channel above 4 or a trigger other than 0..3
 * and 0xFF.., 0 for no access, else rspi_write_pio [fact] */
int rspi_write(unsigned ch, const void *buf, uint32_t count, uint32_t txtrg)
{
    if (ch >= 5 || txtrg - 4 < 0xFB)
    {
        return -1;
    }
    if (count == 0)
    {
        return 0;
    }
    return rspi_write_pio(ch, buf, count, txtrg);
}

/* 0x2011F758: (channel base): pulse TXRST and RXRST (SPBFCR bits 7, 6) [fact] */
void rspi_fifo_reset(uintptr_t base)
{
    reg_rmw8(&REG8(base + SPBFCR), 1, 6, 0x40);
    reg_rmw8(&REG8(base + SPBFCR), 1, 7, 0x80);
    reg_rmw8(&REG8(base + SPBFCR), 0, 6, 0x40);
    reg_rmw8(&REG8(base + SPBFCR), 0, 7, 0x80);
}

/* 0x2011F7B4: clear the channel's receive and transmit flags and empty its buffers; -1 above 4 [fact] */
int rspi_reset_buffers(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi0_clear_rx_flag(); rspi0_clear_tx_flag(); break;
    case 1: rspi1_clear_rx_flag(); rspi1_clear_tx_flag(); break;
    case 2: rspi2_clear_rx_flag(); rspi2_clear_tx_flag(); break;
    case 3: rspi3_clear_rx_flag(); rspi3_clear_tx_flag(); break;
    case 4: rspi4_clear_rx_flag(); rspi4_clear_tx_flag(); break;
    default: return -1;
    }
    rspi_fifo_reset(RSPI_BASE(ch));
    return 0;
}

/* 0x2011F840 / 0x2011F89C: the generic receive / transmit ISRs: the channel's own; -1 above 4 [fact] */
int rspi_rx_isr(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi0_rx_isr(); break;
    case 1: rspi1_rx_isr(); break;
    case 2: rspi2_rx_isr(); break;
    case 3: rspi3_rx_isr(); break;
    case 4: rspi4_rx_isr(); break;
    default: return -1;
    }
    return 0;
}

int rspi_tx_isr(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi0_tx_isr(); break;
    case 1: rspi1_tx_isr(); break;
    case 2: rspi2_tx_isr(); break;
    case 3: rspi3_tx_isr(); break;
    case 4: rspi4_tx_isr(); break;
    default: return -1;
    }
    return 0;
}

/* 0x2011F8F8: wait for TEND on channel 0..4; -1 above 4 [fact] */
int rspi_wait_tx_end(unsigned ch)
{
    switch (ch)
    {
    case 0: rspi0_wait_tend(); break;
    case 1: rspi1_wait_tend(); break;
    case 2: rspi2_wait_tend(); break;
    case 3: rspi3_wait_tend(); break;
    case 4: rspi4_wait_tend(); break;
    default: return -1;
    }
    return 0;
}
