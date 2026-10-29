// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffbdf98 @ fffbdf98 (416 bytes)

void FUN_fffbdf98(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbStack_8;
  byte *pbStack_4;
  
  bVar2 = false;
  if (PTR_DAT_00025d54[0x74] != '\0') {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
    goto LAB_fffbe12e;
  }
  PTR_DAT_00025d54[0x74] = 1;
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d09;
  }
  else {
    pbStack_4 = &DAT_00009d63;
  }
  uVar3 = *pbStack_4 & 0xf;
  if (uVar3 == 0xe) {
LAB_fffbe052:
    pbStack_8 = pbStack_4 + 0x28;
  }
  else if (uVar3 - 2 < 2) {
    pbStack_8 = pbStack_4 + 0x14;
    bVar2 = true;
  }
  else if (uVar3 - 4 < 2) {
    pbStack_8 = pbStack_4 + 0x32;
  }
  else {
    if (1 < uVar3 - 6) {
      if (uVar3 - 8 < 2) goto LAB_fffbe052;
      if (1 < uVar3 - 10) {
        if (uVar3 - 0xc < 2) {
          pbStack_8 = pbStack_4 + 0x1e;
        }
        else {
          if ((*pbStack_4 & 0xf) != 0 && uVar3 != 1) {
            return;
          }
          pbStack_8 = pbStack_4 + 10;
        }
        goto LAB_fffbe05b;
      }
    }
    pbStack_8 = pbStack_4 + 0x3c;
  }
LAB_fffbe05b:
  if (PTR_DAT_00025d54[0x73] == '\x02') {
    bVar1 = *pbStack_8;
    if ((bVar1 & 0x80) == 0) {
      *pbStack_8 = bVar1 | 0x80;
    }
    else {
      *pbStack_8 = bVar1 & 0x7f;
    }
  }
  else if (PTR_DAT_00025d54[0x73] == '\x03') {
    if (bVar2) {
      if (PTR_DAT_00025d54[0x47a] == '\0') {
        bVar1 = *pbStack_8;
        if ((bVar1 & 0x40) == 0) {
          *pbStack_8 = bVar1 | 0x40;
        }
        else {
          *pbStack_8 = bVar1 & 0xbf;
        }
      }
      else if (PTR_DAT_00025d54[0x47a] == '\x01') {
        bVar1 = *pbStack_8;
        if ((bVar1 & 0x20) == 0) {
          *pbStack_8 = bVar1 | 0x20;
        }
        else {
          *pbStack_8 = bVar1 & 0xdf;
        }
      }
    }
    else {
      bVar1 = *pbStack_8;
      if ((bVar1 & 0x40) == 0) {
        *pbStack_8 = bVar1 | 0x40;
      }
      else {
        *pbStack_8 = bVar1 & 0xbf;
      }
    }
  }
  PTR_DAT_00025d54[0x72] = 1;
  swtimer_start(0x45,0x1c2);
  FUN_fffc89b0();
LAB_fffbe12e:
  beep_request(1);
  return;
}


// ===== FUN_fffbe138 @ fffbe138 (7 bytes)

void FUN_fffbe138(void)

{
  FUN_fffc1ede(0xd0);
  return;
}


// ===== FUN_fffbe13f @ fffbe13f (7 bytes)

void FUN_fffbe13f(void)

{
  FUN_fffc1ede(0xd1);
  return;
}


// ===== FUN_fffbe146 @ fffbe146 (7 bytes)

void FUN_fffbe146(void)

{
  FUN_fffc1ede(0xd2);
  return;
}


// ===== FUN_fffbe14d @ fffbe14d (7 bytes)

void FUN_fffbe14d(void)

{
  FUN_fffc1ede(0xd3);
  return;
}


// ===== FUN_fffbe154 @ fffbe154 (7 bytes)

void FUN_fffbe154(void)

{
  FUN_fffc1ede(0xd4);
  return;
}


// ===== FUN_fffbe15b @ fffbe15b (7 bytes)

void FUN_fffbe15b(void)

{
  FUN_fffc1ede(0xd5);
  return;
}


// ===== FUN_fffbe162 @ fffbe162 (7 bytes)

void FUN_fffbe162(void)

{
  FUN_fffc1ede(0xd6);
  return;
}


// ===== FUN_fffbe169 @ fffbe169 (7 bytes)

void FUN_fffbe169(void)

{
  FUN_fffc1ede(0xd7);
  return;
}


// ===== FUN_fffbe170 @ fffbe170 (7 bytes)

void FUN_fffbe170(void)

{
  FUN_fffc1ede(0xd8);
  return;
}


// ===== FUN_fffbe177 @ fffbe177 (7 bytes)

void FUN_fffbe177(void)

{
  FUN_fffc1ede(0xd9);
  return;
}


// ===== FUN_fffbe17e @ fffbe17e (7 bytes)

void FUN_fffbe17e(void)

{
  FUN_fffc1ede(0xda);
  return;
}


// ===== FUN_fffbe185 @ fffbe185 (7 bytes)

void FUN_fffbe185(void)

{
  FUN_fffc1ede(0xdb);
  return;
}


// ===== FUN_fffbe18c @ fffbe18c (7 bytes)

void FUN_fffbe18c(void)

{
  FUN_fffc1ede(0xdc);
  return;
}


// ===== FUN_fffbe193 @ fffbe193 (7 bytes)

