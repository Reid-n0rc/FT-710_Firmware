/* Key tasks of the MAIN image (T24 MAIN round 5; docs/code/main/ui-keys.md): ladder_key_task, main-loop task 8, the
 * remote keypad (the code remote_key_get returns: 1..12 for a key, 0xF0 + n while key n is held, 0 for none). The
 * actions are the image's own functions (ui-keys.md lists them); this file is the dispatch. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

uint8_t remote_key_get(void);
int32_t ladder_key_delay(void);
uint8_t key_event_filter(uint16_t code, uint8_t press);

/* a key that is still the same code: the held codes of keys 7..10 repeat (7 and 9 after ladder_key_delay) */
void FUN_fffe4da3(void);
void FUN_fffe4b73(void);
void FUN_fffe4cc1(void);
void FUN_fffe4a67(void);
/* a new code after key n (1..12): the release action, or the "latched" one when the new code is n's held code
 * 0xF0 + n [fact: each compare with 0xF0 + n, 0xFFFE3EF6..0xFFFE404B] */
void msg_cw_slot_key_1(void), msg_cw_slot_key_2(void), msg_cw_slot_key_3(void), msg_cw_slot_key_4(void),
     msg_cw_slot_key_5(void);
void msg_cw_slot_key_latched_1(void), msg_cw_slot_key_latched_2(void), msg_cw_slot_key_latched_3(void),
     msg_cw_slot_key_latched_4(void), msg_cw_slot_key_latched_5(void);
void FUN_fffe46b0(void), FUN_fffe46d3(void), FUN_fffe46d4(void), FUN_fffe46e2(void), FUN_fffe46e3(void),
     FUN_fffe46f1(void), FUN_fffe46f2(void);
void FUN_fffe47be(void), FUN_fffe49fb(void), FUN_fffe4af8(void), FUN_fffe4c55(void), FUN_fffe4d28(void),
     FUN_fffe4de3(void), FUN_fffe4de4(void);
void FUN_fffe4c04(void);           /* after the held code of key 10 */
void FUN_fffe4bb3(void);           /* after the held code of key 8 */
void FUN_fffe56e4(void);           /* any change while numeric entry is on */
/* a new key after none: the press actions of keys 1..12 */
void msg_slot_key_1(void), msg_slot_key_2(void), msg_slot_key_3(void), msg_slot_key_4(void), msg_slot_key_5(void);
void msg_type_select(void);
void FUN_fffe4f15(void), FUN_fffe4fa9(void), FUN_fffe5000(void), FUN_fffe50e0(void), FUN_fffe5137(void),
     FUN_fffe5138(void);

#define KEY_HELD(n) (0xF0u + (n))  /* the code while key n is held */
#define TMR_MSG_TX_WAIT 0x37       /* a message send's wait (FUN_fffe4efc starts it) [fact: 0xFFFE40C1] */
#define KEY_FILTER_BASE 0x86       /* key_event_filter code of remote key n is 0x86 + n [fact: 0xFFFE3E9E] */

typedef void (*key_action)(void);
/* index n - 1 for key n = 1..12 */
static const key_action key_release[12] = {
    msg_cw_slot_key_1, msg_cw_slot_key_2, msg_cw_slot_key_3, msg_cw_slot_key_4, msg_cw_slot_key_5, FUN_fffe46b0,
    FUN_fffe46d3, FUN_fffe46d4, FUN_fffe46e2, FUN_fffe46e3, FUN_fffe46f1, FUN_fffe46f2,
};
static const key_action key_latched[12] = {
    msg_cw_slot_key_latched_1, msg_cw_slot_key_latched_2, msg_cw_slot_key_latched_3, msg_cw_slot_key_latched_4,
    msg_cw_slot_key_latched_5, FUN_fffe47be, FUN_fffe49fb, FUN_fffe4af8, FUN_fffe4c55, FUN_fffe4d28, FUN_fffe4de3,
    FUN_fffe4de4,
};
static const key_action key_press[12] = {
    msg_slot_key_1, msg_slot_key_2, msg_slot_key_3, msg_slot_key_4, msg_slot_key_5, msg_type_select,
    FUN_fffe4f15, FUN_fffe4fa9, FUN_fffe5000, FUN_fffe50e0, FUN_fffe5137, FUN_fffe5138,
};

/* the code just replaced: what it was decides the action */
static void remote_key_changed(uint8_t last, uint8_t key)
{
    if (last == KEY_HELD(10)) {
        FUN_fffe4c04();
    } else if (last >= 1 && last <= 12) {
        if (key == KEY_HELD(last))
            key_latched[last - 1]();
        else
            key_release[last - 1]();
    } else if (last == KEY_HELD(8)) {
        FUN_fffe4bb3();
    } else if (last == 0 && key >= 1 && key <= 12) {
        key_press[key - 1]();
    }
}

/* ladder_key_task 0xFFFE3E2A: main-loop task 8, nothing while a dialog is shown. A held code that stays repeats its
 * action; a change stops the CW spot tone, or goes to the numeric entry, or (unless the mode locks refuse keys 1..6,
 * key_event_filter) runs the change's action and remembers the new code (remote_key_last 0x1B554). Then the message
 * send's wait ends when soft timer 0x37 expires. */
void ladder_key_task(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr4;
    uint8_t key;

    if (ui->dialog_shown == 1)
        return;
    key = remote_key_get();
    if (remote_key_last == key) {
        if (key == KEY_HELD(10))
            FUN_fffe4da3();
        else if (key == KEY_HELD(8))
            FUN_fffe4b73();
        else if (key == KEY_HELD(9)) {
            if (ladder_key_delay() == 1)
                FUN_fffe4cc1();
        } else if (key == KEY_HELD(7) && ladder_key_delay() == 1)
            FUN_fffe4a67();
    } else {
        if (g_ui.cw_spot_on == 1) {
            g_ui.cw_spot_on = 0;
            beep_stop();
            return;
        }
        if (ui->numentry_mode == 1) {
            FUN_fffe56e4();
            remote_key_last = key;
            return;
        }
        if (key >= 1 && key <= 6 && key_event_filter((uint16_t)(key + KEY_FILTER_BASE), 1) == 0)
            return;
        remote_key_changed(remote_key_last, key);
        ladder_delay_armed = 0;             /* ladder_key_delay starts again */
        remote_key_last = key;
    }
    if (ui->msg_tx_wait == 1 && swtimer_expired(TMR_MSG_TX_WAIT) == 1) {
        ui->msg_tx_wait = 0;
        ui->dvs_busy = 0;
        ui->dvs_armed = 0;
        ui->msg_slot = 0;
        ui->keyer_state = 0;
    }
}
