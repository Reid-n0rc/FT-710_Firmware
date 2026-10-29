// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== dsp_set_r12 @ fff9db97 (47 bytes)

/* reg 0x12 = 8 (once) */

void dsp_set_r12(void)

{
  if (DAT_0001b652 == 8) {
    return;
  }
  DAT_0001b6de = 0x12;
  DAT_0001b6e0 = 8;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r13 @ fff9dbc6 (49 bytes)

/* reg 0x13 = 0xFFF8 (once) */

void dsp_set_r13(void)

{
  if (DAT_0001b654 == -8) {
    return;
  }
  DAT_0001b6de = 0x13;
  DAT_0001b6e0 = 0xfff8;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_tx_gain @ fff9dbf7 (147 bytes)

/* reg 0x20: modulation gain curve value (MIC/USB/REAR gain) */

void dsp_set_tx_gain(void)

{
  bool bVar1;
  byte bVar2;
  ushort uStack_2;
  
  uStack_2 = dsp_route_param(0x20);
  bVar2 = tx_mod_gain();
  if (uStack_2 == 0xffff) {
    uStack_2 = FUN_fffb34e4(bVar2);
  }
  else if (uStack_2 == 0xfffe) {
    uStack_2 = FUN_fffb350e(DAT_00009dc2);
  }
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_2 = 0;
  }
  if (DAT_0001b656 != uStack_2) {
    DAT_0001b6de = 0x20;
    DAT_0001b6e0 = uStack_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_vox_gain @ fff9dc8a (90 bytes)

/* reg 0x21: -(VOX GAIN + curve + 29) */

void dsp_set_vox_gain(void)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = tx_mod_gain();
  sVar2 = FUN_fffb3538('d' - bVar1);
  sVar2 = ~((ushort)DAT_00009bf3 + sVar2 + 0x1d) + 1;
  if (DAT_0001b658 == sVar2) {
    return;
  }
  DAT_0001b6de = 0x21;
  DAT_0001b6e0 = sVar2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_antivox @ fff9dce4 (134 bytes)

/* reg 0x22: anti-VOX vs AF gain, 0xFF when PF5 low */

void dsp_set_antivox(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  ushort uStack_6;
  
  bVar2 = DAT_00009af3;
  bVar3 = FUN_fffb3523(DAT_00020ba8);
  bVar4 = ear_det();
  if (bVar4) {
    uStack_6 = 0xff;
  }
  else {
    bVar1 = DAT_00009bf6;
    if (bVar2 - 1 < 2) {
      bVar1 = DAT_00009bf7;
    }
    uStack_6 = (ushort)bVar1;
    uStack_6 = ~((uStack_6 - bVar3) + 0x32) + 1;
  }
  if (DAT_0001b65a != uStack_6) {
    DAT_0001b6de = 0x22;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_peq_freq @ fff9dd6a (380 bytes)

/* regs 0x25/0x28/0x2B: parametric mic EQ band frequency | 0x1000 enable */

void dsp_set_peq_freq(char param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  ushort uStack_14;
  char local_d;
  ushort uStack_c;
  ushort uStack_a;
  ushort *puStack_8;
  
  cVar2 = DAT_00009bf1;
  local_d = DAT_00009bf0;
  bVar3 = vfo_mode(0);
  if ((bVar3 - 2 < 2) || (bVar3 - 8 < 7)) {
    local_d = '\0';
  }
  bVar3 = FUN_fffb2dfe();
  if (((bVar3 == 4) || (bVar3 - 9 < 3)) && (DAT_00020b6b != '\0')) {
    local_d = '\0';
  }
  if (DAT_00020b96 != '\0') {
    local_d = '\0';
  }
  if (param_1 == '\x02') {
    bVar3 = DAT_00009ae9;
    if (cVar2 == '\0') {
      bVar3 = DAT_00009ae0;
    }
    uStack_c = (ushort)bVar3;
    if (uStack_c != 0) {
      uStack_c = uStack_c * 100 + 0x578;
    }
    puStack_8 = &DAT_0001b660;
    uStack_14 = 0x2b;
  }
  else if (param_1 == '\x01') {
    bVar3 = DAT_00009ae6;
    if (cVar2 == '\0') {
      bVar3 = DAT_00009add;
    }
    uStack_c = (ushort)bVar3;
    if (uStack_c != 0) {
      uStack_c = uStack_c * 100 + 600;
    }
    puStack_8 = &DAT_0001b65e;
    uStack_14 = 0x28;
  }
  else {
    if (param_1 != '\0') {
      return;
    }
    bVar3 = DAT_00009ae3;
    if (cVar2 == '\0') {
      bVar3 = DAT_00009ada;
    }
    uStack_c = (ushort)bVar3;
    uStack_c = uStack_c * 100;
    puStack_8 = &DAT_0001b65c;
    uStack_14 = 0x25;
  }
  uStack_a = uStack_c;
  uVar4 = dsp_route_param(uStack_14);
  if ((uVar4 == 0) || (uStack_c == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = '\0';
  }
  if (local_d != '\0') {
    uStack_a = uStack_c | 0x1000;
  }
  if (*puStack_8 == uStack_a) {
    return;
  }
  DAT_0001b6e0 = uStack_a;
  DAT_0001b6de = uStack_14;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_peq_level @ fff9dee6 (239 bytes)

/* regs 0x26/0x29/0x2C: parametric mic EQ band level (signed) */

void dsp_set_peq_level(char param_1)

{
  undefined2 local_10;
  byte local_b;
  ushort local_a;
  ushort *local_8;
  
  if (param_1 == '\x02') {
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009ae1;
    }
    else {
      local_b = DAT_00009aea;
    }
    local_8 = &DAT_0001b666;
    local_10 = 0x2c;
  }
  else if (param_1 == '\x01') {
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009ade;
    }
    else {
      local_b = DAT_00009ae7;
    }
    local_8 = &DAT_0001b664;
    local_10 = 0x29;
  }
  else {
    if (param_1 != '\0') {
      return;
    }
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009adb;
    }
    else {
      local_b = DAT_00009ae4;
    }
    local_8 = &DAT_0001b662;
    local_10 = 0x26;
  }
  if ((local_b & 0x80) == 0) {
    local_a = (ushort)local_b;
  }
  else {
    local_a = ~(ushort)(byte)(~local_b + 1) + 1;
  }
  if (*local_8 == local_a) {
    return;
  }
  DAT_0001b6de = local_10;
  DAT_0001b6e0 = local_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_peq_bw @ fff9dfd5 (216 bytes)

/* regs 0x27/0x2A/0x2D: parametric mic EQ band width */

void dsp_set_peq_bw(char param_1)

{
  undefined2 local_10;
  byte local_b;
  ushort *local_8;
  
  if (param_1 == '\x02') {
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009ae2;
    }
    else {
      local_b = DAT_00009aeb;
    }
    local_8 = &DAT_0001b66c;
    local_10 = 0x2d;
  }
  else if (param_1 == '\x01') {
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009adf;
    }
    else {
      local_b = DAT_00009ae8;
    }
    local_8 = &DAT_0001b66a;
    local_10 = 0x2a;
  }
  else {
    if (param_1 != '\0') {
      return;
    }
    if (DAT_00009bf1 == '\0') {
      local_b = DAT_00009adc;
    }
    else {
      local_b = DAT_00009ae5;
    }
    local_8 = &DAT_0001b668;
    local_10 = 0x27;
  }
  if (*local_8 == (ushort)local_b) {
    return;
  }
  DAT_0001b6de = local_10;
  DAT_0001b6e0 = (ushort)local_b;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_proc @ fff9e0ad (126 bytes)

/* reg 0x2E: speech processor level | 0x1000 (SSB only) */

void dsp_set_proc(void)

{
  bool bVar1;
  byte bVar2;
  ushort uStack_2;
  
  bVar2 = vfo_mode(1);
  if (bVar2 < 2) {
    uStack_2 = (ushort)DAT_00009bf1;
  }
  else {
    uStack_2 = 0;
  }
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_2 = 0;
  }
  if (uStack_2 != 0) {
    uStack_2 = uStack_2 | 0x1000;
  }
  if (DAT_0001b66e != uStack_2) {
    DAT_0001b6de = 0x2e;
    DAT_0001b6e0 = uStack_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_tx_bpf @ fff9e12b (244 bytes)

/* reg 0x2F: TX BPF SEL + 1 (SSB/AM/DATA) */

void dsp_set_tx_bpf(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bStack_3;
  short sStack_2;
  
  bVar3 = vfo_mode(1);
  bStack_3 = 0;
  uVar1 = (uint)bVar3;
  if (uVar1 != 0xe) {
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 == '\0') {
        bStack_3 = DAT_00009a4b;
      }
      else {
        bStack_3 = DAT_00020b64;
      }
      goto LAB_fff9e1c6;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 < 2) {
        if (DAT_00009dc6 == '\0') {
          bStack_3 = DAT_00009a36;
        }
        else {
          bStack_3 = DAT_00020b64;
        }
      }
      goto LAB_fff9e1c6;
    }
  }
  if (DAT_00009dc6 == '\0') {
    bStack_3 = DAT_00009a73;
  }
  else {
    bStack_3 = DAT_00020b64;
  }
LAB_fff9e1c6:
  sStack_2 = bStack_3 + 1;
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    sStack_2 = 0;
  }
  if (DAT_0001b670 != sStack_2) {
    DAT_0001b6de = 0x2f;
    DAT_0001b6e0 = sStack_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r30 @ fff9e21f (76 bytes)

/* reg 0x30 = 0xFF in FM modes (never cleared) */

void dsp_set_r30(void)

{
  byte bVar1;
  
  bVar1 = vfo_mode(1);
  if (((((bVar1 == 0xb) || (bVar1 == 7)) || (bVar1 == 10)) || (bVar1 == 6)) &&
     (DAT_0001b672 != 0xff)) {
    DAT_0001b6de = 0x30;
    DAT_0001b6e0 = 0xff;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r31 @ fff9e26b (197 bytes)

/* reg 0x31: per-mode constant (-43/-54/-56) */

void dsp_set_r31(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  short sStack_2;
  
  bVar3 = vfo_mode(1);
  uVar1 = (uint)bVar3;
  if (uVar1 == 0xe) {
    sStack_2 = -0x2b;
  }
  else if (uVar1 - 2 < 2) {
    sStack_2 = -0x2b;
  }
  else if (uVar1 - 4 < 2) {
    sStack_2 = -0x36;
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        sStack_2 = -0x2b;
        goto LAB_fff9e2da;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          sStack_2 = -0x2b;
        }
        else {
          if (1 < uVar1) {
            return;
          }
          sStack_2 = -0x2b;
        }
        goto LAB_fff9e2da;
      }
    }
    sStack_2 = -0x38;
  }
LAB_fff9e2da:
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    sStack_2 = -0x2b;
  }
  if (DAT_0001b674 == sStack_2) {
    return;
  }
  DAT_0001b6de = 0x31;
  DAT_0001b6e0 = sStack_2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r32 @ fff9e330 (197 bytes)

/* reg 0x32: per-mode constant (-43/-54/-56) */

void dsp_set_r32(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  short sStack_2;
  
  bVar3 = vfo_mode(1);
  uVar1 = (uint)bVar3;
  if (uVar1 == 0xe) {
    sStack_2 = -0x2b;
  }
  else if (uVar1 - 2 < 2) {
    sStack_2 = -0x2b;
  }
  else if (uVar1 - 4 < 2) {
    sStack_2 = -0x36;
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        sStack_2 = -0x2b;
        goto LAB_fff9e39f;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          sStack_2 = -0x2b;
        }
        else {
          if (1 < uVar1) {
            return;
          }
          sStack_2 = -0x2b;
        }
        goto LAB_fff9e39f;
      }
    }
    sStack_2 = -0x38;
  }
