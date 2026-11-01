/*
 * FT-710 DISPLAY (T24 round 5): the VDC5 video display controller driver, 0x201179C0..0x2011D957.
 *
 * The image links the Renesas RZ/A1H r_vdc5 sample driver [inference: the API order, the argument shapes, the error
 * codes and the shared-parameter tables match the public driver (GR-PEACH_video drivers/vdc5, 2014) function for
 * function; docs/code/display/gui.md "VDC5 set-up"]. armcc stores its enumerations in one byte, so every enum field of
 * the parameter structures is a uint8_t here, and the structure offsets are the image's [fact: the strb/ldrb at the
 * offsets below, e.g. vdc5_shrd_set_write_param 0x2011D374]. Function arguments stay full words (armcc does not
 * narrow them: vdc5_layer_to_wr compares r0 unmasked).
 */
#ifndef VDC5_H
#define VDC5_H

#include <stdint.h>
#include <stddef.h>

#define VDC5_CHANNEL_NUM 2

/* error codes (vdc5_error_t) [fact: the returns of the API functions below] */
#define VDC5_OK 0
#define VDC5_ERR_IF_CONDITION 8       /* a format or mode that does not allow the operation */
#define VDC5_ERR_RESOURCE_CLK 9       /* panel clock not set (r_vdc5_initialize not run) */
#define VDC5_ERR_RESOURCE_VSYNC 10    /* sync not set (r_vdc5_sync_control not run) */
#define VDC5_ERR_RESOURCE_INPUT 11    /* no video input */
#define VDC5_ERR_RESOURCE_OUTPUT 12   /* no panel output (r_vdc5_display_output not run) */
#define VDC5_ERR_RESOURCE_LVDS_CLK 13 /* the LVDS PLL is already in use */
#define VDC5_ERR_RESOURCE_LAYER 14    /* the layer is not in the needed state */

/* resource types of vdc5_shrd_get_state / vdc5_shrd_set_state [fact: vdc5_shrd_state_ptr 0x2011D788] */
#define VDC5_RESOURCE_PANEL_CLK 0
#define VDC5_RESOURCE_VIDEO_IN 1
#define VDC5_RESOURCE_VSYNC 2
#define VDC5_RESOURCE_LCD_PANEL 3
#define VDC5_RESOURCE_LVDS_CLK 4

/* layer ids: 0..2 write (scaler 0, scaler 1, OIR), 3..8 read (graphics 0..3, VIN, OIR), -1 all
 * [fact: vdc5_layer_to_wr 0x20117C64, vdc5_layer_to_gr 0x20117D8C, the cmn r1, #1 tests] */
#define VDC5_LAYER_ID_ALL (-1)
#define VDC5_LAYER_ID_NUM 9
#define VDC5_SC_TYPE_NUM 3
#define VDC5_GR_TYPE_NUM 6
#define VDC5_SC_TYPE_OIR 2
#define VDC5_GR_TYPE_OIR 5

typedef struct
{
    uint16_t vs, vw, hs, hw;
} vdc5_period_rect_t;

typedef struct
{
    uint16_t in_vw, in_hw;
} vdc5_width_read_fb_t;

typedef struct
{
    uint8_t lvds_in_clk_sel;   /* +0 */
    uint8_t lvds_idiv_set;     /* +1 */
    uint16_t lvdspll_tst;      /* +2 */
    uint8_t lvds_odiv_set;     /* +4 */
    uint8_t lvds_vdc_sel;      /* +5: the channel output through LVDS [fact: vdc5_shrd_set_init_param] */
    uint16_t lvdspll_fd;       /* +6 */
    uint16_t lvdspll_rd;       /* +8 */
    uint8_t lvdspll_od;        /* +0xA */
} vdc5_lvds_t;

typedef struct
{
    uint8_t panel_icksel;      /* +0: panel clock select; 5 and 6 are the LVDS PLL */
    uint8_t panel_dcdr;        /* +1 */
    const vdc5_lvds_t *lvds;   /* +4 */
} vdc5_init_t;

typedef struct
{
    uint8_t inp_format;        /* +0: 0..2 RGB888/666/565 */
} vdc5_ext_in_sig_t;

typedef struct
{
    uint8_t inp_sel;           /* +0: 0 = video decoder, 1 = external pins */
    uint16_t inp_fh50, inp_fh25;
    const void *dly;           /* +8 */
    const vdc5_ext_in_sig_t *ext_sig;   /* +0xC */
} vdc5_input_t;

typedef struct
{
    uint8_t res_vs_sel;        /* +0: 0 = sync from a video input */
    uint8_t res_vs_in_sel;     /* +1: 1 = the other channel's input */
    uint16_t res_fv, res_fh, res_vsdly;
    vdc5_period_rect_t res_f;  /* +8: full-screen area */
    const struct { uint16_t res_vmask, res_vlack; } *vsync_cpmpe;   /* +0x10 */
} vdc5_sync_ctrl_t;

typedef struct
{
    uint8_t pad[0x2C];
    uint32_t bg_color;         /* +0x2C: 24-bit RGB */
} vdc5_output_t;

