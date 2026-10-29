// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2015c2d4 @ 2015c2d4 (112 bytes)

bool FUN_2015c2d4(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  memcpy(&local_20,(param_1 - 0x1128U & 0xff) * 0x2d + 0x208f0c46,0x15);
  iVar1 = strcmp("FIRMWARE UPDATE      ",&local_20);
  return iVar1 == 0;
}


// ===== FUN_2015c34c @ 2015c34c (224 bytes)

int FUN_2015c34c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_2015c978();
  if (iVar1 == 0x1ff) {
    iVar1 = FUN_2015ccf8(param_1,param_2,&DAT_202665ec,1);
  }
  if (iVar1 == 0x1ff) {
    iVar1 = FUN_2015ccf8(param_1,param_2,&DAT_202665ec,3);
  }
  if ((((iVar1 == 0x1ff) && (iVar1 = FUN_2015cdd4(param_1,param_2), iVar1 != 0x1ff)) &&
      (iVar2 = FUN_2015c278(), iVar2 != 0)) &&
     ((iVar2 = FUN_2015c2d4(iVar1), iVar2 != 0 && (DAT_208000b2 == '\0')))) {
    DAT_20800494 = 1;
  }
  if (iVar1 == 0x1ff) {
    iVar1 = FUN_2015bf88(param_1,param_2,&DAT_202665d8,2);
  }
  if (iVar1 == 0x1ff) {
    iVar1 = 0xff;
  }
  return iVar1;
}


// ===== FUN_2015c43c @ 2015c43c (376 bytes)

undefined4 FUN_2015c43c(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016dd44,7);
    return uVar1;
  case 1:
  case 2:
  case 3:
  case 4:
    break;
  case 5:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016e734,0x11);
    return uVar1;
  case 6:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016e6a4,0xb);
    return uVar1;
  case 7:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016da0c,0x10);
    return uVar1;
  case 8:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2024bc94,0x10);
    return uVar1;
  case 9:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016d358,4);
    return uVar1;
  case 10:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016dffc,0xd);
    return uVar1;
  case 0xb:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016e530,0xd);
    return uVar1;
  case 0xc:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016ea38,0xd);
    return uVar1;
  case 0xd:
    uVar1 = FUN_2015bf88(param_1,param_2,&DAT_2016ed68,7);
    return uVar1;
  default:
    return 0x1ff;
  }
  uVar1 = 0x1ff;
  if (param_3 == 1) {
    uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3a0,4,DAT_208f0bc3,DAT_208f0bc4);
    return uVar1;
  }
  if (param_3 != 2) {
    if (param_3 == 3) {
      uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca418,2,DAT_208f0bc3,DAT_208f0bc4);
      return uVar1;
    }
    if (param_3 == 4) {
      uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3e6,5,DAT_208f0bc3,DAT_208f0bc4);
    }
    return uVar1;
  }
  uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3c8,3,DAT_208f0bc3,DAT_208f0bc4);
  return uVar1;
}


// ===== FUN_2015c558 @ 2015c558 (304 bytes)

undefined4 FUN_2015c558(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  bVar3 = DAT_208f0b2b;
  if (1 < DAT_208f0b2b) {
    bVar3 = 1;
  }
  iVar1 = (int)((uint)DAT_208f0b2f << 0x1a) >> 0x1f;
  if (bVar3 == 0) {
    if ((DAT_208f0b2d & 4) == 0) {
      switch(DAT_208f0b2c) {
      case 0:
      case 1:
      case 2:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302c8a + iVar1 * -0x50,4);
        return uVar2;
      case 3:
      case 6:
      case 9:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302dca + iVar1 * -0x3c,2);
        return uVar2;
      case 4:
      case 7:
      case 10:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302dde + iVar1 * -0x3c,2);
        return uVar2;
      case 5:
      case 8:
      case 0xb:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302df2 + iVar1 * -0x3c,2);
        return uVar2;
      default:
        return 0x1ff;
      }
    }
  }
  else {
    if (bVar3 != 1) {
      return 0x1ff;
    }
    if ((DAT_208f0b2d & 4) == 0) {
      switch(DAT_208f0b2c) {
      case 0:
      case 1:
      case 2:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302cb2 + iVar1 * -0x50,4);
        return uVar2;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
        uVar2 = FUN_2015bf88(param_1,param_2,&UNK_20302d52 + iVar1 * -0x50,4);
        return uVar2;
      default:
        return 0x1ff;
      }
    }
  }
  uVar2 = FUN_2015c81c(param_1,param_2,&DAT_203a53d4,2);
  return uVar2;
}


// ===== FUN_2015c6fc @ 2015c6fc (84 bytes)

ushort FUN_2015c6fc(uint param_1,uint param_2,ushort *param_3,int param_4)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = (uint)*param_3;
  uVar2 = 0x1ff;
  uVar4 = (uint)param_3[1];
  uVar3 = param_3[3] + uVar4;
  if (param_4 == 1) {
    uVar4 = 0;
  }
  bVar5 = param_1 <= uVar1;
  if (uVar1 <= param_1) {
    bVar5 = (param_3[2] + uVar1 & 0xffff) <= param_1;
  }
  if (!bVar5) {
    bVar5 = param_2 <= uVar4;
    if (uVar4 <= param_2) {
      bVar5 = (uVar3 & 0xffff) <= param_2;
    }
    if (!bVar5) {
      uVar2 = param_3[4];
    }
  }
  return uVar2;
}


// ===== FUN_2015c750 @ 2015c750 (500 bytes)

