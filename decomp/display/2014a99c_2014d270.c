// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2014a99c @ 2014a99c (56 bytes)

void FUN_2014a99c(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}


// ===== FUN_2014a9d4 @ 2014a9d4 (284 bytes)

void FUN_2014a9d4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_1c [8];
  
  uVar3 = FUN_2014a4a4();
  iVar1 = (int)uVar3;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    FUN_2014a99c(param_1,(int)((ulonglong)uVar3 >> 0x20));
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,7,0,0,1);
    if (iVar1 != 0) {
      FUN_20144834();
      return;
    }
    iVar1 = 0;
    if (*(char *)(param_1 + 0x10) != '@') {
      if (0x20000 < *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 4)) {
        *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
        iVar1 = -0x10;
        goto LAB_2014aa68;
      }
      if (*(char *)(param_1 + 0x10) == ' ') {
        if (*(int *)(param_1 + 0x3c) == -1) {
          iVar2 = FUN_2014e118();
          if (iVar2 == 0) {
            iVar1 = -0x1f;
            goto LAB_2014aa68;
          }
          iVar1 = FUN_2014b730((int)*(char *)(param_1 + 0x11),auStack_1c,auStack_1c,iVar2);
          FUN_2014e14c(iVar2);
        }
        if (*(int *)(param_1 + 0x40) == -1) {
          *(undefined4 *)(param_1 + 0x40) = 2;
        }
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x40);
      }
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
  }
LAB_2014aa68:
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014aaf0 @ 2014aaf0 (132 bytes)

void FUN_2014aaf0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 != 0) {
    FUN_20144800(iVar1,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x68) & 1) != 0) {
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,8,0);
    if (iVar1 != 0) {
      FUN_20144834();
      return;
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    FUN_20144800(0,0);
    return;
  }
  FUN_20144800(0xfffffff0,0);
  return;
}


// ===== FUN_2014ab74 @ 2014ab74 (168 bytes)

void FUN_2014ab74(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_20144800(0xfffffff3,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
    FUN_20144800(0xfffffff0,0);
    return;
  }
  iVar2 = FUN_2014ddd0(param_1);
  if (iVar2 != 0) {
    FUN_20144800(0xffffffcb,0);
    return;
  }
  if (DAT_20808ba0 == param_1) {
    DAT_20808ba0 = (int *)*param_1;
  }
  else {
    piVar1 = (int *)*DAT_20808ba0;
    piVar4 = DAT_20808ba0;
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      if (param_1 == piVar3) {
        *piVar4 = *piVar3;
        break;
      }
      piVar4 = piVar3;
      piVar1 = (int *)*piVar3;
    }
  }
  FUN_20144800(0);
  return;
}


// ===== FUN_2014ac30 @ 2014ac30 (492 bytes)

int FUN_2014ac30(char *param_1,char *param_2,char *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_4c;
  undefined1 auStack_48 [11];
  char local_3d;
  undefined2 local_32;
  undefined2 local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  local_4c = DAT_20808ba0;
  uVar1 = FUN_2014d35c((int)*param_1);
  iVar2 = FUN_20144918(uVar1,&local_4c);
  if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_4c), iVar2 != 0)) {
    return iVar2;
  }
  param_1 = param_1 + 2;
  uVar3 = *(undefined4 *)(local_4c + 0x34);
  if (*(char *)(local_4c + 0x10) != ' ') {
    param_1 = (char *)FUN_20147248(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
      return -1;
    }
    iVar2 = FUN_20146338(local_4c,param_3,auStack_48,0,0,auStack_28,param_3);
    if (iVar2 != 0) {
      if (*param_1 == '\0') {
        return -3;
      }
      return -4;
    }
    uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
  }
  if (*param_1 != '\0') {
    do {
      param_1 = (char *)FUN_20147248(param_1,param_3);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_3 == '\0') {
        return -1;
      }
      iVar2 = FUN_201471cc(local_4c,uVar3,param_3,auStack_48,0,0,auStack_28,auStack_24,param_3);
      if (iVar2 != 0) {
        if (*param_1 == '\0' && iVar2 == -4) {
          return -3;
        }
        return iVar2;
      }
      uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
    } while (*param_1 != '\0');
  }
  FUN_2014d128(param_2,auStack_48,0xb);
  if (*param_2 == '\x05') {
    *param_2 = -0x1b;
  }
  param_2[0xb] = local_3d;
  FUN_201475d0(param_2 + 0xc,local_32,local_30);
  uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  uVar3 = FUN_2014d93c(auStack_2c);
  *(undefined4 *)(param_2 + 0x34) = uVar3;
  return 0;
}


// ===== FUN_2014ae1c @ 2014ae1c (172 bytes)

void FUN_2014ae1c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      FUN_20144800(0xffffffff,0);
      return;
    }
    if (param_2 == 0) {
      FUN_20144800(0xfffffff3,0);
      return;
    }
    iVar1 = FUN_201473c4(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_2014d220(param_1);
      iVar2 = param_3 + 0x100c;
      FUN_2014d288(iVar2,param_1,iVar1 + 1);
      FUN_2014cd68(iVar2);
      uVar3 = FUN_2014ac30(iVar2,param_2,param_3);
      FUN_20144800(uVar3,0);
      return;
    }
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014aec8 @ 2014aec8 (76 bytes)

