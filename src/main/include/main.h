/* Recreated MAIN (RX651) source, T24: common types and the functions of the image that the recreated code calls.
 *
 * Names are the Ghidra names of decomp/main/functions.tsv; the prototypes follow tools/ghidra/signatures_main.tsv.
 * A function declared here and not defined in src/main/ is linked to its original address in the image (the
 * equivalence check, tools/equiv_main_emu.py, links every call it does not define to the image). RAM variables
 * are declared in main_ram.h and placed at their original addresses by src/main/data_symbols.tsv. */
#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdint.h>

/* Renesas Code Generator status codes (r_cg_macrodriver.h): the values the drivers return [fact: 0x80/0x81 in
 * R_SCI0_Serial_Send 0xFFF933AE; the names are the Code Generator's, inference from the r_cg_* function names]. */
typedef uint16_t MD_STATUS;
#define MD_OK       0x00u
#define MD_ERROR    0x80u
#define MD_ARGERROR 0x81u

/* CC-RX passes the first four integer arguments in R1..R4 and returns in R1, as GCC's RX ABI does; callers
 * extend char and short arguments (eeprom_read 0xFFFB14BA: movu.w/movu.b before bsr eeprom_spi_tx). */

/* --- CAT link (docs/code/main/cat.md, sci.md) --- */
void cat_rx_complete(int32_t port, uint16_t len);
char *cat_rx_byte_hook(uint16_t *count, uint16_t *length, char *ptr, int32_t timer);
void cat_tx_done_sci0(void);
void cat_tx_done_sci2(void);
void cat_tx_done_sci3(void);
uint8_t tunlin_port_mode(void);
void FUN_fffb1976(void);           /* SCI2 transmit end in tuner mode (sci.md) */
void FUN_fffb1944(void);           /* SCI2 receive end in tuner mode: tuner flag 0xA0A9 (sci.md) */
void sci2_rx_byte_hook(void);      /* SCI2 framing, CAT or tuner (sci.md) */

/* --- other links --- */
void displink_rx_frame_len(void);
void displink_rx_done(void);
void sci4_rx_frame_len(void);
void sci4_rx_set_ready(void);
void sci4_rx_set_len(uint16_t len);
void sdr_rx_done_cb(void);

/* --- soft timers (sci.md "swtimer_start") --- */
void swtimer_start(int32_t id, uint16_t n);
uint8_t swtimer_expired(int32_t id);

/* --- EEPROM driver and settings store (docs/code/main/eeprom.md; drivers/eeprom.c, app/settings.c) --- */
void eeprom_spi_tx(uint8_t b);
uint8_t eeprom_spi_rx(void);
void eeprom_read(uint16_t addr, uint8_t *buf, uint16_t n);
void eeprom_write(uint16_t addr, uint8_t *buf, uint16_t n);
void eeprom_init(void);
void eeprom_load_all(void);
void eeprom_hdr_update(uint8_t state);
void eeprom_save_all(void);
void eeprom_save_opstate(void);
void eeprom_save_bandstack(uint8_t vfo_b, uint8_t band, uint8_t slot, uint8_t *rec);
void eeprom_save_image(void);
void eeprom_save_memch(uint8_t ch);
void eeprom_save_qmb(void);
void eeprom_save_qmb_slot(uint8_t slot);
void eeprom_save_msg(int32_t type, int32_t n);
void eeprom_save_atu_mem(void);
void eeprom_save_cfg105(void);
void eeprom_save_dest(void);
void settings_defaults(uint8_t factory);
void reset_memch(void);
void reset_menu(void);
void eeprom_read_raw(uint16_t addr, uint8_t *buf, uint16_t n);
void eeprom_write_raw(uint16_t addr, uint8_t *buf, uint16_t n);
uint8_t supply_undervolt_check(void);    /* 1 = supply too low, skip the save (eeprom.md) */
void defaults_vfo(void);
void defaults_bandstack(void);
void defaults_qmb(void);
void defaults_memch(void);
void defaults_msg(void);
void menu_defaults_load(void);

