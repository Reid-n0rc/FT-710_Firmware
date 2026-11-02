// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 46 functions

// ===== FUN_2016437c @ 2016437c (12 bytes)

void FUN_2016437c(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== ring133_advance @ 20164388 (28 bytes)

/* (idx): returns *idx and advances it; scope_obj_wf_add_row [fact] */

undefined4 ring133_advance(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
                    /* idx + 1, wrapping at 133 [doc] */
  uVar1 = ring133_next();
  *param_1 = uVar1;
  return uVar2;
}


// ===== ring133_reset @ 201643a4 (12 bytes)

/* (idx): *idx = 0; scope_wf_bank_set clears the waterfall ring index with it [fact] */

void ring133_reset(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== ring20_advance @ 201643b0 (28 bytes)

/* (idx): returns *idx and advances it; scope_history_push [fact] */

undefined4 ring20_advance(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
                    /* idx + 1, wrapping at 20 [doc] */
  uVar1 = ring20_next();
  *param_1 = uVar1;
  return uVar2;
}


// ===== ring30_advance @ 201643cc (28 bytes)

/* (idx): returns *idx and advances it; scope3d_redraw_history [fact] */

undefined4 ring30_advance(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
                    /* idx + 1, wrapping at 30 [doc] */
  uVar1 = ring30_next();
  *param_1 = uVar1;
  return uVar2;
}


// ===== ring32_post_inc @ 201643f0 (28 bytes)

/* Returns *idx and sets it to the next value mod 32 [fact] */

undefined2 ring32_post_inc(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = *param_1;
  uVar2 = ring32_next();
  *param_1 = uVar2;
  return uVar1;
}


// ===== FUN_2016440c @ 2016440c (8 bytes)

void FUN_2016440c(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== FUN_20164414 @ 20164414 (60 bytes)

void FUN_20164414(int param_1)

{
  uint itron_acre_mtx_ret;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  itron_acre_mtx_ret = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x44) = itron_acre_mtx_ret;
  return;
}


// ===== FUN_20164454 @ 20164454 (12 bytes)

void FUN_20164454(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== txpool_init_mutex @ 20164460 (60 bytes)

/* Creates the pool mutex (itron_acre_mtx, TA_INHERIT=2) into obj+0x84; called by mainlink_tx_init /
   uart4_tx_init / mainlink_disp_init [fact] */

void txpool_init_mutex(int param_1)

{
  uint itron_acre_mtx_ret;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  itron_acre_mtx_ret = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x84) = itron_acre_mtx_ret;
  return;
}


// ===== txpool_set_slot @ 201644a0 (12 bytes)

/* obj->slot[n] (obj+4+4n) = buffer [fact] */

void txpool_set_slot(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== txpool_next_slot @ 201644ac (56 bytes)

/* Under the pool mutex returns slot[idx] and advances the ring index (mod 32); mainlink_tx_alloc /
   uart4_tx_alloc / mainlink_disp_alloc [fact] */

undefined4 txpool_next_slot(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  mutex_guard_ctor(&uStack_10,*(undefined4 *)(param_1 + 0x84),1);
  iVar1 = ring32_post_inc(param_1);
  uVar2 = *(undefined4 *)(param_1 + iVar1 * 4 + 4);
                    /* Scoped lock destructor [doc] */
  mutex_guard_dtor(&uStack_10);
  return uVar2;
}


// ===== FUN_201644e4 @ 201644e4 (60 bytes)

void FUN_201644e4(int param_1)

{
  uint itron_acre_mtx_ret;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  itron_acre_mtx_ret = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x84) = itron_acre_mtx_ret;
  return;
}


// ===== FUN_20164524 @ 20164524 (12 bytes)

void FUN_20164524(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_20164568 @ 20164568 (56 bytes)

uint FUN_20164568(char *param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  if (cVar1 != param_3) {
    *param_1 = (char)param_3;
    iVar3 = (int)(char)((char)param_3 - cVar1);
  }
  uVar2 = param_2 + iVar3;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if ((int)uVar2 < 0x100) {
    uVar2 = uVar2 & 0xff;
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}


// ===== ring16_push @ 201645a0 (68 bytes)

/* Copies an 8-byte item into the slot at the tail if count < 16 [fact]; usbkbd_queue_key [fact] */

void ring16_push(ushort *param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*param_1 < 0x10) {
    uVar3 = param_2[1];
    uVar1 = param_1[2];
    puVar2 = *(undefined4 **)(param_1 + (uint)uVar1 * 2 + 4);
    *puVar2 = *param_2;
    puVar2[1] = uVar3;
    param_1[2] = uVar1 + 1 & 0xf;
    *param_1 = *param_1 + 1;
  }
  return;
}


// ===== ring16_reset @ 201645e4 (20 bytes)

/* Clears count, head and tail of a 16-entry ring {count, head, tail, slots} [fact] */

void ring16_reset(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== ring16_set_slot @ 201645f8 (12 bytes)

/* ring->slot[n] (obj+8+4n) = pointer [fact] */

void ring16_set_slot(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 8) = param_3;
  return;
}


// ===== ring16_pop @ 20164604 (52 bytes)

/* Returns the slot at the head and advances it (mod 16), 0 when empty [fact]; usbkbd_pop_key [fact]
    */

undefined4 ring16_pop(short *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = 0;
  }
  else {
    *param_1 = *param_1 + -1;
    uVar1 = param_1[1];
    param_1[1] = uVar1 + 1 & 0xf;
    uVar2 = *(undefined4 *)(param_1 + (uint)uVar1 * 2 + 4);
  }
  return uVar2;
}


// ===== ring16_ctor @ 20164638 (20 bytes)

/* ring16_reset, returns this [fact] */

undefined4 ring16_ctor(undefined4 param_1)

{
  ring16_reset();
  return param_1;
}


// ===== FUN_20164654 @ 20164654 (12 bytes)

undefined4 FUN_20164654(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10e8);
}


// ===== FUN_2016466c @ 2016466c (8 bytes)

undefined4 FUN_2016466c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x88);
}


