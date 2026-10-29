// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe564b @ fffe564b (69 bytes)

undefined1 FUN_fffe564b(void)

{
  uint uVar1;
  
  if (PTR_DAT_00025d78[0x407] == '\x01') {
    return 0;
  }
  uVar1 = (uint)(byte)PTR_DAT_00025d78[0x2b];
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


// ===== FUN_fffe5690 @ fffe5690 (47 bytes)

bool FUN_fffe5690(void)

{
  byte bVar1;
  bool bStack_3;
  
  bVar1 = vfo_mode(1);
  if ((bVar1 == 3) || (bVar1 == 2)) {
    bStack_3 = false;
  }
  else {
    bStack_3 = true;
  }
  bStack_3 = !bStack_3;
  return bStack_3;
}


// ===== FUN_fffe56bf @ fffe56bf (37 bytes)

undefined1 FUN_fffe56bf(void)

{
  byte bVar1;
  undefined1 uStack_3;
  
  bVar1 = vfo_mode(1);
  if ((bVar1 < 2) || (bVar1 - 4 < 4)) {
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
  undefined *puVar1;
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
     PTR_DAT_00025d78[0x437] == '\x01')) {
    beep_request(1);
    FUN_fffc8beb();
    PTR_DAT_00025d78[0x1c2] = 0x5e;
    puVar1 = PTR_DAT_00025d78;
    *(undefined2 *)(PTR_DAT_00025d78 + 0x42f) = *(undefined2 *)(local_80 + 2);
    *(undefined4 *)(puVar1 + 0x42b) = local_80[1];
    *(undefined4 *)(puVar1 + 0x427) = *local_80;
    FUN_fffc8cbb(0x5e);
    FUN_fffc8d8c();
    PTR_DAT_00025d78[0x409] = 1;
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
  if (PTR_DAT_00025d78[0x1c7] == '\x01') {
    if ((DAT_00009aad == '\0') && (bVar1 = FUN_fffe584e(0x96a0), bVar1 == 1)) {
      local_2 = 1;
    }
    if ((DAT_00009aae == '\0') && (bVar1 = FUN_fffe584e(0x96d3), bVar1 == 1)) {
      local_2 = local_2 | 2;
    }
    if ((DAT_00009aaf == '\0') && (bVar1 = FUN_fffe584e(0x9706), bVar1 == 1)) {
      local_2 = local_2 | 4;
    }
    if ((DAT_00009ab0 == '\0') && (bVar1 = FUN_fffe584e(0x9739), bVar1 == 1)) {
      local_2 = local_2 | 8;
    }
    if ((DAT_00009ab1 == '\0') && (bVar1 = FUN_fffe584e(0x976c), bVar1 == 1)) {
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
  if ((PTR_DAT_00025d7c[0x418] == '\0') || (PTR_DAT_00025d7c[0xba] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    switch(DAT_00018877) {
    case 0:
      PTR_DAT_00025d7c[0x419] = 0;
      FUN_fffe5a1a();
      return;
    case 1:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5ab2();
        if (iVar2 == 0) {
          PTR_DAT_00025d7c[0x419] = 0;
          FUN_fffe5e67();
          DAT_00018877 = 2;
          return;
        }
        PTR_DAT_00025d7c[0x419] = 1;
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
  PTR_DAT_00025d7c[0x419] = 0;
  scan_step();
  FUN_fffe5e67();
  DAT_00018877 = 2;
  return;
}


// ===== FUN_fffe5a47 @ fffe5a47 (107 bytes)

void FUN_fffe5a47(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = DAT_00009dbd;
  PTR_DAT_00025d7c[0x419] = 1;
  iVar3 = FUN_fffe5f82();
  if ((iVar3 == 0) || (bVar2 = vfo_is_memory(bVar2), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(6);
    if (DAT_00009ac5 == '\x01') {
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
  return DAT_00020b48 == '\x01';
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
  
  if (DAT_00009ac4 == '\0') {
    local_4 = 0;
  }
  else {
    if (DAT_00009dbd == '\0') {
      local_3 = DAT_00009dbe;
    }
    else {
      local_3 = DAT_00009dbf;
    }
    if (local_3 == '\x02') {
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
  
  if (DAT_00009ac2 == '\0') {
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
    if (((bVar1) && (iVar2 = FUN_fffe5e3b(local_1 + local_4), iVar2 == 0)) &&
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
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}


// ===== scan_start_down @ fffe5caf (49 bytes)

/* SC2 */

void scan_start_down(void)

{
  DAT_00018876 = 1;
  DAT_00018877 = 0;
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}


// ===== scan_stop @ fffe5ce0 (46 bytes)

/* SC0 */

void scan_stop(void)

{
  PTR_DAT_00025d7c[0x418] = 0;
  PTR_DAT_00025d7c[0x419] = 0;
  beep_request(6);
  PTR_DAT_00025d7c[0x40c] = 1;
  return;
}


// ===== FUN_fffe5d0e @ fffe5d0e (28 bytes)

bool FUN_fffe5d0e(void)

{
  return DAT_00018876 != '\0';
}


// ===== FUN_fffe5d2a @ fffe5d2a (37 bytes)

void FUN_fffe5d2a(void)

{
  if (DAT_00020f80 == '\0') {
    if (DAT_00018876 == '\x01') {
      scan_start_up();
      return;
    }
  }
  else if (DAT_00018876 == '\0') {
    scan_start_down();
    return;
  }
  return;
}


// ===== FUN_fffe5d4f @ fffe5d4f (45 bytes)

undefined1 FUN_fffe5d4f(void)

{
  undefined1 local_2;
  
  if (DAT_00018877 == 4) {
    local_2 = 1;
  }
  else if (DAT_00018877 < 5) {
    local_2 = 0;
  }
  else {
    local_2 = 1;
  }
  return local_2;
}


// ===== scan_step @ fffe5d7c (19 bytes)

/* One step in direction 0x18876 */

void scan_step(void)

{
  if (DAT_00018876 != '\0') {
    FUN_fffe5dd5();
    return;
  }
  FUN_fffe5d8f();
  return;
}


// ===== FUN_fffe5d8f @ fffe5d8f (70 bytes)

void FUN_fffe5d8f(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = DAT_00009dbd;
  bVar2 = vfo_is_memory(DAT_00009dbd);
  if (bVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 0;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar3 = FUN_fffe5e1b();
    } while (iVar3 == 1);
    return;
  }
  FUN_fffc809d(bVar1);
  return;
}


// ===== FUN_fffe5dd5 @ fffe5dd5 (70 bytes)

void FUN_fffe5dd5(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = DAT_00009dbd;
  bVar2 = vfo_is_memory(DAT_00009dbd);
  if (bVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 1;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar3 = FUN_fffe5e1b();
    } while (iVar3 == 1);
    return;
  }
  FUN_fffc8141(bVar1);
  return;
}


// ===== FUN_fffe5e1b @ fffe5e1b (32 bytes)

undefined1 FUN_fffe5e1b(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = memch_current(DAT_00009dbd);
  uVar2 = FUN_fffe5e3b(bVar1);
  return uVar2;
}


// ===== FUN_fffe5e3b @ fffe5e3b (44 bytes)

bool FUN_fffe5e3b(byte param_1)

{
  return ((&DAT_00006151)[(uint)param_1 * 0x5a] & 0x80) != 0;
}


// ===== FUN_fffe5e67 @ fffe5e67 (83 bytes)

void FUN_fffe5e67(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = vfo_is_memory(DAT_00009dbd);
  if (bVar1 == 1) {
    DAT_00018873 = 1;
    swtimer_start(0x33,0xfa);
    return;
  }
  iVar2 = FUN_fffe5fab();
  DAT_00018873 = 1;
  if (iVar2 != 1) {
    swtimer_start(0x33,5);
    return;
  }
  swtimer_start(0x33,0x32);
  return;
}


// ===== FUN_fffe5eba @ fffe5eba (20 bytes)

void FUN_fffe5eba(void)

{
  DAT_00018873 = 1;
  swtimer_start(0x33,0x19);
  return;
}


// ===== FUN_fffe5ece @ fffe5ece (21 bytes)

void FUN_fffe5ece(void)

{
  DAT_00018875 = 1;
  swtimer_start(0x35,5000);
  return;
}


// ===== FUN_fffe5ee3 @ fffe5ee3 (53 bytes)

undefined1 FUN_fffe5ee3(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018873 == '\x01') {
    bVar1 = swtimer_expired(0x33);
    if (bVar1 == 1) {
      DAT_00018873 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f18 @ fffe5f18 (53 bytes)

undefined1 FUN_fffe5f18(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018874 == '\x01') {
    bVar1 = swtimer_expired(0x34);
    if (bVar1 == 1) {
      DAT_00018874 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f4d @ fffe5f4d (53 bytes)

undefined1 FUN_fffe5f4d(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018875 == '\x01') {
    bVar1 = swtimer_expired(0x35);
    if (bVar1 == 1) {
      DAT_00018875 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f82 @ fffe5f82 (41 bytes)

bool FUN_fffe5f82(void)

{
  byte bVar1;
  
  bVar1 = vfo_mode(DAT_00009dbd);
  return bVar1 < 4;
}


// ===== FUN_fffe5fab @ fffe5fab (50 bytes)

undefined1 FUN_fffe5fab(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = vfo_mode(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 4 < 4) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe5fdd @ fffe5fdd (50 bytes)

undefined1 FUN_fffe5fdd(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = vfo_mode(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe600f @ fffe600f (31 bytes)

bool FUN_fffe600f(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(0);
  return (pbVar1[3] & 8) != 0;
}


// ===== FUN_fffe602e @ fffe602e (120 bytes)

void FUN_fffe602e(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = DAT_00009dbd;
  bVar2 = vfo_mode(0);
  bVar3 = vfo_is_memory(bVar3);
  if (bVar3 == 1) {
    PTR_DAT_00025d7c[0x46c] = 1;
    swtimer_start(0x40,200);
    return;
  }
  uVar1 = (uint)bVar2;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_DAT_00025d7c[0x46c] = 1;
    swtimer_start(0x40,10);
    return;
  }
  PTR_DAT_00025d7c[0x46c] = 1;
  swtimer_start(0x40,100);
  return;
}


// ===== FUN_fffe60a6 @ fffe60a6 (146 bytes)

void FUN_fffe60a6(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc809d(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 1) {
      scan_start_up();
      return;
    }
    scan_stop();
    return;
  }
  scan_start_up();
  return;
}


// ===== FUN_fffe6138 @ fffe6138 (146 bytes)

void FUN_fffe6138(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc8141(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 0) {
      scan_start_down();
      return;
    }
    scan_stop();
    return;
  }
  scan_start_down();
  return;
}


// ===== FUN_fffe61ca @ fffe61ca (29 bytes)

void FUN_fffe61ca(void)

{
  byte bVar1;
  
  bVar1 = blink_phase(0);
  if (bVar1 == 0) {
    PTR_DAT_00025d7c[0x1bc] = 0;
    return;
  }
  PTR_DAT_00025d7c[0x1bc] = 1;
  return;
}


// ===== ex_command @ fffe61e7 (178 bytes)

/* EX core: parse key, read or write, on set menu_apply_from_cat, copy reply 0x18878 -> 0x1C8E */

byte ex_command(char *text,byte is_set,ushort len,byte *reply,ushort *reply_len)

{
  byte *pbVar1;
  uint uVar2;
  byte bStack_1c;
  char acStack_1b [3];
  byte bStack_18;
  undefined4 local_17;
  undefined2 local_13;
  ushort *local_10;
  byte *local_c;
  ushort local_8;
  byte local_5;
  char *local_4;
  
  local_10 = reply_len;
  DAT_0001ff10 = 0;
  DAT_0001b234 = 0;
  local_13 = *(undefined2 *)(text + 6);
  local_17 = *(undefined4 *)(text + 2);
  local_c = reply;
  local_8 = len;
  local_5 = is_set;
  local_4 = text;
  bStack_18 = ex_parse_key(acStack_1b,(byte *)&local_17);
  if (bStack_18 == 0) {
    bStack_1c = 1;
  }
  else {
    bStack_18 = ex_read_or_write(acStack_1b,local_4,local_5,local_8);
    if ((bool)bStack_18) {
      if (local_5 == 1) {
        menu_apply_from_cat((uint)acStack_1b);
      }
      pbVar1 = &DAT_00018878;
      for (uVar2 = (uint)DAT_0001ff10; uVar2 != 0; uVar2 = uVar2 - 1) {
        *local_c = *pbVar1;
        local_c = local_c + 1;
        pbVar1 = pbVar1 + 1;
      }
      *local_10 = DAT_0001ff10;
      bStack_1c = DAT_0001b234;
    }
    else {
      bStack_1c = 1;
    }
  }
  DAT_0001b234 = bStack_1c;
  return bStack_1c;
}


// ===== ex_read_or_write @ fffe6299 (156 bytes)

/* Dispatch on is_set and desc string flag (+0x30) */

bool ex_read_or_write(char *key,char *text,byte is_set,ushort len)

{
  byte lim [16];
  byte lim_00 [16];
  ushort len_00;
  char *out;
  char *key_00;
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 in_stack_ffffffcc [12];
  undefined4 uVar4;
  byte abStack_20 [8];
  char cStack_18;
  byte bStack_e;
  ushort local_c;
  byte local_9;
  char *local_8;
  char *local_4;
  
  uVar4 = 0xfffe62ad;
  local_c = len;
  local_9 = is_set;
  local_8 = text;
  local_4 = key;
  bStack_e = menu_get_limits(key,abStack_20);
  key_00 = local_4;
  out = local_8;
  len_00 = local_c;
  pbVar2 = abStack_20;
  if (bStack_e == 1) {
    if (cStack_18 == '\0') {
      if (local_9 == 0) {
        pbVar1 = &stack0xffffffcc;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *pbVar1 = *pbVar2;
          pbVar1 = pbVar1 + 1;
          pbVar2 = pbVar2 + 1;
        }
        lim[0xc] = (char)uVar4;
        lim[0xd] = (char)((uint)uVar4 >> 8);
        lim[0xe] = (char)((uint)uVar4 >> 0x10);
        lim[0xf] = (char)((uint)uVar4 >> 0x18);
        lim[0] = in_stack_ffffffcc[0];
        lim[1] = in_stack_ffffffcc[1];
        lim[2] = in_stack_ffffffcc[2];
        lim[3] = in_stack_ffffffcc[3];
        lim[4] = in_stack_ffffffcc[4];
        lim[5] = in_stack_ffffffcc[5];
        lim[6] = in_stack_ffffffcc[6];
        lim[7] = in_stack_ffffffcc[7];
        lim[8] = in_stack_ffffffcc[8];
        lim[9] = in_stack_ffffffcc[9];
        lim[10] = in_stack_ffffffcc[10];
        lim[0xb] = in_stack_ffffffcc[0xb];
        bStack_e = ex_read_value(key_00,out,lim);
      }
      else {
        pbVar1 = &stack0xffffffcc;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *pbVar1 = *pbVar2;
          pbVar1 = pbVar1 + 1;
          pbVar2 = pbVar2 + 1;
        }
        lim_00[0xc] = (char)uVar4;
        lim_00[0xd] = (char)((uint)uVar4 >> 8);
        lim_00[0xe] = (char)((uint)uVar4 >> 0x10);
        lim_00[0xf] = (char)((uint)uVar4 >> 0x18);
        lim_00[0] = in_stack_ffffffcc[0];
        lim_00[1] = in_stack_ffffffcc[1];
        lim_00[2] = in_stack_ffffffcc[2];
        lim_00[3] = in_stack_ffffffcc[3];
        lim_00[4] = in_stack_ffffffcc[4];
        lim_00[5] = in_stack_ffffffcc[5];
        lim_00[6] = in_stack_ffffffcc[6];
        lim_00[7] = in_stack_ffffffcc[7];
        lim_00[8] = in_stack_ffffffcc[8];
        lim_00[9] = in_stack_ffffffcc[9];
        lim_00[10] = in_stack_ffffffcc[10];
        lim_00[0xb] = in_stack_ffffffcc[0xb];
        bStack_e = ex_write_value(key_00,out,len_00,lim_00);
      }
    }
    else if (local_9 == 0) {
      bStack_e = ex_read_string((int)local_4,local_8);
    }
    else {
      bStack_e = ex_write_string((uint)local_4,(int)local_8);
    }
  }
  return bStack_e != 0;
}


// ===== ex_read_string @ fffe6335 (198 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reply EXkkkkkk + 12-char text */

byte ex_read_string(int param_1,void *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_18;
  undefined4 local_17;
  undefined4 local_13;
  undefined4 local_f;
  byte bStack_b;
  undefined4 *local_8;
  int local_4;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_18 = 0;
  }
  else {
    local_f = 0;
    local_13 = 0;
    local_17 = 0;
    local_8 = param_2;
    local_4 = param_1;
    bVar2 = menu_string_get(param_1,(uint)&local_17,0xc);
    if (bVar2 == 0) {
      local_18 = 0;
    }
    else {
      DAT_0001887c = local_8[1];
      _DAT_00018878 = *local_8;
      DAT_00018888 = local_f;
      DAT_00018884 = local_13;
      DAT_00018880 = local_17;
      for (bStack_b = 0; bStack_b < 0xc; bStack_b = bStack_b + 1) {
        if (*(char *)((int)&DAT_00018880 + (uint)bStack_b) == '\0') {
          *(undefined1 *)((int)&DAT_00018880 + (uint)bStack_b) = 0x3b;
          break;
        }
      }
      if (bStack_b == 0xc) {
        uRam0001888c = 0x3b;
      }
      DAT_0001ff10 = bStack_b + 9;
      local_18 = 1;
    }
  }
  return local_18;
}


// ===== ex_write_string @ fffe63fb (113 bytes)

/* Copy P4 text up to ";" (max 12) into the item */

bool ex_write_string(uint param_1,int param_2)

{
  byte bVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  byte local_c;
  char local_b;
  int local_8;
  uint local_4;
  
  local_b = '\0';
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = 0;
  local_8 = param_2;
  local_4 = param_1;
  do {
    if (0xc < local_c) {
LAB_fffe6458:
      return local_b == '\x01';
    }
    if (*(char *)((uint)local_c + local_8 + 8) == ';') {
      bVar1 = menu_string_set(local_4,(uint)&local_18,local_c);
      if (bVar1 == 0) {
        return false;
      }
      local_b = '\x01';
      goto LAB_fffe6458;
    }
    *(undefined1 *)((int)&local_18 + (uint)local_c) = *(undefined1 *)((uint)local_c + local_8 + 8);
    local_c = local_c + 1;
  } while( true );
}


// ===== ex_read_value @ fffe646c (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe654d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Format value: 1 digit, 2/3 digits (+sign), or 4 digits (u16 or scaled x10 / x20+20) */

byte ex_read_value(char *key,char *out,byte lim [16])

{
  byte bVar1;
  byte bStack_15;
  bool bStack_12;
  ushort auStack_10 [2];
  char *local_c;
  char *local_8;
  
  DAT_0001887c = *(undefined4 *)(out + 4);
  _DAT_00018878 = *(undefined4 *)out;
  local_c = out;
  local_8 = key;
  bVar1 = menu_value_get(key,auStack_10);
  if (bVar1 == 0) {
    bStack_15 = 0;
  }
  else if ((lim._12_4_ & 0xff) == 2) {
    auStack_10[0] = auStack_10[0] * 0x14 + 0x14;
    DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    bStack_15 = 1;
  }
  else if ((lim._12_4_ & 0xff) == 1) {
    auStack_10[0] = auStack_10[0] * 10;
    DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    bStack_15 = 1;
  }
  else {
    if (lim[9] == 0) {
      if (lim[0xb] == 1) {
        DAT_00018880._0_1_ = nib2hex((byte)auStack_10[0]);
        DAT_00018880._1_1_ = 0x3b;
        DAT_0001ff10 = 10;
      }
      else {
        bStack_12 = 2 < lim[0xb];
        DAT_0001ff10 = ex_fmt_byte((byte)auStack_10[0],bStack_12,lim[10] != 0);
      }
    }
    else {
      DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    }
    bStack_15 = 1;
  }
  return bStack_15;
}


// ===== ex_write_value @ fffe6550 (314 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6687) */
/* WARNING: Removing unreachable block (ram,0xfffe6664) */
/* WARNING: Removing unreachable block (ram,0xfffe6659) */
/* Check length/range, parse P4, unscale (/10 or /20-1), menu_value_set */

byte ex_write_value(char *key,char *text,ushort len,byte lim [16])

{
  bool bVar1;
  byte bVar2;
  ushort uStack_1e;
  short local_1c;
  ushort local_1a;
  ushort local_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  undefined1 local_11;
  byte bStack_10;
  ushort local_e;
  char *local_c;
  char *local_8;
  
  local_1c = lim[0xb] + 9;
  if ((lim._12_4_ & 0xff) == 1) {
    local_18 = lim._2_2_ * 10;
    local_1a = lim._0_2_ * 10;
  }
  else if ((lim._12_4_ & 0xff) == 2) {
    local_18 = lim._2_2_ * 0x14 + 0x14;
    local_1a = lim._0_2_ * 0x14 + 0x14;
  }
  else {
    local_18._0_1_ = lim[2];
    local_18._1_1_ = lim[3];
    local_1a._0_1_ = lim[0];
    local_1a._1_1_ = lim[1];
  }
  if ((lim[9] == 0) && (lim[0xb] < 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_e = len;
  local_c = text;
  local_8 = key;
  if (bVar1) {
    local_11 = lim[10] != 0;
    bStack_10 = ex_parse_byte(text + 8,&bStack_12,lim[0xb],local_11,(byte)local_1a,(byte)local_18,
                              len);
    if (bStack_10 == 0) {
      return 0;
    }
    if (lim[10] == 0) {
      uStack_1e = (ushort)bStack_12;
    }
    else {
      bStack_13 = bStack_12;
      uStack_1e = (ushort)(char)bStack_12;
    }
    bStack_10 = ex_value_allowed(local_8,uStack_1e);
    if (bStack_10 == 0) {
      return 0;
    }
    bVar2 = menu_value_set(local_8,&uStack_1e);
    if (bVar2 == 0) {
      return 0;
    }
  }
  else {
    bStack_10 = ex_parse_4digits(text + 8,&uStack_16,local_1a,local_18,(byte)local_1c,len);
    if (!(bool)bStack_10) {
      return 0;
    }
    uStack_1e = uStack_16;
    if ((lim._12_4_ & 0xff) == 1) {
      uStack_1e = (short)uStack_16 / 10;
    }
    else if ((lim._12_4_ & 0xff) == 2) {
      uStack_1e = (short)uStack_16 / 0x14 - 1;
    }
    bVar2 = menu_value_set(local_8,&uStack_1e);
    if (bVar2 == 0) {
      return 0;
    }
  }
  return 1;
}


// ===== ex_value_allowed @ fffe668a (88 bytes)

/* Rejects EX010113 (SSB TX BPF SEL) value 5 (50-4000Hz) */

byte ex_value_allowed(char *param_1,short param_2)

{
  bool bVar1;
  byte local_8;
  
  if (param_1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    if ((*param_1 == '\0') && (param_1[1] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (param_1[2] == '\f')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (param_2 == 5) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 1;
    }
  }
  return local_8;
}


// ===== ex_fmt_byte @ fffe66e2 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe67f2) */
/* WARNING: Removing unreachable block (ram,0xfffe67ac) */
/* WARNING: Removing unreachable block (ram,0xfffe6726) */
/* Byte -> 2/3 decimal digits, or sign + 2 digits */

short ex_fmt_byte(byte param_1,char param_2,byte param_3)

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
      *(char *)((int)&DAT_00018880 + (uint)local_c) = cVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + (uint)local_c) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_00018880._0_1_ = 0x2b;
    }
    else {
      DAT_00018880._0_1_ = 0x2d;
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
      *(char *)((int)&DAT_00018880 + local_c + 1) = cVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + local_c + 1) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== ex_fmt_4digits @ fffe67f5 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6866) */
/* WARNING: Removing unreachable block (ram,0xfffe681f) */
/* u16 -> 4 decimal digits */

short ex_fmt_4digits(ushort param_1)

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
    *(char *)((int)&DAT_00018880 + (uint)local_a) = cVar1;
  }
  *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = 0x3b;
  return (byte)(local_a + 1) + 8;
}

