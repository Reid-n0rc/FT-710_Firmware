// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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
  
  FUN_2013fe50();
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
      iVar1 = FUN_2011762c(DAT_20808b7c,DAT_20808b78,iVar2,extraout_r3_00,unaff_r4);
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
      iVar1 = FUN_2011762c(DAT_20808b88,DAT_20808b84,iVar2,uVar4,unaff_r4);
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


// ===== fs_fopen @ 20141abc (76 bytes)

undefined4 fs_fopen(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_201418b8(param_1,param_2,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_2014485c(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_20141b08 @ 20141b08 (356 bytes)

undefined4 FUN_20141b08(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(char *)((int)param_1 + 0x442) != '\x01') {
    iVar5 = 0;
    puVar4 = DAT_20808b90;
    if (0 < DAT_20808b94) {
      do {
        if (*(char *)((int)param_1 + 0x44d) == '\x01') {
          if ((((*(short *)(puVar4 + 0x8f) != 0) &&
               (iVar2 = FUN_20148d74(param_1 + 0x8f,puVar4 + 0x8f), iVar2 == 0)) &&
              (param_1 != puVar4)) && (*(char *)((int)puVar4 + 0x442) == '\x01')) {
            if (puVar4[7] != param_1[7]) {
              puVar4[7] = param_1[7];
              uVar3 = FUN_20144980(*puVar4);
              puVar4[8] = uVar3;
              *(undefined2 *)((int)puVar4 + 0x44e) = 1;
            }
            if (*(short *)((int)param_1 + 0x44e) != 0) {
              *(undefined2 *)((int)puVar4 + 0x44e) = 1;
            }
            sVar1 = *(short *)((int)puVar4 + 0x44e);
            goto joined_r0x20141be8;
          }
        }
        else if (((*(char *)(puVar4 + 0x8f) != '\0') &&
                 (iVar2 = FUN_20147774(param_1 + 0x8f,puVar4 + 0x8f), iVar2 == 0)) &&
                ((param_1 != puVar4 && (*(char *)((int)puVar4 + 0x442) == '\x01')))) {
          if (puVar4[7] != param_1[7]) {
            puVar4[7] = param_1[7];
            uVar3 = FUN_20144980(*puVar4);
            puVar4[8] = uVar3;
            *(undefined2 *)((int)puVar4 + 0x44e) = 1;
          }
          if (*(short *)((int)param_1 + 0x44e) != 0) {
            *(undefined2 *)((int)puVar4 + 0x44e) = 1;
          }
          sVar1 = *(short *)((int)puVar4 + 0x44e);
joined_r0x20141be8:
          if (sVar1 != 0) {
            puVar4[0xb] = param_1[0xb];
          }
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x114;
      } while (iVar5 < DAT_20808b94);
    }
    *(undefined2 *)((int)param_1 + 0x44e) = 0;
  }
  return 0;
}


// ===== FUN_20141c6c @ 20141c6c (396 bytes)

void FUN_20141c6c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int local_20;
  
  local_20 = param_2 + 0xe0c;
  if ((char)param_1[0x111] == '\0') {
    iVar1 = *param_1;
    uVar2 = FUN_20156260(param_1[6],*(uint *)(iVar1 + 0x6c) >> 5);
    iVar1 = FUN_20144d04(iVar1,uVar2,&local_20);
    if (iVar1 == 0) {
      FUN_20156260(param_1[6],*(uint *)(*param_1 + 0x6c) >> 5);
      iVar1 = local_20 + extraout_r1_00 * 0x20;
      FUN_2014d918(iVar1 + 0x1c,param_1[0xb]);
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)((int)param_1 + 0x443);
      if ((char)param_1[0x113] == '\x01') {
        FUN_201474a4(iVar1,param_1,6);
      }
      FUN_2014d8ec(iVar1 + 0x16,(short)param_1[0x8d]);
      FUN_2014d8ec(iVar1 + 0x18,*(undefined2 *)((int)param_1 + 0x236));
      FUN_20147588(iVar1,param_1[7],(int)*(char *)(*param_1 + 0x10));
      FUN_20144c04(*param_1,uVar2,local_20);
    }
  }
  else {
    iVar1 = FUN_20144c5c(*param_1,param_1[9],&local_20);
    if (iVar1 == 0) {
      FUN_20156260(param_1[6],*(uint *)(*param_1 + 0x6c) >> 5);
      iVar1 = local_20 + extraout_r1 * 0x20;
      FUN_2014d918(iVar1 + 0x1c,param_1[0xb]);
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)((int)param_1 + 0x443);
      if ((char)param_1[0x113] == '\x01') {
        FUN_201474a4(iVar1,param_1,6);
      }
      FUN_2014d8ec(iVar1 + 0x16,(short)param_1[0x8d]);
      FUN_2014d8ec(iVar1 + 0x18,*(undefined2 *)((int)param_1 + 0x236));
      FUN_20147588(iVar1,param_1[7],(int)*(char *)(*param_1 + 0x10));
      FUN_20144b74(*param_1,param_1[9],local_20);
      return;
    }
  }
  return;
}


// ===== FUN_20141df8 @ 20141df8 (64 bytes)

