// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff90885 @ fff90885 (25 bytes)

undefined1 FUN_fff90885(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fff9085e(&DAT_0001ffc4 + param_1 * 4);
  return uVar1;
}


// ===== FUN_fff9089e @ fff9089e (273 bytes)

uint FUN_fff9089e(int param_1)

{
  char cStack_12;
  byte bStack_11;
  uint local_10;
  char cStack_9;
  int local_4;
  
  local_10 = 0;
  local_4 = param_1;
  if (param_1 == 1) {
    cStack_9 = FUN_fff9086c(0x73);
  }
  else if (param_1 == 0) {
    cStack_9 = FUN_fff9086c(0x72);
  }
  else {
    local_10 = 3;
  }
  if (local_10 == 0) {
    if (cStack_9 == '\x01') {
      *(undefined4 *)(&DAT_00020310 + local_4 * 4) = 1;
      FUN_fff90f9b(local_4,2,(char *)0x10000000);
      FUN_fff90f9b(local_4,5,(char *)0x10000000);
      cStack_12 = '\x01';
      FUN_fff90f9b(local_4,3,&cStack_12);
      (&DAT_00001432)[local_4] = 1;
      for (bStack_11 = 0; bStack_11 < 9; bStack_11 = bStack_11 + 1) {
        *(undefined4 *)(&DAT_00020318 + (uint)bStack_11 * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)bStack_11 * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)bStack_11 * 0xc + 0x20320) = 0x10000000;
      }
      (&DAT_0000142e)[local_4] = 0;
      (&DAT_00001430)[local_4] = 0;
      (&DAT_0000142c)[local_4] = 0;
      FUN_fff90f9b(local_4,1,(char *)0x10000000);
    }
    else {
      local_10 = 1;
    }
  }
  return local_10;
}


// ===== FUN_fff909af @ fff909af (231 bytes)

void FUN_fff909af(int param_1)

{
  byte bStack_11;
  
  if (param_1 < 2) {
    FUN_fff90f9b(param_1,2,(char *)0x10000000);
    FUN_fff90f9b(param_1,5,(char *)0x10000000);
    for (bStack_11 = 0; bStack_11 < 9; bStack_11 = bStack_11 + 1) {
      *(undefined4 *)(&DAT_00020318 + (uint)bStack_11 * 0xc + param_1 * 0x6c) = 0;
      *(undefined1 **)(param_1 * 0x6c + (uint)bStack_11 * 0xc + 0x2031c) = &LAB_fff910bc;
      *(undefined4 *)(param_1 * 0x6c + (uint)bStack_11 * 0xc + 0x20320) = 0x10000000;
    }
    (&DAT_0000142e)[param_1] = 0;
    (&DAT_00001430)[param_1] = 0;
    (&DAT_0000142c)[param_1] = 0;
    (&DAT_00001432)[param_1] = 0;
    if (param_1 == 1) {
      FUN_fff90885(0x73);
    }
    else if (param_1 == 0) {
      FUN_fff90885(0x72);
    }
  }
  return;
}


// ===== FUN_fff90a96 @ fff90a96 (272 bytes)

