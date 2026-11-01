/*
 * FT-710 DISPLAY (T24): declarations shared by the recreated drivers. Functions declared here and not defined in
 * src/display are the image's own: the check (tools/equiv_display_emu.py) and the hybrid link (display.ld,
 * tools/display_link.py) resolve them to their original addresses from decomp/display/functions.tsv.
 */
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define REG8(a) (*(volatile uint8_t *)(uintptr_t)(a))
#define REG16(a) (*(volatile uint16_t *)(uintptr_t)(a))
#define REG32(a) (*(volatile uint32_t *)(uintptr_t)(a))

/* the image's register helpers (0x20157138..0x20157183, A32): *addr = (*addr & ~mask) | value << shift, and
 * (*addr & mask) >> shift [fact: 0x20157138, 0x20157174]. The drivers call them like the Renesas sample code's
 * RZA_IO_RegWrite_8 / RZA_IO_RegRead_8 (same argument order) [inference]. */
void reg_rmw8(volatile void *addr, uint32_t value, uint32_t shift, uint32_t mask);
void reg_rmw16(volatile void *addr, uint32_t value, uint32_t shift, uint32_t mask);
void reg_rmw32(volatile void *addr, uint32_t value, uint32_t shift, uint32_t mask);
uint8_t reg_read8(volatile void *addr, uint32_t shift, uint32_t mask);

void gic_enable_irq(int id);                       /* 0x2011775C */

/* CPG standby control (RZ/A1H manual chapter 55): module stop bits, 1 = stopped */
#define CPG_STBCR9 0xFCFE0438U

#endif
