// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd8efe @ fffd8efe (108 bytes)

void FUN_fffd8efe(void)

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
  local_33 = 0x10;
  pcVar2 = 
  "MIC SCAN RESUME      REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbe6b;
  local_18 = &LAB_fffceca9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ac5;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8f6a @ fffd8f6a (110 bytes)

void FUN_fffd8f6a(void)

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
  local_33 = 0x11;
  pcVar2 = 
  "REF FREQ FINE ADJ    KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbeeb;
  local_18 = &LAB_fffcecbb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffe7;
  local_e = 0x19;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ac6;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd8fd8 @ fffd8fd8 (108 bytes)

void FUN_fffd8fd8(void)

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
  local_33 = 0x12;
  pcVar2 = 
  "KEYBOARD LANGUAGE    MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcbf56;
  local_18 = &LAB_fffceccf;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ac7;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9044 @ fffd9044 (108 bytes)

void FUN_fffd9044(void)

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
  local_33 = 0x13;
  pcVar2 = 
  "MIC P1               MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc035;
  local_18 = &LAB_fffced1d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ac8;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd90b0 @ fffd90b0 (108 bytes)

void FUN_fffd90b0(void)

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
  local_33 = 0x14;
  pcVar2 = 
  "MIC P2               MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc0c2;
  local_18 = &LAB_fffced30;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ac9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd911c @ fffd911c (108 bytes)

void FUN_fffd911c(void)

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
  local_33 = 0x15;
  pcVar2 = 
  "MIC P3               MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc0d7;
  local_18 = &LAB_fffced43;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009aca;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9188 @ fffd9188 (108 bytes)

void FUN_fffd9188(void)

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
  local_33 = 0x16;
  pcVar2 = 
  "MIC P4               MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc0ec;
  local_18 = &LAB_fffced56;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009acb;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd91f4 @ fffd91f4 (108 bytes)

void FUN_fffd91f4(void)

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
  local_33 = 0x17;
  pcVar2 = 
  "MIC UP               MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc101;
  local_18 = &LAB_fffced69;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009acc;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9260 @ fffd9260 (108 bytes)

void FUN_fffd9260(void)

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
  local_33 = 0x18;
  pcVar2 = 
  "MIC DOWN             SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc116;
  local_18 = &LAB_fffced7c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009acd;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd92cc @ fffd92cc (108 bytes)

void FUN_fffd92cc(void)

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
  local_33 = 0x19;
  pcVar2 = 
  "SCU-LAN10            IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc12b;
  local_18 = &LAB_fffced8f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ace;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9338 @ fffd9338 (108 bytes)

void FUN_fffd9338(void)

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
  local_34 = 8;
  local_33 = 0;
  pcVar2 = 
  "IF NOTCH WIDTH       NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc140;
  local_18 = &LAB_fffceddd;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ad1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd93a4 @ fffd93a4 (108 bytes)

void FUN_fffd93a4(void)

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
  local_34 = 8;
  local_33 = 1;
  pcVar2 = 
  "NB REJECTION         NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc1c0;
  local_18 = &LAB_fffcedef;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ad2;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9410 @ fffd9410 (108 bytes)

void FUN_fffd9410(void)

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
  local_34 = 8;
  local_33 = 2;
  pcVar2 = 
  "NB WIDTH             APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc240;
  local_18 = &LAB_fffcee01;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ad3;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd947c @ fffd947c (108 bytes)

void FUN_fffd947c(void)

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
  local_34 = 8;
  local_33 = 3;
  pcVar2 = 
  "APF WIDTH            CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc2c0;
  local_18 = &LAB_fffcee13;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ad4;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd94e8 @ fffd94e8 (110 bytes)

void FUN_fffd94e8(void)

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
  local_34 = 8;
  local_33 = 4;
  pcVar2 = 
  "CONTOUR LEVEL        CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc340;
  local_18 = &LAB_fffcee25;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffd8;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ad5;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9556 @ fffd9556 (108 bytes)

void FUN_fffd9556(void)

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
  local_34 = 8;
  local_33 = 5;
  pcVar2 = 
  "CONTOUR WIDTH        AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc3ac;
  local_18 = &LAB_fffcee39;
  local_14 = &DAT_fffcdc78;
  local_10 = 1;
  local_e = 0xb;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ad6;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd95c2 @ fffd95c2 (108 bytes)

void FUN_fffd95c2(void)

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
  local_34 = 9;
  local_33 = 0;
  pcVar2 = 
  "AMC RELEASE TIME     PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc417;
  local_18 = &LAB_fffcee4b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ad9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd962e @ fffd962e (108 bytes)

void FUN_fffd962e(void)

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
  local_34 = 9;
  local_33 = 1;
  pcVar2 = 
  "PRMTRC EQ1 FREQ      PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc497;
  local_18 = &LAB_fffcee5d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 7;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ada;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd969a @ fffd969a (110 bytes)