undefined4 FUN_20141df8(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014d9c0(*param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_20141c6c(param_1,param_2);
    FUN_2014da64(*param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_20141e38 @ 20141e38 (268 bytes)

int FUN_20141e38(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = FUN_20144950(*param_1);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = *param_1;
  uVar2 = FUN_20156260(param_1[0x8e],*(undefined4 *)(iVar3 + 0x6c));
  if ((param_1[2] != 0) && (param_1[8] != 0)) {
    iVar3 = FUN_20144ac0(iVar3,param_1[8],param_1[1],uVar2);
    if (iVar3 != 0) {
      FUN_2014d148(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
      return iVar3;
    }
    *(undefined1 *)(param_1 + 0x113) = 1;
  }
  cVar1 = *(char *)((int)param_1 + 0x442);
  if ((cVar1 == '\x10' || cVar1 == '\x11') || (cVar1 == ' ' || cVar1 == '!')) {
    iVar3 = FUN_20141df8(param_1,param_2);
    if (iVar3 != 0) {
      FUN_2014d148(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
      return iVar3;
    }
    *(undefined1 *)(param_1 + 0x113) = 0;
  }
  FUN_20141b08(param_1);
  param_1[2] = 0;
  FUN_2014d148(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
  return 0;
}


// ===== FUN_20141f44 @ 20141f44 (172 bytes)

void FUN_20141f44(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_2014a4a4();
  if ((iVar2 == 0) && (iVar2 = FUN_20144878(param_1), iVar2 == 0)) {
    cVar1 = *(char *)((int)param_1 + 0x442);
    iVar2 = FUN_20141e38(param_1,param_2);
    if ((iVar2 == 0) && (cVar1 != '\x01')) {
      iVar2 = FUN_2014a0a4(*param_1,param_2);
    }
    if ((undefined4 *)param_1[1] != param_1 + 0xd) {
      FUN_2014e0ac();
    }
    if ((iVar2 == 0) && (cVar1 != '\x01')) {
      iVar2 = FUN_20144688(*param_1);
    }
    *(undefined1 *)((int)param_1 + 0x442) = 0;
    FUN_20144800(iVar2,0);
    return;
  }
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_20141ff0 @ 20141ff0 (68 bytes)

undefined4 FUN_20141ff0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_20141f44(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_20142034 @ 20142034 (396 bytes)

uint FUN_20142034(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  
  iVar3 = *param_1;
  local_20 = param_4;
  uVar2 = FUN_20156260(param_1[0x8e],*(undefined4 *)(iVar3 + 0x6c));
  iVar3 = FUN_20144950(iVar3);
  if (iVar3 != 0) {
LAB_201420d4:
    uVar2 = FUN_20144800(iVar3,param_1);
    return uVar2;
  }
  if (((param_1[8] != 0) && (*(short *)((int)param_1 + 0x44e) != 0)) &&
     (*(char *)((int)param_1 + 0x442) == '\x01')) {
    iVar3 = FUN_20144a10(*param_1,param_1[8],param_1[1],uVar2 & 0xffff);
    if (iVar3 != 0) goto LAB_201420d4;
    *(undefined2 *)((int)param_1 + 0x44e) = 0;
  }
  if ((uint)param_1[0x8e] <= (uint)param_1[5]) {
    if (param_1[7] != 0) {
      if (param_1[2] != 0) {
        iVar3 = FUN_20144ac0(*param_1,param_1[8],param_1[1],uVar2 & 0xffff);
        if (iVar3 != 0) goto LAB_201420d4;
        param_1[2] = 0;
        *(undefined1 *)(param_1 + 0x113) = 1;
      }
      iVar3 = FUN_20149f68(*param_1,(uVar2 - 1) + param_1[8],&local_20,param_2);
      if (iVar3 != 0) goto LAB_20142164;
      if (local_20 == 0) {
        iVar3 = -0x3d;
        goto LAB_20142164;
      }
      iVar3 = FUN_20144a10(*param_1,local_20,param_1[1],uVar2 & 0xffff);
      if (iVar3 != 0) goto LAB_20142164;
      param_1[8] = local_20;
    }
    param_1[5] = 0;
  }
  if ((uint)param_1[10] < (uint)param_1[0xb]) {
    param_1[10] = param_1[10] + 1;
    iVar3 = param_1[5];
    param_1[5] = iVar3 + 1;
    bVar1 = *(byte *)(param_1[1] + iVar3);
    FUN_20144800(0,param_1);
    return (uint)bVar1;
  }
  iVar3 = -0xe;
LAB_20142164:
  uVar2 = FUN_20144800(iVar3,param_1);
  return uVar2;
}


// ===== FUN_201421c0 @ 201421c0 (104 bytes)

void FUN_201421c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144878(param_1), iVar1 == 0)) {
    if (*(char *)(param_1 + 0x442) != '\x10' && *(char *)(param_1 + 0x442) != ' ') {
      FUN_20142034(param_1,param_2);
      return;
    }
    FUN_20144800(0xfffffffb,param_1);
    return;
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_20142228 @ 20142228 (68 bytes)

undefined4 FUN_20142228(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_201421c0(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_20142300 @ 20142300 (292 bytes)

int FUN_20142300(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = FUN_2014a4a4();
  if ((iVar3 != 0) || (iVar3 = FUN_20144878(param_3), iVar3 != 0)) {
    iVar3 = FUN_2014485c(iVar3,0);
    return iVar3;
  }
  if (param_1 == 0) {
    iVar3 = FUN_2014485c(0xfffffff3,0);
    return iVar3;
  }
  if (*(char *)(param_3 + 0x442) == '\x10' || *(char *)(param_3 + 0x442) == ' ') {
    iVar3 = FUN_2014485c(0xfffffffb,0);
    return iVar3;
  }
  if (param_2 < 1) {
    iVar3 = FUN_2014485c(0);
    return iVar3;
  }
  iVar4 = param_2 + -1;
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      iVar2 = FUN_20142034(param_3,param_4);
      if (iVar2 == -1) break;
      bVar5 = SBORROW4(iVar2,10);
      iVar1 = iVar2 + -10;
      *(char *)(param_1 + iVar3) = (char)iVar2;
      iVar3 = iVar3 + 1;
      if (iVar2 != 10) {
        bVar5 = SBORROW4(iVar3,iVar4);
        iVar1 = iVar3 - iVar4;
      }
    } while (iVar1 < 0 != bVar5);
  }
  *(undefined1 *)(param_1 + iVar3) = 0;
  if ((iVar3 == 0) && (1 < param_2)) {
    iVar3 = FUN_2014485c(0xfffffff2,0);
    return iVar3;
  }
  return param_1;
}


// ===== FUN_20142390 @ 20142390 (84 bytes)

undefined4 FUN_20142390(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_20142300(param_1,param_2,param_3,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_2014485c(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_201423e4 @ 201423e4 (480 bytes)

int FUN_201423e4(uint param_1,int param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_40;
  int local_3c;
  uint uStack_34;
  int iStack_30;
  int *piStack_2c;
  undefined4 local_28;
  
  local_3c = param_3[10];
  uStack_34 = param_1;
  iStack_30 = param_2;
  piStack_2c = param_3;
  local_28 = param_4;
  uVar1 = FUN_20156260(param_3[0x8e],*(undefined4 *)(*param_3 + 0x6c));
  do {
    if (param_1 == 0) goto LAB_20142500;
    if ((uint)param_3[0x8e] <= (uint)param_3[5]) {
      if (param_3[7] != 0) {
        if (param_3[2] != 0) {
          iVar2 = FUN_20144ac0(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
          if (iVar2 != 0) goto LAB_201424fc;
          param_3[2] = 0;
          *(undefined1 *)(param_3 + 0x113) = 1;
        }
        iVar2 = FUN_201448b8(*param_3,param_3[8]);
        if (iVar2 != 0) {
          param_3[8] = param_3[8] + (uVar1 - 1);
        }
        iVar2 = FUN_20149f68(*param_3,param_3[8],&local_40,local_28);
        if (iVar2 != 0) goto LAB_201424fc;
        if (local_40 == 0) goto LAB_20142500;
        iVar2 = FUN_20144a10(*param_3,local_40,param_3[1],uVar1 & 0xffff);
        if (iVar2 != 0) goto LAB_201424fc;
        param_3[8] = local_40;
      }
      param_3[5] = 0;
    }
    if ((uint)param_3[0xb] <= (uint)param_3[10]) break;
    uVar3 = param_3[0x8e] - param_3[5];
    uVar4 = param_1;
    if (uVar3 < param_1) {
      uVar4 = uVar3;
    }
    FUN_2014d128(param_2,param_3[1] + param_3[5],uVar4);
    iVar2 = param_3[5];
    param_1 = param_1 - uVar4;
    param_2 = param_2 + uVar4;
    param_3[5] = iVar2 + uVar4;
    param_3[10] = param_3[10] + uVar4;
    if (((uint)param_3[0x8e] <= iVar2 + uVar4) && (param_3[2] != 0)) {
      iVar2 = FUN_20144ac0(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
      if (iVar2 != 0) goto LAB_201424fc;
      param_3[2] = 0;
      *(undefined1 *)(param_3 + 0x113) = 1;
    }
  } while ((uint)param_3[10] < (uint)param_3[0xb]);
  iVar2 = -0xe;
LAB_201424fc:
  FUN_20144800(iVar2,param_3);
LAB_20142500:
  if ((uint)param_3[0xb] <= (uint)param_3[10]) {
    FUN_20144800(0xfffffff2,param_3);
  }
  return param_3[10] - local_3c;
}


// ===== FUN_201425c4 @ 201425c4 (956 bytes)

int FUN_201425c4(int param_1,int param_2,int param_3,int *param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  uint extraout_r1_00;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_50;
  int local_4c;
  int local_40;
  uint local_3c;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int *piStack_28;
  
  local_4c = 0;
  iVar7 = *param_4;
  iVar8 = *(int *)(iVar7 + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  iStack_2c = param_3;
  piStack_28 = param_4;
  uVar1 = FUN_20156260(param_4[0x8e],iVar8);
  uVar9 = (uint)*(ushort *)(iVar7 + 4) * iVar8;
  FUN_20144800(0,param_4);
  uVar2 = param_4[0xb] - param_4[10];
  uVar10 = param_2 * param_3;
  if (uVar2 < (uint)(param_2 * param_3)) {
    uVar10 = uVar2;
  }
  if (uVar10 == 0) {
    if ((uint)param_4[0xb] <= (uint)param_4[10]) {
      FUN_20144800(0xfffffff2,param_4);
    }
    return 0;
  }
  iVar7 = FUN_20144950(*param_4);
  if (iVar7 != 0) {
LAB_201426a4:
    FUN_20144800(iVar7,param_4);
    return 0;
  }
  if (((param_4[8] != 0) && (*(short *)((int)param_4 + 0x44e) != 0)) &&
     (*(char *)((int)param_4 + 0x442) == '\x01')) {
    iVar7 = FUN_20144a10(*param_4,param_4[8],param_4[1],uVar1 & 0xffff);
    if (iVar7 != 0) goto LAB_201426a4;
    *(undefined2 *)((int)param_4 + 0x44e) = 0;
  }
  iVar7 = param_4[10];
  FUN_20156260(iVar7,uVar9);
  if (extraout_r1 + uVar10 < uVar9) {
    uVar3 = FUN_201423e4(uVar10,param_1,param_4,param_5);
    iVar7 = FUN_20156260(uVar3,local_30);
    return iVar7;
  }
  uVar2 = uVar9 - extraout_r1;
  FUN_20156260(iVar7 + uVar10,uVar9);
  iVar7 = (uVar10 - uVar2) - extraout_r1_00;
  local_50 = extraout_r1_00;
  if ((iVar7 != 0) && (local_50 = extraout_r1_00, extraout_r1_00 == 0)) {
    iVar7 = (uVar10 - uVar2) - uVar9;
    local_50 = uVar9;
  }
  uVar4 = FUN_201423e4(uVar2,param_1,param_4,param_5);
  if (uVar2 <= uVar4) {
    param_1 = param_1 + uVar4;
    param_4[8] = (uVar1 - 1) + param_4[8];
    iVar8 = FUN_20156260(uVar2,local_30);
    uVar4 = 0;
    uVar2 = FUN_20156260(iVar7,uVar9);
    uVar11 = 0;
    if (uVar2 != 0) {
      do {
        iVar5 = FUN_20149f68(*param_4,param_4[8],&local_40,param_5);
        iVar7 = local_40;
        if (iVar5 != 0) goto LAB_201428cc;
        if (local_40 == 0) {
          return iVar8;
        }
        if (uVar4 == 0) {
          local_4c = local_40;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + local_40 + -1;
        }
        else {
          if (param_4[8] + 1 == local_40) {
            local_3c = (uint)*(ushort *)(*param_4 + 4);
            uVar6 = FUN_20156260(0x100);
            if (uVar4 < uVar6) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_3c + iVar7 + -1;
              goto LAB_20142890;
            }
          }
          iVar5 = FUN_20144a10(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff)
          ;
          iVar7 = local_40;
          local_4c = local_40;
          if (iVar5 != 0) goto LAB_201428cc;
          param_1 = uVar9 * uVar4 + param_1;
          iVar5 = FUN_20156260(uVar9 * uVar4,local_30);
          iVar8 = iVar8 + iVar5;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + iVar7 + -1;
        }
LAB_20142890:
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar2);
      if (uVar4 != 0) {
        iVar5 = FUN_20144a10(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) {
LAB_201428cc:
          FUN_20144800(iVar5,param_4);
          return iVar8;
        }
        param_1 = uVar9 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + local_4c + -1;
        iVar7 = FUN_20156260(uVar9 * uVar4,local_30);
        iVar8 = iVar8 + iVar7;
      }
    }
    param_4[10] = uVar9 * uVar2 + param_4[10];
    if (uVar2 != 0) {
      param_4[8] = (param_4[8] - uVar1) + 1;
    }
    uVar1 = FUN_201423e4(local_50,param_1,param_4,param_5);
    uVar4 = uVar10;
    if (uVar1 < local_50) {
      iVar7 = FUN_20156260(uVar1,local_30);
      return iVar7 + iVar8;
    }
  }
  iVar7 = FUN_20156260(uVar4,local_30);
  return iVar7;
}


// ===== FUN_20142980 @ 20142980 (216 bytes)

undefined4 FUN_20142980(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 != 0) || (iVar1 = FUN_20144878(param_4), iVar1 != 0)) {
    FUN_20144800(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)(param_4 + 0x442) == '\x10' || *(char *)(param_4 + 0x442) == ' ') {
      FUN_20144800(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      FUN_20144800(0,param_4);
      return 0;
    }
    uVar2 = FUN_20156260(0xffffffff,param_2);
    if (param_3 <= uVar2) {
      uVar3 = FUN_201425c4(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  FUN_20144800(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fread @ 20142a58 (96 bytes)

undefined4 fs_fread(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_20142980(param_1,param_2,param_3,param_4,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  FUN_20144800(0xffffffe1,0);
  return 0;
}


// ===== FUN_20142ab8 @ 20142ab8 (2496 bytes)

int FUN_20142ab8(int param_1,int param_2,int param_3,uint *param_4,undefined4 param_5)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r1_01;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint *local_40;
  int local_3c;
  int iStack_34;
  int local_30;
  int local_2c;
  uint *puStack_28;
  
  uVar9 = 0;
  iVar7 = 0;
  uVar8 = 0;
  uVar4 = param_2 * param_3;
  local_5c = *param_4;
  iVar5 = *(int *)(local_5c + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  puStack_28 = param_4;
  local_58 = FUN_20156260(param_4[0x8e],iVar5);
  uVar6 = (uint)*(ushort *)(local_5c + 4) * iVar5;
  FUN_20144800(0,param_4);
  if (uVar4 == 0) {
    return 0;
  }
  if (param_4[10] == 0xffffffff) {
    FUN_20144800(0xffffffc5,param_4);
    return 0;
  }
  uVar2 = ~param_4[10];
  if (uVar2 < uVar4) {
    local_2c = FUN_20156260(uVar2,local_30);
    uVar4 = uVar2;
  }
  iVar5 = FUN_20144950(*param_4);
  if (iVar5 != 0) {
LAB_20142d60:
    FUN_20144800(iVar5,param_4);
    return 0;
  }
  FUN_20156260(param_4[10],uVar6);
  local_40 = param_4 + 0x100;
  if (extraout_r1 + uVar4 < uVar6) {
    iVar5 = local_58 - 1;
    do {
      if (param_4[0x8e] <= param_4[5]) {
        if (param_4[2] != 0) {
          uVar8 = *param_4;
          uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(uVar8 + 0x6c));
          iVar7 = FUN_20144ac0(uVar8,param_4[8],param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
          param_4[2] = 0;
          *(undefined1 *)(param_4 + 0x113) = 1;
        }
        iVar7 = FUN_201448b8(*param_4,param_4[8]);
        if (iVar7 != 0) {
          param_4[8] = param_4[8] + iVar5;
        }
        iVar7 = FUN_20149f68(*param_4,param_4[8],&local_60,param_5);
        uVar8 = local_60;
        if (iVar7 != 0) goto LAB_20142cec;
        if (local_60 == 0) {
          iVar7 = FUN_20149eb0(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 != 0) goto LAB_20142cec;
          if (local_60 == 0) {
            iVar7 = -0xb;
            goto LAB_20142cec;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = FUN_20144a10(uVar9,uVar8,param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
        }
        param_4[8] = local_60;
        param_4[5] = 0;
      }
      uVar9 = param_4[0x8e] - param_4[5];
      uVar8 = uVar4;
      if (uVar9 < uVar4) {
        uVar8 = uVar9;
      }
      FUN_2014d128(param_4[1] + param_4[5],param_1,uVar8);
      uVar4 = uVar4 - uVar8;
      param_1 = param_1 + uVar8;
      param_4[5] = param_4[5] + uVar8;
      uVar8 = param_4[10] + uVar8;
      param_4[10] = uVar8;
      if (param_4[0xb] <= uVar8) {
        param_4[0xb] = uVar8;
      }
      param_4[2] = 1;
      *(undefined2 *)((int)local_40 + 0x4e) = 1;
    } while (uVar4 != 0);
    iVar7 = 0;
LAB_20142cec:
    FUN_20144800(iVar7,param_4);
    uVar9 = local_30 * local_2c - uVar4;
    goto LAB_20143008;
  }
  if ((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
     (iVar5 = FUN_20140be8(param_4,0,2,param_5), iVar5 != 0)) goto LAB_20142d60;
  local_50 = param_4[10];
  FUN_20156260(local_50,uVar6);
  local_5c = uVar6 - extraout_r1_00;
  FUN_20156260(local_50 + uVar4,uVar6);
  local_3c = (uVar4 - local_5c) - extraout_r1_01;
  local_50 = extraout_r1_01;
  if ((local_3c != 0) && (local_50 = extraout_r1_01, extraout_r1_01 == 0)) {
    local_3c = (uVar4 - local_5c) - uVar6;
    local_50 = uVar6;
  }
  param_4[3] = 1;
  local_44 = local_58 - 1;
  uVar4 = local_5c;
  while (uVar4 != 0) {
    if (param_4[0x8e] <= param_4[5]) {
      if (param_4[2] != 0) {
        local_4c = *param_4;
        uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(local_4c + 0x6c));
        iVar5 = FUN_20144ac0(local_4c,param_4[8],param_4[1],uVar1);
        if (iVar5 != 0) goto LAB_20142f50;
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
      iVar5 = FUN_201448b8(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      iVar5 = FUN_20149f68(*param_4,param_4[8],&local_60,param_5);
      if (iVar5 != 0) {
LAB_20142f50:
        FUN_20144800(iVar5,param_4);
        iVar5 = FUN_20156260(uVar9,local_30);
        return iVar5;
      }
      local_4c = local_60;
      if (local_60 == 0) {
        iVar5 = FUN_20149eb0(*param_4,param_4[8],&local_60,param_5);
        if (iVar5 != 0) goto LAB_20142f50;
        if (local_60 == 0) {
          FUN_20144800(0xfffffff5,param_4);
          goto LAB_20143008;
        }
      }
      else {
        local_48 = *param_4;
        uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(local_48 + 0x6c));
        iVar5 = FUN_20144a10(local_48,local_4c,param_4[1],uVar1);
        if (iVar5 != 0) {
          FUN_20144800(iVar5,param_4);
          goto LAB_20143008;
        }
      }
      param_4[8] = local_60;
      param_4[5] = 0;
    }
    uVar2 = param_4[0x8e] - param_4[5];
    uVar9 = uVar4;
    if (uVar2 < uVar4) {
      uVar9 = uVar2;
    }
    FUN_2014d128(param_4[1] + param_4[5],param_1,uVar9);
    uVar4 = uVar4 - uVar9;
    param_1 = param_1 + uVar9;
    param_4[5] = param_4[5] + uVar9;
    uVar2 = param_4[10] + uVar9;
    param_4[10] = uVar2;
    if (param_4[0xb] <= uVar2) {
      param_4[0xb] = uVar2;
    }
    param_4[2] = 1;
    *(undefined2 *)((int)local_40 + 0x4e) = 1;
  }
  FUN_20144800(0,param_4);
  uVar9 = 0;
  if (local_5c != 0) {
    uVar9 = local_5c;
  }
  if (param_4[2] == 0) {
LAB_20143048:
    uVar4 = 0;
    local_5c = FUN_20156260(local_3c,uVar6);
    uVar2 = 0;
    if (local_5c != 0) {
      do {
        iVar5 = FUN_20149f68(*param_4,param_4[8],&local_54,param_5);
        if (iVar5 != 0) goto LAB_20142e7c;
        if (local_54 == 0) {
          local_58 = FUN_20149eb0(*param_4,param_4[8],&local_54,param_5);
          if (local_58 != 0) {
            FUN_20144800(local_58,param_4);
          }
          if (local_54 == 0) {
            FUN_20144800(0xfffffff5,param_4);
          }
          if ((local_58 != 0) || (local_54 == 0)) {
            if (uVar4 == 0) {
              uVar9 = uVar9 + iVar7;
            }
            else {
              iVar5 = FUN_20144ac0(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff
                                  );
              uVar9 = uVar6 * uVar4 + uVar9 + iVar7;
              uVar4 = uVar6 * uVar4 + param_4[10] + iVar7;
              param_4[10] = uVar4;
              if (param_4[0xb] < uVar4) {
                param_4[0xb] = uVar4;
              }
              if (iVar5 == 0) {
                *(undefined1 *)(param_4 + 0x113) = 1;
                FUN_20144800(0xfffffff5,param_4);
              }
              else {
                FUN_20144800(iVar5,param_4);
              }
            }
            goto LAB_20143008;
          }
        }
        if (uVar4 == 0) {
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + (local_54 - 1);
          uVar8 = local_54;
        }
        else {
          local_48 = local_54;
          if (param_4[8] + 1 == local_54) {
            local_4c = (uint)*(ushort *)(*param_4 + 4);
            uVar3 = FUN_20156260(0x100);
            if (uVar4 < uVar3) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_4c + (local_48 - 1);
              goto LAB_20143258;
            }
          }
          iVar5 = FUN_20144ac0(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
          if (iVar5 != 0) {
            uVar9 = uVar9 + iVar7;
            FUN_20144800(iVar5,param_4);
            goto LAB_20143008;
          }
          param_1 = uVar6 * uVar4 + param_1;
          iVar7 = uVar6 * uVar4 + iVar7;
          uVar4 = 1;
          param_4[8] = (local_54 - 1) + (uint)*(ushort *)(*param_4 + 4);
          *(undefined1 *)(param_4 + 0x113) = 1;
          uVar8 = local_54;
        }
LAB_20143258:
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_5c);
      if (uVar4 != 0) {
        iVar5 = FUN_20144ac0(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) goto LAB_20142e7c;
        param_1 = uVar6 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + (uVar8 - 1);
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
    }
    uVar4 = 0;
    iVar5 = uVar6 * local_5c + uVar9;
    uVar9 = uVar6 * local_5c + param_4[10];
    param_4[10] = uVar9;
    uVar8 = local_50;
    if (param_4[0xb] < uVar9) {
      param_4[0xb] = uVar9;
    }
    while( true ) {
      if (uVar8 == 0) {
        FUN_20144800(0,param_4);
        return local_2c;
      }
      if (param_4[0x8e] <= param_4[5]) break;
LAB_20143400:
      uVar9 = param_4[0x8e] - param_4[5];
      uVar4 = uVar8;
      if (uVar9 < uVar8) {
        uVar4 = uVar9;
      }
      FUN_2014d128(param_4[1] + param_4[5],param_1,uVar4);
      param_1 = param_1 + uVar4;
      param_4[5] = param_4[5] + uVar4;
      uVar9 = param_4[10] + uVar4;
      param_4[10] = uVar9;
      if (param_4[0xb] <= uVar9) {
        param_4[0xb] = uVar9;
      }
      param_4[2] = 1;
      uVar8 = uVar8 - uVar4;
    }
    if (param_4[2] == 0) {
LAB_20143364:
      iVar7 = FUN_20149f68(*param_4,param_4[8],&local_60,param_5);
      if (iVar7 == 0) {
        local_5c = local_60;
        if (local_60 == 0) {
          iVar7 = FUN_20149eb0(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 == 0) {
            if (local_60 != 0) goto LAB_201433f4;
            FUN_20144800(0xfffffff5,param_4);
            uVar9 = uVar4 + iVar5;
            goto LAB_20143008;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = FUN_20144a10(uVar9,local_5c,param_4[1],uVar1);
          if (iVar7 == 0) {
LAB_201433f4:
            param_4[8] = local_60;
            param_4[5] = 0;
            goto LAB_20143400;
          }
        }
      }
    }
    else {
      uVar9 = *param_4;
      uVar1 = FUN_20156260(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
      iVar7 = FUN_20144ac0(uVar9,param_4[8],param_4[1],uVar1);
      if (iVar7 == 0) {
        param_4[8] = local_44 + param_4[8];
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
        goto LAB_20143364;
      }
    }
    FUN_20144800(iVar7,param_4);
    uVar9 = uVar4 + iVar5;
  }
  else {
    iVar5 = FUN_20144ac0(*param_4,param_4[8],param_4[1],local_58 & 0xffff);
    if (iVar5 == 0) {
      iVar5 = FUN_201448b8(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      param_4[2] = 0;
      *(undefined1 *)(param_4 + 0x113) = 1;
      goto LAB_20143048;
    }
LAB_20142e7c:
    FUN_20144800(iVar5,param_4);
  }
LAB_20143008:
  iVar5 = FUN_20156260(uVar9,local_30);
  return iVar5;
}


// ===== FUN_20143478 @ 20143478 (276 bytes)

undefined4
FUN_20143478(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_1c;
  
  if (((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
      (param_4[10] != param_4[0xb])) && (iVar1 = FUN_20140be8(param_4,0,2,param_5), iVar1 != 0)) {
LAB_201434f8:
    FUN_20144800(iVar1,param_4);
    return 0;
  }
  if (param_4[0xb] == 0) {
    iVar1 = FUN_20149dec(*param_4,0,&local_1c,param_5);
    if (iVar1 != 0) goto LAB_201434f8;
    param_4[7] = local_1c;
    if (local_1c == 0) {
      FUN_20144800(0xfffffff5,param_4);
      return 0;
    }
    iVar1 = FUN_20144980(*param_4);
    param_4[8] = iVar1;
    FUN_2014d148(param_4[1],0,param_4[0x8e],*(undefined4 *)(*param_4 + 0x6c));
  }
  uVar2 = FUN_20142ab8(param_1,param_2,param_3,param_4,param_5);
  uVar3 = FUN_2014d95c();
  FUN_20144800(uVar3,param_4);
  return uVar2;
}


// ===== FUN_2014358c @ 2014358c (240 bytes)

undefined4 FUN_2014358c(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 != 0) || (iVar1 = FUN_20144878(param_4), iVar1 != 0)) {
    FUN_20144800(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)((int)param_4 + 0x442) == '\x01') {
      FUN_20144800(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      FUN_20144800(0,param_4);
      return 0;
    }
    uVar2 = FUN_20156260(0xffffffff,param_2);
    if (param_3 <= uVar2) {
      iVar1 = FUN_20144970(*param_4);
      if (iVar1 != 0) {
        FUN_20144800(iVar1,param_4);
        return 0;
      }
      uVar3 = FUN_20143478(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  FUN_20144800(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fwrite @ 2014367c (96 bytes)

undefined4 fs_fwrite(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014358c(param_1,param_2,param_3,param_4,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  FUN_20144800(0xffffffe1,0);
  return 0;
}


// ===== FUN_201436dc @ 201436dc (116 bytes)

void FUN_201436dc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144878(param_1), iVar1 == 0)) {
    if (2 < param_3) {
      FUN_20144800(0xfffffff3,param_1);
      return;
    }
    uVar2 = FUN_20140be8(param_1,param_2,param_3,param_4);
    FUN_20144800(uVar2,param_1);
    return;
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== fs_fseek @ 20143750 (84 bytes)

undefined4 fs_fseek(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_201436dc(param_1,param_2,param_3,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_201437a4 @ 201437a4 (692 bytes)

int FUN_201437a4(char *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4c;
  undefined1 auStack_48 [11];
  byte local_3d;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  iVar5 = 0;
  local_4c = DAT_20808ba0;
  iVar4 = DAT_20808b90;
  if (0 < DAT_20808b94) {
    do {
      iVar3 = FUN_20147774(iVar4 + 0x23c,param_1);
      if (iVar3 == 0) {
        return -7;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x450;
    } while (iVar5 < DAT_20808b94);
  }
  uVar2 = FUN_2014d35c((int)*param_1);
  iVar4 = FUN_20144918(uVar2,&local_4c);
  if (((iVar4 == 0) && (iVar4 = FUN_20144950(local_4c), iVar4 == 0)) &&
     (iVar4 = FUN_20144970(local_4c), iVar4 == 0)) {
    FUN_2014d148(auStack_48,0,0x20,*(undefined4 *)(local_4c + 0x6c));
    param_1 = param_1 + 2;
    iVar4 = *(int *)(local_4c + 0x34);
    if (*(char *)(local_4c + 0x10) != ' ') {
      param_1 = (char *)FUN_20147248(param_1,param_2);
      if ((param_1 == (char *)0x0) || (*param_2 == '\0')) {
        return -1;
      }
      iVar4 = FUN_20146338(local_4c,param_2,auStack_48,0,0,auStack_28,param_2);
      if (iVar4 != 0) {
        if (*param_1 == '\0') {
          return -3;
        }
        return -4;
      }
      iVar4 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
    }
    cVar1 = *param_1;
    iVar5 = 0;
    while (cVar1 != '\0') {
      param_1 = (char *)FUN_20147248(param_1,param_2);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_2 == '\0') {
        return -1;
      }
      iVar5 = FUN_201471cc(local_4c,iVar4,param_2,auStack_48,0,0,auStack_28,auStack_24,param_2);
      if (iVar5 != 0) {
        if (*param_1 != '\0' || iVar5 != -4) {
          return iVar5;
        }
        return -3;
      }
      iVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
      iVar5 = iVar4;
      iVar4 = iVar3;
      cVar1 = *param_1;
    }
    if ((local_3d & 0x10) != 0) {
      return -3;
    }
    if (iVar5 == 0) {
      iVar4 = FUN_20146338(local_4c,param_2,auStack_48,2,0,auStack_28,param_2);
    }
    else {
      iVar4 = FUN_201471cc(local_4c,iVar5,param_2,auStack_48,2,0,auStack_28,auStack_24,param_2);
    }
    if ((iVar4 == 0) &&
       ((iVar4 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10)), iVar4 == 0 ||
        (iVar4 = FUN_20149788(local_4c,iVar4,param_2), iVar4 == 0)))) {
      iVar4 = FUN_2014a0a4(local_4c,param_2);
      return iVar4;
    }
  }
  return iVar4;
}


// ===== FUN_20143a58 @ 20143a58 (200 bytes)

void FUN_20143a58(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_1 == 0) {
      uVar4 = 0xffffffff;
LAB_20143b18:
      FUN_20144800(uVar4,0);
      return;
    }
    iVar2 = FUN_201473c4(param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_2014d220(param_1);
      iVar3 = param_2 + 0x100c;
      FUN_2014d288(iVar3,param_1,iVar2 + 1);
      FUN_2014cd68(iVar3);
      uVar1 = FUN_2014d35c((int)*(char *)(param_2 + 0x100c));
      iVar2 = FUN_20144918(uVar1,&local_10);
      if ((iVar2 == 0) && (iVar2 = FUN_201437a4(iVar3,param_2), iVar2 == 0)) {
        uVar4 = FUN_20144688(local_10);
        goto LAB_20143b18;
      }
    }
  }
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_20143b20 @ 20143b20 (68 bytes)

undefined4 FUN_20143b20(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_20143a58(param_1,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_20143b70 @ 20143b70 (172 bytes)

int FUN_20143b70(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 == 0) {
    if (param_3 < (uint)(param_4 * 0x206)) {
      return -0x18;
    }
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
    uVar2 = FUN_20156260(param_3,param_4 * 0x206);
    if (uVar2 < 0x10000) {
      if (uVar2 == 0) {
        return -0x18;
      }
    }
    else {
      uVar2 = 0xffff;
    }
    *(short *)(param_1 + 0x48) = (short)uVar2;
    *(uint *)(param_1 + 0x44) = param_2;
    *(short *)(param_1 + 0x4a) = (short)param_4;
    FUN_2014d148(param_2,0,uVar2 * param_4 * 0x206,*(undefined4 *)(param_1 + 0x6c));
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20143c1c @ 20143c1c (24 bytes)

void FUN_20143c1c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_20143b70();
  FUN_20144800(uVar1,0);
  return;
}


// ===== FUN_20143c34 @ 20143c34 (20 bytes)

void FUN_20143c34(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_20143b70();
  FUN_20144800(uVar1,0);
  return;
}


// ===== FUN_20143c48 @ 20143c48 (116 bytes)

uint FUN_20143c48(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = *(uint **)(param_1 + 0x44);
  if (*(ushort *)(param_1 + 0x48) != 0) {
    do {
      uVar1 = *puVar3 & 0x7fffffff;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < *(ushort *)(param_1 + 0x4a) + uVar1)) {
        return uVar2 * *(ushort *)(param_1 + 0x4a) + (param_2 - uVar1) + 1 & 0xffff;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < *(ushort *)(param_1 + 0x48));
  }
  return 0;
}


// ===== FUN_20143cbc @ 20143cbc (340 bytes)

int FUN_20143cbc(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  
  uVar8 = (uint)*(ushort *)(param_1 + 6);
  uVar7 = (uint)*(ushort *)(param_1 + 0x4a);
  iVar9 = *(int *)(param_1 + 0x44);
  iVar2 = FUN_20156260(param_2 - uVar8,uVar7);
  uVar11 = uVar7 * iVar2 + uVar8;
  uVar4 = (uint)*(ushort *)(param_1 + 0x48);
  puVar5 = (ushort *)((*(int *)(param_1 + 0x6c) * uVar7 + 4) * uVar4 + iVar9);
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*puVar5 == uVar4 || *puVar5 == 0) break;
      puVar5 = puVar5 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar4);
  }
  puVar10 = (uint *)(iVar9 + uVar3 * 4);
  iVar2 = uVar3 * uVar7 * *(int *)(param_1 + 0x6c) + iVar9 + uVar4 * 4;
  if ((*puVar10 & 0x80000000) != 0) {
    uVar4 = *puVar10 & 0x7fffffff;
    uVar3 = 0;
    sVar6 = 0;
    if (uVar7 != 0) {
      do {
        if (uVar4 + uVar3 < *(int *)(param_1 + 0xc) + uVar8) {
          sVar6 = sVar6 + 1;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < uVar7);
    }
    iVar9 = FUN_20144ac0(param_1,uVar4,iVar2,sVar6);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
       (iVar9 = FUN_20144ac0(param_1,*(int *)(param_1 + 0xc) + (*puVar10 & 0x7fffffff),iVar2,1),
       iVar9 != 0)) {
      return iVar9;
    }
  }
  iVar2 = FUN_20144a10(param_1,uVar11,iVar2,*(undefined2 *)(param_1 + 0x4a));
  if (iVar2 == 0) {
    *puVar10 = uVar11;
    uVar1 = FUN_20143c48(param_1,param_2);
    *param_3 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== FUN_20143e10 @ 20143e10 (156 bytes)

void FUN_20143e10(int param_1,uint param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort unaff_r5;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x48);
  if (uVar5 != 0) {
    unaff_r5 = 1;
  }
  puVar2 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + 4) * uVar5 +
           *(int *)(param_1 + 0x44));
  uVar1 = puVar2[param_2 - 1];
  uVar3 = 1;
  if (uVar5 != 0) {
    do {
      uVar4 = *puVar2;
      if ((uVar4 == 0 || uVar3 == param_2) || ((uVar1 <= uVar4 && (uVar1 != 0)))) {
        if (uVar3 != param_2) goto LAB_20143e80;
        *puVar2 = unaff_r5;
      }
      else {
        uVar4 = uVar4 + 1;
        *puVar2 = uVar4;
LAB_20143e80:
        if (uVar4 == 0) {
          return;
        }
      }
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= *(ushort *)(param_1 + 0x48));
  }
  return;
}


// ===== FUN_20143eac @ 20143eac (204 bytes)

void FUN_20143eac(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 != 0) {
    FUN_20144800(iVar1,0);
    return;
  }
  if ((param_2 != 0 && param_4 != 0) && ((uint)(param_4 * 0x208) <= param_3)) {
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
    uVar2 = FUN_20156260(param_3,param_4 * 0x208);
    bVar3 = 0x7fff < uVar2;
    if (bVar3) {
      uVar2 = 0x7fff;
    }
    if (bVar3 || 2 < uVar2) {
      *(short *)(param_1 + 0x50) = (short)uVar2;
      *(uint *)(param_1 + 0x4c) = param_2;
      *(short *)(param_1 + 0x52) = (short)param_4;
      FUN_2014d148(param_2,0,uVar2 * param_4 * 0x208,*(undefined4 *)(param_1 + 0x6c));
      FUN_20144800(0);
      return;
    }
  }
  FUN_20144800(0xffffffe4,0);
  return;
}


// ===== FUN_20143f78 @ 20143f78 (136 bytes)

uint FUN_20143f78(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)*(ushort *)(param_1 + 0x50);
  puVar3 = *(uint **)(param_1 + 0x4c);
  puVar5 = (uint *)((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 4) * uVar4 +
                   (int)puVar3);
  uVar2 = 0;
  if (uVar4 != 0) {
    do {
      uVar1 = *puVar3;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < (ushort)*puVar5 + uVar1)) {
        return uVar2 * *(ushort *)(param_1 + 0x52) + (param_2 - uVar1) + 1 & 0xffff;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
      puVar5 = (uint *)((int)puVar5 + 2);
    } while (uVar2 < uVar4);
  }
  return 0;
}


// ===== FUN_20144000 @ 20144000 (616 bytes)

int FUN_20144000(int param_1,uint param_2,undefined2 *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x50);
  iVar12 = *(int *)(param_1 + 0x4c);
  iVar8 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
  puVar7 = (ushort *)((iVar8 + 6) * uVar5 + iVar12);
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      if (uVar5 == (*puVar7 & 0xffff7fff) || (*puVar7 & 0x7fff) == 0) break;
      puVar7 = puVar7 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar5);
  }
  piVar10 = (int *)(iVar12 + uVar3 * 4);
  iVar6 = uVar3 * (uint)*(ushort *)(param_1 + 0x52) * *(int *)(param_1 + 0x6c) + iVar12 + uVar5 * 4;
  puVar9 = (ushort *)((iVar8 + 4) * uVar5 + iVar12 + uVar3 * 2);
  if (((*puVar7 & 0x8000) != 0) &&
     (iVar8 = FUN_20144ac0(param_1,*piVar10,iVar6,*puVar9), iVar8 != 0)) {
    return iVar8;
  }
  if (*(char *)(param_1 + 0x10) != ' ') {
    uVar3 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    iVar8 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
            (uint)*(ushort *)(param_1 + 6);
    if (param_2 < uVar3 + iVar8) {
      uVar5 = uVar3 & 0xffff;
      uVar1 = *(ushort *)(param_1 + 0x52);
      uVar11 = (uint)uVar1;
      if (uVar5 <= uVar11) {
        *puVar9 = (ushort)uVar3;
        iVar12 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                 (uint)*(ushort *)(param_1 + 6);
        iVar8 = FUN_20144a10(param_1,iVar12,iVar6,uVar5);
        if (iVar8 != 0) {
          return iVar8;
        }
        *piVar10 = iVar12;
        uVar2 = FUN_20143f78(param_1,iVar12);
        *param_3 = uVar2;
        return 0;
      }
      iVar12 = FUN_20156260(param_2 - iVar8,uVar11);
      uVar5 = uVar5 - uVar11 * iVar12;
      iVar8 = iVar8 + uVar11 * iVar12;
      if (uVar5 < uVar11) {
        *puVar9 = (ushort)uVar5;
      }
      else {
        *puVar9 = uVar1;
      }
      iVar12 = FUN_20144a10(param_1,iVar8,iVar6,*puVar9);
      if (iVar12 != 0) {
        return iVar12;
      }
      goto LAB_201441cc;
    }
  }
  if (*(ushort *)(param_1 + 0x52) < *(ushort *)(param_1 + 4)) {
    uVar4 = FUN_201449cc(param_1,param_2);
    iVar8 = FUN_20144980(param_1,uVar4);
    uVar1 = *(ushort *)(param_1 + 0x52);
    uVar5 = (uint)uVar1;
    iVar12 = FUN_20156260(param_2 - iVar8,uVar5);
    iVar8 = iVar8 + uVar5 * iVar12;
    uVar3 = (uint)*(ushort *)(param_1 + 4) - uVar5 * iVar12;
    if (uVar3 < uVar5) {
      *puVar9 = (ushort)uVar3;
    }
    else {
      *puVar9 = uVar1;
    }
    iVar12 = FUN_20144a10(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
      *piVar10 = iVar8;
      uVar2 = FUN_20143f78(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  else {
    *puVar9 = *(ushort *)(param_1 + 4);
    uVar4 = FUN_201449cc(param_1,param_2);
    iVar8 = FUN_20144980(param_1,uVar4);
    iVar12 = FUN_20144a10(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
LAB_201441cc:
      *piVar10 = iVar8;
      uVar2 = FUN_20143f78(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  return iVar12;
}


// ===== FUN_20144268 @ 20144268 (420 bytes)

void FUN_20144268(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar7 = (uint)*(ushort *)(param_1 + 0x50);
  puVar3 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
           *(int *)(param_1 + 0x4c));
  uVar1 = *(ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
            *(int *)(param_1 + 0x4c) + param_2 * 2 + -2);
  uVar4 = 1;
  if (*(char *)(param_1 + 0x10) == '@') {
    if (uVar7 != 0) {
      do {
        uVar2 = *puVar3;
        if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
           (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
          if (uVar4 == param_2) {
            *puVar3 = uVar2 & 0x8000 | 1;
          }
          if ((uVar2 & 0x7fff) == 0) {
            return;
          }
        }
        else {
          uVar5 = uVar2 + 1;
          uVar6 = uVar2 + 1;
          *puVar3 = uVar5;
          if ((uVar2 & 0x8000) == 0) {
            if (uVar6 < 0x8000) goto LAB_20144364;
            uVar6 = uVar5 & 0x7fff;
          }
          else {
            if (0x7fff < uVar6) {
              uVar6 = uVar5 & 0x7fff;
              *puVar3 = uVar6;
            }
            uVar6 = uVar6 | 0x8000;
          }
          *puVar3 = uVar6;
        }
LAB_20144364:
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1 & 0xffff;
        if (*(ushort *)(param_1 + 0x50) < uVar4) {
          return;
        }
      } while( true );
    }
  }
  else if (uVar7 != 0) {
    do {
      uVar2 = *puVar3;
      if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
         (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
        if (uVar4 == param_2) {
          *puVar3 = uVar2 & 0x8000 | 1;
        }
        if ((uVar2 & 0x7fff) == 0) {
          return;
        }
      }
      else {
        uVar5 = uVar2 + 1;
        uVar6 = uVar2 + 1;
        *puVar3 = uVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar6 < 0x8000) goto LAB_20144300;
          uVar6 = uVar5 & 0x7fff;
        }
        else {
          if (0x7fff < uVar6) {
            uVar6 = uVar5 & 0x7fff;
            *puVar3 = uVar6;
          }
          uVar6 = uVar6 | 0x8000;
        }
        *puVar3 = uVar6;
      }
LAB_20144300:
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 <= *(ushort *)(param_1 + 0x50));
  }
  return;
}


// ===== FUN_2014440c @ 2014440c (284 bytes)

int FUN_2014440c(int param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar4 = *(undefined4 **)(param_1 + 0x4c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar6 = 0;
    iVar2 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
    uVar1 = (uint)*(ushort *)(param_1 + 0x50);
    puVar3 = (ushort *)((iVar2 + 6) * uVar1 + (int)puVar4);
    puVar5 = (undefined4 *)((iVar2 + 4) * uVar1 + (int)puVar4);
    puVar7 = puVar4 + uVar1;
    if (*(char *)(param_1 + 0x10) == '@') {
      if (uVar1 != 0) {
        do {
          if ((*puVar3 & 0x8000) != 0) {
            iVar2 = FUN_20144ac0(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
            if (iVar2 != 0) {
              return iVar2;
            }
            *puVar3 = *puVar3 & 0x7fff;
          }
          iVar6 = iVar6 + 1;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = (undefined4 *)((int)puVar5 + 2);
          puVar7 = (undefined4 *)
                   (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
        } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
      }
    }
    else if (uVar1 != 0) {
      do {
        if ((*puVar3 & 0x8000) != 0) {
          iVar2 = FUN_20144ac0(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
          *puVar3 = *puVar3 & 0x7fff;
        }
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 2);
        puVar7 = (undefined4 *)
                 (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
      } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
    }
  }
  return 0;
}


// ===== FUN_2014455c @ 2014455c (248 bytes)

int FUN_2014455c(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  puVar4 = *(uint **)(param_1 + 0x44);
  if (puVar4 != (uint *)0x0) {
    puVar6 = puVar4 + *(ushort *)(param_1 + 0x48);
    puVar7 = puVar6;
    for (; puVar4 != puVar6; puVar4 = puVar4 + 1) {
      if ((*puVar4 & 0x80000000) != 0) {
        uVar5 = *puVar4 & 0x7fffffff;
        uVar1 = 0;
        sVar3 = 0;
        if (*(ushort *)(param_1 + 0x4a) != 0) {
          do {
            if (uVar5 + uVar1 < (uint)*(ushort *)(param_1 + 6) + *(int *)(param_1 + 0xc)) {
              sVar3 = sVar3 + 1;
            }
            uVar1 = uVar1 + 1 & 0xffff;
          } while (uVar1 < *(ushort *)(param_1 + 0x4a));
        }
        iVar2 = FUN_20144ac0(param_1,uVar5,puVar7,sVar3);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
           (iVar2 = FUN_20144ac0(param_1,*(int *)(param_1 + 0xc) + uVar5,puVar7,1), iVar2 != 0)) {
          return iVar2;
        }
        *puVar4 = *puVar4 & 0x7fffffff;
      }
      puVar7 = (uint *)(*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + (int)puVar7);
    }
  }
  return 0;
}


// ===== FUN_20144654 @ 20144654 (52 bytes)

undefined4 FUN_20144654(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014455c(param_1);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_20144688 @ 20144688 (104 bytes)

int FUN_20144688(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144654(param_1), iVar1 == 0)) {
    iVar1 = FUN_2014d9c0();
    if (iVar1 == 0) {
      iVar1 = FUN_2014440c(param_1);
      FUN_2014da64(param_1);
    }
    else {
      iVar1 = -0x25;
    }
    return iVar1;
  }
  return iVar1;
}


// ===== FUN_201446bc @ 201446bc (20 bytes)

void FUN_201446bc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_20144688();
  FUN_20144800(uVar1,0);
  return;
}


// ===== FUN_201446d0 @ 201446d0 (292 bytes)

void FUN_201446d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 != 0) {
    FUN_20144800(iVar1,0);
    return;
  }
  iVar1 = FUN_2014db6c(param_1);
  if (iVar1 != 0) {
    FUN_20144800(0xffffffde,0);
    return;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_2014d148(*(int *)(param_1 + 0x44),0,
                 (uint)*(ushort *)(param_1 + 0x48) * (uint)*(ushort *)(param_1 + 0x4a) * 0x206,
                 *(undefined4 *)(param_1 + 0x6c));
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_2014d148(*(int *)(param_1 + 0x58),0,*(undefined4 *)(param_1 + 0x5c),
                 *(undefined4 *)(param_1 + 0x6c));
    FUN_20149824(param_1,0);
    FUN_20149824(param_1,1);
    if (*(char *)(param_1 + 0x10) == ' ') {
      FUN_20149824(param_1,*(undefined4 *)(param_1 + 0x34));
    }
  }
  FUN_2014dc10(param_1);
  iVar1 = FUN_2014d9c0(param_1);
  if (iVar1 != 0) {
    FUN_20144800(0xffffffdb,0);
    return;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_2014d148(*(int *)(param_1 + 0x4c),0,
                 (uint)*(ushort *)(param_1 + 0x50) * (uint)*(ushort *)(param_1 + 0x52) * 0x208,
                 *(undefined4 *)(param_1 + 0x6c));
  }
  FUN_2014da64(param_1);
  FUN_20144800(0);
  return;
}


// ===== FUN_20144800 @ 20144800 (52 bytes)

undefined4 FUN_20144800(int param_1,int param_2)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  FUN_2014d98c(param_1);
  if (param_2 != 0) {
    *(int *)(param_2 + 0x10) = param_1;
  }
  if (param_1 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

