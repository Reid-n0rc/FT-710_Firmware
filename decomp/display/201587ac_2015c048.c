// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_tx_ctor @ 201587ac (32 bytes)

/* vtbl 0x20427FAC */

int mainlink_tx_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fac;
  iVar1 = FUN_20162c18((int)param_1 + 0x811c);
  return iVar1 + -0x811c;
}


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


// ===== task_uart4_rx @ 20158930 (180 bytes)

/* passes raw bytes to FUN_20131154 */

void task_uart4_rx(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  uint local_114;
  undefined1 auStack_110 [260];
  
  __aeabi_memclr4(auStack_110,0x100);
  FUN_20158920(param_1);
  while( true ) {
    while (pvVar1 = itron_twai_flg(*(uint *)(param_1 + 0x24),0xc001,5,&local_114,-1),
          pvVar1 == (void *)0xffffffce) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
    if (pvVar1 != (void *)0x0) break;
    if (((local_114 & 0xc000) == 0) && ((local_114 & 1) != 0)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      uVar2 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                        (*(int **)(param_1 + 0x10),auStack_110,0x100);
      decode_text_rx(auStack_110,uVar2);
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


// ===== uart4_tx_alloc @ 201589f4 (12 bytes)

uint uart4_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_201644ac(param_1 + 0x111c);
  return uVar1;
}


// ===== uart4_tx_init @ 20158a00 (96 bytes)

void uart4_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
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


// ===== task_uart4_tx @ 20158a70 (108 bytes)

void task_uart4_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  FUN_20158a60();
  do {
    itron_trcv_mbx(*(undefined4 *)(param_1 + 0x11a4),local_8,0xffffffff);
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


// ===== uart4_tx_post @ 20158adc (16 bytes)

void uart4_tx_post(int param_1,uint param_2)

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


// ===== mainlink_obj_run @ 20158b10 (240 bytes)

/* task "uart" pri 7: binds SCIF5, starts the 3 sub-tasks, opens 345600 baud 8N2 */

void mainlink_obj_run(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = itron_acre_tsk(0,&DAT_20165938);
  if (((0 < (int)uVar1) && (uVar2 = itron_acre_tsk(0,&DAT_2016591c), 0 < (int)uVar2)) &&
     (uVar3 = itron_acre_tsk(0,&DAT_20165900), 0 < (int)uVar3)) {
    uVar4 = param_1 + 0x8218;
    mainlink_tx_init(uVar4,*(uint *)(param_1 + 0x10));
    mainlink_disp_init(param_1 + 0x58,uVar4);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x14);
    mainlink_rx_bind(param_1 + 0x18,*(uint *)(param_1 + 0x10),uVar4,param_1 + 0x58);
    uVar1 = itron_sta_tsk(uVar1,uVar4);
    if (((uVar1 == 0) && (uVar1 = itron_sta_tsk(uVar2,param_1 + 0x58), uVar1 == 0)) &&
       (uVar1 = itron_sta_tsk(uVar3,param_1 + 0x18), uVar1 == 0)) {
      (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x54600,8,0);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== mainlink_obj_ctor @ 20158c10 (48 bytes)

/* builds RX (+0x18), dispatcher (+0x58) and TX (+0x8218) sub-objects */

int mainlink_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fd0;
  iVar1 = mainlink_rx_ctor((int)param_1 + 0x18);
  iVar1 = mainlink_disp_ctor((void *)(iVar1 + 0x40));
  iVar1 = mainlink_tx_ctor((void *)(iVar1 + 0x81c0));
  return iVar1 + -0x8218;
}


// ===== uart4_obj_run @ 20158c44 (548 bytes)

/* 38400 baud; probes with 0xF0 bytes, then sends 1E 00 31 / 1F 00 32 */

void uart4_obj_run(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_20;
  
  local_20 = 1;
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x9600,8,0);
  if (DAT_208dbb44 == 0xbbbb) {
    itron_tslp_tsk(0xffffffff);
  }
  if (DAT_2045001d == '\x01') {
    DAT_2045001d = '\x02';
    itron_tslp_tsk(0xffffffff);
  }
  iVar6 = 5;
  do {
    local_20 = 0xf0;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(*(int **)(param_1 + 0x10),&local_20,1);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))
                      (*(int **)(param_1 + 0x10),&DAT_2045001e,2,100);
    if (iVar1 != -1) {
      iVar6 = iVar6 + -1;
    }
    if (DAT_2045001d == '\x01') {
      DAT_2045001d = '\x02';
      itron_tslp_tsk(0xffffffff);
    }
  } while (iVar6 != 0);
  DAT_2045001c = 1;
  uVar2 = itron_acre_tsk(0,&DAT_2016583c);
  if (((0 < (int)uVar2) && (uVar3 = itron_acre_tsk(0,&DAT_20165820), 0 < (int)uVar3)) &&
     (uVar4 = itron_acre_tsk(0,&DAT_20165804), 0 < (int)uVar4)) {
    uVar5 = param_1 + 0x938;
    uart4_tx_init(uVar5,*(uint *)(param_1 + 0x10));
    FUN_2015ff94(param_1 + 0x50,uVar5);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x14);
    FUN_20158914(param_1 + 0x18,*(undefined4 *)(param_1 + 0x10),uVar5,param_1 + 0x50);
    uVar2 = itron_sta_tsk(uVar2,uVar5);
    if (((uVar2 == 0) && (uVar2 = itron_sta_tsk(uVar3,param_1 + 0x50), uVar2 == 0)) &&
       (uVar2 = itron_sta_tsk(uVar4,param_1 + 0x18), uVar2 == 0)) {
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar5);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1e;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x31;
      uart4_tx_post(uVar5,uVar2);
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar5);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1f;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x32;
      uart4_tx_post(uVar5,uVar2);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== uart4_obj_ctor @ 20158e8c (48 bytes)

/* vtbl 0x20427FE4 */

int uart4_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fe4;
  iVar1 = FUN_201589e4((int)param_1 + 0x18);
  iVar1 = FUN_20160018(iVar1 + 0x38);
  iVar1 = FUN_20158aec(iVar1 + 0x8e8);
  return iVar1 + -0x938;
}


