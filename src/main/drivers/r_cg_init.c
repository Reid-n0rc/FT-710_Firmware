/* Pin, interrupt-source and ICU set-up of the MAIN image (Renesas Code Generator r_cg_port.c, r_cg_icu.c and the BSP
 * MPC set-up), recreated for T24. These are straight register sequences: they were transcribed from the decompile
 * (decomp/main/fff92014..fff92e48) into the iodefine.h names, and tools/equiv_main_emu.py checks every access, in
 * order and value, against the image. docs/code/main/peripherals.md has the resulting pin map. */
#include "iodefine.h"
#include "main.h"

void R_BSP_RegisterProtectDisable(int32_t region);    /* 0xFFF8FEC0, bsp.md */
void R_BSP_RegisterProtectEnable(int32_t region);     /* 0xFFF8FE3C */
void FUN_fff9321e(void);    /* 0xFFF9321E: empty, called last by R_Pins_Create (R_Pins_Create_UserInit) [inference] */
void FUN_fff92e48(void);    /* 0xFFF92E48: empty, called last by FUN_fff92e25 */

/* icu_select_init 0xFFF92014: the selectable interrupt sources of vectors 128..207 (ICU SLIBXRn / SLIBRn): e.g.
 * 130 <- 0x0F (TPU0 TGIA0), 144 <- 0x14 (TPU1 TGIA1), 186 <- 0x40 (S12ADI0), 189 <- 0x44 (S12ADI1) [fact] */
