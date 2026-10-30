// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff981ba @ fff981ba (158 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9820f) */
/* WARNING: Removing unreachable block (ram,0xfff981d4) */
/* WARNING: Removing unreachable block (ram,0xfff981df) */

void FUN_fff981ba(char param_1,int param_2,char param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  byte bStack_19;
  uint uStack_14;
  
  dest_code_get();
  uStack_14 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                         *(undefined1 *)(param_2 + 0x4b)),
                                *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
  if ((param_3 == '\x01') || (param_3 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_14 = uStack_14 +
                (int)CONCAT11(*(undefined1 *)(param_2 + 0x48),*(undefined1 *)(param_2 + 0x49));
  }
  bVar2 = vfo_tune_locked(param_1);
  if (bVar2 == 1) {
    if (param_1 == '\0') {
      bStack_19 = g_mem_hdr.chan_a;
    }
    else {
      bStack_19 = g_mem_hdr.chan_b;
    }
    uStack_14 = FUN_fff9cba4(uStack_14,bStack_19);
  }
  FUN_fff9ca42(uStack_14,param_4);
  return;
}


// ===== FUN_fff98258 @ fff98258 (82 bytes)

void FUN_fff98258(vfo_side param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bStack_15;
  uint local_14;
  
  local_14 = PTR_g_ui_00025d38->freq_tx;
  bVar1 = vfo_tune_locked(param_1);
  if (bVar1 == 1) {
    if (param_1 == VFO_A) {
      bStack_15 = g_mem_hdr.chan_a;
    }
    else {
      bStack_15 = g_mem_hdr.chan_b;
    }
    local_14 = FUN_fff9cba4(local_14,bStack_15);
  }
  FUN_fff9ca42(local_14,param_4);
  return;
}


// ===== FUN_fff982aa @ fff982aa (17 bytes)

void FUN_fff982aa(byte param_1,uint param_2,uint param_3)

{
  FUN_fff982bb(param_1,param_2);
  return;
}


// ===== FUN_fff982bb @ fff982bb (72 bytes)

void FUN_fff982bb(vfo_side param_1,undefined4 param_2)

{
  if (param_1 == g_opstate.active_vfo) {
    FUN_fff98303(param_1,param_2);
    return;
  }
  if (PTR_g_ui_00025d38->popup7_open != 1) {
    FUN_fff98303(param_1,param_2);
    return;
  }
  FUN_fff98363(param_1,PTR_g_ui_00025d38->keypad_bcd,param_2);
  return;
}


// ===== FUN_fff98303 @ fff98303 (96 bytes)

void FUN_fff98303(vfo_side param_1,undefined4 param_2)

{
  undefined1 auStack_d [5];
  undefined4 local_8;
  vfo_side local_1;
  
  local_8 = param_2;
  local_1 = param_1;
  if (PTR_g_ui_00025d38->keypad_open == 0) {
    FUN_fff9810e(param_1,(uint)auStack_d);
    FUN_fff98363(local_1,auStack_d,local_8);
    return;
  }
  if (param_1 == PTR_g_ui_00025d38->status_side) {
    FUN_fff98363(param_1,PTR_g_ui_00025d38->keypad_bcd,param_2);
    return;
  }
  FUN_fff9810e(param_1,(uint)auStack_d);
  FUN_fff98363(local_1,auStack_d,local_8);
  return;
}


// ===== FUN_fff98363 @ fff98363 (283 bytes)

void FUN_fff98363(vfo_side param_1,byte *param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  byte bStack_d;
  
  if (param_1 == g_opstate.active_vfo) {
    iVar2 = FUN_fff9847e();
    if (iVar2 == 1) {
      if (PTR_g_ui_00025d38->digit_step_khz == 1) {
        bVar1 = (*param_2 & 0xf) != 0;
        if (bVar1) {
          bStack_d = *param_2 | 0xf0;
        }
        else {
          bStack_d = 0xff;
        }
        *param_3 = bStack_d;
        if ((param_2[1] & 0xf0) == 0) {
          bStack_d = param_2[1];
          if (!bVar1) {
            if ((bStack_d & 0xf) == 0) {
              bStack_d = 0xff;
            }
            else {
              bStack_d = param_2[1] | 0xf0;
            }
          }
        }
        else {
          bStack_d = param_2[1];
        }
        param_3[1] = bStack_d;
        param_3[2] = 0xff;
        param_3[3] = param_2[3] | 0xf0;
      }
      else {
        *param_3 = 0xff;
        param_3[1] = 0xff;
        param_3[2] = param_2[2];
        param_3[3] = param_2[3];
      }
    }
    else {
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      param_3[3] = param_2[3];
    }
    param_3[4] = param_2[4];
    return;
  }
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  param_3[4] = param_2[4];
  return;
}


