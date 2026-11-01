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

/* keyer and tuner [fact: app/keyer.c, app/tuner.c] */
extern uint8_t g_ui_keyer_state;          /* UI +0x2B */
extern uint8_t keyer_msg_active;          /* 0x1215F */
extern uint8_t keyer_state[];             /* 0x120BC, 0xA0 bytes */
extern uint8_t keyer_flags[5];            /* 0x12160..0x12164 */
extern uint8_t keyer_sidetone_on;         /* 0x1215E */
extern uint8_t menu_tuner_select;         /* 0x9AB8 */
extern uint8_t atu_ac;                    /* 0x1B3AD */
extern uint8_t atu_tc;                    /* 0x1B3AF */

/* TX/RX sequencer (docs/code/main/tx-protection.md) */
extern uint8_t pc_keying_active;          /* 0x12050: PC keying of a CW mode (ptt_source_select) */
extern uint8_t pc_key_last;               /* 0x12051: last P14 level seen by trx_sequencer in TX */
extern uint8_t spk_route;                 /* 0x20FCC: speaker route 0..4 (speaker_route) */
extern uint8_t ptt_source;                /* 0x1204D: what keyed TX [fact: ptt_source_get 0xFFFB6EC7] */

#endif
