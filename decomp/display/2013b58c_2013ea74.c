// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013b58c @ 2013b58c (12 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2013b58c(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  uVar2 = Rame8010040;
  Rame8010040 = ~uVar2;
  uVar4 = Rame8010030;
  uVar3 = Rame8010042;
  Rame8010042 = ~uVar3;
  uVar1 = Rame8010032;
  uVar5 = 0;
  uVar6 = 0;
  bVar8 = (uVar2 & 0x8000) != 0;
  iVar7 = 0;
  if (bVar8) {
    _DAT_2090bb0c = _DAT_2090bb0c + 1;
  }
  bVar9 = (uVar2 & 0x2000) != 0;
  if (bVar9) {
    _DAT_2090bb10 = _DAT_2090bb10 + 1;
  }
  bVar10 = (uVar2 & 0x400) != 0;
  bVar11 = (uVar4 & 0x400) != 0;
  if (bVar10 && bVar11) {
    uVar4 = uVar4 & 0xfbff;
    uVar5 = 8;
    _DAT_2090bb14 = _DAT_2090bb14 + 1;
  }
  bVar12 = (uVar2 & 0x200) != 0;
  bVar13 = (uVar4 & 0x200) != 0;
  if (bVar12 && bVar13) {
    uVar4 = uVar4 & 0xfdff;
    uVar5 = uVar5 | 0x10;
    _DAT_2090bb18 = _DAT_2090bb18 + 1;
  }
  if ((uVar2 & 0x100) == 0 || (uVar4 & 0x100) == 0) {
    if (((!bVar12 || !bVar13) && ((!bVar10 || !bVar11) && (!bVar9 && !bVar8))) && (uVar2 != 0)) {
      _DAT_2090bb20 = _DAT_2090bb20 + 1;
    }
  }
  else {
    uVar4 = uVar4 & 0xfeff;
    iVar7 = 1;
    _DAT_2090bb1c = _DAT_2090bb1c + 1;
    _DAT_2090bb04 = 0;
  }
  Rame8010030 = uVar4;
  if ((uVar3 & 0x800) != 0 && (uVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 2;
    _DAT_2090bb24 = _DAT_2090bb24 + 1;
  }
  if (((uVar3 & 0x1000) != 0) && (_DAT_2090bb28 = _DAT_2090bb28 + 1, (uVar1 & 0x1000) != 0)) {
    uVar5 = uVar5 | 1;
    FUN_2013b2f8(0,0);
    FUN_20139658(0,0);
  }
  if ((uVar3 & 0x20) != 0) {
    uVar6 = 2;
    _DAT_2090bb2c = _DAT_2090bb2c + 1;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 1;
    _DAT_2090bb30 = _DAT_2090bb30 + 1;
  }
  if (uVar5 != 0) {
    itron_set_flg(_DAT_2090b674,uVar5);
  }
  if (iVar7 != 0) {
    itron_set_flg(_DAT_2090b680,iVar7);
  }
  if (uVar6 != 0) {
    itron_set_flg(_DAT_2090b67c,uVar6);
    return;
  }
  return;
}


// ===== FUN_2013b598 @ 2013b598 (12 bytes)

