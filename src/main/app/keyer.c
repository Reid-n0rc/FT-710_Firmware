/* The CW keyer of the MAIN image, recreated for T24 (docs/code/main/radio-control.md, eeprom.md "Message memory"):
 * the state reset, the element ring index (round 2) and keyer_task, the main-loop task that runs the keyer and the
 * message memories (round 4). The element generator (keyer_elekey, keyer_output_step) is the image's. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

#define KEYER_RING_LEN 0x500u   /* element ring index range [fact: keyer_ring_next 0xFFFBB175] */

/* keyer_init 0xFFFB98C8: keyer idle (UI +0x2B), keyer type 0, the element buffer 0x120BC.. cleared (0xA0 bytes) */
void keyer_init(void)
{
    uint8_t *p = keyer_elem_buf;
    uint32_t n = 0xA0u;

    g_ui_keyer_state = 0;
    keyer_type = 0;
    while (n--)
        *p++ = 0;
}

/* keyer_state_clear 0xFFFBAFF6: the five bytes 0x12160..0x12164 (keyer_task states 0 and 2) */
void keyer_state_clear(void)
{
    keyer_flags[0] = 0;
    keyer_flags[1] = 0;
    keyer_flags[2] = 0;
    keyer_flags[3] = 0;
    keyer_flags[4] = 0;
}

/* keyer_ring_next 0xFFFBB16B: the next ring index, 0 after 0x4FF */
uint16_t keyer_ring_next(uint16_t i)
{
    i = (uint16_t)(i + 1u);
    if (i >= KEYER_RING_LEN)
        i = 0;
    return i;
}

/* keyer_sidetone_off 0xFFFBB1C2: stop the side tone if this keyer started it */
void keyer_sidetone_off(void)
{
    if (keyer_sidetone_on != 1u)
        return;
    beep_stop();
    keyer_sidetone_on = 0;
}

/* soft timers of keyer_task [fact: the swtimer_start / swtimer_expired arguments] */
#define TMR_KEYER_TICK 19         /* keyer_task runs when it has expired */
#define TMR_QSK        25
#define TMR_REC_LIMIT  27         /* 10 s from the start of a recording */
#define TMR_REPEAT     28         /* the message repeat interval */

/* keyer_task's states (g_ui.keyer_state) [fact: the switch at 0xFFFB9AC1 over the table 0xFFF8F208] */
enum keyer_task_state {
    KT_START, KT_KEYING, KT_REC_START, KT_RECORDING, KT_REC_STORE, KT_SEND_START, KT_SENDING, KT_SEND_DONE
};

#define KEYER_ELEM_LIMIT 0x4B0u   /* a text stops being encoded after this many elements [fact: 0xFFFB9FF3] */
#define CONTEST_MAX      9999u

/* the message slot 1..5 of the UI (anything else is slot 1) [fact: 0xFFFB9C20..0xFFFB9C43] */
static uint8_t msg_slot_1to5(void)
{
    uint8_t slot = g_ui.msg_slot;

    return (slot == 0 || slot > 5u) ? 1u : slot;
}

/* the QSK delay: EX020119 x 5 + 15 (qsk_delay_ticks), 15 with the keyer off, and shorter at high speed
 * [fact: 0xFFFB9A0B..0xFFFB9ABE] */
static uint8_t keyer_qsk(void)
{
    uint8_t q = qsk_delay_ticks();

    if (keyer_type == 0)
        return 15;
    if (keyer_speed_cur >= 41u && q > 15u)
        return 15;
    if (keyer_speed_cur >= 36u && q >= 21u)
        return 20;
    if (keyer_speed_cur >= 31u && q >= 26u)
        return 25;
    return q;
}

/* one character's elements from its morse_table row: each element a dot or dash unit and a space */
static void put_morse(uint8_t n, uint8_t bits)
{
    uint8_t i;

    for (i = 0; i < n; i++) {
        keyer_elem_put((bits & 0x80u) ? 2u : 1u);
        keyer_elem_put(0);
        bits = (uint8_t)(bits << 1);
    }
}

static void put_spaces(uint8_t n)
{
    uint8_t i;

    for (i = 0; i < n; i++)
        keyer_elem_put(0);
}

/* '#': the contest number as four characters without a leading zero in the thousands, each through the NUMBER
 * STYLE substitution (cut numbers) and followed by two spaces [fact: 0xFFFB9DDF..0xFFFB9EB0] */
