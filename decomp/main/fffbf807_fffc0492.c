// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== key_nar_short @ fffbf807 (231 bytes)

/* Front-panel key 0x30D NAR, short handler (key tables, display/input.md key codes) (#70) */

void key_nar_short(void)

{
  bool bVar1;
  byte local_d;
  byte *local_c;
  bool local_5;
  byte *local_4;
  
  bVar1 = false;
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
    local_c = &DAT_00009d0d;
  }
  else {
    local_4 = &DAT_00009d63;
    local_c = &DAT_00009d67;
  }
  local_5 = DAT_00009dbd != '\0';
  switch(*local_4 & 0xf) {
  case 0:
  case 1:
    bVar1 = true;
    local_d = 0x80;
    break;
  case 2:
  case 3:
    bVar1 = true;
    local_d = 0x20;
    break;
  case 4:
    FUN_fffc0e3e();
    break;
  case 5:
    FUN_fffc0e31();
    break;
  case 6:
    FUN_fffc0e58();
    break;
  case 7:
    FUN_fffc0e4b();
    break;
  case 8:
  case 9:
  case 0xe:
    bVar1 = true;
    local_d = 4;
    break;
  case 10:
    FUN_fffc0e72();
    break;
  case 0xb:
    FUN_fffc0e65();
    break;
  case 0xc:
  case 0xd:
    bVar1 = true;
    local_d = 8;
  }
  if (bVar1) {
    if ((local_d & *local_c) == 0) {
      *local_c = local_d | *local_c;
    }
    else {
      *local_c = ~local_d & *local_c;
    }
    vfo_mark_edited(local_5);
    vfo_store_back(local_5);
    PTR_DAT_00025d54[0x40c] = 1;
  }
  beep_request(1);
  return;
}


// ===== key_qmb_press @ fffbf8ee (54 bytes)

/* Front-panel key 0x30E QMB, press handler (key tables, display/input.md key codes) (#70) */

void key_qmb_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== qmb_recall @ fffbf924 (416 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf95a) */
/* QR: leave split, enter state 5, load slot */

void qmb_recall(void)

{
  int iVar1;
  byte local_3;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00020b98 != '\0') {
    FUN_fffe3d24();
    DAT_00020b98 = '\0';
  }
  if ((CONCAT11(DAT_00009012,DAT_00009013) & 0x3ff) != 0) {
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = '\0';
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
    }
    if (DAT_00009dbd == '\0') {
      local_3 = 0;
      if (DAT_00009dbe != '\x05') {
        FUN_fffc34d8(0);
      }
    }
    else {
      local_3 = 1;
      if (DAT_00009dbf != '\x05') {
        FUN_fffc34d8(1);
      }
    }
    iVar1 = FUN_fffc302b(local_3);
    if (iVar1 == 0) {
      if (local_3 == 0) {
        PTR_DAT_00025d54[0x443] = 0;
        PTR_DAT_00025d54[0x444] = 0;
      }
      else {
        PTR_DAT_00025d54[0x445] = 0;
        PTR_DAT_00025d54[0x446] = 0;
      }
    }
    vfo_enter_vfo_state(local_3);
    iVar1 = FUN_fffc30af(local_3);
    if (iVar1 == 1) {
      qmb_set_depth(local_3);
      vfo_store_back(local_3);
    }
    if (local_3 == 0) {
      if (DAT_0000901f != '\0') {
        qmb_enter(0);
        return;
      }
      DAT_00009dbe = '\x01';
    }
    else {
      if (DAT_00009021 != '\0') {
        qmb_enter(1);
        return;
      }
      DAT_00009dbf = '\x01';
    }
    qmb_set_depth(local_3);
    vfo_reload(local_3);
    PTR_DAT_00025d54[0x40b] = 1;
    FUN_fffec578();
    FUN_fffc8beb();
    return;
  }
  beep_request(3);
  return;
}


// ===== qmb_store @ fffbfac4 (371 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbfb0d) */
/* QI: operating record -> QMB slot (0x9023+n*0x5A), mask 0x9012 */

