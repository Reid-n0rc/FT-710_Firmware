/*
 * FT-710 DISPLAY (T24 round 4): the RIIC (I2C) driver, 0x2011F970..0x20120D37, recreated from the image.
 *
 * It is the Renesas RZ/A1H sample driver (riic.c with the per-channel riic_userdef.c) [inference: the same call
 * structure, the per-channel flag bytes and the mode arguments; docs/code/display/peripherals.md]. Only channel 2 is
 * used at run time, by the TSC2007 touch controller task (docs/code/display/input.md). The interrupts only set
 * flags; the transfer functions spin on them.
 *
 * Registers (RZ/A1H manual chapter 28; tools/ghidra/sfr_rza1h.tsv): RIICn at 0xFCFEE000 + 0x400 n; ICCR1 +0x00,
 * ICCR2 +0x04, ICMR1 +0x08, ICMR3 +0x10, ICFER +0x14, ICIER +0x1C, ICSR2 +0x24, ICBRL +0x34, ICBRH +0x38,
 * ICDRT +0x3C, ICDRR +0x40.
 */
#include "display.h"
#include "norti.h"

#define RIIC_CH_TOTAL 4
#define ICCR2 0x04
#define ICMR3 0x10
#define ICSR2 0x24
#define ICDRT 0x3C
#define ICDRR 0x40

/* the per-channel flags the interrupts set (.data2) [fact: the userdef functions below] */
extern volatile uint8_t riic_rx_full[RIIC_CH_TOTAL];     /* 0x20800454 */
extern volatile uint8_t riic_tx_empty[RIIC_CH_TOTAL];    /* 0x20800458 */
extern volatile uint8_t riic_tx_end[RIIC_CH_TOTAL];      /* 0x2080045C */
extern volatile uint8_t riic2_tx_count;                  /* 0x20800462 */

/* per-channel register pointers {ICCR1, ICMR1, ICBRL, ICBRH, ICMR3, ICFER, ICIER, ICCR2, ICSR2} [fact: 0x20166D18] */
typedef struct
{
    volatile uint8_t *cr1, *mr1, *brl, *brh, *mr3, *fer, *ier, *cr2, *sr2;
} riic_regs_t;
extern const riic_regs_t riic_reg_table[RIIC_CH_TOTAL];  /* 0x20166D18 */
/* the RI, TI and TEI interrupt descriptors of each channel [fact: 0x20166C28 + 0x3C ch] */
extern const T_CISR riic_cisr[RIIC_CH_TOTAL][3];          /* 0x20166C28 */

void *riic_base(int ch);
void riic_port_init(unsigned ch);
void riic_regs_init(unsigned ch);
int R_RIIC_RiInterrupt(unsigned ch);
int R_RIIC_TiInterrupt(unsigned ch);
int R_RIIC_TeiInterrupt(unsigned ch);

/* 0x2011F970: (ch 0..3): module reset (ICE off, IICRST on, ICE on), ICMR1.CKS = 3, ICBRL 14, ICBRH 16, ICMR3 NF = 3,
 * ICFER NACKE and SCLE, ICIER TIE, RIE, TEIE... then IICRST off [fact: the stores] */
void riic_regs_init(unsigned ch)
{
    const riic_regs_t *r;

    if (ch >= RIIC_CH_TOTAL)
    {
        return;
    }
    r = &riic_reg_table[ch];
    reg_rmw8(r->cr1, 0, 7, 0x80);     /* ICE = 0 */
    reg_rmw8(r->cr1, 1, 6, 0x40);     /* IICRST = 1 */
    reg_rmw8(r->cr1, 1, 7, 0x80);     /* ICE = 1 */
    reg_rmw8(r->mr1, 3, 4, 0x70);     /* CKS: P0 / 8 */
    reg_rmw8(r->brl, 0xE, 0, 0x1F);
    reg_rmw8(r->brh, 0x10, 0, 0x1F);
    reg_rmw8(r->mr3, 3, 0, 3);        /* noise filter stages */
    reg_rmw8(r->fer, 1, 4, 0x10);     /* NACKE */
    reg_rmw8(r->fer, 1, 5, 0x20);     /* NFE */
    reg_rmw8(r->ier, 1, 5, 0x20);     /* RIE */
    reg_rmw8(r->ier, 1, 7, 0x80);     /* TIE */
    reg_rmw8(r->ier, 1, 6, 0x40);     /* TEIE */
    reg_rmw8(r->cr1, 0, 6, 0x40);     /* IICRST = 0 */
}