void FUN_fffd969a(void)

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
  local_34 = 9;
  local_33 = 2;
  pcVar2 = 
  "PRMTRC EQ1 LEVEL     PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc556;
  local_18 = &LAB_fffcee6f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009adb;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9708 @ fffd9708 (108 bytes)

void FUN_fffd9708(void)

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
  local_34 = 9;
  local_33 = 3;
  pcVar2 = 
  "PRMTRC EQ1 BWTH      PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc5ce;
  local_18 = &LAB_fffcee82;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009adc;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9774 @ fffd9774 (108 bytes)

void FUN_fffd9774(void)

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
  local_34 = 9;
  local_33 = 4;
  pcVar2 = 
  "PRMTRC EQ2 FREQ      PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc645;
  local_18 = &LAB_fffcee94;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 9;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009add;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd97e0 @ fffd97e0 (110 bytes)

void FUN_fffd97e0(void)

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
  local_34 = 9;
  local_33 = 5;
  pcVar2 = 
  "PRMTRC EQ2 LEVEL     PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc65e;
  local_18 = &LAB_fffceea6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ade;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd984e @ fffd984e (108 bytes)

void FUN_fffd984e(void)

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
  local_34 = 9;
  local_33 = 6;
  pcVar2 = 
  "PRMTRC EQ2 BWTH      PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc673;
  local_18 = &LAB_fffceeb9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009adf;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd98ba @ fffd98ba (108 bytes)

void FUN_fffd98ba(void)

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
  local_34 = 9;
  local_33 = 7;
  pcVar2 = 
  "PRMTRC EQ3 FREQ      PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc688;
  local_18 = &LAB_fffceecb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x12;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae0;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9926 @ fffd9926 (110 bytes)

void FUN_fffd9926(void)

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
  local_34 = 9;
  local_33 = 8;
  pcVar2 = 
  "PRMTRC EQ3 LEVEL     PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc6a1;
  local_18 = &LAB_fffceede;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9994 @ fffd9994 (108 bytes)

void FUN_fffd9994(void)

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
  local_34 = 9;
  local_33 = 9;
  pcVar2 = 
  "PRMTRC EQ3 BWTH      P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc6b6;
  local_18 = &LAB_fffceef1;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae2;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9a00 @ fffd9a00 (108 bytes)

void FUN_fffd9a00(void)

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
  local_34 = 9;
  local_33 = 10;
  pcVar2 = 
  "P PRMTRC EQ1 FREQ    P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc6cb;
  local_18 = &LAB_fffcef03;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 7;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae3;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9a6c @ fffd9a6c (110 bytes)

void FUN_fffd9a6c(void)

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
  local_34 = 9;
  local_33 = 0xb;
  pcVar2 = 
  "P PRMTRC EQ1 LEVEL   P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc6e3;
  local_18 = &LAB_fffcef15;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae4;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9ada @ fffd9ada (108 bytes)

void FUN_fffd9ada(void)

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
  local_34 = 9;
  local_33 = 0xc;
  pcVar2 = 
  "P PRMTRC EQ1 BWTH    P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc6f8;
  local_18 = &LAB_fffcef28;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae5;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9b46 @ fffd9b46 (108 bytes)

void FUN_fffd9b46(void)

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
  local_34 = 9;
  local_33 = 0xd;
  pcVar2 = 
  "P PRMTRC EQ2 FREQ    P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc70d;
  local_18 = &LAB_fffcef3a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 9;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae6;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9bb2 @ fffd9bb2 (110 bytes)

void FUN_fffd9bb2(void)

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
  local_34 = 9;
  local_33 = 0xe;
  pcVar2 = 
  "P PRMTRC EQ2 LEVEL   P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc726;
  local_18 = &LAB_fffcef4c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae7;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9c20 @ fffd9c20 (108 bytes)

void FUN_fffd9c20(void)

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
  local_34 = 9;
  local_33 = 0xf;
  pcVar2 = 
  "P PRMTRC EQ2 BWTH    P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc73b;
  local_18 = &LAB_fffcef5f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae8;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9c8c @ fffd9c8c (108 bytes)

void FUN_fffd9c8c(void)

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
  local_34 = 9;
  local_33 = 0x10;
  pcVar2 = 
  "P PRMTRC EQ3 FREQ    P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc750;
  local_18 = &LAB_fffcef71;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x12;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009ae9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9cf8 @ fffd9cf8 (110 bytes)

void FUN_fffd9cf8(void)

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
  local_34 = 9;
  local_33 = 0x11;
  pcVar2 = 
  "P PRMTRC EQ3 LEVEL   P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc769;
  local_18 = &LAB_fffcef84;
  local_14 = &DAT_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009aea;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9d66 @ fffd9d66 (108 bytes)

