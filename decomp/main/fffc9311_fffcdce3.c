// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== sci6_iic_condition @ fffc9311 (9 bytes)

/* Writes SIMR3 (start/stop condition generation) */

void sci6_iic_condition(void)

{
  DAT_0008a0cb = 0x54;
  return;
}


// ===== FUN_fffc93a3 @ fffc93a3 (1 bytes)

void FUN_fffc93a3(void)

{
  return;
}


// ===== r_sci6_iic_txi @ fffc93a4 (75 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc93e9) */
/* WARNING: Removing unreachable block (ram,0xfffc93a4) */
/* WARNING: Removing unreachable block (ram,0xfffc93a6) */
/* WARNING: Removing unreachable block (ram,0xfffc93eb) */

undefined4 r_sci6_iic_txi(undefined4 param_1)

{
  undefined1 uVar1;
  byte bVar2;
  
  bVar2 = DAT_0008a0cc;
  if ((bVar2 & 1) == 1) {
    uVar1 = DAT_0008a0c5;
    *DAT_00021050 = uVar1;
    DAT_00021050 = DAT_00021050 + 1;
    DAT_0001fa44 = DAT_0001fa44 + 1;
  }
  DAT_00012236 = 0;
  sci6_iic_condition();
  return param_1;
}


// ===== r_sci6_iic_rxi @ fffc9467 (328 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc94bb) */
/* WARNING: Removing unreachable block (ram,0xfffc94d2) */
/* WARNING: Removing unreachable block (ram,0xfffc958c) */
/* WARNING: Removing unreachable block (ram,0xfffc95a9) */
/* WARNING: Removing unreachable block (ram,0xfffc95a3) */
/* WARNING: Removing unreachable block (ram,0xfffc9469) */
/* WARNING: Removing unreachable block (ram,0xfffc9467) */
/* WARNING: Removing unreachable block (ram,0xfffc95ab) */
/* WARNING: Removing unreachable block (ram,0xfffc958e) */
/* WARNING: Removing unreachable block (ram,0xfffc94d0) */
/* WARNING: Removing unreachable block (ram,0xfffc94bd) */
/* WARNING: Removing unreachable block (ram,0xfffc95a1) */

undefined4 r_sci6_iic_rxi(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = DAT_0008a0cc;
  if ((bVar1 & 1) != 0) {
    DAT_00012236 = 0;
    sci6_iic_condition();
    return param_1;
  }
  if (DAT_00012235 == -0x80) {
    if (DAT_0001fa42 != 0) {
      DAT_0008a0c3 = *DAT_0002104c;
      DAT_0002104c = DAT_0002104c + 1;
      DAT_0001fa42 = DAT_0001fa42 + -1;
      return param_1;
    }
    DAT_00012236 = 0;
    sci6_iic_condition();
    return param_1;
  }
  if (DAT_00012235 == '\0') {
    bVar1 = DAT_0008a0ca;
    if ((bVar1 & 0x20) == 0) {
      if (DAT_0001fa44 < DAT_0001fa46) {
        uVar2 = DAT_0008a0c5;
        *DAT_00021050 = uVar2;
        DAT_00021050 = DAT_00021050 + 1;
        DAT_0001fa44 = DAT_0001fa44 + 1;
      }
    }
    else {
      uVar2 = DAT_0008a0c5;
    }
    if (DAT_0001fa44 == 0) {
      if (DAT_0001fa46 == 1) {
        bVar1 = DAT_0008a0ca;
        DAT_0008a0ca = bVar1 | 0x20;
      }
      else {
        bVar1 = DAT_0008a0ca;
        DAT_0008a0ca = bVar1 & 0xdf;
        bVar1 = DAT_0008a0c2;
        DAT_0008a0c2 = bVar1 | 0x40;
      }
    }
    else if (DAT_0001fa46 == (byte)((char)DAT_0001fa44 + 1)) {
      bVar1 = DAT_0008a0ca;
      DAT_0008a0ca = bVar1 | 0x20;
    }
    DAT_0008a0c3 = 0xff;
    return param_1;
  }
  return param_1;
}


