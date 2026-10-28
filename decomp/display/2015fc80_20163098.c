// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2015fc80 @ 2015fc80 (64 bytes)

undefined2 FUN_2015fc80(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (uint)DAT_208f0bc3 + (int)-*(short *)(param_4 + 0x22);
  if (-*(short *)(param_4 + 0x22) < 0) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else if (param_3 <= iVar1) {
    iVar1 = param_3 + -1;
  }
  return *(undefined2 *)(param_2 + iVar1 * 2);
}


// ===== FUN_2015fcc4 @ 2015fcc4 (148 bytes)

void FUN_2015fcc4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_201644e4();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x28;
    FUN_201587d0(iVar3 + 4);
    FUN_20164524(param_1 + 0x504,uVar2 & 0xffff,iVar3 + 4);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x58c) = uVar1;
  *(undefined1 *)(param_1 + 0x590) = 0;
  *(undefined2 *)(param_1 + 0x592) = 400;
  *(undefined2 *)(param_1 + 0x594) = 0xf0;
  iVar3 = os_create_sem_named(&DAT_201656d4,"mouse_cursor_sem");
  if (0 < iVar3) {
    *(int *)(param_1 + 0x598) = iVar3;
    FUN_201511e8();
    return;
  }
  return;
}


// ===== FUN_2015fd64 @ 2015fd64 (496 bytes)

void FUN_2015fd64(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short *unaff_r9;
  int local_10;
  undefined1 *local_c;
  undefined1 local_8 [8];
  
  do {
    do {
      while( true ) {
        while( true ) {
          FUN_20152434(*(undefined4 *)(param_1 + 0x58c),&local_10,0xffffffff);
          cVar1 = *(char *)(local_10 + 4);
          if (cVar1 != '\0') break;
          *(undefined1 *)(param_1 + 0x590) = 0;
          FUN_20117f00(0,6);
          FUN_20117f00(1,6);
          FUN_2010239c();
        }
        if (cVar1 != '\x01') break;
        *(undefined1 *)(param_1 + 0x590) = 1;
        local_8[0] = 3;
        local_c = local_8;
        FUN_20117ebc(0,6,&local_c);
        FUN_20117ebc(1,6,&local_c);
        FUN_2015fa54(param_1,400,0xf0);
      }
    } while (cVar1 != '\x02');
    if (DAT_20800496 == '\0' && DAT_20800495 == '\0') {
      if ((*(byte *)(local_10 + 0xe) & 1) == 0) {
        FUN_2010239c();
      }
    }
    else {
      FUN_20152bb0(*(undefined4 *)(param_1 + 0x598),0xffffffff);
      iVar2 = (int)*(short *)(local_10 + 0x12) * (*unaff_r9 + 0x96);
      uVar4 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x592));
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      else if (799 < (int)uVar4) {
        uVar4 = 799;
      }
      iVar2 = (int)*(short *)(local_10 + 0x14) * (*unaff_r9 + 0x96);
      uVar3 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x594));
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else if (0x1df < (int)uVar3) {
        uVar3 = 0x1df;
      }
      FUN_201511e8(*(undefined4 *)(param_1 + 0x598));
      FUN_2015fa54(param_1,uVar4 & 0xffff,uVar3 & 0xffff);
      if ((*(byte *)(local_10 + 0xe) & 1) == 0) {
        FUN_2010239c();
      }
      else {
        FUN_20102348(uVar4 & 0xffff,uVar3 & 0xffff);
      }
      if ((*(ushort *)(local_10 + 0xe) & 2) == 0) {
        if ((*(ushort *)(local_10 + 0xe) & 4) == 0) {
          FUN_201024b4();
          FUN_201025b4();
        }
        else {
          FUN_2010256c();
        }
      }
      else {
        FUN_20102478();
      }
      if (((*(ushort *)(local_10 + 0x10) & 0x100) != 0) && (*(short *)(local_10 + 0x22) != 0)) {
        FUN_2015fac4(param_1);
      }
    }
  } while( true );
}


// ===== FUN_2015ff70 @ 2015ff70 (32 bytes)

