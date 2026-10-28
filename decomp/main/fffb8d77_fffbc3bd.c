// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb8d77 @ fffb8d77 (518 bytes)

void FUN_fffb8d77(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  byte local_b;
  byte local_a;
  byte local_9;
  char cStack_7;
  byte bStack_6;
  byte local_5;
  
  uVar8 = DAT_00020f50;
  cVar7 = DAT_00009dbd;
  cVar6 = DAT_00009b1d;
  cVar5 = DAT_00009b1c;
  cVar4 = DAT_00009b1b;
  cVar3 = DAT_00009b1a;
  if (DAT_00020f3b != '\x01') {
    local_5 = 0;
    if (DAT_00020b48 == '\x01') {
      local_5 = 0x10;
    }
    iVar9 = vfo_mode(1);
    if (((1 < iVar9 - 2U) && (1 < iVar9 - 0xcU)) && (DAT_00009c5d != '\0')) {
      local_5 = local_5 | 0x80;
    }
    DAT_00020b3d = 0;
    if (DAT_00020b6b == '\x01') {
      local_5 = local_5 & 0xef | 0x20;
      DAT_00020b3d = 1;
    }
    else {
      if ((DAT_0001204d == '\0') || (iVar9 = tx_freq_allowed(uVar8), iVar9 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_5 = local_5 & 0xef;
        iVar9 = blink_phase(0);
        if (iVar9 != 0) {
          local_5 = local_5 | 0x20;
        }
        DAT_00020b3d = 2;
      }
    }
    if (cVar7 == '\0') {
      bStack_6 = DAT_00009dbe;
      cStack_7 = DAT_00020f29;
    }
    else {
      bStack_6 = DAT_00009dbf;
      cStack_7 = DAT_00020f2a;
    }
    if (cVar3 == '\x02') {
      local_9 = 1;
    }
    else if (cVar3 == '\x01') {
      local_9 = 2;
    }
    else if (cVar3 == '\0') {
      local_9 = 8;
    }
    else {
      local_9 = 0;
    }
    if (cVar4 == '\x02') {
      local_a = 1;
    }
    else if (cVar4 == '\x01') {
      local_a = 2;
    }
    else if (cVar4 == '\0') {
      local_a = 8;
    }
    else {
      local_a = 0;
    }
    if (cVar5 == '\x02') {
      local_b = 4;
    }
    else if (cVar5 == '\x01') {
      local_b = 2;
    }
    else if (cVar5 == '\0') {
      local_b = 8;
    }
    else {
      local_b = 0;
    }
    if (DAT_00009c5e == '\0') {
      if (cStack_7 == '\0') {
        uVar1 = (uint)bStack_6;
        if ((uVar1 - 7 < 2) || (uVar1 - 2 < 3)) {
          local_5 = local_5 | local_b;
        }
        else if ((uVar1 == 5) || (uVar1 == 1)) {
          if (cVar7 == '\0') {
            local_5 = local_5 | local_9;
          }
          else {
            local_5 = local_5 | local_a;
          }
        }
      }
      else {
        local_5 = local_5 | cVar6 == '\0';
      }
    }
    else {
      local_5 = local_5 | 1;
    }
    if (DAT_00020b74 != '\0') {
      local_5 = local_5 | 0x40;
    }
    if (DAT_00020b38 != local_5) {
      DAT_00020b38 = local_5;
      return;
    }
  }
  return;
}


// ===== linear_band_data @ fffb8f7d (481 bytes)

/* TUN/LIN=LINEAR: band code on P13/P12/P50/P22 */

void linear_band_data(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = tunlin_port_mode();
  if (iVar3 == 1) {
    cVar2 = FUN_fffb33ab(DAT_00020f50);
    if (DAT_0001b4d0 != cVar2) {
      DAT_0001b4d0 = cVar2;
      switch(cVar2) {
      case '\0':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\x01':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\x02':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x03':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x04':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x05':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x06':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\a':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\b':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\t':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\n':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\v':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\f':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      }
    }
    return;
  }
  DAT_0001b4d0 = 0xff;
  return;
}


// ===== FUN_fffb915e @ fffb915e (393 bytes)

void FUN_fffb915e(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  byte bStack_4;
  char cStack_3;
  
  if (DAT_00020b6b == '\0') {
    if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      beep_stop();
      bVar1 = DAT_0008c02c;
      DAT_0008c02c = bVar1 | 0x10;
      return;
    }
  }
  else {
    cVar4 = vfo_mode(1);
    cVar3 = DAT_00009a8e;
    if (DAT_00009dc6 == '\0') {
      cStack_3 = DAT_00009a8a;
    }
    else {
      cStack_3 = DAT_00020b68;
    }
    if (cStack_3 == '\x03') {
      puVar5 = (undefined4 *)&DAT_0008c042;
      bVar1 = DAT_0008c042;
      bStack_4 = bVar1 >> 1 & 1;
    }
    else if (cStack_3 == '\x02') {
      puVar5 = (undefined4 *)&DAT_0008c02c;
      bVar1 = DAT_0008c04c;
      bStack_4 = bVar1 >> 6 & 1;
    }
    else {
      if (cStack_3 != '\x01') {
        return;
      }
      puVar5 = (undefined4 *)&DAT_0008c02c;
      bVar1 = DAT_0008c04c;
      bStack_4 = bVar1 >> 5 & 1;
    }
    if ((cVar4 == '\f') || (cVar4 == '\r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      if (bStack_4 == 0) {
        *puVar5 = 1;
      }
      if (cVar3 == '\0') {
        if (puVar5 == (undefined4 *)0x0) {
          bVar1 = DAT_0008c02c;
          DAT_0008c02c = bVar1 | 0x10;
          if (DAT_0001b4d1 != '\x01') {
            DAT_0001b4d1 = 1;
            beep_request(9);
            return;
          }
        }
        else {
          bVar1 = DAT_0008c02c;
          DAT_0008c02c = bVar1 & 0xef;
          if (DAT_0001b4d1 != '\x03') {
            DAT_0001b4d1 = 3;
            beep_request(0xb);
            return;
          }
        }
      }
      else if (puVar5 == (undefined4 *)0x0) {
        bVar1 = DAT_0008c02c;
        DAT_0008c02c = bVar1 & 0xef;
        if (DAT_0001b4d1 != '\x03') {
          DAT_0001b4d1 = 3;
          beep_request(0xb);
          return;
        }
      }
      else {
        bVar1 = DAT_0008c02c;
        DAT_0008c02c = bVar1 | 0x10;
        if (DAT_0001b4d1 != '\x01') {
          DAT_0001b4d1 = 1;
          beep_request(9);
          return;
        }
      }
    }
    else if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      beep_stop();
      bVar1 = DAT_0008c02c;
      DAT_0008c02c = bVar1 | 0x10;
      return;
    }
  }
  return;
}


// ===== FUN_fffb92e7 @ fffb92e7 (105 bytes)

undefined1 FUN_fffb92e7(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012052)[DAT_00012062] = param_1;
  DAT_00012062 = DAT_00012062 + 1;
  if (0xf < DAT_00012062) {
    DAT_00012062 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012052)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9350 @ fffb9350 (105 bytes)

undefined1 FUN_fffb9350(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012063)[DAT_00012073] = param_1;
  DAT_00012073 = DAT_00012073 + 1;
  if (0xf < DAT_00012073) {
    DAT_00012073 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012063)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb93b9 @ fffb93b9 (105 bytes)

undefined1 FUN_fffb93b9(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012074)[DAT_00012084] = param_1;
  DAT_00012084 = DAT_00012084 + 1;
  if (0xf < DAT_00012084) {
    DAT_00012084 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012074)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9422 @ fffb9422 (105 bytes)

undefined1 FUN_fffb9422(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012085)[DAT_00012095] = param_1;
  DAT_00012095 = DAT_00012095 + 1;
  if (0xf < DAT_00012095) {
    DAT_00012095 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012085)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb948b @ fffb948b (110 bytes)

void FUN_fffb948b(undefined4 param_1)

{
  byte local_9;
  float local_8;
  
  *(undefined4 *)(&DAT_00020fd0 + (uint)DAT_00012096 * 4) = param_1;
  DAT_00012096 = DAT_00012096 + 1;
  if (0xf < DAT_00012096) {
    DAT_00012096 = 0;
  }
  local_8 = 0.0;
  for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
    local_8 = *(float *)(&DAT_00020fd0 + (uint)local_9 * 4) + local_8;
  }
  DAT_00020fc8 = local_8 / 16.0;
  return;
}


// ===== FUN_fffb94f9 @ fffb94f9 (163 bytes)

