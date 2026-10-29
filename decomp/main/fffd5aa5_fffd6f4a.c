// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX010118 @ fffd5aa5 (108 bytes)

/* Menu item 0.0.17 RADIO SETTING / MODE SSB / NAR WIDTH */

void menuitem_EX010118(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff859cb;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca318;
  local_18 = &LAB_fffce114;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x16;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010119 @ fffd5b11 (108 bytes)

/* Menu item 0.0.18 RADIO SETTING / MODE SSB / CW AUTO MODE */

void menuitem_EX010119(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0x12;
  pbVar2 = (byte *)0xfff859e0;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca396;
  local_18 = &LAB_fffce127;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a3c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010201 @ fffd5b7d (110 bytes)

/* Menu item 0.1.0 RADIO SETTING / MODE AM / AF TREBLE GAIN */

void menuitem_EX010201(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff859f5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca422;
  local_18 = &LAB_fffce139;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010202 @ fffd5beb (110 bytes)

/* Menu item 0.1.1 RADIO SETTING / MODE AM / AF MIDDLE TONE GAIN */

void menuitem_EX010202(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85a0a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca43a;
  local_18 = &LAB_fffce14c;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a40;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010203 @ fffd5c59 (110 bytes)

/* Menu item 0.1.2 RADIO SETTING / MODE AM / AF BASS GAIN */

void menuitem_EX010203(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85a1f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca452;
  local_18 = &LAB_fffce15f;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a41;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010204 @ fffd5cc7 (108 bytes)

/* Menu item 0.1.3 RADIO SETTING / MODE AM / AGC FAST DELAY */

void menuitem_EX010204(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85a34;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca46a;
  local_18 = &LAB_fffce172;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a42;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010205 @ fffd5d33 (108 bytes)

/* Menu item 0.1.4 RADIO SETTING / MODE AM / AGC MID DELAY */

void menuitem_EX010205(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85a49;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca481;
  local_18 = &LAB_fffce185;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a43;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010206 @ fffd5d9f (108 bytes)

/* Menu item 0.1.5 RADIO SETTING / MODE AM / AGC SLOW DELAY */

void menuitem_EX010206(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85a5e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca498;
  local_18 = &LAB_fffce198;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a44;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010207 @ fffd5e0b (108 bytes)

/* Menu item 0.1.6 RADIO SETTING / MODE AM / LCUT FREQ */

void menuitem_EX010207(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85a73;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca4af;
  local_18 = &LAB_fffce1ab;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a45;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010208 @ fffd5e77 (108 bytes)

/* Menu item 0.1.7 RADIO SETTING / MODE AM / LCUT SLOPE */

void menuitem_EX010208(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85a88;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca4c4;
  local_18 = &LAB_fffce1b9;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a46;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010209 @ fffd5ee3 (108 bytes)

/* Menu item 0.1.8 RADIO SETTING / MODE AM / HCUT FREQ */

void menuitem_EX010209(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85a9d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca4d9;
  local_18 = &LAB_fffce1cb;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a47;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010210 @ fffd5f4f (108 bytes)

/* Menu item 0.1.9 RADIO SETTING / MODE AM / HCUT SLOPE */

void menuitem_EX010210(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85ab2;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca4ee;
  local_18 = &LAB_fffce1d9;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a48;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010211 @ fffd5fbb (108 bytes)

/* Menu item 0.1.10 RADIO SETTING / MODE AM / USB OUT LEVEL */

void menuitem_EX010211(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85ac7;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca503;
  local_18 = &LAB_fffce1eb;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a49;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010212 @ fffd6027 (108 bytes)

/* Menu item 0.1.11 RADIO SETTING / MODE AM / REAR OUT LEVEL */

void menuitem_EX010212(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff85adc;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca519;
  local_18 = &LAB_fffce1fe;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010213 @ fffd6093 (108 bytes)

/* Menu item 0.1.12 RADIO SETTING / MODE AM / TX BPF SEL */

void menuitem_EX010213(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85af1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca52f;
  local_18 = &LAB_fffce211;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010214 @ fffd60ff (108 bytes)

/* Menu item 0.1.13 RADIO SETTING / MODE AM / MOD SOURCE */

void menuitem_EX010214(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85b06;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca544;
  local_18 = &LAB_fffce223;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010215 @ fffd616b (108 bytes)

/* Menu item 0.1.14 RADIO SETTING / MODE AM / USB MOD GAIN */

void menuitem_EX010215(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff85b1b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca559;
  local_18 = &LAB_fffce235;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010216 @ fffd61d7 (108 bytes)

/* Menu item 0.1.15 RADIO SETTING / MODE AM / REAR MOD GAIN */

void menuitem_EX010216(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff85b30;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca56f;
  local_18 = &LAB_fffce248;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010217 @ fffd6243 (108 bytes)

/* Menu item 0.1.16 RADIO SETTING / MODE AM / RPTT SELECT */

void menuitem_EX010217(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff85b45;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca585;
  local_18 = &LAB_fffce25b;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010301 @ fffd62af (110 bytes)

/* Menu item 0.2.0 RADIO SETTING / MODE FM / AF TREBLE GAIN */

void menuitem_EX010301(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85b5a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca59a;
  local_18 = &LAB_fffce26d;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a52;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010302 @ fffd631d (110 bytes)

/* Menu item 0.2.1 RADIO SETTING / MODE FM / AF MIDDLE TONE GAIN */

void menuitem_EX010302(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85b6f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca5b2;
  local_18 = &LAB_fffce280;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a53;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010303 @ fffd638b (110 bytes)

/* Menu item 0.2.2 RADIO SETTING / MODE FM / AF BASS GAIN */

void menuitem_EX010303(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85b84;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca5ca;
  local_18 = &LAB_fffce293;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a54;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010304 @ fffd63f9 (108 bytes)

/* Menu item 0.2.3 RADIO SETTING / MODE FM / AGC FAST DELAY */

void menuitem_EX010304(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85b99;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca5e2;
  local_18 = &LAB_fffce2a6;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a55;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010305 @ fffd6465 (108 bytes)

/* Menu item 0.2.4 RADIO SETTING / MODE FM / AGC MID DELAY */

void menuitem_EX010305(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85bae;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca5f8;
  local_18 = &LAB_fffce2b9;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a56;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010306 @ fffd64d1 (108 bytes)

/* Menu item 0.2.5 RADIO SETTING / MODE FM / AGC SLOW DELAY */

void menuitem_EX010306(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85bc3;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca60f;
  local_18 = &LAB_fffce2cc;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a57;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010307 @ fffd653d (108 bytes)

/* Menu item 0.2.6 RADIO SETTING / MODE FM / LCUT FREQ */

void menuitem_EX010307(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85bd8;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca626;
  local_18 = &LAB_fffce2df;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a58;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010308 @ fffd65a9 (108 bytes)

/* Menu item 0.2.7 RADIO SETTING / MODE FM / LCUT SLOPE */

void menuitem_EX010308(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85bed;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca63b;
  local_18 = &LAB_fffce2ed;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a59;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010309 @ fffd6615 (108 bytes)

/* Menu item 0.2.8 RADIO SETTING / MODE FM / HCUT FREQ */

void menuitem_EX010309(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85c02;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca650;
  local_18 = &LAB_fffce2ff;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a5a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010310 @ fffd6681 (108 bytes)

/* Menu item 0.2.9 RADIO SETTING / MODE FM / HCUT SLOPE */

void menuitem_EX010310(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85c17;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca666;
  local_18 = &LAB_fffce30d;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a5b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010311 @ fffd66ed (108 bytes)

/* Menu item 0.2.10 RADIO SETTING / MODE FM / USB OUT LEVEL */

void menuitem_EX010311(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85c2c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca67b;
  local_18 = &LAB_fffce31f;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010312 @ fffd6759 (108 bytes)

/* Menu item 0.2.11 RADIO SETTING / MODE FM / REAR OUT LEVEL */

void menuitem_EX010312(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff85c41;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca691;
  local_18 = &LAB_fffce332;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010313 @ fffd67c5 (108 bytes)

/* Menu item 0.2.12 RADIO SETTING / MODE FM / MOD SOURCE */

void menuitem_EX010313(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85c56;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca6a7;
  local_18 = &LAB_fffce345;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a5e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010314 @ fffd6831 (108 bytes)

/* Menu item 0.2.13 RADIO SETTING / MODE FM / USB MOD GAIN */

void menuitem_EX010314(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85c6b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca6bc;
  local_18 = &LAB_fffce357;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a5f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010315 @ fffd689d (108 bytes)

/* Menu item 0.2.14 RADIO SETTING / MODE FM / REAR MOD GAIN */

void menuitem_EX010315(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff85c80;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca6d2;
  local_18 = &LAB_fffce36a;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a60;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010316 @ fffd6909 (108 bytes)

/* Menu item 0.2.15 RADIO SETTING / MODE FM / RPTT SELECT */

void menuitem_EX010316(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff85c95;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca6e8;
  local_18 = &LAB_fffce37d;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a61;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010317 @ fffd6975 (99 bytes)

/* Menu item 0.2.16 RADIO SETTING / MODE FM / RPT SHIFT */

void menuitem_EX010317(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
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
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff85caa;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca6fd;
  local_18 = &LAB_fffce38f;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 1;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010318 @ fffd69d8 (108 bytes)

/* Menu item 0.2.17 RADIO SETTING / MODE FM / RPT SHIFT(28MHz) */

void menuitem_EX010318(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff85cbf;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca79d;
  local_18 = &LAB_fffce436;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = &DAT_00009a62;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010319 @ fffd6a44 (110 bytes)

/* Menu item 0.2.18 RADIO SETTING / MODE FM / RPT SHIFT(50MHz) */

void menuitem_EX010319(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0x12;
  pbVar2 = (byte *)0xfff85cd4;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca821;
  local_18 = &LAB_fffce450;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 400;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = &DAT_00009a63;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010320 @ fffd6ab2 (99 bytes)

/* Menu item 0.2.19 RADIO SETTING / MODE FM / ENC/DEC */

void menuitem_EX010320(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
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
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0x13;
  pbVar2 = (byte *)0xfff85ce9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca8b6;
  local_18 = &LAB_fffce4df;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 2;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010321 @ fffd6b15 (99 bytes)

/* Menu item 0.2.20 RADIO SETTING / MODE FM / TONE FREQ */

void menuitem_EX010321(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
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
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0x14;
  pbVar2 = (byte *)0xfff85cfe;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffca956;
  local_18 = &LAB_fffce588;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x31;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0;
  local_3 = 3;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010401 @ fffd6b78 (110 bytes)

/* Menu item 0.3.0 RADIO SETTING / MODE PSK/DATA / AF TREBLE GAIN */

void menuitem_EX010401(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85d13;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaa35;
  local_18 = &LAB_fffce629;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a67;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010402 @ fffd6be6 (110 bytes)

/* Menu item 0.3.1 RADIO SETTING / MODE PSK/DATA / AF MIDDLE TONE GAIN */

void menuitem_EX010402(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85d28;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaa4d;
  local_18 = &LAB_fffce63c;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a68;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010403 @ fffd6c54 (110 bytes)

/* Menu item 0.3.2 RADIO SETTING / MODE PSK/DATA / AF BASS GAIN */

void menuitem_EX010403(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85d3d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaa65;
  local_18 = &LAB_fffce64f;
  local_14 = &LAB_fffcdc78;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a69;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010404 @ fffd6cc2 (108 bytes)

/* Menu item 0.3.3 RADIO SETTING / MODE PSK/DATA / AGC FAST DELAY */

void menuitem_EX010404(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85d52;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaa7d;
  local_18 = &LAB_fffce662;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010405 @ fffd6d2e (108 bytes)

/* Menu item 0.3.4 RADIO SETTING / MODE PSK/DATA / AGC MID DELAY */

void menuitem_EX010405(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85d67;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaa93;
  local_18 = &LAB_fffce675;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010406 @ fffd6d9a (108 bytes)

/* Menu item 0.3.5 RADIO SETTING / MODE PSK/DATA / AGC SLOW DELAY */

void menuitem_EX010406(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85d7c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaaaa;
  local_18 = &LAB_fffce688;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a6c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010407 @ fffd6e06 (108 bytes)

/* Menu item 0.3.6 RADIO SETTING / MODE PSK/DATA / LCUT FREQ */

void menuitem_EX010407(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85d91;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaac1;
  local_18 = &LAB_fffce69b;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a6d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010408 @ fffd6e72 (108 bytes)

/* Menu item 0.3.7 RADIO SETTING / MODE PSK/DATA / LCUT SLOPE */

void menuitem_EX010408(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85da6;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaad6;
  local_18 = &LAB_fffce6a9;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a6e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010409 @ fffd6ede (108 bytes)

/* Menu item 0.3.8 RADIO SETTING / MODE PSK/DATA / HCUT FREQ */

void menuitem_EX010409(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85dbb;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcaaeb;
  local_18 = &LAB_fffce6bb;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a6f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010410 @ fffd6f4a (108 bytes)

/* Menu item 0.3.9 RADIO SETTING / MODE PSK/DATA / HCUT SLOPE */

void menuitem_EX010410(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 3;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85dd0;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = &LAB_fffcab01;
  local_18 = &LAB_fffce6c9;
  local_14 = &LAB_fffcdc78;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a70;
  local_3 = 0;
  menu_register(local_38);
  return;
}

