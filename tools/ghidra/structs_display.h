/* tools/ghidra/structs_display.h -- typed state blocks of the FT-710 DISPLAY firmware V01-08 (T23c, DISPLAY part).
 *
 * Source of truth for the structures, typed globals and frame/object parameter types that
 * tools/ghidra/ApplyStructs.java puts into the Ghidra project (category /FT710). Apply after ApplySfr.java:
 *   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
 *     -scriptPath tools/ghidra -postScript ApplyStructs.java tools/ghidra/structs_display.h
 *
 * First drafted (2026-10-30) from `tools/ghidra/StructAccessDump.java <out> 0x20A00000 0x20000000` (every RAM access
 * with its width), `tools/struct_offsets.py --image display scan`, the descriptors in the image (.rodata), the docs in
 * docs/code/display/ (mainlink.md, gui.md, boot-rtos.md, update.md) and the MAIN side of the link
 * (docs/code/main/display-link.md, which maps the 0x97-byte status block byte by byte). Since then it is edited by
 * hand: add a field when its meaning is found, and cite the evidence.
 *
 * Format: as tools/ghidra/structs_main.h (one field per line with its `+0xOFF` comment, typed globals with `@0xADDRESS`,
 * `return` lines), plus `params` lines (ApplyStructs.java): `void f(struct ml_frame *frame, int32_t flag);
 * / * @0xADDRESS params ... * /` types every `struct NAME *name` parameter at its position; a function without a
 * committed prototype of that length gets the whole line as its prototype. Array sizes are decimal.
 * DISPLAY is a little-endian ARM (RZ/A1H, armcc). The kernel is NORTi 4 (MiSPO, uITRON 4.0; T23d), whose sources are
 * not public: the uITRON 4.0 packet layouts (T_CTSK, T_CISR, ...) are from the spec, the control-block layouts from the
 * kernel code here. Unknown fields that code accesses are f_0xOFF_u8/u16/u32 (width from the p-code).
 * Tags as in AGENTS.md: [fact] (seen in code or data, with the address or function), [inference], [guess].
 */

#include <stdint.h>

/* ---------------------------------------------------------------- NORTi creation packets (.rodata descriptors) */

struct t_ctsk {  /* size 0x1C: uITRON 4.0 T_CTSK plus a name; read by itron_acre_tsk 0x201500F4 (boot-rtos.md task table) */
    uint32_t tskatr;                             /* +0x000 [fact] attributes: bit 1 TA_ACT = start at once (acre_tsk calls act_tsk; set only in ctsk_root) */
    uint32_t exinf;                              /* +0x004 [fact] extended information, passed to the task (act_tsk stores it in the initial frame); 0 in every descriptor */
    uint32_t task;                               /* +0x008 [fact] entry address, bit 0 = Thumb (act_tsk sets CPSR.T then); cpp_task_thunk for the C++ tasks */
    int32_t itskpri;                             /* +0x00C [fact] initial priority 1..8 (acre_tsk: E_PAR if >= 9; copied to TCB +0x04 and +0x27) */
    uint32_t stksz;                              /* +0x010 [fact] stack size in bytes (acre_tsk) */
    uint8_t *stk;                                /* +0x014 [fact] stack, 0 = allocate (acre_tsk FUN_20154704) */
    char *name;                                  /* +0x018 [fact] task name string ("root", "uart", ...), a NORTi extension */
};

struct t_cisr {  /* size 0x14: uITRON 4.0 T_CISR plus one word; read by itron_acre_isr 0x2014F1A8 */
    uint32_t isratr;                             /* +0x000 [fact] attributes, 0 in every descriptor */
    uint32_t exinf;                              /* +0x004 [fact] extended information (acre_isr copies it next to the handler), 0 in every descriptor */
    uint32_t intno;                              /* +0x008 [fact] GIC interrupt ID (scif_rxi_isr disables it with gic_disable_irq(desc->intno)) */
    uint32_t isr;                                /* +0x00C [fact] handler address (acre_isr stores it first in the ISR record) */
    uint32_t intpri;                             /* +0x010 [fact] 5, 9 or 10 in the image, copied by acre_isr; the GIC priority [inference] */
};

struct t_csem {  /* size 0x10: uITRON 4.0 T_CSEM plus a name; read by itron_acre_sem 0x2014FF2C */
    uint32_t sematr;                             /* +0x000 [fact] bit 0 TA_TPRI: priority-ordered wait queue (acre_sem sizes the queue 8 instead of 1) */
    uint32_t isemcnt;                            /* +0x004 [fact] initial count (acre_sem: E_PAR if > maxsem) */
    uint32_t maxsem;                             /* +0x008 [fact] maximum count (acre_sem: E_PAR if > 0xFFFF) */
    char *name;                                  /* +0x00C [inference] name, copied with the packet (os_create_sem_named) */
};

struct t_cflg {  /* size 0xC: uITRON 4.0 T_CFLG plus a name; read by itron_acre_flg 0x2014EFFC */
    uint32_t flgatr;                             /* +0x000 [fact] bit 0 TA_TPRI (queue size), stored in flag +0x08; 2 (TA_WMUL) in every descriptor */
    uint32_t iflgptn;                            /* +0x004 [fact] initial bit pattern (acre_flg) */
    char *name;                                  /* +0x008 [inference] name, 0 in every descriptor */
};

struct t_cmtx {  /* size 0xC: uITRON 4.0 T_CMTX plus a name; read by itron_acre_mtx 0x2014FD24 */
    uint32_t mtxatr;                             /* +0x000 [fact] 2 TA_INHERIT or 3 TA_CEILING (tloc_mtx/chg_pri compare mutex +0x04 with 2 and 3; uITRON 4.0 codes) */
    int32_t ceilpri;                             /* +0x004 [fact] ceiling priority (acre_mtx stores it in mutex +0x0B) */
    char *name;                                  /* +0x008 [inference] name */
};

struct t_cmpf {  /* size 0x14: uITRON 4.0 T_CMPF plus a name; read by itron_acre_mpf 0x2014F8B8 */
    uint32_t mpfatr;                             /* +0x000 [fact] bit 0 TA_TPRI (queue size) */
    uint32_t blkcnt;                             /* +0x004 [fact] number of blocks (acre_mpf: E_PAR if 0) */
    uint32_t blksz;                              /* +0x008 [fact] block size, rounded up to 4 (acre_mpf) */
    uint8_t *mpf;                                /* +0x00C [fact] pool memory, 0 = allocate blkcnt * blksz (FUN_20154720) */
    char *name;                                  /* +0x010 [inference] name */
};

/* ---------------------------------------------------------------- NORTi control blocks (allocated by the kernel) */

