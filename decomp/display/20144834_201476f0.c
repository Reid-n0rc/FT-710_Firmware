// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20144834 @ 20144834 (40 bytes)

undefined4 FUN_20144834(int param_1)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  FUN_2014d98c(param_1);
  if (param_1 < 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_2014485c @ 2014485c (28 bytes)

undefined4 FUN_2014485c(undefined4 param_1,undefined4 param_2)

{
  DAT_20808ba4 = param_1;
  FUN_2014d98c();
  return param_2;
}


// ===== FUN_20144878 @ 20144878 (32 bytes)

undefined4 FUN_20144878(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 0x442) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20144898 @ 20144898 (32 bytes)

undefined4 FUN_20144898(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_201448b8 @ 201448b8 (96 bytes)

undefined4 FUN_201448b8(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (1 < uVar1) {
    iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    FUN_20156260((param_2 -
                 (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                          (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 == 1) {
      return 1;
    }
  }
  return 0;
}


// ===== FUN_20144918 @ 20144918 (56 bytes)

undefined4 FUN_20144918(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = DAT_20808ba0;
  do {
    if (*(char *)((int)piVar1 + 0x11) == param_1) {
      if (param_2 != (int *)0x0) {
        *param_2 = (int)piVar1;
      }
      return 0;
    }
    piVar1 = (int *)*piVar1;
  } while (piVar1 != (int *)0x0);
  return 0xfffffff4;
}


// ===== FUN_20144950 @ 20144950 (32 bytes)

undefined4 FUN_20144950(int param_1)

{
  undefined4 uVar1;
  
  if ((((int)*(char *)(param_1 + 0x68) & 1U) == 0) ||
     (((int)*(char *)(param_1 + 0x68) & 0x80U) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffed;
  }
  return uVar1;
}


// ===== FUN_20144970 @ 20144970 (16 bytes)

uint FUN_20144970(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x68) & 0x20;
  if ((*(byte *)(param_1 + 0x68) & 0x20) != 0) {
    uVar1 = 0xffffffc6;
  }
  return uVar1;
}


// ===== FUN_20144980 @ 20144980 (76 bytes)

int FUN_20144980(int param_1,uint param_2)

{
  int iVar1;
  
  if (1 < param_2) {
    iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    return *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + iVar1 +
           (param_2 - 2) * (uint)*(ushort *)(param_1 + 4) + (uint)*(ushort *)(param_1 + 6);
  }
  return 0;
}


// ===== FUN_201449cc @ 201449cc (68 bytes)

int FUN_201449cc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar1 = FUN_20156260(param_2 - (iVar1 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                                          (uint)*(ushort *)(param_1 + 6)),
                       *(undefined2 *)(param_1 + 4));
  return iVar1 + 2;
}


// ===== FUN_20144a10 @ 20144a10 (176 bytes)

undefined4 FUN_20144a10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_2014dd18(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      FUN_20144800(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,1,param_2,param_3,param_4);
    iVar2 = FUN_2014dd34(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      FUN_20144800(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      FUN_20144800(0);
      return 0;
    }
  }
  FUN_20144800(0xfffffff8,0);
  return 0xfffffff8;
}


// ===== FUN_20144ac0 @ 20144ac0 (176 bytes)

undefined4 FUN_20144ac0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_2014dd18(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      FUN_20144800(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,2,param_2,param_3,param_4);
    iVar2 = FUN_2014dd34(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      FUN_20144800(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      FUN_20144800(0);
      return 0;
    }
  }
  FUN_20144800(0xfffffff7,0);
  return 0xfffffff7;
}


// ===== FUN_20144b74 @ 20144b74 (144 bytes)

undefined4 FUN_20144b74(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar2 = FUN_20144ac0(param_1,param_2,param_3,1);
    return uVar2;
  }
  iVar1 = FUN_20143f78(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffbb;
  }
  else {
    iVar1 = __aeabi_uidivmod(iVar1 + -1,*(undefined2 *)(param_1 + 0x52));
    uVar3 = iVar1 + 1U & 0xffff;
    FUN_20144268(param_1,uVar3);
    iVar1 = (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) *
            (uint)*(ushort *)(param_1 + 0x50) + *(int *)(param_1 + 0x4c) + uVar3 * 2;
    *(ushort *)(iVar1 + -2) = *(ushort *)(iVar1 + -2) | 0x8000;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_20144c04 @ 20144c04 (88 bytes)

undefined4 FUN_20144c04(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
  iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = FUN_20144b74(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== FUN_20144c5c @ 20144c5c (168 bytes)

int FUN_20144c5c(int param_1,undefined4 param_2,int *param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  uint local_18;
  
  local_18 = param_4;
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar2 = FUN_20144a10(param_1,param_2,*param_3,1);
    return iVar2;
  }
  iVar2 = FUN_20143f78(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_20144000(param_1,param_2,&local_18);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else {
    local_18 = CONCAT22(local_18._2_2_,(short)iVar2);
  }
  *param_3 = ((local_18 & 0xffff) - 1) * *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x4c) +
             (uint)*(ushort *)(param_1 + 0x50) * 4;
  sVar1 = __aeabi_uidivmod((local_18 & 0xffff) - 1,*(undefined2 *)(param_1 + 0x52));
  local_18 = CONCAT22(local_18._2_2_,sVar1 + 1);
  FUN_20144268(param_1);
  return 0;
}


// ===== FUN_20144d04 @ 20144d04 (88 bytes)

undefined4 FUN_20144d04(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
  iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = FUN_20144c5c(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== FUN_20144d5c @ 20144d5c (348 bytes)

int FUN_20144d5c(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  FUN_2014d148(param_1,0,0x20,*(undefined4 *)(param_3 + 0x6c));
  FUN_2014d148(param_1 + 1,0xffffffff,10,*(undefined4 *)(param_3 + 0x6c));
  FUN_2014d148(param_1 + 0xe,0xffffffff,0xc,*(undefined4 *)(param_3 + 0x6c));
  FUN_2014d148(param_1 + 0x1c,0xffffffff,4,*(undefined4 *)(param_3 + 0x6c));
  iVar2 = 0;
  pcVar3 = (char *)(param_1 + 1);
  iVar1 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) {
      *pcVar3 = '\0';
      pcVar3[1] = '\0';
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 5);
  pcVar3 = (char *)(param_1 + 0xe);
  iVar2 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) goto LAB_20144eac;
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 6);
  pcVar3 = (char *)(param_1 + 0x1c);
  iVar2 = 0;
  while ((*param_2 != '\0' || (param_2[1] != '\0'))) {
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
    if (1 < iVar2) {
      return iVar1;
    }
  }
LAB_20144eac:
  *pcVar3 = '\0';
  pcVar3[1] = '\0';
  return iVar1;
}


// ===== FUN_20144eb8 @ 20144eb8 (60 bytes)

uint FUN_20144eb8(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    pbVar1 = (byte *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 + *pbVar1;
    uVar3 = (uVar3 & 1) << 7 | (uVar3 & 0xff) >> 1;
  } while (iVar2 < 10);
  return *(byte *)(param_1 + iVar2) + uVar3 & 0xff;
}


// ===== FUN_20144ef4 @ 20144ef4 (432 bytes)

int FUN_20144ef4(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_28;
  
  *(undefined1 *)(param_3 + 0xc) = 0;
  local_28 = (byte *)(param_6 + 0xe0c);
  iVar2 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  iVar3 = FUN_20144d04(param_1,iVar2,&local_28);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = FUN_20144eb8(param_3);
  FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  pbVar4 = local_28 + extraout_r1 * 0x20;
  FUN_2014d128(pbVar4,param_3,0x20);
  if (pbVar4 == local_28) {
    iVar3 = FUN_20144c04(param_1,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (iVar2 == 0 || param_5 == 1) {
      return 0;
    }
    iVar2 = iVar2 + -1;
    iVar3 = FUN_20144d04(param_1,iVar2,&local_28);
    if (iVar3 != 0) {
      return iVar3;
    }
    pbVar4 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
  }
  uVar6 = 1;
  if (1 < param_5) {
    iVar3 = iVar2;
    do {
      pbVar5 = pbVar4 + -0x20;
      iVar2 = FUN_20144d5c(pbVar5,param_4,param_1);
      *pbVar5 = (byte)uVar6;
      param_4 = param_4 + iVar2 * 2;
      pbVar4[-0x15] = 0xf;
      pbVar4[-0x13] = bVar1;
      iVar2 = iVar3;
      if ((pbVar5 == local_28) && (uVar6 != param_5 - 1)) {
        iVar2 = iVar3 + -1;
        iVar3 = FUN_20144c04(param_1,iVar3);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = FUN_20144d04(param_1,iVar2,&local_28);
        if (iVar3 != 0) {
          return iVar3;
        }
        pbVar5 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
      }
      uVar6 = uVar6 + 1 & 0xff;
      pbVar4 = pbVar5;
      iVar3 = iVar2;
    } while (uVar6 < param_5);
    if (1 < param_5) {
      *pbVar5 = *pbVar5 | 0x40;
    }
  }
  iVar2 = FUN_20144c04(param_1,iVar2,local_28);
  return iVar2;
}


// ===== FUN_201450a4 @ 201450a4 (124 bytes)

undefined4 FUN_201450a4(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_2014d148(param_1,0x20,0xb,*(undefined4 *)(param_3 + 0x6c));
  uVar2 = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  uVar3 = 0;
  do {
    cVar1 = *(char *)(param_2 + uVar3);
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '.') {
      if (8 < uVar3) {
        return 0xffffffff;
      }
      uVar2 = 7;
    }
    else {
      *(char *)(param_1 + uVar2) = cVar1;
    }
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar3 < 0xc && uVar2 < 0xc);
  return 0;
}


// ===== FUN_20145120 @ 20145120 (100 bytes)

undefined4 FUN_20145120(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_8 [8];
  
  builtin_strncpy(local_8,"+,;=[]",7);
  local_8[7] = '\0';
  iVar2 = 0;
  do {
    if (*param_1 == local_8[iVar2]) {
      return 1;
    }
    iVar1 = iVar2 + 1;
    iVar2 = iVar2 + 1;
  } while (local_8[iVar1] != '\0');
  return 0;
}


// ===== FUN_2014518c @ 2014518c (200 bytes)

void FUN_2014518c(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (uint)CONCAT11(uVar1,param_1[1]);
  if (uVar2 - 0x8281 < 0x1a) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x21;
  }
  else if (uVar2 - 0x83bf < 0x18) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x20;
  }
  else if (uVar2 - 0x8470 < 0xf) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x30;
  }
  else if (uVar2 - 0x8480 < 0x12) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x31;
  }
  else if (uVar2 - 0xfa40 < 10) {
    uVar2 = uVar2 - 0x72ec;
    *param_2 = (char)(uVar2 >> 8);
  }
  else {
    *param_2 = uVar1;
    uVar2 = (uint)(byte)param_1[1];
  }
  param_2[1] = (char)uVar2;
  return;
}


// ===== FUN_20145254 @ 20145254 (804 bytes)

undefined4 FUN_20145254(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  
  bVar3 = false;
  uVar9 = 0;
  iVar8 = 0;
  cVar2 = *param_1;
  pcVar7 = param_1;
  cVar1 = cVar2;
  while (pcVar5 = param_1, cVar1 != '\0') {
    iVar8 = iVar8 + 1;
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar7;
  }
  while (cVar2 != '\0') {
    iVar4 = FUN_20145120(pcVar5);
    if (iVar4 != 0) {
      uVar9 = 1;
      bVar3 = true;
    }
    cVar2 = pcVar5[1];
    pcVar5 = pcVar5 + 1;
  }
  iVar4 = FUN_2014d338(param_1,0x20);
  if (iVar4 != 0) {
    uVar9 = 1;
    bVar3 = true;
  }
  pcVar5 = (char *)FUN_2014d338(param_1,0x2e);
  if (pcVar5 != (char *)0x0) {
    iVar4 = 0;
    cVar1 = *pcVar7;
    while (cVar1 != '.') {
      iVar4 = iVar4 + 1;
      pcVar7 = pcVar7 + -1;
      cVar1 = *pcVar7;
    }
    if ((pcVar7 != pcVar5) || (4 < iVar4)) {
      uVar9 = 1;
      bVar3 = true;
    }
    iVar4 = FUN_2014d220(pcVar7);
    iVar8 = iVar8 - iVar4;
  }
  bVar10 = iVar8 == 8;
  if (iVar8 < 9) {
    bVar10 = !bVar3;
  }
  else {
    uVar9 = 1;
  }
  if (bVar10) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      if ((int)*param_1 - 0x61U < 0x1a) {
        pcVar7 = param_2 + 1;
        *param_2 = *param_1 + -0x20;
        uVar9 = 1;
        pcVar5 = param_1 + 1;
      }
      else {
        iVar8 = FUN_2014ca90(*param_1);
        if (iVar8 == 0) {
          iVar8 = FUN_20145120(param_1);
          if (iVar8 == 0) {
            pcVar5 = param_1 + 1;
            pcVar7 = param_2 + 1;
            *param_2 = *param_1;
          }
          else {
            uVar9 = 1;
            pcVar7 = param_2 + 1;
            *param_2 = '_';
            pcVar5 = param_1 + 1;
          }
        }
        else {
          FUN_2014518c(param_1,param_2);
          uVar9 = 1;
          pcVar7 = param_2 + 2;
          pcVar5 = param_1 + 2;
        }
      }
      param_1 = pcVar5;
      param_2 = pcVar7;
      cVar1 = *pcVar5;
    }
  }
  else {
    iVar8 = FUN_2014d220(param_3);
    iVar4 = 0;
    while ((iVar4 < 7 - iVar8 && (param_1 != pcVar7))) {
      if ((int)*param_1 - 0x61U < 0x1a) {
        *param_2 = *param_1 + -0x20;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
      else {
        iVar6 = FUN_2014ca90(*param_1);
        if (iVar6 == 0) {
          iVar6 = FUN_20145120(param_1);
          if (iVar6 == 0) {
            cVar1 = *param_1;
            if (cVar1 == '.' || cVar1 == ' ') {
              param_1 = param_1 + 1;
              iVar4 = iVar4 + -1;
              goto LAB_20145474;
            }
            *param_2 = cVar1;
          }
          else {
            *param_2 = '_';
          }
          param_2 = param_2 + 1;
          param_1 = param_1 + 1;
        }
        else {
          FUN_2014518c(param_1,param_2);
          param_2 = param_2 + 2;
          param_1 = param_1 + 2;
          iVar4 = iVar4 + 1;
        }
      }
LAB_20145474:
      iVar4 = iVar4 + 1;
    }
    if (7 - iVar8 < iVar4) {
      param_2 = param_2 + -2;
    }
    *param_2 = '~';
    cVar1 = *param_3;
    while (param_2 = param_2 + 1, cVar1 != '\0') {
      *param_2 = cVar1;
      param_3 = param_3 + 1;
      cVar1 = *param_3;
    }
    iVar8 = 0;
    do {
      cVar1 = *pcVar7;
      if (cVar1 == 0) break;
      if ((int)cVar1 - 0x61U < 0x1a) {
        *param_2 = cVar1 + -0x20;
        pcVar7 = pcVar7 + 1;
        param_2 = param_2 + 1;
      }
      else {
        iVar4 = FUN_2014ca90(*pcVar7);
        if (iVar4 == 0) {
          iVar4 = FUN_20145120(pcVar7);
          if (iVar4 == 0) {
            if (*pcVar7 == ' ') {
              pcVar7 = pcVar7 + 1;
              iVar8 = iVar8 + -1;
              goto LAB_2014553c;
            }
            *param_2 = *pcVar7;
          }
          else {
            *param_2 = '_';
          }
          param_2 = param_2 + 1;
          pcVar7 = pcVar7 + 1;
        }
        else {
          FUN_2014518c(pcVar7,param_2);
          param_2 = param_2 + 2;
          pcVar7 = pcVar7 + 2;
          iVar8 = iVar8 + 1;
        }
      }
LAB_2014553c:
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
    if (4 < iVar8) {
      param_2 = param_2 + -2;
    }
  }
  *param_2 = '\0';
  return uVar9;
}


// ===== FUN_20145578 @ 20145578 (128 bytes)

void FUN_20145578(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  *param_1 = '\0';
  uVar5 = 100000;
  pcVar3 = param_1;
  if (999999 < param_2) {
    param_2 = 999999;
  }
  do {
    cVar1 = FUN_20156260(param_2,uVar5);
    iVar2 = (int)cVar1;
    if (iVar2 < 1) {
      pcVar4 = pcVar3;
      if ((iVar2 == 0) && (*param_1 != '\0')) {
        pcVar4 = pcVar3 + 1;
        *pcVar3 = '0';
      }
    }
    else {
      param_2 = param_2 - iVar2 * uVar5;
      *pcVar3 = cVar1 + '0';
      pcVar4 = pcVar3 + 1;
    }
    uVar5 = uVar5 / 10;
    pcVar3 = pcVar4;
  } while (uVar5 != 0);
  *pcVar4 = '\0';
  return;
}


// ===== FUN_201455f8 @ 201455f8 (276 bytes)

int FUN_201455f8(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int extraout_r1;
  uint uVar6;
  bool bVar7;
  byte *local_20;
  
  local_20 = (byte *)(param_4 + 0xe0c);
  iVar3 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  iVar4 = FUN_20144d04(param_1,iVar3,&local_20);
  if (iVar4 == 0) {
    FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 5);
    if (param_3 == 1) {
      param_3 = 2;
    }
    uVar6 = 0;
    pbVar5 = local_20 + extraout_r1 * 0x20;
    do {
      bVar2 = *pbVar5;
      *pbVar5 = 0xe5;
      if (pbVar5 == local_20) {
        iVar4 = FUN_20144c04(param_1,iVar3);
        if (iVar4 != 0) {
          return iVar4;
        }
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = iVar3 + -1;
        iVar4 = FUN_20144d04(param_1,iVar3,&local_20);
        if (iVar4 != 0) {
          return iVar4;
        }
        pbVar5 = local_20 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
      }
      pbVar1 = pbVar5 + -0x15;
      pbVar5 = pbVar5 + -0x20;
      if (*pbVar1 != 0xf) break;
      uVar6 = uVar6 + 1 & 0xff;
      bVar7 = uVar6 == param_3;
      if (param_3 <= uVar6) {
        bVar7 = (bVar2 & 0x40) == 0x40;
      }
    } while (!bVar7);
    iVar4 = FUN_20144c04(param_1,iVar3,local_20);
  }
  return iVar4;
}


