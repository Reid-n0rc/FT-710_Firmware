/*
 * FT-710 DISPLAY (T24 USB track): the scope object (the image's C++ class as C), its methods and the GUI's thunks
 * to the one instance 0x2047963C (docs/code/display/gui.md "Scope drawing", "Scope / 3DSS / AF-FFT objects").
 * Recreated from the image's disassembly.
 *
 * Every thunk 0x201342B4..0x201344AF loads the instance and tail-calls a method; most methods have no Ghidra entry,
 * so Ghidra counted their bodies into the thunks (scope_palette_set: 256 bytes for three instructions) [fact: the
 * b instructions, decomp/display/functions.tsv]. tools/ghidra/entries_display.T24usb.tsv adds those entries.
 *
 * The object is 0x82FB8 bytes [fact: scope_objects_init clears that much]. The offsets below are the image's.
 * Not recreated yet: the methods behind scope3d_redraw_history (0x20157A00), scope3d_add_line (0x201580E0),
 * scope_history_push (0x20158010), scope_obj_levels_get and scope_obj_wf_add_row, and so those three thunks (their
 * Ghidra sizes hold the method bodies).
 */
#include <stdint.h>

#define SCOPE_OBJ_SIZE 0x82FB8
#define SC_FREEZE_A 0x9C7C      /* byte: no new record is taken (scope_freeze_a_set) */
#define SC_FREEZE_B 0x9C7D      /* byte (scope_freeze_b_set) */
#define SC_BLANK 0x9C7E         /* byte: records are stored blank (0xFF); the bank resets clear it */
#define SC_RECORD 0x9C7F        /* the 850-byte scope record, 0x204832BB in the instance (scope_frame_buf) */
#define SC_HOLD 0x9FD1          /* its hold copy, 850 bytes */
#define SC_REC_LEN 850
#define SC_3D_LINES 0xA323      /* 30 lines of 800 bytes */
#define SC_MARKERS 0x100E4      /* 30 marker records of 0x54 bytes (scope3d_line_markers) */
#define SC_HISTORY 0x10ABC      /* 30 rows of 0x370, 26520 bytes */
#define SC_RING_3D 0x17254      /* ring30 index */
#define SC_WORK 0x17258         /* 16084 bytes */
#define SC_RING_HIST 0x1B12C
#define SC_WF_BANK0 0x1B130     /* two waterfall banks of 133 rows of 0x640 bytes, 0x33F40 each */
#define SC_WF_BANK_SIZE 0x33F40
#define SC_WF_ROW 0x640
#define SC_RING_WF1 0x82FB0     /* ring133 of bank 1 */
#define SC_RING_WF0 0x82FB4     /* ring133 of bank 0 */
#define SC_RAMP_A 0x320C        /* the four 3D colour ramp sub-objects */
#define SC_RAMP_B 0x5DC4
#define SC_RAMP_C 0x6744
#define SC_RAMP_D 0x92FC

#define F8(o, off) (*(volatile uint8_t *)((uint8_t *)(o) + (off)))
#define F16(o, off) (*(uint16_t *)((uint8_t *)(o) + (off)))
#define P(o, off) ((void *)((uint8_t *)(o) + (off)))

/* 0x20450278: the vertical scale tables of modes 8 and 9 and the selected waterfall bank [fact: scope_obj_layout_set
 * stores +0 and +4, scope_wf_bank_set +8] */
extern volatile struct
{
    const uint16_t *vscale8;
    const uint16_t *vscale9;
    int bank;
} scope_tables;
extern uint8_t scope_obj[];                 /* 0x2047963C, the instance */
extern const uint16_t scope_vscale8_small[], scope_vscale8_large[];   /* 0x203D99DC / 0x203D9A18 */
extern const uint16_t scope_vscale9_small[], scope_vscale9_large[];   /* 0x203D9A80 / 0x203D9A9E */
extern const uint8_t scope_record_default[];                          /* 0x203D9B14: 800 bytes */
extern const uint16_t scope_ref_level_on, scope_ref_level_off;        /* 0x20428294 / 0x20428298 */
extern const uint16_t scope_ref2_level_on, scope_ref2_level_off;      /* 0x2042829C / 0x204282A0 */
extern volatile uint8_t scope_blank_flag;   /* 0x208004A0: records are stored blank while set */
extern volatile uint16_t gui_flags;         /* 0x20808A84: bit 10 puts the default record in */

