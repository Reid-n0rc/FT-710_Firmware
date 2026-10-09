// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20120674 @ 20120674 (76 bytes)

undefined4 FUN_20120674(uint param_1,uint param_2)

{
  if ((param_1 < 4) && (param_2 < 3)) {
    if (param_2 == 0) {
      FUN_201205c0();
    }
    else if (param_2 == 1) {
      FUN_2012050c();
    }
    else if (param_2 == 2) {
      FUN_201204d4();
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_201206c0 @ 201206c0 (144 bytes)

undefined4 FUN_201206c0(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_201204a4();
  iVar2 = FUN_20157174(iVar1 + 0x24,4,0x10);
  if (iVar2 == 0) {
    uVar3 = 0;
    if (param_1 == 0) {
      FUN_201200c8();
      FUN_2011fefc();
    }
    else if (param_1 == 1) {
      FUN_201200dc();
      FUN_2011ff0c();
    }
    else if (param_1 == 2) {
      FUN_201200f0();
      FUN_2011ff1c();
    }
    else if (param_1 == 3) {
      FUN_20120104();
      FUN_2011ff2c();
    }
    *(undefined1 *)(iVar1 + 0x3c) = param_2;
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


// ===== FUN_20120750 @ 20120750 (204 bytes)

int FUN_20120750(uint param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 < 4) && (param_3 < 2)) {
    iVar1 = FUN_201206c0(param_1,param_2);
    if (iVar1 == 0) {
      if (param_1 == 0) {
        FUN_20120118(param_3);
        FUN_2011ff3c(param_3);
      }
      else if (param_1 == 1) {
        FUN_20120148(param_3);
        FUN_2011ff54(param_3);
      }
      else if (param_1 == 2) {
        FUN_201201c4(param_3);
        FUN_2011ff6c(param_3);
      }
      else if (param_1 == 3) {
        FUN_201201f4(param_3);
        FUN_2011ff84(param_3);
      }
      iVar2 = FUN_201204a4(param_1);
      iVar2 = FUN_20157174(iVar2 + 0x24,4,0x10);
      if (iVar2 != 0) {
        iVar1 = -2;
      }
    }
    return iVar1;
  }
  return -1;
}


// ===== FUN_2012081c @ 2012081c (232 bytes)

int FUN_2012081c(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (3 < param_1) {
    return -1;
  }
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    uVar3 = 0;
    do {
      iVar1 = FUN_201206c0(param_1,*(undefined1 *)(param_2 + uVar3));
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
    if (param_1 == 0) {
      FUN_20120118(0);
      FUN_2011ff3c(0);
    }
    else if (param_1 == 1) {
      FUN_20120148(0);
      FUN_2011ff54(0);
    }
    else if (param_1 == 2) {
      FUN_201201c4(0);
      FUN_2011ff6c(0);
    }
    else if (param_1 == 3) {
      FUN_201201f4(0);
      FUN_2011ff84(0);
    }
    iVar1 = FUN_201204a4(param_1);
    iVar2 = FUN_20157174(iVar1 + 0x24,4,0x10);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = -2;
    }
  }
  return iVar1;
}


// ===== FUN_20120904 @ 20120904 (20 bytes)

void FUN_20120904(int param_1)

{
  FUN_20157138(param_1 + 0x24,0,4,0x10);
  return;
}


// ===== FUN_20120918 @ 20120918 (100 bytes)

void FUN_20120918(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_20120344();
  }
  else if (param_1 == 1) {
    FUN_20120368();
  }
  else if (param_1 == 2) {
    FUN_2012038c();
  }
  else if (param_1 == 3) {
    FUN_201203b0();
  }
  iVar1 = FUN_201204a4(param_1);
  FUN_20120904();
  FUN_20157138(iVar1 + 0x24,0,3,8);
  return;
}


// ===== FUN_2012097c @ 2012097c (248 bytes)

void FUN_2012097c(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_20120078();
    FUN_2011febc();
  }
  else if (param_1 == 1) {
    FUN_2012008c();
    FUN_2011fecc();
  }
  else if (param_1 == 2) {
    FUN_201200a0();
    FUN_2011fedc();
  }
  else if (param_1 == 3) {
    FUN_201200b4();
    FUN_2011feec();
  }
  iVar1 = FUN_201204a4(param_1);
  switch(param_2) {
  case 1:
    FUN_20157138(iVar1 + 0x10,1,4,0x10);
    FUN_20157138(iVar1 + 0x10,0,3,8);
    break;
  case 2:
    FUN_20157138(iVar1 + 0x10,1,6,0x40);
    break;
  case 3:
    FUN_20157138(iVar1 + 0x10,1,4,0x10);
    FUN_20157138(iVar1 + 0x10,1,3,8);
    break;
  case 4:
    FUN_201204d4(param_1);
  }
  *param_3 = *(undefined1 *)(iVar1 + 0x40);
  return;
}


// ===== FUN_20120a88 @ 20120a88 (20 bytes)

void FUN_20120a88(void)

{
  FUN_201204a4();
  return;
}


// ===== FUN_20120a9c @ 20120a9c (272 bytes)

undefined4 FUN_20120a9c(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (3 < param_1) {
    return 0xffffffff;
  }
  if (param_3 != 0) {
    iVar1 = FUN_201204a4();
    if (param_3 == 1) {
      FUN_20157138(iVar1 + 0x10,1,6,0x40);
      FUN_20157138(iVar1 + 0x10,1,4,0x10);
      FUN_20157138(iVar1 + 0x10,1,3,8);
    }
    FUN_20120a88(param_1);
    if (param_3 != 1) {
      if (param_3 != 2) {
        for (; 3 < param_3; param_3 = param_3 - 1) {
          FUN_2012097c(param_1,0,param_2);
          param_2 = param_2 + 1;
        }
        FUN_2012097c(param_1,2,param_2);
        param_2 = param_2 + 1;
      }
      FUN_2012097c(param_1,3,param_2);
      param_2 = param_2 + 1;
    }
    FUN_2012097c(param_1,4,param_2);
    FUN_20157138(iVar1 + 0x10,0,6,0x40);
    FUN_20120918(param_1);
    return 0;
  }
  return 0;
}


