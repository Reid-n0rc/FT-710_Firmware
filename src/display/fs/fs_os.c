/*
 * FT-710 DISPLAY (T24 round 9): the file-system layer's operating-system glue, 0x2014D95C..0x2014E1EB: the
 * per-task error word, the two drive-lock tables, the device semaphores shared by the drives of one driver, the
 * named semaphores and memory pools the layer creates at fs_init, and the clock for the time stamps. Recreated
 * from the image's disassembly.
 *
 * The NORTi calls are the image's (include/norti.h); os_create_sem_named / os_create_mpf_named are the image's
 * wrappers that create a kernel object from a packet and record its name [fact: 0x2014E584, 0x2014E690].
 */
#include "fs.h"
#include "norti.h"

int os_create_sem_named(const void *pk, const char *name);   /* 0x2014E584 */
int os_create_mpf_named(const void *pk, const char *name);   /* 0x2014E690 */
void rtc_get_tm(void *tm);                                   /* 0x201146B4 */

/* per task (ID 1..256) the last error of the layer, fs_task_ctx[id] at 0x2091D0BC + 4 * id [fact: 0x2014D97C] */
extern int fs_task_err[];                  /* 0x2091D0BC */

/* the drive-lock tables: five {semaphore, the drive letter holding it} [fact: 0x2014D9D0, 0x2014DB74] */
typedef struct
{
    ID sem;
    fs_char_t letter;
    uint8_t _r[3];
} fs_lock_t;
extern fs_lock_t fs_lock_dir[5];           /* 0x2091D4C0: "dir_sem" (fs_lock_a) */
extern fs_lock_t fs_lock_fat[5];           /* 0x2091D4E8: "fat_sem" (fs_lock_b) */

extern fs_drive_t *fs_drive_list;          /* 0x20808BA0 */
extern ID fs_sem_filestr;                  /* 0x20808BB4 */
extern ID fs_sem_dirstr;                   /* 0x20808BB8 */
extern ID fs_sem_fsys;                     /* 0x20808BBC */
extern ER fs_sem_fsys_result;              /* 0x20808BC0 */
extern ID fs_mpf;                          /* 0x20808BC4: "fsys_mpf" */
extern ID fs_work_mpf;                     /* 0x20808BC8: "FSYS Work" */

/* the creation packets (.rodata) and the names (in .text, after each function) [fact: the literals] */
extern const uint8_t fs_csem_dir[], fs_csem_fat[], fs_csem_disk[], fs_csem_filestr[], fs_csem_dirstr[];
extern const uint8_t fs_csem_fsys[], fs_cmpf_fsys[], fs_cmpf_work[];
extern const char fs_name_dir_sem[], fs_name_fat_sem[], fs_name_disk_sem[], fs_name_filestr_sem[];
extern const char fs_name_dirstr_sem[], fs_name_fsys_sem[], fs_name_fsys_mpf[], fs_name_fsys_work[];

/* 0x2014D95C: the calling task's last error; -72 for a task ID outside 1..256 [fact] */
int fs_task_ctx_get(void)
{
    ID id;

    itron_get_tid(&id);
    if ((unsigned)(id - 1) > 0xFF)
    {
        return -72;
    }
    return fs_task_err[id];
}

/* 0x2014D98C: stores the calling task's last error (fs_set_error) [fact] */
void fs_task_err_set(int err)
{
    ID id;

    itron_get_tid(&id);
    if ((unsigned)(id - 1) <= 0xFF)
    {
        fs_task_err[id] = err;
    }
}

/* fs_lock_a / fs_lock_b: the entry of the drive's letter, else a free one; wait for its semaphore (300 ms) and
 * record the letter; err when there is no semaphore or no free entry [fact: 0x2014D9C0, 0x2014DB6C] */
