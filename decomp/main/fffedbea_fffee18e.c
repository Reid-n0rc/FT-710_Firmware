// FT-710_MAIN_V0112.bin — Ghidra decompile, 18 functions

// ===== FUN_fffedbea @ fffedbea (61 bytes)

void FUN_fffedbea(void)

{
  undefined2 extraout_var;
  undefined1 uStack_4;
  
  DAT_00025d18 = DAT_00020f50;
  FUN_fffb4135(DAT_00020f50);
  DAT_0001b3c5 = (char)((ushort)extraout_var >> 8);
  uStack_4 = (undefined1)extraout_var;
  DAT_0001b3c6 = uStack_4;
  return;
}


// ===== FUN_fffedc27 @ fffedc27 (142 bytes)

void FUN_fffedc27(undefined1 param_1)

{
  int iVar1;
  undefined1 local_2;
  undefined1 local_1;
  
  local_1 = param_1;
  if (DAT_0001b3c7 == '\0') {
    local_2 = 0xff;
    FUN_fffb195a(&local_2,1);
    DAT_0001b3c7 = 1;
    swtimer_start(0x23,0x28);
    return;
  }
  iVar1 = swtimer_expired(0x23);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffb195a(&DAT_0001b3c4,local_1);
  DAT_0001b3c7 = 0;
  DAT_0001b3c9 = 0;
  DAT_0001b3ca = 0;
  DAT_0001b3cb = 0;
  swtimer_start(7,100);
  swtimer_start(0x25,100);
  swtimer_start(0x24,0x1cc);
  return;
}


// ===== FUN_fffedcb5 @ fffedcb5 (82 bytes)

void FUN_fffedcb5(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_fffb191e();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffb192d();
  pcVar3 = (char *)FUN_fffb194e();
  cVar1 = *pcVar3;
  if (cVar1 == -0x51) {
    FUN_fff94c75(pcVar3 + 1);
  }
  else {
    if (cVar1 == -0x5f) {
      DAT_0001b3ca = 1;
      return;
    }
    if (cVar1 == -0x60) {
      DAT_0001b3c9 = 1;
      return;
    }
  }
  DAT_0001b3cb = 1;
  return;
}


// ===== R_TPU2_Create @ fffedd07 (102 bytes)

/* TPU2 PCLKB/4, TGRA=74: 5 us, vec138 (speaker-switch soft start) */

void R_TPU2_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfb;
  DAT_0008778a = 0x18;
  bVar2 = DAT_0008738a;
  DAT_0008738a = bVar2 & 0xf2 | 2;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfb;
  DAT_00088130 = 0x29;
  bVar2 = DAT_00088134;
  DAT_00088134 = bVar2 | 0x41;
  DAT_00088132 = 0;
  DAT_00088138 = 0x4a;
  DAT_0008813a = 0x5db;
  FUN_fffedd8b();
  return;
}


// ===== R_TPU2_Start @ fffedd6d (15 bytes)

void R_TPU2_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 | 4;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 4;
  return;
}


// ===== R_TPU2_Stop @ fffedd7c (15 bytes)

/* Disable vector 138, clear TSTR bit 2 */

void R_TPU2_Stop(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 & 0xfb;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfb;
  return;
}


// ===== FUN_fffedd8b @ fffedd8b (1 bytes)

void FUN_fffedd8b(void)

{
  return;
}


// ===== r_tpu2_tgia_isr @ fffedd8c (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfffedd94) */
/* WARNING: Removing unreachable block (ram,0xfffedd8c) */
/* WARNING: Removing unreachable block (ram,0xfffedd8e) */
/* WARNING: Removing unreachable block (ram,0xfffedd96) */
/* vec138 -> spk_softstart_isr */

undefined4 r_tpu2_tgia_isr(undefined4 param_1)

{
  spk_softstart_isr();
  return param_1;
}


// ===== FUN_fffedd9a @ fffedd9a (47 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffedd9a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc6) */

undefined4 FUN_fffedd9a(undefined4 param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = *param_3;
  *(byte *)param_3 = (byte)*param_3 & 0x7f;
  FUN_fffeddc9(param_3);
  *param_3 = uVar1 & 0x80;
  uVar2 = FUN_fffedfa7(param_1,param_2,param_3,0xffffffff);
  return uVar2;
}


// ===== FUN_fffeddc9 @ fffeddc9 (84 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffede1a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc9) */