// ===== FUN_2014570c @ 2014570c (88 bytes)

undefined4 FUN_2014570c(char *param_1)

{
  char *pcVar1;
  char local_18 [12];
  
  FUN_201450a4(local_18);
  pcVar1 = local_18;
  while( true ) {
    if (local_18[0] == '\0') {
      return 0;
    }
    if (*pcVar1 != *param_1) break;
    local_18[0] = pcVar1[1];
    param_1 = param_1 + 1;
    pcVar1 = pcVar1 + 1;
  }
  return 0xffffff9d;
}


// ===== FUN_20145764 @ 20145764 (384 bytes)

int FUN_20145764(char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char local_28 [12];
  
  iVar7 = 0;
  iVar6 = 0;
  iVar3 = 0;
  do {
    if (param_1[iVar3 + 8] != param_2[iVar3 + 8]) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  local_28[8] = 0;
  iVar3 = 7;
  bVar2 = false;
  do {
    cVar1 = param_1[iVar3];
    if (cVar1 == ' ') {
      local_28[iVar3] = '\0';
    }
    else {
      local_28[iVar3] = cVar1;
    }
    if (cVar1 == '~' && !bVar2) {
      bVar2 = true;
      local_28[iVar3] = '\0';
    }
    if (cVar1 == ' ') {
      iVar6 = iVar6 + 1;
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  iVar3 = 0;
  iVar5 = 0;
  do {
    cVar1 = local_28[iVar3];
    if (cVar1 == '\0') break;
    if (cVar1 == '~') {
      iVar5 = iVar5 + 1;
    }
    if (cVar1 != param_2[iVar3]) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  iVar3 = 7;
  do {
    cVar1 = *param_1;
    if (iVar6 == 0) {
      if (cVar1 == '~') {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
      }
      if (cVar1 != *param_2) {
        return 0;
      }
    }
    else {
      if ((cVar1 != *param_2) && (iVar4 = FUN_2014ca90(*param_2), iVar4 == 0)) {
        return 0;
      }
      if (*param_1 == '~') {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
      }
    }
    iVar3 = iVar3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (0 < iVar3);
  if (iVar6 <= iVar3) {
    iVar3 = iVar3 - iVar6;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    param_1 = param_1 + 1;
    iVar7 = (int)*param_1 + iVar7 * 10 + -0x30;
  }
  return iVar7;
}


// ===== FUN_201458e4 @ 201458e4 (536 bytes)

undefined4 FUN_201458e4(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = param_1[1];
  if (bVar1 == 0) {
    if ((param_2[1] == 0) &&
       (((uVar2 = (uint)*param_1, uVar2 - 0x41 < 0x1a && (uVar2 + 0x20 == (uint)*param_2)) ||
        ((uVar2 - 0x61 < 0x1a && (uVar2 - 0x20 == (uint)*param_2)))))) {
      return 1;
    }
  }
  else if (bVar1 == 0xff) {
    if (param_2[1] == 0xff) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x21 < 0x1a) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0x41 < 0x1a) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
    }
  }
  else if (bVar1 == 3) {
    if (param_2[1] == 3) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x91 < 0x11) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xa3 < 7) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xb1 < 0x11) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xc3 < 7) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
    }
  }
  else if (bVar1 == 4) {
    if (param_2[1] == 4) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x10 < 0x20) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 == 1) && (*param_2 == 0x51)) {
        return 1;
      }
      if ((uVar2 - 0x30 < 0x20) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 == 0x51) && (*param_2 == 1)) {
        return 1;
      }
    }
  }
  else if ((bVar1 == 0x21) && (param_2[1] == 0x21)) {
    uVar2 = (uint)*param_1;
    if ((uVar2 - 0x60 < 10) && (uVar2 + 0x10 == (uint)*param_2)) {
      return 1;
    }
    if ((uVar2 - 0x70 < 10) && (uVar2 - 0x10 == (uint)*param_2)) {
      return 1;
    }
  }
  return 0;
}


