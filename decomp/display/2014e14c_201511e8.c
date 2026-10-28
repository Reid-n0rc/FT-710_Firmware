// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2014e14c @ 2014e14c (44 bytes)

undefined4 FUN_2014e14c(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bc8) {
    uVar1 = FUN_20150c70(DAT_20808bc8,param_1);
  }
  return uVar1;
}


// ===== FUN_2014e178 @ 2014e178 (44 bytes)

int FUN_2014e178(void)

{
  int iVar1;
  
  iVar1 = FUN_2014e690(&DAT_20427ec0,"FSYS Work");
  if (iVar1 < 1) {
    DAT_20808bc8 = 0;
  }
  else {
    iVar1 = 0;
    DAT_20808bc8 = iVar1;
  }
  return iVar1;
}


// ===== FUN_2014e1b4 @ 2014e1b4 (40 bytes)

undefined4 FUN_2014e1b4(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bc8) {
    uVar1 = FUN_201502f4();
  }
  return uVar1;
}


// ===== FUN_2014e1dc @ 2014e1dc (16 bytes)

undefined4 FUN_2014e1dc(void)

{
  FUN_201146b4();
  return 1;
}


// ===== FUN_2014e1ec @ 2014e1ec (28 bytes)

undefined4 FUN_2014e1ec(void)

{
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  FUN_20150bd4(auStack_10);
  return local_c;
}


// ===== FUN_2014e208 @ 2014e208 (72 bytes)

int FUN_2014e208(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar1 = *param_2;
    uVar2 = FUN_201549e4(*param_1);
    uVar2 = uVar2 & 0xff;
    uVar3 = FUN_201549e4(uVar1);
    if (uVar2 != (uVar3 & 0xff)) {
      return uVar2 - (uVar3 & 0xff);
    }
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (uVar2 != 0);
  return 0;
}


// ===== FUN_2014e250 @ 2014e250 (84 bytes)

int FUN_2014e250(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  while( true ) {
    bVar4 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar4) {
      return 0;
    }
    uVar1 = *param_2;
    uVar2 = FUN_201549e4(*param_1);
    uVar2 = uVar2 & 0xff;
    uVar3 = FUN_201549e4(uVar1);
    if (uVar2 != (uVar3 & 0xff)) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    if (uVar2 == 0) {
      return 0;
    }
  }
  return uVar2 - (uVar3 & 0xff);
}


// ===== strncmp @ 2014e2a4 (64 bytes)

int strncmp(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  while( true ) {
    bVar2 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar2) {
      return 0;
    }
    uVar1 = (uint)*param_1;
    if (*param_2 != uVar1) break;
    if (uVar1 == 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return uVar1 - *param_2;
}


// ===== FUN_2014e2e4 @ 2014e2e4 (60 bytes)

char * FUN_2014e2e4(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  pcVar4 = param_1;
  do {
    iVar6 = param_3;
    if (iVar6 == 0) {
      return param_1;
    }
    cVar1 = *param_2;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar5;
    param_2 = param_2 + 1;
    param_3 = iVar6 + -1;
  } while (cVar1 != '\0');
  iVar3 = iVar6 + -2;
  iVar6 = iVar6 + -1;
  while (iVar2 = iVar3, iVar6 != 0) {
    *pcVar5 = '\0';
    pcVar5 = pcVar5 + 1;
    iVar3 = iVar2 + -1;
    iVar6 = iVar2;
  }
  return param_1;
}


// ===== FUN_2014e320 @ 2014e320 (164 bytes)

char * FUN_2014e320(char *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  
  if ((param_1 != (char *)0x0) || (param_1 = (char *)*param_3, param_1 != (char *)0x0)) {
    for (; cVar5 = *param_1, cVar5 != '\0'; param_1 = param_1 + 1) {
      cVar1 = *param_2;
      pcVar4 = param_2;
      while( true ) {
        pcVar3 = param_2;
        pcVar2 = param_1;
        if (cVar1 == '\0') {
          while( true ) {
            cVar1 = *pcVar3;
            if (cVar5 == cVar1) break;
            pcVar3 = pcVar3 + 1;
            if (cVar1 == '\0') {
              cVar5 = pcVar2[1];
              pcVar3 = param_2;
              pcVar2 = pcVar2 + 1;
            }
          }
          if (cVar5 == '\0') {
            *param_3 = 0;
          }
          else {
            *pcVar2 = '\0';
            *param_3 = pcVar2 + 1;
          }
          return param_1;
        }
        if (cVar5 == cVar1) break;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
    }
    *param_3 = 0;
  }
  return (char *)0x0;
}


// ===== FUN_2014e3c4 @ 2014e3c4 (448 bytes)

/* WARNING: Removing unreachable block (ram,0x2014e53c) */

uint FUN_2014e3c4(byte *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  bVar3 = false;
  pbVar9 = param_1;
  if (((-1 < param_3) && (param_3 != 1)) && (param_3 < 0x25)) {
    uVar8 = (uint)*param_1;
    piVar6 = (int *)FUN_20154974();
    iVar11 = *piVar6;
    bVar1 = *(byte *)(iVar11 + uVar8);
    pbVar5 = param_1;
    while (pbVar4 = pbVar5 + 1, (bVar1 & 1) != 0) {
      uVar8 = (uint)*pbVar4;
      pbVar5 = pbVar4;
      bVar1 = *(byte *)(iVar11 + uVar8);
    }
    bVar12 = false;
    if ((uVar8 == 0x2b) || (bVar12 = uVar8 == 0x2d, pbVar9 = pbVar4, bVar12)) {
      pbVar9 = pbVar5 + 2;
      uVar8 = (uint)*pbVar4;
    }
    if (uVar8 != 0) {
      if (param_3 == 0 || param_3 == 0x10) {
        if ((uVar8 == 0x30) && (*pbVar9 == 0x78 || *pbVar9 == 0x58)) {
          param_3 = 0x10;
          uVar8 = (uint)pbVar9[1];
          pbVar9 = pbVar9 + 2;
        }
        else if (param_3 == 0) {
          if (uVar8 == 0x30) {
            param_3 = 8;
          }
          else {
            param_3 = 10;
          }
        }
      }
      uVar10 = 0;
      bVar2 = false;
      if (bVar12) {
        uVar14 = FUN_20156260(0x80000000);
      }
      else {
        uVar14 = __aeabi_uidivmod(0x7fffffff,param_3);
      }
      do {
        if (*(byte *)(iVar11 + uVar8) == 0x20) {
          uVar8 = uVar8 - 0x30;
        }
        else {
          if ((*(byte *)(iVar11 + uVar8) & 0x98) == 0) goto LAB_2014e52c;
          if (uVar8 < 0x61) {
            uVar8 = uVar8 - 0x37;
          }
          else {
            uVar8 = uVar8 - 0x57;
          }
        }
        uVar7 = uVar8 & 0xff;
        if (param_3 <= (int)uVar7) goto LAB_2014e52c;
        if (!bVar2) {
          bVar13 = (uint)uVar14 <= uVar10;
          if (uVar10 == (uint)uVar14) {
            bVar13 = (uint)(uVar14 >> 0x20) <= uVar7;
          }
          bVar3 = true;
          if (bVar13 && uVar14 != (CONCAT44(uVar8,uVar10) & 0xffffffffff)) {
            if (bVar12) {
              uVar10 = 0x80000000;
            }
            else {
              uVar10 = 0x7fffffff;
            }
            bVar2 = true;
            bVar12 = false;
          }
          else {
            uVar10 = uVar10 * param_3 + uVar7;
          }
        }
        uVar8 = (uint)*pbVar9;
        pbVar9 = pbVar9 + 1;
      } while( true );
    }
  }
LAB_2014e540:
  uVar10 = 0;
LAB_2014e558:
  if (param_2 != (undefined4 *)0x0) {
    if (bVar3) {
      *param_2 = pbVar9 + -1;
    }
    else {
      *param_2 = param_1;
    }
  }
  return uVar10;
LAB_2014e52c:
  if (bVar3) {
    if ((bVar12) && (!bVar2)) {
      uVar10 = -uVar10;
    }
    goto LAB_2014e558;
  }
  goto LAB_2014e540;
}


// ===== os_create_sem_named @ 2014e584 (44 bytes)

/* wrapper around itron_acre_sem with a name string */

void os_create_sem_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  itron_acre_sem(0,&local_18);
  return;
}


// ===== FUN_2014e5b0 @ 2014e5b0 (52 bytes)

void FUN_2014e5b0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_28 = *param_1;
  uStack_24 = param_1[1];
  uStack_20 = param_1[2];
  uStack_1c = param_1[3];
  local_18 = param_1[4];
  local_14 = param_1[5];
  uStack_10 = param_2;
  itron_acre_tsk(0,&local_28);
  return;
}


