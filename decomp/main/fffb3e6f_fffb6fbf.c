// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb3e6f @ fffb3e6f (156 bytes)

undefined1 FUN_fffb3e6f(byte param_1)

{
  short sVar1;
  byte bStack_5;
  
  sVar1 = dest_code_get();
  if (sVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3ef4;
  }
  if (sVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3ef4;
  }
  if (sVar1 == 0x306f) {
LAB_fffb3edf:
    bStack_5 = 5;
  }
  else {
    if (sVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3ef4;
    }
    if (sVar1 != -0x26b0) {
      if (sVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3ef4;
      }
      if (sVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3ef4;
      }
      if ((sVar1 == 0x7753) || (sVar1 == -0x6309)) {
        bStack_5 = 9;
        goto LAB_fffb3ef4;
      }
      if (sVar1 != -0x5b3b) {
        if (sVar1 != -0x2cd3) {
          if (sVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3ef4;
        }
        goto LAB_fffb3edf;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3ef4:
  return (&DAT_fff81547)[(uint)param_1 + (uint)bStack_5 * 5];
}


// ===== FUN_fffb3f0b @ fffb3f0b (156 bytes)

undefined1 FUN_fffb3f0b(byte param_1)

{
  short sVar1;
  byte bStack_5;
  
  sVar1 = dest_code_get();
  if (sVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3f90;
  }
  if (sVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3f90;
  }
  if (sVar1 == 0x306f) {
LAB_fffb3f7b:
    bStack_5 = 5;
  }
  else {
    if (sVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3f90;
    }
    if (sVar1 != -0x26b0) {
      if (sVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3f90;
      }
      if (sVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3f90;
      }
      if ((sVar1 == 0x7753) || (sVar1 == -0x6309)) {
        bStack_5 = 9;
        goto LAB_fffb3f90;
      }
      if (sVar1 != -0x5b3b) {
        if (sVar1 != -0x2cd3) {
          if (sVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3f90;
        }
        goto LAB_fffb3f7b;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3f90:
  return (&DAT_fff81579)[(uint)param_1 + (uint)bStack_5 * 5];
}


// ===== FUN_fffb3fa7 @ fffb3fa7 (187 bytes)

void FUN_fffb3fa7(void)

{
  dest_code_get();
  return;
}


// ===== FUN_fffb4062 @ fffb4062 (211 bytes)

byte FUN_fffb4062(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  undefined *puVar6;
  byte bStack_f;
  
  uVar5 = vfo_freq(1,2);
  cVar3 = vfo_mode(1);
  cVar4 = FUN_fffb3371(uVar5);
  bVar2 = DAT_00009bfb;
  if ((cVar3 == '\x04') || (cVar3 == '\x05')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_f = DAT_00009bfb;
    puVar6 = (undefined *)dest_code_get();
    if (puVar6 == &DAT_000060e6) {
      if ((cVar4 == '\t') || (bVar2 < 0xb)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bStack_f = 10;
      }
    }
  }
  else if (cVar4 == '\t') {
    bStack_f = DAT_00009bf9;
  }
  else if (cVar4 == '\n') {
    bStack_f = DAT_00009bfa;
  }
  else {
    bStack_f = DAT_00009bf8;
  }
  if (DAT_00020f0c == '\x01') {
    bStack_f = 10;
  }
  else if (DAT_00020f0c == '\x02') {
    bStack_f = 5;
  }
  else if (DAT_00020b40 == '\x02') {
    bStack_f = 5;
  }
  else if (DAT_00020b41 == '\x02') {
    bStack_f = 5;
  }
  return bStack_f;
}


// ===== FUN_fffb4135 @ fffb4135 (85 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4172) */

void FUN_fffb4135(void)

{
  byte local_15;
  
  for (local_15 = 0; local_15 < 8; local_15 = local_15 + 1) {
  }
  return;
}


// ===== FUN_fffb418a @ fffb418a (143 bytes)

undefined1 FUN_fffb418a(undefined1 param_1)

{
  uint uVar1;
  undefined1 local_9;
  undefined1 local_1;
  
  local_1 = param_1;
  if (DAT_00009c5e != '\0') {
    local_1 = 1;
  }
  uVar1 = vfo_mode(local_1);
  if (uVar1 == 0xe) {
LAB_fffb41fc:
    local_9 = DAT_00009bff;
  }
  else {
    if (uVar1 - 2 < 2) {
      return DAT_00009bfd;
    }
    if (uVar1 - 4 < 2) {
      return DAT_00009c00;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb41fc;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return DAT_00009bfe;
        }
        if (1 < uVar1) {
          return 0;
        }
        return DAT_00009bfc;
      }
    }
    local_9 = uRam00009c01;
  }
  return local_9;
}


// ===== audio_route_state @ fffb4219 (734 bytes)

/* WARNING: Type propagation algorithm not settling */
/* Returns 0..14: CW/RTTY RX 0, record 1/3, spot 2, playback 4/5, CW/RTTY TX 6/7, voice RX 8 (9-12
   variants), voice TX 13, playback TX 14 */

void audio_route_state(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined4 *puVar7;
  
  cVar2 = DAT_00020b3d;
  vfo_mode(DAT_00020b6b);
  FUN_fffb2dfe();
  cVar6 = DAT_00020cd1;
  cVar5 = DAT_00020cd0;
  cVar4 = DAT_00020ccd;
  cVar3 = DAT_00020b7c;
  FUN_fffba192();
  if (DAT_00020b96 == '\x01') {
    puVar7 = (undefined4 *)0x1;
  }
  else {
    puVar7 = (undefined4 *)(uint)DAT_00020b97;
    if (puVar7 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffb42a2;
    }
  }
  bVar1 = true;
LAB_fffb42a2:
  if (bVar1) {
    puVar7 = (undefined4 *)vfo_mode(0);
  }
  else {
    if ((cVar3 == '\0') && (cVar5 != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (cVar6 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (cVar4 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (puVar7 = (undefined4 *)(uint)DAT_00020f1b, puVar7 == (undefined4 *)0x1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      puVar7 = (undefined4 *)vfo_mode(1);
    }
  }
  if (cVar2 != '\x01') {
    *puVar7 = 1;
  }
  return;
}


// ===== key_event_filter @ fffb44f7 (1585 bytes)

/* Front-panel key event gate (key code, action): returns 1 if the key may run now; used by many CAT
   handlers */

undefined1 key_event_filter(ushort param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined1 local_7;
  byte bStack_6;
  ushort local_2;
  
  cVar5 = (char)(param_2 >> 4);
  local_7 = 1;
  iVar4 = FUN_fffc4cc5(param_1,param_2 & 0xff);
  if ((iVar4 == 1) && (2 < param_1 - 0xff0)) {
    local_7 = 0;
  }
  bVar3 = (byte)param_2 & 0xf;
  bStack_6 = 0xff;
  if (param_1 == 0x348) {
    bStack_6 = DAT_00009acc;
  }
  else if (param_1 == 0x34e) {
    bStack_6 = DAT_00009acd;
  }
  else if (param_1 == 0x35e) {
    bStack_6 = DAT_00009acb;
  }
  else if (param_1 == 0x35c) {
    bStack_6 = DAT_00009ac9;
  }
  else if (param_1 == 0x35d) {
    bStack_6 = DAT_00009aca;
  }
  else if (param_1 == 0x35b) {
    bStack_6 = DAT_00009ac8;
  }
  local_2 = param_1;
  if (bStack_6 != 0xff) {
    if ((*(short *)(&key_assign_map + (uint)bStack_6 * 2) == 0x300) && (bVar3 == 2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      local_2 = *(ushort *)(&key_assign_map + (uint)bStack_6 * 2);
    }
  }
  if ((local_2 == 0x300) && (bVar3 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_00020b30 = 2;
    local_7 = 0;
  }
  if (DAT_00020bbe == '\x01') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 < 8) || (local_2 - 0x16 < 4)) {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (DAT_00020b8a == '\x01') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((1 < uVar1 - 0xfe) && (uVar1 != 0xff1)) && (uVar1 != 0x302)) &&
         ((uVar1 != 0x30f && (uVar1 != 0x340)))) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (bVar3 == 1) {
            beep_request(3);
          }
          local_7 = 0;
        }
      }
    }
    return local_7;
  }
  if (DAT_00020b98 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      if ((local_2 < 0x200) || (0x288 < local_2)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((((!bVar2) && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) && (uVar1 != 0xe6)) &&
         (((0xe < uVar1 - 0x300 && (1 < uVar1 - 0x310)) && ((uVar1 != 0x340 && (1 < uVar1 - 0xff0)))
          ))) {
        if (bVar3 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if ((DAT_00020b7c == '\x02') && ((local_2 - 0x87 < 5 || (local_2 - 0x8d < 4)))) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((((DAT_00020b97 != '\0') && (uVar1 = (uint)local_2, uVar1 != 0xe8)) && (1 < uVar1 - 0xfe)) &&
     (((0xb < uVar1 - 0x110 && (uVar1 != 0xff1)) && ((uVar1 != 0x30c && (uVar1 != 0x30f)))))) {
    if (uVar1 == 0x300) {
      local_7 = 0;
    }
    else {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (((DAT_00020baf == '\x01') && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) &&
     ((4 < uVar1 - 0x110 &&
      ((((uVar1 != 0x119 && (uVar1 != 0x302)) && (uVar1 != 0x340)) && (uVar1 != 0xff1)))))) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if (DAT_00020b3d != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if (((uVar1 != 0x10) && (5 < uVar1 - 0x30)) &&
         (((((9 < uVar1 - 0x87 && ((5 < uVar1 - 0xd0 && (0xd < uVar1 - 0xd7)))) &&
            (1 < uVar1 - 0xe6)) &&
           (((((uVar1 != 0xe9 && (6 < uVar1 - 0xec)) && (uVar1 != 0x12d)) &&
             (((2 < uVar1 - 0x300 && (uVar1 != 0x306)) &&
              ((uVar1 != 0x30f && ((uVar1 != 0x311 && (2 < uVar1 - 0xff0)))))))) && (uVar1 != 0x340)
            ))) && (((uVar1 != 0x348 && (uVar1 != 0x34e)) &&
                    ((uVar1 != 0x312 || (DAT_00020bbe == '\0')))))))) {
        if (bVar3 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020f11 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((uVar1 != 0x14) && (0xe < uVar1 - 0xb0)) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (uVar1 != 0x302) {
            if (uVar1 == 0x30c) goto LAB_fffb48f7;
            if (uVar1 != 0x340) {
              if (bVar3 == 1) {
                beep_request(3);
              }
              local_7 = 0;
              goto LAB_fffb48f7;
            }
          }
          FUN_fffc23b6();
        }
      }
    }
  }
LAB_fffb48f7:
  if (DAT_00020f0c != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((2 < uVar1 - 0x300) && (uVar1 != 0x340)) && (uVar1 != 0x348)) &&
         ((uVar1 != 0x34e && (uVar1 != 0xff0)))) {
        if (bVar3 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020b74 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 == 0x14) {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 == 0x302) || (local_2 == 0x340)) {
      DAT_00020b74 = '\0';
    }
  }
  iVar4 = vfo_tune_locked(2);
  if (iVar4 == 1) {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 - 0x12 < 3) {
      if (bVar3 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if ((DAT_00020b9b == '\x01') && (local_2 == 0xff1)) {
    local_7 = 0;
  }
  if ((DAT_00020f1b == '\x01') && (local_2 == 0x30e)) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00020ccd == '\x01') && (local_2 == 0x30e)) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c5e != '\0') && (local_2 == 0x306)) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c62 == '\0') || (DAT_00020b97 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) && (local_2 == 0xff0)) {
    FUN_fffc8cbb(0x47);
    FUN_fffc8d8c();
    DAT_00020cc6 = 0x47;
    local_7 = 0;
  }
  if (((DAT_00020f0b != '\0') && (local_2 != 0x340)) && (2 < local_2 - 0xff0)) {
    DAT_00020f0b = '\0';
    beep_stop();
  }
  if (((param_2 & 0xf) == 0) && (2 < local_2 - 0xff0)) {
    local_7 = 1;
  }
  if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && ((local_2 == 0x302 || (local_2 == 0x340)))) {
    if (bVar3 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  return local_7;
}


// ===== supply_undervolt_check @ fffb4b28 (146 bytes)

/* AN003 < 0x7DD -> power_off_io, save, shutdown request 0x20B39=0x90 */

char supply_undervolt_check(void)

{
  int iVar1;
  
  if ((DAT_00020b43 != '\x01') && (DAT_00020b08 < 0x7dd)) {
    iVar1 = swtimer_expired(0x13);
    DAT_00020b43 = '\x01';
    if (iVar1 == 1) {
      power_off_io();
      DAT_00009dc5 = 1;
      FUN_fffd3d03();
      eeprom_save_opstate();
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x90;
    }
    else {
      power_off_io();
      DAT_00009dc5 = 1;
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x90;
    }
  }
  return DAT_00020b43;
}


// ===== vfo_tune_locked @ fffb4bba (139 bytes)

/* 1 if side is in state 7/8 or on 5 MHz/EMG memory (ch 117..132) */

undefined1 vfo_tune_locked(char param_1)

{
  bool bVar1;
  undefined1 local_5;
  byte local_4;
  char local_3;
  char local_1;
  
  local_5 = 0;
  local_1 = param_1;
  if (param_1 == '\x02') {
    if (DAT_00009dbd == '\0') {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
  }
  if (local_1 == '\0') {
    local_3 = DAT_00009dbe;
    local_4 = DAT_000060c9;
  }
  else {
    local_3 = DAT_00009dbf;
    local_4 = DAT_000060ca;
  }
  if (local_3 == '\x02') {
    if ((local_4 < 0x75) || (0x84 < local_4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_5 = 1;
    }
  }
  else if (local_3 == '\a' || local_3 == '\b') {
    local_5 = 1;
  }
  return local_5;
}


// ===== vfo_display_offset @ fffb4c45 (467 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4d66) */
/* WARNING: Removing unreachable block (ram,0xfffb4c6a) */
/* WARNING: Removing unreachable block (ram,0xfffb4dfd) */
/* WARNING: Removing unreachable block (ram,0xfffb4cbe) */
/* WARNING: Removing unreachable block (ram,0xfffb4d3b) */
/* WARNING: Removing unreachable block (ram,0xfffb4d06) */
/* Mode-dependent signed offset added to dial freq (0x20F5C); 0 if setting 0x9B15 != 0 */

ushort vfo_display_offset(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  ushort uStack_e;
  ushort uStack_a;
  
  iVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_e = 0;
  if (DAT_00009b15 == '\0') {
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
      uStack_e = CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
    }
    else if (uVar1 - 2 < 2) {
      uStack_a = CONCAT11(*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
      if (bVar2 == 2) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 8 < 2) {
      uStack_a = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
                 CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
      if (bVar2 == 8) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 0xc < 2) {
      uStack_a = (ushort)*(byte *)(iVar4 + 0x27);
      sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x26),*(byte *)(iVar4 + 0x27));
      if (DAT_00009a8d == '\x01') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x69;
        }
        else {
          uStack_a = 0x69 - uStack_a;
        }
      }
      else if (DAT_00009a8d == '\x02') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0xd7;
        }
        else {
          uStack_a = 0xd7 - uStack_a;
        }
      }
      else if (DAT_00009a8d == '\x03') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x1a9;
        }
        else {
          uStack_a = 0x1a9 - uStack_a;
        }
      }
      else if (bVar2 == 0xc) {
        uStack_a = sVar3 + 0x55;
      }
      else {
        uStack_a = 0x55 - uStack_a;
      }
      uStack_e = ~uStack_a + 1;
    }
    else if (uVar1 < 2) {
      uStack_a = CONCAT11(*(byte *)(iVar4 + 0x12),*(undefined1 *)(iVar4 + 0x13));
      if ((*(byte *)(iVar4 + 0x12) & 0x80) != 0) {
        uStack_a = -(~uStack_a + 1);
      }
      uStack_a = uStack_a + 0x5dc;
      if (bVar2 == 0) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
  }
  return uStack_e;
}


