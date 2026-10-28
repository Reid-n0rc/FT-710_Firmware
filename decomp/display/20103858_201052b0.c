// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== touch_init @ 20103858 (124 bytes)

/* tasks "tsc2007" x2 */

void touch_init(void)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_201651c4);
  if (((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) &&
     (iVar1 = itron_acre_tsk(0,&DAT_201651a8), 0 < iVar1)) {
    itron_sta_tsk(iVar1,0);
  }
  return;
}


// ===== FUN_20103934 @ 20103934 (124 bytes)

void FUN_20103934(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_2014a5dc(param_1,param_2,param_3,0,1,0x200);
  if ((iVar1 == 0) && (iVar1 = FUN_20143c34(param_1,param_4,0x3296,5), iVar1 == 0)) {
    FUN_20143eac(param_1,param_5,0x4100,8);
    return;
  }
  return;
}


// ===== sd_fs_init @ 201039b0 (156 bytes)

/* FAT volume + SDHI driver registration, then sd_task_create */

void sd_fs_init(void)

{
  int iVar1;
  
  iVar1 = FUN_2014a4d0(&DAT_20808c4c,2);
  if (iVar1 == 0) {
    iVar1 = FUN_20103934(&DAT_20809984,0x49,FUN_2013fd98,&DAT_208099f8,&DAT_2080cc8e,0);
    if (iVar1 == 0) {
      sd_task_create();
    }
  }
  return;
}


// ===== FUN_20103a58 @ 20103a58 (40 bytes)

void FUN_20103a58(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_201446bc();
  if (iVar1 == 0) {
    FUN_201446d0(param_1 + param_2 * 4);
    return;
  }
  return;
}


// ===== FUN_20103a94 @ 20103a94 (72 bytes)

void FUN_20103a94(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_2013faf4(param_2);
    FUN_2014d95c();
    if (((param_1 != 0) && (iVar1 == 1)) || (param_1 == 0 && iVar1 == 0)) break;
    FUN_201525f8(10);
  }
  return;
}


// ===== sd_task_create @ 20103b68 (40 bytes)

/* "sdTask" */

