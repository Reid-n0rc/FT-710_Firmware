/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 driver's shared parameters, 0x2011D080..0x2011D957, recreated from the image.
 *
 * The parameters one API call records for later calls (the r_vdc5_shared_param part of the Renesas driver
 * [inference: include/vdc5.h]): the per-channel common block, three scaler and six graphics blocks per channel, the
 * resource states and the layer states. Everything here is plain memory; no register is touched.
 *
 * Ghidra calls two of these by other names (src/display/aliases.tsv): vdc5_shrd_get_state is the driver's
 * "get resource" by type and r_vdc5_shrd_get_resource its "get layer resource"; the names stay so that the image's
 * symbols resolve.
 */
#include "vdc5.h"

/* 0x2011D080: (ch): every layer invalid and idle, common defaults (peripheral clock 4, cascade on), the input
 * colour space and select only while no video input was set, all scaler and graphics blocks cleared with frame
 * number addressing, no LVDS channel (2) [fact: the stores] */
void vdc5_shrd_init(unsigned ch)
{
    vdc5_shrd_common_t *c;
    int i;

    for (i = 0; i < VDC5_LAYER_ID_NUM; i++)
    {
        vdc5_layer_resource[ch][i] = 0;
        vdc5_rw_proc_state[ch][i] = 0;
    }
    c = &vdc5_shrd_common[ch];
    c->panel_icksel = 4;
    c->lvds_ref = 0;
    c->res_vs_in_sel = 0;
    c->cascade = 1;
    c->und_sel = 0;
    c->bg_color_rgb = 0;
    c->bg_color_crycb = 0;
    if (vdc5_video_input_flag[ch] == 0)
    {
        c->color_sp_in = 0;
        c->inp_sel = 0;
    }
    for (i = 0; i < VDC5_SC_TYPE_NUM; i++)
    {
        vdc5_shrd_scaling_t *s = &vdc5_shrd_scaling[ch][i];

        s->res_ds_wr_md = 0;
        s->res_inter = 0;
        s->color_sp_fb_wr = 0;
        s->btm_base = NULL;
        s->width_wr_fb.in_vw = 0;
        s->width_wr_fb.in_hw = 0;
    }
    for (i = 0; i < VDC5_GR_TYPE_NUM; i++)
    {
        vdc5_shrd_graphics_t *g = &vdc5_shrd_graphics[ch][i];

        g->gr_ln_off_dir = 0;
        g->gr_flm_sel = 1;
        g->gr_format = 0;
        g->color_sp_fb_rd = 0;
        g->adj_sel = 0;
        g->gr_grc.vs = 0;
        g->gr_grc.vw = 0;
        g->gr_grc.hs = 0;
        g->gr_grc.hw = 0;
        g->width_read_fb.in_vw = 0;
        g->width_read_fb.in_hw = 0;
    }
    vdc5_lvds_vdc_sel_ch = VDC5_CHANNEL_NUM;
}

/* 0x2011D19C: (ch, init): panel clock select; the LVDS PLL is referred to for select 5 or 6; the LVDS channel from
 * the LVDS block if there is one [fact] */
void vdc5_shrd_set_init_param(unsigned ch, const vdc5_init_t *param)
{
    vdc5_shrd_common_t *c = &vdc5_shrd_common[ch];

    c->panel_icksel = param->panel_icksel;
    if (param->panel_icksel == 5 || param->panel_icksel == 6)
    {
        c->lvds_ref = 1;
    }
    if (param->lvds != NULL)
    {
        vdc5_lvds_vdc_sel_ch = param->lvds->lvds_vdc_sel;
    }
}

/* 0x2011D1E0: (ch): the channel no longer refers to the LVDS PLL [fact] */
void vdc5_shrd_set_terminate(unsigned ch)
{
    vdc5_shrd_common[ch].lvds_ref = 0;
}

/* 0x2011D1F4 (Ghidra: vdc5_shrd_terminate): (ch, input): marks the video input as set; YCbCr for the video decoder
 * and for external YCbCr formats, GBR for external RGB888/666/565 (formats 0..2) [fact] */
void vdc5_shrd_set_input_param(unsigned ch, const vdc5_input_t *param)
{
    vdc5_shrd_common_t *c;

    vdc5_video_input_flag[ch] = 1;
    c = &vdc5_shrd_common[ch];
    if (param->inp_sel != 0 && param->ext_sig->inp_format <= 2)
    {
        c->color_sp_in = 0;
    }
    else
    {
        c->color_sp_in = 1;
    }
    c->inp_sel = param->inp_sel;
}

/* 0x2011D248: (ch, sync): the sync signal source [fact] */
void vdc5_shrd_set_sync_param(unsigned ch, const vdc5_sync_ctrl_t *param)
{
    vdc5_shrd_common[ch].res_vs_in_sel = param->res_vs_in_sel;
}

