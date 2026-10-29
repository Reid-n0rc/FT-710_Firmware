// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex060518 @ fffec2df (6 bytes)

/* AI change detector for menu item EX060518 (table 0xFFF8E1A0[295]) */

void ai_ex060518(void)

{
  FUN_fffebf4d(5);
  return;
}


// ===== ai_ex_fmt_u8 @ fffec2e5 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec3f5) */
/* WARNING: Removing unreachable block (ram,0xfffec3af) */
/* WARNING: Removing unreachable block (ram,0xfffec329) */
/* CAT AI EX reply value at 0x1B23D: u8 as 2 (arg 0) or 3 (arg 1) digits, or signed +/- 2 digits
   (3rd arg 0), then ';'; returns the reply length that the ai_ex* detectors store to 0x1FF12 [fact]
    */

short ai_ex_fmt_u8(byte param_1,char param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  short sStack_10;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_5;
  
  local_5 = param_1;
  if (param_3 == 0) {
    if (param_2 == '\0') {
      local_d = 10;
      local_e = 2;
    }
    else if (param_2 == '\x01') {
      local_d = 100;
      local_e = 3;
    }
    for (local_c = 0; local_c < local_e; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23d)[local_c] = cVar1;
    }
    (&DAT_0001b23d)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_0001b23d = 0x2b;
    }
    else {
      DAT_0001b23d = 0x2d;
      local_5 = ~param_1 + 1;
    }
    local_d = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23e)[local_c] = cVar1;
    }
    (&DAT_0001b23e)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== ai_ex_fmt_u16_4 @ fffec3f8 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec469) */
/* WARNING: Removing unreachable block (ram,0xfffec422) */
/* CAT AI EX reply value at 0x1B23D: u16 as 4 digits + ';'; returns the reply length [fact] */

short ai_ex_fmt_u16_4(ushort param_1)

{
  char cVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_c;
  byte local_a;
  ushort local_6;
  
  local_c = 1000;
  local_6 = param_1;
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    uVar2 = (uint)local_6;
    if (local_c != 0) {
      uVar2 = uVar2 / local_c;
    }
    uVar3 = local_6;
    if (local_c != 0) {
      uVar3 = local_6 / local_c;
    }
    local_6 = local_6 - uVar3 * local_c;
    local_c = local_c / 10;
    cVar1 = nib2hex((byte)uVar2);
    (&DAT_0001b23d)[local_a] = cVar1;
  }
  (&DAT_0001b23d)[local_a] = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== tuner_init @ fffec46c (7 bytes)

/* tuner_task once + FUN_fffec578 */

void tuner_init(void)

{
  tuner_task();
  tuner_rearm();
  return;
}


// ===== tuner_task @ fffec473 (32 bytes)

/* main_loop task 16: antenna tuner, dispatch on tuner select 0x9AB8 [inference] */

void tuner_task(void)

{
  if (g_opstate.ex030104_tuner_type_select == 3) {
    FUN_fffed165();
    return;
  }
  if (1 < g_opstate.ex030104_tuner_type_select) {
    FUN_fffed62a();
    return;
  }
  FUN_fffec62b();
  return;
}


// ===== FUN_fffec493 @ fffec493 (72 bytes)

void FUN_fffec493(void)

{
  DAT_0001b3bc = g_opstate.meter_sel;
  g_opstate.meter_sel = 5;
  DAT_0001b3bd = g_opstate.ex020117_cw_wave_shape;
  g_opstate.ex020117_cw_wave_shape = 0;
  g_ui.popup_code = 0x49;
  popup_open_timed(0);
  return;
}


// ===== FUN_fffec4db @ fffec4db (37 bytes)

void FUN_fffec4db(void)

{
  g_opstate.meter_sel = DAT_0001b3bc;
  g_opstate.ex020117_cw_wave_shape = DAT_0001b3bd;
  popup_close();
  return;
}


// ===== FUN_fffec500 @ fffec500 (15 bytes)

undefined1 FUN_fffec500(void)

{
  return DAT_0001b3ad;
}


// ===== FUN_fffec50f @ fffec50f (15 bytes)

undefined1 FUN_fffec50f(void)

{
  return DAT_0001b3af;
}