// ===== FUN_20120bac @ 20120bac (28 bytes)

undefined4 FUN_20120bac(uint param_1)

{
  if (param_1 < 4) {
    FUN_20120a88(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20120bc8 @ 20120bc8 (28 bytes)

undefined4 FUN_20120bc8(uint param_1)

{
  if (param_1 < 4) {
    FUN_20120918(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20120bf0 @ 20120bf0 (20 bytes)

undefined4 FUN_20120bf0(void)

{
  FUN_201204a4();
  FUN_20120904();
  return 0;
}


// ===== FUN_20120c08 @ 20120c08 (76 bytes)

undefined4 FUN_20120c08(int param_1)

{
  undefined4 uVar1;
  bool in_CY;
  
  if (in_CY) {
    uVar1 = 0xffffffff;
  }
  else {
    if (param_1 == 0) {
      FUN_2011ff9c();
    }
    else if (param_1 == 1) {
      FUN_2011ffac();
    }
    else if (param_1 == 2) {
      FUN_2011ffbc();
    }
    else if (param_1 == 3) {
      FUN_2011ffcc();
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20120c58 @ 20120c58 (76 bytes)

undefined4 FUN_20120c58(int param_1)

{
  undefined4 uVar1;
  bool in_CY;
  
  if (in_CY) {
    uVar1 = 0xffffffff;
  }
  else {
    if (param_1 == 0) {
      FUN_2011ffdc();
    }
    else if (param_1 == 1) {
      FUN_2011ffec();
    }
    else if (param_1 == 2) {
      FUN_2011fffc();
    }
    else if (param_1 == 3) {
      FUN_20120028();
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20120cb0 @ 20120cb0 (136 bytes)

undefined4 FUN_20120cb0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      FUN_20120038(0);
    }
    else if (param_1 == 1) {
      FUN_20120048();
    }
    else if (param_1 == 2) {
      FUN_20120058();
    }
    else if (param_1 == 3) {
      FUN_20120068();
    }
    iVar2 = FUN_201204a4(param_1);
    FUN_20157138(iVar2 + 0x24,0,6,0x40,param_4);
    FUN_20157174(iVar2 + 0x24,6,0x40);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_20120d38 @ 20120d38 (108 bytes)

void FUN_20120d38(void)

{
  DAT_208dd994 = 0;
  DAT_208dd995 = 0;
  FUN_20160c70(&DAT_208dce3c);
  FUN_20160d50(&DAT_208dce3c);
  FUN_20160cf0(&DAT_208dce3c);
  FUN_20160de4(&DAT_208dce3c);
  FUN_20160e44(&DAT_208dce3c);
  FUN_20162b50(&DAT_208dd53c);
  memclr(&DAT_208dd73c,600);
  FUN_20155254(&DAT_208dd73c,200,0xff);
  return;
}


// ===== FUN_20120d40 @ 20120d40 (188 bytes)

void FUN_20120d40(char *param_1)

{
  if (DAT_208dd994 == '\0') {
    if (*param_1 == '\x01') {
      if ((DAT_208004a0 != '\0') || (DAT_208dd995 != '\0')) goto LAB_20157258;
      memcpy(&DAT_208dd73c,param_1,600);
      DAT_208dd73c = 0xff;
      DAT_208dd73d = 0xff;
      if (((ushort)DAT_20808a84 & 0x400) != 0) {
        memcpy(&DAT_208dd73c,&DAT_20166de8,200);
        memcpy(&DAT_208dd804,&DAT_20166eb0,400);
        return;
      }
    }
  }
  else if (DAT_208dd995 != '\0') {
LAB_20157258:
    FUN_20155254(&DAT_208dd73c,600,0xff);
    return;
  }
  return;
}


// ===== FUN_20120d4c @ 20120d4c (20 bytes)

void FUN_20120d4c(undefined1 param_1)

{
  DAT_208dd994 = param_1;
  return;
}


// ===== FUN_20120d58 @ 20120d58 (8 bytes)

void FUN_20120d58(void)

{
  memclr(&DAT_208dd99c,0x13178);
  DAT_208f0b14 = 0;
  return;
}


// ===== FUN_20120d60 @ 20120d60 (152 bytes)

undefined4 FUN_20120d60(int param_1,int param_2)

{
  int iVar1;
  byte local_260 [392];
  undefined1 auStack_d8 [200];
  
  FUN_20157214(&DAT_208dce3c,auStack_d8,&DAT_208dd73c,200);
  FUN_20134074(local_260,auStack_d8);
  iVar1 = 0;
  if (param_1 == 0) {
    do {
      *(undefined *)(param_2 + iVar1) = (&DAT_208dce3c)[local_260[iVar1]];
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x187);
  }
  else {
    do {
      *(undefined *)(param_2 + iVar1) = (&DAT_208dcf3c)[local_260[iVar1]];
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x187);
  }
  return 0x27;
}


// ===== FUN_20120d84 @ 20120d84 (92 bytes)

undefined4 FUN_20120d84(int param_1)

{
  int iVar1;
  byte local_d8 [204];
  
  FUN_20157214(&DAT_208dce3c,local_d8,&DAT_208dd73c,200);
  iVar1 = 0;
  do {
    *(undefined *)(param_1 + iVar1) = (&DAT_208dd23c)[local_d8[iVar1]];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  return 0x2c;
}


// ===== FUN_20120d90 @ 20120d90 (168 bytes)

void FUN_20120d90(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte local_4b0 [391];
  undefined1 auStack_329 [393];
  undefined1 auStack_1a0 [200];
  undefined1 auStack_d8 [200];
  
  if (DAT_208dd994 == '\0') {
    FUN_20157214(&DAT_208dce3c,auStack_1a0,&DAT_208dd73c,200);
    FUN_20134074(local_4b0,auStack_1a0);
    FUN_20134074(auStack_329,auStack_d8);
    iVar3 = FUN_20164360(&DAT_208f0b14);
    iVar4 = 0;
    do {
      pbVar2 = local_4b0 + iVar4;
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(&DAT_208dd99c + iVar1 + iVar3 * 0x30e) =
           *(undefined2 *)(&DAT_208dd53c + (uint)*pbVar2 * 2);
    } while (iVar4 < 0x187);
  }
  return;
}


// ===== FUN_20120d98 @ 20120d98 (56 bytes)

undefined * FUN_20120d98(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_20164758(&DAT_208f0b14,~param_1);
  return &DAT_208dd99c + iVar1 * 0x30e;
}


// ===== FUN_20120da4 @ 20120da4 (192 bytes)

void FUN_20120da4(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte local_320 [784];
  
  FUN_20134094(local_320,&DAT_208dd804);
  iVar3 = 0;
  if (param_1 != 0) {
    do {
      bVar2 = local_320[iVar3 * 2 + 1];
      *(undefined *)(param_2 + iVar3 * 2) = (&DAT_208dd13c)[local_320[iVar3 * 2]];
      iVar1 = iVar3 * 2;
      iVar3 = iVar3 + 1;
      *(undefined *)(param_2 + iVar1 + 1) = (&DAT_208dd13c)[bVar2];
    } while (iVar3 < 0x187);
    return;
  }
  do {
    bVar2 = local_320[iVar3 * 2 + 1];
    *(undefined *)(param_2 + iVar3 * 2) = (&DAT_208dd03c)[local_320[iVar3 * 2]];
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined *)(param_2 + iVar1 + 1) = (&DAT_208dd03c)[bVar2];
  } while (iVar3 < 0x187);
  return;
}


// ===== FUN_20120db4 @ 20120db4 (12 bytes)

void FUN_20120db4(undefined4 param_1)

{
  FUN_201572f8(&DAT_208dce3c,param_1);
  return;
}


// ===== FUN_20120dc0 @ 20120dc0 (44 bytes)

void FUN_20120dc0(void)

{
  FUN_201575f8(&DAT_208dce3c);
  return;
}


// ===== FUN_20120dc8 @ 20120dc8 (12 bytes)

undefined4 FUN_20120dc8(void)

{
  return DAT_208dd998;
}


// ===== FUN_20120de4 @ 20120de4 (184 bytes)

void FUN_20120de4(void)

{
  undefined1 uVar1;
  int iVar2;
  byte bVar3;
  undefined1 uStack_18;
  byte local_17;
  
  if (DAT_208f0b2a == 'P') {
    if (DAT_20450024 != '\0') {
      bVar3 = 0;
      uVar1 = (&DAT_20801d44 + ((uint)(DAT_208f0bc2 >> 4) % 5) * 3)[(DAT_208f0bc2 & 0xf) % 3];
      iVar2 = FUN_20115024(&uStack_18,&DAT_20801d44 + ((uint)(DAT_208f0bc2 >> 4) % 5) * 3,
                           &DAT_20801d44,(DAT_208f0bc2 & 0xf) * -0x55555555);
      if (iVar2 != 0) {
        bVar3 = local_17 & 0xf;
      }
      FUN_20107378(bVar3);
      FUN_201073a4(uVar1);
      return;
    }
  }
  else {
    FUN_2010738c();
  }
  return;
}


// ===== FUN_20120e9c @ 20120e9c (288 bytes)

void FUN_20120e9c(uint param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  sVar2 = 0;
  local_c = 0;
  if (DAT_20800468 != param_1) {
    if (param_1 == 0) {
      DAT_20800478 = DAT_20800478 + 1;
      local_10._0_2_ = 0xe0;
    }
    else {
      DAT_20800474 = DAT_20800474 + 1;
      local_10._0_2_ = 0x1e0;
    }
    if (param_2 == 0x1016) {
      if (param_1 == 0) {
        uVar1 = 0x40;
      }
      else {
        if (param_3 < 3) {
          sVar2 = 1;
        }
        else {
          sVar2 = (short)param_3 + -3;
        }
        uVar1 = 0x41;
      }
      local_10._0_2_ = CONCAT11(uVar1,(undefined1)(undefined2)local_10);
      local_10 = CONCAT13((char)sVar2,CONCAT12((char)((ushort)sVar2 >> 8),(undefined2)local_10));
    }
    else if (param_2 == 0xffff) {
      local_10 = CONCAT13((char)DAT_2080046a,
                          CONCAT12((char)((ushort)DAT_2080046a >> 8),(undefined2)local_10)) &
                 0xffefffff;
    }
    else {
      local_10 = CONCAT13((char)param_2,CONCAT12((char)((uint)param_2 >> 8),(undefined2)local_10)) &
                 0xffefffff;
    }
    DAT_20800468 = (byte)param_1;
    if ((DAT_208f0b2a != '{') || (DAT_208f0b2b == '\0')) {
      DAT_2080046a = (undefined2)param_2;
      mainlink_queue_frame(&local_10,5);
      return;
    }
    DAT_20800487 = 1;
  }
  return;
}


// ===== FUN_20120fe4 @ 20120fe4 (96 bytes)

undefined4 FUN_20120fe4(void)

{
  if (DAT_208f0b2a != 0x3a) {
    if (DAT_208f0b2a < 0x3b) {
      if (DAT_208f0b2a == 0x30) {
        if ((DAT_208f0bc2 != '\x05' && DAT_208f0bc2 != '\v') && DAT_208f0bc2 != '\f') {
          return 0xffff;
        }
      }
      else if (DAT_208f0b2a != 0x34 && DAT_208f0b2a != 0x37) {
        return 0xffff;
      }
    }
    else if ((DAT_208f0b2a != 0x40 && DAT_208f0b2a != 0x43) && DAT_208f0b2a != 0x70) {
      return 0xffff;
    }
  }
  return 0x30f;
}


// ===== FUN_20121044 @ 20121044 (256 bytes)

void FUN_20121044(void)

{
  undefined4 uVar1;
  undefined1 local_18 [12];
  
  FUN_201024c4(local_18);
  switch(local_18[0]) {
  default:
    goto switchD_20121064_caseD_0;
  case 2:
    DAT_20800470 = FUN_20120fe4();
    if (DAT_20800470 == -1) {
      return;
    }
    break;
  case 4:
    FUN_20120e9c(0,DAT_20800470);
    if (DAT_20800470 == -1) {
      return;
    }
    DAT_20800470 = FUN_20120fe4();
    break;
  case 5:
    DAT_20800470 = FUN_20120fe4();
    if (DAT_20800470 == -1) {
      return;
    }
    FUN_20120e9c(1,DAT_20800470,0);
  case 1:
    uVar1 = 0;
    goto LAB_201210b8;
  case 6:
    DAT_20800470 = FUN_20120fe4();
    if (DAT_20800470 != -1) {
      FUN_20120e9c(0,DAT_20800470);
      FUN_20120e9c(1,DAT_20800470,0);
      FUN_20120e9c(0,DAT_20800470);
      return;
    }
    goto switchD_20121064_caseD_0;
  }
  uVar1 = 1;
LAB_201210b8:
  FUN_20120e9c(uVar1,DAT_20800470,0);
switchD_20121064_caseD_0:
  return;
}


// ===== FUN_20121160 @ 20121160 (352 bytes)

undefined4 FUN_20121160(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff;
  if (DAT_208f0b2a == 0x40) {
    uVar1 = 0x12d;
  }
  else if (DAT_208f0b2a < 0x41) {
    if (DAT_208f0b2a == 0x37) {
      uVar1 = 0xf2;
    }
    else if (DAT_208f0b2a < 0x38) {
      if (DAT_208f0b2a == 0x20) {
        if (DAT_208f0b4d < '\0') {
          uVar1 = 0x310;
        }
        else {
          uVar1 = 0x130f;
        }
        return uVar1;
      }
      if (DAT_208f0b2a == 0x30) {
        switch(DAT_208f0bc2) {
        case 0:
          return 0x10;
        case 1:
          return 0x1a;
        case 2:
          return 0x1b;
        case 3:
          return 0x1c;
        case 4:
          return 0x1d;
        case 5:
          return 0x30c;
        case 6:
          return 6;
        case 7:
          goto switchD_20121250_caseD_7;
        case 8:
          return 0xbe;
        case 9:
          return 0x19;
        case 10:
          return 0x18;
        case 0xb:
          return 0x56;
        case 0xc:
          return 0x30b;
        case 0xd:
          return 7;
        default:
          return 0xffff;
        }
      }
      if (DAT_208f0b2a == 0x34) {
        uVar1 = 0x199;
      }
    }
    else {
      if (DAT_208f0b2a != 0x39) {
        if (DAT_208f0b2a == 0x3a) {
          uVar1 = 0x11b;
        }
        return uVar1;
      }
      uVar1 = 0x90;
    }
  }
  else if (DAT_208f0b2a == 0x50) {
    uVar1 = 0x284;
  }
  else if (DAT_208f0b2a < 0x51) {
    if (DAT_208f0b2a == 0x41) {
      uVar1 = 0x109;
    }
    else if (DAT_208f0b2a == 0x43) {
      switch(DAT_208f0d6a) {
      case 0x41:
      case 0x43:
        return 0x159;
      case 0x42:
      case 0x44:
        return 0x149;
      case 0x45:
        return 0x170;
      case 0x46:
      case 0x47:
        break;
      case 0x48:
        return 0x181;
      default:
        return 0xffff;
      }
    }
  }
  else {
    if (DAT_208f0b2a != 0x70) {
      if (DAT_208f0b2a == 0x7c) {
        uVar1 = 0x30f;
      }
      return uVar1;
    }
    uVar1 = 0xff;
  }
switchD_20121250_caseD_7:
  return uVar1;
}


// ===== FUN_20121318 @ 20121318 (372 bytes)

void FUN_20121318(void)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined1 local_1c [12];
  
  local_20 = 0xe5;
  FUN_201023bc(local_1c);
  switch(local_1c[0]) {
  default:
    goto switchD_20121348_caseD_0;
  case 2:
    DAT_2080046e = FUN_20121160();
    if (DAT_2080046e == -1) {
      return;
    }
    break;
  case 4:
    FUN_20120e9c(0,DAT_2080046e);
    if (DAT_2080046e == -1) {
      return;
    }
    DAT_2080046e = FUN_20121160();
    break;
  case 5:
    DAT_2080046e = FUN_20121160();
    if (DAT_2080046e == -1) {
      return;
    }
    if (DAT_208f0b2a == '|') {
      mainlink_queue_frame(&local_20,4);
    }
    else {
      FUN_20120e9c(1,DAT_2080046e,0);
    }
  case 1:
    uVar1 = 0;
    goto LAB_201213bc;
  case 6:
    DAT_2080046e = FUN_20121160();
    if (DAT_2080046e != -1) {
      FUN_20120e9c(0,DAT_2080046e);
      if (DAT_208f0b2a == '|') {
        mainlink_queue_frame(&local_20,4);
      }
      else {
        FUN_20120e9c(1,DAT_2080046e,0);
      }
      FUN_20120e9c(0,DAT_2080046e);
      return;
    }
    goto switchD_20121348_caseD_0;
  }
  if (DAT_208f0b2a != '|') {
    uVar1 = 1;
LAB_201213bc:
    FUN_20120e9c(uVar1,DAT_2080046e,0);
    return;
  }
  mainlink_queue_frame(&local_20,4);
switchD_20121348_caseD_0:
  return;
}


// ===== FUN_201214b0 @ 201214b0 (740 bytes)

void FUN_201214b0(int param_1)

{
  short sVar1;
  short sVar2;
  short local_30 [2];
  short local_2c [2];
  undefined1 local_28 [4];
  uint local_24;
  uint local_20;
  
  local_30[0] = 0;
  local_2c[0] = 0;
  FUN_20102138(local_28,param_1);
  sVar1 = (short)local_24;
  sVar2 = (short)local_20;
  if (param_1 != 0) {
    FUN_20103060((int)(short)local_24,(int)(short)local_20,local_30,local_2c);
    sVar1 = local_30[0];
    sVar2 = local_2c[0];
  }
  local_2c[0] = sVar2;
  local_30[0] = sVar1;
  switch(local_28[0]) {
  default:
    goto switchD_20121518_caseD_0;
  case 1:
    if (((DAT_2080046c & 0x1000) == 0) && (DAT_2080046c != 0x1ff)) {
      return;
    }
    FUN_20120e9c(0,DAT_2080046c);
    return;
  case 2:
    if (param_1 != 0) {
      FUN_20130768(local_24 & 0xffff,local_20 & 0xffff);
    }
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      FUN_20120e9c(1,DAT_2080046c,(int)local_30[0]);
    }
    break;
  case 3:
    DAT_2080047c = DAT_2080047c + 1;
    return;
  case 4:
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      FUN_20120e9c(0,DAT_2080046c);
    }
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      FUN_20120e9c(1,DAT_2080046c,(int)local_30[0]);
    }
    break;
  case 5:
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      FUN_20120e9c(1,DAT_2080046c,(int)local_30[0]);
      FUN_20120e9c(0,DAT_2080046c);
    }
    break;
  case 6:
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      FUN_20120e9c(0,DAT_2080046c);
    }
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      FUN_20120e9c(1,DAT_2080046c,(int)local_30[0]);
      FUN_20120e9c(0,DAT_2080046c);
    }
    if (param_1 == 0) {
      return;
    }
    goto LAB_201215e0;
  }
  if (param_1 != 0) {
LAB_201215e0:
    FUN_20113f38(local_30[0],local_2c[0]);
    return;
  }
switchD_20121518_caseD_0:
  return;
}


// ===== FUN_201217b0 @ 201217b0 (128 bytes)

void FUN_201217b0(void)

{
  undefined4 in_r3;
  undefined4 local_8;
  
  local_8 = in_r3;
  FUN_20120de4();
  local_8 = 0;
  if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
    local_8 = 0xe4;
    if (DAT_20800487 != '\0') {
      DAT_20800487 = 0;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_8,4);
      return;
    }
  }
  FUN_201214b0(0);
  FUN_201214b0(1);
  FUN_20121318();
  FUN_20121044();
  return;
}


// ===== FUN_20121830 @ 20121830 (40 bytes)

void FUN_20121830(undefined1 param_1)

{
  undefined4 local_8;
  
  local_8 = (uint)CONCAT11(param_1,0xe6);
  mainlink_queue_frame(&local_8,4);
  return;
}


// ===== FUN_20121858 @ 20121858 (64 bytes)

void FUN_20121858(undefined1 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10._0_2_ = CONCAT11(param_1,0xe0);
  local_10 = CONCAT13((char)param_2,CONCAT12((char)((uint)param_2 >> 8),(undefined2)local_10)) &
             0xffefffff;
  mainlink_queue_frame(&local_10,5);
  return;
}


// ===== FUN_201218a4 @ 201218a4 (168 bytes)

void FUN_201218a4(void)

{
  undefined2 local_18 [2];
  undefined2 local_14 [2];
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  FUN_20113f60(local_14,local_18);
  FUN_20132680(&local_10,0,local_14[0],local_18[0]);
  DAT_20808584 = local_10;
  DAT_20808586 = local_e;
  DAT_20808588 = local_c;
  DAT_2080858a = local_a;
  FUN_20117e5c(0,6,&DAT_208f4d70);
  FUN_20132680(&local_10,1,local_14[0],local_18[0]);
  DAT_20808584 = local_10;
  DAT_20808586 = local_e;
  DAT_20808588 = local_c;
  DAT_2080858a = local_a;
  FUN_20117e5c(1,6,&DAT_208f4d70);
  return;
}


// ===== FUN_2012194c @ 2012194c (40 bytes)

void FUN_2012194c(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x9a) & 0x1f;
  if (0x14 < uVar1) {
    uVar1 = 0x14;
  }
  DAT_20800328 = (uVar1 - 10) * 10;
  return;
}


// ===== FUN_20121988 @ 20121988 (48 bytes)

int FUN_20121988(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_201219b8 @ 201219b8 (312 bytes)

void FUN_201219b8(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  fb_fill_rect(param_1,0x821,param_2,param_3,0xce,0x10);
  FUN_20135ad8(param_1,param_2 + 2U & 0xffff,param_3,0xc,1,0x4a69);
  FUN_20135ad8(param_1,param_2 + 2U & 0xffff,param_3 + 0xcdU & 0xffff,0xc,1,0x4a69);
  FUN_20135aa4(param_1,param_2,param_3 + 2U & 0xffff,0xca,1,0x4a69);
  FUN_20135aa4(param_1,param_2 + 0xfU & 0xffff,param_3 + 2U & 0xffff,0xca,1,0x4a69);
  gui_draw_runs(param_1,param_2,param_3,&DAT_2016e258);
  uVar1 = 0;
  if (100 < param_4) {
    param_4 = 100;
  }
  if ((param_4 & 0x7fffffff) != 0) {
    do {
      FUN_20135534(param_1,(uint)DAT_208006fe + param_2 & 0xffff,
                   (uint)DAT_208006fc + param_3 + uVar1 & 0xffff,&DAT_2016e268,1,10);
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < param_4 << 1);
  }
  return;
}


// ===== FUN_20121af0 @ 20121af0 (160 bytes)

void FUN_20121af0(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  byte local_f0 [204];
  
  param_2 = param_2 * 800;
  iVar2 = FUN_20120d84(local_f0);
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = 0;
      sVar1 = (&DAT_2016d390)[iVar6];
      if (param_3 < param_4 + param_3) {
        iVar5 = param_3;
        do {
          if ((iVar2 - iVar6 <= (int)(uint)local_f0[iVar3]) &&
             (psVar4 = (short *)(param_1 + (iVar5 + param_2) * 2), *psVar4 == 0)) {
            *psVar4 = sVar1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar5 < param_4 + param_3);
      }
      iVar6 = iVar6 + 1;
      param_2 = param_2 + 800;
    } while (iVar6 < iVar2);
  }
  return;
}


// ===== FUN_20121b90 @ 20121b90 (172 bytes)

void FUN_20121b90(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar1 = *param_4;
  iVar4 = 0;
  uVar5 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      uVar3 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4 + 2);
      uVar6 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4);
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1;
        uVar7 = __aeabi_uidivmod(uVar6,uVar1);
        psVar2 = (short *)(param_1 + (param_3 + param_2 * 800) * 2 +
                          (int)((ulonglong)uVar7 >> 0x20) * 2 + (int)uVar7 * 0x640);
        if (*psVar2 == 0) {
          *psVar2 = *(short *)(*(int *)(param_4 + 6) + iVar4 * 2);
        }
        iVar4 = iVar4 + 1;
        uVar6 = uVar6 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== FUN_20121c3c @ 20121c3c (196 bytes)

