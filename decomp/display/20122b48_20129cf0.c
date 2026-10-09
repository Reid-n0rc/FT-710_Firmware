// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20122b48 @ 20122b48 (440 bytes)

void FUN_20122b48(undefined4 param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  short local_40 [4];
  int local_38;
  uint local_34;
  undefined *local_30 [3];
  
  cVar2 = DAT_208f4606;
  local_30[1] = (undefined *)0x0;
  local_30[2] = (undefined *)0x0;
  local_30[0] = (undefined *)0x0;
  local_38 = 0;
  local_34 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  if (DAT_208f4619 != '\0') {
    local_30[1] = (undefined *)&DAT_2016d418;
    local_40[0] = 0;
    local_40[1] = 0x7c;
    local_38 = (uint)(ushort)((short)(((uint)DAT_208f461a * 10) / 200) + 0x203) << 0x10;
  }
  if (DAT_208f461d != '\0') {
    sVar1 = (short)(((uint)DAT_208f461e * 10) / 200) + 0x1fe;
    if ((DAT_208f0b43 & 0x80) == 0) {
      local_40[0] = 0x7c;
      local_38 = CONCAT22(local_38._2_2_,sVar1);
      local_30[0] = &DAT_2016d408;
    }
    else {
      local_40[0] = 0x7c;
      local_38 = CONCAT22(local_38._2_2_,sVar1);
      local_30[0] = (undefined *)&DAT_2016d3f8;
    }
  }
  if (DAT_208f4621 != '\0') {
    local_30[2] = &DAT_2016d3e8;
    local_40[2] = 0x7c;
    local_40[3] = 0;
    local_34 = (uint)(ushort)((short)(((uint)DAT_208f4622 * 10) / 200) + 0x208);
  }
  if (((DAT_208f4606 != '\x04' && DAT_208f4606 != '\x05') &&
      (DAT_208f4606 != '\x06' && DAT_208f4606 != '\a')) &&
     (DAT_208f4606 != '\n' && DAT_208f4606 != '\v')) {
    uVar5 = 0;
    do {
      puVar4 = (ushort *)local_30[uVar5];
      if (((puVar4 != (ushort *)0x0) &&
          (iVar3 = (int)*(short *)((int)&local_38 + uVar5 * 2), 0x1bd < iVar3)) &&
         ((int)((uint)*puVar4 + iVar3) < 0x31e)) {
        FUN_201366e0(param_1,(int)local_40[uVar5],iVar3,puVar4,0x1bd,0x31d);
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 3);
    FUN_201227d8(param_1,cVar2);
  }
  return;
}


// ===== FUN_20122d00 @ 20122d00 (772 bytes)

void FUN_20122d00(short *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = 0;
  switch(param_2) {
  case 0:
  case 1:
    uVar3 = 0;
    do {
      if ((ushort)(&DAT_2016d488)[uVar3] < param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x17);
    if (0x16 < uVar6) {
      uVar6 = 0x16;
    }
    iVar1 = uVar6 * 6;
    sVar5 = *(short *)(&UNK_2016d4b6 + iVar1);
    sVar4 = *(short *)(&UNK_2016d4b8 + iVar1);
    sVar2 = *(short *)(&UNK_2016d4ba + iVar1);
    break;
  case 2:
  case 3:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    if ((ushort)(&DAT_2016d540)[uVar6 * 3] < param_4) {
      uVar3 = (uint)((ulonglong)(param_4 * 10) * 0x51eb851f >> 0x20);
    }
    else {
      uVar3 = (uint)((ulonglong)(((ushort)(&DAT_2016d540)[uVar6 * 3] + param_4 >> 1) * 10) *
                     0x51eb851f >> 0x20);
    }
    sVar4 = (short)(uVar3 >> 6) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  default:
    sVar4 = 0x99;
    sVar5 = 0x91;
    sVar2 = 0xa0;
    break;
  case 8:
  case 9:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    uVar3 = FUN_20135470(&DAT_208f0b9d);
    sVar4 = (short)(((uVar3 & 0xffff) * 10) / 200) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  case 0xc:
  case 0xd:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    iVar1 = ((int)*(short *)(&DAT_2016d288 + (uint)(DAT_208f0b92 >> 7) * 2) +
            (int)*(short *)(&DAT_2016d29e + (DAT_208f0b92 & 3) * 2) / 2) * 10;
    sVar4 = (((short)(iVar1 / 200) + (short)(iVar1 >> 0x1f)) -
            (short)((longlong)iVar1 * 0x51eb851f >> 0x3f)) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  case 0xe:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    iVar1 = *(short *)(&DAT_2016d298 + ((DAT_208f0b93 & 0x3f) >> 4) * 2) * 10;
    sVar4 = (((short)(iVar1 / 200) +
             (*(short *)(&DAT_2016d298 + ((DAT_208f0b93 & 0x3f) >> 4) * 2) >> 0xf)) -
            (short)((longlong)iVar1 * 0x51eb851f >> 0x3f)) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
  }
  *param_1 = sVar4;
  param_1[1] = sVar5;
  param_1[2] = sVar2;
  return;
}


// ===== FUN_20123088 @ 20123088 (784 bytes)

void FUN_20123088(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  undefined1 uVar8;
  short sVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  undefined4 local_28;
  
  uVar4 = (ushort)DAT_208f0b4c;
  iVar13 = (uint)DAT_208f0b4d << 0x1d;
  uVar14 = DAT_208f0b4d & 3;
  uVar11 = (ushort)DAT_208f0b48 + (ushort)DAT_208f0b47 * 0x100;
  if (uVar11 < 0x32) {
    uVar11 = 0x32;
  }
  if (16000 < uVar11) {
    uVar11 = 16000;
  }
  local_28 = param_4;
  iVar7 = FUN_20135470(&DAT_208f0b49);
  if (iVar7 < -0x4b0) {
    iVar7 = -0x4b0;
  }
  uVar12 = (ushort)DAT_208f0b57;
  if (0x4b0 < iVar7) {
    iVar7 = 0x4b0;
  }
  if (0xf < uVar12) {
    uVar12 = 0xf;
  }
  uVar5 = FUN_20135470(&DAT_208f0b45);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  if (0x140 < uVar5) {
    uVar5 = 0x140;
  }
  local_28 = CONCAT31(CONCAT21(local_28._2_2_,DAT_208f0b44),DAT_208f0b43) & 0xffffff7f;
  uVar6 = FUN_20135470(&local_28);
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  if (0x140 < uVar6) {
    uVar6 = 0x140;
  }
  iVar10 = (int)DAT_208f0b4b;
  param_1[1] = (byte)((uint)iVar13 >> 0x1f);
  if (iVar10 < -0x19) {
    iVar10 = -0x19;
  }
  if (0x19 < iVar10) {
    iVar10 = 0x19;
  }
  sVar9 = (short)iVar10 * 10;
  if ((uVar14 == 3) && (iVar13 < 0)) {
    *param_1 = 4;
  }
  else {
    *param_1 = (char)uVar14;
  }
  *(ushort *)(param_1 + 6) = uVar12;
  *(short *)(param_1 + 10) = (short)iVar7;
  param_1[8] = (byte)(((uint)DAT_208f0b4d << 0x1a) >> 0x1f);
  *(ushort *)(param_1 + 0xe) = uVar11;
  param_1[0x10] = (byte)(((uint)DAT_208f0b4d << 0x1b) >> 0x1f);
  *(ushort *)(param_1 + 0x1a) = uVar5 * 10;
  bVar1 = (byte)(((uint)DAT_208f0b37 << 0x1b) >> 0x1f);
  param_1[0x18] = bVar1;
  *(ushort *)(param_1 + 0x1e) = uVar6 * 10;
  bVar2 = (byte)(((uint)DAT_208f0b37 << 0x1a) >> 0x1f);
  param_1[0x1c] = bVar2;
  *(ushort *)(param_1 + 0x22) = sVar9 + uVar4 * 10;
  *(short *)(param_1 + 0x26) = sVar9;
  bVar3 = (byte)(((uint)DAT_208f0b37 << 0x19) >> 0x1f);
  param_1[0x20] = bVar3;
  *(ushort *)(param_1 + 0x28) = uVar4 * 10;
  param_1[0x19] = bVar1;
  param_1[0x1d] = bVar2;
  param_1[0x21] = bVar3;
  switch(uVar12) {
  case 0:
  case 1:
    param_1[2] = 0;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) == sVar9) break;
LAB_201232ac:
    uVar8 = 1;
    goto LAB_201232b0;
  case 2:
  case 3:
    param_1[2] = 1;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 10:
  case 0xb:
    param_1[2] = 3;
    *(undefined2 *)(param_1 + 0x16) = 0;
    param_1[8] = 0;
    param_1[0x10] = 0;
    *(undefined2 *)(param_1 + 0x12) = 0;
    goto LAB_201233c4;
  case 8:
  case 9:
    param_1[2] = 4;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  case 0xc:
  case 0xd:
    param_1[2] = 5;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  case 0xe:
    param_1[2] = 6;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  default:
    param_1[8] = 1;
    param_1[0x10] = 1;
    goto LAB_201233c4;
  }
  uVar8 = 0;
LAB_201232b0:
  param_1[0x10] = uVar8;
LAB_201233c4:
  param_1[0x2a] = (byte)(((uint)DAT_208f0b4d << 0x19) >> 0x1f);
  return;
}


// ===== FUN_201233d4 @ 201233d4 (472 bytes)

void FUN_201233d4(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (DAT_20800480 == '\0') {
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  iVar3 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = (uint)DAT_208f0b2f;
  uVar5 = (uint)DAT_208f0b34;
  FUN_20123088(&DAT_208f4600);
  uVar1 = DAT_208f4606;
  uVar7 = (uint)DAT_208f4628;
  iVar9 = (int)DAT_208f460a;
  uVar6 = (uint)DAT_208f4616;
  FUN_20122d00(&DAT_208007dc,DAT_208f4606,DAT_208f460e,uVar7);
  FUN_20122d00(&DAT_208007e2,uVar1,uVar6,uVar7);
  if (-1 < (int)(uVar4 << 0x1a)) {
    if (iVar8 != 0) {
      iVar3 = iVar8 + -0x2a940;
    }
    fb_fill_rect(iVar3,0,0x6d,0x1bb,0x164,0x45);
    gui_draw_runs(iVar3,0x6d,0x1bb,&DAT_2016d380);
    if ((DAT_2080048a == '\0') && (FUN_20122b48(iVar3), DAT_2080048a == '\0')) {
      FUN_20122638(iVar3,uVar1,iVar9,1);
    }
    else if ((DAT_208f0b34 & 0x80) != 0) {
      iVar9 = ((uVar5 & 0x7f) >> 4) * 4;
      DAT_208007de = *(undefined2 *)(&DAT_2016d5be + iVar9);
      DAT_208007e0 = *(undefined2 *)(&DAT_2016d5c0 + iVar9);
      FUN_20122638(iVar3,uVar1,0);
    }
    if ((DAT_208f0b33 & 8) != 0) {
      FUN_20121af0(iVar3,0x81,0x209,200);
    }
    FUN_201224c8(iVar3,uVar1);
    if (iVar8 != 0) {
      iVar2 = iVar2 + 0x2acb6;
      iVar8 = iVar8 + 0x376;
      iVar3 = 0;
      do {
        memcpy(iVar2,iVar8,0x2c8);
        iVar3 = iVar3 + 1;
        iVar8 = iVar8 + 0x640;
        iVar2 = iVar2 + 0x640;
      } while (iVar3 < 0x45);
    }
  }
  return;
}


// ===== FUN_201235ac @ 201235ac (604 bytes)

void FUN_201235ac(undefined4 param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  bool bVar5;
  
  cVar3 = DAT_208f4601;
  cVar2 = DAT_208f4600;
  bVar5 = DAT_208f4608 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (DAT_208f4600 == '\0') {
    fb_fill_rect(param_1,uVar4,0x116,0x1bb,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x1bb,(&DAT_208008c8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x1bb,(&DAT_208008d0)[bVar5]);
  }
  bVar5 = DAT_208f4610 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x01') {
    fb_fill_rect(param_1,uVar4,0x116,0x214,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x214,(&DAT_208008d8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x214,(&DAT_208008e0)[bVar5]);
  }
  bVar5 = DAT_208f4618 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x02') {
    fb_fill_rect(param_1,uVar4,0x116,0x26d,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x26d,(&DAT_208008e8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x26d,(&DAT_208008f0)[bVar5]);
  }
  if (cVar3 != '\0') {
    if (DAT_208f4620 == '\0') {
      uVar4 = 0x8410;
    }
    else {
      uVar4 = 0xfc00;
    }
    uVar1 = (uint)(DAT_208f4620 != '\0');
    if (cVar2 == '\x04') {
      fb_fill_rect(param_1,uVar4,0x116,0x2c6,0x58,0x31);
      gui_draw_runs(param_1,0x127,0x2c6,*(undefined4 *)(uVar1 * 4 + 0x20800908));
      return;
    }
    gui_draw_runs(param_1,0x127,0x2c6,(&DAT_20800910)[uVar1]);
    return;
  }
  bVar5 = DAT_208f461c != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x03') {
    fb_fill_rect(param_1,uVar4,0x116,0x2c6,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x2c6,(&DAT_208008f8)[bVar5]);
    return;
  }
  gui_draw_runs(param_1,0x127,0x2c6,(&DAT_20800900)[bVar5]);
  return;
}


// ===== FUN_20123808 @ 20123808 (68 bytes)

void FUN_20123808(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_208f4600 == '\x02') {
    uVar1 = (uint)DAT_208f4618;
  }
  else if (DAT_208f4600 == '\x03') {
    uVar1 = (uint)DAT_208f461c;
  }
  else {
    if (DAT_208f4600 != '\x04') {
      return;
    }
    uVar1 = (uint)DAT_208f4620;
  }
  gui_draw_runs(param_1,0xd0,0x2f7,*(undefined4 *)(&DAT_208007f0 + uVar1 * 4));
  return;
}


// ===== FUN_2012384c @ 2012384c (884 bytes)