// ===== mainlink_send_ui_e2 @ 20158ec0 (96 bytes)

/* 0xE2 UI frame to MAIN */

void mainlink_send_ui_e2(void *param_1,uint param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
  FUN_201636cc((int)&local_18 + 1,param_2);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_18,6);
  }
  FUN_201636cc((int)param_1 + 0x22,param_2);
  *(undefined1 *)param_1 = (undefined1)local_18;
  return;
}


// ===== mainlink_send_ui_c3 @ 20158f28 (120 bytes)

/* 0xC3 UI state frame to MAIN */

void mainlink_send_ui_c3(void *param_1,uint param_2)

{
  undefined4 local_38;
  undefined1 auStack_34 [36];
  
  __aeabi_memclr4(auStack_34,0x1e);
  local_38 = 0xc3;
  memcpy((int)&local_38 + 1,param_2,0x21);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_38,0x22);
  }
  memcpy((int)param_1 + 1,param_2,0x21);
  *(undefined1 *)param_1 = (undefined1)local_38;
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
  short local_14 [2];
  short local_10 [2];
  
  FUN_20159320();
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    gui_update_layers();
    local_14[0] = 0;
    local_10[0] = 0;
    pointer_get_event(local_20,1);
    touch_cal_apply((int)(short)local_20._4_4_,(int)(short)local_20._8_4_,local_14,local_10);
    if (local_20[0] == '\x02' || local_20[0] == '\x04') break;
    if (local_20[0] == '\x05' || local_20[0] == '\x06') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
  }
  return;
}


// ===== FUN_20159058 @ 20159058 (232 bytes)

