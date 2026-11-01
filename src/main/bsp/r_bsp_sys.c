/* Renesas RX FIT BSP of the MAIN image, recreated for T24 (UI track): CPU and lock helpers, register protection,
 * the interrupt callback table and R_BSP_InterruptControl, the group-interrupt enables, the exception vectors, the
 * software-interrupt task queue, the clock set-up and the CC-RX intrinsic setters (docs/code/main/bsp.md).
 *
 * The FIT names (R_BSP_InterruptsEnable, bsp_fit_interrupts_control, ...) are the r_bsp module's: the image follows
 * its structure and command numbers [inference: the Ghidra names of bsp.md and the code shapes below]. Where Ghidra
 * has only FUN_<address>, src/main/aliases.tsv maps the name used here to the address. */
#include <stdint.h>
#include <stdbool.h>
#include "iodefine.h"

#define FIT_NO_PTR ((void *)0x10000000u)   /* FIT_NO_FUNC / FIT_NO_PTR [fact: the value stored by bsp_interrupt_open 0xFFF8FFC4] */

typedef void (*bsp_callback_t)(void *args);
typedef void (*bsp_swint_fn_t)(void *ctx, void *fn);

/* RAM of the BSP (src/main/data_symbols.tsv) */
extern volatile uint16_t g_bsp_protect_counters[4];      /* 0x1B5FC */
extern volatile uint32_t g_bsp_locks[0x74];              /* 0x1FFC4 */
extern bsp_callback_t g_bsp_vectors[0x5F];               /* 0x20194 */
extern volatile uint32_t g_bsp_swint_access_ctrl[2];     /* 0x20310 */
struct bsp_swint_task { uint32_t status; void *task; void *context; };
extern struct bsp_swint_task g_bsp_swint_task[2][9];     /* 0x20318, 0x6C bytes per unit */
extern volatile uint8_t g_bsp_swint_task_num[2];         /* 0x142C */
extern volatile uint8_t g_bsp_swint_buf_top[2];          /* 0x142E */
extern volatile uint8_t g_bsp_swint_buf_bottom[2];       /* 0x1430 */
extern volatile uint8_t g_bsp_swint_nested[2];           /* 0x1432 */
/* ROM */
extern const uint16_t bsp_prcr_masks[];                  /* 0xFFF87ED0 {1, 2, 8}: PRC0, PRC1, PRC3 */
extern const uint32_t bsp_hoco_freqs[3];                 /* 0xFFF8F30C {16, 18, 20 MHz} */
extern uint8_t bsp_swint_dummy_task[];                   /* 0xFFF910BC: SUB #4,SP; MOV.L R1,[SP]; NOP; RTSD #4 */

/* the image's own functions */
uint32_t get_iclk_freq_hz(void);
uint32_t R_BSP_GetIClkFreqHz(void);
uint64_t __udiv64(uint64_t n, uint64_t d);
void R_BSP_InterruptRequestEnable(uint32_t vector);
void R_BSP_InterruptRequestDisable(uint32_t vector);
uint32_t R_BSP_InterruptControl(uint32_t vector, uint32_t cmd, void *data);
void R_BSP_InterruptsEnable(void);
uint32_t R_BSP_CpuInterruptLevelRead(void);
uint8_t R_BSP_CpuInterruptLevelWrite(uint32_t level);
uint32_t bsp_interrupt_enable_disable(uint32_t vector, uint8_t enable);
uint32_t bsp_fit_interrupts_control(uint8_t enable, uint32_t *ipl);
uint32_t bsp_interrupt_group_enable_disable(int32_t vector, uint8_t enable, uint32_t ipl);
void icu_select_init(void);
uint32_t R_BSP_SoftwareInterruptOpen(int32_t unit);
uint32_t R_BSP_SoftwareInterruptControl(int32_t unit, uint32_t cmd, void *arg);
uint8_t R_BSP_SoftwareLock(volatile uint32_t *lock);
uint8_t R_BSP_SoftwareUnlock(volatile uint32_t *lock);
uint8_t R_BSP_HardwareLock(uint32_t id);
uint8_t R_BSP_HardwareUnlock(uint32_t id);
uint8_t bsp_swint_get_access_control(int32_t unit, uint32_t *value);
uint8_t bsp_swint_release_access_control(int32_t unit, uint32_t *value);
void bsp_swint_execute_task(int32_t unit);
uint8_t R_BSP_SoftwareDelay(uint32_t delay, uint32_t units);
void clock_source_select(void);
void mcu_clock_setup(void);

static inline uint32_t psw_get(void)
{
    uint32_t v;
    __asm__ volatile("mvfc psw, %0" : "=r"(v));
    return v;
}

#define PSW_PM 0x100000u   /* PSW bit 20: user mode */

/* --- version, clock, delay --- */

/* FUN_fff8fc3f: returns 0x50040 [fact]; the FIT R_BSP_GetVersion shape ((major << 16) | minor), so BSP 5.64
 * [inference: the encoding is FIT's, the value is the image's] */
uint32_t R_BSP_GetVersion(void)
{
    return 0x50040u;
}

/* R_BSP_GetIClkFreqHz 0xFFF8FC4D: get_iclk_freq_hz() [fact] */
uint32_t R_BSP_GetIClkFreqHz(void)
{
    return get_iclk_freq_hz();
}

/* R_BSP_SoftwareDelay 0xFFF8FC57 (delay, units): units 1000000 / 1000 / 1 (us, ms, s), else 0; loop count =
 * (ICLK * delay / units - 2) / 4, in 32 bits when units is us and delay <= 0xFFFFFFFF / ICLK, else in 64 bits
 * through __udiv64 (the divisor sign-extended, 0xFFF8FCF0); 0 when the count is 0 or does not fit in 32 bits;
 * then a 4-cycle NOP loop and 1 [fact: 0xFFF8FC57..0xFFF8FD6B] */
