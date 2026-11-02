/* The front-panel meters of the MAIN image (T24, UI track): VDD, IDD (ID), ALC, PO, COMP and S from the A/D results
 * and the DSP, each through a 16-sample moving average, the meter getters, and the remote keypad (REM_KEY) scan.
 * meter_task 0xFFFB73DD runs them: every 5 ms the A/D scan and swr_meter_protect (SWR and HI-SWR, not recreated here),
 * every 10 ms the six meters and the keypad [fact]. docs/code/main/tx-protection.md lists the meter globals
 * 0x12043..0x1204C.
 *
 * The float arithmetic follows the image operation by operation (CC-RX -dbl_size=4: every constant is a float); the
 * results are compared on the module's p-code for FADD/FSUB/FMUL/FDIV/FCMP, whose agreement with the RX FPU is not yet
 * checked (T24 MAIN round 4, "FPU instructions other than the conversions are unverified"). */
#include <stdint.h>
#include "main.h"
#include "ft710_state.h"
#include "ui.h"

/* meter values 0..255 (src/main/data_symbols.tsv) */
extern uint8_t meter_vdd_val;          /* 0x12043 */
extern uint8_t meter_idd_val;          /* 0x12044 */
extern uint8_t meter_alc_val;          /* 0x12045 */
extern uint8_t meter_swr_val;          /* 0x12046 */
extern uint8_t meter_swr_raw_val;      /* 0x12047 */
extern uint8_t meter_po_val;           /* 0x12048: average */
extern uint8_t meter_comp_val;         /* 0x12049 */
extern uint8_t meter_s_val;            /* 0x1204A */
extern uint8_t meter_po_peak;          /* 0x1204B: highest of the 16 PO samples */
extern uint8_t remote_key;             /* 0x1204C */
extern float meter_swr_f;              /* 0x20FC4 */
extern float meter_swr_avg_f;          /* 0x20FC8 */
extern float vdd_scale;                /* 0x20FC0 */
extern uint8_t remote_key_count;       /* 0x1B4C8: scans with the same key, up to 101 */
extern uint8_t remote_key_last;        /* 0x1B4C9: key 1..12 of the last window hit */
/* 16-sample rings {samples, index} (one per meter) */
struct meter_ring { uint8_t s[16]; uint8_t idx; };
extern struct meter_ring meter_ring_vdd;   /* 0x12052 */
extern struct meter_ring meter_ring_idd;   /* 0x12063 */
extern struct meter_ring meter_ring_alc;   /* 0x12074 */
extern struct meter_ring meter_ring_swr;   /* 0x12085 */
extern uint8_t meter_ring_swr_f_idx;       /* 0x12096 */
extern float meter_ring_swr_f[16];         /* 0x20FD0 */
extern struct meter_ring meter_ring_po;    /* 0x12097 */
extern struct meter_ring meter_ring_s;     /* 0x120A8 */
/* ROM tables */
struct meter_po_seg { float watts_min, slope, offset; };
struct meter_s_seg { float slope, offset, level_max; };
extern const struct meter_po_seg meter_po_curve[8];     /* 0xFFF88C74: from 100 W down to 0 W */
extern const struct meter_s_seg meter_s_curve[10];      /* 0xFFF88BFC: by (S cal - DSP level) */
extern const uint8_t remote_key_windows[12][2];         /* 0xFFF815AB: A/D window (low, high) per key */

/* FTOU Rs, Rd (RXv2, round towards zero, as an unsigned value); GCC for RXv1 has no such instruction and its unsigned
 * cast calls __fixunssfsi, so the encoding is written out: FC A7 rs:rd with R14 -> R1 */
static inline uint32_t ftou(float f)
{
    register float in __asm__("r14") = f;
    register uint32_t out __asm__("r1");
    __asm__(".byte 0xfc, 0xa7, 0xe1" : "=r"(out) : "r"(in));
    return out;
}

/* --- getters 0xFFFB6E03..0xFFFB6EC3 [fact: each loads its byte] --- */
uint8_t meter_get_vdd(void) { return meter_vdd_val; }
uint8_t meter_get_idd(void) { return meter_idd_val; }
uint8_t meter_get_alc(void) { return meter_alc_val; }
uint8_t meter_get_swr(void) { return meter_swr_val; }
uint8_t meter_get_swr_raw(void) { return meter_swr_raw_val; }
/* FUN_fffb6e4e / FUN_fffb6e5c: the float SWR and its 16-sample average (as their bits in R1) */
float meter_get_swr_f(void) { return meter_swr_f; }
float meter_get_swr_avg_f(void) { return meter_swr_avg_f; }

