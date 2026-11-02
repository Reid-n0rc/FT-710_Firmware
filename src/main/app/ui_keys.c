/* The key dispatch helpers of the MAIN image (T24, UI track; docs/code/main/ui-keys.md "key_task", "Key classes
 * and handler tables"): the class of a key code, the assignable microphone keys, the calls through the five
 * 863-entry handler tables (press, short, long, repeat, release) and the five slot dispatchers of the microphone key
 * assignments. Each table call is a JSR through a ROM table of the image [fact: 7F 1E JSR R14 at 0xFFFBC388]; the
 * handlers are the image's. */
#include <stdint.h>
#include "ft710_state.h"
#include "ui.h"

typedef void (*key_handler_t)(uint32_t r1);

/* ROM (src/main/data_symbols.tsv) */
extern const uint8_t key_class_table[0x35F];        /* 0xFFF83164: class per code */
extern const uint8_t key_slot_class_table[21];      /* 0xFFF834B6: indexed by the slot; slots 13..20 used (0xFFF834C3..) */
extern const uint16_t key_assign_codes[13];         /* 0xFFF88534: the key code of slots 0..12 */
extern const key_handler_t key_press_table[0x35F];  /* 0xFFF89D94 */
extern const key_handler_t key_short_table[0x35F];  /* 0xFFF8AB10 */
extern const key_handler_t key_long_table[0x35F];   /* 0xFFF8B88C */
extern const key_handler_t key_repeat_table[0x35F]; /* 0xFFF8C608 */
extern const key_handler_t key_release_table[0x35F];/* 0xFFF8D384 */
extern const key_handler_t key_slot_tables[5][8];   /* 0xFFF8E100: slots 13..20 per role, 0x20 apart */
/* RAM */
extern uint16_t key_code;                           /* 0x1FA40: the code key_task is handling */

uint8_t key_assign_slot(uint16_t code);
uint8_t key_dest_allowed(uint32_t code, uint32_t x);
void FUN_fffc4d93(void);
void vfo_contour_reset(uint8_t vfo);
void vfo_apf_reset(uint8_t vfo);

#define KEY_SLOT_NONE 0xFFu
#define KEY_LOCK_PWR 0x300u                 /* front-panel LOCK/PWR (ui-keys.md physical keys) */

/* microphone key codes (ui-keys.md "Key assignment") */
#define KEY_MIC_UP 0x348u
#define KEY_MIC_DOWN 0x34Eu
#define KEY_MIC_P1 0x35Bu
#define KEY_MIC_P2 0x35Cu
#define KEY_MIC_P3 0x35Du
#define KEY_MIC_P4 0x35Eu

/* key_nop 0xFFFC4A8D: the empty handler (RTS) [fact] */
__attribute__((naked)) void key_nop(void)
{
    __asm__ volatile("rts");
}

/* key_task_init 0xFFFBBD53 [fact: BSR.A FUN_fffc4d93; RTS] */
void key_task_init(void)
{
    FUN_fffc4d93();
}

/* key_assign_slot 0xFFFBC225 (code): the MIC P1..P4 / UP / DOWN assignment (EX030120..EX030125, 0..20) of an
 * assignable microphone key, 0xFF for any other code [fact] */
uint8_t key_assign_slot(uint16_t code)
{
    uint8_t slot = KEY_SLOT_NONE;
    switch (code) {
    case KEY_MIC_P4: slot = g_opstate.ex030123_mic_p4; break;
    case KEY_MIC_DOWN: slot = g_opstate.ex030125_mic_down; break;
    case KEY_MIC_P1: slot = g_opstate.ex030120_mic_p1; break;
    case KEY_MIC_P2: slot = g_opstate.ex030121_mic_p2; break;
    case KEY_MIC_P3: slot = g_opstate.ex030122_mic_p3; break;
    case KEY_MIC_UP: slot = g_opstate.ex030124_mic_up; break;
    }
    return slot;
}

/* key_class_of 0xFFFBC1D0 (code): the class of the code, or for an assigned microphone key the class of the key its
 * slot stands for (slots 0..12) or of the slot itself (13..20: 0xFFF834B6[slot], i.e. 0xFFF834C3 + slot - 13 at 0xFFFBC20D) [fact] */
uint8_t key_class_of(uint16_t code)
{
    uint8_t slot = key_assign_slot(code);
    if (slot == KEY_SLOT_NONE)
        return key_class_table[code];
    if (slot <= 12)
        return key_class_table[key_assign_codes[slot]];
    return key_slot_class_table[slot];
}

/* key_call_press / _short / _repeat / _release 0xFFFBC35F / 0xFFFBC38E / 0xFFFBC406 / 0xFFFBC435: the handler of
 * key_code when key_dest_allowed(code, 0) allows it; the handler gets that result in R1, as the image's JSR does
 * [fact] */
static void key_call(const key_handler_t *table)
{
    uint8_t ok = key_dest_allowed(key_code, 0);
    if (ok != 0)
        table[key_code](ok);
}

void key_call_press(void) { key_call(key_press_table); }
void key_call_short(void) { key_call(key_short_table); }
void key_call_repeat(void) { key_call(key_repeat_table); }
void key_call_release(void) { key_call(key_release_table); }

/* key_call_long 0xFFFBC3BD: as the others, but LOCK/PWR's long press runs also when not allowed (R1 = 0 at the
 * call) [fact] */
void key_call_long(void)
{
    uint8_t ok = key_dest_allowed(key_code, 0);
    uint32_t blocked = (ok == 0 && key_code != KEY_LOCK_PWR) ? 1u : 0u;
    if (blocked == 0)
        key_long_table[key_code](blocked);
}

/* key_slot_press .. _release 0xFFFC40D7..0xFFFC41A3 (slot): slots 0..12 run the handler of the key code they stand
 * for (R1 = slot), 13..20 the role's own table at 0xFFF8E100 (R1 = the table entry's address) [fact] */
static void key_slot_call(uint8_t slot, const key_handler_t *table, uint32_t role)
{
    if (slot <= 12) {
        table[key_assign_codes[slot]](slot);
    } else {
        const key_handler_t *e = &key_slot_tables[role][slot - 13];
        (*e)((uint32_t)e);
    }
}

void key_slot_press(uint8_t slot) { key_slot_call(slot, key_press_table, 0); }
void key_slot_short(uint8_t slot) { key_slot_call(slot, key_short_table, 1); }
void key_slot_long(uint8_t slot) { key_slot_call(slot, key_long_table, 2); }
void key_slot_repeat(uint8_t slot) { key_slot_call(slot, key_repeat_table, 3); }
void key_slot_release(uint8_t slot) { key_slot_call(slot, key_release_table, 4); }

/* contour_reset_beep 0xFFFBDE35 / apf_reset_beep 0xFFFBDF75: CONTOUR / APF of the active VFO back to its default,
 * then beep 2 [fact] */
void contour_reset_beep(void)
{
    vfo_contour_reset(g_opstate.active_vfo == 0 ? 0 : 1);
    beep_request(2);
}

void apf_reset_beep(void)
{
    vfo_apf_reset(g_opstate.active_vfo == 0 ? 0 : 1);
    beep_request(2);
}
