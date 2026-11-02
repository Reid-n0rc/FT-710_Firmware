// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20157634 @ 20157634 (188 bytes)

void FUN_20157634(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint n;
  ulonglong __aeabi_idivmod_ret;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(param_1 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar4 = (uint)*param_3;
  n = param_2 * 10000;
  uVar2 = (uint)param_3[1];
  if (uVar4 <= uVar2) {
    do {
      bVar1 = *param_3;
      __aeabi_idivmod_ret = __aeabi_idivmod(n,(uVar2 - bVar1) + 1);
      iVar3 = (int)__aeabi_idivmod_ret * ((uVar4 - bVar1) + 1) + 0x26ac;
      *(char *)(param_1 + uVar4) =
           ((char)(iVar3 / 10000) + (char)(iVar3 >> 0x1f)) -
           (char)((longlong)iVar3 * 0x68db8bad >> 0x3f);
      uVar4 = uVar4 + 1;
      uVar2 = (uint)param_3[1];
    } while ((int)uVar4 <= (int)uVar2);
  }
  uVar2 = uVar2 + 1;
  if (uVar2 < 0x100) {
    do {
      *(char *)(param_1 + uVar2) =
           ((char)((int)n / 10000) + (char)((int)n >> 0x1f)) -
           (char)((longlong)(int)n * 0x68db8bad >> 0x3f);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
  }
  return;
}


// ===== scope_wf_bank_set @ 201576f4 (108 bytes)

/* (obj, 0/1/2): 0 clears waterfall bank 0 (0x33F40 B at obj+0x1B130) and selects it (0x20450280 =
   0), 1 selects bank 1, 2 clears both banks [fact] */

void scope_wf_bank_set(int param_1,int param_2)

{
  if (param_2 == 0) {
    __aeabi_memclr4(param_1 + 0x1b130,0x33f40);
    ring133_reset(param_1 + 0x82fb4);
    DAT_20450280 = 0;
  }
  else {
    if (param_2 != 1) {
      __aeabi_memclr4(param_1 + 0x1b130,0x67e80);
      ring133_reset(param_1 + 0x82fb4);
      ring133_reset(param_1 + 0x82fb0);
      return;
    }
    DAT_20450280 = 1;
  }
  return;
}


// ===== scope_obj_history_clear @ 20157778 (116 bytes)

/* (obj): scope record and hold copy to 0xFF, clears the history and 3D work buffers of the scope
   object [fact] */

void scope_obj_history_clear(int param_1)

{
  __aeabi_memset(param_1 + 0x9c7f,0x352,0xff);
  __aeabi_memset(param_1 + 0x9fd1,0x352,0xff);
  __aeabi_memclr4(param_1 + 0x10abc,0x6798);
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
  __aeabi_memclr(param_1 + 0xa323,24000);
  __aeabi_memclr4(param_1 + 0x17258,0x3ed4);
  __aeabi_memclr4_veneer(param_1 + 0x100e4,0x9d8);
  return;
}


// ===== copy_inverted_words_b @ 201577f8 (36 bytes)

/* (this, dst, src, n): n/4 words dst = ~src (second copy of copy_inverted_words);
   scope_history_push uses it [fact] */

void copy_inverted_words_b(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  for (param_4 = param_4 >> 2; param_4 != 0; param_4 = param_4 - 1) {
    *param_2 = ~*param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== scope_obj_store_record @ 2015781c (156 bytes)

/* [fact] (obj, rec): the 850-byte record into +0x9C7F unless frozen (+0x9C7C), blank (0xFF) while
   0x208004A0 or +0x9C7E is set, the default 800 bytes 0x203D9B14 at +0x9C98 with 0x20808A84 bit 10;
   tail call of scope_store_frame; new entry (T24 USB track) */

void scope_obj_store_record(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 0x9c7f;
  if (*(char *)(param_1 + 0x9c7c) == '\0') {
    if ((DAT_208004a0 == '\0') && (*(char *)(param_1 + 0x9c7e) == '\0')) {
      memcpy(iVar1,param_2,0x352);
    }
    else {
      __aeabi_memset(iVar1,0x352,0xff);
    }
    if (((ushort)DAT_20808a84 & 0x400) != 0) {
      __aeabi_memcpy4(param_1 + 0x9c98,&DAT_203d9b14,800);
      return;
    }
  }
  else if (*(char *)(param_1 + 0x9c7e) != '\0') {
    __aeabi_memset_veneer(iVar1,0x352,0xff);
    return;
  }
  return;
}


// ===== scope_obj_reset_bank0 @ 201578c8 (40 bytes)

/* (obj): clears +0x9C7E, scope_obj_history_clear, scope_wf_bank_set(0) [fact] */

void scope_obj_reset_bank0(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  scope_obj_history_clear();
                    /* 0 clears waterfall bank 0 [doc] */
  scope_wf_bank_set(param_1,0);
  return;
}


// ===== scope_obj_freeze_b_set @ 201578f0 (12 bytes)

/* [fact] (obj, v): byte +0x9C7D = v; tail call of scope_freeze_b_set; new entry (T24 USB track) */

void scope_obj_freeze_b_set(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x9c7d) = param_2;
  return;
}


// ===== scope_obj_palette_set @ 201578fc (240 bytes)

/* [fact] (obj, a, b): the colour ramps of COLOR a (tables 0x203D9A54 / +104 / +148) into ramp
   sub-objects +0x320C / +0x5DC4 and the 3D object 0x20470294, of COLOR b into +0x6744 / +0x92FC and
   0x20474C68; tail call of scope_palette_set; new entry (T24 USB track) */

void scope_obj_palette_set(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_20164018(param_1 + 0x320c,(&PTR_DAT_203d9a54)[param_2]);
  FUN_20163f44(param_1 + 0x5dc4,(&PTR_DAT_203d9abc)[param_2]);
  uVar1 = FUN_20164680(param_1 + 0x5dc4);
  uVar2 = FUN_2016469c(param_1 + 0x320c);
  FUN_20158838(&DAT_20470294,(&PTR_DAT_203d9ae8)[param_2],uVar2,uVar1);
  FUN_20164018(param_1 + 0x6744,(&PTR_DAT_203d9a54)[param_3]);
  FUN_20163f44(param_1 + 0x92fc,(&PTR_DAT_203d9abc)[param_3]);
  uVar1 = FUN_20164680(param_1 + 0x92fc);
  uVar2 = FUN_2016469c(param_1 + 0x6744);
  FUN_20158838(&DAT_20474c68,(&PTR_DAT_203d9ae8)[param_3],uVar2,uVar1);
  FUN_20162c28(param_1 + 0x2e06,DAT_2047032c);
  FUN_20162c28(param_1 + 0x3008,DAT_20474d00);
  return;
}


// ===== scope_obj_redraw_history @ 20157a00 (436 bytes)

/* [fact] (obj, mode, flag): the 3DSS history redraw behind scope3d_redraw_history (ring30 walk over
   29 lines, modes 8 / 9); new entry (T24 USB track) */

void scope_obj_redraw_history(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  if (((*(char *)(param_1 + 0x9c7c) == '\0') && (*(char *)(param_1 + 0x9c7d) == '\0')) &&
     (*(char *)(param_1 + 0x9c7e) == '\0')) {
                    /* returns idx and advances it [doc] */
    ring30_advance();
    iVar2 = 0x1d;
    do {
      iVar1 = ring30_offset(param_1 + 0x17254,-iVar2);
      iVar1 = param_1 + iVar1 * 800 + 0x10abc;
      iVar4 = param_1 + iVar2 * 800 + 0xa323;
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
      __aeabi_memclr(iVar4,800);
      if (param_2 == 8) {
        if (param_3 == 0) {
          FUN_20133ee8(iVar2,iVar4,iVar1);
        }
        else {
          FUN_20133efc();
        }
      }
      else if ((param_2 == 9) && (iVar2 < 0xf)) {
        FUN_20133f24(iVar2,iVar4,iVar1);
      }
      iVar2 = iVar2 + -1;
    } while (1 < iVar2);
    iVar2 = 0x1d;
    do {
      iVar1 = ring30_offset(param_1 + 0x17254,-iVar2);
      piVar3 = (int *)(param_1 + iVar1 * 0x54 + 0x1687c);
      piVar5 = (int *)(param_1 + iVar2 * 0x54 + 0x100e4);
      if ((param_2 == 8) || ((param_2 == 9 && (iVar2 < 0xf)))) {
        iVar1 = *piVar3;
        iVar4 = 0;
        if (0 < iVar1) {
          do {
            if (param_2 == 8) {
              if (param_3 == 0) goto LAB_20157b88;
              FUN_20133f58(iVar2,piVar3 + iVar4 + 1,piVar5 + iVar4 + 1);
            }
            else if ((param_2 == 9) && (iVar2 < 0xf)) {
LAB_20157b88:
              FUN_20133f44(iVar2);
            }
            iVar1 = *piVar3;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar1);
        }
        *piVar5 = iVar1;
      }
      iVar2 = iVar2 + -1;
    } while (1 < iVar2);
  }
  return;
}


// ===== scope_obj_freeze_a_set @ 20157bc4 (12 bytes)

/* [fact] (obj, v): byte +0x9C7C = v; tail call of scope_freeze_a_set; new entry (T24 USB track) */

void scope_obj_freeze_a_set(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x9c7c) = param_2;
  return;
}


// ===== scope_obj_layout_set @ 20157bd0 (108 bytes)

/* [fact] (obj, expanded): the flag into the four ramp sub-objects and the mode-8/9 vertical scale
   pointers 0x20450278/7C (0x203D9A18/0x203D9A9E or 0x203D99DC/0x203D9A80); tail call of
   scope3d_layout_set; new entry (T24 USB track) */

void scope_obj_layout_set(int param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0x320c) = uVar1;
  *(undefined1 *)(param_1 + 0x5dc4) = uVar1;
  *(undefined1 *)(param_1 + 0x6744) = uVar1;
  *(undefined1 *)(param_1 + 0x92fc) = uVar1;
  if (param_2 != 0) {
    DAT_20450278 = &DAT_203d9a18;
  }
  else {
    DAT_20450278 = (undefined2 *)&DAT_203d99dc;
  }
  if (param_2 != 0) {
    DAT_2045027c = &DAT_203d9a9e;
  }
  else {
    DAT_2045027c = (undefined2 *)&DAT_203d9a80;
  }
  return;
}


// ===== scope_obj_levels_get @ 20157c50 (224 bytes)

/* (obj, mode, out, ...): per-column levels for mode 8 / 9 / other from the live record or, while
   SPEED STOP (0x20800498), from the hold copy, scaled by the 3D sub-object of the mode (method
   behind scope_levels_get) [fact] */

void scope_obj_levels_get(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_1 + 0x9c98;
  if (DAT_20800498 == '\0') {
    memcpy(param_1 + 0x9fd1,param_1 + 0x9c7f,0x352,param_4,param_4);
  }
  else {
    if (param_2 != 8 && param_2 != 9) goto LAB_20157cc4;
    iVar1 = param_1 + 0x9fea;
  }
  if (param_2 == 8) {
    FUN_201633a0(param_1,param_3,iVar1,param_4);
    FUN_20164674(0x20470330);
    return;
  }
  if (param_2 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_3,iVar1,param_4);
    FUN_20164654(0x20473b7c);
    return;
  }
LAB_20157cc4:
  FUN_201633a0(param_1 + 0x2d00,param_3,iVar1,param_4);
  FUN_2016466c(0x204702a4);
  return;
}


