/* tools/ghidra/structs_main.h -- typed state blocks of the FT-710 MAIN firmware V01-12 (T23c).
 *
 * Source of truth for the structures and typed globals that tools/ghidra/ApplyStructs.java puts into the Ghidra
 * project (category /FT710). Apply after ApplySignatures.java and ApplyEnums.java (which creates the enums of
 * enums_main.h that some fields use):
 *   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
 *     -postScript ApplyEnums.java tools/ghidra/enums_main.h tools/ghidra/enum_uses_main.tsv \
 *     -postScript ApplyStructs.java tools/ghidra/structs_main.h
 *
 * First drafted (2026-10-29) from `tools/struct_offsets.py scan decomp/main <out> --access <StructAccessDump.tsv>`
 * (every offset and access width per block), the docs in docs/code/main/, the menu descriptors
 * (tools/main_menu_table.py) and the cfg105 label table at ROM 0xFFF817C3. Since then it is edited by hand: add a
 * field when its meaning is found, and cite the evidence.
 *
 * Format (ApplyStructs.java parses this file line by line, it is not a general C parser):
 *   - `struct NAME {  / * size 0xNN: description * /` opens a structure of that size; `};` closes it.
 *   - one field per line: `TYPE name[N][M];  / * +0xOFF [tag] evidence * /`. The offset comment is required, fields are
 *     placed at that offset, and bytes no field covers stay undefined (Ghidra shows them as field_0x..).
 *   - TYPE is uint8_t int8_t char uint16_t int16_t uint32_t int32_t, `struct NAME` (declared earlier), `enum NAME`
 *     (from enums_main.h; ApplyStructs looks it up under /FT710, so ApplyEnums.java must have run, and the field takes
 *     the enum's @size, not C's int) or a pointer (`TYPE *`). The target is little-endian; the radio's records keep
 *     big-endian values, so those are byte arrays named *_be.
 *   - a bitfield: `TYPE name : N;  / * +0xOFF.B [tag] evidence * /` puts N bits at bit B (0 = LSB) of the TYPE-sized
 *     unit at +0xOFF; the other bits of that unit stay undefined.
 *   - a top-level `TYPE name[N];  / * @0xADDRESS ... * /` places a typed global (struct instance, array, scalar or
 *     pointer) at that address, clearing the undefined data it covers, and labels it `name`. A name that starts with
 *     PTR_ or DAT_ keeps the default label (a retyped pointer then reads PTR_<target>_<address>, e.g. PTR_g_ui_00025d54).
 *   - `TYPE *function(...);  / * @0xADDRESS return ... * /` only changes the return type of the function there.
 *   - field names: from the docs or a CAT handler; unknown fields that the code accesses are f_0xOFF_u8/u16/u32
 *     (width = the most common access width seen in the decompiler's p-code).
 * Tags as in AGENTS.md: [fact] (seen in code or data, with the address or function), [inference], [guess].
 * [fact: accessed] on a neutral field only says that code reads or writes it, with the widths and some users.
 */

#include <stdint.h>
#include "enums_main.h"

struct mode_blk {  /* size 0xA: one per-mode block of the channel record (radio-control.md "Per-mode block layout") */
    uint8_t flags;                               /* +0x000 [fact] bit 7 manual NOTCH on (BP), bit 6 CONTOUR on (CO), bit 5 APF on (CW block), bit 1 BI flag (cat_BP, cat_CO, cat_BI; radio-control.md per-mode block) */
    uint8_t flags2;                              /* +0x001 [fact] bit 7 BC (DNF), bits 4-6 AGC: bit 6 set, bits 4-5 speed 1..3 (cat_BC, cat_GT, dsp_set_agc 0xFFF9F681) */
    uint8_t contour_be[2];                       /* +0x002 [fact] CONTOUR frequency / 10 Hz, big-endian (CO P2=1, dsp_set_contour 0xFFF9E871) */
    uint8_t notch_be[2];                         /* +0x004 [fact] NOTCH frequency / 10 Hz, big-endian, 1..320 (BP P2=1, sdr_upd_r1d_notch 0xFFFA20F7) */
    uint8_t width_be[2];                         /* +0x006 [fact] WIDTH in Hz, big-endian (cat_SH 0xFFFAE2CA) */
    uint8_t shift_be[2];                         /* +0x008 [fact] s16 IF SHIFT in Hz, big-endian (cat_IS, sdr_upd_r18_rx_freq) */
};

struct vfo_rec {  /* size 0x5A: the 90-byte VFO / memory / band-stack / QMB record; multi-byte values are big-endian (radio-control.md, eeprom.md) */
    uint8_t mode;                                /* +0x000 [fact] bits 0-3 mode index (cat_mode_codes 0xFFF806D0: LSB USB CW-L CW-U AM AM-N FM FM-N DATA-L DATA-U DATA-FM DATA-FM-N RTTY-L RTTY-U PSK); bits 4-7 no reader (vfo_mode 0xFFFB3196). Kept a byte: as `enum radio_mode mode : 4` (+0x000.0) the export printed the whole-record copies as *(undefined1 *)p = *(undefined1 *)q and memch[n]._0_1_ = 9, and no compare got a MODE_ name (T23f, 2026-10-30) */
    uint8_t flags1;                              /* +0x001 [fact] bit 4 RX clarifier on, bit 3 TX clarifier on, bit 7 memory-scan SKIP (FUN_fffe5e3b); bit 2 read by AC (ATU on [inference]) */
    uint8_t flags2;                              /* +0x002 [fact] bits 2-3 repeater shift (0 minus, 1 simplex, 2 plus; cat_MW), bit 1 NB on (cat_NB, sdr_upd_r1a_nb_level) */
    uint8_t flags3;                              /* +0x003 [fact] bits 0-1 ATT (0 off, 6/12/18 dB; cat_RA, rf_bpf_update 0xFFFB56A5); bits 3-5 tone mode (cat_CT; values [inference]) */
    uint8_t nar_flags;                           /* +0x004 [fact] NARROW per mode class: bit 7 SSB, 5 CW, 3 RTTY, 2 DATA (cat_NA, key_nar_short) */
    uint8_t flags5;                              /* +0x005 [fact] bits 0-1 preamp (0 IPO, 2 AMP1, 3 AMP2; cat_PA), bit 7 memory tag shown (cat_MT) */
    uint8_t dnr;                                 /* +0x006 [fact] bits 0-3 DNR level 1..15 (cat_RL 0xFFFADA46), bit 4 DNR on (cat_NR) */
    uint8_t reserved_07[3];                      /* +0x007 [fact] no field access in V01-12 (#161); 50 MHz band-stack defaults write +0x08 = 1 */
    struct mode_blk blk[6];                      /* +0x00A [fact] per-mode blocks: [0] SSB +0x0A, [1] CW +0x14, [2] RTTY +0x1E, [3] DATA/PSK +0x28, [4] AM +0x32, [5] FM/DATA-FM +0x3C (cat_BP 0xFFFA7A71, cat_CO, cat_BI, cat_GT, cat_IS) */
    uint8_t tone_num;                            /* +0x046 [fact] CTCSS/DCS tone number 0..49 (cat_CN) */
    uint8_t reserved_47;                         /* +0x047 [fact] no field access in V01-12 */
    uint8_t clar_offset_be[2];                   /* +0x048 [fact] s16 clarifier offset in Hz, big-endian (vfo_freq_clar, cat_CF) */
    uint8_t freq_be[4];                          /* +0x04A [fact] u32 dial frequency in Hz, big-endian (vfo_freq 0xFFFB357C, cat_FA_FB) */
    char tag[12];                                /* +0x04E [fact] memory tag, ASCII padded with spaces (cat_MT, vfo_clear_tag) */
};

struct preset {  /* size 0x1F: one PRESET block (menu EX06, presets at 0x9B2E + 0x1F*n; active copy at UI state +0x48) */
    char name[12];                               /* +0x000 [fact] PRESET NAME (EX060n01) */
    uint8_t cat1_rate;                           /* +0x00C [fact] EX060n02 CAT1 RATE (menu descriptor, tools/main_menu_table.py) */
    uint8_t cat1_tot;                            /* +0x00D [fact] EX060n03 CAT1 TOT (menu descriptor, tools/main_menu_table.py) */
    uint8_t cat1_cat3_stop_bit;                  /* +0x00E [fact] EX060n04 CAT1 CAT3 STOP BIT (menu descriptor, tools/main_menu_table.py) */
    uint8_t agc_fast_delay;                      /* +0x00F [fact] EX060n05 AGC FAST DELAY (menu descriptor, tools/main_menu_table.py) */
    uint8_t agc_mid_delay;                       /* +0x010 [fact] EX060n06 AGC MID DELAY (menu descriptor, tools/main_menu_table.py) */
    uint8_t agc_slow_delay;                      /* +0x011 [fact] EX060n07 AGC SLOW DELAY (menu descriptor, tools/main_menu_table.py) */
    uint8_t lcut_freq;                           /* +0x012 [fact] EX060n08 LCUT FREQ (menu descriptor, tools/main_menu_table.py) */
    uint8_t lcut_slope;                          /* +0x013 [fact] EX060n09 LCUT SLOPE (menu descriptor, tools/main_menu_table.py) */
    uint8_t hcut_freq;                           /* +0x014 [fact] EX060n10 HCUT FREQ (menu descriptor, tools/main_menu_table.py) */
    uint8_t hcut_slope;                          /* +0x015 [fact] EX060n11 HCUT SLOPE (menu descriptor, tools/main_menu_table.py) */
    uint8_t usb_out_level;                       /* +0x016 [fact] EX060n12 USB OUT LEVEL (menu descriptor, tools/main_menu_table.py) */
    uint8_t rear_out_level;                      /* +0x017 [fact] EX060n13 REAR OUT LEVEL (menu descriptor, tools/main_menu_table.py) */
    uint8_t tx_bpf_sel;                          /* +0x018 [fact] EX060n14 TX BPF SEL (menu descriptor, tools/main_menu_table.py) */
    uint8_t mod_source;                          /* +0x019 [fact] EX060n15 MOD SOURCE (menu descriptor, tools/main_menu_table.py) */
    uint8_t usb_mod_gain;                        /* +0x01A [fact] EX060n16 USB MOD GAIN (menu descriptor, tools/main_menu_table.py) */
    uint8_t rear_mod_gain;                       /* +0x01B [fact] EX060n17 REAR MOD GAIN (menu descriptor, tools/main_menu_table.py) */
    uint8_t rptt_select;                         /* +0x01C [fact] EX060n18 RPTT SELECT (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor[2];                      /* +0x01D [fact] {top, row} menu cursor of the P2 group (eeprom.md, menu block) */
};

