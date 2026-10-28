// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX060316 @ fffdc6fc (109 bytes)

/* Menu item 5.24.15 PRESET / PRESET3 / USB MOD GAIN */

void menuitem_EX060316(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0xf;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2da9;
  local_18 = &LAB_fffd3ad3;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b86;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060317 @ fffdc769 (109 bytes)

/* Menu item 5.24.16 PRESET / PRESET3 / REAR MOD GAIN */

void menuitem_EX060317(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0x10;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2ec0;
  local_18 = &LAB_fffd3b76;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b87;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060318 @ fffdc7d6 (109 bytes)

/* Menu item 5.24.17 PRESET / PRESET3 / RPTT SELECT */

void menuitem_EX060318(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_33 = 0x11;
  pcVar2 = 
  "RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2fd7;
  local_18 = &LAB_fffd3c19;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b88;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060401 @ fffdc843 (109 bytes)

/* Menu item 5.25.0 PRESET / PRESET4 / PRESET NAME */

void menuitem_EX060401(void)

{
  char *pcVar1;
  char *pcVar2;
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
  local_34 = 0x19;
  local_33 = 0;
  pcVar2 = 
  "PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1c0b;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3172;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b8b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060402 @ fffdc8b0 (109 bytes)

/* Menu item 5.25.1 PRESET / PRESET4 / CAT-1 RATE */

void menuitem_EX060402(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 1;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1d6c;
  local_18 = &LAB_fffd31f6;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b97;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060403 @ fffdc91d (109 bytes)

/* Menu item 5.25.2 PRESET / PRESET4 / CAT-1 TIME OUT TIMER */

void menuitem_EX060403(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 2;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1e97;
  local_18 = &LAB_fffd3298;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b98;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060404 @ fffdc98a (109 bytes)

/* Menu item 5.25.3 PRESET / PRESET4 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060404(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 3;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1fc3;
  local_18 = &LAB_fffd333a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b99;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060405 @ fffdc9f7 (109 bytes)

/* Menu item 5.25.4 PRESET / PRESET4 / AGC FAST DELAY */

void menuitem_EX060405(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 4;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd20ee;
  local_18 = &LAB_fffd33dc;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9a;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060406 @ fffdca64 (109 bytes)

/* Menu item 5.25.5 PRESET / PRESET4 / AGC MID DELAY */

void menuitem_EX060406(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 5;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd221f;
  local_18 = &LAB_fffd347f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9b;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060407 @ fffdcad1 (109 bytes)

/* Menu item 5.25.6 PRESET / PRESET4 / AGC SLOW DELAY */

void menuitem_EX060407(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 6;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2351;
  local_18 = &LAB_fffd3522;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9c;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060408 @ fffdcb3e (109 bytes)

/* Menu item 5.25.7 PRESET / PRESET4 / LCUT FREQ */

void menuitem_EX060408(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 7;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2483;
  local_18 = &LAB_fffd35c5;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b9d;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060409 @ fffdcbab (109 bytes)

/* Menu item 5.25.8 PRESET / PRESET4 / LCUT SLOPE */

void menuitem_EX060409(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 8;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd25af;
  local_18 = &LAB_fffd3668;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b9e;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060410 @ fffdcc18 (109 bytes)

/* Menu item 5.25.9 PRESET / PRESET4 / HCUT FREQ */

void menuitem_EX060410(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 9;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd26da;
  local_18 = &LAB_fffd370a;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b9f;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060411 @ fffdcc85 (109 bytes)

/* Menu item 5.25.10 PRESET / PRESET4 / HCUT SLOPE */

void menuitem_EX060411(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 10;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2807;
  local_18 = &LAB_fffd37ad;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ba0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060412 @ fffdccf2 (109 bytes)

/* Menu item 5.25.11 PRESET / PRESET4 / USB OUT LEVEL */

void menuitem_EX060412(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0xb;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2932;
  local_18 = &LAB_fffd384f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba1;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060413 @ fffdcd5f (109 bytes)

/* Menu item 5.25.12 PRESET / PRESET4 / REAR OUT LEVEL */

void menuitem_EX060413(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0xc;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2a49;
  local_18 = &LAB_fffd38f2;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba2;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060414 @ fffdcdcc (109 bytes)

/* Menu item 5.25.13 PRESET / PRESET4 / TX BPF SEL */

void menuitem_EX060414(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0xd;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2b60;
  local_18 = &LAB_fffd3995;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ba3;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060415 @ fffdce39 (109 bytes)

/* Menu item 5.25.14 PRESET / PRESET4 / MOD SOURCE */

void menuitem_EX060415(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0xe;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2c8b;
  local_18 = &LAB_fffd3a37;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ba4;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060416 @ fffdcea6 (109 bytes)

/* Menu item 5.25.15 PRESET / PRESET4 / USB MOD GAIN */

void menuitem_EX060416(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0xf;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2db6;
  local_18 = &LAB_fffd3ad9;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba5;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060417 @ fffdcf13 (109 bytes)

/* Menu item 5.25.16 PRESET / PRESET4 / REAR MOD GAIN */

void menuitem_EX060417(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0x10;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2ecd;
  local_18 = &LAB_fffd3b7c;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba6;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060418 @ fffdcf80 (109 bytes)

/* Menu item 5.25.17 PRESET / PRESET4 / RPTT SELECT */

void menuitem_EX060418(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x19;
  local_33 = 0x11;
  pcVar2 = 
  "RPTT SELECT          PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2fe4;
  local_18 = &LAB_fffd3c1f;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ba7;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060501 @ fffdcfed (109 bytes)

/* Menu item 5.26.0 PRESET / PRESET5 / PRESET NAME */

void menuitem_EX060501(void)

{
  char *pcVar1;
  char *pcVar2;
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
  local_34 = 0x1a;
  local_33 = 0;
  pcVar2 = 
  "PRESET NAME          CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1c18;
  local_18 = &DAT_fffd31e3;
  local_14 = &LAB_fffd3172;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009baa;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060502 @ fffdd05a (109 bytes)

/* Menu item 5.26.1 PRESET / PRESET5 / CAT-1 RATE */

void menuitem_EX060502(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 1;
  pcVar2 = 
  "CAT-1 RATE           CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1d79;
  local_18 = &LAB_fffd31fc;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bb6;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060503 @ fffdd0c7 (109 bytes)

/* Menu item 5.26.2 PRESET / PRESET5 / CAT-1 TIME OUT TIMER */

void menuitem_EX060503(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 2;
  pcVar2 = 
  "CAT-1 TIME OUT TIMER CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1ea4;
  local_18 = &LAB_fffd329e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bb7;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060504 @ fffdd134 (109 bytes)

/* Menu item 5.26.3 PRESET / PRESET5 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060504(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 3;
  pcVar2 = 
  "CAT-1 CAT-3 STOP BIT AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd1fd0;
  local_18 = &LAB_fffd3340;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bb8;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060505 @ fffdd1a1 (109 bytes)

/* Menu item 5.26.4 PRESET / PRESET5 / AGC FAST DELAY */

void menuitem_EX060505(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 4;
  pcVar2 = 
  "AGC FAST DELAY       AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd20fb;
  local_18 = &LAB_fffd33e2;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009bb9;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060506 @ fffdd20e (109 bytes)

/* Menu item 5.26.5 PRESET / PRESET5 / AGC MID DELAY */

void menuitem_EX060506(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 5;
  pcVar2 = 
  "AGC MID DELAY        AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd222c;
  local_18 = &LAB_fffd3485;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009bba;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060507 @ fffdd27b (109 bytes)

/* Menu item 5.26.6 PRESET / PRESET5 / AGC SLOW DELAY */

void menuitem_EX060507(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 6;
  pcVar2 = 
  "AGC SLOW DELAY       LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd235e;
  local_18 = &LAB_fffd3528;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009bbb;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060508 @ fffdd2e8 (109 bytes)

/* Menu item 5.26.7 PRESET / PRESET5 / LCUT FREQ */

void menuitem_EX060508(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 7;
  pcVar2 = 
  "LCUT FREQ            LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2490;
  local_18 = &LAB_fffd35cb;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009bbc;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060509 @ fffdd355 (109 bytes)

/* Menu item 5.26.8 PRESET / PRESET5 / LCUT SLOPE */

void menuitem_EX060509(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 8;
  pcVar2 = 
  "LCUT SLOPE           HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd25bc;
  local_18 = &LAB_fffd366e;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bbd;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060510 @ fffdd3c2 (109 bytes)

/* Menu item 5.26.9 PRESET / PRESET5 / HCUT FREQ */

void menuitem_EX060510(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 9;
  pcVar2 = 
  "HCUT FREQ            HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd26e7;
  local_18 = &LAB_fffd3710;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009bbe;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060511 @ fffdd42f (109 bytes)

/* Menu item 5.26.10 PRESET / PRESET5 / HCUT SLOPE */

void menuitem_EX060511(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 10;
  pcVar2 = 
  "HCUT SLOPE           USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2814;
  local_18 = &LAB_fffd37b3;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bbf;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060512 @ fffdd49c (109 bytes)

/* Menu item 5.26.11 PRESET / PRESET5 / USB OUT LEVEL */

void menuitem_EX060512(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0xb;
  pcVar2 = 
  "USB OUT LEVEL        REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd293f;
  local_18 = &LAB_fffd3855;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009bc0;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060513 @ fffdd509 (109 bytes)

/* Menu item 5.26.12 PRESET / PRESET5 / REAR OUT LEVEL */

void menuitem_EX060513(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0xc;
  pcVar2 = 
  "REAR OUT LEVEL       TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2a56;
  local_18 = &LAB_fffd38f8;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009bc1;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060514 @ fffdd576 (109 bytes)

/* Menu item 5.26.13 PRESET / PRESET5 / TX BPF SEL */

void menuitem_EX060514(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0xd;
  pcVar2 = 
  "TX BPF SEL           MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2b6d;
  local_18 = &LAB_fffd399b;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bc2;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060515 @ fffdd5e3 (109 bytes)

/* Menu item 5.26.14 PRESET / PRESET5 / MOD SOURCE */

void menuitem_EX060515(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0xe;
  pcVar2 = 
  "MOD SOURCE           USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2c98;
  local_18 = &LAB_fffd3a3d;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bc3;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060516 @ fffdd650 (109 bytes)

/* Menu item 5.26.15 PRESET / PRESET5 / USB MOD GAIN */

void menuitem_EX060516(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0xf;
  pcVar2 = 
  "USB MOD GAIN         REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2dc3;
  local_18 = &LAB_fffd3adf;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009bc4;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060517 @ fffdd6bd (109 bytes)

/* Menu item 5.26.16 PRESET / PRESET5 / REAR MOD GAIN */

void menuitem_EX060517(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0x10;
  pcVar2 = 
  "REAR MOD GAIN        RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2eda;
  local_18 = &LAB_fffd3b82;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009bc5;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX060518 @ fffdd72a (109 bytes)

/* Menu item 5.26.17 PRESET / PRESET5 / RPTT SELECT */

void menuitem_EX060518(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  local_34 = 0x1a;
  local_33 = 0x11;
  pcVar2 = 
  "RPTT SELECT          12735D4B8CAF69EF01253F11FP1LP1UP2LP2UP3LP3UP4LP4UP5LP5UP6LP6UP7LP7UP8LP8UP9LP9U501502503504505506507508509510511512513514515EMG"
  ;
  pcVar1 = acStack_32;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  local_1c = &LAB_fffd2ff1;
  local_18 = &LAB_fffd3c25;
  local_14 = &DAT_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009bc6;
  local_3 = 0;
  menu_register(&local_38);
  return;
}


// ===== cat_ai_poll @ fffdd797 (979 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdd814) */
/* Auto-information broadcaster: runs ~70 change detectors, sends one changed item to every port
   with AI on (0x20B20..22) */

void cat_ai_poll(void)

{
  bool bVar1;
  int iVar2;
  short local_2;
  
  if ((DAT_00020b20 == '\x01') || (DAT_00020b21 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b22 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = FUN_fffb1d79(1);
    if ((iVar2 == 0) && (iVar2 = FUN_fffb1d79(2), iVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (iVar2 = FUN_fffb1d79(3), iVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_2 = FUN_fffddcb5();
      if (local_2 == 0) {
        local_2 = FUN_fffdde79();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffddfc3();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde064(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde064(2);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde180();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde263();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde332();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde3f1();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde58a(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde58a(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde887();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde9a8();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdebd1();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdec32();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdecec();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffded19();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdee2c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdee96();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdef13();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf13a(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf13a(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf66f();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf7b3();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf85c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf8d4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf981();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf9ec(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf9ec(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfae4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfbe4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfd36();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfda4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfe0a();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfe7a();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfee6();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdff9c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0016();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe00be();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0143();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe024b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe02f4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0394();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe040b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe057b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0839();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe08c7();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0a60();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0aff();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0ba1(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0ba1(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0d06();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0e99();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(2);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(3);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(4);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(5);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(6);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(7);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6(8);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1447();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe14b4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1523();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1596();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe165d();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1774();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe170a();
      }
      if (local_2 == 0) {
        local_2 = cat_ai_FD();
      }
      if (DAT_000187c2 == '\x01') {
        iVar2 = swtimer_expired(0x32);
        if (iVar2 != 1) {
          return;
        }
        DAT_000187c2 = '\0';
      }
      if (local_2 != 0) {
        if (DAT_00020b20 == '\x01') {
          cat_send_reply(1,&DAT_00015e06,local_2);
        }
        if (DAT_00020b21 == '\x01') {
          cat_send_reply(2,&DAT_00015e06,local_2);
        }
        if (DAT_00020b22 == '\x01') {
          cat_send_reply(3,&DAT_00015e06,local_2);
          return;
        }
      }
    }
  }
  return;
}


// ===== cat_ai_holdoff @ fffddb6a (20 bytes)

/* Arms timer 0x32 (200 ms) and 0x187C2 to hold off the next AI frame after a CAT set */

void cat_ai_holdoff(void)

{
  swtimer_start(0x32,200);
  DAT_000187c2 = 1;
  return;
}


// ===== cat_ai_FD @ fffddb7e (311 bytes)

/* WARNING: Removing unreachable block (ram,0xfffddcb2) */
/* WARNING: Removing unreachable block (ram,0xfffddc73) */
/* AI detector for the undocumented FD command (FD00n + 9 digits) */

ushort cat_ai_FD(void)

{
  bool bVar1;
  undefined1 uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort uStack_26;
  char acStack_23 [4];
  undefined1 uStack_1f;
  undefined1 auStack_1e [9];
  undefined1 uStack_15;
  undefined1 uStack_13;
  byte bStack_12;
  undefined1 uStack_11;
  uint uStack_10;
  uint uStack_c;
  
  vfo_freq(0,2);
  uStack_11 = band_of_freq();
  pcVar4 = "FD000000000000;";
  pcVar3 = acStack_23;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar3 = *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  }
  uStack_26 = 0;
  if (DAT_00020b3d == '\x01') {
    uStack_c = DAT_00020f50;
  }
  else if (DAT_00009c35 == 0) {
    uStack_c = DAT_00020f5c;
    uStack_1f = 0x30;
  }
  else if (DAT_00009c35 == 1) {
    uStack_c = DAT_00020f60;
    uStack_1f = 0x31;
  }
  else {
    uStack_c = bandmem_get(2);
    uStack_1f = 0x32;
  }
  if ((DAT_00025cec == uStack_c) && (DAT_00009c35 == DAT_00025cf0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00025cec = uStack_c;
    DAT_00025cf0 = (uint)DAT_00009c35;
    uStack_10 = 100000000;
    for (bStack_12 = 0; bStack_12 < 9; bStack_12 = bStack_12 + 1) {
      uVar6 = uStack_c;
      if (uStack_10 != 0) {
        uVar6 = uStack_c / uStack_10;
      }
      uStack_13 = (undefined1)uVar6;
      uVar7 = uStack_c;
      if ((uStack_10 & 0xff) != 0) {
        uVar7 = uStack_c / (uStack_10 & 0xff);
      }
      uStack_c = uStack_c - (uVar7 * uStack_10 & 0xff);
      uStack_10 = uStack_10 / 10;
      uVar7 = (uint)bStack_12;
      uVar2 = nib2hex(uVar6 & 0xff);
      auStack_1e[uVar7] = uVar2;
    }
    uStack_15 = 0x3b;
    uStack_26 = 0xf;
  }
  if (uStack_26 != 0) {
    pcVar4 = acStack_23;
    pcVar3 = &DAT_00015e06;
    for (uVar6 = (uint)uStack_26; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  return uStack_26;
}


// ===== FUN_fffddcb5 @ fffddcb5 (452 bytes)

undefined2 FUN_fffddcb5(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 local_12;
  char local_f [7];
  char local_8;
  char local_7;
  char local_6;
  char local_5;
  undefined2 local_4;
  
  local_4 = 0;
  local_5 = DAT_00009ab8;
  local_6 = DAT_00020b41;
  local_7 = DAT_00020b40;
  local_8 = DAT_00020f0c;
  local_f[6] = DAT_00020b3c;
  local_f[0] = 'A';
  local_f[1] = 'C';
  local_f[2] = '0';
  local_f[4] = '0';
  local_f[5] = ';';
  if ((DAT_000187c3 == DAT_00009ab8) && (DAT_000187c4 == DAT_00020b41)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c5 == DAT_00020b40)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c6 == DAT_00020f0c)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c7 == DAT_00020b3c)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c8 == DAT_00020b3f)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_12 = 0;
  }
  else {
    DAT_000187c3 = DAT_00009ab8;
    DAT_000187c4 = DAT_00020b41;
    DAT_000187c5 = DAT_00020b40;
    DAT_000187c6 = DAT_00020f0c;
    DAT_000187c7 = DAT_00020b3c;
    DAT_000187c8 = DAT_00020b3f;
    if (DAT_00009ab8 == '\x03') {
      local_f[3] = 0x32;
      if (DAT_00020f0c == '\x01') {
        local_f[4] = 0x33;
      }
      else if (DAT_00020f0c == '\x02') {
        if (DAT_00020b3c == '\x02') {
          local_f[4] = 0x31;
        }
        else if (DAT_00020b3c == '\x03') {
          local_f[4] = 0x32;
        }
        else {
          local_f[4] = 0x30;
        }
      }
      else {
        local_f[4] = 0x30;
      }
    }
    else {
      local_f[3] = 0x30;
      if ((DAT_00020b41 == '\x02') || (DAT_00020b40 == '\x02')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_f[4] = 0x33;
      }
      else {
        iVar2 = FUN_fffec55a();
        if (iVar2 == 1) {
          local_f[4] = 0x31;
        }
        else {
          local_f[4] = 0x30;
        }
      }
    }
    iVar2 = FUN_fffede1d(&DAT_0001b504,local_f,6);
    if (iVar2 != 0) {
      local_4 = 6;
      pcVar4 = local_f;
      pcVar3 = &DAT_00015e06;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pcVar3 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
      pcVar4 = local_f;
      pcVar3 = &DAT_0001b504;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pcVar3 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
    }
    local_12 = local_4;
  }
  return local_12;
}


// ===== FUN_fffdde79 @ fffdde79 (330 bytes)

/* WARNING: Removing unreachable block (ram,0xfffddfc0) */
/* WARNING: Removing unreachable block (ram,0xfffddf89) */

undefined2 FUN_fffdde79(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char local_11 [8];
  byte local_9;
  byte local_8;
  byte local_7;
  
  bVar3 = DAT_00020ba8;
  local_11[7] = DAT_00020ba8;
  builtin_strncpy(local_11,"AG0000;",7);
  if (DAT_000187c9 == DAT_00020ba8) {
    return 0;
  }
  DAT_000187c9 = DAT_00020ba8;
  DAT_0001b50a = DAT_0001b50a + 1;
  if (3 < DAT_0001b50a) {
    DAT_0001b50a = 0;
  }
  (&DAT_0001b53e)[DAT_0001b50a] = DAT_00020ba8;
  if ((bVar3 < 3) || (0xfc < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    if ((DAT_0001b53e == DAT_0001b540) || (DAT_0001b53f == DAT_0001b541)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      return 0;
    }
    bVar3 = FUN_fffe1805(&DAT_0001b53e);
    bVar4 = FUN_fffe1839(&DAT_0001b53e);
    if ((int)((uint)bVar3 - (uint)bVar4) < 3) {
      return 0;
    }
  }
  local_8 = 100;
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    local_7 = local_11[7];
    if (local_8 != 0) {
      local_7 = (byte)local_11[7] / local_8;
    }
    local_11[7] = local_11[7] - local_7 * local_8;
    local_8 = local_8 / 10;
    uVar1 = (uint)local_9;
    cVar5 = nib2hex(local_7);
    local_11[uVar1 + 3] = cVar5;
  }
  pcVar7 = local_11;
  pcVar6 = &DAT_00015e06;
  for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pcVar6 = *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return 7;
}


// ===== FUN_fffddfc3 @ fffddfc3 (161 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde061) */
/* WARNING: Removing unreachable block (ram,0xfffde02b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffddfc3(void)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 local_12;
  undefined4 local_10;
  undefined2 local_c;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_a = DAT_00009bf2;
  local_10 = 0x30304f41;
  local_c = 0x3b30;
  if (DAT_000187ca == DAT_00009bf2) {
    local_12 = 0;
  }
  else {
    DAT_000187ca = DAT_00009bf2;
    local_8 = 100;
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      local_7 = local_a;
      if (local_8 != 0) {
        local_7 = local_a / local_8;
      }
      local_a = local_a - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      uVar2 = nib2hex(local_7);
      *(undefined1 *)((int)&local_10 + uVar1 + 2) = uVar2;
    }
    DAT_00015e0a = local_c;
    _DAT_00015e06 = local_10;
    local_12 = 6;
  }
  return local_12;
}


// ===== FUN_fffde064 @ fffde064 (284 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde17d) */
/* WARNING: Removing unreachable block (ram,0xfffde0e7) */

ushort FUN_fffde064(char param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char local_15 [7];
  ushort local_e;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  char local_5;
  
  local_5 = param_1;
  local_e = 0;
  builtin_strncpy(local_15,"AS0000;",7);
  if (param_1 == '\x01') {
    pcVar2 = (char *)FUN_fffb54a0();
    bStack_9 = *pcVar2;
    if (DAT_000187cb != bStack_9) {
      local_15[2] = 0x31;
      bStack_a = bStack_9 * '\x05';
      bStack_b = 100;
      DAT_000187cb = bStack_9;
      for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
        bStack_9 = bStack_a;
        if (bStack_b != 0) {
          bStack_9 = bStack_a / bStack_b;
        }
        bStack_a = bStack_a - bStack_9 * bStack_b;
        bStack_b = bStack_b / 10;
        uVar4 = (uint)bStack_c;
        cVar1 = nib2hex(bStack_9);
        local_15[uVar4 + 3] = cVar1;
      }
      local_e = 7;
    }
  }
  else if (param_1 == '\x02') {
    pcVar2 = (char *)FUN_fffb552c();
    bStack_9 = *pcVar2;
    if (DAT_000187cc != bStack_9) {
      local_15[2] = 0x32;
      if (bStack_9 == '\0') {
        local_15[3] = 0x30;
        local_15[4] = 0x30;
        local_15[5] = 0x31;
      }
      else if (bStack_9 == '\x01') {
        local_15[3] = 0x30;
        local_15[4] = 0x30;
        local_15[5] = 0x32;
      }
      local_e = 7;
      DAT_000187cc = bStack_9;
    }
  }
  if (local_e != 0) {
    pcVar3 = local_15;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_e; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return local_e;
}


// ===== FUN_fffde180 @ fffde180 (227 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde260) */
/* WARNING: Removing unreachable block (ram,0xfffde226) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde180(void)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined2 local_1a;
  undefined4 local_17;
  undefined2 local_13;
  byte local_11;
  byte local_10;
  byte local_f;
  byte local_e;
  char local_d;
  undefined1 *local_c;
  
  local_c = &DAT_00009bca;
  local_d = DAT_00009af3;
  local_17 = 0x30305641;
  local_13 = 0x3b30;
  if (DAT_00009af3 == '\0') {
    local_11 = DAT_00009bf6;
  }
  else {
    local_11 = DAT_00009bf7;
  }
  if ((DAT_000187cd == DAT_00009af3) && (DAT_000187ce == local_11)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_1a = 0;
  }
  else {
    DAT_000187cd = DAT_00009af3;
    DAT_000187ce = local_11;
    local_f = 100;
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      local_e = local_11;
      if (local_f != 0) {
        local_e = local_11 / local_f;
      }
      local_11 = local_11 - local_e * local_f;
      local_f = local_f / 10;
      uVar1 = (uint)local_10;
      uVar3 = nib2hex(local_e);
      *(undefined1 *)((int)&local_17 + uVar1 + 2) = uVar3;
    }
    DAT_00015e0a = local_13;
    _DAT_00015e06 = local_17;
    local_1a = 6;
  }
  return local_1a;
}


// ===== FUN_fffde263 @ fffde263 (207 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde263(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined2 uStack_12;
  undefined4 uStack_f;
  byte bStack_a;
  
  iVar3 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uVar1 = (uint)bVar2;
  if (uVar1 - 2 < 2) {
    bStack_a = *(byte *)(iVar3 + 0x15);
  }
  else if (uVar1 - 4 < 2) {
    bStack_a = *(byte *)(iVar3 + 0x33);
  }
  else {
    if (uVar1 - 6 < 2) {
      return 0;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) {
        return 0;
      }
      if (uVar1 - 0xc < 2) {
        bStack_a = *(byte *)(iVar3 + 0x1f);
        goto LAB_fffde2eb;
      }
      if (uVar1 != 0xe) {
        bStack_a = *(byte *)(iVar3 + 0xb);
        goto LAB_fffde2eb;
      }
    }
    bStack_a = *(byte *)(iVar3 + 0x29);
  }
LAB_fffde2eb:
  bStack_a = bStack_a & 0x80;
  if (DAT_000187cf == bStack_a) {
    uStack_12 = 0;
  }
  else {
    if (bStack_a == 0) {
      uStack_f = 0x30304342;
    }
    else {
      uStack_f = 0x31304342;
    }
    DAT_00015e0a._0_1_ = ';';
    _DAT_00015e06 = uStack_f;
    uStack_12 = 5;
    DAT_000187cf = bStack_a;
  }
  return uStack_12;
}


// ===== FUN_fffde332 @ fffde332 (191 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde332(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined2 uStack_10;
  undefined4 uStack_e;
  byte bStack_a;
  
  iVar3 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uVar1 = (uint)bVar2;
  if (uVar1 - 2 < 2) {
    bStack_a = *(byte *)(iVar3 + 0x14);
  }
  else if (uVar1 - 4 < 2) {
    bStack_a = *(byte *)(iVar3 + 0x32);
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        return 0;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return 0;
        }
        if (uVar1 == 0xe) {
          return 0;
        }
        bStack_a = *(byte *)(iVar3 + 10);
        goto LAB_fffde3b1;
      }
    }
    bStack_a = *(byte *)(iVar3 + 0x3c);
  }
LAB_fffde3b1:
  bStack_a = bStack_a & 2;
  if (DAT_000187d0 == bStack_a) {
    uStack_10 = 0;
  }
  else {
    if (bStack_a == 0) {
      uStack_e._0_3_ = 0x304942;
    }
    else {
      uStack_e._0_3_ = 0x314942;
    }
    uStack_e = CONCAT13(';',(undefined3)uStack_e);
    _DAT_00015e06 = uStack_e;
    uStack_10 = 4;
    DAT_000187d0 = bStack_a;
  }
  return uStack_10;
}


// ===== FUN_fffde3f1 @ fffde3f1 (409 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde587) */
/* WARNING: Removing unreachable block (ram,0xfffde4d5) */
/* WARNING: Removing unreachable block (ram,0xfffde54d) */

ushort FUN_fffde3f1(void)

{
  uint uVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  uint uVar5;
  ushort uVar6;
  char acStack_20 [8];
  ushort uStack_18;
  ushort uStack_16;
  undefined1 uStack_13;
  undefined1 uStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  undefined1 uStack_e;
  byte bStack_d;
  int iStack_c;
  
  iStack_c = vfo_rec_ptr(0);
  bStack_d = vfo_mode(0);
  uStack_18 = 0;
  builtin_strncpy(acStack_20,"BP00000;",8);
  uVar5 = (uint)bStack_d;
  if (uVar5 - 2 < 2) {
    bStack_f = *(byte *)(iStack_c + 0x14);
    uStack_13 = *(undefined1 *)(iStack_c + 0x18);
    uStack_12 = *(undefined1 *)(iStack_c + 0x19);
    goto LAB_fffde4d3;
  }
  if (uVar5 - 4 < 2) {
    bStack_f = *(byte *)(iStack_c + 0x32);
    uStack_13 = *(undefined1 *)(iStack_c + 0x36);
    uStack_12 = *(undefined1 *)(iStack_c + 0x37);
    goto LAB_fffde4d3;
  }
  if (uVar5 - 6 < 2) {
LAB_fffde4c1:
    bStack_f = *(byte *)(iStack_c + 0x3c);
    uStack_13 = *(undefined1 *)(iStack_c + 0x40);
    uStack_12 = *(undefined1 *)(iStack_c + 0x41);
  }
  else {
    if (1 < uVar5 - 8) {
      if (uVar5 - 10 < 2) goto LAB_fffde4c1;
      if (uVar5 - 0xc < 2) {
        bStack_f = *(byte *)(iStack_c + 0x1e);
        uStack_13 = *(undefined1 *)(iStack_c + 0x22);
        uStack_12 = *(undefined1 *)(iStack_c + 0x23);
        goto LAB_fffde4d3;
      }
      if (uVar5 != 0xe) {
        bStack_f = *(byte *)(iStack_c + 10);
        uStack_13 = *(undefined1 *)(iStack_c + 0xe);
        uStack_12 = *(undefined1 *)(iStack_c + 0xf);
        goto LAB_fffde4d3;
      }
    }
    bStack_f = *(byte *)(iStack_c + 0x28);
    uStack_13 = *(undefined1 *)(iStack_c + 0x2c);
    uStack_12 = *(undefined1 *)(iStack_c + 0x2d);
  }
LAB_fffde4d3:
  uStack_16 = CONCAT11(uStack_13,uStack_12);
  if (DAT_000187d1 == (bStack_f & 0x80)) {
    if (DAT_0001ff06 != uStack_16) {
      acStack_20[2] = 0x30;
      acStack_20[3] = 0x31;
      bStack_10 = 100;
      DAT_0001ff06 = uStack_16;
      for (bStack_11 = 0; bStack_11 < 3; bStack_11 = bStack_11 + 1) {
        uVar5 = (uint)uStack_16;
        if (bStack_10 != 0) {
          uVar5 = uVar5 / bStack_10;
        }
        uStack_e = (undefined1)uVar5;
        uVar6 = uStack_16;
        if (bStack_10 != 0) {
          uVar6 = uStack_16 / bStack_10;
        }
        uStack_16 = uStack_16 - (uVar6 * bStack_10 & 0xff);
        bStack_10 = bStack_10 / 10;
        uVar1 = (uint)bStack_11;
        cVar2 = nib2hex(uVar5 & 0xff);
        acStack_20[uVar1 + 4] = cVar2;
      }
      uStack_18 = 8;
    }
  }
  else {
    acStack_20[2] = 0x30;
    DAT_000187d1 = bStack_f & 0x80;
    if ((bStack_f & 0x80) == 0) {
      acStack_20[6] = 0x30;
    }
    else {
      acStack_20[6] = 0x31;
    }
    uStack_18 = 8;
  }
  pcVar4 = acStack_20;
  if (uStack_18 != 0) {
    puVar3 = &DAT_00015e06;
    for (uVar5 = (uint)uStack_18; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *pcVar4;
      puVar3 = puVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  return uStack_18;
}

