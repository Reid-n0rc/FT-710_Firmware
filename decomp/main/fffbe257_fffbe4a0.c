// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffbe257 @ fffbe257 (6 bytes)

void FUN_fffbe257(void)

{
  FUN_fffc1fb6(5);
  return;
}


// ===== FUN_fffbe25d @ fffbe25d (6 bytes)

void FUN_fffbe25d(void)

{
  FUN_fffc1fb6(6);
  return;
}


// ===== FUN_fffbe263 @ fffbe263 (6 bytes)

void FUN_fffbe263(void)

{
  FUN_fffc1fb6(7);
  return;
}


// ===== FUN_fffbe269 @ fffbe269 (6 bytes)

void FUN_fffbe269(void)

{
  FUN_fffc1fb6(8);
  return;
}


// ===== FUN_fffbe26f @ fffbe26f (6 bytes)

void FUN_fffbe26f(void)

{
  FUN_fffc1fb6(9);
  return;
}


// ===== FUN_fffbe275 @ fffbe275 (6 bytes)

void FUN_fffbe275(void)

{
  FUN_fffc2356(1);
  return;
}


// ===== FUN_fffbe27b @ fffbe27b (6 bytes)

void FUN_fffbe27b(void)

{
  FUN_fffc2356(2);
  return;
}


// ===== FUN_fffbe281 @ fffbe281 (6 bytes)

void FUN_fffbe281(void)

{
  FUN_fffc2356(3);
  return;
}


// ===== FUN_fffbe287 @ fffbe287 (6 bytes)

void FUN_fffbe287(void)

{
  FUN_fffc2356(4);
  return;
}


// ===== FUN_fffbe28d @ fffbe28d (6 bytes)

void FUN_fffbe28d(void)

{
  FUN_fffc2356(5);
  return;
}


// ===== FUN_fffbe293 @ fffbe293 (6 bytes)

void FUN_fffbe293(void)

{
  FUN_fffc2356(6);
  return;
}


// ===== FUN_fffbe299 @ fffbe299 (6 bytes)

void FUN_fffbe299(void)

{
  FUN_fffc2356(7);
  return;
}


// ===== FUN_fffbe29f @ fffbe29f (6 bytes)

void FUN_fffbe29f(void)

{
  FUN_fffc2356(8);
  return;
}


// ===== FUN_fffbe2a5 @ fffbe2a5 (6 bytes)

void FUN_fffbe2a5(void)

{
  FUN_fffc2371(0);
  return;
}


// ===== FUN_fffbe2ab @ fffbe2ab (6 bytes)

void FUN_fffbe2ab(void)

{
  FUN_fffc2371(1);
  return;
}


// ===== FUN_fffbe2b1 @ fffbe2b1 (6 bytes)

void FUN_fffbe2b1(void)

{
  FUN_fffc2371(2);
  return;
}


// ===== FUN_fffbe2b7 @ fffbe2b7 (6 bytes)

void FUN_fffbe2b7(void)

{
  FUN_fffc2371(3);
  return;
}


// ===== FUN_fffbe2bd @ fffbe2bd (6 bytes)

void FUN_fffbe2bd(void)

{
  FUN_fffc2371(4);
  return;
}


// ===== FUN_fffbe2c3 @ fffbe2c3 (51 bytes)

void FUN_fffbe2c3(void)

{
  byte bVar1;
  
  bVar1 = PTR_DAT_00025d54[0x3ff];
  if ((bVar1 == 4) || (bVar1 == 2)) {
    FUN_fffc238c(0);
    return;
  }
  if (bVar1 == 3) {
    FUN_fffc238c(2);
    return;
  }
  if (bVar1 < 2) {
    beep_request(1);
    FUN_fffc23a4();
    return;
  }
  return;
}


// ===== FUN_fffbe2f6 @ fffbe2f6 (15 bytes)

void FUN_fffbe2f6(void)

