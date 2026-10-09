// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd4ff1 @ fffd4ff1 (13 bytes)

void FUN_fffd4ff1(void)

{
  DAT_0001fa4e = 0;
  FUN_fffd4c30();
  return;
}


// ===== FUN_fffd4ffe @ fffd4ffe (78 bytes)

undefined1 FUN_fffd4ffe(int param_1,undefined1 *param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 local_45;
  undefined1 auStack_1c [18];
  char cStack_a;
  undefined1 *local_8;
  int local_4;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_45 = 0;
  }
  else {
    local_8 = param_2;
    local_4 = param_1;
    cStack_a = FUN_fffd4795(param_1);
    if (cStack_a == '\0') {
      local_45 = 0;
    }
    else {
      puVar2 = auStack_1c;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *local_8 = *puVar2;
        local_8 = local_8 + 1;
        puVar2 = puVar2 + 1;
      }
      local_45 = 1;
    }
  }
  return local_45;
}


// ===== FUN_fffd504c @ fffd504c (343 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd51a0) */
/* WARNING: Removing unreachable block (ram,0xfffd517b) */
/* WARNING: Removing unreachable block (ram,0xfffd5171) */
/* WARNING: Removing unreachable block (ram,0xfffd510b) */
/* WARNING: Removing unreachable block (ram,0xfffd5107) */
/* WARNING: Removing unreachable block (ram,0xfffd5111) */
/* WARNING: Removing unreachable block (ram,0xfffd5175) */
/* WARNING: Removing unreachable block (ram,0xfffd50f0) */

undefined1 FUN_fffd504c(int param_1,char param_2,ushort *param_3)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  undefined1 local_55;
  byte *pbStack_28;
  char cStack_23;
  char cStack_1f;
  
  if ((param_1 == 0) || (param_3 == (ushort *)0x0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_55 = 0;
  }
  else {
    if ((param_2 == '\0') || (param_2 == '\x01')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_55 = 0;
    }
    else {
      cVar3 = FUN_fffd4795(param_1);
      if (cVar3 == '\0') {
        local_55 = 0;
      }
      else {
        if (cStack_1f == '\0') {
          uRam00000000 = 1;
        }
        if (param_2 == '\0') {
          if (cStack_1f == '\0') {
            return 0;
          }
          if (cStack_23 == '\0') {
            *param_3 = (ushort)*pbStack_28;
          }
          else {
            *param_3 = CONCAT11(*pbStack_28,pbStack_28[1]);
          }
        }
        else {
          if (cStack_1f == '\0') {
            return 0;
          }
          if (cStack_23 == '\0') {
            *pbStack_28 = (byte)*param_3;
          }
          else {
            uVar1 = *param_3;
            *pbStack_28 = (byte)(uVar1 >> 8);
            pbStack_28[1] = (byte)uVar1;
          }
        }
        local_55 = 1;
      }
    }
  }
  return local_55;
}


// ===== FUN_fffd51a3 @ fffd51a3 (39 bytes)

undefined1 FUN_fffd51a3(int param_1,undefined4 param_2)

{
  undefined1 local_b;
  
  if (param_1 == 0) {
    local_b = 0;
  }
  else {
    local_b = FUN_fffd504c(param_1,0,param_2);
  }
  return local_b;
}


// ===== FUN_fffd51ca @ fffd51ca (39 bytes)

undefined1 FUN_fffd51ca(int param_1,undefined4 param_2)

{
  undefined1 local_b;
  
  if (param_1 == 0) {
    local_b = 0;
  }
  else {
    local_b = FUN_fffd504c(param_1,1,param_2);
  }
  return local_b;
}


// ===== FUN_fffd51f1 @ fffd51f1 (156 bytes)

