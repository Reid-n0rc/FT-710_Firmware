// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013faf4 @ 2013faf4 (152 bytes)

int FUN_2013faf4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    return -1;
  }
  iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
  if (iVar1 == 0) {
    uVar2 = (uint)*(char *)((&DAT_20808b60)[param_1] + 0x68);
    if ((uVar2 & 0x40) != 0) {
      iVar1 = 1;
      if ((uVar2 & 0x80) != 0) {
        return 1;
      }
      FUN_201446d0((&DAT_20808b60)[param_1]);
      iVar3 = FUN_2014a9d4((&DAT_20808b60)[param_1]);
      goto joined_r0x2013fb7c;
    }
  }
  iVar1 = 0;
  if ((*(byte *)((&DAT_20808b60)[param_1] + 0x68) & 0x80) == 0) {
    return 0;
  }
  iVar3 = FUN_2014aaf0();
joined_r0x2013fb7c:
  if (iVar3 != 0) {
    iVar1 = iVar3;
  }
  return iVar1;
}


// ===== FUN_2013fb8c @ 2013fb8c (20 bytes)

void FUN_2013fb8c(undefined4 param_1)

{
  DAT_20808b64 = param_1;
  DAT_20808b68 = 0;
  return;
}


// ===== FUN_2013fba0 @ 2013fba0 (112 bytes)

int FUN_2013fba0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_20808b64 != 0) && (DAT_20808b68 == 0)) {
    FUN_2014e884(0,6);
    uVar1 = FUN_20132f6c();
    iVar2 = FUN_2014a304(0x49,uVar1,0x20000);
    FUN_2014e884(0);
    if (iVar2 == 0) {
      DAT_20808b68 = 1;
    }
    return iVar2;
  }
  return 0;
}


// ===== FUN_2013fc14 @ 2013fc14 (56 bytes)

void FUN_2013fc14(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = *(undefined4 *)(param_3 + 0x1c);
  uStack_c = *(undefined4 *)(param_3 + 0x20);
  local_8 = *(undefined4 *)(param_3 + 0x24);
  DAT_20808b6c = FUN_2014fd24(0,&local_10);
  return;
}


// ===== FUN_2013fc4c @ 2013fc4c (28 bytes)

void FUN_2013fc4c(int param_1)

{
  if (param_1 != 0) {
    FUN_20151c3c(DAT_20808b6c,0xffffffff);
    return;
  }
  FUN_20152df4(DAT_20808b6c);
  return;
}


// ===== FUN_2013fc68 @ 2013fc68 (212 bytes)

uint FUN_2013fc68(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
    if ((iVar1 == 0) && (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x40U) != 0)) {
      if ((param_2 & 0x40) == 0) {
        if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) == 0) {
          FUN_20151c3c(DAT_20808b6c,0xffffffff);
          FUN_201446d0((&DAT_20808b60)[param_1]);
          iVar1 = FUN_2014a9d4((&DAT_20808b60)[param_1]);
          FUN_20152df4(DAT_20808b6c);
          if (iVar1 != 0) {
            return 0x40;
          }
          FUN_2013fb8c(1);
        }
        param_2 = 0xc0;
      }
    }
    else {
      param_2 = (int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0xffffff3f;
      if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) != 0) {
        FUN_2013fb8c(0);
        iVar1 = FUN_2014aaf0((&DAT_20808b60)[param_1]);
        if (iVar1 == 0) {
          param_2 = 0;
        }
      }
    }
  }
  return param_2;
}


// ===== FUN_2013fd3c @ 2013fd3c (20 bytes)

void FUN_2013fd3c(int param_1)

{
  itron_dly_tsk(param_1 / 10);
  return;
}


// ===== FUN_2013fd98 @ 2013fd98 (60 bytes)

void FUN_2013fd98(void)

{
  DAT_2091cba8 = 0;
  DAT_20808b44 = &DAT_2091cba8;
  DAT_20808b48 = &PTR_FUN_20420564;
  FUN_2013e71c();
  return;
}


// ===== FUN_2013fde8 @ 2013fde8 (104 bytes)

undefined4 FUN_2013fde8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_e820152c;
  if (DAT_20808b70 == -1) {
    iVar2 = FUN_2011762c(0x12f,&DAT_204205cc);
    if (iVar2 < 0) {
      return 0xffffffff;
    }
    DAT_20808b70 = 1;
  }
  DAT_e820152c = uVar1 & 0xffffff | 0x38000000;
  FUN_2015686c();
  DAT_e8201124 = 0x8000;
  FUN_2015688c();
  return 0;
}