int FUN_2015c750(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  switch(DAT_208f0d6a) {
  case 0x41:
  case 0x43:
    if (DAT_208f0d6b != '\x10') {
      iVar2 = FUN_2015bf88(param_1,param_2,&DAT_2026668c,10);
      return iVar2;
    }
    break;
  case 0x42:
  case 0x44:
    if (DAT_208f0d6b != '\x04' && DAT_208f0d6b != '\x10') {
      iVar2 = FUN_2015bf88(param_1,param_2,&DAT_20266628,10);
      return iVar2;
    }
    break;
  case 0x45:
    iVar2 = FUN_2015bf88(param_1,param_2,&DAT_202666f0,3);
    return iVar2;
  default:
    return 0x1ff;
  case 0x47:
    iVar2 = 0x1ff;
    if (DAT_208f0d6b == '\x01') {
      uVar3 = 0;
      do {
        uVar5 = uVar3 * 0x44 + 0x32;
        bVar6 = param_1 < 0x76;
        if (0x74 < param_1) {
          bVar6 = 0xec < param_1;
        }
        uVar4 = uVar3 * 0x44 + 0x75;
        if (!bVar6) {
          uVar1 = uVar5;
          if (uVar5 <= param_2) {
            uVar1 = uVar4;
          }
          if ((uVar5 <= param_2 && param_2 <= uVar4) && param_2 != uVar1) {
            iVar2 = uVar3 + 0x1160;
            break;
          }
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 4);
    }
    else {
      iVar2 = 0x1ff;
      if (DAT_208f0d6b != '\x02') goto LAB_2015d19c;
    }
    if (iVar2 == 0x1ff) {
      bVar6 = param_1 < 0xfb;
      uVar3 = DAT_20802294[1] + 0x19a & 0xffff;
      if (0xf9 < param_1) {
        bVar6 = (*DAT_20802294 + 0xfa & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar5 = 0x19a;
        if (0x199 < param_2) {
          uVar5 = uVar3;
        }
        if ((0x199 < param_2 && param_2 <= uVar3) && param_2 != uVar5) {
          if (DAT_208f0d6b == '\x01') {
            iVar2 = 0x1165;
          }
          else {
            iVar2 = 0x116a;
          }
          return iVar2;
        }
      }
    }
    if (iVar2 == 0x1ff) {
      bVar6 = param_1 < 0x1a5;
      uVar3 = DAT_20802294[1] + 0x19a & 0xffff;
      if (0x1a3 < param_1) {
        bVar6 = (*DAT_20802294 + 0x1a4 & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar5 = 0x19a;
        if (0x199 < param_2) {
          uVar5 = uVar3;
        }
        if ((0x199 < param_2 && param_2 <= uVar3) && param_2 != uVar5) {
          if (DAT_208f0d6b == '\x01') {
            iVar2 = 0x1166;
          }
          else {
            iVar2 = 0x116b;
          }
          return iVar2;
        }
      }
    }
LAB_2015d19c:
    if (iVar2 == 0x1ff) {
      iVar2 = 0xff;
    }
    return iVar2;
  case 0x48:
    iVar2 = FUN_2015bf88(param_1,param_2,&DAT_2026670e,3);
    return iVar2;
  }
  iVar2 = FUN_2015bf88(param_1,param_2,&DAT_2026672c,1);
  return iVar2;
}


// ===== FUN_2015c81c @ 2015c81c (344 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_2015c81c(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  ushort *puVar8;
  bool bVar9;
  
  sVar6 = 0x1ff;
  if (_DAT_208f4bf0 == _DAT_208f4bf2) {
    return 0x1ff;
  }
  _DAT_208f4bf2 = _DAT_208f4bf0;
  uVar7 = 0;
  if (param_4 < 1) goto LAB_2015c958;
  do {
    puVar8 = (ushort *)(param_3 + uVar7 * 10);
    uVar5 = (uint)*puVar8;
    bVar9 = param_1 <= uVar5;
    uVar4 = (uint)puVar8[1];
    if (uVar5 <= param_1) {
      bVar9 = (puVar8[2] + uVar5 & 0xffff) <= param_1;
    }
    uVar5 = puVar8[3] + uVar4 & 0xffff;
    if (!bVar9) {
      uVar1 = uVar4;
      if (uVar4 <= param_2) {
        uVar1 = uVar5;
      }
      if ((uVar4 <= param_2 && param_2 <= uVar5) && param_2 != uVar1) {
        sVar6 = *(short *)(param_3 + uVar7 * 10 + 8);
        break;
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while ((int)uVar7 < param_4);
  if (sVar6 == 0x16c) {
    if (DAT_208f4bef == '\0') goto LAB_2015c950;
    if ((uint)DAT_208f4899 <= (uint)DAT_208f489c) {
      mainlink_send_e6(2);
      goto LAB_2015c958;
    }
    iVar3 = (uint)DAT_208f4899 - (uint)DAT_208f489c;
    if (iVar3 <= (int)(uint)DAT_208f489e) {
      DAT_208f489e = (byte)iVar3;
      mainlink_send_e6(2);
      goto LAB_2015c958;
    }
    DAT_208f489e = DAT_208f489e + 1;
    uVar2 = 0;
  }
  else {
    if (sVar6 != 0x16d) goto LAB_2015c958;
    if (DAT_208f489e != 0) {
      mainlink_send_e6(0);
      DAT_208f489e = DAT_208f489e - 1;
      goto LAB_2015c958;
    }
LAB_2015c950:
    uVar2 = 2;
  }
  mainlink_send_e6(uVar2);
LAB_2015c958:
  if (0xf < DAT_208f489e) {
    DAT_208f489e = 0xf;
  }
  return 0x1ff;
}


// ===== FUN_2015c978 @ 2015c978 (144 bytes)

undefined2 FUN_2015c978(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  bool bVar7;
  
  puVar5 = &DAT_2016dc78;
  uVar2 = 0;
  if (DAT_208f0bc2 == '\x01') {
    puVar5 = &DAT_20266588;
  }
  do {
    puVar3 = puVar5 + uVar2 * 5;
    uVar4 = (uint)*puVar3;
    bVar7 = param_1 <= uVar4;
    uVar6 = (uint)puVar3[1];
    if (uVar4 <= param_1) {
      bVar7 = (puVar3[2] + uVar4 & 0xffff) <= param_1;
    }
    uVar4 = puVar3[3] + uVar6 & 0xffff;
    if (!bVar7) {
      uVar1 = uVar6;
      if (uVar6 <= param_2) {
        uVar1 = uVar4;
      }
      if ((uVar6 <= param_2 && param_2 <= uVar4) && param_2 != uVar1) {
        return puVar5[uVar2 * 5 + 4];
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
    if (7 < uVar2) {
      return 0x1ff;
    }
  } while( true );
}


// ===== FUN_2015ca14 @ 2015ca14 (244 bytes)

int FUN_2015ca14(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  iVar7 = 0x1ff;
  uVar6 = (uint)DAT_208f0bc3;
  uVar1 = be16_load(&DAT_208f0bc6);
  uVar2 = be16_load(&DAT_208f0bc8);
  if (uVar6 < 3) {
    uVar4 = 0;
    if ((byte)(&DAT_20800650)[uVar6] != 0) {
      uVar2 = (uVar2 & 0xffff) + (uint)*(ushort *)(&DAT_20266760 + uVar6 * 4);
      do {
        uVar8 = uVar2 & 0xffff;
        uVar5 = (uint)*(ushort *)(&DAT_2016dcd4 + uVar4 * 4 + uVar6 * 8) + (uVar1 & 0xffff) & 0xffff
        ;
        bVar9 = param_1 <= uVar5;
        uVar3 = (uint)(*(ushort **)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[uVar6] * 4))[1] +
                (uVar2 & 0xffff) & 0xffff;
        if (uVar5 <= param_1) {
          bVar9 = (**(ushort **)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[uVar6] * 4) + uVar5 &
                  0xffff) <= param_1;
        }
        if (!bVar9) {
          uVar5 = uVar8;
          if (uVar8 <= param_2) {
            uVar5 = uVar3;
          }
          if ((uVar8 <= param_2 && param_2 <= uVar3) && param_2 != uVar5) {
            iVar7 = uVar4 + 0x10fe;
            break;
          }
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < (byte)(&DAT_20800650)[uVar6]);
      if (iVar7 != 0x1ff) {
        return iVar7;
      }
    }
    iVar7 = 0xff;
  }
  else {
    iVar7 = 0x10fe;
  }
  return iVar7;
}


// ===== FUN_2015ccf8 @ 2015ccf8 (208 bytes)

ushort FUN_2015ccf8(uint param_1,uint param_2,ushort *param_3,int param_4)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  bool bVar6;
  
  iVar2 = 0;
  iVar5 = 0;
  uVar4 = 0x1ff;
  if (param_4 == 1) {
    iVar5 = 0x32;
  }
  if ((param_4 != 1) && (param_4 == 3)) {
    iVar2 = 0x32;
    iVar5 = 0x32;
  }
  if (((DAT_208f0bc5 & 0xf) == 3) && (DAT_2080060a <= param_2)) {
    puVar1 = param_3 + param_4 * 5;
    uVar3 = ((uint)*param_3 + (uint)*puVar1) - iVar2 & 0xffff;
    bVar6 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar6 = (iVar5 + uVar3 + (uint)puVar1[2] & 0xffff) <= param_1;
    }
    uVar3 = (uint)DAT_2080064e * (DAT_208f0bc6 & 0xf) + (uint)param_3[1] + (uint)puVar1[1] & 0xffff;
    if (!bVar6) {
      bVar6 = param_2 <= uVar3;
      if (uVar3 <= param_2) {
        bVar6 = (puVar1[3] + uVar3 & 0xffff) <= param_2;
      }
      if (!bVar6) {
        uVar4 = puVar1[4];
      }
    }
  }
  return uVar4;
}


// ===== FUN_2015cdd4 @ 2015cdd4 (244 bytes)

int FUN_2015cdd4(uint param_1,uint param_2)

{
  ushort uVar1;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  iVar8 = 0x1ff;
  if (((int)param_2 <= (int)(0x1e0 - (uint)DAT_2080064e)) && (DAT_2080060a <= param_2)) {
    uVar5 = __aeabi_uidivmod(param_2 - DAT_2080060a);
    uVar5 = uVar5 & 0xff;
    iVar6 = FUN_2015507c(uVar5 * 0x2d + 0x208f0c5b,&DAT_20428186,4);
    uVar1 = DAT_20800646;
    uVar2 = DAT_20800644;
    uVar3 = DAT_20800642;
    uVar4 = DAT_20800640;
    if (iVar6 != 0) {
      uVar1 = DAT_20800612;
      uVar2 = DAT_20800610;
      uVar3 = DAT_2080060a;
      uVar4 = DAT_20800608;
    }
    uVar7 = (uint)uVar4;
    bVar9 = param_1 <= uVar7;
    if (uVar7 <= param_1) {
      bVar9 = (uVar2 + uVar7 & 0xffff) <= param_1;
    }
    uVar7 = DAT_2080064e * uVar5 + (uint)uVar3 & 0xffff;
    if (!bVar9) {
      bVar9 = param_2 <= uVar7;
      if (uVar7 <= param_2) {
        bVar9 = (uVar1 + uVar7 & 0xffff) <= param_2;
      }
      if (!bVar9) {
        iVar8 = uVar5 + 0x1128;
      }
    }
  }
  return iVar8;
}


// ===== FUN_2015cfb4 @ 2015cfb4 (148 bytes)

undefined2 FUN_2015cfb4(uint param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = 0;
  if (0 < param_4) {
    do {
      puVar1 = (ushort *)(param_3 + uVar5 * 10);
      uVar4 = (uint)*puVar1;
      uVar3 = (uint)puVar1[1];
      uVar2 = puVar1[3] + uVar3;
      if (uVar5 == param_5 && param_6 == 1) {
        uVar3 = 0;
      }
      bVar6 = param_1 <= uVar4;
      uVar2 = uVar2 & 0xffff;
      if (uVar4 <= param_1) {
        bVar6 = (puVar1[2] + uVar4 & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar4 = uVar3;
        if (uVar3 <= param_2) {
          uVar4 = uVar2;
        }
        if ((uVar3 <= param_2 && param_2 <= uVar2) && param_2 != uVar4) {
          return *(undefined2 *)(param_3 + uVar5 * 10 + 8);
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while ((int)uVar5 < param_4);
  }
  return 0x1ff;
}


// ===== FUN_2015d1c4 @ 2015d1c4 (204 bytes)

void FUN_2015d1c4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  switch(param_1) {
  case 0:
    DAT_208084ce = 600;
    DAT_208084d2 = 0x14;
    break;
  case 1:
    DAT_208084ce = 0x1c2;
    DAT_208084d2 = 0xf;
    break;
  case 2:
    DAT_208084ce = 300;
    DAT_208084d2 = 10;
    break;
  case 3:
    DAT_208084ce = 0x96;
    DAT_208084d2 = 5;
    break;
  default:
    DAT_208084ce = 0x1e;
    DAT_208084d2 = 1;
  }
  iVar3 = 1;
  DAT_208f463e = 1;
  uVar4 = (uint)DAT_208084ce;
  if (1 < uVar4) {
    do {
      iVar1 = __aeabi_uidivmod(iVar3 * 100,uVar4);
      iVar2 = __aeabi_uidivmod((iVar3 + -1) * 100,uVar4);
      if (iVar2 < iVar1) {
        (&DAT_208f463e)[iVar3] = 1;
      }
      else {
        (&DAT_208f463e)[iVar3] = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar4);
  }
  DAT_208084d0 = 0;
  return;
}


// ===== FUN_2015d2a8 @ 2015d2a8 (92 bytes)

void FUN_2015d2a8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
    DAT_208084cc = 0xb5bf;
    return;
  case 2:
  case 8:
    DAT_208084cc = 0xffff;
    break;
  case 3:
  case 10:
    DAT_208084cc = 0xfef0;
    break;
  default:
    DAT_208084cc = 0xb5bf;
    break;
  case 5:
    DAT_208084cc = 0xfdb6;
    break;
  case 6:
    DAT_208084cc = 0xe71f;
    break;
  case 7:
    DAT_208084cc = 0xfe1f;
    break;
  case 9:
    DAT_208084cc = 0x6fed;
  }
  return;
}


// ===== FUN_2015d334 @ 2015d334 (128 bytes)

void FUN_2015d334(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  FUN_2015dc90(uVar1,0x145,0x195,0x187,param_1);
  FUN_20120d90();
  FUN_2015da3c(uVar1,0x16d,0x195,0x187,0x27);
  FUN_2015d650(uVar1,0x145,4,0,0x4f,param_1);
  return;
}


// ===== FUN_2015d3b8 @ 2015d3b8 (212 bytes)

void FUN_2015d3b8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 0;
    iVar3 = 100;
  }
  else {
    iVar2 = 3;
    iVar3 = 0x85;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d49c @ 2015d49c (104 bytes)

void FUN_2015d49c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0xba;
    iVar3 = 0xba;
  }
  else {
    uVar2 = 0xf0;
    iVar3 = 0xf0;
  }
  FUN_2015d70c(uVar1,0x192 - iVar3,4,0x317,uVar2,8,param_2,0x1e);
  return;
}


// ===== FUN_2015d508 @ 2015d508 (208 bytes)

void FUN_2015d508(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 6;
    iVar3 = 0x2a;
  }
  else {
    iVar2 = 7;
    iVar3 = 0x4b;
  }
  FUN_2015db80(uVar1,((0x11c - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x11c - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d5e8 @ 2015d5e8 (100 bytes)

void FUN_2015d5e8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0x50;
    iVar3 = 0x50;
  }
  else {
    uVar2 = 0x90;
    iVar3 = 0x90;
  }
  FUN_2015d70c(uVar1,0x11c - iVar3,4,0x317,uVar2,9,param_2,0xf);
  return;
}


// ===== FUN_2015d650 @ 2015d650 (188 bytes)

void FUN_2015d650(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_338 [788];
  
  iVar3 = 0;
  FUN_20120da4(param_6,local_338);
  iVar4 = param_3 + 0x187;
  for (; param_3 < iVar4; param_3 = param_3 + 1) {
    iVar1 = 1;
    if (0 < param_5) {
      iVar2 = param_2 * 800;
      do {
        if ((iVar1 < (int)(uint)local_338[iVar3 * 2 + 1]) ||
           ((int)(uint)local_338[iVar3 * 2] < iVar1)) {
          *(undefined2 *)(param_1 + (param_3 + iVar2) * 2) = 0;
        }
        else {
          *(undefined2 *)(param_1 + (param_3 + iVar2) * 2) = 0x65f;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 800;
      } while (iVar1 <= param_5);
    }
    iVar3 = iVar3 + 1;
  }
  return;
}


// ===== FUN_2015d70c @ 2015d70c (360 bytes)

void FUN_2015d70c(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 ushort *param_7,int param_8)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  byte abStack_708 [800];
  undefined2 local_3e8 [240];
  undefined2 local_208 [242];
  
  iVar2 = FUN_2013437c(param_6,abStack_708);
  iVar3 = FUN_20134398(param_6);
  iVar8 = *(int *)(iVar2 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  iVar3 = (uint)*param_7 - param_3;
  uVar1 = param_7[1];
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar5 = iVar2 * param_8;
      puVar6 = local_3e8 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar8 + iVar5 * 2);
    } while (iVar2 < param_5);
  }
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar8 = iVar2 * param_8;
      puVar6 = local_208 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar4 + iVar8 * 2);
    } while (iVar2 < param_5);
  }
  iVar4 = 0;
  iVar2 = param_3;
  if (0 < param_4) {
    do {
      bVar9 = SBORROW4(iVar3,iVar4);
      iVar8 = iVar3 - iVar4;
      if (iVar3 <= iVar4) {
        bVar9 = SBORROW4(iVar4,(uint)uVar1 + iVar3);
        iVar8 = iVar4 - ((uint)uVar1 + iVar3);
      }
      iVar5 = param_5 - (uint)abStack_708[iVar4 + param_3];
      iVar7 = (param_2 + iVar5) * 800;
      if (iVar8 < 0 == bVar9) {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_3e8[iVar5];
        }
      }
      else {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_208[iVar5];
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar4 < param_4);
  }
  return;
}