void FUN_20121c3c(void)

{
  short sVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_208004ca == 0) {
    FUN_20155274(uVar2,0xbb800);
    FUN_20133a0c(3);
    FUN_20133a0c(4);
    FUN_20133a0c(6);
    FUN_2013396c(5,1);
    gui_draw_runs(uVar2,*(undefined2 *)(&DAT_20800842 + (uint)DAT_208004cc * 4),
                  *(undefined2 *)(&DAT_20800840 + (uint)DAT_208004cc * 4),&DAT_2016d2c0);
    DAT_208004cc = (ushort)(DAT_208004cc + 1) % 3;
    DAT_208004ca = 0xb4;
  }
  else {
    sVar1 = DAT_208004ca + -1;
    bVar3 = DAT_208004ca == 0x5b;
    DAT_208004ca = sVar1;
    if (bVar3) {
      FUN_2013396c(5,0);
      return;
    }
  }
  return;
}


// ===== FUN_20121d00 @ 20121d00 (96 bytes)

void FUN_20121d00(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
  iVar1 = FUN_20103ba0();
  if ((DAT_208007d0 != iVar1) || (DAT_20800486 == '\0')) {
    local_18._0_2_ = CONCAT11((char)iVar1,(undefined1)local_18);
    mainlink_queue_frame(&local_18,6);
    DAT_20800486 = '\x01';
    DAT_208007d0 = iVar1;
  }
  return;
}