uint8_t R_BSP_SoftwareDelay(uint32_t delay, uint32_t units)
{
    if (units != 1000000u && units != 1000u && units != 1u)
        return 0;
    uint32_t iclk = R_BSP_GetIClkFreqHz();
    uint32_t loops;
    if (units == 1000000u && delay <= (iclk ? 0xFFFFFFFFu / iclk : 0xFFFFFFFFu)) {
        uint32_t t = iclk * delay;
        t = units ? t / units : t;
        t = t < 3 ? 0 : t - 2;
        loops = t >> 2;
        if (loops == 0)
            return 0;
    } else {
        uint64_t t = __udiv64((uint64_t)delay * iclk, (uint64_t)(int64_t)(int32_t)units);
        if (t > 2)
            t -= 2;
        /* the original zeroes a dead local here (28[r0], 0xFFF8FD1E) and keeps t as it was */
        t >>= 2;
        if ((uint32_t)(t >> 32) != 0 || (uint32_t)t == 0)
            return 0;
        loops = (uint32_t)t;
    }
    __asm__ volatile("1: nop\n\tsub #1, %0\n\tbne 1b" : "+r"(loops));
    return 1;
}

/* --- PSW helpers (FIT r_bsp_cpu.c) --- */

/* FUN_fff8fd6d: CLRPSW I unless in user mode [fact] */
void R_BSP_InterruptsDisable(void)
{
    if ((psw_get() & PSW_PM) == 0)
        __asm__ volatile("clrpsw i" ::: "memory");
}

/* FUN_fff8fd84: SETPSW I unless in user mode [fact] */
void R_BSP_InterruptsEnable(void)
{
    if ((psw_get() & PSW_PM) == 0)
        __asm__ volatile("setpsw i" ::: "memory");
}

/* FUN_fff8fd9b: PSW.IPL [fact] */
uint32_t R_BSP_CpuInterruptLevelRead(void)
{
    return (psw_get() & 0x0F000000u) >> 24;
}

/* FUN_fff8fdb8 (level): MVTIPL #level for 0..15 (a table of 16 MVTIPL), true; false for a bigger level or in user
 * mode [fact: 0xFFF8FDB8..0xFFF8FE3A] */
uint8_t R_BSP_CpuInterruptLevelWrite(uint32_t level)
{
    if (psw_get() & PSW_PM)
        return 0;
    switch (level) {
#define IPL(n) case n: __asm__ volatile("mvtipl #" #n ::: "memory"); break;
    IPL(0) IPL(1) IPL(2) IPL(3) IPL(4) IPL(5) IPL(6) IPL(7)
    IPL(8) IPL(9) IPL(10) IPL(11) IPL(12) IPL(13) IPL(14) IPL(15)
#undef IPL
    default:
        return 0;
    }
    return 1;
}

/* --- register write protection (FIT r_bsp_register_protect / mcu_locks) --- */

#define BSP_REG_PROTECT_MPC 3u      /* the region that is MPC PWPR, not a PRCR bit [fact: cmp #3 at 0xFFF8FE7B] */

/* R_BSP_RegisterProtectEnable 0xFFF8FE3C (region): counts down; at 0 locks again: MPC PWPR B0WI = 0, PFSWE = 0,
 * B0WI = 1, or PRCR = (PRCR | 0xA500) & ~mask; inside the FIT interrupt mask (InterruptControl 0x5E, 6 / 5) [fact] */
void R_BSP_RegisterProtectEnable(uint32_t region)
{
    uint32_t ipl;
    R_BSP_InterruptControl(0x5E, 6, &ipl);
    if (g_bsp_protect_counters[region] != 0)
        g_bsp_protect_counters[region]--;
    if (g_bsp_protect_counters[region] == 0) {
        if (region == BSP_REG_PROTECT_MPC) {
            MPC_PWPR &= (uint8_t)~0x80u;
            MPC_PWPR &= (uint8_t)~0x40u;
            MPC_PWPR |= 0x80u;
        } else {
            uint16_t v = SYSTEM_PRCR;
            SYSTEM_PRCR = (uint16_t)((v | 0xA500u) & ~bsp_prcr_masks[region]);
        }
    }
    R_BSP_InterruptControl(0x5E, 5, &ipl);
}

/* R_BSP_RegisterProtectDisable 0xFFF8FEC0 (region): at the first disable MPC PWPR B0WI = 0, PFSWE = 1, or PRCR |=
 * mask | 0xA500; then counts up [fact] */
void R_BSP_RegisterProtectDisable(uint32_t region)
{
    uint32_t ipl;
    R_BSP_InterruptControl(0x5E, 6, &ipl);
    if (g_bsp_protect_counters[region] == 0) {
        if (region == BSP_REG_PROTECT_MPC) {
            MPC_PWPR &= (uint8_t)~0x80u;
            MPC_PWPR |= 0x40u;
        } else {
            uint16_t v = SYSTEM_PRCR;
            SYSTEM_PRCR = (uint16_t)(v | bsp_prcr_masks[region] | 0xA500u);
        }
    }
    g_bsp_protect_counters[region]++;
    R_BSP_InterruptControl(0x5E, 5, &ipl);
}

/* FUN_fff8ff3d: the four protection counters 0x1B5FC = 0, called by PowerON_Reset [fact] */
void bsp_register_protect_open(void)
{
    for (uint32_t i = 0; i < 4; i++)
        g_bsp_protect_counters[i] = 0;
}

/* bsp_callbacks_clear 0xFFF8FF5F: 0x74 words at 0x1FFC4 = 0. They are the hardware lock words of
 * R_BSP_HardwareLock (0x1FFC4 + id * 4, 0xFFF9086C) [fact], so this is the FIT lock initialisation; the Ghidra name
 * says "callbacks" [inference: the callbacks are at 0x20194, bsp_interrupt_open] */
void bsp_callbacks_clear(void)
{
    for (uint32_t i = 0; i < 0x74; i++)
        g_bsp_locks[i] = 0;
}