static void put_contest_number(void)
{
    uint16_t num = contest_number_get();
    uint16_t div = 1000;
    uint8_t k, c;

    for (k = 0; k < 4; k++) {
        c = (uint8_t)nib2hex((uint8_t)(num / div));
        num = (uint16_t)(num - (num / div) * div);
        div = (uint16_t)(div / 10u);
        if (k == 0 && c == '0')
            continue;
        c = (uint8_t)contest_cut_digit((char)c);
        put_morse(morse_table[c][0], morse_table[c][1]);
        put_spaces(2);
    }
}

/* the contest number one up ('<') or down ('>') while break-in is on, within 1..9999 */
static void contest_step(int up)
{
    uint16_t num;

    if (tx_breakin_on() != 1)
        return;
    num = contest_number_get();
    if (up ? num < CONTEST_MAX : num >= 2u)
        contest_number_set((uint16_t)(up ? num + 1u : num - 1u));
}

/* a keyer text into elements: characters through morse_table, a character without elements is a word space (four
 * units), '[' .. ']' joins characters (no letter space), '#' the contest number, '<' / '>' step it, "^0n" the
 * text of slot n (1..5) unless it is this one [fact: 0xFFFB9D84..0xFFFBA006] */
static void encode_text(uint8_t idx)
{
    const struct keyer_text *t = &keyer_text_mem[idx];
    uint8_t len = t->len;
    uint8_t joined = 0;
    uint8_t i, c, n, bits;

    for (i = 0; i < len; i++) {
        c = t->text[i];
        n = morse_table[c][0];
        bits = morse_table[c][1];
        if (c == '#') {
            keyer_has_number = 1;
            put_contest_number();
        } else if (c == '<') {
            contest_step(1);
        } else if (c == '>') {
            contest_step(0);
        } else if (c == '[') {
            joined = 1;
        } else if (c == ']') {
            joined = 0;
        } else if (c == '^') {
            c = t->text[++i];
            i++;
            if (c == '0') {
                c = t->text[i];
                if (c >= '1' && c <= '5') {
                    c = (uint8_t)(hex2nib(c) - 1);
                    if (idx != c)
                        keyer_text_msg_encode(c);
                }
            }
        } else if (n == 0) {
            put_spaces(4);
        } else {
            put_morse(n, bits);
            if (!joined)
                put_spaces(2);
        }
        if (keyer_elem_wr > KEYER_ELEM_LIMIT)
            break;
    }
}

static void copy150(uint8_t *dst, const uint8_t *src)
{
    unsigned i;

    for (i = 0; i < 150u; i++)
        dst[i] = src[i];
}

/* keyer_task 0xFFFB98E9: main-loop task. Off unless the mode keys CW (tx_cw_keying_class) and the PlayList screen
 * is closed; runs each time soft timer 19 expires, not during a tune cycle. Takes a new key speed only when the
 * paddles allow it, derives the dot and dash times and the QSK delay, then runs the keying / recording / sending
 * state machine and one step of the element output. */
