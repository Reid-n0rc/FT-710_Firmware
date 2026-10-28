// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20119990 @ 20119990 (784 bytes)

void FUN_20119990(int param_1,char *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = param_1 * 0x228;
  puVar2 = *(uint **)(&DAT_20165ce4 + iVar1);
  if (*(ushort **)(param_2 + 0x10) == (ushort *)0x0) {
    *puVar2 = *puVar2 & 0xfffffffe;
    **(uint **)(&DAT_20165d9c + iVar1) = **(uint **)(&DAT_20165d9c + iVar1) & 0xfffffffe;
    **(uint **)(&DAT_20165ce8 + iVar1) = **(uint **)(&DAT_20165ce8 + iVar1) & 0xfffffffe;
    **(uint **)(&DAT_20165ce8 + iVar1) = **(uint **)(&DAT_20165ce8 + iVar1) | 0xffff0000;
    **(uint **)(&DAT_20165da0 + iVar1) = **(uint **)(&DAT_20165da0 + iVar1) & 0xfffffffe;
    puVar2 = *(uint **)(&DAT_20165da0 + iVar1);
    uVar3 = *puVar2 | 0xffff0000;
  }
  else {
    *puVar2 = (uint)**(ushort **)(param_2 + 0x10) << 0x10;
    **(int **)(&DAT_20165d9c + iVar1) = (uint)**(ushort **)(param_2 + 0x10) << 0x10;
    **(int **)(&DAT_20165ce8 + iVar1) = (uint)*(ushort *)(*(int *)(param_2 + 0x10) + 2) << 0x10;
    **(int **)(&DAT_20165da0 + iVar1) = (uint)*(ushort *)(*(int *)(param_2 + 0x10) + 2) << 0x10;
    **(uint **)(&DAT_20165ce4 + iVar1) = **(uint **)(&DAT_20165ce4 + iVar1) | 1;
    **(uint **)(&DAT_20165d9c + iVar1) = **(uint **)(&DAT_20165d9c + iVar1) | 1;
    **(uint **)(&DAT_20165ce8 + iVar1) = **(uint **)(&DAT_20165ce8 + iVar1) | 1;
    puVar2 = *(uint **)(&DAT_20165da0 + iVar1);
    uVar3 = *puVar2 | 1;
  }
  *puVar2 = uVar3;
  **(uint **)(&DAT_20165e54 + iVar1) = **(uint **)(&DAT_20165e54 + iVar1) & 0xfffffffe;
  **(uint **)(&DAT_20165e58 + iVar1) = **(uint **)(&DAT_20165e58 + iVar1) & 0xfffffffe;
  **(uint **)(&DAT_20165cf0 + iVar1) = (uint)*(ushort *)(param_2 + 4);
  **(uint **)(&DAT_20165da8 + iVar1) = (uint)*(ushort *)(param_2 + 4);
  **(uint **)(&DAT_20165e60 + iVar1) = (uint)*(ushort *)(param_2 + 4);
  puVar2 = *(uint **)(&DAT_20165cec + iVar1);
  if (*param_2 == '\0') {
    *puVar2 = *puVar2 & 0xfffffffe;
    puVar2 = *(uint **)(&DAT_20165da4 + iVar1);
    uVar3 = *puVar2 & 0xfffffffe;
  }
  else {
    *puVar2 = *puVar2 | 1;
    **(uint **)(&DAT_20165da4 + iVar1) = **(uint **)(&DAT_20165da4 + iVar1) | 1;
    **(uint **)(&DAT_20165cf0 + iVar1) = **(uint **)(&DAT_20165cf0 + iVar1) & 0xf800ffff;
    **(uint **)(&DAT_20165cf0 + iVar1) =
         **(uint **)(&DAT_20165cf0 + iVar1) | (uint)*(ushort *)(param_2 + 2) << 0x10;
    **(uint **)(&DAT_20165da8 + iVar1) = **(uint **)(&DAT_20165da8 + iVar1) & 0xf800ffff;
    puVar2 = *(uint **)(&DAT_20165da8 + iVar1);
    uVar3 = *puVar2 | (uint)*(ushort *)(param_2 + 2) << 0x10;
  }
  *puVar2 = uVar3;
  **(uint **)(&DAT_20165e5c + iVar1) = **(uint **)(&DAT_20165e5c + iVar1) & 0xfffffffe;
  **(uint **)(&DAT_20165cec + iVar1) = **(uint **)(&DAT_20165cec + iVar1) & 0xfffffeff;
  **(uint **)(&DAT_20165da4 + iVar1) = **(uint **)(&DAT_20165da4 + iVar1) | 0x100;
  **(uint **)(&DAT_20165cf4 + iVar1) = **(uint **)(&DAT_20165cf4 + iVar1) & 0xffffff00;
  **(uint **)(&DAT_20165cf4 + iVar1) =
       **(uint **)(&DAT_20165cf4 + iVar1) | (uint)*(ushort *)(param_2 + 6);
  **(uint **)(&DAT_20165dac + iVar1) = **(uint **)(&DAT_20165dac + iVar1) & 0xffffff00;
  **(uint **)(&DAT_20165dac + iVar1) =
       **(uint **)(&DAT_20165dac + iVar1) | (uint)*(ushort *)(param_2 + 6);
  **(uint **)(&DAT_20165e64 + iVar1) = **(uint **)(&DAT_20165e64 + iVar1) & 0xffffff00;
  **(uint **)(&DAT_20165e64 + iVar1) = **(uint **)(&DAT_20165e64 + iVar1) | 1;
  uVar4 = CONCAT22(*(undefined2 *)(param_2 + 8),*(undefined2 *)(param_2 + 10));
  **(undefined4 **)(&DAT_20165cf8 + iVar1) = uVar4;
  **(undefined4 **)(&DAT_20165db0 + iVar1) = uVar4;
  **(undefined4 **)(&DAT_20165e68 + iVar1) = uVar4;
  uVar4 = CONCAT22(*(undefined2 *)(param_2 + 0xc),*(undefined2 *)(param_2 + 0xe));
  *(undefined4 *)(&PTR_DAT_20165cfc)[param_1 * 0x8a] = uVar4;
  *(undefined4 *)(&PTR_DAT_20165db4)[param_1 * 0x8a] = uVar4;
  **(undefined4 **)(&DAT_20165e6c + iVar1) = uVar4;
  **(uint **)(&DAT_20165ce0 + iVar1) = **(uint **)(&DAT_20165ce0 + iVar1) | 0x110;
  **(uint **)(&DAT_20165d98 + iVar1) = **(uint **)(&DAT_20165d98 + iVar1) | 0x110;
  **(uint **)(&DAT_20165e50 + iVar1) = **(uint **)(&DAT_20165e50 + iVar1) | 0x110;
  FUN_201198dc(param_1);
  FUN_2011d58c(param_1,0);
  return;
}


// ===== FUN_20119cd0 @ 20119cd0 (232 bytes)

void FUN_20119cd0(int param_1,int param_2,char *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_2 != -1) {
    if ((param_2 - 3U < 6) && (*param_3 != -1)) {
      puVar2 = (undefined4 *)(&DAT_201662c0 + (param_2 + -3) * 0x58 + param_1 * 0x210);
      *(uint *)puVar2[8] = *(uint *)puVar2[8] & 0xfffffffc;
      *(uint *)puVar2[8] = (int)*param_3 | *(uint *)puVar2[8];
      *(uint *)*puVar2 = *(uint *)*puVar2 | 0x10;
    }
    return;
  }
  uVar1 = 0;
  do {
    if (param_3[uVar1] != -1) {
      puVar2 = (undefined4 *)(&DAT_201662c0 + uVar1 * 0x58 + param_1 * 0x210);
      *(uint *)puVar2[8] = *(uint *)puVar2[8] & 0xfffffffc;
      *(uint *)puVar2[8] = *(uint *)puVar2[8] | (int)param_3[uVar1];
      *(uint *)*puVar2 = *(uint *)*puVar2 | 0x10;
    }
    do {
      uVar1 = uVar1 + 1;
      if (5 < uVar1) {
        return;
      }
    } while (uVar1 == 4);
  } while( true );
}


// ===== FUN_20119db8 @ 20119db8 (28 bytes)

uint FUN_20119db8(uint param_1)

{
  return (param_1 & 0xffffff) >> 0x10 | (param_1 & 0xffff) << 8 | param_1 & 0xff000000;
}


// ===== FUN_20119dd4 @ 20119dd4 (140 bytes)

void FUN_20119dd4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar1 = FUN_2011d61c(param_1,0);
  uVar2 = FUN_20119db8();
  uVar3 = 2;
  do {
    **(uint **)(&DAT_201662c0 + uVar3 * 0x58 + param_1 * 0x210 + 0x4c) = uVar2 & 0xffffff;
    puVar4 = *(uint **)(&DAT_201662c0 + uVar3 * 0x58 + param_1 * 0x210);
    *puVar4 = *puVar4 | 0x10;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 6);
  **(undefined4 **)(&DAT_20165eb8 + param_1 * 0x228) = uVar1;
  **(uint **)(&DAT_20165e50 + param_1 * 0x228) = **(uint **)(&DAT_20165e50 + param_1 * 0x228) | 0x10
  ;
  return;
}


// ===== FUN_20119e60 @ 20119e60 (660 bytes)

