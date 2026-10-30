/* FT-710 MAIN V01-12 enums (T23f). Applied by tools/ghidra/ApplyEnums.java (category /FT710) to the parameters, returns
 * and globals listed in tools/ghidra/enum_uses_main.tsv, after ApplySignatures.java. The struct fields that hold these
 * values (opstate.active_vfo, vfo_state_a/b, band_a/b, ...) name them as `enum NAME` in structs_main.h, which
 * ApplyStructs.java resolves under /FT710, so ApplyEnums.java runs first.
 *
 * Format (read by ApplyEnums.java, and plain C otherwise): each enum is preceded by a comment holding "@size N" (the
 * storage size in bytes; C gives no way to say it) and its evidence. Every value carries its own evidence comment, which
 * ApplyEnums.java stores as the value's comment in Ghidra. Values are decimal or 0x hex. Evidence tags follow AGENTS.md:
 * [fact] = seen in code/data (address given), [inference] = from behaviour.
 * Only values the code produces or tests are listed; an enum with gaps would make Ghidra print an unnamed value as an OR
 * of named ones, so the never-produced values of vfo_state get a name that says so.
 */
#ifndef FT710_ENUMS_MAIN_H
#define FT710_ENUMS_MAIN_H

/* @size 1
 * Operating mode: the low nibble of operating-record byte +0x00 (0x9D09 VFO-A, 0x9D63 VFO-B), returned by vfo_mode
 * (0xFFFB3196, "& 0xf") and mapped to the CAT MD/IF/OI/MR code by cat_mode_codes 0xFFF806D0 = "12735D4B8CAF69EF"
 * [fact: docs/code/main/radio-control.md "Mode index", tools/eeprom_decode.py MODES]. The pairs 0/1, 2/3, 4/5, 6/7,
 * 8/9, 10/11, 12/13 share their per-mode block (radio-control.md) [fact]. */
enum radio_mode {
    MODE_LSB       = 0,   /* CAT '1' [fact: 0xFFF806D0[0]] */
    MODE_USB       = 1,   /* CAT '2' [fact: 0xFFF806D0[1]] */
    MODE_CW_L      = 2,   /* CAT '7'; vfo_mode forces 2 during a tuner cycle / tune carrier [fact: 0xFFFB3196] */
    MODE_CW_U      = 3,   /* CAT '3' [fact: 0xFFF806D0[3]] */
    MODE_AM        = 4,   /* CAT '5' [fact: 0xFFF806D0[4]] */
    MODE_AM_N      = 5,   /* CAT 'D' [fact: 0xFFF806D0[5]] */
    MODE_FM        = 6,   /* CAT '4' [fact: 0xFFF806D0[6]] */
    MODE_FM_N      = 7,   /* CAT 'B'; dsp_fm_noise doubles in 7/11 [fact: 0xFFF806D0[7], 0xFFF9D800] */
    MODE_DATA_L    = 8,   /* CAT '8' [fact: 0xFFF806D0[8]] */
    MODE_DATA_U    = 9,   /* CAT 'C' [fact: 0xFFF806D0[9]] */
    MODE_DATA_FM   = 10,  /* CAT 'A' [fact: 0xFFF806D0[10]] */
    MODE_DATA_FM_N = 11,  /* CAT 'F' [fact: 0xFFF806D0[11]] */
    MODE_RTTY_L    = 12,  /* CAT '6' [fact: 0xFFF806D0[12]] */
    MODE_RTTY_U    = 13,  /* CAT '9' [fact: 0xFFF806D0[13]] */
    MODE_PSK       = 14,  /* CAT 'E' [fact: 0xFFF806D0[14]] */
    MODE_15        = 15,  /* table entry 'F' (as DATA-FM-N); MD set only searches 0..14, FUN_fffc4bd5 has a case 15 [fact: 0xFFF806D0[15], 0xFFFC4BD5] */
    MODE_NONE      = 0xFF /* "no match" while cat_MD looks the mode letter up in cat_mode_codes [fact: cat_MD 0xFFFAB7D1] */
};

/* @size 1
 * Band index: band_of_freq 0xFFFB33E5 returns the row of band_table 0xFFF8876C (12 rows of lo/hi Hz), 0xFF if none;
 * current band of A/B at 0x9DC3/0x9DC4 (opstate.band_a/band_b, typed in structs_main.h); band_select also copies it
 * (<= 11) to the pop-up cursor 0x20F28, which holds a mode or other values for other pop-ups and is not typed; band-stack rows 0..11
 * [fact: docs/code/main/radio-control.md, tools/eeprom_decode.py BANDS/BAND_LIMITS]. */
