// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== eeprom_write_raw @ fffb0651 (19 bytes)

/* Wrapper eeprom_write(addr,buf,n); used by SPW */

void eeprom_write_raw(undefined2 param_1,undefined4 param_2,undefined2 param_3)

{
  eeprom_write(param_1,param_2,param_3);
  return;
}


// ===== FUN_fffb0664 @ fffb0664 (129 bytes)

void FUN_fffb0664(int param_1)

{
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0xe) = 0xb80b9600;
  *(undefined4 *)(param_1 + 10) = 0x96004004;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x14) = 0x96004005;
  *(undefined2 *)(param_1 + 0x26) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x1e) = 0x96004004;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0x800c9600;
  *(undefined4 *)(param_1 + 0x28) = 0x96004004;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x36) = 0x28239600;
  *(undefined4 *)(param_1 + 0x32) = 0x96007004;
  *(undefined2 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x803e9600;
  *(undefined4 *)(param_1 + 0x3c) = 0x96004001;
  return;
}


// ===== defaults_vfo @ fffb06e5 (148 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Default VFO-A/B working records 0x9D09/0x9D63 (dest-dependent byte +0x46) */

void defaults_vfo(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  sVar1 = dest_code_get();
  uRam00009d11 = 0;
  _DAT_00009d0d = &DAT_00010200;
  _DAT_00009d09 = 0x80040040;
  puVar2 = &DAT_00009d4f;
  puVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(&DAT_00009d09);
  uRam00009d6b = 0;
  _DAT_00009d67 = &DAT_00010200;
  _DAT_00009d63 = 0x80040040;
  puVar2 = &DAT_00009da9;
  puVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664();
  DAT_00009dbd = 0;
  if (((sVar1 != 0x20b) && (sVar1 != 0x4380)) && (sVar1 != 0x60e6)) {
    return;
  }
  DAT_00009d4f = 8;
  DAT_00009da9 = 8;
  return;
}


// ===== FUN_fffb0779 @ fffb0779 (687 bytes)

void FUN_fffb0779(undefined4 *param_1)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  sVar1 = dest_code_get();
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[1] = &DAT_00010200;
  *param_1 = 0x80040042;
  puVar2 = (undefined1 *)((int)param_1 + 0x46);
  puVar4 = &DAT_fff8090b;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(param_1);
  *(undefined2 *)((int)param_1 + 0x62) = 0;
  *(undefined **)((int)param_1 + 0x5e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x5a) = 0x80040040;
  puVar3 = param_1 + 0x28;
  puVar2 = &DAT_fff8091f;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x2f) = 0;
  param_1[0x2e] = &DAT_00010200;
  param_1[0x2d] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0xfa);
  puVar4 = &DAT_fff80933;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x116) = 0;
  *(undefined **)((int)param_1 + 0x112) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x10e) = 0x80040040;
  puVar3 = param_1 + 0x55;
  puVar2 = &DAT_fff80947;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x5c) = 0;
  param_1[0x5b] = &DAT_00010200;
  param_1[0x5a] = 0x80040042;
  puVar2 = (undefined1 *)((int)param_1 + 0x1ae);
  puVar4 = &DAT_fff8095b;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x1ca) = 0;
  *(undefined **)((int)param_1 + 0x1c6) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x1c2) = 0x800400c1;
  puVar3 = param_1 + 0x82;
  puVar2 = &DAT_fff8096f;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x89) = 0;
  param_1[0x88] = &DAT_00010200;
  param_1[0x87] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x262);
  puVar4 = &DAT_fff80983;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x27e) = 0;
  *(undefined **)((int)param_1 + 0x27a) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x276) = 0x800400c1;
  puVar3 = param_1 + 0xaf;
  puVar2 = &DAT_fff80997;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0xb6) = 0;
  param_1[0xb5] = &DAT_00010200;
  param_1[0xb4] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x316);
  puVar4 = &DAT_fff809ab;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x332) = 0;
  *(undefined **)((int)param_1 + 0x32e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x32a) = 0x800400c1;
  puVar3 = param_1 + 0xdc;
  puVar2 = &DAT_fff809bf;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0xe3) = 1;
  param_1[0xe2] = &DAT_00010200;
  param_1[0xe1] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x3ca);
  puVar4 = &DAT_fff809d3;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x3e6) = 0;
  *(undefined **)((int)param_1 + 0x3e2) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x3de) = 0x800400c1;
  puVar3 = param_1 + 0x109;
  puVar2 = &DAT_fff809e7;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  if (((sVar1 != 0x20b) && (sVar1 != 0x4380)) && (sVar1 != 0x60e6)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x46) = 8;
  *(undefined1 *)(param_1 + 0x28) = 8;
  *(undefined1 *)((int)param_1 + 0xfa) = 8;
  *(undefined1 *)(param_1 + 0x55) = 8;
  *(undefined1 *)((int)param_1 + 0x1ae) = 8;
  *(undefined1 *)(param_1 + 0x82) = 8;
  *(undefined1 *)((int)param_1 + 0x262) = 8;
  *(undefined1 *)(param_1 + 0xaf) = 8;
  *(undefined1 *)((int)param_1 + 0x316) = 8;
  *(undefined1 *)(param_1 + 0xdc) = 8;
  *(undefined1 *)((int)param_1 + 0x3ca) = 8;
  *(undefined1 *)(param_1 + 0x109) = 8;
  return;
}