// ===== FUN_2015d874 @ 2015d874 (212 bytes)

void FUN_2015d874(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 1;
    iVar3 = 0x3c;
  }
  else {
    iVar2 = 4;
    iVar3 = 0x3f;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d958 @ 2015d958 (212 bytes)

void FUN_2015d958(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 2;
    iVar3 = 0x8c;
  }
  else {
    iVar2 = 5;
    iVar3 = 0xd5;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015da3c @ 2015da3c (96 bytes)

void FUN_2015da3c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  
  while (param_5 = param_5 + -1, -1 < param_5) {
    uVar1 = FUN_20120d98(param_5);
    fb_blit_raw(param_1,param_2 + param_5 & 0xffff,param_3,uVar1,param_4,1);
  }
  return;
}


// ===== FUN_2015da9c @ 2015da9c (228 bytes)

void FUN_2015da9c(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  
  if ((param_5 & 1) != 0) {
    iVar1 = FUN_20134434(param_5 >> 1);
    fb_blit_raw(param_1,param_2 + (param_5 >> 1) * 2 & 0xffff,param_3,iVar1 + param_3 * 2,param_4,1)
    ;
  }
  param_5 = param_5 >> 1;
  fb_fill_box(param_1,param_2 - 1U & 0xffff,param_3,param_4,1,0);
  while (param_5 = param_5 - 1, -1 < (int)param_5) {
    iVar1 = FUN_20134434(param_5);
    uVar2 = param_2 + param_5 * 2;
    iVar1 = iVar1 + param_3 * 2;
    fb_blit_raw(param_1,uVar2 & 0xffff,param_3,iVar1,param_4,1);
    fb_blit_raw(param_1,uVar2 + 1 & 0xffff,param_3,iVar1,param_4,1);
  }
  return;
}


// ===== FUN_2015db80 @ 2015db80 (268 bytes)

void FUN_2015db80(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 ushort *param_7)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte abStack_348 [800];
  int local_28;
  
  FUN_2013437c(param_6,abStack_348);
  uVar2 = DAT_208084cc;
  param_4 = param_4 + param_3;
  iVar1 = param_3 + -0x348;
  iVar8 = 0;
  iVar7 = (uint)*param_7 - param_3;
  local_28 = (uint)param_7[1] + iVar7;
  if (param_3 < param_4) {
    do {
      if ((iVar8 < iVar7) || (local_28 <= iVar8)) {
        iVar4 = 0;
        iVar3 = param_2 * 800;
        if (0 < param_5) {
          do {
            iVar9 = param_5 - iVar4;
            iVar4 = iVar4 + 1;
            iVar5 = param_3 + iVar3;
            iVar3 = iVar3 + 800;
            puVar6 = (undefined2 *)(param_1 + iVar5 * 2);
            if ((int)(uint)abStack_348[iVar8 + iVar1 + 0x348] < iVar9) {
              *puVar6 = 0;
            }
            else {
              *puVar6 = uVar2;
            }
          } while (iVar4 < param_5);
        }
      }
      else {
        iVar4 = 0;
        iVar3 = param_2 * 800;
        if (0 < param_5) {
          do {
            iVar9 = param_5 - iVar4;
            iVar4 = iVar4 + 1;
            iVar5 = param_3 + iVar3;
            iVar3 = iVar3 + 800;
            puVar6 = (undefined2 *)(param_1 + iVar5 * 2);
            if ((int)(uint)abStack_348[iVar8 + iVar1 + 0x348] < iVar9) {
              *puVar6 = 0;
            }
            else {
              *puVar6 = uVar2;
            }
          } while (iVar4 < param_5);
        }
      }
      param_3 = param_3 + 1;
      iVar8 = iVar8 + 1;
    } while (param_3 < param_4);
  }
  return;
}