void FUN_20119e60(int param_1,ushort *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 local_78 [4];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c [14];
  
  local_5c[0] = 0x40;
  local_5c[1] = 0x20;
  local_5c[2] = 0x10;
  local_5c[3] = 8;
  local_5c[4] = 4;
  local_5c[5] = 2;
  local_5c[6] = 1;
  local_5c[0xc] = 0xff;
  local_5c[0xb] = 0x1010100;
  local_5c[7] = 0;
  local_5c[8] = 0x10000;
  local_5c[9] = 0x20000;
  local_5c[10] = 0;
  iVar1 = param_1 * 0x60;
  **(int **)(&DAT_20166714 + iVar1) = (uint)*param_2 << 0x10;
  **(uint **)(&DAT_20166714 + iVar1) = **(uint **)(&DAT_20166714 + iVar1) | (uint)param_2[1];
  local_78[0] = *(undefined4 *)(&DAT_2016671c + iVar1);
  local_78[1] = *(undefined4 *)(&DAT_20166724 + iVar1);
  local_78[2] = *(undefined4 *)(&DAT_2016672c + iVar1);
  local_78[3] = *(undefined4 *)(&DAT_20166734 + iVar1);
  local_68 = *(undefined4 *)(&DAT_2016673c + iVar1);
  local_64 = *(undefined4 *)(&DAT_20166744 + iVar1);
  local_60 = *(undefined4 *)(&DAT_2016674c + iVar1);
  *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18] =
       *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18] & 0xffffff80;
  uVar5 = 0;
  puVar4 = param_2;
  do {
    puVar4 = puVar4 + 2;
    if (*(int *)puVar4 != 0) {
      (*(code *)(&DAT_20165c24)[uVar5])(*(int *)puVar4,&DAT_20166710 + iVar1);
      iVar3 = (int)*(char *)(*(int *)puVar4 + 7);
      if (iVar3 != -1) {
        puVar2 = (uint *)local_78[iVar3];
        *puVar2 = *puVar2 & 0xfffffff8;
        *puVar2 = *puVar2 | uVar5;
        if (*(char *)(*(int *)puVar4 + 8) != '\0') {
          *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18] =
               local_5c[iVar3] | *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18];
        }
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  **(uint **)(&DAT_20166758 + iVar1) = **(uint **)(&DAT_20166758 + iVar1) & 0xeeffccec;
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    **(uint **)(&DAT_20166758 + iVar1) = **(uint **)(&DAT_20166758 + iVar1) | 0x10000000;
  }
  if ((char)param_2[0x13] != '\0') {
    **(uint **)(&DAT_20166758 + iVar1) = **(uint **)(&DAT_20166758 + iVar1) | 0x1000000;
  }
  **(uint **)(&DAT_20166758 + iVar1) =
       **(uint **)(&DAT_20166758 + iVar1) | (uint)*(byte *)((int)param_2 + 0x27) << 0xc;
  **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) & 0xfffcffff;
  **(uint **)(&DAT_20166768 + iVar1) =
       **(uint **)(&DAT_20166768 + iVar1) | local_5c[*(byte *)((int)param_2 + 0x27) + 7];
  puVar2 = *(uint **)(&DAT_20166758 + iVar1);
  uVar5 = *puVar2;
  if (*(char *)((int)param_2 + 0x27) == '\x03') {
    *puVar2 = uVar5 | (uint)(byte)param_2[0x14] << 8;
    if (*(char *)((int)param_2 + 0x29) != '\0') {
      **(uint **)(&DAT_20166758 + iVar1) = **(uint **)(&DAT_20166758 + iVar1) | 0x10;
    }
    puVar2 = *(uint **)(&DAT_20166758 + iVar1);
    uVar5 = *puVar2 | (uint)(byte)param_2[0x15];
  }
  *puVar2 = uVar5;
  uVar5 = *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18];
  if ((char)param_2[0x12] == '\0') {
    uVar5 = uVar5 & 0xfffffeff;
  }
  else {
    uVar5 = uVar5 | 0x100;
  }
  *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18] = uVar5;
  FUN_20119dd4(param_1);
  FUN_20119cd0(param_1,0xffffffff,local_5c + 0xb);
  puVar2 = *(uint **)(&DAT_20166710 + iVar1);
  *puVar2 = *puVar2 | 1;
  **(uint **)(&DAT_20166754 + iVar1) = **(uint **)(&DAT_20166754 + iVar1) | 1;
  return;
}


// ===== FUN_2011a290 @ 2011a290 (260 bytes)

void FUN_2011a290(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint *puVar5;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar2 = *(ushort *)(param_1 + 6);
  uVar3 = *(ushort *)(param_1 + 10);
  uVar4 = *(ushort *)(param_1 + 0xc);
  **(uint **)(param_3 + 0x2c) = **(uint **)(param_3 + 0x2c) | 0x10;
  **(uint **)(param_3 + 0x48) = **(uint **)(param_3 + 0x48) & 0xffffffef;
  if (uVar3 < uVar1) {
    **(undefined4 **)(param_3 + 0x40) = 0x1000;
  }
  else {
    **(undefined4 **)(param_3 + 0x40) = 0x1000;
  }
  puVar5 = *(uint **)(param_3 + 0x2c);
  if (uVar4 < uVar2) {
    *puVar5 = *puVar5 | 1;
    **(uint **)(param_3 + 0x38) = **(uint **)(param_3 + 0x38) & 0xffff0000;
    **(uint **)(param_3 + 0x38) = **(uint **)(param_3 + 0x38) | 0x1000;
  }
  else {
    *puVar5 = *puVar5 & 0xfffffffe;
  }
  **(uint **)(param_3 + 0x3c) = **(uint **)(param_3 + 0x3c) & 0xf000f000;
  **(uint **)(param_3 + 0x5c) = **(uint **)(param_3 + 0x5c) & 0xf000f000;
  if (param_2 != 0) {
    **(uint **)(param_3 + 0x3c) = **(uint **)(param_3 + 0x3c) | 0x8000000;
  }
  return;
}


// ===== vdc5_config @ 2011a394 (1196 bytes)

/* writes VDC5 ch0 registers 0xFCFF7400+ */

void vdc5_config(int param_1,int param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(&DAT_20165ce0 + param_2 * 0xb8 + param_1 * 0x228);
  *(uint *)puVar6[0xc] = (uint)*param_3 << 0x10;
  *(uint *)puVar6[0xc] = *(uint *)puVar6[0xc] | (uint)param_3[1];
  *(uint *)puVar6[0xd] = (uint)param_3[2] << 0x10;
  *(uint *)puVar6[0xd] = *(uint *)puVar6[0xd] | (uint)param_3[3];
  *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] & 0xfff8fff2;
  *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] | (uint)(byte)param_3[8] << 0x10;
  *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] | (uint)*(byte *)((int)param_3 + 0x11) << 2;
  if ((char)param_3[9] != '\0') {
    *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] | 1;
  }
  *(undefined4 *)puVar6[0x1d] = *(undefined4 *)(param_3 + 0xc);
  *(uint *)puVar6[0x1e] = (uint)param_3[0xe] << 0x10;
  *(uint *)puVar6[0x1e] = *(uint *)(param_3 + 0x10) | *(uint *)puVar6[0x1e];
  if (*(int *)(param_3 + 0x10) != 0) {
    *(undefined4 *)puVar6[0x1f] = *(undefined4 *)(param_3 + 0x12);
  }
  *(uint *)puVar6[0x20] = *(uint *)puVar6[0x20] & 0xfffffcff;
  *(uint *)puVar6[0x20] = *(uint *)puVar6[0x20] | (uint)(byte)param_3[10] << 8;
  uVar4 = *(uint *)puVar6[0x21];
  if ((char)param_3[0xb] == '\0') {
    uVar4 = uVar4 & 0xffffffef;
  }
  else {
    uVar4 = uVar4 | 0x10;
  }
  *(uint *)puVar6[0x21] = uVar4;
  uVar4 = *(uint *)puVar6[0x21];
  if (*(char *)((int)param_3 + 0x11) == '\x01') {
    uVar4 = uVar4 | 1;
  }
  else {
    uVar4 = uVar4 & 0xfffffffe;
  }
  *(uint *)puVar6[0x21] = uVar4;
  if (param_2 == 2) {
    *(uint *)puVar6[0x11] = (uint)param_3[1] << 0x10;
    *(uint *)puVar6[0x11] = *(uint *)puVar6[0x11] | (uint)param_3[3];
    *(uint *)puVar6[0xb] = *(uint *)puVar6[0xb] & 0xffffffee;
    puVar3 = (uint *)puVar6[0x20];
    uVar4 = *puVar3 & 0xffffefff;
  }
  else {
    uVar4 = *(uint *)puVar6[5];
    if (*(int *)(param_3 + 0x10) == 0) {
      uVar4 = uVar4 & 0xfffffeff;
    }
    else {
      uVar4 = uVar4 | 0x100;
    }
    *(uint *)puVar6[5] = uVar4;
    uVar4 = *(uint *)puVar6[0xe];
    if ((char)param_3[4] == '\0') {
      uVar4 = uVar4 & 0xdfffffff;
    }
    else {
      uVar4 = uVar4 | 0x20000000;
    }
    *(uint *)puVar6[0xe] = uVar4;
    *(uint *)puVar6[0x11] = (uint)param_3[5] << 0x10;
    *(uint *)puVar6[0x11] = (uint)param_3[6] | *(uint *)puVar6[0x11];
    FUN_2011a290(param_3,*(undefined1 *)((int)param_3 + 0x13),puVar6);
    *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] & 0xffffff8f;
    *(uint *)puVar6[0x1c] = *(uint *)puVar6[0x1c] | (uint)*(byte *)((int)param_3 + 0xf) << 4;
    uVar4 = *(uint *)puVar6[0x20];
    if (*(char *)((int)param_3 + 0x13) == '\0') {
      uVar4 = uVar4 & 0xffffefff;
    }
    else {
      uVar4 = uVar4 | 0x1000;
    }
    *(uint *)puVar6[0x20] = uVar4;
    uVar4 = *(uint *)puVar6[0x20];
    if (*(char *)((int)param_3 + 0x15) == '\0') {
      uVar4 = uVar4 & 0xffffffef;
    }
    else {
      uVar4 = uVar4 | 0x10;
    }
    *(uint *)puVar6[0x20] = uVar4;
    puVar3 = (uint *)puVar6[0x1c];
    if (*(int *)(param_3 + 0x14) != 0) {
      *puVar3 = *puVar3 | 0x80;
      *(undefined4 *)puVar6[0x23] = *(undefined4 *)(param_3 + 0x14);
      *(uint *)puVar6[0x24] = (uint)param_3[0xe] << 0x10;
      *(uint *)puVar6[0x24] = *(uint *)puVar6[0x24] | *(uint *)(param_3 + 0x10);
      if (*(int *)(param_3 + 0x10) != 0) {
        *(undefined4 *)puVar6[0x25] = *(undefined4 *)(param_3 + 0x12);
      }
      goto LAB_2011a684;
    }
    uVar4 = *puVar3 & 0xffffff7f;
  }
  *puVar3 = uVar4;
