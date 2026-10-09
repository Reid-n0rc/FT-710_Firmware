// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff90d85 @ fff90d85 (183 bytes)

void FUN_fff90d85(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 local_18;
  byte *pbStack_14;
  undefined4 uStack_10;
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
    FUN_fff90f9b(local_4,4,0x10000000);
  }
  return;
}


// ===== FUN_fff90e3c @ fff90e3c (244 bytes)

void FUN_fff90e3c(int param_1)

{
  int iVar1;
  undefined4 local_14;
  byte bStack_d;
  int iStack_c;
  int local_4;
  
  local_14 = 0;
  local_4 = param_1;
  iVar1 = FUN_fff91059(param_1,&local_14);
  if (iVar1 == 1) {
    iStack_c = 0;
    for (bStack_d = 0; bStack_d < 9; bStack_d = bStack_d + 1) {
      if (*(int *)(&DAT_00020318 + (uint)bStack_d * 0xc + local_4 * 0x6c) == 2) {
        iStack_c = 8;
        break;
      }
    }
    if (iStack_c == 0) {
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
      FUN_fff90f9b(local_4,4,0x10000000);
    }
  }
  return;
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

void FUN_fff90f9b(int param_1,undefined4 param_2,char *param_3)

{
  if (param_1 < 2) {
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
      FUN_fff90c76(param_1,param_3);
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
      FUN_fff90d85(param_1,param_3);
      break;
    case 9:
      FUN_fff90e3c(param_1);
      break;
    case 10:
      FUN_fff90f30(param_1,param_3);
      break;
    case 0xb:
      *param_3 = (&DAT_0000142c)[param_1];
      break;
    case 0xc:
      *param_3 = '\b' - (&DAT_0000142c)[param_1];
    }
  }
  return;
}


// ===== FUN_fff91059 @ fff91059 (46 bytes)

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_fff91059(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}


// ===== FUN_fff91087 @ fff91087 (53 bytes)

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_fff91087(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}


// ===== FUN_fff910c3 @ fff910c3 (327 bytes)

