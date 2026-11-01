/* Beeps and side tones of the MAIN image (T24 MAIN round 5; docs/code/main/peripherals.md "DA tone"): beep_task, the
 * main-loop task that plays a requested pattern of tones on soft timer 0x16, its request / stop / query calls, and
 * tone_set, which sets the TPU1 period for a 36-sample tone table played into DA0. The tone frequencies are the
 * image's float constants (each decimal below rounds to the bits at the cited instruction). */
#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"
#include "iodefine.h"

void tone_play(const uint16_t *table, uint16_t n);
void tone_stop(void);
void dac0_write(uint16_t v);

#define TMR_BEEP 0x16             /* the soft timer of every tone and pause [fact: 0xFFFB2914, 0xFFFB2E91] */
#define TONE_SAMPLES 36           /* samples per cycle in tone_table [fact: 0xFFFB2E82] */
#define TONE_FOREVER 0xFFFF       /* the RTTY test tones hold until stopped */

/* beep_state 0x12040 [fact: beep_task's compares] */
enum beep_state { BEEP_IDLE = 0, BEEP_START = 1, BEEP_PLAYING = 2, BEEP_STOP = 3 };

/* beep_pattern 0x12041: what beep_request(n) asked for. The tones [fact: the constants of each case]: */
enum beep_pattern {
    BEEP_NONE = 0,
    BEEP_SHORT = 1,               /* 880 Hz 100 ms */
    BEEP_DOUBLE = 2,              /* 880, pause, 880 */
    BEEP_TRIPLE_HIGH = 3,         /* 3 x 1046.5 Hz (C6) with 100 ms pauses */
    BEEP_CW_PITCH = 4,            /* the CW pitch (menu x 10 + 300 Hz) while requested */
    BEEP_RISING = 5,              /* C6, E6, G6 */
    BEEP_FALLING = 6,             /* G5, E5 */
    BEEP_FIVE = 7,                /* 5 x 1318.5 Hz (E6) */
    BEEP_RESTART = 8,             /* 3 x C6 with 70 ms pauses, then the restart request */
    BEEP_RTTY_MARK = 9,           /* the RTTY mark tone (MARK FREQUENCY) until stopped */
    BEEP_RTTY_SHIFT = 10,         /* the SHIFT FREQUENCY itself */
    BEEP_RTTY_SPACE = 11,         /* mark + shift */
};

#define F_A5 880.0f               /* 0x445C0000 [fact: 0xFFFB294B] */
#define F_C6 1046.502f            /* 0x4482D010 [fact: 0xFFFB29D2] */
#define F_E6 1318.51f             /* 0x44A4D052 [fact: 0xFFFB2AA0] */
#define F_G6 1567.982f            /* 0x44C3FF6D [fact: 0xFFFB2AB7] */
#define F_G5 783.991f             /* 0x4443FF6D [fact: 0xFFFB2AEA] */
#define F_E5 659.255f             /* 0x4424D052 [fact: 0xFFFB2B01] */
#define F_PAUSE 0.0f              /* tone_set(0, ms): only the timer runs */

/* the RTTY test tones: MARK FREQUENCY 1275 / 2125 Hz, SHIFT FREQUENCY 170 / 200 / 425 / 850 Hz [fact: 0xFFFB2C5B,
 * 0xFFFB2CA6..0xFFFB2CBD] */
static float rtty_mark(void)
{
    return g_opstate.ex010515_mark_frequency == 0 ? 1275.0f : 2125.0f;
}

static float rtty_shift(void)
{
    switch (g_opstate.ex010516_shift_frequency) {
    case 1: return 200.0f;
    case 2: return 425.0f;
    case 3: return 850.0f;
    default: return 170.0f;
    }
}

/* beep_request 0xFFFB2DA6: start pattern n; the restart pattern always wins, an RTTY test tone replaces only the CW
 * pitch tone, anything else waits until no pattern is set. (A request >= 12 first clears the pattern, then stores
 * it anyway, 0xFFFB2DD0..0xFFFB2DE5.) */
void beep_request(int32_t n)
{
    if (n != BEEP_RESTART) {
        if ((uint32_t)(n - BEEP_RTTY_MARK) <= 2) {
            if (beep_pattern == BEEP_CW_PITCH)
                return;
        } else if (beep_pattern != BEEP_NONE) {
            return;
        }
    }
    beep_pattern = (uint8_t)n;
    beep_state = BEEP_START;
}

/* beep_stop 0xFFFB2DF4 */
void beep_stop(void)
{
    beep_state = BEEP_STOP;
}

/* FUN_fffb2dfe 0xFFFB2DFE: the requested pattern (keyer_task stubs it as a gate) */
uint8_t FUN_fffb2dfe(void)
{
    return beep_pattern;
}

/* tone_idle 0xFFFB2E0D: stop the tone and leave DA0 at the table's first sample */
void tone_idle(void)
{
    tone_stop();
    dac0_write(tone_table[0]);
}

