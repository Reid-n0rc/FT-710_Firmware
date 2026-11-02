/* FT-710 IFDSP HiFi4: small receive/transmit chain blocks (recreated, T24; app/dsp_blocks.c). */
#ifndef DSP_BLOCKS_H
#define DSP_BLOCKS_H

#include <stdint.h>
#include "hifi4_hal.h"

/*
 * State blocks of the chain modules, at their image addresses (data_symbols.tsv). They belong to the modules that
 * are not recreated yet, so they are declared here and not defined; a layout is given only as far as the recreated
 * functions show it. Sizes in brackets are the memset lengths of the init functions [fact].
 */
extern uint32_t apf_state[2];                    /* 0x244510 */
extern uint8_t nlms_auto_notch_state[0xC98];     /* 0x245420 */
extern uint32_t contour_state[6];                /* 0x2464A0 */

struct goertzel {                                /* 28 bytes [fact: zeroin_goertzel_reset steps by 28] */
    float s1, s2;                                /* the two state values: cleared by the reset */
    uint32_t rest[5];                            /* Open: the other fields; would be settled by zeroin_goertzel_tune */
};
extern struct goertzel goertzel_bins[3];         /* 0x246CC8 */

struct am_demod_state {
    float acc[2];                                /* cleared by am_demod_init */
    uint8_t hilbert[];                           /* 0x246EB8: hilbert_iq_init's state */
};
extern struct am_demod_state am_demod_state;     /* 0x246EB0 */

extern uint8_t lms_ale_nr_state[0x6E4];          /* 0x247DD0 */
extern uint32_t manual_notch_state[2];           /* 0x250B40 */
extern uint8_t branch_b_delay_line[0x12C8];           /* 0x250CD0 */
extern uint8_t aess_lowpass_fir_state[0x210];    /* 0x251FA0 */

struct af_cut_state {                            /* 112 bytes: two 56-byte halves */
    struct {
        uint16_t first;                          /* 71/85 (lo-cut), 70/84 (hi-cut) after init. Open: what they
                                                    are; would be settled by af_locut / af_hicut's use of them */
        uint8_t rest[54];
    } half[2];
};
extern struct af_cut_state af_locut_state;       /* 0x252AC0 */
extern struct af_cut_state af_hicut_state;       /* 0x252B30 */

extern uint16_t rx_audio_mode_cache[128];        /* 0x2576E4; index 126 = 0xFFFF after rx_audio_init */
extern uint16_t tx_bpf_selected;                 /* 0x25B810 */
extern uint8_t soft_knee_compressor_state[52];   /* 0x25B9C0 */
extern void *fm_tx_hpf_handle;                          /* 0x25BFF0: iir_cascade handle */
extern uint8_t fm_tx_hpf_mem[];                  /* 0x25C030 */
extern const float fm_tx_hpf_coef[];             /* 0x2371F0 */
extern void *fm_post_lpf_handle;                        /* 0x25C230 */
extern uint8_t fm_post_lpf_mem[];                /* 0x25C240 */
extern const float fm_post_lpf_coef[];           /* 0x2372E0 */
extern uint16_t vox_detector_state[20];          /* 0x25C480: index 18 (+36) = VOX active */
extern uint16_t antivox_detector_state[128];     /* 0x25C6AC: index 126 (+252) = speaker audio present */

struct noise_gen {                               /* noise_gen_seed 0x223A90 */
    float amp;                                   /* +0: 10^(dB/20) [fact: noise_gen_set_level 0x223AB4] */
    float b;                                     /* +4: the second argument. Open: its role; would be settled by
                                                    the generator that reads the block */
    int32_t count;                               /* +8: cleared */
    float acc;                                   /* +12: cleared */
};

/* callees in the image (docs/code/ifdsp/dsp-chains.md, hifi4-libraries.md) */
void hilbert_iq_init(void *state);
void *iir_cascade_init(void *mem, int sections, const float *coef, int flags);
void iir_cascade_process(void *handle, float *out, const float *in, int n);
void rx_audio_chain_init(void);
void FUN_0022312c(void);
void tx_core_init(void);
void tx_alc_init(void);
void ctcss_encoder_init(void);
void two_tone_test_init(void);
void dcs_encoder_init(void);

void deinterleave2_u32(uint32_t *ch0, uint32_t *ch1, const uint32_t *frames, unsigned n);
void interleave2_u32(uint32_t *frames, const uint32_t *ch0, const uint32_t *ch1, unsigned n);
void apf_init(void);
void nlms_auto_notch_init(void);
void contour_init(void);
void zeroin_goertzel_reset(void);
void am_demod_init(void);
void lms_ale_nr_init(void);
void manual_notch_init(void);
void branch_b_delay_init(void);
void aess_lowpass_fir_init(void);
void af_locut_init(void);
void af_hicut_init(void);
void rx_audio_init(void);
void tx_bpf_init(void);
void soft_knee_compressor_init(void);
void fm_tx_hpf_init(void);
void fm_tx_hpf_process(const float *in, float *out);
void fm_post_lpf_init(void);
void tx_chain_init(void);
uint16_t vox_state(void);
void noise_gen_seed(struct noise_gen *g, float amp, float b);
void *spi_tx_buffer_ptr(void);
void *spi_rx_buffer_ptr(void);

#endif
