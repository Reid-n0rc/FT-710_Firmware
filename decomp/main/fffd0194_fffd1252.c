// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd0194 @ fffd0194 (57 bytes)

void FUN_fffd0194(char param_1)

{
  PTR_g_ui_00025d60->dialog_shown = 0;
  if (param_1 != '\x01') {
    FUN_fffd04dd();
    PTR_g_ui_00025d60->sd_step = 5;
    PTR_g_ui_00025d60->sd_busy = 1;
    return;
  }
  dialog_close_to_menu();
  return;
}


// ===== FUN_fffd01cd @ fffd01cd (38 bytes)

void FUN_fffd01cd(void)

{
  PTR_g_ui_00025d60->dialog_shown = 0;
  PTR_g_ui_00025d60->restart_req = 1;
  PTR_g_ui_00025d60->power_cmd = 0x11;
  return;
}


// ===== FUN_fffd01f3 @ fffd01f3 (65 bytes)

void FUN_fffd01f3(void)

{
  if (PTR_g_ui_00025d60->sd_step != 7) {
    PTR_g_ui_00025d60->dialog_shown = 0;
    PTR_g_ui_00025d60->restart_req = 1;
    PTR_g_ui_00025d60->power_cmd = 0x11;
    return;
  }
  menu_close_if_open();
  FUN_fffc4c8b(4);
  return;
}


// ===== FUN_fffd0234 @ fffd0234 (69 bytes)

void FUN_fffd0234(void)

{
  uint uVar1;
  
  uVar1 = (uint)PTR_g_ui_00025d60->dialog_msg;
  if (uVar1 == 1) {
    FUN_fffd0300();
    return;
  }
  if (0xb < uVar1 - 2) {
    if (uVar1 - 0xe < 2) {
LAB_fffd0268:
      menu_reset_exec();
      return;
    }
    if (6 < uVar1 - 0x10) {
      if (uVar1 == 0x17) {
        FUN_fffd0366();
        return;
      }
      if (1 < uVar1 - 0x18) {
        if (uVar1 != 0) {
          return;
        }
        goto LAB_fffd0268;
      }
    }
  }
  FUN_fffd038d();
  return;
}


// ===== menu_reset_exec @ fffd0279 (15 bytes)

/* Runs reset_select(0x20BC0) */

void menu_reset_exec(void)

{
  reset_select(PTR_g_ui_00025d60->reset_kind);
  return;
}


// ===== reset_select @ fffd0288 (103 bytes)

/* 0: memory reset (+ch 1 to VFO), 1: menu reset, 2: settings_defaults(0); then restart code
   0x20B39=0x11 */

void reset_select(char param_1)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  if (param_1 == '\x02') {
    FUN_fffd02f9();
  }
  else if (param_1 == '\x01') {
    FUN_fffd02f4();
  }
  else if (param_1 == '\0') {
    FUN_fffd02ef();
    if (g_opstate.active_vfo == VFO_A) {
      pvVar2 = memch;
      pvVar1 = &g_opstate.vfo_a;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        pvVar1->mode = pvVar2->mode;
        pvVar1 = (vfo_rec *)&pvVar1->flags1;
        pvVar2 = (vfo_rec *)&pvVar2->flags1;
      }
    }
    else {
      pvVar2 = memch;
      pvVar1 = &g_opstate.vfo_b;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        pvVar1->mode = pvVar2->mode;
        pvVar1 = (vfo_rec *)&pvVar1->flags1;
        pvVar2 = (vfo_rec *)&pvVar2->flags1;
      }
    }
  }
  beep_request(8);
  PTR_g_ui_00025d60->power_cmd = 0x11;
  return;
}


// ===== FUN_fffd02ef @ fffd02ef (5 bytes)

void FUN_fffd02ef(void)

{
  reset_memch();
  return;
}


// ===== FUN_fffd02f4 @ fffd02f4 (5 bytes)

void FUN_fffd02f4(void)

{
  reset_menu();
  return;
}


// ===== FUN_fffd02f9 @ fffd02f9 (7 bytes)

void FUN_fffd02f9(void)

{
  settings_defaults(0);
  return;
}


// ===== FUN_fffd0300 @ fffd0300 (102 bytes)

void FUN_fffd0300(void)

