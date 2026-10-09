// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb1dad @ fffb1dad (405 bytes)

void FUN_fffb1dad(ushort *param_1,short *param_2,char *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined2 local_1a;
  char *local_c;
  
  if ((*param_1 == 0) || (iVar6 = FUN_fffb23f3(param_4), iVar6 != 1)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  local_c = param_3;
  if (bVar5) {
    local_c = param_3 + -(uint)*param_1;
    *local_c = *param_3;
    *param_1 = 0;
    *param_2 = 0x29bc;
  }
  if (*param_1 == 3) {
    cVar2 = local_c[-3];
    cVar3 = local_c[-2];
    cVar4 = local_c[-1];
    cVar1 = *local_c;
    FUN_fffb3168();
    FUN_fffb3168();
    FUN_fffb3168();
    if ((cVar2 == 'S') && (cVar3 == 'P')) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (bVar5) {
      if (cVar4 != 'N') {
        if (cVar4 == 'R') {
          *param_2 = 7;
          goto LAB_fffb1ea5;
        }
        if (cVar4 != 'n') {
          if (cVar4 == 'W') {
            *param_2 = 8;
          }
          goto LAB_fffb1ea5;
        }
      }
      if (cVar1 == 'W') {
        *param_2 = 9;
      }
      else {
        *param_2 = 8;
      }
    }
    else {
      if ((cVar2 == 'E') && (cVar3 == '9')) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
      if (bVar5) {
        *param_2 = 0x29b2;
      }
    }
  }
LAB_fffb1ea5:
  if ((*param_2 == 0x29bc) && (*local_c == ';')) {
    *param_2 = *param_1 + 1;
  }
  if (param_4 == 4) {
    cVar1 = DAT_00009aba;
    if (DAT_00009dc6 != '\0') {
      cVar1 = DAT_00020b59;
    }
  }
  else {
    cVar1 = DAT_00009abd;
    if (param_4 != 5) {
      cVar1 = DAT_00009abf;
    }
  }
  if (cVar1 == '\x01') {
    local_1a = 100;
  }
  else if (cVar1 == '\x02') {
    local_1a = 1000;
  }
  else if (cVar1 == '\x03') {
    local_1a = 3000;
  }
  else {
    local_1a = 10;
  }
  FUN_fffb237a(param_4,local_1a);
  return;
}


// ===== sci_tx_end @ fffb1f42 (65 bytes)

/* Returns SSR.TEND for CAT port id (1=SCI3, 2=SCI0, other=SCI2) */

byte sci_tx_end(int param_1)

{
  byte bVar1;
  undefined1 local_6;
  
  if (param_1 == 1) {
    bVar1 = DAT_0008a064;
    local_6 = bVar1 >> 2 & 1;
  }
  else if (param_1 == 2) {
    bVar1 = DAT_0008a004;
    local_6 = bVar1 >> 2 & 1;
  }
  else {
    bVar1 = DAT_0008a044;
    local_6 = bVar1 >> 2 & 1;
  }
  return local_6;
}


// ===== FUN_fffb1f83 @ fffb1f83 (108 bytes)

void FUN_fffb1f83(void)

{
  byte bVar1;
  
  FUN_fffb70c9(1);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xbf;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 & 0xbf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  FUN_fffb70b0(0);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 1;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x20;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x80;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x40;
  bVar1 = DAT_0008c020;
  DAT_0008c020 = bVar1 & 0xfb;
  bVar1 = DAT_0008c000;
  DAT_0008c000 = bVar1 | 1;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 | 0x40;
  FUN_fffb70b0(1);
  return;
}


// ===== FUN_fffb1fef @ fffb1fef (158 bytes)

void FUN_fffb1fef(int param_1,byte param_2,short param_3)

{
  byte bVar1;
  bool bVar2;
  byte local_9;
  ushort local_8;
  
  if ((param_1 == 0) || (param_1 == 4)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    return;
  }
  local_8 = param_2 & 0xf | param_3 << 4;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_9 = 0; local_9 < 0xe; local_9 = local_9 + 1) {
    if ((local_8 & 1) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_8 = local_8 >> 1;
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  if (param_1 == 0) {
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 | 0x40;
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 & 0xbf;
    return;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x40;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  return;
}


// ===== FUN_fffb208d @ fffb208d (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb20eb) */

void FUN_fffb208d(char param_1,undefined1 param_2)

{
  byte bVar1;
  byte local_5;
  ushort local_4;
  undefined1 local_1;
  
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0x7f;
  if (param_1 == '\b') {
    local_1 = 1;
  }
  else if (param_1 == '\x02') {
    local_1 = 4;
  }
  else if (param_1 == '\x03') {
    local_1 = 0xc;
  }
  else if (param_1 == '\x04') {
    local_1 = 2;
  }
  else if (param_1 == '\x05') {
    local_1 = 10;
  }
  else if (param_1 == '\x06') {
    local_1 = 6;
  }
  else if (param_1 == '\a') {
    local_1 = 0xe;
  }
  else if (param_1 == '\x01') {
    local_1 = 8;
  }
  else {
    local_1 = 0;
  }
  local_4 = CONCAT11(local_1,param_2);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_5 = 0; local_5 < 0xc; local_5 = local_5 + 1) {
    if ((local_4 & 0x800) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_4 = local_4 << 1;
    FUN_fffb2210(0);
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  FUN_fffb2210(0);
  return;
}


// ===== FUN_fffb214c @ fffb214c (196 bytes)

void FUN_fffb214c(int param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  byte local_9;
  uint local_8;
  
  if ((param_1 == 2) || (param_1 == 3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) && (param_1 != 5)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
    local_8 = param_2;
    for (local_9 = 0; local_9 < 0x18; local_9 = local_9 + 1) {
      if ((local_8 & 0x800000) == 0) {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 & 0xef;
      }
      else {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 | 0x10;
      }
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x20;
      local_8 = local_8 << 1;
      FUN_fffb2210(0);
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xdf;
    }
    if (param_1 == 2) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xfe;
    }
    else if (param_1 == 3) {
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 & 0xdf;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0x7f;
    }
    FUN_fffb2210(0);
    if (param_1 != 2) {
      if (param_1 != 3) {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 | 0x80;
        return;
      }
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 | 0x20;
      return;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 1;
    return;
  }
  return;
}


// ===== FUN_fffb2210 @ fffb2210 (24 bytes)

void FUN_fffb2210(uint param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
  }
  return;
}


// ===== FUN_fffb2228 @ fffb2228 (96 bytes)

void FUN_fffb2228(void)

{
  byte local_1;
  
  for (local_1 = 0; local_1 < 0x4b; local_1 = local_1 + 1) {
    (&DAT_00011fed)[local_1] = 1;
  }
  for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
    (&DAT_0001203a)[local_1] = 1;
  }
  FUN_fffb2419(0,0x1c2,0xfa);
  FUN_fffb2419(1,1000,1000);
  FUN_fff94a38();
  FUN_fffb27b2();
  return;
}


// ===== FUN_fffb2288 @ fffb2288 (242 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2303) */

void FUN_fffb2288(void)

{
  int iVar1;
  byte local_1;
  
  for (local_1 = 0; local_1 < 0x4b; local_1 = local_1 + 1) {
    if (((&DAT_00011fed)[local_1] == '\0') &&
       (*(int *)(&DAT_00020890 + (uint)local_1 * 4) =
             *(int *)(&DAT_00020890 + (uint)local_1 * 4) + 1,
       *(uint *)(&DAT_000209bc + (uint)local_1 * 4) <=
       (*(uint *)(&DAT_00020890 + (uint)local_1 * 4) & 0xff))) {
      (&DAT_00011fed)[local_1] = 1;
    }
  }
  for (local_1 = 0; local_1 < 2; local_1 = local_1 + 1) {
    *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) = *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) + 1;
    iVar1 = (uint)local_1 * 8;
    if ((&DAT_00012038)[local_1] == '\0') {
      if (*(uint *)(&DAT_00020af4 + iVar1) <= (*(uint *)(&DAT_00020ae8 + (uint)local_1 * 4) & 0xff))
      {
        (&DAT_00012038)[local_1] = 1;
        *(undefined4 *)(&DAT_00020ae8 + (uint)local_1 * 4) = 0;
      }
    }
    else if (*(uint *)(&DAT_00020af0 + iVar1) <=
             (*(uint *)(&DAT_00020ae8 + (uint)local_1 * 4) & 0xff)) {
      (&DAT_00012038)[local_1] = 0;
      *(undefined4 *)(&DAT_00020ae8 + (uint)local_1 * 4) = 0;
    }
  }
  return;
}


