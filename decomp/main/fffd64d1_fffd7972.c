// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd64d1 @ fffd64d1 (108 bytes)

void FUN_fffd64d1(void)

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
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca60f;
  local_18 = &LAB_fffce2cc;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a57;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd653d @ fffd653d (108 bytes)

void FUN_fffd653d(void)

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
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca626;
  local_18 = &LAB_fffce2df;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a58;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd65a9 @ fffd65a9 (108 bytes)

void FUN_fffd65a9(void)

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
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN   ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca63b;
  local_18 = &LAB_fffce2ed;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a59;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6615 @ fffd6615 (108 bytes)

void FUN_fffd6615(void)

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
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca650;
  local_18 = &LAB_fffce2ff;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a5a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6681 @ fffd6681 (108 bytes)

void FUN_fffd6681(void)

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
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca666;
  local_18 = &LAB_fffce30d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a5b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd66ed @ fffd66ed (108 bytes)

void FUN_fffd66ed(void)

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
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca67b;
  local_18 = &LAB_fffce31f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6759 @ fffd6759 (108 bytes)

void FUN_fffd6759(void)

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
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca691;
  local_18 = &LAB_fffce332;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd67c5 @ fffd67c5 (108 bytes)

void FUN_fffd67c5(void)

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
  local_33 = 0xc;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca6a7;
  local_18 = &LAB_fffce345;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a5e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6831 @ fffd6831 (108 bytes)

void FUN_fffd6831(void)

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
  local_33 = 0xd;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca6bc;
  local_18 = &LAB_fffce357;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd689d @ fffd689d (108 bytes)

void FUN_fffd689d(void)

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
  local_33 = 0xe;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca6d2;
  local_18 = &LAB_fffce36a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a60;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6909 @ fffd6909 (108 bytes)

void FUN_fffd6909(void)

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
  local_33 = 0xf;
  pcVar2 = 
  "RPTT SELECT          RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca6e8;
  local_18 = &LAB_fffce37d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a61;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6975 @ fffd6975 (99 bytes)

void FUN_fffd6975(void)

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
  undefined4 local_c;
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
  local_33 = 0x10;
  pcVar2 = 
  "RPT SHIFT            RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN   ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca6fd;
  local_18 = &LAB_fffce38f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 1;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd69d8 @ fffd69d8 (108 bytes)

void FUN_fffd69d8(void)

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
  local_33 = 0x11;
  pcVar2 = 
  "RPT SHIFT(28MHz)     RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca79d;
  local_18 = &LAB_fffce436;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = &DAT_00009a62;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6a44 @ fffd6a44 (110 bytes)

void FUN_fffd6a44(void)

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
  local_33 = 0x12;
  pcVar2 = 
  "RPT SHIFT(50MHz)     ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca821;
  local_18 = &LAB_fffce450;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 400;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = &DAT_00009a63;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6ab2 @ fffd6ab2 (99 bytes)

void FUN_fffd6ab2(void)

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
  undefined4 local_c;
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
  local_33 = 0x13;
  pcVar2 = 
  "ENC/DEC              TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTIO..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca8b6;
  local_18 = &LAB_fffce4df;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 2;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6b15 @ fffd6b15 (99 bytes)

void FUN_fffd6b15(void)

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
  undefined4 local_c;
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
  local_33 = 0x14;
  pcVar2 = 
  "TONE FREQ            AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH   ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffca956;
  local_18 = &LAB_fffce588;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x31;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0;
  local_3 = 3;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6b78 @ fffd6b78 (110 bytes)

void FUN_fffd6b78(void)

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
  local_34 = 3;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaa35;
  local_18 = &LAB_fffce629;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a67;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6be6 @ fffd6be6 (110 bytes)

void FUN_fffd6be6(void)

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
  local_34 = 3;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaa4d;
  local_18 = &LAB_fffce63c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a68;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6c54 @ fffd6c54 (110 bytes)

void FUN_fffd6c54(void)

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
  local_34 = 3;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WID..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaa65;
  local_18 = &LAB_fffce64f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a69;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6cc2 @ fffd6cc2 (108 bytes)

void FUN_fffd6cc2(void)

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
  local_34 = 3;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaa7d;
  local_18 = &LAB_fffce662;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6d2e @ fffd6d2e (108 bytes)

void FUN_fffd6d2e(void)

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
  local_34 = 3;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaa93;
  local_18 = &LAB_fffce675;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6d9a @ fffd6d9a (108 bytes)

void FUN_fffd6d9a(void)

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
  local_34 = 3;
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaaaa;
  local_18 = &LAB_fffce688;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6e06 @ fffd6e06 (108 bytes)

void FUN_fffd6e06(void)

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
  local_34 = 3;
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaac1;
  local_18 = &LAB_fffce69b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a6d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6e72 @ fffd6e72 (108 bytes)

void FUN_fffd6e72(void)

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
  local_34 = 3;
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaad6;
  local_18 = &LAB_fffce6a9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a6e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6ede @ fffd6ede (108 bytes)

void FUN_fffd6ede(void)

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
  local_34 = 3;
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaaeb;
  local_18 = &LAB_fffce6bb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a6f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6f4a @ fffd6f4a (108 bytes)

