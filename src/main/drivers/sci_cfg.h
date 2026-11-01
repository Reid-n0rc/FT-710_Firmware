/* SCI0..SCI5 channel description shared by r_cg_sci.c and r_cg_sci_user.c (T24, MAIN).
 *
 * The image has one Renesas Code Generator driver per channel (docs/code/main/sci.md): the same code six times with
 * other registers, interrupt bits and pins. Here the code is written once, as always-inline helpers over a constant
 * channel description; GCC folds the description into each public R_SCIn_* function, so each still touches only
 * its own channel's registers, in the image's order. The values of every field are [fact] from the functions named
 * in the comments (decomp/main/fff927a9_fff93846.c, fff9384b_fff94850.c). */
#ifndef SCI_CFG_H
#define SCI_CFG_H

#include <stdint.h>
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"
#include "r_cg_sci.h"

#define INLINE static inline __attribute__((always_inline))

/* SCI registers by offset from the channel base 0x8A000 + 0x20 * n (RX651 HWM r01uh0590 Table 5.1) */
#define SCI_SMR(c)   SFR8((c)->base + 0x00u)
#define SCI_BRR(c)   SFR8((c)->base + 0x01u)
#define SCI_SCR(c)   SFR8((c)->base + 0x02u)
#define SCI_TDR(c)   SFR8((c)->base + 0x03u)
#define SCI_SSR(c)   SFR8((c)->base + 0x04u)
#define SCI_RDR(c)   SFR8((c)->base + 0x05u)
#define SCI_SCMR(c)  SFR8((c)->base + 0x06u)
#define SCI_SEMR(c)  SFR8((c)->base + 0x07u)
#define SCI_SIMR1(c) SFR8((c)->base + 0x09u)
#define SCI_SPMR(c)  SFR8((c)->base + 0x0Du)

/* SCR bits */
#define SCR_TIE  0x80u
#define SCR_RIE  0x40u
#define SCR_TE   0x20u
#define SCR_RE   0x10u
#define SCR_TEIE 0x04u

typedef struct {
    uintptr_t base;          /* SCIn register block */
    uint32_t mstp;           /* SYSTEM.MSTPCRB bit of the module */
    uintptr_t ipr_rxi, ipr_txi;  /* ICU.IPR of RXIn and TXIn (vector numbers 58 + 2n for n < 3, 80 + 2(n-3)) */
    uint8_t ipr_keep, ipr_set;   /* IPR = (IPR & keep) | set: priority 8 (SCI0/2/3) or 10 (SCI1/4/5) */
    uint8_t smr, semr, brr;      /* SCMR is 0x72 on every channel */
    uintptr_t rxd_pfs;           /* MPC PFS of the RXD pin; RXD goes to peripheral mode in Create */
    uintptr_t rxd_pmr; uint8_t rxd_bit;
    uintptr_t txd_pfs;           /* MPC PFS of the TXD pin; TXD is a GPIO output high until a send */
    uint8_t pfs_val;             /* PSEL value of both pins */
    uintptr_t txd_podr, txd_pdr, txd_pmr; uint8_t txd_bit;
    uintptr_t ir_rxi, ir_txi;    /* ICU.IR of RXIn, TXIn */
    uintptr_t ier; uint8_t ier_rxi, ier_txi;   /* ICU.IER byte and the RXIn, TXIn enable bits */
    uint32_t genbl0_tei, genbl0_eri;           /* ICU.GENBL0 bits of TEIn and ERIn (group BL0) */
    uint16_t *tx_count; uint8_t **tx_address;  /* driver state (main_ram.h) */
    uint16_t *rx_count; uint16_t *rx_length; uint8_t **rx_address;
} sci_cfg_t;

#define SCI_STATE(n) &g_sci##n##_tx_count, &gp_sci##n##_tx_address, &g_sci##n##_rx_count, &g_sci##n##_rx_length, \
                     &gp_sci##n##_rx_address