enum band_idx {
    BAND_1_8MHZ = 0,     /* 1.800-2.000 MHz [fact: 0xFFF8876C row 0] */
    BAND_3_5MHZ = 1,     /* 3.500-4.000 MHz [fact: row 1] */
    BAND_5MHZ   = 2,     /* 5.000-5.500 MHz (60 m) [fact: row 2] */
    BAND_7MHZ   = 3,     /* 7.000-7.500 MHz [fact: row 3] */
    BAND_10MHZ  = 4,     /* 10.000-10.500 MHz [fact: row 4] */
    BAND_14MHZ  = 5,     /* 14.000-14.500 MHz [fact: row 5] */
    BAND_18MHZ  = 6,     /* 18.000-18.500 MHz [fact: row 6] */
    BAND_21MHZ  = 7,     /* 21.000-21.500 MHz [fact: row 7] */
    BAND_24MHZ  = 8,     /* 24.500-25.000 MHz [fact: row 8] */
    BAND_28MHZ  = 9,     /* 28.000-30.000 MHz [fact: row 9] */
    BAND_50MHZ  = 10,    /* 50.000-54.000 MHz [fact: row 10] */
    BAND_GEN    = 11,    /* general coverage 0.030-75 MHz; band_select clamps the pop-up cursor 0x20F28 to 11 [fact: row 11, 0xFFFC1663] */
    BAND_COUNT  = 12,    /* number of bands: the bound cat_BS/cat_BD/cat_BU check against (BS P1 00..11) [fact: decomp, docs/cat-commands-primary.md BS] */
    BAND_NONE   = 0xFF   /* band_of_freq: no row matches [fact: 0xFFFB33E5] */
};

/* @size 1
 * Which VFO of the operating pair: argument of vfo_rec_ptr 0xFFFB324C / vfo_mode 0xFFFB3196 / vfo_freq 0xFFFB357C.
 * 0 = the active VFO (0x9DBD), anything else = the TX VFO, which is the other VFO while split 0x9C5E is on
 * [fact: 0xFFFB3196 "if (which != 0) split = 0x9C5E"; names: inference]. */
enum vfo_which {
    VFO_RX = 0,   /* active VFO (0x9DBD) [fact: 0xFFFB324C] */
    VFO_TX = 1    /* TX VFO: the other VFO while split 0x9C5E = 1, else the active one [fact: 0xFFFB324C, 0xFFFB3196] */
};

/* @size 1
 * VFO side A/B: the active VFO 0x9DBD (0 = A, 1 = B), the side argument of vfo_freq 0xFFFB357C, vfo_tune_locked
 * 0xFFFB4BBA, vfo_is_memory 0xFFFC2D93, band_select_on 0xFFFC4C4E and the band_select_* helpers
 * [fact: docs/code/main/radio-control.md "State per VFO"]. */
enum vfo_side {
    VFO_A        = 0,  /* VFO-A, record 0x9D09, state 0x9DBE [fact: 0xFFFB357C, 0xFFFC2D93] */
    VFO_B        = 1,  /* VFO-B, record 0x9D63, state 0x9DBF [fact: 0xFFFB357C, 0xFFFC2D93] */
    VFO_SIDE_SEL = 2   /* vfo_freq: the record of vfo_rec_ptr(which); vfo_tune_locked: the active side 0x9DBD [fact: 0xFFFB357C, 0xFFFB4BBA] */
};

/* @size 1
 * VFO/memory state of a side: 0x9DBE (A) / 0x9DBF (B), saved at split entry in 0x9DC7/0x9DC8
 * [fact: docs/code/main/radio-control.md "VFO and memory states", docs/cat-commands-primary.md IF/OI P7 (#173)].
 * cat_vfo_state_codes 0xFFF806DF maps it to the IF/OI/MR P7 digit. */
