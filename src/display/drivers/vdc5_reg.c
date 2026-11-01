/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 driver's register layer, 0x201193C0..0x2011D07F (part), recreated from the
 * image.
 *
 * The functions behind the API calls of drivers/vdc5_api.c that program the VDC5 registers, through the address
 * tables of include/vdc5_regs.h [fact: every register access goes through a table word]. Bit names in the comments
 * are the RZ/A1H hardware manual's (VDC5 chapter). The busy-wait loops count a volatile word, as the image does on
 * the stack [fact: 0x201193C0].
 */
#include "vdc5.h"
#include "vdc5_regs.h"

typedef struct
{
    reg32_t inp_update, inp_sel_cnt, inp_ext_sync_cnt, inp_vsync_ph_adj, inp_dly_adj, imgcnt_update, imgcnt_nr_cnt0,
        imgcnt_nr_cnt1;
} vdc5_regaddr_input_ctrl_t;

typedef struct
{
    reg32_t lvds_update, lvdsfcl, lclkselr, lpllsetr, lphyacc;
} vdc5_regaddr_lvds_t;

extern const vdc5_regaddr_input_ctrl_t vdc5_regaddr_input_ctrl[VDC5_CHANNEL_NUM];   /* 0x20165CA0 */
extern const vdc5_regaddr_lvds_t vdc5_regaddr_lvds;                                 /* 0x20166A70 */
extern const uint16_t vdc5_panel_dcdr_tbl[];      /* 0x20165BFC: SYSCNT_PANEL_CLK divider bits per ratio */
extern const uint16_t vdc5_panel_icksel_tbl[];    /* 0x20165C16: SYSCNT_PANEL_CLK clock select bits per source */

/* the image's version of vdc5_sync_delay_t: the first field is one byte [fact: ldrb at 0x20119824] */
typedef struct
{
    uint8_t inp_vs_dly_l;
    uint16_t inp_fld_dly, inp_vs_dly, inp_hs_dly;
} vdc5_sync_delay_t;

typedef struct
{
    uint8_t inp_format, inp_pxd_edge, inp_vs_edge, inp_hs_edge, inp_endian_on, inp_swap_on, inp_vs_inv, inp_hs_inv,
        inp_h_edge_sel, inp_f525_625, inp_h_pos;
} vdc5_ext_sig_full_t;

void vdc5_shrd_set_cascade(unsigned ch, unsigned on);
void vdc5_shrd_set_und_sel(unsigned ch, unsigned on);
uint32_t vdc5_shrd_get_bg_color(unsigned ch, unsigned color_space);


#define LVDS_PLL_WAIT_CYCLE 0x26

/* 0x201193C0: about 200 us of busy waiting (0x3458 counts) [fact] */
void vdc5_wait_200us(void)
{
    volatile uint32_t n;

    for (n = 0; n < 0x3458; n++)
    {
    }
}

/* 0x201193EC: (ch, init): panel clock off (SYSCNT_PANEL_CLK bit 8); with an LVDS block the LVDS PLL is powered down,
 * programmed (LPHYACC 1; LCLKSELR: input clock, IDIV, test, ODIV, channel 1 select; LPLLSETR: FD, RD, OD), powered up after 200
 * us and its output enabled; the video-decoder clock route (INP_SEL_CNT bit 20 for select 1); then divider and
 * source, and the clock on again [fact] */
void vdc5_reg_initialize(unsigned ch, const vdc5_init_t *param)
{
    reg16_t panel_clk = vdc5_regaddr_system_ctrl[ch].syscnt_panel_clk;
    const vdc5_lvds_t *lvds;
    volatile uint32_t n;
    uint16_t v;

    *panel_clk &= ~0x100;
    lvds = param->lvds;
    if (lvds != NULL)
    {
        const vdc5_regaddr_lvds_t *r = &vdc5_regaddr_lvds;

        *r->lclkselr &= ~0x10U;    /* LVDS PLL output off */
        *r->lpllsetr |= 1;         /* PLL power-down */
        for (n = 0; n < LVDS_PLL_WAIT_CYCLE; n++)
        {
        }
        *r->lphyacc &= ~3U;        /* LPHYACC: PHY access mode 1 */
        *r->lphyacc |= 1;
        *r->lclkselr &= 0xF8FC00FDU;
        *r->lclkselr |= (uint32_t)lvds->lvds_in_clk_sel << 24;
        *r->lclkselr |= (uint32_t)lvds->lvds_idiv_set << 16;
        *r->lclkselr |= (uint32_t)lvds->lvdspll_tst << 10;
        *r->lclkselr |= (uint32_t)lvds->lvds_odiv_set << 8;
        if (lvds->lvds_vdc_sel != 0)
        {
            *r->lclkselr |= 2;
        }
        *r->lpllsetr &= 0xF800E0CFU;
        *r->lpllsetr |= (uint32_t)lvds->lvdspll_fd << 16;
        *r->lpllsetr |= (uint32_t)lvds->lvdspll_rd << 8;
        *r->lpllsetr |= (uint32_t)lvds->lvdspll_od << 4;
        for (n = 0; n < LVDS_PLL_WAIT_CYCLE; n++)
        {
        }
        *r->lpllsetr &= ~1U;       /* PLL normal operation */
        vdc5_wait_200us();
        *r->lclkselr |= 0x10;      /* LVDS PLL output on */
    }
    if (param->panel_icksel == 1)
    {
        *vdc5_regaddr_input_ctrl[ch].inp_sel_cnt |= 0x100000;
    }
    else
    {
        *vdc5_regaddr_input_ctrl[ch].inp_sel_cnt &= ~0x100000U;
    }
    v = vdc5_panel_dcdr_tbl[param->panel_dcdr] | vdc5_panel_icksel_tbl[param->panel_icksel];
    *panel_clk = v;
    *panel_clk = v | 0x100;
}

