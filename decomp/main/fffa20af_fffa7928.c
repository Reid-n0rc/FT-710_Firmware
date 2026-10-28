// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== sdr_upd_r1c @ fffa20af (72 bytes)

/* Reg 0x1C = 2/5/10 from setting 0x9AD2 [guess: NB parameter] */

void sdr_upd_r1c(void)

{
  undefined2 local_2;
  
  if (DAT_00009ad2 == '\x02') {
    local_2 = 10;
  }
  else if (DAT_00009ad2 == '\0') {
    local_2 = 2;
  }
  else {
    local_2 = 5;
  }
  if (DAT_0001b760 == local_2) {
    return;
  }
  DAT_0001b784 = 0x1c;
  DAT_0001b786 = local_2;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r1d_notch @ fffa20f7 (897 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2407) */
/* WARNING: Removing unreachable block (ram,0xfffa2239) */
/* WARNING: Removing unreachable block (ram,0xfffa23f8) */
/* WARNING: Removing unreachable block (ram,0xfffa225d) */
/* WARNING: Removing unreachable block (ram,0xfffa217d) */
/* WARNING: Removing unreachable block (ram,0xfffa21ff) */
/* WARNING: Removing unreachable block (ram,0xfffa21e4) */
/* WARNING: Removing unreachable block (ram,0xfffa2123) */
/* WARNING: Removing unreachable block (ram,0xfffa21c8) */
/* WARNING: Removing unreachable block (ram,0xfffa2199) */
/* WARNING: Removing unreachable block (ram,0xfffa227b) */
/* WARNING: Removing unreachable block (ram,0xfffa234b) */
/* WARNING: Removing unreachable block (ram,0xfffa2369) */
/* WARNING: Removing unreachable block (ram,0xfffa239f) */
/* Reg 0x1D = notch offset/5 Hz (12 bits) | 0x2000 or 0x1000 (width 0x9AD1), 0 when off [inference:
   manual notch] */

void sdr_upd_r1d_notch(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_11;
  short sStack_a;
  ushort uStack_6;
  
  iVar7 = vfo_rec_ptr(0);
  bVar3 = vfo_mode(0);
  cVar2 = DAT_00009ad1;
  uStack_6 = 0;
  bStack_11 = 0;
  uVar1 = (uint)bVar3;
  if (uVar1 == 0xe) {
    bStack_11 = *(byte *)(iVar7 + 0x28) & 0x80;
    if (DAT_00009a79 == '\x01') {
      sStack_a = 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      sStack_a = 2000;
    }
    else {
      sStack_a = 1000;
    }
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 + sStack_a +
               CONCAT11(*(undefined1 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x2d)) * -10;
  }
  else if (uVar1 - 2 < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x14) & 0x80;
    sVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x18),*(undefined1 *)(iVar7 + 0x19));
    sVar5 = CONCAT11(*(undefined1 *)(iVar7 + 0x1c),*(undefined1 *)(iVar7 + 0x1d));
    FUN_fffc4e4f();
    uVar6 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_17,uStack_16) < uVar6) {
      uStack_6 = uVar6 + sVar5 + sVar4 * -10;
    }
    else {
      uStack_6 = (short)(((uint)CONCAT11(uStack_17,uStack_16) + (uint)uVar6) / 2) + sVar5 +
                 sVar4 * -10;
    }
  }
  else if (uVar1 - 8 < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x28) & 0x80;
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
               CONCAT11(*(undefined1 *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31)) +
               CONCAT11(*(undefined1 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x2d)) * -10;
  }
  else if (uVar1 - 0xc < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x1e) & 0x80;
    sVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x22),*(undefined1 *)(iVar7 + 0x23));
    sVar5 = CONCAT11(*(undefined1 *)(iVar7 + 0x26),*(undefined1 *)(iVar7 + 0x27));
    if (DAT_00009a8c == '\0') {
      if (DAT_00009a8d == '\x01') {
        uStack_6 = sVar5 + 0x564 + sVar4 * -10;
      }
      else if (DAT_00009a8d == '\x02') {
        uStack_6 = sVar5 + 0x5d2 + sVar4 * -10;
      }
      else if (DAT_00009a8d == '\x03') {
        uStack_6 = sVar5 + 0x6a4 + sVar4 * -10;
      }
      else {
        uStack_6 = sVar5 + 0x550 + sVar4 * -10;
      }
    }
    else if (DAT_00009a8d == '\x01') {
      uStack_6 = sVar5 + 0x8b6 + sVar4 * -10;
    }
    else if (DAT_00009a8d == '\x02') {
      uStack_6 = sVar5 + 0x924 + sVar4 * -10;
    }
    else if (DAT_00009a8d == '\x03') {
      uStack_6 = sVar5 + 0x9f6 + sVar4 * -10;
    }
    else {
      uStack_6 = sVar5 + 0x8a2 + sVar4 * -10;
    }
  }
  else if (uVar1 < 2) {
    bStack_11 = *(byte *)(iVar7 + 10) & 0x80;
    uStack_6 = CONCAT11(*(undefined1 *)(iVar7 + 0x12),*(undefined1 *)(iVar7 + 0x13)) + 0x5dc +
               CONCAT11(*(undefined1 *)(iVar7 + 0xe),*(undefined1 *)(iVar7 + 0xf)) * -10;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bVar3 == 1) || (bVar3 == 3)) || (bVar3 == 9)) || (bVar3 == 0xd || bVar3 == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uStack_6 & 0x8000) != 0) {
    uStack_6 = uStack_6 & 0xfff;
  }
  if (bStack_11 == 0) {
    uStack_6 = 0;
  }
  else if (cVar2 == '\0') {
    uStack_6 = uStack_6 | 0x2000;
  }
  else {
    uStack_6 = uStack_6 | 0x1000;
  }
  if (DAT_0001b762 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1d;
  DAT_0001b786 = uStack_6;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r1e_passband @ fffa2478 (599 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2685) */
/* WARNING: Removing unreachable block (ram,0xfffa2575) */
/* WARNING: Removing unreachable block (ram,0xfffa2676) */
/* WARNING: Removing unreachable block (ram,0xfffa2500) */
/* WARNING: Removing unreachable block (ram,0xfffa253f) */
/* WARNING: Removing unreachable block (ram,0xfffa2499) */
/* WARNING: Removing unreachable block (ram,0xfffa2524) */
/* WARNING: Removing unreachable block (ram,0xfffa24de) */
/* WARNING: Removing unreachable block (ram,0xfffa258b) */
/* WARNING: Removing unreachable block (ram,0xfffa262c) */
/* Reg 0x1E = signed passband centre / 5 Hz (negated for the upper-side modes) [inference] */

void sdr_upd_r1e_passband(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  undefined1 uStack_11;
  undefined1 uStack_10;
  ushort uStack_6;
  
  iVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_6 = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
    if (DAT_00009a79 == '\x01') {
      uStack_6 = sVar3 + 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      uStack_6 = sVar3 + 2000;
    }
    else {
      uStack_6 = sVar3 + 1000;
    }
  }
  else if (uVar1 - 2 < 2) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
    FUN_fffc4e4f();
    uStack_6 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_11,uStack_10) < uStack_6) {
      uStack_6 = sVar3 + uStack_6;
    }
    else {
      uStack_6 = (short)(((uint)CONCAT11(uStack_11,uStack_10) + (uint)uStack_6) / 2) + sVar3;
    }
  }
  else if (uVar1 - 8 < 2) {
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
               CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
  }
  else if (uVar1 - 0xc < 2) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x26),*(undefined1 *)(iVar4 + 0x27));
    if (DAT_00009a8c == '\0') {
      if (DAT_00009a8d == '\x01') {
        uStack_6 = sVar3 + 0x564;
      }
      else if (DAT_00009a8d == '\x02') {
        uStack_6 = sVar3 + 0x5d2;
      }
      else if (DAT_00009a8d == '\x03') {
        uStack_6 = sVar3 + 0x6a4;
      }
      else {
        uStack_6 = sVar3 + 0x550;
      }
    }
    else if (DAT_00009a8d == '\x01') {
      uStack_6 = sVar3 + 0x8b6;
    }
    else if (DAT_00009a8d == '\x02') {
      uStack_6 = sVar3 + 0x924;
    }
    else if (DAT_00009a8d == '\x03') {
      uStack_6 = sVar3 + 0x9f6;
    }
    else {
      uStack_6 = sVar3 + 0x8a2;
    }
  }
  else if (uVar1 < 2) {
    uStack_6 = CONCAT11(*(undefined1 *)(iVar4 + 0x12),*(undefined1 *)(iVar4 + 0x13)) + 0x5dc;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bVar2 == 1) || (bVar2 == 3)) || (bVar2 == 9)) || (bVar2 == 0xd || bVar2 == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if (DAT_0001b764 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1e;
  DAT_0001b786 = uStack_6;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r1f_width @ fffa26cf (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa270f) */
/* Reg 0x1F = filter width in Hz (AM 9000, AM-N 6000, FM/DATA-FM 16000, FM-N 9000, else the selected
   width) */

void sdr_upd_r1f_width(void)

{
  uint uVar1;
  undefined1 uStack_4;
  undefined1 uStack_3;
  short local_2;
  
  local_2 = 0;
  uVar1 = vfo_mode(0);
  if (uVar1 < 4) goto LAB_fffa2703;
  if (uVar1 != 4) {
    if (uVar1 == 5) {
      local_2 = 6000;
      goto LAB_fffa272e;
    }
    if (uVar1 == 6) {
LAB_fffa2729:
      local_2 = 16000;
      goto LAB_fffa272e;
    }
    if (uVar1 != 7) {
      if (1 < uVar1 - 8) {
        if (uVar1 == 10) goto LAB_fffa2729;
        if (uVar1 == 0xb) goto LAB_fffa271c;
        if (2 < uVar1 - 0xc) goto LAB_fffa272e;
      }
LAB_fffa2703:
      FUN_fffc4e4f(&uStack_4);
      local_2 = CONCAT11(uStack_4,uStack_3);
      goto LAB_fffa272e;
    }
  }
LAB_fffa271c:
  local_2 = 9000;
LAB_fffa272e:
  if (DAT_0001b766 != local_2) {
    DAT_0001b784 = 0x1f;
    DAT_0001b786 = local_2;
    sdr_send_frame(0x77);
    return;
  }
  return;
}


// ===== sdr_upd_r20_scope_freq @ fffa2758 (402 bytes)

/* Regs 0x20/0x21 = 32-bit scope centre frequency (centre mode: RX freq + offset; fixed/cursor:
   start + half span); TX: |f - 62.5 MHz| */

void sdr_upd_r20_scope_freq(char param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uStack_10;
  undefined *puStack_c;
  
  iVar3 = vfo_freq(param_1,2);
  cVar1 = DAT_00009c35;
  puVar4 = (undefined1 *)scope_span_ptr(iVar3);
  if (param_1 == '\0') {
    uVar2 = vfo_display_offset();
    if (cVar1 == '\0') {
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = (undefined *)(iVar3 + (uint)uVar2);
      }
      else {
        uStack_10 = (undefined *)(iVar3 - (uint)(ushort)(~uVar2 + 1));
      }
    }
    else {
      if (cVar1 == '\x02') {
        puStack_c = (undefined *)bandmem_get(2);
      }
      else {
        puStack_c = (undefined *)DAT_00020f60;
      }
      switch(*puVar4) {
      case 0:
        puStack_c = (undefined *)((int)puStack_c + 500);
        break;
      case 1:
        puStack_c = (undefined *)((int)puStack_c + 1000);
        break;
      case 2:
        puStack_c = (undefined *)((int)puStack_c + 0x9c4);
        break;
      case 3:
        puStack_c = &DAT_00001388 + (int)puStack_c;
        break;
      case 4:
        puStack_c = &DAT_00002710 + (int)puStack_c;
        break;
      case 5:
        puStack_c = &DAT_000061a8 + (int)puStack_c;
        break;
      case 6:
        puStack_c = &DAT_0000c350 + (int)puStack_c;
        break;
      case 7:
        puStack_c = &DAT_000186a0 + (int)puStack_c;
        break;
      case 8:
        puStack_c = &DAT_0003d090 + (int)puStack_c;
        break;
      default:
        puStack_c = (undefined *)((int)puStack_c + 500000);
      }
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = puStack_c + uVar2;
      }
      else {
        uStack_10 = puStack_c + -(uint)(ushort)(~uVar2 + 1);
      }
    }
  }
  else {
    uVar5 = tx_freq_repeater_shift(iVar3);
    if (uVar5 < 0x3b9aca1) {
      uStack_10 = (undefined *)(62500000 - (uVar5 & 0xff));
    }
    else {
      uStack_10 = (undefined *)(uVar5 + 0xfc465360);
    }
  }
  if (uStack_10._2_2_ != DAT_0001b768) {
    DAT_0001b784 = 0x20;
    DAT_0001b786 = uStack_10._2_2_;
    sdr_send_frame(0x77);
    DAT_0001b76a = 0xffff;
    return;
  }
  if (((uint)uStack_10 & 0xffff) != (uint)DAT_0001b76a) {
    DAT_0001b784 = 0x21;
    DAT_0001b786 = (undefined2)uStack_10;
    sdr_send_frame(0x77);
    return;
  }
  return;
}


