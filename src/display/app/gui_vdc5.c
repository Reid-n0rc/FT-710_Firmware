/*
 * FT-710 DISPLAY (T24 round 5): the GUI's VDC5 set-up, 0x20132320..0x201330D3 (part), recreated from the image.
 *
 * gui_start (docs/code/display/gui.md "VDC5 set-up") brings up VDC5 channel 0 for the 800x480 TFT and channel 1
 * for the LVDS link to the DVI encoder on MAIN with these helpers: the module clock (CPG), the panel timing tables,
 * the LVDS PLL block, the sync and output parameters, and the graphics-3 line interrupt that paces the GUI loop.
 * The parameter blocks are built on the stack as the image does and passed to the driver (drivers/vdc5_api.c).
 */
#include "display.h"
#include "norti.h"
#include "vdc5.h"

#define CPG_BASE 0xFCFE0000U
#define CPG_STBREQ2 (CPG_BASE + 0x34)   /* module standby request */
#define CPG_STBACK2 (CPG_BASE + 0x44)   /* module standby acknowledge */
#define GIC_ID_VDC50_GR3_VLINE 78

/* one TCON signal timing of the image's tables (10 bytes: start, width, mode, reference, polarity, pin, edge) */
typedef struct
{
    uint16_t tcon_hsvs, tcon_hwvw;
    uint8_t tcon_md, tcon_hs_sel, tcon_inv, tcon_pin, outcnt_edge;
} lcd_tcon_timing_t;

typedef struct
{
    uint16_t tcon_half, tcon_offset;
    const lcd_tcon_timing_t *outctrl[8];
    uint8_t outcnt_lcd_edge, out_endian_on, out_swap_on, out_format, out_frq_sel, out_dir_sel, out_phase;
    uint32_t bg_color;
} gui_output_t;

typedef struct
{
    uint32_t delta, last;
} cycle_stamp_t;

/* the frame pacing words (.data2) [fact: vdc5_vline_cb, vdc5_wait_frames] */
typedef struct
{
    uint32_t pad0[4];
    volatile uint32_t wait;     /* +0x10: frames still to wait (vdc5_wait_frames) */
    uint32_t pad1;
    volatile uint32_t frames;   /* +0x18: graphics-3 line interrupts so far */
} gui_vsync_t;

extern const lcd_tcon_timing_t lcd_tcon_ch0[5];        /* 0x203A6FD4: STVA, STH, STVB, STB, DE */
extern const lcd_tcon_timing_t dvi_tcon_ch1[5][2];     /* 0x203A7006: STVA, STH, STVB, STB, DE per mode */
extern vdc5_lvds_t gui_lvds;                           /* 0x208F4D44 */
extern cycle_stamp_t gui_frame_stamp;                  /* 0x208F4DB8 */
extern gui_vsync_t gui_vsync;                          /* 0x2080858C */
extern vdc5_int_t gui_vline_int;                       /* 0x20907F58 */
extern const T_CISR vdc5_vline_cisr;                   /* 0x203A706C: GIC 78, handler vdc5_ch0_isr_gr3_vline */

uint32_t cycle_delta_2(cycle_stamp_t *stamp);
int r_vdc5_sync_control(unsigned ch, const vdc5_sync_ctrl_t *param);
int r_vdc5_display_output(unsigned ch, const vdc5_output_t *param);
int r_vdc5_callback_isr_checked(unsigned ch, const vdc5_int_t *param);
ER itron_acre_isr(ID id, const T_CISR *pk_cisr);

/* 0x20132320: (ch): the VDC5 module clock on: channel 1 clears both STBCR9 bits 1..0 and the standby request bit 4,
 * channel 0 bit 1 and request bit 5; then waits for the acknowledge to clear [fact] */