// ===== FUN_20164674 @ 20164674 (12 bytes)

undefined4 FUN_20164674(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3848);
}


// ===== FUN_20164680 @ 20164680 (36 bytes)

undefined4 FUN_20164680(char *param_1)

{
  if (*param_1 == '\0') {
    return *(undefined4 *)(param_1 + 0x97c);
  }
  return *(undefined4 *)(param_1 + 4);
}


// ===== FUN_2016469c @ 2016469c (40 bytes)

undefined4 FUN_2016469c(char *param_1)

{
  if (*param_1 == '\0') {
    return *(undefined4 *)(param_1 + 0x2bb4);
  }
  return *(undefined4 *)(param_1 + 4);
}


// ===== FUN_201646bc @ 201646bc (84 bytes)

void FUN_201646bc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  FUN_20133e54(param_3 + 399,*(int *)(param_1 + 0x3c) + param_2 * 0x62e,0x317,param_4 + 399,
               0xfffffe75);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20164714 @ 20164714 (68 bytes)

void FUN_20164714(int param_1,int param_2,int param_3,int param_4)

{
  int i;
  
  FUN_20133e18(param_3 + 399,param_4 + 4,*(int *)(param_1 + 0x3c) + param_2 * 0x62e,0x317);
  i = 0;
  do {
    i = i + 1;
  } while (i < 800);
  return;
}


// ===== ring100_offset @ 20164758 (44 bytes)

/* (idx, d): (*idx + d + 100) % 100; affft_wf_row_addr uses it for the 100-row AF-FFT ring [fact] */

int ring100_offset(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 100) % 100;
}


// ===== ring100_next @ 20164788 (20 bytes)

/* (idx): *idx + 1, wrapping at 100 [fact] */

int ring100_next(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 100) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== ring133_offset @ 2016479c (48 bytes)

/* (idx, d): (*idx + d + 133) % 133; scope_wf_row_addr (133 waterfall rows per bank, gui.md) [fact]
    */

int ring133_offset(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x85 + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x99fc267 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return ((iVar1 >> 7) - (iVar1 >> 0x1f)) * -0x85 + uVar2;
}


// ===== ring133_next @ 201647d0 (20 bytes)

/* (idx): *idx + 1, wrapping at 133 [fact] */

int ring133_next(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x85) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== ring20_offset @ 201647e4 (44 bytes)

/* (idx, d): (*idx + d + 20) % 20; the 20-row history ring (scope_history_push, scope3d_add_line)
   [fact] */

int ring20_offset(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 0x14) % 0x14;
}


// ===== ring20_next @ 20164814 (20 bytes)

/* (idx): *idx + 1, wrapping at 20 [fact] */

int ring20_next(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x14) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== ring30_offset @ 20164828 (48 bytes)

/* (idx, d): (*idx + d + 30) % 30; the 30-line 3DSS ring (scope3d_add_line, scope3d_redraw_history)
   [fact] */

int ring30_offset(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x1e + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x77777777 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return uVar2 + ((iVar1 >> 4) - (iVar1 >> 0x1f)) * -0x1e;
}


// ===== ring30_next @ 2016485c (20 bytes)

/* (idx): *idx + 1, wrapping at 30 [fact] */

int ring30_next(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x1e) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== ring32_next @ 20164870 (24 bytes)

/* (idx + 1) mod 32 [fact] */

short ring32_next(short *param_1)

{
  short sVar1;
  
  sVar1 = *param_1 + 1;
  if (sVar1 == 0x20) {
    sVar1 = 0;
  }
  return sVar1;
}


// ===== __aeabi_dadd @ 20164888 (316 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* Double add: start + span*fraction in progress_scale, + 0.5 (0x3FE00000) rounding in
   touch_cal_apply [inference] */