// ===== FUN_fffec51e @ fffec51e (15 bytes)

undefined1 FUN_fffec51e(void)

{
  return DAT_0001b3b1;
}


// ===== FUN_fffec52d @ fffec52d (10 bytes)

void FUN_fffec52d(void)

{
  DAT_0001b3ac = 0x10;
  return;
}


// ===== vfo_tuner_bit_set @ fffec537 (35 bytes)

/* (on): TX-side record rec+1 bit 2, the tuner bit that FUN_fffec55a reads for CAT AC [fact] */

void vfo_tuner_bit_set(char param_1)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  if (param_1 != '\0') {
    pvVar1->flags1 = pvVar1->flags1 | 4;
    return;
  }
  pvVar1->flags1 = pvVar1->flags1 & 0xfb;
  return;
}


// ===== FUN_fffec55a @ fffec55a (30 bytes)

bool FUN_fffec55a(void)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  return (pvVar1->flags1 & 4) != 0;
}


// ===== tuner_rearm @ fffec578 (179 bytes)

/* TUNER TYPE SELECT 0x9AB8 = 2 path: re-arms the tuner state 0x20B3F after VFO/band changes [fact
   for the callers] (cat-commands-primary.md) */

void tuner_rearm(void)

{
  bool bVar1;
  int iVar2;
  
  if (g_opstate.ex030104_tuner_type_select == 2) {
    iVar2 = FUN_fffed6f5();
    if (iVar2 == 1) {
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        if ((g_ui.atu_state == 4) || (g_ui.atu_state == 5)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          g_ui.atu_state = 6;
          return;
        }
      }
      else if (g_ui.atu_state == 0) {
        g_ui.atu_state = 4;
        return;
      }
    }
  }
  else if (g_opstate.ex030104_tuner_type_select < 2) {
    iVar2 = FUN_fffec55a();
    if (iVar2 == 0) {
      if ((g_ui.atu_state == 1) || (g_ui.atu_state == 2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        g_ui.atu_state = 3;
        return;
      }
    }
    else if (g_ui.atu_state == 0) {
      g_ui.atu_state = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffec62b @ fffec62b (223 bytes)

void FUN_fffec62b(void)

{
  bool bVar1;
  byte bVar2;
  
  g_ui.tuner_indicator = 0;
  if ((g_ui.atu_state == 2) || (g_ui.atu_state == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    g_ui.tuner_indicator = 1;
    if ((g_ui.tune_cycle_3d == 2) && (bVar2 = blink_phase(0), bVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      g_ui.tuner_indicator = 0;
    }
  }
  switch(DAT_0001b3ac) {
  case 1:
    FUN_fffec728();
    return;
  case 2:
    FUN_fffec7f9();
    return;
  case 3:
    FUN_fffec881();
    return;
  case 4:
    FUN_fffec8a1();
    return;
  case 5:
    FUN_fffec911();
    return;
  case 6:
  case 10:
    FUN_fffec9b4();
    return;
  case 7:
  case 0xb:
    FUN_fffeca48();
    return;
  case 8:
    FUN_fffeca7e();
    return;
  case 9:
    FUN_fffecba2();
    return;
  case 0xc:
    FUN_fffecce7();
    return;
  case 0xd:
    FUN_fffecde6();
    return;
  case 0xe:
    FUN_fffece39();
    return;
  case 0xf:
    FUN_fffece69();
    return;
  case 0x10:
    FUN_fffece79();
    return;
  default:
    FUN_fffec70a();
    return;
  case 0x14:
  case 0x15:
    FUN_fffec9ed();
    return;
  }
}


// ===== FUN_fffec70a @ fffec70a (30 bytes)

void FUN_fffec70a(void)

{
  g_ui.tune_cycle_3d = 0;
  g_ui.atu_state = 0;
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffec728 @ fffec728 (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec7d5) */
/* WARNING: Removing unreachable block (ram,0xfffec7e2) */

void FUN_fffec728(void)

{
  uint uVar1;
  char cStack_5;
  
  uVar1 = g_ui.freq_tx;
  if (g_ui.tune_cycle_3d == 1) {
    DAT_0001b3ac = 2;
  }
  else if (g_ui.atu_state == 3) {
    g_ui.atu_state = 0;
  }
  else {
    if (g_ui.transmitting == 0) {
      return;
    }
    if (g_ui.atu_state == 1) {
      cStack_5 = FUN_fffecfac(g_ui.freq_tx);
      if (cStack_5 == -1) {
        cStack_5 = FUN_fffed0ae(uVar1);
      }
      if (cStack_5 != -1) {
        DAT_00025d00 = uVar1;
        DAT_0001b3bb = tx_band_of_freq(uVar1);
        FUN_fffed12f();
        g_ui.atu_state = 2;
      }
    }
  }
  if ((g_ui.atu_state == 2) && (DAT_00025d00 / 10000 != uVar1 / 10000)) {
    g_ui.atu_state = 1;
    return;
  }
  return;
}


// ===== FUN_fffec7f9 @ fffec7f9 (136 bytes)

void FUN_fffec7f9(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = g_ui.freq_tx;
  bVar2 = tx_freq_allowed(g_ui.freq_tx);
  if (bVar2) {
    DAT_00025d00 = uVar1;
    DAT_0001b3bb = tx_band_of_freq(uVar1);
    FUN_fffec493();
    g_ui.tune_cycle_3d = 2;
    g_ui.ptt_atu_tune = 1;
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
    FUN_fffed12f();
    g_ui.atu_state = 0;
    swtimer_start(0x27,100);
    DAT_0001b3ac = 3;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec881 @ fffec881 (32 bytes)

void FUN_fffec881(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  swtimer_start(0x27,0xa0);
  DAT_0001b3ac = 4;
  return;
}


// ===== FUN_fffec8a1 @ fffec8a1 (112 bytes)

void FUN_fffec8a1(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = swtimer_expired(0x27);
  uVar2 = 0;
  if (bVar1 == 0) {
    return;
  }
  DAT_00025d04 = (float)FUN_fffb6e5c();
  if (DAT_00025d04 <= 4.3) {
    if (1.1 < DAT_00025d04 != (bool)((byte)(uVar2 >> 3) & 1)) {
      send_a_set(0);
      send_b_set(0);
      swtimer_start(0x27,5);
      DAT_0001b3ac = 5;
      return;
    }
    atu_mem_store();
    DAT_0001b3ac = 0xe;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec911 @ fffec911 (163 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec925) */
/* WARNING: Removing unreachable block (ram,0xfffec940) */
/* WARNING: Removing unreachable block (ram,0xfffec95b) */

void FUN_fffec911(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 != 0) {
    DAT_0001b3b2 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 10];
    DAT_0001b3ae = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xb];
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xc];
    g_ui.atu_state = 2;
    DAT_0001b3b0 = DAT_0001b3ae;
    DAT_0001b3b3 = DAT_0001b3ae;
    swtimer_start(0x27,5);
    DAT_00025cfc = 0x437f0000;
    DAT_0001b3ac = 6;
    return;
  }
  return;
}


// ===== FUN_fffec9b4 @ fffec9b4 (57 bytes)

void FUN_fffec9b4(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  FUN_fffed12f();
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x06') {
    DAT_0001b3ac = 0x14;
  }
  else {
    DAT_0001b3ac = 0x15;
  }
  return;
}


// ===== FUN_fffec9ed @ fffec9ed (91 bytes)

void FUN_fffec9ed(void)

{
  byte bVar1;
  
  if (g_ui.atu_state == 3) {
    DAT_0001b3ac = 0xf;
    return;
  }
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  send_a_set(1);
  send_b_set(1);
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x14') {
    DAT_0001b3ac = 7;
  }
  else {
    DAT_0001b3ac = 0xb;
  }
  return;
}


// ===== FUN_fffeca48 @ fffeca48 (54 bytes)

void FUN_fffeca48(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\a') {
    DAT_0001b3ac = 8;
  }
  else {
    DAT_0001b3ac = 0xc;
  }
  return;
}


// ===== FUN_fffeca7e @ fffeca7e (292 bytes)

void FUN_fffeca7e(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00025cfc = fVar3;
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    if ((g_opstate.ex030104_tuner_type_select == 1) && (fVar3 <= 1.5)) {
      DAT_0001b3ac = 9;
      return;
    }
  }
  if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b3;
    if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 9;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 6;
  return;
}


// ===== FUN_fffecba2 @ fffecba2 (325 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecbcc) */

void FUN_fffecba2(void)

{
  byte local_1;
  
  if (4.0 < DAT_00025cfc == SBORROW4((int)&stack0x00000000,8)) {
    DAT_00025cfc = 255.0;
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xd];
    if (DAT_0001b3bb < 2) {
      local_1 = 9;
    }
    else {
      local_1 = 3;
    }
    if ((uint)DAT_0001b3b9 + (uint)local_1 < 0x100) {
      DAT_0001b3b5 = DAT_0001b3b9 + local_1;
    }
    else {
      DAT_0001b3b5 = -1;
    }
    if ((uint)DAT_0001b3ba + (uint)local_1 < 0x100) {
      DAT_0001b3b7 = DAT_0001b3ba + local_1;
    }
    else {
      DAT_0001b3b7 = -1;
    }
    if (DAT_0001b3b9 < local_1) {
      DAT_0001b3ae = '\0';
    }
    else {
      DAT_0001b3ae = DAT_0001b3b9 - local_1;
    }
    if (DAT_0001b3ba < local_1) {
      DAT_0001b3b0 = '\0';
    }
    else {
      DAT_0001b3b0 = DAT_0001b3ba - local_1;
    }
    DAT_0001b3b6 = DAT_0001b3ae;
    DAT_0001b3b8 = DAT_0001b3b0;
    send_a_set(0);
    send_b_set(0);
    swtimer_start(0x27,4);
    DAT_0001b3ac = 10;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffecce7 @ fffecce7 (255 bytes)

void FUN_fffecce7(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    DAT_00025cfc = fVar3;
  }
  if ((ushort)DAT_0001b3b7 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b8;
    if ((ushort)DAT_0001b3b5 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 0xd;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 10;
  return;
}


// ===== FUN_fffecde6 @ fffecde6 (83 bytes)

void FUN_fffecde6(void)

{
  if (DAT_00025cfc < DAT_00025d04) {
    DAT_0001b3ae = DAT_0001b3b9;
    DAT_0001b3b0 = DAT_0001b3ba;
  }
  else {
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
  }
  FUN_fffed12f();
  atu_mem_store();
  DAT_0001b3ac = 0xe;
  return;
}


// ===== FUN_fffece39 @ fffece39 (48 bytes)

void FUN_fffece39(void)

{
  FUN_fffec4db();
  g_ui.tune_cycle_3d = 0;
  g_ui.ptt_atu_tune = 0;
  g_ui.atu_state = 2;
  vfo_tuner_bit_set(1);
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffece69 @ fffece69 (16 bytes)

void FUN_fffece69(void)

{
  beep_request(3);
  DAT_0001b3ac = 0x10;
  return;
}


// ===== FUN_fffece79 @ fffece79 (44 bytes)

void FUN_fffece79(void)

{
  g_ui.ptt_atu_tune = 0;
  DAT_0001b3ae = 0;
  DAT_0001b3b0 = 0;
  FUN_fffed12f();
  FUN_fffec4db();
  DAT_0001b3ac = 0;
  return;
}


// ===== atu_mem_store @ fffecea5 (263 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecf52) */
/* WARNING: Removing unreachable block (ram,0xfffecf1b) */
/* WARNING: Removing unreachable block (ram,0xfffecef3) */
/* WARNING: Removing unreachable block (ram,0xfffeceea) */
/* WARNING: Removing unreachable block (ram,0xfffecf0a) */
/* WARNING: Removing unreachable block (ram,0xfffecf47) */
/* WARNING: Removing unreachable block (ram,0xfffecf66) */
/* WARNING: Removing unreachable block (ram,0xfffecf79) */
/* Stores (freq key, 0x1B3AF, 0x1B3AD) in the 100-entry tuner memory 0x9898 ring and saves it */

void atu_mem_store(void)

{
  uint uVar1;
  byte bStack_16;
  byte bStack_15;
  undefined1 uStack_4;
  
  uVar1 = FUN_fffb4135(DAT_00025d00);
  bStack_15 = 0xff;
  bStack_16 = 0;
  do {
    if (DAT_00009899 <= bStack_16) {
LAB_fffecf38:
      if (bStack_15 == 0xff) {
        (&DAT_0000989a)[(uint)DAT_00009898 * 4] = (char)(uVar1 >> 0x18);
        uStack_4 = (undefined1)(uVar1 >> 0x10);
        (&DAT_0000989b)[(uint)DAT_00009898 * 4] = uStack_4;
        (&DAT_0000989c)[(uint)DAT_00009898 * 4] = DAT_0001b3af;
        (&DAT_0000989d)[(uint)DAT_00009898 * 4] = DAT_0001b3ad;
        if (DAT_00009899 < 100) {
          DAT_00009899 = DAT_00009899 + 1;
        }
        if (DAT_00009898 < 99) {
          DAT_00009898 = DAT_00009898 + 1;
        }
        else {
          DAT_00009898 = 0;
        }
      }
      eeprom_save_atu_mem();
      return;
    }
    if (uVar1 >> 0x10 ==
        (uint)CONCAT11((&DAT_0000989a)[(uint)bStack_16 * 4],(&DAT_0000989b)[(uint)bStack_16 * 4])) {
      (&DAT_0000989c)[(uint)bStack_16 * 4] = DAT_0001b3af;
      (&DAT_0000989d)[(uint)bStack_16 * 4] = DAT_0001b3ad;
      bStack_15 = bStack_16;
      goto LAB_fffecf38;
    }
    bStack_16 = bStack_16 + 1;
  } while( true );
}


// ===== FUN_fffecfac @ fffecfac (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecff5) */
/* WARNING: Removing unreachable block (ram,0xfffed085) */
/* WARNING: Removing unreachable block (ram,0xfffed096) */
/* WARNING: Removing unreachable block (ram,0xfffecffe) */

byte FUN_fffecfac(char *param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte local_25;
  byte local_1d;
  char *pcStack_1c;
  char *pcStack_18;
  char *local_10;
  
  bVar2 = DAT_00009899;
  local_25 = 0xff;
  if (param_1 < (char *)0x7a120) {
    local_10 = (char *)0x0;
  }
  else {
    local_10 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
               + (int)(param_1 + 0x29cc);
  }
  for (local_1d = 0; local_1d < bVar2; local_1d = local_1d + 1) {
    iVar3 = FUN_fffb2fec(CONCAT11((&DAT_0000989a)[(uint)local_1d * 4],
                                  (&DAT_0000989b)[(uint)local_1d * 4]));
    pcStack_1c = (char *)(iVar3 * 10000);
    if ((pcStack_1c < local_10) || (param_1 + 500000 < pcStack_1c)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      if (pcStack_1c < param_1) {
        pcStack_1c = param_1 + iVar3 * -10000;
      }
      else {
        pcStack_1c = pcStack_1c + -(int)param_1;
      }
      if (local_25 == 0xff) {
        local_25 = local_1d;
        pcStack_18 = pcStack_1c;
      }
      else if (pcStack_1c < pcStack_18) {
        local_25 = local_1d;
        pcStack_18 = pcStack_1c;
      }
    }
  }
  if (local_25 != 0xff) {
    DAT_0001b3b0 = (&DAT_0000989c)[(uint)local_25 * 4];
    DAT_0001b3ae = (&DAT_0000989d)[(uint)local_25 * 4];
  }
  return local_25;
}


// ===== FUN_fffed0ae @ fffed0ae (129 bytes)

/* WARNING: Removing unreachable block (ram,0xfffed0cd) */
/* WARNING: Removing unreachable block (ram,0xfffed0c0) */
/* WARNING: Removing unreachable block (ram,0xfffed0f2) */
/* WARNING: Removing unreachable block (ram,0xfffed107) */

byte FUN_fffed0ae(uint param_1)

{
  int iVar1;
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xa9 < local_d) {
      return 0xff;
    }
    iVar1 = FUN_fffb2fec(CONCAT11(BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x36],
                                  BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x37]));
    if (param_1 < (uint)(iVar1 * 10000)) break;
    local_d = local_d + 1;
  }
  DAT_0001b3ae = BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x39];
  DAT_0001b3b0 = BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x38];
  return local_d;
}