void FUN_2012384c(undefined4 param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40 [5];
  undefined4 local_2c;
  int iStack_28;
  
  uVar6 = 0;
  local_40[0] = &DAT_201a05f4;
  local_40[1] = &DAT_201a04d0;
  local_40[2] = &DAT_201a03b8;
  local_40[3] = &DAT_201a04d0;
  local_40[4] = &DAT_201a05f4;
  local_2c = param_1;
  iStack_28 = param_2;
  FUN_20135aa4(param_1,0xb4,0x1bd,0x160,1,0xffff);
  uVar3 = 0xfffffff2;
  do {
    uVar2 = uVar3 * 0x19 + param_2 + 0x1ba & 0xffff;
    if (uVar2 - 0x1bd < 0x15f) {
      if ((uVar3 & 1) == 0) {
        FUN_20135ad8(local_2c,0xb6,uVar2,6,2,0xffff);
      }
      else {
        FUN_20135ad8(local_2c,0xb6,uVar2,4,2,0xffff);
      }
    }
    uVar3 = (uint)(short)((short)uVar3 + 1);
  } while ((int)uVar3 < 0xf);
  iVar4 = 0;
  do {
    uVar3 = (uint)(ushort)(&DAT_2016d6dc)[iVar4] + param_2 + 0x1bb & 0xffff;
    if (uVar3 - 0x1bd < 0x161) {
      gui_draw_runs(local_2c,0xbe,uVar3,local_40[iVar4]);
    }
    iVar4 = (int)(short)((short)iVar4 + 1);
  } while (iVar4 < 5);
  local_48 = 0;
  local_44 = 0;
  if (DAT_208f4600 == '\0') {
    uVar6 = *(undefined4 *)(&DAT_208008a0 + (uint)DAT_208f4608 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4608 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,&DAT_20123bfc,(int)DAT_208f460a);
      sVar1 = FUN_20155122(&local_48);
      FUN_20135dd4(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x01') {
    uVar6 = *(undefined4 *)(&DAT_208008a8 + (uint)DAT_208f4610 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4610 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,&DAT_20123bfc,(int)DAT_208f4612);
      sVar1 = FUN_20155122(&local_48);
      FUN_20135dd4(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x02') {
    uVar6 = *(undefined4 *)(&DAT_208008b0 + (uint)DAT_208f4618 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4618 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,&DAT_20123bfc,(int)DAT_208f461a);
      sVar1 = FUN_20155122(&local_48);
      FUN_20135dd4(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x03') {
    uVar6 = *(undefined4 *)(&DAT_208008b8 + (uint)DAT_208f461c * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f461c == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,&DAT_20123bfc,(int)DAT_208f461e);
      sVar1 = FUN_20155122(&local_48);
      FUN_20135dd4(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x04') {
    uVar6 = *(undefined4 *)(&DAT_208008c0 + (uint)DAT_208f4620 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4620 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,&DAT_20123bfc,(int)DAT_208f4626);
      sVar1 = FUN_20155122(&local_48);
      FUN_20135dd4(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  gui_draw_runs(local_2c,0xe4,0x1c1,uVar6);
  return;
}


// ===== FUN_20123c04 @ 20123c04 (704 bytes)

void FUN_20123c04(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (DAT_20800480 == '\0') {
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  iVar4 = fb_get_layer_addr(DAT_208085b8);
  iVar5 = fb_get_layer_addr(DAT_208085b8);
  iVar6 = fb_get_layer_addr(DAT_208085bc);
  FUN_20123088(&DAT_208f4600);
  uVar3 = DAT_208f4628;
  uVar2 = DAT_208f4616;
  uVar1 = DAT_208f4606;
  iVar10 = (int)DAT_208f460a;
  FUN_20122d00(&DAT_208007dc,DAT_208f4606,DAT_208f460e,DAT_208f4628);
  FUN_20122d00(&DAT_208007e2,uVar1,uVar2,uVar3);
  if (iVar8 != 0) {
    iVar5 = iVar8 + -0x2a940;
  }
  if ((((DAT_208f0b2a == '0' || DAT_208f0b2a == 'b') || DAT_208f0b2a == 'P') ||
      (iVar9 = iVar5, DAT_208f4630 != '\0')) && (iVar9 = iVar6, DAT_208f0b2a != 'P')) {
    fb_fill_rect(iVar5,0x821,0x6d,0x1bb,0x164,0x45);
  }
  fb_fill_rect(iVar9,0,0x6d,0x1bb,0x164,0x45);
  gui_draw_runs(iVar9,0x6d,0x1bb,&DAT_2016d68c);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar9,uVar7 + 0x70,0x1bb,&DAT_2016d69c);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 0x42);
  fb_fill_rect(iVar6,0x821,0xb2,0x1bb,0x164,100);
  fb_fill_rect(iVar6,0x821,0x116,0x1bb,0x164,0x32);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar6,uVar7 + 0xb2,0x1bb,&DAT_2016d69c);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 99);
  gui_draw_runs(iVar6,uVar7 + 0xb2,0x1bb,&DAT_2016d6ac);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar6,uVar7 + 0x116,0x1bb,&DAT_2016d6bc);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 0x2f);
  gui_draw_runs(iVar6,uVar7 + 0x116,0x1bb,&DAT_2016d6cc);
  FUN_20122b48(iVar9);
  FUN_20122638(iVar9,uVar1,iVar10,1);
  if ((DAT_208f0b33 & 8) != 0) {
    FUN_20121af0(iVar9,0x81,0x209,200);
  }
  FUN_201224c8(iVar9,uVar1);
  FUN_2012384c(iVar6,DAT_208007e2);
  FUN_20123808(iVar6);
  FUN_201235ac(iVar6);
  if (iVar8 != 0) {
    iVar5 = 0;
    iVar4 = iVar4 + 0x2acb6;
    iVar8 = iVar8 + 0x376;
    do {
      memcpy(iVar4,iVar8,0x2c8);
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0x640;
      iVar4 = iVar4 + 0x640;
    } while (iVar5 < 0x45);
  }
  return;
}


// ===== FUN_201244d8 @ 201244d8 (1544 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_201244d8(void)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  char cVar5;
  undefined2 uVar6;
  short sVar7;
  undefined2 uVar8;
  short sVar9;
  byte bVar10;
  short sVar11;
  short sVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint unaff_r7;
  short sVar23;
  uint unaff_r9;
  bool bVar24;
  uint local_5c;
  undefined2 uVar4;
  
  cVar5 = DAT_208004d1;
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar24 = false;
  }
  else {
    if ((DAT_20800482 != '\x01') || (1 < DAT_208004d0)) {
      return;
    }
    bVar24 = true;
  }
  uVar13 = fb_get_layer_addr(DAT_208085b8);
  bVar10 = DAT_208f0b33;
  sVar9 = DAT_2080082e;
  uVar8 = DAT_2080082c;
  sVar7 = DAT_2080082a;
  uVar6 = DAT_20800828;
  uVar18 = (uint)DAT_208f0b33;
  iVar19 = (uint)DAT_208f0b2f << 0x1a;
  if (iVar19 < 0) {
    sVar23 = 0x80;
  }
  else {
    sVar23 = 0xc9;
  }
  if (bVar24) {
    if (bVar24) {
      unaff_r9 = _DAT_20800718;
      uVar3 = DAT_20800832;
      uVar4 = DAT_20800830;
      if (iVar19 < 0) {
        unaff_r9 = _DAT_2080071c;
        uVar3 = DAT_20800836;
        uVar4 = DAT_20800834;
      }
      uVar20 = CONCAT22(uVar3,uVar4);
      if (DAT_208004d0 == 1) goto joined_r0x20123fbc;
      goto joined_r0x20123fcc;
    }
  }
  else {
    if (iVar19 < 0) {
      uVar20 = *(uint *)(&DAT_20802d78 + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800714;
    }
    else {
      uVar20 = *(uint *)(&DAT_20802d6c + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800710;
    }
    if (DAT_208004d0 == 1) {
joined_r0x20123fbc:
      unaff_r7 = uVar20;
      if (-1 < (int)(uVar18 << 0x19)) goto joined_r0x20123fcc;
    }
    else {
joined_r0x20123fcc:
      unaff_r7 = unaff_r9;
      unaff_r9 = unaff_r7;
      if (DAT_208004d0 != 1) goto LAB_20124054;
    }
    if ((int)(uVar18 << 0x1a) < 0) {
      unaff_r9 = uVar20;
    }
  }
LAB_20124054:
  if (iVar19 < 0) {
    uVar14 = 0x80;
  }
  else {
    uVar14 = 0xc9;
  }
  uVar20 = (uint)(short)(DAT_20802d86 + sVar23);
  sVar1 = DAT_20802d8e + sVar23;
  iVar19 = FUN_20135498(&DAT_208f0b9f);
  iVar15 = FUN_20135498(&DAT_208f0ba3);
  uVar21 = DAT_208f0b3b & 0x1f;
  if (9 < uVar21) {
    uVar21 = 9;
  }
  if (cVar5 == '\0') {
    iVar22 = FUN_20135498(&DAT_208f0ba7);
    iVar16 = iVar22 - *(int *)(&UNK_2016d6e8 + uVar21 * 4) / 2;
    iVar22 = iVar22 + *(int *)(&UNK_2016d6e8 + uVar21 * 4) / 2;
  }
  else {
    iVar16 = FUN_20135498(&DAT_208f0bab);
    iVar22 = *(int *)(&UNK_2016d6e8 + uVar21 * 4) + iVar16;
  }
  sVar11 = FUN_20156260((iVar19 - iVar16) * 0x317,iVar22 - iVar16);
  local_5c = (uint)(short)(sVar11 + 4);
  bVar24 = SBORROW4(local_5c,10);
  iVar2 = local_5c - 10;
  if (9 < (int)local_5c) {
    bVar24 = SBORROW4(iVar19,iVar16);
    iVar2 = iVar19 - iVar16;
  }
  if (iVar2 < 0 == bVar24) {
    if (0x314 < (int)local_5c) {
      local_5c = 0x314;
    }
  }
  else {
    local_5c = 10;
  }
  sVar11 = FUN_20156260((iVar15 - iVar16) * 0x317,iVar22 - iVar16);
  uVar21 = (uint)(short)(sVar11 + 4);
  bVar24 = SBORROW4(uVar21,10);
  iVar2 = uVar21 - 10;
  if (9 < (int)uVar21) {
    bVar24 = SBORROW4(iVar15,iVar16);
    iVar2 = iVar15 - iVar16;
  }
  if (iVar2 < 0 == bVar24) {
    if (0x314 < (int)uVar21) {
      uVar21 = 0x314;
    }
  }
  else {
    uVar21 = 10;
  }
  DAT_208007d4 = 0;
  DAT_208007d6 = 0;
  sVar12 = sVar23 + 0xd;
  uVar17 = (uint)(short)((short)local_5c + -6);
  sVar11 = (short)uVar21 + -6;
  if (-1 < (char)bVar10) {
    DAT_208007d4 = 0;
    DAT_208007d6 = 0;
    return;
  }
  if (cVar5 == '\0') {
LAB_201241e8:
    if (cVar5 != '\x01') goto LAB_20124394;
LAB_201242a0:
    bVar24 = SBORROW4(iVar16,iVar15);
    iVar19 = iVar16 - iVar15;
    iVar2 = iVar16;
    if (iVar16 <= iVar15) {
      bVar24 = SBORROW4(iVar15,iVar22);
      iVar19 = iVar15 - iVar22;
      iVar2 = iVar22;
    }
    if (iVar2 == iVar15 || iVar19 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar12,sVar11,&DAT_2016e410);
      FUN_20135ad8(uVar13,sVar12,uVar21 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                   0xf800);
    }
    if (iVar16 <= iVar15) {
      if (iVar15 <= iVar22) goto LAB_2012442c;
      goto LAB_20124410;
    }
  }
  else {
    if (cVar5 == '\x01') {
      if (iVar16 < iVar19) {
        if (iVar22 <= iVar19) {
          gui_draw_runs(uVar13,sVar9 + sVar23,uVar8,&DAT_2016e3f0);
        }
      }
      else {
        gui_draw_runs(uVar13,sVar7 + sVar23,uVar6,&DAT_2016e3e0);
      }
      gui_draw_runs(uVar13,sVar23,uVar17 & 0xffff,&DAT_2016e400);
      FUN_20135ad8(uVar13,sVar23,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
      goto LAB_201242a0;
    }
    if (cVar5 != '\x02') goto LAB_201241e8;
    if (iVar16 < iVar19) {
      if (iVar22 <= iVar19) {
        gui_draw_runs(uVar13,uVar20 & 0xffff,DAT_20802d88,&DAT_2016e3b0);
      }
    }
    else {
      gui_draw_runs(uVar13,uVar20 & 0xffff,DAT_20802d84,&DAT_2016e3a0);
    }
    bVar24 = SBORROW4(iVar16,iVar19);
    iVar2 = iVar16 - iVar19;
    if (iVar16 < iVar19) {
      bVar24 = SBORROW4(iVar19,iVar22);
      iVar2 = iVar19 - iVar22;
    }
    if (iVar2 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar23,uVar17 & 0xffff,&DAT_2016e400);
      FUN_20135ad8(uVar13,sVar23,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
    }
LAB_20124394:
    bVar24 = SBORROW4(iVar16,iVar15);
    iVar19 = iVar16 - iVar15;
    if (iVar16 < iVar15) {
      bVar24 = SBORROW4(iVar15,iVar22);
      iVar19 = iVar15 - iVar22;
    }
    if (iVar19 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar12,sVar11,&DAT_2016e410);
      FUN_20135ad8(uVar13,sVar12,uVar21 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                   0xf800);
    }
    if (iVar16 < iVar15) {
      if (iVar15 < iVar22) goto LAB_2012442c;
LAB_20124410:
      gui_draw_runs(uVar13,sVar1,DAT_20802d90,&DAT_2016e3d0);
      goto LAB_2012442c;
    }
  }
  gui_draw_runs(uVar13,sVar1,DAT_20802d8c,&DAT_2016e3c0);
LAB_2012442c:
  if ((((uVar18 & 0x1f) >> 4 != 0) && (cVar5 == '\0')) && (1 < DAT_208f0b57)) {
    FUN_20135ad8(uVar13,uVar14,399,unaff_r7 >> 0x10,1,0xffff);
  }
  return;
}


// ===== FUN_20124528 @ 20124528 (484 bytes)

void FUN_20124528(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  iVar4 = -((int)((uint)DAT_208f0b2f << 0x1a) >> 0x1f);
  DAT_20800498 = DAT_208f0b3c >> 4 == 5;
  DAT_20800499 = (bool)DAT_20800498 && DAT_208004d0 == 0;
  if ((DAT_20800489 != '\0') &&
     (cVar1 = DAT_20800489 + -1, bVar5 = DAT_20800489 == '\x01', DAT_20800489 = cVar1, bVar5)) {
    FUN_20134304(0);
  }
  if (DAT_20800482 == '\0') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (iVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        FUN_201335d8(DAT_208007c8,iVar4,&DAT_208007d4,iVar2 + iVar3 * 0x640);
      }
      thunk_FUN_2015d49c(iVar4,&DAT_208007d4);
    }
    else if (DAT_208004d0 == 1) {
      if (DAT_208004d2 == '\x02') {
        thunk_FUN_2015d958(iVar4,&DAT_208007d4);
      }
      else if (DAT_208004d2 == '\0') {
        thunk_FUN_2015d874(iVar4,&DAT_208007d4);
      }
      else {
        thunk_FUN_2015d3b8();
      }
    }
  }
  else if (DAT_20800482 == '\x01') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (iVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        FUN_201335f8(DAT_208007c8,iVar4,&DAT_208007d4,iVar2 + iVar3 * 0x640);
      }
      thunk_FUN_2015d5e8(iVar4,&DAT_208007d4);
    }
    else {
      if (DAT_208004d0 != 1) goto LAB_201246dc;
      thunk_FUN_2015d508(iVar4,&DAT_208007d4);
    }
    if (DAT_208004d0 < 2) {
      thunk_FUN_2015d334(iVar4);
    }
  }
LAB_201246dc:
  DAT_208007c8 = (DAT_208007c8 + 1) % 0x308f4;
  return;
}


// ===== FUN_2012470c @ 2012470c (1132 bytes)