// ===== bandmem_set @ fffb4e18 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4e89) */
/* WARNING: Removing unreachable block (ram,0xfffb4e33) */
/* WARNING: Removing unreachable block (ram,0xfffb4e52) */
/* (kind, f): kind 1 -> 0x9C69[band] (scope CURSOR start), 2 -> 0x9C99[band] / 0x9CC9[GEN sub] (FIX
   start) */

void bandmem_set(char param_1,uint param_2)

{
  byte bVar1;
  undefined1 *puStack_10;
  byte bStack_b;
  
  vfo_freq_clar(0,2);
  bVar1 = band_of_freq();
  if (param_1 == '\x02') {
    puStack_10 = &DAT_00009c99 + (uint)bVar1 * 4;
    if (bVar1 == 0xb) {
      bVar1 = gen_subband_of_freq(param_2);
      for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
        *(char *)((uint)bStack_b + (uint)bVar1 * 4 + 0x9cc9) =
             (char)(param_2 >> ((3 - bStack_b & 3) << 3));
      }
    }
  }
  else {
    puStack_10 = &DAT_00009c69 + (uint)bVar1 * 4;
  }
  for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
    puStack_10[bStack_b] = (char)(param_2 >> ((3 - bStack_b & 3) << 3));
  }
  return;
}