void FUN_2013b598(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  uVar2 = Rame8207040;
  Rame8207040 = ~uVar2;
  uVar4 = Rame8207030;
  uVar3 = Rame8207042;
  Rame8207042 = ~uVar3;
  uVar1 = Rame8207032;
  uVar5 = 0;
  uVar6 = 0;
  bVar8 = (uVar2 & 0x8000) != 0;
  iVar7 = 0;
  if (bVar8) {
    iRam2090bfe4 = iRam2090bfe4 + 1;
  }
  bVar9 = (uVar2 & 0x2000) != 0;
  if (bVar9) {
    iRam2090bfe8 = iRam2090bfe8 + 1;
  }
  bVar10 = (uVar2 & 0x400) != 0;
  bVar11 = (uVar4 & 0x400) != 0;
  if (bVar10 && bVar11) {
    uVar4 = uVar4 & 0xfbff;
    uVar5 = 8;
    iRam2090bfec = iRam2090bfec + 1;
  }
  bVar12 = (uVar2 & 0x200) != 0;
  bVar13 = (uVar4 & 0x200) != 0;
  if (bVar12 && bVar13) {
    uVar4 = uVar4 & 0xfdff;
    uVar5 = uVar5 | 0x10;
    iRam2090bff0 = iRam2090bff0 + 1;
  }
  if ((uVar2 & 0x100) == 0 || (uVar4 & 0x100) == 0) {
    if (((!bVar12 || !bVar13) && ((!bVar10 || !bVar11) && (!bVar9 && !bVar8))) && (uVar2 != 0)) {
      iRam2090bff8 = iRam2090bff8 + 1;
    }
  }
  else {
    uVar4 = uVar4 & 0xfeff;
    iVar7 = 1;
    iRam2090bff4 = iRam2090bff4 + 1;
    uRam2090bfdc = 0;
  }
  Rame8207030 = uVar4;
  if ((uVar3 & 0x800) != 0 && (uVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 2;
    iRam2090bffc = iRam2090bffc + 1;
  }
  if (((uVar3 & 0x1000) != 0) && (iRam2090c000 = iRam2090c000 + 1, (uVar1 & 0x1000) != 0)) {
    uVar5 = uVar5 | 1;
    FUN_2013b2f8(1,0);
    FUN_20139658(1,0);
  }
  if ((uVar3 & 0x20) != 0) {
    uVar6 = 2;
    iRam2090c004 = iRam2090c004 + 1;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 1;
    iRam2090c008 = iRam2090c008 + 1;
  }
  if (uVar5 != 0) {
    itron_set_flg(uRam2090bb4c,uVar5);
  }
  if (iVar7 != 0) {
    itron_set_flg(uRam2090bb58,iVar7);
  }
  if (uVar6 != 0) {
    itron_set_flg(uRam2090bb54,uVar6);
    return;
  }
  return;
}


// ===== usbh_create_objects @ 2013b5bc (696 bytes)

/* m596* / udevtsk%d names */

undefined4 usbh_create_objects(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x10 + 0x2091c368;
  sprintf(iVar1,"m596i%d",param_1);
  iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
  if (-1 < iVar1) {
    *(int *)(param_2 + 0x14) = iVar1;
    iVar1 = param_1 * 0x10 + 0x2091c388;
    sprintf(iVar1,"m596r%d",param_1);
    iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
    if (-1 < iVar1) {
      *(int *)(param_2 + 0x20) = iVar1;
      iVar1 = param_1 * 0x10 + 0x2091c3a8;
      sprintf(iVar1,"m596su%d",param_1);
      iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
      if (-1 < iVar1) {
        *(int *)(param_2 + 0x1c) = iVar1;
        iVar1 = param_1 * 0x10 + 0x2091c508;
        sprintf(iVar1,"m596a%d",param_1);
        iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
        if (-1 < iVar1) {
          *(int *)(param_2 + 0x18) = iVar1;
          iVar1 = param_1 * 0x10 + 0x2091c528;
          sprintf(iVar1,"m596a%d",param_1);
          iVar1 = os_create_sem_named(&DAT_204201ec,iVar1);
          if (-1 < iVar1) {
            *(int *)(param_2 + 0x4a0) = iVar1;
            iVar1 = param_1 * 0x10 + 0x2091c548;
            sprintf(iVar1,"m596c%d",param_1);
            iVar1 = os_create_sem_named(&DAT_204201ec,iVar1);
            if (-1 < iVar1) {
              *(int *)(param_2 + 0x4a8) = iVar1;
              iVar1 = 0;
              do {
                iVar2 = param_1 * 0x30 + 0x2091c308 + iVar1 * 0x10;
                sprintf(iVar2,"m596fi%d%d",param_1,iVar1);
                iVar2 = os_create_sem_named(&DAT_204201ec,iVar2);
                if (iVar2 < 0) {
                  return 0xffffffff;
                }
                iVar3 = iVar1 * 4;
                iVar1 = iVar1 + 1;
                *(int *)(param_2 + iVar3 + 0x30) = iVar2;
              } while (iVar1 < 3);
              iVar1 = 0;
              do {
                iVar3 = param_2 + iVar1 * 0x70;
                iVar2 = param_1 * 0xa0 + 0x2091c3c8 + iVar1 * 0x10;
                *(int *)(iVar3 + 0x4c) = iVar1;
                *(int *)(iVar3 + 0x44) = param_2;
                sprintf(iVar2,"m596d%dt%d",param_1,iVar1);
                iVar2 = FUN_2014e5e4(&DAT_204201d0,iVar2);
                if (iVar2 < 0) {
                  return 0xffffffff;
                }
                iVar1 = iVar1 + 1;
                *(int *)(iVar3 + 100) = iVar2;
              } while (iVar1 < 10);
              iVar1 = param_1 * 0x10 + 0x2091c288;
              sprintf(iVar1,"m596m%d",param_1);
              DAT_20808ad8 = param_1;
              iVar1 = FUN_2014e5b0(&DAT_20808ad4,iVar1);
              if (-1 < iVar1) {
                *(int *)(param_2 + 0x24) = iVar1;
                iVar1 = param_1 * 0x10 + 0x2091c2a8;
                sprintf(iVar1,"m596r%d",param_1);
                DAT_20808af4 = param_1;
                iVar1 = FUN_2014e5b0(&DAT_20808af0,iVar1);
                if (-1 < iVar1) {
                  *(int *)(param_2 + 0x28) = iVar1;
                  iVar1 = param_1 * 0x10 + 0x2091c2e8;
                  sprintf(iVar1,"udevtsk%d",param_1);
                  iVar1 = FUN_2014e6e4(&DAT_204201dc,iVar1);
                  if (-1 < iVar1) {
                    *(int *)(&DAT_2091c214 + param_1 * 8) = iVar1;
                    iVar1 = param_1 * 0x10 + 0x2091c2c8;
                    sprintf(iVar1,"udev%d",param_1);
                    DAT_20808b10 = param_1;
                    iVar1 = FUN_2014e5b0(&DAT_20808b0c,iVar1);
                    if (-1 < iVar1) {
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== usbh_hid_init @ 2013b928 (72 bytes)

/* UHHID */

undefined4 usbh_hid_init(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    DAT_20808b2c = iVar2;
    iVar1 = FUN_2014e5b0(&DAT_20808b28,"UHHID");
    if (iVar1 < 1) {
      return 0xffffffff;
    }
    iVar2 = iVar2 + 1;
    *param_1 = iVar1;
    param_1 = param_1 + 0xc2;
  } while (iVar2 < 2);
  return 0;
}


// ===== FUN_2013b97c @ 2013b97c (56 bytes)

undefined4 FUN_2013b97c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  memclr(&DAT_2091c568,0x610);
  iVar1 = usbh_hid_init(&DAT_2091c568);
  if ((iVar1 < 0) || (iVar1 = FUN_2013c6bc(), iVar1 < 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_2013ba44 @ 2013ba44 (104 bytes)

undefined4 FUN_2013ba44(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = param_1 * 0x308;
  if (*(int *)(&DAT_2091c584 + param_1) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(&DAT_2091c57c + param_1) = 0;
    FUN_2013c798(*(undefined4 *)(&DAT_2091c56c + param_1),*(undefined4 *)(&DAT_2091c574 + param_1));
    iVar2 = 0;
    do {
      if (*(int *)(&DAT_2091c580 + param_1) == 0) break;
      itron_dly_tsk(5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 200);
    uVar1 = 0;
    *(undefined4 *)(&DAT_2091c584 + param_1) = 0;
  }
  return uVar1;
}


// ===== FUN_2013baac @ 2013baac (264 bytes)

undefined4 FUN_2013baac(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  byte local_14 [4];
  
  param_1 = param_1 * 0x308;
  if (((*(int *)(&DAT_2091c57c + param_1) != 0) && (param_2 == 0)) &&
     (*(int *)(&DAT_2091c588 + param_1) == 6)) {
    uVar1 = 0;
    local_14[0] = 0;
    if (0 < *(int *)(&DAT_2091c660 + param_1)) {
      do {
        iVar2 = uVar1 + param_1;
        if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x01') {
          if ((*param_3 & 1) != 0) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
            goto LAB_2013bb24;
          }
        }
        else {
LAB_2013bb24:
          if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x02') {
            if ((*param_3 & 2) == 0) goto LAB_2013bb6c;
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
          if (((&DAT_2091c568)[iVar2 + 0xfc] == '\x03') && ((*param_3 & 4) != 0)) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
        }
LAB_2013bb6c:
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < *(int *)(&DAT_2091c660 + param_1));
    }
    iVar2 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,9,0x200,
                         (&DAT_2091c570)[param_1],local_14,1);
    if (iVar2 == 1) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_2013bbb4 @ 2013bbb4 (124 bytes)

uint FUN_2013bbb4(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_2 & 7;
  uVar5 = 0;
  uVar3 = param_3;
  uVar4 = param_2;
  if (uVar2 != 0) {
    uVar4 = param_2 + 7 & 0xfffffff8;
    uVar3 = param_3 - (uVar4 - param_2);
  }
  uVar1 = 0;
  if (0 < (int)uVar3) {
    do {
      uVar5 = uVar5 | (uint)*(byte *)(param_1 + ((int)(uVar4 + uVar1) >> 3)) << (uVar1 & 0xff);
      uVar1 = uVar1 + 8;
    } while ((int)uVar1 < (int)uVar3);
  }
  if (uVar2 != 0) {
    uVar5 = uVar5 << (8 - uVar2 & 0xff) | (uint)(*(byte *)(param_1 + ((int)param_2 >> 3)) >> uVar2);
  }
  return (1 << (param_3 & 0xff)) - 1U & uVar5;
}


// ===== FUN_2013bc30 @ 2013bc30 (240 bytes)

void FUN_2013bc30(int *param_1,uint *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  ushort *puVar4;
  byte bVar5;
  
  pbVar3 = (byte *)*param_1;
  puVar4 = (ushort *)(pbVar3 + 1);
  bVar5 = *pbVar3 & 3;
  if ((*pbVar3 & 3) == 0) {
    *param_2 = 0;
    iVar2 = *param_1 + 1;
  }
  else if (bVar5 == 1) {
    uVar1 = *puVar4;
    *param_2 = (uint)(byte)uVar1;
    if ((param_3 != 0) && ((*puVar4 & 0x80) != 0)) {
      *param_2 = (byte)uVar1 | 0xffffff00;
    }
    iVar2 = *param_1 + 2;
  }
  else if (bVar5 == 2) {
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 3;
  }
  else {
    if (bVar5 != 3) {
      return;
    }
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 5;
  }
  *param_1 = iVar2;
  return;
}


// ===== FUN_2013bd20 @ 2013bd20 (1540 bytes)

undefined4 FUN_2013bd20(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  byte *local_40;
  uint local_3c;
  uint local_38;
  int iStack_30;
  byte *local_2c;
  int local_28;
  
  iVar7 = 0;
  local_38 = 0;
  iVar4 = param_1 + 0x205;
  local_44 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  do {
    iVar6 = iVar2 * 0x10;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(param_1 + iVar6 + 0x24) = 0xffffffff;
  } while (iVar2 < 10);
  *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x104) = 0;
  iVar2 = 0;
  local_54 = 0;
  iVar6 = 0;
  uVar5 = 0;
  local_50 = 0;
  iVar8 = 0;
  local_48 = 0;
  local_60 = -1;
  local_58 = 0;
  local_5c = -1;
  local_4c = 0;
  local_40 = param_2;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  if (0 < param_3) {
    do {
      bVar1 = *local_40 & 0xfc;
      if (bVar1 == 0x80) {
        FUN_2013bc30(&local_40,&local_3c,0);
        if ((*(int *)(param_1 + 0x20) < 0) || (local_44 != iVar6)) goto LAB_2013c034;
        if (local_48 == 1) {
          if (local_3c == 2 || local_3c == 6) {
            if (local_54 != iVar2) {
              return 0xffffffff;
            }
            iVar2 = 0;
            if (0 < local_54) {
              do {
                if ((*(byte *)(iVar4 + iVar2) - 0x30 < 10) &&
                   (iVar3 = param_1 + (*(byte *)(iVar4 + iVar2) - 0x30) * 0x10,
                   *(int *)(iVar3 + 0x24) < 0)) {
                  *(uint *)(iVar3 + 0x24) = local_58 * iVar2 + uVar5;
                  *(int *)(iVar3 + 0x28) = local_58;
                  *(undefined4 *)(iVar3 + 0x2c) = local_4c;
                  *(undefined4 *)(iVar3 + 0x30) = local_50;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < local_54);
            }
          }
        }
        else {
          if (local_48 == 7) {
            if (local_3c == 2) {
              if (((local_54 != iVar2) || (8 < local_54)) || (local_58 != 1)) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xc4) < 0) {
                *(int *)(param_1 + 200) = local_54;
                iVar3 = param_1 + 0xcc;
                *(uint *)(param_1 + 0xc4) = uVar5;
                iVar2 = local_54;
                goto LAB_2013c1cc;
              }
            }
            else {
              if (local_3c != 0) goto LAB_2013c1d4;
              bVar9 = local_54 == 8;
              if (local_54 < 9) {
                bVar9 = (uVar5 & 7) == 0;
              }
              if (!bVar9) {
                return 0xffffffff;
              }
              if (local_58 != 8) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xd4) < 0) {
                *(int *)(param_1 + 0xd8) = local_54;
                *(int *)(param_1 + 0xd4) = (int)(uVar5 + ((uint)((int)uVar5 >> 0x1f) >> 0x1d)) >> 3;
              }
            }
          }
          else {
            if ((local_48 != 9) || (local_3c != 2)) goto LAB_2013c1d4;
            if (local_54 < iVar2) {
              iVar2 = local_54;
            }
            if (0x10 < local_54) {
              return 0xffffffff;
            }
            if (local_58 != 1) {
              return 0xffffffff;
            }
            if (*(int *)(param_1 + 0xdc) < 0) {
              *(int *)(param_1 + 0xe0) = iVar2;
              iVar3 = param_1 + 0xe4;
              *(uint *)(param_1 + 0xdc) = uVar5;
LAB_2013c1cc:
              memcpy(iVar3,iVar4,iVar2);
            }
          }
          *(char *)(param_1 + 0x104) = (char)iVar6;
        }
LAB_2013c1d4:
        uVar5 = local_58 * local_54 + uVar5;
LAB_2013c034:
        iVar2 = 0;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0x80) {
        if (bVar1 == 0x18) {
          FUN_2013bc30(&local_40,&local_60,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else if (bVar1 < 0x18) {
          if (bVar1 == 4) {
            FUN_2013bc30(&local_40,&local_48,0);
          }
          else if (bVar1 == 8) {
            FUN_2013bc30(&local_40,&local_3c,0);
            local_38 = local_3c;
            if (iVar7 == 0) {
              if (((local_48 & 0xff00) == 0) && (*(int *)(param_1 + 0x20) < 0)) {
                *(uint *)(param_1 + 0x20) = local_3c;
              }
            }
            else if (iVar2 < 0x100) {
              if (local_3c < 0x100) {
                *(char *)(iVar4 + iVar2) = (char)local_3c;
                iVar2 = iVar2 + 1;
              }
              else {
                *(undefined1 *)(iVar4 + iVar2) = 0;
                iVar2 = iVar2 + 1;
              }
            }
          }
          else {
            if (bVar1 != 0x14) goto LAB_2013be4c;
            FUN_2013bc30(&local_40,&local_50,1);
          }
        }
        else if (bVar1 == 0x24) {
          FUN_2013bc30(&local_40,&local_4c,1);
        }
        else if (bVar1 == 0x28) {
          FUN_2013bc30(&local_40,&local_5c,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else {
          if (bVar1 != 0x74) goto LAB_2013be4c;
          FUN_2013bc30(&local_40,&local_58,0);
        }
      }
      else if (bVar1 == 0xa0) {
        FUN_2013bc30(&local_40,&local_3c,0);
        if ((iVar7 == 0) && (local_38 == 6)) {
          local_48 = 7;
        }
        iVar2 = 0;
        iVar7 = iVar7 + 1;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0xa1) {
        if (bVar1 == 0x84) {
          FUN_2013bc30(&local_40,&local_44,0);
          iVar3 = *(int *)(param_1 + 0x20);
          if (-1 < *(int *)(param_1 + 0x20)) {
            iVar3 = iVar6;
          }
          if (iVar3 == 0) {
            uVar5 = 8;
            iVar8 = 0;
            iVar6 = local_44;
          }
        }
        else {
          if (bVar1 == 0x90) {
            FUN_2013bc30(&local_40,&local_3c,0);
            if ((-1 < *(int *)(param_1 + 0x20)) && (local_44 == iVar6)) {
              if ((local_48 == 8) && (local_3c == 2)) {
                if (local_54 < iVar2) {
                  iVar2 = local_54;
                }
                if (8 < local_54) {
                  return 0xffffffff;
                }
                if (local_58 != 1) {
                  return 0xffffffff;
                }
                if (*(int *)(param_1 + 0xf4) < 0) {
                  *(int *)(param_1 + 0xf8) = iVar2;
                  *(int *)(param_1 + 0xf4) = iVar8;
                  memcpy(param_1 + 0xfc,iVar4,iVar2);
                }
              }
              iVar8 = local_58 * local_54 + iVar8;
            }
            goto LAB_2013c034;
          }
          if (bVar1 != 0x94) goto LAB_2013be4c;
          FUN_2013bc30(&local_40,&local_54,0);
        }
      }
      else {
        if (bVar1 == 0xb0) {
          FUN_2013bc30(&local_40,&local_3c,0);
          goto LAB_2013c034;
        }
        if (bVar1 == 0xc0) {
          FUN_2013bc30(&local_40,&local_3c,0);
          iVar2 = 0;
          iVar7 = iVar7 + -1;
          local_60 = -1;
          local_5c = -1;
        }
        else {
LAB_2013be4c:
          FUN_2013bc30(&local_40,&local_3c,0);
        }
      }
    } while ((int)local_40 - (int)local_2c < local_28);
  }
  return 0;
}


// ===== FUN_2013c32c @ 2013c32c (912 bytes)

void FUN_2013c32c(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  ushort uVar7;
  uint uVar8;
  byte *pbVar9;
  bool bVar10;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  param_1 = param_1 * 0x308;
  puVar6 = &DAT_2091c568 + param_1;
  pbVar9 = &DAT_2091c66d + param_1;
  *(undefined4 *)(&DAT_2091c580 + param_1) = 1;
  iVar3 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,9);
  if (((iVar3 == 9) && (uVar8 = (uint)*(ushort *)(&DAT_2091c66f + param_1), uVar8 < 0x100)) &&
     (uVar4 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,uVar8),
     uVar4 == uVar8)) {
    uVar7 = 0;
    pbVar9[uVar4] = 0;
    bVar10 = false;
    for (pbVar5 = pbVar9;
        ((0 < (int)uVar4 && (uVar8 = (uint)*pbVar5, uVar8 != 0)) && ((int)uVar8 <= (int)uVar4));
        pbVar5 = pbVar5 + uVar8) {
      if (pbVar5[1] == 4) {
        bVar10 = (uint)pbVar5[2] == *(uint *)(&DAT_2091c570 + param_1);
      }
      else if (((pbVar5[1] == 0x21) && (bVar10)) && (pbVar5[6] == 0x22)) {
        uVar7 = *(ushort *)(pbVar5 + 7);
      }
      uVar4 = uVar4 - uVar8;
    }
    if ((uVar7 != 0) && (uVar7 < 0x100)) {
      FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,0xb,1,(&DAT_2091c570)[param_1],0,0)
      ;
      iVar3 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x81,6,0x2200,
                           (&DAT_2091c570)[param_1],pbVar9,uVar7);
      if (((-1 < iVar3) && (iVar3 = FUN_2013bd20(puVar6,pbVar9), -1 < iVar3)) &&
         ((iVar3 = *(int *)(&DAT_2091c588 + param_1), iVar3 == 2 || iVar3 == 4 ||
          (iVar3 == 5 || iVar3 == 6)))) {
        FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,10,0,(&DAT_2091c570)[param_1],0,0
                    );
        usbhid_attach_event(*(undefined4 *)(&DAT_2091c56c + param_1),
                            *(undefined4 *)(&DAT_2091c588 + param_1));
        while ((*(int *)(&DAT_2091c57c + param_1) != 0 &&
               (iVar3 = FUN_2013c76c(*(undefined4 *)(&DAT_2091c56c + param_1),
                                     *(undefined4 *)(&DAT_2091c574 + param_1),pbVar9,
                                     *(undefined4 *)(&DAT_2091c578 + param_1)), -1 < iVar3))) {
          if (((&DAT_2091c66c)[param_1] == 0) || ((&DAT_2091c66c)[param_1] == *pbVar9)) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            local_2c = 0;
            local_48 = *(int *)(&DAT_2091c588 + param_1);
            if ((local_48 == 2 || local_48 == 4) || local_48 == 5) {
              if (-1 < *(int *)(&DAT_2091c644 + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c64c)[param_1];
                uVar2 = FUN_2013bbb4(pbVar9,*(undefined4 *)(&DAT_2091c644 + param_1),
                                     *(undefined4 *)(&DAT_2091c648 + param_1));
                local_44 = CONCAT22(uVar2,(undefined2)local_44);
              }
              uVar8 = 0;
              do {
                if (-1 < *(int *)(puVar6 + uVar8 * 0x10 + 0x24)) {
                  local_40 = CONCAT22(local_40._2_2_,
                                      (ushort)local_40 | (ushort)(1 << (uVar8 & 0xff)));
                  uVar4 = FUN_2013bbb4(pbVar9,*(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x24),
                                       *(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x28));
                  if ((*(int *)(puVar6 + uVar8 * 0x10 + 0x30) < 0) &&
                     ((uVar4 & 1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) - 1 & 0xff)) != 0)) {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) =
                         (ushort)uVar4 |
                         ~((short)(1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) & 0xff)) - 1U);
                  }
                  else {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) = (ushort)uVar4;
                  }
                }
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 < 10);
            }
            else if (local_48 == 6) {
              if (-1 < *(int *)(&DAT_2091c62c + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c634)[param_1];
                uVar1 = FUN_2013bbb4(pbVar9,*(undefined4 *)(&DAT_2091c62c + param_1),
                                     *(undefined4 *)(&DAT_2091c630 + param_1));
                local_44._0_2_ = CONCAT11(uVar1,(undefined1)local_44);
              }
              if (-1 < *(int *)(&DAT_2091c63c + param_1)) {
                local_40 = *(undefined4 *)(&DAT_2091c640 + param_1);
                memcpy(&local_3c,pbVar9 + *(int *)(&DAT_2091c63c + param_1),
                       *(undefined4 *)(&DAT_2091c640 + param_1));
              }
            }
            usbhid_report_event(*(undefined4 *)(&DAT_2091c56c + param_1),&local_48);
          }
        }
        usbhid_attach_event(*(undefined4 *)(&DAT_2091c56c + param_1),0xffffffff);
      }
    }
  }
  *(undefined4 *)(&DAT_2091c580 + param_1) = 0;
  *(undefined4 *)(&DAT_2091c588 + param_1) = 0xffffffff;
  FUN_201508ec();
  return;
}


// ===== FUN_2013c6bc @ 2013c6bc (84 bytes)

undefined4 FUN_2013c6bc(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_2091cb78 = 0;
  DAT_2091cb7c = 0;
  DAT_2091cb80 = 0;
  DAT_2091cb84 = 0;
  DAT_2091cb88 = 0;
  DAT_2091cb8c = 0;
  DAT_2091cb90 = 0;
  DAT_2091cb94 = 0;
  DAT_2091cb98 = 0;
  DAT_2091cb9c = 0;
  DAT_2091cba0 = 0;
  DAT_2091cba4 = 0;
  iVar1 = thunk_FUN_201384d4(&DAT_204201fc);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_2013c710 @ 2013c710 (92 bytes)

void FUN_2013c710(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = (&DAT_2091cb78)[param_1 * 6];
  if (iVar1 != 0) {
    local_14 = param_5;
    local_12 = (undefined2)param_7;
    local_18 = param_2;
    local_17 = param_3;
    local_16 = param_4;
    FUN_20138f00(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x8d8),&local_18,param_6,param_7
                );
  }
  return;
}


// ===== FUN_2013c76c @ 2013c76c (44 bytes)

void FUN_2013c76c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (&DAT_2091cb78)[param_1 * 6];
  if (iVar1 != 0) {
    FUN_20139624(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + param_2 * 4 + 0x8d8));
    return;
  }
  return;
}