/* one pin of port 1 to alternative function 1, bidirectional (the sample's port set-up sequence) */
#define P1_ALT1(bit)                                                       \
    do                                                                     \
    {                                                                      \
        reg_rmw16(&REG16(0xFCFE7004U), 0, (bit), 1U << (bit)); /* PIBC1 */ \
        reg_rmw16(&REG16(0xFCFE7104U), 0, (bit), 1U << (bit)); /* PBDC1 */ \
        reg_rmw16(&REG16(0xFCFE3304U), 1, (bit), 1U << (bit)); /* PM1 */   \
        reg_rmw16(&REG16(0xFCFE3404U), 0, (bit), 1U << (bit)); /* PMC1 */  \
        reg_rmw16(&REG16(0xFCFE7204U), 0, (bit), 1U << (bit)); /* PIPC1 */ \
        reg_rmw16(&REG16(0xFCFE7104U), 1, (bit), 1U << (bit)); /* PBDC1 */ \
        reg_rmw16(&REG16(0xFCFE3504U), 0, (bit), 1U << (bit)); /* PFC1 */  \
        reg_rmw16(&REG16(0xFCFE3604U), 0, (bit), 1U << (bit)); /* PFCE1 */ \
        reg_rmw16(&REG16(0xFCFE3A04U), 0, (bit), 1U << (bit)); /* PFCAE1 */\
        reg_rmw16(&REG16(0xFCFE7204U), 1, (bit), 1U << (bit)); /* PIPC1 */ \
        reg_rmw16(&REG16(0xFCFE3404U), 1, (bit), 1U << (bit)); /* PMC1 */  \
    } while (0)

/* 0x2011FA90: (ch 0..3): P1_0 and P1_1 (RIIC0 SCL0/SDA0 on the RZ/A1H [inference: alternative function 1 of
 * P1_0/P1_1]) for every channel 0..3 alike; only ch 0 and 1 call it [fact] */
void riic_port_init(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return;
    }
    P1_ALT1(0);
    P1_ALT1(1);
}

/* 0x2011FC8C..0x2011FEBB: channel open: module clock on (STBCR9 bit 7 - ch, then the dummy read the manual asks
 * for), pins (ch 0 and 1), registers, the three interrupts (ISR objects, then the GIC ids TI, RI, TEI) [fact] */
#define RIIC_USERDEF_INIT(n, pins, ti, ri, tei)                                    \
    void userdef_riic##n##_init(void)                                              \
    {                                                                              \
        volatile uint8_t dummy;                                                    \
                                                                                   \
        reg_rmw8(&REG8(CPG_STBCR9), 0, 7 - (n), 0x80U >> (n));                     \
        dummy = REG8(CPG_STBCR9);                                                  \
        (void)dummy;                                                               \
        if (pins)                                                                  \
        {                                                                          \
            riic_port_init(n);                                                     \
        }                                                                          \
        riic_regs_init(n);                                                         \
        if (itron_acre_isr(0, &riic_cisr[n][0]) > 0 && itron_acre_isr(0, &riic_cisr[n][1]) > 0 && \
            itron_acre_isr(0, &riic_cisr[n][2]) > 0)                               \
        {                                                                          \
            gic_enable_irq(ti);                                                    \
            gic_enable_irq(ri);                                                    \
            gic_enable_irq(tei);                                                   \
        }                                                                          \
    }
RIIC_USERDEF_INIT(0, 1, 0xBF, 0xBE, 0xBD)
RIIC_USERDEF_INIT(1, 1, 0xC7, 0xC6, 0xC5)
RIIC_USERDEF_INIT(2, 0, 0xCF, 0xCE, 0xCD)
RIIC_USERDEF_INIT(3, 0, 0xD7, 0xD6, 0xD5)

/* 0x2011FEBC..0x20120223: the flag functions of riic_userdef.c, one set per channel: clear, set (from the
 * interrupts) and spin until set. init_tx_end and wait_tx_end take the mode: 0 = transmit end, 1 = receive full. */