// ===== FUN_20121d90 @ 20121d90 (248 bytes)

void FUN_20121d90(void)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28 [4];
  byte local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 auStack_14 [8];
  
  local_30 = 0xe3;
  local_2c = 0;
  if (DAT_208f0b2a == '{') {
    if (DAT_208f0b2b != '\0') {
      DAT_208004c8 = 9;
      return;
    }
  }
  else if (DAT_208f0b2a == '#') {
    DAT_208004c8 = 9;
    return;
  }
  if (DAT_208004c8 == 0) {
    FUN_2011459c(local_28,local_24,auStack_14);
    iVar1 = (short)(ushort)(((uint)local_28[0] << 0x1a) >> 0x1e) * 600 + (local_28[0] & 0xf) * 0x3c
            + (uint)local_24[0];
    if (iVar1 != DAT_208004c6) {
      DAT_208004c6 = (short)iVar1;
      FUN_20114528(local_20,local_1c,local_18);
      local_30 = CONCAT13(local_18[0],
                          CONCAT12(local_1c[0],CONCAT11(local_20[0],(undefined1)local_30)));
      local_2c._0_2_ = CONCAT11(local_24[0],local_28[0]);
      mainlink_queue_frame(&local_30,8);
    }
    DAT_208004c8 = 9;
    return;
  }
  DAT_208004c8 = DAT_208004c8 + -1;
  return;
}


