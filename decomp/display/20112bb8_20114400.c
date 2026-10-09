// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20112bb8 @ 20112bb8 (268 bytes)

void FUN_20112bb8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined8 uVar5;
  undefined2 uVar7;
  undefined4 uVar6;
  
  FUN_201637d8(&DAT_20800208,0xff,param_3,param_4,param_4);
  uVar7 = (undefined2)((uint)param_4 >> 0x10);
  FUN_201637d8(&DAT_2080020e,0xff);
  DAT_208001f8 = itron_acre_flg(0,&DAT_201655e8);
  if (((0 < DAT_208001f8) && (iVar3 = itron_acre_tsk(0,&DAT_201655cc), 0 < iVar3)) &&
     (iVar3 = itron_sta_tsk(iVar3,0), iVar3 == 0)) {
    FUN_20112aec();
    iVar3 = itron_acre_tsk(0,&DAT_20165594);
    if ((0 < iVar3) && (iVar4 = itron_sta_tsk(iVar3,0), iVar4 == 0)) {
      FUN_20116768(iVar3,1);
      iVar3 = itron_acre_tsk(0,&DAT_201655b0);
      if ((0 < iVar3) && (iVar4 = itron_sta_tsk(iVar3,0), iVar4 == 0)) {
        FUN_20116768(iVar3,2);
        uVar1 = DAT_fcfef802;
        DAT_fcfef802 = uVar1 & 0xfcff;
        uVar2 = DAT_fcfef802;
        uVar6 = CONCAT22(uVar7,uVar2);
        uVar1 = DAT_fcfef802;
        DAT_fcfef802 = uVar1 | 0x300;
        uVar5 = FUN_2014f1a8(0,&DAT_20165580);
        if (0 < (int)uVar5) {
          FUN_2011775c(0x24,(int)((ulonglong)uVar5 >> 0x20),extraout_r2,uVar6);
          return;
        }
      }
    }
  }
  return;
}


// ===== FUN_20112cc4 @ 20112cc4 (136 bytes)

void FUN_20112cc4(void)

{
  int iVar1;
  
  iVar1 = FUN_201309b4();
  if (iVar1 == 0) {
    if ((DAT_208001e7 != '\0') || (DAT_208001e5 == '\x01')) {
      FUN_2011275c(4,(int)(char)DAT_20800208);
      FUN_20115b04(&DAT_208d99b8);
    }
    if ((DAT_208001e8 != '\0') || (DAT_208001e6 == '\x01')) {
      FUN_2011275c(5,(int)(char)DAT_2080020e);
      FUN_20115b04(&DAT_208d99bd);
      return;
    }
  }
  return;
}


// ===== FUN_20112da4 @ 20112da4 (184 bytes)

int FUN_20112da4(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_2 - 0x1eU < 9) {
    return param_2 + 0x13;
  }
  if (param_2 != 0x27) {
    if (param_2 - 4U < 0x1a) {
      return param_2 + 0x5d;
    }
    if (param_2 - 0x59U < 9) {
      return param_2 + -0x30;
    }
    if (param_2 != 0x62) {
      if (param_2 == 0x87) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x5c;
        }
        else {
          iVar1 = 0x5f;
        }
        return iVar1;
      }
      if (param_2 == 0x2d) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2d;
        }
        else {
          iVar1 = 0x3d;
        }
        return iVar1;
      }
      if (param_2 == 0x37) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2e;
        }
        else {
          iVar1 = 0x3e;
        }
        return iVar1;
      }
      if (param_2 == 0x38) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2f;
        }
        else {
          iVar1 = 0x3f;
        }
        return iVar1;
      }
      if (param_2 == 0x2c) {
        iVar1 = 0x20;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  return 0x30;
}


// ===== FUN_20112e5c @ 20112e5c (216 bytes)