void FUN_fff90a96(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if (param_1 < 2) {
    uStack_1c = 0;
    iStack_10 = param_1;
    uStack_c = param_2;
    iStack_8 = param_3;
    uStack_4 = param_4;
    iVar2 = FUN_fff91059(param_1);
    if (iVar2 == 1) {
      if ((iStack_8 == 0x10000000) || (iStack_8 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_18 = 6;
      }
      else if ((byte)(&DAT_0000142c)[iStack_10] < 8) {
        if ((byte)(&DAT_0000142e)[iStack_10] < 8) {
          (&DAT_0000142e)[iStack_10] = (&DAT_0000142e)[iStack_10] + '\x01';
        }
        else {
          (&DAT_0000142e)[iStack_10] = 0;
        }
        (&DAT_0000142c)[iStack_10] = (&DAT_0000142c)[iStack_10] + '\x01';
        *(undefined4 *)
         (&DAT_00020318 + (uint)(byte)(&DAT_0000142e)[iStack_10] * 0xc + iStack_10 * 0x6c) = 1;
        *(int *)(iStack_10 * 0x6c + (uint)(byte)(&DAT_0000142e)[iStack_10] * 0xc + 0x2031c) =
             iStack_8;
        *(undefined4 *)(iStack_10 * 0x6c + (uint)(byte)(&DAT_0000142e)[iStack_10] * 0xc + 0x20320) =
             uStack_4;
        uStack_18 = 0;
      }
      else {
        uStack_18 = 9;
      }
      FUN_fff91087(iStack_10,&uStack_1c);
      FUN_fff90f9b(iStack_10,4,(char *)0x10000000);
    }
  }
  return;
}


// ===== FUN_fff90ba6 @ fff90ba6 (144 bytes)

void FUN_fff90ba6(int param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_00087303;
    *param_2 = bVar1 & 0xf;
    bVar1 = DAT_00087203;
    param_2[1] = bVar1 >> 2 & 1;
    bVar1 = DAT_0008701a;
    param_2[2] = bVar1 & 1;
    param_2[3] = bRam00001433;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_00087303;
  *param_2 = bVar1 & 0xf;
  bVar1 = DAT_00087203;
  param_2[1] = bVar1 >> 3 & 1;
  bVar1 = DAT_0008701b;
  param_2[2] = bVar1 & 1;
  param_2[3] = DAT_00001432;
  return;
}


// ===== FUN_fff90c36 @ fff90c36 (32 bytes)

void FUN_fff90c36(int param_1)

{
  if (param_1 == 1) {
    FUN_fff8ff82(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  FUN_fff8ff82(0x1b);
  return;
}


// ===== FUN_fff90c56 @ fff90c56 (32 bytes)

void FUN_fff90c56(int param_1)

{
  if (param_1 == 1) {
    FUN_fff8ffa3(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  FUN_fff8ffa3(0x1b);
  return;
}


// ===== FUN_fff90c76 @ fff90c76 (171 bytes)

uint FUN_fff90c76(int param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_1c [7];
  byte bStack_15;
  byte *local_14;
  uint local_10;
  byte *local_8;
  int local_4;
  
  if (*param_2 < 0x10) {
    local_14 = param_2;
    local_8 = param_2;
    local_4 = param_1;
    R_BSP_InterruptControl(0x5e,6,auStack_1c);
    if (local_4 == 1) {
      bVar1 = DAT_00087203;
      bStack_15 = bVar1 >> 2 & 1;
      FUN_fff8ffa3(0x1a);
      bVar1 = DAT_00087303;
      DAT_00087303 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        FUN_fff8ff82(0x1a);
      }
    }
    else if (local_4 == 0) {
      bVar1 = DAT_00087203;
      bStack_15 = bVar1 >> 3 & 1;
      FUN_fff8ffa3(0x1b);
      bVar1 = DAT_00087303;
      DAT_00087303 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        FUN_fff8ff82(0x1b);
      }
    }
    R_BSP_InterruptControl(0x5e,5,auStack_1c);
    local_10 = 0;
  }
  else {
    local_10 = 4;
  }
  return local_10;
}


// ===== FUN_fff90d21 @ fff90d21 (33 bytes)

void FUN_fff90d21(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_000872e1;
    DAT_000872e1 = bVar1 | 1;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_000872e0;
  DAT_000872e0 = bVar1 | 1;
  return;
}


// ===== FUN_fff90d42 @ fff90d42 (33 bytes)

void FUN_fff90d42(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_0008701a;
    DAT_0008701a = bVar1 & 0xfe;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_0008701b;
  DAT_0008701b = bVar1 & 0xfe;
  return;
}


// ===== FUN_fff90d63 @ fff90d63 (17 bytes)

void FUN_fff90d63(int param_1)

{
  (&DAT_00001432)[param_1] = 1;
  return;
}


// ===== FUN_fff90d74 @ fff90d74 (17 bytes)

void FUN_fff90d74(int param_1)

{
  (&DAT_00001432)[param_1] = 0;
  return;
}


// ===== FUN_fff90d85 @ fff90d85 (183 bytes)

uint FUN_fff90d85(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 local_18;
  byte *pbStack_14;
  uint uStack_10;
  byte *local_8;
  int local_4;
  
  local_18 = 0;
  local_8 = param_2;
  local_4 = param_1;
  iVar1 = FUN_fff91059(param_1,&local_18);
  if (iVar1 == 1) {
    pbStack_14 = local_8;
    if (*local_8 < 9) {
      if (*(int *)(&DAT_00020318 + (uint)*local_8 * 0xc + local_4 * 0x6c) == 2) {
        uStack_10 = 8;
      }
      else {
        *(undefined4 *)(&DAT_00020318 + (uint)*local_8 * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)*local_8 * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)*local_8 * 0xc + 0x20320) = 0x10000000;
        uStack_10 = 0;
      }
    }
    else {
      uStack_10 = 7;
    }
    FUN_fff91087(local_4,&local_18);
    FUN_fff90f9b(local_4,4,(char *)0x10000000);
  }
  else {
    uStack_10 = 10;
  }
  return uStack_10;
}


// ===== FUN_fff90e3c @ fff90e3c (244 bytes)

uint FUN_fff90e3c(int param_1)

{
  int iVar1;
  undefined4 local_14;
  byte bStack_d;
  uint uStack_c;
  int local_4;
  
  local_14 = 0;
  local_4 = param_1;
  iVar1 = FUN_fff91059(param_1,&local_14);
  if (iVar1 == 1) {
    uStack_c = 0;
    for (bStack_d = 0; bStack_d < 9; bStack_d = bStack_d + 1) {
      if (*(int *)(&DAT_00020318 + (uint)bStack_d * 0xc + local_4 * 0x6c) == 2) {
        uStack_c = 8;
        break;
      }
    }
    if (uStack_c == 0) {
      for (bStack_d = 0; bStack_d < 9; bStack_d = bStack_d + 1) {
        *(undefined4 *)(&DAT_00020318 + (uint)bStack_d * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)bStack_d * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)bStack_d * 0xc + 0x20320) = 0x10000000;
      }
      (&DAT_0000142e)[local_4] = 0;
      (&DAT_00001430)[local_4] = 0;
      (&DAT_0000142c)[local_4] = 0;
      FUN_fff91087(local_4,&local_14);
    }
    else {
      FUN_fff91087(local_4,&local_14);
      FUN_fff90f9b(local_4,4,(char *)0x10000000);
    }
  }
  else {
    uStack_c = 10;
  }
  return uStack_c;
}


// ===== FUN_fff90f30 @ fff90f30 (107 bytes)

void FUN_fff90f30(int param_1,undefined4 *param_2)

