// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201630cc @ 201630cc (324 bytes)

void FUN_201630cc(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_3 == 7) {
    uVar2 = 0x40;
  }
  if (param_4 != 0) {
    if (param_4 == 1) {
      uVar2 = uVar2 | 0x20;
    }
    else if (param_4 == 2) {
      uVar2 = uVar2 | 0x30;
    }
  }
  if (param_5 != 1) {
    uVar2 = uVar2 | 8;
  }
  if (param_2 < 0x54600) {
    cVar1 = FUN_20156260(64000000,param_2 << 5);
    cVar1 = cVar1 + -1;
  }
  else {
    cVar1 = '\x16';
  }
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  *(undefined2 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x81c) = 0;
  *(undefined4 *)(param_1 + 0x820) = 0;
  *(undefined4 *)(param_1 + 0x828) = 0;
  *(undefined4 *)(param_1 + 0x82c) = 0;
  *(undefined4 *)(param_1 + 0x830) = 0;
  *(undefined4 *)(param_1 + 0x834) = 0;
  *(undefined4 *)(param_1 + 0x838) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 6;
  *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xff6e;
  *(undefined2 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  **(ushort **)(param_1 + 4) = uVar2;
  *(char *)(*(int *)(param_1 + 4) + 4) = cVar1;
  if (param_2 < 0x54600) {
    *(undefined2 *)(*(int *)(param_1 + 4) + 0x28) = 0;
  }
  else {
    *(ushort *)(*(int *)(param_1 + 4) + 0x28) = *(ushort *)(*(int *)(param_1 + 4) + 0x28) | 0x81;
  }
  if ((param_5 & 0x80) != 0) {
    *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 1;
  }
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) & 0xfff9;
  *(ushort *)(*(int *)(param_1 + 4) + 8) = *(ushort *)(*(int *)(param_1 + 4) + 8) | 0xf8;
  return;
}


// ===== FUN_20163218 @ 20163218 (104 bytes)

int FUN_20163218(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2 + iVar2,param_3 - iVar2);
    iVar2 = iVar2 + iVar1;
    if (iVar2 == param_3) {
      return param_3;
    }
    if (param_4 < iVar3) break;
    itron_dly_tsk(1);
  }
  return -1;
}


// ===== FUN_20163280 @ 20163280 (88 bytes)

undefined4 FUN_20163280(int param_1)

{
  FUN_201177a0(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  FUN_201177a0(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  *(undefined2 *)(param_1 + 0x40c) = 0;
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return 0;
}


// ===== FUN_20163360 @ 20163360 (12 bytes)

void FUN_20163360(undefined4 *param_1)

{
  *param_1 = &PTR_uart_obj_init_2042803c;
  return;
}


// ===== FUN_201633a0 @ 201633a0 (108 bytes)

void FUN_201633a0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_4 == 0) {
    iVar2 = 0;
    do {
      *(undefined1 *)(param_2 + iVar2) =
           *(undefined1 *)(param_1 + (*(byte *)(param_3 + iVar2) ^ param_5));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 800);
    return;
  }
  iVar2 = 0;
  do {
    iVar1 = FUN_201341cc(*(byte *)(param_3 + iVar2) ^ param_5,param_4);
    *(undefined1 *)(param_2 + iVar2) = *(undefined1 *)(param_1 + iVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 800);
  return;
}


// ===== FUN_20163428 @ 20163428 (160 bytes)

undefined4 FUN_20163428(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = param_1 + param_2 * 800 + 0xa323;
  param_1 = param_1 + param_2 * 0x100;
  if (param_3 == 8) {
    FUN_201633a0(param_1,param_4,iVar1,param_5,0);
    return DAT_20473b78;
  }
  if (param_3 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_4,iVar1,param_5,0);
    return DAT_20474c64;
  }
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return 0;
}


// ===== FUN_201635b8 @ 201635b8 (44 bytes)

void FUN_201635b8(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 0xe);
  param_2[1] = *(undefined1 *)(param_1 + 0xf);
  param_2[2] = *(undefined1 *)(param_1 + 0x11);
  param_2[3] = *(undefined1 *)(param_1 + 0x12);
  param_2[4] = 0;
  return;
}


// ===== FUN_201635e4 @ 201635e4 (24 bytes)

void FUN_201635e4(int param_1,undefined4 param_2)

{
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_8;
  int iStack_4;
  
  iStack_1c = param_1 + 0xe;
  iStack_8 = param_1 + 4;
  uStack_20 = param_2;
  iStack_4 = iStack_1c;
  FUN_20155f72(&UNK_20428286,&uStack_20,&iStack_8,0x20155f99);
  FUN_20155f98(0,&uStack_20);
  return;
}