LAB_fff9e39f:
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    sStack_2 = -0x2b;
  }
  if (DAT_0001b676 == sStack_2) {
    return;
  }
  DAT_0001b6de = 0x32;
  DAT_0001b6e0 = sStack_2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_amc_release @ fff9e3f5 (139 bytes)

/* reg 0x33: AMC RELEASE TIME 0x11/0x12/0x13, FM 0x0C */

void dsp_set_amc_release(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  short local_2;
  
  if (DAT_00009ad9 == '\x01') {
    local_2 = 0x12;
  }
  else if (DAT_00009ad9 == '\0') {
    local_2 = 0x11;
  }
  else {
    local_2 = 0x13;
  }
  bVar3 = vfo_mode(1);
  uVar1 = (uint)bVar3;
  if ((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) {
    local_2 = 0xc;
  }
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_2 = 0x11;
  }
  if (DAT_0001b678 != local_2) {
    DAT_0001b6de = 0x33;
    DAT_0001b6e0 = local_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_amc_level @ fff9e480 (156 bytes)

/* reg 0x34: AMC OUTPUT LEVEL | 0x1000 */

void dsp_set_amc_level(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  ushort uStack_2;
  
  bVar3 = vfo_mode(1);
  uVar1 = (uint)bVar3;
  if (1 < uVar1 - 2) {
    if ((uVar1 - 6 < 2) || (uVar1 - 10 < 2)) {
      uStack_2 = 100;
      goto LAB_fff9e4bd;
    }
    if (uVar1 != 0xc && uVar1 != 0xd) {
      uStack_2 = (ushort)DAT_00009bf2;
      goto LAB_fff9e4bd;
    }
  }
  uStack_2 = 0;
LAB_fff9e4bd:
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uStack_2 = 0;
  }
  if (uStack_2 != 0) {
    uStack_2 = uStack_2 | 0x1000;
  }
  if (DAT_0001b67a != uStack_2) {
    DAT_0001b6de = 0x34;
    DAT_0001b6e0 = uStack_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_ctcss_enc @ fff9e51c (152 bytes)

/* reg 0x35: TX tone index+1 | 0x1000 (FM, tone on) */

void dsp_set_ctcss_enc(void)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  byte *pbVar5;
  ushort uStack_6;
  
  pbVar5 = vfo_rec_ptr(1);
  bVar1 = pbVar5[3];
  bVar4 = vfo_mode(1);
  uStack_6 = 0;
  if (((char)((bVar1 & 0x38) >> 3) != '\0') &&
     ((uVar2 = (uint)bVar4, uVar2 - 6 < 2 || (uVar2 == 10 || uVar2 == 0xb)))) {
    uStack_6 = pbVar5[0x46] + 1 | 0x1000;
  }
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    uStack_6 = 0;
  }
  if (DAT_0001b67c != uStack_6) {
    DAT_0001b6de = 0x35;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r36 @ fff9e5b4 (48 bytes)

/* reg 0x36 = 0 (once) */

void dsp_set_r36(void)

{
  if (DAT_0001b67e == 0) {
    return;
  }
  DAT_0001b6de = 0x36;
  DAT_0001b6e0 = 0;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r37 @ fff9e5e4 (48 bytes)

/* reg 0x37 = 0 (once) */

void dsp_set_r37(void)

{
  if (DAT_0001b680 == 0) {
    return;
  }
  DAT_0001b6de = 0x37;
  DAT_0001b6e0 = 0;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r38 @ fff9e614 (48 bytes)

/* reg 0x38 = 0 (once) */

void dsp_set_r38(void)

{
  if (DAT_0001b682 == 0) {
    return;
  }
  DAT_0001b6de = 0x38;
  DAT_0001b6e0 = 0;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_fm_flag @ fff9e644 (117 bytes)

/* reg 0x3A: 1 in FM modes */

void dsp_set_fm_flag(byte param_1)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  short local_4;
  
  local_4 = 0;
  bVar3 = vfo_mode(param_1);
  uVar1 = (uint)bVar3;
  if ((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) {
    local_4 = 1;
  }
  if ((DAT_00020baf == '\x01') && (DAT_00020f01 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_4 = 0;
  }
  if (DAT_0001b684 != local_4) {
    DAT_0001b6de = 0x3a;
    DAT_0001b6e0 = local_4;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r3b @ fff9e6b9 (151 bytes)

/* reg 0x3B: per-mode constant (-39/-50/-52) */

void dsp_set_r3b(void)

{
  uint uVar1;
  byte bVar2;
  short sStack_2;
  
  bVar2 = vfo_mode(1);
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
    sStack_2 = -0x27;
  }
  else if (uVar1 - 2 < 2) {
    sStack_2 = -0x27;
  }
  else if (uVar1 - 4 < 2) {
    sStack_2 = -0x32;
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        sStack_2 = -0x27;
        goto LAB_fff9e725;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          sStack_2 = -0x27;
        }
        else {
          if (1 < uVar1) {
            return;
          }
          sStack_2 = -0x27;
        }
        goto LAB_fff9e725;
      }
    }
    sStack_2 = -0x34;
  }
LAB_fff9e725:
  if (DAT_0001b686 == sStack_2) {
    return;
  }
  DAT_0001b6de = 0x3b;
  DAT_0001b6e0 = sStack_2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_r40 @ fff9e750 (116 bytes)

/* reg 0x40: DNR table (levels 8-15 -> 1) */

void dsp_set_dnr_r40(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((bVar1 & 0x10) == 0) {
    sStack_a = 0;
  }
  else if ((1 < bVar2 - 6) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87fba + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b688 != sStack_a) {
    DAT_0001b6de = 0x40;
    DAT_0001b6e0 = sStack_a;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_dnf @ fff9e7c4 (173 bytes)

/* reg 0x41: auto notch (BC) on/off */

void dsp_set_dnf(byte param_1)

{
  uint uVar1;
  byte bVar2;
  byte *pbVar3;
  byte bStack_b;
  ushort uStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar2 = vfo_mode(param_1);
  bStack_b = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      bStack_b = pbVar3[0x15] & 0x80;
      goto LAB_fff9e83e;
    }
    if (uVar1 - 4 < 2) {
      bStack_b = pbVar3[0x33] & 0x80;
      goto LAB_fff9e83e;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        bStack_b = pbVar3[0x1f] & 0x80;
      }
      else if (uVar1 < 2) {
        bStack_b = pbVar3[0xb] & 0x80;
      }
      goto LAB_fff9e83e;
    }
  }
  bStack_b = pbVar3[0x29] & 0x80;
LAB_fff9e83e:
  uStack_a = (ushort)(bStack_b != 0);
  if (DAT_0001b68a == uStack_a) {
    return;
  }
  DAT_0001b6de = 0x41;
  DAT_0001b6e0 = uStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_contour @ fff9e871 (307 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9e935) */
/* WARNING: Removing unreachable block (ram,0xfff9e8cd) */
/* WARNING: Removing unreachable block (ram,0xfff9e959) */
/* WARNING: Removing unreachable block (ram,0xfff9e911) */
/* WARNING: Removing unreachable block (ram,0xfff9e8ef) */
/* reg 0x42: contour freq | 0x1000 on */

void dsp_set_contour(byte param_1)

{
  uint uVar1;
  byte bVar2;
  byte *pbVar3;
  byte bStack_d;
  short sStack_c;
  ushort uStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar2 = vfo_mode(param_1);
  sStack_c = 0;
  bStack_d = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      bStack_d = pbVar3[0x14] & 0x40;
      sStack_c = CONCAT11(pbVar3[0x16],pbVar3[0x17]);
      goto LAB_fff9e968;
    }
    if (uVar1 - 4 < 2) {
      bStack_d = pbVar3[0x32] & 0x40;
      sStack_c = CONCAT11(pbVar3[0x34],pbVar3[0x35]);
      goto LAB_fff9e968;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        bStack_d = pbVar3[0x1e] & 0x40;
        sStack_c = CONCAT11(pbVar3[0x20],pbVar3[0x21]);
      }
      else if (uVar1 < 2) {
        bStack_d = pbVar3[10] & 0x40;
        sStack_c = CONCAT11(pbVar3[0xc],pbVar3[0xd]);
      }
      goto LAB_fff9e968;
    }
  }
  bStack_d = pbVar3[0x28] & 0x40;
  sStack_c = CONCAT11(pbVar3[0x2a],pbVar3[0x2b]);
LAB_fff9e968:
  uStack_a = sStack_c * 10;
  if (bStack_d != 0) {
    uStack_a = uStack_a | 0x1000;
  }
  if (DAT_0001b68c == uStack_a) {
    return;
  }
  DAT_0001b6de = 0x42;
  DAT_0001b6e0 = uStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_contour_level @ fff9e9a4 (86 bytes)

/* reg 0x43: CONTOUR LEVEL (signed) */

void dsp_set_contour_level(void)

{
  undefined2 local_2;
  
  if ((DAT_00009ad5 & 0x80) == 0) {
    local_2 = (ushort)DAT_00009ad5;
  }
  else {
    local_2 = ~(ushort)(byte)(~DAT_00009ad5 + 1) + 1;
  }
  if (DAT_0001b68e == local_2) {
    return;
  }
  DAT_0001b6de = 0x43;
  DAT_0001b6e0 = local_2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_contour_width @ fff9e9fa (63 bytes)

/* reg 0x44: 11 - CONTOUR WIDTH */

void dsp_set_contour_width(void)

{
  if (DAT_0001b690 == (ushort)(0xb - (ushort)DAT_00009ad6)) {
    return;
  }
  DAT_0001b6de = 0x44;
  DAT_0001b6e0 = 0xb - (ushort)DAT_00009ad6;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_apf @ fff9ea39 (174 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9eab4) */
/* reg 0x45: APF centre (pitch + APF offset) | width<<12 when APF on */

void dsp_set_apf(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte bStack_b;
  ushort uStack_a;
  
  pbVar5 = vfo_rec_ptr(param_1);
  bVar3 = DAT_00009c5f;
  bVar2 = DAT_00009c04;
  bVar1 = DAT_00009ad4;
  bVar4 = vfo_mode(param_1);
  if ((bVar3 & 0x80) == 0) {
    uStack_a = (ushort)bVar3;
  }
  else {
    uStack_a = -(ushort)(byte)(~bVar3 + 1);
  }
  uStack_a = uStack_a + bVar2 + 0x1e;
  uStack_a = uStack_a * 10;
  bStack_b = 0;
  if (bVar4 == 2 || bVar4 == 3) {
    bStack_b = pbVar5[0x14] & 0x20;
  }
  if (bStack_b != 0) {
    uStack_a = (bVar1 + 2) * 0x1000 | uStack_a;
  }
  if (DAT_0001b692 != uStack_a) {
    DAT_0001b6de = 0x45;
    DAT_0001b6e0 = uStack_a;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_hcut @ fff9eae7 (551 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ecdb) */
/* reg 0x46: HCUT freq (700+50(n-1)) | slope<<12 */

void dsp_set_hcut(void)

{
  uint uVar1;
  byte bVar2;
  byte bStack_8;
  byte bStack_7;
  ushort uStack_6;
  
  vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_6 = 0;
  bStack_8 = '\0';
  bStack_7 = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fff9ec7c:
    if (DAT_00009dc6 == '\0') {
      bStack_7 = DAT_00009a6f;
      bStack_8 = DAT_00009a70;
    }
    else {
      bStack_7 = DAT_00020b60;
      bStack_8 = DAT_00020b61;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (DAT_00009dc6 == '\0') {
        bStack_7 = DAT_00009a99;
        bStack_8 = DAT_00009a9a;
      }
      else {
        bStack_7 = DAT_00020b60;
        bStack_8 = DAT_00020b61;
      }
      goto LAB_fff9ecb6;
    }
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 == '\0') {
        bStack_7 = DAT_00009a47;
        bStack_8 = DAT_00009a48;
      }
      else {
        bStack_7 = DAT_00020b60;
        bStack_8 = DAT_00020b61;
      }
      goto LAB_fff9ecb6;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff9ec7c;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_7 = DAT_00009a86;
            bStack_8 = DAT_00009a87;
          }
          else {
            bStack_7 = DAT_00020b60;
            bStack_8 = DAT_00020b61;
          }
        }
        else if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_7 = DAT_00009a32;
            bStack_8 = DAT_00009a33;
          }
          else {
            bStack_7 = DAT_00020b60;
            bStack_8 = DAT_00020b61;
          }
        }
        goto LAB_fff9ecb6;
      }
    }
    if (DAT_00009dc6 == '\0') {
      bStack_7 = DAT_00009a5a;
      bStack_8 = DAT_00009a5b;
    }
    else {
      bStack_7 = DAT_00020b60;
      bStack_8 = DAT_00020b61;
    }
  }
LAB_fff9ecb6:
  if (bStack_7 == 0) {
    bStack_8 = 0;
  }
  else {
    bStack_8 = bStack_8 + 1;
    uStack_6 = (bStack_7 - 1) * 0x32 + 700;
  }
  uStack_6 = (ushort)bStack_8 << 0xc | uStack_6;
  if (DAT_0001b694 == uStack_6) {
    return;
  }
  DAT_0001b6de = 0x46;
  DAT_0001b6e0 = uStack_6;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_lcut @ fff9ed0e (550 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ef01) */
/* reg 0x47: LCUT freq (100+50(n-1)) | slope<<12 */

void dsp_set_lcut(void)

{
  uint uVar1;
  byte bVar2;
  byte bStack_8;
  byte bStack_7;
  ushort uStack_6;
  
  vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_6 = 0;
  bStack_8 = '\0';
  bStack_7 = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fff9eea3:
    if (DAT_00009dc6 == '\0') {
      bStack_7 = DAT_00009a6d;
      bStack_8 = DAT_00009a6e;
    }
    else {
      bStack_7 = DAT_00020b5e;
      bStack_8 = DAT_00020b5f;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (DAT_00009dc6 == '\0') {
        bStack_7 = DAT_00009a97;
        bStack_8 = DAT_00009a98;
      }
      else {
        bStack_7 = DAT_00020b5e;
        bStack_8 = DAT_00020b5f;
      }
      goto LAB_fff9eedd;
    }
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 == '\0') {
        bStack_7 = DAT_00009a45;
        bStack_8 = DAT_00009a46;
      }
      else {
        bStack_7 = DAT_00020b5e;
        bStack_8 = DAT_00020b5f;
      }
      goto LAB_fff9eedd;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff9eea3;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_7 = DAT_00009a84;
            bStack_8 = DAT_00009a85;
          }
          else {
            bStack_7 = DAT_00020b5e;
            bStack_8 = DAT_00020b5f;
          }
        }
        else if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_7 = DAT_00009a30;
            bStack_8 = DAT_00009a31;
          }
          else {
            bStack_7 = DAT_00020b5e;
            bStack_8 = DAT_00020b5f;
          }
        }
        goto LAB_fff9eedd;
      }
    }
    if (DAT_00009dc6 == '\0') {
      bStack_7 = DAT_00009a58;
      bStack_8 = DAT_00009a59;
    }
    else {
      bStack_7 = DAT_00020b5e;
      bStack_8 = DAT_00020b5f;
    }
  }