// ===== FUN_fffc95af @ fffc95af (1 bytes)

void FUN_fffc95af(void)

{
  return;
}


// ===== FUN_fffc95b0 @ fffc95b0 (1 bytes)

void FUN_fffc95b0(void)

{
  return;
}


// ===== R_SCI7_Create @ fffc95b1 (163 bytes)

/* SCI7 init ("C4" peripheral link, probably the RT685 DSP) */

void R_SCI7_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xfeffffff;
  bVar2 = DAT_00087362;
  DAT_00087362 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087363;
  DAT_00087363 = bVar2 & 0xfa | 10;
  DAT_0008a0e2 = 0;
  DAT_0008a0e2 = 0;
  bVar2 = DAT_0008a0e9;
  DAT_0008a0e9 = bVar2 & 0xfe;
  DAT_0008a0ed = 0;
  DAT_0008a0e0 = 0;
  DAT_0008a0e6 = 0x72;
  DAT_0008a0e7 = 0;
  DAT_0008a0e1 = 0xc2;
  DAT_0008c18a = 10;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 | 4;
  DAT_0008c188 = 10;
  bVar2 = DAT_0008c029;
  DAT_0008c029 = bVar2 | 1;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 | 1;
  FUN_fffc979f();
  return;
}


// ===== FUN_fffc979f @ fffc979f (1 bytes)

void FUN_fffc979f(void)

{
  return;
}


// ===== r_sci7_transmit_interrupt @ fffc97a0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc97d6) */
/* WARNING: Removing unreachable block (ram,0xfffc97a0) */
/* WARNING: Removing unreachable block (ram,0xfffc97e8) */

undefined4 r_sci7_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001fa48 == 0) {
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a0e3 = *DAT_00021054;
  DAT_00021054 = DAT_00021054 + 1;
  DAT_0001fa48 = DAT_0001fa48 + -1;
  return param_1;
}


// ===== r_sci7_receive_interrupt @ fffc9811 (111 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc9874) */
/* WARNING: Removing unreachable block (ram,0xfffc987c) */
/* WARNING: Removing unreachable block (ram,0xfffc987a) */
/* WARNING: Removing unreachable block (ram,0xfffc9811) */
/* WARNING: Removing unreachable block (ram,0xfffc9813) */
/* WARNING: Removing unreachable block (ram,0xfffc9876) */

