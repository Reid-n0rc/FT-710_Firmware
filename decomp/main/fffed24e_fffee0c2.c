// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffed24e @ fffed24e (91 bytes)

void FUN_fffed24e(char param_1)

{
  DAT_0001b3c3 = 1;
  FUN_fffb237a(0x22,0x32);
  if (param_1 == '\x01') {
    DAT_00020b3c = 2;
  }
  else if (param_1 == '\x02') {
    DAT_00020b3c = 3;
  }
  else {
    DAT_00020b3c = 1;
  }
  if (DAT_00020f0c != '\x01') {
    return;
  }
  FUN_fffed206(0);
  return;
}


// ===== FUN_fffed2a9 @ fffed2a9 (200 bytes)

void FUN_fffed2a9(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_00020b3d == '\0') {
    FUN_fffed206(0);
    return;
  }
  if ((DAT_00020b3c == '\0') || (iVar2 = FUN_fffed61e(), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb2da6(3);
    FUN_fffed206(0);
    return;
  }
  if (DAT_00020b3e == '\x01') {
    DAT_00020b3c = 2;
    FUN_fffb6fd2(1);
    FUN_fffb7011(1);
    return;
  }
  if (DAT_00020b3e != '\x02') {
    if (DAT_00020b3e != '\x03') {
      DAT_00020b3c = 0;
      return;
    }
    DAT_00020b3c = 1;
    iVar2 = FUN_fffb23f3(0x20);
    if (iVar2 != 0) {
      DAT_00020b3e = 0;
      return;
    }
    return;
  }
  DAT_00020b3c = 3;
  FUN_fffb6fd2(1);
  FUN_fffb7011(1);
  return;
}


// ===== FUN_fffed371 @ fffed371 (40 bytes)

void FUN_fffed371(void)

{
  DAT_0001b3be = 1;
  DAT_0001b3c1 = 0;
  DAT_00025d10 = 0x437f0000;
  DAT_0001b3c2 = 0;
  return;
}


// ===== FUN_fffed399 @ fffed399 (104 bytes)

void FUN_fffed399(void)

{
  bool bVar1;
  int iVar2;
  
  if ((DAT_00020b3c == '\0') || (iVar2 = FUN_fffed61e(), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb2da6(3);
    DAT_0001b3be = '\x05';
  }
  if (DAT_0001b3be == '\x05') {
    FUN_fffed5e4();
    return;
  }
  if (DAT_0001b3be == '\x02') {
    FUN_fffed48f();
    return;
  }
  if (DAT_0001b3be != '\x03') {
    if (DAT_0001b3be == '\x04') {
      FUN_fffed5c5();
      return;
    }
    if (DAT_0001b3be == '\x01') {
      FUN_fffed401();
      return;
    }
    return;
  }
  FUN_fffed50f();
  return;
}


// ===== FUN_fffed401 @ fffed401 (142 bytes)

void FUN_fffed401(void)

{
  int iVar1;
  
  DAT_00025d0c = DAT_00020f50;
  if (DAT_0001b3bf == '\0') {
    if (DAT_0001b3c0 == '\0') {
      DAT_00020b3c = 3;
    }
    else {
      DAT_00020b3c = 2;
    }
    FUN_fffb237a(0x20,&DAT_0000ea60);
  }
  else {
    iVar1 = FUN_fffb3371(DAT_00020f50);
    if (iVar1 == 9) {
      DAT_0001b3c0 = '\x01';
      DAT_00020b3c = 2;
      FUN_fffb237a(0x20,&DAT_00001388);
    }
    else {
      FUN_fffb237a(0x20,1);
    }
  }
  DAT_0001b3be = 2;
  return;
}


// ===== FUN_fffed48f @ fffed48f (128 bytes)

void FUN_fffed48f(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x20);
  if (iVar1 == 0) {
    return;
  }
  if (DAT_0001b3bf == '\0') {
    FUN_fffed5ea();
  }
  else if (DAT_00025d08 < DAT_00025d0c) {
    DAT_0001b3c0 = 1;
    DAT_00020b3c = 2;
  }
  else {
    DAT_0001b3c0 = 0;
    DAT_00020b3c = 3;
  }
  DAT_0001b3bf = 0;
  DAT_00020b2d = 1;
  FUN_fffb237a(0x20,&DAT_0000ea60);
  DAT_0001b3be = 3;
  return;
}