void qmb_store(void)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 *local_10;
  bool local_5;
  ushort local_4;
  byte local_2;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  bVar1 = DAT_00009dbd != '\0';
  bVar3 = vfo_is_memory(bVar1);
  if ((bVar3 == 1) && (bVar3 = memch_current_is_special(bVar1), bVar3 == 1)) {
    beep_request(3);
    return;
  }
  local_4 = CONCAT11(DAT_00009012,DAT_00009013) & 0x3ff;
  if (local_4 == 0x3ff) {
    local_2 = DAT_0000901e;
  }
  else {
    local_5 = false;
    for (; (local_5 < 10 && ((local_4 & 1) != 0)); local_4 = local_4 >> 1) {
      local_5 = (bool)(local_5 + 1);
    }
    local_2 = local_5;
  }
  for (local_5 = false; local_5 < 9; local_5 = (bool)(local_5 + 1)) {
    (&DAT_0000901e)[-(uint)local_5] = *(undefined1 *)(0x901d - (uint)local_5);
  }
  DAT_00009015 = local_2;
  puVar4 = &DAT_00009023 + (uint)local_2 * 0x5a;
  if (bVar1) {
    local_10 = &DAT_00009d63;
  }
  else {
    local_10 = &DAT_00009d09;
  }
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *local_10;
    puVar4 = puVar4 + 1;
    local_10 = local_10 + 1;
  }
  bVar2 = 7 < local_2;
  if (bVar2) {
    local_2 = local_2 - 8;
  }
  local_5 = !bVar2;
  (&DAT_00009012)[local_5] = (byte)(1 << (local_2 & 0x1f)) | (&DAT_00009012)[local_5];
  FUN_fffc3408(bVar1);
  if (DAT_00009014 < 10) {
    DAT_00009014 = DAT_00009014 + 1;
  }
  FUN_fffc34d8(bVar1);
  beep_request(5);
  FUN_fffc33ef();
  PTR_DAT_00025d54[0x47f] = DAT_00009015 + 1;
  return;
}


// ===== key_func_press @ fffbfc37 (224 bytes)

/* Front-panel key 0x30F FUNC, press handler (key tables, display/input.md key codes) (#70) */

void key_func_press(void)