// ===== FUN_20121e88 @ 20121e88 (1600 bytes)

void FUN_20121e88(void)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  byte local_260 [12];
  byte local_254;
  byte local_252;
  byte local_251;
  byte local_24f;
  byte local_24e;
  byte local_200;
  char local_1c8;
  
  uVar2 = fb_get_layer_addr(DAT_208085b8);
  FUN_20115000(local_260);
  cVar1 = DAT_208f0b2a;
  if (((DAT_208f0b2a == 'p') && (local_260[0] == 0x30)) && (local_1c8 == -1)) {
    return;
  }
  if (local_260[0] != 100) {
    if (local_260[0] < 0x65) {
      if (local_260[0] != 0x3a) {
        if (local_260[0] < 0x3b) {
          if (local_260[0] != 0x21 && local_260[0] != 0x23) goto LAB_20121f38;
        }
        else if (local_260[0] != 0x3f && local_260[0] != 0x60) goto LAB_20121f38;
      }
    }
    else if ((local_260[0] != 0x65 && local_260[0] != 0x7a) &&
            (local_260[0] != 0x7b && local_260[0] != 0x7c)) goto LAB_20121f38;
  }
  memcpy(local_260,&DAT_208f0d8b,0x240);
LAB_20121f38:
  if ((DAT_208f4634 == '\0') && ((DAT_208f4633 == '\0' || (cVar1 != '7')))) {
    if ((local_260[0] == 0x20 || local_260[0] == 0x37) || local_260[0] == 0x39) {
      fb_copy_rect(uVar2,DAT_2080065e,DAT_2080065c,0x30,0x13);
      bVar4 = local_251 & 0xc0;
      if (bVar4 == 0x40) {
        gui_draw_runs(uVar2,DAT_20800662,DAT_20800660,&DAT_2016ddfc);
      }
      else if (bVar4 == 0x80) {
        gui_draw_runs(uVar2,DAT_20800662,DAT_20800660,&DAT_2016dddc);
      }
      else if (bVar4 == 0xc0) {
        gui_draw_runs(uVar2,DAT_2080065e,DAT_2080065c,&DAT_2016de0c);
      }
    }
    bVar4 = local_200 & 3;
    fb_copy_rect(uVar2,DAT_20800666,DAT_20800664,0x2c,0x13);
    if (bVar4 == 1) {
      gui_draw_runs(uVar2,DAT_20800666,DAT_20800664,&DAT_2016de8c);
    }
    else if (bVar4 == 2) {
      gui_draw_runs(uVar2,DAT_20800666,DAT_20800664,&DAT_2016de7c);
    }
    uVar3 = (uint)local_200;
    fb_copy_rect(uVar2,DAT_2080066a,DAT_20800668,0x16,0x13);
    if ((int)(uVar3 << 0x1c) < 0) {
      gui_draw_runs(uVar2,DAT_2080066a,DAT_20800668,&DAT_2016deac);
    }
    uVar3 = (uint)local_200;
    fb_copy_rect(uVar2,DAT_2080066e,DAT_2080066c,0x22,0x13);
    if ((int)(uVar3 << 0x1b) < 0) {
      gui_draw_runs(uVar2,DAT_2080066e,DAT_2080066c,&DAT_2016de6c);
    }
    fb_copy_rect(uVar2,DAT_20800672,DAT_20800670,0x2c,0xf);
    if ((int)((uint)local_200 << 0x1d) < 0) {
      gui_draw_runs(uVar2,DAT_20800672,DAT_20800670,&DAT_2016de9c);
    }
    if ((DAT_208f4631 == '\0') && (DAT_208f4632 == '\0')) {
      if (DAT_208f4630 == '\0') {
        uVar5 = 0xb4;
      }
      else {
        uVar5 = 0x6d;
      }
      bVar4 = local_252 & 3;
      fb_copy_rect(uVar2,uVar5,DAT_208004b2,0x11,0x11);
      if (bVar4 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b2,&DAT_2016de1c);
      }
      else if (bVar4 == 3) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b2,&DAT_2016de2c);
      }
      bVar4 = local_251 & 3;
      fb_copy_rect(uVar2,uVar5,DAT_208004b4,0x22,0x13);
      if (bVar4 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b4,&DAT_2016ddac);
      }
      else if (bVar4 == 2) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b4,&DAT_2016de3c);
      }
      uVar3 = (uint)local_252;
      fb_copy_rect(uVar2,uVar5,DAT_208004b0,0x2d,0x13);
      if ((int)(uVar3 << 0x1d) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b0,&DAT_2016dd8c);
      }
      uVar3 = (uint)local_252;
      fb_copy_rect(uVar2,uVar5,DAT_208004ac,0x28,0x13);
      if ((int)(uVar3 << 0x1b) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ac,&DAT_2016ddcc);
      }
      fb_copy_rect(uVar2,uVar5,DAT_208004b6,0x22,0x13);
      if ((int)((uint)local_254 << 0x1b) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b6,&DAT_2016dd9c);
      }
      uVar3 = (uint)local_252;
      fb_copy_rect(uVar2,uVar5,DAT_208004a8,0x2e,0x13);
      if ((int)(uVar3 << 0x19) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004a8,&DAT_2016ddec);
      }
      fb_copy_rect(uVar2,uVar5,DAT_208004aa,0x39,0x13);
      if ((int)((uint)local_252 << 0x1a) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004aa,&DAT_2016ddbc);
      }
      uVar3 = (local_251 & 0x1f) >> 3;
      fb_copy_rect(uVar2,uVar5,DAT_208004ae,0x2d,0x13);
      if (uVar3 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ae,&DAT_2016de4c);
      }
      else if (uVar3 == 2) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ae,&DAT_2016de5c);
      }
      if (DAT_208f4633 == '\0') {
        uVar3 = (uint)(local_24f >> 6);
        fb_copy_rect(uVar2,uVar5,DAT_208004b8,*DAT_208025e4,DAT_208025e4[1]);
        if (2 < uVar3) {
          uVar3 = 2;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004b8,(&DAT_208025e4)[uVar3]);
        uVar3 = (uint)(local_24e >> 4);
        fb_copy_rect(uVar2,uVar5,DAT_208004ba,*(undefined2 *)PTR_DAT_208025f0,
                     *(undefined2 *)(PTR_DAT_208025f0 + 2));
        if (5 < uVar3) {
          uVar3 = 5;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004ba,(&PTR_DAT_208025f0)[uVar3]);
        uVar3 = local_24f & 0x1f;
        fb_copy_rect(uVar2,uVar5,DAT_208004bc,0x2d,0x13);
        fb_copy_rect(uVar2,uVar5,DAT_208004be,*(undefined2 *)PTR_DAT_20802608,
                     *(undefined2 *)(PTR_DAT_20802608 + 2));
        gui_draw_runs(uVar2,uVar5,DAT_208004bc,&DAT_2016debc);
        if (9 < uVar3) {
          uVar3 = 9;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004be,(&PTR_DAT_20802608)[uVar3]);
      }
    }
    memcpy(&DAT_208f0d8b,local_260,0x240);
  }
  return;
}