void __aeabi_memset(void *dst, uint32_t n, int c);
void __aeabi_memclr(void *dst, uint32_t n);
void __aeabi_memclr4(void *dst, uint32_t n);
void __aeabi_memcpy(void *dst, const void *src, uint32_t n);
void __aeabi_memcpy4(void *dst, const void *src, uint32_t n);
int ring133_offset(const int *idx, int d);
void ring133_reset(int *idx);
int FUN_20157634(void *a, int v, void *b);             /* the image's, not recreated */
void scope_obj_apply_2e02(void *obj, unsigned v);      /* 0x20162D68, not recreated */
int FUN_201633a0(void *a, int x, void *row, int e, int z);
uint32_t FUN_20164654(const void *o), FUN_20164674(const void *o);
uint32_t FUN_2016466c(const void *o);
int scope_obj_levels_get(void *obj, int a, void *b, int c);
int scope_obj_wf_add_row(void *obj, const void *rec, int mode);
void scope_obj_7f8c(void *obj, int a);                 /* 0x20157F8C (FUN_20157f8c), not recreated */
void FUN_20163d44(void *o, int v), FUN_20163f14(void *o, int v), FUN_20163ae0(void *o, int v);
/* the 3D colour ramp sub-objects' methods (the image's, not recreated) */
void FUN_20164054(void *r, int a, int n, const uint16_t *end, const uint16_t *tab);
void FUN_20163f80(void *r, int a, int n, const uint16_t *end, const uint16_t *tab);
void FUN_20164018(void *r, const void *ramp), FUN_20163f44(void *r, const void *ramp);
void FUN_201640a4(void *r, const void *from), FUN_20163fd0(void *r, const void *from);
uint32_t FUN_20164680(const void *r), FUN_2016469c(const void *r);
void FUN_20158838(void *obj3d, const void *ramp, uint32_t a, uint32_t b);
void FUN_20162c28(void *dst, uint32_t v);
void scope_obj_set_2e04(uint8_t *obj, int v);       /* 0x20162D48 (FUN_20162d48): byte +0x2E04 */
extern uint8_t scope3d_obj_a[];                       /* 0x20470294, the first 3D object */
extern uint8_t scope3d_obj_b[], scope3d_obj_c[];      /* 0x20474C68 / 0x20478550 */
extern const void *const scope_ramp_tab_a[], *const scope_ramp_tab_b[], *const scope_ramp_tab_c[];
                                                      /* 0x203D9A54 / 0x203D9ABC / 0x203D9AE8, by COLOR */

/* 0x201576F4: (obj, which): 0 clears bank 0 and its ring index and selects it; 1 selects bank 1 (nothing cleared);
 * otherwise both banks and both ring indices are cleared and the selection is left [fact] */
void scope_wf_bank_set(uint8_t *obj, int which)
{
    if (which == 0)
    {
        __aeabi_memclr4(P(obj, SC_WF_BANK0), SC_WF_BANK_SIZE);
        ring133_reset(P(obj, SC_RING_WF0));
        scope_tables.bank = 0;
        return;
    }
    if (which == 1)
    {
        scope_tables.bank = 1;
        return;
    }
    __aeabi_memclr4(P(obj, SC_WF_BANK0), 2 * SC_WF_BANK_SIZE);
    ring133_reset(P(obj, SC_RING_WF0));
    ring133_reset(P(obj, SC_RING_WF1));
}

/* 0x20157778: record and hold copy to 0xFF, the history, 3D lines, work area and markers to 0 [fact] */
void scope_obj_history_clear(uint8_t *obj)
{
    __aeabi_memset(P(obj, SC_RECORD), SC_REC_LEN, 0xFF);
    __aeabi_memset(P(obj, SC_HOLD), SC_REC_LEN, 0xFF);
    __aeabi_memclr4(P(obj, SC_HISTORY), 26520);
    __aeabi_memclr(P(obj, SC_3D_LINES), 24000);
    __aeabi_memclr4(P(obj, SC_WORK), 16084);
    __aeabi_memclr4(P(obj, SC_MARKERS), 2520);
}