// ===== FUN_fffed50f @ fffed50f (182 bytes)

void FUN_fffed50f(void)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)SBORROW4((int)&stack0x00000000,4) << 3;
  fVar1 = (float)FUN_fffb6e4e();
  if (2.0 < fVar1 == (bool)((byte)(uVar3 >> 3) & 1)) {
    if (DAT_00025d10 < fVar1) {
      DAT_0001b3c2 = DAT_0001b3c2 + 1;
    }
    else {
      DAT_0001b3c2 = 0;
    }
  }
  else {
    DAT_0001b3c2 = 0;
  }
  DAT_00025d10 = fVar1;
  if (2 < DAT_0001b3c2) {
    DAT_00020b3c = 1;
    FUN_fffb237a(0x20,2000);
    DAT_0001b3be = 4;
    return;
  }
  iVar2 = FUN_fffb23f3(0x20);
  if (iVar2 == 0) {
    return;
  }
  if (DAT_0001b3c1 == '\0') {
    DAT_0001b3c1 = 1;
    FUN_fffed5ea();
    FUN_fffb237a(0x20,&DAT_0000ea60);
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5c5 @ fffed5c5 (31 bytes)

void FUN_fffed5c5(void)

{
  int iVar1;
  
  DAT_0001b3bf = 1;
  iVar1 = FUN_fffb23f3(0x20);
  if (iVar1 == 0) {
    return;
  }
  DAT_0001b3be = 5;
  return;
}


// ===== FUN_fffed5e4 @ fffed5e4 (6 bytes)

void FUN_fffed5e4(void)

{
  FUN_fffed206(0);
  return;
}


// ===== FUN_fffed5ea @ fffed5ea (52 bytes)

void FUN_fffed5ea(void)

{
  if (DAT_0001b3c0 != '\0') {
    DAT_0001b3c0 = 0;
    DAT_00020b3c = 3;
    return;
  }
  DAT_0001b3c0 = 1;
  DAT_00020b3c = 2;
  return;
}


// ===== FUN_fffed61e @ fffed61e (12 bytes)

undefined1 FUN_fffed61e(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fffb6f76();
  return uVar1;
}


// ===== FUN_fffed62a @ fffed62a (203 bytes)

void FUN_fffed62a(void)

{
  bool bVar1;
  int iVar2;
  
  DAT_00020b71 = 0;
  iVar2 = FUN_fffb1900();
  if (iVar2 == 0) {
    if (DAT_00020b3f == '\x05') {
      DAT_00020b71 = 1;
      if ((DAT_00020b40 == '\x02') && (iVar2 = FUN_fffb2406(0), iVar2 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b71 = 0;
      }
    }
    switch(DAT_0001b3c8) {
    case 1:
    case 4:
      FUN_fffed72b();
      return;
    case 2:
    case 5:
      FUN_fffed753();
      return;
    case 3:
      FUN_fffed796();
      return;
    case 6:
      FUN_fffed7f3();
      return;
    case 7:
      FUN_fffed8ab();
      return;
    case 8:
      FUN_fffed8fc();
      return;
    case 9:
      FUN_fffed934();
      return;
    case 10:
      FUN_fffed983();
      return;
    case 0xb:
      FUN_fffed9b3();
      return;
    case 0xc:
      FUN_fffeda3b();
      return;
    case 0xd:
      FUN_fffeda96();
      return;
    case 0xe:
      FUN_fffedab0();
      return;
    case 0xf:
      FUN_fffedac0();
      return;
    case 0x10:
      FUN_fffedae4();
      return;
    default:
      FUN_fffed704();
      return;
    }
  }
  return;
}


// ===== FUN_fffed6f5 @ fffed6f5 (15 bytes)

undefined1 FUN_fffed6f5(void)

{
  return DAT_0001b5aa;
}


// ===== FUN_fffed704 @ fffed704 (39 bytes)

void FUN_fffed704(void)

{
  DAT_0001b3c7 = 0;
  DAT_00020b40 = 0;
  DAT_00020b3f = 0;
  DAT_0001b3c8 = 1;
  return;
}


// ===== FUN_fffed72b @ fffed72b (40 bytes)

void FUN_fffed72b(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x24);
  if ((iVar1 != 0) && (FUN_fffedbc9(), DAT_0001b3c7 == '\0')) {
    DAT_0001b3c8 = DAT_0001b3c8 + '\x01';
    return;
  }
  return;
}


// ===== FUN_fffed753 @ fffed753 (67 bytes)

void FUN_fffed753(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(7);
  if (iVar1 == 1) {
    DAT_0001b5aa = 0;
    DAT_0001b3c8 = 0;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3cb != '\x01') {
    return;
  }
  DAT_0001b5aa = 1;
  DAT_0001b3c8 = DAT_0001b3c8 + '\x01';
  return;
}


// ===== FUN_fffed796 @ fffed796 (93 bytes)

void FUN_fffed796(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x25);
  if (iVar1 != 0) {
    if (DAT_0001b5ab == '\x01') {
      FUN_fffedb87();
    }
    else if (DAT_0001b5ab == '\0') {
      FUN_fffedba8();
    }
    else {
      FUN_fffedb54();
    }
    if (DAT_0001b3c7 == '\0') {
      if (DAT_0001b5ab == '\x02') {
        DAT_0001b5ab = 0;
        DAT_0001b3c8 = 4;
        return;
      }
      DAT_0001b5ab = DAT_0001b5ab + '\x01';
      return;
    }
  }
  return;
}