{
  PTR_g_ui_00025d60->dialog_shown = 0;
  FUN_fffd03a7();
  PTR_g_ui_00025d60->dl_req_40 = 1;
  PTR_g_ui_00025d60->menu_p1 = 4;
  (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1] = 1;
  PTR_g_ui_00025d60->menu_state = 2;
  PTR_g_ui_00025d60->msgmem_open = 0;
  PTR_g_ui_00025d60->keypad_open = 0;
  return;
}


// ===== FUN_fffd0366 @ fffd0366 (39 bytes)

void FUN_fffd0366(void)

{
  PTR_g_ui_00025d60->dialog_shown = 0;
  PTR_g_ui_00025d60->playlist_req = 1;
  PTR_g_ui_00025d60->playlist_substate = 3;
  return;
}


// ===== FUN_fffd038d @ fffd038d (26 bytes)

void FUN_fffd038d(void)

{
  PTR_g_ui_00025d60->dialog_shown = 0;
  PTR_g_ui_00025d60->menu_state = 2;
  return;
}


// ===== FUN_fffd03a7 @ fffd03a7 (5 bytes)

void FUN_fffd03a7(void)

{
  popup_close();
  return;
}


// ===== FUN_fffd03ac @ fffd03ac (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd03f4) */
/* WARNING: Removing unreachable block (ram,0xfffd03c7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffd03ac(void)

{
  if (DAT_00015de5 == '\0') {
    DAT_00015de4 = 0xd;
  }
  else {
    DAT_00015de4 = 0x30;
  }
  _DAT_0001ff04 = 0x100;
  _DAT_0001ff02 = 0;
  return;
}


// ===== FUN_fffd041e @ fffd041e (136 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd04a3) */

ushort FUN_fffd041e(void)

{
  ui_state *puVar1;
  byte bVar2;
  ushort uStack_6;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  bVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = bVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 4;
  if (DAT_00015de5 == '\0') {
    uStack_6 = 0xc25;
  }
  else {
    uStack_6 = 0x2f4b;
  }
  PTR_g_ui_00025d60->sdreq_arg2 = (byte)(uStack_6 >> 8);
  PTR_g_ui_00025d60->sdreq_arg3 = (byte)uStack_6;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return uStack_6 >> 8;
}


// ===== FUN_fffd04a6 @ fffd04a6 (27 bytes)

void FUN_fffd04a6(void)

{
  PTR_g_ui_00025d60->sd_step = 8;
  PTR_g_ui_00025d60->sd_busy = 1;
  return;
}


// ===== sd_save_xfer_id @ fffd04c1 (28 bytes)

/* 0x42 (memory list) or 0x44 (menu) by 0x15DE5 [fact] (display-link.md) */

undefined1 sd_save_xfer_id(void)

{
  undefined1 local_2;
  
  if (DAT_00015de5 == '\0') {
    local_2 = 0x44;
  }
  else {
    local_2 = 0x42;
  }
  return local_2;
}


// ===== FUN_fffd04dd @ fffd04dd (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0563) */

undefined4 FUN_fffd04dd(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  uVar2 = sd_load_xfer_id();
  puVar1->sdreq_op = (byte)uVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 0x10;
  PTR_g_ui_00025d60->sdreq_arg2 = DAT_00015de7 + DAT_00015de8;
  PTR_g_ui_00025d60->sdreq_arg3 = 0x50;
  PTR_g_ui_00025d60->sdreq_arg4 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return uVar2;
}


// ===== sd_load_xfer_id @ fffd0566 (28 bytes)

/* 0x41 (memory list) or 0x43 (menu) by 0x15DE5 [fact] (display-link.md) */

undefined1 sd_load_xfer_id(void)

{
  undefined1 local_2;
  
  if (DAT_00015de5 == '\0') {
    local_2 = 0x43;
  }
  else {
    local_2 = 0x41;
  }
  return local_2;
}


// ===== sd_menu_task @ fffd0582 (77 bytes)

/* main_loop task 13: while +0x88 is set runs the step function of mode 0x15DE3 (1 load, 2 save, 3
   informations, 4 format); aborts if the SD card is gone (+0xA6 = 0) (#65) */

void sd_menu_task(void)