// ===== FUN_fffb237a @ fffb237a (58 bytes)

void FUN_fffb237a(int param_1,ushort param_2)

{
  if (0x4a < param_1) {
    return;
  }
  *(undefined4 *)(&DAT_00020890 + param_1 * 4) = 0;
  *(uint *)(&DAT_000209bc + param_1 * 4) = (uint)param_2 * 10;
  (&DAT_00011fed)[param_1] = 0;
  return;
}


// ===== FUN_fffb23b4 @ fffb23b4 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb23d3) */

void FUN_fffb23b4(int param_1,int param_2)

{
  if (param_1 < 0x4b) {
    *(undefined4 *)(&DAT_00020890 + param_1 * 4) = 0;
    *(uint *)(&DAT_000209bc + param_1 * 4) = (param_2 + 0x32U) / 100;
    (&DAT_00011fed)[param_1] = 0;
    return;
  }
  return;
}


// ===== FUN_fffb23f3 @ fffb23f3 (19 bytes)

undefined1 FUN_fffb23f3(int param_1)

{
  return (&DAT_00011fed)[param_1];
}


// ===== FUN_fffb2406 @ fffb2406 (19 bytes)

undefined1 FUN_fffb2406(int param_1)

{
  return (&DAT_00012038)[param_1];
}