// ===== FUN_20145afc @ 20145afc (232 bytes)

int FUN_20145afc(int param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar3 = (char *)(param_1 + 1);
  iVar2 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) goto LAB_20145bd8;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 5);
  pcVar3 = (char *)(param_1 + 0xe);
  iVar4 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) goto LAB_20145bd8;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 6);
  pcVar3 = (char *)(param_1 + 0x1c);
  iVar4 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) break;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 2);
LAB_20145bd8:
  *param_2 = '\0';
  return iVar2;
}


// ===== FUN_20145be4 @ 20145be4 (512 bytes)

int FUN_20145be4(int param_1,int param_2,short *param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  short *psVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined8 uVar7;
  byte *local_50;
  short local_4c [14];
  int local_30;
  uint local_2c;
  
  local_30 = -1;
  local_50 = (byte *)(param_6 + 0xe0c);
  uVar4 = *(uint *)(param_1 + 0x6c) >> 5;
  uVar7 = FUN_20156260(param_2,uVar4);
  iVar6 = (int)uVar7;
  if ((param_2 != 0) && ((int)((ulonglong)uVar7 >> 0x20) == 0)) {
    iVar6 = FUN_20156260(param_2 + -1,uVar4);
  }
  iVar1 = FUN_20144d04(param_1,iVar6,&local_50);
  if (iVar1 == 0) {
    uVar4 = *(uint *)(param_1 + 0x6c);
    FUN_20156260(param_2,uVar4 >> 5);
    if (extraout_r1 == 0) {
      uVar4 = uVar4 & 0xffffffe0;
    }
    else {
      uVar4 = extraout_r1 * 0x20;
    }
    pbVar5 = local_50 + uVar4;
    if (param_2 == 0) {
      pbVar5 = local_50 + 0x20;
    }
    uVar4 = 1;
    if (1 < param_4) {
      local_2c = param_4 - 1;
      do {
        pbVar5 = pbVar5 + -0x20;
        iVar1 = FUN_20145afc(pbVar5,local_4c);
        psVar3 = local_4c;
        while (iVar1 != 0) {
          iVar1 = iVar1 + -1;
          if ((*param_3 != *psVar3) && (iVar2 = FUN_201458e4(param_3,psVar3), iVar2 == 0)) {
            if ((iVar6 != param_5) && (iVar6 = FUN_20144d04(param_1,param_5,&local_50), iVar6 != 0))
            {
              return iVar6;
            }
            goto LAB_20145dac;
          }
          param_3 = param_3 + 1;
          psVar3 = psVar3 + 1;
        }
        if ((pbVar5 == local_50) && (uVar4 != local_2c)) {
          iVar6 = iVar6 + -1;
          iVar1 = FUN_20144d04(param_1,iVar6,&local_50);
          if (iVar1 != 0) {
            return iVar1;
          }
          pbVar5 = local_50 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < param_4);
    }
    if ((*pbVar5 & 0x40) != 0) {
      local_30 = 0;
    }
    if (((iVar6 == param_5) || (iVar1 = FUN_20144d04(param_1,param_5,&local_50), iVar1 == 0)) &&
       (iVar1 = local_30, (char)*param_3 != '\0')) {
LAB_20145dac:
      iVar1 = -99;
    }
  }
  return iVar1;
}


// ===== FUN_20145df0 @ 20145df0 (1340 bytes)

int FUN_20145df0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                uint *param_6,int param_7)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  char local_80 [16];
  undefined1 auStack_70 [16];
  undefined4 local_60;
  undefined4 uStack_5c;
  int local_58;
  undefined1 auStack_54 [16];
  int local_44;
  char local_40 [4];
  char *local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int iStack_28;
  
  uVar8 = 0xffffffff;
  uVar10 = 0;
  local_38 = 0xffffffff;
  uVar5 = 0;
  uVar9 = 0;
  pcVar4 = (char *)0x0;
  local_40[0] = '\0';
  local_60 = 0x31;
  uStack_5c = 0;
  local_3c = (char *)(param_7 + 0xe0c);
  local_44 = param_7 + 0x40c;
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  iVar3 = FUN_2014cb84(param_2,local_44,local_40);
  if (iVar3 == -99) {
    return -0x46;
  }
  cVar2 = FUN_20145254(local_30,auStack_70,&local_60);
  if (cVar2 == '\x01') {
    uVar5 = (iVar3 + -1) / 0xd + 1U & 0xffff;
  }
  else if (cVar2 == '\0') goto LAB_20145edc;
  if ((local_40[0] == '\0') && (param_4 == 0 || param_4 == 2)) {
    FUN_2014d128(auStack_54,local_30,0xd);
    FUN_2014d38c(auStack_70,auStack_54);
  }