// ===== bandmem_get @ fffb4ebe (148 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4edb) */
/* WARNING: Removing unreachable block (ram,0xfffb4f17) */
/* WARNING: Removing unreachable block (ram,0xfffb4f03) */
/* (kind): read band memory of the band containing the active frequency */

void bandmem_get(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  byte bStack_e;
  
  uVar2 = vfo_freq(0,2);
  cVar1 = band_of_freq(uVar2);
  if ((param_1 == '\x02') && (cVar1 == '\v')) {
    gen_subband_of_freq(uVar2);
  }
  for (bStack_e = 0; bStack_e < 4; bStack_e = bStack_e + 1) {
  }
  return;
}


// ===== tx_freq_repeater_shift @ fffb4f52 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5062) */
/* FM/DATA-FM repeater shift (rec+2 bits2-3) on 28/50 MHz, x10 kHz settings */

void tx_freq_repeater_shift(void)

{
  vfo_rec_ptr(1);
  vfo_mode(1);
  return;
}


// ===== FUN_fffb50d7 @ fffb50d7 (323 bytes)

undefined1 FUN_fffb50d7(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb51ed:
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a77;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a9d;
    }
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a4f;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb51ed;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b68;
          }
          return DAT_00009a8a;
        }
        if (1 < uVar1) {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b68;
        }
        return DAT_00009a3a;
      }
    }
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a61;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  return local_3;
}