undefined1 FUN_fffb94f9(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012097)[DAT_000120a7] = param_1;
  DAT_000120a7 = DAT_000120a7 + 1;
  if (0xf < DAT_000120a7) {
    DAT_000120a7 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012097)[local_5] + local_4;
  }
  DAT_0001204b = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    if (DAT_0001204b < (byte)(&DAT_00012097)[local_5]) {
      DAT_0001204b = (&DAT_00012097)[local_5];
    }
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb959c @ fffb959c (105 bytes)

undefined1 FUN_fffb959c(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_000120a8)[DAT_000120b8] = param_1;
  DAT_000120b8 = DAT_000120b8 + 1;
  if (0xf < DAT_000120b8) {
    DAT_000120b8 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_000120a8)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9605 @ fffb9605 (367 bytes)

void FUN_fffb9605(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bStack_11;
  char cStack_a;
  undefined2 uStack_6;
  
  iVar6 = vfo_rec_ptr(0);
  uStack_6 = 100;
  bVar3 = *(byte *)(iVar6 + 5) & 3;
  vfo_freq(0,2);
  cVar4 = gen_subband_of_freq();
  cVar5 = vfo_mode(0);
  bVar2 = DAT_00020b18;
  iVar6 = audio_route_state();
  bVar1 = DAT_000120ba != bVar3;
  if (!bVar1) {
    bVar3 = DAT_000120ba;
  }
  DAT_000120ba = bVar3;
  bStack_11 = DAT_000120b9 != cVar4;
  if (!bStack_11) {
    cVar4 = DAT_000120b9;
  }
  DAT_000120b9 = cVar4;
  bStack_11 = bStack_11 || bVar1;
  if (DAT_000120bb != cVar5) {
    bStack_11 = true;
    DAT_00020b48 = 0;
    DAT_000120bb = cVar5;
  }
  if (bVar2 < 7) {
    cStack_a = '\x03';
  }
  else {
    cStack_a = '\b';
  }
  if (((DAT_0001b4d2 != cStack_a) && (DAT_0001b4d2 = cStack_a, cStack_a == '\b')) &&
     ((uVar7 = vfo_mode(1), 3 < uVar7 || (iVar8 = FUN_fffba192(), iVar8 == 0)))) {
    bStack_11 = true;
    uStack_6 = 0x28;
  }
  iVar8 = DAT_00025d48;
  if (DAT_00025d48 != iVar6) {
    if ((iVar6 == 2) || (iVar6 == 6)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_00025d48 != 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00025d48 != 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    iVar8 = iVar6;
    if (bVar1) {
      swtimer_start(0x2c,3);
      DAT_00020b49 = 0;
    }
  }
  DAT_00025d48 = iVar8;
  if (bStack_11) {
    swtimer_start(0x2a,uStack_6);
    DAT_0001204f = 1;
    af_mute_set(1);
    DAT_0001204f = 0;
    return;
  }
  return;
}


// ===== pc_keying @ fffb9774 (340 bytes)

/* CW keying from DAKY/RTS/DTR: SEND lines + sidetone beep */

void pc_keying(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  if (DAT_00009a9f == '\x03') {
    bVar1 = DAT_0008c042;
    if (((bVar1 & 1) == 0) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  else if (DAT_00009a9f == '\x02') {
    bVar1 = DAT_0008c047;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = DAT_0008c04c, (bVar1 & 0x20) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  else {
    if (DAT_00009a9f != '\x01') {
      return;
    }
    bVar1 = DAT_0008c047;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = DAT_0008c04c, (bVar1 & 0x40) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    if (DAT_0001b4d3 == '\0') {
      beep_request(4);
      DAT_0001b4d3 = '\x01';
    }
  }
  else if (DAT_0001b4d3 != '\0') {
    beep_stop();
    DAT_0001b4d3 = '\0';
  }
  if ((DAT_00012050 == '\x01') && (DAT_00020b18 == '\x03')) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (!bVar3) {
    if (DAT_0001b4d4 == '\x01') {
      send_a_set(0);
      send_b_set(0);
    }
    DAT_0001b4d4 = 0;
    return;
  }
  if (bVar2) {
    send_a_set(1);
    send_b_set(1);
    DAT_0001b4d4 = 1;
    return;
  }
  if (DAT_0001b4d4 != '\x01') {
    return;
  }
  send_a_set(0);
  send_b_set(0);
  DAT_0001b4d4 = 0;
  return;
}


// ===== keyer_init @ fffb98c8 (33 bytes)

/* Clears keyer state 0x120BC (0xA0 B) */

void keyer_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_00020b2f = 0;
  DAT_0001215f = 0;
  puVar1 = &DAT_000120bc;
  for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return;
}


// ===== keyer_task @ fffb98e9 (2120 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb99ff) */
/* WARNING: Removing unreachable block (ram,0xfffb9dba) */
/* WARNING: Removing unreachable block (ram,0xfffb9dc9) */
/* WARNING: Removing unreachable block (ram,0xfffb9e12) */
/* WARNING: Removing unreachable block (ram,0xfffb9fbe) */
/* WARNING: Removing unreachable block (ram,0xfffb9d50) */
/* WARNING: Removing unreachable block (ram,0xfffb9e51) */
/* WARNING: Removing unreachable block (ram,0xfffb9e42) */
/* WARNING: Removing unreachable block (ram,0xfffb9e7a) */
/* main_loop task 12: CW keyer (speed 0x9C03, 0x20B97) [inference] */

void keyer_task(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  int in_stack_0000003c;
  char cStack_19;
  char cStack_18;
  byte bStack_15;
  byte bStack_13;
  byte bStack_11;
  byte bStack_10;
  ushort uStack_e;
  ushort uStack_c;
  byte bStack_9;
  
  bVar1 = DAT_00009aa9;
  iVar8 = FUN_fffba192();
  if ((iVar8 == 0) || (DAT_00020b97 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    keyer_init();
    FUN_fffbb1c2();
    DAT_00020b2a = 0;
    return;
  }
  iVar8 = swtimer_expired(0x13);
  if ((iVar8 != 1) || (DAT_00020f0c != '\0')) {
    return;
  }
  if (DAT_0001b4d5 != DAT_00009c03) {
    bVar2 = false;
    if (DAT_00012164 == '\0') {
      FUN_fffbb283();
      if ((cStack_18 == '\x01') && (cStack_19 == '\x01')) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if (bVar3) {
        if (DAT_00012162 == '\x02') {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
    }
    if (bVar2) {
      DAT_0001b4d5 = DAT_00009c03;
      keyer_init();
    }
  }
  if (DAT_00009c02 == '\0') {
    DAT_0001215f = 0;
  }
  else {
    DAT_0001215f = DAT_00009aa7;
  }
  DAT_00021014 = 1200000;
  if (DAT_0001b4d5 != 0) {
    DAT_00021014 = 1200000 / DAT_0001b4d5;
  }
  DAT_00021010 = ((bVar1 + 0x19) * DAT_00021014) / 10;
  DAT_0001215c = FUN_fffb548a();
  if (DAT_0001215f == 0) {
    DAT_0001215c = 0xf;
  }
  else {
    if ((DAT_0001b4d5 < 0x29) || (DAT_0001215c < 0x10)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      DAT_0001215c = 0xf;
    }
    else {
      if ((DAT_0001b4d5 < 0x24) || (DAT_0001215c < 0x15)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        DAT_0001215c = 0x14;
      }
      else {
        if ((DAT_0001b4d5 < 0x1f) || (DAT_0001215c < 0x1a)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          DAT_0001215c = 0x19;
        }
      }
    }
  }
  switch(DAT_00020b2f) {
  case 0:
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 1;
    swtimer_start(0x19,DAT_0001215c);
    FUN_fffbaff6();
  case 1:
    if (DAT_0001215f < 2) {
      FUN_fffba840(DAT_0001215f);
    }
    else if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,0);
    }
    break;
  case 2:
    if (DAT_0001215d != '\x01') {
      return;
    }
    puVar11 = &DAT_000120bc;
    for (iVar8 = 0xa0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 3;
    swtimer_start(0x19,DAT_0001215c);
    swtimer_start(0x1b,&DAT_00002710);
    FUN_fffbaff6();
    DAT_00021040 = vfo_rec_ptr(1);
    iVar8 = FUN_fffb521a();
    if (iVar8 == 1) {
      DAT_00012166 = '\x01';
      *(byte *)(DAT_00021040 + 0x14) = *(byte *)(DAT_00021040 + 0x14) & 0xfd;
    }
    else {
      DAT_00012166 = '\0';
    }
  case 3:
    if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,1);
    }
    break;
  case 4:
    if (DAT_00012166 == '\x01') {
      DAT_00012166 = '\0';
      *(byte *)(DAT_00021040 + 0x14) = *(byte *)(DAT_00021040 + 0x14) | 2;
    }
    DAT_0001fa3a = DAT_0001fa38;
    if (DAT_0001fa38 != 0) {
      bStack_9 = DAT_00020ccc;
      if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        bStack_9 = 1;
      }
      in_stack_0000003c = in_stack_0000003c * 0x98;
      (&DAT_0000930f)[in_stack_0000003c] = (char)(DAT_0001fa38 >> 8);
      (&DAT_00009310)[in_stack_0000003c] = (char)DAT_0001fa3a;
      puVar9 = &DAT_00009311 + in_stack_0000003c;
      puVar11 = &DAT_000120bc;
      for (iVar8 = 0x96; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *(undefined1 *)puVar11;
        puVar9 = puVar9 + 1;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      eeprom_save_msg(0,bStack_9);
    }
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    DAT_00020b2f = 0;
    break;
  case 5:
    DAT_00012165 = '\0';
    if (DAT_0001215d != '\x01') {
      DAT_00012165 = 0;
      return;
    }
    iVar8 = FUN_fffb2dfe();
    if (iVar8 == 1) {
      return;
    }
    bStack_9 = DAT_00020ccc;
    if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_9 = 1;
    }
    bStack_9 = bStack_9 - 1;
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    if ((&DAT_00009aad)[bStack_9] == '\x01') {
      DAT_0001fa38 = CONCAT11(*(undefined1 *)(&DAT_000093a7 + in_stack_0000003c * 0x26),
                              *(undefined1 *)((int)&DAT_000093a7 + in_stack_0000003c * 0x98 + 1));
      puVar10 = (undefined1 *)((int)&DAT_000093a7 + in_stack_0000003c * 0x98 + 2);
      puVar11 = &DAT_000120bc;
      for (iVar8 = 0x96; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar11 = *puVar10;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar10 = puVar10 + 1;
      }
    }
    else {
      iVar8 = (uint)bStack_9 * 0x33;
      bVar1 = (&DAT_0000969f)[iVar8];
      bVar2 = false;
      for (bStack_13 = 0; bStack_13 < bVar1; bStack_13 = bStack_13 + 1) {
        bVar5 = (&DAT_000096a0)[(uint)bStack_13 + iVar8];
        bVar4 = (&DAT_fff815c3)[(uint)bVar5 * 2];
        bStack_15 = (&DAT_fff815c4)[(uint)bVar5 * 2];
        if (bVar5 == 0x23) {
          DAT_00012165 = '\x01';
          uStack_e = FUN_fffba30c();
          uStack_c = 1000;
          for (bStack_11 = 0; bStack_11 < 4; bStack_11 = bStack_11 + 1) {
            uVar12 = (uint)uStack_e;
            if (uStack_c != 0) {
              uVar12 = uVar12 / uStack_c;
            }
            uVar7 = uStack_e;
            if ((uStack_c & 0xff) != 0) {
              uVar7 = (ushort)((uint)uStack_e / (uStack_c & 0xff));
            }
            uStack_e = uStack_e - (uVar7 * uStack_c & 0xff);
            uStack_c = uStack_c / 10;
            cVar6 = nib2hex(uVar12 & 0xff);
            if ((bStack_11 == 0) && (cVar6 == '0')) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            if (!bVar3) {
              bVar4 = FUN_fffbb2bf(cVar6);
              bVar5 = (&DAT_fff815c3)[(uint)bVar4 * 2];
              bStack_15 = (&DAT_fff815c4)[(uint)bVar4 * 2];
              for (bStack_10 = 0; bStack_10 < bVar5; bStack_10 = bStack_10 + 1) {
                if ((bStack_15 & 0x80) == 0) {
                  FUN_fffbb024(1);
                }
                else {
                  FUN_fffbb024(2);
                }
                FUN_fffbb024(0);
                bStack_15 = bStack_15 << 1;
              }
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                FUN_fffbb024(0);
              }
            }
          }
        }
        else if (bVar5 == 0x3c) {
          iVar13 = FUN_fffb521a();
          if ((iVar13 == 1) && (uVar7 = FUN_fffba30c(), uVar7 < 9999)) {
            FUN_fffba336(uVar7 + 1);
          }
        }
        else if (bVar5 == 0x3e) {
          iVar13 = FUN_fffb521a();
          if ((iVar13 == 1) && (uVar7 = FUN_fffba30c(), 1 < uVar7)) {
            FUN_fffba336(uVar7 - 1);
          }
        }
        else if (bVar5 == 0x5b) {
          bVar2 = true;
        }
        else if (bVar5 == 0x5d) {
          bVar2 = false;
        }
        else if (bVar5 == 0x5e) {
          bVar5 = bStack_13 + 1;
          bStack_13 = bStack_13 + 2;
          if ((&DAT_000096a0)[(uint)bVar5 + iVar8] == '0') {
            bVar5 = (&DAT_000096a0)[(uint)bStack_13 + iVar8];
            if ((bVar5 < 0x31) || (0x35 < bVar5)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              cVar6 = hex2nib(bVar5);
              if (bStack_9 != (byte)(cVar6 - 1U)) {
                FUN_fffbb338(cVar6 - 1U);
              }
            }
          }
        }
        else {
          bStack_10 = 0;
          if (bVar4 == 0) {
            for (; bStack_10 < 4; bStack_10 = bStack_10 + 1) {
              FUN_fffbb024(0);
            }
          }
          else {
            for (; bStack_10 < bVar4; bStack_10 = bStack_10 + 1) {
              if ((bStack_15 & 0x80) == 0) {
                FUN_fffbb024(1);
              }
              else {
                FUN_fffbb024(2);
              }
              FUN_fffbb024(0);
              bStack_15 = bStack_15 << 1;
            }
            if (!bVar2) {
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                FUN_fffbb024(0);
              }
            }
          }
        }
        if (0x4b0 < DAT_0001fa38) break;
      }
    }
    DAT_0001fa3c = DAT_0001fa38;
    DAT_0001fa38 = 0;
    swtimer_start(0x19,DAT_0001215c);
    DAT_00020b2f = 6;
    FUN_fffbaff6();
  case 6:
    if (DAT_0001fa3a == DAT_0001fa3c) {
      DAT_00020b2f = 7;
      if (DAT_00020cd5 == '\x01') {
        swtimer_start(0x1c,(ushort)DAT_00009ab2 * 1000);
      }
      if ((DAT_00012165 == '\x01') && (uVar7 = FUN_fffba30c(), uVar7 < 9999)) {
        FUN_fffba336(uVar7 + 1);
      }
    }
    else {
      FUN_fffbb283();
      if ((cStack_18 == '\x01') || (cStack_19 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        DAT_00020cd5 = '\0';
        DAT_00020b2f = 7;
      }
    }
    FUN_fffba9c3();
    break;
  case 7:
    if (DAT_00020cd5 == '\x01') {
      iVar8 = swtimer_expired(0x1c);
      if (iVar8 == 1) {
        DAT_00020b2f = 5;
      }
    }
    else {
      DAT_0001fa38 = 0;
      DAT_0001fa3a = 0;
      FUN_fffbb1c2();
      DAT_00020b2f = 0;
    }
  }
  FUN_fffbaa81(DAT_0001215f);
  return;
}


// ===== FUN_fffba192 @ fffba192 (378 bytes)

undefined1 FUN_fffba192(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined1 uStack_5;
  
  bVar4 = ptt_source_get();
  cVar5 = vfo_mode(1);
  uStack_5 = 0;
  cVar6 = FUN_fffb50d7(cVar5);
  cVar3 = DAT_00009a9f;
  DAT_0001215d = 0;
  if ((cVar5 == '\x03') || (cVar5 == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_0001215d = 1;
  }
  else {
    if ((cVar5 == '\0') || (cVar5 == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_0001215d = 2;
    }
  }
  if ((cVar5 == '\x03') || (cVar5 == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    return 1;
  }
  if ((cVar5 == '\0') || (cVar5 == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (DAT_00009a3c != '\x02') {
    if ((DAT_00009a3c == '\x01') && (iVar7 = FUN_fffb32fd(DAT_00020f50), iVar7 == 0xb)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      bVar2 = false;
      goto LAB_fffba271;
    }
  }
  bVar2 = true;
LAB_fffba271:
  if (bVar2) {
    uVar1 = (uint)bVar4;
    if (uVar1 == 1) {
      if ((cVar6 == '\0') || (cVar3 == '\x03')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else if (uVar1 == 3) {
      if ((cVar6 == '\0') || (cVar3 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else if (uVar1 == 4) {
      if ((cVar6 == '\0') || (cVar3 == '\x02')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else {
      if (uVar1 != 6) {
        if (uVar1 == 7) {
          return 3;
        }
        if ((1 < uVar1 - 8) && (uVar1 != 0xb)) {
          return 4;
        }
      }
      uStack_5 = 2;
    }
  }
  return uStack_5;
}


// ===== FUN_fffba30c @ fffba30c (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba31c) */

undefined2 FUN_fffba30c(void)

{
  return CONCAT11(DAT_00009aab,DAT_00009aac);
}


// ===== FUN_fffba336 @ fffba336 (38 bytes)

void FUN_fffba336(undefined2 param_1)

{
  DAT_00009aab = (char)((ushort)param_1 >> 8);
  DAT_00009aac = (char)param_1;
  return;
}


// ===== FUN_fffba35c @ fffba35c (27 bytes)

undefined2 FUN_fffba35c(void)

{
  return *(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2);
}


// ===== FUN_fffba377 @ fffba377 (1225 bytes)

void FUN_fffba377(char param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  char cStack_a;
  char cStack_9;
  undefined4 uStack_8;
  
  iVar2 = ckey_det();
  if (iVar2 != 1) {
    DAT_00020b2a = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  iVar2 = swtimer_expired(0x17);
  if (iVar2 != 1) {
    if (DAT_00012160 == '\0') {
      FUN_fffbb283();
      if ((param_1 == '\x03') || (param_1 == '\x04')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if ((DAT_00012161 == '\x02') && (cStack_9 == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_00012160 = '\x01';
        }
        else {
          if ((DAT_00012161 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00012160 = '\x02';
          }
        }
        if (param_1 == '\x04') {
          if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            DAT_00012160 = '\0';
          }
          else {
            iVar2 = swtimer_expired(0x1d);
            if ((iVar2 != 1) && (DAT_00012161 == '\x02')) {
              DAT_00012160 = '\0';
            }
          }
        }
      }
      if ((DAT_00012160 == '\0') && (DAT_00012161 == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (DAT_00012163 == 1) {
          if (param_1 == '\x03') {
            if ((DAT_00012162 == '\x01') && (cStack_a == '\x01')) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (bVar1) {
              DAT_00012160 = '\x02';
            }
            else {
              if ((DAT_00012162 == '\x02') && (cStack_9 == '\x01')) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
              if (bVar1) {
                DAT_00012160 = '\x01';
              }
            }
          }
        }
        else {
          if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            if (cStack_9 == '\x01') {
              DAT_00012160 = '\x01';
            }
            else if (cStack_a == '\x01') {
              DAT_00012160 = '\x02';
            }
          }
        }
      }
    }
    if ((DAT_00012163 < 2) || (DAT_00012160 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (param_1 != '\x05')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      swtimer_start(0x19,DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
    else {
      if ((DAT_00012163 < 4) || (DAT_00012160 == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (param_1 == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        return;
      }
      swtimer_start(0x19,DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
  }
  if ((param_2 == '\x01') && (iVar2 = FUN_fffbb10b(), iVar2 == 1)) {
    DAT_00020b2f = 4;
    return;
  }
  if (DAT_00012161 == '\0') {
    FUN_fffbb283();
    if ((param_1 == '\x03') || (param_1 == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00012160 == '\x02') {
        cStack_9 = '\0';
        cStack_a = '\x01';
      }
      else if (DAT_00012160 == '\x01') {
        cStack_9 = '\x01';
        cStack_a = '\0';
      }
    }
    else {
      if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        if (DAT_00012160 == '\x02') {
          cStack_9 = '\0';
          cStack_a = '\x01';
        }
        else if (DAT_00012160 == '\x01') {
          cStack_9 = '\x01';
          cStack_a = '\0';
        }
      }
    }
    DAT_00012160 = '\0';
    if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00012162 == '\x01') {
        DAT_00012161 = '\x02';
        uStack_8 = DAT_00021010;
      }
      else {
        DAT_00012161 = '\x01';
        uStack_8 = DAT_00021014;
      }
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      uStack_8 = DAT_00021014;
    }
    else if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      uStack_8 = DAT_00021010;
    }
    else {
      if ((6 < DAT_00012163) ||
         ((DAT_00012163 = DAT_00012163 + 1, param_2 == '\x01' && (DAT_0001fa38 == 0)))) {
        return;
      }
      DAT_00012161 = '\0';
      uStack_8 = DAT_00021014;
    }
    if ((param_1 == '\x05') || (DAT_00012161 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_00012163 = 0;
    }
    if ((param_1 == '\x05') && (DAT_00012163 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00012161 != '\0')) {
      DAT_00012160 = DAT_00012161;
      DAT_00012161 = '\0';
      uStack_8 = DAT_00021014;
      DAT_00012163 = DAT_00012163 + 1;
    }
  }
  else {
    DAT_00012162 = DAT_00012161;
    DAT_00012161 = '\0';
    uStack_8 = DAT_00021014;
    DAT_00012163 = 1;
    if (param_2 == '\x01') {
      swtimer_start(0x1b,&DAT_00002710);
    }
  }
  timer_start_us(0x17,uStack_8);
  if ((param_1 == '\x04') && (DAT_00012161 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    timer_start_us(0x1d,DAT_00021014);
  }
  FUN_fffbb024(DAT_00012161);
  return;
}


// ===== FUN_fffba840 @ fffba840 (387 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba98f) */

void FUN_fffba840(char param_1)

{
  char cVar1;
  int iVar2;
  char cStack_a;
  char cStack_9;
  undefined4 uStack_8;
  
  iVar2 = ckey_det();
  if (iVar2 != 1) {
    DAT_00020b2a = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  iVar2 = swtimer_expired(0x17);
  if (iVar2 != 1) {
    return;
  }
  if (param_1 == '\0') {
    cVar1 = ckey_dot();
    DAT_00012161 = cVar1 == '\x01';
    if ((bool)DAT_00012161) {
      DAT_0001b4d6 = 0;
    }
    else {
      DAT_0001b4d6 = DAT_0001b4d6 + 1;
    }
    if (1 < DAT_0001b4d6) {
      DAT_0001b4d6 = DAT_0001b4d6 - 1;
      return;
    }
    swtimer_start(0x17,2);
    FUN_fffbb024(DAT_00012161);
    return;
  }
  if (DAT_00012161 == '\x01') {
    DAT_00012161 = '\0';
    uStack_8 = DAT_00021014;
  }
  else {
    FUN_fffbb283();
    if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      uStack_8 = 2000;
      DAT_0001b4d6 = 0;
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      uStack_8 = DAT_00021014;
      DAT_0001b4d6 = 0;
    }
    else {
      DAT_00012161 = '\0';
      uStack_8 = 2000;
      DAT_0001b4d6 = DAT_0001b4d6 + 1;
    }
  }
  if (10 < DAT_0001b4d6) {
    DAT_0001b4d6 = DAT_0001b4d6 - 1;
    return;
  }
  timer_start_us(0x17,uStack_8);
  *(undefined4 *)(&DAT_00021018 + ((uint)DAT_0001fa38 - ((DAT_0001fa38 / 10) * 10 & 0xff)) * 4) =
       uStack_8;
  if (DAT_00012161 == '\x02') {
    FUN_fffbb024(1);
    return;
  }
  FUN_fffbb024(DAT_00012161);
  return;
}


// ===== FUN_fffba9c3 @ fffba9c3 (190 bytes)

void FUN_fffba9c3(void)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uStack_6;
  undefined4 uStack_4;
  
  iVar3 = swtimer_expired(0x17);
  if (iVar3 == 1) {
    if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa38 >> 3)) &
        1 << ((byte)DAT_0001fa38 & 7)) == 0) {
      uStack_4 = DAT_00021014;
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
    }
    else {
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
      if ((DAT_0001fa3c == uStack_6) ||
         (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_6 >> 3)) &
          1 << ((byte)uStack_6 & 7)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        uStack_4 = DAT_00021010;
        uVar2 = FUN_fffbb16b(uStack_6);
        uStack_6 = FUN_fffbb16b(uVar2);
      }
      else {
        uStack_4 = DAT_00021014;
      }
    }
    DAT_0001fa38 = uStack_6;
    timer_start_us(0x17,uStack_4);
    return;
  }
  return;
}


// ===== FUN_fffbaa81 @ fffbaa81 (1397 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbafc6) */

void FUN_fffbaa81(byte param_1)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  char cVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  undefined2 uVar8;
  int iVar9;
  byte bStack_18;
  byte bStack_17;
  char cStack_16;
  ushort uStack_12;
  uint uStack_10;
  
  uVar5 = DAT_00020f50;
  vfo_rec_ptr(1);
  cVar4 = DAT_00020b18;
  cStack_16 = -1;
  bVar1 = false;
  if (DAT_00012164 == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_0001fa38 == DAT_0001fa3a) {
    if ((DAT_00012164 != '\0') && (iVar9 = swtimer_expired(0x1a), iVar9 == 1)) {
      if ((DAT_00020b6b == '\x01') || (iVar9 = tx_freq_allowed(uVar5), iVar9 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (DAT_00020b2a == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b2a = '\0';
      }
    }
    swtimer_start(0x19,DAT_0001215c);
    return;
  }
  if (DAT_00012164 != '\0') {
    if ((param_1 == 0) || (param_1 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) && (DAT_00020b2f != '\x06')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_18 = DAT_0001215c >> 1;
      if (bStack_18 == 0) {
        bStack_18 = 1;
      }
      if ((bStack_18 < DAT_0001fa38) &&
         ((uint)DAT_0001fa3a + (uint)bStack_18 + 1 < (uint)DAT_0001fa38)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if ((*(char *)((int)&DAT_000120bc + (uint)(DAT_0001fa38 >> 3)) == '\0') &&
           (*(char *)((int)&DAT_000120bc + (uint)(DAT_0001fa3a >> 3)) == '\0')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_0001fa3a = DAT_0001fa38 - bStack_18;
        }
      }
      iVar9 = FUN_fffb521a();
      if (iVar9 == 1) {
        uStack_12 = DAT_0001fa3a;
        for (bStack_17 = 0; bStack_17 < bStack_18; bStack_17 = bStack_17 + 1) {
          if (bStack_17 != 0) {
            uStack_12 = FUN_fffbb16b(uStack_12);
          }
          if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_12 >> 3)) &
              1 << ((byte)uStack_12 & 7)) != 0) {
            bVar1 = true;
            break;
          }
        }
        if (bVar1) {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00020b2a = '\x01';
          }
          if (cVar4 != '\x03') {
            tx_freq_allowed(uVar5);
          }
        }
        else {
          iVar9 = swtimer_expired(0x1a);
          if (iVar9 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              DAT_00020b2a = '\0';
            }
          }
        }
      }
    }
    else {
      iVar9 = FUN_fffb521a();
      if (iVar9 == 1) {
        if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa3a >> 3)) &
            1 << ((byte)DAT_0001fa3a & 7)) == 0) {
          iVar9 = swtimer_expired(0x1a);
          if (iVar9 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              DAT_00020b2a = '\0';
            }
          }
        }
        else {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00020b2a = 1;
            return;
          }
          if ((cVar4 != '\x03') && (iVar9 = tx_freq_allowed(uVar5), iVar9 != 0)) {
            return;
          }
        }
      }
    }
  }
  iVar9 = swtimer_expired(0x19);
  if (iVar9 != 1) {
    swtimer_start(0x18,0);
    return;
  }
  iVar9 = swtimer_expired(0x18);
  uVar3 = DAT_0001fa3a;
  if (iVar9 == 1) {
    if ((DAT_00020b2f == '\x01') || (DAT_00020b2f == '\x03')) {
      if (param_1 < 2) {
        cStack_16 = '\x01';
      }
      else if (param_1 - 2 < 4) {
        cStack_16 = '\0';
      }
    }
    else if (DAT_00020b2f == '\x06') {
      cStack_16 = '\0';
    }
    if (cStack_16 == '\0') {
      if (DAT_0001fa38 != DAT_0001fa3a) {
        if (DAT_00020b2f == '\x06') {
          uRam00000006 = 1;
        }
        if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa3a >> 3)) &
            1 << ((byte)DAT_0001fa3a & 7)) == 0) {
          if (DAT_00020b2f != '\0') {
            FUN_fffbb1c2();
          }
          FUN_fffbb1dd(0);
          if (DAT_00012164 != '\0') {
            swtimer_start(0x1a,*(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2));
          }
          uStack_10 = DAT_00021014;
          uStack_12 = FUN_fffbb16b(uVar3);
          DAT_00012164 = 0;
        }
        else {
          if (DAT_00020b2f != '\0') {
            FUN_fffbb185();
          }
          FUN_fffbb1dd(1);
          uStack_12 = FUN_fffbb16b(uVar3);
          if ((DAT_0001fa38 == uStack_12) ||
             (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_12 >> 3)) &
              1 << ((byte)uStack_12 & 7)) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            uStack_10 = DAT_00021010;
            uVar8 = FUN_fffbb16b(uStack_12);
            uStack_12 = FUN_fffbb16b(uVar8);
            DAT_00012164 = 2;
          }
          else {
            uStack_10 = DAT_00021014;
            DAT_00012164 = 1;
          }
        }
        DAT_0001fa3a = uStack_12;
        timer_start_us(0x18,uStack_10);
        return;
      }
    }
    else if ((cStack_16 == '\x01') && (DAT_0001fa38 != DAT_0001fa3a)) {
      bVar6 = (byte)(DAT_0001fa3a >> 3);
      bVar7 = (byte)DAT_0001fa3a & 7;
      if (DAT_00020b2f == '\x06') {
        uRam00000006 = 1;
      }
      if (((uint)*(byte *)((int)&DAT_000120bc + (uint)bVar6) & 1 << bVar7) == 0) {
        if (DAT_00020b2f != '\0') {
          FUN_fffbb1c2();
        }
        FUN_fffbb1dd(0);
        if (DAT_00012164 != '\0') {
          swtimer_start(0x1a,*(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2));
        }
        DAT_00012164 = 0;
      }
      else {
        if (DAT_00020b2f != '\0') {
          FUN_fffbb185();
        }
        FUN_fffbb1dd(1);
        DAT_00012164 = 1;
        *(byte *)((int)&DAT_000120bc + (uint)bVar6) =
             *(byte *)((int)&DAT_000120bc + (uint)bVar6) & ~(byte)(1 << bVar7);
      }
      if (param_1 == 0) {
        uStack_10 = 2000;
      }
      else {
        uStack_10 = *(uint *)(&DAT_00021018 + ((uint)uVar3 - ((uVar3 / 10) * 10 & 0xff)) * 4);
      }
      timer_start_us(0x18,uStack_10 & 0xffff);
      DAT_0001fa3a = FUN_fffbb16b(uVar3);
      return;
    }
  }
  return;
}