// ===== FUN_2013fe50 @ 2013fe50 (20 bytes)

void FUN_2013fe50(void)

{
  byte bVar1;
  
  bVar1 = DAT_fcfe0444;
  DAT_fcfe0444 = bVar1 & 0xf3;
  return;
}


// ===== FUN_2013ffec @ 2013ffec (68 bytes)

void FUN_2013ffec(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  DAT_e8200000 = param_2;
  DAT_e8200004 = param_1;
  DAT_e8200008 = 0x200;
  DAT_e820002c = 0x126260;
  DAT_e8200030 = 0;
  DAT_e8200034 = 0;
  uVar1 = DAT_e8200028;
  DAT_e8200028 = uVar1 | 8;
  uVar1 = DAT_e8200028;
  DAT_e8200028 = uVar1 | 1;
  return;
}


// ===== FUN_20140030 @ 20140030 (48 bytes)

void FUN_20140030(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = DAT_e8200024;
    if ((uVar1 & 5) == 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x900000);
  uVar2 = DAT_e8200028;
  DAT_e8200028 = uVar2 | 8;
  return;
}


// ===== FUN_20140060 @ 20140060 (68 bytes)

void FUN_20140060(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  DAT_e8200040 = param_2;
  DAT_e8200044 = param_1;
  DAT_e8200048 = 0x200;
  DAT_e820006c = 0x262269;
  DAT_e8200070 = 0;
  DAT_e8200074 = 0;
  uVar1 = DAT_e8200068;
  DAT_e8200068 = uVar1 | 8;
  uVar1 = DAT_e8200068;
  DAT_e8200068 = uVar1 | 1;
  return;
}


// ===== FUN_201400a4 @ 201400a4 (48 bytes)

void FUN_201400a4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = DAT_e8200064;
    if ((uVar1 & 5) == 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x900000);
  uVar2 = DAT_e8200068;
  DAT_e8200068 = uVar2 | 8;
  return;
}


// ===== sdhi_init @ 201400d4 (60 bytes)

/* SDINT_INI */

undefined4 sdhi_init(void)

{
  int iVar1;
  
  iVar1 = DAT_20808b74;
  if ((DAT_20808b74 == 0) && (iVar1 = FUN_2014e5e4(&DAT_204205d8,"SDINT_INI"), iVar1 < 1)) {
    return 0xffffffff;
  }
  DAT_20808b74 = iVar1;
  return 0;
}


// ===== FUN_20140158 @ 20140158 (84 bytes)

undefined4 FUN_20140158(uint param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_14 [4];
  
  uVar1 = itron_twai_flg(DAT_20808b74,param_1,0,auStack_14,param_2 / 10);
  FUN_2014eb94(DAT_20808b74,~param_1);
  return uVar1;
}


// ===== FUN_201401ac @ 201401ac (48 bytes)

bool FUN_201401ac(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = 0;
  do {
    uVar2 = FUN_20101d94();
    uVar3 = uVar3 + 1;
    uVar1 = uVar2 | uVar1 << 1;
  } while (uVar3 < 0x20);
  return uVar1 != 0;
}


// ===== FUN_201401dc @ 201401dc (44 bytes)

bool FUN_201401dc(void)

{
  ushort uVar1;
  
  uVar1 = DAT_e804e01c;
  return (uVar1 & 0x80) == 0;
}


// ===== FUN_20140210 @ 20140210 (136 bytes)