// ===== FUN_2014e5e4 @ 2014e5e4 (44 bytes)

void FUN_2014e5e4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  uStack_8 = param_2;
  itron_acre_flg(0,&local_10);
  return;
}


// ===== FUN_2014e610 @ 2014e610 (40 bytes)

void FUN_2014e610(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  local_8 = param_2;
  FUN_2014f3e4(0,&local_18);
  return;
}


// ===== FUN_2014e638 @ 2014e638 (44 bytes)

void FUN_2014e638(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  FUN_2014f67c(0,&local_18);
  return;
}


// ===== FUN_2014e664 @ 2014e664 (44 bytes)

void FUN_2014e664(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  uStack_8 = param_2;
  FUN_2014fd24(0,&local_10);
  return;
}


// ===== FUN_2014e690 @ 2014e690 (40 bytes)

void FUN_2014e690(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  local_8 = param_2;
  FUN_2014f8b8(0,&local_18);
  return;
}


// ===== FUN_2014e6b8 @ 2014e6b8 (44 bytes)

void FUN_2014e6b8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  FUN_2014fb04(0,&local_18);
  return;
}


// ===== FUN_2014e6e4 @ 2014e6e4 (44 bytes)

void FUN_2014e6e4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  FUN_2014edf4(0,&local_18);
  return;
}


// ===== FUN_2014e710 @ 2014e710 (36 bytes)

char FUN_2014e710(void)

{
  char cVar1;
  
  cVar1 = DAT_208dc18c;
  if (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01')) {
    cVar1 = '\0';
  }
  return cVar1;
}


// ===== FUN_2014e73c @ 2014e73c (292 bytes)

