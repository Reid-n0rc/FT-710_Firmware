// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00207cf0 @ 00207cf0 (60 bytes)

/* WARNING: Removing unreachable block (ram,0x00207d1a) */

void FUN_00207cf0(void)

{
  code *pcVar1;
  
  if (DAT_00238400 == '\0') {
    DAT_00238400 = 0;
    pcVar1 = *(code **)PTR_DAT_00236820;
    while (pcVar1 != (code *)0x0) {
      PTR_DAT_00236820 = PTR_DAT_00236820 + 4;
      (*pcVar1)();
      pcVar1 = *(code **)PTR_DAT_00236820;
    }
    DAT_00238400 = 1;
    return;
  }
  return;
}


// ===== FUN_00207d2c @ 00207d2c (25 bytes)

/* WARNING: Removing unreachable block (ram,0x00207d37) */

void FUN_00207d2c(void)

{
  return;
}


// ===== FUN_00207d50 @ 00207d50 (8 bytes)

void FUN_00207d50(void)

{
  FUN_00208050();
  return;
}


// ===== FUN_00207d58 @ 00207d58 (748 bytes)

void FUN_00207d58(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  uVar5 = DAT_40021434;
  uVar5 = uVar5 & 3;
  if (uVar5 == 0) {
    memw();
    uVar5 = DAT_40021430;
    uVar5 = uVar5 & 3;
    if (uVar5 == 0) {
      memw();
      uVar5 = DAT_40001100;
      if ((uVar5 & (uint)&DAT_000c0000) == 0) {
        uVar5 = 48000000;
      }
      else if ((undefined *)(uVar5 & (uint)&DAT_000c0000) == &DAT_000c0000) {
        uVar5 = 60000000;
      }
      else {
        uVar5 = 0;
      }
      memw();
      uVar4 = DAT_40021400;
      DAT_00236824 = (uVar5 >> 2) / ((uVar4 & 0xff) + 1);
      return;
    }
    if (uVar5 == 1) {
      memw();
      iVar3 = DAT_40001168;
      if (iVar3 == 0) {
        uVar5 = 24000000;
      }
      else {
        memw();
        uVar1 = DAT_40001168;
        uVar5 = 0;
      }
      memw();
      uVar4 = DAT_40021400;
      DAT_00236824 = uVar5 / ((uVar4 & 0xff) + 1);
      return;
    }
    if (uVar5 == 2) {
      memw();
      uVar5 = DAT_40021400;
      DAT_00236824 = (uint)&DAT_000f4240 / ((uVar5 & 0xff) + 1);
      return;
    }
    if (uVar5 == 3) {
      memw();
      uVar5 = DAT_40021400;
      DAT_00236824 = 16000000 / ((uVar5 & 0xff) + 1);
      return;
    }
  }
  else {
    if (uVar5 == 1) {
      memw();
      uVar5 = DAT_40001200;
      uVar5 = uVar5 & 7;
      if (uVar5 == 0) {
        uVar4 = 16000000;
      }
      else if (uVar5 == 1) {
        memw();
        iVar3 = DAT_40001168;
        if (iVar3 == 0) {
          uVar4 = 24000000;
        }
        else {
          memw();
          uVar4 = 0;
          uVar1 = DAT_40001168;
        }
      }
      else {
        uVar4 = 0;
        if (uVar5 == 2) {
          memw();
          uVar5 = DAT_40001100;
          if ((uVar5 & (uint)&DAT_000c0000) == 0) {
            uVar4 = 48000000;
          }
          else if ((undefined *)(uVar5 & (uint)&DAT_000c0000) == &DAT_000c0000) {
            uVar4 = 60000000;
          }
          else {
            uVar4 = 0;
          }
          uVar4 = uVar4 >> 1;
        }
      }
      memw();
      uVar5 = DAT_40001204;
      if ((uVar5 & 1) == 0) {
        memw();
        uVar5 = DAT_40001210;
        memw();
        uVar1 = DAT_40001214;
        iVar3 = __udivdi3(uVar4 * uVar5,(int)((ulonglong)uVar4 * (ulonglong)uVar5 >> 0x20),uVar1,0);
        memw();
        uVar5 = DAT_40001204;
        uVar4 = ((uVar5 & 0xff0000) >> 0x10) * uVar4 + iVar3;
      }
      memw();
      uVar5 = DAT_40001204;
      if ((uVar5 & 1) == 0) {
        memw();
        uVar5 = DAT_40001218;
        uVar2 = __udivdi3(uVar4 * 0x12,(int)((ulonglong)uVar4 * 0x12 >> 0x20),uVar5 & 0x3f,0);
        memw();
        uVar5 = DAT_40001240;
        memw();
        uVar4 = DAT_40021400;
        DAT_00236824 = (uVar2 / ((uVar5 & 0xff) + 1)) / ((uVar4 & 0xff) + 1);
        return;
      }
      memw();
      uVar5 = DAT_40001240;
      memw();
      uVar2 = DAT_40021400;
      DAT_00236824 = (uVar4 / ((uVar5 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
      return;
    }
    if (uVar5 == 2) {
      memw();
      uVar5 = DAT_40001200;
      uVar5 = uVar5 & 7;
      if (uVar5 == 0) {
        uVar4 = 16000000;
      }
      else if (uVar5 == 1) {
        memw();
        iVar3 = DAT_40001168;
        if (iVar3 == 0) {
          uVar4 = 24000000;
        }
        else {
          memw();
          uVar4 = 0;
          uVar1 = DAT_40001168;
        }
      }
      else {
        uVar4 = 0;
        if (uVar5 == 2) {
          memw();
          uVar5 = DAT_40001100;
          if ((uVar5 & (uint)&DAT_000c0000) == 0) {
            uVar4 = 48000000;
          }
          else if ((undefined *)(uVar5 & (uint)&DAT_000c0000) == &DAT_000c0000) {
            uVar4 = 60000000;
          }
          else {
            uVar4 = 0;
          }
          uVar4 = uVar4 >> 1;
        }
      }
      memw();
      uVar5 = DAT_40001204;
      if ((uVar5 & 1) == 0) {
        memw();
        uVar5 = DAT_40001210;
        memw();
        uVar1 = DAT_40001214;
        iVar3 = __udivdi3(uVar4 * uVar5,(int)((ulonglong)uVar4 * (ulonglong)uVar5 >> 0x20),uVar1,0);
        memw();
        uVar5 = DAT_40001204;
        uVar4 = ((uVar5 & 0xff0000) >> 0x10) * uVar4 + iVar3;
      }
      memw();
      uVar5 = DAT_40001204;
      if ((uVar5 & 1) == 0) {
        memw();
        uVar5 = DAT_40001218;
        uVar4 = __udivdi3(uVar4 * 0x12,(int)((ulonglong)uVar4 * 0x12 >> 0x20),
                          (uVar5 & (uint)&DAT_00003f00) >> 8,0);
      }
      memw();
      uVar5 = DAT_40001244;
      memw();
      uVar2 = DAT_40021400;
      DAT_00236824 = (uVar4 / ((uVar5 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
      return;
    }
    if (uVar5 == 3) {
      memw();
      uVar5 = DAT_40021400;
      DAT_00236824 = (uint)&DAT_00008000 / ((uVar5 & 0xff) + 1);
      return;
    }
  }
  memw();
  uVar1 = DAT_40021400;
  DAT_00236824 = 0;
  return;
}


// ===== FUN_00208050 @ 00208050 (5 bytes)

void FUN_00208050(void)

{
  return;
}


// ===== FUN_00208060 @ 00208060 (259 bytes)

/* WARNING: Removing unreachable block (ram,0x00208140) */
/* WARNING: Removing unreachable block (ram,0x0020809b) */
/* WARNING: Removing unreachable block (ram,0x0020807d) */
/* WARNING: Removing unreachable block (ram,0x00208083) */
/* WARNING: Removing unreachable block (ram,0x00208089) */
/* WARNING: Removing unreachable block (ram,0x00208092) */
/* WARNING: Removing unreachable block (ram,0x00208098) */
/* WARNING: Removing unreachable block (ram,0x00208152) */
/* WARNING: Removing unreachable block (ram,0x0020812d) */
/* WARNING: Removing unreachable block (ram,0x00208116) */

void FUN_00208060(undefined *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == &DAT_40139000) {
    memw();
    DAT_40001044 = 0x8000;
  }
  else {
    memw();
    DAT_40001040 = 1;
  }
  FUN_00208234(param_1,0);
  memw();
  uVar1 = *(uint *)(param_1 + 8) & 0xf9ffe1fc;
  if ((char)param_2[1] != '\0') {
    uVar1 = *(uint *)(param_1 + 8) & 0xf9ffe1fc | (uint)&DAT_00001000;
  }
  uVar2 = 0;
  if (*(char *)((int)param_2 + 5) != '\0') {
    uVar2 = uVar1 | 0x800;
  }
  uVar1 = *param_2;
  if (*(char *)((int)param_2 + 6) != '\0') {
    uVar1 = uVar2 | 0x400;
  }
  uVar2 = 0x200;
  if (*(char *)((int)param_2 + 7) != '\0') {
    uVar2 = uVar1 | 0x200;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar2 | *param_2 & 3;
  return;
}


// ===== FUN_00208164 @ 00208164 (182 bytes)

/* WARNING: Removing unreachable block (ram,0x002081f8) */
/* WARNING: Removing unreachable block (ram,0x002081b4) */
/* WARNING: Removing unreachable block (ram,0x00208187) */
/* WARNING: Removing unreachable block (ram,0x0020818a) */
/* WARNING: Removing unreachable block (ram,0x0020818d) */
/* WARNING: Removing unreachable block (ram,0x00208193) */
/* WARNING: Removing unreachable block (ram,0x00208196) */
/* WARNING: Removing unreachable block (ram,0x00208199) */
/* WARNING: Removing unreachable block (ram,0x00208209) */
/* WARNING: Removing unreachable block (ram,0x002081e7) */
/* WARNING: Removing unreachable block (ram,0x002081c5) */

void FUN_00208164(undefined *param_1)

{
  FUN_00208234(param_1,0);
  if (param_1 != &DAT_40139000) {
    memw();
    DAT_40001070 = 1;
    return;
  }
  memw();
  DAT_40001074 = 0x8000;
  return;
}


// ===== FUN_0020821c @ 0020821c (23 bytes)

void FUN_0020821c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  return;
}


// ===== FUN_00208234 @ 00208234 (50 bytes)

void FUN_00208234(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9fffeff | 0x100;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9fffeff;
  return;
}


// ===== FUN_00208268 @ 00208268 (44 bytes)

void FUN_00208268(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0x79ffffff | 0x80000000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0x79ffffff;
  return;
}


// ===== FUN_00208294 @ 00208294 (51 bytes)

void FUN_00208294(int param_1,uint *param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xc) =
       *(uint *)(param_1 + 0xc) & 0x88ffffff | (*param_2 & 7) << 0x1c | (param_2[1] & 7) << 0x18;
  return;
}


// ===== FUN_002082c8 @ 002082c8 (44 bytes)

void FUN_002082c8(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xb9ffffff | (uint)&DAT_40000000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xb9ffffff;
  return;
}


// ===== FUN_002082f4 @ 002082f4 (44 bytes)

void FUN_002082f4(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9ffbfff | (uint)&DAT_00004000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9ffbfff;
  return;
}


// ===== FUN_00208320 @ 00208320 (64 bytes)

void FUN_00208320(int param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 8) =
       *(uint *)(param_1 + 8) & 0xf9007f8f | (uint)&DAT_00008000 |
       (*(uint *)(param_2 + 4) & 7) << 4 | (*(uint *)(param_2 + 8) & 0xff) << 0x10;
  return;
}


// ===== FUN_00208360 @ 00208360 (110 bytes)

void FUN_00208360(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == (uint *)0x0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffbff;
    return;
  }
  memw();
  uVar1 = (uint)(byte)param_2[1] | (*param_2 & 1) << 9;
  uVar2 = *(uint *)(param_1 + 0xc) & 0xfffffd00 | uVar1;
  if (param_2[2] != 0) {
    uVar1 = uVar2 | 0x400;
    if (param_2[2] == 1) {
      uVar1 = uVar2 | 0x500;
    }
    memw();
    *(uint *)(param_1 + 0xc) = uVar1;
    return;
  }
  memw();
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffc00 | uVar1 | 0x400;
  return;
}


// ===== FUN_002083d0 @ 002083d0 (126 bytes)

void FUN_002083d0(int param_1,uint *param_2)

{
  if (param_2 != (uint *)0x0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xff00ffff | param_2[2] << 0x10;
    memw();
    memw();
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & 0xd10000ff | (param_2[4] & 0x3f) << 8 |
         (param_2[3] & 3) << 0xe | (*param_2 & 1) << 0x1d | (param_2[1] & 7) << 0x19;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xff00ffff;
  return;
}


// ===== FUN_00208450 @ 00208450 (24 bytes)

void FUN_00208450(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = param_2 | *(uint *)(param_1 + 0x10) & 0xff00ffc0;
  return;
}


// ===== FUN_00208468 @ 00208468 (27 bytes)

void FUN_00208468(int param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xff00ffff | param_2 << 0x10;
  return;
}


// ===== FUN_00208484 @ 00208484 (84 bytes)

void FUN_00208484(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 8) & 0xf9ffffff;
  if ((param_2 & 1) != 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xe9ffffff | 0x10000000;
  }
  if ((param_2 >> 1 & 1) != 0) {
    uVar1 = uVar1 & 0xf1ffffff | 0x8000000;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar1;
  if ((param_2 & 4) == 0) {
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xbf00ffff | (uint)&DAT_40000000;
  return;
}


// ===== FUN_002084d8 @ 002084d8 (60 bytes)

void FUN_002084d8(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 8);
  if ((param_2 & 1) != 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xe9ffffff;
  }
  if ((param_2 >> 1 & 1) != 0) {
    uVar1 = uVar1 & 0xf1ffffff;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar1;
  if ((param_2 & 4) == 0) {
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xbf00ffff;
  return;
}


// ===== FUN_00208514 @ 00208514 (40 bytes)

uint FUN_00208514(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *(uint *)(param_1 + 8);
  uVar1 = (uVar2 >> 0x1a & 1) << 0x1a;
  if ((uVar2 >> 0x19 & 1) != 0) {
    uVar1 = uVar1 | 0x2000000;
  }
  if ((uVar2 >> 0x18 & 1) != 0) {
    uVar1 = uVar1 | 0x1000000;
  }
  return uVar1;
}


// ===== FUN_0020853c @ 0020853c (45 bytes)

void FUN_0020853c(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 8) & 0xf9ffffff;
  if ((param_2 >> 0x1a & 1) != 0) {
    uVar1 = uVar1 | 0x4000000;
  }
  if ((param_2 >> 0x19 & 1) != 0) {
    uVar1 = uVar1 | 0x2000000;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar1;
  return;
}


// ===== FUN_0020856c @ 0020856c (109 bytes)

void FUN_0020856c(int param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_2 + 0xc) << 8;
  if (param_2[2] != '\0') {
    uVar1 = (uint)(*param_2 == '\0') << 0x1c | 0x1100000;
  }
  memw();
  *(uint *)(param_1 + 0x14) =
       uVar1 | (*(uint *)(param_2 + 0x10) & 7) << 4 |
       *(int *)(param_2 + 0xc) << 8 & 0x700U |
       (*(uint *)(param_2 + 4) & 1) << 0x10 | (*(uint *)(param_2 + 8) & 7) << 0xc;
  return;
}


// ===== FUN_002085dc @ 002085dc (26 bytes)

void FUN_002085dc(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 0;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 2) = 0;
  return;
}


// ===== CLOCK_AttachClk @ 00208600 (80 bytes)

void CLOCK_AttachClk(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    param_1 = param_1 >> (uVar2 & 0x1f);
    puVar1 = &DAT_40001000;
    if ((param_1 & 0x80008000) != 0) {
      puVar1 = &DAT_40021000;
    }
    if ((param_1 & 0xfff) == 0) break;
    memw();
    *(uint *)(puVar1 + (param_1 & 0xfff)) = param_1 >> 0xc & 7;
    uVar2 = uVar2 + 0x10;
    if (0x10 < uVar2) {
      return;
    }
  }
  return;
}


// ===== FUN_00208654 @ 00208654 (95 bytes)

void FUN_00208654(uint param_1,int param_2)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  
  if ((int)param_1 < 0) {
    puVar1 = &DAT_40021000;
  }
  else {
    puVar1 = &DAT_40001000;
  }
  puVar2 = (uint *)(puVar1 + (param_1 & 0xfff));
  memw();
  memw();
  *puVar2 = *puVar2 | (uint)&DAT_20000000;
  if (param_2 != 0) {
    memw();
    *puVar2 = param_2 - 1;
    memw();
    uVar3 = *puVar2;
    while ((int)uVar3 < 0) {
      memw();
      uVar3 = *puVar2;
    }
    return;
  }
  memw();
  memw();
  *puVar2 = *puVar2 | (uint)&DAT_40000000;
  return;
}


// ===== FUN_002086b4 @ 002086b4 (43 bytes)

undefined4 FUN_002086b4(void)

{
  uint uVar1;
  
  memw();
  uVar1 = DAT_40001100;
  if ((uVar1 & (uint)&DAT_000c0000) == 0) {
    return 48000000;
  }
  if ((undefined *)(uVar1 & (uint)&DAT_000c0000) != &DAT_000c0000) {
    return 0;
  }
  return 60000000;
}


// ===== FUN_002086e0 @ 002086e0 (139 bytes)

uint FUN_002086e0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  memw();
  uVar4 = DAT_40001200;
  uVar4 = uVar4 & 7;
  uVar2 = 16000000;
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      memw();
      iVar3 = DAT_40001168;
      if (iVar3 == 0) {
        memw();
        uVar2 = DAT_00238420;
      }
      else {
        memw();
        memw();
        iVar3 = DAT_40001168;
        uVar2 = 0;
        if (iVar3 == 1) {
          uVar2 = DAT_0023841c;
        }
      }
    }
    else {
      uVar2 = 0;
      if (uVar4 == 2) {
        uVar4 = FUN_002086b4();
        uVar2 = uVar4 >> 1;
      }
    }
  }
  memw();
  uVar4 = DAT_40001204;
  if ((uVar4 & 1) == 0) {
    memw();
    uVar4 = DAT_40001210;
    memw();
    uVar1 = DAT_40001214;
    iVar3 = __udivdi3(uVar2 * uVar4,(int)((ulonglong)uVar2 * (ulonglong)uVar4 >> 0x20),uVar1,0);
    memw();
    uVar4 = DAT_40001204;
    return ((uVar4 & 0xff0000) >> 0x10) * uVar2 + iVar3;
  }
  return uVar2;
}