struct ui_state {  /* size 0x494: the UI / radio state block at 0x20B04, reached through the .data pointers 0x25D38..0x25D7C */
    uint16_t adc_mcup_rvs;                       /* +0x000 0x20B04 [fact] AN001 MCUP_RVS reflected power (adc0_store 0xFFFB27FB; peripherals.md) */
    uint16_t adc_mcup_for;                       /* +0x002 0x20B06 [fact] AN002 MCUP_FOR forward power */
    uint16_t adc_pa_vdd;                         /* +0x004 0x20B08 [fact] AN003 PA_VDD supply voltage; < 0x7DD = power fail (supply_undervolt_check 0xFFFB4B28) */
    uint16_t adc_pa_vu_th;                       /* +0x006 0x20B0A [fact] AN006 PA_VU_TH, converted but never read */
    uint16_t adc_alcm;                           /* +0x008 0x20B0C [fact] AN005 ALCM ALC voltage */
    uint16_t adc_pa_idd;                         /* +0x00A 0x20B0E [fact] AN007 PA_IDD PA current */
    uint16_t adc_rem_key;                        /* +0x00C 0x20B10 [fact] AN108 REM_KEY remote keypad ladder (adc1_store 0xFFFB2858, remote_keypad_scan 0xFFFB7A40) */
    uint16_t adc_pa_hf_th;                       /* +0x00E 0x20B12 [fact] AN109 PA_HF_TH HF PA thermistor */
    uint16_t adc_sdr_det;                        /* +0x010 0x20B14 [fact] AN115 SDR_DET SDR-module detect voltage (sdr_upd_r0f_band) */
    uint16_t adc_an117;                          /* +0x012 0x20B16 [fact] AN117, not used elsewhere */
    uint8_t trx_state;                           /* +0x014 0x20B18 [fact] TX/RX sequencer state 0..8, 8 = RX idle (trx_sequencer 0xFFFB80F9; tx-protection.md) */
    uint8_t tx_ack_sdr;                          /* +0x015 0x20B19 [fact] TX ack set by sdr_task, cleared by trx_sequencer; both acks needed to leave state 1 */
    uint8_t tx_ack_dsp;                          /* +0x016 0x20B1A [fact] TX ack set by dsp_link_poll */
    uint8_t po_meter_scale;                      /* +0x01A 0x20B1E [fact] PO-meter scale from the MTR alignment item (FUN_fffb667a, meter_po; eeprom.md) */
    uint8_t cat_ai_on[3];                        /* +0x01C 0x20B20 [fact] CAT AI flag per port 1/2/3 (cat_AI, cat_ai_poll 0xFFFDD797; cat.md) */
    uint8_t ptt_data;                            /* +0x020 0x20B24 [fact] PTT request: DATA_PTT (P20) low with PTT select DAKY (ptt_inputs_read 0xFFFB7F6F; tx-protection.md) */
    uint8_t ptt_extpa;                           /* +0x021 0x20B25 [fact] PTT request: EXTPA_TXREQ (P15) low; vfo_mode forces CW-L while set */
    uint8_t ptt_usb_rts;                         /* +0x022 0x20B26 [fact] PTT request: USB Standard port RTS (PC6) low and USB_DET, select 1 */
    uint8_t ptt_usb_dtr;                         /* +0x023 0x20B27 [fact] PTT request: USB DTR (PC5) low and USB_DET, select 2 */
    uint8_t cat_tx_req;                          /* +0x024 0x20B28 [fact] CAT TX1 (cat_TX), PTT source 5 */
    uint8_t ptt_vox;                             /* +0x025 0x20B29 [fact] PTT request: VOX (0x9C5D on, DSP status bit 0x10, holdoff timer 0x2F) */
    uint8_t ptt_keyer;                           /* +0x026 0x20B2A [fact] PTT request: CW keyer break-in (keyer_task -> FUN_fffbaa81) */
    uint8_t ptt_mic;                             /* +0x027 0x20B2B [fact] PTT request: MIC PTT, DISPLAY key 0x340 (FUN_fffc0210 sets, key_cancel_check clears) */
    uint8_t ptt_mox;                             /* +0x028 0x20B2C [fact] PTT request: MOX (key_mox_vox_long; read by cat_MX) */
    uint8_t ptt_atu_tune;                        /* +0x029 0x20B2D [fact] PTT request: ATU tune (FUN_fffec7f9, FUN_fffed48f, FUN_fffed8ab) */
    uint8_t ptt_msg_play;                        /* +0x02A 0x20B2E [fact] PTT request: voice-message playback on the air (cat_PB, FUN_fffe4211) */
    uint8_t keyer_state;                         /* +0x02B 0x20B2F [fact] keyer / message-send state; 7 = stop, 5 = queued (cat_KY, FUN_fffe53c0) */
    uint8_t power_key_req;                       /* +0x02C 0x20B30 [fact] 2 = power-off requested by the power key (io_task 0xFFFB6D56; README.md) */
    uint8_t spk_boost_level;                     /* +0x02D 0x20B31 [fact] curve 0xFFF8117D value sent to R2A20178 channel 8 (speaker_route, FUN_fffb5d68; peripherals.md) */
    uint8_t spk_route_both;                      /* +0x02E 0x20B32 [fact] 1 only in speaker route 2 (internal + external speaker, PA6 set, AESS crossover), else 0 (speaker_route 0xFFFB8A8C; peripherals.md "Speaker routing"); no reader in V01-12 */
    uint16_t dsp_route_word;                     /* +0x030 0x20B34 [fact] route word for DSP reg 8: 0x2222 in TX, 0x3233/0x3263 by output select in RX (speaker_route, dsp_route_param; dsp-link.md) */
    uint16_t boot_error;                         /* +0x032 0x20B36 [fact] 2 = DSP missing, 3 = SDR/FPGA missing (dsp_link_init, sdr_init); frame 0x60 bytes 13..14 (display-link.md) */
    uint8_t lamp_map;                            /* +0x034 0x20B38 [fact] 8-bit map sent as status byte 8; FUN_fff98727 sets/clears one bit ("lamp" is [inference]; display-link.md) */
    uint8_t power_cmd;                           /* +0x035 0x20B39 [fact] power command / off reason: 0x10 PS0, 0x11 restart, 0x90 low voltage (power_down_save, cat_PS; cat.md) */
    uint8_t radio_on;                            /* +0x036 0x20B3A [fact] 0 = power-off loop, only PS1 accepted (app_main, displink_rx_F0_hello, cat_parse) */
    uint8_t spk_off_req;                         /* +0x037 0x20B3B [inference] speakers all off while set (speaker_route; peripherals.md route table) */
    uint8_t tuner_result;                        /* +0x038 0x20B3C [inference] tuner sub-state read by cat_AC (2/3 while 0x20F0C = 2) */
    uint8_t tx_lamp;                             /* +0x039 0x20B3D [fact] TX lamp state, a CAT busy guard (cat_SV, cat_RM, cat_RI; cat-commands-primary.md) */
    uint8_t tuner_key_req;                       /* +0x03A 0x20B3E [fact] tuner request with TUNER TYPE SELECT 0x9AB8 = 3: 1 (FUN_fffc4238) / 2 (FUN_fffc43ec) while the TX lamp is on, 3 + timer 0x20 = 1 s while the tune cycle 0x20F0C = 2 (FUN_fffc42ef, FUN_fffc44a3); FUN_fffed2a9 turns 1/2/3 into tuner_result 2/3/1 and clears it [inference: the key handlers are the tuner keys] */
    uint8_t atu_state;                           /* +0x03B 0x20B3F [fact] antenna tuner state, re-armed by FUN_fffec578 (radio-control.md) */
    uint8_t tune_cycle_3c;                       /* +0x03C 0x20B40 [inference] tune cycle state; vfo_mode forces CW-L while it is 2 (cat_AC P3=3 sets 1) */
    uint8_t tune_cycle_3d;                       /* +0x03D 0x20B41 [inference] tune cycle state; vfo_mode forces CW-L while it is 2 (cat_AC P3=3 sets 1) */
    uint8_t dsp_key_state;                       /* +0x03E 0x20B42 [fact] DSP key 0x312 outside the FUNC panel: 1 short (key_dsp_short), 2 long (key_dsp_long), 0 after key_dsp_release; while non-zero FUN_fffc56cd steps both sides (FUN_fffc5e0a(0) and (1)) */
    uint8_t power_fail_latch;                    /* +0x03F 0x20B43 [fact] power fail handled once (supply_undervolt_check; eeprom.md) */
    uint8_t pb3_last;                            /* +0x040 0x20B44 [inference] last PB3 state compared by io_task with timer 0x2A (README.md) */
    uint8_t defaults_loaded;                     /* +0x041 0x20B45 [fact] settings defaults were loaded at boot (eeprom_load_all, app_main) */
    uint8_t cat_disabled;                        /* +0x042 0x20B46 [fact] CAT disabled, set by DISPLAY frame F1 0x03 (displink_rx_F1_sys) */
    uint8_t tot_tripped;                         /* +0x043 0x20B47 [fact] TX time-out tripped, TX refused until PTT release (ptt_arbiter; tx-protection.md) */
    uint8_t squelch_open;                        /* +0x044 0x20B48 [fact] BUSY = squelch open, status bit 4 (FUN_fffb8d77; af_mute_update) */
    uint8_t dsp_route_ready;                     /* +0x045 0x20B49 [fact] set when DSP reg 0x20 has been computed (dsp_route_param; dsp-link.md) */
    uint16_t rx_unmute_delay_ms;                 /* +0x046 0x20B4A [fact] TX->RX AF-unmute delay in ms from sdr_upd_r16_filter, added to timer 0x0D (sdr-link.md) */
    struct preset preset_active;                 /* +0x048 0x20B4C [fact] the selected 31-byte preset, copied from 0x9B2E + 0x1F*n by FUN_fffc4d93 (index 0x9BC9); used instead of the menu values while 0x9DC6 is set */
    uint8_t transmitting;                        /* +0x067 0x20B6B [fact] TX on: status TX bit, FA/FB report the TX frequency 0x20F50 while 1 (displink_build_status, cat_FA_FB) */
    uint8_t status_bit_68;                       /* +0x068 0x20B6C [fact] status byte bit 6; no writer in MAIN, always 0 */
    uint8_t hi_swr;                              /* +0x069 0x20B6D [inference] SWR alarm: set by swr_meter_protect, RI P1 (cat_RI) */
    uint8_t freq_settled_a;                      /* +0x06A 0x20B6E [fact] frequency settled, checked every 100 ms by FUN_fff9ccd3 (display-link.md) */
    uint8_t freq_settled_b;                      /* +0x06B 0x20B6F [fact] frequency settled, checked every 100 ms by FUN_fff9ccd3 */
    uint8_t status_bit_6c;                       /* +0x06C 0x20B70 [fact] status byte bit 4 (FUN_fff97105); no writer in MAIN, always 0 */
    uint8_t tuner_indicator;                     /* +0x06D 0x20B71 [fact] 1 = tuner on, blinking while it tunes (tuner_task, FUN_fffec62b; display-link.md) */
    uint8_t fm_tone_mode;                        /* +0x06E 0x20B72 [fact] FM tone mode in use (rec+3 bits 3-5 in FM/DATA-FM; dsp_set_ctcss_dec) */
    uint8_t status_bit_6f;                       /* +0x06F 0x20B73 [fact] status byte 16 bit 4; no writer in MAIN, always 0 */
    uint8_t func_panel_open;                     /* +0x070 0x20B74 [fact] FUNC-knob function display open, 5 s timer 0x44 (FUN_fffc89b0) */
    uint8_t func_blink_on;                       /* +0x071 0x20B75 [fact] FUNC-panel blink phase, sent as bit 6 of the FUNC status byte (FUN_fff97abc); toggled every 450 ms (timer 0x45 = 0x1C2) by FUN_fffc8ff9 while func_blink_en is set; 1 when the panel is closed */
    uint8_t func_blink_en;                       /* +0x072 0x20B76 [fact] FUNC-panel blinking on: set by the DSP-knob function handlers (FUN_fffbda47..FUN_fffbdf98, key_dsp_release) with timer 0x45, cleared when they leave edit (FUN_fff97abc, FUN_fffc3a10) */
    uint8_t dsp_knob_func;                       /* +0x073 0x20B77 [fact] DSP knob function: 0 SHIFT, 1 WIDTH, 2 NOTCH, 3 CONTOUR/APF (cat_SF P1=1) */
    uint8_t dsp_knob_edit;                       /* +0x074 0x20B78 [fact] toggled by the DSP-knob function handlers FUN_fffbda47 (SHIFT), FUN_fffbdad5 (WIDTH), FUN_fffbdb63 (NOTCH), FUN_fffbdcb0/FUN_fffbde58 (CONTOUR/APF), FUN_fffbdf98; enc3_step and displink_rx_E1_encoder test it, func_display_open clears it [inference: the function value is being edited] */
    uint8_t dsp_key_func_short;                  /* +0x075 0x20B79 [fact] DSP key short press while the FUNC panel is open (key_dsp_short); key_dsp_release acts on it and clears it */
    uint8_t dsp_key_func_long;                   /* +0x076 0x20B7A [fact] DSP key long press while the FUNC panel is open (key_dsp_long); key_dsp_release then calls FUN_fffc4dec and clears it */
    uint8_t dvs_state;                           /* +0x078 0x20B7C [fact] voice-message state: 2 = playing (cat_LM, cat_PB, E8 status) */
    uint8_t dvs_slot;                            /* +0x079 0x20B7D [fact] voice-message slot n-1 (cat_LM) */
    uint8_t func_knob_item;                      /* +0x07A 0x20B7E [fact] FUNC item code 0x1D..0x21 (cat_SF P1=1, cat_SH) */
    uint8_t numentry_bcd[5];                     /* +0x07B 0x20B7F [fact] numeric-entry BCD digits, +0x7C..+0x7F written by ui_numentry_to_bcd 0xFFF95ACE */
    uint8_t enc_blocked;                         /* +0x080 0x20B84 [fact] encoder frames ignored until E5 (displink_rx_E1_encoder; frame 0x7C) */
    uint8_t dl_req_7c;                           /* +0x081 0x20B85 [fact] request: send frame 0x7C (displink_tx_schedule) */
    uint8_t screensaver_on;                      /* +0x082 0x20B86 [fact] toggled by displink_tx_7B 0xFFF9889C, cleared on DISPLAY frame E4 */
    uint8_t screensaver_toggle_req;              /* +0x083 0x20B87 [fact] set by io_task, frame 0x7B request */
    uint8_t dl_block_7a;                         /* +0x084 0x20B88 [fact] blocks after frame 0x7A */
    uint8_t dl_req_7a;                           /* +0x085 0x20B89 [fact] request: send frame 0x7A */
    uint8_t dialog_shown;                        /* +0x086 0x20B8A [fact] message pop-up shown, frame 0x70 due (FUN_fffcfa3d); a CAT busy guard */
    uint8_t dl_req_sd;                           /* +0x087 0x20B8B [fact] request: send SD frame 0x43/0x44/0x45 (type +0x1E0, length +0x1E2) */
    uint8_t dl_req_50;                           /* +0x088 0x20B8C [fact] request: send frame 0x50 (on-screen keyboard), with +0x90 */
    uint8_t dl_req_23;                           /* +0x089 0x20B8D [fact] request: send frame 0x23 */
    uint8_t dl_req_23b;                          /* +0x08A 0x20B8E [fact] request: frame 0x23, empty fill variant */
    uint8_t dl_req_23c;                          /* +0x08B 0x20B8F [fact] request: frame 0x23, empty fill variant */
    uint8_t dl_req_popup;                        /* +0x08C 0x20B90 [fact] request: send pop-up frame 0x30/0x31 */
    uint8_t dl_req_65_clock;                     /* +0x08D 0x20B91 [fact] request: send clock frame 0x65 (set by cat_DT) */
    uint8_t popup_hold;                          /* +0x08F 0x20B93 [fact] pop-up requests +0x1C0/+0x1C1 wait while set */
    uint8_t kbd_open;                            /* +0x090 0x20B94 [fact] request: frame 0x50 (on-screen keyboard); cleared by vm_toggle */
    uint8_t dl_req_3f;                           /* +0x091 0x20B95 [fact] request: send frame 0x3F (b1 = +0x92) */
    uint8_t dvs_lm1_flag;                        /* +0x092 0x20B96 [fact] LM1n flag, sent in frame 0x3F (cat_LM) */
    uint8_t playlist_open;                       /* +0x093 0x20B97 [fact] PlayList screen open, frame 0x3A */
    uint8_t msgmem_open;                         /* +0x094 0x20B98 [fact] message-memory screen, frame 0x39 */
    uint8_t dl_req_40;                           /* +0x095 0x20B99 [fact] request: frame 0x40 (status + menu list), rate-limited by timer 0x29 */
    uint8_t dl_req_37;                           /* +0x096 0x20B9A [fact] request: frame 0x37 (FUNC panel); set when the knob is pressed in the menu */
    uint8_t memlist_open;                        /* +0x097 0x20B9B [fact] MEMORY CH LIST screen, frame 0x41 (vm_toggle) */
    uint8_t link_tx_enabled;                     /* +0x098 0x20B9C [fact] displink_tx_poll sends only while 1; set by power_on_request and the F0 hello (#57) */
    uint8_t dl_req_34;                           /* +0x099 0x20B9D [fact] request: frame 0x34 (displink_tx_34 0xFFF98F7C) */
    uint8_t dl_block_34;                         /* +0x09A 0x20B9E [fact] blocks after frame 0x34; also clears the PTT requests (tx_freq_allowed) */
    uint8_t power_on_reason;                     /* +0x09B 0x20B9F [fact] power-on reason byte from the F0 hello (README.md) */
    uint8_t key_ev_src;                          /* +0x09C 0x20BA0 [fact] key mailbox: high nibble of the DISPLAY E0 event byte (displink_rx_E0_key); 4 = touch on the scope, which key_task sends to key_touch_scope_tune; key_cancel_check ignores source 4 */
    uint8_t key_ev_type;                         /* +0x09D 0x20BA1 [fact] key mailbox: event type (displink_rx_E0_key -> key_task) */
    uint16_t key_ev_code;                        /* +0x09E 0x20BA2 [fact] key mailbox: key code */
    uint8_t key_ev_flag;                         /* +0x0A0 0x20BA4 [fact] key mailbox: new event */
    uint8_t enc_ev_id;                           /* +0x0A1 0x20BA5 [fact] encoder id from DISPLAY frame E1 byte 1 (displink_rx_E1_encoder): 1 main dial, 2/3 other knobs, 6 = FUNC knob while the panel is open (then handled as 3); enc_main_dial tests 6 */
    uint8_t enc_ev_steps;                        /* +0x0A2 0x20BA6 [fact] signed step count of the main-dial E1 frame (byte 2), passed to enc_main_dial or ui_numentry_step (displink_rx_E1_encoder) */
    uint8_t rf_gain;                             /* +0x0A3 0x20BA7 [fact] RF gain (cat_RG; 0x464D instead when 0x9AB6 != 0) */
    uint8_t af_gain;                             /* +0x0A4 0x20BA8 [fact] AF gain (cat_AG), through table 0xFFF81362 to the speaker amp */
    uint8_t sd_state_known;                      /* +0x0A5 0x20BA9 [fact] set by the first DISPLAY E2 frame (SD-card state, displink_rx_E2); FUN_fffcf45c reacts to SD changes only after it */
    uint8_t sd_present;                          /* +0x0A6 0x20BAA [fact] SD card present (displink_rx_E2 0xFFF95BF4) */
    uint8_t sd_present_prev;                     /* +0x0A7 0x20BAB [fact] previous sd_present, for change detection in FUN_fffcf45c (displink_rx_E2 sets both at the first E2) */
    uint8_t audio_ev_kind;                       /* +0x0A8 0x20BAC [fact] byte 1 of the last DISPLAY E7/E8 frame: 0 file count, 1 play status, 0xFF error (displink_rx_E7, displink_rx_E8) */
    uint8_t wav_count;                           /* +0x0AA 0x20BAE [fact] number of .wav files (E7 status 1) */
    uint8_t audio_playing;                       /* +0x0AB 0x20BAF [fact] E7/E8 playback status (0 = stopped); with 0x20F01 the TX audio is muted (dsp_set_tx_gain) */
    uint8_t audio_error;                         /* +0x0AC 0x20BB0 [fact] E7/E8 error index (status 5) */
    uint8_t rtc_yy;                              /* +0x0AD 0x20BB1 [fact] clock year, BCD (cat_DT, displink_rx_E3_clock) */
    uint8_t rtc_mm;                              /* +0x0AE 0x20BB2 [fact] clock month, BCD */
    uint8_t rtc_dd;                              /* +0x0AF 0x20BB3 [fact] clock day, BCD */
    uint8_t rtc_hh;                              /* +0x0B0 0x20BB4 [fact] clock hour, BCD */
    uint8_t rtc_min;                             /* +0x0B1 0x20BB5 [fact] clock minute, BCD */
    uint8_t rtc_set[5];                          /* +0x0B2 0x20BB6 [fact] clock to set on the DISPLAY RTC (frame 0x65; cat_DT mirrors) */
    uint8_t dl_req_64;                           /* +0x0B7 0x20BBB [fact] request: frame 0x64 */
    uint8_t dl_64_value;                         /* +0x0B8 0x20BBC [fact] frame 0x64 b1, sent when it changes (displink_tx_64 0xFFF986E0) */
    uint8_t dl_64_sent;                          /* +0x0B9 0x20BBD [fact] last value sent in frame 0x64; displink_tx_64 sends only when dl_64_value differs; 0xFF = none (qmb_boot_init, FUN_fffc82b7) */
    uint8_t zz_align_mode;                       /* +0x0BA 0x20BBE [fact] factory alignment mode (ZZPE071000, boot code 2; #76) */
    uint8_t dialog_msg;                          /* +0x0BB 0x20BBF [fact] dialog ROM text number for frame 0x70 */
    uint8_t reset_kind;                          /* +0x0BC 0x20BC0 [fact] menu reset selection passed to reset_select (menu_reset_exec) */
    uint8_t dialog_button;                       /* +0x0BD 0x20BC1 [fact] selected dialog button (frame 0x70 byte 0x9A) */
    uint8_t kbd_target;                          /* +0x0BE 0x20BC2 [fact] on-screen keyboard target (displink_build_50, cat_KM) */
    uint8_t msg_slot_idx;                        /* +0x0BF 0x20BC3 [fact] message slot n-1 (FUN_fffe538f) */
    uint8_t kbd_layout;                          /* +0x0C0 0x20BC4 [fact] on-screen keyboard layout 0/1/2 (FUN_fffe29b7: key 0x81 toggles 0/1, 0x82 sets 0, 0x83 sets 2), frame 0x50 byte 0x98 (FUN_fff9a364..FUN_fff9a6f9); 0 lower case, 1 Caps, 2 symbols is [inference] (display-link.md) */
    uint8_t kbd_cursor;                          /* +0x0C1 0x20BC5 [fact] keyboard cursor (FUN_fffe29b7) */
    uint8_t msg_text[5][50];                     /* +0x0C2 0x20BC6 [fact] 5 x 50-byte message texts edited by the keyboard and sent in frame 0x39 */
    uint8_t kbd_show_cursor_char;                /* +0x1BC 0x20CC0 [fact] the character under the cursor is sent as 0xFF unless set */
    uint16_t dl_23_value;                        /* +0x1BE 0x20CC2 [fact] frame 0x23 b1 = high byte + 1 (displink_build_23) */
    uint8_t dl_req_popup_a;                      /* +0x1C0 0x20CC4 [fact] pop-up request (frame 0x30/0x31, entry 16) */
    uint8_t dl_req_popup_b;                      /* +0x1C1 0x20CC5 [fact] pop-up request (frame 0x30/0x31, entry 16) */
    uint8_t popup_code;                          /* +0x1C2 0x20CC6 [fact] pop-up code: frame 0x30 when < 0x1E or 0xFF, 0x31 when < 0x5F (displink_tx_30_31 0xFFF98ECB) */
    uint8_t popup_sel;                           /* +0x1C3 0x20CC7 [fact] selection shown in the 0x30 pop-up (ATT, IPO/AMP, BC rows) */
    uint8_t dl37_bit7;                           /* +0x1C4 0x20CC8 [fact] frame 0x37 byte 0x98 bit 7; displink_build_37 sets it to 1 before every build */
    uint8_t func_assigned;                       /* +0x1C5 0x20CC9 [fact] frame 0x37 byte 0x98 bit 6: set by func_knob_assign and by the TXW-on branch of FUN_fffc3f9c (both with FUN_fffc8e0e(500)), cleared by func_panel_close and FUN_fffc3a10 [inference: confirmation shown after a FUNC assignment] */
    uint8_t dl37_bit5;                           /* +0x1C6 0x20CCA [fact] frame 0x37 byte 0x98 bit 5; displink_build_37 clears it before every build */
    uint8_t msgmem_type;                         /* +0x1C7 0x20CCB [fact] message-memory screen type (2 = EM text slots; frame 0x39) */
    uint8_t msg_slot;                            /* +0x1C8 0x20CCC [fact] message slot n (FUN_fffe538f) */
    uint8_t msg_rec_active;                      /* +0x1C9 0x20CCD [inference] message recording active (cat_LM busy guard, RI P2) */
    uint8_t dvs_armed;                           /* +0x1CA 0x20CCE [fact] armed DVS recording, a CAT busy guard */
    uint8_t msg_tx_wait;                         /* +0x1CB 0x20CCF [fact] set with timer 0x37 by FUN_fffe4efc (#157) */
    uint8_t ky_send_0;                           /* +0x1CC 0x20CD0 [fact] KY a=0 message send (cat_KY) */
    uint8_t ky_send_1;                           /* +0x1CD 0x20CD1 [fact] KY a=1 message send (cat_KY) */
    uint8_t msg_channel;                         /* +0x1CE 0x20CD2 [fact] active message channel, one-hot in frame 0x39 */
    uint8_t msg_playing;                         /* +0x1CF 0x20CD3 [fact] frame 0x39 state bit 2 */
    uint8_t msg_state_1d0;                       /* +0x1D0 0x20CD4 [fact] frame 0x39 state bit 3 */
    uint8_t msg_active;                          /* +0x1D1 0x20CD5 [fact] message channel valid; cleared before a split change */
    uint8_t ky_queued;                           /* +0x1D2 0x20CD6 [fact] KY send started (cat_KY) */
    uint16_t msg_timer;                          /* +0x1D6 0x20CDA [inference] time counter sent big-endian in frame 0x39 (FUN_fffba30c) */
    uint8_t memlist_sel_valid;                   /* +0x1D8 0x20CDC [fact] MEMORY CH LIST: selected channel valid (frame 0x41) */
    uint8_t memlist_flag;                        /* +0x1D9 0x20CDD [fact] MEMORY CH LIST byte 0x98 bit 6 */
    uint8_t memlist_group;                       /* +0x1DA 0x20CDE [fact] MEMORY CH LIST byte 0x99 high nibble */
    uint8_t memlist_row;                         /* +0x1DB 0x20CDF [fact] MEMORY CH LIST cursor row */
    enum band_idx popup_band;                    /* +0x1DC 0x20CE0 [fact] band shown in the BAND pop-up: FUN_fffc3006 (band_of_freq of the dial, BAND_GEN if none) in key_band_short, cursor - 0x6B in FUN_fffc151d; frame 0x30 code 0xC byte 1 (displink_build_30) */
    uint8_t align_cursor_row;                    /* +0x1DD 0x20CE1 [fact] alignment menu cursor row 0..8 (frame 0x62) */
    uint16_t align_item;                         /* +0x1DE 0x20CE2 [fact] alignment item 0..0x104 (align_store, align_load_preset 0xFFFBB567) */
    uint8_t sdreq_type;                          /* +0x1E0 0x20CE4 [fact] SD request frame type 0x43/0x44/0x45 */
    uint16_t sdreq_len;                          /* +0x1E2 0x20CE6 [fact] SD request frame length */
    uint8_t sdreq_op;                            /* +0x1E4 0x20CE8 [fact] SD request byte 1: 0x43 op (1 MEM LIST LOAD, 2 MEM LIST SAVE, 3 MENU LOAD, 4 MENU SAVE, 5 INFORMATIONS, 8 FORMAT; sd_*_start) or the transfer id 0x41..0x44 (sd_save_xfer_id, FUN_fffd0566); displink_build_req sends it after the type (display-link.md "SD CARD transfers") */
    uint8_t sdreq_arg1;                          /* +0x1E5 0x20CE9 [fact] SD request byte 2: 0x43 sub-command (1 list page, 0x10 open file, 4 save value), 0x44/0x45 offset high byte (FUN_fffd0980, FUN_fffd0fde from 0x1FF02) */
    uint8_t sdreq_arg2;                          /* +0x1E6 0x20CEA [fact] SD request byte 3: 0x43 page 0x15DE7 (+ row 0x15DE8 for sub 0x10), 0x44/0x45 offset low byte */
    uint8_t sdreq_arg3;                          /* +0x1E7 0x20CEB [fact] SD request byte 4: 0x43 row 0x15DE8 or 0x50, 0x44/0x45 length high byte (0x1FF04) */
    uint8_t sdreq_arg4;                          /* +0x1E8 0x20CEC [fact] SD request byte 5: 0x44/0x45 length low byte, 0 in the 0x43 frames */
    uint8_t sdreq_data[256];                     /* +0x1E9 0x20CED [fact] SD request data: 0x100 bytes of the image block in frame 0x45 (FUN_fffd1078 copies 0x1FF04 bytes), or 15 bytes from 0x15DEA plus a 0 at +0x1F8 in the 0x43 sub 0x10 frame (FUN_fffd1252); display-link.md "SD CARD transfers" */
    uint8_t sd_answer[265];                      /* +0x2ED 0x20DF1 [fact] answer of DISPLAY frames C3/C4/C5 (displink_rx_C3, displink_rx_C4_C5) */
    uint8_t sd_answer_ready;                     /* +0x3F6 0x20EFA [fact] set when an answer arrived */
    uint8_t sd_step;                             /* +0x3F7 0x20EFB [fact] step of the SD-menu operation run by sd_menu_task: 1 at sd_*_start, then 2..11, 99 (FUN_fffcfe2d); sd_step_reset clears it (docs/code/main/README.md task 13) */
    uint8_t playlist_req;                        /* +0x3F8 0x20EFC [fact] request: send frame 0x3A once */
    uint8_t playlist_substate;                   /* +0x3F9 0x20EFD [fact] PlayList sub-state (3 = delete) */
    uint16_t playlist_first;                     /* +0x3FA 0x20EFE [fact] first file shown (sent big-endian) */
    uint8_t playlist_row;                        /* +0x3FC 0x20F00 [fact] cursor row 0..4 */
    uint8_t playlist_cmd;                        /* +0x3FD 0x20F01 [fact] pending command */
    uint8_t playlist_playing;                    /* +0x3FE 0x20F02 [fact] playing */
    uint8_t menu_state;                          /* +0x3FF 0x20F03 [fact] menu state, 3 = editing a value (frame 0x40) */
    uint8_t dl_req_24;                           /* +0x400 0x20F04 [fact] request: frame 0x24 display settings (cat_DA) */
    uint8_t dl_req_24_later;                     /* +0x401 0x20F05 [fact] frame 0x24 again after timer 0x2B */
    uint8_t txw_swap;                            /* +0x405 0x20F09 [fact] TS swap flag: A/B records swapped (cat_TS) */
    uint8_t sd_busy;                             /* +0x406 0x20F0A [fact] set with sd_step 5 (FUN_fffd0194), 8 (FUN_fffd04a6) and 3 (FUN_fffd16f7), cleared by sd_step_reset, FUN_fffd077e, FUN_fffd12fd and sd_format_step; no reader in V01-12 [inference: a transfer is in progress] */
    uint8_t cw_spot_on;                          /* +0x407 0x20F0B [fact] CS flag (cat_CS, beep_request(4)) */
    uint8_t tune_cycle;                          /* +0x408 0x20F0C [fact] tune / EXT-PA cycle: 1 requested, 2 running (cat_AC, vfo_mode) */
    uint8_t key_consumed;                        /* +0x409 0x20F0D [fact] set by the press handlers; key_task skips key_call_short/key_call_long while it is set (FUN_fffc0b2f, key_task 0xFFFBBD58) */
    uint8_t rtc_edit_apply;                      /* +0x40A 0x20F0E [fact] set by datetime_edit_load in menu state 3; FUN_fffcdbb8 then copies rtc_set[] into rtc_yy..rtc_min and clears it */
    uint8_t vfo_refresh_req;                     /* +0x40B 0x20F0F [inference] refresh request read by freq_cache_update; set after an EX menu apply and by the TS swap (T10f) */
    uint8_t freq_refresh_req;                    /* +0x40C 0x20F10 [fact] frequency-cache refresh request for freq_cache_update (set by ~90 functions; T10g) */
    uint8_t keypad_open;                         /* +0x40D 0x20F11 [fact] direct-frequency keypad (pop-up 8) open: set by FUN_fffbc782 and FUN_fffe1e85, cleared by popup8_close; a CAT busy guard (cat_FA_FB, cat_MD, cat_BS, ... reply ?; while 1) and key_event_filter blocks keys */
    enum vfo_side status_side;                   /* +0x40E 0x20F12 [fact] side of the record in the last status frame: displink_build_status alternates VFO-A (0) and VFO-B (1); FUN_fff97e1d / FUN_fff98303 compare their side argument with it */
    uint8_t keypad_bcd[5];                       /* +0x40F 0x20F13 [fact] keypad digits, packed BCD, 0xF = empty: freq_keypad_key writes nibble (count >> 1) and converts bytes +1..+4 with bcd_to_bin (x1000000, x10000, x100, x1) into the frequency; FUN_fffe1e85 / FUN_fffe1f60 fill them with 0xFF */
    uint8_t keypad_set_fix;                      /* +0x414 0x20F18 [fact] set by FUN_fffbc782 when it opens the keypad, cleared by popup8_close; while 1 the entered frequency is also stored as the FIX-mode scope start (freq_keypad_key -> FUN_fffe1d96 = bandmem_set(2)) */
    uint8_t digit_step_on;                       /* +0x415 0x20F19 [fact] big-step tuning: toggled by FUN_fffbcbea / FUN_fffbcc6f, cleared after 6 blink periods of timer 0x3D (FUN_fffc8e26) and by ui_clear_415_423; FUN_fffc616e then steps 1 MHz or 1 kHz (digit_step_khz); freq_fix_below/above */
    uint8_t digit_step_khz;                      /* +0x416 0x20F1A [fact] step of digit_step_on: 0 = 1 MHz (FUN_fffbcbea), 1 = 1 kHz (FUN_fffbcc6f) (FUN_fffc616e); FUN_fff98363 blanks a digit by it */
    uint8_t dvs_busy;                            /* +0x417 0x20F1B [inference] voice-message play/record busy: set with playback start by cat_LM / cat_PB, a CAT busy guard (blocks FT/MD) */
    uint8_t scan_running;                        /* +0x418 0x20F1C [fact] scan running (cat_SC, scan_task) */
    uint8_t scan_hold;                           /* +0x419 0x20F1D [inference] scan stopped on a signal (scan_task; RI P6 = 2) */
    uint8_t scope_skip;                          /* +0x41A 0x20F1E [fact] scope fields not sent while set (FUN_fff97ba6) */
    uint8_t ss08_value;                          /* +0x41B 0x20F1F [fact] SS P2=8 value 0/1 (cat_SS) */
    uint8_t f_0x41c_u8;                          /* +0x41C 0x20F20 [fact: accessed] func_knob_turn sends the turn to FUN_fffc6f11 while it is 1; FUN_fffc6f11 and popup_close clear it; no code sets it to 1 in V01-12 */
    uint8_t popup7_open;                         /* +0x41D 0x20F21 [fact] pop-up 7 open: FUN_fffe1f60 opens it with split_on = 1, empty keypad digits and timer 0x46 = 10 s; FUN_fffe1f3d closes it; a busy guard next to keypad_open (FUN_fffe60a6) */
    uint8_t band_popup_pick;                     /* +0x41E 0x20F22 [fact] a band was picked in the BAND pop-up (code 0xC): set by FUN_fffc151d and FUN_fffc1605, cleared by key_band_short; FUN_fffc15d4 then selects popup_cursor */
    uint8_t menu_p1;                             /* +0x41F 0x20F23 [fact] current menu P1 (menu.md) */
    uint8_t menu_p2;                             /* +0x420 0x20F24 [fact] current menu local P2 */
    uint8_t menu_step_dir;                       /* +0x421 0x20F25 [fact] on_step direction, 0 = up */
    uint8_t digit_step_blinks;                   /* +0x422 0x20F26 [fact] blink counter of digit_step_on: FUN_fffc8e26 counts the timer 0x3D periods and clears digit_step_on after 6; FUN_fffc8ebc restarts it */
    uint8_t digit_step_blink_on;                 /* +0x423 0x20F27 [fact] blink phase of the selected digit (FUN_fffc8e26), returned by FUN_fff9847e for the status frame (FUN_fff98363) */
    uint8_t popup_cursor;                        /* +0x424 0x20F28 [fact] cursor item of the open pop-up, frame 0x30 byte 3 (displink_build_30): the mode 0..15 for code 5 (key_mode_short, mode_popup_select, FUN_fffc6cd7 steps it 0..15), the SS03 value for code 0xB (FUN_fffc3cd9), the band 0..11 for code 0xC (key_band_short, band_select clamps it to 11); FUN_fffc396d acts on it. So not a band_idx */
    uint8_t clar_flags_a;                        /* +0x425 0x20F29 [fact] clarifier VFO-A: bit 0 RX, bit 1 TX (cat_CF, vfo_freq_clar) */
    uint8_t clar_flags_b;                        /* +0x426 0x20F2A [fact] clarifier VFO-B: bit 0 RX, bit 1 TX */
    char popup_text[9];                          /* +0x427 0x20F2B [inference] free-text pop-up, 9 characters (FUN_fff9a044) */
    uint8_t numentry_mode;                       /* +0x437 0x20F3B [fact] numeric-entry / adjust mode (F0 boot code 4; #72) */
    uint8_t lamp_restore_req;                    /* +0x438 0x20F3C [fact] FUN_fffc9046 restores the lamps (ui_lamp_set(0x12233, 0x12234)) when timer 0x41 expires while it is set, and clears it; no writer of 1 in V01-12 */
    uint8_t memlist_first;                       /* +0x439 0x20F3D [fact] first channel row of the MEMORY CH LIST (frame 0x41) */
    uint8_t memlist_ch;                          /* +0x43A 0x20F3E [fact] channel index (into memch[]) under the MEMORY CH LIST cursor (memlist_cursor_channel); the list handlers read, tag and store that channel (memch_valid, eeprom_save_memch, memch_current_set) */
    uint8_t memlist_popup55;                     /* +0x43B 0x20F3F [fact] pop-up 0x55 opened from the MEMORY CH LIST for a valid channel (FUN_fffc21e8, FUN_fffc224e, FUN_fffc2296); memlist_key / FUN_fffc38fa / popup_close clear it [inference: a confirmation] */
    uint8_t memlist_edit_on;                     /* +0x43C 0x20F40 [fact] set by memlist_key for keys 5..7 (group 1..3); FUN_fffc6800 then sends dial turns to the group editor (FUN_fffc6ac4 / FUN_fffc6b34 / FUN_fffc6b86) instead of moving the cursor */
    uint8_t force_bandstack_a;                   /* +0x43D 0x20F41 [fact] VFO-A: while 1, vfo_store_back / FUN_fffc17df / vfo_reload use the band stack whatever the state; cleared by vfo_enter_mem_state; no writer of 1 in V01-12 */
    uint8_t force_bandstack_b;                   /* +0x43E 0x20F42 [fact] VFO-B: as force_bandstack_a (vfo_store_back, FUN_fffc184f, vfo_reload) */
    uint8_t memtune_valid_a;                     /* +0x43F 0x20F43 [fact] VFO-A memory-tune copy made: set by FUN_fffc18c3 (with memtune_backup_a), FUN_fffc1a0d, FUN_fffc1a35; FUN_fffc1d95 reloads the memory channel instead while 0; memtune_flags_clear */
    uint8_t memtune_valid_b;                     /* +0x440 0x20F44 [fact] VFO-B: as memtune_valid_a (FUN_fffc18e1, FUN_fffc1dca, memtune_flags_clear) */
    uint8_t memtune_backup_a;                    /* +0x441 0x20F45 [fact] VFO-A memtune_backup_a done (FUN_fffc18c3); FUN_fffc1d95 restores the backup while 1, else memch_load_to_vfo */
    uint8_t memtune_backup_b;                    /* +0x442 0x20F46 [fact] VFO-B: as memtune_backup_a (FUN_fffc18e1, FUN_fffc1dca) */
    uint8_t edited_a;                            /* +0x443 0x20F47 [fact] VFO-A record edited: set by vfo_mark_edited(0), vfo_mark_edited_if_vfo, vfo_ab_toggle, FUN_fffc2426, FUN_fffc4a8e; vfo_store_back(0) stores the record back only while it is set and clears it */
    uint8_t tuned_a;                             /* +0x444 0x20F48 [fact] VFO-A tuned: set by vfo_mark_tuned(0) and FUN_fffc568a, cleared by FUN_fffc17df and qmb_recall; FUN_fffc30af tests it with edited_a */
    uint8_t edited_b;                            /* +0x445 0x20F49 [fact] VFO-B: as edited_a (vfo_mark_edited(1), vfo_store_back(1)) */
    uint8_t tuned_b;                             /* +0x446 0x20F4A [fact] VFO-B: as tuned_a (vfo_mark_tuned(1), FUN_fffc184f) */
    uint8_t restart_req;                         /* +0x447 0x20F4B [fact] power-down / restart request, frame 0x7F (cat_PS, cat_ext_ZZ; #76) */
    uint8_t dialog_has_choice;                   /* +0x448 0x20F4C [fact] 1 for dialog messages 1, 7 and 9 (FUN_fffcf4b8, FUN_fffcf549, FUN_fffcf5a0), 0 for the others; enc2_step moves dialog_button only while 1 [inference: a two-button dialog] */
    uint32_t freq_tx;                            /* +0x44C 0x20F50 [fact] frequency cache: TX frequency (freq_cache_update 0xFFF9CEE1) */
    uint32_t freq_a;                             /* +0x450 0x20F54 [fact] frequency cache: VFO-A (FA) */
    uint32_t freq_b;                             /* +0x454 0x20F58 [fact] frequency cache: VFO-B (FB) */
    uint32_t freq_dial;                          /* +0x458 0x20F5C [fact] frequency cache: dial frequency (FD n=0) */
    uint32_t scope_cursor_start;                 /* +0x45C 0x20F60 [fact] scope start in CURSOR mode (FD n=1), mirrored at 0x9E82 */
    uint8_t pms_inhibit;                         /* +0x460 0x20F64 [fact] PMS path of freq_clamp rejects while 1 (FUN_fffe1dd7) */
    uint32_t freq_clamp_result;                  /* +0x464 0x20F68 [fact] result of freq_clamp (cat_FA_FB) */
    uint8_t keypad_pos;                          /* +0x468 0x20F6C [fact] keypad digit position 2..9 (nibble index into keypad_bcd): freq_keypad_key advances it per digit and steps back on delete; 0 after FUN_fffe1e85 / FUN_fffe1f60 */
    uint8_t freq_rejected;                       /* +0x469 0x20F6D [fact] set when freq_clamp rejects (freq_clamp_pms) */
    uint8_t step_fast_req;                       /* +0x46A 0x20F6E [fact] set by FUN_fffe5302 around one FUN_fffc5c8f step: FUN_fffc616e then steps 1 MHz, or 100 kHz with step_fast_100k; freq_fix_below/above, FUN_fffc5ec4, FUN_fffc6073 */
    uint8_t ch_step_mode;                        /* +0x46B 0x20F6F [fact] set by FUN_fffe60a6 / FUN_fffe6138, cleared by cat_UP / cat_DN, FUN_fffc0210, FUN_fffe2ee4 and others; in memory state the UP/DOWN steps move the channel while 1 (vfo_step_up/down -> memch_step_up), and dsp_set_agc / FUN_fffc616e treat it like scan_running; with mic_key_hold the up/down keys start a scan (FUN_fffc42ef, FUN_fffc44a3) */
    uint8_t mic_key_hold;                        /* +0x46C 0x20F70 [inference] timed flag of the MIC/remote-keypad handlers, a CAT busy guard (#69) */
    uint8_t step_dial_req;                       /* +0x46D 0x20F71 [fact] set by FUN_fffc5e0a while it steps a record: FUN_fffc616e then uses the dial step FUN_fffc62ae */
    uint32_t pms_lo;                             /* +0x470 0x20F74 [fact] PMS lower limit (pms_load_limits) */
    uint32_t pms_hi;                             /* +0x474 0x20F78 [fact] PMS upper limit */
    uint8_t step_ch_req;                         /* +0x478 0x20F7C [fact] set by FUN_fffc7fcc around FUN_fffc807e: FUN_fffc616e then uses the channel step FUN_fffc63e6 (AM/FM CH STEP menus) */
    uint8_t step_fast_100k;                      /* +0x479 0x20F7D [fact] with step_fast_req: 100 kHz instead of 1 MHz (FUN_fffe5302, FUN_fffc616e) */
    uint8_t dsp_knob_apf;                        /* +0x47A 0x20F7E [fact] DSP-knob function 3 shows APF (FUNC item 0x21) instead of CONTOUR (0x20): set by FUN_fffbdcb0 in the CW block, cleared by FUN_fffbde58 and freq_cache_update; sent as bit 2 of the FUNC status byte (FUN_fff97abc) */
    uint8_t dl_40_force;                         /* +0x47B 0x20F7F [fact] set by FUN_fffcfaff on dialog answer 0x166: displink_tx_40 then sends frame 0x40 once even when unchanged, and clears it */
    uint8_t ch_knob_mode;                        /* +0x47C 0x20F80 [fact] CH set value 0/1 (cat_CH; #157) */
    uint8_t qmb_pending_slot;                    /* +0x47F 0x20F83 [fact] QMB slot to save (FUN_fff9513c, qmb_store) */
    uint8_t svc_brightness;                      /* +0x480 0x20F84 [fact] service-mode brightness/dimmer index (frame 0x24) */
    uint8_t svc_contrast;                        /* +0x481 0x20F85 [fact] service-mode contrast (frame 0x24) */
    uint8_t split_long_on;                       /* +0x482 0x20F86 [fact] toggled by key_split_long (SPLIT long press, FUN_fff9cdb0 copies the other VFO frequency); split_toggle, FUN_fff97ebf, FUN_fff9ccd3, FUN_fffc56cd, FUN_fffc7fcc test it together with split_on */
    uint8_t txw_on;                              /* +0x483 0x20F87 [fact] TXW flag, not cleared by split (cat_TS) */
    enum vfo_state split_saved_state_a;          /* +0x484 0x20F88 [fact] VFO-A state saved by split_toggle 0xFFFBECA5 */
    enum vfo_state split_saved_state_b;          /* +0x485 0x20F89 [fact] VFO-B state saved by split_toggle */
    uint32_t e7_status;                          /* +0x488 0x20F8C [fact] command word from DISPLAY frame E7 (displink_rx_E7, dispreq_e7_task) */
    uint32_t e8_status;                          /* +0x48C 0x20F90 [fact] command word from DISPLAY frame E8 (displink_rx_E8, dispreq_e8_task) */
    uint8_t func_cursor_locked;                  /* +0x490 0x20F94 [fact] FUNC-knob cursor locked (FUN_fffc3c23, FUN_fffc7c55) */
};

