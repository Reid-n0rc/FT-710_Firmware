/*
 * FT-710 DISPLAY (T24 round 4): a minimal stand-in for the NORTi uITRON 4.0 kernel, with the itron_* interface of
 * include/norti.h, for a source-only build of the DISPLAY program.
 *
 * It is not a recreation of NORTi (MiSPO's kernel is closed; its internals in the image, docs/code/display/
 * boot-rtos.md section 4, are touched directly by other code of the image, so the hybrid link keeps the original
 * kernel). It implements the services the image calls, with uITRON 4.0 semantics as far as the image relies on them:
 * tasks with priorities 1..16 (lower number first; round robin with rot_rdq), sleep and delay, semaphores, event
 * flags (TA_CLR, TWF_ANDW/TWF_ORW), mailboxes (messages linked through their first word), message buffers (byte
 * ring, length-prefixed), mutexes (no priority inheritance), cyclic handlers and interrupt service routines.
 * Timeouts are in ticks of NORTI_TICK_MS milliseconds; norti_tick() advances time and must be called from the
 * system-timer interrupt (in the image OSTM0 every 10 ms, ostm0_tick_isr). Rescheduling happens in the service
 * calls and in norti_tick's caller through norti_dispatch(): this stand-in does not preempt a task from inside an
 * interrupt (the port's interrupt exit would call norti_dispatch for that).
 *
 * Context switch: rtos/norti_port.S. Checked in Unicorn by tools/test_norti_standin.py (two tasks, every object
 * type); nothing here has been run on a radio.
 */
#include <stddef.h>
#include <stdint.h>
#include "norti.h"

#define NORTI_TICK_MS 10
#define MAX_TSK 40
#define MAX_SEM 64
#define MAX_FLG 64
#define MAX_MBX 16
#define MAX_MBF 16
#define MAX_MTX 32
#define MAX_CYC 8
#define MAX_ISR 64
#define MAX_PRI 16
#define E_ILUSE (-28)
#define E_NOSPT (-9)
#define E_RLWAI (-49)

enum { TS_NONE, TS_DORMANT, TS_READY, TS_WAIT };
enum { W_NONE, W_SLP, W_DLY, W_SEM, W_FLG, W_MBX, W_MBF_S, W_MBF_R, W_MTX };

typedef struct
{
    uint32_t *sp;            /* saved stack pointer (norti_port.S) */
    uint8_t state, wait, pri, base_pri;
    uint32_t seq;            /* order of arrival in the ready queue or a wait queue */
    int wobj;                /* object the task waits on */
    int32_t tmo;             /* ticks left, -1 = forever */
    ER wer;                  /* result of the wait */
    int wupcnt;
    /* wait parameters and results */
    FLGPTN wptn, rptn;
    unsigned wmode;
    void *msg;
    unsigned msgsz;
    const T_CTSK *ctsk;
    uint32_t *stk_top;
    intptr_t stacd;
} tcb_t;

typedef struct { int used, cnt, max; } sem_t;
typedef struct { int used; ATR atr; FLGPTN ptn; } flg_t;
typedef struct { int used; void *head, *tail; } mbx_t;
typedef struct { int used; uint8_t *buf; unsigned size, maxmsz, rd, wr, used_b; } mbf_t;
typedef struct { int used; ID owner; } mtx_t;
typedef struct { int used, run; uint32_t period, left; void (*hdr)(intptr_t); intptr_t exinf; } cyc_t;
typedef struct { uint32_t intno; void (*isr)(void); } isr_t;

static tcb_t tcb[MAX_TSK + 1];
static sem_t sem[MAX_SEM + 1];
static flg_t flg[MAX_FLG + 1];
static mbx_t mbx[MAX_MBX + 1];
static mbf_t mbf[MAX_MBF + 1];
static mtx_t mtx[MAX_MTX + 1];
static cyc_t cyc[MAX_CYC + 1];
static isr_t isr_tab[MAX_ISR];
static ID run_id;            /* running task, 0 = the start-up / idle context */
static uint32_t *idle_sp;
static uint32_t seq_now;
static uint64_t sys_ms;
static int cpu_locked;