// ===== FUN_fffbaff6 @ fffbaff6 (46 bytes)

void FUN_fffbaff6(void)

{
  DAT_00012160 = 0;
  DAT_00012161 = 0;
  DAT_00012162 = 0;
  DAT_00012163 = 0;
  DAT_00012164 = 0;
  return;
}


// ===== FUN_fffbb024 @ fffbb024 (231 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb098) */
/* WARNING: Removing unreachable block (ram,0xfffbb108) */

undefined4 FUN_fffbb024(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  byte local_6;
  
  if (param_1 != '\0') {
    cat_apo_reset();
  }
  if (param_1 != '\x02') {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar4 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      *(undefined1 *)((int)&DAT_000120bc + (uint)bVar2) = 0;
    }
    uVar1 = (uint)bVar2;
    bVar4 = (byte)(1 << (uint)(bVar4 & 7));
    if (param_1 == '\x01') {
      *(byte *)((int)&DAT_000120bc + uVar1) = *(byte *)((int)&DAT_000120bc + uVar1) | bVar4;
      FUN_fffbb185();
    }
    else {
      *(byte *)((int)&DAT_000120bc + uVar1) = *(byte *)((int)&DAT_000120bc + uVar1) & ~bVar4;
      FUN_fffbb1c2();
    }
    uVar3 = FUN_fffbb16b(DAT_0001fa38);
    DAT_0001fa38 = (short)uVar3;
    return uVar3;
  }
  for (local_6 = 0; local_6 < 3; local_6 = local_6 + 1) {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar4 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      *(undefined1 *)((int)&DAT_000120bc + (uint)bVar2) = 0;
    }
    *(byte *)((int)&DAT_000120bc + (uint)bVar2) =
         *(byte *)((int)&DAT_000120bc + (uint)bVar2) | (byte)(1 << (bVar4 & 7));
    DAT_0001fa38 = FUN_fffbb16b(DAT_0001fa38);
  }
  uVar3 = FUN_fffbb185();
  return uVar3;
}