/* --- interrupt callbacks (FIT r_bsp_interrupts.c) --- */

static inline bool callback_valid(bsp_callback_t cb)
{
    return !(cb == 0 || cb == (bsp_callback_t)FIT_NO_PTR);
}

/* bsp_interrupt_open 0xFFF8FFC4: 0x5F callbacks = FIT_NO_FUNC, icu_select_init, software interrupt units 0 and 1
 * opened [fact] */
void bsp_interrupt_open(void)
{
    for (uint32_t i = 0; i < 0x5F; i++)
        g_bsp_vectors[i] = (bsp_callback_t)FIT_NO_PTR;
    icu_select_init();
    R_BSP_SoftwareInterruptOpen(0);
    R_BSP_SoftwareInterruptOpen(1);
}

/* R_BSP_InterruptWrite 0xFFF8FFFB (vector, callback): NULL or FIT_NO_FUNC stores FIT_NO_FUNC; returns 0 [fact] */
uint32_t R_BSP_InterruptWrite(int32_t vector, bsp_callback_t cb)
{
    g_bsp_vectors[vector] = callback_valid(cb) ? cb : (bsp_callback_t)FIT_NO_PTR;
    return 0;
}

/* FUN_fff90046 (vector, *out): copies a registered callback to *out [fact]; the FIT R_BSP_InterruptRead (whose
 * error return the image does not have: it returns nothing, 0xFFF90046..0xFFF90096) */
void R_BSP_InterruptRead(int32_t vector, bsp_callback_t *out)
{
    if (callback_valid(g_bsp_vectors[vector]))
        *out = g_bsp_vectors[vector];
}

/* R_BSP_InterruptControl 0xFFF90097 (vector, cmd, data): 0 call the callback with {vector}, 1/2 enable/disable a
 * vector, 3/4 group enable (data = *ipl) / disable, 5/6 FIT interrupt level restore / mask; 1 = no callback, 2 =
 * bad command or data [fact] */
uint32_t R_BSP_InterruptControl(uint32_t vector, uint32_t cmd, void *data)
{
    uint32_t err = 0;
    switch (cmd) {
    case 6:
        err = bsp_fit_interrupts_control(0, data);
        break;
    case 1:
        err = bsp_interrupt_enable_disable(vector, 1);
        break;
    case 2:
        err = bsp_interrupt_enable_disable(vector, 0);
        break;
    case 3:
        if (data != 0 && data != FIT_NO_PTR)
            err = bsp_interrupt_group_enable_disable((int32_t)vector, 1, *(uint32_t *)data);
        else
            err = 2;
        break;
    case 4:
        err = bsp_interrupt_group_enable_disable((int32_t)vector, 0, 0);
        break;
    case 5:
        err = bsp_fit_interrupts_control(1, data);
        break;
    case 0:
        if (callback_valid(g_bsp_vectors[vector])) {
            uint32_t args = vector;
            g_bsp_vectors[vector](&args);
        } else {
            err = 1;
        }
        break;
    default:
        err = 2;
    }
    return err;
}

/* FUN_fff90181 (enable, *ipl): the FIT interrupt mask of the BSP's own critical sections: disable (0) saves
 * PSW.IPL in *ipl and raises it to 15, enable (1) restores *ipl; 2 = bad pointer, 3 = user mode, 5 = level not
 * written (*ipl >= 15 included) [fact: 0xFFF90181..0xFFF901F5] */
uint32_t bsp_fit_interrupts_control(uint8_t enable, uint32_t *ipl)
{
    if (ipl == 0 || ipl == FIT_NO_PTR)
        return 2;
    if (psw_get() & PSW_PM)
        return 3;
    uint32_t err = 0, level;
    if (enable == 1) {
        level = *ipl;
    } else {
        *ipl = R_BSP_CpuInterruptLevelRead();
        level = 15;
    }
    if (*ipl < 15) {
        if (!R_BSP_CpuInterruptLevelWrite(level))
            err = 5;
    } else {
        err = 5;
    }
    return err;
}

/* one group of bsp_interrupt_group_enable_disable: the group vector's IR, IPR and GEN register */
static uint32_t group_enable_disable(uint32_t vec, volatile uint32_t *gen, uint8_t enable, uint32_t ipl)
{
    volatile uint8_t *ir = (volatile uint8_t *)(0x87000u + vec);
    volatile uint8_t *ipr = (volatile uint8_t *)(0x87300u + vec);
    if (enable == 1) {
        R_BSP_InterruptRequestDisable(vec);
        *ir &= (uint8_t)~1u;
        if ((*ipr & 0x0Fu) >= ipl)          /* the group keeps the higher of the two priorities */
            ipl = *ipr & 0x0Fu;
        *ipr = (uint8_t)((*ipr & 0xF0u) | (ipl & 0x0Fu));
        R_BSP_InterruptRequestEnable(vec);
    } else {
        if (*gen != 0)
            return 4;                       /* a source of the group is still enabled */
        R_BSP_InterruptRequestDisable(vec);
        *ipr &= 0xF0u;
    }
    return 0;
}

/* bsp_interrupt_group_enable_disable 0xFFF901F8 (vector, enable, ipl): the BSP vector number ranges of the six
 * groups: 0x11..0x12 BE0 (vector 106), 0x14..0x30 BL0 (110), 0x32..0x49 BL1 (111), 0x4B BL2 (107), 0x4D..0x56 AL0
 * (112), 0x58..0x5C AL1 (113); ipl 1..15 for enable; 2 = bad argument or vector [fact; the range test 0x10..0x0F
 * at 0xFFF90233 never holds] */