/* norti_port.S */
void norti_switch(uint32_t **save, uint32_t *next);
uint32_t *norti_stack_init(uint32_t *top, void (*entry)(void));

/* creation with id 0 = the first free id (the image always passes 0) */
#define ALLOC_ID(tab, max, id)                     \
    do                                             \
    {                                              \
        if ((id) == 0)                             \
        {                                          \
            for ((id) = 1; (id) <= (max); (id)++)  \
            {                                      \
                if (!tab[(id)].used)               \
                {                                  \
                    break;                         \
                }                                  \
            }                                      \
            if ((id) > (max))                      \
            {                                      \
                return E_NOID;                     \
            }                                      \
        }                                          \
        else if ((id) < 0 || (id) > (max))         \
        {                                          \
            return E_ID;                           \
        }                                          \
        else if (tab[(id)].used)                   \
        {                                          \
            return E_OBJ;                          \
        }                                          \
    } while (0)

static tcb_t *cur(void)
{
    return run_id ? &tcb[run_id] : NULL;
}

/* the ready task to run next: the highest priority (lowest number), first come first */
static ID pick(void)
{
    ID best = 0;

    for (ID i = 1; i <= MAX_TSK; i++)
    {
        if (tcb[i].state == TS_READY &&
            (best == 0 || tcb[i].pri < tcb[best].pri || (tcb[i].pri == tcb[best].pri && tcb[i].seq < tcb[best].seq)))
        {
            best = i;
        }
    }
    return best;
}

static void make_ready(ID id)
{
    tcb[id].state = TS_READY;
    tcb[id].wait = W_NONE;
    tcb[id].seq = ++seq_now;
}

/* switch to the best ready task if it is not the running one; a ready running task keeps the CPU against equal
 * priority unless it yields (rot_rdq) */
static void schedule(int yield)
{
    ID next, prev = run_id;
    uint32_t **save;

    if (cpu_locked)
    {
        return;
    }
    next = pick();
    if (!yield && prev != 0 && tcb[prev].state == TS_READY && next != 0 && tcb[next].pri >= tcb[prev].pri)
    {
        return;
    }
    if (next == prev)
    {
        return;
    }
    save = prev ? &tcb[prev].sp : &idle_sp;
    run_id = next;
    norti_switch(save, next ? tcb[next].sp : idle_sp);
}

void norti_dispatch(void)
{
    schedule(0);
}

/* the running task waits on (kind, obj) for tmo ticks; returns the wait result */
static ER wait_on(int kind, int obj, TMO tmo)
{
    tcb_t *t = cur();

    if (t == NULL)
    {
        return E_CTX;
    }
    if (tmo == TMO_POL)
    {
        return E_TMOUT;
    }
    t->state = TS_WAIT;
    t->wait = (uint8_t)kind;
    t->wobj = obj;
    t->tmo = tmo == TMO_FEVR ? -1 : (tmo + NORTI_TICK_MS - 1) / NORTI_TICK_MS;
    t->seq = ++seq_now;
    t->wer = E_OK;
    norti_dispatch();
    return t->wer;
}

/* the first task (by priority, then arrival) that waits on (kind, obj) */
static ID first_waiter(int kind, int obj)
{
    ID best = 0;

    for (ID i = 1; i <= MAX_TSK; i++)
    {
        if (tcb[i].state == TS_WAIT && tcb[i].wait == kind && tcb[i].wobj == obj &&
            (best == 0 || tcb[i].pri < tcb[best].pri || (tcb[i].pri == tcb[best].pri && tcb[i].seq < tcb[best].seq)))
        {
            best = i;
        }
    }
    return best;
}

static void release(ID id, ER er)
{
    tcb[id].wer = er;
    make_ready(id);
}

/* ------------------------------------------------------------------------------------------------- tasks */

