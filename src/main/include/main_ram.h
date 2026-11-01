/* RAM variables of the MAIN image that the recreated source uses (T24). Each one is placed at its original address
 * by src/main/data_symbols.tsv (linker symbols), so the recreated functions read and write the image's own state.
 * The names of the driver variables are the Renesas Code Generator's (gp_sciN_tx_address, g_sciN_tx_count, ...)
 * [inference: the r_cg_sci function names and the layout, count / pointer per direction]. */
#ifndef MAIN_RAM_H
#define MAIN_RAM_H

#include <stdint.h>

/* SCI driver state, docs/code/main/sci.md "Per-channel callbacks and hooks" [fact: the addresses in
 * R_SCIn_Serial_Send / _Receive and the ISRs] */
#define SCI_STATE(n)                                                                                                  \
    extern uint16_t g_sci##n##_tx_count;       /* bytes left to send */                                              \
    extern uint8_t *gp_sci##n##_tx_address;    /* next byte to send */                                               \
    extern uint16_t g_sci##n##_rx_count;       /* bytes received */                                                  \
    extern uint16_t g_sci##n##_rx_length;      /* bytes to receive */                                                \
    extern uint8_t *gp_sci##n##_rx_address;    /* where the next byte goes */
SCI_STATE(0)
SCI_STATE(1)
SCI_STATE(2)
SCI_STATE(3)
SCI_STATE(4)
SCI_STATE(5)
#undef SCI_STATE

/* C library heap (docs/code/main/bsp.md "Data structures and globals") */
extern uint8_t *heap_break;               /* sbrk's current end of the heap */

#endif