{
  if (PTR_g_ui_00025d60->dl_req_50 != 0) {
    if (PTR_g_ui_00025d60->sd_present == 0) {
      dialog_no_sd_card();
      sd_step_reset();
      return;
    }
    if (DAT_00015de3 == '\x04') {
      sd_format_step();
      return;
    }
    if (DAT_00015de3 == '\x02') {
      sd_save_step();
      return;
    }
    if (DAT_00015de3 == '\x03') {
      sd_info_step();
      return;
    }
    if (DAT_00015de3 == '\x01') {
      sd_load_step();
      return;
    }
  }
  return;
}


// ===== sd_step_reset @ fffd05cf (27 bytes)

/* UI +0x3F7 (SD step) = 0, +0x406 = 0 [fact] */

void sd_step_reset(void)

{
  PTR_g_ui_00025d60->sd_step = 0;
  PTR_g_ui_00025d60->sd_busy = 0;
  return;
}


// ===== sd_load_step @ fffd05ea (45 bytes)

/* Mode 1 step machine on +0x3F7; reads blocks with frame 0x44 (#65) */

void sd_load_step(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d60->sd_step;
  if (bVar1 == 6) {
    sd_load_block_answer();
    return;
  }
  if (bVar1 == 3) {
    FUN_fffd06e2();
    return;
  }
  if (bVar1 == 5) {
    FUN_fffd0703();
    return;
  }
  if (bVar1 != 1) {
    return;
  }
  FUN_fffd0617();
  return;
}


// ===== FUN_fffd0617 @ fffd0617 (189 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd06bf) */
/* WARNING: Removing unreachable block (ram,0xfffd06d1) */
/* WARNING: Removing unreachable block (ram,0xfffd06ce) */
/* WARNING: Removing unreachable block (ram,0xfffd06c5) */
/* WARNING: Removing unreachable block (ram,0xfffd06b0) */

undefined4 FUN_fffd0617(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar2 = sd_load_xfer_id();
  if (bVar1 == uVar2) {
    if (PTR_g_ui_00025d60->sd_answer[1] != 0) {
      uVar3 = sd_abort_no_card();
      return uVar3;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
      DAT_00015de6 = PTR_g_ui_00025d60->sd_answer[3];
      if (DAT_00015de6 == 0) {
        DAT_00015de8 = 0xff;
      }
      else {
        DAT_00015de8 = 0;
      }
      DAT_00015de7 = 0;
      uVar3 = FUN_fffd0902();
      PTR_g_ui_00025d60->sd_step = 2;
      return uVar3;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 4) {
      FUN_fffcf583();
      uVar3 = sd_step_reset();
      return uVar3;
    }
  }
  dialog_no_sd_card();
  uVar3 = sd_step_reset();
  return uVar3;
}


// ===== FUN_fffd06d4 @ fffd06d4 (14 bytes)

void FUN_fffd06d4(void)

{
  PTR_g_ui_00025d60->sd_step = 3;
  return;
}


// ===== FUN_fffd06e2 @ fffd06e2 (33 bytes)

void FUN_fffd06e2(void)

{
  if (PTR_g_ui_00025d60->dl_req_sd != 0) {
    return;
  }
  FUN_fffcf5a0();
  PTR_g_ui_00025d60->sd_step = 4;
  return;
}


// ===== FUN_fffd0703 @ fffd0703 (123 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0769) */
/* WARNING: Removing unreachable block (ram,0xfffd077b) */
/* WARNING: Removing unreachable block (ram,0xfffd0778) */
/* WARNING: Removing unreachable block (ram,0xfffd076f) */

undefined4 FUN_fffd0703(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar2 = sd_load_xfer_id();
  if (bVar1 != uVar2) {
    dialog_no_sd_card();
    uVar3 = sd_step_reset();
    return uVar3;
  }
  if ((PTR_g_ui_00025d60->sd_answer[1] == 0x10) && (PTR_g_ui_00025d60->sd_answer[2] == 0)) {
    FUN_fffd03ac();
    uVar3 = FUN_fffd0980();
    PTR_g_ui_00025d60->sd_step = 6;
    return uVar3;
  }
  uVar3 = sd_abort_no_card();
  return uVar3;
}