// ===== FUN_fffb2419 @ fffb2419 (80 bytes)

void FUN_fffb2419(int param_1,ushort param_2,ushort param_3)

{
  if (1 < param_1) {
    return;
  }
  *(undefined4 *)(&DAT_00020ae8 + param_1 * 4) = 0;
  *(uint *)(&DAT_00020af0 + param_1 * 8) = (uint)param_2 * 10;
  *(uint *)(&DAT_00020af4 + param_1 * 8) = (uint)param_3 * 10;
  (&DAT_00012038)[param_1] = 0;
  return;
}


// ===== FUN_fffb2469 @ fffb2469 (58 bytes)

void FUN_fffb2469(void)

{
  DAT_0001fa36 = DAT_0001fa36 + 1;
  if (DAT_0001fa34 <= DAT_0001fa36) {
    DAT_0001fa36 = 0;
  }
  FUN_fff9283d(*(undefined2 *)(DAT_00020b00 + (uint)DAT_0001fa36 * 2));
  return;
}


// ===== FUN_fffb24a3 @ fffb24a3 (39 bytes)

void FUN_fffb24a3(undefined4 param_1,undefined2 param_2)

{
  DAT_0001fa36 = 0;
  DAT_0001fa34 = param_2;
  DAT_00020b00 = param_1;
  FUN_fff94acd();
  return;
}


// ===== FUN_fffb24ca @ fffb24ca (14 bytes)

void FUN_fffb24ca(void)

{
  FUN_fff94adc();
  DAT_00012003 = 1;
  return;
}


// ===== FUN_fffb24d8 @ fffb24d8 (196 bytes)