uint FUN_2012470c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if ((1 < DAT_20800482) || (DAT_208004d0 != '\x03')) {
    return (DAT_208f0b2f & 0x3f) >> 5;
  }
  local_28 = fb_get_layer_addr(DAT_208085b8);
  uVar6 = 0;
  fb_copy_rect(local_28,DAT_208084ea,DAT_208084e8,DAT_208084f0,DAT_208084f2);
  fb_copy_rect(local_28,DAT_208084f6,DAT_208084f4,DAT_208084f8,DAT_208084fa);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f48c8,DAT_208f489a);
  FUN_20135dd4(local_28,&local_68,DAT_2080850a * (ushort)DAT_208f489c + DAT_208084ee,DAT_208084ec,
               DAT_20808508,&DAT_20800b1c);
  uVar1 = (uint)DAT_208f489b;
  uVar3 = (uint)DAT_208f489d;
  uVar7 = (uint)DAT_208f4bab;
  if (uVar1 < DAT_208f4bab) {
    uVar7 = uVar1;
  }
  if (uVar3 < uVar1) {
    iVar4 = uVar1 - uVar7;
    if (iVar4 < (int)uVar3) {
      uVar7 = uVar1 - uVar3 & 0xff;
    }
    uVar6 = uVar1 - iVar4 & 0xff;
    if (uVar7 < uVar6) {
      uVar1 = uVar6 - uVar7 & 0xff;
    }
    else {
      uVar1 = 0;
    }
    uVar3 = uVar3 - uVar1 & 0xff;
    uVar6 = uVar7;
  }
  else {
    uVar3 = uVar1 - uVar7 & 0xff;
    uVar1 = uVar1 - uVar3 & 0xff;
  }
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f489f + uVar6,uVar1);
  FUN_20135dd4(local_28,&local_68,DAT_208084fe,DAT_208084fc,DAT_20808508,&DAT_20800fb4);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f489f + uVar6 + uVar1,uVar3);
  FUN_20135dd4(local_28,&local_68,DAT_208084fe,DAT_20808508 * uVar1 + (uint)DAT_208084fc & 0xffff,
               (uint)DAT_20808508,&DAT_20800b1c);
  uVar7 = 0x10 - DAT_208f489c & 0xffff;
  if (DAT_208f489e <= uVar7) {
    uVar7 = uVar7 - DAT_208f489e & 0xffff;
  }
  uVar5 = 0;
  bVar8 = uVar7 != 0;
  if (DAT_208f489c != 0) {
    do {
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      uVar2 = FUN_20155122(&DAT_208f48f1 + uVar7 * 0x29);
      memcpy(&local_68,&DAT_208f48f1 + uVar7 * 0x29,uVar2);
      FUN_20135dd4(local_28,&local_68,DAT_2080850a * uVar5 + DAT_208084ee,DAT_208084ec,DAT_20808508,
                   &DAT_20800b1c);
      uVar5 = uVar5 + 1;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar5 < DAT_208f489c);
  }
  if (bVar8) {
    if (((uint)DAT_208f489c < (uint)DAT_208f4899) &&
       ((int)(uint)DAT_208f489e < (int)((uint)DAT_208f4899 - (uint)DAT_208f489c))) {
      DAT_208f4bef = 1;
      goto LAB_20131eb8;
    }
  }
  DAT_208f4bef = 0;
LAB_20131eb8:
  gui_draw_runs(local_28,DAT_2080851a + DAT_20808502,DAT_20808518 + DAT_20808500,&DAT_2016dc58);
  gui_draw_runs(local_28,DAT_2080851e + DAT_20808502,DAT_2080851c + DAT_20808500,&DAT_2016dc68);
  uVar7 = (uint)DAT_208f4899;
  uVar6 = (uint)DAT_208f489c;
  if (uVar6 < uVar7) {
    iVar4 = (uVar7 - uVar6) - (uint)DAT_208f489e;
  }
  else {
    iVar4 = 0;
    uVar6 = 0;
    uVar7 = 0;
  }
  uVar7 = FUN_20136584(local_28,DAT_20808522,DAT_20808520,DAT_20808504,DAT_20808506,iVar4,uVar7,
                       uVar6);
  return uVar7;
}


// ===== FUN_20124744 @ 20124744 (200 bytes)

void FUN_20124744(int param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 local_18;
  undefined3 uStack_17;
  uint uStack_14;
  undefined4 local_10;
  
  if (DAT_2080048e == '\x01') {
    uVar2 = 0xe7;
  }
  else {
    uVar2 = 0xe8;
  }
  _local_18 = CONCAT31(0xff,uVar2);
  local_10 = 0;
  if (param_1 == DAT_208007d8) {
    return;
  }
  switch(param_1) {
  case -9:
    bVar3 = 7;
    break;
  case -8:
    bVar3 = 6;
    break;
  default:
    uVar1 = 0xff;
    goto LAB_20124808;
  case -6:
    bVar3 = 5;
    break;
  case -5:
    bVar3 = 4;
    break;
  case -4:
    bVar3 = 3;
    break;
  case -3:
    bVar3 = 2;
    break;
  case -2:
    bVar3 = 1;
    break;
  case -1:
    bVar3 = 0;
  }
  uVar1 = (ushort)bVar3;
LAB_20124808:
  uStack_14 = (uint)(ushort)(uVar1 << 8);
  DAT_208f1221 = 0x7f;
  DAT_208f1220 = 0xff;
  mainlink_queue_frame(&local_18,9);
  DAT_208007d8 = param_1;
  return;
}


// ===== FUN_20124848 @ 20124848 (80 bytes)

undefined4 FUN_20124848(byte param_1)

{
  undefined4 local_18;
  int iStack_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = 0x1e7;
  DAT_208f1221 = 0x7f;
  DAT_208f1220 = 1;
  iStack_14 = (uint)param_1 << 8;
  mainlink_queue_frame(&local_18,9);
  return 1;
}


// ===== FUN_201248a4 @ 201248a4 (72 bytes)

void FUN_201248a4(byte param_1)