LAB_fff9eedd:
  if (bStack_7 == 0) {
    bStack_8 = 0;
  }
  else {
    bStack_8 = bStack_8 + 1;
    uStack_6 = (bStack_7 - 1) * 0x32 + 100;
  }
  uStack_6 = (ushort)bStack_8 << 0xc | uStack_6;
  if (DAT_0001b696 == uStack_6) {
    return;
  }
  DAT_0001b6de = 0x47;
  DAT_0001b6e0 = uStack_6;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_tone_freq @ fff9ef34 (381 bytes)

/* regs 0x48/0x4B/0x4E: AF tone band frequency 200/400/1200 Hz | 0x1000 */

void dsp_set_tone_freq(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined2 uStack_10;
  byte bStack_b;
  ushort uStack_a;
  ushort *puStack_8;
  
  bVar2 = vfo_mode(0);
  bStack_b = 0;
  if (param_1 != '\0') {
    if (param_1 == '\x01') {
      puStack_8 = &DAT_0001b69a;
      uStack_10 = 0x4b;
      uVar1 = (uint)bVar2;
      if (uVar1 == 0xe) {
LAB_fff9f017:
        bStack_b = 4;
      }
      else {
        if (uVar1 - 2 < 2) {
          bStack_b = 4;
          goto LAB_fff9f078;
        }
        if (uVar1 - 4 < 2) {
          bStack_b = 4;
          goto LAB_fff9f078;
        }
        if (1 < uVar1 - 6) {
          if (uVar1 - 8 < 2) goto LAB_fff9f017;
          if (1 < uVar1 - 10) {
            if (uVar1 - 0xc < 2) {
              bStack_b = 4;
            }
            else if (uVar1 < 2) {
              bStack_b = 4;
            }
            goto LAB_fff9f078;
          }
        }
        bStack_b = 4;
      }
      goto LAB_fff9f078;
    }
    puStack_8 = &DAT_0001b69c;
    uStack_10 = 0x4e;
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
LAB_fff9f075:
      bStack_b = 0xc;
    }
    else {
      if (uVar1 - 2 < 2) {
        bStack_b = 0xc;
        goto LAB_fff9f078;
      }
      if (uVar1 - 4 < 2) {
        bStack_b = 0xc;
        goto LAB_fff9f078;
      }
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) goto LAB_fff9f075;
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            bStack_b = 0xc;
          }
          else if (uVar1 < 2) {
            bStack_b = 0xc;
          }
          goto LAB_fff9f078;
        }
      }
      bStack_b = 0xc;
    }
    goto LAB_fff9f078;
  }
  puStack_8 = &DAT_0001b698;
  uStack_10 = 0x48;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fff9efb0:
    bStack_b = 2;
  }
  else {
    if (uVar1 - 2 < 2) {
      bStack_b = 2;
      goto LAB_fff9f078;
    }
    if (uVar1 - 4 < 2) {
      bStack_b = 2;
      goto LAB_fff9f078;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff9efb0;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          bStack_b = 2;
        }
        else if (uVar1 < 2) {
          bStack_b = 2;
        }
        goto LAB_fff9f078;
      }
    }
    bStack_b = 2;
  }