// ===== FUN_2015dc90 @ 2015dc90 (156 bytes)

void FUN_2015dc90(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  byte local_1b0 [396];
  
  iVar2 = FUN_20120d60(param_5,local_1b0);
  param_2 = param_2 * 800;
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar4 = 0;
      if (param_3 < param_4 + param_3) {
        iVar3 = param_3;
        do {
          pbVar1 = local_1b0 + iVar4;
          iVar4 = iVar4 + 1;
          iVar6 = iVar3 + param_2;
          iVar3 = iVar3 + 1;
          puVar7 = (undefined2 *)(param_1 + iVar6 * 2);
          if ((int)(uint)*pbVar1 < iVar2 - iVar5) {
            *puVar7 = 0;
          }
          else {
            *puVar7 = 0x529b;
          }
        } while (iVar3 < param_4 + param_3);
      }
      iVar5 = iVar5 + 1;
      param_2 = param_2 + 800;
    } while (iVar5 < iVar2);
  }
  return;
}


// ===== mainlink_valid_7f @ 2015e16c (28 bytes)

/* byte & 0x7F <= 12 or == 0x7F */

undefined4 mainlink_valid_7f(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((0xc < (param_2 & 0x7f)) && ((param_2 & 0x7f) != 0x7f)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== mainlink_status_valid @ 2015e354 (928 bytes)

/* range checks of the 0x97-byte radio status block */

undefined4
mainlink_status_valid(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  if ((((((*param_2 < 2) && (param_2[1] < 0xc)) && ((~param_2[2] & 3) != 0)) &&
       ((((~param_2[6] & 0x30) != 0 && ((~param_2[9] & 0x70) != 0)) &&
        (((param_2[10] & 7) < 6 &&
         (((param_2[0xb] & 0xf) >> 2 != 3 && ((param_2[0xb] & 0x3f) >> 4 != 3)))))))) &&
      (((param_2[0xc] & 7) < 5 &&
       ((((((((~param_2[0xe] & 0x18) != 0 && (~param_2[0xe] & 3) != 0 && ((param_2[0xf] & 7) < 5))
            && ((param_2[0x11] & 0xf) < 0xb)) &&
           ((uVar5 = (uint)param_2[0x19] + (uint)param_2[0x18] * 0x100 & 0xffff7fff, uVar5 != 0 &&
            (uVar5 < 0x141)))) &&
          (uVar2 = (ushort)param_2[0x1b] + (ushort)param_2[0x1a] * 0x100, uVar2 != 0)) &&
         ((uVar2 < 0x141 && (((uint)param_2[0x13] + (uint)param_2[0x12] * 0x100) - 0x32 < 0x3e4f))))
        && ((((uint)param_2[0x1d] + (uint)param_2[0x1c] * 0x100) - 0x32 < 0x3e4f &&
            (((sVar3 = (ushort)param_2[0x1f] + (ushort)param_2[0x1e] * 0x100,
              (int)sVar3 + 0x4b0U < 0x961 && ((int)(char)param_2[0x20] + 0x19U < 0x33)) &&
             (param_2[0x21] - 0x1e < 0x4c)))))))))) &&
     ((param_2[0x23] >> 4 < 3 && ((param_2[0x23] & 0xf) < 5)))) {
    iVar4 = mainlink_valid_7f(param_1,param_2[0x24],(uint)param_2[0x1c],param_4,sVar3);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x25]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x26]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x27]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x28]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x29]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_code(param_1,param_2[0x2a]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_code(param_1,param_2[0x2b]);
    if (iVar4 == 0) {
      return 0;
    }
    if ((param_2[0x2c] < 0xf) && (bVar1 = param_2[0x2d], bVar1 < 0xb)) {
      if (bVar1 == 2) {
        if (0x74 < param_2[0x2e]) {
          return 0;
        }
      }
      else if (bVar1 == 5) {
        if (9 < param_2[0x2e] - 200) {
          return 0;
        }
      }
      else if (bVar1 == 7) {
        if (0xe < param_2[0x2e] - 0x96) {
          return 0;
        }
      }
      else if ((bVar1 == 8) && (param_2[0x2e] != 199)) {
        return 0;
      }
      if (((((param_2[0x2f] & 0xf) < 0xc) &&
           ((int)(short)((ushort)param_2[0x43] + (ushort)param_2[0x42] * 0x100) + 9999U < 19999)) &&
          (param_2[0x45] < 0xf)) && (bVar1 = param_2[0x46], bVar1 < 0xb)) {
        if (bVar1 == 2) {
          if (0x74 < param_2[0x47]) {
            return 0;
          }
        }
        else if (bVar1 == 5) {
          if (9 < param_2[0x47] - 200) {
            return 0;
          }
        }
        else if (bVar1 == 7) {
          if (0xe < param_2[0x47] - 0x96) {
            return 0;
          }
        }
        else if ((bVar1 == 8) && (param_2[0x47] != 199)) {
          return 0;
        }
        if ((param_2[0x48] & 0xf) < 0xc) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ===== mainlink_rx_validate @ 2015e6f4 (2324 bytes)

/* per-command range checks; 0x7F with the 8-byte key enters maintenance mode */

bool mainlink_rx_validate(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  
  bVar2 = *param_2;
  if (bVar2 == 0x45) {
    return true;
  }
  if (bVar2 < 0x46) {
    if (bVar2 == 0x3f) {
      return param_2[1] < 2;
    }
    if (bVar2 < 0x40) {
      if (bVar2 == 0x1b) {
        return true;
      }
      if (bVar2 == 0x21) {
        return param_2[2] < 8;
      }
      if (bVar2 == 0x23) {
        return (param_2[1] & 0x3f) < 0x33;
      }
      if (bVar2 == 0x33) {
        return true;
      }
    }
    else if ((bVar2 == 0x42 || bVar2 == 0x43) || bVar2 == 0x44) {
      return true;
    }
  }
  else {
    if (bVar2 == 0x7a) {
      return true;
    }
    if (bVar2 < 0x7b) {
      if (bVar2 == 0x60) {
        uVar4 = (uint)param_2[0xe] + (uint)param_2[0xd] * 0x100;
        if (4 < uVar4) {
          if (uVar4 == 0xdb) {
            DAT_20450029 = 1;
            goto LAB_2015dd64;
          }
          if (uVar4 != 0xff) {
            return false;
          }
        }
        DAT_20450029 = 0;
LAB_2015dd64:
        iVar5 = mainlink_status_valid(param_1,param_2 + 0xf);
        return iVar5 != 0;
      }
      if (bVar2 == 100) {
        return param_2[1] < 6;
      }
      if (bVar2 == 0x65) {
        iVar5 = bcd_to_bin(param_2[1]);
        if (((((iVar5 < 100) && (bVar2 = bcd_to_bin(param_2[2]), bVar2 != 0)) && (bVar2 < 0xd)) &&
            ((bVar2 = bcd_to_bin(param_2[3]), bVar2 != 0 && (bVar2 < 0x20)))) &&
           ((bVar2 = bcd_to_bin(param_2[4]), bVar2 < 0x18 &&
            (bVar2 = bcd_to_bin(param_2[5]), bVar2 < 0x3c)))) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        return bVar3;
      }
      if (bVar2 == 0x71) {
        if ((param_2[1] - 3 < 0x7e) || (0x82 < param_2[1])) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        return bVar3;
      }
    }
    else {
      if (bVar2 == 0x7b) {
        return param_2[1] < 2;
      }
      if (bVar2 == 0x7c) {
        return true;
      }
      if (bVar2 == 0x7f) {
        bVar2 = param_2[1];
        if (bVar2 != 0x10) {
          if (bVar2 < 0x11) {
            if (2 < bVar2) {
              return false;
            }
            return true;
          }
          if (bVar2 != 0x11) {
            if (bVar2 != 0x80) {
              return false;
            }
            return true;
          }
        }
        iVar5 = FUN_2015507c(param_2 + 2,&DAT_20450285,8);
        if (iVar5 != 0) {
          return false;
        }
        DAT_2080049c = 1;
        DAT_20800495 = 0;
        mainlink_tx_reset();
        mainlink_set_power_cmd(bVar2);
        return true;
      }
    }
  }
  iVar5 = mainlink_status_valid(param_1,param_2 + 1);
  if (iVar5 == 0) {
    return false;
  }
  bVar2 = *param_2;
  if (bVar2 == 0x39) {
    if ((((param_2[0xb4] < 0xb) && (param_2[0xb5] == 0)) && (param_2[0xb7] < 0x65)) &&
       ((param_2[0xb8] < 0x65 && (iVar5 = be16_load(param_2 + 0xba), iVar5 < 10000)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    return bVar3;
  }
  if (0x39 < bVar2) {
    if (bVar2 == 0x50) {
      if ((param_2[0x98] >> 4 < 5) && ((param_2[0x98] & 0xf) < 3)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      return bVar3;
    }
    if (bVar2 < 0x51) {
      if (bVar2 == 0x3a) {
        switch(param_2[0x98]) {
        case 0:
        case 4:
          break;
        case 1:
          if (4 < (param_2[0x9d] & 0xf)) {
            return false;
          }
          if (4 < (param_2[0x9e] & 0xf)) {
            return false;
          }
          break;
        case 2:
          if (3 < param_2[0x9d]) {
            return false;
          }
          if (5 < param_2[0x9e]) {
            return false;
          }
          break;
        case 3:
          if (3 < param_2[0x9d]) {
            return false;
          }
          break;
        default:
          return false;
        }
        return true;
      }
      if (bVar2 == 0x40) {
        if ((param_2[0x98] < 2) && (param_2[0x99] != 0)) {
          bVar2 = param_2[0x9b] >> 4;
          if ((((bVar2 != 0) && ((bVar2 < 6 && ((param_2[0x9b] & 0xf) < 5)))) &&
              (param_2[0x9c] >> 4 < 8)) && ((param_2[0x9c] & 0xf) < 5)) {
            if (param_2[0x98] == 0) {
              iVar5 = 0;
              do {
                if (0x19 < param_2[iVar5 * 0x2d + 0x11a]) {
                  return false;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < 5);
            }
            return true;
          }
        }
        return false;
      }
      if (bVar2 == 0x41) {
        if ((param_2[0x98] & 0x40) == 0) {
          if ((param_2[0x99] & 0xf) < 4) {
            return true;
          }
        }
        else if (param_2[0x99] >> 4 < 6) {
          return true;
        }
        return false;
      }
    }
    else {
      if (bVar2 == 0x62) {
        return (param_2[0x98] & 0xf) < 9;
      }
      if (bVar2 == 0x70) {
        if (((param_2[0x98] < 4) && (param_2[0x99] < 5)) && (param_2[0x9a] < 2)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        return bVar3;
      }
    }
    return false;
  }
  if (bVar2 == 0x31) {
    switch(param_2[0x98]) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x37:
    case 0x3a:
    case 0x40:
      return true;
    default:
      return false;
    }
  }
  if (0x31 < bVar2) {
    if (bVar2 == 0x34) {
      return param_2[0x99] < 100 && param_2[0x98] < 2;
    }
    if (bVar2 == 0x37) {
      if ((param_2[0x99] < 0x2a) && (param_2[0x9a] < 0x2a)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      return bVar3;
    }
    return false;
  }
  if (bVar2 == 0x20) {
    return true;
  }
  if (bVar2 == 0x24) {
    if (((((param_2[0x99] & 0xf) < 0xb) && ((param_2[0x9a] & 0x1f) < 0x15)) &&
        ((param_2[0x9b] & 0x7f) < 0x65)) &&
       (((param_2[0x9c] & 0x7f) < 0x65 && ((param_2[0x9d] & 0x1f) < 0x15)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    return bVar3;
  }
  if (bVar2 != 0x30) {
    return false;
  }
  uVar4 = (uint)param_2[0x99];
  bVar2 = param_2[0x9b];
  bVar1 = param_2[0x98];
  if (bVar1 != 7) {
    if (bVar1 < 8) {
      switch(bVar1) {
      case 0:
        goto joined_r0x2015e0ec;
      case 1:
        if (3 < uVar4) {
          return false;
        }
        break;
      case 2:
joined_r0x2015e084:
        if (2 < uVar4) {
          return false;
        }
        break;
      case 3:
        if (1 < uVar4) {
          return false;
        }
        break;
      case 4:
        if (4 < uVar4) {
          return false;
        }
        break;
      case 5:
        if (0xf < uVar4) {
          return false;
        }
        break;
      case 6:
        if (9 < uVar4) {
          return false;
        }
        break;
      default:
        goto switchD_2015dfdc_default;
      }
    }
    else if (bVar1 == 0xb) {
      if (10 < (uVar4 & 0xf)) {
        return false;
      }
    }
    else if (bVar1 < 0xc) {
      if (bVar1 != 8) {
        if (bVar1 == 9) goto joined_r0x2015e084;
        if (bVar1 != 10) {
          return false;
        }
        if (2 < param_2[0x99] >> 6) {
          return false;
        }
        if (2 < (uVar4 & 0x3f) >> 4) {
          return false;
        }
        uVar4 = uVar4 & 0xf;
joined_r0x2015e0ec:
        if (5 < uVar4) {
          return false;
        }
      }
    }
    else if (bVar1 == 0xc) {
      if (0xb < uVar4) {
        return false;
      }
    }
    else {
      if (bVar1 == 0xd) goto joined_r0x2015e0ec;
      if (bVar1 != 0xff) {
        return false;
      }
    }
  }
  if ((bVar1 == 1 || bVar1 == 2) || (bVar1 == 3 || bVar1 == 4)) {
    if (1 < param_2[0x9a]) {
      return false;
    }
  }
  else if (param_2[0x9a] != 0) {
    return false;
  }
  if (bVar1 == 5) {
    if (bVar2 < 0x10) {
      return true;
    }
  }
  else if ((bVar1 == 0xb) || (bVar1 == 0xc)) {
    if (bVar2 < 0xc) {
      return true;
    }
  }
  else if (bVar2 == 0) {
    return true;
  }
switchD_2015dfdc_default:
  return false;
}


// ===== mainlink_rx_deliver @ 2015e9b8 (164 bytes)

/* trace, 'D'/'E' block handlers, else post to the dispatcher */

void mainlink_rx_deliver(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  if (*param_2 != '\x06' && *param_2 != '\x15') {
    mainlink_trace(param_2,param_3);
    *(char *)(param_1 + 0x24) = *param_2;
  }
  if (*param_2 != 'D') {
    if (*param_2 != 'E') {
      iVar1 = mainlink_disp_alloc(*(undefined4 *)(param_1 + 0x18));
      *(undefined2 *)(iVar1 + 4) = 0xaa;
      *(short *)(iVar1 + 6) = (short)param_3;
      memcpy(iVar1 + 8,param_2,param_3);
      mainlink_disp_post(*(undefined4 *)(param_1 + 0x18),iVar1);
      return;
    }
    mainlink_rx_block_write(param_2 + 1);
    return;
  }
  mainlink_rx_block_read(param_2 + 1);
  return;
}


// ===== mainlink_valid_code @ 2015eb3c (56 bytes)

/* small code-set check used by mainlink_status_valid */

undefined4 mainlink_valid_code(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_2 - 0x16 < 4) ||
     (((0x21 < param_2 && (param_2 != 0x2d && param_2 != 0x36)) &&
      (param_2 != 0x3a && param_2 != 0xff)))) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== mainlink_rx_bind @ 2015eb74 (12 bytes)

/* (uart, tx, dispatcher) */

void mainlink_rx_bind(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


// ===== mainlink_rx_clear_stats @ 2015eb80 (16 bytes)

void mainlink_rx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== mainlink_rx_parse @ 2015eb90 (168 bytes)

/* first byte: 06/15/1B single byte; else table lookup 0x20450074 */

int mainlink_rx_parse(undefined4 param_1,char *param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *param_2;
  if (cVar1 == '\x06') {
    if (DAT_20450028 == '\0') {
      DAT_20450028 = '\x01';
    }
  }
  else if (cVar1 != '\x15' && cVar1 != '\x1b') {
    uVar2 = 0;
    do {
      if ((&DAT_20450074)[uVar2 * 0xc] == cVar1) {
        iVar3 = mainlink_rx_frame(param_1,&DAT_20450074 + uVar2 * 0xc,param_2,param_3);
        if (iVar3 == 0) {
          *param_4 = &DAT_20450074 + uVar2 * 0xc;
        }
        return iVar3;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x2b);
    return param_3;
  }
  mainlink_rx_deliver(param_1,param_2,1);
  return 1;
}


// ===== task_mainlink_rx @ 2015ec40 (512 bytes)

/* task "uart" pri 3: reads SCIF5, re-assembles frames, NAK after 3 empty reads */

void task_mainlink_rx(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  int local_534;
  undefined1 auStack_530 [1024];
  undefined1 auStack_130 [256];
  uint local_30 [2];
  
  memclr(auStack_130,0x100);
  memclr(auStack_530,0x400);
  uVar3 = 0;
  uVar5 = 0xffffffff;
  local_534 = 0;
  mainlink_rx_clear_stats(param_1);
  uVar4 = 0;
LAB_2015ec90:
  while (iVar1 = itron_twai_flg(*(undefined4 *)(param_1 + 0x34),0xc001,5,local_30,uVar5),
        iVar1 != -0x32) {
    if (iVar1 != 0) {
      return;
    }
    if ((local_30[0] & 0xc000) == 0) goto LAB_2015ed10;
    uVar5 = 0xffffffff;
    uVar3 = 0;
    local_534 = 0;
  }
  goto joined_r0x2015ece4;
LAB_2015ed10:
  if ((local_30[0] & 1) != 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                      (*(int **)(param_1 + 0x10),auStack_130,0x100);
    if (iVar1 == 0) {
joined_r0x2015ece4:
      bVar7 = 2 < (int)uVar4;
      uVar4 = uVar4 + 1;
      if (bVar7) {
        mainlink_send_nak(param_1);
        local_534 = 0;
        uVar3 = 0;
        uVar5 = 0xffffffff;
        uVar4 = 0;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      }
      itron_dly_tsk(1);
    }
    else {
      uVar6 = uVar3 + iVar1;
      if (0x3ff < uVar6) {
        *(uint *)(param_1 + 0x38) = uVar6;
      }
      memcpy(auStack_530 + uVar3,auStack_130);
      if (local_534 == 0) {
        uVar2 = mainlink_rx_parse(param_1,auStack_530,uVar6,&local_534);
        uVar3 = uVar6;
      }
      else {
        uVar2 = mainlink_rx_frame(param_1,local_534,auStack_530,uVar6);
        if (600 < uVar2) {
          mainlink_send_nak(param_1);
          uVar6 = 0;
          local_534 = 0;
          uVar4 = 0;
        }
        for (; uVar3 = uVar6, 0 < (int)uVar2;
            uVar2 = mainlink_rx_parse(param_1,auStack_530 + uVar2,uVar6,&local_534)) {
          if ((int)uVar6 <= (int)uVar2) goto LAB_2015edf4;
          uVar6 = uVar6 - uVar2;
        }
      }
      if (uVar2 == 0) {
        uVar5 = 2;
      }
      else {
LAB_2015edf4:
        bVar7 = uVar2 == uVar3;
        uVar4 = uVar2 - uVar3;
        if (!bVar7) {
          uVar4 = uVar2;
        }
        if ((!bVar7 && uVar2 != 0) && (int)uVar4 < 0 == (bVar7 && SBORROW4(uVar2,uVar3))) {
          mainlink_send_nak(param_1);
        }
        uVar3 = 0;
        uVar5 = 0xffffffff;
        local_534 = 0;
        uVar4 = uVar3;
      }
    }
  }
  goto LAB_2015ec90;
}


// ===== mainlink_send_ack @ 2015ee40 (68 bytes)

/* 1-byte 0x06 frame */

void mainlink_send_ack(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  iVar1 = mainlink_tx_alloc(*(undefined4 *)(param_1 + 0x14));
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 1;
  *(undefined1 *)(iVar1 + 8) = 6;
  mainlink_tx_post(*(undefined4 *)(param_1 + 0x14));
  return;
}


// ===== mainlink_send_nak @ 2015ee84 (68 bytes)

/* 1-byte 0x15 frame */

void mainlink_send_nak(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  iVar1 = mainlink_tx_alloc(*(undefined4 *)(param_1 + 0x14));
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 1;
  *(undefined1 *)(iVar1 + 8) = 0x15;
  mainlink_tx_post(*(undefined4 *)(param_1 + 0x14));
  return;
}


// ===== mainlink_rx_frame @ 2015eec8 (116 bytes)

/* waits for len+2 bytes, validates, ACKs, delivers */

int mainlink_rx_frame(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(ushort *)(param_2 + 2) + 2;
  if (param_4 < iVar2) {
    iVar2 = 0;
  }
  else {
    iVar1 = mainlink_rx_validate(param_1,param_3);
    if (iVar1 == 0) {
      iVar2 = -1;
    }
    else {
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      if (*(char *)(param_2 + 4) == '\0') {
        mainlink_send_ack(param_1);
      }
      mainlink_rx_deliver(param_1,param_3,iVar2);
    }
  }
  return iVar2;
}


// ===== mainlink_rx_ctor @ 2015efe4 (12 bytes)

/* vtbl 0x20427FF8 */

void mainlink_rx_ctor(undefined4 *param_1)

{
  *param_1 = &DAT_20427ff8;
  return;
}


// ===== mouse_cursor_task_create @ 2015eff4 (72 bytes)

void mouse_cursor_task_create(int param_1)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_20165700);
  if (0 < iVar1) {
    mouse_cursor_obj_init(param_1 + 4);
    iVar1 = itron_sta_tsk(iVar1,param_1 + 4);
    if (iVar1 == 0) {
      FUN_201525f8(0xffffffff);
      return;
    }
  }
  return;
}


// ===== FUN_2015f040 @ 2015f040 (24 bytes)

int FUN_2015f040(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428004;
  iVar1 = FUN_2015ff70(param_1 + 1);
  return iVar1 + -4;
}


// ===== FUN_2015f05c @ 2015f05c (60 bytes)

void FUN_2015f05c(int param_1)

{
  uint uVar1;
  
  *(undefined1 *)(param_1 + 0x81) = 0;
  uVar1 = 0;
  do {
    FUN_201645f8(param_1 + 0x88,uVar1 & 0xffff,param_1 + uVar1 * 8);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x10);
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f098 @ 2015f098 (28 bytes)

void FUN_2015f098(int param_1,undefined4 param_2,int param_3)

{
  *(char *)(param_1 + 0x81) = (char)param_3;
  *(undefined4 *)(param_1 + 0x84) = param_2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x80) = 0;
  }
  return;
}


// ===== FUN_2015f0b4 @ 2015f0b4 (16 bytes)

void FUN_2015f0b4(int param_1)

{
  *(undefined1 *)(param_1 + 0x80) = 1;
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f0c4 @ 2015f0c4 (8 bytes)

void FUN_2015f0c4(int param_1)

{
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f0cc @ 2015f0cc (20 bytes)

int FUN_2015f0cc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_20164638(param_1 + 0x88);
  return iVar1 + -0x88;
}


// ===== task_fwdbg @ 2015f0e0 (12 bytes)

/* task entry: loops on update_display_self */

undefined4 task_fwdbg(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined8 uVar4;
  
  uVar4 = update_display_self(param_1);
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  puVar1 = (undefined4 *)uVar4;
  iVar2 = strcmp("fw1up",uVar3);
  if (iVar2 == 0) {
    itron_set_flg(*puVar1,0x1001,*puVar1,extraout_r3,param_1);
    uVar3 = 1;
  }
  else {
    iVar2 = strcmp("fw1chk",uVar3);
    if (iVar2 == 0) {
      itron_set_flg(*puVar1,0x3001,*puVar1,extraout_r3_00,param_1);
      uVar3 = 1;
    }
    else {
      iVar2 = strcmp(&DAT_20428198,uVar3);
      if (iVar2 == 0) {
        itron_set_flg(*puVar1,1,*puVar1,extraout_r3_01,param_1);
        uVar3 = 1;
      }
      else {
        iVar2 = strcmp(&DAT_2042819c,uVar3);
        if (iVar2 == 0) {
          itron_set_flg(*puVar1,2,*puVar1,extraout_r3_02,param_1);
          uVar3 = 1;
        }
        else {
          iVar2 = strcmp(&DAT_204281a0,uVar3);
          if (iVar2 == 0) {
            itron_set_flg(*puVar1,4);
            uVar3 = 1;
          }
          else {
            uVar3 = 0;
          }
        }
      }
    }
  }
  return uVar3;
}


// ===== fwdbg_cmd @ 2015f0ec (240 bytes)

/* fw1up, fw1chk, up0, up1, up2 -> event flags of the self-update task */

undefined4 fwdbg_cmd(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp("fw1up",param_2);
  if (iVar1 == 0) {
    itron_set_flg(*param_1,0x1001);
    uVar2 = 1;
  }
  else {
    iVar1 = strcmp("fw1chk",param_2);
    if (iVar1 == 0) {
      itron_set_flg(*param_1,0x3001);
      uVar2 = 1;
    }
    else {
      iVar1 = strcmp(&DAT_20428198,param_2);
      if (iVar1 == 0) {
        itron_set_flg(*param_1,1);
        uVar2 = 1;
      }
      else {
        iVar1 = strcmp(&DAT_2042819c,param_2);
        if (iVar1 == 0) {
          itron_set_flg(*param_1,2);
          uVar2 = 1;
        }
        else {
          iVar1 = strcmp(&DAT_204281a0,param_2);
          if (iVar1 == 0) {
            itron_set_flg(*param_1,4);
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}


// ===== fwdbg_verify_bank1 @ 2015f1f0 (332 bytes)

/* fw1chk: compares a file with bank 1 (0x18400000), forever (was display_flash_write_bank) */

undefined4 fwdbg_verify_bank1(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int extraout_r1;
  code *pcVar6;
  int iVar7;
  
  iVar1 = DAT_208001c4;
  DAT_208001c0 = DAT_208001c0 + 1;
  iVar2 = fs_fopen(param_2,&DAT_204281a4);
  if (iVar2 == 0) {
    uVar3 = 3;
  }
  else {
    kbd_led_status(3,7);
    itron_dly_tsk(10);
    itron_dly_tsk(10);
    kbd_led_status(4,7);
    pcVar6 = FUN_18400000;
    iVar7 = 0;
    do {
      iVar4 = fs_fread(param_1 + 4,1,0x100,iVar2);
      if (iVar4 == 0) break;
      iVar7 = iVar7 + 1;
      __aeabi_uidivmod(iVar7,100);
      if (extraout_r1 == 0) {
        itron_dly_tsk(10);
      }
      iVar5 = FUN_2015507c(param_1 + 4,pcVar6,iVar4);
      if (iVar5 != 0) {
        DAT_208001c4 = DAT_208001c4 + 1;
      }
      pcVar6 = pcVar6 + 0x100;
    } while (iVar4 != 0);
    FUN_20141ff0(iVar2);
    if (iVar1 == DAT_208001c4) {
      uVar3 = 0;
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