// ===== FUN_2013c798 @ 2013c798 (316 bytes)

undefined4 FUN_2013c798(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if ((&DAT_2091cb78)[param_1 * 6] == 0) {
    return 0xffffffff;
  }
  iVar3 = *(int *)((&DAT_2091cb78)[param_1 * 6] + param_2 * 4 + 0x8d8);
  if (iVar3 != 0) {
    iVar5 = *(int *)(iVar3 + 4);
    uVar9 = *(undefined4 *)(iVar3 + 0x24);
    if (*(int *)(iVar3 + 0xc) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x3c);
    }
    iVar6 = (&DAT_20420144)[*(int *)(iVar3 + 0xc)];
    iVar7 = *(int *)(&DAT_2042016c + iVar4 * 4);
    uVar8 = *(undefined4 *)(iVar5 + iVar4 * 4 + 0x30);
    uVar2 = FUN_2013b524();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = *(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0xfffc;
    thunk_FUN_20152d28(uVar2);
    iVar3 = FUN_2014e1ec();
    while ((iVar4 = FUN_2014e1ec(), (uint)(iVar4 - iVar3) < 0x33 &&
           ((*(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0x1020) != 0))) {
      itron_dly_tsk(2);
    }
    FUN_20152bb0(uVar8,0xffffffff);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar7) = *(ushort *)(*(int *)(iVar5 + 8) + iVar7) & 0x100;
    FUN_20138740(iVar5,iVar7,0);
    uVar2 = FUN_2013b524();
    uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + iVar6);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 | 0x200;
    FUN_2013b54c();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 & 0xfdff;
    thunk_FUN_20152d28(uVar2);
    itron_set_flg(uVar9,8);
    FUN_201511e8(uVar8);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_2013c7c4 @ 2013c7c4 (156 bytes)

undefined4 FUN_2013c7c4(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  *param_1 = *(undefined4 *)(param_2 + 0x850);
  iVar1 = 1;
  if (1 < *(int *)(param_2 + 0x1c)) {
    do {
      iVar2 = param_2 + iVar1 * 0xc;
      if (((*(char *)(iVar2 + 0x861) == '\x03') && ((*(byte *)(iVar2 + 0x860) & 0x80) != 0)) &&
         ((int)param_1[1] < 0)) {
        param_1[1] = iVar1;
        param_1[2] = *(undefined4 *)(iVar2 + 0x864);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x1c));
    if (((-1 < (int)param_1[1]) && (0 < (int)param_1[2])) && ((int)param_1[2] < 0x101)) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_2013c860 @ 2013c860 (336 bytes)

int FUN_2013c860(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    iVar4 = 0;
    while( true ) {
      if ((((&DAT_2091cb7c)[iVar4 * 6] == param_1) && ((&DAT_2091cb80)[iVar4 * 6] == param_2)) &&
         ((&DAT_2091cb78)[iVar4 * 6] != 0)) break;
      iVar4 = iVar4 + 1;
      if (1 < iVar4) {
        return iVar4;
      }
    }
    FUN_2013ba44();
    (&DAT_2091cb78)[iVar4 * 6] = 0;
    return 0;
  }
  iVar4 = 0;
  while( true ) {
    iVar1 = (&DAT_2091cb78)[iVar4 * 6];
    if (iVar1 == 0) break;
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return iVar1;
    }
  }
  iVar1 = FUN_2013c7c4(&DAT_2091cb84 + iVar4 * 6,param_3);
  if (iVar1 < 0) {
    return iVar1;
  }
  (&DAT_2091cb80)[iVar4 * 6] = param_2;
  (&DAT_2091cb7c)[iVar4 * 6] = param_1;
  (&DAT_2091cb78)[iVar4 * 6] = param_3;
  if (0x100 < (int)(&DAT_2091cb8c)[iVar4 * 6]) {
    return -1;
  }
  iVar1 = iVar4 * 0x308;
  if (*(int *)(&DAT_2091c584 + iVar1) != 0) {
    return -1;
  }
  *(int *)(&DAT_2091c56c + iVar1) = iVar4;
  uVar3 = (&DAT_2091cb88)[iVar4 * 6];
  uVar2 = (&DAT_2091cb8c)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c570 + iVar1) = (&DAT_2091cb84)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c574 + iVar1) = uVar3;
  *(undefined4 *)(&DAT_2091c578 + iVar1) = uVar2;
  *(undefined4 *)(&DAT_2091c57c + iVar1) = 1;
  FUN_2014e73c(*(undefined4 *)(&DAT_2091c568 + iVar1));
  iVar4 = 0;
  do {
    if (*(int *)(&DAT_2091c580 + iVar1) != 0) break;
    itron_dly_tsk(5);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 200);
  *(undefined4 *)(&DAT_2091c584 + iVar1) = 1;
  return 0;
}