#define RIIC_USERDEF_FLAGS(n)                                                                    \
    void userdef_riic##n##_init_rx_full(void) { riic_rx_full[n] = 0; }                           \
    void userdef_riic##n##_init_tx_empty(void) { riic_tx_empty[n] = 0; }                         \
    void userdef_riic##n##_init_tx_end(int mode) { (mode == 0 ? riic_tx_end : riic_rx_full)[n] = 0; } \
    void userdef_riic##n##_set_rx_full(void) { riic_rx_full[n] = 1; }                            \
    void userdef_riic##n##_set_tx_end(void) { riic_tx_end[n] = 1; }                              \
    void userdef_riic##n##_wait_rx_full(void) { while (riic_rx_full[n] == 0) { } }               \
    void userdef_riic##n##_wait_tx_empty(void) { while (riic_tx_empty[n] == 0) { } }             \
    void userdef_riic##n##_wait_tx_end(int mode)                                                 \
    {                                                                                            \
        if (mode == 0)                                                                           \
        {                                                                                        \
            while (riic_tx_end[n] == 0) { }                                                      \
            return;                                                                              \
        }                                                                                        \
        while (riic_rx_full[n] == 0) { }                                                         \
    }
RIIC_USERDEF_FLAGS(0)
RIIC_USERDEF_FLAGS(1)
RIIC_USERDEF_FLAGS(2)
RIIC_USERDEF_FLAGS(3)

void userdef_riic0_set_tx_empty(void) { riic_tx_empty[0] = 1; }
void userdef_riic1_set_tx_empty(void) { riic_tx_empty[1] = 1; }
/* 0x2011FFFC: channel 2 also counts its transmit-empty interrupts (Yaesu's addition; read by task_tsc2007_irq through
 * userdef_riic2_tx_count) [fact] */
void userdef_riic2_set_tx_empty(void)
{
    riic_tx_empty[2] = 1;
    riic2_tx_count++;
}
/* 0x2012001C */
uint8_t userdef_riic2_tx_count(void) { return riic2_tx_count; }
void userdef_riic3_set_tx_empty(void) { riic_tx_empty[3] = 1; }

/* 0x20120224..0x201203D3: spin on ICCR2.BBSY (bit 7) until set (mode 1: bus taken) or clear (mode 0: bus free),
 * and on ICSR2.STOP (bit 3) [fact] */
#define RIIC_USERDEF_BUS(n)                                                      \
    void userdef_riic##n##_wait_bus_master(int mode)                             \
    {                                                                            \
        volatile uint8_t *cr2 = &REG8(0xFCFEE004U + 0x400U * (n));               \
                                                                                 \
        if (mode != 0)                                                           \
        {                                                                        \
            while (reg_read8(cr2, 7, 0x80) == 0) { }                             \
            return;                                                              \
        }                                                                        \
        while (reg_read8(cr2, 7, 0x80) == 1) { }                                 \
    }                                                                            \
    void userdef_riic##n##_wait_stop(void)                                       \
    {                                                                            \
        while (reg_read8(&REG8(0xFCFEE024U + 0x400U * (n)), 3, 8) == 0) { }      \
    }
RIIC_USERDEF_BUS(0)
RIIC_USERDEF_BUS(1)
RIIC_USERDEF_BUS(2)
RIIC_USERDEF_BUS(3)

/* 0x201203D4..0x20120433: the interrupt entries created by userdef_riicN_init */
void riic0_ri_isr(void) { R_RIIC_RiInterrupt(0); }
void riic0_ti_isr(void) { R_RIIC_TiInterrupt(0); }
void riic0_tei_isr(void) { R_RIIC_TeiInterrupt(0); }
void riic1_ri_isr(void) { R_RIIC_RiInterrupt(1); }
void riic1_ti_isr(void) { R_RIIC_TiInterrupt(1); }
void riic1_tei_isr(void) { R_RIIC_TeiInterrupt(1); }
void riic2_ri_isr(void) { R_RIIC_RiInterrupt(2); }
void riic2_ti_isr(void) { R_RIIC_TiInterrupt(2); }
void riic2_tei_isr(void) { R_RIIC_TeiInterrupt(2); }
void riic3_ri_isr(void) { R_RIIC_RiInterrupt(3); }
void riic3_ti_isr(void) { R_RIIC_TiInterrupt(3); }
void riic3_tei_isr(void) { R_RIIC_TeiInterrupt(3); }

