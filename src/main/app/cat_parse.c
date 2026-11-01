/* The CAT command parser and dispatcher of the MAIN image, recreated for T24 (docs/code/main/cat.md,
 * decomp/main/cat_dispatch.tsv).
 *
 * cat_parse runs once per main-loop pass [fact: cat.md "Main-loop parse"]: it takes one command from the receive ring
 * (or the E9 frame from its own slot), looks its two-letter mnemonic up in cat_mnemonics (104 entries) and then in
 * cat_ext_mnemonics (10), and hands it to cat_dispatch / cat_ext_SP / cat_dispatch_ext. These check the command
 * length, which tells a read ("FA;") from a set ("FA014250000;"), echo the first bytes of the command into the reply
 * and call the handler. A handler leaves its reply in cat_reply / cat_reply_len or sets cat_error, which turns the
 * reply into "?;". */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "cat_cmds.h"

/* a ring slot (cat_rx_complete): +0 port id, +2 total length incl. mnemonic and ';' (u16), +4 the command text */
#define SLOT_PORT  0
#define SLOT_LEN   2
#define SLOT_TEXT  4

extern const char cat_mnemonics[CAT_COUNT][2];    /* ROM 0xFFF805EC */
extern const char cat_ext_mnemonics[10][2];    /* ROM 0xFFF806BC */

/* The first n bytes of the command text are the start of the reply ("FA" + ..., "AG0" + ...) [fact: the stores to
 * 0x1C8E in every case of cat_dispatch 0xFFFA3B6E]. */
static inline void cat_reply_echo(const uint8_t *slot, unsigned n)
{
    unsigned i;

    for (i = 0; i < n; i++)
        cat_reply[i] = slot[SLOT_TEXT + i];
}

/* the index of a mnemonic in a table, or CAT_NONE. The image compares with SCMPU over 2 bytes [fact:
 * 0xFFFA351D]; no table entry holds a NUL [fact: ROM 0xFFF805EC..0xFFF806CF], so that is a two-byte compare. */
static uint8_t cat_lookup(const char *mn, const char (*table)[2], uint8_t count)
{
    uint8_t i;

    for (i = 0; i < count; i++)
        if (mn[0] == table[i][0] && mn[1] == table[i][1])
            return i;
    return CAT_NONE;
}

static inline int is_letter(uint8_t c, char upper)
{
    return c == (uint8_t)upper || c == (uint8_t)(upper + ('a' - 'A'));
}

/* cat_parse 0xFFFA347C */
void cat_parse(void)
{
    uint8_t head = cat_ring_head();
    uint8_t tail = cat_ring_tail();
    uint8_t idx = CAT_NONE;
    uint8_t port;
    char mn[2];
    uint8_t i;

    cat_error = 0;
    cat_reply_len = 0;
    if (g_ui.cat_disabled == 1)        /* DISPLAY frame F1 0x03 [fact: structs_main.h] */
        return;

    if (head == tail) {
        /* ring empty: the E9 restore frame, which bypasses the ring (cat_rx_byte_hook) [fact: cat.md] */
        uint8_t *e9 = cat_e9_slot();

        if (e9[0] == 1) {
            port = e9[1];
            mn[0] = (char)e9[4];
            mn[1] = (char)e9[5];
            for (i = 0; i < 2; i++)
                toupper_inplace(&mn[i]);
            idx = cat_lookup(mn, cat_ext_mnemonics, 10u);
            if (idx == CATX_E9)
                cat_ext_E9(e9 + 4);
            if (cat_error != 0)
                cat_reply_error();
            if (cat_reply_len != 0)
                cat_send_reply(port, cat_reply, cat_reply_len);
            e9[0] = 0;
        }
    } else {
        uint8_t *slot;
        uint16_t len;

        screensaver_timer_restart();
        slot = cat_ring_pop();
        port = slot[SLOT_PORT];
        if (sci_tx_end(port) == 0) {
            cat_ring_unpop();          /* the port is still sending the last reply: retry next pass */
            return;
        }
        mn[0] = (char)slot[SLOT_TEXT];
        mn[1] = (char)slot[SLOT_TEXT + 1];
        len = *(const uint16_t *)&slot[SLOT_LEN];
        cat_port = port;
        for (i = 0; i < 2; i++)
            toupper_inplace(&mn[i]);       /* the mnemonic only; parameters keep their case */
        idx = cat_lookup(mn, cat_mnemonics, CAT_COUNT);

        /* powered off: only "PS1;" is taken [fact: 0xFFFA3539..0xFFFA356C] */
        if (g_ui.radio_on == 0 && !(idx == CAT_PS && slot[SLOT_TEXT + 2] == '1'))
            return;

        if (idx != CAT_NONE) {
            cat_dispatch(slot, idx, len);
        } else {
            idx = cat_lookup(mn, cat_ext_mnemonics, 10u);
            if (idx == CAT_NONE)
                cat_error = 1;
            else if (idx == CATX_SP)
                cat_ext_SP(slot);
            else
                cat_dispatch_ext(slot, idx, len);
        }
        if (cat_error != 0)
            cat_reply_error();
        else if (g_ui.dialog_shown == 1)
            FUN_fffbe232();
        if (cat_reply_len != 0)
            cat_send_reply(port, cat_reply, cat_reply_len);
    }

    /* the SPN save that cat_SP_table deferred, once timer 0x32 has expired [fact: 0xFFFA36C6] */
    if (cat_spn_save_pending == 1 && swtimer_expired(0x32) == 1) {
        key_dsp_press();
        cat_spn_save_pending = 0;
    }
    cat_ai_poll();
}