// ===== scope_obj_wf_add_row @ 20157d3c (552 bytes)

/* (obj, record, mode): adds a waterfall row: takes the newest history rows (ring index
   obj+0x17254), adds the level offset to each point (clamp_add_u8, 0..255) into the current
   waterfall bank (gui.md: scope_wf_add_row) [fact for the calls] */

void scope_obj_wf_add_row(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  
  if ((((DAT_20800498 == '\0') && (*(char *)(param_1 + 0x9c7c) == '\0')) &&
      (*(char *)(param_1 + 0x9c7d) == '\0')) && (*(char *)(param_1 + 0x9c7e) == '\0')) {
    iVar4 = ring30_offset(param_1 + 0x17254,0xffffffff);
    iVar9 = param_1 + iVar4 * 800 + 0x10abc;
    iVar4 = param_1 + 0x1b12c;
    iVar5 = ring20_offset(iVar4,0);
    memcpy(iVar9,param_1 + iVar5 * 800 + 0x17258,800);
    iVar5 = 1;
    if (1 < param_2) {
      do {
        iVar6 = ring20_offset(iVar4,-iVar5);
        iVar7 = 0;
        do {
          bVar3 = *(byte *)(param_1 + iVar6 * 800 + 0x17258 + iVar7);
          if (*(byte *)(iVar9 + iVar7) < bVar3) {
            *(byte *)(iVar9 + iVar7) = bVar3;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 800);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
                    /* returns idx and advances it [doc] */
    iVar5 = ring133_advance(param_1 + 0x82fb4);
    puVar10 = &DAT_20450278;
    if (DAT_20450280 == 1) {
      iVar5 = ring133_advance(param_1 + 0x82fb0);
    }
    if (param_3 != 0) {
      puVar10 = (undefined4 *)0x0;
    }
    iVar5 = param_1 + DAT_20450280 * 0x33f40 + iVar5 * 0x640 + 0x1b130;
    if (param_3 != 0) {
      do {
        iVar7 = clamp_add_u8(*(undefined1 *)(iVar9 + (int)puVar10),param_3);
        iVar6 = (int)puVar10 * 2;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        *(undefined2 *)(iVar5 + iVar6) = *(undefined2 *)(param_1 + iVar7 * 2 + 0x2e06);
      } while ((int)puVar10 < 800);
    }
    else {
      iVar6 = 0;
      do {
        pbVar2 = (byte *)(iVar9 + iVar6);
        iVar7 = iVar6 * 2;
        iVar6 = iVar6 + 1;
        *(undefined2 *)(iVar5 + iVar7) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x2e06);
      } while (iVar6 < 800);
    }
    iVar6 = 0;
    piVar11 = (int *)(param_1 + 0x1b0d8);
    if (0 < *piVar11) {
      do {
        iVar7 = ring20_offset(iVar4,-iVar6);
        uVar8 = (uint)*(ushort *)(piVar11 + iVar7 + 1);
        if (uVar8 < *(ushort *)((int)piVar11 + iVar7 * 4 + 6) + uVar8) {
          do {
            iVar1 = uVar8 * 2;
            pbVar2 = (byte *)(iVar9 + uVar8);
            uVar8 = uVar8 + 1;
            *(undefined2 *)(iVar5 + iVar1) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x3008);
          } while ((int)uVar8 <
                   (int)((uint)*(ushort *)(piVar11 + iVar7 + 1) +
                        (uint)*(ushort *)((int)piVar11 + iVar7 * 4 + 6)));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar11);
    }
  }
  return;
}


// ===== FUN_20157f8c @ 20157f8c (124 bytes)

void FUN_20157f8c(int param_1)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x9c7c) == '\0') && (*(char *)(param_1 + 0x9c7d) == '\0')) &&
     (*(char *)(param_1 + 0x9c7e) == '\0')) {
                    /* returns idx and advances it [doc] */
    ring20_advance();
    iVar1 = ring20_offset(param_1 + 0x1b12c,0);
                    /* n/4 words dst = ~src [doc] */
    copy_inverted_words_b(param_1,param_1 + iVar1 * 800 + 0x17258,param_1 + 0x9c98,800);
    return;
  }
  return;
}