undefined4 FUN_2014aec8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014ae1c(param_1,param_2,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014af14 @ 2014af14 (48 bytes)

int FUN_2014af14(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_40 [11];
  char local_35;
  
  iVar1 = FUN_2014aec8(param_1,auStack_40);
  if (iVar1 == 0) {
    FUN_20144800(0);
    iVar1 = (int)local_35;
  }
  return iVar1;
}


// ===== FUN_2014af44 @ 2014af44 (32 bytes)

undefined4 FUN_2014af44(int param_1,undefined4 param_2)

{
  FUN_2014d128(param_2,param_1 + 0x2c,4);
  return 0;
}


// ===== FUN_2014af64 @ 2014af64 (100 bytes)

void FUN_2014af64(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144878(param_1), iVar1 == 0)) {
    if (param_2 != 0) {
      uVar2 = FUN_2014af44(param_1,param_2);
      FUN_20144800(uVar2,param_1);
      return;
    }
    FUN_20144800(0xfffffff3,param_1);
    return;
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014afcc @ 2014afcc (84 bytes)

void FUN_2014afcc(uint param_1,undefined4 *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_20156260(0x800000,param_4 >> 9);
  if (param_1 < uVar1) {
    *param_2 = 0;
  }
  else {
    uVar2 = FUN_20156260(param_1,uVar1);
    param_1 = (uint)((ulonglong)uVar2 >> 0x20);
    *param_2 = (int)uVar2;
  }
  *param_3 = param_1 * param_4;
  return;
}


// ===== FUN_2014b020 @ 2014b020 (288 bytes)

undefined4 FUN_2014b020(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = DAT_20808ba0;
  iVar3 = FUN_2014d35c(param_1);
  if (iVar3 != *(char *)((int)piVar5 + 0x11)) {
    do {
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return 0xffffffef;
      }
      iVar3 = FUN_2014d35c(param_1);
    } while (iVar3 != *(char *)((int)piVar5 + 0x11));
  }
  cVar2 = (char)piVar5[4];
  if (cVar2 == '\f') {
    uVar6 = (uint)(piVar5[0x1b] * piVar5[3] * 2) / 3;
  }
  else if (cVar2 == '\x10') {
    uVar6 = ((uint)piVar5[0x1b] >> 1) * piVar5[3];
  }
  else {
    if (cVar2 != ' ') {
      return 0xfffffff3;
    }
    uVar6 = ((uint)piVar5[0x1b] >> 2) * piVar5[3];
  }
  iVar4 = piVar5[0x1b];
  iVar3 = FUN_20156260((uint)*(ushort *)((int)piVar5 + 10) << 5);
  uVar1 = *(ushort *)(piVar5 + 1);
  iVar3 = FUN_20156260(piVar5[5] -
                       (iVar3 + piVar5[3] * (uint)*(ushort *)(piVar5 + 2) +
                                (uint)*(ushort *)((int)piVar5 + 6)));
  if (iVar3 + 2U < uVar6) {
    uVar6 = iVar3 + 2U;
  }
  FUN_2014afcc((uint)uVar1 * (uVar6 - 2),param_2,param_3,iVar4);
  return 0;
}


// ===== FUN_2014b140 @ 2014b140 (156 bytes)

void FUN_2014b140(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = FUN_2014d35c(param_1);
      iVar2 = FUN_20144918(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_18), iVar2 != 0)) goto LAB_2014b1b0;
      uVar3 = FUN_2014d35c(param_1);
      uVar3 = FUN_2014b020(uVar3,param_2,param_3);
    }
    FUN_20144800(uVar3,0);
    return;
  }
LAB_2014b1b0:
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_2014b1e0 @ 2014b1e0 (436 bytes)

