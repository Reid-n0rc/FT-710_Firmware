// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== cat_SD @ fffadd9a (284 bytes)

/* WARNING: Removing unreachable block (ram,0xfffade46) */
/* WARNING: Removing unreachable block (ram,0xfffade0a) */
/* WARNING: Removing unreachable block (ram,0xfffadeb3) */
/* WARNING: Removing unreachable block (ram,0xfffadeb0) */
/* WARNING: Removing unreachable block (ram,0xfffade5c) */
/* WARNING: Removing unreachable block (ram,0xfffadea4) */
/* WARNING: Removing unreachable block (ram,0xfffaddd5) */

undefined2 * cat_SD(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  if (param_2 == '\0') {
    local_b = 10;
    local_d = DAT_00009c05;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return &DAT_00001c8e;
  }
  local_a = 0;
  for (local_c = 2; local_c < 4; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_a = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_a;
  }
  puVar2 = (undefined2 *)(uint)local_a;
  if ((undefined2 *)0x21 < puVar2) {
    DAT_0000464a = 1;
    return puVar2;
  }
  DAT_00009c05 = local_a;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x32;
    FUN_fffc8cbb(0x32);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return puVar2;
}


// ===== cat_SF @ fffadeb6 (1044 bytes)

void cat_SF(int param_1,char param_2)

{
  char cVar1;
  undefined4 *in_R14;
  
  if (*(char *)(param_1 + 2) == '0') {
    *in_R14 = 1;
  }
  if (param_2 == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) == '1') {
        if (DAT_00020b7e == '!') {
          DAT_00001c91 = 0x35;
        }
        else if (DAT_00020b7e == '\x1e') {
          DAT_00001c91 = 0x32;
        }
        else if (DAT_00020b7e == '\x1f') {
          DAT_00001c91 = 0x33;
        }
        else if (DAT_00020b7e == ' ') {
          DAT_00001c91 = 0x34;
        }
        else if (DAT_00020b7e == '\x1d') {
          DAT_00001c91 = 0x31;
        }
        else {
          DAT_00001c91 = 0x30;
        }
      }
    }
    else {
      switch(DAT_00009dc9) {
      case 0:
        DAT_00001c91 = 0x31;
        break;
      case 1:
        DAT_00001c91 = 0x32;
        break;
      default:
        DAT_00001c91 = 0x30;
        break;
      case 3:
        DAT_00001c91 = 0x33;
        break;
      case 4:
        DAT_00001c91 = 0x34;
        break;
      case 5:
        DAT_00001c91 = 0x35;
        break;
      case 6:
        DAT_00001c91 = 0x36;
        break;
      case 7:
        DAT_00001c91 = 0x37;
        break;
      case 9:
        DAT_00001c91 = 0x38;
        break;
      case 10:
        DAT_00001c91 = 0x39;
        break;
      case 0xb:
        DAT_00001c91 = 0x41;
        break;
      case 0xc:
        DAT_00001c91 = 0x42;
        break;
      case 0xd:
        DAT_00001c91 = 0x43;
        break;
      case 0xe:
        DAT_00001c91 = 0x44;
        break;
      case 0xf:
        DAT_00001c91 = 0x45;
        break;
      case 0x12:
        DAT_00001c91 = 0x46;
        break;
      case 0x13:
        DAT_00001c91 = 0x47;
        break;
      case 0x14:
        DAT_00001c91 = 0x48;
      }
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (in_R14 != (undefined4 *)0x0) {
    switch(*(undefined1 *)(param_1 + 3)) {
    case 0x31:
      DAT_00009dc9 = 0;
      DAT_00009c08 = 0;
      return;
    case 0x32:
      DAT_00009dc9 = 1;
      DAT_00009c08 = 1;
      return;
    case 0x33:
      DAT_00009dc9 = 3;
      DAT_00009c08 = 3;
      return;
    case 0x34:
      DAT_00009dc9 = 4;
      DAT_00009c08 = 4;
      return;
    case 0x35:
      DAT_00009dc9 = 5;
      DAT_00009c08 = 5;
      return;
    case 0x36:
      DAT_00009dc9 = 6;
      DAT_00009c08 = 6;
      return;
    case 0x37:
      DAT_00009dc9 = 7;
      DAT_00009c08 = 7;
      return;
    case 0x38:
      DAT_00009dc9 = 9;
      DAT_00009c08 = 9;
      return;
    case 0x39:
      DAT_00009dc9 = 10;
      DAT_00009c08 = 10;
      return;
    default:
      DAT_0000464a = 1;
      return;
    case 0x41:
      DAT_00009dc9 = 0xb;
      DAT_00009c08 = 0xb;
      return;
    case 0x42:
      DAT_00009dc9 = 0xc;
      DAT_00009c08 = 0xc;
      return;
    case 0x43:
      DAT_00009dc9 = 0xd;
      DAT_00009c08 = 0xd;
      return;
    case 0x44:
      DAT_00009dc9 = 0xe;
      DAT_00009c08 = 0xe;
      return;
    case 0x45:
      DAT_00009dc9 = 0xf;
      DAT_00009c08 = 0xf;
      return;
    case 0x46:
      DAT_00009dc9 = 0x12;
      DAT_00009c08 = 0x12;
      return;
    case 0x47:
      DAT_00009dc9 = 0x13;
      DAT_00009c08 = 0x13;
      return;
    case 0x48:
      DAT_00009dc9 = 0x14;
      DAT_00009c08 = 0x14;
      return;
    }
  }
  if (*(char *)(param_1 + 2) != '1') {
    return;
  }
  cVar1 = *(char *)(param_1 + 3);
  if (cVar1 == '5') {
    DAT_00020b7e = 0x21;
    DAT_00020b77 = 3;
  }
  else if (cVar1 == '2') {
    DAT_00020b7e = 0x1e;
    DAT_00020b77 = 1;
  }
  else if (cVar1 == '3') {
    DAT_00020b7e = 0x1f;
    DAT_00020b77 = 2;
  }
  else if (cVar1 == '4') {
    DAT_00020b7e = 0x20;
    DAT_00020b77 = 3;
  }
  else {
    if (cVar1 != '1') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020b7e = 0x1d;
    DAT_00020b77 = 0;
  }
  FUN_fffc89b0();
  return;
}


