/*
 * FT-710 DISPLAY (T24 round 4): the SCIF UART driver (C++ class "uart" of the image, written here as C with the
 * object as first argument), 0x20162DD8..0x20163663 and the per-channel entries 0x20114850..0x20114957, recreated
 * from the image. SCIF5 is the MAIN link (docs/code/display/mainlink.md); SCIF3 and SCIF4 have objects but are not
 * opened at run time [fact: mainlink.md section 10].
 *
 * Each object has a 1 KB RX ring filled by the RXI interrupt and a 1 KB TX ring drained by the TXI interrupt (TIE is
 * set by scif_write and cleared by the TXI handler when the ring is empty). After each received byte the RX
 * interrupt is masked in the GIC and the object's event flag is set; scif_read unmasks it again, so the reader
 * task paces the interrupts [fact: scif_rxi_isr 0x20162EA8, scif_read 0x2016308C].
 */
#include "display.h"
#include "norti.h"
#include "scif.h"

void gic_disable_irq(int id);                    /* 0x201177A0 */

#define RING 0x400U

/* SCIF register blocks (RZ/A1H manual chapter 58) and the RXI/TXI interrupt descriptors in .rodata */
#define SCIF3_REGS ((volatile scif_regs_t *)0xE8008800U)
#define SCIF4_REGS ((volatile scif_regs_t *)0xE8009000U)
#define SCIF5_REGS ((volatile scif_regs_t *)0xE8009800U)
extern const T_CISR cisr_scif3_rxi_isr, cisr_scif3_txi_isr, cisr_scif4_rxi_isr, cisr_scif4_txi_isr,
    cisr_scif5_rxi_isr, cisr_scif5_txi_isr;
extern const void *const uart_vtbl[];            /* 0x2042803C */

static inline void dmb_oshst(void)
{
    __asm__ volatile("dmb oshst" ::: "memory");
}

/* 0x20114850: (stamp): delta = PMCCNTR - last, last = PMCCNTR; returns delta [fact: mrc p15, 0, r0, c9, c13, 0] */
__attribute__((noinline)) uint32_t pmu_cycle_stamp(cyc_stamp_t *s)   /* out of line, as the image calls it */
{
    volatile uint32_t now;

    __asm__ volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(now));
    s->delta = now - s->last;
    s->last = now;
    return s->delta;
}

/* 0x20114884..0x201148B3: the six interrupt entries of the three objects */
void scif3_rxi_isr(void) { scif_rxi_isr(&scif3_uart); }
void scif3_txi_isr(void) { scif_txi_isr(&scif3_uart); }
void scif4_rxi_isr(void) { scif_rxi_isr(&scif4_uart); }
void scif4_txi_isr(void) { scif_txi_isr(&scif4_uart); }
void scif5_rxi_isr(void) { scif_rxi_isr(&scif5_uart); }
void scif5_txi_isr(void) { scif_txi_isr(&scif5_uart); }

/* 0x201148B4, 0x201148D8, 0x201148FC: bind the object to its channel (once) and to the caller's event flag */
scif_uart_t *scif5_get(ID flg)
{
    uart_obj_init(&scif5_uart, SCIF5_REGS, &cisr_scif5_rxi_isr, &cisr_scif5_txi_isr, flg);
    return &scif5_uart;
}

scif_uart_t *scif4_get(ID flg)
{
    uart_obj_init(&scif4_uart, SCIF4_REGS, &cisr_scif4_rxi_isr, &cisr_scif4_txi_isr, flg);
    return &scif4_uart;
}

scif_uart_t *scif3_get(ID flg)
{
    uart_obj_init(&scif3_uart, SCIF3_REGS, &cisr_scif3_rxi_isr, &cisr_scif3_txi_isr, flg);
    return &scif3_uart;
}

/* 0x20114920, 0x2011492C: RXI counters for the debug overlay */
uint32_t scif5_rxi_count_get(void) { return scif5_uart.rxi_count; }
uint32_t scif4_rxi_count_get(void) { return scif4_uart.rxi_count; }

void uart_obj_ctor(scif_uart_t *u);

/* 0x20114938: static constructor of the three objects (run by __cpp_initialize__aeabi_) [fact] */
void scif_uarts_ctor(void)
{
    uart_obj_ctor(&scif3_uart);
    uart_obj_ctor(&scif4_uart);
    uart_obj_ctor(&scif5_uart);
}