void vdc5_module_start(uint8_t ch)
{
    volatile uint8_t dummy;

    if (ch != 0)
    {
        REG8(CPG_STBCR9) &= ~3;
        dummy = REG8(CPG_STBCR9);
        REG8(CPG_STBREQ2) &= ~0x10;
        while ((REG8(CPG_STBACK2) & 0x10) != 0)
        {
        }
    }
    else
    {
        REG8(CPG_STBCR9) &= ~2;
        dummy = REG8(CPG_STBCR9);
        REG8(CPG_STBREQ2) &= ~0x20;
        while ((REG8(CPG_STBACK2) & 0x20) != 0)
        {
        }
    }
    (void)dummy;
}

/* 0x20132398: (ch): standby request, wait for the acknowledge, module clock off (STBCR9 bit 0 for channel 1, bit 1
 * for channel 0) [fact] */
void vdc5_module_stop(uint8_t ch)
{
    volatile uint8_t dummy;

    if (ch != 0)
    {
        REG8(CPG_STBREQ2) |= 0x10;
        while ((REG8(CPG_STBACK2) & 0x10) == 0)
        {
        }
        REG8(CPG_STBCR9) |= 1;
    }
    else
    {
        REG8(CPG_STBREQ2) |= 0x20;
        while ((REG8(CPG_STBACK2) & 0x20) == 0)
        {
        }
        REG8(CPG_STBCR9) |= 2;
    }
    dummy = REG8(CPG_STBCR9);
    (void)dummy;
}

/* 0x201323FC: (outctrl[8]): the TFT's TCON signals STVA, STVB, STH, STB and DE from the table 0x203A6FD4 [fact] */
void lcd_tcon_cfg_ch0(const lcd_tcon_timing_t **outctrl)
{
    if (outctrl == NULL)
    {
        return;
    }
    outctrl[0] = &lcd_tcon_ch0[0];
    outctrl[1] = &lcd_tcon_ch0[2];
    outctrl[2] = &lcd_tcon_ch0[1];
    outctrl[3] = &lcd_tcon_ch0[3];
    outctrl[4] = NULL;
    outctrl[5] = NULL;
    outctrl[6] = NULL;
    outctrl[7] = &lcd_tcon_ch0[4];
}

/* 0x20132440: (mode, outctrl[8]): the same for the DVI channel, one timing set per mode [fact] */
void dvi_tcon_cfg_ch1(unsigned mode, const lcd_tcon_timing_t **outctrl)
{
    if (outctrl == NULL)
    {
        return;
    }
    outctrl[0] = &dvi_tcon_ch1[0][mode];
    outctrl[1] = &dvi_tcon_ch1[2][mode];
    outctrl[2] = &dvi_tcon_ch1[1][mode];
    outctrl[3] = &dvi_tcon_ch1[3][mode];
    outctrl[4] = NULL;
    outctrl[5] = NULL;
    outctrl[6] = NULL;
    outctrl[7] = &dvi_tcon_ch1[4][mode];
}

/* 0x2013249C: (unused, mode): the LVDS PLL block: input = video clock, IDIV 0, test 16, ODIV 2, channel 1, FD 207
 * (mode != 0) or 175, RD 4, OD 2 [fact: the stores; gui.md "LVDS PLL"] */
const vdc5_lvds_t *lvds_pll_cfg(unsigned unused, unsigned mode)
{
    vdc5_lvds_t *l = &gui_lvds;

    (void)unused;
    l->lvds_in_clk_sel = 0;
    l->lvds_idiv_set = 0;
    l->lvdspll_tst = 16;
    l->lvds_odiv_set = 2;
    l->lvds_vdc_sel = 1;
    l->lvdspll_fd = mode != 0 ? 0xCF : 0xAF;
    l->lvdspll_rd = 4;
    l->lvdspll_od = 2;
    return l;
}

/* 0x20132504: (ch, mode): free-running sync: channel 0 1016 x 525 (H 0x3F7 + 1, V 0x20C + 1) with the 800 x 480
 * area at (0x58, 0x20); channel 1 1056 x 517 for mode 0 or 1056 x 628 for mode 1 (800 x 600) [fact] */