LAB_2011a684:
  *(uint *)*puVar6 = *(uint *)*puVar6 | 0x1011;
  *(uint *)puVar6[0x1b] = *(uint *)puVar6[0x1b] | 0x10011;
  if (param_2 == 2) {
    return;
  }
  iVar5 = param_1;
  if (param_2 != 0) {
    if (param_1 == 0) {
      iVar5 = 1;
    }
    else {
      iVar5 = 0;
    }
  }
  iVar1 = FUN_2011d5cc(iVar5);
  iVar2 = FUN_2011d668(param_1,param_2);
  if (iVar1 == 0) {
    uVar4 = (uint)(iVar2 != 0);
  }
  else if (iVar2 == 0) {
    uVar4 = 2;
  }
  else {
    uVar4 = 3;
  }
  iVar1 = uVar4 * 0x12;
  *(uint *)(&DAT_20166204)[iVar5 * 0x18] = uVar4;
  *(undefined4 *)(&DAT_20166208)[iVar5 * 0x18] = 0x800000;
  *(uint *)(&DAT_20166208)[iVar5 * 0x18] =
       *(uint *)(&DAT_20166208)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b8e + iVar1);
  *(uint *)(&DAT_2016620c)[iVar5 * 0x18] = (uint)*(ushort *)(&UNK_20165b90 + iVar1) << 0x10;
  *(uint *)(&DAT_2016620c)[iVar5 * 0x18] =
       *(uint *)(&DAT_2016620c)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b92 + iVar1);
  *(undefined4 *)(&DAT_20166210)[iVar5 * 0x18] = 0x800000;
  *(uint *)(&DAT_20166210)[iVar5 * 0x18] =
       *(uint *)(&DAT_20166210)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b94 + iVar1);
  *(uint *)(&DAT_20166214)[iVar5 * 0x18] = (uint)*(ushort *)(&UNK_20165b96 + iVar1) << 0x10;
  *(uint *)(&DAT_20166214)[iVar5 * 0x18] =
       *(uint *)(&DAT_20166214)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b98 + iVar1);
  *(undefined4 *)(&DAT_20166218)[iVar5 * 0x18] = 0x800000;
  *(uint *)(&DAT_20166218)[iVar5 * 0x18] =
       *(uint *)(&DAT_20166218)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b9a + iVar1);
  *(uint *)(&PTR_DAT_2016621c)[iVar5 * 0x18] = (uint)*(ushort *)(&UNK_20165b9c + iVar1) << 0x10;
  *(uint *)(&PTR_DAT_2016621c)[iVar5 * 0x18] =
       *(uint *)(&PTR_DAT_2016621c)[iVar5 * 0x18] | (uint)*(ushort *)(&UNK_20165b9e + iVar1);
  *(uint *)(&DAT_20166200)[iVar5 * 0x18] = *(uint *)(&DAT_20166200)[iVar5 * 0x18] | 1;
  return;
}


// ===== FUN_2011a6c8 @ 2011a6c8 (312 bytes)

void FUN_2011a6c8(int param_1,int param_2,ushort *param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(&DAT_20165ce0 + param_2 * 0xb8 + param_1 * 0x228);
  *(uint *)puVar4[0xc] = (uint)*param_3 << 0x10;
  *(uint *)puVar4[0xc] = *(uint *)puVar4[0xc] | (uint)param_3[1];
  *(uint *)puVar4[0xd] = (uint)param_3[2] << 0x10;
  *(uint *)puVar4[0xd] = *(uint *)puVar4[0xd] | (uint)param_3[3];
  if (param_2 == 2) {
    *(uint *)puVar4[0x11] = (uint)param_3[1] << 0x10;
    puVar2 = (uint *)puVar4[0x11];
    uVar3 = *puVar2 | (uint)param_3[3];
  }
  else {
    uVar3 = *(uint *)puVar4[0xe];
    if ((char)param_3[4] == '\0') {
      uVar3 = uVar3 & 0xdfffffff;
    }
    else {
      uVar3 = uVar3 | 0x20000000;
    }
    *(uint *)puVar4[0xe] = uVar3;
    *(uint *)puVar4[0x11] = (uint)param_3[5] << 0x10;
    *(uint *)puVar4[0x11] = *(uint *)puVar4[0x11] | (uint)param_3[6];
    uVar1 = FUN_2011d64c();
    FUN_2011a290(param_3,uVar1,puVar4);
    *(uint *)puVar4[0x1c] = *(uint *)puVar4[0x1c] & 0xffffff8f;
    *(uint *)puVar4[0x1c] = *(uint *)puVar4[0x1c] | (uint)*(byte *)((int)param_3 + 0xf) << 4;
    puVar2 = (uint *)puVar4[0x1b];
    uVar3 = *puVar2 | 0x11;
  }
  *puVar2 = uVar3;
  *(uint *)*puVar4 = *(uint *)*puVar4 | 0x1011;
  return;
}


// ===== FUN_2011a800 @ 2011a800 (72 bytes)

void FUN_2011a800(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2;
  }
  iVar1 = iVar2 * 0x12;
  if (param_2 == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = 2;
  }
  puVar4 = &DAT_20166200 + param_1 * 0x18 + iVar3 * 8;
  *(int *)puVar4[1] = iVar2;
  *(undefined4 *)puVar4[2] = 0x800000;
  *(uint *)puVar4[2] = *(uint *)puVar4[2] | (uint)*(ushort *)(&UNK_20165b8e + iVar1);
  *(uint *)puVar4[3] = (uint)*(ushort *)(&UNK_20165b90 + iVar1) << 0x10;
  *(uint *)puVar4[3] = *(uint *)puVar4[3] | (uint)*(ushort *)(&UNK_20165b92 + iVar1);
  *(undefined4 *)puVar4[4] = 0x800000;
  *(uint *)puVar4[4] = *(uint *)puVar4[4] | (uint)*(ushort *)(&UNK_20165b94 + iVar1);
  *(uint *)puVar4[5] = (uint)*(ushort *)(&UNK_20165b96 + iVar1) << 0x10;
  *(uint *)puVar4[5] = *(uint *)puVar4[5] | (uint)*(ushort *)(&UNK_20165b98 + iVar1);
  *(undefined4 *)puVar4[6] = 0x800000;
  *(uint *)puVar4[6] = *(uint *)puVar4[6] | (uint)*(ushort *)(&UNK_20165b9a + iVar1);
  *(uint *)puVar4[7] = (uint)*(ushort *)(&UNK_20165b9c + iVar1) << 0x10;
  *(uint *)puVar4[7] = *(uint *)puVar4[7] | (uint)*(ushort *)(&UNK_20165b9e + iVar1);
  *(uint *)*puVar4 = *(uint *)*puVar4 | 1;
  return;
}


// ===== FUN_2011a848 @ 2011a848 (132 bytes)

void FUN_2011a848(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  
  iVar1 = param_1 * 0x228;
  if (param_2 == 0) {
    puVar4 = *(uint **)(&DAT_20165ce0 + param_1 * 0x228);
    puVar5 = *(uint **)(&DAT_201662c0 + param_1 * 0x210);
    puVar6 = *(undefined4 **)(&DAT_20165d48 + iVar1);
    puVar7 = *(uint **)(&DAT_2016630c + param_1 * 0x210);
  }
  else {
    puVar4 = *(uint **)(&DAT_20165d98 + iVar1);
    puVar5 = *(uint **)(&DAT_20166318 + param_1 * 0x210);
    puVar6 = *(undefined4 **)(&DAT_20165e00 + iVar1);
    puVar7 = (uint *)(&PTR_DAT_20166364)[param_1 * 0x84];
  }
  uVar2 = FUN_2011d61c(param_1,param_3);
  uVar3 = FUN_20119db8();
  *puVar6 = uVar2;
  *puVar4 = *puVar4 | 0x10;
  *puVar7 = uVar3 & 0xffffff;
  *puVar5 = *puVar5 | 0x10;
  return;
}


// ===== FUN_2011a8cc @ 2011a8cc (276 bytes)

undefined4 FUN_2011a8cc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = FUN_2011d5fc();
  if (param_2 == 1) {
    iVar1 = param_1 * 0x228;
    puVar3 = *(uint **)(&DAT_20166338 + param_1 * 0x210);
    if (param_3 == 1 && param_4 == 0) {
      *puVar3 = *puVar3 | 0x10000000;
      uVar2 = 1;
      **(uint **)(&DAT_20165cec + iVar1) = **(uint **)(&DAT_20165cec + iVar1) & 0xfffffeff;
    }
    else {
      *puVar3 = *puVar3 & 0xefffffff;
      uVar2 = 0;
      iVar4 = FUN_2011d5ec(param_1);
      puVar3 = *(uint **)(&DAT_20165cec + iVar1);
      if (iVar4 == 0) {
        *puVar3 = *puVar3 & 0xfffffeff;
        puVar3 = *(uint **)(&DAT_20165da4 + iVar1);
        uVar5 = *puVar3 | 0x100;
      }
      else {
        *puVar3 = *puVar3 | 0x100;
        puVar3 = *(uint **)(&DAT_20165da4 + iVar1);
        uVar5 = *puVar3 & 0xfffffeff;
      }
      *puVar3 = uVar5;
    }
    FUN_2011d57c(param_1,uVar2);
    **(uint **)(&DAT_20165ce0 + iVar1) = **(uint **)(&DAT_20165ce0 + iVar1) | 0x100;
    **(uint **)(&DAT_20165d98 + iVar1) = **(uint **)(&DAT_20165d98 + iVar1) | 0x100;
    **(uint **)(&DAT_20166318 + param_1 * 0x210) =
         **(uint **)(&DAT_20166318 + param_1 * 0x210) | 0x100;
  }
  return uVar2;
}


// ===== FUN_2011a9e0 @ 2011a9e0 (236 bytes)

void FUN_2011a9e0(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = FUN_2011a8cc();
  iVar3 = FUN_2011d84c(param_1,3);
  if ((iVar2 == 0) && ((iVar3 != 0 || (param_2 == 0)))) {
    iVar2 = param_1 * 0x210;
    puVar1 = &DAT_201662c0;
    iVar3 = FUN_2011d60c(param_1);
    puVar4 = *(uint **)(&DAT_20166440 + iVar2);
    if (iVar3 == 0) {
      *puVar4 = *puVar4 & 0xfffffffb;
      puVar1 = &DAT_20166318;
    }
    else {
      *puVar4 = *puVar4 | 4;
    }
    **(uint **)(&DAT_20166440 + iVar2) = **(uint **)(&DAT_20166440 + iVar2) & 0xfffffffc;
    **(uint **)(&DAT_20166440 + iVar2) = **(uint **)(&DAT_20166440 + iVar2) | 3;
    **(undefined4 **)(&DAT_20166444 + iVar2) = **(undefined4 **)(puVar1 + iVar2 + 0x24);
    **(undefined4 **)(&DAT_20166448 + iVar2) = **(undefined4 **)(puVar1 + iVar2 + 0x28);
    **(undefined4 **)(&DAT_2016644c + iVar2) = **(undefined4 **)(&DAT_20166444 + iVar2);
    **(undefined4 **)(&DAT_20166450 + iVar2) = **(undefined4 **)(&DAT_20166448 + iVar2);
    **(uint **)(&DAT_20166420 + iVar2) = **(uint **)(&DAT_20166420 + iVar2) | 0x110;
  }
  return;
}


// ===== FUN_2011aad8 @ 2011aad8 (32 bytes)

uint FUN_2011aad8(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_20156260((param_1 & 7) << 3,*(undefined4 *)(&DAT_20165c70 + param_2 * 4));
  return uVar1 & 0x3f;
}


// ===== FUN_2011aaf8 @ 2011aaf8 (480 bytes)