struct knl_tcb {  /* size 0x28: task control block, allocated by itron_acre_tsk (0x28 bytes, 0x44 with a copy of the T_CTSK behind it) */
    uint32_t sp;                                 /* +0x000 [fact] saved stack pointer: act_tsk sets it to the initial context frame (stack end - 0x48); chg_pri reads the waited object's id at sp + 4 */
    int8_t pri;                                  /* +0x004 [fact] current priority: acre_tsk sets itskpri, tloc_mtx raises it to a TA_CEILING mutex's ceiling, chg_pri sets it */
    uint8_t state;                               /* +0x005 [fact] 0 dormant (act_tsk starts it, chg_pri E_OBJ), 0x10 ready, 0x32 dly_tsk, 0x90/0x92 sem, 0x94/0x96 mutex, 0xD0/0xD2 mpf; bit 1 = with time-out (sig_sem calls knl_timeout_remove) */
    uint8_t q_next;                              /* +0x006 [fact] next task id in the circular queue the task is in (FUN_20153A38 links it; rot_rdq makes it the queue head) */
    uint8_t q_prev;                              /* +0x007 [fact] previous task id in that queue (FUN_201538D4 inserts before the head, FUN_201539EC unlinks) */
    uint8_t f_0x08_u8;                           /* +0x008 [fact: accessed] cleared when the task starts (act_tsk) */
    uint8_t f_0x09_u8;                           /* +0x009 [fact: accessed] cleared at start; sig_sem and chg_pri take another path while it is set (suspend count [guess]) */
    uint8_t tmo_next;                            /* +0x00A [fact] next task id in the time-out wheel slot (knl_timeout_add) */
    uint8_t tmo_prev;                            /* +0x00B [fact] previous task id in the time-out wheel slot (knl_timeout_add) */
    uint32_t tmo_due;                            /* +0x00C [fact] time-out tick: tmout + knl_sys.tick_lo (knl_timeout_add), wheel slot = tmo_due & knl_sys.tmo_mask */
    uint8_t *queue;                              /* +0x010 [fact] head byte of the ready or wait queue the task is in (FUN_201538D4 / FUN_20153A38 set it, FUN_201539EC clears *queue when the task was alone; rot_rdq rotates it) */
    uint8_t *stk;                                /* +0x014 [fact] stack (T_CTSK.stk or allocated; acre_tsk fills it with the task id) */
    struct t_ctsk *ctsk;                         /* +0x018 [fact] creation packet, or its copy behind the TCB when it is not in the image (acre_tsk, knl_addr_in_image) */
    uint32_t f_0x1c_u32;                         /* +0x01C [fact: accessed] 0 at create (acre_tsk) */
    uint32_t f_0x20_u32;                         /* +0x020 [fact: accessed] 0 at start (act_tsk); wake-up count [guess] */
    int16_t mtx_held;                            /* +0x024 [fact] id of the last mutex the task locked; that mutex's +0x08 holds the one before (tloc_mtx, chg_pri walks the list) */
    uint8_t act_cnt;                             /* +0x026 [fact] queued activations: act_tsk on a running task increments it, E_QOVR at 0xFF */
    int8_t bpri;                                 /* +0x027 [fact] base priority: acre_tsk itskpri, chg_pri sets it; tloc_mtx checks a ceiling against it */
};

struct knl_sem {  /* size 0x11: semaphore control block (itron_acre_sem: 0x0C + queue) */
    struct t_csem *csem;                         /* +0x000 [fact] creation packet or its copy (acre_sem) */
    uint16_t semcnt;                             /* +0x004 [fact] count (sig_sem ++, twai_sem --) */
    uint16_t maxsem;                             /* +0x006 [fact] maximum count; sig_sem returns E_QOVR at it */
    uint8_t wq[9];                               /* +0x008 [fact] wait queue: one head (FIFO, ended by 0xFE) or 8 heads by priority (TA_TPRI, ended by 0xFF); task ids */
};

struct knl_flg {  /* size 0x12: event-flag control block (itron_acre_flg: 0x0C + queue) */
    struct t_cflg *cflg;                         /* +0x000 [fact] creation packet or its copy (acre_flg) */
    uint32_t flgptn;                             /* +0x004 [fact] bit pattern (acre_flg iflgptn; set_flg / clr_flg) */
    uint8_t flgatr;                              /* +0x008 [fact] attribute byte copied from T_CFLG.flgatr (acre_flg) */
    uint8_t wq[9];                               /* +0x009 [fact] wait queue, as knl_sem.wq */
};

struct knl_mtx {  /* size 0x15: mutex control block (itron_acre_mtx: 0x10 + queue) */
    struct t_cmtx *cmtx;                         /* +0x000 [fact] creation packet or its copy (acre_mtx) */
    int32_t mtxatr;                              /* +0x004 [fact] 2 TA_INHERIT, 3 TA_CEILING (tloc_mtx, chg_pri) */
    int16_t prev_held;                           /* +0x008 [fact] the mutex the owner locked before this one (tloc_mtx stores TCB.mtx_held here) */
    uint8_t owner;                               /* +0x00A [fact] owning task id, 0 = free (tloc_mtx) */
    int8_t pri;                                  /* +0x00B [fact] ceiling (TA_CEILING) or inherited priority (TA_INHERIT: the highest waiter, tloc_mtx) */
    uint8_t wq[9];                               /* +0x00C [fact] wait queue, as knl_sem.wq */
};

struct knl_mpf {  /* size 0x1B: fixed-size memory-pool control block (itron_acre_mpf: 0x14 + queue) */
    struct t_cmpf *cmpf;                         /* +0x000 [fact] creation packet or its copy (acre_mpf) */
    uint8_t *free_head;                          /* +0x004 [fact] first free block; each free block's first word links the next (tget_mpf pops it, rel_mpf pushes) */
    uint8_t *pool;                               /* +0x008 [fact] pool memory (acre_mpf) */
    uint32_t pool_size;                          /* +0x00C [fact] blkcnt * rounded blksz (acre_mpf) */
    uint16_t fblkcnt;                            /* +0x010 [fact] free blocks: blkcnt at create, tget_mpf -- */
    uint8_t wq[9];                               /* +0x012 [fact] wait queue, as knl_sem.wq */
};

struct knl_sys {  /* size 0x58: NORTi system variables 0x208003A8..0x208003FF, all set by the kernel init FUN_201530FC */
    uint32_t f_0x00_u32;                         /* +0x000 0x208003A8 [fact: accessed] kernel_heap_init, FUN_20156310, FUN_2015632C */
    uint32_t task_cpsr;                          /* +0x004 0x208003AC [fact] CPSR of a new task: act_tsk / sta_tsk store it (| 0x20 = Thumb when the entry address is odd) in the initial frame */
    uint32_t idle_hook;                          /* +0x008 0x208003B0 [fact] function the idle loop in main calls when non-zero (0 at init) */
    uint32_t f_0x0c_u32;                         /* +0x00C 0x208003B4 [fact: accessed] 8 at init, counted down by itron_acre_mbx (auto-assigned mailbox id [inference]) */
    uint32_t f_0x10_u32;                         /* +0x010 0x208003B8 [fact: accessed] 0 at init */
    uint16_t tim_base_hi;                        /* +0x014 0x208003BC [fact] SYSTIM offset, high 16 bits (itron_get_tim adds it to tick_hi) */
    uint32_t tim_base_lo;                        /* +0x018 0x208003C0 [fact] SYSTIM offset, low 32 bits (itron_get_tim) */
    uint16_t tick_hi;                            /* +0x01C 0x208003C4 [fact] tick counter, high 16 bits (itron_get_tim) */
    uint32_t tick_lo;                            /* +0x020 0x208003C8 [fact] tick counter, low 32 bits: the time-out base (knl_timeout_add) and SYSTIM (itron_get_tim) */
    uint32_t f_0x24_u32;                         /* +0x024 0x208003CC [fact: accessed] dis_dsp returns E_CTX when bit 7 is set, unl_cpu clears bits 6-7 (saved interrupt mask [guess]) */
    uint32_t f_0x28_u32;                         /* +0x028 0x208003D0 [fact: accessed] the idle loop in main stores an inverted value here */
    int32_t last_ercd;                           /* +0x02C 0x208003D4 [fact] error code of the last failed service call: every itron_* stores E_xxx here before returning it */
    uint8_t f_0x30_u8;                           /* +0x030 0x208003D8 [fact: accessed] chg_pri stores the new priority of the running task here */
    uint8_t dsp_pending;                         /* +0x031 0x208003D9 [inference] a task switch is pending: ena_dsp / unl_cpu dispatch when it is set */
    uint8_t ctx_isr;                             /* +0x032 0x208003DA [inference] non-task context (interrupt nesting): every waiting call returns E_CTX while it is non-zero */
    uint8_t dsp_state;                           /* +0x033 0x208003DB [fact] bit 0 dispatch disabled, bit 3 by dis_dsp (|= 9), bit 4 CPU locked (loc_cpu: 0x13 / 0x1B); waits return E_CTX while non-zero */
    uint8_t f_0x34_u8;                           /* +0x034 0x208003DC [fact: accessed] unl_cpu dispatches when it is set; ostm0_tick_isr sets it to max task id + 1 */
    uint8_t tick_pending;                        /* +0x035 0x208003DD [inference] ostm0_tick_isr increments it, the idle loop in main counts it down */
    uint8_t f_0x36_u8;                           /* +0x036 0x208003DE [fact: accessed] main copies it to +0x34 */
    int8_t run_pri;                              /* +0x037 0x208003DF [fact] priority of the running task (9 = idle at init; waits index the TA_TPRI queue with it - 1) */
    uint8_t tmo_mask;                            /* +0x038 0x208003E0 [fact] mask of the time-out wheel 0x20800400 (knl_timeout_add) */
    uint8_t tmo_mask_1;                          /* +0x039 0x208003E1 [fact] mask of the second wheel 0x20800401 (FUN_20153788) */
    uint8_t tmo_mask_2;                          /* +0x03A 0x208003E2 [fact] mask of the third wheel 0x20800402 (FUN_20153620) */
    uint32_t wait_arg3;                          /* +0x03C 0x208003E4 [fact] third argument of the blocking call in progress (twai_flg, tsnd_mbf) */
    uint32_t wait_arg2;                          /* +0x040 0x208003E8 [fact] second argument of the blocking call in progress (tget_mpf p_blk, trcv_*, tsnd_*) */
    uint32_t wait_id;                            /* +0x044 0x208003EC [fact] object id of the blocking call in progress (twai_sem, tloc_mtx, tget_mpf, ...) */
    uint8_t *isr_area;                           /* +0x048 0x208003F0 [fact] top of the 0x400 bytes FUN_201530FC clears below its second argument */
    uint32_t f_0x4c_u32;                         /* +0x04C 0x208003F4 [fact: accessed] 0 at init */
    uint32_t f_0x50_u32;                         /* +0x050 0x208003F8 [fact: accessed] 0 at init */
    uint32_t *heap;                              /* +0x054 0x208003FC [fact] kernel memory pool header {next, size} (FUN_201530FC first argument; kernel_heap_init, boot-rtos.md) */
};