// ===== FUN_fffbb10b @ fffbb10b (96 bytes)

undefined1 FUN_fffbb10b(void)

{
  int iVar1;
  undefined1 local_2;
  
  local_2 = 0;
  iVar1 = swtimer_expired(0x1b);
  if (iVar1 == 1) {
    if (6 < DAT_0001fa38) {
      DAT_0001fa38 = DAT_0001fa38 - 7;
    }
    DAT_0001fa3a = DAT_0001fa38;
    local_2 = 1;
  }
  else if (0x4b0 < DAT_0001fa38) {
    DAT_0001fa38 = 0x4b0;
    DAT_0001fa3a = 0x4b0;
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffbb16b @ fffbb16b (26 bytes)

ushort FUN_fffbb16b(short param_1)

{
  undefined2 local_2;
  
  local_2 = param_1 + 1;
  if (0x4ff < local_2) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffbb185 @ fffbb185 (61 bytes)

void FUN_fffbb185(void)

{
  uint uVar1;
  undefined1 uStack_1;
  
  uVar1 = vfo_mode(1);
  if (uVar1 < 2) {
    uStack_1 = DAT_00009bfc;
  }
  else {
    uStack_1 = DAT_00009bfd;
  }
  if (uStack_1 == '\0') {
    return;
  }
  beep_request(4);
  DAT_0001215e = 1;
  return;
}


// ===== FUN_fffbb1c2 @ fffbb1c2 (27 bytes)

void FUN_fffbb1c2(void)

{
  if (DAT_0001215e != '\x01') {
    return;
  }
  beep_stop();
  DAT_0001215e = 0;
  return;
}


// ===== FUN_fffbb1dd @ fffbb1dd (166 bytes)

void FUN_fffbb1dd(char param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = FUN_fffba192();
  bVar1 = false;
  iVar4 = ptt_source_get();
  if ((iVar4 != 1) && (1 < iVar4 - 3U)) {
    if (iVar4 == 7) {
      bVar1 = true;
      goto LAB_fffbb21f;
    }
    if (iVar4 != 8 && iVar4 != 9) goto LAB_fffbb21f;
  }
  if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar1 = true;
  }
LAB_fffbb21f:
  if (bVar1) {
    send_a_set(param_1);
    send_b_set(param_1);
  }
  if ((DAT_00009aa0 == '\x01') && (param_1 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((DAT_00020b18 == '\x03') && (DAT_00020b2a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b2a = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffbb283 @ fffbb283 (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb2a9) */
/* WARNING: Removing unreachable block (ram,0xfffbb2bc) */

undefined4 FUN_fffbb283(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (DAT_00009aa8 != '\0') {
    uVar1 = ckey_dot();
    *param_2 = uVar1;
    uVar2 = ckey_dash();
    *param_1 = (char)uVar2;
    return uVar2;
  }
  uVar1 = ckey_dot();
  *param_1 = uVar1;
  uVar2 = ckey_dash();
  *param_2 = (char)uVar2;
  return uVar2;
}


// ===== FUN_fffbb2bf @ fffbb2bf (121 bytes)

char FUN_fffbb2bf(char param_1)

{
  char local_1;
  
  if (param_1 == '1') {
    if (3 < DAT_00009aaa - 1) {
      return '1';
    }
    return 'A';
  }
  if (param_1 == '2') {
    if (DAT_00009aaa != 1 && DAT_00009aaa != 2) {
      return '2';
    }
    return 'U';
  }
  if (param_1 == '9') {
    if (5 < DAT_00009aaa - 1) {
      return '9';
    }
    return 'N';
  }
  if (param_1 != '0') {
    return param_1;
  }
  if ((DAT_00009aaa == 6) || (DAT_00009aaa == 2)) {
LAB_fffbb32d:
    local_1 = 'T';
  }
  else {
    if (DAT_00009aaa != 3) {
      if (DAT_00009aaa == 4) goto LAB_fffbb32d;
      if ((DAT_00009aaa != 5) && (DAT_00009aaa != 1)) {
        return '0';
      }
    }
    local_1 = 'O';
  }
  return local_1;
}


// ===== FUN_fffbb338 @ fffbb338 (559 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb382) */
/* WARNING: Removing unreachable block (ram,0xfffbb408) */
/* WARNING: Removing unreachable block (ram,0xfffbb417) */
/* WARNING: Removing unreachable block (ram,0xfffbb3c5) */
/* WARNING: Removing unreachable block (ram,0xfffbb373) */
/* WARNING: Removing unreachable block (ram,0xfffbb51a) */
/* WARNING: Removing unreachable block (ram,0xfffbb440) */

void FUN_fffbb338(byte param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  byte local_13;
  byte local_11;
  byte bStack_f;
  byte local_e;
  ushort uStack_6;
  ushort uStack_4;
  
  bVar1 = (&DAT_0000969f)[(uint)param_1 * 0x33];
  bVar5 = false;
  local_11 = 0;
  while( true ) {
    if (bVar1 <= local_11) {
      return;
    }
    bVar2 = (&DAT_000096a0)[(uint)local_11 + (uint)param_1 * 0x33];
    bVar7 = (&DAT_fff815c3)[(uint)bVar2 * 2];
    local_13 = (&DAT_fff815c4)[(uint)bVar2 * 2];
    if (bVar2 == 0x23) {
      uStack_6 = FUN_fffba30c();
      bVar4 = false;
      uStack_4 = 1000;
      for (bStack_f = 0; bStack_f < 4; bStack_f = bStack_f + 1) {
        uVar9 = (uint)uStack_6;
        if (uStack_4 != 0) {
          uVar9 = uVar9 / uStack_4;
        }
        uVar8 = uStack_6;
        if ((uStack_4 & 0xff) != 0) {
          uVar8 = (ushort)((uint)uStack_6 / (uStack_4 & 0xff));
        }
        uStack_6 = uStack_6 - (uVar8 * uStack_4 & 0xff);
        uStack_4 = uStack_4 / 10;
        cVar6 = nib2hex(uVar9 & 0xff);
        if ((cVar6 != '0') || (bVar4)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar3) || (bStack_f == 3)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          bVar4 = true;
          bVar7 = FUN_fffbb2bf(cVar6);
          bVar2 = (&DAT_fff815c3)[(uint)bVar7 * 2];
          local_13 = (&DAT_fff815c4)[(uint)bVar7 * 2];
          for (local_e = 0; local_e < bVar2; local_e = local_e + 1) {
            if ((local_13 & 0x80) == 0) {
              FUN_fffbb024(1);
            }
            else {
              FUN_fffbb024(2);
            }
            FUN_fffbb024(0);
            local_13 = local_13 << 1;
          }
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            FUN_fffbb024(0);
          }
        }
      }
    }
    else if (bVar2 == 0x3c) {
      uVar8 = FUN_fffba30c();
      if (uVar8 < 9999) {
        FUN_fffba336(uVar8 + 1);
      }
    }
    else if (bVar2 == 0x3e) {
      uVar8 = FUN_fffba30c();
      if (1 < uVar8) {
        FUN_fffba336(uVar8 - 1);
      }
    }
    else if (bVar2 == 0x5b) {
      bVar5 = true;
    }
    else if (bVar2 == 0x5d) {
      bVar5 = false;
    }
    else if (bVar2 == 0x5e) {
      local_11 = local_11 + 2;
    }
    else {
      local_e = 0;
      if (bVar7 == 0) {
        for (; local_e < 4; local_e = local_e + 1) {
          FUN_fffbb024(0);
        }
      }
      else {
        for (; local_e < bVar7; local_e = local_e + 1) {
          if ((local_13 & 0x80) == 0) {
            FUN_fffbb024(1);
          }
          else {
            FUN_fffbb024(2);
          }
          FUN_fffbb024(0);
          local_13 = local_13 << 1;
        }
        if (!bVar5) {
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            FUN_fffbb024(0);
          }
        }
      }
    }
    if (0x4b0 < DAT_0001fa38) break;
    local_11 = local_11 + 1;
  }
  return;
}


// ===== FUN_fffbb567 @ fffbb567 (1020 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb8cc) */
/* WARNING: Removing unreachable block (ram,0xfffbb7f9) */

void FUN_fffbb567(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  int iVar5;
  ushort uVar6;
  byte *local_10;
  byte *local_c;
  
  bVar1 = (&DAT_fff88cd7)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  bVar2 = (&DAT_fff88cd4)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  bVar3 = (bVar2 & 0x80) == 0;
  if (bVar3) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (bVar3) {
    local_10 = (byte *)((int)&DAT_00004761 +
                       (uint)(byte)(&DAT_000060b1)[bVar1] * 0x438 + (uint)bVar1 * 0x5a);
  }
  else {
    local_10 = &DAT_00005409 + (uint)(byte)(&DAT_000060bd)[bVar1] * 0x438 + (uint)bVar1 * 0x5a;
  }
  pbVar4 = local_c;
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar4 = *local_10;
    pbVar4 = pbVar4 + 1;
    local_10 = local_10 + 1;
  }
  if ((bVar2 & 0x20) == 0) {
    local_c[4] = local_c[4] & 0x7f;
  }
  else {
    local_c[4] = local_c[4] | 0x80;
  }
  if ((bVar2 & 8) == 0) {
    local_c[4] = local_c[4] & 0xef;
  }
  else {
    local_c[4] = local_c[4] | 0x10;
  }
  bVar1 = (&DAT_fff88cd5)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  if ((bVar1 & 8) == 0) {
    local_c[3] = local_c[3] & 0xfd;
  }
  else {
    local_c[3] = local_c[3] | 2;
  }
  if ((bVar1 & 4) == 0) {
    local_c[3] = local_c[3] & 0xfe;
  }
  else {
    local_c[3] = local_c[3] | 1;
  }
  if ((bVar1 & 2) == 0) {
    local_c[5] = local_c[5] & 0xfd;
  }
  else {
    local_c[5] = local_c[5] | 2;
  }
  if ((bVar1 & 1) == 0) {
    local_c[5] = local_c[5] & 0xfe;
  }
  else {
    local_c[5] = local_c[5] | 1;
  }
  bVar1 = (&DAT_fff88cd8)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  *local_c = *local_c & 0xf0;
  *local_c = bVar1 & 0xf | *local_c;
  DAT_00009c5b = (&DAT_fff88cd9)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  if (((&DAT_fff88cd4)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc] & 0x40) != 0) {
    local_c[0x4a] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 0x18);
    local_c[0x4b] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 0x10);
    local_c[0x4c] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 8);
    local_c[0x4d] = (&LAB_fff88cdc)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
    PTR_DAT_00025d4c[0x40c] = 1;
  }
  DAT_00021048 = (undefined1 *)FUN_fffc7827();
  if ((*(ushort *)(PTR_DAT_00025d4c + 0x1de) < 0x45) ||
     (0xda < *(ushort *)(PTR_DAT_00025d4c + 0x1de))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (bVar3) {
    uVar6 = *(ushort *)(PTR_DAT_00025d4c + 0x1de) - 0x45;
    DAT_0001fa3e = uVar6 - ((uVar6 / 0xf) * 0xf & 0xff);
    if (DAT_0001fa3e < 3) {
      *DAT_00021048 = 100;
    }
    else if (DAT_0001fa3e < 6) {
      *DAT_00021048 = 0x32;
    }
    else if (DAT_0001fa3e < 9) {
      *DAT_00021048 = 0x14;
    }
    else if (DAT_0001fa3e < 0xc) {
      *DAT_00021048 = 10;
    }
    else if (DAT_0001fa3e < 0xf) {
      *DAT_00021048 = 5;
    }
  }
  else {
    if ((*(ushort *)(PTR_DAT_00025d4c + 0x1de) < 0xde) ||
       (0xe9 < *(ushort *)(PTR_DAT_00025d4c + 0x1de))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      DAT_0001fa3e = (*(short *)(PTR_DAT_00025d4c + 0x1de) - 0xdeU) -
                     (((ushort)(*(short *)(PTR_DAT_00025d4c + 0x1de) - 0xdeU) / 0xc) * 0xc & 0xff);
      if (DAT_0001fa3e < 3) {
        *DAT_00021048 = 0x32;
      }
      else if (DAT_0001fa3e < 6) {
        *DAT_00021048 = 0x14;
      }
      else if (DAT_0001fa3e < 9) {
        *DAT_00021048 = 10;
      }
      else if (DAT_0001fa3e < 0xc) {
        *DAT_00021048 = 5;
      }
    }
    else {
      *DAT_00021048 = 100;
    }
  }
  FUN_fffbba9f(*(undefined2 *)(PTR_DAT_00025d4c + 0x1de));
  FUN_fffbbb85(*(undefined2 *)(PTR_DAT_00025d4c + 0x1de));
  return;
}