uint32_t bsp_interrupt_group_enable_disable(int32_t vector, uint8_t enable, uint32_t ipl)
{
    if (enable == 1 && (ipl == 0 || ipl > 15))
        return 2;
    if (vector >= 0x11 && vector <= 0x12)
        return group_enable_disable(106, &ICU_GENBE0, enable, ipl);
    if (vector >= 0x14 && vector <= 0x30)
        return group_enable_disable(110, &ICU_GENBL0, enable, ipl);
    if (vector >= 0x32 && vector <= 0x49)
        return group_enable_disable(111, &ICU_GENBL1, enable, ipl);
    if (vector == 0x4B)
        return group_enable_disable(107, &ICU_GENBL2, enable, ipl);
    if (vector >= 0x4D && vector <= 0x56)
        return group_enable_disable(112, &ICU_GENAL0, enable, ipl);
    if (vector >= 0x58 && vector <= 0x5C)
        return group_enable_disable(113, &ICU_GENAL1, enable, ipl);
    return 2;
}

/* FUN_fff916ac (vector, enable): 2 NMI pin (enable only: NMIER.NMIEN), 3 FPU exceptions (FPSW EV..EX bits
 * 0x7C00 set or cleared), 11 bus error (IR016 = 0, IPR000 = 15, vector 16 and BEREN.IGAEN/TOEN); 3 = not
 * supported [fact: 0xFFF916AC..0xFFF91748] */
uint32_t bsp_interrupt_enable_disable(uint32_t vector, uint8_t enable)
{
    uint32_t err = 0;
    if (vector == 2) {
        if (enable == 1)
            ICU_NMIER |= 1u;
        else
            err = 3;
    } else if (vector == 3) {
        uint32_t fpsw;
        __asm__ volatile("mvfc fpsw, %0" : "=r"(fpsw));
        fpsw = enable == 1 ? fpsw | 0x7C00u : fpsw & 0xFFFF83FFu;
        __asm__ volatile("mvtc %0, fpsw" :: "r"(fpsw));
    } else if (vector == 11) {
        if (enable == 1) {
            ICU_IR016 &= (uint8_t)~1u;
            ICU_IPR000 |= 0x0Fu;
            R_BSP_InterruptRequestEnable(16);
            BSC_BEREN |= 1u;
            BSC_BEREN |= 2u;
        } else {
            R_BSP_InterruptRequestDisable(16);
            BSC_BEREN &= (uint8_t)~1u;
            BSC_BEREN &= (uint8_t)~2u;
        }
    } else {
        err = 3;
    }
    return err;
}

/* --- exception vectors: each runs the callback registered under its BSP number [fact: the R1 values] --- */

__attribute__((interrupt)) void SuperVisorInst(void) { R_BSP_InterruptControl(0, 0, FIT_NO_PTR); }
__attribute__((interrupt)) void AccessExc(void) { R_BSP_InterruptControl(4, 0, FIT_NO_PTR); }
__attribute__((interrupt)) void UndefinedInst(void) { R_BSP_InterruptControl(1, 0, FIT_NO_PTR); }
__attribute__((interrupt)) void Undefined_0xD8(void) { R_BSP_InterruptControl(10, 0, FIT_NO_PTR); }

/* FloatingPoint 0xFFF905F2: the callback, then FPSW cause flags CV..CE (bits 2..7) cleared [fact: AND #-253] */
__attribute__((interrupt)) void FloatingPoint(void)
{
    R_BSP_InterruptControl(3, 0, FIT_NO_PTR);
    uint32_t fpsw;
    __asm__ volatile("mvfc fpsw, %0" : "=r"(fpsw));
    fpsw &= 0xFFFFFF03u;
    __asm__ volatile("mvtc %0, fpsw" :: "r"(fpsw));
}

/* vec016_BSC_BUSERR 0xFFF90819: BERCLR.STSCLR = 1, then the bus-error callback (11) [fact] */
__attribute__((interrupt)) void vec016_BSC_BUSERR(void)
{
    BSC_BERCLR |= 1u;
    R_BSP_InterruptControl(11, 0, FIT_NO_PTR);
}

/* --- locks --- */

/* R_BSP_SoftwareLock 0xFFF90837: XCHG 1 into the lock; true when it was 0 [fact] */
uint8_t R_BSP_SoftwareLock(volatile uint32_t *lock)
{
    uint32_t v = 1;
    __asm__ volatile("xchg [%1].l, %0" : "+r"(v) : "r"(lock) : "memory");
    return v == 0;
}

/* R_BSP_SoftwareUnlock 0xFFF9085E: lock = 0, true [fact] */
uint8_t R_BSP_SoftwareUnlock(volatile uint32_t *lock)
{
    *lock = 0;
    return 1;
}

/* R_BSP_HardwareLock / Unlock 0xFFF9086C / 0xFFF90885: the software lock on word id of 0x1FFC4 [fact] */
uint8_t R_BSP_HardwareLock(uint32_t id)
{
    return R_BSP_SoftwareLock(&g_bsp_locks[id]);
}

uint8_t R_BSP_HardwareUnlock(uint32_t id)
{
    return R_BSP_SoftwareUnlock(&g_bsp_locks[id]);
}

/* --- software interrupts (FIT r_bsp_software_interrupt.c): unit 0 = SWINT (vector 27, lock 0x72), unit 1 =
 * SWINT2 (vector 26, lock 0x73); 9 task slots {status, task, context} per unit [fact] --- */

enum { SWINT_FREE = 0, SWINT_REQUESTED = 1, SWINT_RUNNING = 2, SWINT_DONE = 3 };   /* slot status [fact: the values
                                        set and tested in bsp_swint_execute_task]; the names are FIT's [inference] */

static void swint_slot_clear(int32_t unit, uint32_t i)
{
    g_bsp_swint_task[unit][i].status = SWINT_FREE;
    g_bsp_swint_task[unit][i].task = bsp_swint_dummy_task;
    g_bsp_swint_task[unit][i].context = FIT_NO_PTR;
}

/* R_BSP_SoftwareInterruptOpen 0xFFF9089E (unit): hardware lock, access word 1, disable, clear request, priority 1,
 * nesting on, slots and counters cleared, enable; 1 = locked, 3 = bad unit [fact] */
