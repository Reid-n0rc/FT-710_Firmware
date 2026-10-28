// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX010207 @ fffd5e0b (108 bytes)

/* Menu item 0.1.6 RADIO SETTING / MODE AM / LCUT FREQ */

void menuitem_EX010207(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010208 @ fffd5e77 (108 bytes)

/* Menu item 0.1.7 RADIO SETTING / MODE AM / LCUT SLOPE */

void menuitem_EX010208(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010209 @ fffd5ee3 (108 bytes)

/* Menu item 0.1.8 RADIO SETTING / MODE AM / HCUT FREQ */

void menuitem_EX010209(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010210 @ fffd5f4f (108 bytes)

/* Menu item 0.1.9 RADIO SETTING / MODE AM / HCUT SLOPE */

void menuitem_EX010210(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010211 @ fffd5fbb (108 bytes)

/* Menu item 0.1.10 RADIO SETTING / MODE AM / USB OUT LEVEL */

void menuitem_EX010211(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010212 @ fffd6027 (108 bytes)

/* Menu item 0.1.11 RADIO SETTING / MODE AM / REAR OUT LEVEL */

void menuitem_EX010212(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010213 @ fffd6093 (108 bytes)

/* Menu item 0.1.12 RADIO SETTING / MODE AM / TX BPF SEL */

void menuitem_EX010213(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010214 @ fffd60ff (108 bytes)

/* Menu item 0.1.13 RADIO SETTING / MODE AM / MOD SOURCE */

void menuitem_EX010214(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010215 @ fffd616b (108 bytes)

/* Menu item 0.1.14 RADIO SETTING / MODE AM / USB MOD GAIN */

void menuitem_EX010215(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010216 @ fffd61d7 (108 bytes)

/* Menu item 0.1.15 RADIO SETTING / MODE AM / REAR MOD GAIN */

void menuitem_EX010216(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010217 @ fffd6243 (108 bytes)

/* Menu item 0.1.16 RADIO SETTING / MODE AM / RPTT SELECT */

void menuitem_EX010217(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010301 @ fffd62af (110 bytes)

/* Menu item 0.2.0 RADIO SETTING / MODE FM / AF TREBLE GAIN */

void menuitem_EX010301(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010302 @ fffd631d (110 bytes)

/* Menu item 0.2.1 RADIO SETTING / MODE FM / AF MIDDLE TONE GAIN */

void menuitem_EX010302(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010303 @ fffd638b (110 bytes)

/* Menu item 0.2.2 RADIO SETTING / MODE FM / AF BASS GAIN */

void menuitem_EX010303(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010304 @ fffd63f9 (108 bytes)

/* Menu item 0.2.3 RADIO SETTING / MODE FM / AGC FAST DELAY */

void menuitem_EX010304(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010305 @ fffd6465 (108 bytes)

/* Menu item 0.2.4 RADIO SETTING / MODE FM / AGC MID DELAY */

void menuitem_EX010305(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010306 @ fffd64d1 (108 bytes)

/* Menu item 0.2.5 RADIO SETTING / MODE FM / AGC SLOW DELAY */

void menuitem_EX010306(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010307 @ fffd653d (108 bytes)

/* Menu item 0.2.6 RADIO SETTING / MODE FM / LCUT FREQ */

void menuitem_EX010307(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010308 @ fffd65a9 (108 bytes)

/* Menu item 0.2.7 RADIO SETTING / MODE FM / LCUT SLOPE */

void menuitem_EX010308(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010309 @ fffd6615 (108 bytes)

/* Menu item 0.2.8 RADIO SETTING / MODE FM / HCUT FREQ */

void menuitem_EX010309(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010310 @ fffd6681 (108 bytes)

/* Menu item 0.2.9 RADIO SETTING / MODE FM / HCUT SLOPE */

void menuitem_EX010310(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010311 @ fffd66ed (108 bytes)

/* Menu item 0.2.10 RADIO SETTING / MODE FM / USB OUT LEVEL */

void menuitem_EX010311(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010312 @ fffd6759 (108 bytes)

/* Menu item 0.2.11 RADIO SETTING / MODE FM / REAR OUT LEVEL */

void menuitem_EX010312(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010313 @ fffd67c5 (108 bytes)

/* Menu item 0.2.12 RADIO SETTING / MODE FM / MOD SOURCE */

void menuitem_EX010313(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010314 @ fffd6831 (108 bytes)

/* Menu item 0.2.13 RADIO SETTING / MODE FM / USB MOD GAIN */

void menuitem_EX010314(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010315 @ fffd689d (108 bytes)

/* Menu item 0.2.14 RADIO SETTING / MODE FM / REAR MOD GAIN */

void menuitem_EX010315(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010316 @ fffd6909 (108 bytes)

/* Menu item 0.2.15 RADIO SETTING / MODE FM / RPTT SELECT */

void menuitem_EX010316(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010317 @ fffd6975 (99 bytes)

/* Menu item 0.2.16 RADIO SETTING / MODE FM / RPT SHIFT */

void menuitem_EX010317(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010318 @ fffd69d8 (108 bytes)

/* Menu item 0.2.17 RADIO SETTING / MODE FM / RPT SHIFT(28MHz) */

void menuitem_EX010318(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010319 @ fffd6a44 (110 bytes)

/* Menu item 0.2.18 RADIO SETTING / MODE FM / RPT SHIFT(50MHz) */

void menuitem_EX010319(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010320 @ fffd6ab2 (99 bytes)

/* Menu item 0.2.19 RADIO SETTING / MODE FM / ENC/DEC */

void menuitem_EX010320(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010321 @ fffd6b15 (99 bytes)

/* Menu item 0.2.20 RADIO SETTING / MODE FM / TONE FREQ */

void menuitem_EX010321(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010401 @ fffd6b78 (110 bytes)

/* Menu item 0.3.0 RADIO SETTING / MODE PSK/DATA / AF TREBLE GAIN */

void menuitem_EX010401(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010402 @ fffd6be6 (110 bytes)

/* Menu item 0.3.1 RADIO SETTING / MODE PSK/DATA / AF MIDDLE TONE GAIN */

void menuitem_EX010402(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010403 @ fffd6c54 (110 bytes)

/* Menu item 0.3.2 RADIO SETTING / MODE PSK/DATA / AF BASS GAIN */

void menuitem_EX010403(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010404 @ fffd6cc2 (108 bytes)

/* Menu item 0.3.3 RADIO SETTING / MODE PSK/DATA / AGC FAST DELAY */

void menuitem_EX010404(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010405 @ fffd6d2e (108 bytes)

/* Menu item 0.3.4 RADIO SETTING / MODE PSK/DATA / AGC MID DELAY */

void menuitem_EX010405(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010406 @ fffd6d9a (108 bytes)

/* Menu item 0.3.5 RADIO SETTING / MODE PSK/DATA / AGC SLOW DELAY */

void menuitem_EX010406(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010407 @ fffd6e06 (108 bytes)

/* Menu item 0.3.6 RADIO SETTING / MODE PSK/DATA / LCUT FREQ */

void menuitem_EX010407(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010408 @ fffd6e72 (108 bytes)

/* Menu item 0.3.7 RADIO SETTING / MODE PSK/DATA / LCUT SLOPE */

void menuitem_EX010408(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010409 @ fffd6ede (108 bytes)

/* Menu item 0.3.8 RADIO SETTING / MODE PSK/DATA / HCUT FREQ */

void menuitem_EX010409(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010410 @ fffd6f4a (108 bytes)

/* Menu item 0.3.9 RADIO SETTING / MODE PSK/DATA / HCUT SLOPE */

void menuitem_EX010410(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010411 @ fffd6fb6 (108 bytes)

/* Menu item 0.3.10 RADIO SETTING / MODE PSK/DATA / USB OUT LEVEL */

void menuitem_EX010411(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010412 @ fffd7022 (108 bytes)

/* Menu item 0.3.11 RADIO SETTING / MODE PSK/DATA / REAR OUT LEVEL */

void menuitem_EX010412(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010413 @ fffd708e (108 bytes)

/* Menu item 0.3.12 RADIO SETTING / MODE PSK/DATA / TX BPF SEL */

void menuitem_EX010413(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010414 @ fffd70fa (108 bytes)

/* Menu item 0.3.13 RADIO SETTING / MODE PSK/DATA / MOD SOURCE */

void menuitem_EX010414(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010415 @ fffd7166 (108 bytes)

/* Menu item 0.3.14 RADIO SETTING / MODE PSK/DATA / USB MOD GAIN */

void menuitem_EX010415(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010416 @ fffd71d2 (108 bytes)

/* Menu item 0.3.15 RADIO SETTING / MODE PSK/DATA / REAR MOD GAIN */

void menuitem_EX010416(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010417 @ fffd723e (108 bytes)

/* Menu item 0.3.16 RADIO SETTING / MODE PSK/DATA / RPTT SELECT */

void menuitem_EX010417(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}


// ===== menuitem_EX010418 @ fffd72aa (108 bytes)

/* Menu item 0.3.17 RADIO SETTING / MODE PSK/DATA / NAR WIDTH */

void menuitem_EX010418(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  char acStack_32 [22];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
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
  menu_register(&local_38);
  return;
}