// ===== scope_obj_history_push @ 20158010 (196 bytes)

/* [fact] the method behind scope_history_push (tail call at 0x20134354); new entry (T24 USB track)
    */

void scope_obj_history_push(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  
  if ((((DAT_20800498 == '\0') && (*(char *)(param_1 + 0x9c7c) == '\0')) &&
      (*(char *)(param_1 + 0x9c7d) == '\0')) && (*(char *)(param_1 + 0x9c7e) == '\0')) {
                    /* returns idx and advances it [doc] */
    ring20_advance();
    iVar1 = ring20_offset(param_1 + 0x1b12c,0);
                    /* n/4 words dst = ~src [doc] */
    copy_inverted_words_b(param_1,param_1 + iVar1 * 800 + 0x17258,param_1 + 0x9c98,800);
    iVar1 = param_1 + iVar1 * 4;
    *(undefined2 *)(iVar1 + 0x1b0dc) = *param_3;
    *(undefined2 *)(iVar1 + 0x1b0de) = param_3[1];
    iVar1 = *(int *)(param_1 + 0x1b0d8) + 1;
    *(int *)(param_1 + 0x1b0d8) = iVar1;
    if (param_2 <= iVar1) {
      *(int *)(param_1 + 0x1b0d8) = param_2;
    }
  }
  return;
}


