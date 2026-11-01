/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 driver API, 0x201179C0..0x20118363, recreated from the image.
 *
 * Each call checks the resources it needs in the shared parameters (drivers/vdc5_shrd.c), records its parameters
 * there, has the register layer program the VDC5 and marks what it set up. The driver is built without its
 * parameter checks (no range checks before the resource checks) [fact: the first call of every function is a
 * resource query or a parameter store]. Users: gui_start and the layer code (docs/code/display/gui.md).
 *
 * Ghidra names (aliases.tsv): 0x20117AD4 is called r_vdc5_terminate there, but it is the video-input call (it
 * records the input and sets resource 1, "video in"); the real terminate is the unlisted function at 0x20117A68,
 * and the release call at 0x20117F3C is unlisted too.
 */
#include "vdc5.h"

void vdc5_shrd_set_terminate(unsigned ch);
int vdc5_layer_to_wr(int layer);
int vdc5_layer_to_gr(int layer);

/* 0x201179C0: (ch, init, init_func, user_num): the channel's shared parameters to their defaults; error 13 if the
 * LVDS PLL is already set up and the call brings an LVDS block; then the user's clock set-up function, the
 * registers, all interrupts off, the panel clock (and LVDS) resources valid [fact] */
int r_vdc5_initialize(unsigned ch, const vdc5_init_t *param, void (*init_func)(uint32_t), uint32_t user_num)
{
    vdc5_shrd_init(ch);
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_LVDS_CLK) != 0 && param->lvds != NULL)
    {
        return VDC5_ERR_RESOURCE_LVDS_CLK;
    }
    vdc5_shrd_set_init_param(ch, param);
    if (init_func != NULL)
    {
        init_func(user_num);
    }
    vdc5_reg_initialize(ch, param);
    vdc5_int_callbacks_clear(ch);
    vdc5_shrd_set_state(ch, VDC5_RESOURCE_PANEL_CLK, 1);
    if (param->lvds != NULL)
    {
        vdc5_shrd_set_state(ch, VDC5_RESOURCE_LVDS_CLK, 1);
    }
    return VDC5_OK;
}

/* 0x20117A68 (not in Ghidra's function list): (ch, quit_func, user_num): interrupts off, registers to their
 * reset state, the panel clock released, the LVDS PLL too once neither channel refers to it, then the user's
 * clock shut-down function [fact] */
int r_vdc5_terminate(unsigned ch, void (*quit_func)(uint32_t), uint32_t user_num)
{
    vdc5_shrd_set_terminate(ch);
    vdc5_int_callbacks_clear(ch);
    vdc5_reg_terminate(ch);
    vdc5_shrd_set_state(ch, VDC5_RESOURCE_PANEL_CLK, 0);
    if (vdc5_shrd_get_lvds_clk_ref() == 0)
    {
        vdc5_shrd_set_state(ch, VDC5_RESOURCE_LVDS_CLK, 0);
    }
    if (quit_func != NULL)
    {
        quit_func(user_num);
    }
    return VDC5_OK;
}

/* 0x20117AD4 (Ghidra: r_vdc5_terminate): (ch, input): records the video input, programs it, marks it valid [fact] */
int r_vdc5_video_input(unsigned ch, const vdc5_input_t *param)
{
    vdc5_shrd_set_input_param(ch, param);
    vdc5_reg_video_input(ch, param);
    vdc5_shrd_set_state(ch, VDC5_RESOURCE_VIDEO_IN, 1);
    return VDC5_OK;
}

/* 0x20117B0C: (ch, sync): needs the panel clock (9); with the sync taken from a video input (res_vs_sel 0) that
 * input must be set: this channel's, or the other one's for res_vs_in_sel 1 (11) [fact] */
int r_vdc5_sync_control(unsigned ch, const vdc5_sync_ctrl_t *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_PANEL_CLK) != 1)
    {
        return VDC5_ERR_RESOURCE_CLK;
    }
    if (param->res_vs_sel == 0)
    {
        unsigned in_ch = ch;

        if (param->res_vs_in_sel != 0)
        {
            in_ch = (ch == 0) ? 1 : 0;
        }
        if (vdc5_shrd_get_state(in_ch, VDC5_RESOURCE_VIDEO_IN) != 1)
        {
            return VDC5_ERR_RESOURCE_INPUT;
        }
    }
    vdc5_shrd_set_sync_param(ch, param);
    vdc5_reg_sync_control(ch, param);
    vdc5_shrd_set_state(ch, VDC5_RESOURCE_VSYNC, 1);
    return VDC5_OK;
}

/* 0x20117BA8: (ch, output): needs the panel clock (9) and the sync (10) [fact] */
int r_vdc5_display_output(unsigned ch, const vdc5_output_t *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_PANEL_CLK) != 1)
    {
        return VDC5_ERR_RESOURCE_CLK;
    }
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_VSYNC) != 1)
    {
        return VDC5_ERR_RESOURCE_VSYNC;
    }
    vdc5_shrd_set_output_param(ch, param);
    vdc5_reg_display_output(ch, param);
    vdc5_shrd_set_state(ch, VDC5_RESOURCE_LCD_PANEL, 1);
    return VDC5_OK;
}

