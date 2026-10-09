// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201587d0 @ 201587d0 (44 bytes)

void FUN_201587d0(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// ===== FUN_201587fc @ 201587fc (60 bytes)

void FUN_201587fc(undefined1 *param_1)

{
  FUN_20163d44(param_1 + 0x10,0);
  FUN_20163f14(param_1 + 0x9c,0);
  FUN_20163ae0(param_1 + 0x38e8,0);
  *param_1 = 0;
  return;
}


// ===== FUN_20158838 @ 20158838 (16 bytes)

void FUN_20158838(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined *puVar3;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  cVar1 = *param_1;
  puVar3 = (undefined *)0x3ff00000;
  uVar2 = 0;
  if (cVar1 == '\x01') {
    uVar2 = 0x9999999a;
    puVar3 = &DAT_3fe99999;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 0x33333333;
    puVar3 = &DAT_3fe33333;
  }
  else if (cVar1 == '\x03') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fd99999;
  }
  else if (cVar1 == '\x04') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fc99999;
  }
  *param_1 = cVar1;
  FUN_20163ca4(param_1 + 0x10,cVar1,uVar2,puVar3,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar2,puVar3,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar2,puVar3,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158848 @ 20158848 (180 bytes)

void FUN_20158848(undefined1 *param_1,int param_2)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)0x3ff00000;
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = 0x9999999a;
    puVar2 = &DAT_3fe99999;
  }
  else if (param_2 == 2) {
    uVar1 = 0x33333333;
    puVar2 = &DAT_3fe33333;
  }
  else if (param_2 == 3) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fd99999;
  }
  else if (param_2 == 4) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fc99999;
  }
  *param_1 = (char)param_2;
  FUN_20163ca4(param_1 + 0x10,param_2,uVar1,puVar2,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar1,puVar2,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar1,puVar2,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158914 @ 20158914 (12 bytes)

void FUN_20158914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


// ===== FUN_20158920 @ 20158920 (16 bytes)

void FUN_20158920(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== FUN_20158930 @ 20158930 (180 bytes)

void FUN_20158930(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_114;
  undefined1 auStack_110 [260];
  
  memclr(auStack_110,0x100);
  FUN_20158920(param_1);
  while( true ) {
    while (iVar1 = itron_twai_flg(*(undefined4 *)(param_1 + 0x24),0xc001,5,&local_114,0xffffffff),
          iVar1 == -0x32) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
    if (iVar1 != 0) break;
    if (((local_114 & 0xc000) == 0) && ((local_114 & 1) != 0)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      uVar2 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                        (*(int **)(param_1 + 0x10),auStack_110,0x100);
      FUN_20131154(auStack_110,uVar2);
    }
  }
  return;
}


// ===== FUN_201589e4 @ 201589e4 (12 bytes)

void FUN_201589e4(undefined4 *param_1)

{
  *param_1 = &DAT_20427fb8;
  return;
}


// ===== FUN_201589f4 @ 201589f4 (12 bytes)

undefined4 FUN_201589f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x11a0),1);
  iVar1 = FUN_201643f0(param_1 + 0x111c);
  uVar2 = *(undefined4 *)(param_1 + 0x111c + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== FUN_20158a00 @ 20158a00 (96 bytes)

void FUN_20158a00(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  FUN_20164460();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    FUN_20158618(iVar3 + 0x1c);
    FUN_201644a0(param_1 + 0x111c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x11a4) = uVar1;
  return;
}


// ===== FUN_20158a60 @ 20158a60 (16 bytes)

void FUN_20158a60(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== FUN_20158a70 @ 20158a70 (108 bytes)

void FUN_20158a70(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  FUN_20158a60();
  do {
    FUN_20152434(*(undefined4 *)(param_1 + 0x11a4),local_8,0xffffffff);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
  } while( true );
}


// ===== FUN_20158adc @ 20158adc (16 bytes)

void FUN_20158adc(int param_1,undefined4 param_2)

{
  FUN_20162d3c(param_1,*(undefined4 *)(param_1 + 0x11a4),param_2);
  return;
}


// ===== FUN_20158aec @ 20158aec (32 bytes)

int FUN_20158aec(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fc4;
  iVar1 = FUN_20162c18(param_1 + 0x447);
  return iVar1 + -0x111c;
}


// ===== FUN_20158b10 @ 20158b10 (240 bytes)

void FUN_20158b10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = itron_acre_tsk(0,&DAT_20165938,param_3,param_4,param_4);
  if (((0 < iVar1) && (iVar2 = itron_acre_tsk(0,&DAT_2016591c), 0 < iVar2)) &&
     (iVar3 = itron_acre_tsk(0,&DAT_20165900), 0 < iVar3)) {
    iVar4 = param_1 + 0x8218;
    FUN_2015863c(iVar4,*(undefined4 *)(param_1 + 0x10));
    FUN_20160048(param_1 + 0x58,iVar4);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x14);
    FUN_2015eb74(param_1 + 0x18,*(undefined4 *)(param_1 + 0x10),iVar4,param_1 + 0x58);
    iVar1 = itron_sta_tsk(iVar1,iVar4);
    if (((iVar1 == 0) && (iVar1 = itron_sta_tsk(iVar2,param_1 + 0x58), iVar1 == 0)) &&
       (iVar1 = itron_sta_tsk(iVar3,param_1 + 0x18), iVar1 == 0)) {
      (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x54600,8,0);
      FUN_201525f8(0xffffffff);
      return;
    }
  }
  return;
}


// ===== FUN_20158c10 @ 20158c10 (48 bytes)

int FUN_20158c10(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fd0;
  iVar1 = FUN_2015efe4(param_1 + 6);
  iVar1 = FUN_20160288(iVar1 + 0x40);
  iVar1 = FUN_201587ac(iVar1 + 0x81c0);
  return iVar1 + -0x8218;
}


// ===== FUN_20158c44 @ 20158c44 (548 bytes)

void FUN_20158c44(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20;
  
  local_20 = 1;
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x9600,8,0);
  if (DAT_208dbb44 == 0xbbbb) {
    FUN_201525f8(0xffffffff);
  }
  if (DAT_2045001d == '\x01') {
    DAT_2045001d = '\x02';
    FUN_201525f8(0xffffffff);
  }
  iVar4 = 5;
  do {
    local_20 = 0xf0;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(*(int **)(param_1 + 0x10),&local_20,1);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))
                      (*(int **)(param_1 + 0x10),&DAT_2045001e,2,100);
    if (iVar1 != -1) {
      iVar4 = iVar4 + -1;
    }
    if (DAT_2045001d == '\x01') {
      DAT_2045001d = '\x02';
      FUN_201525f8(0xffffffff);
    }
  } while (iVar4 != 0);
  DAT_2045001c = 1;
  iVar4 = itron_acre_tsk(0,&DAT_2016583c);
  if (((0 < iVar4) && (iVar1 = itron_acre_tsk(0,&DAT_20165820), 0 < iVar1)) &&
     (iVar2 = itron_acre_tsk(0,&DAT_20165804), 0 < iVar2)) {
    iVar3 = param_1 + 0x938;
    FUN_20158a00(iVar3,*(undefined4 *)(param_1 + 0x10));
    FUN_2015ff94(param_1 + 0x50,iVar3);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x14);
    FUN_20158914(param_1 + 0x18,*(undefined4 *)(param_1 + 0x10),iVar3,param_1 + 0x50);
    iVar4 = itron_sta_tsk(iVar4,iVar3);
    if (((iVar4 == 0) && (iVar4 = itron_sta_tsk(iVar1,param_1 + 0x50), iVar4 == 0)) &&
       (iVar4 = itron_sta_tsk(iVar2,param_1 + 0x18), iVar4 == 0)) {
      itron_dly_tsk(10);
      iVar4 = FUN_201589f4(iVar3);
      *(undefined2 *)(iVar4 + 4) = 0xaa;
      *(undefined2 *)(iVar4 + 6) = 3;
      *(undefined1 *)(iVar4 + 8) = 0x1e;
      *(undefined1 *)(iVar4 + 9) = 0;
      *(undefined1 *)(iVar4 + 10) = 0x31;
      FUN_20158adc(iVar3,iVar4);
      itron_dly_tsk(10);
      iVar4 = FUN_201589f4(iVar3);
      *(undefined2 *)(iVar4 + 4) = 0xaa;
      *(undefined2 *)(iVar4 + 6) = 3;
      *(undefined1 *)(iVar4 + 8) = 0x1f;
      *(undefined1 *)(iVar4 + 9) = 0;
      *(undefined1 *)(iVar4 + 10) = 0x32;
      FUN_20158adc(iVar3,iVar4);
      FUN_201525f8(0xffffffff);
      return;
    }
  }
  return;
}