uint32_t R_BSP_SoftwareInterruptOpen(int32_t unit)
{
    uint32_t err = 0;
    uint8_t locked;
    if (unit == 1)
        locked = R_BSP_HardwareLock(0x73);
    else if (unit == 0)
        locked = R_BSP_HardwareLock(0x72);
    else
        err = 3;
    if (err == 0) {
        if (locked == 1) {
            g_bsp_swint_access_ctrl[unit] = 1;
            R_BSP_SoftwareInterruptControl(unit, 2, FIT_NO_PTR);
            R_BSP_SoftwareInterruptControl(unit, 5, FIT_NO_PTR);
            uint8_t ipl = 1;
            R_BSP_SoftwareInterruptControl(unit, 3, &ipl);
            g_bsp_swint_nested[unit] = 1;
            for (uint8_t i = 0; i < 9; i++)
                swint_slot_clear(unit, i);
            g_bsp_swint_buf_top[unit] = 0;
            g_bsp_swint_buf_bottom[unit] = 0;
            g_bsp_swint_task_num[unit] = 0;
            R_BSP_SoftwareInterruptControl(unit, 1, FIT_NO_PTR);
        } else {
            err = 1;
        }
    }
    return err;
}

/* R_BSP_SoftwareInterruptClose 0xFFF909AF (unit): disable, clear request, slots and counters, nesting off, unlock
 * [fact] */
void R_BSP_SoftwareInterruptClose(int32_t unit)
{
    if (unit >= 2)
        return;
    R_BSP_SoftwareInterruptControl(unit, 2, FIT_NO_PTR);
    R_BSP_SoftwareInterruptControl(unit, 5, FIT_NO_PTR);
    for (uint8_t i = 0; i < 9; i++)
        swint_slot_clear(unit, i);
    g_bsp_swint_buf_top[unit] = 0;
    g_bsp_swint_buf_bottom[unit] = 0;
    g_bsp_swint_task_num[unit] = 0;
    g_bsp_swint_nested[unit] = 0;
    if (unit == 1)
        R_BSP_HardwareUnlock(0x73);
    else if (unit == 0)
        R_BSP_HardwareUnlock(0x72);
}

/* R_BSP_SoftwareInterruptSetTask 0xFFF90A96 (unit, {status, task, context} in R2..R4): queues the task in the next
 * slot of the ring (top 0..8), then requests the interrupt; 6 = no task, 9 = queue full (8), 10 = access busy, 3 =
 * bad unit [fact]. No caller in V01-12 (bsp.md) */
uint32_t R_BSP_SoftwareInterruptSetTask(int32_t unit, uint32_t status, void *task, void *context)
{
    if (unit > 1)
        return 3;
    uint32_t acc = 0, err;
    if (bsp_swint_get_access_control(unit, &acc) != 1)
        return 10;
    if (task == FIT_NO_PTR || task == 0) {
        err = 6;
    } else if (g_bsp_swint_task_num[unit] >= 8) {
        err = 9;
    } else {
        if (g_bsp_swint_buf_top[unit] >= 8)
            g_bsp_swint_buf_top[unit] = 0;
        else
            g_bsp_swint_buf_top[unit]++;
        g_bsp_swint_task_num[unit]++;
        g_bsp_swint_task[unit][g_bsp_swint_buf_top[unit]].status = SWINT_REQUESTED;
        g_bsp_swint_task[unit][g_bsp_swint_buf_top[unit]].task = task;
        g_bsp_swint_task[unit][g_bsp_swint_buf_top[unit]].context = context;
        err = 0;
    }
    bsp_swint_release_access_control(unit, &acc);
    R_BSP_SoftwareInterruptControl(unit, 4, FIT_NO_PTR);
    return err;
}

/* bsp_swint_get_interrupt_information 0xFFF90BA6 (unit, out[4]): IPR003 priority, the IER03 bit (3 for SWINT, 2 for
 * SWINT2), the IR bit, the nesting flag [fact] */
void bsp_swint_get_interrupt_information(int32_t unit, uint8_t *out)
{
    if (unit == 1) {
        out[0] = ICU_IPR003 & 0x0Fu;
        out[1] = (ICU_IER03 >> 2) & 1u;
        out[2] = ICU_IR026 & 1u;
        out[3] = g_bsp_swint_nested[1];
    } else if (unit == 0) {
        out[0] = ICU_IPR003 & 0x0Fu;
        out[1] = (ICU_IER03 >> 3) & 1u;
        out[2] = ICU_IR027 & 1u;
        out[3] = g_bsp_swint_nested[0];
    }
}

void bsp_swint_enable_interrupt(int32_t unit)
{
    if (unit == 1)
        R_BSP_InterruptRequestEnable(26);
    else if (unit == 0)
        R_BSP_InterruptRequestEnable(27);
}

void bsp_swint_disable_interrupt(int32_t unit)
{
    if (unit == 1)
        R_BSP_InterruptRequestDisable(26);
    else if (unit == 0)
        R_BSP_InterruptRequestDisable(27);
}

/* bsp_swint_set_interrupt_priority 0xFFF90C76 (unit, *ipl): ipl < 16 into IPR003 with the vector disabled around
 * it and enabled again only if it was; the two units share IPR003 [fact]; 4 = bad level */
uint32_t bsp_swint_set_interrupt_priority(int32_t unit, uint8_t *ipl)
{
    if (*ipl >= 16)
        return 4;
    uint32_t mask;
    R_BSP_InterruptControl(0x5E, 6, &mask);
    if (unit == 1) {
        uint8_t was = (ICU_IER03 >> 2) & 1u;
        R_BSP_InterruptRequestDisable(26);
        ICU_IPR003 = (uint8_t)((ICU_IPR003 & 0xF0u) | (*ipl & 0x0Fu));
        if (was == 1)
            R_BSP_InterruptRequestEnable(26);
    } else if (unit == 0) {
        uint8_t was = (ICU_IER03 >> 3) & 1u;
        R_BSP_InterruptRequestDisable(27);
        ICU_IPR003 = (uint8_t)((ICU_IPR003 & 0xF0u) | (*ipl & 0x0Fu));
        if (was == 1)
            R_BSP_InterruptRequestEnable(27);
    }
    R_BSP_InterruptControl(0x5E, 5, &mask);
    return 0;
}