{
  undefined4 *local_10;
  byte local_9;
  
  local_10 = param_2;
  for (local_9 = 0; local_9 < 9; local_9 = local_9 + 1) {
    *local_10 = *(undefined4 *)(&DAT_00020318 + (uint)local_9 * 0xc + param_1 * 0x6c);
    local_10[1] = *(undefined4 *)(param_1 * 0x6c + (uint)local_9 * 0xc + 0x2031c);
    local_10[2] = *(undefined4 *)(param_1 * 0x6c + (uint)local_9 * 0xc + 0x20320);
    local_10 = local_10 + 3;
  }
  return;
}


// ===== FUN_fff90f9b @ fff90f9b (190 bytes)

uint FUN_fff90f9b(int param_1,uint param_2,char *param_3)

{
  uint local_14;
  
  if (param_1 < 2) {
    local_14 = 0;
    switch(param_2) {
    case 0:
      FUN_fff90ba6(param_1,param_3);
      break;
    case 1:
      FUN_fff90c36(param_1);
      break;
    case 2:
      FUN_fff90c56(param_1);
      break;
    case 3:
      local_14 = FUN_fff90c76(param_1,(byte *)param_3);
      break;
    case 4:
      FUN_fff90d21(param_1);
      break;
    case 5:
      FUN_fff90d42(param_1);
      break;
    case 6:
      FUN_fff90d63(param_1);
      break;
    case 7:
      FUN_fff90d74(param_1);
      break;
    case 8:
      local_14 = FUN_fff90d85(param_1,(byte *)param_3);
      break;
    case 9:
      local_14 = FUN_fff90e3c(param_1);
      break;
    case 10:
      FUN_fff90f30(param_1,param_3);
      break;
    case 0xb:
      *param_3 = (&DAT_0000142c)[param_1];
      break;
    case 0xc:
      *param_3 = '\b' - (&DAT_0000142c)[param_1];
      break;
    default:
      local_14 = 5;
    }
  }
  else {
    local_14 = 3;
  }
  return local_14;
}


// ===== FUN_fff91059 @ fff91059 (46 bytes)

bool FUN_fff91059(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_2 = *(int *)(&DAT_00020310 + param_1 * 4);
  *(int *)(&DAT_00020310 + param_1 * 4) = iVar1;
  return *param_2 == 1;
}


// ===== FUN_fff91087 @ fff91087 (53 bytes)

bool FUN_fff91087(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = *(undefined4 *)(&DAT_00020310 + param_1 * 4);
  *(undefined4 *)(&DAT_00020310 + param_1 * 4) = uVar1;
  return *(int *)(&DAT_00020310 + param_1 * 4) == 1;
}


// ===== FUN_fff910c3 @ fff910c3 (327 bytes)

