/* CAT command table and handler prototypes of the MAIN image (T24; docs/code/main/cat.md, decomp/main/cat_dispatch.tsv).
 * The handlers are the image's (decomp/main); each gets a pointer to the command text (the mnemonic, at slot + 4) and,
 * for commands with a read and a set form, set = 0 (read) or 1 (set), chosen by the length (cat_dispatch). */
#ifndef CAT_CMDS_H
#define CAT_CMDS_H

#include <stdint.h>

/* The indexes are enum cat_cmd / enum cat_ext_cmd of tools/ghidra/enums_main.h (positions in cat_mnemonics 0xFFF805EC
 * and cat_ext_mnemonics 0xFFF806BC). */
#include "enums_main.h"

void cat_AB(void);
void cat_AC(const uint8_t *text, uint8_t set);
void cat_AG(const uint8_t *text, uint8_t set);
void cat_AI(const uint8_t *text, uint8_t set);
void cat_AM(void);
void cat_AO(const uint8_t *text, uint8_t set);
void cat_AS(const uint8_t *text, uint8_t set);
void cat_AV(const uint8_t *text, uint8_t set);
void cat_BA(void);
void cat_BC(const uint8_t *text, uint8_t set);
void cat_BD(const uint8_t *text);
void cat_BI(const uint8_t *text, uint8_t set);
void cat_BM(void);
void cat_BP(const uint8_t *text, uint8_t set);
void cat_BS(const uint8_t *text);
void cat_BU(const uint8_t *text);
void cat_CF(const uint8_t *text, uint8_t set);
void cat_CH(const uint8_t *text);
void cat_CN(const uint8_t *text, uint8_t set);
void cat_CO(const uint8_t *text, uint8_t set);
void cat_CS(const uint8_t *text, uint8_t set);
void cat_CT(const uint8_t *text, uint8_t set);
void cat_DA(const uint8_t *text, uint8_t set);
void cat_DN(void);
void cat_DT(const uint8_t *text, uint8_t set);
void cat_EM(const uint8_t *text, uint8_t set);
void cat_EN(const uint8_t *text);
void cat_EX(const uint8_t *text, uint8_t set, uint16_t len);
void cat_FA_FB(const uint8_t *text, uint8_t set, uint8_t vfo_b);  /* FA = 0, FB = 1 */
void cat_FN(const uint8_t *text, uint8_t set);
void cat_FS(const uint8_t *text, uint8_t set);
void cat_FT(const uint8_t *text, uint8_t set);
void cat_GP(const uint8_t *text, uint8_t set);
void cat_GT(const uint8_t *text, uint8_t set);
void cat_ID(void);
void cat_IF_OI(uint8_t opposite);                              /* IF = 0, OI = 1 */
void cat_IS(const uint8_t *text, uint8_t set);
void cat_KM(const uint8_t *text, uint8_t set, uint16_t len);
void cat_KP(const uint8_t *text, uint8_t set);
void cat_KR(const uint8_t *text, uint8_t set);
void cat_KS(const uint8_t *text, uint8_t set);
void cat_KY(const uint8_t *text);
void cat_LK(const uint8_t *text, uint8_t set);
void cat_LM(const uint8_t *text, uint8_t set);
void cat_MA(void);
void cat_MB(void);
void cat_MC(const uint8_t *text, uint8_t set);
void cat_MD(const uint8_t *text, uint8_t set);
void cat_MG(const uint8_t *text, uint8_t set);
void cat_ML(const uint8_t *text, uint8_t set);
void cat_MR(const uint8_t *text, uint8_t set);                 /* called with set = 0 only */
void cat_MS(const uint8_t *text, uint8_t set);
void cat_MT(const uint8_t *text, uint8_t set, uint16_t len);
void cat_MW(const uint8_t *text, uint8_t set);
void cat_MX(const uint8_t *text, uint8_t set);
void cat_NA(const uint8_t *text, uint8_t set);
void cat_NB(const uint8_t *text, uint8_t set);
void cat_NL(const uint8_t *text, uint8_t set);
void cat_NR(const uint8_t *text, uint8_t set);
void cat_OS(const uint8_t *text, uint8_t set);
void cat_PA(const uint8_t *text, uint8_t set);
void cat_PB(const uint8_t *text, uint8_t set);
void cat_PC(const uint8_t *text, uint8_t set);
void cat_PL(const uint8_t *text, uint8_t set);
void cat_PR(const uint8_t *text, uint8_t set);
void cat_PS(const uint8_t *text, uint8_t set);
void cat_QI(void);
void cat_QR(void);
void cat_QS(void);
void cat_RA(const uint8_t *text, uint8_t set);
void cat_RG(const uint8_t *text, uint8_t set);
void cat_RI(const uint8_t *text);
void cat_RL(const uint8_t *text, uint8_t set);
void cat_RM(const uint8_t *text);
void cat_SC(const uint8_t *text, uint8_t set);
void cat_SD(const uint8_t *text, uint8_t set);
void cat_SF(const uint8_t *text, uint8_t set);
void cat_SH(const uint8_t *text, uint8_t set);
void cat_SM(const uint8_t *text);
void cat_SQ(const uint8_t *text, uint8_t set);
void cat_SS(const uint8_t *text, uint8_t set);
void cat_ST(const uint8_t *text, uint8_t set);
void cat_SV(const uint8_t *text, uint8_t set);
void cat_TS(const uint8_t *text, uint8_t set);
void cat_TX(const uint8_t *text, uint8_t set);
void cat_UP(void);
void cat_VD(const uint8_t *text, uint8_t set);
void cat_VG(const uint8_t *text, uint8_t set);
void cat_VM(const uint8_t *text, uint16_t len);
void cat_VS(const uint8_t *text, uint8_t set);
void cat_VX(const uint8_t *text, uint8_t set);
void cat_ZI(const uint8_t *text);

/* the extended table's handlers (cat_ext_SP, cat_dispatch_ext) */
void cat_ext_SP(const uint8_t *slot);
void cat_ext_E9(const uint8_t *text);
void cat_ext_EO(const uint8_t *text, uint8_t set);
void cat_ext_E8(void);
void cat_ext_FD(const uint8_t *text, uint8_t set);
void cat_ext_PE(const uint8_t *text, uint8_t set);
void cat_ext_ZZ(const uint8_t *text);
void cat_ext_VE(uint8_t level);
void cat_ext_JP(const uint8_t *text, uint8_t set);
void cat_SP_sdr_reg(const uint8_t *text, uint8_t write);
void cat_SP_dev4_reg(const uint8_t *text, uint8_t write);
void cat_SP_adc_dump(void);
void cat_SP_eeprom_byte(const uint8_t *text, uint8_t write);
void cat_SP_meters(void);
void cat_SP_table(const uint8_t *text, uint8_t write, uint16_t len);

#endif