// ===== FUN_20158e8c @ 20158e8c (48 bytes)

int FUN_20158e8c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fe4;
  iVar1 = FUN_201589e4(param_1 + 6);
  iVar1 = FUN_20160018(iVar1 + 0x38);
  iVar1 = FUN_20158aec(iVar1 + 0x8e8);
  return iVar1 + -0x938;
}


// ===== FUN_20158ec0 @ 20158ec0 (96 bytes)

void FUN_20158ec0(undefined1 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
  FUN_201636cc((int)&local_18 + 1,param_2);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_18,6);
  }
  FUN_201636cc(param_1 + 0x22,param_2);
  *param_1 = (undefined1)local_18;
  return;
}


// ===== FUN_20158f28 @ 20158f28 (120 bytes)

void FUN_20158f28(undefined1 *param_1,undefined4 param_2)

{
  undefined4 local_38;
  undefined1 auStack_34 [36];
  
  memclr(auStack_34,0x1e);
  local_38 = 0xc3;
  memcpy((int)&local_38 + 1,param_2,0x21);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_38,0x22);
  }
  memcpy(param_1 + 1,param_2,0x21);
  *param_1 = (undefined1)local_38;
  return;
}


// ===== FUN_20158fa8 @ 20158fa8 (40 bytes)

uint FUN_20158fa8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xb;
  param_1 = param_1 >> 4;
  uVar2 = 3;
  do {
    if ((param_1 & 1) != 0) {
      uVar1 = uVar2 & 0xff;
    }
    uVar2 = uVar2 - 1;
    param_1 = param_1 >> 1;
  } while (-1 < (int)uVar2);
  return uVar1;
}


// ===== FUN_20158fd0 @ 20158fd0 (132 bytes)

void FUN_20158fd0(void)

{
  char local_20 [12];
  undefined2 local_14 [2];
  undefined2 local_10 [2];
  
  FUN_20159320();
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    gui_update_layers();
    local_14[0] = 0;
    local_10[0] = 0;
    FUN_20102138(local_20,1);
    FUN_20103060((int)(short)local_20._4_4_,(int)(short)local_20._8_4_,local_14,local_10);
    if (local_20[0] == '\x02' || local_20[0] == '\x04') break;
    if (local_20[0] == '\x05' || local_20[0] == '\x06') {
      return;
    }
    FUN_201525f8(0xffffffff);
  }
  return;
}


// ===== FUN_20159058 @ 20159058 (232 bytes)

void FUN_20159058(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  gui_update_layers();
  if (*(int *)(param_2 + 8) != 2) {
    uVar1 = fb_get_layer_addr(DAT_208085bc);
    fb_copy_rect(uVar1,0,0,800,0x1e0);
    FUN_20135ff0(uVar1,"FIRMWARE BOOT ERROR",100,400,0xc,&DAT_208038c0);
    do {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      FUN_201525f8(0xffffffff);
    } while( true );
  }
  bootloader_screen(param_1,param_2);
  return;
}


// ===== FUN_20159158 @ 20159158 (428 bytes)

void FUN_20159158(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_80;
  uint local_7c;
  undefined1 *local_78;
  undefined1 auStack_74 [68];
  char local_30 [16];
  
  FUN_20155310(auStack_74,"UPDATE ERROR",0x44);
  local_78 = auStack_74;
  local_7c = 0xbf;
  local_80 = 0x105;
  FUN_20126a58(1,1,1,0);
  uVar6 = **(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4) + 0x119 & 0xffff;
  uVar5 = (*(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4))[1] + 0x11d & 0xffff;
  FUN_20159320();
  do {
    FUN_201218a4();
    if (DAT_20800493 != '\0') {
      FUN_20117030();
    }
    local_80 = local_80 & 0xffff0000;
    local_7c = local_7c & 0xffff0000;
    FUN_20102138(local_30,1);
    FUN_20103060((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,&local_80,&local_7c);
    if ((local_30[0] == '\x02' || local_30[0] == '\x04') ||
       (local_30[0] == '\x05' || local_30[0] == '\x06')) {
      FUN_20113f38(local_80 & 0xffff,local_7c & 0xffff);
      uVar3 = (uint)(short)local_80;
      bVar7 = SBORROW4(uVar3,0x119);
      iVar1 = uVar3 - 0x119;
      uVar4 = 0x119;
      if (0x118 < (int)uVar3) {
        bVar7 = SBORROW4(uVar6,uVar3);
        iVar1 = uVar6 - uVar3;
        uVar4 = uVar6;
      }
      if (uVar3 != uVar4 && iVar1 < 0 == bVar7) {
        if ((0x11c < (short)local_7c) && ((int)(short)local_7c < (int)uVar5)) {
          return;
        }
      }
    }
    FUN_20102138(local_30,0);
    uVar4 = (uint)(short)local_30._4_4_;
    local_80 = CONCAT22(local_80._2_2_,(short)local_30._4_4_);
    uVar3 = (uint)(short)local_30._8_4_;
    local_7c = CONCAT22(local_7c._2_2_,(short)local_30._8_4_);
    if ((DAT_20800494 != '\0') &&
       ((local_30[0] == '\x02' || local_30[0] == '\x04' ||
        (local_30[0] == '\x05' || local_30[0] == '\x06')))) {
      bVar7 = SBORROW4(uVar4,0x119);
      iVar1 = uVar4 - 0x119;
      uVar2 = 0x119;
      if (0x118 < (int)uVar4) {
        bVar7 = SBORROW4(uVar6,uVar4);
        iVar1 = uVar6 - uVar4;
        uVar2 = uVar6;
      }
      if (uVar4 != uVar2 && iVar1 < 0 == bVar7) {
        bVar7 = SBORROW4(uVar3,0x11d);
        iVar1 = uVar3 - 0x11d;
        uVar4 = 0x11d;
        if (0x11c < (int)uVar3) {
          bVar7 = SBORROW4(uVar5,uVar3);
          iVar1 = uVar5 - uVar3;
          uVar4 = uVar5;
        }
        if (uVar3 != uVar4 && iVar1 < 0 == bVar7) {
          return;
        }
      }
    }
    gui_update_layers();
    FUN_201525f8(0xffffffff);
  } while( true );
}


// ===== FUN_20159320 @ 20159320 (28 bytes)

void FUN_20159320(void)

{
  undefined1 auStack_10 [12];
  
  FUN_20102138(auStack_10,1);
  return;
}


// ===== FUN_2015933c @ 2015933c (76 bytes)

void FUN_2015933c(void)

{
  undefined1 auStack_4c [68];
  
  FUN_20155310(auStack_4c,"INSERT FIRMWARE",0x44);
  FUN_20126a58(1,1,3,0,0xe6,0xb7,auStack_4c);
  return;
}


// ===== bootloader_screen @ 2015938c (552 bytes)

/* YAESU FT-710 BOOT LOADER V01-02 */

void bootloader_screen(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar4 = DAT_20808540;
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_2010da68();
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  fb_fill_rect(uVar1,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar1,8,400,&DAT_2016dc08);
  FUN_20135ff0(uVar1,uVar4,8,400,0xc,&DAT_20803a40);
  uVar5 = 0;
  do {
    FUN_20135ff0(uVar1,(&DAT_2080856c)[uVar5],uVar5 * 0x20 + 100,400,0xc,&DAT_208038c0);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 2);
  gui_update_layers();
  DAT_20808532 = 1;
  iVar2 = FUN_20159cb0();
  if (DAT_20800493 == '\0') {
    FUN_20107e90();
    FUN_2010dfc4();
    iVar3 = FUN_20103bb0();
    if (iVar3 == 0) {
      uVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_copy_rect(uVar4,100,0,800,0x17c);
      FUN_20135ff0(uVar4,DAT_2080856c,100,400,0xc,&DAT_208038c0);
      gui_update_layers();
    }
    iVar3 = FUN_20103bb0();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      FUN_201525f8(0xffffffff);
      iVar3 = FUN_20103bb0();
    }
    if (iVar2 != 0) {
      *param_2 = 0xbbbb;
      FUN_20159d98(param_1,"YAESU FT-710 BOOT LOADER V01-02");
      return;
    }
    param_2[2] = 1;
    FUN_20159d98(param_1,DAT_20808540);
    DAT_20800496 = 0;
    DAT_20800495 = 1;
  }
  return;
}