struct cfg105 {  /* size 0x105: factory alignment table at 0x4659 (EEPROM 0x000A), one byte per alignment item (eeprom.md "cfg105") */
    uint8_t a001_gn_vdd_mtr;                     /* +0x000 0x04659 [fact] alignment item "001 [GN] VDD MTR" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a002_gn_fan;                         /* +0x001 0x0465A [fact] alignment item "002 [GN] FAN" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a003_gn_ref_freq;                    /* +0x002 0x0465B [fact] alignment item "003 [GN] REF FREQ" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a004_gn_tx_inh;                      /* +0x003 0x0465C [fact] alignment item "004 [GN] TX INH" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a005_gn_reserved;                    /* +0x004 0x0465D [fact] alignment item "005 [GN] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a006_gn_reserved;                    /* +0x005 0x0465E [fact] alignment item "006 [GN] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a007_gn_reserved;                    /* +0x006 0x0465F [fact] alignment item "007 [GN] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a008_gn_dbg_mode_enable;             /* +0x007 0x04660 [fact] alignment item "008 [GN] DBG MODE ENABLE" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a009_mt_po_mtr_100w_pos;             /* +0x008 0x04661 [fact] alignment item "009 [MT] PO MTR 100W POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a010_mt_po_mtr_50w_pos;              /* +0x009 0x04662 [fact] alignment item "010 [MT] PO MTR  50W POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a011_mt_po_mtr_20w_pos;              /* +0x00A 0x04663 [fact] alignment item "011 [MT] PO MTR  20W POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a012_mt_po_mtr_10w_pos;              /* +0x00B 0x04664 [fact] alignment item "012 [MT] PO MTR  10W POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a013_mt_po_mtr_5w_pos;               /* +0x00C 0x04665 [fact] alignment item "013 [MT] PO MTR   5W POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a014_mt_alc_mtr_pos;                 /* +0x00D 0x04666 [fact] alignment item "014 [MT] ALC MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a015_mt_vdd_mtr_pos;                 /* +0x00E 0x04667 [fact] alignment item "015 [MT] VDD MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a016_mt_idd_mtr_pos;                 /* +0x00F 0x04668 [fact] alignment item "016 [MT] IDD MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a017_mt_swr_1_5_mtr_pos;             /* +0x010 0x04669 [fact] alignment item "017 [MT] SWR 1.5 MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a018_mt_swr_2_0_mtr_pos;             /* +0x011 0x0466A [fact] alignment item "018 [MT] SWR 2.0 MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a019_mt_swr_3_0_mtr_pos;             /* +0x012 0x0466B [fact] alignment item "019 [MT] SWR 3.0 MTR POS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a020_mt_reserved;                    /* +0x013 0x0466C [fact] alignment item "020 [MT] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a021_mt_reserved;                    /* +0x014 0x0466D [fact] alignment item "021 [MT] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a022_mt_reserved;                    /* +0x015 0x0466E [fact] alignment item "022 [MT] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a023_rx_rf_agc_7;                    /* +0x016 0x0466F [fact] alignment item "023 [RX] RF-AGC  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a024_rx_rf_agc_14;                   /* +0x017 0x04670 [fact] alignment item "024 [RX] RF-AGC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a025_rx_rf_agc_21;                   /* +0x018 0x04671 [fact] alignment item "025 [RX] RF-AGC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a026_rx_rf_agc_28;                   /* +0x019 0x04672 [fact] alignment item "026 [RX] RF-AGC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a027_rx_rf_agc_50;                   /* +0x01A 0x04673 [fact] alignment item "027 [RX] RF-AGC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a028_rx_if_agc_7;                    /* +0x01B 0x04674 [fact] alignment item "028 [RX] IF-AGC  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a029_rx_if_agc_14;                   /* +0x01C 0x04675 [fact] alignment item "029 [RX] IF-AGC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a030_rx_if_agc_21;                   /* +0x01D 0x04676 [fact] alignment item "030 [RX] IF-AGC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a031_rx_if_agc_28;                   /* +0x01E 0x04677 [fact] alignment item "031 [RX] IF-AGC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a032_rx_if_agc_50;                   /* +0x01F 0x04678 [fact] alignment item "032 [RX] IF-AGC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a033_rx_s_mtr_0;                     /* +0x020 0x04679 [fact] alignment item "033 [RX] S-MTR 0" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a034_rx_s_mtr_2;                     /* +0x021 0x0467A [fact] alignment item "034 [RX] S-MTR 2" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a035_rx_s_mtr_5;                     /* +0x022 0x0467B [fact] alignment item "035 [RX] S-MTR 5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a036_rx_s_mtr_7;                     /* +0x023 0x0467C [fact] alignment item "036 [RX] S-MTR 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a037_rx_s_mtr_9;                     /* +0x024 0x0467D [fact] alignment item "037 [RX] S-MTR 9" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a038_rx_s_mtr_10;                    /* +0x025 0x0467E [fact] alignment item "038 [RX] S-MTR +10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a039_rx_s_mtr_20;                    /* +0x026 0x0467F [fact] alignment item "039 [RX] S-MTR +20" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a040_rx_s_mtr_30;                    /* +0x027 0x04680 [fact] alignment item "040 [RX] S-MTR +30" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a041_rx_s_mtr_40;                    /* +0x028 0x04681 [fact] alignment item "041 [RX] S-MTR +40" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a042_rx_s_mtr_50;                    /* +0x029 0x04682 [fact] alignment item "042 [RX] S-MTR +50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a043_rx_s_mtr_60;                    /* +0x02A 0x04683 [fact] alignment item "043 [RX] S-MTR +60" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a044_rx_reserved;                    /* +0x02B 0x04684 [fact] alignment item "044 [RX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a045_rx_reserved;                    /* +0x02C 0x04685 [fact] alignment item "045 [RX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a046_rx_fm_sql_thw;                  /* +0x02D 0x04686 [fact] alignment item "046 [RX] FM SQL THW" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a047_rx_fm_sql_thn;                  /* +0x02E 0x04687 [fact] alignment item "047 [RX] FM SQL THN" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a048_rx_fm_sql_ti;                   /* +0x02F 0x04688 [fact] alignment item "048 [RX] FM SQL TI" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a049_rx_scope_sdr_ref;               /* +0x030 0x04689 [fact] alignment item "049 [RX] SCOPE SDR REF" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a050_tx_mf_predr_bias;               /* +0x031 0x0468A [fact] alignment item "050 [TX] MF PREDR BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a051_tx_mf_drive_bias;               /* +0x032 0x0468B [fact] alignment item "051 [TX] MF DRIVE BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a052_tx_mf_final_bias;               /* +0x033 0x0468C [fact] alignment item "052 [TX] MF FINAL BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a053_tx_hf_predr_bias;               /* +0x034 0x0468D [fact] alignment item "053 [TX] HF PREDR BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a054_tx_hf_drive_bias;               /* +0x035 0x0468E [fact] alignment item "054 [TX] HF DRIVE BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a055_tx_hf_final_bias;               /* +0x036 0x0468F [fact] alignment item "055 [TX] HF FINAL BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a056_tx_vhf_predr_bias;              /* +0x037 0x04690 [fact] alignment item "056 [TX] VHF PREDR BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a057_tx_vhf_drive_bias;              /* +0x038 0x04691 [fact] alignment item "057 [TX] VHF DRIVE BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a058_tx_vhf_final_bias;              /* +0x039 0x04692 [fact] alignment item "058 [TX] VHF FINAL BIAS" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a059_tx_i_alc_1_8;                   /* +0x03A 0x04693 [fact] alignment item "059 [TX] I-ALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a060_tx_i_alc_3_5;                   /* +0x03B 0x04694 [fact] alignment item "060 [TX] I-ALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a061_tx_i_alc_7;                     /* +0x03C 0x04695 [fact] alignment item "061 [TX] I-ALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a062_tx_i_alc_10;                    /* +0x03D 0x04696 [fact] alignment item "062 [TX] I-ALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a063_tx_i_alc_14;                    /* +0x03E 0x04697 [fact] alignment item "063 [TX] I-ALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a064_tx_i_alc_18;                    /* +0x03F 0x04698 [fact] alignment item "064 [TX] I-ALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a065_tx_i_alc_21;                    /* +0x040 0x04699 [fact] alignment item "065 [TX] I-ALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a066_tx_i_alc_24;                    /* +0x041 0x0469A [fact] alignment item "066 [TX] I-ALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a067_tx_i_alc_28;                    /* +0x042 0x0469B [fact] alignment item "067 [TX] I-ALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a068_tx_i_alc_50;                    /* +0x043 0x0469C [fact] alignment item "068 [TX] I-ALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a069_tx_i_alc_70;                    /* +0x044 0x0469D [fact] alignment item "069 [TX] I-ALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a070_tx_100w_falc_1_8;               /* +0x045 0x0469E [fact] alignment item "070 [TX] 100W FALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a071_tx_100w_mtr_1_8;                /* +0x046 0x0469F [fact] alignment item "071 [TX] 100W MTR  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a072_tx_100w_txg_1_8;                /* +0x047 0x046A0 [fact] alignment item "072 [TX] 100W TXG  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a073_tx_50w_falc_1_8;                /* +0x048 0x046A1 [fact] alignment item "073 [TX]  50W FALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a074_tx_50w_mtr_1_8;                 /* +0x049 0x046A2 [fact] alignment item "074 [TX]  50W MTR  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a075_tx_50w_txg_1_8;                 /* +0x04A 0x046A3 [fact] alignment item "075 [TX]  50W TXG  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a076_tx_20w_falc_1_8;                /* +0x04B 0x046A4 [fact] alignment item "076 [TX]  20W FALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a077_tx_20w_mtr_1_8;                 /* +0x04C 0x046A5 [fact] alignment item "077 [TX]  20W MTR  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a078_tx_20w_txg_1_8;                 /* +0x04D 0x046A6 [fact] alignment item "078 [TX]  20W TXG  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a079_tx_10w_falc_1_8;                /* +0x04E 0x046A7 [fact] alignment item "079 [TX]  10W FALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a080_tx_10w_mtr_1_8;                 /* +0x04F 0x046A8 [fact] alignment item "080 [TX]  10W MTR  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a081_tx_10w_txg_1_8;                 /* +0x050 0x046A9 [fact] alignment item "081 [TX]  10W TXG  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a082_tx_5w_falc_1_8;                 /* +0x051 0x046AA [fact] alignment item "082 [TX]   5W FALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a083_tx_5w_mtr_1_8;                  /* +0x052 0x046AB [fact] alignment item "083 [TX]   5W MTR  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a084_tx_5w_txg_1_8;                  /* +0x053 0x046AC [fact] alignment item "084 [TX]   5W TXG  1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a085_tx_100w_falc_3_5;               /* +0x054 0x046AD [fact] alignment item "085 [TX] 100W FALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a086_tx_100w_mtr_3_5;                /* +0x055 0x046AE [fact] alignment item "086 [TX] 100W MTR  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a087_tx_100w_txg_3_5;                /* +0x056 0x046AF [fact] alignment item "087 [TX] 100W TXG  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a088_tx_50w_falc_3_5;                /* +0x057 0x046B0 [fact] alignment item "088 [TX]  50W FALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a089_tx_50w_mtr_3_5;                 /* +0x058 0x046B1 [fact] alignment item "089 [TX]  50W MTR  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a090_tx_50w_txg_3_5;                 /* +0x059 0x046B2 [fact] alignment item "090 [TX]  50W TXG  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a091_tx_20w_falc_3_5;                /* +0x05A 0x046B3 [fact] alignment item "091 [TX]  20W FALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a092_tx_20w_mtr_3_5;                 /* +0x05B 0x046B4 [fact] alignment item "092 [TX]  20W MTR  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a093_tx_20w_txg_3_5;                 /* +0x05C 0x046B5 [fact] alignment item "093 [TX]  20W TXG  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a094_tx_10w_falc_3_5;                /* +0x05D 0x046B6 [fact] alignment item "094 [TX]  10W FALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a095_tx_10w_mtr_3_5;                 /* +0x05E 0x046B7 [fact] alignment item "095 [TX]  10W MTR  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a096_tx_10w_txg_3_5;                 /* +0x05F 0x046B8 [fact] alignment item "096 [TX]  10W TXG  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a097_tx_5w_falc_3_5;                 /* +0x060 0x046B9 [fact] alignment item "097 [TX]   5W FALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a098_tx_5w_mtr_3_5;                  /* +0x061 0x046BA [fact] alignment item "098 [TX]   5W MTR  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a099_tx_5w_txg_3_5;                  /* +0x062 0x046BB [fact] alignment item "099 [TX]   5W TXG  3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a100_tx_100w_falc_7;                 /* +0x063 0x046BC [fact] alignment item "100 [TX] 100W FALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a101_tx_100w_mtr_7;                  /* +0x064 0x046BD [fact] alignment item "101 [TX] 100W MTR  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a102_tx_100w_txg_7;                  /* +0x065 0x046BE [fact] alignment item "102 [TX] 100W TXG  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a103_tx_50w_falc_7;                  /* +0x066 0x046BF [fact] alignment item "103 [TX]  50W FALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a104_tx_50w_mtr_7;                   /* +0x067 0x046C0 [fact] alignment item "104 [TX]  50W MTR  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a105_tx_50w_txg_7;                   /* +0x068 0x046C1 [fact] alignment item "105 [TX]  50W TXG  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a106_tx_20w_falc_7;                  /* +0x069 0x046C2 [fact] alignment item "106 [TX]  20W FALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a107_tx_20w_mtr_7;                   /* +0x06A 0x046C3 [fact] alignment item "107 [TX]  20W MTR  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a108_tx_20w_txg_7;                   /* +0x06B 0x046C4 [fact] alignment item "108 [TX]  20W TXG  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a109_tx_10w_falc_7;                  /* +0x06C 0x046C5 [fact] alignment item "109 [TX]  10W FALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a110_tx_10w_mtr_7;                   /* +0x06D 0x046C6 [fact] alignment item "110 [TX]  10W MTR  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a111_tx_10w_txg_7;                   /* +0x06E 0x046C7 [fact] alignment item "111 [TX]  10W TXG  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a112_tx_5w_falc_7;                   /* +0x06F 0x046C8 [fact] alignment item "112 [TX]   5W FALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a113_tx_5w_mtr_7;                    /* +0x070 0x046C9 [fact] alignment item "113 [TX]   5W MTR  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a114_tx_5w_txg_7;                    /* +0x071 0x046CA [fact] alignment item "114 [TX]   5W TXG  7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a115_tx_100w_falc_10;                /* +0x072 0x046CB [fact] alignment item "115 [TX] 100W FALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a116_tx_100w_mtr_10;                 /* +0x073 0x046CC [fact] alignment item "116 [TX] 100W MTR  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a117_tx_100w_txg_10;                 /* +0x074 0x046CD [fact] alignment item "117 [TX] 100W TXG  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a118_tx_50w_falc_10;                 /* +0x075 0x046CE [fact] alignment item "118 [TX]  50W FALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a119_tx_50w_mtr_10;                  /* +0x076 0x046CF [fact] alignment item "119 [TX]  50W MTR  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a120_tx_50w_txg_10;                  /* +0x077 0x046D0 [fact] alignment item "120 [TX]  50W TXG  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a121_tx_20w_falc_10;                 /* +0x078 0x046D1 [fact] alignment item "121 [TX]  20W FALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a122_tx_20w_mtr_10;                  /* +0x079 0x046D2 [fact] alignment item "122 [TX]  20W MTR  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a123_tx_20w_txg_10;                  /* +0x07A 0x046D3 [fact] alignment item "123 [TX]  20W TXG  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a124_tx_10w_falc_10;                 /* +0x07B 0x046D4 [fact] alignment item "124 [TX]  10W FALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a125_tx_10w_mtr_10;                  /* +0x07C 0x046D5 [fact] alignment item "125 [TX]  10W MTR  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a126_tx_10w_txg_10;                  /* +0x07D 0x046D6 [fact] alignment item "126 [TX]  10W TXG  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a127_tx_5w_falc_10;                  /* +0x07E 0x046D7 [fact] alignment item "127 [TX]   5W FALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a128_tx_5w_mtr_10;                   /* +0x07F 0x046D8 [fact] alignment item "128 [TX]   5W MTR  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a129_tx_5w_txg_10;                   /* +0x080 0x046D9 [fact] alignment item "129 [TX]   5W TXG  10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a130_tx_100w_falc_14;                /* +0x081 0x046DA [fact] alignment item "130 [TX] 100W FALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a131_tx_100w_mtr_14;                 /* +0x082 0x046DB [fact] alignment item "131 [TX] 100W MTR  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a132_tx_100w_txg_14;                 /* +0x083 0x046DC [fact] alignment item "132 [TX] 100W TXG  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a133_tx_50w_falc_14;                 /* +0x084 0x046DD [fact] alignment item "133 [TX]  50W FALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a134_tx_50w_mtr_14;                  /* +0x085 0x046DE [fact] alignment item "134 [TX]  50W MTR  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a135_tx_50w_txg_14;                  /* +0x086 0x046DF [fact] alignment item "135 [TX]  50W TXG  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a136_tx_20w_falc_14;                 /* +0x087 0x046E0 [fact] alignment item "136 [TX]  20W FALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a137_tx_20w_mtr_14;                  /* +0x088 0x046E1 [fact] alignment item "137 [TX]  20W MTR  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a138_tx_20w_txg_14;                  /* +0x089 0x046E2 [fact] alignment item "138 [TX]  20W TXG  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a139_tx_10w_falc_14;                 /* +0x08A 0x046E3 [fact] alignment item "139 [TX]  10W FALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a140_tx_10w_mtr_14;                  /* +0x08B 0x046E4 [fact] alignment item "140 [TX]  10W MTR  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a141_tx_10w_txg_14;                  /* +0x08C 0x046E5 [fact] alignment item "141 [TX]  10W TXG  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a142_tx_5w_falc_14;                  /* +0x08D 0x046E6 [fact] alignment item "142 [TX]   5W FALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a143_tx_5w_mtr_14;                   /* +0x08E 0x046E7 [fact] alignment item "143 [TX]   5W MTR  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a144_tx_5w_txg_14;                   /* +0x08F 0x046E8 [fact] alignment item "144 [TX]   5W TXG  14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a145_tx_100w_falc_18;                /* +0x090 0x046E9 [fact] alignment item "145 [TX] 100W FALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a146_tx_100w_mtr_18;                 /* +0x091 0x046EA [fact] alignment item "146 [TX] 100W MTR  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a147_tx_100w_txg_18;                 /* +0x092 0x046EB [fact] alignment item "147 [TX] 100W TXG  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a148_tx_50w_falc_18;                 /* +0x093 0x046EC [fact] alignment item "148 [TX]  50W FALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a149_tx_50w_mtr_18;                  /* +0x094 0x046ED [fact] alignment item "149 [TX]  50W MTR  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a150_tx_50w_txg_18;                  /* +0x095 0x046EE [fact] alignment item "150 [TX]  50W TXG  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a151_tx_20w_falc_18;                 /* +0x096 0x046EF [fact] alignment item "151 [TX]  20W FALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a152_tx_20w_mtr_18;                  /* +0x097 0x046F0 [fact] alignment item "152 [TX]  20W MTR  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a153_tx_20w_txg_18;                  /* +0x098 0x046F1 [fact] alignment item "153 [TX]  20W TXG  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a154_tx_10w_falc_18;                 /* +0x099 0x046F2 [fact] alignment item "154 [TX]  10W FALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a155_tx_10w_mtr_18;                  /* +0x09A 0x046F3 [fact] alignment item "155 [TX]  10W MTR  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a156_tx_10w_txg_18;                  /* +0x09B 0x046F4 [fact] alignment item "156 [TX]  10W TXG  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a157_tx_5w_falc_18;                  /* +0x09C 0x046F5 [fact] alignment item "157 [TX]   5W FALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a158_tx_5w_mtr_18;                   /* +0x09D 0x046F6 [fact] alignment item "158 [TX]   5W MTR  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a159_tx_5w_txg_18;                   /* +0x09E 0x046F7 [fact] alignment item "159 [TX]   5W TXG  18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a160_tx_100w_falc_21;                /* +0x09F 0x046F8 [fact] alignment item "160 [TX] 100W FALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a161_tx_100w_mtr_21;                 /* +0x0A0 0x046F9 [fact] alignment item "161 [TX] 100W MTR  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a162_tx_100w_txg_21;                 /* +0x0A1 0x046FA [fact] alignment item "162 [TX] 100W TXG  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a163_tx_50w_falc_21;                 /* +0x0A2 0x046FB [fact] alignment item "163 [TX]  50W FALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a164_tx_50w_mtr_21;                  /* +0x0A3 0x046FC [fact] alignment item "164 [TX]  50W MTR  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a165_tx_50w_txg_21;                  /* +0x0A4 0x046FD [fact] alignment item "165 [TX]  50W TXG  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a166_tx_20w_falc_21;                 /* +0x0A5 0x046FE [fact] alignment item "166 [TX]  20W FALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a167_tx_20w_mtr_21;                  /* +0x0A6 0x046FF [fact] alignment item "167 [TX]  20W MTR  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a168_tx_20w_txg_21;                  /* +0x0A7 0x04700 [fact] alignment item "168 [TX]  20W TXG  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a169_tx_10w_falc_21;                 /* +0x0A8 0x04701 [fact] alignment item "169 [TX]  10W FALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a170_tx_10w_mtr_21;                  /* +0x0A9 0x04702 [fact] alignment item "170 [TX]  10W MTR  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a171_tx_10w_txg_21;                  /* +0x0AA 0x04703 [fact] alignment item "171 [TX]  10W TXG  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a172_tx_5w_falc_21;                  /* +0x0AB 0x04704 [fact] alignment item "172 [TX]   5W FALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a173_tx_5w_mtr_21;                   /* +0x0AC 0x04705 [fact] alignment item "173 [TX]   5W MTR  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a174_tx_5w_txg_21;                   /* +0x0AD 0x04706 [fact] alignment item "174 [TX]   5W TXG  21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a175_tx_100w_falc_24;                /* +0x0AE 0x04707 [fact] alignment item "175 [TX] 100W FALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a176_tx_100w_mtr_24;                 /* +0x0AF 0x04708 [fact] alignment item "176 [TX] 100W MTR  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a177_tx_100w_txg_24;                 /* +0x0B0 0x04709 [fact] alignment item "177 [TX] 100W TXG  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a178_tx_50w_falc_24;                 /* +0x0B1 0x0470A [fact] alignment item "178 [TX]  50W FALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a179_tx_50w_mtr_24;                  /* +0x0B2 0x0470B [fact] alignment item "179 [TX]  50W MTR  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a180_tx_50w_txg_24;                  /* +0x0B3 0x0470C [fact] alignment item "180 [TX]  50W TXG  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a181_tx_20w_falc_24;                 /* +0x0B4 0x0470D [fact] alignment item "181 [TX]  20W FALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a182_tx_20w_mtr_24;                  /* +0x0B5 0x0470E [fact] alignment item "182 [TX]  20W MTR  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a183_tx_20w_txg_24;                  /* +0x0B6 0x0470F [fact] alignment item "183 [TX]  20W TXG  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a184_tx_10w_falc_24;                 /* +0x0B7 0x04710 [fact] alignment item "184 [TX]  10W FALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a185_tx_10w_mtr_24;                  /* +0x0B8 0x04711 [fact] alignment item "185 [TX]  10W MTR  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a186_tx_10w_txg_24;                  /* +0x0B9 0x04712 [fact] alignment item "186 [TX]  10W TXG  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a187_tx_5w_falc_24;                  /* +0x0BA 0x04713 [fact] alignment item "187 [TX]   5W FALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a188_tx_5w_mtr_24;                   /* +0x0BB 0x04714 [fact] alignment item "188 [TX]   5W MTR  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a189_tx_5w_txg_24;                   /* +0x0BC 0x04715 [fact] alignment item "189 [TX]   5W TXG  24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a190_tx_100w_falc_28;                /* +0x0BD 0x04716 [fact] alignment item "190 [TX] 100W FALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a191_tx_100w_mtr_28;                 /* +0x0BE 0x04717 [fact] alignment item "191 [TX] 100W MTR  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a192_tx_100w_txg_28;                 /* +0x0BF 0x04718 [fact] alignment item "192 [TX] 100W TXG  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a193_tx_50w_falc_28;                 /* +0x0C0 0x04719 [fact] alignment item "193 [TX]  50W FALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a194_tx_50w_mtr_28;                  /* +0x0C1 0x0471A [fact] alignment item "194 [TX]  50W MTR  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a195_tx_50w_txg_28;                  /* +0x0C2 0x0471B [fact] alignment item "195 [TX]  50W TXG  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a196_tx_20w_falc_28;                 /* +0x0C3 0x0471C [fact] alignment item "196 [TX]  20W FALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a197_tx_20w_mtr_28;                  /* +0x0C4 0x0471D [fact] alignment item "197 [TX]  20W MTR  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a198_tx_20w_txg_28;                  /* +0x0C5 0x0471E [fact] alignment item "198 [TX]  20W TXG  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a199_tx_10w_falc_28;                 /* +0x0C6 0x0471F [fact] alignment item "199 [TX]  10W FALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a200_tx_10w_mtr_28;                  /* +0x0C7 0x04720 [fact] alignment item "200 [TX]  10W MTR  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a201_tx_10w_txg_28;                  /* +0x0C8 0x04721 [fact] alignment item "201 [TX]  10W TXG  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a202_tx_5w_falc_28;                  /* +0x0C9 0x04722 [fact] alignment item "202 [TX]   5W FALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a203_tx_5w_mtr_28;                   /* +0x0CA 0x04723 [fact] alignment item "203 [TX]   5W MTR  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a204_tx_5w_txg_28;                   /* +0x0CB 0x04724 [fact] alignment item "204 [TX]   5W TXG  28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a205_tx_100w_falc_50;                /* +0x0CC 0x04725 [fact] alignment item "205 [TX] 100W FALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a206_tx_100w_mtr_50;                 /* +0x0CD 0x04726 [fact] alignment item "206 [TX] 100W MTR  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a207_tx_100w_txg_50;                 /* +0x0CE 0x04727 [fact] alignment item "207 [TX] 100W TXG  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a208_tx_50w_falc_50;                 /* +0x0CF 0x04728 [fact] alignment item "208 [TX]  50W FALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a209_tx_50w_mtr_50;                  /* +0x0D0 0x04729 [fact] alignment item "209 [TX]  50W MTR  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a210_tx_50w_txg_50;                  /* +0x0D1 0x0472A [fact] alignment item "210 [TX]  50W TXG  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a211_tx_20w_falc_50;                 /* +0x0D2 0x0472B [fact] alignment item "211 [TX]  20W FALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a212_tx_20w_mtr_50;                  /* +0x0D3 0x0472C [fact] alignment item "212 [TX]  20W MTR  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a213_tx_20w_txg_50;                  /* +0x0D4 0x0472D [fact] alignment item "213 [TX]  20W TXG  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a214_tx_10w_falc_50;                 /* +0x0D5 0x0472E [fact] alignment item "214 [TX]  10W FALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a215_tx_10w_mtr_50;                  /* +0x0D6 0x0472F [fact] alignment item "215 [TX]  10W MTR  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a216_tx_10w_txg_50;                  /* +0x0D7 0x04730 [fact] alignment item "216 [TX]  10W TXG  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a217_tx_5w_falc_50;                  /* +0x0D8 0x04731 [fact] alignment item "217 [TX]   5W FALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a218_tx_5w_mtr_50;                   /* +0x0D9 0x04732 [fact] alignment item "218 [TX]   5W MTR  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a219_tx_5w_txg_50;                   /* +0x0DA 0x04733 [fact] alignment item "219 [TX]   5W TXG  50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a220_tx_reserved;                    /* +0x0DB 0x04734 [fact] alignment item "220 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a221_tx_reserved;                    /* +0x0DC 0x04735 [fact] alignment item "221 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a222_tx_reserved;                    /* +0x0DD 0x04736 [fact] alignment item "222 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a223_tx_50w_falc_70;                 /* +0x0DE 0x04737 [fact] alignment item "223 [TX]  50W FALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a224_tx_50w_mtr_70;                  /* +0x0DF 0x04738 [fact] alignment item "224 [TX]  50W MTR  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a225_tx_50w_txg_70;                  /* +0x0E0 0x04739 [fact] alignment item "225 [TX]  50W TXG  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a226_tx_20w_falc_70;                 /* +0x0E1 0x0473A [fact] alignment item "226 [TX]  20W FALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a227_tx_20w_mtr_70;                  /* +0x0E2 0x0473B [fact] alignment item "227 [TX]  20W MTR  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a228_tx_20w_txg_70;                  /* +0x0E3 0x0473C [fact] alignment item "228 [TX]  20W TXG  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a229_tx_10w_falc_70;                 /* +0x0E4 0x0473D [fact] alignment item "229 [TX]  10W FALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a230_tx_10w_mtr_70;                  /* +0x0E5 0x0473E [fact] alignment item "230 [TX]  10W MTR  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a231_tx_10w_txg_70;                  /* +0x0E6 0x0473F [fact] alignment item "231 [TX]  10W TXG  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a232_tx_5w_falc_70;                  /* +0x0E7 0x04740 [fact] alignment item "232 [TX]   5W FALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a233_tx_5w_mtr_70;                   /* +0x0E8 0x04741 [fact] alignment item "233 [TX]   5W MTR  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a234_tx_5w_txg_70;                   /* +0x0E9 0x04742 [fact] alignment item "234 [TX]   5W TXG  70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a235_tx_rev_alc_1_8;                 /* +0x0EA 0x04743 [fact] alignment item "235 [TX] REV ALC 1.8" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a236_tx_rev_alc_3_5;                 /* +0x0EB 0x04744 [fact] alignment item "236 [TX] REV ALC 3.5" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a237_tx_rev_alc_7;                   /* +0x0EC 0x04745 [fact] alignment item "237 [TX] REV ALC 7" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a238_tx_rev_alc_10;                  /* +0x0ED 0x04746 [fact] alignment item "238 [TX] REV ALC 10" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a239_tx_rev_alc_14;                  /* +0x0EE 0x04747 [fact] alignment item "239 [TX] REV ALC 14" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a240_tx_rev_alc_18;                  /* +0x0EF 0x04748 [fact] alignment item "240 [TX] REV ALC 18" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a241_tx_rev_alc_21;                  /* +0x0F0 0x04749 [fact] alignment item "241 [TX] REV ALC 21" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a242_tx_rev_alc_24;                  /* +0x0F1 0x0474A [fact] alignment item "242 [TX] REV ALC 24" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a243_tx_rev_alc_28;                  /* +0x0F2 0x0474B [fact] alignment item "243 [TX] REV ALC 28" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a244_tx_rev_alc_50;                  /* +0x0F3 0x0474C [fact] alignment item "244 [TX] REV ALC 50" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a245_tx_rev_alc_70;                  /* +0x0F4 0x0474D [fact] alignment item "245 [TX] REV ALC 70" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a246_tx_alc_mtr;                     /* +0x0F5 0x0474E [fact] alignment item "246 [TX] ALC MTR" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a247_tx_reserved;                    /* +0x0F6 0x0474F [fact] alignment item "247 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a248_tx_reserved;                    /* +0x0F7 0x04750 [fact] alignment item "248 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a249_tx_reserved;                    /* +0x0F8 0x04751 [fact] alignment item "249 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a250_tx_reserved;                    /* +0x0F9 0x04752 [fact] alignment item "250 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a251_tx_reserved;                    /* +0x0FA 0x04753 [fact] alignment item "251 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a252_tx_reserved;                    /* +0x0FB 0x04754 [fact] alignment item "252 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a253_tx_reserved;                    /* +0x0FC 0x04755 [fact] alignment item "253 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a254_tx_reserved;                    /* +0x0FD 0x04756 [fact] alignment item "254 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a255_tx_reserved;                    /* +0x0FE 0x04757 [fact] alignment item "255 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a256_tx_reserved;                    /* +0x0FF 0x04758 [fact] alignment item "256 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a257_tx_reserved;                    /* +0x100 0x04759 [fact] alignment item "257 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a258_tx_reserved;                    /* +0x101 0x0475A [fact] alignment item "258 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a259_tx_reserved;                    /* +0x102 0x0475B [fact] alignment item "259 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a260_tx_reserved;                    /* +0x103 0x0475C [fact] alignment item "260 [TX] --RESERVED--" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
    uint8_t a261_tx_idd_mtr;                     /* +0x104 0x0475D [fact] alignment item "261 [TX] IDD MTR" (label table ROM 0xFFF817C3; eeprom.md cfg105) */
};