void FUN_fff910c3(int param_1)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 local_8;
  int local_4;
  
  local_8 = 0;
  uStack_c = 0xfff910d1;
  local_4 = param_1;
  iVar1 = FUN_fff91059(param_1,&local_8);
  if (iVar1 == 1) {
    uStack_c = 0xfff910dd;
    FUN_fff91087(local_4,&local_8);
    if ((&DAT_00001432)[local_4] == '\x01') {
      uStack_c = 0xfff910ef;
      FUN_fff8fd84();
    }
    local_8 = 0;
    uStack_c = 0xfff910f9;
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
        uStack_c = 0xfff9116b;
        FUN_fff91087(local_4,&local_8);
        uStack_c = 0;
        FUN_fff91059(local_8,&uStack_c);
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
    uStack_c = 0xfff91206;
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


// ===== FUN_fff91303 @ fff91303 (212 bytes)

void FUN_fff91303(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined1 uVar4;
  byte bVar5;
  
  uVar2 = DAT_00080026;
  bVar5 = (byte)((ushort)uVar2 >> 8) & 7;
  if (bVar5 == 4) {
    uVar2 = DAT_00080028;
    sVar3 = DAT_00080028;
    if (((uint)(int)sVar3 >> 4 & 1) == 1) {
      uVar4 = DAT_00080037;
    }
    uVar2 = DAT_00080028;
  }
  else if (bVar5 == 1) {
    uVar4 = DAT_00080037;
  }
  uVar1 = DAT_00080020;
  return;
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

void FUN_fff913db(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  DAT_000803fe = 0xa50b;
  FUN_fff91495();
  DAT_00080020 = 0x21c21222;
  uVar1 = DAT_00080020;
  DAT_00080024 = 0x11;
  uVar2 = DAT_00080024;
  DAT_00080026 = 0x400;
  uVar2 = DAT_00080026;
  DAT_00080034 = 1;
  FUN_fff8fc57(0x19,&DAT_000f4240);
  DAT_000803fe = 0xa500;
  return;
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

void FUN_fff916ac(int param_1,char param_2)

{
  byte bVar1;
  
  if (param_1 == 2) {
    if (param_2 == '\x01') {
      bVar1 = DAT_00087581;
      DAT_00087581 = bVar1 | 1;
    }
  }
  else if ((param_1 != 3) && (param_1 == 0xb)) {
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
  return;
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
    FUN_fff90097(0x15,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1f < 0) {
    FUN_fff90097(0x14,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1c < 0) {
    FUN_fff90097(0x17,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1d < 0) {
    FUN_fff90097(0x16,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1a < 0) {
    FUN_fff90097(0x19,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x1b < 0) {
    FUN_fff90097(0x18,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x18 < 0) {
    FUN_fff90097(0x1b,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x19 < 0) {
    FUN_fff90097(0x1a,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x16 < 0) {
    FUN_fff90097(0x1d,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x17 < 0) {
    FUN_fff90097(0x1c,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x14 < 0) {
    FUN_fff90097(0x1f,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x15 < 0) {
    FUN_fff90097(0x1e,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x12 < 0) {
    FUN_fff90097(0x21,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x13 < 0) {
    FUN_fff90097(0x20,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x10 < 0) {
    FUN_fff90097(0x23,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0x11 < 0) {
    FUN_fff90097(0x22,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xe < 0) {
    FUN_fff90097(0x25,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xf < 0) {
    FUN_fff90097(0x24,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xd < 0) {
    FUN_fff90097(0x26,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xc < 0) {
    FUN_fff90097(0x27,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 0xb < 0) {
    FUN_fff90097(0x28,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 10 < 0) {
    FUN_fff90097(0x29,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 7 < 0) {
    FUN_fff90097(0x2a,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 5 < 0) {
    FUN_fff90097(0x2b,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 4 < 0) {
    FUN_fff90097(0x2c,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 3 < 0) {
    FUN_fff90097(0x2d,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 2 < 0) {
    FUN_fff90097(0x2e,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 < 0) {
    FUN_fff90097(0x30,0,0x10000000);
  }
  iVar1 = DAT_00087630;
  if (iVar1 << 1 < 0) {
    FUN_fff90097(0x2f,0,0x10000000);
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
    FUN_fff90097(0x32,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x1b < 0) {
    FUN_fff90097(0x33,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x1a < 0) {
    FUN_fff90097(0x34,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x19 < 0) {
    FUN_fff90097(0x35,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x18 < 0) {
    FUN_fff90097(0x36,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x17 < 0) {
    FUN_fff90097(0x37,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x16 < 0) {
    FUN_fff90097(0x38,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x15 < 0) {
    FUN_fff90097(0x39,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x14 < 0) {
    FUN_fff90097(0x3a,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x13 < 0) {
    FUN_fff90097(0x3b,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x11 < 0) {
    FUN_fff90097(0x3d,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x12 < 0) {
    FUN_fff90097(0x3c,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0xf < 0) {
    FUN_fff90097(0x3f,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0x10 < 0) {
    FUN_fff90097(0x3e,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 0xb < 0) {
    FUN_fff90097(0x40,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 10 < 0) {
    FUN_fff90097(0x41,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 9 < 0) {
    FUN_fff90097(0x42,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 8 < 0) {
    FUN_fff90097(0x43,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 6 < 0) {
    FUN_fff90097(0x45,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 7 < 0) {
    FUN_fff90097(0x44,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 4 < 0) {
    FUN_fff90097(0x47,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 5 < 0) {
    FUN_fff90097(0x46,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 2 < 0) {
    FUN_fff90097(0x49,0,0x10000000);
  }
  iVar1 = DAT_00087634;
  if (iVar1 << 3 < 0) {
    FUN_fff90097(0x48,0,0x10000000);
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
    FUN_fff90097(0x4b,0,0x10000000);
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
    FUN_fff90097(0x4e,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x17 < 0) {
    FUN_fff90097(0x4d,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x12 < 0) {
    FUN_fff90097(0x50,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0x13 < 0) {
    FUN_fff90097(0x4f,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xe < 0) {
    FUN_fff90097(0x52,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xf < 0) {
    FUN_fff90097(0x51,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xc < 0) {
    FUN_fff90097(0x54,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xd < 0) {
    FUN_fff90097(0x53,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 10 < 0) {
    FUN_fff90097(0x56,0,0x10000000);
  }
  iVar1 = DAT_00087830;
  if (iVar1 << 0xb < 0) {
    FUN_fff90097(0x55,0,0x10000000);
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
    FUN_fff90097(0x58,0,0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x16 < 0) {
    FUN_fff90097(0x5a,0,0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x15 < 0) {
    FUN_fff90097(0x5b,0,0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x17 < 0) {
    FUN_fff90097(0x59,0,0x10000000);
  }
  iVar1 = DAT_00087834;
  if (iVar1 << 0x14 < 0) {
    FUN_fff90097(0x5c,0,0x10000000);
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
    FUN_fff90097(0x11,0,0x10000000);
  }
  iVar1 = DAT_00087600;
  if (iVar1 << 0x1e < 0) {
    uVar2 = DAT_00087680;
    DAT_00087680 = uVar2 | 2;
    FUN_fff90097(0x12,0,0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff92014 @ fff92014 (1121 bytes)

void FUN_fff92014(void)

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


// ===== FUN_fff927a9 @ fff927a9 (37 bytes)

void FUN_fff927a9(void)

{
  byte bVar1;
  
  DAT_00088032 = 0x3350;
  DAT_00088036 = 0;
  DAT_00088038 = 0x80;
  bVar1 = DAT_00087581;
  DAT_00087581 = bVar1 | 8;
  FUN_fff927df();
  return;
}


// ===== FUN_fff927ce @ fff927ce (17 bytes)

void FUN_fff927ce(void)

{
  DAT_00088030 = 0;
  DAT_00088030 = 0xff;
  return;
}


// ===== FUN_fff927df @ fff927df (1 bytes)

void FUN_fff927df(void)

{
  return;
}


// ===== FUN_fff927e5 @ fff927e5 (65 bytes)

void FUN_fff927e5(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfff7ffff;
  DAT_00088045 = 0;
  DAT_00088046 = 0;
  bVar2 = DAT_0008c060;
  DAT_0008c060 = bVar2 & 0xf7;
  bVar2 = DAT_0008c000;
  DAT_0008c000 = bVar2 & 0xf7;
  bVar2 = DAT_0008c143;
  DAT_0008c143 = bVar2 | 0x80;
  FUN_fff92850();
  return;
}


// ===== FUN_fff92826 @ fff92826 (15 bytes)

void FUN_fff92826(void)

{
  byte bVar1;
  
  bVar1 = DAT_00088044;
  DAT_00088044 = bVar1 & 0xdf;
  bVar1 = DAT_00088044;
  DAT_00088044 = bVar1 | 0x40;
  return;
}


// ===== FUN_fff9283d @ fff9283d (19 bytes)

void FUN_fff9283d(ushort param_1)

{
  DAT_00088040 = param_1 & 0xfff;
  return;
}


// ===== FUN_fff92850 @ fff92850 (1 bytes)

void FUN_fff92850(void)

{
  return;
}


// ===== FUN_fff92851 @ fff92851 (422 bytes)

void FUN_fff92851(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfffdffff;
  uVar3 = DAT_00089000;
  DAT_00089000 = uVar3 & 0xefff;
  uVar3 = DAT_00089090;
  DAT_00089090 = uVar3 & 0x7fff;
  uVar3 = DAT_00089090;
  DAT_00089090 = uVar3 & 0xdfff;
  bVar2 = DAT_00087217;
  DAT_00087217 = bVar2 & 0xfb;
  DAT_00089000 = 0;
  DAT_0008907a = 0;
  DAT_000890e1 = 0xb;
  DAT_000890e2 = 0xb;
  DAT_000890e3 = 0xb;
  DAT_000890e5 = 0xb;
  DAT_000890e6 = 0xb;
  DAT_000890e7 = 0xb;
  DAT_00089004 = 0xee;
  DAT_00089008 = 0xe8;
  DAT_00089066 = 0x618;
  DAT_0008900e = 0;
  uVar3 = DAT_00089000;
  DAT_00089000 = uVar3 | 0x1000;
  DAT_0008900c = 0x83;
  DAT_00089090 = 0;
  DAT_000877ba = 0x40;
  bVar2 = DAT_000873ba;
  DAT_000873ba = bVar2 & 0xf6 | 6;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xfd;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xfd;
  DAT_0008c161 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xfb;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xfb;
  DAT_0008c162 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xf7;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xf7;
  DAT_0008c163 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xdf;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xdf;
  DAT_0008c165 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xbf;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xbf;
  DAT_0008c166 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0x7f;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0x7f;
  DAT_0008c167 = 0x80;
  FUN_fff92b00();
  return;
}


// ===== FUN_fff929f7 @ fff929f7 (28 bytes)

void FUN_fff929f7(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_000870ba;
  DAT_000870ba = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 | 4;
  uVar2 = DAT_00089000;
  DAT_00089000 = uVar2 | 0x8000;
  return;
}


// ===== FUN_fff92a13 @ fff92a13 (30 bytes)

void FUN_fff92a13(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00089000;
  DAT_00089000 = uVar2 & 0x7fff;
  bVar1 = DAT_000870ba;
  DAT_000870ba = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 & 0xfb;
  return;
}


// ===== FUN_fff92a31 @ fff92a31 (207 bytes)

void FUN_fff92a31(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_00089020;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 1) {
    uVar1 = DAT_00089022;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 2) {
    uVar1 = DAT_00089024;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 3) {
    uVar1 = DAT_00089026;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 4) {
    uVar1 = DAT_00089028;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 5) {
    uVar1 = DAT_0008902a;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 6) {
    uVar1 = DAT_0008902c;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 7) {
    uVar1 = DAT_0008902e;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 0x1a) {
    uVar1 = DAT_00089086;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 0x18) {
    uVar1 = DAT_00089018;
    *param_2 = uVar1;
    return;
  }
  if (param_1 == 0x19) {
    uVar1 = DAT_00089084;
    *param_2 = uVar1;
    return;
  }
  if (param_1 != 0x15) {
    return;
  }
  uVar1 = DAT_0008901e;
  *param_2 = uVar1;
  return;
}


// ===== FUN_fff92b00 @ fff92b00 (1 bytes)

void FUN_fff92b00(void)

{
  return;
}


// ===== vec186_isr @ fff92b01 (22 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92b11) */
/* WARNING: Removing unreachable block (ram,0xfff92b01) */
/* WARNING: Removing unreachable block (ram,0xfff92b03) */
/* WARNING: Removing unreachable block (ram,0xfff92b13) */

undefined4 vec186_isr(undefined4 param_1)

{
  FUN_fff92a13();
  FUN_fffb27fb();
  FUN_fffb284e();
  return param_1;
}


// ===== FUN_fff92b17 @ fff92b17 (349 bytes)

void FUN_fff92b17(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfffeffff;
  uVar3 = DAT_00089100;
  DAT_00089100 = uVar3 & 0xefff;
  uVar3 = DAT_00089190;
  DAT_00089190 = uVar3 & 0x7fff;
  uVar3 = DAT_00089190;
  DAT_00089190 = uVar3 & 0xdfff;
  bVar2 = DAT_00087217;
  DAT_00087217 = bVar2 & 0xdf;
  DAT_0008917a = 0;
  DAT_00089100 = 0x5000;
  DAT_0008910e = 0;
  DAT_0008910c = 0x83;
  DAT_00089104 = 0x8300;
  DAT_00089106 = 2;
  DAT_00089108 = 0x8300;
  DAT_0008910a = 2;
  DAT_000891e8 = 0xb;
  DAT_000891e9 = 0xb;
  DAT_000891ef = 0xb;
  DAT_000891dd = 0xb;
  DAT_00089190 = 0;
  DAT_000877bd = 0x44;
  bVar2 = DAT_000873bd;
  DAT_000873bd = bVar2 & 0xf6 | 6;
  bVar2 = DAT_0008c06d;
  DAT_0008c06d = bVar2 & 0xfe;
  bVar2 = DAT_0008c00d;
  DAT_0008c00d = bVar2 & 0xfe;
  DAT_0008c1a8 = 0x80;
  bVar2 = DAT_0008c06d;
  DAT_0008c06d = bVar2 & 0xfd;
  bVar2 = DAT_0008c00d;
  DAT_0008c00d = bVar2 & 0xfd;
  DAT_0008c1a9 = 0x80;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 & 0xfd;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 & 0xfd;
  DAT_0008c189 = 0x80;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 & 0xf7;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 & 0xf7;
  DAT_0008c18b = 0x80;
  FUN_fff92e0e();
  return;
}


// ===== FUN_fff92c74 @ fff92c74 (28 bytes)

void FUN_fff92c74(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_000870bd;
  DAT_000870bd = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 | 0x20;
  uVar2 = DAT_00089100;
  DAT_00089100 = uVar2 | 0x8000;
  return;
}


// ===== FUN_fff92c90 @ fff92c90 (30 bytes)

void FUN_fff92c90(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00089100;
  DAT_00089100 = uVar2 & 0x7fff;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 & 0xdf;
  bVar1 = DAT_000870bd;
  DAT_000870bd = bVar1 & 0xfe;
  return;
}


// ===== FUN_fff92cae @ fff92cae (352 bytes)

void FUN_fff92cae(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = DAT_00089120;
    *param_2 = uVar1;
    return;
  case 1:
    uVar1 = DAT_00089122;
    *param_2 = uVar1;
    return;
  case 2:
    uVar1 = DAT_00089124;
    *param_2 = uVar1;
    return;
  case 3:
    uVar1 = DAT_00089126;
    *param_2 = uVar1;
    return;
  case 4:
    uVar1 = DAT_00089128;
    *param_2 = uVar1;
    return;
  case 5:
    uVar1 = DAT_0008912a;
    *param_2 = uVar1;
    return;
  case 6:
    uVar1 = DAT_0008912c;
    *param_2 = uVar1;
    return;
  case 7:
    uVar1 = DAT_0008912e;
    *param_2 = uVar1;
    return;
  case 8:
    uVar1 = DAT_00089130;
    *param_2 = uVar1;
    return;
  case 9:
    uVar1 = DAT_00089132;
    *param_2 = uVar1;
    return;
  case 10:
    uVar1 = DAT_00089134;
    *param_2 = uVar1;
    return;
  case 0xb:
    uVar1 = DAT_00089136;
    *param_2 = uVar1;
    return;
  case 0xc:
    uVar1 = DAT_00089138;
    *param_2 = uVar1;
    return;
  case 0xd:
    uVar1 = DAT_0008913a;
    *param_2 = uVar1;
    return;
  case 0xe:
    uVar1 = DAT_0008913c;
    *param_2 = uVar1;
    return;
  case 0xf:
    uVar1 = DAT_0008913e;
    *param_2 = uVar1;
    return;
  case 0x10:
    uVar1 = DAT_00089140;
    *param_2 = uVar1;
    return;
  case 0x11:
    uVar1 = DAT_00089142;
    *param_2 = uVar1;
    return;
  case 0x12:
    uVar1 = DAT_00089144;
    *param_2 = uVar1;
    return;
  case 0x13:
    uVar1 = DAT_00089146;
    *param_2 = uVar1;
    return;
  case 0x14:
    uVar1 = DAT_00089148;
    *param_2 = uVar1;
    return;
  case 0x15:
    uVar1 = DAT_0008911e;
    *param_2 = uVar1;
    return;
  case 0x16:
    uVar1 = DAT_0008911a;
    *param_2 = uVar1;
    return;
  case 0x17:
    uVar1 = DAT_0008911c;
    *param_2 = uVar1;
    return;
  case 0x18:
    uVar1 = DAT_00089118;
    *param_2 = uVar1;
    return;
  case 0x19:
    uVar1 = DAT_00089184;
    *param_2 = uVar1;
    return;
  case 0x1a:
    uVar1 = DAT_00089186;
    *param_2 = uVar1;
    return;
  default:
    return;
  }
}


// ===== FUN_fff92e0e @ fff92e0e (1 bytes)

void FUN_fff92e0e(void)

{
  return;
}


// ===== vec189_isr @ fff92e0f (22 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92e1f) */
/* WARNING: Removing unreachable block (ram,0xfff92e0f) */
/* WARNING: Removing unreachable block (ram,0xfff92e11) */
/* WARNING: Removing unreachable block (ram,0xfff92e21) */

undefined4 vec189_isr(undefined4 param_1)

{
  FUN_fff92c90();
  FUN_fffb2858();
  FUN_fffb2894();
  return param_1;
}


// ===== FUN_fff92e25 @ fff92e25 (35 bytes)

void FUN_fff92e25(void)

{
  byte bVar1;
  
  DAT_00087208 = 0;
  DAT_00087209 = 0;
  bVar1 = DAT_00087203;
  DAT_00087203 = bVar1 & 0xf7;
  bVar1 = DAT_00087203;
  DAT_00087203 = bVar1 & 0xfb;
  FUN_fff92e48();
  return;
}


// ===== FUN_fff92e48 @ fff92e48 (1 bytes)

void FUN_fff92e48(void)

{
  return;
}


// ===== FUN_fff92e49 @ fff92e49 (981 bytes)

void FUN_fff92e49(void)

{
  DAT_0008c080 = 0;
  DAT_0008c0c0 = 0xa4;
  DAT_0008c0e0 = 0;
  DAT_0008c128 = 0;
  DAT_0008c060 = 0;
  DAT_0008c000 = 0x50;
  DAT_0008c082 = 0;
  DAT_0008c0c1 = 0;
  DAT_0008c0e1 = 0;
  DAT_0008c129 = 0;
  DAT_0008c061 = 0;
  DAT_0008c001 = 3;
  DAT_0008c022 = 0;
  DAT_0008c084 = 0;
  DAT_0008c085 = 0;
  DAT_0008c0c2 = 3;
  DAT_0008c0e2 = 0xc;
  DAT_0008c12a = 0;
  DAT_0008c062 = 0;
  DAT_0008c002 = 0x14;
  DAT_0008c086 = 0;
  DAT_0008c087 = 0;
  DAT_0008c0c3 = 0x12;
  DAT_0008c12b = 0;
  DAT_0008c063 = 0;
  DAT_0008c003 = 0;
  DAT_0008c088 = 0;
  DAT_0008c089 = 0;
  DAT_0008c0c4 = 0x11;
  DAT_0008c064 = 0;
  DAT_0008c004 = 0;
  DAT_0008c025 = 0;
  DAT_0008c08b = 0;
  DAT_0008c0c5 = 0x1e;
  DAT_0008c0e5 = 0;
  DAT_0008c12d = 0;
  DAT_0008c065 = 0;
  DAT_0008c005 = 0xc0;
  DAT_0008c026 = 0;
  DAT_0008c08c = 0;
  DAT_0008c08d = 0;
  DAT_0008c0c6 = 0x17;
  DAT_0008c066 = 0;
  DAT_0008c006 = 0xe8;
  DAT_0008c027 = 0x40;
  DAT_0008c08e = 4;
  DAT_0008c08f = 0;
  DAT_0008c0c7 = 0;
  DAT_0008c0e7 = 9;
  DAT_0008c12f = 0;
  DAT_0008c067 = 0;
  DAT_0008c007 = 0xdf;
  DAT_0008c028 = 0x40;
  DAT_0008c090 = 0;
  DAT_0008c091 = 0;
  DAT_0008c0c8 = 0;
  DAT_0008c0e8 = 0;
  DAT_0008c130 = 0;
  DAT_0008c068 = 0;
  DAT_0008c008 = 0x7f;
  DAT_0008c092 = 0;
  DAT_0008c0e9 = 0;
  DAT_0008c131 = 0;
  DAT_0008c02a = 0;
  DAT_0008c094 = 0;
  DAT_0008c095 = 0;
  DAT_0008c0ca = 8;
  DAT_0008c0ea = 0;
  DAT_0008c132 = 0;
  DAT_0008c06a = 0;
  DAT_0008c00a = 0xf7;
  DAT_0008c02b = 0;
  DAT_0008c096 = 0;
  DAT_0008c097 = 0;
  DAT_0008c0eb = 0;
  DAT_0008c133 = 0;
  DAT_0008c06b = 0;
  DAT_0008c00b = 0xfc;
  DAT_0008c02c = 0x10;
  DAT_0008c098 = 0;
  DAT_0008c099 = 0;
  DAT_0008c0cc = 2;
  DAT_0008c0ec = 0;
  DAT_0008c134 = 0;
  DAT_0008c06c = 0;
  DAT_0008c00c = 0x11;
  DAT_0008c02d = 0;
  DAT_0008c09a = 0;
  DAT_0008c09b = 0;
  DAT_0008c0ed = 0;
  DAT_0008c135 = 0;
  DAT_0008c06d = 0;
  DAT_0008c00d = 0xfc;
  DAT_0008c02e = 0;
  DAT_0008c09c = 0;
  DAT_0008c09d = 0;
  DAT_0008c0ce = 8;
  DAT_0008c0ee = 0;
  DAT_0008c136 = 0;
  DAT_0008c06e = 0;
  DAT_0008c00e = 0x77;
  DAT_0008c0cf = 0x20;
  DAT_0008c06f = 0;
  DAT_0008c00f = 0xdf;
  DAT_0008c032 = 0;
  DAT_0008c0a4 = 0;
  DAT_0008c0d2 = 0x20;
  DAT_0008c072 = 0;
  DAT_0008c012 = 0xdf;
  FUN_fff9321e();
  return;
}


// ===== FUN_fff9321e @ fff9321e (1 bytes)

void FUN_fff9321e(void)

{
  return;
}


// ===== R_SCI0_Create @ fff9321f (163 bytes)

/* SCI0 init (USB "Standard" CAT via CP2105) */

void R_SCI0_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0x7fffffff;
  bVar2 = DAT_0008733a;
  DAT_0008733a = bVar2 & 0xf8 | 8;
  bVar2 = DAT_0008733b;
  DAT_0008733b = bVar2 & 0xf8 | 8;
  DAT_0008a002 = 0;
  DAT_0008a002 = 0;
  bVar2 = DAT_0008a009;
  DAT_0008a009 = bVar2 & 0xfe;
  DAT_0008a00d = 0;
  DAT_0008a000 = 1;
  DAT_0008a006 = 0x72;
  DAT_0008a007 = 0x10;
  DAT_0008a001 = 0xc2;
  DAT_0008c15b = 0xb;
  bVar2 = DAT_0008c063;
  DAT_0008c063 = bVar2 | 8;
  DAT_0008c15a = 0xb;
  bVar2 = DAT_0008c023;
  DAT_0008c023 = bVar2 | 4;
  bVar2 = DAT_0008c003;
  DAT_0008c003 = bVar2 | 4;
  FUN_fff9340d();
  return;
}


// ===== R_SCI0_Start @ fff932c2 (64 bytes)

void R_SCI0_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008703b;
  DAT_0008703b = bVar1 & 0xfe;
  bVar1 = DAT_0008703a;
  DAT_0008703a = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 8;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 1;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 4;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 2;
  return;
}


// ===== R_SCI0_Stop @ fff93302 (104 bytes)

void R_SCI0_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c063;
  DAT_0008c063 = bVar1 & 0xfb;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xdf;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xef;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0x7f;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xbf;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xf7;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffffe;
  bVar1 = DAT_0008703b;
  DAT_0008703b = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xfb;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffffd;
  bVar1 = DAT_0008703a;
  DAT_0008703a = bVar1 & 0xfe;
  return;
}


// ===== R_SCI0_Serial_Receive @ fff9336a (68 bytes)

undefined2 R_SCI0_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b606 = 0;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 0x40;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 0x10;
    DAT_0001b608 = param_2;
    DAT_000207f8 = param_1;
  }
  return local_a;
}


// ===== R_SCI0_Serial_Send @ fff933ae (95 bytes)

undefined2 R_SCI0_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_00087207;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 & 0xf7;
      bVar1 = DAT_0008a002;
      DAT_0008a002 = bVar1 | 0xa0;
      bVar1 = DAT_0008c063;
      DAT_0008c063 = bVar1 | 4;
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 | 8;
      DAT_0001b604 = param_2;
      DAT_000207f4 = param_1;
    }
  }
  return local_a;
}