{
  undefined4 local_10;
  int iStack_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x1e8;
  DAT_208f1221 = 0;
  DAT_208f1220 = 1;
  iStack_c = (uint)param_1 << 8;
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== FUN_201248f8 @ 201248f8 (380 bytes)

undefined4 FUN_201248f8(void)

{
  int iVar1;
  
  if (DAT_2080048e == '\x02' || DAT_2080048e == '\x03') {
    if (((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
       (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) {
      iVar1 = FUN_20103ba0();
      if (((iVar1 == 0) && (iVar1 = FUN_201058c0(), iVar1 == 0)) &&
         (DAT_20800490 == '\0' && DAT_2080048f == '\0')) {
        FUN_20124744(0xffffffff);
        DAT_2080048e = 0;
        return 0;
      }
      if ((((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
          (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) &&
         (((DAT_20800490 == '\x01' || (DAT_2080048f == '\x01')) &&
          (iVar1 = FUN_201058c0(), iVar1 != 0)))) {
        FUN_201248a4(0,1);
        FUN_201058c0();
        FUN_20124744();
      }
    }
    iVar1 = FUN_20105790();
    if ((iVar1 == 0) && (DAT_20800490 != '\0' || DAT_2080048f != '\0')) {
      if (DAT_2080048f == '\x01') {
        FUN_20105a20();
        DAT_2080048f = '\0';
      }
      if (DAT_20800490 == '\x01') {
        FUN_2010579c();
        DAT_20800490 = '\0';
      }
      FUN_201248a4(0);
    }
  }
  if ((DAT_2080048e == '\x01') && (iVar1 = FUN_201058c0(), iVar1 != 0)) {
    FUN_20124848(0,1);
    FUN_201058c0();
    FUN_20124744();
    DAT_208007d8 = 0;
    DAT_2080048e = '\0';
    FUN_201058cc();
    DAT_20800490 = '\0';
    DAT_20800491 = 0;
  }
  return 0;
}


// ===== FUN_20124a74 @ 20124a74 (36 bytes)

void FUN_20124a74(int param_1,int param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(&DAT_208f1264 + (param_1 + param_2 & 0xffffU) * 0x34);
  return;
}


// ===== FUN_20124a98 @ 20124a98 (32 bytes)

void FUN_20124a98(int param_1,int param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  puVar6 = (uint *)(&DAT_208f1234 + (param_1 + param_2 & 0xffffU) * 0x34);
  if (((uint)param_3 & 3) == 0) {
    while( true ) {
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar2 = UnsignedSaturate(1 - (uVar9 & 0xff),8);
      uVar3 = UnsignedSaturate(1 - (uVar9 >> 8 & 0xff),8);
      uVar4 = UnsignedSaturate(1 - (uVar9 >> 0x10 & 0xff),8);
      uVar5 = UnsignedSaturate(1 - (uVar9 >> 0x18),8);
      if (CONCAT13((char)uVar5,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar2))) != 0) break;
      *param_3 = uVar9;
      param_3 = param_3 + 1;
    }
    while( true ) {
      *(char *)param_3 = (char)uVar9;
      if ((uVar9 & 0xff) == 0) break;
      uVar9 = uVar9 >> 8;
      param_3 = (uint *)((int)param_3 + 1);
    }
  }
  else {
    do {
      pcVar7 = (char *)((int)puVar6 + 1);
      uVar9 = *puVar6;
      pcVar8 = (char *)((int)param_3 + 1);
      *(char *)param_3 = (char)uVar9;
      if ((char)uVar9 == '\0') {
        return;
      }
      puVar6 = (uint *)((int)puVar6 + 2);
      cVar1 = *pcVar7;
      param_3 = (uint *)((int)param_3 + 2);
      *pcVar8 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_20124ab8 @ 20124ab8 (44 bytes)

void FUN_20124ab8(int param_1,int param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  puVar6 = (uint *)((param_1 + param_2 & 0xffffU) * 0x34 + 0x208f125a);
  if ((((uint)param_3 | (uint)puVar6) & 3) == 0) {
    while( true ) {
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar2 = UnsignedSaturate(1 - (uVar9 & 0xff),8);
      uVar3 = UnsignedSaturate(1 - (uVar9 >> 8 & 0xff),8);
      uVar4 = UnsignedSaturate(1 - (uVar9 >> 0x10 & 0xff),8);
      uVar5 = UnsignedSaturate(1 - (uVar9 >> 0x18),8);
      if (CONCAT13((char)uVar5,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar2))) != 0) break;
      *param_3 = uVar9;
      param_3 = param_3 + 1;
    }
    while( true ) {
      *(char *)param_3 = (char)uVar9;
      if ((uVar9 & 0xff) == 0) break;
      uVar9 = uVar9 >> 8;
      param_3 = (uint *)((int)param_3 + 1);
    }
  }
  else {
    do {
      pcVar7 = (char *)((int)puVar6 + 1);
      uVar9 = *puVar6;
      pcVar8 = (char *)((int)param_3 + 1);
      *(char *)param_3 = (char)uVar9;
      if ((char)uVar9 == '\0') {
        return;
      }
      puVar6 = (uint *)((int)puVar6 + 2);
      cVar1 = *pcVar7;
      param_3 = (uint *)((int)param_3 + 2);
      *pcVar8 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_20124adc @ 20124adc (204 bytes)

int FUN_20124adc(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 0xe7;
  uStack_14 = 0;
  local_10 = 0;
  if (DAT_208f1222 != 0) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    uVar1 = FUN_20135470(param_1 + 0x9b);
    FUN_20124a98(uVar1,*(undefined1 *)(param_1 + 0x9d),&local_30);
    FUN_2015515c(&local_30,&DAT_20124bb8);
    iVar2 = FUN_201057d8(&local_30,&DAT_208f1234,0xff,1);
    if (iVar2 < 1) {
      FUN_20124744();
    }
    else {
      uStack_14._0_2_ = CONCAT11((char)iVar2,(undefined1)uStack_14);
      mainlink_queue_frame(&local_18,9);
      DAT_208f1222 = (short)iVar2;
    }
    return (int)(char)iVar2;
  }
  FUN_20124744(0xfffffffa);
  return -6;
}


// ===== FUN_20124bc0 @ 20124bc0 (100 bytes)

int FUN_20124bc0(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 0xe7;
  uStack_14 = 0;
  local_10 = 0;
  iVar1 = FUN_20105550(&DAT_208f1234,0xff,1);
  if (iVar1 < 1) {
    FUN_20124744();
  }
  else {
    uStack_14._0_2_ = CONCAT11((char)iVar1,(undefined1)uStack_14);
    mainlink_queue_frame(&local_18,9);
    DAT_208f1222 = (undefined2)iVar1;
  }
  return (int)(char)iVar1;
}


// ===== FUN_20124c24 @ 20124c24 (4304 bytes)

void FUN_20124c24(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  undefined2 *puVar7;
  short *psVar8;
  uint uVar9;
  int iVar10;
  short local_5c [2];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined1 auStack_3c [24];
  
  local_58 = fb_get_layer_addr(DAT_208085bc);
  uVar5 = 0;
  iVar10 = 0;
  bVar6 = 0;
  uVar9 = 0;
  if (1 < DAT_2080048e) {
    return;
  }
  DAT_2080048e = 1;
  DAT_20800483 = 1;
  DAT_20800484 = 1;
  switch(*(undefined1 *)(param_1 + 0x98)) {
  case 0:
    if ((*param_2 != ':') || (param_2[0x98] != '\0')) {
      FUN_20124bc0();
    }
    DAT_2080048d = 0;
    DAT_20800490 = 0;
    DAT_208004a1 = *(undefined1 *)(param_1 + 0x9b);
    DAT_208f1224 = 0;
    return;
  case 1:
    uVar2 = FUN_20135470(param_1 + 0x9b);
    puVar7 = DAT_20800810;
    uVar5 = uVar2 & 0xffff;
    DAT_208f1226 = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d) & 0xf;
    DAT_208f1229 = *(byte *)(param_1 + 0x9e) & 0xf;
    DAT_208f122a = *(byte *)(param_1 + 0x9f) >> 7;
    local_54 = DAT_20800818;
    DAT_208f1228 = bVar6;
    FUN_2010579c();
    if (DAT_20800490 != '\0') {
      iVar3 = FUN_20124848(0,1);
      if (iVar3 == 0) {
        return;
      }
      DAT_2080048d = '\0';
      DAT_20800490 = '\0';
    }
    DAT_208f1224 = '\0';
    break;
  case 2:
    uVar2 = FUN_20135470(param_1 + 0x9b);
    uVar5 = uVar2 & 0xffff;
    DAT_208f122c = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d);
    DAT_208f122f = *(char *)(param_1 + 0x9e);
    puVar7 = DAT_20800810;
    local_54 = DAT_20800818;
    DAT_208f122e = bVar6;
    break;
  case 3:
    FUN_20124adc(param_1);
    uVar2 = FUN_20135470(param_1 + 0x9b);
    uVar5 = uVar2 & 0xffff;
    DAT_208f1226 = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d) & 0xf;
    DAT_208f1229 = *(byte *)(param_1 + 0x9e) & 0xf;
    DAT_208f122a = *(byte *)(param_1 + 0x9f) >> 7;
    local_54 = DAT_20800818;
    DAT_20800490 = '\0';
    DAT_208f1224 = '\0';
    DAT_208f122f = '\0';
    puVar7 = DAT_20800810;
    DAT_208f1228 = bVar6;
    break;
  case 4:
    uVar9 = *(byte *)(param_1 + 0x9b) & 1;
    DAT_208004a1 = *(byte *)(param_1 + 0x9c);
    local_54 = (&DAT_20800818)[uVar9];
    puVar7 = (&DAT_20800810)[uVar9];
    break;
  default:
    DAT_20800490 = 0;
    return;
  }
  iVar3 = FUN_20103ba0();
  if (iVar3 == 0) {
    DAT_20800490 = 0;
    DAT_2080048d = 0;
    FUN_2010579c();
    FUN_20124744(0xffffffff);
    return;
  }
  if ((*(char *)(param_1 + 0x98) != param_2[0x98]) || (*(char *)(param_1 + 0x98) == '\x03')) {
    if (DAT_208f462d == '\0') {
      fb_fill_rect(local_58,0x4a69,0,0,800,0x1e0);
      fb_fill_rect(local_58,0x2124,DAT_208006c6,DAT_208006c4,DAT_208006c8,DAT_208006ca);
      gui_draw_runs(local_58,DAT_208006ce,DAT_208006cc,&DAT_2016e184);
      DAT_208f462d = '\x01';
    }
    fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
    fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
    fb_fill_rect(local_58,0x821,0x7e,0x294,*puVar7,puVar7[1]);
    gui_draw_runs(local_58,0x7e,0x294,puVar7);
    gui_draw_runs(local_58,DAT_208006f2 + 0x7e,DAT_208006f0 + 0x294,local_54);
    if ((DAT_20800490 != '\x01') && (*(char *)(param_1 + 0x98) != '\x04')) {
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      sprintf(&local_50,"00:00:00");
      fb_fill_rect(local_58,0x4a69,DAT_208006da,DAT_208006d8,
                   (*(ushort *)PTR_DAT_20800b64 & 0x1fff) << 3,*(undefined2 *)(PTR_DAT_20800b64 + 2)
                  );
      FUN_20135dd4(local_58,&local_50,DAT_208006da,DAT_208006d8,0xf,&DAT_20800b1c);
      local_5c[0] = 0;
      FUN_201219b8(local_58,DAT_208006de,DAT_208006dc,0);
    }
    iVar10 = 1;
  }
  if (*(char *)(param_1 + 0x98) == '\x04' || *(char *)(param_1 + 0x98) == '\x02') {
    fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
    fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
    if (DAT_20800490 != '\0' || uVar9 != 0) {
LAB_201250b4:
      gui_draw_runs(local_58,DAT_208006f6,DAT_208006f4,&DAT_2016ebac);
      if (100 < DAT_208004a1) {
        DAT_208004a1 = 100;
      }
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      sprintf(&local_50,&DAT_20125360,DAT_208004a1);
      local_50 = CONCAT13(0x25,(undefined3)local_50);
      FUN_20135dd4(local_58,&local_50,DAT_208006fa,DAT_208006f8,0x11,&DAT_20803030);
LAB_2012512c:
      if (*(char *)(param_1 + 0x98) == '\x04') {
        fb_fill_rect(local_58,0x821,0x7e,0x294,*puVar7,puVar7[1]);
        gui_draw_runs(local_58,0x7e,0x294,puVar7);
        gui_draw_runs(local_58,DAT_208006f2 + 0x7e,DAT_208006f0 + 0x294,local_54);
      }
      goto LAB_20125194;
    }
    if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_2012512c;
    if (DAT_208f122f == '\x01') goto LAB_201250b4;
LAB_201251a8:
    if (iVar10 == 0) {
      if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_20125284;
      if (*(char *)(param_1 + 0x9e) != param_2[0x9e]) goto LAB_201251d0;
    }
    else {
LAB_201251d0:
      if ((*(char *)(param_1 + 0x9e) != '\x03' && *(char *)(param_1 + 0x9e) != '\x02') &&
         (param_2[0x9e] != '\x03' && param_2[0x9e] != '\x02')) {
        iVar3 = 0;
        do {
          psVar8 = &DAT_2016e1c4 + iVar3 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar3 * 5],*psVar8,(&DAT_2016e1c8)[iVar3 * 5],
                       (&DAT_2016e1ca)[iVar3 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar3 * 5],*psVar8,DAT_20802290);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar3 * 5] + DAT_208006e2,*psVar8 + DAT_208006e0,
                        (&PTR_DAT_208026c8)[iVar3]);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 5);
      }
      if (iVar10 == 0) {
LAB_20125284:
        if (*(char *)(param_1 + 0x98) == '\x01' || *(char *)(param_1 + 0x98) == '\x03')
        goto LAB_20125294;
      }
      else {
LAB_20125294:
        fb_fill_rect(local_58,0x4a69,DAT_208006d2,DAT_208006d0,
                     *(short *)PTR_DAT_20800b64 * 0xf + 0xf,*(undefined2 *)(PTR_DAT_20800b64 + 2));
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        FUN_20124a98(uVar5,bVar6,&local_50);
        FUN_201550dc(auStack_3c,&local_50);
        FUN_20135dd4(local_58,&local_50,DAT_208006d2,DAT_208006d0,0xf,&DAT_20800b1c);
        fb_fill_rect(local_58,0x4a69,DAT_208006d6,DAT_208006d4,*(short *)PTR_DAT_20800b64 * 9,
                     *(undefined2 *)(PTR_DAT_20800b64 + 2));
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        FUN_20124ab8(uVar5,bVar6,&local_50);
        FUN_20135dd4(local_58,&local_50,DAT_208006d6,DAT_208006d4,0xf,&DAT_20800b1c);
        iVar10 = 5;
        do {
          psVar8 = &DAT_2016e1c4 + iVar10 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,
                       (&DAT_2016e1c8)[iVar10 * 5],(&DAT_2016e1ca)[iVar10 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,&DAT_2016e194);
          iVar3 = 0;
          do {
            FUN_20135ad8(local_58,(&DAT_2080080a)[iVar3 * 2] + (&DAT_2016e1c6)[iVar10 * 5],
                         *psVar8 + (&DAT_20800808)[iVar3 * 2],(&DAT_2016e1ca)[iVar10 * 5] + -2,1,
                         0x8410);
            iVar3 = iVar3 + 1;
          } while (iVar3 < 2);
          iVar3 = ((uVar5 + iVar10) - 5 & 0xff) * 0x34;
          FUN_20135dd4(local_58,&DAT_208f1234 + iVar3,DAT_208006e6 + (&DAT_2016e1c6)[iVar10 * 5],
                       *psVar8 + DAT_208006e4,0xf,&DAT_20800b1c);
          FUN_20135dd4(local_58,&DAT_208f1244 + iVar3,DAT_208006ea + (&DAT_2016e1c6)[iVar10 * 5],
                       *psVar8 + DAT_208006e8,0xf,&DAT_20800b1c);
          FUN_20135dd4(local_58,&DAT_208f124f + iVar3,DAT_208006ee + (&DAT_2016e1c6)[iVar10 * 5],
                       *psVar8 + DAT_208006ec,0xf,&DAT_20800b1c);
          if (((uint)DAT_208f1228 == iVar10 - 5U) && (*(char *)(param_1 + 0x98) == '\x01')) {
            if (DAT_208f122a == 0) {
              uVar4 = 0xf980;
            }
            else {
              uVar4 = 0xffff;
            }
            FUN_20136290(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,(&DAT_2016e1c8)[iVar10 * 5],
                         (&DAT_2016e1ca)[iVar10 * 5],3,uVar4);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 9);
        iVar10 = 9;
        do {
          psVar8 = &DAT_2016e1c4 + iVar10 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,
                       (&DAT_2016e1c8)[iVar10 * 5],(&DAT_2016e1ca)[iVar10 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,DAT_20802290);
          gui_draw_runs(local_58,DAT_208006e2 + (&DAT_2016e1c6)[iVar10 * 5],*psVar8 + DAT_208006e0,
                        *(undefined4 *)(iVar10 * 4 + 0x208007fc));
          if ((DAT_208f122a != 0) && ((uint)DAT_208f1229 == iVar10 - 9U)) {
            FUN_20136398(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,(&DAT_2016e1c8)[iVar10 * 5],
                         (&DAT_2016e1ca)[iVar10 * 5],3);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0xb);
        if ((DAT_208f122a == 0) && (DAT_208f1228 == 4)) {
          FUN_20136290(local_58,0x1a2,0x2b4,0x68,0x3c,3,0xf980);
        }
      }
      if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_201256d0;
    }
  }
  else {
LAB_20125194:
    cVar1 = *(char *)(param_1 + 0x98);
    if ((cVar1 == '\x01' || cVar1 == '\x02') || cVar1 == '\x03') goto LAB_201251a8;
LAB_201256d0:
    if (DAT_20800490 == '\0') goto LAB_20125cbc;
  }
  DAT_2080048c = DAT_208f122f;
  if (DAT_208f122f == DAT_2080048d) {
    if (DAT_208f122f == '\x01') {
      if ((((DAT_20800490 == '\x01') && (iVar10 = FUN_20105790(), iVar10 != 4)) &&
          (iVar10 = FUN_20105790(), iVar10 != 8)) &&
         ((iVar10 = FUN_20105790(), iVar10 != 0x10 && (iVar10 = FUN_20105790(), iVar10 != 0x20)))) {
        iVar10 = FUN_20124848(0,1);
        if (iVar10 == 0) {
          return;
        }
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
        fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
        fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
        DAT_20800490 = '\0';
        *(undefined1 *)(param_1 + 0x98) = 2;
        *(undefined1 *)(param_1 + 0x9e) = 0;
        DAT_2080048c = '\0';
        DAT_2080048d = '\0';
        FUN_2011508c(param_1);
      }
    }
    else if (((DAT_208f122f == '\x03' || DAT_208f122f == '\x02') && (DAT_20800490 == '\x01')) &&
            (iVar10 = FUN_20105790(), iVar10 == 0)) {
      iVar10 = FUN_20124848(0,1);
      if (iVar10 == 0) {
        return;
      }
      fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
      gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
      gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
      DAT_20800490 = '\0';
      *(undefined1 *)(param_1 + 0x9e) = 0;
      DAT_2080048c = '\0';
      DAT_2080048d = '\0';
      FUN_2011508c(param_1);
    }
  }
  else {
    if (DAT_208f122f == '\x01') {
      if (DAT_20800490 == '\0') {
        FUN_20124a74(uVar5,bVar6,&local_40);
        if (local_40 != 0) {
LAB_20125a30:
          FUN_20124744(0xfffffff8);
          DAT_208f1224 = 0;
          DAT_20800490 = 0;
          DAT_2080048d = 0;
          FUN_2010579c();
          return;
        }
        iVar10 = FUN_20124848(1);
        if (iVar10 == 0) {
          return;
        }
        local_5c[0] = 0;
        FUN_20105be8(local_5c,&local_50);
        if (local_5c[0] == 0) {
          local_50 = 0;
          local_4c = 0;
          local_48 = 0;
          local_44 = 0;
          FUN_20124a98(uVar5,bVar6,&local_50);
          FUN_20105a54(&local_50,1);
        }
        else {
          FUN_20105ae8();
        }
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1a4);
        DAT_208f1224 = '\x01';
        DAT_20800490 = '\x01';
      }
      else {
        iVar10 = FUN_20105790();
        if ((((iVar10 != 4) && (iVar10 = FUN_20105790(), iVar10 != 8)) &&
            (iVar10 = FUN_20105790(), iVar10 != 0x10)) && (iVar10 = FUN_20105790(), iVar10 != 0x20))
        {
          iVar10 = FUN_20124848(0,1);
          if (iVar10 == 0) {
            return;
          }
          fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
          gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
          gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
          fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
          fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
          DAT_20800490 = '\0';
          *(undefined1 *)(param_1 + 0x98) = 2;
          *(undefined1 *)(param_1 + 0x9e) = 0;
          DAT_2080048c = '\0';
          DAT_2080048d = 0;
          FUN_2011508c(param_1);
        }
      }
    }
    else if (DAT_208f122f == '\0') {
      iVar10 = FUN_20124848(0,1);
      if (iVar10 == 0) {
        return;
      }
      if (DAT_20800490 != '\0') {
        FUN_20105b28();
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
        fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
        fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
        DAT_20800490 = '\0';
      }
    }
    else if (DAT_208f122f == '\x03') {
      FUN_20124a74(uVar5,bVar6,&local_40);
      if (local_40 != 0) goto LAB_20125a30;
      iVar10 = FUN_20124848(1);
      if (iVar10 == 0) {
        return;
      }
      FUN_20105b68();
      *(undefined1 *)(param_1 + 0x9e) = 1;
      FUN_2011508c(param_1);
    }
    else if (DAT_208f122f == '\x02') {
      FUN_20124a74(uVar5,bVar6,&local_40);
      if (local_40 != 0) {
        FUN_20124744(0xfffffff9);
        DAT_208f1224 = 0;
        DAT_20800490 = 0;
        DAT_2080048d = 0;
        FUN_2010579c();
        return;
      }
      iVar10 = FUN_20124848(1);
      if (iVar10 == 0) {
        return;
      }
      FUN_20105ba8();
      *(undefined1 *)(param_1 + 0x9e) = 1;
      FUN_2011508c(param_1);
    }
    else {
      DAT_20800490 = '\0';
      DAT_208f1224 = '\0';
      FUN_2010579c();
    }
    DAT_2080048d = DAT_2080048c;
  }
LAB_20125cbc:
  if (DAT_208f1224 == '\0') {
    return;
  }
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  FUN_20105be8(local_5c,&local_50);
  fb_fill_rect(local_58,0x4a69,DAT_208006da,DAT_208006d8,(*(ushort *)PTR_DAT_20800b64 & 0x1fff) << 3
               ,*(undefined2 *)(PTR_DAT_20800b64 + 2));
  FUN_20135dd4(local_58,&local_50,DAT_208006da,DAT_208006d8,0xf,&DAT_20800b1c);
  FUN_201219b8(local_58,DAT_208006de,DAT_208006dc,local_5c[0]);
  if (local_5c[0] == 100) {
    DAT_208f1224 = '\0';
  }
  return;
}


// ===== FUN_20125d8c @ 20125d8c (232 bytes)

bool FUN_20125d8c(void)

{
  bool bVar1;
  int iVar2;
  short local_30 [4];
  undefined1 auStack_28 [20];
  
  if (((DAT_208f0b2a == 'p' && DAT_2080049e == ':') && (DAT_20800490 != '\0')) &&
     (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
    DAT_2080048e = '\x01';
  }
  else {
    if (DAT_2080048e != '\x01') {
      iVar2 = FUN_20105790();
      if (iVar2 != 8) {
        return false;
      }
      DAT_20800490 = 0;
      FUN_2010579c();
      return false;
    }
    if (DAT_208f0b2a != ':') {
      return false;
    }
    iVar2 = FUN_20103ba0();
    if (iVar2 != 0) {
      bVar1 = (DAT_208f122f == '\x01' || DAT_208f122f == '\x03') || DAT_208f122f == '\x02';
      if ((DAT_208f122f == '\x01' || DAT_208f122f == '\x03') || DAT_208f122f == '\x02') {
        return bVar1;
      }
      local_30[0] = 0;
      FUN_20105be8(local_30,auStack_28);
      if (local_30[0] != 100) {
        return bVar1;
      }
      FUN_2010579c();
      return bVar1;
    }
  }
  DAT_20800490 = 0;
  FUN_2010579c();
  FUN_20124744(0xffffffff);
  return false;
}


// ===== touch_calibration @ 20125e78 (244 bytes)

/* TOUCH THE CROSS */

void touch_calibration(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_20133870(5);
  fb_fill_rect(uVar1,0,0,0,800,0x1e0);
  gui_draw_runs(uVar1,*(undefined2 *)(&DAT_2016d61e + param_1 * 4),
                *(undefined2 *)(&DAT_2016d61c + param_1 * 4),&DAT_2016d60c);
  uVar2 = 0;
  do {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_201550dc(&local_50,(&DAT_20800880)[uVar2]);
    FUN_20135ff0(uVar1,&local_50,uVar2 * 0x14 + 0x177,400,0xf,&DAT_20800b1c);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return;
}


// ===== FUN_20125f6c @ 20125f6c (476 bytes)

void FUN_20125f6c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_20133870(5);
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    fb_fill_rect(uVar1,0,0,0,800,0x1e0);
    break;
  case 1:
    fb_fill_rect(uVar1,0xffff,0,0,800,0x1e0);
    return;
  case 2:
    fb_fill_rect(uVar1,0xf800,0,0,800,0x1e0);
    return;
  case 3:
    fb_fill_rect(uVar1,0x7e0,0,0,800,0x1e0);
    return;
  case 4:
    fb_fill_rect(uVar1,0x1f,0,0,800,0x1e0);
    return;
  case 5:
    fb_fill_rect(uVar1,0xffff,0,0,100,0x1e0);
    fb_fill_rect(uVar1,0xfea0,0,100,100,0x1e0);
    fb_fill_rect(uVar1,0x57d,0,200,100,0x1e0);
    fb_fill_rect(uVar1,0x7e0,0,300,100,0x1e0);
    fb_fill_rect(uVar1,0xf81f,0,400,100,0x1e0);
    fb_fill_rect(uVar1,0xf800,0,500,100,0x1e0);
    fb_fill_rect(uVar1,0x1f,0,600,100,0x1e0);
    fb_fill_rect(uVar1,0,0,700,100,0x1e0);
    return;
  }
  return;
}


// ===== FUN_20126160 @ 20126160 (12 bytes)

void FUN_20126160(undefined1 param_1)

{
  DAT_20800480 = param_1;
  return;
}


// ===== FUN_2012616c @ 2012616c (116 bytes)

void FUN_2012616c(int param_1)

{
  if (param_1 == 1) {
    FUN_20126160(1);
    DAT_208007cc = FUN_20111174(0xffffffff);
    FUN_20133d7c();
    return;
  }
  if (param_1 == 0) {
    if (DAT_208007cc == 0) {
      return;
    }
    FUN_20133da8();
  }
  else if (DAT_208007cc == 0) {
    return;
  }
  DAT_208007cc = 0;
  FUN_20133620();
  FUN_20126160(0);
  return;
}


// ===== FUN_201261e0 @ 201261e0 (456 bytes)

void FUN_201261e0(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_c = 0;
  local_a = 800;
  local_10 = 0;
  local_1c = 0;
  local_e = 0x1e0;
  local_28 = &local_10;
  local_1a = 0;
  local_19 = 0xff;
  local_24 = &local_1c;
  local_18 = 0;
  local_20 = 0;
  FUN_20133658(0,5,1,&local_28);
  FUN_20133658(1,5,1,&local_28);
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 == 0x41) {
switchD_2012629c_caseD_43:
    if (*(char *)(param_1 + 2) == '\x01') {
LAB_20126304:
      FUN_20134984(param_1);
      return;
    }
    if ((*(char *)(param_1 + 2) == '\x10') && (iVar2 = FUN_20134990(param_1), iVar2 != 0)) {
      FUN_2013499c(param_1);
      return;
    }
  }
  else {
    if (bVar1 < 0x42) {
      switch(bVar1) {
      default:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        FUN_20134978(param_1);
        return;
      case 5:
        FUN_201349d8(param_1);
        return;
      case 8:
        FUN_201349f0(param_1);
        return;
      }
    }
    switch(bVar1) {
    case 0x42:
    case 0x44:
      bVar1 = *(byte *)(param_1 + 2);
      if (bVar1 == 3) {
        FUN_201349b4(param_1);
        return;
      }
      if (3 < bVar1) {
        if (bVar1 == 4) {
          FUN_201349c0(param_1);
          return;
        }
        if (bVar1 != 0x10) {
          return;
        }
        FUN_201349cc(param_1);
        return;
      }
      if (bVar1 != 1) {
        if (bVar1 != 2) {
          return;
        }
        FUN_201349a8(param_1);
        return;
      }
      goto LAB_20126304;
    case 0x43:
      goto switchD_2012629c_caseD_43;
    case 0x45:
      FUN_201349e4(param_1);
      return;
    case 0x48:
      if (*(char *)(param_1 + 2) == '\x01') {
        FUN_201349fc(param_1);
        return;
      }
      if (*(char *)(param_1 + 2) == '\x10') {
        FUN_20134a08(param_1);
        return;
      }
    }
  }
  return;
}


// ===== FUN_201263e8 @ 201263e8 (696 bytes)

void FUN_201263e8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if ((*(char *)(param_1 + 0x98) == '\x01') && (*(char *)(param_1 + 0x99) != '\0')) {
    fb_fill_rect(uVar1,0x821,0,0,800,0x1e0);
    fb_fill_rect(uVar1,0x4a69,0x1e,3,0x31a,0x1c2);
    fb_fill_rect(uVar1,0x3186,3,3,0x31a,0x18);
    gui_draw_runs(uVar1,3,3,&DAT_2016dc08);
    FUN_20135ff0(uVar1,"CERTIFICATIONS",4,400,0xf,&DAT_20800b1c);
    FUN_201363c0(uVar1,DAT_20800602,DAT_20800600,DAT_20800604,DAT_20800606,
                 *(undefined4 *)(&DAT_2016edbc + (uint)*(byte *)(param_1 + 0x99) * 4),0x19,0xc,0x821
                );
    fb_fill_rect(uVar1,0x821,DAT_208005f2,DAT_208005f0,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005f2,DAT_208005f0,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005f6,DAT_208005f4,&DAT_2016dc58);
    fb_fill_rect(uVar1,0x821,DAT_208005fa,DAT_208005f8,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005fa,DAT_208005f8,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005fe,DAT_208005fc,&DAT_2016dc68);
    fb_fill_rect(uVar1,0x821,0x1a0,0x247,*DAT_20802290,DAT_20802290[1]);
    gui_draw_runs(uVar1,0x1a0,0x247,DAT_20802290);
    gui_draw_runs(uVar1,0x1b7,0x250,&DAT_2016edb0);
    FUN_20136398(uVar1,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    FUN_20135aa4(uVar1,400,10,0x2b2,1,0x821);
    sVar5 = 10;
    iVar4 = 0;
    do {
      sVar5 = sVar5 + 0x1e;
      uVar3 = 0x23;
      iVar2 = *(int *)(&DAT_2016edbc + (uint)*(byte *)(param_1 + 0x99) * 4) + iVar4;
      if (iVar2 == 0 || iVar2 == 0xf) {
        uVar3 = 0x14;
      }
      FUN_20135ec0(uVar1,"FCC ID : K6620801X50" + iVar2 * 0x31,sVar5,uVar3,0x10,&DAT_20803030);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
  }
  return;
}


// ===== FUN_201266ec @ 201266ec (304 bytes)

void FUN_201266ec(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  char local_28;
  char local_27;
  char local_26;
  undefined2 local_24 [2];
  undefined2 local_20 [2];
  undefined1 local_1c;
  
  if ((param_3 != 0) || ((*param_1 & 3) != (*param_2 & 3))) {
    bVar2 = *param_2;
    uVar4 = *param_1 & 1;
    uVar1 = (*param_1 & 3) >> 1;
    if (((param_3 != 0 || uVar4 != (bVar2 & 1)) && (FUN_20101dec(uVar4), param_3 != 0)) ||
       (uVar1 != (bVar2 & 3) >> 1)) {
      local_1c = FUN_20132bc0(uVar1);
      iVar3 = FUN_20113f50();
      if (iVar3 != 0) {
        FUN_20113f60(local_24,local_20);
        FUN_20133a38(6);
        FUN_20113f38(local_24[0],local_20[0]);
        FUN_201218a4();
      }
      if (param_3 != 0) goto LAB_201267bc;
    }
  }
  if ((param_1[5] & 0x1f) == (param_2[5] & 0x1f)) {
    return;
  }
LAB_201267bc:
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  bVar2 = param_1[5] & 0x1f;
  if (0x14 < bVar2) {
    bVar2 = 0x14;
  }
  local_28 = bVar2 * '\n' + '\x1c';
  local_26 = bVar2 * '\n' + '\x11';
  local_30 = &local_28;
  local_27 = local_28;
  FUN_201182d4(0,&local_38);
  return;
}


// ===== FUN_2012681c @ 2012681c (248 bytes)

void FUN_2012681c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,param_3,
               *(short *)((&PTR_DAT_208022a0)[param_4] + 2) + -2,2,0xf980);
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,
               (uint)*(ushort *)(&PTR_DAT_208022a0)[param_4] + param_3 + -2 & 0xffff,
               *(ushort *)((int)(&PTR_DAT_208022a0)[param_4] + 2) - 2,2,0xf980);
  FUN_20135aa4(param_1,param_2,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
               0xf980);
  FUN_20135aa4(param_1,(uint)*(ushort *)((int)(&PTR_DAT_208022a0)[param_4] + 2) + param_2 + -2 &
                       0xffff,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
               0xf980);
  gui_draw_runs(param_1,param_2,param_3,(&PTR_DAT_208022a0)[param_4]);
  return;
}