// ===== scope_obj_add_line @ 201580e0 (568 bytes)

/* [fact] the method behind scope3d_add_line (tail call at 0x20134338); new entry (T24 USB track) */

void scope_obj_add_line(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  if (((*(char *)(param_1 + 0x9c7c) == '\0') && (*(char *)(param_1 + 0x9c7d) == '\0')) &&
     (*(char *)(param_1 + 0x9c7e) == '\0')) {
    iVar2 = ring30_offset(param_1 + 0x17254,0xffffffff,param_3,param_4,param_4);
    iVar9 = param_1 + iVar2 * 800 + 0x10abc;
    iVar3 = param_1 + 0x1b12c;
    iVar4 = ring20_offset(iVar3,0);
    memcpy(iVar9,param_1 + iVar4 * 800 + 0x17258,800);
    iVar4 = 1;
    if (1 < param_3) {
      do {
        iVar5 = ring20_offset(iVar3,-iVar4);
        iVar6 = 0;
        do {
          bVar1 = *(byte *)(param_1 + iVar5 * 800 + 0x17258 + iVar6);
          if (*(byte *)(iVar9 + iVar6) < bVar1) {
            *(byte *)(iVar9 + iVar6) = bVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 800);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_3);
    }
    iVar5 = 0;
    iVar4 = *(int *)(param_1 + 0x1b0d8);
    if (0 < iVar4) {
      iVar6 = param_1 + iVar2 * 0x54;
      do {
        iVar7 = ring20_offset(iVar3,-iVar5);
        iVar4 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        *(undefined4 *)(iVar6 + iVar4 + 0x16880) = *(undefined4 *)(param_1 + iVar7 * 4 + 0x1b0dc);
        iVar4 = *(int *)(param_1 + 0x1b0d8);
      } while (iVar5 < iVar4);
    }
    iVar3 = param_1 + iVar2 * 0x54;
    *(int *)(iVar3 + 0x1687c) = iVar4;
    iVar2 = param_1 + 0xa643;
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
    __aeabi_memclr(iVar2,800);
    if (param_2 == 8) {
      if (param_4 == 0) {
        FUN_20133ec0(1,iVar2,iVar9);
      }
      else {
        FUN_20133ed4();
      }
    }
    else if (param_2 == 9) {
      FUN_20133f10(1,iVar2,iVar9);
    }
    piVar8 = (int *)(iVar3 + 0x1687c);
    iVar2 = *piVar8;
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (param_2 == 8) {
          if (param_4 == 0) goto LAB_201582f8;
          FUN_20133f58(1,piVar8 + iVar3 + 1,(int *)(param_1 + 0x10138) + iVar3 + 1);
        }
        else if (param_2 == 9) {
LAB_201582f8:
          FUN_20133f44(1);
        }
        iVar2 = *piVar8;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    *(int *)(param_1 + 0x10138) = iVar2;
  }
  return;
}


// ===== scope_obj_init @ 20158330 (420 bytes)

/* [fact] (obj): flags off, record and hold copy blank, the ramp sub-objects and both 3D objects set
   up with COLOR 0, +0x2E04 = 100, both waterfall banks and the history cleared; tail call of
   scope_objects_init; new entry (T24 USB track) */

void scope_obj_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined1 *)(param_1 + 0x9c7c) = 0;
  *(undefined1 *)(param_1 + 0x9c7d) = 0;
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  __aeabi_memset(param_1 + 0x9c7f,0x352,0xff,param_4,param_4);
  __aeabi_memset(param_1 + 0x9fd1,0x352,0xff);
  iVar1 = param_1 + 0x320c;
  FUN_20164054(iVar1,0,0x1e,&DAT_203d9a18,&DAT_203d99dc);
  iVar2 = param_1 + 0x5dc4;
  FUN_20163f80(iVar2,0,0xf,&DAT_203d9a9e);
  FUN_20164018(iVar1,&DAT_203b6704);
  FUN_20163f44(iVar2,&DAT_203daf14);
                    /* resets the three sub-objects [doc] */
  scope3d_obj_init(&DAT_20470294);
  uVar3 = FUN_20164680(iVar2);
  uVar4 = FUN_2016469c(iVar1);
  FUN_20158838(&DAT_20470294,&DAT_203e58ac,uVar4,uVar3);
  FUN_201640a4(param_1 + 0x6744,iVar1);
  FUN_20163fd0(param_1 + 0x92fc,iVar2);
  scope3d_obj_init(&DAT_20474c68);
  uVar3 = FUN_20164680(param_1 + 0x92fc);
  uVar4 = FUN_2016469c(param_1 + 0x6744);
  FUN_20158838(&DAT_20474c68,&DAT_203e58ac,uVar4,uVar3);
  scope_obj_set_2e04_thunk(param_1,100);
  scope_obj_set_2e00(param_1,0);
  scope_obj_set_2e02(param_1,0);
  FUN_20162c28(param_1 + 0x2e06,DAT_2047032c);
  FUN_20162c28(param_1 + 0x3008,DAT_20474d00);
                    /* 0 clears waterfall bank 0 [doc] */
  scope_wf_bank_set(param_1,2);
  scope_obj_history_clear(param_1);
  return;
}