/* cat_ext_SP 0xFFFA36F2: the service command SP, by its third letter: SPS (SDR register), SPD (device 4 register),
 * SPI (A/D dump), SPW / SPR (EEPROM byte, summed), SPM (meters, summed), SPN (table), SPA (save the alignment
 * table, summed) [fact: the compares in 0xFFFA36F2..0xFFFA3A29; cat-undocumented.md] */
void cat_ext_SP(const uint8_t *slot)
{
    const uint8_t *text = slot + SLOT_TEXT;
    uint16_t len = *(const uint16_t *)&slot[SLOT_LEN];
    uint8_t sub = text[2];
    uint8_t rw;

    if (is_letter(sub, 'S')) {
        cat_reply_echo(slot, 4);
        rw = text[3];
        if (is_letter(rw, 'W'))
            cat_SP_sdr_reg(text, 1);
        else if (is_letter(rw, 'R'))
            cat_SP_sdr_reg(text, 0);
        else
            cat_error = 1;
    } else if (is_letter(sub, 'D')) {
        cat_reply_echo(slot, 4);
        rw = text[3];
        if (is_letter(rw, 'W'))
            cat_SP_dev4_reg(text, 1);
        else if (is_letter(rw, 'R'))
            cat_SP_dev4_reg(text, 0);
        else
            cat_error = 1;
    } else if (is_letter(sub, 'I')) {
        cat_reply_echo(slot, 4);
        if (is_letter(text[3], 'R'))
            cat_SP_adc_dump();
        else
            cat_error = 1;
    } else if (sub == 'W' || sub == 'R') {           /* upper case only [fact: 0xFFFA3848] */
        if (!cat_checksum_ok(text, (uint16_t)(len - 2u))) {
            cat_error = 1;
            return;
        }
        cat_reply_echo(slot, 5);
        cat_SP_eeprom_byte(text, sub == 'W');
    } else if (is_letter(sub, 'M')) {
        if (!cat_checksum_ok(text, (uint16_t)(len - 2u))) {
            cat_error = 1;
            return;
        }
        cat_reply_echo(slot, 3);
        cat_SP_meters();
    } else if (is_letter(sub, 'N')) {
        cat_reply_echo(slot, 3);
        rw = text[3];
        if (is_letter(rw, 'W') || is_letter(rw, 'S'))
            cat_SP_table(text, 1, len);
        else if (is_letter(rw, 'R'))
            cat_SP_table(text, 0, len);
        else
            cat_error = 1;
    } else if (is_letter(sub, 'A')) {
        if (!cat_checksum_ok(text, (uint16_t)(len - 2u))) {
            cat_error = 1;
            return;
        }
        if (is_letter(text[3], 'W') && is_letter(text[4], 'E'))
            eeprom_save_cfg105();          /* "SPAWE": write the alignment table to the EEPROM */
        else
            cat_error = 1;
    }
    /* any other third letter: no reply and no error [fact: 0xFFFA399B..0xFFFA39A1] */
}