// ===== FUN_0020876c @ 0020876c (172 bytes)

uint FUN_0020876c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_002086e0();
  memw();
  uVar2 = DAT_40001204;
  if ((uVar2 & 1) != 0) {
    return uVar1;
  }
  if (param_1 == 0) {
    memw();
    uVar2 = DAT_40001218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),uVar2 & 0x3f,0);
    return uVar2;
  }
  if (param_1 == 1) {
    memw();
    uVar2 = DAT_40001218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                      (uVar2 & (uint)&DAT_00003f00) >> 8,0);
    return uVar2;
  }
  if (param_1 != 2) {
    if (param_1 != 3) {
      return 0;
    }
    memw();
    uVar2 = DAT_40001218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                      (uVar2 & 0x3f000000) >> 0x18,0);
    return uVar2;
  }
  memw();
  uVar2 = DAT_40001218;
  uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                    (uVar2 & (uint)&DAT_003f0000) >> 0x10,0);
  return uVar2;
}


// ===== FUN_00208818 @ 00208818 (139 bytes)

uint FUN_00208818(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  memw();
  uVar4 = DAT_40021200;
  uVar4 = uVar4 & 7;
  uVar2 = 16000000;
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      memw();
      iVar3 = DAT_40001168;
      if (iVar3 == 0) {
        memw();
        uVar2 = DAT_00238420;
      }
      else {
        memw();
        memw();
        iVar3 = DAT_40001168;
        uVar2 = 0;
        if (iVar3 == 1) {
          uVar2 = DAT_0023841c;
        }
      }
    }
    else {
      uVar2 = 0;
      if (uVar4 == 2) {
        uVar4 = FUN_002086b4();
        uVar2 = uVar4 >> 1;
      }
    }
  }
  memw();
  uVar4 = DAT_40021204;
  if ((uVar4 & 1) == 0) {
    memw();
    uVar4 = DAT_40021210;
    memw();
    uVar1 = DAT_40021214;
    iVar3 = __udivdi3(uVar2 * uVar4,(int)((ulonglong)uVar2 * (ulonglong)uVar4 >> 0x20),uVar1,0);
    memw();
    uVar4 = DAT_40021204;
    return ((uVar4 & 0xff0000) >> 0x10) * uVar2 + iVar3;
  }
  return uVar2;
}