undefined4 sd_task_create(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e5b0(&DAT_201651e0,"sdTask");
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_2014e73c(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_20103ba0 @ 20103ba0 (16 bytes)

uint FUN_20103ba0(void)

{
  return (DAT_20800094 & 0x7f) >> 6;
}


// ===== FUN_20103bb0 @ 20103bb0 (16 bytes)

byte FUN_20103bb0(void)

{
  return DAT_20800094 >> 7;
}


// ===== FUN_20103bc0 @ 20103bc0 (40 bytes)

uint FUN_20103bc0(void)

{
  uint uVar1;
  
  if (*(int *)(DAT_20808b60 + 0x24) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(byte *)(DAT_20808b60 + 0x68) & 0x3f) >> 5;
  }
  return uVar1;
}


// ===== FUN_20103bc8 @ 20103bc8 (12 bytes)

void FUN_20103bc8(undefined4 param_1)

{
  DAT_20800098 = param_1;
  return;
}


// ===== FUN_20103bdc @ 20103bdc (56 bytes)

undefined4 FUN_20103bdc(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    if (*(short *)(&UNK_201651fc + iVar1 * 8) == param_1) {
      return *(undefined4 *)(&UNK_20165200 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  return 0x10000;
}


// ===== FUN_20103c14 @ 20103c14 (84 bytes)

uint FUN_20103c14(void)

{
  int iVar1;
  undefined1 local_20;
  undefined1 local_1f;
  uint local_c [2];
  
  local_c[0] = 0xff;
  local_20 = 0x62;
  local_1f = 0x70;
  iVar1 = FUN_20104f34(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    FUN_20104e20(local_c,1);
    local_c[0] = local_c[0] & 0xff;
  }
  return local_c[0];
}


// ===== FUN_20103c70 @ 20103c70 (88 bytes)

uint FUN_20103c70(undefined4 param_1)

{
  int iVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1e;
  uint local_c [2];
  
  local_c[0] = 0xff;
  local_20 = 0x65;
  local_1f = 0x72;
  local_1e = param_1;
  iVar1 = FUN_20104f34(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    FUN_20104e20(local_c,1);
    local_c[0] = local_c[0] & 0xff;
  }
  return local_c[0];
}


// ===== FUN_20103cc8 @ 20103cc8 (52 bytes)

int FUN_20103cc8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = iVar1 + (*(byte *)(param_1 + iVar2) + 1 & 0xff);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return iVar1;
}


// ===== FUN_20103cfc @ 20103cfc (212 bytes)

undefined4 FUN_20103cfc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  iVar4 = 0;
  if (param_1 != 0) {
    FUN_201140f4(param_1,param_2,0,0);
    FUN_201140d0();
  }
  FUN_20105060();
  iVar1 = FUN_20103c14();
  if (-1 < iVar1) {
    uVar3 = 0;
    while (iVar1 = FUN_20103c70(iVar4), -1 < iVar1) {
      iVar1 = FUN_20103bdc(uVar3);
      iVar4 = iVar4 + iVar1;
      if (param_1 != 0) {
        uVar5 = FUN_20164d54(0x88);
        uVar6 = FUN_20164d54(uVar3);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
        FUN_201140f4(param_1,uVar2,(int)uVar5,uVar2);
        FUN_201140d0();
        if ((uVar3 & 7) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar3 = uVar3 + 1;
      if (0x87 < (int)uVar3) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_20103dd0 @ 20103dd0 (164 bytes)

uint FUN_20103dd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2e;
  uint local_1c [2];
  
  iVar1 = FUN_20103cc8(param_2,param_3);
  local_1c[0] = 0xff;
  local_30 = 0x70;
  local_2f = 0x72;
  local_2e = param_1;
  iVar2 = FUN_20104f34(&local_30,6);
  if ((-1 < iVar2) && (iVar2 = FUN_20104f34(param_2,param_3), -1 < iVar2)) {
    FUN_20104e20(local_1c,1);
    iVar2 = FUN_20103cc8(param_1 + 0x18000000,param_3);
    if (iVar2 == iVar1) {
      local_1c[0] = local_1c[0] & 0xff;
    }
    else {
      local_1c[0] = 0x16;
    }
    return local_1c[0];
  }
  return 1;
}


// ===== FUN_20103e74 @ 20103e74 (208 bytes)

undefined4 FUN_20103e74(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar1 = param_3 + 0xffffU >> 0x10;
  if (param_1 != 0) {
    FUN_201140f4(param_1,param_2,0,0);
    FUN_201140d0();
  }
  FUN_20105060();
  iVar2 = FUN_20103c14();
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = FUN_20103c70(param_2);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x10000;
      if (param_1 != 0) {
        uVar5 = FUN_20164d82(uVar1);
        uVar6 = FUN_20164d54(uVar4);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
        FUN_201140f4(param_1,uVar3,(int)uVar5,uVar3);
        FUN_201140d0();
        if ((uVar4 & 0xf) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}


// ===== FUN_20103f44 @ 20103f44 (188 bytes)

undefined4 FUN_20103f44(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  iVar4 = 0;
  if (param_1 != 0) {
    FUN_201140f4();
    FUN_201140d0();
  }
  FUN_20105060();
  iVar1 = FUN_20103c14();
  if (-1 < iVar1) {
    uVar3 = 0;
    while (iVar1 = FUN_20103c70(iVar4), -1 < iVar1) {
      iVar4 = iVar4 + 0x10000;
      if (param_1 != 0) {
        uVar5 = FUN_20164d54(0x100);
        uVar6 = FUN_20164d54(uVar3);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
        FUN_201140f4(param_1,uVar2,(int)uVar5,uVar2);
        FUN_201140d0();
        if ((uVar3 & 0xf) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar3 = uVar3 + 1;
      if (0xff < (int)uVar3) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_20104000 @ 20104000 (80 bytes)

undefined1 FUN_20104000(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_3fefa010;
  uVar2 = DAT_3fefa01c;
  DAT_3fefa010 = 0x9f0000;
  DAT_3fefa01c = 0x4000;
  DAT_3fefa010 = uVar1;
  DAT_3fefa01c = uVar2;
  return DAT_18000000;
}


// ===== FUN_20104050 @ 20104050 (40 bytes)

void FUN_20104050(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_20104000();
  if (iVar1 != 0xbf) {
    FUN_20103f44();
    return;
  }
  FUN_20103cfc(param_1);
  return;
}


// ===== FUN_20104078 @ 20104078 (104 bytes)

undefined4 FUN_20104078(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_28;
  undefined1 local_27;
  undefined4 local_26;
  
  FUN_20105060();
  local_28 = 0x72;
  local_27 = 100;
  local_26 = param_1;
  iVar1 = FUN_20104f34(&local_28,6);
  if (iVar1 < 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_20104e20(param_3,param_2);
  }
  return uVar2;
}


// ===== FUN_20104104 @ 20104104 (20 bytes)

undefined4 FUN_20104104(int *param_1,int param_2)

{
  return *(undefined4 *)(*param_1 + param_2);
}


// ===== FUN_20104110 @ 20104110 (28 bytes)

void FUN_20104110(int *param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_20104124 @ 20104124 (28 bytes)

void FUN_20104124(int *param_1,undefined2 param_2,int param_3)

{
  *(undefined2 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_20104138 @ 20104138 (28 bytes)

void FUN_20104138(int *param_1,undefined1 param_2,int param_3)

{
  *(undefined1 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_20104154 @ 20104154 (48 bytes)

int FUN_20104154(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20104188 @ 20104188 (24 bytes)

uint FUN_20104188(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_20104104(param_1,0x48);
  return ~(uVar1 >> 1) & 1;
}


// ===== FUN_201041a0 @ 201041a0 (84 bytes)

undefined4 FUN_201041a0(undefined4 param_1)

{
  uint uVar1;
  undefined4 local_10;
  
  local_10 = 100000;
  do {
    uVar1 = FUN_20104104(param_1,0x48);
    if ((uVar1 & 1) != 0) {
      return 0;
    }
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  return 0xffffffff;
}


// ===== FUN_201041f4 @ 201041f4 (136 bytes)

undefined4 FUN_201041f4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_20104104(param_1,0x48);
  if (iVar1 != 1) {
    iVar1 = FUN_201041a0(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_20104104(param_1,0x48);
    if (iVar1 != 1) {
      FUN_20104110(param_1,0x20,1);
      FUN_20104110(param_1,0x20,0);
      FUN_201041a0(param_1);
      iVar1 = FUN_20104104(param_1,0x48);
      if (iVar1 != 1) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}


// ===== FUN_2010427c @ 2010427c (528 bytes)

int FUN_2010427c(int param_1,ushort *param_2,uint param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  byte bVar9;
  undefined4 uVar10;
  
  bVar9 = 0;
  uVar10 = 0;
  bVar2 = true;
  iVar3 = FUN_201041a0();
  do {
    if (iVar3 < 0) {
      return iVar3;
    }
    if (param_3 == 0) {
      return 0;
    }
    uVar8 = param_3;
    if (*(int *)(param_1 + 4) == 0) {
      if (param_3 < 4) {
        if (param_3 == 3) {
          uVar8 = 2;
        }
      }
      else {
        uVar8 = 4;
      }
      bVar9 = (&UNK_2016525c)[uVar8] | bVar9 & 0xf0;
      uVar4 = (uint)(byte)*param_2;
      puVar6 = (ushort *)((int)param_2 + 1);
      if (1 < (int)uVar8) {
        uVar1 = CONCAT11(*(byte *)((int)param_2 + 1),(byte)*param_2);
        uVar4 = (uint)uVar1;
        puVar6 = param_2 + 1;
        if (2 < (int)uVar8) {
          puVar6 = (ushort *)((int)param_2 + 3);
          uVar4 = (uint)CONCAT12((byte)param_2[1],uVar1);
        }
      }
      puVar7 = puVar6;
      if ((int)uVar8 < 4) goto LAB_201043ac;
      puVar7 = (ushort *)((int)puVar6 + 1);
      uVar4 = uVar4 | (uint)(byte)*puVar6 << 0x18;
LAB_201043b4:
      if (uVar8 == 1) {
        FUN_20104138(param_1,uVar4 & 0xff,0x40);
      }
      else {
        FUN_20104110(param_1,uVar4,0x40);
        if (uVar8 == 8) {
          FUN_20104110(param_1,uVar10,0x44);
        }
      }
    }
    else {
      if (7 < param_3) {
        uVar8 = 8;
      }
      if ((uVar8 & 1) != 0) {
        return -1;
      }
      if (uVar8 == 6) {
        uVar8 = 4;
      }
      bVar9 = *(byte *)((int)&DAT_20165268 + uVar8 + 1) | bVar9 & 0xf0;
      if (uVar8 == 8) {
        uVar10 = *(undefined4 *)param_2;
        param_2 = param_2 + 2;
      }
      uVar4 = (uint)*param_2;
      puVar7 = param_2 + 1;
      if (3 < (int)uVar8) {
        puVar7 = param_2 + 2;
        uVar4 = CONCAT13(*(byte *)((int)param_2 + 3),CONCAT12((byte)param_2[1],*param_2));
        goto LAB_201043b4;
      }
LAB_201043ac:
      if (uVar8 != 2) goto LAB_201043b4;
      FUN_20104124(param_1,uVar4 & 0xffff,0x40);
    }
    param_3 = param_3 - uVar8;
    if (param_3 == 0) {
      bVar2 = false;
    }
    FUN_20104110(param_1,0,0x24);
    FUN_20104110(param_1,0,0x28);
    FUN_20104110(param_1,0,0x2c);
    FUN_20104110(param_1,bVar9,0x30);
    uVar5 = 3;
    if (bVar2 || param_4 != 0) {
      uVar5 = 0x103;
    }
    FUN_20104110(param_1,uVar5,0x20);
    iVar3 = FUN_201041a0(param_1);
    param_2 = puVar7;
  } while( true );
}


// ===== FUN_2010448c @ 2010448c (704 bytes)

int FUN_2010448c(int param_1,byte *param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  byte bVar2;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte *pbVar16;
  uint uVar17;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar10 = true;
  bVar9 = false;
  iVar12 = FUN_201041a0();
  if (iVar12 < 0) {
    return iVar12;
  }
  if (((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x14) == 0)) &&
     (*(char *)(param_1 + 0x28) == '\x05' || *(char *)(param_1 + 0x28) == -0x61)) {
    bVar9 = true;
    param_3 = param_3 << 1;
  }
  if (*(char *)(param_1 + 0x28) == 'p') {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar17 = param_3;
    if (*(int *)(param_1 + 4) == 0) {
      if (param_3 < 4) {
        if (param_3 == 3) {
          uVar17 = 2;
        }
      }
      else {
        uVar17 = 4;
      }
      puVar13 = &UNK_2016525c;
    }
    else {
      if (7 < param_3) {
        uVar17 = 8;
      }
      if ((uVar17 & 1) != 0) {
        return -1;
      }
      puVar13 = (undefined *)0x20165269;
      if (uVar17 == 6) {
        uVar17 = 4;
      }
    }
    param_3 = param_3 - uVar17;
    if (param_3 == 0) {
      bVar10 = false;
    }
    uVar1 = puVar13[uVar17];
    FUN_20104110(param_1,0,0x24);
    FUN_20104110(param_1,0,0x28);
    FUN_20104110(param_1,0,0x2c);
    FUN_20104110(param_1,uVar1,0x30);
    uVar15 = 7;
    if (bVar10 || param_4 != 0) {
      uVar15 = 0x107;
    }
    FUN_20104110(param_1,uVar15,0x20);
    iVar12 = FUN_201041a0(param_1);
    if (iVar12 < 0) break;
    uVar15 = FUN_20104104(param_1,0x38);
    uVar14 = FUN_20104104(param_1,0x3c);
    bVar2 = (byte)uVar14;
    bVar3 = (byte)((uint)uVar14 >> 8);
    bVar4 = (byte)((uint)uVar14 >> 0x10);
    bVar5 = (byte)((uint)uVar14 >> 0x18);
    bVar6 = (byte)uVar15;
    bVar11 = (byte)((uint)uVar15 >> 8);
    bVar7 = (byte)((uint)uVar15 >> 0x10);
    bVar8 = (byte)((uint)uVar15 >> 0x18);
    if (bVar9) {
      if (uVar17 == 8) {
        if (*(int *)(param_1 + 0x18) == 0) {
          *param_2 = bVar3 | bVar2;
          param_2[1] = bVar4 | bVar5;
          param_2[2] = bVar6 | bVar11;
          param_2[3] = bVar7 | bVar8;
          param_2 = param_2 + 4;
        }
        else {
          *param_2 = bVar3 & bVar2;
          param_2[1] = bVar4 & bVar5;
          param_2[2] = bVar6 & bVar11;
          param_2[3] = bVar7 & bVar8;
          param_2 = param_2 + 4;
        }
      }
      else if (uVar17 == 2) {
        if (*(int *)(param_1 + 0x18) == 0) {
          bVar11 = bVar11 | bVar6;
        }
        else {
          bVar11 = bVar11 & bVar6;
        }
        *param_2 = bVar11;
        param_2 = param_2 + 1;
      }
      else if (uVar17 == 4) {
        if (*(int *)(param_1 + 0x18) == 0) {
          *param_2 = bVar11 | bVar6;
          param_2[1] = bVar7 | bVar8;
          param_2 = param_2 + 2;
        }
        else {
          *param_2 = bVar11 & bVar6;
          param_2[1] = bVar7 & bVar8;
          param_2 = param_2 + 2;
        }
      }
    }
    else {
      if (uVar17 == 8) {
        *param_2 = bVar2;
        param_2[1] = bVar3;
        param_2[2] = bVar4;
        param_2[3] = bVar5;
        param_2 = param_2 + 4;
      }
      *param_2 = bVar6;
      pbVar16 = param_2 + 1;
      if (1 < (int)uVar17) {
        pbVar16 = param_2 + 2;
        param_2[1] = bVar11;
      }
      param_2 = pbVar16;
      if (3 < (int)uVar17) {
        *pbVar16 = bVar7;
        pbVar16[1] = bVar8;
        param_2 = pbVar16 + 2;
      }
    }
  }
  return iVar12;
}


// ===== FUN_2010474c @ 2010474c (104 bytes)

void FUN_2010474c(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *unaff_r5;
  uint uVar3;
  undefined1 local_20 [16];
  
  *(undefined1 *)(param_1 + 0x28) = *param_2;
  if (*(int *)(param_1 + 4) != 0) {
    uVar3 = 0;
    if (param_3 != 0) {
      unaff_r5 = local_20;
    }
    iVar2 = 0;
    if (param_3 != 0) {
      do {
        unaff_r5[iVar2] = param_2[uVar3];
        puVar1 = param_2 + uVar3;
        uVar3 = uVar3 + 1;
        unaff_r5[iVar2 + 1] = *puVar1;
        iVar2 = iVar2 + 2;
      } while (uVar3 < param_3);
    }
    param_3 = param_3 << 1;
    param_2 = local_20;
  }
  FUN_2010427c(param_1,param_2,param_3);
  return;
}


// ===== FUN_201047b4 @ 201047b4 (148 bytes)

undefined4 FUN_201047b4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  undefined1 local_14 [8];
  
  iVar2 = 1000000;
  local_14[0] = 5;
  local_18 = 0;
  FUN_2010474c(param_1,local_14,1);
  do {
    FUN_2010448c(param_1,&local_18,1);
    if ((local_18 & 0x81) == 0) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_2010448c(param_1,&local_18,1,0);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20104848 @ 20104848 (156 bytes)

undefined4 FUN_20104848(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  undefined1 local_14 [8];
  
  iVar2 = 1000000;
  local_14[0] = 5;
  local_18 = 0;
  FUN_2010474c(param_1,local_14,1);
  do {
    FUN_2010448c(param_1,&local_18,1);
    if (((local_18 & 2) != 0) && ((local_18 & 0x81) == 0)) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_2010448c(param_1,&local_18,1,0);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_201048e4 @ 201048e4 (96 bytes)

uint FUN_201048e4(undefined4 param_1)

{
  uint local_10;
  undefined1 local_c [4];
  
  local_c[0] = 0x35;
  local_10 = 0;
  FUN_2010474c(param_1,local_c,1);
  FUN_2010448c(param_1,&local_10,1);
  FUN_2010448c(param_1,&local_10,1,0);
  return local_10 & 0xff;
}


// ===== FUN_20104944 @ 20104944 (36 bytes)

undefined4 FUN_20104944(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x81fff320;
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = 0x81fff321;
  }
  FUN_20104110(param_1,uVar1,0);
  return 0;
}


// ===== FUN_20104968 @ 20104968 (140 bytes)

undefined4 FUN_20104968(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_20104104(param_1,0xc);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  FUN_20104110(param_1,0x1000000,0xc);
  FUN_20104110(param_1,0,0x20);
  FUN_201041a0(param_1);
  iVar2 = FUN_20104188(param_1);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_20104104(param_1,0);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
    uVar3 = FUN_20104104(param_1,0);
    FUN_20104110(param_1,uVar3 | 0x80000000,0);
    FUN_20104944(param_1);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20104a08 @ 20104a08 (92 bytes)

undefined4 FUN_20104a08(int param_1)

{
  uint uVar1;
  
  FUN_201041f4();
  FUN_20104110(param_1,*(undefined4 *)(param_1 + 0x24),0xc);
  FUN_20104110(param_1,*(undefined4 *)(param_1 + 0x20),0);
  uVar1 = FUN_20104104(param_1,0xc);
  FUN_20104110(param_1,uVar1 | 0x200,0xc);
  FUN_20104104(param_1,0xc);
  return 0;
}


// ===== FUN_20104a64 @ 20104a64 (188 bytes)

int FUN_20104a64(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined4 local_14;
  
  _local_18 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                       CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),0xb)))
  ;
  local_14 = 0x80000ff;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_201048e4(param_1);
    FUN_2010474c(param_1,&local_18,5,1);
    FUN_2010448c(param_1,param_2,param_3,0);
    if (*(int *)(param_1 + 4) != 0) {
      param_3 = param_3 / 2;
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    FUN_20104a08(&DAT_20810d90);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20104b20 @ 20104b20 (184 bytes)

int FUN_20104b20(int param_1)

{
  int iVar1;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c [4];
  
  local_c[0] = 6;
  _local_10 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                       CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),0xd8))
                      );
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_2010474c(param_1,local_c,1,0);
    iVar1 = FUN_20104848(param_1);
    if (iVar1 == 0) {
      thunk_FUN_20104154(&DAT_208000a8);
      FUN_2010474c(param_1,&local_10,4,0);
      iVar1 = FUN_201047b4(param_1);
      thunk_FUN_20104154(&DAT_208000a8);
      FUN_20104a08(&DAT_20810d90);
    }
  }
  return iVar1;
}


// ===== FUN_20104bd8 @ 20104bd8 (452 bytes)

int FUN_20104bd8(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined1 local_2c [8];
  
  local_30 = 2;
  local_2c[0] = 6;
  iVar2 = *(int *)(param_1 + 4) * 0x100 + 0x100;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      while( true ) {
        local_30 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                            CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                     CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),
                                              (undefined1)local_30)));
        FUN_2010474c(param_1,local_2c,1,0);
        iVar1 = FUN_20104848(param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (DAT_208000a0 == 0) {
          if (iVar2 <= param_3) {
            FUN_2010474c(param_1,&local_30,4,1);
            FUN_2010427c(param_1,param_2,iVar2,0);
            param_3 = param_3 - iVar2;
            param_2 = param_2 + iVar2;
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x100;
          }
        }
        else if (iVar2 <= DAT_208000a0 + param_3) {
          FUN_2010474c(param_1,&local_30,4,1);
          FUN_2010427c(param_1,&DAT_20810dbc,DAT_208000a0,1);
          FUN_2010427c(param_1,param_2,iVar2 - DAT_208000a0,0);
          iVar1 = DAT_208000a0;
          DAT_208000a0 = 0;
          param_3 = param_3 - (iVar2 - iVar1);
          param_2 = param_2 + (iVar2 - iVar1);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x100;
        }
        iVar1 = FUN_201047b4(param_1);
        if (*(int *)(param_1 + 0x10) != 0) break;
        if (param_3 < iVar2) {
          for (; param_3 != 0; param_3 = param_3 + -1) {
            (&DAT_20810dbc)[DAT_208000a0] = *param_2;
            DAT_208000a0 = DAT_208000a0 + 1;
            param_2 = param_2 + 1;
          }
        }
        if ((iVar1 != 0) || (param_3 == 0)) break;
      }
    }
    FUN_20104a08(&DAT_20810d90);
  }
  return iVar1;
}


// ===== FUN_20104d9c @ 20104d9c (132 bytes)

int FUN_20104d9c(undefined4 param_1)

{
  int iVar1;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  
  local_10[0] = 0x98;
  local_c[0] = 6;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_2010474c(param_1,local_c,1,0);
    iVar1 = FUN_20104848(param_1);
    if (iVar1 == 0) {
      FUN_2010474c(param_1,local_10,1,0);
      iVar1 = FUN_201047b4(param_1);
      FUN_20104a08(&DAT_20810d90);
    }
  }
  return iVar1;
}


// ===== FUN_20104e20 @ 20104e20 (276 bytes)

uint FUN_20104e20(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  if (DAT_20810d98 != 1) {
    if (DAT_20810d98 == 3) {
      if (DAT_208000a0 != 0) {
        iVar2 = DAT_20810d94 * 0x100;
        DAT_20810d98 = 3;
        for (; DAT_208000a0 < iVar2 + 0x100; DAT_208000a0 = DAT_208000a0 + 1) {
          (&DAT_20810dbc)[DAT_208000a0] = 0xff;
        }
        DAT_208000a0 = 0;
        FUN_20104bd8(&DAT_20810d90);
      }
    }
    else if (DAT_20810d98 != 2) {
      DAT_20810d98 = 0;
      DAT_20810da0 = 0;
      return 0;
    }
    DAT_20810d98 = 0;
    uVar1 = (undefined1)DAT_20810da0;
    DAT_20810da0 = 0;
    *param_1 = uVar1;
    return 1;
  }
  bVar3 = DAT_20810d94 != 0;
  bVar4 = (param_2 & 1) != 0;
  if (bVar3 && bVar4) {
    param_2 = param_2 + 1;
  }
  iVar2 = FUN_20104a64(&DAT_20810d90,param_1,param_2);
  if (DAT_20810da0 == 0) {
    if (bVar3 && bVar4) {
      param_2 = param_2 - 1;
      DAT_20810d98 = 0;
    }
    if (iVar2 != 0) {
      param_2 = 0xfffffffd;
      DAT_20810d98 = 0;
    }
    return param_2;
  }
  DAT_20810d98 = 0;
  return 0xffffffff;
}


// ===== FUN_20104f34 @ 20104f34 (300 bytes)

uint FUN_20104f34(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  
  if (DAT_20810da0 != 0) {
    return 0xffffffff;
  }
  if (DAT_20810d98 == 1) {
    DAT_20810d98 = 0;
    DAT_20810d9c = 0;
  }
  else {
    uVar2 = param_2;
    if (DAT_20810d98 == 3) goto LAB_20105028;
    if (DAT_20810d98 != 0) {
      return 0xfffffffc;
    }
  }
  cVar1 = *param_1;
  if (cVar1 == 'r') {
    if (5 < param_2) {
      DAT_20810d98 = 1;
      DAT_20810d9c = *(undefined4 *)(param_1 + 2);
      return param_2;
    }
    return 0xfffffffc;
  }
  if (cVar1 == 'e') {
    if (5 < param_2) {
      DAT_20810d98 = 2;
      DAT_20810d9c = *(undefined4 *)(param_1 + 2);
      uVar2 = FUN_20104b20(&DAT_20810d90);
      return uVar2;
    }
    return 0xfffffffc;
  }
  if (cVar1 != 'p') {
    if (cVar1 == 'd') {
      if (1 < param_2) {
        DAT_20810d94 = (byte)param_1[1] - 0x30;
        return param_2;
      }
      return 0xfffffffc;
    }
    if (cVar1 == 'b') {
      FUN_20104d9c(&DAT_20810d90);
      return param_2;
    }
    return 0xfffffffc;
  }
  if (param_2 < 6) {
    return 0xfffffffc;
  }
  DAT_20810d98 = 3;
  DAT_20810d9c = *(undefined4 *)(param_1 + 2);
  if (param_2 < 7) {
    DAT_20810d98 = 3;
    return param_2;
  }
  param_1 = param_1 + 6;
  uVar2 = param_2 - 6;
LAB_20105028:
  FUN_20104bd8(&DAT_20810d90,param_1,uVar2);
  return param_2;
}


// ===== FUN_20105060 @ 20105060 (20 bytes)

undefined4 FUN_20105060(void)

{
  DAT_20810d90 = &DAT_3fefa000;
  return 0;
}


// ===== FUN_2010508c @ 2010508c (32 bytes)

void FUN_2010508c(void)

{
  if (DAT_208000e0 != 0) {
    FUN_20141ff0();
  }
  DAT_208000e0 = 0;
  return;
}


// ===== FUN_201050ac @ 201050ac (96 bytes)

undefined4 FUN_201050ac(void)

{
  int iVar1;
  
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    FUN_2010508c();
  }
  else if (DAT_208000e0 != 0) {
    iVar1 = FUN_20141ff0();
    if (iVar1 == 0) {
      DAT_208000e0 = 0;
      return 0;
    }
    DAT_208000bc = FUN_2014d95c();
    DAT_208000e0 = 0;
  }
  return 0xfffffffe;
}


// ===== FUN_2010510c @ 2010510c (76 bytes)

char * FUN_2010510c(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  do {
    cVar1 = *param_1;
    if (cVar1 == *param_2) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (param_2[iVar2] == '\0') {
          return param_1;
        }
      } while (param_1[iVar2] == param_2[iVar2]);
    }
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (char *)0x0;
}


// ===== FUN_20105158 @ 20105158 (292 bytes)

undefined4 FUN_20105158(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_2015507c(param_1,&DAT_20105280,4);
    if ((((((iVar1 == 0) && (iVar1 = FUN_2015507c(param_1 + 8,&DAT_20105288,4), iVar1 == 0)) &&
          (iVar1 = FUN_2015507c(param_1 + 0x24,&DAT_20105290,4), iVar1 == 0)) &&
         ((iVar1 = FUN_2015507c(param_1 + 0x2c,&DAT_20105298,4), iVar1 == 0 &&
          (iVar1 = FUN_2015507c(param_1 + 0xc,&DAT_201052a0,4), iVar1 == 0)))) &&
        ((iVar1 = FUN_2015507c(param_1 + 0x54,&DAT_201052a8,4), iVar1 == 0 &&
         ((param_3 != 2 || (iVar1 = FUN_2015507c(param_2,param_1 + 0x34,7), iVar1 == 0)))))) &&
       ((*(int *)(param_1 + 0x30) == 0x20 && (*(int *)(param_1 + 0x10) == 0x10)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffd;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_201052b0 @ 201052b0 (588 bytes)

undefined4 FUN_201052b0(int *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [20];
  ushort local_64;
  ushort local_62;
  int local_60;
  undefined4 local_5c;
  ushort local_56;
  undefined1 auStack_44 [36];
  int local_20;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if (DAT_208000e0 != 0) {
    return 0xfffffffe;
  }
  if (param_2 == 1) {
    pcVar7 = "I:\\FT-710\\PlayList";
  }
  else {
    if (param_2 != 2) {
      return 0xfffffffe;
    }
    pcVar7 = "I:\\FT-710\\MESSAGE";
  }
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    return 0xfffffffe;
  }
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  FUN_201550dc(&local_b8,pcVar7);
  FUN_2015515c(&local_b8,&DAT_20105524);
  FUN_2015515c(&local_b8,*param_1);
  FUN_2015515c(&local_b8,&DAT_20105528);
  DAT_208000e0 = fs_fopen(&local_b8,&DAT_20105530);
  if (DAT_208000e0 == 0) {
    return 0xfffffffe;
  }
  iVar1 = fs_fread(auStack_78,0x5c,1,DAT_208000e0);
  if (iVar1 == 0) {
    FUN_2010508c();
    return 0xfffffffe;
  }
  iVar1 = FUN_20105158(auStack_78,*param_1,param_2);
  if (iVar1 != 0) {
    FUN_2010508c();
    return 0xfffffffd;
  }
  param_1[3] = (uint)local_64;
  param_1[4] = (uint)local_62;
  param_1[5] = local_60;
  param_1[6] = (uint)local_56;
  param_1[7] = local_20;
  puVar2 = (undefined1 *)FUN_2010510c(auStack_44,&DAT_20105534);
  if (puVar2 == (undefined1 *)0x0) {
    iVar1 = param_1[1];
    if (iVar1 == 0) goto LAB_20105468;
    puVar2 = auStack_44;
  }
  else {
    *puVar2 = 0;
    if (param_1[1] != 0) {
      FUN_201550dc(param_1[1],auStack_44);
    }
    iVar1 = param_1[2];
    if (iVar1 == 0) goto LAB_20105468;
    puVar2 = puVar2 + 1;
  }
  FUN_201550dc(iVar1,puVar2);
LAB_20105468:
  iVar1 = param_1[8];
  if (iVar1 != 0) {
    uVar3 = FUN_20156260(local_20,local_5c);
    uVar5 = (uint)((ulonglong)uVar3 * 0x91a2b3c5 >> 0x20);
    uVar6 = (uVar5 & 0x7ffff) >> 0xb;
    if (99 < uVar6) {
      uVar6 = 99;
    }
    uVar3 = uVar3 + (short)(ushort)(byte)((uVar5 << 0xd) >> 0x18) * -0xe10;
    uVar4 = ((uint)((ulonglong)uVar3 * 0x88888889 >> 0x20) & 0x1fff) >> 5;
    uVar5 = uVar4;
    if (0x3b < uVar4) {
      uVar5 = 0x3b;
    }
    uVar3 = uVar3 + uVar4 * -0x3c & 0xff;
    if (0x3b < uVar3) {
      uVar3 = 0x3b;
    }
    FUN_20154a30(iVar1,10,"%02d:%02d:%02d",uVar6,uVar5,uVar3);
  }
  return 0;
}

