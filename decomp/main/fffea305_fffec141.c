// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex040106 @ fffea305 (61 bytes)

/* AI change detector for menu item EX040106 (table 0xFFF8E1A0[195]) */

void ai_ex040106(void)

{
  if (DAT_0001b365 == DAT_00009b11) {
    return;
  }
  DAT_0001b365 = DAT_00009b11;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009b11,0,0);
  return;
}


// ===== ai_ex040201 @ fffea342 (76 bytes)

/* AI change detector for menu item EX040201 (table 0xFFF8E1A0[196]) */

void ai_ex040201(void)

{
  if (DAT_0001b366 == DAT_00009b14) {
    return;
  }
  DAT_0001b366 = DAT_00009b14;
  DAT_0001b23d = nib2hex(DAT_00009b14);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040202 @ fffea38e (76 bytes)

/* AI change detector for menu item EX040202 (table 0xFFF8E1A0[197]) */

void ai_ex040202(void)

{
  if (DAT_0001b367 == DAT_00009b15) {
    return;
  }
  DAT_0001b367 = DAT_00009b15;
  DAT_0001b23d = nib2hex(DAT_00009b15);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040203 @ fffea3da (76 bytes)

/* AI change detector for menu item EX040203 (table 0xFFF8E1A0[198]) */

void ai_ex040203(void)

{
  if (DAT_0001b368 == DAT_00009b16) {
    return;
  }
  DAT_0001b368 = DAT_00009b16;
  DAT_0001b23d = nib2hex(DAT_00009b16);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040204 @ fffea426 (76 bytes)

/* AI change detector for menu item EX040204 (table 0xFFF8E1A0[199]) */

void ai_ex040204(void)

{
  if (DAT_0001b369 == DAT_00009b17) {
    return;
  }
  DAT_0001b369 = DAT_00009b17;
  DAT_0001b23d = nib2hex(DAT_00009b17);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040301 @ fffea472 (76 bytes)

/* AI change detector for menu item EX040301 (table 0xFFF8E1A0[200]) */

void ai_ex040301(void)

{
  if (DAT_0001b36a == DAT_00009b1a) {
    return;
  }
  DAT_0001b36a = DAT_00009b1a;
  DAT_0001b23d = nib2hex(DAT_00009b1a);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040302 @ fffea4be (76 bytes)

/* AI change detector for menu item EX040302 (table 0xFFF8E1A0[201]) */

void ai_ex040302(void)

{
  if (DAT_0001b36b == DAT_00009b1b) {
    return;
  }
  DAT_0001b36b = DAT_00009b1b;
  DAT_0001b23d = nib2hex(DAT_00009b1b);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040303 @ fffea50a (76 bytes)

/* AI change detector for menu item EX040303 (table 0xFFF8E1A0[202]) */

void ai_ex040303(void)

{
  if (DAT_0001b36c == DAT_00009b1c) {
    return;
  }
  DAT_0001b36c = DAT_00009b1c;
  DAT_0001b23d = nib2hex(DAT_00009b1c);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040304 @ fffea556 (76 bytes)

/* AI change detector for menu item EX040304 (table 0xFFF8E1A0[203]) */

void ai_ex040304(void)

{
  if (DAT_0001b36d == DAT_00009b1d) {
    return;
  }
  DAT_0001b36d = DAT_00009b1d;
  DAT_0001b23d = nib2hex(DAT_00009b1d);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040401 @ fffea5a2 (76 bytes)

/* AI change detector for menu item EX040401 (table 0xFFF8E1A0[204]) */

void ai_ex040401(void)

{
  if (DAT_0001b36e == DAT_00009b20) {
    return;
  }
  DAT_0001b36e = DAT_00009b20;
  DAT_0001b23d = nib2hex(DAT_00009b20);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex040402 @ fffea5ee (76 bytes)

/* AI change detector for menu item EX040402 (table 0xFFF8E1A0[205]) */

void ai_ex040402(void)

{
  if (DAT_0001b36f == DAT_00009b21) {
    return;
  }
  DAT_0001b36f = DAT_00009b21;
  DAT_0001b23d = nib2hex(DAT_00009b21);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== FUN_fffea63a @ fffea63a (594 bytes)

void FUN_fffea63a(char param_1)

{
  int iVar1;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined4 uStack_6;
  byte bStack_2;
  char local_1;
  
  local_1 = param_1;
  if (param_1 == '\x05') {
    iVar1 = strncmp(&DAT_0001b3a0,&DAT_00009baa,0xc);
    if (iVar1 != 0) {
      DAT_0001b3a8 = DAT_00009bb2;
      DAT_0001b3a4 = DAT_00009bae;
      DAT_0001b3a0 = DAT_00009baa;
      uStack_6 = DAT_00009bb2;
      uStack_a = DAT_00009bae;
      uStack_e = DAT_00009baa;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x02') {
    iVar1 = strncmp(&DAT_0001b37c,&DAT_00009b4d,0xc);
    if (iVar1 != 0) {
      DAT_0001b384 = DAT_00009b55;
      DAT_0001b380 = DAT_00009b51;
      DAT_0001b37c = DAT_00009b4d;
      uStack_6 = DAT_00009b55;
      uStack_a = DAT_00009b51;
      uStack_e = DAT_00009b4d;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x03') {
    iVar1 = strncmp(&DAT_0001b388,&DAT_00009b6c,0xc);
    if (iVar1 != 0) {
      DAT_0001b390 = DAT_00009b74;
      DAT_0001b38c = DAT_00009b70;
      DAT_0001b388 = DAT_00009b6c;
      uStack_6 = DAT_00009b74;
      uStack_a = DAT_00009b70;
      uStack_e = DAT_00009b6c;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x04') {
    iVar1 = strncmp(&DAT_0001b394,&DAT_00009b8b,0xc);
    if (iVar1 != 0) {
      DAT_0001b39c = DAT_00009b93;
      DAT_0001b398 = DAT_00009b8f;
      DAT_0001b394 = DAT_00009b8b;
      uStack_6 = DAT_00009b93;
      uStack_a = DAT_00009b8f;
      uStack_e = DAT_00009b8b;
      DAT_0001ff12 = 0x15;
    }
  }
  else if ((param_1 == '\x01') && (iVar1 = strncmp(&DAT_0001b370,&DAT_00009b2e,0xc), iVar1 != 0)) {
    DAT_0001b378 = DAT_00009b36;
    DAT_0001b374 = DAT_00009b32;
    DAT_0001b370 = DAT_00009b2e;
    uStack_6 = DAT_00009b36;
    uStack_a = DAT_00009b32;
    uStack_e = DAT_00009b2e;
    DAT_0001ff12 = 0x15;
  }
  if (DAT_0001ff12 != 0) {
    for (bStack_2 = 0; bStack_2 < 0xc; bStack_2 = bStack_2 + 1) {
      (&DAT_0001b23d)[bStack_2] = *(undefined1 *)((int)&uStack_e + (uint)bStack_2);
    }
    DAT_0001b249 = 0x3b;
    return;
  }
  return;
}


// ===== FUN_fffea88c @ fffea88c (380 bytes)

void FUN_fffea88c(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b559 != DAT_00009bb6) {
      DAT_0001b559 = DAT_00009bb6;
      DAT_0001b23d = nib2hex(DAT_00009bb6);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b556 != DAT_00009b59) {
      DAT_0001b556 = DAT_00009b59;
      DAT_0001b23d = nib2hex(DAT_00009b59);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b557 != DAT_00009b78) {
      DAT_0001b557 = DAT_00009b78;
      DAT_0001b23d = nib2hex(DAT_00009b78);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b558 != DAT_00009b97) {
      DAT_0001b558 = DAT_00009b97;
      DAT_0001b23d = nib2hex(DAT_00009b97);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b555 != DAT_00009b3a)) {
    DAT_0001b555 = DAT_00009b3a;
    DAT_0001b23d = nib2hex(DAT_00009b3a);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeaa08 @ fffeaa08 (380 bytes)

void FUN_fffeaa08(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b55e != DAT_00009bb7) {
      DAT_0001b55e = DAT_00009bb7;
      DAT_0001b23d = nib2hex(DAT_00009bb7);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b55b != DAT_00009b5a) {
      DAT_0001b55b = DAT_00009b5a;
      DAT_0001b23d = nib2hex(DAT_00009b5a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b55c != DAT_00009b79) {
      DAT_0001b55c = DAT_00009b79;
      DAT_0001b23d = nib2hex(DAT_00009b79);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b55d != DAT_00009b98) {
      DAT_0001b55d = DAT_00009b98;
      DAT_0001b23d = nib2hex(DAT_00009b98);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55a != DAT_00009b3b)) {
    DAT_0001b55a = DAT_00009b3b;
    DAT_0001b23d = nib2hex(DAT_00009b3b);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeab84 @ fffeab84 (380 bytes)

void FUN_fffeab84(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b563 != DAT_00009bb8) {
      DAT_0001b563 = DAT_00009bb8;
      DAT_0001b23d = nib2hex(DAT_00009bb8);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b560 != DAT_00009b5b) {
      DAT_0001b560 = DAT_00009b5b;
      DAT_0001b23d = nib2hex(DAT_00009b5b);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b561 != DAT_00009b7a) {
      DAT_0001b561 = DAT_00009b7a;
      DAT_0001b23d = nib2hex(DAT_00009b7a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b562 != DAT_00009b99) {
      DAT_0001b562 = DAT_00009b99;
      DAT_0001b23d = nib2hex(DAT_00009b99);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55f != DAT_00009b3c)) {
    DAT_0001b55f = DAT_00009b3c;
    DAT_0001b23d = nib2hex(DAT_00009b3c);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffead00 @ fffead00 (375 bytes)

void FUN_fffead00(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b568 != DAT_00009bb9) {
      DAT_0001b568 = DAT_00009bb9;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bb9 + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b565 != DAT_00009b5c) {
      DAT_0001b565 = DAT_00009b5c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5c + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b566 != DAT_00009b7b) {
      DAT_0001b566 = DAT_00009b7b;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7b + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b567 != DAT_00009b9a) {
      DAT_0001b567 = DAT_00009b9a;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9a + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b564 != DAT_00009b3d)) {
    DAT_0001b564 = DAT_00009b3d;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3d + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeae77 @ fffeae77 (375 bytes)

void FUN_fffeae77(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b56d != DAT_00009bba) {
      DAT_0001b56d = DAT_00009bba;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bba + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b56a != DAT_00009b5d) {
      DAT_0001b56a = DAT_00009b5d;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5d + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b56b != DAT_00009b7c) {
      DAT_0001b56b = DAT_00009b7c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7c + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b56c != DAT_00009b9b) {
      DAT_0001b56c = DAT_00009b9b;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9b + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b569 != DAT_00009b3e)) {
    DAT_0001b569 = DAT_00009b3e;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3e + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeafee @ fffeafee (375 bytes)

void FUN_fffeafee(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b572 != DAT_00009bbb) {
      DAT_0001b572 = DAT_00009bbb;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bbb + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b56f != DAT_00009b5e) {
      DAT_0001b56f = DAT_00009b5e;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5e + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b570 != DAT_00009b7d) {
      DAT_0001b570 = DAT_00009b7d;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7d + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b571 != DAT_00009b9c) {
      DAT_0001b571 = DAT_00009b9c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9c + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b56e != DAT_00009b3f)) {
    DAT_0001b56e = DAT_00009b3f;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3f + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeb165 @ fffeb165 (340 bytes)

void FUN_fffeb165(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b577 != DAT_00009bbc) {
      DAT_0001b577 = DAT_00009bbc;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bbc,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b574 != DAT_00009b5f) {
      DAT_0001b574 = DAT_00009b5f;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b5f,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b575 != DAT_00009b7e) {
      DAT_0001b575 = DAT_00009b7e;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b7e,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b576 != DAT_00009b9d) {
      DAT_0001b576 = DAT_00009b9d;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b9d,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b573 != DAT_00009b40)) {
    DAT_0001b573 = DAT_00009b40;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b40,0,0);
    return;
  }
  return;
}


// ===== FUN_fffeb2b9 @ fffeb2b9 (380 bytes)

void FUN_fffeb2b9(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b57c != DAT_00009bbd) {
      DAT_0001b57c = DAT_00009bbd;
      DAT_0001b23d = nib2hex(DAT_00009bbd);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b579 != DAT_00009b60) {
      DAT_0001b579 = DAT_00009b60;
      DAT_0001b23d = nib2hex(DAT_00009b60);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57a != DAT_00009b7f) {
      DAT_0001b57a = DAT_00009b7f;
      DAT_0001b23d = nib2hex(DAT_00009b7f);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b57b != DAT_00009b9e) {
      DAT_0001b57b = DAT_00009b9e;
      DAT_0001b23d = nib2hex(DAT_00009b9e);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b578 != DAT_00009b41)) {
    DAT_0001b578 = DAT_00009b41;
    DAT_0001b23d = nib2hex(DAT_00009b41);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeb435 @ fffeb435 (340 bytes)

void FUN_fffeb435(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b581 != DAT_00009bbe) {
      DAT_0001b581 = DAT_00009bbe;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bbe,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b57e != DAT_00009b61) {
      DAT_0001b57e = DAT_00009b61;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b61,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57f != DAT_00009b80) {
      DAT_0001b57f = DAT_00009b80;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b80,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b580 != DAT_00009b9f) {
      DAT_0001b580 = DAT_00009b9f;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b9f,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b57d != DAT_00009b42)) {
    DAT_0001b57d = DAT_00009b42;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b42,0,0);
    return;
  }
  return;
}


// ===== FUN_fffeb589 @ fffeb589 (380 bytes)

void FUN_fffeb589(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b586 != DAT_00009bbf) {
      DAT_0001b586 = DAT_00009bbf;
      DAT_0001b23d = nib2hex(DAT_00009bbf);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b583 != DAT_00009b62) {
      DAT_0001b583 = DAT_00009b62;
      DAT_0001b23d = nib2hex(DAT_00009b62);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b584 != DAT_00009b81) {
      DAT_0001b584 = DAT_00009b81;
      DAT_0001b23d = nib2hex(DAT_00009b81);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b585 != DAT_00009ba0) {
      DAT_0001b585 = DAT_00009ba0;
      DAT_0001b23d = nib2hex(DAT_00009ba0);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b582 != DAT_00009b43)) {
    DAT_0001b582 = DAT_00009b43;
    DAT_0001b23d = nib2hex(DAT_00009b43);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeb705 @ fffeb705 (340 bytes)

void FUN_fffeb705(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b58b != DAT_00009bc0) {
      DAT_0001b58b = DAT_00009bc0;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc0,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b588 != DAT_00009b63) {
      DAT_0001b588 = DAT_00009b63;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b63,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b589 != DAT_00009b82) {
      DAT_0001b589 = DAT_00009b82;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b82,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58a != DAT_00009ba1) {
      DAT_0001b58a = DAT_00009ba1;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba1,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b587 != DAT_00009b44)) {
    DAT_0001b587 = DAT_00009b44;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b44,1,0);
    return;
  }
  return;
}


// ===== FUN_fffeb859 @ fffeb859 (340 bytes)

void FUN_fffeb859(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b590 != DAT_00009bc1) {
      DAT_0001b590 = DAT_00009bc1;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc1,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b58d != DAT_00009b64) {
      DAT_0001b58d = DAT_00009b64;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b64,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b58e != DAT_00009b83) {
      DAT_0001b58e = DAT_00009b83;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b83,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58f != DAT_00009ba2) {
      DAT_0001b58f = DAT_00009ba2;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba2,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b58c != DAT_00009b45)) {
    DAT_0001b58c = DAT_00009b45;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b45,1,0);
    return;
  }
  return;
}


// ===== FUN_fffeb9ad @ fffeb9ad (380 bytes)

void FUN_fffeb9ad(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b595 != DAT_00009bc2) {
      DAT_0001b595 = DAT_00009bc2;
      DAT_0001b23d = nib2hex(DAT_00009bc2);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b592 != DAT_00009b65) {
      DAT_0001b592 = DAT_00009b65;
      DAT_0001b23d = nib2hex(DAT_00009b65);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b593 != DAT_00009b84) {
      DAT_0001b593 = DAT_00009b84;
      DAT_0001b23d = nib2hex(DAT_00009b84);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b594 != DAT_00009ba3) {
      DAT_0001b594 = DAT_00009ba3;
      DAT_0001b23d = nib2hex(DAT_00009ba3);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b591 != DAT_00009b46)) {
    DAT_0001b591 = DAT_00009b46;
    DAT_0001b23d = nib2hex(DAT_00009b46);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffebb29 @ fffebb29 (380 bytes)

void FUN_fffebb29(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59a != DAT_00009bc3) {
      DAT_0001b59a = DAT_00009bc3;
      DAT_0001b23d = nib2hex(DAT_00009bc3);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b597 != DAT_00009b66) {
      DAT_0001b597 = DAT_00009b66;
      DAT_0001b23d = nib2hex(DAT_00009b66);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b598 != DAT_00009b85) {
      DAT_0001b598 = DAT_00009b85;
      DAT_0001b23d = nib2hex(DAT_00009b85);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b599 != DAT_00009ba4) {
      DAT_0001b599 = DAT_00009ba4;
      DAT_0001b23d = nib2hex(DAT_00009ba4);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b596 != DAT_00009b47)) {
    DAT_0001b596 = DAT_00009b47;
    DAT_0001b23d = nib2hex(DAT_00009b47);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffebca5 @ fffebca5 (340 bytes)

void FUN_fffebca5(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59f != DAT_00009bc4) {
      DAT_0001b59f = DAT_00009bc4;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc4,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b59c != DAT_00009b67) {
      DAT_0001b59c = DAT_00009b67;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b67,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b59d != DAT_00009b86) {
      DAT_0001b59d = DAT_00009b86;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b86,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b59e != DAT_00009ba5) {
      DAT_0001b59e = DAT_00009ba5;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba5,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b59b != DAT_00009b48)) {
    DAT_0001b59b = DAT_00009b48;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b48,1,0);
    return;
  }
  return;
}