undefined4 FUN_20140210(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  bool bVar4;
  
  DAT_e804e0f0 = 0x100;
  puVar3 = param_1;
  if (((uint)param_1 & 0x1f) != 0) {
    puVar3 = &DAT_2091cec0;
  }
  thunk_FUN_20101088(puVar3,0x200);
  FUN_2013ffec(puVar3,&DAT_e804e000);
  iVar1 = FUN_20140158(4,500);
  FUN_20140030();
  thunk_FUN_20101088(puVar3,0x200);
  if (iVar1 == 0) {
    if (((uint)param_1 & 0x1f) != 0) {
      iVar1 = 0x1ff;
      do {
        bVar4 = iVar1 != 0;
        iVar1 = iVar1 + -1;
        *param_1 = *puVar3;
        param_1 = param_1 + 1;
        puVar3 = puVar3 + 1;
      } while (bVar4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff1;
  }
  return uVar2;
}


// ===== FUN_20140298 @ 20140298 (116 bytes)

undefined4 FUN_20140298(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  DAT_e804e0f0 = 0x100;
  if (((uint)param_1 & 0x1f) != 0) {
    iVar2 = 0x1ff;
    puVar1 = &DAT_2091cec0;
    do {
      bVar4 = iVar2 != 0;
      iVar2 = iVar2 + -1;
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    } while (bVar4);
    param_1 = &DAT_2091cec0;
  }
  thunk_FUN_20101030(param_1,0x200);
  FUN_20140060(&DAT_e804e000,param_1);
  iVar2 = FUN_20140158(4,500);
  FUN_201400a4();
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


// ===== FUN_2014030c @ 2014030c (36 bytes)

void FUN_2014030c(void)

{
  itron_set_flg(DAT_20808b74,4);
  return;
}


// ===== FUN_20140320 @ 20140320 (20 bytes)

undefined4 FUN_20140320(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_201401ac();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}


// ===== FUN_20140334 @ 20140334 (164 bytes)

int FUN_20140334(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  while ((uVar1 = DAT_e804e01e, (uVar1 & 0x4000) != 0 || ((uVar1 & 0x2000) == 0))) {
    if ((uVar1 & 0x807f) != 0) {
      return -9;
    }
    iVar3 = FUN_20140320();
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar4 = uVar4 + 1;
    if (0x8fffff < uVar4) {
      return -1;
    }
  }
  if (0x8fffff < uVar4) {
    return -1;
  }
  if (param_1 != -1) {
    if (param_1 == 0) {
      uVar2 = 0x140;
      goto LAB_201403cc;
    }
    if (param_1 != 1) {
      if (param_1 != 2) {
        return -8;
      }
      uVar2 = 0x100;
      goto LAB_201403cc;
    }
  }
  uVar2 = 0x101;
LAB_201403cc:
  DAT_e804e024 = uVar2;
  return 0;
}


// ===== FUN_201403d8 @ 201403d8 (16 bytes)

void FUN_201403d8(void)

{
  DAT_e804e024 = 0x200;
  return;
}


// ===== FUN_201403e8 @ 201403e8 (12 bytes)

void FUN_201403e8(undefined2 param_1)

{
  DAT_e804e026 = param_1;
  return;
}


// ===== FUN_201403f4 @ 201403f4 (12 bytes)

void FUN_201403f4(undefined2 param_1)

{
  DAT_e804e00a = param_1;
  return;
}


// ===== FUN_20140400 @ 20140400 (12 bytes)

void FUN_20140400(undefined2 param_1)

{
  DAT_e804e008 = param_1;
  return;
}


// ===== FUN_2014040c @ 2014040c (20 bytes)

undefined4 FUN_2014040c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_201401dc();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}


// ===== FUN_20140420 @ 20140420 (8 bytes)

undefined4 FUN_20140420(void)

{
  return 0xfffffff7;
}


// ===== FUN_20140428 @ 20140428 (8 bytes)

undefined4 FUN_20140428(void)

{
  return 0xfffffff6;
}


// ===== FUN_20140430 @ 20140430 (8 bytes)

undefined4 FUN_20140430(void)

{
  return 4;
}


// ===== FUN_20140438 @ 20140438 (8 bytes)

undefined4 FUN_20140438(void)

{
  return 5;
}


// ===== FUN_20140440 @ 20140440 (28 bytes)

undefined4 FUN_20140440(void)

{
  DAT_e804e0e0 = 0;
  DAT_e804e0e0 = 1;
  return 0;
}


// ===== FUN_2014045c @ 2014045c (20 bytes)

undefined4 FUN_2014045c(void)

{
  FUN_20101d70(1);
  return 0;
}


// ===== FUN_20140474 @ 20140474 (24 bytes)

void FUN_20140474(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 2) {
    uVar1 = 0x40ee;
  }
  else {
    uVar1 = 0xc0ee;
  }
  DAT_e804e028 = uVar1;
  return;
}


// ===== FUN_2014048c @ 2014048c (4 bytes)

void FUN_2014048c(void)

{
  return;
}


// ===== FUN_20140490 @ 20140490 (4 bytes)

void FUN_20140490(void)

{
  return;
}


// ===== FUN_20140494 @ 20140494 (4 bytes)

void FUN_20140494(void)

{
  return;
}


// ===== FUN_20140498 @ 20140498 (4 bytes)

void FUN_20140498(void)

{
  return;
}


// ===== FUN_2014049c @ 2014049c (8 bytes)

undefined4 FUN_2014049c(void)

{
  return 0xfffffff7;
}


// ===== FUN_201404a4 @ 201404a4 (148 bytes)

int FUN_201404a4(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort uVar4;
  uint uVar5;
  
  puVar3 = &DAT_e804e01c;
  if (param_1 == 1) {
    uVar4 = 1;
  }
  else if (param_1 == 2) {
    uVar4 = 4;
  }
  else {
    puVar3 = &DAT_e804e01e;
    if (param_1 == 3) {
      uVar4 = 0x200;
    }
    else {
      if (param_1 != 4) {
        return -2;
      }
      uVar4 = 0x100;
    }
  }
  uVar5 = 0;
  do {
    if ((uVar4 & ~*puVar3) == 0) {
      *puVar3 = ~uVar4;
      return 0;
    }
    uVar1 = DAT_e804e01e;
    if ((uVar1 & 0x48) != 0) {
      return -1;
    }
    iVar2 = FUN_20140320();
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x900000);
  return -1;
}


// ===== FUN_20140538 @ 20140538 (136 bytes)

undefined4 FUN_20140538(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_e804e01c;
  DAT_e804e01c = uVar1 & 0xfff8;
  uVar1 = DAT_e804e01e;
  DAT_e804e01e = uVar1 & 0x800;
  DAT_e804e006 = (short)((uint)param_3 >> 0x10);
  DAT_e804e004 = (short)param_3;
  uVar1 = DAT_e804e01e;
  if ((uVar1 & 0x4000) == 0) {
    if (param_2 == 0) {
      if (param_1 == 7) {
        if (param_3 == 0) {
          uVar2 = 0x307;
        }
        else {
          uVar2 = 0x507;
        }
      }
      else {
        uVar2 = *(undefined2 *)(&UNK_204205fc + param_1 * 2);
      }
    }
    else {
      uVar2 = *(undefined2 *)(&DAT_2042067c + param_1 * 2);
    }
    DAT_e804e000 = uVar2;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffff7;
  }
  return uVar3;
}


// ===== FUN_201405e4 @ 201405e4 (52 bytes)

uint FUN_201405e4(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  FUN_20140538();
  iVar2 = FUN_201404a4(1);
  if (iVar2 == 0) {
    uVar1 = DAT_e804e01e;
    uVar3 = uVar1 & 0xffff807f;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== FUN_201405f4 @ 201405f4 (192 bytes)

void FUN_201405f4(int param_1,int param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 + 0x2b0);
  if ((param_1 != 1 && param_1 != 6) && (param_1 != 7 && param_1 != 3)) {
    uVar1 = DAT_e804e01a;
    *(char *)piVar3 = (char)uVar1;
    uVar1 = DAT_e804e018;
    *(char *)(param_2 + 0x2b1) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b2) = (char)uVar1;
    uVar1 = DAT_e804e016;
    *(char *)(param_2 + 0x2b3) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b4) = (char)uVar1;
    uVar1 = DAT_e804e014;
    *(char *)(param_2 + 0x2b5) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b6) = (char)uVar1;
    uVar1 = DAT_e804e012;
    *(char *)(param_2 + 0x2b7) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b8) = (char)uVar1;
    uVar1 = DAT_e804e010;
    *(char *)(param_2 + 0x2b9) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2ba) = (char)uVar1;
    uVar1 = DAT_e804e00e;
    *(char *)(param_2 + 699) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 700) = (char)uVar1;
    uVar1 = DAT_e804e00c;
    *(char *)(param_2 + 0x2bd) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2be) = (char)uVar1;
    return;
  }
  *piVar3 = 0;
  uVar2 = DAT_e804e00e;
  *piVar3 = (uint)uVar2 << 0x10;
  uVar1 = DAT_e804e00c;
  *piVar3 = CONCAT22(uVar2,uVar1);
  return;
}