typedef struct
{
    uint8_t type;              /* +0: interrupt type 0..22 */
    void (*callback)(int type);   /* +4 */
    uint16_t line_num;         /* +8 */
} vdc5_int_t;

typedef struct
{
    vdc5_period_rect_t res;    /* +0 */
    uint8_t res_pfil_sel;      /* +8 */
    uint16_t res_out_vw;       /* +0xA */
    uint16_t res_out_hw;       /* +0xC */
    uint8_t adj_sel;           /* +0xE */
    uint8_t res_ds_wr_md;      /* +0xF */
} vdc5_scalingdown_rot_t;

typedef struct
{
    vdc5_scalingdown_rot_t scalingdown_rot;   /* +0 */
    uint8_t res_wrswa;         /* +0x10 */
    uint8_t res_md;            /* +0x11: 0 and 3 are YCbCr */
    uint8_t res_bst_md;
    uint8_t res_inter;         /* +0x13 */
    uint8_t res_fs_rate, res_fld_sel, res_dth_on;
    void *base;                /* +0x18 */
    uint32_t ln_off, flm_num, flm_off;
    void *btm_base;            /* +0x28 */
} vdc5_write_t;

typedef struct
{
    uint8_t gr_ln_off_dir;     /* +0 */
    uint8_t gr_flm_sel;        /* +1: 1 = frame number (fixed buffer) */
    uint8_t gr_imr_flm_inv;
    uint8_t gr_bst_md;
    void *gr_base;             /* +4 */
    uint32_t gr_ln_off;        /* +8 */
    const vdc5_width_read_fb_t *width_read_fb;   /* +0xC */
    uint8_t adj_sel;           /* +0x10 */
    uint8_t gr_format;         /* +0x11: 8 and 9 are YCbCr */
    uint8_t gr_ycc_swap;
    uint8_t gr_rdswa;
    vdc5_period_rect_t gr_grc; /* +0x14 */
} vdc5_read_t;

typedef struct
{
    void *gr_base;                             /* +0 */
    const vdc5_width_read_fb_t *width_read_fb; /* +4 */
    const vdc5_period_rect_t *gr_grc;          /* +8 */
    const void *gr_disp_sel;                   /* +0xC */
} vdc5_read_chg_t;

/* the shared parameters (r_vdc5_shared_param), all in .bss2 [fact: vdc5_shrd_init 0x2011D080] */
typedef struct
{
    uint8_t panel_icksel;      /* +0 */
    uint8_t lvds_ref;          /* +1: the LVDS PLL clock is used */
    uint8_t color_sp_in;       /* +2: colour space of the video input (0 GBR, 1 YCbCr) */
    uint8_t inp_sel;           /* +3 */
    uint8_t res_vs_in_sel;     /* +4 */
    uint8_t cascade;           /* +5 */
    uint8_t und_sel;           /* +6 */
    uint32_t bg_color_rgb;     /* +8 */
    uint32_t bg_color_crycb;   /* +0xC */
} vdc5_shrd_common_t;

typedef struct
{
    uint8_t res_ds_wr_md;      /* +0 */
    uint8_t res_inter;         /* +1 */
    uint8_t color_sp_fb_wr;    /* +2 */
    void *btm_base;            /* +4 */
    vdc5_width_read_fb_t width_wr_fb;   /* +8 */
} vdc5_shrd_scaling_t;

typedef struct
{
    uint8_t gr_ln_off_dir;     /* +0 */
    uint8_t gr_flm_sel;        /* +1 */
    uint8_t gr_format;         /* +2 */
    uint8_t color_sp_fb_rd;    /* +3 */
    uint8_t adj_sel;           /* +4 */
    vdc5_period_rect_t gr_grc; /* +6 */
    vdc5_width_read_fb_t width_read_fb;   /* +0xE */
} vdc5_shrd_graphics_t;

extern vdc5_shrd_common_t vdc5_shrd_common[VDC5_CHANNEL_NUM];                         /* 0x208DCCC4 */
extern vdc5_shrd_scaling_t vdc5_shrd_scaling[VDC5_CHANNEL_NUM][VDC5_SC_TYPE_NUM];     /* 0x208DCCE4 */
extern vdc5_shrd_graphics_t vdc5_shrd_graphics[VDC5_CHANNEL_NUM][VDC5_GR_TYPE_NUM];   /* 0x208DCD2C */
extern uint8_t vdc5_layer_resource[VDC5_CHANNEL_NUM][VDC5_LAYER_ID_NUM];               /* 0x208DCE04 */
extern uint8_t vdc5_rw_proc_state[VDC5_CHANNEL_NUM][VDC5_LAYER_ID_NUM];                /* 0x208DCE16 */
extern uint8_t vdc5_lvds_resource;           /* 0x2080040C */
extern uint8_t vdc5_lvds_vdc_sel_ch;         /* 0x2080040D */
extern uint8_t vdc5_video_input_flag[VDC5_CHANNEL_NUM];   /* 0x2080040E */
extern uint8_t vdc5_resource[VDC5_CHANNEL_NUM][4];        /* 0x20800410: panel clock, video in, vsync, LCD panel */