{
  int iVar1;
  
  if (PTR_DAT_00025d54[0xba] == '\x01') {
    beep_request(1);
    return;
  }
  if (PTR_DAT_00025d54[0x86] == '\x01') {
    FUN_fffd00ac();
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x95] == '\x01') {
    if (PTR_DAT_00025d54[0x88] == '\x01') {
      iVar1 = FUN_fffd1ba6();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    else {
      iVar1 = FUN_fffd1abd();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if ((PTR_DAT_00025d54[0x93] != '\x01') && (PTR_DAT_00025d54[0x94] != '\x01')) {
    if (PTR_DAT_00025d54[0x97] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d54[0x418] == '\x01') {
      scan_stop();
      PTR_DAT_00025d54[0x409] = 1;
      return;
    }
    if (PTR_DAT_00025d54[0x96] == '\0') {
      beep_request(1);
      return;
    }
  }
  return;
}


// ===== key_func_short @ fffbfd17 (10 bytes)

/* Front-panel key 0x30F FUNC, short handler (key tables, display/input.md key codes) (#70) */

void key_func_short(void)

{
  DAT_0001b4dd = 1;
  return;
}


// ===== key_func_long @ fffbfd21 (93 bytes)

/* Front-panel key 0x30F FUNC, long handler (key tables, display/input.md key codes) (#70) */

void key_func_long(void)

{
  bool bVar1;
  
  DAT_0001b4de = 1;
  if ((DAT_00009c5e == '\x01') && (PTR_DAT_00025d54[0x483] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_DAT_00025d54[0xba] == '\x01') {
      beep_request(2);
      eeprom_save_cfg105();
      return;
    }
    return;
  }
  beep_request(2);
  FUN_fffc3fef();
  return;
}


// ===== key_func_release @ fffbfd7e (150 bytes)

/* Front-panel key 0x30F FUNC, release handler (key tables, display/input.md key codes) (#70) */

void key_func_release(void)

{
  bool bVar1;
  
  if ((DAT_0001b4dd == '\x01') && (DAT_0001b4de == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((DAT_0001b4dd == '\x01') && (DAT_0001b4de == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00020b9b == '\x01') {
        FUN_fffc2794();
      }
      if (DAT_00009c5e == '\x01') {
        FUN_fffc1e6f();
      }
      DAT_0001b4dd = 0;
      DAT_0001b4de = 0;
      return;
    }
    return;
  }
  FUN_fffc3a10();
  DAT_0001b4dd = 0;
  DAT_0001b4de = 0;
  return;
}


// ===== key_step_mch_press @ fffbfe14 (74 bytes)

/* Front-panel key 0x310 STEP/MCH, press handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (DAT_00020b9b != '\x01') {
    return;
  }
  FUN_fffc2794();
  beep_request(1);
  return;
}


// ===== key_step_mch_short @ fffbfe5e (48 bytes)

/* Front-panel key 0x310 STEP/MCH, short handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_short(void)

{
  if (PTR_DAT_00025d54[0x70] != '\x01') {
    return;
  }
  PTR_DAT_00025d54[0x70] = 0;
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_step_mch_long @ fffbfe8e (91 bytes)

/* Front-panel key 0x310 STEP/MCH, long handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_long(void)

{
  bool bVar1;
  
  bVar1 = DAT_00009dbd != '\0';
  FUN_fffc3503(bVar1);
  FUN_fffc3582(bVar1);
  FUN_fffc3659(bVar1);
  FUN_fffc3773(bVar1);
  FUN_fffc388d(bVar1);
  vfo_mark_edited(bVar1);
  vfo_store_back(bVar1);
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_fine_fast_press @ fffbfee9 (57 bytes)

/* Front-panel key 0x311 FINE/FAST, press handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_fine_fast_short @ fffbff22 (53 bytes)

/* Front-panel key 0x311 FINE/FAST, short handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_short(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009c61 == '\0') {
    DAT_00009c61 = 1;
    return;
  }
  DAT_00009c61 = 0;
  return;
}


// ===== key_fine_fast_long @ fffbff57 (60 bytes)

/* Front-panel key 0x311 FINE/FAST, long handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_long(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009c61 == '\x02') {
    DAT_00009c61 = 0;
  }
  else {
    DAT_00009c61 = 2;
  }
  beep_request(2);
  return;
}


// ===== key_dsp_press @ fffbff93 (112 bytes)

/* Front-panel key 0x312 DSP, press handler (key tables, display/input.md key codes) (#70) */

void key_dsp_press(void)

{
  int iVar1;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0xba] == '\x01') {
    iVar1 = align_store();
    if (iVar1 == 1) {
      beep_request(1);
    }
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x70] == '\x01') {
    FUN_fffc89b0();
    return;
  }
  return;
}


// ===== key_dsp_short @ fffc0003 (68 bytes)

/* Front-panel key 0x312 DSP, short handler (key tables, display/input.md key codes) (#70) */

void key_dsp_short(void)

{
  if (PTR_DAT_00025d54[0x97] == '\x01') {
    if (PTR_DAT_00025d54[0x1d9] != '\0') {
      FUN_fffc38fa();
      PTR_DAT_00025d54[0x409] = 1;
    }
  }
  else if (PTR_DAT_00025d54[0x70] == '\x01') {
    PTR_DAT_00025d54[0x75] = 1;
  }
  else {
    PTR_DAT_00025d54[0x3e] = 1;
  }
  FUN_fffc5290();
  return;
}


// ===== key_dsp_long @ fffc0047 (72 bytes)

/* Front-panel key 0x312 DSP, long handler (key tables, display/input.md key codes) (#70) */

void key_dsp_long(void)

{
  if (PTR_DAT_00025d54[0x97] == '\x01') {
    if (PTR_DAT_00025d54[0x1d9] != '\0') {
      return;
    }
    FUN_fffc38fa();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x70] != '\x01') {
    PTR_DAT_00025d54[0x3e] = 2;
    return;
  }
  PTR_DAT_00025d54[0x76] = 1;
  beep_request(2);
  return;
}


// ===== key_dsp_release @ fffc008f (385 bytes)

/* Front-panel key 0x312 DSP, release handler (key tables, display/input.md key codes) (#70) */