void keyer_task(void)
{
    uint8_t weight = g_opstate.ex020203_cw_weight;
    uint8_t p1, p2;
    uint16_t num;

    if (tx_cw_keying_class() == 0 || g_ui.playlist_open != 0) {
        keyer_init();
        keyer_sidetone_off();
        g_ui.ptt_keyer = 0;
        return;
    }
    if (swtimer_expired(TMR_KEYER_TICK) != 1 || g_ui.tune_cycle != 0)
        return;
    if (keyer_speed_cur != g_opstate.key_speed) {
        int take = 0;

        if (keyer_flags[4] == 0) {
            keyer_paddles_read(&p1, &p2);
            if (p1 == 1 && p2 == 1)
                take = keyer_flags[2] == 2;     /* both paddles closed */
            else
                take = 1;
        }
        if (take) {
            keyer_speed_cur = g_opstate.key_speed;
            keyer_init();
        }
    }
    keyer_type = g_opstate.keyer_on == 0 ? 0 : g_opstate.ex020201_keyer_type;
    /* the module's DIVU by 0 keeps the dividend (the manual: undefined, p. 78); the speed in use is 0 only before
     * the first copy */
    keyer_dot_time = 1200000u;
    if (keyer_speed_cur != 0)
        keyer_dot_time = 1200000u / keyer_speed_cur;
    keyer_dash_time = (uint32_t)(weight + 25u) * keyer_dot_time / 10u;
    keyer_qsk_ticks = keyer_qsk();

    switch (g_ui.keyer_state) {
    case KT_START:
        keyer_elem_rd = 0;
        keyer_elem_wr = 0;
        g_ui.keyer_state = KT_KEYING;
        swtimer_start(TMR_QSK, keyer_qsk_ticks);
        keyer_state_clear();
        /* fall through */
    case KT_KEYING:
        if (keyer_type < 2u)
            keyer_straight_bug(keyer_type);
        else if (keyer_type <= 5u)
            keyer_elekey(keyer_type, 0);
        break;
    case KT_REC_START: {
        unsigned i;

        if (tx_keying_kind != 1)
            return;
        for (i = 0; i < 0xA0u; i++)
            keyer_elem_buf[i] = 0;
        keyer_elem_rd = 0;
        keyer_elem_wr = 0;
        g_ui.keyer_state = KT_RECORDING;
        swtimer_start(TMR_QSK, keyer_qsk_ticks);
        swtimer_start(TMR_REC_LIMIT, 10000);
        keyer_state_clear();
        keyer_rec_vfob = vfo_rec_ptr(1);
        if (tx_breakin_on() == 1) {             /* break-in off while recording (VFO-B record byte 0x14 bit 1) */
            keyer_breakin_saved = 1;
            keyer_rec_vfob[0x14] &= (uint8_t)~0x02u;
        } else {
            keyer_breakin_saved = 0;
        }
    }
        /* fall through */
    case KT_RECORDING:
        if ((uint8_t)(keyer_type - 2u) <= 3u)
            keyer_elekey(keyer_type, 1);
        break;
    case KT_REC_STORE:
        if (keyer_breakin_saved == 1) {
            keyer_breakin_saved = 0;
            keyer_rec_vfob[0x14] |= 0x02u;
        }
        keyer_elem_rd = keyer_elem_wr;
        if (keyer_elem_wr != 0) {
            uint8_t slot = msg_slot_1to5();
            struct keyer_msg *m = &keyer_msg_mem[slot - 1u];

            m->len_be[0] = (uint8_t)(keyer_elem_rd >> 8);
            m->len_be[1] = (uint8_t)keyer_elem_rd;
            copy150(m->elems, keyer_elem_buf);
            eeprom_save_msg(0, slot);
        }
        keyer_elem_wr = 0;
        keyer_elem_rd = 0;
        g_ui.keyer_state = KT_START;
        break;
    case KT_SEND_START: {
        uint8_t idx;

        keyer_has_number = 0;
        if (tx_keying_kind != 1)
            return;
        if (beep_pattern_get() == 1)
            return;
        idx = (uint8_t)(msg_slot_1to5() - 1u);
        keyer_elem_wr = 0;
        keyer_elem_rd = 0;
        if ((&g_opstate.ex020206_cw_memory_1)[idx] == 1) {     /* CW MEMORY n = 1: the recorded elements */
            const struct keyer_msg *m = &keyer_msg_mem[idx];

            keyer_elem_wr = (uint16_t)(m->len_be[0] << 8 | m->len_be[1]);
            copy150(keyer_elem_buf, m->elems);
        } else {                                               /* 0: the keyer text */
            encode_text(idx);
        }
        keyer_elem_end = keyer_elem_wr;
        keyer_elem_wr = 0;
        swtimer_start(TMR_QSK, keyer_qsk_ticks);
        g_ui.keyer_state = KT_SENDING;
        keyer_state_clear();
    }
        /* fall through */
    case KT_SENDING:
        if (keyer_elem_rd == keyer_elem_end) {
            g_ui.keyer_state = KT_SEND_DONE;
            if (g_ui.msg_active == 1)
                swtimer_start(TMR_REPEAT, (uint16_t)(g_opstate.ex020211_repeat_interval * 1000u));
            if (keyer_has_number == 1 && (num = contest_number_get()) < CONTEST_MAX)
                contest_number_set((uint16_t)(num + 1u));
        } else {
            keyer_paddles_read(&p1, &p2);
            if (p1 == 1 || p2 == 1) {          /* a paddle stops the message */
                g_ui.msg_active = 0;
                g_ui.keyer_state = KT_SEND_DONE;
            }
        }
        FUN_fffba9c3();
        break;
    case KT_SEND_DONE:
        if (g_ui.msg_active == 1) {            /* repeat after the interval */
            if (swtimer_expired(TMR_REPEAT) == 1)
                g_ui.keyer_state = KT_SEND_START;
        } else {
            keyer_elem_wr = 0;
            keyer_elem_rd = 0;
            keyer_sidetone_off();
            g_ui.keyer_state = KT_START;
        }
        break;
    default:
        break;
    }
    keyer_output_step(keyer_type);
}
