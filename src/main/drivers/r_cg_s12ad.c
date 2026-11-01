/* S12AD unit 0 and unit 1 (12-bit A/D) drivers of the MAIN image (Renesas Code Generator r_cg_s12ad.c), recreated for
 * T24. Create is a straight register sequence transcribed from the decompile; Get_ValueResult and the scan-end
 * handlers from the disassembly. Unit 0 scans AN001..AN003, AN005..AN007, unit 1 the supply, power and key inputs
 * (docs/code/main/peripherals.md, tx-protection.md). */
#include "iodefine.h"
#include "main.h"

void R_S12AD0_Create_UserInit(void);
void R_S12AD1_Create_UserInit(void);
void R_S12AD0_Stop(void);
void R_S12AD1_Stop(void);
void adc0_store(void);      /* 0xFFFB27FB: copy unit 0's results */
void adc0_done(void);       /* 0xFFFB284E */
void adc1_store(void);      /* unit 1 counterparts (r_s12ad1_scan_end_isr 0xFFF92E0F) */
void adc1_done(void);

/* R_S12AD0_Create 0xFFF92851 */
void R_S12AD0_Create(void)
{
    SYSTEM_MSTPCRA = SYSTEM_MSTPCRA & 0xFFFDFFFFu;
    S12AD_ADCSR = S12AD_ADCSR & 0xEFFFu;
    S12AD_ADCMPCR = S12AD_ADCMPCR & 0x7FFFu;
    S12AD_ADCMPCR = S12AD_ADCMPCR & 0xDFFFu;
    ICU_IER17 = ICU_IER17 & 0xFBu;
    S12AD_ADCSR = 0u;
    S12AD_ADDISCR = 0u;
    S12AD_ADSSTR1 = 0xBu;
    S12AD_ADSSTR2 = 0xBu;
    S12AD_ADSSTR3 = 0xBu;
    S12AD_ADSSTR5 = 0xBu;
    S12AD_ADSSTR6 = 0xBu;
    S12AD_ADSSTR7 = 0xBu;
    S12AD_ADANSA0 = 0xEEu;
    S12AD_ADADS0 = 0xE8u;
    S12AD_ADSHCR = 0x618u;
    S12AD_ADCER = 0u;
    S12AD_ADCSR = S12AD_ADCSR | 0x1000u;
    S12AD_ADADC = 0x83u;
    S12AD_ADCMPCR = 0u;
    ICU_SLIBR186 = 0x40u;
    ICU_IPR186 = (ICU_IPR186 & 0xF6u) | 6u;
    PORT4_PMR = PORT4_PMR & 0xFDu;
    PORT4_PDR = PORT4_PDR & 0xFDu;
    MPC_P41PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xFBu;
    PORT4_PDR = PORT4_PDR & 0xFBu;
    MPC_P42PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xF7u;
    PORT4_PDR = PORT4_PDR & 0xF7u;
    MPC_P43PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xDFu;
    PORT4_PDR = PORT4_PDR & 0xDFu;
    MPC_P45PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0xBFu;
    PORT4_PDR = PORT4_PDR & 0xBFu;
    MPC_P46PFS = 0x80u;
    PORT4_PMR = PORT4_PMR & 0x7Fu;
    PORT4_PDR = PORT4_PDR & 0x7Fu;
    MPC_P47PFS = 0x80u;
    R_S12AD0_Create_UserInit();
}

/* R_S12AD0_Start 0xFFF929F7 */
void R_S12AD0_Start(void)
{
    ICU_IR186 = ICU_IR186 & 0xFEu;
    ICU_IER17 = ICU_IER17 | 4u;
    S12AD_ADCSR = S12AD_ADCSR | 0x8000u;
}

/* R_S12AD0_Stop 0xFFF92A13 */
void R_S12AD0_Stop(void)
{
    S12AD_ADCSR = S12AD_ADCSR & 0x7FFFu;
    ICU_IR186 = ICU_IR186 & 0xFEu;
    ICU_IER17 = ICU_IER17 & 0xFBu;
}

/* R_S12AD1_Create 0xFFF92B17 */
void R_S12AD1_Create(void)
{
    SYSTEM_MSTPCRA = SYSTEM_MSTPCRA & 0xFFFEFFFFu;
    S12AD1_ADCSR = S12AD1_ADCSR & 0xEFFFu;
    S12AD1_ADCMPCR = S12AD1_ADCMPCR & 0x7FFFu;
    S12AD1_ADCMPCR = S12AD1_ADCMPCR & 0xDFFFu;
    ICU_IER17 = ICU_IER17 & 0xDFu;
    S12AD1_ADDISCR = 0u;
    S12AD1_ADCSR = 0x5000u;
    S12AD1_ADCER = 0u;
    S12AD1_ADADC = 0x83u;
    S12AD1_ADANSA0 = 0x8300u;
    S12AD1_ADANSA1 = 2u;
    S12AD1_ADADS0 = 0x8300u;
    S12AD1_ADADS1 = 2u;
    S12AD1_ADSSTR8 = 0xBu;
    S12AD1_ADSSTR9 = 0xBu;
    S12AD1_ADSSTR15 = 0xBu;
    S12AD1_ADSSTRL = 0xBu;
    S12AD1_ADCMPCR = 0u;
    ICU_SLIBR189 = 0x44u;
    ICU_IPR189 = (ICU_IPR189 & 0xF6u) | 6u;
    PORTD_PMR = PORTD_PMR & 0xFEu;
    PORTD_PDR = PORTD_PDR & 0xFEu;
    MPC_PD0PFS = 0x80u;
    PORTD_PMR = PORTD_PMR & 0xFDu;
    PORTD_PDR = PORTD_PDR & 0xFDu;
    MPC_PD1PFS = 0x80u;
    PORT9_PMR = PORT9_PMR & 0xFDu;
    PORT9_PDR = PORT9_PDR & 0xFDu;
    MPC_P91PFS = 0x80u;
    PORT9_PMR = PORT9_PMR & 0xF7u;
    PORT9_PDR = PORT9_PDR & 0xF7u;
    MPC_P93PFS = 0x80u;
    R_S12AD1_Create_UserInit();
}