void FUN_fffd9d66(void)

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
  local_34 = 9;
  local_33 = 0x12;
  pcVar2 = 
  "P PRMTRC EQ3 BWTH    HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc77e;
  local_18 = &LAB_fffcef97;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009aeb;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9dd2 @ fffd9dd2 (108 bytes)

void FUN_fffd9dd2(void)

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
  local_34 = 10;
  local_33 = 0;
  pcVar2 = 
  "HF MAX POWER         50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc793;
  local_18 = &LAB_fffcefa9;
  local_14 = &DAT_fffcdc78;
  local_10 = 5;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009aee;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9e3e @ fffd9e3e (108 bytes)

void FUN_fffd9e3e(void)

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
  local_34 = 10;
  local_33 = 1;
  pcVar2 = 
  "50M MAX POWER        70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc850;
  local_18 = &LAB_fffcefc1;
  local_14 = &DAT_fffcdc78;
  local_10 = 5;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009aef;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9eaa @ fffd9eaa (108 bytes)

void FUN_fffd9eaa(void)

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
  local_34 = 10;
  local_33 = 2;
  pcVar2 = 
  "70M MAX POWER        AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc899;
  local_18 = &LAB_fffcefd9;
  local_14 = &DAT_fffcdc78;
  local_10 = 5;
  local_e = 0x32;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009af0;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9f16 @ fffd9f16 (108 bytes)

void FUN_fffd9f16(void)

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
  local_34 = 10;
  local_33 = 3;
  pcVar2 = 
  "AM MAX POWER         VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc8e2;
  local_18 = &LAB_fffceff1;
  local_14 = &DAT_fffcdc78;
  local_10 = 5;
  local_e = 0x19;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009af1;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9f82 @ fffd9f82 (108 bytes)

void FUN_fffd9f82(void)

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
  local_34 = 10;
  local_33 = 4;
  pcVar2 = 
  "VOX SELECT           EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc93c;
  local_18 = &LAB_fffcf01c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009af3;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffd9fee @ fffd9fee (108 bytes)

void FUN_fffd9fee(void)

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
  local_34 = 10;
  local_33 = 5;
  pcVar2 = 
  "EMERGENCY FREQ TX    TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc9bc;
  local_18 = &LAB_fffcf02e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009af4;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda05a @ fffda05a (108 bytes)

void FUN_fffda05a(void)

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
  local_34 = 10;
  local_33 = 6;
  pcVar2 = 
  "TX INHITBIT          METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc9d1;
  local_18 = &LAB_fffcf06e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009af5;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda0c6 @ fffda0c6 (108 bytes)

void FUN_fffda0c6(void)

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
  local_34 = 10;
  local_33 = 7;
  pcVar2 = 
  "METER DETECTOR       SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcc9e6;
  local_18 = &LAB_fffcf080;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009af6;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda132 @ fffda132 (108 bytes)

void FUN_fffda132(void)

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
  local_34 = 0xb;
  local_33 = 0;
  pcVar2 = 
  "SSB/CW DIAL STEP     RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcca66;
  local_18 = &LAB_fffcf092;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009af9;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda19e @ fffda19e (108 bytes)

void FUN_fffda19e(void)

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
  local_34 = 0xb;
  local_33 = 1;
  pcVar2 = 
  "RTTY/PSK DIAL STEP   CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccae6;
  local_18 = &LAB_fffcf0a4;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009afa;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda20a @ fffda20a (108 bytes)

void FUN_fffda20a(void)

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
  local_34 = 0xb;
  local_33 = 2;
  pcVar2 = 
  "CH STEP              AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccb66;
  local_18 = &LAB_fffcf0b6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009afb;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda276 @ fffda276 (108 bytes)

void FUN_fffda276(void)

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
  local_34 = 0xb;
  local_33 = 3;
  pcVar2 = 
  "AM CH STEP           FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccbe6;
  local_18 = &LAB_fffcf0c8;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 5;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009afc;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda2e2 @ fffda2e2 (108 bytes)

void FUN_fffda2e2(void)

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
  local_34 = 0xb;
  local_33 = 4;
  pcVar2 = 
  "FM CH STEP           MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccc66;
  local_18 = &LAB_fffcf0da;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 5;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009afd;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda34e @ fffda34e (108 bytes)

void FUN_fffda34e(void)

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
  local_34 = 0xb;
  local_33 = 5;
  pcVar2 = 
  "MAIN STEPS PER REV.  MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccce6;
  local_18 = &LAB_fffcf0ec;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009afe;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}


// ===== FUN_fffda3ba @ fffda3ba (108 bytes)

void FUN_fffda3ba(void)

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
  undefined *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined4 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 0;
  pcVar2 = 
  "MY CALL              MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccd66;
  local_18 = &DAT_fffcf0fe;
  local_14 = &LAB_fffcf303;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b01;
  local_3 = 0;
  FUN_fffd442f(&local_38);
  return;
}