/* 0x20162DD8: RXI: count; count an error status (any SCFSR bit but RDF, TDFE, TEND); if a byte is there, store it
 * in the ring (or drop it with a dummy read when the ring is full), clear RDF, mask the RX interrupt if a reader
 * waits on the flag, set the flag, time-stamp [fact] */
void scif_rxi_isr(scif_uart_t *u)
{
    volatile scif_regs_t *r;
    int full;

    u->rxi_count++;
    r = u->regs;
    if ((r->scfsr & ~0x62U) != 0)
    {
        u->rx_errors++;
    }
    if ((r->scfsr & 2) == 0)
    {
        u->rxi_no_data++;
        return;
    }
    if (u->rx_rd <= u->rx_wr)
    {
        full = (int)(u->rx_wr - u->rx_rd) >= (int)(RING - 1);
    }
    else
    {
        full = (int)(u->rx_rd - u->rx_wr) <= 1;
    }
    if (full)
    {
        volatile uint8_t dummy = r->scfrdr;

        (void)dummy;
        r->scfsr &= ~2U;
        u->rx_count++;
        u->rx_overflow++;
        return;
    }
    u->rx_buf[u->rx_wr] = r->scfrdr;
    dmb_oshst();
    u->rx_wr = (uint16_t)((u->rx_wr + 1) & (RING - 1));
    u->regs->scfsr &= ~2U;
    if (u->rx_flg != 0)
    {
        gic_disable_irq(u->rxi_isr->intno);
    }
    itron_set_flg(u->rx_flg, 1);
    u->rx_count++;
    pmu_cycle_stamp(&u->rx_time);
}

/* 0x20162F10: TXI: if the FIFO has room (TDFE), send the next ring byte and clear TDFE and TEND; if the ring is
 * empty, turn TIE off [fact] */
void scif_txi_isr(scif_uart_t *u)
{
    volatile scif_regs_t *r;

    u->txi_count++;
    r = u->regs;
    if ((r->scfsr & 0x20) == 0)
    {
        u->txi_not_ready++;
        return;
    }
    if (u->tx_rd == u->tx_wr)
    {
        r->scscr &= ~0x80U;
        return;
    }
    r->scftdr = u->tx_buf[u->tx_rd];
    dmb_oshst();
    u->tx_rd = (uint16_t)((u->tx_rd + 1) & (RING - 1));
    u->regs->scfsr &= ~0x60U;
    u->tx_count++;
    pmu_cycle_stamp(&u->tx_time);
}

/* 0x20162FAC (vtable slot 0): first call binds the registers and descriptors and creates the TXI and RXI ISR
 * objects (-1 if either fails); later calls only change the event flag [fact] */
int uart_obj_init(scif_uart_t *u, volatile scif_regs_t *regs, const T_CISR *rxi, const T_CISR *txi, ID flg)
{
    if (u->regs != 0)
    {
        u->rx_flg = flg;
        return 0;
    }
    u->regs = regs;
    u->rx_flg = flg;
    u->rxi_isr = rxi;
    u->txi_isr = txi;
    if (itron_acre_isr(0, txi) < 1 || itron_acre_isr(0, u->rxi_isr) < 1)
    {
        return -1;
    }
    return 0;
}

/* 0x20163014 (slot 2): mask both interrupts in the GIC */
void scif_irq_off(scif_uart_t *u)
{
    gic_disable_irq(u->txi_isr->intno);
    gic_disable_irq(u->rxi_isr->intno);
}

/* 0x20163038 (slot 4): copy up to n bytes out of the RX ring, then unmask the RX interrupt; returns the count */
int scif_read(scif_uart_t *u, uint8_t *buf, int n)
{
    int got = 0;

    while (n-- != 0 && u->rx_wr != u->rx_rd)
    {
        *buf++ = u->rx_buf[u->rx_rd];
        dmb_oshst();
        u->rx_rd = (uint16_t)((u->rx_rd + 1) & (RING - 1));
        got++;
    }
    gic_enable_irq(u->rxi_isr->intno);
    return got;
}

/* 0x20163098 (slot 1): open and unmask TXI and RXI */
void scif_start(scif_uart_t *u, uint32_t baud, int bits, int parity, uint32_t stop)
{
    scif_open(u, baud, bits, parity, stop);
    gic_enable_irq(u->txi_isr->intno);
    gic_enable_irq(u->rxi_isr->intno);
}

