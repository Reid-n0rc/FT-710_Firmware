/*
 * FT-710 DISPLAY (T24): the NORTi (MiSPO, uITRON 4.0) service calls the recreated code uses, with the image's
 * argument shapes (docs/code/display/boot-rtos.md section 4). In the check and in the hybrid link they are the
 * image's kernel at its original addresses; src/display/rtos/ is a minimal stand-in with the same interface.
 *
 * The object-creation calls take (id, descriptor); id 0 asks the kernel to choose one, and the return value is the
 * new id (> 0) or an error code (< 0) [fact: itron_acre_isr 0x2014F1A8 tests r0 == 0 (moveq sb, #1); every caller
 * tests the result with "cmp r0, #0; ble"]. Error codes are uITRON 4.0's: E_OK 0, E_PAR -17, E_ID -18, E_CTX -25,
 * E_NOID -34, E_NOEXS -42, E_TMOUT -50.
 */
#ifndef NORTI_H
#define NORTI_H

#include <stdint.h>

typedef int ER;
typedef int ID;
typedef int TMO;
typedef unsigned int FLGPTN;
typedef unsigned int ATR;

#define E_OK 0
#define E_PAR (-17)
#define E_ID (-18)
#define E_CTX (-25)
#define E_NOMEM (-33)
#define E_NOID (-34)
#define E_OBJ (-41)
#define E_NOEXS (-42)
#define E_QOVR (-43)
#define E_TMOUT (-50)
#define TMO_POL 0
#define TMO_FEVR (-1)
#define TWF_ANDW 0x00
#define TWF_ORW 0x01
#define TA_CLR 0x04

typedef void (*FP)(intptr_t);

/* T_CISR, 0x14 bytes [fact: the RIIC descriptors at 0x20166C28: {0, 0, intno, isr, 9}] */
typedef struct
{
    ATR isratr;
    intptr_t exinf;
    uint32_t intno;
    void (*isr)(void);
    uint32_t imask;      /* Open: the meaning of the fifth word (9 in every RIIC descriptor); would be settled by
                            the use of +0x10 in itron_acre_isr 0x2014F1A8 */
} T_CISR;

/* T_CTSK, 0x1C bytes {attr, exinf, entry, prio, stksz, stk, name} (boot-rtos.md) */
typedef struct
{
    ATR tskatr;
    intptr_t exinf;
    FP task;
    int itskpri;
    uint32_t stksz;
    void *stk;
    const char *name;
} T_CTSK;

ER itron_acre_isr(ID id, const T_CISR *pk);
ER itron_acre_tsk(ID id, const T_CTSK *pk);
ER itron_sta_tsk(ID id, intptr_t stacd);
ER itron_dly_tsk(int ms);
ER itron_tslp_tsk(TMO tmout);
ER itron_iwup_tsk(ID id);
ER itron_sig_sem(ID id);
ER itron_twai_sem(ID id, TMO tmout);
ER itron_set_flg(ID id, FLGPTN set);
ER itron_clr_flg(ID id, FLGPTN clr);
ER itron_twai_flg(ID id, FLGPTN wai, unsigned mode, FLGPTN *p_flg, TMO tmout);
ER itron_snd_mbx(ID id, void *msg);
ER itron_trcv_mbx(ID id, void **p_msg, TMO tmout);
ER itron_tsnd_mbf(ID id, const void *msg, unsigned size, TMO tmout);
ER itron_trcv_mbf(ID id, void *msg, TMO tmout);
ER itron_tloc_mtx(ID id, TMO tmout);
ER itron_unl_mtx(ID id);
ER itron_loc_cpu(void);
ER itron_unl_cpu(void);
ER itron_get_tim(void *p_systim);
ER itron_sta_cyc(ID id);
ER itron_stp_cyc(ID id);

#endif