struct ee_hdr {  /* size 0xA: EEPROM header mirror at 0x464F (EEPROM 0x0000) */
    uint8_t stamp[5];                            /* +0x000 0x0464F [fact] date/time stamp, BCD yy mm dd hh mm (from DT via JP set; eeprom.md) */
    uint8_t save_count_be[4];                    /* +0x005 0x04654 [fact] big-endian save counter, +1 per save (eeprom_hdr_update) */
    uint8_t state;                               /* +0x009 0x04658 [fact] 0 = write in progress, 1 = clean */
};

struct mem_hdr {  /* size 0x87: memory-channel header at 0x60C9 (EEPROM 0x1A7A), dumped by E8 */
    uint8_t chan_a;                              /* +0x000 0x060C9 [fact] current memory channel VFO-A (cat_MC, cat_MR) */
    uint8_t chan_b;                              /* +0x001 0x060CA [fact] current memory channel VFO-B */
    uint8_t chan_used[117];                      /* +0x002 0x060CB [fact] channel-used flags (memory-maps.md) */
};

struct qmb_hdr {  /* size 0x11: QMB header at 0x9012 (EEPROM 0x49C3) */
    uint8_t used_mask_be[2];                     /* +0x000 0x09012 [fact] big-endian bit mask of the filled QMB slots: qmb_recall / qmb_store test CONCAT11(+0, +1) & 0x3FF (0x3FF = all ten full), FUN_fffc31c0 tests bit n */
    uint8_t count;                               /* +0x002 0x09014 [inference] number of stored QMB records (eeprom.md) */
    uint8_t order[10];                           /* +0x003 0x09015 [inference] QMB order list */
    uint8_t ptr_a[2];                            /* +0x00D 0x0901F [inference] QMB pointer VFO-A (0x901F..0x9020) */
    uint8_t ptr_b[2];                            /* +0x00F 0x09021 [inference] QMB pointer VFO-B (0x9021..0x9022) */
};