// ===== scope_obj_set_2e00 @ 201584f8 (68 bytes)

/* [fact] (obj, on): halfword 0x20428294 (on) or 0x20428298 into +0x2E00, +0x3006, +0x3208, then
   scope_obj_apply_2e00; Ghidra FUN_201584f8 (T24 USB track) */

void scope_obj_set_2e00(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x2e00) = 0xff38;
    *(undefined2 *)(param_1 + 0x3006) = 0xff38;
    *(undefined2 *)(param_1 + 0x3208) = 0xff38;
  }
  else {
    *(undefined2 *)(param_1 + 0x2e00) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3006) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3208) = 0xaf4c;
  }
  scope_obj_apply_2e00();
  return;
}


// ===== scope_obj_set_2e02 @ 20158544 (28 bytes)

/* [fact] (obj, on): halfword 0x2042829C (on) or 0x204282A0 into +0x2E02, then scope_obj_apply_2e02;
   Ghidra FUN_20158544 (T24 USB track) */

void scope_obj_set_2e02(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = &DAT_204282a0;
  }
  else {
    puVar1 = &DAT_2042829c;
  }
  *(undefined2 *)(param_1 + 0x2e02) = *puVar1;
  scope_obj_apply_2e02();
  return;
}


// ===== scope_obj_reset_bank1 @ 20158568 (40 bytes)

/* (obj): clears +0x9C7E, scope_obj_history_clear, scope_wf_bank_set(1) [fact] */

void scope_obj_reset_bank1(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  scope_obj_history_clear();
                    /* 0 clears waterfall bank 0 [doc] */
  scope_wf_bank_set(param_1,1);
  return;
}


// ===== scope_obj_indices_clear @ 20158590 (104 bytes)

/* (obj): zeroes the four ring indices +0x17254, +0x1B12C, +0x82FB0, +0x82FB4 [fact] */

int scope_obj_indices_clear(int param_1)

{
  *(undefined4 *)(param_1 + 0x17254) = 0;
  *(undefined4 *)(param_1 + 0x1b12c) = 0;
  *(undefined4 *)(param_1 + 0x82fb0) = 0;
  *(undefined4 *)(param_1 + 0x82fb4) = 0;
  return param_1;
}