undefined1 FUN_fffd51f1(int param_1,char param_2,undefined1 *param_3,byte param_4)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined1 local_4d;
  undefined4 *puStack_20;
  
  if ((param_1 == 0) || (param_3 == (undefined1 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_4d = 0;
  }
  else if (param_4 == 0) {
    local_4d = 0;
  }
  else {
    if ((param_2 == '\0') || (param_2 == '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_4d = 0;
    }
    else {
      cVar2 = FUN_fffd4795(param_1);
      if (cVar2 == '\0') {
        local_4d = 0;
      }
      else {
        if (param_2 == '\0') {
          for (uVar3 = (uint)param_4; uVar3 != 0; uVar3 = uVar3 - 1) {
            *param_3 = *(undefined1 *)puStack_20;
            param_3 = param_3 + 1;
            puStack_20 = (undefined4 *)((int)puStack_20 + 1);
          }
        }
        else {
          puStack_20[2] = 0;
          puStack_20[1] = 0;
          *puStack_20 = 0;
          for (uVar3 = (uint)param_4; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puStack_20 = *param_3;
            puStack_20 = (undefined4 *)((int)puStack_20 + 1);
            param_3 = param_3 + 1;
          }
        }
        local_4d = 1;
      }
    }
  }
  return local_4d;
}


// ===== FUN_fffd528d @ fffd528d (41 bytes)

undefined1 FUN_fffd528d(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_fffd51f1(param_1,0,param_2,param_3);
  }
  return local_c;
}


// ===== FUN_fffd52b6 @ fffd52b6 (41 bytes)

undefined1 FUN_fffd52b6(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_fffd51f1(param_1,1,param_2,param_3);
  }
  return local_c;
}


// ===== FUN_fffd52df @ fffd52df (148 bytes)

undefined1 FUN_fffd52df(char param_1,undefined1 *param_2,undefined1 *param_3)