LAB_fff9f078:
  if ((ushort)((ushort)bStack_b * 100) == 0) {
    uStack_a = 0;
  }
  else {
    uStack_a = (ushort)bStack_b * 100 | 0x1000;
  }
  if (*puStack_8 != uStack_a) {
    DAT_0001b6de = uStack_10;
    DAT_0001b6e0 = uStack_a;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_tone_gain @ fff9f0b1 (480 bytes)

/* regs 0x49/0x4C/0x4F: AF BASS/MIDDLE/TREBLE GAIN (signed) */

void dsp_set_tone_gain(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined2 uStack_14;
  byte bStack_f;
  ushort uStack_e;
  ushort *puStack_c;
  
  bVar2 = vfo_mode(0);
  bStack_f = 0;
  if (param_1 != '\0') {
    if (param_1 == '\x01') {
      puStack_c = &DAT_0001b6a0;
      uStack_14 = 0x4c;
      uVar1 = (uint)bVar2;
      if (uVar1 == 0xe) {
LAB_fff9f1d4:
        bStack_f = DAT_00009a68;
      }
      else {
        if (uVar1 - 2 < 2) {
          bStack_f = DAT_00009a92;
          goto LAB_fff9f24f;
        }
        if (uVar1 - 4 < 2) {
          bStack_f = DAT_00009a40;
          goto LAB_fff9f24f;
        }
        if (1 < uVar1 - 6) {
          if (uVar1 - 8 < 2) goto LAB_fff9f1d4;
          if (1 < uVar1 - 10) {
            if (uVar1 - 0xc < 2) {
              bStack_f = DAT_00009a7f;
            }
            else if (uVar1 < 2) {
              bStack_f = DAT_00009a2b;
            }
            goto LAB_fff9f24f;
          }
        }
        bStack_f = DAT_00009a53;
      }
      goto LAB_fff9f24f;
    }
    puStack_c = &DAT_0001b6a2;
    uStack_14 = 0x4f;
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
LAB_fff9f249:
      bStack_f = DAT_00009a67;
    }
    else {
      if (uVar1 - 2 < 2) {
        bStack_f = DAT_00009a91;
        goto LAB_fff9f24f;
      }
      if (uVar1 - 4 < 2) {
        bStack_f = DAT_00009a3f;
        goto LAB_fff9f24f;
      }
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) goto LAB_fff9f249;
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            bStack_f = DAT_00009a7e;
          }
          else if (uVar1 < 2) {
            bStack_f = DAT_00009a2a;
          }
          goto LAB_fff9f24f;
        }
      }
      bStack_f = DAT_00009a52;
    }
    goto LAB_fff9f24f;
  }
  puStack_c = &DAT_0001b69e;
  uStack_14 = 0x49;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fff9f14e:
    bStack_f = DAT_00009a69;
  }
  else {
    if (uVar1 - 2 < 2) {
      bStack_f = DAT_00009a93;
      goto LAB_fff9f24f;
    }
    if (uVar1 - 4 < 2) {
      bStack_f = DAT_00009a41;
      goto LAB_fff9f24f;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff9f14e;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          bStack_f = DAT_00009a80;
        }
        else if (uVar1 < 2) {
          bStack_f = DAT_00009a2c;
        }
        goto LAB_fff9f24f;
      }
    }
    bStack_f = DAT_00009a54;
  }