void FUN_fffbe193(void)

{
  FUN_fffc1ede(0xdd);
  return;
}


// ===== FUN_fffbe19a @ fffbe19a (7 bytes)

void FUN_fffbe19a(void)

{
  FUN_fffc1ede(0xde);
  return;
}


// ===== FUN_fffbe1a1 @ fffbe1a1 (7 bytes)

void FUN_fffbe1a1(void)

{
  FUN_fffc1ede(0xdf);
  return;
}


// ===== FUN_fffbe1a8 @ fffbe1a8 (7 bytes)

void FUN_fffbe1a8(void)

{
  FUN_fffc1ede(0xe0);
  return;
}


// ===== FUN_fffbe1af @ fffbe1af (10 bytes)

void FUN_fffbe1af(void)

{
  FUN_fffc1ede(0xe1);
  FUN_fffc5290();
  return;
}


// ===== FUN_fffbe1b9 @ fffbe1b9 (7 bytes)

void FUN_fffbe1b9(void)

{
  FUN_fffc1ede(0xe2);
  return;
}


// ===== FUN_fffbe1c0 @ fffbe1c0 (7 bytes)

void FUN_fffbe1c0(void)

{
  FUN_fffc1ede(0xe3);
  return;
}


// ===== FUN_fffbe1c7 @ fffbe1c7 (7 bytes)

void FUN_fffbe1c7(void)

{
  FUN_fffc1ede(0xe4);
  return;
}


// ===== FUN_fffbe1ce @ fffbe1ce (7 bytes)

void FUN_fffbe1ce(void)

{
  FUN_fffc1ede(0xe5);
  return;
}


// ===== FUN_fffbe1d5 @ fffbe1d5 (7 bytes)

void FUN_fffbe1d5(void)

{
  FUN_fffc1ede(0xe6);
  return;
}


// ===== FUN_fffbe1dc @ fffbe1dc (7 bytes)

void FUN_fffbe1dc(void)

{
  FUN_fffc1ede(0xe7);
  return;
}


// ===== FUN_fffbe1e3 @ fffbe1e3 (7 bytes)

void FUN_fffbe1e3(void)

{
  FUN_fffc1ede(0xe8);
  return;
}


// ===== FUN_fffbe1ea @ fffbe1ea (7 bytes)

void FUN_fffbe1ea(void)

{
  FUN_fffc1ede(0xe9);
  return;
}


// ===== FUN_fffbe1f1 @ fffbe1f1 (7 bytes)

void FUN_fffbe1f1(void)

{
  FUN_fffc1ede(0xec);
  return;
}


// ===== FUN_fffbe1f8 @ fffbe1f8 (1 bytes)

void FUN_fffbe1f8(void)

{
  return;
}


// ===== FUN_fffbe1f9 @ fffbe1f9 (7 bytes)

void FUN_fffbe1f9(void)

{
  FUN_fffc1ede(0xed);
  return;
}


// ===== FUN_fffbe200 @ fffbe200 (7 bytes)

void FUN_fffbe200(void)

{
  FUN_fffc1ede(0xee);
  return;
}


// ===== FUN_fffbe207 @ fffbe207 (7 bytes)

void FUN_fffbe207(void)

{
  FUN_fffc1ede(0xef);
  return;
}


// ===== FUN_fffbe20e @ fffbe20e (7 bytes)

void FUN_fffbe20e(void)

{
  FUN_fffc1ede(0xf0);
  return;
}


// ===== FUN_fffbe215 @ fffbe215 (7 bytes)

void FUN_fffbe215(void)

{
  FUN_fffc1ede(0xf1);
  return;
}


// ===== FUN_fffbe21c @ fffbe21c (7 bytes)

void FUN_fffbe21c(void)

{
  FUN_fffc1ede(0xf2);
  return;
}


// ===== FUN_fffbe223 @ fffbe223 (7 bytes)

void FUN_fffbe223(void)

{
  FUN_fffc1ede(0xf3);
  return;
}


// ===== FUN_fffbe22a @ fffbe22a (7 bytes)

void FUN_fffbe22a(void)

{
  FUN_fffc0b2f(0xfe);
  return;
}


// ===== FUN_fffbe231 @ fffbe231 (1 bytes)

void FUN_fffbe231(void)

{
  return;
}


// ===== FUN_fffbe232 @ fffbe232 (7 bytes)

void FUN_fffbe232(void)

{
  FUN_fffc0b2f(0xff);
  return;
}


// ===== FUN_fffbe239 @ fffbe239 (6 bytes)

void FUN_fffbe239(void)

{
  FUN_fffc1fb6(0);
  return;
}


// ===== FUN_fffbe23f @ fffbe23f (6 bytes)

void FUN_fffbe23f(void)

{
  FUN_fffc1fb6(1);
  return;
}


// ===== FUN_fffbe245 @ fffbe245 (6 bytes)

void FUN_fffbe245(void)

{
  FUN_fffc1fb6(2);
  return;
}


// ===== FUN_fffbe24b @ fffbe24b (6 bytes)

void FUN_fffbe24b(void)

{
  FUN_fffc1fb6(3);
  return;
}


// ===== FUN_fffbe251 @ fffbe251 (6 bytes)

void FUN_fffbe251(void)

{
  FUN_fffc1fb6(4);
  return;
}


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