static void task_start(void)
{
    tcb_t *t = cur();

    t->ctsk->task(t->stacd);
    itron_ext_tsk();
}

ER itron_acre_tsk(ID id, const T_CTSK *pk)
{
    static uint8_t stacks[MAX_TSK][4096] __attribute__((aligned(8)));

    if (id == 0)
    {
        for (id = 1; id <= MAX_TSK && tcb[id].state != TS_NONE; id++)
        {
        }
        if (id > MAX_TSK)
        {
            return E_NOID;
        }
    }
    else if (id < 0 || id > MAX_TSK)
    {
        return E_ID;
    }
    else if (tcb[id].state != TS_NONE)
    {
        return E_OBJ;
    }
    if (pk->itskpri < 1 || pk->itskpri > MAX_PRI || pk->task == NULL)
    {
        return E_PAR;
    }
    for (volatile uint8_t *z = (volatile uint8_t *)&tcb[id]; z < (volatile uint8_t *)&tcb[id + 1]; z++)
    {
        *z = 0;                      /* no C library: clear the control block by hand */
    }
    tcb[id].state = TS_DORMANT;
    tcb[id].pri = tcb[id].base_pri = (uint8_t)pk->itskpri;
    tcb[id].ctsk = pk;
    /* the caller's stack, or one of the stand-in's 4 KB stacks (the image allocates them from its kernel pool) */
    tcb[id].stk_top = (uint32_t *)(pk->stk ? (uint8_t *)pk->stk + pk->stksz : stacks[id - 1] + sizeof stacks[0]);
    if (pk->tskatr & 2)              /* TA_ACT */
    {
        itron_sta_tsk(id, pk->exinf);
    }
    return id;
}

ER itron_sta_tsk(ID id, intptr_t stacd)
{
    tcb_t *t;

    if (id < 1 || id > MAX_TSK || tcb[id].state == TS_NONE)
    {
        return E_NOEXS;
    }
    t = &tcb[id];
    if (t->state != TS_DORMANT)
    {
        return E_OBJ;
    }
    t->stacd = stacd;
    t->wupcnt = 0;
    t->pri = t->base_pri;
    t->sp = norti_stack_init(t->stk_top, task_start);
    make_ready(id);
    norti_dispatch();
    return E_OK;
}

ER itron_act_tsk(ID id)
{
    if (id == 0)
    {
        id = run_id;
    }
    if (id < 1 || id > MAX_TSK || tcb[id].state == TS_NONE)
    {
        return E_NOEXS;
    }
    return itron_sta_tsk(id, tcb[id].ctsk->exinf);
}

ER itron_ext_tsk(void)
{
    tcb_t *t = cur();

    if (t == NULL)
    {
        return E_CTX;
    }
    t->state = TS_DORMANT;
    norti_dispatch();
    return E_OK;                     /* not reached */
}

ER itron_get_tid(ID *p_tskid)
{
    *p_tskid = run_id;
    return E_OK;
}

ER itron_dly_tsk(int ms)
{
    ER er = wait_on(W_DLY, 0, ms <= 0 ? NORTI_TICK_MS : ms);

    return er == E_TMOUT ? E_OK : er;
}

ER itron_tslp_tsk(TMO tmout)
{
    tcb_t *t = cur();

    if (t == NULL)
    {
        return E_CTX;
    }
    if (t->wupcnt > 0)
    {
        t->wupcnt--;
        return E_OK;
    }
    return wait_on(W_SLP, 0, tmout);
}

ER itron_wup_tsk(ID id)
{
    if (id < 1 || id > MAX_TSK || tcb[id].state == TS_NONE)
    {
        return E_NOEXS;
    }
    if (tcb[id].state == TS_DORMANT)
    {
        return E_OBJ;
    }
    if (tcb[id].state == TS_WAIT && tcb[id].wait == W_SLP)
    {
        release(id, E_OK);
        norti_dispatch();
    }
    else if (tcb[id].wupcnt++ > 255)
    {
        tcb[id].wupcnt--;
        return E_QOVR;
    }
    return E_OK;
}

