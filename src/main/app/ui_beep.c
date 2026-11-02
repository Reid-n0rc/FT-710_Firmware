/* The beep requests and the tone generator set-up of the MAIN image (T24, UI track). beep_task 0xFFFB28E2 plays the
 * pattern in beep_pattern (0x12041) when beep_state (0x12040) is 1 [inference: the names.tsv plate comment of
 * beep_task and the stores below]; beep_task itself is not recreated (its float constants and FCMPs wait for the FPU
 * semantics check, T24 MAIN round 4). */
#include <stdint.h>
#include "main.h"
#include "iodefine.h"

extern uint8_t beep_state;               /* 0x12040: 1 = start the requested pattern, 3 = stop */
extern uint8_t beep_pattern;             /* 0x12041: pattern number of the current beep */
extern uint16_t tone_idle_level;         /* 0x1FF1C: DA0 value between tones */

void tone_stop(void);
void tone_play(uint16_t *level, uint32_t n);
void dac0_write(uint16_t v);

#define BEEP_START 1u
#define BEEP_STOP 3u
#define TMR_TONE 22                       /* tone_set: the tone's length [fact: swtimer_start(22, ms)] */

/* beep_request 0xFFFB2DA6 (pattern): pattern 8 always starts; 9..11 do not start while pattern 4 plays; the others
 * only when no pattern is set (0) [fact]. A pattern >= 12 clears the pattern first, which the next store overwrites
 * (0xFFFB2DD4) */
void beep_request(int32_t pattern)
{
    if (pattern != 8) {
        if ((uint32_t)(pattern - 9) <= 2) {
            if (beep_pattern == 4)
                return;
        } else if (beep_pattern != 0) {
            return;
        }
    }
    if (pattern >= 12)
        beep_pattern = 0;
    beep_pattern = (uint8_t)pattern;
    beep_state = BEEP_START;
}

/* beep_stop 0xFFFB2DF4 [fact] */
void beep_stop(void)
{
    beep_state = BEEP_STOP;
}

/* FUN_fffb2dfe: the current pattern [fact]; keyer_task waits for 0 (T24 round 4 stubs it) */
uint8_t beep_pattern_get(void)
{
    return beep_pattern;
}

/* tone_idle 0xFFFB2E0D: tone_stop, then DA0 back to the idle level [fact] */
void tone_idle(void)
{
    tone_stop();
    dac0_write(tone_idle_level);
}

/* tone_set 0xFFFB2E1E (hz, ms): for 30 <= hz <= 20000 TPU1.TGRA (0x88128) = 1 / (hz x 36 / 60 MHz) - 1
 * (FTOU) and tone_play(&tone_idle_level, 36); outside that range nothing; hz = 0 only the timer; then soft timer 22 =
 * ms [fact] */
void tone_set(float hz, uint16_t ms)
{
    if (hz != 0.0f) {
        if (hz < 30.0f || !(20000.0f >= hz))
            return;
        float period = 1.0f / (hz * 36.0f / 60000000.0f);
        register float in __asm__("r1") = period + -1.0f;
        register uint32_t out __asm__("r14");
        __asm__(".byte 0xfc, 0xa7, 0x1e" : "=r"(out) : "r"(in));      /* FTOU R1, R14 (RXv2) */
        TPU1_TGRA = (uint16_t)out;
        tone_play(&tone_idle_level, 36);
    }
    swtimer_start(TMR_TONE, ms);
}