// ===== cat_SH @ fffae2ca (897 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae499) */
/* WARNING: Removing unreachable block (ram,0xfffae402) */
/* WARNING: Removing unreachable block (ram,0xfffae5c0) */
/* WARNING: Removing unreachable block (ram,0xfffae648) */
/* WARNING: Removing unreachable block (ram,0xfffae606) */
/* WARNING: Removing unreachable block (ram,0xfffae4af) */
/* WARNING: Removing unreachable block (ram,0xfffae554) */
/* WARNING: Removing unreachable block (ram,0xfffae5cc) */
/* WARNING: Removing unreachable block (ram,0xfffae51c) */
/* WARNING: Removing unreachable block (ram,0xfffae58a) */
/* WARNING: Removing unreachable block (ram,0xfffae2f5) */
/* WARNING: Removing unreachable block (ram,0xfffae45e) */
/* WARNING: Removing unreachable block (ram,0xfffae449) */
/* WARNING: Removing unreachable block (ram,0xfffae37f) */
/* WARNING: Removing unreachable block (ram,0xfffae31e) */
/* WARNING: Removing unreachable block (ram,0xfffae350) */
/* WARNING: Removing unreachable block (ram,0xfffae3af) */

undefined2 * cat_SH(int param_1,char param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 *puVar4;
  char in_stack_0000000c;
  undefined2 *puStack_20;
  int iStack_1c;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  ushort uStack_12;
  
  iStack_1c = FUN_fffb324c(0);
  bVar1 = FUN_fffb3196(0);
  if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 2);
  }
  if (param_2 == '\0') {
    switch(bVar1) {
    case 0:
    case 1:
      cVar2 = FUN_fffb36ff(bVar1,CONCAT11(*(undefined1 *)(iStack_1c + 0x10),
                                          *(undefined1 *)(iStack_1c + 0x11)));
      bStack_17 = cVar2 + 1;
      if (0x17 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 2:
    case 3:
      cVar2 = FUN_fffb36ff(bVar1,CONCAT11(*(undefined1 *)(iStack_1c + 0x1a),
                                          *(undefined1 *)(iStack_1c + 0x1b)));
      bStack_17 = cVar2 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 4:
    case 7:
    case 0xb:
      bStack_17 = 2;
      break;
    case 5:
      bStack_17 = 1;
      break;
    case 6:
    case 10:
      bStack_17 = 3;
      break;
    case 8:
    case 9:
    case 0xe:
      cVar2 = FUN_fffb36ff(bVar1,CONCAT11(*(undefined1 *)(iStack_1c + 0x2e),
                                          *(undefined1 *)(iStack_1c + 0x2f)));
      bStack_17 = cVar2 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 0xc:
    case 0xd:
      cVar2 = FUN_fffb36ff(bVar1,CONCAT11(*(undefined1 *)(iStack_1c + 0x24),
                                          *(undefined1 *)(iStack_1c + 0x25)));
      bStack_17 = cVar2 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
    }
    bStack_15 = 10;
    for (bStack_16 = 0; bStack_16 < 2; bStack_16 = bStack_16 + 1) {
      bVar1 = bStack_17;
      if (bStack_15 != 0) {
        bVar1 = bStack_17 / bStack_15;
      }
      bStack_17 = bStack_17 - bVar1 * bStack_15;
      bStack_15 = bStack_15 / 10;
      uVar3 = FUN_fffb2e9c(bVar1);
      (&DAT_00001c92)[bStack_16] = uVar3;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c91 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  if ((undefined2 *)(uint)*(byte *)(param_1 + 3) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 3);
  }
  bStack_17 = 0;
  for (bStack_16 = 4; bStack_16 < 6; bStack_16 = bStack_16 + 1) {
    if ((*(byte *)((uint)bStack_16 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_16 + param_1))) {
      puStack_20 = (undefined2 *)0x1;
    }
    else {
      puStack_20 = (undefined2 *)0x0;
    }
    if (puStack_20 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return puStack_20;
    }
    bStack_17 = (*(byte *)((uint)bStack_16 + param_1) & 0xf) * in_stack_0000000c + bStack_17;
  }
  puVar4 = (undefined2 *)(uint)bVar1;
  if (puVar4 != (undefined2 *)0xe) {
    if (puVar4 + -1 < (undefined2 *)0x2) {
      iStack_1c = iStack_1c + 0x1a;
      if (bStack_17 == 0) {
        uStack_12 = 500;
      }
      else {
        if ((undefined2 *)0x15 < (undefined2 *)(uint)bStack_17) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)bStack_17;
        }
        uStack_12 = FUN_fffb3775(bVar1,*(undefined1 *)(bStack_17 - 1));
      }
      goto LAB_fffae5cf;
    }
    if ((undefined2 *)0x1 < puVar4 + -4) {
      if (puVar4 + -6 < (undefined2 *)0x2) {
        iStack_1c = iStack_1c + 0x24;
        if (bStack_17 == 0) {
          uStack_12 = 500;
        }
        else {
          if ((undefined2 *)0x15 < (undefined2 *)(uint)bStack_17) {
            DAT_0000464a = 1;
            return (undefined2 *)(uint)bStack_17;
          }
          uStack_12 = FUN_fffb3775(bVar1,*(undefined1 *)(bStack_17 - 1));
        }
      }
      else {
        if ((undefined2 *)0x1 < puVar4) {
          DAT_0000464a = 1;
          return puVar4;
        }
        iStack_1c = iStack_1c + 0x10;
        if (bStack_17 == 0) {
          uStack_12 = 3000;
        }
        else {
          if ((undefined2 *)0x17 < (undefined2 *)(uint)bStack_17) {
            DAT_0000464a = 1;
            return (undefined2 *)(uint)bStack_17;
          }
          uStack_12 = FUN_fffb3775(bVar1,*(undefined1 *)(bStack_17 - 1));
        }
      }
      goto LAB_fffae5cf;
    }
  }
  iStack_1c = iStack_1c + 0x2e;
  if (bStack_17 == 0) {
    uStack_12 = 0xc80;
  }
  else {
    if ((undefined2 *)0x15 < (undefined2 *)(uint)bStack_17) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)bStack_17;
    }
    uStack_12 = FUN_fffb3775(bVar1,*(undefined1 *)(bStack_17 - 1));
  }
LAB_fffae5cf:
  if (uStack_12 == 0xffff) {
    DAT_0000464a = 1;
    return (undefined2 *)0xffff;
  }
  for (bStack_16 = 0; bStack_16 < 2; bStack_16 = bStack_16 + 1) {
    *(char *)((uint)bStack_16 + iStack_1c) = (char)(uStack_12 >> ((1 - bStack_16 & 3) << 3));
  }
  DAT_00020b7e = 0x1e;
  DAT_00020b77 = 1;
  FUN_fffc89b0();
  DAT_00020f10 = 1;
  FUN_fffc2fde(DAT_00009dbd);
  puVar4 = (undefined2 *)FUN_fffc16f6(DAT_00009dbd);
  return puVar4;
}