// ===== FUN_fffebdf9 @ fffebdf9 (340 bytes)

void FUN_fffebdf9(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a4 != DAT_00009bc5) {
      DAT_0001b5a4 = DAT_00009bc5;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc5,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a1 != DAT_00009b68) {
      DAT_0001b5a1 = DAT_00009b68;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b68,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a2 != DAT_00009b87) {
      DAT_0001b5a2 = DAT_00009b87;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b87,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a3 != DAT_00009ba6) {
      DAT_0001b5a3 = DAT_00009ba6;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba6,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a0 != DAT_00009b49)) {
    DAT_0001b5a0 = DAT_00009b49;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b49,1,0);
    return;
  }
  return;
}


// ===== FUN_fffebf4d @ fffebf4d (380 bytes)

void FUN_fffebf4d(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a9 != DAT_00009bc6) {
      DAT_0001b5a9 = DAT_00009bc6;
      DAT_0001b23d = nib2hex(DAT_00009bc6);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a6 != DAT_00009b69) {
      DAT_0001b5a6 = DAT_00009b69;
      DAT_0001b23d = nib2hex(DAT_00009b69);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a7 != DAT_00009b88) {
      DAT_0001b5a7 = DAT_00009b88;
      DAT_0001b23d = nib2hex(DAT_00009b88);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a8 != DAT_00009ba7) {
      DAT_0001b5a8 = DAT_00009ba7;
      DAT_0001b23d = nib2hex(DAT_00009ba7);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a5 != DAT_00009b4a)) {
    DAT_0001b5a5 = DAT_00009b4a;
    DAT_0001b23d = nib2hex(DAT_00009b4a);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex060101 @ fffec0c9 (6 bytes)

/* AI change detector for menu item EX060101 (table 0xFFF8E1A0[206]) */

void ai_ex060101(void)

{
  FUN_fffea63a(1);
  return;
}


// ===== ai_ex060102 @ fffec0cf (6 bytes)

/* AI change detector for menu item EX060102 (table 0xFFF8E1A0[207]) */

void ai_ex060102(void)

{
  FUN_fffea88c(1);
  return;
}


// ===== ai_ex060103 @ fffec0d5 (6 bytes)

/* AI change detector for menu item EX060103 (table 0xFFF8E1A0[208]) */

void ai_ex060103(void)

{
  FUN_fffeaa08(1);
  return;
}


// ===== ai_ex060104 @ fffec0db (6 bytes)

/* AI change detector for menu item EX060104 (table 0xFFF8E1A0[209]) */

void ai_ex060104(void)

{
  FUN_fffeab84(1);
  return;
}


// ===== ai_ex060105 @ fffec0e1 (6 bytes)

/* AI change detector for menu item EX060105 (table 0xFFF8E1A0[210]) */

void ai_ex060105(void)

{
  FUN_fffead00(1);
  return;
}


// ===== ai_ex060106 @ fffec0e7 (6 bytes)

/* AI change detector for menu item EX060106 (table 0xFFF8E1A0[211]) */

void ai_ex060106(void)

{
  FUN_fffeae77(1);
  return;
}


// ===== ai_ex060107 @ fffec0ed (6 bytes)

/* AI change detector for menu item EX060107 (table 0xFFF8E1A0[212]) */

void ai_ex060107(void)

{
  FUN_fffeafee(1);
  return;
}


// ===== ai_ex060108 @ fffec0f3 (6 bytes)

/* AI change detector for menu item EX060108 (table 0xFFF8E1A0[213]) */

void ai_ex060108(void)

{
  FUN_fffeb165(1);
  return;
}


// ===== ai_ex060109 @ fffec0f9 (6 bytes)

/* AI change detector for menu item EX060109 (table 0xFFF8E1A0[214]) */

void ai_ex060109(void)

{
  FUN_fffeb2b9(1);
  return;
}


// ===== ai_ex060110 @ fffec0ff (6 bytes)

/* AI change detector for menu item EX060110 (table 0xFFF8E1A0[215]) */

void ai_ex060110(void)

{
  FUN_fffeb435(1);
  return;
}


// ===== ai_ex060111 @ fffec105 (6 bytes)

/* AI change detector for menu item EX060111 (table 0xFFF8E1A0[216]) */

void ai_ex060111(void)

{
  FUN_fffeb589(1);
  return;
}


// ===== ai_ex060112 @ fffec10b (6 bytes)

/* AI change detector for menu item EX060112 (table 0xFFF8E1A0[217]) */

void ai_ex060112(void)

{
  FUN_fffeb705(1);
  return;
}


// ===== ai_ex060113 @ fffec111 (6 bytes)

/* AI change detector for menu item EX060113 (table 0xFFF8E1A0[218]) */

void ai_ex060113(void)

{
  FUN_fffeb859(1);
  return;
}


// ===== ai_ex060114 @ fffec117 (6 bytes)

/* AI change detector for menu item EX060114 (table 0xFFF8E1A0[219]) */

void ai_ex060114(void)

{
  FUN_fffeb9ad(1);
  return;
}


// ===== ai_ex060115 @ fffec11d (6 bytes)

/* AI change detector for menu item EX060115 (table 0xFFF8E1A0[220]) */

void ai_ex060115(void)

{
  FUN_fffebb29(1);
  return;
}


// ===== ai_ex060116 @ fffec123 (6 bytes)

/* AI change detector for menu item EX060116 (table 0xFFF8E1A0[221]) */

void ai_ex060116(void)

{
  FUN_fffebca5(1);
  return;
}


// ===== ai_ex060117 @ fffec129 (6 bytes)

/* AI change detector for menu item EX060117 (table 0xFFF8E1A0[222]) */

void ai_ex060117(void)

{
  FUN_fffebdf9(1);
  return;
}


// ===== ai_ex060118 @ fffec12f (6 bytes)

/* AI change detector for menu item EX060118 (table 0xFFF8E1A0[223]) */

void ai_ex060118(void)

{
  FUN_fffebf4d(1);
  return;
}


// ===== ai_ex060201 @ fffec135 (6 bytes)

/* AI change detector for menu item EX060201 (table 0xFFF8E1A0[224]) */

void ai_ex060201(void)

{
  FUN_fffea63a(2);
  return;
}


// ===== ai_ex060202 @ fffec13b (6 bytes)

/* AI change detector for menu item EX060202 (table 0xFFF8E1A0[225]) */

void ai_ex060202(void)

{
  FUN_fffea88c(2);
  return;
}


// ===== ai_ex060203 @ fffec141 (6 bytes)

/* AI change detector for menu item EX060203 (table 0xFFF8E1A0[226]) */

void ai_ex060203(void)

{
  FUN_fffeaa08(2);
  return;
}