LAB_fff9f24f:
  if ((bStack_f & 0x80) == 0) {
    uStack_e = (ushort)bStack_f;
  }
  else {
    uStack_e = ~(ushort)(byte)(~bStack_f + 1) + 1;
  }
  if (*puStack_c != uStack_e) {
    DAT_0001b6de = uStack_14;
    DAT_0001b6e0 = uStack_e;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_tone_type @ fff9f291 (367 bytes)

/* regs 0x4A/0x4D/0x50: AF tone band type 2/1/1 */

void dsp_set_tone_type(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined2 uStack_10;
  byte bStack_b;
  ushort *puStack_8;
  
  bVar2 = vfo_mode(0);
  bStack_b = 0;
  if (param_1 != '\0') {
    if (param_1 == '\x01') {
      puStack_8 = &DAT_0001b6a6;
      uStack_10 = 0x4d;
      uVar1 = (uint)bVar2;
      if (uVar1 == 0xe) {
LAB_fff9f374:
        bStack_b = 1;
      }
      else {
        if (uVar1 - 2 < 2) {
          bStack_b = 1;
          goto LAB_fff9f3d5;
        }
        if (uVar1 - 4 < 2) {
          bStack_b = 1;
          goto LAB_fff9f3d5;
        }
        if (1 < uVar1 - 6) {
          if (uVar1 - 8 < 2) goto LAB_fff9f374;
          if (1 < uVar1 - 10) {
            if (uVar1 - 0xc < 2) {
              bStack_b = 1;
            }
            else if (uVar1 < 2) {
              bStack_b = 1;
            }
            goto LAB_fff9f3d5;
          }
        }
        bStack_b = 1;
      }
      goto LAB_fff9f3d5;
    }
    puStack_8 = &DAT_0001b6a8;
    uStack_10 = 0x50;
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
LAB_fff9f3d2:
      bStack_b = 1;
    }
    else {
      if (uVar1 - 2 < 2) {
        bStack_b = 1;
        goto LAB_fff9f3d5;
      }
      if (uVar1 - 4 < 2) {
        bStack_b = 1;
        goto LAB_fff9f3d5;
      }
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) goto LAB_fff9f3d2;
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            bStack_b = 1;
          }
          else if (uVar1 < 2) {
            bStack_b = 1;
          }
          goto LAB_fff9f3d5;
        }
      }
      bStack_b = 1;
    }
    goto LAB_fff9f3d5;
  }
  puStack_8 = &DAT_0001b6a4;
  uStack_10 = 0x4a;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fff9f30d:
    bStack_b = 2;
  }
  else {
    if (uVar1 - 2 < 2) {
      bStack_b = 2;
      goto LAB_fff9f3d5;
    }
    if (uVar1 - 4 < 2) {
      bStack_b = 2;
      goto LAB_fff9f3d5;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff9f30d;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          bStack_b = 2;
        }
        else if (uVar1 < 2) {
          bStack_b = 2;
        }
        goto LAB_fff9f3d5;
      }
    }
    bStack_b = 2;
  }
