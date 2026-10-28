// FT-710_MAIN_V0112.bin — Ghidra decompile, 24 functions

// ===== FUN_fffedba8 @ fffedba8 (33 bytes)

void FUN_fffedba8(void)

{
  DAT_0001b3c4 = 0xe0;
  DAT_0001b3c5 = 1;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedbc9 @ fffedbc9 (33 bytes)

void FUN_fffedbc9(void)

{
  DAT_0001b3c4 = 0xef;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedbea @ fffedbea (61 bytes)

void FUN_fffedbea(void)

{
  uint uVar1;
  undefined1 uStack_4;
  
  DAT_00025d18 = DAT_00020f50;
  uVar1 = FUN_fffb4135(DAT_00020f50);
  DAT_0001b3c5 = (char)(uVar1 >> 0x18);
  uStack_4 = (undefined1)(uVar1 >> 0x10);
  DAT_0001b3c6 = uStack_4;
  return;
}


// ===== FUN_fffedc27 @ fffedc27 (142 bytes)

void FUN_fffedc27(undefined1 param_1)

{
  byte bVar1;
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
  bVar1 = swtimer_expired(0x23);
  if (bVar1 != 1) {
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

void r_tpu2_tgia_isr(void)

{
  spk_softstart_isr();
  return;
}


// ===== FUN_fffedd9a @ fffedd9a (47 bytes)

/* WARNING: Removing unreachable block (ram,0xfffedd9a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc6) */

uint FUN_fffedd9a(uint param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *param_3;
  *(byte *)param_3 = (byte)*param_3 & 0x7f;
  FUN_fffeddc9(param_3);
  *param_3 = uVar1 & 0x80;
  uVar2 = FUN_fffedfa7(param_1,param_2,param_3,0xffffffff);
  return uVar2;
}


// ===== FUN_fffeddc9 @ fffeddc9 (84 bytes)

/* WARNING: Removing unreachable block (ram,0xfffede1a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc9) */

uint FUN_fffeddc9(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  
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

ulonglong FUN_fffede41(uint param_1,uint param_2,uint param_3,uint param_4)

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
          if ((param_3 & 0xff) != 0) {
            param_2 = param_2 / (param_3 & 0xff);
          }
          uVar2 = param_1 & 0xffff;
          if ((param_3 & 0xff) != 0) {
            uVar2 = uVar2 / (param_3 & 0xff);
          }
          return CONCAT44(param_2,uVar2);
        }
        if (param_1 != 0) {
          if ((param_3 & 0xff) != 0) {
            param_1 = param_1 / (param_3 & 0xff);
          }
          return (ulonglong)param_1;
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
  return CONCAT44(uVar7,uVar5);
}


// ===== _INITSCT @ fffededa (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfffededa) */
/* WARNING: Removing unreachable block (ram,0xfffedf21) */
/* CC-RX section init: BTBL 0xFFF8E6C4..DC zero-fill, DTBL 0xFFF8E6A0..C4 copy ROM->RAM */

void _INITSCT(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ppuVar2 = &BTBL;
  while ((undefined **)((uint)ppuVar2 & 0xff) < RelocatableVectors) {
    puVar1 = *ppuVar2;
    ppuVar3 = ppuVar2 + 1;
    ppuVar2 = ppuVar2 + 2;
    if ((undefined *)((uint)puVar1 & 0xff) < *ppuVar3) {
      sstr(puVar1,0,(int)*ppuVar3 - ((uint)puVar1 & 0xff));
    }
  }
  ppuVar2 = &DTBL;
  while ((undefined **)((uint)ppuVar2 & 0xff) < &BTBL) {
    puVar1 = *ppuVar2;
    ppuVar3 = ppuVar2 + 1;
    ppuVar4 = ppuVar2 + 2;
    ppuVar2 = ppuVar2 + 3;
    if ((undefined *)((uint)puVar1 & 0xff) < *ppuVar3) {
      smovf(*ppuVar4,puVar1,(int)*ppuVar3 - ((uint)puVar1 & 0xff));
    }
  }
  return;
}


// ===== FUN_fffedf24 @ fffedf24 (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffedfa4) */
/* WARNING: Removing unreachable block (ram,0xfffedf24) */

uint FUN_fffedf24(ushort *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  if (param_1 == (ushort *)0x0) {
    puVar5 = &DAT_0001ff74;
    uVar7 = 0;
    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {
      if (((ushort *)*puVar5 != (ushort *)0x0) &&
         (uVar2 = FUN_fffedf24((ushort *)*puVar5), (int)uVar2 < 0)) {
        uVar7 = 0xffffffff;
      }
      puVar5 = puVar5 + 1;
    }
  }
  else {
    uVar7 = 0;
    if ((*param_1 & 0x2000) != 0) {
      iVar4 = *(int *)(param_1 + 2);
      iVar6 = 0;
      while( true ) {
        pvVar3 = (void *)(iVar6 + iVar4);
        if ((void *)(*(uint *)(param_1 + 6) & 0xff) <= pvVar3) break;
        uVar7 = FUN_fff8facd((int)*(char *)((int)param_1 + 3),pvVar3,
                             *(uint *)(param_1 + 6) - ((uint)pvVar3 & 0xff));
        if ((int)uVar7 < 1) {
          uVar1 = *(undefined4 *)(param_1 + 2);
          *(undefined4 *)(param_1 + 6) = uVar1;
          *(undefined4 *)(param_1 + 10) = uVar1;
          *(undefined4 *)(param_1 + 0x16) = uVar1;
          *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
          return 0xffffffff;
        }
        iVar6 = iVar6 + uVar7;
      }
      uVar1 = *(undefined4 *)(param_1 + 2);
      uVar7 = 0;
      *(undefined4 *)(param_1 + 6) = uVar1;
      *(undefined4 *)(param_1 + 10) = uVar1;
      *(undefined4 *)(param_1 + 0x16) = uVar1;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) & 0xdf;
    }
  }
  return uVar7;
}


// ===== FUN_fffedfa7 @ fffedfa7 (214 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee07a) */
/* WARNING: Removing unreachable block (ram,0xfffedfa7) */

ushort * FUN_fffedfa7(int param_1,char *param_2,ushort *param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_R2;
  ushort uVar6;
  int in_stack_0000000c;
  ushort uVar7;
  
  if (param_3 != (ushort *)0x0) {
    smovf(param_3,0xfff8e644,0x48);
    uVar5 = 0xfff8e68c;
    *(char *)(param_3 + 1) = (char)param_3[1];
    puVar3 = param_3 + 0x22;
    *(ushort **)(param_3 + 2) = puVar3;
    *(ushort **)(param_3 + 6) = puVar3;
    *(ushort **)(param_3 + 8) = puVar3;
    *(ushort **)(param_3 + 0x14) = puVar3;
    *(ushort **)(param_3 + 10) = puVar3;
    *(ushort **)(param_3 + 0x16) = puVar3;
    *(ushort **)(param_3 + 0xc) = puVar3;
    *(ushort **)(param_3 + 0xe) = param_3 + 0x12;
    cVar1 = *param_2;
    if (cVar1 == 'r') {
      uVar7 = 1;
    }
    else if (cVar1 == 'w') {
      uVar7 = 0x1a;
    }
    else {
      uVar7 = 0x16;
      if (cVar1 != 'a') {
        uVar7 = 0;
      }
    }
    uVar6 = uVar7 | (byte)*param_3 & 0x80;
    *param_3 = uVar6;
    if ((uVar7 & 3) == 0) {
      FUN_fffeddc9(param_3,0xfff8e68c);
      DAT_00025d1c = 0x16;
    }
    else {
      while( true ) {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        if ((cVar1 != 'b') && (cVar1 != '+')) break;
        if (cVar1 == 'b') {
          if ((uVar6 & 0x20) != 0) break;
          uVar6 = uVar6 | 0x20;
        }
        else {
          if ((uVar6 & 3) == 3) break;
          uVar6 = uVar6 | 3;
        }
        *param_3 = uVar6;
      }
      if (param_1 == 0) {
        if (-1 < param_4) {
          *(char *)((int)param_3 + 3) = (char)param_4;
          return param_3;
        }
      }
      else {
        if (in_stack_0000000c != 0) {
          uVar6 = uVar6 | 0x40;
        }
        iVar4 = FUN_fffee18e(param_1,uVar6,in_stack_0000000c == 0x55);
        *(char *)((int)param_3 + 3) = (char)iVar4;
        uVar5 = extraout_R2;
        if (-1 < iVar4) {
          return param_3;
        }
      }
      uVar2 = DAT_00025d1c;
      FUN_fffeddc9(param_3,uVar5);
      DAT_00025d1c = uVar2;
    }
  }
  return (ushort *)0x0;
}


// ===== FUN_fffee07d @ fffee07d (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee07d) */
/* WARNING: Removing unreachable block (ram,0xfffee0bf) */

short * FUN_fffee07d(void)

{
  short *psVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_0001ff74;
  uVar2 = 0;
  while( true ) {
    if (0x13 < uVar2) {
      return (short *)0x0;
    }
    psVar1 = (short *)*puVar3;
    if (psVar1 == (short *)0x0) break;
    if (*psVar1 == 0) {
      *psVar1 = -0x81;
      return psVar1;
    }
    puVar3 = puVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  psVar1 = (short *)FUN_fffee239(0x48);
  if (psVar1 == (short *)0x0) {
    return (short *)0x0;
  }
  *puVar3 = psVar1;
  *(char *)(psVar1 + 1) = (char)uVar2;
  *psVar1 = 0x80;
  return psVar1;
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
  
  uVar3 = *(uint *)(BYTE_ARRAY_fff8e648 + (param_2 & 3) * 4 + 0x44);
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


// ===== FUN_fffee1be @ fffee1be (123 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee1be) */
/* WARNING: Removing unreachable block (ram,0xfffee236) */

uint * FUN_fffee1be(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  do {
    puVar2 = DAT_00025e58;
    if (DAT_00025e58 == (uint *)0x0) {
      puVar2 = &DAT_00025e5c;
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
    }
    else {
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
      puVar2 = &DAT_00025e5c;
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)(*DAT_00025e58 & 0xff)) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
    }
    uVar4 = 0x400;
    while( true ) {
      uVar3 = param_1;
      if ((param_1 & 0xff) <= uVar4) {
        uVar3 = uVar4;
      }
      puVar2 = (uint *)FUN_fffee29c(uVar3);
      if (puVar2 != (uint *)0x0) break;
      if (uVar3 == (param_1 & 0xff)) {
        return (uint *)0x0;
      }
      uVar4 = uVar3 >> 1;
    }
    *puVar2 = uVar3;
    FUN_fffee10b();
  } while( true );
}


// ===== FUN_fffee239 @ fffee239 (99 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee299) */

uint * FUN_fffee239(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xf & 0xfffffff8;
  if (((param_1 & 0xff) < uVar3) && (param_1 != 0)) {
    if (uVar3 < 8) {
      uVar3 = 8;
    }
    puVar2 = (uint *)FUN_fffee1be(uVar3);
    if (puVar2 != (uint *)0x0) {
      puVar1 = (uint *)*puVar2;
      if (*puVar1 - 8 < (uVar3 & 0xff)) {
        *puVar2 = puVar1[1];
      }
      else {
        *puVar2 = uVar3 + (int)puVar1;
        *(uint *)(uVar3 + (int)puVar1 + 4) = puVar1[1];
        *(uint *)*puVar2 = *puVar1 - (uVar3 & 0xff);
        *puVar1 = uVar3;
      }
      uVar3 = *puVar2;
      if ((uVar3 == 0) || (DAT_00025e58 = uVar3 + 4, *(int *)(uVar3 + 4) == 0)) {
        DAT_00025e58 = 0;
      }
      return puVar1 + 2;
    }
  }
  return (uint *)0x0;
}


// ===== FUN_fffee29c @ fffee29c (27 bytes)

int FUN_fffee29c(int param_1)

{
  bool bVar1;
  
  if (param_1 < 1) {
    bVar1 = false;
  }
  else {
    param_1 = FUN_fff912c7();
    bVar1 = false;
    if (param_1 != -1) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    param_1 = 0;
  }
  return param_1;
}