// ===== FUN_fffbb963 @ fffbb963 (161 bytes)

void FUN_fffbb963(char param_1)

{
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (*(short *)(PTR_DAT_00025d4c + 0x1de) == 0) {
        *(undefined2 *)(PTR_DAT_00025d4c + 0x1de) = 0x104;
      }
      else {
        *(short *)(PTR_DAT_00025d4c + 0x1de) = *(short *)(PTR_DAT_00025d4c + 0x1de) + -1;
      }
      if (PTR_DAT_00025d4c[0x1dd] != '\0') {
        PTR_DAT_00025d4c[0x1dd] = PTR_DAT_00025d4c[0x1dd] + -1;
      }
    }
  }
  else {
    if ((ushort)(*(short *)(PTR_DAT_00025d4c + 0x1de) + 1U) < 0x105) {
      *(ushort *)(PTR_DAT_00025d4c + 0x1de) = *(short *)(PTR_DAT_00025d4c + 0x1de) + 1U;
    }
    else {
      *(undefined2 *)(PTR_DAT_00025d4c + 0x1de) = 0;
    }
    if ((byte)PTR_DAT_00025d4c[0x1dd] < 8) {
      PTR_DAT_00025d4c[0x1dd] = PTR_DAT_00025d4c[0x1dd] + '\x01';
    }
  }
  FUN_fffbb567();
  return;
}