// ===== msgbuf_init @ 20158618 (24 bytes)

/* (obj): clears the two u16 indices +4/+6 and the 0x80-byte buffer at +8; used by the same TX
   objects [fact] */

void msgbuf_init(int param_1)

{
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  __aeabi_memclr4_veneer(param_1 + 8,0x80);
  return;
}


// ===== mainlink_tx_alloc @ 20158630 (12 bytes)

/* gets a free 0x408-byte buffer */

uint mainlink_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = txpool_next_slot(param_1 + 0x811c);
  return uVar1;
}


// ===== mainlink_tx_init @ 2015863c (96 bytes)

/* 32 x 0x408 B buffer pool + mailbox */

void mainlink_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
                    /* Creates the pool mutex [doc] */
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    msgbuf_init(iVar3 + 0x1c);
    txpool_set_slot(param_1 + 0x811c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x81a4) = uVar1;
  return;
}


// ===== mainlink_tx_clear_stats @ 2015869c (16 bytes)

void mainlink_tx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== task_mainlink_tx @ 201586ac (152 bytes)

/* task "uart" pri 4: mailbox -> scif_write(buf+8, len), then mainlink_trace */

void task_mainlink_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  mainlink_tx_clear_stats(param_1);
  do {
    do {
      itron_trcv_mbx(*(undefined4 *)(param_1 + 0x81a4),local_8,0xffffffff);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
    } while (iVar1 == 0);
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
    mainlink_trace(local_8[0] + 8,(uint)*(ushort *)(local_8[0] + 6));
  } while( true );
}


// ===== mainlink_tx_post @ 20158744 (100 bytes)

/* waits for the 3 ms pacing counter, posts to the TX mailbox, re-arms cmd_interval */

void mainlink_tx_post(int param_1,uint param_2)

{
  while (g_ml.pace_count != 0) {
    itron_dly_tsk(1);
  }
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x81a4),param_2);
  itron_twai_sem(g_ml.pace_sem,0xffffffff);
  g_ml.pace_count = 3;
  itron_sig_sem(g_ml.pace_sem);
  return;
}


// ===== mainlink_tx_ctor @ 201587ac (32 bytes)

/* vtbl 0x20427FAC */

int mainlink_tx_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fac;
  iVar1 = FUN_20162c18((int)param_1 + 0x811c);
  return iVar1 + -0x811c;
}


// ===== FUN_201587d0 @ 201587d0 (44 bytes)

void FUN_201587d0(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// ===== scope3d_obj_init @ 201587fc (60 bytes)

/* (obj): resets the three sub-objects (+0x10, +0x9C, +0x38E8) and byte 0; used for the 3D objects
   0x20470294 / 0x20474C68 by scope_objects_init [fact] */

void scope3d_obj_init(undefined1 *param_1)

{
  FUN_20163d44(param_1 + 0x10,0);
  FUN_20163f14(param_1 + 0x9c,0);
  FUN_20163ae0(param_1 + 0x38e8,0);
  *param_1 = 0;
  return;
}


// ===== FUN_20158838 @ 20158838 (16 bytes)

void FUN_20158838(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined *puVar3;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  cVar1 = *param_1;
  puVar3 = (undefined *)0x3ff00000;
  uVar2 = 0;
  if (cVar1 == '\x01') {
    uVar2 = 0x9999999a;
    puVar3 = &DAT_3fe99999;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 0x33333333;
    puVar3 = &DAT_3fe33333;
  }
  else if (cVar1 == '\x03') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fd99999;
  }
  else if (cVar1 == '\x04') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fc99999;
  }
  *param_1 = cVar1;
  FUN_20163ca4(param_1 + 0x10,cVar1,uVar2,puVar3,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar2,puVar3,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar2,puVar3,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158848 @ 20158848 (180 bytes)

void FUN_20158848(undefined1 *param_1,int param_2)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)0x3ff00000;
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = 0x9999999a;
    puVar2 = &DAT_3fe99999;
  }
  else if (param_2 == 2) {
    uVar1 = 0x33333333;
    puVar2 = &DAT_3fe33333;
  }
  else if (param_2 == 3) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fd99999;
  }
  else if (param_2 == 4) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fc99999;
  }
  *param_1 = (char)param_2;
  FUN_20163ca4(param_1 + 0x10,param_2,uVar1,puVar2,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar1,puVar2,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar1,puVar2,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158914 @ 20158914 (12 bytes)

void FUN_20158914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


// ===== FUN_20158920 @ 20158920 (16 bytes)

void FUN_20158920(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== task_uart4_rx @ 20158930 (180 bytes)

/* passes raw bytes to FUN_20131154 */

void task_uart4_rx(int param_1)

{
  void *itron_twai_flg_ret;
  undefined4 uVar1;
  uint local_114;
  undefined1 auStack_110 [260];
  
  __aeabi_memclr4(auStack_110,0x100);
  FUN_20158920(param_1);
  while( true ) {
    while (itron_twai_flg_ret = itron_twai_flg(*(uint *)(param_1 + 0x24),0xc001,5,&local_114,-1),
          itron_twai_flg_ret == (void *)0xffffffce) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
    if (itron_twai_flg_ret != (void *)0x0) break;
    if (((local_114 & 0xc000) == 0) && ((local_114 & 1) != 0)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                        (*(int **)(param_1 + 0x10),auStack_110,0x100);
      decode_text_rx(auStack_110,uVar1);
    }
  }
  return;
}


// ===== FUN_201589e4 @ 201589e4 (12 bytes)

void FUN_201589e4(undefined4 *param_1)

{
  *param_1 = &DAT_20427fb8;
  return;
}


// ===== uart4_tx_alloc @ 201589f4 (12 bytes)

uint uart4_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = txpool_next_slot(param_1 + 0x111c);
  return uVar1;
}


// ===== uart4_tx_init @ 20158a00 (96 bytes)

void uart4_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
                    /* Creates the pool mutex [doc] */
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    msgbuf_init(iVar3 + 0x1c);
    txpool_set_slot(param_1 + 0x111c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x11a4) = uVar1;
  return;
}


