// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex010310 @ fffe7a0a (76 bytes)

/* AI change detector for menu item EX010310 (table 0xFFF8E1A0[45]) */

void ai_ex010310(void)

{
  if (DAT_0001b2c7 == DAT_00009a5b) {
    return;
  }
  DAT_0001b2c7 = DAT_00009a5b;
  DAT_0001b23d = nib2hex(DAT_00009a5b);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010311 @ fffe7a56 (61 bytes)

/* AI change detector for menu item EX010311 (table 0xFFF8E1A0[46]) */

void ai_ex010311(void)

{
  if (DAT_0001b2c8 == DAT_00009a5c) {
    return;
  }
  DAT_0001b2c8 = DAT_00009a5c;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a5c,1,0);
  return;
}


// ===== ai_ex010312 @ fffe7a93 (61 bytes)

/* AI change detector for menu item EX010312 (table 0xFFF8E1A0[47]) */

void ai_ex010312(void)

{
  if (DAT_0001b2c9 == DAT_00009a5d) {
    return;
  }
  DAT_0001b2c9 = DAT_00009a5d;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a5d,1,0);
  return;
}


// ===== ai_ex010313 @ fffe7ad0 (76 bytes)

/* AI change detector for menu item EX010313 (table 0xFFF8E1A0[48]) */

void ai_ex010313(void)

{
  if (DAT_0001b2ca == DAT_00009a5e) {
    return;
  }
  DAT_0001b2ca = DAT_00009a5e;
  DAT_0001b23d = nib2hex(DAT_00009a5e);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010314 @ fffe7b1c (61 bytes)

/* AI change detector for menu item EX010314 (table 0xFFF8E1A0[49]) */

void ai_ex010314(void)

{
  if (DAT_0001b2cb == DAT_00009a5f) {
    return;
  }
  DAT_0001b2cb = DAT_00009a5f;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a5f,1,0);
  return;
}


// ===== ai_ex010315 @ fffe7b59 (61 bytes)

/* AI change detector for menu item EX010315 (table 0xFFF8E1A0[50]) */

void ai_ex010315(void)

{
  if (DAT_0001b2cc == DAT_00009a60) {
    return;
  }
  DAT_0001b2cc = DAT_00009a60;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a60,1,0);
  return;
}


// ===== ai_ex010316 @ fffe7b96 (76 bytes)

/* AI change detector for menu item EX010316 (table 0xFFF8E1A0[51]) */

void ai_ex010316(void)