// ===== FUN_fffbba04 @ fffbba04 (11 bytes)

void FUN_fffbba04(char param_1)

{
  FUN_fffbbbdc((int)param_1);
  return;
}


// ===== FUN_fffbba0f @ fffbba0f (31 bytes)

undefined1 FUN_fffbba0f(void)

{
  return 1;
}


// ===== FUN_fffbba2e @ fffbba2e (113 bytes)

void FUN_fffbba2e(void)

{
  short extraout_var;
  int iVar1;
  uint uVar2;
  
  if ((DAT_0001b4d7 != '\0') && (iVar1 = swtimer_expired(0x42), iVar1 == 1)) {
    DAT_0001b4d8 = DAT_0001b4d8 + 1;
    dsp_status1_raw();
    DAT_0001ff64 = extraout_var + DAT_0001ff64;
    if (DAT_0001b4d8 < 0x10) {
      swtimer_start(0x42,0x1e);
      return;
    }
    uVar2 = (uint)DAT_0001ff64;
    if (DAT_0001b4d8 != 0) {
      uVar2 = uVar2 / DAT_0001b4d8;
    }
    *DAT_00021044 = (char)uVar2;
    DAT_0001b4d7 = 0;
    return;
  }
  return;
}


// ===== FUN_fffbba9f @ fffbba9f (230 bytes)