// ===== FUN_fffb521a @ fffb521a (98 bytes)

bool FUN_fffb521a(void)

{
  int iVar1;
  uint uVar2;
  byte bStack_9;
  
  iVar1 = vfo_rec_ptr(1);
  uVar2 = vfo_mode(1);
  if (1 < uVar2 - 10) {
    if (uVar2 - 2 < 2) {
      bStack_9 = *(byte *)(iVar1 + 0x14);
      goto LAB_fffb526d;
    }
    if (uVar2 - 4 < 2) {
      bStack_9 = *(byte *)(iVar1 + 0x32);
      goto LAB_fffb526d;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 < 2) {
        bStack_9 = *(byte *)(iVar1 + 10);
      }
      else {
        bStack_9 = 0;
      }
      goto LAB_fffb526d;
    }
  }
  bStack_9 = *(byte *)(iVar1 + 0x3c);
LAB_fffb526d:
  return (bStack_9 & 2) != 0;
}


// ===== tx_mod_gain @ fffb527c (526 bytes)

/* Current modulation gain: MIC GAIN or per-mode USB/REAR MOD GAIN by MOD SOURCE */

undefined1 tx_mod_gain(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uStack_b;
  
  bVar2 = vfo_mode(DAT_00020b6b);
  cVar3 = FUN_fffb3d11(bVar2);
  uStack_b = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffb5345:
    if (cVar3 == '\0') {
      uStack_b = DAT_00009bed;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a75;
      }
      else {
        uStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a76;
      }
      else {
        uStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (cVar3 == '\0') {
        return DAT_00009bee;
      }
      if (cVar3 == '\x01') {
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b66;
        }
        return DAT_00009a4d;
      }
      if (cVar3 != '\x02') {
        return 0;
      }
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b67;
      }
      return DAT_00009a4e;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb5345;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          return 0;
        }
        if (cVar3 == '\0') {
          return DAT_00009bec;
        }
        if (cVar3 == '\x01') {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b66;
          }
          return DAT_00009a38;
        }
        if (cVar3 != '\x02') {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b67;
        }
        return DAT_00009a39;
      }
    }
    if (cVar3 == '\0') {
      uStack_b = DAT_00009bef;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a5f;
      }
      else {
        uStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a60;
      }
      else {
        uStack_b = DAT_00020b67;
      }
    }
  }
  return uStack_b;
}


// ===== FUN_fffb548a @ fffb548a (22 bytes)

char FUN_fffb548a(void)

{
  return DAT_00009aa3 * '\x05' + '\x0f';
}


// ===== FUN_fffb54a0 @ fffb54a0 (140 bytes)

void FUN_fffb54a0(void)

{
  vfo_mode(0);
  return;
}


// ===== FUN_fffb552c @ fffb552c (140 bytes)

void FUN_fffb552c(void)

{
  vfo_mode(0);
  return;
}


// ===== portctl_init @ fffb55b8 (10 bytes)

/* 0x12042=0 */

void portctl_init(void)

{
  DAT_00012042 = 0;
  return;
}


// ===== rf_ctrl_task @ fffb55c2 (41 bytes)

/* main loop: updates all shift registers and DACs when values change */

void rf_ctrl_task(void)

{
  pa_relay_update();
  rf_bpf_update();
  atu_relay_update();
  main_dac_update();
  pa_dac_update();
  FUN_fffb5d68();
  if (DAT_00012042 != '\0') {
    return;
  }
  DAT_00012042 = 1;
  return;
}


// ===== pa_relay_update @ fffb55eb (186 bytes)

/* /SST4: TX band one-hot + tuner/AM/RX/band-10 bits [inference] */