// ===== FUN_20158a60 @ 20158a60 (16 bytes)

void FUN_20158a60(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== task_uart4_tx @ 20158a70 (108 bytes)

void task_uart4_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  FUN_20158a60();
  do {
    itron_trcv_mbx(*(undefined4 *)(param_1 + 0x11a4),local_8,0xffffffff);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
  } while( true );
}


// ===== uart4_tx_post @ 20158adc (16 bytes)

void uart4_tx_post(int param_1,uint param_2)

{
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x11a4),param_2);
  return;
}


// ===== FUN_20158aec @ 20158aec (32 bytes)

int FUN_20158aec(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fc4;
  iVar1 = FUN_20162c18(param_1 + 0x447);
  return iVar1 + -0x111c;
}


// ===== mainlink_obj_run @ 20158b10 (240 bytes)

/* task "uart" pri 7: binds SCIF5, starts the 3 sub-tasks, opens 345600 baud 8N2 */

void mainlink_obj_run(int param_1)

{
  uint uVar1;
  uint itron_acre_tsk_ret;
  uint itron_acre_tsk_ret_2;
  uint uVar2;
  
  uVar1 = itron_acre_tsk(0,(byte *)&ctsk_uart_5938);
  if (((0 < (int)uVar1) &&
      (itron_acre_tsk_ret = itron_acre_tsk(0,(byte *)&ctsk_uart_591c), 0 < (int)itron_acre_tsk_ret))
     && (itron_acre_tsk_ret_2 = itron_acre_tsk(0,(byte *)&ctsk_uart_5900),
        0 < (int)itron_acre_tsk_ret_2)) {
    uVar2 = param_1 + 0x8218;
                    /* 32 x 0x408 B buffer pool + mailbox [doc, inference] */
    mainlink_tx_init(uVar2,*(uint *)(param_1 + 0x10));
                    /* 32 x 0x408 B pool + mailbox [doc, inference] */
    mainlink_disp_init(param_1 + 0x58,uVar2);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x14);
    mainlink_rx_bind(param_1 + 0x18,*(uint *)(param_1 + 0x10),uVar2,param_1 + 0x58);
    uVar1 = itron_sta_tsk(uVar1,uVar2);
    if (((uVar1 == 0) && (uVar1 = itron_sta_tsk(itron_acre_tsk_ret,param_1 + 0x58), uVar1 == 0)) &&
       (uVar1 = itron_sta_tsk(itron_acre_tsk_ret_2,param_1 + 0x18), uVar1 == 0)) {
      (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x54600,8,0);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== mainlink_obj_ctor @ 20158c10 (48 bytes)

/* builds RX (+0x18), dispatcher (+0x58) and TX (+0x8218) sub-objects */

int mainlink_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fd0;
  iVar1 = mainlink_rx_ctor((int)param_1 + 0x18);
  iVar1 = mainlink_disp_ctor((void *)(iVar1 + 0x40));
  iVar1 = mainlink_tx_ctor((void *)(iVar1 + 0x81c0));
  return iVar1 + -0x8218;
}


// ===== uart4_obj_run @ 20158c44 (548 bytes)

/* 38400 baud; probes with 0xF0 bytes, then sends 1E 00 31 / 1F 00 32 */

void uart4_obj_run(int param_1)

{
  int iVar1;
  uint uVar2;
  uint itron_acre_tsk_ret;
  uint itron_acre_tsk_ret_2;
  uint uVar3;
  int i;
  undefined4 local_20;
  
  local_20 = 1;
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x9600,8,0);
  if (g_bootinfo.bank == 0xbbbb) {
    itron_tslp_tsk(0xffffffff);
  }
  if (DAT_2045001d == '\x01') {
    DAT_2045001d = '\x02';
    itron_tslp_tsk(0xffffffff);
  }
  i = 5;
  do {
    local_20 = 0xf0;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(*(int **)(param_1 + 0x10),&local_20,1);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))
                      (*(int **)(param_1 + 0x10),&DAT_2045001e,2,100);
    if (iVar1 != -1) {
      i = i + -1;
    }
    if (DAT_2045001d == '\x01') {
      DAT_2045001d = '\x02';
      itron_tslp_tsk(0xffffffff);
    }
  } while (i != 0);
  DAT_2045001c = 1;
  uVar2 = itron_acre_tsk(0,(byte *)&ctsk_uart4_583c);
  if (((0 < (int)uVar2) &&
      (itron_acre_tsk_ret = itron_acre_tsk(0,(byte *)&ctsk_uart4_5820), 0 < (int)itron_acre_tsk_ret)
      ) && (itron_acre_tsk_ret_2 = itron_acre_tsk(0,(byte *)&ctsk_uart4_5804),
           0 < (int)itron_acre_tsk_ret_2)) {
    uVar3 = param_1 + 0x938;
    uart4_tx_init(uVar3,*(uint *)(param_1 + 0x10));
    FUN_2015ff94(param_1 + 0x50,uVar3);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x14);
    FUN_20158914(param_1 + 0x18,*(undefined4 *)(param_1 + 0x10),uVar3,param_1 + 0x50);
    uVar2 = itron_sta_tsk(uVar2,uVar3);
    if (((uVar2 == 0) && (uVar2 = itron_sta_tsk(itron_acre_tsk_ret,param_1 + 0x50), uVar2 == 0)) &&
       (uVar2 = itron_sta_tsk(itron_acre_tsk_ret_2,param_1 + 0x18), uVar2 == 0)) {
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar3);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1e;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x31;
      uart4_tx_post(uVar3,uVar2);
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar3);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1f;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x32;
      uart4_tx_post(uVar3,uVar2);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== uart4_obj_ctor @ 20158e8c (48 bytes)