/* 0x20120454: open a channel; -1 for ch > 3 [fact] */
int R_RIIC_Init(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (ch == 0)
    {
        userdef_riic0_init();
    }
    else if (ch == 1)
    {
        userdef_riic1_init();
    }
    else if (ch == 2)
    {
        userdef_riic2_init();
    }
    else if (ch == 3)
    {
        userdef_riic3_init();
    }
    return 0;
}

/* 0x201204A4: register base of a channel (0xFCFEE000 for any other value) [fact] */
void *riic_base(int ch)
{
    if (ch == 1)
    {
        return (void *)0xFCFEE400U;
    }
    if (ch == 2)
    {
        return (void *)0xFCFEE800U;
    }
    if (ch == 3)
    {
        return (void *)0xFCFEEC00U;
    }
    return (void *)0xFCFEE000U;
}

/* 0x201204D4: stop condition: clear ICSR2.STOP, set ICCR2.SP [fact] */
void riic_transmit_stop(int ch)
{
    volatile uint8_t *b = riic_base(ch);

    reg_rmw8(b + ICSR2, 0, 3, 8);
    reg_rmw8(b + ICCR2, 1, 3, 8);
}

/* the flag set-up before a start or restart condition: wait for the bus state, clear the three flags */
static inline void riic_prepare(int ch, int busy)
{
    if (ch == 0)
    {
        userdef_riic0_wait_bus_master(busy);
        userdef_riic0_init_rx_full();
        userdef_riic0_init_tx_empty();
        userdef_riic0_init_tx_end(0);
    }
    else if (ch == 1)
    {
        userdef_riic1_wait_bus_master(busy);
        userdef_riic1_init_rx_full();
        userdef_riic1_init_tx_empty();
        userdef_riic1_init_tx_end(0);
    }
    else if (ch == 2)
    {
        userdef_riic2_wait_bus_master(busy);
        userdef_riic2_init_rx_full();
        userdef_riic2_init_tx_empty();
        userdef_riic2_init_tx_end(0);
    }
    else if (ch == 3)
    {
        userdef_riic3_wait_bus_master(busy);
        userdef_riic3_init_rx_full();
        userdef_riic3_init_tx_empty();
        userdef_riic3_init_tx_end(0);
    }
}

/* 0x2012050C: restart condition (bus taken): ICCR2.RS [fact] */
void riic_transmit_restart(int ch)
{
    riic_prepare(ch, 1);
    reg_rmw8((volatile uint8_t *)riic_base(ch) + ICCR2, 1, 2, 4);
}

/* 0x201205C0: start condition (bus free): ICCR2.ST [fact] */
void riic_transmit_start(int ch)
{
    riic_prepare(ch, 0);
    reg_rmw8((volatile uint8_t *)riic_base(ch) + ICCR2, 1, 1, 2);
}

/* 0x20120674: (ch, cond): 0 start, 1 restart, 2 stop; -1 for a bad argument [fact] */
int R_RIIC_SendCond(unsigned ch, unsigned cond)
{
    if (ch >= RIIC_CH_TOTAL || cond >= 3)
    {
        return -1;
    }
    if (cond == 0)
    {
        riic_transmit_start(ch);
    }
    else if (cond == 1)
    {
        riic_transmit_restart(ch);
    }
    else if (cond == 2)
    {
        riic_transmit_stop(ch);
    }
    return 0;
}

/* 0x201206C0: (ch, byte): -2 if the last byte was not acknowledged (ICSR2.NACKF), else wait for transmit-empty,
 * clear it, write ICDRT [fact] */
int riic_transmit(int ch, uint8_t data)
{
    volatile uint8_t *b = riic_base(ch);

    if (reg_read8(b + ICSR2, 4, 0x10) != 0)
    {
        return -2;
    }
    if (ch == 0)
    {
        userdef_riic0_wait_tx_empty();
        userdef_riic0_init_tx_empty();
    }
    else if (ch == 1)
    {
        userdef_riic1_wait_tx_empty();
        userdef_riic1_init_tx_empty();
    }
    else if (ch == 2)
    {
        userdef_riic2_wait_tx_empty();
        userdef_riic2_init_tx_empty();
    }
    else if (ch == 3)
    {
        userdef_riic3_wait_tx_empty();
        userdef_riic3_init_tx_empty();
    }
    b[ICDRT] = data;
    return 0;
}