/* 0x201195E8: (ch): panel clock off; the LVDS PLL off and powered down once no channel uses it [fact] */
void vdc5_reg_terminate(unsigned ch)
{
    volatile uint32_t n;

    *vdc5_regaddr_system_ctrl[ch].syscnt_panel_clk &= ~0x100;
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_LVDS_CLK) != 0 && vdc5_shrd_get_lvds_clk_ref() == 0)
    {
        *vdc5_regaddr_lvds.lclkselr &= ~0x10U;
        *vdc5_regaddr_lvds.lpllsetr |= 1;
        for (n = 0; n < LVDS_PLL_WAIT_CYCLE; n++)
        {
        }
    }
}

/* 0x20119668: (external signal, input registers): INP_SEL_CNT format (YCbCr444 as RGB888) and edges,
 * INP_EXT_SYNC_CNT endian, swap, polarities, H reference, 525/625 lines, H position [fact] */
void vdc5_set_video_external_input(const vdc5_ext_sig_full_t *sig, const vdc5_regaddr_input_ctrl_t *in)
{
    *in->inp_sel_cnt &= ~0x7111U;
    if (sig->inp_format == 6)
    {
        *in->inp_sel_cnt |= 0;
    }
    else
    {
        *in->inp_sel_cnt |= (uint32_t)sig->inp_format << 12;
    }
    if (sig->inp_pxd_edge != 0)
    {
        *in->inp_sel_cnt |= 0x100;
    }
    if (sig->inp_vs_edge != 0)
    {
        *in->inp_sel_cnt |= 0x10;
    }
    if (sig->inp_hs_edge != 0)
    {
        *in->inp_sel_cnt |= 1;
    }
    *in->inp_ext_sync_cnt &= ~0x11110113U;
    if (sig->inp_endian_on != 0)
    {
        *in->inp_ext_sync_cnt |= 0x10000000;
    }
    if (sig->inp_swap_on != 0)
    {
        *in->inp_ext_sync_cnt |= 0x1000000;
    }
    if (sig->inp_vs_inv != 0)
    {
        *in->inp_ext_sync_cnt |= 0x100000;
    }
    if (sig->inp_hs_inv != 0)
    {
        *in->inp_ext_sync_cnt |= 0x10000;
    }
    if (sig->inp_h_edge_sel != 0)
    {
        *in->inp_ext_sync_cnt |= 0x100;
    }
    if (sig->inp_f525_625 != 0)
    {
        *in->inp_ext_sync_cnt |= 0x10;
    }
    *in->inp_ext_sync_cnt |= sig->inp_h_pos;
}

/* 0x201197C0 (Ghidra: vdc5_reg_terminate): (ch, input): input select (INP_SEL_CNT bit 20 = external), the field
 * frequencies, the sync delays, the noise reducer bypass (IMGCNT_NR_CNT0 bit 20, off for external RGB), the external
 * signal, then INP_UPDATE and IMGCNT_UPDATE [fact] */
void vdc5_reg_video_input(unsigned ch, const vdc5_input_t *param)
{
    const vdc5_regaddr_input_ctrl_t *in = &vdc5_regaddr_input_ctrl[ch];
    const vdc5_sync_delay_t *dly = param->dly;
    const vdc5_ext_sig_full_t *sig;

    if (param->inp_sel == 0)
    {
        *in->inp_sel_cnt &= ~0x100000U;
    }
    else
    {
        *in->inp_sel_cnt |= 0x100000;
    }
    *in->inp_vsync_ph_adj = (uint32_t)param->inp_fh50 << 16;
    *in->inp_vsync_ph_adj |= param->inp_fh25;
    if (dly != NULL)
    {
        *in->inp_dly_adj = (uint32_t)dly->inp_vs_dly_l << 24;
        *in->inp_dly_adj |= (uint32_t)dly->inp_fld_dly << 16;
        *in->inp_dly_adj |= (uint32_t)dly->inp_vs_dly << 8;
        *in->inp_dly_adj |= dly->inp_hs_dly;
    }
    *in->imgcnt_nr_cnt0 |= 0x100000;
    sig = (const vdc5_ext_sig_full_t *)param->ext_sig;
    if (sig != NULL)
    {
        vdc5_set_video_external_input(sig, in);
        if (sig->inp_format <= 2)
        {
            *in->imgcnt_nr_cnt0 &= ~0x100000U;
        }
    }
    *in->inp_update |= 0x11;
    *in->imgcnt_update |= 1;
}

/* 0x201198DC: (ch): the initial layer connection: graphics 1 GR1_AB1 bit 28 (cascade on), VIN layer: lower layer
 * shown (GR_VIN_AB1), its alpha window cleared (AB6) and opaque (AB7), then the updates [fact] */
void vdc5_set_initial_connection(unsigned ch)
{
    const vdc5_regaddr_img_synthesizer_t *gr1 = &vdc5_regaddr_img_synthesizer[ch][1];
    const vdc5_regaddr_img_synthesizer_t *vin = &vdc5_regaddr_img_synthesizer[ch][4];

    *gr1->gr_ab1 |= 0x10000000;
    *gr1->gr_update |= 0x100;
    vdc5_shrd_set_cascade(ch, 1);
    *vin->gr_ab1 &= ~0x1000U;
    *vin->gr_ab1 |= 4;
    *vin->gr_ab1 &= ~3U;
    *vin->gr_ab1 |= 1;
    *vin->gr_ab6 &= 0xFE00FF00U;
    *vin->gr_ab7 |= 0xFF0000;
    *vin->gr_update |= 0x110;
}

/* 0x20119990: (ch, sync): for scalers 0, 1 and the OIR: the V-sync compensation (SCL0_FRC1/2: mask and lack
 * period, or off with the lack at 0xFFFF), the H period (FRC4), free-running V sync (FRC3, FRC4 period) or the
 * input's, scaler 1 on the other channel's sync (FRC3 bit 8), the sync delay (FRC5; 1 for the OIR), the full-screen
 * area (FRC6/7), the updates; then the initial layer connection and und_sel off [fact] */