void FUN_20159058(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  gui_update_layers();
  if (*(int *)(param_2 + 8) != 2) {
    uVar2 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(uVar2,0,0,800,0x1e0);
    gui_draw_text_centered(uVar2,0x204280a8,100,400,0xc,0x208038c0);
    do {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  bootloader_screen(param_1,param_2);
  return;
}


// ===== update_error_screen @ 20159158 (428 bytes)

/* "UPDATE ERROR", waits for a touch */

void update_error_screen(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  short sVar8;
  short sVar9;
  undefined1 auStack_74 [68];
  char local_30 [16];
  
  __aeabi_memcpy4(auStack_74,"UPDATE ERROR",0x44);
  confirm_dialog_draw(1,1,1,0,0x105,0xbf,(int)auStack_74);
  uVar6 = **(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4) + 0x119 & 0xffff;
  uVar5 = (*(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4))[1] + 0x11d & 0xffff;
  FUN_20159320();
  do {
    FUN_201218a4();
    if (DAT_20800493 != '\0') {
      FUN_20117030();
    }
    uVar4 = 0;
    uVar3 = 0;
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,(short *)&stack0xffffff80,
                    (short *)&stack0xffffff84);
    sVar9 = (short)uVar3;
    sVar8 = (short)uVar4;
    if ((local_30[0] == '\x02' || local_30[0] == '\x04') ||
       (local_30[0] == '\x05' || local_30[0] == '\x06')) {
      mouse_cursor_set_pos(uVar4 & 0xffff,uVar3 & 0xffff);
      uVar3 = (uint)sVar8;
      bVar7 = SBORROW4(uVar3,0x119);
      iVar1 = uVar3 - 0x119;
      uVar4 = 0x119;
      if (0x118 < (int)uVar3) {
        bVar7 = SBORROW4(uVar6,uVar3);
        iVar1 = uVar6 - uVar3;
        uVar4 = uVar6;
      }
      if (((uVar3 != uVar4 && iVar1 < 0 == bVar7) && (0x11c < sVar9)) && ((int)sVar9 < (int)uVar5))
      {
        return;
      }
    }
    pointer_get_event(local_30,0);
    uVar4 = (uint)(short)local_30._4_4_;
    uVar3 = (uint)(short)local_30._8_4_;
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
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== FUN_20159320 @ 20159320 (28 bytes)

void FUN_20159320(void)

{
  undefined1 auStack_10 [12];
  
  pointer_get_event(auStack_10,1);
  return;
}


// ===== FUN_2015933c @ 2015933c (76 bytes)

void FUN_2015933c(void)

{
  undefined1 auStack_4c [68];
  
  __aeabi_memcpy4(auStack_4c,"INSERT FIRMWARE",0x44);
  confirm_dialog_draw(1,1,3,0,0xe6,0xb7,(int)auStack_4c);
  return;
}


// ===== bootloader_screen @ 2015938c (552 bytes)

/* YAESU FT-710 BOOT LOADER V01-02 */

void bootloader_screen(undefined4 param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_20808540;
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  FUN_2010da68();
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,8,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,iVar3,8,400,0xc,0x20803a40);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uVar2,(&DAT_2080856c)[uVar4],uVar4 * 0x20 + 100,400,0xc,0x208038c0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  gui_update_layers();
  DAT_20808532 = 1;
  uVar2 = bootloader_unlock_wait();
  if (DAT_20800493 == '\0') {
    bVar1 = usbkbd_last_key();
    fwupdate_set_hotkey(bVar1);
    iVar3 = sd_state_bit7();
    if (iVar3 == 0) {
      uVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_clear_rect(uVar4,100,0,800,0x17c);
      gui_draw_text_centered(uVar4,DAT_2080856c,100,400,0xc,0x208038c0);
      gui_update_layers();
    }
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
    if (uVar2 != 0) {
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


// ===== fw_installed_versions_set @ 201595f0 (64 bytes)

/* installed versions from the MAIN 0x60 frame (this = update-UI object, r1 = frame) */

void fw_installed_versions_set(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  
  uVar1 = be16_load(param_2);
  *param_1 = uVar1;
  uVar1 = be16_load(param_2 + 2);
  param_1[1] = uVar1;
  uVar1 = be16_load(param_2 + 4);
  param_1[2] = uVar1;
  uVar1 = be16_load(param_2 + 10);
  param_1[3] = uVar1;
  return;
}


// ===== FUN_20159630 @ 20159630 (220 bytes)

void FUN_20159630(void)

{
  char local_28 [12];
  ushort local_1c [2];
  ushort local_18 [4];
  
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    FUN_201218a4();
    local_1c[0] = 0;
    local_18[0] = 0;
    pointer_get_event(local_28,1);
    touch_cal_apply((int)(short)local_28._4_4_,(int)(short)local_28._8_4_,(short *)local_1c,
                    (short *)local_18);
    if ((local_28[0] == '\x02' || local_28[0] == '\x04') ||
       (local_28[0] == '\x05' || local_28[0] == '\x06')) {
      mouse_cursor_set_pos((uint)local_1c[0],(uint)local_18[0]);
      return;
    }
    pointer_get_event(local_28,0);
    if (local_28[0] == '\x02' || local_28[0] == '\x04') {
      return;
    }
    if (local_28[0] == '\x05' || local_28[0] == '\x06') break;
    if (DAT_20808533 != '\0') {
      DAT_20808533 = 0;
      return;
    }
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
  }
  return;
}


// ===== fwupdate_screen @ 20159714 (1376 bytes)

/* MAIN/DISPLAY FIRMWARE UPDATE, STEP 1 of 2 (this = update-UI object) */

void fwupdate_screen(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_288 [288];
  undefined1 auStack_168 [72];
  char cStack_120;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  uStack_28 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808564)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  gui_update_layers();
  FUN_20158fd0();
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  do {
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_20808538,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    fwfile_check_versions(param_1 + 8);
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(undefined4 *)(param_1 + 0x84) = 1;
    fwfile_status_text(param_1 + 8,1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    if (iVar3 != 0) {
      if ((*(char *)(param_1 + 8) == '\x01') && (*(char *)(param_1 + 0x50) == '\x01')) break;
      fb_clear_rect(uStack_28,0x132,0,800,0xae);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 8) == '\x01') {
        sprintf(&uStack_48,"[ OK ]");
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x1d);
      }
      gui_draw_text_words(uStack_28,0x204280ef,0x132,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x132,0x1a4,0xf,0x20800b1c);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 0x50) == '\x01') {
        sprintf(&uStack_48,"[ OK ] %s",param_1 + 0x8c);
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x65);
      }
      gui_draw_text_words(uStack_28,0x2042810c,0x152,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x152,0x1a4,0xf,0x20800b1c);
      gui_draw_text_centered(uStack_28,DAT_2080853c,0x192,400,0xf,0x20800b1c);
    }
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit6();
    while (iVar3 != 0) {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      iVar3 = sd_state_bit6();
    }
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_2080856c,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
  } while( true );
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  gui_draw_text_centered(uStack_28,0x20428122,0x132,400,0xf,0x20800b1c);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808548)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
  bVar1 = 0xff;
  while( true ) {
    bVar2 = fwupdate_poll(param_1 + 8);
    iVar3 = sd_state_bit6();
    if (iVar3 == 0) break;
    if ((bVar1 != bVar2) ||
       (iVar3 = memcmp(param_1 + 8,auStack_288,0x120), bVar1 = bVar2, iVar3 != 0)) {
      __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
      if (*(char *)(param_1 + 8) == '\x04') {
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x40) & 0xffff,
                   *(uint *)(param_1 + 0x40));
      }
      else if (*(char *)(param_1 + 0x50) == '\x04') {
        if (cStack_120 != '\x04') {
          fb_clear_rect(uStack_28,0x132,0,800,0xae);
          gui_draw_text_centered(uStack_28,0x2042812f,0x132,400,0xf,0x20800b1c);
          uVar4 = 0;
          do {
            gui_draw_text_centered
                      (uStack_28,(&DAT_20808550)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c);
            uVar4 = uVar4 + 1 & 0xff;
          } while (uVar4 < 2);
        }
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x88) & 0xffff,
                   *(uint *)(param_1 + 0x88));
        gui_update_layers();
        fb_get_layer_addr(DAT_208085bc);
      }
      __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
      if (bVar2 != 0) goto LAB_20159c44;
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      bVar1 = bVar2;
    }
  }
  bVar2 = 2;
