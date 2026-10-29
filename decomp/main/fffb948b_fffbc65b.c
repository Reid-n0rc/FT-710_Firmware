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
  bVar6 = DAT_00020b18;
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
    DAT_00020b48 = 0;
    DAT_000120bb = bVar5;
  }
  if (bVar6 < 7) {
    cStack_a = '\x03';
  }
  else {
    cStack_a = '\b';
  }
  if (((DAT_0001b4d2 != cStack_a) && (DAT_0001b4d2 = cStack_a, cStack_a == '\b')) &&
     ((bVar6 = vfo_mode(1), 3 < bVar6 || (bVar6 = FUN_fffba192(), bVar6 == 0)))) {
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
      DAT_00020b49 = 0;
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
  DAT_00020b2f = 0;
  DAT_0001215f = 0;
  sstr(0x120bc,0,0xa0);
  return;
}


// ===== keyer_task @ fffb98e9 (2120 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb9e42) */
/* WARNING: Removing unreachable block (ram,0xfffb99ff) */
/* WARNING: Removing unreachable block (ram,0xfffb9dba) */
/* WARNING: Removing unreachable block (ram,0xfffb9dc9) */
/* WARNING: Removing unreachable block (ram,0xfffb9e12) */
/* WARNING: Removing unreachable block (ram,0xfffb9e51) */
/* WARNING: Removing unreachable block (ram,0xfffb9fbe) */
/* WARNING: Removing unreachable block (ram,0xfffb9d50) */
/* WARNING: Removing unreachable block (ram,0xfffb9e7a) */
/* main_loop task 12: CW keyer (speed 0x9C03, 0x20B97) [inference] */