void FUN_fffbba9f(ushort param_1)

{
  bool bVar1;
  ushort uVar2;
  undefined1 *local_8;
  
  if (param_1 != DAT_0001ff66) {
    if ((DAT_0001ff66 < 0x3a) || (0x44 < DAT_0001ff66)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uVar2 = DAT_0001ff66 * 0xf - 0x321;
      local_8 = PTR_DAT_00025d50 + uVar2;
      if (0xda < uVar2) {
        local_8 = local_8 + 3;
      }
      *local_8 = DAT_00012167;
      local_8[2] = DAT_00012168;
    }
    if ((param_1 < 0x3a) || (0x44 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uVar2 = param_1 * 0xf - 0x321;
      local_8 = PTR_DAT_00025d50 + uVar2;
      if (0xda < uVar2) {
        local_8 = local_8 + 3;
      }
      DAT_00012167 = *local_8;
      *local_8 = 0xff;
      DAT_00012168 = local_8[2];
      local_8[2] = 0xff;
    }
    DAT_0001ff66 = param_1;
    return;
  }
  return;
}


// ===== FUN_fffbbb85 @ fffbbb85 (87 bytes)

void FUN_fffbbb85(short param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != DAT_0001ff68) {
    if (DAT_0001ff68 == 0xf5) {
      puVar1 = (undefined1 *)FUN_fff99877();
      *puVar1 = DAT_00012169;
    }
    if (param_1 == 0xf5) {
      puVar1 = (undefined1 *)FUN_fff99877();
      DAT_00012169 = *puVar1;
      *puVar1 = 0x32;
    }
    DAT_0001ff68 = param_1;
    return;
  }
  return;
}


// ===== FUN_fffbbbdc @ fffbbbdc (46 bytes)

void FUN_fffbbbdc(char param_1)

{
  if (*(short *)(PTR_DAT_00025d4c + 0x1de) == 2) {
    cal_adjust(0x19,0xe6,(int)param_1);
    return;
  }
  cal_adjust(0,0xff,(int)param_1);
  return;
}


// ===== cal_adjust @ fffbbc0a (74 bytes)

/* cfg105[0x20CE2] += delta, clamped to [min,max] (alignment value edit, ZZ00 mode) */

void cal_adjust(byte param_1,byte param_2,char param_3)

{
  short sVar1;
  byte *pbVar2;
  byte local_a;
  
  pbVar2 = PTR_DAT_00025d50 + *(ushort *)(PTR_DAT_00025d4c + 0x1de);
  sVar1 = (ushort)*pbVar2 + (short)param_3;
  if ((short)(ushort)param_2 < sVar1) {
    *pbVar2 = param_2;
    return;
  }
  if ((short)(ushort)param_1 <= sVar1) {
    local_a = (byte)sVar1;
    *pbVar2 = local_a;
    return;
  }
  *pbVar2 = param_1;
  return;
}


// ===== key_task_init @ fffbbd53 (5 bytes)

/* [inference] */

void key_task_init(void)

{
  FUN_fffc4d93();
  return;
}


// ===== key_task @ fffbbd58 (939 bytes)

/* Key state machine (main_loop): press/short/long/repeat/release tables by key class */