int vdc5_sync_setup(unsigned ch, unsigned mode)
{
    vdc5_sync_ctrl_t s;

    s.res_vs_sel = 1;
    s.res_vs_in_sel = 0;
    s.res_vsdly = 0;
    s.vsync_cpmpe = NULL;
    s.res_f.hw = 800;
    if (ch == 0)
    {
        s.res_fv = 0x20C;
        s.res_fh = 0x3F7;
        s.res_f.vs = 0x20;
        s.res_f.vw = 480;
        s.res_f.hs = 0x58;
    }
    else if (mode != 0)
    {
        s.res_fv = 0x273;
        s.res_fh = 0x41F;
        s.res_f.vs = 0x1B;
        s.res_f.vw = 600;
        s.res_f.hs = 0xD8;
    }
    else
    {
        s.res_fv = 0x204;
        s.res_fh = 0x43F;
        s.res_f.vs = 0x1F;
        s.res_f.vw = 480;
        s.res_f.hs = 0xE0;
    }
    return r_vdc5_sync_control(ch, &s);
}

/* 0x201325E8: (ch, mode): parallel RGB888 output, black background; channel 0 TCON half 0x1FB and swapped data,
 * channel 1 half 0x21F (mode 0) or 0x20F [fact] */
int vdc5_output_setup(unsigned ch, unsigned mode)
{
    gui_output_t o;

    o.tcon_offset = 0;
    if (ch != 0)
    {
        o.tcon_half = mode == 0 ? 0x21F : 0x20F;
        dvi_tcon_cfg_ch1(mode, o.outctrl);
        o.out_swap_on = 0;
    }
    else
    {
        o.tcon_half = 0x1FB;
        lcd_tcon_cfg_ch0(o.outctrl);
        o.out_swap_on = 1;
    }
    o.outcnt_lcd_edge = 0;
    o.out_endian_on = 0;
    o.out_format = 0;
    o.out_frq_sel = 0;
    o.out_dir_sel = 0;
    o.out_phase = 0;
    o.bg_color = 0;
    return r_vdc5_display_output(ch, (const vdc5_output_t *)&o);
}

/* 0x20133014: the graphics-3 line callback: a cycle stamp, the frame count, and one frame less to wait [fact] */
void vdc5_vline_cb(int type)
{
    (void)type;
    cycle_delta_2(&gui_frame_stamp);
    gui_vsync.frames++;
    if (gui_vsync.wait != 0)
    {
        gui_vsync.wait--;
    }
}

/* 0x2013304C: (ch): the graphics-3 line interrupt at line 0, no callback yet [fact] */
int vdc5_vline_int_setup(unsigned ch)
{
    gui_vline_int.type = 3;
    gui_vline_int.callback = NULL;
    gui_vline_int.line_num = 0;
    return r_vdc5_callback_isr_checked(ch, &gui_vline_int);
}

/* 0x20133068 / 0x2013307C: (ch): the callback on / off [fact] */
int vdc5_vline_cb_enable(unsigned ch)
{
    gui_vline_int.callback = vdc5_vline_cb;
    return r_vdc5_callback_isr_checked(ch, &gui_vline_int);
}

int vdc5_vline_cb_disable(unsigned ch)
{
    gui_vline_int.callback = NULL;
    return r_vdc5_callback_isr_checked(ch, &gui_vline_int);
}

/* 0x20133090: (n): busy-waits until the line interrupt has counted n frames down [fact] */
void vdc5_wait_frames(uint32_t n)
{
    gui_vsync.wait = n;
    while (gui_vsync.wait != 0)
    {
    }
}

/* 0x201330A8: registers the graphics-3 line handler with the kernel and enables GIC 78; returns 0, or the kernel's
 * error code (its ble skips the mov r0, #0 at 0x201330CC) [fact] */
int vdc5_isr_create(void)
{
    ER er = itron_acre_isr(0, &vdc5_vline_cisr);

    if (er <= 0)
    {
        return er;
    }
    gic_enable_irq(GIC_ID_VDC50_GR3_VLINE);
    return 0;
}