undefined4 r_sci7_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001fa4a < DAT_0001fa4c) {
    uVar2 = DAT_0008a0e5;
    *DAT_00021058 = uVar2;
    DAT_00021058 = DAT_00021058 + 1;
    DAT_0001fa4a = DAT_0001fa4a + 1;
  }
  if (DAT_0001fa4c <= DAT_0001fa4a) {
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0xbf;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0xef;
    FUN_fffc98a8();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fffc98a7 @ fffc98a7 (1 bytes)

void FUN_fffc98a7(void)

{
  return;
}


// ===== FUN_fffc98a8 @ fffc98a8 (1 bytes)

void FUN_fffc98a8(void)

{
  return;
}


// ===== FUN_fffc98a9 @ fffc98a9 (1 bytes)

void FUN_fffc98a9(void)

{
  return;
}


// ===== FUN_fffc98aa @ fffc98aa (9 bytes)

void FUN_fffc98aa(void)

{
  FUN_fffd405e();
  FUN_fffd4ff1();
  return;
}


// ===== FUN_fffc98b3 @ fffc98b3 (14 bytes)

void FUN_fffc98b3(void)

{
  PTR_DAT_00025d60[0x3ff] = 0;
  return;
}


// ===== FUN_fffc98c1 @ fffc98c1 (56 bytes)

undefined1 FUN_fffc98c1(void)

{
  undefined1 uVar1;
  
  if ((PTR_DAT_00025d60[0x41f] == '\x04') && (DAT_00015e04 == '\x02')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffc98f9 @ fffc98f9 (626 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffc99cf) */
/* WARNING: Removing unreachable block (ram,0xfffc98f9) */
/* WARNING: Removing unreachable block (ram,0xfffc99f2) */
/* WARNING: Removing unreachable block (ram,0xfffc9b68) */

ushort FUN_fffc98f9(int param_1,ushort param_2)

{
  undefined1 uVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  byte bStack_1e;
  byte bStack_1d;
  ushort uStack_14;
  byte bStack_11;
  byte bStack_10;
  ushort local_e;
  byte bStack_b;
  ushort uStack_a;
  
  uVar1 = FUN_fffc98c1();
  *(undefined1 *)((uint)param_2 + param_1) = uVar1;
  DAT_0001226e = (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]];
  PTR_DAT_00025d60[0x420] = (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]];
  uVar1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  bStack_b = FUN_fffd4841(uVar1);
  if (bStack_b == 0) {
    local_e = 0;
  }
  else {
    *(byte *)((uint)(ushort)(param_2 + 1) + param_1) = bStack_b;
    uVar1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
    pbVar3 = (byte *)FUN_fffd4ada(uVar1);
    DAT_0001226f = *pbVar3;
    DAT_00012270 = pbVar3[1];
    *(byte *)((uint)(ushort)(param_2 + 2) + param_1) = DAT_00012270;
    if (5 < bStack_b) {
      bStack_b = 5;
    }
    *(byte *)((uint)(ushort)(param_2 + 3) + param_1) = bStack_b << 4 | PTR_DAT_00025d60[0x3ff];
    *(byte *)((uint)(ushort)(param_2 + 4) + param_1) = DAT_0001226e << 4 | DAT_0001226f;
    pcVar5 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
             + (uint)(byte)PTR_DAT_00025d60[0x41f] * 0x14;
    pcVar4 = (char *)(param_1 + (uint)(ushort)(param_2 + 5));
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pcVar4 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    uStack_a = param_2 + 0x19;
    uVar1 = PTR_DAT_00025d60[0x41f];
    bStack_11 = 0;
    cVar2 = FUN_fffd52df(uVar1);
    if (cVar2 == '\0') {
      local_e = 0;
    }
    else {
      bStack_10 = bStack_1d;
      for (uStack_14 = (ushort)bStack_1d; uStack_14 <= bStack_1e; uStack_14 = uStack_14 + 1) {
        cVar2 = FUN_fffd45a8(uVar1,bStack_10);
        if (cVar2 == '\x01') {
          pcVar5 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_10 * 0xd + 0x78;
          pcVar4 = (char *)(param_1 + (uint)uStack_a);
          for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
            *pcVar4 = *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          }
          uStack_a = uStack_a + 0xd;
          bStack_11 = bStack_11 + 1;
        }
        bStack_10 = bStack_10 + 1;
      }
      uStack_a = (8 - (ushort)bStack_11) * 0xd + uStack_a;
      FUN_fffd49f4(uVar1,DAT_0001226e);
      for (local_e = 0; local_e < bStack_b; local_e = local_e + 1) {
        DAT_00012271 = 0;
        if ((PTR_DAT_00025d60[0x3ff] == '\x03') && (local_e == DAT_0001226f)) {
          DAT_00012271 = 1;
        }
        cVar2 = FUN_fffd47ea();
        if (cVar2 == '\0') {
          return 0;
        }
        iVar6 = (uint)uStack_a + param_1;
        *(undefined4 *)(iVar6 + 0x28) = 0x20202020;
        *(undefined4 *)(iVar6 + 0x24) = 0x20202020;
        *(undefined4 *)(iVar6 + 0x20) = 0x20202020;
        *(undefined4 *)(iVar6 + 0x1c) = 0x20202020;
        *(undefined4 *)(iVar6 + 0x18) = 0x20202020;
        *(undefined1 *)(iVar6 + 0x2c) = 0x20;
        FUN_fffd49a0();
        uStack_a = uStack_a + 0x2d;
        DAT_00012270 = DAT_00012270 + 1;
      }
    }
  }
  return local_e;
}


