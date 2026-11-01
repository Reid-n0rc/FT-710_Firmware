/* Recreated MAIN (RX651) source, T24: common types and the functions of the image that the recreated code calls.
 *
 * Names are the Ghidra names of decomp/main/functions.tsv; the prototypes follow tools/ghidra/signatures_main.tsv.
 * A function declared here and not defined in src/main/ is linked to its original address in the image (the
 * equivalence check, tools/equiv_main_emu.py, links every call it does not define to the image). RAM variables
 * are declared in main_ram.h and placed at their original addresses by src/main/data_symbols.tsv. */
#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdint.h>

/* Renesas Code Generator status codes (r_cg_macrodriver.h): the values the drivers return [fact: 0x80/0x81 in
 * R_SCI0_Serial_Send 0xFFF933AE; the names are the Code Generator's, inference from the r_cg_* function names]. */
typedef uint16_t MD_STATUS;
#define MD_OK       0x00u
#define MD_ERROR    0x80u
#define MD_ARGERROR 0x81u

/* CC-RX passes the first four integer arguments in R1..R4 and returns in R1, as GCC's RX ABI does; callers
 * extend char and short arguments (eeprom_read 0xFFFB14BA: movu.w/movu.b before bsr eeprom_spi_tx). */

/* --- CAT link (docs/code/main/cat.md, sci.md) --- */
void cat_rx_complete(int32_t port, uint16_t len);
char *cat_rx_byte_hook(uint16_t *count, uint16_t *length, char *ptr, int32_t timer);
void cat_tx_done_sci0(void);
void cat_tx_done_sci2(void);
void cat_tx_done_sci3(void);
uint8_t tunlin_port_mode(void);
void FUN_fffb1976(void);           /* SCI2 transmit end in tuner mode (sci.md) */
void FUN_fffb1944(void);           /* SCI2 receive end in tuner mode: tuner flag 0xA0A9 (sci.md) */
void sci2_rx_byte_hook(void);      /* SCI2 framing, CAT or tuner (sci.md) */

/* --- other links --- */
void displink_rx_frame_len(void);
void displink_rx_done(void);
void sci4_rx_frame_len(void);
void sci4_rx_set_ready(void);
void sci4_rx_set_len(uint16_t len);
void sdr_rx_done_cb(void);

/* --- soft timers (sci.md "swtimer_start") --- */
void swtimer_start(int32_t id, uint16_t n);
uint8_t swtimer_expired(int32_t id);

#endif