/* cat_dispatch_ext 0xFFFA3A2A: the extended table without SP (cat_ext_SP) and E9 (only from the E9 slot) */
void cat_dispatch_ext(const uint8_t *slot, uint8_t idx, uint16_t len)
{
    const uint8_t *text = slot + SLOT_TEXT;

    switch (idx) {
    case CATX_EO:
        cat_reply_echo(slot, 5);
        if (len != 10u)
            break;
        cat_ext_EO(text, 1);
        return;
    case CATX_JP:
        cat_reply_echo(slot, 6);
        if (len == 7u) {
            cat_ext_JP(text, 0);
            return;
        }
        if (len != 15u)
            break;
        cat_ext_JP(text, 1);
        return;
    case CATX_FD:
        cat_reply_echo(slot, 5);
        if (len == 6u) {
            cat_ext_FD(text, 0);
            return;
        }
        if (len != 15u)
            break;
        cat_ext_FD(text, 1);
        return;
    case CATX_PE:
        cat_reply_echo(slot, 5);
        if (len == 6u) {
            cat_ext_PE(text, 0);
            return;
        }
        if (len != 9u)
            break;
        cat_ext_PE(text, 1);
        return;
    case CATX_ZZ:
        cat_ext_ZZ(text);
        return;
    case CATX_VE:
        cat_reply_echo(slot, 3);
        cat_ext_VE((uint8_t)hex2nib(text[2]));
        return;
    case CATX_E8:
        cat_reply_echo(slot, 2);
        cat_ext_E8();
        return;
    default:                               /* KT, E9: nothing [fact: 0xFFFA3A2A] */
        return;
    }
    cat_error = 1;
}

/* cat_dispatch 0xFFFA3B6E: the primary table. The length is that of the whole command with mnemonic and ';'; a
 * wrong length is "?;" [fact: the case code; decomp/main/cat_dispatch.tsv lists every test]. */