void FUN_fff910c3(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = param_1;
  iVar2 = FUN_fff91059(param_1,&local_8);
  if (iVar2 == 1) {
    FUN_fff91087(local_4,&local_8);
    if ((&DAT_00001432)[local_4] == '\x01') {
      FUN_fff8fd84();
    }
    local_8 = 0;
    FUN_fff91059(local_4,&local_8);
    while( true ) {
      if ((&DAT_0000142c)[local_4] == '\0') break;
      if ((byte)(&DAT_00001430)[local_4] < 8) {
        (&DAT_00001430)[local_4] = (&DAT_00001430)[local_4] + '\x01';
      }
      else {
        (&DAT_00001430)[local_4] = 0;
      }
      if (*(int *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) == 1
         ) {
        *(undefined4 *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c)
             = 2;
        FUN_fff91087(local_4,&local_8);
        iVar2 = (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c;
        pcVar1 = *(code **)(&DAT_00020318 + iVar2 + 4);
        (*pcVar1)(*(undefined4 *)(&DAT_00020318 + iVar2 + 8),pcVar1);
        local_8 = 0;
        FUN_fff91059(local_4,&local_8);
        if (*(int *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) ==
            2) {
          *(undefined4 *)
           (&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) = 3;
        }
      }
      if ((&DAT_0000142c)[local_4] != '\0') {
        (&DAT_0000142c)[local_4] = (&DAT_0000142c)[local_4] + -1;
      }
    }
    FUN_fff91087(local_4,&local_8);
    return;
  }
  return;
}


// ===== vec027_ICU_SWINT @ fff9120a (15 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91213) */
/* WARNING: Removing unreachable block (ram,0xfff9120a) */
/* WARNING: Removing unreachable block (ram,0xfff9120c) */
/* WARNING: Removing unreachable block (ram,0xfff91215) */

undefined4 vec027_ICU_SWINT(undefined4 param_1)

{
  FUN_fff910c3(0);
  return param_1;
}


// ===== vec026_ICU_SWINT2 @ fff91219 (15 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91222) */
/* WARNING: Removing unreachable block (ram,0xfff91219) */
/* WARNING: Removing unreachable block (ram,0xfff9121b) */
/* WARNING: Removing unreachable block (ram,0xfff91224) */

undefined4 vec026_ICU_SWINT2(undefined4 param_1)

{
  FUN_fff910c3(1);
  return param_1;
}


// ===== FUN_fff91228 @ fff91228 (32 bytes)

undefined4 FUN_fff91228(undefined4 param_1)

{
  uint in_PSW;
  
  if ((in_PSW & 0x100000) != 0) {
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff91248 @ fff91248 (4 bytes)

void FUN_fff91248(void)

{
  return;
}


// ===== get_bpsw @ fff9124c (19 bytes)

/* CC-RX intrinsic: return BPSW in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_bpsw(void)

{
  uint in_BPSW;
  
  return in_BPSW;
}


// ===== FUN_fff9125f @ fff9125f (4 bytes)

void FUN_fff9125f(void)

{
  return;
}


// ===== get_bpc @ fff91263 (19 bytes)

/* CC-RX intrinsic: return BPC in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_bpc(void)

{
  uint in_BPC;
  
  return in_BPC;
}


// ===== FUN_fff91276 @ fff91276 (4 bytes)

void FUN_fff91276(void)

{
  return;
}


// ===== get_extb @ fff9127a (19 bytes)

/* CC-RX intrinsic: return EXTB in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_extb(void)

{
  uint in_EXTB;
  
  return in_EXTB;
}


// ===== FUN_fff9128d @ fff9128d (4 bytes)

void FUN_fff9128d(void)

{
  return;
}


// ===== FUN_fff91291 @ fff91291 (4 bytes)

void FUN_fff91291(void)

{
  return;
}


// ===== get_acc_hi @ fff91295 (19 bytes)

/* CC-RX intrinsic: return ACC bits 63..32 (MVFACHI #0,A0) in R1 (SUB #8,SP; save via [SP]; RTSD
   #8); no callers [inference for the name] */

uint get_acc_hi(void)

{
  undefined8 in_ACC;
  
  return (uint)((ulonglong)in_ACC >> 0x20);
}


// ===== get_acc_mi @ fff912a8 (19 bytes)

/* CC-RX intrinsic: return ACC bits 47..16 (MVFACMI #0,A0) in R1 (SUB #8,SP; save via [SP]; RTSD
   #8); no callers [inference for the name] */

uint get_acc_mi(void)

{
  undefined8 in_ACC;
  
  return (uint)((ulonglong)in_ACC >> 0x10);
}


// ===== FUN_fff912bb @ fff912bb (4 bytes)

void FUN_fff912bb(byte *param_1,byte param_2)

{
  *param_1 = *param_1 | '\x01' << (param_2 & 7);
  return;
}


// ===== FUN_fff912bf @ fff912bf (4 bytes)

void FUN_fff912bf(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & ~('\x01' << (param_2 & 7));
  return;
}


// ===== FUN_fff912c3 @ fff912c3 (4 bytes)

void FUN_fff912c3(byte *param_1,byte param_2)

{
  *param_1 = *param_1 ^ '\x01' << (param_2 & 7);
  return;
}


// ===== sbrk @ fff912c7 (60 bytes)

/* lowsrc sbrk(size): advances the heap pointer at 0x25D34 if the new end is <= 0x207F4; only caller
   heap_getmem [inference for the name] */

void sbrk(int param_1)

{
  if ((undefined4 *)(param_1 + iRam00025d34) <= &DAT_000207f4) {
    iRam00025d34 = iRam00025d34 + param_1;
  }
  return;
}


// ===== FUN_fff91303 @ fff91303 (212 bytes)

uint FUN_fff91303(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  uint local_1c [5];
  undefined *local_8;
  
  local_1c[0] = 16000000;
  local_1c[1] = 18000000;
  local_1c[2] = 20000000;
  uVar1 = DAT_00080026;
  bVar3 = (byte)(uVar1 >> 8) & 7;
  if (bVar3 == 4) {
    sVar2 = DAT_00080028;
    local_1c[4] = ((uint)(int)sVar2 >> 8 & 0x3f) * 10 + 10 >> 1;
    local_1c[3] = 24000000;
    sVar2 = DAT_00080028;
    if (((uint)(int)sVar2 >> 4 & 1) == 1) {
      bVar3 = DAT_00080037;
      local_1c[3] = local_1c[bVar3 & 3];
    }
    uVar1 = DAT_00080028;
    uVar4 = (uVar1 & 3) * 10 + 10;
    if (uVar4 != 0) {
      local_1c[3] = local_1c[3] / uVar4;
    }
    local_8 = (undefined *)(local_1c[3] * local_1c[4]);
  }
  else if (bVar3 == 1) {
    bVar3 = DAT_00080037;
    local_8 = (undefined *)local_1c[bVar3 & 3];
  }
  else if (bVar3 == 2) {
    local_8 = (undefined *)0x16e3600;
  }
  else if (bVar3 == 3) {
    local_8 = (undefined *)0x8000;
  }
  else if ((uVar1 & 0x700) == 0) {
    local_8 = &DAT_0003a980;
  }
  else {
    local_8 = (undefined *)0x16e3600;
  }
  uVar4 = DAT_00080020;
  return (uint)local_8 >> ((uVar4 & 0xfffffff) >> 0x18);
}


// ===== hw_init_clock @ fff913d7 (4 bytes)

/* Called first from PowerON_Reset; writes SYSTEM regs (PRCR 0x803FE=0xA50B ...) [inference:
   clock/system setup] */

void hw_init_clock(void)

{
  FUN_fff913db();
  return;
}


// ===== FUN_fff913db @ fff913db (186 bytes)

byte FUN_fff913db(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  DAT_000803fe = 0xa50b;
  FUN_fff91495();
  DAT_00080020 = 0x21c21222;
  uVar1 = DAT_00080020;
  DAT_00080024 = 0x11;
  uVar2 = DAT_00080024;
  DAT_00080026 = 0x400;
  uVar2 = DAT_00080026;
  DAT_00080034 = 1;
  bVar3 = FUN_fff8fc57(0x19,&DAT_000f4240);
  DAT_000803fe = 0xa500;
  return bVar3;
}


// ===== FUN_fff91495 @ fff91495 (371 bytes)

void FUN_fff91495(void)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte local_1;
  
  bVar3 = DAT_0008c293;
  DAT_0008c293 = bVar3 & 0xfe;
  bVar3 = DAT_0008c293;
  DAT_0008c293 = bVar3 & 0xbf;
  bVar3 = DAT_00080036;
  if ((bVar3 & 1) == 1) {
    DAT_0008c294 = 1;
  }
  else {
    do {
      bVar3 = DAT_0008003c;
    } while ((bVar3 & 8) == 0);
  }
  bVar3 = DAT_0008c293;
  DAT_0008c293 = bVar3 & 0xcf;
  DAT_000800a2 = 0x53;
  DAT_00080032 = 0;
  uVar2 = DAT_00080032;
  do {
    bVar3 = DAT_0008003c;
  } while ((bVar3 & 1) == 0);
  bVar3 = DAT_0008c291;
  if ((bVar3 & 1) == 0) {
    bVar3 = DAT_0008c428;
    DAT_0008c428 = bVar3 & 0xfe;
    for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
      uVar2 = DAT_0008c428;
    }
    uVar2 = DAT_0008c428;
    bVar3 = DAT_0008c426;
    DAT_0008c426 = bVar3 & 0xfe;
    for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
      uVar2 = DAT_0008c426;
    }
    uVar2 = DAT_0008c426;
    DAT_00080033 = 1;
    uVar2 = DAT_00080033;
    do {
      bVar3 = DAT_0008003c;
    } while ((bVar3 & 2) != 0);
  }
  else {
    DAT_00080033 = 1;
    uVar2 = DAT_00080033;
    do {
      bVar3 = DAT_0008003c;
    } while ((bVar3 & 2) != 0);
  }
  uVar1 = DAT_00080028;
  DAT_00080028 = uVar1 & 0xfffc;
  uVar1 = DAT_00080028;
  DAT_00080028 = uVar1 & 0xffef;
  uVar1 = DAT_00080028;
  DAT_00080028 = uVar1 & 0xd3ff | 0x1300;
  DAT_0008002a = 0;
  do {
    bVar3 = DAT_0008003c;
  } while ((bVar3 & 4) == 0);
  DAT_0008101c = 2;
  cVar4 = DAT_0008101c;
  if (cVar4 != '\x02') {
    return;
  }
  return;
}