void FUN_2011aaf8(ushort *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6
                 ,int param_7)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = *(ushort *)(param_2 + 2) <= *param_1;
  if (bVar3) {
    **(uint **)(param_7 + 0x48) = **(uint **)(param_7 + 0x48) & 0xffffffef;
  }
  else {
    **(uint **)(param_7 + 0x2c) = **(uint **)(param_7 + 0x2c) & 0xffffffef;
    **(uint **)(param_7 + 0x48) = **(uint **)(param_7 + 0x48) | 0x10;
    **(undefined4 **)(param_7 + 0x40) = 0x1000;
  }
  if (param_1[1] < *(ushort *)(param_2 + 6)) {
    **(uint **)(param_7 + 0x48) = **(uint **)(param_7 + 0x48) | 1;
    **(uint **)(param_7 + 0x58) = **(uint **)(param_7 + 0x58) & 0xffff0000;
    **(uint **)(param_7 + 0x58) = **(uint **)(param_7 + 0x58) | 0x1000;
  }
  else {
    **(uint **)(param_7 + 0x48) = **(uint **)(param_7 + 0x48) & 0xfffffffe;
  }
  if (param_4 != 0) {
    if (!bVar3) {
      if (param_5 != 2) {
        if (param_5 == 3) {
          if (param_6 != 0) {
            return;
          }
        }
        else {
          if (param_5 == 4) {
            **(uint **)(param_7 + 0x3c) = **(uint **)(param_7 + 0x3c) & 0xf000f000;
            **(uint **)(param_7 + 0x5c) = **(uint **)(param_7 + 0x5c) & 0xf000f000;
            puVar1 = *(uint **)(param_7 + 0x5c);
            uVar2 = *puVar1 | 0x8000000;
            goto LAB_2011aca0;
          }
          if (param_6 != 1) {
            return;
          }
        }
        **(uint **)(param_7 + 0x3c) = **(uint **)(param_7 + 0x3c) & 0xf000f000;
        **(uint **)(param_7 + 0x5c) = **(uint **)(param_7 + 0x5c) & 0xf000f000;
        puVar1 = *(uint **)(param_7 + 0x3c);
        uVar2 = *puVar1 | 0x800;
        goto LAB_2011aca0;
      }
      **(uint **)(param_7 + 0x3c) = **(uint **)(param_7 + 0x3c) & 0xf000f000;
      **(uint **)(param_7 + 0x5c) = **(uint **)(param_7 + 0x5c) & 0xf000f000;
      **(uint **)(param_7 + 0x5c) = **(uint **)(param_7 + 0x5c) | 0x800;
    }
    return;
  }
  **(uint **)(param_7 + 0x3c) = **(uint **)(param_7 + 0x3c) & 0xf000f000;
  puVar1 = *(uint **)(param_7 + 0x5c);
  uVar2 = *puVar1 & 0xf000f000;
LAB_2011aca0:
  *puVar1 = uVar2;
  return;
}


// ===== FUN_2011acd8 @ 2011acd8 (500 bytes)

void FUN_2011acd8(int param_1,int param_2,ushort *param_3,ushort *param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (param_2 == 0) {
    iVar7 = 0;
  }
  else if (param_2 == 1) {
    iVar7 = 1;
  }
  else {
    iVar7 = 2;
  }
  puVar6 = (undefined4 *)(&DAT_20165ce0 + iVar7 * 0xb8 + param_1 * 0x228);
  if (param_5 == 1 && param_6 == 0) {
    *(uint *)puVar6[0x19] = *(uint *)puVar6[0x19] | 0x10;
    puVar4 = (uint *)*puVar6;
    uVar5 = *puVar4 | 0x2010;
  }
  else {
    if (param_2 == 5) {
      *(uint *)puVar6[0x12] = *(uint *)puVar6[0x12] & 0xffffffee;
      *(uint *)puVar6[0x19] = *(uint *)puVar6[0x19] | 0x10;
    }
    else {
      *(uint *)puVar6[0x19] = *(uint *)puVar6[0x19] & 0xffffffef;
      *(uint *)puVar6[0x13] = (uint)*param_4 << 0x10;
      *(uint *)puVar6[0x13] = *(uint *)puVar6[0x13] | (uint)param_4[1];
      *(uint *)puVar6[0x14] = (uint)param_4[2] << 0x10;
      *(uint *)puVar6[0x14] = *(uint *)puVar6[0x14] | (uint)param_4[3];
      *(uint *)puVar6[0x15] = (uint)*param_3 << 0x10;
      *(uint *)puVar6[0x15] = *(uint *)puVar6[0x15] | (uint)param_3[1];
      uVar1 = FUN_2011d634(param_1,iVar7);
      uVar2 = FUN_2011d71c(param_1,param_2);
      uVar8 = 0;
      if ((param_5 == 0 || param_5 == 3) && (iVar7 = FUN_2011d64c(param_1,iVar7), iVar7 != 0)) {
        uVar8 = 1;
      }
      uVar3 = FUN_2011d6a0(param_1,param_2);
      FUN_2011aaf8(param_3,param_4,uVar2,uVar8,uVar1,uVar3,puVar6);
    }
    *(uint *)*puVar6 = *(uint *)*puVar6 | 0x2111;
    if (param_5 == 1) {
      return;
    }
    **(undefined4 **)((int)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210) + 0x14) =
         *(undefined4 *)puVar6[0x1f];
    puVar4 = *(uint **)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
    uVar5 = *puVar4 | 1;
  }
  *puVar4 = uVar5;
  return;
}


// ===== FUN_2011aecc @ 2011aecc (104 bytes)

undefined4 FUN_2011aecc(uint param_1,int param_2,ushort *param_3,int param_4)

{
  if (param_2 == 1) {
    if (1 < param_1) {
      return 0;
    }
    if ((*(ushort *)(param_4 + 2) <= *param_3) && (*(ushort *)(param_4 + 6) <= param_3[1])) {
      return 0;
    }
  }
  else if ((*(ushort *)(param_4 + 2) <= *param_3) && (*(ushort *)(param_4 + 6) <= param_3[1])) {
    return 0;
  }
  return 1;
}


// ===== FUN_2011af34 @ 2011af34 (1052 bytes)

void FUN_2011af34(int param_1,uint param_2,char *param_3)

{
  undefined *puVar1;
  ushort *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 *puVar7;
  
  puVar2 = (ushort *)FUN_2011d75c();
  uVar3 = FUN_2011aecc(param_2,param_3[1],puVar2,param_3 + 0x14);
  if (param_2 < 2 || param_2 == 5) {
    FUN_2011acd8(param_1,param_2,puVar2,param_3 + 0x14,param_3[1],uVar3);
  }
  puVar7 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  *(uint *)puVar7[2] = *(uint *)puVar7[2] & 0xfffefcfe;
  if (*param_3 != '\0') {
    *(uint *)puVar7[2] = *(uint *)puVar7[2] | 0x10000;
  }
  *(uint *)puVar7[2] = *(uint *)puVar7[2] | (uint)(byte)param_3[1] << 8;
  if (param_3[3] != '\0') {
    *(uint *)puVar7[2] = *(uint *)puVar7[2] | 1;
  }
  if (param_3[1] == '\x02') {
    uVar4 = *(uint *)puVar7[2];
    if (param_3[2] == '\0') {
      uVar4 = uVar4 & 0xffffffef;
    }
    else {
      uVar4 = uVar4 | 0x10;
    }
    *(uint *)puVar7[2] = uVar4;
  }
  *(uint *)puVar7[3] = *(uint *)(param_3 + 4) & 0xfffffff8;
  *(uint *)puVar7[4] = *(uint *)puVar7[4] & 0x8000fc00;
  *(uint *)puVar7[4] = *(uint *)puVar7[4] | (uint)*(ushort *)(param_3 + 8) << 0x10;
  *(undefined4 *)puVar7[6] = 0x7ff;
  *(uint *)puVar7[6] = *(uint *)puVar7[6] | (uint)*puVar2 * 0x10000 - 0x10000;
  *(uint *)puVar7[7] = *(uint *)puVar7[7] & 0x800e3c0;
  *(uint *)puVar7[7] = *(uint *)puVar7[7] | (uint)(byte)param_3[0x11] << 0x1c;
  *(uint *)puVar7[7] = (uint)puVar2[1] * 0x10000 - 0x10000 | *(uint *)puVar7[7];
  *(uint *)puVar7[7] = *(uint *)puVar7[7] | (uint)(byte)param_3[0x13] << 10;
  if ((byte)param_3[1] < 2) {
    uVar4 = FUN_2011aad8(*(undefined4 *)(param_3 + 4),param_3[0x11]);
    *(uint *)puVar7[7] = uVar4 | *(uint *)puVar7[7];
  }
  *(uint *)puVar7[8] = *(uint *)puVar7[8] & 0xfffffffc;
  uVar4 = *(uint *)puVar7[8];
  if (param_2 != 0 && param_2 != 5) {
    uVar4 = uVar4 | 1;
  }
  *(uint *)puVar7[8] = uVar4;
  *(uint *)puVar7[9] = (uint)*(ushort *)(param_3 + 0x14) << 0x10;
  *(uint *)puVar7[9] = *(uint *)puVar7[9] | (uint)*(ushort *)(param_3 + 0x16);
  *(uint *)puVar7[10] = (uint)*(ushort *)(param_3 + 0x18) << 0x10;
  *(uint *)puVar7[10] = *(uint *)puVar7[10] | (uint)*(ushort *)(param_3 + 0x1a);
  if ((param_2 == 1 || param_2 == 2) || param_2 == 3) {
    *(uint *)puVar7[8] = *(uint *)puVar7[8] & 0xffff2fff;
    *(undefined4 *)puVar7[0xb] = *(undefined4 *)puVar7[9];
    *(undefined4 *)puVar7[0xc] = *(undefined4 *)puVar7[10];
    *(uint *)puVar7[0xd] = *(uint *)puVar7[0xd] & 0xfe00ff00;
    *(uint *)puVar7[0xe] = *(uint *)puVar7[0xe] | 0xff0000;
  }
  *(uint *)puVar7[0xe] = *(uint *)puVar7[0xe] & 0xfffffffe;
  if (param_2 == 0 || param_2 == 5) {
    *(uint *)puVar7[0x11] = *(uint *)puVar7[0x11] | 0xff000000;
    *(uint *)puVar7[0x12] = *(uint *)puVar7[0x12] | 0xff000000;
    if (param_2 != 0) goto LAB_2011b23c;
  }
  else {
LAB_2011b23c:
    if (param_2 != 1) goto LAB_2011b244;
  }
  *(uint *)puVar7[7] = *(uint *)puVar7[7] & 0xffff1fff;
  puVar6 = (uint *)puVar7[7];
  uVar4 = *puVar6;
  if (param_3[0x11] == '\b') {
    *puVar6 = uVar4 | (uint)(byte)param_3[0x12] << 0xd;
    puVar6 = (uint *)puVar7[7];
    uVar4 = *puVar6 | 0x100;
  }
  *puVar6 = uVar4;
  FUN_2011a9e0(param_1,param_2,param_3[1],uVar3);
  iVar5 = FUN_2011d6fc(param_1,param_2);
  FUN_2011a848(param_1,param_2,iVar5);
  FUN_2011a800(param_1,param_2,iVar5);
  puVar1 = &DAT_20166130;
  if (param_2 != 0) {
    puVar1 = &DAT_20166164;
  }
  puVar6 = *(uint **)((int)(puVar1 + param_1 * 0x68) + 8);
  uVar4 = *puVar6;
  if (iVar5 == 0) {
    uVar4 = uVar4 & 0xffffffef;
  }
  else {
    uVar4 = uVar4 | 0x10;
  }
  *puVar6 = uVar4;
  puVar6 = *(uint **)(puVar1 + param_1 * 0x68);
  *puVar6 = *puVar6 | 1;
LAB_2011b244:
  iVar5 = FUN_2011d84c(param_1,4);
  if (iVar5 == 0 && param_2 == 0) {
    FUN_2011a800(param_1,1,0);
  }
  *(uint *)*puVar7 = *(uint *)*puVar7 | 0x111;
  return;
}