{
  bool bVar1;
  undefined1 local_e;
  
  if ((param_2 == (undefined1 *)0x0) || (param_3 == (undefined1 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_e = 0;
  }
  else {
    if (param_1 == '\x05') {
      *param_2 = 0x16;
      *param_3 = 0x1a;
    }
    else if (param_1 == '\x01') {
      *param_2 = 5;
      *param_3 = 6;
    }
    else if (param_1 == '\x02') {
      *param_2 = 7;
      *param_3 = 0xb;
    }
    else if (param_1 == '\x03') {
      *param_2 = 0xc;
      *param_3 = 0xf;
    }
    else if (param_1 == '\x04') {
      *param_2 = 0x10;
      *param_3 = 0x15;
    }
    else {
      if (param_1 != '\0') {
        return 0;
      }
      *param_2 = 0;
      *param_3 = 4;
    }
    local_e = 1;
  }
  return local_e;
}


// ===== FUN_fffd5373 @ fffd5373 (110 bytes)

void FUN_fffd5373(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9b6b;
  local_18 = &LAB_fffcde05;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd53e1 @ fffd53e1 (110 bytes)

void FUN_fffd53e1(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9be2;
  local_18 = &LAB_fffcde62;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd544f @ fffd544f (110 bytes)

void FUN_fffd544f(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9bfa;
  local_18 = &LAB_fffcde75;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd54bd @ fffd54bd (108 bytes)

void FUN_fffd54bd(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9c12;
  local_18 = &LAB_fffcde88;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5529 @ fffd5529 (108 bytes)

void FUN_fffd5529(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9cab;
  local_18 = &LAB_fffcde9b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5595 @ fffd5595 (108 bytes)

void FUN_fffd5595(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELY        LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9cc2;
  local_18 = &LAB_fffcdeae;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5601 @ fffd5601 (108 bytes)

void FUN_fffd5601(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9cd9;
  local_18 = &LAB_fffcdec1;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a30;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd566d @ fffd566d (108 bytes)

void FUN_fffd566d(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9d85;
  local_18 = &LAB_fffcdf17;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a31;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd56d9 @ fffd56d9 (108 bytes)

void FUN_fffd56d9(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9e11;
  local_18 = &LAB_fffcdf29;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a32;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5745 @ fffd5745 (108 bytes)

void FUN_fffd5745(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9ebf;
  local_18 = &LAB_fffcdf93;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a33;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd57b1 @ fffd57b1 (108 bytes)

void FUN_fffd57b1(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9f4b;
  local_18 = &LAB_fffcdfa5;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a34;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd581d @ fffd581d (108 bytes)

void FUN_fffd581d(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9fc3;
  local_18 = &LAB_fffce000;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a35;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5889 @ fffd5889 (108 bytes)

void FUN_fffd5889(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0xc;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TY..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffc9fd9;
  local_18 = &LAB_fffce013;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 6;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a36;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd58f5 @ fffd58f5 (108 bytes)

void FUN_fffd58f5(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0xd;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca110;
  local_18 = &LAB_fffce0ca;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a37;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5961 @ fffd5961 (108 bytes)

void FUN_fffd5961(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0xe;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DIS..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca19c;
  local_18 = &LAB_fffce0dc;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a38;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd59cd @ fffd59cd (108 bytes)

void FUN_fffd59cd(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0xf;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY T..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca214;
  local_18 = &LAB_fffce0ef;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a39;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5a39 @ fffd5a39 (108 bytes)

void FUN_fffd5a39(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0x10;
  pcVar2 = 
  "RPTT SELECT          NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATO..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca28c;
  local_18 = &LAB_fffce102;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a3a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5aa5 @ fffd5aa5 (108 bytes)

void FUN_fffd5aa5(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0x11;
  pcVar2 = 
  "NAR WIDTH            CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca318;
  local_18 = &LAB_fffce114;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x16;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5b11 @ fffd5b11 (108 bytes)

void FUN_fffd5b11(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0x12;
  pcVar2 = 
  "CW AUTO MODE         AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/D..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca396;
  local_18 = &LAB_fffce127;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a3c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5b7d @ fffd5b7d (110 bytes)

void FUN_fffd5b7d(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca422;
  local_18 = &LAB_fffce139;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5beb @ fffd5beb (110 bytes)

void FUN_fffd5beb(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca43a;
  local_18 = &LAB_fffce14c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a40;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5c59 @ fffd5c59 (110 bytes)

void FUN_fffd5c59(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUM..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca452;
  local_18 = &LAB_fffce15f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a41;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5cc7 @ fffd5cc7 (108 bytes)

void FUN_fffd5cc7(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca46a;
  local_18 = &LAB_fffce172;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a42;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5d33 @ fffd5d33 (108 bytes)

void FUN_fffd5d33(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca481;
  local_18 = &LAB_fffce185;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a43;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5d9f @ fffd5d9f (108 bytes)

void FUN_fffd5d9f(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca498;
  local_18 = &LAB_fffce198;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a44;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5e0b @ fffd5e0b (108 bytes)

void FUN_fffd5e0b(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca4af;
  local_18 = &LAB_fffce1ab;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a45;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5e77 @ fffd5e77 (108 bytes)

void FUN_fffd5e77(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca4c4;
  local_18 = &LAB_fffce1b9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a46;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5ee3 @ fffd5ee3 (108 bytes)

void FUN_fffd5ee3(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca4d9;
  local_18 = &LAB_fffce1cb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a47;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5f4f @ fffd5f4f (108 bytes)

void FUN_fffd5f4f(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca4ee;
  local_18 = &LAB_fffce1d9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a48;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd5fbb @ fffd5fbb (108 bytes)

void FUN_fffd5fbb(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca503;
  local_18 = &LAB_fffce1eb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a49;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6027 @ fffd6027 (108 bytes)

void FUN_fffd6027(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN POR..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca519;
  local_18 = &LAB_fffce1fe;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6093 @ fffd6093 (108 bytes)

void FUN_fffd6093(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0xc;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca52f;
  local_18 = &LAB_fffce211;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd60ff @ fffd60ff (108 bytes)

void FUN_fffd60ff(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0xd;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca544;
  local_18 = &LAB_fffce223;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd616b @ fffd616b (108 bytes)

void FUN_fffd616b(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0xe;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca559;
  local_18 = &LAB_fffce235;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd61d7 @ fffd61d7 (108 bytes)

void FUN_fffd61d7(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0xf;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca56f;
  local_18 = &LAB_fffce248;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6243 @ fffd6243 (108 bytes)

void FUN_fffd6243(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 1;
  local_33 = 0x10;
  pcVar2 = 
  "RPTT SELECT          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca585;
  local_18 = &LAB_fffce25b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd62af @ fffd62af (110 bytes)

void FUN_fffd62af(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 2;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca59a;
  local_18 = &LAB_fffce26d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a52;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd631d @ fffd631d (110 bytes)

void FUN_fffd631d(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 2;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca5b2;
  local_18 = &LAB_fffce280;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a53;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd638b @ fffd638b (110 bytes)

void FUN_fffd638b(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 2;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca5ca;
  local_18 = &LAB_fffce293;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a54;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd63f9 @ fffd63f9 (108 bytes)

void FUN_fffd63f9(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 2;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca5e2;
  local_18 = &LAB_fffce2a6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a55;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6465 @ fffd6465 (108 bytes)

void FUN_fffd6465(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 2;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca5f8;
  local_18 = &LAB_fffce2b9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a56;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}