// ===== sdr_upd_r22_scope_span @ fffa28ea (168 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2913) */
/* Reg 0x22 = scope span in kHz (1,2,5,10,20,50,100,200,500, default 1000) */

void sdr_upd_r22_scope_span(undefined1 param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined1 *puStack_10;
  short sStack_a;
  
  cVar1 = DAT_00009c35;
  uVar3 = vfo_freq(param_1,2);
  bVar2 = freq_range_index(uVar3);
  sStack_a = 1000;
  if (cVar1 == '\x02') {
    puStack_10 = (&PTR_DAT_fff885b0)[(uint)bVar2 * 2];
  }
  else {
    puStack_10 = (&PTR_DAT_fff885ac)[(uint)bVar2 * 2];
  }
  switch(*puStack_10) {
  case 0:
    sStack_a = 1;
    break;
  case 1:
    sStack_a = 2;
    break;
  case 2:
    sStack_a = 5;
    break;
  case 3:
    sStack_a = 10;
    break;
  case 4:
    sStack_a = 0x14;
    break;
  case 5:
    sStack_a = 0x32;
    break;
  case 6:
    sStack_a = 100;
    break;
  case 7:
    sStack_a = 200;
    break;
  case 8:
    sStack_a = 500;
  }
  if (DAT_0001b76c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0x22;
  DAT_0001b786 = sStack_a;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r23 @ fffa2992 (83 bytes)

/* Reg 0x23 = 0x8000/0x7000/0x5000 from setting 0x9B14 [guess: scope/gain] */

void sdr_upd_r23(void)

{
  undefined2 local_2;
  
  if (DAT_00009b14 == '\x01') {
    local_2 = 0x7000;
  }
  else if (DAT_00009b14 == '\x02') {
    local_2 = 0x5000;
  }
  else {
    local_2 = -0x8000;
  }
  if (DAT_0001b76e == local_2) {
    return;
  }
  DAT_0001b784 = 0x23;
  DAT_0001b786 = local_2;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_init_r24 @ fffa29e5 (49 bytes)

/* Reg 0x24 = 0x0317, sent once after the first full sync */

void sdr_init_r24(void)

{
  if (DAT_0001b770 == 0x317) {
    return;
  }
  DAT_0001b784 = 0x24;
  DAT_0001b786 = 0x317;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r25_tx_drive @ fffa2a16 (377 bytes)

/* Reg 0x25 = TX drive: power setting interpolated (5/10/20/50/100 W) in the per-band calibration in
   the 0x4659 (SPN) table, << 4 */

void sdr_upd_r25_tx_drive(void)

{
  undefined *puVar1;
  byte bVar2;
  short sVar3;
  float fVar4;
  uint uVar5;
  float fStack_28;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  
  uVar5 = (uint)SCARRY4((int)&stack0x00000000,-0x28) << 3;
  bVar2 = FUN_fffb4062();
  fVar4 = (float)bVar2;
  bVar2 = FUN_fffb3371(DAT_00020f50);
  puVar1 = (&PTR_DAT_fff8861c)[bVar2];
  if (fVar4 - 100.0 == 0.0) {
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 100.0;
      fStack_28 = 101.0;
      fStack_18 = fStack_1c;
    }
    else {
      fStack_1c = (float)(byte)puVar1[5];
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_18 = fStack_1c;
    }
  }
  else if (fVar4 - 50.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[5];
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 50.0;
      fStack_28 = 100.0;
    }
    else {
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_1c = fStack_18;
    }
  }
  else if (fVar4 - 20.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[8];
    fStack_24 = 20.0;
    fStack_28 = 50.0;
    fStack_1c = (float)(byte)puVar1[5];
  }
  else if (fVar4 - 10.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[0xb];
    fStack_24 = 10.0;
    fStack_28 = 20.0;
    fStack_1c = (float)(byte)puVar1[8];
  }
  else {
    fStack_18 = (float)(byte)puVar1[0xe];
    fStack_24 = 5.0;
    fStack_28 = 10.0;
    fStack_1c = (float)(byte)puVar1[0xb];
  }
  sVar3 = SUB42(ROUND(((fVar4 - fStack_24) * (fStack_1c - fStack_18)) / (fStack_28 - fStack_24) +
                      fStack_18),0) << 4;
  if (DAT_0001b772 == sVar3) {
    return;
  }
  DAT_0001b784 = 0x25;
  DAT_0001b786 = sVar3;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r26 @ fffa2b8f (116 bytes)

/* Reg 0x26 = 0x0610 in RX; in TX 0x0140/0x0610/0x0200/0xFF00 from 0x9C36/0x9B16/0x9B17 [meaning
   unknown] */

void sdr_upd_r26(char param_1)

{
  undefined2 local_4;
  
  if (param_1 == '\0') {
    local_4 = 0x610;
  }
  else if (DAT_00009c36 == '\0') {
    if (DAT_00009b16 == '\0') {
      local_4 = 0x610;
    }
    else {
      local_4 = 0x140;
    }
  }
  else if (DAT_00009b17 == '\0') {
    local_4 = 0x200;
  }
  else {
    local_4 = -0x100;
  }
  if (DAT_0001b774 == local_4) {
    return;
  }
  DAT_0001b784 = 0x26;
  DAT_0001b786 = local_4;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r27_scope_level @ fffa2c03 (156 bytes)

/* Reg 0x27 = 0x8000 | -(scope ref level byte + offset) + 0/2/4 (setting 0x9B14) [inference] */

void sdr_upd_r27_scope_level(char param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  cVar2 = DAT_00009b14;
  cVar1 = DAT_00004689;
  uVar4 = vfo_freq(param_1,2);
  pcVar5 = (char *)scope_level_ptr(uVar4,param_1);
  if (cVar2 == '\x01') {
    uStack_14 = '\x02';
  }
  else if (cVar2 == '\x02') {
    uStack_14 = '\x04';
  }
  else {
    uStack_14 = '\0';
  }
  if (param_1 == '\0') {
    uStack_13 = *pcVar5 + cVar1 + 0x44;
  }
  else {
    uStack_13 = *pcVar5 - 0x37;
  }
  uVar3 = (byte)(~uStack_13 + 1 + uStack_14) | 0x8000;
  if (DAT_0001b776 == uVar3) {
    return;
  }
  DAT_0001b784 = 0x27;
  DAT_0001b786 = uVar3;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_shadow_update @ fffa2c9f (856 bytes)

/* After an ACKed frame: copies 0x1B786 into the shadow slot of register 0x1B784 (0x1B736..0x1B780;
   0xFFFF -> 0x1B782) */

void sdr_shadow_update(void)

{
  if (DAT_0001b784 == -1) {
    DAT_0001b782 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 1) {
    DAT_0001b738 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 3) {
    DAT_0001b73a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 4) {
    DAT_0001b73c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 8) {
    DAT_0001b73e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 9) {
    DAT_0001b740 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 10) {
    DAT_0001b742 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xb) {
    DAT_0001b744 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xc) {
    DAT_0001b746 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xd) {
    DAT_0001b748 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xe) {
    DAT_0001b74a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xf) {
    DAT_0001b74c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x12) {
    DAT_0001b74e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x13) {
    DAT_0001b750 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x14) {
    DAT_0001b752 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x15) {
    DAT_0001b754 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x16) {
    DAT_0001b756 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x18) {
    DAT_0001b758 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x19) {
    DAT_0001b75a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1a) {
    DAT_0001b75c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1b) {
    DAT_0001b75e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1c) {
    DAT_0001b760 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1d) {
    DAT_0001b762 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1e) {
    DAT_0001b764 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1f) {
    DAT_0001b766 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x20) {
    DAT_0001b768 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x21) {
    DAT_0001b76a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x22) {
    DAT_0001b76c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x23) {
    DAT_0001b76e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x24) {
    DAT_0001b770 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x25) {
    DAT_0001b772 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x26) {
    DAT_0001b774 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x27) {
    DAT_0001b776 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x30) {
    DAT_0001b778 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x31) {
    DAT_0001b77a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x32) {
    DAT_0001b77c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x33) {
    DAT_0001b77e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x37) {
    DAT_0001b780 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 != 0) {
    return;
  }
  DAT_0001b736 = DAT_0001b786;
  return;
}


// ===== sdr_wait_reply @ fffa2ff7 (140 bytes)

/* Blocking wait for the reply of the pending frame; read -> 0x1B786=hex2word(reply+1); calls
   sdr_shadow_update (arg2=1: reg forced to 0xFFFF so the value lands in 0x1B782) */

undefined1 sdr_wait_reply(char param_1,char param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  while( true ) {
    while (param_1 != 'r') {
      if (DAT_00001c8b != '\x01') {
        return local_9;
      }
      iVar1 = sdr_poll_reply(0x77);
      if (iVar1 == 1) {
        if (param_2 == '\x01') {
          DAT_0001b784 = 0xffff;
        }
        sdr_shadow_update();
        local_9 = 1;
      }
    }
    if (DAT_00001c8c != '\x01') break;
    iVar1 = sdr_poll_reply(0x72);
    if (iVar1 == 1) {
      DAT_0001b786 = hex2word();
      if (param_2 == '\x01') {
        DAT_0001b784 = 0xffff;
      }
      sdr_shadow_update();
      return 1;
    }
  }
  return local_9;
}


// ===== sdr_poll_reply @ fffa3083 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa30f6) */
/* Reply poll: if 0xA2B3, clears pending flags; 'r' -> checks 2-hex sum of bytes 0..4, 'w' -> byte 0
   must be ACK 0x06; on timer 2 timeout clears the flags and fails */

undefined1 sdr_poll_reply(char param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_e;
  
  local_e = 0;
  iVar1 = sdr_rx_ready();
  if (iVar1 == 1) {
    uVar2 = sdr_rx_buf();
    *param_2 = uVar2;
    DAT_00001c8b = 0;
    DAT_00001c8c = 0;
    if (param_1 == 'r') {
      iVar1 = sdr_check_hex_sum((char *)*param_2,5);
      if (iVar1 == 1) {
        local_e = 1;
      }
    }
    else if (*(char *)*param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    iVar1 = swtimer_expired(2);
    if (iVar1 == 1) {
      DAT_00001c8b = 0;
      DAT_00001c8c = 0;
    }
  }
  return local_e;
}


// ===== sdr_send_frame @ fffa30f9 (181 bytes)

/* Builds 'r'/'w' + 4-hex reg (0x1B784) [+ 4-hex value 0x1B786] + 2-hex sum8 + CR at 0x1C7F, sets
   pending flag 0x1C8C (r) / 0x1C8B (w), sends via sdr_send_cmd, arms timer 2 = 6 ms */

void sdr_send_frame(char param_1)

{
  undefined1 uVar1;
  byte local_2;
  
  DAT_00001c7f = param_1;
  word2hex(0x1c80,DAT_0001b784);
  local_2 = 5;
  if (param_1 == 'w') {
    word2hex(0x1c84,DAT_0001b786);
    local_2 = 9;
    DAT_00001c8b = 1;
  }
  else {
    DAT_00001c8c = 1;
  }
  uVar1 = sdr_sum8(&DAT_00001c7f,local_2);
  byte2hex(&DAT_00001c7f + local_2,uVar1);
  (&DAT_00001c7f)[(byte)(local_2 + 2)] = 0xd;
  sdr_send_cmd(&DAT_00001c7f,local_2 + 3);
  swtimer_start(2,6);
  return;
}


// ===== sdr_sum8 @ fffa31ae (45 bytes)

/* 8-bit additive sum of n bytes (frame checksum) */

char sdr_sum8(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== sdr_check_hex_sum @ fffa31db (75 bytes)

/* 1 if the 2 hex chars after n bytes equal sum8 of those bytes */

undefined1 sdr_check_hex_sum(int param_1,byte param_2)

{
  undefined1 uVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uVar1 = sdr_sum8(param_1,param_2);
  byte2hex(&cStack_8,uVar1);
  if ((cStack_8 == *(char *)((uint)local_5 + local_4)) &&
     (cStack_7 == *(char *)(local_4 + (uint)local_5 + 1))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== sdr_bridge_mode @ fffa3226 (598 bytes)

/* SDR maintenance bridge driven by DISPLAY link (ACK 0x06 / NAK 0x15), started via 0x1C8D */

void sdr_bridge_mode(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 auStack_10 [4];
  undefined1 uStack_c;
  char acStack_b [11];
  
  DAT_00001c8d = 0;
  dsp_reset_set(0);
  sdr_reset_set(0);
  sdr_update_set(0);
  swtimer_start(0x1e,100);
  do {
    iVar2 = swtimer_expired(0x1e);
  } while (iVar2 != 1);
  sdr_reset_set(1);
  swtimer_start(0x1e,2000);
  do {
    iVar2 = swtimer_expired(0x1e);
  } while (iVar2 != 1);
  DAT_0001b784 = 0x37;
  DAT_0001b786 = 0xbcc5;
  sdr_send_frame(0x77);
  iVar2 = sdr_wait_reply(0x77,0);
  if (iVar2 == 1) {
    uStack_12 = 6;
    displink_uart_send(&uStack_12,1);
    while( true ) {
      do {
        do {
          wdt_kick();
          iVar2 = displink_rx_ready();
        } while (iVar2 != 1);
        pcVar3 = (char *)displink_rx_buf();
        pcVar4 = acStack_b;
        for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pcVar4 = *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        }
        displink_rx_rearm();
      } while (acStack_b[0] == '\x06');
      if ((acStack_b[0] == -0xf) && (acStack_b[1] == -0x7f)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      if ((acStack_b[0] == -3) && (acStack_b[1] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0001b784 = hex2word();
        DAT_0001b786 = hex2word();
        sdr_send_frame(0x77);
        iVar2 = sdr_wait_reply(0x77,0);
        if (iVar2 == 1) {
          uStack_12 = 6;
          displink_uart_send(&uStack_12,1);
        }
        else {
          uStack_12 = 0x15;
          displink_uart_send(&uStack_12,1);
        }
      }
      else {
        if ((acStack_b[0] == -2) && (acStack_b[1] == '\0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_12 = 6;
          displink_uart_send(&uStack_12,1);
          DAT_0001b784 = hex2word();
          sdr_send_frame(0x72);
          iVar2 = sdr_wait_reply(0x72,0);
          if (iVar2 == 1) {
            uStack_12 = 0x7d;
            uStack_11 = 0;
            if (DAT_0001b784 == 0x32) {
              word2hex(auStack_10,DAT_0001b77c);
              uStack_c = sdr_sum8(&uStack_12,6);
              displink_uart_send(&uStack_12,7);
            }
            else if (DAT_0001b784 == 0x33) {
              word2hex(auStack_10,DAT_0001b77e);
              uStack_c = sdr_sum8(&uStack_12,6);
              displink_uart_send(&uStack_12,7);
            }
            else {
              uStack_12 = 0x15;
              displink_uart_send(&uStack_12,1);
            }
          }
          else {
            uStack_12 = 0x15;
            displink_uart_send(&uStack_12,1);
          }
        }
        else {
          uStack_12 = 0x15;
          displink_uart_send(&uStack_12,1);
        }
      }
    }
    uStack_12 = 6;
    displink_uart_send(&uStack_12,1);
    sdr_reset_set(0);
    sdr_update_set(1);
    swtimer_start(0x1e,100);
    do {
      iVar2 = swtimer_expired(0x1e);
    } while (iVar2 != 1);
    sdr_reset_set(1);
    dsp_reset_set(1);
    return;
  }
  uStack_12 = 0x15;
  displink_uart_send(&uStack_12,1);
  return;
}


// ===== cat_parse @ fffa347c (630 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa350d) */
/* WARNING: Removing unreachable block (ram,0xfffa3588) */
/* WARNING: Removing unreachable block (ram,0xfffa365b) */
/* CAT command parser: looks up the 2-char mnemonic in cat_mnemonics (0xFFF805EC, 104 entries) then
   cat_ext_mnemonics (0xFFF806BC, 10 entries), calls cat_dispatch / cat_dispatch_ext */

void cat_parse(void)

{
  undefined2 uVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  uint *in_R15;
  byte bStack_f;
  byte bStack_e;
  undefined2 uStack_d;
  char cStack_b;
  char cStack_a;
  char cStack_9;
  char *pcStack_8;
  char *pcStack_4;
  
  cStack_9 = cat_ring_head();
  cStack_a = cat_ring_tail();
  DAT_0000464a = '\0';
  bStack_f = 0xff;
  DAT_0001b788 = 0;
  if (DAT_00020b46 == '\x01') {
    DAT_0001b788 = 0;
    DAT_0000464a = 0;
    return;
  }
  if (cStack_9 == cStack_a) {
    pcStack_8 = (char *)cat_e9_slot();
    if (*pcStack_8 == '\x01') {
      cStack_b = pcStack_8[1];
      uStack_d = *(undefined2 *)(pcStack_8 + 4);
      for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
        toupper_inplace();
      }
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        puVar8 = (undefined4 *)((uint)bStack_e * 2);
        pbVar7 = (byte *)(puVar8 + -0x1fe51);
        iVar6 = 2;
        pbVar5 = (byte *)&uStack_d;
        do {
          bVar2 = *pbVar5;
          bVar3 = *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
          iVar6 = iVar6 + -1;
          if ((bVar2 != bVar3) || (bVar2 == 0)) break;
        } while (iVar6 != 0);
        if (bVar3 <= bVar2) {
          *puVar8 = 1;
        }
        bVar4 = bVar3 > bVar2;
        if (bVar4 || bVar2 == bVar3) {
          *in_R15 = (uint)(bVar4 || bVar2 == bVar3);
        }
        if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 3) {
        cat_ext_E9();
      }
      if (DAT_0000464a != '\0') {
        cat_reply_error();
      }
      if (DAT_0001b788 != 0) {
        cat_send_reply(cStack_b,&DAT_00001c8e,DAT_0001b788);
      }
      *pcStack_8 = '\0';
    }
  }
  else {
    cat_apo_reset();
    pcStack_4 = (char *)cat_ring_pop();
    cStack_b = *pcStack_4;
    iVar6 = sci_tx_end(cStack_b);
    if (iVar6 == 0) {
      cat_ring_unpop();
      return;
    }
    uStack_d = *(undefined2 *)(pcStack_4 + 4);
    uVar1 = *(undefined2 *)(pcStack_4 + 2);
    DAT_0000464c = cStack_b;
    for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
      toupper_inplace();
    }
    for (bStack_e = 0; bStack_e < 0x68; bStack_e = bStack_e + 1) {
      puVar8 = (undefined4 *)((uint)bStack_e * 2);
      pbVar7 = (byte *)(puVar8 + -0x1fe85);
      iVar6 = 2;
      pbVar5 = (byte *)&uStack_d;
      do {
        bVar2 = *pbVar5;
        bVar3 = *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
        iVar6 = iVar6 + -1;
        if ((bVar2 != bVar3) || (bVar2 == 0)) break;
      } while (iVar6 != 0);
      if (bVar3 <= bVar2) {
        *puVar8 = 1;
      }
      bVar4 = bVar3 > bVar2;
      if (bVar4 || bVar2 == bVar3) {
        *in_R15 = (uint)(bVar4 || bVar2 == bVar3);
      }
      if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
        bStack_f = bStack_e;
        break;
      }
    }
    if (DAT_00020b3a == '\0') {
      if ((bStack_f == 0x47) && (pcStack_4[6] == '1')) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (!bVar4) {
        return;
      }
    }
    if (bStack_f == 0xff) {
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        puVar8 = (undefined4 *)((uint)bStack_e * 2);
        pbVar7 = (byte *)(puVar8 + -0x1fe51);
        iVar6 = 2;
        pbVar5 = (byte *)&uStack_d;
        do {
          bVar2 = *pbVar5;
          bVar3 = *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
          iVar6 = iVar6 + -1;
          if ((bVar2 != bVar3) || (bVar2 == 0)) break;
        } while (iVar6 != 0);
        if (bVar3 <= bVar2) {
          *puVar8 = 1;
        }
        bVar4 = bVar3 > bVar2;
        if (bVar4 || bVar2 == bVar3) {
          *in_R15 = (uint)(bVar4 || bVar2 == bVar3);
        }
        if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 0xff) {
        DAT_0000464a = '\x01';
      }
      else if (bStack_f == 0) {
        cat_ext_SP(pcStack_4);
      }
      else {
        cat_dispatch_ext(pcStack_4,bStack_f,uVar1);
      }
    }
    else {
      cat_dispatch(pcStack_4,bStack_f,uVar1);
    }
    if (DAT_0000464a == '\0') {
      if (DAT_00020b8a == '\x01') {
        FUN_fffbe232();
      }
    }
    else {
      cat_reply_error();
    }
    if (DAT_0001b788 != 0) {
      cat_send_reply(cStack_b,&DAT_00001c8e,DAT_0001b788);
    }
  }
  if ((DAT_0000464b == '\x01') && (iVar6 = swtimer_expired(0x32), iVar6 == 1)) {
    FUN_fffbff93();
    DAT_0000464b = '\0';
  }
  cat_ai_poll();
  return;
}


// ===== cat_ext_SP @ fffa36f2 (824 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Extended command SP (index 0 of 0xFFF806BC table) */

void cat_ext_SP(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 6);
  if ((cVar1 == 'S') || (cVar1 == 's')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_sdr_reg(param_1 + 4,1);
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_sdr_reg(param_1 + 4,0);
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'D') || (cVar1 == 'd')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_dev4_reg(param_1 + 4,1);
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_dev4_reg(param_1 + 4,0);
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'I') || (cVar1 == 'i')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if ((*(char *)(param_1 + 7) == 'R') || (*(char *)(param_1 + 7) == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_adc_dump();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'W') || (cVar1 == 'R')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    iVar3 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) + -2);
    if (iVar3 != 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c92 = *(undefined1 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (cVar1 == 'W') {
      cat_SP_eeprom_byte(param_1 + 4,1);
      return;
    }
    cat_SP_eeprom_byte(param_1 + 4,0);
    return;
  }
  if ((cVar1 == 'M') || (cVar1 == 'm')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    iVar3 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) + -2);
    if (iVar3 != 1) {
      DAT_0000464a = 1;
      return;
    }
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    cat_SP_meters();
    return;
  }
  if ((cVar1 == 'N') || (cVar1 == 'n')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,1,*(undefined2 *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'S') || (cVar1 == 's')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,1,*(undefined2 *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,0,*(undefined2 *)(param_1 + 2));
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'A') || (cVar1 == 'a')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return;
  }
  iVar3 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) + -2);
  if (iVar3 != 1) {
    DAT_0000464a = 1;
    return;
  }
  if ((*(char *)(param_1 + 7) == 'W') || (*(char *)(param_1 + 7) == 'w')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'e')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar2 = true;
      goto LAB_fffa3a12;
    }
  }
  bVar2 = false;