/* ---------------------------------------------------------------- boot-info block */

struct boot_info {  /* size 0x5C: the boot-info block (update.md, memory-maps.md "Dual-bank boot"); bootinfo_load 0x20116C4C copies 0x60 bytes, the last word lands in the unused slot 0 of knl_tsk_tab */
    uint32_t bank;                               /* +0x000 [fact] running bank 1 or 2, 0xBBBB in loader mode (boot_select_bank writes 0xBBBB; update.md) */
    uint32_t mode;                               /* +0x008 [fact] 1 normal, 2 key-6 / loader mode (power_on_request), 3 loader (update.md) */
    uint32_t bank1_flag;                         /* +0x020 [fact] bank 1 flag block offset, default 0x3E0000 (bootinfo_load) */
    uint32_t bank1_image;                        /* +0x024 [fact] bank 1 image offset, default 0x400000 */
    uint32_t bank2_flag;                         /* +0x040 [fact] bank 2 flag block offset, default 0x3F0000 */
    uint32_t bank2_image;                        /* +0x044 [fact] bank 2 image offset, default 0xA00000 */
};

/* ---------------------------------------------------------------- SCIF UART objects (mainlink.md section 3) */

struct scif_regs {  /* size 0x2C: one SCIF channel's registers (RZ/A1H HWM Table 58.1: SCIF_SCSMR_n at +0 ... SCEMR_n at +0x28; sfr_rza1h.tsv) */
    uint16_t scsmr;                              /* +0x000 [fact] serial mode (scif_open) */
    uint8_t scbrr;                               /* +0x004 [fact] bit rate (scif_open: 0x16 for 345600) */
    uint16_t scscr;                              /* +0x008 [fact] serial control (scif_open |= 0xF8, scif_txi_isr clears TIE) */
    uint8_t scftdr;                              /* +0x00C [fact] transmit FIFO data (scif_txi_isr) */
    uint16_t scfsr;                              /* +0x010 [fact] serial status: bit 1 RDF, bit 5 TDFE (scif_rxi_isr, scif_txi_isr) */
    uint8_t scfrdr;                              /* +0x014 [fact] receive FIFO data (scif_rxi_isr) */
    uint16_t scfcr;                              /* +0x018 [fact] FIFO control: scif_open resets both FIFOs (| 6, then & ~6) */
    uint16_t scfdr;                              /* +0x01C [fact] FIFO data count */
    uint16_t scsptr;                             /* +0x020 [fact] serial port */
    uint16_t sclsr;                              /* +0x024 [fact] line status (scif_open clears it) */
    uint16_t scemr;                              /* +0x028 [fact] serial extension mode: 0x81 (BGDM, ABCS) for 345600 baud (scif_open) */
};

struct cyc_stamp {  /* size 0x8: time between two events in CPU cycles (FUN_20114850: CP15 c9/c13 = PMCCNTR) */
    uint32_t delta;                              /* +0x000 [fact] now - last (FUN_20114850) */
    uint32_t last;                               /* +0x004 [fact] cycle count at the last event */
};

struct scif_uart {  /* size 0x850: UART object with RX and TX rings; instances 0x208DA1E0 (SCIF3), 0x208DAA30 (SCIF4), 0x208DB280 (SCIF5) */
    uint32_t *vtbl;                              /* +0x000 [inference] C++ vtable: uart4_obj_run calls slot 1 of the object scif4_get returns as open(baud, bits, parity) */
    struct scif_regs *regs;                      /* +0x004 [fact] register block, set once by uart_obj_init (&SCIF_SCSMR_n) */
    uint16_t rx_rd;                              /* +0x008 [fact] RX ring read index (scif_read), mod 0x400 */
    uint16_t rx_wr;                              /* +0x00A [fact] RX ring write index (scif_rxi_isr), mod 0x400 */
    uint8_t rx_buf[1024];                        /* +0x00C [fact] RX ring (mainlink.md: 1 KB RX ring) */
    uint16_t tx_rd;                              /* +0x40C [fact] TX ring read index (scif_txi_isr) */
    uint16_t tx_wr;                              /* +0x40E [fact] TX ring write index (scif_write) */
    uint8_t tx_buf[1024];                        /* +0x410 [fact] TX ring */
    struct t_cisr *rxi_isr;                      /* +0x810 [fact] RXI interrupt descriptor (uart_obj_init; scif_read re-enables desc->intno) */
    struct t_cisr *txi_isr;                      /* +0x814 [fact] TXI interrupt descriptor (uart_obj_init) */
    uint32_t rx_flg;                             /* +0x818 [fact] event flag set (bit 0) per received byte, 0 = none (uart_obj_init last argument, scif_rxi_isr, scif_has_flag) */
    uint32_t rxi_count;                          /* +0x81C [fact] RXI interrupts (scif_rxi_isr) */
    uint32_t rx_count;                           /* +0x820 [fact] bytes received or dropped (scif_rxi_isr) */
    uint32_t rx_overflow;                        /* +0x824 [fact] bytes dropped because the ring was full (scif_rxi_isr) */
    uint32_t rx_errors;                          /* +0x828 [fact] RXI with an SCFSR error bit (& 0xFF9D) set (scif_rxi_isr) */
    uint32_t rxi_no_data;                        /* +0x82C [fact] RXI without RDF (scif_rxi_isr) */
    uint32_t txi_count;                          /* +0x830 [fact] TXI interrupts (scif_txi_isr) */
    uint32_t tx_count;                           /* +0x834 [fact] bytes sent (scif_txi_isr) */
    uint32_t txi_not_ready;                      /* +0x838 [fact] TXI without TDFE (scif_txi_isr) */
    struct cyc_stamp rx_time;                    /* +0x840 [fact] cycles between received bytes (scif_rxi_isr) */
    struct cyc_stamp tx_time;                    /* +0x848 [fact] cycles between sent bytes (scif_txi_isr) */
};