/* from an interrupt: wake, no dispatch (the interrupt exit does it) */
ER itron_iwup_tsk(ID id)
{
    int locked = cpu_locked;
    ER er;

    cpu_locked = 1;
    er = itron_wup_tsk(id);
    cpu_locked = locked;
    return er;
}

ER itron_rot_rdq(int pri)
{
    tcb_t *t = cur();

    if (t != NULL && (pri == 0 || pri == t->pri))
    {
        t->seq = ++seq_now;          /* to the end of its priority's queue */
        schedule(1);
    }
    return E_OK;
}

ER itron_chg_pri(ID id, int pri)
{
    if (id == 0)
    {
        id = run_id;
    }
    if (id < 1 || id > MAX_TSK || tcb[id].state == TS_NONE)
    {
        return E_NOEXS;
    }
    if (pri < 0 || pri > MAX_PRI)
    {
        return E_PAR;
    }
    tcb[id].pri = tcb[id].base_pri = (uint8_t)(pri ? pri : tcb[id].ctsk->itskpri);
    norti_dispatch();
    return E_OK;
}

ER itron_get_pri(ID id, int *p_pri)
{
    if (id == 0)
    {
        id = run_id;
    }
    if (id < 1 || id > MAX_TSK || tcb[id].state == TS_NONE)
    {
        return E_NOEXS;
    }
    *p_pri = tcb[id].pri;
    return E_OK;
}

ER itron_sus_tsk(ID id)
{
    return E_NOSPT;                  /* not used by the recreated code */
}

ER itron_loc_cpu(void)
{
    cpu_locked = 1;
    return E_OK;
}

ER itron_unl_cpu(void)
{
    cpu_locked = 0;
    norti_dispatch();
    return E_OK;
}

ER itron_dis_dsp(void)
{
    return itron_loc_cpu();
}

ER itron_ena_dsp(void)
{
    return itron_unl_cpu();
}

ER itron_get_tim(void *p_systim)
{
    *(uint64_t *)p_systim = sys_ms;
    return E_OK;
}

/* ------------------------------------------------------------------------------------------------- semaphores */

typedef struct { ATR sematr; unsigned isemcnt, maxsem; } T_CSEM_S;

ER itron_acre_sem(ID id, const void *pk)
{
    const T_CSEM_S *c = pk;

    ALLOC_ID(sem, MAX_SEM, id);
    sem[id] = (sem_t){ 1, (int)c->isemcnt, (int)c->maxsem };
    return id;
}

ER itron_del_sem(ID id)
{
    if (id < 1 || id > MAX_SEM || !sem[id].used)
    {
        return E_NOEXS;
    }
    for (ID w; (w = first_waiter(W_SEM, id)) != 0;)
    {
        release(w, -51);             /* E_DLT */
    }
    sem[id].used = 0;
    norti_dispatch();
    return E_OK;
}

ER itron_sig_sem(ID id)
{
    ID w;

    if (id < 1 || id > MAX_SEM || !sem[id].used)
    {
        return E_NOEXS;
    }
    w = first_waiter(W_SEM, id);
    if (w)
    {
        release(w, E_OK);
        norti_dispatch();
    }
    else if (sem[id].cnt < sem[id].max)
    {
        sem[id].cnt++;
    }
    else
    {
        return E_QOVR;
    }
    return E_OK;
}

ER itron_twai_sem(ID id, TMO tmout)
{
    if (id < 1 || id > MAX_SEM || !sem[id].used)
    {
        return E_NOEXS;
    }
    if (sem[id].cnt > 0)
    {
        sem[id].cnt--;
        return E_OK;
    }
    return wait_on(W_SEM, id, tmout);
}

/* ------------------------------------------------------------------------------------------------- event flags */

typedef struct { ATR flgatr; FLGPTN iflgptn; } T_CFLG_S;