/* R_S12AD1_Start 0xFFF92C74 */
void R_S12AD1_Start(void)
{
    ICU_IR189 = ICU_IR189 & 0xFEu;
    ICU_IER17 = ICU_IER17 | 0x20u;
    S12AD1_ADCSR = S12AD1_ADCSR | 0x8000u;
}

/* R_S12AD1_Stop 0xFFF92C90 */
void R_S12AD1_Stop(void)
{
    S12AD1_ADCSR = S12AD1_ADCSR & 0x7FFFu;
    ICU_IER17 = ICU_IER17 & 0xDFu;
    ICU_IR189 = ICU_IR189 & 0xFEu;
}

void R_S12AD0_Create_UserInit(void) {}       /* 0xFFF92B00 */
void R_S12AD1_Create_UserInit(void) {}       /* 0xFFF92E0E */

/* R_S12AD0_Get_ValueResult 0xFFF92A31: one result register by channel number; unit 0 has AN000..AN007 (0..7),
 * ADRD (21) and the double-trigger registers ADDBLDR/A/B (24..26); any other number stores nothing [fact: the
 * compare chain 0xFFF92A39..0xFFF92A6C] */
void R_S12AD0_Get_ValueResult(uint32_t channel, uint16_t *buffer)
{
    switch (channel) {
    case 0: *buffer = S12AD_ADDR0; break;
    case 1: *buffer = S12AD_ADDR1; break;
    case 2: *buffer = S12AD_ADDR2; break;
    case 3: *buffer = S12AD_ADDR3; break;
    case 4: *buffer = S12AD_ADDR4; break;
    case 5: *buffer = S12AD_ADDR5; break;
    case 6: *buffer = S12AD_ADDR6; break;
    case 7: *buffer = S12AD_ADDR7; break;
    case 21: *buffer = S12AD_ADRD; break;
    case 24: *buffer = S12AD_ADDBLDR; break;
    case 25: *buffer = S12AD_ADDBLDRA; break;
    case 26: *buffer = S12AD_ADDBLDRB; break;
    default: break;
    }
}

/* R_S12AD1_Get_ValueResult 0xFFF92CAE: unit 1, channels 0..20 (AN100..AN120), 21 ADRD, 22 ADTSDR (temperature
 * sensor), 23 ADOCDR (internal reference), 24..26 ADDBLDR/A/B; above 26 nothing [fact: the jump table 0xFFF8EF6E] */
void R_S12AD1_Get_ValueResult(uint32_t channel, uint16_t *buffer)
{
    switch (channel) {
    case 0: *buffer = S12AD1_ADDR0; break;
    case 1: *buffer = S12AD1_ADDR1; break;
    case 2: *buffer = S12AD1_ADDR2; break;
    case 3: *buffer = S12AD1_ADDR3; break;
    case 4: *buffer = S12AD1_ADDR4; break;
    case 5: *buffer = S12AD1_ADDR5; break;
    case 6: *buffer = S12AD1_ADDR6; break;
    case 7: *buffer = S12AD1_ADDR7; break;
    case 8: *buffer = S12AD1_ADDR8; break;
    case 9: *buffer = S12AD1_ADDR9; break;
    case 10: *buffer = S12AD1_ADDR10; break;
    case 11: *buffer = S12AD1_ADDR11; break;
    case 12: *buffer = S12AD1_ADDR12; break;
    case 13: *buffer = S12AD1_ADDR13; break;
    case 14: *buffer = S12AD1_ADDR14; break;
    case 15: *buffer = S12AD1_ADDR15; break;
    case 16: *buffer = S12AD1_ADDR16; break;
    case 17: *buffer = S12AD1_ADDR17; break;
    case 18: *buffer = S12AD1_ADDR18; break;
    case 19: *buffer = S12AD1_ADDR19; break;
    case 20: *buffer = S12AD1_ADDR20; break;
    case 21: *buffer = S12AD1_ADRD; break;
    case 22: *buffer = S12AD1_ADTSDR; break;
    case 23: *buffer = S12AD1_ADOCDR; break;
    case 24: *buffer = S12AD1_ADDBLDR; break;
    case 25: *buffer = S12AD1_ADDBLDRA; break;
    case 26: *buffer = S12AD1_ADDBLDRB; break;
    default: break;
    }
}

/* r_s12ad0_scan_end_isr 0xFFF92B01 / r_s12ad1_scan_end_isr 0xFFF92E0F (S12ADI0 vector 186, S12ADI1 vector 189):
 * stop the unit, store the results, flag them [fact] */
__attribute__((interrupt)) void r_s12ad0_scan_end_isr(void)
{
    R_S12AD0_Stop();
    adc0_store();
    adc0_done();
}

__attribute__((interrupt)) void r_s12ad1_scan_end_isr(void)
{
    R_S12AD1_Stop();
    adc1_store();
    adc1_done();
}
