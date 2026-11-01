/* The antenna-tuner dispatch of the MAIN image, recreated for T24 (docs/code/main/radio-control.md): which tuner
 * task runs follows the TUNER SELECT menu (0x9AB8), and the internal tuner's two relay bytes. */
#include "main.h"
#include "main_ram.h"

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

/* atu_ac_get 0xFFFEC500, atu_tc_get 0xFFFEC50F: the internal tuner's AC and TC relay bytes (/SST6) */
uint8_t atu_ac_get(void)
{
    return atu_ac;
}

uint8_t atu_tc_get(void)
{
    return atu_tc;
}