// ===== FUN_20126914 @ 20126914 (324 bytes)

void FUN_20126914(undefined4 param_1,int param_2,int param_3,int param_4)

{
  fb_fill_rect(param_1,0x4a69,param_2 + 2U & 0xffff,param_3 + 2U & 0xffff,
               **(short **)(&DAT_2080228c + param_4 * 4) + -4,
               (*(short **)(&DAT_2080228c + param_4 * 4))[1] + -4);
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,param_3,
               *(short *)(*(int *)(&DAT_2080228c + param_4 * 4) + 2) + -2,2,0x821);
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,
               (uint)**(ushort **)(&DAT_2080228c + param_4 * 4) + param_3 + -2 & 0xffff,
               *(short *)((&PTR_DAT_208022a0)[param_4] + 2) + -2,2,0x821);
  FUN_20135aa4(param_1,param_2,param_3 + 1U & 0xffff,**(short **)(&DAT_2080228c + param_4 * 4) + -2,
               2,0x821);
  FUN_20135aa4(param_1,(uint)*(ushort *)(*(int *)(&DAT_2080228c + param_4 * 4) + 2) + param_2 + -2 &
                       0xffff,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
               0x821);
  gui_draw_runs(param_1,param_2,param_3,*(undefined4 *)(&DAT_2080228c + param_4 * 4));
  return;
}


// ===== FUN_20126a58 @ 20126a58 (1084 bytes)

void FUN_20126a58(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined **ppuVar6;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  uint local_28;
  
  iStack_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  local_28 = param_4;
  local_3c = fb_get_layer_addr(DAT_208085bc);
  iVar3 = 0;
  if (param_3 < 3) {
    puVar4 = (ushort *)(&PTR_DAT_208022c0)[param_2];
  }
  else {
    puVar4 = (ushort *)(&PTR_DAT_208022d0)[param_2];
  }
  local_38 = (uint)(param_3 >= 3);
  if (((uint)puVar4[1] + param_6 < 0x1e1) && ((uint)*puVar4 + param_5 < 0x321)) {
    if (param_1 != 0) {
      FUN_2013573c(local_3c,0xf980,param_6,param_5,(uint)*puVar4,(uint)puVar4[1],2);
      fb_fill_rect(local_3c,0x821,param_6 + 2U & 0xffff,param_5 + 2U & 0xffff,*puVar4 - 4,
                   puVar4[1] - 4);
      iVar1 = 0;
      if ((&DAT_2016d28c)[param_2] != '\0') {
        do {
          if (param_2 == 3) {
            if (param_3 < 3) {
              if (param_3 < 2) {
                iVar3 = 0;
              }
            }
            else {
              iVar3 = 2;
            }
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
            FUN_201354ec(&local_54);
            FUN_20135ff0(local_3c,&local_54,
                         (uint)(ushort)(&DAT_2016dcca)[iVar3 * 2] + param_6 & 0xffff,
                         (uint)(ushort)(&DAT_2016dcc8)[iVar3 * 2] + param_5 & 0xffff,
                         **(undefined2 **)(DAT_208022ec + 0x48),DAT_208022ec);
          }
          else if (param_2 == 1) {
            if (param_3 < 3) {
              if (param_3 == 1) {
                iVar3 = 0;
              }
            }
            else {
              iVar3 = 1;
            }
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
            FUN_201354ec(&local_54);
            FUN_20135ff0(local_3c,&local_54,
                         (uint)(ushort)(&DAT_2016dcca)[iVar3 * 2] + param_6 + iVar1 * 0x28 & 0xffff,
                         (uint)(ushort)(&DAT_2016dcc8)[iVar3 * 2] + param_5 & 0xffff,
                         **(undefined2 **)(DAT_208022e4 + 0x48),DAT_208022e4);
          }
          else {
            iVar3 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            if (param_2 == 0) {
              FUN_20155310(&local_54,&DAT_20126eb8,0x16);
              FUN_201354ec(&local_54);
              FUN_20135ff0(local_3c,&local_54,param_6 + iVar1 * 0x28 + 0x14U & 0xffff,
                           param_5 + 0xaaU & 0xffff,**(undefined2 **)(DAT_208022e0 + 0x48),
                           DAT_208022e0);
            }
            else {
              memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
              FUN_201354ec(&local_54);
              FUN_20135ff0(local_3c,&local_54,param_6 + iVar1 * 0x28 + 0x14U & 0xffff,
                           param_5 + 0xaaU & 0xffff,
                           **(undefined2 **)((&DAT_208022e0)[param_2] + 0x48),
                           (&DAT_208022e0)[param_2]);
            }
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)(uint)(byte)(&DAT_2016d28c)[param_2]);
      }
    }
    if (local_38 == 0) {
      uVar2 = 0;
      uVar5 = (((uint)puVar4[1] + param_6) -
              (uint)*(ushort *)
                     (*(int *)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[param_3] * 4) + 2)) -
              0x14 & 0xffff;
      if ((&DAT_20800650)[param_3] != '\0') {
        ppuVar6 = &PTR_DAT_208022f0 + param_3 * 2;
        do {
          puVar4 = (ushort *)(&DAT_2016dcd4 + uVar2 * 4 + param_3 * 8);
          FUN_20126914(local_3c,uVar5,(uint)*puVar4 + param_5 & 0xffff,(&DAT_20800654)[param_3]);
          gui_draw_runs(local_3c,*(ushort *)(&DAT_2016dcf6 + param_3 * 4) + uVar5 & 0xffff,
                        (uint)*puVar4 + (uint)*(ushort *)(&DAT_2016dcf4 + param_3 * 4) + param_5 &
                        0xffff,ppuVar6[uVar2]);
          if (uVar2 == local_28) {
            FUN_2012681c(local_3c,uVar5,(uint)*puVar4 + param_5 & 0xffff,(&DAT_20800654)[param_3]);
          }
          uVar2 = uVar2 + 1 & 0xff;
        } while (uVar2 < (byte)(&DAT_20800650)[param_3]);
      }
    }
  }
  return;
}


// ===== FUN_20126ebc @ 20126ebc (108 bytes)

void FUN_20126ebc(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  byte bVar5;
  
  bVar5 = *(byte *)(param_1 + 0x98);
  bVar4 = *(byte *)(param_1 + 0x99);
  uVar1 = *(undefined1 *)(param_1 + 0x9a);
  if (3 < bVar5) {
    bVar5 = 3;
  }
  if (3 < bVar4) {
    bVar4 = 3;
  }
  uVar2 = FUN_20135470(param_1 + 0x9c);
  uVar3 = FUN_20135470(param_1 + 0x9e);
  FUN_20126a58(param_2,bVar5,bVar4,uVar1,uVar2,uVar3,param_1 + 0xa0);
  return;
}


