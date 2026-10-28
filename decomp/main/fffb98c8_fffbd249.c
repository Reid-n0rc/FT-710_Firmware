// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb98c8 @ fffb98c8 (33 bytes)

void FUN_fffb98c8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_00020b2f = 0;
  DAT_0001215f = 0;
  puVar1 = &DAT_000120bc;
  for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return;
}


// ===== FUN_fffb98e9 @ fffb98e9 (2120 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb99ff) */
/* WARNING: Removing unreachable block (ram,0xfffb9dba) */
/* WARNING: Removing unreachable block (ram,0xfffb9dc9) */
/* WARNING: Removing unreachable block (ram,0xfffb9e12) */
/* WARNING: Removing unreachable block (ram,0xfffb9fbe) */
/* WARNING: Removing unreachable block (ram,0xfffb9d50) */
/* WARNING: Removing unreachable block (ram,0xfffb9e51) */
/* WARNING: Removing unreachable block (ram,0xfffb9e42) */
/* WARNING: Removing unreachable block (ram,0xfffb9e7a) */

void FUN_fffb98e9(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  int in_stack_0000003c;
  char cStack_19;
  char cStack_18;
  byte bStack_15;
  byte bStack_13;
  byte bStack_11;
  byte bStack_10;
  ushort uStack_e;
  ushort uStack_c;
  byte bStack_9;
  
  bVar1 = DAT_00009aa9;
  iVar8 = FUN_fffba192();
  if ((iVar8 == 0) || (DAT_00020b97 != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fffb98c8();
    FUN_fffbb1c2();
    DAT_00020b2a = 0;
    return;
  }
  iVar8 = FUN_fffb23f3(0x13);
  if ((iVar8 != 1) || (DAT_00020f0c != '\0')) {
    return;
  }
  if (DAT_0001b4d5 != DAT_00009c03) {
    bVar2 = false;
    if (DAT_00012164 == '\0') {
      FUN_fffbb283();
      if ((cStack_18 == '\x01') && (cStack_19 == '\x01')) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if (bVar3) {
        if (DAT_00012162 == '\x02') {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
    }
    if (bVar2) {
      DAT_0001b4d5 = DAT_00009c03;
      FUN_fffb98c8();
    }
  }
  if (DAT_00009c02 == '\0') {
    DAT_0001215f = 0;
  }
  else {
    DAT_0001215f = DAT_00009aa7;
  }
  DAT_00021014 = 1200000;
  if (DAT_0001b4d5 != 0) {
    DAT_00021014 = 1200000 / DAT_0001b4d5;
  }
  DAT_00021010 = ((bVar1 + 0x19) * DAT_00021014) / 10;
  DAT_0001215c = FUN_fffb548a();
  if (DAT_0001215f == 0) {
    DAT_0001215c = 0xf;
  }
  else {
    if ((DAT_0001b4d5 < 0x29) || (DAT_0001215c < 0x10)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      DAT_0001215c = 0xf;
    }
    else {
      if ((DAT_0001b4d5 < 0x24) || (DAT_0001215c < 0x15)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        DAT_0001215c = 0x14;
      }
      else {
        if ((DAT_0001b4d5 < 0x1f) || (DAT_0001215c < 0x1a)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          DAT_0001215c = 0x19;
        }
      }
    }
  }
  switch(DAT_00020b2f) {
  case 0:
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 1;
    FUN_fffb237a(0x19,DAT_0001215c);
    FUN_fffbaff6();
  case 1:
    if (DAT_0001215f < 2) {
      FUN_fffba840(DAT_0001215f);
    }
    else if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,0);
    }
    break;
  case 2:
    if (DAT_0001215d != '\x01') {
      return;
    }
    puVar11 = &DAT_000120bc;
    for (iVar8 = 0xa0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    DAT_0001fa3a = 0;
    DAT_0001fa38 = 0;
    DAT_00020b2f = 3;
    FUN_fffb237a(0x19,DAT_0001215c);
    FUN_fffb237a(0x1b,&DAT_00002710);
    FUN_fffbaff6();
    DAT_00021040 = FUN_fffb324c(1);
    iVar8 = FUN_fffb521a();
    if (iVar8 == 1) {
      DAT_00012166 = '\x01';
      *(byte *)(DAT_00021040 + 0x14) = *(byte *)(DAT_00021040 + 0x14) & 0xfd;
    }
    else {
      DAT_00012166 = '\0';
    }
  case 3:
    if (DAT_0001215f - 2 < 4) {
      FUN_fffba377(DAT_0001215f,1);
    }
    break;
  case 4:
    if (DAT_00012166 == '\x01') {
      DAT_00012166 = '\0';
      *(byte *)(DAT_00021040 + 0x14) = *(byte *)(DAT_00021040 + 0x14) | 2;
    }
    DAT_0001fa3a = DAT_0001fa38;
    if (DAT_0001fa38 != 0) {
      bStack_9 = DAT_00020ccc;
      if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        bStack_9 = 1;
      }
      in_stack_0000003c = in_stack_0000003c * 0x98;
      (&DAT_0000930f)[in_stack_0000003c] = (char)(DAT_0001fa38 >> 8);
      (&DAT_00009310)[in_stack_0000003c] = (char)DAT_0001fa3a;
      puVar9 = &DAT_00009311 + in_stack_0000003c;
      puVar11 = &DAT_000120bc;
      for (iVar8 = 0x96; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *(undefined1 *)puVar11;
        puVar9 = puVar9 + 1;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      FUN_fffb0450(0,bStack_9);
    }
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    DAT_00020b2f = 0;
    break;
  case 5:
    DAT_00012165 = '\0';
    if (DAT_0001215d != '\x01') {
      DAT_00012165 = 0;
      return;
    }
    iVar8 = FUN_fffb2dfe();
    if (iVar8 == 1) {
      return;
    }
    bStack_9 = DAT_00020ccc;
    if ((DAT_00020ccc == 0) || (5 < DAT_00020ccc)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_9 = 1;
    }
    bStack_9 = bStack_9 - 1;
    DAT_0001fa38 = 0;
    DAT_0001fa3a = 0;
    if ((&DAT_00009aad)[bStack_9] == '\x01') {
      DAT_0001fa38 = CONCAT11(*(undefined1 *)(&DAT_000093a7 + in_stack_0000003c * 0x26),
                              *(undefined1 *)((int)&DAT_000093a7 + in_stack_0000003c * 0x98 + 1));
      puVar10 = (undefined1 *)((int)&DAT_000093a7 + in_stack_0000003c * 0x98 + 2);
      puVar11 = &DAT_000120bc;
      for (iVar8 = 0x96; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar11 = *puVar10;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar10 = puVar10 + 1;
      }
    }
    else {
      iVar8 = (uint)bStack_9 * 0x33;
      bVar1 = (&DAT_0000969f)[iVar8];
      bVar2 = false;
      for (bStack_13 = 0; bStack_13 < bVar1; bStack_13 = bStack_13 + 1) {
        bVar5 = (&DAT_000096a0)[(uint)bStack_13 + iVar8];
        bVar4 = (&DAT_fff815c3)[(uint)bVar5 * 2];
        bStack_15 = (&DAT_fff815c4)[(uint)bVar5 * 2];
        if (bVar5 == 0x23) {
          DAT_00012165 = '\x01';
          uStack_e = FUN_fffba30c();
          uStack_c = 1000;
          for (bStack_11 = 0; bStack_11 < 4; bStack_11 = bStack_11 + 1) {
            uVar12 = (uint)uStack_e;
            if (uStack_c != 0) {
              uVar12 = uVar12 / uStack_c;
            }
            uVar7 = uStack_e;
            if ((uStack_c & 0xff) != 0) {
              uVar7 = (ushort)((uint)uStack_e / (uStack_c & 0xff));
            }
            uStack_e = uStack_e - (uVar7 * uStack_c & 0xff);
            uStack_c = uStack_c / 10;
            cVar6 = nib2hex(uVar12 & 0xff);
            if ((bStack_11 == 0) && (cVar6 == '0')) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            if (!bVar3) {
              bVar4 = FUN_fffbb2bf(cVar6);
              bVar5 = (&DAT_fff815c3)[(uint)bVar4 * 2];
              bStack_15 = (&DAT_fff815c4)[(uint)bVar4 * 2];
              for (bStack_10 = 0; bStack_10 < bVar5; bStack_10 = bStack_10 + 1) {
                if ((bStack_15 & 0x80) == 0) {
                  FUN_fffbb024(1);
                }
                else {
                  FUN_fffbb024(2);
                }
                FUN_fffbb024(0);
                bStack_15 = bStack_15 << 1;
              }
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                FUN_fffbb024(0);
              }
            }
          }
        }
        else if (bVar5 == 0x3c) {
          iVar13 = FUN_fffb521a();
          if ((iVar13 == 1) && (uVar7 = FUN_fffba30c(), uVar7 < 9999)) {
            FUN_fffba336(uVar7 + 1);
          }
        }
        else if (bVar5 == 0x3e) {
          iVar13 = FUN_fffb521a();
          if ((iVar13 == 1) && (uVar7 = FUN_fffba30c(), 1 < uVar7)) {
            FUN_fffba336(uVar7 - 1);
          }
        }
        else if (bVar5 == 0x5b) {
          bVar2 = true;
        }
        else if (bVar5 == 0x5d) {
          bVar2 = false;
        }
        else if (bVar5 == 0x5e) {
          bVar5 = bStack_13 + 1;
          bStack_13 = bStack_13 + 2;
          if ((&DAT_000096a0)[(uint)bVar5 + iVar8] == '0') {
            bVar5 = (&DAT_000096a0)[(uint)bStack_13 + iVar8];
            if ((bVar5 < 0x31) || (0x35 < bVar5)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              cVar6 = hex2nib(bVar5);
              if (bStack_9 != (byte)(cVar6 - 1U)) {
                FUN_fffbb338(cVar6 - 1U);
              }
            }
          }
        }
        else {
          bStack_10 = 0;
          if (bVar4 == 0) {
            for (; bStack_10 < 4; bStack_10 = bStack_10 + 1) {
              FUN_fffbb024(0);
            }
          }
          else {
            for (; bStack_10 < bVar4; bStack_10 = bStack_10 + 1) {
              if ((bStack_15 & 0x80) == 0) {
                FUN_fffbb024(1);
              }
              else {
                FUN_fffbb024(2);
              }
              FUN_fffbb024(0);
              bStack_15 = bStack_15 << 1;
            }
            if (!bVar2) {
              for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
                FUN_fffbb024(0);
              }
            }
          }
        }
        if (0x4b0 < DAT_0001fa38) break;
      }
    }
    DAT_0001fa3c = DAT_0001fa38;
    DAT_0001fa38 = 0;
    FUN_fffb237a(0x19,DAT_0001215c);
    DAT_00020b2f = 6;
    FUN_fffbaff6();
  case 6:
    if (DAT_0001fa3a == DAT_0001fa3c) {
      DAT_00020b2f = 7;
      if (DAT_00020cd5 == '\x01') {
        FUN_fffb237a(0x1c,*(undefined2 *)((uint)DAT_00009ab2 * 1000));
      }
      if ((DAT_00012165 == '\x01') && (uVar7 = FUN_fffba30c(), uVar7 < 9999)) {
        FUN_fffba336(uVar7 + 1);
      }
    }
    else {
      FUN_fffbb283();
      if ((cStack_18 == '\x01') || (cStack_19 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        DAT_00020cd5 = '\0';
        DAT_00020b2f = 7;
      }
    }
    FUN_fffba9c3();
    break;
  case 7:
    if (DAT_00020cd5 == '\x01') {
      iVar8 = FUN_fffb23f3(0x1c);
      if (iVar8 == 1) {
        DAT_00020b2f = 5;
      }
    }
    else {
      DAT_0001fa38 = 0;
      DAT_0001fa3a = 0;
      FUN_fffbb1c2();
      DAT_00020b2f = 0;
    }
  }
  FUN_fffbaa81(DAT_0001215f);
  return;
}


// ===== FUN_fffba192 @ fffba192 (378 bytes)

undefined1 FUN_fffba192(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined1 uStack_5;
  
  bVar4 = FUN_fffb6ec5();
  cVar5 = FUN_fffb3196(1);
  uStack_5 = 0;
  cVar6 = FUN_fffb50d7(cVar5);
  cVar3 = DAT_00009a9f;
  DAT_0001215d = 0;
  if ((cVar5 == '\x03') || (cVar5 == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_0001215d = 1;
  }
  else {
    if ((cVar5 == '\0') || (cVar5 == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_0001215d = 2;
    }
  }
  if ((cVar5 == '\x03') || (cVar5 == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    return 1;
  }
  if ((cVar5 == '\0') || (cVar5 == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (DAT_00009a3c != '\x02') {
    if ((DAT_00009a3c == '\x01') && (iVar7 = FUN_fffb32fd(DAT_00020f50), iVar7 == 0xb)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      bVar2 = false;
      goto LAB_fffba271;
    }
  }
  bVar2 = true;
LAB_fffba271:
  if (bVar2) {
    uVar1 = (uint)bVar4;
    if (uVar1 == 1) {
      if ((cVar6 == '\0') || (cVar3 == '\x03')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else if (uVar1 == 3) {
      if ((cVar6 == '\0') || (cVar3 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else if (uVar1 == 4) {
      if ((cVar6 == '\0') || (cVar3 == '\x02')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uStack_5 = 3;
      }
      else {
        uStack_5 = 2;
      }
    }
    else {
      if (uVar1 != 6) {
        if (uVar1 == 7) {
          return 3;
        }
        if ((1 < uVar1 - 8) && (uVar1 != 0xb)) {
          return 4;
        }
      }
      uStack_5 = 2;
    }
  }
  return uStack_5;
}


// ===== FUN_fffba30c @ fffba30c (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba31c) */

undefined2 FUN_fffba30c(void)

{
  return CONCAT11(DAT_00009aab,DAT_00009aac);
}


// ===== FUN_fffba336 @ fffba336 (38 bytes)

void FUN_fffba336(undefined2 param_1)

{
  DAT_00009aab = (char)((ushort)param_1 >> 8);
  DAT_00009aac = (char)param_1;
  return;
}


// ===== FUN_fffba35c @ fffba35c (27 bytes)

undefined2 FUN_fffba35c(void)

{
  return *(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2);
}


// ===== FUN_fffba377 @ fffba377 (1225 bytes)

void FUN_fffba377(char param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  char cStack_a;
  char cStack_9;
  undefined4 uStack_8;
  
  iVar2 = FUN_fffb6ed4();
  if (iVar2 != 1) {
    DAT_00020b2a = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  iVar2 = FUN_fffb23f3(0x17);
  if (iVar2 != 1) {
    if (DAT_00012160 == '\0') {
      FUN_fffbb283();
      if ((param_1 == '\x03') || (param_1 == '\x04')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if ((DAT_00012161 == '\x02') && (cStack_9 == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_00012160 = '\x01';
        }
        else {
          if ((DAT_00012161 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00012160 = '\x02';
          }
        }
        if (param_1 == '\x04') {
          if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            DAT_00012160 = '\0';
          }
          else {
            iVar2 = FUN_fffb23f3(0x1d);
            if ((iVar2 != 1) && (DAT_00012161 == '\x02')) {
              DAT_00012160 = '\0';
            }
          }
        }
      }
      if ((DAT_00012160 == '\0') && (DAT_00012161 == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (DAT_00012163 == 1) {
          if (param_1 == '\x03') {
            if ((DAT_00012162 == '\x01') && (cStack_a == '\x01')) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (bVar1) {
              DAT_00012160 = '\x02';
            }
            else {
              if ((DAT_00012162 == '\x02') && (cStack_9 == '\x01')) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
              if (bVar1) {
                DAT_00012160 = '\x01';
              }
            }
          }
        }
        else {
          if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            if (cStack_9 == '\x01') {
              DAT_00012160 = '\x01';
            }
            else if (cStack_a == '\x01') {
              DAT_00012160 = '\x02';
            }
          }
        }
      }
    }
    if ((DAT_00012163 < 2) || (DAT_00012160 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (param_1 != '\x05')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffb237a(0x19,DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
    else {
      if ((DAT_00012163 < 4) || (DAT_00012160 == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (param_1 == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        return;
      }
      FUN_fffb237a(0x19,DAT_0001215c);
      DAT_0001fa3a = DAT_0001fa38;
    }
  }
  if ((param_2 == '\x01') && (iVar2 = FUN_fffbb10b(), iVar2 == 1)) {
    DAT_00020b2f = 4;
    return;
  }
  if (DAT_00012161 == '\0') {
    FUN_fffbb283();
    if ((param_1 == '\x03') || (param_1 == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00012160 == '\x02') {
        cStack_9 = '\0';
        cStack_a = '\x01';
      }
      else if (DAT_00012160 == '\x01') {
        cStack_9 = '\x01';
        cStack_a = '\0';
      }
    }
    else {
      if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        if (DAT_00012160 == '\x02') {
          cStack_9 = '\0';
          cStack_a = '\x01';
        }
        else if (DAT_00012160 == '\x01') {
          cStack_9 = '\x01';
          cStack_a = '\0';
        }
      }
    }
    DAT_00012160 = '\0';
    if ((cStack_9 == '\x01') && (cStack_a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00012162 == '\x01') {
        DAT_00012161 = '\x02';
        uStack_8 = DAT_00021010;
      }
      else {
        DAT_00012161 = '\x01';
        uStack_8 = DAT_00021014;
      }
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      uStack_8 = DAT_00021014;
    }
    else if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      uStack_8 = DAT_00021010;
    }
    else {
      if ((6 < DAT_00012163) ||
         ((DAT_00012163 = DAT_00012163 + 1, param_2 == '\x01' && (DAT_0001fa38 == 0)))) {
        return;
      }
      DAT_00012161 = '\0';
      uStack_8 = DAT_00021014;
    }
    if ((param_1 == '\x05') || (DAT_00012161 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_00012163 = 0;
    }
    if ((param_1 == '\x05') && (DAT_00012163 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00012161 != '\0')) {
      DAT_00012160 = DAT_00012161;
      DAT_00012161 = '\0';
      uStack_8 = DAT_00021014;
      DAT_00012163 = DAT_00012163 + 1;
    }
  }
  else {
    DAT_00012162 = DAT_00012161;
    DAT_00012161 = '\0';
    uStack_8 = DAT_00021014;
    DAT_00012163 = 1;
    if (param_2 == '\x01') {
      FUN_fffb237a(0x1b,&DAT_00002710);
    }
  }
  FUN_fffb23b4(0x17,uStack_8);
  if ((param_1 == '\x04') && (DAT_00012161 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffb23b4(0x1d,DAT_00021014);
  }
  FUN_fffbb024(DAT_00012161);
  return;
}


// ===== FUN_fffba840 @ fffba840 (387 bytes)

/* WARNING: Removing unreachable block (ram,0xfffba98f) */

void FUN_fffba840(char param_1)

{
  char cVar1;
  int iVar2;
  char cStack_a;
  char cStack_9;
  undefined4 uStack_8;
  
  iVar2 = FUN_fffb6ed4();
  if (iVar2 != 1) {
    DAT_00020b2a = 0;
    DAT_0001fa38 = DAT_0001fa3a;
    return;
  }
  iVar2 = FUN_fffb23f3(0x17);
  if (iVar2 != 1) {
    return;
  }
  if (param_1 == '\0') {
    cVar1 = FUN_fffb6ef3();
    DAT_00012161 = cVar1 == '\x01';
    if ((bool)DAT_00012161) {
      DAT_0001b4d6 = 0;
    }
    else {
      DAT_0001b4d6 = DAT_0001b4d6 + 1;
    }
    if (1 < DAT_0001b4d6) {
      DAT_0001b4d6 = DAT_0001b4d6 - 1;
      return;
    }
    FUN_fffb237a(0x17,2);
    FUN_fffbb024(DAT_00012161);
    return;
  }
  if (DAT_00012161 == '\x01') {
    DAT_00012161 = '\0';
    uStack_8 = DAT_00021014;
  }
  else {
    FUN_fffbb283();
    if (cStack_a == '\x01') {
      DAT_00012161 = '\x02';
      uStack_8 = 2000;
      DAT_0001b4d6 = 0;
    }
    else if (cStack_9 == '\x01') {
      DAT_00012161 = '\x01';
      uStack_8 = DAT_00021014;
      DAT_0001b4d6 = 0;
    }
    else {
      DAT_00012161 = '\0';
      uStack_8 = 2000;
      DAT_0001b4d6 = DAT_0001b4d6 + 1;
    }
  }
  if (10 < DAT_0001b4d6) {
    DAT_0001b4d6 = DAT_0001b4d6 - 1;
    return;
  }
  FUN_fffb23b4(0x17,uStack_8);
  *(undefined4 *)(&DAT_00021018 + ((uint)DAT_0001fa38 - ((DAT_0001fa38 / 10) * 10 & 0xff)) * 4) =
       uStack_8;
  if (DAT_00012161 == '\x02') {
    FUN_fffbb024(1);
    return;
  }
  FUN_fffbb024(DAT_00012161);
  return;
}


// ===== FUN_fffba9c3 @ fffba9c3 (190 bytes)

void FUN_fffba9c3(void)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uStack_6;
  undefined4 uStack_4;
  
  iVar3 = FUN_fffb23f3(0x17);
  if (iVar3 == 1) {
    if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa38 >> 3)) &
        1 << ((byte)DAT_0001fa38 & 7)) == 0) {
      uStack_4 = DAT_00021014;
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
    }
    else {
      uStack_6 = FUN_fffbb16b(DAT_0001fa38);
      if ((DAT_0001fa3c == uStack_6) ||
         (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_6 >> 3)) &
          1 << ((byte)uStack_6 & 7)) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        uStack_4 = DAT_00021010;
        uVar2 = FUN_fffbb16b(uStack_6);
        uStack_6 = FUN_fffbb16b(uVar2);
      }
      else {
        uStack_4 = DAT_00021014;
      }
    }
    DAT_0001fa38 = uStack_6;
    FUN_fffb23b4(0x17,uStack_4);
    return;
  }
  return;
}


// ===== FUN_fffbaa81 @ fffbaa81 (1397 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbafc6) */

void FUN_fffbaa81(byte param_1)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  char cVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  undefined2 uVar8;
  int iVar9;
  byte bStack_18;
  byte bStack_17;
  char cStack_16;
  ushort uStack_12;
  uint uStack_10;
  
  uVar5 = DAT_00020f50;
  FUN_fffb324c(1);
  cVar4 = DAT_00020b18;
  cStack_16 = -1;
  bVar1 = false;
  if (DAT_00012164 == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_0001fa38 == DAT_0001fa3a) {
    if ((DAT_00012164 != '\0') && (iVar9 = FUN_fffb23f3(0x1a), iVar9 == 1)) {
      if ((DAT_00020b6b == '\x01') || (iVar9 = FUN_fffb37fe(uVar5), iVar9 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (DAT_00020b2a == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b2a = '\0';
      }
    }
    FUN_fffb237a(0x19,DAT_0001215c);
    return;
  }
  if (DAT_00012164 != '\0') {
    if ((param_1 == 0) || (param_1 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) && (DAT_00020b2f != '\x06')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_18 = DAT_0001215c >> 1;
      if (bStack_18 == 0) {
        bStack_18 = 1;
      }
      if ((bStack_18 < DAT_0001fa38) &&
         ((uint)DAT_0001fa3a + (uint)bStack_18 + 1 < (uint)DAT_0001fa38)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if ((*(char *)((int)&DAT_000120bc + (uint)(DAT_0001fa38 >> 3)) == '\0') &&
           (*(char *)((int)&DAT_000120bc + (uint)(DAT_0001fa3a >> 3)) == '\0')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_0001fa3a = DAT_0001fa38 - bStack_18;
        }
      }
      iVar9 = FUN_fffb521a();
      if (iVar9 == 1) {
        uStack_12 = DAT_0001fa3a;
        for (bStack_17 = 0; bStack_17 < bStack_18; bStack_17 = bStack_17 + 1) {
          if (bStack_17 != 0) {
            uStack_12 = FUN_fffbb16b(uStack_12);
          }
          if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_12 >> 3)) &
              1 << ((byte)uStack_12 & 7)) != 0) {
            bVar1 = true;
            break;
          }
        }
        if (bVar1) {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00020b2a = '\x01';
          }
          if (cVar4 != '\x03') {
            FUN_fffb37fe(uVar5);
          }
        }
        else {
          iVar9 = FUN_fffb23f3(0x1a);
          if (iVar9 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              DAT_00020b2a = '\0';
            }
          }
        }
      }
    }
    else {
      iVar9 = FUN_fffb521a();
      if (iVar9 == 1) {
        if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa3a >> 3)) &
            1 << ((byte)DAT_0001fa3a & 7)) == 0) {
          iVar9 = FUN_fffb23f3(0x1a);
          if (iVar9 == 1) {
            if ((DAT_00020b3d == '\0') || (DAT_00020b2a != '\x01')) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              DAT_00020b2a = '\0';
            }
          }
        }
        else {
          if ((DAT_00020b6b == '\0') && (DAT_00020b2a != '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_00020b2a = 1;
            return;
          }
          if ((cVar4 != '\x03') && (iVar9 = FUN_fffb37fe(uVar5), iVar9 != 0)) {
            return;
          }
        }
      }
    }
  }
  iVar9 = FUN_fffb23f3(0x19);
  if (iVar9 != 1) {
    FUN_fffb237a(0x18,0);
    return;
  }
  iVar9 = FUN_fffb23f3(0x18);
  uVar3 = DAT_0001fa3a;
  if (iVar9 == 1) {
    if ((DAT_00020b2f == '\x01') || (DAT_00020b2f == '\x03')) {
      if (param_1 < 2) {
        cStack_16 = '\x01';
      }
      else if (param_1 - 2 < 4) {
        cStack_16 = '\0';
      }
    }
    else if (DAT_00020b2f == '\x06') {
      cStack_16 = '\0';
    }
    if (cStack_16 == '\0') {
      if (DAT_0001fa38 != DAT_0001fa3a) {
        if (DAT_00020b2f == '\x06') {
          uRam00000006 = 1;
        }
        if (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(DAT_0001fa3a >> 3)) &
            1 << ((byte)DAT_0001fa3a & 7)) == 0) {
          if (DAT_00020b2f != '\0') {
            FUN_fffbb1c2();
          }
          FUN_fffbb1dd(0);
          if (DAT_00012164 != '\0') {
            FUN_fffb237a(0x1a,*(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2));
          }
          uStack_10 = DAT_00021014;
          uStack_12 = FUN_fffbb16b(uVar3);
          DAT_00012164 = 0;
        }
        else {
          if (DAT_00020b2f != '\0') {
            FUN_fffbb185();
          }
          FUN_fffbb1dd(1);
          uStack_12 = FUN_fffbb16b(uVar3);
          if ((DAT_0001fa38 == uStack_12) ||
             (((uint)*(byte *)((int)&DAT_000120bc + (uint)(byte)(uStack_12 >> 3)) &
              1 << ((byte)uStack_12 & 7)) == 0)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            uStack_10 = DAT_00021010;
            uVar8 = FUN_fffbb16b(uStack_12);
            uStack_12 = FUN_fffbb16b(uVar8);
            DAT_00012164 = 2;
          }
          else {
            uStack_10 = DAT_00021014;
            DAT_00012164 = 1;
          }
        }
        DAT_0001fa3a = uStack_12;
        FUN_fffb23b4(0x18,uStack_10);
        return;
      }
    }
    else if ((cStack_16 == '\x01') && (DAT_0001fa38 != DAT_0001fa3a)) {
      bVar6 = (byte)(DAT_0001fa3a >> 3);
      bVar7 = (byte)DAT_0001fa3a & 7;
      if (DAT_00020b2f == '\x06') {
        uRam00000006 = 1;
      }
      if (((uint)*(byte *)((int)&DAT_000120bc + (uint)bVar6) & 1 << bVar7) == 0) {
        if (DAT_00020b2f != '\0') {
          FUN_fffbb1c2();
        }
        FUN_fffbb1dd(0);
        if (DAT_00012164 != '\0') {
          FUN_fffb237a(0x1a,*(undefined2 *)(&DAT_fff88380 + (uint)DAT_00009c05 * 2));
        }
        DAT_00012164 = 0;
      }
      else {
        if (DAT_00020b2f != '\0') {
          FUN_fffbb185();
        }
        FUN_fffbb1dd(1);
        DAT_00012164 = 1;
        *(byte *)((int)&DAT_000120bc + (uint)bVar6) =
             *(byte *)((int)&DAT_000120bc + (uint)bVar6) & ~(byte)(1 << bVar7);
      }
      if (param_1 == 0) {
        uStack_10 = 2000;
      }
      else {
        uStack_10 = *(uint *)(&DAT_00021018 + ((uint)uVar3 - ((uVar3 / 10) * 10 & 0xff)) * 4);
      }
      FUN_fffb23b4(0x18,uStack_10 & 0xffff);
      DAT_0001fa3a = FUN_fffbb16b(uVar3);
      return;
    }
  }
  return;
}