ER itron_acre_flg(ID id, const void *pk)
{
    const T_CFLG_S *c = pk;

    ALLOC_ID(flg, MAX_FLG, id);
    flg[id] = (flg_t){ 1, c->flgatr, c->iflgptn };
    return id;
}

static int flg_match(FLGPTN ptn, FLGPTN wai, unsigned mode)
{
    return (mode & TWF_ORW) ? (ptn & wai) != 0 : (ptn & wai) == wai;
}

ER itron_set_flg(ID id, FLGPTN set)
{
    int woke = 0;

    if (id < 1 || id > MAX_FLG || !flg[id].used)
    {
        return E_NOEXS;
    }
    flg[id].ptn |= set;
    for (ID i = 1; i <= MAX_TSK; i++)
    {
        tcb_t *t = &tcb[i];

        if (t->state == TS_WAIT && t->wait == W_FLG && t->wobj == id && flg_match(flg[id].ptn, t->wptn, t->wmode))
        {
            t->rptn = flg[id].ptn;
            release(i, E_OK);
            woke = 1;
            if (flg[id].atr & TA_CLR)
            {
                flg[id].ptn = 0;
                break;
            }
        }
    }
    if (woke)
    {
        norti_dispatch();
    }
    return E_OK;
}

/* the image passes the bits to keep (~ptn), as uITRON 4.0 defines it [fact: boot-rtos.md, itron_clr_flg] */
ER itron_clr_flg(ID id, FLGPTN clr)
{
    if (id < 1 || id > MAX_FLG || !flg[id].used)
    {
        return E_NOEXS;
    }
    flg[id].ptn &= clr;
    return E_OK;
}

ER itron_twai_flg(ID id, FLGPTN wai, unsigned mode, FLGPTN *p_flg, TMO tmout)
{
    tcb_t *t = cur();
    ER er;

    if (id < 1 || id > MAX_FLG || !flg[id].used)
    {
        return E_NOEXS;
    }
    if (wai == 0)
    {
        return E_PAR;
    }
    if (flg_match(flg[id].ptn, wai, mode))
    {
        *p_flg = flg[id].ptn;
        if (flg[id].atr & TA_CLR)
        {
            flg[id].ptn = 0;
        }
        return E_OK;
    }
    if (t == NULL)
    {
        return tmout == TMO_POL ? E_TMOUT : E_CTX;
    }
    t->wptn = wai;
    t->wmode = mode;
    er = wait_on(W_FLG, id, tmout);
    if (er == E_OK)
    {
        *p_flg = t->rptn;
    }
    return er;
}

/* ------------------------------------------------------------------------------------------------- mailboxes */

ER itron_acre_mbx(ID id, const void *pk)
{
    ALLOC_ID(mbx, MAX_MBX, id);
    mbx[id] = (mbx_t){ 1, NULL, NULL };
    return id;
}

/* messages are linked through their first word (T_MSG) */
ER itron_snd_mbx(ID id, void *msg)
{
    ID w;

    if (id < 1 || id > MAX_MBX || !mbx[id].used)
    {
        return E_NOEXS;
    }
    w = first_waiter(W_MBX, id);
    if (w)
    {
        tcb[w].msg = msg;
        release(w, E_OK);
        norti_dispatch();
        return E_OK;
    }
    *(void **)msg = NULL;
    if (mbx[id].tail)
    {
        *(void **)mbx[id].tail = msg;
    }
    else
    {
        mbx[id].head = msg;
    }
    mbx[id].tail = msg;
    return E_OK;
}

ER itron_trcv_mbx(ID id, void **p_msg, TMO tmout)
{
    ER er;

    if (id < 1 || id > MAX_MBX || !mbx[id].used)
    {
        return E_NOEXS;
    }
    if (mbx[id].head)
    {
        *p_msg = mbx[id].head;
        mbx[id].head = *(void **)mbx[id].head;
        if (mbx[id].head == NULL)
        {
            mbx[id].tail = NULL;
        }
        return E_OK;
    }
    er = wait_on(W_MBX, id, tmout);
    if (er == E_OK)
    {
        *p_msg = cur()->msg;
    }
    return er;
}