/* meter_get_po 0xFFFB6E6A: METER DETECTOR (EX030408) 0 = the average, else the peak of the 16 samples [fact: the
 * test of 0x9AF6; the menu name is the menu table's] */
uint8_t meter_get_po(void)
{
    return g_opstate.ex030408_meter_detector == 0 ? meter_po_val : meter_po_peak;
}

uint8_t meter_get_comp(void) { return meter_comp_val; }
uint8_t meter_get_s(void) { return meter_s_val; }
uint8_t remote_key_get(void) { return remote_key; }

/* --- the moving averages 0xFFFB92E7..0xFFFB959C: the sample into the ring, the mean of the 16 (sum in 16 bits)
 * [fact] --- */

static uint8_t ring_mean(struct meter_ring *r, uint8_t v)
{
    r->s[r->idx] = v;
    r->idx++;
    if (r->idx > 15)
        r->idx = 0;
    uint16_t sum = 0;
    for (uint8_t i = 0; i < 16; i++)
        sum = (uint16_t)(sum + r->s[i]);
    return (uint8_t)(sum >> 4);
}

uint8_t meter_avg_vdd(uint8_t v) { return ring_mean(&meter_ring_vdd, v); }
uint8_t meter_avg_idd(uint8_t v) { return ring_mean(&meter_ring_idd, v); }
uint8_t meter_avg_alc(uint8_t v) { return ring_mean(&meter_ring_alc, v); }
uint8_t meter_avg_swr(uint8_t v) { return ring_mean(&meter_ring_swr, v); }
uint8_t meter_avg_s(uint8_t v) { return ring_mean(&meter_ring_s, v); }

/* FUN_fffb94f9: the PO mean, and the peak of the ring into 0x1204B [fact] */
uint8_t meter_avg_po(uint8_t v)
{
    struct meter_ring *r = &meter_ring_po;
    r->s[r->idx] = v;
    r->idx++;
    if (r->idx > 15)
        r->idx = 0;
    uint16_t sum = 0;
    for (uint8_t i = 0; i < 16; i++)
        sum = (uint16_t)(sum + r->s[i]);
    meter_po_peak = 0;
    for (uint8_t i = 0; i < 16; i++)
        if (meter_po_peak < r->s[i])
            meter_po_peak = r->s[i];
    return (uint8_t)(sum >> 4);
}

/* FUN_fffb948b (swr): the float SWR into a 16-word ring 0x20FD0; 0x20FC8 = the sum / 16 [fact] */
void meter_avg_swr_f(float swr)
{
    meter_ring_swr_f[meter_ring_swr_f_idx] = swr;
    meter_ring_swr_f_idx++;
    if (meter_ring_swr_f_idx > 15)
        meter_ring_swr_f_idx = 0;
    float sum = 0.0f;
    for (uint8_t i = 0; i < 16; i++)
        sum = meter_ring_swr_f[i] + sum;
    meter_swr_avg_f = sum / 16.0f;
}

/* --- the task --- */

#define TMR_METER_FAST 9      /* 5 ms: A/D scan and SWR [fact: swtimer_start(9, 5)] */
#define TMR_METER 10          /* 10 ms: the meters [fact: swtimer_start(10, 10)] */
#define TMR_AF_MUTE 0x2A      /* meter_s waits for it (the AF mute timer, af_mute_update) */

void adc_scan_blocking(void);
void meter_vdd(void);
void meter_idd(void);
void meter_alc(void);
void meter_po(void);
void meter_comp(void);
void meter_s(void);
void remote_keypad_scan(void);
void vdd_scale_calc(void);

/* meter_task 0xFFFB73DD [fact] */
void meter_task(void)
{
    if (swtimer_expired(TMR_METER_FAST) == 1) {
        swtimer_start(TMR_METER_FAST, 5);
        adc_scan_blocking();
        swr_meter_protect();
    }
    if (swtimer_expired(TMR_METER) == 1) {
        swtimer_start(TMR_METER, 10);
        meter_vdd();
        meter_idd();
        meter_alc();
        meter_po();
        meter_comp();
        meter_s();
        remote_keypad_scan();
    }
}