void FUN_fffd6f4a(void)

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
  local_34 = 3;
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab01;
  local_18 = &LAB_fffce6c9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a70;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd6fb6 @ fffd6fb6 (108 bytes)

void FUN_fffd6fb6(void)

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
  local_34 = 3;
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab16;
  local_18 = &LAB_fffce6db;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a71;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7022 @ fffd7022 (108 bytes)

void FUN_fffd7022(void)

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
  local_34 = 3;
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab2c;
  local_18 = &LAB_fffce6ee;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a72;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd708e @ fffd708e (108 bytes)

void FUN_fffd708e(void)

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
  local_34 = 3;
  local_33 = 0xc;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab42;
  local_18 = &LAB_fffce701;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a73;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd70fa @ fffd70fa (108 bytes)

void FUN_fffd70fa(void)

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
  local_34 = 3;
  local_33 = 0xd;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab57;
  local_18 = &LAB_fffce713;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a74;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7166 @ fffd7166 (108 bytes)

void FUN_fffd7166(void)

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
  local_34 = 3;
  local_33 = 0xe;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab6c;
  local_18 = &LAB_fffce725;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a75;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd71d2 @ fffd71d2 (108 bytes)

void FUN_fffd71d2(void)

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
  local_34 = 3;
  local_33 = 0xf;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab82;
  local_18 = &LAB_fffce738;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a76;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd723e @ fffd723e (108 bytes)

void FUN_fffd723e(void)

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
  local_34 = 3;
  local_33 = 0x10;
  pcVar2 = 
  "RPTT SELECT          NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcab98;
  local_18 = &LAB_fffce74b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a77;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd72aa @ fffd72aa (108 bytes)

void FUN_fffd72aa(void)

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
  local_34 = 3;
  local_33 = 0x11;
  pcVar2 = 
  "NAR WIDTH            PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcabad;
  local_18 = &LAB_fffce75d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a78;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7316 @ fffd7316 (108 bytes)

void FUN_fffd7316(void)

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
  local_34 = 3;
  local_33 = 0x12;
  pcVar2 = 
  "PSK TONE             DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcac3a;
  local_18 = &LAB_fffce770;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a79;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7382 @ fffd7382 (110 bytes)

void FUN_fffd7382(void)

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
  local_34 = 3;
  local_33 = 0x13;
  pcVar2 = 
  "DATA SHIFT (SSB)     AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcacb7;
  local_18 = &LAB_fffce782;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 300;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = &DAT_00009a7a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd73f0 @ fffd73f0 (110 bytes)

void FUN_fffd73f0(void)

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
  local_34 = 4;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcad49;
  local_18 = &LAB_fffce7c7;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a7e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd745e @ fffd745e (110 bytes)

void FUN_fffd745e(void)

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
  local_34 = 4;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcad61;
  local_18 = &LAB_fffce7da;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a7f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd74cc @ fffd74cc (110 bytes)

void FUN_fffd74cc(void)

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
  local_34 = 4;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcad79;
  local_18 = &LAB_fffce7ed;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a80;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd753a @ fffd753a (108 bytes)

void FUN_fffd753a(void)

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
  local_34 = 4;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POW..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcad91;
  local_18 = &LAB_fffce800;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a81;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd75a6 @ fffd75a6 (108 bytes)

void FUN_fffd75a6(void)

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
  local_34 = 4;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POW..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcada7;
  local_18 = &LAB_fffce813;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a82;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7612 @ fffd7612 (108 bytes)

void FUN_fffd7612(void)

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
  local_34 = 4;
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcadbe;
  local_18 = &LAB_fffce826;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a83;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd767e @ fffd767e (108 bytes)

void FUN_fffd767e(void)

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
  local_34 = 4;
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcadd5;
  local_18 = &LAB_fffce839;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a84;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd76ea @ fffd76ea (108 bytes)

void FUN_fffd76ea(void)

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
  local_34 = 4;
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY F..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcadea;
  local_18 = &LAB_fffce847;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a85;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7756 @ fffd7756 (108 bytes)

void FUN_fffd7756(void)

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
  local_34 = 4;
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcadff;
  local_18 = &LAB_fffce859;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a86;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd77c2 @ fffd77c2 (108 bytes)

void FUN_fffd77c2(void)

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
  local_34 = 4;
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETEC..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae15;
  local_18 = &LAB_fffce867;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a87;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd782e @ fffd782e (108 bytes)

void FUN_fffd782e(void)

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
  local_34 = 4;
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae2a;
  local_18 = &LAB_fffce879;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a88;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd789a @ fffd789a (108 bytes)

void FUN_fffd789a(void)

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
  local_34 = 4;
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae40;
  local_18 = &LAB_fffce88c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a89;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7906 @ fffd7906 (108 bytes)

void FUN_fffd7906(void)

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
  local_34 = 4;
  local_33 = 0xc;
  pcVar2 = 
  "RPTT SELECT          NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP    ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae56;
  local_18 = &LAB_fffce89f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a8a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7972 @ fffd7972 (108 bytes)

void FUN_fffd7972(void)

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
  local_34 = 4;
  local_33 = 0xd;
  pcVar2 = 
  "NAR WIDTH            MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae6b;
  local_18 = &LAB_fffce8b1;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a8b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}