undefined4 FUN_fffeddc9(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*param_1 & 3) == 0) || (*(char *)((int)param_1 + 3) < '\0')) {
    FUN_fffee0c2(param_1);
    uVar2 = 0xffffffff;
    DAT_00025d1c = 9;
  }
  else {
    uVar2 = FUN_fffedf24(param_1);
    if ((*param_1 & 0x40) != 0) {
      FUN_fffee10b(*(undefined4 *)(param_1 + 2));
    }
    param_1[2] = 0;
    param_1[3] = 0;
    iVar1 = FUN_fff8fac2((int)*(char *)((int)param_1 + 3));
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
    FUN_fffee0c2(param_1);
  }
  return uVar2;
}


// ===== FUN_fffede1d @ fffede1d (36 bytes)

int FUN_fffede1d(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 == 0) {
    return 0;
  }
  do {
    if ((param_3 & 0xff) <= uVar3) break;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 + 1;
    cVar2 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 == cVar2);
  return (uint)(byte)param_1[-1] - (uint)(byte)param_2[-1];
}


// ===== FUN_fffede41 @ fffede41 (153 bytes)

uint FUN_fffede41(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_4 & 0xffff0000) == 0) {
    if (param_4 == 0) {
      if ((param_3 & 0xffff0000) == 0) {
        if (param_2 != 0) {
          param_1 = param_1 & 0xffff;
          if ((param_3 & 0xff) != 0) {
            param_1 = param_1 / (param_3 & 0xff);
          }
          return param_1;
        }
        if (param_1 != 0) {
          if ((param_3 & 0xff) != 0) {
            param_1 = param_1 / (param_3 & 0xff);
          }
          return param_1;
        }
        return 0;
      }
      iVar3 = 0x20;
      uVar2 = 0;
      param_4 = param_3;
    }
    else {
      param_4 = param_4 << 0x10 | param_3 >> 0x10 & 0xff;
      iVar3 = 0x10;
      uVar2 = param_3 << 0x10;
    }
  }
  else {
    iVar3 = 0;
    uVar2 = param_3;
  }
  uVar6 = 0;
  uVar4 = 0;
  if ((param_4 & 0x80000000) == 0) {
    do {
      if (param_2 <= (param_4 & 0xff)) break;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 << 1;
      uVar5 = param_4 << 1;
      bVar1 = (int)param_4 < 0;
      param_4 = uVar5;
      if (bVar1) {
        param_4 = uVar5 | 1;
      }
    } while (-1 < (int)param_4);
  }
  do {
    bVar1 = param_1 < (uVar2 & 0xff);
    param_1 = param_1 - (uVar2 & 0xff);
    uVar5 = param_4 - bVar1;
    bVar1 = param_2 < uVar5;
    param_2 = param_2 - uVar5;
    if (bVar1) {
      bVar1 = CARRY4(uVar2,param_1);
      param_1 = param_1 + uVar2;
      param_2 = param_2 + param_4 +
                (uint)(CARRY4(param_2,(uint)bVar1) || CARRY4(param_4,param_2 + bVar1));
    }
    uVar5 = uVar4 << 1;
    if ((int)uVar4 < 0) {
      uVar5 = uVar5 | 1;
    }
    uVar7 = uVar6 << 1;
    if ((int)uVar6 < 0) {
      uVar7 = uVar7 | 1;
    }
    param_4 = param_4 >> 1;
    uVar4 = uVar2 & 1;
    uVar2 = uVar2 >> 1;
    if (uVar4 != 0) {
      uVar2 = uVar2 | 0x80000000;
    }
    iVar3 = iVar3 + -1;
    uVar4 = uVar5;
    uVar6 = uVar7;
  } while (-1 < iVar3);
  return uVar5;
}


// ===== _INITSCT @ fffededa (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfffededa) */
/* WARNING: Removing unreachable block (ram,0xfffedf21) */
/* CC-RX section init: BTBL 0xFFF8E6C4..DC zero-fill, DTBL 0xFFF8E6A0..C4 copy ROM->RAM */