uint __aeabi_dadd(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    bVar10 = param_3 <= param_1;
    uVar4 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar10 <= param_2 - param_4) {
      bVar11 = CARRY4(param_3,uVar4);
      param_3 = param_3 + uVar4;
      uVar5 = (param_2 - param_4) - (uint)!bVar10 ^ 0x80000000;
      param_4 = param_4 + uVar5 + bVar11;
      bVar10 = param_1 < uVar4;
      param_1 = param_1 - uVar4;
      param_2 = (param_2 - uVar5) - (uint)bVar10;
    }
    uVar5 = param_2 >> 0x14;
    uVar4 = uVar5 - (param_4 >> 0x14);
    if ((param_4 & 0x7ff00000) == 0 || (uVar5 & 0x7ff) == 0x7ff) {
      if ((uVar5 & 0x7ff) != 0x7ff) {
        if ((param_2 & 0x7ff00000) == 0) {
          param_1 = 0;
        }
        return param_1;
      }
      fp_nan_handler();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar3 = -param_3;
    param_2 = param_2 & ~(uVar5 << 0x14);
    iVar7 = -(param_4 & 0xfffff) + -0x100000;
    if (param_3 != 0) {
      iVar7 = -(param_4 & 0xfffff) + -0x100001;
    }
    if (uVar4 < 0x21) {
      uVar1 = uVar3 >> (uVar4 & 0xff);
      uVar2 = param_1 + uVar1;
      param_2 = param_2 + (iVar7 >> (uVar4 & 0xff)) + (uint)CARRY4(param_1,uVar1);
      uVar8 = iVar7 << (0x20 - uVar4 & 0xff);
      uVar1 = uVar2 + uVar8;
      bVar10 = CARRY4(param_2,(uint)CARRY4(uVar2,uVar8));
      iVar7 = param_2 + CARRY4(uVar2,uVar8);
      uVar4 = 0x20 - uVar4;
    }
    else {
      uVar3 = (uint)(param_3 * -2 != 0) | (iVar7 * 2 + (uint)CARRY4(uVar3,uVar3)) * 2;
      uVar4 = uVar4 - 0x20;
      if (0x1d < uVar4) {
        return param_1;
      }
      uVar2 = iVar7 >> (uVar4 & 0xff);
      uVar1 = param_1 + uVar2;
      bVar10 = param_2 != 0 || CARRY4(param_2 - 1,(uint)CARRY4(param_1,uVar2));
      iVar7 = (param_2 - 1) + (uint)CARRY4(param_1,uVar2);
      uVar4 = 0x1e - uVar4;
    }
    if (-1 < iVar7) {
      iVar7 = uVar3 << (uVar4 & 0xff);
      if (-1 < iVar7) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      if (uVar1 != 0 && iVar7 != -0x80000000) {
        return uVar1;
      }
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 & 0xfffffffe;
      }
      return uVar1;
    }
    uVar2 = uVar4 + 1 & 0xff;
    bVar10 = uVar2 == 0 && bVar10 || uVar2 != 0 && (uVar3 << uVar2 - 1 & 0x80000000) != 0;
    uVar8 = uVar1 * 2 + (uint)bVar10;
    uVar4 = iVar7 * 2 + (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)bVar10));
    uVar1 = uVar4 + uVar5 * 0x200000;
    bVar10 = (uVar1 >> 0x14 & 1) != 0;
    if (bVar10 && uVar1 >> 0x15 != 0) {
      uVar4 = -((int)(uVar3 << uVar2) >> 0x1f);
      uVar5 = uVar8 + uVar4;
      bVar10 = uVar5 == 0;
      if (!CARRY4(uVar8,uVar4)) {
        bVar10 = uVar3 << uVar2 == -0x80000000;
      }
      if (!bVar10) {
        return uVar5;
      }
      if (uVar5 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 & 0xfffffffe;
      }
      return uVar5;
    }
    if (!bVar10) {
      if (uVar4 + 0x200000 == 0) {
        iVar7 = uVar8 << LZCOUNT(uVar8);
        if (iVar7 == 0) {
          return uVar8;
        }
        iVar6 = ((uVar5 & 0xfffff7ff) - LZCOUNT(uVar8)) + -0x17;
        uVar8 = iVar7 << 0x15;
      }
      else {
        uVar4 = LZCOUNT(uVar4 + 0x200000) - 0xb;
        iVar6 = ((uVar5 & 0xfffff7ff) - uVar4) + -2;
        uVar8 = uVar8 << (uVar4 & 0xff);
      }
      if (-1 < iVar6) {
        return uVar8;
      }
      return 0;
    }
    uVar3 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar8 >> 1;
    uVar4 = (((int)uVar4 >> 1) + uVar5 * 0x100000) * 2;
    if (uVar4 == 0 && uVar3 == 0) {
      return uVar3;
    }
    if (0x1fffff < uVar4) {
      return uVar3;
    }
    return 0;
  }
  uVar4 = param_1 - param_3;
  iVar7 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar10 = CARRY4(param_3,uVar4);
    param_3 = param_3 + uVar4;
    param_4 = param_4 + iVar7 + (uint)bVar10;
    bVar10 = param_1 < uVar4;
    param_1 = param_1 - uVar4;
    param_2 = (param_2 - iVar7) - (uint)bVar10;
  }
  uVar5 = param_2 >> 0x14;
  uVar4 = uVar5 - (param_4 >> 0x14);
  if ((param_4 & 0x7ff00000) == 0 || (uVar5 & 0x7ff) == 0x7ff) {
    if ((uVar5 & 0x7ff) != 0x7ff) {
      if ((param_2 & 0x7ff00000) == 0) {
        param_1 = 0;
      }
      return param_1;
    }
                    /* Shared NaN/Inf path of the double routines [doc] */
    fp_nan_handler();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar5 << 0x14);
  uVar3 = param_4 & 0x1fffff | 0x100000;
  if (uVar4 < 0x21) {
    uVar8 = param_3 >> (uVar4 & 0xff);
    uVar1 = param_1 + uVar8;
    uVar9 = uVar3 << (0x20 - uVar4 & 0xff);
    uVar2 = uVar1 + uVar9;
    param_2 = param_2 + (uVar3 >> (uVar4 & 0xff)) + (uint)CARRY4(param_1,uVar8) +
              (uint)CARRY4(uVar1,uVar9);
    uVar4 = 0x20 - uVar4;
    if (0xfffff < param_2) {
LAB_20164966:
      bVar12 = (byte)uVar2 & 1;
      uVar3 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar2 >> 1;
      param_2 = (param_2 + 0x100000 >> 1) + uVar5 * 0x100000;
      if ((uVar2 & 1) == 0) {
LAB_20164994:
        if (param_2 * 2 < 0xffe00000) {
          return uVar3;
        }
        uVar4 = fp_exception_stub(uVar3,param_2 + 0xa0000000);
        return uVar4;
      }
      bVar10 = CARRY4(uVar3,(uint)bVar12);
      uVar3 = uVar3 + bVar12;
      uVar5 = uVar3;
      if (!bVar10) {
        uVar5 = param_3 << (uVar4 & 0xff);
      }
      if (uVar5 != 0) goto LAB_20164994;
      goto LAB_2016491c;
    }
    param_2 = param_2 + uVar5 * 0x100000;
  }
  else {
    param_3 = uVar3 * 2 + (uint)(param_3 != 0);
    uVar1 = uVar4 - 0x20;
    uVar4 = 0x1f - uVar1;
    if (uVar1 < 0x20) {
      uVar3 = uVar3 >> (uVar1 & 0xff);
      uVar2 = param_1 + uVar3;
    }
    else {
      uVar4 = 0;
      uVar2 = param_1;
    }
    param_2 = param_2 + uVar5 * 0x100000 + (uint)(uVar1 < 0x20 && CARRY4(param_1,uVar3));
    if (uVar5 != param_2 >> 0x14) {
      param_2 = param_2 + uVar5 * -0x100000;
      goto LAB_20164966;
    }
  }
  iVar7 = param_3 << (uVar4 & 0xff);
  if (-1 < iVar7) {
    return uVar2;
  }
  uVar3 = uVar2 + 1;
  uVar4 = uVar3;
  if (uVar2 != 0xffffffff) {
    uVar4 = iVar7 << 1;
  }
  if (uVar4 != 0) {
    return uVar3;
  }