enum vfo_state {
    VFO_STATE_UNUSED_0 = 0,  /* never written by V01-12; P7 'F' [fact: #173, 0xFFF806DF[0]] */
    VFO_STATE_VFO      = 1,  /* VFO (band-stack record); P7 '0' [fact: 0xFFF806DF[1], vfo_enter_vfo_state 0xFFFC3081] */
    VFO_STATE_MEMORY   = 2,  /* memory channel; P7 '1' [fact: 0xFFF806DF[2], vfo_enter_mem_state 0xFFFC28FB, cat_MC] */
    VFO_STATE_MEMTUNE  = 3,  /* memory tune; P7 '2' [fact: 0xFFF806DF[3], vfo_mem_to_memtune 0xFFFC5CE0] */
    VFO_STATE_PMS      = 4,  /* PMS (tune inside a P-pair); P7 '5'; freq_clamp uses the PMS limits [fact: 0xFFF806DF[4], 0xFFFC5CE0, #173] */
    VFO_STATE_QMB      = 5,  /* QMB recall; P7 '3'; qmb_boot_init re-checks 5 [fact: 0xFFF806DF[5], 0xFFF94CAB] */
    VFO_STATE_UNUSED_6 = 6,  /* never written by V01-12; P7 'F' [fact: #173, 0xFFF806DF[6]] */
    VFO_STATE_LOCKED_7 = 7,  /* memory, no tuning (vfo_tune_locked, vfo_is_memory); never written by V01-12; P7 '1' [fact: 0xFFFB4BBA, 0xFFFC2D93, #173] */
    VFO_STATE_LOCKED_8 = 8,  /* as 7 [fact: 0xFFFB4BBA, 0xFFFC2D93, #173] */
    VFO_STATE_UNUSED_9 = 9   /* never written by V01-12; P7 'F' [fact: #173, 0xFFF806DF[9]] */
};

/* @size 1
 * CAT command index: position of the 2-letter mnemonic in cat_mnemonics 0xFFF805EC (104 entries), which cat_parse
 * passes to cat_dispatch 0xFFFA3B6E as the switch value [fact: decomp/main/cat_dispatch.tsv "primary"]. Every value is
 * the mnemonic at that index [fact: 0xFFF805EC]. */
enum cat_cmd {
    CAT_AB = 0, CAT_AC = 1, CAT_AG = 2, CAT_AI = 3, CAT_AM = 4, CAT_AO = 5, CAT_AS = 6, CAT_AV = 7,
    CAT_BA = 8, CAT_BC = 9, CAT_BD = 10, CAT_BI = 11, CAT_BM = 12, CAT_BP = 13, CAT_BS = 14, CAT_BU = 15,
    CAT_BY = 16, CAT_CF = 17, CAT_CH = 18, CAT_CN = 19, CAT_CO = 20, CAT_CS = 21, CAT_CT = 22, CAT_DA = 23,
    CAT_DN = 24, CAT_DT = 25, CAT_ED = 26, CAT_EK = 27, CAT_EM = 28, CAT_EN = 29, CAT_EU = 30, CAT_EX = 31,
    CAT_FA = 32, CAT_FB = 33, CAT_FN = 34, CAT_FS = 35, CAT_FT = 36, CAT_GT = 37, CAT_GP = 38, CAT_ID = 39,
    CAT_IF = 40, CAT_IS = 41, CAT_KM = 42, CAT_KP = 43, CAT_KR = 44, CAT_KS = 45, CAT_KY = 46, CAT_LK = 47,
    CAT_LM = 48, CAT_MA = 49, CAT_MB = 50, CAT_MC = 51, CAT_MD = 52, CAT_MG = 53, CAT_ML = 54, CAT_MR = 55,
    CAT_MS = 56, CAT_MT = 57, CAT_MW = 58, CAT_MX = 59, CAT_NA = 60, CAT_NB = 61, CAT_NL = 62, CAT_NR = 63,
    CAT_OI = 64, CAT_OS = 65, CAT_PA = 66, CAT_PB = 67, CAT_PC = 68, CAT_PL = 69, CAT_PR = 70, CAT_PS = 71,
    CAT_QI = 72, CAT_QR = 73, CAT_QS = 74, CAT_RA = 75, CAT_RC = 76, CAT_RD = 77, CAT_RG = 78, CAT_RI = 79,
    CAT_RL = 80, CAT_RM = 81, CAT_RS = 82, CAT_RT = 83, CAT_RU = 84, CAT_SC = 85, CAT_SD = 86, CAT_SF = 87,
    CAT_SH = 88, CAT_SM = 89, CAT_SQ = 90, CAT_SS = 91, CAT_ST = 92, CAT_SV = 93, CAT_TS = 94, CAT_TX = 95,
    CAT_UP = 96, CAT_VD = 97, CAT_VG = 98, CAT_VM = 99, CAT_VS = 100, CAT_VX = 101, CAT_XT = 102, CAT_ZI = 103,
    CAT_COUNT = 104,  /* number of primary mnemonics: cat_parse's lookup loop bound [fact: 0xFFF805EC, cat_parse 0xFFFA347C] */
    CAT_NONE = 0xFF   /* "not found" index in cat_parse (then the extended table is tried) [fact: cat_parse 0xFFFA347C] */
};