LAB_20145edc:
  uVar7 = 0;
  uVar6 = uVar5 + 1 & 0xffff;
  local_58 = param_7 + 0x1600;
  uVar1 = (undefined2)(uVar5 + 1);
  if (*(short *)(local_34 + 10) != 0) {
    do {
      uVar12 = FUN_20156260(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar13 = (undefined4)uVar12;
      if (((int)((ulonglong)uVar12 >> 0x20) == 0) &&
         (iVar3 = FUN_20144d04(local_34,uVar13,&local_3c), pcVar4 = local_3c, local_38 = uVar13,
         iVar3 != 0)) {
        return iVar3;
      }
      if (pcVar4 == (char *)0x0) {
        return -0xd;
      }
      if (*pcVar4 == -0x1b) {
        if (param_4 != 0 && param_4 != 2) {
          uVar10 = uVar10 + 1 & 0xffff;
          bVar11 = uVar10 == uVar6;
          if (uVar6 <= uVar10) {
            bVar11 = uVar8 == 0xffffffff;
          }
          if (bVar11) {
            uVar8 = (uint)(short)uVar7;
          }
        }
      }
      else {
        if (*pcVar4 == '\0') {
          if (param_4 == 0 || param_4 == 2) {
            return -0x47;
          }
          if (999999 < uVar9) {
            return -0x42;
          }
          if (uVar9 != 0) {
            FUN_20145578(&local_60,uVar9);
          }
          cVar2 = FUN_20145254(local_30,auStack_70,&local_60);
          FUN_201450a4(local_80,auStack_70,local_34);
          if (local_80[0] == -0x1b) {
            local_80[0] = '\x05';
          }
          FUN_2014d128(local_2c,local_80,0xb);
          if ((int)uVar8 < 0) {
            if (((*(ushort *)(local_34 + 10) - uVar7) + uVar10 & 0xffff) < uVar6) {
              return -0x42;
            }
            uVar8 = ((uVar7 + uVar6) - uVar10) - 1;
            *param_6 = uVar8;
            *(short *)(local_58 + 0x20) = (short)uVar8;
            *(undefined2 *)(local_58 + 0x22) = uVar1;
            if (param_4 != 3) {
              if (cVar2 != '\x01') {
                iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
                return iVar3;
              }
              iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
              return iVar3;
            }
            return 0;
          }
          *param_6 = uVar8;
          *(short *)(local_58 + 0x20) = (short)uVar8;
          *(undefined2 *)(local_58 + 0x22) = uVar1;
          goto joined_r0x20146034;
        }
        uVar10 = 0;
        if (((pcVar4[0xb] & 8U) == 0) && (param_4 != 3)) {
          iVar3 = FUN_20145be4(local_34,uVar7,local_44,uVar6,local_38,param_7);
          FUN_201450a4(local_80,auStack_70,local_34);
          if (local_80[0] == -0x1b) {
            local_80[0] = '\x05';
          }
          uVar5 = FUN_20145764(pcVar4,local_80);
          if (uVar9 <= uVar5) {
            uVar9 = uVar5 + 1;
          }
          if (iVar3 == 0) {
LAB_201461a8:
            if (param_4 == 1) {
              return -0xd;
            }
            FUN_2014d128(local_2c,pcVar4,0x20);
            if (param_4 == 2) {
              iVar3 = FUN_201455f8(local_34,uVar7,uVar6,param_7);
              return iVar3;
            }
            if (param_4 == 0) {
              *param_6 = uVar7;
              *(short *)(local_58 + 0x20) = (short)uVar7;
              *(undefined2 *)(local_58 + 0x22) = uVar1;
              return 0;
            }
          }
          else {
            uVar5 = FUN_2014d220(local_30);
            if (uVar5 < 0xd) {
              if (uVar9 != 0) {
                FUN_20145578(&local_60,uVar9);
              }
              FUN_20145254(local_30,auStack_70,&local_60);
              FUN_201450a4(local_80,auStack_70,local_34);
              if (local_80[0] == -0x1b) {
                local_80[0] = '\x05';
              }
              iVar3 = FUN_2014570c(pcVar4,local_80,local_34);
              if (iVar3 == 0) goto LAB_201461a8;
            }
          }
        }
      }
      pcVar4 = pcVar4 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(ushort *)(local_34 + 10));
  }
  if (param_4 == 1 || param_4 == 3) {
    if (-1 < (int)uVar8) {
      if (999999 < uVar9) {
        return -0x42;
      }
      if (uVar9 != 0) {
        FUN_20145578(&local_60,uVar9);
      }
      FUN_20145254(local_30,auStack_70,&local_60);
      FUN_201450a4(local_80,auStack_70,local_34);
      if (local_80[0] == -0x1b) {
        local_80[0] = '\x05';
      }
      FUN_2014d128(local_2c,local_80,0xb);
      *param_6 = uVar8;
      *(short *)(local_58 + 0x20) = (short)uVar8;
      *(undefined2 *)(local_58 + 0x22) = uVar1;
joined_r0x20146034:
      if (param_4 == 3) {
        return 0;
      }
      iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
      return iVar3;
    }
    if (param_4 == 3) {
      return -0xb;
    }
  }
  return -0x47;
}


