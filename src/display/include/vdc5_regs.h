/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 driver's register-address tables in .rodata.
 *
 * The driver reaches every VDC5 register through tables of pointers, per channel and per block (the
 * r_vdc5_register_address part of the Renesas driver [inference: include/vdc5.h]). The layouts below are the image's
 * [fact: the offsets the code loads, e.g. r_vdc5_callback_isr 0x201183B0 reads system_ctrl + 0x20 ch + 0x0C and
 * img_synthesizer + 0x210 ch + 0x58 gr + 0x50; the table words, e.g. 0x20166A30 = 0xFCFF7A80 (SYSCNT_INT1)].
 * Register names are those of the RZ/A1H hardware manual (VDC5 chapter).
 */
#ifndef VDC5_REGS_H
#define VDC5_REGS_H

#include <stdint.h>

typedef volatile uint32_t *reg32_t;
typedef volatile uint16_t *reg16_t;

typedef struct
{
    reg32_t scl0_update, scl0_frc1, scl0_frc2, scl0_frc3, scl0_frc4, scl0_frc5, scl0_frc6, scl0_frc7, scl0_frc9,
        scl0_mon0;
    reg16_t scl0_int;
    reg32_t scl0_ds1, scl0_ds2, scl0_ds3, scl0_ds4, scl0_ds5, scl0_ds6, scl0_ds7, scl0_us1, scl0_us2, scl0_us3,
        scl0_us4, scl0_us5, scl0_us6, scl0_us7, scl0_us8, scl0_ovr1, scl1_update, scl1_wr1, scl1_wr2, scl1_wr3,
        scl1_wr4, scl1_wr5, scl1_wr6, scl1_wr7, scl1_wr8, scl1_wr9, scl1_wr10, scl1_wr11, scl1_mon1, scl1_pbuf0,
        scl1_pbuf1, scl1_pbuf2, scl1_pbuf3, scl1_pbuf_fld, scl1_pbuf_cnt;
} vdc5_regaddr_scaler_t;   /* 0xB8 bytes */

typedef struct
{
    reg32_t gr_update, gr_flm_rd, gr_flm1, gr_flm2, gr_flm3, gr_flm4, gr_flm5, gr_flm6, gr_ab1, gr_ab2, gr_ab3,
        gr_ab4, gr_ab5, gr_ab6, gr_ab7, gr_ab8, gr_ab9, gr_ab10, gr_ab11, gr_base, gr_clut, gr_mon;
} vdc5_regaddr_img_synthesizer_t;   /* 0x58 bytes */

typedef struct
{
    reg32_t syscnt_int1, syscnt_int2, syscnt_int3;   /* interrupt status (write 0 to clear a bit) */
    reg32_t syscnt_int4, syscnt_int5, syscnt_int6;   /* interrupt enable */
    reg16_t syscnt_panel_clk, syscnt_clut;
} vdc5_regaddr_system_ctrl_t;   /* 0x20 bytes */

extern const vdc5_regaddr_scaler_t vdc5_regaddr_scaler[2][3];                   /* 0x20165CE0 */
extern const vdc5_regaddr_img_synthesizer_t vdc5_regaddr_img_synthesizer[2][6]; /* 0x201662C0 */
extern const vdc5_regaddr_system_ctrl_t vdc5_regaddr_system_ctrl[2];            /* 0x20166A30 */

#endif