{
  int iVar1;
  
  iVar1 = FUN_fffcdc79();
  if (iVar1 != 1) {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe305 @ fffbe305 (30 bytes)

void FUN_fffbe305(void)

{
  FUN_fffcdc79();
  swtimer_start(0x40,0x96);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffbe323 @ fffbe323 (15 bytes)

void FUN_fffbe323(void)

{
  FUN_fffcdc79();
  swtimer_start(0x40,0x96);
  return;
}


// ===== FUN_fffbe332 @ fffbe332 (1 bytes)

void FUN_fffbe332(void)

{
  return;
}


// ===== FUN_fffbe333 @ fffbe333 (15 bytes)

void FUN_fffbe333(void)

{
  int iVar1;
  
  iVar1 = FUN_fffcdd0f();
  if (iVar1 != 1) {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe342 @ fffbe342 (30 bytes)

void FUN_fffbe342(void)

{
  FUN_fffcdd0f();
  swtimer_start(0x40,0x96);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffbe360 @ fffbe360 (15 bytes)

void FUN_fffbe360(void)

{
  FUN_fffcdd0f();
  swtimer_start(0x40,0x96);
  return;
}


// ===== FUN_fffbe36f @ fffbe36f (1 bytes)

void FUN_fffbe36f(void)

{
  return;
}


// ===== FUN_fffbe370 @ fffbe370 (24 bytes)

void FUN_fffbe370(void)

{
  PTR_DAT_00025d54[0x421] = 1;
  menu_ui_step();
  beep_request(1);
  return;
}


// ===== FUN_fffbe388 @ fffbe388 (43 bytes)

void FUN_fffbe388(void)

{
  PTR_DAT_00025d54[0x421] = 1;
  menu_ui_step();
  swtimer_start(0x40,0x96);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffbe3b3 @ fffbe3b3 (28 bytes)

void FUN_fffbe3b3(void)

{
  PTR_DAT_00025d54[0x421] = 1;
  menu_ui_step();
  swtimer_start(0x40,0x96);
  return;
}


// ===== FUN_fffbe3cf @ fffbe3cf (1 bytes)

void FUN_fffbe3cf(void)

{
  return;
}


// ===== FUN_fffbe3d0 @ fffbe3d0 (24 bytes)

void FUN_fffbe3d0(void)

{
  PTR_DAT_00025d54[0x421] = 0;
  menu_ui_step();
  beep_request(1);
  return;
}


// ===== FUN_fffbe3e8 @ fffbe3e8 (43 bytes)

void FUN_fffbe3e8(void)

{
  PTR_DAT_00025d54[0x421] = 0;
  menu_ui_step();
  swtimer_start(0x40,0x96);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffbe413 @ fffbe413 (28 bytes)

void FUN_fffbe413(void)

{
  PTR_DAT_00025d54[0x421] = 0;
  menu_ui_step();
  swtimer_start(0x40,0x96);
  return;
}


// ===== FUN_fffbe42f @ fffbe42f (1 bytes)

void FUN_fffbe42f(void)

{
  return;
}


// ===== FUN_fffbe430 @ fffbe430 (8 bytes)

void FUN_fffbe430(void)

{
  FUN_fffc0b2f(0x140);
  return;
}


// ===== FUN_fffbe438 @ fffbe438 (8 bytes)

void FUN_fffbe438(void)

{
  FUN_fffc0b2f(0x141);
  return;
}


// ===== FUN_fffbe440 @ fffbe440 (8 bytes)

void FUN_fffbe440(void)

{
  FUN_fffc0b2f(0x142);
  return;
}


// ===== FUN_fffbe448 @ fffbe448 (8 bytes)

void FUN_fffbe448(void)

{
  FUN_fffc0b2f(0x143);
  return;
}


// ===== FUN_fffbe450 @ fffbe450 (8 bytes)

void FUN_fffbe450(void)

{
  FUN_fffc0b2f(0x144);
  return;
}


// ===== FUN_fffbe458 @ fffbe458 (8 bytes)

void FUN_fffbe458(void)

{
  FUN_fffc0b2f(0x145);
  return;
}


// ===== FUN_fffbe460 @ fffbe460 (8 bytes)

void FUN_fffbe460(void)

{
  FUN_fffc0b2f(0x146);
  return;
}


// ===== FUN_fffbe468 @ fffbe468 (8 bytes)

void FUN_fffbe468(void)

{
  FUN_fffc0b2f(0x147);
  return;
}


// ===== FUN_fffbe470 @ fffbe470 (8 bytes)

void FUN_fffbe470(void)

{
  FUN_fffc0b2f(0x148);
  return;
}


// ===== FUN_fffbe478 @ fffbe478 (8 bytes)

void FUN_fffbe478(void)

{
  FUN_fffc0b2f(0x149);
  return;
}


// ===== FUN_fffbe480 @ fffbe480 (8 bytes)

void FUN_fffbe480(void)

{
  FUN_fffc0b2f(0x150);
  return;
}


// ===== FUN_fffbe488 @ fffbe488 (8 bytes)

void FUN_fffbe488(void)

{
  FUN_fffc0b2f(0x151);
  return;
}


// ===== FUN_fffbe490 @ fffbe490 (8 bytes)

void FUN_fffbe490(void)

{
  FUN_fffc0b2f(0x152);
  return;
}


// ===== FUN_fffbe498 @ fffbe498 (8 bytes)

void FUN_fffbe498(void)

{
  FUN_fffc0b2f(0x153);
  return;
}


// ===== FUN_fffbe4a0 @ fffbe4a0 (8 bytes)

void FUN_fffbe4a0(void)

{
  FUN_fffc0b2f(0x154);
  return;
}