void vdc5_reg_sync_control(unsigned ch, const vdc5_sync_ctrl_t *param)
{
    const vdc5_regaddr_scaler_t *s0 = &vdc5_regaddr_scaler[ch][0];
    const vdc5_regaddr_scaler_t *s1 = &vdc5_regaddr_scaler[ch][1];
    const vdc5_regaddr_scaler_t *so = &vdc5_regaddr_scaler[ch][2];
    uint32_t full;

    if (param->vsync_cpmpe != NULL)
    {
        *s0->scl0_frc1 = (uint32_t)param->vsync_cpmpe->res_vmask << 16;
        *s1->scl0_frc1 = (uint32_t)param->vsync_cpmpe->res_vmask << 16;
        *s0->scl0_frc2 = (uint32_t)param->vsync_cpmpe->res_vlack << 16;
        *s1->scl0_frc2 = (uint32_t)param->vsync_cpmpe->res_vlack << 16;
        *s0->scl0_frc1 |= 1;
        *s1->scl0_frc1 |= 1;
        *s0->scl0_frc2 |= 1;
        *s1->scl0_frc2 |= 1;
    }
    else
    {
        *s0->scl0_frc1 &= ~1U;
        *s1->scl0_frc1 &= ~1U;
        *s0->scl0_frc2 &= ~1U;
        *s0->scl0_frc2 |= 0xFFFF0000U;
        *s1->scl0_frc2 &= ~1U;
        *s1->scl0_frc2 |= 0xFFFF0000U;
    }
    *so->scl0_frc1 &= ~1U;
    *so->scl0_frc2 &= ~1U;
    *s0->scl0_frc4 = param->res_fh;
    *s1->scl0_frc4 = param->res_fh;
    *so->scl0_frc4 = param->res_fh;
    if (param->res_vs_sel == 0)
    {
        *s0->scl0_frc3 &= ~1U;
        *s1->scl0_frc3 &= ~1U;
    }
    else
    {
        *s0->scl0_frc3 |= 1;
        *s1->scl0_frc3 |= 1;
        *s0->scl0_frc4 &= ~0x07FF0000U;
        *s0->scl0_frc4 |= (uint32_t)param->res_fv << 16;
        *s1->scl0_frc4 &= ~0x07FF0000U;
        *s1->scl0_frc4 |= (uint32_t)param->res_fv << 16;
    }
    *so->scl0_frc3 &= ~1U;
    *s0->scl0_frc3 &= ~0x100U;
    *s1->scl0_frc3 |= 0x100;
    *s0->scl0_frc5 &= ~0xFFU;
    *s0->scl0_frc5 |= param->res_vsdly;
    *s1->scl0_frc5 &= ~0xFFU;
    *s1->scl0_frc5 |= param->res_vsdly;
    *so->scl0_frc5 &= ~0xFFU;
    *so->scl0_frc5 |= 1;
    full = ((uint32_t)param->res_f.vs << 16) | param->res_f.vw;
    *s0->scl0_frc6 = full;
    *s1->scl0_frc6 = full;
    *so->scl0_frc6 = full;
    full = ((uint32_t)param->res_f.hs << 16) | param->res_f.hw;
    *s0->scl0_frc7 = full;
    *s1->scl0_frc7 = full;
    *so->scl0_frc7 = full;
    *s0->scl0_update |= 0x110;
    *s1->scl0_update |= 0x110;
    *so->scl0_update |= 0x110;
    vdc5_set_initial_connection(ch);
    vdc5_shrd_set_und_sel(ch, 0);
}

/* the LCD output block, one per channel (0x60 bytes) [fact: the offsets vdc5_reg_display_output loads] */
typedef struct
{
    reg32_t tcon_update, tcon_tim, tcon_tim_stva1, tcon_tim_stva2, tcon_tim_stvb1, tcon_tim_stvb2, tcon_tim_sth1,
        tcon_tim_sth2, tcon_tim_stb1, tcon_tim_stb2, tcon_tim_cpv1, tcon_tim_cpv2, tcon_tim_pola1, tcon_tim_pola2,
        tcon_tim_polb1, tcon_tim_polb2, tcon_tim_de, out_update, out_set, out_bright1, out_bright2, out_contrast,
        out_pdtha, out_clk_phase;
} vdc5_regaddr_output_ctrl_t;

extern const vdc5_regaddr_output_ctrl_t vdc5_regaddr_output_ctrl[VDC5_CHANNEL_NUM];   /* 0x20166710 */

/* one TCON signal's timing (vdc5_lcd_tcon_timing_t) */
typedef struct
{
    uint16_t tcon_hsvs, tcon_hwvw;
    uint8_t tcon_md, tcon_hs_sel, tcon_inv;
    int8_t tcon_pin;           /* +7: output pin 0..6, -1 none */
    uint8_t outcnt_edge;       /* +8 */
} vdc5_lcd_tcon_timing_t;

typedef struct
{
    uint16_t tcon_half, tcon_offset;
    const vdc5_lcd_tcon_timing_t *outctrl[8];   /* +4: STVA, STVB, STH, STB, CPV, POLA, POLB, DE */
    uint8_t outcnt_lcd_edge;   /* +0x24 */
    uint8_t out_endian_on, out_swap_on, out_format, out_frq_sel, out_dir_sel, out_phase;
    uint32_t bg_color;         /* +0x2C */
} vdc5_output_full_t;

/* 0x2011CA00 .. 0x2011CD0F: the eight TCON signal set-ups: start/width (TCON_TIMx1), and in TCON_TIMx2 the
 * polarity (bit 4), the reference (bit 8: H sync or not) and for POLA/POLB the mode (bits 13..12) [fact] */
void vdc5_tcon_stva(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    *o->tcon_tim_stva1 = (uint32_t)t->tcon_hsvs << 16;
    *o->tcon_tim_stva1 |= t->tcon_hwvw;
    if (t->tcon_inv == 0)
    {
        *o->tcon_tim_stva2 &= ~0x10U;
    }
    else
    {
        *o->tcon_tim_stva2 |= 0x10;
    }
}

void vdc5_tcon_stvb(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    *o->tcon_tim_stvb1 = (uint32_t)t->tcon_hsvs << 16;
    *o->tcon_tim_stvb1 |= t->tcon_hwvw;
    if (t->tcon_inv == 0)
    {
        *o->tcon_tim_stvb2 &= ~0x10U;
    }
    else
    {
        *o->tcon_tim_stvb2 |= 0x10;
    }
}