// ===== FUN_20146338 @ 20146338 (108 bytes)

undefined4
FUN_20146338(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014d9c0();
  if (iVar1 == 0) {
    uVar2 = FUN_20145df0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_2014da64(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_201463a4 @ 201463a4 (204 bytes)

int FUN_201463a4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  
  local_18 = param_4;
  iVar1 = FUN_20149dec(param_1,param_2,&local_18,param_3);
  if (iVar1 == 0) {
    if (local_18 == 0) {
      FUN_20144800(0xfffffff5,0);
      return 0;
    }
    iVar2 = FUN_20144980(param_1);
    FUN_2014d148(param_3 + 0x60c,0,0x200);
    iVar3 = 0;
    if (*(short *)(param_1 + 4) != 0) {
      do {
        iVar1 = FUN_20144ac0(param_1,iVar2,param_3 + 0x60c,1);
        if (iVar1 != 0) goto LAB_20146424;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 4));
    }
    FUN_20144800(0);
    return local_18;
  }
LAB_20146424:
  FUN_20144800(iVar1,0);
  return 0;
}


// ===== FUN_20146470 @ 20146470 (176 bytes)

undefined4 FUN_20146470(undefined1 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = param_3;
  do {
    if (uVar2 == 0) {
      return 0;
    }
    while( true ) {
      if ((param_3 == uVar2) || (param_1[0xb] == '\x0f')) {
        *param_1 = 0xe5;
      }
      if (*(undefined1 **)(param_2 + iVar3 * 4) == param_1) break;
      if ((uVar2 != 0) && (param_1[-0x15] != '\x0f')) {
        return 0;
      }
      uVar2 = uVar2 - 1 & 0xffff;
      param_1 = param_1 + -0x20;
      if (uVar2 == 0) {
        return 0;
      }
    }
    uVar2 = uVar2 - 1 & 0xffff;
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    param_1 = (undefined1 *)
              (*(int *)(param_2 + iVar1 + 4) + (*(uint *)(param_4 + 0x6c) & 0xffffffe0) + -0x20);
  } while (iVar3 < 3);
  return 0xffffffbc;
}


// ===== FUN_20146520 @ 20146520 (140 bytes)

undefined4 FUN_20146520(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
  FUN_201450a4(local_18);
  if (local_18[0] == -0x1b) {
    local_18[0] = '\x05';
  }
  else {
    pcVar3 = local_18;
    if (local_18[0] == '\0') {
      return 0;
    }
  }
  while( true ) {
    iVar1 = FUN_2014ca90(*pcVar3);
    pcVar2 = pcVar3;
    pcVar4 = param_1;
    if (iVar1 != 0) {
      pcVar2 = pcVar3 + 1;
      pcVar4 = param_1 + 1;
      if (*pcVar3 != *param_1) {
        return 0xffffff9d;
      }
    }
    pcVar3 = pcVar2 + 1;
    param_1 = pcVar4 + 1;
    if (*pcVar2 != *pcVar4) break;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return 0xffffff9d;
}


// ===== FUN_201465ac @ 201465ac (92 bytes)

undefined4 FUN_201465ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  iVar1 = FUN_20145764();
  iVar2 = FUN_2014d834(param_3);
  if (iVar2 <= iVar1) {
    if (0x98967e < iVar1) {
      return 0xffffffbe;
    }
    FUN_2014d864(iVar1 + 1,auStack_18,10);
    FUN_2014d270(param_3,auStack_18);
  }
  return 0;
}


// ===== FUN_20146608 @ 20146608 (228 bytes)

undefined4 FUN_20146608(int param_1,byte *param_2,short *param_3,int param_4)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  short local_40 [14];
  
  iVar7 = 0;
  uVar2 = FUN_20144eb8(param_2);
  do {
    pbVar1 = param_2;
    if (*(byte **)(param_1 + iVar7 * 4) == param_2) {
      iVar7 = iVar7 + 1;
      iVar3 = *(int *)(param_1 + iVar7 * 4);
      if (iVar3 == 0) goto LAB_201466e0;
      pbVar1 = (byte *)(iVar3 + (*(uint *)(param_4 + 0x6c) & 0xffffffe0));
    }
    param_2 = pbVar1 + -0x20;
    if ((pbVar1[-0x15] != 0xf) || (pbVar1[-0x13] != uVar2)) goto LAB_201466e0;
    iVar3 = FUN_20145afc(param_2,local_40);
    psVar6 = local_40;
    for (; 0 < iVar3; iVar3 = iVar3 + -1) {
      if ((*param_3 != *psVar6) && (iVar4 = FUN_201458e4(param_3,psVar6), iVar4 == 0))
      goto LAB_201466e0;
      param_3 = param_3 + 1;
      psVar6 = psVar6 + 1;
    }
  } while ((*param_2 & 0x40) == 0);
  uVar5 = 0;
  if (*param_3 != 0) {
LAB_201466e0:
    uVar5 = 0xffffff9d;
  }
  return uVar5;
}


// ===== FUN_201466ec @ 201466ec (408 bytes)