/* ------------------------------------------------------------------------------------------------- message buffers */

typedef struct { ATR mbfatr; unsigned maxmsz; unsigned mbfsz; void *mbf; } T_CMBF_S;

ER itron_acre_mbf(ID id, const void *pk)
{
    static uint8_t pool[MAX_MBF][1024];
    const T_CMBF_S *c = pk;

    ALLOC_ID(mbf, MAX_MBF, id);
    mbf[id] = (mbf_t){ 1, c->mbf ? c->mbf : pool[id - 1], c->mbf ? c->mbfsz : sizeof pool[0], c->maxmsz, 0, 0, 0 };
    return id;
}

static void ring_put(mbf_t *b, const uint8_t *p, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        b->buf[b->wr] = p[i];
        b->wr = (b->wr + 1) % b->size;
    }
    b->used_b += n;
}

static void ring_get(mbf_t *b, uint8_t *p, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        p[i] = b->buf[b->rd];
        b->rd = (b->rd + 1) % b->size;
    }
    b->used_b -= n;
}

/* a sender waiting for room may proceed once the receivers made some */
static void mbf_wake_senders(ID id)
{
    mbf_t *b = &mbf[id];

    for (ID w; (w = first_waiter(W_MBF_S, id)) != 0;)
    {
        uint16_t n = (uint16_t)tcb[w].msgsz;

        if (b->size - b->used_b < n + 2U)
        {
            break;
        }
        ring_put(b, (const uint8_t *)&n, 2);
        ring_put(b, tcb[w].msg, n);
        release(w, E_OK);
    }
}

ER itron_tsnd_mbf(ID id, const void *msg, unsigned size, TMO tmout)
{
    mbf_t *b;
    ID w;
    uint16_t n = (uint16_t)size;

    if (id < 1 || id > MAX_MBF || !mbf[id].used)
    {
        return E_NOEXS;
    }
    b = &mbf[id];
    if (size == 0 || (b->maxmsz && size > b->maxmsz) || size + 2U > b->size)
    {
        return E_PAR;
    }
    w = first_waiter(W_MBF_R, id);
    if (w && b->used_b == 0)
    {
        for (unsigned i = 0; i < size; i++)
        {
            ((uint8_t *)tcb[w].msg)[i] = ((const uint8_t *)msg)[i];
        }
        tcb[w].msgsz = size;
        release(w, E_OK);
        norti_dispatch();
        return E_OK;
    }
    if (b->size - b->used_b >= size + 2U && first_waiter(W_MBF_S, id) == 0)
    {
        ring_put(b, (const uint8_t *)&n, 2);
        ring_put(b, msg, size);
        return E_OK;
    }
    if (cur() == NULL)
    {
        return E_TMOUT;
    }
    cur()->msg = (void *)msg;
    cur()->msgsz = size;
    return wait_on(W_MBF_S, id, tmout);
}

/* returns the size of the message received */
ER itron_trcv_mbf(ID id, void *msg, TMO tmout)
{
    mbf_t *b;
    uint16_t n;
    ER er;

    if (id < 1 || id > MAX_MBF || !mbf[id].used)
    {
        return E_NOEXS;
    }
    b = &mbf[id];
    if (b->used_b >= 2)
    {
        ring_get(b, (uint8_t *)&n, 2);
        ring_get(b, msg, n);
        mbf_wake_senders(id);
        norti_dispatch();
        return n;
    }
    if (cur() == NULL)
    {
        return E_TMOUT;
    }
    cur()->msg = msg;
    er = wait_on(W_MBF_R, id, tmout);
    return er == E_OK ? (ER)cur()->msgsz : er;
}

/* ------------------------------------------------------------------------------------------------- mutexes */

ER itron_acre_mtx(ID id, const void *pk)
{
    ALLOC_ID(mtx, MAX_MTX, id);
    mtx[id] = (mtx_t){ 1, 0 };
    return id;
}