void pa_relay_update(void)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uStack_8;
  
  cVar3 = vfo_mode(1);
  uVar2 = DAT_00020f50;
  bVar4 = FUN_fffb3337(DAT_00020f50);
  uStack_8 = 1 << (bVar4 & 0x1f);
  if (DAT_00020b3f == '\x02') {
    iVar5 = FUN_fffec50f();
    if ((iVar5 == 0) && (iVar5 = FUN_fffec500(), iVar5 == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = uStack_8 | 0x80;
    }
  }
  if (cVar3 == '\x04') {
    uStack_8 = uStack_8 | 0x100;
  }
  iVar5 = rx_line_get();
  if (iVar5 == 1) {
    uStack_8 = uStack_8 | 0x200;
  }
  cVar3 = FUN_fffb3371(uVar2);
  if (cVar3 == '\n') {
    uStack_8 = uStack_8 | 0x400;
  }
  if ((DAT_00020f98 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  shreg_write24(3,uStack_8);
  DAT_00020f98 = uStack_8;
  return;
}


// ===== rf_bpf_update @ fffb56a5 (225 bytes)

/* /SST3: RX/TX band one-hot + preamp/ATT bits [inference] */

void rf_bpf_update(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar5 = vfo_rec_ptr(DAT_00020b6b);
  bVar2 = *(byte *)(iVar5 + 3) & 3;
  bVar3 = *(byte *)(iVar5 + 5) & 3;
  if (DAT_00020b6b == '\x01') {
    uStack_8 = DAT_00020f50;
  }
  else {
    uStack_8 = vfo_freq(0,2);
    iVar5 = tx_line_get();
    if (iVar5 != 0) {
      return;
    }
  }
  bVar4 = FUN_fffb32fd(uStack_8);
  uStack_c = 1 << (bVar4 & 0x1f);
  if (bVar2 == 1) {
    uStack_c = uStack_c | 0x8000;
  }
  else if (bVar2 == 2) {
    uStack_c = uStack_c | 0x10000;
  }
  else if (bVar2 != 3) {
    uStack_c = uStack_c | 0x18000;
  }
  if (bVar3 == 3) {
    uStack_c = uStack_c | 0x40000;
  }
  else if (bVar3 == 0) {
    uStack_c = uStack_c | 0x20000;
  }
  uStack_c = uStack_c | 0x200000;
  if ((DAT_00020f9c == uStack_c) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  shreg_write24(2,uStack_c);
  DAT_00020f9c = uStack_c;
  return;
}


// ===== atu_relay_update @ fffb5786 (238 bytes)

/* /SST6: internal tuner relay bytes, SEND dropped 15 ms while switching [inference] */

void atu_relay_update(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uStack_8;
  
  cVar2 = send_a_get();
  uStack_8 = 0;
  if (DAT_00020b3f == '\x02') {
    iVar4 = FUN_fffec50f();
    uVar3 = FUN_fffec500();
    uStack_8 = FUN_fffec51e();
    uStack_8 = uStack_8 | (uVar3 | iVar4 << 8) << 8;
  }
  if ((DAT_00020fa0 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (cVar2 != '\0') {
      send_a_set(0);
      send_b_set(0);
      DAT_0001b4c5 = '\x01';
      swtimer_start(0x30,0xf);
    }
    shreg_write24(5,uStack_8);
    DAT_00020fa0 = uStack_8;
  }
  if ((DAT_0001b4c5 == '\x01') && (iVar4 = swtimer_expired(0x30), iVar4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00020b18 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return;
  }
  DAT_0001b4c5 = 0;
  send_a_set(1);
  send_b_set(1);
  return;
}


// ===== main_dac_update @ fffb5874 (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb58a4) */
/* WARNING: Removing unreachable block (ram,0xfffb5934) */
/* Q1005 ch3 (FADJ) and ch5 */

void main_dac_update(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  ushort local_a;
  
  sVar3 = ((ushort)DAT_0000465b - (ushort)DAT_00009ac6 & 0xff) << 2;
  if ((DAT_00020fa4 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,3,sVar3);
    DAT_00020fa4 = sVar3;
  }
  uVar4 = vfo_freq(0,2);
  bVar2 = FUN_fffb33ab(uVar4);
  if (bVar2 < 5) {
    local_a = (ushort)bRam0000466f;
  }
  else if (bVar2 < 7) {
    local_a = (ushort)bRam00004670;
  }
  else if (bVar2 < 9) {
    local_a = (ushort)bRam00004671;
  }
  else if (bVar2 < 0xb) {
    local_a = (ushort)bRam00004672;
  }
  else {
    local_a = (ushort)bRam00004673;
  }
  sVar3 = local_a << 2;
  if ((DAT_00020fa6 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,5,sVar3);
    DAT_00020fa6 = sVar3;
    return;
  }
  return;
}


// ===== pa_dac_update @ fffb5976 (1010 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5b07) */
/* WARNING: Removing unreachable block (ram,0xfffb5a6c) */
/* WARNING: Removing unreachable block (ram,0xfffb5bbc) */
/* WARNING: Removing unreachable block (ram,0xfffb5caf) */
/* WARNING: Removing unreachable block (ram,0xfffb5d26) */
/* WARNING: Removing unreachable block (ram,0xfffb5aaf) */
/* WARNING: Removing unreachable block (ram,0xfffb5bff) */
/* WARNING: Removing unreachable block (ram,0xfffb5c42) */
/* PA BU2505 ch1..7,10: per-band cal, drive level, fan (ch6 from PA_HF_TH) [inference] */

void pa_dac_update(void)

{
  bool bVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  short sVar6;
  float fVar7;
  ushort uStack_14;
  ushort uStack_12;
  ushort uStack_10;
  ushort uStack_e;
  ushort uStack_c;
  ushort uStack_a;
  
  uVar2 = DAT_00020f50;
  bVar3 = (byte)(DAT_00020b12 >> 4);
  uVar4 = FUN_fffb3371(DAT_00020f50);
  switch(uVar4) {
  case 0:
    uStack_c = (ushort)bRam00004743;
    uStack_e = (ushort)bRam00004693;
    break;
  case 1:
    uStack_c = (ushort)bRam00004744;
    uStack_e = (ushort)bRam00004694;
    break;
  case 2:
    uStack_c = (ushort)bRam00004745;
    uStack_e = (ushort)bRam00004695;
    break;
  case 3:
    uStack_c = (ushort)bRam00004746;
    uStack_e = (ushort)bRam00004696;
    break;
  case 4:
    uStack_c = (ushort)bRam00004747;
    uStack_e = (ushort)bRam00004697;
    break;
  case 5:
    uStack_c = (ushort)bRam00004748;
    uStack_e = (ushort)bRam00004698;
    break;
  case 6:
    uStack_c = (ushort)bRam00004749;
    uStack_e = (ushort)bRam00004699;
    break;
  case 7:
    uStack_c = (ushort)bRam0000474a;
    uStack_e = (ushort)bRam0000469a;
    break;
  case 8:
    uStack_c = (ushort)bRam0000474b;
    uStack_e = (ushort)bRam0000469b;
    break;
  case 9:
    uStack_c = (ushort)bRam0000474c;
    uStack_e = (ushort)bRam0000469c;
    break;
  default:
    uStack_c = (ushort)bRam0000474d;
    uStack_e = (ushort)bRam0000469d;
  }
  sVar6 = uStack_c << 2;
  if ((DAT_00020fa8 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,1,sVar6);
    DAT_00020fa8 = sVar6;
  }
  sVar6 = uStack_e << 2;
  if ((DAT_00020fb6 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,10,sVar6);
    DAT_00020fb6 = sVar6;
  }
  bVar5 = FUN_fffb4062();
  sVar6 = FUN_fffb667a(uVar4,bVar5);
  fVar7 = ROUND((float)(((int)sVar6 & 0x3fffU) << 2) * *(float *)(&DAT_fff88a68 + (uint)bVar5 * 4) +
                0.5);
  sVar6 = SUB42(fVar7,0);
  if ((DAT_00020faa == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,2,(uint)fVar7 & 0xffff);
    DAT_00020faa = sVar6;
  }
  bVar5 = FUN_fffb3337(uVar2);
  if (bVar5 == 0) {
    uStack_10 = (ushort)bRam0000468c;
    uStack_12 = (ushort)bRam0000468b;
    uStack_14 = (ushort)bRam0000468a;
  }
  else if (bVar5 < 6) {
    uStack_10 = (ushort)bRam0000468f;
    uStack_12 = (ushort)bRam0000468e;
    uStack_14 = (ushort)bRam0000468d;
  }
  else {
    uStack_10 = (ushort)bRam00004692;
    uStack_12 = (ushort)bRam00004691;
    uStack_14 = (ushort)bRam00004690;
  }
  sVar6 = uStack_10 << 2;
  if ((DAT_00020fac == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,3,sVar6);
    DAT_00020fac = sVar6;
  }
  sVar6 = uStack_12 << 2;
  if ((DAT_00020fae == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,4,sVar6);
    DAT_00020fae = sVar6;
  }
  sVar6 = uStack_14 << 2;
  if ((DAT_00020fb0 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,5,sVar6);
    DAT_00020fb0 = sVar6;
  }
  if (bVar3 < DAT_0000465a) {
    uStack_a = 0xad;
  }
  else if (DAT_0000465a + 10 < (uint)bVar3) {
    uStack_a = 0;
  }
  else {
    uStack_a = DAT_00020fb2 >> 2;
  }
  uStack_a = uStack_a << 2;
  if ((DAT_00020fb2 == uStack_a) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,6,uStack_a);
    DAT_00020fb2 = uStack_a;
  }
  if (DAT_00020b3c == '\x03') {
    uStack_a = 0xff;
  }
  else if (DAT_00020b3c == '\x02') {
    uStack_a = 0x51;
  }
  else if (DAT_00020b3c == '\x01') {
    uStack_a = 0x60;
  }
  else {
    uStack_a = 0;
  }
  if (DAT_00009ab8 != '\x03') {
    uStack_a = 0;
  }
  sVar6 = uStack_a << 2;
  if ((DAT_00020fb4 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  bu2505_write(4,7,sVar6);
  DAT_00020fb4 = sVar6;
  return;
}


// ===== FUN_fffb5d68 @ fffb5d68 (2322 bytes)

void FUN_fffb5d68(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  char cStack_f;
  char cStack_e;
  char cStack_d;
  char cStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  char cStack_8;
  char cStack_7;
  
  iVar8 = audio_route_state();
  bVar4 = vfo_mode(0);
  bVar5 = FUN_fffb2dfe();
  FUN_fffb3d11(bVar4);
  cVar7 = DAT_00020b6b;
  bVar2 = false;
  cStack_e = '\0';
  cStack_d = '\0';
  cStack_b = '\0';
  uStack_a = 0;
  uStack_9 = 0;
  cStack_8 = '\0';
  cStack_f = DAT_00020b31;
  cVar6 = FUN_fffb3d11(bVar4);
  uVar1 = (uint)bVar4;
  if (uVar1 == 0xe) {
LAB_fffb6009:
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a71;
      uStack_a = DAT_00009a72;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bed;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a75;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a76;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
  else if (uVar1 - 2 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a9b;
      uStack_a = DAT_00009a9c;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
  }
  else if (uVar1 - 4 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a49;
      uStack_a = DAT_00009a4a;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bee;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a4d;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a4e;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb6009;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a88;
            uStack_a = DAT_00009a89;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
        }
        else if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a34;
            uStack_a = DAT_00009a35;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
          if (cVar6 == '\0') {
            cStack_b = DAT_00009bec;
          }
          else if (cVar6 == '\x01') {
            if (DAT_00009dc6 == '\0') {
              cStack_b = DAT_00009a38;
            }
            else {
              cStack_b = DAT_00020b66;
            }
          }
          else if (cVar6 == '\x02') {
            if (DAT_00009dc6 == '\0') {
              cStack_b = DAT_00009a39;
            }
            else {
              cStack_b = DAT_00020b67;
            }
          }
        }
        goto LAB_fffb612b;
      }
    }
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a5c;
      uStack_a = DAT_00009a5d;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bef;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a5f;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a60;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
LAB_fffb612b:
  cVar6 = FUN_fffb418a(cVar7);
  cVar7 = DAT_00020ba8;
  switch(iVar8) {
  case 0:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    bVar2 = true;
    break;
  case 1:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    bVar2 = true;
    break;
  case 2:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 3:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 4:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 5:
    cStack_8 = DAT_00009dc1;
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 6:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x1a);
    cStack_e = cVar6;
    break;
  case 7:
    cStack_8 = FUN_fffb34f9(cVar6);
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x1a);
    break;
  case 8:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    tx_mod_gain();
    cStack_b = FUN_fffb34cf();
    bVar2 = true;
    break;
  case 9:
    iVar9 = ear_det();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    bVar2 = true;
    break;
  case 10:
    cStack_8 = FUN_fffb34f9(cVar6);
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xb:
  case 0xc:
    cStack_8 = DAT_00009dc1;
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xd:
    cStack_8 = FUN_fffb34f9(cVar6);
    tx_mod_gain();
    cStack_b = FUN_fffb34cf();
    break;
  case 0xe:
    cStack_8 = DAT_00009dc1;
    cStack_b = FUN_fffb350e(DAT_00009dc2);
  }
  if ((bVar5 - 1 < 3) || (bVar5 - 5 < 4)) {
    cStack_d = '\0';
    cStack_e = DAT_00009ab5;
    if (DAT_00009ab5 != '\0') goto LAB_fffb6432;
  }
  if (DAT_00020ba8 == '\0') {
    if ((iVar8 == 4) || (iVar8 == 7)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      iVar8 = FUN_fffb418a(DAT_00020b6b);
      if (iVar8 == 0) {
        FUN_fffb71f5();
      }
    }
    else if (bVar2) {
      FUN_fffb71f5();
    }
  }
LAB_fffb6432:
  if ((DAT_00020b18 < 3) && (iVar8 = swtimer_expired(0xe), iVar8 != 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((!bVar2) && (DAT_00020b3d != '\x02')) {
    if ((DAT_00020fbd == cStack_8) && (DAT_00012042 != '\0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      sst2_write12(1,cStack_8);
      DAT_00020fbd = cStack_8;
    }
    if ((DAT_00020fbc == cStack_8) && (DAT_00012042 != '\0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      sst2_write12(5,cStack_8);
      DAT_00020fbc = cStack_8;
    }
  }
  cStack_7 = FUN_fffb34f9(uStack_9);
  if (DAT_00020b6b != '\0') {
    cStack_7 = '\0';
  }
  if ((DAT_00020fb8 == cStack_7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(2,cStack_7);
    DAT_00020fb8 = cStack_7;
  }
  cVar7 = FUN_fffb34f9(uStack_a);
  if ((DAT_00020fb9 == cVar7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(3,cVar7);
    DAT_00020fb9 = cVar7;
  }
  if ((DAT_00020fba == cStack_b) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(4,cStack_b);
    DAT_00020fba = cStack_b;
  }
  if ((DAT_00020fbe == cStack_d) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(6,cStack_d);
    DAT_00020fbe = cStack_d;
  }
  cVar7 = FUN_fffb34f9(cStack_e);
  if ((DAT_00020fbf == cVar7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(7,cVar7);
    DAT_00020fbf = cVar7;
  }
  if ((DAT_00020fbb == cStack_f) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    sst2_write12(8,cStack_f);
    DAT_00020fbb = cStack_f;
    return;
  }
  return;
}


// ===== FUN_fffb667a @ fffb667a (1636 bytes)

char FUN_fffb667a(undefined1 param_1,byte param_2)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_e;
  char local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  switch(param_1) {
  case 0:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_0000469e;
      local_c = DAT_0000469e;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046a7;
          local_c = DAT_000046aa;
        }
        else {
          local_a = 10;
          local_b = DAT_000046a4;
          local_c = DAT_000046a7;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046a1;
        local_c = DAT_000046a4;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_0000469e;
      local_c = DAT_000046a1;
    }
    local_e = DAT_0000469f;
    break;
  case 1:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046ad;
      local_c = DAT_000046ad;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046b6;
          local_c = DAT_000046b9;
        }
        else {
          local_a = 10;
          local_b = DAT_000046b3;
          local_c = DAT_000046b6;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046b0;
        local_c = DAT_000046b3;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046ad;
      local_c = DAT_000046b0;
    }
    local_e = DAT_000046ae;
    break;
  case 2:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046bc;
      local_c = DAT_000046bc;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046c5;
          local_c = DAT_000046c8;
        }
        else {
          local_a = 10;
          local_b = DAT_000046c2;
          local_c = DAT_000046c5;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046bf;
        local_c = DAT_000046c2;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046bc;
      local_c = DAT_000046bf;
    }
    local_e = DAT_000046bd;
    break;
  case 3:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046cb;
      local_c = DAT_000046cb;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046d4;
          local_c = DAT_000046d7;
        }
        else {
          local_a = 10;
          local_b = DAT_000046d1;
          local_c = DAT_000046d4;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046ce;
        local_c = DAT_000046d1;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046cb;
      local_c = DAT_000046ce;
    }
    local_e = DAT_000046cc;
    break;
  case 4:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046da;
      local_c = DAT_000046da;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046e3;
          local_c = DAT_000046e6;
        }
        else {
          local_a = 10;
          local_b = DAT_000046e0;
          local_c = DAT_000046e3;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046dd;
        local_c = DAT_000046e0;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046da;
      local_c = DAT_000046dd;
    }
    local_e = DAT_000046db;
    break;
  case 5:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046e9;
      local_c = DAT_000046e9;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046f2;
          local_c = DAT_000046f5;
        }
        else {
          local_a = 10;
          local_b = DAT_000046ef;
          local_c = DAT_000046f2;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046ec;
        local_c = DAT_000046ef;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046e9;
      local_c = DAT_000046ec;
    }
    local_e = DAT_000046ea;
    break;
  case 6:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046f8;
      local_c = DAT_000046f8;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_00004701;
          local_c = DAT_00004704;
        }
        else {
          local_a = 10;
          local_b = DAT_000046fe;
          local_c = DAT_00004701;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046fb;
        local_c = DAT_000046fe;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046f8;
      local_c = DAT_000046fb;
    }
    local_e = DAT_000046f9;
    break;
  case 7:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004707;
      local_c = DAT_00004707;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_00004710;
          local_c = DAT_00004713;
        }
        else {
          local_a = 10;
          local_b = DAT_0000470d;
          local_c = DAT_00004710;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_0000470a;
        local_c = DAT_0000470d;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004707;
      local_c = DAT_0000470a;
    }
    local_e = DAT_00004708;
    break;
  case 8:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004716;
      local_c = DAT_00004716;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000471f;
          local_c = DAT_00004722;
        }
        else {
          local_a = 10;
          local_b = DAT_0000471c;
          local_c = DAT_0000471f;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004719;
        local_c = DAT_0000471c;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004716;
      local_c = DAT_00004719;
    }
    local_e = DAT_00004717;
    break;
  case 9:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004725;
      local_c = DAT_00004725;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000472e;
          local_c = DAT_00004731;
        }
        else {
          local_a = 10;
          local_b = DAT_0000472b;
          local_c = DAT_0000472e;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004728;
        local_c = DAT_0000472b;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004725;
      local_c = DAT_00004728;
    }
    local_e = DAT_00004726;
    break;
  default:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000473d;
          local_c = DAT_00004740;
        }
        else {
          local_a = 10;
          local_b = DAT_0000473a;
          local_c = DAT_0000473d;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004737;
        local_c = DAT_0000473a;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    local_e = DAT_00004738;
  }
  DAT_00020b1e = local_e;
  if (local_b < local_c) {
    in_stack_0000000c = ((uint)local_c - (uint)local_b) * in_stack_0000000c;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || in_stack_0000000c != -1)) {
      in_stack_0000000c = in_stack_0000000c / (int)uVar1;
    }
    local_d = (char)in_stack_0000000c;
  }
  else {
    in_stack_0000000c = ((uint)local_b - (uint)local_c) * in_stack_0000000c;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || in_stack_0000000c != -1)) {
      in_stack_0000000c = in_stack_0000000c / (int)uVar1;
    }
    local_d = (char)in_stack_0000000c;
  }
  local_d = local_d + local_c;
  return local_d;
}


