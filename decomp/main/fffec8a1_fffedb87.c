// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffec8a1 @ fffec8a1 (112 bytes)

void FUN_fffec8a1(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = swtimer_expired(0x27);
  uVar2 = 0;
  if (bVar1 == 0) {
    return;
  }
  DAT_00025d04 = (float)FUN_fffb6e5c();
  if (DAT_00025d04 <= 4.3) {
    if (1.1 < DAT_00025d04 != (bool)((byte)(uVar2 >> 3) & 1)) {
      send_a_set(0);
      send_b_set(0);
      swtimer_start(0x27,5);
      DAT_0001b3ac = 5;
      return;
    }
    atu_mem_store();
    DAT_0001b3ac = 0xe;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec911 @ fffec911 (163 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec925) */
/* WARNING: Removing unreachable block (ram,0xfffec940) */
/* WARNING: Removing unreachable block (ram,0xfffec95b) */

void FUN_fffec911(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 != 0) {
    DAT_0001b3b2 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 10];
    DAT_0001b3ae = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xb];
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xc];
    DAT_00020b3f = 2;
    DAT_0001b3b0 = DAT_0001b3ae;
    DAT_0001b3b3 = DAT_0001b3ae;
    swtimer_start(0x27,5);
    DAT_00025cfc = 0x437f0000;
    DAT_0001b3ac = 6;
    return;
  }
  return;
}


// ===== FUN_fffec9b4 @ fffec9b4 (57 bytes)

void FUN_fffec9b4(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  FUN_fffed12f();
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x06') {
    DAT_0001b3ac = 0x14;
  }
  else {
    DAT_0001b3ac = 0x15;
  }
  return;
}


// ===== FUN_fffec9ed @ fffec9ed (91 bytes)

void FUN_fffec9ed(void)

{
  byte bVar1;
  
  if (DAT_00020b3f == '\x03') {
    DAT_0001b3ac = 0xf;
    return;
  }
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  send_a_set(1);
  send_b_set(1);
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x14') {
    DAT_0001b3ac = 7;
  }
  else {
    DAT_0001b3ac = 0xb;
  }
  return;
}


// ===== FUN_fffeca48 @ fffeca48 (54 bytes)

void FUN_fffeca48(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\a') {
    DAT_0001b3ac = 8;
  }
  else {
    DAT_0001b3ac = 0xc;
  }
  return;
}


// ===== FUN_fffeca7e @ fffeca7e (292 bytes)

void FUN_fffeca7e(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00025cfc = fVar3;
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    if ((DAT_00009ab8 == '\x01') && (fVar3 <= 1.5)) {
      DAT_0001b3ac = 9;
      return;
    }
  }
  if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b3;
    if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 9;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 6;
  return;
}


// ===== FUN_fffecba2 @ fffecba2 (325 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecbcc) */

void FUN_fffecba2(void)

