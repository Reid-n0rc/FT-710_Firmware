// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe4c55 @ fffe4c55 (108 bytes)

void FUN_fffe4c55(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d78->kbd_open == 0) {
    if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->keypad_open != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (g_ui.dl_req_40 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    beep_request(1);
    FUN_fffe506d();
  }
  else {
    FUN_fffe5092();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffe4cc1 @ fffe4cc1 (103 bytes)

void FUN_fffe4cc1(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d78->kbd_open != 0) {
    FUN_fffe5092();
    return;
  }
  if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->keypad_open != 1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (g_ui.dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    beep_request(1);
    FUN_fffe506d();
    return;
  }
  return;
}


// ===== FUN_fffe4d28 @ fffe4d28 (123 bytes)

void FUN_fffe4d28(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->keypad_open != 1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (g_ui.dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00018872 == '\x01') {
      vfo_step_down(g_opstate.active_vfo);
      FUN_fffe40e5();
      beep_request(1);
      return;
    }
    FUN_fffe5129();
    ladder_key_delay();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffe4da3 @ fffe4da3 (64 bytes)

void FUN_fffe4da3(void)

{
  int iVar1;
  
  if (DAT_00018872 == '\x01') {
    iVar1 = FUN_fffe415d();
    if (iVar1 == 1) {
      if (PTR_g_ui_00025d78->ch_step_mode == 1) {
        vfo_step_down(g_opstate.active_vfo);
      }
      FUN_fffe40e5();
      return;
    }
  }
  else {
    iVar1 = ladder_key_delay();
    if (iVar1 == 1) {
      FUN_fffe5129();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4de3 @ fffe4de3 (1 bytes)

void FUN_fffe4de3(void)

{
  return;
}


// ===== FUN_fffe4de4 @ fffe4de4 (1 bytes)

void FUN_fffe4de4(void)

{
  return;
}


// ===== msg_cw_send_start @ fffe4de5 (137 bytes)

/* (ch): CW only; the same slot running -> msg_cw_stop, else sets +0x1CC / +0x1CD and starts slot ch
   [fact] */

undefined1 msg_cw_send_start(byte param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 uStack_3;
  
  iVar2 = vfo_mode_is_cw();
  if (iVar2 == 0) {
    uStack_3 = 0;
  }
  else {
    if ((PTR_g_ui_00025d78->ky_send_0 == 1) || (PTR_g_ui_00025d78->ky_send_1 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (param_1 == PTR_g_ui_00025d78->msg_slot)) {
      msg_cw_stop();
      uStack_3 = 0;
    }
    else {
      iVar2 = FUN_fffe5544(param_1);
      if (iVar2 == 0) {
        PTR_g_ui_00025d78->ky_send_0 = 1;
      }
      else {
        PTR_g_ui_00025d78->ky_send_1 = 1;
      }
      iVar2 = FUN_fffe55ab(param_1);
      if (iVar2 == 0) {
        uStack_3 = 0;
      }
      else {
        msg_slot_select(param_1);
        uStack_3 = 1;
      }
    }
  }
  return uStack_3;
}


// ===== FUN_fffe4e6e @ fffe4e6e (142 bytes)

void FUN_fffe4e6e(byte param_1)

{
  int iVar1;
  
  if (PTR_g_ui_00025d78->msgmem_type == 0) {
    PTR_g_ui_00025d78->dvs_slot = param_1 - 1;
    PTR_g_ui_00025d78->msg_slot = param_1;
    PTR_g_ui_00025d78->dvs_armed = 1;
    FUN_fffe4efc();
    return;
  }
  if (PTR_g_ui_00025d78->msgmem_type != 1) {
    return;
  }
  PTR_g_ui_00025d78->dvs_busy = 0;
  PTR_g_ui_00025d78->msg_tx_wait = 0;
  iVar1 = FUN_fffe5544(param_1);
  if (iVar1 != 1) {
    FUN_fffe5350(param_1);
    return;
  }
  PTR_g_ui_00025d78->msg_rec_active = 1;
  msg_slot_select(param_1);
  PTR_g_ui_00025d78->keyer_state = 2;
  return;
}


// ===== FUN_fffe4efc @ fffe4efc (25 bytes)

void FUN_fffe4efc(void)

{
  swtimer_start(0x37,10000);
  PTR_g_ui_00025d78->msg_tx_wait = 1;
  return;
}


// ===== FUN_fffe4f15 @ fffe4f15 (109 bytes)

void FUN_fffe4f15(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d78->kbd_open != 0) {
    beep_request(1);
    FUN_fffe4f82();
    return;
  }
  beep_request(1);
  if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->keypad_open != 1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (g_ui.dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffe52dd();
    return;
  }
  return;
}


// ===== FUN_fffe4f82 @ fffe4f82 (39 bytes)

void FUN_fffe4f82(void)

{
  if (PTR_g_ui_00025d78->kbd_cursor != 0) {
    PTR_g_ui_00025d78->kbd_cursor = PTR_g_ui_00025d78->kbd_cursor - 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe4fa9 @ fffe4fa9 (73 bytes)

void FUN_fffe4fa9(void)

{
  DAT_00018872 = 0;
  if (g_ui.dl_req_40 == 1) {
    beep_request(1);
    return;
  }
  if (PTR_g_ui_00025d78->kbd_open != 0) {
    beep_request(1);
    FUN_fffe4ff2();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe60a6();
  beep_request(1);
  return;
}


// ===== FUN_fffe4ff2 @ fffe4ff2 (14 bytes)

void FUN_fffe4ff2(void)

{
  int iVar1;
  
  iVar1 = FUN_fffe5211();
  if (iVar1 != 0) {
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe5000 @ fffe5000 (109 bytes)

void FUN_fffe5000(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d78->kbd_open != 0) {
    beep_request(1);
    FUN_fffe5092();
    return;
  }
  beep_request(1);
  if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->keypad_open != 1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (g_ui.dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffe506d();
    return;
  }
  return;
}


// ===== FUN_fffe506d @ fffe506d (37 bytes)

void FUN_fffe506d(void)

{
  PTR_g_ui_00025d78->ch_knob_mode = 0;
  if (PTR_g_ui_00025d78->scan_running != 1) {
    FUN_fffe5302();
    return;
  }
  FUN_fffe5d2a();
  return;
}


// ===== FUN_fffe5092 @ fffe5092 (78 bytes)

void FUN_fffe5092(void)

{
  byte bVar1;
  byte local_1;
  
  bVar1 = PTR_g_ui_00025d78->kbd_target;
  if (bVar1 == 5) {
    local_1 = 0xf;
  }
  else if (bVar1 == 2) {
    local_1 = 0x32;
  }
  else if (bVar1 < 2) {
    local_1 = 0xc;
  }
  if ((int)(local_1 - 1) <= (int)(uint)PTR_g_ui_00025d78->kbd_cursor) {
    beep_request(3);
    return;
  }
  PTR_g_ui_00025d78->kbd_cursor = PTR_g_ui_00025d78->kbd_cursor + 1;
  return;
}


// ===== FUN_fffe50e0 @ fffe50e0 (73 bytes)

void FUN_fffe50e0(void)

{
  DAT_00018872 = 0;
  if (g_ui.dl_req_40 == 1) {
    beep_request(1);
    return;
  }
  if (PTR_g_ui_00025d78->kbd_open != 0) {
    beep_request(1);
    FUN_fffe5129();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe6138();
  beep_request(1);
  return;
}


// ===== FUN_fffe5129 @ fffe5129 (14 bytes)

void FUN_fffe5129(void)

{
  int iVar1;
  
  iVar1 = FUN_fffe5180();
  if (iVar1 != 0) {
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe5137 @ fffe5137 (1 bytes)

void FUN_fffe5137(void)

{
  return;
}


// ===== FUN_fffe5138 @ fffe5138 (72 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe517d) */

void FUN_fffe5138(void)

{
  ui_state *puVar1;
  ushort uVar2;
  
  puVar1 = PTR_g_ui_00025d78;
  uVar2 = contest_number_get();
  puVar1->msg_timer = uVar2;
  if (1 < PTR_g_ui_00025d78->msg_timer) {
    PTR_g_ui_00025d78->msg_timer = PTR_g_ui_00025d78->msg_timer - 1;
  }
  FUN_fffba336(PTR_g_ui_00025d78->msg_timer);
  beep_request(1);
  return;
}


// ===== FUN_fffe5180 @ fffe5180 (145 bytes)

bool FUN_fffe5180(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar2 = (uint)PTR_g_ui_00025d78->kbd_target;
  if (1 < uVar2) {
    if (uVar2 == 2) {
      iVar3 = FUN_fffe52a1();
      pbVar4 = (byte *)(iVar3 + (uint)PTR_g_ui_00025d78->kbd_cursor);
      if (0x7c < *pbVar4) {
        return false;
      }
      *pbVar4 = *pbVar4 + 1;
      if (*pbVar4 == 0x60) {
        *pbVar4 = 0x7d;
      }
      return true;
    }
    if (uVar2 - 3 < 2) {
      return true;
    }
    if (uVar2 != 5) {
      return false;
    }
  }
  iVar3 = FUN_fffe52a1();
  pbVar4 = (byte *)(iVar3 + (uint)PTR_g_ui_00025d78->kbd_cursor);
  bVar1 = *pbVar4;
  if (bVar1 < 0x70) {
    *pbVar4 = *pbVar4 + 1;
  }
  return bVar1 < 0x70;
}


// ===== FUN_fffe5211 @ fffe5211 (144 bytes)

bool FUN_fffe5211(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  bool local_9;
  
  bVar1 = PTR_g_ui_00025d78->kbd_target;
  if (1 < bVar1) {
    if (bVar1 == 2) {
      iVar2 = FUN_fffe52a1();
      pbVar3 = (byte *)(iVar2 + (uint)PTR_g_ui_00025d78->kbd_cursor);
      if (0x20 < *pbVar3) {
        *pbVar3 = *pbVar3 - 1;
        if (*pbVar3 == 0x7c) {
          *pbVar3 = 0x5f;
        }
        return true;
      }
      *pbVar3 = 0x20;
      return false;
    }
    if (bVar1 == 4) {
      return true;
    }
    if (bVar1 != 5) {
      return false;
    }
  }
  iVar2 = FUN_fffe52a1();
  pbVar3 = (byte *)(iVar2 + (uint)PTR_g_ui_00025d78->kbd_cursor);
  bVar1 = *pbVar3;
  if (bVar1 < 0x21) {
    *pbVar3 = 0x20;
  }
  else {
    *pbVar3 = *pbVar3 - 1;
  }
  local_9 = bVar1 >= 0x21;
  return local_9;
}


// ===== FUN_fffe52a1 @ fffe52a1 (60 bytes)

void FUN_fffe52a1(void)

{
  return;
}


// ===== FUN_fffe52dd @ fffe52dd (37 bytes)

void FUN_fffe52dd(void)

{
  PTR_g_ui_00025d78->ch_knob_mode = 1;
  if (PTR_g_ui_00025d78->scan_running != 1) {
    FUN_fffe5302();
    return;
  }
  FUN_fffe5d2a();
  return;
}


// ===== FUN_fffe5302 @ fffe5302 (78 bytes)

void FUN_fffe5302(void)

{
  vfo_side vVar1;
  
  vVar1 = g_opstate.active_vfo;
  PTR_g_ui_00025d78->step_fast_req = 1;
  PTR_g_ui_00025d78->step_fast_100k = 1;
  FUN_fffc5c8f(vVar1,1);
  PTR_g_ui_00025d78->step_fast_req = 0;
  PTR_g_ui_00025d78->step_fast_100k = 0;
  return;
}


// ===== FUN_fffe5350 @ fffe5350 (63 bytes)

void FUN_fffe5350(undefined1 param_1)

{
  PTR_g_ui_00025d78->kbd_open = 1;
  PTR_g_ui_00025d78->kbd_target = 2;
  PTR_g_ui_00025d78->kbd_layout = 0;
  PTR_g_ui_00025d78->kbd_cursor = 0;
  msg_slot_select(param_1);
  displink_39_keyer_texts();
  return;
}


// ===== msg_slot_select @ fffe538f (49 bytes)

/* (n): UI +0x1C8 = n, +0xBF = +0x1CE = n-1 (KY) */

void msg_slot_select(byte param_1)

{
  PTR_g_ui_00025d78->msg_slot = param_1;
  PTR_g_ui_00025d78->msg_slot_idx = param_1 - 1;
  PTR_g_ui_00025d78->msg_channel = param_1 - 1;
  return;
}


// ===== msg_cw_stop @ fffe53c0 (65 bytes)

/* Clears +0x1CC, +0x1CD, +0x417, +0x1D1; keyer state +0x2B = 7 (idle) [fact] */

void msg_cw_stop(void)

{
  PTR_g_ui_00025d78->ky_send_0 = 0;
  PTR_g_ui_00025d78->ky_send_1 = 0;
  PTR_g_ui_00025d78->dvs_busy = 0;
  PTR_g_ui_00025d78->msg_active = 0;
  PTR_g_ui_00025d78->keyer_state = 7;
  return;
}


// ===== FUN_fffe5401 @ fffe5401 (323 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe551d) */
/* WARNING: Removing unreachable block (ram,0xfffe5477) */
/* WARNING: Removing unreachable block (ram,0xfffe54af) */
/* WARNING: Removing unreachable block (ram,0xfffe54e6) */
/* WARNING: Removing unreachable block (ram,0xfffe543f) */

ushort FUN_fffe5401(char param_1)

{
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined1 local_5;
  
  if (param_1 == '\x05') {
    local_5 = g_opstate.ex020210_cw_memory_5;
    local_8 = (ushort)DAT_0000976b;
    local_a = CONCAT11(DAT_00009607,DAT_00009608);
  }
  else if (param_1 == '\x02') {
    local_5 = g_opstate.ex020207_cw_memory_2;
    local_8 = (ushort)DAT_000096d2;
    local_a = CONCAT11(DAT_0000943f,DAT_00009440);
  }
  else if (param_1 == '\x03') {
    local_5 = g_opstate.ex020208_cw_memory_3;
    local_8 = (ushort)DAT_00009705;
    local_a = CONCAT11(DAT_000094d7,DAT_000094d8);
  }
  else if (param_1 == '\x04') {
    local_5 = g_opstate.ex020209_cw_memory_4;
    local_8 = (ushort)DAT_00009738;
    local_a = CONCAT11(DAT_0000956f,DAT_00009570);
  }
  else if (param_1 == '\x01') {
    local_5 = g_opstate.ex020206_cw_memory_1;
    local_8 = (ushort)DAT_0000969f;
    local_a = CONCAT11(DAT_000093a7,DAT_000093a8);
  }
  if (local_5 == 0) {
    local_c = local_8;
  }
  else {
    local_c = local_a;
  }
  return local_c;
}


// ===== FUN_fffe5544 @ fffe5544 (38 bytes)

byte FUN_fffe5544(byte param_1)

{
  return g_opstate.ex020205_contest_number_be[param_1 + 1];
}


// ===== FUN_fffe556a @ fffe556a (65 bytes)

void FUN_fffe556a(void)

{
  PTR_g_ui_00025d78->msg_rec_active = 0;
  PTR_g_ui_00025d78->dvs_armed = 0;
  PTR_g_ui_00025d78->dvs_busy = 0;
  PTR_g_ui_00025d78->dvs_state = 0;
  PTR_g_ui_00025d78->msg_tx_wait = 0;
  return;
}


// ===== FUN_fffe55ab @ fffe55ab (160 bytes)

undefined1 FUN_fffe55ab(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffe564b();
  if (iVar2 == 0) {
    PTR_g_ui_00025d78->ky_send_1 = 0;
    PTR_g_ui_00025d78->ky_send_0 = 0;
    return 0;
  }
  if ((PTR_g_ui_00025d78->ky_send_0 == 1) || (PTR_g_ui_00025d78->ky_send_1 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (PTR_g_ui_00025d78->keyer_state != 1) {
      msg_cw_stop();
      return 0;
    }
    iVar2 = FUN_fffe5401(param_1);
    if (iVar2 == 0) {
      PTR_g_ui_00025d78->ky_send_1 = 0;
      PTR_g_ui_00025d78->ky_send_0 = 0;
      beep_request(3);
      return 0;
    }
    PTR_g_ui_00025d78->keyer_state = 5;
  }
  return 1;
}


// ===== FUN_fffe564b @ fffe564b (69 bytes)

undefined1 FUN_fffe564b(void)

{
  uint uVar1;
  
  if (PTR_g_ui_00025d78->cw_spot_on == 1) {
    return 0;
  }
  uVar1 = (uint)PTR_g_ui_00025d78->keyer_state;
  if (1 < uVar1) {
    if (uVar1 - 2 < 3) {
      return 0;
    }
    if (2 < uVar1 - 5) {
      return 1;
    }
  }
  return 1;
}


// ===== vfo_mode_is_cw @ fffe5690 (47 bytes)

/* vfo_mode(1) is 2 or 3 [fact] */

bool vfo_mode_is_cw(void)

{
  radio_mode rVar1;
  bool bStack_3;
  
  rVar1 = vfo_mode(VFO_TX);
  if ((rVar1 == MODE_CW_U) || (rVar1 == MODE_CW_L)) {
    bStack_3 = false;
  }
  else {
    bStack_3 = true;
  }
  bStack_3 = !bStack_3;
  return bStack_3;
}


// ===== msg_voice_mode_ok @ fffe56bf (37 bytes)

/* 1 when the TX mode class (vfo_mode(1)) is < 2 or 4..7, i.e. not CW [fact] */

undefined1 msg_voice_mode_ok(void)

{
  radio_mode rVar1;
  undefined1 uStack_3;
  
  rVar1 = vfo_mode(VFO_TX);
  if ((rVar1 < 2) || (rVar1 - 4 < 4)) {
    uStack_3 = 1;
  }
  else {
    uStack_3 = 0;
  }
  return uStack_3;
}


// ===== FUN_fffe56e4 @ fffe56e4 (159 bytes)

void FUN_fffe56e4(byte param_1)

{
  ui_state *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined1 local_84 [4];
  undefined4 *local_80;
  char acStack_79 [120];
  byte local_1;
  
  pcVar3 = "     RM 1";
  pcVar2 = acStack_79;
  local_1 = param_1;
  for (iVar4 = 0x78; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  if ((local_1 == 0) || (0xc < local_1)) {
    local_84 = (undefined1  [4])0x0;
  }
  else {
    local_84 = (undefined1  [4])0x1;
  }
  if ((local_84 != (undefined1  [4])0x0) &&
     (local_80 = (undefined4 *)(local_84 + (uint)local_1 * 10 + 1),
     PTR_g_ui_00025d78->numentry_mode == 1)) {
    beep_request(1);
    popup_close();
    PTR_g_ui_00025d78->popup_code = 0x5e;
    puVar1 = PTR_g_ui_00025d78;
    *(undefined2 *)(PTR_g_ui_00025d78->popup_text + 8) = *(undefined2 *)(local_80 + 2);
    *(undefined4 *)(puVar1->popup_text + 4) = local_80[1];
    *(undefined4 *)puVar1->popup_text = *local_80;
    popup_duration_get(0x5e);
    popup_open_timed();
    PTR_g_ui_00025d78->key_consumed = 1;
    return;
  }
  return;
}


// ===== FUN_fffe5783 @ fffe5783 (203 bytes)

byte FUN_fffe5783(void)

{
  byte bVar1;
  byte local_3;
  byte local_2;
  
  local_2 = 0;
  if (PTR_g_ui_00025d78->msgmem_type == 1) {
    if ((g_opstate.ex020206_cw_memory_1 == 0) && (bVar1 = FUN_fffe584e(0x96a0), bVar1 == 1)) {
      local_2 = 1;
    }
    if ((g_opstate.ex020207_cw_memory_2 == 0) && (bVar1 = FUN_fffe584e(0x96d3), bVar1 == 1)) {
      local_2 = local_2 | 2;
    }
    if ((g_opstate.ex020208_cw_memory_3 == 0) && (bVar1 = FUN_fffe584e(0x9706), bVar1 == 1)) {
      local_2 = local_2 | 4;
    }
    if ((g_opstate.ex020209_cw_memory_4 == 0) && (bVar1 = FUN_fffe584e(0x9739), bVar1 == 1)) {
      local_2 = local_2 | 8;
    }
    if ((g_opstate.ex020210_cw_memory_5 == 0) && (bVar1 = FUN_fffe584e(0x976c), bVar1 == 1)) {
      local_2 = local_2 | 0x10;
    }
    local_3 = local_2;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


// ===== FUN_fffe584e @ fffe584e (49 bytes)

byte FUN_fffe584e(int param_1)

{
  byte local_6;
  
  local_6 = 0;
  while( true ) {
    if (0x31 < local_6) {
      return 0;
    }
    if (*(char *)((uint)local_6 + param_1) == '#') break;
    local_6 = local_6 + 1;
  }
  return 1;
}


// ===== scan_task @ fffe587f (411 bytes)

/* Main-loop scan state machine (0x18877), run flag 0x20F1C */

void scan_task(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffe61ca();
  if ((PTR_g_ui_00025d7c->scan_running == 0) || (PTR_g_ui_00025d7c->zz_align_mode == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    switch(DAT_00018877) {
    case 0:
      PTR_g_ui_00025d7c->scan_hold = 0;
      FUN_fffe5a1a();
      return;
    case 1:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5ab2();
        if (iVar2 == 0) {
          PTR_g_ui_00025d7c->scan_hold = 0;
          FUN_fffe5e67();
          DAT_00018877 = 2;
          return;
        }
        PTR_g_ui_00025d7c->scan_hold = 1;
        FUN_fffe5a1a();
        return;
      }
      break;
    case 2:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5acf();
        if (iVar2 == 0) {
          FUN_fffe5a47();
          return;
        }
        iVar2 = FUN_fffe5ab2();
        if (iVar2 == 0) {
          FUN_fffe5a2a();
          return;
        }
        iVar2 = FUN_fffe5fdd();
        if (iVar2 == 0) {
          FUN_fffe5a2a();
          return;
        }
        iVar2 = FUN_fffe600f();
        if (iVar2 != 1) {
          FUN_fffe5a2a();
          return;
        }
        DAT_00018873 = 1;
        swtimer_start(0x33,500);
        DAT_00018877 = 3;
        return;
      }
      break;
    case 3:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5acf();
        if (iVar2 == 1) {
          FUN_fffe5a2a();
          return;
        }
        FUN_fffe5a47();
        return;
      }
      break;
    case 4:
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 1) {
        DAT_00018874 = 1;
        swtimer_start(0x34,0x5dc);
        DAT_00018877 = 5;
        return;
      }
      break;
    case 5:
      iVar2 = FUN_fffe5f18();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 0) {
        DAT_00018877 = 4;
        return;
      }
      break;
    case 6:
      iVar2 = FUN_fffe5f4d();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 1) {
        DAT_00018874 = 1;
        swtimer_start(0x34,0x5dc);
        DAT_00018877 = 7;
        return;
      }
      break;
    case 7:
      iVar2 = FUN_fffe5f4d();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5f18();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 0) {
        DAT_00018877 = 6;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffe5a1a @ fffe5a1a (16 bytes)

void FUN_fffe5a1a(void)

{
  scan_step();
  FUN_fffe5e67();
  DAT_00018877 = 1;
  return;
}


// ===== FUN_fffe5a2a @ fffe5a2a (29 bytes)

void FUN_fffe5a2a(void)

{
  PTR_g_ui_00025d7c->scan_hold = 0;
  scan_step();
  FUN_fffe5e67();
  DAT_00018877 = 2;
  return;
}


// ===== FUN_fffe5a47 @ fffe5a47 (107 bytes)

void FUN_fffe5a47(void)

{
  bool bVar1;
  vfo_side vVar2;
  byte bVar3;
  int iVar4;
  
  vVar2 = g_opstate.active_vfo;
  PTR_g_ui_00025d7c->scan_hold = 1;
  iVar4 = FUN_fffe5f82();
  if ((iVar4 == 0) || (bVar3 = vfo_is_memory(vVar2), bVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(6);
    if (g_opstate.ex030117_mic_scan_resume == 1) {
      FUN_fffe5ece();
      DAT_00018877 = 6;
      return;
    }
    DAT_00018877 = 4;
    return;
  }
  scan_step();
  FUN_fffe5eba();
  return;
}


// ===== FUN_fffe5ab2 @ fffe5ab2 (29 bytes)

bool FUN_fffe5ab2(void)

{
  return g_ui.squelch_open == 1;
}


// ===== FUN_fffe5acf @ fffe5acf (24 bytes)

bool FUN_fffe5acf(void)

{
  bool bVar1;
  
  bVar1 = af_mute_get();
  return bVar1;
}


// ===== FUN_fffe5ae7 @ fffe5ae7 (24 bytes)

bool FUN_fffe5ae7(void)

{
  bool bVar1;
  
  bVar1 = af_mute_get();
  return bVar1;
}


// ===== scan_allowed @ fffe5aff (82 bytes)

byte scan_allowed(void)

{
  undefined1 local_4;
  undefined1 local_3;
  
  if (g_opstate.ex030116_mic_scan == 0) {
    local_4 = 0;
  }
  else {
    if (g_opstate.active_vfo == VFO_A) {
      local_3 = g_opstate.vfo_state_a;
    }
    else {
      local_3 = g_opstate.vfo_state_b;
    }
    if (local_3 == VFO_STATE_MEMORY) {
      local_4 = FUN_fffe5b51();
    }
    else {
      local_4 = 1;
    }
  }
  return local_4;
}


// ===== FUN_fffe5b51 @ fffe5b51 (213 bytes)

byte FUN_fffe5b51(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  byte bStack_7;
  
  if (g_opstate.ex030114_mem_group == 0) {
    bStack_7 = FUN_fffe5c26('\0',99);
  }
  else {
    bVar2 = FUN_fff9bfb8();
    if (bVar2 < 8) {
      if (bVar2 == 7) {
        uVar3 = dest_code_get();
        if ((uVar3 == 0xd950) || (uVar3 == 0xa4c5)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          bStack_7 = FUN_fffe5c26('u',7);
        }
        else {
          if ((uVar3 == 0x315b) || (uVar3 == 0x50e2)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            bStack_7 = FUN_fffe5c26('u',0xf);
          }
          else {
            bStack_7 = 0;
          }
        }
      }
      else if (bVar2 == 6) {
        bStack_7 = FUN_fffe5c26('c',0x12);
      }
      else {
        bStack_7 = FUN_fffe5c26("RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                                [bVar2 + 0x3d92],BYTE_ARRAY_fff872a8[bVar2 + 3]);
      }
    }
    else {
      bStack_7 = 0;
    }
  }
  return bStack_7;
}


// ===== FUN_fffe5c26 @ fffe5c26 (88 bytes)

byte FUN_fffe5c26(char param_1,byte param_2)

{
  bool bVar1;
  int iVar2;
  byte *pbStack_c;
  byte local_5;
  byte local_4;
  byte local_2;
  char local_1;
  
  local_5 = 0;
  local_4 = 0;
  local_2 = param_2;
  local_1 = param_1;
  while( true ) {
    if (local_2 <= local_4) {
      return 0;
    }
    bVar1 = memch_valid(local_1 + local_4,&pbStack_c);
    if (((bVar1) && (iVar2 = memch_skip_get(local_1 + local_4), iVar2 == 0)) &&
       (local_5 = local_5 + 1, 1 < local_5)) break;
    local_4 = local_4 + 1;
  }
  return 1;
}


// ===== scan_start_up @ fffe5c7e (49 bytes)

/* SC1 */

void scan_start_up(void)

{
  DAT_00018876 = 0;
  DAT_00018877 = 0;
  if (PTR_g_ui_00025d7c->scan_running != 0) {
    return;
  }
  PTR_g_ui_00025d7c->scan_running = 1;
  return;
}


// ===== scan_start_down @ fffe5caf (49 bytes)

/* SC2 */

void scan_start_down(void)

{
  DAT_00018876 = 1;
  DAT_00018877 = 0;
  if (PTR_g_ui_00025d7c->scan_running != 0) {
    return;
  }
  PTR_g_ui_00025d7c->scan_running = 1;
  return;
}