void bsp_swint_set_interrupt_request(int32_t unit)
{
    if (unit == 1)
        ICU_SWINT2R |= 1u;
    else if (unit == 0)
        ICU_SWINTR |= 1u;
}

void bsp_swint_clear_interrupt_request(int32_t unit)
{
    if (unit == 1)
        ICU_IR026 &= (uint8_t)~1u;
    else if (unit == 0)
        ICU_IR027 &= (uint8_t)~1u;
}

void bsp_swint_enable_nested_interrupt(int32_t unit)
{
    g_bsp_swint_nested[unit] = 1;
}

void bsp_swint_disable_nested_interrupt(int32_t unit)
{
    g_bsp_swint_nested[unit] = 0;
}

/* bsp_swint_clear_task 0xFFF90D85 (unit, *slot): frees one slot unless it runs; 7 = bad slot, 8 = running, 10 =
 * access busy; requests the interrupt afterwards [fact] */
uint32_t bsp_swint_clear_task(int32_t unit, uint8_t *slot)
{
    uint32_t acc = 0, err;
    if (bsp_swint_get_access_control(unit, &acc) != 1)
        return 10;
    if (*slot < 9) {
        if (g_bsp_swint_task[unit][*slot].status == SWINT_RUNNING) {
            err = 8;
        } else {
            swint_slot_clear(unit, *slot);
            err = 0;
        }
    } else {
        err = 7;
    }
    bsp_swint_release_access_control(unit, &acc);
    R_BSP_SoftwareInterruptControl(unit, 4, FIT_NO_PTR);
    return err;
}

/* bsp_swint_clear_all_task 0xFFF90E3C (unit): frees every slot and the counters unless one runs (8; then the
 * interrupt is requested again) [fact] */
uint32_t bsp_swint_clear_all_task(int32_t unit)
{
    uint32_t acc = 0, err;
    if (bsp_swint_get_access_control(unit, &acc) != 1)
        return 10;
    err = 0;
    for (uint8_t i = 0; i < 9; i++) {
        if (g_bsp_swint_task[unit][i].status == SWINT_RUNNING) {
            err = 8;
            break;
        }
    }
    if (err == 0) {
        for (uint8_t i = 0; i < 9; i++)
            swint_slot_clear(unit, i);
        g_bsp_swint_buf_top[unit] = 0;
        g_bsp_swint_buf_bottom[unit] = 0;
        g_bsp_swint_task_num[unit] = 0;
        bsp_swint_release_access_control(unit, &acc);
    } else {
        bsp_swint_release_access_control(unit, &acc);
        R_BSP_SoftwareInterruptControl(unit, 4, FIT_NO_PTR);
    }
    return err;
}

/* bsp_swint_get_all_task_status 0xFFF90F30 (unit, out): the nine slots copied [fact] */
void bsp_swint_get_all_task_status(int32_t unit, struct bsp_swint_task *out)
{
    for (uint8_t i = 0; i < 9; i++) {
        out->status = g_bsp_swint_task[unit][i].status;
        out->task = g_bsp_swint_task[unit][i].task;
        out->context = g_bsp_swint_task[unit][i].context;
        out++;
    }
}

/* R_BSP_SoftwareInterruptControl 0xFFF90F9B (unit, cmd, arg): commands 0..12 over the helpers above, 11 = queued
 * count, 12 = free slots (8 - count) into *arg; 3 = bad unit, 5 = bad command [fact] */
uint32_t R_BSP_SoftwareInterruptControl(int32_t unit, uint32_t cmd, void *arg)
{
    if (unit >= 2)
        return 3;
    uint32_t err = 0;
    switch (cmd) {
    case 0: bsp_swint_get_interrupt_information(unit, arg); break;
    case 1: bsp_swint_enable_interrupt(unit); break;
    case 2: bsp_swint_disable_interrupt(unit); break;
    case 3: err = bsp_swint_set_interrupt_priority(unit, arg); break;
    case 4: bsp_swint_set_interrupt_request(unit); break;
    case 5: bsp_swint_clear_interrupt_request(unit); break;
    case 6: bsp_swint_enable_nested_interrupt(unit); break;
    case 7: bsp_swint_disable_nested_interrupt(unit); break;
    case 8: err = bsp_swint_clear_task(unit, arg); break;
    case 9: err = bsp_swint_clear_all_task(unit); break;
    case 10: bsp_swint_get_all_task_status(unit, arg); break;
    case 11: *(uint8_t *)arg = g_bsp_swint_task_num[unit]; break;
    case 12: *(uint8_t *)arg = (uint8_t)(8u - g_bsp_swint_task_num[unit]); break;
    default: err = 5;
    }
    return err;
}

/* bsp_swint_get_access_control 0xFFF91059 (unit, *value): XCHG of *value and the unit's access word (the word goes
 * through a register: load, XCHG with *value, store); true when *value is now 1 (the access was free) [fact] */
uint8_t bsp_swint_get_access_control(int32_t unit, uint32_t *value)
{
    uint32_t w = g_bsp_swint_access_ctrl[unit];
    __asm__ volatile("xchg [%1].l, %0" : "+r"(w) : "r"(value) : "memory");
    g_bsp_swint_access_ctrl[unit] = w;
    return *value == 1;
}