// ===== trx_init @ fffb6cde (120 bytes)

/* trx_state=4, timer 0x13 2.5 s, AF_MUTE on */

void trx_init(void)

{
  byte bVar1;
  byte bStack_1;
  
  DAT_00020b18 = 4;
  DAT_00020b6b = 0;
  DAT_0001204d = 0;
  swtimer_start(0x13,0x9c4);
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 8;
  DAT_00020b44 = 1;
  for (bStack_1 = 0; bStack_1 < 4; bStack_1 = bStack_1 + 1) {
    DAT_00020f60 = DAT_00020f60 << 8 | (uint)(byte)(&DAT_00009e82)[bStack_1];
  }
  return;
}


// ===== io_task @ fffb6d56 (173 bytes)

/* main loop: AF mute, meters, io_poll, power checks */

void io_task(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = swtimer_expired(0x2a);
  if (((iVar1 != 0) && (uVar2 = af_mute_get(), uVar2 != DAT_00020b44)) && (DAT_00020b18 == '\b')) {
    af_mute_set(DAT_00020b44);
  }
  meter_task();
  io_poll();
  FUN_fffb8d77();
  FUN_fffb9605();
  iVar1 = supply_undervolt_check();
  if (iVar1 != 1) {
    if (DAT_00020b30 == '\x02') {
      DAT_00009dc5 = 0;
      FUN_fffd3d03();
      if (DAT_00020bbe == '\0') {
        eeprom_save_opstate();
      }
      do {
        iVar1 = sci1_tx_end();
      } while (iVar1 == 0);
      sw_reset();
    }
    iVar1 = FUN_fffb267f();
    if (iVar1 == 1) {
      if (DAT_00020b86 == '\0') {
        DAT_00020b87 = 1;
        return;
      }
    }
    else if (DAT_00020b86 != '\0') {
      DAT_00020b87 = 1;
      return;
    }
  }
  return;
}