// ===== FUN_201224c8 @ 201224c8 (160 bytes)

void FUN_201224c8(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
  case 0xe:
    sVar3 = DAT_208007e4 + 0x1bb;
    sVar1 = DAT_208007e6 + 0x1bb;
    FUN_20121b90(param_1,0x81,DAT_208007e4 + 0x1b1,&DAT_2016d66c);
    FUN_20121b90(param_1,0x81,sVar1,&DAT_2016d67c);
    uVar2 = 0;
    if (sVar1 != sVar3) {
      do {
        FUN_20121b90(param_1,0x81,sVar3 + uVar2,&DAT_2016d65c);
        uVar2 = uVar2 + 1;
      } while (uVar2 < (ushort)(sVar1 - sVar3));
      return;
    }
  }
  return;
}


// ===== FUN_20122638 @ 20122638 (356 bytes)

void FUN_20122638(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
  case 0xe:
    break;
  default:
    if (param_4 != 0) {
      return;
    }
  }
  iVar1 = (int)(short)param_3 / 0x14;
  uVar2 = (uint)DAT_208007de + iVar1 + 0x1bb & 0xffff;
  uVar3 = iVar1 + (uint)DAT_208007e0 + 0x1bb & 0xffff;
  uVar4 = uVar2 - 0xb & 0xffff;
  uVar5 = uVar3 + 0xb & 0xffff;
  puVar6 = &DAT_2016d428;
  if (0 < (int)(uVar4 - 0x1bd)) {
    FUN_20136670(param_1,0xac,0x1bd,uVar4 - 0x1bd & 0xffff,2,0xffff,&DAT_2016d428,param_1,param_2,
                 param_3,param_4);
  }
  if (uVar4 - 0x1bd < 0x161) {
    FUN_20121b90(param_1,0x7f,uVar4,puVar6);
  }
  else {
    uVar2 = 0x1bd;
  }
  if (uVar3 - 0x1b1 < 0x161) {
    FUN_20121b90(param_1,0x7f,uVar3,&DAT_2016d438);
  }
  else {
    uVar3 = 0x31d;
  }
  if (uVar2 - 0x1bd < 0x161) {
    FUN_20136670(param_1,0x7f,uVar2,uVar3 - uVar2 & 0xffff,2,0xffff,puVar6,param_1,param_2,param_3,
                 param_4);
  }
  uVar2 = 0x31d - uVar5;
  if (0 < (int)uVar2) {
    FUN_20136670(param_1,0xac,uVar5,uVar2 & 0xffff,2,0xffff,puVar6,param_1,param_2,param_3,param_4);
  }
  return;
}