// ===== FUN_20126f28 @ 20126f28 (676 bytes)

void FUN_20126f28(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  short *local_50;
  undefined2 *local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  short local_38;
  short local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_54 = fb_get_layer_addr(DAT_208085bc);
  if (param_3 != 0) {
    local_34 = 0;
    local_38 = DAT_208004a4;
    local_44 = 0;
    local_42 = 0;
    local_36 = 0x1e0 - DAT_208004a4;
    local_50 = &local_38;
    local_41 = 0xff;
    local_4c = &local_44;
    local_32 = 800;
    local_40 = 0;
    local_48 = 0;
    FUN_20133658(0,5,1,&local_50);
    FUN_20133658(1,5,1,&local_50);
    fb_fill_rect(local_54,0x821,DAT_208004a4,0,800,0x1e0 - DAT_208004a4);
    iVar1 = 0;
    do {
      FUN_20135aa4(local_54,iVar1 * (uint)DAT_208004a6 + (uint)DAT_208004ee & 0xffff,DAT_208004ec,
                   DAT_208004f0,DAT_208004f2,0x8410);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  uVar2 = 0;
  do {
    if (((param_3 != 0) || (*(char *)(param_1 + 0x98) != *(char *)(param_2 + 0x98))) ||
       (iVar1 = FUN_2015507c(param_1 + uVar2 * 0x1c + 0x9a,param_2 + uVar2 * 0x1c + 0x9a,0x1c),
       iVar1 != 0)) {
      local_30 = 0;
      local_2c = 0;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      iVar1 = param_1 + uVar2 * 0x1c;
      FUN_2014e2e4(&local_30,iVar1 + 0x9a,5);
      FUN_2014e2e4(&local_70,iVar1 + 0x9f,0x14);
      FUN_2014e2e4(&local_58,iVar1 + 0xb3,3);
      fb_fill_rect(local_54,0x821,uVar2 * DAT_208004a6 + (uint)DAT_208004e2 & 0xffff,0,800,0x18);
      if (*(byte *)(param_1 + 0x98) == uVar2) {
        gui_draw_runs(local_54,uVar2 * DAT_208004a6 + (uint)DAT_208004de & 0xffff,DAT_208004dc,
                      &DAT_2016d310);
      }
      FUN_20135dd4(local_54,&local_30,uVar2 * DAT_208004a6 + (uint)DAT_208004e2 & 0xffff,
                   DAT_208004e0,0xf,&DAT_20800cac);
      FUN_20135dd4(local_54,&local_70,uVar2 * DAT_208004a6 + (uint)DAT_208004e6 & 0xffff,
                   DAT_208004e4,0xf,&DAT_20800cac);
      FUN_20135dd4(local_54,&local_58,uVar2 * DAT_208004a6 + (uint)DAT_208004ea & 0xffff,
                   DAT_208004e8,0xf,&DAT_20800cac);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 9);
  return;
}


// ===== FUN_201271cc @ 201271cc (904 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_201271cc(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  ushort *puVar6;
  short *psVar7;
  int iVar8;
  short sVar9;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  puVar5 = (undefined *)0x0;
  iVar8 = 0;
  DAT_20800465 = (undefined1)param_1;
  param_1 = param_1 * 0x2f;
  do {
    puVar6 = &DAT_20801fb6 + iVar8 * 5;
    sVar9 = (&DAT_20801fba)[iVar8 * 5];
    if (sVar9 == 0x102) {
      psVar7 = (short *)&UNK_2016d93c;
    }
    else if (sVar9 == 0x7e) {
      psVar7 = (short *)&UNK_2016d92c;
    }
    else if (sVar9 == 0x66) {
      psVar7 = &DAT_2016d90c;
    }
    else {
      psVar7 = &DAT_2016d94c;
    }
    uVar3 = (uint)(byte)(&DAT_20801d53)[iVar8 + param_1];
    if (uVar3 == 0xe2) {
      psVar7 = (short *)&UNK_2016d91c;
    }
    else if ((uVar3 == 0xe3 || uVar3 == 0xec) || uVar3 == 0xed) {
      psVar7 = &DAT_2016d90c;
    }
    sVar9 = 0;
    if (uVar3 == 0xe7) {
      psVar7 = &DAT_2016d90c;
      uVar4 = (uint)DAT_2080057c;
      puVar5 = &UNK_2016d9bc;
      uVar3 = (uint)DAT_2080057e;
      goto LAB_201273f8;
    }
    if (uVar3 < 0xe8) {
      if (uVar3 == 0xe3) {
        uVar4 = (uint)DAT_20800580;
        puVar5 = &UNK_2016d98c;
        uVar3 = (uint)DAT_20800582;
      }
      else if (uVar3 < 0xe4) {
        uVar4 = 0;
        if (uVar3 == 0) goto LAB_20127424;
        if (uVar3 == 0xe1) {
          puVar5 = &DAT_2016d97c;
          uVar4 = (uint)DAT_20800578;
          uVar3 = (uint)DAT_2080057a;
        }
        else {
          if (uVar3 != 0xe2) goto switchD_201272d0_default;
          uVar4 = (uint)DAT_20800580;
          puVar5 = &UNK_2016d99c;
          uVar3 = (uint)DAT_20800582;
        }
      }
      else if (uVar3 == 0xe4) {
        puVar5 = &DAT_2016d96c;
        uVar4 = (uint)DAT_2080057c;
        uVar3 = (uint)DAT_2080057e;
      }
      else if (uVar3 == 0xe5) {
        uVar4 = (uint)DAT_20800584;
        puVar5 = &UNK_2016d9fc;
        uVar3 = (uint)DAT_20800586;
      }
      else {
        if (uVar3 != 0xe6) goto switchD_201272d0_default;
        puVar5 = &DAT_2016d9cc;
        uVar4 = (uint)DAT_2080057c;
        uVar3 = (uint)DAT_2080057e;
      }
      goto LAB_201273f8;
    }
    switch(uVar3) {
    case 0xe8:
    case 0xe9:
      uVar4 = (uint)DAT_20800570;
      uVar3 = (uint)DAT_20800572;
      break;
    case 0xea:
      uVar4 = (uint)DAT_20800588;
      puVar5 = &UNK_2016d9dc;
      uVar3 = (uint)DAT_2080058a;
      break;
    case 0xeb:
      uVar4 = (uint)DAT_20800588;
      puVar5 = &UNK_2016d9ec;
      uVar3 = (uint)DAT_2080058a;
      break;
    case 0xec:
      puVar5 = &UNK_2016d95c;
      uVar4 = (uint)DAT_20800574;
      uVar3 = (uint)DAT_20800576;
      break;
    case 0xed:
      puVar5 = &UNK_2016d9ac;
      uVar4 = (uint)DAT_20800574;
      uVar3 = (uint)DAT_20800576;
      break;
    default:
switchD_201272d0_default:
      puVar5 = *(undefined **)(&DAT_208012b8 + (uint)(byte)(&DAT_2080173c)[uVar3] * 4);
      uVar4 = _DAT_2080056c;
      goto LAB_20127424;
    }
LAB_201273f8:
    uVar4 = uVar4 | uVar3 << 0x10;
LAB_20127424:
    if ((iVar8 == 0x20) && ((&DAT_20801d73)[param_1] != -0x1e && (&DAT_20801d73)[param_1] != -0x1d))
    {
      sVar9 = 0x24;
      psVar7 = &DAT_2016d94c;
      uVar4 = uVar4 & 0xffff0000 | uVar4 + 0x24 & 0xffff;
    }
    fb_fill_rect(uVar2,0x821,(&DAT_20801fb8)[iVar8 * 5] + 1,*puVar6 + sVar9 + 1,*psVar7 + -2,
                 psVar7[1] + -2);
    gui_draw_runs(uVar2,(&DAT_20801fb8)[iVar8 * 5],*puVar6 + sVar9,psVar7);
    cVar1 = (&DAT_20801d53)[iVar8 + param_1];
    if (cVar1 == -0x18) {
      FUN_20135ec0(uVar2,&DAT_201275e0,
                   (uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                   *puVar6 + uVar4 & 0xffff,0x18,&DAT_208012b8);
    }
    else if (cVar1 == -0x17) {
      FUN_20135ec0(uVar2,&DAT_201275e4,
                   (uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                   *puVar6 + uVar4 & 0xffff,0x18,&DAT_208012b8);
    }
    else if (cVar1 != '\0') {
      gui_draw_runs(uVar2,(uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                    *puVar6 + uVar4 & 0xffff,puVar5);
    }
    iVar8 = iVar8 + 1;
    if (0x2e < iVar8) {
      return;
    }
  } while( true );
}


// ===== FUN_201275e8 @ 201275e8 (1340 bytes)

void FUN_201275e8(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte local_a8 [96];
  undefined4 local_48;
  undefined2 *local_44;
  undefined2 *local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  
  local_48 = fb_get_layer_addr(DAT_208085bc);
  iVar7 = 0;
  bVar2 = *(byte *)(param_1 + 0x98);
  uVar3 = bVar2 & 0xf;
  uVar8 = *(byte *)(param_1 + 0x99) & 0x3f;
  uVar6 = *(byte *)(param_2 + 0x99) & 0x3f;
  local_28 = 0x28;
  DAT_20800464 = (&DAT_20801d44)[uVar3 % 3 + ((uint)(bVar2 >> 4) % 5) * 3];
  uVar4 = (uint)DAT_20800464;
  memcpy(&DAT_20801fb6,(&PTR_DAT_20802198)[uVar4],0x1e0,uVar3 * -0x55555555);
  if ((param_3 == 0) && ((uint)*(byte *)(param_2 + 0x98) == (uint)bVar2)) {
    memcpy(local_a8,param_2 + 0xc2,0x32);
    memcpy(local_a8 + 0x34,param_2 + 0x9a,local_28);
  }
  else {
    FUN_20107d8c(uVar4);
    local_30 = 0;
    local_44 = &local_30;
    local_38 = 0;
    local_2e = 0x1e0;
    local_36 = 0;
    local_2c = 0;
    local_35 = 0xff;
    local_40 = &local_38;
    local_2a = 800;
    local_34 = 0;
    local_3c = 0;
    FUN_20133658(0,5,1,&local_44);
    FUN_20133658(1,5,1,&local_44);
    fb_copy_rect(local_48,0,0,800,0x1e0);
    fb_fill_rect(local_48,0x821,0,0,800,0x1e0);
    fb_fill_rect(local_48,0x4a69,DAT_20800546,DAT_20800544,DAT_20800548,DAT_2080054a);
    fb_fill_rect(local_48,0x821,DAT_20800562,DAT_20800560,DAT_20800564,DAT_20800566);
    FUN_201271cc(DAT_20800464);
    memclr(local_a8,0x32);
    memclr(local_a8 + 0x34,local_28);
  }
  iVar5 = 0;
  do {
    if (uVar8 != uVar6) {
      uVar3 = (uint)DAT_2080055c + uVar6 * 0xf & 0xffff;
      bVar2 = *(byte *)(param_1 + uVar6 + 0xc2);
      fb_fill_rect(local_48,0x821,DAT_2080055e,uVar3,0xf,0x18);
      gui_draw_runs(local_48,DAT_2080055e,uVar3,
                    *(undefined4 *)(&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[bVar2] * 4));
      uVar6 = uVar8;
    }
    uVar3 = (uint)*(byte *)(param_1 + iVar5 + 0xc2);
    if (local_a8[iVar5] != uVar3) {
      fb_fill_rect(local_48,0x821,DAT_2080055e,(uint)DAT_2080055c + iVar5 * 0xf & 0xffff,0xf,0x18);
      gui_draw_runs(local_48,DAT_2080055e,(uint)DAT_2080055c + iVar5 * 0xf & 0xffff,
                    *(undefined4 *)(&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[uVar3] * 4));
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x32);
  fb_fill_rect(local_48,0xffff,DAT_2080055e,(uint)DAT_2080055c + uVar8 * 0xf + 1 & 0xffff,
               DAT_20800568,DAT_2080056a);
  iVar5 = FUN_2015507c(param_1 + 0x9a,local_a8 + 0x34,local_28);
  if (iVar5 != 0) {
    fb_fill_rect(local_48,0x821,DAT_2080054e,DAT_2080054c,DAT_20800548,0x1e0 - DAT_2080054a);
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0xa4,0x14);
    uVar6 = 0;
    iVar5 = FUN_20155122(local_a8);
    if (iVar5 != 0) {
      do {
        pbVar1 = local_a8 + uVar6;
        uVar6 = uVar6 + 1;
        if (*pbVar1 == 0x20) {
          iVar7 = iVar7 + 1;
        }
        uVar3 = FUN_20155122(local_a8);
      } while (uVar6 < uVar3);
    }
    iVar5 = FUN_20155122(local_a8);
    uVar3 = 0;
    uVar6 = (uint)DAT_20800554 - ((iVar5 * 0xf + iVar7 * -7 & 0xffffU) >> 1);
    iVar7 = FUN_20155122(local_a8);
    if (iVar7 != 0) {
      do {
        uVar6 = uVar6 & 0xffff;
        if (local_a8[uVar3] == 0x20) {
          uVar6 = uVar6 + 8;
        }
        else {
          gui_draw_runs(local_48,DAT_20800556,uVar6,
                        *(undefined4 *)
                         (&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[local_a8[uVar3]] * 4));
          uVar6 = uVar6 + 0xf;
        }
        uVar3 = uVar3 + 1;
        uVar4 = FUN_20155122(local_a8);
      } while (uVar3 < uVar4);
    }
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0x9a,10);
    FUN_20135ec0(local_48,local_a8,DAT_20800552,DAT_20800550,0xf,&DAT_20800cac);
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0xb8,10);
    FUN_20135ec0(local_48,local_a8,DAT_2080055a,DAT_20800558,0xf,&DAT_20800cac);
  }
  return;
}


// ===== FUN_20127b24 @ 20127b24 (1516 bytes)

void FUN_20127b24(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  iVar7 = (uint)*(byte *)(param_1 + 0x98) << 0x19;
  local_2c = (uint)(*(byte *)(param_1 + 0x99) >> 4);
  local_30 = *(byte *)(param_1 + 0x99) & 0xf;
  if (param_2 != 0) {
    if ((*(byte *)(param_1 + 5) & 0x20) == 0) {
      iVar3 = 0xb4;
    }
    else {
      iVar3 = 0x6d;
    }
    fb_fill_rect(uVar1,0x821,iVar3,0,800,0x1e0 - iVar3);
    fb_fill_rect(uVar1,0x4a69,DAT_2080058e,DAT_2080058c,DAT_20800590,DAT_20800592);
  }
  fb_fill_rect(uVar1,0x2124,DAT_20800596,DAT_20800594,DAT_20800598,DAT_2080059a);
  gui_draw_runs(uVar1,DAT_20800702,DAT_20800700,&DAT_2016dae8);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  FUN_201636cc(&local_40,param_1 + 0xab);
  FUN_20135dd4(uVar1,&local_40,DAT_2080059e,DAT_2080059c,0xf,&DAT_2080099c);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_40 = *(undefined4 *)(param_1 + 0xb0);
  FUN_20135dd4(uVar1,&local_40,DAT_208005a2,DAT_208005a0,0xe,&DAT_2080099c);
  uVar5 = 0;
  do {
    psVar4 = &DAT_2016db98 + uVar5 * 5;
    fb_fill_rect(uVar1,0x821,(&DAT_2016db9a)[uVar5 * 5],*psVar4,0x239,0x3c);
    gui_draw_runs(uVar1,(&DAT_2016db9a)[uVar5 * 5],*psVar4,&DAT_2016d5fc);
    iVar3 = 0;
    do {
      FUN_20135ad8(uVar1,(&DAT_20802282)[iVar3 * 2] + (&DAT_2016db9a)[uVar5 * 5],
                   *psVar4 + (&DAT_20802280)[iVar3 * 2],0x3a,1,0x8410);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    if (uVar5 == local_30) {
      if (iVar7 < 0) {
        uVar2 = 0xffff;
      }
      else {
        uVar2 = 0xf980;
      }
      FUN_20136290(uVar1,(&DAT_2016db9a)[uVar5 * 5],*psVar4,0x239,0x3c,3,uVar2);
    }
    iVar3 = param_1 + uVar5 * 0x24;
    if ((*(byte *)(iVar3 + 0xb5) & 2) != 0) {
      gui_draw_runs(uVar1,DAT_208005b2 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b0,
                    &DAT_2016daf8);
    }
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    FUN_201636cc(&local_40,iVar3 + 0xb6);
    FUN_20135dd4(uVar1,&local_40,DAT_208005b6 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b4,
                 0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xbb,10);
    FUN_20135dd4(uVar1,&local_40,DAT_208005ba + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b8,
                 0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xc5,7);
    FUN_20135dd4(uVar1,&local_40,DAT_208005be + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005bc,
                 0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    if ((*(byte *)(iVar3 + 0xb5) & 1) == 0) {
      puVar9 = &DAT_20801134;
    }
    else {
      puVar9 = &DAT_20800cac;
    }
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xcd,0xc);
    FUN_20135dd4(uVar1,&local_40,DAT_208005c2 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005c0,
                 0xf,puVar9);
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 4);
  iVar3 = 4;
  iVar8 = local_2c + 4;
  do {
    puVar6 = &DAT_2016db98 + iVar3 * 5;
    fb_fill_rect(uVar1,0x821,(&DAT_2016db9a)[iVar3 * 5],*puVar6,*DAT_20802290,DAT_20802290[1]);
    gui_draw_runs(uVar1,(&DAT_2016db9a)[iVar3 * 5],*puVar6,DAT_20802290);
    if ((iVar7 < 0) && (iVar3 == iVar8)) {
      FUN_20136398(uVar1,(&DAT_2016db9a)[iVar3 * 5],*puVar6,
                   *(undefined2 *)(&UNK_2016db9c + iVar3 * 10),
                   *(undefined2 *)(&UNK_2016db9e + iVar3 * 10),3);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  gui_draw_runs(uVar1,DAT_208005a6 + 0xd3,DAT_208005a4 + 0x244,&DAT_2016db48);
  gui_draw_runs(uVar1,DAT_208005a6 + 0xd3,DAT_208005a4 + 0x2b4,&DAT_2016db38);
  gui_draw_runs(uVar1,DAT_208005aa + 0x118,DAT_208005a8 + 0x244,&DAT_2016db68);
  gui_draw_runs(uVar1,DAT_208005ae + 0x118,DAT_208005ac + 0x244,&DAT_2016db28);
  gui_draw_runs(uVar1,DAT_208005aa + 0x118,DAT_208005a8 + 0x2b4,&DAT_2016db08);
  gui_draw_runs(uVar1,DAT_208005ae + 0x118,DAT_208005ac + 0x2b4,&DAT_2016db78);
  if ((*(byte *)(param_1 + 0x98) & 0x80) == 0) {
    gui_draw_runs(uVar1,DAT_208005a6 + 0x15d,DAT_208005a4 + 0x2b4,&DAT_2016db18);
  }
  else {
    gui_draw_runs(uVar1,DAT_208005a6 + 0x15d,DAT_208005a4 + 0x2b4,&DAT_2016db58);
  }
  gui_draw_runs(uVar1,DAT_208005a6 + 0x1a2,DAT_208005a4 + 0x2b4,&DAT_2016db88);
  return;
}


// ===== FUN_201281c0 @ 201281c0 (540 bytes)

void FUN_201281c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  bVar3 = *(byte *)(param_1 + 0x9b) & 0xf;
  if (param_3 != 0) {
    fb_fill_rect(local_2c,0x821,DAT_2080060a,DAT_20800628 + DAT_20800634 + 1,DAT_208005e0,
                 DAT_208005e2);
  }
  uVar2 = 0;
  do {
    if ((param_3 != 0) ||
       (iVar1 = FUN_2015507c(param_1 + uVar2 * 0x1e + 0x119,param_2 + uVar2 * 0x1e + 0x119,0x1e),
       iVar1 != 0)) {
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_4c,param_1 + uVar2 * 0x1e + 0x119,0x1e);
      FUN_20135dd4(local_2c,&local_4c,DAT_2080064e * uVar2 + (uint)DAT_2080063a & 0xffff,
                   DAT_20800638,0xf,&DAT_20800b1c);
      if (uVar2 != 4) {
        FUN_20135aa4(local_2c,DAT_2080064e * uVar2 + (uint)DAT_2080062a & 0xffff,DAT_20800628,
                     DAT_2080063c,DAT_2080063e,0);
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 5);
  fb_fill_rect(local_2c,0x3186,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e);
  FUN_20135dd4(local_2c,"BACK",DAT_208005ea,DAT_208005e8,DAT_208005ec,&DAT_20800fb4);
  if (bVar3 != 4 && bVar3 != 1) {
    FUN_20136290(local_2c,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e,1,0x821);
    return;
  }
  FUN_20136398(local_2c,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e,3);
  return;
}


// ===== FUN_201283fc @ 201283fc (360 bytes)

void FUN_201283fc(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = fb_get_layer_addr(DAT_208085bc);
  param_2 = param_1 * 0x2d + param_2;
  cVar1 = *(char *)(param_2 + 0x119);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_40,param_2 + 0x11c,0x15);
  FUN_20135ec0(local_28,&local_40,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
               DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(local_28,0x821,(uint)DAT_2080064e * param_1 + (uint)DAT_20800626 & 0xffff,
               DAT_20800624,*DAT_2080229c,DAT_2080229c[1]);
  gui_draw_runs(local_28,(uint)DAT_2080064e * param_1 + (uint)DAT_20800626 & 0xffff,DAT_20800624,
                DAT_2080229c);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_40,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  FUN_201354ec(&local_40);
  if (cVar1 < '\0') {
    puVar2 = &DAT_20800e34;
  }
  else {
    puVar2 = &DAT_20800b1c;
  }
  FUN_20135ff0(local_28,&local_40,(uint)DAT_2080064e * param_1 + (uint)DAT_20800632 & 0xffff,
               DAT_20800630,0xf,puVar2);
  return;
}


// ===== FUN_20128564 @ 20128564 (416 bytes)

void FUN_20128564(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  param_2 = param_1 * 0x2d + param_2;
  cVar1 = *(char *)(param_2 + 0x119);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x11c,0x15);
  FUN_20135ec0(uVar2,&local_38,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
               DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x821,(uint)DAT_2080064e * param_1 + 0x2f & 0xffff,0x120,*DAT_208022b4,
               DAT_208022b4[1]);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x2f & 0xffff,0x120,DAT_208022b4);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x129,DAT_208022b8);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x291,DAT_208022bc);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  FUN_201354ec(&local_38);
  if (cVar1 < '\0') {
    puVar3 = &DAT_2080143c;
  }
  else {
    puVar3 = &DAT_208012b8;
  }
  FUN_20135ff0(uVar2,&local_38,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x1e9,0x18,puVar3);
  return;
}


// ===== FUN_20128704 @ 20128704 (348 bytes)

void FUN_20128704(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  param_2 = param_2 + param_1 * 0x2d;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x11c,0x15);
  FUN_20135ec0(uVar1,&local_38,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
               DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar1,0x821,(uint)DAT_2080064e * param_1 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
               *DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar1,(uint)DAT_2080064e * param_1 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
                DAT_20802290);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  FUN_201354ec(&local_38);
  gui_draw_runs(uVar1,(uint)DAT_2080064e * param_1 + (uint)DAT_2080064a + (uint)DAT_20800642 &
                      0xffff,DAT_20800640 + DAT_20800648,&DAT_2016dc18);
  return;
}


// ===== FUN_20128860 @ 20128860 (1104 bytes)

void FUN_20128860(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  uVar8 = 0xff;
  uVar10 = 0xff;
  uVar2 = (uint)*(byte *)(param_1 + 0x9a);
  uVar3 = (uint)*(byte *)(param_1 + 0x99);
  bVar7 = *(byte *)(param_1 + 0x9b) & 0xf;
  if ((bVar7 == 2 || bVar7 == 3) || (5 < uVar2)) {
    uVar8 = *(byte *)(param_1 + 0x9c) & 0xf;
  }
  bVar9 = *(byte *)(param_2 + 0x9b) & 0xf;
  if ((bVar9 == 2 || bVar9 == 3) || (5 < uVar2)) {
    uVar10 = *(byte *)(param_2 + 0x9c) & 0xf;
  }
  uVar6 = 0;
  do {
    if (((param_3 != 0) || (uVar8 != uVar10 || bVar7 != bVar9)) ||
       (iVar4 = FUN_2015507c(uVar6 * 0x2d + param_1 + 0x119,uVar6 * 0x2d + param_2 + 0x119,0x2d),
       iVar4 != 0)) {
      fb_fill_rect(uVar1,0x4a69,DAT_2080064e * uVar6 + (uint)DAT_2080060e & 0xffff,DAT_2080060c,
                   DAT_20800610,DAT_2080062e + DAT_20800612,uVar3);
      iVar4 = uVar6 * 0x2d + param_1;
      uVar5 = (*(byte *)(iVar4 + 0x119) & 0x7f) >> 6;
      if ((*(byte *)(iVar4 + 0x11a) & 0x1f) != 0) {
        iVar4 = FUN_2015507c(iVar4 + 0x131,"DONE",4);
        if (iVar4 == 0) {
          FUN_20128704(uVar6,param_1);
          if (bVar7 == 2 && uVar6 == uVar8) {
            FUN_20136398(uVar1,DAT_2080064e * uVar6 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
                         DAT_20800644,DAT_20800646,3);
          }
        }
        else if ((bVar7 == 3) && (uVar5 != 0)) {
          FUN_20128564(uVar6,param_1);
        }
        else {
          FUN_201283fc(uVar6,param_1);
          if (bVar7 == 2 && uVar6 == uVar8) {
            FUN_20136398(uVar1,DAT_2080064e * uVar6 + (uint)DAT_2080060e & 0xffff,DAT_2080060c,
                         DAT_20800610,DAT_20800612,3);
          }
        }
      }
      if (uVar6 != 4) {
        FUN_20135aa4(uVar1,DAT_2080064e * uVar6 + (uint)DAT_2080062a & 0xffff,DAT_20800628,
                     DAT_2080062c,(undefined1)DAT_2080062e,0x821);
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 5);
  if (((param_3 != 0) || (*(char *)(param_1 + 0x99) != DAT_208f0bc3)) ||
     (*(char *)(param_1 + 0x9a) != DAT_208f0bc4)) {
    FUN_201363c0(uVar1,DAT_20800602,DAT_20800600,DAT_20800604,DAT_20800606,uVar2,uVar3,5,0x821);
    fb_fill_rect(uVar1,0x821,DAT_208005f2,DAT_208005f0,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005f2,DAT_208005f0,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005f6,DAT_208005f4,&DAT_2016dc58);
    fb_fill_rect(uVar1,0x821,DAT_208005fa,DAT_208005f8,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005fa,DAT_208005f8,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005fe,DAT_208005fc,&DAT_2016dc68);
    if (param_3 != 0) goto LAB_20128bf0;
  }
  if (bVar7 == bVar9) {
    return;
  }
LAB_20128bf0:
  if (*(char *)(param_1 + 0x98) == '\0') {
    fb_fill_rect(uVar1,0x3186,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a);
    FUN_20135dd4(uVar1,"BACK",DAT_208005ea,DAT_208005e8,DAT_208005ec,&DAT_20800fb4);
    if (bVar7 == 4 || bVar7 == 1) {
      FUN_20136398(uVar1,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a,3);
      return;
    }
    FUN_20136290(uVar1,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a,1,0x821);
  }
  return;
}


// ===== FUN_20128d00 @ 20128d00 (404 bytes)

void FUN_20128d00(int param_1,int param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  bVar2 = *(byte *)(param_1 + 0x9b);
  uVar1 = (uint)(*(byte *)(param_1 + 0x9c) >> 4);
  bVar6 = (bVar2 & 0xf) == (*(byte *)(param_2 + 0x9b) & 0xf);
  bVar7 = param_3 == 0 && bVar6;
  if (param_3 == 0 && bVar6) {
    bVar7 = uVar1 == *(byte *)(param_2 + 0x9c) >> 4;
  }
  if ((!bVar7) || (iVar3 = FUN_2015507c(param_1 + 0xb1,param_2 + 0xb1,0x68), iVar3 != 0)) {
    uVar5 = 0;
    do {
      psVar4 = &DAT_2016dc78 + uVar5 * 5;
      fb_fill_rect(local_2c,0x821,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5],
                   (&DAT_2016dc7e)[uVar5 * 5]);
      if (uVar5 == uVar1) {
        if ((bVar2 & 0xf) == 0) {
          gui_draw_runs(local_2c,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,&DAT_2016dc28);
          FUN_20135864(local_2c,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5],
                       (&DAT_2016dc7e)[uVar5 * 5],0x821,0x4a69);
        }
        else {
          fb_fill_rect(local_2c,0x4a69,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5]
                       ,(&DAT_2016dc7e)[uVar5 * 5]);
        }
      }
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_3c,uVar5 * 0xd + param_1 + 0xb1,0xd);
      FUN_20135ec0(local_2c,&local_3c,(&DAT_2016dc7a)[uVar5 * 5] + DAT_208005e6,
                   *psVar4 + DAT_208005e4,0xf,&DAT_20800b1c);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 7);
  }
  return;
}