// ===== sd_load_block_answer @ fffd077e (388 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd08e9) */
/* WARNING: Removing unreachable block (ram,0xfffd08ff) */
/* WARNING: Removing unreachable block (ram,0xfffd08fc) */
/* WARNING: Removing unreachable block (ram,0xfffd07b0) */
/* WARNING: Removing unreachable block (ram,0xfffd07de) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SD load step: when the DISPLAY's answer (g_ui.sd_answer) matches the expected offset/length
   (0x1FF02 / 0x1FF04), stores the block, advances; after the last block checks the region code and
   copies the loaded image into the memory / QMB headers, else requests the next block (sd_step = 6)
   [fact: fffd077e]; only caller sd_load_step */

uint sd_load_block_answer(uint param_1)

{
  ushort uVar1;
  qmb_hdr *pqVar2;
  mem_hdr *pmVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined *puVar7;
  
  if (PTR_g_ui_00025d60->sd_answer_ready == 1) {
    PTR_g_ui_00025d60->sd_answer_ready = 0;
    param_1 = (uint)CONCAT11(PTR_g_ui_00025d60->sd_answer[1],PTR_g_ui_00025d60->sd_answer[2]);
    if ((param_1 == _DAT_0001ff02) &&
       (param_1 = (uint)CONCAT11(PTR_g_ui_00025d60->sd_answer[3],PTR_g_ui_00025d60->sd_answer[4]),
       param_1 == _DAT_0001ff04)) {
      FUN_fffd0a16();
      _DAT_0001ff02 = _DAT_0001ff02 + _DAT_0001ff04;
      DAT_00015de4 = DAT_00015de4 + -1;
      if (DAT_00015de4 == '\x01') {
        if (DAT_00015de5 == '\0') {
          _DAT_0001ff04 = 0xc25 - _DAT_0001ff02;
        }
        else {
          _DAT_0001ff04 = 0x2f4b - _DAT_0001ff02;
        }
      }
      if (DAT_00015de4 != '\0') {
        uVar4 = FUN_fffd0980();
        PTR_g_ui_00025d60->sd_step = 6;
        return uVar4;
      }
      uVar1 = dest_code_get();
      if (DAT_00015de5 == '\0') {
        uVar4 = FUN_fffcf5bd();
        if (uVar1 == uVar4) {
          pbVar5 = &DAT_00012275;
          pqVar2 = &g_qmb_hdr;
          for (iVar6 = 0xc23; iVar6 != 0; iVar6 = iVar6 + -1) {
            pqVar2->used_mask_be[0] = *pbVar5;
            pqVar2 = (qmb_hdr *)(pqVar2->used_mask_be + 1);
            pbVar5 = pbVar5 + 1;
          }
        }
        else {
          beep_request(3);
        }
      }
      else {
        uVar4 = FUN_fffcf5bd();
        if (uVar1 == uVar4) {
          pbVar5 = &DAT_00012e9a;
          pmVar3 = &g_mem_hdr;
          for (puVar7 = &DAT_00002f49; puVar7 != (undefined *)0x0; puVar7 = puVar7 + -1) {
            pmVar3->chan_a = *pbVar5;
            pmVar3 = (mem_hdr *)&pmVar3->chan_b;
            pbVar5 = pbVar5 + 1;
          }
        }
        else {
          beep_request(3);
        }
      }
      uVar4 = FUN_fffcf5f9();
      PTR_g_ui_00025d60->sd_step = 7;
      PTR_g_ui_00025d60->sd_busy = 0;
      return uVar4;
    }
  }
  return param_1;
}


// ===== FUN_fffd0902 @ fffd0902 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0976) */

undefined4 FUN_fffd0902(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  uVar2 = sd_load_xfer_id();
  puVar1->sdreq_op = (byte)uVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 1;
  PTR_g_ui_00025d60->sdreq_arg2 = DAT_00015de7;
  PTR_g_ui_00025d60->sdreq_arg3 = DAT_00015de8;
  PTR_g_ui_00025d60->sdreq_arg4 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return uVar2;
}


// ===== sd_abort_no_card @ fffd0979 (7 bytes)

/* dialog_no_sd_card, then sd_step_reset [fact] */

void sd_abort_no_card(void)

{
  dialog_no_sd_card();
  sd_step_reset();
  return;
}