/* tone_set 0xFFFB2E1E: play f Hz (30..20000; 0 = silence) for ms milliseconds. TPU1 counts PCLK = 60 MHz and
 * steps one table sample per compare match, so TGRA = 1 / (36 f / 60e6) - 1, converted with FTOU [fact:
 * 0xFFFB2E56..0xFFFB2E80; in range the signed conversion gives the same 16 bits, and a NaN gives 0xFFFF or 0 either
 * way]. A frequency out of range plays nothing and starts no timer. */
void tone_set(float f, uint16_t ms)
{
    if (f != 0.0f) {
        if (f < 30.0f || f > 20000.0f)
            return;
        float period = 1.0f / (f * 36.0f / 60000000.0f);
        TPU1_TGRA = (uint16_t)(int32_t)(period + -1.0f);
        tone_play(tone_table, TONE_SAMPLES);
    }
    swtimer_start(TMR_BEEP, ms);
}

/* the patterns of n tone/pause steps: step k plays tones[k] (F_PAUSE for a pause) for ms[k]; the step after the last
 * stops the pattern */
static void play_step(const float *tones, const uint8_t *ms, uint8_t n)
{
    if (beep_step < n)
        tone_set(tones[beep_step], ms[beep_step]);
    else
        beep_stop();
    beep_step++;
}

/* beep_task 0xFFFB28E2: main-loop task 6. START silences DA0 and goes to PLAYING; PLAYING runs the pattern's next
 * step each time soft timer 0x16 expires; STOP silences and clears the request. */
void beep_task(void)
{
    if (beep_state == BEEP_START) {
        tone_idle();
        beep_step = 0;
        beep_state = BEEP_PLAYING;
        return;
    }
    if (beep_state == BEEP_PLAYING) {
        if (swtimer_expired(TMR_BEEP) != 1)
            return;
        switch (beep_pattern) {
        case BEEP_SHORT:
            if (beep_step == 0) {
                tone_set(F_A5, 100);
                beep_step++;
            } else {
                beep_stop();
            }
            break;
        case BEEP_DOUBLE: {
            static const float t[] = {F_A5, F_PAUSE, F_A5};
            static const uint8_t ms[] = {100, 10, 100};
            play_step(t, ms, 3);
            break;
        }
        case BEEP_TRIPLE_HIGH: {
            static const float t[] = {F_C6, F_PAUSE, F_C6, F_PAUSE, F_C6};
            static const uint8_t ms[] = {100, 100, 100, 100, 100};
            play_step(t, ms, 5);
            break;
        }
        case BEEP_CW_PITCH: {
            /* the same pitch keeps running: only the timer is restarted [fact: 0xFFFB2A45 FCMP, BEQ] */
            float f = (float)g_opstate.cw_pitch * 10.0f + 300.0f;
            if (beep_cw_freq == f) {
                swtimer_start(TMR_BEEP, 100);
            } else {
                beep_cw_freq = f;
                tone_set(f, 100);
            }
            break;
        }
        case BEEP_RISING: {
            static const float t[] = {F_C6, F_PAUSE, F_E6, F_PAUSE, F_G6};
            static const uint8_t ms[] = {100, 10, 100, 10, 100};
            play_step(t, ms, 5);
            break;
        }
        case BEEP_FALLING: {
            static const float t[] = {F_G5, F_PAUSE, F_E5};
            static const uint8_t ms[] = {100, 10, 100};
            play_step(t, ms, 3);
            break;
        }
        case BEEP_FIVE: {
            static const float t[] = {F_E6, F_PAUSE, F_E6, F_PAUSE, F_E6, F_PAUSE, F_E6, F_PAUSE, F_E6};
            static const uint8_t ms[] = {100, 40, 100, 20, 100, 20, 100, 20, 100};
            play_step(t, ms, 9);
            break;
        }
        case BEEP_RESTART:
            /* three C6 tones, silence at step 5, then the restart request [fact: 0xFFFB2BBA..0xFFFB2C3C] */
            if (beep_step == 5) {
                tone_idle();
            } else if (beep_step < 5) {
                static const float t[] = {F_C6, F_PAUSE, F_C6, F_PAUSE, F_C6};
                static const uint8_t ms[] = {100, 70, 100, 70, 100};
                tone_set(t[beep_step], ms[beep_step]);
            } else {
                beep_stop();
                g_ui.restart_req = 1;
            }
            beep_step++;
            break;
        case BEEP_RTTY_MARK:
        case BEEP_RTTY_SHIFT:
        case BEEP_RTTY_SPACE:
            /* a test tone already started holds on (timer only) */
            if (beep_last_pattern == beep_pattern) {
                swtimer_start(TMR_BEEP, TONE_FOREVER);
            } else {
                float f = beep_pattern == BEEP_RTTY_MARK ? rtty_mark()
                        : beep_pattern == BEEP_RTTY_SHIFT ? rtty_shift() : rtty_mark() + rtty_shift();
                tone_set(f, TONE_FOREVER);
            }
            break;
        default:
            beep_stop();
            break;
        }
        beep_last_pattern = beep_pattern;
        return;
    }
    if (beep_state == BEEP_STOP) {
        tone_idle();
        beep_state = BEEP_IDLE;
        beep_pattern = BEEP_NONE;
        beep_cw_freq = 0.0f;
        beep_last_pattern = 0;
    }
}
