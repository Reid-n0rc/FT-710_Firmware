// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX030101 @ fffd883e (108 bytes)

/* Menu item 2.7.0 OPERATION SETTING / GENERAL / BEEP LEVEL */

void menuitem_EX030101(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030102 @ fffd88aa (108 bytes)

/* Menu item 2.7.1 OPERATION SETTING / GENERAL / RF/SQL VR */

void menuitem_EX030102(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030103 @ fffd8916 (108 bytes)

/* Menu item 2.7.2 OPERATION SETTING / GENERAL / TUN/LIN PORT SELECT */

void menuitem_EX030103(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030104 @ fffd8982 (108 bytes)

/* Menu item 2.7.3 OPERATION SETTING / GENERAL / TUNER TYPE SELECT */

void menuitem_EX030104(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030105 @ fffd89ee (108 bytes)

/* Menu item 2.7.4 OPERATION SETTING / GENERAL / CAT-1 RATE */

void menuitem_EX030105(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030106 @ fffd8a5a (108 bytes)

/* Menu item 2.7.5 OPERATION SETTING / GENERAL / CAT-1 TIME OUT TIMER */

void menuitem_EX030106(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030107 @ fffd8ac6 (108 bytes)

/* Menu item 2.7.6 OPERATION SETTING / GENERAL / CAT-1 CAT-3 STOP BIT */

void menuitem_EX030107(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030108 @ fffd8b32 (108 bytes)

/* Menu item 2.7.7 OPERATION SETTING / GENERAL / CAT-2 RATE */

void menuitem_EX030108(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030109 @ fffd8b9e (108 bytes)

/* Menu item 2.7.8 OPERATION SETTING / GENERAL / CAT-2 TIME OUT TIMER */

void menuitem_EX030109(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030110 @ fffd8c0a (108 bytes)

/* Menu item 2.7.9 OPERATION SETTING / GENERAL / CAT-3 RATE */

void menuitem_EX030110(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030111 @ fffd8c76 (108 bytes)

/* Menu item 2.7.10 OPERATION SETTING / GENERAL / CAT-3 TIME OUT TIMER */

void menuitem_EX030111(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030112 @ fffd8ce2 (108 bytes)

/* Menu item 2.7.11 OPERATION SETTING / GENERAL / QMB CH */

void menuitem_EX030112(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030113 @ fffd8d4e (108 bytes)

/* Menu item 2.7.12 OPERATION SETTING / GENERAL / BAND STACK */

void menuitem_EX030113(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030114 @ fffd8dba (108 bytes)

/* Menu item 2.7.13 OPERATION SETTING / GENERAL / MEM GROUP */

void menuitem_EX030114(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030115 @ fffd8e26 (108 bytes)

/* Menu item 2.7.14 OPERATION SETTING / GENERAL / TX TIME OUT TIMER */

void menuitem_EX030115(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030116 @ fffd8e92 (108 bytes)

/* Menu item 2.7.15 OPERATION SETTING / GENERAL / MIC SCAN */

void menuitem_EX030116(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030117 @ fffd8efe (108 bytes)

/* Menu item 2.7.16 OPERATION SETTING / GENERAL / MIC SCAN RESUME */

void menuitem_EX030117(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030118 @ fffd8f6a (110 bytes)

/* Menu item 2.7.17 OPERATION SETTING / GENERAL / REF FREQ FINE ADJ */

void menuitem_EX030118(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030119 @ fffd8fd8 (108 bytes)

/* Menu item 2.7.18 OPERATION SETTING / GENERAL / KEYBOARD LANGUAGE */

void menuitem_EX030119(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030120 @ fffd9044 (108 bytes)

/* Menu item 2.7.19 OPERATION SETTING / GENERAL / MIC P1 */

void menuitem_EX030120(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030121 @ fffd90b0 (108 bytes)

/* Menu item 2.7.20 OPERATION SETTING / GENERAL / MIC P2 */

void menuitem_EX030121(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030122 @ fffd911c (108 bytes)

/* Menu item 2.7.21 OPERATION SETTING / GENERAL / MIC P3 */

void menuitem_EX030122(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030123 @ fffd9188 (108 bytes)

/* Menu item 2.7.22 OPERATION SETTING / GENERAL / MIC P4 */

void menuitem_EX030123(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030124 @ fffd91f4 (108 bytes)

/* Menu item 2.7.23 OPERATION SETTING / GENERAL / MIC UP */

void menuitem_EX030124(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030125 @ fffd9260 (108 bytes)

/* Menu item 2.7.24 OPERATION SETTING / GENERAL / MIC DOWN */

void menuitem_EX030125(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030126 @ fffd92cc (108 bytes)

/* Menu item 2.7.25 OPERATION SETTING / GENERAL / SCU-LAN10 */

void menuitem_EX030126(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030201 @ fffd9338 (108 bytes)

/* Menu item 2.8.0 OPERATION SETTING / RX DSP / IF NOTCH WIDTH */

void menuitem_EX030201(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030202 @ fffd93a4 (108 bytes)

/* Menu item 2.8.1 OPERATION SETTING / RX DSP / NB REJECTION */

void menuitem_EX030202(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030203 @ fffd9410 (108 bytes)

/* Menu item 2.8.2 OPERATION SETTING / RX DSP / NB WIDTH */

void menuitem_EX030203(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030204 @ fffd947c (108 bytes)

/* Menu item 2.8.3 OPERATION SETTING / RX DSP / APF WIDTH */

void menuitem_EX030204(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030205 @ fffd94e8 (110 bytes)

/* Menu item 2.8.4 OPERATION SETTING / RX DSP / CONTOUR LEVEL */

void menuitem_EX030205(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030206 @ fffd9556 (108 bytes)

/* Menu item 2.8.5 OPERATION SETTING / RX DSP / CONTOUR WIDTH */

void menuitem_EX030206(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030301 @ fffd95c2 (108 bytes)

/* Menu item 2.9.0 OPERATION SETTING / TX AUDIO / AMC RELEASE TIME */

void menuitem_EX030301(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030302 @ fffd962e (108 bytes)

/* Menu item 2.9.1 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 FREQ */

void menuitem_EX030302(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030303 @ fffd969a (110 bytes)

/* Menu item 2.9.2 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 LEVEL */

void menuitem_EX030303(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030304 @ fffd9708 (108 bytes)

/* Menu item 2.9.3 OPERATION SETTING / TX AUDIO / PRMTRC EQ1 BWTH */

void menuitem_EX030304(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030305 @ fffd9774 (108 bytes)

/* Menu item 2.9.4 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 FREQ */

void menuitem_EX030305(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030306 @ fffd97e0 (110 bytes)

/* Menu item 2.9.5 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 LEVEL */

void menuitem_EX030306(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030307 @ fffd984e (108 bytes)

/* Menu item 2.9.6 OPERATION SETTING / TX AUDIO / PRMTRC EQ2 BWTH */

void menuitem_EX030307(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030308 @ fffd98ba (108 bytes)

/* Menu item 2.9.7 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 FREQ */

void menuitem_EX030308(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030309 @ fffd9926 (110 bytes)

/* Menu item 2.9.8 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 LEVEL */

void menuitem_EX030309(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030310 @ fffd9994 (108 bytes)

/* Menu item 2.9.9 OPERATION SETTING / TX AUDIO / PRMTRC EQ3 BWTH */

void menuitem_EX030310(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030311 @ fffd9a00 (108 bytes)

/* Menu item 2.9.10 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 FREQ */

void menuitem_EX030311(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030312 @ fffd9a6c (110 bytes)

/* Menu item 2.9.11 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 LEVEL */

void menuitem_EX030312(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030313 @ fffd9ada (108 bytes)

/* Menu item 2.9.12 OPERATION SETTING / TX AUDIO / P PRMTRC EQ1 BWTH */

void menuitem_EX030313(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030314 @ fffd9b46 (108 bytes)

/* Menu item 2.9.13 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 FREQ */

void menuitem_EX030314(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030315 @ fffd9bb2 (110 bytes)

/* Menu item 2.9.14 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 LEVEL */

void menuitem_EX030315(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030316 @ fffd9c20 (108 bytes)

/* Menu item 2.9.15 OPERATION SETTING / TX AUDIO / P PRMTRC EQ2 BWTH */

void menuitem_EX030316(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030317 @ fffd9c8c (108 bytes)

/* Menu item 2.9.16 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 FREQ */

void menuitem_EX030317(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030318 @ fffd9cf8 (110 bytes)

/* Menu item 2.9.17 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 LEVEL */

void menuitem_EX030318(void)

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
  menu_register(&local_38);
  return;
}