/* shared parameters (drivers/vdc5_shrd.c) */
void vdc5_shrd_init(unsigned ch);
void vdc5_shrd_set_init_param(unsigned ch, const vdc5_init_t *param);
void vdc5_shrd_set_terminate(unsigned ch);
void vdc5_shrd_set_input_param(unsigned ch, const vdc5_input_t *param);
void vdc5_shrd_set_sync_param(unsigned ch, const vdc5_sync_ctrl_t *param);
void vdc5_shrd_set_output_param(unsigned ch, const vdc5_output_t *param);
void vdc5_shrd_set_write_param(unsigned ch, unsigned sc, const vdc5_write_t *param);
void vdc5_shrd_set_chg_write_param(unsigned ch, unsigned sc, const vdc5_scalingdown_rot_t *param);
void vdc5_shrd_set_read_param(unsigned ch, unsigned gr, const vdc5_read_t *param);
void vdc5_shrd_set_chg_read_param(unsigned ch, unsigned gr, const vdc5_read_chg_t *param);
int vdc5_shrd_get_lvds_clk_ref(void);
uint8_t vdc5_shrd_get_color_space_fb_rd(unsigned ch, unsigned gr);
uint8_t *vdc5_shrd_state_ptr(unsigned ch, unsigned type);
void vdc5_shrd_set_state(unsigned ch, unsigned type, unsigned state);
int vdc5_shrd_get_state(unsigned ch, unsigned type);
void vdc5_shrd_set_resource(unsigned ch, int layer, unsigned state);
int r_vdc5_shrd_get_resource(unsigned ch, int layer);
int vdc5_shrd_res_idle(unsigned ch, int layer);
int vdc5_shrd_res_busy(unsigned ch, int layer);
uint8_t vdc5_shrd_get_vs_in_sel(unsigned ch);
uint8_t vdc5_shrd_get_cascade(unsigned ch);
uint8_t vdc5_shrd_get_und_sel(unsigned ch);
uint8_t vdc5_shrd_get_writing_mode(unsigned ch, unsigned sc);
uint8_t vdc5_shrd_get_interlace(unsigned ch, unsigned sc);
uint8_t vdc5_shrd_get_ln_off_dir(unsigned ch, unsigned gr);
uint8_t vdc5_shrd_get_sel_fb_addr_sig(unsigned ch, unsigned gr);
uint8_t vdc5_shrd_get_graphics_format(unsigned ch, unsigned gr);
uint8_t vdc5_shrd_get_measure_folding(unsigned ch, unsigned gr);
vdc5_period_rect_t *vdc5_shrd_get_display_area(unsigned ch, unsigned gr);
vdc5_width_read_fb_t *vdc5_shrd_get_fr_buff_width_rd(unsigned ch, unsigned gr);

/* the register layer (the image's, not recreated yet) */
void vdc5_reg_initialize(unsigned ch, const vdc5_init_t *param);
void vdc5_reg_terminate(unsigned ch);
void vdc5_wait_200us(void);
void vdc5_reg_video_input(unsigned ch, const vdc5_input_t *param);
void vdc5_reg_sync_control(unsigned ch, const vdc5_sync_ctrl_t *param);
void vdc5_reg_display_output(unsigned ch, const vdc5_output_t *param);
void vdc5_reg_write_data_control(unsigned ch, unsigned sc, const vdc5_write_t *param);
void vdc5_reg_change_write_process(unsigned ch, unsigned sc, const void *param);
void vdc5_reg_read_data_control(unsigned ch, unsigned gr, const vdc5_read_t *param);
void vdc5_reg_change_read_process(unsigned ch, unsigned gr, const vdc5_read_chg_t *param);
void vdc5_reg_start_process(unsigned ch, int layer, const void *param);
void vdc5_reg_stop_process(unsigned ch, int layer);
void vdc5_reg_release_data_control(unsigned ch, int layer);
void vdc5_reg_video_noise_reduction(unsigned ch, unsigned on, const void *param);
void vdc5_reg_image_color_matrix(unsigned ch, const void *param);
void vdc5_reg_image_enhancement(unsigned ch, unsigned id, unsigned shp_h_on, const void *sharp, unsigned lti_h_on,
                                const void *lti, const void *area);
void vdc5_reg_image_black_stretch(unsigned ch, unsigned id, unsigned on, const void *param);
void vdc5_reg_alpha_blending(unsigned ch, unsigned gr, const void *param);
void vdc5_reg_alpha_blending_rect(unsigned ch, unsigned gr, unsigned on, const void *param);
void vdc5_reg_chromakey(unsigned ch, unsigned gr, unsigned on, const void *param);
void vdc5_reg_clut(unsigned ch, unsigned gr, const void *param);
void vdc5_reg_display_calibration(unsigned ch, const void *param);
void vdc5_reg_gamma_correction(unsigned ch, unsigned on, const void *param);

/* interrupts (drivers/vdc5_int.c) */
void vdc5_int_callbacks_clear(unsigned ch);
void r_vdc5_callback_isr(unsigned ch, const vdc5_int_t *param);

#endif