// ===== FUN_20163600 @ 20163600 (84 bytes)

undefined4 FUN_20163600(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*param_1 == param_3) && (iVar1 = FUN_2014e250(param_1[1],param_2,param_1[3]), iVar1 == 0))
     && (iVar1 = FUN_2014e250(param_1[2],param_1[4] + param_2,param_1[5]), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_20163654 @ 20163654 (16 bytes)

bool FUN_20163654(int param_1)

{
  return *(int *)(param_1 + 0x818) != 0;
}


// ===== FUN_20163668 @ 20163668 (28 bytes)

void FUN_20163668(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    *(undefined1 *)(param_1 + 2) = 0;
    puVar1 = param_1;
  }
  else {
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_20163684 @ 20163684 (36 bytes)

void FUN_20163684(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    param_1[2] = 0;
    puVar1 = param_1;
  }
  else {
    *(undefined1 *)((int)param_1 + 5) = 0;
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_201636a8 @ 201636a8 (16 bytes)

void FUN_201636a8(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ===== FUN_201636b8 @ 201636b8 (20 bytes)

void FUN_201636b8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


// ===== FUN_201636cc @ 201636cc (44 bytes)

void FUN_201636cc(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  return;
}


// ===== FUN_201636f8 @ 201636f8 (52 bytes)

void FUN_201636f8(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  return;
}


// ===== FUN_2016372c @ 2016372c (68 bytes)

void FUN_2016372c(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  return;
}


// ===== FUN_20163770 @ 20163770 (28 bytes)

void FUN_20163770(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  return;
}


// ===== FUN_2016378c @ 2016378c (20 bytes)

void FUN_2016378c(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  return;
}


// ===== FUN_201637a0 @ 201637a0 (28 bytes)

void FUN_201637a0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
  return;
}


// ===== FUN_201637bc @ 201637bc (28 bytes)

void FUN_201637bc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
  return;
}


// ===== FUN_201637d8 @ 201637d8 (24 bytes)

void FUN_201637d8(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = param_2 & 0xff | param_2 << 8;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// ===== FUN_201637f0 @ 201637f0 (24 bytes)

void FUN_201637f0(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  return;
}


// ===== FUN_20163808 @ 20163808 (40 bytes)

uint FUN_20163808(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    uVar1 = 4;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 == 0x7ff) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 == 1) {
    uVar1 = 5;
  }
  return uVar1;
}


// ===== FUN_20163864 @ 20163864 (14 bytes)

undefined4 FUN_20163864(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}


// ===== FUN_20163874 @ 20163874 (34 bytes)

undefined4 FUN_20163874(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (iVar1 = strcmp(0x204286fc), iVar1 != 0))
  {
    return 0;
  }
  return 0x20428704;
}


// ===== FUN_201638a0 @ 201638a0 (34 bytes)

undefined4 FUN_201638a0(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (iVar1 = strcmp(0x2042880c), iVar1 != 0))
  {
    return 0;
  }
  return 0x20428814;
}


// ===== FUN_201638cc @ 201638cc (12 bytes)

void FUN_201638cc(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_201638d8 @ 201638d8 (40 bytes)

void FUN_201638d8(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x4b0);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x968) = param_1;
  return;
}


// ===== FUN_20163900 @ 20163900 (56 bytes)

void FUN_20163900(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (iVar3 < 0x4b0);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0x25a] = param_1;
  return;
}


// ===== FUN_20163938 @ 20163938 (264 bytes)

void FUN_20163938(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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


// ===== FUN_20163a40 @ 20163a40 (160 bytes)

void FUN_20163a40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
            FUN_20163938(param_1,iVar1,param_3,param_4,param_5,uVar3 - iVar1,iVar2);
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


// ===== FUN_20163ae0 @ 20163ae0 (44 bytes)

void FUN_20163ae0(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x870);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x10e8) = param_1;
  return;
}


// ===== FUN_20163b0c @ 20163b0c (12 bytes)

void FUN_20163b0c(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_20163b18 @ 20163b18 (48 bytes)

void FUN_20163b18(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x15cc);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x2ba0) = param_1;
  return;
}


// ===== FUN_20163b48 @ 20163b48 (12 bytes)

undefined4 FUN_20163b48(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2ba0);
}


// ===== FUN_20163b54 @ 20163b54 (72 bytes)

void FUN_20163b54(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (iVar3 < 0x15cc);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0xae8] = param_1;
  return;
}


// ===== FUN_20163b9c @ 20163b9c (264 bytes)

void FUN_20163b9c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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


// ===== FUN_201640ec @ 201640ec (24 bytes)

undefined4 FUN_201640ec(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,10);
  return param_1;
}