LAB_20159c44:
  FUN_2010e4a0();
  if (bVar2 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== bootloader_unlock_wait @ 20159cb0 (216 bytes)

/* key-6 mode: > 4 encoder steps -> loader-install mode */

uint bootloader_unlock_wait(void)

{
  uint uVar1;
  char local_30 [12];
  short local_24 [2];
  short local_20 [4];
  
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
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,local_24,local_20);
    if (local_30[0] == '\x02' || local_30[0] == '\x04') {
      return 0;
    }
    if (local_30[0] == '\x05' || local_30[0] == '\x06') break;
    pointer_get_event(local_30,0);
    itron_tslp_tsk(0xffffffff);
  }
  return 0;
}


// ===== FUN_20159d98 @ 20159d98 (956 bytes)

void FUN_20159d98(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
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
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_20800494 != '\0') {
    mainlink_send_e6(0);
  }
  DAT_20800496 = 1;
  DAT_20800495 = 0;
LAB_20159dec:
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  FUN_201218a4();
  fwupdate_menu_screen(param_1,0,local_2c);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (*(char *)(param_1 + 0x128) == -0x3d) {
    __aeabi_memclr4(local_4b8,0x240);
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
        iVar1 = fb_get_layer_addr(DAT_208085bc);
        fb_clear_rect_checked(iVar1,0x19a,0x1a4,0x17c,0x46);
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
      if ((DAT_20800494 == '\0') || (mainlink_send_e6(0), DAT_20808530 == '\0')) goto LAB_2015a100;
      local_4b3 = 10;
      FUN_2015b748(param_1,local_4b8);
      gui_update_layers();
      iVar2 = FUN_2015a17c(param_1);
      if (iVar2 == 0) goto LAB_20159f50;
      mainlink_send_e6(0);
      if (DAT_20808531 != '\0') goto LAB_2015a100;
      goto LAB_20159dec;
    }
    if (DAT_20800494 != '\0') {
      __aeabi_memclr4(auStack_278,0x240);
      local_273 = 0xb;
      FUN_2015b450(param_1,auStack_278,local_2c);
      gui_update_layers();
      iVar1 = FUN_2015a910(param_1,auStack_278,local_2c);
      if (iVar1 == 0) {
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      goto LAB_2015a100;
    }
    uVar3 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect_checked(uVar3,0x19a,0,800,0x46);
    gui_draw_text_centered(uVar3,DAT_2080853c,0x1a7,400,0xc,0x208038c0);
    iVar1 = sd_state_bit6();
    while (iVar1 != 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      iVar1 = sd_state_bit6();
    }
  }
