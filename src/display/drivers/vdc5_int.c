/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 driver's interrupt part, 0x2011834C..0x201193EB, recreated from the image.
 *
 * 23 interrupt sources per channel in three groups of eight bits 4 apart: types 0..7 in SYSCNT_INT1/INT4, 8..15 in
 * INT2/INT5, 16..22 in INT3/INT6 (INT1..3 status, INT4..6 enable) [fact: the 46 handlers 0x20118548..0x201193BF
 * and the bit table 0x20165B2C]. r_vdc5_callback_isr records a callback and switches the source on or off; each
 * handler (registered with the GIC through r_vdc5_get_isr) clears its status bit, calls the callback with its type
 * and restores the status word. The firmware uses only type 3 (graphics 3 line, GIC 78) on channel 0
 * (vdc5_vline_cb, docs/code/display/gui.md).
 */
#include "vdc5.h"
#include "vdc5_regs.h"

#define VDC5_INT_TYPE_NUM 23
#define VDC5_INT_TYPE_VLINE 3
#define VDC5_INT_TYPE_S0_WLINE 9
#define VDC5_INT_TYPE_S1_WLINE 16
#define VDC5_INT_TYPE_OIR_VLINE 19

typedef void (*vdc5_isr_t)(uint32_t int_sense);
typedef void (*vdc5_callback_t)(int type);

extern vdc5_callback_t vdc5_int_callback[VDC5_CHANNEL_NUM][VDC5_INT_TYPE_NUM];   /* 0x208DCC0C */
extern const vdc5_isr_t vdc5_isr_table[VDC5_CHANNEL_NUM][VDC5_INT_TYPE_NUM];     /* 0x20165A74 */
extern const uint32_t vdc5_int_bit_table[VDC5_INT_TYPE_NUM];                     /* 0x20165B2C */

/* 0x2011834C: (ch, type): the handler of one source, for the GIC registration [fact] */
vdc5_isr_t r_vdc5_get_isr(unsigned ch, unsigned type)
{
    return vdc5_isr_table[ch][type];
}

/* 0x20118364: (ch): no callbacks, every source disabled [fact] */
void vdc5_int_callbacks_clear(unsigned ch)
{
    const vdc5_regaddr_system_ctrl_t *sys = &vdc5_regaddr_system_ctrl[ch];
    int i;

    for (i = 0; i < VDC5_INT_TYPE_NUM; i++)
    {
        vdc5_int_callback[ch][i] = NULL;
    }
    *sys->syscnt_int4 = 0;
    *sys->syscnt_int5 = 0;
    *sys->syscnt_int6 = 0;
}

/* 0x201183B0: (ch, {type, callback, line}): records the callback; with one, enables the source (and copies the
 * enable word to the status register when it was off) and sets the line number of the line interrupts (graphics 3
 * and OIR: GR_CLUT bits 10..0 and P_VEN; scaler 0/1 write line: SCL0_INT and VEN_A); without one, disables it
 * [fact] */
void r_vdc5_callback_isr(unsigned ch, const vdc5_int_t *param)
{
    const vdc5_regaddr_system_ctrl_t *sys = &vdc5_regaddr_system_ctrl[ch];
    reg32_t status, enable;
    uint32_t bit;

    if (param->type < 8)
    {
        status = sys->syscnt_int1;
        enable = sys->syscnt_int4;
    }
    else if (param->type < 16)
    {
        status = sys->syscnt_int2;
        enable = sys->syscnt_int5;
    }
    else
    {
        status = sys->syscnt_int3;
        enable = sys->syscnt_int6;
    }
    bit = vdc5_int_bit_table[param->type];
    vdc5_int_callback[ch][param->type] = param->callback;
    if (param->callback == NULL)
    {
        *enable &= ~bit;
        *status = *enable;
        return;
    }
    if ((*enable & bit) == 0)
    {
        *enable |= bit;
        *status = *enable;
    }
    if (param->type == VDC5_INT_TYPE_VLINE || param->type == VDC5_INT_TYPE_OIR_VLINE)
    {
        const vdc5_regaddr_img_synthesizer_t *gr =
            &vdc5_regaddr_img_synthesizer[ch][param->type == VDC5_INT_TYPE_VLINE ? 3 : 5];

        *gr->gr_clut &= ~0x7FFU;
        *gr->gr_clut |= param->line_num;
        *gr->gr_update |= 0x10;
    }
    else if (param->type == VDC5_INT_TYPE_S0_WLINE || param->type == VDC5_INT_TYPE_S1_WLINE)
    {
        const vdc5_regaddr_scaler_t *sc = &vdc5_regaddr_scaler[ch][param->type == VDC5_INT_TYPE_S0_WLINE ? 0 : 1];

        *sc->scl0_int = param->line_num;
        *sc->scl0_update |= 1;
    }
}

/* one handler: (ch, type) -> status SYSCNT_INT(1 + type / 8), enable INT(4 + type / 8), bit 1 << 4 (type % 8),
 * callback slot [ch][type]; the status bit is cleared while the callback runs [fact: 0x20118548 and the other 45] */
