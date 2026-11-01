/* RAM variables of the MAIN image that the recreated source uses (T24). Each one is placed at its original address
 * by src/main/data_symbols.tsv (linker symbols), so the recreated functions read and write the image's own state.
 * The names of the driver variables are the Renesas Code Generator's (gp_sciN_tx_address, g_sciN_tx_count, ...)
 * [inference: the r_cg_sci function names and the layout, count / pointer per direction]. */
#ifndef MAIN_RAM_H
#define MAIN_RAM_H

#include <stdint.h>

/* SCI driver state, docs/code/main/sci.md "Per-channel callbacks and hooks" [fact: the addresses in
 * R_SCIn_Serial_Send / _Receive and the ISRs] */
#define SCI_STATE(n)                                                                                                  \
    extern uint16_t g_sci##n##_tx_count;       /* bytes left to send */                                              \
    extern uint8_t *gp_sci##n##_tx_address;    /* next byte to send */                                               \
    extern uint16_t g_sci##n##_rx_count;       /* bytes received */                                                  \
    extern uint16_t g_sci##n##_rx_length;      /* bytes to receive */                                                \
    extern uint8_t *gp_sci##n##_rx_address;    /* where the next byte goes */
SCI_STATE(0)
SCI_STATE(1)
SCI_STATE(2)
SCI_STATE(3)
SCI_STATE(4)
SCI_STATE(5)
#undef SCI_STATE

/* C library heap (docs/code/main/bsp.md "Data structures and globals") */
extern uint8_t *heap_break;               /* sbrk's current end of the heap */

/* Settings store (docs/code/main/eeprom.md "EEPROM address map") [fact: 0x464F + the EEPROM address is the buffer
 * of every eeprom_read/eeprom_write call] */
extern uint8_t ee_mirror[0x5837];         /* RAM copy of EEPROM 0x0000..0x5836 */
extern uint8_t ui_defaults_loaded;        /* 1 after eeprom_load_all fell back to defaults (UI +0x41) */
/* ROM defaults (settings_defaults) */
extern const uint8_t cfg105_defaults[0x105];
extern const uint8_t dest_defaults[3];
extern const uint8_t bandmem_defaults[0xA0];
extern const uint8_t scope_defaults[0x28];
extern const uint8_t vfo_state_defaults[0x10];
extern const uint8_t zero_9c17_defaults[30];

/* DSP link (docs/code/main/dsp-link.md) [fact: dsp_send_frame 0xFFFA0B4C, the setters] */
extern uint16_t dsp_shadow[];             /* last value of each register the DSP confirmed, by slot */
extern uint16_t dsp_tx_reg;               /* register of the next frame */
extern uint16_t dsp_tx_data;              /* value of the next write */
extern uint8_t dsp_tx_frame[];            /* the frame being sent */
extern uint8_t dsp_busy_write;            /* a write waits for its ACK */
extern uint8_t dsp_busy_read;             /* a read waits for its reply */
extern uint8_t menu_affft_att;            /* AF-FFT attenuator (0x9C39, opstate) */
extern uint8_t menu_cw_pitch;             /* KEY PITCH menu index (0x9C04, opstate) */

/* SDR link (docs/code/main/sdr-link.md) [fact: sdr_send_frame 0xFFFA30F9, sdr_send_cmd 0xFFFB1B2B, the updaters] */
extern uint16_t sdr_shadow[];
extern uint16_t sdr_tx_reg;
extern uint16_t sdr_tx_data;
extern uint8_t sdr_tx_frame[];
extern uint8_t sdr_busy_write;
extern uint8_t sdr_bridge_req;            /* 0x1C8D: run sdr_bridge_mode */
extern uint8_t sdr_last_tx;               /* 0x1B3DD */
extern uint8_t sdr_synced;                /* 0x1B3DC */
extern uint8_t rf_ctrl_ready;             /* 0x12042: 1 after rf_ctrl_task's first pass */
extern uint8_t sdr_busy_read;
extern uint8_t sdr_rx_frame[];            /* reply buffer, 7 bytes */
extern uint8_t sdr_rx_done;               /* 1 = a reply is in */
extern uint8_t menu_cw_wave_shape;        /* 0x9AA1 */
extern uint8_t menu_nb_rejection;         /* 0x9AD2 */
extern uint8_t menu_scope_rbw;            /* 0x9B14 */