/* 0x2011D25C: one colour component from RGB with 11-bit two's-complement coefficients in 1/256, plus an offset,
 * clamped to 0..255 [fact] */
static int vdc5_sum_product(int red, int green, int blue, int coeff_r, int coeff_g, int coeff_b, int offset)
{
    int v;

    if (coeff_r >= 0x400)
    {
        coeff_r -= 0x800;
    }
    if (coeff_g >= 0x400)
    {
        coeff_g -= 0x800;
    }
    if (coeff_b >= 0x400)
    {
        coeff_b -= 0x800;
    }
    v = red * coeff_r + green * coeff_g + blue * coeff_b;
    v = v / 256 + offset;
    if (v < 0)
    {
        v = 0;
    }
    else if (v > 255)
    {
        v = 255;
    }
    return v;
}

/* 0x2011D2B4: (ch, output): the background colour as RGB and as CrYCb (BT.601: Y = 77 R + 150 G + 29 B,
 * Cb and Cr with offset 128) [fact: the coefficients passed to vdc5_sum_product] */
void vdc5_shrd_set_output_param(unsigned ch, const vdc5_output_t *param)
{
    vdc5_shrd_common_t *c = &vdc5_shrd_common[ch];
    int r, g, b, y, cb, cr;

    c->bg_color_rgb = param->bg_color;
    r = (param->bg_color >> 16) & 0xFF;
    g = (param->bg_color >> 8) & 0xFF;
    b = param->bg_color & 0xFF;
    y = vdc5_sum_product(r, g, b, 0x4D, 0x96, 0x1D, 0);
    cb = vdc5_sum_product(r, g, b, 0x7D5, 0x7AB, 0x80, 0x80);
    cr = vdc5_sum_product(r, g, b, 0x80, 0x795, 0x7EB, 0x80);
    c->bg_color_crycb = ((uint32_t)cr << 16) | ((uint32_t)y << 8) | (uint32_t)cb;
}

/* 0x2011D374: (ch, scaler, write): writing mode and field mode (fixed for the OIR), the frame buffer's colour space
 * (YCbCr for res_md 0 and 3), the bottom-field buffer and the written image size [fact] */
void vdc5_shrd_set_write_param(unsigned ch, unsigned sc, const vdc5_write_t *param)
{
    vdc5_shrd_scaling_t *s = &vdc5_shrd_scaling[ch][sc];

    if (sc == VDC5_SC_TYPE_OIR)
    {
        s->res_ds_wr_md = 0;
        s->res_inter = 0;
    }
    else
    {
        s->res_ds_wr_md = param->scalingdown_rot.res_ds_wr_md;
        s->res_inter = param->res_inter;
    }
    s->color_sp_fb_wr = (param->res_md == 0 || param->res_md == 3) ? 1 : 0;
    s->btm_base = param->btm_base;
    if (sc == VDC5_SC_TYPE_OIR)
    {
        s->width_wr_fb.in_vw = param->scalingdown_rot.res.vw;
        s->width_wr_fb.in_hw = param->scalingdown_rot.res.hw;
    }
    else
    {
        s->width_wr_fb.in_vw = param->scalingdown_rot.res_out_vw;
        s->width_wr_fb.in_hw = param->scalingdown_rot.res_out_hw;
    }
}

/* 0x2011D3F0: (ch, scaler, scaling-down parameters): as above for a running write [fact] */
void vdc5_shrd_set_chg_write_param(unsigned ch, unsigned sc, const vdc5_scalingdown_rot_t *param)
{
    vdc5_shrd_scaling_t *s = &vdc5_shrd_scaling[ch][sc];

    if (sc != VDC5_SC_TYPE_OIR)
    {
        s->res_ds_wr_md = param->res_ds_wr_md;
        s->width_wr_fb.in_vw = param->res_out_vw;
        s->width_wr_fb.in_hw = param->res_out_hw;
    }
    else
    {
        s->width_wr_fb.in_vw = param->res.vw;
        s->width_wr_fb.in_hw = param->res.hw;
    }
}

/* the image copies a rectangle as four halfwords [fact: ldrh/strh at 0x2011D488..0x2011D4A4] */
static inline void vdc5_rect_copy(vdc5_period_rect_t *d, const vdc5_period_rect_t *s)
{
    d->vs = s->vs;
    d->vw = s->vw;
    d->hs = s->hs;
    d->hw = s->hw;
}

/* 0x2011D438: (ch, graphics, read): the read layer's addressing, format (YCbCr for 8 and 9), folding, display area;
 * the buffer size given, or the display area (frame-number addressing, OIR), or the size the scaler writes [fact] */