{
  if (DAT_0001b2cd == DAT_00009a61) {
    return;
  }
  DAT_0001b2cd = DAT_00009a61;
  DAT_0001b23d = nib2hex(DAT_00009a61);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010317 @ fffe7be2 (106 bytes)

/* AI change detector for menu item EX010317 (table 0xFFF8E1A0[52]) */

void ai_ex010317(void)

{
  byte n;
  undefined1 local_1;
  
  if (DAT_00009dbd == '\0') {
    local_1 = DAT_00009d0b;
  }
  else {
    local_1 = DAT_00009d65;
  }
  n = local_1 >> 2 & 3;
  if (DAT_0001b2ce == n) {
    return;
  }
  DAT_0001b2ce = n;
  DAT_0001b23d = nib2hex(n);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010318 @ fffe7c4c (67 bytes)

/* AI change detector for menu item EX010318 (table 0xFFF8E1A0[53]) */

void ai_ex010318(void)

{
  if (DAT_0001b2cf == DAT_00009a62) {
    return;
  }
  DAT_0001b2cf = DAT_00009a62;
  DAT_0001ff12 = FUN_fffec3f8((ushort)DAT_00009a62 * 10);
  return;
}


// ===== ai_ex010319 @ fffe7c8f (82 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe7c9f) */
/* AI change detector for menu item EX010319 (table 0xFFF8E1A0[54]) */

void ai_ex010319(void)

{
  short sVar1;
  
  sVar1 = CONCAT11(DAT_00009a63,DAT_00009a64);
  if (DAT_0001ff14 == sVar1) {
    return;
  }
  DAT_0001ff14 = sVar1;
  DAT_0001ff12 = FUN_fffec3f8(sVar1 * 10);
  return;
}


// ===== ai_ex010320 @ fffe7ce1 (114 bytes)

/* AI change detector for menu item EX010320 (table 0xFFF8E1A0[55]) */

void ai_ex010320(void)

{
  byte local_1;
  
  local_1 = DAT_00009d0c;
  if (DAT_00009dbd != '\0') {
    local_1 = DAT_00009d66;
  }
  local_1 = local_1 & 0x38;
  if (DAT_0001b2d0 != local_1) {
    DAT_0001b2d0 = local_1;
    DAT_0001b23d = nib2hex(local_1 >> 3);
    DAT_0001b23e = 0x3b;
    DAT_0001ff12 = 10;
    return;
  }
  return;
}


// ===== ai_ex010321 @ fffe7d53 (89 bytes)

/* AI change detector for menu item EX010321 (table 0xFFF8E1A0[56]) */

void ai_ex010321(void)

{
  undefined1 local_1;
  
  if (DAT_00009dbd == '\0') {
    local_1 = DAT_00009d4f;
  }
  else {
    local_1 = DAT_00009da9;
  }
  if (DAT_0001b2d1 == local_1) {
    return;
  }
  DAT_0001b2d1 = local_1;
  DAT_0001ff12 = FUN_fffec2e5(local_1,1,0);
  return;
}


// ===== ai_ex010401 @ fffe7dac (61 bytes)

/* AI change detector for menu item EX010401 (table 0xFFF8E1A0[57]) */

void ai_ex010401(void)

{
  if (DAT_0001b2d2 == DAT_00009a67) {
    return;
  }
  DAT_0001b2d2 = DAT_00009a67;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a67,0,1);
  return;
}


// ===== ai_ex010402 @ fffe7de9 (61 bytes)

/* AI change detector for menu item EX010402 (table 0xFFF8E1A0[58]) */

void ai_ex010402(void)

{
  if (DAT_0001b2d3 == DAT_00009a68) {
    return;
  }
  DAT_0001b2d3 = DAT_00009a68;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a68,0,1);
  return;
}


// ===== ai_ex010403 @ fffe7e26 (61 bytes)

/* AI change detector for menu item EX010403 (table 0xFFF8E1A0[59]) */

void ai_ex010403(void)

{
  if (DAT_0001b2d4 == DAT_00009a69) {
    return;
  }
  DAT_0001b2d4 = DAT_00009a69;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a69,0,1);
  return;
}


// ===== ai_ex010404 @ fffe7e63 (72 bytes)

/* AI change detector for menu item EX010404 (table 0xFFF8E1A0[60]) */

void ai_ex010404(void)

{
  if (DAT_0001b2d5 == DAT_00009a6a) {
    return;
  }
  DAT_0001b2d5 = DAT_00009a6a;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a6a + 1) * 0x14);
  return;
}


// ===== ai_ex010405 @ fffe7eab (72 bytes)

/* AI change detector for menu item EX010405 (table 0xFFF8E1A0[61]) */

void ai_ex010405(void)

{
  if (DAT_0001b2d6 == DAT_00009a6b) {
    return;
  }
  DAT_0001b2d6 = DAT_00009a6b;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a6b + 1) * 0x14);
  return;
}


// ===== ai_ex010406 @ fffe7ef3 (72 bytes)

/* AI change detector for menu item EX010406 (table 0xFFF8E1A0[62]) */

void ai_ex010406(void)

{
  if (DAT_0001b2d7 == DAT_00009a6c) {
    return;
  }
  DAT_0001b2d7 = DAT_00009a6c;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a6c + 1) * 0x14);
  return;
}


// ===== ai_ex010407 @ fffe7f3b (61 bytes)

/* AI change detector for menu item EX010407 (table 0xFFF8E1A0[63]) */

void ai_ex010407(void)