/* 0x201630CC: (baud, bits, parity, stop): SCSMR CHR (7 bits), PE/O/E (parity 1 = even, 2 = odd), STOP (2 stop bits
 * unless stop == 1); SCBRR = 64 MHz / (32 baud) - 1, or 0x16 with SCEMR BGDM + ABCS from 345600 baud up (the MAIN
 * link: 64 MHz / (8 x 23) = 347826 baud, +0.6 %) [inference: the P1 clock of 64 MHz from the divisor]; resets the
 * rings, the counters and both FIFOs (stop bit 7 also sets loop-back) and enables TE, RE, RIE, TIE, REIE [fact] */
void scif_open(scif_uart_t *u, uint32_t baud, int bits, int parity, uint32_t stop)
{
    uint16_t smr = 0;
    uint8_t brr;

    if (bits == 7)
    {
        smr = 0x40;
    }
    if (parity == 1)
    {
        smr |= 0x20;
    }
    else if (parity == 2)
    {
        smr |= 0x30;
    }
    if (stop != 1)
    {
        smr |= 8;
    }
    brr = baud < 345600U ? (uint8_t)(64000000U / (baud << 5) - 1) : 0x16;
    u->rx_wr = 0;
    u->rx_rd = 0;
    u->tx_wr = 0;
    u->tx_rd = 0;
    u->rxi_count = 0;
    u->rx_count = 0;
    u->rx_errors = 0;
    u->rxi_no_data = 0;
    u->txi_count = 0;
    u->tx_count = 0;
    u->txi_not_ready = 0;
    u->regs->scscr = 0;
    u->regs->scfcr |= 6;
    u->regs->scfsr &= ~0x91U;
    (void)u->regs->sclsr;            /* ORER is cleared by reading it first */
    u->regs->sclsr = 0;
    u->regs->scscr = 0;
    u->regs->scsmr = smr;
    u->regs->scbrr = brr;
    if (baud < 345600U)
    {
        u->regs->scemr = 0;
    }
    else
    {
        u->regs->scemr |= 0x81;
    }
    if (stop & 0x80)
    {
        u->regs->scfcr |= 1;
    }
    u->regs->scfcr &= ~6U;
    u->regs->scscr |= 0xF8;
}

/* 0x20163218 (slot 6): read exactly n bytes through the object's read method, retrying every 1 ms; -1 after more
 * than tries attempts [fact] */
int scif_read_timeout(scif_uart_t *u, uint8_t *buf, int n, int tries)
{
    int got = 0;

    for (int i = 1;; i++)
    {
        got += ((int (*)(scif_uart_t *, uint8_t *, int))u->vtbl[4])(u, buf + got, n - got);
        if (got == n)
        {
            return n;
        }
        if (i > tries)
        {
            return -1;
        }
        itron_dly_tsk(1);
    }
}

/* 0x20163280: empty both rings with the interrupts masked [fact] */
int scif_flush(scif_uart_t *u)
{
    gic_disable_irq(u->txi_isr->intno);
    gic_disable_irq(u->rxi_isr->intno);
    u->rx_wr = 0;
    u->rx_rd = 0;
    u->tx_wr = 0;
    u->tx_rd = 0;
    gic_enable_irq(u->txi_isr->intno);
    gic_enable_irq(u->rxi_isr->intno);
    return 0;
}

/* 0x201632D8 (slot 9): all n bytes into the TX ring and TIE on, or nothing (returns 0) if they do not fit [fact] */
int scif_write(scif_uart_t *u, const uint8_t *buf, uint32_t n)
{
    uint32_t wr = u->tx_wr, rd = u->tx_rd;
    uint32_t room = wr >= rd ? (RING - 1) - (wr - rd) : rd - wr - 1;

    if (room < n)
    {
        return 0;
    }
    for (uint32_t k = n; k != 0; k--)
    {
        u->tx_buf[wr] = *buf++;
        wr = (wr + 1) & (RING - 1);
    }
    u->tx_wr = (uint16_t)wr;
    dmb_oshst();
    u->regs->scscr |= 0x80;
    return (int)n;
}

/* 0x20163360: C++ constructor: the vtable */
void uart_obj_ctor(scif_uart_t *u)
{
    u->vtbl = uart_vtbl;
}

/* 0x20163654 (slot 3): is an event flag bound? */
int scif_has_flag(scif_uart_t *u)
{
    return u->rx_flg != 0;
}