// ===== FUN_fffd0980 @ fffd0980 (150 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0a13) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd0980(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  uVar2 = sd_load_xfer_id();
  puVar1->sdreq_op = (byte)uVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = (byte)((ushort)_DAT_0001ff02 >> 8);
  PTR_g_ui_00025d60->sdreq_arg2 = DAT_0001ff02;
  PTR_g_ui_00025d60->sdreq_arg3 = (byte)((ushort)_DAT_0001ff04 >> 8);
  PTR_g_ui_00025d60->sdreq_arg4 = DAT_0001ff04;
  PTR_g_ui_00025d60->sdreq_len = 7;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x44;
  return uVar2;
}


// ===== FUN_fffd0a16 @ fffd0a16 (82 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffd0a16(void)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (DAT_00015de5 != '\0') {
    pbVar1 = &DAT_00012e98 + _DAT_0001ff02;
    pbVar2 = PTR_g_ui_00025d60->sd_answer + 5;
    for (uVar3 = (uint)_DAT_0001ff04; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pbVar1 = *pbVar2;
      pbVar1 = pbVar1 + 1;
      pbVar2 = pbVar2 + 1;
    }
    return;
  }
  pbVar1 = &DAT_00012273 + _DAT_0001ff02;
  pbVar2 = PTR_g_ui_00025d60->sd_answer + 5;
  for (uVar3 = (uint)_DAT_0001ff04; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== sd_save_step @ fffd0a68 (138 bytes)

/* Mode 2 step machine; writes blocks with frame 0x45 [inference from the 0x45 sender in this range]
   (#65) */

void sd_save_step(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d60->sd_step;
  if (bVar1 == 99) {
    if (0x14 < DAT_00015dfb) {
      DAT_00015dfb = 0;
      PTR_g_ui_00025d60->dl_req_sd = 1;
      FUN_fffd0c59();
      PTR_g_ui_00025d60->sd_step = 4;
      return;
    }
    DAT_00015dfb = DAT_00015dfb + 1;
    return;
  }
  if (bVar1 == 3) {
    FUN_fffd0c38();
    return;
  }
  if (bVar1 == 4) {
    FUN_fffd0d0e();
    return;
  }
  if (bVar1 == 6) {
    FUN_fffd0ed3();
    return;
  }
  if (bVar1 == 8) {
    FUN_fffd0f6f();
    return;
  }
  if (bVar1 == 9) {
    FUN_fffd1130();
    return;
  }
  if (bVar1 == 10) {
    FUN_fffd12fd();
    return;
  }
  if (bVar1 != 1) {
    return;
  }
  FUN_fffd0af2();
  return;
}


// ===== FUN_fffd0af2 @ fffd0af2 (190 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0ba1) */
/* WARNING: Removing unreachable block (ram,0xfffd0bad) */
/* WARNING: Removing unreachable block (ram,0xfffd0baa) */
/* WARNING: Removing unreachable block (ram,0xfffd0b7b) */
/* WARNING: Removing unreachable block (ram,0xfffd0b89) */

undefined4 FUN_fffd0af2(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar2 = sd_save_xfer_id();
  if (bVar1 == uVar2) {
    if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
      DAT_00015de6 = PTR_g_ui_00025d60->sd_answer[3];
      if (DAT_00015de6 == 0) {
        DAT_00015de8 = 0xfe;
      }
      else {
        DAT_00015de8 = 0;
      }
      DAT_00015de7 = 0;
      uVar3 = FUN_fffd0bb0();
      PTR_g_ui_00025d60->sd_step = 2;
      return uVar3;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 1) {
      FUN_fffcf68f();
      uVar3 = sd_step_reset();
      return uVar3;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 4) {
      FUN_fffcf583();
      uVar3 = sd_step_reset();
      return uVar3;
    }
  }
  dialog_no_sd_card();
  uVar3 = sd_step_reset();
  return uVar3;
}


// ===== FUN_fffd0bb0 @ fffd0bb0 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0c24) */

undefined4 FUN_fffd0bb0(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  uVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = (byte)uVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 1;
  PTR_g_ui_00025d60->sdreq_arg2 = DAT_00015de7;
  PTR_g_ui_00025d60->sdreq_arg3 = DAT_00015de8;
  PTR_g_ui_00025d60->sdreq_arg4 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return uVar2;
}


// ===== FUN_fffd0c27 @ fffd0c27 (17 bytes)

void FUN_fffd0c27(void)

{
  FUN_fffd0bb0();
  PTR_g_ui_00025d60->sd_step = 2;
  return;
}