{
  if (DAT_0001b2d8 == DAT_00009a6d) {
    return;
  }
  DAT_0001b2d8 = DAT_00009a6d;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a6d,0,0);
  return;
}


// ===== ai_ex010408 @ fffe7f78 (76 bytes)

/* AI change detector for menu item EX010408 (table 0xFFF8E1A0[64]) */

void ai_ex010408(void)

{
  if (DAT_0001b2d9 == DAT_00009a6e) {
    return;
  }
  DAT_0001b2d9 = DAT_00009a6e;
  DAT_0001b23d = nib2hex(DAT_00009a6e);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010409 @ fffe7fc4 (61 bytes)

/* AI change detector for menu item EX010409 (table 0xFFF8E1A0[65]) */

void ai_ex010409(void)

{
  if (DAT_0001b2da == DAT_00009a6f) {
    return;
  }
  DAT_0001b2da = DAT_00009a6f;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a6f,0,0);
  return;
}


// ===== ai_ex010410 @ fffe8001 (76 bytes)

/* AI change detector for menu item EX010410 (table 0xFFF8E1A0[66]) */

void ai_ex010410(void)

{
  if (DAT_0001b2db == DAT_00009a70) {
    return;
  }
  DAT_0001b2db = DAT_00009a70;
  DAT_0001b23d = nib2hex(DAT_00009a70);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010411 @ fffe804d (61 bytes)

/* AI change detector for menu item EX010411 (table 0xFFF8E1A0[67]) */

void ai_ex010411(void)

{
  if (DAT_0001b2dc == DAT_00009a71) {
    return;
  }
  DAT_0001b2dc = DAT_00009a71;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a71,1,0);
  return;
}


// ===== ai_ex010412 @ fffe808a (61 bytes)

/* AI change detector for menu item EX010412 (table 0xFFF8E1A0[68]) */

void ai_ex010412(void)

{
  if (DAT_0001b2dd == DAT_00009a72) {
    return;
  }
  DAT_0001b2dd = DAT_00009a72;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a72,1,0);
  return;
}


// ===== ai_ex010413 @ fffe80c7 (76 bytes)

/* AI change detector for menu item EX010413 (table 0xFFF8E1A0[69]) */

void ai_ex010413(void)

{
  if (DAT_0001b2de == DAT_00009a73) {
    return;
  }
  DAT_0001b2de = DAT_00009a73;
  DAT_0001b23d = nib2hex(DAT_00009a73);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010414 @ fffe8113 (76 bytes)

/* AI change detector for menu item EX010414 (table 0xFFF8E1A0[70]) */

void ai_ex010414(void)

{
  if (DAT_0001b2df == DAT_00009a74) {
    return;
  }
  DAT_0001b2df = DAT_00009a74;
  DAT_0001b23d = nib2hex(DAT_00009a74);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010415 @ fffe815f (61 bytes)

/* AI change detector for menu item EX010415 (table 0xFFF8E1A0[71]) */

void ai_ex010415(void)

{
  if (DAT_0001b2e0 == DAT_00009a75) {
    return;
  }
  DAT_0001b2e0 = DAT_00009a75;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a75,1,0);
  return;
}


// ===== ai_ex010416 @ fffe819c (61 bytes)

/* AI change detector for menu item EX010416 (table 0xFFF8E1A0[72]) */

void ai_ex010416(void)

{
  if (DAT_0001b2e1 == DAT_00009a76) {
    return;
  }
  DAT_0001b2e1 = DAT_00009a76;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a76,1,0);
  return;
}


// ===== ai_ex010417 @ fffe81d9 (76 bytes)

/* AI change detector for menu item EX010417 (table 0xFFF8E1A0[73]) */

void ai_ex010417(void)

{
  if (DAT_0001b2e2 == DAT_00009a77) {
    return;
  }
  DAT_0001b2e2 = DAT_00009a77;
  DAT_0001b23d = nib2hex(DAT_00009a77);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010418 @ fffe8225 (61 bytes)

/* AI change detector for menu item EX010418 (table 0xFFF8E1A0[74]) */

void ai_ex010418(void)

{
  if (DAT_0001b2e3 == DAT_00009a78) {
    return;
  }
  DAT_0001b2e3 = DAT_00009a78;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a78,0,0);
  return;
}