// ===== FUN_fffed7f3 @ fffed7f3 (184 bytes)

/* WARNING: Removing unreachable block (ram,0xfffed887) */
/* WARNING: Removing unreachable block (ram,0xfffed894) */

void FUN_fffed7f3(void)

{
  int iVar1;
  
  if (DAT_00020b40 == '\x01') {
    DAT_0001b3c8 = 7;
  }
  else if (DAT_00020b3f == '\x04') {
    FUN_fffedb42();
    if (DAT_0001b3c7 == '\0') {
      DAT_0001b3c8 = 0x10;
    }
  }
  else if (DAT_00020b3f == '\x06') {
    FUN_fffedb54();
    if (DAT_0001b3c7 == '\0') {
      DAT_0001b3c8 = 0x10;
    }
  }
  else {
    iVar1 = FUN_fffb23f3(0x24);
    if (iVar1 == 1) {
      DAT_0001b3c8 = 4;
    }
  }
  if ((DAT_00020b3f == '\x05') && (DAT_00025d18 / 10000 != (DAT_00020f50 / 10000 & 0xff))) {
    DAT_00020b3f = 4;
    return;
  }
  return;
}


// ===== FUN_fffed8ab @ fffed8ab (81 bytes)

void FUN_fffed8ab(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb37fe(DAT_00020f50);
  if (iVar1 == 0) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  DAT_00020b40 = 2;
  DAT_00020b2d = 1;
  FUN_fffedb54();
  if (DAT_0001b3c7 != '\0') {
    return;
  }
  DAT_0001b3c8 = 8;
  return;
}


// ===== FUN_fffed8fc @ fffed8fc (56 bytes)

void FUN_fffed8fc(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(7);
  if (iVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3ca != '\x01') {
    return;
  }
  FUN_fffb237a(0x26,0xfa);
  DAT_0001b3c8 = 9;
  return;
}


// ===== FUN_fffed934 @ fffed934 (79 bytes)