/* ---------------------------------------------------------------- the MAIN-link frame (MAIN -> DISPLAY screen packets) */

struct ml_vfo {  /* size 0x19: one VFO block of the status block, frame bytes 45-69 (main side) and 70-94 (sub side) (display-link.md, #72) */
    uint8_t mode;                                /* +0x000 [fact] mode, rec+0 & 0xF (MAIN cat_mode_codes order) */
    uint8_t state;                               /* +0x001 [fact] VFO state: 0, 1 VFO, 2 memory, 3 memory tune, 4 PMS, 5 QMB, 7 60 m, 8 EMG, 9 split RX, 10 split TX (MAIN FUN_fff97cf7) */
    uint8_t channel;                             /* +0x002 [fact] memory channel number */
    uint8_t flags;                               /* +0x003 [fact] MAIN FUN_fff97e1d flags (bits not mapped) */
    uint8_t freq_digits[5];                      /* +0x004 [fact] frequency digits (MAIN FUN_fff982bb, or the numeric-entry BCD) */
    char tag[12];                                /* +0x009 [fact] memory tag, rec+0x4E */
    uint8_t side;                                /* +0x015 [fact] MAIN UI +0x425 */
    uint8_t clar_be[2];                          /* +0x016 [fact] s16 clarifier offset in Hz, big-endian (rec+0x48) */
    uint8_t f_0x18_u8;                           /* +0x018 [inference] byte 69 / 94, not mapped on the MAIN side */
};

struct ml_frame {  /* size 0x240: one MAIN -> DISPLAY frame as the GUI keeps it: cmd, the 0x97-byte status block (display-link.md "The 0x97-byte radio status block"), the screen's own data */
    uint8_t cmd;                                 /* +0x000 [fact] screen / command id (gui.md "Screen packets"; gui_screen_update dispatches on it) */
    uint8_t byte1;                               /* +0x001 [fact] status frames: scope flag MAIN 0x9C37, 1 = small scope plus the oscilloscope / AF-FFT panel (scope_area_setup, 0x20800482; gui.md); short frames: 0x7B screen saver on (mainlink.md), 0x64 test pattern, 0x21 level, 0x3F record flag */
    uint8_t scope_mode;                          /* +0x002 [fact] scope mode 0..0xB: 3DSS / 2D, CENTER / CURSOR / FIX, waterfall size (scope_mode_decode; gui.md) */
    uint8_t vfo_flags;                           /* +0x003 [fact] bit 7 active VFO is B, bit 5 split, bits 4/6 side flag; bit 2 text view (never set by MAIN, gui.md) */
    uint8_t flags4;                              /* +0x004 [fact] bit 5 when MAIN UI +0x95, +0x96 or +0x97 is set */
    uint8_t scope_flags;                         /* +0x005 [fact] split | waterfall EXPAND << 5 | MAIN 0x9DC6 << 6 (gui.md: bit 5 = expanded area) */
    uint8_t disp_sens;                           /* +0x006 [fact] 3DSS sensitivity << 6 | 2D sensitivity << 7 */
    uint8_t tx_swr;                              /* +0x007 [fact] HI-SWR warning << 4 (2 bits), bit 7 TX (meter_draw) */
    uint8_t led_mask;                            /* +0x008 [fact] front-panel LED mask, led_set_mask(frame[8]) in gui_screen_update */
    uint8_t flags9;                              /* +0x009 [fact] bit 3 AF-FFT overlay of the filter graph (main_filter_graph), bits 4-6 MAIN UI +0x6C/+0x6B/+0x6A, bit 7 marker */
    uint8_t tx_bpf;                              /* +0x00A [fact] TX BPF SEL of the mode | 0x80 */
    uint8_t meter_sel;                           /* +0x00B [fact] meter 0 PO, 1 COMP, 2 ALC, 3 VDD, 4 IDD, 5 SWR (meter_draw_scale) */
    uint8_t att_amp_dnf;                         /* +0x00C [fact] ATT | IPO/AMP1/AMP2 << 2 | {2 FM, DNF} << 4 */
    uint8_t cw_apf_contour_notch_agc;            /* +0x00D [fact] 0x80 CW indicator, 0x40 APF, 0x20 CONTOUR, 0x10 NOTCH, bits 0-2 AGC */
    uint8_t txvfo_flags;                         /* +0x00E [fact] bit 6, bit 5 keyer, bit 4 monitor, bit 2 BK-IN/VOX; FM: repeater shift + 1 */
    uint8_t tone_tuner_msg;                      /* +0x00F [fact] FM tone mode | tuner << 3 | message/keyer state << 6 */
    uint8_t peak;                                /* +0x010 [fact] PEAK (bits 0-2) | MAIN UI +0x6F << 4 (gui.md: PEAK LV1-LV5) */
    uint8_t span_ccf;                            /* +0x011 [fact] span index | CENTER/CURSOR/FIX << 6 */
    uint8_t speed_color;                         /* +0x012 [fact] scope SPEED << 4 | COLOR (gui.md; FUN_2012C6C4) */
    uint8_t width_default_be[2];                 /* +0x013 [fact] default WIDTH of the mode in Hz, big-endian */
    uint8_t zero_in[4];                          /* +0x015 [fact] CW zero-in indicator (MAIN table 0xFFF804DE) */
    uint8_t contour_be[2];                       /* +0x019 [fact] CONTOUR frequency / 10, big-endian; bit 7 of byte 0 = CONTOUR LEVEL negative */
    uint8_t notch_be[2];                         /* +0x01B [fact] NOTCH frequency / 10, big-endian */
    uint8_t width_be[2];                         /* +0x01D [fact] WIDTH in Hz, big-endian */
    uint8_t shift_be[2];                         /* +0x01F [fact] IF SHIFT in Hz, big-endian */
    uint8_t apf_offset;                          /* +0x021 [fact] APF offset (CO03) */
    uint8_t cw_pitch;                            /* +0x022 [fact] CW pitch / 10 Hz - 30 (MAIN 0x9C04 + 30) */
    uint8_t dsp_knob;                            /* +0x023 [fact] bit 7 FUNC panel open, bit 6, bit 5 shift != 0, bit 4 width != default, bit 2, bits 0-1 DSP-knob function */
    uint8_t dvs;                                 /* +0x024 [fact] voice-memory channel | DVS state << 4 (audio_error_check) */
    uint8_t scope_cfg[6];                        /* +0x025 [fact] scope settings, bytes 37-42 (CENTER/CURSOR/FIX, 3DSS, ..., EXPAND) */
    uint8_t const_ff;                            /* +0x02B [fact] always 0xFF */
    uint8_t func_knob;                           /* +0x02C [fact] FUNC-knob function code (scr_main_layout) */
    struct ml_vfo main_vfo;                      /* +0x02D [fact] VFO block of the main side, bytes 45-69 */
    struct ml_vfo sub_vfo;                       /* +0x046 [fact] VFO block of the other side, bytes 70-94 */
    uint8_t meter;                               /* +0x05F [fact] meter value: S-meter in RX, else the meter_sel quantity (meter_draw) */
    uint8_t tune_lock;                           /* +0x060 [fact] FINE/FAST | LOCK << 2 | NB << 3 | DNR << 4 */
    uint8_t zero_61[6];                          /* +0x061 [fact] always 0 (bytes 97-102) */
    uint8_t f_0x67_u8;                           /* +0x067 [fact: accessed] MAIN writes 0 (byte 103); FUN_20130C90 compares bits 6-7 and 0-5 with the new frame */
    uint8_t rtty;                                /* +0x068 [fact] RTTY shift (2 bits) | polarity << 7 (FUN_20130C90, FUN_201227D8) */
    uint8_t psk;                                 /* +0x069 [fact] PSK/DATA setting << 4 (MAIN 0x9A79) */
    uint8_t key_speed;                           /* +0x06A [fact] key speed (KS) */
    uint8_t f_0x6b_u8;                           /* +0x06B [fact: accessed] MAIN writes 0 (byte 107); FUN_20130C90 */
    uint8_t f_0x6c_u8;                           /* +0x06C [fact: accessed] MAIN writes 0 (byte 108); FUN_20130C90 */
    uint8_t f_0x6d_u8;                           /* +0x06D [fact: accessed] MAIN writes 0 (byte 109); FUN_20130C90 */
    uint8_t f_0x6e_u8;                           /* +0x06E [fact: accessed] MAIN writes 0 (byte 110); FUN_20130C90 */
    uint8_t f_0x6f_u8;                           /* +0x06F [fact: accessed] MAIN writes 0 (byte 111); FUN_20130C90 */
    uint8_t text_view_sets;                      /* +0x070 [fact] low nibble -> 0x208084D9, the text sets of the scope text view (FUN_20131638; gui.md); MAIN writes 0 (byte 112) */
    uint8_t osc;                                 /* +0x071 [fact] OSC time (3 bits) | AF-FFT att << 5 | 0x18 (FUN_2012CAAC) */
    uint8_t zero_72;                             /* +0x072 [fact] always 0 (byte 114) */
    uint8_t data_offset_be[2];                   /* +0x073 [fact] DATA offset in Hz, big-endian (be16_load) */
    uint8_t op_freq_be[4];                       /* +0x075 [fact] operating frequency in Hz, u32 big-endian (be32_load) */
    uint8_t tx_freq_be[4];                       /* +0x079 [fact] TX frequency, big-endian */
    uint8_t dial_freq_be[4];                     /* +0x07D [fact] dial frequency, big-endian (FUN_2012CF30) */
    uint8_t scope_start_be[4];                   /* +0x081 [fact] scope start frequency, big-endian (FUN_2012CF30) */
    uint8_t zero_85[19];                         /* +0x085 [fact] always 0 (bytes 133-151); a status-only frame has its checksum at +0x98 */
    uint8_t payload[424];                        /* +0x098 [fact] the screen's own data (display-link.md "Payloads after the status block"; 0x30/0x31 popup code at +0x98 ...) */
};