struct opstate {  /* size 0x45C: operating state at 0x9A2A (EEPROM 0x53DB): menu values, presets, front-panel values, VFO records */
    int8_t ex010101_af_treble_gain;              /* +0x000 0x09A2A [fact] menu 010101 RADIO SETTING / MODE SSB / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010102_af_middle_tone_gain;         /* +0x001 0x09A2B [fact] menu 010102 RADIO SETTING / MODE SSB / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010103_af_bass_gain;                /* +0x002 0x09A2C [fact] menu 010103 RADIO SETTING / MODE SSB / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010104_agc_fast_delay;             /* +0x003 0x09A2D [fact] menu 010104 RADIO SETTING / MODE SSB / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010105_agc_mid_delay;              /* +0x004 0x09A2E [fact] menu 010105 RADIO SETTING / MODE SSB / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010106_agc_slow_dely;              /* +0x005 0x09A2F [fact] menu 010106 RADIO SETTING / MODE SSB / AGC SLOW DELY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010107_lcut_freq;                  /* +0x006 0x09A30 [fact] menu 010107 RADIO SETTING / MODE SSB / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010108_lcut_slope;                 /* +0x007 0x09A31 [fact] menu 010108 RADIO SETTING / MODE SSB / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010109_hcut_freq;                  /* +0x008 0x09A32 [fact] menu 010109 RADIO SETTING / MODE SSB / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010110_hcut_slope;                 /* +0x009 0x09A33 [fact] menu 010110 RADIO SETTING / MODE SSB / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010111_usb_out_level;              /* +0x00A 0x09A34 [fact] menu 010111 RADIO SETTING / MODE SSB / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010112_rear_out_level;             /* +0x00B 0x09A35 [fact] menu 010112 RADIO SETTING / MODE SSB / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010113_tx_bpf_sel;                 /* +0x00C 0x09A36 [fact] menu 010113 RADIO SETTING / MODE SSB / TX BPF SEL, u8, range 0..6 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010114_mod_source;                 /* +0x00D 0x09A37 [fact] menu 010114 RADIO SETTING / MODE SSB / MOD SOURCE, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010115_usb_mod_gain;               /* +0x00E 0x09A38 [fact] menu 010115 RADIO SETTING / MODE SSB / USB MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010116_rear_mod_gain;              /* +0x00F 0x09A39 [fact] menu 010116 RADIO SETTING / MODE SSB / REAR MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010117_rptt_select;                /* +0x010 0x09A3A [fact] menu 010117 RADIO SETTING / MODE SSB / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010118_nar_width;                  /* +0x011 0x09A3B [fact] menu 010118 RADIO SETTING / MODE SSB / NAR WIDTH, u8, range 0..22 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010119_cw_auto_mode;               /* +0x012 0x09A3C [fact] menu 010119 RADIO SETTING / MODE SSB / CW AUTO MODE, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9a3d[2];                 /* +0x013 0x09A3D [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    int8_t ex010201_af_treble_gain;              /* +0x015 0x09A3F [fact] menu 010201 RADIO SETTING / MODE AM / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010202_af_middle_tone_gain;         /* +0x016 0x09A40 [fact] menu 010202 RADIO SETTING / MODE AM / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010203_af_bass_gain;                /* +0x017 0x09A41 [fact] menu 010203 RADIO SETTING / MODE AM / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010204_agc_fast_delay;             /* +0x018 0x09A42 [fact] menu 010204 RADIO SETTING / MODE AM / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010205_agc_mid_delay;              /* +0x019 0x09A43 [fact] menu 010205 RADIO SETTING / MODE AM / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010206_agc_slow_delay;             /* +0x01A 0x09A44 [fact] menu 010206 RADIO SETTING / MODE AM / AGC SLOW DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010207_lcut_freq;                  /* +0x01B 0x09A45 [fact] menu 010207 RADIO SETTING / MODE AM / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010208_lcut_slope;                 /* +0x01C 0x09A46 [fact] menu 010208 RADIO SETTING / MODE AM / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010209_hcut_freq;                  /* +0x01D 0x09A47 [fact] menu 010209 RADIO SETTING / MODE AM / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010210_hcut_slope;                 /* +0x01E 0x09A48 [fact] menu 010210 RADIO SETTING / MODE AM / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010211_usb_out_level;              /* +0x01F 0x09A49 [fact] menu 010211 RADIO SETTING / MODE AM / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010212_rear_out_level;             /* +0x020 0x09A4A [fact] menu 010212 RADIO SETTING / MODE AM / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010213_tx_bpf_sel;                 /* +0x021 0x09A4B [fact] menu 010213 RADIO SETTING / MODE AM / TX BPF SEL, u8, range 0..4 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010214_mod_source;                 /* +0x022 0x09A4C [fact] menu 010214 RADIO SETTING / MODE AM / MOD SOURCE, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010215_usb_mod_gain;               /* +0x023 0x09A4D [fact] menu 010215 RADIO SETTING / MODE AM / USB MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010216_rear_mod_gain;              /* +0x024 0x09A4E [fact] menu 010216 RADIO SETTING / MODE AM / REAR MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010217_rptt_select;                /* +0x025 0x09A4F [fact] menu 010217 RADIO SETTING / MODE AM / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9a50[2];                 /* +0x026 0x09A50 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    int8_t ex010301_af_treble_gain;              /* +0x028 0x09A52 [fact] menu 010301 RADIO SETTING / MODE FM / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010302_af_middle_tone_gain;         /* +0x029 0x09A53 [fact] menu 010302 RADIO SETTING / MODE FM / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010303_af_bass_gain;                /* +0x02A 0x09A54 [fact] menu 010303 RADIO SETTING / MODE FM / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010304_agc_fast_delay;             /* +0x02B 0x09A55 [fact] menu 010304 RADIO SETTING / MODE FM / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010305_agc_mid_delay;              /* +0x02C 0x09A56 [fact] menu 010305 RADIO SETTING / MODE FM / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010306_agc_slow_delay;             /* +0x02D 0x09A57 [fact] menu 010306 RADIO SETTING / MODE FM / AGC SLOW DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010307_lcut_freq;                  /* +0x02E 0x09A58 [fact] menu 010307 RADIO SETTING / MODE FM / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010308_lcut_slope;                 /* +0x02F 0x09A59 [fact] menu 010308 RADIO SETTING / MODE FM / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010309_hcut_freq;                  /* +0x030 0x09A5A [fact] menu 010309 RADIO SETTING / MODE FM / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010310_hcut_slope;                 /* +0x031 0x09A5B [fact] menu 010310 RADIO SETTING / MODE FM / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010311_usb_out_level;              /* +0x032 0x09A5C [fact] menu 010311 RADIO SETTING / MODE FM / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010312_rear_out_level;             /* +0x033 0x09A5D [fact] menu 010312 RADIO SETTING / MODE FM / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010313_mod_source;                 /* +0x034 0x09A5E [fact] menu 010313 RADIO SETTING / MODE FM / MOD SOURCE, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010314_usb_mod_gain;               /* +0x035 0x09A5F [fact] menu 010314 RADIO SETTING / MODE FM / USB MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010315_rear_mod_gain;              /* +0x036 0x09A60 [fact] menu 010315 RADIO SETTING / MODE FM / REAR MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010316_rptt_select;                /* +0x037 0x09A61 [fact] menu 010316 RADIO SETTING / MODE FM / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010318_rpt_shift_28mhz;            /* +0x038 0x09A62 [fact] menu 010318 RADIO SETTING / MODE FM / RPT SHIFT(28MHz), u8 x10, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010319_rpt_shift_50mhz_be[2];      /* +0x039 0x09A63 [fact] menu 010319 RADIO SETTING / MODE FM / RPT SHIFT(50MHz), u16 x10, read byte by byte (big-endian [inference]), range 0..400 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9a65[2];                 /* +0x03B 0x09A65 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    int8_t ex010401_af_treble_gain;              /* +0x03D 0x09A67 [fact] menu 010401 RADIO SETTING / MODE PSK/DATA / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010402_af_middle_tone_gain;         /* +0x03E 0x09A68 [fact] menu 010402 RADIO SETTING / MODE PSK/DATA / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010403_af_bass_gain;                /* +0x03F 0x09A69 [fact] menu 010403 RADIO SETTING / MODE PSK/DATA / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010404_agc_fast_delay;             /* +0x040 0x09A6A [fact] menu 010404 RADIO SETTING / MODE PSK/DATA / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010405_agc_mid_delay;              /* +0x041 0x09A6B [fact] menu 010405 RADIO SETTING / MODE PSK/DATA / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010406_agc_slow_delay;             /* +0x042 0x09A6C [fact] menu 010406 RADIO SETTING / MODE PSK/DATA / AGC SLOW DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010407_lcut_freq;                  /* +0x043 0x09A6D [fact] menu 010407 RADIO SETTING / MODE PSK/DATA / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010408_lcut_slope;                 /* +0x044 0x09A6E [fact] menu 010408 RADIO SETTING / MODE PSK/DATA / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010409_hcut_freq;                  /* +0x045 0x09A6F [fact] menu 010409 RADIO SETTING / MODE PSK/DATA / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010410_hcut_slope;                 /* +0x046 0x09A70 [fact] menu 010410 RADIO SETTING / MODE PSK/DATA / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010411_usb_out_level;              /* +0x047 0x09A71 [fact] menu 010411 RADIO SETTING / MODE PSK/DATA / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010412_rear_out_level;             /* +0x048 0x09A72 [fact] menu 010412 RADIO SETTING / MODE PSK/DATA / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010413_tx_bpf_sel;                 /* +0x049 0x09A73 [fact] menu 010413 RADIO SETTING / MODE PSK/DATA / TX BPF SEL, u8, range 0..4 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010414_mod_source;                 /* +0x04A 0x09A74 [fact] menu 010414 RADIO SETTING / MODE PSK/DATA / MOD SOURCE, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010415_usb_mod_gain;               /* +0x04B 0x09A75 [fact] menu 010415 RADIO SETTING / MODE PSK/DATA / USB MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010416_rear_mod_gain;              /* +0x04C 0x09A76 [fact] menu 010416 RADIO SETTING / MODE PSK/DATA / REAR MOD GAIN, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010417_rptt_select;                /* +0x04D 0x09A77 [fact] menu 010417 RADIO SETTING / MODE PSK/DATA / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010418_nar_width;                  /* +0x04E 0x09A78 [fact] menu 010418 RADIO SETTING / MODE PSK/DATA / NAR WIDTH, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010419_psk_tone;                   /* +0x04F 0x09A79 [fact] menu 010419 RADIO SETTING / MODE PSK/DATA / PSK TONE, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010420_data_shift_ssb_be[2];       /* +0x050 0x09A7A [fact] menu 010420 RADIO SETTING / MODE PSK/DATA / DATA SHIFT (SSB), u16 x10, read byte by byte (big-endian [inference]), range 0..300 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9a7c[2];                 /* +0x052 0x09A7C [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    int8_t ex010501_af_treble_gain;              /* +0x054 0x09A7E [fact] menu 010501 RADIO SETTING / MODE RTTY / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010502_af_middle_tone_gain;         /* +0x055 0x09A7F [fact] menu 010502 RADIO SETTING / MODE RTTY / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex010503_af_bass_gain;                /* +0x056 0x09A80 [fact] menu 010503 RADIO SETTING / MODE RTTY / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010504_agc_fast_delay;             /* +0x057 0x09A81 [fact] menu 010504 RADIO SETTING / MODE RTTY / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010505_agc_mid_delay;              /* +0x058 0x09A82 [fact] menu 010505 RADIO SETTING / MODE RTTY / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010506_agc_slow_delay;             /* +0x059 0x09A83 [fact] menu 010506 RADIO SETTING / MODE RTTY / AGC SLOW DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010507_lcut_freq;                  /* +0x05A 0x09A84 [fact] menu 010507 RADIO SETTING / MODE RTTY / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010508_lcut_slope;                 /* +0x05B 0x09A85 [fact] menu 010508 RADIO SETTING / MODE RTTY / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010509_hcut_freq;                  /* +0x05C 0x09A86 [fact] menu 010509 RADIO SETTING / MODE RTTY / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010510_hcut_slope;                 /* +0x05D 0x09A87 [fact] menu 010510 RADIO SETTING / MODE RTTY / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010511_usb_out_level;              /* +0x05E 0x09A88 [fact] menu 010511 RADIO SETTING / MODE RTTY / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010512_rear_out_level;             /* +0x05F 0x09A89 [fact] menu 010512 RADIO SETTING / MODE RTTY / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010513_rptt_select;                /* +0x060 0x09A8A [fact] menu 010513 RADIO SETTING / MODE RTTY / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010514_nar_width;                  /* +0x061 0x09A8B [fact] menu 010514 RADIO SETTING / MODE RTTY / NAR WIDTH, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010515_mark_frequency;             /* +0x062 0x09A8C [fact] menu 010515 RADIO SETTING / MODE RTTY / MARK FREQUENCY, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010516_shift_frequency;            /* +0x063 0x09A8D [fact] menu 010516 RADIO SETTING / MODE RTTY / SHIFT FREQUENCY, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex010517_polarity_tx;                /* +0x064 0x09A8E [fact] menu 010517 RADIO SETTING / MODE RTTY / POLARITY TX, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9a8f[2];                 /* +0x065 0x09A8F [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    int8_t ex020101_af_treble_gain;              /* +0x067 0x09A91 [fact] menu 020101 CW SETTING / MODE CW / AF TREBLE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex020102_af_middle_tone_gain;         /* +0x068 0x09A92 [fact] menu 020102 CW SETTING / MODE CW / AF MIDDLE TONE GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex020103_af_bass_gain;                /* +0x069 0x09A93 [fact] menu 020103 CW SETTING / MODE CW / AF BASS GAIN, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020104_agc_fast_delay;             /* +0x06A 0x09A94 [fact] menu 020104 CW SETTING / MODE CW / AGC FAST DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020105_agc_mid_delay;              /* +0x06B 0x09A95 [fact] menu 020105 CW SETTING / MODE CW / AGC MID DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020106_agc_slow_delay;             /* +0x06C 0x09A96 [fact] menu 020106 CW SETTING / MODE CW / AGC SLOW DELAY, u8 x20+20, range 0..199 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020107_lcut_freq;                  /* +0x06D 0x09A97 [fact] menu 020107 CW SETTING / MODE CW / LCUT FREQ, u8, range 0..19 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020108_lcut_slope;                 /* +0x06E 0x09A98 [fact] menu 020108 CW SETTING / MODE CW / LCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020109_hcut_freq;                  /* +0x06F 0x09A99 [fact] menu 020109 CW SETTING / MODE CW / HCUT FREQ, u8, range 0..67 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020110_hcut_slope;                 /* +0x070 0x09A9A [fact] menu 020110 CW SETTING / MODE CW / HCUT SLOPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020111_usb_out_level;              /* +0x071 0x09A9B [fact] menu 020111 CW SETTING / MODE CW / USB OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020112_rear_out_level;             /* +0x072 0x09A9C [fact] menu 020112 CW SETTING / MODE CW / REAR OUT LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020113_rptt_select;                /* +0x073 0x09A9D [fact] menu 020113 CW SETTING / MODE CW / RPTT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020114_nar_width;                  /* +0x074 0x09A9E [fact] menu 020114 CW SETTING / MODE CW / NAR WIDTH, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020115_pc_keying;                  /* +0x075 0x09A9F [fact] menu 020115 CW SETTING / MODE CW / PC KEYING, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020116_cw_bk_in_type;              /* +0x076 0x09AA0 [fact] menu 020116 CW SETTING / MODE CW / CW BK-IN TYPE, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020117_cw_wave_shape;              /* +0x077 0x09AA1 [fact] menu 020117 CW SETTING / MODE CW / CW WAVE SHAPE, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020118_cw_freq_display;            /* +0x078 0x09AA2 [fact] menu 020118 CW SETTING / MODE CW / CW FREQ DISPLAY, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020119_qsk_delay_time;             /* +0x079 0x09AA3 [fact] menu 020119 CW SETTING / MODE CW / QSK DELAY TIME, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020120_cw_indicator;               /* +0x07A 0x09AA4 [fact] menu 020120 CW SETTING / MODE CW / CW INDICATOR, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9aa5[2];                 /* +0x07B 0x09AA5 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex020201_keyer_type;                 /* +0x07D 0x09AA7 [fact] menu 020201 CW SETTING / KEYER / KEYER TYPE, u8, range 0..5 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020202_keyer_dot_dash;             /* +0x07E 0x09AA8 [fact] menu 020202 CW SETTING / KEYER / KEYER DOT/DASH, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020203_cw_weight;                  /* +0x07F 0x09AA9 [fact] menu 020203 CW SETTING / KEYER / CW WEIGHT, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020204_number_style;               /* +0x080 0x09AAA [fact] menu 020204 CW SETTING / KEYER / NUMBER STYLE, u8, range 0..6 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020205_contest_number_be[2];       /* +0x081 0x09AAB [fact] menu 020205 CW SETTING / KEYER / CONTEST NUMBER, u16, read byte by byte (big-endian [inference]), range 1..9999 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020206_cw_memory_1;                /* +0x083 0x09AAD [fact] menu 020206 CW SETTING / KEYER / CW MEMORY 1, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020207_cw_memory_2;                /* +0x084 0x09AAE [fact] menu 020207 CW SETTING / KEYER / CW MEMORY 2, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020208_cw_memory_3;                /* +0x085 0x09AAF [fact] menu 020208 CW SETTING / KEYER / CW MEMORY 3, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020209_cw_memory_4;                /* +0x086 0x09AB0 [fact] menu 020209 CW SETTING / KEYER / CW MEMORY 4, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020210_cw_memory_5;                /* +0x087 0x09AB1 [fact] menu 020210 CW SETTING / KEYER / CW MEMORY 5, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex020211_repeat_interval;            /* +0x088 0x09AB2 [fact] menu 020211 CW SETTING / KEYER / REPEAT INTERVAL, u8, range 1..60 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9ab3[2];                 /* +0x089 0x09AB3 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex030101_beep_level;                 /* +0x08B 0x09AB5 [fact] menu 030101 OPERATION SETTING / GENERAL / BEEP LEVEL, u8, range 0..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030102_rf_sql_vr;                  /* +0x08C 0x09AB6 [fact] menu 030102 OPERATION SETTING / GENERAL / RF/SQL VR, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    enum tunlin_mode ex030103_tun_lin_port_select; /* +0x08D 0x09AB7 [fact] menu 030103 OPERATION SETTING / GENERAL / TUN/LIN PORT SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030104_tuner_type_select;          /* +0x08E 0x09AB8 [fact] menu 030104 OPERATION SETTING / GENERAL / TUNER TYPE SELECT, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030105_cat_1_rate;                 /* +0x08F 0x09AB9 [fact] menu 030105 OPERATION SETTING / GENERAL / CAT-1 RATE, u8, range 0..4 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030106_cat_1_time_out_timer;       /* +0x090 0x09ABA [fact] menu 030106 OPERATION SETTING / GENERAL / CAT-1 TIME OUT TIMER, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030107_cat_1_cat_3_stop_bit;       /* +0x091 0x09ABB [fact] menu 030107 OPERATION SETTING / GENERAL / CAT-1 CAT-3 STOP BIT, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030108_cat_2_rate;                 /* +0x092 0x09ABC [fact] menu 030108 OPERATION SETTING / GENERAL / CAT-2 RATE, u8, range 0..4 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030109_cat_2_time_out_timer;       /* +0x093 0x09ABD [fact] menu 030109 OPERATION SETTING / GENERAL / CAT-2 TIME OUT TIMER, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030110_cat_3_rate;                 /* +0x094 0x09ABE [fact] menu 030110 OPERATION SETTING / GENERAL / CAT-3 RATE, u8, range 0..4 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030111_cat_3_time_out_timer;       /* +0x095 0x09ABF [fact] menu 030111 OPERATION SETTING / GENERAL / CAT-3 TIME OUT TIMER, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030112_qmb_ch;                     /* +0x096 0x09AC0 [fact] menu 030112 OPERATION SETTING / GENERAL / QMB CH, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030113_band_stack;                 /* +0x097 0x09AC1 [fact] menu 030113 OPERATION SETTING / GENERAL / BAND STACK, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030114_mem_group;                  /* +0x098 0x09AC2 [fact] menu 030114 OPERATION SETTING / GENERAL / MEM GROUP, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030115_tx_time_out_timer;          /* +0x099 0x09AC3 [fact] menu 030115 OPERATION SETTING / GENERAL / TX TIME OUT TIMER, u8, range 0..30 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030116_mic_scan;                   /* +0x09A 0x09AC4 [fact] menu 030116 OPERATION SETTING / GENERAL / MIC SCAN, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030117_mic_scan_resume;            /* +0x09B 0x09AC5 [fact] menu 030117 OPERATION SETTING / GENERAL / MIC SCAN RESUME, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030118_ref_freq_fine_adj;           /* +0x09C 0x09AC6 [fact] menu 030118 OPERATION SETTING / GENERAL / REF FREQ FINE ADJ, s8, range -25..25 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030119_keyboard_language;          /* +0x09D 0x09AC7 [fact] menu 030119 OPERATION SETTING / GENERAL / KEYBOARD LANGUAGE, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030120_mic_p1;                     /* +0x09E 0x09AC8 [fact] menu 030120 OPERATION SETTING / GENERAL / MIC P1, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030121_mic_p2;                     /* +0x09F 0x09AC9 [fact] menu 030121 OPERATION SETTING / GENERAL / MIC P2, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030122_mic_p3;                     /* +0x0A0 0x09ACA [fact] menu 030122 OPERATION SETTING / GENERAL / MIC P3, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030123_mic_p4;                     /* +0x0A1 0x09ACB [fact] menu 030123 OPERATION SETTING / GENERAL / MIC P4, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030124_mic_up;                     /* +0x0A2 0x09ACC [fact] menu 030124 OPERATION SETTING / GENERAL / MIC UP, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030125_mic_down;                   /* +0x0A3 0x09ACD [fact] menu 030125 OPERATION SETTING / GENERAL / MIC DOWN, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030126_scu_lan10;                  /* +0x0A4 0x09ACE [fact] menu 030126 OPERATION SETTING / GENERAL / SCU-LAN10, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9acf[2];                 /* +0x0A5 0x09ACF [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex030201_if_notch_width;             /* +0x0A7 0x09AD1 [fact] menu 030201 OPERATION SETTING / RX DSP / IF NOTCH WIDTH, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030202_nb_rejection;               /* +0x0A8 0x09AD2 [fact] menu 030202 OPERATION SETTING / RX DSP / NB REJECTION, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030203_nb_width;                   /* +0x0A9 0x09AD3 [fact] menu 030203 OPERATION SETTING / RX DSP / NB WIDTH, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030204_apf_width;                  /* +0x0AA 0x09AD4 [fact] menu 030204 OPERATION SETTING / RX DSP / APF WIDTH, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030205_contour_level;               /* +0x0AB 0x09AD5 [fact] menu 030205 OPERATION SETTING / RX DSP / CONTOUR LEVEL, s8, range -40..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030206_contour_width;              /* +0x0AC 0x09AD6 [fact] menu 030206 OPERATION SETTING / RX DSP / CONTOUR WIDTH, u8, range 1..11 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9ad7[2];                 /* +0x0AD 0x09AD7 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex030301_amc_release_time;           /* +0x0AF 0x09AD9 [fact] menu 030301 OPERATION SETTING / TX AUDIO / AMC RELEASE TIME, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030302_prmtrc_eq1_freq;            /* +0x0B0 0x09ADA [fact] menu 030302 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 FREQ, u8, range 0..7 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030303_prmtrc_eq1_level;            /* +0x0B1 0x09ADB [fact] menu 030303 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030304_prmtrc_eq1_bwth;            /* +0x0B2 0x09ADC [fact] menu 030304 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030305_prmtrc_eq2_freq;            /* +0x0B3 0x09ADD [fact] menu 030305 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 FREQ, u8, range 0..9 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030306_prmtrc_eq2_level;            /* +0x0B4 0x09ADE [fact] menu 030306 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030307_prmtrc_eq2_bwth;            /* +0x0B5 0x09ADF [fact] menu 030307 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030308_prmtrc_eq3_freq;            /* +0x0B6 0x09AE0 [fact] menu 030308 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 FREQ, u8, range 0..18 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030309_prmtrc_eq3_level;            /* +0x0B7 0x09AE1 [fact] menu 030309 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030310_prmtrc_eq3_bwth;            /* +0x0B8 0x09AE2 [fact] menu 030310 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030311_p_prmtrc_eq1_freq;          /* +0x0B9 0x09AE3 [fact] menu 030311 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 FREQ, u8, range 0..7 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030312_p_prmtrc_eq1_level;          /* +0x0BA 0x09AE4 [fact] menu 030312 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030313_p_prmtrc_eq1_bwth;          /* +0x0BB 0x09AE5 [fact] menu 030313 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030314_p_prmtrc_eq2_freq;          /* +0x0BC 0x09AE6 [fact] menu 030314 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 FREQ, u8, range 0..9 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030315_p_prmtrc_eq2_level;          /* +0x0BD 0x09AE7 [fact] menu 030315 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030316_p_prmtrc_eq2_bwth;          /* +0x0BE 0x09AE8 [fact] menu 030316 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030317_p_prmtrc_eq3_freq;          /* +0x0BF 0x09AE9 [fact] menu 030317 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 FREQ, u8, range 0..18 (menu descriptor, tools/main_menu_table.py) */
    int8_t ex030318_p_prmtrc_eq3_level;          /* +0x0C0 0x09AEA [fact] menu 030318 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 LEVEL, s8, range -20..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030319_p_prmtrc_eq3_bwth;          /* +0x0C1 0x09AEB [fact] menu 030319 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 BWTH, u8, range 0..10 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9aec[2];                 /* +0x0C2 0x09AEC [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex030401_hf_max_power;               /* +0x0C4 0x09AEE [fact] menu 030401 OPERATION SETTING / TX GENERAL / HF MAX POWER, u8, range 5..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030402_50m_max_power;              /* +0x0C5 0x09AEF [fact] menu 030402 OPERATION SETTING / TX GENERAL / 50M MAX POWER, u8, range 5..100 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030403_70m_max_power;              /* +0x0C6 0x09AF0 [fact] menu 030403 OPERATION SETTING / TX GENERAL / 70M MAX POWER, u8, range 5..50 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030404_am_max_power;               /* +0x0C7 0x09AF1 [fact] menu 030404 OPERATION SETTING / TX GENERAL / AM MAX POWER, u8, range 5..25 (menu descriptor, tools/main_menu_table.py) */
    uint8_t unused_9af2;                         /* +0x0C8 0x09AF2 [fact] the only byte of the menu block nothing references (menu.md) */
    uint8_t ex030405_vox_select;                 /* +0x0C9 0x09AF3 [fact] menu 030405 OPERATION SETTING / TX GENERAL / VOX SELECT, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030406_emergency_freq_tx;          /* +0x0CA 0x09AF4 [fact] menu 030406 OPERATION SETTING / TX GENERAL / EMERGENCY FREQ TX, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030407_tx_inhitbit;                /* +0x0CB 0x09AF5 [fact] menu 030407 OPERATION SETTING / TX GENERAL / TX INHITBIT, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030408_meter_detector;             /* +0x0CC 0x09AF6 [fact] menu 030408 OPERATION SETTING / TX GENERAL / METER DETECTOR, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9af7[2];                 /* +0x0CD 0x09AF7 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex030501_ssb_cw_dial_step;           /* +0x0CF 0x09AF9 [fact] menu 030501 OPERATION SETTING / TUNING / SSB/CW DIAL STEP, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030502_rtty_psk_dial_step;         /* +0x0D0 0x09AFA [fact] menu 030502 OPERATION SETTING / TUNING / RTTY/PSK DIAL STEP, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030503_ch_step;                    /* +0x0D1 0x09AFB [fact] menu 030503 OPERATION SETTING / TUNING / CH STEP, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030504_am_ch_step;                 /* +0x0D2 0x09AFC [fact] menu 030504 OPERATION SETTING / TUNING / AM CH STEP, u8, range 0..5 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030505_fm_ch_step;                 /* +0x0D3 0x09AFD [fact] menu 030505 OPERATION SETTING / TUNING / FM CH STEP, u8, range 0..5 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex030506_main_steps_per_rev;         /* +0x0D4 0x09AFE [fact] menu 030506 OPERATION SETTING / TUNING / MAIN STEPS PER REV., u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9aff[2];                 /* +0x0D5 0x09AFF [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    char ex040101_my_call[12];                   /* +0x0D7 0x09B01 [fact] menu 040101 DISPLAY SETTING / DISPLAY / MY CALL, string12, range 0..0 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040102_my_call_time;               /* +0x0E3 0x09B0D [fact] menu 040102 DISPLAY SETTING / DISPLAY / MY CALL TIME, u8, range 0..5 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040103_pop_up_time;                /* +0x0E4 0x09B0E [fact] menu 040103 DISPLAY SETTING / DISPLAY / POP-UP TIME, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040104_screen_saver;               /* +0x0E5 0x09B0F [fact] menu 040104 DISPLAY SETTING / DISPLAY / SCREEN SAVER, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040105_led_dimmer;                 /* +0x0E6 0x09B10 [fact] menu 040105 DISPLAY SETTING / DISPLAY / LED DIMMER, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040106_mouse_pointer_speed;        /* +0x0E7 0x09B11 [fact] menu 040106 DISPLAY SETTING / DISPLAY / MOUSE POINTER SPEED, u8, range 0..20 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9b12[2];                 /* +0x0E8 0x09B12 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex040201_rbw;                        /* +0x0EA 0x09B14 [fact] menu 040201 DISPLAY SETTING / SCOPE / RBW, u8, range 0..2 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040202_scope_ctr;                  /* +0x0EB 0x09B15 [fact] menu 040202 DISPLAY SETTING / SCOPE / SCOPE CTR, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040203_2d_disp_sensitivity;        /* +0x0EC 0x09B16 [fact] menu 040203 DISPLAY SETTING / SCOPE / 2D DISP SENSITIVITY, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040204_3dss_disp_sensitivity;      /* +0x0ED 0x09B17 [fact] menu 040204 DISPLAY SETTING / SCOPE / 3DSS DISP SENSITIVITY, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9b18[2];                 /* +0x0EE 0x09B18 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex040301_vmi_color_vfo_a;            /* +0x0F0 0x09B1A [fact] menu 040301 DISPLAY SETTING / VFO IND COLOR / VMI COLOR VFO-A, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040302_vmi_color_vfo_b;            /* +0x0F1 0x09B1B [fact] menu 040302 DISPLAY SETTING / VFO IND COLOR / VMI COLOR VFO-B, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040303_vmi_color_memory;           /* +0x0F2 0x09B1C [fact] menu 040303 DISPLAY SETTING / VFO IND COLOR / VMI COLOR MEMORY, u8, range 0..3 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040304_vmi_color_clar;             /* +0x0F3 0x09B1D [fact] menu 040304 DISPLAY SETTING / VFO IND COLOR / VMI COLOR CLAR, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9b1e[2];                 /* +0x0F4 0x09B1E [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t ex040401_ext_display;                /* +0x0F6 0x09B20 [fact] menu 040401 DISPLAY SETTING / EXT MONITOR / EXT DISPLAY, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t ex040402_pixel;                      /* +0x0F7 0x09B21 [fact] menu 040402 DISPLAY SETTING / EXT MONITOR / PIXEL, u8, range 0..1 (menu descriptor, tools/main_menu_table.py) */
    uint8_t menu_cursor_9b22[2];                 /* +0x0F8 0x09B22 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t menu_cursor_9b24[2];                 /* +0x0FA 0x09B24 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t menu_cursor_9b26[2];                 /* +0x0FC 0x09B26 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t menu_cursor_9b28[2];                 /* +0x0FE 0x09B28 [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t menu_cursor_9b2a[2];                 /* +0x100 0x09B2A [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    uint8_t menu_cursor_9b2c[2];                 /* +0x102 0x09B2C [fact] {top, row} cursor of a P2 menu group (FUN_fffd405e / FUN_fffd3d03; eeprom.md) */
    struct preset presets[5];                    /* +0x104 0x09B2E [fact] PRESET1..5 (EX06), 0x1F bytes each */
    uint8_t preset_sel;                          /* +0x19F 0x09BC9 [inference] preset selection; FUN_fffc4d93 copies presets[n] to the UI state +0x48 */
    uint8_t scope_level_rx[14];                  /* +0x1A0 0x09BCA [fact] SCOPE LEVEL per frequency range in RX: FUN_fff9c6ab returns 0x9BCA + freq_range_index (display-link.md frame 0x37 item 0); FUN_fffb13e2 fills 0x9BCA..0x9C16 from ROM */
    uint8_t scope_level_tx[14];                  /* +0x1AE 0x09BD8 [fact] SCOPE LEVEL per frequency range in TX: FUN_fff9c6ab returns 0x9BD8 + freq_range_index while transmitting */
    uint8_t ss01_peak;                           /* +0x1BC 0x09BE6 [fact] scope PEAK (SS01; FUN_fff976d2) */
    uint8_t ss02_marker;                         /* +0x1BD 0x09BE7 [fact] scope MARKER (SS02) */
    uint8_t ss03_value;                          /* +0x1BE 0x09BE8 [fact] SS P2=3 value (cat_SS) */
    uint8_t tft_contrast;                        /* +0x1BF 0x09BE9 [fact] TFT CONTRAST 0..20 (DA P2; frame 0x24) */
    uint8_t tft_brightness;                      /* +0x1C0 0x09BEA [fact] TFT brightness (DA P3; frame 0x24) */
    uint8_t mic_gain[4];                         /* +0x1C2 0x09BEC [fact] MIC GAIN per mode class (MG, tx_mod_gain) */
    uint8_t proc_on;                             /* +0x1C6 0x09BF0 [inference] processor on / parametric EQ (PR; split of the PR/PL pair is [inference]) */
    uint8_t proc_level;                          /* +0x1C7 0x09BF1 [inference] processor level (PL) */
    uint8_t amc_level;                           /* +0x1C8 0x09BF2 [fact] AMC output level (AO, dsp_set_amc_level) */
    uint8_t vox_gain;                            /* +0x1C9 0x09BF3 [fact] VOX gain (VG, dsp_set_vox_gain) */
    uint8_t vox_delay[2];                        /* +0x1CA 0x09BF4 [fact] VOX delay (VD, ptt_arbiter); a 16-bit value [inference] */
    uint8_t antivox[2];                          /* +0x1CC 0x09BF6 [fact] anti-VOX (AV, dsp_set_antivox) */
    uint8_t rf_power[4];                         /* +0x1CE 0x09BF8 [fact] RF power per band group (PC, MAX POWER on_draw EX030401..04) */
    uint8_t monitor[5];                          /* +0x1D2 0x09BFC [inference] monitor level / on (ML) */
    uint8_t monitor_fm;                          /* +0x1D7 0x09C01 [fact] monitor level of FM / FM-N / DATA-FM / DATA-FM-N (modes 6, 7, 10, 11): cat_ML answers from it but rejects a set (docs/cat-commands-primary.md ML), FUN_fffb418a; the sixth entry after monitor[5] */
    uint8_t keyer_on;                            /* +0x1D8 0x09C02 [fact] keyer on (KR, keyer_task) */
    uint8_t key_speed;                           /* +0x1D9 0x09C03 [fact] key speed (KS, keyer_task) */
    uint8_t cw_pitch;                            /* +0x1DA 0x09C04 [fact] CW pitch, x10 + 300 Hz (KP, dsp_set_cw_pitch) */
    uint8_t cw_bkin_delay;                       /* +0x1DB 0x09C05 [fact] CW break-in delay (SD, FUN_fffbaa81) */
    uint8_t aess_level_ssb;                      /* +0x1DC 0x09C06 [fact] AESS level SSB, AS1 = byte x 5 (FUN_fffb54a0; #157) */
    uint8_t aess_center_ssb;                     /* +0x1DD 0x09C07 [fact] AESS centre SSB, 0 = 700 Hz, 1 = 1000 Hz (FUN_fffb552c; #157) */
    uint8_t func_knob_sf;                        /* +0x1DE 0x09C08 [fact] sub-dial (FUNC knob) function (SF, displink_build_37) */
    uint8_t aess_level[7];                       /* +0x1DF 0x09C09 [fact] AESS level CW, DATA, RTTY, DATA-FM, PSK, AM, FM (FUN_fffb54a0) */
    uint8_t aess_center[7];                      /* +0x1E6 0x09C10 [fact] AESS centre CW, DATA, RTTY, DATA-FM, PSK, AM, FM (FUN_fffb552c) */
    uint8_t zero_9c17[30];                       /* +0x1ED 0x09C17 [fact] 30 bytes copied from ROM 0xFFF80FD6 (all 0) by menu_defaults_load; no other reference */
    uint8_t scope_mode;                          /* +0x20B 0x09C35 [fact] scope CENTER 0 / CURSOR 1 / FIX 2 (SS06, cat_ai_FD) */
    uint8_t scope_3dss;                          /* +0x20C 0x09C36 [fact] 1 = 3DSS, 0 = waterfall (SS06) */
    uint8_t scope_flag_37;                       /* +0x20D 0x09C37 [fact] scope flag sent in the status block; meaning open */
    uint8_t wf_size;                             /* +0x20E 0x09C38 [fact] waterfall size, 1 NORMAL, 2 EXPAND (SS06) */
    uint8_t ss07_affft_att;                      /* +0x20F 0x09C39 [fact] SS07 P1 (dsp_set_affft_att) */
    uint8_t osc_level_tx;                        /* +0x210 0x09C3A [fact] oscilloscope level TX (SS07, dsp_set_osc) */
    uint8_t osc_level_rx;                        /* +0x211 0x09C3B [fact] oscilloscope level RX (SS07, dsp_set_osc) */
    uint8_t osc_time;                            /* +0x212 0x09C3C [fact] oscilloscope time (SS07, dsp_set_osc) */
    uint8_t scope_expand;                        /* +0x213 0x09C3D [fact] EXPAND flag, flipped with 0x9C38 by FUN_fffbc91a */
    uint8_t scope_span_idx_a[14];                /* +0x214 0x09C3E [inference] per-band scope span index, side A (scope_span_index -> 0xFFF89D24) */
    uint8_t scope_span_idx_b[14];                /* +0x222 0x09C4C [inference] per-band scope span index, side B (scope_span_index) */
    uint8_t ss00_value;                          /* +0x230 0x09C5A [fact] SS P2=0 value 0..4 (cat_SS, FUN_fffc4f9e) */
    uint8_t meter_sel;                           /* +0x231 0x09C5B [fact] meter selection 0..5 (MS; used by RM while TX) */
    uint8_t toggle_9c5c;                         /* +0x232 0x09C5C [fact] toggled only by FUN_fffbcbbd, status byte 9 bit 3; meaning open */
    uint8_t vox_on;                              /* +0x233 0x09C5D [fact] VOX on (VX, key_mox_vox_short) */
    uint8_t split_on;                            /* +0x234 0x09C5E [fact] split (ST, FT, split_toggle 0xFFFBECA5) */
    int8_t apf_freq;                             /* +0x235 0x09C5F [fact] APF frequency, CO03 value - 25 (cat_CO, dsp_set_apf) */
    uint8_t fn_select;                           /* +0x237 0x09C61 [fact] FN value 0/1/2 (cat_FN, key_fine_fast_short) */
    uint8_t lock_on;                             /* +0x238 0x09C62 [fact] front-panel lock (LK, key_lock_pwr_short) */
    uint16_t f_0x23b_u16;                        /* +0x23B 0x09C65 [fact: accessed] widths 4:3; FUN_fffdfe0a settings_defaults */
    uint8_t na_ai_value;                         /* +0x23E 0x09C68 [fact] FUN_fffdfe0a sends the auto-information NA0<n>; when it changes (shadow 0x1B51D); only settings_defaults writes it (0) */
    uint32_t bandmem_cursor[12];                 /* +0x23F 0x09C69 [fact] per-band scope start in CURSOR mode, big-endian (bandmem_get/bandmem_set; radio-control.md) */
    uint32_t bandmem_fix[12];                    /* +0x26F 0x09C99 [fact] per-band scope start in FIX mode */
    uint32_t bandmem_fix_gen[16];                /* +0x29F 0x09CC9 [fact] FIX-mode sub-slots of the general-coverage band */
    struct vfo_rec vfo_a;                        /* +0x2DF 0x09D09 [fact] VFO-A working record */
    struct vfo_rec vfo_b;                        /* +0x339 0x09D63 [fact] VFO-B working record */
    enum vfo_side active_vfo;                    /* +0x393 0x09DBD [fact] active VFO, 0 = A, 1 = B (vfo_rec_ptr) */
    enum vfo_state vfo_state_a;                  /* +0x394 0x09DBE [fact] VFO-A state: 1 VFO, 2 memory, 3 memory tune, 4 PMS, 5 QMB, 7/8 locked (radio-control.md) */
    enum vfo_state vfo_state_b;                  /* +0x395 0x09DBF [fact] VFO-B state, same values */
    uint8_t nb_level;                            /* +0x396 0x09DC0 [fact] NB level 0..10 (NL, sdr_upd_r1a_nb_level) */
    uint8_t play_volume;                         /* +0x397 0x09DC1 [fact] PlayList volume 0..100 (FUN_fffc6595, frame 0x3A) */
    uint8_t level_9dc2;                          /* +0x398 0x09DC2 [fact] a second level in frame 0x39, TX gain in state 14 (dsp_set_tx_gain); not traced */
    enum band_idx band_a;                        /* +0x399 0x09DC3 [fact] current band index VFO-A (band_select_stack) */
    enum band_idx band_b;                        /* +0x39A 0x09DC4 [fact] current band index VFO-B */
    uint8_t auto_power_on;                       /* +0x39B 0x09DC5 [fact] 1 = come back on after the reset (power_down_save, cat_PS) */
    uint8_t preset_on;                           /* +0x39C 0x09DC6 [fact] use the preset copy at UI +0x48 instead of the menu values (dsp_set_agc, sci3_set_baud) */
    enum vfo_state split_saved_vfo_state_a;      /* +0x39D 0x09DC7 [fact] VFO state saved by split_toggle */
    enum vfo_state split_saved_vfo_state_b;      /* +0x39E 0x09DC8 [fact] VFO state saved by split_toggle */
    uint8_t func_knob;                           /* +0x39F 0x09DC9 [fact] FUNC-knob function (SF P1=0, copied to 0x9C08) */
    struct vfo_rec memtune_a;                    /* +0x3A4 0x09DCE [fact] memory-tune backup of VFO-A (cat_MR, memtune_backup) */
    struct vfo_rec memtune_b;                    /* +0x3FE 0x09E28 [fact] memory-tune backup of VFO-B (memtune_backup_b 0xFFFC1913) */
    uint8_t scope_cursor_start_be[4];            /* +0x458 0x09E82 [fact] copy of the CURSOR scope start, u32 big-endian (trx_init) */
};


