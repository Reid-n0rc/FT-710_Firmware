/* Small main-loop tasks of the MAIN image (T24 round 4; docs/code/main/README.md "Main loop"): the watchdog kick,
 * the RF control pass, the I/O and power supervisor, the scan and the E8 request task. main_loop itself (0xFFF94B8B, the
 * 16 tasks in an endless loop) is not recreated: it never returns, so the equivalence check cannot decide it. */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

void iwdt_refresh(void);
void pa_relay_update(void);
void rf_bpf_update(void);
void atu_relay_update(void);
void main_dac_update(void);
void pa_dac_update(void);
void audio_level_update(void);
void meter_task(void);
void io_poll(void);
void lamp_map_update(void);
void FUN_fffb9605(void);
void menu_cursors_save(void);
void sw_reset(void);
uint8_t screensaver_timer_expired(void);
uint8_t sci1_tx_end(void);
void dispreq_e8_result(void);
void FUN_fffe3615(void);

#define TMR_AF_MUTE 0x2A          /* the AF mute follows PB3 when it has expired */
#define PWR_KEY_OFF 2u            /* g_ui.power_key_req: the power key asks for power off */

/* wdt_kick 0xFFFB3E6A: main-loop task 1 (also the power-off loop) */
void wdt_kick(void)
{
    iwdt_refresh();
}

/* rf_ctrl_task 0xFFFB55C2: main-loop task 5: the PA relays, RF BPF, ATU relays, DACs and audio levels, each
 * written when it changed; rf_ctrl_ready after the first pass */
void rf_ctrl_task(void)
{
    pa_relay_update();
    rf_bpf_update();
    atu_relay_update();
    main_dac_update();
    pa_dac_update();
    audio_level_update();
    if (rf_ctrl_ready == 0)
        rf_ctrl_ready = 1;
}

/* io_task 0xFFFB6D56: main-loop task 2: in RX (state 8) the AF mute follows PB3 once soft timer 0x2A has expired;
 * the meters, the GPIO poll, the lamps; then, unless the supply is too low, the power key's power off (save the
 * operating state unless in alignment mode, wait for SCI1, software reset) and the screen saver's toggle request */
void io_task(void)
{
    if (swtimer_expired(TMR_AF_MUTE) != 0 && af_mute_get() != g_ui.pb3_last && g_ui.trx_state == 8)
        af_mute_set(g_ui.pb3_last);
    meter_task();
    io_poll();
    lamp_map_update();
    FUN_fffb9605();
    if (supply_undervolt_check() == 1)
        return;
    if (g_ui.power_key_req == PWR_KEY_OFF) {
        g_opstate.auto_power_on = 0;
        menu_cursors_save();
        if (g_ui.zz_align_mode == 0)
            eeprom_save_opstate();
        while (sci1_tx_end() == 0)
            ;
        sw_reset();
    }
    if (screensaver_timer_expired() == 1) {
        if (g_ui.screensaver_on == 0)
            g_ui.screensaver_toggle_req = 1;
    } else if (g_ui.screensaver_on != 0) {
        g_ui.screensaver_toggle_req = 1;
    }
}

/* the scan's helpers; the predicates return 0 or 1 [fact: each call site compares R1 with 0 or 1] */
void FUN_fffe61ca(void);
void FUN_fffe5a1a(void);                  /* (re)start the scan step */
void FUN_fffe5e67(void);
void FUN_fffe5a47(void);
void FUN_fffe5a2a(void);                  /* stop the scan */
int32_t FUN_fffe5ee3(void);
int32_t FUN_fffe5ab2(void);
int32_t FUN_fffe5acf(void);
int32_t FUN_fffe5fdd(void);
int32_t FUN_fffe600f(void);
int32_t FUN_fffe5ae7(void);
int32_t FUN_fffe5f18(void);
int32_t FUN_fffe5f4d(void);

/* scan_task 0xFFFE587F: main-loop task 9, the scan state machine scan_state 0..7 (the switch 0xFFFE58C8) while a
 * scan runs and the radio is not in alignment mode; states 2 -> 3 hold on a busy channel (timer 0x33, 500),
 * 4 <-> 5 and 6 <-> 7 wait to resume (timer 0x34, 1500) */
void scan_task(void)
{
    struct ui_state *ui = (struct ui_state *)g_ui_ptr3;

    FUN_fffe61ca();
    if (ui->scan_running == 0 || ui->zz_align_mode == 1)
        return;
    switch (scan_state) {
    case 0:
        ui->scan_hold = 0;
        FUN_fffe5a1a();
        return;
    case 1:
        if (FUN_fffe5ee3() != 1)
            return;
        if (FUN_fffe5ab2() == 0) {
            ui->scan_hold = 0;
            FUN_fffe5e67();
            scan_state = 2;
        } else {
            ui->scan_hold = 1;
            FUN_fffe5a1a();
        }
        return;
    case 2:
        if (FUN_fffe5ee3() != 1)
            return;
        if (FUN_fffe5acf() == 0)
            FUN_fffe5a47();
        else if (FUN_fffe5ab2() == 0 || FUN_fffe5fdd() == 0 || FUN_fffe600f() != 1)
            FUN_fffe5a2a();
        else {
            scan_busy_wait = 1;
            swtimer_start(0x33, 500);
            scan_state = 3;
        }
        return;
    case 3:
        if (FUN_fffe5ee3() != 1)
            return;
        if (FUN_fffe5acf() == 1)
            FUN_fffe5a2a();
        else
            FUN_fffe5a47();
        return;
    case 4:
        if (FUN_fffe5ae7() == 1) {
            scan_resume_wait = 1;
            swtimer_start(0x34, 1500);
            scan_state = 5;
        }
        return;
    case 5:
        if (FUN_fffe5f18() == 1)
            FUN_fffe5a2a();
        else if (FUN_fffe5ae7() == 0)
            scan_state = 4;
        return;
    case 6:
        if (FUN_fffe5f4d() == 1) {
            FUN_fffe5a2a();
        } else if (FUN_fffe5ae7() == 1) {
            scan_resume_wait = 1;
            swtimer_start(0x34, 1500);
            scan_state = 7;
        }
        return;
    case 7:
        if (FUN_fffe5f4d() == 1 || FUN_fffe5f18() == 1)
            FUN_fffe5a2a();
        else if (FUN_fffe5ae7() == 0)
            scan_state = 6;
        return;
    default:
        return;
    }
}

/* dispreq_e8_task 0xFFFE360E: main-loop task 10: the E8 status of the DISPLAY's audio screens, then
 * FUN_fffe3615 */
void dispreq_e8_task(void)
{
    dispreq_e8_result();
    FUN_fffe3615();
}