{
  byte local_1;
  
  if (4.0 < DAT_00025cfc == SBORROW4((int)&stack0x00000000,8)) {
    DAT_00025cfc = 255.0;
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xd];
    if (DAT_0001b3bb < 2) {
      local_1 = 9;
    }
    else {
      local_1 = 3;
    }
    if ((uint)DAT_0001b3b9 + (uint)local_1 < 0x100) {
      DAT_0001b3b5 = DAT_0001b3b9 + local_1;
    }
    else {
      DAT_0001b3b5 = -1;
    }
    if ((uint)DAT_0001b3ba + (uint)local_1 < 0x100) {
      DAT_0001b3b7 = DAT_0001b3ba + local_1;
    }
    else {
      DAT_0001b3b7 = -1;
    }
    if (DAT_0001b3b9 < local_1) {
      DAT_0001b3ae = '\0';
    }
    else {
      DAT_0001b3ae = DAT_0001b3b9 - local_1;
    }
    if (DAT_0001b3ba < local_1) {
      DAT_0001b3b0 = '\0';
    }
    else {
      DAT_0001b3b0 = DAT_0001b3ba - local_1;
    }
    DAT_0001b3b6 = DAT_0001b3ae;
    DAT_0001b3b8 = DAT_0001b3b0;
    send_a_set(0);
    send_b_set(0);
    swtimer_start(0x27,4);
    DAT_0001b3ac = 10;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffecce7 @ fffecce7 (255 bytes)

void FUN_fffecce7(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    DAT_00025cfc = fVar3;
  }
  if ((ushort)DAT_0001b3b7 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b8;
    if ((ushort)DAT_0001b3b5 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 0xd;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 10;
  return;
}


// ===== FUN_fffecde6 @ fffecde6 (83 bytes)

void FUN_fffecde6(void)

{
  if (DAT_00025cfc < DAT_00025d04) {
    DAT_0001b3ae = DAT_0001b3b9;
    DAT_0001b3b0 = DAT_0001b3ba;
  }
  else {
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
  }
  FUN_fffed12f();
  atu_mem_store();
  DAT_0001b3ac = 0xe;
  return;
}


// ===== FUN_fffece39 @ fffece39 (48 bytes)

void FUN_fffece39(void)

{
  FUN_fffec4db();
  DAT_00020b41 = 0;
  DAT_00020b2d = 0;
  DAT_00020b3f = 2;
  FUN_fffec537(1);
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffece69 @ fffece69 (16 bytes)

void FUN_fffece69(void)

{
  beep_request(3);
  DAT_0001b3ac = 0x10;
  return;
}


// ===== FUN_fffece79 @ fffece79 (44 bytes)

void FUN_fffece79(void)

{
  DAT_00020b2d = 0;
  DAT_0001b3ae = 0;
  DAT_0001b3b0 = 0;
  FUN_fffed12f();
  FUN_fffec4db();
  DAT_0001b3ac = 0;
  return;
}


// ===== atu_mem_store @ fffecea5 (263 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecf52) */
/* WARNING: Removing unreachable block (ram,0xfffecf1b) */
/* WARNING: Removing unreachable block (ram,0xfffecef3) */
/* WARNING: Removing unreachable block (ram,0xfffeceea) */
/* WARNING: Removing unreachable block (ram,0xfffecf0a) */
/* WARNING: Removing unreachable block (ram,0xfffecf47) */
/* WARNING: Removing unreachable block (ram,0xfffecf66) */
/* WARNING: Removing unreachable block (ram,0xfffecf79) */
/* Stores (freq key, 0x1B3AF, 0x1B3AD) in the 100-entry tuner memory 0x9898 ring and saves it */

void atu_mem_store(void)

{
  uint uVar1;
  byte bStack_16;
  byte bStack_15;
  undefined1 uStack_4;
  
  uVar1 = FUN_fffb4135(DAT_00025d00);
  bStack_15 = 0xff;
  bStack_16 = 0;
  do {
    if (DAT_00009899 <= bStack_16) {
LAB_fffecf38:
      if (bStack_15 == 0xff) {
        (&DAT_0000989a)[(uint)DAT_00009898 * 4] = (char)(uVar1 >> 0x18);
        uStack_4 = (undefined1)(uVar1 >> 0x10);
        (&DAT_0000989b)[(uint)DAT_00009898 * 4] = uStack_4;
        (&DAT_0000989c)[(uint)DAT_00009898 * 4] = DAT_0001b3af;
        (&DAT_0000989d)[(uint)DAT_00009898 * 4] = DAT_0001b3ad;
        if (DAT_00009899 < 100) {
          DAT_00009899 = DAT_00009899 + 1;
        }
        if (DAT_00009898 < 99) {
          DAT_00009898 = DAT_00009898 + 1;
        }
        else {
          DAT_00009898 = 0;
        }
      }
      eeprom_save_atu_mem();
      return;
    }
    if (uVar1 >> 0x10 ==
        (uint)CONCAT11((&DAT_0000989a)[(uint)bStack_16 * 4],(&DAT_0000989b)[(uint)bStack_16 * 4])) {
      (&DAT_0000989c)[(uint)bStack_16 * 4] = DAT_0001b3af;
      (&DAT_0000989d)[(uint)bStack_16 * 4] = DAT_0001b3ad;
      bStack_15 = bStack_16;
      goto LAB_fffecf38;
    }
    bStack_16 = bStack_16 + 1;
  } while( true );
}


// ===== FUN_fffecfac @ fffecfac (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecff5) */
/* WARNING: Removing unreachable block (ram,0xfffed085) */
/* WARNING: Removing unreachable block (ram,0xfffed096) */
/* WARNING: Removing unreachable block (ram,0xfffecffe) */

byte FUN_fffecfac(char *param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte local_25;
  byte local_1d;
  char *pcStack_1c;
  char *pcStack_18;
  char *local_10;
  
  bVar2 = DAT_00009899;
  local_25 = 0xff;
  if (param_1 < (char *)0x7a120) {
    local_10 = (char *)0x0;
  }
  else {
    local_10 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
               + (int)(param_1 + 0x29cc);
  }
  for (local_1d = 0; local_1d < bVar2; local_1d = local_1d + 1) {
    iVar3 = FUN_fffb2fec(CONCAT11((&DAT_0000989a)[(uint)local_1d * 4],
                                  (&DAT_0000989b)[(uint)local_1d * 4]));
    pcStack_1c = (char *)(iVar3 * 10000);
    if ((pcStack_1c < local_10) || (param_1 + 500000 < pcStack_1c)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      if (pcStack_1c < param_1) {
        pcStack_1c = param_1 + iVar3 * -10000;
      }
      else {
        pcStack_1c = pcStack_1c + -(int)param_1;
      }
      if (local_25 == 0xff) {
        local_25 = local_1d;
        pcStack_18 = pcStack_1c;
      }
      else if (pcStack_1c < pcStack_18) {
        local_25 = local_1d;
        pcStack_18 = pcStack_1c;
      }
    }
  }
  if (local_25 != 0xff) {
    DAT_0001b3b0 = (&DAT_0000989c)[(uint)local_25 * 4];
    DAT_0001b3ae = (&DAT_0000989d)[(uint)local_25 * 4];
  }
  return local_25;
}


// ===== FUN_fffed0ae @ fffed0ae (129 bytes)

/* WARNING: Removing unreachable block (ram,0xfffed0cd) */
/* WARNING: Removing unreachable block (ram,0xfffed0c0) */
/* WARNING: Removing unreachable block (ram,0xfffed0f2) */
/* WARNING: Removing unreachable block (ram,0xfffed107) */

byte FUN_fffed0ae(uint param_1)

{
  int iVar1;
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xa9 < local_d) {
      return 0xff;
    }
    iVar1 = FUN_fffb2fec(CONCAT11(BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x36],
                                  BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x37]));
    if (param_1 < (uint)(iVar1 * 10000)) break;
    local_d = local_d + 1;
  }
  DAT_0001b3ae = BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x39];
  DAT_0001b3b0 = BYTE_ARRAY_fff87bf2[(uint)local_d * 4 + 0x38];
  return local_d;
}