undefined4 _INITSCT(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  ppuVar5 = &BTBL;
  while ((undefined **)((uint)ppuVar5 & 0xff) < RelocatableVectors) {
    puVar1 = (undefined4 *)*ppuVar5;
    ppuVar6 = ppuVar5 + 1;
    ppuVar5 = ppuVar5 + 2;
    if ((undefined *)((uint)puVar1 & 0xff) < *ppuVar6) {
      for (iVar4 = (int)*ppuVar6 - ((uint)puVar1 & 0xff); iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar1 = 0;
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
    }
  }
  ppuVar5 = &DTBL;
  while ((undefined **)((uint)ppuVar5 & 0xff) < &BTBL) {
    puVar3 = *ppuVar5;
    ppuVar6 = ppuVar5 + 1;
    puVar2 = ppuVar5[2];
    ppuVar5 = ppuVar5 + 3;
    if ((undefined *)((uint)puVar3 & 0xff) < *ppuVar6) {
      for (iVar4 = (int)*ppuVar6 - ((uint)puVar3 & 0xff); iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return param_1;
}


// ===== FUN_fffedf24 @ fffedf24 (131 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffedfa4) */
/* WARNING: Removing unreachable block (ram,0xfffedf24) */

undefined4 FUN_fffedf24(ushort *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (param_1 == (ushort *)0x0) {
    piVar4 = &DAT_0001ff74;
    uVar6 = 0;
    for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {
      if ((*piVar4 != 0) && (iVar5 = FUN_fffedf24(), iVar5 < 0)) {
        uVar6 = 0xffffffff;
      }
      piVar4 = piVar4 + 1;
    }
  }
  else {
    uVar6 = 0;
    if ((*param_1 & 0x2000) != 0) {
      iVar3 = *(int *)(param_1 + 2);
      for (iVar5 = 0; (uint)(iVar5 + iVar3) < (*(uint *)(param_1 + 6) & 0xff); iVar5 = iVar5 + iVar2
          ) {
        iVar2 = FUN_fff8facd((int)*(char *)((int)param_1 + 3));
        if (iVar2 < 1) {
          uVar6 = *(undefined4 *)(param_1 + 2);
          *(undefined4 *)(param_1 + 6) = uVar6;
          *(undefined4 *)(param_1 + 10) = uVar6;
          *(undefined4 *)(param_1 + 0x16) = uVar6;
          *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
          return 0xffffffff;
        }
      }
      uVar1 = *(undefined4 *)(param_1 + 2);
      uVar6 = 0;
      *(undefined4 *)(param_1 + 6) = uVar1;
      *(undefined4 *)(param_1 + 10) = uVar1;
      *(undefined4 *)(param_1 + 0x16) = uVar1;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) & 0xdf;
    }
  }
  return uVar6;
}


// ===== FUN_fffedfa7 @ fffedfa7 (214 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffee07a) */
/* WARNING: Removing unreachable block (ram,0xfffedfa7) */

undefined2 * FUN_fffedfa7(int param_1,char *param_2,undefined2 *param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int in_stack_0000000c;
  
  if (param_3 != (undefined2 *)0x0) {
    uVar3 = *(undefined1 *)(param_3 + 1);
    puVar6 = &DAT_fff8e644;
    uVar2 = *param_3;
    puVar5 = param_3;
    for (iVar8 = 0x48; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar5 = *puVar6;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      puVar6 = puVar6 + 1;
    }
    *(undefined1 *)(param_3 + 1) = uVar3;
    puVar5 = param_3 + 0x22;
    *(undefined2 **)(param_3 + 2) = puVar5;
    *(undefined2 **)(param_3 + 6) = puVar5;
    *(undefined2 **)(param_3 + 8) = puVar5;
    *(undefined2 **)(param_3 + 0x14) = puVar5;
    *(undefined2 **)(param_3 + 10) = puVar5;
    *(undefined2 **)(param_3 + 0x16) = puVar5;
    *(undefined2 **)(param_3 + 0xc) = puVar5;
    *(undefined2 **)(param_3 + 0xe) = param_3 + 0x12;
    cVar1 = *param_2;
    if (cVar1 == 'r') {
      uVar9 = 1;
    }
    else if (cVar1 == 'w') {
      uVar9 = 0x1a;
    }
    else {
      uVar9 = 0x16;
      if (cVar1 != 'a') {
        uVar9 = 0;
      }
    }
    puVar10 = (undefined4 *)(uVar9 | (byte)uVar2 & 0x80);
    *param_3 = (short)puVar10;
    if ((uVar9 & 3) == 0) {
      FUN_fffeddc9(param_3);
      DAT_00025d1c = 0x16;
    }
    else {
      while( true ) {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        if ((cVar1 != 'b') && (cVar1 != '+')) break;
        if (cVar1 == 'b') {
          if (((uint)puVar10 & 0x20) != 0) break;
          puVar10 = (undefined4 *)((uint)puVar10 | 0x20);
        }
        else {
          if (((uint)puVar10 & 3) == 3) break;
          puVar10 = (undefined4 *)((uint)puVar10 | 3);
        }
        *param_3 = (short)puVar10;
      }
      if (param_1 == 0) {
        if (-1 < param_4) {
          *(char *)((int)param_3 + 3) = (char)param_4;
          return param_3;
        }
      }
      else {
        puVar7 = puVar10;
        if (in_stack_0000000c != 0) {
          puVar7 = (undefined4 *)((uint)puVar10 | 0x40);
        }
        if (in_stack_0000000c == 0x55) {
          *puVar10 = 1;
        }
        iVar8 = FUN_fffee18e(param_1,puVar7);
        *(char *)((int)param_3 + 3) = (char)iVar8;
        if (-1 < iVar8) {
          return param_3;
        }
      }
      uVar4 = DAT_00025d1c;
      FUN_fffeddc9(param_3);
      DAT_00025d1c = uVar4;
    }
  }
  return (undefined2 *)0x0;
}


// ===== FUN_fffee0c2 @ fffee0c2 (73 bytes)

void FUN_fffee0c2(ushort *param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((*param_1 & 0x80) == 0) {
    puVar1 = param_1 + 0x22;
    *(undefined1 *)((int)param_1 + 3) = 0xff;
    *(ushort **)(param_1 + 2) = puVar1;
    *(ushort **)(param_1 + 6) = puVar1;
    *(ushort **)(param_1 + 8) = puVar1;
    *(ushort **)(param_1 + 0x14) = puVar1;
    *(ushort **)(param_1 + 10) = puVar1;
    *(ushort **)(param_1 + 0x16) = puVar1;
    *(ushort **)(param_1 + 0xc) = puVar1;
    *param_1 = 0;
    *(ushort **)(param_1 + 0xe) = param_1 + 0x12;
    return;
  }
  uVar3 = 0;
  puVar2 = &DAT_0001ff74;
  do {
    if (0x13 < uVar3) {
LAB_fffee106:
      FUN_fffee10b();
      return;
    }
    if (param_1 == (ushort *)*puVar2) {
      *puVar2 = 0;
      goto LAB_fffee106;
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while( true );
}


// ===== FUN_fffee10b @ fffee10b (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee18b) */

int * FUN_fffee10b(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_1 != (int *)0x0) {
    puVar3 = (uint *)(param_1 + -2);
    uVar1 = *puVar3;
    if ((7 < uVar1) && ((uVar1 & 7) == 0)) {
      if ((DAT_00025e5c == (uint *)0x0) || (puVar3 < (uint *)((uint)DAT_00025e5c & 0xff))) {
        param_1[-1] = (int)DAT_00025e5c;
        puVar4 = puVar3;
        DAT_00025e5c = puVar3;
      }
      else {
        puVar6 = (uint *)&DAT_00025e5c;
        do {
          puVar4 = (uint *)*puVar6;
          uVar2 = puVar4[1];
          puVar6 = puVar4 + 1;
          if (((uint)puVar3 & 0xff) <= uVar2) break;
        } while (uVar2 != 0);
        uVar5 = *puVar4 + (int)puVar4;
        if (puVar3 < (uint *)(uVar5 & 0xff)) {
          return param_1;
        }
        if (uVar5 == ((uint)puVar3 & 0xff)) {
          *puVar4 = uVar1 + *puVar4;
        }
        else {
          if ((uVar2 != 0) && (uVar2 < ((int)param_1 + (uVar1 - 8) & 0xff))) {
            return param_1;
          }
          param_1[-1] = uVar2;
          puVar4[1] = (uint)puVar3;
          puVar4 = puVar3;
        }
      }
      param_1 = (int *)puVar4[1];
      if ((param_1 != (int *)0x0) && ((int)puVar4 + *puVar4 == ((uint)param_1 & 0xff))) {
        DAT_00025e58 = 0;
        param_1 = (int *)puVar4[1];
        *puVar4 = *puVar4 + *param_1;
        puVar4[1] = param_1[1];
      }
    }
  }
  return param_1;
}


// ===== FUN_fffee18e @ fffee18e (48 bytes)

int FUN_fffee18e(undefined4 param_1,uint param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(&DAT_fff8e68c + (param_2 & 3) * 4);
  if ((param_2 & 4) != 0) {
    uVar3 = uVar3 | 0x20;
  }
  if ((param_2 & 8) != 0) {
    uVar3 = uVar3 | 0x10;
  }
  if ((param_2 & 0x10) != 0) {
    uVar3 = uVar3 | 8;
  }
  uVar2 = 0x1b6;
  if (param_3 != 0) {
    uVar2 = 0x180;
  }
  cVar1 = FUN_fff8fa1b(param_1,uVar3,uVar2);
  return (int)cVar1;
}