/* 0x2015781C: (obj, rec): takes the 850-byte record unless frozen (SC_FREEZE_A; then it is only blanked when
 * SC_BLANK is set); blank (0xFF) while 0x208004A0 or SC_BLANK is set; with gui_flags bit 10 the default 800 bytes
 * go in at record +0x19 [fact: 0x20157828..0x201578A4] */
void scope_obj_store_record(uint8_t *obj, const uint8_t *rec)
{
    if (F8(obj, SC_FREEZE_A))
    {
        if (F8(obj, SC_BLANK))
        {
            __aeabi_memset(P(obj, SC_RECORD), SC_REC_LEN, 0xFF);
        }
        return;
    }
    if (scope_blank_flag != 0 || F8(obj, SC_BLANK))
    {
        __aeabi_memset(P(obj, SC_RECORD), SC_REC_LEN, 0xFF);
    }
    else
    {
        __aeabi_memcpy(P(obj, SC_RECORD), rec, SC_REC_LEN);
    }
    if (gui_flags & 0x400)
    {
        __aeabi_memcpy4(P(obj, SC_RECORD + 0x19), scope_record_default, 800);
    }
}

/* 0x201578C4: (obj, v): byte +0x2E04 = v, through scope_obj_set_2e04 (FUN_20162d48) [fact: b 0x20162D48; strb r1, [r0, #0x2E04]] */
void scope_obj_set_2e04_thunk(uint8_t *obj, int v)
{
    scope_obj_set_2e04(obj, v);
}

/* 0x201578C8 / 0x20158568: SC_BLANK off, history cleared, waterfall bank 0 cleared and selected / bank 1 selected
 * [fact] */
void scope_obj_reset_bank0(uint8_t *obj)
{
    F8(obj, SC_BLANK) = 0;
    scope_obj_history_clear(obj);
    scope_wf_bank_set(obj, 0);
}

void scope_obj_reset_bank1(uint8_t *obj)
{
    F8(obj, SC_BLANK) = 0;
    scope_obj_history_clear(obj);
    scope_wf_bank_set(obj, 1);
}

/* 0x201578F0 / 0x20157BC4: the freeze bytes [fact] */
void scope_obj_freeze_b_set(uint8_t *obj, int v)
{
    F8(obj, SC_FREEZE_B) = (uint8_t)v;
}

void scope_obj_freeze_a_set(uint8_t *obj, int v)
{
    F8(obj, SC_FREEZE_A) = (uint8_t)v;
}

/* 0x20157BD0: (obj, expanded): the flag into the four ramp sub-objects (their byte 0) and the vertical scale tables
 * of the expanded or the normal layout [fact] */
void scope_obj_layout_set(uint8_t *obj, int expanded)
{
    F8(obj, SC_RAMP_A) = (uint8_t)expanded;
    F8(obj, SC_RAMP_B) = (uint8_t)expanded;
    F8(obj, SC_RAMP_C) = (uint8_t)expanded;
    F8(obj, SC_RAMP_D) = (uint8_t)expanded;
    scope_tables.vscale8 = expanded ? scope_vscale8_large : scope_vscale8_small;
    scope_tables.vscale9 = expanded ? scope_vscale9_large : scope_vscale9_small;
}

/* 0x20162D54: (obj): FUN_20157634(obj + 0x2D00, byte +0x2E04, obj + 0x2E00) [fact] */
int scope_obj_apply_2e00(uint8_t *obj)
{
    return FUN_20157634(P(obj, 0x2D00), F8(obj, 0x2E04), P(obj, 0x2E00));
}

/* 0x201584F8 / 0x20158544: (obj, on): a halfword of two ROM pairs into +0x2E00, +0x3006, +0x3208 (then applied by
 * scope_obj_apply_2e00) or into +0x2E02 (scope_obj_apply_2e02, which also takes the value) [fact] */
