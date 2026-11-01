/* Pieces of the CW keyer of the MAIN image, recreated for T24 (docs/code/main/radio-control.md, eeprom.md "Message
 * memory"): the state reset and the element ring index. keyer_task and the element generator are not recreated
 * yet. */
#include "main.h"
#include "main_ram.h"

#define KEYER_RING_LEN 0x500u   /* element ring index range [fact: keyer_ring_next 0xFFFBB175] */

/* keyer_init 0xFFFB98C8: keyer idle (UI +0x2B), no message, element state 0x120BC.. cleared (0xA0 bytes) */
void keyer_init(void)
{
    uint8_t *p = keyer_state;
    uint32_t n = 0xA0u;

    g_ui_keyer_state = 0;
    keyer_msg_active = 0;
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