void keyer_task(void)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
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
  
  local_1 = DAT_00009aa9;
  bVar3 = FUN_fffba192();
  if ((bVar3 == 0) || (DAT_00020b97 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    keyer_init();
    FUN_fffbb1c2();
    DAT_00020b2a = 0;
    return;
  }
  bVar3 = swtimer_expired(0x13);
  if ((bVar3 != 1) || (DAT_00020f0c != '\0')) {
    return;
  }
  if (DAT_0001b4d5 != DAT_00009c03) {
    bVar1 = false;
    if (DAT_00012164 == '\0') {
      FUN_fffbb283(&cStack_18,&cStack_19);
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
  DAT_00021010 = ((local_1 + 0x19) * DAT_00021014) / 10;
  DAT_0001215c = FUN_fffb548a();
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
  switch(DAT_00020b2f) {
  case 0:
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 1;
    swtimer_start(0x19,(ushort)DAT_0001215c);
    FUN_fffbaff6();
  case 1:
    if (DAT_0001215f < 2) {
      FUN_fffba840(DAT_0001215f);
    }
    else if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,'\0');
    }
    break;
  case 2:
    if (DAT_0001215d != '\x01') {
      return;
    }
    sstr(0x120bc,0,0xa0);
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 3;
    swtimer_start(0x19,(ushort)DAT_0001215c);
    swtimer_start(0x1b,10000);
    FUN_fffbaff6();
    DAT_00021040 = vfo_rec_ptr(1);
    iVar6 = FUN_fffb521a();
    if (iVar6 == 1) {
      DAT_00012166 = '\x01';
      DAT_00021040[0x14] = DAT_00021040[0x14] & 0xfd;
    }
    else {
      DAT_00012166 = '\0';
    }
  case 3:
    if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,'\x01');
    }
    break;
  case 4:
    if (DAT_00012166 == '\x01') {
      DAT_00012166 = '\0';
      DAT_00021040[0x14] = DAT_00021040[0x14] | 2;
    }
    DAT_0001fa3a = DAT_0001fa38;
    if (DAT_0001fa38 != 0) {
      bStack_9 = DAT_00020ccc;
      if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        bStack_9 = 1;
      }
      iVar6 = (uint)bStack_9 * 0x98;
      (&DAT_0000930f)[iVar6] = (char)(DAT_0001fa38 >> 8);
      (&DAT_00009310)[iVar6] = (char)DAT_0001fa3a;
      puStack_8 = (undefined *)(iVar6 + 0x9311);
      smovf(puStack_8,0x120bc,0x96);
      eeprom_save_msg(0,(uint)bStack_9);
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
    bVar3 = FUN_fffb2dfe();
    if (bVar3 == 1) {
      return;
    }
    bStack_9 = DAT_00020ccc;
    if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
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
    if ((&DAT_00009aad)[bStack_9] == '\x01') {
      iVar6 = (uint)bStack_9 * 0x98;
      DAT_0001fa38 = CONCAT11((&DAT_000093a7)[iVar6],(&DAT_000093a8)[iVar6]);
      puStack_8 = (undefined *)(iVar6 + 0x93a9);
      smovf(0x120bc,puStack_8,0x96);
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
          uStack_e = FUN_fffba30c();
          uStack_c = 1000;
          for (bStack_11 = 0; bStack_11 < 4; bStack_11 = bStack_11 + 1) {
            uVar5 = (uint)uStack_e;
            if (uStack_c != 0) {
              uVar5 = uVar5 / uStack_c;
            }
            bStack_12 = (byte)uVar5;
            uVar7 = uStack_e;
            if (uStack_c != 0) {
              uVar7 = uStack_e / uStack_c;
            }
            uStack_e = uStack_e - uVar7 * uStack_c;
            uStack_c = uStack_c / 10;
            bStack_14 = nib2hex(bStack_12);
            if ((bStack_11 == 0) && (bStack_14 == 0x30)) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (!bVar1) {
              bStack_14 = FUN_fffbb2bf(bStack_14);
              bStack_16 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2];
              bStack_15 = BYTE_ARRAY_fff815c3[(uint)bStack_14 * 2 + 1];
              for (bStack_10 = 0; bStack_10 < bStack_16; bStack_10 = bStack_10 + 1) {
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
        else if (bStack_14 == 0x3c) {
          iVar6 = FUN_fffb521a();
          if ((iVar6 == 1) && (uStack_e = FUN_fffba30c(), uStack_e < 9999)) {
            uStack_e = uStack_e + 1;
            FUN_fffba336(uStack_e);
          }
        }
        else if (bStack_14 == 0x3e) {
          iVar6 = FUN_fffb521a();
          if ((iVar6 == 1) && (uStack_e = FUN_fffba30c(), 1 < uStack_e)) {
            uStack_e = uStack_e - 1;
            FUN_fffba336(uStack_e);
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
                FUN_fffbb338(bStack_14);
              }
            }
          }
        }
        else {
          bStack_10 = 0;
          if (bStack_16 == 0) {
            for (; bStack_10 < 4; bStack_10 = bStack_10 + 1) {
              FUN_fffbb024(0);
            }
          }
          else {
            for (; bStack_10 < bStack_16; bStack_10 = bStack_10 + 1) {
              if ((bStack_15 & 0x80) == 0) {
                FUN_fffbb024(1);
              }
              else {
                FUN_fffbb024(2);
              }
              FUN_fffbb024(0);
              bStack_15 = bStack_15 << 1;
            }
            if (cStack_17 == '\0') {
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
    swtimer_start(0x19,(ushort)DAT_0001215c);
    DAT_00020b2f = 6;
    FUN_fffbaff6();
  case 6:
    if (DAT_0001fa3a == DAT_0001fa3c) {
      DAT_00020b2f = 7;
      if (DAT_00020cd5 == '\x01') {
        swtimer_start(0x1c,(ushort)DAT_00009ab2 * 1000);
      }
      if ((DAT_00012165 == '\x01') && (uStack_e = FUN_fffba30c(), uStack_e < 9999)) {
        uStack_e = uStack_e + 1;
        FUN_fffba336(uStack_e);
      }
    }
    else {
      FUN_fffbb283(&cStack_18,&cStack_19);
      if ((cStack_18 == '\x01') || (cStack_19 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020cd5 = '\0';
        DAT_00020b2f = 7;
      }
    }
    FUN_fffba9c3();
    break;
  case 7:
    if (DAT_00020cd5 == '\x01') {
      bVar3 = swtimer_expired(0x1c);
      if (bVar3 == 1) {
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


// ===== FUN_fffba131 @ fffba131 (97 bytes)

undefined * FUN_fffba131(undefined4 param_1,int param_2,byte param_3)

{
  bool bVar1;
  int iVar2;
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
  smovf(&DAT_000096a0 + iVar2,param_1,(uint)local_9);
  return &DAT_000096a0 + iVar2 + local_9;
}


// ===== FUN_fffba192 @ fffba192 (378 bytes)

byte FUN_fffba192(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  byte bStack_5;
  
  bVar4 = ptt_source_get();
  bVar5 = vfo_mode(1);
  bStack_5 = 0;
  cVar6 = FUN_fffb50d7(bVar5);
  cVar3 = DAT_00009a9f;
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
        bStack_5 = 3;
      }
      else {
        bStack_5 = 2;
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
        bStack_5 = 3;
      }
      else {
        bStack_5 = 2;
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
  return *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)DAT_00009c05 * 2 + 0x110);
}


// ===== FUN_fffba377 @ fffba377 (1225 bytes)

void FUN_fffba377(char param_1,char param_2)

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
    DAT_00020b2a = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  bVar2 = swtimer_expired(0x17);
  if (bVar2 != 1) {
    if (DAT_00012160 == '\0') {
      FUN_fffbb283(&cStack_9,&cStack_a);
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
  if ((local_2 == '\x01') && (iVar3 = FUN_fffbb10b(), iVar3 == 1)) {
    DAT_00020b2f = 4;
    return;
  }
  if (DAT_00012161 == '\0') {
    FUN_fffbb283(&cStack_9,&cStack_a);
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
  FUN_fffbb024(DAT_00012161);
  return;
}


// ===== FUN_fffba840 @ fffba840 (387 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba98f) */

void FUN_fffba840(char param_1)

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
    DAT_00020b2a = 0;
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
    FUN_fffbb024(DAT_00012161);
    return;
  }
  if (DAT_00012161 == '\x01') {
    DAT_00012161 = '\0';
    iStack_8 = DAT_00021014;
  }
  else {
    FUN_fffbb283(&cStack_9,&cStack_a);
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
  byte bVar2;
  undefined2 uVar3;
  ushort uStack_6;
  int iStack_4;
  
  bVar2 = swtimer_expired(0x17);
  if (bVar2 == 1) {
    if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa38 >> 3)] & 1 << ((byte)DAT_0001fa38 & 7)) ==
        0) {
      iStack_4 = DAT_00021014;
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
    }
    else {
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
      if ((DAT_0001fa3c == uStack_6) ||
         (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_6 >> 3)] & 1 << ((byte)uStack_6 & 7)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        iStack_4 = DAT_00021010;
        uVar3 = FUN_fffbb16b(uStack_6);
        uStack_6 = FUN_fffbb16b(uVar3);
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


// ===== FUN_fffbaa81 @ fffbaa81 (1397 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbafc6) */

void FUN_fffbaa81(byte param_1)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  uint freq;
  bool bVar4;
  byte bVar5;
  byte bVar6;
  undefined2 uVar7;
  int iVar8;
  byte bStack_18;
  byte bStack_17;
  char cStack_16;
  ushort uStack_12;
  uint uStack_10;
  
  freq = DAT_00020f50;
  vfo_rec_ptr(1);
  cVar3 = DAT_00020b18;
  cStack_16 = -1;
  bVar4 = false;
  if (DAT_0001fa38 == DAT_0001fa3a) {
    if ((DAT_00012164 == '\0') && (bVar5 = swtimer_expired(0x1a), bVar5 == 1)) {
      if ((DAT_00020b6b == '\x01') || (bVar4 = tx_freq_allowed(freq), !bVar4)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if ((bVar4) && (DAT_00020b2a == '\x01')) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (bVar4) {
        DAT_00020b2a = '\0';
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
    if ((bVar1) && (DAT_00020b2f != '\x06')) {
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
      iVar8 = FUN_fffb521a();
      if (iVar8 == 1) {
        uStack_12 = DAT_0001fa3a;
        for (bStack_17 = 0; bStack_17 < bStack_18; bStack_17 = bStack_17 + 1) {
          if (bStack_17 != 0) {
            uStack_12 = FUN_fffbb16b(uStack_12);
          }
          if (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_12 >> 3)] & 1 << ((byte)uStack_12 & 7)) !=
              0) {
            bVar4 = true;
            break;
          }
        }
        if (bVar4) {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if (bVar4) {
            DAT_00020b2a = '\x01';
          }
          if (cVar3 != '\x03') {
            tx_freq_allowed(freq);
          }
        }
        else {
          bVar5 = swtimer_expired(0x1a);
          if (bVar5 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              DAT_00020b2a = '\0';
            }
          }
        }
      }
    }
    else {
      iVar8 = FUN_fffb521a();
      if (iVar8 == 1) {
        if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa3a >> 3)] & 1 << ((byte)DAT_0001fa3a & 7))
            == 0) {
          bVar5 = swtimer_expired(0x1a);
          if (bVar5 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              DAT_00020b2a = '\0';
            }
          }
        }
        else {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if (bVar4) {
            DAT_00020b2a = 1;
            return;
          }
          if ((cVar3 != '\x03') && (bVar4 = tx_freq_allowed(freq), bVar4)) {
            return;
          }
        }
      }
    }
  }
  bVar5 = swtimer_expired(0x19);
  if (bVar5 != 1) {
    swtimer_start(0x18,0);
    return;
  }
  bVar5 = swtimer_expired(0x18);
  uVar2 = DAT_0001fa3a;
  if (bVar5 == 1) {
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
        if (((uint)(byte)(&DAT_000120bc)[(byte)(DAT_0001fa3a >> 3)] & 1 << ((byte)DAT_0001fa3a & 7))
            == 0) {
          if (DAT_00020b2f == '\x06') {
            FUN_fffbb1c2();
          }
          FUN_fffbb1dd(0);
          if (DAT_00012164 != '\0') {
            swtimer_start(0x1a,*(ushort *)(BYTE_ARRAY_fff88270 + (uint)DAT_00009c05 * 2 + 0x110));
          }
          uStack_10 = DAT_00021014;
          uStack_12 = FUN_fffbb16b(uVar2);
          DAT_00012164 = 0;
        }
        else {
          if (DAT_00020b2f == '\x06') {
            FUN_fffbb185();
          }
          FUN_fffbb1dd(1);
          uStack_12 = FUN_fffbb16b(uVar2);
          if ((DAT_0001fa38 == uStack_12) ||
             (((uint)(byte)(&DAT_000120bc)[(byte)(uStack_12 >> 3)] & 1 << ((byte)uStack_12 & 7)) ==
              0)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (bVar4) {
            uStack_10 = DAT_00021010;
            uVar7 = FUN_fffbb16b(uStack_12);
            uStack_12 = FUN_fffbb16b(uVar7);
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
      bVar5 = (byte)(DAT_0001fa3a >> 3);
      bVar6 = (byte)DAT_0001fa3a & 7;
      if (((uint)(byte)(&DAT_000120bc)[bVar5] & 1 << bVar6) == 0) {
        if (DAT_00020b2f == '\x06') {
          FUN_fffbb1c2();
        }
        FUN_fffbb1dd(0);
        if (DAT_00012164 != '\0') {
          swtimer_start(0x1a,*(ushort *)(BYTE_ARRAY_fff88270 + (uint)DAT_00009c05 * 2 + 0x110));
        }
        DAT_00012164 = 0;
      }
      else {
        if (DAT_00020b2f == '\x06') {
          FUN_fffbb185();
        }
        FUN_fffbb1dd(1);
        DAT_00012164 = 1;
        (&DAT_000120bc)[bVar5] = (&DAT_000120bc)[bVar5] & ~(byte)(1 << bVar6);
      }
      if (param_1 == 0) {
        uStack_10 = 2000;
      }
      else {
        uStack_10 = *(uint *)(&DAT_00021018 + ((uint)uVar2 % 10) * 4);
      }
      timer_start_us(0x18,uStack_10 & 0xffff);
      DAT_0001fa3a = FUN_fffbb16b(uVar2);
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
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte local_6;
  
  if (param_1 != '\0') {
    cat_apo_reset();
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
      FUN_fffbb185();
    }
    else {
      (&DAT_000120bc)[bVar2] = (&DAT_000120bc)[bVar2] & ~bVar1;
      FUN_fffbb1c2();
    }
    uVar3 = FUN_fffbb16b(DAT_0001fa38);
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
    DAT_0001fa38 = FUN_fffbb16b(DAT_0001fa38);
  }
  uVar3 = FUN_fffbb185();
  return uVar3;
}


// ===== FUN_fffbb10b @ fffbb10b (96 bytes)

undefined1 FUN_fffbb10b(void)

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
  byte bVar1;
  undefined1 uStack_1;
  
  bVar1 = vfo_mode(1);
  if (bVar1 < 2) {
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

void FUN_fffbb1dd(byte param_1)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar3 = FUN_fffba192();
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
  if ((DAT_00009aa0 == '\x01') && (param_1 == 0)) {
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

void FUN_fffbb283(void *param_1,void *param_2)

{
  bool bVar1;
  
  if (DAT_00009aa8 != '\0') {
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
    bVar7 = BYTE_ARRAY_fff815c3[(uint)bVar2 * 2];
    local_13 = BYTE_ARRAY_fff815c3[(uint)bVar2 * 2 + 1];
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
          bVar7 = FUN_fffbb2bf(cVar6);
          bVar2 = BYTE_ARRAY_fff815c3[(uint)bVar7 * 2];
          local_13 = BYTE_ARRAY_fff815c3[(uint)bVar7 * 2 + 1];
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
  bool bVar2;
  undefined *local_10;
  byte *local_c;
  byte bStack_5;
  byte local_4;
  byte local_3;
  byte local_2;
  byte local_1;
  
  local_1 = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc + 3];
  bVar1 = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  bVar2 = (bVar1 & 0x80) == 0;
  if (bVar2) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (bVar2) {
    local_2 = (&DAT_000060b1)[local_1];
    local_10 = &DAT_00004761 + (uint)local_2 * 0x438 + (uint)local_1 * 0x5a;
  }
  else {
    local_2 = (&DAT_000060bd)[local_1];
    local_10 = &DAT_00005409 + (uint)local_2 * 0x438 + (uint)local_1 * 0x5a;
  }
  smovf(local_c,local_10,0x5a);
  if ((bVar1 & 0x20) == 0) {
    local_c[4] = local_c[4] & 0x7f;
  }
  else {
    local_c[4] = local_c[4] | 0x80;
  }
  if ((bVar1 & 8) == 0) {
    local_c[4] = local_c[4] & 0xef;
  }
  else {
    local_c[4] = local_c[4] | 0x10;
  }
  bVar1 = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc + 1];
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
  local_4 = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc + 4];
  *local_c = *local_c & 0xf0;
  *local_c = local_4 & 0xf | *local_c;
  DAT_00009c5b = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc + 5];
  local_3 = BYTE_ARRAY_fff88cd4[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  if ((local_3 & 0x40) != 0) {
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
  DAT_00021048 = FUN_fffc7827(&local_4,&bStack_5);
  if ((*(ushort *)(PTR_DAT_00025d4c + 0x1de) < 0x45) ||
     (0xda < *(ushort *)(PTR_DAT_00025d4c + 0x1de))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    DAT_0001fa3e = (ushort)(*(ushort *)(PTR_DAT_00025d4c + 0x1de) - 0x45) % 0xf;
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
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      DAT_0001fa3e = (ushort)(*(short *)(PTR_DAT_00025d4c + 0x1de) - 0xdeU) % 0xc;
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
  (*(code *)(&PTR_LAB_fff89910)[*(ushort *)(PTR_DAT_00025d4c + 0x1de)])();
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
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  
  FUN_fffc4d93();
  scope_cursor_follow();
  FUN_fffcdb26();
  bVar3 = key_cancel_check();
  if (bVar3 == 1) {
    PTR_DAT_00025d54[0xa0] = 0;
  }
  if (DAT_0001b4db == '\x01') {
    bVar3 = swtimer_expired(0x3f);
    if (bVar3 == 1) {
      DAT_0001b4db = '\0';
      PTR_DAT_00025d54[0xa0] = 1;
      PTR_DAT_00025d54[0x9d] = 2;
      *(ushort *)(PTR_DAT_00025d54 + 0x9e) = DAT_0001fa40;
    }
  }
  else if ((DAT_0001b4dc == '\x01') && (bVar3 = swtimer_expired(0x40), bVar3 == 1)) {
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
        uVar1 = *(ushort *)(PTR_DAT_00025d54 + 0x9e);
        if (DAT_0001216a == '\x04') {
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
          if (PTR_DAT_00025d54[0x409] == '\0') {
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
      if (DAT_0001216a == '\x04') {
        DAT_0001216b = 0;
        return;
      }
      if (DAT_0001fa40 != *(ushort *)(PTR_DAT_00025d54 + 0x9e)) {
        if (DAT_0001216c == 2) {
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
        if (DAT_0001216c == 1) {
          if (PTR_DAT_00025d54[0x409] == '\0') {
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
      if (PTR_DAT_00025d54[0x9d] != '\x02') {
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
      if ((bVar2) && (PTR_DAT_00025d54[0x409] == '\0')) {
        key_call_long();
      }
      DAT_0001216b = '\x02';
      if ((DAT_0001fa40 == 0x300) && (PTR_DAT_00025d54[0x409] == '\0')) {
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
      if ((DAT_0001216c == 2) && (PTR_DAT_00025d54[0x409] == '\0')) {
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
        (uint)(*(int *)(scope_span_table + (uint)bVar1 * 4) + *(int *)(PTR_DAT_00025d54 + 0x45c))) {
      return;
    }
    local_4 = FUN_fffb3aee(local_4 - *(int *)(scope_span_table + (uint)bVar1 * 4));
  }
  *(uint *)(PTR_DAT_00025d54 + 0x45c) = local_4;
  for (bStack_6 = 0; bStack_6 < 4; bStack_6 = bStack_6 + 1) {
    (&DAT_00009e82)[bStack_6] = (char)(local_4 >> ((3 - bStack_6 & 3) << 3));
  }
  bandmem_set('\x01',local_4);
  return;
}


// ===== key_call_press @ fffbc35f (47 bytes)

/* JSR key_press_table[code] */

void key_call_press(void)

{
  char cVar1;
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
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
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
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
  
  cVar2 = FUN_fffc519d(DAT_0001fa40,0);
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


// ===== key_call_repeat @ fffbc406 (47 bytes)

/* JSR key_repeat_table[code] */

void key_call_repeat(void)

{
  char cVar1;
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_repeat_table)[DAT_0001fa40])();
  return;
}


// ===== key_call_release @ fffbc435 (47 bytes)

/* JSR key_release_table[code] */

void key_call_release(void)

{
  char cVar1;
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_release_table)[DAT_0001fa40])();
  return;
}


// ===== key_touch_scope_tune @ fffbc464 (405 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc507) */
/* WARNING: Removing unreachable block (ram,0xfffbc500) */
/* WARNING: Removing unreachable block (ram,0xfffbc55d) */
/* Touch (source 4) x position (0..0x316) -> VFO frequency in the scope span */

void key_touch_scope_tune(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  bool bStack_15;
  uint uStack_10;
  undefined1 *puStack_8;
  
  iVar3 = FUN_fffc8ca8();
  if (iVar3 == 1) {
    if (PTR_DAT_00025d54[0x1c2] == '\b') {
      FUN_fffc23b6();
      return;
    }
    FUN_fffc8beb();
    return;
  }
  iVar3 = FUN_fffc90ed();
  if (iVar3 != 1) {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc4caa();
    if (PTR_DAT_00025d54[0x418] == '\x01') {
      scan_stop();
    }
    if (DAT_00009dbd == 0) {
      puStack_8 = &DAT_00009d09;
    }
    else {
      puStack_8 = &DAT_00009d63;
    }
    bStack_15 = DAT_00009dbd != 0;
    bVar2 = scope_span_index(bStack_15);
    uVar1 = *(uint *)(scope_span_table + (uint)bVar2 * 4);
    if (DAT_00009c35 == '\0') {
      uStack_10 = ((uint)(byte)puStack_8[0x4a] << 0x18 | (uint)(byte)puStack_8[0x4b] << 0x10 |
                   (uint)(byte)puStack_8[0x4c] << 8 | (uint)(byte)puStack_8[0x4d]) - (uVar1 >> 1);
    }
    else if (DAT_00009c35 == '\x01') {
      uStack_10 = DAT_00020f60;
    }
    else {
      uStack_10 = bandmem_get('\x02');
    }
    if (param_1 < 0x317) {
      pvVar4 = (void *)((uVar1 * param_1) / 0x316 + uStack_10);
      bVar2 = freq_in_range(pvVar4);
      if (bVar2 != 0) {
        puStack_8[0x4a] = (char)((uint)pvVar4 >> 0x18);
        puStack_8[0x4b] = (char)((uint)pvVar4 >> 0x10);
        puStack_8[0x4c] = (char)((uint)pvVar4 >> 8);
        uStack_10._0_1_ = SUB41(pvVar4,0);
        puStack_8[0x4d] = (undefined1)uStack_10;
        vfo_store_back(DAT_00009dbd);
        bVar2 = vfo_is_memory(DAT_00009dbd);
        if (bVar2 == 1) {
          if (DAT_00009dbd == 0) {
            DAT_00009dbe = 3;
          }
          else {
            DAT_00009dbf = 3;
          }
        }
        PTR_DAT_00025d54[0x40c] = 1;
        beep_request(1);
        return;
      }
      beep_request(3);
      return;
    }
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffbc605 @ fffbc605 (51 bytes)

void FUN_fffbc605(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc65b();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbc638 @ fffbc638 (35 bytes)

bool FUN_fffbc638(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d54[0x95];
  if (cVar1 != '\0') {
    FUN_fffd1712();
  }
  return cVar1 != '\0';
}


// ===== FUN_fffbc65b @ fffbc65b (28 bytes)

void FUN_fffbc65b(void)

{
  FUN_fffc8beb();
  beep_request(1);
  if (DAT_00009c35 == '\x02') {
    return;
  }
  FUN_fffbc677();
  return;
}