void FUN_201466ec(int param_1,undefined4 *param_2,int param_3,char *param_4,int param_5,int param_6,
                 int param_7)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  byte *local_28;
  
  iVar5 = 0;
  param_4[0xc] = '\0';
  local_28 = (byte *)(param_7 + 0x60c);
  iVar2 = FUN_20144c5c(param_1,*param_2,&local_28);
  if (iVar2 != 0) {
    return;
  }
  pbVar3 = local_28 + param_3 * 0x20;
  if (*param_4 == -0x1b) {
    *param_4 = '\x05';
  }
  FUN_2014d128(pbVar3,param_4,0x20);
  param_6 = param_6 + -1;
  if (param_6 == 0) {
    FUN_20144b74(param_1,*param_2,local_28);
    return;
  }
  if (pbVar3 == local_28) {
    iVar2 = FUN_20144b74(param_1,*param_2);
    if (iVar2 != 0) {
      return;
    }
    iVar5 = 1;
    iVar2 = FUN_20144c5c(param_1,param_2[1],&local_28);
    if (iVar2 != 0) {
      return;
    }
    pbVar3 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
  }
  bVar1 = FUN_20144eb8(param_4);
  bVar6 = 1;
  do {
    pbVar4 = pbVar3 + -0x20;
    iVar2 = FUN_20144d5c(pbVar4,param_5,param_1);
    *pbVar4 = bVar6;
    param_5 = param_5 + iVar2 * 2;
    pbVar3[-0x15] = 0xf;
    pbVar3[-0x13] = bVar1;
    if ((pbVar4 == local_28) && (param_6 != 1)) {
      iVar2 = FUN_20144b74(param_1,param_2[iVar5]);
      if (iVar2 != 0) {
        return;
      }
      iVar5 = iVar5 + 1;
      iVar2 = FUN_20144c5c(param_1,param_2[iVar5],&local_28);
      if (iVar2 != 0) {
        return;
      }
      pbVar4 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
    }
    param_6 = param_6 + -1;
    bVar6 = bVar6 + 1;
    pbVar3 = pbVar4;
    if (param_6 == 0) {
      *pbVar4 = *pbVar4 | 0x40;
      FUN_20144b74(param_1,param_2[iVar5],local_28);
      return;
    }
  } while( true );
}


// ===== FUN_20146884 @ 20146884 (60 bytes)

int FUN_20146884(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0xc && param_2 != 0x10) {
    iVar1 = FUN_2014d900(param_1 + 0x1a);
    iVar2 = FUN_2014d900(param_1 + 0x14);
    return iVar1 + iVar2 * 0x10000;
  }
  iVar1 = FUN_2014d900(param_1 + 0x1a);
  return iVar1;
}


// ===== FUN_201468c0 @ 201468c0 (2308 bytes)

/* WARNING: Type propagation algorithm not settling */