// ===== ai_ex010419 @ fffe8262 (76 bytes)

/* AI change detector for menu item EX010419 (table 0xFFF8E1A0[75]) */

void ai_ex010419(void)

{
  if (DAT_0001b2e4 == DAT_00009a79) {
    return;
  }
  DAT_0001b2e4 = DAT_00009a79;
  DAT_0001b23d = nib2hex(DAT_00009a79);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010420 @ fffe82ae (82 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe82be) */
/* AI change detector for menu item EX010420 (table 0xFFF8E1A0[76]) */

void ai_ex010420(void)

{
  short sVar1;
  
  sVar1 = CONCAT11(DAT_00009a7a,DAT_00009a7b);
  if (DAT_0001ff16 == sVar1) {
    return;
  }
  DAT_0001ff16 = sVar1;
  DAT_0001ff12 = FUN_fffec3f8(sVar1 * 10);
  return;
}


// ===== ai_ex010501 @ fffe8300 (61 bytes)

/* AI change detector for menu item EX010501 (table 0xFFF8E1A0[77]) */

void ai_ex010501(void)

{
  if (DAT_0001b2e5 == DAT_00009a7e) {
    return;
  }
  DAT_0001b2e5 = DAT_00009a7e;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a7e,0,1);
  return;
}


// ===== ai_ex010502 @ fffe833d (61 bytes)

/* AI change detector for menu item EX010502 (table 0xFFF8E1A0[78]) */

void ai_ex010502(void)

{
  if (DAT_0001b2e6 == DAT_00009a7f) {
    return;
  }
  DAT_0001b2e6 = DAT_00009a7f;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a7f,0,1);
  return;
}


// ===== ai_ex010503 @ fffe837a (61 bytes)

/* AI change detector for menu item EX010503 (table 0xFFF8E1A0[79]) */

void ai_ex010503(void)

{
  if (DAT_0001b2e7 == DAT_00009a80) {
    return;
  }
  DAT_0001b2e7 = DAT_00009a80;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a80,0,1);
  return;
}


// ===== ai_ex010504 @ fffe83b7 (72 bytes)

/* AI change detector for menu item EX010504 (table 0xFFF8E1A0[80]) */

void ai_ex010504(void)

{
  if (DAT_0001b2e8 == DAT_00009a81) {
    return;
  }
  DAT_0001b2e8 = DAT_00009a81;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a81 + 1) * 0x14);
  return;
}


// ===== ai_ex010505 @ fffe83ff (72 bytes)

/* AI change detector for menu item EX010505 (table 0xFFF8E1A0[81]) */

void ai_ex010505(void)

{
  if (DAT_0001b2e9 == DAT_00009a82) {
    return;
  }
  DAT_0001b2e9 = DAT_00009a82;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a82 + 1) * 0x14);
  return;
}


// ===== ai_ex010506 @ fffe8447 (72 bytes)

/* AI change detector for menu item EX010506 (table 0xFFF8E1A0[82]) */

void ai_ex010506(void)

{
  if (DAT_0001b2ea == DAT_00009a83) {
    return;
  }
  DAT_0001b2ea = DAT_00009a83;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a83 + 1) * 0x14);
  return;
}


// ===== ai_ex010507 @ fffe848f (61 bytes)

/* AI change detector for menu item EX010507 (table 0xFFF8E1A0[83]) */

void ai_ex010507(void)

{
  if (DAT_0001b2eb == DAT_00009a84) {
    return;
  }
  DAT_0001b2eb = DAT_00009a84;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a84,0,0);
  return;
}


// ===== ai_ex010508 @ fffe84cc (76 bytes)

/* AI change detector for menu item EX010508 (table 0xFFF8E1A0[84]) */

void ai_ex010508(void)