// ===== FUN_002088a8 @ 002088a8 (172 bytes)

uint FUN_002088a8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00208818();
  memw();
  uVar2 = DAT_40021204;
  if ((uVar2 & 1) != 0) {
    return uVar1;
  }
  if (param_1 == 0) {
    memw();
    uVar2 = DAT_40021218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),uVar2 & 0x3f,0);
    return uVar2;
  }
  if (param_1 == 1) {
    memw();
    uVar2 = DAT_40021218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                      (uVar2 & (uint)&DAT_00003f00) >> 8,0);
    return uVar2;
  }
  if (param_1 != 2) {
    if (param_1 != 3) {
      return 0;
    }
    memw();
    uVar2 = DAT_40021218;
    uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                      (uVar2 & 0x3f000000) >> 0x18,0);
    return uVar2;
  }
  memw();
  uVar2 = DAT_40021218;
  uVar2 = __udivdi3(uVar1 * 0x12,(int)((ulonglong)uVar1 * 0x12 >> 0x20),
                    (uVar2 & (uint)&DAT_003f0000) >> 0x10,0);
  return uVar2;
}


// ===== FUN_00208958 @ 00208958 (156 bytes)

undefined * FUN_00208958(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined *)0x0;
  memw();
  uVar4 = DAT_40001434;
  uVar4 = uVar4 & 3;
  if (uVar4 == 0) {
    memw();
    uVar4 = DAT_40001430;
    uVar4 = uVar4 & 3;
    if (uVar4 == 0) {
      uVar4 = FUN_002086b4();
      return (undefined *)(uVar4 >> 2);
    }
    if (uVar4 == 1) {
      memw();
      iVar1 = DAT_40001168;
      if (iVar1 != 0) {
        memw();
        memw();
        iVar1 = DAT_40001168;
        if (iVar1 == 1) {
          puVar2 = DAT_0023841c;
        }
        return puVar2;
      }
      memw();
      return DAT_00238420;
    }
    if (uVar4 == 2) {
      return &DAT_000f4240;
    }
    if (uVar4 == 3) {
      puVar2 = (undefined *)FUN_002086b4();
      return puVar2;
    }
  }
  else {
    if (uVar4 == 1) {
      return (undefined *)0xf42400;
    }
    if (uVar4 == 2) {
      uVar3 = FUN_0020876c(0);
      memw();
      uVar4 = DAT_40001240;
      return (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
    }
    if (uVar4 == 3) {
      memw();
      uVar4 = DAT_400011c0;
      if ((uVar4 & 1) != 0) {
        puVar2 = &DAT_00008000;
      }
      return puVar2;
    }
  }
  return (undefined *)0x0;
}