LAB_fffa3a12:
  if (bVar2) {
    eeprom_save_cfg105();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_dispatch_ext @ fffa3a2a (324 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatch for the extended/hidden mnemonic table (EO E8 FD PE ZZ VE JP; E9/KT no case here) */

void cat_dispatch_ext(int param_1,char param_2,short param_3)

{
  undefined1 uVar1;
  
  if (param_2 == '\x01') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_EO(param_1 + 4,1);
    return;
  }
  if (param_2 == '\t') {
    _DAT_00001c92 = *(undefined2 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 7) {
      cat_ext_JP(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_JP(param_1 + 4,1);
    return;
  }
  if (param_2 == '\x04') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_ext_FD(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_FD(param_1 + 4,1);
    return;
  }
  if (param_2 != '\x06') {
    if (param_2 == '\a') {
      cat_ext_ZZ(param_1 + 4);
      return;
    }
    if (param_2 == '\b') {
      _DAT_00001c8e =
           CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4)
                   );
      uVar1 = hex2nib(*(undefined1 *)(param_1 + 6));
      cat_ext_VE(uVar1);
      return;
    }
    if (param_2 != '\x02') {
      return;
    }
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    cat_ext_E8();
    return;
  }
  _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
  _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
  if (param_3 == 6) {
    cat_ext_PE(param_1 + 4,0);
    return;
  }
  if (param_3 != 9) {
    DAT_0000464a = 1;
    return;
  }
  cat_ext_PE(param_1 + 4,1);
  return;
}


// ===== cat_dispatch @ fffa3b6e (4803 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAT dispatch switch: index -> case via 16-bit offset table 0xFFF8F014 (BRA.L at 0xFFFA3B8A); each
   case checks parameter length (query vs set) then calls cat_XX */

void cat_dispatch(int param_1,char param_2,ushort param_3)

{
  bool bVar1;
  undefined1 uVar2;
  
  uVar2 = DAT_00001c91;
  switch(param_2) {
  case '\0':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AB();
    return;
  case '\x01':
    break;
  case '\x02':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AG(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AG(param_1 + 4,1);
    return;
  case '\x03':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AI(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_AI(param_1 + 4,1);
    return;
  case '\x04':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AM();
    return;
  case '\x05':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AO(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AO(param_1 + 4,1);
    return;
  case '\x06':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AS(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AS(param_1 + 4,1);
    return;
  case '\a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AV(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AV(param_1 + 4,1);
    return;
  case '\b':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BA();
    return;
  case '\t':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_BC(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BC(param_1 + 4,1);
    return;
  case '\n':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BD(param_1 + 4);
    return;
  case '\v':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_BI(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BI(param_1 + 4,1);
    return;
  case '\f':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BM();
    return;
  case '\r':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_BP(param_1 + 4,0);
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_BP(param_1 + 4,1);
    return;
  case '\x0e':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BS(param_1 + 4);
    return;
  case '\x0f':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BU(param_1 + 4);
    return;
  default:
    DAT_0000464a = 1;
    return;
  case '\x11':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_CF(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_CF(param_1 + 4,1);
    return;
  case '\x12':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CH(param_1 + 4);
    return;
  case '\x13':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_CN(param_1 + 4,0);
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_CN(param_1 + 4,1);
    return;
  case '\x14':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 5) {
      cat_CO(param_1 + 4,0);
      return;
    }
    if (param_3 != 9) {
      DAT_0000464a = 1;
      return;
    }
    cat_CO(param_1 + 4,1);
    return;
  case '\x15':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_CS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CS(param_1 + 4,1);
    return;
  case '\x16':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_CT(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_CT(param_1 + 4,1);
    return;
  case '\x17':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_DA(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_DA(param_1 + 4,1);
    return;
  case '\x18':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_DN();
    return;
  case '\x19':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_DT(param_1 + 4,0);
      return;
    }
    if ((param_3 == 10) || (param_3 == 0xc)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_DT(param_1 + 4,1);
    return;
  case '\x1c':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_EM(param_1 + 4,0);
      return;
    }
    if ((param_3 < 6) || (0x37 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_EM(param_1 + 4,1);
    return;
  case '\x1d':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_EN(param_1 + 4);
    return;
  case '\x1f':
    _DAT_00001c92 = *(undefined4 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 9) {
      cat_EX(param_1 + 4,0,9);
      return;
    }
    if (8 < param_3) {
      cat_EX(param_1 + 4,1,param_3);
      return;
    }
    DAT_0000464a = 1;
    return;
  case ' ':
  case '!':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FA_FB(param_1 + 4,0,param_2 != ' ');
      return;
    }
    if (param_3 != 0xc) {
      DAT_0000464a = 1;
      return;
    }
    cat_FA_FB(param_1 + 4,1,param_2 != ' ');
    return;
  case '\"':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FN(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FN(param_1 + 4,1);
    return;
  case '#':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FS(param_1 + 4,1);
    return;
  case '$':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FT(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FT(param_1 + 4,1);
    return;
  case '%':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_GT(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_GT(param_1 + 4,1);
    return;
  case '&':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_GP(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_GP(param_1 + 4,1);
    return;
  case '\'':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_ID();
    return;
  case '(':
  case '@':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_IF_OI(param_2 != '(');
    return;
  case ')':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_IS(param_1 + 4,0);
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_IS(param_1 + 4,1);
    return;
  case '*':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_KM(param_1 + 4,0,4);
      return;
    }
    if ((param_3 < 5) || (0x36 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_KM(param_1 + 4,1,param_3);
    return;
  case '+':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KP(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KP(param_1 + 4,1);
    return;
  case ',':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KR(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_KR(param_1 + 4,1);
    return;
  case '-':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KS(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_KS(param_1 + 4,1);
    return;
  case '.':
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KY(param_1 + 4);
    return;
  case '/':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_LK(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_LK(param_1 + 4,1);
    return;
  case '0':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_LM(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_LM(param_1 + 4,1);
    return;
  case '1':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MA();
    return;
  case '2':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MB();
    return;
  case '3':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MC(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MC(param_1 + 4,1);
    return;
  case '4':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_MD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MD(param_1 + 4,1);
    return;
  case '5':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MG(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MG(param_1 + 4,1);
    return;
  case '6':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_ML(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_ML(param_1 + 4,1);
    return;
  case '7':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MR(param_1 + 4,0);
    return;
  case '8':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MS(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MS(param_1 + 4,1);
    return;
  case '9':
    _DAT_00001c92 = CONCAT31((undefined3)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_MT(param_1 + 4,0,6);
      return;
    }
    if ((param_3 < 8) || (0x13 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_MT(param_1 + 4,1,param_3);
    return;
  case ':':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 0x1c) {
      DAT_0000464a = 1;
      return;
    }
    cat_MW(param_1 + 4,1);
    return;
  case ';':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_MX(param_1 + 4,1);
    return;
  case '<':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NA(param_1 + 4,1);
    return;
  case '=':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NB(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NB(param_1 + 4,1);
    return;
  case '>':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NL(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_NL(param_1 + 4,1);
    return;
  case '?':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NR(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NR(param_1 + 4,1);
    return;
  case 'A':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_OS(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_OS(param_1 + 4,1);
    return;
  case 'B':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PA(param_1 + 4,1);
    return;
  case 'C':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PB(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PB(param_1 + 4,1);
    return;
  case 'D':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PC(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PC(param_1 + 4,1);
    return;
  case 'E':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PL(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PL(param_1 + 4,1);
    return;
  case 'F':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PR(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PR(param_1 + 4,1);
    return;
  case 'G':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_PS(param_1 + 4,1);
    return;
  case 'H':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QI();
    return;
  case 'I':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QR();
    return;
  case 'J':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QS();
    return;
  case 'K':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_RA(param_1 + 4,1);
    return;
  case 'N':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RG(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_RG(param_1 + 4,1);
    return;
  case 'O':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RI(param_1 + 4);
    return;
  case 'P':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RL(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_RL(param_1 + 4,1);
    return;
  case 'Q':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RM(param_1 + 4);
    return;
  case 'U':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SC(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SC(param_1 + 4,1);
    return;
  case 'V':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SD(param_1 + 4,1);
    return;
  case 'W':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SF(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SF(param_1 + 4,1);
    return;
  case 'X':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SH(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SH(param_1 + 4,1);
    return;
  case 'Y':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SM(param_1 + 4);
    return;
  case 'Z':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SQ(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SQ(param_1 + 4,1);
    return;
  case '[':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_SS(param_1 + 4,0);
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_SS(param_1 + 4,1);
    return;
  case '\\':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_ST(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ST(param_1 + 4,1);
    return;
  case ']':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_SV(param_1 + 4,1);
    return;
  case '^':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TS(param_1 + 4,1);
    return;
  case '_':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TX(param_1 + 4,1);
    return;
  case '`':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_UP();
    return;
  case 'a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_VD(param_1 + 4,1);
    return;
  case 'b':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VG(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_VG(param_1 + 4,1);
    return;
  case 'c':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if ((param_3 == 4) || (param_3 == 3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (param_3 == 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_VM(param_1 + 4,param_3);
    return;
  case 'd':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VS(param_1 + 4,1);
    return;
  case 'e':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VX(param_1 + 4,1);
    return;
  case 'g':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ZI(param_1 + 4);
    return;
  }
  _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
  if (param_3 == 3) {
    cat_AC(param_1 + 4,0);
    return;
  }
  if (param_3 != 6) {
    DAT_0000464a = 1;
    return;
  }
  cat_AC(param_1 + 4,1);
  return;
}


// ===== cat_SP_sdr_reg @ fffa4e31 (94 bytes)

/* SPS R/W: SDR register read/write (4-hex addr at text+4, 4-hex value at text+8) */

void cat_SP_sdr_reg(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined2 uStack_a;
  undefined2 uStack_8;
  char local_5;
  undefined4 local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = hex2word();
  uStack_a = hex2word();
  iVar1 = sdr_reg_access(uStack_8,&uStack_a,local_5);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  word2hex(&DAT_00001c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== cat_SP_dev4_reg @ fffa4e8f (94 bytes)

/* SPD R/W: SCI4 device register read/write */

void cat_SP_dev4_reg(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined2 uStack_a;
  undefined2 uStack_8;
  char local_5;
  undefined4 local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = hex2word();
  uStack_a = hex2word();
  iVar1 = dsp_reg_access(uStack_8,&uStack_a,local_5);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  word2hex(&DAT_00001c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== cat_SP_adc_dump @ fffa4eed (524 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SPIR: 12 ADC results (0x20B04..0x20B16) as 3 hex digits each */

void cat_SP_adc_dump(void)

{
  undefined1 uStack_6;
  undefined2 uStack_5;
  undefined1 uStack_3;
  undefined2 local_2;
  
  local_2 = 0;
  word2hex(&uStack_6,0);
  DAT_00001c93._1_1_ = uStack_3;
  _DAT_00001c92 = uStack_5;
  local_2 = DAT_00020b04;
  word2hex(&uStack_6,DAT_00020b04);
  DAT_00001c97 = uStack_3;
  DAT_00001c93._2_2_ = uStack_5;
  local_2 = DAT_00020b06;
  word2hex(&uStack_6,DAT_00020b06);
  uRam00001c9a = uStack_3;
  _DAT_00001c98 = uStack_5;
  local_2 = DAT_00020b08;
  word2hex(&uStack_6,DAT_00020b08);
  DAT_00001c9d = uStack_3;
  uRam00001c9b = uStack_5;
  local_2 = 0;
  word2hex(&uStack_6,0);
  DAT_00001ca0 = uStack_3;
  uRam00001c9e = uStack_5;
  local_2 = DAT_00020b0c;
  word2hex(&uStack_6,DAT_00020b0c);
  DAT_00001ca3 = uStack_3;
  _DAT_00001ca1 = uStack_5;
  local_2 = 0;
  word2hex(&uStack_6,0);
  DAT_00001ca6 = uStack_3;
  _DAT_00001ca4 = uStack_5;
  local_2 = DAT_00020b0e;
  word2hex(&uStack_6,DAT_00020b0e);
  DAT_00001ca9 = uStack_3;
  _DAT_00001ca7 = uStack_5;
  local_2 = DAT_00020b14;
  word2hex(&uStack_6,DAT_00020b14);
  uRam00001cac = uStack_3;
  uRam00001caa = uStack_5;
  local_2 = DAT_00020b16;
  word2hex(&uStack_6,DAT_00020b16);
  uRam00001caf = uStack_3;
  uRam00001cad = uStack_5;
  local_2 = DAT_00020b10;
  word2hex(&uStack_6,DAT_00020b10);
  uRam00001cb2 = uStack_3;
  uRam00001cb0 = uStack_5;
  local_2 = DAT_00020b12;
  word2hex(&uStack_6,DAT_00020b12);
  uRam00001cb5 = uStack_3;
  uRam00001cb3 = uStack_5;
  uRam00001cb6 = 0x3b;
  DAT_0001b788 = 0x29;
  return;
}


// ===== cat_SP_table @ fffa50f9 (274 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa51a6) */
/* WARNING: Removing unreachable block (ram,0xfffa511d) */
/* WARNING: Removing unreachable block (ram,0xfffa5208) */
/* WARNING: Removing unreachable block (ram,0xfffa512e) */
/* WARNING: Removing unreachable block (ram,0xfffa5144) */
/* WARNING: Removing unreachable block (ram,0xfffa5158) */
/* WARNING: Removing unreachable block (ram,0xfffa5205) */
/* WARNING: Removing unreachable block (ram,0xfffa51d1) */
/* SPN R/W/S (binary): table 0x4659[1..0x105] */

undefined2 * cat_SP_table(int param_1,char param_2,short param_3)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 *puVar4;
  
  puVar4 = (undefined2 *)cat_checksum_ok(param_1,param_3 + -2);
  if (puVar4 != (undefined2 *)0x1) {
    DAT_0000464a = 1;
    return puVar4;
  }
  uVar3 = CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  if (uVar3 == 0) {
    DAT_0000464a = 1;
    return (undefined2 *)0x0;
  }
  if ((undefined2 *)0x105 < (undefined2 *)(uint)uVar3) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)uVar3;
  }
  uVar3 = uVar3 - 1;
  if (param_2 != '\0') {
    if ((*(char *)(param_1 + 3) == 'W') || (*(char *)(param_1 + 3) == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar1 = *(byte *)(param_1 + 6);
      (&DAT_00004659)[uVar3] = bVar1;
      return (undefined2 *)(uint)bVar1;
    }
    if ((*(char *)(param_1 + 3) == 'S') || (*(char *)(param_1 + 3) == 's')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      return (undefined2 *)0x0;
    }
    puVar4 = (undefined2 *)swtimer_start(0x32,500);
    DAT_0000464b = 1;
    return puVar4;
  }
  DAT_00020ce2 = uVar3;
  FUN_fffbb567();
  DAT_00001c91 = (&DAT_00004659)[uVar3];
  DAT_00001c92 = sum8(&DAT_00001c8e,4);
  DAT_00001c93._0_1_ = 0x3b;
  DAT_0001b788 = 6;
  return &DAT_00001c8e;
}


// ===== cat_SP_eeprom_byte @ fffa520b (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5268) */
/* WARNING: Removing unreachable block (ram,0xfffa5217) */
/* WARNING: Removing unreachable block (ram,0xfffa5281) */
/* SPR/SPW (binary): EEPROM byte read/write at 16-bit address */

undefined2 * cat_SP_eeprom_byte(int param_1,char param_2)

{
  byte local_d;
  ushort local_c;
  char local_9;
  int local_8;
  
  local_c = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  local_d = *(byte *)(param_1 + 5);
  local_9 = param_2;
  local_8 = param_1;
  if (param_2 != '\0') {
    eeprom_write_raw(local_c,&local_d,1);
    (&DAT_0000464f)[local_c] = local_d;
    return (undefined2 *)(uint)local_d;
  }
  eeprom_read_raw(local_c,&local_d,1);
  DAT_00001c93._0_1_ = local_d;
  DAT_00001c93._1_1_ = sum8(&DAT_00001c8e,6);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return &DAT_00001c8e;
}


// ===== cat_SP_meters @ fffa5284 (288 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffa5284) */
/* WARNING: Removing unreachable block (ram,0xfffa53a1) */
/* SPM (binary): 8 meter bytes + checksum */

undefined4 cat_SP_meters(void)

{
  DAT_00001c91 = meter_get_s();
  DAT_00001c92 = 0;
  DAT_00001c93._0_1_ = meter_get_po();
  DAT_00001c93._1_1_ = meter_get_swr();
  DAT_00001c93._2_1_ = meter_get_comp();
  DAT_00001c93._3_1_ = meter_get_alc();
  DAT_00001c97 = meter_get_vdd();
  DAT_00001c98 = meter_get_idd();
  DAT_00001c99 = 0;
  uRam00001c9a = 0;
  uRam00001c9b = 0;
  DAT_00001c9c = sum8(&DAT_00001c8e,0xe);
  DAT_00001c9d = 0x3b;
  DAT_0001b788 = 0x10;
  return 0x10;
}


// ===== cat_ext_E8 @ fffa53a4 (271 bytes)

void cat_ext_E8(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  char cStack_a;
  ushort uStack_8;
  
  cVar1 = cat_rand8();
  cStack_a = '\0';
  DAT_00001c91 = cVar1 + '\a';
  DAT_00001c92 = cVar1 + -0x70;
  puVar3 = &DAT_000060c9;
  puVar2 = (undefined1 *)((int)&DAT_00001c93 + 2);
  DAT_00001c90 = cVar1;
  DAT_00001c93._0_1_ = cVar1;
  DAT_00001c93._1_1_ = cVar1;
  for (puVar4 = &DAT_000029a9; puVar4 != (undefined *)0x0; puVar4 = puVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uStack_8 = 0; uStack_8 < 0x29a9; uStack_8 = uStack_8 + 1) {
    cStack_a = *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cStack_a;
    *(char *)((int)&DAT_00001c93 + uStack_8 + 2) =
         *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cVar1;
  }
  cRam0000463e = cStack_a + cVar1;
  uRam0000463f = 0x3b;
  DAT_0001b788 = 0x29b2;
  return;
}


// ===== cat_ext_VE @ fffa54b3 (184 bytes)

void cat_ext_VE(char param_1)

{
  undefined4 uStack_8;
  
  if (param_1 == '\0') {
    uStack_8 = ver_main();
  }
  else if (param_1 == '\x01') {
    uStack_8 = ver_display();
  }
  else if (param_1 == '\x02') {
    uStack_8 = ver_sdr();
  }
  else {
    if (param_1 != '\x03') {
      DAT_0000464a = 1;
      return;
    }
    uStack_8 = ver_dsp();
  }
  DAT_00001c91 = *(undefined1 *)(uStack_8 + 1);
  DAT_00001c92 = *(undefined1 *)(uStack_8 + 2);
  DAT_00001c93._0_1_ = *(undefined1 *)(uStack_8 + 4);
  DAT_00001c93._1_1_ = *(undefined1 *)(uStack_8 + 5);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return;
}


// ===== cat_ext_JP @ fffa556b (822 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5810) */

void cat_ext_JP(undefined4 param_1,char param_2)

{
  bool bVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  short sStack_e;
  undefined *local_c;
  char local_5;
  undefined4 local_4;
  
  local_c = &DAT_0000464f;
  local_5 = param_2;
  local_4 = param_1;
  sStack_e = hex2word();
  if (sStack_e != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    bStack_f = hex2byte();
    bStack_10 = hex2byte();
    bStack_11 = hex2byte();
    bStack_12 = hex2byte();
    bStack_11 = ~bStack_11;
    bStack_12 = ~bStack_12;
    if ((bStack_f == bStack_11) && (bStack_10 == bStack_12)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    sStack_e = CONCAT11(bStack_f,bStack_10);
    if (sStack_e == 0x306f) {
      sStack_e = -0x2cd3;
    }
    else if (sStack_e == -0x4a59) {
      sStack_e = -0x567d;
    }
    else if (sStack_e == -0x6309) {
      sStack_e = 0x7753;
    }
    else if (sStack_e == -0x5b3b) {
      sStack_e = -0x26b0;
    }
    else if (sStack_e == 0x50e2) {
      sStack_e = 0x315b;
    }
    *local_c = DAT_00020bb1;
    local_c[1] = DAT_00020bb2;
    local_c[2] = DAT_00020bb3;
    local_c[3] = DAT_00020bb4;
    local_c[4] = DAT_00020bb5;
    dest_code_set(sStack_e);
    return;
  }
  sStack_e = dest_code_get();
  bStack_f = (byte)((ushort)sStack_e >> 8);
  bStack_10 = (byte)sStack_e;
  byte2hex(&uStack_14,bStack_f);
  DAT_00001c93._1_1_ = uStack_14;
  DAT_00001c93._2_1_ = uStack_13;
  byte2hex(&uStack_14,bStack_10);
  DAT_00001c93._3_1_ = uStack_14;
  DAT_00001c97 = uStack_13;
  byte2hex(&uStack_14,~bStack_f);
  DAT_00001c98 = uStack_14;
  DAT_00001c99 = uStack_13;
  byte2hex(&uStack_14,~bStack_10);
  uRam00001c9a = uStack_14;
  uRam00001c9b = uStack_13;
  byte2hex(&uStack_14,*local_c);
  DAT_00001c9c = uStack_14;
  DAT_00001c9d = uStack_13;
  byte2hex(&uStack_14,local_c[1]);
  uRam00001c9e = uStack_14;
  uRam00001c9f = uStack_13;
  byte2hex(&uStack_14,local_c[2]);
  DAT_00001ca0 = uStack_14;
  DAT_00001ca1 = uStack_13;
  byte2hex(&uStack_14,local_c[3]);
  DAT_00001ca2 = uStack_14;
  DAT_00001ca3 = uStack_13;
  byte2hex(&uStack_14,local_c[4]);
  DAT_00001ca4 = uStack_14;
  DAT_00001ca5 = uStack_13;
  DAT_00001ca6 = 0x3b;
  DAT_0001b788 = 0x19;
  return;
}


// ===== cat_ext_ZZ @ fffa58a1 (228 bytes)

void cat_ext_ZZ(int param_1)

{
  undefined2 uVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  char local_9;
  char cStack_8;
  byte local_7;
  
  uVar1 = *(undefined2 *)(param_1 + 2);
  for (local_7 = 0; local_7 < 2; local_7 = local_7 + 1) {
    toupper_inplace();
  }
  local_9 = (char)uVar1;
  if ((local_9 == 'P') && (cStack_8 = (char)((ushort)uVar1 >> 8), cStack_8 == 'E')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    DAT_0000464a = 1;
    return;
  }
  sVar4 = hex2word();
  if (sVar4 != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  cVar3 = hex2byte();
  if (cVar3 != -0x67) {
    if (cVar3 == '\x01') {
      settings_defaults(0);
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x11;
      return;
    }
    if (cVar3 == '\0') {
      DAT_00020bbe = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  settings_defaults(1);
  eeprom_save_cfg105();
  eeprom_save_dest();
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== cat_ext_E9 @ fffa5985 (204 bytes)

/* Extended E9, reached only from the second input path in cat_parse */

void cat_ext_E9(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  char local_e;
  ushort local_c;
  
  bVar1 = *(byte *)(param_1 + 2);
  bVar2 = *(byte *)(param_1 + 3);
  bVar3 = *(byte *)(param_1 + 4);
  local_e = '\0';
  for (local_c = 0; local_c < 0x29a9; local_c = local_c + 1) {
    *(byte *)(local_c + 7 + param_1) = *(char *)(local_c + 7 + param_1) - bVar1;
    local_e = *(char *)(local_c + 7 + param_1) + local_e;
  }
  if ((ushort)((ushort)bVar3 - (ushort)bVar1 & 0xff | ((ushort)bVar2 - (ushort)bVar1) * 0x100) ==
      0x790) {
    if ((byte)((&DAT_000029b0)[param_1] - bVar1) == local_e) {
      puVar4 = &DAT_000060c9;
      puVar5 = (undefined1 *)(param_1 + 7);
      for (puVar6 = &DAT_000029a9; puVar6 != (undefined *)0x0; puVar6 = puVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      eeprom_save_image();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ext_FD @ fffa5a51 (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5be8) */
/* WARNING: Removing unreachable block (ram,0xfffa5c39) */
/* WARNING: Removing unreachable block (ram,0xfffa5c76) */
/* WARNING: Removing unreachable block (ram,0xfffa5c51) */
/* WARNING: Removing unreachable block (ram,0xfffa5c81) */
/* WARNING: Removing unreachable block (ram,0xfffa5b46) */
/* WARNING: Removing unreachable block (ram,0xfffa5b0b) */
/* WARNING: Removing unreachable block (ram,0xfffa5ad6) */
/* WARNING: Removing unreachable block (ram,0xfffa5a94) */
/* WARNING: Removing unreachable block (ram,0xfffa5bb3) */
/* WARNING: Removing unreachable block (ram,0xfffa5c8d) */
/* WARNING: Removing unreachable block (ram,0xfffa5b7b) */
/* WARNING: Removing unreachable block (ram,0xfffa5bf4) */

undefined2 * cat_ext_FD(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined2 *puStack_1c;
  byte bStack_17;
  uint uStack_14;
  uint uStack_10;
  
  vfo_freq(0,2);
  band_of_freq();
  bVar1 = *(byte *)(param_1 + 4);
  if ((*(char *)(param_1 + 2) == '0') && (*(char *)(param_1 + 3) == '0')) {
    puStack_1c = (undefined2 *)0x0;
  }
  else {
    puStack_1c = (undefined2 *)0x1;
  }
  if (puStack_1c != (undefined2 *)0x0) {
    DAT_0000464a = 1;
    return puStack_1c;
  }
  puVar5 = (undefined2 *)(uint)bVar1;
  if (param_2 != '\0') {
    if (puVar5 != (undefined2 *)0x32) {
      DAT_0000464a = 1;
      return puVar5;
    }
    uStack_10 = 0;
    uStack_14 = 100000000;
    bStack_17 = 5;
    while( true ) {
      if (0xd < bStack_17) {
        iVar4 = freq_in_range(uStack_10);
        if (iVar4 != 0) {
          puVar5 = (undefined2 *)bandmem_set(2,uStack_10);
          return puVar5;
        }
        DAT_0000464a = 1;
        return (undefined2 *)0x0;
      }
      if ((*(byte *)((uint)bStack_17 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_17 + param_1))) {
        puStack_1c = (undefined2 *)0x1;
      }
      else {
        puStack_1c = (undefined2 *)0x0;
      }
      if (puStack_1c != (undefined2 *)0x0) break;
      uStack_10 = (*(byte *)((uint)bStack_17 + param_1) & 0xf) * uStack_14 + uStack_10;
      uStack_14 = uStack_14 / 10;
      bStack_17 = bStack_17 + 1;
    }
    DAT_0000464a = 1;
    return puStack_1c;
  }
  if (puVar5 == (undefined2 *)0x30) {
    uStack_10 = DAT_00020f5c;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      uVar3 = uStack_10;
      if (uStack_14 != 0) {
        uVar3 = uStack_10 / uStack_14;
      }
      uVar6 = uStack_10;
      if ((uStack_14 & 0xff) != 0) {
        uVar6 = uStack_10 / (uStack_14 & 0xff);
      }
      uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
      uStack_14 = uStack_14 / 10;
      uVar2 = nib2hex(uVar3 & 0xff);
      *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return &DAT_00001c8e;
  }
  if (bVar1 == 0x31) {
    uStack_10 = DAT_00020f60;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      uVar3 = uStack_10;
      if (uStack_14 != 0) {
        uVar3 = uStack_10 / uStack_14;
      }
      uVar6 = uStack_10;
      if ((uStack_14 & 0xff) != 0) {
        uVar6 = uStack_10 / (uStack_14 & 0xff);
      }
      uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
      uStack_14 = uStack_14 / 10;
      uVar2 = nib2hex(uVar3 & 0xff);
      *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return &DAT_00001c8e;
  }
  if ((undefined2 *)(uint)bVar1 != (undefined2 *)0x32) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)bVar1;
  }
  uStack_10 = bandmem_get(2);
  uStack_14 = 100000000;
  for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
    uVar3 = uStack_10;
    if (uStack_14 != 0) {
      uVar3 = uStack_10 / uStack_14;
    }
    uVar6 = uStack_10;
    if ((uStack_14 & 0xff) != 0) {
      uVar6 = uStack_10 / (uStack_14 & 0xff);
    }
    uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
    uStack_14 = uStack_14 / 10;
    uVar2 = nib2hex(uVar3 & 0xff);
    *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
  }
  DAT_00001c9c = 0x3b;
  DAT_0001b788 = 0xf;
  return &DAT_00001c8e;
}


// ===== cat_ext_EO @ fffa5c90 (847 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5d68) */
/* WARNING: Removing unreachable block (ram,0xfffa5e8a) */
/* WARNING: Removing unreachable block (ram,0xfffa5f4e) */

void cat_ext_EO(int param_1)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  short in_stack_00000044;
  undefined *puStack_18;
  uint uStack_14;
  ushort uStack_e;
  byte bStack_8;
  byte bStack_6;
  
  iVar5 = vfo_rec_ptr(0);
  bVar2 = hex2nib(*(undefined1 *)(param_1 + 2));
  if (2 < bVar2) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00020f3b = 0;
  DAT_00020b8a = 0;
  DAT_00020b99 = 0;
  DAT_00020bbe = 0;
  DAT_00020b97 = 0;
  DAT_00020b98 = 0;
  DAT_00020b9a = 0;
  DAT_00020b9b = 0;
  if (*(char *)(param_1 + 3) == '0') {
    uVar6 = vfo_freq(0,2);
    uStack_e = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      bVar2 = *(byte *)((uint)bStack_8 + param_1);
      if ((bVar2 < 0x30) || (0x39 < bVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      sVar4 = hex2nib(bVar2);
      uStack_e = sVar4 * in_stack_00000044 + uStack_e;
    }
    if (*(char *)(param_1 + 5) == '0') {
      uStack_14 = (uint)uStack_e;
    }
    else if (*(char *)(param_1 + 5) == '1') {
      uStack_14 = (uint)uStack_e * 1000;
    }
    else if (*(char *)(param_1 + 5) == '2') {
      uStack_14 = (uint)uStack_e * 1000000;
    }
    if (*(char *)(param_1 + 4) == '+') {
      puStack_18 = (undefined *)(uVar6 + uStack_14);
    }
    else {
      if (*(char *)(param_1 + 4) != '-') {
        DAT_0000464a = 1;
        return;
      }
      if (uVar6 < uStack_14) {
        puStack_18 = (undefined *)0x0;
      }
      else {
        puStack_18 = (undefined *)(uVar6 - uStack_14);
      }
    }
    if (puStack_18 < &DAT_00007530) {
      puStack_18 = &DAT_00007530;
    }
    else if ((undefined *)0x47868c0 < puStack_18) {
      puStack_18 = (undefined *)0x47868c0;
    }
    for (bStack_8 = 0; bStack_8 < 4; bStack_8 = bStack_8 + 1) {
      *(char *)((uint)bStack_8 + iVar5 + 0x4a) =
           (char)((uint)puStack_18 >> ((3 - bStack_8 & 3) << 3));
    }
  }
  else if (*(char *)(param_1 + 3) == '1') {
    bStack_6 = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = hex2nib(*(undefined1 *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * (char)in_stack_00000044 + bStack_6;
    }
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      enc2_step((int)(char)bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      enc2_step((int)(char)(~bStack_6 + 1));
    }
  }
  else if (*(char *)(param_1 + 3) == '2') {
    bStack_6 = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = hex2nib(*(undefined1 *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * (char)in_stack_00000044 + bStack_6;
    }
    DAT_00020f3b = 0;
    DAT_00020bbe = 0;
    DAT_00020b74 = 1;
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      enc3_step((int)(char)bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      enc3_step((int)(char)(~bStack_6 + 1));
    }
  }
  DAT_00020f10 = 1;
  return;
}


// ===== cat_ext_PE @ fffa5fdf (1166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6276) */
/* WARNING: Removing unreachable block (ram,0xfffa646a) */
/* WARNING: Removing unreachable block (ram,0xfffa6400) */
/* WARNING: Removing unreachable block (ram,0xfffa6390) */
/* WARNING: Removing unreachable block (ram,0xfffa62d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6378) */
/* WARNING: Removing unreachable block (ram,0xfffa63e8) */
/* WARNING: Removing unreachable block (ram,0xfffa6224) */
/* WARNING: Removing unreachable block (ram,0xfffa6467) */
/* WARNING: Removing unreachable block (ram,0xfffa6327) */

int cat_ext_PE(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_R14;
  byte bVar4;
  char in_stack_00000020;
  int local_18;
  byte *local_14;
  byte local_e;
  byte local_b;
  byte local_a;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ada;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009adb;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adc;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009add;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ade;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adf;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae0;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae1;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae2;
      }
    }
  }
  if (*(char *)(param_1 + 2) == '2') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae3;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae4;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae5;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae6;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae7;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae8;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae9;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009aea;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009aeb;
      }
    }
  }
  if (*(char *)(param_1 + 4) == '0') {
    *in_R14 = 1;
  }
  if (param_2 == '\0') {
    if ((in_R14 == (undefined4 *)0x0) && (*(char *)(param_1 + 4) != '2')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_a = 100;
      local_e = *local_14;
      iVar3 = 0;
      for (local_b = 0; local_b < 3; local_b = local_b + 1) {
        bVar4 = local_e;
        if (local_a != 0) {
          bVar4 = local_e / local_a;
        }
        local_e = local_e - bVar4 * local_a;
        local_a = local_a / 10;
        iVar3 = nib2hex(bVar4);
        *(char *)((int)&DAT_00001c93 + (uint)local_b) = (char)iVar3;
      }
      *(undefined1 *)((int)&DAT_00001c93 + (uint)local_b) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 5;
      return iVar3;
    }
    if (*(char *)(param_1 + 4) == '1') {
      local_e = *local_14;
      if ((local_e & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        local_e = ~local_e + 1;
      }
      local_a = 10;
      iVar3 = 0;
      for (local_b = 0; local_b < 2; local_b = local_b + 1) {
        bVar4 = local_e;
        if (local_a != 0) {
          bVar4 = local_e / local_a;
        }
        local_e = local_e - bVar4 * local_a;
        local_a = local_a / 10;
        iVar3 = nib2hex(bVar4);
        *(char *)((int)&DAT_00001c93 + local_b + 1) = (char)iVar3;
      }
      *(undefined1 *)((int)&DAT_00001c93 + local_b + 1) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 6;
      return iVar3;
    }
  }
  else {
    if ((in_R14 == (undefined4 *)0x0) && (*(char *)(param_1 + 4) != '2')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      for (local_b = 5; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          local_18 = 1;
        }
        else {
          local_18 = 0;
        }
        if (local_18 != 0) {
          DAT_0000464a = 1;
          return local_18;
        }
        cVar2 = hex2nib(*(undefined1 *)((uint)local_b + param_1));
        local_e = cVar2 * in_stack_00000020 + local_e;
      }
      *local_14 = local_e;
    }
    else if (*(char *)(param_1 + 4) == '1') {
      for (local_b = 6; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          local_18 = 1;
        }
        else {
          local_18 = 0;
        }
        if (local_18 != 0) {
          DAT_0000464a = 1;
          return local_18;
        }
        cVar2 = hex2nib(*(undefined1 *)((uint)local_b + param_1));
        local_e = cVar2 * in_stack_00000020 + local_e;
      }
      if (*(char *)(param_1 + 5) == '-') {
        local_e = ~local_e + 1;
      }
      *local_14 = local_e;
    }
    if ((DAT_00020b20 == '\x01') || (DAT_00020b21 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b22 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      iVar3 = cat_ai_holdoff();
      return iVar3;
    }
  }
  return 0;
}


// ===== cat_AB @ fffa646d (359 bytes)

void cat_AB(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    iVar2 = vfo_tune_locked(1);
    if (iVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbf = 1;
    puVar4 = &DAT_00009d09;
    puVar3 = &DAT_00009d63;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_mark_edited(1);
    vfo_store_back(1);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AC @ fffa65d4 (659 bytes)

void cat_AC(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  vfo_rec_ptr(0);
  cVar3 = DAT_00009ab8;
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    if (DAT_00009ab8 == '\x03') {
      DAT_00001c91 = 0x32;
      if (DAT_00020f0c == '\0') {
        DAT_00001c92 = 0x30;
      }
      else if (DAT_00020f0c == '\x02') {
        if (DAT_00020b3c == '\x02') {
          DAT_00001c92 = 0x31;
        }
        else if (DAT_00020b3c == '\x03') {
          DAT_00001c92 = 0x32;
        }
      }
      else if (DAT_00020f0c == '\x01') {
        DAT_00001c92 = 0x33;
      }
    }
    else {
      DAT_00001c91 = 0x30;
      if (DAT_00020b41 == '\x02') {
        DAT_00001c92 = 0x33;
      }
      else {
        FUN_fffec55a();
        DAT_00001c92 = nib2hex();
      }
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    iVar4 = key_event_filter(0x301,0);
    if (iVar4 == 0) {
      DAT_0000464a = 1;
      return;
    }
    cVar1 = *(char *)(param_1 + 3);
    if (cVar1 == '2') {
      if (cVar3 != '\x03') {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(param_1 + 4) == '0') {
        FUN_fffed24e(0);
      }
      else if (*(char *)(param_1 + 4) == '1') {
        FUN_fffed206(2);
        FUN_fffed24e(1);
      }
      else if (*(char *)(param_1 + 4) == '2') {
        FUN_fffed206(2);
        FUN_fffed24e(2);
      }
      else {
        if (*(char *)(param_1 + 4) != '3') {
          DAT_0000464a = 1;
          return;
        }
        FUN_fffed206(1);
      }
    }
    else if (cVar1 != '1') {
      if (cVar1 == '0') {
        if ((cVar3 == '\0') || (cVar3 == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 3;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 1;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            if (DAT_00020b3d == '\0') {
              DAT_00020b41 = '\x01';
            }
          }
        }
        else {
          if (cVar3 != '\x02') {
            DAT_0000464a = 1;
            return;
          }
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 6;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 4;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            DAT_00020b40 = 1;
          }
        }
      }
      else {
        DAT_0000464a = 1;
      }
    }
    FUN_fffe6e26();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AG @ fffa6867 (223 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa68d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6927) */
/* WARNING: Removing unreachable block (ram,0xfffa6911) */
/* WARNING: Removing unreachable block (ram,0xfffa68a1) */
/* WARNING: Removing unreachable block (ram,0xfffa6943) */

undefined2 * cat_AG(int param_1,char param_2)

{
  undefined1 uVar1;
  byte bVar2;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00020ba8;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar2 = local_d;
      if (local_b != 0) {
        bVar2 = local_d / local_b;
      }
      local_d = local_d - bVar2 * local_b;
      local_b = local_b / 10;
      uVar1 = nib2hex(bVar2);
      (&DAT_00001c91)[local_c] = uVar1;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  local_d = '\0';
  local_c = 3;
  while( true ) {
    if ((undefined2 *)0x5 < (undefined2 *)(uint)local_c) {
      DAT_00020ba8 = local_d;
      return (undefined2 *)(uint)local_c;
    }
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) break;
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
    local_c = local_c + 1;
  }
  DAT_0000464a = 1;
  return local_14;
}


// ===== cat_AI @ fffa6946 (224 bytes)

void cat_AI(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (DAT_0000464c == '\x03') {
      DAT_00001c90 = nib2hex(DAT_00020b22);
    }
    else if (DAT_0000464c == '\x02') {
      DAT_00001c90 = nib2hex(DAT_00020b21);
    }
    else if (DAT_0000464c == '\x01') {
      DAT_00001c90 = nib2hex(DAT_00020b20);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (0x31 < *(byte *)(param_1 + 2)) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_0000464c == '\x03') {
    DAT_00020b22 = hex2nib(*(undefined1 *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x02') {
    DAT_00020b21 = hex2nib(*(undefined1 *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x01') {
    DAT_00020b20 = hex2nib(*(undefined1 *)(param_1 + 2));
  }
  if (*(char *)(param_1 + 2) == '1') {
    cat_ai_holdoff();
    return;
  }
  return;
}


// ===== cat_AM @ fffa6a26 (329 bytes)

void cat_AM(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  bVar2 = DAT_000060c9;
  puVar4 = &DAT_00006150 + (uint)DAT_000060c9 * 0x5a;
  puVar3 = (undefined1 *)
           ((int)&DAT_00004761 +
           (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438);
  if ((DAT_000060c9 < 0x75) || (0x84 < DAT_000060c9)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbe == '\x01') {
      puVar3 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x04') {
      vm_toggle();
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x03') {
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbe == '\x05') {
        for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        eeprom_save_memch(bVar2);
        return;
      }
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    vfo_mark_edited(DAT_00009dbd);
    vfo_store_back(DAT_00009dbd);
    DAT_00020f10 = 1;
    eeprom_save_memch(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AO @ fffa6b6f (302 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6bdf) */
/* WARNING: Removing unreachable block (ram,0xfffa6c30) */
/* WARNING: Removing unreachable block (ram,0xfffa6c97) */
/* WARNING: Removing unreachable block (ram,0xfffa6c8b) */
/* WARNING: Removing unreachable block (ram,0xfffa6c1a) */
/* WARNING: Removing unreachable block (ram,0xfffa6baa) */
/* WARNING: Removing unreachable block (ram,0xfffa6c9a) */

undefined2 * cat_AO(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00009bf2;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = nib2hex(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
  }
  if ((local_d == 0) || (100 < local_d)) {
    local_14 = (undefined2 *)0x0;
  }
  else {
    local_14 = (undefined2 *)0x1;
  }
  if (local_14 != (undefined2 *)0x0) {
    DAT_00009bf2 = local_d;
    if (DAT_00009ace != '\0') {
      return local_14;
    }
    DAT_00020cc6 = 0x28;
    FUN_fffc8cbb(0x28);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_AS @ fffa6c9d (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6d9c) */
/* WARNING: Removing unreachable block (ram,0xfffa6ddc) */
/* WARNING: Removing unreachable block (ram,0xfffa6e46) */
/* WARNING: Removing unreachable block (ram,0xfffa6e3a) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed9) */
/* WARNING: Removing unreachable block (ram,0xfffa6df2) */
/* WARNING: Removing unreachable block (ram,0xfffa6e0d) */
/* WARNING: Removing unreachable block (ram,0xfffa6ea3) */
/* WARNING: Removing unreachable block (ram,0xfffa6eca) */
/* WARNING: Removing unreachable block (ram,0xfffa6e79) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed6) */
/* WARNING: Removing unreachable block (ram,0xfffa6cf7) */
/* WARNING: Removing unreachable block (ram,0xfffa6d86) */

char * cat_AS(int param_1,char param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *extraout_R14;
  byte bVar4;
  char in_stack_00000028;
  char *pcStack_1c;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  
  pcVar1 = (char *)FUN_fffb54a0();
  pcVar2 = (char *)FUN_fffb552c();
  if (*(char *)(param_1 + 2) == '1') {
    *extraout_R14 = 1;
  }
  if (param_2 == '\0') {
    pcVar3 = (char *)0x0;
    if (extraout_R14 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '2') {
        DAT_0000464a = 1;
        return (char *)0x0;
      }
      if (*pcVar2 == '\0') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x31;
      }
      else if (*pcVar2 == '\x01') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x32;
      }
    }
    else {
      bStack_d = *pcVar1 * '\x05';
      bStack_b = 100;
      for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
        bVar4 = bStack_d;
        if (bStack_b != 0) {
          bVar4 = bStack_d / bStack_b;
        }
        bStack_d = bStack_d - bVar4 * bStack_b;
        bStack_b = bStack_b / 10;
        pcVar3 = (char *)nib2hex(bVar4);
        (&DAT_00001c91)[bStack_c] = (char)pcVar3;
      }
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return pcVar3;
  }
  if (extraout_R14 == (undefined4 *)0x0) {
    if ((char *)(uint)*(byte *)(param_1 + 2) != (char *)0x32) {
      DAT_0000464a = 1;
      return (char *)(uint)*(byte *)(param_1 + 2);
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      pcStack_1c = (char *)0x0;
    }
    else {
      pcStack_1c = (char *)0x1;
    }
    if (pcStack_1c != (char *)0x0) {
      DAT_0000464a = 1;
      return pcStack_1c;
    }
    if (*(char *)(param_1 + 5) == '1') {
      *pcVar2 = '\0';
    }
    else {
      if ((char *)(uint)*(byte *)(param_1 + 5) != (char *)0x32) {
        DAT_0000464a = 1;
        return (char *)(uint)*(byte *)(param_1 + 5);
      }
      *pcVar2 = '\x01';
    }
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x58;
      FUN_fffc8cbb(0x58);
      pcVar1 = (char *)FUN_fffc8d8c();
      return pcVar1;
    }
  }
  else {
    bStack_d = 0;
    for (bStack_c = 3; bStack_c < 6; bStack_c = bStack_c + 1) {
      if ((*(byte *)((uint)bStack_c + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_c + param_1))) {
        pcStack_1c = (char *)0x1;
      }
      else {
        pcStack_1c = (char *)0x0;
      }
      if (pcStack_1c != (char *)0x0) {
        DAT_0000464a = 1;
        return pcStack_1c;
      }
      bStack_d = (*(byte *)((uint)bStack_c + param_1) & 0xf) * in_stack_00000028 + bStack_d;
    }
    if ((char *)0x64 < (char *)(uint)bStack_d) {
      DAT_0000464a = 1;
      return (char *)(uint)bStack_d;
    }
    pcVar2 = (char *)(bStack_d / 5);
    *pcVar1 = (char)pcVar2;
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x33;
      FUN_fffc8cbb(0x33);
      pcVar1 = (char *)FUN_fffc8d8c();
      return pcVar1;
    }
  }
  return pcVar2;
}


// ===== cat_AV @ fffa6edc (316 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6fa3) */
/* WARNING: Removing unreachable block (ram,0xfffa6f68) */
/* WARNING: Removing unreachable block (ram,0xfffa7015) */
/* WARNING: Removing unreachable block (ram,0xfffa7012) */
/* WARNING: Removing unreachable block (ram,0xfffa6fb9) */
/* WARNING: Removing unreachable block (ram,0xfffa7006) */
/* WARNING: Removing unreachable block (ram,0xfffa6f33) */

undefined2 * cat_AV(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000008;
  undefined2 *local_1c;
  byte local_15;
  byte local_14;
  byte local_13;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_15 = DAT_00009bf6;
    }
    else {
      local_15 = DAT_00009bf7;
    }
    local_13 = 100;
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      bVar3 = local_15;
      if (local_13 != 0) {
        bVar3 = local_15 / local_13;
      }
      local_15 = local_15 - bVar3 * local_13;
      local_13 = local_13 / 10;
      uVar1 = nib2hex(bVar3);
      (&DAT_00001c90)[local_14] = uVar1;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  local_15 = 0;
  for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
    if ((*(byte *)((uint)local_14 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_14 + param_1))
       ) {
      local_1c = (undefined2 *)0x1;
    }
    else {
      local_1c = (undefined2 *)0x0;
    }
    if (local_1c != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_1c;
    }
    local_15 = (*(byte *)((uint)local_14 + param_1) & 0xf) * in_stack_00000008 + local_15;
  }
  if ((undefined2 *)0x64 < (undefined2 *)(uint)local_15) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)local_15;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf6 = local_15;
  }
  else {
    DAT_00009bf7 = local_15;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2b;
    FUN_fffc8cbb(0x2b);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return (undefined2 *)&DAT_00009bca;
}


// ===== cat_BA @ fffa7018 (359 bytes)

void cat_BA(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    iVar2 = vfo_tune_locked(0);
    if (iVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbe = 1;
    puVar4 = &DAT_00009d63;
    puVar3 = &DAT_00009d09;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_mark_edited(0);
    vfo_store_back(0);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_BC @ fffa717f (346 bytes)

void cat_BC(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbStack_14;
  byte bStack_e;
  
  iVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x15);
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x33);
    }
    else {
      if (uVar1 - 6 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 8) {
        if (uVar1 - 10 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 - 0xc < 2) {
          bStack_e = *(byte *)(iVar4 + 0x1f);
          goto LAB_fffa7214;
        }
        if (uVar1 != 0xe) {
          bStack_e = *(byte *)(iVar4 + 0xb);
          goto LAB_fffa7214;
        }
      }
      bStack_e = *(byte *)(iVar4 + 0x29);
    }
LAB_fffa7214:
    DAT_00001c90 = 0x30;
    if ((bStack_e & 0x80) == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x15);
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x33);
  }
  else {
    if (uVar1 - 6 < 2) {
      DAT_0000464a = 1;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (uVar1 - 0xc < 2) {
        pbStack_14 = (byte *)(iVar4 + 0x1f);
        goto LAB_fffa72ae;
      }
      if (uVar1 != 0xe) {
        pbStack_14 = (byte *)(iVar4 + 0xb);
        goto LAB_fffa72ae;
      }
    }
    pbStack_14 = (byte *)(iVar4 + 0x29);
  }
LAB_fffa72ae:
  cVar3 = hex2nib(*(undefined1 *)(param_1 + 3));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0x7f;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 0x80;
  return;
}


// ===== cat_BD @ fffa72d9 (659 bytes)

void cat_BD(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_d;
  byte bStack_5;
  
  cVar2 = DAT_00009dbd;
  if (DAT_00020f1c == '\x01') {
    puVar4 = (undefined4 *)0x1;
  }
  else {
    puVar4 = (undefined4 *)(uint)DAT_00020f70;
    if (puVar4 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffa730b;
    }
  }
  bVar1 = true;
LAB_fffa730b:
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f0c, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b8a, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b3d, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cce, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f1b, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020ccd, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b7c, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cd0, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cd1, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f11, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    *puVar4 = 1;
  }
  if (cVar2 == '\0') {
    if (puVar4 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
    else {
      local_d = 0;
    }
  }
  else if (puVar4 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  else {
    local_d = 1;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((cVar2 == '\0') && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((cVar2 == '\x01') && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  uVar3 = vfo_freq(0,local_d);
  bStack_5 = band_of_freq(uVar3);
  if (0xb < bStack_5) {
    bStack_5 = 0xb;
  }
  if (bStack_5 == 0) {
    bStack_5 = '\v';
  }
  else if (bStack_5 < 0xc) {
    bStack_5 = bStack_5 - 1;
  }
  else {
    bStack_5 = '\v';
  }
  if (*(char *)(param_1 + 2) == '0') {
    band_select_on(bStack_5,cVar2);
    return;
  }
  band_select_on(bStack_5,local_d);
  return;
}


// ===== cat_BU @ fffa756c (640 bytes)

void cat_BU(int param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_d;
  char cStack_5;
  
  cVar2 = DAT_00009dbd;
  if (DAT_00020f1c == '\x01') {
    puVar5 = (undefined4 *)0x1;
  }
  else {
    puVar5 = (undefined4 *)(uint)DAT_00020f70;
    if (puVar5 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffa759e;
    }
  }
  bVar1 = true;
LAB_fffa759e:
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f0c, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b8a, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b3d, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cce, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f1b, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020ccd, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b7c, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cd0, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cd1, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f11, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    *puVar5 = 1;
  }
  if (cVar2 == '\0') {
    if (puVar5 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
    else {
      local_d = 0;
    }
  }
  else if (puVar5 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  else {
    local_d = 1;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((cVar2 == '\0') && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((cVar2 == '\x01') && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  uVar4 = vfo_freq(0,local_d);
  bVar3 = band_of_freq(uVar4);
  if (bVar3 < 0xb) {
    cStack_5 = bVar3 + 1;
  }
  else {
    cStack_5 = '\0';
  }
  if (*(char *)(param_1 + 2) == '0') {
    band_select_on(cStack_5,cVar2);
    return;
  }
  band_select_on(cStack_5,local_d);
  return;
}


// ===== cat_BI @ fffa77ec (316 bytes)

void cat_BI(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbStack_14;
  byte bStack_e;
  
  iVar4 = vfo_rec_ptr(1);
  bVar2 = vfo_mode(1);
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x14);
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x32);
    }
    else {
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            DAT_0000464a = 1;
            return;
          }
          if (uVar1 == 0xe) {
            DAT_0000464a = 1;
            return;
          }
          bStack_e = *(byte *)(iVar4 + 10);
          goto LAB_fffa786d;
        }
      }
      bStack_e = *(byte *)(iVar4 + 0x3c);
    }
LAB_fffa786d:
    if ((bStack_e & 2) == 0) {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x14);
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x32);
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 == 0xe) {
          DAT_0000464a = 1;
          return;
        }
        pbStack_14 = (byte *)(iVar4 + 10);
        goto LAB_fffa78fd;
      }
    }
    pbStack_14 = (byte *)(iVar4 + 0x3c);
  }
LAB_fffa78fd:
  cVar3 = hex2nib(*(undefined1 *)(param_1 + 2));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0xfd;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 2;
  return;
}


// ===== cat_BM @ fffa7928 (329 bytes)

void cat_BM(void)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  int iVar7;
  
  bVar2 = DAT_000060ca;
  puVar4 = &DAT_00006150 + (uint)DAT_000060ca * 0x5a;
  puVar3 = &DAT_00005409 +
           (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438;
  if ((DAT_000060ca < 0x75) || (0x84 < DAT_000060ca)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbf == '\x01') {
      puVar5 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    else if (DAT_00009dbf == '\x04') {
      vm_toggle();
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbf == '\x03') {
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbf == '\x05') {
        for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        eeprom_save_memch(bVar2);
        return;
      }
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    vfo_mark_edited(DAT_00009dbd);
    vfo_store_back(DAT_00009dbd);
    DAT_00020f10 = 1;
    eeprom_save_memch(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}