// ===== FUN_2013c928 @ 2013c928 (56 bytes)

undefined4 FUN_2013c928(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    (*(code *)((undefined4 *)param_2[1])[1])();
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x2013c95c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)param_2[1])((int)*(short *)(*param_2 + 0x2c4));
  return uVar1;
}


// ===== FUN_2013c960 @ 2013c960 (112 bytes)

undefined4 FUN_2013c960(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined2 *)(*param_1 + 0x2ac) = 0;
  (**(code **)(param_1[1] + 0x2c))();
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013c9d0 @ 2013c9d0 (488 bytes)

undefined4 FUN_2013c9d0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
    if (iVar1 != 0) {
      uVar3 = 0;
      while( true ) {
        iVar2 = (**(code **)(param_1[1] + 0x48))(1,0,0xff8000,*param_1);
        if (iVar2 != 0) {
          return 0xfffffff7;
        }
        (**(code **)(param_1[1] + 0x4c))(3,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0) break;
        uVar3 = uVar3 + 1;
        FUN_2013fd3c(1);
        if (999 < uVar3) {
          return 0xffffffff;
        }
      }
      *(undefined2 *)(*param_1 + 0x2c4) = 0xffff;
      *(undefined2 *)(*param_1 + 0x2c6) = 1;
      return 0;
    }
    (**(code **)(param_1[1] + 0x4c))(1,*param_1);
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(3,*param_1);
      uVar3 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
      if (uVar3 != 0) {
        if (2 < iVar2) {
          return 0xffffffff;
        }
        uVar4 = 0;
        do {
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar3,*param_1);
            if ((iVar2 == 0) &&
               ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
               (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
              return 0;
            }
          }
          uVar4 = uVar4 + 1;
          FUN_2013fd3c(1);
          if (999 < uVar4) {
            return 0xffffffff;
          }
        } while( true );
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xffffffff;
    }
  } while( true );
}