// ===== FUN_201227d8 @ 201227d8 (820 bytes)

void FUN_201227d8(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar6;
  int iVar7;
  
  bVar2 = false;
  iVar7 = 0;
  uVar3 = (uint)DAT_208f0b92;
  bVar1 = DAT_208f0b92 >> 7;
  uVar6 = (DAT_208f0b93 & 0x3f) >> 4;
  iVar5 = (uint)DAT_208f0b4c * 10;
  uVar4 = FUN_20135470(&DAT_208f0b9d);
  uVar4 = uVar4 & 0xffff;
  if (2 < uVar6) {
    uVar6 = 2;
  }
  if (3000 < uVar4) {
    uVar4 = 3000;
  }
  switch(param_2) {
  default:
    if (iVar7 == 0) goto LAB_20122aec;
    break;
  case 2:
  case 3:
    unaff_r7 = (uint)(iVar5 * 10) / 200 + 0x4e & 0xffff | 0x6f0000;
    break;
  case 8:
  case 9:
    uVar3 = (uVar4 * 10) / 200 + 0x4e;
    goto LAB_20122a4c;
  case 0xc:
    iVar7 = (int)*(short *)(&DAT_2016d288 + (uint)bVar1 * 2);
    iVar5 = iVar7 + *(short *)(&DAT_2016d29e + (uVar3 & 3) * 2);
    goto LAB_20122aa0;
  case 0xd:
    iVar7 = (int)*(short *)(&DAT_2016d288 + (uint)bVar1 * 2);
    iVar5 = *(short *)(&DAT_2016d29e + (uVar3 & 3) * 2) + iVar7;
LAB_20122aa0:
    uVar3 = (iVar7 * 10) / 200 + 0x4eU & 0xffff;
    bVar2 = true;
    unaff_r6 = (iVar5 * 10) / 200 + 0x4eU & 0xffff | 0x6f0000;
    gui_draw_runs(param_1,0x6f,uVar3 + 0x1af & 0xffff,&DAT_2016d458);
    FUN_20135aa4(param_1,0x7e,uVar3 + 0x1bb & 0xffff,1,0x30,0xfc00);
    goto LAB_20122aec;
  case 0xe:
    uVar3 = (*(short *)(&DAT_2016d298 + uVar6 * 2) * 10) / 200 + 0x4eU & 0xffff;
LAB_20122a4c:
    gui_draw_runs(param_1,0x6f,uVar3 + 0x1b4 & 0xffff,&DAT_2016d448);
    FUN_20135aa4(param_1,0x7e,uVar3 + 0x1bb & 0xffff,1,0x30,0xfc00);
    goto LAB_20122aec;
  }
  gui_draw_runs(param_1,unaff_r7 >> 0x10,unaff_r7 + 0x1b4 & 0xffff,&DAT_2016d468);
  FUN_20135aa4(param_1,(unaff_r7 >> 0x10) + 0xf & 0xffff,unaff_r7 + 0x1bb & 0xffff,1,0x30,0xfc00);
LAB_20122aec:
  if (bVar2) {
    gui_draw_runs(param_1,unaff_r6 >> 0x10,unaff_r6 + 0x1b9 & 0xffff,&DAT_2016d478);
    FUN_20135aa4(param_1,(unaff_r6 >> 0x10) + 0xf & 0xffff,unaff_r6 + 0x1bb & 0xffff,1,0x30,0xffe0);
  }
  return;
}

