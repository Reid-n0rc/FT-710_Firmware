// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  uint uVar8;
  bool bStack_11;
  char cStack_a;
  ushort uStack_6;
  
  pbVar7 = vfo_rec_ptr(0);
  uStack_6 = 100;
  bVar3 = pbVar7[5] & 3;
  uVar8 = vfo_freq(0,2);
  bVar4 = gen_subband_of_freq(uVar8);
  bVar5 = vfo_mode(0);
  bVar6 = g_ui.trx_state;
  uVar8 = audio_route_state();
  bVar1 = DAT_000120ba != bVar3;
  if (!bVar1) {
    bVar3 = DAT_000120ba;
  }
  DAT_000120ba = bVar3;
  bStack_11 = DAT_000120b9 != bVar4;
  if (!bStack_11) {
    bVar4 = DAT_000120b9;
  }
  DAT_000120b9 = bVar4;
  bStack_11 = bStack_11 || bVar1;
  if (DAT_000120bb != bVar5) {
    bStack_11 = true;
    g_ui.squelch_open = 0;
    DAT_000120bb = bVar5;
  }
  if (bVar6 < 7) {
    cStack_a = '\x03';
  }
  else {
    cStack_a = '\b';
  }
  if (((DAT_0001b4d2 != cStack_a) && (DAT_0001b4d2 = cStack_a, cStack_a == '\b')) &&
     ((bVar6 = vfo_mode(1), 3 < bVar6 || (bVar6 = tx_cw_keying_class(), bVar6 == 0)))) {
    bStack_11 = true;
    uStack_6 = 0x28;
  }
  uVar2 = DAT_00025d48;
  if (DAT_00025d48 != uVar8) {
    if ((uVar8 == 2) || (uVar8 == 6)) {
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
    uVar2 = uVar8;
    if (bVar1) {
      swtimer_start(0x2c,3);
      g_ui.dsp_route_ready = 0;
    }
  }
  DAT_00025d48 = uVar2;
  if (bStack_11) {
    swtimer_start(0x2a,uStack_6);
    DAT_0001204f = 1;
    af_mute_set('\x01');
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
  if (g_opstate.ex020115_pc_keying == 3) {
    bVar1 = PORT2_PIDR;
    if (((bVar1 & 1) == 0) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  else if (g_opstate.ex020115_pc_keying == 2) {
    bVar1 = PORT7_PIDR;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = PORTC_PIDR, (bVar1 & 0x20) == 0)) {
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
    if (g_opstate.ex020115_pc_keying != 1) {
      return;
    }
    bVar1 = PORT7_PIDR;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = PORTC_PIDR, (bVar1 & 0x40) == 0)) {
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
  if ((DAT_00012050 == '\x01') && (g_ui.trx_state == 3)) {
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
  undefined1 *puVar1;
  int iVar2;
  
  g_ui.keyer_state = 0;
  DAT_0001215f = 0;
  puVar1 = &DAT_000120bc;
  for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
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
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  ushort uVar9;
  char cStack_19;
  char cStack_18;
  char cStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  ushort uStack_e;
  ushort uStack_c;
  byte bStack_9;
  undefined *puStack_8;
  byte local_1;
  
  local_1 = g_opstate.ex020203_cw_weight;
  bVar3 = tx_cw_keying_class();
  if ((bVar3 == 0) || (g_ui.playlist_open != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    keyer_init();
    keyer_sidetone_off();
    g_ui.ptt_keyer = 0;
    return;
  }
  bVar3 = swtimer_expired(0x13);
  if ((bVar3 != 1) || (g_ui.tune_cycle != 0)) {
    return;
  }
  if (DAT_0001b4d5 != g_opstate.key_speed) {
    bVar1 = false;
    if (DAT_00012164 == '\0') {
      keyer_paddles_read(&cStack_18,&cStack_19);
      if ((cStack_18 == '\x01') && (cStack_19 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (DAT_00012162 == '\x02') {
          bVar1 = true;
        }
      }
      else {
        bVar1 = true;
      }
    }
    if (bVar1) {
      DAT_0001b4d5 = g_opstate.key_speed;
      keyer_init();
    }
  }
  if (g_opstate.keyer_on == 0) {
    DAT_0001215f = 0;
  }
  else {
    DAT_0001215f = g_opstate.ex020201_keyer_type;
  }
  DAT_00021014 = 1200000;
  if (DAT_0001b4d5 != 0) {
    DAT_00021014 = 1200000 / DAT_0001b4d5;
  }
  DAT_00021010 = ((local_1 + 0x19) * DAT_00021014) / 10;
  DAT_0001215c = qsk_delay_ticks();
  if (DAT_0001215f == 0) {
    DAT_0001215c = 0xf;
  }
  else {
    if ((DAT_0001b4d5 < 0x29) || (DAT_0001215c < 0x10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_0001215c = 0xf;
    }
    else {
      if ((DAT_0001b4d5 < 0x24) || (DAT_0001215c < 0x15)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        DAT_0001215c = 0x14;
      }
      else {
        if ((DAT_0001b4d5 < 0x1f) || (DAT_0001215c < 0x1a)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          DAT_0001215c = 0x19;
        }
      }
    }
  }
  switch(g_ui.keyer_state) {
  case 0:
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    g_ui.keyer_state = 1;
    swtimer_start(0x19,(ushort)DAT_0001215c);
    keyer_state_clear();
  case 1:
    if (DAT_0001215f < 2) {
      keyer_straight_bug(DAT_0001215f);
    }
    else if (DAT_0001215f - 2 < 4) {
      keyer_elekey(DAT_0001215f,'\0');
    }
    break;
  case 2:
    if (DAT_0001215d != '\x01') {
      return;
    }
    puVar5 = &DAT_000120bc;
    for (iVar7 = 0xa0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    g_ui.keyer_state = 3;
    swtimer_start(0x19,(ushort)DAT_0001215c);
    swtimer_start(0x1b,10000);
    keyer_state_clear();
    DAT_00021040 = vfo_rec_ptr(1);
    iVar7 = tx_breakin_on();
    if (iVar7 == 1) {
      DAT_00012166 = '\x01';
      DAT_00021040[0x14] = DAT_00021040[0x14] & 0xfd;
    }
    else {
      DAT_00012166 = '\0';
    }
  case 3:
    if (DAT_0001215f - 2 < 4) {
      keyer_elekey(DAT_0001215f,'\x01');
    }
    break;
  case 4:
    if (DAT_00012166 == '\x01') {
      DAT_00012166 = '\0';
      DAT_00021040[0x14] = DAT_00021040[0x14] | 2;
    }
    DAT_0001fa3a = DAT_0001fa38;
    if (DAT_0001fa38 != 0) {
      bStack_9 = g_ui.msg_slot;
      if ((g_ui.msg_slot == 0) || (5 < g_ui.msg_slot)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        bStack_9 = 1;
      }
      iVar7 = (uint)bStack_9 * 0x98;
      *(char *)((int)qmb + iVar7 + 0x2ec) = (char)(DAT_0001fa38 >> 8);
      *(char *)((int)qmb + iVar7 + 0x2ed) = (char)DAT_0001fa3a;
      puStack_8 = (undefined *)((int)qmb + iVar7 + 0x2ee);
      puVar5 = &DAT_000120bc;
      puVar8 = puStack_8;
      for (iVar7 = 0x96; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar5;
        puVar8 = puVar8 + 1;
        puVar5 = puVar5 + 1;
      }
      eeprom_save_msg(0,(uint)bStack_9);
    }
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    g_ui.keyer_state = 0;
    break;
  case 5:
    DAT_00012165 = '\0';
    if (DAT_0001215d != '\x01') {
      DAT_00012165 = 0;
      return;
    }
    bVar3 = FUN_fffb2dfe();
    if (bVar3 == 1) {
      return;
    }
    bStack_9 = g_ui.msg_slot;
    if ((g_ui.msg_slot == 0) || (5 < g_ui.msg_slot)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bStack_9 = 1;
    }
    bStack_9 = bStack_9 - 1;
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    if (g_opstate.ex020205_contest_number_be[bStack_9 + 2] == 1) {
      iVar7 = (uint)bStack_9 * 0x98;
      DAT_0001fa38 = CONCAT11((&DAT_000093a7)[iVar7],(&DAT_000093a8)[iVar7]);
      puStack_8 = &DAT_000093a9 + iVar7;
      puVar5 = &DAT_000120bc;
      puVar8 = puStack_8;
      for (iVar7 = 0x96; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar5 = *puVar8;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    else {
      bStack_f = (&DAT_0000969f)[(uint)bStack_9 * 0x33];
      puStack_8 = &DAT_000096a0 + (uint)bStack_9 * 0x33;
      cStack_17 = '\0';
      for (bStack_13 = 0; bStack_13 < bStack_f; bStack_13 = bStack_13 + 1) {
        bStack_14 = puStack_8[bStack_13];
        bStack_16 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2];
        bStack_15 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2 + 1];
        if (bStack_14 == 0x23) {
          DAT_00012165 = '\x01';
          uStack_e = contest_number_get();
          uStack_c = 1000;
          for (bStack_11 = 0; bStack_11 < 4; bStack_11 = bStack_11 + 1) {
            uVar6 = (uint)uStack_e;
            if (uStack_c != 0) {
              uVar6 = uVar6 / uStack_c;
            }
            bStack_12 = (byte)uVar6;
            uVar9 = uStack_e;
            if (uStack_c != 0) {
              uVar9 = uStack_e / uStack_c;
            }
            uStack_e = uStack_e - uVar9 * uStack_c;
            uStack_c = uStack_c / 10;
            bStack_14 = nib2hex(bStack_12);
            if ((bStack_11 == 0) && (bStack_14 == 0x30)) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (!bVar1) {
              bStack_14 = contest_cut_digit(bStack_14);
              bStack_16 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2];
              bStack_15 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2 + 1];
              for (bStack_10 = 0; bStack_10 < bStack_16; bStack_10 = bStack_10 + 1) {
                if ((bStack_15 & 0x80) == 0) {
                  keyer_elem_put(1);
                }
                else {
                  keyer_elem_put(2);
                }
                keyer_elem_put(0);
                bStack_15 = bStack_15 << 1;
              }
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                keyer_elem_put(0);
              }
            }
          }
        }
        else if (bStack_14 == 0x3c) {
          iVar7 = tx_breakin_on();
          if ((iVar7 == 1) && (uStack_e = contest_number_get(), uStack_e < 9999)) {
            uStack_e = uStack_e + 1;
            contest_number_set(uStack_e);
          }
        }
        else if (bStack_14 == 0x3e) {
          iVar7 = tx_breakin_on();
          if ((iVar7 == 1) && (uStack_e = contest_number_get(), 1 < uStack_e)) {
            uStack_e = uStack_e - 1;
            contest_number_set(uStack_e);
          }
        }
        else if (bStack_14 == 0x5b) {
          cStack_17 = '\x01';
        }
        else if (bStack_14 == 0x5d) {
          cStack_17 = '\0';
        }
        else if (bStack_14 == 0x5e) {
          bStack_14 = puStack_8[(byte)(bStack_13 + 1)];
          bStack_13 = bStack_13 + 2;
          if (bStack_14 == 0x30) {
            bStack_14 = puStack_8[bStack_13];
            if ((bStack_14 < 0x31) || (0x35 < bStack_14)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              cVar4 = hex2nib(bStack_14);
              bStack_14 = cVar4 - 1;
              if (bStack_9 != bStack_14) {
                keyer_text_msg_encode(bStack_14);
              }
            }
          }
        }
        else {
          bStack_10 = 0;
          if (bStack_16 == 0) {
            for (; bStack_10 < 4; bStack_10 = bStack_10 + 1) {
              keyer_elem_put(0);
            }
          }
          else {
            for (; bStack_10 < bStack_16; bStack_10 = bStack_10 + 1) {
              if ((bStack_15 & 0x80) == 0) {
                keyer_elem_put(1);
              }
              else {
                keyer_elem_put(2);
              }
              keyer_elem_put(0);
              bStack_15 = bStack_15 << 1;
            }
            if (cStack_17 == '\0') {
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                keyer_elem_put(0);
              }
            }
          }
        }
        if (0x4b0 < DAT_0001fa38) break;
      }
    }
    DAT_0001fa3c = DAT_0001fa38;
    DAT_0001fa38 = 0;
    swtimer_start(0x19,(ushort)DAT_0001215c);
    g_ui.keyer_state = 6;
    keyer_state_clear();
  case 6:
    if (DAT_0001fa3a == DAT_0001fa3c) {
      g_ui.keyer_state = 7;
      if (g_ui.msg_active == 1) {
        swtimer_start(0x1c,(ushort)g_opstate.ex020211_repeat_interval * 1000);
      }
      if ((DAT_00012165 == '\x01') && (uStack_e = contest_number_get(), uStack_e < 9999)) {
        uStack_e = uStack_e + 1;
        contest_number_set(uStack_e);
      }
    }
    else {
      keyer_paddles_read(&cStack_18,&cStack_19);
      if ((cStack_18 == '\x01') || (cStack_19 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        g_ui.msg_active = 0;
        g_ui.keyer_state = 7;
      }
    }
    FUN_fffba9c3();
    break;
  case 7:
    if (g_ui.msg_active == 1) {
      bVar3 = swtimer_expired(0x1c);
      if (bVar3 == 1) {
        g_ui.keyer_state = 5;
      }
    }
    else {
      DAT_0001fa38 = 0;
      DAT_0001fa3a = 0;
      keyer_sidetone_off();
      g_ui.keyer_state = 0;
    }
  }
  keyer_output_step(DAT_0001215f);
  return;
}


// ===== FUN_fffba131 @ fffba131 (97 bytes)

void FUN_fffba131(undefined1 *param_1,int param_2,byte param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_9;
  int local_8;
  
  if ((param_2 < 1) || (5 < param_2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_8 = param_2;
  if (bVar1) {
    local_8 = 1;
  }
  local_9 = param_3;
  if (0x32 < param_3) {
    local_9 = 0x32;
  }
  iVar2 = (local_8 + -1) * 0x33;
  (&DAT_0000969f)[iVar2] = local_9;
  puVar3 = &DAT_000096a0 + iVar2;
  for (uVar4 = (uint)local_9; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *param_1;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== tx_cw_keying_class @ fffba192 (378 bytes)

/* 0 voice, 1 CW mode, 2/3 CW in SSB (CW AUTO MODE 0x9A3C; value 1 only on band 0xB) by PTT source
   against PC KEYING 0x9A9F / RPTT SELECT; also sets 0x1215D [fact for the cases] */

byte tx_cw_keying_class(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  byte bStack_5;
  
  bVar4 = ptt_source_get();
  bVar5 = vfo_mode(1);
  bStack_5 = 0;
  cVar6 = rptt_select_get(bVar5);
  bVar3 = g_opstate.ex020115_pc_keying;
  DAT_0001215d = 0;
  if ((bVar5 == 3) || (bVar5 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_0001215d = 1;
  }
  else {
    if ((bVar5 == 0) || (bVar5 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_0001215d = 2;
    }
  }
  if ((bVar5 == 3) || (bVar5 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    return 1;
  }
  if ((bVar5 == 0) || (bVar5 == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (g_opstate.ex010119_cw_auto_mode != 2) {
    if ((g_opstate.ex010119_cw_auto_mode == 1) && (iVar7 = FUN_fffb32fd(g_ui.freq_tx), iVar7 == 0xb)
       ) {
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
      if ((cVar6 == '\0') || (bVar3 == 3)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        bStack_5 = 3;
      }
      else {
        bStack_5 = 2;
      }
    }
    else if (uVar1 == 3) {
      if ((cVar6 == '\0') || (bVar3 == 1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        bStack_5 = 3;
      }
      else {
        bStack_5 = 2;
      }
    }
    else if (uVar1 == 4) {
      if ((cVar6 == '\0') || (bVar3 == 2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        bStack_5 = 3;
      }
      else {
        bStack_5 = 2;
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
      bStack_5 = 2;
    }
  }
  return bStack_5;
}


// ===== contest_number_get @ fffba30c (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba31c) */
/* CONTEST NUMBER (EX020205) as u16 BE from 0x9AAB / 0x9AAC [fact] */

undefined2 contest_number_get(void)

{
  return CONCAT11(g_opstate.ex020205_contest_number_be[0],g_opstate.ex020205_contest_number_be[1]);
}


// ===== contest_number_set @ fffba336 (38 bytes)

/* Stores a u16 big-endian into g_opstate.ex020205_contest_number_be [fact: fffba336]; the setter
   twin of contest_number_get */

void contest_number_set(undefined2 param_1)

{
  g_opstate.ex020205_contest_number_be[0] = (byte)((ushort)param_1 >> 8);
  g_opstate.ex020205_contest_number_be[1] = (byte)param_1;
  return;
}


// ===== FUN_fffba35c @ fffba35c (27 bytes)

undefined2 FUN_fffba35c(void)

{
  return *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)g_opstate.cw_bkin_delay * 2 + 0x110);
}


// ===== keyer_elekey @ fffba377 (1225 bytes)

/* Keyer for KEYER TYPE 2..5 (ELEKEY-A, -B, -Y, ACS): keyer_task calls it when the type - 2 < 4;
   iambic squeeze memory for types 3 and 4 [fact: fffba377 and the caller's test] */

void keyer_elekey(char param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  char cStack_a;
  char cStack_9;
  int iStack_8;
  char local_2;
  char local_1;
  
  local_2 = param_2;
  local_1 = param_1;
  bVar1 = ckey_det();
  if (!bVar1) {
    g_ui.ptt_keyer = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  bVar2 = swtimer_expired(0x17);
  if (bVar2 != 1) {
    if (DAT_00012160 == '\0') {
      keyer_paddles_read(&cStack_9,&cStack_a);
      if ((local_1 == '\x03') || (local_1 == '\x04')) {
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
        if (local_1 == '\x04') {
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
            bVar2 = swtimer_expired(0x1d);
            if ((bVar2 != 1) && (DAT_00012161 == '\x02')) {
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
          if (local_1 == '\x03') {
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
    if ((bVar1) && (local_1 != '\x05')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      swtimer_start(0x19,(ushort)DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
    else {
      if ((DAT_00012163 < 4) || (DAT_00012160 == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (local_1 == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        return;
      }
      swtimer_start(0x19,(ushort)DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
  }
  if ((local_2 == '\x01') && (iVar3 = keyer_ring_limit(), iVar3 == 1)) {
    g_ui.keyer_state = 4;
    return;
  }
  if (DAT_00012161 == '\0') {
    keyer_paddles_read(&cStack_9,&cStack_a);
    if ((local_1 == '\x03') || (local_1 == '\x04')) {
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
        iStack_8 = DAT_00021010;
      }
      else {
        DAT_00012161 = '\x01';
        iStack_8 = DAT_00021014;
      }
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      iStack_8 = DAT_00021014;
    }
    else if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      iStack_8 = DAT_00021010;
    }
    else {
      if ((6 < DAT_00012163) ||
         ((DAT_00012163 = DAT_00012163 + 1, local_2 == '\x01' && (DAT_0001fa38 == 0)))) {
        return;
      }
      DAT_00012161 = '\0';
      iStack_8 = DAT_00021014;
    }
    if ((local_1 == '\x05') || (DAT_00012161 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_00012163 = 0;
    }
    if ((local_1 == '\x05') && (DAT_00012163 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00012161 != '\0')) {
      DAT_00012160 = DAT_00012161;
      DAT_00012161 = '\0';
      iStack_8 = DAT_00021014;
      DAT_00012163 = DAT_00012163 + 1;
    }
  }
  else {
    DAT_00012162 = DAT_00012161;
    DAT_00012161 = '\0';
    iStack_8 = DAT_00021014;
    DAT_00012163 = 1;
    if (local_2 == '\x01') {
      swtimer_start(0x1b,10000);
    }
  }
  timer_start_us(0x17,iStack_8);
  if ((local_1 == '\x04') && (DAT_00012161 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    timer_start_us(0x1d,DAT_00021014);
  }
  keyer_elem_put(DAT_00012161);
  return;
}


// ===== keyer_straight_bug @ fffba840 (387 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba98f) */
/* Keyer for KEYER TYPE 0/1 (OFF = straight key, BUG): keyer_task calls it when the type (0x1215F) <
   2; times elements with timer 0x17 and puts them with keyer_elem_put [fact: fffba840 and the
   caller's test; type labels from ROM 0xFFF84339 OFF/BUG/ELEKEY-A/-B/-Y/ACS] */

void keyer_straight_bug(char param_1)

{
  bool bVar1;
  byte bVar2;
  char cStack_a;
  char cStack_9;
  int iStack_8;
  char local_1;
  
  local_1 = param_1;
  bVar1 = ckey_det();
  if (!bVar1) {
    g_ui.ptt_keyer = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  bVar2 = swtimer_expired(0x17);
  if (bVar2 != 1) {
    return;
  }
  if (local_1 == '\0') {
    DAT_00012161 = ckey_dot();
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
    cStack_9 = DAT_00012161;
    swtimer_start(0x17,2);
    keyer_elem_put(DAT_00012161);
    return;
  }
  if (DAT_00012161 == '\x01') {
    DAT_00012161 = '\0';
    iStack_8 = DAT_00021014;
  }
  else {
    keyer_paddles_read(&cStack_9,&cStack_a);
    if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      iStack_8 = 2000;
      DAT_0001b4d6 = 0;
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      iStack_8 = DAT_00021014;
      DAT_0001b4d6 = 0;
    }
    else {
      DAT_00012161 = '\0';
      iStack_8 = 2000;
      DAT_0001b4d6 = DAT_0001b4d6 + 1;
    }
  }
  if (10 < DAT_0001b4d6) {
    DAT_0001b4d6 = DAT_0001b4d6 - 1;
    return;
  }
  timer_start_us(0x17,iStack_8);
  *(int *)(&DAT_00021018 + ((uint)DAT_0001fa38 % 10) * 4) = iStack_8;
  if (DAT_00012161 == '\x02') {
    keyer_elem_put(1);
    return;
  }
  keyer_elem_put(DAT_00012161);
  return;
}


// ===== FUN_fffba9c3 @ fffba9c3 (190 bytes)

void FUN_fffba9c3(void)

{
  bool bVar1;
  byte bVar2;
  undefined2 uVar3;
  ushort uStack_6;
  int iStack_4;
  
  bVar2 = swtimer_expired(0x17);
  if (bVar2 == 1) {
    if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa38 >> 3)] & 1 << ((byte)DAT_0001fa38 & 7)) ==
        0) {
      iStack_4 = DAT_00021014;
      uStack_6 = keyer_ring_next(DAT_0001fa38);
    }
    else {
      uStack_6 = keyer_ring_next(DAT_0001fa38);
      if ((DAT_0001fa3c == uStack_6) ||
         (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_6 >> 3)] & 1 << ((byte)uStack_6 & 7)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        iStack_4 = DAT_00021010;
        uVar3 = keyer_ring_next(uStack_6);
        uStack_6 = keyer_ring_next(uVar3);
      }
      else {
        iStack_4 = DAT_00021014;
      }
    }
    DAT_0001fa38 = uStack_6;
    timer_start_us(0x17,iStack_4);
    return;
  }
  return;
}


// ===== keyer_output_step @ fffbaa81 (1397 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbafc6) */
/* Plays the element ring 0x120BC from the read index 0x1FA3A up to the write index 0x1FA38:
   raises/clears g_ui.ptt_keyer (break-in), keyer_key_out, sidetone in state 6 [fact: fffbaa81] */

void keyer_output_step(byte param_1)

{
  bool bVar1;
  ushort uVar2;
  uint freq;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  byte bStack_18;
  byte bStack_17;
  char cStack_16;
  ushort uStack_12;
  uint uStack_10;
  
  freq = g_ui.freq_tx;
  vfo_rec_ptr(1);
  bVar4 = g_ui.trx_state;
  cStack_16 = -1;
  bVar3 = false;
  if (DAT_0001fa38 == DAT_0001fa3a) {
    if ((DAT_00012164 == '\0') && (bVar4 = swtimer_expired(0x1a), bVar4 == 1)) {
      if ((g_ui.transmitting == 1) || (bVar3 = tx_freq_allowed(freq), !bVar3)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if ((bVar3) && (g_ui.ptt_keyer == 1)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if (bVar3) {
        g_ui.ptt_keyer = 0;
      }
    }
    swtimer_start(0x19,(ushort)DAT_0001215c);
    return;
  }
  if (DAT_00012164 == '\0') {
    if ((param_1 == 0) || (param_1 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (g_ui.keyer_state != 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bStack_18 = DAT_0001215c >> 1;
      if (bStack_18 == 0) {
        bStack_18 = 1;
      }
      if ((bStack_18 < DAT_0001fa38) &&
         ((uint)DAT_0001fa3a + (uint)bStack_18 + 1 < (uint)DAT_0001fa38)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (((&DAT_000120bc)[DAT_0001fa38 >> 3] == '\0') &&
           ((&DAT_000120bc)[DAT_0001fa3a >> 3] == '\0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0001fa3a = DAT_0001fa38 - bStack_18;
        }
      }
      iVar7 = tx_breakin_on();
      if (iVar7 == 1) {
        uStack_12 = DAT_0001fa3a;
        for (bStack_17 = 0; bStack_17 < bStack_18; bStack_17 = bStack_17 + 1) {
          if (bStack_17 != 0) {
            uStack_12 = keyer_ring_next(uStack_12);
          }
          if (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_12 >> 3)] & 1 << ((byte)uStack_12 & 7)) !=
              0) {
            bVar3 = true;
            break;
          }
        }
        if (bVar3) {
          if ((g_ui.transmitting == 0) && (g_ui.ptt_keyer != 1)) {
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if (bVar3) {
            g_ui.ptt_keyer = 1;
          }
          if (bVar4 != 3) {
            tx_freq_allowed(freq);
          }
        }
        else {
          bVar4 = swtimer_expired(0x1a);
          if (bVar4 == 1) {
            if ((g_ui.tx_lamp == 0) || (g_ui.ptt_keyer != 1)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              g_ui.ptt_keyer = 0;
            }
          }
        }
      }
    }
    else {
      iVar7 = tx_breakin_on();
      if (iVar7 == 1) {
        if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa3a >> 3)] & 1 << ((byte)DAT_0001fa3a & 7))
            == 0) {
          bVar4 = swtimer_expired(0x1a);
          if (bVar4 == 1) {
            if ((g_ui.tx_lamp == 0) || (g_ui.ptt_keyer != 1)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              g_ui.ptt_keyer = 0;
            }
          }
        }
        else {
          if ((g_ui.transmitting == 0) && (g_ui.ptt_keyer != 1)) {
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if (bVar3) {
            g_ui.ptt_keyer = 1;
            return;
          }
          if ((bVar4 != 3) && (bVar3 = tx_freq_allowed(freq), bVar3)) {
            return;
          }
        }
      }
    }
  }
  bVar4 = swtimer_expired(0x19);
  if (bVar4 != 1) {
    swtimer_start(0x18,0);
    return;
  }
  bVar4 = swtimer_expired(0x18);
  uVar2 = DAT_0001fa3a;
  if (bVar4 == 1) {
    if ((g_ui.keyer_state == 1) || (g_ui.keyer_state == 3)) {
      if (param_1 < 2) {
        cStack_16 = '\x01';
      }
      else if (param_1 - 2 < 4) {
        cStack_16 = '\0';
      }
    }
    else if (g_ui.keyer_state == 6) {
      cStack_16 = '\0';
    }
    if (cStack_16 == '\0') {
      if (DAT_0001fa38 != DAT_0001fa3a) {
        if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa3a >> 3)] & 1 << ((byte)DAT_0001fa3a & 7))
            == 0) {
          if (g_ui.keyer_state == 6) {
            keyer_sidetone_off();
          }
          keyer_key_out(0);
          if (DAT_00012164 != '\0') {
            swtimer_start(0x1a,*(ushort *)
                                (BYTE_ARRAY_fff88270 + (uint)g_opstate.cw_bkin_delay * 2 + 0x110));
          }
          uStack_10 = DAT_00021014;
          uStack_12 = keyer_ring_next(uVar2);
          DAT_00012164 = 0;
        }
        else {
          if (g_ui.keyer_state == 6) {
            keyer_sidetone_on();
          }
          keyer_key_out(1);
          uStack_12 = keyer_ring_next(uVar2);
          if ((DAT_0001fa38 == uStack_12) ||
             (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_12 >> 3)] & 1 << ((byte)uStack_12 & 7)) ==
              0)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          if (bVar3) {
            uStack_10 = DAT_00021010;
            uVar6 = keyer_ring_next(uStack_12);
            uStack_12 = keyer_ring_next(uVar6);
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
      bVar4 = (byte)(DAT_0001fa3a >> 3);
      bVar5 = (byte)DAT_0001fa3a & 7;
      if (((uint)(byte)(&DAT_000120bc)[bVar4] & 1 << bVar5) == 0) {
        if (g_ui.keyer_state == 6) {
          keyer_sidetone_off();
        }
        keyer_key_out(0);
        if (DAT_00012164 != '\0') {
          swtimer_start(0x1a,*(ushort *)
                              (BYTE_ARRAY_fff88270 + (uint)g_opstate.cw_bkin_delay * 2 + 0x110));
        }
        DAT_00012164 = 0;
      }
      else {
        if (g_ui.keyer_state == 6) {
          keyer_sidetone_on();
        }
        keyer_key_out(1);
        DAT_00012164 = 1;
        (&DAT_000120bc)[bVar4] = (&DAT_000120bc)[bVar4] & ~(byte)(1 << bVar5);
      }
      if (param_1 == 0) {
        uStack_10 = 2000;
      }
      else {
        uStack_10 = *(uint *)(&DAT_00021018 + ((uint)uVar2 % 10) * 4);
      }
      timer_start_us(0x18,uStack_10 & 0xffff);
      DAT_0001fa3a = keyer_ring_next(uVar2);
      return;
    }
  }
  return;
}


// ===== keyer_state_clear @ fffbaff6 (46 bytes)

/* Clears the keyer bytes 0x12160..0x12164 [fact: fffbaff6]; keyer_task states 0 and 2 */

void keyer_state_clear(void)

{
  DAT_00012160 = 0;
  DAT_00012161 = 0;
  DAT_00012162 = 0;
  DAT_00012163 = 0;
  DAT_00012164 = 0;
  return;
}


// ===== keyer_elem_put @ fffbb024 (231 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb098) */
/* WARNING: Removing unreachable block (ram,0xfffbb108) */
/* Appends to the keyer element ring 0x120BC (index 0x1FA38): arg 1 = one mark bit + sidetone on, 0
   = one space bit + sidetone off, 2 = three mark bits (dash) [fact: fffbb024]; matches eeprom.md's
   description of the ring */

undefined4 keyer_elem_put(char param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte local_6;
  
  if (param_1 != '\0') {
    screensaver_timer_restart();
  }
  if (param_1 != '\x02') {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar1 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      (&DAT_000120bc)[bVar2] = 0;
    }
    bVar1 = (byte)(1 << (uint)(bVar1 & 7));
    if (param_1 == '\x01') {
      (&DAT_000120bc)[bVar2] = (&DAT_000120bc)[bVar2] | bVar1;
      keyer_sidetone_on();
    }
    else {
      (&DAT_000120bc)[bVar2] = (&DAT_000120bc)[bVar2] & ~bVar1;
      keyer_sidetone_off();
    }
    uVar3 = keyer_ring_next(DAT_0001fa38);
    DAT_0001fa38 = (short)uVar3;
    return uVar3;
  }
  for (local_6 = 0; local_6 < 3; local_6 = local_6 + 1) {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar1 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      (&DAT_000120bc)[bVar2] = 0;
    }
    (&DAT_000120bc)[bVar2] = (&DAT_000120bc)[bVar2] | (byte)(1 << (bVar1 & 7));
    DAT_0001fa38 = keyer_ring_next(DAT_0001fa38);
  }
  uVar3 = keyer_sidetone_on();
  return uVar3;
}


// ===== keyer_ring_limit @ fffbb10b (96 bytes)

/* Helper of keyer_elekey: when timer 0x1B expires drops the last 7 elements and returns 1; caps the
   ring at 0x4B0 elements (returns 1) [fact: fffbb10b] */

undefined1 keyer_ring_limit(void)

{
  byte bVar1;
  undefined1 local_2;
  
  local_2 = 0;
  bVar1 = swtimer_expired(0x1b);
  if (bVar1 == 1) {
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


// ===== keyer_ring_next @ fffbb16b (26 bytes)

/* Ring index + 1, wraps to 0 above 0x4FF [fact: fffbb16b]; the keyer element ring 0x120BC */

ushort keyer_ring_next(short param_1)

{
  undefined2 local_2;
  
  local_2 = param_1 + 1;
  if (0x4ff < local_2) {
    local_2 = 0;
  }
  return local_2;
}


// ===== keyer_sidetone_on @ fffbb185 (61 bytes)

/* When MONITOR (g_opstate.monitor[0] for SSB/AM-type modes, [1] from CW) is on: beep_request(4),
   flag 0x1215E = 1 [fact: fffbb185] */

void keyer_sidetone_on(void)

{
  byte bVar1;
  undefined1 uStack_1;
  
  bVar1 = vfo_mode(1);
  if (bVar1 < 2) {
    uStack_1 = g_opstate.monitor[0];
  }
  else {
    uStack_1 = g_opstate.monitor[1];
  }
  if (uStack_1 == 0) {
    return;
  }
  beep_request(4);
  DAT_0001215e = 1;
  return;
}


// ===== keyer_sidetone_off @ fffbb1c2 (27 bytes)

/* If flag 0x1215E is set: beep_stop, flag = 0 [fact: fffbb1c2] */

void keyer_sidetone_off(void)

{
  if (DAT_0001215e != '\x01') {
    return;
  }
  beep_stop();
  DAT_0001215e = 0;
  return;
}


// ===== keyer_key_out @ fffbb1dd (166 bytes)

/* (on): sets SEND_A/SEND_B (send_a_set / send_b_set) when the PTT source / CW keying class asks for
   it, and handles EX020116 CW BK-IN TYPE [fact: fffbb1dd]; only caller keyer_output_step */

void keyer_key_out(byte param_1)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar3 = tx_cw_keying_class();
  bVar1 = false;
  bVar4 = ptt_source_get();
  uVar5 = (uint)bVar4;
  if ((uVar5 != 1) && (1 < uVar5 - 3)) {
    if (uVar5 == 7) {
      bVar1 = true;
      goto LAB_fffbb21f;
    }
    if (uVar5 != 8 && uVar5 != 9) goto LAB_fffbb21f;
  }
  if ((bVar3 == 1) || (bVar3 == 3)) {
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
  if ((g_opstate.ex020116_cw_bk_in_type == 1) && (param_1 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((g_ui.trx_state == 3) && (g_ui.ptt_keyer == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      g_ui.ptt_keyer = 0;
      return;
    }
  }
  return;
}


// ===== keyer_paddles_read @ fffbb283 (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb2a9) */
/* WARNING: Removing unreachable block (ram,0xfffbb2bc) */
/* (*dot, *dash): ckey_dot / ckey_dash, swapped when EX020202 KEYER DOT/DASH is reversed [fact:
   fffbb283] */

void keyer_paddles_read(void *param_1,void *param_2)

{
  bool bVar1;
  
  if (g_opstate.ex020202_keyer_dot_dash != 0) {
    bVar1 = ckey_dot();
    *(bool *)param_2 = bVar1;
    bVar1 = ckey_dash();
    *(bool *)param_1 = bVar1;
    return;
  }
  bVar1 = ckey_dot();
  *(bool *)param_1 = bVar1;
  bVar1 = ckey_dash();
  *(bool *)param_2 = bVar1;
  return;
}


// ===== contest_cut_digit @ fffbb2bf (121 bytes)

/* Cut-number substitution by EX020204 NUMBER STYLE: '1' -> 'A', '2' -> 'U', '9' -> 'N', '0' -> 'T'
   or 'O', others unchanged [fact: fffbb2bf] */

char contest_cut_digit(char param_1)

{
  char local_1;
  
  if (param_1 == '1') {
    if (3 < g_opstate.ex020204_number_style - 1) {
      return '1';
    }
    return 'A';
  }
  if (param_1 == '2') {
    if (g_opstate.ex020204_number_style != 1 && g_opstate.ex020204_number_style != 2) {
      return '2';
    }
    return 'U';
  }
  if (param_1 == '9') {
    if (5 < g_opstate.ex020204_number_style - 1) {
      return '9';
    }
    return 'N';
  }
  if (param_1 != '0') {
    return param_1;
  }
  if ((g_opstate.ex020204_number_style == 6) || (g_opstate.ex020204_number_style == 2)) {
LAB_fffbb32d:
    local_1 = 'T';
  }
  else {
    if (g_opstate.ex020204_number_style != 3) {
      if (g_opstate.ex020204_number_style == 4) goto LAB_fffbb32d;
      if ((g_opstate.ex020204_number_style != 5) && (g_opstate.ex020204_number_style != 1)) {
        return '0';
      }
    }
    local_1 = 'O';
  }
  return local_1;
}


// ===== keyer_text_msg_encode @ fffbb338 (559 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb382) */
/* WARNING: Removing unreachable block (ram,0xfffbb408) */
/* WARNING: Removing unreachable block (ram,0xfffbb417) */
/* WARNING: Removing unreachable block (ram,0xfffbb3c5) */
/* WARNING: Removing unreachable block (ram,0xfffbb373) */
/* WARNING: Removing unreachable block (ram,0xfffbb51a) */
/* WARNING: Removing unreachable block (ram,0xfffbb440) */
/* (n): turns keyer memory text n (0x969F + n*0x33: length + 50 chars, eeprom.md) into elements via
   the Morse table 0xFFF815C3 (2 bytes per char), '#' inserts the contest number [fact: fffbb338] */

void keyer_text_msg_encode(byte param_1)

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
    bVar7 = BYTE_ARRAY_fff815c3[(uint)bVar2 * 2];
    local_13 = BYTE_ARRAY_fff815c3[(uint)bVar2 * 2 + 1];
    if (bVar2 == 0x23) {
      uStack_6 = contest_number_get();
      bVar4 = false;
      uStack_4 = 1000;
      for (bStack_f = 0; bStack_f < 4; bStack_f = bStack_f + 1) {
        uVar9 = (uint)uStack_6;
        if (uStack_4 != 0) {
          uVar9 = uVar9 / uStack_4;
        }
        uVar8 = uStack_6;
        if (uStack_4 != 0) {
          uVar8 = uStack_6 / uStack_4;
        }
        uStack_6 = uStack_6 - uVar8 * uStack_4;
        uStack_4 = uStack_4 / 10;
        cVar6 = nib2hex((byte)uVar9);
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
          bVar7 = contest_cut_digit(cVar6);
          bVar2 = BYTE_ARRAY_fff815c3[(uint)bVar7 * 2];
          local_13 = BYTE_ARRAY_fff815c3[(uint)bVar7 * 2 + 1];
          for (local_e = 0; local_e < bVar2; local_e = local_e + 1) {
            if ((local_13 & 0x80) == 0) {
              keyer_elem_put(1);
            }
            else {
              keyer_elem_put(2);
            }
            keyer_elem_put(0);
            local_13 = local_13 << 1;
          }
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            keyer_elem_put(0);
          }
        }
      }
    }
    else if (bVar2 == 0x3c) {
      uVar8 = contest_number_get();
      if (uVar8 < 9999) {
        contest_number_set(uVar8 + 1);
      }
    }
    else if (bVar2 == 0x3e) {
      uVar8 = contest_number_get();
      if (1 < uVar8) {
        contest_number_set(uVar8 - 1);
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
          keyer_elem_put(0);
        }
      }
      else {
        for (; local_e < bVar7; local_e = local_e + 1) {
          if ((local_13 & 0x80) == 0) {
            keyer_elem_put(1);
          }
          else {
            keyer_elem_put(2);
          }
          keyer_elem_put(0);
          local_13 = local_13 << 1;
        }
        if (!bVar5) {
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            keyer_elem_put(0);
          }
        }
      }
    }
    if (0x4b0 < DAT_0001fa38) break;
    local_11 = local_11 + 1;
  }
  return;
}


// ===== align_load_preset @ fffbb567 (1020 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb8cc) */
/* WARNING: Removing unreachable block (ram,0xfffbb7f9) */
/* Sets up the radio for the current alignment item from preset 0xFFF88CD4[item] (VFO A/B, band
   memory, mode bits, optional frequency, TX power for items 0x45..0xDA) */

void align_load_preset(void)

{
  byte bVar1;
  bool bVar2;
  vfo_rec *pvVar3;
  int iVar4;
  vfo_rec *local_10;
  vfo_rec *local_c;
  byte bStack_5;
  byte local_4;
  byte local_3;
  byte local_2;
  byte local_1;
  
  local_1 = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc + 3];
  bVar1 = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc];
  bVar2 = (bVar1 & 0x80) == 0;
  if (bVar2) {
    local_c = &g_opstate.vfo_a;
  }
  else {
    local_c = &g_opstate.vfo_b;
  }
  if (bVar2) {
    local_2 = bandstack_level_a[local_1];
    local_10 = bandstack_a[local_2] + local_1;
  }
  else {
    local_2 = bandstack_level_b[local_1];
    local_10 = bandstack_b[local_2] + local_1;
  }
  pvVar3 = local_c;
  for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
    pvVar3->mode = local_10->mode;
    pvVar3 = (vfo_rec *)&pvVar3->flags1;
    local_10 = (vfo_rec *)&local_10->flags1;
  }
  if ((bVar1 & 0x20) == 0) {
    local_c->nar_flags = local_c->nar_flags & 0x7f;
  }
  else {
    local_c->nar_flags = local_c->nar_flags | 0x80;
  }
  if ((bVar1 & 8) == 0) {
    local_c->nar_flags = local_c->nar_flags & 0xef;
  }
  else {
    local_c->nar_flags = local_c->nar_flags | 0x10;
  }
  bVar1 = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc + 1];
  if ((bVar1 & 8) == 0) {
    local_c->flags3 = local_c->flags3 & 0xfd;
  }
  else {
    local_c->flags3 = local_c->flags3 | 2;
  }
  if ((bVar1 & 4) == 0) {
    local_c->flags3 = local_c->flags3 & 0xfe;
  }
  else {
    local_c->flags3 = local_c->flags3 | 1;
  }
  if ((bVar1 & 2) == 0) {
    local_c->flags5 = local_c->flags5 & 0xfd;
  }
  else {
    local_c->flags5 = local_c->flags5 | 2;
  }
  if ((bVar1 & 1) == 0) {
    local_c->flags5 = local_c->flags5 & 0xfe;
  }
  else {
    local_c->flags5 = local_c->flags5 | 1;
  }
  local_4 = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc + 4];
  local_c->mode = local_c->mode & 0xf0;
  local_c->mode = local_4 & 0xf | local_c->mode;
  g_opstate.meter_sel = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc + 5];
  local_3 = BYTE_ARRAY_fff88cd4[(uint)PTR_g_ui_00025d4c->align_item * 0xc];
  if ((local_3 & 0x40) != 0) {
    local_c->freq_be[0] =
         (byte)((uint)*(undefined4 *)(&LAB_fff88cdc + (uint)PTR_g_ui_00025d4c->align_item * 0xc) >>
               0x18);
    local_c->freq_be[1] =
         (byte)((uint)*(undefined4 *)(&LAB_fff88cdc + (uint)PTR_g_ui_00025d4c->align_item * 0xc) >>
               0x10);
    local_c->freq_be[2] =
         (byte)((uint)*(undefined4 *)(&LAB_fff88cdc + (uint)PTR_g_ui_00025d4c->align_item * 0xc) >>
               8);
    local_c->freq_be[3] = (&LAB_fff88cdc)[(uint)PTR_g_ui_00025d4c->align_item * 0xc];
    PTR_g_ui_00025d4c->freq_refresh_req = 1;
  }
  DAT_00021048 = rf_power_ptr(&local_4,&bStack_5);
  if ((PTR_g_ui_00025d4c->align_item < 0x45) || (0xda < PTR_g_ui_00025d4c->align_item)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    DAT_0001fa3e = (ushort)(PTR_g_ui_00025d4c->align_item - 0x45) % 0xf;
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
    if ((PTR_g_ui_00025d4c->align_item < 0xde) || (0xe9 < PTR_g_ui_00025d4c->align_item)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      DAT_0001fa3e = (ushort)(PTR_g_ui_00025d4c->align_item - 0xde) % 0xc;
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
  align_ialc_park(PTR_g_ui_00025d4c->align_item);
  FUN_fffbbb85(PTR_g_ui_00025d4c->align_item);
  return;
}


// ===== FUN_fffbb963 @ fffbb963 (161 bytes)

void FUN_fffbb963(char param_1)

{
  ushort uVar1;
  
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (PTR_g_ui_00025d4c->align_item == 0) {
        PTR_g_ui_00025d4c->align_item = 0x104;
      }
      else {
        PTR_g_ui_00025d4c->align_item = PTR_g_ui_00025d4c->align_item - 1;
      }
      if (PTR_g_ui_00025d4c->align_cursor_row != 0) {
        PTR_g_ui_00025d4c->align_cursor_row = PTR_g_ui_00025d4c->align_cursor_row - 1;
      }
    }
  }
  else {
    uVar1 = PTR_g_ui_00025d4c->align_item + 1;
    if (uVar1 < 0x105) {
      PTR_g_ui_00025d4c->align_item = uVar1;
    }
    else {
      PTR_g_ui_00025d4c->align_item = 0;
    }
    if (PTR_g_ui_00025d4c->align_cursor_row < 8) {
      PTR_g_ui_00025d4c->align_cursor_row = PTR_g_ui_00025d4c->align_cursor_row + 1;
    }
  }
  align_load_preset();
  return;
}


// ===== FUN_fffbba04 @ fffbba04 (11 bytes)

void FUN_fffbba04(char param_1)

{
  FUN_fffbbbdc((int)param_1);
  return;
}


// ===== align_store @ fffbba0f (31 bytes)

/* DSP key in alignment mode: runs the store handler 0xFFF89910[item] for the current item (+0x1DE)
    */

undefined1 align_store(void)

{
  (*(code *)(&PTR_align_store_ui4_fff89910)[PTR_g_ui_00025d4c->align_item])();
  return 1;
}


// ===== FUN_fffbba2e @ fffbba2e (113 bytes)

void FUN_fffbba2e(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  if ((DAT_0001b4d7 != '\0') && (bVar1 = swtimer_expired(0x42), bVar1 == 1)) {
    DAT_0001b4d8 = DAT_0001b4d8 + 1;
    uVar2 = dsp_status1_raw();
    DAT_0001ff64 = (uVar2 >> 8) + DAT_0001ff64;
    if (DAT_0001b4d8 < 0x10) {
      swtimer_start(0x42,0x1e);
      return;
    }
    uVar3 = (uint)DAT_0001ff64;
    if (DAT_0001b4d8 != 0) {
      uVar3 = uVar3 / DAT_0001b4d8;
    }
    *DAT_00021044 = (char)uVar3;
    DAT_0001b4d7 = 0;
    return;
  }
  return;
}


// ===== align_ialc_park @ fffbba9f (230 bytes)

/* (item): while an I-ALC item (index 0x3A..0x44) is selected, saves the band's 100 W FALC/TXG (50 W
   on 70 MHz) to 0x12167/0x12168 and sets them to 0xFF; restores them on leaving [fact] */

void align_ialc_park(ushort param_1)

{
  bool bVar1;
  ushort uVar2;
  byte *local_8;
  
  if (param_1 != DAT_0001ff66) {
    if ((DAT_0001ff66 < 0x3a) || (0x44 < DAT_0001ff66)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uVar2 = DAT_0001ff66 * 0xf - 0x321;
      local_8 = &PTR_g_cfg105_00025d50->a001_gn_vdd_mtr + uVar2;
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
      local_8 = &PTR_g_cfg105_00025d50->a001_gn_vdd_mtr + uVar2;
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
      puVar1 = (undefined1 *)mic_gain_ptr();
      *puVar1 = DAT_00012169;
    }
    if (param_1 == 0xf5) {
      puVar1 = (undefined1 *)mic_gain_ptr();
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
  if (PTR_g_ui_00025d4c->align_item == 2) {
    cal_adjust(0x19,0xe6,param_1);
    return;
  }
  cal_adjust(0,0xff,param_1);
  return;
}


// ===== cal_adjust @ fffbbc0a (74 bytes)

/* cfg105[0x20CE2] += delta, clamped to [min,max] (alignment value edit, ZZ00 mode) */

void cal_adjust(byte param_1,byte param_2,char param_3)

{
  short sVar1;
  byte *pbVar2;
  byte local_a;
  
  pbVar2 = &PTR_g_cfg105_00025d50->a001_gn_vdd_mtr + PTR_g_ui_00025d4c->align_item;
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


// ===== align_store_ui4 @ fffbbc54 (27 bytes)

/* cal[item] = UI-state +4 (0x20B08) >> 4 (item 0) */

void align_store_ui4(void)

{
  (&PTR_g_cfg105_00025d50->a001_gn_vdd_mtr)[PTR_g_ui_00025d4c->align_item] =
       (byte)(PTR_g_ui_00025d4c->adc_pa_vdd >> 4);
  return;
}


// ===== align_store_dsp_level @ fffbbc6f (31 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbbc6f) */
/* WARNING: Removing unreachable block (ram,0xfffbbc8b) */
/* cal[item] = dsp_signal_level() (11 items from 32) */

ushort align_store_dsp_level(void)

{
  ushort uVar1;
  cfg105 *pcVar2;
  ushort uVar3;
  
  pcVar2 = PTR_g_cfg105_00025d50;
  uVar1 = PTR_g_ui_00025d4c->align_item;
  uVar3 = dsp_signal_level();
  (&pcVar2->a001_gn_vdd_mtr)[uVar1] = (byte)uVar3;
  return uVar3;
}


// ===== align_store_ui2 @ fffbbc8e (42 bytes)

/* cal[item] = UI-state +2 (0x20B06) >> 4 (54 items from 70) */

void align_store_ui2(void)

{
  (&PTR_g_cfg105_00025d50->a001_gn_vdd_mtr)[PTR_g_ui_00025d4c->align_item] =
       (byte)(PTR_g_ui_00025d4c->adc_mcup_for >> 4);
  return;
}


// ===== align_store_dsp_async @ fffbbcb8 (71 bytes)

/* Starts a DSP status read (dsp_status1_raw, timer 0x42 30 ms); the result goes to cal[item] later
   (items 45..47) */

void align_store_dsp_async(void)

{
  ushort uVar1;
  
  DAT_00021044 = &PTR_g_cfg105_00025d50->a001_gn_vdd_mtr + PTR_g_ui_00025d4c->align_item;
  DAT_0001b4d7 = 1;
  uVar1 = dsp_status1_raw();
  DAT_0001ff64 = uVar1 >> 8;
  DAT_0001b4d8 = 1;
  swtimer_start(0x42,0x1e);
  return;
}


// ===== align_store_ui8_scaled @ fffbbcff (83 bytes)

/* cal[item] = (0x20B0C >> 4) * 0x4666 / 137 rounded (item 245) */

void align_store_ui8_scaled(void)

{
  (&PTR_g_cfg105_00025d50->a001_gn_vdd_mtr)[PTR_g_ui_00025d4c->align_item] =
       SUB41(ROUND((float)((uint)(byte)(g_ui.adc_alcm >> 4) * (uint)g_cfg105.a014_mt_alc_mtr_pos) /
                   137.0 + 0.5),0);
  return;
}


// ===== align_store_nop @ fffbbd52 (1 bytes)

/* Empty store handler (191 of the 261 items) */

void align_store_nop(void)

{
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
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  
  FUN_fffc4d93();
  scope_cursor_follow();
  FUN_fffcdb26();
  bVar3 = key_cancel_check();
  if (bVar3 == 1) {
    PTR_g_ui_00025d54->key_ev_flag = 0;
  }
  if (DAT_0001b4db == '\x01') {
    bVar3 = swtimer_expired(0x3f);
    if (bVar3 == 1) {
      DAT_0001b4db = '\0';
      PTR_g_ui_00025d54->key_ev_flag = 1;
      PTR_g_ui_00025d54->key_ev_type = 2;
      PTR_g_ui_00025d54->key_ev_code = DAT_0001fa40;
    }
  }
  else if ((DAT_0001b4dc == '\x01') && (bVar3 = swtimer_expired(0x40), bVar3 == 1)) {
    key_call_repeat();
    return;
  }
  if (PTR_g_ui_00025d54->key_ev_flag != 0) {
    PTR_g_ui_00025d54->key_ev_flag = 0;
    if (PTR_g_ui_00025d54->dialog_shown == 1) {
      DAT_0001216b = '\0';
    }
    if (DAT_0001216b == '\0') {
      if (PTR_g_ui_00025d54->key_ev_type == 1) {
        PTR_g_ui_00025d54->key_consumed = 0;
        DAT_0001216b = '\x01';
        DAT_0001216a = PTR_g_ui_00025d54->key_ev_src;
        uVar1 = PTR_g_ui_00025d54->key_ev_code;
        if (DAT_0001216a == 4) {
          key_touch_scope_tune(uVar1);
          return;
        }
        DAT_0001fa40 = uVar1;
        DAT_0001216c = key_class_of(uVar1);
        if ((DAT_0001216c == 0) || (DAT_0001216c == 2)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          key_call_press();
          if (PTR_g_ui_00025d54->key_consumed == 0) {
            key_call_short();
          }
        }
        else if (DAT_0001216c == 1) {
          key_call_press();
        }
        if (DAT_0001fa40 == 0x340) {
          DAT_0001216b = '\0';
        }
        iVar4 = FUN_fffd4c17();
        if (iVar4 == 1) {
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
      if (DAT_0001216a == 4) {
        DAT_0001216b = 0;
        return;
      }
      if (DAT_0001fa40 != PTR_g_ui_00025d54->key_ev_code) {
        if (DAT_0001216c == 2) {
          if (PTR_g_ui_00025d54->key_ev_code == 0x340) {
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
      if (PTR_g_ui_00025d54->key_ev_type == 0) {
        if (DAT_0001216c == 1) {
          if (PTR_g_ui_00025d54->key_consumed == 0) {
            key_call_short();
          }
        }
        else if (DAT_0001216c == 2) {
          key_call_release();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if (PTR_g_ui_00025d54->key_ev_type != 2) {
        if (DAT_0001216c == 2) {
          key_call_release();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if ((DAT_0001216c == 1) || (DAT_0001216c == 2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if ((bVar2) && (PTR_g_ui_00025d54->key_consumed == 0)) {
        key_call_long();
      }
      DAT_0001216b = '\x02';
      if ((DAT_0001fa40 == 0x300) && (PTR_g_ui_00025d54->key_consumed == 0)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        DAT_0001216b = 0;
        return;
      }
    }
    else if (DAT_0001216b == '\x02') {
      if ((DAT_0001216c == 2) && (PTR_g_ui_00025d54->key_consumed == 0)) {
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

byte key_cancel_check(void)

{
  bool bVar1;
  byte local_2;
  
  if (PTR_g_ui_00025d54->key_ev_flag == 0) {
    local_2 = 0;
  }
  else {
    if ((PTR_g_ui_00025d54->key_ev_src == 4) || (PTR_g_ui_00025d54->key_ev_code != 0x340)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (PTR_g_ui_00025d54->key_ev_type == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_g_ui_00025d54->dvs_state == 1) {
        PTR_g_ui_00025d54->dvs_state = 0;
        g_ui.msg_slot = 0;
        if (g_ui.ptt_msg_play == 1) {
          g_ui.ptt_msg_play = 0;
        }
      }
      else if (PTR_g_ui_00025d54->dvs_state == 2) {
        PTR_g_ui_00025d54->dvs_state = 0;
        g_ui.msg_slot = 0;
      }
      PTR_g_ui_00025d54->ptt_mic = 0;
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

byte key_class_of(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  byte bStack_5;
  
  bVar2 = key_assign_slot(param_1);
  if (bVar2 == 0xff) {
    bStack_5 = *(byte *)((int)&key_class_table + (uint)param_1);
  }
  else {
    uVar1 = (uint)bVar2;
    if (uVar1 < 0xd) {
      bStack_5 = *(byte *)((int)&key_class_table +
                          (uint)*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20));
    }
    else {
      bStack_5 = BYTE_ARRAY_fff834b3[uVar1 + 3];
    }
  }
  return bStack_5;
}


// ===== key_assign_slot @ fffbc225 (122 bytes)

/* assignable code (0x348,0x34E,0x35B..0x35E) -> slot from settings 0x9AC8..0x9ACD */

byte key_assign_slot(short param_1)

{
  undefined1 local_4;
  
  local_4 = 0xff;
  if (param_1 == 0x35e) {
    local_4 = g_opstate.ex030123_mic_p4;
  }
  else if (param_1 == 0x34e) {
    local_4 = g_opstate.ex030125_mic_down;
  }
  else if (param_1 == 0x35b) {
    local_4 = g_opstate.ex030120_mic_p1;
  }
  else if (param_1 == 0x35c) {
    local_4 = g_opstate.ex030121_mic_p2;
  }
  else if (param_1 == 0x35d) {
    local_4 = g_opstate.ex030122_mic_p3;
  }
  else if (param_1 == 0x348) {
    local_4 = g_opstate.ex030124_mic_up;
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
  
  if (g_opstate.active_vfo == VFO_A) {
    local_4 = PTR_g_ui_00025d54->freq_a;
  }
  else {
    local_4 = PTR_g_ui_00025d54->freq_b;
  }
  local_7 = g_opstate.active_vfo != VFO_A;
  bVar1 = scope_span_index(local_7);
  if (local_4 < PTR_g_ui_00025d54->scope_cursor_start) {
    local_4 = FUN_fffb3aee();
  }
  else {
    if (local_4 <=
        *(int *)(scope_span_table + (uint)bVar1 * 4) + PTR_g_ui_00025d54->scope_cursor_start) {
      return;
    }
    local_4 = FUN_fffb3aee(local_4 - *(int *)(scope_span_table + (uint)bVar1 * 4));
  }
  PTR_g_ui_00025d54->scope_cursor_start = local_4;
  for (bStack_6 = 0; bStack_6 < 4; bStack_6 = bStack_6 + 1) {
    g_opstate.scope_cursor_start_be[bStack_6] = (byte)(local_4 >> ((3 - bStack_6 & 3) << 3));
  }
  bandmem_set('\x01',local_4);
  return;
}


// ===== key_call_press @ fffbc35f (47 bytes)

/* JSR key_press_table[code] */

void key_call_press(void)

{
  char cVar1;
  
  cVar1 = key_dest_allowed(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_press_table)[DAT_0001fa40])();
  return;
}


// ===== key_call_short @ fffbc38e (47 bytes)

/* JSR key_short_table[code] */

void key_call_short(void)

{
  char cVar1;
  
  cVar1 = key_dest_allowed(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_short_table)[DAT_0001fa40])();
  return;
}


// ===== key_call_long @ fffbc3bd (73 bytes)

/* JSR key_long_table[code] */

void key_call_long(void)

{
  bool bVar1;
  char cVar2;
  
  cVar2 = key_dest_allowed(DAT_0001fa40,0);
  if ((cVar2 == '\0') && (DAT_0001fa40 != 0x300)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    (*(code *)(&key_long_table)[DAT_0001fa40])();
    return;
  }
  return;
}