// ===== FUN_002089f8 @ 002089f8 (173 bytes)

undefined * FUN_002089f8(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined *)0x0;
  memw();
  uVar4 = DAT_40021434;
  uVar4 = uVar4 & 3;
  if (uVar4 == 0) {
    memw();
    uVar4 = DAT_40021430;
    uVar4 = uVar4 & 3;
    if (uVar4 == 0) {
      puVar2 = (undefined *)FUN_002086b4();
      return puVar2;
    }
    if (uVar4 == 1) {
      memw();
      iVar1 = DAT_40001168;
      if (iVar1 != 0) {
        memw();
        memw();
        iVar1 = DAT_40001168;
        if (iVar1 == 1) {
          puVar2 = DAT_0023841c;
        }
        return puVar2;
      }
      memw();
      return DAT_00238420;
    }
    if (uVar4 == 2) {
      return &DAT_000f4240;
    }
    if (uVar4 == 3) {
      return (undefined *)0xf42400;
    }
  }
  else {
    if (uVar4 == 1) {
      uVar3 = FUN_0020876c(0);
      memw();
      uVar4 = DAT_40001240;
      return (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
    }
    if (uVar4 == 2) {
      uVar3 = FUN_0020876c(1);
      memw();
      uVar4 = DAT_40001244;
      return (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
    }
    if (uVar4 == 3) {
      memw();
      uVar4 = DAT_400011c0;
      if ((uVar4 & 1) != 0) {
        puVar2 = &DAT_00008000;
      }
      return puVar2;
    }
  }
  return (undefined *)0x0;
}


// ===== FUN_00208aa8 @ 00208aa8 (311 bytes)

uint FUN_00208aa8(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  uVar5 = DAT_400016d4;
  uVar5 = uVar5 & 7;
  if (uVar5 == 0) {
    memw();
    uVar5 = DAT_400016d0;
    uVar5 = uVar5 & 7;
    if (uVar5 == 0) {
      memw();
      uVar5 = DAT_400016d8;
      return 16000000 / ((uVar5 & 0xff) + 1);
    }
    if (uVar5 == 1) {
      memw();
      iVar1 = DAT_40001168;
      if (iVar1 != 0) {
        memw();
        memw();
        iVar1 = DAT_40001168;
        uVar5 = 0;
        if (iVar1 == 1) {
          uVar5 = DAT_0023841c;
        }
        memw();
        uVar3 = DAT_400016d8;
        return uVar5 / ((uVar3 & 0xff) + 1);
      }
      memw();
      memw();
      uVar5 = DAT_400016d8;
      return DAT_00238420 / ((uVar5 & 0xff) + 1);
    }
    if (uVar5 == 2) {
      memw();
      uVar5 = DAT_400016d8;
      return (uint)&DAT_000f4240 / ((uVar5 & 0xff) + 1);
    }
    if (uVar5 == 3) {
      uVar3 = FUN_002086b4();
      memw();
      uVar5 = DAT_400016d8;
      return uVar3 / ((uVar5 & 0xff) + 1);
    }
  }
  else {
    if (uVar5 == 1) {
      uVar4 = FUN_0020876c(0);
      memw();
      uVar5 = DAT_40001240;
      memw();
      uVar3 = DAT_400016d8;
      return (uVar4 / ((uVar5 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
    }
    if (uVar5 == 3) {
      uVar4 = FUN_0020876c(2);
      memw();
      uVar5 = DAT_40001248;
      memw();
      uVar3 = DAT_400016d8;
      return (uVar4 / ((uVar5 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
    }
    if (uVar5 == 5) {
      uVar4 = FUN_0020876c(3);
      memw();
      uVar5 = DAT_4000124c;
      memw();
      uVar3 = DAT_400016d8;
      return (uVar4 / ((uVar5 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
    }
  }
  memw();
  uVar2 = DAT_400016d8;
  return 0;
}


// ===== FUN_00208be0 @ 00208be0 (433 bytes)

uint FUN_00208be0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  
  puVar5 = (undefined *)0x0;
  memw();
  uVar6 = DAT_40021764;
  uVar6 = uVar6 & 7;
  if (uVar6 == 0) {
    memw();
    uVar6 = DAT_40021760;
    uVar6 = uVar6 & 7;
    if (uVar6 == 0) {
      uVar6 = 16000000;
    }
    else {
      if (uVar6 == 1) {
        memw();
        iVar1 = DAT_40001168;
        if (iVar1 != 0) {
          memw();
          memw();
          iVar1 = DAT_40001168;
          uVar6 = 0;
          if (iVar1 == 1) {
            uVar6 = DAT_0023841c;
          }
          memw();
          uVar2 = DAT_40021768;
          return uVar6 / ((uVar2 & 0xff) + 1);
        }
        memw();
        memw();
        uVar6 = DAT_40021768;
        return DAT_00238420 / ((uVar6 & 0xff) + 1);
      }
      if (uVar6 == 2) {
        memw();
        uVar6 = DAT_40021768;
        return (uint)&DAT_000f4240 / ((uVar6 & 0xff) + 1);
      }
      if (uVar6 == 3) {
        uVar6 = FUN_002086b4();
      }
      else if (uVar6 == 4) {
        uVar6 = FUN_00208958();
      }
      else {
        if (uVar6 != 6) goto LAB_00208c1b;
        uVar6 = FUN_002089f8();
      }
    }
  }
  else {
    if (uVar6 == 1) {
      uVar4 = FUN_0020876c(0);
      memw();
      uVar6 = DAT_40001240;
      memw();
      uVar2 = DAT_40021768;
      return (uVar4 / ((uVar6 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
    }
    if (uVar6 == 2) {
      uVar4 = FUN_0020876c(2);
      memw();
      uVar6 = DAT_40001248;
      memw();
      uVar2 = DAT_40021768;
      return (uVar4 / ((uVar6 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
    }
    if (uVar6 != 3) {
      if (uVar6 == 4) {
        uVar4 = FUN_0020876c(3);
        memw();
        uVar6 = DAT_4000124c;
        memw();
        uVar2 = DAT_40021768;
        return (uVar4 / ((uVar6 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
      }
      if (uVar6 == 5) {
        uVar4 = FUN_002088a8(0);
        memw();
        uVar6 = DAT_40021240;
        memw();
        uVar2 = DAT_40021768;
        return (uVar4 / ((uVar6 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
      }
      if (uVar6 == 6) {
        memw();
        uVar6 = DAT_400011c0;
        if ((uVar6 & 1) != 0) {
          puVar5 = &DAT_00008000;
        }
        memw();
        uVar6 = DAT_40021768;
        return (uint)puVar5 / ((uVar6 & 0xff) + 1);
      }
LAB_00208c1b:
      memw();
      uVar3 = DAT_40021768;
      return 0;
    }
    uVar6 = FUN_0020876c(1);
    memw();
    uVar2 = DAT_40001244;
    uVar6 = uVar6 / ((uVar2 & 0xff) + 1);
  }
  memw();
  uVar2 = DAT_40021768;
  return uVar6 / ((uVar2 & 0xff) + 1);
}


// ===== FUN_00208d94 @ 00208d94 (248 bytes)

undefined4 FUN_00208d94(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_1 < 8) {
    iVar1 = param_1 * 0x20;
    memw();
    uVar6 = *(uint *)(&DAT_40021500 + iVar1) & 7;
    memw();
    uVar5 = (*(uint *)(&DAT_40021504 + iVar1) & (uint)&DAT_0000ff00) >> 8;
    memw();
    uVar2 = *(uint *)(&DAT_40021504 + iVar1) & 0xff;
LAB_00208dc9:
    if (uVar6 != 0) {
      if (uVar6 == 1) {
        memw();
        uVar7 = DAT_400216fc;
        uVar4 = FUN_0020876c(0);
        memw();
        uVar6 = DAT_40001240;
        uVar7 = (uVar4 / ((uVar6 & 0xff) + 1)) / ((uVar7 & 0xff) + 1);
      }
      else if (uVar6 == 2) {
        uVar7 = 16000000;
      }
      else {
        uVar7 = 0;
        if (uVar6 == 3) {
          uVar7 = FUN_002086b4();
        }
      }
      goto LAB_00208ddb;
    }
  }
  else {
    if (param_1 == 0xe) {
      memw();
      uVar6 = DAT_400216c0;
      uVar6 = uVar6 & 7;
      memw();
      uVar2 = DAT_400216c4;
      uVar5 = (uVar2 & (uint)&DAT_0000ff00) >> 8;
      memw();
      uVar2 = DAT_400216c4;
      uVar2 = uVar2 & 0xff;
      goto LAB_00208dc9;
    }
    uVar5 = 0;
    if (param_1 == 0xf) {
      memw();
      uVar6 = DAT_400216e0;
      uVar6 = uVar6 & 7;
      memw();
      uVar2 = DAT_400216e4;
      uVar5 = (uVar2 & (uint)&DAT_0000ff00) >> 8;
      memw();
      uVar2 = DAT_400216e4;
      uVar2 = uVar2 & 0xff;
      goto LAB_00208dc9;
    }
    uVar2 = 0;
  }
  uVar7 = FUN_00208958();
LAB_00208ddb:
  uVar6 = uVar2 + 1;
  uVar3 = __udivdi3(uVar7 * uVar6,
                    (int)((ulonglong)uVar7 * (ulonglong)uVar6 >> 0x20) + uVar7 * (uVar6 < uVar2),
                    uVar5 + uVar2 + 1,0);
  return uVar3;
}


// ===== CLOCK_GetFlexCommClkFreq @ 00208e90 (123 bytes)

uint CLOCK_GetFlexCommClkFreq(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 < 8) {
    memw();
    iVar3 = *(int *)(&DAT_40021508 + param_1 * 0x20);
  }
  else if (param_1 == 0xe) {
    memw();
    iVar3 = DAT_400216c8;
  }
  else {
    if (param_1 != 0xf) {
      return 16000000;
    }
    memw();
    iVar3 = DAT_400216e8;
  }
  if (iVar3 == 0) {
    return 16000000;
  }
  if (iVar3 == 1) {
    uVar2 = FUN_002086b4();
    return uVar2;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
      memw();
      return DAT_00238424;
    }
    if (iVar3 == 4) {
      uVar2 = FUN_00208d94(param_1);
      return uVar2;
    }
    return 0;
  }
  uVar1 = FUN_002088a8(0);
  memw();
  uVar2 = DAT_40021240;
  return uVar1 / ((uVar2 & 0xff) + 1);
}


// ===== FUN_00208f10 @ 00208f10 (99 bytes)

undefined * FUN_00208f10(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  uVar3 = *(uint *)(&DAT_40021720 + param_1 * 4) & 7;
  if (uVar3 == 0) {
    puVar1 = (undefined *)FUN_00208958();
    return puVar1;
  }
  if (uVar3 == 1) {
    return (undefined *)0xf42400;
  }
  if (uVar3 == 2) {
    puVar1 = (undefined *)FUN_002086b4();
    return puVar1;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      return DAT_00238424;
    }
    if (uVar3 != 5) {
      return (undefined *)0x0;
    }
    return &DAT_000f4240;
  }
  uVar2 = FUN_002088a8(0);
  memw();
  uVar3 = DAT_40021240;
  return (undefined *)(uVar2 / ((uVar3 & 0xff) + 1));
}


// ===== FUN_00208f78 @ 00208f78 (191 bytes)

uint FUN_00208f78(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar4 = DAT_40001620;
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    uVar3 = FUN_00208958();
    memw();
    uVar4 = DAT_40001624;
    return uVar3 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 1) {
    uVar2 = FUN_0020876c(0);
    memw();
    uVar4 = DAT_40001240;
    memw();
    uVar3 = DAT_40001624;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  if (uVar4 == 2) {
    uVar2 = FUN_0020876c(2);
    memw();
    uVar4 = DAT_40001248;
    memw();
    uVar3 = DAT_40001624;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  if (uVar4 != 3) {
    if (uVar4 != 4) {
      memw();
      uVar1 = DAT_40001624;
      return 0;
    }
    uVar2 = FUN_0020876c(3);
    memw();
    uVar4 = DAT_4000124c;
    memw();
    uVar3 = DAT_40001624;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  uVar3 = FUN_002086b4();
  memw();
  uVar4 = DAT_40001624;
  return uVar3 / ((uVar4 & 0xff) + 1);
}


// ===== FUN_00209038 @ 00209038 (245 bytes)

uint FUN_00209038(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar4 = DAT_40001640;
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    uVar3 = FUN_00208958();
    memw();
    uVar4 = DAT_40001644;
    return uVar3 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 1) {
    uVar2 = FUN_0020876c(0);
    memw();
    uVar4 = DAT_40001240;
    memw();
    uVar3 = DAT_40001644;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  if (uVar4 == 2) {
    uVar2 = FUN_0020876c(2);
    memw();
    uVar4 = DAT_40001248;
    memw();
    uVar3 = DAT_40001644;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  if (uVar4 != 3) {
    if (uVar4 == 4) {
      uVar2 = FUN_0020876c(3);
      memw();
      uVar4 = DAT_4000124c;
      memw();
      uVar3 = DAT_40001644;
      return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
    }
    if (uVar4 != 5) {
      memw();
      uVar1 = DAT_40001644;
      return 0;
    }
    uVar2 = FUN_002088a8(0);
    memw();
    uVar3 = DAT_40021240;
    memw();
    uVar4 = DAT_40001644;
    return (uVar2 / ((uVar3 & 0xff) + 1)) / ((uVar4 & 0xff) + 1);
  }
  uVar3 = FUN_002086b4();
  memw();
  uVar4 = DAT_40001644;
  return uVar3 / ((uVar4 & 0xff) + 1);
}


// ===== FUN_00209130 @ 00209130 (100 bytes)

uint FUN_00209130(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  iVar2 = DAT_40021740;
  if (iVar2 == 0) {
    uVar5 = FUN_002086b4();
    memw();
    uVar1 = DAT_40021744;
    return uVar5 / ((uVar1 & 0xff) + 1);
  }
  memw();
  iVar2 = DAT_40021740;
  if (iVar2 != 1) {
    memw();
    uVar3 = DAT_40021744;
    return 0;
  }
  uVar4 = FUN_002088a8(0);
  memw();
  uVar1 = DAT_40021240;
  memw();
  uVar5 = DAT_40021744;
  return (uVar4 / ((uVar1 & 0xff) + 1)) / ((uVar5 & 0xff) + 1);
}


// ===== FUN_00209194 @ 00209194 (57 bytes)

undefined * FUN_00209194(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    memw();
    uVar1 = DAT_40001720;
    if ((uVar1 & 7) == 0) {
      return &DAT_000f4240;
    }
    puVar2 = (undefined *)FUN_00208958();
    return puVar2;
  }
  memw();
  uVar1 = DAT_400217a0;
  if ((uVar1 & 7) == 0) {
    return &DAT_000f4240;
  }
  puVar2 = (undefined *)FUN_00208958();
  return puVar2;
}


// ===== FUN_002091d0 @ 002091d0 (80 bytes)

undefined * FUN_002091d0(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  
  memw();
  iVar2 = DAT_40001760;
  if (iVar2 == 0) {
    uVar4 = FUN_00208958();
    memw();
    uVar1 = DAT_40001764;
    return (undefined *)(uVar4 / ((uVar1 & 0xff) + 1));
  }
  if (iVar2 == 1) {
    return &DAT_000f4240;
  }
  if (iVar2 == 2) {
    puVar3 = (undefined *)0x0;
    memw();
    uVar1 = DAT_400011c0;
    if ((uVar1 & 1) != 0) {
      puVar3 = &DAT_00008000;
    }
    return puVar3;
  }
  if (iVar2 != 3) {
    return (undefined *)0x0;
  }
  return (undefined *)0xf42400;
}


// ===== FUN_00209220 @ 00209220 (208 bytes)

uint FUN_00209220(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    puVar1 = &DAT_40001684;
    puVar3 = &DAT_40001680;
  }
  else {
    puVar3 = &DAT_40001690;
    puVar1 = &DAT_40001694;
  }
  memw();
  uVar4 = *puVar3 & 7;
  if (uVar4 == 0) {
    uVar4 = FUN_00208958();
    memw();
    return uVar4 / ((*puVar1 & 0xff) + 1);
  }
  if (uVar4 == 1) {
    uVar2 = FUN_0020876c(0);
    memw();
    uVar4 = DAT_40001240;
    memw();
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((*puVar1 & 0xff) + 1);
  }
  if (uVar4 != 2) {
    if (uVar4 == 3) {
      uVar4 = FUN_002086b4();
      memw();
      return uVar4 / ((*puVar1 & 0xff) + 1);
    }
    if (uVar4 != 4) {
      memw();
      return 0;
    }
    uVar2 = FUN_0020876c(3);
    memw();
    uVar4 = DAT_4000124c;
    memw();
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((*puVar1 & 0xff) + 1);
  }
  uVar2 = FUN_0020876c(2);
  memw();
  uVar4 = DAT_40001248;
  memw();
  return (uVar2 / ((uVar4 & 0xff) + 1)) / ((*puVar1 & 0xff) + 1);
}


// ===== FUN_002092f4 @ 002092f4 (77 bytes)

uint FUN_002092f4(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  memw();
  uVar1 = DAT_40021780;
  if ((uVar1 & 7) == 0) {
    uVar3 = FUN_00208958();
    memw();
    uVar1 = DAT_40021790;
    return uVar3 / ((uVar1 & 0xff) + 1);
  }
  if ((uVar1 & 7) != 1) {
    memw();
    uVar2 = DAT_40021790;
    return 0;
  }
  uVar3 = FUN_002086b4();
  memw();
  uVar1 = DAT_40021790;
  return uVar3 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_00209344 @ 00209344 (132 bytes)

uint FUN_00209344(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  iVar1 = DAT_40001660;
  if (iVar1 == 0) {
    memw();
    iVar1 = DAT_40001168;
    if (iVar1 != 0) {
      memw();
      memw();
      iVar1 = DAT_40001168;
      uVar4 = 0;
      if (iVar1 == 1) {
        uVar4 = DAT_0023841c;
      }
      memw();
      uVar3 = DAT_40001664;
      return uVar4 / ((uVar3 & 0xff) + 1);
    }
    memw();
    memw();
    uVar4 = DAT_40001664;
    return DAT_00238420 / ((uVar4 & 0xff) + 1);
  }
  memw();
  iVar1 = DAT_40001660;
  if (iVar1 != 1) {
    memw();
    uVar2 = DAT_40001664;
    return 0;
  }
  uVar3 = FUN_00208958();
  memw();
  uVar4 = DAT_40001664;
  return uVar3 / ((uVar4 & 0xff) + 1);
}


// ===== FUN_002093cc @ 002093cc (266 bytes)

uint FUN_002093cc(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  
  memw();
  uVar4 = DAT_40021700;
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    memw();
    uVar4 = DAT_40021704;
    return 16000000 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 1) {
    uVar2 = FUN_002086b4();
    memw();
    uVar4 = DAT_40021704;
    return uVar2 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 2) {
    uVar3 = FUN_002088a8(0);
    memw();
    uVar4 = DAT_40021240;
    memw();
    uVar2 = DAT_40021704;
    return (uVar3 / ((uVar4 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
  }
  if (uVar4 != 3) {
    if (uVar4 == 4) {
      memw();
      uVar4 = DAT_40021704;
      return (uint)&DAT_000f4240 / ((uVar4 & 0xff) + 1);
    }
    if (uVar4 != 5) {
      memw();
      uVar1 = DAT_40021704;
      return 0;
    }
    memw();
    uVar4 = DAT_40001730;
    if ((uVar4 & 7) != 0) {
      memw();
      uVar4 = DAT_40001734;
      memw();
      uVar2 = DAT_40021704;
      return ((uint)&DAT_000f4240 / ((uVar4 & 0xff) + 1)) / ((uVar2 & 0xff) + 1);
    }
    puVar5 = (undefined *)0x0;
    memw();
    uVar4 = DAT_400011c0;
    if ((uVar4 & 1) != 0) {
      puVar5 = &DAT_00008000;
    }
    memw();
    uVar4 = DAT_40021704;
    return (uint)puVar5 / ((uVar4 & 0xff) + 1);
  }
  memw();
  memw();
  uVar4 = DAT_40021704;
  return DAT_00238424 / ((uVar4 & 0xff) + 1);
}


// ===== FUN_002094dc @ 002094dc (179 bytes)

uint FUN_002094dc(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar4 = DAT_400217c0;
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    uVar3 = FUN_00208958();
    memw();
    uVar4 = DAT_400217c4;
    return uVar3 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 1) {
    memw();
    uVar4 = DAT_400217c4;
    return 16000000 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 == 2) {
    uVar3 = FUN_002086b4();
    memw();
    uVar4 = DAT_400217c4;
    return uVar3 / ((uVar4 & 0xff) + 1);
  }
  if (uVar4 != 3) {
    if (uVar4 != 4) {
      memw();
      uVar1 = DAT_400217c4;
      return 0;
    }
    uVar2 = FUN_0020876c(3);
    memw();
    uVar4 = DAT_4000124c;
    memw();
    uVar3 = DAT_400217c4;
    return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  uVar2 = FUN_0020876c(2);
  memw();
  uVar4 = DAT_40001248;
  memw();
  uVar3 = DAT_400217c4;
  return (uVar2 / ((uVar4 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
}


// ===== FUN_00209590 @ 00209590 (264 bytes)

uint FUN_00209590(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
  case 1:
    uVar2 = FUN_00208958();
    memw();
    uVar1 = DAT_40001400;
    return uVar2 / ((uVar1 & 0xff) + 1);
  case 2:
    uVar1 = FUN_00209130();
    return uVar1;
  case 3:
    uVar1 = FUN_00208be0();
    return uVar1;
  case 4:
    uVar1 = FUN_00208aa8();
    return uVar1;
  case 5:
    uVar1 = FUN_00208f78();
    return uVar1;
  case 6:
    uVar1 = FUN_00209038();
    return uVar1;
  case 7:
    uVar1 = FUN_00209194(0);
    return uVar1;
  case 8:
    uVar1 = FUN_00209194(1);
    return uVar1;
  case 9:
    uVar1 = FUN_002091d0();
    return uVar1;
  case 10:
    uVar1 = FUN_00209220(0);
    return uVar1;
  case 0xb:
    uVar1 = FUN_00209220(1);
    return uVar1;
  case 0xc:
    uVar1 = FUN_002092f4();
    return uVar1;
  case 0xd:
    uVar1 = FUN_00209344();
    return uVar1;
  case 0xe:
    uVar1 = FUN_002093cc();
    return uVar1;
  case 0xf:
    uVar2 = FUN_002089f8();
    memw();
    uVar1 = DAT_40021400;
    return uVar2 / ((uVar1 & 0xff) + 1);
  case 0x10:
    uVar1 = FUN_002094dc();
    return uVar1;
  case 0x11:
    uVar1 = CLOCK_GetFlexCommClkFreq(0);
    return uVar1;
  case 0x12:
    uVar1 = CLOCK_GetFlexCommClkFreq(1);
    return uVar1;
  case 0x13:
    uVar1 = CLOCK_GetFlexCommClkFreq(2);
    return uVar1;
  case 0x14:
    uVar1 = CLOCK_GetFlexCommClkFreq(3);
    return uVar1;
  case 0x15:
    uVar1 = CLOCK_GetFlexCommClkFreq(4);
    return uVar1;
  case 0x16:
    uVar1 = CLOCK_GetFlexCommClkFreq(5);
    return uVar1;
  case 0x17:
    uVar1 = CLOCK_GetFlexCommClkFreq(6);
    return uVar1;
  case 0x18:
    uVar1 = CLOCK_GetFlexCommClkFreq(7);
    return uVar1;
  case 0x19:
    uVar1 = CLOCK_GetFlexCommClkFreq(0xe);
    return uVar1;
  case 0x1a:
    uVar1 = CLOCK_GetFlexCommClkFreq(0xf);
    return uVar1;
  default:
    return 0;
  }
}


// ===== FUN_0020969c @ 0020969c (132 bytes)

void FUN_0020969c(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_1;
  if (uVar2 < 8) {
    memw();
    bVar1 = param_1[9];
    *(undefined4 *)(&DAT_40021500 + uVar2 * 0x20) = *(undefined4 *)(param_1 + 4);
    memw();
    *(uint *)(&DAT_40021504 + uVar2 * 0x20) = (uint)CONCAT11(bVar1,param_1[8]);
    return;
  }
  if (uVar2 != 0xe) {
    if (uVar2 != 0xf) {
      return;
    }
    memw();
    DAT_400216e0 = *(undefined4 *)(param_1 + 4);
    memw();
    DAT_400216e4 = (uint)CONCAT11(param_1[9],param_1[8]);
    return;
  }
  memw();
  DAT_400216c0 = *(undefined4 *)(param_1 + 4);
  memw();
  DAT_400216c4 = (uint)CONCAT11(param_1[9],param_1[8]);
  return;
}