static inline void vdc5_isr(unsigned ch, unsigned type)
{
    reg32_t const *regs = &vdc5_regaddr_system_ctrl[ch].syscnt_int1;
    reg32_t status = regs[type / 8];
    uint32_t bit = 1U << (4 * (type % 8));
    uint32_t state = *regs[3 + type / 8];

    if ((state & bit) != 0 && (*status & bit) != 0)
    {
        *status = state & ~bit;
        if (vdc5_int_callback[ch][type] != NULL)
        {
            vdc5_int_callback[ch][type](type);
        }
        *status = state;
    }
}

#define VDC5_ISR(name, ch, type) \
    void name(uint32_t int_sense) \
    { \
        (void)int_sense; \
        vdc5_isr(ch, type); \
    }

VDC5_ISR(vdc5_ch0_isr_s0_vi_vsync, 0, 0)
VDC5_ISR(vdc5_ch0_isr_s0_lo_vsync, 0, 1)
VDC5_ISR(vdc5_ch0_isr_s0_vsyncerr, 0, 2)
VDC5_ISR(vdc5_ch0_isr_gr3_vline, 0, 3)
VDC5_ISR(vdc5_ch0_isr_s0_vfield, 0, 4)
VDC5_ISR(vdc5_ch0_isr_iv1_vbuferr, 0, 5)
VDC5_ISR(vdc5_ch0_isr_iv3_vbuferr, 0, 6)
VDC5_ISR(vdc5_ch0_isr_iv5_vbuferr, 0, 7)
VDC5_ISR(vdc5_ch0_isr_iv6_vbuferr, 0, 8)
VDC5_ISR(vdc5_ch0_isr_s0_wline, 0, 9)
VDC5_ISR(vdc5_ch0_isr_s1_vi_vsync, 0, 10)
VDC5_ISR(vdc5_ch0_isr_s1_lo_vsync, 0, 11)
VDC5_ISR(vdc5_ch0_isr_s1_vsyncerr, 0, 12)
VDC5_ISR(vdc5_ch0_isr_s1_vfield, 0, 13)
VDC5_ISR(vdc5_ch0_isr_iv2_vbuferr, 0, 14)
VDC5_ISR(vdc5_ch0_isr_iv4_vbuferr, 0, 15)
VDC5_ISR(vdc5_ch0_isr_s1_wline, 0, 16)
VDC5_ISR(vdc5_ch0_isr_oir_vi_vsync, 0, 17)
VDC5_ISR(vdc5_ch0_isr_oir_lo_vsync, 0, 18)
VDC5_ISR(vdc5_ch0_isr_oir_vline, 0, 19)
VDC5_ISR(vdc5_ch0_isr_oir_vfield, 0, 20)
VDC5_ISR(vdc5_ch0_isr_iv7_vbuferr, 0, 21)
VDC5_ISR(vdc5_ch0_isr_iv8_vbuferr, 0, 22)
VDC5_ISR(vdc5_ch1_isr_s0_vi_vsync, 1, 0)
VDC5_ISR(vdc5_ch1_isr_s0_lo_vsync, 1, 1)
VDC5_ISR(vdc5_ch1_isr_s0_vsyncerr, 1, 2)
VDC5_ISR(vdc5_ch1_isr_gr3_vline, 1, 3)
VDC5_ISR(vdc5_ch1_isr_s0_vfield, 1, 4)
VDC5_ISR(vdc5_ch1_isr_iv1_vbuferr, 1, 5)
VDC5_ISR(vdc5_ch1_isr_iv3_vbuferr, 1, 6)
VDC5_ISR(vdc5_ch1_isr_iv5_vbuferr, 1, 7)
VDC5_ISR(vdc5_ch1_isr_iv6_vbuferr, 1, 8)
VDC5_ISR(vdc5_ch1_isr_s0_wline, 1, 9)
VDC5_ISR(vdc5_ch1_isr_s1_vi_vsync, 1, 10)
VDC5_ISR(vdc5_ch1_isr_s1_lo_vsync, 1, 11)
VDC5_ISR(vdc5_ch1_isr_s1_vsyncerr, 1, 12)
VDC5_ISR(vdc5_ch1_isr_s1_vfield, 1, 13)
VDC5_ISR(vdc5_ch1_isr_iv2_vbuferr, 1, 14)
VDC5_ISR(vdc5_ch1_isr_iv4_vbuferr, 1, 15)
VDC5_ISR(vdc5_ch1_isr_s1_wline, 1, 16)
VDC5_ISR(vdc5_ch1_isr_oir_vi_vsync, 1, 17)
VDC5_ISR(vdc5_ch1_isr_oir_lo_vsync, 1, 18)
VDC5_ISR(vdc5_ch1_isr_oir_vline, 1, 19)
VDC5_ISR(vdc5_ch1_isr_oir_vfield, 1, 20)
VDC5_ISR(vdc5_ch1_isr_iv7_vbuferr, 1, 21)
VDC5_ISR(vdc5_ch1_isr_iv8_vbuferr, 1, 22)