void cat_dispatch(const uint8_t *slot, uint8_t idx, uint16_t len)
{
    const uint8_t *text = slot + SLOT_TEXT;

    switch (idx) {
    case CAT_AB:
        if (len != 3u)
            break;
        cat_AB();
        return;
    case CAT_AC:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_AC(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_AC(text, 1);
        return;
    case CAT_AG:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_AG(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_AG(text, 1);
        return;
    case CAT_AI:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_AI(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_AI(text, 1);
        return;
    case CAT_AM:
        if (len != 3u)
            break;
        cat_AM();
        return;
    case CAT_AO:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_AO(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_AO(text, 1);
        return;
    case CAT_AS:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_AS(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_AS(text, 1);
        return;
    case CAT_AV:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_AV(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_AV(text, 1);
        return;
    case CAT_BA:
        if (len != 3u)
            break;
        cat_BA();
        return;
    case CAT_BC:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_BC(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_BC(text, 1);
        return;
    case CAT_BD:
        cat_reply_echo(slot, 2);
        if (len != 4u)
            break;
        cat_BD(text);
        return;
    case CAT_BI:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_BI(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_BI(text, 1);
        return;
    case CAT_BM:
        if (len != 3u)
            break;
        cat_BM();
        return;
    case CAT_BP:
        cat_reply_echo(slot, 4);
        if (len == 5u) {
            cat_BP(text, 0);
            return;
        }
        if (len != 8u)
            break;
        cat_BP(text, 1);
        return;
    case CAT_BS:
        cat_reply_echo(slot, 4);
        if (len != 5u)
            break;
        cat_BS(text);
        return;
    case CAT_BU:
        cat_reply_echo(slot, 2);
        if (len != 4u)
            break;
        cat_BU(text);
        return;
    case CAT_CF:
        cat_reply_echo(slot, 4);
        if (len == 6u) {
            cat_CF(text, 0);
            return;
        }
        if (len != 11u)
            break;
        cat_CF(text, 1);
        return;
    case CAT_CH:
        if (len != 4u)
            break;
        cat_CH(text);
        return;
    case CAT_CN:
        cat_reply_echo(slot, 4);
        if (len == 5u) {
            cat_CN(text, 0);
            return;
        }
        if (len != 8u)
            break;
        cat_CN(text, 1);
        return;
    case CAT_CO:
        cat_reply_echo(slot, 3);
        if (len == 5u) {
            cat_CO(text, 0);
            return;
        }
        if (len != 9u)
            break;
        cat_CO(text, 1);
        return;
    case CAT_CS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_CS(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_CS(text, 1);
        return;
    case CAT_CT:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_CT(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_CT(text, 1);
        return;
    case CAT_DA:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_DA(text, 0);
            return;
        }
        if (len != 11u)
            break;
        cat_DA(text, 1);
        return;
    case CAT_DN:
        if (len != 3u)
            break;
        cat_DN();
        return;
    case CAT_DT:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_DT(text, 0);
            return;
        }
        if (len != 10u && len != 12u)
            break;
        cat_DT(text, 1);
        return;
    case CAT_EM:
        cat_reply_echo(slot, 4);
        if (len == 5u) {
            cat_EM(text, 0);
            return;
        }
        if (len < 6u || len > 55u)
            break;
        cat_EM(text, 1);
        return;
    case CAT_EN:
        cat_reply_echo(slot, 3);
        if (len != 5u)
            break;
        cat_EN(text);
        return;
    case CAT_EX:
        cat_reply_echo(slot, 8);
        if (len == 9u) {
            cat_EX(text, 0, 9);
            return;
        }
        if (len > 8u) {
            cat_EX(text, 1, len);
            return;
        }
        break;
    case CAT_FA:
    case CAT_FB:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_FA_FB(text, 0, idx == CAT_FB);
            return;
        }
        if (len != 12u)
            break;
        cat_FA_FB(text, 1, idx == CAT_FB);
        return;
    case CAT_FN:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_FN(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_FN(text, 1);
        return;
    case CAT_FS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_FS(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_FS(text, 1);
        return;
    case CAT_FT:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_FT(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_FT(text, 1);
        return;
    case CAT_GT:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_GT(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_GT(text, 1);
        return;
    case CAT_GP:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_GP(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_GP(text, 1);
        return;
    case CAT_ID:
        cat_reply_echo(slot, 3);
        if (len != 3u)
            break;
        cat_ID();
        return;
    case CAT_IF:
    case CAT_OI:
        cat_reply_echo(slot, 2);
        if (len != 3u)
            break;
        cat_IF_OI(idx == CAT_OI);
        return;
    case CAT_IS:
        cat_reply_echo(slot, 2);
        if (len == 4u) {
            cat_IS(text, 0);
            return;
        }
        if (len != 10u)
            break;
        cat_IS(text, 1);
        return;
    case CAT_KM:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_KM(text, 0, 4);
            return;
        }
        if (len < 5u || len > 54u)
            break;
        cat_KM(text, 1, len);
        return;
    case CAT_KP:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_KP(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_KP(text, 1);
        return;
    case CAT_KR:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_KR(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_KR(text, 1);
        return;
    case CAT_KS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_KS(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_KS(text, 1);
        return;
    case CAT_KY:
        if (len != 5u)
            break;
        cat_KY(text);
        return;
    case CAT_LK:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_LK(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_LK(text, 1);
        return;
    case CAT_LM:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_LM(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_LM(text, 1);
        return;
    case CAT_MA:
        if (len != 3u)
            break;
        cat_MA();
        return;
    case CAT_MB:
        if (len != 3u)
            break;
        cat_MB();
        return;
    case CAT_MC:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_MC(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_MC(text, 1);
        return;
    case CAT_MD:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_MD(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_MD(text, 1);
        return;
    case CAT_MG:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_MG(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_MG(text, 1);
        return;
    case CAT_ML:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_ML(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_ML(text, 1);
        return;
    case CAT_MR:
        cat_reply_echo(slot, 2);
        if (len != 6u)
            break;
        cat_MR(text, 0);
        return;
    case CAT_MS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_MS(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_MS(text, 1);
        return;
    case CAT_MT:
        cat_reply_echo(slot, 5);
        if (len == 6u) {
            cat_MT(text, 0, 6);
            return;
        }
        if (len < 8u || len > 19u)
            break;
        cat_MT(text, 1, len);
        return;
    case CAT_MW:
        cat_reply_echo(slot, 2);
        if (len != 28u)
            break;
        cat_MW(text, 1);
        return;
    case CAT_MX:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_MX(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_MX(text, 1);
        return;
    case CAT_NA:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_NA(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_NA(text, 1);
        return;
    case CAT_NB:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_NB(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_NB(text, 1);
        return;
    case CAT_NL:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_NL(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_NL(text, 1);
        return;
    case CAT_NR:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_NR(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_NR(text, 1);
        return;
    case CAT_OS:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_OS(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_OS(text, 1);
        return;
    case CAT_PA:
        cat_reply_echo(slot, 2);
        if (len == 4u) {
            cat_PA(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_PA(text, 1);
        return;
    case CAT_PB:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_PB(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_PB(text, 1);
        return;
    case CAT_PC:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_PC(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_PC(text, 1);
        return;
    case CAT_PL:
        cat_reply_echo(slot, 3);
        if (len == 3u) {
            cat_PL(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_PL(text, 1);
        return;
    case CAT_PR:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_PR(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_PR(text, 1);
        return;
    case CAT_PS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_PS(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_PS(text, 1);
        return;
    case CAT_QI:
        if (len != 3u)
            break;
        cat_QI();
        return;
    case CAT_QR:
        if (len != 3u)
            break;
        cat_QR();
        return;
    case CAT_QS:
        if (len != 3u)
            break;
        cat_QS();
        return;
    case CAT_RA:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_RA(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_RA(text, 1);
        return;
    case CAT_RG:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_RG(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_RG(text, 1);
        return;
    case CAT_RI:
        cat_reply_echo(slot, 3);
        if (len != 4u)
            break;
        cat_RI(text);
        return;
    case CAT_RL:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_RL(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_RL(text, 1);
        return;
    case CAT_RM:
        cat_reply_echo(slot, 3);
        if (len != 4u)
            break;
        cat_RM(text);
        return;
    case CAT_SC:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_SC(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_SC(text, 1);
        return;
    case CAT_SD:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_SD(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_SD(text, 1);
        return;
    case CAT_SF:
        cat_reply_echo(slot, 3);
        if (len == 4u) {
            cat_SF(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_SF(text, 1);
        return;
    case CAT_SH:
        cat_reply_echo(slot, 2);
        if (len == 4u) {
            cat_SH(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_SH(text, 1);
        return;
    case CAT_SM:
        cat_reply_echo(slot, 2);
        if (len != 4u)
            break;
        cat_SM(text);
        return;
    case CAT_SQ:
        cat_reply_echo(slot, 2);
        if (len == 4u) {
            cat_SQ(text, 0);
            return;
        }
        if (len != 7u)
            break;
        cat_SQ(text, 1);
        return;
    case CAT_SS:
        cat_reply_echo(slot, 4);
        if (len == 5u) {
            cat_SS(text, 0);
            return;
        }
        if (len != 10u)
            break;
        cat_SS(text, 1);
        return;
    case CAT_ST:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_ST(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_ST(text, 1);
        return;
    case CAT_SV:
        cat_reply_echo(slot, 2);
        if (len != 3u)
            break;
        cat_SV(text, 1);
        return;
    case CAT_TS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_TS(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_TS(text, 1);
        return;
    case CAT_TX:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_TX(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_TX(text, 1);
        return;
    case CAT_UP:
        if (len != 3u)
            break;
        cat_UP();
        return;
    case CAT_VD:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_VD(text, 0);
            return;
        }
        if (len != 5u)
            break;
        cat_VD(text, 1);
        return;
    case CAT_VG:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_VG(text, 0);
            return;
        }
        if (len != 6u)
            break;
        cat_VG(text, 1);
        return;
    case CAT_VM:
        cat_reply_echo(slot, 2);
        if (len != 3u && len != 4u && len != 6u)
            break;
        cat_VM(text, len);
        return;
    case CAT_VS:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_VS(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_VS(text, 1);
        return;
    case CAT_VX:
        cat_reply_echo(slot, 2);
        if (len == 3u) {
            cat_VX(text, 0);
            return;
        }
        if (len != 4u)
            break;
        cat_VX(text, 1);
        return;
    case CAT_ZI:
        if (len != 4u)
            break;
        cat_ZI(text);
        return;
    default:        /* BY, ED, EK, EU, RC, RD, RS, RT, RU, XT: in the table, but answered "?;" [fact: cat_dispatch.tsv] */
        break;
    }
    cat_error = 1;
}