// ===== cat_SM @ fffae64b (129 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae661) */
/* WARNING: Removing unreachable block (ram,0xfffae68b) */
/* WARNING: Removing unreachable block (ram,0xfffae6c9) */

undefined2 * cat_SM(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  
  if ((undefined2 *)(uint)*(byte *)(param_1 + 2) == (undefined2 *)0x30) {
    bStack_c = FUN_fffb6ea7();
    bStack_a = 100;
    for (bStack_b = 0; bStack_b < 3; bStack_b = bStack_b + 1) {
      bVar2 = bStack_c;
      if (bStack_a != 0) {
        bVar2 = bStack_c / bStack_a;
      }
      bStack_c = bStack_c - bVar2 * bStack_a;
      bStack_a = bStack_a / 10;
      uVar1 = FUN_fffb2e9c(bVar2);
      (&DAT_00001c91)[bStack_b] = uVar1;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  DAT_0000464a = 1;
  return (undefined2 *)(uint)*(byte *)(param_1 + 2);
}


// ===== cat_SQ @ fffae6cc (388 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae7bd) */
/* WARNING: Removing unreachable block (ram,0xfffae782) */
/* WARNING: Removing unreachable block (ram,0xfffae841) */
/* WARNING: Removing unreachable block (ram,0xfffae84d) */
/* WARNING: Removing unreachable block (ram,0xfffae7d3) */
/* WARNING: Removing unreachable block (ram,0xfffae836) */
/* WARNING: Removing unreachable block (ram,0xfffae744) */

undefined2 * cat_SQ(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_0000001c;
  undefined2 *local_18;
  float local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    bVar3 = DAT_00020ba7;
    if (DAT_00009ab6 == '\0') {
      bVar3 = DAT_0000464e;
    }
    local_14 = (float)bVar3;
    local_d = SUB41(ROUND((local_14 * 100.0) / 255.0 + 0.5),0);
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c91)[local_c] = uVar1;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 3; local_c < 6; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_18 = (undefined2 *)0x1;
    }
    else {
      local_18 = (undefined2 *)0x0;
    }
    if (local_18 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_18;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_0000001c + local_d;
  }
  if ((undefined2 *)0x64 < (undefined2 *)(uint)local_d) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)local_d;
  }
  puVar2 = (undefined2 *)(((float)local_d * 255.0) / 100.0 + 0.5);
  DAT_0000464e = SUB41(ROUND((float)puVar2),0);
  if (DAT_00009ab6 != '\0') {
    DAT_00020ba7 = DAT_0000464e;
    return puVar2;
  }
  return puVar2;
}


// ===== cat_SS @ fffae850 (2917 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaf243) */
/* WARNING: Removing unreachable block (ram,0xfffae86b) */
/* WARNING: Removing unreachable block (ram,0xfffaec73) */
/* WARNING: Removing unreachable block (ram,0xfffaec96) */
/* WARNING: Removing unreachable block (ram,0xfffaecae) */
/* WARNING: Removing unreachable block (ram,0xfffaeca2) */
/* WARNING: Removing unreachable block (ram,0xfffaed06) */
/* WARNING: Removing unreachable block (ram,0xfffaed30) */
/* WARNING: Removing unreachable block (ram,0xfffaed24) */
/* WARNING: Removing unreachable block (ram,0xfffaed88) */
/* WARNING: Removing unreachable block (ram,0xfffaedb2) */
/* WARNING: Removing unreachable block (ram,0xfffaeda6) */
/* WARNING: Removing unreachable block (ram,0xfffaee0a) */
/* WARNING: Removing unreachable block (ram,0xfffaee34) */
/* WARNING: Removing unreachable block (ram,0xfffaee28) */
/* WARNING: Removing unreachable block (ram,0xfffaee96) */
/* WARNING: Removing unreachable block (ram,0xfffaef84) */
/* WARNING: Removing unreachable block (ram,0xfffaef8d) */
/* WARNING: Removing unreachable block (ram,0xfffaeeac) */
/* WARNING: Removing unreachable block (ram,0xfffaef39) */
/* WARNING: Removing unreachable block (ram,0xfffaf277) */
/* WARNING: Removing unreachable block (ram,0xfffaf2ae) */
/* WARNING: Removing unreachable block (ram,0xfffaf2d9) */
/* WARNING: Removing unreachable block (ram,0xfffaf324) */
/* WARNING: Removing unreachable block (ram,0xfffaf39a) */
/* WARNING: Removing unreachable block (ram,0xfffaf3a6) */
/* WARNING: Removing unreachable block (ram,0xfffaf37c) */
/* WARNING: Removing unreachable block (ram,0xfffaf3b2) */
/* WARNING: Removing unreachable block (ram,0xfffaf21b) */
/* WARNING: Removing unreachable block (ram,0xfffaf20f) */
/* WARNING: Removing unreachable block (ram,0xfffaf1e0) */
/* WARNING: Removing unreachable block (ram,0xfffaf1b1) */
/* WARNING: Removing unreachable block (ram,0xfffaf1a5) */
/* WARNING: Removing unreachable block (ram,0xfffaf176) */
/* WARNING: Removing unreachable block (ram,0xfffaf147) */
/* WARNING: Removing unreachable block (ram,0xfffaf13b) */
/* WARNING: Removing unreachable block (ram,0xfffaf10c) */
/* WARNING: Removing unreachable block (ram,0xfffaf0dd) */
/* WARNING: Removing unreachable block (ram,0xfffaf0c4) */
/* WARNING: Removing unreachable block (ram,0xfffaf0ab) */
/* WARNING: Removing unreachable block (ram,0xfffaf227) */
/* WARNING: Removing unreachable block (ram,0xfffaf074) */
/* WARNING: Removing unreachable block (ram,0xfffaf010) */
/* WARNING: Removing unreachable block (ram,0xfffaf01c) */
/* WARNING: Removing unreachable block (ram,0xfffaefe5) */
/* WARNING: Removing unreachable block (ram,0xfffaec1d) */
/* WARNING: Removing unreachable block (ram,0xfffae9e4) */
/* WARNING: Removing unreachable block (ram,0xfffaebfd) */
/* WARNING: Removing unreachable block (ram,0xfffaeb21) */
/* WARNING: Removing unreachable block (ram,0xfffaeae3) */
/* WARNING: Removing unreachable block (ram,0xfffaeae6) */
/* WARNING: Removing unreachable block (ram,0xfffaeae5) */
/* WARNING: Removing unreachable block (ram,0xfffaeaf0) */
/* WARNING: Removing unreachable block (ram,0xfffaeaf1) */
/* WARNING: Removing unreachable block (ram,0xfffaeb09) */
/* WARNING: Removing unreachable block (ram,0xfffaef62) */