void vdc5_shrd_set_read_param(unsigned ch, unsigned gr, const vdc5_read_t *param)
{
    vdc5_shrd_graphics_t *g = &vdc5_shrd_graphics[ch][gr];

    g->gr_ln_off_dir = param->gr_ln_off_dir;
    g->gr_flm_sel = param->gr_flm_sel;
    g->gr_format = param->gr_format;
    g->color_sp_fb_rd = (param->gr_format == 8 || param->gr_format == 9) ? 1 : 0;
    g->adj_sel = param->adj_sel;
    vdc5_rect_copy(&g->gr_grc, &param->gr_grc);
    if (param->width_read_fb != NULL)
    {
        g->width_read_fb.in_vw = param->width_read_fb->in_vw;
        g->width_read_fb.in_hw = param->width_read_fb->in_hw;
    }
    else if (param->gr_flm_sel == 1 || gr == VDC5_GR_TYPE_OIR)
    {
        g->width_read_fb.in_vw = param->gr_grc.vw;
        g->width_read_fb.in_hw = param->gr_grc.hw;
    }
    else
    {
        const vdc5_width_read_fb_t *w = &vdc5_shrd_scaling[ch][gr == 0 ? 0 : 1].width_wr_fb;

        g->width_read_fb.in_vw = w->in_vw;
        g->width_read_fb.in_hw = w->in_hw;
    }
}

/* 0x2011D514: (ch, graphics, change): a new display area and buffer size, where given [fact] */
void vdc5_shrd_set_chg_read_param(unsigned ch, unsigned gr, const vdc5_read_chg_t *param)
{
    vdc5_shrd_graphics_t *g = &vdc5_shrd_graphics[ch][gr];

    if (param->gr_grc != NULL)
    {
        vdc5_rect_copy(&g->gr_grc, param->gr_grc);
    }
    if (param->width_read_fb != NULL)
    {
        g->width_read_fb.in_vw = param->width_read_fb->in_vw;
        g->width_read_fb.in_hw = param->width_read_fb->in_hw;
    }
}

/* 0x2011D57C .. 0x2011D787: setters and getters of single fields [fact: each reads or writes the one field] */
void vdc5_shrd_set_cascade(unsigned ch, unsigned on)
{
    vdc5_shrd_common[ch].cascade = on;
}

void vdc5_shrd_set_und_sel(unsigned ch, unsigned on)
{
    vdc5_shrd_common[ch].und_sel = on;
}

uint8_t vdc5_shrd_get_panel_clksel(unsigned ch)
{
    return vdc5_shrd_common[ch].panel_icksel;
}

/* 1 while either channel refers to the LVDS PLL */
int vdc5_shrd_get_lvds_clk_ref(void)
{
    return (vdc5_shrd_common[0].lvds_ref != 0 || vdc5_shrd_common[1].lvds_ref != 0) ? 1 : 0;
}

uint8_t vdc5_shrd_get_color_space(unsigned ch)
{
    return vdc5_shrd_common[ch].color_sp_in;
}

uint8_t vdc5_shrd_get_input_select(unsigned ch)
{
    return vdc5_shrd_common[ch].inp_sel;
}

uint8_t vdc5_shrd_get_vs_in_sel(unsigned ch)
{
    return vdc5_shrd_common[ch].res_vs_in_sel;
}

uint8_t vdc5_shrd_get_cascade(unsigned ch)
{
    return vdc5_shrd_common[ch].cascade;
}

uint8_t vdc5_shrd_get_und_sel(unsigned ch)
{
    return vdc5_shrd_common[ch].und_sel;
}

/* (ch, colour space): 0 = RGB, otherwise CrYCb */
uint32_t vdc5_shrd_get_bg_color(unsigned ch, unsigned color_space)
{
    return color_space == 0 ? vdc5_shrd_common[ch].bg_color_rgb : vdc5_shrd_common[ch].bg_color_crycb;
}

uint8_t vdc5_shrd_get_writing_mode(unsigned ch, unsigned sc)
{
    return vdc5_shrd_scaling[ch][sc].res_ds_wr_md;
}

uint8_t vdc5_shrd_get_interlace(unsigned ch, unsigned sc)
{
    return vdc5_shrd_scaling[ch][sc].res_inter;
}

uint8_t vdc5_shrd_get_color_space_fb_wr(unsigned ch, unsigned sc)
{
    return vdc5_shrd_scaling[ch][sc].color_sp_fb_wr;
}

void *vdc5_shrd_get_fr_buff_btm(unsigned ch, unsigned sc)
{
    return vdc5_shrd_scaling[ch][sc].btm_base;
}