/* bsp_swint_release_access_control 0xFFF91087: the same exchange; true when the access word is 1 again [fact] */
uint8_t bsp_swint_release_access_control(int32_t unit, uint32_t *value)
{
    uint32_t w = g_bsp_swint_access_ctrl[unit];
    __asm__ volatile("xchg [%1].l, %0" : "+r"(w) : "r"(value) : "memory");
    g_bsp_swint_access_ctrl[unit] = w;
    return g_bsp_swint_access_ctrl[unit] == 1;
}

/* bsp_swint_execute_task 0xFFF910C3 (unit): with the access, interrupts enabled when nesting is on; runs the
 * requested slots from bottom + 1 in ring order while tasks are queued (requested -> running -> task(context) ->
 * done), the access released around each task [fact]. The call passes the task address in R2 as well (CC-RX's JSR
 * R2 with R1 = context, 0xFFF91185..0xFFF91189) */
void bsp_swint_execute_task(int32_t unit)
{
    uint32_t acc = 0;
    if (bsp_swint_get_access_control(unit, &acc) != 1)
        return;
    bsp_swint_release_access_control(unit, &acc);
    if (g_bsp_swint_nested[unit] == 1)
        R_BSP_InterruptsEnable();
    acc = 0;
    bsp_swint_get_access_control(unit, &acc);
    while (g_bsp_swint_task_num[unit] != 0) {
        if (g_bsp_swint_buf_bottom[unit] >= 8)
            g_bsp_swint_buf_bottom[unit] = 0;
        else
            g_bsp_swint_buf_bottom[unit]++;
        if (g_bsp_swint_task[unit][g_bsp_swint_buf_bottom[unit]].status == SWINT_REQUESTED) {
            g_bsp_swint_task[unit][g_bsp_swint_buf_bottom[unit]].status = SWINT_RUNNING;
            bsp_swint_release_access_control(unit, &acc);
            struct bsp_swint_task *t = &g_bsp_swint_task[unit][g_bsp_swint_buf_bottom[unit]];
            ((bsp_swint_fn_t)t->task)(t->context, t->task);
            acc = 0;
            bsp_swint_get_access_control(unit, &acc);
            if (g_bsp_swint_task[unit][g_bsp_swint_buf_bottom[unit]].status == SWINT_RUNNING)
                g_bsp_swint_task[unit][g_bsp_swint_buf_bottom[unit]].status = SWINT_DONE;
        }
        if (g_bsp_swint_task_num[unit] != 0)
            g_bsp_swint_task_num[unit]--;
    }
    bsp_swint_release_access_control(unit, &acc);
}

__attribute__((interrupt)) void vec027_ICU_SWINT(void) { bsp_swint_execute_task(0); }
__attribute__((interrupt)) void vec026_ICU_SWINT2(void) { bsp_swint_execute_task(1); }

/* --- CC-RX intrinsic setters and helpers 0xFFF91228..0xFFF912C6, transcribed (no callers) [fact: the bytes] --- */

__attribute__((naked)) void chg_pmusr(void)
{
    __asm__ volatile("push.l r1\n\tmvfc psw, r1\n\tbtst #20, r1\n\tbne 1f\n\tbset #20, r1\n\tpush.l r2\n\t"
                     "mov.l r0, r2\n\txchg 8[r2].l, r1\n\txchg 4[r2].l, r1\n\tpop r2\n\trte\n1:\tpop r1\n\trts");
}

__attribute__((naked)) void set_bpsw(uint32_t v) { __asm__ volatile("mvtc r1, bpsw\n\trts"); }
__attribute__((naked)) void set_bpc(uint32_t v) { __asm__ volatile("mvtc r1, bpc\n\trts"); }
/* MVTC R1, EXTB (RXv2; GNU as for RXv1 does not know EXTB) */
__attribute__((naked)) void set_extb(uint32_t v) { __asm__ volatile(".byte 0xfd, 0x68, 0x1d\n\trts"); }
__attribute__((naked)) void set_acc_hi(uint32_t v) { __asm__ volatile("mvtachi r1\n\trts"); }
__attribute__((naked)) void set_acc_lo(uint32_t v) { __asm__ volatile("mvtaclo r1\n\trts"); }
__attribute__((naked)) void byte_bset(volatile uint8_t *p, uint32_t bit) { __asm__ volatile("bset r2, [r1].b\n\trts"); }
__attribute__((naked)) void byte_bclr(volatile uint8_t *p, uint32_t bit) { __asm__ volatile("bclr r2, [r1].b\n\trts"); }
__attribute__((naked)) void byte_bnot(volatile uint8_t *p, uint32_t bit) { __asm__ volatile("bnot r2, [r1].b\n\trts"); }

/* --- clocks (FIT mcu_clocks.c) --- */

/* get_iclk_freq_hz 0xFFF91303: ICLK from SCKCR3.CKSEL: 0 LOCO 240 kHz, 1 HOCO (HOCOCR2.HCFRQ: 16/18/20 MHz), 2 main
 * 24 MHz, 3 sub 32768 Hz, 4 PLL (24 MHz main or the HOCO when PLLSRCSEL, / (PLIDIV + 1), x (STC + 1) / 2), else 24
 * MHz; >> SCKCR.ICK [fact]. The HOCO table is a stack copy of 0xFFF8F30C with the PLL input in the next word, so
 * HCFRQ = 3 reads that word: the PLL input in the PLL case, an unset word in the HOCO case (zero in the check;
 * Open: what the radio's stack holds there; HCFRQ = 3 is reserved in the RX651 manual, so it is not reached) */