/* 0x20117C14: (ch, interrupt): the public callback set-up, needs the panel clock (9) and the sync (10) [fact] */
int r_vdc5_callback_isr_checked(unsigned ch, const vdc5_int_t *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_PANEL_CLK) != 1)
    {
        return VDC5_ERR_RESOURCE_CLK;
    }
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_VSYNC) != 1)
    {
        return VDC5_ERR_RESOURCE_VSYNC;
    }
    r_vdc5_callback_isr(ch, param);
    return VDC5_OK;
}

/* 0x20117C64: write layer id 0..2 to scaler 0..2, anything else to 3 [fact] */
int vdc5_layer_to_wr(int layer)
{
    if ((unsigned)layer > 1 && layer != 2)
    {
        return 3;
    }
    return layer;
}

/* 0x20117C7C: (ch, layer 0..2, write): error 14 if the layer is taken; scaler 0 needs this channel's video input,
 * scaler 1 the other channel's (11); then the write registers and the layer resource [fact] */
int r_vdc5_write_data_control(unsigned ch, int layer, const vdc5_write_t *param)
{
    int sc = vdc5_layer_to_wr(layer);

    if (r_vdc5_shrd_get_resource(ch, layer) != 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    if (layer == 0 || layer == 1)
    {
        unsigned in_ch = ch;

        if (layer == 1)
        {
            in_ch = (ch == 0) ? 1 : 0;
        }
        if (vdc5_shrd_get_state(in_ch, VDC5_RESOURCE_VIDEO_IN) != 1)
        {
            return VDC5_ERR_RESOURCE_INPUT;
        }
    }
    vdc5_shrd_set_write_param(ch, sc, param);
    vdc5_config(ch, sc, param);
    vdc5_shrd_set_resource(ch, layer, 1);
    return VDC5_OK;
}

/* 0x20117D2C: (ch, layer, change): the layer must be running (14) [fact] */
int r_vdc5_change_write_process(unsigned ch, int layer, const vdc5_scalingdown_rot_t *param)
{
    int sc = vdc5_layer_to_wr(layer);

    if (vdc5_shrd_res_busy(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_shrd_set_chg_write_param(ch, sc, param);
    vdc5_reg_change_write_process(ch, sc, param);
    return VDC5_OK;
}

/* 0x20117D8C: read layer id 3..8 to graphics 0..5, anything else to 6 [fact] */
int vdc5_layer_to_gr(int layer)
{
    switch (layer)
    {
    case 3:
        return 0;
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 3;
    case 7:
        return 4;
    case 8:
        return 5;
    default:
        return 6;
    }
}

/* 0x20117DEC: (ch, layer, read): error 14 if the layer is taken; then the read registers and the resource [fact] */
int r_vdc5_read_data_control(unsigned ch, int layer, const vdc5_read_t *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (r_vdc5_shrd_get_resource(ch, layer) != 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_shrd_set_read_param(ch, gr, param);
    vdc5_reg_read_data_control(ch, gr, param);
    vdc5_shrd_set_resource(ch, layer, 1);
    return VDC5_OK;
}

/* 0x20117E5C: (ch, layer, change): a new frame buffer, area or size for a running layer (14 otherwise) [fact] */
int r_vdc5_change_read_process(unsigned ch, int layer, const vdc5_read_chg_t *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (vdc5_shrd_res_busy(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_shrd_set_chg_read_param(ch, gr, param);
    vdc5_reg_change_read_process(ch, gr, param);
    return VDC5_OK;
}

/* 0x20117EBC: (ch, layer or -1 for all, start): one layer must be set up and idle (14) [fact] */
int r_vdc5_start_process(unsigned ch, int layer, const void *param)
{
    if (layer != VDC5_LAYER_ID_ALL && vdc5_shrd_res_idle(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_start_process(ch, layer, param);
    return VDC5_OK;
}

/* 0x20117F00: (ch, layer or -1): one layer must be running (14) [fact] */
int r_vdc5_stop_process(unsigned ch, int layer)
{
    if (layer != VDC5_LAYER_ID_ALL && vdc5_shrd_res_busy(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_stop_process(ch, layer);
    return VDC5_OK;
}

/* 0x20117F3C (not in Ghidra's function list): (ch, layer or -1): releases a stopped layer (14 if it is not set up
 * or still running), its registers and its resource [fact] */
int r_vdc5_release_data_control(unsigned ch, int layer)
{
    if (layer != VDC5_LAYER_ID_ALL && vdc5_shrd_res_idle(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_release_data_control(ch, layer);
    vdc5_shrd_set_resource(ch, layer, 0);
    return VDC5_OK;
}

/* 0x20117F88: (ch, on, param): needs a video input (11) [fact] */
int r_vdc5_video_noise_reduction(unsigned ch, unsigned on, const void *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_VIDEO_IN) != 1)
    {
        return VDC5_ERR_RESOURCE_INPUT;
    }
    vdc5_reg_video_noise_reduction(ch, on, param);
    return VDC5_OK;
}

/* 0x20117FC8: (ch, matrix): the layer the matrix module belongs to must be set up (14): module 0 the input
 * (scaler 0 write of this channel, else scaler 1 write of the other one), module 1 graphics 0, others graphics 1
 * [fact] */
int r_vdc5_image_color_matrix(unsigned ch, const uint8_t *param)
{
    int res;

    if (param[0] == 0)
    {
        res = r_vdc5_shrd_get_resource(ch, 0);
        if (res == 0)
        {
            res = r_vdc5_shrd_get_resource(ch == 0 ? 1 : 0, 1);
        }
    }
    else if (param[0] == 1)
    {
        res = r_vdc5_shrd_get_resource(ch, 3);
    }
    else
    {
        res = r_vdc5_shrd_get_resource(ch, 4);
    }
    if (res == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_image_color_matrix(ch, param);
    return VDC5_OK;
}

/* 0x20118054: (ch, image-quality block 0/1, ...): graphics 0 or 1 must be set up (14) and read YCbCr (8) [fact] */
int r_vdc5_image_enhancement(unsigned ch, unsigned id, unsigned shp_h_on, const void *sharp, unsigned lti_h_on,
                             const void *lti, const void *area)
{
    if (r_vdc5_shrd_get_resource(ch, id == 0 ? 3 : 4) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    if (vdc5_shrd_get_color_space_fb_rd(ch, id != 0 ? 1 : 0) == 0)
    {
        return VDC5_ERR_IF_CONDITION;
    }
    vdc5_reg_image_enhancement(ch, id, shp_h_on, sharp, lti_h_on, lti, area);
    return VDC5_OK;
}

/* 0x201180E0: (ch, image-quality block 0/1, on, param): the same checks [fact] */
int r_vdc5_image_black_stretch(unsigned ch, unsigned id, unsigned on, const void *param)
{
    if (r_vdc5_shrd_get_resource(ch, id == 0 ? 3 : 4) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    if (vdc5_shrd_get_color_space_fb_rd(ch, id != 0 ? 1 : 0) == 0)
    {
        return VDC5_ERR_IF_CONDITION;
    }
    vdc5_reg_image_black_stretch(ch, id, on, param);
    return VDC5_OK;
}

/* 0x2011814C: (ch, layer, param): the layer must be set up (14) [fact] */
int r_vdc5_alpha_blending(unsigned ch, int layer, const void *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (r_vdc5_shrd_get_resource(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_alpha_blending(ch, gr, param);
    return VDC5_OK;
}

/* 0x2011819C: (ch, layer, on, param): except for layer 7 (VIN), the layer must be set up (14) and read RGB (8)
 * [fact] */
int r_vdc5_alpha_blending_rect(unsigned ch, int layer, unsigned on, const void *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (layer != 7)
    {
        if (r_vdc5_shrd_get_resource(ch, layer) == 0)
        {
            return VDC5_ERR_RESOURCE_LAYER;
        }
        if (vdc5_shrd_get_color_space_fb_rd(ch, gr) == 1)
        {
            return VDC5_ERR_IF_CONDITION;
        }
    }
    vdc5_reg_alpha_blending_rect(ch, gr, on, param);
    return VDC5_OK;
}

/* 0x20118214: (ch, layer, on, chroma key): the layer must be set up (14) and read RGB (8) [fact] */
int r_vdc5_chromakey(unsigned ch, int layer, unsigned on, const void *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (r_vdc5_shrd_get_resource(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    if (vdc5_shrd_get_color_space_fb_rd(ch, gr) == 1)
    {
        return VDC5_ERR_IF_CONDITION;
    }
    vdc5_reg_chromakey(ch, gr, on, param);
    return VDC5_OK;
}

/* 0x20118284: (ch, layer, CLUT): the layer must be set up (14) [fact] */
int r_vdc5_clut(unsigned ch, int layer, const void *param)
{
    int gr = vdc5_layer_to_gr(layer);

    if (r_vdc5_shrd_get_resource(ch, layer) == 0)
    {
        return VDC5_ERR_RESOURCE_LAYER;
    }
    vdc5_reg_clut(ch, gr, param);
    return VDC5_OK;
}

/* 0x201182D4: (ch, calibration): needs the panel output (12) [fact] */
int r_vdc5_display_calibration(unsigned ch, const void *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_LCD_PANEL) != 1)
    {
        return VDC5_ERR_RESOURCE_OUTPUT;
    }
    vdc5_reg_display_calibration(ch, param);
    return VDC5_OK;
}

/* 0x2011830C: (ch, on, gamma tables): needs the panel output (12) [fact] */
int r_vdc5_gamma_correction(unsigned ch, unsigned on, const void *param)
{
    if (vdc5_shrd_get_state(ch, VDC5_RESOURCE_LCD_PANEL) != 1)
    {
        return VDC5_ERR_RESOURCE_OUTPUT;
    }
    vdc5_reg_gamma_correction(ch, on, param);
    return VDC5_OK;
}