// ===== FUN_2011b498 @ 2011b498 (868 bytes)

void FUN_2011b498(int param_1,uint param_2,uint *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 unaff_r4;
  undefined4 *puVar11;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_lr;
  
  uVar6 = FUN_2011d6bc();
  uVar7 = FUN_2011d73c(param_1,param_2);
  uVar8 = FUN_2011d75c(param_1,param_2);
  uVar9 = FUN_2011aecc(param_2,uVar6,uVar8,uVar7);
  if (param_2 < 2 || param_2 == 5) {
    FUN_2011acd8(param_1,param_2,uVar8,uVar7,uVar6,uVar9);
  }
  puVar11 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  if ((*param_3 != 0) && (*(uint *)puVar11[3] = *param_3 & 0xfffffff8, uVar6 < 2)) {
    uVar7 = FUN_2011d6dc(param_1,param_2);
    *(uint *)puVar11[7] = *(uint *)puVar11[7] & 0xffffffc0;
    uVar10 = FUN_2011aad8(*param_3,uVar7);
    *(uint *)puVar11[7] = uVar10 | *(uint *)puVar11[7];
  }
  if (param_3[1] != 0) {
    *(uint *)puVar11[6] = *(uint *)puVar11[6] & 0xf800ffff;
    *(uint *)puVar11[6] = *(uint *)puVar11[6] | (uint)*(ushort *)param_3[1] * 0x10000 - 0x10000;
    *(uint *)puVar11[7] = *(uint *)puVar11[7] & 0xf800ffff;
    *(uint *)puVar11[7] =
         (uint)*(ushort *)(param_3[1] + 2) * 0x10000 - 0x10000 | *(uint *)puVar11[7];
  }
  if (((char *)param_3[3] != (char *)0x0) && (*(char *)param_3[3] != -1)) {
    *(uint *)puVar11[8] = *(uint *)puVar11[8] & 0xfffffffc;
    *(uint *)puVar11[8] = *(uint *)puVar11[8] | (int)*(char *)param_3[3];
  }
  if ((ushort *)param_3[2] != (ushort *)0x0) {
    *(uint *)puVar11[9] = (uint)*(ushort *)param_3[2] << 0x10;
    *(uint *)puVar11[9] = *(uint *)puVar11[9] | (uint)*(ushort *)(param_3[2] + 2);
    *(uint *)puVar11[10] = (uint)*(ushort *)(param_3[2] + 4) << 0x10;
    *(uint *)puVar11[10] = *(uint *)puVar11[10] | (uint)*(ushort *)(param_3[2] + 6);
  }
  *(uint *)*puVar11 = *(uint *)*puVar11 | 0x11;
  if (param_2 < 2) {
    iVar2 = FUN_2011d5fc();
    iVar3 = FUN_2011a8cc(param_1,param_2,uVar6,uVar9,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                         unaff_lr);
    iVar4 = FUN_2011d84c(param_1,3);
    if (iVar4 != 0) {
      iVar4 = param_1 * 0x210;
      puVar1 = &DAT_201662c0;
      if (iVar3 == 0) {
        iVar2 = FUN_2011d60c(param_1);
        puVar5 = *(uint **)(&DAT_20166440 + iVar4);
        if (iVar2 == 0) {
          *puVar5 = *puVar5 & 0xfffffffb;
          puVar1 = &DAT_20166318;
        }
        else {
          *puVar5 = *puVar5 | 4;
        }
        **(uint **)(&DAT_20166440 + iVar4) = **(uint **)(&DAT_20166440 + iVar4) & 0xfffffffc;
        **(uint **)(&DAT_20166440 + iVar4) = **(uint **)(&DAT_20166440 + iVar4) | 3;
        **(undefined4 **)(&DAT_20166444 + iVar4) = **(undefined4 **)(puVar1 + iVar4 + 0x24);
        **(undefined4 **)(&DAT_20166448 + iVar4) = **(undefined4 **)(puVar1 + iVar4 + 0x28);
      }
      else if (iVar2 == 0) {
        **(uint **)(&DAT_20166440 + iVar4) = **(uint **)(&DAT_20166440 + iVar4) | 4;
        **(uint **)(&DAT_20166440 + iVar4) = **(uint **)(&DAT_20166440 + iVar4) & 0xfffffffc;
        **(uint **)(&DAT_20166440 + iVar4) = **(uint **)(&DAT_20166440 + iVar4) | 1;
      }
      **(uint **)(&DAT_20166420 + iVar4) = **(uint **)(&DAT_20166420 + iVar4) | 0x110;
    }
    return;
  }
  return;
}


// ===== FUN_2011b6d8 @ 2011b6d8 (440 bytes)

void FUN_2011b6d8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  switch(param_2) {
  case 0:
    puVar2 = (uint *)(&PTR_DAT_20165d4c)[param_1 * 0x8a];
    uVar3 = *puVar2 | 0x100011;
    break;
  case 1:
    puVar2 = (uint *)(&PTR_DAT_20165e04)[param_1 * 0x8a];
    uVar3 = *puVar2 | 0x100011;
    break;
  case 2:
    *(uint *)(&PTR_DAT_20165ebc)[param_1 * 0x8a] =
         *(uint *)(&PTR_DAT_20165ebc)[param_1 * 0x8a] | 0x11;
    return;
  case 3:
    **(uint **)(&DAT_201662c0 + param_1 * 0x210) =
         **(uint **)(&DAT_201662c0 + param_1 * 0x210) | 0x11;
    return;
  case 4:
    **(uint **)(&DAT_20166318 + param_1 * 0x210) =
         **(uint **)(&DAT_20166318 + param_1 * 0x210) | 0x11;
    return;
  case 5:
    **(uint **)(&DAT_20166370 + param_1 * 0x210) =
         **(uint **)(&DAT_20166370 + param_1 * 0x210) | 0x11;
    return;
  case 6:
    **(uint **)(&DAT_201663c8 + param_1 * 0x210) =
         **(uint **)(&DAT_201663c8 + param_1 * 0x210) | 0x11;
    return;
  default:
    return;
  case 8:
    puVar2 = (uint *)(&PTR_DAT_20166478)[param_1 * 0x84];
    uVar3 = *puVar2 | 0x11;
    break;
  case 0xffffffff:
    *(uint *)(&PTR_DAT_20165d4c)[param_1 * 0x8a] =
         *(uint *)(&PTR_DAT_20165d4c)[param_1 * 0x8a] | 0x100011;
    *(uint *)(&PTR_DAT_20165e04)[param_1 * 0x8a] =
         *(uint *)(&PTR_DAT_20165e04)[param_1 * 0x8a] | 0x100011;
    *(uint *)(&PTR_DAT_20165ebc)[param_1 * 0x8a] =
         *(uint *)(&PTR_DAT_20165ebc)[param_1 * 0x8a] | 0x11;
    **(uint **)(&DAT_201662c0 + param_1 * 0x210) =
         **(uint **)(&DAT_201662c0 + param_1 * 0x210) | 0x11;
    iVar1 = param_1 * 0x210;
    **(uint **)(&DAT_20166318 + iVar1) = **(uint **)(&DAT_20166318 + iVar1) | 0x11;
    **(uint **)(&DAT_20166370 + iVar1) = **(uint **)(&DAT_20166370 + iVar1) | 0x11;
    **(uint **)(&DAT_201663c8 + iVar1) = **(uint **)(&DAT_201663c8 + iVar1) | 0x11;
    puVar2 = (uint *)(&PTR_DAT_20166478)[param_1 * 0x84];
    uVar3 = *puVar2 | 0x11;
  }
  *puVar2 = uVar3;
  return;
}


// ===== FUN_2011b8b8 @ 2011b8b8 (208 bytes)

