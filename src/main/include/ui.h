/* Recreated MAIN source, T24 UI track: the image's functions that the front-panel input, meter, dial-step and beep
 * code calls (names of decomp/main/functions.tsv; prototypes after tools/ghidra/signatures_main.tsv and the call
 * sites). Kept apart from main.h so that the two T24 tracks do not edit the same lines; a declaration that is also in
 * main.h has the same prototype. */
#ifndef UI_H
#define UI_H

#include <stdint.h>

/* soft timers, pop-ups, beeps */
void swtimer_start(int32_t id, uint16_t n);
uint8_t swtimer_expired(int32_t id);
void screensaver_timer_restart(void);
void beep_request(int32_t kind);

/* meters */
void adc_scan_start(void);
uint8_t adc_scan_done(void);
void swr_meter_protect(void);
uint16_t dsp_comp_level(void);
uint16_t dsp_signal_level(void);
uint8_t tx_band_of_freq(uint32_t f);

#endif