int * FUN_20112e5c(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *extraout_r3;
  
  iVar3 = 0;
  for (iVar2 = 0; (iVar2 < *(int *)(param_3 + 8) && (*(char *)(param_3 + iVar2 + 0xc) != '\0'));
      iVar2 = iVar2 + 1) {
    iVar3 = iVar3 + 1;
  }
  if (1 < iVar3) {
    return (int *)0x0;
  }
  cVar1 = *(char *)(param_3 + 0xc);
  if (cVar1 == '\0' && *(char *)(param_3 + 5) == '\0') {
    return (int *)0x0;
  }
  iVar2 = 0;
  if (cVar1 != '(' && cVar1 != 'X') {
    if (cVar1 != ')') {
      if (cVar1 != '*') {
        iVar2 = FUN_20112da4(param_1);
        if (iVar2 < 0) {
          return (int *)0x0;
        }
        uVar4 = *extraout_r3;
        if (0x1e < uVar4) {
          return (int *)0x0;
        }
        *extraout_r3 = uVar4 + 1;
        *(char *)((int)extraout_r3 + uVar4 + 4) = (char)iVar2;
        return (int *)0x0;
      }
      if (*param_1 < 1) {
        return (int *)0x0;
      }
      iVar2 = *param_1 + -1;
    }
    *param_1 = iVar2;
    return (int *)0x0;
  }
  *(undefined1 *)((int)param_1 + *param_1 + 4) = 0;
  *param_1 = 0;
  return param_1 + 1;
}


// ===== FUN_20112f3c @ 20112f3c (164 bytes)

