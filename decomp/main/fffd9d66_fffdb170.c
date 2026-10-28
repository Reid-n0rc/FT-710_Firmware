// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX030319 @ fffd9d66 (108 bytes)

/* Menu item 2.9.18 OPERATION SETTING / TX AUDIO / P PRMTRC EQ3 BWTH */

void menuitem_EX030319(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030401 @ fffd9dd2 (108 bytes)

/* Menu item 2.10.0 OPERATION SETTING / TX GENERAL / HF MAX POWER */

void menuitem_EX030401(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030402 @ fffd9e3e (108 bytes)

/* Menu item 2.10.1 OPERATION SETTING / TX GENERAL / 50M MAX POWER */

void menuitem_EX030402(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030403 @ fffd9eaa (108 bytes)

/* Menu item 2.10.2 OPERATION SETTING / TX GENERAL / 70M MAX POWER */

void menuitem_EX030403(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030404 @ fffd9f16 (108 bytes)

/* Menu item 2.10.3 OPERATION SETTING / TX GENERAL / AM MAX POWER */

void menuitem_EX030404(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030405 @ fffd9f82 (108 bytes)

/* Menu item 2.10.4 OPERATION SETTING / TX GENERAL / VOX SELECT */

void menuitem_EX030405(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030406 @ fffd9fee (108 bytes)

/* Menu item 2.10.5 OPERATION SETTING / TX GENERAL / EMERGENCY FREQ TX */

void menuitem_EX030406(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030407 @ fffda05a (108 bytes)

/* Menu item 2.10.6 OPERATION SETTING / TX GENERAL / TX INHITBIT */

void menuitem_EX030407(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030408 @ fffda0c6 (108 bytes)

/* Menu item 2.10.7 OPERATION SETTING / TX GENERAL / METER DETECTOR */

void menuitem_EX030408(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030501 @ fffda132 (108 bytes)

/* Menu item 2.11.0 OPERATION SETTING / TUNING / SSB/CW DIAL STEP */

void menuitem_EX030501(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030502 @ fffda19e (108 bytes)

/* Menu item 2.11.1 OPERATION SETTING / TUNING / RTTY/PSK DIAL STEP */

void menuitem_EX030502(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030503 @ fffda20a (108 bytes)

/* Menu item 2.11.2 OPERATION SETTING / TUNING / CH STEP */

void menuitem_EX030503(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030504 @ fffda276 (108 bytes)

/* Menu item 2.11.3 OPERATION SETTING / TUNING / AM CH STEP */

void menuitem_EX030504(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030505 @ fffda2e2 (108 bytes)

/* Menu item 2.11.4 OPERATION SETTING / TUNING / FM CH STEP */

void menuitem_EX030505(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX030506 @ fffda34e (108 bytes)

/* Menu item 2.11.5 OPERATION SETTING / TUNING / MAIN STEPS PER REV. */

void menuitem_EX030506(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040101 @ fffda3ba (108 bytes)

/* Menu item 3.12.0 DISPLAY SETTING / DISPLAY / MY CALL */

void menuitem_EX040101(void)

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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040102 @ fffda426 (108 bytes)

/* Menu item 3.12.1 DISPLAY SETTING / DISPLAY / MY CALL TIME */

void menuitem_EX040102(void)

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
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 1;
  pcVar2 = 
  "MY CALL TIME         POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccdcd;
  local_18 = &LAB_fffcf0ff;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 5;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b0d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040103 @ fffda492 (108 bytes)

/* Menu item 3.12.2 DISPLAY SETTING / DISPLAY / POP-UP TIME */

void menuitem_EX040103(void)

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
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 2;
  pcVar2 = 
  "POP-UP TIME          SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcce4d;
  local_18 = &LAB_fffcf111;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b0e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040104 @ fffda4fe (108 bytes)

/* Menu item 3.12.3 DISPLAY SETTING / DISPLAY / SCREEN SAVER */

void menuitem_EX040104(void)

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
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 3;
  pcVar2 = 
  "SCREEN SAVER         LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccecd;
  local_18 = &LAB_fffcf123;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b0f;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040105 @ fffda56a (108 bytes)

/* Menu item 3.12.4 DISPLAY SETTING / DISPLAY / LED DIMMER */

void menuitem_EX040105(void)

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
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 4;
  pcVar2 = 
  "LED DIMMER           MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccf4d;
  local_18 = &LAB_fffcf139;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b10;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040106 @ fffda5d6 (108 bytes)

/* Menu item 3.12.5 DISPLAY SETTING / DISPLAY / MOUSE POINTER SPEED */

void menuitem_EX040106(void)

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
  local_35 = 3;
  local_34 = 0xc;
  local_33 = 5;
  pcVar2 = 
  "MOUSE POINTER SPEED  RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffccfce;
  local_18 = &LAB_fffcf188;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b11;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040201 @ fffda642 (108 bytes)

/* Menu item 3.13.0 DISPLAY SETTING / SCOPE / RBW */

void menuitem_EX040201(void)

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
  local_35 = 3;
  local_34 = 0xd;
  local_33 = 0;
  pcVar2 = 
  "RBW                  SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd039;
  local_18 = &LAB_fffcf1d7;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b14;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040202 @ fffda6ae (108 bytes)

/* Menu item 3.13.1 DISPLAY SETTING / SCOPE / SCOPE CTR */

void menuitem_EX040202(void)

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
  local_35 = 3;
  local_34 = 0xd;
  local_33 = 1;
  pcVar2 = 
  "SCOPE CTR            2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd0b9;
  local_18 = &LAB_fffcf1e9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b15;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040203 @ fffda71a (108 bytes)

/* Menu item 3.13.2 DISPLAY SETTING / SCOPE / 2D DISP SENSITIVITY */

void menuitem_EX040203(void)

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
  local_35 = 3;
  local_34 = 0xd;
  local_33 = 2;
  pcVar2 = 
  "2D DISP SENSITIVITY  3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd139;
  local_18 = &LAB_fffcf1fb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b16;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040204 @ fffda786 (108 bytes)

/* Menu item 3.13.3 DISPLAY SETTING / SCOPE / 3DSS DISP SENSITIVITY */

void menuitem_EX040204(void)

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
  local_35 = 3;
  local_34 = 0xd;
  local_33 = 3;
  pcVar2 = 
  "3DSS DISP SENSITIVITYVMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd1b9;
  local_18 = &LAB_fffcf20d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b17;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040301 @ fffda7f2 (108 bytes)

/* Menu item 3.14.0 DISPLAY SETTING / VFO IND COLOR / VMI COLOR VFO-A */

void menuitem_EX040301(void)

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
  local_35 = 3;
  local_34 = 0xe;
  local_33 = 0;
  pcVar2 = 
  "VMI COLOR VFO-A      VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd239;
  local_18 = &LAB_fffcf21f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b1a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040302 @ fffda85e (108 bytes)

/* Menu item 3.14.1 DISPLAY SETTING / VFO IND COLOR / VMI COLOR VFO-B */

void menuitem_EX040302(void)

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
  local_35 = 3;
  local_34 = 0xe;
  local_33 = 1;
  pcVar2 = 
  "VMI COLOR VFO-B      VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd2b9;
  local_18 = &LAB_fffcf231;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b1b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040303 @ fffda8ca (108 bytes)

/* Menu item 3.14.2 DISPLAY SETTING / VFO IND COLOR / VMI COLOR MEMORY */

void menuitem_EX040303(void)

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
  local_35 = 3;
  local_34 = 0xe;
  local_33 = 2;
  pcVar2 = 
  "VMI COLOR MEMORY     VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd339;
  local_18 = &LAB_fffcf243;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b1c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040304 @ fffda936 (108 bytes)

/* Menu item 3.14.3 DISPLAY SETTING / VFO IND COLOR / VMI COLOR CLAR */

void menuitem_EX040304(void)

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
  local_35 = 3;
  local_34 = 0xe;
  local_33 = 3;
  pcVar2 = 
  "VMI COLOR CLAR       EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd3b9;
  local_18 = &LAB_fffcf255;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b1d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040401 @ fffda9a2 (108 bytes)

/* Menu item 3.15.0 DISPLAY SETTING / EXT MONITOR / EXT DISPLAY */

void menuitem_EX040401(void)

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
  local_35 = 3;
  local_34 = 0xf;
  local_33 = 0;
  pcVar2 = 
  "EXT DISPLAY          PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DEL..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd439;
  local_18 = &LAB_fffcf267;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b20;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX040402 @ fffdaa0e (108 bytes)

/* Menu item 3.15.1 DISPLAY SETTING / EXT MONITOR / PIXEL */

void menuitem_EX040402(void)

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
  local_35 = 3;
  local_34 = 0xf;
  local_33 = 1;
  pcVar2 = 
  "PIXEL                DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd44e;
  local_18 = &LAB_fffcf2b5;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b21;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_16_00 @ fffdaa7a (99 bytes)

/* Menu item 4.16.0 EXTENSION SETTING / DATE&TIME / DAY */

void menuitem_int4_16_00(void)

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
  local_35 = 4;
  local_34 = 0x10;
  local_33 = 0;
  pcVar2 = 
  "DAY                  MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd4ce;
  local_18 = &LAB_fffcf37a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_16_01 @ fffdaadd (99 bytes)

/* Menu item 4.16.1 EXTENSION SETTING / DATE&TIME / MONTH */

void menuitem_int4_16_01(void)

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
  local_35 = 4;
  local_34 = 0x10;
  local_33 = 1;
  pcVar2 = 
  "MONTH                YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd5d5;
  local_18 = &LAB_fffcf3fb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_16_02 @ fffdab40 (99 bytes)

/* Menu item 4.16.2 EXTENSION SETTING / DATE&TIME / YEAR */

void menuitem_int4_16_02(void)

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
  local_35 = 4;
  local_34 = 0x10;
  local_33 = 2;
  pcVar2 = 
  "YEAR                 HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd65d;
  local_18 = &LAB_fffcf410;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_16_03 @ fffdaba3 (99 bytes)

/* Menu item 4.16.3 EXTENSION SETTING / DATE&TIME / HOUR */

void menuitem_int4_16_03(void)

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
  local_35 = 4;
  local_34 = 0x10;
  local_33 = 3;
  pcVar2 = 
  "HOUR                 MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd6fc;
  local_18 = &LAB_fffcf425;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_16_04 @ fffdac06 (99 bytes)

/* Menu item 4.16.4 EXTENSION SETTING / DATE&TIME / MINUTE */

void menuitem_int4_16_04(void)

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
  local_35 = 4;
  local_34 = 0x10;
  local_33 = 4;
  pcVar2 = 
  "MINUTE               MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEV..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd77b;
  local_18 = &LAB_fffcf43a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_00 @ fffdac69 (99 bytes)

/* Menu item 4.17.0 EXTENSION SETTING / SD CARD / MEM LIST LOAD */

void menuitem_int4_17_00(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 0;
  pcVar2 = 
  "MEM LIST LOAD        MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LE..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd7fa;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf44f;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_01 @ fffdaccc (99 bytes)

/* Menu item 4.17.1 EXTENSION SETTING / SD CARD / MEM LIST SAVE */

void menuitem_int4_17_01(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 1;
  pcVar2 = 
  "MEM LIST SAVE        MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd865;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf780;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_02 @ fffdad2f (99 bytes)

/* Menu item 4.17.2 EXTENSION SETTING / SD CARD / MENU LOAD */

void menuitem_int4_17_02(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 2;
  pcVar2 = 
  "MENU LOAD            MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd86e;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf830;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_03 @ fffdad92 (99 bytes)

/* Menu item 4.17.3 EXTENSION SETTING / SD CARD / MENU SAVE */

void menuitem_int4_17_03(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 3;
  pcVar2 = 
  "MENU SAVE            INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAI..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd877;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf857;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_04 @ fffdadf5 (99 bytes)

/* Menu item 4.17.4 EXTENSION SETTING / SD CARD / INFORMATIONS */

void menuitem_int4_17_04(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 4;
  pcVar2 = 
  "INFORMATIONS         FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd880;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf87e;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_05 @ fffdae58 (99 bytes)

/* Menu item 4.17.5 EXTENSION SETTING / SD CARD / FIRMWARE UPDATE */

void menuitem_int4_17_05(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 5;
  pcVar2 = 
  "FIRMWARE UPDATE      FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd889;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf921;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_17_06 @ fffdaebb (99 bytes)

/* Menu item 4.17.6 EXTENSION SETTING / SD CARD / FORMAT */

void menuitem_int4_17_06(void)

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
  local_35 = 4;
  local_34 = 0x11;
  local_33 = 6;
  pcVar2 = 
  "FORMAT               SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CA..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd892;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf944;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_18_00 @ fffdaf1e (99 bytes)

/* Menu item 4.18.0 EXTENSION SETTING / SOFT VERSION / SOFTVERSION */

void menuitem_int4_18_00(void)

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
  local_35 = 4;
  local_34 = 0x12;
  local_33 = 0;
  pcVar2 = 
  "SOFTVERSION          CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd89b;
  local_18 = &DAT_fffd31e3;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_19_00 @ fffdaf81 (99 bytes)

/* Menu item 4.19.0 EXTENSION SETTING / CALIBRATION / CALIBRATION */

void menuitem_int4_19_00(void)

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
  local_35 = 4;
  local_34 = 0x13;
  local_33 = 0;
  pcVar2 = 
  "CALIBRATION          MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd96c;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcf9e7;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_20_00 @ fffdafe4 (99 bytes)

/* Menu item 4.20.0 EXTENSION SETTING / RESET / MEMORY CLEAR */

void menuitem_int4_20_00(void)

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
  local_35 = 4;
  local_34 = 0x14;
  local_33 = 0;
  pcVar2 = 
  "MEMORY CLEAR         MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd975;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcfa17;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_20_01 @ fffdb047 (99 bytes)

/* Menu item 4.20.1 EXTENSION SETTING / RESET / MENU CLEAR */

void menuitem_int4_20_01(void)

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
  local_35 = 4;
  local_34 = 0x14;
  local_33 = 1;
  pcVar2 = 
  "MENU CLEAR           ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U5015025035045055..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd97e;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcfa74;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_20_02 @ fffdb0aa (99 bytes)

/* Menu item 4.20.2 EXTENSION SETTING / RESET / ALL RESET */

void menuitem_int4_20_02(void)

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
  local_35 = 4;
  local_34 = 0x14;
  local_33 = 2;
  pcVar2 = 
  "ALL RESET            CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U5015025035045055065075085095105115125..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd987;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffcfa83;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_int4_21_00 @ fffdb10d (99 bytes)

/* Menu item 4.21.0 EXTENSION SETTING / CERTIFICATION / CERTIFICATION */

void menuitem_int4_21_00(void)

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
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38 = 1;
  local_37 = 2;
  local_36 = 0;
  local_35 = 4;
  local_34 = 0x15;
  local_33 = 0;
  pcVar2 = 
  "CERTIFICATION        PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffcd990;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3cd5;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060101 @ fffdb170 (108 bytes)

/* Menu item 5.22.0 PRESET / PRESET1 / PRESET NAME */

void menuitem_EX060101(void)

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
  local_35 = 5;
  local_34 = 0x16;
  local_33 = 0;
  pcVar2 = 
  "PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1be4;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3172;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b2e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}