int scope_obj_set_2e00(uint8_t *obj, int on)
{
    uint16_t v = on ? scope_ref_level_on : scope_ref_level_off;

    F16(obj, 0x2E00) = v;
    F16(obj, 0x3006) = v;
    F16(obj, 0x3208) = v;
    return scope_obj_apply_2e00(obj);
}

void scope_obj_set_2e02(uint8_t *obj, int on)
{
    uint16_t v = on ? scope_ref2_level_on : scope_ref2_level_off;

    F16(obj, 0x2E02) = v;
    scope_obj_apply_2e02(obj, v);
}

/* 0x20158590: the four ring indices to 0 [fact] */
void scope_obj_indices_clear(uint8_t *obj)
{
    *(int *)P(obj, SC_RING_3D) = 0;
    *(int *)P(obj, SC_RING_HIST) = 0;
    *(int *)P(obj, SC_RING_WF1) = 0;
    *(int *)P(obj, SC_RING_WF0) = 0;
}

/* 0x201587FC: (3D object): resets its three sub-objects (+0x10, +0x9C, +0x38E8) and byte 0 [fact] */
void scope3d_obj_init(uint8_t *o)
{
    FUN_20163d44(o + 0x10, 0);
    FUN_20163f14(o + 0x9C, 0);
    FUN_20163ae0(o + 0x38E8, 0);
    o[0] = 0;
}

/* 0x201578FC: (obj, a, b): the colour ramps of COLOR a into ramp sub-objects A and B and the first 3D object, of
 * COLOR b into C and D and the second 3D object, then the two words +0x88 of the 3D objects' sub-objects +0x10 into
 * +0x2E06 and +0x3008 [fact: 0x2015791C..0x201579E8] */
void scope_obj_palette_set(uint8_t *obj, int a, int b)
{
    FUN_20164018(P(obj, SC_RAMP_A), scope_ramp_tab_a[a]);
    FUN_20163f44(P(obj, SC_RAMP_B), scope_ramp_tab_b[a]);
    uint32_t vb = FUN_20164680(P(obj, SC_RAMP_B));
    FUN_20158838(scope3d_obj_a, scope_ramp_tab_c[a], FUN_2016469c(P(obj, SC_RAMP_A)), vb);
    FUN_20164018(P(obj, SC_RAMP_C), scope_ramp_tab_a[b]);
    FUN_20163f44(P(obj, SC_RAMP_D), scope_ramp_tab_b[b]);
    uint32_t vd = FUN_20164680(P(obj, SC_RAMP_D));
    FUN_20158838(scope3d_obj_b, scope_ramp_tab_c[b], FUN_2016469c(P(obj, SC_RAMP_C)), vd);
    FUN_20162c28(P(obj, 0x2E06), *(uint32_t *)(scope3d_obj_a + 0x10 + 0x88));
    FUN_20162c28(P(obj, 0x3008), *(uint32_t *)(scope3d_obj_b + 0x10 + 0x88));
}

/* 0x20158330: the flags off, record and hold copy blank, ramp A over the 30 mode-8 scale entries and B over the 15
 * mode-9 ones, both with COLOR 0, the two 3D objects reset and given their ramps (C and D copied from A and B), the
 * +0x2E04 byte 100, the levels +0x2E00 / +0x2E02 off, the words +0x2E06 / +0x3008, both waterfall banks cleared and
 * the history [fact: 0x20158330..0x201584D0] */