byte * cat_SS(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  byte extraout_R1;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  char in_stack_00000018;
  byte *pbStack_20;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  if ((byte *)(uint)*(byte *)(param_1 + 2) != (byte *)0x30) {
    DAT_0000464a = 1;
    return (byte *)(uint)*(byte *)(param_1 + 2);
  }
  puVar9 = (undefined4 *)FUN_fffb2f07(*(undefined1 *)(param_1 + 3));
  if (extraout_R1 == 0) {
    *puVar9 = 1;
  }
  if (param_2 == '\0') {
    if (puVar9 == (undefined4 *)0x0) {
      if (extraout_R1 == 1) {
        pbVar8 = (byte *)FUN_fffb2e9c(DAT_00009be6);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
      else if (extraout_R1 == 2) {
        pbVar8 = (byte *)FUN_fffb2e9c(DAT_00009be7);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
      else if (extraout_R1 == 3) {
        pbVar8 = (byte *)FUN_fffb2e9c(DAT_00009be8);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
      else if (extraout_R1 == 4) {
        uVar7 = FUN_fffb357c(DAT_00020b6b,2);
        pbVar8 = (byte *)FUN_fffa150c(uVar7,DAT_00020b6b);
        if (*pbVar8 < 0x3c) {
          DAT_00001c92 = 0x2d;
          bStack_11 = 0x3c - *pbVar8;
        }
        else {
          DAT_00001c92 = 0x2b;
          bStack_11 = *pbVar8 - 0x3c;
        }
        bStack_14 = bStack_11 >> 1;
        bStack_12 = 10;
        for (bStack_13 = 0; bStack_13 < 2; bStack_13 = bStack_13 + 1) {
          bVar4 = bStack_14;
          if (bStack_12 != 0) {
            bVar4 = bStack_14 / bStack_12;
          }
          bStack_14 = bStack_14 - bVar4 * bStack_12;
          bStack_12 = bStack_12 / 10;
          pbVar8 = (byte *)FUN_fffb2e9c(bVar4);
          *(char *)((int)&DAT_00001c93 + (uint)bStack_13) = (char)pbVar8;
        }
        DAT_00001c93._0_3_ = CONCAT12(0x2e,(undefined2)DAT_00001c93);
        if ((bStack_11 & 1) == 0) {
          DAT_00001c93 = CONCAT13(0x30,(undefined3)DAT_00001c93);
        }
        else {
          DAT_00001c93 = CONCAT13(0x35,(undefined3)DAT_00001c93);
        }
      }
      else if (extraout_R1 == 5) {
        uVar7 = FUN_fffb357c(0,2);
        puVar6 = (undefined1 *)FUN_fffa1541(uVar7);
        pbVar8 = (byte *)FUN_fffb2e9c(*puVar6);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
      else if (extraout_R1 == 6) {
        if (DAT_00009c35 == '\0') {
          uRam00000000 = 1;
        }
        if (DAT_00009c36 == '\0') {
          if (DAT_00009c35 == '\0') {
            if (DAT_00009c38 == '\0') {
              uRam00000000 = 1;
              bStack_11 = 0xb;
            }
            else {
              bStack_11 = 9;
            }
          }
          else if (DAT_00009c38 == '\0') {
            bStack_11 = 3;
          }
          else if (DAT_00009c38 == '\x01') {
            bStack_11 = 4;
          }
          else {
            bStack_11 = 5;
          }
        }
        else if (DAT_00009c35 == '\0') {
          bStack_11 = 2;
        }
        else {
          bStack_11 = 0;
        }
        pbVar8 = (byte *)FUN_fffb2e9c(bStack_11);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
      else if (extraout_R1 == 7) {
        DAT_00001c92 = FUN_fffb2e9c(DAT_00009c39);
        uVar3 = FUN_fffb2e9c(DAT_00009c3b);
        DAT_00001c93 = CONCAT31(DAT_00001c93._1_3_,uVar3);
        uVar3 = FUN_fffb2e9c(DAT_00009c3c);
        DAT_00001c93._0_2_ = CONCAT11(uVar3,(undefined1)DAT_00001c93);
        pbVar8 = (byte *)FUN_fffb2e9c(DAT_00009c3a);
        DAT_00001c93._0_3_ = CONCAT12((char)pbVar8,(undefined2)DAT_00001c93);
        DAT_00001c93 = CONCAT13(0x30,(undefined3)DAT_00001c93);
      }
      else {
        if (extraout_R1 != 8) {
          DAT_0000464a = 1;
          return (byte *)0x0;
        }
        pbVar8 = (byte *)FUN_fffb2e9c(DAT_00020f1f);
        DAT_00001c92 = SUB41(pbVar8,0);
        DAT_00001c93 = 0x30303030;
      }
    }
    else {
      iVar5 = FUN_fffc4f8f();
      if (iVar5 == 1) {
        bStack_11 = 5;
      }
      else {
        bStack_11 = DAT_00009c5a;
      }
      pbVar8 = (byte *)FUN_fffb2e9c(bStack_11);
      DAT_00001c92 = SUB41(pbVar8,0);
      DAT_00001c93 = 0x30303030;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c97 = 0x3b;
    DAT_0001b788 = 10;
    return pbVar8;
  }
  if (puVar9 != (undefined4 *)0x0) {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 != (byte *)0x0) {
      DAT_0000464a = 1;
      return pbStack_20;
    }
    bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
    pbVar8 = (byte *)(uint)bVar4;
    if (pbVar8 < (byte *)0x5) {
      DAT_00009c5a = bVar4;
      pbVar8 = (byte *)FUN_fffc4f9e(0);
      return pbVar8;
    }
    if (pbVar8 != (byte *)0x5) {
      DAT_0000464a = 1;
      return pbVar8;
    }
    pbVar8 = (byte *)FUN_fffc4f9e(1);
    return pbVar8;
  }
  if (extraout_R1 == 1) {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 == (byte *)0x0) {
      bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
      pbVar8 = (byte *)(uint)bVar4;
      if ((byte *)0x4 < pbVar8) {
        DAT_0000464a = 1;
        return pbVar8;
      }
      DAT_00009be6 = bVar4;
      return pbVar8;
    }
    DAT_0000464a = 1;
    return pbStack_20;
  }
  if (extraout_R1 == 2) {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 == (byte *)0x0) {
      bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
      pbVar8 = (byte *)(uint)bVar4;
      if ((byte *)0x1 < pbVar8) {
        DAT_0000464a = 1;
        return pbVar8;
      }
      DAT_00009be7 = bVar4;
      return pbVar8;
    }
    DAT_0000464a = 1;
    return pbStack_20;
  }
  if (extraout_R1 == 3) {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 == (byte *)0x0) {
      bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
      pbVar8 = (byte *)(uint)bVar4;
      if ((byte *)0xa < pbVar8) {
        DAT_0000464a = 1;
        return pbVar8;
      }
      DAT_00009be8 = bVar4;
      return pbVar8;
    }
    DAT_0000464a = 1;
    return pbStack_20;
  }
  if (extraout_R1 != 4) {
    if (extraout_R1 == 5) {
      if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
        pbStack_20 = (byte *)0x1;
      }
      else {
        pbStack_20 = (byte *)0x0;
      }
      if (pbStack_20 == (byte *)0x0) {
        uVar7 = FUN_fffb357c(0,2);
        pbVar8 = (byte *)FUN_fffa1541(uVar7);
        bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
        if ((byte *)0x9 < (byte *)(uint)bVar4) {
          DAT_0000464a = 1;
          return (byte *)(uint)bVar4;
        }
        *pbVar8 = bVar4;
        return (byte *)(uint)bVar4;
      }
      DAT_0000464a = 1;
      return pbStack_20;
    }
    if (extraout_R1 == 6) {
      if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
        pbStack_20 = (byte *)0x1;
      }
      else {
        pbStack_20 = (byte *)0x0;
      }
      if (pbStack_20 == (byte *)0x0) {
        bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
        pbVar8 = (byte *)(uint)bVar4;
        switch(pbVar8) {
        case (byte *)0x0:
          DAT_00009c36 = 1;
          DAT_00009c35 = 0;
          return pbVar8;
        case (byte *)0x1:
          DAT_00009c36 = 1;
          DAT_00009c35 = 1;
          return pbVar8;
        case (byte *)0x2:
          DAT_00009c36 = 1;
          DAT_00009c35 = 2;
          return pbVar8;
        case (byte *)0x3:
          DAT_00009c36 = 0;
          DAT_00009c35 = 0;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return pbVar8;
        case (byte *)0x4:
          DAT_00009c36 = 0;
          DAT_00009c35 = 0;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return pbVar8;
        case (byte *)0x5:
          DAT_0000464a = 1;
          return pbVar8;
        case (byte *)0x6:
          DAT_00009c36 = 0;
          DAT_00009c35 = 1;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return pbVar8;
        case (byte *)0x7:
          DAT_00009c36 = 0;
          DAT_00009c35 = 1;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return pbVar8;
        case (byte *)0x8:
          DAT_0000464a = 1;
          return pbVar8;
        case (byte *)0x9:
          DAT_00009c36 = 0;
          DAT_00009c35 = 2;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return pbVar8;
        case (byte *)0xa:
          DAT_00009c36 = 0;
          DAT_00009c35 = 2;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return pbVar8;
        case (byte *)0xb:
          DAT_0000464a = 1;
          return pbVar8;
        default:
          DAT_0000464a = 1;
          return pbVar8;
        }
      }
      DAT_0000464a = 1;
      return pbStack_20;
    }
    if (extraout_R1 == 7) {
      if ((byte *)(uint)*(byte *)(param_1 + 8) != (byte *)0x30) {
        DAT_0000464a = 1;
        return (byte *)(uint)*(byte *)(param_1 + 8);
      }
      bStack_13 = 4;
      while( true ) {
        if (5 < bStack_13) {
          if ((*(byte *)(param_1 + 6) < 0x30) || (0x35 < *(byte *)(param_1 + 6))) {
            pbStack_20 = (byte *)0x1;
          }
          else {
            pbStack_20 = (byte *)0x0;
          }
          if (pbStack_20 == (byte *)0x0) {
            if ((*(byte *)(param_1 + 7) < 0x30) || (0x32 < *(byte *)(param_1 + 7))) {
              pbStack_20 = (byte *)0x1;
            }
            else {
              pbStack_20 = (byte *)0x0;
            }
            if (pbStack_20 == (byte *)0x0) {
              DAT_00009c39 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
              DAT_00009c3b = FUN_fffb2f07(*(undefined1 *)(param_1 + 5));
              DAT_00009c3c = FUN_fffb2f07(*(undefined1 *)(param_1 + 6));
              pbVar8 = (byte *)FUN_fffb2f07(*(undefined1 *)(param_1 + 7));
              DAT_00009c3a = (char)pbVar8;
              return pbVar8;
            }
            DAT_0000464a = 1;
            return pbStack_20;
          }
          DAT_0000464a = 1;
          return pbStack_20;
        }
        if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
           (0x32 < *(byte *)((uint)bStack_13 + param_1))) {
          pbStack_20 = (byte *)0x1;
        }
        else {
          pbStack_20 = (byte *)0x0;
        }
        if (pbStack_20 != (byte *)0x0) break;
        bStack_13 = bStack_13 + 1;
      }
      DAT_0000464a = 1;
      return pbStack_20;
    }
    if ((byte *)(uint)extraout_R1 != (byte *)0x8) {
      DAT_0000464a = 1;
      return (byte *)(uint)extraout_R1;
    }
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) || (*(char *)(param_1 + 7) != '0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (*(char *)(param_1 + 8) != '0')) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 == (byte *)0x0) {
      bVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
      pbVar8 = (byte *)(uint)bVar4;
      if ((byte *)0x1 < pbVar8) {
        DAT_0000464a = 1;
        return pbVar8;
      }
      DAT_00020f1f = bVar4;
      return pbVar8;
    }
    DAT_0000464a = 1;
    return pbStack_20;
  }
  uVar7 = FUN_fffb357c(DAT_00020b6b,2);
  pbVar8 = (byte *)FUN_fffa150c(uVar7,DAT_00020b6b);
  bStack_14 = 0;
  for (bStack_13 = 5; bStack_13 < 7; bStack_13 = bStack_13 + 1) {
    if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_13 + param_1))) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 != (byte *)0x0) {
      DAT_0000464a = 1;
      return pbStack_20;
    }
    bStack_14 = (*(byte *)((uint)bStack_13 + param_1) & 0xf) * in_stack_00000018 + bStack_14;
  }
  cVar1 = *(char *)(param_1 + 4);
  if ((bStack_14 < 0x1f) && (*(char *)(param_1 + 7) == '.')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
LAB_fffaeef9:
    bVar2 = true;
  }
  else {
    if ((cVar1 == '+') || (cVar1 == '-')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) goto LAB_fffaeef9;
    bVar2 = false;
  }
  if (!bVar2) {
    if ((*(char *)(param_1 + 8) == '0') || (*(char *)(param_1 + 8) == '5')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      pbStack_20 = (byte *)0x0;
      goto LAB_fffaef2a;
    }
  }
  pbStack_20 = (byte *)0x1;