// ===== FUN_20159630 @ 20159630 (220 bytes)

void FUN_20159630(void)

{
  char local_28 [12];
  undefined2 local_1c [2];
  undefined2 local_18 [4];
  
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    FUN_201218a4();
    local_1c[0] = 0;
    local_18[0] = 0;
    FUN_20102138(local_28,1);
    FUN_20103060((int)(short)local_28._4_4_,(int)(short)local_28._8_4_,local_1c,local_18);
    if ((local_28[0] == '\x02' || local_28[0] == '\x04') ||
       (local_28[0] == '\x05' || local_28[0] == '\x06')) {
      FUN_20113f38(local_1c[0],local_18[0]);
      return;
    }
    FUN_20102138(local_28,0);
    if (local_28[0] == '\x02' || local_28[0] == '\x04') {
      return;
    }
    if (local_28[0] == '\x05' || local_28[0] == '\x06') break;
    if (DAT_20808533 != '\0') {
      DAT_20808533 = 0;
      return;
    }
    gui_update_layers();
    FUN_201525f8(0xffffffff);
  }
  return;
}


// ===== FUN_20159cb0 @ 20159cb0 (216 bytes)

undefined4 FUN_20159cb0(void)

{
  uint uVar1;
  char local_30 [12];
  undefined2 local_24 [2];
  undefined2 local_20 [4];
  
  uVar1 = 0;
  FUN_20159320();
  DAT_208001e4 = '\0';
  while( true ) {
    if (DAT_20800493 != '\0') {
      return 0;
    }
    if ((DAT_208dbb4c == 2) &&
       (uVar1 = FUN_20164568(&DAT_20808bcc,uVar1,(int)DAT_208001e4), 4 < uVar1)) {
      return 1;
    }
    gui_update_layers();
    local_24[0] = 0;
    local_20[0] = 0;
    FUN_20102138(local_30,1);
    FUN_20103060((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,local_24,local_20);
    if (local_30[0] == '\x02' || local_30[0] == '\x04') {
      return 0;
    }
    if (local_30[0] == '\x05' || local_30[0] == '\x06') break;
    FUN_20102138(local_30,0);
    FUN_201525f8(0xffffffff);
  }
  return 0;
}


// ===== FUN_20159d98 @ 20159d98 (956 bytes)

void FUN_20159d98(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_4b8 [3];
  char local_4b5;
  undefined1 local_4b4;
  undefined1 local_4b3;
  undefined1 auStack_278 [5];
  undefined1 local_273;
  int iStack_30;
  undefined4 local_2c;
  
  iStack_30 = param_1;
  local_2c = param_2;
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_20800494 != '\0') {
    FUN_20121830(0);
  }
  DAT_20800496 = 1;
  DAT_20800495 = 0;
LAB_20159dec:
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  FUN_201218a4();
  FUN_2015a500(param_1,0,local_2c);
  gui_update_layers();
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if (*(char *)(param_1 + 0x128) == -0x3d) {
    memclr(local_4b8,0x240);
    local_4b8[0] = 0x43;
    if ((*(char *)(param_1 + 0x12a) == '\0') && (*(char *)(param_1 + 299) != '\0')) {
      if ((*(byte *)(param_1 + 299) & 0x40) == 0) {
        local_4b4 = 0;
      }
      else {
        local_4b4 = 0x40;
      }
      local_4b5 = *(char *)(param_1 + 299);
      local_4b3 = FUN_20158fa8(*(undefined1 *)(param_1 + 299));
      FUN_2015b450(param_1,local_4b8,local_2c);
      if (DAT_20800494 == '\0') {
        uVar1 = fb_get_layer_addr(DAT_208085bc);
        FUN_20135604(uVar1,0x19a,0x1a4,0x17c,0x46);
        gui_update_layers();
      }
      iVar2 = FUN_2015a910(param_1,local_4b8,local_2c);
      if (iVar2 == 0) {
LAB_20159f50:
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      if ((DAT_20800494 == '\0') || (FUN_20121830(0), DAT_20808530 == '\0')) goto LAB_2015a100;
      local_4b3 = 10;
      FUN_2015b748(param_1,local_4b8);
      gui_update_layers();
      iVar2 = FUN_2015a17c(param_1);
      if (iVar2 == 0) goto LAB_20159f50;
      FUN_20121830(0);
      if (DAT_20808531 != '\0') goto LAB_2015a100;
      goto LAB_20159dec;
    }
    if (DAT_20800494 != '\0') {
      memclr(auStack_278,0x240);
      local_273 = 0xb;
      FUN_2015b450(param_1,auStack_278,local_2c);
      gui_update_layers();
      iVar2 = FUN_2015a910(param_1,auStack_278,local_2c);
      if (iVar2 == 0) {
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      goto LAB_2015a100;
    }
    uVar1 = fb_get_layer_addr(DAT_208085bc);
    FUN_20135604(uVar1,0x19a,0,800,0x46);
    FUN_20135ff0(uVar1,DAT_2080853c,0x1a7,400,0xc,&DAT_208038c0);
    iVar2 = FUN_20103ba0();
    while (iVar2 != 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      FUN_201525f8(0xffffffff);
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      iVar2 = FUN_20103ba0();
    }
  }
LAB_2015a040:
  if (DAT_20800494 != '\0') {
    FUN_2015933c();
    FUN_20159630();
    if (DAT_20800493 == '\0') {
      FUN_20121830(0);
    }
LAB_2015a100:
    FUN_20133870(5);
    if ((DAT_20800494 != '\0') && (DAT_20808531 == '\0')) {
      DAT_20800494 = 0;
      return;
    }
    FUN_2015b134(param_1,0,local_2c);
    do {
      gui_update_layers();
      FUN_201525f8(0xffffffff);
    } while( true );
  }
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_20135604(uVar1,0x1a,0,800,0x1c6);
  FUN_20135ff0(uVar1,DAT_2080856c,100,400,0xc,&DAT_208038c0);
  FUN_20133870(5);
  gui_update_layers();
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar2 = FUN_20103bb0();
  while (iVar2 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    FUN_201525f8(0xffffffff);
    iVar2 = FUN_20103bb0();
  }
  goto LAB_20159dec;
}


// ===== FUN_2015a17c @ 2015a17c (832 bytes)

undefined4 FUN_2015a17c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  short local_2a0 [2];
  short local_29c [2];
  undefined1 auStack_298 [5];
  undefined1 local_293;
  int local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char local_34 [12];
  int local_28;
  
  local_28 = param_1;
  memclr(auStack_298,0x240);
  sVar5 = DAT_20808536;
  iVar4 = 10;
  FUN_20159320();
  local_58 = 0xfa;
  local_54 = *DAT_20802294 + 0xfa & 0xffff;
  uVar7 = *DAT_20802294 + 0x1a4 & 0xffff;
  uVar8 = DAT_20802294[1] + 0x19a & 0xffff;
  uVar6 = DAT_20802294[1] + 0x19a & 0xffff;
  do {
    iVar1 = FUN_20103bb0();
    if (iVar1 == 0) {
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_58 = 0x447;
      FUN_20158f28(local_28 + 0x128,&local_58);
      return 0;
    }
    FUN_201218a4();
    if (DAT_20800493 != '\0') {
      return 0;
    }
    gui_update_layers();
    local_29c[0] = 0;
    local_2a0[0] = 0;
    FUN_20102138(local_34,1);
    FUN_20103060((int)(short)local_34._4_4_,(int)(short)local_34._8_4_,local_29c,local_2a0);
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      FUN_20113f38(local_29c[0],local_2a0[0]);
      uVar2 = (uint)local_29c[0];
      if ((local_58 <= (int)uVar2) && ((int)uVar2 < (int)local_54)) {
        iVar3 = (int)local_2a0[0];
        bVar9 = SBORROW4(0x19a,iVar3);
        iVar1 = 0x19a - iVar3;
        if (0x199 < iVar3) {
          bVar9 = SBORROW4(iVar3,uVar8);
          iVar1 = iVar3 - uVar8;
        }
        if (iVar1 < 0 != bVar9) {
          DAT_20808531 = 1;
          return 1;
        }
      }
      bVar10 = SBORROW4(uVar2,0x1a4);
      iVar1 = uVar2 - 0x1a4;
      bVar9 = uVar2 == 0x1a4;
      if (0x1a3 < (int)uVar2) {
        bVar10 = SBORROW4(uVar7,uVar2);
        iVar1 = uVar7 - uVar2;
        bVar9 = uVar7 == uVar2;
      }
      if (!bVar9 && iVar1 < 0 == bVar10) {
        iVar3 = (int)local_2a0[0];
        bVar9 = SBORROW4(0x19a,iVar3);
        iVar1 = 0x19a - iVar3;
        if (0x199 < iVar3) {
          bVar9 = SBORROW4(iVar3,uVar6);
          iVar1 = iVar3 - uVar6;
        }
        if (iVar1 < 0 != bVar9) {
          DAT_20808531 = 0;
          return 1;
        }
      }
    }
    FUN_20102138(local_34,0);
    local_29c[0] = (short)local_34._4_4_;
    uVar2 = (uint)local_29c[0];
    local_2a0[0] = (short)local_34._8_4_;
    iVar1 = (int)local_2a0[0];
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      if ((local_58 <= (int)uVar2) && ((int)uVar2 < (int)local_54)) {
        bVar9 = SBORROW4(0x19a,iVar1);
        iVar3 = 0x19a - iVar1;
        if (0x199 < iVar1) {
          bVar9 = SBORROW4(iVar1,uVar8);
          iVar3 = iVar1 - uVar8;
        }
        if (iVar3 < 0 != bVar9) {
          DAT_20808531 = 1;
          return 1;
        }
      }
      bVar10 = SBORROW4(uVar2,0x1a4);
      iVar3 = uVar2 - 0x1a4;
      bVar9 = uVar2 == 0x1a4;
      if (0x1a3 < (int)uVar2) {
        bVar10 = SBORROW4(uVar7,uVar2);
        iVar3 = uVar7 - uVar2;
        bVar9 = uVar7 == uVar2;
      }
      if (((!bVar9 && iVar3 < 0 == bVar10) && (0x199 < iVar1)) && (iVar1 < (int)uVar6)) {
        DAT_20808531 = 0;
        return 1;
      }
    }
    FUN_201023bc(local_34);
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      DAT_20808531 = 0;
      return 1;
    }
    if ((sVar5 != DAT_20808536) || (DAT_20808534 != 0)) {
      if ((sVar5 < DAT_20808536) || (DAT_20808534 < 0)) {
        if (iVar4 != 0xb) {
          iVar4 = 0xb;
          local_293 = 0xb;
          FUN_2015b748(local_28,auStack_298);
        }
      }
      else if (iVar4 != 10) {
        iVar4 = 10;
        local_293 = 10;
        FUN_2015b748(local_28,auStack_298);
      }
      DAT_20808534 = 0;
      sVar5 = DAT_20808536;
    }
    if (DAT_20808533 != '\0') {
      DAT_20808531 = iVar4 == 10;
      DAT_20808533 = 0;
      return 1;
    }
    FUN_201525f8(0xffffffff);
  } while( true );
}