// ===== FUN_2013cbb8 @ 2013cbb8 (560 bytes)

int FUN_2013cbb8(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(param_1[1] + 0x48))(8,0,0x1aa,*param_1);
  if ((iVar1 == 0) &&
     ((**(code **)(param_1[1] + 0x4c))(7,*param_1), *(int *)(*param_1 + 0x2b0) == 0x1aa)) {
    iVar1 = (**(code **)(param_1[1] + 0x48))(5,0);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
        if (iVar2 == 0) {
          (**(code **)(param_1[1] + 0x4c))(1,*param_1);
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(3,*param_1);
            uVar4 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
            if (uVar4 != 0) {
              if (2 < iVar1) {
                return -1;
              }
              uVar3 = 0;
              do {
                iVar1 = (**(code **)(param_1[1] + 8))();
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
                if (iVar1 == 0) {
                  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
                  iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar4 | 0x41000000,*param_1);
                  if ((iVar1 == 0) &&
                     ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
                     (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
                    if ((*(uint *)(*param_1 + 0x2b0) & 0x40000000) == 0) {
                      return 1;
                    }
                    iVar1 = (**(code **)(param_1[1] + 0x1c))(0);
                    iVar2 = *param_1;
                    if (((*(uint *)(iVar2 + 0x2b0) & 0x1000000) != 0) && (iVar1 == 0)) {
                      *(ushort *)(iVar2 + 0x2c0) = *(ushort *)(iVar2 + 0x2c0) | 4;
                    }
                    return 0;
                  }
                }
                uVar3 = uVar3 + 1;
                FUN_2013fd3c(1);
                if (999 < uVar3) {
                  return -1;
                }
              } while( true );
            }
          }
        }
        iVar1 = iVar1 + 1;
        if (2 < iVar1) {
          return -1;
        }
      } while( true );
    }
    iVar1 = -5;
  }
  else {
    iVar1 = -9;
  }
  return iVar1;
}


// ===== FUN_2013cde8 @ 2013cde8 (256 bytes)

int FUN_2013cde8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (iVar1 = (**(code **)(param_1[1] + 0x48))(0xb,0,0,*param_1), iVar1 != 0) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return -9;
    }
  }
  if (2 < iVar2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
  if ((*(uint *)(*param_1 + 0x2b0) & 0x2c80008) != 0) {
    return -0x17;
  }
  iVar2 = FUN_2013c928(0,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(param_1[1] + 0x10))();
  if (iVar2 != 2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x38))();
  FUN_2013fd3c(10);
  iVar2 = (**(code **)(param_1[1] + 0x14))();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_2013c928(1,param_1);
  if (iVar2 == 0) {
    FUN_2013fd3c(1);
    iVar2 = (**(code **)(param_1[1] + 0x10))();
    if (iVar2 != 3) {
      return -9;
    }
    return 0;
  }
  return iVar2;
}


// ===== FUN_2013cee8 @ 2013cee8 (152 bytes)

