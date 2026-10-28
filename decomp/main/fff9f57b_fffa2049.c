// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
    dsp_send_frame(0x77);
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
    dsp_send_frame(0x77);
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
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_agc @ fff9f681 (1261 bytes)

/* reg 0x62 AGC on, reg 0x66 AGC delay (20n+20 ms; scan 200/40/4) */

void dsp_set_agc(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bStack_9;
  byte bStack_7;
  ushort uStack_6;
  
  iVar3 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  bStack_9 = 0;
  uVar4 = (uint)bVar2;
  if (uVar4 != 0xe) {
    if (uVar4 - 2 < 2) {
      bStack_7 = *(byte *)(iVar3 + 0x15);
      if ((bStack_7 & 0x40) != 0) {
        uVar4 = (bStack_7 & 0x30) >> 4;
        if (uVar4 == 3) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a96;
          }
          else {
            bStack_9 = DAT_00020b5d;
          }
        }
        else if (uVar4 == 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a95;
          }
          else {
            bStack_9 = DAT_00020b5c;
          }
        }
        else if (uVar4 < 2) {
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
    if (uVar4 - 4 < 2) {
      bStack_7 = *(byte *)(iVar3 + 0x33);
      if ((bStack_7 & 0x40) != 0) {
        uVar4 = (bStack_7 & 0x30) >> 4;
        if ((uVar4 == 0) || (uVar4 == 3)) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a44;
          }
          else {
            bStack_9 = DAT_00020b5d;
          }
        }
        else if (uVar4 == 2) {
          if (DAT_00009dc6 == '\0') {
            bStack_9 = DAT_00009a43;
          }
          else {
            bStack_9 = DAT_00020b5c;
          }
        }
        else if (uVar4 == 1) {
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
    if (1 < uVar4 - 8) {
      if (uVar4 - 0xc < 2) {
        bStack_7 = *(byte *)(iVar3 + 0x1f);
        if ((bStack_7 & 0x40) != 0) {
          uVar4 = (bStack_7 & 0x30) >> 4;
          if (uVar4 != 0) {
            if (uVar4 == 3) {
              if (DAT_00009dc6 == '\0') {
                bStack_9 = DAT_00009a83;
              }
              else {
                bStack_9 = DAT_00020b5d;
              }
              goto LAB_fff9fa98;
            }
            if (uVar4 != 2) {
              if (uVar4 == 1) {
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
      else if (uVar4 < 2) {
        bStack_7 = *(byte *)(iVar3 + 0xb);
        if ((bStack_7 & 0x40) != 0) {
          uVar4 = (bStack_7 & 0x30) >> 4;
          if ((uVar4 == 0) || (uVar4 == 3)) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a2f;
            }
            else {
              bStack_9 = DAT_00020b5d;
            }
          }
          else if (uVar4 == 2) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a2e;
            }
            else {
              bStack_9 = DAT_00020b5c;
            }
          }
          else if (uVar4 == 1) {
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
        bStack_7 = *(byte *)(iVar3 + 0x3d);
        if ((bStack_7 & 0x40) != 0) {
          uVar4 = (bStack_7 & 0x30) >> 4;
          if (uVar4 == 3) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a57;
            }
            else {
              bStack_9 = DAT_00020b5d;
            }
          }
          else if (uVar4 == 2) {
            if (DAT_00009dc6 == '\0') {
              bStack_9 = DAT_00009a56;
            }
            else {
              bStack_9 = DAT_00020b5c;
            }
          }
          else if (uVar4 < 2) {
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
  bStack_7 = *(byte *)(iVar3 + 0x29);
  if ((bStack_7 & 0x40) == 0) goto LAB_fff9fa98;
  uVar4 = (bStack_7 & 0x30) >> 4;
  if (uVar4 != 0) {
    if (uVar4 == 3) {
      if (DAT_00009dc6 == '\0') {
        bStack_9 = DAT_00009a6c;
      }
      else {
        bStack_9 = DAT_00020b5d;
      }
      goto LAB_fff9fa98;
    }
    if (uVar4 != 2) {
      if (uVar4 == 1) {
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
  iVar3 = swtimer_expired(0x2a);
  if (iVar3 == 0) {
    uStack_6 = 1;
  }
  if (DAT_0001b6c2 != uStack_6) {
    DAT_0001b6de = 0x62;
    DAT_0001b6e0 = uStack_6;
    dsp_send_frame(0x77);
    return;
  }
  iVar3 = swtimer_expired(0x2a);
  if (iVar3 == 0) {
    bStack_9 = 0;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f6f == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar3 = vfo_is_memory(DAT_00009dbd);
    if (iVar3 == 1) {
      uStack_6 = 200;
    }
    else {
      uVar4 = (uint)bVar2;
      if ((uVar4 - 4 < 4) || (uVar4 == 10 || uVar4 == 0xb)) {
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
  dsp_send_frame(0x77);
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
      dsp_send_frame(0x77);
      return;
    }
    if (uVar1 <= (*(uint *)(&dsp_freq_ranges + (uint)bStack_7 * 4) & 0xff)) {
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
  int iVar1;
  ushort local_2;
  
  local_2 = (ushort)(byte)(&DAT_fff805ac)[DAT_00020ba7 >> 2];
  if (DAT_00009ab6 == '\x01') {
    local_2 = 0xff;
  }
  else if ((DAT_00009ab6 == '\x02') &&
          ((iVar1 = vfo_mode(0), iVar1 - 6U < 2 || (iVar1 == 10 || iVar1 == 0xb)))) {
    local_2 = 0xff;
  }
  if (DAT_0001b6cc != local_2) {
    DAT_0001b6de = 0x67;
    DAT_0001b6e0 = local_2;
    dsp_send_frame(0x77);
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
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_400b @ fff9fcd0 (129 bytes)

/* reg 0x400B: DNR table by level */

void dsp_set_dnr_400b(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f1a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6d0 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x400b;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_400d @ fff9fd51 (129 bytes)

/* reg 0x400D: DNR table by level */

void dsp_set_dnr_400d(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f3a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6d2 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x400d;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
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
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_4022 @ fff9fe2a (133 bytes)

/* reg 0x4022: DNR table by level */

void dsp_set_dnr_4022(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((bVar1 & 0x10) == 0) {
    sStack_a = 0;
  }
  else if ((1 < bVar2 - 6) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f5a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6d6 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4022;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_4023 @ fff9feaf (129 bytes)

/* reg 0x4023: DNR table by level */

void dsp_set_dnr_4023(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f7a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6d8 == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4023;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_4025 @ fff9ff30 (129 bytes)

/* reg 0x4025: DNR table by level */

void dsp_set_dnr_4025(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f9a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6da == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4025;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_set_dnr_4026 @ fff9ffb1 (129 bytes)

/* reg 0x4026: DNR table by level (all zero) */

void dsp_set_dnr_4026(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = vfo_rec_ptr(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = vfo_mode(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87fda + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6dc == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4026;
  DAT_0001b6e0 = sStack_a;
  dsp_send_frame(0x77);
  return;
}


// ===== dsp_status1_filter @ fffa0032 (270 bytes)

/* reg1: bit6 debounced over 5 polls -> 0x1C61; in RX (0x20B18==8) high byte averaged over 2 ->
   0x1C60 */

void dsp_status1_filter(void)

{
  ushort uVar1;
  char local_6;
  byte local_5;
  ushort local_4;
  
  uVar1 = DAT_0001b636;
  if (DAT_00020b18 == '\b') {
    (&DAT_00001c64)[DAT_00001c66] = (char)(DAT_0001b636 >> 8);
    DAT_00001c66 = DAT_00001c66 + 1;
    if (1 < DAT_00001c66) {
      DAT_00001c66 = 0;
    }
    local_4 = 0;
    for (local_5 = 0; local_5 < 2; local_5 = local_5 + 1) {
      local_4 = (byte)(&DAT_00001c64)[local_5] + local_4;
    }
    DAT_00001c60 = (undefined1)(local_4 >> 1);
  }
  if ((uVar1 & 0x40) == 0) {
    (&DAT_00001c67)[DAT_00001c6c] = 0;
  }
  else {
    (&DAT_00001c67)[DAT_00001c6c] = 1;
  }
  DAT_00001c6c = DAT_00001c6c + 1;
  if (4 < DAT_00001c6c) {
    DAT_00001c6c = 0;
  }
  local_6 = '\0';
  for (local_5 = 0; local_5 < 5; local_5 = local_5 + 1) {
    local_6 = (&DAT_00001c67)[local_5] + local_6;
  }
  if (local_6 == '\x05') {
    DAT_00001c61 = 1;
    return;
  }
  if (local_6 == '\0') {
    DAT_00001c61 = 0;
    return;
  }
  return;
}


// ===== dsp_status2_filter @ fffa0140 (178 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa01bf) */
/* WARNING: Removing unreachable block (ram,0xfffa019f) */
/* WARNING: Removing unreachable block (ram,0xfffa01c7) */
/* WARNING: Removing unreachable block (ram,0xfffa01de) */
/* reg2: 32-sample average of each byte -> 0x1B6E2 */

void dsp_status2_filter(void)

{
  byte local_5;
  ushort local_4;
  ushort local_2;
  
  *(undefined2 *)(&DAT_0001b6e6 + (uint)DAT_00001c6d * 2) = DAT_0001b638;
  DAT_00001c6d = DAT_00001c6d + 1;
  if (0x1f < DAT_00001c6d) {
    DAT_00001c6d = 0;
  }
  local_4 = 0;
  local_2 = 0;
  for (local_5 = 0; local_5 < 0x20; local_5 = local_5 + 1) {
    local_2 = (*(ushort *)(&DAT_0001b6e6 + (uint)local_5 * 2) >> 8) + local_2;
    local_4 = (byte)(&DAT_0001b6e6)[(uint)local_5 * 2] + local_4;
  }
  DAT_0001b6e2 = local_2 / 0x20 << 8 | local_4 / 0x20;
  return;
}


// ===== dsp_status3_filter @ fffa01f2 (115 bytes)

/* reg3: 16-sample average of low byte -> 0x1C62 */

void dsp_status3_filter(void)

{
  byte local_3;
  ushort local_2;
  
  (&DAT_00001c6e)[DAT_00001c7e] = (char)DAT_0001b63a;
  DAT_00001c7e = DAT_00001c7e + 1;
  if (0xf < DAT_00001c7e) {
    DAT_00001c7e = 0;
  }
  local_2 = 0;
  for (local_3 = 0; local_3 < 0x10; local_3 = local_3 + 1) {
    local_2 = (byte)(&DAT_00001c6e)[local_3] + local_2;
  }
  DAT_00001c62 = (char)(local_2 >> 4);
  return;
}


// ===== dsp_status4_filter @ fffa0265 (277 bytes)

/* reg4: most frequent of last 8 samples -> 0x1B6E4 (100 if none repeats) */

void dsp_status4_filter(void)

{
  byte local_f [9];
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  ushort local_2;
  
  local_3 = 8;
  local_f[1] = 0;
  local_f[2] = 0;
  local_f[3] = 0;
  local_f[4] = 0;
  local_f[5] = 0;
  local_f[6] = 0;
  local_f[7] = 0;
  local_f[0] = 0;
  *(undefined2 *)(&DAT_0001b726 + (uint)DAT_0001b3db * 2) = DAT_0001b63c;
  DAT_0001b3db = DAT_0001b3db + 1;
  if (7 < DAT_0001b3db) {
    DAT_0001b3db = 0;
  }
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    local_2 = *(ushort *)(&DAT_0001b726 + (uint)local_4 * 2);
    local_6 = 0;
    if (local_2 != 0x7fff) {
      for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
        if (local_2 == (*(ushort *)(&DAT_0001b726 + (uint)local_5 * 2) & 0xff)) {
          local_6 = local_6 + 1;
        }
      }
    }
    local_f[local_4] = local_6;
  }
  local_6 = 0;
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
      if (local_6 < local_f[local_5]) {
        local_6 = local_f[local_5];
        local_f[8] = local_5;
      }
    }
  }
  if (local_6 < 2) {
    local_2 = 100;
  }
  else {
    local_2 = *(ushort *)(&DAT_0001b726 + (uint)local_f[8] * 2);
  }
  DAT_0001b6e4 = local_2;
  return;
}


// ===== dsp_shadow_store @ fffa037a (1884 bytes)

/* Store 0x1B6E0 into the shadow of register 0x1B6DE (table 0x1B634..0x1B6DD); regs 1-4 also run
   their status filters */

void dsp_shadow_store(void)

{
  if (DAT_0001b6de == 0) {
    DAT_0001b634 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 1) {
    DAT_0001b636 = DAT_0001b6e0;
    dsp_status1_filter();
    return;
  }
  if (DAT_0001b6de == 2) {
    DAT_0001b638 = DAT_0001b6e0;
    dsp_status2_filter();
    return;
  }
  if (DAT_0001b6de == 3) {
    DAT_0001b63a = DAT_0001b6e0;
    dsp_status3_filter();
    return;
  }
  if (DAT_0001b6de == 4) {
    DAT_0001b63c = DAT_0001b6e0;
    dsp_status4_filter();
    return;
  }
  if (DAT_0001b6de == 0x4026) {
    DAT_0001b6dc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 8) {
    DAT_0001b640 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 9) {
    DAT_0001b642 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 10) {
    DAT_0001b644 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xc) {
    DAT_0001b646 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xd) {
    DAT_0001b648 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xe) {
    DAT_0001b64a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xf) {
    DAT_0001b64c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x10) {
    DAT_0001b64e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x11) {
    DAT_0001b650 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x12) {
    DAT_0001b652 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x13) {
    DAT_0001b654 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x20) {
    DAT_0001b656 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x21) {
    DAT_0001b658 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x22) {
    DAT_0001b65a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x25) {
    DAT_0001b65c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x26) {
    DAT_0001b662 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x27) {
    DAT_0001b668 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x28) {
    DAT_0001b65e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x29) {
    DAT_0001b664 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2a) {
    DAT_0001b66a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2b) {
    DAT_0001b660 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2c) {
    DAT_0001b666 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2d) {
    DAT_0001b66c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2e) {
    DAT_0001b66e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2f) {
    DAT_0001b670 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x30) {
    DAT_0001b672 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x31) {
    DAT_0001b674 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x32) {
    DAT_0001b676 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x33) {
    DAT_0001b678 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x34) {
    DAT_0001b67a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x35) {
    DAT_0001b67c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x36) {
    DAT_0001b67e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x37) {
    DAT_0001b680 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x38) {
    DAT_0001b682 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3a) {
    DAT_0001b684 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3b) {
    DAT_0001b686 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x40) {
    DAT_0001b688 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x41) {
    DAT_0001b68a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x42) {
    DAT_0001b68c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x43) {
    DAT_0001b68e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x44) {
    DAT_0001b690 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x45) {
    DAT_0001b692 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x46) {
    DAT_0001b694 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x47) {
    DAT_0001b696 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x48) {
    DAT_0001b698 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x49) {
    DAT_0001b69e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4a) {
    DAT_0001b6a4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4b) {
    DAT_0001b69a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4c) {
    DAT_0001b6a0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4d) {
    DAT_0001b6a6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4e) {
    DAT_0001b69c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4f) {
    DAT_0001b6a2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x50) {
    DAT_0001b6a8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x51) {
    DAT_0001b6aa = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x52) {
    DAT_0001b6ac = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x53) {
    DAT_0001b6ae = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x54) {
    DAT_0001b6b0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x55) {
    DAT_0001b6b2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x56) {
    DAT_0001b6b4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x57) {
    DAT_0001b6b6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x58) {
    DAT_0001b6b8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5c) {
    DAT_0001b6ba = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5d) {
    DAT_0001b6bc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x60) {
    DAT_0001b6be = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x61) {
    DAT_0001b6c0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x62) {
    DAT_0001b6c2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 99) {
    DAT_0001b6c4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 100) {
    DAT_0001b6c6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x65) {
    DAT_0001b6c8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x66) {
    DAT_0001b6ca = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x67) {
    DAT_0001b6cc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x68) {
    DAT_0001b6ce = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400b) {
    DAT_0001b6d0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400d) {
    DAT_0001b6d2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4020) {
    DAT_0001b6d4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4022) {
    DAT_0001b6d6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4023) {
    DAT_0001b6d8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4025) {
    DAT_0001b6da = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de != 6) {
    return;
  }
  DAT_0001b63e = DAT_0001b6e0;
  return;
}


// ===== dsp_check_reply @ fffa0ad6 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0b49) */
/* Poll SCI4 reply: 'r'+4hex+2hex sum (read) or 0x06 (write ACK) -> 1; timer 3 expiry clears busy
   flags */

undefined1 dsp_check_reply(char param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_e;
  
  local_e = 0;
  iVar1 = sci4_rx_ready();
  if (iVar1 == 1) {
    uVar2 = sci4_rx_buf();
    *param_2 = uVar2;
    DAT_00001c5e = 0;
    DAT_00001c5f = 0;
    if (param_1 == 'r') {
      iVar1 = dsp_reply_sum_ok((char *)*param_2,5);
      if (iVar1 == 1) {
        local_e = 1;
      }
    }
    else if (*(char *)*param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    iVar1 = swtimer_expired(3);
    if (iVar1 == 1) {
      DAT_00001c5e = 0;
      DAT_00001c5f = 0;
    }
  }
  return local_e;
}


// ===== dsp_send_frame @ fffa0b4c (181 bytes)

/* Build "rAAAACC\r" / "wAAAADDDDCC\r" from 0x1B6DE/0x1B6E0 into 0x1A5E, send on SCI4, start 6 ms
   reply timer 3, set busy flag 0x1C5F/0x1C5E */

void dsp_send_frame(char param_1)

{
  undefined1 uVar1;
  byte local_2;
  
  DAT_00001a5e = param_1;
  word2hex(&DAT_00001a5f,DAT_0001b6de);
  local_2 = 5;
  if (param_1 == 'w') {
    word2hex(0x1a63,DAT_0001b6e0);
    local_2 = 9;
    DAT_00001c5e = 1;
  }
  else {
    DAT_00001c5f = 1;
  }
  uVar1 = dsp_sum8(&DAT_00001a5e,local_2);
  byte2hex(&DAT_00001a5e + local_2,uVar1);
  (&DAT_00001a5e)[(byte)(local_2 + 2)] = 0xd;
  sci4_send(&DAT_00001a5e,local_2 + 3);
  swtimer_start(3,6);
  return;
}


// ===== dsp_sum8 @ fffa0c01 (45 bytes)

/* 8-bit additive checksum over n bytes */

char dsp_sum8(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== dsp_reply_sum_ok @ fffa0c2e (75 bytes)

/* Checks the 2 hex checksum chars after n reply chars */

undefined1 dsp_reply_sum_ok(int param_1,byte param_2)

{
  undefined1 uVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uVar1 = dsp_sum8(param_1,param_2);
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


// ===== dsp_isp_bridge @ fffa0c79 (449 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0c79) */
/* WARNING: Removing unreachable block (ram,0xfffa0d7d) */
/* WARNING: Removing unreachable block (ram,0xfffa0da3) */
/* DSP firmware update: P71=0/P72=1 (ISP boot), ping 5A A6, then forward MCUBoot frames
   DISPLAY(SCI1) <-> DSP(SCI4) until DISPLAY sends F1 82; never returns to normal mode */

undefined4 dsp_isp_bridge(void)

{
  bool bVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined1 auStack_40c [516];
  char acStack_208 [516];
  
  sci4_send(&DAT_00001a5e,0);
  DAT_00001c63 = 0;
  dsp_reset_set(0);
  dsp_update_set(1);
  swtimer_start(0x1e,100);
  do {
    iVar4 = swtimer_expired(0x1e);
  } while (iVar4 != 1);
  dsp_reset_set(1);
  swtimer_start(0x1e,100);
  do {
    iVar4 = swtimer_expired(0x1e);
  } while (iVar4 != 1);
  DAT_00001a5e = 0x5a;
  DAT_00001a5f = 0xa6;
  sci4_send(&DAT_00001a5e,2);
  swtimer_start(0x1e,0x32);
  do {
    iVar4 = swtimer_expired(0x1e);
  } while (iVar4 != 1);
  sci4_send(&DAT_00001a5e,0);
  do {
    iVar4 = sci1_tx_end();
  } while (iVar4 == 0);
  auStack_40c[0] = 6;
  displink_uart_send(auStack_40c,1);
  do {
    wdt_kick();
    iVar4 = displink_rx_ready();
    if (iVar4 == 1) {
      pcVar5 = (char *)displink_rx_buf();
      pcVar6 = acStack_208;
      for (iVar4 = 0x204; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pcVar6 = *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
      displink_rx_rearm();
      if (acStack_208[0] != '\x06') {
        if ((acStack_208[0] == -0xf) && (acStack_208[1] == -0x7e)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          do {
            iVar4 = sci1_tx_end();
          } while (iVar4 == 0);
          auStack_40c[0] = 6;
          uVar7 = displink_uart_send(auStack_40c,1);
          return uVar7;
        }
        if (acStack_208[0] == 'Z') {
          do {
            iVar4 = sci1_tx_end();
          } while (iVar4 == 0);
          auStack_40c[0] = 6;
          displink_uart_send(auStack_40c,1);
          pcVar6 = acStack_208 + 3;
          pcVar5 = &DAT_00001a5e;
          for (uVar10 = (uint)CONCAT11(acStack_208[2],acStack_208[1]); uVar10 != 0;
              uVar10 = uVar10 - 1) {
            *pcVar5 = *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          }
          sci4_send(&DAT_00001a5e,CONCAT11(acStack_208[2],acStack_208[1]));
        }
      }
    }
    iVar4 = sci4_rx_ready();
    if (iVar4 == 1) {
      puVar8 = (undefined1 *)sci4_rx_buf();
      uVar3 = sci4_rx_len();
      do {
        iVar4 = sci1_tx_end();
      } while (iVar4 == 0);
      auStack_40c[0] = 0x5a;
      auStack_40c[1] = (undefined1)uVar3;
      auStack_40c[2] = (undefined1)(uVar3 >> 8);
      puVar9 = auStack_40c + 3;
      for (uVar10 = (uint)uVar3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar9 = *puVar8;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      uVar2 = dsp_sum8(auStack_40c,(ushort)(uVar3 + 3) & 0xff);
      auStack_40c[(ushort)(uVar3 + 3)] = uVar2;
      displink_uart_send(auStack_40c,uVar3 + 4);
      sci4_send(&DAT_00001a5e,0);
    }
  } while( true );
}


// ===== dsp_route_param @ fffa0e3a (760 bytes)

/* Per-audio-route constants for regs 8, 9, 10, 0x0D/0x0E, 0x20 and EQ enable 0x25/0x28/0x2B; sets
   0x20B49 */

undefined2 dsp_route_param(ushort param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uStack_a;
  
  iVar2 = audio_route_state();
  uStack_a = 0;
  switch(iVar2) {
  case 0:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 1:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 2:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 3:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 4:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 5:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 6:
    uVar1 = (uint)param_1;
    if (uVar1 == 0x20) {
      uStack_a = 0;
    }
    else if (uVar1 == 9) {
      uStack_a = 0;
    }
    else if (uVar1 == 10) {
      uStack_a = 0x22;
    }
    else if (uVar1 - 0xd < 2) {
      uStack_a = 0xf000;
    }
    else if (uVar1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 7:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 8:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 9:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 10:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xb:
  case 0xc:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xd:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
    break;
  case 0xe:
    if (param_1 == 0x20) {
      uStack_a = 0xfffe;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
  }
  if (((param_1 == 0x25) || (param_1 == 0x28)) || (param_1 == 0x2b)) {
    if (iVar2 < 8) {
      uStack_a = 0;
    }
    else {
      uStack_a = 0xffff;
    }
  }
  if (param_1 == 0x20) {
    DAT_00020b49 = 1;
  }
  return uStack_a;
}


// ===== sdr_init @ fffa1132 (187 bytes)

/* Boot (app_main): SDR_RESET P77=1, wait 1000 ms, clear shadows, read regs 0 and 1 (fail ->
   0x20B36=3), build SDR version 'Vxx-yy' from reg 0 into 0x144A (VE P1=2) */

void sdr_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_7 = 0x56;
  local_6 = 0x2a;
  local_5 = 0x2a;
  local_4 = 0x2d;
  local_3 = 0x2a;
  local_2 = 0x2a;
  local_1 = 0;
  sdr_reset_set(1);
  swtimer_start(0x1f,1000);
  do {
    iVar1 = swtimer_expired(0x1f);
  } while (iVar1 != 1);
  puVar2 = (undefined4 *)&DAT_0001b736;
  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xff;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  DAT_00001c8b = 0;
  DAT_00001c8d = 0;
  sdr_req_reg0();
  iVar1 = sdr_wait_reply(0x72,0);
  if (iVar1 != 1) {
    DAT_00020b36 = 3;
    return;
  }
  sdr_req_reg1();
  iVar1 = sdr_wait_reply(0x72,0);
  if (iVar1 != 1) {
    DAT_00020b36 = 3;
    return;
  }
  word2hex(&uStack_b,DAT_0001b736);
  local_6 = uStack_b;
  local_5 = uStack_a;
  local_3 = uStack_9;
  local_2 = uStack_8;
  FUN_fff94c57(&local_7);
  return;
}


// ===== sdr_task @ fffa11ed (664 bytes)

/* Main-loop SDR task: completes a pending write, runs sdr_bridge_mode on request, waits for TX/RX
   line changes, then calls the per-register updaters in order until one sends a frame (one write
   per pass) */

void sdr_task(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = DAT_00020b6b;
  cVar2 = DAT_00020b18;
  if (DAT_00001c8b == '\x01') {
    iVar4 = sdr_poll_reply(0x77);
    if (iVar4 != 1) {
      return;
    }
    sdr_shadow_update();
  }
  if (DAT_00001c8d == '\x01') {
    sdr_bridge_mode();
  }
  if (DAT_0001b3dd != cVar3) {
    if ((cVar3 == '\x01') && (iVar4 = rx_line_get(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((cVar3 == '\0') && (iVar4 = tx_line_get(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_0001b3dd = cVar3;
  }
  sdr_upd_r0a_demod(cVar3);
  if (((((((((DAT_00001c8b == '\0') && (sdr_upd_r0b_band(cVar3), DAT_00001c8b == '\0')) &&
           (sdr_upd_r0c_rtty_shift(), DAT_00001c8b == '\0')) &&
          ((sdr_upd_r0d(), DAT_00001c8b == '\0' && (sdr_upd_r0f_band(cVar3), DAT_00001c8b == '\0')))
          ) && (sdr_upd_r20_scope_freq(cVar3), DAT_00001c8b == '\0')) &&
        (((sdr_upd_r22_scope_span(cVar3), DAT_00001c8b == '\0' &&
          (sdr_upd_r23(), DAT_00001c8b == '\0')) &&
         ((sdr_upd_r25_tx_drive(cVar3), DAT_00001c8b == '\0' &&
          (((sdr_upd_r26(cVar3), DAT_00001c8b == '\0' &&
            (sdr_upd_r27_scope_level(cVar3), DAT_00001c8b == '\0')) &&
           (sdr_upd_r03(), DAT_00001c8b == '\0')))))))) &&
       ((sdr_upd_r08_tx_freq(), DAT_00001c8b == '\0' && (sdr_upd_r0e(), DAT_00001c8b == '\0')))) &&
      (sdr_upd_r14_mode(), DAT_00001c8b == '\0')) &&
     ((cVar3 != '\0' ||
      ((((sdr_upd_r04(), DAT_00001c8b == '\0' && (sdr_upd_r12(), DAT_00001c8b == '\0')) &&
        ((sdr_upd_r13(), DAT_00001c8b == '\0' &&
         (((sdr_upd_r16_filter(), DAT_00001c8b == '\0' &&
           (sdr_upd_r18_rx_freq(), DAT_00001c8b == '\0')) &&
          (sdr_upd_r1a_nb_level(), DAT_00001c8b == '\0')))))) &&
       (((sdr_upd_r1b(), DAT_00001c8b == '\0' && (sdr_upd_r1c(), DAT_00001c8b == '\0')) &&
        ((sdr_upd_r1d_notch(), DAT_00001c8b == '\0' &&
         ((sdr_upd_r1e_passband(), DAT_00001c8b == '\0' &&
          (sdr_upd_r1f_width(), DAT_00001c8b == '\0')))))))))))) {
    if (DAT_0001b3dc == '\0') {
      sdr_init_r15();
      if (DAT_00001c8b != '\0') {
        return;
      }
      sdr_init_r24();
      if (DAT_00001c8b != '\0') {
        return;
      }
      DAT_0001b3dc = '\x01';
    }
    if ((cVar2 == '\x01') || (cVar2 == '\a')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b19 = 1;
      return;
    }
  }
  return;
}


// ===== sdr_reg_access @ fffa1485 (135 bytes)

/* SDR register r/w over SCI5 ('r'/'w' + hex addr [+ value] + sum + CR, waits for reply) */

undefined1 sdr_reg_access(undefined2 param_1,undefined2 *param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 local_b;
  
  local_b = 0;
  while( true ) {
    if ((DAT_00001c8b == '\x01') || (DAT_00001c8c == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    sdr_task();
  }
  DAT_0001b784 = param_1;
  if (param_3 == '\0') {
    sdr_send_frame(0x72);
    iVar2 = sdr_wait_reply(0x72,1);
    if (iVar2 == 1) {
      *param_2 = DAT_0001b782;
      local_b = 1;
    }
  }
  else {
    DAT_0001b786 = *param_2;
    sdr_send_frame(0x77);
    local_b = sdr_wait_reply(0x77,1);
  }
  return local_b;
}


// ===== scope_level_ptr @ fffa150c (53 bytes)

/* Returns the pointer to the scope reference-level byte for a frequency and VFO side
   (FUN_fffb3480); used by SS sel 4 and SDR reg 0x27 [inference] */

void scope_level_ptr(undefined4 param_1)

{
  freq_range_index(param_1);
  return;
}


// ===== scope_span_ptr @ fffa1541 (53 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa155b) */
/* Returns the pointer to the scope span index for a frequency (FUN_fffb3480); used by SS sel 5 and
   SDR reg 0x20/0x21 [inference] */

void scope_span_ptr(undefined4 param_1)

{
  freq_range_index(param_1);
  return;
}


// ===== sdr_bridge_request @ fffa1576 (10 bytes)

/* DISPLAY-link sub-command 1: sets 0x1C8D so sdr_task enters sdr_bridge_mode */

void sdr_bridge_request(void)

{
  DAT_00001c8d = 1;
  return;
}


// ===== sdr_req_reg0 @ fffa1580 (16 bytes)

/* Sends a read of SDR register 0 (version) */

void sdr_req_reg0(void)

{
  DAT_0001b784 = 0;
  sdr_send_frame(0x72);
  return;
}


// ===== sdr_req_reg1 @ fffa1590 (16 bytes)

/* Sends a read of SDR register 1 */

void sdr_req_reg1(void)

{
  DAT_0001b784 = 1;
  sdr_send_frame(0x72);
  return;
}


// ===== sdr_upd_r03 @ fffa15a0 (83 bytes)

/* Reg 0x03 = 0xE63D if TX-side frequency <= 62.5 MHz else 0xE61D */

void sdr_upd_r03(void)

{
  uint uVar1;
  undefined2 uStack_6;
  
  uVar1 = vfo_freq(1,2);
  if (uVar1 < 0x3b9aca1) {
    uStack_6 = -0x19c3;
  }
  else {
    uStack_6 = -0x19e3;
  }
  if (DAT_0001b73a == uStack_6) {
    return;
  }
  DAT_0001b784 = 3;
  DAT_0001b786 = uStack_6;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r04 @ fffa15f3 (57 bytes)

/* Reg 0x04 = 0xE519 (constant; RX only) */

void sdr_upd_r04(void)

{
  vfo_rec_ptr(0);
  if (DAT_0001b73c == -0x1ae7) {
    return;
  }
  DAT_0001b784 = 4;
  DAT_0001b786 = 0xe519;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r08_tx_freq @ fffa162c (268 bytes)

/* Regs 0x08/0x09 = 32-bit operating frequency 0x20F50 in Hz, with PSK tone / CW pitch offsets
   [inference: TX NCO] */

void sdr_upd_r08_tx_freq(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  ushort uStack_6;
  undefined4 uStack_4;
  
  cVar1 = vfo_mode(1);
  uStack_4 = DAT_00020f50;
  if (cVar1 == '\x0e') {
    if (DAT_00009a79 == '\x01') {
      uStack_6 = 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      uStack_6 = 2000;
    }
    else {
      uStack_6 = 1000;
    }
    uStack_4 = DAT_00020f50 - uStack_6;
  }
  else {
    iVar3 = FUN_fffba192();
    if (iVar3 == 3) {
      uVar2 = (ushort)DAT_00009c04 * 10 + 300;
      if (cVar1 == '\0') {
        uStack_4 = uStack_4 - uVar2;
      }
      else if (cVar1 == '\x01') {
        uStack_4 = uStack_4 + uVar2;
      }
      DAT_0001b3de = '\x01';
    }
    else if (DAT_0001b3de == '\x01') {
      iVar3 = tx_line_get();
      if (iVar3 == 1) {
        return;
      }
      DAT_0001b3de = '\0';
    }
  }
  if (uStack_4._2_2_ == DAT_0001b73e) {
    if ((uStack_4 & 0xffff) == (uint)DAT_0001b740) {
      return;
    }
    DAT_0001b784 = 9;
    DAT_0001b786 = (undefined2)uStack_4;
    sdr_send_frame(0x77);
    return;
  }
  DAT_0001b784 = 8;
  DAT_0001b786 = uStack_4._2_2_;
  sdr_send_frame(0x77);
  DAT_0001b740 = 0xffff;
  return;
}


// ===== sdr_upd_r0a_demod @ fffa1738 (164 bytes)

/* Reg 0x0A = mode class 0..5 (CW, AM, FM, LSB-side, USB-side, RTTY) of the RX/TX VFO; only while
   0x1204D != 0 */

void sdr_upd_r0a_demod(undefined1 param_1)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  short sStack_4;
  
  bVar2 = vfo_mode(param_1);
  cVar3 = ptt_source_get();
  if (cVar3 == '\0') {
    return;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 0) {
LAB_fffa1791:
    sStack_4 = 3;
    iVar4 = FUN_fffba192();
    if (iVar4 == 3) {
      sStack_4 = 0;
    }
  }
  else {
    if ((uVar1 == 1) || (uVar1 == 0xe)) {
LAB_fffa17a1:
      sStack_4 = 4;
      iVar4 = FUN_fffba192();
      if (iVar4 == 3) {
        sStack_4 = 0;
      }
      goto LAB_fffa17b2;
    }
    if (uVar1 - 4 < 2) {
      sStack_4 = 1;
      goto LAB_fffa17b2;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 == 8) goto LAB_fffa1791;
      if (uVar1 == 9) goto LAB_fffa17a1;
      if (1 < uVar1 - 10) {
        if (uVar1 == 2 || uVar1 == 3) {
          sStack_4 = 0;
        }
        else {
          sStack_4 = 5;
        }
        goto LAB_fffa17b2;
      }
    }
    sStack_4 = 2;
  }
LAB_fffa17b2:
  if (DAT_0001b742 == sStack_4) {
    return;
  }
  DAT_0001b784 = 10;
  DAT_0001b786 = sStack_4;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r0b_band @ fffa17dc (97 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa17fc) */
/* Reg 0x0B = per-band word from 0xFFF87FFA (RX) / 0xFFF87FFE (TX), 8-byte rows */

void sdr_upd_r0b_band(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  short sStack_a;
  
  vfo_mode(param_1);
  uVar2 = vfo_freq(param_1,2);
  bVar1 = gen_subband_of_freq(uVar2);
  if (param_1 == '\0') {
    sStack_a = *(short *)(&DAT_fff87ffa + (uint)bVar1 * 8);
  }
  else {
    sStack_a = *(short *)(&DAT_fff87ffe + (uint)bVar1 * 8);
  }
  if (DAT_0001b744 != sStack_a) {
    DAT_0001b784 = 0xb;
    DAT_0001b786 = sStack_a;
    sdr_send_frame(0x77);
    return;
  }
  return;
}


// ===== sdr_upd_r0c_rtty_shift @ fffa183d (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1872) */
/* WARNING: Removing unreachable block (ram,0xfffa187a) */
/* Reg 0x0C = (RTTY shift 170/200/425/850 Hz from 0x9A8D)/5 << 8 | 3 */

void sdr_upd_r0c_rtty_shift(void)

{
  ushort uVar1;
  undefined2 local_2;
  
  if (DAT_00009a8d == '\x01') {
    local_2 = 200;
  }
  else if (DAT_00009a8d == '\x02') {
    local_2 = 0x1a9;
  }
  else if (DAT_00009a8d == '\x03') {
    local_2 = 0x352;
  }
  else {
    local_2 = 0xaa;
  }
  uVar1 = local_2 / 5 << 8 | 3;
  if (DAT_0001b746 == uVar1) {
    return;
  }
  DAT_0001b784 = 0xc;
  DAT_0001b786 = uVar1;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r0d @ fffa18ae (74 bytes)

/* Reg 0x0D = 9/14/19 from setting 0x9AA1 (0..2) [meaning unknown] */

void sdr_upd_r0d(void)

{
  undefined2 local_2;
  
  if (DAT_00009aa1 == '\x01') {
    local_2 = 0xe;
  }
  else if (DAT_00009aa1 == '\0') {
    local_2 = 9;
  }
  else {
    local_2 = 0x13;
  }
  if (DAT_0001b748 == local_2) {
    return;
  }
  DAT_0001b784 = 0xd;
  DAT_0001b786 = local_2;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r0e @ fffa18f8 (49 bytes)

/* Reg 0x0E = 0x1200 (constant) */

void sdr_upd_r0e(void)

{
  if (DAT_0001b74a == 0x1200) {
    return;
  }
  DAT_0001b784 = 0xe;
  DAT_0001b786 = 0x1200;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r0f_band @ fffa1929 (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa196a) */
/* Reg 0x0F = per-band word 0xFFF87FFC/0xFFF88000, 0 when ADC 0x20B14 >= 0xE8B, unchanged between
   0x9B3..0xE8A */

void sdr_upd_r0f_band(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  short sStack_a;
  
  vfo_mode(param_1);
  if (DAT_00020b14 < 0xe8b) {
    if (0x9b2 < DAT_00020b14) {
      return;
    }
    uVar2 = vfo_freq(param_1,2);
    bVar1 = gen_subband_of_freq(uVar2);
    if (param_1 == '\0') {
      sStack_a = *(short *)(&DAT_fff87ffc + (uint)bVar1 * 8);
    }
    else {
      sStack_a = *(short *)(&DAT_fff88000 + (uint)bVar1 * 8);
    }
  }
  else {
    sStack_a = 0;
  }
  if (DAT_0001b74c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0xf;
  DAT_0001b786 = sStack_a;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r12 @ fffa19ac (49 bytes)

/* Reg 0x12 = 0x8000 (constant; RX only) */

void sdr_upd_r12(void)

{
  if (DAT_0001b74e == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x12;
  DAT_0001b786 = 0x8000;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r13 @ fffa19dd (49 bytes)

/* Reg 0x13 = 0x8000 (constant; RX only) */

void sdr_upd_r13(void)

{
  if (DAT_0001b750 == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x13;
  DAT_0001b786 = 0x8000;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r14_mode @ fffa1a0e (124 bytes)

/* Reg 0x14 = 0x2000/0x3200 (AM)/0x7800 (FM, DATA-FM)/0x3C00 (FM-N, DATA-FM-N) by TX-side mode */

void sdr_upd_r14_mode(void)

{
  undefined1 uVar1;
  short sStack_2;
  
  uVar1 = vfo_mode(1);
  switch(uVar1) {
  case 2:
  case 3:
    sStack_2 = 0x2000;
    break;
  case 4:
  case 5:
    sStack_2 = 0x3200;
    break;
  case 6:
  case 10:
    sStack_2 = 0x7800;
    break;
  case 7:
  case 0xb:
    sStack_2 = 0x3c00;
    break;
  case 8:
  case 9:
    sStack_2 = 0x2000;
    break;
  case 0xc:
  case 0xd:
    sStack_2 = 0x2000;
    break;
  case 0xe:
    sStack_2 = 0x2000;
    break;
  default:
    sStack_2 = 0x2000;
  }
  if (DAT_0001b752 != sStack_2) {
    DAT_0001b784 = 0x14;
    DAT_0001b786 = sStack_2;
    sdr_send_frame(0x77);
    return;
  }
  return;
}


// ===== sdr_init_r15 @ fffa1a8a (49 bytes)

/* Reg 0x15 = 0x2000, sent once after the first full sync */

void sdr_init_r15(void)

{
  if (DAT_0001b754 == 0x2000) {
    return;
  }
  DAT_0001b784 = 0x15;
  DAT_0001b786 = 0x2000;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r16_filter @ fffa1abb (430 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1ae7) */
/* Reg 0x16 = filter class by mode and width (CW 0..2, SSB/data 0x10..0x12, AM 0x20/0x21, FM
   0x30/0x31); also sets 0x20B4A */

void sdr_upd_r16_filter(void)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  char *pcVar5;
  undefined1 uStack_7;
  undefined1 uStack_6;
  short sStack_2;
  
  bVar3 = vfo_mode(0);
  pcVar5 = (char *)FUN_fffb54a0();
  bVar1 = *pcVar5 == '\0';
  FUN_fffc4e4f();
  uVar4 = CONCAT11(uStack_7,uStack_6);
  uVar2 = (uint)bVar3;
  if (1 < uVar2 - 10) {
    if (uVar2 == 4) {
      sStack_2 = 0x21;
      DAT_00020b4a = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 == 5) {
      sStack_2 = 0x20;
      DAT_00020b4a = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 != 6) {
      if (uVar2 == 7) {
        sStack_2 = 0x30;
        DAT_00020b4a = 0x1e;
      }
      else if (uVar2 == 2 || uVar2 == 3) {
        if (uVar4 < 0xfb) {
          sStack_2 = 0;
          if (bVar1) {
            DAT_00020b4a = 0x4a;
          }
          else {
            DAT_00020b4a = 0x54;
          }
        }
        else if (uVar4 < 800) {
          sStack_2 = 1;
          if (bVar1) {
            DAT_00020b4a = 0x27;
          }
          else {
            DAT_00020b4a = 0x31;
          }
        }
        else {
          sStack_2 = 2;
          if (bVar1) {
            DAT_00020b4a = 0x17;
          }
          else {
            DAT_00020b4a = 0x21;
          }
        }
      }
      else if (uVar4 < 0x44d) {
        sStack_2 = 0x10;
        if (bVar1) {
          DAT_00020b4a = 0x1f;
        }
        else {
          DAT_00020b4a = 0x29;
        }
      }
      else if (uVar4 < 2000) {
        sStack_2 = 0x11;
        if (bVar1) {
          DAT_00020b4a = 0x17;
        }
        else {
          DAT_00020b4a = 0x21;
        }
      }
      else {
        sStack_2 = 0x12;
        if (bVar1) {
          DAT_00020b4a = 0x15;
        }
        else {
          DAT_00020b4a = 0x1f;
        }
      }
      goto LAB_fffa1c3f;
    }
  }
  sStack_2 = 0x31;
  DAT_00020b4a = 0x1e;
LAB_fffa1c3f:
  if (DAT_0001b756 == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x16;
  DAT_0001b786 = sStack_2;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r18_rx_freq @ fffa1c69 (872 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1e44) */
/* WARNING: Removing unreachable block (ram,0xfffa1eab) */
/* WARNING: Removing unreachable block (ram,0xfffa1e6a) */
/* WARNING: Removing unreachable block (ram,0xfffa1e83) */
/* WARNING: Removing unreachable block (ram,0xfffa1e1c) */
/* WARNING: Removing unreachable block (ram,0xfffa1d55) */
/* WARNING: Removing unreachable block (ram,0xfffa1cdf) */
/* WARNING: Removing unreachable block (ram,0xfffa1c97) */
/* WARNING: Removing unreachable block (ram,0xfffa1f47) */
/* WARNING: Removing unreachable block (ram,0xfffa1d04) */
/* WARNING: Removing unreachable block (ram,0xfffa1d7f) */
/* WARNING: Removing unreachable block (ram,0xfffa1dcd) */
/* WARNING: Removing unreachable block (ram,0xfffa1de8) */
/* WARNING: Removing unreachable block (ram,0xfffa1ed4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Regs 0x18/0x19 = 32-bit RX VFO frequency in Hz plus the mode offset (SSB 1500 Hz + shift, CW
   pitch, RTTY mark/shift, DATA offset, PSK) [inference: RX NCO] */

void sdr_upd_r18_rx_freq(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 uStack_16;
  undefined1 uStack_15;
  short sStack_12;
  ushort uStack_a;
  undefined4 uStack_8;
  
  iVar7 = vfo_rec_ptr(0);
  bVar3 = vfo_mode(0);
  uStack_8 = vfo_freq_clar(0,2);
  uVar2 = (uint)bVar3;
  if (uVar2 == 0xe) {
    uVar4 = CONCAT11(*(byte *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31));
    if ((*(byte *)(iVar7 + 0x30) & 0x80) == 0) {
      uStack_8 = uVar4 + uStack_8;
    }
    else {
      uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
    }
  }
  else if (uVar2 - 2 < 2) {
    bVar1 = *(byte *)(iVar7 + 0x1c);
    uVar5 = CONCAT11(bVar1,*(undefined1 *)(iVar7 + 0x1d));
    FUN_fffc4e4f();
    uVar4 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_16,uStack_15) < uVar4) {
      if ((bVar1 & 0x80) != 0) {
        _DAT_0000464f = 1;
      }
      if (bVar3 == 2) {
        uStack_8 = uStack_8 + (ushort)(~uVar5 + 1);
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar5 + 1);
      }
    }
    else {
      uVar5 = (short)((int)((uint)CONCAT11(uStack_16,uStack_15) - (uint)uVar4) / 2) + uVar5;
      if ((uVar5 & 0x8000) != 0) {
        _DAT_0000464f = 1;
      }
      if (bVar3 == 2) {
        uStack_8 = uStack_8 + (ushort)(~uVar5 + 1);
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar5 + 1);
      }
    }
  }
  else {
    puVar8 = (undefined4 *)(uVar2 - 8);
    if (puVar8 < (undefined4 *)0x2) {
      uVar4 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
              CONCAT11(*(undefined1 *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31));
      if ((uVar4 & 0x8000) != 0) {
        *puVar8 = 1;
      }
      if (bVar3 == 8) {
        uStack_8 = uStack_8 - uVar4;
      }
      else if (puVar8 == (undefined4 *)0x0) {
        uStack_8 = uStack_8 + uVar4;
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
      }
    }
    else {
      puVar8 = (undefined4 *)(uVar2 - 0xc);
      if (puVar8 < (undefined4 *)0x2) {
        sVar6 = CONCAT11(*(undefined1 *)(iVar7 + 0x26),*(byte *)(iVar7 + 0x27));
        if (DAT_00009a8d == '\x01') {
          sStack_12 = 0x69;
        }
        else if (DAT_00009a8d == '\x02') {
          sStack_12 = 0xd7;
        }
        else if (DAT_00009a8d == '\x03') {
          sStack_12 = 0x1a9;
        }
        else {
          sStack_12 = 0x55;
        }
        if (bVar3 != 0xc) {
          sVar6 = -(ushort)*(byte *)(iVar7 + 0x27);
        }
        uStack_a = sStack_12 + sVar6;
        if ((uStack_a & 0x8000) == 0) {
          uStack_8 = uStack_8 - (uStack_a & 0xff);
        }
        else {
          uStack_8 = uStack_8 + (ushort)(~uStack_a + 1);
        }
      }
      else if (uVar2 < 2) {
        uVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x12),*(undefined1 *)(iVar7 + 0x13)) + 0x5dc;
        if ((uVar4 & 0x8000) != 0) {
          *puVar8 = 1;
        }
        if (bVar3 == 0) {
          uStack_8 = uStack_8 + (ushort)(~uVar4 + 1);
        }
        else if (puVar8 == (undefined4 *)0x0) {
          uStack_8 = uStack_8 + uVar4;
        }
        else {
          uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
        }
      }
    }
  }
  if (uStack_8._2_2_ == DAT_0001b758) {
    if ((uStack_8 & 0xffff) == (uint)DAT_0001b75a) {
      return;
    }
    DAT_0001b784 = 0x19;
    DAT_0001b786 = (undefined2)uStack_8;
    sdr_send_frame(0x77);
    return;
  }
  DAT_0001b784 = 0x18;
  DAT_0001b786 = uStack_8._2_2_;
  sdr_send_frame(0x77);
  DAT_0001b75a = 0xffff;
  return;
}


// ===== sdr_upd_r1a_nb_level @ fffa1fd1 (120 bytes)

/* Reg 0x1A = NB level (NL 0x9DC0) mapped through 0xFFF8808A (AM) / 0xFFF880A0, 0 when NB is off */

void sdr_upd_r1a_nb_level(void)

{
  byte bVar1;
  int iVar2;
  short sStack_6;
  
  iVar2 = vfo_rec_ptr(0);
  bVar1 = DAT_00009dc0;
  if ((*(byte *)(iVar2 + 2) & 2) == 0) {
    sStack_6 = 0;
  }
  else {
    iVar2 = vfo_mode(0);
    if (iVar2 == 4 || iVar2 == 5) {
      sStack_6 = *(short *)(&DAT_fff8808a + (uint)bVar1 * 2);
    }
    else {
      sStack_6 = *(short *)(&DAT_fff880a0 + (uint)bVar1 * 2);
    }
  }
  if (DAT_0001b75c == sStack_6) {
    return;
  }
  DAT_0001b784 = 0x1a;
  DAT_0001b786 = sStack_6;
  sdr_send_frame(0x77);
  return;
}


// ===== sdr_upd_r1b @ fffa2049 (102 bytes)

/* Reg 0x1B = table 0xFFF880B6 (AM) / 0xFFF880BC indexed by setting 0x9AD3 [guess: NB parameter] */

void sdr_upd_r1b(void)

{
  byte bVar1;
  int iVar2;
  short sStack_2;
  
  vfo_mode(0);
  bVar1 = DAT_00009ad3;
  iVar2 = vfo_mode(0);
  if (iVar2 == 4 || iVar2 == 5) {
    sStack_2 = *(short *)(&DAT_fff880b6 + (uint)bVar1 * 2);
  }
  else {
    sStack_2 = *(short *)((int)&PTR_DAT_fff880bc + (uint)bVar1 * 2);
  }
  if (DAT_0001b75e == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x1b;
  DAT_0001b786 = sStack_2;
  sdr_send_frame(0x77);
  return;
}