// ===== FUN_fffed12f @ fffed12f (54 bytes)

void FUN_fffed12f(void)

{
  DAT_0001b3ad = DAT_0001b3ae;
  DAT_0001b3af = DAT_0001b3b0;
  DAT_0001b3b1 = "EX010101EX010102EX010103EX010104EX010105EX010106EX010107EX010108EX010109EX010110EX010111EX010112EX010113EX010114EX010115EX010116EX010117EX010118EX010119EX010201EX010202EX010203EX010204EX010205EX010206EX010207EX010208EX010209EX010210EX010211EX010212EX010213EX010214EX010215EX010216EX010217EX010301EX010302EX010303EX010304EX010305EX010306EX010307EX010308EX010309EX010310EX010311EX010312EX010313EX010314EX010315EX010316EX010317EX010318EX010319EX010320EX010321EX010401EX010402EX010403EX010404EX010405EX010406EX010407EX010408EX010409EX010410EX010411EX010412EX010413EX010414EX010415EX010416EX010417EX010418EX010419EX010420EX010501EX010502EX010503EX010504EX010505EX010506EX010507EX010508EX010509EX010510EX010511EX010512EX010513EX010514EX010515EX010516EX010517EX020101EX020102EX020103EX020104EX020105EX020106EX020107EX020108EX020109EX020110EX020111EX020112EX020113EX020114EX020115EX020116EX020117EX020118EX020119EX020120EX020201EX020202EX020203EX020204EX020205EX020206EX020207EX020208EX020209EX020210EX020211EX030101EX030102EX030103EX030104EX030105EX030106EX030107EX030108EX030109EX030110EX030111EX030112EX030113EX030114EX030115EX030116EX030117EX030118EX030119EX030120EX030121EX030122EX030123EX030124EX030125EX030126EX030201EX030202EX030203EX030204EX030205EX030206EX030301EX030302EX030303EX030304EX030305EX030306EX030307EX030308EX030309EX030310EX030311EX030312EX030313EX030314EX030315EX030316EX030317EX030318EX030319EX030401EX030402EX030403EX030404EX030405EX030406EX030407EX030408EX030501EX030502EX030503EX030504EX030505EX030506EX040101EX040102EX040103EX040104EX040105EX040106EX040201EX040202EX040203EX040204EX040301EX040302EX040303EX040304EX040401EX040402EX060101EX060102EX060103EX060104EX060105EX060106EX060107EX060108EX060109EX060110EX060111EX060112EX060113EX060114EX060115EX060116EX060117EX060118EX060201EX060202EX060203EX060204EX060205EX060206EX060207EX060208EX060209EX060210EX060211EX060212EX060213EX060214EX060215EX060216EX060217EX060218EX060301EX060302EX060303EX060304EX060305EX060306EX060307EX060308EX060309EX060310EX060311EX060312EX060313EX060314..." /* TRUNCATED STRING LITERAL */
                 [DAT_0001b3bb + 0x940];
  return;
}