void scope_obj_init(uint8_t *obj)
{
    F8(obj, SC_FREEZE_A) = 0;
    F8(obj, SC_FREEZE_B) = 0;
    F8(obj, SC_BLANK) = 0;
    __aeabi_memset(P(obj, SC_RECORD), SC_REC_LEN, 0xFF);
    __aeabi_memset(P(obj, SC_HOLD), SC_REC_LEN, 0xFF);
    FUN_20164054(P(obj, SC_RAMP_A), 0, 30, scope_vscale8_small + 30, scope_vscale8_small);
    FUN_20163f80(P(obj, SC_RAMP_B), 0, 15, scope_vscale9_small + 15, scope_vscale9_small);
    FUN_20164018(P(obj, SC_RAMP_A), scope_ramp_tab_a[0]);
    FUN_20163f44(P(obj, SC_RAMP_B), scope_ramp_tab_b[0]);
    scope3d_obj_init(scope3d_obj_a);
    uint32_t vb = FUN_20164680(P(obj, SC_RAMP_B));
    FUN_20158838(scope3d_obj_a, scope_ramp_tab_c[0], FUN_2016469c(P(obj, SC_RAMP_A)), vb);
    FUN_201640a4(P(obj, SC_RAMP_C), P(obj, SC_RAMP_A));
    FUN_20163fd0(P(obj, SC_RAMP_D), P(obj, SC_RAMP_B));
    scope3d_obj_init(scope3d_obj_b);
    uint32_t vd = FUN_20164680(P(obj, SC_RAMP_D));
    FUN_20158838(scope3d_obj_b, scope_ramp_tab_c[0], FUN_2016469c(P(obj, SC_RAMP_C)), vd);
    scope_obj_set_2e04_thunk(obj, 100);
    scope_obj_set_2e00(obj, 0);
    scope_obj_set_2e02(obj, 0);
    FUN_20162c28(P(obj, 0x2E06), *(uint32_t *)(scope3d_obj_a + 0x10 + 0x88));
    FUN_20162c28(P(obj, 0x3008), *(uint32_t *)(scope3d_obj_b + 0x10 + 0x88));
    scope_wf_bank_set(obj, 2);
    scope_obj_history_clear(obj);
}

/* 0x2016340C: (obj, i): the marker record of 3DSS line i [fact] */
void *scope_obj_line_markers(uint8_t *obj, int i)
{
    return obj + SC_MARKERS + 0x54 * i;
}

/* 0x201634B8: (obj, i, mode): entry i of the vertical scale of mode 8 or 9, else 0 [fact] */
unsigned scope_obj_vscale(uint8_t *obj, int i, int mode)
{
    if (mode == 8)
    {
        return scope_tables.vscale8[i];
    }
    if (mode == 9)
    {
        return scope_tables.vscale9[i];
    }
    return 0;
}

/* 0x201634F0: (obj, i): the i-th newest row of the selected waterfall bank, by the ring index of bank 0, or of bank 1
 * when bank 1 is selected; the third argument is not used [fact] */
uint8_t *scope_obj_wf_row_addr(uint8_t *obj, int i, int unused)
{
    int slot = ring133_offset(P(obj, SC_RING_WF0), ~i);

    if (scope_tables.bank == 1)
    {
        slot = ring133_offset(P(obj, SC_RING_WF1), ~i);
    }
    return obj + SC_WF_BANK0 + scope_tables.bank * SC_WF_BANK_SIZE + slot * SC_WF_ROW;
}

/* 0x20163564: (obj, i, mode, expanded): entry i of the ROM scale table of the layout (not the selected one in
 * scope_tables), 0 for other modes [fact] */
unsigned scope_obj_line_offset(uint8_t *obj, int i, int mode, int expanded)
{
    if (mode == 8)
    {
        return (expanded ? scope_vscale8_large : scope_vscale8_small)[i];
    }
    if (mode == 9)
    {
        return (expanded ? scope_vscale9_large : scope_vscale9_small)[i];
    }
    return 0;
}

/* --- the thunks to the instance 0x2047963C, in the image's order --- */

/* 0x201342B4: the object cleared and initialised (scope_obj_init 0x20158330) [fact] */
void scope_objects_init(void)
{
    __aeabi_memclr4(scope_obj, SCOPE_OBJ_SIZE);
    scope_obj_init(scope_obj);
}

void scope_obj_bank_reset(int which)              /* 0x201342D0 */
{
    scope_wf_bank_set(scope_obj, which);
}

void scope_palette_set(int a, int b)              /* 0x201342DC */
{
    scope_obj_palette_set(scope_obj, a, b);
}