void FUN_fffb24d8(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffb23f3(0x2d);
  if (iVar2 != 0) {
    FUN_fffb7322(1);
    FUN_fffedd7c();
    DAT_0001b3df = 9;
    DAT_0001b3e0 = 0;
    DAT_0001b3e1 = 0;
    return;
  }
  DAT_0001b3e0 = DAT_0001b3e0 + 1;
  if (DAT_0001b3e0 == 1) {
    FUN_fffb7322(1);
    bVar1 = false;
    while (!bVar1) {
      bVar1 = true;
    }
    FUN_fffb7322(0);
  }
  if (DAT_0001b3df <= DAT_0001b3e0) {
    DAT_0001b3e0 = 0;
    DAT_0001b3e1 = DAT_0001b3e1 + 1;
    if (10 < DAT_0001b3e1) {
      DAT_0001b3e1 = 0;
      if (DAT_0001b3df != 0) {
        DAT_0001b3df = DAT_0001b3df - 1;
        return;
      }
      return;
    }
  }
  return;
}


// ===== FUN_fffb259c @ fffb259c (104 bytes)

void FUN_fffb259c(void)

{
  byte local_1;
  
  for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
    if ((((&DAT_0001203a)[local_1] == '\0') && (*(short *)(&DAT_0001fa2c + (uint)local_1 * 2) != 0))
       && (*(short *)(&DAT_0001fa24 + (uint)local_1 * 2) =
                *(short *)(&DAT_0001fa24 + (uint)local_1 * 2) + 1,
          *(ushort *)(&DAT_0001fa2c + (uint)local_1 * 2) <=
          (*(ushort *)(&DAT_0001fa24 + (uint)local_1 * 2) & 0xff))) {
      (&DAT_0001203a)[local_1] = 1;
    }
  }
  return;
}


// ===== FUN_fffb2604 @ fffb2604 (57 bytes)

void FUN_fffb2604(int param_1,short param_2)

{
  if (3 < param_1) {
    return;
  }
  *(undefined2 *)(&DAT_0001fa24 + param_1 * 2) = 0;
  *(short *)(&DAT_0001fa2c + param_1 * 2) = param_2 * 10;
  (&DAT_0001203a)[param_1] = 0;
  return;
}


// ===== FUN_fffb263d @ fffb263d (66 bytes)

void FUN_fffb263d(void)

{
  undefined1 local_3;
  undefined2 local_2;
  
  local_2 = 0;
  local_3 = DAT_00009b0f;
  if (3 < DAT_00009b0f) {
    local_3 = 3;
  }
  if (local_3 == 3) {
    local_2 = 0xe10;
  }
  else if (local_3 == 2) {
    local_2 = 0x708;
  }
  else if (local_3 == 1) {
    local_2 = 900;
  }
  FUN_fffb2604(0,local_2);
  return;
}


// ===== FUN_fffb267f @ fffb267f (15 bytes)

undefined1 FUN_fffb267f(void)

{
  return DAT_0001203a;
}


// ===== FUN_fffb268e @ fffb268e (49 bytes)

void FUN_fffb268e(void)

{
  ushort uVar1;
  
  if (DAT_00009ac3 == 0) {
    return;
  }
  uVar1 = (ushort)DAT_00009ac3 * 0x3c;
  FUN_fffb2604(1,uVar1);
  FUN_fffb2604(2,*(undefined2 *)(uVar1 - 10));
  return;
}


// ===== FUN_fffb26bf @ fffb26bf (38 bytes)

undefined1 FUN_fffb26bf(void)

{
  undefined1 local_2;
  
  if (DAT_00009ac3 == '\0') {
    local_2 = 0;
  }
  else {
    local_2 = DAT_0001203b;
  }
  return local_2;
}


// ===== FUN_fffb26e5 @ fffb26e5 (51 bytes)

char FUN_fffb26e5(void)

{
  undefined1 local_2;
  
  if (DAT_00009ac3 == '\0') {
    local_2 = '\0';
  }
  else {
    local_2 = DAT_0001203c;
    if (DAT_0001203c == '\x01') {
      FUN_fffb2604(2,0);
    }
  }
  return local_2;
}