void FUN_2011b8b8(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*param_3 != 0) {
    FUN_20119cd0();
  }
  iVar1 = FUN_2011d958(param_1);
  if (param_2 == -1) {
    uVar3 = 0;
    do {
      iVar2 = FUN_2011d8e8(param_1,(int)(char)uVar3);
      if (iVar2 != 0) {
        (*(code *)(&PTR_FUN_20165bd8)[uVar3])(param_1,1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 9);
  }
  else {
    (*(code *)(&PTR_FUN_20165bd8)[param_2])(param_1,1);
  }
  FUN_2011b6d8(param_1,param_2);
  iVar2 = FUN_2011d958(param_1);
  if ((iVar1 == 0) && (iVar2 != 0)) {
    **(uint **)(&DAT_20165e5c + param_1 * 0x228) =
         **(uint **)(&DAT_20165e5c + param_1 * 0x228) | 0x10000;
    **(uint **)(&DAT_20165e50 + param_1 * 0x228) =
         **(uint **)(&DAT_20165e50 + param_1 * 0x228) | 0x100;
  }
  return;
}


// ===== FUN_2011b988 @ 2011b988 (192 bytes)

void FUN_2011b988(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_2011d958();
  if (param_2 == -1) {
    uVar3 = 0;
    do {
      iVar2 = FUN_2011d920(param_1,(int)(char)uVar3);
      if (iVar2 != 0) {
        (*(code *)(&PTR_FUN_20165bd8)[uVar3])(param_1,0);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 9);
  }
  else {
    (*(code *)(&PTR_FUN_20165bd8)[param_2])(param_1,0);
  }
  FUN_2011b6d8(param_1,param_2);
  iVar2 = FUN_2011d958(param_1);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    **(uint **)(&DAT_20165e5c + param_1 * 0x228) =
         **(uint **)(&DAT_20165e5c + param_1 * 0x228) & 0xfffeffff;
    **(uint **)(&DAT_20165e50 + param_1 * 0x228) =
         **(uint **)(&DAT_20165e50 + param_1 * 0x228) | 0x100;
  }
  return;
}


// ===== FUN_2011ba48 @ 2011ba48 (316 bytes)

void FUN_2011ba48(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_2011d8e8(param_1,4);
  if ((param_2 == 4) || ((param_2 == -1 && (iVar1 != 0)))) {
    FUN_201198dc(param_1);
    iVar1 = param_1 * 0x228;
    **(uint **)(&DAT_20165cec + iVar1) = **(uint **)(&DAT_20165cec + iVar1) & 0xfffffeff;
    **(uint **)(&DAT_20165ce0 + iVar1) = **(uint **)(&DAT_20165ce0 + iVar1) | 0x100;
    **(uint **)(&DAT_20165da4 + iVar1) = **(uint **)(&DAT_20165da4 + iVar1) | 0x100;
    **(uint **)(&DAT_20165d98 + iVar1) = **(uint **)(&DAT_20165d98 + iVar1) | 0x100;
    FUN_2011a800(param_1,1,0);
  }
  iVar1 = FUN_2011d8e8(param_1,3);
  if ((param_2 == 3) || ((param_2 == -1 && (iVar1 != 0)))) {
    param_1 = param_1 * 0x210;
    **(uint **)(&DAT_20166440 + param_1) = **(uint **)(&DAT_20166440 + param_1) & 0xffffefff;
    **(uint **)(&DAT_20166440 + param_1) = **(uint **)(&DAT_20166440 + param_1) | 4;
    **(uint **)(&DAT_20166440 + param_1) = **(uint **)(&DAT_20166440 + param_1) & 0xfffffffc;
    **(uint **)(&DAT_20166440 + param_1) = **(uint **)(&DAT_20166440 + param_1) | 1;
    **(uint **)(&DAT_20166454 + param_1) = **(uint **)(&DAT_20166454 + param_1) & 0xfe00ff00;
    **(uint **)(&DAT_20166458 + param_1) = **(uint **)(&DAT_20166458 + param_1) | 0xff0000;
    **(uint **)(&DAT_20166420 + param_1) = **(uint **)(&DAT_20166420 + param_1) | 0x110;
  }
  return;
}


// ===== FUN_2011bb84 @ 2011bb84 (264 bytes)

void FUN_2011bb84(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1 * 0x20;
  if (param_3 != (byte *)0x0) {
    **(uint **)(&DAT_20165cb8 + iVar1) = **(uint **)(&DAT_20165cb8 + iVar1) & 0xffff80cc;
    **(uint **)(&DAT_20165cb8 + iVar1) =
         **(uint **)(&DAT_20165cb8 + iVar1) | *(int *)(param_3 + 4) << 8;
    **(uint **)(&DAT_20165cb8 + iVar1) = **(uint **)(&DAT_20165cb8 + iVar1) | (uint)*param_3 << 4;
    **(uint **)(&DAT_20165cb8 + iVar1) = **(uint **)(&DAT_20165cb8 + iVar1) | (uint)param_3[8];
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] = (uint)param_3[0x10] << 0x18;
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] =
         *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] | (uint)param_3[0xc] << 0x14;
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] =
         *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] | (uint)param_3[0x14] << 0x10;
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] =
         *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] | *(int *)(param_3 + 0x1c) << 8;
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] =
         *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] | (uint)param_3[0x18] << 4;
    *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8] =
         (uint)param_3[0x20] | *(uint *)(&PTR_DAT_20165cbc)[param_1 * 8];
  }
  uVar2 = **(uint **)(&DAT_20165cb8 + iVar1);
  if (param_2 == 0) {
    uVar2 = uVar2 & 0xfffeffff;
  }
  else {
    uVar2 = uVar2 | 0x10000;
  }
  **(uint **)(&DAT_20165cb8 + iVar1) = uVar2;
  **(uint **)(&DAT_20165cb4 + iVar1) = **(uint **)(&DAT_20165cb4 + iVar1) | 1;
  return;
}


// ===== FUN_2011bc8c @ 2011bc8c (36 bytes)

void FUN_2011bc8c(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_20166200 + param_1 * 0x18 + (uint)*param_2 * 8;
  *(uint *)puVar1[1] = (uint)param_2[1];
  *(uint *)puVar1[2] = (uint)*(ushort *)(param_2 + 2) << 0x10;
  *(uint *)puVar1[2] = *(uint *)puVar1[2] | (uint)*(ushort *)(param_2 + 8);
  *(uint *)puVar1[3] = (uint)*(ushort *)(param_2 + 10) << 0x10;
  *(uint *)puVar1[3] = *(uint *)puVar1[3] | (uint)*(ushort *)(param_2 + 0xc);
  *(uint *)puVar1[4] = (uint)*(ushort *)(param_2 + 4) << 0x10;
  *(uint *)puVar1[4] = *(uint *)puVar1[4] | (uint)*(ushort *)(param_2 + 0xe);
  *(uint *)puVar1[5] = (uint)*(ushort *)(param_2 + 0x10) << 0x10;
  *(uint *)puVar1[5] = *(uint *)puVar1[5] | (uint)*(ushort *)(param_2 + 0x12);
  *(uint *)puVar1[6] = (uint)*(ushort *)(param_2 + 6) << 0x10;
  *(uint *)puVar1[6] = *(uint *)puVar1[6] | (uint)*(ushort *)(param_2 + 0x14);
  *(uint *)puVar1[7] = (uint)*(ushort *)(param_2 + 0x16) << 0x10;
  *(uint *)puVar1[7] = *(uint *)puVar1[7] | (uint)*(ushort *)(param_2 + 0x18);
  *(uint *)*puVar1 = *(uint *)*puVar1 | 1;
  return;
}


// ===== FUN_2011bcb0 @ 2011bcb0 (220 bytes)

void FUN_2011bcb0(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 != (char *)0x0) {
    if (*param_2 == '\0') {
      **(undefined4 **)(param_3 + 0x2c) = 0;
    }
    else {
      **(undefined4 **)(param_3 + 0x2c) = 0x1000000;
    }
    **(uint **)(param_3 + 0x2c) = **(uint **)(param_3 + 0x2c) | (uint)(byte)param_2[2] << 0x10;
    **(uint **)(param_3 + 0x2c) = **(uint **)(param_3 + 0x2c) | (uint)(byte)param_2[3] << 8;
    **(uint **)(param_3 + 0x2c) = (uint)(byte)param_2[4] | **(uint **)(param_3 + 0x2c);
    if (param_2[1] == '\0') {
      **(undefined4 **)(param_3 + 0x30) = 0;
    }
    else {
      **(undefined4 **)(param_3 + 0x30) = 0x1000000;
    }
    **(uint **)(param_3 + 0x30) = **(uint **)(param_3 + 0x30) | (uint)(byte)param_2[5] << 0x10;
    **(uint **)(param_3 + 0x30) = **(uint **)(param_3 + 0x30) | (uint)(byte)param_2[6] << 8;
    **(uint **)(param_3 + 0x30) = (uint)(byte)param_2[7] | **(uint **)(param_3 + 0x30);
  }
  uVar1 = **(uint **)(param_3 + 0x2c);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0x7fffffff;
  }
  else {
    uVar1 = uVar1 | 0x80000000;
  }
  **(uint **)(param_3 + 0x2c) = uVar1;
  return;
}


// ===== FUN_2011bd8c @ 2011bd8c (372 bytes)

void FUN_2011bd8c(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 != (char *)0x0) {
    **(uint **)(param_3 + 0x14) = **(uint **)(param_3 + 0x14) & 0xffffffc0;
    **(uint **)(param_3 + 0x14) = **(uint **)(param_3 + 0x14) | (uint)(byte)param_2[5];
    **(int **)(param_3 + 0x18) = (uint)(byte)param_2[1] << 0x18;
    **(uint **)(param_3 + 0x18) = **(uint **)(param_3 + 0x18) | (uint)(byte)param_2[2] << 0x10;
    **(uint **)(param_3 + 0x18) = **(uint **)(param_3 + 0x18) | (uint)(byte)param_2[3] << 8;
    **(uint **)(param_3 + 0x18) = (uint)(byte)param_2[4] | **(uint **)(param_3 + 0x18);
    if (*param_2 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x10000;
    }
    **(undefined4 **)(param_3 + 0x1c) = uVar2;
    **(uint **)(param_3 + 0x1c) = **(uint **)(param_3 + 0x1c) | (uint)(byte)param_2[10];
    **(int **)(param_3 + 0x20) = (uint)(byte)param_2[6] << 0x18;
    **(uint **)(param_3 + 0x20) = **(uint **)(param_3 + 0x20) | (uint)(byte)param_2[7] << 0x10;
    **(uint **)(param_3 + 0x20) = **(uint **)(param_3 + 0x20) | (uint)(byte)param_2[8] << 8;
    **(uint **)(param_3 + 0x20) = (uint)(byte)param_2[9] | **(uint **)(param_3 + 0x20);
    **(uint **)(param_3 + 0x24) = (uint)(byte)param_2[0xf];
    **(int **)(param_3 + 0x28) = (uint)(byte)param_2[0xb] << 0x18;
    **(uint **)(param_3 + 0x28) = **(uint **)(param_3 + 0x28) | (uint)(byte)param_2[0xc] << 0x10;
    **(uint **)(param_3 + 0x28) = **(uint **)(param_3 + 0x28) | (uint)(byte)param_2[0xd] << 8;
    **(uint **)(param_3 + 0x28) = (uint)(byte)param_2[0xe] | **(uint **)(param_3 + 0x28);
  }
  uVar1 = **(uint **)(param_3 + 0x14);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  **(uint **)(param_3 + 0x14) = uVar1;
  return;
}


// ===== FUN_2011bf00 @ 2011bf00 (180 bytes)

void FUN_2011bf00(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,ushort *param_7)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&DAT_20166130 + param_2 * 0x34 + param_1 * 0x68);
  FUN_2011bd8c(param_3,param_4,puVar1);
  FUN_2011bcb0(param_5,param_6,puVar1);
  if (param_7 != (ushort *)0x0) {
    *(uint *)puVar1[3] = (uint)*param_7 << 0x10;
    *(uint *)puVar1[3] = *(uint *)puVar1[3] | (uint)param_7[1];
    *(uint *)puVar1[4] = (uint)param_7[2] << 0x10;
    *(uint *)puVar1[4] = *(uint *)puVar1[4] | (uint)param_7[3];
  }
  *(uint *)*puVar1 = *(uint *)*puVar1 | 1;
  return;
}


// ===== FUN_2011bfc4 @ 2011bfc4 (164 bytes)

void FUN_2011bfc4(int param_1,int param_2,int param_3,ushort *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(&DAT_20166130 + param_2 * 0x34 + param_1 * 0x68);
  if (param_4 != (ushort *)0x0) {
    *(uint *)puVar1[1] = (uint)*param_4 << 0x14;
    *(uint *)puVar1[1] = *(uint *)puVar1[1] | (uint)param_4[1] << 0x10;
    *(uint *)puVar1[1] = *(uint *)puVar1[1] | (uint)param_4[2] << 8;
    *(uint *)puVar1[1] = (uint)param_4[3] | *(uint *)puVar1[1];
  }
  uVar2 = *(uint *)puVar1[1];
  if (param_3 == 0) {
    uVar2 = uVar2 & 0xfeffffff;
  }
  else {
    uVar2 = uVar2 | 0x1000000;
  }
  *(uint *)puVar1[1] = uVar2;
  *(uint *)*puVar1 = *(uint *)*puVar1 | 1;
  return;
}