/* --- helpers, DSP link (docs/code/main/dsp-link.md; app/dsp_link.c) --- */
void byte2hex(char *out, uint8_t v);               /* two upper-case hex digits */
void word2hex(int32_t out, uint16_t v);            /* four hex digits at address out */
uint8_t vfo_mode(uint8_t which);                   /* mode code of VFO which (radio-control.md) */
uint8_t sci4_rx_ready(void);
uint32_t sci4_rx_buf(void);
void sci4_send(uint32_t buf, uint16_t len);
uint16_t dsp_route_param(uint16_t reg);
uint8_t tx_mod_gain(void);                       /* MIC / USB / REAR gain of the TX audio source */
uint16_t FUN_fffb34e4(uint8_t gain);              /* ROM curve 0xFFF88126[gain] (u16) */
uint16_t FUN_fffb350e(uint8_t level);             /* ROM curve 0xFFF881F0[level] (u16) */
uint8_t FUN_fffb3523(uint8_t af_gain);            /* ROM curve 0xFFF811E2[af_gain] */
uint8_t FUN_fffb3538(uint8_t n);                  /* ROM curve 0xFFF812E2[n] */
uint8_t beep_pattern_get(void);                       /* RAM 0x12041 (a TX state, 4 and 9..11 tested by dsp_set_peq_freq) */
uint32_t aess_level_ptr(void);                    /* address of the active mode's AESS level byte */
uint32_t aess_mode_ptr(void);                     /* address of the active mode's AESS centre byte */
uint8_t dsp_sum8(const uint8_t *p, uint8_t n);
uint8_t dsp_reply_sum_ok(const uint8_t *p, uint8_t n);
uint8_t dsp_check_reply(uint8_t kind, uint8_t **reply);
void dsp_send_frame(uint8_t kind);
void dsp_shadow_store(void);
void dsp_status1_filter(void);
void dsp_status2_filter(void);
void dsp_status3_filter(void);
void dsp_status4_filter(void);
void sdr_shadow_update(void);

/* --- SDR link (docs/code/main/sdr-link.md; app/sdr_link.c) --- */
uint32_t vfo_freq(uint8_t which, uint8_t side);    /* Hz; side 0 = A, 1 = B, 2 = vfo_rec_ptr(which) */
uint8_t *vfo_rec_ptr(uint8_t which);
uint8_t vfo_is_memory(uint8_t side);
uint32_t vfo_freq_clar(uint8_t which, uint8_t side);   /* vfo_freq + the clarifier offset when on */
uint16_t vfo_filter_width_hz(uint8_t *width_be);      /* the selected filter width, also stored big-endian */              /* 1 when the side is in a memory state */
void sdr_link_start(void);
uint8_t sdr_rx_ready(void);
uint32_t sdr_rx_buf(void);
void sdr_send_cmd(uint32_t buf, uint16_t len);
uint8_t sdr_sum8(const uint8_t *p, uint8_t n);
uint8_t sdr_check_hex_sum(const uint8_t *p, uint8_t n);
uint8_t sdr_poll_reply(uint8_t kind, uint8_t **reply);
void sdr_send_frame(uint8_t kind);

/* --- CAT glue (docs/code/main/cat.md; app/cat_link.c) --- */
uint8_t sum8(const uint8_t *p, uint16_t n);
uint8_t cat_checksum_ok(const uint8_t *p, uint16_t n);
uint8_t cat_ring_head(void);
uint8_t cat_ring_tail(void);
void cat_ring_unpop(void);
uint8_t *cat_ring_pop(void);
uint8_t *cat_e9_slot(void);
void cat_send_reply(int32_t port, uint8_t *buf, uint16_t len);
uint8_t cat_tx_busy(int32_t port);
void cat_reply_error(void);
void qmb_store(void);
void qmb_recall(void);
void cat_parse(void);
void cat_dispatch(const uint8_t *slot, uint8_t idx, uint16_t len);
void cat_dispatch_ext(const uint8_t *slot, uint8_t idx, uint16_t len);
void cat_ai_poll(void);                 /* AI broadcaster (cat-ai.md) */
uint8_t sci_tx_end(int32_t port);       /* 1 when the port's last transmission has ended (sci.md) */
void screensaver_timer_restart(void);
void toupper_inplace(char *c);
char hex2nib(uint8_t c);                /* '0'..'9', 'A'..'F', 'a'..'f' -> 0..15, else 0xFF */
void key_dsp_press(void);
/* used by the CAT handlers (app/cat_handlers.c) */
char nib2hex(uint8_t n);                /* "0123456789ABCDEF"[n & 15] */
uint8_t key_event_filter(uint16_t key, uint8_t kind);   /* 0 = the key (and its CAT command) is locked now */
int32_t vfo_mode_is_cw(void);
void vfo_mark_edited(uint8_t side);
void vfo_store_back(uint8_t side);
void key_mox_vox_press(void);
void key_mox_vox_short(void);
void key_mox_vox_long(void);
void key_zin_spot_short(void);
void power_on_request(void);
int32_t FUN_fffe5d0e(void);             /* 0 while the scan runs upward (cat_SC) */
uint8_t scan_allowed(void);
void scan_start_up(void);
void scan_start_down(void);
void scan_stop(void);
uint8_t meter_get_s(void);
void split_toggle(void);
uint8_t ptt_source_get(void);
uint16_t popup_duration_get(uint8_t code);
void popup_open_timed(uint16_t time);
uint8_t ex_command(char *text, uint8_t set, uint16_t len, uint8_t *reply, uint16_t *reply_len);
void cat_ai_holdoff(void);
int32_t keyer_mode_class(uint8_t *rec);
void beep_request(int32_t kind);
uint8_t gpo_a_get(void);
uint8_t gpo_b_get(void);
uint8_t gpo_c_get(void);
uint8_t gpo_d_get(void);
void gpo_a_set(uint8_t on);
void gpo_b_set(uint8_t on);
void gpo_c_set(uint8_t on);
void gpo_d_set(uint8_t on);
void mic_up_key_press(void);
void mic_down_key_press(void);
uint8_t vfo_tune_locked(uint8_t side);
void FUN_fffbe232(void);                /* ui_softkey_dispatch(0xFF), run by cat_parse while a pop-up is shown [fact: 0xFFFBE232] */