void icu_select_init(void)
{
    ICU_SLIBXR128 = 1u;
    ICU_SLIBXR129 = 2u;
    ICU_SLIBR146 = 3u;
    ICU_SLIBR147 = 4u;
    ICU_SLIBR148 = 5u;
    ICU_SLIBR149 = 6u;
    ICU_SLIBR150 = 7u;
    ICU_SLIBR151 = 8u;
    ICU_SLIBR152 = 9u;
    ICU_SLIBR153 = 10u;
    ICU_SLIBR154 = 0xBu;
    ICU_SLIBR155 = 0xCu;
    ICU_SLIBR156 = 0xDu;
    ICU_SLIBR157 = 0xEu;
    ICU_SLIBXR130 = 0xFu;
    ICU_SLIBXR131 = 0x10u;
    ICU_SLIBXR132 = 0x11u;
    ICU_SLIBXR133 = 0x12u;
    ICU_SLIBXR134 = 0x13u;
    ICU_SLIBR144 = 0x14u;
    ICU_SLIBXR135 = 0x15u;
    ICU_SLIBXR136 = 0x16u;
    ICU_SLIBXR137 = 0x17u;
    ICU_SLIBXR138 = 0x18u;
    ICU_SLIBXR139 = 0x19u;
    ICU_SLIBXR140 = 0x1Au;
    ICU_SLIBXR141 = 0x1Bu;
    ICU_SLIBXR142 = 0x1Cu;
    ICU_SLIBXR143 = 0x1Du;
    ICU_SLIBR145 = 0x1Eu;
    ICU_SLIBR158 = 0x1Fu;
    ICU_SLIBR159 = 0x20u;
    ICU_SLIBR160 = 0x21u;
    ICU_SLIBR161 = 0x22u;
    ICU_SLIBR162 = 0x23u;
    ICU_SLIBR163 = 0x24u;
    ICU_SLIBR164 = 0x25u;
    ICU_SLIBR165 = 0x26u;
    ICU_SLIBR166 = 0x27u;
    ICU_SLIBR167 = 0x28u;
    ICU_SLIBR168 = 0x29u;
    ICU_SLIBR169 = 0x2Au;
    ICU_SLIBR170 = 0x2Bu;
    ICU_SLIBR171 = 0x2Cu;
    ICU_SLIBR172 = 0x2Du;
    ICU_SLIBR173 = 0x2Eu;
    ICU_SLIBR174 = 0x2Fu;
    ICU_SLIBR175 = 0x30u;
    ICU_SLIBR176 = 0x31u;
    ICU_SLIBR177 = 0x32u;
    ICU_SLIBR178 = 0x33u;
    ICU_SLIBR179 = 0x34u;
    ICU_SLIBR180 = 0x35u;
    ICU_SLIBR181 = 0x36u;
    ICU_SLIBR182 = 0x37u;
    ICU_SLIBR183 = 0x38u;
    ICU_SLIBR184 = 0x39u;
    ICU_SLIBR185 = 0x3Eu;
    ICU_SLIBR186 = 0x40u;
    ICU_SLIBR187 = 0x41u;
    ICU_SLIBR188 = 0x42u;
    ICU_SLIBR189 = 0x44u;
    ICU_SLIBR190 = 0x45u;
    ICU_SLIBR191 = 0x46u;
    ICU_SLIBR192 = 0x4Cu;
    ICU_SLIBR193 = 0x4Fu;
    ICU_SLIBR194 = 0x50u;
    ICU_SLIBR195 = 0x55u;
    ICU_SLIBR196 = 0x56u;
    ICU_SLIBR197 = 0x57u;
    ICU_SLIBR198 = 0x58u;
    ICU_SLIBR199 = 0x59u;
    ICU_SLIBR200 = 0x5Au;
    ICU_SLIBR201 = 0x5Bu;
    ICU_SLIBR202 = 0x5Cu;
    ICU_SLIBR203 = 0x5Du;
    ICU_SLIBR204 = 0x5Eu;
    ICU_SLIBR205 = 0x5Fu;
    ICU_SLIAR209 = 1u;
    ICU_SLIAR210 = 2u;
    ICU_SLIAR211 = 3u;
    ICU_SLIAR212 = 4u;
    ICU_SLIAR213 = 5u;
    ICU_SLIAR214 = 6u;
    ICU_SLIAR215 = 7u;
    ICU_SLIAR208 = 8u;
    ICU_SLIAR216 = 9u;
    ICU_SLIAR217 = 10u;
    ICU_SLIAR218 = 0xBu;
    ICU_SLIAR219 = 0xCu;
    ICU_SLIAR220 = 0xDu;
    ICU_SLIAR221 = 0xEu;
    ICU_SLIAR222 = 0xFu;
    ICU_SLIAR223 = 0x10u;
    ICU_SLIAR224 = 0x11u;
    ICU_SLIAR225 = 0x12u;
    ICU_SLIAR226 = 0x13u;
    ICU_SLIAR227 = 0x14u;
    ICU_SLIAR228 = 0x15u;
    ICU_SLIAR229 = 0x16u;
    ICU_SLIAR230 = 0x17u;
    ICU_SLIAR231 = 0x18u;
    ICU_SLIAR232 = 0x19u;
    ICU_SLIAR233 = 0x1Bu;
    ICU_SLIAR234 = 0x1Cu;
    ICU_SLIAR235 = 0x1Du;
    ICU_SLIAR236 = 0x1Eu;
    ICU_SLIAR237 = 0x1Fu;
    ICU_SLIAR238 = 0x20u;
    ICU_SLIAR239 = 0x21u;
    ICU_SLIAR240 = 0x22u;
    ICU_SLIAR241 = 0x23u;
    ICU_SLIAR242 = 0x24u;
    ICU_SLIAR243 = 0x25u;
    ICU_SLIAR244 = 0x26u;
    ICU_SLIAR245 = 0x27u;
    ICU_SLIAR246 = 0x29u;
    ICU_SLIAR247 = 0x2Au;
    ICU_SLIAR248 = 0x2Bu;
    ICU_SLIAR249 = 0x2Cu;
    ICU_SLIAR250 = 0x2Du;
    ICU_SLIAR251 = 0x58u;
    ICU_SLIAR252 = 0x59u;
}