/* ---------------------------------------------------------------- MAIN-link driver variables (.data 0x20450024..0x20450073, mainlink.md section 12) */

struct ml_state {  /* size 0x50: MAIN-link driver state, module .data at 0x20450024 */
    uint8_t got24;                               /* +0x000 0x20450024 [fact] "new 0x24 frame" flag (task_mainlink_dispatch, mainlink_get_settings24) */
    uint8_t got21;                               /* +0x001 0x20450025 [fact] "new 0x21 frame" flag */
    uint8_t got60;                               /* +0x002 0x20450026 [fact] "new 0x60 frame" flag (mainlink_got_frame60) */
    uint8_t fwupdate_armed;                      /* +0x003 0x20450027 [fact] firmware-update menu armed (mainlink_queue_frame, gui_main_loop) */
    uint8_t hello_acked;                         /* +0x004 0x20450028 [fact] hello (F0) acknowledged (mainlink_rx_parse, mainlink_hello_poweron) */
    uint8_t err_box_on_fail;                     /* +0x005 0x20450029 [fact] on link failure show an error box instead of resetting (0x60 frame +0xD = 0xDB; mainlink_rx_validate, task_mainlink_retry) */
    uint8_t ack_pending;                         /* +0x006 0x2045002A [fact] a frame waits for its ACK (mainlink_submit, mainlink_on_ack) */
    uint8_t enc_queue_mask;                      /* +0x007 0x2045002B [fact] encoder-queue mask (mainlink_send_enc, mainlink_flush_enc) */
    uint8_t retry_count;                         /* +0x008 0x2045002C [fact] resend count (mainlink_on_nak, mainlink_submit) */
    uint8_t wait_cmd;                            /* +0x009 0x2045002D [fact] command waiting for its ACK (mainlink_set_wait_cmd / mainlink_get_wait_cmd) */
    uint8_t e0_wr;                               /* +0x00A 0x2045002E [fact] E0 ring write index (mainlink_submit) */
    uint8_t e0_rd;                               /* +0x00B 0x2045002F [fact] E0 ring read index (mainlink_flush_parked) */
    uint8_t pot5_last[2];                        /* +0x00C 0x20450030 [fact: accessed] pot5_filter state */
    uint8_t pot4_last[2];                        /* +0x00E 0x20450032 [fact: accessed] pot4_filter state */
    uint8_t last_rx_cmd;                         /* +0x010 0x20450034 [fact] command byte of the last frame the dispatcher got (06/15/1B tested; mainlink_send_key compares it with 0x7C) */
    uint8_t last21;                              /* +0x011 0x20450035 [fact] payload of the last 0x21 frame (FUN_2011503C) */
    uint8_t f_0x12_u8;                           /* +0x012 0x20450036 [fact: accessed] FUN_2011503C */
    uint8_t f_0x13_u8;                           /* +0x013 0x20450037 [fact: accessed] FUN_2011503C */
    uint32_t resend_len;                         /* +0x014 0x20450038 [fact] length of the frame kept for a resend (mainlink_submit, task_mainlink_retry) */
    uint32_t pot5_sum;                           /* +0x018 0x2045003C [fact: accessed] pot5_filter (u32) */
    uint8_t pot5_hist[4];                        /* +0x01C 0x20450040 [fact: accessed] pot5_filter (read as u32 and as bytes) */
    uint32_t pot4_sum;                           /* +0x020 0x20450044 [fact: accessed] pot4_filter (u32) */
    uint8_t pot4_hist[4];                        /* +0x024 0x20450048 [fact: accessed] pot4_filter (read as u32 and as bytes) */
    uint32_t retry_flg;                          /* +0x028 0x2045004C [fact] retry event flag id (mainlink_init: acre_flg(cflg_mainlink_retry)) */
    uint32_t pace_count;                         /* +0x02C 0x20450050 [fact] pacing counter, decremented every 1 ms by task_cmd_interval */
    uint32_t pace_sem;                           /* +0x030 0x20450054 [fact] semaphore id of the pacing counter (mainlink_init) */
    uint32_t enc_sem;                            /* +0x034 0x20450058 [fact] encoder-queue semaphore id (mainlink_init) */
    uint32_t got_esc;                            /* +0x038 0x2045005C [fact] 0x1B (ESC) received (mainlink_got_esc) */
    uint8_t *link_obj;                           /* +0x03C 0x20450060 [fact] the link object 0x2045FD40 (mainlink_obj_ctor; +0x10 its scif_uart, +0x14 the RX flag id) */
    uint32_t ack_tmo_cyc;                        /* +0x040 0x20450064 [fact] ACK-timeout cyclic handler id (mainlink_init) */
    uint8_t last_e1[5];                          /* +0x044 0x20450068 [fact] last E1 frame, the resend copy (mainlink.md) */
    uint8_t settings24[7];                       /* +0x049 0x2045006D [fact] settings from the last 0x24 frame (mainlink.md; FUN_201636F8) */
};

/* ---------------------------------------------------------------- typed globals */