LAB_2015a040:
  if (DAT_20800494 != '\0') {
    FUN_2015933c();
    FUN_20159630();
    if (DAT_20800493 == '\0') {
      mainlink_send_e6(0);
    }
LAB_2015a100:
    layer_alpha_rect_opaque(5);
    if ((DAT_20800494 != '\0') && (DAT_20808531 == '\0')) {
      DAT_20800494 = 0;
      return;
    }
    fwupdate_progress_screen(param_1,0,local_2c);
    do {
      gui_update_layers();
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect_checked(uVar3,0x1a,0,800,0x1c6);
  gui_draw_text_centered(uVar3,DAT_2080856c,100,400,0xc,0x208038c0);
  layer_alpha_rect_opaque(5);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar2 = sd_state_bit7();
  while (iVar2 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
    iVar2 = sd_state_bit7();
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
  ushort local_2a0 [2];
  ushort local_29c [2];
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
  __aeabi_memclr4(auStack_298,0x240);
  sVar5 = DAT_20808536;
  iVar4 = 10;
  FUN_20159320();
  local_58 = 0xfa;
  local_54 = *DAT_20802294 + 0xfa & 0xffff;
  uVar7 = *DAT_20802294 + 0x1a4 & 0xffff;
  uVar8 = DAT_20802294[1] + 0x19a & 0xffff;
  uVar6 = DAT_20802294[1] + 0x19a & 0xffff;
  do {
    iVar1 = sd_state_bit7();
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
      mainlink_send_ui_c3((void *)(local_28 + 0x128),(uint)&local_58);
      return 0;
    }
    FUN_201218a4();
    if (DAT_20800493 != '\0') {
      return 0;
    }
    gui_update_layers();
    local_29c[0] = 0;
    local_2a0[0] = 0;
    pointer_get_event(local_34,1);
    touch_cal_apply((int)(short)local_34._4_4_,(int)(short)local_34._8_4_,(short *)local_29c,
                    (short *)local_2a0);
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      mouse_cursor_set_pos((uint)local_29c[0],(uint)local_2a0[0]);
      uVar2 = (uint)(short)local_29c[0];
      if ((local_58 <= (int)uVar2) && ((int)uVar2 < (int)local_54)) {
        iVar3 = (int)(short)local_2a0[0];
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
        iVar3 = (int)(short)local_2a0[0];
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
    pointer_get_event(local_34,0);
    local_29c[0] = (ushort)local_34._4_4_;
    uVar2 = (uint)(short)local_29c[0];
    local_2a0[0] = (ushort)local_34._8_4_;
    iVar1 = (int)(short)local_2a0[0];
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
    mouse_right_get_event(local_34);
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
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== FUN_2015a4c8 @ 2015a4c8 (52 bytes)

void FUN_2015a4c8(void)

{
  touch_set_up();
  mouse_set_up();
  if (DAT_20800494 != '\0') {
    mainlink_send_touch_key(0,0xffff);
  }
  FUN_20159320();
  return;
}


// ===== fwupdate_menu_screen @ 2015a500 (964 bytes)

/* file list, CRC check, pre-marks newer versions */

void fwupdate_menu_screen(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
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
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(uVar2,param_3,4,400,0xf,0x20800cac);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
  iVar3 = sd_state_bit7();
  if (iVar3 == 0) {
    local_38 = 0;
    local_4c = 0x447;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_4c);
    return;
  }
  fwfile_check_versions(param_1 + 8);
  iVar3 = 0;
  do {
    iVar4 = param_1 + iVar3 * 0x48;
    gui_draw_text(local_4c,iVar4 + 9,iVar3 * 0x44 + 0x41U & 0xffff,0xc4);
    gui_draw_text(local_4c,iVar4 + 0x1d,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  gui_update_layers();
  fb_get_layer_addr(DAT_208085bc);
  gui_scope_draw_hold_set(1);
  uVar2 = fwfile_status_text(param_1 + 8,0);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
  FUN_20133620();
  gui_scope_draw_hold_set(0);
  itron_dly_tsk(0x32);
  iVar3 = sd_state_bit6();
  if (iVar3 != 0) {
    if (uVar2 != 1 && uVar2 != 3) {
      iVar3 = 0x47;
      local_5c = 0;
      local_6c = 0;
      local_68 = 0;
      if (uVar2 == 0) {
        iVar3 = 0;
      }
      local_64 = 0;
      local_70._0_2_ = CONCAT11((char)uVar2,0x47);
      local_70 = (uint)(ushort)local_70;
      local_60 = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      if (uVar2 == 0) {
        do {
          iVar4 = param_1 + iVar3 * 0x48;
          if (*(char *)(iVar4 + 8) == '\x01') {
            local_70._0_3_ =
                 CONCAT12(local_70._2_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(ushort)local_70);
            local_70 = (uint)(uint3)local_70;
          }
          if (*(char *)(iVar4 + 8) == '\x03') {
            local_6c = (uint)(byte)((byte)local_6c | (byte)(1 << (7U - iVar3 & 0xff)));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 4);
      }
      iVar3 = 0;
      do {
        sprintf(&stack0xffffff88,&DAT_2042813c,*(undefined2 *)(param_1 + iVar3 * 2));
        iVar4 = FUN_2014e208(param_1 + iVar3 * 0x48 + 0x31,&stack0xffffff88);
        if (0 < iVar4) {
          local_70 = CONCAT13(local_70._3_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(uint3)local_70);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_70);
      iVar3 = 0;
      do {
        uVar2 = iVar3 * 0x44 + 0x41;
        fb_fill_rect(local_4c,0x821,uVar2 & 0xffff,0x25c,800,0x1a);
        iVar4 = param_1 + iVar3 * 0x48;
        gui_draw_text(local_4c,iVar4 + 9,uVar2 & 0xffff,0xc4);
        gui_draw_text(local_4c,iVar4 + 0x1d,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      FUN_2015a4c8();
      return;
    }
    local_38 = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_4c = (uint)CONCAT11((char)uVar2,0x47);
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_4c);
    return;
  }
  mainlink_send_ui_e2((void *)(param_1 + 0x128),(uint)&stack0xffffff88);
  return;
}


// ===== FUN_2015a8dc @ 2015a8dc (52 bytes)

/* WARNING: Removing unreachable block (ram,0x2015b1d4) */
/* WARNING: Removing unreachable block (ram,0x2015b4d4) */

void FUN_2015a8dc(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  bool bVar8;
  char acStack_270 [288];
  undefined1 auStack_150 [288];
  uint uVar9;
  
  cVar1 = *(char *)(param_2 + 2);
  if (cVar1 == '\x01') {
    uVar9 = fb_get_layer_addr(DAT_208085bc);
    uVar7 = (uint)*(byte *)(param_2 + 5);
    fb_clear_rect(uVar9,0,0,800,0x1e0);
    fb_fill_rect(uVar9,0x3186,2,2,0x31a,0x18);
    gui_draw_runs(uVar9,4,400,&DAT_2016dc08);
    gui_draw_text_centered(uVar9,DAT_20808540,4,400,0xf,0x20800cac);
    uVar3 = 0;
    do {
      uVar5 = 1 << (7 - uVar3 & 0xff);
      if ((*(byte *)(param_2 + 3) & uVar5) != 0) {
        iVar4 = uVar3 * 0x44 + 0x32;
        fb_clear_rect(uVar9,iVar4,0x75,0x78,0x43);
        if ((*(byte *)(param_2 + 4) & uVar5) == 0) {
          puVar6 = (undefined2 *)&DAT_203a5684;
          *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 0;
        }
        else {
          puVar6 = &DAT_203a5694;
          *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 1;
        }
        gui_draw_runs(uVar9,iVar4,0x75,puVar6);
        if (uVar3 == uVar7) {
          FUN_20136398(uVar9,iVar4,0x75,*puVar6);
        }
      }
      iVar4 = param_1 + uVar3 * 0x48;
      gui_draw_text(uVar9,iVar4 + 9,uVar3 * 0x44 + 0x41,0xc4);
      gui_draw_text(uVar9,iVar4 + 0x1d,uVar3 * 0x44 + 0x43,0x1dc);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 4);
    FUN_20126914(uVar9,0x19a,0xfa,2);
    if (*(char *)(param_2 + 4) == '\0') {
      gui_draw_runs(uVar9,0x1a6,0x10f,&DAT_20255114);
    }
    else {
      gui_draw_runs(uVar9,0x1a6,0x10f,&DAT_20254600);
    }
    if (uVar7 == 10) {
      FUN_20136398(uVar9,0x19a,0xfa,*DAT_20802294);
    }
    if (DAT_20800494 != '\0') {
      FUN_20126914(uVar9,0x19a,0x1a4,2);
      gui_draw_runs(uVar9,0x1a6,0x1b9,&DAT_20251ec8);
      if (uVar7 == 0xb) {
        FUN_20136398(uVar9,0x19a,0x1a4,*DAT_20802294);
      }
    }
    return;
  }
  if (cVar1 == '\x02') {
    uVar9 = fb_get_layer_addr(DAT_208085bc);
    cVar1 = *(char *)(param_2 + 5);
    fb_clear_rect(uVar9,0,0,800,0x1e0);
    fb_fill_rect(uVar9,0x3186,2,2,0x31a,0x18);
    gui_draw_runs(uVar9,4,400,&DAT_2016dc08);
    gui_draw_runs(uVar9,8,0x168,&DAT_203a56b4);
    gui_draw_text_centered(uVar9,0x20428153,0xf0,400,0xf,0x20800cac);
    FUN_20126914(uVar9,0x19a,0xfa,2);
    gui_draw_runs(uVar9,0x1a6,0x10f,&DAT_20253aec);
    if (cVar1 == '\n') {
      FUN_20136398(uVar9,0x19a,0xfa,*DAT_20802294);
    }
    FUN_20126914(uVar9,0x19a,0x1a4,2);
    gui_draw_runs(uVar9,0x1a6,0x1b9,&DAT_20251ec8);
    if (cVar1 == '\v') {
      FUN_20136398(uVar9,0x19a,0x1a4,*DAT_20802294);
    }
    return;
  }
  if (cVar1 != '\x03') {
    return;
  }
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  mouse_detach_post();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_clear_rect(uVar3,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar3,4,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar3,DAT_20808540,4,400,0xf,0x20800cac);
  gui_draw_text_centered(uVar3,DAT_20808544,0x1a7,400,0xf,0x20800cac);
  uVar9 = 0xff;
  __aeabi_memcpy4(acStack_270,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
  gui_scope_draw_hold_set(1);
  while( true ) {
    bVar2 = fwupdate_poll(param_1 + 8);
    uVar7 = (uint)bVar2;
    iVar4 = sd_state_bit6();
    if (iVar4 == 0) break;
    bVar8 = uVar9 != uVar7;
    uVar9 = uVar7;
    if ((bVar8) || (iVar4 = memcmp(param_1 + 8,auStack_150,0x120), iVar4 != 0)) {
      __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
      uVar5 = 0;
      do {
        iVar4 = param_1 + uVar5 * 0x48;
        gui_draw_text(uVar3,iVar4 + 9,uVar5 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar1 = *(char *)(iVar4 + 8);
        if (cVar1 == '\x04') {
          if (acStack_270[uVar5 * 0x48] != '\x04') {
            fb_clear_rect(uVar3,uVar5 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_progress_bar
                    (uVar3,uVar5 * 0x44 + 0x42,0x1dc,*(uint *)(iVar4 + 0x40) & 0xffff,
                     *(uint *)(iVar4 + 0x40));
        }
        else {
          if (cVar1 == '\x05') {
            if (acStack_270[uVar5 * 0x48] != '\x05') {
              fb_clear_rect(uVar3,uVar5 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(uVar3,uVar5 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar1 != acStack_270[uVar5 * 0x48]) {
            fb_clear_rect(uVar3,uVar5 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_text(uVar3,iVar4 + 0x1d,uVar5 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 4);
      __aeabi_memcpy4(acStack_270,param_1 + 8,0x120);
      if (uVar7 != 0) goto LAB_2015b360;
      gui_update_layers();
      uVar3 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  uVar7 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (uVar7 != 1) {
    update_error_screen();
  }
  system_reboot();
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
  ushort local_2a8 [2];
  ushort local_2a4 [2];
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
  __aeabi_memclr4(auStack_2a0,0x240);
  memcpy(auStack_2a0,param_2,0x240);
LAB_2015a994:
  iVar4 = sd_state_bit7();
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
    mainlink_send_ui_c3((void *)(local_30 + 0x128),(uint)&local_60);
    return 0;
  }
  FUN_201218a4();
  if (DAT_20800493 != '\0') {
    return 0;
  }
  gui_update_layers();
  local_2a8[0] = 0;
  local_2a4[0] = 0;
  pointer_get_event(local_48 + 0xc,1);
  touch_cal_apply((int)(short)local_48._16_4_,(int)(short)local_48._20_4_,(short *)local_2a8,
                  (short *)local_2a4);
  if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
     (local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
    mouse_cursor_set_pos((uint)local_2a8[0],(uint)local_2a4[0]);
    if ((local_29c != 0) &&
       ((((local_58 <= (short)local_2a8[0] && ((int)(short)local_2a8[0] < (int)local_50)) &&
         (0x199 < (short)local_2a4[0])) && ((int)(short)local_2a4[0] < (int)local_54)))) {
      DAT_20808530 = 1;
      return 1;
    }
    if (DAT_20800494 != '\0') {
      uVar5 = (uint)(short)local_2a8[0];
      bVar17 = SBORROW4(uVar5,local_5c);
      iVar4 = uVar5 - local_5c;
      uVar7 = local_5c;
      if ((int)local_5c <= (int)uVar5) {
        bVar17 = SBORROW4(uVar14,uVar5);
        iVar4 = uVar14 - uVar5;
        uVar7 = uVar14;
      }
      if (uVar5 != uVar7 && iVar4 < 0 == bVar17) {
        puVar6 = (uint *)(int)(short)local_2a4[0];
        bVar17 = SBORROW4((int)puVar6,(int)local_60);
        iVar4 = (int)puVar6 - (int)local_60;
        puVar8 = local_60;
        if ((int)local_60 <= (int)puVar6) {
          bVar17 = SBORROW4((int)puVar13,(int)puVar6);
          iVar4 = (int)puVar13 - (int)puVar6;
          puVar8 = puVar13;
        }
        if (puVar6 != puVar8 && iVar4 < 0 == bVar17) {
          mainlink_send_e6(0);
          DAT_20808530 = 0;
          return 1;
        }
      }
    }
    uVar7 = 0;
    do {
      iVar4 = uVar7 * 0x44 + 0x32;
      iVar10 = uVar7 * 0x44 + 0x75;
      if (((((uint)local_29d & 1 << (7 - uVar7 & 0xff)) != 0) && (0x74 < (short)local_2a8[0])) &&
         ((short)local_2a8[0] < 0xed)) {
        iVar15 = (int)(short)local_2a4[0];
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
            mainlink_send_e6(0);
          }
          break;
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 4);
  }
  pointer_get_event(local_48 + 0xc,0);
  local_2a8[0] = (ushort)local_48._16_4_;
  iVar4 = (int)(short)local_2a8[0];
  local_2a4[0] = (ushort)local_48._20_4_;
  puVar8 = (uint *)(int)(short)local_2a4[0];
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
              mainlink_send_e6(0);
            }
            break;
          }
        }
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 4);
    }
    mouse_right_get_event(local_48 + 0xc);
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
        mainlink_send_e6(0);
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
        mainlink_send_e6(0);
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
  itron_tslp_tsk(0xffffffff);
  param_2 = uVar7;
  goto LAB_2015a994;
}


// ===== fwupdate_insert_sd_screen @ 2015afb0 (356 bytes)

/* INSERT FIRMWARE SD CARD screen (MAIN timeout path, docs/code/display/gui.md) */

void fwupdate_insert_sd_screen(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_278 [14];
  char cStack_26a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(uVar2,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uVar2,(&DAT_20808558)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,0x20800b1c);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  mainlink_get_frame60((uint)auStack_278);
  if ((cStack_26a != '\x01' && cStack_26a != '\x02') && (cStack_26a != '\x03')) {
    cStack_26a = '\x01';
  }
  sprintf(&uStack_38,"ERROR CODE : %03d",cStack_26a);
  gui_draw_text_centered(uVar2,(int)&uStack_38,0x192,400,0xf,0x20800b1c);
  gui_update_layers();
  key_task_resume();
  DAT_20808532 = 1;
  FUN_20158fd0();
  if (DAT_20800493 == '\0') {
    bVar1 = usbkbd_last_key();
    fwupdate_set_hotkey(bVar1);
    iVar3 = fb_get_layer_addr(DAT_208085b8);
    fb_clear_rect(iVar3,0,0,800,0x1e0);
    iVar3 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(iVar3,0,0,800,0x1e0);
    gui_update_layers();
    bootloader_screen(param_1,&DAT_208dbb44);
    DAT_20808532 = 0;
  }
  return;
}


// ===== fwupdate_progress_screen @ 2015b134 (764 bytes)

/* progress rows, error screen, update_finish_reset */

void fwupdate_progress_screen(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  char local_270 [288];
  undefined1 auStack_150 [288];
  uint local_30;
  uint local_2c;
  
  local_30 = fb_get_layer_addr(DAT_208085bc);
  mouse_detach_post();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_clear_rect(local_30,0,0,800,0x1e0);
  fb_fill_rect(local_30,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(local_30,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(local_30,param_3,4,400,0xf,0x20800cac);
  gui_draw_text_centered(local_30,DAT_20808544,0x1a7,400,0xf,0x20800cac);
  local_2c = 0xff;
  __aeabi_memcpy4(local_270,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
  gui_scope_draw_hold_set(1);
  while( true ) {
    bVar2 = fwupdate_poll(param_1 + 8);
    uVar5 = (uint)bVar2;
    iVar3 = sd_state_bit6();
    if (iVar3 == 0) break;
    bVar6 = local_2c != uVar5;
    local_2c = uVar5;
    if ((bVar6) || (iVar3 = memcmp(param_1 + 8,auStack_150,0x120), iVar3 != 0)) {
      __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
      uVar4 = 0;
      do {
        iVar3 = param_1 + uVar4 * 0x48;
        gui_draw_text(local_30,iVar3 + 9,uVar4 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar1 = *(char *)(iVar3 + 8);
        if (cVar1 == '\x04') {
          if (local_270[uVar4 * 0x48] != '\x04') {
            fb_clear_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_progress_bar
                    (local_30,uVar4 * 0x44 + 0x42,0x1dc,*(uint *)(iVar3 + 0x40) & 0xffff,
                     *(uint *)(iVar3 + 0x40));
        }
        else {
          if (cVar1 == '\x05') {
            if (local_270[uVar4 * 0x48] != '\x05') {
              fb_clear_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(local_30,uVar4 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar1 != local_270[uVar4 * 0x48]) {
            fb_clear_rect(local_30,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_text(local_30,iVar3 + 0x1d,uVar4 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 4);
      __aeabi_memcpy4(local_270,param_1 + 8,0x120);
      if (uVar5 != 0) goto LAB_2015b360;
      gui_update_layers();
      local_30 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  uVar5 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (uVar5 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== FUN_2015b450 @ 2015b450 (708 bytes)

void FUN_2015b450(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar6 = (uint)*(byte *)(param_2 + 5);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(uVar2,param_3,4,400,0xf,0x20800cac);
  uVar3 = 0;
  do {
    uVar1 = 1 << (7 - uVar3 & 0xff);
    if ((*(byte *)(param_2 + 3) & uVar1) != 0) {
      iVar5 = uVar3 * 0x44 + 0x32;
      fb_clear_rect(uVar2,iVar5,0x75,0x78,0x43);
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
    gui_draw_text(uVar2,iVar5 + 9,uVar3 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
    gui_draw_text(uVar2,iVar5 + 0x1d,uVar3 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
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
  uint uVar2;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  cVar1 = *(char *)(param_2 + 5);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  gui_draw_runs(uVar2,8,0x168,&DAT_203a56b4);
  gui_draw_text_centered(uVar2,0x20428153,0xf0,400,0xf,0x20800cac);
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
  scope3d_draw_line(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,
                    uVar4,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== FUN_2015b9a8 @ 2015b9a8 (28 bytes)

void FUN_2015b9a8(void)

{
  FUN_20134310();
  __aeabi_memclr_veneer(DAT_208085b4,0x6b080);
  return;
}


// ===== scope3d_render_large @ 2015b9cc (240 bytes)

/* mode 8: 29 lines, 222/274 rows */

void scope3d_render_large(void *param_1,uint param_2,int param_3,ushort *param_4,uint param_5)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  int unaff_r7;
  bool bVar4;
  ulonglong uVar5;
  undefined4 local_28;
  
  bVar4 = param_3 == 0;
  if (!bVar4) {
    unaff_r7 = (int)param_1 + 0x7c;
  }
  local_28 = 0;
  if (bVar4) {
    unaff_r7 = (int)param_1 + 4;
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
  scope_history_push((uint)DAT_208085b0,&local_28);
  scope3d_add_line(8,(uint)DAT_208085b0,param_3);
  uVar5 = __aeabi_idivmod(param_2,(uint)DAT_208085b0);
  if ((int)(uVar5 >> 0x20) == 0) {
    scope3d_redraw_history(8,param_3);
  }
  __aeabi_memclr(*(undefined4 *)param_1,0x6b080);
  iVar2 = 1;
  do {
    (*pcVar3)(*(undefined4 *)param_1,iVar2,*(uint *)(unaff_r7 + iVar2 * 4) & 0xffff,4,8,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1e);
  if (param_3 == 0) {
    sVar1 = 0xde;
  }
  else {
    sVar1 = 0x112;
  }
  memcpy(param_5,*(undefined4 *)param_1,sVar1 * 0x640);
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
  scope3d_draw_line(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,
                    uVar4,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== scope3d_render_small @ 2015bb7c (236 bytes)

/* mode 9: 14 lines, 104/156 rows */

void scope3d_render_small(void *param_1,uint param_2,int param_3,ushort *param_4,uint param_5)

{
  short unaff_r4;
  int iVar1;
  int unaff_r6;
  undefined4 uVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined4 local_28;
  
  bVar3 = param_3 != 0;
  if (bVar3) {
    unaff_r6 = (int)param_1 + 0x130;
  }
  local_28 = 0;
  if (bVar3) {
    unaff_r4 = 0x9c;
  }
  if (!bVar3) {
    unaff_r6 = (int)param_1 + 0xf4;
    unaff_r4 = 0x68;
  }
  if (3 < *param_4) {
    local_28 = CONCAT22(param_4[1],*param_4);
  }
  scope_history_push((uint)DAT_208085b0,&local_28);
  scope3d_add_line(9,(uint)DAT_208085b0,param_3);
  uVar4 = __aeabi_idivmod(param_2,(uint)DAT_208085b0);
  if ((int)(uVar4 >> 0x20) == 0) {
    scope3d_redraw_history(9,param_3);
  }
  uVar2 = *(undefined4 *)param_1;
  __aeabi_memclr(uVar2,unaff_r4 * 0x640);
  iVar1 = 1;
  do {
    FUN_2015b8f8(*(undefined4 *)param_1,iVar1,*(uint *)(unaff_r6 + iVar1 * 4) & 0xffff,4,9,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  memcpy(param_5,uVar2,unaff_r4 * 0x640);
  return;
}


// ===== scope3d_draw_line @ 2015bc6c (484 bytes)

/* WARNING: Type propagation algorithm not settling */
/* line i at x = 5i+4, width 791-10i */

void scope3d_draw_line(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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

