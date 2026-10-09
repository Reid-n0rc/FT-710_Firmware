// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201476f0 @ 201476f0 (12 bytes)

undefined4 FUN_201476f0(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & ~param_1) != 0) {
    uVar1 = 0xffffff9d;
  }
  return uVar1;
}


// ===== FUN_201476fc @ 201476fc (120 bytes)

uint FUN_201476fc(uint param_1)

{
  if (param_1 - 0x8281 < 0x1a) {
    param_1 = param_1 - 0x21;
  }
  else if (param_1 - 0x83bf < 0x18) {
    param_1 = param_1 - 0x20;
  }
  else if (param_1 - 0x8470 < 0xf) {
    param_1 = param_1 - 0x30;
  }
  else {
    if (0x11 < param_1 - 0x8480) {
      if (9 < param_1 - 0xfa40) {
        return param_1;
      }
      return param_1 - 0x72ec & 0xffff;
    }
    param_1 = param_1 - 0x31;
  }
  return param_1 & 0xffff;
}


// ===== FUN_20147774 @ 20147774 (220 bytes)

int FUN_20147774(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  while( true ) {
    cVar1 = *param_1;
    cVar2 = *param_2;
    if (cVar1 == '\0' && cVar2 == '\0') {
      return 0;
    }
    if (cVar1 == 0) break;
    if (cVar2 == 0) {
      return 1;
    }
    iVar5 = FUN_2014ca90(cVar2);
    if (iVar5 == 0) {
      cVar1 = FUN_2014d35c((int)cVar1);
      cVar2 = FUN_2014d35c((int)cVar2);
      if ((char)(cVar1 - cVar2) != 0) {
        return (int)(char)(cVar1 - cVar2);
      }
    }
    else {
      cVar1 = param_2[1];
      cVar2 = *param_2;
      sVar3 = FUN_201476fc(CONCAT11(*param_1,param_1[1]));
      sVar4 = FUN_201476fc(CONCAT11(cVar2,cVar1));
      if (sVar3 != sVar4) {
        return -1;
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return -1;
}


// ===== FUN_20147850 @ 20147850 (248 bytes)

int FUN_20147850(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = *param_1;
      cVar2 = *param_2;
      if (cVar1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (cVar1 == 0) {
        return -1;
      }
      if (cVar2 == 0) {
        return 1;
      }
      iVar5 = FUN_2014ca90(cVar2);
      if (iVar5 == 0) {
        cVar1 = FUN_2014d35c((int)cVar1);
        cVar2 = FUN_2014d35c((int)cVar2);
        if ((char)(cVar1 - cVar2) != 0) {
          return (int)(char)(cVar1 - cVar2);
        }
      }
      else {
        cVar1 = param_2[1];
        cVar2 = *param_2;
        sVar3 = FUN_201476fc(CONCAT11(*param_1,param_1[1]));
        sVar4 = FUN_201476fc(CONCAT11(cVar2,cVar1));
        if (sVar3 != sVar4) {
          return -1;
        }
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
        uVar6 = uVar6 + 1;
      }
      uVar6 = uVar6 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar6 < param_3);
  }
  return 0;
}


// ===== FUN_20147950 @ 20147950 (408 bytes)

void FUN_20147950(uint param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if (0 < param_3 + -10) {
    FUN_2014d148(param_2,0x30,param_3,0x200);
    param_2 = param_2 + param_3 + -10;
    param_3 = 10;
  }
  pcVar2 = param_2;
  pcVar1 = param_2;
  switch(param_3) {
  default:
    return;
  case 10:
    pcVar1 = param_2 + 1;
    *param_2 = (byte)((ulonglong)param_1 * 0x89705f41 + 0x89705f41 >> 0x3d) + 0x30;
    param_1 = param_1 + (uint)((ulonglong)param_1 * 0x89705f41 + 0x89705f41 >> 0x3d) * -1000000000;
  case 9:
    pcVar2 = pcVar1 + 1;
    *pcVar1 = (char)(param_1 / 100000000) + '0';
    param_1 = param_1 % 100000000;
  case 8:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 10000000) + '0';
    param_1 = param_1 % 10000000;
  case 7:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 1000000) + '0';
    param_1 = param_1 + (short)(param_1 / 1000000) * -1000000;
  case 6:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)((ulonglong)param_1 * 0xa7c5ac47 + 0xa7c5ac47 >> 0x30) + '0';
    param_1 = param_1 + (uint)((ulonglong)param_1 * 0xa7c5ac47 + 0xa7c5ac47 >> 0x30) * -100000;
  case 5:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 10000) + '0';
    param_1 = param_1 % 10000;
  case 4:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 1000) + '0';
    param_1 = param_1 % 1000;
  case 3:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 100) + '0';
    param_1 = param_1 % 100;
  case 2:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 10) + '0';
    param_1 = param_1 % 10;
  case 1:
    *param_2 = (char)param_1 + '0';
    return;
  }
}


// ===== FUN_20147b14 @ 20147b14 (268 bytes)