void key_dsp_release(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  
  if (DAT_00020bbe != '\x01') {
    if (PTR_DAT_00025d54[0x70] == '\x01') {
      if (PTR_DAT_00025d54[0x75] == '\x01') {
        if (PTR_DAT_00025d54[0x76] == '\x01') {
          FUN_fffc4dec();
          PTR_DAT_00025d54[0x76] = 0;
          PTR_DAT_00025d54[0x75] = 0;
        }
        else {
          beep_request(1);
          if (PTR_DAT_00025d54[0x74] == '\0') {
            PTR_DAT_00025d54[0x72] = 1;
            swtimer_start(0x45,0x1c2);
            cVar1 = PTR_DAT_00025d54[0x73];
            if (cVar1 == '\x03') {
              if (PTR_DAT_00025d54[0x47a] == '\0') {
                FUN_fffbdcb0();
              }
              else {
                FUN_fffbde58();
              }
            }
            else if (cVar1 == '\x01') {
              FUN_fffbdad5();
            }
            else if (cVar1 == '\x02') {
              FUN_fffbdb63();
            }
            else if (cVar1 == '\0') {
              FUN_fffbda47();
            }
          }
          else {
            PTR_DAT_00025d54[0x74] = 0;
            PTR_DAT_00025d54[0x72] = 0;
            PTR_DAT_00025d54[0x71] = 1;
          }
          PTR_DAT_00025d54[0x75] = 0;
        }
      }
    }
    else if (PTR_DAT_00025d54[0x97] == '\x01') {
      if ((PTR_DAT_00025d54[0x1d9] == '\0') && (PTR_DAT_00025d54[0x409] == '\0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        FUN_fffc4064();
      }
    }
    else if (PTR_DAT_00025d54[0x3e] != '\x02') {
      bVar3 = vfo_mode(0);
      uVar4 = (uint)bVar3;
      if ((uVar4 - 6 < 2) || (uVar4 == 10 || uVar4 == 0xb)) {
        beep_request(3);
        PTR_DAT_00025d54[0x409] = 1;
      }
      else {
        beep_request(1);
        FUN_fffc89b0();
        PTR_DAT_00025d54[0x7a] = 0x1d;
      }
    }
    PTR_DAT_00025d54[0x3e] = 0;
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  return;
}


// ===== FUN_fffc0210 @ fffc0210 (289 bytes)

void FUN_fffc0210(void)

{
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x46b] == '\x01') {
    beep_request(6);
    PTR_DAT_00025d54[0x46b] = 0;
    PTR_DAT_00025d54[0x46c] = 0;
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x1ca] == '\x01') {
    PTR_DAT_00025d54[0x417] = 0;
    PTR_DAT_00025d54[0x1ca] = 0;
    PTR_DAT_00025d54[0x78] = 2;
    PTR_DAT_00025d54[0x1cb] = 0;
    PTR_DAT_00025d54[0x1cf] = 1;
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x417] == '\x01') {
    PTR_DAT_00025d54[0x417] = 0;
    PTR_DAT_00025d54[0x1cb] = 0;
    PTR_DAT_00025d54[0x1c8] = 0;
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x78] == '\x01') {
    PTR_DAT_00025d54[0x1cf] = 0;
    PTR_DAT_00025d54[0x1d0] = 1;
  }
  PTR_DAT_00025d54[0x27] = 1;
  return;
}


// ===== FUN_fffc0331 @ fffc0331 (1 bytes)

void FUN_fffc0331(void)

{
  return;
}


// ===== FUN_fffc0332 @ fffc0332 (1 bytes)

void FUN_fffc0332(void)

{
  return;
}


// ===== FUN_fffc0333 @ fffc0333 (1 bytes)

void FUN_fffc0333(void)

{
  return;
}


// ===== FUN_fffc0334 @ fffc0334 (1 bytes)

void FUN_fffc0334(void)

{
  return;
}


// ===== FUN_fffc0335 @ fffc0335 (14 bytes)

void FUN_fffc0335(void)

{
  FUN_fffc40d7(DAT_00009acc);
  return;
}


// ===== FUN_fffc0343 @ fffc0343 (14 bytes)

void FUN_fffc0343(void)

{
  FUN_fffc410a(DAT_00009acc);
  return;
}


// ===== FUN_fffc0351 @ fffc0351 (14 bytes)

void FUN_fffc0351(void)

{
  FUN_fffc413d(DAT_00009acc);
  return;
}


// ===== FUN_fffc035f @ fffc035f (14 bytes)

void FUN_fffc035f(void)

{
  FUN_fffc4170(DAT_00009acc);
  return;
}