LAB_fffaef2a:
  if (pbStack_20 != (byte *)0x0) {
    DAT_0000464a = 1;
    return pbStack_20;
  }
  if (cVar1 == '-') {
    bStack_14 = ('\x1e' - bStack_14) * '\x02';
    if (*(char *)(param_1 + 8) == '5') {
      bStack_14 = bStack_14 - 1;
    }
  }
  else {
    bStack_14 = (bStack_14 + 0x1e) * '\x02';
    if (*(char *)(param_1 + 8) == '5') {
      bStack_14 = bStack_14 + 1;
    }
  }
  if ((byte *)(uint)bStack_14 < (byte *)0x79) {
    *pbVar8 = bStack_14;
    return (byte *)(uint)bStack_14;
  }
  DAT_0000464a = 1;
  return (byte *)(uint)bStack_14;
}


// ===== cat_ST @ fffaf3b5 (185 bytes)

void cat_ST(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    if (DAT_00009c5e == '\0') {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar1 = FUN_fffb44f7(0x305,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b3d != '\0') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009c5e == '\x01') {
      FUN_fffbeca5();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00009c5e == '\0') {
      FUN_fffbeca5();
      return;
    }
  }
  return;
}


// ===== cat_SV @ fffaf46e (345 bytes)

void cat_SV(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffb44f7(0x30a,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffbf4bb();
  return;
}


// ===== cat_TS @ fffaf5c7 (497 bytes)

void cat_TS(int param_1,char param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 auStack_5f [90];
  char local_5;
  int local_4;
  
  local_4 = param_1;
  local_5 = param_2;
  if (param_2 == '\0') {
    if (DAT_00020f09 == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 0;
    if (DAT_00020f09 == '\x01') {
      DAT_00020f09 = 0;
      puVar3 = &DAT_00009d09;
      puVar2 = auStack_5f;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar3 = &DAT_00009d63;
      puVar2 = &DAT_00009d09;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = &DAT_00009d63;
      puVar3 = auStack_5f;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      DAT_00020f0f = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  iVar4 = FUN_fffb44f7(0xec,0);
  if (iVar4 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009c5e != '\x01') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 1;
    if (DAT_00020f09 == '\0') {
      DAT_00020f09 = 1;
      puVar3 = &DAT_00009d09;
      puVar2 = auStack_5f;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar3 = &DAT_00009d63;
      puVar2 = &DAT_00009d09;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = &DAT_00009d63;
      puVar3 = auStack_5f;
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      DAT_00020f0f = 1;
      return;
    }
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_TX @ fffaf7b8 (188 bytes)

void cat_TX(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  
  if (param_2 == '\0') {
    cVar2 = FUN_fffb6ec5();
    if (cVar2 == '\0') {
      DAT_00001c90 = 0x30;
    }
    else if (cVar2 == '\x05') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x32;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  cVar2 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  if (cVar2 == '\0') {
    DAT_00020b28 = 0;
    return;
  }
  if (cVar2 == '\x01') {
    DAT_00020b28 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VD @ fffaf874 (332 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaf93d) */
/* WARNING: Removing unreachable block (ram,0xfffaf902) */
/* WARNING: Removing unreachable block (ram,0xfffaf9bd) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ba) */
/* WARNING: Removing unreachable block (ram,0xfffaf953) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ae) */
/* WARNING: Removing unreachable block (ram,0xfffaf8cd) */

undefined2 * cat_VD(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_d = DAT_00009bf4;
    }
    else {
      local_d = DAT_00009bf5;
    }
    local_b = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 2; local_c < 4; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
  }
  if ((undefined2 *)0x21 < (undefined2 *)(uint)local_d) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)local_d;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf4 = local_d;
  }
  else {
    DAT_00009bf5 = local_d;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2a;
    FUN_fffc8cbb(0x2a);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return (undefined2 *)(uint)local_d;
}


// ===== cat_VG @ fffaf9c0 (283 bytes)

/* WARNING: Removing unreachable block (ram,0xfffafa6b) */
/* WARNING: Removing unreachable block (ram,0xfffafa30) */
/* WARNING: Removing unreachable block (ram,0xfffafad8) */
/* WARNING: Removing unreachable block (ram,0xfffafad5) */
/* WARNING: Removing unreachable block (ram,0xfffafa81) */
/* WARNING: Removing unreachable block (ram,0xfffafac9) */
/* WARNING: Removing unreachable block (ram,0xfffaf9fb) */

undefined2 * cat_VG(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00009bf3;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
  }
  puVar2 = (undefined2 *)(uint)local_d;
  if ((undefined2 *)0x64 < puVar2) {
    DAT_0000464a = 1;
    return puVar2;
  }
  DAT_00009bf3 = local_d;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x29;
    FUN_fffc8cbb(0x29);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return puVar2;
}


// ===== cat_VM @ fffafadb (738 bytes)

void cat_VM(int param_1,short param_2)

{
  bool bVar1;
  int iVar2;
  byte local_8;
  char local_7;
  
  if ((param_2 == 3) || (*(char *)(param_1 + 2) == '0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_7 = DAT_00009dbe;
    local_8 = DAT_000060c9;
  }
  else {
    local_7 = DAT_00009dbf;
    local_8 = DAT_000060ca;
  }
  if (param_2 == 4) {
    DAT_00001c90 = 0x30;
    if (local_7 == '\x02') {
      if (local_8 < 0x84) {
        if (local_8 < 0x75) {
          if (local_8 < 99) {
            FUN_fffb2eb7(&DAT_00001c91,0x11);
          }
          else {
            FUN_fffb2eb7(&DAT_00001c91,0x21);
          }
        }
        else {
          FUN_fffb2eb7(&DAT_00001c91,0x51);
        }
      }
      else {
        FUN_fffb2eb7(&DAT_00001c91,0x91);
      }
    }
    else if (local_7 == '\x03') {
      FUN_fffb2eb7(&DAT_00001c91,0x10);
    }
    else if (local_7 == '\x04') {
      FUN_fffb2eb7(&DAT_00001c91,0x20);
    }
    else {
      FUN_fffb2eb7(&DAT_00001c91,0);
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  iVar2 = FUN_fffb44f7(0x309,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (param_2 == 3) {
      FUN_fffbf41f();
      return;
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (local_7 != '\x01') {
        FUN_fffbf41f();
        if (DAT_00009dbd == '\0') {
          local_7 = DAT_00009dbe;
        }
        else {
          local_7 = DAT_00009dbf;
        }
        if (local_7 != '\x01') {
          FUN_fffbf41f();
          return;
        }
      }
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VS @ fffafdbd (483 bytes)

void cat_VS(int param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    DAT_00001c90 = FUN_fffb2e9c(DAT_00009dbd);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar2 = FUN_fffb44f7(0x30a,0);
  if (iVar2 != 0) {
    if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f0c != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b8a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b3d != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cce == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f1b == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020ccd == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b7c != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cd0 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cd1 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f11 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_00009c5e = 0;
      if (*(char *)(param_1 + 2) == '0') {
        if (DAT_00009dbd == '\x01') {
          FUN_fffbf4bb();
        }
      }
      else {
        if (*(char *)(param_1 + 2) != '1') {
          DAT_0000464a = 1;
          return;
        }
        if (DAT_00009dbd == '\0') {
          FUN_fffbf4bb();
        }
      }
      DAT_00020f10 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VX @ fffaffa0 (206 bytes)

void cat_VX(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  FUN_fffb324c(0);
  bVar2 = FUN_fffb3196(1);
  if (param_2 == '\0') {
    uVar1 = (uint)bVar2;
    if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = FUN_fffb2e9c(DAT_00009c5d);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar3 = FUN_fffb44f7(0x302,0);
  if (iVar3 == 0) {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00009c5d = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00009c5d = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ZI @ fffb006e (190 bytes)

void cat_ZI(int param_1)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = FUN_fffb44f7(0x307,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  pbVar3 = (byte *)FUN_fffb324c(DAT_00020b6b);
  if (((*pbVar3 & 0xf) == 2) || ((*pbVar3 & 0xf) == 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffbf0b6();
  return;
}


// ===== FUN_fffb012c @ fffb012c (58 bytes)

void FUN_fffb012c(int param_1,char param_2,ushort param_3)

{
  ushort local_e;
  
  for (local_e = 0; (local_e < param_3 && (*(char *)((uint)local_e + param_1) != param_2));
      local_e = local_e + 1) {
  }
  return;
}


// ===== FUN_fffb0166 @ fffb0166 (28 bytes)

void FUN_fffb0166(void)

{
  DAT_00001c8e._0_1_ = 0x3f;
  DAT_00001c8e._1_1_ = 0x3b;
  DAT_0001b788 = 2;
  return;
}


// ===== FUN_fffb0182 @ fffb0182 (45 bytes)

bool FUN_fffb0182(int param_1,ushort param_2)

{
  char cVar1;
  
  cVar1 = FUN_fffb01af(param_1,param_2);
  return cVar1 == *(char *)((uint)param_2 + param_1);
}


// ===== FUN_fffb01af @ fffb01af (48 bytes)

char FUN_fffb01af(int param_1,ushort param_2)

{
  undefined1 local_b;
  undefined2 local_a;
  
  local_b = '\0';
  for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
    local_b = *(char *)((uint)local_a + param_1) + local_b;
  }
  return local_b;
}


// ===== FUN_fffb01df @ fffb01df (20 bytes)

void FUN_fffb01df(byte param_1)

{
  (&DAT_000060cb)[param_1] = 1;
  return;
}


// ===== FUN_fffb01f3 @ fffb01f3 (54 bytes)

void FUN_fffb01f3(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x20;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(1);
  eeprom_spi_tx(0x80);
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xdf;
  return;
}


// ===== FUN_fffb0229 @ fffb0229 (134 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb0229(void)

{
  eeprom_read(0,&DAT_0000464f,10);
  if (DAT_00004657._1_1_ == '\x01') {
    eeprom_read(0,&DAT_0000464f,&DAT_00005837);
    return;
  }
  if (DAT_00004657._1_1_ == '\0') {
    eeprom_read(10,&DAT_00004659,0x105);
    eeprom_read(0x10f,&DAT_0000475e,3);
    FUN_fffb0558(0);
  }
  else {
    DAT_00004657 = 0;
    DAT_00004653 = 0;
    _DAT_0000464f = 0;
    FUN_fffb0558(1);
    FUN_fffb0532();
    FUN_fffb0544();
  }
  DAT_00020b45 = 1;
  return;
}


// ===== FUN_fffb02af @ fffb02af (32 bytes)

void FUN_fffb02af(void)

{
  FUN_fffb142b(0);
  eeprom_write(0x112,&DAT_00004761,&DAT_00005725);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb02cf @ fffb02cf (52 bytes)

void FUN_fffb02cf(void)

{
  FUN_fffb142b(0);
  eeprom_write(&DAT_000053db,&DAT_00009a2a,0x45c);
  eeprom_write(&DAT_00001a62,&DAT_000060b1,0x18);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb0303 @ fffb0303 (83 bytes)

void FUN_fffb0303(char param_1,byte param_2,byte param_3,undefined4 param_4)

{
  int iVar1;
  short local_a;
  
  local_a = 0x112;
  iVar1 = FUN_fffb4b28();
  if (iVar1 != 1) {
    if (param_1 != '\0') {
      local_a = 0xdba;
    }
    FUN_fffb142b(0);
    eeprom_write((ushort)param_2 * 0x5a + (ushort)param_3 * 0x438 + local_a,param_4,0x5a);
    FUN_fffb142b(1);
    return;
  }
  return;
}


// ===== FUN_fffb0356 @ fffb0356 (32 bytes)

void FUN_fffb0356(void)

{
  FUN_fffb142b(0);
  eeprom_write(&DAT_00001a7a,&DAT_000060c9,&DAT_00002f49);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb0376 @ fffb0376 (75 bytes)

void FUN_fffb0376(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffb4b28();
  if (iVar1 == 1) {
    return;
  }
  FUN_fffb142b(0);
  eeprom_write(&DAT_00001a7a,&DAT_000060c9,0x87);
  eeprom_write(*(undefined2 *)(&DAT_00001b01 + (uint)param_1 * 0x5a),
               &DAT_00006150 + (uint)param_1 * 0x5a,0x5a);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb03c1 @ fffb03c1 (32 bytes)

void FUN_fffb03c1(void)

{
  FUN_fffb142b(0);
  eeprom_write(&DAT_000049c3,&DAT_00009012,0x395);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb03e1 @ fffb03e1 (111 bytes)

void FUN_fffb03e1(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffb4b28();
  if (iVar1 == 1) {
    return;
  }
  FUN_fffb142b(0);
  eeprom_write(&DAT_000049c3,&DAT_00009012,0x11);
  eeprom_write(*(undefined2 *)(&DAT_000049d4 + (uint)param_1 * 0x5a),
               &DAT_00009023 + (uint)param_1 * 0x5a,0x5a);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb0450 @ fffb0450 (185 bytes)

void FUN_fffb0450(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = FUN_fffb4b28();
  if ((iVar3 != 1) && (param_1 < 3)) {
    if ((param_2 < 1) || (5 < param_2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      sVar1 = (short)param_2 + -1;
      FUN_fffb142b(0);
      if (param_1 == 0) {
        eeprom_write(*(undefined2 *)(&DAT_00004d58 + (ushort)(sVar1 * 0x98)),
                     (int)&DAT_000093a7 + (uint)(ushort)(sVar1 * 0x98),0x98);
      }
      else if (param_1 == 1) {
        eeprom_write(*(undefined2 *)(&DAT_00005050 + (ushort)(sVar1 * 0x33)),
                     &DAT_0000969f + (ushort)(sVar1 * 0x33),0x33);
      }
      else {
        eeprom_write(*(undefined2 *)(&DAT_0000514f + (ushort)(sVar1 * 0x32)),
                     (int)&DAT_0000979e + (uint)(ushort)(sVar1 * 0x32),0x32);
      }
      FUN_fffb142b(1);
      return;
    }
  }
  return;
}


// ===== FUN_fffb0509 @ fffb0509 (41 bytes)

void FUN_fffb0509(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb4b28();
  if (iVar1 == 1) {
    return;
  }
  FUN_fffb142b(0);
  eeprom_write(&DAT_00005249,&DAT_00009898,0x192);
  FUN_fffb142b(1);
  return;
}


// ===== FUN_fffb0532 @ fffb0532 (18 bytes)

void FUN_fffb0532(void)

{
  eeprom_write(10,&DAT_00004659,0x105);
  return;
}


// ===== FUN_fffb0544 @ fffb0544 (20 bytes)

void FUN_fffb0544(void)

{
  eeprom_write(0x10f,&DAT_0000475e,3);
  return;
}


// ===== FUN_fffb0558 @ fffb0558 (222 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb0558(char param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (param_1 == '\x01') {
    puVar2 = &DAT_00004659;
    puVar3 = &DAT_fff8074f;
    for (iVar4 = 0x105; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_00004760 = 0;
    _DAT_0000475e = 0x8043;
  }
  FUN_fffb06e5();
  FUN_fffb0a28();
  FUN_fffb0a7c();
  FUN_fffb0a8f();
  FUN_fffb10a4();
  puVar1 = (undefined4 *)&DAT_00009898;
  for (iVar4 = 0x192; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  puVar2 = &DAT_00009c69;
  puVar3 = &DAT_fff80d82;
  for (iVar4 = 0xa0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_00009c35;
  puVar3 = &DAT_fff80e22;
  for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb1168();
  DAT_00009c65 = 0;
  _DAT_00009c61 = 0;
  _DAT_00009c5d = 0x1000000;
  puVar1 = (undefined4 *)&DAT_00009dbe;
  for (iVar4 = 200; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  puVar2 = &DAT_00009dbe;
  puVar3 = &DAT_fff80fc6;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_00009c17;
  puVar3 = &DAT_fff80fd6;
  for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fffb0636 @ fffb0636 (4 bytes)

void FUN_fffb0636(void)

{
  FUN_fffb0a8f();
  return;
}


// ===== FUN_fffb063a @ fffb063a (4 bytes)

void FUN_fffb063a(void)

{
  FUN_fffb1168();
  return;
}


// ===== FUN_fffb063e @ fffb063e (19 bytes)

void FUN_fffb063e(undefined2 param_1,undefined4 param_2,undefined2 param_3)

{
  eeprom_read(param_1,param_2,param_3);
  return;
}


// ===== FUN_fffb0651 @ fffb0651 (19 bytes)

void FUN_fffb0651(undefined2 param_1,undefined4 param_2,undefined2 param_3)

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


// ===== FUN_fffb06e5 @ fffb06e5 (148 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb06e5(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  sVar1 = FUN_fffb3b33();
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
  
  sVar1 = FUN_fffb3b33();
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


// ===== FUN_fffb0a28 @ fffb0a28 (84 bytes)

void FUN_fffb0a28(void)

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


// ===== FUN_fffb0a7c @ fffb0a7c (19 bytes)

void FUN_fffb0a7c(void)

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


// ===== FUN_fffb0a8f @ fffb0a8f (1557 bytes)

void FUN_fffb0a8f(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  byte bStack_b;
  
  sVar1 = FUN_fffb3b33();
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


// ===== FUN_fffb10a4 @ fffb10a4 (196 bytes)

void FUN_fffb10a4(void)

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


// ===== FUN_fffb1168 @ fffb1168 (43 bytes)

void FUN_fffb1168(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_fffb1193();
  FUN_fffb11f0();
  FUN_fffb120d();
  FUN_fffb12e6();
  FUN_fffb1303();
  FUN_fffb1325();
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


// ===== FUN_fffb1193 @ fffb1193 (93 bytes)

void FUN_fffb1193(void)

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


// ===== FUN_fffb11f0 @ fffb11f0 (29 bytes)

void FUN_fffb11f0(void)

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


// ===== FUN_fffb120d @ fffb120d (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb12c1) */
/* WARNING: Removing unreachable block (ram,0xfffb12e3) */
/* WARNING: Removing unreachable block (ram,0xfffb12c9) */
/* WARNING: Removing unreachable block (ram,0xfffb12d6) */

undefined1 * FUN_fffb120d(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  sVar1 = FUN_fffb3b33();
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

