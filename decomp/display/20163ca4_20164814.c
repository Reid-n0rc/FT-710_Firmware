// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20163ca4 @ 20163ca4 (160 bytes)

void FUN_20163ca4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_5 != 0) {
    do {
      uVar3 = (uint)param_5[1];
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + iVar2 * 2 + (uint)*param_5 * iVar1 * 2) != 0) {
            FUN_20163b9c(param_1,iVar1,param_3,param_4,param_5,uVar3 - iVar1,iVar2);
            break;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163d44 @ 20163d44 (40 bytes)

void FUN_20163d44(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x40);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x88) = param_1;
  return;
}


// ===== FUN_20163d6c @ 20163d6c (264 bytes)

void FUN_20163d6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}


// ===== FUN_20163e74 @ 20163e74 (160 bytes)

void FUN_20163e74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_5 != 0) {
    do {
      uVar3 = (uint)param_5[1];
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + iVar2 * 2 + (uint)*param_5 * iVar1 * 2) != 0) {
            FUN_20163d6c(param_1,iVar1,param_3,param_4,param_5,uVar3 - iVar1,iVar2);
            break;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163f14 @ 20163f14 (48 bytes)

void FUN_20163f14(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x1c20);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x3848) = param_1;
  return;
}


// ===== FUN_20163f44 @ 20163f44 (52 bytes)

void FUN_20163f44(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  FUN_20134124(*(undefined1 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x97c),
               *(undefined4 *)(param_1 + 0x10));
  return;
}


// ===== FUN_20163f80 @ 20163f80 (88 bytes)

void FUN_20163f80(undefined1 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 *param_5)

{
  *(short *)(param_1 + 8) = (short)param_3;
  FUN_201638d8(param_1 + 0x14,0);
  FUN_201638cc(param_1 + 0x14,param_3,*param_5);
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined2 **)(param_1 + 0x10) = param_5;
  *param_1 = param_2;
  return;
}


// ===== FUN_20163fd0 @ 20163fd0 (72 bytes)

undefined1 * FUN_20163fd0(undefined1 *param_1,undefined1 *param_2)

{
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  FUN_20163900(param_1 + 0x14,param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  return param_1;
}


// ===== FUN_20164018 @ 20164018 (52 bytes)

void FUN_20164018(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  uVar1 = FUN_20163b48(param_1 + 0x14);
  FUN_20134124(*(undefined1 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 0xc),uVar1,*(undefined4 *)(param_1 + 0x10));
  return;
}


// ===== FUN_20164054 @ 20164054 (88 bytes)

void FUN_20164054(undefined1 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 *param_5)

{
  *(short *)(param_1 + 8) = (short)param_3;
  FUN_20163b18(param_1 + 0x14,0);
  FUN_20163b0c(param_1 + 0x14,param_3,*param_5);
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined2 **)(param_1 + 0x10) = param_5;
  *param_1 = param_2;
  return;
}


// ===== FUN_201640a4 @ 201640a4 (72 bytes)

undefined1 * FUN_201640a4(undefined1 *param_1,undefined1 *param_2)

{
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  FUN_20163b54(param_1 + 0x14,param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  return param_1;
}


// ===== copy10 @ 201640ec (24 bytes)

/* (dst, src): memcpy of 10 bytes, returns dst; firmware-object version fields
   (fwfile_check_versions, fwobj_*) [fact] */

undefined4 copy10(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,10);
  return param_1;
}


// ===== copy32 @ 20164104 (24 bytes)

/* (dst, src): memcpy of 0x20 bytes, returns dst; firmware-object name fields [fact] */

undefined4 copy32(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,0x20);
  return param_1;
}


// ===== copy48 @ 2016411c (24 bytes)

/* (dst, src): memcpy of 0x30 bytes, returns dst; fwobj_base_ctor [fact] */

undefined4 copy48(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,0x30);
  return param_1;
}


// ===== FUN_20164298 @ 20164298 (156 bytes)

void FUN_20164298(int param_1,int param_2,ushort *param_3,ushort *param_4)

{
  ushort uVar1;
  
  uVar1 = *param_3;
  if (uVar1 < 4) {
    *param_4 = 0;
    param_4[1] = 0;
    return;
  }
  if (param_3[1] == 0) {
    *param_4 = uVar1;
    uVar1 = param_3[1];
  }
  else {
    uVar1 = *(short *)(*(int *)(param_1 + 0x3c) + param_2 * 0x62e + (uint)uVar1 * 2 + -8) + 399;
    *param_4 = uVar1;
    uVar1 = (*(short *)(*(int *)(param_1 + 0x3c) + param_2 * 0x62e +
                       ((uint)param_3[1] + (uint)*param_3) * 2 + -10) - uVar1) + 400;
  }
  param_4[1] = uVar1;
  return;
}


// ===== scope3d_widths_init @ 20164334 (44 bytes)

/* (table, ...): fills the 3DSS line width table 0x317 - 10*i (gui.md: line i is 791 - 10i wide)
   [fact] */

void scope3d_widths_init(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = 0x317;
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(short *)(param_1 + iVar1) = sVar3;
    sVar3 = sVar3 + -10;
  } while (iVar2 < 0x1e);
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  return;
}


// ===== ring100_advance @ 20164360 (28 bytes)

/* (idx): returns *idx and advances it with ring100_next; affft_wf_add_row [fact] */

undefined4 ring100_advance(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = ring100_next();
  *param_1 = uVar1;
  return uVar2;
}


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
  uint uVar1;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  uVar1 = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x44) = uVar1;
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
  uint uVar1;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  uVar1 = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x84) = uVar1;
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
  mutex_guard_dtor(&uStack_10);
  return uVar2;
}


// ===== FUN_201644e4 @ 201644e4 (60 bytes)

void FUN_201644e4(int param_1)

{
  uint uVar1;
  t_cmtx local_18;
  
  local_18.mtxatr = 2;
  local_18.ceilpri = 0;
  local_18.name = (char *)0x0;
  uVar1 = itron_acre_mtx(0,&local_18);
  *(uint *)(param_1 + 0x84) = uVar1;
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
  int iVar1;
  
  FUN_20133e18(param_3 + 399,param_4 + 4,*(int *)(param_1 + 0x3c) + param_2 * 0x62e,0x317);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
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