// ===== FUN_fffb2718 @ fffb2718 (28 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2723) */

char FUN_fffb2718(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00088116;
  return (char)uVar1 + (char)(uVar1 / 0xff);
}


// ===== FUN_fffb2734 @ fffb2734 (126 bytes)

void FUN_fffb2734(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xf7;
  DAT_0008778e = 0x1c;
  bVar2 = DAT_0008738e;
  DAT_0008738e = bVar2 & 0xf2 | 2;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xf7;
  DAT_00088140 = 0x2e;
  bVar2 = DAT_00088144;
  DAT_00088144 = bVar2 | 0x41;
  DAT_00088142 = 0;
  DAT_00088143 = 0;
  DAT_00088148 = 0x5b8d;
  DAT_0008814a = 0x16;
  DAT_0008814c = 0x16;
  DAT_0008814e = 0x16;
  FUN_fffb27d0();
  return;
}


// ===== FUN_fffb27b2 @ fffb27b2 (15 bytes)

void FUN_fffb27b2(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 | 0x40;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 8;
  return;
}


// ===== FUN_fffb27d0 @ fffb27d0 (1 bytes)

void FUN_fffb27d0(void)

{
  return;
}


// ===== vec142_isr @ fffb27d1 (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb27d9) */
/* WARNING: Removing unreachable block (ram,0xfffb27d1) */
/* WARNING: Removing unreachable block (ram,0xfffb27d3) */
/* WARNING: Removing unreachable block (ram,0xfffb27db) */

undefined4 vec142_isr(undefined4 param_1)

{
  FUN_fffb259c();
  return param_1;
}


// ===== FUN_fffb27df @ fffb27df (1 bytes)

void FUN_fffb27df(void)

{
  return;
}


// ===== FUN_fffb27e0 @ fffb27e0 (27 bytes)

void FUN_fffb27e0(void)

{
  DAT_0001203e = 0;
  DAT_0001203f = 0;
  FUN_fff929f7();
  FUN_fff92c74();
  return;
}


// ===== FUN_fffb27fb @ fffb27fb (83 bytes)

void FUN_fffb27fb(void)

{
  FUN_fff92a31(1,&DAT_00020b04);
  FUN_fff92a31(2,&DAT_00020b06);
  FUN_fff92a31(3,&DAT_00020b08);
  FUN_fff92a31(5,&DAT_00020b0c);
  FUN_fff92a31(6,&DAT_00020b0a);
  FUN_fff92a31(7,&DAT_00020b0e);
  return;
}


// ===== FUN_fffb284e @ fffb284e (10 bytes)

void FUN_fffb284e(void)

{
  DAT_0001203e = 1;
  return;
}


// ===== FUN_fffb2858 @ fffb2858 (60 bytes)

void FUN_fffb2858(void)

{
  FUN_fff92cae(8,&DAT_00020b10);
  FUN_fff92cae(9,&DAT_00020b12);
  FUN_fff92cae(0xf,&DAT_00020b14);
  FUN_fff92cae(0x11,&DAT_00020b16);
  return;
}


// ===== FUN_fffb2894 @ fffb2894 (10 bytes)

void FUN_fffb2894(void)

{
  DAT_0001203f = 1;
  return;
}


// ===== FUN_fffb289e @ fffb289e (51 bytes)

undefined1 FUN_fffb289e(void)