/* vtbl 0x20427FE4 */

int uart4_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fe4;
  iVar1 = FUN_201589e4((int)param_1 + 0x18);
  iVar1 = FUN_20160018(iVar1 + 0x38);
  iVar1 = FUN_20158aec(iVar1 + 0x8e8);
  return iVar1 + -0x938;
}


// ===== mainlink_send_ui_e2 @ 20158ec0 (96 bytes)

/* 0xE2 UI frame to MAIN */

void mainlink_send_ui_e2(void *param_1,uint param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
                    /* Copies 5 bytes [doc] */
  copy5((int)&local_18 + 1,param_2);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_18,6);
  }
  copy5((int)param_1 + 0x22,param_2);
  *(undefined1 *)param_1 = (undefined1)local_18;
  return;
}


// ===== mainlink_send_ui_c3 @ 20158f28 (120 bytes)

/* 0xC3 UI state frame to MAIN */

void mainlink_send_ui_c3(void *param_1,uint param_2)

{
  undefined4 local_38;
  undefined1 auStack_34 [36];
  
  __aeabi_memclr4(auStack_34,0x1e);
  local_38 = 0xc3;
  memcpy((int)&local_38 + 1,param_2,0x21);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_38,0x22);
  }
  memcpy((int)param_1 + 1,param_2,0x21);
  *(undefined1 *)param_1 = (undefined1)local_38;
  return;
}


// ===== FUN_20158fa8 @ 20158fa8 (40 bytes)

uint FUN_20158fa8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xb;
  param_1 = param_1 >> 4;
  uVar2 = 3;
  do {
    if ((param_1 & 1) != 0) {
      uVar1 = uVar2 & 0xff;
    }
    uVar2 = uVar2 - 1;
    param_1 = param_1 >> 1;
  } while (-1 < (int)uVar2);
  return uVar1;
}


// ===== touch_wait_tap @ 20158fd0 (132 bytes)

/* Waits for a touch: polls pointer_get_event / touch_cal_apply every tick until a press (event 2 or
   4), a release (5 or 6) or the power-key flag 0x20800493; fwupdate_screen and
   fwupdate_insert_sd_screen wait with it [fact] */

void touch_wait_tap(void)

{
  char local_20 [12];
  short local_14 [2];
  short local_10 [2];
  
  pointer_touch_poll();
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    gui_update_layers();
    local_14[0] = 0;
    local_10[0] = 0;
    pointer_get_event(local_20,1);
    touch_cal_apply((int)(short)local_20._4_4_,(int)(short)local_20._8_4_,local_14,local_10);
    if (local_20[0] == '\x02' || local_20[0] == '\x04') break;
    if (local_20[0] == '\x05' || local_20[0] == '\x06') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
  }
  return;
}