/* wait for and clear the transmit-end (mode 0) or receive-full (mode 1) flag of a channel */
static inline void riic_wait_end(int ch, int mode)
{
    if (ch == 0)
    {
        userdef_riic0_wait_tx_end(mode);
        userdef_riic0_init_tx_end(mode);
    }
    else if (ch == 1)
    {
        userdef_riic1_wait_tx_end(mode);
        userdef_riic1_init_tx_end(mode);
    }
    else if (ch == 2)
    {
        userdef_riic2_wait_tx_end(mode);
        userdef_riic2_init_tx_end(mode);
    }
    else if (ch == 3)
    {
        userdef_riic3_wait_tx_end(mode);
        userdef_riic3_init_tx_end(mode);
    }
}

/* 0x20120750: (ch, address byte, mode): send the slave address, wait for transmit end (mode 0, write) or receive
 * full (mode 1, read); -2 on NACK, -1 for a bad argument [fact] */
int R_RIIC_WriteSlaveAddr(unsigned ch, uint8_t addr, unsigned mode)
{
    int ret;

    if (ch >= RIIC_CH_TOTAL || mode >= 2)
    {
        return -1;
    }
    ret = riic_transmit(ch, addr);
    if (ret != 0)
    {
        return ret;
    }
    riic_wait_end(ch, mode);
    if (reg_read8((volatile uint8_t *)riic_base(ch) + ICSR2, 4, 0x10) != 0)
    {
        ret = -2;
    }
    return ret;
}

/* 0x2012081C: (ch, buf, n): send n bytes, wait for transmit end; -2 on NACK [fact] */
int R_RIIC_Write(unsigned ch, const uint8_t *buf, unsigned n)
{
    int ret;

    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    for (unsigned i = 0; i < n; i++)
    {
        ret = riic_transmit(ch, buf[i]);
        if (ret != 0)
        {
            return ret;
        }
    }
    riic_wait_end(ch, 0);
    return reg_read8((volatile uint8_t *)riic_base(ch) + ICSR2, 4, 0x10) != 0 ? -2 : 0;
}

/* 0x20120904: (register base): clear ICSR2.NACKF [fact] */
void riic_clear_nack(volatile uint8_t *base)
{
    reg_rmw8(base + ICSR2, 0, 4, 0x10);
}

/* 0x20120918: wait for the stop condition, then clear NACKF and STOP [fact] */
void riic_detect_stop(int ch)
{
    volatile uint8_t *b;

    if (ch == 0)
    {
        userdef_riic0_wait_stop();
    }
    else if (ch == 1)
    {
        userdef_riic1_wait_stop();
    }
    else if (ch == 2)
    {
        userdef_riic2_wait_stop();
    }
    else if (ch == 3)
    {
        userdef_riic3_wait_stop();
    }
    b = riic_base(ch);
    riic_clear_nack(b);
    reg_rmw8(b + ICSR2, 0, 3, 8);
}

/* 0x2012097C: (ch, mode, *out): wait for and clear receive-full, prepare the acknowledge of the next byte through
 * ICMR3 (1: ACKWP + ACKBT = 0, 2: WAIT, 3: ACKWP + ACKBT = 1 (NACK), 4: stop condition), then read ICDRR [fact] */
void riic_receive(int ch, unsigned mode, uint8_t *out)
{
    volatile uint8_t *b;

    if (ch == 0)
    {
        userdef_riic0_wait_rx_full();
        userdef_riic0_init_rx_full();
    }
    else if (ch == 1)
    {
        userdef_riic1_wait_rx_full();
        userdef_riic1_init_rx_full();
    }
    else if (ch == 2)
    {
        userdef_riic2_wait_rx_full();
        userdef_riic2_init_rx_full();
    }
    else if (ch == 3)
    {
        userdef_riic3_wait_rx_full();
        userdef_riic3_init_rx_full();
    }
    b = riic_base(ch);
    switch (mode)
    {
    case 1:
        reg_rmw8(b + ICMR3, 1, 4, 0x10);
        reg_rmw8(b + ICMR3, 0, 3, 8);
        break;
    case 2:
        reg_rmw8(b + ICMR3, 1, 6, 0x40);
        break;
    case 3:
        reg_rmw8(b + ICMR3, 1, 4, 0x10);
        reg_rmw8(b + ICMR3, 1, 3, 8);
        break;
    case 4:
        riic_transmit_stop(ch);
        break;
    default:
        break;
    }
    *out = b[ICDRR];
}