LAB_fff9f3d5:
  if (*puStack_8 != (ushort)bStack_b) {
    DAT_0001b6de = uStack_10;
    DAT_0001b6e0 = (ushort)bStack_b;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r51 @ fff9f400 (48 bytes)

/* reg 0x51 = 0 (once) */

void dsp_set_r51(void)

{
  if (DAT_0001b6aa == 0) {
    return;
  }
  DAT_0001b6de = 0x51;
  DAT_0001b6e0 = 0;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_am_notch @ fff9f430 (152 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9f46e) */
/* reg 0x52: manual notch freq | width<<12 (AM only) */

void dsp_set_am_notch(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bStack_7;
  ushort uStack_6;
  
  pbVar2 = vfo_rec_ptr(0);
  bVar1 = vfo_mode(0);
  uStack_6 = 0;
  bStack_7 = 0;
  if (bVar1 == 4 || bVar1 == 5) {
    bStack_7 = pbVar2[0x32] & 0x80;
    uStack_6 = CONCAT11(pbVar2[0x36],pbVar2[0x37]);
  }
  if (bStack_7 == 0) {
    uStack_6 = 0;
  }
  else if (DAT_00009ad1 == '\0') {
    uStack_6 = uStack_6 * 10 | 0x1000;
  }
  else {
    uStack_6 = uStack_6 * 10 | 0x2000;
  }
  if (DAT_0001b6ac != uStack_6) {
    DAT_0001b6de = 0x52;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_ctcss_dec @ fff9f4c8 (131 bytes)

/* reg 0x53: RX tone index+1 | 0x1000 (FM, tone on); sets 0x20B72 */

void dsp_set_ctcss_dec(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  ushort uStack_6;
  
  pbVar4 = vfo_rec_ptr(0);
  cVar2 = (char)((pbVar4[3] & 0x38) >> 3);
  bVar3 = vfo_mode(0);
  DAT_00020b72 = '\0';
  uStack_6 = 0;
  if ((cVar2 != '\0') && ((uVar1 = (uint)bVar3, uVar1 - 6 < 2 || (uVar1 == 10 || uVar1 == 0xb)))) {
    uStack_6 = pbVar4[0x46] + 1 | 0x1000;
    DAT_00020b72 = cVar2;
  }
  if (DAT_0001b6ae != uStack_6) {
    DAT_0001b6de = 0x53;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r56 @ fff9f54b (48 bytes)

/* reg 0x56 = 0x20 */

void dsp_set_r56(void)

{
  if (DAT_0001b6b4 == 0x20) {
    return;
  }
  DAT_0001b6de = 0x56;
  DAT_0001b6e0 = 0x20;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_affft_att @ fff9f57b (75 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9f593) */
/* reg 0x5C: AF-FFT attenuator (SS07 P3) <<8 | 0x1000 */

void dsp_set_affft_att(void)

{
  ushort uVar1;
  
  uVar1 = (ushort)DAT_00009c39 << 8 | 0x1000;
  if (DAT_0001b6ba != uVar1) {
    DAT_0001b6de = 0x5c;
    DAT_0001b6e0 = uVar1;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_osc @ fff9f5c6 (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9f5fe) */
/* reg 0x5D: oscilloscope level (RX/TX) <<8 | 0x1000 | time */

void dsp_set_osc(char param_1)

{
  ushort uVar1;
  undefined1 local_5;
  
  if (param_1 == '\0') {
    local_5 = DAT_00009c3b;
  }
  else {
    local_5 = DAT_00009c3a;
  }
  uVar1 = (ushort)local_5 << 8 | 0x1000 | (ushort)DAT_00009c3c;
  if (DAT_0001b6bc != uVar1) {
    DAT_0001b6de = 0x5d;
    DAT_0001b6e0 = uVar1;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_cw_pitch @ fff9f638 (73 bytes)

/* reg 0x61: (KEY PITCH + 30)*10 | 0x1000 */

void dsp_set_cw_pitch(void)

{
  ushort uVar1;
  
  uVar1 = (DAT_00009c04 + 0x1e) * 10 | 0x1000;
  if (DAT_0001b6c0 == uVar1) {
    return;
  }
  DAT_0001b6de = 0x61;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_agc @ fff9f681 (1261 bytes)

/* reg 0x62 AGC on, reg 0x66 AGC delay (20n+20 ms; scan 200/40/4) */

void dsp_set_agc(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  byte bStack_9;
  byte bStack_7;
  ushort uStack_6;
  
  pbVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  bStack_9 = 0;
  uVar5 = (uint)bVar2;
  if (uVar5 != 0xe) {
    if (uVar5 - 2 < 2) {
      bStack_7 = pbVar4[0x15];
      if ((bStack_7 & 0x40) != 0) {
        uVar5 = (bStack_7 & 0x30) >> 4;
        if (uVar5 == 3) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a96;
          }
          else {
            bStack_9 = DAT_00020b5d;
          }
        }
        else if (uVar5 == 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a95;
          }
          else {
            bStack_9 = DAT_00020b5c;
          }
        }
        else if (uVar5 < 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a94;
          }
          else {
            bStack_9 = DAT_00020b5b;
          }
        }
      }
      goto LAB_fff9fa98;
    }
    if (uVar5 - 4 < 2) {
      bStack_7 = pbVar4[0x33];
      if ((bStack_7 & 0x40) != 0) {
        uVar5 = (bStack_7 & 0x30) >> 4;
        if ((uVar5 == 0) || (uVar5 == 3)) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a44;
          }
          else {
            bStack_9 = DAT_00020b5d;
          }
        }
        else if (uVar5 == 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a43;
          }
          else {
            bStack_9 = DAT_00020b5c;
          }
        }
        else if (uVar5 == 1) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a42;
          }
          else {
            bStack_9 = DAT_00020b5b;
          }
        }
      }
      goto LAB_fff9fa98;
    }
    if (1 < uVar5 - 8) {
      if (uVar5 - 0xc < 2) {
        bStack_7 = pbVar4[0x1f];
        if ((bStack_7 & 0x40) != 0) {
          uVar5 = (bStack_7 & 0x30) >> 4;
          if (uVar5 != 0) {
            if (uVar5 == 3) {
              if (DAT_00009dc6 == '\0') {
                bStack_9 = DAT_00009a83;
              }
              else {
                bStack_9 = DAT_00020b5d;
              }
              goto LAB_fff9fa98;
            }
            if (uVar5 != 2) {
              if (uVar5 == 1) {
                if (DAT_00009dc6 == '\0') {
                  bStack_9 = DAT_00009a81;
                }
                else {
                  bStack_9 = DAT_00020b5b;
                }
              }
              goto LAB_fff9fa98;
            }
          }
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a82;
          }
          else {
            bStack_9 = DAT_00020b5c;
          }
        }
      }
      else if (uVar5 < 2) {
        bStack_7 = pbVar4[0xb];
        if ((bStack_7 & 0x40) != 0) {
          uVar5 = (bStack_7 & 0x30) >> 4;
          if ((uVar5 == 0) || (uVar5 == 3)) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a2f;
            }
            else {
              bStack_9 = DAT_00020b5d;
            }
          }
          else if (uVar5 == 2) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a2e;
            }
            else {
              bStack_9 = DAT_00020b5c;
            }
          }
          else if (uVar5 == 1) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a2d;
            }
            else {
              bStack_9 = DAT_00020b5b;
            }
          }
        }
      }
      else {
        bStack_7 = pbVar4[0x3d];
        if ((bStack_7 & 0x40) != 0) {
          uVar5 = (bStack_7 & 0x30) >> 4;
          if (uVar5 == 3) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a57;
            }
            else {
              bStack_9 = DAT_00020b5d;
            }
          }
          else if (uVar5 == 2) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a56;
            }
            else {
              bStack_9 = DAT_00020b5c;
            }
          }
          else if (uVar5 < 2) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a55;
            }
            else {
              bStack_9 = DAT_00020b5b;
            }
          }
        }
      }
      goto LAB_fff9fa98;
    }
  }
  bStack_7 = pbVar4[0x29];
  if ((bStack_7 & 0x40) == 0) goto LAB_fff9fa98;
  uVar5 = (bStack_7 & 0x30) >> 4;
  if (uVar5 != 0) {
    if (uVar5 == 3) {
      if (DAT_00009dc6 == '\0') {
        bStack_9 = DAT_00009a6c;
      }
      else {
        bStack_9 = DAT_00020b5d;
      }
      goto LAB_fff9fa98;
    }
    if (uVar5 != 2) {
      if (uVar5 == 1) {
        if (DAT_00009dc6 == '\0') {
          bStack_9 = DAT_00009a6a;
        }
        else {
          bStack_9 = DAT_00020b5b;
        }
      }
      goto LAB_fff9fa98;
    }
  }
  if (DAT_00009dc6 == '\0') {
    bStack_9 = DAT_00009a6b;
  }
  else {
    bStack_9 = DAT_00020b5c;
  }