/* adc_scan_blocking 0xFFFB741E: one S12AD scan, polled until done [fact] */
void adc_scan_blocking(void)
{
    adc_scan_start();
    while (adc_scan_done() != 1)
        ;
}

/* vdd_scale_calc 0xFFFB742B: volts per A/D step: GN VDD MTR / 192 x 0.07176471 / (13.8 / MT VDD MTR POS) (the
 * alignment items 001 and 015 of g_cfg105) [fact: the constants 0x3D92F960, 0x415CCCCD, 0x43400000] */
void vdd_scale_calc(void)
{
    float gain = (float)g_cfg105.a001_gn_vdd_mtr;
    float pos = (float)g_cfg105.a015_mt_vdd_mtr_pos;
    vdd_scale = 0.07176471f / (13.8f / pos);
    vdd_scale = gain / 192.0f * vdd_scale;
}

/* meter_vdd 0xFFFB747C: PA VDD A/D (top 8 bits) x vdd_scale, as 16 bits, limited to 255, averaged [fact] */
void meter_vdd(void)
{
    uint8_t ad = (uint8_t)(g_ui.adc_pa_vdd >> 4);
    vdd_scale_calc();
    uint16_t v = (uint16_t)ftou((float)ad * vdd_scale);
    if (v > 255)
        v = 255;
    meter_vdd_val = meter_avg_vdd((uint8_t)v);
}

/* meter_idd 0xFFFB74B8 / meter_alc 0xFFFB74FF: A/D (top 8 bits) x MT pos / TX cal (alignment items 016 / 261, 014 /
 * 246), as 16 bits, limited to 255, averaged [fact]. The divisor is not tested for 0: DIVU as in the image */
void meter_idd(void)
{
    uint8_t ad = (uint8_t)(g_ui.adc_pa_idd >> 4);
    uint8_t div = g_cfg105.a261_tx_idd_mtr, pos = g_cfg105.a016_mt_idd_mtr_pos;
    uint16_t v = (uint16_t)((uint32_t)ad * pos / div);
    if (v > 255)
        v = 255;
    meter_idd_val = meter_avg_idd((uint8_t)v);
}

void meter_alc(void)
{
    uint8_t ad = (uint8_t)(g_ui.adc_alcm >> 4);
    uint8_t div = g_cfg105.a246_tx_alc_mtr, pos = g_cfg105.a014_mt_alc_mtr_pos;
    uint16_t v = (uint16_t)((uint32_t)ad * pos / div);
    if (v > 255)
        v = 255;
    meter_alc_val = meter_avg_alc((uint8_t)v);
}

#define BAND_50MHZ 10         /* tx_band_of_freq: 50 MHz, the band with 50 W [inference: the FT-710's 50 W on 6 m] */

/* meter_po 0xFFFB7772: watts from the forward-power A/D: a quadratic through 0 with slope 0.00694025 at the origin
 * and full power (100 W, 50 W on band 10) at the PO scale point (g_ui.po_meter_scale x 16); then the meter position
 * by the first segment of 0xFFF88C74 whose lower bound is <= the watts (slope x W + offset), limited to 255, FTOU,
 * averaged [fact]. Below 0 W no segment applies and the image uses two unset stack words (here 0: the value the
 * check's zeroed stack gives; Open: what the radio's stack holds there, reached only for a negative result) */
void meter_po(void)
{
    const float k = 0.00694025f, zero = 0.0f;
    float ad = (float)g_ui.adc_mcup_for;
    float cal = (float)((uint32_t)g_ui.po_meter_scale << 4);
    float full = tx_band_of_freq(g_ui.freq_tx) == BAND_50MHZ ? 50.0f : 100.0f;
    float a = (full - cal * k - zero) / (cal * cal);
    float w = ad * a * ad + ad * k + zero;
    float slope = 0.0f, offset = 0.0f;
    for (uint8_t i = 0; i < 8; i++) {
        if (!(w < meter_po_curve[i].watts_min)) {
            slope = meter_po_curve[i].slope;
            offset = meter_po_curve[i].offset;
            break;
        }
    }
    float m = slope * w + offset;
    if (!(255.0f >= m))
        m = 255.0f;
    meter_po_val = meter_avg_po((uint8_t)ftou(m));
}