void FUN_fffed934(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x26);
  if (iVar1 != 0) {
    DAT_00025d14 = FUN_fffb6e5c();
    FUN_fffb6fd2(0);
    FUN_fffb7011(0);
    FUN_fffb237a(0x26,5);
    DAT_0001b3c8 = 10;
    return;
  }
  if (DAT_00020b6b != '\0') {
    return;
  }
  FUN_fffb237a(0x26,0xfa);
  return;
}


// ===== FUN_fffed983 @ fffed983 (48 bytes)

void FUN_fffed983(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x26);
  if ((iVar1 != 0) && (FUN_fffedb75(), DAT_0001b3c7 == '\0')) {
    FUN_fffb237a(0x26,&DAT_00002710);
    DAT_0001b3c8 = 0xb;
    return;
  }
  return;
}


// ===== FUN_fffed9b3 @ fffed9b3 (136 bytes)

void FUN_fffed9b3(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x26);
  if (iVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  if (DAT_00020b3f == '\x06') {
    DAT_0001b3c8 = 0xf;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3c9 == '\x01') {
    FUN_fffb6fd2(1);
    FUN_fffb7011(1);
    DAT_00020b3f = '\x05';
  }
  if (DAT_0001b3ca == '\x01') {
    FUN_fffb237a(0x26,0xfa);
    DAT_0001b3c8 = 0xc;
    return;
  }
  if (DAT_0001b3cb == '\x01') {
    DAT_0001b3c8 = 0xe;
    return;
  }
  return;
}


// ===== FUN_fffeda3b @ fffeda3b (91 bytes)

void FUN_fffeda3b(void)

{
  int iVar1;
  float fVar2;
  
  iVar1 = FUN_fffb23f3(0x26);
  if (iVar1 == 0) {
    if (DAT_00020b6b != '\0') {
      return;
    }
    FUN_fffb237a(0x26,0xfa);
    return;
  }
  fVar2 = (float)FUN_fffb6e5c();
  if (DAT_00025d14 <= fVar2) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  DAT_00020b2d = 0;
  DAT_0001b3c8 = 0xd;
  return;
}


// ===== FUN_fffeda96 @ fffeda96 (26 bytes)

void FUN_fffeda96(void)

{
  DAT_00020b40 = 0;
  DAT_0001b3c8 = 4;
  FUN_fffec537(1);
  return;
}


// ===== FUN_fffedab0 @ fffedab0 (16 bytes)

void FUN_fffedab0(void)

{
  FUN_fffb2da6(3);
  DAT_0001b3c8 = 0xf;
  return;
}


// ===== FUN_fffedac0 @ fffedac0 (36 bytes)

void FUN_fffedac0(void)

{
  FUN_fffedb54();
  if (DAT_0001b3c7 != '\0') {
    return;
  }
  DAT_00020b2d = 0;
  DAT_0001b3c8 = 0;
  return;
}


// ===== FUN_fffedae4 @ fffedae4 (94 bytes)

void FUN_fffedae4(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(7);
  if (iVar1 == 1) {
    DAT_0001b3c8 = 0xe;
    return;
  }
  FUN_fffedcb5();
  if (DAT_0001b3ca == '\x01') {
    if (DAT_00020b3f == '\x04') {
      DAT_00020b3f = '\x05';
    }
    else if (DAT_00020b3f == '\x06') {
      DAT_00020b3f = '\0';
    }
    DAT_0001b3c8 = 6;
    return;
  }
  return;
}


// ===== FUN_fffedb42 @ fffedb42 (18 bytes)

void FUN_fffedb42(void)