// ===== FUN_fffed165 @ fffed165 (161 bytes)

void FUN_fffed165(void)

{
  byte bVar1;
  
  if (DAT_0001b3c3 == '\x01') {
    bVar1 = swtimer_expired(0x22);
    if (bVar1 == 1) {
      DAT_0001b3c3 = 0;
      g_ui.tuner_result = 0;
      return;
    }
  }
  else {
    bVar1 = swtimer_expired(0x21);
    if (bVar1 != 0) {
      swtimer_start(0x21,5);
      g_ui.tuner_indicator = 2;
      if (g_ui.tune_cycle == 1) {
        FUN_fffed399();
      }
      else {
        if (g_ui.tune_cycle != 2) {
          g_ui.tuner_result = 0;
          return;
        }
        FUN_fffed2a9();
      }
      bVar1 = blink_phase(0);
      if (bVar1 == 0) {
        g_ui.tuner_indicator = 0;
        return;
      }
    }
  }
  return;
}


// ===== tuner_tune_state_set @ fffed206 (72 bytes)

/* (s): 0x20F0C = s; 1 starts (0x1B3BE = 1), 2 swaps the meter (0x9C5B = 5) and CW WAVE SHAPE
   (0x9AA1 = 0) and opens pop-up 0x49, 0 restores both [fact]; a tune cycle [inference] */

