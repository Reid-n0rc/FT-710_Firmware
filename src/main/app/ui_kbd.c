/* The on-screen keyboard payloads of DISPLAY-link frame 0x50 (T24, UI track; docs/code/main/display-link.md frame
 * 0x50, ui-keys.md): one builder per text the keyboard edits (MY CALL, MEMORY NAME, the CW / RTTY / PSK message
 * memories, FILE NAME, PRESET NAME), each filling the staging buffer 0x1741: layout byte +0x98, cursor +0x99, the
 * label +0x9A, the title +0xA4, "Char #nn" +0xB8, the text +0xC2 with the cursor character marked 0xFF [fact: the
 * offsets in dl50_mycall 0xFFF9A364..0xFFF9A42D]. */
#include <stdint.h>
#include "ft710_state.h"

extern uint8_t displink_stage[];                /* 0x1741 */
extern struct ui_state *g_ui_ptr;               /* 0x25D38 = &g_ui */

void memch_label_fmt(uint8_t *dst, uint8_t ch);
void kbd_fmt_char_pos(uint8_t *dst);
void kbd_copy_text(const uint8_t *src, uint8_t *dst, uint8_t n);
void dl50_slot_label(void);
void dl50_msg_text(void);

#define F50_LAYOUT 0x98
#define F50_CURSOR 0x99
#define F50_LABEL 0x9A
#define F50_TITLE 0xA4
#define F50_CHARPOS 0xB8
#define F50_TEXT 0xC2

/* the layout byte: base | 0 / 1 / 2 by g_ui.kbd_layout 0 / 1 / other [fact: BSET #0 / #1 on the base] */
static void f50_layout3(uint8_t base)
{
    if (g_ui_ptr->kbd_layout == 0)
        displink_stage[F50_LAYOUT] = base;
    else if (g_ui_ptr->kbd_layout == 1)
        displink_stage[F50_LAYOUT] = base | 1u;
    else
        displink_stage[F50_LAYOUT] = base | 2u;
}

/* the title without its NUL (CC-RX's SUNTIL / SMOVF copy of strlen bytes) */
static void f50_title(const char *s)
{
    uint8_t *d = &displink_stage[F50_TITLE];
    while (*s)
        *d++ = (uint8_t)*s++;
}

/* dl50_mycall 0xFFF9A364: target 0, 12 characters [fact] */
void dl50_mycall(void)
{
    f50_layout3(0x00);
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    f50_title("MY CALL");
    kbd_fmt_char_pos(&displink_stage[F50_CHARPOS]);
    kbd_copy_text(g_ui_ptr->msg_text[0], &displink_stage[F50_TEXT], 12);
}

/* dl50_memory_name 0xFFF9A42F: the channel label of the memory list's channel, 12 characters [fact] */
void dl50_memory_name(void)
{
    f50_layout3(0x00);
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    memch_label_fmt(&displink_stage[F50_LABEL], g_ui_ptr->memlist_ch);
    f50_title("MEMORY NAME");
    kbd_fmt_char_pos(&displink_stage[F50_CHARPOS]);
    kbd_copy_text(g_ui_ptr->msg_text[0], &displink_stage[F50_TEXT], 12);
}

/* dl50_cw_text 0xFFF9A4F4 / dl50_rtty_text 0xFFF9A55E: layout 0x10 / 0x30, | 2 unless the layout is 0 [fact] */
void dl50_cw_text(void)
{
    displink_stage[F50_LAYOUT] = g_ui_ptr->kbd_layout == 0 ? 0x10 : 0x12;
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    dl50_slot_label();
    f50_title("CW TEXT");
    dl50_msg_text();
}

void dl50_rtty_text(void)
{
    displink_stage[F50_LAYOUT] = g_ui_ptr->kbd_layout == 0 ? 0x30 : 0x32;
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    dl50_slot_label();
    f50_title("RTTY TEXT");
    dl50_msg_text();
}

/* dl50_psk_text 0xFFF9A5C8: layout 0x20 | 0 / 1 / 2 [fact] */
void dl50_psk_text(void)
{
    f50_layout3(0x20);
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    dl50_slot_label();
    f50_title("PSK TEXT");
    dl50_msg_text();
}

/* dl50_file_name 0xFFF9A64F (layout 0x40, 20 characters) / dl50_preset_name 0xFFF9A6F9 (layout 0, 12) [fact] */
void dl50_file_name(void)
{
    f50_layout3(0x40);
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    f50_title("FILE NAME");
    kbd_fmt_char_pos(&displink_stage[F50_CHARPOS]);
    kbd_copy_text(g_ui_ptr->msg_text[0], &displink_stage[F50_TEXT], 20);
}

void dl50_preset_name(void)
{
    f50_layout3(0x00);
    displink_stage[F50_CURSOR] = g_ui_ptr->kbd_cursor;
    f50_title("PRESET NAME");
    kbd_fmt_char_pos(&displink_stage[F50_CHARPOS]);
    kbd_copy_text(g_ui_ptr->msg_text[0], &displink_stage[F50_TEXT], 12);
}

/* kbd_fmt_char_pos 0xFFF9A7A2 (dst): "Char #" and the cursor position + 1 as two digits (DIV, signed) [fact] */
void kbd_fmt_char_pos(uint8_t *dst)
{
    int32_t pos = g_ui_ptr->kbd_cursor + 1;
    uint8_t tens = (uint8_t)(pos / 10);
    pos = g_ui_ptr->kbd_cursor + 1;
    uint8_t ones = (uint8_t)(pos - pos / 10 * 10);
    dst[0] = 'C';
    dst[1] = 'h';
    dst[2] = 'a';
    dst[3] = 'r';
    dst[4] = ' ';
    dst[5] = '#';
    dst[6] = tens | 0x30u;
    dst[7] = ones | 0x30u;
}

/* kbd_copy_text 0xFFF9A804 (src, dst, n): n bytes, then the cursor character 0xFF unless g_ui +0x1BC is set [fact] */
void kbd_copy_text(const uint8_t *src, uint8_t *dst, uint8_t n)
{
    for (uint32_t i = n; i != 0; i--)
        *dst++ = *src++;
    dst -= n;
    if (g_ui_ptr->kbd_show_cursor_char == 0)
        dst[g_ui_ptr->kbd_cursor] = 0xFF;
}

/* dl50_slot_label 0xFFF9A83B: "ch" and the message slot 1..5 [fact] */
void dl50_slot_label(void)
{
    displink_stage[F50_LABEL] = 'c';
    displink_stage[F50_LABEL + 1] = 'h';
    displink_stage[F50_LABEL + 2] = (uint8_t)((g_ui_ptr->msg_slot_idx + 1) | 0x30);
}

/* dl50_msg_text 0xFFF9A869: the 50 characters of the current message slot [fact: MUL #50] */
void dl50_msg_text(void)
{
    kbd_fmt_char_pos(&displink_stage[F50_CHARPOS]);
    kbd_copy_text(&g_ui_ptr->msg_text[0][0] + g_ui_ptr->msg_slot_idx * 50, &displink_stage[F50_TEXT], 50);
}