// ===== defaults_bandstack @ fffb0a28 (84 bytes)

/* Clears 0x4761..0x60C8 and fills 6 band-stack sets (FUN_fffb0779 per set) */

void defaults_bandstack(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar1 = &DAT_00004761;
  for (puVar2 = &DAT_00001968; puVar2 != (undefined *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  FUN_fffb0779(&DAT_00004761);
  FUN_fffb0779(0x4b99);
  FUN_fffb0779(0x4fd1);
  FUN_fffb0779(&DAT_00005409);
  FUN_fffb0779(0x5841);
  FUN_fffb0779(0x5c79);
  return;
}


// ===== defaults_qmb @ fffb0a7c (19 bytes)

/* Clears the QMB block 0x9012 (0x395) */

void defaults_qmb(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)&DAT_00009012;
  for (iVar2 = 0x395; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return;
}


// ===== defaults_memch @ fffb0a8f (1557 bytes)

/* Clears 0x60C9 (0x2F49), default records for 117 channels, dest-specific 60 m channels */

void defaults_memch(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  byte bStack_b;
  
  sVar1 = dest_code_get();
  puVar2 = (undefined4 *)&DAT_000060c9;
  for (puVar5 = &DAT_00002f49; puVar5 != (undefined *)0x0; puVar5 = puVar5 + -1) {
    *puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  puVar2 = (undefined4 *)&DAT_000060c9;
  for (iVar6 = 0x22; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  DAT_000060cb = 1;
  for (bStack_b = 0; bStack_b < 0x75; bStack_b = bStack_b + 1) {
    iVar6 = (uint)bStack_b * 0x5a;
    *(undefined2 *)(iVar6 + 0x6158) = 0;
    *(undefined **)(iVar6 + 0x6154) = &DAT_00010200;
    *(undefined4 *)(&DAT_00006150 + iVar6) = 0x80040040;
    puVar3 = (undefined1 *)(iVar6 + 0x6196);
    puVar4 = &DAT_fff80947;
    for (iVar7 = 0x14; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(&DAT_00006150 + iVar6);
  }
  if (sVar1 == -0x26b0) {
LAB_fffb0e99:
    uRam00008a7a = 0;
    puRam00008a76 = &DAT_00030200;
    uRam00008a72 = 0x80040101;
    puVar3 = (undefined1 *)0x8ab8;
    puVar4 = &DAT_fff80b4f;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8a72);
    uRam00008ad4 = 0;
    puRam00008ad0 = &DAT_00030200;
    uRam00008acc = 0x80040101;
    puVar3 = (undefined1 *)0x8b12;
    puVar4 = &DAT_fff80b63;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8acc);
    uRam00008b2e = 0;
    puRam00008b2a = &DAT_00030200;
    uRam00008b26 = 0x80040101;
    puVar3 = (undefined1 *)0x8b6c;
    puVar4 = &DAT_fff80b77;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8b26);
    uRam00008b88 = 0;
    puRam00008b84 = &DAT_00030200;
    uRam00008b80 = 0x80040101;
    puVar3 = (undefined1 *)0x8bc6;
    puVar4 = &DAT_fff80b8b;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8b80);
    uRam00008be2 = 0;
    puRam00008bde = &DAT_00030200;
    uRam00008bda = 0x80040101;
    puVar3 = (undefined1 *)0x8c20;
    puVar4 = &DAT_fff80b9f;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8bda);
    uRam00008c3c = 0;
    puRam00008c38 = &DAT_00030200;
    uRam00008c34 = 0x80040101;
    puVar3 = (undefined1 *)0x8c7a;
    puVar4 = &DAT_fff80bb3;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8c34);
    uRam00008c96 = 0;
    puRam00008c92 = &DAT_00030200;
    uRam00008c8e = 0x80040101;
    puVar3 = (undefined1 *)0x8cd4;
    puVar4 = &DAT_fff80bc7;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8c8e);
    uRam00008cf0 = 0;
    puRam00008cec = &DAT_00030200;
    uRam00008ce8 = 0x80040101;
    puVar3 = (undefined1 *)0x8d2e;
    puVar4 = &DAT_fff80bdb;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8ce8);
    uRam00008d4a = 0;
    puRam00008d46 = &DAT_00030200;
    uRam00008d42 = 0x80040101;
    puVar3 = (undefined1 *)0x8d88;
    puVar4 = &DAT_fff80bef;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8d42);
    uRam00008da4 = 0;
    puRam00008da0 = &DAT_00030200;
    uRam00008d9c = 0x80040101;
    puVar3 = (undefined1 *)0x8de2;
    puVar4 = &DAT_fff80c03;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8d9c);
    return;
  }
  if (sVar1 == 0x1cb9) {
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040101;
    puVar3 = (undefined1 *)0x8ffe;
    puVar4 = &DAT_fff80c21;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
  if (sVar1 != 0x315b) {
    if (sVar1 != 0x4380) {
      if (sVar1 == 0x50e2) goto LAB_fffb0b88;
      if (sVar1 != 0x60e6) {
        if (sVar1 == -0x5b3b) goto LAB_fffb0e99;
        if (sVar1 != 0x20b) {
          return;
        }
      }
    }
    uRam00006196 = 8;
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040003;
    puVar3 = (undefined1 *)0x8ffe;
    puVar4 = &DAT_fff80c3f;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
LAB_fffb0b88:
  for (bStack_b = 0; bStack_b < 0xf; bStack_b = bStack_b + 1) {
    (&DAT_00006140)[bStack_b] = 1;
  }
  uRam00008a7a = 0;
  puRam00008a76 = &DAT_00030200;
  uRam00008a72 = 0x80040101;
  puVar3 = (undefined1 *)0x8ab8;
  puVar4 = &DAT_fff80a19;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8a72);
  uRam00008ad4 = 0;
  puRam00008ad0 = &DAT_00030200;
  uRam00008acc = 0x80040101;
  puVar3 = (undefined1 *)0x8b12;
  puVar4 = &DAT_fff80a2d;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8acc);
  uRam00008b2e = 0;
  puRam00008b2a = &DAT_00030200;
  uRam00008b26 = 0x80040101;
  puVar3 = (undefined1 *)0x8b6c;
  puVar4 = &DAT_fff80a41;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8b26);
  uRam00008b88 = 0;
  puRam00008b84 = &DAT_00030200;
  uRam00008b80 = 0x80040101;
  puVar3 = (undefined1 *)0x8bc6;
  puVar4 = &DAT_fff80a55;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8b80);
  uRam00008be2 = 0;
  puRam00008bde = &DAT_00030200;
  uRam00008bda = 0x80040101;
  puVar3 = (undefined1 *)0x8c20;
  puVar4 = &DAT_fff80a69;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8bda);
  uRam00008c3c = 0;
  puRam00008c38 = &DAT_00030200;
  uRam00008c34 = 0x80040103;
  puVar3 = (undefined1 *)0x8c7a;
  puVar4 = &DAT_fff80a7d;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8c34);
  uRam00008c96 = 0;
  puRam00008c92 = &DAT_00030200;
  uRam00008c8e = 0x80040103;
  puVar3 = (undefined1 *)0x8cd4;
  puVar4 = &DAT_fff80a91;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8c8e);
  uRam00008cf0 = 0;
  puRam00008cec = &DAT_00030200;
  uRam00008ce8 = 0x80040103;
  puVar3 = (undefined1 *)0x8d2e;
  puVar4 = &DAT_fff80aa5;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8ce8);
  uRam00008d4a = 0;
  puRam00008d46 = &DAT_00030200;
  uRam00008d42 = 0x80040103;
  puVar3 = (undefined1 *)0x8d88;
  puVar4 = &DAT_fff80ab9;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8d42);
  uRam00008da4 = 0;
  puRam00008da0 = &DAT_00030200;
  uRam00008d9c = 0x80040103;
  puVar3 = (undefined1 *)0x8de2;
  puVar4 = &DAT_fff80acd;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8d9c);
  uRam00008dfe = 0;
  puRam00008dfa = &DAT_00030200;
  uRam00008df6 = 0x80040109;
  puVar3 = (undefined1 *)0x8e3c;
  puVar4 = &DAT_fff80ae1;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8df6);
  uRam00008e58 = 0;
  puRam00008e54 = &DAT_00030200;
  uRam00008e50 = 0x80040109;
  puVar3 = (undefined1 *)0x8e96;
  puVar4 = &DAT_fff80af5;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8e50);
  uRam00008eb2 = 0;
  puRam00008eae = &DAT_00030200;
  uRam00008eaa = 0x80040109;
  puVar3 = (undefined1 *)0x8ef0;
  puVar4 = &DAT_fff80b09;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8eaa);
  uRam00008f0c = 0;
  puRam00008f08 = &DAT_00030200;
  uRam00008f04 = 0x80040109;
  puVar3 = (undefined1 *)0x8f4a;
  puVar4 = &DAT_fff80b1d;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8f04);
  uRam00008f66 = 0;
  puRam00008f62 = &DAT_00030200;
  uRam00008f5e = 0x80040109;
  puVar3 = (undefined1 *)0x8fa4;
  puVar4 = &DAT_fff80b31;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8f5e);
  uRam00008fc0 = 0;
  puRam00008fbc = &DAT_00030200;
  uRam00008fb8 = 0x80040101;
  puVar3 = (undefined1 *)0x8ffe;
  puVar4 = &DAT_fff80c21;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(0x8fb8);
  return;
}