// ===== FUN_20128e94 @ 20128e94 (184 bytes)

void FUN_20128e94(void)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_fill_rect(uVar1,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar1,0x3186,DAT_208005c6,DAT_208005c4,DAT_208005cc,DAT_208005ce);
  fb_fill_rect(uVar1,0x821,DAT_208005d2,DAT_208005d0,DAT_208005d4,DAT_208005d6);
  fb_fill_rect(uVar1,0x4a69,DAT_208005da,DAT_208005d8,DAT_208005dc,DAT_208005de);
  return;
}


// ===== FUN_20128f4c @ 20128f4c (264 bytes)

void FUN_20128f4c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if (param_3 == 0) {
    iVar2 = FUN_2015507c(param_1 + 0x9d,param_2 + 0x9d,0x14);
    if (iVar2 == 0) goto LAB_20129000;
  }
  else {
    FUN_20128e94();
  }
  gui_draw_runs(uVar1,DAT_208005c6,DAT_208005c4,&DAT_2016dc08);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  memcpy(&local_30,param_1 + 0x9d,0x14);
  FUN_20135ff0(uVar1,&local_30,DAT_208005ca,DAT_208005c8,0xf,&DAT_20800b1c);
LAB_20129000:
  FUN_20128d00(param_1,param_2,param_3);
  if (*(char *)(param_1 + 0x98) != '\0') {
    if (*(char *)(param_1 + 0x98) == '\x01') {
      FUN_201281c0(param_1,param_2,param_3);
    }
    return;
  }
  FUN_20128860(param_1,param_2,param_3);
  return;
}