int FUN_2015ff70(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428018;
  iVar1 = FUN_20162c20(param_1 + 0x141);
  return iVar1 + -0x504;
}


// ===== FUN_2015ff94 @ 2015ff94 (92 bytes)

void FUN_2015ff94(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_20164414();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    FUN_20158618(iVar3 + 0x14);
    FUN_20164454(param_1 + 0x894,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x8dc) = uVar1;
  return;
}


// ===== FUN_2015fff0 @ 2015fff0 (40 bytes)

void FUN_2015fff0(int param_1)

{
  undefined1 auStack_8 [8];
  
  do {
    FUN_20152434(*(undefined4 *)(param_1 + 0x8dc),auStack_8,0xffffffff);
    *(int *)(param_1 + 0x8e0) = *(int *)(param_1 + 0x8e0) + 1;
  } while( true );
}


// ===== FUN_20160018 @ 20160018 (32 bytes)

int FUN_20160018(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428024;
  iVar1 = FUN_20162c10(param_1 + 0x225);
  return iVar1 + -0x894;
}


// ===== FUN_2016003c @ 2016003c (68 bytes)

undefined4 FUN_2016003c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x8198),1);
  iVar1 = FUN_201643f0(param_1 + 0x8114);
  uVar2 = *(undefined4 *)(param_1 + 0x8114 + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== FUN_20160048 @ 20160048 (96 bytes)

void FUN_20160048(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_20164460();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    FUN_20158618(iVar3 + 0x14);
    FUN_201644a0(param_1 + 0x8114,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x819c) = uVar1;
  return;
}


// ===== FUN_201600ac @ 201600ac (436 bytes)

void FUN_201600ac(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int unaff_r7;
  int local_8 [2];
  
  do {
    FUN_20152434(*(undefined4 *)(param_1 + 0x819c),local_8,0xffffffff);
    *(int *)(param_1 + 0x81a0) = *(int *)(param_1 + 0x81a0) + 1;
    bVar1 = *(byte *)(local_8[0] + 8);
    if (bVar1 == 0x21) {
      memcpy(&DAT_20450035,local_8[0] + 9,*(ushort *)(local_8[0] + 6) - 2);
      *(undefined1 *)(unaff_r7 + -0x48) = 1;
    }
    else if (bVar1 < 0x22) {
      if (bVar1 == 6) {
        *(int *)(param_1 + 0x81a4) = *(int *)(param_1 + 0x81a4) + 1;
        FUN_20130968();
        FUN_2011606c();
      }
      else if (bVar1 == 0x15) {
        *(int *)(param_1 + 0x81a8) = *(int *)(param_1 + 0x81a8) + 1;
        FUN_201160b4();
      }
      else if (bVar1 == 0x1b) {
        *(undefined4 *)(unaff_r7 + -0x11) = 1;
        *(int *)(param_1 + 0x81ac) = *(int *)(param_1 + 0x81ac) + 1;
      }
      else if (bVar1 == 0x20) {
        *(int *)(param_1 + 0x81b4) = *(int *)(param_1 + 0x81b4) + 1;
      }
    }
    else if (bVar1 == 0x23) {
      DAT_208084d4 = 1;
    }
    else if (bVar1 == 0x24) {
      FUN_201636f8();
      *(undefined1 *)(unaff_r7 + -0x49) = 1;
    }
    else if (bVar1 == 0x43) {
      *(int *)(param_1 + 0x81b8) = *(int *)(param_1 + 0x81b8) + 1;
    }
    else if (bVar1 == 0x60) {
      *(undefined1 *)(unaff_r7 + -0x47) = 1;
      FUN_20155310(&DAT_2045fb00,local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      iVar3 = FUN_2011727c();
      if (((iVar3 == 0) && (*(int *)(param_1 + 0x81b0) != 0)) && (DAT_2045fbb3 == '\x01')) {
        FUN_20117288(1);
      }
      *(int *)(param_1 + 0x81b0) = *(int *)(param_1 + 0x81b0) + 1;
    }
    cVar2 = *(char *)(local_8[0] + 8);
    *(char *)(unaff_r7 + -0x39) = cVar2;
    if ((cVar2 != '\x06' && cVar2 != '\x15') && cVar2 != '\x1b') {
      FUN_20155310(&DAT_2045f260,local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      FUN_20155310(&DAT_2045f8c0,local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
    }
  } while( true );
}


// ===== FUN_20160288 @ 20160288 (32 bytes)

int FUN_20160288(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428030;
  iVar1 = FUN_20162c18(param_1 + 0x2045);
  return iVar1 + -0x8114;
}


// ===== FUN_201602ac @ 201602ac (288 bytes)

undefined4 FUN_201602ac(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  iVar1 = fs_fopen(param_2,&DAT_204281ed);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    FUN_201140d0(5);
    FUN_20150dcc(0);
    thunk_FUN_2014af64(iVar1,&local_1c);
    if (local_1c == 0x43075a) {
      FUN_20150aac(0,&local_20);
      local_20 = local_20 + -1;
      FUN_2014e884(0);
      iVar3 = sfl_read_header(iVar1,0);
      FUN_2014e884(0);
      if (param_3 == 0) {
        FUN_20141ff0(iVar1);
        if (iVar3 != 0) {
          return 2;
        }
      }
      else {
        FUN_20100480(1);
        gpio_rx_reset(1);
        FUN_20101d2c(1);
        iVar3 = sdr_flash_write(iVar1,1,*(undefined1 *)(param_1 + 0xab));
        FUN_20141ff0(iVar1);
        if (iVar3 == 0) {
          return 3;
        }
      }
      return 0;
    }
    FUN_20141ff0(iVar1);
    uVar2 = 2;
  }
  return uVar2;
}


// ===== FUN_201603d4 @ 201603d4 (28 bytes)

void FUN_201603d4(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_201604f4();
  *puVar1 = &DAT_20428070;
  *(undefined1 *)((int)puVar1 + 0xab) = param_2;
  return;
}


// ===== FUN_201603f4 @ 201603f4 (28 bytes)

void FUN_201603f4(int param_1,undefined4 param_2)

{
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_8;
  int iStack_4;
  
  iStack_1c = param_1 + 0x37;
  iStack_20 = param_1 + 0x58;
  uStack_8 = param_2;
  iStack_4 = iStack_1c;
  FUN_20155f72(&DAT_204281f0,&iStack_20,&uStack_8,0x20155f99);
  FUN_20155f98(0,&iStack_20);
  return;
}


// ===== FUN_2016040c @ 2016040c (12 bytes)

void FUN_2016040c(int param_1)

{
  *(undefined1 *)(param_1 + 0x57) = 0;
  return;
}


// ===== FUN_20160418 @ 20160418 (132 bytes)

undefined4 FUN_20160418(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [36];
  
  iVar1 = FUN_20163600(param_1 + 0x14);
  uVar2 = 0;
  if (iVar1 != 0) {
    FUN_20164104(auStack_30,param_2);
    if (*(char *)(param_1 + 0x57) == '\0') {
      memcpy(param_1 + 0x37,auStack_30,0x20);
      *(undefined1 *)(param_1 + 0x57) = 1;
    }
    else {
      iVar1 = thunk_FUN_2014e208(param_1 + 0x37,auStack_30);
      if (iVar1 < 1) {
        memcpy(param_1 + 0x37,auStack_30,0x20);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ===== FUN_2016049c @ 2016049c (44 bytes)

void FUN_2016049c(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_28 [32];
  
  uVar1 = FUN_20164104(auStack_28);
  memcpy(param_1 + 0x89,uVar1,0x20);
  return;
}


// ===== FUN_201604c8 @ 201604c8 (20 bytes)

void FUN_201604c8(int param_1)

{
  FUN_20160c28(param_1 + 0xe,*(int *)(param_1 + 0x20) + param_1 + 0x37);
  return;
}


// ===== FUN_201604dc @ 201604dc (24 bytes)

void FUN_201604dc(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xaa) = 0;
  *(undefined1 *)(param_1 + 0x88) = param_2;
  *(undefined1 *)(param_1 + 0xa9) = 1;
  return;
}


// ===== FUN_201604f4 @ 201604f4 (88 bytes)

int FUN_201604f4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_2042807c;
  iVar1 = FUN_201640ec(param_1 + 1,&DAT_20428430);
  iVar1 = FUN_20160c5c(iVar1 + 10,"-----");
  iVar1 = FUN_201640ec(iVar1 + 0x1e,&DAT_20428430);
  iVar1 = FUN_20164104(iVar1 + 0xb,&DAT_20428430);
  iVar1 = FUN_2016411c(iVar1 + 0x21,&DAT_20428430);
  iVar1 = FUN_20164104(iVar1 + 0x31,&DAT_20428430);
  return iVar1 + -0x89;
}


// ===== FUN_20160558 @ 20160558 (80 bytes)

void FUN_20160558(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  param_1[1] = param_2;
  param_1[2] = param_3;
  iVar1 = FUN_20155122(param_2);
  param_1[3] = iVar1;
  iVar1 = FUN_20155122(param_3);
  param_1[5] = iVar1;
  iVar1 = FUN_20155122(&DAT_204281f5);
  param_1[4] = iVar1 + param_1[3];
  *param_1 = iVar1 + param_1[3] + param_1[5];
  return;
}


// ===== FUN_201605ac @ 201605ac (244 bytes)

undefined4 FUN_201605ac(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_18 = param_4;
  iVar1 = fs_fopen(param_2,&DAT_204281fa);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    FUN_201140d0(5);
    FUN_20150dcc(0);
    FUN_20150aac(0,&local_18);
    local_18 = local_18 + -1;
    FUN_2014e884(0);
    iVar3 = sfl_read_header(iVar1,0);
    FUN_2014e884(0);
    if (param_3 == 0) {
      FUN_20141ff0(iVar1);
      if (iVar3 != 0) {
        return 2;
      }
    }
    else {
      FUN_20116518(1);
      gpio_rx_reset(0);
      FUN_20101ca4(1);
      itron_dly_tsk(5);
      gpio_rx_reset(1);
      itron_dly_tsk(0x28);
      iVar3 = FUN_2010d50c(iVar1,1);
      FUN_20141ff0(iVar1);
      if (iVar3 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_201606a4 @ 201606a4 (20 bytes)

void FUN_201606a4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_201604f4();
  *puVar1 = &DAT_20428088;
  return;
}


// ===== FUN_201606bc @ 201606bc (264 bytes)

undefined4 FUN_201606bc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_28;
  uint uStack_24;
  undefined4 local_20;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  iVar1 = fs_fopen(param_2,&DAT_204281fd);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    FUN_201140d0(5);
    FUN_20150dcc(0);
    FUN_20150aac(0,&local_28);
    local_28 = local_28 - 1;
    FUN_2014e884(0);
    iVar3 = sfl_read_header(iVar1,0);
    FUN_2014e884(0);
    if (param_3 == 0) {
      FUN_20141ff0(iVar1);
      if (iVar3 != 0) {
        return 2;
      }
    }
    else {
      FUN_20100480(1);
      gpio_rx_reset(1);
      local_28 = (uint)*(byte *)(param_1 + 0xab);
      local_20 = 0;
      uStack_24 = (uint)(local_28 == 0);
      iVar3 = FUN_2010b81c(iVar1,1,0);
      FUN_20141ff0(iVar1);
      if (iVar3 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_201607c8 @ 201607c8 (28 bytes)

void FUN_201607c8(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_201604f4();
  *puVar1 = &DAT_20428094;
  *(undefined1 *)((int)puVar1 + 0xab) = param_2;
  return;
}


// ===== FUN_201607e8 @ 201607e8 (1032 bytes)

undefined4 FUN_201607e8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *unaff_r10;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auStack_d0 [68];
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  int local_78;
  int local_74;
  undefined1 auStack_70 [4];
  undefined4 local_6c;
  undefined1 auStack_68 [24];
  undefined4 local_50;
  uint local_4c;
  undefined1 auStack_48 [8];
  uint local_40;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  
  bVar1 = false;
  memclr(auStack_d0,0x44);
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_78 = fs_fopen(param_2,&DAT_20428200);
  if (local_78 == 0) {
    return 1;
  }
  FUN_20150aac(0,&local_74);
  local_74 = local_74 + -1;
  FUN_2014e884(0);
  iVar2 = sfl_read_header(local_78,auStack_d0);
  FUN_2014e884(0);
  if (DAT_20800181 == ':') {
    unaff_r10 = (undefined4 *)&DAT_20428203;
    iVar3 = thunk_FUN_20155058(auStack_d0,&DAT_20428203);
    if (iVar3 != 0) {
      iVar4 = FUN_20155122(&DAT_20428203);
      iVar3 = iVar3 + iVar4;
      *(undefined1 *)(iVar3 + 8) = 0;
      iVar4 = FUN_2015507c("#UP0    ",iVar3,8);
      if (iVar4 == 0) {
        uVar5 = FUN_201640ec(auStack_3c,iVar3);
        memcpy(param_1 + 4,uVar5,10);
        uVar5 = FUN_201640ec(auStack_30,&DAT_20428210);
        memcpy(param_1 + 0x2c,uVar5,10);
        bVar1 = true;
      }
    }
  }
  if (param_3 == 0) {
    FUN_20141ff0(local_78);
    if (iVar2 == 0) {
      return 0;
    }
    return 2;
  }
  iVar2 = FUN_2010e514(3);
  if (iVar2 == 0) {
    return 3;
  }
  FUN_20100480(1);
  gpio_rx_reset(1);
  FUN_20101d2c(1);
  local_50 = FUN_20111174(0x100);
  FUN_201140e8(auStack_70,5,0x1e);
  uVar8 = 0;
  iVar2 = 0;
  thunk_FUN_2014af64(local_78,&local_40);
  if (local_40 < 0x242) {
    return 3;
  }
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_74 = local_40 - 0x240;
  if (DAT_208dbb44 == 1) {
    puVar7 = &DAT_208dbb84;
    unaff_r10 = &DAT_208dbb64;
  }
  else {
    puVar7 = &DAT_208dbb64;
  }
  iVar3 = puVar7[1];
  if (DAT_208dbb44 != 1) {
    unaff_r10 = &DAT_208dbb84;
  }
  sfl_stream_init(auStack_68,local_78,0,1);
  FUN_201140f4(auStack_70,extraout_r1,0,0x3ff00000);
  FUN_201140d0();
  if (DAT_208dbb4c == 2) {
    bVar1 = true;
LAB_201609ec:
    iVar3 = 0;
    iVar4 = FUN_20103e74(0,0x3c0000,0x14);
    if (iVar4 != 0) goto LAB_20160ac8;
    iVar4 = FUN_20103e74(auStack_70,0,local_74);
  }
  else {
    if (bVar1) goto LAB_201609ec;
    iVar4 = FUN_20103e74(0,*puVar7,0x14);
    if (iVar4 != 0) goto LAB_20160ac8;
    iVar4 = FUN_20103e74(auStack_70,puVar7[1],local_74);
  }
  if (iVar4 == 0) {
    FUN_201140e8(auStack_48,local_6c,99);
    local_4c = 0xffffffff;
    crc32_make_table();
    while( true ) {
      iVar4 = FUN_20114bfc(local_50,1,0x100,auStack_68);
      if (iVar4 == 0) {
        FUN_201140d0(100);
        FUN_20141ff0(local_78);
        if (local_74 != iVar2) {
          return 3;
        }
        local_8c = 0x11111111;
        local_7c = ~local_4c;
        local_88 = local_74;
        if (bVar1) {
          iVar2 = FUN_20103dd0(0x3c0000,&local_8c,0x14);
        }
        else {
          iVar2 = FUN_20103dd0(*puVar7,&local_8c,0x14);
          if (iVar2 != 0) {
            return 3;
          }
          iVar2 = FUN_20103e74(0,*unaff_r10,0x14);
        }
        if (iVar2 == 0) {
          iVar2 = FUN_2010e514(0x83);
          if (iVar2 != 0) {
            return 0;
          }
          return 3;
        }
        return 3;
      }
      iVar6 = FUN_20103dd0(iVar3,local_50,iVar4);
      if (iVar6 != 0) break;
      local_4c = crc32_update(local_4c,iVar4,local_50);
      iVar2 = iVar2 + iVar4;
      iVar3 = iVar3 + 0x100;
      uVar9 = FUN_20164d82(local_74);
      uVar10 = FUN_20164d82(iVar2);
      uVar9 = FUN_201649d8((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                           (int)((ulonglong)uVar9 >> 0x20));
      uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
      FUN_201140f4(auStack_48,uVar5,(int)uVar9,uVar5);
      FUN_201140d0();
      if ((uVar8 & 0xf) == 0) {
        FUN_20150dcc(0);
      }
      uVar8 = uVar8 + 1;
    }
  }
LAB_20160ac8:
  FUN_20141ff0(local_78);
  return 3;
}


// ===== FUN_20160c10 @ 20160c10 (20 bytes)

void FUN_20160c10(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_201604f4();
  *puVar1 = &DAT_204280a0;
  return;
}


// ===== FUN_20160c28 @ 20160c28 (52 bytes)

void FUN_20160c28(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = 0x2d;
  param_1[3] = param_2[2];
  param_1[4] = param_2[3];
  param_1[5] = 0;
  return;
}


// ===== FUN_20160c5c @ 20160c5c (20 bytes)

undefined4 FUN_20160c5c(undefined4 param_1)

{
  FUN_20160c28();
  return param_1;
}


// ===== FUN_20160c70 @ 20160c70 (124 bytes)

void FUN_20160c70(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0x27;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}


// ===== FUN_20160cf0 @ 20160cf0 (92 bytes)

void FUN_20160cf0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1 + 0x200) = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      if (0xff < iVar1) {
        return;
      }
      if (iVar1 < 1) break;
      iVar2 = iVar1 * 0xc1a + 0x2134;
      *(char *)(param_1 + iVar1 + 0x200) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== FUN_20160d50 @ 20160d50 (144 bytes)

void FUN_20160d50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x100) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x100) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0x27;
  } while (iVar1 < 0x100);
  return;
}


// ===== FUN_20160de4 @ 20160de4 (92 bytes)

void FUN_20160de4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1 + 0x300) = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      if (0xff < iVar1) {
        return;
      }
      if (iVar1 < 1) break;
      iVar2 = iVar1 * 0xc1a + 0x2134;
      *(char *)(param_1 + iVar1 + 0x300) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== FUN_20160e44 @ 20160e44 (144 bytes)

void FUN_20160e44(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x400) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xe34 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x400) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0x2c;
  } while (iVar1 < 0x100);
  return;
}