static inline int fs_lock(fs_lock_t *t, const fs_drive_t *d, int err)
{
    int i;
    ER r;

    for (i = 0; i < 5; i++)
    {
        if (t[i].letter == d->letter)
        {
            if (t[i].sem == 0)
            {
                return err;
            }
            r = itron_twai_sem(t[i].sem, 300);
            if (r != 0)
            {
                return r;
            }
            t[i].letter = d->letter;
            return 0;
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (t[i].letter == 0)
        {
            if (t[i].sem == 0)
            {
                return err;
            }
            r = itron_twai_sem(t[i].sem, 300);
            if (r != 0)
            {
                return r;
            }
            t[i].letter = d->letter;
            return 0;
        }
    }
    return err;
}

/* fs_unlock_a / fs_unlock_b: signal the entry of the drive's letter and free it, with dispatching off [fact] */
static inline int fs_unlock(fs_lock_t *t, const fs_drive_t *d, int err)
{
    for (int i = 0; i < 5; i++)
    {
        if (t[i].letter == d->letter)
        {
            if (t[i].sem == 0)
            {
                return err;
            }
            itron_dis_dsp();
            ER r = itron_sig_sem(t[i].sem);
            if (r == 0)
            {
                t[i].letter = 0;
            }
            itron_ena_dsp();
            return r;
        }
    }
    return err;
}

/* fs_sem_a_create / fs_sem_b_create: clear the table, create five semaphores and signal each once; stops at the
 * first failure [fact] */
static inline void fs_lock_create(fs_lock_t *t, const void *pk, const char *name)
{
    fs_memset(t, 0, sizeof(fs_lock_t) * 5, 0x200);
    for (int i = 0; i < 5; i++)
    {
        ID id = os_create_sem_named(pk, name);

        if (id <= 0)
        {
            return;
        }
        t[i].sem = id;
        itron_sig_sem(id);
    }
}

/* fs_sem_a_delete / fs_sem_b_delete: delete the five; returns the last itron_del_sem result [fact] */
static inline ER fs_lock_delete(fs_lock_t *t)
{
    ER r = 0;

    for (int i = 0; i < 5; i++)
    {
        if (t[i].sem != 0)
        {
            r = itron_del_sem(t[i].sem);
            t[i].sem = 0;
        }
    }
    return r;
}

int fs_lock_a(const fs_drive_t *d)          /* 0x2014D9C0: -37 */
{
    return fs_lock(fs_lock_dir, d, -37);
}

int fs_unlock_a(const fs_drive_t *d)        /* 0x2014DA64: -38 */
{
    return fs_unlock(fs_lock_dir, d, -38);
}

void fs_sem_a_create(void)                  /* 0x2014DAD0: "dir_sem" */
{
    fs_lock_create(fs_lock_dir, fs_csem_dir, fs_name_dir_sem);
}

ER fs_sem_a_delete(void)                    /* 0x2014DB2C */
{
    return fs_lock_delete(fs_lock_dir);
}

int fs_lock_b(const fs_drive_t *d)          /* 0x2014DB6C: -34 */
{
    return fs_lock(fs_lock_fat, d, -34);
}

int fs_unlock_b(const fs_drive_t *d)        /* 0x2014DC10: -35 */
{
    return fs_unlock(fs_lock_fat, d, -35);
}

void fs_sem_b_create(void)                  /* 0x2014DC7C: "fat_sem" */
{
    fs_lock_create(fs_lock_fat, fs_csem_fat, fs_name_fat_sem);
}

ER fs_sem_b_delete(void)                    /* 0x2014DCD8 */
{
    return fs_lock_delete(fs_lock_fat);
}

/* 0x2014DD18 / 0x2014DD34: wait (1 s) for and signal a device semaphore; E_NOEXS (-42) for an id <= 0 [fact] */
ER fs_sem_wait_1s(ID id)
{
    return id > 0 ? itron_twai_sem(id, 1000) : -42;
}

ER fs_sem_signal(ID id)
{
    return id > 0 ? itron_sig_sem(id) : -42;
}

/* 0x2014DD4C: the drive takes the semaphore of another drive with the same driver entry, else a new "disk_sem"
 * (signalled once) [fact] */
ER fs_drive_sem_create(fs_drive_t *d)
{
    fs_drive_t *p = fs_drive_list;

    for (;;)
    {
        if (p->op == d->op && p != d)
        {
            d->sem = p->sem;
            return 0;
        }
        fs_drive_t *n = p->next;
        if (n == 0)
        {
            break;
        }
        p = n;
    }
    ID id = os_create_sem_named(fs_csem_disk, fs_name_disk_sem);
    if (id <= 0)
    {
        return id;
    }
    d->sem = id;
    return itron_sig_sem(id);
}

/* 0x2014DDD0: deletes the drive's semaphore and clears it in the other drives of the same driver [fact] */
ER fs_drive_sem_delete(fs_drive_t *d)
{
    fs_drive_t *p = fs_drive_list;

    if (d->sem <= 0)
    {
        return 0;
    }
    for (;;)
    {
        if (p->op == d->op && p != d)
        {
            p->sem = 0;
        }
        fs_drive_t *n = p->next;
        if (n == 0)
        {
            break;
        }
        p = n;
    }
    ER r = itron_del_sem(d->sem);
    d->sem = 0;
    return r;
}

/* the layer's three single semaphores: wait 300 ms, signal, create (signalled once), delete; 0 while the
 * semaphore does not exist [fact: 0x2014DE30..0x2014E06B] */
ER fs_sem1_wait(void)                       /* 0x2014DE30: "filestr_sem" */
{
    return fs_sem_filestr > 0 ? itron_twai_sem(fs_sem_filestr, 300) : 0;
}

ER fs_sem1_signal(void)                     /* 0x2014DE5C */
{
    return fs_sem_filestr > 0 ? itron_sig_sem(fs_sem_filestr) : 0;
}

void fs_sem1_create(void)                   /* 0x2014DE84 */
{
    fs_sem_filestr = 0;
    ID id = os_create_sem_named(fs_csem_filestr, fs_name_filestr_sem);
    if (id > 0)
    {
        fs_sem_filestr = id;
        itron_sig_sem(id);
    }
}

ER fs_sem1_delete(void)                     /* 0x2014DECC */
{
    return fs_sem_filestr > 0 ? itron_del_sem(fs_sem_filestr) : 0;
}

ER fs_sem2_wait(void)                       /* 0x2014DEF4: "dirstr_sem" */
{
    return fs_sem_dirstr > 0 ? itron_twai_sem(fs_sem_dirstr, 300) : 0;
}

ER fs_sem2_signal(void)                     /* 0x2014DF20 */
{
    return fs_sem_dirstr > 0 ? itron_sig_sem(fs_sem_dirstr) : 0;
}

void fs_sem2_create(void)                   /* 0x2014DF48 */
{
    fs_sem_dirstr = 0;
    ID id = os_create_sem_named(fs_csem_dirstr, fs_name_dirstr_sem);
    if (id > 0)
    {
        fs_sem_dirstr = id;
        itron_sig_sem(id);
    }
}

ER fs_sem2_delete(void)                     /* 0x2014DF8C */
{
    return fs_sem_dirstr > 0 ? itron_del_sem(fs_sem_dirstr) : 0;
}

/* 0x2014DFB4 / 0x2014DFDC: wait for / signal "fsys_sem"; the result is kept in 0x20808BC0 and returned (the old
 * one when the semaphore does not exist) [fact] */
ER fsys_sem_wait(void)
{
    if (fs_sem_fsys > 0)
    {
        fs_sem_fsys_result = itron_twai_sem(fs_sem_fsys, 300);
    }
    return fs_sem_fsys_result;
}

ER fsys_sem_signal(void)
{
    if (fs_sem_fsys > 0)
    {
        fs_sem_fsys_result = itron_sig_sem(fs_sem_fsys);
    }
    return fs_sem_fsys_result;
}

void fsys_init_sem(void)                    /* 0x2014E000 */
{
    fs_sem_fsys = 0;
    ID id = os_create_sem_named(fs_csem_fsys, fs_name_fsys_sem);
    if (id > 0)
    {
        fs_sem_fsys = id;
        itron_sig_sem(id);
    }
}

ER fsys_sem_delete(void)                    /* 0x2014E044 */
{
    return fs_sem_fsys > 0 ? itron_del_sem(fs_sem_fsys) : 0;
}

/* 0x2014E06C: a block of "fsys_mpf" without waiting, for sizes up to 64 KB; 0 otherwise [fact] */
void *fs_mpf_alloc(uint32_t size)
{
    void *blk;

    if (size > 0x10000)
    {
        return 0;
    }
    if (fs_mpf <= 0 || itron_tget_mpf(fs_mpf, &blk, 0) != 0)
    {
        return 0;
    }
    return blk;
}

void fs_mpf_free(void *blk)                 /* 0x2014E0AC */
{
    if (fs_mpf > 0)
    {
        itron_rel_mpf(fs_mpf, blk);
    }
}

void fs_mpf_create(void)                    /* 0x2014E0C8 */
{
    ID id = os_create_mpf_named(fs_cmpf_fsys, fs_name_fsys_mpf);

    fs_mpf = id > 0 ? id : 0;
}

void fs_mpf_delete(void)                    /* 0x2014E100 */
{
    if (fs_mpf > 0)
    {
        itron_del_mpf(fs_mpf);
    }
}

/* 0x2014E118 / 0x2014E14C: a work buffer of "FSYS Work" for one file-system call, and its release [fact] */
void *fs_work_alloc(void)
{
    void *blk;

    if (fs_work_mpf <= 0 || itron_tget_mpf(fs_work_mpf, &blk, 0) != 0)
    {
        return 0;
    }
    return blk;
}

ER fs_work_free(void *blk)
{
    return fs_work_mpf > 0 ? itron_rel_mpf(fs_work_mpf, blk) : 0;
}

/* 0x2014E178: creates "FSYS Work"; 0, or the creation error (the pool id then 0) [fact] */
int fs_work_pool_create(void)
{
    ID id = os_create_mpf_named(fs_cmpf_work, fs_name_fsys_work);

    if (id > 0)
    {
        fs_work_mpf = id;
        return 0;
    }
    fs_work_mpf = 0;
    return id;
}

ER fs_work_pool_delete(void)                /* 0x2014E1B4 */
{
    return fs_work_mpf > 0 ? itron_del_mpf(fs_work_mpf) : 0;
}

/* 0x2014E1DC: the RTC time into the caller's struct tm for the time stamps; returns 1 [fact] */
int fs_get_time_tm(void *tm)
{
    rtc_get_tm(tm);
    return 1;
}