// ===== FUN_20129054 @ 20129054 (184 bytes)

void FUN_20129054(int param_1,int param_2,int param_3)

{
  undefined2 *local_30;
  undefined2 *local_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  if (param_3 != 0) {
    local_14 = 0;
    local_12 = 800;
    local_18 = 0;
    local_24 = 0;
    local_16 = 0x1e0;
    local_30 = &local_18;
    local_22 = 0;
    local_21 = 0xff;
    local_2c = &local_24;
    local_20 = 0;
    local_28 = 0;
    FUN_20133658(0,5,1,&local_30);
    FUN_20133658(1,5,1,&local_30);
  }
  if (*(byte *)(param_1 + 0x98) != *(byte *)(param_2 + 0x98)) {
    param_3 = 1;
  }
  if (*(byte *)(param_1 + 0x98) < 2) {
    FUN_20128f4c(param_1,param_2,param_3);
  }
  return;
}


// ===== FUN_2012910c @ 2012910c (676 bytes)

void FUN_2012910c(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  char local_28;
  byte local_24;
  
  uVar2 = DAT_208f0b57;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  bVar1 = *(byte *)(param_1 + 0x24) >> 4;
  cVar5 = (*(byte *)(param_1 + 0x24) & 0xf) + 1;
  sprintf(&local_48,"MSG_CH%d",cVar5);
  if (bVar1 == 1) {
    if (DAT_2080048f == '\0') {
      if (DAT_20800490 == '\x01') {
        if (DAT_2080049d == cVar5) {
          return;
        }
        FUN_2010579c();
      }
      DAT_2080049d = cVar5;
      iVar3 = FUN_20105550(&DAT_208f1234,0xff,2);
      if (0 < iVar3) {
        local_28 = '\0';
        local_24 = 0;
        do {
          iVar3 = FUN_2015507c(&DAT_208f1234 + (uint)local_24 * 0x34,&local_48,7);
          if (iVar3 == 0) {
            if (*(int *)(&DAT_208f1264 + (uint)local_24 * 0x34) != 0) {
              FUN_20124744(0xfffffff7);
              return;
            }
            local_28 = '\x01';
            break;
          }
          local_24 = local_24 + 1;
        } while (local_24 < 5);
        if (local_28 != '\0') {
          if (DAT_20800490 == '\0') {
            FUN_201248a4(1);
          }
          FUN_20105a54(&local_48,2);
          DAT_20800490 = 1;
          return;
        }
        iVar3 = -4;
      }
LAB_201292c4:
      FUN_20124744(iVar3);
      return;
    }
LAB_20129190:
    iVar3 = FUN_20105790();
    if (iVar3 != 0) goto LAB_20129330;
  }
  else {
    if (bVar1 == 2) {
      if (DAT_2080048f == '\0') {
        iVar3 = FUN_20103bc0();
        if (iVar3 == 0) {
          FUN_201248a4(2,1);
          uVar4 = FUN_20135498(&DAT_208f0ba3);
          FUN_20154a30(&local_58,0x10,&DAT_201293f0,uVar4);
          FUN_201058dc(&local_48,&local_58,uVar2,2);
          DAT_2080048f = 1;
          return;
        }
        iVar3 = -3;
        goto LAB_201292c4;
      }
      goto LAB_20129190;
    }
    if (bVar1 != 0) goto LAB_20129190;
  }
  if ((DAT_20800490 != '\x01') && (DAT_2080048f != '\x01')) {
LAB_20129330:
    if (bVar1 != 0) {
      return;
    }
    iVar3 = FUN_201058c0();
    if (iVar3 != 0) {
      FUN_201058cc();
    }
    return;
  }
  iVar3 = FUN_201058c0();
  if (iVar3 == 0) {
    if (DAT_20800490 == '\x01') {
      FUN_2010579c();
      DAT_20800490 = '\0';
    }
    if (DAT_2080048f != '\x01') goto LAB_20129398;
    FUN_20105a20();
  }
  else {
    FUN_201058c0();
    FUN_20124744();
    DAT_208007d8 = 0;
    FUN_201058cc();
    DAT_20800490 = '\0';
  }
  DAT_2080048f = '\0';
LAB_20129398:
  FUN_201248a4(0);
  DAT_2080048e = 0;
  return;
}


// ===== FUN_201293f8 @ 201293f8 (2000 bytes)

void FUN_201293f8(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  short *psVar6;
  byte bVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  uint local_28;
  
  fb_get_layer_addr(DAT_208085b8);
  local_30 = fb_get_layer_addr(DAT_208085bc);
  iVar3 = FUN_20105790();
  if ((((iVar3 == 0) && (iVar3 = FUN_201058c0(), iVar3 == 0)) &&
      ((bVar4 = *(byte *)(param_1 + 0x2d), bVar4 < 2 ||
       ((bVar4 == 4 || bVar4 == 5 || (bVar4 == 6 || bVar4 == 7)))))) &&
     (iVar3 = FUN_20103ba0(), iVar3 == 0)) {
    FUN_20124744(0xffffffff);
    return;
  }
  if (DAT_2080048e != '\x01') {
    DAT_2080048e = '\x02';
  }
  if (param_2 != 0) {
    FUN_2013573c(local_30,0x821,0x6d,0x62,0x25c,0xd2,2);
    fb_fill_rect(local_30,0x4a69,0x6f,100,600,0xce);
    fb_fill_rect(local_30,0x3186,0x74,0x69,0x24d,0x17);
    gui_draw_runs(local_30,DAT_2080078e,DAT_2080078c,&DAT_2016ebbc);
  }
  fb_fill_rect(local_30,0x4a69,DAT_20800792,DAT_20800790,0x7a,0x12);
  fb_fill_rect(local_30,0x4a69,DAT_20800796,DAT_20800794,0x44,0x18);
  if ((*(byte *)(param_1 + 0xb1) & 0xc) != 0) {
    if ((*(byte *)(param_1 + 0xb1) & 8) == 0) {
      bVar4 = *(byte *)(param_1 + 0xb7);
      gui_draw_runs(local_30,DAT_20800792,DAT_20800790,&DAT_2016ebac);
    }
    else {
      bVar4 = *(byte *)(param_1 + 0xb8);
      gui_draw_runs(local_30,DAT_20800792,DAT_20800790,&DAT_2016ebcc);
    }
    local_4c = 0;
    if (100 < bVar4) {
      bVar4 = 100;
    }
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    sprintf(&local_4c,&DAT_20129988,bVar4);
    local_4c = CONCAT13(0x25,(undefined3)local_4c);
    FUN_20135dd4(local_30,&local_4c,DAT_20800796,DAT_20800794,0x11,&DAT_20803030);
  }
  bVar4 = *(byte *)(param_1 + 0xb1);
  uVar5 = 0;
  bVar7 = bVar4 & 3;
  local_28 = (uint)*(byte *)(param_1 + 0xb4);
  do {
    puVar11 = (undefined *)0x0;
    puVar10 = (undefined *)0x0;
    puVar8 = (undefined *)0x0;
    if (uVar5 + 1 == local_28) {
      if ((bVar4 & 3) == 0) {
        psVar6 = (short *)0x20800798;
        puVar9 = *(undefined **)(&UNK_2016ecbc + uVar5 * 8);
      }
      else {
        psVar6 = &DAT_2080079c;
        puVar8 = &DAT_208031c0;
        puVar10 = &DAT_2016eb8c;
        puVar9 = (undefined *)(&DAT_2016ece4)[uVar5 * 2];
        puVar11 = &DAT_2016eb6c;
      }
      gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5]);
    }
    else {
      if ((bVar4 & 3) == 0) {
        psVar6 = (short *)0x20800798;
        puVar9 = *(undefined **)(&UNK_2016ecb8 + uVar5 * 8);
      }
      else {
        psVar6 = &DAT_2080079c;
        puVar8 = &DAT_208031c0;
        puVar9 = (&PTR_DAT_2016ece0)[uVar5 * 2];
        puVar11 = &DAT_2016eb5c;
        puVar10 = &UNK_2016eb9c;
      }
      fb_fill_rect(local_30,0x821,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5],
                   *(undefined2 *)(&UNK_2016ebe0 + uVar5 * 10),
                   *(undefined2 *)(&UNK_2016ebe2 + uVar5 * 10));
      gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5],&DAT_2016eb2c);
    }
    gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5] + psVar6[1],
                  (&DAT_2016ebdc)[uVar5 * 5] + *psVar6,puVar9);
    if (bVar7 == 1) {
      uVar1 = 1 << (uVar5 & 0xff);
      if ((*(byte *)(param_1 + 0xb2) & uVar1) != 0) {
        gui_draw_runs(local_30,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007a2,
                      (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a0,puVar11);
      }
      if ((*(byte *)(param_1 + 0xb3) & uVar1) != 0) {
        gui_draw_runs(local_30,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007a6,
                      (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a4,puVar10);
      }
    }
    if (puVar8 != (undefined *)0x0) {
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      if ((bVar7 == 1) && (((uint)*(byte *)(param_1 + 0xb6) & 1 << (uVar5 & 0xff)) != 0)) {
        local_4c = 0x20;
        FUN_2015525c((int)&local_4c + 1,6,0x7f);
        local_48 = CONCAT13(0x20,(undefined3)local_48);
      }
      else {
        FUN_2016372c(&local_4c,param_1 + uVar5 * 8 + 0xc0);
      }
      FUN_20135dd4(local_30,&local_4c,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007aa,
                   (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a8,0xd,puVar8);
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 5);
  iVar3 = 6;
  do {
    if ((bVar4 & 3) == 0) {
      if (iVar3 + 1U == local_28) {
        puVar11 = (&PTR_DAT_2016ecdc)[iVar3 * 2];
        gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],&DAT_2016eb3c);
      }
      else {
        local_2c = &DAT_2016eb2c;
        puVar11 = (&PTR_DAT_2016ecd8)[iVar3 * 2];
        fb_fill_rect(local_30,0x821,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],
                     *(undefined2 *)(&UNK_2016ebe0 + iVar3 * 10),
                     *(undefined2 *)(&UNK_2016ebe2 + iVar3 * 10));
        gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],local_2c);
      }
      gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5] + DAT_208007ae,
                    (&DAT_2016ebdc)[iVar3 * 5] + DAT_208007ac,puVar11);
    }
    else if (bVar7 == 1 && iVar3 == 6) {
      fb_fill_rect(local_30,0x821,0xfc,0xe1,0x6e,0x3c);
      gui_draw_runs(local_30,0xfc,0xe1,&DAT_2016eb2c);
      gui_draw_runs(local_30,DAT_208007b2 + 0xfc,DAT_208007b0 + 0xe1,&DAT_2016eb4c);
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      uVar2 = FUN_20135470(param_1 + 0xba);
      if (9999 < uVar2) {
        uVar2 = 9999;
      }
      sprintf(&local_4c,&DAT_20129c38,uVar2);
      FUN_20135dd4(local_30,&local_4c,DAT_208007b6 + 0xfc,DAT_208007b4 + 0xe1,0xd,&DAT_208031c0);
    }
    else {
      fb_fill_rect(local_30,0x4a69,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],
                   *(undefined2 *)(&UNK_2016ebe0 + iVar3 * 10),
                   *(undefined2 *)(&UNK_2016ebe2 + iVar3 * 10));
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  if (local_28 == 6) {
    gui_draw_runs(local_30,0xfc,0x69,&DAT_2016eb3c);
    gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x69,&DAT_2016eb7c);
  }
  else {
    fb_fill_rect(local_30,0x821,0xfc,0x69,0x6e,0x3c);
    gui_draw_runs(local_30,0xfc,0x69,&DAT_2016eb2c);
    gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x69,&DAT_2016eb7c);
  }
  fb_fill_rect(local_30,0x821,0xfc,0x249,0x6e,0x3c);
  gui_draw_runs(local_30,0xfc,0x249,&DAT_2016eb2c);
  gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x249,&DAT_2016eb1c);
  FUN_2012910c(param_1);
  return;
}


// ===== FUN_20129c44 @ 20129c44 (172 bytes)

void FUN_20129c44(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r4;
  
  iVar2 = -9999;
  iVar4 = 4;
  if ((-10000 < param_1) && (iVar2 = param_1, 9999 < param_1)) {
    iVar2 = 9999;
  }
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = -iVar2;
  }
  iVar3 = (int)(short)iVar3;
  if (0 < iVar3) {
    unaff_r4 = 0x66666667;
  }
  if (iVar3 == 0) {
    iVar4 = 3;
    *(undefined1 *)(param_2 + 4) = 0x30;
  }
  else {
    for (; 0 < iVar3; iVar3 = (int)(short)iVar3 / 10) {
      *(char *)(param_2 + iVar4) =
           (char)iVar3 +
           ((char)(int)((longlong)unaff_r4 * (longlong)iVar3 >> 0x22) -
           (char)((longlong)unaff_r4 * (longlong)iVar3 >> 0x3f)) * -10 + '0';
      iVar4 = iVar4 + -1;
    }
  }
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = 0x2d;
  }
  uVar1 = (undefined1)iVar3;
  if (0 < iVar2) {
    uVar1 = 0x2b;
  }
  if (iVar2 != 0) {
    *(undefined1 *)(param_2 + iVar4) = uVar1;
  }
  return;
}


// ===== FUN_20129cf0 @ 20129cf0 (348 bytes)

void FUN_20129cf0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 auStack_2c [5];
  undefined1 local_27;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  uVar5 = (uint)*(byte *)(param_1 + 0x42);
  uVar6 = (uint)*(byte *)(param_2 + 0x42);
  iVar2 = FUN_20135470(param_1 + 0x43);
  iVar3 = FUN_20135470(param_2 + 0x43);
  bVar7 = param_3 == 0 && uVar5 == uVar6;
  bVar4 = *(byte *)(param_1 + 0x49) & 0xf;
  if (param_3 == 0 && uVar5 == uVar6) {
    bVar7 = bVar4 == (*(byte *)(param_2 + 0x49) & 0xf);
  }
  if (bVar7) {
    if (bVar4 != 9) {
      return;
    }
  }
  else {
    fb_copy_rect(uVar1,DAT_20800522,DAT_2080051c,0x121,0x36);
    if (bVar4 != 9) {
      return;
    }
    gui_draw_runs(uVar1,DAT_2080051e,DAT_2080051c,(&PTR_DAT_20800890)[uVar5 & 3]);
  }
  if ((param_3 != 0 || uVar5 != uVar6) || (iVar2 != iVar3)) {
    fb_copy_rect(uVar1,DAT_20800522,DAT_20800520,DAT_20800528,0x26);
    FUN_201637f0(auStack_2c,0x20);
    local_27 = 0;
    FUN_20129c44(iVar2,auStack_2c);
    FUN_20135dd4(uVar1,auStack_2c,DAT_20800522,DAT_20800520,DAT_20800524,&DAT_20802394);
    gui_draw_runs(uVar1,DAT_2080052e,DAT_2080052c,&DAT_2016d64c);
  }
  return;
}