// ===== FUN_fff91608 @ fff91608 (164 bytes)

void FUN_fff91608(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = DAT_0008c000;
  DAT_0008c000 = bVar1 | 0x50;
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 3;
  uVar2 = DAT_0008c002;
  DAT_0008c002 = uVar2;
  uVar2 = DAT_0008c003;
  DAT_0008c003 = uVar2;
  uVar2 = DAT_0008c004;
  DAT_0008c004 = uVar2;
  bVar1 = DAT_0008c005;
  DAT_0008c005 = bVar1 | 0x80;
  uVar2 = DAT_0008c006;
  DAT_0008c006 = uVar2;
  uVar2 = DAT_0008c007;
  DAT_0008c007 = uVar2;
  bVar1 = DAT_0008c008;
  DAT_0008c008 = bVar1 | 0x30;
  bVar1 = DAT_0008c009;
  DAT_0008c009 = bVar1 | 0xf0;
  uVar2 = DAT_0008c00a;
  DAT_0008c00a = uVar2;
  uVar2 = DAT_0008c00b;
  DAT_0008c00b = uVar2;
  uVar2 = DAT_0008c00c;
  DAT_0008c00c = uVar2;
  uVar2 = DAT_0008c00d;
  DAT_0008c00d = uVar2;
  uVar2 = DAT_0008c00e;
  DAT_0008c00e = uVar2;
  bVar1 = DAT_0008c00f;
  DAT_0008c00f = bVar1 | 0xdf;
  uVar2 = DAT_0008c010;
  DAT_0008c010 = 0xff;
  bVar1 = DAT_0008c012;
  DAT_0008c012 = bVar1 | 0xd7;
  return;
}


// ===== FUN_fff916ac @ fff916ac (158 bytes)

uint FUN_fff916ac(int param_1,char param_2)

{
  byte bVar1;
  uint local_14;
  
  local_14 = 0;
  if (param_1 == 2) {
    if (param_2 == '\x01') {
      bVar1 = DAT_00087581;
      DAT_00087581 = bVar1 | 1;
    }
    else {
      local_14 = 3;
    }
  }
  else if (param_1 != 3) {
    if (param_1 == 0xb) {
      if (param_2 == '\x01') {
        bVar1 = DAT_00087010;
        DAT_00087010 = bVar1 & 0xfe;
        bVar1 = DAT_00087300;
        DAT_00087300 = bVar1 | 0xf;
        FUN_fff8ff82(0x10);
        bVar1 = DAT_00081304;
        DAT_00081304 = bVar1 | 1;
        bVar1 = DAT_00081304;
        DAT_00081304 = bVar1 | 2;
      }
      else {
        FUN_fff8ffa3(0x10);
        bVar1 = DAT_00081304;
        DAT_00081304 = bVar1 & 0xfe;
        bVar1 = DAT_00081304;
        DAT_00081304 = bVar1 & 0xfd;
      }
    }
    else {
      local_14 = 3;
    }
  }
  return local_14;
}