// ===== defaults_msg @ fffb10a4 (196 bytes)

/* Clears 0x93A7 (0x4F1), keyer texts from ROM 0xFFF80C53.. */

void defaults_msg(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar1 = &DAT_000093a7;
  for (iVar4 = 0x4f1; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  puVar2 = &DAT_0000969f;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_000096d2;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_00009705;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_00009738;
  puVar3 = &DAT_fff80c86;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_0000976b;
  puVar3 = &DAT_fff80cb9;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_0000979e;
  puVar2 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_000097d0;
  puVar2 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009802;
  puVar2 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009834;
  puVar2 = &DAT_fff80d1e;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009866;
  puVar2 = &DAT_fff80d50;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_load @ fffb1168 (43 bytes)

/* Reset menu value block 0x9A2A.. from ROM 0xFFF80E4A.. (callees below) + 0x9C17<-0xFFF80FD6 */

void menu_defaults_load(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  menu_defaults_mode();
  menu_defaults_cw();
  menu_defaults_operation();
  menu_defaults_display();
  FUN_fffb1303();
  menu_defaults_presets();
  FUN_fffb13e2();
  puVar1 = &DAT_00009c17;
  puVar2 = &DAT_fff80fd6;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_mode @ fffb1193 (93 bytes)

/* RADIO SETTING mode groups 0x9A2A..0x9A90 <- ROM */

void menu_defaults_mode(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80e4a;
  puVar1 = &DAT_00009a2a;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a3f;
  puVar2 = &DAT_fff80e5f;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a52;
  puVar2 = &DAT_fff80e72;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a67;
  puVar2 = &DAT_fff80e87;
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a7e;
  puVar2 = &DAT_fff80e9e;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_cw @ fffb11f0 (29 bytes)

/* CW SETTING 0x9A91..0x9AB4 <- ROM 0xFFF80EB1 */

void menu_defaults_cw(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80eb1;
  puVar1 = &DAT_00009a91;
  for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_operation @ fffb120d (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb12c1) */
/* WARNING: Removing unreachable block (ram,0xfffb12e3) */
/* WARNING: Removing unreachable block (ram,0xfffb12c9) */
/* WARNING: Removing unreachable block (ram,0xfffb12d6) */
/* OPERATION SETTING 0x9AB5.. <- ROM 0xFFF80ED5, then dest-dependent MAX POWER, KEYBOARD LANGUAGE,
   TX TOT */

undefined1 * menu_defaults_operation(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  sVar1 = dest_code_get();
  puVar3 = &DAT_fff80ed5;
  puVar2 = &DAT_00009ab5;
  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_00009aee = FUN_fffb3e6f(0);
  DAT_00009aef = FUN_fffb3e6f(1);
  DAT_00009af0 = FUN_fffb3e6f(2);
  if (sVar1 == 0x60e6) {
    DAT_00009af1 = FUN_fffb3e6f(4);
  }
  else {
    DAT_00009af1 = FUN_fffb3e6f(3);
  }
  if (sVar1 == -0x26b0) {
LAB_fffb12d9:
    DAT_00009ac7 = 2;
    DAT_00009ac3 = 10;
    return &DAT_00009ab5;
  }
  if (((sVar1 != 0x1cb9) && (sVar1 != 0x306f)) && (sVar1 != 0x315b)) {
    if (sVar1 == 0x4380) {
LAB_fffb12bc:
      DAT_00009ac7 = 0;
      return &DAT_00009ab5;
    }
    if (sVar1 != 0x50e2) {
      if (sVar1 == 0x60e6) goto LAB_fffb12bc;
      if ((sVar1 != 0x7753) && (sVar1 != -0x6309)) {
        if (sVar1 == -0x5b3b) goto LAB_fffb12d9;
        if (sVar1 != -0x2cd3) {
          if (sVar1 != 0x20b) {
            DAT_00009ac7 = 5;
            DAT_00009ac3 = 10;
            return &DAT_00009ab5;
          }
          goto LAB_fffb12bc;
        }
      }
    }
  }
  DAT_00009ac7 = 1;
  return &DAT_00009ab5;
}


// ===== menu_defaults_display @ fffb12e6 (29 bytes)

/* DISPLAY SETTING 0x9B01.. <- ROM 0xFFF80F21 */

void menu_defaults_display(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80f21;
  puVar1 = &DAT_00009b01;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fffb1303 @ fffb1303 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb1303(void)

{
  _DAT_00009b2c = 0;
  _DAT_00009b28 = 0;
  _DAT_00009b24 = 0;
  return;
}


// ===== menu_defaults_presets @ fffb1325 (189 bytes)

/* 5 x PRESET block 0x9B2E+0x1F*n <- ROM 0xFFF80F4E; names FT-8, PRESET2..5 */

void menu_defaults_presets(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80f4e;
  puVar1 = &DAT_00009b2e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b4d;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b6c;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b8b;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009baa;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  DAT_00009b2e = 0x382d5446;
  DAT_00009b51._2_1_ = 0x32;
  DAT_00009b51._0_2_ = 0x5445;
  DAT_00009b4d = 0x53455250;
  DAT_00009b70._0_2_ = 0x5445;
  DAT_00009b70._2_1_ = 0x33;
  DAT_00009b6c = 0x53455250;
  DAT_00009b8f._2_1_ = 0x34;
  DAT_00009b8f._0_2_ = 0x5445;
  DAT_00009b8b = 0x53455250;
  DAT_00009bae._2_1_ = 0x35;
  DAT_00009bae._0_2_ = 0x5445;
  DAT_00009baa = 0x53455250;
  DAT_00009bc9 = 0;
  return;
}


// ===== FUN_fffb13e2 @ fffb13e2 (73 bytes)

void FUN_fffb13e2(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = "2222222222222222222222222222";
  pcVar1 = &DAT_00009bca;
  for (iVar3 = 0x4d; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  DAT_00009bf8 = DAT_00009aee;
  DAT_00009bf9 = DAT_00009aef;
  DAT_00009bfa = DAT_00009af0;
  DAT_00009bfb = DAT_00009af1;
  return;
}


// ===== eeprom_hdr_update @ fffb142b (121 bytes)

/* Increments the save counter in the EEPROM header mirror 0x464F and writes 10 bytes at EEPROM 0 */

void eeprom_hdr_update(undefined1 param_1)

{
  uint local_8;
  byte local_2;
  
  local_8 = 0;
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    local_8 = (uint)*(byte *)((int)&DAT_00004653 + local_2 + 1) << (3 - local_2 & 3) * 8 | local_8;
  }
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    *(char *)((int)&DAT_00004653 + local_2 + 1) = (char)(local_8 + 1 >> ((3 - local_2 & 3) << 3));
  }
  DAT_00004657._1_1_ = param_1;
  eeprom_write(0,&DAT_0000464f,10);
  return;
}


// ===== eeprom_read @ fffb14a4 (73 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffb14a4) */
/* WARNING: Removing unreachable block (ram,0xfffb14ea) */
/* SPI READ (0x03) + 16-bit address, reads n bytes */

ushort eeprom_read(undefined1 param_1,int param_2,ushort param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 local_10;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(3);
  eeprom_spi_tx();
  eeprom_spi_tx(param_1);
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
    uVar2 = eeprom_spi_rx();
    *(undefined1 *)((uint)local_10 + param_2) = uVar2;
  }
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  return local_10;
}


// ===== eeprom_write @ fffb14ed (189 bytes)

/* 64-byte page writes: RDSR(0x05) poll WIP, WREN(0x06), WRITE(0x02)+addr+data */

void eeprom_write(byte param_1,undefined1 *param_2,ushort param_3)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte local_c;
  byte bStack_b;
  ushort local_a;
  undefined1 *local_8;
  
  local_a = param_3;
  local_8 = param_2;
  while (local_a != 0) {
    local_c = 0x40 - (param_1 & 0x3f);
    if (local_a <= local_c) {
      local_c = (byte)local_a;
    }
    local_a = local_a - local_c;
    bVar2 = true;
    while (bVar2) {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 & 0xfe;
      eeprom_spi_tx(5);
      bVar3 = eeprom_spi_rx();
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 | 1;
      if ((bVar3 & 1) == 0) {
        bVar2 = false;
      }
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xfe;
    eeprom_spi_tx(6);
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xfe;
    eeprom_spi_tx(2);
    eeprom_spi_tx();
    eeprom_spi_tx(param_1);
    for (bStack_b = 0; bStack_b < local_c; bStack_b = bStack_b + 1) {
      eeprom_spi_tx(*local_8);
      local_8 = local_8 + 1;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 1;
    param_1 = param_1 + local_c;
  }
  return;
}


// ===== eeprom_spi_tx @ fffb15aa (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb15d6) */
/* Shift one byte out MSB first on PE6, clock PE5 */

void eeprom_spi_tx(byte param_1)

{
  byte bVar1;
  undefined1 local_2;
  undefined1 local_1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  local_1 = param_1;
  for (local_2 = 0; local_2 < 8; local_2 = local_2 + 1) {
    if ((local_1 & 0x80) == 0) {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 & 0xbf;
    }
    else {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 | 0x40;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 0x20;
    local_1 = local_1 << 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xdf;
  }
  return;
}


// ===== eeprom_spi_rx @ fffb15ef (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb15f9) */
/* Shift one byte in from PE7 (PIDR bit 7) */

byte eeprom_spi_rx(void)

{
  byte bVar1;
  char cVar2;
  undefined1 local_3;
  undefined1 local_2;
  
  local_3 = 0;
  for (local_2 = 0; local_2 < 8; local_2 = local_2 + 1) {
    local_3 = local_3 << 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 0x20;
    cVar2 = DAT_0008c04e;
    if (cVar2 < '\0') {
      local_3 = local_3 | 1;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xdf;
  }
  return local_3;
}


// ===== sci_start_all @ fffb1632 (19 bytes)

/* From app_main: sci0_set_baud, displink_uart_start, sci2_configure, sci3_set_baud, SCI4/SCI5 start
    */

void sci_start_all(void)

{
  sci0_set_baud();
  displink_uart_start();
  sci2_configure();
  sci3_set_baud();
  FUN_fffb1a81();
  sdr_link_start();
  return;
}


// ===== sci0_set_baud @ fffb1645 (189 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb16c3) */
/* WARNING: Removing unreachable block (ram,0xfffb1689) */
/* WARNING: Removing unreachable block (ram,0xfffb166d) */
/* WARNING: Removing unreachable block (ram,0xfffb16ad) */
/* WARNING: Removing unreachable block (ram,0xfffb16ce) */
/* WARNING: Removing unreachable block (ram,0xfffb16e5) */
/* Re-configures SCI0 SMR/BRR/SEMR from table 0xFFF80FF4 (4 bytes x 5) by CAT RATE setting */

void sci0_set_baud(void)

{
  byte bVar1;
  byte local_1;
  
  bVar1 = DAT_00009abc;
  local_1 = DAT_00009abc;
  do {
  } while (DAT_00011fe8 != '\0');
  R_SCI0_Stop();
  if (4 < bVar1) {
    local_1 = 0;
  }
  bVar1 = DAT_0008a000;
  DAT_0008a000 = (&DAT_fff80ff6)[(uint)local_1 * 4] | bVar1 & 0xfc;
  DAT_0008a001 = (&DAT_fff80ff7)[(uint)local_1 * 4];
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xbf | ((&sci_baud_table)[(uint)local_1 * 4] & 1) << 6;
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xef | ((&DAT_fff80ff5)[(uint)local_1 * 4] & 1) << 4;
  R_SCI0_Start();
  R_SCI0_Serial_Receive(&DAT_0000a2b4,&DAT_000029bc);
  return;
}


// ===== displink_uart_start @ fffb1702 (28 bytes)

/* R_SCI1_Start + arm receive 0x9E86/0x204 */

void displink_uart_start(void)

{
  DAT_0000a08a = 0;
  R_SCI1_Start();
  R_SCI1_Serial_Receive(&DAT_00009e86,0x204);
  return;
}


// ===== displink_rx_ready @ fffb171e (15 bytes)

/* returns 0xA08A */

undefined1 displink_rx_ready(void)

{
  return DAT_0000a08a;
}


// ===== displink_rx_rearm @ fffb172d (24 bytes)

/* 0xA08A=0, arm receive again */

void displink_rx_rearm(void)

{
  DAT_0000a08a = 0;
  R_SCI1_Serial_Receive(&DAT_00009e86,0x204);
  return;
}


// ===== displink_rx_done @ fffb1745 (10 bytes)

/* 0xA08A=1 */

void displink_rx_done(void)

{
  DAT_0000a08a = 1;
  return;
}


// ===== displink_rx_buf @ fffb174f (12 bytes)

/* returns 0x9E86 */

void displink_rx_buf(void)

{
  return;
}


// ===== displink_uart_send @ fffb175b (16 bytes)

/* R_SCI1_Serial_Send(buf,len) */

void displink_uart_send(undefined4 param_1,undefined2 param_2)

{
  R_SCI1_Serial_Send(param_1,param_2);
  return;
}


// ===== sci1_tx_end @ fffb176b (19 bytes)

byte sci1_tx_end(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008a024;
  return bVar1 >> 2 & 1;
}


// ===== sci2_configure @ fffb177e (386 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb186a) */
/* WARNING: Removing unreachable block (ram,0xfffb1820) */
/* WARNING: Removing unreachable block (ram,0xfffb1854) */
/* WARNING: Removing unreachable block (ram,0xfffb1875) */
/* WARNING: Removing unreachable block (ram,0xfffb188c) */
/* WARNING: Removing unreachable block (ram,0xfffb1804) */
/* Selects SCI2 mode/pins by tuner/port setting and re-creates SCI2 */

void sci2_configure(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte bStack_3;
  byte bStack_1;
  
  cVar3 = tunlin_port_mode();
  R_SCI2_Stop();
  do {
  } while (DAT_00011fe9 != '\0');
  if (cVar3 != '\x01') {
    gpo_a_set(0);
    gpo_b_set(0);
    gpo_c_set(0);
    gpo_d_set(0);
  }
  if ((cVar3 == '\x03') || (cVar3 == '\x01')) {
    uVar1 = DAT_00080014;
    DAT_00080014 = uVar1 | 0x20000000;
    DAT_0008c14a = 0;
    bVar2 = DAT_0008c061;
    DAT_0008c061 = bVar2 & 0xfb;
    DAT_0008c14b = 0;
    gpo_a_dir_out();
    gpo_b_dir_out();
    gpo_c_dir(1);
    tun_lin_sel_set(0);
    rem_key_sel_set(1);
    return;
  }
  if (cVar3 == '\x02') {
    R_SCI2_Create();
    bStack_1 = DAT_00009abe;
    if (4 < DAT_00009abe) {
      bStack_1 = 3;
    }
    bVar2 = DAT_0008a040;
    bStack_3 = (&DAT_fff80ff6)[(uint)bStack_1 * 4] | bVar2 & 0xf4;
    if (DAT_00009abb != '\0') {
      bStack_3 = bStack_3 | 8;
    }
    DAT_0008a040 = bStack_3;
    DAT_0008a041 = (&DAT_fff80ff7)[(uint)bStack_1 * 4];
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xbf | ((&sci_baud_table)[(uint)bStack_1 * 4] & 1) << 6;
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xef | ((&DAT_fff80ff5)[(uint)bStack_1 * 4] & 1) << 4;
    R_SCI2_Start();
    R_SCI2_Serial_Receive(&DAT_0000cc70,&DAT_000029bc);
    gpo_c_dir(1);
    tun_lin_sel_set(1);
    rem_key_sel_set(0);
    return;
  }
  if (cVar3 == '\0') {
    R_SCI2_Create();
    R_SCI2_Start();
    gpo_c_dir(0);
    tun_lin_sel_set(1);
    rem_key_sel_set(0);
    etun_reset_set(0);
    return;
  }
  return;
}


// ===== tunlin_port_mode @ fffb1900 (30 bytes)

/* setting 0x9AB7: 0 EXT-TUNER 1 LINEAR 2 CAT-3 3 GPO */

byte tunlin_port_mode(void)

{
  undefined1 local_2;
  
  local_2 = DAT_00009ab7;
  if (3 < DAT_00009ab7) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffb191e @ fffb191e (15 bytes)

undefined1 FUN_fffb191e(void)

{
  return DAT_0000a0a9;
}


// ===== FUN_fffb192d @ fffb192d (23 bytes)

void FUN_fffb192d(void)

{
  DAT_0000a0a9 = 0;
  R_SCI2_Serial_Receive(&DAT_0000a08b,0x1e);
  return;
}


// ===== FUN_fffb1944 @ fffb1944 (10 bytes)

void FUN_fffb1944(void)

{
  DAT_0000a0a9 = 1;
  return;
}


// ===== FUN_fffb194e @ fffb194e (12 bytes)

void FUN_fffb194e(void)

{
  return;
}


// ===== FUN_fffb195a @ fffb195a (28 bytes)

void FUN_fffb195a(undefined4 param_1,undefined2 param_2)

{
  R_SCI2_Serial_Send(param_1,param_2);
  FUN_fffb192d();
  DAT_0000a0aa = 1;
  return;
}


// ===== FUN_fffb1976 @ fffb1976 (10 bytes)

void FUN_fffb1976(void)

{
  DAT_0000a0aa = 0;
  return;
}


// ===== sci3_set_baud @ fffb198f (242 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1a42) */
/* WARNING: Removing unreachable block (ram,0xfffb1a00) */
/* WARNING: Removing unreachable block (ram,0xfffb19e4) */
/* WARNING: Removing unreachable block (ram,0xfffb1a2c) */
/* WARNING: Removing unreachable block (ram,0xfffb1a4d) */
/* WARNING: Removing unreachable block (ram,0xfffb1a64) */
/* Re-configures SCI3 baud from table 0xFFF80FF4 */

void sci3_set_baud(void)

{
  byte bVar1;
  char local_4;
  byte bStack_3;
  byte local_1;
  
  do {
  } while (DAT_00011fea != '\0');
  if (DAT_00009dc6 == '\0') {
    local_1 = DAT_00009ab9;
    local_4 = DAT_00009abb;
  }
  else {
    local_1 = DAT_00020b58;
    local_4 = DAT_00020b5a;
  }
  R_SCI3_Stop();
  if (4 < local_1) {
    local_1 = 3;
  }
  bVar1 = DAT_0008a060;
  bStack_3 = (&DAT_fff80ff6)[(uint)local_1 * 4] | bVar1 & 0xf4;
  if (local_4 != '\0') {
    bStack_3 = bStack_3 | 8;
  }
  DAT_0008a060 = bStack_3;
  DAT_0008a061 = (&DAT_fff80ff7)[(uint)local_1 * 4];
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xbf | ((&sci_baud_table)[(uint)local_1 * 4] & 1) << 6;
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xef | ((&DAT_fff80ff5)[(uint)local_1 * 4] & 1) << 4;
  R_SCI3_Start();
  R_SCI3_Serial_Receive(&DAT_0000f62c,&DAT_000029bc);
  return;
}


// ===== FUN_fffb1a81 @ fffb1a81 (14 bytes)

void FUN_fffb1a81(void)

{
  DAT_0000a2ab = 0;
  R_SCI4_Start();
  return;
}


// ===== sci4_rx_ready @ fffb1a8f (15 bytes)

/* Returns 0xA2AB (SCI4 frame complete) */

undefined1 sci4_rx_ready(void)

{
  return DAT_0000a2ab;
}


// ===== sci4_rx_set_ready @ fffb1a9e (10 bytes)

/* 0xA2AB=1 */

void sci4_rx_set_ready(void)

{
  DAT_0000a2ab = 1;
  return;
}


// ===== sci4_rx_buf @ fffb1aa8 (12 bytes)

/* Returns the SCI4 receive buffer (0xA0AB) [decompiler lost the return value] */

void sci4_rx_buf(void)

{
  return;
}


// ===== sci4_send @ fffb1ab4 (39 bytes)

/* R_SCI4_Serial_Send then re-arm R_SCI4_Serial_Receive(0xA0AB, 0x200) */

void sci4_send(undefined4 param_1,undefined2 param_2)

{
  R_SCI4_Serial_Send(param_1,param_2);
  DAT_0000a2ab = 0;
  R_SCI4_Serial_Receive(&DAT_0000a0ab,0x200);
  return;
}


// ===== sci4_rx_set_len @ fffb1adb (14 bytes)

/* 0x1B78A=len */

void sci4_rx_set_len(undefined2 param_1)

{
  DAT_0001b78a = param_1;
  return;
}


// ===== sci4_rx_len @ fffb1ae9 (15 bytes)

/* Returns 0x1B78A */

undefined2 sci4_rx_len(void)

{
  return DAT_0001b78a;
}


// ===== sdr_link_start @ fffb1af8 (14 bytes)

/* Clears the SDR reply-ready flag 0xA2B3 and starts SCI5 (called from the SCI start-up chain
   FUN_fffb1632) */

void sdr_link_start(void)

{
  DAT_0000a2b3 = 0;
  R_SCI5_Start();
  return;
}


// ===== sdr_rx_ready @ fffb1b06 (15 bytes)

/* Returns 0xA2B3: 1 when the 7-byte SDR reply has arrived in 0xA2AC */

undefined1 sdr_rx_ready(void)

{
  return DAT_0000a2b3;
}


// ===== sdr_rx_done_cb @ fffb1b15 (10 bytes)

/* Sets 0xA2B3=1 (SCI5 receive end) */

void sdr_rx_done_cb(void)

{
  DAT_0000a2b3 = 1;
  return;
}


// ===== sdr_rx_buf @ fffb1b1f (12 bytes)

/* Returns 0xA2AC, the 7-byte SDR reply buffer (MOV.L #0xA2AC,R1; decompile lost the return) */

void sdr_rx_buf(void)

{
  return;
}