/* STH, STB, CPV: start/width, then reference and polarity */
static inline void vdc5_tcon_h(const vdc5_lcd_tcon_timing_t *t, reg32_t tim1, reg32_t tim2)
{
    *tim1 = (uint32_t)t->tcon_hsvs << 16;
    *tim1 |= t->tcon_hwvw;
    *tim2 &= ~0x110U;
    if (t->tcon_hs_sel != 0)
    {
        *tim2 |= 0x100;
    }
    if (t->tcon_inv != 0)
    {
        *tim2 |= 0x10;
    }
}

void vdc5_tcon_sth(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    vdc5_tcon_h(t, o->tcon_tim_sth1, o->tcon_tim_sth2);
}

void vdc5_tcon_stb(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    vdc5_tcon_h(t, o->tcon_tim_stb1, o->tcon_tim_stb2);
}

void vdc5_tcon_cpv(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    vdc5_tcon_h(t, o->tcon_tim_cpv1, o->tcon_tim_cpv2);
}

/* POLA, POLB: as above with the polarity mode */
static inline void vdc5_tcon_pol(const vdc5_lcd_tcon_timing_t *t, reg32_t tim1, reg32_t tim2)
{
    *tim1 = (uint32_t)t->tcon_hsvs << 16;
    *tim1 |= t->tcon_hwvw;
    *tim2 &= ~0x3110U;
    *tim2 |= (uint32_t)t->tcon_md << 12;
    if (t->tcon_hs_sel != 0)
    {
        *tim2 |= 0x100;
    }
    if (t->tcon_inv != 0)
    {
        *tim2 |= 0x10;
    }
}

void vdc5_tcon_pola(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    vdc5_tcon_pol(t, o->tcon_tim_pola1, o->tcon_tim_pola2);
}

void vdc5_tcon_polb(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    vdc5_tcon_pol(t, o->tcon_tim_polb1, o->tcon_tim_polb2);
}

/* DE: only its polarity */
void vdc5_tcon_de(const vdc5_lcd_tcon_timing_t *t, const vdc5_regaddr_output_ctrl_t *o)
{
    *o->tcon_tim_de = (t->tcon_inv == 0) ? 0 : 1;
}

/* 0x20119DB8: 0x00RRGGBB (and alpha in bits 31..24) to the GR_BASE order 0x00GGBBRR [fact] */
uint32_t vdc5_color_to_agbr(uint32_t c)
{
    return ((c << 8) & 0xFFFF00) | (c & 0xFF000000) | ((c >> 16) & 0xFF);
}

/* 0x20119DD4: (ch): the background colour into graphics 2, 3, VIN, OIR (GR_BASE, P_VEN) and the OIR scaler
 * (SCL0_OVR1, VEN_B) [fact] */
void vdc5_set_graphics_background_color(unsigned ch)
{
    uint32_t rgb = vdc5_shrd_get_bg_color(ch, 0);
    uint32_t agbr = vdc5_color_to_agbr(rgb) & 0xFFFFFF;
    unsigned gr;

    for (gr = 2; gr < VDC5_GR_TYPE_NUM; gr = (gr + 1) & 0xFF)
    {
        *vdc5_regaddr_img_synthesizer[ch][gr].gr_base = agbr;
        *vdc5_regaddr_img_synthesizer[ch][gr].gr_update |= 0x10;
    }
    *vdc5_regaddr_scaler[ch][2].scl0_ovr1 = rgb;
    *vdc5_regaddr_scaler[ch][2].scl0_update |= 0x10;
}

/* 0x20119CD0: (ch, layer or -1, display selections): GRx_AB1 DISP_SEL of one read layer (3..8) or of every
 * graphics but VIN, skipping -1 entries [fact] */
void vdc5_set_graphics_display_mode(unsigned ch, int layer, const int8_t *sel)
{
    const vdc5_regaddr_img_synthesizer_t *g;
    unsigned gr;

    if (layer == VDC5_LAYER_ID_ALL)
    {
        for (gr = 0; gr < VDC5_GR_TYPE_NUM; gr++)
        {
            if (gr != 4 && sel[gr] != -1)
            {
                g = &vdc5_regaddr_img_synthesizer[ch][gr];
                *g->gr_ab1 &= ~3U;
                *g->gr_ab1 |= sel[gr];
                *g->gr_update |= 0x10;
            }
        }
    }
    else if ((unsigned)(layer - 3) <= 5 && *sel != -1)
    {
        g = &vdc5_regaddr_img_synthesizer[ch][layer - 3];
        *g->gr_ab1 &= ~3U;
        *g->gr_ab1 |= *sel;
        *g->gr_update |= 0x10;
    }
}

typedef void (*vdc5_tcon_fn)(const vdc5_lcd_tcon_timing_t *, const vdc5_regaddr_output_ctrl_t *);

/* 0x20119E60: (ch, output): TCON half and offset, each given TCON signal on its pin (TCON_TIMx2 bits 2..0) with
 * its clock edge (OUT_CLK_PHASE, bits 6..0 for pins 0..6), endian, swap, format, dither (OUT_PDTHA), serial RGB
 * clock and scan, the LCD clock edge, the background colour, the default display selections (graphics 0 and OIR
 * background, 1..3 lower layer), then TCON_UPDATE and OUT_UPDATE [fact] */