struct knl_sys knl_sys;                          /* @0x208003A8 [inference] NORTi system variables (layout above) */
struct knl_tcb *knl_tsk_tab[65];                 /* @0x208DBBA0 [fact] TCB per task id 1..64 (slot 0 unused; the idle id 65 is the next table's slot 0); itron_acre_tsk, every task call */
struct knl_sem *knl_sem_tab[64];                 /* @0x208DBCA4 [fact] semaphore per id 1..64 (slot 0 unused, id 64 is knl_flg_tab[0]); itron_acre_sem, itron_sig_sem, itron_twai_sem */
struct knl_flg *knl_flg_tab[64];                 /* @0x208DBDA4 [fact] event flag per id 1..64 (slot 0 unused); itron_acre_flg, itron_set_flg, itron_twai_flg, itron_clr_flg */
struct knl_mpf *knl_mpf_tab[16];                 /* @0x208DBF24 [fact] fixed-size pool per id 1..16 (slot 0 unused); itron_acre_mpf, itron_tget_mpf, itron_rel_mpf */
struct knl_mtx *knl_mtx_tab[32];                 /* @0x208DBFC4 [fact] mutex per id 1..32 (slot 0 unused); itron_acre_mtx, itron_tloc_mtx, itron_unl_mtx */
uint8_t knl_rdq[10];                             /* @0x208DC18C [fact] [0] running task id (max id + 1 = idle; itron_get_tid), [1..8] ready-queue head per priority (itron_rot_rdq), [9] cleared at init */
struct boot_info g_bootinfo;                     /* @0x208DBB44 [fact] copy of the boot-info block (bootinfo_load; 0x60 bytes copied, see above) */
struct scif_uart scif3_uart;                     /* @0x208DA1E0 [fact] SCIF3 UART object (scif3_get) */
struct scif_uart scif4_uart;                     /* @0x208DAA30 [fact] SCIF4 UART object (scif4_get; the unused SCIF4 link, mainlink.md section 10) */
struct scif_uart scif5_uart;                     /* @0x208DB280 [fact] SCIF5 UART object, the MAIN link (scif5_get) */
struct ml_state g_ml;                            /* @0x20450024 [fact] MAIN-link driver variables (mainlink.md section 12) */
struct ml_frame ml_rx_frame;                     /* @0x2045F260 [fact] latest MAIN frame (task_mainlink_dispatch copies every frame but 06/15/1B here) */
struct ml_frame ml_gui_snapshot;                 /* @0x2045F8C0 [fact] the GUI snapshot (mainlink_get_last_frame copies it out) */
struct ml_frame gui_frame;                       /* @0x208F0B2A [fact] frame currently on screen: gui_screen_update compares the snapshot with it and copies the new frame over it */
struct ml_frame gui_frame_saved;                 /* @0x208F0FCB [fact] saved frame that mainlink_inject_rx replays (gui_screen_update) */
struct t_cflg cflg_keycode;                      /* @0x20165548 [fact] event flag of task_keycode (keycode_init) */
struct t_cflg cflg_renc;                         /* @0x201655E8 [fact] event flag created by renc_init */
struct t_cflg cflg_powon;                        /* @0x20165738 [fact] event flag created by powon_init */
struct t_cflg cflg_uart4;                        /* @0x201657F8 [fact] RX flag of the SCIF4 object (uart4_link_init) */
struct t_cflg cflg_mainlink_rx;                  /* @0x201658B8 [fact] RX flag of the SCIF5 object (mainlink_init: scif5_get(flag)) */
struct t_cflg cflg_mainlink_retry;               /* @0x201658F4 [fact] retry flag, id in g_ml.retry_flg (mainlink_init) */
struct t_cmtx cmtx_2016533c;                     /* @0x2016533C [fact] TA_INHERIT mutex packet (the only constant T_CMTX; itron_acre_mtx) */
struct t_ctsk ctsk_tsc2007_51a8;                 /* @0x201651A8 [fact] "tsc2007": task_tsc2007, pri 5, stack 0x100; touch_init */
struct t_ctsk ctsk_tsc2007_51c4;                 /* @0x201651C4 [fact] "tsc2007": task_tsc2007_irq, pri 4, stack 0x100; touch_init */
struct t_ctsk ctsk_audio_codec;                  /* @0x20165314 [fact] "audio_codec": task_audio_codec, pri 5, stack 0x2400; audio_codec_init */
struct t_ctsk ctsk_dspup;                        /* @0x20165478 [fact] "dspup": update_dsp, pri 3, stack 0x800; dspup_init */
struct t_ctsk ctsk_fwupdate;                     /* @0x201654A0 [fact] "fwupdate": task_fwupdate, pri 8, stack 0x2400; fwupdate_init */
struct t_ctsk ctsk_uptest;                       /* @0x201654C8 [fact] "uptest": update_main_cpu, pri 3, stack 0x2000; uptest_init */
struct t_ctsk ctsk_sdmenu;                       /* @0x201654F8 [fact] "sdmenu": task_sdmenu, pri 8, stack 0x2000; sdmenu_init */
struct t_ctsk ctsk_keycode;                      /* @0x2016552C [fact] "keycode": task_keycode, pri 5, stack 0x800; keycode_init */
struct t_ctsk ctsk_spi_slave_task;               /* @0x20165554 [fact] "spi_slave_task": task_spi_slave, pri 5, stack 0x100; spi_slave_init */
struct t_ctsk ctsk_ad_renc;                      /* @0x20165594 [fact] "ad renc": task_ad_renc, pri 5, stack 0x400; renc_init */
struct t_ctsk ctsk_detect_renc;                  /* @0x201655B0 [fact] "detect renc": task_detect_renc, pri 5, stack 0x400; renc_init */
struct t_ctsk ctsk_renc;                         /* @0x201655CC [fact] "renc": task_renc, pri 5, stack 0x400; renc_init */
struct t_ctsk ctsk_key;                          /* @0x201656A8 [fact] "key": task_key, pri 5, stack 0x400; key_init */
struct t_ctsk ctsk_mouse_cursor_56e4;            /* @0x201656E4 [fact] "mouse_cursor": cpp_task_thunk, pri 7, stack 0x400; mouse_cursor_init */
struct t_ctsk ctsk_mouse_cursor_5700;            /* @0x20165700 [fact] "mouse_cursor": cpp_task_thunk, pri 7, stack 0x400; mouse_cursor_task_create */
struct t_ctsk ctsk_powon;                        /* @0x2016571C [fact] "powon": task_powon, pri 3, stack 0x400; powon_init */
struct t_ctsk ctsk_uart4_57dc;                   /* @0x201657DC [fact] "uart4": cpp_task_thunk, pri 7, stack 0x400; uart4_link_init (no caller) */
struct t_ctsk ctsk_uart4_5804;                   /* @0x20165804 [fact] "uart4": cpp_task_thunk, pri 4, stack 0x400; uart4_obj_run */
struct t_ctsk ctsk_uart4_5820;                   /* @0x20165820 [fact] "uart4": cpp_task_thunk, pri 4, stack 0x400; uart4_obj_run */
struct t_ctsk ctsk_uart4_583c;                   /* @0x2016583C [fact] "uart4": cpp_task_thunk, pri 4, stack 0x400; uart4_obj_run */
struct t_ctsk ctsk_uart_5880;                    /* @0x20165880 [fact] "uart": cpp_task_thunk, pri 7, stack 0x2000; mainlink_init (link object task) */
struct t_ctsk ctsk_cmd_interval;                 /* @0x2016589C [fact] "cmd_interval": task_cmd_interval, pri 3, stack 0x100; mainlink_init */
struct t_ctsk ctsk_retry;                        /* @0x201658D8 [fact] "retry": task_mainlink_retry, pri 4, stack 0x2000; mainlink_init */
struct t_ctsk ctsk_uart_5900;                    /* @0x20165900 [fact] "uart": cpp_task_thunk, pri 3, stack 0x2000; mainlink_obj_run (RX, mainlink.md) */
struct t_ctsk ctsk_uart_591c;                    /* @0x2016591C [fact] "uart": cpp_task_thunk, pri 4, stack 0x2000; mainlink_obj_run (dispatcher) */
struct t_ctsk ctsk_uart_5938;                    /* @0x20165938 [fact] "uart": cpp_task_thunk, pri 4, stack 0x2000; mainlink_obj_run (TX) */
struct t_ctsk ctsk_cli;                          /* @0x20165968 [fact] "cli": task_cli, pri 5, stack 0x2000; cli_init */
struct t_ctsk ctsk_root;                         /* @0x20165A44 [fact] "root": task_root, pri 8, stack 0x2000, TA_ACT; main */
struct t_ctsk ctsk_test_disp;                    /* @0x20420088 [fact] "test_disp": task_test_disp, pri 5, stack 0x2400; test_disp_init */
struct t_cisr cisr_tsc2007_tint_isr;             /* @0x20165194 [fact] GIC ID 35 -> tsc2007_tint_isr, intpri 5; task_tsc2007 */
struct t_cisr cisr_renc_irq4_isr;                /* @0x20165580 [fact] GIC ID 36 -> renc_irq4_isr, intpri 5; renc_init */
struct t_cisr cisr_powon_isr;                    /* @0x20165744 [fact] GIC ID 37 -> powon_isr, intpri 5; powon_init */
struct t_cisr cisr_scif3_txi_isr;                /* @0x20165764 [fact] GIC ID 236 -> scif3_txi_isr, intpri 10; scif3_get -> uart_obj_init */
struct t_cisr cisr_scif3_rxi_isr;                /* @0x20165778 [fact] GIC ID 235 -> scif3_rxi_isr, intpri 10; scif3_get -> uart_obj_init */
struct t_cisr cisr_scif4_txi_isr;                /* @0x2016578C [fact] GIC ID 240 -> scif4_txi_isr, intpri 10; scif4_get -> uart_obj_init */
struct t_cisr cisr_scif4_rxi_isr;                /* @0x201657A0 [fact] GIC ID 239 -> scif4_rxi_isr, intpri 10; scif4_get -> uart_obj_init */
struct t_cisr cisr_scif5_txi_isr;                /* @0x201657B4 [fact] GIC ID 244 -> scif5_txi_isr, intpri 10; scif5_get -> uart_obj_init */
struct t_cisr cisr_scif5_rxi_isr;                /* @0x201657C8 [fact] GIC ID 243 -> scif5_rxi_isr, intpri 10; scif5_get -> uart_obj_init */
struct t_cisr cisr_periodic_wakeup_isr;          /* @0x20165954 [fact] GIC ID 135 (OSTM1) -> periodic_wakeup_isr, intpri 5; periodic_wakeup_start */
struct t_cisr cisr_ostm0_tick_isr;               /* @0x20165A60 [fact] GIC ID 134 (OSTM0) -> ostm0_tick_isr, intpri 5; ostm_init */
struct t_cisr cisr_rspi0_spti_isr;               /* @0x20166A84 [fact] GIC ID 272 -> rspi0_spti_isr, intpri 10; rspi0_open, rspi0_open_irq_only */
struct t_cisr cisr_rspi0_spri_isr;               /* @0x20166A98 [fact] GIC ID 271 -> rspi0_spri_isr, intpri 10; rspi0_open, rspi0_open_irq_only */
struct t_cisr cisr_rspi1_spti_isr;               /* @0x20166AAC [fact] GIC ID 275 -> rspi1_spti_isr, intpri 10; rspi1_open, rspi1_open_irq_only */
struct t_cisr cisr_rspi1_spri_isr;               /* @0x20166AC0 [fact] GIC ID 274 -> rspi1_spri_isr, intpri 10; rspi1_open, rspi1_open_irq_only */
struct t_cisr cisr_rspi2_spti_isr;               /* @0x20166AD4 [fact] GIC ID 278 -> rspi2_spti_isr, intpri 10; rspi2_open */
struct t_cisr cisr_rspi2_spri_isr;               /* @0x20166AE8 [fact] GIC ID 277 -> rspi2_spri_isr, intpri 10; rspi2_open */
struct t_cisr cisr_rspi3_spti_isr;               /* @0x20166AFC [fact] GIC ID 281 -> rspi3_spti_isr, intpri 10; rspi3_open */
struct t_cisr cisr_rspi3_spri_isr;               /* @0x20166B10 [fact] GIC ID 280 -> rspi3_spri_isr, intpri 10; rspi3_open */
struct t_cisr cisr_rspi4_spti_isr;               /* @0x20166B24 [fact] GIC ID 284 -> rspi4_spti_isr, intpri 10; rspi4_open */
struct t_cisr cisr_rspi4_spri_isr;               /* @0x20166B38 [fact] GIC ID 283 -> rspi4_spri_isr, intpri 10; rspi4_open */
struct t_cisr cisr_int191;                       /* @0x20166C28 [fact] GIC ID 191 -> FUN_201203DC, intpri 9; FUN_2011FC8C */
struct t_cisr cisr_int190;                       /* @0x20166C3C [fact] GIC ID 190 -> FUN_201203D4, intpri 9; FUN_2011FC8C */
struct t_cisr cisr_int189;                       /* @0x20166C50 [fact] GIC ID 189 -> FUN_201203E4, intpri 9; FUN_2011FC8C */
struct t_cisr cisr_int199;                       /* @0x20166C64 [fact] GIC ID 199 -> FUN_201203F4, intpri 9; FUN_2011FD1C */
struct t_cisr cisr_int198;                       /* @0x20166C78 [fact] GIC ID 198 -> FUN_201203EC, intpri 9; FUN_2011FD1C */
struct t_cisr cisr_int197;                       /* @0x20166C8C [fact] GIC ID 197 -> FUN_201203FC, intpri 9; FUN_2011FD1C */
struct t_cisr cisr_int207;                       /* @0x20166CA0 [fact] GIC ID 207 -> FUN_2012040C, intpri 9; FUN_2011FDAC */
struct t_cisr cisr_int206;                       /* @0x20166CB4 [fact] GIC ID 206 -> FUN_20120404, intpri 9; FUN_2011FDAC */
struct t_cisr cisr_int205;                       /* @0x20166CC8 [fact] GIC ID 205 -> FUN_20120414, intpri 9; FUN_2011FDAC */
struct t_cisr cisr_int215;                       /* @0x20166CDC [fact] GIC ID 215 -> FUN_20120424, intpri 9; FUN_2011FE34 */
struct t_cisr cisr_int214;                       /* @0x20166CF0 [fact] GIC ID 214 -> FUN_2012041C, intpri 9; FUN_2011FE34 */
struct t_cisr cisr_int213;                       /* @0x20166D04 [fact] GIC ID 213 -> FUN_2012042C, intpri 9; FUN_2011FE34 */
struct t_cisr cisr_int78;                        /* @0x203A706C [fact] GIC ID 78 (VDC5 ch0 GR3_VLINE, gui.md) -> FUN_20118638, intpri 5; vdc5_isr_create */
struct t_cisr cisr_sdr_ss_isr;                   /* @0x203A7080 [fact] GIC ID 535 -> sdr_ss_isr, intpri 5; link_ss_irq_init */
struct t_cisr cisr_dsp_ss_isr;                   /* @0x203A7094 [fact] GIC ID 449 -> dsp_ss_isr, intpri 5; link_ss_irq_init */
struct t_cisr cisr_dmac3_isr;                    /* @0x204200B0 [fact] GIC ID 44 -> dmac3_isr, intpri 5; dmac3_rspi4_tx_setup */
struct t_cisr cisr_dmac4_isr;                    /* @0x204200C4 [fact] GIC ID 45 -> dmac4_isr, intpri 5; dmac4_rspi4_rx_setup */
struct t_cisr cisr_dmac5_isr;                    /* @0x204200D8 [fact] GIC ID 46 -> dmac5_isr, intpri 5; dmac5_rspi2_rx_setup */
struct t_cisr cisr_dmac9_isr;                    /* @0x204200EC [fact] GIC ID 50 -> dmac9_isr, intpri 5; dmac9_register_isr */
struct t_cisr cisr_dmac10_isr;                   /* @0x20420100 [fact] GIC ID 51 -> dmac10_isr, intpri 5; dmac10_register_isr */