// ===== FUN_fffc9b83 @ fffc9b83 (95 bytes)

void FUN_fffc9b83(byte *param_1,char param_2)

{
  if (param_2 == '\0') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffc9c29 @ fffc9c29 (130 bytes)

void FUN_fffc9c29(byte *param_1,byte param_2,short param_3)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = (ushort)param_2 * 0x14 + 0x14;
  if (sVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  bVar1 = FUN_fff9c843(sVar2,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[0] = 0x6d;
  param_1[1] = 0x73;
  param_1[2] = 0x65;
  param_1[3] = 99;
  return;
}


// ===== FUN_fffc9cee @ fffc9cee (151 bytes)

void FUN_fffc9cee(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = FUN_fff9c843(uVar2 * 0x32 + 0x32,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== FUN_fffc9d9a @ fffc9d9a (119 bytes)

void FUN_fffc9d9a(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffc9e27 @ fffc9e27 (152 bytes)

void FUN_fffc9e27(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = FUN_fff9c843(uVar2 * 0x32 + 0x28a,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== FUN_fffc9ed4 @ fffc9ed4 (119 bytes)

void FUN_fffc9ed4(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffc9f61 @ fffc9f61 (98 bytes)

void FUN_fffc9f61(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffca06d @ fffca06d (163 bytes)

void FUN_fffca06d(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 10;
  param_1[2] = 0;
  local_5 = param_2;
  if (DAT_00012272 == '\0') {
    if (5 < param_2) {
      local_5 = 0;
    }
    pbVar1 = (byte *)(
                     "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                     + (uint)local_5 * 0x15 + 0x201);
    param_1 = param_1 + 0x18;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *pbVar1;
      param_1 = param_1 + 1;
      pbVar1 = pbVar1 + 1;
    }
    return;
  }
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x27f);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffca125 @ fffca125 (119 bytes)

void FUN_fffca125(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 3;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x2e8);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffca1b2 @ fffca1b2 (98 bytes)

void FUN_fffca1b2(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffca22a @ fffca22a (98 bytes)

void FUN_fffca22a(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffca2a1 @ fffca2a1 (119 bytes)

void FUN_fffca2a1(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x33c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffca3ab @ fffca3ab (119 bytes)

void FUN_fffca3ab(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  local_5 = param_2;
  if (2 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x72c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcabc2 @ fffcabc2 (120 bytes)

void FUN_fffcabc2(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  local_5 = param_2;
  if (0x14 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x573);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcb34b @ fffcb34b (119 bytes)

void FUN_fffcb34b(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcb672 @ fffcb672 (119 bytes)

void FUN_fffcb672(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xf36);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcb9ba @ fffcb9ba (119 bytes)

void FUN_fffcb9ba(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  local_5 = param_2;
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1047);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcba46 @ fffcba46 (119 bytes)

void FUN_fffcba46(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x10b0);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcc04a @ fffcc04a (120 bytes)

void FUN_fffcc04a(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  local_5 = param_2;
  if (0x14 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x123f);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fffcc4af @ fffcc4af (167 bytes)

void FUN_fffcc4af(byte *param_1,short param_2,byte param_3,byte param_4)

{
  byte bVar1;
  ushort local_c;
  
  if (param_3 == param_4) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (param_3 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  local_c = ((ushort)param_3 * 100 + param_2) - 100;
  if (0xc80 < local_c) {
    local_c = 0xc80;
  }
  bVar1 = FUN_fff9c843(local_c,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== FUN_fffcc56b @ fffcc56b (99 bytes)

void FUN_fffcc56b(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffcc5e3 @ fffcc5e3 (98 bytes)

void FUN_fffcc5e3(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== FUN_fffcc7dc @ fffcc7dc (116 bytes)

void FUN_fffcc7dc(byte *param_1,char param_2,char param_3)

{
  byte bVar1;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  bVar1 = FUN_fff9c6f0(param_2,param_1 + 0x18);
  param_1[bVar1 + 0x18] = 0x57;
  return;
}


// ===== FUN_fffcd54d @ fffcd54d (136 bytes)

void FUN_fffcd54d(void)

{
  if (PTR_DAT_00025d60[0x3ff] == '\x03') {
    PTR_DAT_00025d60[0x40a] = 1;
    return;
  }
  PTR_DAT_00025d60[0xb3] = PTR_DAT_00025d60[0xae];
  if (PTR_DAT_00025d60[0xae] == '\0') {
    PTR_DAT_00025d60[0xb3] = 1;
  }
  PTR_DAT_00025d60[0xb4] = PTR_DAT_00025d60[0xaf];
  if (PTR_DAT_00025d60[0xaf] == '\0') {
    PTR_DAT_00025d60[0xb4] = 1;
  }
  PTR_DAT_00025d60[0xb2] = PTR_DAT_00025d60[0xad];
  PTR_DAT_00025d60[0xb5] = PTR_DAT_00025d60[0xb0];
  PTR_DAT_00025d60[0xb6] = PTR_DAT_00025d60[0xb1];
  return;
}


// ===== FUN_fffcd803 @ fffcd803 (98 bytes)

void FUN_fffcd803(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x20202020;
  *(undefined4 *)(param_1 + 0x24) = 0x20202020;
  *(undefined4 *)(param_1 + 0x20) = 0x20202020;
  *(undefined4 *)(param_1 + 0x1c) = 0x20202020;
  *(undefined4 *)(param_1 + 0x18) = 0x20202020;
  param_1[0x2c] = 0x20;
  *(undefined4 *)(param_1 + 0x18) = 0x454e4f44;
  return;
}


// ===== FUN_fffcd999 @ fffcd999 (184 bytes)

undefined1 FUN_fffcd999(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uStack_4;
  
  bVar2 = param_1 - 1;
  bVar3 = FUN_fffd48d1(PTR_DAT_00025d60[0x41f]);
  if (bVar2 < bVar3) {
    (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = bVar2;
    PTR_DAT_00025d60[0x420] = bVar2;
    if ((PTR_DAT_00025d60[0x41f] == '\x04') && (bVar2 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_DAT_00025d60[0x3ff] == '\x02') {
        PTR_DAT_00025d60[0x3ff] = 0;
      }
      uStack_4 = 1;
    }
    else {
      if (PTR_DAT_00025d60[0x41f] != '\x05') {
        bVar2 = DAT_00009bc9;
      }
      DAT_00009bc9 = bVar2;
      PTR_DAT_00025d60[0x3ff] = 2;
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffcda51 @ fffcda51 (213 bytes)

undefined1 FUN_fffcda51(char param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined1 uStack_9;
  
  cVar2 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  if (cVar2 == '\x12') {
    uStack_9 = 0;
  }
  else {
    pcVar3 = (char *)FUN_fffd4ada(cVar2);
    *pcVar3 = param_1;
    if (DAT_0001b4fc == '\0') {
      DAT_00015dfd = PTR_DAT_00025d60[0x41f];
      DAT_00015dff = *pcVar3 + pcVar3[1];
      if ((DAT_00015dfd == '\x04') && (cVar2 == '\x11')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (DAT_00015dff == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        PTR_s_V01_12_0001b4fd._0_1_ = 1;
      }
      DAT_00015dfe = cVar2;
      iVar4 = FUN_fffcdb6b(&DAT_00015dfd);
      if (iVar4 == 1) {
        DAT_0001b4fc = '\x01';
      }
      else {
        FUN_fffcdc1f();
      }
    }
    uStack_9 = 1;
  }
  return uStack_9;
}


// ===== FUN_fffcdb26 @ fffcdb26 (69 bytes)

void FUN_fffcdb26(void)

{
  int iVar1;
  
  if (DAT_0001b4fc == '\x01') {
    DAT_0001b4fc = 2;
    FUN_fffb237a(0x31,200);
    return;
  }
  if ((DAT_0001b4fc == '\x02') && (iVar1 = FUN_fffb23f3(0x31), iVar1 == 1)) {
    DAT_0001b4fc = 0;
    FUN_fffcdc1f();
    return;
  }
  return;
}


// ===== FUN_fffcdb6b @ fffcdb6b (77 bytes)

undefined1 FUN_fffcdb6b(int param_1)

{
  bool bVar1;
  undefined1 local_6;
  
  if ((*(char *)(param_1 + 1) == '\x14') || (*(char *)(param_1 + 1) == '\x11')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = 1;
  }
  else {
    if ((*(char *)(param_1 + 1) == '\f') && (*(char *)(param_1 + 2) == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_6 = 1;
    }
    else {
      local_6 = 0;
    }
  }
  return local_6;
}


// ===== FUN_fffcdbb8 @ fffcdbb8 (103 bytes)

void FUN_fffcdbb8(void)

{
  if (PTR_DAT_00025d60[0x40a] != '\x01') {
    return;
  }
  PTR_DAT_00025d60[0x40a] = 0;
  PTR_DAT_00025d60[0xae] = PTR_DAT_00025d60[0xb3];
  PTR_DAT_00025d60[0xaf] = PTR_DAT_00025d60[0xb4];
  PTR_DAT_00025d60[0xad] = PTR_DAT_00025d60[0xb2];
  PTR_DAT_00025d60[0xb0] = PTR_DAT_00025d60[0xb5];
  PTR_DAT_00025d60[0xb1] = PTR_DAT_00025d60[0xb6];
  PTR_DAT_00025d60[0x8d] = 1;
  return;
}


// ===== FUN_fffcdc1f @ fffcdc1f (89 bytes)

void FUN_fffcdc1f(void)

{
  char *pcVar1;
  undefined1 uStack_5;
  undefined1 uStack_4;
  char cStack_3;
  char cStack_2;
  undefined1 uStack_1;
  
  PTR_DAT_00025d60[0x3ff] = 3;
  uStack_1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar1 = (char *)FUN_fffd4ada(uStack_1);
  cStack_3 = *pcVar1 + pcVar1[1];
  uStack_5 = PTR_DAT_00025d60[0x41f];
  uStack_4 = uStack_1;
  cStack_2 = cStack_3;
  FUN_fffd49da(&uStack_5);
  FUN_fffc8f30(3000);
  return;
}


// ===== FUN_fffcdc79 @ fffcdc79 (106 bytes)

undefined1 FUN_fffcdc79(void)

{
  undefined1 uVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 uStack_9;
  
  uVar1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar3 = (char *)FUN_fffd4ada(uVar1);
  if (pcVar3 == (char *)0x0) {
    uStack_9 = 0;
  }
  else {
    bVar2 = FUN_fffd4841(uVar1);
    if (bVar2 < 5) {
      uStack_9 = 0;
    }
    else if (pcVar3[1] == '\0') {
      uStack_9 = 0;
    }
    else {
      pcVar3[1] = pcVar3[1] + -1;
      if (*pcVar3 != '\x04') {
        *pcVar3 = *pcVar3 + '\x01';
      }
      uStack_9 = FUN_fffcdce3();
    }
  }
  return uStack_9;
}


// ===== FUN_fffcdce3 @ fffcdce3 (27 bytes)

undefined1 FUN_fffcdce3(void)

{
  if (PTR_DAT_00025d60[0x3ff] == '\x03') {
    FUN_fffcdcfe();
  }
  return 1;
}

