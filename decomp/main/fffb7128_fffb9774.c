// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb7128 @ fffb7128 (37 bytes)

void FUN_fffb7128(char param_1)

{
  byte bVar1;
  
  if (param_1 != '\0') {
    bVar1 = DAT_0008c005;
    DAT_0008c005 = bVar1 | 1;
    return;
  }
  bVar1 = DAT_0008c005;
  DAT_0008c005 = bVar1 & 0xfe;
  return;
}


// ===== FUN_fffb714d @ fffb714d (24 bytes)

void FUN_fffb714d(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  DAT_0008c021 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== FUN_fffb7165 @ fffb7165 (24 bytes)

void FUN_fffb7165(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  DAT_0008c021 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== FUN_fffb717d @ fffb717d (22 bytes)

void FUN_fffb717d(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== FUN_fffb7193 @ fffb7193 (24 bytes)

void FUN_fffb7193(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== FUN_fffb71ab @ fffb71ab (19 bytes)

byte FUN_fffb71ab(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  return bVar1 >> 3 & 1;
}


// ===== FUN_fffb71be @ fffb71be (19 bytes)

byte FUN_fffb71be(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb71d1 @ fffb71d1 (17 bytes)

byte FUN_fffb71d1(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c025;
  return bVar1 & 1;
}


// ===== FUN_fffb71e2 @ fffb71e2 (19 bytes)

byte FUN_fffb71e2(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c022;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb71f5 @ fffb71f5 (10 bytes)

void FUN_fffb71f5(void)

{
  DAT_0001204e = 1;
  return;
}


// ===== FUN_fffb71ff @ fffb71ff (27 bytes)

void FUN_fffb71ff(char param_1)

{
  byte bVar1;
  
  if (param_1 != '\0') {
    bVar1 = DAT_0008c022;
    DAT_0008c022 = bVar1 & 0xfb;
    return;
  }
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 | 4;
  return;
}


// ===== FUN_fffb721a @ fffb721a (17 bytes)

byte FUN_fffb721a(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02b;
  return bVar1 >> 7;
}


// ===== FUN_fffb722b @ fffb722b (24 bytes)

bool FUN_fffb722b(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02b;
  return (bVar1 & 8) != 0;
}


// ===== FUN_fffb7243 @ fffb7243 (199 bytes)

void FUN_fffb7243(char param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char local_1;
  
  iVar3 = FUN_fffb4219();
  if ((iVar3 - 4U < 2) || (local_1 = param_1, iVar3 == 0xb || iVar3 == 0xc)) {
    local_1 = '\0';
  }
  iVar3 = FUN_fffb23f3(0x2a);
  if (iVar3 == 0) {
    bVar1 = DAT_0008c02b;
    if ((bVar1 & 8) == 0) {
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 | 8;
    }
    if (DAT_0001204f == '\0') {
      if ((DAT_00020b18 == '\b') || (DAT_00020b18 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (local_1 == '\0') {
          DAT_00020b44 = 0;
          return;
        }
        DAT_00020b44 = 1;
        return;
      }
    }
  }
  else if (local_1 == '\0') {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xf7;
    if (DAT_00020b18 == '\b') {
      DAT_00020b44 = 0;
      return;
    }
  }
  else {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 | 8;
    if (DAT_00020b18 == '\b') {
      DAT_00020b44 = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffb730a @ fffb730a (24 bytes)

bool FUN_fffb730a(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c04f;
  return (bVar1 & 0x20) == 0;
}


// ===== FUN_fffb7322 @ fffb7322 (132 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7384) */
/* WARNING: Removing unreachable block (ram,0xfffb739a) */

void FUN_fffb7322(byte param_1)

{
  byte bVar1;
  
  if (DAT_00020fcc == 3) {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc == 1) {
    bVar1 = DAT_0008c028;
    DAT_0008c028 = bVar1 & 0xfe | param_1 & 1;
    return;
  }
  if (DAT_00020fcc == 2) {
    bVar1 = DAT_0008c027;
    DAT_0008c027 = bVar1 & 0xfe | param_1 & 1;
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc != 0) {
    return;
  }
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== power_off_io @ fffb73a6 (55 bytes)

/* Power-down: clears several port bits, stops SCI5 [inference] */

void power_off_io(void)

{
  byte bVar1;
  
  FUN_fffb70c9(0);
  FUN_fffb7067(0);
  FUN_fffb70df(0);
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xef;
  R_SCI5_Stop();
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xf7;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0x7f;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xdf;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0x7f;
  return;
}


// ===== FUN_fffb73dd @ fffb73dd (65 bytes)

void FUN_fffb73dd(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(9);
  if (iVar1 == 1) {
    FUN_fffb237a(9,5);
    FUN_fffb741e();
    FUN_fffb7545();
  }
  iVar1 = FUN_fffb23f3(10);
  if (iVar1 == 1) {
    FUN_fffb237a(10,10);
    FUN_fffb747c();
    FUN_fffb74b8();
    FUN_fffb74ff();
    FUN_fffb7772();
    FUN_fffb7869();
    FUN_fffb7959();
    FUN_fffb7a40();
    return;
  }
  return;
}


// ===== FUN_fffb741e @ fffb741e (13 bytes)

void FUN_fffb741e(void)

{
  int iVar1;
  
  FUN_fffb27e0();
  do {
    iVar1 = FUN_fffb289e();
  } while (iVar1 != 1);
  return;
}


// ===== FUN_fffb742b @ fffb742b (81 bytes)

void FUN_fffb742b(void)

{
  DAT_00020fc0 = ((float)DAT_00004659 / 192.0) * (0.07176471 / (13.8 / (float)DAT_00004667));
  return;
}


// ===== FUN_fffb747c @ fffb747c (60 bytes)

void FUN_fffb747c(void)

{
  ushort uVar1;
  float fVar2;
  undefined1 uStack_4;
  
  uVar1 = DAT_00020b08 >> 4;
  FUN_fffb742b();
  fVar2 = ROUND((float)(byte)uVar1 * DAT_00020fc0);
  uStack_4 = SUB41(fVar2,0);
  if (0xff < ((uint)fVar2 & 0xffff)) {
    uStack_4 = 0xff;
  }
  DAT_00012043 = FUN_fffb92e7(uStack_4);
  return;
}


// ===== FUN_fffb74b8 @ fffb74b8 (71 bytes)

void FUN_fffb74b8(void)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(DAT_00020b0e >> 4) * in_stack_0000000c;
  if (DAT_0000475d != 0) {
    uVar1 = uVar1 / DAT_0000475d;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < (uVar1 & 0xffff)) {
    local_6 = 0xff;
  }
  DAT_00012044 = FUN_fffb9350(local_6);
  return;
}


// ===== FUN_fffb74ff @ fffb74ff (70 bytes)

void FUN_fffb74ff(void)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(DAT_00020b0c >> 4) * in_stack_0000000c;
  if (DAT_0000474e != 0) {
    uVar1 = uVar1 / DAT_0000474e;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < (uVar1 & 0xffff)) {
    local_6 = 0xff;
  }
  DAT_00012045 = FUN_fffb93b9(local_6);
  return;
}


// ===== FUN_fffb7545 @ fffb7545 (557 bytes)

void FUN_fffb7545(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined1 uStack_22;
  float fStack_20;
  float fStack_1c;
  float local_18;
  
  uVar7 = (uint)DAT_00020b04;
  uVar2 = (uint)DAT_00020b06;
  uVar3 = (uint)DAT_00004669;
  fStack_20 = (float)DAT_0000466a;
  uVar4 = (uint)DAT_0000466b;
  fVar5 = (float)uVar7 / (float)uVar2;
  local_18 = (fVar5 + 1.0) / (1.0 - fVar5);
  if (DAT_00020b6b != '\0') {
    if ((local_18 - 1.0 < 0.0) || (0.0 <= local_18 - 5.0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_0001b4c7 < 9) {
        bVar1 = SCARRY4((uint)DAT_0001b4c7,1);
        DAT_0001b4c7 = DAT_0001b4c7 + 1;
      }
      else {
        iVar6 = FUN_fffb2406(1);
        bVar1 = false;
        if (iVar6 == 0) {
          DAT_00020b6d = 1;
        }
        else {
          DAT_00020b6d = 2;
        }
      }
      DAT_0001b4c6 = 0;
    }
    else {
      bVar1 = SBORROW4((uint)DAT_0001b4c6,8);
      if (DAT_0001b4c6 < 9) {
        bVar1 = SCARRY4((uint)DAT_0001b4c6,1);
        DAT_0001b4c6 = DAT_0001b4c6 + 1;
      }
      else {
        DAT_00020b6d = 0;
      }
      DAT_0001b4c7 = 0;
    }
    if ((10.0 < (float)uVar7 == bVar1) && (10.0 < (float)uVar2 == bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (local_18 - 1.0 < 0.0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    uVar7 = 0;
    if (bVar1) {
      DAT_00020b6d = 0;
      uVar7 = (uint)SBORROW4((uint)DAT_00020b41,2) << 3;
      if (DAT_00020b41 == 2) {
        local_18 = 255.0;
      }
      else {
        local_18 = 1.0;
      }
    }
    DAT_00020fc4 = local_18;
    FUN_fffb948b(local_18);
    if (1.5 < local_18 == (bool)((byte)(uVar7 >> 3) & 1)) {
      fStack_1c = (float)uVar3 / 1.5;
      fStack_20 = -fStack_1c;
    }
    else {
      if ((local_18 <= 1.5) || (2.0 < local_18 != (bool)((byte)(uVar7 >> 3) & 1))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        fStack_1c = (fStack_20 - (float)uVar3) / 0.5;
        fStack_20 = fStack_1c * -2.0 + fStack_20;
      }
      else {
        fStack_1c = ((float)uVar4 - fStack_20) / 1.0;
        fStack_20 = fStack_1c * -3.0 + (float)uVar4;
      }
    }
    fVar5 = ROUND(fStack_1c * local_18 + fStack_20);
    uStack_22 = SUB41(fVar5,0);
    if (0xff < ((uint)fVar5 & 0xffff)) {
      uStack_22 = 0xff;
    }
    DAT_00012047 = uStack_22;
    DAT_00012046 = FUN_fffb9422(uStack_22);
    return;
  }
  DAT_00020b6d = 0;
  return;
}


// ===== FUN_fffb7772 @ fffb7772 (247 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7794) */

void FUN_fffb7772(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  byte bStack_2d;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  fVar2 = (float)DAT_00020b06;
  fVar3 = (float)((DAT_00020b1e & 0xf) << 4);
  cVar1 = FUN_fffb3371(DAT_00020f50);
  if (cVar1 == '\n') {
    fStack_28 = 50.0;
  }
  else {
    fStack_28 = 100.0;
  }
  fVar2 = fVar2 * (((fStack_28 - fVar3 * 0.00694025) - 0.0) / (fVar3 * fVar3)) * fVar2 +
          fVar2 * 0.00694025 + 0.0;
  bStack_2d = 0;
  do {
    if (7 < bStack_2d) {
LAB_fffb7837:
      fStack_1c = fStack_20 * fVar2 + fStack_24;
      if (255.0 < fStack_1c) {
        fStack_1c = 255.0;
      }
      DAT_00012048 = FUN_fffb94f9(*(undefined1 *)ROUND(fStack_1c));
      return;
    }
    iVar4 = (uint)bStack_2d * 0xc;
    if (fVar2 < *(float *)(&DAT_fff88c74 + iVar4) == SCARRY4(iVar4,-0x7738c)) {
      fStack_20 = *(float *)(&DAT_fff88c78 + (uint)bStack_2d * 0xc);
      fStack_24 = *(float *)(&DAT_fff88c7c + (uint)bStack_2d * 0xc);
      goto LAB_fffb7837;
    }
    bStack_2d = bStack_2d + 1;
  } while( true );
}


// ===== FUN_fffb7869 @ fffb7869 (240 bytes)

void FUN_fffb7869(void)

{
  uint uVar1;
  byte *pbVar2;
  float fVar3;
  uint uVar4;
  undefined1 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar4 = 0;
  if (DAT_00009bf1 == '\0') {
    uVar1 = FUN_fff9d857();
    uVar4 = uVar4 & 0xfffffff8;
    uVar1 = uVar1 >> 8 & 0xff;
  }
  else {
    pbVar2 = (byte *)FUN_fff9d857();
    uVar1 = (uint)*pbVar2;
  }
  uStack_10 = (float)uVar1;
  if (10.0 < uStack_10 == (bool)((byte)(uVar4 >> 3) & 1)) {
    uStack_14 = 10.3;
    uStack_18 = 0.0;
  }
  else if (20.0 < uStack_10 == (bool)((byte)(uVar4 >> 3) & 1)) {
    uStack_14 = 8.7;
    uStack_18 = 16.0;
  }
  else {
    uStack_14 = 5.8;
    if (30.0 < uStack_10 == (bool)((byte)(uVar4 >> 3) & 1)) {
      uStack_18 = 74.0;
    }
    else {
      uStack_18 = 75.2;
    }
  }
  fVar3 = ROUND((uStack_14 * uStack_10) / 2.0 + uStack_18);
  uStack_1a = SUB41(fVar3,0);
  if (0xff < ((uint)fVar3 & 0xffff)) {
    uStack_1a = 0xff;
  }
  DAT_00012049 = uStack_1a;
  return;
}


// ===== FUN_fffb7959 @ fffb7959 (231 bytes)

void FUN_fffb7959(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte bStack_1a;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  
  uVar1 = (uint)DAT_00004681;
  bVar2 = FUN_fff9d866();
  iVar3 = FUN_fffb23f3(0x2a);
  if (iVar3 == 0) {
    return;
  }
  fStack_c = 1.95;
  fStack_10 = 177.0;
  bStack_1a = 0;
  do {
    if (9 < bStack_1a) {
LAB_fffb79e0:
      fStack_18 = ((float)uVar1 - (float)bVar2) * fStack_c + fStack_10;
      if (fStack_18 - 0.0 < 0.0) {
        fStack_18 = 0.0;
      }
      else if (255.0 < fStack_18) {
        fStack_18 = 255.0;
      }
      if (DAT_00020b3d != '\0') {
        DAT_0001204a = 0;
        return;
      }
      DAT_0001204a = FUN_fffb959c(*(undefined1 *)ROUND(fStack_18));
      return;
    }
    iVar3 = (uint)bStack_1a * 0xc;
    if (*(float *)(&DAT_fff88c04 + iVar3) < (float)uVar1 - (float)bVar2 == SCARRY4(iVar3,-0x77404))
    {
      fStack_c = *(float *)(&DAT_fff88bfc + (uint)bStack_1a * 0xc);
      fStack_10 = *(float *)(&DAT_fff88c00 + (uint)bStack_1a * 0xc);
      goto LAB_fffb79e0;
    }
    bStack_1a = bStack_1a + 1;
  } while( true );
}


// ===== FUN_fffb7a40 @ fffb7a40 (259 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7a58) */
/* WARNING: Removing unreachable block (ram,0xfffb7a67) */

void FUN_fffb7a40(void)

{
  bool bVar1;
  byte bVar2;
  byte local_3;
  
  bVar2 = (byte)(DAT_00020b10 >> 4);
  local_3 = 0;
  do {
    if (0xb < local_3) {
LAB_fffb7abb:
      if (0xb < local_3) {
        DAT_0001b4c8 = 0;
        DAT_0001b4c9 = 0;
        DAT_0001204c = 0;
        return;
      }
      if (DAT_0001b4c8 == 2) {
        cat_apo_reset();
        if (DAT_00020b86 == '\0') {
          DAT_0001204c = DAT_0001b4c9;
        }
      }
      else if (DAT_0001b4c8 == 100) {
        DAT_0001204c = DAT_0001204c | 0xf0;
      }
      if (100 < DAT_0001b4c8) {
        return;
      }
      DAT_0001b4c8 = DAT_0001b4c8 + 1;
      return;
    }
    if (((byte)(&DAT_fff815ab)[(uint)local_3 * 2] < bVar2) &&
       (bVar2 < (byte)(&DAT_fff815ac)[(uint)local_3 * 2])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_0001b4c9 != (byte)(local_3 + 1)) {
        DAT_0001b4c9 = local_3 + 1;
      }
      goto LAB_fffb7abb;
    }
    local_3 = local_3 + 1;
  } while( true );
}


// ===== FUN_fffb7b43 @ fffb7b43 (34 bytes)

void FUN_fffb7b43(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x13);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffb7f6f();
  FUN_fffb80f9();
  FUN_fffb8a02();
  FUN_fffb8a8c();
  FUN_fffb7b65();
  FUN_fffb8f7d();
  FUN_fffb915e();
  return;
}


// ===== FUN_fffb7b65 @ fffb7b65 (391 bytes)

void FUN_fffb7b65(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = FUN_fffb324c(DAT_00020b6b);
  cVar3 = DAT_00009ab6;
  bVar1 = *(byte *)(iVar4 + 3);
  iVar4 = FUN_fffb23f3(0x2a);
  if (iVar4 != 0) {
    if (DAT_00020b18 == '\b') {
      if (DAT_0001b4ca != cVar3) {
        DAT_0001b4ca = cVar3;
        iVar4 = FUN_fffb722b();
        if (iVar4 != 0) {
          FUN_fffb7243(0);
        }
        DAT_00020b48 = 0;
        FUN_fffb237a(0x2a,0x32);
        DAT_0001204f = 1;
        FUN_fffb7243(1);
        DAT_0001204f = 0;
        return;
      }
      iVar4 = FUN_fffb4219();
      if (((iVar4 - 4U < 2) || (iVar4 == 0xb || iVar4 == 0xc)) &&
         (iVar4 = FUN_fffb722b(), iVar4 != 0)) {
        FUN_fffb7243(0);
      }
      if ((char)((bVar1 & 0x38) >> 3) == '\x02') {
        iVar4 = FUN_fffb3196(0);
        if ((iVar4 - 6U < 2) || (iVar4 == 10 || iVar4 == 0xb)) {
          iVar4 = FUN_fff9d838();
          if (iVar4 == 0) {
            DAT_00020b48 = '\0';
            iVar4 = FUN_fffb722b();
            if (iVar4 == 0) {
              FUN_fffb7243(1);
            }
          }
          else {
            DAT_00020b48 = '\x01';
            iVar4 = FUN_fffb722b();
            if (iVar4 != 0) {
              FUN_fffb7243(0);
            }
          }
        }
        else {
          iVar4 = FUN_fffb722b();
          if (iVar4 != 0) {
            FUN_fffb7243(0);
          }
        }
      }
      else {
        if (cVar3 == '\0') {
          bVar1 = DAT_0008c022;
          DAT_0008c022 = bVar1 & 0xef;
          iVar4 = FUN_fffb722b();
          if (iVar4 == 0) {
            return;
          }
          FUN_fffb7243(0);
          DAT_00020b48 = 0;
          return;
        }
        FUN_fffb7cec();
        if (cVar3 == '\x01') {
          FUN_fffb7e61();
        }
      }
      if (DAT_00020b48 != '\x01') {
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 0x10;
        return;
      }
      bVar1 = DAT_0008c022;
      DAT_0008c022 = bVar1 & 0xef;
      return;
    }
    bVar1 = DAT_0008c022;
    DAT_0008c022 = bVar1 | 0x10;
    iVar4 = FUN_fffb722b();
    if ((iVar4 == 0) || (DAT_00020b18 != '\x03')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      FUN_fffb7243(0);
      return;
    }
  }
  return;
}


// ===== FUN_fffb7cec @ fffb7cec (373 bytes)

void FUN_fffb7cec(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_8;
  
  bVar2 = FUN_fffb3196(0);
  bVar3 = DAT_00004687;
  if ((((bVar2 == 0xb) || (bVar2 == 7)) || (bVar3 = DAT_00004686, bVar2 == 10)) || (bVar2 == 6)) {
    fStack_8 = (float)bVar3;
    fStack_18 = (float)DAT_00004688;
    if (DAT_00020ba7 < 0x19) {
      fStack_18 = 256.0;
      fStack_1c = 0.0;
    }
    else if (DAT_00020ba7 < 0x32) {
      fStack_18 = fStack_8;
      fStack_1c = 30.0;
    }
    else if (DAT_00020ba7 < 0xfa) {
      fStack_18 = (float)DAT_00020ba7 * ((fStack_8 - fStack_18) / -200.0) +
                  (fStack_8 * 5.0 - fStack_18) / 4.0;
      if (DAT_00020ba7 < 100) {
        fStack_1c = 15.0;
      }
      else if (DAT_00020ba7 < 0x96) {
        fStack_1c = 22.0;
      }
      else if (DAT_00020ba7 < 200) {
        fStack_1c = 25.0;
      }
      else {
        fStack_1c = 30.0;
      }
    }
    else {
      fStack_1c = 25.0;
    }
    DAT_0001b4cb = bVar2;
    bVar3 = FUN_fff9d800();
    if ((float)bVar3 < fStack_18) {
      DAT_00020b48 = 1;
      iVar4 = FUN_fffb722b();
      if (iVar4 != 0) {
        FUN_fffb7243(0);
        return;
      }
    }
    else if (fStack_18 + fStack_1c < (float)bVar3) {
      DAT_00020b48 = 0;
      iVar4 = FUN_fffb722b();
      if (iVar4 == 0) {
        FUN_fffb7243(1);
        return;
      }
    }
  }
  else {
    uVar1 = (uint)DAT_0001b4cb;
    if (((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) &&
       (DAT_0001b4cb = bVar2, iVar4 = FUN_fffb722b(), iVar4 != 0)) {
      FUN_fffb7243(0);
      return;
    }
  }
  return;
}


// ===== FUN_fffb7e61 @ fffb7e61 (270 bytes)

void FUN_fffb7e61(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  float fStack_24;
  float fStack_20;
  
  uVar1 = (uint)DAT_00004681;
  uVar3 = FUN_fffb3196(0);
  if (((uVar3 < 6) || (uVar3 - 8 < 2)) || (uVar3 - 0xc < 3)) {
    fVar4 = (float)uVar1 + 110.0;
    fStack_20 = (float)uVar1 + 80.0;
    if (DAT_00020ba7 < 0x19) {
      fStack_20 = 256.0;
      fStack_24 = 0.0;
    }
    else if (DAT_00020ba7 < 0xf0) {
      fStack_20 = (float)DAT_00020ba7 * ((fStack_20 - fVar4) / 216.0) +
                  (fVar4 * 240.0 - fStack_20 * 24.0) / 216.0;
      fStack_24 = 6.0;
    }
    else {
      fStack_24 = 6.0;
    }
    bVar2 = FUN_fff9d866();
    if ((float)bVar2 < fStack_20) {
      DAT_00020b48 = 1;
      iVar5 = FUN_fffb722b();
      if (iVar5 != 0) {
        FUN_fffb7243(0);
        return;
      }
    }
    else if (fStack_20 + fStack_24 < (float)bVar2) {
      DAT_00020b48 = 0;
      iVar5 = FUN_fffb722b();
      if (iVar5 == 0) {
        FUN_fffb7243(1);
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffb7f6f @ fffb7f6f (394 bytes)

void FUN_fffb7f6f(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  byte bStack_5;
  byte bStack_4;
  char cStack_2;
  
  bVar3 = FUN_fffb3196(1);
  cStack_2 = FUN_fffb50d7(bVar3);
  cVar4 = FUN_fffba192();
  DAT_00020b24 = 0;
  DAT_00020b26 = 0;
  DAT_00020b27 = 0;
  DAT_00020b29 = 0;
  bVar1 = DAT_0008c041;
  DAT_00020b25 = (bVar1 & 0x20) == 0;
  if (cVar4 == '\0') {
    bStack_5 = 1;
  }
  else {
    bStack_5 = 2;
  }
  for (bStack_4 = 0; bStack_4 < bStack_5; bStack_4 = bStack_4 + 1) {
    if (cVar4 == '\x01') {
      if ((bStack_4 == 1) && (cStack_2 == '\0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        cStack_2 = DAT_00009a9f;
      }
    }
    else if (bStack_4 == 1) {
      cStack_2 = DAT_00009a9f;
    }
    if ((cStack_2 == '\x03') && (bVar1 = DAT_0008c042, (bVar1 & 1) == 0)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_00020b24 = 1;
joined_r0xfffb8040:
      if (cVar4 == '\x01') break;
    }
    else {
      bVar1 = DAT_0008c047;
      if ((bVar1 >> 5 & 1) == 1) {
        if ((cStack_2 == '\x01') && (bVar1 = DAT_0008c04c, (bVar1 & 0x40) == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_00020b26 = 1;
        }
        else {
          if ((cStack_2 == '\x02') && (bVar1 = DAT_0008c04c, (bVar1 & 0x20) == 0)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_fffb80ab;
          DAT_00020b27 = 1;
        }
        goto joined_r0xfffb8040;
      }
    }
LAB_fffb80ab:
  }
  if ((((1 < bVar3 - 2) && (1 < bVar3 - 0xc)) && (DAT_00009c5d != '\0')) &&
     ((uVar5 = FUN_fff9d7f0(), (uVar5 & 0x10) != 0 && (iVar6 = FUN_fffb23f3(0x2f), iVar6 == 1)))) {
    DAT_00020b29 = 1;
    return;
  }
  return;
}


// ===== FUN_fffb80f9 @ fffb80f9 (1193 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb812b) */

void FUN_fffb80f9(void)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  undefined1 uStack_9;
  
  uVar3 = DAT_00020f50;
  uStack_9 = FUN_fffb548a();
  cVar1 = DAT_00009aa1;
  cVar4 = FUN_fffba192();
  bVar5 = cVar1 * '\x02' + 4;
  FUN_fffb86e8();
  iVar6 = FUN_fffb521a();
  if (iVar6 == 1) {
    if (DAT_0001204d == '\a') {
      uStack_9 = 0;
    }
    else if ((DAT_0001204d == '\b' || DAT_0001204d == '\t') && (iVar6 = FUN_fffb6ed4(), iVar6 != 0))
    {
      if ((cVar4 == '\0') || (cVar4 == '\x02')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        uStack_9 = 0;
      }
    }
  }
  if (DAT_00020b18 == '\0') {
    iVar6 = FUN_fffb37fe(uVar3);
    if (iVar6 != 0) {
      DAT_00020b18 = '\x01';
      FUN_fffb237a(0xc,1);
      FUN_fffb237a(0xd,1);
      FUN_fffb237a(0xe,5);
      FUN_fffb237a(0xf,1);
      FUN_fffb237a(0x10,3);
      FUN_fffb237a(0x11,uStack_9);
    }
    DAT_00020b19 = '\0';
    DAT_00020b1a = '\0';
  }
  else if (DAT_00020b18 == '\x01') {
    bVar5 = DAT_0008c022;
    if (((bVar5 & 0x10) == 0) && (iVar6 = FUN_fffb23f3(0xc), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c022;
      DAT_0008c022 = bVar5 | 0x10;
    }
    iVar6 = FUN_fffb722b();
    if ((iVar6 == 0) && (iVar6 = FUN_fffb23f3(0xd), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffb7243(1);
    }
    iVar6 = FUN_fffb23f3(0xe);
    if (iVar6 == 1) {
      if ((cVar4 == '\x01') || (cVar4 == '\x03')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        bVar5 = DAT_0008c027;
        DAT_0008c027 = bVar5 & 0xfe;
        bVar5 = DAT_0008c02b;
        DAT_0008c02b = bVar5 & 0xfb;
        bVar5 = DAT_0008c028;
        DAT_0008c028 = bVar5 & 0xfe;
      }
      if ((DAT_00020b19 == '\x01') && (DAT_00020b1a == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (DAT_00020fcc != 4) {
          iVar6 = FUN_fffb730a();
          if (iVar6 != 1) {
            bVar5 = DAT_0008c027;
            DAT_0008c027 = bVar5 | 1;
            bVar5 = DAT_0008c02b;
            DAT_0008c02b = bVar5 | 4;
          }
          bVar5 = DAT_0008c028;
          DAT_0008c028 = bVar5 | 1;
        }
        iVar6 = FUN_fffb722b();
        if (iVar6 != 0) {
          FUN_fffb7243(0);
        }
        DAT_00020b18 = '\x02';
      }
    }
    cVar1 = DAT_0008c02b;
    if ((cVar1 < '\0') && (iVar6 = FUN_fffb23f3(0xf), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02b;
      DAT_0008c02b = bVar5 & 0x7f;
    }
    iVar6 = FUN_fffb23f3(0x10);
    if (iVar6 == 1) {
      bVar5 = DAT_0008c027;
      DAT_0008c027 = bVar5 | 8;
    }
  }
  else if (DAT_00020b18 == '\x02') {
    iVar6 = FUN_fffb23f3(0x11);
    if (iVar6 == 1) {
      DAT_00012051 = 1;
      DAT_00020b18 = '\x03';
    }
  }
  else if (DAT_00020b18 == '\x03') {
    bVar5 = DAT_0008c041;
    if (DAT_00012051 != (bVar5 >> 4 & 1)) {
      bVar5 = DAT_0008c041;
      if ((bVar5 >> 4 & 1) == 1) {
        FUN_fffb6fd2(0);
        FUN_fffb7011(0);
      }
      else if (DAT_0001204d != '\a') {
        if (DAT_0001204d == '\b' || DAT_0001204d == '\t') {
          iVar6 = FUN_fffb6ed4();
          if (iVar6 == 0) {
            FUN_fffb6fd2(1);
            FUN_fffb7011(1);
          }
          else {
            if ((cVar4 == '\0') || (cVar4 == '\x02')) {
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
            if (bVar2) {
              FUN_fffb6fd2(1);
              FUN_fffb7011(1);
            }
          }
        }
        else {
          if ((DAT_00012050 == '\0') || (iVar6 = FUN_fffb521a(), iVar6 == 1)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            FUN_fffb6fd2(1);
            FUN_fffb7011(1);
          }
        }
      }
      bVar5 = DAT_0008c041;
      DAT_00012051 = bVar5 >> 4 & 1;
    }
  }
  else if (DAT_00020b18 == '\x04') {
    DAT_00020b18 = '\x05';
    DAT_00020b19 = '\0';
    DAT_00020b1a = '\0';
  }
  else if (DAT_00020b18 == '\x05') {
    FUN_fffb6fd2(0);
    FUN_fffb7011(0);
    DAT_00020b18 = '\x06';
    FUN_fffb237a(0x12,bVar5);
    FUN_fffb237a(0xc,*(undefined2 *)(bVar5 + 6));
    FUN_fffb237a(0xd,*(undefined2 *)((uint)DAT_00020b4a + (uint)bVar5));
    FUN_fffb237a(0xe,*(undefined2 *)(bVar5 + 5));
    FUN_fffb237a(0xf,*(undefined2 *)(bVar5 + 4));
    FUN_fffb237a(0x10,*(undefined2 *)(bVar5 + 3));
  }
  else if (DAT_00020b18 == '\x06') {
    iVar6 = FUN_fffb23f3(0x12);
    if ((iVar6 == 1) && (DAT_00020b49 == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      iVar6 = FUN_fffb722b();
      if (iVar6 == 0) {
        FUN_fffb7243(1);
      }
      DAT_00020b18 = '\a';
    }
  }
  else if (DAT_00020b18 == '\a') {
    bVar5 = DAT_0008c027;
    if (((bVar5 >> 3 & 1) == 1) && (iVar6 = FUN_fffb23f3(0x10), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c027;
      DAT_0008c027 = bVar5 & 0xf7;
    }
    cVar1 = DAT_0008c02b;
    if ((cVar1 < '\0') || (iVar6 = FUN_fffb23f3(0xf), iVar6 != 1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02b;
      DAT_0008c02b = bVar5 | 0x80;
    }
    bVar5 = DAT_0008c022;
    if (((bVar5 >> 4 & 1) == 1) && (iVar6 = FUN_fffb23f3(0xc), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c022;
      DAT_0008c022 = bVar5 & 0xef;
    }
    iVar6 = FUN_fffb23f3(0xe);
    if ((iVar6 == 1) && (DAT_00020fcc != 4)) {
      iVar6 = FUN_fffb730a();
      if (iVar6 != 1) {
        bVar5 = DAT_0008c027;
        DAT_0008c027 = bVar5 | 1;
        bVar5 = DAT_0008c02b;
        DAT_0008c02b = bVar5 | 4;
      }
      bVar5 = DAT_0008c028;
      DAT_0008c028 = bVar5 | 1;
    }
    iVar6 = FUN_fffb23f3(0xd);
    if (iVar6 == 1) {
      iVar6 = FUN_fffb722b();
      if ((iVar6 == 0) || (DAT_00020b44 != '\0')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        FUN_fffb237a(0x2a,0);
        FUN_fffb7243(0);
      }
      DAT_00020b18 = '\b';
    }
  }
  FUN_fffb9774();
  return;
}


// ===== FUN_fffb85a2 @ fffb85a2 (326 bytes)

byte FUN_fffb85a2(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  byte bStack_5;
  byte bStack_3;
  
  FUN_fffb3196(1);
  bStack_3 = 0;
  cVar3 = FUN_fffba192();
  if (DAT_00020b97 == '\0') {
    if (DAT_00020b28 == '\x01') {
      bStack_3 = 5;
    }
    else if (DAT_00020b25 == '\x01') {
      bStack_3 = 2;
    }
    else if (DAT_00020b24 == '\x01') {
      bStack_3 = 1;
    }
    else if (DAT_00020b26 == '\x01') {
      bStack_3 = 3;
    }
    else if (DAT_00020b27 == '\x01') {
      bStack_3 = 4;
    }
    else if (DAT_00020b2a == '\x01') {
      bStack_3 = 7;
    }
    else if (DAT_00020b2b == '\x01') {
      bStack_3 = 8;
    }
    else if (DAT_00020b2c == '\x01') {
      bStack_3 = 9;
    }
    else if (DAT_00020b2d == '\x01') {
      bStack_3 = 10;
    }
    else if (DAT_00020b2e == '\x01') {
      bStack_3 = 0xb;
    }
    else if (DAT_00020b29 == '\x01') {
      bStack_3 = 6;
    }
    if (bStack_3 != 0) {
      cat_apo_reset();
    }
    DAT_00012050 = 0;
    uVar1 = (uint)bStack_3;
    if (((uVar1 == 1) || (uVar1 - 3 < 2)) || (uVar1 == 8 || uVar1 == 9)) {
      if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        DAT_00012050 = 1;
      }
    }
    if ((bStack_3 != 0) && (bStack_3 != 6)) {
      FUN_fffb237a(0x2f,200);
    }
    bStack_5 = bStack_3;
  }
  else {
    bStack_5 = 0;
  }
  return bStack_5;
}


// ===== FUN_fffb86e8 @ fffb86e8 (794 bytes)

void FUN_fffb86e8(void)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  byte bStack_f;
  char cStack_c;
  
  uVar3 = DAT_00020f50;
  FUN_fffb3196(1);
  cVar4 = FUN_fffba192();
  bVar5 = FUN_fffb85a2();
  if (DAT_0001204d != bVar5) {
    DAT_0001b4cd = DAT_0001204d;
    DAT_0001204d = bVar5;
  }
  if (DAT_0001204d == 0) {
    cStack_c = '\0';
    DAT_00020b47 = 0;
  }
  else if (DAT_00020b7c != '\x02') {
    cStack_c = '\x01';
  }
  iVar7 = FUN_fffb37fe(uVar3);
  if (iVar7 == 0) {
    bVar5 = DAT_0008c02a;
    if ((bVar5 >> 1 & 1) != 1) {
      bVar5 = DAT_0008c02a;
      DAT_0008c02a = bVar5 | 2;
    }
    if (DAT_00020b6b != '\x01') {
      return;
    }
    DAT_0001b4cc = 0;
    DAT_0001b4ce = 0;
    DAT_00020b18 = 4;
    DAT_00020b6b = 0;
    return;
  }
  bVar5 = DAT_0008c041;
  if (((bVar5 >> 4 & 1) == 1) && (bVar5 = DAT_0008c02a, (bVar5 >> 1 & 1) != 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar5 = DAT_0008c02a;
    DAT_0008c02a = bVar5 | 2;
  }
  else {
    bVar5 = DAT_0008c041;
    if (((bVar5 >> 4 & 1) == 1) || (bVar5 = DAT_0008c02a, (bVar5 >> 1 & 1) != 1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02a;
      DAT_0008c02a = bVar5 & 0xfd;
    }
  }
  if (cStack_c == '\x01') {
    if (DAT_0001b4ce == '\0') {
      if ((byte)(DAT_0001b4cc + 1) < 2) {
        DAT_0001b4cc = DAT_0001b4cc + 1;
        return;
      }
      DAT_0001b4cc = 0;
      DAT_0001b4ce = 1;
      DAT_00020b18 = 0;
      DAT_00020b6b = 1;
      FUN_fffb268e();
      return;
    }
    DAT_0001b4cc = 0;
    iVar7 = FUN_fffb26bf();
    if (iVar7 != 1) {
      iVar7 = FUN_fffb26e5();
      if (iVar7 != 1) {
        return;
      }
      FUN_fffb2da6(7);
      return;
    }
    DAT_00020b47 = 1;
    return;
  }
  if (DAT_0001b4ce != '\x01') {
    DAT_0001b4cc = 0;
    return;
  }
  uVar1 = (uint)DAT_0001b4cd;
  if ((uVar1 != 1) && (1 < uVar1 - 3)) {
    if (uVar1 == 6) {
      if (DAT_0001b4cc == 0) {
        if (DAT_00009af3 == '\0') {
          bStack_f = DAT_00009bf4;
        }
        else {
          bStack_f = DAT_00009bf5;
        }
        FUN_fffb237a(0x15,*(undefined2 *)(&DAT_fff8833c + (uint)bStack_f * 2));
        DAT_0001b4cc = DAT_0001b4cc + 1;
      }
      else {
        iVar7 = FUN_fffb23f3(0x15);
        if (iVar7 == 1) {
          DAT_0001b4cc = DAT_0001b4cc + 1;
        }
      }
    }
    else {
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    goto LAB_fffb89c6;
  }
  if (DAT_00009aa0 == '\0') {
    if ((cVar4 == '\x01') || (cVar4 == '\x03')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (cVar4 == '\x04')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) goto LAB_fffb8963;
    bVar2 = true;
  }
  else {
LAB_fffb8963:
    bVar2 = false;
  }
  if (bVar2) {
    if (DAT_0001b4cc == 0) {
      uVar6 = FUN_fffba35c();
      FUN_fffb237a(0x1a,uVar6);
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    else {
      iVar7 = FUN_fffb23f3(0x1a);
      if (iVar7 == 1) {
        DAT_0001b4cc = DAT_0001b4cc + 1;
      }
    }
  }
  else {
    DAT_0001b4cc = DAT_0001b4cc + 1;
  }
LAB_fffb89c6:
  if (DAT_0001b4cc < 2) {
    return;
  }
  DAT_0001b4cc = 0;
  DAT_0001b4ce = 0;
  DAT_00020b18 = 4;
  DAT_00020b6b = 0;
  return;
}


// ===== FUN_fffb8a02 @ fffb8a02 (138 bytes)

void FUN_fffb8a02(void)

{
  uint uVar1;
  byte bVar2;
  char cStack_2;
  
  bVar2 = FUN_fffb3196(1);
  cStack_2 = FUN_fffb3d11(bVar2);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    cStack_2 = '\x03';
  }
  if (DAT_0001b4cf == cStack_2) {
    return;
  }
  DAT_0001b4cf = cStack_2;
  if (cStack_2 == '\x02') {
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 2;
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 & 0xfb;
    return;
  }
  if (cStack_2 != '\x01') {
    if (cStack_2 == '\0') {
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfd;
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfb;
      return;
    }
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 2;
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 4;
    return;
  }
  bVar2 = DAT_0008c028;
  DAT_0008c028 = bVar2 & 0xfd;
  bVar2 = DAT_0008c028;
  DAT_0008c028 = bVar2 | 4;
  return;
}


// ===== FUN_fffb8a8c @ fffb8a8c (747 bytes)

void FUN_fffb8a8c(void)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = (char *)FUN_fffb54a0();
  cVar1 = *pcVar4;
  if (DAT_00020b18 != '\a') {
    bVar2 = DAT_0008c040;
    if ((bVar2 >> 2 & 1) == 1) {
      iVar5 = FUN_fffb730a();
      if (iVar5 == 1) {
        DAT_00020fcc = 1;
      }
      else {
        DAT_00020fcc = 0;
      }
    }
    else {
      iVar5 = FUN_fffb730a();
      if (iVar5 == 1) {
        DAT_00020fcc = 1;
      }
      else if ((char)(cVar1 * '\x05') == '\0') {
        DAT_00020fcc = 3;
      }
      else {
        DAT_00020fcc = 2;
      }
    }
    if ((DAT_0001204e == '\x01') || (DAT_00020b3b == '\x01')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) || (DAT_00020b46 == '\x01')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      DAT_00020fcc = 4;
      DAT_0001204e = '\0';
    }
    iVar5 = FUN_fffb23f3(0x2c);
    if (iVar5 == 0) {
      DAT_00020fcc = 4;
    }
    if (DAT_00025d44 != DAT_00020fcc) {
      if (DAT_00025d44 == 4) {
        FUN_fffb237a(0x2d,5);
        FUN_fffedd6d();
      }
      DAT_00025d44 = DAT_00020fcc;
    }
    iVar5 = FUN_fffb23f3(0x2d);
    if (iVar5 != 0) {
      if (DAT_00020fcc == 0) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 | 1;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 & 0xfb;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0xff;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      if (DAT_00020fcc == 1) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 & 0xfb;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 | 1;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0xff;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      if (DAT_00020fcc == 2) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 | 1;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 | 4;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 | 0x40;
        DAT_00020b31 = FUN_fffb34f9(cVar1 * '\x05');
        DAT_00020b32 = 1;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3263;
        return;
      }
      if (DAT_00020fcc == 3) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 | 4;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      bVar2 = DAT_0008c027;
      DAT_0008c027 = bVar2 & 0xfe;
      bVar2 = DAT_0008c02b;
      DAT_0008c02b = bVar2 & 0xfb;
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfe;
      DAT_00020b31 = 0;
      DAT_00020b32 = 0;
      if (DAT_00020b6b == '\x01') {
        DAT_00020b34 = 0x2222;
        return;
      }
      DAT_00020b34 = 0x3233;
      return;
    }
  }
  return;
}


// ===== FUN_fffb8d77 @ fffb8d77 (518 bytes)

void FUN_fffb8d77(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  byte local_b;
  byte local_a;
  byte local_9;
  char cStack_7;
  byte bStack_6;
  byte local_5;
  
  uVar8 = DAT_00020f50;
  cVar7 = DAT_00009dbd;
  cVar6 = DAT_00009b1d;
  cVar5 = DAT_00009b1c;
  cVar4 = DAT_00009b1b;
  cVar3 = DAT_00009b1a;
  if (DAT_00020f3b != '\x01') {
    local_5 = 0;
    if (DAT_00020b48 == '\x01') {
      local_5 = 0x10;
    }
    iVar9 = FUN_fffb3196(1);
    if (((1 < iVar9 - 2U) && (1 < iVar9 - 0xcU)) && (DAT_00009c5d != '\0')) {
      local_5 = local_5 | 0x80;
    }
    DAT_00020b3d = 0;
    if (DAT_00020b6b == '\x01') {
      local_5 = local_5 & 0xef | 0x20;
      DAT_00020b3d = 1;
    }
    else {
      if ((DAT_0001204d == '\0') || (iVar9 = FUN_fffb37fe(uVar8), iVar9 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_5 = local_5 & 0xef;
        iVar9 = FUN_fffb2406(0);
        if (iVar9 != 0) {
          local_5 = local_5 | 0x20;
        }
        DAT_00020b3d = 2;
      }
    }
    if (cVar7 == '\0') {
      bStack_6 = DAT_00009dbe;
      cStack_7 = DAT_00020f29;
    }
    else {
      bStack_6 = DAT_00009dbf;
      cStack_7 = DAT_00020f2a;
    }
    if (cVar3 == '\x02') {
      local_9 = 1;
    }
    else if (cVar3 == '\x01') {
      local_9 = 2;
    }
    else if (cVar3 == '\0') {
      local_9 = 8;
    }
    else {
      local_9 = 0;
    }
    if (cVar4 == '\x02') {
      local_a = 1;
    }
    else if (cVar4 == '\x01') {
      local_a = 2;
    }
    else if (cVar4 == '\0') {
      local_a = 8;
    }
    else {
      local_a = 0;
    }
    if (cVar5 == '\x02') {
      local_b = 4;
    }
    else if (cVar5 == '\x01') {
      local_b = 2;
    }
    else if (cVar5 == '\0') {
      local_b = 8;
    }
    else {
      local_b = 0;
    }
    if (DAT_00009c5e == '\0') {
      if (cStack_7 == '\0') {
        uVar1 = (uint)bStack_6;
        if ((uVar1 - 7 < 2) || (uVar1 - 2 < 3)) {
          local_5 = local_5 | local_b;
        }
        else if ((uVar1 == 5) || (uVar1 == 1)) {
          if (cVar7 == '\0') {
            local_5 = local_5 | local_9;
          }
          else {
            local_5 = local_5 | local_a;
          }
        }
      }
      else {
        local_5 = local_5 | cVar6 == '\0';
      }
    }
    else {
      local_5 = local_5 | 1;
    }
    if (DAT_00020b74 != '\0') {
      local_5 = local_5 | 0x40;
    }
    if (DAT_00020b38 != local_5) {
      DAT_00020b38 = local_5;
      return;
    }
  }
  return;
}


// ===== FUN_fffb8f7d @ fffb8f7d (481 bytes)

void FUN_fffb8f7d(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_fffb1900();
  if (iVar3 == 1) {
    cVar2 = FUN_fffb33ab(DAT_00020f50);
    if (DAT_0001b4d0 != cVar2) {
      DAT_0001b4d0 = cVar2;
      switch(cVar2) {
      case '\0':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\x01':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\x02':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x03':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x04':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x05':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\x06':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\a':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\b':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 & 0xfb;
        return;
      case '\t':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\n':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xfb;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\v':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 & 0xf7;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 & 0xfe;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      case '\f':
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 8;
        bVar1 = DAT_0008c021;
        DAT_0008c021 = bVar1 | 4;
        bVar1 = DAT_0008c025;
        DAT_0008c025 = bVar1 | 1;
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 4;
        return;
      }
    }
    return;
  }
  DAT_0001b4d0 = 0xff;
  return;
}


// ===== FUN_fffb915e @ fffb915e (393 bytes)

void FUN_fffb915e(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  byte bStack_4;
  char cStack_3;
  
  if (DAT_00020b6b == '\0') {
    if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      FUN_fffb2df4();
      bVar1 = DAT_0008c02c;
      DAT_0008c02c = bVar1 | 0x10;
      return;
    }
  }
  else {
    cVar4 = FUN_fffb3196(1);
    cVar3 = DAT_00009a8e;
    if (DAT_00009dc6 == '\0') {
      cStack_3 = DAT_00009a8a;
    }
    else {
      cStack_3 = DAT_00020b68;
    }
    if (cStack_3 == '\x03') {
      puVar5 = (undefined4 *)&DAT_0008c042;
      bVar1 = DAT_0008c042;
      bStack_4 = bVar1 >> 1 & 1;
    }
    else if (cStack_3 == '\x02') {
      puVar5 = (undefined4 *)&DAT_0008c02c;
      bVar1 = DAT_0008c04c;
      bStack_4 = bVar1 >> 6 & 1;
    }
    else {
      if (cStack_3 != '\x01') {
        return;
      }
      puVar5 = (undefined4 *)&DAT_0008c02c;
      bVar1 = DAT_0008c04c;
      bStack_4 = bVar1 >> 5 & 1;
    }
    if ((cVar4 == '\f') || (cVar4 == '\r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      if (bStack_4 == 0) {
        *puVar5 = 1;
      }
      if (cVar3 == '\0') {
        if (puVar5 == (undefined4 *)0x0) {
          bVar1 = DAT_0008c02c;
          DAT_0008c02c = bVar1 | 0x10;
          if (DAT_0001b4d1 != '\x01') {
            DAT_0001b4d1 = 1;
            FUN_fffb2da6(9);
            return;
          }
        }
        else {
          bVar1 = DAT_0008c02c;
          DAT_0008c02c = bVar1 & 0xef;
          if (DAT_0001b4d1 != '\x03') {
            DAT_0001b4d1 = 3;
            FUN_fffb2da6(0xb);
            return;
          }
        }
      }
      else if (puVar5 == (undefined4 *)0x0) {
        bVar1 = DAT_0008c02c;
        DAT_0008c02c = bVar1 & 0xef;
        if (DAT_0001b4d1 != '\x03') {
          DAT_0001b4d1 = 3;
          FUN_fffb2da6(0xb);
          return;
        }
      }
      else {
        bVar1 = DAT_0008c02c;
        DAT_0008c02c = bVar1 | 0x10;
        if (DAT_0001b4d1 != '\x01') {
          DAT_0001b4d1 = 1;
          FUN_fffb2da6(9);
          return;
        }
      }
    }
    else if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      FUN_fffb2df4();
      bVar1 = DAT_0008c02c;
      DAT_0008c02c = bVar1 | 0x10;
      return;
    }
  }
  return;
}


// ===== FUN_fffb92e7 @ fffb92e7 (105 bytes)

undefined1 FUN_fffb92e7(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012052)[DAT_00012062] = param_1;
  DAT_00012062 = DAT_00012062 + 1;
  if (0xf < DAT_00012062) {
    DAT_00012062 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012052)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9350 @ fffb9350 (105 bytes)

undefined1 FUN_fffb9350(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012063)[DAT_00012073] = param_1;
  DAT_00012073 = DAT_00012073 + 1;
  if (0xf < DAT_00012073) {
    DAT_00012073 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012063)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb93b9 @ fffb93b9 (105 bytes)

undefined1 FUN_fffb93b9(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012074)[DAT_00012084] = param_1;
  DAT_00012084 = DAT_00012084 + 1;
  if (0xf < DAT_00012084) {
    DAT_00012084 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012074)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9422 @ fffb9422 (105 bytes)

undefined1 FUN_fffb9422(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012085)[DAT_00012095] = param_1;
  DAT_00012095 = DAT_00012095 + 1;
  if (0xf < DAT_00012095) {
    DAT_00012095 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012085)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb948b @ fffb948b (110 bytes)

void FUN_fffb948b(undefined4 param_1)

{
  byte local_9;
  float local_8;
  
  *(undefined4 *)(&DAT_00020fd0 + (uint)DAT_00012096 * 4) = param_1;
  DAT_00012096 = DAT_00012096 + 1;
  if (0xf < DAT_00012096) {
    DAT_00012096 = 0;
  }
  local_8 = 0.0;
  for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
    local_8 = *(float *)(&DAT_00020fd0 + (uint)local_9 * 4) + local_8;
  }
  DAT_00020fc8 = local_8 / 16.0;
  return;
}


// ===== FUN_fffb94f9 @ fffb94f9 (163 bytes)

undefined1 FUN_fffb94f9(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012097)[DAT_000120a7] = param_1;
  DAT_000120a7 = DAT_000120a7 + 1;
  if (0xf < DAT_000120a7) {
    DAT_000120a7 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012097)[local_5] + local_4;
  }
  DAT_0001204b = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    if (DAT_0001204b < (byte)(&DAT_00012097)[local_5]) {
      DAT_0001204b = (&DAT_00012097)[local_5];
    }
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb959c @ fffb959c (105 bytes)

undefined1 FUN_fffb959c(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_000120a8)[DAT_000120b8] = param_1;
  DAT_000120b8 = DAT_000120b8 + 1;
  if (0xf < DAT_000120b8) {
    DAT_000120b8 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_000120a8)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9605 @ fffb9605 (367 bytes)

void FUN_fffb9605(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bStack_11;
  char cStack_a;
  undefined2 uStack_6;
  
  iVar6 = FUN_fffb324c(0);
  uStack_6 = 100;
  bVar3 = *(byte *)(iVar6 + 5) & 3;
  FUN_fffb357c(0,2);
  cVar4 = FUN_fffb3445();
  cVar5 = FUN_fffb3196(0);
  bVar2 = DAT_00020b18;
  iVar6 = FUN_fffb4219();
  bVar1 = DAT_000120ba != bVar3;
  if (!bVar1) {
    bVar3 = DAT_000120ba;
  }
  DAT_000120ba = bVar3;
  bStack_11 = DAT_000120b9 != cVar4;
  if (!bStack_11) {
    cVar4 = DAT_000120b9;
  }
  DAT_000120b9 = cVar4;
  bStack_11 = bStack_11 || bVar1;
  if (DAT_000120bb != cVar5) {
    bStack_11 = true;
    DAT_00020b48 = 0;
    DAT_000120bb = cVar5;
  }
  if (bVar2 < 7) {
    cStack_a = '\x03';
  }
  else {
    cStack_a = '\b';
  }
  if (((DAT_0001b4d2 != cStack_a) && (DAT_0001b4d2 = cStack_a, cStack_a == '\b')) &&
     ((uVar7 = FUN_fffb3196(1), 3 < uVar7 || (iVar8 = FUN_fffba192(), iVar8 == 0)))) {
    bStack_11 = true;
    uStack_6 = 0x28;
  }
  iVar8 = DAT_00025d48;
  if (DAT_00025d48 != iVar6) {
    if ((iVar6 == 2) || (iVar6 == 6)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_00025d48 != 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00025d48 != 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    iVar8 = iVar6;
    if (bVar1) {
      FUN_fffb237a(0x2c,3);
      DAT_00020b49 = 0;
    }
  }
  DAT_00025d48 = iVar8;
  if (bStack_11) {
    FUN_fffb237a(0x2a,uStack_6);
    DAT_0001204f = 1;
    FUN_fffb7243(1);
    DAT_0001204f = 0;
    return;
  }
  return;
}


// ===== FUN_fffb9774 @ fffb9774 (340 bytes)

void FUN_fffb9774(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  if (DAT_00009a9f == '\x03') {
    bVar1 = DAT_0008c042;
    if (((bVar1 & 1) == 0) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  else if (DAT_00009a9f == '\x02') {
    bVar1 = DAT_0008c047;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = DAT_0008c04c, (bVar1 & 0x20) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  else {
    if (DAT_00009a9f != '\x01') {
      return;
    }
    bVar1 = DAT_0008c047;
    if (((bVar1 >> 5 & 1) == 1) && (bVar1 = DAT_0008c04c, (bVar1 & 0x40) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) && (DAT_00012050 == '\x01')) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    if (DAT_0001b4d3 == '\0') {
      FUN_fffb2da6(4);
      DAT_0001b4d3 = '\x01';
    }
  }
  else if (DAT_0001b4d3 != '\0') {
    FUN_fffb2df4();
    DAT_0001b4d3 = '\0';
  }
  if ((DAT_00012050 == '\x01') && (DAT_00020b18 == '\x03')) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (!bVar3) {
    if (DAT_0001b4d4 == '\x01') {
      FUN_fffb6fd2(0);
      FUN_fffb7011(0);
    }
    DAT_0001b4d4 = 0;
    return;
  }
  if (bVar2) {
    FUN_fffb6fd2(1);
    FUN_fffb7011(1);
    DAT_0001b4d4 = 1;
    return;
  }
  if (DAT_0001b4d4 != '\x01') {
    return;
  }
  FUN_fffb6fd2(0);
  FUN_fffb7011(0);
  DAT_0001b4d4 = 0;
  return;
}