void tuner_tune_state_set(byte param_1)

{
  g_ui.tune_cycle = param_1;
  if (param_1 == 1) {
    FUN_fffed371();
  }
  else if (param_1 != 2) {
    DAT_0001b3be = 0;
    g_ui.ptt_atu_tune = 0;
    DAT_00025d08 = DAT_00025d0c;
    FUN_fffec4db();
    return;
  }
  FUN_fffec493();
  return;
}


// ===== FUN_fffed24e @ fffed24e (91 bytes)

void FUN_fffed24e(char param_1)

{
  DAT_0001b3c3 = 1;
  swtimer_start(0x22,0x32);
  if (param_1 == '\x01') {
    g_ui.tuner_result = 2;
  }
  else if (param_1 == '\x02') {
    g_ui.tuner_result = 3;
  }
  else {
    g_ui.tuner_result = 1;
  }
  if (g_ui.tune_cycle != 1) {
    return;
  }
  tuner_tune_state_set(0);
  return;
}


// ===== FUN_fffed2a9 @ fffed2a9 (200 bytes)

void FUN_fffed2a9(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  if (g_ui.tx_lamp == 0) {
    tuner_tune_state_set(0);
    return;
  }
  if ((g_ui.tuner_result == 0) || (iVar3 = FUN_fffed61e(), iVar3 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    beep_request(3);
    tuner_tune_state_set(0);
    return;
  }
  if (g_ui.f_0x03a_u8 == 1) {
    g_ui.tuner_result = 2;
    send_a_set(1);
    send_b_set(1);
    return;
  }
  if (g_ui.f_0x03a_u8 != 2) {
    if (g_ui.f_0x03a_u8 != 3) {
      g_ui.tuner_result = 0;
      return;
    }
    g_ui.tuner_result = 1;
    bVar2 = swtimer_expired(0x20);
    if (bVar2 != 0) {
      g_ui.f_0x03a_u8 = 0;
      return;
    }
    return;
  }
  g_ui.tuner_result = 3;
  send_a_set(1);
  send_b_set(1);
  return;
}


// ===== FUN_fffed371 @ fffed371 (40 bytes)

void FUN_fffed371(void)

{
  DAT_0001b3be = 1;
  DAT_0001b3c1 = 0;
  DAT_00025d10 = 0x437f0000;
  DAT_0001b3c2 = 0;
  return;
}


// ===== FUN_fffed399 @ fffed399 (104 bytes)

void FUN_fffed399(void)

{
  bool bVar1;
  int iVar2;
  
  if ((g_ui.tuner_result == 0) || (iVar2 = FUN_fffed61e(), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    beep_request(3);
    DAT_0001b3be = '\x05';
  }
  if (DAT_0001b3be == '\x05') {
    FUN_fffed5e4();
    return;
  }
  if (DAT_0001b3be == '\x02') {
    FUN_fffed48f();
    return;
  }
  if (DAT_0001b3be != '\x03') {
    if (DAT_0001b3be == '\x04') {
      FUN_fffed5c5();
      return;
    }
    if (DAT_0001b3be == '\x01') {
      FUN_fffed401();
      return;
    }
    return;
  }
  FUN_fffed50f();
  return;
}


// ===== FUN_fffed401 @ fffed401 (142 bytes)

void FUN_fffed401(void)

{
  int iVar1;
  
  DAT_00025d0c = g_ui.freq_tx;
  if (DAT_0001b3bf == '\0') {
    if (DAT_0001b3c0 == '\0') {
      g_ui.tuner_result = 3;
    }
    else {
      g_ui.tuner_result = 2;
    }
    swtimer_start(0x20,60000);
  }
  else {
    iVar1 = tx_band_of_freq(g_ui.freq_tx);
    if (iVar1 == 9) {
      DAT_0001b3c0 = '\x01';
      g_ui.tuner_result = 2;
      swtimer_start(0x20,5000);
    }
    else {
      swtimer_start(0x20,1);
    }
  }
  DAT_0001b3be = 2;
  return;
}


// ===== FUN_fffed48f @ fffed48f (128 bytes)

void FUN_fffed48f(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  if (DAT_0001b3bf == '\0') {
    FUN_fffed5ea();
  }
  else if (DAT_00025d08 < DAT_00025d0c) {
    DAT_0001b3c0 = 1;
    g_ui.tuner_result = 2;
  }
  else {
    DAT_0001b3c0 = 0;
    g_ui.tuner_result = 3;
  }
  DAT_0001b3bf = 0;
  g_ui.ptt_atu_tune = 1;
  swtimer_start(0x20,60000);
  DAT_0001b3be = 3;
  return;
}


// ===== FUN_fffed50f @ fffed50f (182 bytes)

void FUN_fffed50f(void)

{
  byte bVar1;
  float fVar2;
  uint uVar3;
  
  uVar3 = (uint)SBORROW4((int)&stack0x00000000,4) << 3;
  fVar2 = (float)FUN_fffb6e4e();
  if (2.0 < fVar2 == (bool)((byte)(uVar3 >> 3) & 1)) {
    if (DAT_00025d10 < fVar2) {
      DAT_0001b3c2 = DAT_0001b3c2 + 1;
    }
    else {
      DAT_0001b3c2 = 0;
    }
  }
  else {
    DAT_0001b3c2 = 0;
  }
  DAT_00025d10 = fVar2;
  if (2 < DAT_0001b3c2) {
    g_ui.tuner_result = 1;
    swtimer_start(0x20,2000);
    DAT_0001b3be = 4;
    return;
  }
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  if (DAT_0001b3c1 == '\0') {
    DAT_0001b3c1 = 1;
    FUN_fffed5ea();
    swtimer_start(0x20,60000);
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5c5 @ fffed5c5 (31 bytes)

void FUN_fffed5c5(void)

{
  byte bVar1;
  
  DAT_0001b3bf = 1;
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5e4 @ fffed5e4 (6 bytes)

void FUN_fffed5e4(void)

{
  tuner_tune_state_set(0);
  return;
}


// ===== FUN_fffed5ea @ fffed5ea (52 bytes)

void FUN_fffed5ea(void)

{
  if (DAT_0001b3c0 != '\0') {
    DAT_0001b3c0 = 0;
    g_ui.tuner_result = 3;
    return;
  }
  DAT_0001b3c0 = 1;
  g_ui.tuner_result = 2;
  return;
}


// ===== FUN_fffed61e @ fffed61e (12 bytes)

bool FUN_fffed61e(void)

{
  bool bVar1;
  
  bVar1 = atas_det();
  return bVar1;
}


// ===== FUN_fffed62a @ fffed62a (203 bytes)

void FUN_fffed62a(void)

{
  bool bVar1;
  tunlin_mode tVar2;
  byte bVar3;
  
  g_ui.tuner_indicator = 0;
  tVar2 = tunlin_port_mode();
  if (tVar2 == TUNLIN_EXT_TUNER) {
    if (g_ui.atu_state == 5) {
      g_ui.tuner_indicator = 1;
      if ((g_ui.tune_cycle_3c == 2) && (bVar3 = blink_phase(0), bVar3 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        g_ui.tuner_indicator = 0;
      }
    }
    switch(DAT_0001b3c8) {
    case 1:
    case 4:
      FUN_fffed72b();
      return;
    case 2:
    case 5:
      FUN_fffed753();
      return;
    case 3:
      FUN_fffed796();
      return;
    case 6:
      FUN_fffed7f3();
      return;
    case 7:
      FUN_fffed8ab();
      return;
    case 8:
      FUN_fffed8fc();
      return;
    case 9:
      FUN_fffed934();
      return;
    case 10:
      FUN_fffed983();
      return;
    case 0xb:
      FUN_fffed9b3();
      return;
    case 0xc:
      FUN_fffeda3b();
      return;
    case 0xd:
      FUN_fffeda96();
      return;
    case 0xe:
      FUN_fffedab0();
      return;
    case 0xf:
      FUN_fffedac0();
      return;
    case 0x10:
      FUN_fffedae4();
      return;
    default:
      FUN_fffed704();
      return;
    }
  }
  return;
}


// ===== FUN_fffed6f5 @ fffed6f5 (15 bytes)

undefined1 FUN_fffed6f5(void)

{
  return DAT_0001b5aa;
}

