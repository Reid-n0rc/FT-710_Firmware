// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013fde8 @ 2013fde8 (104 bytes)

undefined4 FUN_2013fde8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_e820152c;
  if (DAT_20808b70 == -1) {
    iVar2 = gic_def_inh(0x12f,&DAT_204205cc);
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


// ===== sdhi0_clock_on @ 2013fe50 (20 bytes)

/* STBCR12 &= 0xF3 */

void sdhi0_clock_on(void)

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
    uVar2 = sd_card_detect();
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
  sd_power(1);
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


// ===== FUN_201409ec @ 201409ec (316 bytes)

int FUN_201409ec(undefined4 param_1,int param_2,uint param_3,int param_4)

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
      iVar3 = FUN_201405e4(0x18,0,param_1,param_4);
      if (iVar3 == 0) {
LAB_20140a8c:
        if (2 < iVar2) {
          return -9;
        }
        FUN_201405f4(1,param_4);
        if ((*(uint *)(param_4 + 0x2b0) &
            *(uint *)(&DAT_2042024c + (uint)*(ushort *)(param_4 + 0x2c6) * 4)) == 0) {
          uVar4 = 0;
          if (param_3 != 0) {
            do {
              iVar2 = FUN_20140298(param_2);
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
        return -0x15;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    do {
      iVar3 = FUN_201405e4(0x19,0,param_1,param_4);
      if (iVar3 == 0) goto LAB_20140a8c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return -9;
}


// ===== FUN_20140b50 @ 20140b50 (24 bytes)

int FUN_20140b50(void)

{
  int iVar1;
  
  iVar1 = FUN_201409ec();
  if (iVar1 != 0) {
    FUN_201407bc();
  }
  return iVar1;
}


// ===== FUN_20140b68 @ 20140b68 (424 bytes)

int FUN_20140b68(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 unaff_r4;
  
  sdhi0_clock_on();
  FUN_20140440(2);
  iVar2 = FUN_2013fde8();
  if ((iVar2 == 0) && (iVar2 = sdhi_init(), iVar2 == 0)) {
    DAT_20808b82 = 0;
    DAT_20808b8e = 0;
    uVar3 = DAT_fcfe1000;
    DAT_fcfe1000 = uVar3 & 0xffffff00;
    uVar3 = DAT_fcfe1000;
    DAT_fcfe1000 = uVar3 | 0xc2;
    uVar3 = DAT_fcfe1000;
    DAT_fcfe1000 = uVar3 & 0xff00ffff;
    uVar3 = DAT_fcfe1000;
    DAT_fcfe1000 = uVar3 | 0xc10000;
    uVar3 = *(uint *)((int)&DAT_e8201400 + (DAT_20808b7c & 0xfffffffc));
    iVar2 = (DAT_20808b7c & 3) << 3;
    uVar4 = extraout_r3_00;
    if (DAT_20808b80 == -1) {
      iVar1 = gic_def_inh(DAT_20808b7c,DAT_20808b78,iVar2,extraout_r3_00,unaff_r4);
      if (iVar1 < 0) {
        return -1;
      }
      DAT_20808b80 = '\x01';
      uVar4 = extraout_r3;
    }
    *(uint *)((int)&DAT_e8201400 + (DAT_20808b7c & 0xfffffffc)) =
         uVar3 & ~(0xff << iVar2) | 7 << (DAT_20808b7c & 3) * 8 + 3;
    uVar3 = *(uint *)((int)&DAT_e8201400 + (DAT_20808b88 & 0xfffffffc));
    iVar2 = (DAT_20808b88 & 3) << 3;
    if (DAT_20808b8c == -1) {
      iVar1 = gic_def_inh(DAT_20808b88,DAT_20808b84,iVar2,uVar4,unaff_r4);
      if (iVar1 < 0) {
        return -1;
      }
      DAT_20808b8c = '\x01';
    }
    *(uint *)((int)&DAT_e8201400 + (DAT_20808b88 & 0xfffffffc)) =
         uVar3 & ~(0xff << iVar2) | 7 << (DAT_20808b88 & 3) * 8 + 3;
    uVar3 = DAT_e8200028;
    DAT_e8200028 = uVar3 | 8;
    uVar3 = DAT_e8200068;
    DAT_e8200068 = uVar3 | 8;
    FUN_2015686c();
    *(int *)(&DAT_e8201100 + (DAT_20808b7c >> 5) * 4) = 1 << (DAT_20808b7c & 0x1f);
    *(int *)(&DAT_e8201100 + (DAT_20808b88 >> 5) * 4) = 1 << (DAT_20808b88 & 0x1f);
    FUN_2015688c();
    return 0;
  }
  return iVar2;
}


// ===== FUN_20140b9c @ 20140b9c (76 bytes)

void FUN_20140b9c(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_e804e01e;
  if ((uVar1 & 0x100) == 0) {
    if ((uVar1 & 0x200) == 0) {
      return;
    }
    DAT_e804e01e = 0xfdff;
    uVar2 = 2;
  }
  else {
    DAT_e804e01e = 0xfeff;
    uVar2 = 1;
  }
  itron_set_flg(DAT_20808b74,uVar2);
  return;
}


// ===== FUN_20140be8 @ 20140be8 (940 bytes)

int FUN_20140be8(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_40;
  int local_3c;
  int local_38;
  int *piStack_34;
  uint uStack_30;
  int iStack_2c;
  undefined4 local_28;
  
  bVar1 = false;
  if (param_3 == 0) {
    if ((int)param_2 < 0) {
      return -0xd;
    }
    uVar6 = param_2;
    if ((uint)param_1[0xb] < param_2) {
      return -0xd;
    }
  }
  else {
    if (param_3 == 1) {
      if ((int)param_2 < 1) {
        if (((int)param_2 < 0) && ((uint)param_1[10] < -param_2)) {
          return -0xd;
        }
      }
      else if ((uint)(param_1[0xb] - param_1[10]) < param_2) {
        return -0xd;
      }
      iVar2 = param_1[10];
    }
    else {
      if (param_3 != 2) {
        return -0xe;
      }
      if (0 < (int)param_2) {
        return -0xd;
      }
      if (((int)param_2 < 0) && ((uint)param_1[0xb] < -param_2)) {
        return -0xd;
      }
      iVar2 = param_1[0xb];
    }
    uVar6 = iVar2 + param_2;
  }
  if (*(char *)((int)param_1 + 0x442) == '\0') {
    return -6;
  }
  if (param_1[10] == uVar6) {
    return 0;
  }
  iVar2 = *param_1;
  uVar8 = param_1[0x8e];
  piStack_34 = param_1;
  uStack_30 = param_2;
  iStack_2c = param_3;
  local_28 = param_4;
  uVar3 = FUN_20156260(uVar8,*(undefined4 *)(iVar2 + 0x6c));
  if (uVar8 <= (uint)param_1[5]) {
    iVar2 = FUN_201448b8(iVar2,param_1[8]);
    if (iVar2 == 0) {
      param_1[8] = (param_1[8] - uVar3) + 1;
    }
    if (param_1[2] != 0) {
      iVar2 = FUN_20144ac0(*param_1,param_1[8],param_1[1],uVar3 & 0xffff);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[2] = 0;
      *(undefined1 *)(param_1 + 0x113) = 1;
    }
    if ((uint)param_1[10] < (uint)param_1[0xb]) {
      iVar2 = FUN_20149f68(*param_1,(uVar3 - 1) + param_1[8],&local_40,local_28);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((local_40 != 0) &&
         (iVar2 = FUN_20144a10(*param_1,local_40,param_1[1],uVar3 & 0xffff), iVar2 != 0)) {
        return iVar2;
      }
      param_1[8] = local_40;
      param_1[5] = 0;
    }
  }
  local_38 = *param_1;
  local_3c = *(int *)(local_38 + 0x6c);
  iVar4 = FUN_20156260(uVar6,local_3c);
  uVar8 = param_1[10];
  iVar2 = FUN_20156260(uVar8,local_3c);
  iVar4 = iVar4 - iVar2;
  if ((iVar4 == 0) && (uVar8 != uVar6)) goto LAB_20140f18;
  local_3c = param_1[8];
  if (param_1[2] != 0) {
    iVar2 = FUN_20144ac0(local_38,local_3c,param_1[1],uVar3 & 0xffff);
    if (iVar2 != 0) {
      return iVar2;
    }
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 0x113) = 1;
  }
  if (iVar4 < 1) {
    iVar2 = *param_1;
    iVar4 = FUN_20156260(uVar6,*(undefined4 *)(iVar2 + 0x6c));
    iVar2 = FUN_20144980(iVar2,param_1[7]);
    param_1[8] = iVar2;
  }
  else {
    iVar2 = FUN_20156260(param_1[5],*(undefined4 *)(*param_1 + 0x6c));
    iVar2 = iVar2 + param_1[8];
  }
  iVar7 = 0;
  if (0 < iVar4) {
    do {
      iVar2 = FUN_20149f68(*param_1,iVar2,&local_40,local_28);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_40 == 0) {
        param_1[10] = param_1[0xb];
        param_1[5] = param_1[0x8e];
        if (param_1[0xb] != uVar6) {
          return -0xe;
        }
        iVar2 = param_1[8];
        bVar1 = false;
        break;
      }
      iVar7 = iVar7 + 1;
      bVar1 = true;
      param_1[8] = local_40;
      iVar2 = local_40;
    } while (iVar7 < iVar4);
  }
  if ((int)uVar3 < 2) {
LAB_20140ef0:
    iVar4 = FUN_20144a10(*param_1,iVar2,param_1[1],uVar3 & 0xffff);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
    uVar5 = FUN_201449cc(*param_1,iVar2);
    iVar2 = FUN_20144980(*param_1,uVar5);
    iVar4 = FUN_201449cc(*param_1,local_3c);
    iVar7 = FUN_201449cc(*param_1,iVar2);
    if (iVar4 != iVar7) goto LAB_20140ef0;
  }
  param_1[8] = iVar2;
LAB_20140f18:
  param_1[10] = uVar6;
  iVar2 = param_1[0x8e];
  FUN_20156260(uVar6);
  param_1[5] = extraout_r1;
  if ((((extraout_r1 == 0) && (param_1[0xb] == uVar6)) && (uVar6 != 0)) && (!bVar1)) {
    param_1[5] = iVar2;
  }
  return 0;
}


// ===== FUN_20140f94 @ 20140f94 (2180 bytes)

void FUN_20140f94(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_6c;
  undefined1 auStack_68 [11];
  byte local_5d;
  undefined1 auStack_52 [2];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38 [2];
  char *local_30;
  char *pcStack_2c;
  char *pcStack_28;
  
  piVar7 = DAT_20808b90;
  bVar2 = false;
  local_3c = 0;
  local_38[0] = 0;
  iVar9 = 0;
  local_40 = 0;
  piVar10 = (int *)0x0;
  local_44 = 0;
  local_48 = DAT_20808ba0;
  local_30 = param_1;
  pcStack_2c = param_2;
  pcStack_28 = param_3;
  iVar5 = FUN_2014de30();
  if (iVar5 != 0) {
    iVar5 = -0x28;
    piVar7 = (int *)0x0;
    goto LAB_20141070;
  }
  iVar5 = 0;
  if (0 < DAT_20808b94) {
    do {
      piVar11 = piVar7 + 0x100;
      if (*(char *)((int)piVar7 + 0x442) == '\0' && !bVar2) {
        bVar2 = true;
        piVar10 = piVar7;
      }
      else {
        iVar6 = FUN_20147774(piVar7 + 0x8f,local_30);
        if ((iVar6 == 0) &&
           ((*param_2 != 'r' || ((param_2[1] == '+' && (*(char *)((int)piVar11 + 0x42) != '\x01'))))
           )) {
          FUN_2014de5c();
          piVar7 = (int *)0x0;
          iVar5 = -7;
          goto LAB_20141070;
        }
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 0x114;
    } while (iVar5 < DAT_20808b94);
    if (bVar2) {
      if (piVar10 == (int *)0x0) {
        FUN_2014de5c();
        piVar7 = (int *)0x0;
        iVar5 = -0xd;
        goto LAB_20141070;
      }
      uVar3 = FUN_2014d35c((int)*local_30);
      iVar5 = FUN_20144918(uVar3,&local_48);
      if (iVar5 != 0) {
        FUN_2014de5c();
        piVar7 = (int *)0x0;
        goto LAB_20141070;
      }
      FUN_2014d148(piVar10,0,0x450,*(undefined4 *)(local_48 + 0x6c));
      *(undefined1 *)((int)piVar10 + 0x442) = 0xff;
      FUN_2014de5c();
      iVar5 = FUN_20144950(local_48);
      if ((iVar5 != 0) ||
         (((*param_2 != 'r' || (param_2[1] == '+')) && (iVar5 = FUN_20144970(local_48), iVar5 != 0))
         )) goto LAB_20141154;
      iVar5 = 0;
      FUN_2014d148(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
      *piVar10 = local_48;
      pcVar8 = local_30 + 2;
      local_6c = *(int *)(local_48 + 0x34);
      if (*(char *)(local_48 + 0x10) == ' ') {
LAB_201412a0:
        cVar1 = *pcVar8;
        while (cVar1 != '\0') {
          pcVar8 = (char *)FUN_20147248(pcVar8,param_3);
          if ((pcVar8 == (char *)0x0) || (*param_3 == '\0')) goto LAB_20141208;
          iVar5 = FUN_201468c0(local_48,local_6c,param_3,auStack_68,0,0,&local_40,&local_44,param_3)
          ;
          if (*pcVar8 == '\0') {
            if ((iVar5 == 0) && (iVar9 = FUN_201476f0((int)(char)local_5d,0x10), iVar9 == 0)) {
              cVar1 = *param_2;
              goto joined_r0x2014124c;
            }
            if ((*param_2 == 'r') && (iVar5 != 0)) goto LAB_2014125c;
          }
          else {
            if (iVar5 != 0) goto LAB_2014146c;
            iVar9 = FUN_201476f0((int)(char)local_5d,0x10);
            if (iVar9 != 0) goto LAB_201411f8;
          }
          iVar6 = FUN_20146884(auStack_68,(int)*(char *)(local_48 + 0x10));
          iVar9 = local_6c;
          local_6c = iVar6;
          cVar1 = *pcVar8;
        }
      }
      else {
        pcVar8 = (char *)FUN_20147248(pcVar8,param_3);
        if ((pcVar8 == (char *)0x0) || (*param_3 == '\0')) {
LAB_20141208:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          piVar7 = (int *)0x0;
          iVar5 = -1;
          goto LAB_20141070;
        }
        iVar5 = FUN_20145df0(local_48,param_3,auStack_68,0,0,&local_40,param_3);
        if (*pcVar8 == '\0') {
          if ((iVar5 == 0) && (iVar6 = FUN_201476f0((int)(char)local_5d,0x10), iVar6 == 0)) {
            cVar1 = *param_2;
joined_r0x2014124c:
            if (cVar1 != 'r') {
              piVar7 = (int *)0x0;
              *(undefined1 *)((int)piVar10 + 0x442) = 0;
              iVar5 = -2;
              goto LAB_20141070;
            }
          }
          else if ((*param_2 != 'r') || (iVar5 == 0)) goto LAB_20141280;
LAB_2014125c:
          piVar7 = (int *)0x0;
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          iVar5 = -3;
          goto LAB_20141070;
        }
        if ((iVar5 != 0) || (iVar6 = FUN_201476f0((int)(char)local_5d,0x10), iVar6 != 0)) {
LAB_201411f8:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          iVar5 = -4;
          piVar7 = (int *)0x0;
          goto LAB_20141070;
        }
LAB_20141280:
        if (*pcVar8 != '\0') {
          local_6c = FUN_20146884(auStack_68,(int)*(char *)(local_48 + 0x10));
          goto LAB_201412a0;
        }
      }
      cVar1 = *param_2;
      if (cVar1 == 'a') {
        if (iVar5 != 0) {
          FUN_2014d148(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
          local_5d = 0x20;
          FUN_201474a4(auStack_68,piVar10,7);
          if (iVar9 == 0) {
            iVar5 = FUN_20145df0(local_48,param_3,auStack_68,1,0,&local_40,param_3);
            iVar6 = FUN_20144980(local_48,0);
          }
          else {
            iVar5 = FUN_201468c0(local_48,iVar9,param_3,auStack_68,1,0,&local_40,&local_44,param_3);
            iVar6 = local_44;
          }
          piVar10[9] = iVar6;
          if (iVar5 != 0) {
LAB_2014146c:
            *(undefined1 *)((int)piVar10 + 0x442) = 0;
            piVar7 = (int *)0x0;
            goto LAB_20141070;
          }
        }
        if ((local_5d & 1) == 0) {
          *(undefined1 *)((int)piVar10 + 0x442) = 0x20;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x21;
          }
          *(byte *)((int)piVar10 + 0x443) = local_5d;
          uVar4 = FUN_2014d900(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = FUN_2014d900(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
          iVar5 = FUN_2014d93c(auStack_4c);
          piVar10[0xb] = iVar5;
          piVar10[0xc] = iVar5;
          iVar5 = FUN_20146884(auStack_68,(int)*(char *)(local_48 + 0x10));
          piVar10[7] = iVar5;
          iVar5 = FUN_20144980(local_48,iVar5);
          piVar10[8] = iVar5;
          piVar10[6] = local_40;
          if (iVar9 == 0) {
            iVar9 = FUN_20144980(local_48,0);
          }
          else {
            *(undefined1 *)(piVar10 + 0x111) = 1;
            iVar9 = local_44;
          }
          piVar10[9] = iVar9;
LAB_201417fc:
          FUN_2014d288(piVar10 + 0x8f,local_30,0x102);
          iVar5 = 0;
          piVar7 = piVar10;
          goto LAB_20141070;
        }
      }
      else if (cVar1 == 'r') {
        if (((local_5d & 1) == 0) || (param_2[1] != '+')) {
          piVar10[6] = local_40;
          if (iVar9 == 0) {
            iVar9 = FUN_20144980(local_48,0);
          }
          else {
            *(undefined1 *)(piVar10 + 0x111) = 1;
            iVar9 = local_44;
          }
          piVar10[9] = iVar9;
          *(undefined1 *)((int)piVar10 + 0x442) = 1;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x11;
          }
          iVar9 = FUN_2014d93c(auStack_4c);
          piVar10[0xb] = iVar9;
          piVar10[0xc] = iVar9;
          iVar9 = FUN_20146884(auStack_68,(int)*(char *)(local_48 + 0x10));
          piVar10[7] = iVar9;
          iVar9 = FUN_20144980(local_48,iVar9);
          piVar10[8] = iVar9;
          *(byte *)((int)piVar10 + 0x443) = local_5d;
          uVar4 = FUN_2014d900(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = FUN_2014d900(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
          goto LAB_201417fc;
        }
      }
      else if (cVar1 == 'w') {
        if (iVar5 != 0) {
LAB_20141700:
          FUN_2014d148(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
          local_5d = 0x20;
          FUN_201474a4(auStack_68,piVar10,7);
          if (iVar9 == 0) {
            iVar5 = FUN_20145df0(local_48,param_3,auStack_68,1,0,&local_40,param_3);
            iVar6 = FUN_20144980(local_48,0);
          }
          else {
            iVar5 = FUN_201468c0(local_48,iVar9,param_3,auStack_68,1,0,&local_40,&local_44,param_3);
            iVar6 = local_44;
          }
          piVar10[9] = iVar6;
          if (iVar5 != 0) goto LAB_2014146c;
          *(undefined1 *)((int)piVar10 + 0x442) = 0x10;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x11;
          }
          piVar10[6] = local_40;
          *(byte *)((int)piVar10 + 0x443) = local_5d;
          uVar4 = FUN_2014d900(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = FUN_2014d900(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
          piVar10[7] = 0;
          if (iVar9 != 0) {
            *(undefined1 *)(piVar10 + 0x111) = 1;
          }
          goto LAB_201417fc;
        }
        if ((local_5d & 1) == 0) {
          if (iVar9 == 0) {
            iVar5 = FUN_20145df0(local_48,param_3,auStack_68,3,0,&local_3c,param_3);
          }
          else {
            iVar5 = FUN_201468c0(local_48,iVar9,param_3,auStack_68,3,0,&local_3c,local_38,param_3);
          }
          if (iVar5 == 0) {
            if (iVar9 == 0) {
              iVar5 = FUN_20145df0(local_48,param_3,auStack_68,2,0,&local_40,param_3);
            }
            else {
              iVar5 = FUN_201468c0(local_48,iVar9,param_3,auStack_68,2,0,&local_40,&local_44,param_3
                                  );
            }
            if ((iVar5 == 0) &&
               ((iVar5 = FUN_20146884(auStack_68,(int)*(char *)(local_48 + 0x10)), iVar5 == 0 ||
                (iVar5 = FUN_20149788(local_48,iVar5,param_3), iVar5 == 0)))) goto LAB_20141700;
          }
LAB_20141154:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          piVar7 = (int *)0x0;
          goto LAB_20141070;
        }
      }
      *(undefined1 *)((int)piVar10 + 0x442) = 0;
      iVar5 = -5;
      piVar7 = (int *)0x0;
      goto LAB_20141070;
    }
  }
  FUN_2014de5c();
  piVar7 = (int *)0x0;
  iVar5 = -10;
LAB_20141070:
  FUN_2014485c(iVar5,piVar7);
  return;
}


// ===== FUN_20141824 @ 20141824 (148 bytes)

void FUN_20141824(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  uVar1 = FUN_2014d35c((int)*param_1);
  iVar2 = FUN_20144918(uVar1,&local_18);
  if (iVar2 != 0) {
    FUN_2014485c(iVar2,0);
    return;
  }
  iVar2 = FUN_2014d9c0(local_18);
  if (iVar2 == 0) {
    uVar4 = FUN_20140f94(param_1,param_2,param_3);
    uVar3 = FUN_2014d95c();
    FUN_2014da64(local_18);
  }
  else {
    uVar4 = 0;
    uVar3 = 0xffffffdb;
  }
  FUN_2014485c(uVar3,uVar4);
  return;
}


// ===== FUN_201418b8 @ 201418b8 (516 bytes)

void FUN_201418b8(char *param_1,char *param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_20;
  
  local_20 = DAT_20808ba0;
  iVar3 = FUN_2014a4a4();
  if (iVar3 != 0) {
    FUN_2014485c(iVar3,0);
    return;
  }
  if (param_1 == (char *)0x0 || param_2 == (char *)0x0) {
    piVar5 = (int *)0x0;
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_201473c4(param_1);
    if (iVar3 == 0) {
      uVar1 = FUN_2014d35c((int)*param_1);
      iVar3 = FUN_20144918(uVar1,&local_20);
      if (iVar3 == 0) {
        iVar3 = FUN_2014d220(param_1);
        iVar4 = param_3 + 0x100c;
        FUN_2014d288(iVar4,param_1,iVar3 + 1);
        FUN_2014cd68(iVar4);
        piVar5 = (int *)FUN_20141824(iVar4,param_2,param_3);
        iVar3 = FUN_2014d95c();
        if (piVar5 != (int *)0x0) {
          iVar4 = FUN_2014e06c((uint)*(ushort *)(*piVar5 + 4) * *(int *)(*piVar5 + 0x6c));
          piVar5[1] = iVar4;
          iVar6 = *piVar5;
          piVar5[0x8e] = (uint)*(ushort *)(iVar6 + 4) * *(int *)(iVar6 + 0x6c);
          if (iVar4 == 0) {
            piVar5[1] = (int)(piVar5 + 0xd);
            piVar5[0x8e] = *(int *)(iVar6 + 0x6c);
          }
          if ((*param_2 == 'r' || *param_2 == 'a') && (piVar5[0xb] != 0)) {
            uVar2 = FUN_20156260(piVar5[0x8e],*(undefined4 *)(iVar6 + 0x6c));
            iVar4 = FUN_20144a10(iVar6,piVar5[8],piVar5[1],uVar2);
            if (iVar4 != 0) {
              if ((int *)piVar5[1] != piVar5 + 0xd) {
                FUN_2014e0ac();
              }
              FUN_2014d148(piVar5 + 0x8f,0,0x206,*(undefined4 *)(*piVar5 + 0x6c));
              *(undefined1 *)((int)piVar5 + 0x442) = 0;
              piVar5 = (int *)0x0;
              iVar3 = iVar4;
            }
            if (((*param_2 == 'a') && (piVar5 != (int *)0x0)) &&
               (iVar4 = FUN_20140be8(piVar5,0,2,param_3), iVar4 != 0)) {
              if ((int *)piVar5[1] != piVar5 + 0xd) {
                FUN_2014e0ac();
              }
              FUN_2014d148(piVar5 + 0x8f,0,0x206,*(undefined4 *)(*piVar5 + 0x6c));
              *(undefined1 *)((int)piVar5 + 0x442) = 0;
              piVar5 = (int *)0x0;
              iVar3 = iVar4;
            }
          }
        }
        goto LAB_20141914;
      }
    }
    piVar5 = (int *)0x0;
  }
LAB_20141914:
  FUN_2014485c(iVar3,piVar5);
  return;
}