LAB_2016491c:
  if (uVar3 == 0) {
    param_2 = param_2 + 1;
    uVar3 = 0;
  }
  else {
    uVar3 = uVar3 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return uVar3;
  }
                    /* Empty 12-byte routine the NaN path calls [doc, inference] */
  uVar4 = fp_exception_stub(uVar3,param_2 + 0xa0000000);
  return uVar4;
}


// ===== __aeabi_ddiv @ 201649d8 (538 bytes)

/* Double divide: Z2/Z1 and X/4096.0 (0x40B00000) in tsc2007_pressure, sum/5.0 (0x40140000) in
   touch_cal_fit [inference from the constants] */

uint __aeabi_ddiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint unaff_lr;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  
  if ((~(param_2 >> 4) & 0x7ff0000) == 0 || (~(param_4 >> 4) & 0x7ff0000) == 0) {
                    /* Shared NaN/Inf path of the double routines [doc] */
    uVar14 = fp_nan_handler();
    uVar6 = fp_exception_stub((int)uVar14,
                              *(byte *)((int)((ulonglong)uVar14 >> 0x20) + 0x18) ^ extraout_r3);
    return uVar6;
  }
  uVar7 = param_2 ^ param_4;
  uVar4 = param_2 >> 4 & 0x7ff0000;
  bVar13 = uVar4 == 0;
  uVar6 = uVar7 >> 0x1f;
  if (!bVar13) {
    uVar7 = param_4 >> 4 & 0x7ff0000;
    bVar13 = uVar7 == 0;
  }
  if (!bVar13) {
    iVar5 = (uVar4 | uVar6) - uVar7;
    uVar7 = param_4 << 0xb | 0x80000000;
    uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
    uVar3 = uVar7 | param_3 >> 0x15;
    uVar6 = iVar5 + 0x3fe0000;
    if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
      uVar3 = 0x100000;
      uVar4 = 0;
    }
    else {
      uVar9 = (uint)*(byte *)((uVar7 >> 0x18) + 0x20164b80);
      uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
      iVar10 = (int)((ulonglong)uVar9 * (ulonglong)uVar3);
      iVar8 = -(int)((ulonglong)uVar9 * (ulonglong)uVar3 >> 0x20);
      iVar11 = iVar8 + 0x10000;
      if (iVar10 != 0) {
        iVar11 = iVar8 + 0xffff;
      }
      uVar9 = uVar9 * iVar11 + (int)((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
      lVar1 = (ulonglong)uVar9 * (ulonglong)uVar3 +
              ((ulonglong)uVar9 * (ulonglong)(param_3 * 0x800) >> 0x20);
      iVar10 = (int)lVar1;
      iVar8 = -(int)((ulonglong)lVar1 >> 0x20);
      uVar3 = iVar8 + 0x80000000;
      if (iVar10 != 0) {
        uVar3 = iVar8 + 0x7fffffff;
      }
      uVar2 = (ulonglong)uVar9 * (ulonglong)uVar3 +
              ((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
      uVar9 = (uint)(uVar2 >> 0x20);
      uVar3 = (uint)((ulonglong)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
      uVar12 = (uint)((ulonglong)(param_1 * 0x800) * (ulonglong)uVar9 >> 0x20);
      uVar2 = (ulonglong)uVar4 * (ulonglong)uVar9 +
              (ulonglong)CONCAT14(CARRY4(uVar3,uVar12),uVar3 + uVar12);
      iVar8 = (int)(uVar2 >> 0x20);
      unaff_lr = iVar8 + 0x70000000;
      if (!SCARRY4(iVar8,0x70000000)) {
        uVar6 = iVar5 + 0x3fd0000;
        uVar2 = CONCAT44(iVar8 * 2 + (uint)((uVar2 & 0x80000000) != 0),(int)uVar2 << 1);
      }
      uVar3 = (uint)(uVar2 + 0x80 >> 0x20);
      uVar4 = (uint)(uVar2 + 0x80) >> 8 | uVar3 * 0x1000000;
      uVar3 = uVar3 >> 8;
      if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
        uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
        iVar5 = uVar3 * uVar9 +
                uVar4 * (uVar7 >> 0xb) + (int)((ulonglong)uVar4 * (ulonglong)uVar9 >> 0x20);
        if (-1 < (int)unaff_lr) {
          iVar5 = iVar5 + param_1 * -0x100000;
        }
        unaff_lr = iVar5 + param_1 * -0x100000 +
                   (uVar7 >> 0xc) +
                   (uint)CARRY4((uint)((ulonglong)uVar4 * (ulonglong)uVar9),
                                uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f);
        if ((int)unaff_lr < 0) {
          bVar13 = 0xfffffffe < uVar4;
          uVar4 = uVar4 + 1;
          uVar3 = uVar3 + bVar13;
        }
      }
    }
    iVar5 = uVar3 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
    if (0x7f00000 < (uVar6 & 0xfffffffe)) {
      if (-1 < (int)uVar6) {
        unaff_lr = iVar5 + 0x100000;
      }
      if (-1 >= (int)uVar6 || (int)(unaff_lr ^ uVar6 << 0x1f) < 0) {
        if ((int)uVar6 < 0) {
          return 0;
        }
                    /* Empty 12-byte routine the NaN path calls [doc, inference] */
        uVar6 = fp_exception_stub(uVar4,iVar5 + -0x60000000);
        return uVar6;
      }
      return uVar4;
    }
    return uVar4;
  }
  if ((param_2 & 0x7ff00000) != 0) {
    uVar6 = fp_exception_stub(param_1,param_2 ^ param_4);
    return uVar6;
  }
  if ((param_4 & 0x7ff00000) == 0) {
    return 0;
  }
  return 0;
}


// ===== __aeabi_d2iz @ 20164c90 (92 bytes)

/* Double to signed int, truncating with saturation (0x7FFFFFFF ^ sign) [fact for the code]; follows
   "+ 0.5" in touch_cal_apply [inference] */

uint __aeabi_d2iz(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  iVar1 = ((param_2 & 0x7fffffff) >> 0x14) - 0x400;
  bVar5 = SBORROW4(0x1e,iVar1);
  uVar2 = -iVar1 + 0x1e;
  bVar4 = uVar2 == 0;
  uVar3 = uVar2;
  if (!bVar4 && iVar1 < 0x1f) {
    bVar5 = SBORROW4(0x21,uVar2);
    uVar3 = 0x21 - uVar2;
    bVar4 = uVar2 == 0x21;
  }
  if (!bVar4 && (int)uVar3 < 0 == bVar5) {
    return ((param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff) ^ (int)param_2 >> 0x1f
           ) - ((int)param_2 >> 0x1f);
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar1 != -0x3ff) {
    return (int)param_2 >> 0x20 ^ 0x7fffffff;
  }
                    /* Shared NaN/Inf path of the double routines [doc] */
  fp_nan_handler(param_1);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== __aeabi_d2uiz @ 20164cf0 (88 bytes)

/* Double to unsigned int: negative gives 0, overflow 0xFFFFFFFF [fact for the code];
   tsc2007_pressure result [inference] */

uint __aeabi_d2uiz(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  uint uVar3;
  bool bVar4;
  
  iVar1 = (param_2 >> 0x14) - 0x400;
  bVar4 = SBORROW4(0x1e,iVar1);
  uVar2 = -iVar1 + 0x1e;
  uVar3 = uVar2;
  if (iVar1 < 0x1f) {
    bVar4 = SBORROW4(0x20,uVar2);
    uVar3 = 0x20 - uVar2;
  }
  if ((int)uVar3 < 0 == bVar4) {
    return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
  }
  if ((int)param_2 < 0) {
    return 0;
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar1 != -0x3ff) {
    return 0xffffffff;
  }
                    /* Shared NaN/Inf path of the double routines [doc] */
  fp_nan_handler(param_1);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== __aeabi_i2d @ 20164d54 (46 bytes)

/* int -> IEEE double (sign, exponent 0x41D - clz, mantissa) [fact] */

undefined8 __aeabi_i2d(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}


// ===== __aeabi_ui2d @ 20164d82 (38 bytes)

/* unsigned int -> IEEE double [fact] */

undefined8 __aeabi_ui2d(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44((0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}


// ===== __aeabi_dmul @ 20164da8 (300 bytes)

/* Double multiply: 400.0 (0x40790000) * x in tsc2007_pressure, span * fraction in progress_scale, x
   * 100.0 in sd_format_request [inference] */

longlong __aeabi_dmul(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint extraout_r3;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  undefined8 uVar16;
  longlong lVar17;
  
  uVar12 = param_2 >> 4 & 0x7ff0000;
  bVar15 = uVar12 == 0;
  if (!bVar15) {
    unaff_r5 = param_4 >> 4 & 0x7ff0000;
    bVar15 = unaff_r5 == 0;
  }
  if (!bVar15) {
    bVar15 = uVar12 == 0x7ff0000;
  }
  if (!bVar15) {
    bVar15 = unaff_r5 == 0x7ff0000;
  }
  if (!bVar15) {
    uVar5 = param_2 & 0x1fffff | 0x100000;
    uVar7 = param_4 & 0x1fffff | 0x100000;
    iVar13 = (uVar12 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
    lVar17 = (ulonglong)uVar5 * (ulonglong)param_3;
    uVar10 = (uint)((ulonglong)lVar17 >> 0x20);
    lVar1 = (ulonglong)param_1 * (ulonglong)uVar7;
    uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
    iVar14 = iVar13 + -0x3fc0000;
    lVar3 = lVar17 + lVar1;
    uVar9 = (uint)((ulonglong)lVar3 >> 0x20);
    lVar2 = (ulonglong)uVar5 * (ulonglong)uVar7;
    uVar12 = (uint)lVar2;
    uVar11 = (uint)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    lVar4 = lVar3 + CONCAT44(uVar12,uVar11);
    uVar7 = (uint)lVar4;
    uVar5 = (uint)((ulonglong)lVar4 >> 0x20);
    uVar12 = (int)((ulonglong)lVar2 >> 0x20) +
             (uint)(CARRY4(uVar8,uVar10) ||
                   CARRY4(uVar8 + uVar10,(uint)CARRY4((uint)lVar1,(uint)lVar17))) +
             (uint)(CARRY4(uVar9,uVar12) || CARRY4(uVar9 + uVar12,(uint)CARRY4((uint)lVar3,uVar11)))
    ;
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar7 = uVar7 | 1;
    }
    if ((uVar12 & 0x200) == 0) {
      uVar9 = uVar7 << 0xc;
      uVar8 = uVar12 * 0x1000 | uVar5 >> 0x14;
      uVar12 = uVar5 << 0xc | uVar7 >> 0x14;
      iVar6 = -4;
    }
    else {
      uVar9 = uVar7 << 0xb;
      uVar8 = uVar12 * 0x800 | uVar5 >> 0x15;
      uVar12 = uVar5 << 0xb | uVar7 >> 0x15;
      iVar6 = -3;
    }
    uVar7 = iVar6 + (iVar14 >> 0x10);
    uVar5 = uVar8 + uVar7 * 0x100000 ^ iVar13 * -0x80000000;
    if (uVar9 != 0) {
      bVar15 = (uVar9 & 0x80000000) != 0;
      if ((uVar9 & 0x7fffffff) != 0) {
        uVar9 = 0;
      }
      uVar5 = uVar5 + CARRY4(uVar12,(uint)bVar15);
      uVar12 = uVar12 + bVar15 & ~(uVar9 >> 0x1f);
    }
    if (0x7fd < uVar7) {
      if (iVar14 < 0x4000000) {
        return (ulonglong)(uVar5 + 0x60000000 & 0x80000000) << 0x20;
      }
      return (ulonglong)((uint)((int)(uVar5 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
    }
    return CONCAT44(uVar5,uVar12);
  }
  if (uVar12 == 0x7ff0000 || (param_4 >> 4 & 0x7ff0000) == 0x7ff0000) {
                    /* Shared NaN/Inf path of the double routines [doc] */
    uVar16 = fp_nan_handler();
                    /* Empty 12-byte routine the NaN path calls [doc, inference] */
    lVar17 = fp_exception_stub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20) << 2 ^ extraout_r3);
    return lVar17;
  }
  return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
}


// ===== fp_nan_handler @ 20164efc (152 bytes)

/* Shared NaN/Inf path of the double routines: picks the result by a 3-bit code table after the
   caller's return address [fact for the code]; armcc fplib internal [inference] */

int fp_nan_handler(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int unaff_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + (1 - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_20164f68_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_20164f68_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x20164f66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}


// ===== fp_exception_stub @ 20164f98 (12 bytes)

/* Empty 12-byte routine the NaN path calls (fplib exception hook, no handler installed) [inference]
    */

void fp_exception_stub(void)

{
  return;
}


// ===== __aeabi_dsub @ 20164fa4 (464 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* Double subtract: Z2/Z1 - 1.0 (0x3FF00000) in tsc2007_pressure [inference] */

ulonglong __aeabi_dsub(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  ulonglong uVar14;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    bVar11 = param_3 <= param_1;
    uVar7 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar7);
      param_3 = param_3 + uVar7;
      uVar8 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar8 + bVar12;
      bVar11 = param_1 < uVar7;
      param_1 = param_1 - uVar7;
      param_2 = (param_2 - uVar8) - (uint)bVar11;
    }
    uVar8 = param_2 >> 0x14;
    uVar7 = uVar8 - (param_4 >> 0x14);
    if ((param_4 & 0x7ff00000) == 0 || (uVar8 & 0x7ff) == 0x7ff) {
      if ((uVar8 & 0x7ff) != 0x7ff) {
        if ((param_2 & 0x7ff00000) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
                    /* Shared NaN/Inf path of the double routines [doc] */
      fp_nan_handler();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar5 = -param_3;
    uVar2 = param_2 & ~(uVar8 << 0x14);
    iVar6 = -(param_4 & 0xfffff) + -0x100000;
    if (param_3 != 0) {
      iVar6 = -(param_4 & 0xfffff) + -0x100001;
    }
    if (uVar7 < 0x21) {
      uVar9 = uVar5 >> (uVar7 & 0xff);
      uVar1 = param_1 + uVar9;
      uVar2 = uVar2 + (iVar6 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar9);
      uVar10 = iVar6 << (0x20 - uVar7 & 0xff);
      uVar9 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar2,(uint)CARRY4(uVar1,uVar10));
      iVar6 = uVar2 + CARRY4(uVar1,uVar10);
      uVar7 = 0x20 - uVar7;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar6 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar7 = uVar7 - 0x20;
      if (0x1d < uVar7) {
        return CONCAT44(uVar2 + uVar8 * 0x100000,param_1);
      }
      uVar1 = iVar6 >> (uVar7 & 0xff);
      uVar9 = param_1 + uVar1;
      bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1,(uint)CARRY4(param_1,uVar1));
      iVar6 = (uVar2 - 1) + (uint)CARRY4(param_1,uVar1);
      uVar7 = 0x1e - uVar7;
    }
    if (-1 < iVar6) {
      iVar4 = uVar5 << (uVar7 & 0xff);
      iVar6 = iVar6 + uVar8 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar6,uVar9);
      }
      uVar9 = uVar9 + 1;
      if (uVar9 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar6,uVar9);
      }
      if (uVar9 == 0) {
        iVar6 = iVar6 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar9);
    }
    uVar2 = uVar7 + 1 & 0xff;
    bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
    uVar1 = uVar9 * 2 + (uint)bVar11;
    uVar7 = iVar6 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11));
    uVar9 = uVar7 + uVar8 * 0x200000;
    bVar11 = (uVar9 >> 0x14 & 1) != 0;
    if (bVar11 && uVar9 >> 0x15 != 0) {
      uVar9 = -((int)(uVar5 << uVar2) >> 0x1f);
      uVar10 = uVar1 + uVar9;
      bVar11 = uVar10 == 0;
      iVar6 = uVar7 + uVar8 * 0x100000;
      if (!CARRY4(uVar1,uVar9)) {
        bVar11 = uVar5 << uVar2 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar6,uVar10);
      }
      if (uVar10 == 0) {
        iVar6 = iVar6 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar10);
    }
    if (!bVar11) {
      iVar6 = uVar7 + 0x200000;
      if (iVar6 == 0) {
        uVar7 = uVar1 << LZCOUNT(uVar1);
        if (uVar7 == 0) {
          return (ulonglong)uVar1;
        }
        iVar4 = ((uVar8 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
        iVar6 = uVar7 << 0x15;
        uVar7 = uVar7 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar6) - 0xb;
        iVar4 = ((uVar8 & 0xfffff7ff) - uVar5) + -2;
        uVar7 = iVar6 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
        iVar6 = uVar1 << (uVar5 & 0xff);
      }
      iVar3 = uVar7 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar6);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar8 = ((int)uVar7 >> 1) + uVar8 * 0x100000;
    uVar7 = (uint)((uVar7 & 1) != 0) << 0x1f | uVar1 >> 1;
    if (uVar8 * 2 == 0 && uVar7 == 0) {
      return (ulonglong)uVar7;
    }
    if (0x1fffff < uVar8 * 2) {
      return CONCAT44(uVar8,uVar7);
    }
    return (ulonglong)(uVar8 & 0x80000000) << 0x20;
  }
  param_4 = param_4 ^ 0x80000000;
  uVar7 = param_1 - param_3;
  iVar6 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar7);
    param_3 = param_3 + uVar7;
    param_4 = param_4 + iVar6 + (uint)bVar11;
    bVar11 = param_1 < uVar7;
    param_1 = param_1 - uVar7;
    param_2 = (param_2 - iVar6) - (uint)bVar11;
  }
  uVar8 = param_2 >> 0x14;
  uVar7 = uVar8 - (param_4 >> 0x14);
  if ((param_4 & 0x7ff00000) == 0 || (uVar8 & 0x7ff) == 0x7ff) {
    if ((uVar8 & 0x7ff) != 0x7ff) {
      if ((param_2 & 0x7ff00000) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    fp_nan_handler();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar8 << 0x14);
  uVar5 = param_4 & 0x1fffff | 0x100000;
  if (uVar7 < 0x21) {
    uVar1 = param_3 >> (uVar7 & 0xff);
    uVar2 = param_1 + uVar1;
    uVar10 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar9 = uVar2 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar1) +
              (uint)CARRY4(uVar2,uVar10);
    uVar7 = 0x20 - uVar7;
    if (0xfffff < param_2) {
LAB_20164966:
      bVar13 = (byte)uVar9 & 1;
      uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar9 >> 1;
      param_2 = (param_2 + 0x100000 >> 1) + uVar8 * 0x100000;
      if ((uVar9 & 1) == 0) {
LAB_20164994:
        if (param_2 * 2 < 0xffe00000) {
          return CONCAT44(param_2,uVar5);
        }
        uVar14 = fp_exception_stub(uVar5,param_2 + 0xa0000000);
        return uVar14;
      }
      bVar11 = CARRY4(uVar5,(uint)bVar13);
      uVar5 = uVar5 + bVar13;
      uVar8 = uVar5;
      if (!bVar11) {
        uVar8 = param_3 << (uVar7 & 0xff);
      }
      if (uVar8 != 0) goto LAB_20164994;
      goto LAB_2016491c;
    }
    param_2 = param_2 + uVar8 * 0x100000;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar2 = uVar7 - 0x20;
    uVar7 = 0x1f - uVar2;
    if (uVar2 < 0x20) {
      uVar5 = uVar5 >> (uVar2 & 0xff);
      uVar9 = param_1 + uVar5;
    }
    else {
      uVar7 = 0;
      uVar9 = param_1;
    }
    param_2 = param_2 + uVar8 * 0x100000 + (uint)(uVar2 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar8 != param_2 >> 0x14) {
      param_2 = param_2 + uVar8 * -0x100000;
      goto LAB_20164966;
    }
  }
  iVar6 = param_3 << (uVar7 & 0xff);
  if (-1 < iVar6) {
    return CONCAT44(param_2,uVar9);
  }
  uVar5 = uVar9 + 1;
  uVar7 = uVar5;
  if (uVar9 != 0xffffffff) {
    uVar7 = iVar6 << 1;
  }
  if (uVar7 != 0) {
    return CONCAT44(param_2,uVar5);
  }
LAB_2016491c:
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
  uVar14 = fp_exception_stub(uVar5,param_2 + 0xa0000000);
  return uVar14;
}