void scope_store_frame(const uint8_t *rec)        /* 0x201342EC */
{
    scope_obj_store_record(scope_obj, rec);
}

void scope_freeze_a_set(int v)                    /* 0x201342F8 */
{
    scope_obj_freeze_a_set(scope_obj, v);
}

void scope_freeze_b_set(int v)                    /* 0x20134304 */
{
    scope_obj_freeze_b_set(scope_obj, v);
}

void scope_history_reset(void)                    /* 0x20134310 */
{
    scope_obj_history_clear(scope_obj);
}

void scope_obj_7f8c_thunk(int a)                  /* 0x2013433C (FUN_2013433c, no caller) */
{
    scope_obj_7f8c(scope_obj, a);
}

unsigned scope3d_vscale(int i, int mode)          /* 0x20134358 */
{
    return scope_obj_vscale(scope_obj, i, mode);
}

unsigned scope3d_line_offset(int i, int mode, int expanded)   /* 0x20134368 */
{
    return scope_obj_line_offset(scope_obj, i, mode, expanded);
}

int scope_levels_get(int a, void *out)            /* 0x2013437C */
{
    return scope_obj_levels_get(scope_obj, a, out, 0);
}

/* 0x20134390: replaces only r0, so the caller's r1..r3 reach scope_obj_levels_get unchanged; no caller in the image
 * [fact: ldr r0, =0x2047963C; b 0x20157C50; functions.tsv: 0 callers] */
int scope_record_hold_copy(int unused, int a, void *out, int c)
{
    return scope_obj_levels_get(scope_obj, a, out, c);
}

/* 0x20134398: (mode): the second colour ramp: word +0x3848 of the 3D object's sub-object +0x9C (mode 8), +0x10E8 of
 * 0x20478550 (mode 9), or +0x88 of the sub-object +0x10 [fact] */
uint32_t scope_ramp_get(int mode)
{
    if (mode == 8)
    {
        return FUN_20164674(scope3d_obj_b + 0x9C);
    }
    if (mode == 9)
    {
        return FUN_20164654(scope3d_obj_c);
    }
    return FUN_2016466c(scope3d_obj_b + 0x10);
}

void *scope3d_line_markers(int i)                 /* 0x20134408 */
{
    return scope_obj_line_markers(scope_obj, i);
}

int scope_wf_add_row(const void *rec)             /* 0x20134414 */
{
    return scope_obj_wf_add_row(scope_obj, rec, 0);
}

int scope_wf_add_row_mode(const void *rec, int mode)   /* 0x20134424 */
{
    return scope_obj_wf_add_row(scope_obj, rec, mode);
}

uint8_t *scope_wf_row_addr(int i, int b)          /* 0x20134434 */
{
    return scope_obj_wf_row_addr(scope_obj, i, b);
}

/* 0x20134444 (FUN_20134444): (v, on): byte +0x2E04 = v, then scope_obj_set_2e00(on) [fact] */
int scope_set_2e04_2e00(int v, int on)
{
    scope_obj_set_2e04_thunk(scope_obj, v);
    return scope_obj_set_2e00(scope_obj, on);
}

int scope_set_2e00(int on)                        /* 0x20134468 (FUN_20134468) */
{
    return scope_obj_set_2e00(scope_obj, on);
}

void scope_set_2e02(int on)                       /* 0x20134474 (FUN_20134474) */
{
    scope_obj_set_2e02(scope_obj, on);
}

void scope3d_layout_set(int expanded)             /* 0x20134480 */
{
    scope_obj_layout_set(scope_obj, expanded);
}

void scope_reset_bank0(void)                      /* 0x2013448C */
{
    scope_obj_reset_bank0(scope_obj);
}

void scope_reset_bank1(void)                      /* 0x20134498 */
{
    scope_obj_reset_bank1(scope_obj);
}

uint8_t *scope_frame_buf(void)                    /* 0x201344A0: the instance's record */
{
    return scope_obj + SC_RECORD;
}

void scope_indices_clear(void)                    /* 0x201344A8 */
{
    scope_obj_indices_clear(scope_obj);
}