// ===== FUN_fffed12f @ fffed12f (54 bytes)

void FUN_fffed12f(void)

{
  DAT_0001b3ad = DAT_0001b3ae;
  DAT_0001b3af = DAT_0001b3b0;
  DAT_0001b3b1 = "EX010101EX010102EX010103EX010104EX010105EX010106EX010107EX010108EX010109EX010110EX010111EX010112EX010113EX010114EX010115EX010116EX010117EX010118EX010119EX010201EX010202EX010203EX010204EX010205EX010206EX010207EX010208EX010209EX010210EX010211EX010212EX010213EX010214EX010215EX010216EX010217EX010301EX010302EX010303EX010304EX010305EX010306EX010307EX010308EX010309EX010310EX010311EX010312EX010313EX010314EX010315EX010316EX010317EX010318EX010319EX010320EX010321EX010401EX010402EX010403EX010404EX010405EX010406EX010407EX010408EX010409EX010410EX010411EX010412EX010413EX010414EX010415EX010416EX010417EX010418EX010419EX010420EX010501EX010502EX010503EX010504EX010505EX010506EX010507EX010508EX010509EX010510EX010511EX010512EX010513EX010514EX010515EX010516EX010517EX020101EX020102EX020103EX020104EX020105EX020106EX020107EX020108EX020109EX020110EX020111EX020112EX020113EX020114EX020115EX020116EX020117EX020118EX020119EX020120EX020201EX020202EX020203EX020204EX020205EX020206EX020207EX020208EX020209EX020210EX020211EX030101EX030102EX030103EX030104EX030105EX030106EX030107EX030108EX030109EX030110EX030111EX030112EX030113EX030114EX030115EX030116EX030117EX030118EX030119EX030120EX030121EX030122EX030123EX030124EX030125EX030126EX030201EX030202EX030203EX030204EX030205EX030206EX030301EX030302EX030303EX030304EX030305EX030306EX030307EX030308EX030309EX030310EX030311EX030312EX030313EX030314EX030315EX030316EX030317EX030318EX030319EX030401EX030402EX030403EX030404EX030405EX030406EX030407EX030408EX030501EX030502EX030503EX030504EX030505EX030506EX040101EX040102EX040103EX040104EX040105EX040106EX040201EX040202EX040203EX040204EX040301EX040302EX040303EX040304EX040401EX040402EX060101EX060102EX060103EX060104EX060105EX060106EX060107EX060108EX060109EX060110EX060111EX060112EX060113EX060114EX060115EX060116EX060117EX060118EX060201EX060202EX060203EX060204EX060205EX060206EX060207EX060208EX060209EX060210EX060211EX060212EX060213EX060214EX060215EX060216EX060217EX060218EX060301EX060302EX060303EX060304EX060305EX060306EX060307EX060308EX060309EX060310EX060311EX060312EX060313EX060314..." /* TRUNCATED STRING LITERAL */
                 [DAT_0001b3bb + 0x940];
  return;
}