void key_task(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffc4d93();
  scope_cursor_follow();
  FUN_fffcdb26();
  iVar2 = key_cancel_check();
  if (iVar2 == 1) {
    PTR_DAT_00025d54[0xa0] = 0;
  }
  if (DAT_0001b4db == '\x01') {
    iVar2 = swtimer_expired(0x3f);
    if (iVar2 == 1) {
      DAT_0001b4db = '\0';
      PTR_DAT_00025d54[0xa0] = 1;
      PTR_DAT_00025d54[0x9d] = 2;
      *(ushort *)(PTR_DAT_00025d54 + 0x9e) = DAT_0001fa40;
    }
  }
  else if ((DAT_0001b4dc == '\x01') && (iVar2 = swtimer_expired(0x40), iVar2 == 1)) {
    key_call_repeat();
    return;
  }
  if (PTR_DAT_00025d54[0xa0] != '\0') {
    PTR_DAT_00025d54[0xa0] = 0;
    if (PTR_DAT_00025d54[0x86] == '\x01') {
      DAT_0001216b = '\0';
    }
    if (DAT_0001216b == '\0') {
      if (PTR_DAT_00025d54[0x9d] == '\x01') {
        PTR_DAT_00025d54[0x409] = 0;
        DAT_0001216b = '\x01';
        DAT_0001216a = PTR_DAT_00025d54[0x9c];
        if (DAT_0001216a == '\x04') {
          key_touch_scope_tune();
          return;
        }
        DAT_0001fa40 = *(ushort *)(PTR_DAT_00025d54 + 0x9e);
        DAT_0001216c = key_class_of(*(ushort *)(PTR_DAT_00025d54 + 0x9e));
        if ((DAT_0001216c == '\0') || (DAT_0001216c == '\x02')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          key_call_press();
          if (PTR_DAT_00025d54[0x409] == '\0') {
            key_call_short();
          }
        }
        else if (DAT_0001216c == '\x01') {
          key_call_press();
        }
        if (DAT_0001fa40 == 0x340) {
          DAT_0001216b = '\0';
        }
        iVar2 = FUN_fffd4c17();
        if (iVar2 == 1) {
          DAT_0001216b = 0;
          FUN_fffd4c26();
          return;
        }
        if (DAT_0001fa40 < 0x300) {
          swtimer_start(0x3f,1000);
          DAT_0001b4db = 1;
          return;
        }
      }
    }
    else if (DAT_0001216b == '\x01') {
      if (DAT_0001216a == '\x04') {
        DAT_0001216b = 0;
        return;
      }
      if (DAT_0001fa40 != *(ushort *)(PTR_DAT_00025d54 + 0x9e)) {
        if (DAT_0001216c == '\x02') {
          if (*(short *)(PTR_DAT_00025d54 + 0x9e) == 0x340) {
            DAT_0001216b = 1;
            return;
          }
          key_call_release();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if (PTR_DAT_00025d54[0x9d] == '\0') {
        if (DAT_0001216c == '\x01') {
          if (PTR_DAT_00025d54[0x409] == '\0') {
            key_call_short();
          }
        }
        else if (DAT_0001216c == '\x02') {
          key_call_release();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if (PTR_DAT_00025d54[0x9d] != '\x02') {
        if (DAT_0001216c == '\x02') {
          key_call_release();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if ((DAT_0001216c == '\x01') || (DAT_0001216c == '\x02')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (PTR_DAT_00025d54[0x409] == '\0')) {
        key_call_long();
      }
      DAT_0001216b = '\x02';
      if ((DAT_0001fa40 == 0x300) && (PTR_DAT_00025d54[0x409] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0001216b = 0;
        return;
      }
    }
    else if (DAT_0001216b == '\x02') {
      if ((DAT_0001216c == '\x02') && (PTR_DAT_00025d54[0x409] == '\0')) {
        key_call_release();
      }
      if (DAT_0001b4dc == '\x01') {
        DAT_0001b4dc = '\0';
      }
      DAT_0001216b = 0;
      FUN_fffc2403();
      return;
    }
  }
  return;
}


// ===== key_cancel_check @ fffbc103 (205 bytes)

/* code 0x340 release: clears +0x78 / 0x20CCC / 0x20B2E */

undefined1 key_cancel_check(void)

{
  bool bVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d54[0xa0] == '\0') {
    local_2 = 0;
  }
  else {
    if ((PTR_DAT_00025d54[0x9c] == '\x04') || (*(short *)(PTR_DAT_00025d54 + 0x9e) != 0x340)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (PTR_DAT_00025d54[0x9d] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_DAT_00025d54[0x78] == '\x01') {
        PTR_DAT_00025d54[0x78] = 0;
        DAT_00020ccc = 0;
        if (DAT_00020b2e == '\x01') {
          DAT_00020b2e = '\0';
        }
      }
      else if (PTR_DAT_00025d54[0x78] == '\x02') {
        PTR_DAT_00025d54[0x78] = 0;
        DAT_00020ccc = 0;
      }
      PTR_DAT_00025d54[0x27] = 0;
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  return local_2;
}


// ===== key_class_of @ fffbc1d0 (85 bytes)

/* class from 0xFFF83164 (or via assignable slot) */

undefined1 key_class_of(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_5;
  
  bVar2 = key_assign_slot(param_1);
  if (bVar2 == 0xff) {
    uStack_5 = *(undefined1 *)((int)&key_class_table + (uint)param_1);
  }
  else {
    uVar1 = (uint)bVar2;
    if (uVar1 < 0xd) {
      uStack_5 = *(undefined1 *)
                  ((int)&key_class_table + (uint)*(ushort *)(&key_assign_codes + uVar1 * 2));
    }
    else {
      uStack_5 = (&UNK_fff834b6)[uVar1];
    }
  }
  return uStack_5;
}


// ===== key_assign_slot @ fffbc225 (122 bytes)

/* assignable code (0x348,0x34E,0x35B..0x35E) -> slot from settings 0x9AC8..0x9ACD */

undefined1 key_assign_slot(short param_1)

{
  undefined1 local_4;
  
  local_4 = 0xff;
  if (param_1 == 0x35e) {
    local_4 = DAT_00009acb;
  }
  else if (param_1 == 0x34e) {
    local_4 = DAT_00009acd;
  }
  else if (param_1 == 0x35b) {
    local_4 = DAT_00009ac8;
  }
  else if (param_1 == 0x35c) {
    local_4 = DAT_00009ac9;
  }
  else if (param_1 == 0x35d) {
    local_4 = DAT_00009aca;
  }
  else if (param_1 == 0x348) {
    local_4 = DAT_00009acc;
  }
  return local_4;
}


// ===== scope_cursor_follow @ fffbc29f (192 bytes)

/* Keep dial inside CURSOR window, update 0x20F60/0x9E82/bandmem 1 */

void scope_cursor_follow(void)

{
  byte bVar1;
  bool local_7;
  byte bStack_6;
  uint local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = *(uint *)(PTR_DAT_00025d54 + 0x450);
  }
  else {
    local_4 = *(uint *)(PTR_DAT_00025d54 + 0x454);
  }
  local_7 = DAT_00009dbd != '\0';
  bVar1 = scope_span_index(local_7);
  if (local_4 < *(uint *)(PTR_DAT_00025d54 + 0x45c)) {
    local_4 = FUN_fffb3aee();
  }
  else {
    if (local_4 <=
        (*(int *)(&scope_span_table + (uint)bVar1 * 4) + *(int *)(PTR_DAT_00025d54 + 0x45c) & 0xffU)
       ) {
      return;
    }
    local_4 = FUN_fffb3aee(local_4 - (*(uint *)(&scope_span_table + (uint)bVar1 * 4) & 0xff));
  }
  *(uint *)(PTR_DAT_00025d54 + 0x45c) = local_4;
  for (bStack_6 = 0; bStack_6 < 4; bStack_6 = bStack_6 + 1) {
    (&DAT_00009e82)[bStack_6] = (char)(local_4 >> ((3 - bStack_6 & 3) << 3));
  }
  bandmem_set(1,local_4);
  return;
}


// ===== key_call_press @ fffbc35f (47 bytes)

/* JSR key_press_table[code] */

undefined * key_call_press(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&key_press_table)[DAT_0001fa40];
}


// ===== key_call_short @ fffbc38e (47 bytes)

/* JSR key_short_table[code] */

undefined * key_call_short(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&key_short_table)[DAT_0001fa40];
}


// ===== key_call_long @ fffbc3bd (73 bytes)

/* JSR key_long_table[code] */

undefined * key_call_long(void)

{
  bool bVar1;
  char extraout_R1;
  undefined *puVar2;
  
  puVar2 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if ((extraout_R1 == '\0') &&
     (puVar2 = (undefined *)(uint)DAT_0001fa40, puVar2 != (undefined *)0x300)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return (&key_long_table)[DAT_0001fa40];
  }
  return puVar2;
}