/* CAT (docs/code/main/cat.md) [fact: the functions of app/cat_link.c] */
extern uint8_t cat_ring_in;               /* ring head (cat_rx_complete) */
extern uint8_t cat_ring_out;              /* ring tail (cat_task) */
extern uint8_t cat_ring[];                /* 60 slots of 0x6A bytes */
extern uint8_t cat_e_slot[];              /* E1/E9 frame slot */
extern uint8_t cat_tx_busy_sci0;
extern uint8_t cat_tx_busy_sci2;
extern uint8_t cat_tx_busy_sci3;
extern uint8_t cat_reply[];               /* the reply being built */
extern uint16_t cat_reply_len;
extern uint8_t cat_error;                 /* 1 = answer "?;" */
extern uint8_t cat_sq_level;              /* SQ 0..255 while RF/SQL VR is 0 (cat_SQ) */
extern uint8_t cat_ai_held;               /* AI hold-off after a set (timer 0x32) */

/* DISPLAY link (docs/code/main/display-link.md) [fact: the functions of app/display_link.c] */
extern uint8_t displink_rx_flag;          /* 1 = a frame is in */
extern uint8_t displink_rx_frame[];       /* receive buffer, 0x204 bytes */
extern uint8_t displink_tx_frame[];       /* the frame sent last (kept for a resend) */
extern uint16_t displink_tx_len;
extern uint8_t displink_tx_sent;          /* something was sent this pass */
extern uint8_t displink_tx_pending;       /* a frame waits for its ACK */
extern uint8_t displink_tx_acked;
extern uint8_t displink_hello_sent;
extern uint8_t displink_stage[];          /* staging buffer of most frames */
extern uint8_t displink_stage_status[];   /* staging buffer of frame 0x20 */
extern uint8_t *g_ui_ptr;                 /* pointer to the UI state (0x20B04) */
extern uint8_t *g_ui_ptr2;                /* 0x25D70: the same, used by dispreq_e7_task */
extern uint8_t *g_ui_ptr3;                /* 0x25D7C: the same, used by scan_task */
extern uint8_t scan_state, scan_busy_wait, scan_resume_wait;   /* 0x18877, 0x18873, 0x18874 */
extern uint8_t displink_ack_req, displink_nak_req, displink_gap, displink_ack_wait, displink_ack_wait_start;
extern uint8_t displink_rx_copy[];        /* 0x198F: the frame being dispatched */
struct vfo_rec;
extern struct vfo_rec *dlstat_rec;        /* 0x20874: the active VFO record of the status block */
extern uint16_t dlstat_pos_a, dlstat_pos_b, dlstat_pos_state_a, dlstat_pos_state_b;
extern uint8_t *dlstat_swap_a, *dlstat_swap_b;
extern uint8_t dlstat_freq5[5];           /* 0x19C5 */
extern uint8_t dl60_ver_tmp[6];           /* 0x19BF: a version string being packed (displink_build_60) */
extern uint16_t dl41_pos;                 /* 0x1B632: write offset in frame 0x41 */
extern uint8_t *dl41_used_ptr;            /* 0x20880 */
extern struct vfo_rec *dl41_rec;          /* 0x20884 */
extern const uint8_t dl41_header[15], dl41_group_names[][4], dl41_mode_names[][8];