// ===== FUN_20160ed8 @ 20160ed8 (52 bytes)

void FUN_20160ed8(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10 = 0xe2;
  mainlink_queue_frame(&local_10,6);
  return;
}


// ===== FUN_20161bb0 @ 20161bb0 (52 bytes)

void FUN_20161bb0(void)

{
  undefined1 auStack_10 [12];
  
  FUN_2010231c();
  FUN_2010239c();
  FUN_20120e9c(0,0xffff);
  FUN_20102138(auStack_10,1);
  return;
}


// ===== FUN_20162b50 @ 20162b50 (176 bytes)

void FUN_20162b50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xf;
  } while (iVar2 < 0x100);
  iVar2 = 0x81;
  do {
    if (iVar2 + -0x81 < 1) {
      *(undefined2 *)(param_1 + iVar2 * 2) = 0xf;
    }
    else {
      *(undefined2 *)(param_1 + iVar2 * 2) =
           *(undefined2 *)(&UNK_20166da8 + (0x20 - ((iVar2 + -0x81) * 0xa54 + 0x26ac) / 10000) * 2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xfb);
  iVar2 = 0xfb;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xffff;
  } while (iVar2 < 0x100);
  return;
}


// ===== FUN_20162c10 @ 20162c10 (16 bytes)

void FUN_20162c10(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20162c18 @ 20162c18 (8 bytes)

void FUN_20162c18(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20162c20 @ 20162c20 (16 bytes)

void FUN_20162c20(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20162c28 @ 20162c28 (212 bytes)

void FUN_20162c28(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0;
  } while (iVar3 < 0x100);
  uVar7 = (uint)*(byte *)(param_1 + 0x200);
  uVar4 = (uint)*(byte *)(param_1 + 0x201);
  iVar3 = *(int *)(param_2 + 4);
  if (uVar7 <= uVar4) {
    do {
      bVar2 = *(byte *)(param_1 + 0x200);
      iVar5 = __aeabi_uidivmod(640000,(uVar4 - bVar2) + 1);
      iVar6 = uVar7 - bVar2;
      iVar1 = uVar7 * 2;
      uVar7 = uVar7 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)
            (iVar3 + ((uint)*(ushort *)(param_2 + 2) - (iVar5 * (iVar6 + 1) + 0x26ac) / 10000) * 2);
      uVar4 = (uint)*(byte *)(param_1 + 0x201);
    } while ((int)uVar7 <= (int)uVar4);
  }
  uVar4 = uVar4 + 1;
  if (uVar4 < 0x100) {
    do {
      iVar1 = uVar4 * 2;
      uVar4 = uVar4 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)(iVar3 + (uint)*(ushort *)(param_2 + 2) * 2 + -0x80);
    } while ((int)uVar4 < 0x100);
  }
  return;
}