/* ------------------------------------------------------------------------------------------------ typed globals */

/* the UI / radio state block and the eleven .data pointer constants that hold its address (after _INITSCT copies
   .data from ROM 0xFFF8EADC; memory-maps.md "Global state block 0x20B04") [fact] */
struct ui_state g_ui;                       /* @0x00020B04 [fact] UI / radio state block */
struct ui_state *PTR_DAT_00025d38;          /* @0x00025D38 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d4c;          /* @0x00025D4C [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d54;          /* @0x00025D54 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d58;          /* @0x00025D58 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d5c;          /* @0x00025D5C [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d60;          /* @0x00025D60 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d6c;          /* @0x00025D6C [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d70;          /* @0x00025D70 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d74;          /* @0x00025D74 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d78;          /* @0x00025D78 [fact] = 0x20B04 */
struct ui_state *PTR_DAT_00025d7c;          /* @0x00025D7C [fact] = 0x20B04 */

/* CAT flags just below the EEPROM mirror (cat.md "Data structures and globals") */
uint8_t cat_error;                          /* @0x0000464A [fact] CAT error: the parser replaces the reply with ?; (cat_reply_error 0xFFFB0166) */
uint8_t cat_spn_save_pending;               /* @0x0000464B [fact] set by SPNS; cat_parse runs FUN_fffbff93 when timer 0x32 expires */
uint8_t cat_port;                           /* @0x0000464C [fact] port id 1..3 of the command being handled */
uint8_t rf_gain_alt;                        /* @0x0000464D [inference] RG level used instead of UI +0xA3 while 0x9AB6 != 0 (cat_RG) */