// ===== FUN_fffd0c38 @ fffd0c38 (33 bytes)

void FUN_fffd0c38(void)

{
  if (PTR_g_ui_00025d60->dl_req_sd != 1) {
    return;
  }
  FUN_fffd0c59();
  PTR_g_ui_00025d60->sd_step = 4;
  return;
}


// ===== FUN_fffd0c59 @ fffd0c59 (181 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0d0b) */

undefined4 FUN_fffd0c59(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  uVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = (byte)uVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 2;
  PTR_g_ui_00025d60->sdreq_arg2 = 0xff;
  DAT_00015df9 = 1;
  if (DAT_00015de8 != -2) {
    DAT_00015df9 = 0;
    PTR_g_ui_00025d60->sdreq_arg2 = DAT_00015de7 + DAT_00015de8;
  }
  PTR_g_ui_00025d60->sdreq_arg3 = 0;
  PTR_g_ui_00025d60->sdreq_arg4 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return uVar2;
}


// ===== FUN_fffd0d0e @ fffd0d0e (266 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0d8e) */
/* WARNING: Removing unreachable block (ram,0xfffd0e15) */
/* WARNING: Removing unreachable block (ram,0xfffd0e12) */
/* WARNING: Removing unreachable block (ram,0xfffd0df7) */
/* WARNING: Removing unreachable block (ram,0xfffd0e0c) */
/* WARNING: Removing unreachable block (ram,0xfffd0dec) */

byte (*) [50] FUN_fffd0d0e(byte (*param_1) [50])

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  byte (*pabVar5) [50];
  byte *pbVar6;
  int iVar7;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar3 = sd_save_xfer_id();
  if ((bVar1 == uVar3) && (PTR_g_ui_00025d60->sdreq_arg1 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
      pbVar6 = PTR_g_ui_00025d60->sd_answer + 3;
      pbVar4 = &DAT_00015dea;
      for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar4 = *pbVar6;
        pbVar4 = pbVar4 + 1;
        pbVar6 = pbVar6 + 1;
      }
      if (DAT_00015df9 != '\0') {
        PTR_g_ui_00025d60->kbd_open = 1;
        PTR_g_ui_00025d60->kbd_target = 5;
        PTR_g_ui_00025d60->kbd_cursor = 0;
        pabVar5 = PTR_g_ui_00025d60->msg_text;
        for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
          (*pabVar5)[0] = 0x20;
          pabVar5 = (byte (*) [50])(*pabVar5 + 1);
        }
        pabVar5 = PTR_g_ui_00025d60->msg_text;
        pbVar4 = &DAT_00015dea;
        for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
          (*pabVar5)[0] = *pbVar4;
          pabVar5 = (byte (*) [50])(*pabVar5 + 1);
          pbVar4 = pbVar4 + 1;
        }
        PTR_g_ui_00025d60->sd_step = 5;
        return pabVar5;
      }
      pabVar5 = (byte (*) [50])FUN_fffd0e26();
      return pabVar5;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 1) {
      pabVar5 = (byte (*) [50])FUN_fffd0e18();
      return pabVar5;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 2) {
      pabVar5 = (byte (*) [50])FUN_fffd0e1f();
      return pabVar5;
    }
  }
  pabVar5 = (byte (*) [50])sd_abort_no_card();
  return pabVar5;
}


// ===== FUN_fffd0e18 @ fffd0e18 (7 bytes)

void FUN_fffd0e18(void)

{
  FUN_fffcf50f();
  sd_step_reset();
  return;
}


// ===== FUN_fffd0e1f @ fffd0e1f (7 bytes)

void FUN_fffd0e1f(void)

{
  FUN_fffcf52c();
  sd_step_reset();
  return;
}


// ===== FUN_fffd0e26 @ fffd0e26 (17 bytes)

void FUN_fffd0e26(void)

{
  FUN_fffcf549();
  PTR_g_ui_00025d60->sd_step = 7;
  return;
}


// ===== FUN_fffd0e37 @ fffd0e37 (51 bytes)

void FUN_fffd0e37(void)

{
  byte *pbVar1;
  byte (*pabVar2) [50];
  int iVar3;
  
  pabVar2 = PTR_g_ui_00025d60->msg_text;
  pbVar1 = &DAT_00015dea;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = (*pabVar2)[0];
    pbVar1 = pbVar1 + 1;
    pabVar2 = (byte (*) [50])(*pabVar2 + 1);
  }
  PTR_g_ui_00025d60->kbd_open = 0;
  FUN_fffd0e6a();
  PTR_g_ui_00025d60->sd_step = 6;
  return;
}


