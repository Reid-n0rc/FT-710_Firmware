/*
 * FT-710 DISPLAY (T24 round 4): smoke test of the NORTi stand-in (rtos/norti.c), run in Unicorn by
 * tools/test_norti_standin.py. Two tasks hand control to each other through every object type; each step appends
 * one character to test_log, and the expected sequence is in the test script.
 */
#include "norti.h"

char test_log[64];
int test_len;
static ID sem_id, flg_id, mbx_id, mbf_id, mtx_id;
static volatile int cyc_runs;

static void L(char c)
{
    test_log[test_len++] = c;
}

static void cyc_hdr(intptr_t x)
{
    cyc_runs++;
}

/* priority 2: runs first whenever it is ready */
static void task_a(intptr_t x)
{
    FLGPTN p;
    void *m;
    char buf[8];
    ER n;

    L('a');
    itron_twai_sem(sem_id, TMO_FEVR);
    L('A');
    itron_twai_flg(flg_id, 3, TWF_ANDW, &p, TMO_FEVR);
    L('F');
    itron_trcv_mbx(mbx_id, &m, TMO_FEVR);
    L(((char *)m)[4]);
    n = itron_trcv_mbf(mbf_id, buf, TMO_FEVR);
    L((char)('0' + n));
    L(buf[0]);
    L(itron_twai_sem(sem_id, 30) == E_TMOUT ? 'T' : '?');
    itron_tloc_mtx(mtx_id, TMO_FEVR);
    L('M');
    itron_unl_mtx(mtx_id);
    L('x');
    itron_ext_tsk();
}

/* priority 3 */
static void task_b(intptr_t x)
{
    static struct
    {
        void *next;
        char c;
    } msg = { 0, 'm' };

    L('b');
    itron_sig_sem(sem_id);
    L('1');
    itron_set_flg(flg_id, 1);
    L('2');
    itron_set_flg(flg_id, 2);
    L('3');
    itron_snd_mbx(mbx_id, &msg);
    L('4');
    itron_tsnd_mbf(mbf_id, "hi", 2, TMO_FEVR);
    L('5');
    itron_tloc_mtx(mtx_id, TMO_FEVR);
    L('L');
    itron_dly_tsk(50);
    L('U');
    itron_unl_mtx(mtx_id);
    L('y');
    itron_ext_tsk();
}

int test_main(void)
{
    static const struct { ATR a; unsigned i, m; } csem = { 0, 0, 4 };
    static const struct { ATR a; FLGPTN i; } cflg = { 0, 0 };
    static const struct { ATR a; unsigned maxmsz, mbfsz; void *mbf; } cmbf = { 0, 16, 0, 0 };
    static const struct { ATR a; intptr_t x; void (*h)(intptr_t); uint32_t t, p; } ccyc = { 2, 0, cyc_hdr, 10, 0 };
    static const T_CTSK ta = { 0, 0, task_a, 2, 0, 0, "A" }, tb = { 0, 0, task_b, 3, 0, 0, "B" };
    ID a, b;

    sem_id = itron_acre_sem(0, &csem);
    flg_id = itron_acre_flg(0, &cflg);
    mbx_id = itron_acre_mbx(0, 0);
    mbf_id = itron_acre_mbf(0, &cmbf);
    mtx_id = itron_acre_mtx(0, 0);
    itron_acre_cyc(0, &ccyc);
    a = itron_acre_tsk(0, &ta);
    b = itron_acre_tsk(0, &tb);
    itron_sta_tsk(a, 0);
    itron_sta_tsk(b, 0);
    for (int t = 0; t < 100 && test_len < 18; t++)
    {
        norti_idle_step();
    }
    if (cyc_runs >= 5)
    {
        L('c');
    }
    return test_len;
}