/* keyer and tuner [fact: app/keyer.c, app/tuner.c] */
extern uint8_t g_ui_keyer_state;          /* UI +0x2B */
extern uint8_t keyer_type;                /* 0x1215F: 0 = KEYER off, else EX020201 KEYER TYPE */
extern uint8_t int_tuner_step;            /* 0x1B3AC: internal-tuner step (tuner_int_task) */
extern uint8_t ext_tuner_step;            /* 0x1B3C8: external-tuner step (tuner_ext_task) */
extern uint8_t tuner_result_hold;         /* 0x1B3C3: 1 while the tune result is shown (tuner_result_set) */
extern uint8_t keyer_elem_buf[];          /* 0x120BC, 0xA0 bytes: the element bits */
extern uint8_t keyer_flags[5];            /* 0x12160..0x12164 */
extern uint8_t keyer_sidetone_on;         /* 0x1215E */
extern uint8_t keyer_speed_cur;           /* 0x1B4D5: the key speed in use */
extern uint32_t keyer_dot_time;           /* 0x21014: 1200000 / speed */
extern uint32_t keyer_dash_time;          /* 0x21010: (weight + 25) x dot / 10 */
extern uint8_t keyer_qsk_ticks;           /* 0x1215C */
extern uint8_t tx_keying_kind;            /* 0x1215D: 1 CW, 2 LSB/USB (tx_cw_keying_class) */
extern uint8_t keyer_has_number;          /* 0x12165 */
extern uint8_t keyer_breakin_saved;       /* 0x12166 */
extern uint8_t *keyer_rec_vfob;           /* 0x21040 */
extern uint16_t keyer_elem_wr;            /* 0x1FA38 */
extern uint16_t keyer_elem_rd;            /* 0x1FA3A */
extern uint16_t keyer_elem_end;           /* 0x1FA3C */
/* message memory (eeprom.md "Message memory"): recorded elements and keyer texts, slots 1..5 */
struct keyer_msg {
    uint8_t len_be[2];                    /* element count, big-endian */
    uint8_t elems[150];
};
struct keyer_text {
    uint8_t len;
    uint8_t text[50];
};
_Static_assert(sizeof(struct keyer_msg) == 0x98 && sizeof(struct keyer_text) == 0x33, "message slot sizes");
extern struct keyer_msg keyer_msg_mem[5];      /* 0x93A7 */
extern struct keyer_text keyer_text_mem[5];    /* 0x969F */
extern const uint8_t morse_table[][2];         /* 0xFFF815C3: {element count, elements from bit 7, 1 = dash} */
extern uint8_t em_text_mem[5][50];             /* 0x979E: the EM text slots, each ended by 0xFE */
extern uint8_t menu_tuner_select;         /* 0x9AB8 */
extern uint8_t atu_ac;                    /* 0x1B3AD */
extern uint8_t atu_tc;                    /* 0x1B3AF */

/* TX/RX sequencer (docs/code/main/tx-protection.md) */
extern uint8_t pc_keying_active;          /* 0x12050: PC keying of a CW mode (ptt_source_select) */
extern uint8_t pc_key_last;               /* 0x12051: last P14 level seen by trx_sequencer in TX */
extern uint32_t spk_route;                /* 0x20FCC: speaker route 0..4 (speaker_route); a 32-bit word: every access is MOV.L */
extern uint8_t ptt_source;                /* 0x1204D: what keyed TX [fact: ptt_source_get 0xFFFB6EC7] */

/* beeps and tones (app/beep.c, round 5) [fact: the addresses in beep_task / beep_request / tone_set] */
extern uint8_t beep_state;                /* 0x12040: idle, start, playing, stop */
extern uint8_t beep_pattern;              /* 0x12041: the requested pattern */
extern uint8_t beep_step;                 /* 0x1B3E2: the pattern's next step */
extern uint8_t beep_last_pattern;         /* 0x1B3E3: the pattern of the last pass (the RTTY tones hold) */
extern float beep_cw_freq;                /* 0x25D40: the CW pitch tone playing, Hz */
extern uint16_t tone_table[36];           /* 0x1FF1C: one cycle of DA0 samples (tone_play, tone_idle) */

/* meters and squelch (app/meters.c, round 5) [fact: the addresses in meter_vdd .. signal_level_squelch] */
extern float vdd_scale;                   /* 0x20FC0: supply meter scale (vdd_scale_calc) */
extern float swr_value;                   /* 0x20FC4: the SWR of the last pass */
extern uint8_t meter_vdd_val;             /* 0x12043 */
extern uint8_t meter_swr_val;             /* 0x12046 */
extern uint8_t meter_swr_pos;             /* 0x12047 */
extern uint8_t meter_po_val;              /* 0x12048 */
extern uint8_t meter_comp_val;            /* 0x12049 */
extern uint8_t meter_s_val;               /* 0x1204A */
extern uint8_t swr_good_count;            /* 0x1B4C6 */
extern uint8_t swr_bad_count;             /* 0x1B4C7 */
extern uint8_t fm_sql_last_mode;          /* 0x1B4CB */

#endif
