// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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


// ===== FUN_201640ec @ 201640ec (24 bytes)

undefined4 FUN_201640ec(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,10);
  return param_1;
}


// ===== FUN_20164104 @ 20164104 (24 bytes)

undefined4 FUN_20164104(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,0x20);
  return param_1;
}


// ===== FUN_2016411c @ 2016411c (24 bytes)

undefined4 FUN_2016411c(undefined4 param_1,undefined4 param_2)

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


// ===== FUN_20164334 @ 20164334 (44 bytes)

void FUN_20164334(int param_1,undefined4 param_2)

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


// ===== FUN_20164360 @ 20164360 (28 bytes)

undefined4 FUN_20164360(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_20164788();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_2016437c @ 2016437c (12 bytes)

void FUN_2016437c(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20164388 @ 20164388 (28 bytes)

undefined4 FUN_20164388(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_201647d0();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643a4 @ 201643a4 (12 bytes)

void FUN_201643a4(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_201643b0 @ 201643b0 (28 bytes)

undefined4 FUN_201643b0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_20164814();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643cc @ 201643cc (28 bytes)

undefined4 FUN_201643cc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_2016485c();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643f0 @ 201643f0 (28 bytes)

undefined2 FUN_201643f0(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = *param_1;
  uVar2 = FUN_20164870();
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
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  return;
}


// ===== FUN_20164454 @ 20164454 (12 bytes)

void FUN_20164454(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_20164460 @ 20164460 (60 bytes)

void FUN_20164460(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  return;
}


// ===== FUN_201644a0 @ 201644a0 (12 bytes)

void FUN_201644a0(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_201644ac @ 201644ac (56 bytes)

undefined4 FUN_201644ac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x84),1);
  iVar1 = FUN_201643f0(param_1);
  uVar2 = *(undefined4 *)(param_1 + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== FUN_201644e4 @ 201644e4 (60 bytes)

void FUN_201644e4(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
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


// ===== FUN_201645a0 @ 201645a0 (68 bytes)

void FUN_201645a0(ushort *param_1,undefined4 *param_2)

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


// ===== FUN_201645e4 @ 201645e4 (20 bytes)

void FUN_201645e4(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== FUN_201645f8 @ 201645f8 (12 bytes)

void FUN_201645f8(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 8) = param_3;
  return;
}


// ===== FUN_20164604 @ 20164604 (52 bytes)

undefined4 FUN_20164604(short *param_1)

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


// ===== FUN_20164638 @ 20164638 (20 bytes)

undefined4 FUN_20164638(undefined4 param_1)

{
  FUN_201645e4();
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


// ===== FUN_20164758 @ 20164758 (44 bytes)

int FUN_20164758(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 100) % 100;
}


// ===== FUN_20164788 @ 20164788 (20 bytes)

int FUN_20164788(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 100) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_2016479c @ 2016479c (48 bytes)

int FUN_2016479c(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x85 + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x99fc267 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return ((iVar1 >> 7) - (iVar1 >> 0x1f)) * -0x85 + uVar2;
}


// ===== FUN_201647d0 @ 201647d0 (20 bytes)

int FUN_201647d0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x85) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_201647e4 @ 201647e4 (44 bytes)

int FUN_201647e4(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 0x14) % 0x14;
}


// ===== FUN_20164814 @ 20164814 (20 bytes)

int FUN_20164814(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x14) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20164828 @ 20164828 (48 bytes)

int FUN_20164828(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x1e + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x77777777 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return uVar2 + ((iVar1 >> 4) - (iVar1 >> 0x1f)) * -0x1e;
}


// ===== FUN_2016485c @ 2016485c (20 bytes)

int FUN_2016485c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x1e) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20164870 @ 20164870 (24 bytes)

short FUN_20164870(short *param_1)

{
  short sVar1;
  
  sVar1 = *param_1 + 1;
  if (sVar1 == 0x20) {
    sVar1 = 0;
  }
  return sVar1;
}