/* ---------------------------------------------------------------- return types */

struct scif_uart *scif4_get(uint32_t flg);      /* @0x201148D8 return [fact] &scif4_uart after uart_obj_init */
struct scif_uart *scif5_get(uint32_t flg);      /* @0x201148B4 return [fact] &scif5_uart after uart_obj_init */

/* ---------------------------------------------------------------- parameter types
 * Only handlers of status-carrying frames (byte 1..0x97 = the status block) take struct ml_frame; the short frames
 * (0x21, 0x23, 0x3F, 0x43, 0x64, 0x65, 0x7A..0x7C: rtc_set_from_main, rec_start_stop, pkt23_tx_text, scr_lcd_test,
 * scr_sd_menu) use bytes 1.. for their own data and stay untyped. */

uint32_t itron_acre_tsk(uint32_t tskid, struct t_ctsk *pk_ctsk);            /* @0x201500F4 params [fact] T_CTSK reader (above) */
uint32_t itron_acre_isr(uint32_t isrid, struct t_cisr *pk_cisr);            /* @0x2014F1A8 params [fact] T_CISR reader */
uint32_t itron_acre_sem(uint32_t semid, struct t_csem *pk_csem);            /* @0x2014FF2C params [fact] T_CSEM reader */
uint32_t itron_acre_flg(uint32_t flgid, struct t_cflg *pk_cflg);            /* @0x2014EFFC params [fact] T_CFLG reader */
uint32_t itron_acre_mtx(uint32_t mtxid, struct t_cmtx *pk_cmtx);            /* @0x2014FD24 params [fact] T_CMTX reader */
uint32_t itron_acre_mpf(uint32_t mpfid, struct t_cmpf *pk_cmpf);            /* @0x2014F8B8 params [fact] T_CMPF reader */
void knl_timeout_add(int32_t tmout, struct knl_tcb *tcb, uint8_t tskid);   /* @0x20154498 params [fact] (tmout, TCB, task id) */
void knl_timeout_remove(struct knl_tcb *tcb, uint32_t tskid);             /* @0x20153AD4 params [fact] (TCB, task id) */
void FUN_201538d4(uint8_t *queue, struct knl_tcb *tcb, uint8_t tskid);   /* @0x201538D4 params [fact] links the task at the tail of the circular queue whose head byte is *queue */
void FUN_201539ec(struct knl_tcb *tcb, uint32_t tskid);                  /* @0x201539EC params [fact] unlinks the task from its queue */
void FUN_20153a38(uint8_t *queue, struct knl_tcb *tcb, uint32_t tskid);  /* @0x20153A38 params [fact] unlinks the task and links it into *queue (chg_pri, tloc_mtx) */
uint32_t uart_obj_init(struct scif_uart *uart, struct scif_regs *regs, struct t_cisr *rxi, struct t_cisr *txi, uint32_t flg);  /* @0x20162FAC params [fact] */
struct scif_uart *scif3_get(uint32_t flg);                                /* @0x201148FC params [fact] returns &scif3_uart; no committed prototype, so this line sets it whole */
void scif_rxi_isr(struct scif_uart *uart);                                 /* @0x20162DD8 params [fact] scifN_rxi_isr pass &scifN_uart */
void scif_txi_isr(struct scif_uart *uart);                                 /* @0x20162F10 params [fact] */
void scif_irq_off(struct scif_uart *uart);                                 /* @0x20163014 params [fact] */
int32_t scif_read(struct scif_uart *uart, uint8_t *buf, int32_t n);        /* @0x20163038 params [fact] */
void scif_start(struct scif_uart *uart, uint32_t baud, int32_t bits, int32_t parity, uint32_t stop);  /* @0x20163098 params [fact] scif_open, then enables both interrupts */
void scif_open(struct scif_uart *uart, uint32_t baud, int32_t bits, int32_t parity, uint32_t stop);  /* @0x201630CC params [fact] */
uint32_t scif_flush(struct scif_uart *uart);                               /* @0x20163280 params [fact] */
uint32_t scif_write(struct scif_uart *uart, uint8_t *buf, uint32_t n);     /* @0x201632D8 params [fact] */
uint8_t scif_has_flag(struct scif_uart *uart);                             /* @0x20163654 params [fact] */
void mainlink_get_last_frame(struct ml_frame *dst);                        /* @0x20115000 params [fact] copies ml_gui_snapshot to dst */
uint8_t mainlink_last_frame_differs(struct ml_frame *frame);               /* @0x2011506C params [fact] memcmp with ml_gui_snapshot */
void mainlink_set_last_frame(struct ml_frame *src);                        /* @0x2011508C params [fact] copies src to ml_gui_snapshot */
void mainlink_inject_rx(struct ml_frame *frame);                           /* @0x20116560 params [fact] posts gui_frame_saved to the dispatcher */
void FUN_2012194c(struct ml_frame *frame);                                 /* @0x2012194C params [fact] gui_screen_update passes (new frame, gui_frame, 0); reads frame +0x9A */
void scr_playlist(struct ml_frame *frame, struct ml_frame *old);           /* @0x20124C24 params [fact] gui_screen_update: (new frame, gui_frame) */
void scr_info(struct ml_frame *frame);                                     /* @0x201263E8 params [fact] */
void scr_confirm(struct ml_frame *frame, uint32_t flag);                   /* @0x20126EBC params [fact] */
void scr_setup_menu(struct ml_frame *frame, struct ml_frame *old, int32_t flag);  /* @0x20126F28 params [fact] */
void scr_keyboard(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x201275E8 params [fact] */
void scr_memory_list(struct ml_frame *frame, int32_t flag);               /* @0x20127B24 params [fact] */
void scr_text_list(struct ml_frame *frame, struct ml_frame *old, int32_t flag);   /* @0x20129054 params [fact] */
void vfo_audio_status_draw(struct ml_frame *frame, int32_t flag);         /* @0x201293F8 params [fact] */
void scr_vfo(struct ml_frame *frame, struct ml_frame *old, int32_t flag); /* @0x2012A6A4 params [fact] */
void scr_func_panel(struct ml_frame *frame, int32_t flag);                /* @0x2012A9EC params [fact] */
void scr_value_popup(struct ml_frame *frame);                              /* @0x2012ADE0 params [fact] popup slot = payload[0] (gui.md) */
void scr_select_popup(struct ml_frame *frame, struct ml_frame *old, int32_t flag);  /* @0x2012C1B4 params [fact] */
uint32_t FUN_2012c2d8(struct ml_frame *frame, struct ml_frame *old);       /* @0x2012C2D8 params [fact] gui_screen_update: (new frame, gui_frame or 0) */
void audio_error_check(struct ml_frame *frame);                            /* @0x2012C4A0 params [fact] */
void FUN_2012c6c4(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012C6C4 params [fact] scr_main_layout passes its three arguments */
void FUN_2012caac(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012CAAC params [fact] scr_main_layout */
void FUN_2012cf30(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012CF30 params [fact] scr_main_layout */
void scope_area_setup(struct ml_frame *frame, struct ml_frame *old, int32_t flag);  /* @0x2012D52C params [fact] scr_main_layout */
void FUN_2012d8bc(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012D8BC params [fact] scr_main_layout */
void FUN_2012e1a4(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012E1A4 params [fact] scr_main_layout */
void FUN_2012e27c(struct ml_frame *frame, struct ml_frame *old, int32_t flag);    /* @0x2012E27C params [fact] scr_main_layout */
void scr_main_layout(struct ml_frame *frame, struct ml_frame *old, int32_t flag); /* @0x2012E3E0 params [fact] gui_screen_update: (new frame, gui_frame, flag) */
void FUN_2012e678(struct ml_frame *frame, struct ml_frame *old);           /* @0x2012E678 params [fact] gui_screen_update: (new frame, gui_frame) */
void FUN_2012ea74(struct ml_frame *frame, struct ml_frame *old);           /* @0x2012EA74 params [fact] gui_screen_update: (new frame, gui_frame) */
void FUN_20130c90(uint32_t item, struct ml_frame *frame, int32_t flag);    /* @0x20130C90 params [fact] FUN_201310EC calls it for items 0..15; compares frame +0x67..+0x71 with gui_frame */
void meter_draw_scale(struct ml_frame *frame, struct ml_frame *old, int32_t flag);  /* @0x20134D24 params [fact] scr_main_layout */