// ===== FUN_fffbaff6 @ fffbaff6 (46 bytes)

void FUN_fffbaff6(void)

{
  DAT_00012160 = 0;
  DAT_00012161 = 0;
  DAT_00012162 = 0;
  DAT_00012163 = 0;
  DAT_00012164 = 0;
  return;
}


// ===== FUN_fffbb024 @ fffbb024 (231 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb098) */
/* WARNING: Removing unreachable block (ram,0xfffbb108) */

undefined4 FUN_fffbb024(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  byte local_6;
  
  if (param_1 != '\0') {
    cat_apo_reset();
  }
  if (param_1 != '\x02') {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar4 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      *(undefined1 *)((int)&DAT_000120bc + (uint)bVar2) = 0;
    }
    uVar1 = (uint)bVar2;
    bVar4 = (byte)(1 << (uint)(bVar4 & 7));
    if (param_1 == '\x01') {
      *(byte *)((int)&DAT_000120bc + uVar1) = *(byte *)((int)&DAT_000120bc + uVar1) | bVar4;
      FUN_fffbb185();
    }
    else {
      *(byte *)((int)&DAT_000120bc + uVar1) = *(byte *)((int)&DAT_000120bc + uVar1) & ~bVar4;
      FUN_fffbb1c2();
    }
    uVar3 = FUN_fffbb16b(DAT_0001fa38);
    DAT_0001fa38 = (short)uVar3;
    return uVar3;
  }
  for (local_6 = 0; local_6 < 3; local_6 = local_6 + 1) {
    bVar2 = (byte)(DAT_0001fa38 >> 3);
    bVar4 = (byte)DAT_0001fa38;
    if ((DAT_0001fa38 & 7) == 0) {
      *(undefined1 *)((int)&DAT_000120bc + (uint)bVar2) = 0;
    }
    *(byte *)((int)&DAT_000120bc + (uint)bVar2) =
         *(byte *)((int)&DAT_000120bc + (uint)bVar2) | (byte)(1 << (bVar4 & 7));
    DAT_0001fa38 = FUN_fffbb16b(DAT_0001fa38);
  }
  uVar3 = FUN_fffbb185();
  return uVar3;
}


