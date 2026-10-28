// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe5350 @ fffe5350 (63 bytes)

void FUN_fffe5350(undefined1 param_1)

{
  PTR_DAT_00025d78[0x90] = 1;
  PTR_DAT_00025d78[0xbe] = 2;
  PTR_DAT_00025d78[0xc0] = 0;
  PTR_DAT_00025d78[0xc1] = 0;
  FUN_fffe538f(param_1);
  FUN_fff9ba18();
  return;
}


// ===== FUN_fffe538f @ fffe538f (49 bytes)

void FUN_fffe538f(char param_1)

{
  PTR_DAT_00025d78[0x1c8] = param_1;
  PTR_DAT_00025d78[0xbf] = param_1 + -1;
  PTR_DAT_00025d78[0x1ce] = param_1 + -1;
  return;
}


// ===== FUN_fffe53c0 @ fffe53c0 (65 bytes)

void FUN_fffe53c0(void)

{
  PTR_DAT_00025d78[0x1cc] = 0;
  PTR_DAT_00025d78[0x1cd] = 0;
  PTR_DAT_00025d78[0x417] = 0;
  PTR_DAT_00025d78[0x1d1] = 0;
  PTR_DAT_00025d78[0x2b] = 7;
  return;
}


// ===== FUN_fffe5401 @ fffe5401 (323 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe551d) */
/* WARNING: Removing unreachable block (ram,0xfffe5477) */
/* WARNING: Removing unreachable block (ram,0xfffe54af) */
/* WARNING: Removing unreachable block (ram,0xfffe54e6) */
/* WARNING: Removing unreachable block (ram,0xfffe543f) */

ushort FUN_fffe5401(char param_1)

{
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined1 local_5;
  
  if (param_1 == '\x05') {
    local_5 = DAT_00009ab1;
    local_8 = (ushort)DAT_0000976b;
    local_a = CONCAT11(DAT_00009607,DAT_00009608);
  }
  else if (param_1 == '\x02') {
    local_5 = DAT_00009aae;
    local_8 = (ushort)DAT_000096d2;
    local_a = CONCAT11(DAT_0000943f,DAT_00009440);
  }
  else if (param_1 == '\x03') {
    local_5 = DAT_00009aaf;
    local_8 = (ushort)DAT_00009705;
    local_a = CONCAT11(DAT_000094d7,DAT_000094d8);
  }
  else if (param_1 == '\x04') {
    local_5 = DAT_00009ab0;
    local_8 = (ushort)DAT_00009738;
    local_a = CONCAT11(DAT_0000956f,DAT_00009570);
  }
  else if (param_1 == '\x01') {
    local_5 = DAT_00009aad;
    local_8 = (ushort)DAT_0000969f;
    local_a = CONCAT11((undefined1)DAT_000093a7,DAT_000093a7._1_1_);
  }
  if (local_5 == '\0') {
    local_c = local_8;
  }
  else {
    local_c = local_a;
  }
  return local_c;
}


// ===== FUN_fffe5544 @ fffe5544 (38 bytes)

undefined1 FUN_fffe5544(byte param_1)

{
  return (&DAT_00009aac)[param_1];
}


// ===== FUN_fffe556a @ fffe556a (65 bytes)

void FUN_fffe556a(void)

{
  PTR_DAT_00025d78[0x1c9] = 0;
  PTR_DAT_00025d78[0x1ca] = 0;
  PTR_DAT_00025d78[0x417] = 0;
  PTR_DAT_00025d78[0x78] = 0;
  PTR_DAT_00025d78[0x1cb] = 0;
  return;
}


// ===== FUN_fffe55ab @ fffe55ab (160 bytes)