undefined4 FUN_20147b14(undefined1 *param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar2 = false;
  uVar3 = 0;
  uVar4 = 0;
  do {
    cVar1 = *(char *)(param_2 + uVar3);
    if (cVar1 == '\0') {
      if (uVar3 == 0) {
        return 0xffffff9d;
      }
      break;
    }
    if (cVar1 == ' ') {
      return 0xffffff9d;
    }
    if (cVar1 == '.') {
      if (8 < uVar3) {
        return 0xffffff9d;
      }
      if (uVar3 == 0) {
        return 0xffffff9d;
      }
      bVar5 = uVar4 != 0;
      uVar4 = uVar3;
      if (bVar5) {
        return 0xffffff9d;
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  if ((uVar4 != 0) && (4 < (int)(uVar3 - uVar4))) {
    return 0xffffff9d;
  }
  FUN_2014d148(param_1,0x20,0xb,*(undefined4 *)(param_3 + 0x6c));
  uVar4 = 0;
  param_1[0xb] = 0;
  uVar3 = 0;
  while( true ) {
    cVar1 = *(char *)(param_2 + uVar4);
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '.') {
      bVar2 = true;
      uVar3 = 7;
    }
    else {
      param_1[uVar3] = cVar1;
    }
    if (uVar4 == 8 && !bVar2) break;
    uVar4 = uVar4 + 1 & 0xff;
    uVar3 = uVar3 + 1 & 0xff;
    if (0xb < uVar4 || 0xb < uVar3) {
      return 0;
    }
  }
  *param_1 = 0;
  return 0;
}


// ===== FUN_20147c20 @ 20147c20 (92 bytes)

int FUN_20147c20(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char local_18 [12];
  char *pcVar3;
  
  iVar1 = FUN_20147b14(local_18);
  if (iVar1 == 0) {
    pcVar3 = local_18;
    if (local_18[0] != '\0') {
      while( true ) {
        pcVar2 = pcVar3 + 1;
        if (*pcVar3 != *param_1) break;
        pcVar3 = pcVar2;
        param_1 = param_1 + 1;
        if (*pcVar2 == '\0') {
          return 0;
        }
      }
    }
    iVar1 = -99;
  }
  return iVar1;
}


// ===== FUN_20147c7c @ 20147c7c (972 bytes)

int FUN_20147c7c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                uint *param_6,int param_7)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined *puStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int local_58;
  undefined1 auStack_54 [16];
  char *local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int iStack_28;
  
  uVar9 = 0;
  uVar8 = 0xffffffff;
  puStack_68 = &DAT_20202020;
  puStack_64 = &DAT_20202020;
  uStack_60 = 0x4e4543;
  uStack_5c = 0;
  local_44 = (char *)(param_7 + 0xe0c);
  pcVar5 = (char *)0x0;
  iVar4 = param_7 + 0x40c;
  local_3c[0] = 0;
  local_40 = 0xffffffff;
  local_34 = param_1;
  uStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  iVar2 = FUN_2014cff4(param_2,iVar4,local_3c);
  if (iVar2 == -99) {
    return -0x46;
  }
  local_38 = 1;
  uVar7 = 0;
  uVar3 = (iVar2 + -1) / 0xd + 2;
  uVar6 = uVar3 & 0xffff;
  local_58 = param_7 + 0x1600;
  uVar1 = (undefined2)uVar3;
  if (*(short *)(local_34 + 10) != 0) {
    do {
      uVar11 = FUN_20156260(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar12 = (undefined4)uVar11;
      if (((int)((ulonglong)uVar11 >> 0x20) == 0) &&
         (iVar2 = FUN_20144d04(local_34,uVar12,&local_44), pcVar5 = local_44, local_40 = uVar12,
         iVar2 != 0)) {
        return iVar2;
      }
      if (pcVar5 == (char *)0x0) {
        return -0xd;
      }
      if (*pcVar5 == -0x1b) {
        if (param_4 != 0 && param_4 != 2) {
          uVar9 = uVar9 + 1 & 0xffff;
          bVar10 = uVar9 == uVar6;
          if (uVar6 <= uVar9) {
            bVar10 = uVar8 == 0xffffffff;
          }
          if (bVar10) {
            uVar8 = (uint)(short)uVar7;
          }
        }
      }
      else {
        if (*pcVar5 == '\0') {
          if (param_4 == 0 || param_4 == 2) {
            return -0x47;
          }
          if ((int)uVar8 < 0) {
            if (((*(ushort *)(local_34 + 10) - uVar7) + uVar9 & 0xffff) < uVar6) {
              return -0x42;
            }
            uVar8 = ((uVar7 + uVar6) - uVar9) - 1;
            *param_6 = uVar8;
            *(short *)(local_58 + 0x20) = (short)uVar8;
            *(undefined2 *)(local_58 + 0x22) = uVar1;
            if (param_4 != 3) {
              FUN_20147950(*param_6,&puStack_68,8);
              FUN_2014d128(local_2c,&puStack_68,0xb);
              if (local_38 != 0) {
                iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
                return iVar2;
              }
              iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
              return iVar2;
            }
            return 0;
          }
          *param_6 = uVar8;
          *(short *)(local_58 + 0x20) = (short)uVar8;
          *(undefined2 *)(local_58 + 0x22) = uVar1;
          goto joined_r0x20147df0;
        }
        uVar9 = 0;
        if (((pcVar5[0xb] & 8U) == 0) && (param_4 != 3)) {
          iVar2 = FUN_20145be4(local_34,uVar7,iVar4,uVar6,local_40,param_7);
          if (iVar2 == 0) {
LAB_20147f14:
            if (param_4 == 1) {
              return -0xd;
            }
            FUN_2014d128(local_2c,pcVar5,0x20);
            if (param_4 == 2) {
              iVar2 = FUN_201455f8(local_34,uVar7,uVar6,param_7);
              return iVar2;
            }
            if (param_4 == 0) {
              *param_6 = uVar7;
              *(short *)(local_58 + 0x20) = (short)uVar7;
              *(undefined2 *)(local_58 + 0x22) = uVar1;
              return 0;
            }
          }
          else {
            uVar3 = FUN_2014d248(iVar4);
            if (uVar3 < 0x19) {
              FUN_2014d050(auStack_54,iVar4);
              iVar2 = FUN_20147c20(pcVar5,auStack_54,local_34);
              if (iVar2 == 0) goto LAB_20147f14;
            }
          }
        }
      }
      pcVar5 = pcVar5 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(ushort *)(local_34 + 10));
  }
  if (param_4 == 1 || param_4 == 3) {
    if (-1 < (int)uVar8) {
      *param_6 = uVar8;
      *(short *)(local_58 + 0x20) = (short)uVar8;
      *(undefined2 *)(local_58 + 0x22) = uVar1;
joined_r0x20147df0:
      if (param_4 == 3) {
        return 0;
      }
      FUN_20147950(*param_6,&puStack_68,8);
      FUN_2014d128(local_2c,&puStack_68,0xb);
      iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
      return iVar2;
    }
    if (param_4 == 3) {
      return -0xb;
    }
  }
  return -0x47;
}


// ===== FUN_20148048 @ 20148048 (108 bytes)

undefined4
FUN_20148048(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014d9c0();
  if (iVar1 == 0) {
    uVar2 = FUN_20147c7c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_2014da64(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_201480b4 @ 201480b4 (156 bytes)

int FUN_201480b4(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
  iVar1 = FUN_20147b14(local_18);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_18[0] == '\0') {
    return -99;
  }
  if (local_18[0] == -0x1b) {
    local_18[0] = '\x05';
  }
  else {
    pcVar3 = local_18;
    if (local_18[0] == '\0') {
      return 0;
    }
  }
  while( true ) {
    iVar1 = FUN_2014ca90(*pcVar3);
    pcVar2 = pcVar3;
    pcVar4 = param_1;
    if (iVar1 != 0) {
      pcVar2 = pcVar3 + 1;
      pcVar4 = param_1 + 1;
      if (*pcVar3 != *param_1) {
        return -99;
      }
    }
    pcVar3 = pcVar2 + 1;
    param_1 = pcVar4 + 1;
    if (*pcVar2 != *pcVar4) break;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return -99;
}


// ===== FUN_20148150 @ 20148150 (2048 bytes)

/* WARNING: Type propagation algorithm not settling */

int FUN_20148150(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6,uint *param_7,int *param_8,int param_9)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  undefined6 uVar16;
  int local_b4 [4];
  int local_a4;
  char *local_a0 [4];
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  int local_84;
  undefined1 auStack_80 [12];
  int local_74;
  int local_70;
  undefined1 local_6c [12];
  undefined1 auStack_60 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [4];
  int local_38;
  int iStack_34;
  int local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  local_a0[3] = &DAT_20202020;
  puStack_90 = &DAT_20202020;
  uStack_8c = 0x4e4543;
  uStack_88 = 0x87900000;
  local_a4 = 1;
  iStack_34 = param_1;
  local_30 = param_2;
  uStack_2c = param_3;
  local_28 = param_4;
  FUN_2014d148(local_6c,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_6c[0] = 0x2e;
  local_a0[0] = (char *)(param_9 + 0x60c);
  local_a0[1] = (char *)(param_9 + 0x80c);
  local_a0[2] = (char *)(param_9 + 0xa0c);
  FUN_2014d148(local_a0[1],0,0x200,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148((char *)(param_9 + 0xa0c),0,0x200,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148(local_b4,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  FUN_2014d148(auStack_80,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  iVar14 = 0;
  local_44 = 0;
  local_3c[0] = 0;
  uVar15 = 0xffffffff;
  uVar10 = 0;
  uVar11 = 0;
  local_50 = 0;
  iVar3 = FUN_201497cc(param_1,&local_40,local_30,0,0x72,param_9);
  if (iVar3 == 0) {
    if (local_40 == 0) {
LAB_2014836c:
      iVar3 = -0x47;
    }
    else {
      local_70 = param_9 + 0x40c;
      iVar3 = FUN_2014cff4(param_3,local_70,local_3c);
      if (iVar3 != -99) {
        local_38 = 1;
        uVar12 = 0;
        local_b4[3] = (iVar3 + -1) / 0xd + 2U & 0xffff;
        local_48 = param_9 + 0x1624;
        local_74 = param_9 + 0x1600;
        do {
          iVar3 = FUN_20144980(param_1,local_30);
          local_84 = 0;
          if (*(short *)(param_1 + 4) != 0) {
            do {
              iVar4 = FUN_20144c5c(param_1,iVar3,local_a0);
              pcVar13 = local_a0[0];
              if (iVar4 != 0) {
                return iVar4;
              }
              local_b4[0] = iVar3;
              if (local_a4 == 1) {
                if ((*(int *)(param_1 + 0x34) != local_30) &&
                   ((iVar4 = FUN_2014d48c(local_a0[0],local_6c,0xb), iVar4 != 0 ||
                    (iVar4 = FUN_20146884(pcVar13,(int)*(char *)(param_1 + 0x10)), iVar4 != local_30
                    )))) goto LAB_2014836c;
                local_a4 = 0;
              }
              uVar12 = 0;
              if (*(uint *)(param_1 + 0x6c) >> 5 != 0) {
                do {
                  if (*pcVar13 == '\0') {
                    if (param_5 == 0 || param_5 == 2) {
                      return -4;
                    }
                    goto LAB_201483cc;
                  }
                  if ((*pcVar13 == -0x1b) && (param_5 == 1 || param_5 == 3)) {
                    if ((local_b4[3] == iVar14 + 1U) && ((int)uVar15 < 0)) {
                      uVar15 = (uint)(short)uVar12;
                      FUN_2014d128(auStack_80,local_b4,0xc);
                      *param_8 = iVar3;
                      *param_7 = uVar15;
                      local_44 = local_50;
                    }
                    iVar14 = iVar14 + 1;
                  }
                  else {
                    iVar14 = 0;
                    bVar1 = pcVar13[0xb];
                    if (((bVar1 & 0x30) == 0) && ((~bVar1 & 0xf) == 0)) {
                      if (uVar11 == 0) {
                        uVar10 = 1;
                        uVar11 = uVar10;
                      }
                      else {
                        uVar10 = uVar10 + 1 & 0xffff;
                      }
                    }
                    else if (uVar11 == 0) {
                      uVar10 = 1;
                    }
                    else {
                      uVar10 = uVar10 + 1 & 0xffff;
                      uVar11 = 0;
                    }
                    if (((bVar1 & 8) == 0) && (param_5 != 3)) {
                      iVar4 = FUN_20146608(local_a0,pcVar13,local_70,param_1);
                      if (iVar4 == 0) {
LAB_20148840:
                        FUN_2014d128(local_28,pcVar13,0x20);
                        if (param_5 == 0) {
                          *param_8 = iVar3;
                          *param_7 = uVar12;
                          *(short *)(local_74 + 0x20) = (short)uVar12;
                          *(short *)(local_74 + 0x22) = (short)local_b4[3];
                          FUN_2014d128(local_48,local_b4,0xc);
                          return 0;
                        }
                        if (param_5 != 2) {
                          return -0xd;
                        }
                        iVar3 = FUN_20146470(pcVar13,local_a0,uVar10,param_1);
                        if (iVar3 != 0) {
                          return iVar3;
                        }
                        iVar3 = (uVar10 - uVar12) + -1;
                        iVar14 = 1;
                        if (0 < iVar3) {
                          do {
                            iVar14 = iVar14 + 1;
                            iVar3 = iVar3 - (*(uint *)(param_1 + 0x6c) >> 5);
                          } while (0 < iVar3);
                        }
                        iVar3 = 0;
                        if (0 < iVar14) {
                          while( true ) {
                            if (local_b4[iVar3] == 0) {
                              return 0;
                            }
                            iVar4 = FUN_20144b74(param_1,local_b4[iVar3],local_a0[iVar3]);
                            if (iVar4 != 0) break;
                            iVar3 = iVar3 + 1;
                            if (iVar14 <= iVar3) {
                              return 0;
                            }
                          }
                          return iVar4;
                        }
                        return 0;
                      }
                      uVar7 = FUN_2014d248(local_70);
                      if (uVar7 < 0x19) {
                        FUN_2014d050(auStack_60,local_70);
                        iVar4 = FUN_201480b4(pcVar13,auStack_60,param_1);
                        if (iVar4 == 0) goto LAB_20148840;
                      }
                    }
                  }
                  uVar12 = uVar12 + 1;
                  pcVar13 = pcVar13 + 0x20;
                } while (uVar12 < *(uint *)(param_1 + 0x6c) >> 5);
              }
              pcVar2 = local_a0[1];
              pcVar13 = local_a0[0];
              pcVar9 = local_a0[2];
              iVar3 = iVar3 + 1;
              local_a0[0] = local_a0[2];
              local_a0[2] = local_a0[1];
              local_a0[1] = pcVar13;
              local_b4[2] = local_b4[1];
              local_b4[1] = local_b4[0];
              local_84 = local_84 + 1;
              local_50 = local_50 + 1;
            } while (local_84 < (int)(uint)*(ushort *)(param_1 + 4));
          }
          FUN_201497cc(param_1,&local_4c,local_30,0,0x72,param_9);
          if (local_4c == 0xffffff7) {
            return -0x3d;
          }
          if (local_4c + 0xf0000008U < 8) {
            if (param_5 == 0 || param_5 == 2) {
              return -4;
            }
            if (-1 < (int)uVar15) {
LAB_201483cc:
              if (-1 < (int)uVar15) {
                *(short *)(local_74 + 0x20) = (short)uVar15;
                *(short *)(local_74 + 0x22) = (short)local_b4[3];
                FUN_2014d128(local_48,auStack_80,0xc);
                if (param_5 == 3) {
                  return 0;
                }
                FUN_20147950(local_44 * (*(uint *)(param_1 + 0x6c) >> 5) + uVar15,local_a0 + 3,8);
                FUN_2014d128(local_28,local_a0 + 3,0xb);
                iVar3 = FUN_201466ec(param_1,auStack_80,uVar15 & 0xffff,local_28,local_70,
                                     local_b4[3],param_9);
                return iVar3;
              }
              iVar14 = (local_b4[3] + uVar12) - iVar14;
              uVar16 = FUN_20156260(iVar14 + -1,*(uint *)(param_1 + 0x6c) >> 5);
              sVar8 = (short)((uint6)uVar16 >> 0x20);
              iVar4 = 0;
              if ((int)uVar16 < 1) goto LAB_20148520;
              goto LAB_20148488;
            }
            local_4c = FUN_201463a4(param_1,local_30,param_9);
            iVar3 = FUN_2014d95c();
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          local_30 = local_4c;
        } while( true );
      }
      iVar3 = -0x46;
    }
  }
  return iVar3;
LAB_20148488:
  iVar3 = iVar3 + 1;
  uVar11 = (uint)*(ushort *)(param_1 + 4);
  if (uVar11 == 1) {
    iVar6 = FUN_201463a4(param_1,local_30,param_9);
    local_30 = iVar6;
    iVar3 = FUN_2014d95c();
    if (iVar3 != 0) {
      return iVar3;
    }
LAB_20148620:
    iVar3 = FUN_20144980(param_1,iVar6);
  }
  else if (uVar11 == 2) {
    if (local_84 == 1) {
      iVar6 = FUN_201463a4(param_1,local_30,param_9);
      iVar3 = FUN_2014d95c();
      if (iVar3 != 0) {
        return iVar3;
      }
      goto LAB_20148620;
    }
  }
  else if (uVar11 - 1 == local_84) {
    uVar5 = FUN_201463a4(param_1,local_30,param_9);
    iVar3 = FUN_2014d95c();
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = FUN_20144980(param_1,uVar5);
    local_84 = 0;
  }
  iVar4 = iVar4 + 1;
  local_b4[2] = local_b4[1];
  local_b4[1] = local_b4[0];
  local_84 = local_84 + 1;
  local_b4[0] = iVar3;
  if ((int)uVar16 <= iVar4) {
LAB_20148520:
    *param_8 = iVar3;
    *param_7 = (int)sVar8;
    *(short *)(local_74 + 0x20) = sVar8;
    *(short *)(local_74 + 0x22) = (short)local_b4[3];
    FUN_2014d128(local_48,local_b4,0xc);
    if (param_5 == 3) {
      return 0;
    }
    FUN_20147950(local_50 * (*(uint *)(param_1 + 0x6c) >> 5) + iVar14 + -1,local_a0 + 3,8);
    FUN_2014d128(local_28,local_a0 + 3,0xb);
    if (local_38 == 0) {
      iVar3 = FUN_201466ec(param_1,local_b4,sVar8,local_28,0,local_b4[3],param_9);
      return iVar3;
    }
    iVar3 = FUN_201466ec(param_1,local_b4,sVar8,local_28,local_70,local_b4[3],param_9);
    return iVar3;
  }
  goto LAB_20148488;
}


// ===== FUN_20148990 @ 20148990 (124 bytes)

undefined4
FUN_20148990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_2;
  uVar3 = param_3;
  uVar4 = param_4;
  iVar1 = FUN_2014d9c0(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_20148150(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_1,uVar2,uVar3,uVar4);
    FUN_2014da64(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_20148a0c @ 20148a0c (124 bytes)

void FUN_20148a0c(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  if ((*param_1 != '\\') && (param_1[1] != '\0')) {
    return;
  }
  do {
    cVar2 = param_1[2];
    if (cVar2 == '\0') {
      cVar1 = param_1[3];
joined_r0x20148a4c:
      if (cVar1 == '\0') {
        *param_2 = '\0';
        param_2[1] = '\0';
        return;
      }
    }
    else if (cVar2 == '\\') {
      cVar1 = param_1[3];
      goto joined_r0x20148a4c;
    }
    *param_2 = cVar2;
    param_2[1] = param_1[3];
    param_2 = param_2 + 2;
    param_1 = param_1 + 2;
  } while( true );
}


// ===== FUN_20148a88 @ 20148a88 (136 bytes)

int FUN_20148a88(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char local_218;
  char local_217;
  
  iVar3 = 0;
  pcVar2 = (char *)(param_1 + 4);
  while ((((*pcVar2 != '\0' || (pcVar2[1] != '\0')) &&
          ((pcVar2 = (char *)FUN_20148a0c(pcVar2,&local_218), local_218 != '\0' ||
           (local_217 != '\0')))) && ((*pcVar2 != '\0' || (pcVar2[1] != '\0'))))) {
    iVar1 = FUN_2014d248(&local_218);
    iVar3 = iVar1 + iVar3 + 2;
  }
  return iVar3 + 6;
}


// ===== FUN_20148b10 @ 20148b10 (160 bytes)

undefined4 FUN_20148b10(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  for (; (*param_1 != '\0' || (param_1[1] != '\0')); param_1 = param_1 + 2) {
    cVar1 = *DAT_20808ba8;
    pcVar2 = DAT_20808ba8;
    while (cVar1 != '\0') {
      if ((*pcVar2 == *param_1) && (param_1[1] == '\0')) {
        return 0xffffffff;
      }
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
  }
  if (param_1[-2] == '.') {
    cVar1 = param_1[-1];
  }
  else {
    if (param_1[-2] != ' ') {
      return 0;
    }
    cVar1 = param_1[-1];
  }
  if (cVar1 != '\0') {
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20148bf0 @ 20148bf0 (108 bytes)

int FUN_20148bf0(int param_1)

{
  int iVar1;
  char *pcVar2;
  char local_210;
  char local_20f;
  
  pcVar2 = (char *)(param_1 + 4);
  while (((*pcVar2 != '\0' || (pcVar2[1] != '\0')) &&
         ((pcVar2 = (char *)FUN_20148a0c(pcVar2,&local_210), local_210 != '\0' ||
          (local_20f != '\0'))))) {
    iVar1 = FUN_20148b10(&local_210);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


// ===== FUN_20148c94 @ 20148c94 (224 bytes)

uint FUN_20148c94(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 0xff) == 0) {
    if (0x1900 < param_1 - 0x6100) {
      return param_1;
    }
  }
  else if ((~param_1 & 0xff) == 0) {
    if (0x1900 < param_1 - 0x41ff) {
      return param_1;
    }
  }
  else {
    uVar1 = param_1 & 0xff;
    if (uVar1 == 3) {
      if ((0x1000 < param_1 - 0xb103) && (0x600 < param_1 - 0xc303)) {
        return param_1;
      }
    }
    else {
      if (uVar1 != 4) {
        if (uVar1 != 0x21) {
          return param_1;
        }
        if (0x900 < param_1 - 0x7021) {
          return param_1;
        }
        param_1 = param_1 - 0x1000;
LAB_20148cdc:
        return param_1 & 0xffff;
      }
      if (0x500 < param_1 - 0x3004) {
        if (param_1 == 0x5104) {
          param_1 = 0x104;
          goto LAB_20148cdc;
        }
        if ((0x700 < param_1 - 0x3604) && (0x1100 < param_1 - 0x3e04)) {
          return param_1;
        }
      }
    }
  }
  return param_1 - 0x2000 & 0xffff;
}


// ===== FUN_20148d74 @ 20148d74 (120 bytes)

uint FUN_20148d74(short *param_1,short *param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  while( true ) {
    sVar2 = *param_2;
    if (*param_1 == 0 && sVar2 == 0) {
      return 0;
    }
    if (*param_1 == 0) {
      return 0xffffffff;
    }
    if (sVar2 == 0) {
      return 1;
    }
    iVar3 = FUN_20148c94();
    iVar4 = FUN_20148c94(sVar2);
    uVar1 = iVar3 - iVar4 & 0xffff;
    if (uVar1 != 0) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return uVar1;
}


// ===== FUN_20148dec @ 20148dec (144 bytes)

uint FUN_20148dec(short *param_1,short *param_2,uint param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (param_3 != 0) {
    do {
      sVar2 = *param_2;
      if (*param_1 == 0 && sVar2 == 0) {
        return 0;
      }
      if (*param_1 == 0) {
        return 0xffffffff;
      }
      if (sVar2 == 0) {
        return 1;
      }
      iVar3 = FUN_20148c94();
      iVar4 = FUN_20148c94(sVar2);
      uVar1 = iVar3 - iVar4 & 0xffff;
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar5 = uVar5 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar5 < param_3);
  }
  return 0;
}


// ===== FUN_20148f40 @ 20148f40 (124 bytes)

undefined4 FUN_20148f40(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2015507c(param_2,&DAT_20148fbc,4);
  if ((((iVar1 == 0) && (iVar1 = FUN_2015507c(param_2 + 0x1e4,&DAT_20148fc4,4), iVar1 == 0)) &&
      (*(char *)(param_2 + 0x1fe) == 'U')) && (*(char *)(param_2 + 0x1ff) == -0x56)) {
    uVar2 = FUN_2014d93c(param_2 + 0x1e8);
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    uVar2 = FUN_2014d93c(param_2 + 0x1ec);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    return 0;
  }
  return 0xffffffff;
}


// ===== fat_mount @ 20148fcc (300 bytes)

/* FAT12/16/32/EXFAT detection */

undefined4 fat_mount(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_2015507c(param_2 + 3,"EXFAT",5);
  if (iVar3 == 0) {
    cVar1 = '@';
  }
  else {
    iVar3 = FUN_2015507c(param_2 + 0x52,"FAT32",5);
    if (iVar3 == 0) {
      cVar1 = ' ';
    }
    else {
      iVar3 = FUN_2015507c(param_2 + 0x36,"FAT12",5);
      if (iVar3 == 0) {
        cVar1 = '\f';
      }
      else {
        iVar3 = FUN_2015507c(param_2 + 0x36,"FAT16",5);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
        cVar1 = '\x10';
      }
    }
  }
  *(char *)(param_1 + 0x10) = cVar1;
  if (cVar1 == '@') {
    return 0xffffffff;
  }
  *(ushort *)(param_1 + 4) = (ushort)*(byte *)(param_2 + 0xd);
  uVar2 = FUN_2014d900(param_2 + 0xe);
  *(undefined2 *)(param_1 + 6) = uVar2;
  *(ushort *)(param_1 + 8) = (ushort)*(byte *)(param_2 + 0x10);
  uVar2 = FUN_2014d900(param_2 + 0x11);
  *(undefined2 *)(param_1 + 10) = uVar2;
  iVar3 = FUN_2014d900(param_2 + 0x13);
  *(int *)(param_1 + 0x14) = iVar3;
  if (iVar3 == 0) {
    uVar4 = FUN_2014d93c(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = uVar4;
  }
  iVar3 = FUN_2014d900(param_2 + 0x16);
  *(int *)(param_1 + 0xc) = iVar3;
  if (*(char *)(param_1 + 0x10) == ' ') {
    if (iVar3 == 0) {
      uVar4 = FUN_2014d93c(param_2 + 0x24);
      *(undefined4 *)(param_1 + 0xc) = uVar4;
    }
    uVar4 = FUN_2014d93c(param_2 + 0x2c);
    *(undefined4 *)(param_1 + 0x34) = uVar4;
    uVar2 = FUN_2014d900(param_2 + 0x30);
    *(undefined2 *)(param_1 + 0x3a) = uVar2;
  }
  return 0;
}


// ===== FUN_201490f8 @ 201490f8 (324 bytes)

undefined4 FUN_201490f8(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  if ((*(char *)(param_2 + 0x1fe) != 'U') || (*(char *)(param_2 + 0x1ff) != -0x56)) {
    return 0xffffffff;
  }
  iVar3 = FUN_2014d93c(param_2 + 0x1c6);
  *(int *)(param_1 + 0x30) = iVar3;
  if (iVar3 == 0) {
LAB_20148e80:
    *(undefined4 *)(param_1 + 0x30) = 0;
    iVar3 = FUN_2015507c(param_2 + 3,"EXFAT",5,extraout_r3_02,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
    if (iVar3 == 0) {
      cVar1 = '@';
    }
    else {
      iVar3 = FUN_2015507c(param_2 + 0x52,"FAT32",5,extraout_r3,unaff_r4,unaff_r5,unaff_r6,unaff_lr)
      ;
      if (iVar3 == 0) {
        cVar1 = ' ';
      }
      else {
        iVar3 = FUN_2015507c(param_2 + 0x36,"FAT12",5,extraout_r3_00,unaff_r4,unaff_r5,unaff_r6,
                             unaff_lr);
        if (iVar3 == 0) {
          cVar1 = '\f';
        }
        else {
          iVar3 = FUN_2015507c(param_2 + 0x36,"FAT16",5,extraout_r3_01,unaff_r4,unaff_r5,unaff_r6,
                               unaff_lr);
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          cVar1 = '\x10';
        }
      }
    }
    *(char *)(param_1 + 0x10) = cVar1;
    if (cVar1 == '@') {
      return 0xffffffff;
    }
    return 0;
  }
  cVar1 = *(char *)(param_2 + 0x1c2);
  if (cVar1 == '\a') {
    uVar2 = 0x40;
  }
  else if (cVar1 == '\x01') {
    uVar2 = 0xc;
  }
  else if ((cVar1 == '\x04' || cVar1 == '\x06') || cVar1 == '\x0e') {
    uVar2 = 0x10;
  }
  else {
    if (cVar1 != '\v' && cVar1 != '\f') goto LAB_20148e80;
    uVar2 = 0x20;
  }
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  return 0;
}


// ===== FUN_2014919c @ 2014919c (220 bytes)

int FUN_2014919c(int param_1,uint param_2,int *param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint local_18;
  
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar2 = *(ushort *)(param_1 + 6) + param_2;
    local_18 = param_4;
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar2 = FUN_20144a10(param_1,iVar2,param_4 + 0xc0c,1);
      if (iVar2 != 0) {
        return iVar2;
      }
      *param_3 = param_4 + 0xc0c;
    }
    else {
      iVar3 = FUN_20143c48(param_1,iVar2);
      if (iVar3 == 0) {
        iVar2 = FUN_20143cbc(param_1,iVar2,&local_18);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      else {
        local_18 = CONCAT22(local_18._2_2_,(short)iVar3);
      }
      *param_3 = ((local_18 & 0xffff) - 1) * *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x44) +
                 (uint)*(ushort *)(param_1 + 0x48) * 4;
      sVar1 = __aeabi_uidivmod((local_18 & 0xffff) - 1,*(undefined2 *)(param_1 + 0x4a));
      local_18 = CONCAT22(local_18._2_2_,sVar1 + 1);
      FUN_20143e10(param_1);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -0xb;
  }
  return iVar2;
}


// ===== FUN_20149278 @ 20149278 (196 bytes)

int FUN_20149278(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x44);
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar2 = *(ushort *)(param_1 + 6) + param_2;
    if (iVar1 == 0) {
      iVar1 = FUN_20144ac0(param_1,iVar2,param_3,1);
      if (iVar1 == 0) {
        if (*(short *)(param_1 + 8) != 1) {
          iVar1 = FUN_20144ac0(param_1,*(int *)(param_1 + 0xc) + iVar2,param_3,1);
          return iVar1;
        }
        iVar1 = 0;
      }
    }
    else {
      iVar2 = FUN_20143c48(param_1,iVar2);
      if (iVar2 == 0) {
        iVar1 = -0x45;
      }
      else {
        iVar2 = __aeabi_uidivmod(iVar2 + -1,*(undefined2 *)(param_1 + 0x4a));
        uVar3 = iVar2 + 1U & 0xffff;
        FUN_20143e10(param_1,uVar3);
        iVar1 = iVar1 + uVar3 * 4;
        *(uint *)(iVar1 + -4) = *(uint *)(iVar1 + -4) | 0x80000000;
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = -0xb;
  }
  return iVar1;
}


// ===== FUN_2014933c @ 2014933c (120 bytes)

undefined4 FUN_2014933c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_18;
  int local_14;
  
  uVar3 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = FUN_2014919c(param_1,(int)uVar3,&local_14,param_3);
  if (iVar1 == 0) {
    local_18 = *(undefined4 *)(local_14 + (int)((ulonglong)uVar3 >> 0x20) * 4);
    uVar2 = FUN_2014d93c(&local_18);
    return uVar2;
  }
  if (*(char *)(param_1 + 0x10) == '@') {
    uVar2 = 0xfffffff7;
  }
  else {
    uVar2 = 0xffffff7;
  }
  return uVar2;
}


// ===== FUN_201493b4 @ 201493b4 (108 bytes)

void FUN_201493b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int local_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iStack_24 = param_1;
  uStack_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  uVar3 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = FUN_2014919c(param_1,(int)uVar3,&local_28,param_4);
  if (iVar1 == 0) {
    uVar2 = FUN_2014d93c(&uStack_1c);
    *(undefined4 *)(local_28 + (int)((ulonglong)uVar3 >> 0x20) * 4) = uVar2;
    FUN_20149278(param_1,(int)uVar3);
  }
  return;
}


// ===== FUN_20149420 @ 20149420 (636 bytes)

uint FUN_20149420(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2c [2];
  
  if (*(char *)(param_1 + 0x10) == ' ') {
    if (param_4 != 0x77) {
      uVar3 = FUN_2014933c(param_1,param_2,param_5);
      return uVar3;
    }
    iVar4 = FUN_201493b4(param_1,param_2,param_3,param_5);
    if (iVar4 != 0) {
      return 0xffffff7;
    }
    return 0;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar5 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 1);
    iVar1 = (int)uVar5;
    iVar4 = (int)((ulonglong)uVar5 >> 0x20) << 1;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x6c);
    iVar1 = FUN_20156260(param_2 * 3,iVar4 << 1);
    iVar4 = (param_2 * 3 >> 1) - iVar4 * iVar1;
  }
  iVar2 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
  if (iVar2 != 0) {
    return 0xffffff7;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = FUN_2014d900(local_2c[0] + iVar4);
    if (param_4 == 0x77) {
      FUN_2014d8ec(local_2c[0] + iVar4,param_3 & 0xffff);
      iVar4 = FUN_20149278(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
    goto LAB_20149684;
  }
  local_30 = *(undefined1 *)(local_2c[0] + iVar4);
  if (*(int *)(param_1 + 0x6c) + -1 == iVar4) {
    iVar1 = iVar1 + 1;
    iVar4 = -1;
    iVar2 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
    if (iVar2 != 0) {
      return 0xffffff7;
    }
  }
  local_2f = *(undefined1 *)(local_2c[0] + iVar4 + 1);
  uVar3 = FUN_2014d900(&local_30);
  if ((param_2 & 1) == 0) {
    if (param_4 == 0x77) {
      FUN_2014d8ec(&local_30,uVar3 & 0xf000 | param_3 & 0xfff);
      goto LAB_201495e4;
    }
  }
  else {
    if (param_4 == 0x77) {
      FUN_2014d8ec(&local_30,uVar3 & 0xf | (param_3 & 0xfff) << 4);
    }
    uVar3 = uVar3 >> 4;
    if (param_4 == 0x77) {
LAB_201495e4:
      *(undefined1 *)(local_2c[0] + iVar4 + 1) = local_2f;
      if (iVar4 == -1) {
        iVar4 = FUN_20149278(param_1,iVar1);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        iVar1 = iVar1 + -1;
        iVar4 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        *(undefined1 *)(*(int *)(param_1 + 0x6c) + local_2c[0] + -1) = local_30;
      }
      else {
        *(undefined1 *)(local_2c[0] + iVar4) = local_30;
      }
      iVar4 = FUN_20149278(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
  }
  uVar3 = uVar3 & 0xffff0fff;
  if (0xff6 < uVar3) {
    uVar3 = uVar3 | 0xf000;
  }
LAB_20149684:
  if (0xfff7 < uVar3) {
    uVar3 = 0xfffffff;
  }
  return uVar3;
}


// ===== FUN_2014969c @ 2014969c (32 bytes)

void FUN_2014969c(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & ~(&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== FUN_201496bc @ 201496bc (204 bytes)

undefined4 FUN_201496bc(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2;
  while( true ) {
    uVar1 = FUN_20149420(param_1,uVar3,0,0x72,param_3);
    if ((uVar1 == 0xffffff7) || (uVar3 < 2)) {
      return 0xffffffc3;
    }
    if ((*(int *)(param_1 + 0x58) != 0) && (uVar3 < *(uint *)(param_1 + 0x60))) {
      FUN_2014969c(param_1,uVar3);
    }
    iVar2 = FUN_20149420(param_1,uVar3,0,0x77,param_3);
    if (iVar2 == 0xffffff7) break;
    if (*(char *)(param_1 + 0x10) == ' ') {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    }
    uVar3 = uVar1;
    if (uVar1 + 0xf0000008 < 8) {
      if (*(int *)(param_1 + 0x2c) == 0) {
        *(uint *)(param_1 + 0x2c) = param_2;
      }
      return 0;
    }
  }
  return 0xffffffc3;
}


// ===== FUN_20149788 @ 20149788 (68 bytes)

undefined4 FUN_20149788(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_201496bc(param_1,param_2,param_3);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_201497cc @ 201497cc (88 bytes)

undefined4
FUN_201497cc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_20149420(param_1,param_3,param_4,param_5,param_6);
    *param_2 = uVar2;
    FUN_2014dc10(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_20149824 @ 20149824 (32 bytes)

void FUN_20149824(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) | (&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== FUN_20149844 @ 20149844 (28 bytes)

byte FUN_20149844(int param_1,uint param_2)

{
  return *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & (&DAT_20808bac)[param_2 & 7];
}


// ===== FUN_20149860 @ 20149860 (224 bytes)

undefined4 FUN_20149860(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
LAB_20149870:
  uVar2 = *(uint *)(param_1 + 0x28);
  bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
  bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
  if (bVar4 && !bVar3) {
    do {
      if (bVar4 && !bVar3) {
        iVar1 = FUN_20149844(param_1,uVar2);
        if (iVar1 == 0) goto LAB_20149908;
        if (*(int *)(param_1 + 0x2c) != 0) goto code_r0x201498a4;
      }
      uVar2 = uVar2 + 1;
      bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
      bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
      if (!bVar4 || bVar3) break;
    } while( true );
  }
  goto LAB_201498c0;
code_r0x201498a4:
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_20149870;
LAB_201498c0:
  uVar2 = 2;
  if (*(uint *)(param_1 + 0x28) < 3) {
    return 0xffffff9d;
  }
  do {
    if (uVar2 < *(uint *)(param_1 + 0x60)) {
      iVar1 = FUN_20149844(param_1,uVar2);
      if (iVar1 == 0) {
LAB_20149908:
        *param_2 = uVar2;
        *(uint *)(param_1 + 0x28) = uVar2 + 1;
        FUN_20149824(param_1,uVar2);
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) break;
    }
    uVar2 = uVar2 + 1;
    if (*(uint *)(param_1 + 0x28) <= uVar2) {
      return 0xffffff9d;
    }
  } while( true );
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_201498c0;
}


// ===== FUN_20149940 @ 20149940 (320 bytes)

int FUN_20149940(int param_1,uint *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int local_38 [2];
  int iStack_30;
  uint *local_2c;
  undefined4 local_28;
  
  bVar1 = false;
  iVar7 = 0;
  local_38[0] = 0;
  iVar4 = *(int *)(param_1 + 0xc);
  uVar6 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if (iVar2 + 2U < uVar6) {
    uVar6 = iVar2 + 2U;
  }
LAB_201499a0:
  do {
    iVar2 = -1;
    for (uVar5 = *(uint *)(param_1 + 0x28); uVar5 < uVar6; uVar5 = uVar5 + 1) {
      uVar8 = FUN_20156260(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar4 = (int)uVar8;
      if ((iVar2 != iVar4) &&
         (iVar3 = FUN_2014919c(param_1,iVar4,local_38,local_28), iVar2 = iVar4, iVar3 != 0)) {
        return iVar3;
      }
      if (local_38[0] != 0) {
        iVar7 = FUN_2014d93c(local_38[0] + (int)((ulonglong)uVar8 >> 0x20) * 4);
      }
      if (iVar7 == 0) {
        *local_2c = uVar5;
        *(uint *)(param_1 + 0x28) = uVar5 + 1;
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_201499a0;
      }
    }
    if ((uVar5 != uVar6) || (bVar1)) {
      return -99;
    }
    uVar6 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== FUN_20149a80 @ 20149a80 (268 bytes)

uint FUN_20149a80(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_18;
  
  local_18 = param_4;
  if ((*(int *)(param_1 + 0x58) == 0) || (*(char *)(param_1 + 0x54) == '\0')) {
    iVar1 = FUN_20149940(param_1,&local_18);
  }
  else {
    iVar1 = FUN_20149860(param_1,&local_18);
    if (iVar1 == 0) goto LAB_20149af8;
    if (*(int *)(param_1 + 0x60) == *(int *)(param_1 + 100)) {
      return 0;
    }
    iVar1 = FUN_20149940(param_1,&local_18,param_3);
  }
  if (iVar1 != 0) {
    return 0;
  }
LAB_20149af8:
  iVar1 = FUN_201493b4(param_1,local_18,0xfffffff,param_3);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x58) != 0) && (local_18 < *(uint *)(param_1 + 0x60))) {
      FUN_20149824(param_1);
    }
    if (*(uint *)(param_1 + 0x2c) == local_18) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    if (param_2 == 0) {
      return local_18;
    }
    iVar1 = FUN_201493b4(param_1,param_2,local_18,param_3);
    if (iVar1 == 0) {
      return local_18;
    }
  }
  return 0;
}


// ===== FUN_20149b8c @ 20149b8c (608 bytes)

uint FUN_20149b8c(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint local_24;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x10) == ' ') {
    uVar3 = FUN_20149a80(param_1);
    return uVar3;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = (*(uint *)(param_1 + 0x6c) >> 1) * *(int *)(param_1 + 0xc);
  }
  else {
    uVar3 = (*(uint *)(param_1 + 0x6c) * *(int *)(param_1 + 0xc) * 2) / 3;
  }
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if ((iVar2 + 2U & 0xffff) < uVar3) {
    uVar3 = iVar2 + 2U & 0xffff;
  }
  if ((*(int *)(param_1 + 0x58) != 0) && (*(char *)(param_1 + 0x54) != '\0')) {
    iVar2 = FUN_20149860(param_1,&local_24);
    if (iVar2 == 0) {
      iVar2 = FUN_20149420(param_1,local_24,0xffff,0x77,param_3);
      if (iVar2 == 0) {
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if (param_2 != 0) {
          iVar2 = FUN_20149420(param_1,param_2,local_24,0x77,param_3);
joined_r0x20149d18:
          if (iVar2 == 0xffffff7) {
            return 0;
          }
        }
        return local_24;
      }
    }
    else if (*(int *)(param_1 + 0x60) != *(int *)(param_1 + 100)) goto LAB_20149c58;
    return 0;
  }
LAB_20149c58:
  do {
    for (local_24 = *(uint *)(param_1 + 0x28); local_24 < uVar3; local_24 = local_24 + 1) {
      iVar2 = FUN_20149420(param_1,local_24,0,0x72,param_3);
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x28) = local_24 + 1;
        iVar2 = FUN_20149420(param_1,local_24,0xffff,0x77,param_3);
        if (iVar2 != 0) {
          return 0;
        }
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if ((*(int *)(param_1 + 0x58) != 0) && (local_24 < *(uint *)(param_1 + 0x60))) {
          FUN_20149824(param_1);
        }
        if (param_2 == 0) {
          return local_24;
        }
        iVar2 = FUN_20149420(param_1,param_2,local_24,0x77,param_3);
        goto joined_r0x20149d18;
      }
      if (iVar2 == 0xffffff7) {
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_20149c58;
      }
    }
    if (local_24 != uVar3) {
      return 0;
    }
    if (bVar1) {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== FUN_20149dec @ 20149dec (92 bytes)

undefined4
FUN_20149dec(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_20144800(0);
  iVar1 = FUN_2014db6c(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_20149b8c(param_1,param_2,param_4);
    *param_3 = uVar2;
    FUN_2014dc10(param_1);
    uVar2 = FUN_2014d95c();
    return uVar2;
  }
  return 0xffffffde;
}


// ===== FUN_20149e48 @ 20149e48 (96 bytes)

undefined4 FUN_20149e48(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar3 = FUN_20149420(param_1,param_2,0,0x72,param_4);
    *param_3 = uVar3;
    if (0xffffff6 < uVar3) {
      *param_3 = 0;
    }
    FUN_2014dc10(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_20149eb0 @ 20149eb0 (184 bytes)

int FUN_20149eb0(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    FUN_20156260((param_2 -
                 (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                          (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = FUN_201449cc(param_1,param_2);
  iVar2 = FUN_20149dec(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_20144980(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== FUN_20149f68 @ 20149f68 (184 bytes)

int FUN_20149f68(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    FUN_20156260((param_2 -
                 (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                          (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = FUN_201449cc(param_1,param_2);
  iVar2 = FUN_20149e48(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_20144980(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== FUN_2014a020 @ 2014a020 (132 bytes)

int FUN_2014a020(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 0x3a);
  if (*(char *)(param_1 + 0x10) == ' ') {
    iVar2 = FUN_20144a10(param_1,uVar1,param_2 + 0xc0c,1);
    if (iVar2 == 0) {
      FUN_2014d918(param_2 + 0xdf4,*(undefined4 *)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x28);
      FUN_2014d918(param_2 + 0xdf8);
      iVar2 = FUN_20144ac0(param_1,uVar1,param_2 + 0xc0c,1);
      return iVar2;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ===== FUN_2014a0a4 @ 2014a0a4 (60 bytes)

undefined4 FUN_2014a0a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014a020(param_1,param_2);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014a0e0 @ 2014a0e0 (548 bytes)

void FUN_2014a0e0(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_28;
  int local_24 [2];
  
  local_28 = DAT_20808ba0;
  iVar4 = FUN_2014a4a4();
  if (iVar4 != 0) goto LAB_2014a14c;
  if (param_2 == 0 || param_3 == 0) {
    iVar4 = -0xd;
    goto LAB_2014a14c;
  }
  uVar3 = FUN_2014d35c(param_1);
  iVar4 = FUN_20144918(uVar3,&local_28);
  iVar2 = local_28;
  if (iVar4 != 0) goto LAB_2014a14c;
  cVar1 = *(char *)(local_28 + 0x10);
  if (cVar1 == '\f') {
    uVar5 = (uint)(*(int *)(local_28 + 0x6c) * *(int *)(local_28 + 0xc) * 2) / 3;
LAB_2014a1cc:
    *(uint *)(local_28 + 100) = uVar5;
  }
  else {
    if (cVar1 != '\x10') {
      if (cVar1 != ' ') {
        iVar4 = -0x10;
        goto LAB_2014a14c;
      }
      uVar5 = (*(uint *)(local_28 + 0x6c) >> 2) * *(int *)(local_28 + 0xc);
      goto LAB_2014a1cc;
    }
    *(uint *)(local_28 + 100) = (*(uint *)(local_28 + 0x6c) >> 1) * *(int *)(local_28 + 0xc);
  }
  uVar6 = *(undefined4 *)(local_28 + 0x6c);
  iVar4 = FUN_20156260((uint)*(ushort *)(local_28 + 10) << 5);
  iVar4 = FUN_20156260(*(int *)(iVar2 + 0x14) -
                       (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
  if (iVar4 + 2U < *(uint *)(iVar2 + 100)) {
    *(uint *)(iVar2 + 100) = iVar4 + 2U;
  }
  uVar5 = *(uint *)(iVar2 + 100);
  if (param_3 < (uint)((uVar5 & 7) != 0) + (uVar5 >> 3)) {
    *(uint *)(iVar2 + 0x60) = param_3 << 3;
  }
  else {
    *(uint *)(iVar2 + 0x60) = uVar5;
  }
  *(int *)(iVar2 + 0x58) = param_2;
  *(uint *)(iVar2 + 0x5c) = param_3;
  FUN_2014d148(param_2,0,param_3,uVar6);
  if (param_5 == 0) {
    iVar4 = 0;
  }
  else {
    uVar5 = 0;
    if (*(int *)(local_28 + 0x60) != 0) {
      do {
        if ((*(byte *)(local_28 + 0x68) & 0x40) == 0) {
          iVar4 = -0x13;
          goto LAB_2014a14c;
        }
        iVar4 = FUN_201497cc(local_28,local_24,uVar5,0,0x72,param_4);
        if (iVar4 != 0) goto LAB_2014a14c;
        if (local_24[0] != 0) {
          FUN_20149824(local_28,uVar5);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(local_28 + 0x60));
    }
    *(undefined1 *)(local_28 + 0x54) = 1;
    iVar4 = 0;
  }
LAB_2014a14c:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a304 @ 2014a304 (92 bytes)

undefined4 FUN_2014a304(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014a0e0(param_1,param_2,param_3,iVar1,1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014a360 @ 2014a360 (320 bytes)

void FUN_2014a360(undefined4 param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int local_18;
  
  local_18 = DAT_20808ba0;
  iVar4 = FUN_2014a4a4();
  if (iVar4 != 0) {
    FUN_20144800(iVar4,0);
    return;
  }
  if (param_2 == (uint *)0x0) {
    iVar4 = -0xd;
  }
  else {
    uVar3 = FUN_2014d35c(param_1);
    iVar4 = FUN_20144918(uVar3,&local_18);
    iVar2 = local_18;
    if (iVar4 == 0) {
      cVar1 = *(char *)(local_18 + 0x10);
      if (cVar1 == '\f') {
        uVar5 = (uint)(*(int *)(local_18 + 0x6c) * *(int *)(local_18 + 0xc) * 2) / 3;
      }
      else if (cVar1 == '\x10') {
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 1) * *(int *)(local_18 + 0xc);
      }
      else {
        if (cVar1 != ' ') {
          iVar4 = -0x10;
          goto LAB_2014a3b8;
        }
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 2) * *(int *)(local_18 + 0xc);
      }
      iVar4 = FUN_20156260((uint)*(ushort *)(local_18 + 10) << 5,*(undefined4 *)(local_18 + 0x6c));
      iVar4 = FUN_20156260(*(int *)(iVar2 + 0x14) -
                           (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                    (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
      if (iVar4 + 2U < uVar5) {
        uVar5 = iVar4 + 2U;
      }
      *param_2 = uVar5 >> 3;
      iVar4 = 0;
      *param_2 = (uVar5 >> 3) + (uint)((uVar5 & 7) != 0);
    }
  }
LAB_2014a3b8:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a4a4 @ 2014a4a4 (44 bytes)

undefined4 FUN_2014a4a4(void)

{
  undefined4 uVar1;
  
  if (DAT_20808b90 == 0) {
    uVar1 = 0xffffffee;
  }
  else if (DAT_20808ba0 == 0) {
    uVar1 = 0xffffffef;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_2014a4d0 @ 2014a4d0 (268 bytes)

void FUN_2014a4d0(undefined4 param_1,short param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  
  FUN_2014d148(param_1,0,param_2 * 0x450);
  FUN_2014d148(param_3,0,param_4 * 0x24c);
  DAT_20808ba0 = 0;
  DAT_20808b90 = param_1;
  DAT_20808b94 = param_2;
  DAT_20808b98 = param_3;
  DAT_20808b9c = param_4;
  FUN_2014e0c8();
  iVar1 = FUN_2014e178();
  if (iVar1 < 0) {
    FUN_20144800(0xffffffe2,0);
    return;
  }
  iVar1 = FUN_2014dad0();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffdc,0);
    return;
  }
  iVar1 = FUN_2014dc7c();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffdf,0);
    return;
  }
  iVar1 = FUN_2014de84();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffd9,0);
    return;
  }
  iVar1 = FUN_2014df48();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffd6,0);
    return;
  }
  FUN_20144800(0,0);
  return;
}


// ===== FUN_2014a5dc @ 2014a5dc (572 bytes)

void FUN_2014a5dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_24 [8];
  
  iVar4 = FUN_2014a4a4();
  if (iVar4 == -0x12) {
    FUN_20144800(0xffffffee,0);
    return;
  }
  FUN_2014d148(param_1,0,0x74,param_6);
  uVar3 = FUN_2014d35c(param_2);
  *(undefined1 *)((int)param_1 + 0x11) = uVar3;
  param_1[0x1b] = param_6;
  param_1[7] = param_4;
  param_1[6] = param_3;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  if (param_5 != 0) {
    *(undefined1 *)(param_1 + 0x1a) = 1;
  }
  param_1[0xd] = 0;
  param_1[10] = 2;
  puVar1 = param_1;
  if (DAT_20808ba0 != (undefined4 *)0x0) {
    puVar1 = DAT_20808ba0;
    for (puVar2 = (undefined4 *)*DAT_20808ba0; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar1 = puVar2;
    }
    *puVar1 = param_1;
    puVar1 = DAT_20808ba0;
  }
  DAT_20808ba0 = puVar1;
  *param_1 = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0;
  param_1[0x11] = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined2 *)((int)param_1 + 0x52) = 0;
  param_1[0x13] = 0;
  iVar4 = (*(code *)param_1[6])(param_1,5,0,0,1);
  if (iVar4 != 0) {
LAB_2014a734:
    FUN_20144834();
    return;
  }
  iVar4 = FUN_2014dd4c(param_1);
  if (iVar4 < 0) {
    iVar4 = -0x2d;
    goto LAB_2014a774;
  }
  if (param_5 != 0) goto LAB_2014a774;
  iVar4 = (*(code *)param_1[6])(param_1,7,0,0,1);
  if (iVar4 != 0) goto LAB_2014a734;
  iVar4 = 0;
  if (*(char *)(param_1 + 4) == '@') goto LAB_2014a774;
  if (param_1[0x1b] * (uint)*(ushort *)(param_1 + 1) < 0x20001) {
    if (*(char *)(param_1 + 4) != ' ') goto LAB_2014a774;
    if (param_1[0xf] == -1) {
      iVar5 = FUN_2014e118();
      if (iVar5 == 0) {
        iVar4 = FUN_2014ddd0(param_1);
        if (iVar4 == 0) {
          iVar4 = -0x1f;
          goto LAB_2014a774;
        }
        goto LAB_2014a800;
      }
      iVar4 = FUN_2014b730((int)*(char *)((int)param_1 + 0x11),auStack_24,auStack_24,iVar5);
      FUN_2014e14c(iVar5);
    }
    if (param_1[0x10] == -1) {
      param_1[0x10] = 2;
    }
    param_1[10] = param_1[0x10];
  }
  else {
    iVar4 = FUN_2014ddd0(param_1);
    if (iVar4 == 0) {
      iVar4 = -0x10;
      goto LAB_2014a774;
    }
LAB_2014a800:
    iVar4 = -0x35;
  }
LAB_2014a774:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a818 @ 2014a818 (36 bytes)

void FUN_2014a818(void)

{
  FUN_2014a5dc();
  return;
}