code * FUN_2014e73c(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_r4;
  int *piVar6;
  uint uVar7;
  undefined4 unaff_lr;
  
  if (param_1 == 0) {
    param_1 = (uint)DAT_208dc18c;
  }
  if (DAT_201659d0 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  piVar6 = *(int **)(&DAT_208dbba0 + param_1 * 4);
  if (piVar6 == (int *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(char *)((int)piVar6 + 5) == '\0') {
    iVar2 = piVar6[6];
    uVar7 = *(uint *)(iVar2 + 8);
    iVar4 = piVar6[5] + *(int *)(iVar2 + 0x10);
    uVar5 = *(undefined4 *)(iVar2 + 4);
    *(int *)(iVar4 + -0x18) = iVar4;
    *(undefined4 *)(iVar4 + -0x48) = uVar5;
    uVar3 = DAT_208003ac;
    if ((uVar7 & 1) != 0) {
      uVar3 = DAT_208003ac | 0x20;
    }
    *(uint *)(iVar4 + -0xc) = uVar3;
    uVar3 = FUN_201568b8();
    *(uint *)(iVar4 + -0xc) = uVar3 | *(uint *)(iVar4 + -0xc);
    *(code **)(iVar4 + -0x14) = FUN_201508ec;
    *(uint *)(iVar4 + -4) = uVar7;
    *piVar6 = iVar4 + -0x48;
    *(undefined1 *)(piVar6 + 2) = 0;
    *(undefined1 *)((int)piVar6 + 9) = 0;
    piVar6[8] = 0;
    *(undefined1 *)((int)piVar6 + 5) = 0x10;
    iVar2 = piVar6[1];
    FUN_201538d4(&DAT_208dc18c + (char)iVar2,piVar6,param_1,&DAT_208dc18c + (char)iVar2,unaff_r4,
                 unaff_lr);
    if ((int)DAT_208003df <= (int)(char)iVar2) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  cVar1 = *(char *)((int)piVar6 + 0x26) + '\x01';
  *(char *)((int)piVar6 + 0x26) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)((int)piVar6 + 0x26) = 0xff;
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_2014e884 @ 2014e884 (736 bytes)

code * FUN_2014e884(uint param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  
  bVar11 = param_1 == 0;
  if (bVar11) {
    param_1 = (uint)DAT_208dc18c;
  }
  if (param_2 < 9) {
    if ((param_1 <= DAT_201659d0) && (DAT_208003da == '\0' || !bVar11)) {
      software_interrupt(0);
      puVar4 = &DAT_208dbba4 + param_1;
      piVar10 = *(int **)(&DAT_208dbba0 + param_1 * 4);
      if (piVar10 == (int *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      bVar3 = *(byte *)((int)piVar10 + 5);
      if (bVar3 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      if (param_2 == 0) {
        puVar4 = (undefined4 *)piVar10[6];
      }
      iVar9 = (int)(short)piVar10[9];
      if (param_2 == 0) {
        param_2 = puVar4[3];
      }
      if ((iVar9 == 0) && ((bVar3 & 0xfc) != 0x94)) {
        bVar11 = true;
      }
      else {
        bVar11 = false;
      }
      cVar2 = (char)param_2;
      if (bVar11) {
LAB_2014e9e4:
        *(char *)((int)piVar10 + 0x27) = cVar2;
        iVar9 = piVar10[1];
        *(char *)(piVar10 + 1) = cVar2;
        if (bVar3 == 0x10) {
          if (*(char *)((int)piVar10 + 9) == '\0') {
            FUN_20153a38(&DAT_208dc18c + param_2,piVar10,param_1);
            uVar5 = (uint)DAT_208dc18c;
            if (((uVar5 != param_1) || ((int)param_2 < (int)DAT_208003df)) &&
               ((uVar5 == param_1 || ((int)DAT_208003df < (int)param_2)))) {
              if ((uVar5 == param_1) && (DAT_208003d8 = cVar2, cVar2 != 0)) {
                DAT_208003df = cVar2;
              }
              software_interrupt(0);
              return FUN_201567f4;
            }
            software_interrupt(0);
            return FUN_2015655c;
          }
        }
        else if (0x4f < bVar3) {
          if (*(char *)(piVar10[4] + 1) != -2) {
            FUN_20153a38(piVar10[4] - ((int)(char)iVar9 - (int)cVar2),piVar10,param_1);
          }
          bVar3 = *(byte *)((int)piVar10 + 5) & 0xfc;
          if (bVar3 == 0x94) {
            iVar9 = *(int *)(&DAT_208dbfc4 + *(int *)(*piVar10 + 4) * 4);
            if (*(int *)(iVar9 + 4) == 2) {
              iVar8 = 1;
              for (pcVar6 = (char *)(iVar9 + 0xc); *pcVar6 == '\0'; pcVar6 = pcVar6 + 1) {
                iVar8 = iVar8 + 1;
              }
              if (*(char *)(iVar9 + 0xb) != iVar8) {
                FUN_20153f28(*(undefined1 *)(iVar9 + 10));
              }
            }
          }
          else if (bVar3 == 0x60) {
            iVar9 = FUN_20153dec(*(undefined4 *)(*piVar10 + 4));
            if (iVar9 != 0) {
              software_interrupt(0);
              return FUN_2015655c;
            }
          }
          else if (((*(byte *)((int)piVar10 + 5) & 0xf0) == 0xc0) &&
                  (iVar9 = FUN_20153b8c(*(undefined4 *)(*piVar10 + 4)), iVar9 != 0)) {
            software_interrupt(0);
            return FUN_2015655c;
          }
        }
        software_interrupt(0);
        return FUN_201567f4;
      }
      if ((int)param_2 < (int)(char)piVar10[1]) {
        iVar8 = 8;
        while (iVar9 != 0) {
          iVar9 = *(int *)(&DAT_208dbfc4 + iVar9 * 4);
          iVar7 = (int)*(char *)(iVar9 + 0xb);
          if ((*(int *)(iVar9 + 4) == 3) && ((int)param_2 < iVar7)) {
            software_interrupt(0);
            return (code *)0xffffffe4;
          }
          iVar9 = (int)*(short *)(iVar9 + 8);
          bVar11 = iVar7 != 0;
          iVar1 = 0;
          if (bVar11) {
            iVar1 = iVar8 - iVar7;
          }
          if ((bVar11 && iVar8 != iVar7) && iVar1 < 0 == (bVar11 && SBORROW4(iVar8,iVar7))) {
            iVar8 = iVar7;
          }
        }
        if ((int)param_2 <= iVar8) goto LAB_2014e9e4;
      }
      *(char *)((int)piVar10 + 0x27) = cVar2;
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffef;
  }
  return DAT_208003d4;
}


// ===== FUN_2014eb94 @ 2014eb94 (132 bytes)

code * FUN_2014eb94(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 == 0xffffffff) {
    DAT_208003d4 = (code *)0x0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      iVar1 = *(int *)(&DAT_208dbda4 + param_1 * 4);
      if (iVar1 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & param_2;
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  return DAT_208003d4;
}


// ===== FUN_2014ec30 @ 2014ec30 (424 bytes)

uint FUN_2014ec30(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 local_28 [2];
  uint local_24;
  
  if (DAT_208003da == '\0') {
    if ((param_1 == 0) || ((param_1 != 0 && (param_1 < 9)))) {
      if (param_2 != (uint *)0x0) {
        uVar1 = *param_2;
        if ((uVar1 & 2) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
        else {
          uVar1 = uVar1 | 1;
        }
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 8;
          iVar2 = DAT_208dbf84;
          while (uVar4 = param_1, iVar2 != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
            iVar2 = *(int *)(&DAT_208dbf64 + param_1 * 4);
          }
        }
        else {
          if (*(int *)(&DAT_208dbf64 + param_1 * 4) != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar4 = 0;
        }
        iVar2 = FUN_2015476c(0x20);
        if (iVar2 != 0) {
          *(int *)(&DAT_208dbf64 + param_1 * 4) = iVar2;
          *(undefined1 *)(iVar2 + 8) = 0;
          *(undefined1 *)(iVar2 + 9) = 0;
          local_28[0] = 0;
          *(undefined2 *)(iVar2 + 0x10) = 0;
          *(uint *)(iVar2 + 0x14) = param_2[3];
          local_24 = param_2[4];
          if (local_24 == 0) {
            local_24 = param_2[3];
          }
          *(uint *)(iVar2 + 0x1c) = param_2[2];
          uVar3 = param_2[1];
          *(uint *)(iVar2 + 0xc) = uVar1;
          *(uint *)(iVar2 + 0x18) = uVar3;
          if ((uVar1 & 6) != 0) {
            FUN_201543e4(local_28,&DAT_208003c4,iVar2);
            FUN_20153720(&DAT_208dbf64,iVar2,param_1);
          }
          software_interrupt(0);
          return uVar4;
        }
        software_interrupt(0);
        DAT_208003d4 = 0xfffffffb;
        return 0xfffffffb;
      }
      DAT_208003d4 = 0xffffffef;
    }
    else {
      DAT_208003d4 = 0xffffffee;
    }
  }
  else {
    DAT_208003d4 = 0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== FUN_2014edf4 @ 2014edf4 (496 bytes)

uint FUN_2014edf4(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_28;
  
  uVar7 = 0;
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (8 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_28 = param_1, *(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_28 = 0;
  }
  iVar9 = *(int *)(param_2 + 4);
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar4 = iVar6 + 0x1c;
  if (iVar9 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_2 + 8);
    if (iVar5 == 0) {
      uVar7 = iVar6 + 0x1fU & 0xfffffffc;
      iVar4 = uVar7 + iVar9 * 4;
    }
  }
  iVar1 = FUN_2011758c(param_2);
  if (iVar1 == 0) {
    uVar8 = iVar4 + 3U & 0xfffffffc;
    iVar4 = uVar8 + 0x10;
  }
  else {
    uVar8 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar4);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbfa4 + param_1 * 4) = piVar2;
  if (uVar8 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar8;
    FUN_201545f0((int)piVar2 + uVar8,param_2,0x10);
  }
  if (uVar7 != 0) {
    iVar5 = (int)piVar2 + uVar7;
  }
  piVar2[1] = iVar5;
  piVar2[2] = iVar5;
  piVar2[3] = iVar5;
  piVar2[4] = iVar5 + iVar9 * 4;
  *(short *)(piVar2 + 5) = (short)iVar9;
  *(undefined2 *)((int)piVar2 + 0x16) = 0;
  *(undefined1 *)(piVar2 + 6) = 0;
  *(undefined1 *)((int)piVar2 + 0x19) = 0xfe;
  iVar4 = 0;
  iVar9 = iVar4;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar9 + 1;
      *(undefined1 *)((int)piVar2 + iVar9 + 0x1a) = 0;
      iVar9 = iVar4;
    } while (iVar4 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014efa4;
    }
  }
  uVar3 = 0xff;
LAB_2014efa4:
  *(undefined1 *)((int)piVar2 + iVar4 + 0x1a) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== itron_acre_flg @ 2014effc (404 bytes)

uint itron_acre_flg(uint param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x40 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x40;
    while (uVar7 = param_1, *(int *)(&DAT_208dbda4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbda4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar7 = 0;
  }
  if ((*param_2 & 1) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 7;
  }
  iVar2 = FUN_2011758c(param_2);
  if (iVar2 == 0) {
    uVar8 = uVar6 + 0xf & 0xfffffffc;
    uVar1 = uVar8;
  }
  else {
    uVar8 = 0;
    uVar1 = uVar6;
  }
  piVar3 = (int *)FUN_2015476c(uVar1 + 0xc);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbda4 + param_1 * 4) = piVar3;
  if (uVar8 == 0) {
    *piVar3 = (int)param_2;
    uVar5 = extraout_r1;
  }
  else {
    *piVar3 = (int)piVar3 + uVar8;
    FUN_201545f0((int)piVar3 + uVar8,param_2,0xc);
    uVar5 = extraout_r1_00;
  }
  if (-1 < (int)uVar6) {
    uVar5 = 0;
  }
  piVar3[1] = *(int *)(param_2 + 4);
  *(byte *)(piVar3 + 2) = *param_2;
  iVar4 = 0;
  iVar2 = iVar4;
  if (-1 < (int)uVar6) {
    do {
      iVar4 = iVar2 + 1;
      *(undefined1 *)((int)piVar3 + iVar2 + 9) = uVar5;
      iVar2 = iVar4;
    } while (iVar4 <= (int)uVar6);
    if (uVar6 == 0) {
      uVar5 = 0xfe;
      goto LAB_2014f130;
    }
  }
  uVar5 = 0xff;
LAB_2014f130:
  *(undefined1 *)((int)piVar3 + iVar4 + 9) = uVar5;
  software_interrupt(0);
  return uVar7;
}


// ===== itron_acre_isr @ 2014f1a8 (536 bytes)

/* create an interrupt service routine object (auto-ID counts down from 0x40) [inference] */

uint itron_acre_isr(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  
  if (DAT_208003da == '\0') {
    if (param_1 < 0x41) {
      uVar2 = FUN_201175b4(param_2);
      if (uVar2 == 0) {
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 0x40;
          while (uVar2 = param_1, (&DAT_208dc044)[param_1] != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          uVar2 = 0;
          if ((&DAT_208dc044)[param_1] != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
        }
        puVar3 = (undefined4 *)FUN_2015476c(0x14);
        if (puVar3 != (undefined4 *)0x0) {
          pcVar4 = (code *)FUN_2011761c(param_2);
          if (pcVar4 == FUN_201568e0) {
            iVar5 = FUN_2015476c(0x58);
            if (iVar5 == 0) {
              FUN_20154790(puVar3,0x14);
              software_interrupt(0);
              DAT_208003d4 = 0xfffffffb;
              return 0xfffffffb;
            }
            FUN_201545f0(iVar5,FUN_201568e0,0x58);
            *(undefined4 **)(iVar5 + 0x4c) = puVar3;
            puVar3[3] = iVar5 + 0x4c;
            FUN_201175dc(iVar5,param_2);
          }
          else {
            iVar5 = FUN_2011761c(param_2);
            piVar6 = (int *)(iVar5 + 0x4c);
            iVar5 = *piVar6;
            if (iVar5 == 0) {
              *piVar6 = (int)puVar3;
              puVar3[3] = piVar6;
            }
            else {
              for (iVar1 = *(int *)(iVar5 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
                if (*(int *)(iVar1 + 0xc) != iVar5 + 8) {
                  FUN_20154790(puVar3,0x14);
                  software_interrupt(0);
                  DAT_208003d4 = 0xffffffe4;
                  return 0xffffffe4;
                }
                iVar5 = iVar1;
              }
              *(int *)(iVar5 + 8) = (int)puVar3;
              puVar3[3] = (int *)(iVar5 + 8);
            }
          }
          *puVar3 = *(undefined4 *)(param_2 + 0xc);
          puVar3[1] = *(undefined4 *)(param_2 + 4);
          puVar3[2] = 0;
          puVar3[4] = *(undefined4 *)(param_2 + 8);
          (&DAT_208dc044)[param_1] = puVar3;
          software_interrupt(0);
          return uVar2;
        }
        software_interrupt(0);
        DAT_208003d4 = 0xfffffffb;
        return 0xfffffffb;
      }
    }
    else {
      uVar2 = 0xffffffee;
    }
  }
  else {
    uVar2 = 0xffffffe7;
  }
  DAT_208003d4 = uVar2;
  return uVar2;
}


// ===== FUN_2014f3e4 @ 2014f3e4 (640 bytes)

uint FUN_2014f3e4(uint param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint local_30;
  uint local_2c;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  uVar2 = 0;
  if (param_2[1] != 0) {
    uVar2 = param_2[2];
  }
  if (param_2[1] == 0 || 0xffff < uVar2) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  if (8 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_2c = param_1, *(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_2c = 0;
  }
  if ((*param_2 & 1) == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = 7;
  }
  if ((*param_2 & 4) == 0) {
    iVar9 = 1;
  }
  else {
    iVar9 = 8;
  }
  iVar1 = iVar10 + 0x18;
  iVar8 = iVar1 + iVar9 + 1;
  iVar3 = FUN_2011758c(param_2);
  if (iVar3 == 0) {
    uVar2 = iVar1 + iVar9 + 4U & 0xfffffffc;
    iVar8 = uVar2 + 0x14;
  }
  else {
    uVar2 = 0;
  }
  local_30 = param_2[3];
  uVar11 = param_2[2];
  if (((local_30 == 0) && (uVar11 != 0)) && (local_30 = FUN_20154720(uVar11), local_30 == 0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  piVar4 = (int *)FUN_2015476c(iVar8);
  if (piVar4 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbec4 + param_1 * 4) = piVar4;
  if (uVar2 == 0) {
    *piVar4 = (int)param_2;
  }
  else {
    *piVar4 = (int)piVar4 + uVar2;
    FUN_201545f0((int)piVar4 + uVar2,param_2,0x14);
  }
  if (uVar11 == 0) {
    local_30 = 0;
  }
  piVar4[1] = local_30;
  *(undefined2 *)(piVar4 + 2) = 0;
  *(undefined2 *)((int)piVar4 + 10) = 0;
  *(short *)(piVar4 + 3) = (short)uVar11;
  *(short *)((int)piVar4 + 0xe) = (short)uVar11;
  *(short *)(piVar4 + 4) = (short)param_2[1];
  iVar8 = 0;
  iVar3 = iVar8;
  if (-1 < iVar10) {
    do {
      iVar8 = iVar3 + 1;
      *(undefined1 *)((int)piVar4 + iVar3 + 0x13) = 0;
      iVar3 = iVar8;
    } while (iVar8 <= iVar10);
    if (iVar10 == 0) {
      uVar7 = 0xfe;
      goto LAB_2014f5f8;
    }
  }
  uVar7 = 0xff;
LAB_2014f5f8:
  *(undefined1 *)((int)piVar4 + iVar8 + 0x13) = uVar7;
  puVar5 = (undefined1 *)((int)piVar4 + iVar1);
  iVar10 = 0;
  *(char *)((int)piVar4 + 0x12) = (char)iVar1;
  puVar6 = puVar5;
  if (iVar9 != 0) {
    do {
      iVar10 = iVar10 + 1;
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (iVar10 < iVar9);
  }
  if (iVar9 == 1) {
    uVar7 = 0xfe;
  }
  else {
    uVar7 = 0xff;
  }
  *puVar5 = uVar7;
  software_interrupt(0);
  return local_2c;
}


// ===== FUN_2014f67c @ 2014f67c (544 bytes)

undefined4 * FUN_2014f67c(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *local_28;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = &DAT_ffffffe7;
    return (undefined4 *)&DAT_ffffffe7;
  }
  if (&SupervisorCall < param_1) {
    DAT_208003d4 = (undefined1 *)0xffffffee;
    return (undefined4 *)0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == (undefined4 *)0x0) {
    if (DAT_208003b4 == (undefined4 *)0x0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffde;
    }
    iVar5 = *(int *)(&DAT_208dbea4 + (int)DAT_208003b4 * 4);
    param_1 = DAT_208003b4;
    while (iVar5 != 0) {
      param_1 = (undefined4 *)((int)param_1 + -1);
      if (param_1 == (undefined4 *)0x0) {
        software_interrupt(0);
        return (undefined4 *)0xffffffde;
      }
      iVar5 = *(int *)(&DAT_208dbea4 + (int)param_1 * 4);
    }
    DAT_208003b4 = (undefined4 *)((int)param_1 + -1);
    local_28 = param_1;
  }
  else {
    if (*(int *)(&DAT_208dbea4 + (int)param_1 * 4) != 0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffd7;
    }
    local_28 = (undefined4 *)0x0;
  }
  if ((*param_2 & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  if ((*param_2 & 2) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = param_2[1];
  }
  iVar8 = iVar5 + 0xc;
  if (param_2[2] == 0) {
    uVar6 = iVar5 + 0xfU & 0xfffffffc;
    iVar8 = uVar6 + uVar4 * 8;
  }
  else {
    uVar6 = 0;
  }
  iVar1 = FUN_2011758c(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar8 + 3U & 0xfffffffc;
    iVar8 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar8);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = (undefined1 *)0xfffffffb;
    return (undefined4 *)0xfffffffb;
  }
  iVar1 = (int)param_1 * 4;
  if (uVar6 != 0) {
    param_1 = (undefined4 *)((int)piVar2 + uVar6);
  }
  *(int **)(&DAT_208dbea4 + iVar1) = piVar2;
  *(char *)(piVar2 + 1) = (char)uVar4;
  *(char *)((int)piVar2 + 5) = (char)iVar8;
  *(char *)((int)piVar2 + 6) = (char)uVar6;
  if (uVar6 == 0) {
    param_1 = (undefined4 *)param_2[2];
  }
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    FUN_201545f0((int)piVar2 + uVar7,param_2,0x10);
  }
  iVar8 = 0;
  if (0 < (int)uVar4) {
    do {
      *param_1 = 0;
      iVar8 = iVar8 + 1;
      param_1[1] = 0;
      param_1 = param_1 + 2;
    } while (iVar8 < (int)uVar4);
  }
  iVar1 = 0;
  iVar8 = iVar1;
  if (-1 < iVar5) {
    do {
      iVar1 = iVar8 + 1;
      *(undefined1 *)((int)piVar2 + iVar8 + 7) = 0;
      iVar8 = iVar1;
    } while (iVar1 <= iVar5);
    if (iVar5 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014f830;
    }
  }
  uVar3 = 0xff;
LAB_2014f830:
  *(undefined1 *)((int)piVar2 + iVar1 + 7) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== FUN_2014f8b8 @ 2014f8b8 (564 bytes)

uint FUN_2014f8b8(uint param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  iVar2 = 0x10;
  if (0x10 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  iVar5 = *(int *)(param_2 + 8);
  if (iVar5 != 0) {
    iVar2 = *(int *)(param_2 + 4);
  }
  if (iVar5 == 0 || iVar2 == 0) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  uVar8 = iVar5 + 3U & 0xfffffffc;
  if (uVar8 < 4) {
    uVar8 = 4;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x10;
    while (uVar9 = param_1, (&DAT_208dbf24)[param_1] != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if ((&DAT_208dbf24)[param_1] != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar9 = 0;
  }
  puVar6 = *(undefined4 **)(param_2 + 0xc);
  if ((puVar6 == (undefined4 *)0x0) &&
     (puVar6 = (undefined4 *)FUN_20154720(iVar2 * uVar8), puVar6 == (undefined4 *)0x0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  if ((*param_2 & 1) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 7;
  }
  iVar5 = FUN_2011758c(param_2);
  if (iVar5 == 0) {
    uVar10 = uVar7 + 0x17 & 0xfffffffc;
    uVar1 = uVar10;
  }
  else {
    uVar10 = 0;
    uVar1 = uVar7;
  }
  piVar3 = (int *)FUN_2015476c(uVar1 + 0x14);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  (&DAT_208dbf24)[param_1] = piVar3;
  if (uVar10 == 0) {
    *piVar3 = (int)param_2;
  }
  else {
    *piVar3 = (int)piVar3 + uVar10;
    FUN_201545f0((int)piVar3 + uVar10,param_2,0x14);
  }
  piVar3[1] = (int)puVar6;
  piVar3[2] = (int)puVar6;
  piVar3[3] = iVar2 * uVar8;
  *(undefined2 *)(piVar3 + 4) = *(undefined2 *)(param_2 + 4);
  iVar2 = *(int *)(param_2 + 4);
  while (iVar2 = iVar2 + -1, iVar2 != 0) {
    *puVar6 = (undefined4 *)((int)puVar6 + uVar8);
    puVar6 = (undefined4 *)((int)puVar6 + uVar8);
  }
  *puVar6 = 0;
  iVar2 = 0;
  iVar5 = 0;
  if (-1 < (int)uVar7) {
    do {
      iVar2 = iVar5 + 1;
      *(undefined1 *)((int)piVar3 + iVar5 + 0x12) = 0;
      iVar5 = iVar2;
    } while (iVar2 <= (int)uVar7);
    if (uVar7 == 0) {
      uVar4 = 0xfe;
      goto LAB_2014faac;
    }
  }
  uVar4 = 0xff;
LAB_2014faac:
  *(undefined1 *)((int)piVar3 + iVar2 + 0x12) = uVar4;
  software_interrupt(0);
  return uVar9;
}


// ===== FUN_2014fb04 @ 2014fb04 (520 bytes)

uint FUN_2014fb04(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if ((param_1 != 0) && ((param_1 == 0 || (8 < param_1)))) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 != 0) {
    if (*(int *)(&DAT_208dbf04 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar8 = 0;
  }
  else {
    param_1 = 8;
    iVar4 = DAT_208dbf24;
    while (uVar8 = param_1, iVar4 != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      iVar4 = *(int *)(&DAT_208dbf04 + param_1 * 4);
    }
  }
  iVar4 = *(int *)(param_2 + 8);
  iVar9 = *(int *)(param_2 + 4);
  if ((iVar4 == 0) && (iVar4 = FUN_20154720(iVar9), iVar4 == 0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar5 = iVar6 + 0x14;
  iVar1 = FUN_2011758c(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar6 + 0x17U & 0xfffffffc;
    iVar5 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar5);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  FUN_201530e4(iVar4,iVar9);
  *(int **)(&DAT_208dbf04 + param_1 * 4) = piVar2;
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
    uVar3 = extraout_r1;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    FUN_201545f0((int)piVar2 + uVar7,param_2,0x10);
    uVar3 = extraout_r1_00;
  }
  piVar2[1] = iVar4;
  piVar2[2] = iVar4;
  iVar4 = 0;
  if (-1 < iVar6) {
    uVar3 = 0;
  }
  piVar2[3] = iVar9;
  iVar9 = iVar4;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar9 + 1;
      *(undefined1 *)((int)piVar2 + iVar9 + 0x10) = uVar3;
      iVar9 = iVar4;
    } while (iVar4 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014fccc;
    }
  }
  uVar3 = 0xff;
LAB_2014fccc:
  *(undefined1 *)((int)piVar2 + iVar4 + 0x10) = uVar3;
  software_interrupt(0);
  return uVar8;
}


// ===== FUN_2014fd24 @ 2014fd24 (496 bytes)

uint FUN_2014fd24(uint param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar6 = *param_2;
  if (iVar6 == 3) {
    uVar7 = param_2[1];
  }
  else {
    uVar7 = 8;
  }
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x20 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  if (3 < iVar6) {
    DAT_208003d4 = 0xfffffff5;
    return 0xfffffff5;
  }
  if ((iVar6 == 3) && ((uVar7 == 0 || (8 < uVar7)))) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x20;
    iVar4 = DAT_208dc044;
    while (uVar8 = param_1, iVar4 != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      iVar4 = *(int *)(&DAT_208dbfc4 + param_1 * 4);
    }
  }
  else {
    if (*(int *)(&DAT_208dbfc4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar8 = 0;
  }
  if (iVar6 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 7;
  }
  iVar5 = iVar4 + 0x10;
  iVar2 = FUN_2011758c(param_2);
  if (iVar2 == 0) {
    uVar9 = iVar4 + 0x13U & 0xfffffffc;
    iVar5 = uVar9 + 0xc;
  }
  else {
    uVar9 = 0;
  }
  piVar3 = (int *)FUN_2015476c(iVar5);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbfc4 + param_1 * 4) = piVar3;
  if (uVar9 == 0) {
    *piVar3 = (int)param_2;
  }
  else {
    *piVar3 = (int)piVar3 + uVar9;
    FUN_201545f0((int)piVar3 + uVar9,param_2,0xc);
  }
  if (iVar6 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = (undefined1)uVar7;
  }
  *(undefined1 *)((int)piVar3 + 0xb) = uVar1;
  *(undefined1 *)((int)piVar3 + 10) = 0;
  iVar2 = 0;
  *(undefined2 *)(piVar3 + 2) = 0;
  piVar3[1] = iVar6;
  iVar6 = iVar2;
  if (-1 < iVar4) {
    do {
      iVar2 = iVar6 + 1;
      *(undefined1 *)((int)piVar3 + iVar6 + 0xc) = 0;
      iVar6 = iVar2;
    } while (iVar2 <= iVar4);
    if (iVar4 == 0) {
      uVar1 = 0xfe;
      goto LAB_2014fe9c;
    }
  }
  uVar1 = 0xff;
LAB_2014fe9c:
  *(undefined1 *)((int)piVar3 + iVar2 + 0xc) = uVar1;
  software_interrupt(0);
  return uVar8;
}


// ===== itron_acre_sem @ 2014ff2c (432 bytes)

uint itron_acre_sem(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x40 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  if ((0xffff < *(uint *)(param_2 + 8)) || (*(uint *)(param_2 + 8) < *(uint *)(param_2 + 4))) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x40;
    while (uVar6 = param_1, (&DAT_208dbca4)[param_1] != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if ((&DAT_208dbca4)[param_1] != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar6 = 0;
  }
  if ((*param_2 & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  iVar4 = iVar5 + 0xc;
  iVar1 = FUN_2011758c(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar5 + 0xfU & 0xfffffffc;
    iVar4 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar4);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  (&DAT_208dbca4)[param_1] = piVar2;
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
    uVar3 = extraout_r1;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    FUN_201545f0((int)piVar2 + uVar7,param_2,0x10);
    uVar3 = extraout_r1_00;
  }
  if (-1 < iVar5) {
    uVar3 = 0;
  }
  *(undefined2 *)(piVar2 + 1) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)((int)piVar2 + 6) = *(undefined2 *)(param_2 + 8);
  iVar4 = 0;
  iVar1 = iVar4;
  if (-1 < iVar5) {
    do {
      iVar4 = iVar1 + 1;
      *(undefined1 *)((int)piVar2 + iVar1 + 8) = uVar3;
      iVar1 = iVar4;
    } while (iVar4 <= iVar5);
    if (iVar5 == 0) {
      uVar3 = 0xfe;
      goto LAB_2015007c;
    }
  }
  uVar3 = 0xff;
LAB_2015007c:
  *(undefined1 *)((int)piVar2 + iVar4 + 8) = uVar3;
  software_interrupt(0);
  return uVar6;
}


// ===== itron_acre_tsk @ 201500f4 (488 bytes)

/* create task, id 0 = auto-assign; TCB table 0x208DBBA0 */

uint itron_acre_tsk(uint param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  
  if (DAT_208003da == '\0') {
    if (DAT_201659d0 < param_1) {
      DAT_208003d4 = 0xffffffee;
    }
    else {
      if (*(int *)(param_2 + 0xc) < 9) {
        software_interrupt(0);
        uVar5 = DAT_201659d0;
        if (param_1 == 0) {
          while (uVar7 = uVar5, *(int *)(&DAT_208dbba0 + uVar5 * 4) != 0) {
            uVar5 = uVar5 - 1;
            if (uVar5 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          if (*(int *)(&DAT_208dbba0 + param_1 * 4) != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar5 = param_1;
          uVar7 = 0;
        }
        iVar2 = FUN_2011758c(param_2);
        if (iVar2 == 0) {
          uVar8 = 0x44;
          iVar2 = 0x28;
        }
        else {
          uVar8 = 0x28;
          iVar2 = 0;
        }
        iVar3 = FUN_2015476c(uVar8);
        if (iVar3 == 0) {
          software_interrupt(0);
          DAT_208003d4 = 0xfffffffb;
          return 0xfffffffb;
        }
        puVar6 = *(uint **)(param_2 + 0x14);
        iVar9 = *(int *)(param_2 + 0x10);
        if ((puVar6 == (uint *)0x0) && (puVar6 = (uint *)FUN_20154704(iVar9), puVar6 == (uint *)0x0)
           ) {
          FUN_20154790(iVar3,uVar8);
          software_interrupt(0);
          DAT_208003d4 = 0xffffffdf;
          return 0xffffffdf;
        }
        *(int *)(&DAT_208dbba0 + uVar5 * 4) = iVar3;
        *(undefined1 *)(iVar3 + 5) = 0;
        *(undefined1 *)(iVar3 + 0x26) = 0;
        *(undefined2 *)(iVar3 + 0x24) = 0;
        if (iVar2 == 0) {
          *(byte **)(iVar3 + 0x18) = param_2;
        }
        else {
          *(int *)(iVar3 + 0x18) = iVar3 + iVar2;
          FUN_201545f0(iVar3 + iVar2,param_2,0x1c);
        }
        bVar1 = param_2[0xc];
        *(byte *)(iVar3 + 4) = bVar1;
        *(byte *)(iVar3 + 0x27) = bVar1;
        *(uint **)(iVar3 + 0x14) = puVar6;
        uVar4 = iVar9 - 0x48U >> 2;
        *(undefined4 *)(iVar3 + 0x1c) = 0;
        do {
          uVar4 = uVar4 - 1;
          *puVar6 = uVar5 << 0x18 | uVar5 << 0x10 | uVar5 << 8 | uVar5;
          puVar6 = puVar6 + 1;
        } while (uVar4 != 0);
        software_interrupt(0);
        if ((*param_2 & 2) != 0) {
          FUN_2014e73c(uVar5);
        }
        return uVar7;
      }
      DAT_208003d4 = 0xffffffef;
    }
  }
  else {
    DAT_208003d4 = 0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== FUN_201502f4 @ 201502f4 (436 bytes)

code * FUN_201502f4(uint param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int *piVar8;
  
  bVar2 = false;
  if (DAT_208003da == '\0') {
    if ((param_1 != 0) && (param_1 < 0x11)) {
      software_interrupt(0);
      piVar8 = (int *)(&DAT_208dbf24)[param_1];
      if (piVar8 == (int *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (piVar8[1] == 0) {
        pbVar6 = (byte *)((int)piVar8 + 0x12);
        bVar1 = *(byte *)((int)piVar8 + 0x12);
        while (uVar7 = (uint)bVar1, uVar7 < 0xfe) {
          while (uVar7 != 0) {
            puVar4 = *(undefined4 **)(&DAT_208dbba0 + uVar7 * 4);
            *(undefined4 *)*puVar4 = 0xffffffcd;
            if ((*(byte *)((int)puVar4 + 5) & 2) != 0) {
              FUN_20153ad4(puVar4,uVar7);
            }
            *(undefined1 *)((int)puVar4 + 5) = 0x10;
            if (*(char *)((int)puVar4 + 9) == '\0') {
              FUN_20154508(puVar4,uVar7);
              bVar2 = (bool)(bVar2 | *(char *)(puVar4 + 1) < DAT_208003df);
            }
            else {
              FUN_201539ec();
            }
            uVar7 = (uint)*pbVar6;
          }
          pbVar6 = pbVar6 + 1;
          bVar1 = *pbVar6;
        }
      }
      if (*(int *)(*piVar8 + 0xc) == 0) {
        FUN_20154744(piVar8[2],piVar8[3]);
      }
      iVar5 = 0x14;
      if (*(byte *)((int)piVar8 + 0x13) < 0xfe) {
        iVar5 = 0x1b;
      }
      iVar3 = FUN_2011758c(*piVar8);
      if (iVar3 == 0) {
        iVar5 = (iVar5 + 3U & 0xfffffffc) + 0x14;
      }
      FUN_20154790(piVar8,iVar5);
      (&DAT_208dbf24)[param_1] = 0;
      if (bVar2) {
        software_interrupt(0);
        return FUN_2015655c;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== FUN_201504d0 @ 201504d0 (384 bytes)

code * FUN_201504d0(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  
  bVar1 = false;
  if (DAT_208003da == '\0') {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      puVar7 = (undefined4 *)(&DAT_208dbca4)[param_1];
      if (puVar7 == (undefined4 *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (*(short *)(puVar7 + 1) == 0) {
        uVar5 = (uint)*(byte *)(puVar7 + 2);
        pbVar6 = (byte *)(puVar7 + 2);
        do {
          while (uVar5 != 0) {
            puVar3 = *(undefined4 **)(&DAT_208dbba0 + uVar5 * 4);
            *(undefined4 *)*puVar3 = 0xffffffcd;
            if ((*(byte *)((int)puVar3 + 5) & 2) != 0) {
              FUN_20153ad4(puVar3,uVar5);
            }
            *(undefined1 *)((int)puVar3 + 5) = 0x10;
            if (*(char *)((int)puVar3 + 9) == '\0') {
              FUN_20154508(puVar3,uVar5);
              bVar1 = (bool)(bVar1 | *(char *)(puVar3 + 1) < DAT_208003df);
            }
            else {
              FUN_201539ec();
            }
            uVar5 = (uint)*pbVar6;
          }
          pbVar6 = pbVar6 + 1;
          uVar5 = (uint)*pbVar6;
        } while (uVar5 < 0xfe);
      }
      iVar4 = 0xc;
      if (*(byte *)((int)puVar7 + 9) < 0xfe) {
        iVar4 = 0x13;
      }
      iVar2 = FUN_2011758c(*puVar7);
      if (iVar2 == 0) {
        iVar4 = (iVar4 + 3U & 0xfffffffc) + 0x10;
      }
      FUN_20154790(puVar7,iVar4);
      (&DAT_208dbca4)[param_1] = 0;
      if (!bVar1) {
        software_interrupt(0);
        return FUN_201567f4;
      }
      software_interrupt(0);
      return FUN_2015655c;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== FUN_20150678 @ 20150678 (164 bytes)

code * FUN_20150678(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 1) == 0) {
    if ((DAT_208003da != '\0') || (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01'))) {
      software_interrupt(0);
      DAT_208003d4 = 0xffffffe7;
      return (code *)0xffffffe7;
    }
    DAT_208003db = DAT_208003db | 9;
  }
  else if (((byte)DAT_208003cc & 0x80) != 0) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffe7;
    return (code *)0xffffffe7;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_dly_tsk @ 20150740 (172 bytes)

code * itron_dly_tsk(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
     (uVar1 = (uint)DAT_208dc18c, uVar1 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    iVar2 = *(int *)(&DAT_208dbba0 + uVar1 * 4);
    software_interrupt(0);
    if (param_1 != 0) {
      FUN_20154498(param_1,iVar2,uVar1);
      *(undefined1 *)(iVar2 + 5) = 0x32;
      FUN_201539ec(iVar2,uVar1);
      software_interrupt(0);
      return FUN_201566f0;
    }
    software_interrupt(0);
    return (code *)0x0;
  }
  DAT_208003d4 = 0xffffffe7;
  return (code *)0xffffffe7;
}


// ===== FUN_2015080c @ 2015080c (184 bytes)

code * FUN_2015080c(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 1) != 0) {
    if ((DAT_208003da != '\0') || (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01'))) {
      software_interrupt(0);
      DAT_208003d4 = 0xffffffe7;
      return (code *)0xffffffe7;
    }
    if ((DAT_208003db & 0x10) == 0) {
      DAT_208003db = DAT_208003db & 0xf6;
      if ((DAT_208003db == 0) && (DAT_208003d9 != '\0')) {
        software_interrupt(0);
        return FUN_20156748;
      }
    }
    else {
      DAT_208003db = DAT_208003db & 0xf7;
    }
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_201508ec @ 201508ec (264 bytes)

undefined1 * FUN_201508ec(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  cVar2 = DAT_208003da;
  if (DAT_208003da == '\0') {
    cVar2 = DAT_208003db;
  }
  if ((DAT_208003da == '\0' && cVar2 == '\0') && (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U)))
  {
    software_interrupt(0);
    uVar5 = (uint)DAT_208dc18c;
    iVar4 = *(int *)(&DAT_208dbba0 + uVar5 * 4);
    uVar1 = *(undefined1 *)(*(int *)(iVar4 + 0x18) + 0xc);
    *(undefined1 *)(iVar4 + 4) = uVar1;
    *(undefined1 *)(iVar4 + 0x27) = uVar1;
    puVar3 = *(undefined4 **)(iVar4 + 0x1c);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      *(undefined2 *)(puVar3 + 2) = 1;
      puVar3[1] = 0;
    }
    FUN_201539ec(iVar4,uVar5);
    if (*(short *)(iVar4 + 0x24) != 0) {
      FUN_20154930();
      *(undefined2 *)(iVar4 + 0x24) = 0;
    }
    if (*(char *)(iVar4 + 0x26) < '\x01') {
      *(undefined1 *)(iVar4 + 5) = 0;
    }
    else {
      *(char *)(iVar4 + 0x26) = *(char *)(iVar4 + 0x26) + -1;
      FUN_20156860(*(int *)(iVar4 + 0x14) + *(int *)(*(int *)(iVar4 + 0x18) + 0x10) + -0x48,
                   *(undefined4 *)(*(int *)(iVar4 + 0x18) + 4),iVar4,uVar5);
    }
    software_interrupt(0);
    return &DAT_2015677c;
  }
  DAT_208003d4 = 0xffffffe7;
  DAT_208003db = 0;
  return &DAT_208003db;
}


// ===== FUN_201509f4 @ 201509f4 (148 bytes)

undefined * FUN_201509f4(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_3[6] + 8);
  param_1[0xc] = param_1 + 0x12;
  *param_1 = param_2;
  uVar1 = DAT_208003ac;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_208003ac | 0x20;
  }
  param_1[0xf] = uVar1;
  uVar1 = FUN_201568b8();
  param_1[0xf] = uVar1 | param_1[0xf];
  param_1[0xd] = FUN_201508ec;
  param_1[0x11] = uVar2;
  *param_3 = (int)param_1;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  param_3[8] = 0;
  *(undefined1 *)((int)param_3 + 5) = 0x10;
  FUN_201538d4(&DAT_208dc18c + *(char *)((int)param_3 + 0x27),param_3,param_4);
  software_interrupt(0);
  return &DAT_2015677c;
}


// ===== FUN_20150aac @ 20150aac (212 bytes)

code * FUN_20150aac(uint param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 == 0;
  if (bVar2) {
    param_1 = (uint)DAT_208dc18c;
  }
  if ((DAT_201659d0 < param_1) || (DAT_208003da != '\0' && bVar2)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  if (DAT_208dc18c == param_1) {
    *param_2 = (int)*(char *)(*(int *)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) + 4);
    return (code *)0x0;
  }
  software_interrupt(0);
  iVar1 = *(int *)(&DAT_208dbba0 + param_1 * 4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 5) != '\0') {
      *param_2 = (int)*(char *)(iVar1 + 4);
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return (code *)0xffffffd7;
  }
  software_interrupt(0);
  return (code *)0xffffffd6;
}


// ===== FUN_20150ba0 @ 20150ba0 (44 bytes)

undefined4 FUN_20150ba0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_208dc18c;
  if (uVar1 == ((byte)DAT_201659d0 + 1 & 0xff)) {
    uVar1 = 0;
  }
  *param_1 = uVar1;
  return 0;
}


// ===== FUN_20150bd4 @ 20150bd4 (88 bytes)

code * FUN_20150bd4(short *param_1)

{
  short sVar1;
  uint uVar2;
  
  software_interrupt(0);
  uVar2 = DAT_208003c8 + DAT_208003c0;
  *(uint *)(param_1 + 2) = uVar2;
  sVar1 = DAT_208003bc + DAT_208003c4;
  *param_1 = sVar1;
  if (uVar2 < DAT_208003c8) {
    *param_1 = sVar1 + 1;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_20150c3c @ 20150c3c (44 bytes)

undefined4 FUN_20150c3c(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 8) == 0) {
    DAT_208003db = 0x13;
  }
  else {
    DAT_208003db = 0x1b;
  }
  return 0;
}


// ===== FUN_20150c70 @ 20150c70 (320 bytes)

code * FUN_20150c70(uint param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 unaff_r4;
  int *piVar5;
  undefined4 unaff_lr;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar3 = (&DAT_208dbf24)[param_1];
  if (iVar3 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (((((uint)param_2 & 3) == 0) && (*(int **)(iVar3 + 8) <= param_2)) &&
     (param_2 < (int *)((int)*(int **)(iVar3 + 8) + *(int *)(iVar3 + 0xc)))) {
    if (*(int *)(iVar3 + 4) == 0) {
      pbVar4 = (byte *)(iVar3 + 0x12);
      bVar1 = *(byte *)(iVar3 + 0x12);
      while (uVar2 = (uint)bVar1, uVar2 < 0xfe) {
        if (uVar2 != 0) {
          piVar5 = *(int **)(&DAT_208dbba0 + uVar2 * 4);
          **(uint **)(*piVar5 + 0xc) = (uint)param_2;
          if ((*(byte *)((int)piVar5 + 5) & 2) != 0) {
            FUN_20153ad4(piVar5,uVar2);
          }
          *(undefined1 *)((int)piVar5 + 5) = 0x10;
          if (*(char *)((int)piVar5 + 9) != '\0') {
            FUN_201539ec();
            software_interrupt(0);
            return FUN_201567f4;
          }
          iVar3 = piVar5[1];
          FUN_20153a38(&DAT_208dc18c + (char)iVar3,piVar5,uVar2,&DAT_208dc18c + (char)iVar3,unaff_r4
                       ,unaff_lr);
          if ((int)(char)iVar3 < (int)DAT_208003df) {
            software_interrupt(0);
            return FUN_2015655c;
          }
          software_interrupt(0);
          return FUN_201567f4;
        }
        pbVar4 = pbVar4 + 1;
        bVar1 = *pbVar4;
      }
    }
    *param_2 = *(int *)(iVar3 + 4);
    *(int **)(iVar3 + 4) = param_2;
    *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 1;
    software_interrupt(0);
    return FUN_201567f4;
  }
  software_interrupt(0);
  return (code *)0xffffffef;
}


// ===== FUN_20150dcc @ 20150dcc (276 bytes)

code * FUN_20150dcc(uint param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  if (param_1 == 0) {
    if (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U)) {
      software_interrupt(0);
      uVar2 = (uint)DAT_208dc18c;
      iVar1 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
      if ((int)*(char *)(iVar1 + 0x27) == (int)DAT_208003df) {
        pbVar3 = *(byte **)(iVar1 + 0x10);
      }
      else {
        pbVar3 = &DAT_208dc18c + *(char *)(iVar1 + 0x27);
        uVar2 = (uint)*pbVar3;
        if (uVar2 == 0) {
          software_interrupt(0);
          return FUN_201567f4;
        }
        iVar1 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
      }
      if (*(byte *)(iVar1 + 6) == uVar2) {
        software_interrupt(0);
        return FUN_201567f4;
      }
      *pbVar3 = *(byte *)(iVar1 + 6);
      software_interrupt(0);
      return FUN_2015655c;
    }
  }
  else if (param_1 < 9) {
    software_interrupt(0);
    uVar2 = (uint)(&DAT_208dc18c)[param_1];
    if (((uVar2 != 0) && (*(byte *)(*(int *)(&DAT_208dbba0 + uVar2 * 4) + 6) != uVar2)) &&
       ((&DAT_208dc18c)[param_1] = *(byte *)(*(int *)(&DAT_208dbba0 + uVar2 * 4) + 6),
       (int)param_1 <= (int)DAT_208003df)) {
      software_interrupt(0);
      return FUN_2015655c;
    }
    software_interrupt(0);
    return FUN_201567f4;
  }
  DAT_208003d4 = 0xffffffef;
  return (code *)0xffffffef;
}


// ===== itron_set_flg @ 20150f00 (704 bytes)

code * itron_set_flg(uint param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_r4;
  int *piVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 unaff_lr;
  bool bVar10;
  
  if (param_2 == 0) {
    DAT_208003d4 = (code *)0x0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      iVar8 = *(int *)(&DAT_208dbda4 + param_1 * 4);
      if (iVar8 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      for (pbVar9 = (byte *)(iVar8 + 9); uVar7 = (uint)*pbVar9, uVar7 == 0; pbVar9 = pbVar9 + 1) {
      }
      if (0xfd < uVar7) {
        *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | param_2;
        software_interrupt(0);
        return FUN_201567f4;
      }
      piVar6 = *(int **)(&DAT_208dbba0 + uVar7 * 4);
      uVar5 = (uint)*(byte *)((int)piVar6 + 7);
      bVar10 = uVar5 == uVar7;
      if (bVar10) {
        uVar5 = (uint)*(byte *)(iVar8 + 8);
      }
      if (!bVar10 || (uVar5 & 2) != 0) {
        bVar10 = false;
        param_2 = param_2 | *(uint *)(iVar8 + 4);
LAB_20150fa4:
        piVar6 = *(int **)(&DAT_208dbba0 + (uint)*pbVar9 * 4);
        bVar1 = *(byte *)((int)piVar6 + 7);
        uVar7 = (uint)*pbVar9;
        do {
          bVar2 = *(byte *)((int)piVar6 + 5);
          bVar3 = *(byte *)((int)piVar6 + 6);
          if ((bVar2 & 1) == 0) {
            if ((*(uint *)(*piVar6 + 8) & ~param_2) == 0) goto LAB_2015109c;
          }
          else if ((*(uint *)(*piVar6 + 8) & param_2) != 0) {
LAB_2015109c:
            **(uint **)(*piVar6 + 0xc) = param_2;
            if ((bVar2 & 2) != 0) {
              FUN_20153ad4(piVar6,uVar7);
            }
            *(undefined1 *)((int)piVar6 + 5) = 0x10;
            if (*(char *)((int)piVar6 + 9) == '\0') {
              iVar4 = (int)(char)piVar6[1];
              if (iVar4 < DAT_208003df) {
                bVar10 = (bool)(bVar10 | iVar4 < DAT_208003df);
              }
              FUN_20153a38(&DAT_208dc18c + iVar4,piVar6,uVar7);
            }
            else {
              FUN_201539ec(piVar6,uVar7);
            }
            if ((bVar2 & 4) != 0) {
              *(undefined4 *)(iVar8 + 4) = 0;
              if (!bVar10) {
                software_interrupt(0);
                return FUN_201567f4;
              }
              software_interrupt(0);
              return FUN_2015655c;
            }
          }
          if (bVar1 == uVar7) goto LAB_2015116c;
          piVar6 = *(int **)(&DAT_208dbba0 + (uint)bVar3 * 4);
          uVar7 = (uint)bVar3;
        } while( true );
      }
      bVar1 = *(byte *)((int)piVar6 + 5);
      if ((bVar1 & 1) == 0) {
        param_2 = *(uint *)(iVar8 + 4) | param_2;
        if ((*(uint *)(*piVar6 + 8) & ~param_2) != 0) goto LAB_20151030;
      }
      else {
        param_2 = *(uint *)(iVar8 + 4) | param_2;
        if ((*(uint *)(*piVar6 + 8) & param_2) == 0) {
LAB_20151030:
          *(uint *)(iVar8 + 4) = param_2;
          software_interrupt(0);
          return FUN_201567f4;
        }
      }
      **(uint **)(*piVar6 + 0xc) = param_2;
      if ((bVar1 & 4) != 0) {
        param_2 = 0;
      }
      *(uint *)(iVar8 + 4) = param_2;
      if ((bVar1 & 2) != 0) {
        FUN_20153ad4(piVar6,uVar7);
      }
      *(undefined1 *)((int)piVar6 + 5) = 0x10;
      if (*(char *)((int)piVar6 + 9) == '\0') {
        iVar8 = piVar6[1];
        FUN_20153a38(&DAT_208dc18c + (char)iVar8,piVar6,uVar7,&DAT_208dc18c + (char)iVar8,unaff_r4,
                     unaff_lr);
        if ((int)DAT_208003df <= (int)(char)iVar8) {
          software_interrupt(0);
          return FUN_201567f4;
        }
        software_interrupt(0);
        return FUN_2015655c;
      }
      FUN_201539ec();
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  return DAT_208003d4;
LAB_2015116c:
  do {
    pbVar9 = pbVar9 + 1;
  } while (*pbVar9 == 0);
  if (0xfd < *pbVar9) {
    *(uint *)(iVar8 + 4) = param_2;
    if (!bVar10) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  goto LAB_20150fa4;
}


// ===== FUN_201511e8 @ 201511e8 (260 bytes)

code * FUN_201511e8(uint param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 unaff_r4;
  uint uVar5;
  undefined4 unaff_lr;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar3 = (&DAT_208dbca4)[param_1];
  if (iVar3 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  sVar2 = *(short *)(iVar3 + 4);
  if (sVar2 == 0) {
    pbVar4 = (byte *)(iVar3 + 8);
    do {
      uVar5 = (uint)*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (uVar5 == 0);
    if (uVar5 < 0xfe) {
      iVar3 = *(int *)(&DAT_208dbba0 + uVar5 * 4);
      if ((*(byte *)(iVar3 + 5) & 2) != 0) {
        FUN_20153ad4(iVar3,uVar5);
      }
      *(undefined1 *)(iVar3 + 5) = 0x10;
      if (*(char *)(iVar3 + 9) != '\0') {
        FUN_201539ec();
        software_interrupt(0);
        return FUN_201567f4;
      }
      cVar1 = *(char *)(iVar3 + 4);
      FUN_20153a38(&DAT_208dc18c + cVar1,iVar3,uVar5,&DAT_208dc18c + cVar1,unaff_r4,unaff_lr);
      if ((int)cVar1 < (int)DAT_208003df) {
        software_interrupt(0);
        return FUN_2015655c;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  *(short *)(iVar3 + 4) = sVar2 + 1;
  if (sVar2 == *(short *)(iVar3 + 6)) {
    *(short *)(iVar3 + 4) = *(short *)(iVar3 + 6);
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return FUN_201567f4;
}