/* meter_comp 0xFFFB7869: the DSP compression value (high byte when the processor level 0x9BF1 is 0, else the low byte)
 * through three lines 0..10 -> 0..103, 10..20 -> 103..190, 20..30 -> 190..248 (and 255 at 31), x / 2, FTOU, 16 bits,
 * limited to 255; not averaged [fact] */
void meter_comp(void)
{
    const float p10 = 103.0f, p20 = 190.0f, p30 = 248.0f;
    float v, m, b;
    if (g_opstate.proc_level == 0)
        v = (float)(dsp_comp_level() >> 8);
    else
        v = (float)(uint8_t)dsp_comp_level();
    if (!(10.0f < v)) {
        m = p10 / 10.0f;
        b = 0.0f;
    } else if (!(20.0f < v)) {
        m = (p20 - p10) / 10.0f;
        b = m * -20.0f + p20;
    } else {
        m = (p30 - p20) / 10.0f;
        b = !(30.0f < v) ? m * -30.0f + p30 : m * -31.0f + 255.0f;
    }
    uint16_t r = (uint16_t)ftou(m * v / 2.0f + b);
    if (r > 255)
        r = 255;
    meter_comp_val = (uint8_t)r;
}

/* meter_s 0xFFFB7959: only after the AF mute timer 0x2A: d = S cal (alignment item 041, RX S MTR) - DSP level, the
 * first segment of 0xFFF88BFC with d <= its bound (else the last), slope x d + offset limited to 0..255; 0 while
 * transmitting, else FTOU and averaged [fact] */
void meter_s(void)
{
    float cal = (float)g_cfg105.a041_rx_s_mtr_40;
    uint8_t level = (uint8_t)dsp_signal_level();
    if (swtimer_expired(TMR_AF_MUTE) == 0)
        return;
    float lv = (float)level;
    float d = cal - lv;
    float slope = meter_s_curve[9].slope, offset = meter_s_curve[9].offset;
    for (uint8_t i = 0; i < 10; i++) {
        if (!(meter_s_curve[i].level_max < d)) {
            slope = meter_s_curve[i].slope;
            offset = meter_s_curve[i].offset;
            break;
        }
    }
    float m = (cal - lv) * slope + offset;
    if (!(m >= 0.0f))
        m = 0.0f;
    else if (!(255.0f >= m))
        m = 255.0f;
    if (g_ui.tx_lamp != 0) {
        meter_s_val = 0;
        return;
    }
    meter_s_val = meter_avg_s((uint8_t)ftou(m));
}

#define REMOTE_KEYS 12
#define REMOTE_KEY_HOLD 0xF0u     /* or'ed into the key after 100 scans (1 s) [fact: 0xFFFB7B19; the time is
                                     100 x the 10 ms of meter_task] */

/* remote_keypad_scan 0xFFFB7A40: the REM_KEY A/D (top 8 bits) inside one of 12 open windows gives key 1..12; on the
 * second scan with a key the key is published in 0x1204C (unless the screen saver is on; the screen-saver timer is
 * restarted either way), on the 100th it gets the hold bits 0xF0; no window clears the key and the count [fact] */
void remote_keypad_scan(void)
{
    uint8_t ad = (uint8_t)(g_ui.adc_rem_key >> 4);
    uint8_t n = REMOTE_KEYS, i;
    for (i = 0; i < n; i++) {
        uint8_t lo = remote_key_windows[i][0], hi = remote_key_windows[i][1];
        if (lo < ad && ad < hi) {
            if (remote_key_last != i + 1)
                remote_key_last = (uint8_t)(i + 1);
            break;
        }
    }
    if (i >= n) {
        remote_key_count = 0;
        remote_key_last = 0;
        remote_key = 0;
        return;
    }
    if (remote_key_count == 2) {
        screensaver_timer_restart();
        if (g_ui.screensaver_on == 0)
            remote_key = remote_key_last;
    } else if (remote_key_count == 100) {
        remote_key |= REMOTE_KEY_HOLD;
    }
    if (remote_key_count <= 100)
        remote_key_count++;
}