/* 0x20120A88: dummy read of ICDRR (starts the reception) [fact: ldrb r0, [r0, #0x40]; strb r0, [sp]] */
void riic_receive_dummy(unsigned ch)
{
    volatile uint8_t dummy = ((volatile uint8_t *)riic_base(ch))[ICDRR];

    (void)dummy;
}

/* 0x20120A9C: (ch, buf, n): read n bytes: dummy read, n - 3 bytes acknowledged, then WAIT, NACK and the stop
 * condition on the last three, ICMR3.WAIT off, wait for the stop [fact] */
int R_RIIC_Read(unsigned ch, uint8_t *buf, unsigned n)
{
    volatile uint8_t *b;

    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    b = riic_base(ch);
    if (n == 1)
    {
        reg_rmw8(b + ICMR3, 1, 6, 0x40);
        reg_rmw8(b + ICMR3, 1, 4, 0x10);
        reg_rmw8(b + ICMR3, 1, 3, 8);
    }
    riic_receive_dummy(ch);
    if (n != 1)
    {
        if (n != 2)
        {
            for (; n > 3; n--)
            {
                riic_receive(ch, 0, buf++);
            }
            riic_receive(ch, 2, buf++);
        }
        riic_receive(ch, 3, buf++);
    }
    riic_receive(ch, 4, buf);
    reg_rmw8(b + ICMR3, 0, 6, 0x40);
    riic_detect_stop(ch);
    return 0;
}

/* 0x20120BAC, 0x20120BC8, 0x20120BE4: the public wrappers; -1 for ch > 3 [fact] */
int R_RIIC_ReadDummy(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    riic_receive_dummy(ch);
    return 0;
}

int R_RIIC_DetectStop(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    riic_detect_stop(ch);
    return 0;
}

int R_RIIC_ClearNack(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    riic_clear_nack(riic_base(ch));
    return 0;
}

/* 0x20120C04, 0x20120C54: receive-full and transmit-empty interrupts: set the channel's flag [fact] */
int R_RIIC_RiInterrupt(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (ch == 0)
    {
        userdef_riic0_set_rx_full();
    }
    else if (ch == 1)
    {
        userdef_riic1_set_rx_full();
    }
    else if (ch == 2)
    {
        userdef_riic2_set_rx_full();
    }
    else if (ch == 3)
    {
        userdef_riic3_set_rx_full();
    }
    return 0;
}

int R_RIIC_TiInterrupt(unsigned ch)
{
    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (ch == 0)
    {
        userdef_riic0_set_tx_empty();
    }
    else if (ch == 1)
    {
        userdef_riic1_set_tx_empty();
    }
    else if (ch == 2)
    {
        userdef_riic2_set_tx_empty();
    }
    else if (ch == 3)
    {
        userdef_riic3_set_tx_empty();
    }
    return 0;
}

/* 0x20120CB0: transmit-end interrupt: set the flag, clear ICSR2.TEND and read it back [fact] */
int R_RIIC_TeiInterrupt(unsigned ch)
{
    volatile uint8_t *b;

    if (ch >= RIIC_CH_TOTAL)
    {
        return -1;
    }
    if (ch == 0)
    {
        userdef_riic0_set_tx_end();
    }
    else if (ch == 1)
    {
        userdef_riic1_set_tx_end();
    }
    else if (ch == 2)
    {
        userdef_riic2_set_tx_end();
    }
    else if (ch == 3)
    {
        userdef_riic3_set_tx_end();
    }
    b = riic_base(ch);
    reg_rmw8(b + ICSR2, 0, 6, 0x40);
    reg_read8(b + ICSR2, 6, 0x40);
    return 0;
}