void vdc5_reg_display_output(unsigned ch, const vdc5_output_t *param_)
{
    static const vdc5_tcon_fn tcon_fn[8] = {vdc5_tcon_stva, vdc5_tcon_stvb, vdc5_tcon_sth, vdc5_tcon_stb,
                                            vdc5_tcon_cpv, vdc5_tcon_pola, vdc5_tcon_polb, vdc5_tcon_de};
    static const uint32_t pin_edge[7] = {0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    static const uint32_t dither_format[4] = {0, 0x10000, 0x20000, 0};
    static const int8_t disp_sel[8] = {0, 1, 1, 1, -1, 0};
    const vdc5_output_full_t *param = (const vdc5_output_full_t *)param_;
    const vdc5_regaddr_output_ctrl_t *o = &vdc5_regaddr_output_ctrl[ch];
    reg32_t pin_reg[7];
    unsigned i;

    *o->tcon_tim = (uint32_t)param->tcon_half << 16;
    *o->tcon_tim |= param->tcon_offset;
    pin_reg[0] = o->tcon_tim_stva2;
    pin_reg[1] = o->tcon_tim_stvb2;
    pin_reg[2] = o->tcon_tim_sth2;
    pin_reg[3] = o->tcon_tim_stb2;
    pin_reg[4] = o->tcon_tim_cpv2;
    pin_reg[5] = o->tcon_tim_pola2;
    pin_reg[6] = o->tcon_tim_polb2;
    *o->out_clk_phase &= ~0x7FU;
    for (i = 0; i < 8; i++)
    {
        const vdc5_lcd_tcon_timing_t *t = param->outctrl[i];

        if (t != NULL)
        {
            tcon_fn[i](t, o);
            if (param->outctrl[i]->tcon_pin != -1)
            {
                int pin = param->outctrl[i]->tcon_pin;

                *pin_reg[pin] &= ~7U;
                *pin_reg[pin] |= i;
                if (param->outctrl[i]->outcnt_edge != 0)
                {
                    *o->out_clk_phase |= pin_edge[pin];
                }
            }
        }
    }
    *o->out_set &= ~0x11003313U;
    if (param->out_endian_on != 0)
    {
        *o->out_set |= 0x10000000;
    }
    if (param->out_swap_on != 0)
    {
        *o->out_set |= 0x1000000;
    }
    *o->out_set |= (uint32_t)param->out_format << 12;
    *o->out_pdtha &= ~0x30000U;
    *o->out_pdtha |= dither_format[param->out_format];
    if (param->out_format == 3)
    {
        *o->out_set |= (uint32_t)param->out_frq_sel << 8;
        if (param->out_dir_sel != 0)
        {
            *o->out_set |= 0x10;
        }
        *o->out_set |= param->out_phase;
    }
    else
    {
        *o->out_set |= 0;
    }
    if (param->outcnt_lcd_edge == 0)
    {
        *o->out_clk_phase &= ~0x100U;
    }
    else
    {
        *o->out_clk_phase |= 0x100;
    }
    vdc5_set_graphics_background_color(ch);
    vdc5_set_graphics_display_mode(ch, VDC5_LAYER_ID_ALL, disp_sel);
    *o->tcon_update |= 1;
    *o->out_update |= 1;
}

/* the colour-matrix block (0x20 bytes; three per channel: input, graphics 0, graphics 1) */
typedef struct
{
    reg32_t mtx_update, mtx_mode, mtx_yg_adj0, mtx_yg_adj1, mtx_cbb_adj0, mtx_cbb_adj1, mtx_crr_adj0, mtx_crr_adj1;
} vdc5_regaddr_color_matrix_t;

extern const vdc5_regaddr_color_matrix_t vdc5_regaddr_color_matrix[VDC5_CHANNEL_NUM][3];   /* 0x20166200 */
/* the colour-matrix offsets (YG, B, R) and, after them, the nine gains of each of the four conversion modes
 * (GBR->GBR, GBR->YCbCr, YCbCr->GBR, YCbCr->YCbCr) [fact: 0x2011A258, 0x20165B88 + 6 + 18 mode] */
extern const uint16_t vdc5_colormtx_offset_adj[3];   /* 0x20165B88 */
#define vdc5_colormtx_gain_adj(mode) (vdc5_colormtx_offset_adj + 3 + 9 * (mode))

uint8_t vdc5_shrd_get_color_space(unsigned ch);
uint8_t vdc5_shrd_get_color_space_fb_wr(unsigned ch, unsigned sc);
void r_vdc5_shrd_rw_enable(unsigned ch, int layer);
void r_vdc5_shrd_rw_disable(unsigned ch, int layer);

/* 0x2011A110: (mode, offsets, gains, matrix registers): MTX_MODE, the three offset/gain pairs and the six other
 * gains, then MTX_UPDATE [fact] */
void vdc5_set_color_matrix(unsigned mode, const uint16_t *offset, const uint16_t *gain,
                           const vdc5_regaddr_color_matrix_t *m)
{
    *m->mtx_mode = mode;
    *m->mtx_yg_adj0 = (uint32_t)offset[0] << 16;
    *m->mtx_yg_adj0 |= gain[0];
    *m->mtx_yg_adj1 = (uint32_t)gain[1] << 16;
    *m->mtx_yg_adj1 |= gain[2];
    *m->mtx_cbb_adj0 = (uint32_t)offset[1] << 16;
    *m->mtx_cbb_adj0 |= gain[3];
    *m->mtx_cbb_adj1 = (uint32_t)gain[4] << 16;
    *m->mtx_cbb_adj1 |= gain[5];
    *m->mtx_crr_adj0 = (uint32_t)offset[2] << 16;
    *m->mtx_crr_adj0 |= gain[6];
    *m->mtx_crr_adj1 = (uint32_t)gain[7] << 16;
    *m->mtx_crr_adj1 |= gain[8];
    *m->mtx_update |= 1;
}

/* 0x2011A20C (not in Ghidra's function list): (ch, scaler): the input controller's matrix converts from the input's
 * colour space to that of the frame buffer the scaler writes; scaler 1 takes the other channel's input [fact] */
void vdc5_set_input_cntrl_color_mtx(unsigned ch, unsigned sc)
{
    unsigned in_ch = (sc == 0) ? ch : (ch == 0 ? 1 : 0);
    unsigned in_sp = vdc5_shrd_get_color_space(in_ch);
    unsigned wr_sp = vdc5_shrd_get_color_space_fb_wr(ch, sc);
    unsigned mode;

    if (in_sp != 0)
    {
        mode = (wr_sp == 0) ? 2 : 3;
    }
    else
    {
        mode = (wr_sp != 0) ? 1 : 0;
    }
    vdc5_set_color_matrix(mode, vdc5_colormtx_offset_adj, vdc5_colormtx_gain_adj(mode),
                          &vdc5_regaddr_color_matrix[in_ch][0]);
}

/* 0x2011A800: (ch, graphics 0/1, colour space): the graphics layer's matrix to GBR, from GBR or from YCbCr [fact] */
void vdc5_set_img_qa_improver_color_mtx(unsigned ch, unsigned gr, unsigned color_space)
{
    unsigned mode = (color_space == 0) ? 0 : 2;

    vdc5_set_color_matrix(mode, vdc5_colormtx_offset_adj, vdc5_colormtx_gain_adj(mode),
                          &vdc5_regaddr_color_matrix[ch][gr == 0 ? 1 : 2]);
}

/* 0x2011CD10 .. 0x2011D07F: the per-layer start/stop functions of the table 0x20165BD8 [fact: the table words].
 * Write layers: SCL1_WR5 bit 0, and for scalers 0 and 1 a pulse of SCL1_PBUF_CNT bit 16 (buffer reset) with
 * read-backs; read layers: GRx_FLM_RD bit 0, and when stopping the layer shows the background (graphics 0, OIR)
 * or the lower layer [fact] */
static inline void vdc5_rw_write_scaler(unsigned ch, unsigned sc, unsigned on)
{
    const vdc5_regaddr_scaler_t *s = &vdc5_regaddr_scaler[ch][sc];
    volatile uint32_t dummy;

    if (on == 0)
    {
        *s->scl1_wr5 &= ~1U;
        r_vdc5_shrd_rw_disable(ch, sc);
        return;
    }
    *s->scl1_wr5 |= 1;
    if (sc != VDC5_SC_TYPE_OIR)
    {
        *s->scl1_pbuf_cnt |= 0x10000;
        dummy = *s->scl1_pbuf_cnt;
        *s->scl1_pbuf_cnt &= ~0x10000U;
        dummy = *s->scl1_pbuf_cnt;
        (void)dummy;
    }
    r_vdc5_shrd_rw_enable(ch, sc);
}

void vdc5_rw_write_0(unsigned ch, unsigned on)
{
    vdc5_rw_write_scaler(ch, 0, on);
}

void vdc5_rw_write_1(unsigned ch, unsigned on)
{
    vdc5_rw_write_scaler(ch, 1, on);
}

void vdc5_rw_write_oir(unsigned ch, unsigned on)
{
    vdc5_rw_write_scaler(ch, 2, on);
}

static inline void vdc5_rw_read(unsigned ch, unsigned gr, unsigned on, unsigned stop_sel)
{
    const vdc5_regaddr_img_synthesizer_t *g = &vdc5_regaddr_img_synthesizer[ch][gr];

    if (on == 0)
    {
        *g->gr_flm_rd &= ~1U;
        *g->gr_ab1 &= ~3U;
        *g->gr_ab1 |= stop_sel;
        r_vdc5_shrd_rw_disable(ch, gr + 3);
    }
    else
    {
        *g->gr_flm_rd |= 1;
        r_vdc5_shrd_rw_enable(ch, gr + 3);
    }
}

void vdc5_rw_read_0(unsigned ch, unsigned on)
{
    vdc5_rw_read(ch, 0, on, 0);
}

void vdc5_rw_read_1(unsigned ch, unsigned on)
{
    vdc5_rw_read(ch, 1, on, 1);
}

void vdc5_rw_read_2(unsigned ch, unsigned on)
{
    vdc5_rw_read(ch, 2, on, 1);
}

void vdc5_rw_read_3(unsigned ch, unsigned on)
{
    vdc5_rw_read(ch, 3, on, 1);
}

void vdc5_rw_read_oir(unsigned ch, unsigned on)
{
    vdc5_rw_read(ch, 5, on, 0);
}

typedef void (*vdc5_rw_fn)(unsigned ch, unsigned on);
extern const vdc5_rw_fn vdc5_rw_proc_function_tbl[VDC5_LAYER_ID_NUM];   /* 0x20165BD8; entry 7 (VIN) is NULL */

/* 0x2011D958: 1 if the OIR write or read layer is set up and running [fact] */
int vdc5_shrd_get_oir_rw_proc_enabled(unsigned ch)
{
    int on = 0;

    if (vdc5_layer_resource[ch][2] != 0 && vdc5_rw_proc_state[ch][2] != 0)
    {
        on = 1;
    }
    if (vdc5_layer_resource[ch][8] != 0 && vdc5_rw_proc_state[ch][8] != 0)
    {
        on = 1;
    }
    return on;
}

/* 0x2011B6D8: (ch, layer or -1): the update bits of the layer's block (SCL1_UPDATE: UPDATE_B, VEN_B, VEN_A; the
 * OIR without UPDATE_B; GRx_UPDATE: P_VEN, IBUS_VEN), or of all of them [fact] */
void vdc5_set_reg_update_rw_enable(unsigned ch, int layer)
{
    int gr;

    switch (layer)
    {
    case 0:
    case 1:
        *vdc5_regaddr_scaler[ch][layer].scl1_update |= 0x100011;
        break;
    case 2:
        *vdc5_regaddr_scaler[ch][2].scl1_update |= 0x11;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
        *vdc5_regaddr_img_synthesizer[ch][layer - 3].gr_update |= 0x11;
        break;
    case VDC5_LAYER_ID_ALL:
        *vdc5_regaddr_scaler[ch][0].scl1_update |= 0x100011;
        *vdc5_regaddr_scaler[ch][1].scl1_update |= 0x100011;
        *vdc5_regaddr_scaler[ch][2].scl1_update |= 0x11;
        for (gr = 0; gr < 4; gr++)
        {
            *vdc5_regaddr_img_synthesizer[ch][gr].gr_update |= 0x11;
        }
        *vdc5_regaddr_img_synthesizer[ch][5].gr_update |= 0x11;
        break;
    default:
        break;
    }
}

/* 0x2011B8B8: (ch, layer or -1, {display selection}): the display selection if given, the layer (or every set-up
 * idle layer) started, the updates; the OIR's frame clock (SCL0_FRC3 bit 16) on when the OIR starts [fact] */
void vdc5_reg_start_process(unsigned ch, int layer, const void *param)
{
    const int8_t *const *start = param;
    int before, after;
    unsigned i;

    if (start[0] != NULL)
    {
        vdc5_set_graphics_display_mode(ch, layer, start[0]);
    }
    before = vdc5_shrd_get_oir_rw_proc_enabled(ch);
    if (layer != VDC5_LAYER_ID_ALL)
    {
        vdc5_rw_proc_function_tbl[layer](ch, 1);
    }
    else
    {
        for (i = 0; i < VDC5_LAYER_ID_NUM; i++)
        {
            if (vdc5_shrd_res_idle(ch, (int8_t)i) != 0)
            {
                vdc5_rw_proc_function_tbl[i](ch, 1);
            }
        }
    }
    vdc5_set_reg_update_rw_enable(ch, layer);
    after = vdc5_shrd_get_oir_rw_proc_enabled(ch);
    if (before == 0 && after != 0)
    {
        *vdc5_regaddr_scaler[ch][2].scl0_frc3 |= 0x10000;
        *vdc5_regaddr_scaler[ch][2].scl0_update |= 0x100;
    }
}

/* 0x2011B988: (ch, layer or -1): the layer (or every running layer) stopped, the updates; the OIR's frame clock
 * off when the OIR stops [fact] */
void vdc5_reg_stop_process(unsigned ch, int layer)
{
    int before, after;
    unsigned i;

    before = vdc5_shrd_get_oir_rw_proc_enabled(ch);
    if (layer != VDC5_LAYER_ID_ALL)
    {
        vdc5_rw_proc_function_tbl[layer](ch, 0);
    }
    else
    {
        for (i = 0; i < VDC5_LAYER_ID_NUM; i++)
        {
            if (vdc5_shrd_res_busy(ch, (int8_t)i) != 0)
            {
                vdc5_rw_proc_function_tbl[i](ch, 0);
            }
        }
    }
    vdc5_set_reg_update_rw_enable(ch, layer);
    after = vdc5_shrd_get_oir_rw_proc_enabled(ch);
    if (before != 0 && after == 0)
    {
        *vdc5_regaddr_scaler[ch][2].scl0_frc3 &= ~0x10000U;
        *vdc5_regaddr_scaler[ch][2].scl0_update |= 0x100;
    }
}

/* 0x2011BA48: (ch, layer or -1): releasing graphics 1 restores the initial connection, scaler 0/1 syncs and the
 * graphics 1 matrix; releasing graphics 0 restores the VIN layer [fact] */
void vdc5_reg_release_data_control(unsigned ch, int layer)
{
    int idle = vdc5_shrd_res_idle(ch, 4);

    if (layer == 4 || (layer == VDC5_LAYER_ID_ALL && idle != 0))
    {
        vdc5_set_initial_connection(ch);
        *vdc5_regaddr_scaler[ch][0].scl0_frc3 &= ~0x100U;
        *vdc5_regaddr_scaler[ch][0].scl0_update |= 0x100;
        *vdc5_regaddr_scaler[ch][1].scl0_frc3 |= 0x100;
        *vdc5_regaddr_scaler[ch][1].scl0_update |= 0x100;
        vdc5_set_img_qa_improver_color_mtx(ch, 1, 0);
    }
    idle = vdc5_shrd_res_idle(ch, 3);
    if (layer == 3 || (layer == VDC5_LAYER_ID_ALL && idle != 0))
    {
        const vdc5_regaddr_img_synthesizer_t *vin = &vdc5_regaddr_img_synthesizer[ch][4];

        *vin->gr_ab1 &= ~0x1000U;
        *vin->gr_ab1 |= 4;
        *vin->gr_ab1 &= ~3U;
        *vin->gr_ab1 |= 1;
        *vin->gr_ab6 &= 0xFE00FF00U;
        *vin->gr_ab7 |= 0xFF0000;
        *vin->gr_update |= 0x110;
    }
}

/* the image-quality improver block (0x34 bytes; two per channel, for graphics 0 and 1) */
typedef struct
{
    reg32_t adj_update, adj_bkstr_set, adj_enh_tim1, adj_enh_tim2, adj_enh_tim3, adj_enh_shp1, adj_enh_shp2,
        adj_enh_shp3, adj_enh_shp4, adj_enh_shp5, adj_enh_shp6, adj_enh_lti1, adj_enh_lti2;
} vdc5_regaddr_img_qlty_imp_t;

extern const vdc5_regaddr_img_qlty_imp_t vdc5_regaddr_img_qlty_imp[VDC5_CHANNEL_NUM][2];   /* 0x20166130 */

typedef struct
{
    uint8_t nr1d_tap;
    uint32_t nr1d_th;
    uint8_t nr1d_gain;
} vdc5_nr_param_t;

/* 0x2011BB84: (ch, on, {Y, Cb, Cr}): the 1-D noise reducer's tap, threshold and gain per component
 * (IMGCNT_NR_CNT0/1), on/off (NR_CNT0 bit 16), IMGCNT_UPDATE [fact] */
void vdc5_reg_video_noise_reduction(unsigned ch, unsigned on, const void *param_)
{
    const vdc5_nr_param_t *nr = param_;
    const vdc5_regaddr_input_ctrl_t *in = &vdc5_regaddr_input_ctrl[ch];

    if (nr != NULL)
    {
        *in->imgcnt_nr_cnt0 &= ~0x7F33U;
        *in->imgcnt_nr_cnt0 |= nr[0].nr1d_th << 8;
        *in->imgcnt_nr_cnt0 |= (uint32_t)nr[0].nr1d_tap << 4;
        *in->imgcnt_nr_cnt0 |= nr[0].nr1d_gain;
        *in->imgcnt_nr_cnt1 = nr[1].nr1d_th << 24;
        *in->imgcnt_nr_cnt1 |= (uint32_t)nr[1].nr1d_tap << 20;
        *in->imgcnt_nr_cnt1 |= (uint32_t)nr[1].nr1d_gain << 16;
        *in->imgcnt_nr_cnt1 |= nr[2].nr1d_th << 8;
        *in->imgcnt_nr_cnt1 |= (uint32_t)nr[2].nr1d_tap << 4;
        *in->imgcnt_nr_cnt1 |= nr[2].nr1d_gain;
    }
    if (on == 0)
    {
        *in->imgcnt_nr_cnt0 &= ~0x10000U;
    }
    else
    {
        *in->imgcnt_nr_cnt0 |= 0x10000;
    }
    *in->imgcnt_update |= 1;
}

typedef struct
{
    uint8_t module, mtx_mode;
    uint16_t offset[3];        /* +2 */
    uint16_t gain[9];          /* +8 */
} vdc5_color_matrix_t;

/* 0x2011BC8C: (ch, matrix): one colour matrix as given [fact] */
void vdc5_reg_image_color_matrix(unsigned ch, const void *param_)
{
    const vdc5_color_matrix_t *m = param_;

    vdc5_set_color_matrix(m->mtx_mode, m->offset, m->gain, &vdc5_regaddr_color_matrix[ch][m->module]);
}

typedef struct
{
    uint16_t bkstr_st, bkstr_d, bkstr_t1, bkstr_t2;
} vdc5_black_t;

/* 0x2011BFC4: (ch, block 0/1, on, levels): black stretch levels (ADJ_BKSTR_SET), on/off (bit 24), ADJ_UPDATE
 * [fact] */
void vdc5_reg_image_black_stretch(unsigned ch, unsigned id, unsigned on, const void *param_)
{
    const vdc5_black_t *b = param_;
    const vdc5_regaddr_img_qlty_imp_t *q = &vdc5_regaddr_img_qlty_imp[ch][id];

    if (b != NULL)
    {
        *q->adj_bkstr_set = (uint32_t)b->bkstr_st << 20;
        *q->adj_bkstr_set |= (uint32_t)b->bkstr_d << 16;
        *q->adj_bkstr_set |= (uint32_t)b->bkstr_t1 << 8;
        *q->adj_bkstr_set |= b->bkstr_t2;
    }
    if (on == 0)
    {
        *q->adj_bkstr_set &= ~0x1000000U;
    }
    else
    {
        *q->adj_bkstr_set |= 0x1000000;
    }
    *q->adj_update |= 1;
}

typedef struct
{
    const uint8_t *alpha_1bit;    /* {gr_a0, gr_a1}: alpha of the two ARGB1555 levels */
    const uint8_t *alpha_pixel;   /* {gr_acalc_md}: premultiplied alpha */
} vdc5_alpha_blending_t;

/* 0x2011C068: (ch, graphics, alpha): the ARGB1555 alpha values (GRx_AB10/11 bits 31..24), the per-pixel alpha
 * mode (GRx_AB1 bit 14), P_VEN [fact] */
void vdc5_reg_alpha_blending(unsigned ch, unsigned gr, const void *param_)
{
    const vdc5_alpha_blending_t *a = param_;
    const vdc5_regaddr_img_synthesizer_t *g = &vdc5_regaddr_img_synthesizer[ch][gr];

    if (a->alpha_1bit != NULL)
    {
        *g->gr_ab10 &= ~0xFF000000U;
        *g->gr_ab10 |= (uint32_t)a->alpha_1bit[0] << 24;
        *g->gr_ab11 &= ~0xFF000000U;
        *g->gr_ab11 |= (uint32_t)a->alpha_1bit[1] << 24;
    }
    if (a->alpha_pixel != NULL)
    {
        if (a->alpha_pixel[0] == 0)
        {
            *g->gr_ab1 &= ~0x4000U;
        }
        else
        {
            *g->gr_ab1 |= 0x4000;
        }
    }
    *g->gr_update |= 0x10;
}

typedef struct
{
    uint8_t route;                         /* 0: brightness, contrast, gamma; 1: gamma first */
    const uint16_t *bright;                /* +4: {G, B, R} */
    const uint8_t *contrast;               /* +8: {G, B, R} */
    const uint8_t *panel_dither;           /* +0xC: {mode, pa, pb, pc, pd} */
} vdc5_disp_calibration_t;

/* 0x2011C6EC: (ch, calibration): the correction order (OUT_CLK_PHASE bit 12), brightness (OUT_BRIGHT1/2),
 * contrast (OUT_CONTRAST), the panel dither mode and, for 2x2 dither (mode 2), its pattern (OUT_PDTHA), OUT_UPDATE
 * [fact] */
void vdc5_reg_display_calibration(unsigned ch, const void *param_)
{
    const vdc5_disp_calibration_t *c = param_;
    const vdc5_regaddr_output_ctrl_t *o = &vdc5_regaddr_output_ctrl[ch];

    if (c->route == 0)
    {
        *o->out_clk_phase &= ~0x1000U;
    }
    else
    {
        *o->out_clk_phase |= 0x1000;
    }
    if (c->bright != NULL)
    {
        *o->out_bright1 = c->bright[0];
        *o->out_bright2 = (uint32_t)c->bright[1] << 16;
        *o->out_bright2 |= c->bright[2];
    }
    if (c->contrast != NULL)
    {
        *o->out_contrast = (uint32_t)c->contrast[0] << 16;
        *o->out_contrast |= (uint32_t)c->contrast[1] << 8;
        *o->out_contrast |= c->contrast[2];
    }
    if (c->panel_dither != NULL)
    {
        const uint8_t *d = c->panel_dither;

        *o->out_pdtha &= ~0x300000U;
        *o->out_pdtha |= (uint32_t)d[0] << 20;
        if (d[0] == 2)
        {
            *o->out_pdtha &= ~0x3333U;
            *o->out_pdtha |= (uint32_t)d[1] << 12;
            *o->out_pdtha |= (uint32_t)d[2] << 8;
            *o->out_pdtha |= (uint32_t)d[3] << 4;
            *o->out_pdtha |= d[4];
        }
    }
    *o->out_update |= 1;
}