{
  if (DAT_0001b2ec == DAT_00009a85) {
    return;
  }
  DAT_0001b2ec = DAT_00009a85;
  DAT_0001b23d = nib2hex(DAT_00009a85);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010509 @ fffe8518 (61 bytes)

/* AI change detector for menu item EX010509 (table 0xFFF8E1A0[85]) */

void ai_ex010509(void)

{
  if (DAT_0001b2ed == DAT_00009a86) {
    return;
  }
  DAT_0001b2ed = DAT_00009a86;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a86,0,0);
  return;
}


// ===== ai_ex010510 @ fffe8555 (76 bytes)

/* AI change detector for menu item EX010510 (table 0xFFF8E1A0[86]) */

void ai_ex010510(void)

{
  if (DAT_0001b2ee == DAT_00009a87) {
    return;
  }
  DAT_0001b2ee = DAT_00009a87;
  DAT_0001b23d = nib2hex(DAT_00009a87);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010511 @ fffe85a1 (61 bytes)

/* AI change detector for menu item EX010511 (table 0xFFF8E1A0[87]) */

void ai_ex010511(void)

{
  if (DAT_0001b2ef == DAT_00009a88) {
    return;
  }
  DAT_0001b2ef = DAT_00009a88;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a88,1,0);
  return;
}


// ===== ai_ex010512 @ fffe85de (61 bytes)

/* AI change detector for menu item EX010512 (table 0xFFF8E1A0[88]) */

void ai_ex010512(void)

{
  if (DAT_0001b2f0 == DAT_00009a89) {
    return;
  }
  DAT_0001b2f0 = DAT_00009a89;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a89,1,0);
  return;
}


// ===== ai_ex010513 @ fffe861b (76 bytes)

/* AI change detector for menu item EX010513 (table 0xFFF8E1A0[89]) */

void ai_ex010513(void)

{
  if (DAT_0001b2f1 == DAT_00009a8a) {
    return;
  }
  DAT_0001b2f1 = DAT_00009a8a;
  DAT_0001b23d = nib2hex(DAT_00009a8a);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010514 @ fffe8667 (61 bytes)

/* AI change detector for menu item EX010514 (table 0xFFF8E1A0[90]) */

void ai_ex010514(void)

{
  if (DAT_0001b2f2 == DAT_00009a8b) {
    return;
  }
  DAT_0001b2f2 = DAT_00009a8b;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a8b,0,0);
  return;
}


// ===== ai_ex010515 @ fffe86a4 (76 bytes)

/* AI change detector for menu item EX010515 (table 0xFFF8E1A0[91]) */

void ai_ex010515(void)

{
  if (DAT_0001b2f3 == DAT_00009a8c) {
    return;
  }
  DAT_0001b2f3 = DAT_00009a8c;
  DAT_0001b23d = nib2hex(DAT_00009a8c);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010516 @ fffe86f0 (76 bytes)

/* AI change detector for menu item EX010516 (table 0xFFF8E1A0[92]) */

void ai_ex010516(void)

{
  if (DAT_0001b2f4 == DAT_00009a8d) {
    return;
  }
  DAT_0001b2f4 = DAT_00009a8d;
  DAT_0001b23d = nib2hex(DAT_00009a8d);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010517 @ fffe873c (82 bytes)

/* AI change detector for menu item EX010517 (table 0xFFF8E1A0[93]) */

void ai_ex010517(void)

{
  undefined1 local_1;
  
  DAT_0001b2f5 = DAT_00009a8e;
  if (DAT_00009a8e == local_1) {
    return;
  }
  DAT_0001b2f5 = local_1;
  DAT_0001b23d = nib2hex(local_1);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020101 @ fffe878e (61 bytes)

/* AI change detector for menu item EX020101 (table 0xFFF8E1A0[94]) */

void ai_ex020101(void)

{
  if (DAT_0001b2f6 == DAT_00009a91) {
    return;
  }
  DAT_0001b2f6 = DAT_00009a91;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a91,0,1);
  return;
}