// ===== FUN_fffed165 @ fffed165 (161 bytes)

void FUN_fffed165(void)

{
  byte bVar1;
  
  if (DAT_0001b3c3 == '\x01') {
    bVar1 = swtimer_expired(0x22);
    if (bVar1 == 1) {
      DAT_0001b3c3 = 0;
      DAT_00020b3c = 0;
      return;
    }
  }
  else {
    bVar1 = swtimer_expired(0x21);
    if (bVar1 != 0) {
      swtimer_start(0x21,5);
      DAT_00020b71 = 2;
      if (DAT_00020f0c == '\x01') {
        FUN_fffed399();
      }
      else {
        if (DAT_00020f0c != '\x02') {
          DAT_00020b3c = 0;
          return;
        }
        FUN_fffed2a9();
      }
      bVar1 = blink_phase(0);
      if (bVar1 == 0) {
        DAT_00020b71 = 0;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffed206 @ fffed206 (72 bytes)

void FUN_fffed206(char param_1)

{
  DAT_00020f0c = param_1;
  if (param_1 == '\x01') {
    FUN_fffed371();
  }
  else if (param_1 != '\x02') {
    DAT_0001b3be = 0;
    DAT_00020b2d = 0;
    DAT_00025d08 = DAT_00025d0c;
    FUN_fffec4db();
    return;
  }
  FUN_fffec493();
  return;
}


// ===== FUN_fffed24e @ fffed24e (91 bytes)

void FUN_fffed24e(char param_1)

{
  DAT_0001b3c3 = 1;
  swtimer_start(0x22,0x32);
  if (param_1 == '\x01') {
    DAT_00020b3c = 2;
  }
  else if (param_1 == '\x02') {
    DAT_00020b3c = 3;
  }
  else {
    DAT_00020b3c = 1;
  }
  if (DAT_00020f0c != '\x01') {
    return;
  }
  FUN_fffed206(0);
  return;
}


// ===== FUN_fffed2a9 @ fffed2a9 (200 bytes)

void FUN_fffed2a9(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  if (DAT_00020b3d == '\0') {
    FUN_fffed206(0);
    return;
  }
  if ((DAT_00020b3c == '\0') || (iVar3 = FUN_fffed61e(), iVar3 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    beep_request(3);
    FUN_fffed206(0);
    return;
  }
  if (DAT_00020b3e == '\x01') {
    DAT_00020b3c = 2;
    send_a_set(1);
    send_b_set(1);
    return;
  }
  if (DAT_00020b3e != '\x02') {
    if (DAT_00020b3e != '\x03') {
      DAT_00020b3c = 0;
      return;
    }
    DAT_00020b3c = 1;
    bVar2 = swtimer_expired(0x20);
    if (bVar2 != 0) {
      DAT_00020b3e = 0;
      return;
    }
    return;
  }
  DAT_00020b3c = 3;
  send_a_set(1);
  send_b_set(1);
  return;
}


// ===== FUN_fffed371 @ fffed371 (40 bytes)

void FUN_fffed371(void)

{
  DAT_0001b3be = 1;
  DAT_0001b3c1 = 0;
  DAT_00025d10 = 0x437f0000;
  DAT_0001b3c2 = 0;
  return;
}


// ===== FUN_fffed399 @ fffed399 (104 bytes)

void FUN_fffed399(void)

{
  bool bVar1;
  int iVar2;
  
  if ((DAT_00020b3c == '\0') || (iVar2 = FUN_fffed61e(), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    beep_request(3);
    DAT_0001b3be = '\x05';
  }
  if (DAT_0001b3be == '\x05') {
    FUN_fffed5e4();
    return;
  }
  if (DAT_0001b3be == '\x02') {
    FUN_fffed48f();
    return;
  }
  if (DAT_0001b3be != '\x03') {
    if (DAT_0001b3be == '\x04') {
      FUN_fffed5c5();
      return;
    }
    if (DAT_0001b3be == '\x01') {
      FUN_fffed401();
      return;
    }
    return;
  }
  FUN_fffed50f();
  return;
}


// ===== FUN_fffed401 @ fffed401 (142 bytes)

void FUN_fffed401(void)

{
  int iVar1;
  
  DAT_00025d0c = DAT_00020f50;
  if (DAT_0001b3bf == '\0') {
    if (DAT_0001b3c0 == '\0') {
      DAT_00020b3c = 3;
    }
    else {
      DAT_00020b3c = 2;
    }
    swtimer_start(0x20,60000);
  }
  else {
    iVar1 = FUN_fffb3371(DAT_00020f50);
    if (iVar1 == 9) {
      DAT_0001b3c0 = '\x01';
      DAT_00020b3c = 2;
      swtimer_start(0x20,5000);
    }
    else {
      swtimer_start(0x20,1);
    }
  }
  DAT_0001b3be = 2;
  return;
}


// ===== FUN_fffed48f @ fffed48f (128 bytes)

void FUN_fffed48f(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  if (DAT_0001b3bf == '\0') {
    FUN_fffed5ea();
  }
  else if (DAT_00025d08 < DAT_00025d0c) {
    DAT_0001b3c0 = 1;
    DAT_00020b3c = 2;
  }
  else {
    DAT_0001b3c0 = 0;
    DAT_00020b3c = 3;
  }
  DAT_0001b3bf = 0;
  DAT_00020b2d = 1;
  swtimer_start(0x20,60000);
  DAT_0001b3be = 3;
  return;
}


// ===== FUN_fffed50f @ fffed50f (182 bytes)

void FUN_fffed50f(void)

{
  byte bVar1;
  float fVar2;
  uint uVar3;
  
  uVar3 = (uint)SBORROW4((int)&stack0x00000000,4) << 3;
  fVar2 = (float)FUN_fffb6e4e();
  if (2.0 < fVar2 == (bool)((byte)(uVar3 >> 3) & 1)) {
    if (DAT_00025d10 < fVar2) {
      DAT_0001b3c2 = DAT_0001b3c2 + 1;
    }
    else {
      DAT_0001b3c2 = 0;
    }
  }
  else {
    DAT_0001b3c2 = 0;
  }
  DAT_00025d10 = fVar2;
  if (2 < DAT_0001b3c2) {
    DAT_00020b3c = 1;
    swtimer_start(0x20,2000);
    DAT_0001b3be = 4;
    return;
  }
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  if (DAT_0001b3c1 == '\0') {
    DAT_0001b3c1 = 1;
    FUN_fffed5ea();
    swtimer_start(0x20,60000);
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5c5 @ fffed5c5 (31 bytes)

void FUN_fffed5c5(void)

{
  byte bVar1;
  
  DAT_0001b3bf = 1;
  bVar1 = swtimer_expired(0x20);
  if (bVar1 == 0) {
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5e4 @ fffed5e4 (6 bytes)

void FUN_fffed5e4(void)

{
  FUN_fffed206(0);
  return;
}


// ===== FUN_fffed5ea @ fffed5ea (52 bytes)

void FUN_fffed5ea(void)

{
  if (DAT_0001b3c0 != '\0') {
    DAT_0001b3c0 = 0;
    DAT_00020b3c = 3;
    return;
  }
  DAT_0001b3c0 = 1;
  DAT_00020b3c = 2;
  return;
}


// ===== FUN_fffed61e @ fffed61e (12 bytes)

bool FUN_fffed61e(void)

{
  bool bVar1;
  
  bVar1 = atas_det();
  return bVar1;
}


// ===== FUN_fffed62a @ fffed62a (203 bytes)

void FUN_fffed62a(void)

{
  bool bVar1;
  byte bVar2;
  
  DAT_00020b71 = 0;
  bVar2 = tunlin_port_mode();
  if (bVar2 == 0) {
    if (DAT_00020b3f == '\x05') {
      DAT_00020b71 = 1;
      if ((DAT_00020b40 == '\x02') && (bVar2 = blink_phase(0), bVar2 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b71 = 0;
      }
    }
    switch(DAT_0001b3c8) {
    case 1:
    case 4:
      FUN_fffed72b();
      return;
    case 2:
    case 5:
      FUN_fffed753();
      return;
    case 3:
      FUN_fffed796();
      return;
    case 6:
      FUN_fffed7f3();
      return;
    case 7:
      FUN_fffed8ab();
      return;
    case 8:
      FUN_fffed8fc();
      return;
    case 9:
      FUN_fffed934();
      return;
    case 10:
      FUN_fffed983();
      return;
    case 0xb:
      FUN_fffed9b3();
      return;
    case 0xc:
      FUN_fffeda3b();
      return;
    case 0xd:
      FUN_fffeda96();
      return;
    case 0xe:
      FUN_fffedab0();
      return;
    case 0xf:
      FUN_fffedac0();
      return;
    case 0x10:
      FUN_fffedae4();
      return;
    default:
      FUN_fffed704();
      return;
    }
  }
  return;
}


// ===== FUN_fffed6f5 @ fffed6f5 (15 bytes)

undefined1 FUN_fffed6f5(void)

{
  return DAT_0001b5aa;
}


// ===== FUN_fffed704 @ fffed704 (39 bytes)

void FUN_fffed704(void)

{
  DAT_0001b3c7 = 0;
  DAT_00020b40 = 0;
  DAT_00020b3f = 0;
  DAT_0001b3c8 = 1;
  return;
}


// ===== FUN_fffed72b @ fffed72b (40 bytes)

void FUN_fffed72b(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x24);
  if ((bVar1 != 0) && (FUN_fffedbc9(), DAT_0001b3c7 == '\0')) {
    DAT_0001b3c8 = DAT_0001b3c8 + '\x01';
    return;
  }
  return;
}


// ===== FUN_fffed753 @ fffed753 (67 bytes)

void FUN_fffed753(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(7);
  if (bVar1 == 1) {
    DAT_0001b5aa = 0;
    DAT_0001b3c8 = 0;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3cb != '\x01') {
    return;
  }
  DAT_0001b5aa = 1;
  DAT_0001b3c8 = DAT_0001b3c8 + '\x01';
  return;
}


// ===== FUN_fffed796 @ fffed796 (93 bytes)

void FUN_fffed796(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x25);
  if (bVar1 != 0) {
    if (DAT_0001b5ab == '\x01') {
      FUN_fffedb87();
    }
    else if (DAT_0001b5ab == '\0') {
      FUN_fffedba8();
    }
    else {
      FUN_fffedb54();
    }
    if (DAT_0001b3c7 == '\0') {
      if (DAT_0001b5ab == '\x02') {
        DAT_0001b5ab = 0;
        DAT_0001b3c8 = 4;
        return;
      }
      DAT_0001b5ab = DAT_0001b5ab + '\x01';
      return;
    }
  }
  return;
}


// ===== FUN_fffed7f3 @ fffed7f3 (184 bytes)

/* WARNING: Removing unreachable block (ram,0xfffed887) */
/* WARNING: Removing unreachable block (ram,0xfffed894) */

void FUN_fffed7f3(void)

{
  byte bVar1;
  
  if (DAT_00020b40 == '\x01') {
    DAT_0001b3c8 = 7;
  }
  else if (DAT_00020b3f == '\x04') {
    FUN_fffedb42();
    if (DAT_0001b3c7 == '\0') {
      DAT_0001b3c8 = 0x10;
    }
  }
  else if (DAT_00020b3f == '\x06') {
    FUN_fffedb54();
    if (DAT_0001b3c7 == '\0') {
      DAT_0001b3c8 = 0x10;
    }
  }
  else {
    bVar1 = swtimer_expired(0x24);
    if (bVar1 == 1) {
      DAT_0001b3c8 = 4;
    }
  }
  if ((DAT_00020b3f == '\x05') && (DAT_00025d18 / 10000 != (DAT_00020f50 / 10000 & 0xff))) {
    DAT_00020b3f = 4;
    return;
  }
  return;
}


// ===== FUN_fffed8ab @ fffed8ab (81 bytes)

void FUN_fffed8ab(void)

{
  bool bVar1;
  
  bVar1 = tx_freq_allowed(DAT_00020f50);
  if (!bVar1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  DAT_00020b40 = 2;
  DAT_00020b2d = 1;
  FUN_fffedb54();
  if (DAT_0001b3c7 != '\0') {
    return;
  }
  DAT_0001b3c8 = 8;
  return;
}


// ===== FUN_fffed8fc @ fffed8fc (56 bytes)

void FUN_fffed8fc(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(7);
  if (bVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3ca != '\x01') {
    return;
  }
  swtimer_start(0x26,0xfa);
  DAT_0001b3c8 = 9;
  return;
}


// ===== FUN_fffed934 @ fffed934 (79 bytes)

void FUN_fffed934(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x26);
  if (bVar1 != 0) {
    DAT_00025d14 = FUN_fffb6e5c();
    send_a_set(0);
    send_b_set(0);
    swtimer_start(0x26,5);
    DAT_0001b3c8 = 10;
    return;
  }
  if (DAT_00020b6b != '\0') {
    return;
  }
  swtimer_start(0x26,0xfa);
  return;
}


// ===== FUN_fffed983 @ fffed983 (48 bytes)

void FUN_fffed983(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x26);
  if ((bVar1 != 0) && (FUN_fffedb75(), DAT_0001b3c7 == '\0')) {
    swtimer_start(0x26,10000);
    DAT_0001b3c8 = 0xb;
    return;
  }
  return;
}


// ===== FUN_fffed9b3 @ fffed9b3 (136 bytes)

void FUN_fffed9b3(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x26);
  if (bVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  if (DAT_00020b3f == '\x06') {
    DAT_0001b3c8 = 0xf;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3c9 == '\x01') {
    send_a_set(1);
    send_b_set(1);
    DAT_00020b3f = '\x05';
  }
  if (DAT_0001b3ca == '\x01') {
    swtimer_start(0x26,0xfa);
    DAT_0001b3c8 = 0xc;
    return;
  }
  if (DAT_0001b3cb == '\x01') {
    DAT_0001b3c8 = 0xe;
    return;
  }
  return;
}


// ===== FUN_fffeda3b @ fffeda3b (91 bytes)

void FUN_fffeda3b(void)

{
  byte bVar1;
  float fVar2;
  
  bVar1 = swtimer_expired(0x26);
  if (bVar1 == 0) {
    if (DAT_00020b6b != '\0') {
      return;
    }
    swtimer_start(0x26,0xfa);
    return;
  }
  fVar2 = (float)FUN_fffb6e5c();
  if (DAT_00025d14 <= fVar2) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  DAT_00020b2d = 0;
  DAT_0001b3c8 = 0xd;
  return;
}


// ===== FUN_fffeda96 @ fffeda96 (26 bytes)

void FUN_fffeda96(void)

{
  DAT_00020b40 = 0;
  DAT_0001b3c8 = 4;
  FUN_fffec537(1);
  return;
}


// ===== FUN_fffedab0 @ fffedab0 (16 bytes)

void FUN_fffedab0(void)

{
  beep_request(3);
  DAT_0001b3c8 = 0xf;
  return;
}


// ===== FUN_fffedac0 @ fffedac0 (36 bytes)

void FUN_fffedac0(void)

{
  FUN_fffedb54();
  if (DAT_0001b3c7 != '\0') {
    return;
  }
  DAT_00020b2d = 0;
  DAT_0001b3c8 = 0;
  return;
}


// ===== FUN_fffedae4 @ fffedae4 (94 bytes)

void FUN_fffedae4(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(7);
  if (bVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3ca == '\x01') {
    if (DAT_00020b3f == '\x04') {
      DAT_00020b3f = '\x05';
    }
    else if (DAT_00020b3f == '\x06') {
      DAT_00020b3f = '\0';
    }
    DAT_0001b3c8 = 6;
    return;
  }
  return;
}


// ===== FUN_fffedb42 @ fffedb42 (18 bytes)

void FUN_fffedb42(void)

{
  DAT_0001b3c4 = 0xf0;
  FUN_fffedbea();
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb54 @ fffedb54 (33 bytes)

void FUN_fffedb54(void)

{
  DAT_0001b3c4 = 0xf1;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb75 @ fffedb75 (18 bytes)

void FUN_fffedb75(void)

{
  DAT_0001b3c4 = 0xf2;
  FUN_fffedbea();
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb87 @ fffedb87 (33 bytes)

void FUN_fffedb87(void)

{
  DAT_0001b3c4 = 0xe0;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 1;
  FUN_fffedc27(3);
  return;
}