// ===== FUN_fff9847e @ fff9847e (32 bytes)

bool FUN_fff9847e(void)

{
  return PTR_g_ui_00025d38->digit_step_blink_on != 0;
}


// ===== FUN_fff9849e @ fff9849e (136 bytes)

byte FUN_fff9849e(void)

{
  byte local_2;
  
  if (PTR_g_ui_00025d38->transmitting == 0) {
    local_2 = meter_get_s();
  }
  else if (g_opstate.meter_sel == 5) {
    if (g_ui.tune_cycle_3d == 2) {
      local_2 = meter_get_swr_raw();
    }
    else {
      local_2 = meter_get_swr();
    }
  }
  else if (g_opstate.meter_sel == 1) {
    local_2 = meter_get_comp();
  }
  else if (g_opstate.meter_sel == 2) {
    local_2 = meter_get_alc();
  }
  else if (g_opstate.meter_sel == 3) {
    local_2 = meter_get_vdd();
  }
  else if (g_opstate.meter_sel == 4) {
    local_2 = meter_get_idd();
  }
  else if (g_opstate.meter_sel == 0) {
    local_2 = meter_get_po();
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff98526 @ fff98526 (64 bytes)

byte FUN_fff98526(int param_1)

{
  undefined1 local_6;
  
  local_6 = 0;
  if ((*(byte *)(param_1 + 6) & 0x10) != 0) {
    local_6 = 0x10;
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    local_6 = local_6 | 8;
  }
  if (g_opstate.lock_on == 1) {
    local_6 = local_6 | 4;
  }
  return g_opstate.fn_select | local_6;
}


// ===== disp_put_op_freq @ fff98566 (95 bytes)

/* DISPLAY frame +0x1715: operating frequency */

void disp_put_op_freq(void *param_1)

{
  uint local_8;
  
  if (PTR_g_ui_00025d38->transmitting == 1) {
    local_8 = PTR_g_ui_00025d38->freq_dial;
  }
  else if (g_opstate.active_vfo == VFO_A) {
    local_8 = PTR_g_ui_00025d38->freq_a;
  }
  else {
    local_8 = PTR_g_ui_00025d38->freq_b;
  }
  *(char *)param_1 = (char)(local_8 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)(local_8 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)(local_8 >> 8);
  *(undefined1 *)((int)param_1 + 3) = (undefined1)local_8;
  return;
}


// ===== disp_put_tx_freq @ fff985c5 (48 bytes)

/* DISPLAY frame +0x1719: TX frequency 0x20F50 */

void disp_put_tx_freq(void *param_1)

{
  uint uVar1;
  undefined1 local_8;
  
  uVar1 = PTR_g_ui_00025d38->freq_tx;
  *(char *)param_1 = (char)(uVar1 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)(uVar1 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)(uVar1 >> 8);
  local_8 = (undefined1)uVar1;
  *(undefined1 *)((int)param_1 + 3) = local_8;
  return;
}


// ===== disp_put_dial_freq @ fff985f5 (116 bytes)

/* DISPLAY frame +0x171D: dial frequency */

void disp_put_dial_freq(void *param_1)

{
  int iVar1;
  uint local_8;
  
  if (PTR_g_ui_00025d38->transmitting == 1) {
    local_8 = PTR_g_ui_00025d38->freq_tx;
  }
  else {
    iVar1 = FUN_fff98669();
    if (iVar1 == 0) {
      local_8 = PTR_g_ui_00025d38->freq_dial;
    }
    else if (g_opstate.active_vfo == VFO_A) {
      local_8 = PTR_g_ui_00025d38->freq_a;
    }
    else {
      local_8 = PTR_g_ui_00025d38->freq_b;
    }
  }
  *(char *)param_1 = (char)(local_8 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)(local_8 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)(local_8 >> 8);
  *(undefined1 *)((int)param_1 + 3) = (undefined1)local_8;
  return;
}


// ===== FUN_fff98669 @ fff98669 (40 bytes)

byte FUN_fff98669(void)

{
  byte local_2;
  
  if (PTR_g_ui_00025d38->transmitting == 1) {
    local_2 = 1;
  }
  else {
    local_2 = g_opstate.ex040202_scope_ctr;
  }
  return local_2;
}


// ===== disp_put_scope_start @ fff98691 (79 bytes)

/* DISPLAY frame +0x1721: scope start (0x20F60 or FIX band memory) */

void disp_put_scope_start(int param_1)

{
  byte local_a;
  uint local_8;
  
  if (g_opstate.scope_mode == 2) {
    local_8 = bandmem_get('\x02');
  }
  else {
    local_8 = g_ui.scope_cursor_start;
  }
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    *(char *)((uint)local_a + param_1) = (char)(local_8 >> ((3 - local_a & 3) << 3));
  }
  return;
}


// ===== displink_tx_64 @ fff986e0 (71 bytes)

/* 0x64 (3 bytes): +0xB8 when changed */

void displink_tx_64(void)

{
  if (PTR_g_ui_00025d38->dl_64_value == PTR_g_ui_00025d38->dl_64_sent) {
    return;
  }
  PTR_g_ui_00025d38->dl_64_sent = PTR_g_ui_00025d38->dl_64_value;
  DAT_00001456 = 100;
  DAT_00001457 = PTR_g_ui_00025d38->dl_64_value;
  DAT_0001b628 = 3;
  displink_tx_start(3);
  return;
}


// ===== ui_lamp_set @ fff98727 (112 bytes)

/* set/clear one bit of UI +0x34 (status byte 8); lamp/LED meaning is inference (#179) */

void ui_lamp_set(char param_1,char param_2)

{
  byte local_3;
  
  if (param_1 == '\b') {
    local_3 = 0x20;
  }
  else if (param_1 == '\x02') {
    local_3 = 0x40;
  }
  else if (param_1 == '\x03') {
    local_3 = 0x10;
  }
  else if (param_1 == '\x04') {
    local_3 = 8;
  }
  else if (param_1 == '\x05') {
    local_3 = 4;
  }
  else if (param_1 == '\x06') {
    local_3 = 2;
  }
  else if (param_1 == '\a') {
    local_3 = 1;
  }
  else {
    if (param_1 != '\x01') {
      return;
    }
    local_3 = 0x80;
  }
  if (param_2 != '\0') {
    PTR_g_ui_00025d38->lamp_map = local_3 | PTR_g_ui_00025d38->lamp_map;
    return;
  }
  PTR_g_ui_00025d38->lamp_map = ~local_3 & PTR_g_ui_00025d38->lamp_map;
  return;
}


// ===== power_down_save @ fff98797 (210 bytes)

/* Restart/power-off request: notifies DISPLAY; code 0x90 waits 2 s, else eeprom_save_all (0x9DC5=1
   if code 0x11); then mcu_software_reset */

void power_down_save(void)

{
  byte bVar1;
  
  DAT_00001456 = 0x7f;
  DAT_00001457 = PTR_g_ui_00025d38->power_cmd & 0x7f;
  DAT_00001458 = 0x9b;
  DAT_00001459 = 0xba;
  DAT_0000145a = 0xf6;
  DAT_0000145b = 0x38;
  DAT_0000145c = 0xff;
  DAT_0000145d = 0x25;
  DAT_0000145e = 0x73;
  DAT_0000145f = 0x1f;
  DAT_0001b628 = 0xb;
  displink_tx_start(0xb);
  if (PTR_g_ui_00025d38->power_cmd == 0x90) {
    swtimer_start(0x14,2000);
    do {
      bVar1 = swtimer_expired(0x14);
    } while (bVar1 == 0);
  }
  else if (PTR_g_ui_00025d38->power_cmd == 0x11) {
    g_opstate.auto_power_on = 1;
    eeprom_save_all();
  }
  else {
    g_opstate.auto_power_on = 0;
    eeprom_save_all();
  }
  sw_reset();
  return;
}


// ===== displink_tx_7C @ fff98869 (51 bytes)

/* 0x7C (5 bytes) */

void displink_tx_7C(void)

{
  DAT_00001456 = 0x7c;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7B @ fff9889c (86 bytes)

/* 0x7B (5 bytes), toggles +0x82 */

void displink_tx_7B(void)

{
  bool bVar1;
  
  DAT_00001456 = 0x7b;
  bVar1 = PTR_g_ui_00025d38->screensaver_on == 1;
  if (bVar1) {
    PTR_g_ui_00025d38->screensaver_on = 0;
  }
  else {
    PTR_g_ui_00025d38->screensaver_on = 1;
  }
  DAT_00001457 = !bVar1;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7A @ fff988f2 (51 bytes)

/* 0x7A (5 bytes) */

void displink_tx_7A(void)

{
  DAT_00001456 = 0x7a;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_70 @ fff98925 (42 bytes)

/* 0x70 (0xE3 bytes) */

void displink_tx_70(void)

{
  byte bVar1;
  
  displink_build_70();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0xe2);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe3;
  displink_tx_start(0xe3);
  return;
}


// ===== displink_build_70 @ fff9894f (638 bytes)

void displink_build_70(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x70;
  displink_copy_status();
  switch(PTR_g_ui_00025d38->dialog_msg) {
  case 0:
    displink_70_msg(0xfff80000);
    return;
  case 1:
    DAT_000017d9 = 3;
    DAT_000017da = 2;
    DAT_000017db = PTR_g_ui_00025d38->dialog_button;
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff80016;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 2:
    displink_70_msg2(0xfff8002c);
    return;
  case 3:
    displink_70_query(0xfff80058);
    return;
  case 4:
    displink_70_query(0xfff8006e);
    return;
  case 5:
    displink_70_msg2(0xfff80084);
    return;
  case 6:
    displink_70_query(0xfff800b0);
    return;
  case 7:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_g_ui_00025d38->dialog_button;
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff800c6;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 8:
    displink_70_query(0xfff800dc);
    return;
  case 9:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_g_ui_00025d38->dialog_button;
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff800f2;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 10:
    displink_70_query(0xfff80108);
    return;
  case 0xb:
    displink_70_query(0xfff8011e);
    return;
  case 0xc:
    displink_70_query(0xfff80134);
    return;
  case 0xd:
    displink_70_query(0xfff8014a);
    return;
  case 0xe:
    displink_70_msg(0xfff80160);
    return;
  case 0xf:
    displink_70_query(0xfff80176);
    return;
  case 0x10:
    displink_70_query(0xfff8018c);
    return;
  case 0x11:
    displink_70_query(0xfff801a2);
    return;
  case 0x12:
    displink_70_query(0xfff801b8);
    return;
  case 0x13:
    displink_70_query(0xfff801ce);
    return;
  case 0x14:
    displink_70_query(0xfff801e4);
    return;
  case 0x15:
    displink_70_query(0xfff801fa);
    return;
  case 0x16:
    displink_70_query(0xfff80210);
    return;
  case 0x17:
    displink_70_msg(0xfff80252);
    return;
  case 0x18:
    displink_70_query(0xfff80176);
    return;
  case 0x19:
    displink_70_query(0xfff80226);
    return;
  case 0x1a:
    displink_70_query(0xfff8023c);
    return;
  default:
    return;
  }
}


// ===== displink_tx_req @ fff98bcd (82 bytes)

/* 0x43/0x44/0x45 request, type +0x1E0, length +0x1E2 */

void displink_tx_req(void)

{
  byte bVar1;
  
  PTR_g_ui_00025d38->dl_req_sd = 0;
  displink_build_req();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,PTR_g_ui_00025d38->sdreq_len - 1);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = PTR_g_ui_00025d38->sdreq_len;
  displink_tx_start(PTR_g_ui_00025d38->sdreq_len);
  return;
}


// ===== displink_build_req @ fff98c1f (86 bytes)

void displink_build_req(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = PTR_g_ui_00025d38->sdreq_type;
  DAT_00001742 = PTR_g_ui_00025d38->sdreq_op;
  if ((PTR_g_ui_00025d38->sdreq_op & 0xf0) == 0) {
    return;
  }
  FUN_fff98c75(2);
  return;
}


// ===== FUN_fff98c75 @ fff98c75 (94 bytes)

void FUN_fff98c75(ushort param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = PTR_g_ui_00025d38->sdreq_op - 1 & 0xf;
  if ((1 < uVar3 - 6) && (uVar3 != 4)) {
    if (uVar3 < 4) {
      uVar3 = (uint)PTR_g_ui_00025d38->sdreq_len;
      pbVar2 = &PTR_g_ui_00025d38->sdreq_arg1;
      pbVar1 = &DAT_00001741 + param_1;
      while (uVar3 = uVar3 - 1, uVar3 != 0) {
        *pbVar1 = *pbVar2;
        pbVar1 = pbVar1 + 1;
        pbVar2 = pbVar2 + 1;
      }
      return;
    }
    return;
  }
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)&PTR_g_ui_00025d38->sdreq_arg1;
  return;
}


// ===== displink_copy_status @ fff98cd3 (25 bytes)

/* build the 0x97-byte status block and copy it to staging frame bytes 1..0x97 (0x1742) (#179) */

void displink_copy_status(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  displink_build_status();
  puVar2 = &DAT_000016a1;
  puVar1 = &DAT_00001742;
  for (iVar3 = 0x97; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== displink_70_msg @ fff98cec (111 bytes)

/* 0x70 dialog: style 3, no buttons, 22 bytes of ROM text (#179) */

void displink_70_msg(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 3;
  DAT_000017da = 0;
  DAT_000017db = PTR_g_ui_00025d38->dialog_button;
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== displink_70_msg2 @ fff98d5b (111 bytes)

/* 0x70 dialog: style 1, buttons 4, 44 bytes of ROM text (#179) */

void displink_70_msg2(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 1;
  DAT_000017da = 4;
  DAT_000017db = PTR_g_ui_00025d38->dialog_button;
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x2c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== displink_70_query @ fff98dca (111 bytes)

/* 0x70 dialog: style 3, buttons 4, 22 bytes of ROM text (#179) */

void displink_70_query(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 3;
  DAT_000017da = 4;
  DAT_000017db = PTR_g_ui_00025d38->dialog_button;
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== displink_tx_23 @ fff98e39 (31 bytes)

/* 0x23 (0x37 bytes) */

void displink_tx_23(void)

{
  PTR_g_ui_00025d38->dl_req_23 = 0;
  displink_build_23();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e58 @ fff98e58 (31 bytes)

void FUN_fff98e58(void)

{
  PTR_g_ui_00025d38->dl_req_23b = 0;
  FUN_fff98ec9();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e77 @ fff98e77 (31 bytes)

void FUN_fff98e77(void)

{
  PTR_g_ui_00025d38->dl_req_23c = 0;
  FUN_fff98eca();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== displink_build_23 @ fff98e96 (51 bytes)

void displink_build_23(void)

{
  DAT_00001456 = 0x23;
  DAT_00001457 = (char)(PTR_g_ui_00025d38->dl_23_value >> 8) + '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  return;
}


// ===== FUN_fff98ec9 @ fff98ec9 (1 bytes)

void FUN_fff98ec9(void)

{
  return;
}


// ===== FUN_fff98eca @ fff98eca (1 bytes)

void FUN_fff98eca(void)

{
  return;
}


// ===== displink_tx_30_31 @ fff98ecb (177 bytes)

/* 0x30 (0xA0) or 0x31 (0xA3) by +0x1C2 */

void displink_tx_30_31(void)

{
  bool bVar1;
  byte bVar2;
  
  PTR_g_ui_00025d38->dl_req_popup = 0;
  PTR_g_ui_00025d38->dl_req_popup_a = 0;
  if ((PTR_g_ui_00025d38->popup_code == 0xff) || (PTR_g_ui_00025d38->popup_code < 0x1e)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    displink_build_30();
    bVar2 = displink_copy_if_changed(0x1741,0x1456,0x9f);
    if (bVar2 == 1) {
      DAT_0001b628 = 0xa0;
      displink_tx_start(0xa0);
      return;
    }
  }
  else if (PTR_g_ui_00025d38->popup_code < 0x5f) {
    displink_build_31();
    bVar2 = displink_copy_if_changed(0x1741,0x1456,0xa2);
    if (bVar2 == 1) {
      DAT_0001b628 = 0xa3;
      displink_tx_start(0xa3);
      return;
    }
  }
  return;
}


// ===== displink_tx_34 @ fff98f7c (53 bytes)

/* 0x34 (0xA3 bytes) */

void displink_tx_34(void)

{
  displink_build_34(1,DAT_0001b3d6);
  DAT_0001b628 = 0xa3;
  displink_tx_start(0xa3);
  PTR_g_ui_00025d38->dl_req_34 = 0;
  PTR_g_ui_00025d38->dl_block_34 = 1;
  return;
}


// ===== displink_build_30 @ fff98fb1 (622 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99181) */
/* WARNING: Removing unreachable block (ram,0xfff9917b) */

void displink_build_30(void)

{
  byte bVar1;
  int iVar2;
  bool bStack_9;
  vfo_rec *pvStack_8;
  char cStack_1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x30;
  displink_copy_status();
  DAT_000017d9 = PTR_g_ui_00025d38->popup_code;
  if (PTR_g_ui_00025d38->popup_code != 0xff) {
    if (g_opstate.active_vfo == VFO_A) {
      pvStack_8 = &g_opstate.vfo_a;
    }
    else {
      pvStack_8 = &g_opstate.vfo_b;
    }
    bStack_9 = g_opstate.active_vfo != VFO_A;
    switch(PTR_g_ui_00025d38->popup_code) {
    case 0:
      DAT_000017da = g_opstate.meter_sel;
      return;
    case 1:
      DAT_000017da = pvStack_8->flags3 & 3;
      DAT_000017db = PTR_g_ui_00025d38->popup_sel;
      return;
    case 2:
      bVar1 = pvStack_8->flags5 & 3;
      if (bVar1 == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = bVar1 - 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_g_ui_00025d38->popup_sel;
      return;
    case 3:
      bVar1 = mode_block_byte1(pvStack_8);
      DAT_000017da = bVar1 >> 7;
      DAT_000017db = PTR_g_ui_00025d38->popup_sel;
      return;
    case 4:
      bVar1 = mode_block_byte1(pvStack_8);
      if ((bVar1 & 0x40) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (bVar1 >> 4 & 3) + 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_g_ui_00025d38->popup_sel;
      return;
    case 5:
      DAT_000017da = pvStack_8->mode & 0xf;
      DAT_000017db = 0;
      DAT_000017dc = PTR_g_ui_00025d38->popup_cursor;
      return;
    case 6:
      DAT_000017da = scope_span_index(bStack_9);
      return;
    case 7:
    case 8:
      DAT_000017da = 0;
      return;
    case 9:
      DAT_000017da = g_opstate.ss07_affft_att;
      return;
    case 10:
      DAT_000017da = g_opstate.osc_level_tx << 6 | g_opstate.osc_level_rx << 4 | g_opstate.osc_time;
      return;
    case 0xb:
      DAT_000017da = g_opstate.ss03_value;
      DAT_000017db = 0;
      DAT_000017dc = PTR_g_ui_00025d38->popup_cursor;
      return;
    case 0xc:
      DAT_000017da = PTR_g_ui_00025d38->popup_band;
      DAT_000017db = 0;
      DAT_000017dc = PTR_g_ui_00025d38->popup_cursor;
      return;
    case 0xd:
      iVar2 = FUN_fffc4f8f();
      if (iVar2 == 0) {
        DAT_000017da = g_opstate.ss00_value;
        return;
      }
      DAT_000017da = 5;
      return;
    }
  }
  return;
}


// ===== mode_block_byte1 @ fff9921f (120 bytes)

/* active mode's per-mode block byte +1 (BC bit 7, AGC bits 4-6) (#179) */

byte mode_block_byte1(byte *param_1)

{
  uint uVar1;
  byte local_7;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 == 0xe) {
LAB_fff99289:
    local_7 = param_1[0x29];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x15];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x33];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff99289;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1f];
        }
        if (1 < uVar1) {
          return 0;
        }
        return param_1[0xb];
      }
    }
    local_7 = param_1[0x3d];
  }
  return local_7;
}


// ===== displink_build_31 @ fff99297 (478 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void displink_build_31(void)

{
  byte bVar1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x31;
  displink_copy_status();
  DAT_000017d9 = PTR_g_ui_00025d38->popup_code - 0x1e;
  DAT_000017e2 = 0x20;
  _DAT_000017de = 0x20202020;
  _DAT_000017da = 0x20202020;
  bVar1 = PTR_g_ui_00025d38->popup_code;
  if (bVar1 == 0x5e) {
    FUN_fff9a044(0x99);
    return;
  }
  if (bVar1 == 0x1f) {
    FUN_fff9959f(0x99);
    return;
  }
  if (bVar1 == 0x22) {
    FUN_fff99e15(0x99);
    return;
  }
  if (bVar1 == 0x23) {
    FUN_fff9a00f(0x99);
    return;
  }
  if (bVar1 == 0x24) {
    FUN_fff99abf(0x99);
    return;
  }
  if (bVar1 == 0x25) {
    FUN_fff99837(0x99);
    return;
  }
  if (bVar1 == 0x26) {
    FUN_fff99ddb(0x99);
    return;
  }
  if (bVar1 == 0x27) {
    FUN_fff997df(0x99);
    return;
  }
  if (bVar1 == 0x28) {
    FUN_fff99a8a(0x99);
    return;
  }
  if (bVar1 == 0x29) {
    FUN_fff996e2(0x99);
    return;
  }
  if (bVar1 == 0x2a) {
    FUN_fff99717(0x99);
    return;
  }
  if (bVar1 == 0x2b) {
    FUN_fff9978c(0x99);
    return;
  }
  if (bVar1 == 0x2c) {
    FUN_fff995cc(0x99);
    return;
  }
  if (bVar1 == 0x2d) {
    FUN_fff9960e(0x99);
    return;
  }
  if (bVar1 == 0x2f) {
    FUN_fff99d82(0x99);
    return;
  }
  if (bVar1 == 0x30) {
    FUN_fff998e2(0x99);
    return;
  }
  if (bVar1 == 0x31) {
    FUN_fff9992a(0x99);
    return;
  }
  if (bVar1 == 0x32) {
    FUN_fff99989(0x99);
    return;
  }
  if (bVar1 == 0x33) {
    FUN_fff999e3(0x99);
    return;
  }
  if (bVar1 == 0x38) {
    FUN_fff99b70(0x99);
    return;
  }
  if (bVar1 == 0x39) {
    FUN_fff99ba5(0x99);
    return;
  }
  if (bVar1 == 0x3a) {
    FUN_fff99d42(0x99);
    return;
  }
  if (bVar1 == 0x43) {
    FUN_fff99bfe(0x99);
    return;
  }
  if (bVar1 == 0x44) {
    FUN_fff99ca2(0x99);
    return;
  }
  if (bVar1 == 0x45) {
    FUN_fff99cf2(0x99);
    return;
  }
  if (bVar1 == 0x46) {
    FUN_fff99d48(0x99);
    return;
  }
  if (bVar1 == 0x55) {
    FUN_fff99c58(0x99);
    return;
  }
  if (bVar1 == 0x58) {
    FUN_fff99a29(0x99);
    return;
  }
  if (bVar1 != 0x1e) {
    return;
  }
  FUN_fff99475(0x99);
  return;
}


// ===== FUN_fff99475 @ fff99475 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99588) */
/* WARNING: Removing unreachable block (ram,0xfff994d7) */
/* WARNING: Removing unreachable block (ram,0xfff99568) */
/* WARNING: Removing unreachable block (ram,0xfff9953b) */

void FUN_fff99475(ushort param_1)

{
  byte bVar1;
  byte *pbVar2;
  ushort uStack_6;
  undefined1 uStack_4;
  
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4264302e;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  pbVar2 = (byte *)FUN_fff9c6ab();
  bVar1 = *pbVar2;
  if (bVar1 == 0x3c) {
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (bVar1 < 0x3d) {
    uStack_4 = 0x2d;
  }
  else {
    uStack_4 = 0x2b;
  }
  uStack_6 = (ushort)bVar1 * 5 - 300;
  if (bVar1 < 0x3c) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uint)uStack_6 % 10 == 0) {
    (&DAT_00001746)[param_1] = 0x30;
  }
  else {
    (&DAT_00001746)[param_1] = 0x35;
  }
  if (uStack_6 < 10) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (uStack_6 < 100) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = (char)(uStack_6 / 10) + '0';
    return;
  }
  if (999 < uStack_6) {
    return;
  }
  (&DAT_00001742)[param_1] = uStack_4;
  (&DAT_00001743)[param_1] = (char)(uStack_6 / 100) + '0';
  (&DAT_00001744)[param_1] =
       (char)((int)((uint)uStack_6 + (uint)(uStack_6 / 100) * -100) / 10) + '0';
  return;
}


// ===== FUN_fff9959f @ fff9959f (45 bytes)

/* WARNING: Removing unreachable block (ram,0xfff995b0) */

void FUN_fff9959f(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)g_opstate.ss01_peak;
  *(undefined4 *)(&DAT_00001745 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + uVar1 * 8 + 0x235);
  *(undefined4 *)(&DAT_00001741 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + uVar1 * 8 + 0x231);
  return;
}


// ===== FUN_fff995cc @ fff995cc (66 bytes)

void FUN_fff995cc(ushort param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  uVar1 = FUN_fffb4062();
  bVar2 = dec_to_str_n(uVar1,3,&DAT_000019ca);
  (&DAT_00001748)[param_1] = 0x57;
  uVar5 = (uint)bVar2;
  puVar3 = &DAT_00001748 + (param_1 - uVar5);
  puVar4 = &DAT_000019ca;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff9960e @ fff9960e (91 bytes)

void FUN_fff9960e(ushort param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  char cStack_3;
  
  pcVar2 = (char *)FUN_fff99669();
  if (pcVar2 == (char *)0x0) {
    cStack_3 = '\0';
  }
  else {
    cStack_3 = *pcVar2;
  }
  if (cStack_3 != '\0') {
    bVar1 = dec_to_str_n(cStack_3,3,&DAT_000019d2);
    uVar5 = (uint)bVar1;
    puVar3 = &DAT_00001749 + (param_1 - uVar5);
    puVar4 = &DAT_000019d2;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    return;
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return;
}


// ===== FUN_fff99669 @ fff99669 (121 bytes)

uint FUN_fff99669(void)

{
  radio_mode rVar1;
  uint uVar2;
  
  rVar1 = vfo_mode(VFO_TX);
  uVar2 = (uint)rVar1;
  if (uVar2 != 0xe) {
    if (uVar2 - 2 < 2) {
      return 0x9bfd;
    }
    if (uVar2 - 4 < 2) {
      return 0x9c00;
    }
    if (1 < uVar2 - 8) {
      if (uVar2 - 0xc < 2) {
        return 0x9bfe;
      }
      if (1 < uVar2) {
        return 0;
      }
      return 0x9bfc;
    }
  }
  return 0x9bff;
}


// ===== FUN_fff996e2 @ fff996e2 (53 bytes)

void FUN_fff996e2(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n(g_opstate.vox_gain,3,&DAT_000019da);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_000019da;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99717 @ fff99717 (117 bytes)

void FUN_fff99717(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_3;
  
  *(undefined2 *)(&DAT_00001747 + param_1) = 0x736d;
  if (g_opstate.ex030405_vox_select == 0) {
    local_3 = g_opstate.vox_delay[0];
  }
  else {
    local_3 = g_opstate.vox_delay[1];
  }
  if (0x21 < local_3) {
    local_3 = 0;
  }
  bVar1 = dec_to_str_n(*(undefined2 *)(BYTE_ARRAY_fff87ed4 + (uint)local_3 * 2 + 2),4,&DAT_000019e2)
  ;
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_000019e2;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff9978c @ fff9978c (83 bytes)

void FUN_fff9978c(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_3;
  
  if (g_opstate.ex030405_vox_select == 0) {
    local_3 = g_opstate.antivox[0];
  }
  else {
    local_3 = g_opstate.antivox[1];
  }
  bVar1 = dec_to_str_n(local_3,3,&DAT_000019ea);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_000019ea;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff997df @ fff997df (88 bytes)

void FUN_fff997df(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  if (g_opstate.proc_level != 0) {
    bVar1 = dec_to_str_n(g_opstate.proc_level,3,&DAT_000019f2);
    uVar4 = (uint)bVar1;
    puVar2 = &DAT_00001749 + (param_1 - uVar4);
    puVar3 = &DAT_000019f2;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return;
}


// ===== FUN_fff99837 @ fff99837 (64 bytes)

void FUN_fff99837(ushort param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined1 uStack_3;
  
  puVar2 = (undefined1 *)FUN_fff99877();
  if (puVar2 == (undefined1 *)0x0) {
    uStack_3 = 0;
  }
  else {
    uStack_3 = *puVar2;
  }
  bVar1 = dec_to_str_n(uStack_3,3,&DAT_000019fa);
  uVar4 = (uint)bVar1;
  puVar3 = &DAT_00001749 + (param_1 - uVar4);
  puVar2 = &DAT_000019fa;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