{
  undefined1 uVar1;
  
  if ((DAT_0001203e == '\x01') && (DAT_0001203f == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffb28d1 @ fffb28d1 (17 bytes)

void FUN_fffb28d1(void)

{
  FUN_fff9283d(DAT_0001ff1c);
  FUN_fff92826();
  return;
}


// ===== FUN_fffb28e2 @ fffb28e2 (1220 bytes)

void FUN_fffb28e2(void)

{
  int iVar1;
  float fVar2;
  float fStack_4;
  
  if (DAT_00012040 == '\x01') {
    FUN_fffb2e0d();
    DAT_0001b3e2 = 0;
    DAT_00012040 = 2;
    return;
  }
  if (DAT_00012040 == '\x02') {
    iVar1 = FUN_fffb23f3(0x16);
    if (iVar1 == 1) {
      switch(DAT_00012041) {
      case 1:
        if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x445c0000,100);
          DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        }
        else {
          FUN_fffb2df4();
        }
        break;
      case 2:
        if (DAT_0001b3e2 == '\x02') {
          FUN_fffb2e1e(0x445c0000,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          FUN_fffb2e1e(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x445c0000,100);
        }
        else {
          FUN_fffb2df4();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 3:
        if (DAT_0001b3e2 == '\x04') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          FUN_fffb2e1e(0,100);
        }
        else if (DAT_0001b3e2 == '\x02') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          FUN_fffb2e1e(0,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else {
          FUN_fffb2df4();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 4:
        fVar2 = (float)DAT_00009c04 * 10.0 + 300.0;
        if (DAT_00025d40 == fVar2) {
          FUN_fffb237a(0x16,100);
        }
        else {
          DAT_00025d40 = fVar2;
          FUN_fffb2e1e(fVar2,100);
        }
        break;
      case 5:
        if (DAT_0001b3e2 == '\x04') {
          FUN_fffb2e1e(0x44c3ff6d,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          FUN_fffb2e1e(0,10);
        }
        else if (DAT_0001b3e2 == '\x02') {
          FUN_fffb2e1e(0x44a4d052,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          FUN_fffb2e1e(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else {
          FUN_fffb2df4();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 6:
        if (DAT_0001b3e2 == '\x02') {
          FUN_fffb2e1e(0x4424d052,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          FUN_fffb2e1e(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x4443ff6d,100);
        }
        else {
          FUN_fffb2df4();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 7:
        switch(DAT_0001b3e2) {
        case '\0':
          FUN_fffb2e1e(0x44a4d052,100);
          break;
        case '\x01':
          FUN_fffb2e1e(0,0x28);
          break;
        case '\x02':
          FUN_fffb2e1e(0x44a4d052,100);
          break;
        case '\x03':
          FUN_fffb2e1e(0,0x14);
          break;
        case '\x04':
          FUN_fffb2e1e(0x44a4d052,100);
          break;
        case '\x05':
          FUN_fffb2e1e(0,0x14);
          break;
        case '\x06':
          FUN_fffb2e1e(0x44a4d052,100);
          break;
        case '\a':
          FUN_fffb2e1e(0,0x14);
          break;
        case '\b':
          FUN_fffb2e1e(0x44a4d052,100);
          break;
        default:
          FUN_fffb2df4();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 8:
        if (DAT_0001b3e2 == '\x05') {
          FUN_fffb2e0d();
        }
        else if (DAT_0001b3e2 == '\x01') {
          FUN_fffb2e1e(0,0x46);
        }
        else if (DAT_0001b3e2 == '\x02') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          FUN_fffb2e1e(0,0x46);
        }
        else if (DAT_0001b3e2 == '\x04') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          FUN_fffb2e1e(0x4482d010,100);
        }
        else {
          FUN_fffb2df4();
          DAT_00020f4b = 1;
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 9:
        if (DAT_0001b3e3 == '\t') {
          FUN_fffb237a(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          FUN_fffb2e1e(fStack_4,0xffff);
        }
        break;
      case 10:
        if (DAT_0001b3e3 == '\n') {
          FUN_fffb237a(0x16,0xffff);
        }
        else {
          if (DAT_00009a8d == '\x01') {
            fStack_4 = 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = 850.0;
          }
          else {
            fStack_4 = 170.0;
          }
          FUN_fffb2e1e(fStack_4,0xffff);
        }
        break;
      case 0xb:
        if (DAT_0001b3e3 == '\v') {
          FUN_fffb237a(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          if (DAT_00009a8d == '\x01') {
            fStack_4 = fStack_4 + 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = fStack_4 + 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = fStack_4 + 850.0;
          }
          else {
            fStack_4 = fStack_4 + 170.0;
          }
          FUN_fffb2e1e(fStack_4,0xffff);
        }
        break;
      default:
        FUN_fffb2df4();
      }
      DAT_0001b3e3 = DAT_00012041;
      return;
    }
  }
  else if (DAT_00012040 == '\x03') {
    FUN_fffb2e0d();
    DAT_00012040 = 0;
    DAT_00012041 = 0;
    DAT_00025d40 = 0.0;
    DAT_0001b3e3 = 0;
    return;
  }
  return;
}


// ===== FUN_fffb2da6 @ fffb2da6 (78 bytes)

void FUN_fffb2da6(int param_1)

{
  if (param_1 != 8) {
    if (param_1 - 9U < 3) {
      if (DAT_00012041 == '\x04') {
        return;
      }
    }
    else if (DAT_00012041 != '\0') {
      return;
    }
  }
  DAT_00012041 = (char)param_1;
  DAT_00012040 = 1;
  return;
}


// ===== FUN_fffb2df4 @ fffb2df4 (10 bytes)

void FUN_fffb2df4(void)

{
  DAT_00012040 = 3;
  return;
}


// ===== FUN_fffb2dfe @ fffb2dfe (15 bytes)

undefined1 FUN_fffb2dfe(void)

{
  return DAT_00012041;
}


// ===== FUN_fffb2e0d @ fffb2e0d (17 bytes)

void FUN_fffb2e0d(void)

{
  FUN_fffb24ca();
  FUN_fff9283d(DAT_0001ff1c);
  return;
}


// ===== FUN_fffb2e1e @ fffb2e1e (126 bytes)

void FUN_fffb2e1e(float param_1,undefined2 param_2)

{
  bool bVar1;
  
  if (param_1 - 0.0 != 0.0) {
    if ((param_1 - 30.0 < 0.0) || (20000.0 < param_1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_00088128 = SUB42(ROUND(1.0 / ((param_1 * 36.0) / 6e+07) + -1.0),0);
    FUN_fffb24a3(&DAT_0001ff1c,0x24);
  }
  FUN_fffb237a(0x16,param_2);
  return;
}


// ===== FUN_fffb2e9c @ fffb2e9c (27 bytes)

char FUN_fffb2e9c(byte param_1)

{
  return "@0123456789ABCDEF"[(param_1 & 0xf) + 1];
}


// ===== FUN_fffb2eb7 @ fffb2eb7 (48 bytes)

void FUN_fffb2eb7(char *param_1,byte param_2)

{
  *param_1 = "@0123456789ABCDEF"[(param_2 >> 4) + 1];
  param_1[1] = "@0123456789ABCDEF"[(param_2 & 0xf) + 1];
  return;
}


// ===== FUN_fffb2ee7 @ fffb2ee7 (32 bytes)

void FUN_fffb2ee7(int param_1,undefined4 param_2)

{
  FUN_fffb2eb7(param_1,(char)((uint)param_2 >> 8));
  FUN_fffb2eb7(param_1 + 2,(char)param_2);
  return;
}


// ===== FUN_fffb2f07 @ fffb2f07 (114 bytes)

char FUN_fffb2f07(byte param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = -1;
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    local_3 = param_1 - 0x30;
  }
  else {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_3 = param_1 - 0x37;
    }
    else {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_3 = param_1 + 0xa9;
      }
    }
  }
  return local_3;
}


// ===== FUN_fffb2f79 @ fffb2f79 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2f86) */

byte FUN_fffb2f79(undefined1 *param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = FUN_fffb2f07(*param_1);
  bVar2 = FUN_fffb2f07(param_1[1]);
  return bVar2 | cVar1 << 4;
}


// ===== FUN_fffb2f9e @ fffb2f9e (34 bytes)

ushort FUN_fffb2f9e(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = FUN_fffb2f79();
  uVar2 = FUN_fffb2f79(param_1 + 2);
  return uVar2 | sVar1 << 8;
}