undefined4 FUN_2013cee8(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(2,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar3) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      uVar2 = 0;
      do {
        *(undefined1 *)(*param_1 + uVar2 + 0x211) = *(undefined1 *)(*param_1 + uVar2 + 0x2b0);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 0x10);
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d0bc @ 2013d0bc (156 bytes)

undefined4 FUN_2013d0bc(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(9,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x201;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d158 @ 2013d158 (104 bytes)

undefined4 FUN_2013d158(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 2) && ((*param_1 & 0x3f) >> 2 < 3)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) && ((param_1[0xe] & 3) < 2)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== FUN_2013d1c8 @ 2013d1c8 (112 bytes)

undefined4 FUN_2013d1c8(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 4) && ((*param_1 & 0x3f) >> 2 < 5)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) &&
      (((param_1[0xc] & 0x1f) >> 2 < 8 && ((param_1[0xe] & 3) < 2)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== FUN_2013d238 @ 2013d238 (156 bytes)

undefined4 FUN_2013d238(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(10,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x211;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d398 @ 2013d398 (156 bytes)

undefined4 FUN_2013d398(uint *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar1 = (**(code **)(param_2[1] + 0x48))(0xd,0,(uint)*(ushort *)(*param_2 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar4) {
        return 0xfffffff7;
      }
      (**(code **)(param_2[1] + 0x4c))(1,*param_2);
      uVar3 = *(uint *)(*param_2 + 0x2b0);
      if ((uVar3 & *(uint *)(&DAT_2042022c + (uint)*(ushort *)(*param_2 + 0x2c6) * 4)) == 0) {
        uVar2 = 0;
        *param_1 = uVar3;
      }
      else {
        uVar2 = 0xffffffe9;
      }
      return uVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d434 @ 2013d434 (200 bytes)

undefined4 FUN_2013d434(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,0,*param_2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  else {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,param_1 << 0x10,*param_2);
      if (iVar1 == 0) {
        if (2 < iVar3) {
          return 0xfffffff7;
        }
        (**(code **)(param_2[1] + 0x4c))(1,*param_2);
        uVar2 = 0;
        if ((*(uint *)(&DAT_20420224 + (uint)*(ushort *)(*param_2 + 0x2c6) * 4) &
            *(uint *)(*param_2 + 0x2b0)) != 0) {
          uVar2 = 0xffffffe9;
        }
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return 0xfffffff7;
}


// ===== FUN_2013d4fc @ 2013d4fc (248 bytes)

int FUN_2013d4fc(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  local_10 = param_4;
  iVar1 = FUN_2013d398(&local_10,param_1);
  if (iVar1 == 0) {
    if ((local_10 & 0x1e00) == 0x800) {
      return 0;
    }
    if ((local_10 & 0x1e00) == 0xa00) {
      iVar1 = FUN_2013d434(0,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((local_10 & 0x1e00) == 0xa00) goto LAB_2013d5d4;
    }
    if ((local_10 & 0x1e00) == 0x600) {
LAB_2013d5d4:
      iVar1 = FUN_2013d434(*(undefined2 *)(*param_1 + 0x2aa),param_1);
      return iVar1;
    }
    if ((local_10 & 0x1e00) == 0xc00) {
      iVar1 = (**(code **)(param_1[1] + 0x54))(*param_1);
      if (iVar1 == 0) {
        uVar2 = 0;
        do {
          iVar1 = FUN_2013d398(&local_10,param_1);
          if (iVar1 != 0) {
            return iVar1;
          }
          if ((local_10 & 0x1e00) == 0x800) {
            return 0;
          }
          iVar1 = (**(code **)(param_1[1] + 8))();
          if (iVar1 != 0) {
            return iVar1;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < 0x20000);
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -9;
    }
  }
  return iVar1;
}


// ===== FUN_2013d5f4 @ 2013d5f4 (336 bytes)

int FUN_2013d5f4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = FUN_2013d4fc(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(8,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0x33,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x221,8);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013d744 @ 2013d744 (212 bytes)

undefined4 FUN_2013d744(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(1,*param_1);
      if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
        return 0xffffffe9;
      }
      iVar1 = (**(code **)(param_1[1] + 0x48))(6,1,*(undefined2 *)(*param_1 + 0x2ac));
      if (iVar1 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        (**(code **)(param_1[1] + 0x2c))(*(undefined2 *)(*param_1 + 0x2ac));
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xfffffff7;
    }
  } while( true );
}


// ===== FUN_2013d818 @ 2013d818 (336 bytes)

int FUN_2013d818(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = FUN_2013d4fc(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(0x40,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0xd,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x229,0x40);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013d968 @ 2013d968 (260 bytes)

int FUN_2013d968(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar2 = FUN_2013d4fc(param_2);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_2[1] + 0x50))(0x40,1,*param_2), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_2[1] + 0x48))(6,0,param_1,*param_2);
      if (iVar3 == 0) {
        if (iVar2 < 3) {
          (**(code **)(param_2[1] + 0x4c))(1,*param_2);
          if ((*(uint *)(*param_2 + 0x2b0) & 0x82f80008) != 0) {
            return -0x17;
          }
          iVar2 = (**(code **)(param_2[1] + 0x44))(4);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar1 = (**(code **)(param_2[1] + 0x5c))(iVar1 + 0x269,0x40);
          if (iVar1 != 0) {
            return iVar1;
          }
                    /* WARNING: Could not recover jumptable at 0x2013da68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar1 = (**(code **)(param_2[1] + 0x44))(2);
          return iVar1;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013de60 @ 2013de60 (296 bytes)

uint FUN_2013de60(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(param_1[1] + 0x34))(0);
  uVar1 = FUN_2013d968(0xffffff,param_1);
  if ((uVar1 == 0) &&
     (uVar1 = *(byte *)(*param_1 + 0x272) & 1, (*(byte *)(*param_1 + 0x272) & 1) != 0)) {
    iVar2 = (**(code **)(param_1[1] + 0x18))(0);
    if (iVar2 == 0) {
      uVar3 = 0;
      while ((uVar1 = (**(code **)(param_1[1] + 8))(), uVar1 == 0 &&
             (uVar1 = FUN_2013d968(0xfff0ff,param_1), uVar1 == 0))) {
        iVar2 = *param_1;
        if (800 < CONCAT11(*(undefined1 *)(iVar2 + 0x269),*(undefined1 *)(iVar2 + 0x26a)))
        goto LAB_2013df04;
        if ((*(char *)(iVar2 + 0x27a) != '\x01') || ((*(byte *)(iVar2 + 0x282) & 1) == 0)) {
          if ((~*(byte *)(iVar2 + 0x278) & 0xf) == 0) {
            return 0;
          }
          uVar1 = FUN_2013d968(0x80fff0ff,param_1);
          if (uVar1 != 0) {
            return uVar1;
          }
          if ((*(byte *)(*param_1 + 0x278) & 0xf) == 0) {
            (**(code **)(param_1[1] + 0x34))(0);
            return 0;
          }
        }
        uVar3 = uVar3 + 1;
        if (0x1ffff < uVar3) {
          return 0xffffffff;
        }
      }
    }
    else {
LAB_2013df04:
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ===== FUN_2013df88 @ 2013df88 (1084 bytes)

uint FUN_2013df88(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  *(undefined2 *)(*param_1 + 0x2c4) = 1;
  iVar7 = *param_1;
  uVar6 = *(byte *)(iVar7 + 0x221) & 0xf;
  if (((*(byte *)(iVar7 + 0x221) & 0xf) != 0) &&
     (uVar6 = *(byte *)(iVar7 + 0x205) & 0x40, (*(byte *)(iVar7 + 0x205) & 0x40) != 0)) {
    if ((*(byte *)(iVar7 + 0x2c0) & 4) == 0) {
      uVar6 = FUN_2013d968(0xffffff,param_1);
      if ((uVar6 == 0) &&
         (uVar6 = *(byte *)(*param_1 + 0x276) & 2, (*(byte *)(*param_1 + 0x276) & 2) != 0)) {
        uVar8 = 0;
        while (uVar6 = FUN_2013d968(0xfffff1,param_1), uVar6 == 0) {
          iVar7 = *param_1;
          if (800 < CONCAT11(*(undefined1 *)(iVar7 + 0x269),*(undefined1 *)(iVar7 + 0x26a))) {
            return 0;
          }
          if ((*(char *)(iVar7 + 0x27a) != '\x01') || ((*(byte *)(iVar7 + 0x286) & 2) == 0)) {
            if ((~*(byte *)(iVar7 + 0x279) & 0xf) == 0) {
              return 0;
            }
            uVar6 = FUN_2013d968(0x80fffff1,param_1);
            if (uVar6 != 0) {
              return uVar6;
            }
            if ((*(byte *)(*param_1 + 0x279) & 0xf) == 1) {
              (**(code **)(param_1[1] + 0x30))(1);
              *(undefined2 *)(*param_1 + 0x2c4) = 2;
              return 0;
            }
            uVar6 = (**(code **)(param_1[1] + 8))();
            if (uVar6 != 0) {
              return uVar6;
            }
          }
          uVar8 = uVar8 + 1;
          if (0x1ffff < uVar8) {
            return 0xffffffff;
          }
        }
      }
      return uVar6;
    }
    uVar6 = FUN_2013de60();
    if (uVar6 == 0) {
      (**(code **)(param_1[1] + 0x3c))(0);
      uVar6 = FUN_2013d968(0xffffff,param_1);
      if (uVar6 == 0) {
        uVar6 = 0xfffff1;
        bVar1 = *(byte *)(*param_1 + 0x276);
        if ((bVar1 & 8) == 0) {
          if ((bVar1 & 0x10) == 0) {
            if ((bVar1 & 4) == 0) {
              if ((bVar1 & 2) == 0) {
                return bVar1 & 2;
              }
              uVar8 = 2;
            }
            else {
              uVar8 = 4;
              uVar6 = 0xff3ff2;
            }
          }
          else {
            uVar8 = 0x10;
            uVar6 = 0xff3ff4;
          }
        }
        else {
          uVar8 = 8;
          uVar6 = 0xff3ff3;
        }
        uVar9 = 0;
        do {
          uVar3 = (**(code **)(param_1[1] + 8))();
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = FUN_2013d968(uVar6,param_1);
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = uVar6 & 0xf;
          iVar7 = (**(code **)(param_1[1] + 0x1c))(uVar3);
          iVar4 = *param_1;
          uVar2 = CONCAT11(*(undefined1 *)(iVar4 + 0x269),*(undefined1 *)(iVar4 + 0x26a));
          bVar10 = uVar2 == 800;
          if (uVar2 < 0x321) {
            bVar10 = iVar7 == 0;
          }
          if (bVar10) {
            if (((*(char *)(iVar4 + 0x27a) != '\x01') || ((*(byte *)(iVar4 + 0x286) & uVar8) == 0))
               && ((uVar6 == 0xfffff1 ||
                   ((*(char *)(iVar4 + 0x27a) != '\x01' || ((*(byte *)(iVar4 + 0x280) & 8) == 0)))))
               ) {
              if ((~*(byte *)(iVar4 + 0x279) & 0xf) == 0) {
                return 0;
              }
              if ((~(*(byte *)(iVar4 + 0x278) >> 4) & 0xf) == 0) {
                return 0;
              }
              uVar5 = FUN_2013d968(uVar6 | 0x80000000,param_1);
              if (uVar5 != 0) {
                return uVar5;
              }
              uVar5 = (uint)*(byte *)(*param_1 + 0x279);
              if (((uVar5 & 0xf) == uVar3) &&
                 ((uVar6 == 0xfffff1 ||
                  ((uVar6 & 0xffff) >> 0xc == (uint)(*(byte *)(*param_1 + 0x278) >> 4))))) {
                uVar5 = uVar5 & 0xf;
                if (uVar5 == 1) {
                  (**(code **)(param_1[1] + 0x3c))(1);
                  *(undefined2 *)(*param_1 + 0x2c2) = 1;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
                if (uVar5 == 2) {
                  (**(code **)(param_1[1] + 0x3c))(2);
                  *(undefined2 *)(*param_1 + 0x2c2) = 2;
                  *(undefined2 *)(*param_1 + 0x2c4) = 3;
                  return 0;
                }
                if (uVar5 == 3) {
                  (**(code **)(param_1[1] + 0x3c))(3);
                  *(undefined2 *)(*param_1 + 0x2c2) = 3;
                  *(undefined2 *)(*param_1 + 0x2c4) = 4;
                  return 0;
                }
                if (uVar5 == 4) {
                  (**(code **)(param_1[1] + 0x3c))(4);
                  *(undefined2 *)(*param_1 + 0x2c2) = 4;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
              }
            }
          }
          else {
            if (uVar3 == 1) {
              return 0;
            }
            if (uVar3 == 3) {
              if ((*(byte *)(iVar4 + 0x276) & 0x10) == 0) goto LAB_2013dca4;
              uVar6 = uVar6 + 1;
              uVar8 = (uVar8 & 0x7f) << 1;
            }
            else if (uVar3 == 4) {
              uVar8 = uVar8 >> 2;
              uVar6 = uVar6 - 2;
            }
            else {
LAB_2013dca4:
              uVar8 = uVar8 >> 1;
              uVar6 = uVar6 - 1;
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x20000);
        uVar6 = 0xffffffff;
      }
      return uVar6;
    }
  }
  return uVar6;
}


// ===== sd_card_identify @ 2013dff0 (624 bytes)

/* card reset/identify, card-type flags at +0x2C0/+0x2C2 */

int sd_card_identify(int *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_r4;
  
  iVar4 = (**(code **)(param_1[1] + 8))();
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined2 *)(*param_1 + 0x2c0) = 0;
  *(undefined2 *)(*param_1 + 0x2c2) = 0;
  *(undefined2 *)(*param_1 + 0x2c4) = 0;
  *(undefined2 *)(*param_1 + 0x2c6) = 0;
  (**(code **)(param_1[1] + 0x30))(0);
  iVar4 = FUN_2013c928(1,param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  FUN_2013fd3c(1);
  iVar4 = FUN_2013c960(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = FUN_2013cbb8(param_1);
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(*param_1 + 0x2c0);
    *(ushort *)(*param_1 + 0x2c0) = uVar1 | 2;
    if ((uVar1 & 4) == 0) goto LAB_2013e0c0;
    iVar4 = FUN_2013cde8(param_1);
  }
  else {
    if (iVar4 == 1) {
      *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
      goto LAB_2013e0c0;
    }
    if (iVar4 != -9) {
      return iVar4;
    }
    *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
    iVar4 = FUN_2013c9d0(param_1);
  }
  if (iVar4 != 0) {
    return iVar4;
  }
LAB_2013e0c0:
  iVar4 = FUN_2013cee8(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = 0;
  if (*(short *)(*param_1 + 0x2c6) == 1) {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0x10000,*param_1,unaff_r4);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        *(undefined2 *)(*param_1 + 0x2aa) = 1;
        uVar3 = *(uint *)(*param_1 + 0x2b0);
        if ((uVar3 & 0xd80000) != 0) {
          if (((uVar3 & 0xd80000) == 0x400000) && ((uVar3 & 0x1e00) == 0x400)) {
            return 0;
          }
          return -0x17;
        }
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  else {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0,*param_1);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(6,*param_1);
        *(short *)(*param_1 + 0x2aa) = (short)((uint)*(undefined4 *)(*param_1 + 0x2b0) >> 0x10);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xe000) == 0) {
          return 0;
        }
        return -8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  return -9;
}


// ===== FUN_2013e124 @ 2013e124 (304 bytes)

int FUN_2013e124(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_2013d0bc();
  if (iVar1 == 0) {
    if (*(short *)(*param_1 + 0x2c6) == 1) {
      iVar1 = FUN_2013d1c8(*param_1 + 0x201);
    }
    else {
      iVar1 = FUN_2013d158();
    }
    if ((iVar1 == 0) && (iVar1 = FUN_2013d238(param_1), iVar1 == 0)) {
      iVar1 = *param_1;
      if ((((*(char *)(iVar1 + 0x211) != '\0') || (*(char *)(iVar1 + 0x212) != '\0')) ||
          (*(char *)(iVar1 + 0x213) != '\0')) &&
         ((((*(char *)(iVar1 + 0x214) != '\0' || (*(char *)(iVar1 + 0x215) != '\0')) ||
           ((*(char *)(iVar1 + 0x216) != '\0' ||
            ((*(char *)(iVar1 + 0x217) != '\0' || (*(char *)(iVar1 + 0x218) != '\0')))))) ||
          ((*(char *)(iVar1 + 0x219) != '\0' ||
           (((((*(char *)(iVar1 + 0x21a) != '\0' || (*(char *)(iVar1 + 0x21b) != '\0')) ||
              (*(char *)(iVar1 + 0x21c) != '\0')) ||
             ((*(char *)(iVar1 + 0x21d) != '\0' || (*(char *)(iVar1 + 0x21e) != '\0')))) ||
            (*(char *)(iVar1 + 0x21f) != '\0')))))))) {
        return 0;
      }
      return -5;
    }
  }
  return iVar1;
}


// ===== FUN_2013e190 @ 2013e190 (84 bytes)

void FUN_2013e190(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_2013d434(param_1,param_4);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_4[1] + 0x50))(param_2,param_3,*param_4), iVar1 == 0)) {
    FUN_2013d434(0,param_4);
    return;
  }
  return;
}


// ===== FUN_2013e1e4 @ 2013e1e4 (76 bytes)

int FUN_2013e1e4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_2013d5f4();
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x222) & 4) == 0) {
      *(undefined2 *)(iVar1 + 0x2ac) = 0;
      return 0;
    }
    *(undefined2 *)(iVar1 + 0x2ac) = 2;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sd_read_sectors @ 2013e230 (132 bytes)

/* driver op +0x58 */

void sd_read_sectors(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
    param_1 = param_1 << 9;
  }
  iVar1 = FUN_2013d4fc(param_4);
  if ((iVar1 == 0) &&
     ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
      (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e2ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_4[1] + 0x58))(param_1,param_2,param_3,*param_4);
    return;
  }
  return;
}


// ===== sd_write_sectors @ 2013e2b4 (156 bytes)

/* driver op +0x60; -7 = write-protected */

int sd_write_sectors(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_4[1] + 0xc))();
  if (iVar1 == 0) {
    if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
      param_1 = param_1 << 9;
    }
    iVar1 = FUN_2013d4fc(param_4);
    if ((iVar1 == 0) &&
       ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
        (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(param_4[1] + 0x60))(param_1,param_2,param_3,*param_4);
      return iVar1;
    }
  }
  else {
    iVar1 = -7;
  }
  return iVar1;
}