// ===== meter_get_vdd @ fffb6e03 (15 bytes)

undefined1 meter_get_vdd(void)

{
  return DAT_00012043;
}


// ===== meter_get_idd @ fffb6e12 (15 bytes)

undefined1 meter_get_idd(void)

{
  return DAT_00012044;
}


// ===== meter_get_alc @ fffb6e21 (15 bytes)

undefined1 meter_get_alc(void)

{
  return DAT_00012045;
}


// ===== meter_get_swr @ fffb6e30 (15 bytes)

undefined1 meter_get_swr(void)

{
  return DAT_00012046;
}


// ===== meter_get_swr_raw @ fffb6e3f (15 bytes)

undefined1 meter_get_swr_raw(void)

{
  return DAT_00012047;
}


// ===== FUN_fffb6e4e @ fffb6e4e (14 bytes)

void FUN_fffb6e4e(void)

{
  return;
}


// ===== FUN_fffb6e5c @ fffb6e5c (14 bytes)

void FUN_fffb6e5c(void)

{
  return;
}


// ===== meter_get_po @ fffb6e6a (46 bytes)

undefined1 meter_get_po(void)

{
  undefined1 local_3;
  
  if (DAT_00009af6 == '\0') {
    local_3 = DAT_00012048;
  }
  else {
    local_3 = DAT_0001204b;
  }
  return local_3;
}


