// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd79de @ fffd79de (108 bytes)

void FUN_fffd79de(void)

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
  local_33 = 0xe;
  pcVar2 = 
  "MARK FREQUENCY       SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcae80;
  local_18 = &LAB_fffce8c4;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a8c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7a4a @ fffd7a4a (108 bytes)

void FUN_fffd7a4a(void)

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
  local_33 = 0xf;
  pcVar2 = 
  "SHIFT FREQUENCY      POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaefd;
  local_18 = &LAB_fffce8d6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a8d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7ab6 @ fffd7ab6 (108 bytes)

void FUN_fffd7ab6(void)

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
  local_33 = 0x10;
  pcVar2 = 
  "POLARITY TX          AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL    ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaf7a;
  local_18 = &LAB_fffce8e8;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a8e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7b22 @ fffd7b22 (110 bytes)

void FUN_fffd7b22(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0;
  pcVar2 = 
  "AF TREBLE GAIN       AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIM..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcaff7;
  local_18 = &LAB_fffce8fa;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a91;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7b90 @ fffd7b90 (110 bytes)

void FUN_fffd7b90(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 1;
  pcVar2 = 
  "AF MIDDLE TONE GAIN  AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb00f;
  local_18 = &LAB_fffce90d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a92;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7bfe @ fffd7bfe (110 bytes)

void FUN_fffd7bfe(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 2;
  pcVar2 = 
  "AF BASS GAIN         AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb027;
  local_18 = &LAB_fffce920;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a93;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7c6c @ fffd7c6c (108 bytes)

void FUN_fffd7c6c(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 3;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb03f;
  local_18 = &LAB_fffce933;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a94;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7cd8 @ fffd7cd8 (108 bytes)

void FUN_fffd7cd8(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 4;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb055;
  local_18 = &LAB_fffce946;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a95;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7d44 @ fffd7d44 (108 bytes)

void FUN_fffd7d44(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 5;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW        ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb06c;
  local_18 = &LAB_fffce959;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a96;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7db0 @ fffd7db0 (108 bytes)

void FUN_fffd7db0(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 6;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb083;
  local_18 = &LAB_fffce96c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a97;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7e1c @ fffd7e1c (108 bytes)

void FUN_fffd7e1c(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 7;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SEN..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb098;
  local_18 = &LAB_fffce97a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a98;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7e88 @ fffd7e88 (108 bytes)

void FUN_fffd7e88(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 8;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP S..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb0ad;
  local_18 = &LAB_fffce98c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a99;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7ef4 @ fffd7ef4 (108 bytes)

void FUN_fffd7ef4(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 9;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR V..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb0c2;
  local_18 = &LAB_fffce99a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a9a;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7f60 @ fffd7f60 (108 bytes)

void FUN_fffd7f60(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 10;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR V..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb0d7;
  local_18 = &LAB_fffce9ac;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a9b;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd7fcc @ fffd7fcc (108 bytes)

void FUN_fffd7fcc(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0xb;
  pcVar2 = 
  "REAR OUT LEVEL       RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR M..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb0ed;
  local_18 = &LAB_fffce9bf;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a9c;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8038 @ fffd8038 (108 bytes)

void FUN_fffd8038(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0xc;
  pcVar2 = 
  "RPTT SELECT          NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR C..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb103;
  local_18 = &LAB_fffce9d2;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a9d;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd80a4 @ fffd80a4 (108 bytes)

void FUN_fffd80a4(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0xd;
  pcVar2 = 
  "NAR WIDTH            PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb118;
  local_18 = &LAB_fffce9e4;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a9e;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8110 @ fffd8110 (108 bytes)

void FUN_fffd8110(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0xe;
  pcVar2 = 
  "PC KEYING            CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL      ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb12d;
  local_18 = &LAB_fffce9f7;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a9f;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd817c @ fffd817c (108 bytes)

void FUN_fffd817c(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0xf;
  pcVar2 = 
  "CW BK-IN TYPE        CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY        ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb142;
  local_18 = &LAB_fffcea09;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa0;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd81e8 @ fffd81e8 (108 bytes)

void FUN_fffd81e8(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0x10;
  pcVar2 = 
  "CW WAVE SHAPE        CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH      ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb1bf;
  local_18 = &LAB_fffcea1b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8254 @ fffd8254 (108 bytes)

void FUN_fffd8254(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0x11;
  pcVar2 = 
  "CW FREQ DISPLAY      QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR       ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb23c;
  local_18 = &LAB_fffcea2d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa2;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd82c0 @ fffd82c0 (108 bytes)

void FUN_fffd82c0(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0x12;
  pcVar2 = 
  "QSK DELAY TIME       CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR       ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb2b9;
  local_18 = &LAB_fffcea3f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa3;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd832c @ fffd832c (108 bytes)

void FUN_fffd832c(void)

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
  local_35 = 1;
  local_34 = 5;
  local_33 = 0x13;
  pcVar2 = 
  "CW INDICATOR         KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb336;
  local_18 = &LAB_fffcea51;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa4;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8398 @ fffd8398 (108 bytes)

void FUN_fffd8398(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 0;
  pcVar2 = 
  "KEYER TYPE           KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LO..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb3c2;
  local_18 = &LAB_fffcea63;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 5;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa7;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8404 @ fffd8404 (108 bytes)

void FUN_fffd8404(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 1;
  pcVar2 = 
  "KEYER DOT/DASH       CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb43f;
  local_18 = &LAB_fffcea79;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aa8;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8470 @ fffd8470 (108 bytes)

void FUN_fffd8470(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 2;
  pcVar2 = 
  "CW WEIGHT            NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb4bc;
  local_18 = &LAB_fffcea8b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009aa9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd84dc @ fffd84dc (108 bytes)

void FUN_fffd84dc(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 3;
  pcVar2 = 
  "NUMBER STYLE         CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb57a;
  local_18 = &LAB_fffcea9e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 6;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aaa;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8548 @ fffd8548 (110 bytes)

void FUN_fffd8548(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 4;
  pcVar2 = 
  "CONTEST NUMBER       CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATION..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb5f7;
  local_18 = &LAB_fffceab0;
  local_14 = &DAT_fffcdc78;
  local_10 = 1;
  local_e = 9999;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 0;
  local_c = &DAT_00009aab;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd85b6 @ fffd85b6 (108 bytes)

void FUN_fffd85b6(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 5;
  pcVar2 = 
  "CW MEMORY 1          CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UP..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb65d;
  local_18 = &LAB_fffceacc;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aad;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8622 @ fffd8622 (108 bytes)

void FUN_fffd8622(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 6;
  pcVar2 = 
  "CW MEMORY 2          CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT     ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb6e9;
  local_18 = &LAB_fffceade;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aae;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd868e @ fffd868e (108 bytes)

void FUN_fffd868e(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 7;
  pcVar2 = 
  "CW MEMORY 3          CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb6fe;
  local_18 = &LAB_fffceaf0;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aaf;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd86fa @ fffd86fa (108 bytes)

void FUN_fffd86fa(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 8;
  pcVar2 = 
  "CW MEMORY 4          CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb713;
  local_18 = &LAB_fffceb02;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab0;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8766 @ fffd8766 (108 bytes)

void FUN_fffd8766(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 9;
  pcVar2 = 
  "CW MEMORY 5          REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb728;
  local_18 = &LAB_fffceb14;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd87d2 @ fffd87d2 (108 bytes)

void FUN_fffd87d2(void)

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
  local_35 = 1;
  local_34 = 6;
  local_33 = 10;
  pcVar2 = 
  "REPEAT INTERVAL      BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb73d;
  local_18 = &LAB_fffceb26;
  local_14 = &DAT_fffcdc78;
  local_10 = 1;
  local_e = 0x3c;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ab2;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd883e @ fffd883e (108 bytes)

void FUN_fffd883e(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0;
  pcVar2 = 
  "BEEP LEVEL           RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb7b9;
  local_18 = &LAB_fffceb39;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ab5;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd88aa @ fffd88aa (108 bytes)

void FUN_fffd88aa(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 1;
  pcVar2 = 
  "RF/SQL VR            TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb825;
  local_18 = &LAB_fffceb4c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab6;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8916 @ fffd8916 (108 bytes)

void FUN_fffd8916(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 2;
  pcVar2 = 
  "TUN/LIN PORT SELECT  TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb8a5;
  local_18 = &LAB_fffceb5e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab7;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8982 @ fffd8982 (108 bytes)

void FUN_fffd8982(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 3;
  pcVar2 = 
  "TUNER TYPE SELECT    CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb925;
  local_18 = &LAB_fffceb74;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab8;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd89ee @ fffd89ee (108 bytes)

void FUN_fffd89ee(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 4;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcb9a5;
  local_18 = &LAB_fffcebb8;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ab9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8a5a @ fffd8a5a (108 bytes)

void FUN_fffd8a5a(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 5;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcba31;
  local_18 = &LAB_fffcebce;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009aba;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8ac6 @ fffd8ac6 (108 bytes)

void FUN_fffd8ac6(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 6;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbabd;
  local_18 = &LAB_fffcebe0;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009abb;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8b32 @ fffd8b32 (108 bytes)

void FUN_fffd8b32(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 7;
  pcVar2 = 
  "CAT-2 RATE           CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbb3d;
  local_18 = &LAB_fffcebfa;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009abc;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8b9e @ fffd8b9e (108 bytes)

void FUN_fffd8b9e(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 8;
  pcVar2 = 
  "CAT-2 TIME OUT TIMER CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbb52;
  local_18 = &LAB_fffcec10;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009abd;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8c0a @ fffd8c0a (108 bytes)

void FUN_fffd8c0a(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 9;
  pcVar2 = 
  "CAT-3 RATE           CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbb67;
  local_18 = &LAB_fffcec22;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009abe;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8c76 @ fffd8c76 (108 bytes)

void FUN_fffd8c76(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 10;
  pcVar2 = 
  "CAT-3 TIME OUT TIMER QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbb7c;
  local_18 = &LAB_fffcec38;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009abf;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8ce2 @ fffd8ce2 (108 bytes)

void FUN_fffd8ce2(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0xb;
  pcVar2 = 
  "QMB CH               BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbb91;
  local_18 = &LAB_fffcec4a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ac0;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8d4e @ fffd8d4e (108 bytes)

void FUN_fffd8d4e(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0xc;
  pcVar2 = 
  "BAND STACK           MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbc11;
  local_18 = &LAB_fffcec60;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ac1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8dba @ fffd8dba (108 bytes)

void FUN_fffd8dba(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0xd;
  pcVar2 = 
  "MEM GROUP            TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbc91;
  local_18 = &LAB_fffcec72;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ac2;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8e26 @ fffd8e26 (108 bytes)

void FUN_fffd8e26(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0xe;
  pcVar2 = 
  "TX TIME OUT TIMER    MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbd11;
  local_18 = &LAB_fffcec84;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x1e;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ac3;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8e92 @ fffd8e92 (108 bytes)

void FUN_fffd8e92(void)

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
  local_35 = 2;
  local_34 = 7;
  local_33 = 0xf;
  pcVar2 = 
  "MIC SCAN             MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbdeb;
  local_18 = &LAB_fffcec97;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ac4;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}