uint32_t get_iclk_freq_hz(void)
{
    uint32_t f[4];
    f[0] = bsp_hoco_freqs[0];
    f[1] = bsp_hoco_freqs[1];
    f[2] = bsp_hoco_freqs[2];
    f[3] = 0;
    uint32_t hz;
    switch ((SYSTEM_SCKCR3 >> 8) & 7u) {
    case 4: {
        uint32_t mul = ((((int16_t)SYSTEM_PLLCR >> 8) & 0x3Fu) * 10u + 10u) >> 1;   /* (STC + 1) / 2, x10 */
        f[3] = 24000000u;
        if ((((int16_t)SYSTEM_PLLCR >> 4) & 1u) == 1)
            f[3] = f[SYSTEM_HOCOCR2 & 3u];
        hz = f[3] / ((SYSTEM_PLLCR & 3u) * 10u + 10u) * mul;
        break;
    }
    case 1:
        hz = f[SYSTEM_HOCOCR2 & 3u];
        break;
    case 2:
        hz = 24000000u;
        break;
    case 3:
        hz = 32768u;
        break;
    case 0:
        hz = 240000u;
        break;
    default:
        hz = 24000000u;
    }
    return hz >> ((SYSTEM_SCKCR << 4) >> 28);
}

/* hw_init_clock 0xFFF913D7: mcu_clock_setup [fact] */
void hw_init_clock(void)
{
    mcu_clock_setup();
}

/* mcu_clock_setup 0xFFF913DB: PRCR = 0xA50B, the oscillators, SCKCR = 0x21C21222 (FCK, ICK, BCK, PCKA..D dividers,
 * PSTOP1 / BCLK bits), SCKCR2 = 0x11 (UCK), SCKCR3 = 0x400 (PLL), LOCO stopped, 25 us, PRCR = 0xA500; each register
 * read back once [fact] */
void mcu_clock_setup(void)
{
    SYSTEM_PRCR = 0xA50Bu;
    clock_source_select();
    SYSTEM_SCKCR = 0x21C21222u;
    (void)SYSTEM_SCKCR;
    SYSTEM_SCKCR2 = 0x11u;
    (void)SYSTEM_SCKCR2;
    SYSTEM_SCKCR3 = 0x400u;
    (void)SYSTEM_SCKCR3;
    SYSTEM_LOCOCR = 1u;
    R_BSP_SoftwareDelay(25, 1000000u);
    SYSTEM_PRCR = 0xA500u;
}

/* clock_source_select 0xFFF91495: main oscillator (MOFCR.MOFXIN = 0, MODRV2 = 0, MOSEL = 0 resonator), HOCO power
 * off when stopped else wait HCOVF, MOSCWTCR = 0x53, MOSCCR = 0 and wait MOOVF; on a cold start (RSTSR1.CWSF = 0)
 * the RTC count stopped (RCR4.RCKSEL = 0, RCR3.RTCEN = 0, each followed by four reads), then the sub-clock stopped
 * (SOSCCR = 1, wait SOOVF clear); PLL: PLIDIV = 0, PLLSRCSEL = 0, STC = 0x13 (x10), PLLCR2 = 0 and wait PLOVF; ROMWT
 * = 2 [fact] */
void clock_source_select(void)
{
    SYSTEM_MOFCR &= (uint8_t)~0x01u;
    SYSTEM_MOFCR &= (uint8_t)~0x40u;
    if ((SYSTEM_HOCOCR & 1u) == 1)
        SYSTEM_HOCOPCR = 1u;
    else
        while ((SYSTEM_OSCOVFSR & 0x08u) == 0)
            ;
    SYSTEM_MOFCR &= 0xCFu;
    SYSTEM_MOSCWTCR = 0x53u;
    SYSTEM_MOSCCR = 0u;
    (void)SYSTEM_MOSCCR;
    while ((SYSTEM_OSCOVFSR & 0x01u) == 0)
        ;
    if ((SYSTEM_RSTSR1 & 1u) == 0) {
        RTC_RCR4 &= (uint8_t)~1u;
        for (uint8_t i = 0; i < 4; i++)
            (void)RTC_RCR4;
        (void)(RTC_RCR4 & 1u);
        RTC_RCR3 &= (uint8_t)~1u;
        for (uint8_t i = 0; i < 4; i++)
            (void)RTC_RCR3;
        (void)(RTC_RCR3 & 1u);
    }
    SYSTEM_SOSCCR = 1u;
    (void)SYSTEM_SOSCCR;
    while ((SYSTEM_OSCOVFSR & 0x02u) != 0)
        ;
    SYSTEM_PLLCR &= 0xFFFCu;
    SYSTEM_PLLCR &= 0xFFEFu;
    SYSTEM_PLLCR = (uint16_t)((SYSTEM_PLLCR | 0x1300u) & 0xD3FFu);
    SYSTEM_PLLCR2 = 0u;
    while ((SYSTEM_OSCOVFSR & 0x04u) == 0)
        ;
    SYSTEM_ROMWT = 2u;
    (void)SYSTEM_ROMWT;
}

/* FUN_fff91608: PDR of the pins the 100/144-pin package does not have set to output (P0 |= 0x50, P1 |= 3, P5 |=
 * 0x80, P8 |= 0x30, P9 |= 0xF0, PF |= 0xDF, PG = 0xFF, PJ |= 0xD7; the other ports read and written back) [fact];
 * FIT's bsp_non_existent_port_init [inference: the shape] */
void bsp_non_existent_port_init(void)
{
    PORT0_PDR |= 0x50u;
    PORT1_PDR |= 0x03u;
    PORT2_PDR = PORT2_PDR;
    PORT3_PDR = PORT3_PDR;
    PORT4_PDR = PORT4_PDR;
    PORT5_PDR |= 0x80u;
    PORT6_PDR = PORT6_PDR;
    PORT7_PDR = PORT7_PDR;
    PORT8_PDR |= 0x30u;
    PORT9_PDR |= 0xF0u;
    PORTA_PDR = PORTA_PDR;
    PORTB_PDR = PORTB_PDR;
    PORTC_PDR = PORTC_PDR;
    PORTD_PDR = PORTD_PDR;
    PORTE_PDR = PORTE_PDR;
    PORTF_PDR |= 0xDFu;
    (void)PORTG_PDR;
    PORTG_PDR = 0xFFu;
    PORTJ_PDR |= 0xD7u;
}