// ===== FUN_2015a4c8 @ 2015a4c8 (52 bytes)

void FUN_2015a4c8(void)

{
  FUN_2010231c();
  FUN_2010239c();
  if (DAT_20800494 != '\0') {
    FUN_20120e9c(0,0xffff);
  }
  FUN_20159320();
  return;
}


// ===== FUN_2015a500 @ 2015a500 (964 bytes)

void FUN_2015a500(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  uint uVar4;
  undefined4 local_78;
  undefined *local_74;
  undefined4 local_70;
  uint local_6c;
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
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_20107e90();
  FUN_2010dfc4();
  local_78 = 0x1e0;
  fb_copy_rect(uVar1,0,0,800);
  local_78 = 0x31a;
  local_74 = (undefined *)0x18;
  fb_fill_rect(uVar1,0x3186,2);
  gui_draw_runs(uVar1,4,400,&DAT_2016dc08);
  iVar2 = extraout_r1;
  if (param_3 != 0) {
    iVar2 = param_3;
  }
  local_78 = 0xf;
  local_74 = &DAT_20800cac;
  if (param_3 == 0) {
    iVar2 = DAT_20808540;
  }
  FUN_20135ff0(uVar1,iVar2,4,400);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
  iVar2 = FUN_20103bb0();
  if (iVar2 == 0) {
    local_38 = 0;
    local_4c = 0x447;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    FUN_20158f28(param_1 + 0x128,&local_4c);
    return;
  }
  fwfile_check_versions(param_1 + 8);
  iVar2 = 0;
  do {
    local_78 = 0xf;
    local_74 = &DAT_20800b1c;
    iVar3 = param_1 + iVar2 * 0x48;
    FUN_20135dd4(local_4c,iVar3 + 9,iVar2 * 0x44 + 0x41U & 0xffff,0xc4);
    local_74 = &DAT_20800b1c;
    local_78 = 0xf;
    FUN_20135dd4(local_4c,iVar3 + 0x1d,iVar2 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  gui_update_layers();
  fb_get_layer_addr(DAT_208085bc);
  FUN_20126160(1);
  iVar2 = fwfile_status_text(param_1 + 8,0);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
  FUN_20133620();
  FUN_20126160(0);
  itron_dly_tsk(0x32);
  iVar3 = FUN_20103ba0();
  if (iVar3 == 0) {
    local_78 = 0;
    local_74 = (undefined *)0x0;
    FUN_20158ec0(param_1 + 0x128,&local_78);
    return;
  }
  if (iVar2 == 1 || iVar2 == 3) {
    local_38 = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_4c = (uint)CONCAT11((char)iVar2,0x47);
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    FUN_20158f28(param_1 + 0x128,&local_4c);
    return;
  }
  iVar3 = 0x47;
  local_5c = 0;
  local_6c = 0;
  local_68 = 0;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  local_64 = 0;
  local_70._0_2_ = CONCAT11((char)iVar2,0x47);
  local_70 = (uint)(ushort)local_70;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  if (iVar2 == 0) {
    do {
      iVar2 = param_1 + iVar3 * 0x48;
      if (*(char *)(iVar2 + 8) == '\x01') {
        local_70._0_3_ =
             CONCAT12(local_70._2_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(ushort)local_70);
        local_70 = (uint)(uint3)local_70;
      }
      if (*(char *)(iVar2 + 8) == '\x03') {
        local_6c = (uint)(byte)((byte)local_6c | (byte)(1 << (7U - iVar3 & 0xff)));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  iVar2 = 0;
  do {
    sprintf(&local_78,&DAT_2042813c,*(undefined2 *)(param_1 + iVar2 * 2));
    iVar3 = FUN_2014e208(param_1 + iVar2 * 0x48 + 0x31,&local_78);
    if (0 < iVar3) {
      local_70 = CONCAT13(local_70._3_1_ | (byte)(1 << (7U - iVar2 & 0xff)),(uint3)local_70);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_20158f28(param_1 + 0x128,&local_70);
  iVar2 = 0;
  do {
    local_78 = 800;
    local_74 = (undefined *)0x1a;
    uVar4 = iVar2 * 0x44 + 0x41;
    fb_fill_rect(local_4c,0x821,uVar4 & 0xffff,0x25c);
    local_74 = &DAT_20800b1c;
    local_78 = 0xf;
    iVar3 = param_1 + iVar2 * 0x48;
    FUN_20135dd4(local_4c,iVar3 + 9,uVar4 & 0xffff,0xc4);
    local_74 = &DAT_20800b1c;
    local_78 = 0xf;
    FUN_20135dd4(local_4c,iVar3 + 0x1d,iVar2 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_2015a4c8();
  return;
}


// ===== FUN_2015a910 @ 2015a910 (1628 bytes)

/* WARNING: Removing unreachable block (ram,0x2015ae84) */

undefined4 FUN_2015a910(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *extraout_r1;
  uint *extraout_r1_00;
  uint uVar9;
  int iVar10;
  short sVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  bool bVar17;
  short local_2a8 [2];
  short local_2a4 [2];
  undefined1 auStack_2a0 [3];
  byte local_29d;
  byte local_29c;
  byte local_29b;
  uint *local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  byte local_48 [24];
  int local_30;
  uint uStack_2c;
  undefined4 local_28;
  
  sVar11 = DAT_20808536;
  local_30 = param_1;
  uStack_2c = param_2;
  local_28 = param_3;
  FUN_20159320();
  local_58 = 0xfa;
  local_50 = *DAT_20802294 + 0xfa & 0xffff;
  uVar14 = *DAT_20802294 + 0x1a4 & 0xffff;
  local_60 = (uint *)0x19a;
  local_54 = DAT_20802294[1] + 0x19a & 0xffff;
  puVar13 = (uint *)(DAT_20802294[1] + 0x19a & 0xffff);
  local_5c = 0x1a4;
  memclr(auStack_2a0,0x240);
  memcpy(auStack_2a0,param_2,0x240);
LAB_2015a994:
  iVar4 = FUN_20103bb0();
  if (iVar4 == 0) {
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_48[5] = 0;
    local_48[6] = 0;
    local_48[7] = 0;
    local_48[8] = 0;
    local_48[9] = 0;
    local_48[10] = 0;
    local_48[0xb] = 0;
    local_60 = (uint *)0x447;
    FUN_20158f28(local_30 + 0x128,&local_60);
    return 0;
  }
  FUN_201218a4();
  if (DAT_20800493 != '\0') {
    return 0;
  }
  gui_update_layers();
  local_2a8[0] = 0;
  local_2a4[0] = 0;
  FUN_20102138(local_48 + 0xc,1);
  FUN_20103060((int)(short)local_48._16_4_,(int)(short)local_48._20_4_,local_2a8,local_2a4);
  if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
     (local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
    FUN_20113f38(local_2a8[0],local_2a4[0]);
    if ((local_29c != 0) &&
       ((((local_58 <= local_2a8[0] && ((int)local_2a8[0] < (int)local_50)) &&
         (0x199 < local_2a4[0])) && ((int)local_2a4[0] < (int)local_54)))) {
      DAT_20808530 = 1;
      return 1;
    }
    if (DAT_20800494 != '\0') {
      uVar5 = (uint)local_2a8[0];
      bVar17 = SBORROW4(uVar5,local_5c);
      iVar4 = uVar5 - local_5c;
      uVar7 = local_5c;
      if ((int)local_5c <= (int)uVar5) {
        bVar17 = SBORROW4(uVar14,uVar5);
        iVar4 = uVar14 - uVar5;
        uVar7 = uVar14;
      }
      if (uVar5 != uVar7 && iVar4 < 0 == bVar17) {
        puVar6 = (uint *)(int)local_2a4[0];
        bVar17 = SBORROW4((int)puVar6,(int)local_60);
        iVar4 = (int)puVar6 - (int)local_60;
        puVar8 = local_60;
        if ((int)local_60 <= (int)puVar6) {
          bVar17 = SBORROW4((int)puVar13,(int)puVar6);
          iVar4 = (int)puVar13 - (int)puVar6;
          puVar8 = puVar13;
        }
        if (puVar6 != puVar8 && iVar4 < 0 == bVar17) {
          FUN_20121830(0);
          DAT_20808530 = 0;
          return 1;
        }
      }
    }
    uVar7 = 0;
    do {
      iVar4 = uVar7 * 0x44 + 0x32;
      iVar10 = uVar7 * 0x44 + 0x75;
      if (((((uint)local_29d & 1 << (7 - uVar7 & 0xff)) != 0) && (0x74 < local_2a8[0])) &&
         (local_2a8[0] < 0xed)) {
        iVar15 = (int)local_2a4[0];
        bVar17 = SBORROW4(iVar15,iVar4);
        iVar1 = iVar15 - iVar4;
        if (iVar4 <= iVar15) {
          bVar17 = SBORROW4(iVar10,iVar15);
          iVar1 = iVar10 - iVar15;
          iVar4 = iVar10;
        }
        if (iVar15 != iVar4 && iVar1 < 0 == bVar17) {
          local_29c = local_29c ^ (byte)(1 << (7 - uVar7 & 0xff));
          local_29b = (byte)uVar7;
          FUN_2015b450(local_30,auStack_2a0,local_28);
          if (DAT_20800494 != '\0') {
            FUN_20121830(0);
          }
          break;
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 4);
  }
  FUN_20102138(local_48 + 0xc,0);
  local_2a8[0] = (short)local_48._16_4_;
  iVar4 = (int)local_2a8[0];
  local_2a4[0] = (short)local_48._20_4_;
  puVar8 = (uint *)(int)local_2a4[0];
  if (DAT_20800494 != '\0') {
    if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
       (local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
      local_4c = (uint)local_29c;
      if (((local_4c != 0) &&
          (((local_58 <= iVar4 && (iVar4 < (int)local_50)) && (0x199 < (int)puVar8)))) &&
         ((int)puVar8 < (int)local_54)) {
        DAT_20808530 = 1;
        return 1;
      }
      bVar17 = SBORROW4(local_5c,iVar4);
      iVar10 = local_5c - iVar4;
      if ((int)local_5c <= iVar4) {
        bVar17 = SBORROW4(iVar4,uVar14);
        iVar10 = iVar4 - uVar14;
      }
      if (iVar10 < 0 != bVar17) {
        bVar17 = SBORROW4((int)puVar8,(int)local_60);
        iVar10 = (int)puVar8 - (int)local_60;
        puVar6 = local_60;
        if ((int)local_60 <= (int)puVar8) {
          bVar17 = SBORROW4((int)puVar13,(int)puVar8);
          iVar10 = (int)puVar13 - (int)puVar8;
          puVar6 = puVar13;
        }
        if (puVar8 != puVar6 && iVar10 < 0 == bVar17) {
          DAT_20808530 = 0;
          return 1;
        }
      }
      uVar7 = 0;
      do {
        puVar6 = (uint *)(uVar7 * 0x44 + 0x32);
        puVar16 = (uint *)(uVar7 * 0x44 + 0x75);
        if (((((uint)local_29d & 1 << (7 - uVar7 & 0xff)) != 0) && (0x74 < iVar4)) && (iVar4 < 0xed)
           ) {
          bVar17 = SBORROW4((int)puVar8,(int)puVar6);
          iVar10 = (int)puVar8 - (int)puVar6;
          if ((int)puVar6 <= (int)puVar8) {
            bVar17 = SBORROW4((int)puVar16,(int)puVar8);
            iVar10 = (int)puVar16 - (int)puVar8;
            puVar6 = puVar16;
          }
          if (puVar8 != puVar6 && iVar10 < 0 == bVar17) {
            local_29c = local_29c ^ (byte)(1 << (7 - uVar7 & 0xff));
            local_29b = (byte)uVar7;
            FUN_2015b450(local_30,auStack_2a0,local_28);
            if (DAT_20800494 != '\0') {
              FUN_20121830(0);
            }
            break;
          }
        }
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 4);
    }
    FUN_201023bc(local_48 + 0xc);
    if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
       (puVar8 = extraout_r1, local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
      DAT_20808530 = 0;
      return 1;
    }
  }
  if (DAT_20808533 != '\0') {
    DAT_20808533 = '\0';
    local_4c = 0x10204080;
    switch(local_29b) {
    case 0:
    case 1:
    case 2:
    case 3:
      if (DAT_20800494 != '\0') {
        FUN_20121830(0);
      }
      puVar8 = (uint *)(uint)local_29c;
      bVar2 = *(byte *)((int)&local_4c + (uint)local_29b);
      if ((local_29c & bVar2) == 0) {
        local_29c = bVar2 | local_29c;
      }
      else {
        local_29c = local_29c & ~bVar2;
      }
      break;
    case 10:
      DAT_20808530 = 1;
      DAT_20808533 = 0;
      return 1;
    case 0xb:
      if (DAT_20800494 != '\0') {
        FUN_20121830(0);
        puVar8 = extraout_r1_00;
      }
      DAT_20808530 = 0;
    }
    if (local_29b == 10 || local_29b == 0xb) {
      return 1;
    }
  }
  sVar3 = DAT_20808536;
  uVar7 = param_2;
  if (DAT_20800494 != '\0') {
    if ((sVar11 != DAT_20808536) || (DAT_20808534 != 0)) {
      if ((sVar11 < DAT_20808536) || (DAT_20808534 < 0)) {
        uVar5 = local_29b + 1;
        if (uVar5 < 0xb) {
          if (uVar5 < 4) {
            puVar8 = &local_4c;
          }
          local_4c = 0x10204080;
          if (uVar5 < 4) {
            do {
              if ((*(byte *)((int)puVar8 + uVar5) & local_29d) != 0) goto LAB_2015af84;
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 < 4);
          }
          if (local_29c != 0) goto LAB_2015af20;
        }
LAB_2015af4c:
        uVar7 = 0xb;
      }
      else {
        uVar12 = (uint)local_29b;
        if (uVar12 == 0xb) {
          if (local_29c == 0) {
            local_48[0] = 0x80;
            local_48[1] = 0x40;
            local_48[2] = 0x20;
            local_48[3] = 0x10;
            if (local_29d == 0) goto LAB_2015af4c;
            uVar5 = 3;
            do {
              if ((local_48[uVar5] & local_29d) != 0) goto LAB_2015af84;
              uVar5 = uVar5 - 1;
            } while (((int)uVar5 < 4) && (-1 < (int)uVar5));
          }
          else {
LAB_2015af20:
            uVar7 = 10;
          }
        }
        else {
          local_48[4] = 0x80;
          local_48[5] = 0x40;
          local_48[6] = 0x20;
          local_48[7] = 0x10;
          if (uVar12 == 10) {
            uVar5 = 3;
            uVar9 = uVar5;
          }
          else {
            uVar5 = uVar12 - 1;
            uVar9 = uVar5;
          }
          do {
            uVar7 = uVar12;
            if ((int)uVar5 < 0) break;
            if ((local_48[uVar5 + 4] & local_29d) != 0) goto LAB_2015af84;
            uVar5 = uVar5 - 1;
            uVar7 = param_2;
          } while ((int)uVar5 <= (int)uVar9);
        }
      }
      goto LAB_2015aea4;
    }
    goto LAB_2015aea8;
  }
  goto LAB_2015aec4;
LAB_2015af84:
  uVar7 = (int)(short)uVar5;
LAB_2015aea4:
  local_29b = (byte)uVar7;
LAB_2015aea8:
  DAT_20808534 = 0;
  FUN_2015b450(local_30,auStack_2a0,local_28);
  sVar11 = sVar3;
LAB_2015aec4:
  FUN_201525f8(0xffffffff);
  param_2 = uVar7;
  goto LAB_2015a994;
}


// ===== FUN_2015b134 @ 2015b134 (764 bytes)

void FUN_2015b134(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  char local_270 [288];
  undefined1 auStack_150 [288];
  undefined4 local_30;
  int local_2c;
  
  local_30 = fb_get_layer_addr(DAT_208085bc);
  FUN_20113ea0();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_copy_rect(local_30,0,0,800,0x1e0);
  fb_fill_rect(local_30,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(local_30,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  FUN_20135ff0(local_30,param_3,4,400,0xf,&DAT_20800cac);
  FUN_20135ff0(local_30,DAT_20808544,0x1a7,400,0xf,&DAT_20800cac);
  local_2c = 0xff;
  FUN_20155310(local_270,param_1 + 8,0x120);
  FUN_20155310(auStack_150,param_1 + 8,0x120);
  FUN_20126160(1);
  while( true ) {
    iVar2 = FUN_2010e2d4(param_1 + 8);
    iVar3 = FUN_20103ba0();
    if (iVar3 == 0) break;
    bVar5 = local_2c != iVar2;
    local_2c = iVar2;
    if ((bVar5) || (iVar3 = FUN_2015507c(param_1 + 8,auStack_150,0x120), iVar3 != 0)) {
      FUN_20155310(auStack_150,param_1 + 8,0x120);
      uVar4 = 0;
      do {
        iVar3 = param_1 + uVar4 * 0x48;
        FUN_20135dd4(local_30,iVar3 + 9,uVar4 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar1 = *(char *)(iVar3 + 8);
        if (cVar1 == '\x04') {
          if (local_270[uVar4 * 0x48] != '\x04') {
            fb_copy_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          FUN_201219b8(local_30,uVar4 * 0x44 + 0x42,0x1dc,*(uint *)(iVar3 + 0x40) & 0xffff,
                       *(uint *)(iVar3 + 0x40));
        }
        else {
          if (cVar1 == '\x05') {
            if (local_270[uVar4 * 0x48] != '\x05') {
              fb_copy_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(local_30,uVar4 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar1 != local_270[uVar4 * 0x48]) {
            fb_copy_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          FUN_20135dd4(local_30,iVar3 + 0x1d,uVar4 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 4);
      FUN_20155310(local_270,param_1 + 8,0x120);
      if (iVar2 != 0) goto LAB_2015b360;
      gui_update_layers();
      local_30 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  iVar2 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (iVar2 != 1) {
    FUN_20159158();
  }
  FUN_20114df4();
  return;
}


// ===== FUN_2015b450 @ 2015b450 (708 bytes)

void FUN_2015b450(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar6 = (uint)*(byte *)(param_2 + 5);
  fb_copy_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  FUN_20135ff0(uVar2,param_3,4,400,0xf,&DAT_20800cac);
  uVar3 = 0;
  do {
    uVar1 = 1 << (7 - uVar3 & 0xff);
    if ((*(byte *)(param_2 + 3) & uVar1) != 0) {
      iVar5 = uVar3 * 0x44 + 0x32;
      fb_copy_rect(uVar2,iVar5,0x75,0x78,0x43);
      if ((*(byte *)(param_2 + 4) & uVar1) == 0) {
        puVar4 = (undefined2 *)&DAT_203a5684;
        *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 0;
      }
      else {
        puVar4 = &DAT_203a5694;
        *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 1;
      }
      gui_draw_runs(uVar2,iVar5,0x75,puVar4);
      if (uVar3 == uVar6) {
        FUN_20136398(uVar2,iVar5,0x75,*puVar4,puVar4[1],3);
      }
    }
    iVar5 = param_1 + uVar3 * 0x48;
    FUN_20135dd4(uVar2,iVar5 + 9,uVar3 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
    FUN_20135dd4(uVar2,iVar5 + 0x1d,uVar3 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  FUN_20126914(uVar2,0x19a,0xfa,2);
  if (*(char *)(param_2 + 4) == '\0') {
    gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20255114);
  }
  else {
    gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20254600);
  }
  if (uVar6 == 10) {
    FUN_20136398(uVar2,0x19a,0xfa,*DAT_20802294,DAT_20802294[1],3);
  }
  if (DAT_20800494 != '\0') {
    FUN_20126914(uVar2,0x19a,0x1a4,2);
    gui_draw_runs(uVar2,0x1a6,0x1b9,&DAT_20251ec8);
    if (uVar6 == 0xb) {
      FUN_20136398(uVar2,0x19a,0x1a4,*DAT_20802294,DAT_20802294[1],3);
    }
  }
  return;
}


// ===== FUN_2015b748 @ 2015b748 (392 bytes)

void FUN_2015b748(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  cVar1 = *(char *)(param_2 + 5);
  fb_copy_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  gui_draw_runs(uVar2,8,0x168,&DAT_203a56b4);
  FUN_20135ff0(uVar2,"UPDATE?",0xf0,400,0xf,&DAT_20800cac);
  FUN_20126914(uVar2,0x19a,0xfa,2);
  gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20253aec);
  if (cVar1 == '\n') {
    FUN_20136398(uVar2,0x19a,0xfa,*DAT_20802294,DAT_20802294[1],3);
  }
  FUN_20126914(uVar2,0x19a,0x1a4,2);
  gui_draw_runs(uVar2,0x1a6,0x1b9,&DAT_20251ec8);
  if (cVar1 == '\v') {
    FUN_20136398(uVar2,0x19a,0x1a4,*DAT_20802294,DAT_20802294[1],3);
  }
  return;
}


// ===== FUN_2015b8f8 @ 2015b8f8 (176 bytes)

void FUN_2015b8f8(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_358 [804];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  uVar1 = FUN_201343c4(param_2,param_5,auStack_358);
  uVar2 = FUN_20134398(param_5);
  uVar3 = FUN_20134408(param_2);
  uVar4 = FUN_20134358(param_2,param_5);
  FUN_2015bc6c(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,uVar4
               ,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== FUN_2015b9a8 @ 2015b9a8 (28 bytes)

void FUN_2015b9a8(void)

{
  FUN_20134310();
  FUN_2015526c(DAT_208085b4,0x6b080);
  return;
}


// ===== FUN_2015b9cc @ 2015b9cc (240 bytes)

void FUN_2015b9cc(undefined4 *param_1,undefined4 param_2,int param_3,ushort *param_4,
                 undefined4 param_5)

{
  short sVar1;
  int extraout_r1;
  int iVar2;
  code *pcVar3;
  undefined4 *unaff_r7;
  bool bVar4;
  undefined4 local_28;
  
  bVar4 = param_3 == 0;
  if (!bVar4) {
    unaff_r7 = param_1 + 0x1f;
  }
  local_28 = 0;
  if (bVar4) {
    unaff_r7 = param_1 + 1;
  }
  if (bVar4) {
    pcVar3 = FUN_2015b8f8;
  }
  else {
    pcVar3 = FUN_2015bacc;
  }
  if (3 < *param_4) {
    local_28 = CONCAT22(param_4[1],*param_4);
  }
  FUN_20134348(DAT_208085b0,&local_28);
  FUN_20134328(8,DAT_208085b0,param_3);
  __aeabi_uidivmod(param_2,DAT_208085b0);
  if (extraout_r1 == 0) {
    FUN_20134318(8,param_3);
  }
  FUN_20155274(*param_1,0x6b080);
  iVar2 = 1;
  do {
    (*pcVar3)(*param_1,iVar2,unaff_r7[iVar2] & 0xffff,4,8,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1e);
  if (param_3 == 0) {
    sVar1 = 0xde;
  }
  else {
    sVar1 = 0x112;
  }
  memcpy(param_5,*param_1,sVar1 * 0x640);
  return;
}


// ===== FUN_2015bacc @ 2015bacc (176 bytes)

void FUN_2015bacc(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_358 [804];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  uVar1 = FUN_201343c4(param_2,param_5,auStack_358);
  uVar2 = FUN_20134398(param_5);
  uVar3 = FUN_20134408(param_2);
  uVar4 = FUN_20134358(param_2,param_5);
  FUN_2015bc6c(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,uVar4
               ,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== FUN_2015bb7c @ 2015bb7c (236 bytes)

void FUN_2015bb7c(undefined4 *param_1,undefined4 param_2,int param_3,ushort *param_4,
                 undefined4 param_5)

{
  int extraout_r1;
  short unaff_r4;
  int iVar1;
  undefined4 *unaff_r6;
  undefined4 uVar2;
  bool bVar3;
  undefined4 local_28;
  
  bVar3 = param_3 != 0;
  if (bVar3) {
    unaff_r6 = param_1 + 0x4c;
  }
  local_28 = 0;
  if (bVar3) {
    unaff_r4 = 0x9c;
  }
  if (!bVar3) {
    unaff_r6 = param_1 + 0x3d;
    unaff_r4 = 0x68;
  }
  if (3 < *param_4) {
    local_28 = CONCAT22(param_4[1],*param_4);
  }
  FUN_20134348(DAT_208085b0,&local_28);
  FUN_20134328(9,DAT_208085b0,param_3);
  __aeabi_uidivmod(param_2,DAT_208085b0);
  if (extraout_r1 == 0) {
    FUN_20134318(9,param_3);
  }
  uVar2 = *param_1;
  FUN_20155274(uVar2,unaff_r4 * 0x640);
  iVar1 = 1;
  do {
    FUN_2015b8f8(*param_1,iVar1,unaff_r6[iVar1] & 0xffff,4,9,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  memcpy(param_5,uVar2,unaff_r4 * 0x640);
  return;
}


// ===== FUN_2015bc6c @ 2015bc6c (484 bytes)

/* WARNING: Type propagation algorithm not settling */

void FUN_2015bc6c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 ushort *param_7,int param_8,int param_9,int *param_10,int param_11)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  ushort *puVar4;
  short *psVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  short local_400 [240];
  short local_220 [240];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  
  local_28 = param_4;
  iStack_2c = param_3;
  iStack_30 = param_2;
  local_34 = param_1;
  local_38 = param_2 * 800;
  uVar6 = (uint)param_7[1];
  uVar1 = *param_7;
  iVar11 = *(int *)(param_7 + 2);
  iVar3 = 0;
  iVar9 = *(int *)(param_9 + 4);
  if (uVar6 != 0) {
    do {
      iVar8 = (uVar6 - param_5) + iVar3;
      psVar5 = local_400 + iVar3;
      iVar3 = iVar3 + 1;
      *psVar5 = *(short *)(iVar11 + (iVar8 * (uint)uVar1 + param_8) * 2);
    } while (iVar3 < (int)uVar6);
  }
  iVar3 = 0;
  if (uVar6 != 0) {
    do {
      iVar11 = (uVar6 - param_5) + iVar3;
      psVar5 = local_220 + iVar3;
      iVar3 = iVar3 + 1;
      *psVar5 = *(short *)(iVar9 + (iVar11 * (uint)uVar1 + param_8) * 2);
    } while (iVar3 < (int)uVar6);
  }
  iVar3 = 0;
  local_3c = local_28 + param_3;
  if (param_3 < local_3c) {
    local_40 = param_11 + -1;
    do {
      bVar2 = false;
      iVar8 = 0;
      iVar9 = param_5 - (uint)*(byte *)(param_6 + iVar3);
      iVar11 = local_38 + iVar9 * 800;
      puVar7 = (ushort *)0x0;
      if (0 < *param_10) {
        do {
          puVar4 = (ushort *)(param_10 + iVar8 + 1);
          if (((((puVar7 == (ushort *)0x0) || (*puVar7 != *puVar4)) ||
               (puVar7[1] != *(ushort *)((int)param_10 + iVar8 * 4 + 6))) &&
              ((uVar6 = (uint)*(ushort *)((int)param_10 + iVar8 * 4 + 6), uVar6 != 0 &&
               (puVar7 = puVar4, (int)((uint)*puVar4 + param_11) <= param_3)))) &&
             (param_3 <= (int)(param_11 + -1 + uVar6 + *puVar4))) {
            bVar2 = true;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *param_10);
      }
      while ((iVar9 < param_5 &&
             (psVar5 = (short *)(local_34 + (param_3 + iVar11) * 2), *psVar5 == 0))) {
        iVar11 = iVar11 + 800;
        if (bVar2) {
          psVar10 = local_220;
        }
        else {
          psVar10 = local_400;
        }
        psVar10 = psVar10 + iVar9;
        iVar9 = iVar9 + 1;
        *psVar5 = *psVar10;
      }
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
    } while (param_3 < local_3c);
  }
  return;
}


// ===== FUN_2015bf88 @ 2015bf88 (184 bytes)

undefined2 FUN_2015bf88(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = 0;
  if (0 < param_4) {
    do {
      puVar2 = (ushort *)(param_3 + uVar6 * 10);
      uVar1 = (uint)*puVar2;
      uVar3 = puVar2[2] + uVar1;
      uVar4 = (uint)puVar2[1];
      uVar5 = puVar2[3] + uVar4 & 0xffff;
      if ((uVar6 == 0x20) &&
         ((&DAT_20801d73)[(uint)DAT_20800465 * 0x2f] != -0x1e &&
          (&DAT_20801d73)[(uint)DAT_20800465 * 0x2f] != -0x1d)) {
        uVar1 = uVar1 + 0x24 & 0xffff;
      }
      bVar7 = param_1 <= uVar1;
      if (uVar1 <= param_1) {
        bVar7 = (uVar3 & 0xffff) <= param_1;
      }
      if (!bVar7) {
        uVar1 = uVar4;
        if (uVar4 <= param_2) {
          uVar1 = uVar5;
        }
        if ((uVar4 <= param_2 && param_2 <= uVar5) && param_2 != uVar1) {
          return *(undefined2 *)(param_3 + uVar6 * 10 + 8);
        }
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while ((int)uVar6 < param_4);
  }
  return 0x1ff;
}


// ===== FUN_2015c048 @ 2015c048 (912 bytes)

int FUN_2015c048(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  byte bVar6;
  undefined4 uVar7;
  
  if (DAT_208f0b2a == 0x40) {
    iVar5 = FUN_2015c34c(param_1,param_2);
switchD_2015c074_caseD_32:
    if (iVar5 != 0x1ff) {
      return iVar5;
    }
  }
  else {
    if (DAT_208f0b2a < 0x41) {
      iVar5 = 0x1ff;
      switch(DAT_208f0b2a) {
      case 0x30:
        iVar5 = FUN_2015c43c(param_1,param_2,DAT_208f0bc2);
        break;
      case 0x31:
        iVar5 = FUN_20130998();
        if (iVar5 == 0) {
          return 0xff;
        }
        goto LAB_2015c240;
      case 0x34:
        iVar5 = FUN_2015bf88(param_1,param_2,&DAT_20266736,4);
        break;
      case 0x37:
        iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2080188c,0x23);
        if ((iVar5 == 0x10e7) && (DAT_208f0ca2 == '5')) {
          return 0x10e9;
        }
        break;
      case 0x39:
        if ((DAT_208f0bdb & 3) == 0) {
          iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016ebdc,0xb);
        }
        else if ((DAT_208f0bdb & 3) == 1) {
          iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016ec4a,0xb);
        }
        else {
          iVar5 = FUN_2015bf88(param_1,param_2,&DAT_20376520,0xb);
        }
        break;
      case 0x3a:
        iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016e1c4,0xd);
      }
      goto switchD_2015c074_caseD_32;
    }
    if (DAT_208f0b2a == 0x50) {
      iVar5 = FUN_2015bf88(param_1,param_2,(&PTR_DAT_20802198)[DAT_20800464],0x30);
      goto switchD_2015c074_caseD_32;
    }
    if (DAT_208f0b2a < 0x51) {
      if (DAT_208f0b2a == 0x41) {
        iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016db98,0xb);
      }
      else {
        if (DAT_208f0b2a != 0x43) goto LAB_2015c240;
        iVar5 = FUN_2015c750(param_1,param_2);
      }
      goto switchD_2015c074_caseD_32;
    }
    if (DAT_208f0b2a == 0x70) {
      iVar5 = FUN_2015ca14(param_1,param_2);
      goto switchD_2015c074_caseD_32;
    }
    if (DAT_208f0b2a == 0x7c) {
      return 0xff;
    }
  }
LAB_2015c240:
  bVar1 = DAT_208f0b4d;
  uVar2 = (uint)DAT_208f0b2f;
  uVar3 = (uint)DAT_208f0b4d;
  uVar4 = (uint)DAT_208f0b4f;
  bVar6 = DAT_208f0b50 & 0x7f;
  uVar7 = param_2;
  if ((((int)(uVar2 << 0x1a) < 0) || (DAT_208f0b2a == 0x37)) ||
     (iVar5 = FUN_2015c6fc(param_1,param_2,&DAT_20192748,0,param_1,param_2,unaff_r4,unaff_r5,
                           unaff_r6), iVar5 == 0x1ff)) {
    iVar5 = FUN_2015c6fc(param_1,param_2,&DAT_2042007c,0,param_1,uVar7,unaff_r4,unaff_r5,unaff_r6);
  }
  if (iVar5 == 0x1ff) {
    iVar5 = FUN_2015c6fc(param_1,param_2,&DAT_20350ac8,0,param_1,uVar7,unaff_r4,unaff_r5,unaff_r6);
  }
  if (iVar5 == 0x1ff) {
    iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2021cc58,3);
  }
  if (((iVar5 == 0x1ff) || (DAT_208f0b2a != 0x30)) || (3 < DAT_208f0bc2 - 1)) {
    if (iVar5 != 0x1ff) goto LAB_2015cc24;
  }
  else {
    iVar5 = 0x1ff;
  }
  if ((-1 < (int)(uVar2 << 0x1a)) && (DAT_208f0b2a != 0x37)) {
    iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016e15c,4);
  }
LAB_2015cc24:
  if ((((iVar5 == 0x1ff) && ((char)bVar1 < '\0')) &&
      (iVar5 = FUN_2015bf88(param_1,param_2,&DAT_201ac45c,5), iVar5 == 0x10c3)) &&
     ((int)(uVar3 << 0x1d) < 0)) {
    iVar5 = 0x10c4;
  }
  if (DAT_20800483 == '\0') {
    if (iVar5 == 0x1ff) {
      iVar5 = FUN_2015c558(param_1,param_2);
    }
    if (iVar5 == 0x1ff) {
      iVar5 = FUN_2015bf88(param_1,param_2,&DAT_2016e304,6);
      if (iVar5 == 0x1000) {
        if ((uVar4 & 0x7f) == 0xb) {
          return 0x1008;
        }
        iVar5 = (uVar4 & 0x7f) + 0x1000;
      }
      if (iVar5 == 0x1003 && bVar6 == 0xc) {
        iVar5 = 0x1009;
      }
    }
  }
  return iVar5;
}


// ===== FUN_2015c278 @ 2015c278 (84 bytes)

bool FUN_2015c278(void)

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
  memcpy(&local_20,&DAT_208f0bc7,0x14);
  iVar1 = strcmp("EXTENSION SETTING   ",&local_20);
  return iVar1 == 0;
}


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