/* --- DISPLAY link (docs/code/main/display-link.md; app/display_link.c) --- */
void displink_uart_send(uint8_t *buf, uint16_t len);
void displink_tx_resend(void);
void displink_put_sum(uint8_t *frame, uint16_t len);
void displink_tx_start(uint16_t len);
void mem_zero(uint16_t n, uint8_t *p);
uint8_t displink_copy_if_changed(const uint8_t *src, uint8_t *dst, uint16_t n);
uint16_t displink_build_status(void);    /* the status block; returns its length + 1 (152) */
void displink_copy_status(void);           /* the common status bytes into the frame being built */
void displink_build_20(void);
void displink_build_23(void);
void displink_build_24(void);
void displink_build_37(void);
void displink_build_39(void);
void displink_build_41(void);
void displink_build_50(void);
void displink_build_60(void);
void displink_build_62(void);
void displink_build_70(void);

/* --- TX/RX sequencer (docs/code/main/tx-protection.md; app/trx_lines.c) --- */
void trx_sequencer(void);
void ptt_arbiter(void);
uint8_t qsk_delay_ticks(void);
int32_t tx_breakin_on(void);
uint8_t ckey_det(void);
uint8_t tx_freq_allowed(uint32_t freq);
uint8_t af_mute_get(void);
void af_mute_set(uint8_t on);
uint8_t ear_det(void);
void pc_keying(void);
void send_a_set(uint8_t on);
void send_b_set(uint8_t on);

/* --- keyer and tuner (app/keyer.c, app/tuner.c) --- */
void beep_stop(void);
void keyer_init(void);
void keyer_state_clear(void);
void keyer_sidetone_off(void);
void keyer_paddles_read(uint8_t *p1, uint8_t *p2);   /* the two paddle inputs, 1 = closed */
void keyer_straight_bug(uint8_t type);                /* KEYER TYPE 0/1 */
void keyer_elekey(uint8_t type, uint8_t record);      /* KEYER TYPE 2..5; record = 1 while recording a message */
void keyer_output_step(uint8_t type);
void keyer_elem_put(uint8_t elem);                     /* 0 space, 1 dot, 2 dash unit into keyer_elem_buf */
void keyer_text_msg_encode(uint8_t slot);              /* the elements of another keyer text (slot 0..4) */
uint16_t contest_number_get(void);
void contest_number_set(uint16_t n);
char contest_cut_digit(char c);                        /* EX020204 NUMBER STYLE substitution */
void FUN_fffba9c3(void);                               /* keyer_task state 6, every pass */
void keyer_init(void);
void keyer_state_clear(void);
void keyer_sidetone_off(void);
void keyer_paddles_read(uint8_t *p1, uint8_t *p2);   /* the two paddle inputs, 1 = closed */
void keyer_straight_bug(uint8_t type);                /* KEYER TYPE 0/1 */
void keyer_elekey(uint8_t type, uint8_t record);      /* KEYER TYPE 2..5; record = 1 while recording a message */
void keyer_output_step(uint8_t type);
void keyer_elem_put(uint8_t elem);                     /* 0 space, 1 dot, 2 dash unit into keyer_elem_buf */
void keyer_text_msg_encode(uint8_t slot);              /* the elements of another keyer text (slot 0..4) */
uint16_t contest_number_get(void);
void contest_number_set(uint16_t n);
char contest_cut_digit(char c);                        /* EX020204 NUMBER STYLE substitution */
void FUN_fffba9c3(void);                               /* keyer_task state 6, every pass */
uint8_t tx_cw_keying_class(void);                      /* 0 = the mode does not key CW; sets tx_keying_kind */
void tuner_atas_task(void);
void tuner_ext_task(void);
void tuner_int_task(void);
void tuner_rearm(void);
void tuner_task(void);

#endif