// ===== FUN_201406b4 @ 201406b4 (152 bytes)

undefined4 FUN_201406b4(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_201403e8();
  FUN_201403f4(param_2);
  if (param_2 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  FUN_20140400(uVar1);
  iVar3 = 0;
  do {
    iVar2 = FUN_201405e4(0x10,0,param_1,param_3);
    if (iVar2 == 0) {
      if (2 < iVar3) {
        return 0xfffffff7;
      }
      FUN_201405f4(1,param_3);
      uVar1 = 0;
      if ((*(uint *)(param_3 + 0x2b0) &
          *(uint *)(&DAT_2042023c + (uint)*(ushort *)(param_3 + 0x2c6) * 4)) != 0) {
        uVar1 = 0xffffffe9;
      }
      return uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0xfffffff7;
}


// ===== FUN_2014074c @ 2014074c (112 bytes)

undefined4 FUN_2014074c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (iVar1 = FUN_201405e4(0xc,0,0,param_1), iVar1 != 0) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xfffffff7;
    }
  }
  if (2 < iVar2) {
    return 0xfffffff7;
  }
  FUN_201405f4(1,param_1);
  if ((*(uint *)(param_1 + 0x2b0) &
      *(uint *)(&DAT_20420234 + (uint)*(ushort *)(param_1 + 0x2c6) * 4)) != 0) {
    return 0xfffffff7;
  }
  return 0;
}


