/* The antenna-tuner dispatch of the MAIN image, recreated for T24 (docs/code/main/radio-control.md): which tuner
 * task runs follows the TUNER SELECT menu (0x9AB8), and the internal tuner's two relay bytes (round 2); the
 * internal, external and ATAS tuner tasks and tuner_rearm (round 4). */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

/* TUNER SELECT value of the ATAS task [fact: the compares in tuner_task 0xFFFEC473; the names of the tasks are the
 * Ghidra names] */
#define TUNER_ATAS 3u

/* tuner_task 0xFFFEC473: main-loop task; 0/1 internal, 3 ATAS, other external */
void tuner_task(void)
{
    uint8_t sel = menu_tuner_select;

    if (sel == TUNER_ATAS)
        tuner_atas_task();
    else if (sel > 1u)
        tuner_ext_task();
    else
        tuner_int_task();
}

/* tuner_init 0xFFFEC46C */
void tuner_init(void)
{
    tuner_task();
    tuner_rearm();
}

uint8_t blink_phase(int32_t which);       /* 0 / 1, the phase of a blinking indicator */
uint8_t vfo_tuner_bit_get(void);          /* bit 2 of the TX VFO record's flags1: the tuner is on for the VFO */
uint8_t FUN_fffed6f5(void);               /* 1 = the external tuner may be armed (tuner_rearm) */
void FUN_fffed399(void);                  /* ATAS: tune cycle 1 */
void FUN_fffed2a9(void);                  /* ATAS: tune cycle 2 */
/* the internal-tuner steps (tuner_int_task) and the external-tuner steps (tuner_ext_task) */
void FUN_fffec70a(void);
void FUN_fffec728(void);
void FUN_fffec7f9(void);
void FUN_fffec881(void);
void FUN_fffec8a1(void);
void FUN_fffec911(void);
void FUN_fffec9b4(void);
void FUN_fffeca48(void);
void FUN_fffeca7e(void);
void FUN_fffecba2(void);
void FUN_fffecce7(void);
void FUN_fffecde6(void);
void FUN_fffece39(void);
void FUN_fffece69(void);
void FUN_fffece79(void);
void FUN_fffec9ed(void);
void FUN_fffed704(void);
void FUN_fffed72b(void);
void FUN_fffed753(void);
void FUN_fffed796(void);
void FUN_fffed7f3(void);
void FUN_fffed8ab(void);
void FUN_fffed8fc(void);
void FUN_fffed934(void);
void FUN_fffed983(void);
void FUN_fffed9b3(void);
void FUN_fffeda3b(void);
void FUN_fffeda96(void);
void FUN_fffedab0(void);
void FUN_fffedac0(void);
void FUN_fffedae4(void);

/* the tuner indicator: on, and off in the dark phase of the blink while the cycle runs (2) */
static void tuner_indicator_set(uint8_t on, uint8_t cycle)
{
    g_ui.tuner_indicator = 0;
    if (on) {
        g_ui.tuner_indicator = 1;
        if (cycle == 2 && blink_phase(0) == 0)
            g_ui.tuner_indicator = 0;
    }
}

/* tuner_int_task 0xFFFEC62B: TUNER SELECT 0/1 (internal tuner): the indicator while atu_state is 1 or 2, then one
 * step of the internal tuner by int_tuner_step (the switch 0xFFFEC6B8; 6/10, 7/11, 0x14/0x15 share a step) */
void tuner_int_task(void)
{
    tuner_indicator_set(g_ui.atu_state == 2 || g_ui.atu_state == 1, g_ui.tune_cycle_3d);
    switch (int_tuner_step) {
    case 1: FUN_fffec728(); break;
    case 2: FUN_fffec7f9(); break;
    case 3: FUN_fffec881(); break;
    case 4: FUN_fffec8a1(); break;
    case 5: FUN_fffec911(); break;
    case 6: case 10: FUN_fffec9b4(); break;
    case 7: case 11: FUN_fffeca48(); break;
    case 8: FUN_fffeca7e(); break;
    case 9: FUN_fffecba2(); break;
    case 12: FUN_fffecce7(); break;
    case 13: FUN_fffecde6(); break;
    case 14: FUN_fffece39(); break;
    case 15: FUN_fffece69(); break;
    case 16: FUN_fffece79(); break;
    case 0x14: case 0x15: FUN_fffec9ed(); break;
    default: FUN_fffec70a(); break;
    }
}