/* R_Pins_Create 0xFFF92E49: open-drain, pull-up, drive-strength, mode and direction of P0..PJ */
void R_Pins_Create(void)
{
    PORT0_ODR0 = 0u;
    PORT0_PCR = 0xA4u;
    PORT0_DSCR = 0u;
    PORT0_DSCR2 = 0u;
    PORT0_PMR = 0u;
    PORT0_PDR = 0x50u;
    PORT1_ODR0 = 0u;
    PORT1_PCR = 0u;
    PORT1_DSCR = 0u;
    PORT1_DSCR2 = 0u;
    PORT1_PMR = 0u;
    PORT1_PDR = 3u;
    PORT2_PODR = 0u;
    PORT2_ODR0 = 0u;
    PORT2_ODR1 = 0u;
    PORT2_PCR = 3u;
    PORT2_DSCR = 0xCu;
    PORT2_DSCR2 = 0u;
    PORT2_PMR = 0u;
    PORT2_PDR = 0x14u;
    PORT3_ODR0 = 0u;
    PORT3_ODR1 = 0u;
    PORT3_PCR = 0x12u;
    PORT3_DSCR2 = 0u;
    PORT3_PMR = 0u;
    PORT3_PDR = 0u;
    PORT4_ODR0 = 0u;
    PORT4_ODR1 = 0u;
    PORT4_PCR = 0x11u;
    PORT4_PMR = 0u;
    PORT4_PDR = 0u;
    PORT5_PODR = 0u;
    PORT5_ODR1 = 0u;
    PORT5_PCR = 0x1Eu;
    PORT5_DSCR = 0u;
    PORT5_DSCR2 = 0u;
    PORT5_PMR = 0u;
    PORT5_PDR = 0xC0u;
    PORT6_PODR = 0u;
    PORT6_ODR0 = 0u;
    PORT6_ODR1 = 0u;
    PORT6_PCR = 0x17u;
    PORT6_PMR = 0u;
    PORT6_PDR = 0xE8u;
    PORT7_PODR = 0x40u;
    PORT7_ODR0 = 4u;
    PORT7_ODR1 = 0u;
    PORT7_PCR = 0u;
    PORT7_DSCR = 9u;
    PORT7_DSCR2 = 0u;
    PORT7_PMR = 0u;
    PORT7_PDR = 0xDFu;
    PORT8_PODR = 0x40u;
    PORT8_ODR0 = 0u;
    PORT8_ODR1 = 0u;
    PORT8_PCR = 0u;
    PORT8_DSCR = 0u;
    PORT8_DSCR2 = 0u;
    PORT8_PMR = 0u;
    PORT8_PDR = 0x7Fu;
    PORT9_ODR0 = 0u;
    PORT9_DSCR = 0u;
    PORT9_DSCR2 = 0u;
    PORTA_PODR = 0u;
    PORTA_ODR0 = 0u;
    PORTA_ODR1 = 0u;
    PORTA_PCR = 8u;
    PORTA_DSCR = 0u;
    PORTA_DSCR2 = 0u;
    PORTA_PMR = 0u;
    PORTA_PDR = 0xF7u;
    PORTB_PODR = 0u;
    PORTB_ODR0 = 0u;
    PORTB_ODR1 = 0u;
    PORTB_DSCR = 0u;
    PORTB_DSCR2 = 0u;
    PORTB_PMR = 0u;
    PORTB_PDR = 0xFCu;
    PORTC_PODR = 0x10u;
    PORTC_ODR0 = 0u;
    PORTC_ODR1 = 0u;
    PORTC_PCR = 2u;
    PORTC_DSCR = 0u;
    PORTC_DSCR2 = 0u;
    PORTC_PMR = 0u;
    PORTC_PDR = 0x11u;
    PORTD_PODR = 0u;
    PORTD_ODR0 = 0u;
    PORTD_ODR1 = 0u;
    PORTD_DSCR = 0u;
    PORTD_DSCR2 = 0u;
    PORTD_PMR = 0u;
    PORTD_PDR = 0xFCu;
    PORTE_PODR = 0u;
    PORTE_ODR0 = 0u;
    PORTE_ODR1 = 0u;
    PORTE_PCR = 8u;
    PORTE_DSCR = 0u;
    PORTE_DSCR2 = 0u;
    PORTE_PMR = 0u;
    PORTE_PDR = 0x77u;
    PORTF_PCR = 0x20u;
    PORTF_PMR = 0u;
    PORTF_PDR = 0xDFu;
    PORTJ_PODR = 0u;
    PORTJ_ODR0 = 0u;
    PORTJ_PCR = 0x20u;
    PORTJ_PMR = 0u;
    PORTJ_PDR = 0xDFu;
    FUN_fff9321e();
}

/* mpc_pin_functions_init 0xFFF92475: analog inputs (PFS = 0x80) and SCI pin functions, with the MPC write
 * protection off (region 3) around them; no caller in V01-12 [fact: bsp.md] */
