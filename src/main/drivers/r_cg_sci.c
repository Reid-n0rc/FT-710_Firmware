/* SCI0..SCI5 asynchronous drivers of the MAIN image (Renesas Code Generator r_cg_sci.c style), recreated for T24.
 *
 * docs/code/main/sci.md describes the channels; the function names are the image's Ghidra names. Every function is
 * the image's sequence of register accesses, in the image's order and widths (checked by tools/equiv_main_emu.py:
 * the order and values of all peripheral accesses are compared). SCI6 (simple I2C) and SCI7 (never started) are not
 * recreated yet. */
#include "sci_cfg.h"

/* R_SCIn_Create: module on, interrupt priorities, the channel registers (SCR off twice, as the image does), the pins.
 * [fact: R_SCI0_Create 0xFFF9321F and the other five, same sequence] */
INLINE void sci_create(const sci_cfg_t *c)
{
    SYSTEM_MSTPCRB &= ~c->mstp;
    SFR8(c->ipr_rxi) = (uint8_t)((SFR8(c->ipr_rxi) & c->ipr_keep) | c->ipr_set);
    SFR8(c->ipr_txi) = (uint8_t)((SFR8(c->ipr_txi) & c->ipr_keep) | c->ipr_set);
    SCI_SCR(c) = 0x00u;
    SCI_SCR(c) = 0x00u;
    SCI_SIMR1(c) &= 0xFEu;          /* IICM = 0: not simple I2C */
    SCI_SPMR(c) = 0x00u;
    SCI_SMR(c) = c->smr;
    SCI_SCMR(c) = 0x72u;
    SCI_SEMR(c) = c->semr;
    SCI_BRR(c) = c->brr;
    SFR8(c->rxd_pfs) = c->pfs_val;  /* RXD: peripheral function now */
    SFR8(c->rxd_pmr) |= c->rxd_bit;
    SFR8(c->txd_pfs) = c->pfs_val;  /* TXD: GPIO output, high, until R_SCIn_Serial_Send */
    SFR8(c->txd_podr) |= c->txd_bit;
    SFR8(c->txd_pdr) |= c->txd_bit;
}

/* R_SCIn_Start: clear the pending TXI/RXI requests, enable TXI, TEI, RXI, ERI [fact: R_SCI0_Start 0xFFF932C2] */
INLINE void sci_start(const sci_cfg_t *c)
{
    SFR8(c->ir_txi) &= 0xFEu;
    SFR8(c->ir_rxi) &= 0xFEu;
    SFR8(c->ier) |= c->ier_txi;
    ICU_GENBL0 |= c->genbl0_tei;
    SFR8(c->ier) |= c->ier_rxi;
    ICU_GENBL0 |= c->genbl0_eri;
}

/* R_SCIn_Stop: TXD back to GPIO, transmitter and receiver off, all four interrupts off [fact: R_SCI0_Stop 0xFFF93302] */
INLINE void sci_stop(const sci_cfg_t *c)
{
    SFR8(c->txd_pmr) &= (uint8_t)~c->txd_bit;
    SCI_SCR(c) &= (uint8_t)~SCR_TE;
    SCI_SCR(c) &= (uint8_t)~SCR_RE;
    SCI_SCR(c) &= (uint8_t)~SCR_TIE;
    SCI_SCR(c) &= (uint8_t)~SCR_RIE;
    SFR8(c->ier) &= (uint8_t)~c->ier_txi;
    ICU_GENBL0 &= ~c->genbl0_tei;
    SFR8(c->ir_txi) &= 0xFEu;
    SFR8(c->ier) &= (uint8_t)~c->ier_rxi;
    ICU_GENBL0 &= ~c->genbl0_eri;
    SFR8(c->ir_rxi) &= 0xFEu;
}

/* R_SCIn_Serial_Receive: arm a receive of rx_num bytes into rx_buf [fact: R_SCI0_Serial_Receive 0xFFF9336A] */
INLINE MD_STATUS sci_receive(const sci_cfg_t *c, uint8_t *rx_buf, uint16_t rx_num)
{
    if (rx_num == 0u)
        return MD_ARGERROR;
    *c->rx_count = 0u;
    SCI_SCR(c) |= SCR_RIE;
    SCI_SCR(c) |= SCR_RE;
    *c->rx_length = rx_num;
    *c->rx_address = rx_buf;
    return MD_OK;
}

/* R_SCIn_Serial_Send: start sending tx_num bytes; MD_ERROR while TXI is disabled (a send in progress)
 * [fact: R_SCI0_Serial_Send 0xFFF933AE; SCI2's 0xFFF93C15 tests the same bit 7 with a signed compare] */
INLINE MD_STATUS sci_send(const sci_cfg_t *c, uint8_t *tx_buf, uint16_t tx_num)
{
    if (tx_num == 0u)
        return MD_ARGERROR;
    if ((SFR8(c->ier) & c->ier_txi) == 0u)
        return MD_ERROR;
    SFR8(c->ier) &= (uint8_t)~c->ier_txi;
    SCI_SCR(c) |= SCR_TIE | SCR_TE;
    SFR8(c->txd_pmr) |= c->txd_bit;     /* TXD to the SCI */
    SFR8(c->ier) |= c->ier_txi;
    *c->tx_count = tx_num;
    *c->tx_address = tx_buf;
    return MD_OK;
}

/* The Code Generator's empty user hooks [fact: one rts each, docs/code/main/sci.md] */
void R_SCI0_Create_UserInit(void) {}
void R_SCI1_Create_UserInit(void) {}
void R_SCI2_Create_UserInit(void) {}
void R_SCI3_Create_UserInit(void) {}
void R_SCI4_Create_UserInit(void) {}
void R_SCI5_Create_UserInit(void) {}

#define SCI_API(n)                                                                                                    \
    void R_SCI##n##_Create(void) { sci_create(&SCI##n##_CFG); R_SCI##n##_Create_UserInit(); }                         \
    void R_SCI##n##_Start(void) { sci_start(&SCI##n##_CFG); }                                                         \
    void R_SCI##n##_Stop(void) { sci_stop(&SCI##n##_CFG); }                                                           \
    MD_STATUS R_SCI##n##_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num)                                             \
    { return sci_receive(&SCI##n##_CFG, rx_buf, rx_num); }                                                            \
    MD_STATUS R_SCI##n##_Serial_Send(uint8_t *tx_buf, uint16_t tx_num)                                                \
    { return sci_send(&SCI##n##_CFG, tx_buf, tx_num); }

SCI_API(0)
SCI_API(1)
SCI_API(2)
SCI_API(3)
SCI_API(4)
SCI_API(5)