int FUN_2014b1e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int iStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar7 = 0;
  uVar3 = 0;
  uVar9 = 0;
  local_48 = 0;
  uVar6 = 0;
  local_44 = 0;
  uVar1 = *(ushort *)(param_1 + 4);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  if ((param_5 != 0) && (*(int *)(param_1 + 0x3c) != -1)) {
    FUN_2014afcc(*(int *)(param_1 + 0x3c) * (uint)uVar1,param_2,param_3,*(uint *)(param_1 + 0x6c));
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  uVar8 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),(uint)uVar1);
  uVar5 = 2;
  if (iVar2 + 2U < uVar8) {
    uVar8 = iVar2 + 2U;
  }
  local_40 = -1;
  if (2 < uVar8) {
    do {
      uVar11 = FUN_20156260(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar2 = (int)uVar11;
      local_3c = (int)((ulonglong)uVar11 >> 0x20) << 2;
      if ((local_40 != iVar2) &&
         (iVar4 = FUN_2014919c(param_1,iVar2,&local_44,local_28), local_40 = iVar2, iVar4 != 0)) {
        return iVar4;
      }
      if (local_44 == 0) {
        return -0xd;
      }
      iVar2 = FUN_2014d93c(local_44 + local_3c);
      if (iVar2 == 0) {
        bVar10 = uVar3 == 0;
        uVar3 = uVar3 + 1;
        if (bVar10) {
          uVar6 = uVar5;
        }
        iVar7 = iVar7 + 1;
      }
      else {
        if (uVar9 < uVar3) {
          uVar9 = uVar3;
          local_48 = uVar6;
        }
        uVar3 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar8);
    if (uVar3 < uVar9) {
      *(uint *)(param_1 + 0x40) = local_48;
      *(uint *)(param_1 + 0x28) = local_48;
      goto LAB_2014b36c;
    }
  }
  *(uint *)(param_1 + 0x40) = uVar6;
  *(uint *)(param_1 + 0x28) = uVar6;
LAB_2014b36c:
  *(int *)(param_1 + 0x3c) = iVar7;
  FUN_2014afcc((uint)*(ushort *)(param_1 + 4) * iVar7,local_30,local_2c,
               *(undefined4 *)(param_1 + 0x6c));
  return 0;
}


// ===== FUN_2014b394 @ 2014b394 (84 bytes)

undefined4
FUN_2014b394(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b1e0(param_1,param_2,param_3,param_4,param_5);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b3e8 @ 2014b3e8 (272 bytes)

int FUN_2014b3e8(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  int local_38;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar6 = 0;
  local_38 = 0;
  iVar3 = *(int *)(param_1 + 0xc);
  uVar5 = (*(uint *)(param_1 + 0x6c) >> 1) * iVar3;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar3 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar1 + iVar3 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar4 = 2;
  iVar1 = -1;
  if (iVar3 + 2U < uVar5) {
    uVar5 = iVar3 + 2U;
  }
  if (2 < uVar5) {
    do {
      uVar7 = FUN_20156260(uVar4,*(uint *)(param_1 + 0x6c) >> 1);
      iVar3 = (int)uVar7;
      if ((iVar1 != iVar3) &&
         (iVar2 = FUN_2014919c(param_1,iVar3,&local_38,local_28), iVar1 = iVar3, iVar2 != 0)) {
        return iVar2;
      }
      if (local_38 == 0) {
        return -0xd;
      }
      iVar3 = FUN_2014d900(local_38 + (int)((ulonglong)uVar7 >> 0x20) * 2);
      uVar4 = uVar4 + 1;
      if (iVar3 == 0) {
        iVar6 = iVar6 + 1;
      }
    } while (uVar4 < uVar5);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar6;
  return 0;
}


// ===== FUN_2014b500 @ 2014b500 (76 bytes)

undefined4 FUN_2014b500(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b3e8(param_1,param_2,param_3,param_4);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b54c @ 2014b54c (408 bytes)

int FUN_2014b54c(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar9 = 0;
  local_40 = 0;
  iVar5 = *(int *)(param_1 + 0xc);
  lVar1 = (ulonglong)(uint)(*(int *)(param_1 + 0x6c) * iVar5 * 2) * 0xaaaaaaab;
  uVar8 = ((uint)((ulonglong)lVar1 >> 0x20) & 0x1ffff) >> 1;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(int *)(param_1 + 0x6c),(int)lVar1);
  iVar5 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar5 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar6 = 2;
  iVar2 = -1;
  if ((iVar5 + 2U & 0xffff) < uVar8) {
    uVar8 = iVar5 + 2U & 0xffff;
  }
  if (2 < uVar8) {
    do {
      iVar7 = *(int *)(param_1 + 0x6c);
      iVar5 = FUN_20156260(uVar6 * 3,iVar7 << 1);
      iVar7 = (uVar6 * 3 >> 1) - iVar7 * iVar5;
      if ((iVar2 != iVar5) &&
         (iVar3 = FUN_2014919c(param_1,iVar5,&local_40,local_28), iVar2 = iVar5, iVar3 != 0)) {
        return iVar3;
      }
      if (local_40 == 0) {
        return -0xd;
      }
      local_3c = *(undefined1 *)(local_40 + iVar7);
      if (*(int *)(param_1 + 0x6c) + -1 == iVar7) {
        iVar2 = iVar5 + 1;
        iVar7 = -1;
        iVar5 = FUN_2014919c(param_1,iVar2,&local_40,local_28);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      local_3b = *(undefined1 *)(local_40 + iVar7 + 1);
      uVar4 = FUN_2014d900(&local_3c);
      if ((uVar6 & 1) != 0) {
        uVar4 = uVar4 >> 4;
      }
      uVar4 = uVar4 & 0xffff0fff;
      if (0xff6 < uVar4) {
        uVar4 = uVar4 | 0xf000;
      }
      if (uVar4 == 0) {
        iVar9 = iVar9 + 1;
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < uVar8);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar9;
  return 0;
}


// ===== FUN_2014b6e4 @ 2014b6e4 (76 bytes)

undefined4 FUN_2014b6e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b54c(param_1,param_2,param_3,param_4);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b730 @ 2014b730 (172 bytes)

void FUN_2014b730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int local_14;
  
  local_14 = DAT_20808ba0;
  uVar2 = FUN_2014d35c();
  iVar3 = FUN_20144918(uVar2,&local_14);
  if (iVar3 == 0) {
    cVar1 = *(char *)(local_14 + 0x10);
    if (cVar1 == '\f') {
      FUN_2014b6e4(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == '\x10') {
      FUN_2014b500(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == ' ') {
      FUN_2014b394(local_14,param_2,param_3,param_4,1);
    }
  }
  return;
}


// ===== FUN_2014b7dc @ 2014b7dc (164 bytes)

void FUN_2014b7dc(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = FUN_2014d35c(param_1);
      iVar2 = FUN_20144918(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_18), iVar2 != 0)) goto LAB_2014b850;
      uVar3 = FUN_2014d35c(param_1);
      uVar3 = FUN_2014b730(uVar3,param_2,param_3,param_4);
    }
    FUN_20144800(uVar3,0);
    return;
  }
LAB_2014b850:
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_2014b880 @ 2014b880 (84 bytes)

undefined4 FUN_2014b880(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014b7dc(param_1,param_2,param_3,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014b8d4 @ 2014b8d4 (104 bytes)

void FUN_2014b8d4(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,int param_5)

{
  FUN_2014d148(param_1,0,0x20,*(undefined4 *)(param_5 + 0x6c));
  FUN_2014d128(param_1,param_2,0xb);
  *(undefined1 *)(param_1 + 0xb) = param_3;
  FUN_201474a4(param_1,0,7);
  FUN_20147588(param_1,param_4,(int)*(char *)(param_5 + 0x10));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// ===== FUN_2014b93c @ 2014b93c (300 bytes)

int FUN_2014b93c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_48 [32];
  undefined1 local_28;
  undefined1 local_27;
  
  iVar1 = FUN_20144980();
  iVar4 = param_4 + 0xc0c;
  FUN_2014d148(iVar4,0,0x200);
  FUN_2014d148(&local_28,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_28 = 0x2e;
  FUN_2014b8d4(auStack_48,&local_28,0x10,param_2,param_1);
  FUN_2014d1c4(iVar4,auStack_48,0x20);
  local_27 = 0x2e;
  FUN_2014b8d4(auStack_48,&local_28,0x10,param_3,param_1);
  FUN_2014d1c4(param_4 + 0xc2c,auStack_48,0x20);
  iVar2 = FUN_20144ac0(param_1,iVar1,iVar4,1);
  if (iVar2 == 0) {
    FUN_2014d148(iVar4,0,0x200);
    uVar3 = 1;
    if (1 < *(ushort *)(param_1 + 4)) {
      do {
        iVar2 = FUN_20144ac0(param_1,iVar1 + uVar3,iVar4,1);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < *(ushort *)(param_1 + 4));
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ===== FUN_2014ba68 @ 2014ba68 (956 bytes)

int FUN_2014ba68(char *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_54;
  undefined1 auStack_50 [11];
  char local_45;
  uint local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  local_54 = DAT_20808ba0;
  uVar2 = FUN_2014d35c((int)*param_1);
  iVar3 = FUN_20144918(uVar2,&local_54);
  if (((iVar3 == 0) && (iVar3 = FUN_20144950(local_54), iVar3 == 0)) &&
     (iVar3 = FUN_20144970(local_54), iVar3 == 0)) {
    param_1 = param_1 + 2;
    iVar3 = *(int *)(local_54 + 0x34);
    if (*(char *)(local_54 + 0x10) != ' ') {
      param_1 = (char *)FUN_20147248(param_1,param_2);
      if ((param_1 == (char *)0x0) || (*param_2 == '\0')) {
        return -1;
      }
      iVar3 = FUN_20146338(local_54,param_2,auStack_50,0,0,auStack_28,param_2);
      if (*param_1 == '\0') {
        if (iVar3 == 0) {
          return -2;
        }
      }
      else if ((iVar3 != 0) || (iVar3 = FUN_201476f0((int)local_45,0x10), iVar3 != 0)) {
        return -4;
      }
      iVar3 = FUN_20146884(auStack_50,(int)*(char *)(local_54 + 0x10));
    }
    cVar1 = *param_1;
    iVar4 = 0;
    while (cVar1 != '\0') {
      param_1 = (char *)FUN_20147248(param_1,param_2);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_2 == '\0') {
        return -1;
      }
      iVar4 = FUN_201471cc(local_54,iVar3,param_2,auStack_50,0,0,auStack_28,auStack_24,param_2);
      if (*param_1 == '\0') {
        if (iVar4 == 0) {
          return -2;
        }
      }
      else {
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_201476f0((int)local_45,0x10);
        if (iVar4 != 0) {
          return -4;
        }
      }
      iVar5 = FUN_20146884(auStack_50,(int)*(char *)(local_54 + 0x10));
      iVar4 = iVar3;
      iVar3 = iVar5;
      cVar1 = *param_1;
    }
    FUN_2014d148(auStack_50,0,0x20,*(undefined4 *)(local_54 + 0x6c));
    iVar3 = FUN_20149dec(local_54,0,&local_30,param_2);
    if (iVar3 == 0) {
      if (local_30 == 0) {
        iVar3 = -0xb;
      }
      else {
        iVar3 = iVar4;
        if ((*(char *)(local_54 + 0x10) == ' ') && (*(int *)(local_54 + 0x34) == iVar4)) {
          iVar3 = 0;
        }
        iVar5 = FUN_2014b93c(local_54,local_30,iVar3,param_2);
        if (iVar5 == 0) {
          FUN_20147588(auStack_50,local_30,(int)*(char *)(local_54 + 0x10));
          local_45 = 0x10;
          FUN_201474a4(auStack_50,0,7);
          if (iVar4 == 0) {
            iVar5 = FUN_20146338(local_54,param_2,auStack_50,1,0,auStack_28,param_2);
          }
          else {
            iVar5 = FUN_201471cc(local_54,iVar4,param_2,auStack_50,1,0,auStack_28,auStack_24,param_2
                                );
          }
          if (iVar5 == 0) {
            iVar3 = FUN_2014a0a4(local_54,param_2);
            return iVar3;
          }
          iVar3 = FUN_201497cc(local_54,auStack_2c,local_30,0,0x77,param_2);
          if (iVar3 == 0) {
            if ((*(int *)(local_54 + 0x58) != 0) && (local_30 < *(uint *)(local_54 + 0x60))) {
              FUN_2014969c();
            }
            cVar1 = *(char *)(local_54 + 0x10);
            goto joined_r0x2014be00;
          }
        }
        else {
          iVar3 = FUN_201497cc(local_54,auStack_2c,local_30,0,0x77,param_2);
          if (iVar3 == 0) {
            if ((*(int *)(local_54 + 0x58) != 0) && (local_30 < *(uint *)(local_54 + 0x60))) {
              FUN_2014969c();
            }
            cVar1 = *(char *)(local_54 + 0x10);
joined_r0x2014be00:
            if (cVar1 == ' ') {
              *(int *)(local_54 + 0x3c) = *(int *)(local_54 + 0x3c) + 1;
            }
            return iVar5;
          }
        }
      }
    }
  }
  return iVar3;
}


// ===== FUN_2014be24 @ 2014be24 (200 bytes)

void FUN_2014be24(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_1 == 0) {
      uVar4 = 0xffffffff;
LAB_2014bee4:
      FUN_20144800(uVar4,0);
      return;
    }
    iVar2 = FUN_201473c4(param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_2014d220(param_1);
      iVar3 = param_2 + 0x100c;
      FUN_2014d288(iVar3,param_1,iVar2 + 1);
      FUN_2014cd68(iVar3);
      uVar1 = FUN_2014d35c((int)*(char *)(param_2 + 0x100c));
      iVar2 = FUN_20144918(uVar1,&local_10);
      if ((iVar2 == 0) && (iVar2 = FUN_2014ba68(iVar3,param_2), iVar2 == 0)) {
        uVar4 = FUN_20144688(local_10);
        goto LAB_2014bee4;
      }
    }
  }
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_2014beec @ 2014beec (68 bytes)

undefined4 FUN_2014beec(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014be24(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014bf30 @ 2014bf30 (812 bytes)

int * FUN_2014bf30(char *param_1,int *param_2,char *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_54;
  undefined1 auStack_50 [11];
  byte local_45;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [8];
  
  local_54 = DAT_20808ba0;
  FUN_2014485c(0);
  iVar2 = FUN_2014def4();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_2014485c(0xffffffd5,0);
    return piVar3;
  }
  if (param_2 == (int *)0x0) {
    iVar2 = 0;
    iVar5 = (int)DAT_20808b9c;
    param_2 = DAT_20808b98;
    if (0 < iVar5) {
      do {
        if ((char)param_2[1] == '\0') break;
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 0x93;
      } while (iVar2 < iVar5);
    }
    if (iVar2 == iVar5) {
      FUN_2014df20();
      iVar2 = -0xf;
      param_2 = (int *)0x0;
      goto LAB_2014c04c;
    }
  }
  *(undefined1 *)(param_2 + 1) = 0xff;
  FUN_2014df20();
  FUN_2014d148(auStack_50,0,0x20,*(undefined4 *)(local_54 + 0x6c));
  if (local_54 == 0) {
    *(undefined1 *)(param_2 + 1) = 0;
    param_2 = (int *)0x0;
    iVar2 = -0x11;
    goto LAB_2014c04c;
  }
  if (*param_1 == '/' || *param_1 == '\\') {
    *(undefined1 *)(param_2 + 1) = 1;
    iVar2 = 0;
    *(undefined1 *)((int)param_2 + 5) = 0;
    *param_2 = local_54;
    goto LAB_2014c04c;
  }
  uVar1 = FUN_2014d35c();
  iVar2 = FUN_20144918(uVar1,&local_54);
  if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_54), iVar2 != 0)) {
    *(undefined1 *)(param_2 + 1) = 0;
    param_2 = (int *)0x0;
    goto LAB_2014c04c;
  }
  uVar4 = FUN_2014d220(param_1);
  if (uVar4 < 4) {
    *(undefined1 *)(param_2 + 1) = 1;
    *(undefined2 *)((int)param_2 + 6) = 0;
    *param_2 = local_54;
    param_2[2] = *(int *)(local_54 + 0x34);
    *(undefined1 *)((int)param_2 + 5) = 1;
    if (*(char *)(local_54 + 0x10) == ' ') {
      iVar2 = FUN_20144980();
      param_2[3] = iVar2;
      iVar2 = 0;
    }
    else {
      param_2[3] = *(int *)(local_54 + 0xc) * (uint)*(ushort *)(local_54 + 8) +
                   (uint)*(ushort *)(local_54 + 6);
      iVar2 = 0;
    }
    goto LAB_2014c04c;
  }
  param_1 = param_1 + 2;
  uVar6 = *(undefined4 *)(local_54 + 0x34);
  if (*(char *)(local_54 + 0x10) == ' ') {
LAB_2014c17c:
    if (*param_1 != '\0') {
      do {
        param_1 = (char *)FUN_20147248(param_1,param_3);
        if ((param_1 == (char *)0x0) || (*param_3 == '\0')) goto LAB_2014c158;
        iVar2 = FUN_201468c0(local_54,uVar6,param_3,auStack_50,0,0,auStack_2c,auStack_30,param_3);
        if (iVar2 != 0) goto LAB_2014c24c;
        uVar6 = FUN_20146884(auStack_50,(int)*(char *)(local_54 + 0x10));
      } while (*param_1 != '\0');
    }
    iVar2 = FUN_20146884(auStack_50,(int)*(char *)(local_54 + 0x10));
    if ((local_45 & 0x10) != 0) {
      *(undefined1 *)((int)param_2 + 5) = 1;
      *(undefined1 *)(param_2 + 1) = 1;
      param_2[2] = iVar2;
      iVar2 = FUN_20144980(local_54,iVar2);
      param_2[3] = iVar2;
      *(undefined2 *)((int)param_2 + 6) = 0;
      *param_2 = local_54;
      return param_2;
    }
  }
  else {
    param_1 = (char *)FUN_20147248(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
LAB_2014c158:
      *(undefined1 *)(param_2 + 1) = 0;
      param_2 = (int *)0x0;
      iVar2 = -1;
      goto LAB_2014c04c;
    }
    iVar2 = FUN_20145df0(local_54,param_3,auStack_50,0,0,auStack_2c,param_3);
    if (iVar2 == 0) {
      uVar6 = FUN_20146884(auStack_50,(int)*(char *)(local_54 + 0x10));
      goto LAB_2014c17c;
    }
  }
LAB_2014c24c:
  *(undefined1 *)(param_2 + 1) = 0;
  param_2 = (int *)0x0;
  iVar2 = -4;
LAB_2014c04c:
  piVar3 = (int *)FUN_2014485c(iVar2,param_2);
  return piVar3;
}


// ===== FUN_2014c31c @ 2014c31c (424 bytes)

void FUN_2014c31c(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 local_18 [2];
  
  iVar2 = FUN_2014a4a4();
  if (iVar2 != 0) {
LAB_2014c394:
    FUN_2014485c(iVar2,0);
    return;
  }
  if (param_1 == 0) {
LAB_2014c3ec:
    FUN_2014485c(0xffffffff,0);
    return;
  }
  iVar2 = FUN_2014d220(param_1);
  pcVar3 = (char *)(param_2 + 0x100c);
  FUN_2014d288(pcVar3,param_1,iVar2 + 1);
  FUN_2014cd68(pcVar3);
  iVar2 = FUN_2014d220(pcVar3);
  if (iVar2 == 1) {
    if (*(char *)(param_2 + 0x100c) != '/' && *(char *)(param_2 + 0x100c) != '\\') {
LAB_2014c3d0:
      FUN_2014485c(0xfffffff4,0);
      return;
    }
  }
  else if (iVar2 == 2) {
    if ((0x19 < (int)*(char *)(param_2 + 0x100c) - 0x41U) &&
       (0x19 < (int)*(char *)(param_2 + 0x100c) - 0x61U)) goto LAB_2014c3d0;
    if (*(char *)(param_2 + 0x100d) != ':') goto LAB_2014c3ec;
  }
  else {
    iVar2 = FUN_201473c4(pcVar3);
    if (iVar2 != 0) goto LAB_2014c394;
  }
  local_18[0] = DAT_20808ba0;
  if (*pcVar3 == '/' || *pcVar3 == '\\') {
    uVar4 = FUN_2014bf30(pcVar3,0,param_2);
    iVar2 = FUN_2014d95c();
  }
  else {
    uVar1 = FUN_2014d35c();
    uVar5 = FUN_20144918(uVar1,local_18);
    iVar2 = (int)uVar5;
    if (iVar2 == 0) {
      iVar2 = FUN_2014d9c0(local_18[0],(int)((ulonglong)uVar5 >> 0x20));
      if (iVar2 == 0) {
        uVar4 = FUN_2014bf30(pcVar3,0,param_2);
        iVar2 = FUN_2014d95c();
        FUN_2014da64(local_18[0]);
      }
      else {
        uVar4 = 0;
        iVar2 = -0x25;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  FUN_2014485c(iVar2,uVar4);
  return;
}


// ===== FUN_2014c410 @ 2014c410 (68 bytes)

undefined4 FUN_2014c410(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014c31c(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_2014485c(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014c454 @ 2014c454 (32 bytes)

undefined4 FUN_2014c454(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xfffffff3;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_2014c474 @ 2014c474 (68 bytes)

void FUN_2014c474(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144898(param_1), iVar1 == 0)) {
    uVar2 = FUN_2014c454(param_1);
    FUN_20144800(uVar2,0);
    return;
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014c4bc @ 2014c4bc (80 bytes)

int FUN_2014c4bc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int local_10;
  
  local_10 = param_5 + 0xe0c;
  iVar1 = FUN_20144c5c(param_1,param_2,&local_10);
  if (iVar1 == 0) {
    FUN_2014d128(param_4,local_10 + param_3 * 0x20,0x20);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_2014c50c @ 2014c50c (380 bytes)

void FUN_2014c50c(int *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int extraout_r1;
  int iVar6;
  uint uVar7;
  int local_24 [2];
  
  iVar6 = *param_1;
  uVar7 = param_1[3];
  if ((char)param_1[1] == -2) {
    *(undefined1 *)(param_1 + 1) = 0xff;
    FUN_2014485c(0);
    return;
  }
  if ((char)param_1[1] != '\x01') {
    piVar4 = (int *)0x0;
    iVar2 = -0xd;
    goto LAB_2014c574;
  }
  iVar2 = FUN_20144950(iVar6);
  if ((iVar2 != 0) ||
     (iVar2 = FUN_2014c4bc(*param_1,uVar7,*(undefined2 *)((int)param_1 + 6),param_1 + 6,param_2),
     iVar2 != 0)) {
LAB_2014c5a0:
    piVar4 = (int *)0x0;
    goto LAB_2014c574;
  }
  piVar4 = param_1 + 6;
  if ((char)param_1[6] == '\0') {
    *(undefined1 *)(param_1 + 1) = 0xff;
    piVar4 = (int *)0x0;
  }
  else {
    *(short *)(param_1 + 4) = *(short *)((int)param_1 + 6);
    sVar1 = *(short *)((int)param_1 + 6) + 1;
    iVar2 = param_1[3];
    param_1[5] = iVar2;
    uVar5 = *(uint *)(iVar6 + 0x6c);
    *(short *)((int)param_1 + 6) = sVar1;
    FUN_20156260(sVar1,uVar5 >> 5);
    if (extraout_r1 == 0) {
      *(undefined2 *)((int)param_1 + 6) = 0;
      iVar3 = FUN_20156260((uint)*(ushort *)(iVar6 + 10) << 5,*(undefined4 *)(iVar6 + 0x6c));
      uVar5 = iVar3 + -1 +
              *(int *)(iVar6 + 0xc) * (uint)*(ushort *)(iVar6 + 8) + (uint)*(ushort *)(iVar6 + 6);
      if (uVar7 < uVar5) {
        param_1[3] = iVar2 + 1;
      }
      else {
        if (uVar5 != uVar7) {
          iVar2 = FUN_20149f68(*param_1,uVar7,local_24,param_2);
          if (iVar2 != 0) goto LAB_2014c5a0;
          if (local_24[0] != 0) {
            param_1[3] = local_24[0];
            goto LAB_2014c678;
          }
        }
        *(undefined1 *)(param_1 + 1) = 0xfe;
      }
    }
  }
LAB_2014c678:
  iVar2 = 0;
LAB_2014c574:
  FUN_2014485c(iVar2,piVar4);
  return;
}


// ===== FUN_2014c688 @ 2014c688 (812 bytes)

int * FUN_2014c688(int *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar10 = 0;
  iVar8 = *param_1;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  uVar11 = 0;
  FUN_2014485c(0,0);
  uVar9 = 0;
  if (*(char *)((int)param_1 + 5) == '\0') {
    piVar3 = (int *)0x0;
    if (*param_1 != 0) {
      param_1[0xe] = (int)(param_1 + 6);
      *(undefined1 *)(param_1 + 6) = *(undefined1 *)(*param_1 + 0x11);
      *(undefined1 *)((int)param_1 + 0x42) = *(undefined1 *)(*param_1 + 0x11);
      FUN_2014d270((int)param_1 + 0x19,&DAT_2014c9b4);
      FUN_2014d270((int)param_1 + 0x43,&DAT_2014c9b4);
      *param_1 = *(int *)*param_1;
      piVar3 = param_1 + 0xe;
    }
  }
  else {
    while( true ) {
      pbVar4 = (byte *)FUN_2014c50c(param_1,param_2);
      piVar3 = (int *)0x0;
      if (pbVar4 == (byte *)0x0) break;
      uVar5 = (uint)*pbVar4;
      if (uVar5 == 0x2e || uVar5 == 0xe5) {
        uVar10 = 0;
        uVar9 = uVar10;
      }
      else {
        if (pbVar4[0xb] != 0xf) {
          param_1[0xe] = (int)pbVar4;
          if (uVar10 == 0) {
            FUN_20147640((int)param_1 + 0x42,pbVar4,(int)(char)pbVar4[0xc]);
            if ((param_1[2] == *(int *)(iVar8 + 0x34)) && (*(char *)(iVar8 + 0x10) != ' ')) {
              *(short *)(param_1 + 0x10) =
                   ((short)param_1[5] -
                   ((short)*(undefined4 *)(iVar8 + 0xc) * *(short *)(iVar8 + 8) +
                   *(short *)(iVar8 + 6))) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                   (short)param_1[4];
              iVar8 = 0;
            }
            else {
              uVar7 = FUN_201449cc(*param_1,param_1[5]);
              sVar2 = FUN_20144980(*param_1,uVar7);
              *(short *)(param_1 + 0x10) =
                   ((short)param_1[5] - sVar2) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                   (short)param_1[4];
              iVar8 = FUN_201449cc(*param_1);
            }
            param_1[0xf] = iVar8;
          }
          cVar1 = (char)uVar10;
          do {
            if (uVar10 == 0) {
              return param_1 + 0xe;
            }
            cVar1 = cVar1 + -1;
            uVar10 = (uint)cVar1;
            uVar9 = 0;
            do {
              iVar8 = FUN_2014cc1c((int)param_1 + uVar11 + 0x42,
                                   param_2 + uVar10 * 0x1a + uVar9 + 0x1418);
              if ((iVar8 == 0) || (*(char *)((int)param_1 + uVar11 + 0x42) == '\0')) break;
              uVar11 = iVar8 + uVar11 & 0xffff;
              uVar9 = uVar9 + 2 & 0xff;
            } while (uVar9 < 0x19);
            *(undefined1 *)((int)param_1 + uVar11 + 0x42) = 0;
          } while( true );
        }
        if (uVar9 == 0) {
LAB_2014c78c:
          if (0x13 < (int)uVar10) goto LAB_2014c780;
          if (uVar10 == 0) goto LAB_2014c79c;
          goto LAB_2014c83c;
        }
        if ((uVar5 & 0xffffffbf) == uVar9 - 1) {
          uVar9 = uVar9 - 1 & 0xff;
          goto LAB_2014c78c;
        }
LAB_2014c780:
        uVar9 = 0;
        uVar10 = 0;
LAB_2014c79c:
        if ((*pbVar4 & 0x40) != 0) {
          uVar9 = uVar5 & 0xffffffbf;
          if ((param_1[2] == *(int *)(iVar8 + 0x34)) && (*(char *)(iVar8 + 0x10) != ' ')) {
            *(short *)(param_1 + 0x10) =
                 ((short)param_1[5] -
                 ((short)*(undefined4 *)(iVar8 + 0xc) * *(short *)(iVar8 + 8) +
                 *(short *)(iVar8 + 6))) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) + (short)param_1[4]
            ;
            iVar6 = 0;
          }
          else {
            uVar7 = FUN_201449cc(*param_1,param_1[5]);
            sVar2 = FUN_20144980(*param_1,uVar7);
            *(short *)(param_1 + 0x10) =
                 ((short)param_1[5] - sVar2) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                 (short)param_1[4];
            iVar6 = FUN_201449cc(*param_1);
          }
          param_1[0xf] = iVar6;
LAB_2014c83c:
          iVar6 = param_2 + uVar10 * 0x1a;
          FUN_2014d128(iVar6 + 0x1418,pbVar4 + 1,10);
          FUN_2014d128(iVar6 + 0x1422,pbVar4 + 0xe,0xc);
          FUN_2014d128(iVar6 + 0x142e,pbVar4 + 0x1c,4);
          uVar10 = (uint)(char)((char)uVar10 + '\x01');
        }
      }
    }
  }
  return piVar3;
}


// ===== FUN_2014ca08 @ 2014ca08 (148 bytes)

undefined4 FUN_2014ca08(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  iVar2 = FUN_2014a4a4();
  if ((iVar2 == 0) && (iVar2 = FUN_20144898(param_1), iVar2 == 0)) {
    uVar3 = *param_1;
    iVar2 = FUN_2014d9c0(uVar3);
    if (iVar2 != 0) {
      uVar3 = FUN_2014485c(0xffffffdb,0);
      return uVar3;
    }
    uVar1 = FUN_2014c688(param_1,param_2,extraout_r2,extraout_r3,unaff_r4,unaff_r5,unaff_r6,unaff_lr
                        );
    FUN_2014da64(uVar3);
    return uVar1;
  }
  uVar3 = FUN_2014485c(iVar2,0);
  return uVar3;
}


// ===== FUN_2014ca4c @ 2014ca4c (68 bytes)

undefined4 FUN_2014ca4c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014ca08(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_2014485c(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014ca90 @ 2014ca90 (40 bytes)

undefined4 FUN_2014ca90(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 - 0x81U < 0x1f) || (param_1 - 0xe0U < 0x1d)) {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_2014cab8 @ 2014cab8 (204 bytes)

uint FUN_2014cab8(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 - 0x20 < 0x5f) {
    if (uVar1 == 0x5c) {
      uVar1 = 0xa500;
    }
    else {
      uVar1 = uVar1 << 8;
    }
  }
  else {
    if (uVar1 - 0x81 < 0x1f) {
      return (uint)(ushort)(&DAT_20420756)[((uint)param_1[1] + uVar1 * 0x100) - 0x8140 & 0xffff] *
             0x100 + (uint)((ushort)(&DAT_20420756)
                                    [((uint)param_1[1] + uVar1 * 0x100) - 0x8140 & 0xffff] >> 8) &
             0xffff;
    }
    if (uVar1 - 0xa1 < 0x3f) {
      return (uVar1 + 0xfec0 & 0xff) * 0x100 + ((uVar1 + 0xfec0 & 0xffff) >> 8);
    }
    if (uVar1 - 0xe0 < 0x1d) {
      return (uint)(ushort)(&DAT_204244d0)[((uint)param_1[1] + uVar1 * 0x100) - 0xe040 & 0xffff] *
             0x100 + (uint)((ushort)(&DAT_204244d0)
                                    [((uint)param_1[1] + uVar1 * 0x100) - 0xe040 & 0xffff] >> 8) &
             0xffff;
    }
    uVar1 = 0xffff;
  }
  return uVar1;
}


// ===== FUN_2014cb84 @ 2014cb84 (152 bytes)

int FUN_2014cb84(char *param_1,undefined1 *param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  while( true ) {
    if (cVar1 == '\0') {
      *param_2 = 0;
      param_2[1] = 0;
      return iVar3;
    }
    iVar2 = FUN_2014ca90(*param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_2014cab8(param_1);
      param_1 = param_1 + 1;
    }
    else {
      iVar2 = FUN_2014cab8(param_1);
      *param_3 = 1;
      param_1 = param_1 + 2;
    }
    *param_2 = (char)((uint)iVar2 >> 8);
    param_2[1] = (char)iVar2;
    param_2 = param_2 + 2;
    if (iVar2 == 0xffff) break;
    cVar1 = *param_1;
    iVar3 = iVar3 + 1;
  }
  return -99;
}


// ===== FUN_2014cc1c @ 2014cc1c (332 bytes)

undefined4 FUN_2014cc1c(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *param_2;
  uVar3 = (uint)bVar1;
  uVar2 = uVar3 + (uint)param_2[1] * 0x100;
  if (uVar2 == 0) {
    *param_1 = 0;
    return 1;
  }
  if (uVar2 == 0xa5) {
    *param_1 = 0x5c;
    return 1;
  }
  if (uVar2 == 0x203e) {
    *param_1 = 0x7e;
    return 1;
  }
  if (((param_2[1] == 0xff) && (0x60 < uVar3)) && (uVar3 < 0xa0)) {
    *param_1 = bVar1 + 0x40;
  }
  else {
    if (0x5e < uVar2 - 0x20) {
      uVar3 = 0;
      do {
        if ((ushort)(&DAT_20420756)[uVar3] == uVar2) {
          *param_1 = (byte)(uVar3 + 0x8140 >> 8);
          param_1[1] = (byte)(uVar3 + 0x8140);
          return 2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x1ebd);
      uVar3 = 0;
      do {
        if ((ushort)(&DAT_204244d0)[uVar3] == uVar2) {
          *param_1 = (byte)(uVar3 + 0xe040 >> 8);
          param_1[1] = (byte)(uVar3 + 0xe040);
          return 2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x1cbd);
      return 0;
    }
    *param_1 = bVar1;
  }
  return 1;
}


// ===== FUN_2014cd68 @ 2014cd68 (652 bytes)

void FUN_2014cd68(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *extraout_r3;
  undefined2 *puVar4;
  int extraout_r12;
  bool bVar5;
  
  bVar1 = *param_1;
joined_r0x2014cd78:
  if (bVar1 == 0) {
    return;
  }
  iVar2 = FUN_2014ca90(*param_1);
  param_1 = extraout_r3;
  if (iVar2 != 0) {
    uVar3 = (uint)extraout_r3[1] + (uint)*extraout_r3 * 0x100;
    if (0xc < uVar3 - 0x8790) {
      if (uVar3 - 0xed40 < 0xbd) {
        if ((uVar3 - 0xed40 < 0x23) || (uVar3 - 0xed80 < 0x61)) {
          *extraout_r3 = (byte)(uVar3 + extraout_r12 >> 8);
          extraout_r3[1] = (byte)(uVar3 + extraout_r12);
        }
        else {
          if (0x81 < uVar3 - 0xede1) {
LAB_2014cea4:
            uVar3 = uVar3 + 0xd1d;
            *extraout_r3 = (byte)(uVar3 >> 8);
            goto LAB_2014ceb0;
          }
LAB_2014cec8:
          *extraout_r3 = (byte)(uVar3 + 0xd5f >> 8);
          extraout_r3[1] = (byte)(uVar3 + 0xd5f);
        }
        goto LAB_2014cfe0;
      }
      if (0xbc < uVar3 - 0xee40) {
        if (uVar3 - 0xfa4a < 0x12) {
          if (uVar3 - 0xfa4a < 10) {
            uVar3 = uVar3 - 0x72f6;
            *extraout_r3 = (byte)(uVar3 >> 8);
            goto LAB_2014ceb0;
          }
          puVar4 = &DAT_2042073e;
          iVar2 = 0;
          bVar5 = true;
          while (bVar5) {
            if ((ushort)(&DAT_2042073e)[iVar2 * 2] == uVar3) goto LAB_2014cf4c;
            iVar2 = iVar2 + 1;
            bVar5 = (&DAT_2042073e)[iVar2 * 2] != 0;
          }
        }
        goto LAB_2014cfe0;
      }
      if ((0x22 < uVar3 - 0xee40) && (0x60 < uVar3 - 0xee80)) {
        if (uVar3 - 0xee63 < 0x1c) goto LAB_2014cea4;
        if (uVar3 - 0xeee1 < 0xc) goto LAB_2014cec8;
        if (uVar3 - 0xeeef < 10) {
          *extraout_r3 = (byte)(uVar3 + 0xb51 >> 8);
          extraout_r3[1] = (byte)(uVar3 + 0xb51);
        }
        else if (((uVar3 != 0xee7f) && (uVar3 != 0xeeed)) && (uVar3 != 0xeeee)) {
          iVar2 = 0;
          puVar4 = &DAT_2042072a;
          do {
            if ((ushort)(&DAT_2042072a)[iVar2 * 2] == uVar3) goto LAB_2014cf4c;
            iVar2 = iVar2 + 1;
          } while ((&DAT_2042072a)[iVar2 * 2] != 0);
        }
        goto LAB_2014cfe0;
      }
      uVar3 = uVar3 + extraout_r12;
      *extraout_r3 = (byte)(uVar3 >> 8);
      goto LAB_2014ceb0;
    }
    iVar2 = 0;
    do {
      if ((ushort)(&DAT_20420702)[iVar2 * 2] == uVar3) {
        *extraout_r3 = (byte)((ushort)(&DAT_20420704)[iVar2 * 2] >> 8);
        uVar3 = (uint)*(byte *)(&DAT_20420704 + iVar2 * 2);
        goto LAB_2014ceb0;
      }
      iVar2 = iVar2 + 1;
    } while ((&DAT_20420702)[iVar2 * 2] != 0);
    goto LAB_2014cfe0;
  }
  goto LAB_2014cfe4;
LAB_2014cf4c:
  *extraout_r3 = (byte)((ushort)puVar4[iVar2 * 2 + 1] >> 8);
  uVar3 = (uint)*(byte *)(puVar4 + iVar2 * 2 + 1);
LAB_2014ceb0:
  extraout_r3[1] = (byte)uVar3;
LAB_2014cfe0:
  param_1 = extraout_r3 + 1;
LAB_2014cfe4:
  param_1 = param_1 + 1;
  bVar1 = *param_1;
  goto joined_r0x2014cd78;
}


// ===== FUN_2014cff4 @ 2014cff4 (92 bytes)

int FUN_2014cff4(char *param_1,char *param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (*param_1 != '\0' || (param_1[1] != '\0')); param_1 = param_1 + 2) {
    iVar1 = iVar1 + 1;
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2 = param_2 + 2;
  }
  *param_2 = '\0';
  param_2[1] = '\0';
  *param_3 = 1;
  return iVar1;
}


// ===== FUN_2014d050 @ 2014d050 (196 bytes)

int FUN_2014d050(char *param_1,byte *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0;
  pcVar4 = param_1;
  do {
    uVar3 = (uint)*param_2;
    iVar2 = uVar3 + (uint)param_2[1] * 0x100;
    if (iVar2 == 0) {
      *pcVar4 = '\0';
      return iVar6;
    }
    if (iVar2 == 0xa5) {
      *pcVar4 = '\\';
    }
    else if (iVar2 == 0x203e) {
      *pcVar4 = '~';
    }
    else {
      if (((param_2[1] == 0xff) && (0x60 < uVar3)) && (uVar3 < 0xa0)) {
        cVar1 = *param_2 + 0x40;
      }
      else {
        if (0x5e < iVar2 - 0x20U) {
          *param_1 = '\0';
          return 0;
        }
        cVar1 = FUN_2014d35c((int)(char)*param_2);
      }
      *pcVar4 = cVar1;
    }
    iVar5 = iVar5 + 1;
    pcVar4 = pcVar4 + 1;
    param_2 = param_2 + 2;
    iVar6 = iVar6 + 1;
  } while (iVar5 < 0xc);
  return iVar6;
}


// ===== FUN_2014d128 @ 2014d128 (32 bytes)

void FUN_2014d128(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_2014d148 @ 2014d148 (124 bytes)

void FUN_2014d148(undefined4 *param_1,undefined1 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (((uint)param_1 & 3) == 0 && param_3 == param_4) {
    param_4 = param_4 >> 5;
    uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (param_4 != 0) {
      do {
        param_4 = param_4 - 1;
        *param_1 = uVar1;
        param_1[1] = uVar1;
        param_1[2] = uVar1;
        param_1[3] = uVar1;
        param_1[4] = uVar1;
        param_1[5] = uVar1;
        param_1[6] = uVar1;
        param_1[7] = uVar1;
        param_1 = param_1 + 8;
      } while (param_4 != 0);
      return;
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
  }
  return;
}


// ===== FUN_2014d1c4 @ 2014d1c4 (92 bytes)

void FUN_2014d1c4(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  puVar1 = param_1 + param_3;
  if (param_2 < param_1 && param_1 < puVar2) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *puVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
    }
  }
  else if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (param_3 != 0);
    return;
  }
  return;
}


// ===== FUN_2014d220 @ 2014d220 (40 bytes)

int FUN_2014d220(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
  }
  return iVar2;
}


// ===== FUN_2014d248 @ 2014d248 (40 bytes)

int FUN_2014d248(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    sVar1 = *param_1;
  }
  return iVar2 << 1;
}


// ===== FUN_2014d270 @ 2014d270 (24 bytes)

void FUN_2014d270(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_2;
    *param_1 = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

