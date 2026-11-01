/*
 * FT-710 DISPLAY (T24 USB track): the scope-area text terminal on the SCIF4 link, its small parts (docs/code/display/
 * gui.md "Scope-area text terminal on SCIF4"): the state clear, the answer ring and the "send all settings" loop.
 * Recreated from the image's disassembly. Not recreated yet: textterm_send_setting 0x20130C90 (the 3-byte setting
 * frames) and the state machine textterm_tx_poll 0x20131638.
 *
 * The state is 0x35E bytes at 0x208F4896 [fact: textterm_clear clears that much from the literal 0x20131590]; the
 * 64-byte answer ring is inside it at +0x316 (0x208F4BAC), its write and read indices at +0x356 / +0x357
 * (0x208F4BEC / 0x208F4BED).
 */
#include <stdint.h>

typedef struct
{
    uint8_t body[0x314];
    uint8_t keep;           /* +0x314: survives textterm_clear */
    uint8_t pad;
    uint8_t rx[64];         /* +0x316: the answer bytes decode_text_rx pushes */
    uint8_t rx_wr;          /* +0x356 */
    uint8_t rx_rd;          /* +0x357 */
    uint8_t tail[6];
} textterm_t;

extern textterm_t textterm;    /* 0x208F4896 */

void __aeabi_memclr(void *dst, uint32_t n);
void textterm_send_setting(unsigned item, const uint8_t *frame, int force);

/* 0x20130C70: the whole state cleared except the byte +0x314 [fact] */
void textterm_clear(void)
{
    uint8_t keep = textterm.keep;

    __aeabi_memclr(&textterm, sizeof textterm);
    textterm.keep = keep;
}

/* 0x201310EC: (frame, force): settings 0..15 except 11 and 12 [fact] */
void textterm_send_all(const uint8_t *frame, int force)
{
    for (unsigned i = 0; i < 16; i++)
    {
        if (i == 11 || i == 12)
        {
            continue;
        }
        textterm_send_setting(i, frame, force);
    }
}

/* 0x20131130: (byte): appended at the write index; a full ring overwrites the oldest [fact: no full test] */
void textterm_rx_push(uint8_t b)
{
    textterm.rx[textterm.rx_wr] = b;
    textterm.rx_wr = (textterm.rx_wr + 1) & 63;
}

/* 0x201315A4: indices and ring cleared [fact] */
void textterm_rx_clear(void)
{
    textterm.rx_rd = 0;
    textterm.rx_wr = 0;
    __aeabi_memclr(textterm.rx, sizeof textterm.rx);
}

/* 0x201315C0: (byte): 0 when the ring is empty or its next byte is 0 (left in place); otherwise the byte is taken
 * (its slot cleared) and the result is 1 when it equals byte [fact] */
int textterm_rx_expect(unsigned b)
{
    unsigned rd = textterm.rx_rd;

    if (rd == textterm.rx_wr)
    {
        return 0;
    }
    uint8_t c = textterm.rx[rd];

    if (c != b && c == 0)
    {
        return 0;
    }
    textterm.rx[rd] = 0;
    textterm.rx_rd = (textterm.rx_rd + 1) & 63;
    return c == b;
}