// ===== FUN_fffd0e6a @ fffd0e6a (105 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0ed0) */

byte * FUN_fffd0e6a(void)

{
  ui_state *puVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  bVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = bVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 3;
  pbVar3 = &PTR_g_ui_00025d60->sdreq_arg2;
  pbVar4 = &DAT_00015dea;
  for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar3 = *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  }
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return pbVar3;
}


// ===== FUN_fffd0ed3 @ fffd0ed3 (156 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0f63) */
/* WARNING: Removing unreachable block (ram,0xfffd0f6c) */
/* WARNING: Removing unreachable block (ram,0xfffd0f08) */
/* WARNING: Removing unreachable block (ram,0xfffd0f69) */
/* WARNING: Removing unreachable block (ram,0xfffd0f4e) */
/* WARNING: Removing unreachable block (ram,0xfffd0f39) */
/* WARNING: Removing unreachable block (ram,0xfffd0f1d) */

undefined4 FUN_fffd0ed3(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar2 = sd_save_xfer_id();
  if (bVar1 != uVar2) {
    uVar3 = sd_abort_no_card();
    return uVar3;
  }
  if (PTR_g_ui_00025d60->sd_answer[1] != 2) {
    uVar3 = sd_abort_no_card();
    return uVar3;
  }
  if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
    FUN_fffd03ac();
    FUN_fffd041e();
    uVar3 = FUN_fffd04a6();
    return uVar3;
  }
  if (PTR_g_ui_00025d60->sd_answer[2] == 1) {
    uVar3 = FUN_fffd0e26();
    return uVar3;
  }
  if (PTR_g_ui_00025d60->sd_answer[2] != 2) {
    uVar3 = sd_abort_no_card();
    return uVar3;
  }
  uVar3 = FUN_fffd0e1f();
  return uVar3;
}


// ===== FUN_fffd0f6f @ fffd0f6f (94 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0fc1) */
/* WARNING: Removing unreachable block (ram,0xfffd0fca) */
/* WARNING: Removing unreachable block (ram,0xfffd0fc7) */