// ===== FUN_2013e35c @ 2013e35c (112 bytes)

int FUN_2013e35c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      iVar1 = (**(code **)(*(int *)(param_5 + 4) + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== FUN_2013e3cc @ 2013e3cc (112 bytes)

int FUN_2013e3cc(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      iVar1 = (**(code **)(*(int *)(param_5 + 4) + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = sd_write_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== FUN_2013e43c @ 2013e43c (208 bytes)

int FUN_2013e43c(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = sd_read_sectors(0,*param_2 + 1,1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_201490f8(param_1,*param_2 + 1);
    if (iVar1 == 0) {
      iVar1 = sd_read_sectors(*(undefined4 *)(param_1 + 0x30),*param_2 + 1,1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = fat_mount(param_1,*param_2 + 1);
      if (-1 < iVar1) {
        if (*(char *)(param_1 + 0x10) == ' ') {
          iVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + (uint)*(ushort *)(param_1 + 0x3a),
                                  *param_2 + 1,1,param_2);
          if (iVar1 != 0) {
            return iVar1;
          }
          FUN_20148f40(param_1,*param_2 + 1);
        }
        return 0;
      }
    }
    iVar1 = -4;
  }
  return iVar1;
}


// ===== FUN_2013e71c @ 2013e71c (700 bytes)

int FUN_2013e71c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  switch(param_2) {
  default:
    return -3;
  case 1:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = FUN_2013e35c(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 2:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = FUN_2013e3cc(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 5:
    iVar2 = (**(code **)(param_6[1] + 100))();
    if ((iVar2 == 0) && (iVar2 = FUN_2013f9fc(param_1,*(undefined1 *)*param_6), iVar2 == 0)) {
      *(int **)(param_1 + 0x24) = param_6;
      return 0;
    }
    return -8;
  case 7:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = (**(code **)(param_6[1] + 0x24))();
      if (iVar2 == 0) {
        iVar3 = 0;
        do {
          iVar2 = (**(code **)(param_6[1] + 0x20))(2);
          if ((((((iVar2 == 0) && (iVar2 = sd_card_identify(param_6), iVar2 == 0)) &&
                (iVar2 = FUN_2013e124(param_6), iVar2 == 0)) &&
               ((iVar2 = FUN_2013e190(*(undefined2 *)(*param_6 + 0x2aa),0x200,1,param_6), iVar2 == 0
                && (iVar2 = FUN_2013d434(*(undefined2 *)(*param_6 + 0x2aa),param_6), iVar2 == 0))))
              && ((*(short *)(*param_6 + 0x2c6) == 1 ||
                  (((iVar2 = FUN_2013e1e4(param_6), iVar2 == 0 &&
                    (iVar2 = FUN_2013d744(param_6), iVar2 == 0)) &&
                   ((iVar2 = FUN_2013df88(param_6), iVar2 == 0 &&
                    (iVar2 = FUN_2013d818(param_6), iVar2 == 0)))))))) &&
             ((iVar2 = FUN_2013c928(1,param_6), iVar2 == 0 &&
              (((*(short *)(*param_6 + 0x2c2) != 2 && *(short *)(*param_6 + 0x2c2) != 3 ||
                (iVar2 = (**(code **)(param_6[1] + 0x40))(), iVar2 == 0)) &&
               (iVar2 = FUN_2013e43c(param_1,param_6), iVar2 == 0)))))) {
            thunk_FUN_20150c3c();
            *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
            iVar2 = (**(code **)(param_6[1] + 0xc))();
            if (iVar2 == 0) {
              bVar1 = *(byte *)(param_1 + 0x68) & 0xdf;
            }
            else {
              bVar1 = *(byte *)(param_1 + 0x68) | 0x20;
            }
            *(byte *)(param_1 + 0x68) = bVar1;
            thunk_FUN_20152d28();
            return 0;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
      }
      return iVar2;
    }
    break;
  case 8:
    (**(code **)(param_6[1] + 0x28))();
    thunk_FUN_20150c3c();
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    thunk_FUN_20152d28();
    return 0;
  case 9:
                    /* WARNING: Could not recover jumptable at 0x2013e358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (**(code **)(param_6[1] + 8))();
    return iVar2;
  }
  return -6;
}


// ===== FUN_2013e7e8 @ 2013e7e8 (24 bytes)

void FUN_2013e7e8(int param_1)

{
  if (*(int *)(param_1 + 0x2f4) != 0) {
    *(int *)(param_1 + 0x2f4) = *(int *)(param_1 + 0x2f4) + -1;
  }
  return;
}


// ===== FUN_2013e800 @ 2013e800 (12 bytes)

void FUN_2013e800(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x2f4) = param_1;
  *(undefined4 *)(param_2 + 0x2f8) = param_1;
  return;
}


// ===== FUN_2013e8d0 @ 2013e8d0 (420 bytes)

int FUN_2013e8d0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  iVar7 = 0;
  FUN_2014d148(iVar2 + 1,0,0x200,0);
  cVar1 = *(char *)(iVar2 + 0x2dc);
  if (cVar1 == '\f') {
    FUN_2014d128(*param_1 + 1,&DAT_20420254,3);
  }
  else if (cVar1 == '\x10') {
    FUN_2014d128(*param_1 + 1,&DAT_20420257,4);
  }
  else {
    if (cVar1 != ' ') {
      return -2;
    }
    FUN_2014d128(*param_1 + 1,&DAT_204202f3,0xc);
  }
  iVar6 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4);
  iVar3 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
  if (iVar3 == 0) {
    if (*(char *)(iVar2 + 0x2dc) != '@') {
      iVar7 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0);
      iVar4 = sd_write_sectors(iVar7,*param_1 + 1,1,param_1);
      iVar3 = 0;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    FUN_2013e7e8(*param_1);
    FUN_2014d148(*param_1 + 1,0,0x200);
    iVar4 = *(int *)(iVar2 + 0x2e0);
    if ((*(char *)(iVar2 + 0x2dc) != '@') && (uVar5 = 0, iVar4 != 1)) {
      do {
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 1;
        iVar2 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = sd_write_sectors(iVar7,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_2013e7e8(*param_1);
        uVar5 = uVar5 + 1;
        iVar3 = 0;
      } while (uVar5 < iVar4 - 1U);
    }
  }
  return iVar3;
}


// ===== FUN_2013ea74 @ 2013ea74 (332 bytes)

void FUN_2013ea74(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  FUN_2014d148(iVar1 + 1,0,0x200);
  FUN_2014d128(*param_1 + 1,DAT_20808b4c,4);
  FUN_2014d128(*param_1 + 0x1e5,DAT_20808b50,4);
  FUN_2014d918(*param_1 + 0x1e9,0xffffffff);
  FUN_2014d918(*param_1 + 0x1ed,0xffffffff);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar2 = *(int *)(iVar1 + 0x2d0);
  iVar3 = sd_write_sectors(iVar2 + 1,*param_1 + 1,1,param_1);
  if ((iVar3 == 0) && (iVar2 = sd_write_sectors(iVar2 + 7,*param_1 + 1,1,param_1), iVar2 == 0)) {
    FUN_2014d148(*param_1 + 1,0,0x200);
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    iVar1 = *(int *)(iVar1 + 0x2d0);
    iVar2 = sd_write_sectors(iVar1 + 2,*param_1 + 1,1,param_1);
    if (iVar2 == 0) {
      sd_write_sectors(iVar1 + 8,*param_1 + 1,1,param_1);
      return;
    }
  }
  return;
}