// ===== FUN_fffbb10b @ fffbb10b (96 bytes)

undefined1 FUN_fffbb10b(void)

{
  int iVar1;
  undefined1 local_2;
  
  local_2 = 0;
  iVar1 = FUN_fffb23f3(0x1b);
  if (iVar1 == 1) {
    if (6 < DAT_0001fa38) {
      DAT_0001fa38 = DAT_0001fa38 - 7;
    }
    DAT_0001fa3a = DAT_0001fa38;
    local_2 = 1;
  }
  else if (0x4b0 < DAT_0001fa38) {
    DAT_0001fa38 = 0x4b0;
    DAT_0001fa3a = 0x4b0;
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffbb16b @ fffbb16b (26 bytes)

ushort FUN_fffbb16b(short param_1)

{
  undefined2 local_2;
  
  local_2 = param_1 + 1;
  if (0x4ff < local_2) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffbb185 @ fffbb185 (61 bytes)

void FUN_fffbb185(void)

{
  uint uVar1;
  undefined1 uStack_1;
  
  uVar1 = FUN_fffb3196(1);
  if (uVar1 < 2) {
    uStack_1 = DAT_00009bfc;
  }
  else {
    uStack_1 = DAT_00009bfd;
  }
  if (uStack_1 == '\0') {
    return;
  }
  FUN_fffb2da6(4);
  DAT_0001215e = 1;
  return;
}


// ===== FUN_fffbb1c2 @ fffbb1c2 (27 bytes)

void FUN_fffbb1c2(void)

{
  if (DAT_0001215e != '\x01') {
    return;
  }
  FUN_fffb2df4();
  DAT_0001215e = 0;
  return;
}


// ===== FUN_fffbb1dd @ fffbb1dd (166 bytes)

void FUN_fffbb1dd(char param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = FUN_fffba192();
  bVar1 = false;
  iVar4 = FUN_fffb6ec5();
  if ((iVar4 != 1) && (1 < iVar4 - 3U)) {
    if (iVar4 == 7) {
      bVar1 = true;
      goto LAB_fffbb21f;
    }
    if (iVar4 != 8 && iVar4 != 9) goto LAB_fffbb21f;
  }
  if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar1 = true;
  }
LAB_fffbb21f:
  if (bVar1) {
    FUN_fffb6fd2(param_1);
    FUN_fffb7011(param_1);
  }
  if ((DAT_00009aa0 == '\x01') && (param_1 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((DAT_00020b18 == '\x03') && (DAT_00020b2a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b2a = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffbb283 @ fffbb283 (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb2a9) */
/* WARNING: Removing unreachable block (ram,0xfffbb2bc) */

undefined4 FUN_fffbb283(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (DAT_00009aa8 != '\0') {
    uVar1 = FUN_fffb6ef3();
    *param_2 = uVar1;
    uVar2 = FUN_fffb6f0b();
    *param_1 = (char)uVar2;
    return uVar2;
  }
  uVar1 = FUN_fffb6ef3();
  *param_1 = uVar1;
  uVar2 = FUN_fffb6f0b();
  *param_2 = (char)uVar2;
  return uVar2;
}


// ===== FUN_fffbb2bf @ fffbb2bf (121 bytes)

char FUN_fffbb2bf(char param_1)

{
  char local_1;
  
  if (param_1 == '1') {
    if (3 < DAT_00009aaa - 1) {
      return '1';
    }
    return 'A';
  }
  if (param_1 == '2') {
    if (DAT_00009aaa != 1 && DAT_00009aaa != 2) {
      return '2';
    }
    return 'U';
  }
  if (param_1 == '9') {
    if (5 < DAT_00009aaa - 1) {
      return '9';
    }
    return 'N';
  }
  if (param_1 != '0') {
    return param_1;
  }
  if ((DAT_00009aaa == 6) || (DAT_00009aaa == 2)) {
LAB_fffbb32d:
    local_1 = 'T';
  }
  else {
    if (DAT_00009aaa != 3) {
      if (DAT_00009aaa == 4) goto LAB_fffbb32d;
      if ((DAT_00009aaa != 5) && (DAT_00009aaa != 1)) {
        return '0';
      }
    }
    local_1 = 'O';
  }
  return local_1;
}


// ===== FUN_fffbb338 @ fffbb338 (559 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb382) */
/* WARNING: Removing unreachable block (ram,0xfffbb408) */
/* WARNING: Removing unreachable block (ram,0xfffbb417) */
/* WARNING: Removing unreachable block (ram,0xfffbb3c5) */
/* WARNING: Removing unreachable block (ram,0xfffbb373) */
/* WARNING: Removing unreachable block (ram,0xfffbb51a) */
/* WARNING: Removing unreachable block (ram,0xfffbb440) */

void FUN_fffbb338(byte param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  byte local_13;
  byte local_11;
  byte bStack_f;
  byte local_e;
  ushort uStack_6;
  ushort uStack_4;
  
  bVar1 = (&DAT_0000969f)[(uint)param_1 * 0x33];
  bVar5 = false;
  local_11 = 0;
  while( true ) {
    if (bVar1 <= local_11) {
      return;
    }
    bVar2 = (&DAT_000096a0)[(uint)local_11 + (uint)param_1 * 0x33];
    bVar7 = (&DAT_fff815c3)[(uint)bVar2 * 2];
    local_13 = (&DAT_fff815c4)[(uint)bVar2 * 2];
    if (bVar2 == 0x23) {
      uStack_6 = FUN_fffba30c();
      bVar4 = false;
      uStack_4 = 1000;
      for (bStack_f = 0; bStack_f < 4; bStack_f = bStack_f + 1) {
        uVar9 = (uint)uStack_6;
        if (uStack_4 != 0) {
          uVar9 = uVar9 / uStack_4;
        }
        uVar8 = uStack_6;
        if ((uStack_4 & 0xff) != 0) {
          uVar8 = (ushort)((uint)uStack_6 / (uStack_4 & 0xff));
        }
        uStack_6 = uStack_6 - (uVar8 * uStack_4 & 0xff);
        uStack_4 = uStack_4 / 10;
        cVar6 = nib2hex(uVar9 & 0xff);
        if ((cVar6 != '0') || (bVar4)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar3) || (bStack_f == 3)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          bVar4 = true;
          bVar7 = FUN_fffbb2bf(cVar6);
          bVar2 = (&DAT_fff815c3)[(uint)bVar7 * 2];
          local_13 = (&DAT_fff815c4)[(uint)bVar7 * 2];
          for (local_e = 0; local_e < bVar2; local_e = local_e + 1) {
            if ((local_13 & 0x80) == 0) {
              FUN_fffbb024(1);
            }
            else {
              FUN_fffbb024(2);
            }
            FUN_fffbb024(0);
            local_13 = local_13 << 1;
          }
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            FUN_fffbb024(0);
          }
        }
      }
    }
    else if (bVar2 == 0x3c) {
      uVar8 = FUN_fffba30c();
      if (uVar8 < 9999) {
        FUN_fffba336(uVar8 + 1);
      }
    }
    else if (bVar2 == 0x3e) {
      uVar8 = FUN_fffba30c();
      if (1 < uVar8) {
        FUN_fffba336(uVar8 - 1);
      }
    }
    else if (bVar2 == 0x5b) {
      bVar5 = true;
    }
    else if (bVar2 == 0x5d) {
      bVar5 = false;
    }
    else if (bVar2 == 0x5e) {
      local_11 = local_11 + 2;
    }
    else {
      local_e = 0;
      if (bVar7 == 0) {
        for (; local_e < 4; local_e = local_e + 1) {
          FUN_fffbb024(0);
        }
      }
      else {
        for (; local_e < bVar7; local_e = local_e + 1) {
          if ((local_13 & 0x80) == 0) {
            FUN_fffbb024(1);
          }
          else {
            FUN_fffbb024(2);
          }
          FUN_fffbb024(0);
          local_13 = local_13 << 1;
        }
        if (!bVar5) {
          for (local_e = 0; local_e < 2; local_e = local_e + 1) {
            FUN_fffbb024(0);
          }
        }
      }
    }
    if (0x4b0 < DAT_0001fa38) break;
    local_11 = local_11 + 1;
  }
  return;
}


// ===== FUN_fffbb567 @ fffbb567 (1020 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbb8cc) */
/* WARNING: Removing unreachable block (ram,0xfffbb7f9) */

void FUN_fffbb567(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  int iVar5;
  ushort uVar6;
  byte *local_10;
  byte *local_c;
  
  bVar1 = (&DAT_fff88cd7)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  bVar2 = (&DAT_fff88cd4)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  bVar3 = (bVar2 & 0x80) == 0;
  if (bVar3) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (bVar3) {
    local_10 = (byte *)((int)&DAT_00004761 +
                       (uint)(byte)(&DAT_000060b1)[bVar1] * 0x438 + (uint)bVar1 * 0x5a);
  }
  else {
    local_10 = &DAT_00005409 + (uint)(byte)(&DAT_000060bd)[bVar1] * 0x438 + (uint)bVar1 * 0x5a;
  }
  pbVar4 = local_c;
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar4 = *local_10;
    pbVar4 = pbVar4 + 1;
    local_10 = local_10 + 1;
  }
  if ((bVar2 & 0x20) == 0) {
    local_c[4] = local_c[4] & 0x7f;
  }
  else {
    local_c[4] = local_c[4] | 0x80;
  }
  if ((bVar2 & 8) == 0) {
    local_c[4] = local_c[4] & 0xef;
  }
  else {
    local_c[4] = local_c[4] | 0x10;
  }
  bVar1 = (&DAT_fff88cd5)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  if ((bVar1 & 8) == 0) {
    local_c[3] = local_c[3] & 0xfd;
  }
  else {
    local_c[3] = local_c[3] | 2;
  }
  if ((bVar1 & 4) == 0) {
    local_c[3] = local_c[3] & 0xfe;
  }
  else {
    local_c[3] = local_c[3] | 1;
  }
  if ((bVar1 & 2) == 0) {
    local_c[5] = local_c[5] & 0xfd;
  }
  else {
    local_c[5] = local_c[5] | 2;
  }
  if ((bVar1 & 1) == 0) {
    local_c[5] = local_c[5] & 0xfe;
  }
  else {
    local_c[5] = local_c[5] | 1;
  }
  bVar1 = (&DAT_fff88cd8)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  *local_c = *local_c & 0xf0;
  *local_c = bVar1 & 0xf | *local_c;
  DAT_00009c5b = (&DAT_fff88cd9)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
  if (((&DAT_fff88cd4)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc] & 0x40) != 0) {
    local_c[0x4a] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 0x18);
    local_c[0x4b] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 0x10);
    local_c[0x4c] =
         (byte)((uint)*(undefined4 *)
                       (&LAB_fff88cdc + (uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc) >> 8);
    local_c[0x4d] = (&LAB_fff88cdc)[(uint)*(ushort *)(PTR_DAT_00025d4c + 0x1de) * 0xc];
    PTR_DAT_00025d4c[0x40c] = 1;
  }
  DAT_00021048 = (undefined1 *)FUN_fffc7827();
  if ((*(ushort *)(PTR_DAT_00025d4c + 0x1de) < 0x45) ||
     (0xda < *(ushort *)(PTR_DAT_00025d4c + 0x1de))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (bVar3) {
    uVar6 = *(ushort *)(PTR_DAT_00025d4c + 0x1de) - 0x45;
    DAT_0001fa3e = uVar6 - ((uVar6 / 0xf) * 0xf & 0xff);
    if (DAT_0001fa3e < 3) {
      *DAT_00021048 = 100;
    }
    else if (DAT_0001fa3e < 6) {
      *DAT_00021048 = 0x32;
    }
    else if (DAT_0001fa3e < 9) {
      *DAT_00021048 = 0x14;
    }
    else if (DAT_0001fa3e < 0xc) {
      *DAT_00021048 = 10;
    }
    else if (DAT_0001fa3e < 0xf) {
      *DAT_00021048 = 5;
    }
  }
  else {
    if ((*(ushort *)(PTR_DAT_00025d4c + 0x1de) < 0xde) ||
       (0xe9 < *(ushort *)(PTR_DAT_00025d4c + 0x1de))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      DAT_0001fa3e = (*(short *)(PTR_DAT_00025d4c + 0x1de) - 0xdeU) -
                     (((ushort)(*(short *)(PTR_DAT_00025d4c + 0x1de) - 0xdeU) / 0xc) * 0xc & 0xff);
      if (DAT_0001fa3e < 3) {
        *DAT_00021048 = 0x32;
      }
      else if (DAT_0001fa3e < 6) {
        *DAT_00021048 = 0x14;
      }
      else if (DAT_0001fa3e < 9) {
        *DAT_00021048 = 10;
      }
      else if (DAT_0001fa3e < 0xc) {
        *DAT_00021048 = 5;
      }
    }
    else {
      *DAT_00021048 = 100;
    }
  }
  FUN_fffbba9f(*(undefined2 *)(PTR_DAT_00025d4c + 0x1de));
  FUN_fffbbb85(*(undefined2 *)(PTR_DAT_00025d4c + 0x1de));
  return;
}


// ===== FUN_fffbb963 @ fffbb963 (161 bytes)

void FUN_fffbb963(char param_1)

{
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (*(short *)(PTR_DAT_00025d4c + 0x1de) == 0) {
        *(undefined2 *)(PTR_DAT_00025d4c + 0x1de) = 0x104;
      }
      else {
        *(short *)(PTR_DAT_00025d4c + 0x1de) = *(short *)(PTR_DAT_00025d4c + 0x1de) + -1;
      }
      if (PTR_DAT_00025d4c[0x1dd] != '\0') {
        PTR_DAT_00025d4c[0x1dd] = PTR_DAT_00025d4c[0x1dd] + -1;
      }
    }
  }
  else {
    if ((ushort)(*(short *)(PTR_DAT_00025d4c + 0x1de) + 1U) < 0x105) {
      *(ushort *)(PTR_DAT_00025d4c + 0x1de) = *(short *)(PTR_DAT_00025d4c + 0x1de) + 1U;
    }
    else {
      *(undefined2 *)(PTR_DAT_00025d4c + 0x1de) = 0;
    }
    if ((byte)PTR_DAT_00025d4c[0x1dd] < 8) {
      PTR_DAT_00025d4c[0x1dd] = PTR_DAT_00025d4c[0x1dd] + '\x01';
    }
  }
  FUN_fffbb567();
  return;
}


// ===== FUN_fffbba04 @ fffbba04 (11 bytes)

void FUN_fffbba04(char param_1)

{
  FUN_fffbbbdc((int)param_1);
  return;
}


// ===== FUN_fffbba0f @ fffbba0f (31 bytes)

undefined1 FUN_fffbba0f(void)

{
  return 1;
}


// ===== FUN_fffbba2e @ fffbba2e (113 bytes)

void FUN_fffbba2e(void)

{
  short extraout_var;
  int iVar1;
  uint uVar2;
  
  if ((DAT_0001b4d7 != '\0') && (iVar1 = FUN_fffb23f3(0x42), iVar1 == 1)) {
    DAT_0001b4d8 = DAT_0001b4d8 + 1;
    FUN_fff9d7f0();
    DAT_0001ff64 = extraout_var + DAT_0001ff64;
    if (DAT_0001b4d8 < 0x10) {
      FUN_fffb237a(0x42,0x1e);
      return;
    }
    uVar2 = (uint)DAT_0001ff64;
    if (DAT_0001b4d8 != 0) {
      uVar2 = uVar2 / DAT_0001b4d8;
    }
    *DAT_00021044 = (char)uVar2;
    DAT_0001b4d7 = 0;
    return;
  }
  return;
}


// ===== FUN_fffbba9f @ fffbba9f (230 bytes)

void FUN_fffbba9f(ushort param_1)

{
  bool bVar1;
  ushort uVar2;
  undefined1 *local_8;
  
  if (param_1 != DAT_0001ff66) {
    if ((DAT_0001ff66 < 0x3a) || (0x44 < DAT_0001ff66)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uVar2 = DAT_0001ff66 * 0xf - 0x321;
      local_8 = PTR_DAT_00025d50 + uVar2;
      if (0xda < uVar2) {
        local_8 = local_8 + 3;
      }
      *local_8 = DAT_00012167;
      local_8[2] = DAT_00012168;
    }
    if ((param_1 < 0x3a) || (0x44 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uVar2 = param_1 * 0xf - 0x321;
      local_8 = PTR_DAT_00025d50 + uVar2;
      if (0xda < uVar2) {
        local_8 = local_8 + 3;
      }
      DAT_00012167 = *local_8;
      *local_8 = 0xff;
      DAT_00012168 = local_8[2];
      local_8[2] = 0xff;
    }
    DAT_0001ff66 = param_1;
    return;
  }
  return;
}


// ===== FUN_fffbbb85 @ fffbbb85 (87 bytes)

void FUN_fffbbb85(short param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != DAT_0001ff68) {
    if (DAT_0001ff68 == 0xf5) {
      puVar1 = (undefined1 *)FUN_fff99877();
      *puVar1 = DAT_00012169;
    }
    if (param_1 == 0xf5) {
      puVar1 = (undefined1 *)FUN_fff99877();
      DAT_00012169 = *puVar1;
      *puVar1 = 0x32;
    }
    DAT_0001ff68 = param_1;
    return;
  }
  return;
}


// ===== FUN_fffbbbdc @ fffbbbdc (46 bytes)

void FUN_fffbbbdc(char param_1)

{
  if (*(short *)(PTR_DAT_00025d4c + 0x1de) == 2) {
    FUN_fffbbc0a(0x19,0xe6,(int)param_1);
    return;
  }
  FUN_fffbbc0a(0,0xff,(int)param_1);
  return;
}


// ===== FUN_fffbbc0a @ fffbbc0a (74 bytes)

void FUN_fffbbc0a(byte param_1,byte param_2,char param_3)

{
  short sVar1;
  byte *pbVar2;
  byte local_a;
  
  pbVar2 = PTR_DAT_00025d50 + *(ushort *)(PTR_DAT_00025d4c + 0x1de);
  sVar1 = (ushort)*pbVar2 + (short)param_3;
  if ((short)(ushort)param_2 < sVar1) {
    *pbVar2 = param_2;
    return;
  }
  if ((short)(ushort)param_1 <= sVar1) {
    local_a = (byte)sVar1;
    *pbVar2 = local_a;
    return;
  }
  *pbVar2 = param_1;
  return;
}


// ===== FUN_fffbbd53 @ fffbbd53 (5 bytes)

void FUN_fffbbd53(void)

{
  FUN_fffc4d93();
  return;
}


// ===== FUN_fffbbd58 @ fffbbd58 (939 bytes)

void FUN_fffbbd58(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffc4d93();
  FUN_fffbc29f();
  FUN_fffcdb26();
  iVar2 = FUN_fffbc103();
  if (iVar2 == 1) {
    PTR_DAT_00025d54[0xa0] = 0;
  }
  if (DAT_0001b4db == '\x01') {
    iVar2 = FUN_fffb23f3(0x3f);
    if (iVar2 == 1) {
      DAT_0001b4db = '\0';
      PTR_DAT_00025d54[0xa0] = 1;
      PTR_DAT_00025d54[0x9d] = 2;
      *(ushort *)(PTR_DAT_00025d54 + 0x9e) = DAT_0001fa40;
    }
  }
  else if ((DAT_0001b4dc == '\x01') && (iVar2 = FUN_fffb23f3(0x40), iVar2 == 1)) {
    FUN_fffbc406();
    return;
  }
  if (PTR_DAT_00025d54[0xa0] != '\0') {
    PTR_DAT_00025d54[0xa0] = 0;
    if (PTR_DAT_00025d54[0x86] == '\x01') {
      DAT_0001216b = '\0';
    }
    if (DAT_0001216b == '\0') {
      if (PTR_DAT_00025d54[0x9d] == '\x01') {
        PTR_DAT_00025d54[0x409] = 0;
        DAT_0001216b = '\x01';
        DAT_0001216a = PTR_DAT_00025d54[0x9c];
        if (DAT_0001216a == '\x04') {
          FUN_fffbc464();
          return;
        }
        DAT_0001fa40 = *(ushort *)(PTR_DAT_00025d54 + 0x9e);
        DAT_0001216c = FUN_fffbc1d0(*(ushort *)(PTR_DAT_00025d54 + 0x9e));
        if ((DAT_0001216c == '\0') || (DAT_0001216c == '\x02')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          FUN_fffbc35f();
          if (PTR_DAT_00025d54[0x409] == '\0') {
            FUN_fffbc38e();
          }
        }
        else if (DAT_0001216c == '\x01') {
          FUN_fffbc35f();
        }
        if (DAT_0001fa40 == 0x340) {
          DAT_0001216b = '\0';
        }
        iVar2 = FUN_fffd4c17();
        if (iVar2 == 1) {
          DAT_0001216b = 0;
          FUN_fffd4c26();
          return;
        }
        if (DAT_0001fa40 < 0x300) {
          FUN_fffb237a(0x3f,1000);
          DAT_0001b4db = 1;
          return;
        }
      }
    }
    else if (DAT_0001216b == '\x01') {
      if (DAT_0001216a == '\x04') {
        DAT_0001216b = 0;
        return;
      }
      if (DAT_0001fa40 != *(ushort *)(PTR_DAT_00025d54 + 0x9e)) {
        if (DAT_0001216c == '\x02') {
          if (*(short *)(PTR_DAT_00025d54 + 0x9e) == 0x340) {
            DAT_0001216b = 1;
            return;
          }
          FUN_fffbc435();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if (PTR_DAT_00025d54[0x9d] == '\0') {
        if (DAT_0001216c == '\x01') {
          if (PTR_DAT_00025d54[0x409] == '\0') {
            FUN_fffbc38e();
          }
        }
        else if (DAT_0001216c == '\x02') {
          FUN_fffbc435();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if (PTR_DAT_00025d54[0x9d] != '\x02') {
        if (DAT_0001216c == '\x02') {
          FUN_fffbc435();
        }
        if (DAT_0001b4db == '\x01') {
          DAT_0001b4db = '\0';
        }
        DAT_0001216b = 0;
        return;
      }
      if ((DAT_0001216c == '\x01') || (DAT_0001216c == '\x02')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (PTR_DAT_00025d54[0x409] == '\0')) {
        FUN_fffbc3bd();
      }
      DAT_0001216b = '\x02';
      if ((DAT_0001fa40 == 0x300) && (PTR_DAT_00025d54[0x409] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0001216b = 0;
        return;
      }
    }
    else if (DAT_0001216b == '\x02') {
      if ((DAT_0001216c == '\x02') && (PTR_DAT_00025d54[0x409] == '\0')) {
        FUN_fffbc435();
      }
      if (DAT_0001b4dc == '\x01') {
        DAT_0001b4dc = '\0';
      }
      DAT_0001216b = 0;
      FUN_fffc2403();
      return;
    }
  }
  return;
}


// ===== FUN_fffbc103 @ fffbc103 (205 bytes)

undefined1 FUN_fffbc103(void)

{
  bool bVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d54[0xa0] == '\0') {
    local_2 = 0;
  }
  else {
    if ((PTR_DAT_00025d54[0x9c] == '\x04') || (*(short *)(PTR_DAT_00025d54 + 0x9e) != 0x340)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (PTR_DAT_00025d54[0x9d] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_DAT_00025d54[0x78] == '\x01') {
        PTR_DAT_00025d54[0x78] = 0;
        DAT_00020ccc = 0;
        if (DAT_00020b2e == '\x01') {
          DAT_00020b2e = '\0';
        }
      }
      else if (PTR_DAT_00025d54[0x78] == '\x02') {
        PTR_DAT_00025d54[0x78] = 0;
        DAT_00020ccc = 0;
      }
      PTR_DAT_00025d54[0x27] = 0;
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  return local_2;
}


// ===== FUN_fffbc1d0 @ fffbc1d0 (85 bytes)

undefined1 FUN_fffbc1d0(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_5;
  
  bVar2 = FUN_fffbc225(param_1);
  if (bVar2 == 0xff) {
    uStack_5 = *(undefined1 *)((int)&PTR_DAT_fff83164 + (uint)param_1);
  }
  else {
    uVar1 = (uint)bVar2;
    if (uVar1 < 0xd) {
      uStack_5 = *(undefined1 *)
                  ((int)&PTR_DAT_fff83164 + (uint)*(ushort *)(&DAT_fff88534 + uVar1 * 2));
    }
    else {
      uStack_5 = (&UNK_fff834b6)[uVar1];
    }
  }
  return uStack_5;
}


// ===== FUN_fffbc225 @ fffbc225 (122 bytes)

undefined1 FUN_fffbc225(short param_1)

{
  undefined1 local_4;
  
  local_4 = 0xff;
  if (param_1 == 0x35e) {
    local_4 = DAT_00009acb;
  }
  else if (param_1 == 0x34e) {
    local_4 = DAT_00009acd;
  }
  else if (param_1 == 0x35b) {
    local_4 = DAT_00009ac8;
  }
  else if (param_1 == 0x35c) {
    local_4 = DAT_00009ac9;
  }
  else if (param_1 == 0x35d) {
    local_4 = DAT_00009aca;
  }
  else if (param_1 == 0x348) {
    local_4 = DAT_00009acc;
  }
  return local_4;
}


// ===== FUN_fffbc29f @ fffbc29f (192 bytes)

void FUN_fffbc29f(void)

{
  byte bVar1;
  bool local_7;
  byte bStack_6;
  uint local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = *(uint *)(PTR_DAT_00025d54 + 0x450);
  }
  else {
    local_4 = *(uint *)(PTR_DAT_00025d54 + 0x454);
  }
  local_7 = DAT_00009dbd != '\0';
  bVar1 = FUN_fff9772f(local_7);
  if (local_4 < *(uint *)(PTR_DAT_00025d54 + 0x45c)) {
    local_4 = FUN_fffb3aee();
  }
  else {
    if (local_4 <=
        (*(int *)(&DAT_fff89d24 + (uint)bVar1 * 4) + *(int *)(PTR_DAT_00025d54 + 0x45c) & 0xffU)) {
      return;
    }
    local_4 = FUN_fffb3aee(local_4 - (*(uint *)(&DAT_fff89d24 + (uint)bVar1 * 4) & 0xff));
  }
  *(uint *)(PTR_DAT_00025d54 + 0x45c) = local_4;
  for (bStack_6 = 0; bStack_6 < 4; bStack_6 = bStack_6 + 1) {
    (&DAT_00009e82)[bStack_6] = (char)(local_4 >> ((3 - bStack_6 & 3) << 3));
  }
  FUN_fffb4e18(1,local_4);
  return;
}


// ===== FUN_fffbc35f @ fffbc35f (47 bytes)

undefined * FUN_fffbc35f(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&PTR_LAB_fff89d94)[DAT_0001fa40];
}


// ===== FUN_fffbc38e @ fffbc38e (47 bytes)

undefined * FUN_fffbc38e(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&PTR_LAB_fff8ab10)[DAT_0001fa40];
}


// ===== FUN_fffbc3bd @ fffbc3bd (73 bytes)

undefined * FUN_fffbc3bd(void)

{
  bool bVar1;
  char extraout_R1;
  undefined *puVar2;
  
  puVar2 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if ((extraout_R1 == '\0') &&
     (puVar2 = (undefined *)(uint)DAT_0001fa40, puVar2 != (undefined *)0x300)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return (&PTR_LAB_fff8b88c)[DAT_0001fa40];
  }
  return puVar2;
}


// ===== FUN_fffbc406 @ fffbc406 (47 bytes)

undefined * FUN_fffbc406(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&PTR_LAB_fff8c608)[DAT_0001fa40];
}


// ===== FUN_fffbc435 @ fffbc435 (47 bytes)

undefined * FUN_fffbc435(void)

{
  char extraout_R1;
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_fffc519d(DAT_0001fa40,0);
  if (extraout_R1 == '\0') {
    return puVar1;
  }
  return (&PTR_LAB_fff8d384)[DAT_0001fa40];
}


// ===== FUN_fffbc464 @ fffbc464 (405 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc507) */
/* WARNING: Removing unreachable block (ram,0xfffbc500) */
/* WARNING: Removing unreachable block (ram,0xfffbc55d) */

void FUN_fffbc464(ushort param_1)

{
  uint uVar1;
  int iVar2;
  int in_stack_00000014;
  bool bStack_15;
  int iStack_10;
  undefined1 *puStack_8;
  
  iVar2 = FUN_fffc8ca8();
  if (iVar2 == 1) {
    if (PTR_DAT_00025d54[0x1c2] == '\b') {
      FUN_fffc23b6();
      return;
    }
    FUN_fffc8beb();
    return;
  }
  iVar2 = FUN_fffc90ed();
  if (iVar2 != 1) {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc4caa();
    if (PTR_DAT_00025d54[0x418] == '\x01') {
      FUN_fffe5ce0();
    }
    if (DAT_00009dbd == '\0') {
      puStack_8 = &DAT_00009d09;
    }
    else {
      puStack_8 = &DAT_00009d63;
    }
    bStack_15 = DAT_00009dbd != '\0';
    iVar2 = FUN_fff9772f(bStack_15);
    uVar1 = *(uint *)(&DAT_fff89d24 + iVar2 * 4);
    if (DAT_00009c35 == '\0') {
      iStack_10 = ((uint)(byte)puStack_8[0x4a] << 0x18 | (uint)(byte)puStack_8[0x4d]) -
                  (uVar1 >> 1 & 0xff);
    }
    else if (DAT_00009c35 == '\x01') {
      iStack_10 = DAT_00020f60;
    }
    else {
      iStack_10 = FUN_fffb4ebe(2);
    }
    if (param_1 < 0x317) {
      iStack_10 = (uVar1 * in_stack_00000014) / 0x316 + iStack_10;
      iVar2 = FUN_fffb3aa1(iStack_10);
      if (iVar2 != 0) {
        puStack_8[0x4a] = (char)((uint)iStack_10 >> 0x18);
        puStack_8[0x4b] = (char)((uint)iStack_10 >> 0x10);
        puStack_8[0x4c] = (char)((uint)iStack_10 >> 8);
        puStack_8[0x4d] = (undefined1)iStack_10;
        FUN_fffc16f6(DAT_00009dbd);
        iVar2 = FUN_fffc2d93(DAT_00009dbd);
        if (iVar2 == 1) {
          if (DAT_00009dbd == '\0') {
            DAT_00009dbe = 3;
          }
          else {
            DAT_00009dbf = 3;
          }
        }
        PTR_DAT_00025d54[0x40c] = 1;
        FUN_fffb2da6(1);
        return;
      }
      FUN_fffb2da6(3);
      return;
    }
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffbc605 @ fffbc605 (51 bytes)

void FUN_fffbc605(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc65b();
    return;
  }
  FUN_fffe5ce0();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbc638 @ fffbc638 (35 bytes)

bool FUN_fffbc638(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d54[0x95];
  if (cVar1 != '\0') {
    FUN_fffd1712();
  }
  return cVar1 != '\0';
}


// ===== FUN_fffbc65b @ fffbc65b (28 bytes)

void FUN_fffbc65b(void)

{
  FUN_fffc8beb();
  FUN_fffb2da6(1);
  if (DAT_00009c35 == '\x02') {
    return;
  }
  FUN_fffbc677();
  return;
}


// ===== FUN_fffbc677 @ fffbc677 (114 bytes)

void FUN_fffbc677(void)

{
  PTR_DAT_00025d54[0x409] = 1;
  if (DAT_00009c35 == '\x02') {
    DAT_00009c35 = 0;
    PTR_DAT_00025d54[0x40c] = 1;
    return;
  }
  if (DAT_00009c35 == '\x01') {
    DAT_00009c35 = 2;
    PTR_DAT_00025d54[0x40c] = 1;
    return;
  }
  if (DAT_00009c35 != '\0') {
    return;
  }
  FUN_fffbc6e9();
  DAT_00009c35 = 1;
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== FUN_fffbc6e9 @ fffbc6e9 (149 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc778) */
/* WARNING: Removing unreachable block (ram,0xfffbc77b) */

undefined4 FUN_fffbc6e9(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool local_b;
  byte bStack_a;
  int local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = *(int *)(PTR_DAT_00025d54 + 0x450);
  }
  else {
    local_8 = *(int *)(PTR_DAT_00025d54 + 0x454);
  }
  local_b = DAT_00009dbd != '\0';
  cVar1 = band_of_freq(local_8);
  if (cVar1 == -1) {
    return 0xff;
  }
  iVar2 = FUN_fff9772f(local_b);
  uVar4 = local_8 - (*(uint *)(&DAT_fff89d24 + iVar2 * 4) >> 1 & 0xff);
  *(uint *)(PTR_DAT_00025d54 + 0x45c) = uVar4;
  for (bStack_a = 0; bStack_a < 4; bStack_a = bStack_a + 1) {
    (&DAT_00009e82)[bStack_a] = (char)(uVar4 >> ((3 - bStack_a & 3) << 3));
  }
  uVar3 = FUN_fffb4e18(1,uVar4);
  return uVar3;
}


// ===== FUN_fffbd074 @ fffbd074 (69 bytes)

void FUN_fffbd074(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffb2da6(1);
    FUN_fffc5290();
    return;
  }
  FUN_fffe5ce0();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbd16c @ fffbd16c (20 bytes)

void FUN_fffbd16c(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbd1e8 @ fffbd1e8 (20 bytes)

void FUN_fffbd1e8(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x02') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbd249 @ fffbd249 (20 bytes)

void FUN_fffbd249(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x03') {
    return;
  }
  FUN_fffc078d();
  return;
}