undefined4 FUN_fffd0f6f(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar3 = sd_save_xfer_id();
  if ((bVar1 == uVar3) && (PTR_g_ui_00025d60->sd_answer[1] == 3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uVar4 = FUN_fffd0fcd();
    return uVar4;
  }
  uVar4 = sd_abort_no_card();
  return uVar4;
}


// ===== FUN_fffd0fcd @ fffd0fcd (17 bytes)

void FUN_fffd0fcd(void)

{
  FUN_fffd0fde();
  PTR_g_ui_00025d60->sd_step = 9;
  return;
}


// ===== FUN_fffd0fde @ fffd0fde (154 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1075) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd0fde(void)

{
  ui_state *puVar1;
  byte bVar2;
  undefined4 uVar3;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  bVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = bVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = (byte)((ushort)_DAT_0001ff02 >> 8);
  PTR_g_ui_00025d60->sdreq_arg2 = DAT_0001ff02;
  PTR_g_ui_00025d60->sdreq_arg3 = (byte)((ushort)_DAT_0001ff04 >> 8);
  PTR_g_ui_00025d60->sdreq_arg4 = DAT_0001ff04;
  uVar3 = FUN_fffd1078();
  PTR_g_ui_00025d60->sdreq_len = 0x107;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x45;
  return uVar3;
}


// ===== FUN_fffd1078 @ fffd1078 (184 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffd1078(void)

{
  ushort uVar1;
  byte *pbVar2;
  qmb_hdr *pqVar3;
  mem_hdr *pmVar4;
  byte *pbVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  
  uVar1 = dest_code_get();
  if (_DAT_0001ff02 == 0) {
    DAT_00012273 = (undefined1)uVar1;
    DAT_00012274 = (undefined1)(uVar1 >> 8);
    pqVar3 = &g_qmb_hdr;
    pbVar2 = &DAT_00012275;
    DAT_00012e98 = DAT_00012273;
    DAT_00012e99 = DAT_00012274;
    for (iVar6 = 0xc23; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pbVar2 = pqVar3->used_mask_be[0];
      pbVar2 = pbVar2 + 1;
      pqVar3 = (qmb_hdr *)(pqVar3->used_mask_be + 1);
    }
    pmVar4 = &g_mem_hdr;
    pbVar2 = &DAT_00012e9a;
    for (puVar7 = &DAT_00002f49; puVar7 != (undefined *)0x0; puVar7 = puVar7 + -1) {
      *pbVar2 = pmVar4->chan_a;
      pbVar2 = pbVar2 + 1;
      pmVar4 = (mem_hdr *)&pmVar4->chan_b;
    }
  }
  pbVar2 = PTR_g_ui_00025d60->sdreq_data;
  if (DAT_00015de5 == '\0') {
    pbVar5 = &DAT_00012273 + _DAT_0001ff02;
    for (uVar8 = (uint)_DAT_0001ff04; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pbVar2 = *pbVar5;
      pbVar2 = pbVar2 + 1;
      pbVar5 = pbVar5 + 1;
    }
    return;
  }
  pbVar5 = &DAT_00012e98 + _DAT_0001ff02;
  for (uVar8 = (uint)_DAT_0001ff04; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pbVar2 = *pbVar5;
    pbVar2 = pbVar2 + 1;
    pbVar5 = pbVar5 + 1;
  }
  return;
}


// ===== FUN_fffd1130 @ fffd1130 (290 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1239) */
/* WARNING: Removing unreachable block (ram,0xfffd124f) */
/* WARNING: Removing unreachable block (ram,0xfffd1167) */
/* WARNING: Removing unreachable block (ram,0xfffd124c) */
/* WARNING: Removing unreachable block (ram,0xfffd11cb) */
/* WARNING: Removing unreachable block (ram,0xfffd1199) */
/* WARNING: Removing unreachable block (ram,0xfffd117a) */
/* WARNING: Removing unreachable block (ram,0xfffd11ac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd1130(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar2 = sd_save_xfer_id();
  if (bVar1 != uVar2) {
    uVar3 = sd_abort_no_card();
    return uVar3;
  }
  if (CONCAT11(PTR_g_ui_00025d60->sd_answer[1],PTR_g_ui_00025d60->sd_answer[2]) != _DAT_0001ff02) {
    uVar3 = sd_abort_no_card();
    return uVar3;
  }
  if (CONCAT11(PTR_g_ui_00025d60->sd_answer[3],PTR_g_ui_00025d60->sd_answer[4]) == _DAT_0001ff04) {
    _DAT_0001ff02 = _DAT_0001ff02 + _DAT_0001ff04;
    DAT_00015de4 = DAT_00015de4 + -1;
    if (DAT_00015de4 == '\x01') {
      if (DAT_00015de5 == '\0') {
        _DAT_0001ff04 = 0xc25 - _DAT_0001ff02;
      }
      else {
        _DAT_0001ff04 = 0x2f4b - _DAT_0001ff02;
      }
    }
    if (DAT_00015de4 != '\0') {
      uVar3 = FUN_fffd0fcd();
      return uVar3;
    }
    uVar3 = FUN_fffd1252();
    PTR_g_ui_00025d60->sd_step = 10;
    return uVar3;
  }
  uVar3 = sd_abort_no_card();
  return uVar3;
}


// ===== FUN_fffd1252 @ fffd1252 (171 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd12fa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * FUN_fffd1252(void)

{
  ui_state *puVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  PTR_g_ui_00025d60->dl_req_sd = 1;
  puVar1 = PTR_g_ui_00025d60;
  bVar2 = sd_save_xfer_id();
  puVar1->sdreq_op = bVar2;
  PTR_g_ui_00025d60->sdreq_arg1 = 0x10;
  PTR_g_ui_00025d60->sdreq_arg2 = 0x50;
  PTR_g_ui_00025d60->sdreq_arg3 = (byte)((ushort)_DAT_0001ff04 >> 8);
  PTR_g_ui_00025d60->sdreq_arg4 = DAT_0001ff04;
  pbVar3 = PTR_g_ui_00025d60->sdreq_data;
  pbVar4 = &DAT_00015dea;
  for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar3 = *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  }
  PTR_g_ui_00025d60->sdreq_data[0xf] = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return pbVar3;
}