undefined1 FUN_fffe55ab(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffe564b();
  if (iVar2 == 0) {
    PTR_DAT_00025d78[0x1cd] = 0;
    PTR_DAT_00025d78[0x1cc] = 0;
    return 0;
  }
  if ((PTR_DAT_00025d78[0x1cc] == '\x01') || (PTR_DAT_00025d78[0x1cd] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (PTR_DAT_00025d78[0x2b] != '\x01') {
      FUN_fffe53c0();
      return 0;
    }
    iVar2 = FUN_fffe5401(param_1);
    if (iVar2 == 0) {
      PTR_DAT_00025d78[0x1cd] = 0;
      PTR_DAT_00025d78[0x1cc] = 0;
      beep_request(3);
      return 0;
    }
    PTR_DAT_00025d78[0x2b] = 5;
  }
  return 1;
}


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
  char cVar1;
  bool bStack_3;
  
  cVar1 = vfo_mode(1);
  if ((cVar1 == '\x03') || (cVar1 == '\x02')) {
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
  int iVar1;
  byte local_3;
  byte local_2;
  
  local_2 = 0;
  if (PTR_DAT_00025d78[0x1c7] == '\x01') {
    if ((DAT_00009aad == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = 1;
    }
    if ((DAT_00009aae == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 2;
    }
    if ((DAT_00009aaf == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 4;
    }
    if ((DAT_00009ab0 == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 8;
    }
    if ((DAT_00009ab1 == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
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

undefined1 FUN_fffe584e(int param_1)

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
  undefined1 uVar2;
  int iVar3;
  
  uVar2 = DAT_00009dbd;
  PTR_DAT_00025d7c[0x419] = 1;
  iVar3 = FUN_fffe5f82();
  if ((iVar3 == 0) || (iVar3 = vfo_is_memory(uVar2), iVar3 == 1)) {
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
  int iVar1;
  
  iVar1 = af_mute_get();
  return iVar1 == 1;
}


// ===== FUN_fffe5ae7 @ fffe5ae7 (24 bytes)

bool FUN_fffe5ae7(void)

{
  int iVar1;
  
  iVar1 = af_mute_get();
  return iVar1 == 1;
}


// ===== scan_allowed @ fffe5aff (82 bytes)

undefined1 scan_allowed(void)

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

undefined1 FUN_fffe5b51(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined1 uStack_7;
  
  if (DAT_00009ac2 == '\0') {
    uStack_7 = FUN_fffe5c26(0,99);
  }
  else {
    bVar2 = FUN_fff9bfb8();
    if (bVar2 < 8) {
      if (bVar2 == 7) {
        sVar3 = dest_code_get();
        if ((sVar3 == -0x26b0) || (sVar3 == -0x5b3b)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_7 = FUN_fffe5c26(0x75,7);
        }
        else {
          if ((sVar3 == 0x315b) || (sVar3 == 0x50e2)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_7 = FUN_fffe5c26(0x75,0xf);
          }
          else {
            uStack_7 = 0;
          }
        }
      }
      else if (bVar2 == 6) {
        uStack_7 = FUN_fffe5c26(99,0x12);
      }
      else {
        uStack_7 = FUN_fffe5c26("RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                                [bVar2 + 0x3d92],(&UNK_fff872ab)[bVar2]);
      }
    }
    else {
      uStack_7 = 0;
    }
  }
  return uStack_7;
}


// ===== FUN_fffe5c26 @ fffe5c26 (88 bytes)

undefined1 FUN_fffe5c26(char param_1,byte param_2)

{
  int iVar1;
  byte local_5;
  byte local_4;
  
  local_5 = 0;
  local_4 = 0;
  while( true ) {
    if (param_2 <= local_4) {
      return 0;
    }
    iVar1 = memch_valid(param_1 + local_4);
    if (((iVar1 == 1) && (iVar1 = FUN_fffe5e3b(param_1 + local_4), iVar1 == 0)) &&
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
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = DAT_00009dbd;
  iVar2 = vfo_is_memory(DAT_00009dbd);
  if (iVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 0;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar2 = FUN_fffe5e1b();
    } while (iVar2 == 1);
    return;
  }
  FUN_fffc809d(uVar1);
  return;
}


// ===== FUN_fffe5dd5 @ fffe5dd5 (70 bytes)

void FUN_fffe5dd5(void)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = DAT_00009dbd;
  iVar2 = vfo_is_memory(DAT_00009dbd);
  if (iVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 1;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar2 = FUN_fffe5e1b();
    } while (iVar2 == 1);
    return;
  }
  FUN_fffc8141(uVar1);
  return;
}


// ===== FUN_fffe5e1b @ fffe5e1b (32 bytes)

undefined1 FUN_fffe5e1b(void)

{
  undefined1 uVar1;
  
  uVar1 = memch_current(DAT_00009dbd);
  uVar1 = FUN_fffe5e3b(uVar1);
  return uVar1;
}


// ===== FUN_fffe5e3b @ fffe5e3b (44 bytes)

bool FUN_fffe5e3b(byte param_1)

{
  return ((&DAT_00006151)[(uint)param_1 * 0x5a] & 0x80) != 0;
}


// ===== FUN_fffe5e67 @ fffe5e67 (83 bytes)

void FUN_fffe5e67(void)

{
  int iVar1;
  
  iVar1 = vfo_is_memory(DAT_00009dbd);
  if (iVar1 == 1) {
    DAT_00018873 = 1;
    swtimer_start(0x33,0xfa);
    return;
  }
  iVar1 = FUN_fffe5fab();
  DAT_00018873 = 1;
  if (iVar1 != 1) {
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
  swtimer_start(0x35,&DAT_00001388);
  return;
}


// ===== FUN_fffe5ee3 @ fffe5ee3 (53 bytes)

undefined1 FUN_fffe5ee3(void)

{
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018873 == '\x01') {
    iVar1 = swtimer_expired(0x33);
    if (iVar1 == 1) {
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
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018874 == '\x01') {
    iVar1 = swtimer_expired(0x34);
    if (iVar1 == 1) {
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
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018875 == '\x01') {
    iVar1 = swtimer_expired(0x35);
    if (iVar1 == 1) {
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
  int iVar1;
  
  iVar1 = vfo_rec_ptr(0);
  return (*(byte *)(iVar1 + 3) & 8) != 0;
}


// ===== FUN_fffe602e @ fffe602e (120 bytes)

void FUN_fffe602e(void)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  
  uVar2 = DAT_00009dbd;
  bVar3 = vfo_mode(0);
  iVar4 = vfo_is_memory(uVar2);
  if (iVar4 == 1) {
    PTR_DAT_00025d7c[0x46c] = 1;
    swtimer_start(0x40,200);
    return;
  }
  uVar1 = (uint)bVar3;
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
  int iVar1;
  
  iVar1 = blink_phase(0);
  if (iVar1 == 0) {
    PTR_DAT_00025d7c[0x1bc] = 0;
    return;
  }
  PTR_DAT_00025d7c[0x1bc] = 1;
  return;
}


// ===== ex_command @ fffe61e7 (178 bytes)

/* EX core: parse key, read or write, on set menu_apply_from_cat, copy reply 0x18878 -> 0x1C8E */

undefined1
ex_command(int param_1,char param_2,undefined2 param_3,undefined1 *param_4,undefined4 param_5,
          ushort *param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 uStack_1c;
  undefined1 auStack_1b [3];
  char cStack_18;
  undefined4 local_17;
  undefined2 local_13;
  ushort *local_10;
  undefined1 *local_c;
  undefined2 local_8;
  char local_5;
  int local_4;
  
  local_10 = param_6;
  DAT_0001ff10 = 0;
  DAT_0001b234 = 0;
  local_13 = *(undefined2 *)(param_1 + 6);
  local_17 = *(undefined4 *)(param_1 + 2);
  local_c = param_4;
  local_8 = param_3;
  local_5 = param_2;
  local_4 = param_1;
  cStack_18 = ex_parse_key();
  if (cStack_18 == '\0') {
    uStack_1c = 1;
  }
  else {
    cStack_18 = ex_read_or_write(auStack_1b,local_4,local_5,local_8);
    if (cStack_18 == '\0') {
      uStack_1c = 1;
    }
    else {
      if (local_5 == '\x01') {
        menu_apply_from_cat(auStack_1b);
      }
      puVar1 = &DAT_00018878;
      for (uVar2 = (uint)DAT_0001ff10; uVar2 != 0; uVar2 = uVar2 - 1) {
        *local_c = *puVar1;
        local_c = local_c + 1;
        puVar1 = puVar1 + 1;
      }
      *local_10 = DAT_0001ff10;
      uStack_1c = DAT_0001b234;
    }
  }
  DAT_0001b234 = uStack_1c;
  return uStack_1c;
}


// ===== ex_read_or_write @ fffe6299 (156 bytes)

/* Dispatch on is_set and desc string flag (+0x30) */

bool ex_read_or_write(undefined4 param_1,undefined4 param_2,char param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char extraout_R1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_34 [12];
  undefined4 uStack_28;
  undefined1 auStack_20 [8];
  char cStack_18;
  char cStack_e;
  undefined2 local_c;
  char local_9;
  undefined4 local_8;
  undefined4 local_4;
  
  uStack_28 = 0xfffe62ad;
  local_c = param_4;
  local_9 = param_3;
  local_8 = param_2;
  local_4 = param_1;
  puVar7 = (undefined4 *)menu_get_limits(param_1);
  uVar3 = local_4;
  uVar2 = local_8;
  uVar1 = local_c;
  cStack_e = extraout_R1;
  if (extraout_R1 == '\x01') {
    if (local_9 == '\0') {
      *puVar7 = 1;
    }
    if (cStack_18 == '\0') {
      if (puVar7 == (undefined4 *)0x0) {
        puVar4 = auStack_34;
        puVar5 = auStack_20;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        cStack_e = ex_write_value(uVar3,uVar2,uVar1);
      }
      else {
        puVar4 = auStack_34;
        puVar5 = auStack_20;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        cStack_e = ex_read_value(uVar3,uVar2);
      }
    }
    else if (puVar7 == (undefined4 *)0x0) {
      uStack_28 = 0xfffe631f;
      cStack_e = ex_write_string(local_4,local_8);
    }
    else {
      uStack_28 = 0xfffe6315;
      cStack_e = ex_read_string(local_4,local_8);
    }
  }
  return cStack_e != '\0';
}