{
  DAT_0001b3c4 = 0xf0;
  FUN_fffedbea();
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb54 @ fffedb54 (33 bytes)

void FUN_fffedb54(void)

{
  DAT_0001b3c4 = 0xf1;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb75 @ fffedb75 (18 bytes)

void FUN_fffedb75(void)

{
  DAT_0001b3c4 = 0xf2;
  FUN_fffedbea();
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedb87 @ fffedb87 (33 bytes)

void FUN_fffedb87(void)

{
  DAT_0001b3c4 = 0xe0;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 1;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedba8 @ fffedba8 (33 bytes)

void FUN_fffedba8(void)

{
  DAT_0001b3c4 = 0xe0;
  DAT_0001b3c5 = 1;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedbc9 @ fffedbc9 (33 bytes)

void FUN_fffedbc9(void)

{
  DAT_0001b3c4 = 0xef;
  DAT_0001b3c5 = 0;
  DAT_0001b3c6 = 0;
  FUN_fffedc27(3);
  return;
}


// ===== FUN_fffedbea @ fffedbea (61 bytes)

void FUN_fffedbea(void)

{
  undefined2 extraout_var;
  undefined1 uStack_4;
  
  DAT_00025d18 = DAT_00020f50;
  FUN_fffb4135(DAT_00020f50);
  DAT_0001b3c5 = (char)((ushort)extraout_var >> 8);
  uStack_4 = (undefined1)extraout_var;
  DAT_0001b3c6 = uStack_4;
  return;
}


// ===== FUN_fffedc27 @ fffedc27 (142 bytes)

void FUN_fffedc27(undefined1 param_1)

{
  int iVar1;
  undefined1 local_2;
  undefined1 local_1;
  
  local_1 = param_1;
  if (DAT_0001b3c7 == '\0') {
    local_2 = 0xff;
    FUN_fffb195a(&local_2,1);
    DAT_0001b3c7 = 1;
    FUN_fffb237a(0x23,0x28);
    return;
  }
  iVar1 = FUN_fffb23f3(0x23);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffb195a(&DAT_0001b3c4,local_1);
  DAT_0001b3c7 = 0;
  DAT_0001b3c9 = 0;
  DAT_0001b3ca = 0;
  DAT_0001b3cb = 0;
  FUN_fffb237a(7,100);
  FUN_fffb237a(0x25,100);
  FUN_fffb237a(0x24,0x1cc);
  return;
}


// ===== FUN_fffedcb5 @ fffedcb5 (82 bytes)

void FUN_fffedcb5(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_fffb191e();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffb192d();
  pcVar3 = (char *)FUN_fffb194e();
  cVar1 = *pcVar3;
  if (cVar1 == -0x51) {
    FUN_fff94c75(pcVar3 + 1);
  }
  else {
    if (cVar1 == -0x5f) {
      DAT_0001b3ca = 1;
      return;
    }
    if (cVar1 == -0x60) {
      DAT_0001b3c9 = 1;
      return;
    }
  }
  DAT_0001b3cb = 1;
  return;
}


// ===== FUN_fffedd07 @ fffedd07 (102 bytes)

void FUN_fffedd07(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfb;
  DAT_0008778a = 0x18;
  bVar2 = DAT_0008738a;
  DAT_0008738a = bVar2 & 0xf2 | 2;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfb;
  DAT_00088130 = 0x29;
  bVar2 = DAT_00088134;
  DAT_00088134 = bVar2 | 0x41;
  DAT_00088132 = 0;
  DAT_00088138 = 0x4a;
  DAT_0008813a = 0x5db;
  FUN_fffedd8b();
  return;
}


// ===== FUN_fffedd6d @ fffedd6d (15 bytes)

void FUN_fffedd6d(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 | 4;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 4;
  return;
}


// ===== FUN_fffedd7c @ fffedd7c (15 bytes)

void FUN_fffedd7c(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 & 0xfb;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfb;
  return;
}


// ===== FUN_fffedd8b @ fffedd8b (1 bytes)

void FUN_fffedd8b(void)

{
  return;
}


// ===== vec138_isr @ fffedd8c (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfffedd94) */
/* WARNING: Removing unreachable block (ram,0xfffedd8c) */
/* WARNING: Removing unreachable block (ram,0xfffedd8e) */
/* WARNING: Removing unreachable block (ram,0xfffedd96) */

undefined4 vec138_isr(undefined4 param_1)

{
  FUN_fffb24d8();
  return param_1;
}


// ===== FUN_fffedd9a @ fffedd9a (47 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffedd9a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc6) */

undefined4 FUN_fffedd9a(undefined4 param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = *param_3;
  *(byte *)param_3 = (byte)*param_3 & 0x7f;
  FUN_fffeddc9(param_3);
  *param_3 = uVar1 & 0x80;
  uVar2 = FUN_fffedfa7(param_1,param_2,param_3,0xffffffff);
  return uVar2;
}


// ===== FUN_fffeddc9 @ fffeddc9 (84 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffede1a) */
/* WARNING: Removing unreachable block (ram,0xfffeddc9) */

undefined4 FUN_fffeddc9(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*param_1 & 3) == 0) || (*(char *)((int)param_1 + 3) < '\0')) {
    FUN_fffee0c2(param_1);
    uVar2 = 0xffffffff;
    DAT_00025d1c = 9;
  }
  else {
    uVar2 = FUN_fffedf24(param_1);
    if ((*param_1 & 0x40) != 0) {
      FUN_fffee10b(*(undefined4 *)(param_1 + 2));
    }
    param_1[2] = 0;
    param_1[3] = 0;
    iVar1 = FUN_fff8fac2((int)*(char *)((int)param_1 + 3));
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
    FUN_fffee0c2(param_1);
  }
  return uVar2;
}


// ===== FUN_fffede1d @ fffede1d (36 bytes)

int FUN_fffede1d(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 == 0) {
    return 0;
  }
  do {
    if ((param_3 & 0xff) <= uVar3) break;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 + 1;
    cVar2 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 == cVar2);
  return (uint)(byte)param_1[-1] - (uint)(byte)param_2[-1];
}


// ===== FUN_fffede41 @ fffede41 (153 bytes)

ushort * FUN_fffede41(ushort *param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_4 & 0xffff0000) == 0) {
    if (param_4 == 0) {
      if ((param_3 & 0xffff0000) == 0) {
        if (param_2 != 0) {
          puVar2 = (ushort *)(uint)*param_1;
          if ((param_3 & 0xff) != 0) {
            puVar2 = (ushort *)((uint)puVar2 / (param_3 & 0xff));
          }
          return puVar2;
        }
        if (param_1 != (ushort *)0x0) {
          if ((param_3 & 0xff) != 0) {
            param_1 = (ushort *)((uint)param_1 / (param_3 & 0xff));
          }
          return param_1;
        }
        return (ushort *)0x0;
      }
      iVar4 = 0x20;
      uVar3 = 0;
      param_4 = param_3;
    }
    else {
      param_4 = param_4 << 0x10 | param_3 >> 0x10 & 0xff;
      iVar4 = 0x10;
      uVar3 = param_3 << 0x10;
    }
  }
  else {
    iVar4 = 0;
    uVar3 = param_3;
  }
  uVar6 = 0;
  puVar2 = (ushort *)0x0;
  if ((param_4 & 0x80000000) == 0) {
    do {
      if (param_2 <= (param_4 & 0xff)) break;
      iVar4 = iVar4 + 1;
      uVar3 = uVar3 << 1;
      uVar7 = param_4 << 1;
      bVar1 = (int)param_4 < 0;
      param_4 = uVar7;
      if (bVar1) {
        param_4 = uVar7 | 1;
      }
    } while (-1 < (int)param_4);
  }
  do {
    bVar1 = param_1 < (ushort *)(uVar3 & 0xff);
    param_1 = (ushort *)((int)param_1 - (int)(uVar3 & 0xff));
    uVar7 = param_4 - bVar1;
    bVar1 = param_2 < uVar7;
    param_2 = param_2 - uVar7;
    if (bVar1) {
      bVar1 = CARRY4(uVar3,(uint)param_1);
      param_1 = (ushort *)((int)param_1 + uVar3);
      param_2 = param_2 + param_4 +
                (uint)(CARRY4(param_2,(uint)bVar1) || CARRY4(param_4,param_2 + bVar1));
    }
    puVar5 = (ushort *)((int)puVar2 << 1);
    if ((int)puVar2 < 0) {
      puVar5 = (ushort *)((uint)puVar5 | 1);
    }
    uVar7 = uVar6 << 1;
    if ((int)uVar6 < 0) {
      uVar7 = uVar7 | 1;
    }
    param_4 = param_4 >> 1;
    uVar6 = uVar3 & 1;
    uVar3 = uVar3 >> 1;
    if (uVar6 != 0) {
      uVar3 = uVar3 | 0x80000000;
    }
    iVar4 = iVar4 + -1;
    puVar2 = puVar5;
    uVar6 = uVar7;
  } while (-1 < iVar4);
  return puVar5;
}