// ===== FUN_2011c068 @ 2011c068 (176 bytes)

void FUN_2011c068(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  if (*param_3 != 0) {
    *(uint *)puVar1[0x11] = *(uint *)puVar1[0x11] & 0xffffff;
    *(uint *)puVar1[0x11] = *(uint *)puVar1[0x11] | (uint)*(byte *)*param_3 << 0x18;
    *(uint *)puVar1[0x12] = *(uint *)puVar1[0x12] & 0xffffff;
    *(uint *)puVar1[0x12] = *(uint *)puVar1[0x12] | (uint)*(byte *)(*param_3 + 1) << 0x18;
  }
  if ((char *)param_3[1] != (char *)0x0) {
    uVar2 = *(uint *)puVar1[8];
    if (*(char *)param_3[1] == '\0') {
      uVar2 = uVar2 & 0xffffbfff;
    }
    else {
      uVar2 = uVar2 | 0x4000;
    }
    *(uint *)puVar1[8] = uVar2;
  }
  *(uint *)*puVar1 = *(uint *)*puVar1 | 0x10;
  return;
}


// ===== FUN_2011c118 @ 2011c118 (92 bytes)

void FUN_2011c118(ushort *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != (ushort *)0x0) {
    uVar1 = (uint)*param_1 + (**(uint **)(param_2 + 0x24) >> 0x10);
    uVar2 = (uint)param_1[2] + (**(uint **)(param_2 + 0x28) >> 0x10);
    if (uVar1 >> 0xb != 0) {
      uVar1 = 0x7ff;
    }
    if (uVar2 >> 0xb != 0) {
      uVar2 = 0x7ff;
    }
    **(uint **)(param_2 + 0x2c) = (uint)param_1[1] | uVar1 << 0x10;
    **(uint **)(param_2 + 0x30) = (uint)param_1[3] | uVar2 << 0x10;
  }
  return;
}


// ===== FUN_2011c174 @ 2011c174 (184 bytes)

void FUN_2011c174(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = FUN_2011d60c();
  if (param_2 != iVar2) {
    FUN_2011d58c(param_1,param_2);
    iVar2 = FUN_2011d5fc(param_1);
    iVar3 = FUN_2011d84c(param_1,3);
    if ((iVar2 == 0) && (iVar3 != 0)) {
      param_1 = param_1 * 0x210;
      puVar1 = &DAT_201662c0;
      puVar4 = *(uint **)(&DAT_20166440 + param_1);
      if (param_2 == 0) {
        *puVar4 = *puVar4 & 0xfffffffb;
        puVar1 = &DAT_20166318;
      }
      else {
        *puVar4 = *puVar4 | 4;
      }
      **(undefined4 **)(&DAT_20166444 + param_1) = **(undefined4 **)(puVar1 + param_1 + 0x24);
      **(undefined4 **)(&DAT_20166448 + param_1) = **(undefined4 **)(puVar1 + param_1 + 0x28);
      **(uint **)(&DAT_20166420 + param_1) = **(uint **)(&DAT_20166420 + param_1) | 0x110;
    }
  }
  return;
}


// ===== FUN_2011c22c @ 2011c22c (308 bytes)

void FUN_2011c22c(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  uVar3 = **(uint **)(&DAT_201662e0 + param_1 * 0x210 + param_2 * 0x58);
  if (param_3 == 0) {
    uVar3 = uVar3 & 0xffffefff;
  }
  else {
    uVar3 = uVar3 | 0x1000;
  }
  **(uint **)(&DAT_201662e0 + param_1 * 0x210 + param_2 * 0x58) = uVar3;
  if (param_4 != (undefined4 *)0x0) {
    if ((undefined1 *)param_4[2] != (undefined1 *)0x0) {
      FUN_2011c174(param_1,*(undefined1 *)param_4[2]);
    }
    FUN_2011c118(*param_4,puVar4);
    psVar1 = (short *)param_4[1];
    if (psVar1 != (short *)0x0) {
      if (param_2 != 4) {
        uVar3 = *(uint *)puVar4[8];
        if ((char)psVar1[2] == '\0') {
          uVar3 = uVar3 & 0xffff7fff;
        }
        else {
          uVar3 = uVar3 | 0x8000;
        }
        *(uint *)puVar4[8] = uVar3;
      }
      iVar2 = (int)*psVar1;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
        *(undefined4 *)puVar4[0xd] = 0x1000000;
      }
      else {
        *(undefined4 *)puVar4[0xd] = 0;
      }
      *(uint *)puVar4[0xd] = *(uint *)puVar4[0xd] | iVar2 << 0x10;
      *(uint *)puVar4[0xd] = *(uint *)puVar4[0xd] | (uint)*(byte *)(psVar1 + 1);
      *(uint *)puVar4[0xe] = *(uint *)puVar4[0xe] & 0xff00ffff;
      *(uint *)puVar4[0xe] = *(uint *)puVar4[0xe] | (uint)*(byte *)((int)psVar1 + 3) << 0x10;
    }
  }
  *(uint *)*puVar4 = *(uint *)*puVar4 | 0x10;
  return;
}


// ===== FUN_2011c360 @ 2011c360 (28 bytes)

uint FUN_2011c360(ushort param_1)

{
  return ((uint)((short)(param_1 & 0x1f) * 0x20e) >> 5) + 1 >> 1;
}


// ===== FUN_2011c37c @ 2011c37c (12 bytes)

int FUN_2011c37c(uint param_1)

{
  return (param_1 & 0xf) * 0x11;
}


// ===== FUN_2011c388 @ 2011c388 (28 bytes)

uint FUN_2011c388(ushort param_1)

{
  return ((uint)((short)(param_1 & 0x3f) * 0x206) >> 6) + 1 >> 1;
}


// ===== FUN_2011c3a4 @ 2011c3a4 (256 bytes)

uint FUN_2011c3a4(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  switch(param_1) {
  case 0:
    uVar3 = FUN_2011c360((param_2 & 0xffff) >> 0xb);
    iVar1 = FUN_2011c388((param_2 & 0x7ff) >> 5);
    iVar2 = FUN_2011c360(param_2 & 0x1f);
    return iVar1 << 0x10 | iVar2 << 8 | uVar3;
  case 1:
    uVar3 = FUN_20119db8(param_2);
    return uVar3;
  case 2:
    uVar3 = FUN_2011c360((param_2 & 0x7fff) >> 10);
    iVar1 = FUN_2011c360((param_2 & 0x3ff) >> 5);
    iVar2 = FUN_2011c360(param_2 & 0x1f);
    return iVar1 << 0x10 | iVar2 << 8 | uVar3;
  case 3:
    uVar3 = FUN_2011c37c((param_2 & 0xfff) >> 8);
    iVar1 = FUN_2011c37c((param_2 & 0xff) >> 4);
    iVar2 = FUN_2011c37c(param_2 & 0xf);
    return iVar1 << 0x10 | iVar2 << 8 | uVar3;
  case 4:
    uVar3 = FUN_20119db8(param_2 & 0xffffff);
    return uVar3;
  default:
    return 0;
  case 10:
    uVar3 = FUN_2011c360((param_2 & 0xffff) >> 0xb);
    iVar1 = FUN_2011c360((param_2 & 0x7ff) >> 6);
    iVar2 = FUN_2011c360((param_2 & 0x3f) >> 1);
    return iVar1 << 0x10 | iVar2 << 8 | uVar3;
  case 0xb:
    uVar3 = FUN_20119db8(param_2 >> 8);
    return uVar3;
  }
}


// ===== FUN_2011c4d4 @ 2011c4d4 (224 bytes)

void FUN_2011c4d4(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  if (param_4 != (byte *)0x0) {
    iVar1 = FUN_2011d6dc(param_1,param_2);
    if ((iVar1 == 7 || iVar1 == 6) || iVar1 == 5) {
      *(uint *)puVar4[0xf] = (uint)*param_4 << 0x18;
      uVar2 = FUN_20119db8(*(uint *)(param_4 + 4) & 0xffffff);
      *(undefined4 *)puVar4[0x10] = uVar2;
    }
    else {
      uVar2 = FUN_2011c3a4(iVar1,*(undefined4 *)param_4);
      *(undefined4 *)puVar4[0xf] = uVar2;
      uVar2 = FUN_2011c3a4(iVar1,*(undefined4 *)(param_4 + 4));
      *(undefined4 *)puVar4[0x10] = uVar2;
    }
    uVar3 = *(uint *)puVar4[0x10];
    if (param_2 == 0 || param_2 == 5) {
      uVar3 = uVar3 | 0xff000000;
    }
    else {
      uVar3 = uVar3 | (uint)param_4[8] << 0x18;
    }
    *(uint *)puVar4[0x10] = uVar3;
  }
  uVar3 = *(uint *)puVar4[0xe];
  if (param_3 == 0) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  else {
    uVar3 = uVar3 | 1;
  }
  *(uint *)puVar4[0xe] = uVar3;
  *(uint *)*puVar4 = *(uint *)*puVar4 | 0x10;
  return;
}


// ===== FUN_2011c5b4 @ 2011c5b4 (48 bytes)

void FUN_2011c5b4(uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined4 *)param_1[1];
  if (*param_1 != 0) {
    do {
      *param_2 = *puVar1;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 < *param_1);
  }
  return;
}


// ===== FUN_2011c5e4 @ 2011c5e4 (264 bytes)

void FUN_2011c5e4(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(&DAT_201662c0 + param_2 * 0x58 + param_1 * 0x210);
  iVar1 = FUN_2011d6dc(param_1,param_2);
  if (iVar1 == 7) {
    if (*param_3 == 1) {
      uVar3 = FUN_20119db8(*(undefined4 *)param_3[1]);
      *(undefined4 *)puVar5[0x11] = uVar3;
      if (param_2 == 0 || param_2 == 5) {
        *(uint *)puVar5[0x11] = *(uint *)puVar5[0x11] | 0xff000000;
      }
      goto LAB_2011c6d8;
    }
    uVar3 = FUN_20119db8(*(undefined4 *)param_3[1]);
    *(undefined4 *)puVar5[0x11] = uVar3;
    uVar3 = FUN_20119db8(*(undefined4 *)(param_3[1] + 4));
    *(undefined4 *)puVar5[0x12] = uVar3;
    if (param_2 != 0 && param_2 != 5) goto LAB_2011c6d8;
    *(uint *)puVar5[0x11] = *(uint *)puVar5[0x11] | 0xff000000;
    puVar2 = (uint *)puVar5[0x12];
    uVar4 = *puVar2 | 0xff000000;
  }
  else {
    FUN_2011c5b4(param_3,(&PTR_DAT_201666e0)[param_1 * 6 + param_2]);
    puVar2 = (uint *)puVar5[0x14];
    uVar4 = *puVar2 ^ 0x10000;
  }
  *puVar2 = uVar4;
LAB_2011c6d8:
  *(uint *)*puVar5 = *(uint *)*puVar5 | 0x10;
  return;
}