// ===== cpp_task_thunk @ 20162d04 (12 bytes)

/* task entry for C++ objects: exinf = object, calls obj->vtbl[0] */

void cpp_task_thunk(undefined4 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x20162d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ===== FUN_20162d10 @ 20162d10 (40 bytes)

void FUN_20162d10(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  uStack_14 = 1;
  uStack_10 = 0;
  uStack_c = 0;
  FUN_2014f67c(0,&local_18);
  return;
}


// ===== FUN_20162d3c @ 20162d3c (12 bytes)

code * FUN_20162d3c(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 unaff_r4;
  uint uVar6;
  int *piVar7;
  undefined4 unaff_lr;
  bool bVar8;
  
  if ((param_2 == 0) || (8 < param_2)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  puVar4 = *(undefined4 **)(&DAT_208dbea4 + param_2 * 4);
  if (puVar4 == (undefined4 *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  pbVar2 = (byte *)((int)puVar4 + 7);
  do {
    uVar6 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (uVar6 == 0);
  if (0xfd < uVar6) {
    uVar6 = (uint)*(byte *)((int)puVar4 + 6);
    if (uVar6 != 0) {
      piVar7 = (int *)(uVar6 + (int)puVar4);
    }
    else {
      piVar7 = (int *)*puVar4;
    }
    uVar5 = (uint)*(byte *)(puVar4 + 1);
    if (uVar6 == 0) {
      piVar7 = (int *)piVar7[2];
    }
    if (1 < uVar5) {
      iVar3 = param_3[1];
      bVar8 = SBORROW4(uVar5,iVar3);
      iVar1 = uVar5 - iVar3;
      if (iVar3 <= (int)uVar5) {
        bVar8 = SBORROW4(iVar3,1);
        iVar1 = iVar3 + -1;
      }
      if (iVar1 < 0 != bVar8) {
        software_interrupt(0);
        return (code *)0xffffffef;
      }
      piVar7 = piVar7 + iVar3 * 2 + -2;
    }
    if (*piVar7 == 0) {
      *piVar7 = (int)param_3;
    }
    else {
      *(undefined4 **)piVar7[1] = param_3;
    }
    piVar7[1] = (int)param_3;
    *param_3 = 0;
    software_interrupt(0);
    return FUN_201567f4;
  }
  piVar7 = *(int **)(&DAT_208dbba0 + uVar6 * 4);
  **(undefined4 **)(*piVar7 + 0xc) = param_3;
  if ((*(byte *)((int)piVar7 + 5) & 2) != 0) {
    FUN_20153ad4(piVar7,uVar6);
  }
  *(undefined1 *)((int)piVar7 + 5) = 0x10;
  if (*(char *)((int)piVar7 + 9) == '\0') {
    iVar1 = piVar7[1];
    FUN_20153a38(&DAT_208dc18c + (char)iVar1,piVar7,uVar6,&DAT_208dc18c + (char)iVar1,unaff_r4,
                 unaff_lr);
    if ((int)DAT_208003df <= (int)(char)iVar1) {
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


// ===== FUN_20162d48 @ 20162d48 (12 bytes)

void FUN_20162d48(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2e04) = param_2;
  return;
}


// ===== FUN_20162dd8 @ 20162dd8 (316 bytes)

void FUN_20162dd8(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x81c) = *(int *)(param_1 + 0x81c) + 1;
  iVar1 = *(int *)(param_1 + 4);
  if ((*(ushort *)(iVar1 + 0x10) & 0xff9d) != 0) {
    *(int *)(param_1 + 0x828) = *(int *)(param_1 + 0x828) + 1;
  }
  if ((*(ushort *)(iVar1 + 0x10) & 2) != 0) {
    if (((*(ushort *)(param_1 + 10) < *(ushort *)(param_1 + 8)) ||
        (0x3fe < (int)((uint)*(ushort *)(param_1 + 10) - (uint)*(ushort *)(param_1 + 8)))) &&
       ((*(ushort *)(param_1 + 8) <= *(ushort *)(param_1 + 10) ||
        ((int)((uint)*(ushort *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 10)) < 2)))) {
      *(ushort *)(iVar1 + 0x10) = *(ushort *)(iVar1 + 0x10) & 0xfffd;
      *(int *)(param_1 + 0x820) = *(int *)(param_1 + 0x820) + 1;
      *(int *)(param_1 + 0x824) = *(int *)(param_1 + 0x824) + 1;
      return;
    }
    *(undefined1 *)((uint)*(ushort *)(param_1 + 10) + param_1 + 0xc) = *(undefined1 *)(iVar1 + 0x14)
    ;
    DataMemoryBarrier(2);
    *(ushort *)(param_1 + 10) = *(short *)(param_1 + 10) + 1U & 0x3ff;
    *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xfffd;
    if (*(int *)(param_1 + 0x818) != 0) {
      FUN_201177a0(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
    }
    itron_set_flg(*(undefined4 *)(param_1 + 0x818),1);
    *(int *)(param_1 + 0x820) = *(int *)(param_1 + 0x820) + 1;
    FUN_20114850(param_1 + 0x840);
    return;
  }
  *(int *)(param_1 + 0x82c) = *(int *)(param_1 + 0x82c) + 1;
  return;
}


// ===== uart_obj_init @ 20162fac (104 bytes)

undefined4
uart_obj_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 0x818) = param_5;
    *(undefined4 *)(param_1 + 0x810) = param_3;
    *(undefined4 *)(param_1 + 0x814) = param_4;
    iVar1 = FUN_2014f1a8(0,param_4);
    if ((iVar1 < 1) || (iVar1 = FUN_2014f1a8(0,*(undefined4 *)(param_1 + 0x810)), iVar1 < 1)) {
      return 0xffffffff;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x818) = param_5;
  }
  return 0;
}


// ===== FUN_20163014 @ 20163014 (36 bytes)

void FUN_20163014(int param_1)

{
  FUN_201177a0(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  FUN_201177a0(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return;
}


// ===== FUN_20163038 @ 20163038 (96 bytes)

int FUN_20163038(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  while ((bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2 &&
         (*(short *)(param_1 + 10) != *(short *)(param_1 + 8)))) {
    *param_2 = *(undefined1 *)((uint)*(ushort *)(param_1 + 8) + param_1 + 0xc);
    DataMemoryBarrier(2);
    *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) + 1U & 0x3ff;
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  }
  FUN_2011775c(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return iVar1;
}


// ===== FUN_20163098 @ 20163098 (52 bytes)

void FUN_20163098(int param_1)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_stack_00000000;
  
  FUN_201630cc(param_1);
  FUN_2011775c(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  FUN_2011775c(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8),extraout_r1,extraout_r2,
               in_stack_00000000);
  return;
}

