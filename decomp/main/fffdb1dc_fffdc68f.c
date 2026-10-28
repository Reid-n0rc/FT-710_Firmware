// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX060102 @ fffdb1dc (108 bytes)

/* Menu item 5.22.1 PRESET / PRESET1 / CAT-1 RATE */

void menuitem_EX060102(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 1;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1d45;
  local_18 = &LAB_fffd31e4;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b3a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060103 @ fffdb248 (108 bytes)

/* Menu item 5.22.2 PRESET / PRESET1 / CAT-1 TIME OUT TIMER */

void menuitem_EX060103(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 2;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1e70;
  local_18 = &LAB_fffd3286;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b3b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060104 @ fffdb2b4 (108 bytes)

/* Menu item 5.22.3 PRESET / PRESET1 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060104(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 3;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1f9c;
  local_18 = &LAB_fffd3328;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b3c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060105 @ fffdb320 (108 bytes)

/* Menu item 5.22.4 PRESET / PRESET1 / AGC FAST DELAY */

void menuitem_EX060105(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 4;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd20c7;
  local_18 = &LAB_fffd33ca;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b3d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060106 @ fffdb38c (108 bytes)

/* Menu item 5.22.5 PRESET / PRESET1 / AGC MID DELAY */

void menuitem_EX060106(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 5;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd21f8;
  local_18 = &LAB_fffd346d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b3e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060107 @ fffdb3f8 (108 bytes)

/* Menu item 5.22.6 PRESET / PRESET1 / AGC SLOW DELAY */

void menuitem_EX060107(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 6;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd232a;
  local_18 = &LAB_fffd3510;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b3f;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060108 @ fffdb464 (108 bytes)

/* Menu item 5.22.7 PRESET / PRESET1 / LCUT FREQ */

void menuitem_EX060108(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 7;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd245c;
  local_18 = &LAB_fffd35b3;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b40;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060109 @ fffdb4d0 (108 bytes)

/* Menu item 5.22.8 PRESET / PRESET1 / LCUT SLOPE */

void menuitem_EX060109(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 8;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2588;
  local_18 = &LAB_fffd3656;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b41;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060110 @ fffdb53c (108 bytes)

/* Menu item 5.22.9 PRESET / PRESET1 / HCUT FREQ */

void menuitem_EX060110(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 9;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd26b3;
  local_18 = &LAB_fffd36f8;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b42;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060111 @ fffdb5a8 (108 bytes)

/* Menu item 5.22.10 PRESET / PRESET1 / HCUT SLOPE */

void menuitem_EX060111(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 10;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd27e0;
  local_18 = &LAB_fffd379b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b43;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060112 @ fffdb614 (108 bytes)

/* Menu item 5.22.11 PRESET / PRESET1 / USB OUT LEVEL */

void menuitem_EX060112(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xb;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd290b;
  local_18 = &LAB_fffd383d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b44;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060113 @ fffdb680 (108 bytes)

/* Menu item 5.22.12 PRESET / PRESET1 / REAR OUT LEVEL */

void menuitem_EX060113(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xc;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2a22;
  local_18 = &LAB_fffd38e0;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b45;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060114 @ fffdb6ec (108 bytes)

/* Menu item 5.22.13 PRESET / PRESET1 / TX BPF SEL */

void menuitem_EX060114(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xd;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2b39;
  local_18 = &LAB_fffd3983;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b46;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060115 @ fffdb758 (108 bytes)

/* Menu item 5.22.14 PRESET / PRESET1 / MOD SOURCE */

void menuitem_EX060115(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xe;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2c64;
  local_18 = &LAB_fffd3a25;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b47;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060116 @ fffdb7c4 (108 bytes)

/* Menu item 5.22.15 PRESET / PRESET1 / USB MOD GAIN */

void menuitem_EX060116(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xf;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2d8f;
  local_18 = &LAB_fffd3ac7;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b48;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060117 @ fffdb830 (108 bytes)

/* Menu item 5.22.16 PRESET / PRESET1 / REAR MOD GAIN */

void menuitem_EX060117(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0x10;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2ea6;
  local_18 = &LAB_fffd3b6a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b49;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060118 @ fffdb89c (108 bytes)

/* Menu item 5.22.17 PRESET / PRESET1 / RPTT SELECT */

void menuitem_EX060118(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0x11;
  pcVar2 = 
  "RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2fbd;
  local_18 = &LAB_fffd3c0d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b4a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060201 @ fffdb908 (108 bytes)

/* Menu item 5.23.0 PRESET / PRESET2 / PRESET NAME */

void menuitem_EX060201(void)

{
  char *pcVar1;
  char *pcVar2;
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
  local_34 = 0x17;
  local_33 = 0;
  pcVar2 = 
  "PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1bf1;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3172;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b4d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060202 @ fffdb974 (108 bytes)

/* Menu item 5.23.1 PRESET / PRESET2 / CAT-1 RATE */

void menuitem_EX060202(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 1;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1d52;
  local_18 = &LAB_fffd31ea;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b59;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060203 @ fffdb9e0 (108 bytes)

/* Menu item 5.23.2 PRESET / PRESET2 / CAT-1 TIME OUT TIMER */

void menuitem_EX060203(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 2;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1e7d;
  local_18 = &LAB_fffd328c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b5a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060204 @ fffdba4c (108 bytes)

/* Menu item 5.23.3 PRESET / PRESET2 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060204(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 3;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1fa9;
  local_18 = &LAB_fffd332e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b5b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060205 @ fffdbab8 (108 bytes)

/* Menu item 5.23.4 PRESET / PRESET2 / AGC FAST DELAY */

void menuitem_EX060205(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 4;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd20d4;
  local_18 = &LAB_fffd33d0;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060206 @ fffdbb24 (108 bytes)

/* Menu item 5.23.5 PRESET / PRESET2 / AGC MID DELAY */

void menuitem_EX060206(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 5;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2205;
  local_18 = &LAB_fffd3473;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060207 @ fffdbb90 (108 bytes)

/* Menu item 5.23.6 PRESET / PRESET2 / AGC SLOW DELAY */

void menuitem_EX060207(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 6;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2337;
  local_18 = &LAB_fffd3516;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060208 @ fffdbbfc (108 bytes)

/* Menu item 5.23.7 PRESET / PRESET2 / LCUT FREQ */

void menuitem_EX060208(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 7;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2469;
  local_18 = &LAB_fffd35b9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b5f;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060209 @ fffdbc68 (108 bytes)

/* Menu item 5.23.8 PRESET / PRESET2 / LCUT SLOPE */

void menuitem_EX060209(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 8;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2595;
  local_18 = &LAB_fffd365c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b60;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060210 @ fffdbcd4 (108 bytes)

/* Menu item 5.23.9 PRESET / PRESET2 / HCUT FREQ */

void menuitem_EX060210(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 9;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd26c0;
  local_18 = &LAB_fffd36fe;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b61;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060211 @ fffdbd40 (108 bytes)

/* Menu item 5.23.10 PRESET / PRESET2 / HCUT SLOPE */

void menuitem_EX060211(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 10;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd27ed;
  local_18 = &LAB_fffd37a1;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b62;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060212 @ fffdbdac (108 bytes)

/* Menu item 5.23.11 PRESET / PRESET2 / USB OUT LEVEL */

void menuitem_EX060212(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0xb;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2918;
  local_18 = &LAB_fffd3843;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b63;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060213 @ fffdbe18 (108 bytes)

/* Menu item 5.23.12 PRESET / PRESET2 / REAR OUT LEVEL */

void menuitem_EX060213(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0xc;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2a2f;
  local_18 = &LAB_fffd38e6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b64;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060214 @ fffdbe84 (108 bytes)

/* Menu item 5.23.13 PRESET / PRESET2 / TX BPF SEL */

void menuitem_EX060214(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0xd;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2b46;
  local_18 = &LAB_fffd3989;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b65;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060215 @ fffdbef0 (108 bytes)

/* Menu item 5.23.14 PRESET / PRESET2 / MOD SOURCE */

void menuitem_EX060215(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0xe;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2c71;
  local_18 = &LAB_fffd3a2b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b66;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060216 @ fffdbf5c (108 bytes)

/* Menu item 5.23.15 PRESET / PRESET2 / USB MOD GAIN */

void menuitem_EX060216(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0xf;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2d9c;
  local_18 = &LAB_fffd3acd;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b67;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060217 @ fffdbfc8 (108 bytes)

/* Menu item 5.23.16 PRESET / PRESET2 / REAR MOD GAIN */

void menuitem_EX060217(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0x10;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2eb3;
  local_18 = &LAB_fffd3b70;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b68;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060218 @ fffdc034 (108 bytes)

/* Menu item 5.23.17 PRESET / PRESET2 / RPTT SELECT */

void menuitem_EX060218(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x17;
  local_33 = 0x11;
  pcVar2 = 
  "RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2fca;
  local_18 = &LAB_fffd3c13;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b69;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060301 @ fffdc0a0 (108 bytes)

/* Menu item 5.24.0 PRESET / PRESET3 / PRESET NAME */

void menuitem_EX060301(void)

{
  char *pcVar1;
  char *pcVar2;
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
  local_34 = 0x18;
  local_33 = 0;
  pcVar2 = 
  "PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1bfe;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3172;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b6c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060302 @ fffdc10c (108 bytes)

/* Menu item 5.24.1 PRESET / PRESET3 / CAT-1 RATE */

void menuitem_EX060302(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 1;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1d5f;
  local_18 = &LAB_fffd31f0;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b78;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060303 @ fffdc178 (108 bytes)

/* Menu item 5.24.2 PRESET / PRESET3 / CAT-1 TIME OUT TIMER */

void menuitem_EX060303(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 2;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1e8a;
  local_18 = &LAB_fffd3292;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b79;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060304 @ fffdc1e4 (108 bytes)

/* Menu item 5.24.3 PRESET / PRESET3 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060304(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 3;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1fb6;
  local_18 = &LAB_fffd3334;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b7a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060305 @ fffdc250 (108 bytes)

/* Menu item 5.24.4 PRESET / PRESET3 / AGC FAST DELAY */

void menuitem_EX060305(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 4;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd20e1;
  local_18 = &LAB_fffd33d6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060306 @ fffdc2bc (108 bytes)

/* Menu item 5.24.5 PRESET / PRESET3 / AGC MID DELAY */

void menuitem_EX060306(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 5;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2212;
  local_18 = &LAB_fffd3479;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060307 @ fffdc328 (108 bytes)

/* Menu item 5.24.6 PRESET / PRESET3 / AGC SLOW DELAY */

void menuitem_EX060307(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 6;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2344;
  local_18 = &LAB_fffd351c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060308 @ fffdc394 (109 bytes)

/* Menu item 5.24.7 PRESET / PRESET3 / LCUT FREQ */

void menuitem_EX060308(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 7;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2476;
  local_18 = &LAB_fffd35bf;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b7e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060309 @ fffdc401 (109 bytes)

/* Menu item 5.24.8 PRESET / PRESET3 / LCUT SLOPE */

void menuitem_EX060309(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 8;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd25a2;
  local_18 = &LAB_fffd3662;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b7f;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060310 @ fffdc46e (109 bytes)

/* Menu item 5.24.9 PRESET / PRESET3 / HCUT FREQ */

void menuitem_EX060310(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 9;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd26cd;
  local_18 = &LAB_fffd3704;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b80;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060311 @ fffdc4db (109 bytes)

/* Menu item 5.24.10 PRESET / PRESET3 / HCUT SLOPE */

void menuitem_EX060311(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 10;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd27fa;
  local_18 = &LAB_fffd37a7;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b81;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060312 @ fffdc548 (109 bytes)

/* Menu item 5.24.11 PRESET / PRESET3 / USB OUT LEVEL */

void menuitem_EX060312(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 0xb;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2925;
  local_18 = &LAB_fffd3849;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b82;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060313 @ fffdc5b5 (109 bytes)

/* Menu item 5.24.12 PRESET / PRESET3 / REAR OUT LEVEL */

void menuitem_EX060313(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 0xc;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2a3c;
  local_18 = &LAB_fffd38ec;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b83;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060314 @ fffdc622 (109 bytes)

/* Menu item 5.24.13 PRESET / PRESET3 / TX BPF SEL */

void menuitem_EX060314(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 0xd;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2b53;
  local_18 = &LAB_fffd398f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b84;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060315 @ fffdc68f (109 bytes)

/* Menu item 5.24.14 PRESET / PRESET3 / MOD SOURCE */

void menuitem_EX060315(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x18;
  local_33 = 0xe;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2c7e;
  local_18 = &LAB_fffd3a31;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b85;
  local_3 = 0;
  menu_register(&local_38);
  return;
}