// ===== _INITSCT @ fffededa (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfffededa) */
/* WARNING: Removing unreachable block (ram,0xfffedf21) */
/* CC-RX section init: BTBL 0xFFF8E6C4..DC zero-fill, DTBL 0xFFF8E6A0..C4 copy ROM->RAM */

undefined4 _INITSCT(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  ppuVar5 = &BTBL;
  while ((undefined **)((uint)ppuVar5 & 0xff) < RelocatableVectors) {
    puVar1 = (undefined4 *)*ppuVar5;
    ppuVar6 = ppuVar5 + 1;
    ppuVar5 = ppuVar5 + 2;
    if ((undefined *)((uint)puVar1 & 0xff) < *ppuVar6) {
      for (iVar4 = (int)*ppuVar6 - ((uint)puVar1 & 0xff); iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar1 = 0;
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
    }
  }
  ppuVar5 = &DTBL;
  while ((undefined **)((uint)ppuVar5 & 0xff) < &BTBL) {
    puVar3 = *ppuVar5;
    ppuVar6 = ppuVar5 + 1;
    puVar2 = ppuVar5[2];
    ppuVar5 = ppuVar5 + 3;
    if ((undefined *)((uint)puVar3 & 0xff) < *ppuVar6) {
      for (iVar4 = (int)*ppuVar6 - ((uint)puVar3 & 0xff); iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return param_1;
}


// ===== FUN_fffedf24 @ fffedf24 (131 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffedfa4) */
/* WARNING: Removing unreachable block (ram,0xfffedf24) */

undefined4 FUN_fffedf24(ushort *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (param_1 == (ushort *)0x0) {
    piVar4 = &DAT_0001ff74;
    uVar6 = 0;
    for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {
      if ((*piVar4 != 0) && (iVar5 = FUN_fffedf24(), iVar5 < 0)) {
        uVar6 = 0xffffffff;
      }
      piVar4 = piVar4 + 1;
    }
  }
  else {
    uVar6 = 0;
    if ((*param_1 & 0x2000) != 0) {
      iVar3 = *(int *)(param_1 + 2);
      for (iVar5 = 0; (uint)(iVar5 + iVar3) < (*(uint *)(param_1 + 6) & 0xff); iVar5 = iVar5 + iVar2
          ) {
        iVar2 = FUN_fff8facd((int)*(char *)((int)param_1 + 3));
        if (iVar2 < 1) {
          uVar6 = *(undefined4 *)(param_1 + 2);
          *(undefined4 *)(param_1 + 6) = uVar6;
          *(undefined4 *)(param_1 + 10) = uVar6;
          *(undefined4 *)(param_1 + 0x16) = uVar6;
          *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
          return 0xffffffff;
        }
      }
      uVar1 = *(undefined4 *)(param_1 + 2);
      uVar6 = 0;
      *(undefined4 *)(param_1 + 6) = uVar1;
      *(undefined4 *)(param_1 + 10) = uVar1;
      *(undefined4 *)(param_1 + 0x16) = uVar1;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) & 0xdf;
    }
  }
  return uVar6;
}


// ===== FUN_fffedfa7 @ fffedfa7 (214 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffee07a) */
/* WARNING: Removing unreachable block (ram,0xfffedfa7) */

undefined2 * FUN_fffedfa7(int param_1,char *param_2,undefined2 *param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  ushort uVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  int in_stack_0000000c;
  
  if (param_3 != (undefined2 *)0x0) {
    uVar3 = *(undefined1 *)(param_3 + 1);
    puVar7 = &DAT_fff8e644;
    uVar2 = *param_3;
    puVar5 = param_3;
    for (iVar8 = 0x48; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar5 = *puVar7;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      puVar7 = puVar7 + 1;
    }
    *(undefined1 *)(param_3 + 1) = uVar3;
    puVar5 = param_3 + 0x22;
    *(undefined2 **)(param_3 + 2) = puVar5;
    *(undefined2 **)(param_3 + 6) = puVar5;
    *(undefined2 **)(param_3 + 8) = puVar5;
    *(undefined2 **)(param_3 + 0x14) = puVar5;
    *(undefined2 **)(param_3 + 10) = puVar5;
    *(undefined2 **)(param_3 + 0x16) = puVar5;
    *(undefined2 **)(param_3 + 0xc) = puVar5;
    *(undefined2 **)(param_3 + 0xe) = param_3 + 0x12;
    cVar1 = *param_2;
    if (cVar1 == 'r') {
      uVar9 = 1;
    }
    else if (cVar1 == 'w') {
      uVar9 = 0x1a;
    }
    else {
      uVar9 = 0x16;
      if (cVar1 != 'a') {
        uVar9 = 0;
      }
    }
    puVar10 = (ushort *)(uVar9 | (byte)uVar2 & 0x80);
    *param_3 = (short)puVar10;
    if ((uVar9 & 3) == 0) {
      FUN_fffeddc9(param_3);
      DAT_00025d1c = 0x16;
    }
    else {
      while( true ) {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        if ((cVar1 != 'b') && (cVar1 != '+')) break;
        if (cVar1 == 'b') {
          if ((*puVar10 & 0x20) != 0) break;
          puVar10 = (ushort *)((uint)puVar10 | 0x20);
        }
        else {
          if ((*puVar10 & 3) == 3) break;
          puVar10 = (ushort *)((uint)puVar10 | 3);
        }
        *param_3 = (short)puVar10;
      }
      if (param_1 == 0) {
        if (-1 < param_4) {
          *(char *)((int)param_3 + 3) = (char)param_4;
          return param_3;
        }
      }
      else {
        uVar6 = *puVar10;
        if (in_stack_0000000c != 0) {
          uVar6 = uVar6 | 0x40;
        }
        if (in_stack_0000000c == 0x55) {
          puVar10[0] = 1;
          puVar10[1] = 0;
        }
        iVar8 = FUN_fffee18e(param_1,uVar6);
        *(char *)((int)param_3 + 3) = (char)iVar8;
        if (-1 < iVar8) {
          return param_3;
        }
      }
      uVar4 = DAT_00025d1c;
      FUN_fffeddc9(param_3);
      DAT_00025d1c = uVar4;
    }
  }
  return (undefined2 *)0x0;
}


// ===== FUN_fffee0c2 @ fffee0c2 (73 bytes)

void FUN_fffee0c2(ushort *param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((*param_1 & 0x80) == 0) {
    puVar1 = param_1 + 0x22;
    *(undefined1 *)((int)param_1 + 3) = 0xff;
    *(ushort **)(param_1 + 2) = puVar1;
    *(ushort **)(param_1 + 6) = puVar1;
    *(ushort **)(param_1 + 8) = puVar1;
    *(ushort **)(param_1 + 0x14) = puVar1;
    *(ushort **)(param_1 + 10) = puVar1;
    *(ushort **)(param_1 + 0x16) = puVar1;
    *(ushort **)(param_1 + 0xc) = puVar1;
    *param_1 = 0;
    *(ushort **)(param_1 + 0xe) = param_1 + 0x12;
    return;
  }
  uVar3 = 0;
  puVar2 = &DAT_0001ff74;
  do {
    if (0x13 < uVar3) {
LAB_fffee106:
      FUN_fffee10b();
      return;
    }
    if (param_1 == (ushort *)*puVar2) {
      *puVar2 = 0;
      goto LAB_fffee106;
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while( true );
}