// ===== FUN_201407bc @ 201407bc (36 bytes)

void FUN_201407bc(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int extraout_r2;
  undefined2 extraout_r3;
  undefined2 extraout_r12;
  
  uVar1 = DAT_e804e024;
  FUN_20140440(2,param_2,&DAT_e804e000,uVar1);
  *(undefined2 *)(extraout_r2 + 0x24) = extraout_r3;
  *(undefined2 *)(extraout_r2 + 0x28) = extraout_r12;
  return;
}


// ===== FUN_201407e0 @ 201407e0 (316 bytes)

int FUN_201407e0(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_201406b4(0x200,param_3,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = DAT_e804e0d8;
  DAT_e804e0d8 = uVar1 | 2;
  iVar2 = 0;
  if (param_3 == 1) {
    do {
      iVar3 = FUN_201405e4(0x11,0,param_1,param_4);
      if (iVar3 == 0) {
LAB_20140880:
        if (2 < iVar2) {
          return -9;
        }
        FUN_201405f4(1,param_4);
        if ((*(uint *)(param_4 + 0x2b0) &
            *(uint *)(&DAT_20420244 + (uint)*(ushort *)(param_4 + 0x2c6) * 4)) == 0) {
          uVar4 = 0;
          if (param_3 != 0) {
            do {
              iVar2 = FUN_20140210(param_2);
              if (iVar2 != 0) {
                uVar1 = DAT_e804e0d8;
                DAT_e804e0d8 = uVar1 & 0xfffd;
                return iVar2;
              }
              param_2 = param_2 + 0x200;
              uVar4 = uVar4 + 1 & 0xffff;
            } while (uVar4 < param_3);
          }
          uVar1 = DAT_e804e0d8;
          DAT_e804e0d8 = uVar1 & 0xfffd;
          iVar3 = FUN_201404a4(2);
          iVar2 = 0;
          if (iVar3 != 0) {
            iVar2 = -1;
          }
          return iVar2;
        }
        return -0x16;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    do {
      iVar3 = FUN_201405e4(0x12,0,param_1,param_4);
      if (iVar3 == 0) goto LAB_20140880;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return -9;
}


// ===== FUN_2014091c @ 2014091c (124 bytes)

int FUN_2014091c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_3 == 2) {
    iVar1 = FUN_201407e0(param_1,param_2,1);
    if (iVar1 != 0) {
      FUN_201407bc();
      return iVar1;
    }
    if (*(short *)(param_4 + 0x2c0) == 2) {
      param_1 = param_1 + 1;
    }
    else {
      param_1 = param_1 + 0x200;
    }
    iVar1 = FUN_201407e0(param_1,param_2 + 0x200,1,param_4);
  }
  else {
    iVar1 = FUN_201407e0();
  }
  if (iVar1 != 0) {
    FUN_201407bc();
  }
  return iVar1;
}


// ===== FUN_20140998 @ 20140998 (84 bytes)

undefined4 FUN_20140998(undefined1 *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 >> 2 != 0) {
    do {
      uVar1 = DAT_e804e030;
      iVar2 = iVar2 + 1;
      *param_1 = (char)uVar1;
      param_1[1] = (char)((uint)uVar1 >> 8);
      param_1[2] = (char)((uint)uVar1 >> 0x10);
      param_1[3] = (char)((uint)uVar1 >> 0x18);
      param_1 = param_1 + 4;
    } while (iVar2 < (int)(param_2 >> 2));
  }
  return 0;
}