void FUN_20112f3c(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar3 = 0;
  if (param_2 == 0) {
    do {
      if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
        (&DAT_2080023c)[iVar3] = 0;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    return;
  }
  iVar3 = 0;
  do {
    if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
      iVar2 = 0;
      do {
        if ((ushort)(&DAT_2080023c)[iVar2] == param_2) {
          bVar1 = false;
          goto LAB_20112fcc;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      if (bVar1) {
        (&DAT_2080023c)[iVar3] = (ushort)param_2;
      }
    }
LAB_20112fcc:
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return;
    }
  } while( true );
}


// ===== FUN_20112fe0 @ 20112fe0 (200 bytes)

bool FUN_20112fe0(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  bVar6 = false;
  iVar3 = 0;
  switch(param_1) {
  default:
    iVar5 = 4;
    break;
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
    iVar5 = 3;
  }
  iVar4 = 0;
  if (iVar5 != 0) {
    iVar1 = param_1 * 6;
    do {
      sVar2 = (&DAT_2080023c)[iVar4];
      if (sVar2 == 0) break;
      if ((sVar2 == *(short *)(&DAT_20165678 + iVar1)) ||
         (sVar2 == *(short *)(&DAT_2016567a + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      if ((param_1 == 2 || param_1 == 6) && (sVar2 == *(short *)(&DAT_2016567c + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (((param_1 == 2 || param_1 == 6) ||
      (bVar6 = iVar3 == 2, (param_1 == 0 || param_1 == 2) || param_1 == 6)) && (iVar3 == 3)) {
    bVar6 = true;
  }
  return bVar6;
}


// ===== FUN_201130c8 @ 201130c8 (60 bytes)

byte FUN_201130c8(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  do {
    iVar2 = FUN_20112fe0(bVar1);
    if (iVar2 != 0) {
      return bVar1;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return 0;
}


// ===== FUN_20113104 @ 20113104 (164 bytes)

void FUN_20113104(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      uVar1 = (&DAT_20165626)[iVar3 * 4 + iVar2];
      if (((&DAT_208d9a60)[iVar3 * 4 + iVar2] == 1) && ((&DAT_208d9b10)[iVar3 * 4 + iVar2] == 0)) {
        if (DAT_20800214 != '\0') {
          DAT_20800214 = '\0';
          (&DAT_208d9b68)[iVar3 * 4 + iVar2] = (&DAT_208d9b68)[iVar3 * 4 + iVar2] + 1;
          (&DAT_208d9ab8)[iVar3 * 4 + iVar2] = 1;
        }
        FUN_20112f3c(0,uVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


// ===== FUN_201131a8 @ 201131a8 (12 bytes)

void FUN_201131a8(undefined4 param_1)

{
  DAT_208d9af8 = param_1;
  return;
}


// ===== FUN_201131b4 @ 201131b4 (52 bytes)

void FUN_201131b4(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (param_1 < *(ushort *)(param_2 + uVar1 * 2)) {
      return;
    }
    iVar2 = iVar2 + 1;
    uVar1 = uVar1 + 1 & 0xff;
  } while (iVar2 < 5);
  return;
}


// ===== FUN_201131e8 @ 201131e8 (136 bytes)

undefined4 FUN_201131e8(undefined4 param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 1 << (param_2 & 0xff);
  switch(param_1) {
  case 2:
    uVar2 = DAT_fcfe3208;
    break;
  case 3:
    uVar2 = DAT_fcfe320c;
    break;
  default:
    goto switchD_20113204_caseD_4;
  case 7:
    uVar2 = DAT_fcfe321c;
    break;
  case 8:
    uVar2 = DAT_fcfe3220;
    break;
  case 9:
    uVar2 = DAT_fcfe3224;
    break;
  case 10:
    uVar2 = DAT_fcfe3228;
    if ((uVar2 & uVar1) != 0) {
      return 1;
    }
    return 0;
  }
  if ((uVar2 & uVar1) != 0) {
    return 1;
  }
switchD_20113204_caseD_4:
  return 0;
}


// ===== FUN_20113294 @ 20113294 (512 bytes)

void FUN_20113294(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  puVar2 = &local_20;
  uStack_1c = 0;
  local_20 = CONCAT13((char)param_1,CONCAT12((char)((uint)param_1 >> 8),CONCAT11(param_2,0xe0)));
  iVar1 = FUN_20116dac();
  if (iVar1 == 0) goto LAB_20113460;
  if (DAT_20800495 == '\0') {
    if (local_20._1_1_ == '\0') {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
LAB_2011343c:
      if (local_20._3_1_ != '\x0f') goto LAB_20113460;
    }
    else {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
      if (local_20._3_1_ != '\0') goto LAB_2011343c;
    }
    iVar1 = FUN_20115018();
    if (iVar1 == 0) goto LAB_20113460;
    uVar3 = 5;
  }
  else {
    if ((DAT_208f0b2a != '{') || (DAT_208f0b2b == '\0')) {
      if ((DAT_2080049f == '\0') || (DAT_20450034 == '|')) {
        if (DAT_20800219 == '\0') {
          if (local_20._1_1_ == '\0') {
            if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
              if (DAT_20800216 == '\0') {
                return;
              }
              DAT_20800216 = '\0';
            }
          }
          else if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
            DAT_20800216 = '\x01';
          }
        }
        else {
          if (local_20._1_1_ != '\x02') {
            DAT_20800219 = 0;
            return;
          }
          DAT_20800219 = '\x01';
          if (local_20._2_1_ != '\x03') {
            DAT_20800219 = 1;
            return;
          }
          if (local_20._3_1_ != '\0') {
            DAT_20800219 = 1;
            return;
          }
        }
        mainlink_queue_frame(&local_20,5);
      }
      else {
        local_18 = 0xe5;
        mainlink_queue_frame(&local_18,4);
        DAT_2080049f = '\0';
        DAT_20800219 = '\x01';
      }
      goto LAB_20113460;
    }
    local_18 = CONCAT31(local_18._1_3_,0xe4);
    if (DAT_20800218 == '\0') goto LAB_20113460;
    uVar3 = 4;
    DAT_20800218 = '\0';
    DAT_20800488 = 1;
    puVar2 = &local_18;
  }
  mainlink_queue_frame(puVar2,uVar3);
LAB_20113460:
  if (((local_20._1_1_ == '\x02') && (local_20._2_1_ == '\x03')) && (local_20._3_1_ == '\0')) {
    DAT_20800216 = 0;
    FUN_2011722c();
    return;
  }
  return;
}


// ===== FUN_201134d0 @ 201134d0 (80 bytes)

void FUN_201134d0(int param_1)

{
  int iVar1;
  undefined4 local_20 [4];
  
  iVar1 = 0;
  local_20[0] = 1;
  local_20[1] = 2;
  local_20[2] = 7;
  local_20[3] = 8;
  do {
    if (iVar1 == param_1) {
      FUN_20100414();
    }
    else {
      FUN_20100838(8,local_20[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return;
}


// ===== FUN_20113558 @ 20113558 (188 bytes)

void FUN_20113558(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_38 [12];
  int local_2c;
  int local_28;
  
  iVar2 = 1;
  do {
    uVar1 = FUN_201131e8(*(undefined4 *)(&DAT_208002a4 + iVar2 * 0x10),
                         *(undefined4 *)(iVar2 * 0x10 + 0x208002a8));
    (&DAT_208d9af8)[iVar2] = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  DAT_20800230 = FUN_201131e8(DAT_20800304,DAT_20800308);
  iVar2 = 0;
  do {
    FUN_201134d0(iVar2);
    iVar3 = 0;
    do {
      uVar1 = FUN_201131e8((&DAT_20800244)[iVar3 * 6],(&DAT_20800248)[iVar3 * 6]);
      iVar4 = iVar3 + 1;
      (&DAT_208d9b10)[iVar3 * 4 + iVar2] = uVar1;
      iVar3 = iVar4;
    } while (iVar4 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_201110cc(auStack_38);
  DAT_2080021e = (undefined2)((uint)(local_2c << 0xc) >> 0x10);
  FUN_201110cc(auStack_38);
  DAT_20800220 = (short)((uint)(local_28 << 0xc) >> 0x10);
  return;
}


// ===== FUN_20113614 @ 20113614 (540 bytes)

void FUN_20113614(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = 0;
  do {
    if ((0 < (int)(&DAT_208d9ba8)[iVar2]) && ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]))
    {
      (&DAT_208d9ba8)[iVar2] = (&DAT_208d9ba8)[iVar2] + 1;
    }
    if ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]) {
      if (2 < (int)(&DAT_208d9ba8)[iVar2]) {
        (&DAT_208d9a48)[iVar2] = 1;
        (&DAT_208d9ba8)[iVar2] = 0;
      }
    }
    else {
      (&DAT_208d9ba8)[iVar2] = 1;
      (&DAT_208002ac)[iVar2 * 4] = (&DAT_208d9af8)[iVar2];
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if ((0 < DAT_20800238) && (DAT_2080030c == DAT_20800230)) {
    DAT_20800238 = DAT_20800238 + 1;
  }
  if (DAT_2080030c == DAT_20800230) {
    if (2 < DAT_20800238) {
      DAT_20800228 = 1;
      DAT_20800238 = 0;
    }
  }
  else {
    DAT_20800238 = 1;
    DAT_2080030c = DAT_20800230;
  }
  iVar2 = 0;
  do {
    iVar3 = 0;
    do {
      iVar6 = (&DAT_208d9bc0)[iVar2 * 4 + iVar3];
      if ((0 < iVar6) &&
         ((&DAT_208d9b10)[iVar2 * 4 + iVar3] == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2])) {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = iVar6 + 1;
      }
      iVar6 = (&DAT_208d9b10)[iVar2 * 4 + iVar3];
      if (iVar6 == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2]) {
        if (2 < (int)(&DAT_208d9bc0)[iVar2 * 4 + iVar3]) {
          (&DAT_208d9a60)[iVar2 * 4 + iVar3] = 1;
          (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 0;
        }
      }
      else {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 1;
        (&DAT_20800244)[iVar2 * 6 + iVar3 + 2] = iVar6;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  uVar4 = FUN_201131b4((undefined1)DAT_2080021e,&DAT_20800314);
  uVar5 = FUN_201131b4((undefined1)DAT_20800220,&DAT_2080031e);
  iVar2 = 0;
  while (((byte)(&DAT_201655f4)[iVar2 * 2] != uVar4 || ((byte)(&DAT_201655f5)[iVar2 * 2] != uVar5)))
  {
    iVar2 = iVar2 + 1;
    if (0x18 < iVar2) {
      uVar4 = 0;
LAB_20113520:
      if (DAT_2080021b == uVar4) {
        bVar1 = (byte)uVar4;
        if (DAT_2080021c != '\x02') {
          DAT_2080021c = DAT_2080021c + '\x01';
          bVar1 = DAT_2080021a;
        }
      }
      else {
        DAT_2080021c = '\0';
        bVar1 = DAT_2080021a;
        DAT_2080021b = (byte)uVar4;
      }
      DAT_2080021a = bVar1;
      return;
    }
  }
  uVar4 = iVar2 + 1U & 0xff;
  goto LAB_20113520;
}


// ===== FUN_201137f8 @ 201137f8 (1140 bytes)

void FUN_201137f8(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    do {
      FUN_201525f8(0xffffffff);
    } while (DAT_20800217 != '\0');
    if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
      DAT_20800218 = 1;
    }
    FUN_20113558();
    FUN_20113614();
    if (DAT_20800228 == 1) {
      if (DAT_20800230 == 0) {
        if (DAT_20800215 != '\0') {
          FUN_20113294(DAT_20800310,1);
          DAT_20800215 = '\0';
          DAT_20800234 = DAT_20800234 + 1;
          DAT_2080022c = 1;
        }
      }
      else {
        FUN_20113294(DAT_20800310,0);
        DAT_20800215 = '\x01';
        DAT_20800234 = 0;
        DAT_2080022c = 0;
      }
      DAT_20800228 = 0;
    }
    if (DAT_2080022c == 1) {
      if (DAT_20800234 < 1000) {
        DAT_20800234 = DAT_20800234 + 1;
        goto LAB_201138dc;
      }
LAB_201138e4:
      FUN_20113294(DAT_20800310,2);
      DAT_20800234 = 0;
      DAT_2080022c = 0;
    }
    else {
LAB_201138dc:
      if (999 < DAT_20800234) goto LAB_201138e4;
    }
    iVar4 = 0;
    do {
      if ((&DAT_208d9a48)[iVar4] == 1) {
        if ((&DAT_208d9af8)[iVar4] == 0) {
          if ((DAT_20800214 != '\0') && (iVar2 = FUN_201025c4(), iVar2 == 0)) {
            FUN_20113294((&DAT_208002b0)[iVar4 * 8],1);
            DAT_20800214 = '\0';
            (&DAT_208d9b50)[iVar4] = (&DAT_208d9b50)[iVar4] + 1;
            (&DAT_208d9aa0)[iVar4] = 1;
          }
          FUN_20112f3c(0,(&DAT_208002b0)[iVar4 * 8]);
        }
        else {
          if ((DAT_2080023c == (&DAT_208002b0)[iVar4 * 8]) && (DAT_20800214 == '\0')) {
            FUN_20113294((&DAT_208002b0)[iVar4 * 8],0);
            DAT_20800214 = '\x01';
          }
          FUN_20112f3c((&DAT_208002b0)[iVar4 * 8],0);
          (&DAT_208d9b50)[iVar4] = 0;
          (&DAT_208d9aa0)[iVar4] = 0;
        }
        (&DAT_208d9a48)[iVar4] = 0;
      }
      iVar2 = (&DAT_208d9b50)[iVar4];
      if ((&DAT_208d9aa0)[iVar4] == 1) {
        if (iVar2 < 1000) {
          iVar2 = iVar2 + 1;
          (&DAT_208d9b50)[iVar4] = iVar2;
          goto LAB_201139f0;
        }
LAB_201139f8:
        FUN_20113294((&DAT_208002b0)[iVar4 * 8],2);
        (&DAT_208d9b50)[iVar4] = 0;
        (&DAT_208d9aa0)[iVar4] = 0;
      }
      else {
LAB_201139f0:
        if (999 < iVar2) goto LAB_201139f8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    iVar4 = FUN_20116dac();
    if ((iVar4 != 0) || (DAT_2080049b != '\0')) {
      iVar4 = 0;
      do {
        iVar2 = 0;
        do {
          sVar1 = (&DAT_20165626)[iVar4 * 4 + iVar2];
          if ((&DAT_208d9a60)[iVar4 * 4 + iVar2] == 1) {
            if ((&DAT_208d9b10)[iVar4 * 4 + iVar2] == 0) {
              if (DAT_20800214 != '\0') {
                FUN_20113294(sVar1,1);
                DAT_20800214 = '\0';
                (&DAT_208d9b68)[iVar4 * 4 + iVar2] = (&DAT_208d9b68)[iVar4 * 4 + iVar2] + 1;
                (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 1;
              }
              FUN_20112f3c(0,sVar1);
            }
            else {
              if (DAT_2080023c == sVar1) {
                FUN_20113294(sVar1,0);
                DAT_20800214 = '\x01';
              }
              FUN_20112f3c(sVar1,0);
              (&DAT_208d9b68)[iVar4 * 4 + iVar2] = 0;
              (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 0;
            }
            (&DAT_208d9a60)[iVar4 * 4 + iVar2] = 0;
          }
          iVar3 = (&DAT_208d9b68)[iVar4 * 4 + iVar2];
          if ((&DAT_208d9ab8)[iVar4 * 4 + iVar2] == 1) {
            if (iVar3 < 1000) {
              iVar3 = iVar3 + 1;
              (&DAT_208d9b68)[iVar4 * 4 + iVar2] = iVar3;
              goto LAB_20113b38;
            }
LAB_20113b40:
            FUN_20113294(sVar1,2);
            (&DAT_208d9b68)[iVar4 * 4 + iVar2] = 0;
            (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 0;
          }
          else {
LAB_20113b38:
            if (999 < iVar3) goto LAB_20113b40;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      if (DAT_2080021a != 0) {
        if ((DAT_2080023c == (&DAT_20165644)[DAT_2080021a]) && (DAT_2080021c == '\0')) {
          FUN_20113294((&DAT_20165644)[DAT_2080021a],0);
          DAT_20800214 = '\x01';
          FUN_20112f3c((&DAT_20165644)[DAT_2080021a],0);
          DAT_2080021a = 0;
          DAT_20800224 = 0;
        }
        if (DAT_2080021c == '\x02') {
          if ((DAT_20800214 != '\0') && (DAT_20800224 == 0)) {
            FUN_20113294((&DAT_20165644)[DAT_2080021a],1);
            DAT_20800214 = '\0';
            FUN_20112f3c(0,(&DAT_20165644)[DAT_2080021a]);
          }
          if ((DAT_2080023c == (&DAT_20165644)[DAT_2080021a]) && (DAT_20800224 < 1000)) {
            DAT_20800224 = DAT_20800224 + 1;
          }
          if (DAT_20800224 == 1000) {
            FUN_20113294((&DAT_20165644)[DAT_2080021a],2);
            DAT_20800224 = DAT_20800224 + 1;
          }
        }
      }
    }
  } while( true );
}


// ===== FUN_20113c6c @ 20113c6c (24 bytes)

bool FUN_20113c6c(void)

{
  return DAT_208d9aac == 1;
}


// ===== FUN_20113c84 @ 20113c84 (68 bytes)

void FUN_20113c84(void)

{
  int iVar1;
  int iVar2;
  
  FUN_201131a8(1);
  iVar1 = itron_acre_tsk(0,&DAT_201656a8);
  if ((0 < iVar1) && (iVar2 = itron_sta_tsk(iVar1,0), iVar2 == 0)) {
    FUN_20116768(iVar1,4);
    return;
  }
  return;
}


// ===== FUN_20113d00 @ 20113d00 (16 bytes)

void FUN_20113d00(void)

{
  DAT_20800217 = 1;
  return;
}


// ===== FUN_20113d10 @ 20113d10 (16 bytes)

void FUN_20113d10(void)

{
  DAT_20800217 = 0;
  return;
}


// ===== FUN_20113d20 @ 20113d20 (76 bytes)

void FUN_20113d20(void)

{
  byte bVar1;
  
  DAT_fcff0300 = 0x22;
  DAT_fcff0306 = 0;
  DAT_fcff0308 = 19999;
  DAT_fcff030a = 0;
  DAT_fcff030c = 0;
  DAT_fcff030e = 0;
  DAT_fcff0302 = 0x12;
  DAT_fcff0301 = 2;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 1;
  return;
}


// ===== FUN_20113db8 @ 20113db8 (84 bytes)

void FUN_20113db8(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = FUN_201353f8(param_1 * 20000,param_1 * 20000 >> 0x1f);
  iVar1 = FUN_201353f8(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 20000) {
    iVar1 = 19999;
  }
  DAT_fcff030a = (short)iVar1 + -1;
  return;
}


// ===== FUN_20113dc0 @ 20113dc0 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x20113d74) */
/* WARNING: Removing unreachable block (ram,0x20113d80) */

void FUN_20113dc0(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  FUN_20113d20();
  iVar1 = FUN_201353f8(1200000,0,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  iVar1 = FUN_201353f8(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 20000) {
    iVar1 = 19999;
  }
  DAT_fcff030a = (short)iVar1 + -1;
  return;
}


// ===== FUN_20113de0 @ 20113de0 (24 bytes)

void FUN_20113de0(int param_1,undefined1 param_2)

{
  (&DAT_208d9c00)[param_1 * 5] = (char)param_1;
  (&DAT_208d9c01)[param_1 * 5] = param_2;
  return;
}


// ===== FUN_20113df8 @ 20113df8 (80 bytes)

void FUN_20113df8(void)

{
  int iVar1;
  
  memclr(&DAT_208d9c40,0x5a0);
  DAT_20800330 = FUN_2015f040(&DAT_208d9c40);
  iVar1 = itron_acre_tsk(0,&DAT_201656e4);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,DAT_20800330);
    return;
  }
  return;
}


// ===== FUN_20113e4c @ 20113e4c (96 bytes)

void FUN_20113e4c(void)

{
  int iVar1;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
  return;
}


// ===== FUN_20113ea0 @ 20113ea0 (80 bytes)

void FUN_20113ea0(void)

{
  int iVar1;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
  return;
}


// ===== FUN_20113ef0 @ 20113ef0 (72 bytes)

void FUN_20113ef0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 2;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)(iVar1 + 8) = *param_1;
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  *(undefined4 *)(iVar1 + 0x10) = uVar3;
  *(undefined4 *)(iVar1 + 0x14) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)(iVar1 + 0x18) = param_1[4];
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  *(undefined4 *)(iVar1 + 0x20) = uVar3;
  *(undefined4 *)(iVar1 + 0x24) = uVar4;
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
  return;
}


// ===== FUN_20113f38 @ 20113f38 (24 bytes)

void FUN_20113f38(undefined4 param_1,undefined4 param_2)

{
  FUN_2015fa54(DAT_20800330 + 4,param_1,param_2);
  return;
}


// ===== FUN_20113f50 @ 20113f50 (24 bytes)

undefined1 FUN_20113f50(void)

{
  return *(undefined1 *)(DAT_20800330 + 0x594);
}


// ===== FUN_20113f60 @ 20113f60 (84 bytes)

void FUN_20113f60(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = DAT_20800330;
  FUN_20152bb0(*(undefined4 *)(DAT_20800330 + 0x59c),0xffffffff);
  *param_1 = *(undefined2 *)(iVar1 + 0x596);
  *param_2 = *(undefined2 *)(iVar1 + 0x598);
  FUN_201511e8(*(undefined4 *)(iVar1 + 0x59c));
  return;
}


// ===== FUN_20113f8c @ 20113f8c (80 bytes)

void FUN_20113f8c(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *unaff_r4;
  int local_4;
  
  do {
    do {
      do {
        iVar2 = itron_twai_flg(*unaff_r4,1,5,&local_4,0xffffffff);
      } while (iVar2 != 0);
    } while (local_4 != 1);
    uVar1 = DAT_fcfe3208;
    FUN_201131a8(uVar1 & 1);
    FUN_2011775c(0x25);
  } while( true );
}


// ===== FUN_20113fdc @ 20113fdc (76 bytes)

void FUN_20113fdc(void)

{
  ushort uVar1;
  
  FUN_201177a0(0x25);
  itron_set_flg(DAT_20800358,1);
  FUN_20152fac(DAT_2080035c);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 0x20) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xffdf;
  }
  return;
}


// ===== FUN_20114028 @ 20114028 (4 bytes)

void FUN_20114028(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined8 uVar4;
  
  uVar1 = DAT_fcfef802;
  DAT_fcfef802 = uVar1 & 0xf3ff;
  uVar2 = DAT_fcfef802;
  uVar1 = DAT_fcfef802;
  DAT_fcfef802 = uVar1 | 0xc00;
  DAT_20800358 = itron_acre_flg(0,&DAT_20165738);
  if (0 < DAT_20800358) {
    DAT_2080035c = itron_acre_tsk(0,&DAT_2016571c);
    if (((0 < DAT_2080035c) && (iVar3 = itron_sta_tsk(DAT_2080035c,0), iVar3 == 0)) &&
       (uVar4 = FUN_2014f1a8(0,&DAT_20165744), 0 < (int)uVar4)) {
      FUN_2011775c(0x25,(int)((ulonglong)uVar4 >> 0x20),extraout_r2,uVar2);
      return;
    }
  }
  return;
}


// ===== FUN_2011402c @ 2011402c (140 bytes)

void FUN_2011402c(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined8 uVar3;
  
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xf3ff;
  uVar1 = *(undefined2 *)(param_1 + 2);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | 0xc00;
  DAT_20800358 = itron_acre_flg(0,&DAT_20165738);
  if (0 < DAT_20800358) {
    DAT_2080035c = itron_acre_tsk(0,&DAT_2016571c);
    if (((0 < DAT_2080035c) && (iVar2 = itron_sta_tsk(DAT_2080035c,0), iVar2 == 0)) &&
       (uVar3 = FUN_2014f1a8(0,&DAT_20165744), 0 < (int)uVar3)) {
      FUN_2011775c(0x25,(int)((ulonglong)uVar3 >> 0x20),extraout_r2,uVar1);
      return;
    }
  }
  return;
}


// ===== FUN_201140d0 @ 201140d0 (12 bytes)

void FUN_201140d0(undefined4 param_1)

{
  DAT_20800364 = param_1;
  return;
}


// ===== FUN_201140dc @ 201140dc (12 bytes)

undefined4 FUN_201140dc(void)

{
  return DAT_20800364;
}


// ===== FUN_201140e8 @ 201140e8 (12 bytes)

void FUN_201140e8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_201140f4 @ 201140f4 (84 bytes)

uint FUN_201140f4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  iVar3 = *param_1;
  uVar7 = FUN_20164d54(param_1[1] - iVar3);
  uVar7 = FUN_20164da8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_3,param_4);
  uVar8 = FUN_20164d54(iVar3);
  uVar7 = FUN_20164888((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
  uVar1 = (uint)((ulonglong)uVar7 >> 0x20);
  iVar3 = ((uVar1 & 0x7fffffff) >> 0x14) - 0x400;
  bVar6 = SBORROW4(0x1e,iVar3);
  uVar2 = -iVar3 + 0x1e;
  bVar5 = uVar2 == 0;
  uVar4 = uVar2;
  if (!bVar5 && iVar3 < 0x1f) {
    bVar6 = SBORROW4(0x21,uVar2);
    uVar4 = 0x21 - uVar2;
    bVar5 = uVar2 == 0x21;
  }
  if (!bVar5 && (int)uVar4 < 0 == bVar6) {
    return ((uVar1 << 0xb | 0x80000000 | (uint)uVar7 >> 0x15) >> (uVar2 & 0xff) ^ (int)uVar1 >> 0x1f
           ) - ((int)uVar1 >> 0x1f);
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar3 != -0x3ff) {
    return (int)uVar1 >> 0x20 ^ 0x7fffffff;
  }
  FUN_20164efc((uint)uVar7);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== FUN_20114144 @ 20114144 (36 bytes)

void FUN_20114144(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x14;
  do {
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar2);
  return;
}


// ===== FUN_20114168 @ 20114168 (88 bytes)

void FUN_20114168(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    DAT_fcfe3104 = 0x20000;
    if ((param_1 & 1) == 0) {
      DAT_fcfe3104 = 0x10000;
    }
    else {
      DAT_fcfe3104 = 0x10001;
    }
    FUN_20114144(1);
    DAT_fcfe3104 = 0x20002;
    param_1 = param_1 >> 1;
    FUN_20114144(1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}


// ===== FUN_201141c0 @ 201141c0 (36 bytes)

void FUN_201141c0(undefined1 *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_20114168(*param_1);
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_201141e4 @ 201141e4 (96 bytes)

uint FUN_201141e4(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  FUN_20101f50();
  iVar3 = 0;
  do {
    uVar2 = uVar2 >> 1;
    DAT_fcfe3104 = 0x20000;
    FUN_20114144(1);
    uVar1 = DAT_fcfe3204;
    DAT_fcfe3104 = 0x20002;
    if ((uVar1 & 1) != 0) {
      uVar2 = uVar2 | 0x80;
    }
    FUN_20114144(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  FUN_20101f44();
  return uVar2;
}


// ===== FUN_20114244 @ 20114244 (36 bytes)

void FUN_20114244(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = FUN_201141e4();
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_20114268 @ 20114268 (100 bytes)

undefined4 FUN_20114268(uint param_1)

{
  undefined4 uVar1;
  
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_20114168(param_1 | 0x86);
  uVar1 = FUN_201141e4();
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  FUN_20114144(1);
  return uVar1;
}


// ===== FUN_201142cc @ 201142cc (92 bytes)

void FUN_201142cc(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10._2_2_ = (undefined2)((uint)param_4 >> 0x10);
  local_10 = CONCAT22(local_10._2_2_,CONCAT11(param_2,param_1)) | 6;
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_201141c0(&local_10,2);
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== FUN_20114328 @ 20114328 (24 bytes)

void FUN_20114328(void)

{
  DAT_fcfe3104 = 0x20002;
  DAT_fcfe3104 = 0x40000;
  return;
}


// ===== FUN_20114340 @ 20114340 (96 bytes)

void FUN_20114340(undefined4 param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_20114168(0x26);
  FUN_201141c0(param_1,7);
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== FUN_201143a0 @ 201143a0 (96 bytes)

void FUN_201143a0(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_20114168(0x66);
  FUN_201141c0(param_1 + 4,3);
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== FUN_20114400 @ 20114400 (108 bytes)

void FUN_20114400(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_20114168(0xa6);
  FUN_20114244(param_1,7);
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}