uint8_t vdc5_shrd_get_ln_off_dir(unsigned ch, unsigned gr)
{
    return vdc5_shrd_graphics[ch][gr].gr_ln_off_dir;
}

uint8_t vdc5_shrd_get_sel_fb_addr_sig(unsigned ch, unsigned gr)
{
    return vdc5_shrd_graphics[ch][gr].gr_flm_sel;
}

uint8_t vdc5_shrd_get_graphics_format(unsigned ch, unsigned gr)
{
    return vdc5_shrd_graphics[ch][gr].gr_format;
}

uint8_t vdc5_shrd_get_color_space_fb_rd(unsigned ch, unsigned gr)
{
    return vdc5_shrd_graphics[ch][gr].color_sp_fb_rd;
}

uint8_t vdc5_shrd_get_measure_folding(unsigned ch, unsigned gr)
{
    return vdc5_shrd_graphics[ch][gr].adj_sel;
}

vdc5_period_rect_t *vdc5_shrd_get_display_area(unsigned ch, unsigned gr)
{
    return &vdc5_shrd_graphics[ch][gr].gr_grc;
}

vdc5_width_read_fb_t *vdc5_shrd_get_fr_buff_width_rd(unsigned ch, unsigned gr)
{
    return &vdc5_shrd_graphics[ch][gr].width_read_fb;
}

uint8_t vdc5_shrd_get_lvds_ch(void)
{
    return vdc5_lvds_vdc_sel_ch;
}

/* 0x2011D788: (ch, type): the state byte of a resource type 0..3 of the channel, the LVDS one (4, shared by both
 * channels), NULL for any other type [fact: the jump table] */
uint8_t *vdc5_shrd_state_ptr(unsigned ch, unsigned type)
{
    uint8_t *r = vdc5_resource[ch];

    switch (type)
    {
    case VDC5_RESOURCE_PANEL_CLK:
        return &r[0];
    case VDC5_RESOURCE_VIDEO_IN:
        return &r[1];
    case VDC5_RESOURCE_VSYNC:
        return &r[2];
    case VDC5_RESOURCE_LCD_PANEL:
        return &r[3];
    case VDC5_RESOURCE_LVDS_CLK:
        return &vdc5_lvds_resource;
    default:
        return NULL;
    }
}

/* 0x2011D7D8 */
void vdc5_shrd_set_state(unsigned ch, unsigned type, unsigned state)
{
    uint8_t *p = vdc5_shrd_state_ptr(ch, type);

    if (p != NULL)
    {
        *p = state;
    }
}

/* 0x2011D830: the state, 0 for an unknown type */
int vdc5_shrd_get_state(unsigned ch, unsigned type)
{
    uint8_t *p = vdc5_shrd_state_ptr(ch, type);

    return p != NULL ? *p : 0;
}

/* 0x2011D7F0: (ch, layer, state): one layer's resource state, or (layer -1) that of every layer not running [fact] */
void vdc5_shrd_set_resource(unsigned ch, int layer, unsigned state)
{
    unsigned i;

    if (layer != VDC5_LAYER_ID_ALL)
    {
        vdc5_layer_resource[ch][layer] = state;
        return;
    }
    for (i = 0; i < VDC5_LAYER_ID_NUM; i++)
    {
        if (vdc5_rw_proc_state[ch][i] == 0)
        {
            vdc5_layer_resource[ch][i] = state;
        }
    }
}

/* 0x2011D84C */
int r_vdc5_shrd_get_resource(unsigned ch, int layer)
{
    return vdc5_layer_resource[ch][layer];
}

/* 0x2011D860 / 0x2011D8B4: (ch, layer): the layer runs / stops, if it holds its resource [fact] */
void r_vdc5_shrd_rw_enable(unsigned ch, int layer)
{
    if (layer != VDC5_LAYER_ID_ALL && vdc5_layer_resource[ch][layer] != 0)
    {
        vdc5_rw_proc_state[ch][layer] = 1;
    }
}

void r_vdc5_shrd_rw_disable(unsigned ch, int layer)
{
    if (layer != VDC5_LAYER_ID_ALL && vdc5_layer_resource[ch][layer] != 0)
    {
        vdc5_rw_proc_state[ch][layer] = 0;
    }
}

/* 0x2011D8E8 / 0x2011D920: 1 if the layer holds its resource and is idle / is running [fact] */
int vdc5_shrd_res_idle(unsigned ch, int layer)
{
    return (vdc5_layer_resource[ch][layer] != 0 && vdc5_rw_proc_state[ch][layer] == 0) ? 1 : 0;
}

int vdc5_shrd_res_busy(unsigned ch, int layer)
{
    return (vdc5_layer_resource[ch][layer] != 0 && vdc5_rw_proc_state[ch][layer] != 0) ? 1 : 0;
}
