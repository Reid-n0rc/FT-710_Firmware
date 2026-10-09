// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffa2ff7 @ fffa2ff7 (140 bytes)

undefined1 FUN_fffa2ff7(char param_1,char param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  while( true ) {
    while (param_1 != 'r') {
      if (DAT_00001c8b != '\x01') {
        return local_9;
      }
      iVar1 = FUN_fffa3083(0x77);
      if (iVar1 == 1) {
        if (param_2 == '\x01') {
          DAT_0001b784 = 0xffff;
        }
        FUN_fffa2c9f();
        local_9 = 1;
      }
    }
    if (DAT_00001c8c != '\x01') break;
    iVar1 = FUN_fffa3083(0x72);
    if (iVar1 == 1) {
      DAT_0001b786 = FUN_fffb2f9e();
      if (param_2 == '\x01') {
        DAT_0001b784 = 0xffff;
      }
      FUN_fffa2c9f();
      return 1;
    }
  }
  return local_9;
}


// ===== FUN_fffa3083 @ fffa3083 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa30f6) */

undefined1 FUN_fffa3083(char param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_e;
  
  local_e = 0;
  iVar1 = FUN_fffb1b06();
  if (iVar1 == 1) {
    uVar2 = FUN_fffb1b1f();
    *param_2 = uVar2;
    DAT_00001c8b = 0;
    DAT_00001c8c = 0;
    if (param_1 == 'r') {
      iVar1 = FUN_fffa31db((char *)*param_2,5);
      if (iVar1 == 1) {
        local_e = 1;
      }
    }
    else if (*(char *)*param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    iVar1 = FUN_fffb23f3(2);
    if (iVar1 == 1) {
      DAT_00001c8b = 0;
      DAT_00001c8c = 0;
    }
  }
  return local_e;
}


// ===== FUN_fffa30f9 @ fffa30f9 (181 bytes)

void FUN_fffa30f9(char param_1)

{
  undefined1 uVar1;
  byte local_2;
  
  DAT_00001c7f = param_1;
  FUN_fffb2ee7(0x1c80,DAT_0001b784);
  local_2 = 5;
  if (param_1 == 'w') {
    FUN_fffb2ee7(0x1c84,DAT_0001b786);
    local_2 = 9;
    DAT_00001c8b = 1;
  }
  else {
    DAT_00001c8c = 1;
  }
  uVar1 = FUN_fffa31ae(&DAT_00001c7f,local_2);
  FUN_fffb2eb7(&DAT_00001c7f + local_2,uVar1);
  (&DAT_00001c7f)[(byte)(local_2 + 2)] = 0xd;
  sdr_send_cmd(&DAT_00001c7f,local_2 + 3);
  FUN_fffb237a(2,6);
  return;
}


// ===== FUN_fffa31ae @ fffa31ae (45 bytes)

char FUN_fffa31ae(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== FUN_fffa31db @ fffa31db (75 bytes)

undefined1 FUN_fffa31db(int param_1,byte param_2)

{
  undefined1 uVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uVar1 = FUN_fffa31ae(param_1,param_2);
  FUN_fffb2eb7(&cStack_8,uVar1);
  if ((cStack_8 == *(char *)((uint)local_5 + local_4)) &&
     (cStack_7 == *(char *)(local_4 + (uint)local_5 + 1))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffa3226 @ fffa3226 (598 bytes)

void FUN_fffa3226(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 auStack_10 [4];
  undefined1 uStack_c;
  char acStack_b [11];
  
  DAT_00001c8d = 0;
  FUN_fffb7080(0);
  FUN_fffb7051(0);
  FUN_fffb7067(0);
  FUN_fffb237a(0x1e,100);
  do {
    iVar2 = FUN_fffb23f3(0x1e);
  } while (iVar2 != 1);
  FUN_fffb7051(1);
  FUN_fffb237a(0x1e,2000);
  do {
    iVar2 = FUN_fffb23f3(0x1e);
  } while (iVar2 != 1);
  DAT_0001b784 = 0x37;
  DAT_0001b786 = 0xbcc5;
  FUN_fffa30f9(0x77);
  iVar2 = FUN_fffa2ff7(0x77,0);
  if (iVar2 == 1) {
    uStack_12 = 6;
    FUN_fffb175b(&uStack_12,1);
    while( true ) {
      do {
        do {
          FUN_fffb3e6a();
          iVar2 = FUN_fffb171e();
        } while (iVar2 != 1);
        pcVar3 = (char *)FUN_fffb174f();
        pcVar4 = acStack_b;
        for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pcVar4 = *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        }
        FUN_fffb172d();
      } while (acStack_b[0] == '\x06');
      if ((acStack_b[0] == -0xf) && (acStack_b[1] == -0x7f)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      if ((acStack_b[0] == -3) && (acStack_b[1] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0001b784 = FUN_fffb2f9e();
        DAT_0001b786 = FUN_fffb2f9e();
        FUN_fffa30f9(0x77);
        iVar2 = FUN_fffa2ff7(0x77,0);
        if (iVar2 == 1) {
          uStack_12 = 6;
          FUN_fffb175b(&uStack_12,1);
        }
        else {
          uStack_12 = 0x15;
          FUN_fffb175b(&uStack_12,1);
        }
      }
      else {
        if ((acStack_b[0] == -2) && (acStack_b[1] == '\0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_12 = 6;
          FUN_fffb175b(&uStack_12,1);
          DAT_0001b784 = FUN_fffb2f9e();
          FUN_fffa30f9(0x72);
          iVar2 = FUN_fffa2ff7(0x72,0);
          if (iVar2 == 1) {
            uStack_12 = 0x7d;
            uStack_11 = 0;
            if (DAT_0001b784 == 0x32) {
              FUN_fffb2ee7(auStack_10,DAT_0001b77c);
              uStack_c = FUN_fffa31ae(&uStack_12,6);
              FUN_fffb175b(&uStack_12,7);
            }
            else if (DAT_0001b784 == 0x33) {
              FUN_fffb2ee7(auStack_10,DAT_0001b77e);
              uStack_c = FUN_fffa31ae(&uStack_12,6);
              FUN_fffb175b(&uStack_12,7);
            }
            else {
              uStack_12 = 0x15;
              FUN_fffb175b(&uStack_12,1);
            }
          }
          else {
            uStack_12 = 0x15;
            FUN_fffb175b(&uStack_12,1);
          }
        }
        else {
          uStack_12 = 0x15;
          FUN_fffb175b(&uStack_12,1);
        }
      }
    }
    uStack_12 = 6;
    FUN_fffb175b(&uStack_12,1);
    FUN_fffb7051(0);
    FUN_fffb7067(1);
    FUN_fffb237a(0x1e,100);
    do {
      iVar2 = FUN_fffb23f3(0x1e);
    } while (iVar2 != 1);
    FUN_fffb7051(1);
    FUN_fffb7080(1);
    return;
  }
  uStack_12 = 0x15;
  FUN_fffb175b(&uStack_12,1);
  return;
}


// ===== cat_parse @ fffa347c (630 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa350d) */
/* WARNING: Removing unreachable block (ram,0xfffa3588) */
/* WARNING: Removing unreachable block (ram,0xfffa365b) */
/* CAT command parser: looks up the 2-char mnemonic in cat_mnemonics (0xFFF805EC, 104 entries) then
   cat_ext_mnemonics (0xFFF806BC, 10 entries), calls cat_dispatch / cat_dispatch_ext */

void cat_parse(void)

{
  undefined2 uVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  uint *in_R15;
  byte bVar9;
  byte bStack_f;
  byte bStack_e;
  undefined2 uStack_d;
  char cStack_b;
  char cStack_a;
  char cStack_9;
  char *pcStack_8;
  char *pcStack_4;
  
  cStack_9 = FUN_fffb1c91();
  cStack_a = FUN_fffb1ca0();
  DAT_0000464a = '\0';
  bStack_f = 0xff;
  DAT_0001b788 = 0;
  if (DAT_00020b46 == '\x01') {
    DAT_0001b788 = 0;
    DAT_0000464a = 0;
    return;
  }
  if (cStack_9 == cStack_a) {
    pcStack_8 = (char *)FUN_fffb1d06();
    if (*pcStack_8 == '\x01') {
      cStack_b = pcStack_8[1];
      uStack_d = *(undefined2 *)(pcStack_8 + 4);
      for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
        FUN_fffb3168();
      }
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        puVar8 = (undefined4 *)((uint)bStack_e * 2);
        pcVar7 = (char *)(puVar8 + -0x1fe51);
        iVar6 = 2;
        pcVar5 = (char *)&uStack_d;
        do {
          if (iVar6 == 0) {
            bVar9 = 3;
            bVar4 = true;
            goto code_r0xfffa366d;
          }
          cVar2 = *pcVar5;
          cVar3 = *pcVar7;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
          iVar6 = iVar6 + -1;
        } while ((cVar2 != '\0') && (cVar2 == cVar3));
        bVar9 = -1 < (char)(cVar2 - cVar3);
        bVar4 = false;
code_r0xfffa366d:
        if ((bool)(bVar9 & 1)) {
          *puVar8 = 1;
        }
        if (!(bool)(bVar9 & 1) || bVar4) {
          *in_R15 = (uint)(!(bool)(bVar9 & 1) || bVar4);
        }
        if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 3) {
        cat_ext_E9();
      }
      if (DAT_0000464a != '\0') {
        FUN_fffb0166();
      }
      if (DAT_0001b788 != 0) {
        FUN_fffb1d12(cStack_b,&DAT_00001c8e,DAT_0001b788);
      }
      *pcStack_8 = '\0';
    }
  }
  else {
    FUN_fffb263d();
    pcStack_4 = (char *)FUN_fffb1cd2();
    cStack_b = *pcStack_4;
    iVar6 = sci_tx_end(cStack_b);
    if (iVar6 == 0) {
      FUN_fffb1caf();
      return;
    }
    uStack_d = *(undefined2 *)(pcStack_4 + 4);
    uVar1 = *(undefined2 *)(pcStack_4 + 2);
    DAT_0000464c = cStack_b;
    for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
      FUN_fffb3168();
    }
    for (bStack_e = 0; bStack_e < 0x68; bStack_e = bStack_e + 1) {
      puVar8 = (undefined4 *)((uint)bStack_e * 2);
      pcVar7 = (char *)(puVar8 + -0x1fe85);
      iVar6 = 2;
      pcVar5 = (char *)&uStack_d;
      do {
        if (iVar6 == 0) {
          bVar9 = 3;
          bVar4 = true;
          goto code_r0xfffa351f;
        }
        cVar2 = *pcVar5;
        cVar3 = *pcVar7;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + -1;
      } while ((cVar2 != '\0') && (cVar2 == cVar3));
      bVar9 = -1 < (char)(cVar2 - cVar3);
      bVar4 = false;
code_r0xfffa351f:
      if ((bool)(bVar9 & 1)) {
        *puVar8 = 1;
      }
      if (!(bool)(bVar9 & 1) || bVar4) {
        *in_R15 = (uint)(!(bool)(bVar9 & 1) || bVar4);
      }
      if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
        bStack_f = bStack_e;
        break;
      }
    }
    if (DAT_00020b3a == '\0') {
      if ((bStack_f == 0x47) && (pcStack_4[6] == '1')) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (!bVar4) {
        return;
      }
    }
    if (bStack_f == 0xff) {
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        puVar8 = (undefined4 *)((uint)bStack_e * 2);
        pcVar7 = (char *)(puVar8 + -0x1fe51);
        iVar6 = 2;
        pcVar5 = (char *)&uStack_d;
        do {
          if (iVar6 == 0) {
            bVar9 = 3;
            bVar4 = true;
            goto code_r0xfffa359a;
          }
          cVar2 = *pcVar5;
          cVar3 = *pcVar7;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
          iVar6 = iVar6 + -1;
        } while ((cVar2 != '\0') && (cVar2 == cVar3));
        bVar9 = -1 < (char)(cVar2 - cVar3);
        bVar4 = false;
code_r0xfffa359a:
        if ((bool)(bVar9 & 1)) {
          *puVar8 = 1;
        }
        if (!(bool)(bVar9 & 1) || bVar4) {
          *in_R15 = (uint)(!(bool)(bVar9 & 1) || bVar4);
        }
        if (puVar8 == (undefined4 *)((uint)in_R15 & 0xff)) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 0xff) {
        DAT_0000464a = '\x01';
      }
      else if (bStack_f == 0) {
        cat_ext_SP(pcStack_4);
      }
      else {
        cat_dispatch_ext(pcStack_4,bStack_f,uVar1);
      }
    }
    else {
      cat_dispatch(pcStack_4,bStack_f,uVar1);
    }
    if (DAT_0000464a == '\0') {
      if (DAT_00020b8a == '\x01') {
        FUN_fffbe232();
      }
    }
    else {
      FUN_fffb0166();
    }
    if (DAT_0001b788 != 0) {
      FUN_fffb1d12(cStack_b,&DAT_00001c8e,DAT_0001b788);
    }
  }
  if ((DAT_0000464b == '\x01') && (iVar6 = FUN_fffb23f3(0x32), iVar6 == 1)) {
    FUN_fffbff93();
    DAT_0000464b = '\0';
  }
  FUN_fffdd797();
  return;
}


// ===== cat_ext_SP @ fffa36f2 (824 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Extended command SP (index 0 of 0xFFF806BC table) */

void cat_ext_SP(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 6);
  if ((cVar1 == 'S') || (cVar1 == 's')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa4e31(param_1 + 4,1);
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa4e31(param_1 + 4,0);
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'D') || (cVar1 == 'd')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa4e8f(param_1 + 4,1);
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa4e8f(param_1 + 4,0);
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'I') || (cVar1 == 'i')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if ((*(char *)(param_1 + 7) == 'R') || (*(char *)(param_1 + 7) == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa4eed();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'W') || (cVar1 == 'R')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    iVar3 = FUN_fffb0182(param_1 + 4,*(undefined2 *)(*(ushort *)(param_1 + 2) - 2));
    if (iVar3 != 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c92 = *(undefined1 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (cVar1 == 'W') {
      FUN_fffa520b(param_1 + 4,1);
      return;
    }
    FUN_fffa520b(param_1 + 4,0);
    return;
  }
  if ((cVar1 == 'M') || (cVar1 == 'm')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    iVar3 = FUN_fffb0182(param_1 + 4,*(undefined2 *)(*(ushort *)(param_1 + 2) - 2));
    if (iVar3 != 1) {
      DAT_0000464a = 1;
      return;
    }
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    FUN_fffa5284();
    return;
  }
  if ((cVar1 == 'N') || (cVar1 == 'n')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa50f9(param_1 + 4,1,*(undefined2 *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'S') || (cVar1 == 's')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa50f9(param_1 + 4,1,*(undefined2 *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      FUN_fffa50f9(param_1 + 4,0,*(undefined2 *)(param_1 + 2));
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'A') || (cVar1 == 'a')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return;
  }
  iVar3 = FUN_fffb0182(param_1 + 4,*(undefined2 *)(*(ushort *)(param_1 + 2) - 2));
  if (iVar3 != 1) {
    DAT_0000464a = 1;
    return;
  }
  if ((*(char *)(param_1 + 7) == 'W') || (*(char *)(param_1 + 7) == 'w')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'e')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar2 = true;
      goto LAB_fffa3a12;
    }
  }
  bVar2 = false;
LAB_fffa3a12:
  if (bVar2) {
    FUN_fffb0532();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_dispatch_ext @ fffa3a2a (324 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatch for the extended/hidden mnemonic table (EO E8 FD PE ZZ VE JP; E9/KT no case here) */

void cat_dispatch_ext(int param_1,char param_2,short param_3)

{
  undefined1 uVar1;
  
  if (param_2 == '\x01') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_EO(param_1 + 4,1);
    return;
  }
  if (param_2 == '\t') {
    _DAT_00001c92 = *(undefined2 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 7) {
      cat_ext_JP(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_JP(param_1 + 4,1);
    return;
  }
  if (param_2 == '\x04') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_ext_FD(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_FD(param_1 + 4,1);
    return;
  }
  if (param_2 != '\x06') {
    if (param_2 == '\a') {
      cat_ext_ZZ(param_1 + 4);
      return;
    }
    if (param_2 == '\b') {
      _DAT_00001c8e =
           CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4)
                   );
      uVar1 = FUN_fffb2f07(*(undefined1 *)(param_1 + 6));
      cat_ext_VE(uVar1);
      return;
    }
    if (param_2 != '\x02') {
      return;
    }
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    cat_ext_E8();
    return;
  }
  _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
  _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
  if (param_3 == 6) {
    cat_ext_PE(param_1 + 4,0);
    return;
  }
  if (param_3 != 9) {
    DAT_0000464a = 1;
    return;
  }
  cat_ext_PE(param_1 + 4,1);
  return;
}


// ===== cat_dispatch @ fffa3b6e (4803 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAT dispatch switch: index -> case via 16-bit offset table 0xFFF8F014 (BRA.L at 0xFFFA3B8A); each
   case checks parameter length (query vs set) then calls cat_XX */

void cat_dispatch(int param_1,char param_2,ushort param_3)

{
  bool bVar1;
  undefined1 uVar2;
  
  uVar2 = DAT_00001c91;
  switch(param_2) {
  case '\0':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AB();
    return;
  case '\x01':
    break;
  case '\x02':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AG(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AG(param_1 + 4,1);
    return;
  case '\x03':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AI(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_AI(param_1 + 4,1);
    return;
  case '\x04':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AM();
    return;
  case '\x05':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AO(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AO(param_1 + 4,1);
    return;
  case '\x06':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AS(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AS(param_1 + 4,1);
    return;
  case '\a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AV(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AV(param_1 + 4,1);
    return;
  case '\b':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BA();
    return;
  case '\t':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_BC(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BC(param_1 + 4,1);
    return;
  case '\n':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BD(param_1 + 4);
    return;
  case '\v':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_BI(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BI(param_1 + 4,1);
    return;
  case '\f':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BM();
    return;
  case '\r':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_BP(param_1 + 4,0);
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_BP(param_1 + 4,1);
    return;
  case '\x0e':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BS(param_1 + 4);
    return;
  case '\x0f':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BU(param_1 + 4);
    return;
  default:
    DAT_0000464a = 1;
    return;
  case '\x11':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_CF(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_CF(param_1 + 4,1);
    return;
  case '\x12':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CH(param_1 + 4);
    return;
  case '\x13':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_CN(param_1 + 4,0);
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_CN(param_1 + 4,1);
    return;
  case '\x14':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 5) {
      cat_CO(param_1 + 4,0);
      return;
    }
    if (param_3 != 9) {
      DAT_0000464a = 1;
      return;
    }
    cat_CO(param_1 + 4,1);
    return;
  case '\x15':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_CS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CS(param_1 + 4,1);
    return;
  case '\x16':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_CT(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_CT(param_1 + 4,1);
    return;
  case '\x17':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_DA(param_1 + 4,0);
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_DA(param_1 + 4,1);
    return;
  case '\x18':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_DN();
    return;
  case '\x19':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_DT(param_1 + 4,0);
      return;
    }
    if ((param_3 == 10) || (param_3 == 0xc)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_DT(param_1 + 4,1);
    return;
  case '\x1c':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_EM(param_1 + 4,0);
      return;
    }
    if ((param_3 < 6) || (0x37 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_EM(param_1 + 4,1);
    return;
  case '\x1d':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_EN(param_1 + 4);
    return;
  case '\x1f':
    _DAT_00001c92 = *(undefined4 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 9) {
      cat_EX(param_1 + 4,0,9);
      return;
    }
    if (8 < param_3) {
      cat_EX(param_1 + 4,1,param_3);
      return;
    }
    DAT_0000464a = 1;
    return;
  case ' ':
  case '!':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FA_FB(param_1 + 4,0,param_2 != ' ');
      return;
    }
    if (param_3 != 0xc) {
      DAT_0000464a = 1;
      return;
    }
    cat_FA_FB(param_1 + 4,1,param_2 != ' ');
    return;
  case '\"':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FN(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FN(param_1 + 4,1);
    return;
  case '#':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FS(param_1 + 4,1);
    return;
  case '$':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FT(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FT(param_1 + 4,1);
    return;
  case '%':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_GT(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_GT(param_1 + 4,1);
    return;
  case '&':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_GP(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_GP(param_1 + 4,1);
    return;
  case '\'':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_ID();
    return;
  case '(':
  case '@':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_IF_OI(param_2 != '(');
    return;
  case ')':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_IS(param_1 + 4,0);
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_IS(param_1 + 4,1);
    return;
  case '*':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_KM(param_1 + 4,0,4);
      return;
    }
    if ((param_3 < 5) || (0x36 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_KM(param_1 + 4,1,param_3);
    return;
  case '+':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KP(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KP(param_1 + 4,1);
    return;
  case ',':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KR(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_KR(param_1 + 4,1);
    return;
  case '-':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KS(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_KS(param_1 + 4,1);
    return;
  case '.':
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KY(param_1 + 4);
    return;
  case '/':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_LK(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_LK(param_1 + 4,1);
    return;
  case '0':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_LM(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_LM(param_1 + 4,1);
    return;
  case '1':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MA();
    return;
  case '2':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MB();
    return;
  case '3':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MC(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MC(param_1 + 4,1);
    return;
  case '4':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_MD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MD(param_1 + 4,1);
    return;
  case '5':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MG(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MG(param_1 + 4,1);
    return;
  case '6':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_ML(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_ML(param_1 + 4,1);
    return;
  case '7':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MR(param_1 + 4,0);
    return;
  case '8':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MS(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MS(param_1 + 4,1);
    return;
  case '9':
    _DAT_00001c92 = CONCAT31((undefined3)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_MT(param_1 + 4,0,6);
      return;
    }
    if ((param_3 < 8) || (0x13 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_MT(param_1 + 4,1,param_3);
    return;
  case ':':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 0x1c) {
      DAT_0000464a = 1;
      return;
    }
    cat_MW(param_1 + 4,1);
    return;
  case ';':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_MX(param_1 + 4,1);
    return;
  case '<':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NA(param_1 + 4,1);
    return;
  case '=':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NB(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NB(param_1 + 4,1);
    return;
  case '>':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NL(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_NL(param_1 + 4,1);
    return;
  case '?':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NR(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NR(param_1 + 4,1);
    return;
  case 'A':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_OS(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_OS(param_1 + 4,1);
    return;
  case 'B':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PA(param_1 + 4,1);
    return;
  case 'C':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PB(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PB(param_1 + 4,1);
    return;
  case 'D':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PC(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PC(param_1 + 4,1);
    return;
  case 'E':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PL(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PL(param_1 + 4,1);
    return;
  case 'F':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PR(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PR(param_1 + 4,1);
    return;
  case 'G':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_PS(param_1 + 4,1);
    return;
  case 'H':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QI();
    return;
  case 'I':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QR();
    return;
  case 'J':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QS();
    return;
  case 'K':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RA(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_RA(param_1 + 4,1);
    return;
  case 'N':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RG(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_RG(param_1 + 4,1);
    return;
  case 'O':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RI(param_1 + 4);
    return;
  case 'P':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RL(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_RL(param_1 + 4,1);
    return;
  case 'Q':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RM(param_1 + 4);
    return;
  case 'U':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SC(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SC(param_1 + 4,1);
    return;
  case 'V':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SD(param_1 + 4,1);
    return;
  case 'W':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SF(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SF(param_1 + 4,1);
    return;
  case 'X':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SH(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SH(param_1 + 4,1);
    return;
  case 'Y':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SM(param_1 + 4);
    return;
  case 'Z':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SQ(param_1 + 4,0);
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SQ(param_1 + 4,1);
    return;
  case '[':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_SS(param_1 + 4,0);
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_SS(param_1 + 4,1);
    return;
  case '\\':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_ST(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ST(param_1 + 4,1);
    return;
  case ']':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_SV(param_1 + 4,1);
    return;
  case '^':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TS(param_1 + 4,1);
    return;
  case '_':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TX(param_1 + 4,1);
    return;
  case '`':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_UP();
    return;
  case 'a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VD(param_1 + 4,0);
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_VD(param_1 + 4,1);
    return;
  case 'b':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VG(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_VG(param_1 + 4,1);
    return;
  case 'c':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if ((param_3 == 4) || (param_3 == 3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (param_3 == 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_VM(param_1 + 4,param_3);
    return;
  case 'd':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VS(param_1 + 4,1);
    return;
  case 'e':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VX(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VX(param_1 + 4,1);
    return;
  case 'g':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ZI(param_1 + 4);
    return;
  }
  _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
  if (param_3 == 3) {
    cat_AC(param_1 + 4,0);
    return;
  }
  if (param_3 != 6) {
    DAT_0000464a = 1;
    return;
  }
  cat_AC(param_1 + 4,1);
  return;
}


// ===== FUN_fffa4e31 @ fffa4e31 (94 bytes)

void FUN_fffa4e31(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined2 uStack_a;
  undefined2 uStack_8;
  char local_5;
  undefined4 local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = FUN_fffb2f9e();
  uStack_a = FUN_fffb2f9e();
  iVar1 = FUN_fffa1485(uStack_8,&uStack_a,local_5);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  FUN_fffb2ee7(&DAT_00001c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== FUN_fffa4e8f @ fffa4e8f (94 bytes)

void FUN_fffa4e8f(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined2 uStack_a;
  undefined2 uStack_8;
  char local_5;
  undefined4 local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = FUN_fffb2f9e();
  uStack_a = FUN_fffb2f9e();
  iVar1 = FUN_fff9d8a4(uStack_8,&uStack_a,local_5);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  FUN_fffb2ee7(&DAT_00001c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== FUN_fffa4eed @ fffa4eed (524 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffa4eed(void)

{
  undefined1 uStack_6;
  undefined2 uStack_5;
  undefined1 uStack_3;
  undefined2 local_2;
  
  local_2 = 0;
  FUN_fffb2ee7(&uStack_6,0);
  DAT_00001c93._1_1_ = uStack_3;
  _DAT_00001c92 = uStack_5;
  local_2 = DAT_00020b04;
  FUN_fffb2ee7(&uStack_6,DAT_00020b04);
  DAT_00001c97 = uStack_3;
  DAT_00001c93._2_2_ = uStack_5;
  local_2 = DAT_00020b06;
  FUN_fffb2ee7(&uStack_6,DAT_00020b06);
  uRam00001c9a = uStack_3;
  _DAT_00001c98 = uStack_5;
  local_2 = DAT_00020b08;
  FUN_fffb2ee7(&uStack_6,DAT_00020b08);
  DAT_00001c9d = uStack_3;
  uRam00001c9b = uStack_5;
  local_2 = 0;
  FUN_fffb2ee7(&uStack_6,0);
  DAT_00001ca0 = uStack_3;
  uRam00001c9e = uStack_5;
  local_2 = DAT_00020b0c;
  FUN_fffb2ee7(&uStack_6,DAT_00020b0c);
  DAT_00001ca3 = uStack_3;
  _DAT_00001ca1 = uStack_5;
  local_2 = 0;
  FUN_fffb2ee7(&uStack_6,0);
  DAT_00001ca6 = uStack_3;
  _DAT_00001ca4 = uStack_5;
  local_2 = DAT_00020b0e;
  FUN_fffb2ee7(&uStack_6,DAT_00020b0e);
  DAT_00001ca9 = uStack_3;
  _DAT_00001ca7 = uStack_5;
  local_2 = DAT_00020b14;
  FUN_fffb2ee7(&uStack_6,DAT_00020b14);
  uRam00001cac = uStack_3;
  uRam00001caa = uStack_5;
  local_2 = DAT_00020b16;
  FUN_fffb2ee7(&uStack_6,DAT_00020b16);
  uRam00001caf = uStack_3;
  uRam00001cad = uStack_5;
  local_2 = DAT_00020b10;
  FUN_fffb2ee7(&uStack_6,DAT_00020b10);
  uRam00001cb2 = uStack_3;
  uRam00001cb0 = uStack_5;
  local_2 = DAT_00020b12;
  FUN_fffb2ee7(&uStack_6,DAT_00020b12);
  uRam00001cb5 = uStack_3;
  uRam00001cb3 = uStack_5;
  uRam00001cb6 = 0x3b;
  DAT_0001b788 = 0x29;
  return;
}


// ===== FUN_fffa50f9 @ fffa50f9 (274 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa51a6) */
/* WARNING: Removing unreachable block (ram,0xfffa511d) */
/* WARNING: Removing unreachable block (ram,0xfffa5208) */
/* WARNING: Removing unreachable block (ram,0xfffa512e) */
/* WARNING: Removing unreachable block (ram,0xfffa5144) */
/* WARNING: Removing unreachable block (ram,0xfffa5158) */
/* WARNING: Removing unreachable block (ram,0xfffa5205) */
/* WARNING: Removing unreachable block (ram,0xfffa51d1) */

undefined2 * FUN_fffa50f9(int param_1,char param_2,ushort param_3)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 *puVar4;
  
  puVar4 = (undefined2 *)FUN_fffb0182(param_1,*(undefined2 *)(param_3 - 2));
  if (puVar4 != (undefined2 *)0x1) {
    DAT_0000464a = 1;
    return puVar4;
  }
  uVar3 = CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  if (uVar3 == 0) {
    DAT_0000464a = 1;
    return (undefined2 *)0x0;
  }
  if ((undefined2 *)0x105 < (undefined2 *)(uint)uVar3) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)uVar3;
  }
  uVar3 = uVar3 - 1;
  if (param_2 != '\0') {
    if ((*(char *)(param_1 + 3) == 'W') || (*(char *)(param_1 + 3) == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar1 = *(byte *)(param_1 + 6);
      (&DAT_00004659)[uVar3] = bVar1;
      return (undefined2 *)(uint)bVar1;
    }
    if ((*(char *)(param_1 + 3) == 'S') || (*(char *)(param_1 + 3) == 's')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      return (undefined2 *)0x0;
    }
    puVar4 = (undefined2 *)FUN_fffb237a(0x32,500);
    DAT_0000464b = 1;
    return puVar4;
  }
  DAT_00020ce2 = uVar3;
  FUN_fffbb567();
  DAT_00001c91 = (&DAT_00004659)[uVar3];
  DAT_00001c92 = FUN_fffb01af(&DAT_00001c8e,4);
  DAT_00001c93._0_1_ = 0x3b;
  DAT_0001b788 = 6;
  return &DAT_00001c8e;
}


// ===== FUN_fffa520b @ fffa520b (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5268) */
/* WARNING: Removing unreachable block (ram,0xfffa5217) */
/* WARNING: Removing unreachable block (ram,0xfffa5281) */

undefined2 * FUN_fffa520b(int param_1,char param_2)

{
  byte local_d;
  ushort local_c;
  char local_9;
  int local_8;
  
  local_c = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  local_d = *(byte *)(param_1 + 5);
  local_9 = param_2;
  local_8 = param_1;
  if (param_2 != '\0') {
    FUN_fffb0651(local_c,&local_d,1);
    (&DAT_0000464f)[local_c] = local_d;
    return (undefined2 *)(uint)local_d;
  }
  FUN_fffb063e(local_c,&local_d,1);
  DAT_00001c93._0_1_ = local_d;
  DAT_00001c93._1_1_ = FUN_fffb01af(&DAT_00001c8e,6);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return &DAT_00001c8e;
}


// ===== FUN_fffa5284 @ fffa5284 (288 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffa5284) */
/* WARNING: Removing unreachable block (ram,0xfffa53a1) */

undefined4 FUN_fffa5284(void)

{
  uint uVar1;
  undefined1 uVar2;
  
  DAT_00001c91 = FUN_fffb6ea7();
  DAT_00001c92 = 0;
  DAT_00001c93._0_1_ = FUN_fffb6e6a();
  DAT_00001c93._1_1_ = FUN_fffb6e30();
  DAT_00001c93._2_1_ = FUN_fffb6e98();
  DAT_00001c93._3_1_ = FUN_fffb6e21();
  DAT_00001c97 = FUN_fffb6e03();
  DAT_00001c98 = FUN_fffb6e12();
  DAT_00001c99 = 0;
  uRam00001c9a = 0;
  uRam00001c9b = 0;
  uVar1 = (uint)bRam0000000e;
  uVar2 = FUN_fffb01af(&DAT_00001c8e,uVar1);
  *(undefined1 *)((int)&DAT_00001c8e + uVar1) = uVar2;
  DAT_00001c9d = 0x3b;
  DAT_0001b788 = 0x10;
  return 0x10;
}


// ===== cat_ext_E8 @ fffa53a4 (271 bytes)

void cat_ext_E8(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  char cStack_a;
  ushort uStack_8;
  
  cVar1 = FUN_fffb2718();
  cStack_a = '\0';
  DAT_00001c91 = cVar1 + '\a';
  DAT_00001c92 = cVar1 + -0x70;
  puVar3 = &DAT_000060c9;
  puVar2 = (undefined1 *)((int)&DAT_00001c93 + 2);
  DAT_00001c90 = cVar1;
  DAT_00001c93._0_1_ = cVar1;
  DAT_00001c93._1_1_ = cVar1;
  for (puVar4 = &DAT_000029a9; puVar4 != (undefined *)0x0; puVar4 = puVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uStack_8 = 0; uStack_8 < 0x29a9; uStack_8 = uStack_8 + 1) {
    cStack_a = *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cStack_a;
    *(char *)((int)&DAT_00001c93 + uStack_8 + 2) =
         *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cVar1;
  }
  cRam0000463e = cStack_a + cVar1;
  uRam0000463f = 0x3b;
  DAT_0001b788 = 0x29b2;
  return;
}


// ===== cat_ext_VE @ fffa54b3 (184 bytes)

void cat_ext_VE(char param_1)

{
  undefined4 uStack_8;
  
  if (param_1 == '\0') {
    uStack_8 = FUN_fff94bcd();
  }
  else if (param_1 == '\x01') {
    uStack_8 = FUN_fff94bf1();
  }
  else if (param_1 == '\x02') {
    uStack_8 = FUN_fff94c4b();
  }
  else {
    if (param_1 != '\x03') {
      DAT_0000464a = 1;
      return;
    }
    uStack_8 = FUN_fff94c2d();
  }
  DAT_00001c91 = *(undefined1 *)(uStack_8 + 1);
  DAT_00001c92 = *(undefined1 *)(uStack_8 + 2);
  DAT_00001c93._0_1_ = *(undefined1 *)(uStack_8 + 4);
  DAT_00001c93._1_1_ = *(undefined1 *)(uStack_8 + 5);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return;
}


// ===== cat_ext_JP @ fffa556b (822 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5810) */

void cat_ext_JP(undefined4 param_1,char param_2)

{
  bool bVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  short sStack_e;
  undefined *local_c;
  char local_5;
  undefined4 local_4;
  
  local_c = &DAT_0000464f;
  local_5 = param_2;
  local_4 = param_1;
  sStack_e = FUN_fffb2f9e();
  if (sStack_e != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    bStack_f = FUN_fffb2f79();
    bStack_10 = FUN_fffb2f79();
    bStack_11 = FUN_fffb2f79();
    bStack_12 = FUN_fffb2f79();
    bStack_11 = ~bStack_11;
    bStack_12 = ~bStack_12;
    if ((bStack_f == bStack_11) && (bStack_10 == bStack_12)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    sStack_e = CONCAT11(bStack_f,bStack_10);
    if (sStack_e == 0x306f) {
      sStack_e = -0x2cd3;
    }
    else if (sStack_e == -0x4a59) {
      sStack_e = -0x567d;
    }
    else if (sStack_e == -0x6309) {
      sStack_e = 0x7753;
    }
    else if (sStack_e == -0x5b3b) {
      sStack_e = -0x26b0;
    }
    else if (sStack_e == 0x50e2) {
      sStack_e = 0x315b;
    }
    *local_c = DAT_00020bb1;
    local_c[1] = DAT_00020bb2;
    local_c[2] = DAT_00020bb3;
    local_c[3] = DAT_00020bb4;
    local_c[4] = DAT_00020bb5;
    FUN_fffb3b5d(sStack_e);
    return;
  }
  sStack_e = FUN_fffb3b33();
  bStack_f = (byte)((ushort)sStack_e >> 8);
  bStack_10 = (byte)sStack_e;
  FUN_fffb2eb7(&uStack_14,bStack_f);
  DAT_00001c93._1_1_ = uStack_14;
  DAT_00001c93._2_1_ = uStack_13;
  FUN_fffb2eb7(&uStack_14,bStack_10);
  DAT_00001c93._3_1_ = uStack_14;
  DAT_00001c97 = uStack_13;
  FUN_fffb2eb7(&uStack_14,*(undefined1 *)~(uint)bStack_f);
  DAT_00001c98 = uStack_14;
  DAT_00001c99 = uStack_13;
  FUN_fffb2eb7(&uStack_14,*(undefined1 *)~(uint)bStack_10);
  uRam00001c9a = uStack_14;
  uRam00001c9b = uStack_13;
  FUN_fffb2eb7(&uStack_14,*local_c);
  DAT_00001c9c = uStack_14;
  DAT_00001c9d = uStack_13;
  FUN_fffb2eb7(&uStack_14,local_c[1]);
  uRam00001c9e = uStack_14;
  uRam00001c9f = uStack_13;
  FUN_fffb2eb7(&uStack_14,local_c[2]);
  DAT_00001ca0 = uStack_14;
  DAT_00001ca1 = uStack_13;
  FUN_fffb2eb7(&uStack_14,local_c[3]);
  DAT_00001ca2 = uStack_14;
  DAT_00001ca3 = uStack_13;
  FUN_fffb2eb7(&uStack_14,local_c[4]);
  DAT_00001ca4 = uStack_14;
  DAT_00001ca5 = uStack_13;
  DAT_00001ca6 = 0x3b;
  DAT_0001b788 = 0x19;
  return;
}


// ===== cat_ext_ZZ @ fffa58a1 (228 bytes)

void cat_ext_ZZ(int param_1)

{
  undefined2 uVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  char local_9;
  char cStack_8;
  byte local_7;
  
  uVar1 = *(undefined2 *)(param_1 + 2);
  for (local_7 = 0; local_7 < 2; local_7 = local_7 + 1) {
    FUN_fffb3168();
  }
  local_9 = (char)uVar1;
  if ((local_9 == 'P') && (cStack_8 = (char)((ushort)uVar1 >> 8), cStack_8 == 'E')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    DAT_0000464a = 1;
    return;
  }
  sVar4 = FUN_fffb2f9e();
  if (sVar4 != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  cVar3 = FUN_fffb2f79();
  if (cVar3 != -0x67) {
    if (cVar3 == '\x01') {
      FUN_fffb0558(0);
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x11;
      return;
    }
    if (cVar3 == '\0') {
      DAT_00020bbe = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  FUN_fffb0558(1);
  FUN_fffb0532();
  FUN_fffb0544();
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== cat_ext_E9 @ fffa5985 (204 bytes)

/* Extended E9, reached only from the second input path in cat_parse */

void cat_ext_E9(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  char local_e;
  ushort local_c;
  
  bVar1 = *(byte *)(param_1 + 2);
  bVar2 = *(byte *)(param_1 + 3);
  bVar3 = *(byte *)((uint)*(byte *)(param_1 + 4) - (uint)bVar1);
  local_e = '\0';
  for (local_c = 0; local_c < 0x29a9; local_c = local_c + 1) {
    *(byte *)(local_c + 7 + param_1) = *(char *)(local_c + 7 + param_1) - bVar1;
    local_e = *(char *)(local_c + 7 + param_1) + local_e;
  }
  if ((ushort)((ushort)bVar3 | ((ushort)bVar2 - (ushort)bVar1) * 0x100) == 0x790) {
    if (*(char *)((uint)(byte)(&DAT_000029b0)[param_1] - (uint)bVar1) == local_e) {
      puVar4 = &DAT_000060c9;
      puVar5 = (undefined1 *)(param_1 + 7);
      for (puVar6 = &DAT_000029a9; puVar6 != (undefined *)0x0; puVar6 = puVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_fffb0356();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ext_FD @ fffa5a51 (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5be8) */
/* WARNING: Removing unreachable block (ram,0xfffa5c39) */
/* WARNING: Removing unreachable block (ram,0xfffa5c76) */
/* WARNING: Removing unreachable block (ram,0xfffa5c51) */
/* WARNING: Removing unreachable block (ram,0xfffa5c81) */
/* WARNING: Removing unreachable block (ram,0xfffa5b46) */
/* WARNING: Removing unreachable block (ram,0xfffa5b0b) */
/* WARNING: Removing unreachable block (ram,0xfffa5ad6) */
/* WARNING: Removing unreachable block (ram,0xfffa5a94) */
/* WARNING: Removing unreachable block (ram,0xfffa5bb3) */
/* WARNING: Removing unreachable block (ram,0xfffa5c8d) */
/* WARNING: Removing unreachable block (ram,0xfffa5b7b) */
/* WARNING: Removing unreachable block (ram,0xfffa5bf4) */

undefined2 * cat_ext_FD(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined2 *puStack_1c;
  byte bStack_17;
  uint uStack_14;
  uint uStack_10;
  
  FUN_fffb357c(0,2);
  FUN_fffb33e5();
  bVar1 = *(byte *)(param_1 + 4);
  if ((*(char *)(param_1 + 2) == '0') && (*(char *)(param_1 + 3) == '0')) {
    puStack_1c = (undefined2 *)0x0;
  }
  else {
    puStack_1c = (undefined2 *)0x1;
  }
  if (puStack_1c != (undefined2 *)0x0) {
    DAT_0000464a = 1;
    return puStack_1c;
  }
  puVar5 = (undefined2 *)(uint)bVar1;
  if (param_2 != '\0') {
    if (puVar5 != (undefined2 *)0x32) {
      DAT_0000464a = 1;
      return puVar5;
    }
    uStack_10 = 0;
    uStack_14 = 100000000;
    bStack_17 = 5;
    while( true ) {
      if (0xd < bStack_17) {
        iVar4 = FUN_fffb3aa1(uStack_10);
        if (iVar4 != 0) {
          puVar5 = (undefined2 *)FUN_fffb4e18(2,uStack_10);
          return puVar5;
        }
        DAT_0000464a = 1;
        return (undefined2 *)0x0;
      }
      if ((*(byte *)((uint)bStack_17 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_17 + param_1))) {
        puStack_1c = (undefined2 *)0x1;
      }
      else {
        puStack_1c = (undefined2 *)0x0;
      }
      if (puStack_1c != (undefined2 *)0x0) break;
      uStack_10 = (*(byte *)((uint)bStack_17 + param_1) & 0xf) * uStack_14 + uStack_10;
      uStack_14 = uStack_14 / 10;
      bStack_17 = bStack_17 + 1;
    }
    DAT_0000464a = 1;
    return puStack_1c;
  }
  if (puVar5 == (undefined2 *)0x30) {
    uStack_10 = DAT_00020f5c;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      uVar3 = uStack_10;
      if (uStack_14 != 0) {
        uVar3 = uStack_10 / uStack_14;
      }
      uVar6 = uStack_10;
      if ((uStack_14 & 0xff) != 0) {
        uVar6 = uStack_10 / (uStack_14 & 0xff);
      }
      uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
      uStack_14 = uStack_14 / 10;
      uVar2 = FUN_fffb2e9c(uVar3 & 0xff);
      *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return &DAT_00001c8e;
  }
  if (bVar1 == 0x31) {
    uStack_10 = DAT_00020f60;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      uVar3 = uStack_10;
      if (uStack_14 != 0) {
        uVar3 = uStack_10 / uStack_14;
      }
      uVar6 = uStack_10;
      if ((uStack_14 & 0xff) != 0) {
        uVar6 = uStack_10 / (uStack_14 & 0xff);
      }
      uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
      uStack_14 = uStack_14 / 10;
      uVar2 = FUN_fffb2e9c(uVar3 & 0xff);
      *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return &DAT_00001c8e;
  }
  if ((undefined2 *)(uint)bVar1 != (undefined2 *)0x32) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)bVar1;
  }
  uStack_10 = FUN_fffb4ebe(2);
  uStack_14 = 100000000;
  for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
    uVar3 = uStack_10;
    if (uStack_14 != 0) {
      uVar3 = uStack_10 / uStack_14;
    }
    uVar6 = uStack_10;
    if ((uStack_14 & 0xff) != 0) {
      uVar6 = uStack_10 / (uStack_14 & 0xff);
    }
    uStack_10 = uStack_10 - (uVar6 * uStack_14 & 0xff);
    uStack_14 = uStack_14 / 10;
    uVar2 = FUN_fffb2e9c(uVar3 & 0xff);
    *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
  }
  DAT_00001c9c = 0x3b;
  DAT_0001b788 = 0xf;
  return &DAT_00001c8e;
}


// ===== cat_ext_EO @ fffa5c90 (847 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5d68) */
/* WARNING: Removing unreachable block (ram,0xfffa5e8a) */
/* WARNING: Removing unreachable block (ram,0xfffa5f4e) */

void cat_ext_EO(int param_1)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  short in_stack_00000044;
  undefined *puStack_18;
  uint uStack_14;
  ushort uStack_e;
  byte bStack_8;
  byte bStack_6;
  
  iVar5 = FUN_fffb324c(0);
  bVar2 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  if (2 < bVar2) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00020f3b = 0;
  DAT_00020b8a = 0;
  DAT_00020b99 = 0;
  DAT_00020bbe = 0;
  DAT_00020b97 = 0;
  DAT_00020b98 = 0;
  DAT_00020b9a = 0;
  DAT_00020b9b = 0;
  if (*(char *)(param_1 + 3) == '0') {
    uVar6 = FUN_fffb357c(0,2);
    uStack_e = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      bVar2 = *(byte *)((uint)bStack_8 + param_1);
      if ((bVar2 < 0x30) || (0x39 < bVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      sVar4 = FUN_fffb2f07(bVar2);
      uStack_e = sVar4 * in_stack_00000044 + uStack_e;
    }
    if (*(char *)(param_1 + 5) == '0') {
      uStack_14 = (uint)uStack_e;
    }
    else if (*(char *)(param_1 + 5) == '1') {
      uStack_14 = (uint)uStack_e * 1000;
    }
    else if (*(char *)(param_1 + 5) == '2') {
      uStack_14 = (uint)uStack_e * 1000000;
    }
    if (*(char *)(param_1 + 4) == '+') {
      puStack_18 = (undefined *)(uVar6 + uStack_14);
    }
    else {
      if (*(char *)(param_1 + 4) != '-') {
        DAT_0000464a = 1;
        return;
      }
      if (uVar6 < uStack_14) {
        puStack_18 = (undefined *)0x0;
      }
      else {
        puStack_18 = (undefined *)(uVar6 - uStack_14);
      }
    }
    if (puStack_18 < &DAT_00007530) {
      puStack_18 = &DAT_00007530;
    }
    else if ((undefined *)0x47868c0 < puStack_18) {
      puStack_18 = (undefined *)0x47868c0;
    }
    for (bStack_8 = 0; bStack_8 < 4; bStack_8 = bStack_8 + 1) {
      *(char *)((uint)bStack_8 + iVar5 + 0x4a) =
           (char)((uint)puStack_18 >> ((3 - bStack_8 & 3) << 3));
    }
  }
  else if (*(char *)(param_1 + 3) == '1') {
    bStack_6 = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = FUN_fffb2f07(*(undefined1 *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * (char)in_stack_00000044 + bStack_6;
    }
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      FUN_fffc64c0((int)(char)bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      FUN_fffc64c0((int)(char)(~bStack_6 + 1));
    }
  }
  else if (*(char *)(param_1 + 3) == '2') {
    bStack_6 = 0;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = FUN_fffb2f07(*(undefined1 *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * (char)in_stack_00000044 + bStack_6;
    }
    DAT_00020f3b = 0;
    DAT_00020bbe = 0;
    DAT_00020b74 = 1;
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      FUN_fffc7daf((int)(char)bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      FUN_fffc7daf((int)(char)(~bStack_6 + 1));
    }
  }
  DAT_00020f10 = 1;
  return;
}


// ===== cat_ext_PE @ fffa5fdf (1166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6276) */
/* WARNING: Removing unreachable block (ram,0xfffa646a) */
/* WARNING: Removing unreachable block (ram,0xfffa6400) */
/* WARNING: Removing unreachable block (ram,0xfffa6390) */
/* WARNING: Removing unreachable block (ram,0xfffa62d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6378) */
/* WARNING: Removing unreachable block (ram,0xfffa63e8) */
/* WARNING: Removing unreachable block (ram,0xfffa6224) */
/* WARNING: Removing unreachable block (ram,0xfffa6467) */
/* WARNING: Removing unreachable block (ram,0xfffa6327) */

int cat_ext_PE(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_R14;
  byte bVar4;
  char in_stack_00000020;
  int local_18;
  byte *local_14;
  byte local_e;
  byte local_b;
  byte local_a;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ada;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009adb;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adc;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009add;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ade;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adf;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae0;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae1;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae2;
      }
    }
  }
  if (*(char *)(param_1 + 2) == '2') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae3;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae4;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae5;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae6;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae7;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae8;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae9;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009aea;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009aeb;
      }
    }
  }
  if (*(char *)(param_1 + 4) == '0') {
    *in_R14 = 1;
  }
  if (param_2 == '\0') {
    if ((in_R14 == (undefined4 *)0x0) && (*(char *)(param_1 + 4) != '2')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_a = 100;
      local_e = *local_14;
      iVar3 = 0;
      for (local_b = 0; local_b < 3; local_b = local_b + 1) {
        bVar4 = local_e;
        if (local_a != 0) {
          bVar4 = local_e / local_a;
        }
        local_e = local_e - bVar4 * local_a;
        local_a = local_a / 10;
        iVar3 = FUN_fffb2e9c(bVar4);
        *(char *)((int)&DAT_00001c93 + (uint)local_b) = (char)iVar3;
      }
      *(undefined1 *)((int)&DAT_00001c93 + (uint)local_b) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 5;
      return iVar3;
    }
    if (*(char *)(param_1 + 4) == '1') {
      local_e = *local_14;
      if ((local_e & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        local_e = ~local_e + 1;
      }
      local_a = 10;
      iVar3 = 0;
      for (local_b = 0; local_b < 2; local_b = local_b + 1) {
        bVar4 = local_e;
        if (local_a != 0) {
          bVar4 = local_e / local_a;
        }
        local_e = local_e - bVar4 * local_a;
        local_a = local_a / 10;
        iVar3 = FUN_fffb2e9c(bVar4);
        *(char *)((int)&DAT_00001c93 + local_b + 1) = (char)iVar3;
      }
      *(undefined1 *)((int)&DAT_00001c93 + local_b + 1) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 6;
      return iVar3;
    }
  }
  else {
    if ((in_R14 == (undefined4 *)0x0) && (*(char *)(param_1 + 4) != '2')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      for (local_b = 5; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          local_18 = 1;
        }
        else {
          local_18 = 0;
        }
        if (local_18 != 0) {
          DAT_0000464a = 1;
          return local_18;
        }
        cVar2 = FUN_fffb2f07(*(undefined1 *)((uint)local_b + param_1));
        local_e = cVar2 * in_stack_00000020 + local_e;
      }
      *local_14 = local_e;
    }
    else if (*(char *)(param_1 + 4) == '1') {
      for (local_b = 6; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          local_18 = 1;
        }
        else {
          local_18 = 0;
        }
        if (local_18 != 0) {
          DAT_0000464a = 1;
          return local_18;
        }
        cVar2 = FUN_fffb2f07(*(undefined1 *)((uint)local_b + param_1));
        local_e = cVar2 * in_stack_00000020 + local_e;
      }
      if (*(char *)(param_1 + 5) == '-') {
        local_e = ~local_e + 1;
      }
      *local_14 = local_e;
    }
    if ((DAT_00020b20 == '\x01') || (DAT_00020b21 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b22 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      iVar3 = FUN_fffddb6a();
      return iVar3;
    }
  }
  return 0;
}


// ===== cat_AB @ fffa646d (359 bytes)

void cat_AB(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
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
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    iVar2 = FUN_fffb4bba(1);
    if (iVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbf = 1;
    puVar4 = &DAT_00009d09;
    puVar3 = &DAT_00009d63;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffc2fde(1);
    FUN_fffc16f6(1);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AC @ fffa65d4 (659 bytes)

void cat_AC(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  FUN_fffb324c(0);
  cVar3 = DAT_00009ab8;
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    if (DAT_00009ab8 == '\x03') {
      DAT_00001c91 = 0x32;
      if (DAT_00020f0c == '\0') {
        DAT_00001c92 = 0x30;
      }
      else if (DAT_00020f0c == '\x02') {
        if (DAT_00020b3c == '\x02') {
          DAT_00001c92 = 0x31;
        }
        else if (DAT_00020b3c == '\x03') {
          DAT_00001c92 = 0x32;
        }
      }
      else if (DAT_00020f0c == '\x01') {
        DAT_00001c92 = 0x33;
      }
    }
    else {
      DAT_00001c91 = 0x30;
      if (DAT_00020b41 == '\x02') {
        DAT_00001c92 = 0x33;
      }
      else {
        FUN_fffec55a();
        DAT_00001c92 = FUN_fffb2e9c();
      }
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    iVar4 = FUN_fffb44f7(0x301,0);
    if (iVar4 == 0) {
      DAT_0000464a = 1;
      return;
    }
    cVar1 = *(char *)(param_1 + 3);
    if (cVar1 == '2') {
      if (cVar3 != '\x03') {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(param_1 + 4) == '0') {
        FUN_fffed24e(0);
      }
      else if (*(char *)(param_1 + 4) == '1') {
        FUN_fffed206(2);
        FUN_fffed24e(1);
      }
      else if (*(char *)(param_1 + 4) == '2') {
        FUN_fffed206(2);
        FUN_fffed24e(2);
      }
      else {
        if (*(char *)(param_1 + 4) != '3') {
          DAT_0000464a = 1;
          return;
        }
        FUN_fffed206(1);
      }
    }
    else if (cVar1 != '1') {
      if (cVar1 == '0') {
        if ((cVar3 == '\0') || (cVar3 == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 3;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 1;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            if (DAT_00020b3d == '\0') {
              DAT_00020b41 = '\x01';
            }
          }
        }
        else {
          if (cVar3 != '\x02') {
            DAT_0000464a = 1;
            return;
          }
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 6;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 4;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            DAT_00020b40 = 1;
          }
        }
      }
      else {
        DAT_0000464a = 1;
      }
    }
    FUN_fffe6e26();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AG @ fffa6867 (223 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa68d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6927) */
/* WARNING: Removing unreachable block (ram,0xfffa6911) */
/* WARNING: Removing unreachable block (ram,0xfffa68a1) */
/* WARNING: Removing unreachable block (ram,0xfffa6943) */

undefined2 * cat_AG(int param_1,char param_2)

{
  undefined1 uVar1;
  byte bVar2;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00020ba8;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar2 = local_d;
      if (local_b != 0) {
        bVar2 = local_d / local_b;
      }
      local_d = local_d - bVar2 * local_b;
      local_b = local_b / 10;
      uVar1 = FUN_fffb2e9c(bVar2);
      (&DAT_00001c91)[local_c] = uVar1;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  local_d = '\0';
  local_c = 3;
  while( true ) {
    if ((undefined2 *)0x5 < (undefined2 *)(uint)local_c) {
      DAT_00020ba8 = local_d;
      return (undefined2 *)(uint)local_c;
    }
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) break;
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
    local_c = local_c + 1;
  }
  DAT_0000464a = 1;
  return local_14;
}


// ===== cat_AI @ fffa6946 (224 bytes)

void cat_AI(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (DAT_0000464c == '\x03') {
      DAT_00001c90 = FUN_fffb2e9c(DAT_00020b22);
    }
    else if (DAT_0000464c == '\x02') {
      DAT_00001c90 = FUN_fffb2e9c(DAT_00020b21);
    }
    else if (DAT_0000464c == '\x01') {
      DAT_00001c90 = FUN_fffb2e9c(DAT_00020b20);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (0x31 < *(byte *)(param_1 + 2)) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_0000464c == '\x03') {
    DAT_00020b22 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x02') {
    DAT_00020b21 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x01') {
    DAT_00020b20 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  }
  if (*(char *)(param_1 + 2) == '1') {
    FUN_fffddb6a();
    return;
  }
  return;
}


// ===== cat_AM @ fffa6a26 (329 bytes)

void cat_AM(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  bVar2 = DAT_000060c9;
  puVar4 = &DAT_00006150 + (uint)DAT_000060c9 * 0x5a;
  puVar3 = (undefined1 *)
           ((int)&DAT_00004761 +
           (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438);
  if ((DAT_000060c9 < 0x75) || (0x84 < DAT_000060c9)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbe == '\x01') {
      puVar3 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x04') {
      FUN_fffbf41f();
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x03') {
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbe == '\x05') {
        for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        FUN_fffb0376(bVar2);
        return;
      }
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    FUN_fffc2fde(DAT_00009dbd);
    FUN_fffc16f6(DAT_00009dbd);
    DAT_00020f10 = 1;
    FUN_fffb0376(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AO @ fffa6b6f (302 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6bdf) */
/* WARNING: Removing unreachable block (ram,0xfffa6c30) */
/* WARNING: Removing unreachable block (ram,0xfffa6c97) */
/* WARNING: Removing unreachable block (ram,0xfffa6c8b) */
/* WARNING: Removing unreachable block (ram,0xfffa6c1a) */
/* WARNING: Removing unreachable block (ram,0xfffa6baa) */
/* WARNING: Removing unreachable block (ram,0xfffa6c9a) */

undefined2 * cat_AO(int param_1,char param_2)

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
    local_d = DAT_00009bf2;
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
  if ((local_d == 0) || (100 < local_d)) {
    local_14 = (undefined2 *)0x0;
  }
  else {
    local_14 = (undefined2 *)0x1;
  }
  if (local_14 != (undefined2 *)0x0) {
    DAT_00009bf2 = local_d;
    if (DAT_00009ace != '\0') {
      return local_14;
    }
    DAT_00020cc6 = 0x28;
    FUN_fffc8cbb(0x28);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_AS @ fffa6c9d (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6d9c) */
/* WARNING: Removing unreachable block (ram,0xfffa6ddc) */
/* WARNING: Removing unreachable block (ram,0xfffa6e46) */
/* WARNING: Removing unreachable block (ram,0xfffa6e3a) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed9) */
/* WARNING: Removing unreachable block (ram,0xfffa6df2) */
/* WARNING: Removing unreachable block (ram,0xfffa6e0d) */
/* WARNING: Removing unreachable block (ram,0xfffa6ea3) */
/* WARNING: Removing unreachable block (ram,0xfffa6eca) */
/* WARNING: Removing unreachable block (ram,0xfffa6e79) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed6) */
/* WARNING: Removing unreachable block (ram,0xfffa6cf7) */
/* WARNING: Removing unreachable block (ram,0xfffa6d86) */

char * cat_AS(int param_1,char param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *extraout_R14;
  byte bVar4;
  char in_stack_00000028;
  char *pcStack_1c;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  
  pcVar1 = (char *)FUN_fffb54a0();
  pcVar2 = (char *)FUN_fffb552c();
  if (*(char *)(param_1 + 2) == '1') {
    *extraout_R14 = 1;
  }
  if (param_2 == '\0') {
    pcVar3 = (char *)0x0;
    if (extraout_R14 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '2') {
        DAT_0000464a = 1;
        return (char *)0x0;
      }
      if (*pcVar2 == '\0') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x31;
      }
      else if (*pcVar2 == '\x01') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x32;
      }
    }
    else {
      bStack_d = *pcVar1 * '\x05';
      bStack_b = 100;
      for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
        bVar4 = bStack_d;
        if (bStack_b != 0) {
          bVar4 = bStack_d / bStack_b;
        }
        bStack_d = bStack_d - bVar4 * bStack_b;
        bStack_b = bStack_b / 10;
        pcVar3 = (char *)FUN_fffb2e9c(bVar4);
        (&DAT_00001c91)[bStack_c] = (char)pcVar3;
      }
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return pcVar3;
  }
  if (extraout_R14 == (undefined4 *)0x0) {
    if ((char *)(uint)*(byte *)(param_1 + 2) != (char *)0x32) {
      DAT_0000464a = 1;
      return (char *)(uint)*(byte *)(param_1 + 2);
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      pcStack_1c = (char *)0x0;
    }
    else {
      pcStack_1c = (char *)0x1;
    }
    if (pcStack_1c != (char *)0x0) {
      DAT_0000464a = 1;
      return pcStack_1c;
    }
    if (*(char *)(param_1 + 5) == '1') {
      *pcVar2 = '\0';
    }
    else {
      if ((char *)(uint)*(byte *)(param_1 + 5) != (char *)0x32) {
        DAT_0000464a = 1;
        return (char *)(uint)*(byte *)(param_1 + 5);
      }
      *pcVar2 = '\x01';
    }
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x58;
      FUN_fffc8cbb(0x58);
      pcVar1 = (char *)FUN_fffc8d8c();
      return pcVar1;
    }
  }
  else {
    bStack_d = 0;
    for (bStack_c = 3; bStack_c < 6; bStack_c = bStack_c + 1) {
      if ((*(byte *)((uint)bStack_c + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_c + param_1))) {
        pcStack_1c = (char *)0x1;
      }
      else {
        pcStack_1c = (char *)0x0;
      }
      if (pcStack_1c != (char *)0x0) {
        DAT_0000464a = 1;
        return pcStack_1c;
      }
      bStack_d = (*(byte *)((uint)bStack_c + param_1) & 0xf) * in_stack_00000028 + bStack_d;
    }
    if ((char *)0x64 < (char *)(uint)bStack_d) {
      DAT_0000464a = 1;
      return (char *)(uint)bStack_d;
    }
    pcVar2 = (char *)(bStack_d / 5);
    *pcVar1 = (char)pcVar2;
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x33;
      FUN_fffc8cbb(0x33);
      pcVar1 = (char *)FUN_fffc8d8c();
      return pcVar1;
    }
  }
  return pcVar2;
}


// ===== cat_AV @ fffa6edc (316 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6fa3) */
/* WARNING: Removing unreachable block (ram,0xfffa6f68) */
/* WARNING: Removing unreachable block (ram,0xfffa7015) */
/* WARNING: Removing unreachable block (ram,0xfffa7012) */
/* WARNING: Removing unreachable block (ram,0xfffa6fb9) */
/* WARNING: Removing unreachable block (ram,0xfffa7006) */
/* WARNING: Removing unreachable block (ram,0xfffa6f33) */

undefined2 * cat_AV(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000008;
  undefined2 *local_1c;
  byte local_15;
  byte local_14;
  byte local_13;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_15 = DAT_00009bf6;
    }
    else {
      local_15 = DAT_00009bf7;
    }
    local_13 = 100;
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      bVar3 = local_15;
      if (local_13 != 0) {
        bVar3 = local_15 / local_13;
      }
      local_15 = local_15 - bVar3 * local_13;
      local_13 = local_13 / 10;
      uVar1 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c90)[local_14] = uVar1;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  local_15 = 0;
  for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
    if ((*(byte *)((uint)local_14 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_14 + param_1))
       ) {
      local_1c = (undefined2 *)0x1;
    }
    else {
      local_1c = (undefined2 *)0x0;
    }
    if (local_1c != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_1c;
    }
    local_15 = (*(byte *)((uint)local_14 + param_1) & 0xf) * in_stack_00000008 + local_15;
  }
  if ((undefined2 *)0x64 < (undefined2 *)(uint)local_15) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)local_15;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf6 = local_15;
  }
  else {
    DAT_00009bf7 = local_15;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2b;
    FUN_fffc8cbb(0x2b);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return (undefined2 *)&DAT_00009bca;
}


// ===== cat_BA @ fffa7018 (359 bytes)

void cat_BA(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
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
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    iVar2 = FUN_fffb4bba(0);
    if (iVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbe = 1;
    puVar4 = &DAT_00009d63;
    puVar3 = &DAT_00009d09;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_fffc2fde(0);
    FUN_fffc16f6(0);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_BC @ fffa717f (346 bytes)

void cat_BC(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbStack_14;
  byte bStack_e;
  
  iVar4 = FUN_fffb324c(0);
  bVar2 = FUN_fffb3196(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x15);
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x33);
    }
    else {
      if (uVar1 - 6 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 8) {
        if (uVar1 - 10 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 - 0xc < 2) {
          bStack_e = *(byte *)(iVar4 + 0x1f);
          goto LAB_fffa7214;
        }
        if (uVar1 != 0xe) {
          bStack_e = *(byte *)(iVar4 + 0xb);
          goto LAB_fffa7214;
        }
      }
      bStack_e = *(byte *)(iVar4 + 0x29);
    }
LAB_fffa7214:
    DAT_00001c90 = 0x30;
    if ((bStack_e & 0x80) == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x15);
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x33);
  }
  else {
    if (uVar1 - 6 < 2) {
      DAT_0000464a = 1;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (uVar1 - 0xc < 2) {
        pbStack_14 = (byte *)(iVar4 + 0x1f);
        goto LAB_fffa72ae;
      }
      if (uVar1 != 0xe) {
        pbStack_14 = (byte *)(iVar4 + 0xb);
        goto LAB_fffa72ae;
      }
    }
    pbStack_14 = (byte *)(iVar4 + 0x29);
  }
LAB_fffa72ae:
  cVar3 = FUN_fffb2f07(*(undefined1 *)(param_1 + 3));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0x7f;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 0x80;
  return;
}


// ===== cat_BD @ fffa72d9 (659 bytes)

void cat_BD(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_d;
  byte bStack_5;
  
  cVar2 = DAT_00009dbd;
  if (DAT_00020f1c == '\x01') {
    puVar4 = (undefined4 *)0x1;
  }
  else {
    puVar4 = (undefined4 *)(uint)DAT_00020f70;
    if (puVar4 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffa730b;
    }
  }
  bVar1 = true;
LAB_fffa730b:
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f0c, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b8a, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b3d, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cce, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f1b, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020ccd, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020b7c, puVar4 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cd0, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020cd1, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar4 = (undefined4 *)(uint)DAT_00020f11, puVar4 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    *puVar4 = 1;
  }
  if (cVar2 == '\0') {
    if (puVar4 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
    else {
      local_d = 0;
    }
  }
  else if (puVar4 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  else {
    local_d = 1;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((cVar2 == '\0') && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((cVar2 == '\x01') && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  uVar3 = FUN_fffb357c(0,local_d);
  bStack_5 = FUN_fffb33e5(uVar3);
  if (0xb < bStack_5) {
    bStack_5 = 0xb;
  }
  if (bStack_5 == 0) {
    bStack_5 = '\v';
  }
  else if (bStack_5 < 0xc) {
    bStack_5 = bStack_5 - 1;
  }
  else {
    bStack_5 = '\v';
  }
  if (*(char *)(param_1 + 2) == '0') {
    FUN_fffc4c4e(bStack_5,cVar2);
    return;
  }
  FUN_fffc4c4e(bStack_5,local_d);
  return;
}


// ===== cat_BU @ fffa756c (640 bytes)

void cat_BU(int param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_d;
  char cStack_5;
  
  cVar2 = DAT_00009dbd;
  if (DAT_00020f1c == '\x01') {
    puVar5 = (undefined4 *)0x1;
  }
  else {
    puVar5 = (undefined4 *)(uint)DAT_00020f70;
    if (puVar5 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffa759e;
    }
  }
  bVar1 = true;
LAB_fffa759e:
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f0c, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b8a, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b3d, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cce, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f1b, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020ccd, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020b7c, puVar5 != (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cd0, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020cd1, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (puVar5 = (undefined4 *)(uint)DAT_00020f11, puVar5 == (undefined4 *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    *puVar5 = 1;
  }
  if (cVar2 == '\0') {
    if (puVar5 == (undefined4 *)0x0) {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
    else {
      local_d = 0;
    }
  }
  else if (puVar5 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  else {
    local_d = 1;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((cVar2 == '\0') && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((cVar2 == '\x01') && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  uVar4 = FUN_fffb357c(0,local_d);
  bVar3 = FUN_fffb33e5(uVar4);
  if (bVar3 < 0xb) {
    cStack_5 = bVar3 + 1;
  }
  else {
    cStack_5 = '\0';
  }
  if (*(char *)(param_1 + 2) == '0') {
    FUN_fffc4c4e(cStack_5,cVar2);
    return;
  }
  FUN_fffc4c4e(cStack_5,local_d);
  return;
}


// ===== cat_BI @ fffa77ec (316 bytes)

void cat_BI(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbStack_14;
  byte bStack_e;
  
  iVar4 = FUN_fffb324c(1);
  bVar2 = FUN_fffb3196(1);
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x14);
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = *(byte *)(iVar4 + 0x32);
    }
    else {
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            DAT_0000464a = 1;
            return;
          }
          if (uVar1 == 0xe) {
            DAT_0000464a = 1;
            return;
          }
          bStack_e = *(byte *)(iVar4 + 10);
          goto LAB_fffa786d;
        }
      }
      bStack_e = *(byte *)(iVar4 + 0x3c);
    }
LAB_fffa786d:
    if ((bStack_e & 2) == 0) {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x14);
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = (byte *)(iVar4 + 0x32);
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 == 0xe) {
          DAT_0000464a = 1;
          return;
        }
        pbStack_14 = (byte *)(iVar4 + 10);
        goto LAB_fffa78fd;
      }
    }
    pbStack_14 = (byte *)(iVar4 + 0x3c);
  }
LAB_fffa78fd:
  cVar3 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0xfd;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 2;
  return;
}


// ===== cat_BM @ fffa7928 (329 bytes)

void cat_BM(void)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  int iVar7;
  
  bVar2 = DAT_000060ca;
  puVar4 = &DAT_00006150 + (uint)DAT_000060ca * 0x5a;
  puVar3 = &DAT_00005409 +
           (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438;
  if ((DAT_000060ca < 0x75) || (0x84 < DAT_000060ca)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbf == '\x01') {
      puVar5 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    else if (DAT_00009dbf == '\x04') {
      FUN_fffbf41f();
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbf == '\x03') {
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbf == '\x05') {
        for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        FUN_fffb0376(bVar2);
        return;
      }
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    FUN_fffc2fde(DAT_00009dbd);
    FUN_fffc16f6(DAT_00009dbd);
    DAT_00020f10 = 1;
    FUN_fffb0376(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_BP @ fffa7a71 (836 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa7d1c) */
/* WARNING: Removing unreachable block (ram,0xfffa7b81) */
/* WARNING: Removing unreachable block (ram,0xfffa7ba9) */
/* WARNING: Removing unreachable block (ram,0xfffa7db2) */
/* WARNING: Removing unreachable block (ram,0xfffa7cd9) */
/* WARNING: Removing unreachable block (ram,0xfffa7d69) */
/* WARNING: Removing unreachable block (ram,0xfffa7daf) */
/* WARNING: Removing unreachable block (ram,0xfffa7d33) */
/* WARNING: Removing unreachable block (ram,0xfffa7a9d) */
/* WARNING: Removing unreachable block (ram,0xfffa7bde) */
/* WARNING: Removing unreachable block (ram,0xfffa7d85) */

undefined2 * cat_BP(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  ushort uVar6;
  short in_stack_00000038;
  undefined2 *puStack_2c;
  ushort uStack_26;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  byte *pbStack_1c;
  undefined1 uStack_16;
  undefined1 uStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  iVar3 = FUN_fffb324c(0);
  bVar1 = FUN_fffb3196(0);
  if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 2);
  }
  uVar4 = (uint)bVar1;
  if (param_2 == '\0') {
    if (uVar4 - 2 < 2) {
      bStack_12 = *(byte *)(iVar3 + 0x14);
      uStack_16 = *(undefined1 *)(iVar3 + 0x18);
      uStack_15 = *(undefined1 *)(iVar3 + 0x19);
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 4 < 2) {
      bStack_12 = *(byte *)(iVar3 + 0x32);
      uStack_16 = *(undefined1 *)(iVar3 + 0x36);
      uStack_15 = *(undefined1 *)(iVar3 + 0x37);
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 6 < 2) {
LAB_fffa7b3c:
      bStack_12 = *(byte *)(iVar3 + 0x3c);
      uStack_16 = *(undefined1 *)(iVar3 + 0x40);
      uStack_15 = *(undefined1 *)(iVar3 + 0x41);
    }
    else {
      if (1 < uVar4 - 8) {
        if (uVar4 - 10 < 2) goto LAB_fffa7b3c;
        if (uVar4 - 0xc < 2) {
          bStack_12 = *(byte *)(iVar3 + 0x1e);
          uStack_16 = *(undefined1 *)(iVar3 + 0x22);
          uStack_15 = *(undefined1 *)(iVar3 + 0x23);
          goto LAB_fffa7b4e;
        }
        if (uVar4 != 0xe) {
          bStack_12 = *(byte *)(iVar3 + 10);
          uStack_16 = *(undefined1 *)(iVar3 + 0xe);
          uStack_15 = *(undefined1 *)(iVar3 + 0xf);
          goto LAB_fffa7b4e;
        }
      }
      bStack_12 = *(byte *)(iVar3 + 0x28);
      uStack_16 = *(undefined1 *)(iVar3 + 0x2c);
      uStack_15 = *(undefined1 *)(iVar3 + 0x2d);
    }
LAB_fffa7b4e:
    if (*(char *)(param_1 + 3) == '0') {
      DAT_00001c92 = 0x30;
      DAT_00001c93._0_1_ = 0x30;
      if ((bStack_12 & 0x80) == 0) {
        DAT_00001c93._1_1_ = 0x30;
      }
      else {
        DAT_00001c93._1_1_ = 0x31;
      }
    }
    else {
      uStack_26 = CONCAT11(uStack_16,uStack_15);
      bStack_13 = 100;
      for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
        uVar4 = (uint)uStack_26;
        if (bStack_13 != 0) {
          uVar4 = uVar4 / bStack_13;
        }
        uVar6 = uStack_26;
        if (bStack_13 != 0) {
          uVar6 = uStack_26 / bStack_13;
        }
        uStack_26 = uStack_26 - (uVar6 * bStack_13 & 0xff);
        bStack_13 = bStack_13 / 10;
        uVar2 = FUN_fffb2e9c(uVar4 & 0xff);
        (&DAT_00001c92)[bStack_14] = uVar2;
      }
    }
    DAT_00001c93._2_1_ = 0x3b;
    DAT_0001b788 = 8;
    return &DAT_00001c8e;
  }
  if (uVar4 - 2 < 2) {
    pbStack_1c = (byte *)(iVar3 + 0x14);
    puStack_24 = (undefined1 *)(iVar3 + 0x18);
    puStack_20 = (undefined1 *)(iVar3 + 0x19);
    goto LAB_fffa7c97;
  }
  if (uVar4 - 4 < 2) {
    pbStack_1c = (byte *)(iVar3 + 0x32);
    puStack_24 = (undefined1 *)(iVar3 + 0x36);
    puStack_20 = (undefined1 *)(iVar3 + 0x37);
    goto LAB_fffa7c97;
  }
  if (uVar4 - 6 < 2) {
LAB_fffa7c82:
    pbStack_1c = (byte *)(iVar3 + 0x3c);
    puStack_24 = (undefined1 *)(iVar3 + 0x40);
    puStack_20 = (undefined1 *)(iVar3 + 0x41);
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffa7c82;
      if (uVar4 - 0xc < 2) {
        pbStack_1c = (byte *)(iVar3 + 0x1e);
        puStack_24 = (undefined1 *)(iVar3 + 0x22);
        puStack_20 = (undefined1 *)(iVar3 + 0x23);
        goto LAB_fffa7c97;
      }
      if (uVar4 != 0xe) {
        pbStack_1c = (byte *)(iVar3 + 10);
        puStack_24 = (undefined1 *)(iVar3 + 0xe);
        puStack_20 = (undefined1 *)(iVar3 + 0xf);
        goto LAB_fffa7c97;
      }
    }
    pbStack_1c = (byte *)(iVar3 + 0x28);
    puStack_24 = (undefined1 *)(iVar3 + 0x2c);
    puStack_20 = (undefined1 *)(iVar3 + 0x2d);
  }
LAB_fffa7c97:
  if (*(char *)(param_1 + 3) == '0') {
    puVar5 = (undefined2 *)(uint)*(byte *)(param_1 + 4);
    if ((puVar5 != (undefined2 *)0x30) ||
       (puVar5 = (undefined2 *)(uint)*(byte *)(param_1 + 5), puVar5 != (undefined2 *)0x30)) {
      return puVar5;
    }
    if (*(char *)(param_1 + 6) == '0') {
      *pbStack_1c = *pbStack_1c & 0x7f;
    }
    else {
      if ((undefined2 *)(uint)*(byte *)(param_1 + 6) != (undefined2 *)0x31) {
        DAT_0000464a = 1;
        return (undefined2 *)(uint)*(byte *)(param_1 + 6);
      }
      *pbStack_1c = *pbStack_1c | 0x80;
    }
  }
  else {
    if ((undefined2 *)(uint)*(byte *)(param_1 + 3) != (undefined2 *)0x31) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)*(byte *)(param_1 + 3);
    }
    uStack_26 = 0;
    for (bStack_14 = 4; bStack_14 < 7; bStack_14 = bStack_14 + 1) {
      if ((*(byte *)((uint)bStack_14 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_14 + param_1))) {
        puStack_2c = (undefined2 *)0x1;
      }
      else {
        puStack_2c = (undefined2 *)0x0;
      }
      if (puStack_2c != (undefined2 *)0x0) {
        DAT_0000464a = 1;
        return puStack_2c;
      }
      uStack_26 = (*(byte *)((uint)bStack_14 + param_1) & 0xf) * in_stack_00000038 + uStack_26;
    }
    if ((uStack_26 == 0) || (0x140 < uStack_26)) {
      puStack_2c = (undefined2 *)0x1;
    }
    else {
      puStack_2c = (undefined2 *)0x0;
    }
    if (puStack_2c != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return puStack_2c;
    }
    *puStack_24 = (char)(uStack_26 >> 8);
    *puStack_20 = (undefined1)uStack_26;
  }
  DAT_00020f10 = 1;
  FUN_fffc2fde(DAT_00009dbd);
  puVar5 = (undefined2 *)FUN_fffc16f6(DAT_00009dbd);
  return puVar5;
}


// ===== cat_BS @ fffa7db5 (492 bytes)

void cat_BS(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  uVar2 = DAT_00009dbd;
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
    if ((*(byte *)(param_1 + 2) < 0x30) || (0x31 < *(byte *)(param_1 + 2))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      cVar3 = FUN_fffb2f07(*(undefined1 *)(param_1 + 2));
      if ((*(byte *)(param_1 + 3) < 0x30) || (0x39 < *(byte *)(param_1 + 3))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        cVar4 = FUN_fffb2f07(*(undefined1 *)(param_1 + 3));
        bVar5 = cVar4 + cVar3 * '\n';
        if (0xc < bVar5) {
          DAT_0000464a = 1;
          return;
        }
        FUN_fffc4c4e(bVar5,uVar2);
        DAT_00009c5e = 0;
        DAT_00009dbe = 1;
        DAT_00009dbf = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CF @ fffa7fa1 (980 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8071) */
/* WARNING: Removing unreachable block (ram,0xfffa808d) */
/* WARNING: Removing unreachable block (ram,0xfffa8303) */
/* WARNING: Removing unreachable block (ram,0xfffa82ac) */
/* WARNING: Removing unreachable block (ram,0xfffa8287) */
/* WARNING: Removing unreachable block (ram,0xfffa825c) */
/* WARNING: Removing unreachable block (ram,0xfffa8218) */
/* WARNING: Removing unreachable block (ram,0xfffa831d) */
/* WARNING: Removing unreachable block (ram,0xfffa8372) */
/* WARNING: Removing unreachable block (ram,0xfffa8354) */
/* WARNING: Removing unreachable block (ram,0xfffa81e0) */
/* WARNING: Removing unreachable block (ram,0xfffa8191) */
/* WARNING: Removing unreachable block (ram,0xfffa813d) */
/* WARNING: Removing unreachable block (ram,0xfffa81c6) */
/* WARNING: Removing unreachable block (ram,0xfffa81fa) */

undefined2 * cat_CF(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  ushort uVar7;
  undefined2 *puStack_24;
  byte bStack_1e;
  char local_1d;
  byte *local_1c;
  ushort uStack_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  undefined2 *local_10;
  undefined4 uStack_c;
  
  uStack_c = CONCAT13(param_2,(undefined3)uStack_c);
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = (undefined2 *)&DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
    else {
      local_10 = (undefined2 *)&DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
  }
  else {
    if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x31) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)*(byte *)(param_1 + 2);
    }
    if (DAT_00009dbd == '\0') {
      local_10 = (undefined2 *)&DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
    else {
      local_10 = (undefined2 *)&DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
  }
  bVar2 = FUN_fffb2f07(*(undefined1 *)(param_1 + 4));
  if ((undefined2 *)0x1 < (undefined2 *)(uint)bVar2) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)bVar2;
  }
  if (param_2 == '\0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = FUN_fffb2e9c(bVar2);
    if (bVar2 == 0) {
      if (local_1d == '\0') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x01') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x02') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x31;
      }
      else if (local_1d == '\x03') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x31;
      }
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c97 = 0x30;
    }
    else {
      uStack_16 = CONCAT11(*(byte *)(local_10 + 0x24),*(undefined1 *)((int)local_10 + 0x49));
      if ((*(byte *)(local_10 + 0x24) & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        uStack_16 = ~uStack_16 + 1;
      }
      uStack_18 = 1000;
      for (bStack_13 = 0; bStack_13 < 4; bStack_13 = bStack_13 + 1) {
        uVar4 = (uint)uStack_16;
        if (uStack_18 != 0) {
          uVar4 = uVar4 / uStack_18;
        }
        uVar7 = uStack_16;
        if ((uStack_18 & 0xff) != 0) {
          uVar7 = (ushort)((uint)uStack_16 / (uStack_18 & 0xff));
        }
        uStack_16 = uStack_16 - (uVar7 * uStack_18 & 0xff);
        uStack_18 = uStack_18 / 10;
        uVar3 = FUN_fffb2e9c(uVar4 & 0xff);
        *(undefined1 *)((int)&DAT_00001c93 + bStack_13 + 1) = uVar3;
      }
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return &DAT_00001c8e;
  }
  puVar5 = (undefined2 *)FUN_fffb44f7(0x306,0);
  if (puVar5 != (undefined2 *)0x0) {
    if (DAT_00009c5e == '\x01') {
      DAT_0000464a = 1;
      return puVar5;
    }
    iVar6 = FUN_fffb4bba(DAT_00009dbd);
    if (iVar6 != 1) {
      if (bVar2 == 0) {
        if ((*(char *)(param_1 + 7) == '0') && (*(char *)(param_1 + 8) == '0')) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((bVar1) || (*(char *)(param_1 + 9) != '0')) {
          puStack_24 = (undefined2 *)0x1;
        }
        else {
          puStack_24 = (undefined2 *)0x0;
        }
        if (puStack_24 != (undefined2 *)0x0) {
          DAT_0000464a = 1;
          return puStack_24;
        }
        bStack_12 = 0;
        bStack_1e = 0;
        if (*(char *)(param_1 + 5) == '1') {
          bStack_12 = 1;
          bStack_1e = 0x10;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 5) != (undefined2 *)0x30) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 5);
        }
        if (*(char *)(param_1 + 6) == '1') {
          bStack_12 = bStack_12 | 2;
          bStack_1e = bStack_1e | 8;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 6) != (undefined2 *)0x30) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 6);
        }
        *local_1c = bStack_12;
        *(byte *)((int)local_10 + 1) = *(byte *)((int)local_10 + 1) & 0xe7;
        *(byte *)((int)local_10 + 1) = *(byte *)((int)local_10 + 1) | bStack_1e;
      }
      else {
        uStack_16 = 0;
        for (bStack_13 = 6; bStack_13 < 10; bStack_13 = bStack_13 + 1) {
          if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
             (0x39 < *(byte *)((uint)bStack_13 + param_1))) {
            puStack_24 = (undefined2 *)0x1;
          }
          else {
            puStack_24 = (undefined2 *)0x0;
          }
          if (puStack_24 != (undefined2 *)0x0) {
            DAT_0000464a = 1;
            return puStack_24;
          }
          uStack_16 = *(short *)((*(byte *)((uint)bStack_13 + param_1) & 0xf) * uStack_c) +
                      uStack_16;
        }
        if (*(char *)(param_1 + 5) == '-') {
          uStack_16 = ~uStack_16 + 1;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 5) != (undefined2 *)0x2b) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 5);
        }
        *(char *)(local_10 + 0x24) = (char)(uStack_16 >> 8);
        *(byte *)((int)local_10 + 0x49) = (byte)uStack_16;
        local_10 = (undefined2 *)(uint)(byte)uStack_16;
      }
      DAT_00020f10 = 1;
      return local_10;
    }
    DAT_0000464a = 1;
    return (undefined2 *)0x1;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_CH @ fffa8375 (414 bytes)

void cat_CH(int param_1)

{
  bool bVar1;
  char local_6;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
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
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_6 = DAT_00009dbe;
  }
  else {
    local_6 = DAT_00009dbf;
  }
  if (local_6 != '\x02') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00020f80 = 0;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00020f80 = 1;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CN @ fffa8513 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8603) */
/* WARNING: Removing unreachable block (ram,0xfffa863e) */
/* WARNING: Removing unreachable block (ram,0xfffa8695) */
/* WARNING: Removing unreachable block (ram,0xfffa8654) */
/* WARNING: Removing unreachable block (ram,0xfffa85ce) */
/* WARNING: Removing unreachable block (ram,0xfffa852e) */

undefined2 * cat_CN(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_0000000c;
  undefined2 *local_1c;
  undefined1 local_15;
  byte local_14;
  byte local_13;
  byte local_12;
  undefined1 *local_10;
  
  if ((undefined2 *)(uint)*(byte *)(param_1 + 3) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 3);
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
    else {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
    else {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
  }
  if (param_2 != '\0') {
    local_14 = 0;
    local_13 = 4;
    while( true ) {
      if (6 < local_13) {
        if (local_14 < 0x32) {
          local_10[0x46] = local_14;
        }
        else {
          DAT_0000464a = 1;
        }
        DAT_00020f10 = 1;
        FUN_fffc2fde(local_15);
        puVar2 = (undefined2 *)FUN_fffc16f6(local_15);
        return puVar2;
      }
      if ((*(byte *)((uint)local_13 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)local_13 + param_1))) {
        local_1c = (undefined2 *)0x1;
      }
      else {
        local_1c = (undefined2 *)0x0;
      }
      if (local_1c != (undefined2 *)0x0) break;
      local_14 = (*(byte *)((uint)local_13 + param_1) & 0xf) * in_stack_0000000c + local_14;
      local_13 = local_13 + 1;
    }
    DAT_0000464a = 1;
    return local_1c;
  }
  local_12 = 100;
  local_14 = local_10[0x46];
  for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
    bVar3 = local_14;
    if (local_12 != 0) {
      bVar3 = local_14 / local_12;
    }
    local_14 = local_14 - bVar3 * local_12;
    local_12 = local_12 / 10;
    uVar1 = FUN_fffb2e9c(bVar3);
    (&DAT_00001c92)[local_13] = uVar1;
  }
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return &DAT_00001c8e;
}


// ===== cat_CO @ fffa8698 (1280 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa89a8) */
/* WARNING: Removing unreachable block (ram,0xfffa89f9) */
/* WARNING: Removing unreachable block (ram,0xfffa8b95) */
/* WARNING: Removing unreachable block (ram,0xfffa8b27) */
/* WARNING: Removing unreachable block (ram,0xfffa8b7d) */
/* WARNING: Removing unreachable block (ram,0xfffa8b3d) */
/* WARNING: Removing unreachable block (ram,0xfffa89b4) */
/* WARNING: Removing unreachable block (ram,0xfffa8999) */
/* WARNING: Removing unreachable block (ram,0xfffa8aad) */
/* WARNING: Removing unreachable block (ram,0xfffa8ab9) */
/* WARNING: Removing unreachable block (ram,0xfffa8a9e) */
/* WARNING: Removing unreachable block (ram,0xfffa8a8f) */
/* WARNING: Removing unreachable block (ram,0xfffa8a47) */
/* WARNING: Removing unreachable block (ram,0xfffa8a11) */
/* WARNING: Removing unreachable block (ram,0xfffa8a71) */
/* WARNING: Removing unreachable block (ram,0xfffa88d2) */
/* WARNING: Removing unreachable block (ram,0xfffa87dc) */
/* WARNING: Removing unreachable block (ram,0xfffa889d) */
/* WARNING: Removing unreachable block (ram,0xfffa871e) */
/* WARNING: Removing unreachable block (ram,0xfffa8732) */
/* WARNING: Removing unreachable block (ram,0xfffa875a) */
/* WARNING: Removing unreachable block (ram,0xfffa8746) */
/* WARNING: Removing unreachable block (ram,0xfffa870a) */
/* WARNING: Removing unreachable block (ram,0xfffa8a4c) */
/* WARNING: Removing unreachable block (ram,0xfffa8b89) */
/* WARNING: Removing unreachable block (ram,0xfffa8aec) */
/* WARNING: Removing unreachable block (ram,0xfffa86f7) */

byte * cat_CO(int param_1,char param_2)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  uint3 uVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined1 uVar8;
  uint uVar9;
  byte bVar10;
  ushort uVar11;
  char in_stack_00000004;
  byte *pbStack_30;
  ushort uStack_2a;
  ushort uStack_28;
  byte bStack_25;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  byte *pbStack_1c;
  byte *pbStack_18;
  byte bStack_11;
  int iStack_10;
  char local_9;
  int local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  iStack_10 = FUN_fffb324c(0);
  bStack_11 = FUN_fffb3196(0);
  uVar6 = uStack_24;
  uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
  uVar9 = (uint)bStack_11;
  if (local_9 != '\0') {
    if (uVar9 - 2 < 2) {
      pbStack_18 = (byte *)(iStack_10 + 0x14);
      pbStack_1c = (byte *)(iStack_10 + 0x14);
      puStack_20 = (undefined1 *)(iStack_10 + 0x16);
      goto LAB_fffa8986;
    }
    if (uVar9 - 4 < 2) {
      pbStack_18 = (byte *)(iStack_10 + 0x32);
      pbStack_1c = (byte *)((int)&uStack_24 + 3);
      puStack_20 = (undefined1 *)(iStack_10 + 0x34);
      goto LAB_fffa8986;
    }
    if (uVar9 - 6 < 2) {
LAB_fffa8973:
      pbStack_18 = (byte *)(iStack_10 + 0x3c);
      pbStack_1c = (byte *)((int)&uStack_24 + 3);
      puStack_20 = (undefined1 *)(iStack_10 + 0x3e);
    }
    else {
      if (1 < uVar9 - 8) {
        if (uVar9 - 10 < 2) goto LAB_fffa8973;
        if (uVar9 - 0xc < 2) {
          pbStack_18 = (byte *)(iStack_10 + 0x1e);
          pbStack_1c = (byte *)(iStack_10 + 0x1e);
          puStack_20 = (undefined1 *)(iStack_10 + 0x20);
          goto LAB_fffa8986;
        }
        if (uVar9 != 0xe) {
          pbStack_18 = (byte *)(iStack_10 + 10);
          pbStack_1c = (byte *)((int)&uStack_24 + 3);
          puStack_20 = (undefined1 *)(iStack_10 + 0xc);
          goto LAB_fffa8986;
        }
      }
      pbStack_18 = (byte *)(iStack_10 + 0x28);
      pbStack_1c = (byte *)(iStack_10 + 0x28);
      puStack_20 = (undefined1 *)(iStack_10 + 0x2a);
    }
LAB_fffa8986:
    if (*(char *)(local_8 + 3) == '0') {
      if (*(char *)(local_8 + 7) == '0') {
        *pbStack_18 = *pbStack_18 & 0xbf;
        return pbStack_18;
      }
      if ((byte *)(uint)*(byte *)(local_8 + 7) == (byte *)0x31) {
        *pbStack_18 = *pbStack_18 | 0x40;
        return pbStack_18;
      }
      DAT_0000464a = 1;
      return (byte *)(uint)*(byte *)(local_8 + 7);
    }
    if (*(char *)(local_8 + 3) == '1') {
      uStack_28 = 0;
      uStack_24 = CONCAT31(uStack_24._1_3_,4);
      while (uVar9 = uStack_24, (uStack_24 & 0xff) < 8) {
        bVar7 = *(byte *)((uStack_24 & 0xff) + local_8);
        sVar4 = (ushort)uStack_24;
        uStack_24._0_3_ = CONCAT12(bVar7,(ushort)uStack_24);
        uVar5 = (uint3)uStack_24;
        uStack_24 = (uint)(uint3)uStack_24;
        uVar2 = uStack_24;
        if ((bVar7 < 0x30) || (0x39 < bVar7)) {
          pbStack_30 = (byte *)0x1;
        }
        else {
          pbStack_30 = (byte *)0x0;
        }
        if (pbStack_30 != (byte *)0x0) {
          DAT_0000464a = 1;
          return pbStack_30;
        }
        uStack_24._0_1_ = (char)uVar9;
        uStack_28 = (*(byte *)((uVar2 & 0xff) + local_8) & 0xf) * sVar4 + uStack_28;
        uStack_24 = CONCAT31(uVar5 >> 8,(char)uStack_24 + '\x01');
      }
      if ((uStack_28 < 10) || (0xc80 < uStack_28)) {
        pbStack_30 = (byte *)0x1;
      }
      else {
        pbStack_30 = (byte *)0x0;
      }
      if (pbStack_30 == (byte *)0x0) {
        *puStack_20 = (char)(uStack_28 / 10 >> 8);
        uStack_28._0_1_ = (byte)(uStack_28 / 10);
        puStack_20[1] = (byte)uStack_28;
        DAT_00020f10 = 1;
        return (byte *)(uint)(byte)uStack_28;
      }
      DAT_0000464a = 1;
      return pbStack_30;
    }
    if (*(char *)(local_8 + 3) == '2') {
      if (*pbStack_1c == 0xff) {
        DAT_0000464a = 1;
        return pbStack_1c;
      }
      if (*(char *)(local_8 + 7) != '0') {
        if ((byte *)(uint)*(byte *)(local_8 + 7) == (byte *)0x31) {
          *pbStack_1c = *pbStack_1c | 0x20;
          return pbStack_1c;
        }
        DAT_0000464a = 1;
        return (byte *)(uint)*(byte *)(local_8 + 7);
      }
      *pbStack_1c = *pbStack_1c & 0xdf;
      return pbStack_1c;
    }
    if ((byte *)(uint)*(byte *)(local_8 + 3) != (byte *)0x33) {
      DAT_0000464a = 1;
      return (byte *)(uint)*(byte *)(local_8 + 3);
    }
    if ((*(char *)(local_8 + 4) == '0') && (*(char *)(local_8 + 5) == '0')) {
      pbStack_30 = (byte *)0x0;
    }
    else {
      pbStack_30 = (byte *)0x1;
    }
    if (pbStack_30 == (byte *)0x0) {
      bStack_25 = 0;
      uStack_24 = 6;
      while( true ) {
        cVar3 = (char)uStack_24;
        if (7 < uStack_24) {
          pbVar1 = (byte *)(uint)bStack_25;
          if ((byte *)0x32 < pbVar1) {
            DAT_0000464a = 1;
            return pbVar1;
          }
          DAT_00009c5f = bStack_25 - 0x19;
          DAT_00020f10 = 1;
          return pbVar1;
        }
        bVar7 = *(byte *)(uStack_24 + local_8);
        uStack_24._0_3_ = CONCAT12(bVar7,(ushort)uStack_24);
        uStack_24 = (uint)(uint3)uStack_24;
        if ((bVar7 < 0x30) || (0x39 < bVar7)) {
          pbStack_30 = (byte *)0x1;
        }
        else {
          pbStack_30 = (byte *)0x0;
        }
        if (pbStack_30 != (byte *)0x0) break;
        bStack_25 = (*(byte *)((uStack_24 & 0xff) + local_8) & 0xf) * in_stack_00000004 + bStack_25;
        uStack_24 = (uint)(byte)(cVar3 + 1);
      }
      DAT_0000464a = 1;
      return pbStack_30;
    }
    DAT_0000464a = 1;
    return pbStack_30;
  }
  uStack_24._0_2_ = (ushort)uVar6;
  if (uVar9 - 2 < 2) {
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x14),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x16),*(undefined1 *)(iStack_10 + 0x17));
    goto LAB_fffa8761;
  }
  if (uVar9 - 4 < 2) {
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x32),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x34),*(undefined1 *)(iStack_10 + 0x35));
    goto LAB_fffa8761;
  }
  if (uVar9 - 6 < 2) {
LAB_fffa874f:
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x3c),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x3e),*(undefined1 *)(iStack_10 + 0x3f));
  }
  else {
    if (1 < uVar9 - 8) {
      if (uVar9 - 10 < 2) goto LAB_fffa874f;
      if (uVar9 - 0xc < 2) {
        uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x1e),(ushort)uStack_24);
        uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
        uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x20),*(undefined1 *)(iStack_10 + 0x21));
        goto LAB_fffa8761;
      }
      if (uVar9 != 0xe) {
        uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 10),(ushort)uStack_24);
        uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
        uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0xc),*(undefined1 *)(iStack_10 + 0xd));
        goto LAB_fffa8761;
      }
    }
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x28),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x2a),*(undefined1 *)(iStack_10 + 0x2b));
  }
LAB_fffa8761:
  if (*(char *)(local_8 + 3) == '0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((uStack_24 & 0x400000) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '1') {
    DAT_00001c91 = 0x31;
    uStack_2a = 1000;
    uStack_28 = uStack_28 * 10;
    uStack_24 = uStack_24 & 0xffffff00;
    while ((uStack_24 & 0xff) < 4) {
      uVar9 = (uint)uStack_28;
      if (uStack_2a != 0) {
        uVar9 = uVar9 / uStack_2a;
      }
      uStack_24._0_3_ = CONCAT12((char)uVar9,(ushort)uStack_24);
      uVar11 = uStack_28;
      if ((uStack_2a & 0xff) != 0) {
        uVar11 = (ushort)((uint)uStack_28 / (uStack_2a & 0xff));
      }
      uStack_28 = uStack_28 - (uVar11 * uStack_2a & 0xff);
      uStack_2a = uStack_2a / 10;
      uVar2 = (uint)(uint3)uStack_24;
      uVar8 = FUN_fffb2e9c((char)uVar9);
      (&DAT_00001c92)[uVar2 & 0xff] = uVar8;
      uStack_24 = CONCAT31(uStack_24._1_3_,(char)uStack_24 + '\x01');
    }
    DAT_00001c93._2_1_ = 0x30;
  }
  else if (*(char *)(local_8 + 3) == '2') {
    DAT_00001c91 = 0x32;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((uStack_24 & 0x200000) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '3') {
    DAT_00001c91 = 0x33;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    bStack_25 = DAT_00009c5f + 0x19;
    uStack_24 = CONCAT22(uStack_24._2_2_,0xa00);
    while ((uStack_24 & 0xff) < 2) {
      bVar7 = bStack_25;
      if (uStack_24._1_1_ != 0) {
        bVar7 = bStack_25 / uStack_24._1_1_;
      }
      bVar10 = bStack_25;
      if (uStack_24._1_1_ != 0) {
        bVar10 = bStack_25 / uStack_24._1_1_;
      }
      bStack_25 = bStack_25 - bVar10 * uStack_24._1_1_;
      uStack_24._0_2_ = CONCAT11(uStack_24._1_1_ / 10,(char)uStack_24);
      uStack_24 = CONCAT22(CONCAT11(uStack_24._3_1_,bVar7),(ushort)uStack_24);
      uVar9 = (uint)(ushort)uStack_24;
      uVar8 = FUN_fffb2e9c(bVar7);
      *(undefined1 *)((int)&DAT_00001c93 + (uVar9 & 0xff) + 1) = uVar8;
      uStack_24 = CONCAT31(uStack_24._1_3_,(char)uStack_24 + '\x01');
    }
  }
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return (byte *)&DAT_00001c8e;
}


// ===== cat_CS @ fffa8b98 (225 bytes)

void cat_CS(int param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    if (DAT_00020f0b == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  uVar1 = FUN_fffb324c(1);
  iVar2 = FUN_fffb44f7(0x307,2);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_0000464a = 1;
    return;
  }
  iVar2 = FUN_fffc3e3c(uVar1);
  if (iVar2 != 0) {
    if (*(char *)(param_1 + 2) == '1') {
      DAT_00020f0b = 1;
      FUN_fffb2da6(4);
      return;
    }
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00020f0b != '\x01') {
      return;
    }
    DAT_00020f0b = 0;
    FUN_fffb2df4();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CT @ fffa8c79 (273 bytes)

void cat_CT(int param_1,char param_2)

{
  byte bVar1;
  undefined1 *local_c;
  
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (param_2 != '\0') {
    if (*(char *)(param_1 + 3) == '0') {
      local_c[3] = local_c[3] & 199;
    }
    else if (*(char *)(param_1 + 3) == '2') {
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 8;
    }
    else {
      if (*(char *)(param_1 + 3) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 0x10;
    }
    DAT_00020f10 = 1;
    return;
  }
  bVar1 = (local_c[3] & 0x38) >> 3;
  if (bVar1 == 0) {
    DAT_00001c91 = 0x30;
  }
  else if (bVar1 == 1) {
    DAT_00001c91 = 0x32;
  }
  else {
    if (bVar1 != 2) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c91 = 0x31;
  }
  DAT_00001c92 = 0x3b;
  DAT_0001b788 = 5;
  return;
}


// ===== cat_DA @ fffa8d8a (671 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8eab) */
/* WARNING: Removing unreachable block (ram,0xfffa8e27) */
/* WARNING: Removing unreachable block (ram,0xfffa8ee6) */
/* WARNING: Removing unreachable block (ram,0xfffa8f41) */
/* WARNING: Removing unreachable block (ram,0xfffa9026) */
/* WARNING: Removing unreachable block (ram,0xfffa8ef7) */
/* WARNING: Removing unreachable block (ram,0xfffa8f52) */
/* WARNING: Removing unreachable block (ram,0xfffa8f9c) */
/* WARNING: Removing unreachable block (ram,0xfffa8dd8) */
/* WARNING: Removing unreachable block (ram,0xfffa8e76) */
/* WARNING: Removing unreachable block (ram,0xfffa8fad) */
/* WARNING: Removing unreachable block (ram,0xfffa901a) */

undefined2 * cat_DA(int param_1,char param_2)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_f;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    DAT_00001c91 = 0x30;
    local_b = 10;
    local_f = DAT_00009be9;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_f;
      if (local_b != 0) {
        bVar3 = local_f / local_b;
      }
      local_f = local_f - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = FUN_fffb2e9c(bVar3);
      (&DAT_00001c92)[local_c] = uVar2;
    }
    local_b = 10;
    local_d = DAT_00009bea;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = FUN_fffb2e9c(bVar3);
      *(undefined1 *)((int)&DAT_00001c93 + local_c + 1) = uVar2;
    }
    local_b = 10;
    local_e = DAT_00009b10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_e;
      if (local_b != 0) {
        bVar3 = local_e / local_b;
      }
      local_e = local_e - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = FUN_fffb2e9c(bVar3);
      *(undefined1 *)((int)&DAT_00001c93 + local_c + 3) = uVar2;
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return &DAT_00001c8e;
  }
  local_f = 0;
  for (local_c = 4; local_c < 6; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_f = (bVar3 & 0xf) * in_stack_00000010 + local_f;
  }
  local_d = 0;
  for (local_c = 6; local_c < 8; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (bVar3 & 0xf) * in_stack_00000010 + local_d;
  }
  local_e = 0;
  for (local_c = 8; local_c < 10; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_e = (bVar3 & 0xf) * in_stack_00000010 + local_e;
  }
  if ((local_f < 0x15) && (local_d < 0x15)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (local_e < 0x15)) {
    local_14 = (undefined2 *)0x1;
  }
  else {
    local_14 = (undefined2 *)0x0;
  }
  if (local_14 != (undefined2 *)0x0) {
    DAT_00009be9 = local_f;
    DAT_00009bea = local_d;
    DAT_00009b10 = local_e;
    DAT_00020f04 = 1;
    return local_14;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_DN @ fffa9029 (300 bytes)

void cat_DN(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffb44f7(0x34e,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
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
  FUN_fffc037b();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_UP @ fffa9155 (300 bytes)

void cat_UP(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffb44f7(0x348,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
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
  FUN_fffc0335();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_DT @ fffa9281 (967 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa943d) */
/* WARNING: Removing unreachable block (ram,0xfffa93cb) */
/* WARNING: Removing unreachable block (ram,0xfffa940d) */
/* WARNING: Removing unreachable block (ram,0xfffa9491) */
/* WARNING: Removing unreachable block (ram,0xfffa95a3) */
/* WARNING: Removing unreachable block (ram,0xfffa95e5) */

void cat_DT(int param_1,char param_2)

{
  bool bVar1;
  undefined4 *in_R14;
  char in_stack_00000010;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_7;
  byte local_6;
  
  if (*(char *)(param_1 + 2) == '0') {
    *in_R14 = 1;
  }
  if (param_2 == '\0') {
    if (in_R14 != (undefined4 *)0x0) {
      DAT_00001c91 = 0x32;
      DAT_00001c92 = 0x30;
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb1);
      FUN_fffb311d(0x1c95,DAT_00020bb2);
      FUN_fffb311d(&DAT_00001c97,DAT_00020bb3);
      DAT_00001c99 = 0x3b;
      DAT_0001b788 = 0xc;
      return;
    }
    if (*(char *)(param_1 + 2) == '1') {
      FUN_fffb311d(&DAT_00001c91,DAT_00020bb4);
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb5);
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c97 = 0x3b;
      DAT_0001b788 = 10;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (in_R14 != (undefined4 *)0x0) {
    for (local_6 = 3; local_6 < 0xb; local_6 = local_6 + 1) {
      if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1))
         ) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
    }
    local_9 = '\0';
    for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_9;
    }
    if (local_9 != '\x14') {
      DAT_0000464a = 1;
      return;
    }
    local_9 = 0;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_9;
    }
    local_a = 0;
    for (local_6 = 7; local_6 < 9; local_6 = local_6 + 1) {
      local_a = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_a;
    }
    if ((local_a == 0) || (0xc < local_a)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_b = 0;
      for (local_6 = 9; local_6 < 0xb; local_6 = local_6 + 1) {
        local_b = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_b;
      }
      if (local_a == 2) {
        if ((local_9 & 3) == 0) {
          local_7 = 0x1d;
        }
        else {
          local_7 = 0x1c;
        }
      }
      else if ((((local_a == 4) || (local_a == 6)) || (local_a == 9)) || (local_a == 0xb)) {
        local_7 = 0x1e;
      }
      else {
        local_7 = 0x1f;
      }
      if ((local_b == 0) || (local_7 < local_b)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      DAT_00020bb1 = FUN_fffb30b5(param_1 + 5);
      DAT_00020bb6 = DAT_00020bb1;
      DAT_00020bb2 = FUN_fffb30b5(param_1 + 7);
      DAT_00020bb7 = DAT_00020bb2;
      DAT_00020bb3 = FUN_fffb30b5(param_1 + 9);
      DAT_00020bb8 = DAT_00020bb3;
      DAT_00020b91 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    DAT_0000464a = 1;
    return;
  }
  for (local_6 = 3; local_6 < 9; local_6 = local_6 + 1) {
    if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
  }
  local_7 = 0;
  for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
    local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_7;
  }
  if (local_7 < 0x18) {
    local_7 = 0;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_7;
    }
    if (0x3b < local_7) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020bb4 = FUN_fffb30b5(param_1 + 3);
    DAT_00020bb9 = DAT_00020bb4;
    DAT_00020bba = FUN_fffb30b5(param_1 + 5);
    DAT_00020bb5 = DAT_00020bba;
    DAT_00020b91 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}