int FUN_201468c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6,uint *param_7,int *param_8,int param_9)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  undefined6 uVar15;
  int local_d4 [3];
  undefined1 auStack_c8 [16];
  char *local_b8 [3];
  char local_ac [12];
  char local_a0 [16];
  uint local_90;
  int local_8c;
  undefined1 local_88;
  undefined1 local_87;
  undefined1 auStack_80 [12];
  int local_74;
  int local_70;
  undefined1 local_6c [12];
  undefined1 auStack_60 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  char local_40 [4];
  int local_3c [2];
  int iStack_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_44 = 1;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  FUN_2014d148(local_6c,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_6c[0] = 0x2e;
  local_b8[0] = (char *)(param_9 + 0x60c);
  local_b8[1] = (char *)(param_9 + 0x80c);
  local_a0[0] = '\0';
  local_b8[2] = (char *)(param_9 + 0xa0c);
  FUN_2014d148(local_b8[1],0,0x200,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148((char *)(param_9 + 0xa0c),0,0x200,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148(local_d4,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148(auStack_80,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  local_40[0] = '\0';
  iVar13 = 0;
  local_88 = 0x31;
  uVar14 = 0xffffffff;
  uVar11 = 0;
  local_87 = 0;
  uVar9 = 0;
  uVar10 = 0;
  iVar3 = FUN_201497cc(param_1,local_3c,local_30,0,0x72,param_9);
  if (iVar3 == 0) {
    if (local_3c[0] == 0) {
LAB_20146b94:
      iVar3 = -0x47;
    }
    else {
      local_50 = param_9 + 0x40c;
      iVar3 = FUN_2014cb84(local_2c,local_50,local_40);
      if (iVar3 != -99) {
        if ((param_5 == 0 || param_5 == 2) && (uVar4 = FUN_2014d220(local_2c), uVar4 < 0xd)) {
          FUN_2014d270(local_a0,local_2c);
          FUN_2014d5b4(local_a0);
        }
        if (local_a0[0] == '\0') {
          local_70 = FUN_20145254(local_2c,auStack_c8,&DAT_20146dcc);
        }
        else {
          local_70 = FUN_20145254(local_a0,auStack_c8,&DAT_20146dcc);
        }
        if (local_70 == 1) {
          uVar11 = (iVar3 + -1) / 0xd + 1U & 0xffff;
        }
        local_90 = uVar11 + 1 & 0xffff;
        if (((local_70 != 0) && (local_40[0] == '\0')) && (param_5 == 0 || param_5 == 2)) {
          FUN_2014d128(auStack_60,local_a0,0xd);
          iVar3 = FUN_2014d38c(auStack_c8,auStack_60);
          if (iVar3 == 0) {
            local_70 = 0;
          }
        }
        uVar11 = 0;
        local_48 = param_9 + 0x1624;
        local_74 = param_9 + 0x1600;
        do {
          iVar3 = FUN_20144980(param_1,local_30);
          local_8c = 0;
          if (*(short *)(param_1 + 4) != 0) {
            do {
              iVar5 = FUN_20144c5c(param_1,iVar3,local_b8);
              pcVar12 = local_b8[0];
              if (iVar5 != 0) {
                return iVar5;
              }
              local_d4[0] = iVar3;
              if (local_44 == 1) {
                if ((*(int *)(param_1 + 0x34) != local_30) &&
                   ((iVar5 = FUN_2014d48c(local_b8[0],local_6c,0xb), iVar5 != 0 ||
                    (iVar5 = FUN_20146884(pcVar12,(int)*(char *)(param_1 + 0x10)), iVar5 != local_30
                    )))) goto LAB_20146b94;
                local_44 = 0;
              }
              uVar11 = 0;
              if (*(uint *)(param_1 + 0x6c) >> 5 != 0) {
                do {
                  if (*pcVar12 == '\0') {
                    if (param_5 == 0 || param_5 == 2) {
                      return -4;
                    }
                    goto LAB_20146bf4;
                  }
                  if ((*pcVar12 == -0x1b) && (param_5 == 1 || param_5 == 3)) {
                    if ((local_90 == iVar13 + 1U) && ((int)uVar14 < 0)) {
                      uVar14 = (uint)(short)uVar11;
                      FUN_2014d128(auStack_80,local_d4,0xc);
                      *param_8 = iVar3;
                      *param_7 = uVar14;
                    }
                    iVar13 = iVar13 + 1;
                  }
                  else {
                    iVar13 = 0;
                    bVar1 = pcVar12[0xb];
                    if (((bVar1 & 0x30) == 0) && ((~bVar1 & 0xf) == 0)) {
                      if (uVar10 == 0) {
                        uVar9 = 1;
                        uVar10 = uVar9;
                      }
                      else {
                        uVar9 = uVar9 + 1 & 0xffff;
                      }
                    }
                    else if (uVar10 == 0) {
                      uVar9 = 1;
                    }
                    else {
                      uVar9 = uVar9 + 1 & 0xffff;
                      uVar10 = 0;
                    }
                    if (((bVar1 & 8) == 0) && (param_5 != 3)) {
                      if ((param_5 == 1) && (local_70 == 1)) {
                        FUN_201450a4(local_ac,auStack_c8,param_1);
                        if (local_ac[0] == -0x1b) {
                          local_ac[0] = '\x05';
                        }
                        iVar5 = FUN_201465ac(pcVar12,local_ac,&local_88);
                        if (iVar5 != 0) {
                          return iVar5;
                        }
                      }
                      iVar5 = FUN_20146608(local_b8,pcVar12,local_50,param_1);
                      if (iVar5 == 0) {
LAB_201470bc:
                        FUN_2014d128(local_28,pcVar12,0x20);
                        if (param_5 == 0) {
                          *param_8 = iVar3;
                          *param_7 = uVar11;
                          *(short *)(local_74 + 0x20) = (short)uVar11;
                          *(short *)(local_74 + 0x22) = (short)local_90;
                          FUN_2014d128(local_48,local_d4,0xc);
                          return 0;
                        }
                        if (param_5 != 2) {
                          return -0xd;
                        }
                        iVar3 = FUN_20146470(pcVar12,local_b8,uVar9,param_1);
                        if (iVar3 != 0) {
                          return iVar3;
                        }
                        iVar3 = (uVar9 - uVar11) + -1;
                        iVar13 = 1;
                        if (0 < iVar3) {
                          do {
                            iVar13 = iVar13 + 1;
                            iVar3 = iVar3 - (*(uint *)(param_1 + 0x6c) >> 5);
                          } while (0 < iVar3);
                        }
                        iVar3 = 0;
                        if (0 < iVar13) {
                          while( true ) {
                            if (local_d4[iVar3] == 0) {
                              return 0;
                            }
                            iVar5 = FUN_20144b74(param_1,local_d4[iVar3],local_b8[iVar3]);
                            if (iVar5 != 0) break;
                            iVar3 = iVar3 + 1;
                            if (iVar13 <= iVar3) {
                              return 0;
                            }
                          }
                          return iVar5;
                        }
                        return 0;
                      }
                      uVar4 = FUN_2014d220(local_2c);
                      if (uVar4 < 0xd) {
                        FUN_201450a4(local_ac,auStack_c8,param_1);
                        if (local_ac[0] == -0x1b) {
                          local_ac[0] = '\x05';
                        }
                        iVar5 = FUN_201465ac(pcVar12,local_ac,&local_88);
                        if (iVar5 != 0) {
                          return iVar5;
                        }
                        FUN_20145254(local_2c,auStack_c8,&local_88);
                        iVar5 = FUN_20146520(pcVar12,auStack_c8,param_1);
                        if (iVar5 == 0) goto LAB_201470bc;
                      }
                    }
                  }
                  uVar11 = uVar11 + 1;
                  pcVar12 = pcVar12 + 0x20;
                } while (uVar11 < *(uint *)(param_1 + 0x6c) >> 5);
              }
              pcVar2 = local_b8[1];
              pcVar12 = local_b8[0];
              iVar3 = iVar3 + 1;
              pcVar8 = local_b8[2];
              local_b8[0] = local_b8[2];
              local_b8[2] = local_b8[1];
              local_b8[1] = pcVar12;
              local_d4[2] = local_d4[1];
              local_d4[1] = local_d4[0];
              local_8c = local_8c + 1;
            } while (local_8c < (int)(uint)*(ushort *)(param_1 + 4));
          }
          FUN_201497cc(param_1,&local_4c,local_30,0,0x72,param_9);
          if (local_4c == 0xffffff7) {
            return -0x3d;
          }
          if (local_4c + 0xf0000008U < 8) {
            if (param_5 == 0 || param_5 == 2) {
              return -4;
            }
            if (-1 < (int)uVar14) {
LAB_20146bf4:
              FUN_20145254(local_2c,auStack_c8,&local_88);
              FUN_201450a4(local_ac,auStack_c8,param_1);
              FUN_2014d128(local_28,local_ac,0xb);
              if (-1 < (int)uVar14) {
                *(short *)(local_74 + 0x20) = (short)uVar14;
                *(short *)(local_74 + 0x22) = (short)local_90;
                FUN_2014d128(local_48,auStack_80,0xc);
                if (param_5 == 3) {
                  return 0;
                }
                iVar3 = FUN_201466ec(param_1,auStack_80,uVar14 & 0xffff,local_28,local_50,local_90,
                                     param_9);
                return iVar3;
              }
              uVar15 = FUN_20156260(((local_90 + uVar11) - iVar13) + -1,
                                    *(uint *)(param_1 + 0x6c) >> 5);
              sVar7 = (short)((uint6)uVar15 >> 0x20);
              iVar13 = 0;
              if ((int)uVar15 < 1) goto LAB_20146d4c;
              goto LAB_20146cb4;
            }
            local_4c = FUN_201463a4(param_1,local_30,param_9);
            iVar3 = FUN_2014d95c();
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          local_30 = local_4c;
        } while( true );
      }
      iVar3 = -0x46;
    }
  }
  return iVar3;
LAB_20146cb4:
  iVar3 = iVar3 + 1;
  uVar10 = (uint)*(ushort *)(param_1 + 4);
  if (uVar10 == 1) {
    iVar5 = FUN_201463a4(param_1,local_30,param_9);
    local_30 = iVar5;
    iVar3 = FUN_2014d95c();
    if (iVar3 != 0) {
      return iVar3;
    }
LAB_20146e24:
    iVar3 = FUN_20144980(param_1,iVar5);
  }
  else if (uVar10 == 2) {
    if (local_8c == 1) {
      iVar5 = FUN_201463a4(param_1,local_30,param_9);
      iVar3 = FUN_2014d95c();
      if (iVar3 != 0) {
        return iVar3;
      }
      goto LAB_20146e24;
    }
  }
  else if (uVar10 - 1 == local_8c) {
    uVar6 = FUN_201463a4(param_1,local_30,param_9);
    iVar3 = FUN_2014d95c();
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = FUN_20144980(param_1,uVar6);
    local_8c = 0;
  }
  iVar13 = iVar13 + 1;
  local_d4[2] = local_d4[1];
  local_d4[1] = local_d4[0];
  local_8c = local_8c + 1;
  local_d4[0] = iVar3;
  if ((int)uVar15 <= iVar13) {
LAB_20146d4c:
    *param_8 = iVar3;
    *param_7 = (int)sVar7;
    *(short *)(local_74 + 0x20) = sVar7;
    *(short *)(local_74 + 0x22) = (short)local_90;
    FUN_2014d128(local_48,local_d4,0xc);
    if (param_5 == 3) {
      return 0;
    }
    if (local_70 == 1) {
      iVar3 = FUN_201466ec(param_1,local_d4,sVar7,local_28,local_50,local_90,param_9);
      return iVar3;
    }
    iVar3 = FUN_201466ec(param_1,local_d4,sVar7,local_28,0,local_90,param_9);
    return iVar3;
  }
  goto LAB_20146cb4;
}


// ===== FUN_201471cc @ 201471cc (124 bytes)

undefined4
FUN_201471cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_2;
  uVar3 = param_3;
  uVar4 = param_4;
  iVar1 = FUN_2014d9c0(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_201468c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_1,uVar2,uVar3,uVar4);
    FUN_2014da64(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_20147248 @ 20147248 (96 bytes)

char * FUN_20147248(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*param_1 == '\\') {
    while (pcVar2 = param_1 + 1, *pcVar2 != '\0' && *pcVar2 != '\\') {
      iVar1 = FUN_2014ca90(*pcVar2);
      pcVar3 = pcVar2;
      pcVar4 = param_2;
      if (iVar1 != 0) {
        pcVar3 = param_1 + 2;
        pcVar4 = param_2 + 1;
        *param_2 = *pcVar2;
      }
      param_2 = pcVar4 + 1;
      *pcVar4 = *pcVar3;
      param_1 = pcVar3;
    }
    *param_2 = '\0';
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


// ===== FUN_201472a8 @ 201472a8 (108 bytes)

int FUN_201472a8(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char local_218 [524];
  
  pcVar3 = (char *)(param_1 + 2);
  cVar1 = *(char *)(param_1 + 2);
  iVar4 = 0;
  while (((cVar1 != '\0' && (pcVar3 = (char *)FUN_20147248(pcVar3,local_218), local_218[0] != '\0'))
         && (*pcVar3 != '\0'))) {
    iVar2 = FUN_2014d220(local_218);
    iVar4 = iVar2 + iVar4 + 1;
    cVar1 = *pcVar3;
  }
  return iVar4 + 3;
}


// ===== FUN_20147314 @ 20147314 (176 bytes)

undefined4 FUN_20147314(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = true;
  if (*param_1 != '\0') {
    do {
      pcVar4 = param_1;
      if (*pcVar4 != ' ') {
        bVar1 = false;
      }
      if (iVar5 == 0) {
        iVar2 = FUN_2014ca90(*pcVar4);
        if (iVar2 == 0) {
          if (*DAT_20808ba8 != '\0') {
            pcVar3 = DAT_20808ba8;
            do {
              if (*pcVar3 == *pcVar4) {
                return 0xffffffff;
              }
              pcVar3 = pcVar3 + 1;
            } while (*pcVar3 != '\0');
          }
        }
        else {
          iVar5 = 1;
        }
      }
      else {
        iVar5 = iVar5 + -1;
      }
      param_1 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    if ((!bVar1) && (*pcVar4 != '.' && *pcVar4 != ' ')) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_201473c4 @ 201473c4 (224 bytes)

int FUN_201473c4(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char local_218 [520];
  
  iVar2 = (int)*param_1;
  if ((0x19 < iVar2 - 0x41U) && (0x19 < iVar2 - 0x61U)) {
    return -0xc;
  }
  if ((param_1[1] == ':') && (param_1[2] == '\\')) {
    iVar4 = 0;
    pcVar3 = param_1;
    if (iVar2 != 0) {
      do {
        iVar2 = FUN_2014ca90(*pcVar3);
        iVar4 = iVar4 + 1;
        if (iVar2 != 0) {
          pcVar3 = pcVar3 + 1;
        }
        pcVar3 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      if (0x102 < iVar4) goto LAB_20147444;
    }
    cVar1 = param_1[2];
    param_1 = param_1 + 2;
    while( true ) {
      if ((cVar1 == '\0') ||
         (param_1 = (char *)FUN_20147248(param_1,local_218), local_218[0] == '\0')) {
        return 0;
      }
      iVar2 = FUN_20147314(local_218);
      if (iVar2 != 0) break;
      cVar1 = *param_1;
    }
  }
  else {
LAB_20147444:
    iVar2 = -1;
  }
  return iVar2;
}


// ===== FUN_201474a4 @ 201474a4 (228 bytes)

void FUN_201474a4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int iStack_30;
  int local_2c;
  
  iVar1 = FUN_2014e1dc(&local_40);
  if (iVar1 == 0) {
    uVar2 = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = local_40 / 2 | local_3c << 5 | local_38 << 0xb;
    uVar2 = iStack_30 * 0x20 + 0x20U | local_34;
    if (0x4f < local_2c) {
      uVar2 = uVar2 | local_2c * 0x200 - 0xa000U;
    }
  }
  if ((param_3 & 1) != 0) {
    FUN_2014d8ec(param_1 + 0xe,uVar3 & 0xffff);
    FUN_2014d8ec(param_1 + 0x10,uVar2 & 0xffff);
  }
  if ((param_3 & 2) != 0) {
    FUN_2014d8ec(param_1 + 0x16,uVar3 & 0xffff);
    FUN_2014d8ec(param_1 + 0x18,uVar2 & 0xffff);
    if (param_2 != 0) {
      *(short *)(param_2 + 0x234) = (short)uVar3;
      *(short *)(param_2 + 0x236) = (short)uVar2;
    }
  }
  if ((param_3 & 4) != 0) {
    FUN_2014d8ec(param_1 + 0x12,uVar2 & 0xffff);
  }
  return;
}


// ===== FUN_20147588 @ 20147588 (72 bytes)

void FUN_20147588(int param_1,uint param_2,int param_3)

{
  if (param_3 != 0xc && param_3 != 0x10) {
    FUN_2014d8ec(param_1 + 0x1a,param_2 & 0xffff);
    FUN_2014d8ec(param_1 + 0x14,param_2 >> 0x10);
    return;
  }
  FUN_2014d8ec(param_1 + 0x1a,param_2 & 0xffff);
  return;
}


// ===== FUN_201475d0 @ 201475d0 (112 bytes)

void FUN_201475d0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  uVar1 = FUN_2014d900(&uStack_14);
  uVar2 = FUN_2014d900(&uStack_10);
  *param_1 = (uVar1 & 0x1f) << 1;
  param_1[1] = (uVar1 & 0x7ff) >> 5;
  param_1[2] = uVar1 >> 0xb;
  param_1[3] = uVar2 & 0x1f;
  param_1[4] = ((uVar2 & 0x1ff) >> 5) - 1;
  param_1[5] = (uVar2 >> 9) + 0x50;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ===== FUN_20147640 @ 20147640 (176 bytes)

undefined4 FUN_20147640(char *param_1,int param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if (*(char *)(param_2 + iVar3) == ' ') break;
    if ((param_3 & 8) == 0) {
      *param_1 = *(char *)(param_2 + iVar3);
    }
    else {
      cVar1 = FUN_2014d374((int)*(char *)(param_2 + iVar3));
      *param_1 = cVar1;
    }
    param_1 = param_1 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 8;
  do {
    if (*(char *)(param_2 + iVar3) == ' ') {
      pcVar2 = param_1;
      if (iVar3 == 8) {
        pcVar2 = param_1 + 1;
        *param_1 = '\0';
      }
      break;
    }
    pcVar2 = param_1;
    if (iVar3 == 8) {
      *param_1 = '.';
      pcVar2 = param_1 + 1;
    }
    if ((param_3 & 0x10) == 0) {
      cVar1 = *(char *)(param_2 + iVar3);
    }
    else {
      cVar1 = FUN_2014d374((int)*(char *)(param_2 + iVar3));
    }
    iVar3 = iVar3 + 1;
    param_1 = pcVar2 + 1;
    *pcVar2 = cVar1;
    pcVar2 = param_1;
  } while (iVar3 < 0xb);
  *pcVar2 = '\0';
  return 0;
}


// ===== FUN_201476f0 @ 201476f0 (12 bytes)

undefined4 FUN_201476f0(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & ~param_1) != 0) {
    uVar1 = 0xffffff9d;
  }
  return uVar1;
}