ER itron_tloc_mtx(ID id, TMO tmout)
{
    if (id < 1 || id > MAX_MTX || !mtx[id].used)
    {
        return E_NOEXS;
    }
    if (mtx[id].owner == run_id && run_id != 0)
    {
        return E_ILUSE;
    }
    if (mtx[id].owner == 0)
    {
        mtx[id].owner = run_id;
        return E_OK;
    }
    return wait_on(W_MTX, id, tmout);
}

ER itron_unl_mtx(ID id)
{
    ID w;

    if (id < 1 || id > MAX_MTX || !mtx[id].used)
    {
        return E_NOEXS;
    }
    if (mtx[id].owner != run_id)
    {
        return E_ILUSE;
    }
    w = first_waiter(W_MTX, id);
    mtx[id].owner = w;
    if (w)
    {
        release(w, E_OK);
        norti_dispatch();
    }
    return E_OK;
}

/* ------------------------------------------------------------------------------------------------- cyclic handlers */

typedef struct { ATR cycatr; intptr_t exinf; void (*cychdr)(intptr_t); uint32_t cyctim, cycphs; } T_CCYC_S;

ER itron_acre_cyc(ID id, const void *pk)
{
    const T_CCYC_S *c = pk;
    uint32_t period = (c->cyctim + NORTI_TICK_MS - 1) / NORTI_TICK_MS;

    ALLOC_ID(cyc, MAX_CYC, id);
    cyc[id] = (cyc_t){ 1, (c->cycatr & 2) != 0, period ? period : 1, period ? period : 1, c->cychdr, c->exinf };
    return id;
}

ER itron_sta_cyc(ID id)
{
    if (id < 1 || id > MAX_CYC || !cyc[id].used)
    {
        return E_NOEXS;
    }
    cyc[id].run = 1;
    cyc[id].left = cyc[id].period;
    return E_OK;
}

ER itron_stp_cyc(ID id)
{
    if (id < 1 || id > MAX_CYC || !cyc[id].used)
    {
        return E_NOEXS;
    }
    cyc[id].run = 0;
    return E_OK;
}

/* ------------------------------------------------------------------------------------------------- interrupts */

ER itron_acre_isr(ID id, const T_CISR *pk)
{
    for (int i = MAX_ISR - 1; i >= 0; i--)    /* the image's ids count down from 0x40 */
    {
        if (isr_tab[i].isr == NULL)
        {
            isr_tab[i].intno = pk->intno;
            isr_tab[i].isr = pk->isr;
            return i + 1;
        }
    }
    return E_NOID;
}

/* called by the port's IRQ entry with the GIC interrupt id: every ISR created for it */
void norti_isr_dispatch(uint32_t intno)
{
    for (int i = 0; i < MAX_ISR; i++)
    {
        if (isr_tab[i].isr != NULL && isr_tab[i].intno == intno)
        {
            isr_tab[i].isr();
        }
    }
}

/* ------------------------------------------------------------------------------------------------- time */

/* one system tick (NORTI_TICK_MS): timeouts and cyclic handlers; the caller dispatches afterwards */
void norti_tick(void)
{
    int locked = cpu_locked;

    cpu_locked = 1;
    sys_ms += NORTI_TICK_MS;
    for (ID i = 1; i <= MAX_TSK; i++)
    {
        tcb_t *t = &tcb[i];

        if (t->state == TS_WAIT && t->tmo > 0 && --t->tmo == 0)
        {
            release(i, E_TMOUT);
        }
    }
    for (ID i = 1; i <= MAX_CYC; i++)
    {
        if (cyc[i].used && cyc[i].run && --cyc[i].left == 0)
        {
            cyc[i].left = cyc[i].period;
            cyc[i].hdr(cyc[i].exinf);
        }
    }
    cpu_locked = locked;
}

/* the idle loop of the start-up context once the tasks run: tick (the caller supplies the time base) and dispatch */
void norti_idle_step(void)
{
    norti_tick();
    norti_dispatch();
}
