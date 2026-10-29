# IFDSP: HiFi4 receive and transmit chains, stage by stage (#86)

Back to [hifi4.md](hifi4.md) (threads, I/O, register file, tables) and the [IFDSP overview](README.md). This page says **what each signal
stage computes**, with its constants and the registers that steer it. Sources: the decompiled C in `decomp/ifdsp/hifi4/` and, for every
kernel, the FLIX-aware listing `decomp/ifdsp/hifi4/flix.dis` (the decompiler drops many loops and the `ae_*` arithmetic). Literal values
are decoded from the L32R pools. Tags: **[fact]** = seen in code or data (address given), **[inference]**, **[guess]**. Function names are
the ones applied in Ghidra by this issue (`tools/ghidra/IfdspHifi4Names.java`). Register numbers are DSP register-file indexes; the MAIN
side of each register is in [control-link.md](control-link.md#register-map).

## Rates and conventions

- The I2S links and the per-block threads run at **72 kHz**, 24 samples per block (333 µs). The receive-audio chain (`Thread_Rx_Audio`)
  and the transmit core run at **12 kHz** between a ÷6 and a ×6 resampler (#154, [hifi4.md](hifi4.md#i2s-on-flexcomm25-dma1)) **[fact]**.
- **Gain registers are in 0.5 dB steps.** Every dB-valued register is converted with `i2f_scaled`(v, −1) = v / 2 before 10^(x/20)
  (`FUN_00234730`; e.g. reg 0x20 at 0x2264C8, reg 0x13 at 0x225A9E, reg 0xF at 0x225E26) **[fact]**. This applies to regs 0x0F, 0x11–0x13,
  0x20–0x23, 0x31, 0x32, 0x3B, 0x58, 0x60, 0x68, 0x4014–0x4016, 0x4025, 0x4026. hifi4.md called reg 0x20 "signed dB"; it is half-dB.
- Many settings use a **"bit 12 = on, bits 11–0 = value"** word (frequency in Hz ≤ 5999 for the 12 kHz stages) **[fact]**.
- All arithmetic is float32 **[fact]**.

Library helpers used below **[fact: code and polynomial tables]**: `vec_sum_sq` 0x234BE0 (Σx²), `sqrtf_` 0x235C8C, `divf_` 0x235BA8,
`log10f_` 0x2190F0, `pow10f_` 0x218B70, `tanf_` 0x219690 (table 0x200890: 1/3, 0.1333, 0.0540), `cosf_` 0x218FC0, `sinf_` 0x219560,
`atan2f_` 0x218E60, newlib `powf` 0x2294E0, `cosf` 0x2293E0 and `sinf` 0x229460 (#184), `i2f_scaled` 0x234730 (float(i)·2^s), `f2i_scaled` 0x234710, `vec_scale_f32` 0x234F40, `fir_init` 0x233984,
`fir_process` 0x233A10, `iir_cascade_init` 0x2340FC, `iir_cascade_process` 0x2341C0.

## Receive chain

```mermaid
flowchart TB
  subgraph RP["Thread_Rx_Path, 72 kHz, 24 samples"]
    IN["FC3 RX IF<br/>int → float"] --> AGC["if_agc_process<br/>regs 0x62 0x63 0x66 0x67 0x68"]
    AGC --> MET["if_meter_tick<br/>reg 3, reg 0x4005"]
    AGC --> DEM{"rx_demod_dispatch<br/>reg 6"}
    DEM -- "0–7" --> WV["ssb_weaver_demod<br/>NCO 18 ∓ 2 kHz"]
    DEM -- "8" --> AM["am_demod<br/>Hilbert envelope"]
    DEM -- "9" --> FM["fm_demod<br/>discriminator + noise squelch"]
  end
  WV & AM & FM --> PUSH["rx_audio_push_block<br/>12 blocks"]
  subgraph RA["Thread_Rx_Audio, 12 kHz, 48 samples"]
    DEC["÷6"] --> PRE{"reg 6 = 9?"}
    PRE -- "FM" --> FMP["fm_audio_post<br/>CTCSS, DCS, HPF, de-emph"]
    PRE -- "other" --> ZI["cw_zero_in_estimator<br/>reg 4"]
    FMP & ZI --> NOTCH["manual_notch<br/>reg 0x52"]
    NOTCH --> SNR["spectral_nr<br/>regs 0x4022/23"]
    SNR --> ALE["lms_ale_nr<br/>reg 0x40"]
    ALE --> AN["nlms_auto_notch<br/>reg 0x41"]
    AN --> CON["contour_peaking<br/>regs 0x42–0x44"]
    CON --> APF["apf_peak_filter<br/>reg 0x45"]
    APF --> LIM["af_limiter<br/>regs 0x57/0x58"]
    LIM --> BA["branch A: hi/lo-cut 0x46/0x47<br/>RX EQ 0x48–0x50, delay"]
    LIM --> BB["branch B: hi/lo-cut 0x54/0x55<br/>AESS low-pass 0x4020, delay 0x56"]
    BA & BB --> INT["×6 each"]
  end
  PUSH --> DEC
  INT --> OUT["A → RX block 0x2CAC50, B → 0x2CACB0<br/>→ routing (codec, SPI, recorder)"]
```

### Rx_Path (72 kHz)

| Address | Ghidra name | What it computes | Registers | Tag |
|---|---|---|---|---|
| 0x220EE0 | `rx_demod_dispatch` | Copies the block, runs `if_agc_process`, then by reg 6: 0, 2, 4, 6 → `ssb_weaver_init`(0) + `ssb_weaver_demod`; 1, 3, 5, 7 → (1); 8 → AM; 9 → FM; anything else passes through | 6 | [fact] |
| 0x21F0DC (+0x21EF90 init, 0x21F004 params) | `if_agc_process` | **Feed-forward AGC, one gain per block.** Level = √(Σx² / 24) (1/24 = 0x3D2AAAAB at 0x21F0F6), averaged with the previous block. Wanted gain = min(Gmax, 0.2512 / level): target 0.2512 = **−12 dBFS** (0x3E809BCC at 0x21F088). **Attack** is immediate and the gain is applied to the previous block (one block = 333 µs look-ahead). **Hang** 20 ms (counter step 1/60 per block, 0x3C888889). **Decay** linear in dB, 40 dB per reg-0x66 ms | 0x62 ≠ 0: AGC on (0: fixed gain Gmax). 0x66: decay time in ms, 20–4000 (default 3000). 0x67: gain 10^((x − 255)·0.025) (0x204BD0 = 0.025). 0x63: Gmax = g67 · 0.2512 · 10^((255 − x)/40) (`if_agc_params` 0x21F06B–0x21F091, used as the ceiling at 0x21F137), i.e. the **AGC gain ceiling** in 0.5 dB steps below 255; the DSP default 0xE7 gives Gmax = g67 exactly. MAIN sends a per-band factory byte (below). 0x68: fixed input gain, 0.5 dB steps (MAIN writes 0x94 = +74 dB) | [fact] constants and flow; units of 0x66 [inference] |
| 0x21F320 (+0x21F348 `meter_to_reg4005`, 0x21F388 `status_reg3_update`) | `if_meter_tick` | Every 60 blocks (20 ms): reg 0x4005 = linear RMS level before the AGC (PWM meter); reg 3 high byte = min(255, (65535·rms) >> 6); reg 3 low byte = 255 − 2·(Gmax_dB − gain_dB) = **AGC gain reduction in 0.5 dB steps** | writes 3, 0x4005 | [fact]; reg 3 low byte as S-meter source [inference, MAIN averages it] |
| 0x21D8A0 / 0x21D940 | `ssb_weaver_init` / `ssb_weaver_demod` | **Weaver SSB/CW demodulator.** NCO 1 at (±2000 + 18000) Hz, 2π/72000 (0x206EA8/0x206EAC), I/Q mix; ÷6 with 0x2373D0 (LP 4.9 kHz); 9-section LP 0x237440 (1.97 kHz at 12 kHz) on I and Q; NCO 2 at 2 kHz (π/3 per sample at 12 kHz) and I·cos + s·Q·sin; ×6 with gain 6 and 0x2373D0. Param 0 (CW-U, USB) sets s = −1 → NCO 1 at 16 kHz; param 1 (CW-L, LSB) → 20 kHz. So the SDR delivers the signal with its (suppressed) carrier at **18 kHz** in a real 72 kHz stream, and the audio passband is 0–4 kHz | 6 | [fact: constants]; carrier position [inference] |
| 0x21D5B0 / 0x21D5C8 | `am_demod_init` / `am_demod` | Analytic signal (`hilbert_iq` 0x225370: 71-tap FIR 0x205840 for Q, I = input delayed 35 samples), envelope √(I² + Q²), DC blocker y = x − x₋₁ + 0.999·y₋₁ | — | [fact: structure]; coefficient values [fact per the FLIX listing, not re-checked] |
| 0x21D650 / 0x21D68C | `fm_demod_init` / `fm_demod` | Analytic signal, mix by an NCO of −2π/3 per sample (−24 kHz, fs/3; 0xC0060A92), polar discriminator atan2(x·conj(x₋₁)) × 1.6225, hold on zero input. **Noise squelch level:** discriminator output through the 5-section BP 0x2368D0 (9–15 kHz at 72 kHz), Σ\|n\| over 1800 samples (25 ms), scaled into **reg 1 high byte** | writes reg 1 bits 15–8 | [fact]; why FM sits at 24 kHz and SSB at 18 kHz is open |
| 0x224960 | `rx_aux_in_gain` (was `rx_loop_gain`) | Gain from reg 0x60 (0.5 dB) on **codec ADC channel 1** (`codec_in_fifo_pop`(1)), which then replaces the demodulator output as the Rx_Audio input; only when reg 6 = 10 and reg 10 n0 = 1 (`Thread_Rx_Path_entry` 0x2262FC). MAIN never sends 10 (#184) | 0x60 | [fact]; purpose [inference, below] |
| 0x224814 | `rx_out_gain_mute_update` | Per-output gain from regs 0xE / 0xD (0.5 dB; MAIN's 0xF000 in FM = mute), applied with a ±1 clip in the sink `codec_out_sink` (0x224604); reg 0x10 bit 0 or the GPIO select starts a soft mute through the 1 ms raised-cosine ramp (`mute_ramp_step`) | 0xD, 0xE, 0x10 | [fact] |
| 0x225AB4 | `play_gain_update` | reg 0x13 → 10^(x/40), the gain of the playback reader `playback_ring_read` | 0x13 | [fact] |

### Rx_Audio (12 kHz, 48 samples)

| Address | Ghidra name | What it computes | Registers | Tag |
|---|---|---|---|---|
| 0x21F484 | `rx_audio_chain` | ÷6 (0x2373D0), the stages below in order, ×6 per branch. reg 6 = 9 runs `fm_audio_post`, reg 6 = 10 runs neither it nor the zero-in, anything else runs `cw_zero_in_estimator` | 6 | [fact] |
| 0x21D270 (+0x21D234 `cw_zero_in_init`) | `cw_zero_in_estimator` (was `status_reg4_update`) | Non-FM modes. Analytic signal; sums the per-sample phase step (atan2) over 240 samples (20 ms) → frequency f (× 12000/2π, 0x203AC8). If f ≥ 10 Hz and the amplitude A = √2·RMS ≥ 1e-5, a **3-bin Goertzel tone gate** checks that the 240 samples really hold one tone at f (below); while the gate is open: reg 4 = round(clamp(f − pitch, ±999) / 10), else 0x7FFF. MAIN adds reg 4 × 10 Hz to the VFO: **CW auto zero-in** | 0x61: bit 12 on, bits 11–0 = CW pitch | [fact] |
| 0x21D0D0 / 0x21D140 / 0x21D190 / 0x21D1E0 (+0x21D0A8 reset) | `zeroin_goertzel_tune` / `_step` / `_mag` / `zeroin_tone_gate` | The zero-in gate (#184). `tune`(f): three Goertzel bins at f, f − 15 Hz and f + 15 Hz (±15.0 at 0x206DDC/0x206DE0), coefficient 2·cos(2π f / 12000) (`cosf` 0x2293E0, 2.0 at 0x203AC0). `step`(x): s = x + c·s₁ − s₂ per bin, run over the same 240 samples. `mag`: \|X\| = √(s₁² + s₂² − c·s₁·s₂). `gate`(state): **closed → open** when the centre bin > 90.83·A (0x203ACC; an ideal tone gives 120·A over 240 samples, so ≈ −2.4 dB) **and** beats both ±15 Hz bins; **open → closed** only when the centre bin drops below 90.83·A. So reg 4 follows only a clean single carrier, and the side-bin test is the hysteresis | — | [fact] |
| 0x220B5C (+0x220B30) | `fm_audio_post` | FM only: CTCSS and DCS decoders, then 5-section HP 0x236AB0 (−70 dB below 200 Hz, flat above 300 Hz: removes the subtone); if reg 0x3A bit 0, 8-section 0x236B20 (≈ −6 dB/octave above 400 Hz: **de-emphasis**) | 0x3A | [fact: response]; names [inference] |
| 0x21F6D0 / 0x21F7EC / 0x21FA48 | `ctcss_init` / `ctcss_config` / `ctcss_detect` | LP 0x236940, keep 1 of 8 (1.5 kHz), BP 0x236990. **Sliding Goertzel** over 200 samples (133 ms) at 0.985 f, f, 1.015 f. Lock when the centre bin beats both sides and is > 50.1 × the window amplitude; unlock below 3.16 × (10 dB hysteresis). Result → reg 1 bit 6. The coefficients come from `ctcss_goertzel_init` 0x21F968 (on a tone change: also clears the 3 bin states and the 200-sample window) and `ctcss_goertzel_retune` 0x21F8BC (on every lock change): sin and 2·cos of 2π f_bin / 1500 (2π, 200, 1/200, 1/1500 at 0x204CB0..BC); **side bins at 0.985 / 1.015 f while unlocked and 0.98 / 1.02 f while locked** (0x3F7C28F6 / 0x3F81EB85 vs 0x3F7AE148 / 0x3F828F5C), so a locked tone may drift ±2 % before a side bin wins (#184) | 0x53: bit 12 on, tone index 1–50 into 0x204BE0 | [fact]; purpose of the wider locked spacing [inference] |
| 0x21FD20 / 0x21FDBC (+0x220224) | `dcs_init` / `dcs_config` / `dcs_detect` | **DCS decoder.** Builds the 23-bit Golay word from the 9-bit code + 0x800, normal / inverted / either; LP 0x236A30 + 109-tap FIR 0x2051C0; 2136-sample buffer (23 bits at 134.4 bit/s); bit-phase search, slicing at ±0.7 × RMS. Result → reg 1 bit 7 | 0x51 (MAIN writes 0) | [fact: structure]; Golay [inference] |
| 0x21E530 (+0x21E520) | `manual_notch` | Three identical notch biquads, b = g·[1, −2 cos ω, 1], a = [1, −2g cos ω, 2g − 1], g = 1/(1 + α), α = k·tan(ω/35). Type 1 k = 0.05 (−3 dB width ≈ 4 Hz at 700 Hz), type 2 k = 1.4705 (≈ 115 Hz at 700 Hz) | 0x52: type in bits 15–12, frequency bits 11–0 | [fact] |
| 0x21E0F4 (+0x21DF20, 0x21DFE4, 0x21E24C) | `spectral_nr` | **STFT Wiener noise reduction.** 512-point periodic-Hann frames, hop 256 (21.3 ms), overlap-add, complex FFT `fft512_cplx` 0x2174B0 with twiddles 0x200D00, inverse 0x217D10. Per bin γ = \|X\|² / N; **decision-directed** a-priori SNR ξ = 0.98·G²·γ₋₁ + 0.02·max(γ − 1, 0); G = ξ / (1 + ξ); out = \|X\|·(1 − β + β·G) with the input phase. Noise PSD N: mode 1 learns (pass-through), 2 freezes the average, 3 tracks N = 0.99 N + 0.01 \|X\|² | 0x4022: mode 0–3 (0 bypass); 0x4023: depth β in % (≤ 100) | [fact] |
| 0x21DBD0 (+0x21DBB0) | `lms_ale_nr` | **LMS adaptive line enhancer** (keeps the correlated part = signal). Input gain reg 0x4025, LP 0x236850; 128 taps, reference delayed 33 samples; y = Σw·x, e = d − y (both clipped ±10); w ← w·(1 − 1e-6·leak) + μ·e·x, μ = min(reg 0x400B / 1000, 1.8). Output y × reg 0x4026; 1 s cross-fade when switched on | 0x40 bit 0 on; 0x400B μ (default 8); 0x400D leak (default 512); 0x4025/0x4026 gains | [fact] |
| 0x21C8BC (+0x21C890) | `nlms_auto_notch` | ×2 to 24 kHz (96 samples), LP 0x236850; **NLMS predictor**, 128 taps, delay ≈ 257 samples (10.7 ms); w ← leak·w + μ·e·x / max(Σx², 0.001), μ = reg 0x400C·1e-6, leak = 1 − reg 0x400E·1e-6. **Outputs the error** (removes steady tones), back to 12 kHz | 0x41 bit 0 on; 0x400C (1024), 0x400E (2) | [fact] |
| 0x21CC68 (+0x21CC50) | `contour_peaking` | One peaking biquad (Zölzer boost/cut), K = tan(π f / 12000), V = 10^(dB/20); on boost the output is rescaled so the peak stays near unity | 0x42: bit 12 on + frequency; 0x43: level −40 … +20 dB; 0x44: Q 1–10 (0 → 0.5) | [fact: ranges]; rescaling [inference] |
| 0x21C818 (+0x21C610, 0x21C670, 0x21C748) | `apf_peak_filter` | Type 1: resonator biquad, Q = 30, +60 dB peak × 0.001 (unity at the peak). Types 2–4: FIR band-pass = low-pass prototype × 2 cos(ω₀ n), prototypes of 295 / 197 / 103 taps (0x203120, 0x2035C0, 0x2038E0; lengths at 0x203100), ≈ 100 / 108 / 150 Hz wide | 0x45: type bits 15–12 = 1–4, centre = CW pitch | [fact] |
| 0x224ED8 (1, …) (+0x224E80) | `peak_limiter` (shared with the TX speech processor, instance 0) | 7-sample look-ahead; envelope √2·RMS over 7 samples; above the threshold gain = thr / env at once, linear release over 2·T[L] samples (T from 0x237500, 600 … 6); pre-gain 10^(0.003 L) | RX: 0x57 (bit 12 on, L ≤ 100), 0x58 threshold. MAIN never writes 0x57, so it is off | [fact] |
| 0x21EC40 (+0x21EC20) | `af_hicut` | Type 1: 1st-order bilinear low-pass (6 dB/oct); type 2: 3rd-order (18 dB/oct) | instance 0: 0x46; instance 1: 0x54 | [fact]; HI-CUT menu [inference] |
| 0x21E8B0 (+0x21E890) | `af_locut` | Same structure as high-pass | 0x47; 0x55 | [fact] |
| 0x220AA4 / 0x220470 (+0x220420, band 0x220790) | `rx_eq_3band` / `rx_eq_update` | Three peaking biquads like the contour: f ≤ 5999 Hz, −40 … +20 dB, Q 1–10 | 0x48–0x4A, 0x4B–0x4D, 0x4E–0x50 | [fact] |
| 0x21E82C | `branch_a_align_delay` | 128-sample delay, active only while the branch-B FIR is on: (257 − 1) / 2 = 128 = the FIR's group delay, so both branches stay time-aligned | (0x4020) | [fact] |
| 0x21E754 (+0x21E740) | `aess_lowpass_fir` (was `cw_fir_lowpass`) | **AESS crossover low-pass** on branch B (#184). 257-tap FIR, reg 0x4020 bits 15–12 = 1 (gentle: 0x203B70 / 0x203F80) or 2 (steep: 0x204390 / 0x2047A0), bits 11–0 = 700 or 1000 Hz (−3 dB there in all four tables; steep: −12.2 dB at 1000 Hz (700) and −13.5 dB at 1500 Hz (1000), −40.7 / −31.4 dB at 3 kHz; gentle ≈ −6 dB/octave). MAIN's `dsp_set_aess` sends 0x2000 \| 700 or 0x2000 \| 1000 (steep), 0 when the AESS level is 0 | 0x4020 | [fact: responses computed from the tables]; AESS crossover [inference, strong] |
| 0x21E6C4 (+0x21E6B0) | `branch_b_delay` | Delay of up to 1200 samples on branch B only; MAIN writes 32 (2.7 ms) | 0x56 | [fact]; why (acoustic alignment of the two speakers) [guess] |

**No noise blanker on the HiFi4.** None of the stages above is an impulse blanker, and MAIN sends its NB level to the SDR FPGA
(register 0x1A, [main/sdr-link.md](../main/sdr-link.md)), so the NB runs in the FPGA **[inference]**.

## Transmit chain

```mermaid
flowchart TB
  subgraph TP["Thread_Tx_Path, 72 kHz"]
    MIC["codec in ch0<br/>block 2"] --> SEL{"reg 10 n0"}
    PLAY["playback_ring_read<br/>block 3"] --> SEL
    TONE["test_tone_gen<br/>block 4"] --> SEL
    SEL --> VOX["vox_detector / antivox<br/>regs 0x21, 0x22 → reg 1 bit 4"]
    SEL --> G20["reg 0x20 gain"]
  end
  G20 --> D6["÷6"]
  subgraph CORE["tx_core_12k, 12 kHz, 4 samples"]
    D6 --> EQ["tx_param_eq_3band<br/>0x25–0x2D"]
    EQ --> SP["speech_processor<br/>0x2E/0x3B → reg 2 lo"]
    SP --> CMP["soft_knee_compressor<br/>0x401A–1F (off)"]
    CMP --> BPF["tx_bpf_select<br/>0x2F: 7 passbands"]
    BPF --> FMP["FM: HPF 293 Hz, gain 0x30,<br/>pre-emphasis 0x3A"]
    FMP --> LIMT["soft_knee_limiter<br/>0x4015–19 (off)"]
    LIMT --> U6["×6"]
  end
  U6 --> ALC["tx_alc<br/>0x31–0x34 → reg 2 hi"]
  ALC --> FMLP["FM: LP 3 kHz"]
  FMLP --> SUB["ctcss_encoder 0x35<br/>two_tone_test_gen 0x36/37<br/>dcs_encoder 0x38"]
  SUB --> GATE{"reg 0x4006 ≠ 0?"}
  GATE -- "yes" --> MOD["weaver_ssb_mod / am_modulator / fm_modulator"]
  GATE -- "no (default)" --> B1["block 1"]
  MOD --> B1
  B1 --> OUTP["txaf_out_push<br/>reg 0xF gain, clip, mute ramp → FC2"]
```

| Address | Ghidra name | What it computes | Registers | Tag |
|---|---|---|---|---|
| 0x2249D0 | `routing_regs_decode` | Splits regs 8/9/10 into the selector nibbles 0x263D50–0x263D5C | 8, 9, 10 | [fact] |
| 0x224798 | `codec_in_fifo_pop` | Pops one block of codec-in channel *ch* (Q31 → float), zeros if empty; ch 0 = mic (block 2), ch 1 = block 5 | — | [fact]; ch 0 = mic [inference] |
| 0x2248D8 (+0x2248A0) | `aux_in_gain_lp` | Block 5: gain reg 0x23, LP 0x2373A0 (4.9 kHz); only when reg 6 = 10 | 0x23 | [fact] |
| 0x2259E4 | `playback_ring_read` | Next block from the 4000-block ring 0x268E20 (filled by `playback_ring_fill` 0x225834 from the DISPLAY PLAY stream, ÷2 + IIR), gain from reg 0x13, clip ±1 | 0x13 | [fact]; PLAY source [inference] |
| 0x225264 | `test_tone_gen` | Sine, phase += f·2π/72000 (0x38B702D4), amplitude 10^(L/40); defaults 1000 Hz, −12 dB | 0x4013 f, 0x4014 L | [fact] |
| 0x2233FC / 0x223734 (+0x223320, 0x22338C) | `vox_detector` / `antivox_detector` | 3 blocks (1 ms) → LP 0x237360 → keep 1 of 9 (8 kHz). With reg 0xC bit 0, a 51-tap NLMS predictor (`nlms_51tap_update`) is used as a line enhancer first, but it is fed the wrong samples (bug, see below; MAIN keeps reg 0xC = 0). Level = 20 log10(Σ\|x\| / 160) over 20 ms; above the threshold → flag with 100 ms hang. Writes level·2 to reg 0x4008/0x4009, reg 0x400A = ch0 \| ch1 << 1 \| VOX << 2, reg 1 bit 4 = VOX = mic ∧ ¬speaker (`vox_state` 0x223A74) | 0x21 (VOX gain), 0x22 (anti-VOX), 0xC bit 0, 0x4011 μ, 0x4012 leak | [fact: 0x22354D, 0x223559, 0x223584]; VOX / anti-VOX [inference, strong] |
| 0x22313C | `tx_chain` | `tx_core_12k` → `tx_alc` → (FM: `fm_post_lpf`) → block 2 → `ctcss_encoder` → `two_tone_test_gen` → `dcs_encoder` → **if reg 0x4006 ≠ 0**: modulator by reg 6 (jump table 0x204EF0: 0/2/4/6 Weaver(0), 1/3/5/7 Weaver(1), 8 AM, 9 FM, 10 none) → block 1 | 6, 0x4006 | [fact: gate `beqz` at 0x2231BD on reg 0x4006 (0x20077F00 + 0x10C)] |
| 0x2220E8 (+0x2220A0) | `tx_core_12k` | ÷6 (0x2373D0) → EQ → processor → compressor → BPF → FM block → limiter → ×6 (gain 6, 0x2373D0) | 6 | [fact] |
| 0x221854 + 0x221220 / 0x221540 | `tx_param_eq_3band` + `tx_eq_band3_update` / `tx_eq_band_update` | Three peaking biquads (Zölzer), K = tan(π f / 12000), gain −40 … +20 dB, Q 1–10 | 0x25–0x2D | [fact] |
| 0x224ED8 (0, …) | `peak_limiter` (instance 0) = **speech processor** | Pre-gain 10^(0.003 L), 7-sample look-ahead limiter (above), release from 0x237500 (100 ms … 1 ms); every 5 calls **reg 2 low byte** = gain reduction in 0.5 dB steps | 0x2E (on + level, SSB only), 0x3B threshold | [fact] |
| 0x222244 | `soft_knee_compressor` | dB-domain gain computer with soft knee (T, W, R) and attack/release smoothing α = exp(−ln 9 / (t·12000)) | 0x401A on (default off), 0x401B T, 0x401C attack 10 ms, 0x401D release 300 ms, 0x401E knee, 0x401F ratio 10; no MAIN writer | [fact: 0xC00C9F54 = −ln 9, 12000.0 = 0x463B8000] |
| 0x2221D0 | `tx_bpf_select` | reg 0x2F = 1–7 picks the cascade 0x236C50[v − 1] (section counts 0x204DA0: 9, 9, 10, 11, 12, 9, 8): passbands 35–3199, 70–3035, 117–2930, 246–2824, 363–2766, 23–3352, 23–4137 Hz at 12 kHz, i.e. the SSB TX BPF menu | 0x2F | [fact] |
| 0x222D34 (+0x222D00) | `fm_tx_audio` | HP 0x2371F0 (293 Hz) → gain (reg 0x30 & 0xFF)/255 → if reg 0x3A bit 0, 0x237240 (+6 dB/octave 200 Hz – 3 kHz): **pre-emphasis** | 0x30, 0x3A | [fact: response]; name [inference] |
| 0x222E30 (+0x222E10) | `soft_knee_limiter` | Same gain computer with R = ∞ | 0x4015 on (off), 0x4016–0x4019 | [fact] |
| 0x221F98 + 0x221E84 (+0x221E40) | `tx_alc` + `tx_alc_update` | Per 72 kHz sample: envelope e ← c·\|x\| + (1 − c)·e with c = 0.5 (attack, `const.s 3` = 0.5) when \|x\| ≥ e, else c = **powf(0.5, reg 0x33)** (release; `powf` 0x2294E0 at 0x221F8D); gain = P·G1 / max(e, P·G2), y = x·gain (`divf_` 0x22200A); **reg 2 high byte** = ALC gain reduction. reg 0x34: bit 12 = on (off: pass-through), bits 11–0 = level P in % (0 → 1, clamped to 100). G1 = 10^(reg 0x31 / 40), G2 = 10^(reg 0x32 / 40) (half-dB). So G1 is the output ceiling and G2·P the level below which the gain stops rising | 0x31/0x32 (−43 SSB, −54 AM, −56 FM half-dB), 0x33, 0x34 | [fact: flix.dis 0x221E84–0x22202A] |
| 0x22309C (+0x223080) | `fm_post_lpf` | LP 0x2372E0 (3.0 kHz at 72 kHz), bypassed by reg 0xC bit 8 | 0xC | [fact] |
| 0x222510 (+0x2224E0) | `ctcss_encoder` | Adds A·sin φ, φ += tone·2π/72000 (table 0x204DD0), A from reg 0x11 | 0x35 (bit 12 + index 1–50), 0x11 | [fact] |
| 0x222AF0 (+0x222AB0) | `two_tone_test_gen` | Two sine generators, on when reg 0x36/0x37 top nibble = 1, f = bits 11–0 | 0x36, 0x37 (MAIN writes 0) | [fact]; name [inference] |
| 0x222688 (+0x222640) | `dcs_encoder` | 23-bit Golay DCS word (normal / inverted), NRZ at 24 kHz (179 samples per bit ≈ 134 bit/s), shaped by the 109-tap FIR 0x205380, ×3 to 72 kHz | 0x38, 0x39, 0x11 | [fact]; DCS [inference, strong] |
| 0x221B10 / 0x221BB8 | `weaver_ssb_mod_init` / `weaver_ssb_mod` | Mirror of the demodulator: ÷6, 2 kHz NCO, 0x237440 LP pair, ×6, NCO at 18 ∓ 2 kHz (2π/72000, 0x221D65) | 6 | [fact] |
| 0x2218E0 + 0x221908 | `am_modulator_init` / `am_modulator` | DC blocker (0.999, 0x3F7FBE77 at 0x22190E), 0.3·(1 + m)·sin φ with φ += 2π/3 (**24 kHz carrier**), then the 6-section BP 0x236BD0 (≈ 21–29 kHz) | 6 = 8 | [fact] |
| 0x221A10 + 0x221A30 | `fm_modulator_init` / `fm_modulator` | φ += x·k + 2π/3, out = sin φ; k = (reg 0x4007 / 256)·7500·2π/72000 (7500.0 = 0x45EA6000 at 0x221AED): 24 kHz centre | 0x4007 (default 0x3A) | [fact] |
| 0x225BE8 | `txaf_out_push` | If the FC2 FIFO has room: clip(x·g, ±1), g from reg 0xF, × mute ramp, float → Q31; source block 1 (reg 9 n0 = 2) or 5 (= 1) | 0xF, 9 | [fact] |
| 0x225408 (+0x2253F0, 0x225478, 0x22548C) | `mute_ramp_step` | States on / off / falling / rising, one step per sample through the 73-point raised cosine 0x2375D0: **1.0 ms** fades | — | [fact] |
| 0x225DC4 | `tx_mute_ctrl` | mute = reg 0x10 bit 1 or GPIO P0_4 (reg 0xC top nibble = 1); writes the VOX state to GPIO byte 0x40100044 | 0xF, 0x10, 0xC | [fact] |
| 0x225A84 | `rec_gain_update` | Recorder gain from reg 0x12 (MAIN 8 = +4 dB) for `rec_resample_sink` (`FUN_002255B4`) | 0x12 | [fact] |

**The modulators are gated off.** `tx_chain` runs the Weaver / AM / FM modulators only when reg 0x4006 ≠ 0; its default is 0 and neither MAIN
nor the M33 writes it (register scan; checked store by store in #184, below) **[fact]**. So in normal use block 1 (the TX AF stream to the SDR) is **baseband audio** from the
12 kHz core, and the modulation is done in the SDR FPGA **[inference]**. The DSP has no CW keying or side-tone source of its own; MAIN sets reg
10 to the mic in CW, so CW is generated in the FPGA too **[inference]**.

## Corrections to earlier pages (made here)

- **reg 2** is not the S-meter: low byte = speech-processor gain reduction (COMP meter), high byte = ALC gain reduction, both 0.5 dB steps
  **[fact: 0x22519B, 0x222034]**. The S-meter source is reg 3's low byte (AGC gain reduction) **[inference]**.
- **reg 0x4005** (PWM meter) is the linear IF RMS before the AGC **[fact]**.
- Gain registers are half-dB (above).
- The 7 voice passbands (0x236C50) are the 12 kHz TX BPF, selected by reg 0x2F **[fact]**.
- `FUN_002233FC`'s 51-tap NLMS is part of the VOX detector, not a TX signal stage **[fact]**.
- #184: MAIN's DNR does write regs 0x40 and 0x4022/0x4023 (levels 1–7 Wiener, 8–15 LMS ALE). The branch-B FIR is the AESS
  low-pass, not a CW filter (`aess_lowpass_fir`). `rx_loop_gain` reads codec ADC channel 1, not an output FIFO (`rx_aux_in_gain`).
  0x21BE54 is the IPC category-3 (version) handler and 0x21BE20 the category-1 (mute) one. 0x233410 is called from
  `regfile_set_defaults` too, and the register file is cleared by the M33, not by that call (details below) **[fact]**.

## Answers to the #86 open points (#184)

The points left open by #86, answered from the firmware where possible. What needs the FPGA netlist or the board is in #193.

### IF placement, what the FPGA gets, and who writes reg 0x4006

- **What the DSP expects** **[fact: constants above]**: a real 72 kHz RX IF. SSB/CW: carrier at 18 kHz (fs/4) with the sideband
  inverted (USB → NCO 1 at 16 kHz, LSB → 20 kHz). FM: carrier at 24 kHz (NCO −2π/3 per sample). AM: anywhere, because `am_demod`
  takes the Hilbert envelope. The TX modulators mirror this: Weaver at 18 ∓ 2 kHz, AM and FM carriers at 2π/3 = 24 kHz.
- **Who writes reg 0x4006.** On the HiFi4 only `regfile_set_defaults`: `s16i a12, a9, 0x10c` at 0x21BFDC with a9 = 0x20077F00 and
  a12 = 0 (set at 0x21BEDD), i.e. the default 0. No other store to 0x2007800C exists among the 14 users of the 0x20077F00 base; the
  only other access is `tx_chain`'s read. The M33 writes only regs 0, 1 and 0x4000 ([ipc.md](ipc.md)), and MAIN has no setter and no
  0x4006 operand. So only the console `w` command or CAT `SPDW4006…` can set it **[fact: flix.dis, decomp/ifdsp/m33,
  decomp/main]**. In service the TX AF stream is the 12 kHz core's audio up-sampled to 72 kHz, and the SDR FPGA modulates
  **[inference, strong]**. The DSP modulators are a development or test path **[inference]**.
- **Why 24 kHz for FM.** fs/3 makes the NCO a 3-sample cycle (cos = −1/2, sin = ±√3/2), so the FM mixer and both AM/FM modulators
  need no phase accumulator or table, and the same carrier serves RX and TX **[inference]**. MAIN cannot be the one that moves the
  carrier: it tunes the SDR RX NCO with ±(1500 + shift) in SSB and no offset in AM/FM (SDR reg 0x18/0x19, `sdr_upd_r18_rx_freq`), and sends the modulation
  class in SDR reg 0x0A (0 CW, 1 AM, 2 FM, 3 LSB, 4 USB, 5 RTTY) ([main/sdr-link.md](../main/sdr-link.md)). A single fixed IF in the
  FPGA cannot put the SSB carrier at 18 kHz and the FM carrier at 24 kHz, so the FPGA must shift the IF by class **[inference]**.
  Confirming that needs the DDC in the netlist (#193).

### DNR: MAIN drives both noise reductions, split by level

The #86 page said MAIN writes neither NR register. That was wrong: the register map in [control-link.md](control-link.md#register-map)
already lists the writers. `dsp_link_poll` calls `dsp_set_dnr_r40`, `_400b`, `_400d`, `_4022`, `_4023`, `_4025` and `_4026` in one
pass (decomp/main 0xFFF9C555 file). Each of them reads the PTT-side VFO record +0x06 (bit 4 = DNR on, bits 0–3 = level 1–15, #161),
sends 0 when DNR is off or the mode is FM / DATA-FM (6, 7, 10, 11), and otherwise indexes a 16-entry table by the level
**[fact: `dsp_set_dnr_r40` 0xFFF9E750, `dsp_set_dnr_4022` 0xFFF9FE2A; tables read from the MAIN image]**:

| DNR level | 0x4022 (Wiener mode) | 0x4023 (depth β %) | 0x40 (LMS ALE) | 0x400B (μ ×1000) | 0x400D (leak ×1e-6) | 0x4025 (in gain, half-dB) |
|---|---|---|---|---|---|---|
| 1–7 | 3 (track N) | 32, 40, 48, 56, 64, 72, 80 | 0 | 0 | 0 | 0 |
| 8–15 | 0 (bypass) | 0 | 1 | 2304, 1792, 1280, 768, 256, 224, 192, 160 | 32, 64, 96, …, 256 | −17, −17, −18, −19, −20, −21, −20, −21 |

Tables 0xFFF87F5A, 0xFFF87F7A, 0xFFF87FBA, 0xFFF87F1A, 0xFFF87F3A, 0xFFF87F9A; reg 0x4026 (0xFFF87FDA) is 0 at every level. So
**levels 1–7 are the STFT Wiener NR** in its tracking mode with a deeper mix per step, and **levels 8–15 are the LMS line enhancer**,
with μ falling from 1.8 (2304 is clamped) to 0.16, the leak rising, and −8.5 … −10.5 dB of input gain **[fact]**. The DSP's own
defaults (0x400B = 8, 0x400D = 512) are never used while DNR is on.

### ALC (AMC) release, regs 0x33, 0x34 and 0x63

- **reg 0x33** → release coefficient c = powf(0.5, x) per 72 kHz sample (`tx_alc_update` 0x221F79–0x221F90; `FUN_002294E0` is
  newlib's `powf` wrapper: its matherr record names `"powf"` (0x206414), and `FUN_00223AB4` uses it as powf(10, x/20)). Below
  the envelope, e ← c·|x| + (1 − c)·e, so e decays with a time constant of 2^x / 72000 s **[fact: code; arithmetic]**. MAIN's AMC RELEASE TIME
  FAST / MID / SLOW = 0x11 / 0x12 / 0x13 → **1.8 / 3.6 / 7.3 s**; FM 0x0C → 57 ms. The attack coefficient is 0.5 per sample.
- **reg 0x34** = bit 12 ALC on, bits 11–0 = output level P in % (clamped 1–100). P scales both G1 and G2. MAIN sends `AO` | 0x1000
  in SSB, AM and DATA, 100 | 0x1000 in FM, and 0 (ALC off) in CW, RTTY and during voice playback (`dsp_set_amc_level` 0xFFF9E480)
  **[fact]**. This block is MAIN's AMC (automatic mic gain control) **[inference, strong]**.
- **reg 0x63** = the IF AGC **gain ceiling**: Gmax = g67 · 0.2512 · 10^((255 − x)/40), 0.5 dB per step (`if_agc_params` 0x21F06B)
  **[fact]**. MAIN sends one of the five cfg105 bytes 0x4674..0x4678 (`SPN` entries 28..32) by RX band ≤ 7.5 / 14.5 / 21.5 / 41.5 /
  75 MHz (`dsp_set_freq_range_param` 0xFFF9FB6E) **[fact]**. Because reg 3's low byte (the S-meter source) is 255 − 2·(Gmax_dB −
  gain_dB), these bytes are a per-band gain and S-meter calibration **[inference]**. The values need an EEPROM dump (#193).

### Rx_Audio branch B is the AESS speaker feed; reg 6 = 10 is an external-audio mode

- `Thread_Rx_Audio_entry` (0x220F90) runs `rx_audio_chain`(in, A, B) and pushes A into FIFO 0 and B into FIFO 1. `rx_audio_push_block`
  (0x220F74) pops them into RX blocks 0x2CAC50 (A, routing source 3) and 0x2CACB0 (B, routing source 6) **[fact]**.
- MAIN sets reg 8 = 0x3263 only for speaker route 2 (internal and external speaker both on, `speaker_route` 0x20FCC, see
  [main/peripherals.md](../main/peripherals.md)); every other RX route uses 0x3233 **[fact: decomp/main fffb70c9 file]**. With 0x3263,
  codec DAC channel 0 gets branch B and channel 1 gets branch A ([control-link.md](control-link.md#audio-routing-registers-8-9-10-77-fact)).
- Branch B shares the NR, notch, contour, APF and limiter with A, but not MAIN's HCUT/LCUT (0x46/0x47) or the AF tone EQ. Its own
  hi/lo-cut (0x54/0x55) is never written, so it is off. It then runs `aess_lowpass_fir`: with AESS on (`dsp_set_aess`: level ≠ 0) a
  steep 700 or 1000 Hz low-pass, and branch A is delayed by the FIR's 128-sample group delay. So with both speakers on and AESS on,
  one speaker plays the full processed audio and the other a low-passed copy: the **AESS crossover** **[inference, strong]**. Which
  speaker is which, where the AESS level `AS1` is applied (it is not sent to the DSP), and why B gets 32 more samples of delay (reg
  0x56) are in #193.
- **reg 6 = 10** (never sent by MAIN): `Thread_Rx_Path_entry` 0x2262FC feeds Rx_Audio from **codec ADC channel 1** × reg 0x60
  (`rx_aux_in_gain`) instead of the demodulator, if reg 10 n0 = 1. Routing source 4 then gets the raw SDR block, `rx_audio_chain`
  skips both the FM post-processing and the zero-in, the TX side takes ADC channel 1 as source 5 (`aux_in_gain_lp`, reg 0x23), and the
  modulator table has no entry for 10 **[fact]**. A value 1 in reg 10's low nibble also makes the M33 switch the codec's right
  MICPGA to IN1R ([control-link.md](control-link.md)). So reg 6 = 10 runs an external analog input through the DSP audio chain, with
  no demodulator. A factory test mode is likely **[inference]**. MAIN sends neither 6 = 10, a reg 10 low nibble of 1, reg 0x23 nor
  reg 0x60 **[fact]**.

### The VOX / anti-VOX NLMS is fed the wrong samples (a bug, dormant)

In `vox_detector` (and identically in `antivox_detector` at 0x2237F4) the enabled path is **[fact: flix.dis 0x2234B9–0x223534]**:

1. 72 samples (3 blocks) are low-passed (0x237360) and every 9th is kept: 8 samples at 8 kHz, written back to the start of the
   input buffer (+40).
2. Bundle 0x2234BC `{ addi a2, a9, −108; mov.n a11, a2 }` then `memcpy(hist + 101, a11, 32)`. All slots of a FLIX bundle read their
   operands before any slot writes, so a11 is the **old a2**, the function's first argument: the raw 72 kHz block. The 8 newest
   history samples, which are also the NLMS desired signal d (`nlms_51tap_update`(x = hist, w, d = hist + 101, e, y, μ, leak)), are
   therefore samples 0–7 of the last raw block, not the 8 decimated ones.
3. The NLMS output y (0x25C75C) then overwrites the decimated samples, and the level is summed from y.

So with reg 0xC bit 0 set, the low-pass and decimation are thrown away, and the predictor sees 8 adjacent 72 kHz samples out of
every 1 ms. Even if the bundle ran its slots in order (it does not), a11 would equal a2 and the copy would be a no-op, so the
decimated samples never reach the predictor either way. This is a source-level bug (the wrong pointer passed to the copy)
**[inference, strong]**. It has no effect in service: MAIN writes reg 0xC = 0, so the plain path (Σ|x| over the decimated samples)
runs **[fact]**.

### Helpers that were unread

- `FUN_0021D0D0` / `D140` / `D190` / `D1E0` are the zero-in's three-bin Goertzel tone gate, and `FUN_0021D234` its init (rows in the
  Rx_Audio table) **[fact]**.
- `FUN_0021F8BC` / `F968` are the CTCSS Goertzel coefficient retune / init. The side bins widen from ±1.5 % to ±2 % while a tone is
  locked (`ctcss_detect` row) **[fact]**.
- `FUN_002293E0` / `FUN_00229460` are newlib `cosf` / `sinf` (|x| ≤ π/4 goes straight to the kernels 0x22A610 / 0x22B420, else
  `rem_pio2f` 0x22A320 and the quadrant switch), and `FUN_002294E0` is `powf` **[fact]**.

### IPC: the FLIX-hidden operands, and `xthal_set_region_attribute`

Read from the objdump listing at the branch targets where the per-function listing had desynchronised (0x21C438, 0x21C460)
**[fact]**:

| Address | Code | Value |
|---|---|---|
| 0x21C405 | `{ addi a14, a1, 127; movi a11, 30 }` → `rpmsg_lite_create_ept` | DSP endpoint **30 = 0x1E** |
| 0x21C438 | `{ l32r a10, 0x40111000; movi a11, 1 }` → `MU_SetFlags` | flag **1** to the M33 |
| 0x21C460 / 0x21C463 | `SEMA42_Init(0x40112000)` | |
| 0x21C469 | `{ movi a11, 0; movi a12, 3 }` → `SEMA42_Lock` | **gate 0, processor 3** |
| 0x21C472 | `{ l32r a10, 0x40111000; movi a11, 3 }` → `MU_SetFlags` | flag **3** |
| 0x21BD49–0x21BD63 | `ipc_handle_msg`: `bnei +9, 1`, `beqi +10, 2`, then category 0 / 1 / `beqi.w15 a9, 3` | version 1.2; categories **0, 1 and 3** |
| 0x21BDB4–0x21BDC0 | `rpmsg_lite_send(rl, ept, 40, msg, 152, 0)` | reply to endpoint **40**, 0x98 bytes |

Corrections to [ipc.md](ipc.md): the DSP does handle **category 3**. Category 1 goes to 0x21BE20 (now `handle_msg_audio`): it
accepts command 0 with param[0] = 0 or 1 (the M33's "Mute off / on") and does nothing else; another param gives error 2, another
command error 3. Category 3 goes to 0x21BE54 (now `handle_msg_version`, formerly misnamed `handle_msg_audio`): command 0 sets param[0]
= 1, so the M33 would print `DSP Version 0001`. Any other category gives type 2, error 3. The literal 0x40112000 (pool 0x2069B0) is
used only by `SEMA42_GetInstance` and `Thread_Ipc`, so the DSP never releases gate 0.

**0x233410 is the Cadence HAL `xthal_set_region_attribute`**, in its region-protection (cacheattr) variant **[fact: structure]**.
It returns 0 for size 0, −3 when vaddr + size wraps, and −2 for a partial region when flag bit 9 (`XTHAL_CAFLAG_EXACT`) is set.
It reads the current attributes with `FUN_00233580` (now `xthal_get_cacheattr`: `rdtlb1` at 0xE0000000, 0xC0000000, …, 0 for the 8 × 512 MB
regions, one nibble each). It then rewrites the nibbles of the regions the range touches, with the "no partial" (bit 10), expand
(bit 8), no-writeback (bit 11) and no-invalidate (bit 12) flag tests and the class table at 0x200070. Finally it writes them with
`FUN_002335A0` (now `xthal_set_cacheattr`: `witlb`, skipping the region it runs from, then `wdtlb` for each region) and calls
0x236450 / 0x2364B0 / 0x2364D0, the cache writeback / invalidate helpers **[inference]**. cattr 2 is `XCHAL_CA_BYPASS` (the code special-cases 2 and 6
as bypass and 4 and 5 as write-back) **[inference: HAL encoding]**. There are three calls **[fact]**: the DSP main (0x21C4AD,
0x21C4C2) passes (0x20060000, 0x31E0, 2, 0) and (0x20060000, 0x20060000 − 0x20060000 = 0, 2, 0), which returns at once, and
`regfile_set_defaults` (0x21BE8F) passes (0x20070000, 0x10000, 2, 0). Earlier pages read the last one as a memset of the register
file and put it in the main; the clear is the M33's `regfile_clear` 0x00080C20. With flags 0 the first call already switches the
**whole region 0x20000000–0x3FFFFFFF** (DMA buffers, register file, rpmsg shared memory) to bypass, so the third changes nothing
**[inference: HAL semantics]**. The DSP's own code and data at 0x0020_0000 (region 0) keep their attribute.

### Still open

- The exact arithmetic of the `ae_*` operations is still taken from the FLIX listing; the Ghidra C shows them as named calls.
- The SDR FPGA's per-mode IF placement, the AESS speaker assignment and level, and the per-band reg 0x63 values: #193.