LAB_fff9fa98:
  uStack_6 = (ushort)((bStack_7 & 0x40) != 0);
  bVar3 = swtimer_expired(0x2a);
  if (bVar3 == 0) {
    uStack_6 = 1;
  }
  if (DAT_0001b6c2 != uStack_6) {
    DAT_0001b6de = 0x62;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame('w');
    return;
  }
  bVar3 = swtimer_expired(0x2a);
  if (bVar3 == 0) {
    bStack_9 = 0;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f6f == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bVar3 = vfo_is_memory(DAT_00009dbd);
    if (bVar3 == 1) {
      uStack_6 = 200;
    }
    else {
      uVar5 = (uint)bVar2;
      if ((uVar5 - 4 < 4) || (uVar5 == 10 || uVar5 == 0xb)) {
        uStack_6 = 0x28;
      }
      else {
        uStack_6 = 4;
      }
    }
  }
  else {
    uStack_6 = (ushort)bStack_9 * 0x14 + 0x14;
  }
  if (DAT_0001b6ca == uStack_6) {
    return;
  }
  DAT_0001b6de = 0x66;
  DAT_0001b6e0 = uStack_6;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_freq_range_param @ fff9fb6e (188 bytes)

/* SCI4 reg 99 = cfg105 byte chosen by frequency range (0xFFF88598) */