/* EEPROM mirror: RAM = 0x464F + EEPROM address (eeprom.md) */
struct ee_hdr g_ee_hdr;                     /* @0x0000464F [fact] EEPROM 0x0000 */
struct cfg105 g_cfg105;                     /* @0x00004659 [fact] EEPROM 0x000A, CAT SPN / alignment mode */
struct cfg105 *PTR_DAT_00025d50;            /* @0x00025D50 [fact] = 0x4659 */
uint8_t dest_code[3];                       /* @0x0000475E [fact] destination / version code, EEPROM 0x010F (cat_ext_JP) */
struct vfo_rec bandstack_a[3][12];          /* @0x00004761 [fact] band stack VFO-A: 3 levels x 12 bands (eeprom_save_bandstack) */
struct vfo_rec bandstack_b[3][12];          /* @0x00005409 [fact] band stack VFO-B */
uint8_t bandstack_level_a[12];              /* @0x000060B1 [fact] current band-stack level per band, VFO-A */
uint8_t bandstack_level_b[12];              /* @0x000060BD [fact] current band-stack level per band, VFO-B */
struct mem_hdr g_mem_hdr;                   /* @0x000060C9 [fact] memory header, start of the E8/E9 image */
struct vfo_rec memch[133];                  /* @0x00006150 [fact] memory channels 001-099, P1L-P9U, 501-515, EMG (radio-control.md) */
struct qmb_hdr g_qmb_hdr;                   /* @0x00009012 [inference] QMB header */
struct vfo_rec qmb[10];                     /* @0x00009023 [fact] QMB records (eeprom_save_qmb_slot) */
struct opstate g_opstate;                   /* @0x00009A2A [fact] operating state, EEPROM 0x53DB, saved at power-off (eeprom_save_opstate) */

/* return types */
struct vfo_rec *vfo_rec_ptr(uint8_t which); /* @0xFFFB324C return [fact] returns 0x9D09 or 0x9D63 (signatures_main.tsv) */