/* tuner_ext_task 0xFFFED62A: TUNER SELECT 2 (external tuner), only with the TUN/LIN port in EXT-TUNER mode (0): the
 * indicator while atu_state is 5, then one step by ext_tuner_step (the switch 0xFFFED6A6; 1/4 and 2/5 share) */
void tuner_ext_task(void)
{
    g_ui.tuner_indicator = 0;
    if (tunlin_port_mode() != 0)
        return;
    tuner_indicator_set(g_ui.atu_state == 5, g_ui.tune_cycle_3c);
    switch (ext_tuner_step) {
    case 1: case 4: FUN_fffed72b(); break;
    case 2: case 5: FUN_fffed753(); break;
    case 3: FUN_fffed796(); break;
    case 6: FUN_fffed7f3(); break;
    case 7: FUN_fffed8ab(); break;
    case 8: FUN_fffed8fc(); break;
    case 9: FUN_fffed934(); break;
    case 10: FUN_fffed983(); break;
    case 11: FUN_fffed9b3(); break;
    case 12: FUN_fffeda3b(); break;
    case 13: FUN_fffeda96(); break;
    case 14: FUN_fffedab0(); break;
    case 15: FUN_fffedac0(); break;
    case 16: FUN_fffedae4(); break;
    default: FUN_fffed704(); break;
    }
}

/* tuner_atas_task 0xFFFED165: TUNER SELECT 3 (ATAS). While a result is shown (tuner_result_hold) it waits for soft
 * timer 0x22 and clears the result; otherwise every 5 ticks of timer 0x21 it runs the tune cycle's step (1 or 2;
 * any other cycle clears the result) with the indicator 2 blinking. */
void tuner_atas_task(void)
{
    if (tuner_result_hold == 1) {
        if (swtimer_expired(0x22) == 1) {
            tuner_result_hold = 0;
            g_ui.tuner_result = 0;
        }
        return;
    }
    if (swtimer_expired(0x21) == 0)
        return;
    swtimer_start(0x21, 5);
    g_ui.tuner_indicator = 2;
    if (g_ui.tune_cycle == 1) {
        FUN_fffed399();
    } else if (g_ui.tune_cycle == 2) {
        FUN_fffed2a9();
    } else {
        g_ui.tuner_result = 0;
        return;
    }
    if (blink_phase(0) == 0)
        g_ui.tuner_indicator = 0;
}

/* tuner_rearm 0xFFFEC578: after a VFO / band change, the tuner state follows the VFO's tuner bit: internal tuner
 * (SELECT 0/1) atu_state 0 -> 1 when on, 1/2 -> 3 when off; external (SELECT 2, when FUN_fffed6f5 allows) 0 -> 4,
 * 4/5 -> 6 */
void tuner_rearm(void)
{
    uint8_t sel = g_opstate.ex030104_tuner_type_select;

    if (sel == 2) {
        if (FUN_fffed6f5() != 1)
            return;
        if (vfo_tuner_bit_get() == 0) {
            if (g_ui.atu_state == 4 || g_ui.atu_state == 5)
                g_ui.atu_state = 6;
        } else if (g_ui.atu_state == 0) {
            g_ui.atu_state = 4;
        }
    } else if (sel < 2) {
        if (vfo_tuner_bit_get() == 0) {
            if (g_ui.atu_state == 1 || g_ui.atu_state == 2)
                g_ui.atu_state = 3;
        } else if (g_ui.atu_state == 0) {
            g_ui.atu_state = 1;
        }
    }
}

/* atu_ac_get 0xFFFEC500, atu_tc_get 0xFFFEC50F: the internal tuner's AC and TC relay bytes (/SST6) */
uint8_t atu_ac_get(void)
{
    return atu_ac;
}

uint8_t atu_tc_get(void)
{
    return atu_tc;
}
