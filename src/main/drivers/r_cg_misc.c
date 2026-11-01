/* Small Renesas Code Generator drivers of the MAIN image (IWDT, DA, TPU0/TPU1), recreated for T24.
 * docs/code/main/peripherals.md describes their use; every value below is [fact] from the disassembly at the
 * address given with each function. */
#include "iodefine.h"
#include "main.h"

void swtimer_tick(void);           /* 0xFFFB2288: soft-timer tick (sci.md "swtimer_start") */
void tone_sample_isr(void);        /* 0xFFFB2469: side-tone / beep sample (peripherals.md) */
void R_IWDT_Create_UserInit(void);
void R_DA_Create_UserInit(void);
void R_TPU0_Create_UserInit(void);
void R_TPU1_Create_UserInit(void);

/* ---- IWDT (r_cg_iwdt.c) ---- */

/* R_IWDT_Create 0xFFF927A9: IWDTCR = 0x3350, no reset on underflow (IWDTRCR = 0), stop in sleep (IWDTCSTPR = 0x80),
 * NMI enable for the IWDT underflow (NMIER bit 3) */
void R_IWDT_Create(void)
{
    IWDT_IWDTCR = 0x3350u;
    IWDT_IWDTRCR = 0x00u;
    IWDT_IWDTCSTPR = 0x80u;
    ICU_NMIER |= 0x08u;
    R_IWDT_Create_UserInit();
}

/* iwdt_refresh 0xFFF927CE: the refresh sequence 0x00, 0xFF (R_IWDT_Restart) */
void iwdt_refresh(void)
{
    IWDT_IWDTRR = 0x00u;
    IWDT_IWDTRR = 0xFFu;
}

void R_IWDT_Create_UserInit(void) {}          /* 0xFFF927DF */

/* ---- DA (r_cg_da.c) ---- */

/* R_DA_Create 0xFFF927E5: module on, right-justified data, no A/D sync, P03 (DA0) as analog output */
void R_DA_Create(void)
{
    SYSTEM_MSTPCRA &= ~(1ul << 19);
    DA_DADPR = 0x00u;
    DA_DAADSCR = 0x00u;
    PORT0_PMR &= 0xF7u;
    PORT0_PDR &= 0xF7u;
    MPC_P03PFS |= 0x80u;             /* ASEL */
    R_DA_Create_UserInit();
}

/* R_DA0_Start 0xFFF92826: DACR.DAE = 0, DAOE0 = 1 */
void R_DA0_Start(void)
{
    DA_DACR &= (uint8_t)~0x20u;
    DA_DACR |= 0x40u;
}

/* R_DA0_Stop 0xFFF92835: DAOE0 = 0 */
void R_DA0_Stop(void)
{
    DA_DACR &= (uint8_t)~0x40u;
}

/* dac0_write 0xFFF9283D: DADR0 = 12-bit value (R_DA0_Set_ConversionValue) */
void dac0_write(uint16_t value)
{
    DA_DADR0 = (uint16_t)(value & 0x0FFFu);
}

void R_DA_Create_UserInit(void) {}            /* 0xFFF92850 */

/* ---- TPU0 / TPU1 (r_cg_tpu.c, r_cg_tpu_user.c) ---- */

/* R_TPU0_Create 0xFFF949B4: module on, TPU0 stopped and not synchronous, TGIA0 on selectable vector 130 (source 15)
 * at priority 4, TCR = 0x2A, TIER |= 0x41 (TGIEA, TTGE), TGRA..D = 374; TPU0 is the 100 us tick of
 * docs/code/main/README.md */
void R_TPU0_Create(void)
{
    SYSTEM_MSTPCRA &= ~(1ul << 13);
    TPUA_TSTR &= (uint8_t)~0x01u;
    ICU_SLIBXR130 = 15u;
    ICU_IPR130 = (uint8_t)((ICU_IPR130 | 0x04u) & 0xF4u);
    TPUA_TSYR &= (uint8_t)~0x01u;
    TPU0_TCR = 0x2Au;
    TPU0_TIER |= 0x41u;
    TPU0_TIORH = 0x00u;
    TPU0_TIORL = 0x00u;
    TPU0_TGRA = 374u;
    TPU0_TGRB = 374u;
    TPU0_TGRC = 374u;
    TPU0_TGRD = 374u;
    R_TPU0_Create_UserInit();
}

/* R_TPU0_Start 0xFFF94A38 / R_TPU0_Stop 0xFFF94A47: IER10 bit 2 (vector 130) and TSTR.CST0 */
void R_TPU0_Start(void)
{
    ICU_IER10 |= 0x04u;
    TPUA_TSTR |= 0x01u;
}

void R_TPU0_Stop(void)
{
    ICU_IER10 &= (uint8_t)~0x04u;
    TPUA_TSTR &= (uint8_t)~0x01u;
}

void R_TPU0_Create_UserInit(void) {}          /* 0xFFF94A56 */

/* r_tpu0_tgia_isr 0xFFF94A57: TGIA0 -> the soft-timer tick */
__attribute__((interrupt)) void r_tpu0_tgia_isr(void)
{
    swtimer_tick();
}

/* R_TPU1_Create 0xFFF94A65: TGIA1 on selectable vector 144 (source 20) at priority 14, TCR = 0x20, TGRA = 624,
 * TGRB = 5999 */
void R_TPU1_Create(void)
{
    SYSTEM_MSTPCRA &= ~(1ul << 13);
    TPUA_TSTR &= (uint8_t)~0x02u;
    ICU_SLIBR144 = 20u;
    ICU_IPR144 = (uint8_t)((ICU_IPR144 | 0x0Eu) & 0xFEu);
    TPUA_TSYR &= (uint8_t)~0x02u;
    TPU1_TCR = 0x20u;
    TPU1_TIER |= 0x41u;
    TPU1_TIOR = 0x00u;
    TPU1_TGRA = 624u;
    TPU1_TGRB = 0x176Fu;
    R_TPU1_Create_UserInit();
}

/* R_TPU1_Start 0xFFF94ACD / R_TPU1_Stop 0xFFF94ADC: IER12 bit 0 (vector 144) and TSTR.CST1 */
void R_TPU1_Start(void)
{
    ICU_IER12 |= 0x01u;
    TPUA_TSTR |= 0x02u;
}

void R_TPU1_Stop(void)
{
    ICU_IER12 &= (uint8_t)~0x01u;
    TPUA_TSTR &= (uint8_t)~0x02u;
}

void R_TPU1_Create_UserInit(void) {}          /* 0xFFF94AEB */

/* r_tpu1_tgia_isr 0xFFF94AEC: TGIA1 -> the side-tone sample */
__attribute__((interrupt)) void r_tpu1_tgia_isr(void)
{
    tone_sample_isr();
}