/* SCI0: CP2105 "Standard" CAT, P33 RXD0 / P32 TXD0, vectors 58/59 (R_SCI0_Create 0xFFF9321F, R_SCI0_Start 0xFFF932C2) */
static const sci_cfg_t SCI0_CFG = {0x8A000u, 0x80000000u, 0x8733Au, 0x8733Bu, 0xF8u, 0x08u, 0x01u, 0x10u, 0xC2u,
    0x8C15Bu, 0x8C063u, 0x08u, 0x8C15Au, 0x0Bu, 0x8C023u, 0x8C003u, 0x8C063u, 0x04u,
    0x8703Au, 0x8703Bu, 0x87207u, 0x04u, 0x08u, 0x001u, 0x002u, SCI_STATE(0)};
/* SCI1: DISPLAY link, P30 RXD1 / P26 TXD1, vectors 60/61 (R_SCI1_Create 0xFFF9354E, R_SCI1_Start 0xFFF935EF) */
static const sci_cfg_t SCI1_CFG = {0x8A020u, 0x40000000u, 0x8733Cu, 0x8733Du, 0xFAu, 0x0Au, 0x08u, 0x10u, 0x0Au,
    0x8C158u, 0x8C063u, 0x01u, 0x8C156u, 0x0Au, 0x8C022u, 0x8C002u, 0x8C062u, 0x40u,
    0x8703Cu, 0x8703Du, 0x87207u, 0x10u, 0x20u, 0x004u, 0x008u, SCI_STATE(1)};
/* SCI2: TUNER/LINEAR jack, P12 RXD2 / P13 TXD2, vectors 62/63 (R_SCI2_Create 0xFFF93A86, R_SCI2_Start 0xFFF93B29) */
static const sci_cfg_t SCI2_CFG = {0x8A040u, 0x20000000u, 0x8733Eu, 0x8733Fu, 0xF8u, 0x08u, 0x01u, 0x10u, 0xC2u,
    0x8C14Au, 0x8C061u, 0x04u, 0x8C14Bu, 0x0Au, 0x8C021u, 0x8C001u, 0x8C061u, 0x08u,
    0x8703Eu, 0x8703Fu, 0x87207u, 0x40u, 0x80u, 0x010u, 0x020u, SCI_STATE(2)};
/* SCI3: CP2105 "Enhanced" CAT, P25 RXD3 / P23 TXD3, vectors 80/81 (R_SCI3_Create 0xFFF93F0D, R_SCI3_Start 0xFFF93FB0) */
static const sci_cfg_t SCI3_CFG = {0x8A060u, 0x10000000u, 0x87350u, 0x87351u, 0xF8u, 0x08u, 0x00u, 0x50u, 0xC2u,
    0x8C155u, 0x8C062u, 0x20u, 0x8C153u, 0x0Au, 0x8C022u, 0x8C002u, 0x8C062u, 0x08u,
    0x87050u, 0x87051u, 0x8720Au, 0x01u, 0x02u, 0x040u, 0x080u, SCI_STATE(3)};
/* SCI4: IF DSP (RT685), PB0 RXD4 / PB1 TXD4, vectors 82/83 (R_SCI4_Create 0xFFF9423C, R_SCI4_Start 0xFFF942DF) */
static const sci_cfg_t SCI4_CFG = {0x8A080u, 0x08000000u, 0x87352u, 0x87353u, 0xFAu, 0x0Au, 0x00u, 0x50u, 0x40u,
    0x8C198u, 0x8C06Bu, 0x01u, 0x8C199u, 0x0Au, 0x8C02Bu, 0x8C00Bu, 0x8C06Bu, 0x02u,
    0x87052u, 0x87053u, 0x8720Au, 0x04u, 0x08u, 0x100u, 0x200u, SCI_STATE(4)};
/* SCI5: SDR FPGA link, PC2 RXD5 / PC3 TXD5, vectors 84/85 (R_SCI5_Create 0xFFF94662, R_SCI5_Start 0xFFF94705) */
static const sci_cfg_t SCI5_CFG = {0x8A0A0u, 0x04000000u, 0x87354u, 0x87355u, 0xFAu, 0x0Au, 0x00u, 0x50u, 0x40u,
    0x8C1A2u, 0x8C06Cu, 0x04u, 0x8C1A3u, 0x0Au, 0x8C02Cu, 0x8C00Cu, 0x8C06Cu, 0x08u,
    0x87054u, 0x87055u, 0x8720Au, 0x10u, 0x20u, 0x400u, 0x800u, SCI_STATE(5)};

#endif