void dsp_set_freq_range_param(void)

{
  uint uVar1;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  
  vfo_mode(0);
  uVar1 = vfo_freq(0,2);
  bStack_8 = 0;
  bStack_7 = 0;
  do {
    if (4 < bStack_7) {
LAB_fff9fba9:
      if (bStack_8 == 3) {
        bStack_9 = DAT_00004677;
      }
      else if (bStack_8 == 1) {
        bStack_9 = DAT_00004675;
      }
      else if (bStack_8 == 2) {
        bStack_9 = DAT_00004676;
      }
      else if (bStack_8 == 0) {
        bStack_9 = DAT_00004674;
      }
      else {
        bStack_9 = DAT_00004678;
      }
      if (DAT_0001b6c4 == bStack_9) {
        return;
      }
      DAT_0001b6de = 99;
      DAT_0001b6e0 = (ushort)bStack_9;
      dsp_send_frame('w');
      return;
    }
    if (uVar1 <= *(uint *)(dsp_freq_ranges + (uint)bStack_7 * 4)) {
      bStack_8 = bStack_7;
      goto LAB_fff9fba9;
    }
    bStack_7 = bStack_7 + 1;
  } while( true );
}


// ===== dsp_set_rf_gain @ fff9fc2a (118 bytes)

/* reg 0x67: RF gain curve (0xFF when knob is SQL) */

void dsp_set_rf_gain(void)

{
  byte bVar1;
  ushort local_2;
  uint uVar2;
  
  local_2 = (ushort)BYTE_ARRAY_fff805ac[DAT_00020ba7 >> 2];
  if (DAT_00009ab6 == '\x01') {
    local_2 = 0xff;
  }
  else if (DAT_00009ab6 == '\x02') {
    bVar1 = vfo_mode(0);
    uVar2 = (uint)bVar1;
    if ((uVar2 - 6 < 2) || (uVar2 == 10 || uVar2 == 0xb)) {
      local_2 = 0xff;
    }
  }
  if (DAT_0001b6cc != local_2) {
    DAT_0001b6de = 0x67;
    DAT_0001b6e0 = local_2;
    dsp_send_frame('w');
    return;
  }
  return;
}


// ===== dsp_set_r68 @ fff9fca0 (48 bytes)

/* reg 0x68 = 0x94 (once) */

void dsp_set_r68(void)

{
  if (DAT_0001b6ce == 0x94) {
    return;
  }
  DAT_0001b6de = 0x68;
  DAT_0001b6e0 = 0x94;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_400b @ fff9fcd0 (129 bytes)

/* reg 0x400B: DNR table by level */

void dsp_set_dnr_400b(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87f1a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6d0 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x400b;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_400d @ fff9fd51 (129 bytes)

/* reg 0x400D: DNR table by level */

void dsp_set_dnr_400d(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87f39 + (uint)(bVar1 & 0xf) * 2 + 1);
  }
  if (DAT_0001b6d2 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x400d;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_aess @ fff9fdd2 (88 bytes)

/* reg 0x4020: 0 / 0x2000|700 / 0x2000|1000 (AESS on, centre) */

void dsp_set_aess(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 uStack_2;
  
  pcVar1 = (char *)FUN_fffb54a0();
  pcVar2 = (char *)FUN_fffb552c();
  if (*pcVar1 == '\0') {
    uStack_2 = 0;
  }
  else if (*pcVar2 == '\0') {
    uStack_2 = 0x22bc;
  }
  else {
    uStack_2 = 0x23e8;
  }
  if (DAT_0001b6d4 == uStack_2) {
    return;
  }
  DAT_0001b6de = 0x4020;
  DAT_0001b6e0 = uStack_2;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_4022 @ fff9fe2a (133 bytes)

/* reg 0x4022: DNR table by level */

void dsp_set_dnr_4022(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  uStack_a = 0;
  if ((bVar1 & 0x10) == 0) {
    uStack_a = 0;
  }
  else if ((1 < bVar2 - 6) && (1 < bVar2 - 10)) {
    uStack_a = USHORT_ARRAY_fff87f4a[(bVar1 & 0xf) + 8];
  }
  if (DAT_0001b6d6 == uStack_a) {
    return;
  }
  DAT_0001b6de = 0x4022;
  DAT_0001b6e0 = uStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_4023 @ fff9feaf (129 bytes)

/* reg 0x4023: DNR table by level */

void dsp_set_dnr_4023(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87f69 + (uint)(bVar1 & 0xf) * 2 + 0x11);
  }
  if (DAT_0001b6d8 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4023;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_4025 @ fff9ff30 (129 bytes)

/* reg 0x4025: DNR table by level */

void dsp_set_dnr_4025(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87f89 + (uint)(bVar1 & 0xf) * 2 + 0x11);
  }
  if (DAT_0001b6da == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4025;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_dnr_4026 @ fff9ffb1 (129 bytes)

/* reg 0x4026: DNR table by level (all zero) */

void dsp_set_dnr_4026(byte param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_a;
  
  pbVar3 = vfo_rec_ptr(param_1);
  bVar1 = pbVar3[6];
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(BYTE_ARRAY_fff87fd9 + (uint)(bVar1 & 0xf) * 2 + 1);
  }
  if (DAT_0001b6dc == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4026;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame('w');
  return;
}