// ===== FUN_fffc036d @ fffc036d (14 bytes)

void FUN_fffc036d(void)

{
  FUN_fffc41a3(DAT_00009acc);
  return;
}


// ===== FUN_fffc037b @ fffc037b (14 bytes)

void FUN_fffc037b(void)

{
  FUN_fffc40d7(DAT_00009acd);
  return;
}


// ===== FUN_fffc0389 @ fffc0389 (14 bytes)

void FUN_fffc0389(void)

{
  FUN_fffc410a(DAT_00009acd);
  return;
}


// ===== FUN_fffc0397 @ fffc0397 (14 bytes)

void FUN_fffc0397(void)

{
  FUN_fffc413d(DAT_00009acd);
  return;
}


// ===== FUN_fffc03a5 @ fffc03a5 (14 bytes)

void FUN_fffc03a5(void)

{
  FUN_fffc4170(DAT_00009acd);
  return;
}


// ===== FUN_fffc03b3 @ fffc03b3 (14 bytes)

void FUN_fffc03b3(void)

{
  FUN_fffc41a3(DAT_00009acd);
  return;
}


// ===== FUN_fffc03c1 @ fffc03c1 (13 bytes)

void FUN_fffc03c1(void)

{
  PTR_DAT_00025d54[0x37] = 1;
  return;
}


// ===== FUN_fffc03ce @ fffc03ce (1 bytes)

void FUN_fffc03ce(void)

{
  return;
}


// ===== FUN_fffc03cf @ fffc03cf (13 bytes)

void FUN_fffc03cf(void)

{
  PTR_DAT_00025d54[0x37] = 0;
  return;
}


// ===== FUN_fffc03dc @ fffc03dc (14 bytes)

void FUN_fffc03dc(void)

{
  FUN_fffc40d7(DAT_00009ac8);
  return;
}


// ===== FUN_fffc03ea @ fffc03ea (14 bytes)

void FUN_fffc03ea(void)

{
  FUN_fffc410a(DAT_00009ac8);
  return;
}


// ===== FUN_fffc03f8 @ fffc03f8 (14 bytes)

void FUN_fffc03f8(void)

{
  FUN_fffc413d(DAT_00009ac8);
  return;
}


// ===== FUN_fffc0406 @ fffc0406 (14 bytes)

void FUN_fffc0406(void)

{
  FUN_fffc4170(DAT_00009ac8);
  return;
}


// ===== FUN_fffc0414 @ fffc0414 (14 bytes)

void FUN_fffc0414(void)

{
  FUN_fffc41a3(DAT_00009ac8);
  return;
}


// ===== FUN_fffc0422 @ fffc0422 (14 bytes)

void FUN_fffc0422(void)

{
  FUN_fffc40d7(DAT_00009ac9);
  return;
}


// ===== FUN_fffc0430 @ fffc0430 (14 bytes)

void FUN_fffc0430(void)

{
  FUN_fffc410a(DAT_00009ac9);
  return;
}


// ===== FUN_fffc043e @ fffc043e (14 bytes)

void FUN_fffc043e(void)

{
  FUN_fffc413d(DAT_00009ac9);
  return;
}


// ===== FUN_fffc044c @ fffc044c (14 bytes)

void FUN_fffc044c(void)

{
  FUN_fffc4170(DAT_00009ac9);
  return;
}


// ===== FUN_fffc045a @ fffc045a (14 bytes)

void FUN_fffc045a(void)

{
  FUN_fffc41a3(DAT_00009ac9);
  return;
}


// ===== FUN_fffc0468 @ fffc0468 (14 bytes)

void FUN_fffc0468(void)

{
  FUN_fffc40d7(DAT_00009aca);
  return;
}


// ===== FUN_fffc0476 @ fffc0476 (14 bytes)

void FUN_fffc0476(void)

{
  FUN_fffc410a(DAT_00009aca);
  return;
}


// ===== FUN_fffc0484 @ fffc0484 (14 bytes)

void FUN_fffc0484(void)

{
  FUN_fffc413d(DAT_00009aca);
  return;
}


// ===== FUN_fffc0492 @ fffc0492 (14 bytes)

void FUN_fffc0492(void)

{
  FUN_fffc4170(DAT_00009aca);
  return;
}