void mpc_pin_functions_init(void)
{
    R_BSP_RegisterProtectDisable(3);
    MPC_P41PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xFDu;
    PORT4_PDR = PORT4_PDR & 0xFDu;
    MPC_P42PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xFBu;
    PORT4_PDR = PORT4_PDR & 0xFBu;
    MPC_P43PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xF7u;
    PORT4_PDR = PORT4_PDR & 0xF7u;
    MPC_P45PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xDFu;
    PORT4_PDR = PORT4_PDR & 0xDFu;
    MPC_P46PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xBFu;
    PORT4_PDR = PORT4_PDR & 0xBFu;
    MPC_P47PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0x7Fu;
    PORT4_PDR = PORT4_PDR & 0x7Fu;
    MPC_PD0PFS = 0x80u;
    PORTD_PMR = PORTD_PMR & 0xFEu;
    PORTD_PDR = PORTD_PDR & 0xFEu;
    MPC_PD1PFS = 0x80u;
    PORTD_PMR = PORTD_PMR & 0xFDu;
    PORTD_PDR = PORTD_PDR & 0xFDu;
    MPC_P91PFS = 0x80u;
    PORT9_PMR = PORT9_PMR & 0xFDu;
    PORT9_PDR = PORT9_PDR & 0xFDu;
    MPC_P93PFS = 0x80u;
    PORT9_PMR = PORT9_PMR & 0xF7u;
    PORT9_PDR = PORT9_PDR & 0xF7u;
    MPC_P03PFS = 0x80u;
    PORT0_PMR = PORT0_PMR & 0xF7u;
    PORT0_PDR = PORT0_PDR & 0xF7u;
    MPC_P27PFS = 1u;
    PORT2_PMR = PORT2_PMR | 0x80u;
    MPC_P33PFS = 0xBu;
    PORT3_PMR = PORT3_PMR | 8u;
    MPC_P30PFS = 10u;
    PORT3_PMR = PORT3_PMR | 1u;
    MPC_P12PFS = 10u;
    PORT1_PMR = PORT1_PMR | 4u;
    MPC_P25PFS = 10u;
    PORT2_PMR = PORT2_PMR | 0x20u;
    MPC_PB0PFS = 10u;
    PORTB_PMR = PORTB_PMR | 1u;
    MPC_PC2PFS = 10u;
    PORTC_PMR = PORTC_PMR | 4u;
    MPC_P92PFS = 10u;
    PORT9_PMR = PORT9_PMR | 4u;
    MPC_P01PFS = 10u;
    PORT0_PMR = PORT0_PMR | 2u;
    MPC_P00PFS = 10u;
    PORT0_PMR = PORT0_PMR | 1u;
    PORT3_PODR = PORT3_PODR | 4u;
    MPC_P32PFS = 0xBu;
    PORT3_PDR = PORT3_PDR | 4u;
    PORT2_PODR = PORT2_PODR | 0x40u;
    MPC_P26PFS = 10u;
    PORT2_PDR = PORT2_PDR | 0x40u;
    PORT1_PODR = PORT1_PODR | 8u;
    MPC_P13PFS = 10u;
    PORT1_PDR = PORT1_PDR | 8u;
    PORT2_PODR = PORT2_PODR | 8u;
    MPC_P23PFS = 10u;
    PORT2_PDR = PORT2_PDR | 8u;
    PORTB_PODR = PORTB_PODR | 2u;
    MPC_PB1PFS = 10u;
    PORTB_PDR = PORTB_PDR | 2u;
    PORTC_PODR = PORTC_PODR | 8u;
    MPC_PC3PFS = 10u;
    PORTC_PDR = PORTC_PDR | 8u;
    PORT9_PODR = PORT9_PODR | 1u;
    MPC_P90PFS = 10u;
    PORT9_PDR = PORT9_PDR | 1u;
    R_BSP_RegisterProtectEnable(3);
}

/* FUN_fff92e25 0xFFF92E25: IRQ0..15 (IER08, IER09) and vectors 26/27 (IER03 bits 2, 3) disabled, then an empty
 * user hook: the shape of the Code Generator's R_ICU_Create [inference: register set and order; no other ICU
 * set-up function exists] */
void FUN_fff92e25(void)
{
    ICU_IER08 = 0u;
    ICU_IER09 = 0u;
    ICU_IER03 = ICU_IER03 & 0xF7u;
    ICU_IER03 = ICU_IER03 & 0xFBu;
    FUN_fff92e48();
}