/* @size 1
 * Extended CAT command index: position in cat_ext_mnemonics 0xFFF806BC (10 entries), tried when the primary lookup
 * fails and passed to cat_dispatch_ext 0xFFFA3A2A [fact: decomp/main/cat_dispatch.tsv "secondary"]. */
enum cat_ext_cmd {
    CATX_SP = 0,  /* special-cased by cat_ext_SP 0xFFFA36F2 [fact] */
    CATX_EO = 1,  /* cat_ext_EO [fact] */
    CATX_E8 = 2,  /* cat_ext_E8 [fact] */
    CATX_E9 = 3,  /* cat_ext_E9, second input path only [fact] */
    CATX_FD = 4,  /* cat_ext_FD [fact] */
    CATX_KT = 5,  /* no case in cat_dispatch_ext [fact] */
    CATX_PE = 6,  /* cat_ext_PE [fact] */
    CATX_ZZ = 7,  /* cat_ext_ZZ [fact] */
    CATX_VE = 8,  /* cat_ext_VE [fact] */
    CATX_JP = 9   /* cat_ext_JP [fact] */
};

/* @size 2
 * SDR register 0x0A, the modulation class of the active side, written by sdr_upd_r0a_demod 0xFFFA1738; shadow 0x1B742
 * [fact for the values: 0xFFFA1738; meaning inference: docs/code/main/sdr-link.md]. */
enum sdr_mod_class {
    SDR_MOD_CW   = 0,  /* modes 2/3, or CW keying in an SSB/DATA mode (FUN_fffba192() == 3) [fact: 0xFFFA1738] */
    SDR_MOD_AM   = 1,  /* modes 4/5 [fact: 0xFFFA1738] */
    SDR_MOD_FM   = 2,  /* modes 6/7/10/11 [fact: 0xFFFA1738] */
    SDR_MOD_LSB  = 3,  /* modes 0/8 [fact: 0xFFFA1738] */
    SDR_MOD_USB  = 4,  /* modes 1/9/14 [fact: 0xFFFA1738] */
    SDR_MOD_RTTY = 5   /* modes 12/13 (the default) [fact: 0xFFFA1738] */
};

/* @size 2
 * DSP (RT685) register 6, demodulator / sideband select, written by dsp_set_demod 0xFFF9D9A7 from vfo_mode(0); shadow
 * 0x1B63E [fact for the values: 0xFFF9D9A7; meaning inference: docs/code/main/dsp-link.md]. */
enum dsp_demod {
    DSP_DEMOD_CW_U = 0,  /* mode 3 and the default [fact: 0xFFF9D9A7] */
    DSP_DEMOD_CW_L = 1,  /* mode 2 [fact: 0xFFF9D9A7] */
    DSP_DEMOD_USB  = 2,  /* modes 1/9/13/14 (upper side) [fact: 0xFFF9D9A7] */
    DSP_DEMOD_LSB  = 3,  /* modes 0/8/12 (lower side) [fact: 0xFFF9D9A7] */
    DSP_DEMOD_AM   = 8,  /* modes 4/5 [fact: 0xFFF9D9A7] */
    DSP_DEMOD_FM   = 9   /* modes 6/7/10/11 [fact: 0xFFF9D9A7] */
};

/* @size 1
 * TUN/LIN PORT SELECT, setting 0x9AB7, returned by tunlin_port_mode 0xFFFB1900 (values > 3 read as 0)
 * [fact: docs/code/main/peripherals.md, CAT manual menu chart]. */
enum tunlin_mode {
    TUNLIN_EXT_TUNER = 0,  /* EXT-TUNER: SCI2 to an external tuner [fact: peripherals.md] */
    TUNLIN_LINEAR    = 1,  /* LINEAR [fact: peripherals.md] */
    TUNLIN_CAT3      = 2,  /* CAT-3: CAT on SCI2 [fact: peripherals.md] */
    TUNLIN_GPO       = 3   /* GPO [fact: peripherals.md] */
};

#endif /* FT710_ENUMS_MAIN_H */