// ===== FUN_2011c6ec @ 2011c6ec (368 bytes)

void FUN_2011c6ec(int param_1,char *param_2)

{
  int iVar1;
  ushort *puVar2;
  byte *pbVar3;
  uint uVar4;
  
  iVar1 = param_1 * 0x60;
  uVar4 = *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18];
  if (*param_2 == '\0') {
    uVar4 = uVar4 & 0xffffefff;
  }
  else {
    uVar4 = uVar4 | 0x1000;
  }
  *(uint *)(&PTR_DAT_2016676c)[param_1 * 0x18] = uVar4;
  puVar2 = *(ushort **)(param_2 + 4);
  if (puVar2 != (ushort *)0x0) {
    **(uint **)(&DAT_2016675c + iVar1) = (uint)*puVar2;
    **(int **)(&DAT_20166760 + iVar1) = (uint)puVar2[1] << 0x10;
    **(uint **)(&DAT_20166760 + iVar1) = (uint)puVar2[2] | **(uint **)(&DAT_20166760 + iVar1);
  }
  pbVar3 = *(byte **)(param_2 + 8);
  if (pbVar3 != (byte *)0x0) {
    **(int **)(&DAT_20166764 + iVar1) = (uint)*pbVar3 << 0x10;
    **(uint **)(&DAT_20166764 + iVar1) = **(uint **)(&DAT_20166764 + iVar1) | (uint)pbVar3[1] << 8;
    **(uint **)(&DAT_20166764 + iVar1) = (uint)pbVar3[2] | **(uint **)(&DAT_20166764 + iVar1);
  }
  pbVar3 = *(byte **)(param_2 + 0xc);
  if (pbVar3 != (byte *)0x0) {
    **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) & 0xffcfffff;
    **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) | (uint)*pbVar3 << 0x14;
    if (*pbVar3 == 2) {
      **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) & 0xffffcccc;
      **(uint **)(&DAT_20166768 + iVar1) =
           **(uint **)(&DAT_20166768 + iVar1) | (uint)pbVar3[1] << 0xc;
      **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) | (uint)pbVar3[2] << 8
      ;
      **(uint **)(&DAT_20166768 + iVar1) = **(uint **)(&DAT_20166768 + iVar1) | (uint)pbVar3[3] << 4
      ;
      **(uint **)(&DAT_20166768 + iVar1) = (uint)pbVar3[4] | **(uint **)(&DAT_20166768 + iVar1);
    }
  }
  **(uint **)(&DAT_20166754 + iVar1) = **(uint **)(&DAT_20166754 + iVar1) | 1;
  return;
}


// ===== FUN_2011c85c @ 2011c85c (72 bytes)

void FUN_2011c85c(ushort *param_1,int param_2)

{
  ushort *puVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_1 == (ushort *)0x0) {
    return;
  }
  uVar2 = 0;
  do {
    puVar1 = param_1 + 1;
    **(int **)(param_2 + uVar2 * 4) = (uint)*param_1 << 0x10;
    puVar3 = *(uint **)(param_2 + uVar2 * 4);
    param_1 = param_1 + 2;
    *puVar3 = *puVar3 | (uint)*puVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  return;
}


// ===== FUN_2011c8a4 @ 2011c8a4 (172 bytes)

void FUN_2011c8a4(byte *param_1,undefined4 *param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_1 == (byte *)0x0) {
    return;
  }
  *(uint *)*param_2 = (uint)*param_1 << 0x10;
  *(uint *)*param_2 = *(uint *)*param_2 | (uint)param_1[1] << 8;
  *(uint *)*param_2 = *(uint *)*param_2 | (uint)param_1[2];
  param_1 = param_1 + 3;
  uVar1 = 1;
  do {
    *(uint *)param_2[uVar1] = (uint)*param_1 << 0x18;
    *(uint *)param_2[uVar1] = *(uint *)param_2[uVar1] | (uint)param_1[1] << 0x10;
    pbVar2 = param_1 + 3;
    *(uint *)param_2[uVar1] = *(uint *)param_2[uVar1] | (uint)param_1[2] << 8;
    param_1 = param_1 + 4;
    *(uint *)param_2[uVar1] = *(uint *)param_2[uVar1] | (uint)*pbVar2;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}


// ===== FUN_2011c950 @ 2011c950 (176 bytes)

void FUN_2011c950(int param_1,int param_2,undefined4 *param_3)

{
  **(uint **)(&DAT_201667d0 + param_1 * 0x130) = (uint)(param_2 != 0);
  if (param_3 != (undefined4 *)0x0) {
    FUN_2011c8a4(param_3[1],&PTR_DAT_20166818 + param_1 * 0x4c);
    FUN_2011c85c(*param_3,&PTR_DAT_201667d8 + param_1 * 0x4c);
    *(uint *)(&PTR_DAT_201667d4)[param_1 * 0x4c] = *(uint *)(&PTR_DAT_201667d4)[param_1 * 0x4c] | 1;
    FUN_2011c8a4(param_3[3],&PTR_DAT_2016687c + param_1 * 0x4c);
    FUN_2011c85c(param_3[2],&PTR_DAT_2016683c + param_1 * 0x4c);
    *(uint *)(&PTR_DAT_20166838)[param_1 * 0x4c] = *(uint *)(&PTR_DAT_20166838)[param_1 * 0x4c] | 1;
    FUN_2011c8a4(param_3[5],&PTR_DAT_201668e0 + param_1 * 0x4c);
    FUN_2011c85c(param_3[4],&PTR_DAT_201668a0 + param_1 * 0x4c);
    *(uint *)(&PTR_DAT_2016689c)[param_1 * 0x4c] = *(uint *)(&PTR_DAT_2016689c)[param_1 * 0x4c] | 1;
  }
  return;
}


// ===== FUN_2011ca00 @ 2011ca00 (68 bytes)

void FUN_2011ca00(ushort *param_1,int param_2)

{
  uint uVar1;
  
  **(int **)(param_2 + 8) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 8) = **(uint **)(param_2 + 8) | (uint)param_1[1];
  uVar1 = **(uint **)(param_2 + 0xc);
  if ((char)param_1[3] == '\0') {
    uVar1 = uVar1 & 0xffffffef;
  }
  else {
    uVar1 = uVar1 | 0x10;
  }
  **(uint **)(param_2 + 0xc) = uVar1;
  return;
}


// ===== FUN_2011ca44 @ 2011ca44 (68 bytes)

void FUN_2011ca44(ushort *param_1,int param_2)

{
  uint uVar1;
  
  **(int **)(param_2 + 0x10) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x10) = **(uint **)(param_2 + 0x10) | (uint)param_1[1];
  uVar1 = **(uint **)(param_2 + 0x14);
  if ((char)param_1[3] == '\0') {
    uVar1 = uVar1 & 0xffffffef;
  }
  else {
    uVar1 = uVar1 | 0x10;
  }
  **(uint **)(param_2 + 0x14) = uVar1;
  return;
}


// ===== FUN_2011ca88 @ 2011ca88 (112 bytes)

void FUN_2011ca88(ushort *param_1,int param_2)

{
  **(int **)(param_2 + 0x18) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x18) = **(uint **)(param_2 + 0x18) | (uint)param_1[1];
  **(uint **)(param_2 + 0x1c) = **(uint **)(param_2 + 0x1c) & 0xfffffeef;
  if (*(char *)((int)param_1 + 5) != '\0') {
    **(uint **)(param_2 + 0x1c) = **(uint **)(param_2 + 0x1c) | 0x100;
  }
  if ((char)param_1[3] != '\0') {
    **(uint **)(param_2 + 0x1c) = **(uint **)(param_2 + 0x1c) | 0x10;
  }
  return;
}


// ===== FUN_2011caf8 @ 2011caf8 (112 bytes)

void FUN_2011caf8(ushort *param_1,int param_2)

{
  **(int **)(param_2 + 0x20) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x20) = **(uint **)(param_2 + 0x20) | (uint)param_1[1];
  **(uint **)(param_2 + 0x24) = **(uint **)(param_2 + 0x24) & 0xfffffeef;
  if (*(char *)((int)param_1 + 5) != '\0') {
    **(uint **)(param_2 + 0x24) = **(uint **)(param_2 + 0x24) | 0x100;
  }
  if ((char)param_1[3] != '\0') {
    **(uint **)(param_2 + 0x24) = **(uint **)(param_2 + 0x24) | 0x10;
  }
  return;
}


// ===== FUN_2011cb68 @ 2011cb68 (112 bytes)

void FUN_2011cb68(ushort *param_1,int param_2)

{
  **(int **)(param_2 + 0x28) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x28) = **(uint **)(param_2 + 0x28) | (uint)param_1[1];
  **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) & 0xfffffeef;
  if (*(char *)((int)param_1 + 5) != '\0') {
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | 0x100;
  }
  if ((char)param_1[3] != '\0') {
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | 0x10;
  }
  return;
}


// ===== FUN_2011cbd8 @ 2011cbd8 (136 bytes)

void FUN_2011cbd8(ushort *param_1,int param_2)

{
  **(int **)(param_2 + 0x30) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x30) = **(uint **)(param_2 + 0x30) | (uint)param_1[1];
  **(uint **)(param_2 + 0x34) = **(uint **)(param_2 + 0x34) & 0xffffceef;
  **(uint **)(param_2 + 0x34) = **(uint **)(param_2 + 0x34) | (uint)(byte)param_1[2] << 0xc;
  if (*(char *)((int)param_1 + 5) != '\0') {
    **(uint **)(param_2 + 0x34) = **(uint **)(param_2 + 0x34) | 0x100;
  }
  if ((char)param_1[3] != '\0') {
    **(uint **)(param_2 + 0x34) = **(uint **)(param_2 + 0x34) | 0x10;
  }
  return;
}


// ===== FUN_2011cc60 @ 2011cc60 (136 bytes)

void FUN_2011cc60(ushort *param_1,int param_2)

{
  **(int **)(param_2 + 0x38) = (uint)*param_1 << 0x10;
  **(uint **)(param_2 + 0x38) = **(uint **)(param_2 + 0x38) | (uint)param_1[1];
  **(uint **)(param_2 + 0x3c) = **(uint **)(param_2 + 0x3c) & 0xffffceef;
  **(uint **)(param_2 + 0x3c) = **(uint **)(param_2 + 0x3c) | (uint)(byte)param_1[2] << 0xc;
  if (*(char *)((int)param_1 + 5) != '\0') {
    **(uint **)(param_2 + 0x3c) = **(uint **)(param_2 + 0x3c) | 0x100;
  }
  if ((char)param_1[3] != '\0') {
    **(uint **)(param_2 + 0x3c) = **(uint **)(param_2 + 0x3c) | 0x10;
  }
  return;
}