// ===== meter_get_comp @ fffb6e98 (15 bytes)

undefined1 meter_get_comp(void)

{
  return DAT_00012049;
}


// ===== meter_get_s @ fffb6ea7 (15 bytes)

undefined1 meter_get_s(void)

{
  return DAT_0001204a;
}


// ===== remote_key_get @ fffb6eb6 (15 bytes)

undefined1 remote_key_get(void)

{
  return DAT_0001204c;
}


// ===== ptt_source_get @ fffb6ec5 (15 bytes)

/* returns 0x1204D (CAT TX read: 0->TX0, 5->TX1, else TX2) */

undefined1 ptt_source_get(void)

{
  return DAT_0001204d;
}


// ===== ckey_det @ fffb6ed4 (31 bytes)

/* P87 */

bool ckey_det(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c048;
  return -1 < cVar1;
}


// ===== ckey_dot @ fffb6ef3 (24 bytes)

/* P16 low */

bool ckey_dot(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c041;
  return (bVar1 & 0x40) == 0;
}


// ===== ckey_dash @ fffb6f0b (31 bytes)

/* P17 low */

bool ckey_dash(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c041;
  return -1 < cVar1;
}


// ===== jp_p51_get @ fffb6f2a (19 bytes)

/* P51 strap */

byte jp_p51_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 1 & 1;
}


// ===== atas_det @ fffb6f76 (30 bytes)

/* P55 */

bool atas_det(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return (bVar1 >> 5 & 1) == 1;
}


// ===== tx_line_get @ fffb6fac (19 bytes)

/* P73 TX */

byte tx_line_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  return bVar1 >> 3 & 1;
}


// ===== send_a_get @ fffb6fbf (19 bytes)

byte send_a_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02a;
  return bVar1 >> 2 & 1;
}