// ===== vec110_GROUPBL0 @ fff9174a (884 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91ab2) */
/* WARNING: Removing unreachable block (ram,0xfff91aba) */
/* WARNING: Removing unreachable block (ram,0xfff91ab8) */
/* WARNING: Removing unreachable block (ram,0xfff9174a) */
/* WARNING: Removing unreachable block (ram,0xfff9174c) */
/* WARNING: Removing unreachable block (ram,0xfff91ab4) */

undefined4 vec110_GROUPBL0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1e < 0) {
    R_BSP_InterruptControl(0x15,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1f < 0) {
    R_BSP_InterruptControl(0x14,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1c < 0) {
    R_BSP_InterruptControl(0x17,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1d < 0) {
    R_BSP_InterruptControl(0x16,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1a < 0) {
    R_BSP_InterruptControl(0x19,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x18,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x18 < 0) {
    R_BSP_InterruptControl(0x1b,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x19 < 0) {
    R_BSP_InterruptControl(0x1a,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x1d,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x1c,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x1f,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x1e,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x21,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x20,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x10 < 0) {
    R_BSP_InterruptControl(0x23,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x11 < 0) {
    R_BSP_InterruptControl(0x22,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xe < 0) {
    R_BSP_InterruptControl(0x25,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x24,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xd < 0) {
    R_BSP_InterruptControl(0x26,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xc < 0) {
    R_BSP_InterruptControl(0x27,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x28,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x29,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 7 < 0) {
    R_BSP_InterruptControl(0x2a,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 5 < 0) {
    R_BSP_InterruptControl(0x2b,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 4 < 0) {
    R_BSP_InterruptControl(0x2c,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 3 < 0) {
    R_BSP_InterruptControl(0x2d,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 2 < 0) {
    R_BSP_InterruptControl(0x2e,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 < 0) {
    R_BSP_InterruptControl(0x30,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 1 < 0) {
    R_BSP_InterruptControl(0x2f,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec111_GROUPBL1 @ fff91abe (736 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91d92) */
/* WARNING: Removing unreachable block (ram,0xfff91d9a) */
/* WARNING: Removing unreachable block (ram,0xfff91d98) */
/* WARNING: Removing unreachable block (ram,0xfff91abe) */
/* WARNING: Removing unreachable block (ram,0xfff91ac0) */
/* WARNING: Removing unreachable block (ram,0xfff91d94) */

undefined4 vec111_GROUPBL1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00087634;
  if (iVar1 << 0x1c < 0) {
    R_BSP_InterruptControl(0x32,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x33,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x1a < 0) {
    R_BSP_InterruptControl(0x34,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x19 < 0) {
    R_BSP_InterruptControl(0x35,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x18 < 0) {
    R_BSP_InterruptControl(0x36,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x37,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x38,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x39,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x3a,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x3b,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x11 < 0) {
    R_BSP_InterruptControl(0x3d,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x3c,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x3f,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x10 < 0) {
    R_BSP_InterruptControl(0x3e,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x40,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x41,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 9 < 0) {
    R_BSP_InterruptControl(0x42,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 8 < 0) {
    R_BSP_InterruptControl(0x43,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 6 < 0) {
    R_BSP_InterruptControl(0x45,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 7 < 0) {
    R_BSP_InterruptControl(0x44,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 4 < 0) {
    R_BSP_InterruptControl(0x47,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 5 < 0) {
    R_BSP_InterruptControl(0x46,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 2 < 0) {
    R_BSP_InterruptControl(0x49,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 3 < 0) {
    R_BSP_InterruptControl(0x48,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec107_GROUPBL2 @ fff91d9e (46 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91dc0) */
/* WARNING: Removing unreachable block (ram,0xfff91dc8) */
/* WARNING: Removing unreachable block (ram,0xfff91dc6) */
/* WARNING: Removing unreachable block (ram,0xfff91d9e) */
/* WARNING: Removing unreachable block (ram,0xfff91da0) */
/* WARNING: Removing unreachable block (ram,0xfff91dc2) */

undefined4 vec107_GROUPBL2(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00087638;
  if (iVar1 << 0x1f < 0) {
    R_BSP_InterruptControl(0x4b,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec112_GROUPAL0 @ fff91dcc (316 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91efc) */
/* WARNING: Removing unreachable block (ram,0xfff91f04) */
/* WARNING: Removing unreachable block (ram,0xfff91f02) */
/* WARNING: Removing unreachable block (ram,0xfff91dcc) */
/* WARNING: Removing unreachable block (ram,0xfff91dce) */
/* WARNING: Removing unreachable block (ram,0xfff91efe) */

undefined4 vec112_GROUPAL0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00087830;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x4e,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x4d,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x50,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x4f,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xe < 0) {
    R_BSP_InterruptControl(0x52,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x51,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xc < 0) {
    R_BSP_InterruptControl(0x54,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xd < 0) {
    R_BSP_InterruptControl(0x53,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x56,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x55,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec113_GROUPAL1 @ fff91f08 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91fa2) */
/* WARNING: Removing unreachable block (ram,0xfff91faa) */
/* WARNING: Removing unreachable block (ram,0xfff91fa8) */
/* WARNING: Removing unreachable block (ram,0xfff91f08) */
/* WARNING: Removing unreachable block (ram,0xfff91f0a) */
/* WARNING: Removing unreachable block (ram,0xfff91fa4) */

undefined4 vec113_GROUPAL1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00087834;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x58,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x5a,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x5b,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x59,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x5c,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec106_GROUPBE0 @ fff91fae (102 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92008) */
/* WARNING: Removing unreachable block (ram,0xfff92010) */
/* WARNING: Removing unreachable block (ram,0xfff9200e) */
/* WARNING: Removing unreachable block (ram,0xfff91fae) */
/* WARNING: Removing unreachable block (ram,0xfff91fb0) */
/* WARNING: Removing unreachable block (ram,0xfff9200a) */

undefined4 vec106_GROUPBE0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00087600;
  if (iVar1 << 0x1f < 0) {
    uVar2 = DAT_00087680;
    DAT_00087680 = uVar2 | 1;
    R_BSP_InterruptControl(0x11,0,(void *)0x10000000);
  }
  iVar1 = DAT_00087600;
  if (iVar1 << 0x1e < 0) {
    uVar2 = DAT_00087680;
    DAT_00087680 = uVar2 | 2;
    R_BSP_InterruptControl(0x12,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== icu_select_init @ fff92014 (1121 bytes)

/* Writes ICU SLIBXR128.. selectable interrupt sources (130<-0x0F TPU0, 138<-0x18 TPU2, 142<-0x1C
   TPU3, 144<-0x14 TPU1, 186<-0x40 S12ADI0, 189<-0x44 S12ADI1) */

void icu_select_init(void)

{
  DAT_00087780 = 1;
  DAT_00087781 = 2;
  DAT_00087792 = 3;
  DAT_00087793 = 4;
  DAT_00087794 = 5;
  DAT_00087795 = 6;
  DAT_00087796 = 7;
  DAT_00087797 = 8;
  DAT_00087798 = 9;
  DAT_00087799 = 10;
  DAT_0008779a = 0xb;
  DAT_0008779b = 0xc;
  DAT_0008779c = 0xd;
  DAT_0008779d = 0xe;
  DAT_00087782 = 0xf;
  DAT_00087783 = 0x10;
  DAT_00087784 = 0x11;
  DAT_00087785 = 0x12;
  DAT_00087786 = 0x13;
  DAT_00087790 = 0x14;
  DAT_00087787 = 0x15;
  DAT_00087788 = 0x16;
  DAT_00087789 = 0x17;
  DAT_0008778a = 0x18;
  DAT_0008778b = 0x19;
  DAT_0008778c = 0x1a;
  DAT_0008778d = 0x1b;
  DAT_0008778e = 0x1c;
  DAT_0008778f = 0x1d;
  DAT_00087791 = 0x1e;
  DAT_0008779e = 0x1f;
  DAT_0008779f = 0x20;
  DAT_000877a0 = 0x21;
  DAT_000877a1 = 0x22;
  DAT_000877a2 = 0x23;
  DAT_000877a3 = 0x24;
  DAT_000877a4 = 0x25;
  DAT_000877a5 = 0x26;
  DAT_000877a6 = 0x27;
  DAT_000877a7 = 0x28;
  DAT_000877a8 = 0x29;
  DAT_000877a9 = 0x2a;
  DAT_000877aa = 0x2b;
  DAT_000877ab = 0x2c;
  DAT_000877ac = 0x2d;
  DAT_000877ad = 0x2e;
  DAT_000877ae = 0x2f;
  DAT_000877af = 0x30;
  DAT_000877b0 = 0x31;
  DAT_000877b1 = 0x32;
  DAT_000877b2 = 0x33;
  DAT_000877b3 = 0x34;
  DAT_000877b4 = 0x35;
  DAT_000877b5 = 0x36;
  DAT_000877b6 = 0x37;
  DAT_000877b7 = 0x38;
  DAT_000877b8 = 0x39;
  DAT_000877b9 = 0x3e;
  DAT_000877ba = 0x40;
  DAT_000877bb = 0x41;
  DAT_000877bc = 0x42;
  DAT_000877bd = 0x44;
  DAT_000877be = 0x45;
  DAT_000877bf = 0x46;
  DAT_000877c0 = 0x4c;
  DAT_000877c1 = 0x4f;
  DAT_000877c2 = 0x50;
  DAT_000877c3 = 0x55;
  DAT_000877c4 = 0x56;
  DAT_000877c5 = 0x57;
  DAT_000877c6 = 0x58;
  DAT_000877c7 = 0x59;
  DAT_000877c8 = 0x5a;
  DAT_000877c9 = 0x5b;
  DAT_000877ca = 0x5c;
  DAT_000877cb = 0x5d;
  DAT_000877cc = 0x5e;
  DAT_000877cd = 0x5f;
  DAT_000879d1 = 1;
  DAT_000879d2 = 2;
  DAT_000879d3 = 3;
  DAT_000879d4 = 4;
  DAT_000879d5 = 5;
  DAT_000879d6 = 6;
  DAT_000879d7 = 7;
  DAT_000879d0 = 8;
  DAT_000879d8 = 9;
  DAT_000879d9 = 10;
  DAT_000879da = 0xb;
  DAT_000879db = 0xc;
  DAT_000879dc = 0xd;
  DAT_000879dd = 0xe;
  DAT_000879de = 0xf;
  DAT_000879df = 0x10;
  DAT_000879e0 = 0x11;
  DAT_000879e1 = 0x12;
  DAT_000879e2 = 0x13;
  DAT_000879e3 = 0x14;
  DAT_000879e4 = 0x15;
  DAT_000879e5 = 0x16;
  DAT_000879e6 = 0x17;
  DAT_000879e7 = 0x18;
  DAT_000879e8 = 0x19;
  DAT_000879e9 = 0x1b;
  DAT_000879ea = 0x1c;
  DAT_000879eb = 0x1d;
  DAT_000879ec = 0x1e;
  DAT_000879ed = 0x1f;
  DAT_000879ee = 0x20;
  DAT_000879ef = 0x21;
  DAT_000879f0 = 0x22;
  DAT_000879f1 = 0x23;
  DAT_000879f2 = 0x24;
  DAT_000879f3 = 0x25;
  DAT_000879f4 = 0x26;
  DAT_000879f5 = 0x27;
  DAT_000879f6 = 0x29;
  DAT_000879f7 = 0x2a;
  DAT_000879f8 = 0x2b;
  DAT_000879f9 = 0x2c;
  DAT_000879fa = 0x2d;
  DAT_000879fb = 0x58;
  DAT_000879fc = 0x59;
  return;
}


// ===== FUN_fff92475 @ fff92475 (820 bytes)

void FUN_fff92475(void)

{
  byte bVar1;
  
  FUN_fff8fec0(3);
  DAT_0008c161 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0xfd;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0xfd;
  DAT_0008c162 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0xfb;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0xfb;
  DAT_0008c163 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0xf7;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0xf7;
  DAT_0008c165 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0xdf;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0xdf;
  DAT_0008c166 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0xbf;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0xbf;
  DAT_0008c167 = 0x80;
  bVar1 = DAT_0008c064;
  DAT_0008c064 = bVar1 & 0x7f;
  bVar1 = DAT_0008c004;
  DAT_0008c004 = bVar1 & 0x7f;
  DAT_0008c1a8 = 0x80;
  bVar1 = DAT_0008c06d;
  DAT_0008c06d = bVar1 & 0xfe;
  bVar1 = DAT_0008c00d;
  DAT_0008c00d = bVar1 & 0xfe;
  DAT_0008c1a9 = 0x80;
  bVar1 = DAT_0008c06d;
  DAT_0008c06d = bVar1 & 0xfd;
  bVar1 = DAT_0008c00d;
  DAT_0008c00d = bVar1 & 0xfd;
  DAT_0008c189 = 0x80;
  bVar1 = DAT_0008c069;
  DAT_0008c069 = bVar1 & 0xfd;
  bVar1 = DAT_0008c009;
  DAT_0008c009 = bVar1 & 0xfd;
  DAT_0008c18b = 0x80;
  bVar1 = DAT_0008c069;
  DAT_0008c069 = bVar1 & 0xf7;
  bVar1 = DAT_0008c009;
  DAT_0008c009 = bVar1 & 0xf7;
  DAT_0008c143 = 0x80;
  bVar1 = DAT_0008c060;
  DAT_0008c060 = bVar1 & 0xf7;
  bVar1 = DAT_0008c000;
  DAT_0008c000 = bVar1 & 0xf7;
  DAT_0008c157 = 1;
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 | 0x80;
  DAT_0008c15b = 0xb;
  bVar1 = DAT_0008c063;
  DAT_0008c063 = bVar1 | 8;
  DAT_0008c158 = 10;
  bVar1 = DAT_0008c063;
  DAT_0008c063 = bVar1 | 1;
  DAT_0008c14a = 10;
  bVar1 = DAT_0008c061;
  DAT_0008c061 = bVar1 | 4;
  DAT_0008c155 = 10;
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 | 0x20;
  DAT_0008c198 = 10;
  bVar1 = DAT_0008c06b;
  DAT_0008c06b = bVar1 | 1;
  DAT_0008c1a2 = 10;
  bVar1 = DAT_0008c06c;
  DAT_0008c06c = bVar1 | 4;
  DAT_0008c18a = 10;
  bVar1 = DAT_0008c069;
  DAT_0008c069 = bVar1 | 4;
  DAT_0008c141 = 10;
  bVar1 = DAT_0008c060;
  DAT_0008c060 = bVar1 | 2;
  DAT_0008c140 = 10;
  bVar1 = DAT_0008c060;
  DAT_0008c060 = bVar1 | 1;
  bVar1 = DAT_0008c023;
  DAT_0008c023 = bVar1 | 4;
  DAT_0008c15a = 0xb;
  bVar1 = DAT_0008c003;
  DAT_0008c003 = bVar1 | 4;
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 | 0x40;
  DAT_0008c156 = 10;
  bVar1 = DAT_0008c002;
  DAT_0008c002 = bVar1 | 0x40;
  bVar1 = DAT_0008c021;
  DAT_0008c021 = bVar1 | 8;
  DAT_0008c14b = 10;
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 8;
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 | 8;
  DAT_0008c153 = 10;
  bVar1 = DAT_0008c002;
  DAT_0008c002 = bVar1 | 8;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 2;
  DAT_0008c199 = 10;
  bVar1 = DAT_0008c00b;
  DAT_0008c00b = bVar1 | 2;
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 | 8;
  DAT_0008c1a3 = 10;
  bVar1 = DAT_0008c00c;
  DAT_0008c00c = bVar1 | 8;
  bVar1 = DAT_0008c029;
  DAT_0008c029 = bVar1 | 1;
  DAT_0008c188 = 10;
  bVar1 = DAT_0008c009;
  DAT_0008c009 = bVar1 | 1;
  FUN_fff8fe3c(3);
  return;
}

