/*
 * FT-710 DISPLAY (T24): the SCIF UART object (layouts from tools/ghidra/structs_display.h, where each field has its
 * evidence). One object per channel: SCIF3 0x208DA1E0, SCIF4 0x208DAA30, SCIF5 0x208DB280 (the MAIN link).
 */
#ifndef SCIF_H
#define SCIF_H

#include <stdint.h>
#include "norti.h"

typedef struct
{
    uint16_t scsmr;          /* +0x00 serial mode */
    uint16_t _r02;
    uint8_t scbrr;           /* +0x04 bit rate */
    uint8_t _r05[3];
    uint16_t scscr;          /* +0x08 serial control: 0x80 TIE, 0x40 RIE, 0x20 TE, 0x10 RE, 0x08 REIE */
    uint16_t _r0a;
    uint8_t scftdr;          /* +0x0C transmit FIFO data */
    uint8_t _r0d[3];
    uint16_t scfsr;          /* +0x10 status: bit 1 RDF, bit 5 TDFE, bit 6 TEND */
    uint16_t _r12;
    uint8_t scfrdr;          /* +0x14 receive FIFO data */
    uint8_t _r15[3];
    uint16_t scfcr;          /* +0x18 FIFO control: bit 0 LOOP, bits 1..2 RFRST/TFRST */
    uint16_t _r1a;
    uint16_t scfdr;          /* +0x1C FIFO data count */
    uint16_t _r1e;
    uint16_t scsptr;         /* +0x20 serial port */
    uint16_t _r22;
    uint16_t sclsr;          /* +0x24 line status (ORER) */
    uint16_t _r26;
    uint16_t scemr;          /* +0x28 extension mode: 0x81 = BGDM + ABCS (double-speed baud generator) */
} scif_regs_t;

typedef struct
{
    uint32_t delta;          /* cycles since the previous event */
    uint32_t last;           /* PMCCNTR at the previous event */
} cyc_stamp_t;

typedef struct scif_uart
{
    const void *const *vtbl;           /* +0x000 C++ vtable 0x2042803C (uart_obj_ctor) */
    volatile scif_regs_t *regs;        /* +0x004 register block, set once by uart_obj_init */
    volatile uint16_t rx_rd;           /* +0x008 RX ring read index (mod 0x400) */
    volatile uint16_t rx_wr;           /* +0x00A RX ring write index */
    uint8_t rx_buf[1024];              /* +0x00C */
    volatile uint16_t tx_rd;           /* +0x40C */
    volatile uint16_t tx_wr;           /* +0x40E */
    uint8_t tx_buf[1024];              /* +0x410 */
    const T_CISR *rxi_isr;             /* +0x810 RXI interrupt descriptor */
    const T_CISR *txi_isr;             /* +0x814 TXI interrupt descriptor */
    ID rx_flg;                         /* +0x818 event flag set (bit 0) per received byte, 0 = none */
    uint32_t rxi_count;                /* +0x81C RXI interrupts */
    uint32_t rx_count;                 /* +0x820 bytes received or dropped */
    uint32_t rx_overflow;              /* +0x824 bytes dropped: ring full */
    uint32_t rx_errors;                /* +0x828 RXI with an error bit in SCFSR */
    uint32_t rxi_no_data;              /* +0x82C RXI without RDF */
    uint32_t txi_count;                /* +0x830 TXI interrupts */
    uint32_t tx_count;                 /* +0x834 bytes sent */
    uint32_t txi_not_ready;            /* +0x838 TXI without TDFE */
    uint32_t _r83c;
    cyc_stamp_t rx_time;               /* +0x840 cycles between received bytes */
    cyc_stamp_t tx_time;               /* +0x848 cycles between sent bytes */
} scif_uart_t;

extern scif_uart_t scif3_uart, scif4_uart, scif5_uart;

int uart_obj_init(scif_uart_t *u, volatile scif_regs_t *regs, const T_CISR *rxi, const T_CISR *txi, ID flg);
void scif_open(scif_uart_t *u, uint32_t baud, int bits, int parity, uint32_t stop);
int scif_read(scif_uart_t *u, uint8_t *buf, int n);
int scif_write(scif_uart_t *u, const uint8_t *buf, uint32_t n);
void scif_rxi_isr(scif_uart_t *u);
void scif_txi_isr(scif_uart_t *u);

#endif
