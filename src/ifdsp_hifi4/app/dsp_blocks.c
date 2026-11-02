/*
 * FT-710 IFDSP HiFi4: small blocks of the receive and transmit chains (recreated, T24): the state resets the chain
 * init functions call, sample (de)interleaving, the VOX state, the FM TX filters' set-up and the noise generator seed
 * (docs/code/ifdsp/dsp-chains.md). The state blocks belong to the chain modules and are declared in dsp_blocks.h.
 *
 * Floats: the image passes float arguments in the FP/AE registers (XCC's convention for this core); this source is
 * built with GCC's soft-float convention (floats in the address registers). tools/equiv_hifi4_emu.py maps the
 * arguments for each side, so the functions are compared on their values, not their register interface.
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "dsp_blocks.h"

/* ---- sample (de)interleaving ------------------------------------------------------------------------------------ */

/* 0x21C560: split n stereo frames into two channels */
void deinterleave2_u32(uint32_t *ch0, uint32_t *ch1, const uint32_t *frames, unsigned n)
{
    while (n--) {
        *ch0++ = frames[0];
        *ch1++ = frames[1];
        frames += 2;
    }
}

/* 0x21C598: merge two channels into n stereo frames */
void interleave2_u32(uint32_t *frames, const uint32_t *ch0, const uint32_t *ch1, unsigned n)
{
    while (n--) {
        frames[0] = *ch0++;
        frames[1] = *ch1++;
        frames += 2;
    }
}

/* ---- state resets ------------------------------------------------------------------------------------------------ */

/* 0x21C600 */
void apf_init(void)
{
    apf_state[0] = 0;
    apf_state[1] = 0;
}

/* 0x21C890: clear, then 1.0 at +0xC8C */
void nlms_auto_notch_init(void)
{
    memset(nlms_auto_notch_state, 0, sizeof nlms_auto_notch_state);
    *(float *)&nlms_auto_notch_state[0xC8C] = 1.0f;
}

/* 0x21CC50 */
void contour_init(void)
{
    unsigned i;

    for (i = 0; i < 6; i++)
        contour_state[i] = 0;
}

/* 0x21D0A8: the two Goertzel state values of each bin */
void zeroin_goertzel_reset(void)
{
    unsigned i;

    for (i = 0; i < 3; i++) {
        goertzel_bins[i].s1 = 0.0f;
        goertzel_bins[i].s2 = 0.0f;
    }
}

/* 0x21D5B0 */
void am_demod_init(void)
{
    am_demod_state.acc[0] = 0.0f;
    am_demod_state.acc[1] = 0.0f;
    hilbert_iq_init(am_demod_state.hilbert);
}

/* 0x21DBB0: clear, then 1.0 at +0x6D4, +0x6DC and +0x6E0 */
void lms_ale_nr_init(void)
{
    memset(lms_ale_nr_state, 0, sizeof lms_ale_nr_state);
    *(float *)&lms_ale_nr_state[0x6D4] = 1.0f;
    *(float *)&lms_ale_nr_state[0x6DC] = 1.0f;
    *(float *)&lms_ale_nr_state[0x6E0] = 1.0f;
}

/* 0x21E520 */
void manual_notch_init(void)
{
    manual_notch_state[0] = 0;
    manual_notch_state[1] = 0;
}

/* 0x21E6B0 */
void branch_b_delay_init(void)
{
    memset(branch_b_delay_line, 0, sizeof branch_b_delay_line);
}

/* 0x21E740 */
void aess_lowpass_fir_init(void)
{
    memset(aess_lowpass_fir_state, 0, sizeof aess_lowpass_fir_state);
}

/* 0x21E890: clear, then 71 and 85 in the two halves' first words */
void af_locut_init(void)
{
    memset(&af_locut_state, 0, sizeof af_locut_state);
    af_locut_state.half[0].first = 71;
    af_locut_state.half[1].first = 85;
}

/* 0x21EC20: as af_locut_init with 70 and 84 */
void af_hicut_init(void)
{
    memset(&af_hicut_state, 0, sizeof af_hicut_state);
    af_hicut_state.half[0].first = 70;
    af_hicut_state.half[1].first = 84;
}

/* 0x220C68 */
void rx_audio_init(void)
{
    rx_audio_mode_cache[126] = 0xFFFF;
    rx_audio_chain_init();
}

/* 0x2221C0 */
void tx_bpf_init(void)
{
    tx_bpf_selected = 0;
}

/* 0x222230 */
void soft_knee_compressor_init(void)
{
    memset(soft_knee_compressor_state, 0, sizeof soft_knee_compressor_state);
}

/* 0x222DD4: a 4-section cascade on the coefficients at 0x2371F0 */
void fm_tx_hpf_init(void)
{
    fm_tx_hpf_handle = iir_cascade_init(fm_tx_hpf_mem, 4, fm_tx_hpf_coef, 1);
}

/* 0x222DF0: one 4-sample block */
void fm_tx_hpf_process(const float *in, float *out)
{
    iir_cascade_process(fm_tx_hpf_handle, out, in, 4);
}

/* 0x223080: a 2-section cascade on the coefficients at 0x2372E0 */
void fm_post_lpf_init(void)
{
    fm_post_lpf_handle = iir_cascade_init(fm_post_lpf_mem, 2, fm_post_lpf_coef, 1);
}

/* 0x223110 */
void tx_chain_init(void)
{
    FUN_0022312c();
    tx_core_init();
    tx_alc_init();
    fm_post_lpf_init();
    ctcss_encoder_init();
    two_tone_test_init();
    dcs_encoder_init();
}

/* 0x223A74: VOX active and no speaker audio (anti-VOX) */
uint16_t vox_state(void)
{
    return vox_detector_state[18] & ~antivox_detector_state[126];
}

/* 0x223A90: the generator's two values, a cleared accumulator, and a seed from the cycle counter */
void noise_gen_seed(struct noise_gen *g, float amp, float b)
{
    g->amp = amp;
    g->b = b;
    g->acc = 0.0f;
    g->count = 0;
    srand(xthal_get_ccount());
}

/* ---- buffers ------------------------------------------------------------------------------------------------------ */

/* 0x2211B8 / 0x2211C0: the FLEXCOMM1 SPI DMA buffers in the shared SRAM */
void *spi_tx_buffer_ptr(void)
{
    return (void *)0x200607E0;
}

void *spi_rx_buffer_ptr(void)
{
    return (void *)0x200619E0;
}
