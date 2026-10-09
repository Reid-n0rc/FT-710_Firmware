// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== FUN_00084e38 @ 00084e38 (94 bytes)

/* WARNING: Removing unreachable block (ram,0x00084e94) */

void FUN_00084e38(void)

{
  FUN_000875f0(0,&DAT_00087e84,&DAT_00088b78);
  FUN_000872f8(&DAT_00088b78,0,0x400,0x100);
  FUN_000875f0(1,&DAT_00087e86,&DAT_00088bb4);
  FUN_000872f8(&DAT_00088bb4,0,0x400,0x100);
  FUN_000875f0(2,&DAT_00087e86,&DAT_00088bf0);
  FUN_000872f8(&DAT_00088bf0,0,0x400,0x100);
  return;
}


// ===== vsnprintf_core @ 00084eb0 (2778 bytes)

uint vsnprintf_core(int *param_1,undefined4 param_2,uint param_3,int param_4,byte *param_5,
                   uint *param_6,code *param_7)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint *puVar11;
  char *pcVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  undefined4 *puVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  uint local_88;
  uint local_84;
  uint local_70;
  uint local_60;
  char *local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  char acStack_48 [36];
  
  local_88 = 0;
LAB_00084ec2:
  while( true ) {
    pbVar18 = param_5 + 1;
    bVar2 = *param_5;
    if (bVar2 == 0) {
      return local_88;
    }
    uVar5 = (int)local_88 >> 0x1f;
    if (bVar2 == 0x25) break;
    bVar25 = local_88 < param_3;
    local_88 = local_88 + 1;
    param_5 = pbVar18;
    if ((int)((uVar5 - param_4) - (uint)bVar25) < 0 !=
        (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)bVar25))) {
      iVar7 = param_1[2];
      param_1[2] = iVar7 + -1;
      if (iVar7 + -1 < 0) {
        FUN_000874b0(bVar2,param_1);
      }
      else {
        pbVar18 = (byte *)*param_1;
        *param_1 = (int)(pbVar18 + 1);
        *pbVar18 = bVar2;
      }
    }
  }
  uVar23 = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          param_5 = pbVar18 + 1;
          uVar16 = (uint)*pbVar18;
          if (uVar16 != 0x2b) break;
          uVar23 = uVar23 | 2;
          pbVar18 = param_5;
        }
        if (uVar16 < 0x2c) break;
        if (uVar16 == 0x2d) {
          uVar23 = uVar23 | 1;
          pbVar18 = param_5;
        }
        else {
          if (uVar16 != 0x30) goto LAB_00084f3a;
          uVar23 = uVar23 | 0x200;
          pbVar18 = param_5;
        }
      }
      if (uVar16 != 0x20) break;
      uVar23 = uVar23 | 4;
      pbVar18 = param_5;
    }
    if (uVar16 != 0x23) break;
    uVar23 = uVar23 | 8;
    pbVar18 = param_5;
  }
LAB_00084f3a:
  if (uVar16 == 0x2a) {
    uVar21 = *param_6;
    uVar16 = (uint)*param_5;
    if ((int)uVar21 < 0) {
      uVar21 = -uVar21;
      uVar23 = uVar23 ^ 1;
    }
    param_5 = pbVar18 + 2;
    param_6 = param_6 + 1;
  }
  else {
    uVar21 = 0;
    while ((uVar16 - 0x30 & 0xff) < 10) {
      uVar21 = uVar21 * 10 + (uVar16 - 0x30);
      uVar16 = (uint)*param_5;
      param_5 = param_5 + 1;
    }
  }
  uVar8 = uVar21 & ~((int)uVar21 >> 0x1f);
  puVar14 = param_6;
  if (uVar16 == 0x2e) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x2a) {
      puVar14 = param_6 + 1;
      uVar24 = *param_6;
      uVar16 = (uint)param_5[1];
      param_5 = param_5 + 2;
    }
    else {
      uVar24 = 0;
      while( true ) {
        param_5 = param_5 + 1;
        if (9 < (uVar16 - 0x30 & 0xff)) break;
        uVar24 = uVar24 * 10 + (uVar16 - 0x30);
        uVar16 = (uint)*param_5;
      }
    }
    if ((int)uVar24 < 0) goto LAB_00085002;
    uVar23 = uVar23 | 0x10;
  }
  else {
LAB_00085002:
    uVar24 = 0;
  }
  if (uVar16 == 0x6c) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x6c) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x60;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x20;
    }
  }
  if ((uVar16 == 0x4c) || (uVar16 == 0x71)) {
    bVar2 = *param_5;
    uVar23 = uVar23 | 0x60;
LAB_00084ffe:
    uVar16 = (uint)bVar2;
    param_5 = param_5 + 1;
  }
  else {
    if (uVar16 != 0x68) {
      if (uVar16 == 0x6a) {
        uVar23 = uVar23 | 0x40;
      }
      else if ((uVar16 != 0x7a) && (uVar16 != 0x74)) goto LAB_0008502a;
      bVar2 = *param_5;
      goto LAB_00084ffe;
    }
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x68) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x100;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x80;
    }
  }
LAB_0008502a:
  param_6 = puVar14;
  if (0x78 < uVar16) goto switchD_000850fe_caseD_59;
  if (uVar16 < 0x58) {
    if (uVar16 == 0x41) {
switchD_000850fe_caseD_61:
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 0xd;
        uVar23 = uVar23 | 0x10;
      }
switchD_000850fe_caseD_65:
      puVar20 = (undefined4 *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar20 + 2;
      local_50 = *puVar20;
      uStack_4c = puVar20[1];
      uVar21 = 0;
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 6;
      }
      uVar6 = 0;
      pcVar3 = (char *)0x0;
      local_5c = (char *)0x0;
      uVar23 = uVar23 | 0x400;
      goto LAB_00085464;
    }
    if (uVar16 < 0x42) {
      if (uVar16 != 0) goto switchD_000850fe_caseD_59;
      param_5 = param_5 + -1;
      goto LAB_00084ec2;
    }
    if ((uVar16 & 0xfffffffd) == 0x45) goto switchD_000850fe_caseD_65;
switchD_000850fe_caseD_59:
    iVar7 = uVar8 - 1;
    if ((uVar23 & 1) == 0) {
      uVar24 = local_88;
      iVar19 = iVar7;
      if ((uVar23 & 0x200) == 0) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x30;
      }
      while (-1 < iVar19 + -1) {
        if ((int)((uVar5 - param_4) - (uint)(uVar24 < param_3)) < 0 !=
            (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar24 < param_3)))) {
          iVar22 = param_1[2];
          param_1[2] = iVar22 + -1;
          if (iVar22 + -1 < 0) {
            FUN_000874b0(uVar4,param_1);
          }
          else {
            puVar9 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar9 + 1);
            *puVar9 = uVar4;
          }
        }
        uVar5 = uVar5 + (0xfffffffe < uVar24);
        uVar24 = uVar24 + 1;
        iVar19 = iVar19 + -1;
      }
      if ((int)uVar21 < 1) {
        iVar7 = 0;
      }
      iVar19 = 1 - uVar8;
      if ((int)uVar21 < 1) {
        iVar19 = 0;
      }
      local_88 = iVar7 + local_88;
      iVar7 = iVar19 + (uVar8 - 2);
    }
    uVar5 = local_88 + 1;
    iVar19 = (int)local_88 >> 0x1f;
    if ((int)((iVar19 - param_4) - (uint)(local_88 < param_3)) < 0 !=
        (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(local_88 < param_3)))) {
      iVar19 = param_1[2];
      param_1[2] = iVar19 + -1;
      if (iVar19 + -1 < 0) {
        FUN_000874b0(uVar16,param_1);
      }
      else {
        puVar9 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar9 + 1);
        *puVar9 = (char)uVar16;
      }
    }
    local_88 = uVar5;
    if ((uVar23 & 1) != 0) {
      iVar19 = (int)uVar5 >> 0x1f;
      uVar23 = uVar5;
      iVar22 = iVar7;
      while (iVar22 = iVar22 + -1, -1 < iVar22) {
        if ((int)((iVar19 - param_4) - (uint)(uVar23 < param_3)) < 0 !=
            (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(uVar23 < param_3)))) {
          iVar10 = param_1[2];
          param_1[2] = iVar10 + -1;
          if (iVar10 + -1 < 0) {
            FUN_000874b0(0x20,param_1);
          }
          else {
            puVar9 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar9 + 1);
            *puVar9 = 0x20;
          }
        }
        bVar25 = 0xfffffffe < uVar23;
        uVar23 = uVar23 + 1;
        iVar19 = iVar19 + (uint)bVar25;
      }
      if (-1 < iVar7) {
        local_88 = uVar5 + iVar7;
      }
    }
    goto LAB_00084ec2;
  }
  switch(uVar16) {
  case 0x58:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0X";
    if ((uVar23 & 8) == 0) {
      local_5c = "";
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789ABCDEF";
    break;
  default:
    goto switchD_000850fe_caseD_59;
  case 0x61:
    goto switchD_000850fe_caseD_61;
  case 99:
    param_6 = puVar14 + 1;
    uVar16 = *puVar14;
    goto switchD_000850fe_caseD_59;
  case 100:
  case 0x69:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = (int)uVar21 >> 0x1f;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar6 = (int)(uVar21 << 0x18) >> 0x1f;
        uVar21 = (uint)(char)uVar21;
      }
    }
    else {
      uVar6 = (int)(uVar21 << 0x10) >> 0x1f;
      uVar21 = (uint)(short)uVar21;
    }
    if ((int)uVar6 < 0) {
      bVar25 = uVar21 != 0;
      uVar21 = -uVar21;
      local_5c = "-";
      uVar6 = -uVar6 - (uint)bVar25;
    }
    else {
      if ((uVar23 & 2) == 0) {
        local_5c = " ";
        uVar15 = uVar23 & 4;
        goto LAB_000854ea;
      }
      local_5c = "+";
    }
    goto LAB_00085596;
  case 0x65:
  case 0x66:
  case 0x67:
    goto switchD_000850fe_caseD_65;
  case 0x6e:
    puVar11 = (uint *)*puVar14;
    param_6 = puVar14 + 1;
    if ((uVar23 & 0x40) == 0) {
      if ((uVar23 & 0x20) == 0) {
        if ((uVar23 & 0x100) != 0) {
          *(char *)puVar11 = (char)local_88;
          goto LAB_00084ec2;
        }
        if ((uVar23 & 0x80) != 0) {
          *(short *)puVar11 = (short)local_88;
          goto LAB_00084ec2;
        }
      }
      *puVar11 = local_88;
      goto LAB_00084ec2;
    }
    *puVar11 = local_88;
    puVar11[1] = uVar5;
    goto LAB_00084ec2;
  case 0x6f:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0";
    uVar15 = uVar23 & 8;
LAB_000854ea:
    if (uVar15 == 0) {
      local_5c = "";
    }
LAB_00085596:
    pcVar3 = (char *)0x0;
    if ((uVar23 & 0x10) != 0) {
      pcVar3 = (char *)0x0;
      uVar23 = uVar23 & 0xfffffdff;
    }
    break;
  case 0x70:
    uVar6 = 0;
    param_6 = puVar14 + 1;
    uVar21 = *puVar14;
    pcVar3 = "0123456789abcdef";
    local_5c = "0x";
    break;
  case 0x73:
    goto switchD_000850fe_caseD_73;
  case 0x75:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = (char *)0x0;
    local_5c = "";
    break;
  case 0x78:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0x";
    if ((uVar23 & 8) == 0) {
      local_5c = "";
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789abcdef";
  }
LAB_00085464:
  uVar15 = param_3 - local_88;
  local_58 = -1;
  local_54 = -1;
  iVar19 = (param_4 - uVar5) - (uint)(param_3 < local_88);
  iVar7 = 0;
  pcVar12 = acStack_48;
  do {
    iVar7 = iVar7 + 1;
    *pcVar12 = 'U';
    pcVar12 = pcVar12 + 1;
  } while (iVar7 != 0x20);
  local_60 = uVar24;
  if ((uVar23 & 0x410) == 0) {
    local_60 = 1;
  }
  pcVar12 = acStack_48;
  if (uVar16 < 0x6f) {
    if (uVar16 < 0x48) {
      if (0x40 < uVar16) {
        iVar7 = 0;
        if ((1 << (uVar16 - 0x41 & 0xff) & 0x51U) == 0) goto switchD_000855de_caseD_71;
switchD_000856e6_caseD_61:
        iVar7 = (*param_7)(uVar16,&local_50,acStack_48,uVar23,&local_5c,&local_60,&local_58,
                           &local_54);
        goto switchD_000855de_caseD_71;
      }
    }
    else {
      switch(uVar16) {
      case 0x58:
        iVar7 = 0;
        goto switchD_000855de_caseD_70;
      case 0x61:
      case 0x65:
      case 0x66:
      case 0x67:
        goto switchD_000856e6_caseD_61;
      case 100:
      case 0x69:
        goto switchD_000855de_caseD_75;
      }
    }
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    switch(uVar16) {
    case 0x6f:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 3 | uVar5) {
        uVar5 = uVar6 << 0x1d;
        iVar7 = iVar7 + 1;
        *pcVar12 = ((byte)uVar21 & 7) + 0x30;
        uVar6 = uVar6 >> 3;
        pcVar12 = pcVar12 + 1;
      }
      break;
    case 0x70:
    case 0x78:
switchD_000855de_caseD_70:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 4 | uVar5) {
        uVar5 = uVar6 << 0x1c;
        iVar7 = iVar7 + 1;
        *pcVar12 = pcVar3[uVar21 & 0xf];
        uVar6 = uVar6 >> 4;
        pcVar12 = pcVar12 + 1;
      }
      break;
    case 0x75:
switchD_000855de_caseD_75:
      iVar7 = 0;
      pcVar3 = acStack_48;
      for (; uVar21 != 0 || uVar6 != 0; uVar6 = uVar16 + (uVar5 >> 4) + (uint)CARRY4(uVar6,uVar24))
      {
        uVar5 = uVar21 >> 2 | uVar6 << 0x1e;
        uVar16 = uVar21 >> 1 | uVar6 << 0x1f;
        uVar24 = uVar16 + uVar5;
        uVar5 = (uVar6 >> 2) + (uVar6 >> 1) + (uint)CARRY4(uVar16,uVar5);
        uVar16 = uVar24 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 4) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar17 >> 8 | uVar5 * 0x1000000;
        uVar24 = uVar17 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 8) + (uint)CARRY4(uVar17,uVar16);
        uVar16 = uVar24 >> 0x10 | uVar5 * 0x10000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 0x10) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar5 + CARRY4(uVar17,uVar5);
        uVar24 = uVar17 + uVar5 >> 3 | uVar16 * 0x20000000;
        uVar17 = (uint)((ulonglong)uVar24 * 10);
        uVar16 = uVar16 >> 3;
        uVar5 = ((uVar6 + (0xfffffff9 < uVar21)) -
                (uVar16 * 10 + (int)((ulonglong)uVar24 * 10 >> 0x20))) - (uint)(uVar21 + 6 < uVar17)
        ;
        uVar6 = (uVar21 + 6) - uVar17 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar6 + uVar24;
        *pcVar3 = (char)uVar21 + '0' + (char)uVar17 * -10;
        iVar7 = iVar7 + 1;
        uVar21 = uVar17;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
switchD_000855de_caseD_71:
  if ((uVar23 & 0x400) == 0) {
    local_60 = local_60 - iVar7;
    if ((int)local_60 < 0) {
      local_60 = 0;
    }
  }
  else {
    local_60 = 0;
    if (0 < local_58) {
      local_60 = local_58 - 1;
    }
    if (0 < local_54) {
      local_60 = local_54 + -1 + local_60;
    }
  }
  iVar10 = iVar7 + local_60;
  iVar22 = FUN_0008737a(local_5c);
  local_84 = (uVar8 - iVar10) - iVar22;
  if ((uVar23 & 0x201) == 0) {
    iVar22 = 0;
    for (uVar5 = 0; -1 < (int)((local_84 - 1) - uVar5); uVar5 = uVar5 + 1) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar5 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          FUN_000874b0(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      iVar22 = iVar22 + (uint)(0xfffffffe < uVar5);
    }
    uVar5 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar5;
  }
  else {
    uVar5 = 0;
  }
  iVar22 = (int)uVar5 >> 0x1f;
  uVar16 = uVar5;
  while( true ) {
    pcVar3 = local_5c + 1;
    cVar1 = *local_5c;
    local_5c = pcVar3;
    if (cVar1 == '\0') break;
    uVar5 = uVar5 + 1;
    if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
        (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
      iVar10 = param_1[2];
      param_1[2] = iVar10 + -1;
      if (iVar10 + -1 < 0) {
        FUN_000874b0(cVar1,param_1);
      }
      else {
        pcVar3 = (char *)*param_1;
        *param_1 = (int)(pcVar3 + 1);
        *pcVar3 = cVar1;
      }
    }
    bVar25 = 0xfffffffe < uVar16;
    uVar16 = uVar16 + 1;
    iVar22 = iVar22 + (uint)bVar25;
  }
  if ((uVar23 & 1) == 0) {
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    local_70 = local_84;
    uVar16 = uVar5;
    while (local_70 = local_70 - 1, -1 < (int)local_70) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          FUN_000874b0(uVar4,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = uVar4;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    uVar16 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar16;
    uVar5 = uVar5 + uVar16;
  }
  iVar22 = 0;
  if ((uVar23 & 0x400) == 0) {
    iVar22 = (int)uVar5 >> 0x1f;
    uVar16 = uVar5;
    while (local_60 = local_60 - 1, -1 < (int)local_60) {
      uVar5 = uVar5 + 1;
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          FUN_000874b0(0x30,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x30;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    iVar10 = iVar7;
    uVar16 = uVar5;
    while (0 < iVar10) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar13 = param_1[2];
        cVar1 = acStack_48[iVar10 + -1];
        param_1[2] = iVar13 + -1;
        if (iVar13 + -1 < 0) {
          FUN_000874b0(cVar1,param_1);
        }
        else {
          pcVar3 = (char *)*param_1;
          *param_1 = (int)(pcVar3 + 1);
          *pcVar3 = cVar1;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
      iVar10 = iVar10 + -1;
    }
    if (-1 < iVar7) {
      uVar5 = uVar5 + iVar7;
    }
  }
  else {
    for (; iVar22 < iVar7; iVar22 = iVar22 + 1) {
      cVar1 = acStack_48[iVar22];
      iVar10 = (int)uVar5 >> 0x1f;
      uVar16 = uVar5;
      if (cVar1 == '<') {
        while (local_58 = local_58 + -1, -1 < local_58) {
          if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
              (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              FUN_000874b0(0x30,param_1);
            }
            else {
              puVar9 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar9 + 1);
              *puVar9 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else if (cVar1 == '>') {
        while (local_54 = local_54 + -1, -1 < local_54) {
          if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
              (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              FUN_000874b0(0x30,param_1);
            }
            else {
              puVar9 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar9 + 1);
              *puVar9 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else {
        uVar16 = uVar5 + 1;
        if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
            (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
          iVar10 = param_1[2];
          param_1[2] = iVar10 + -1;
          if (iVar10 + -1 < 0) {
            FUN_000874b0(cVar1,param_1);
          }
          else {
            pcVar3 = (char *)*param_1;
            *param_1 = (int)(pcVar3 + 1);
            *pcVar3 = cVar1;
          }
        }
      }
      uVar5 = uVar16;
    }
  }
  if ((uVar23 & 1) != 0) {
    iVar7 = (int)uVar5 >> 0x1f;
    uVar23 = uVar5;
    uVar16 = local_84;
    while (uVar16 = uVar16 - 1, -1 < (int)uVar16) {
      if ((int)((iVar7 - iVar19) - (uint)(uVar23 < uVar15)) < 0 !=
          (SBORROW4(iVar7,iVar19) != SBORROW4(iVar7 - iVar19,(uint)(uVar23 < uVar15)))) {
        iVar22 = param_1[2];
        param_1[2] = iVar22 + -1;
        if (iVar22 + -1 < 0) {
          FUN_000874b0(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar23;
      uVar23 = uVar23 + 1;
      iVar7 = iVar7 + (uint)bVar25;
    }
    if (-1 < (int)local_84) {
      uVar5 = uVar5 + local_84;
    }
  }
  local_88 = local_88 + uVar5;
  goto LAB_00084ec2;
switchD_000850fe_caseD_73:
  param_6 = puVar14 + 1;
  pcVar3 = (char *)*puVar14;
  if (pcVar3 == (char *)0x0) {
    pcVar3 = "(null)";
  }
  local_84 = FUN_0008737a(pcVar3);
  if (((uVar23 & 0x10) != 0) && ((int)uVar24 <= (int)local_84)) {
    local_84 = uVar24;
  }
  uVar8 = uVar8 - local_84;
  if ((uVar23 & 1) == 0) {
    uVar16 = local_88;
    uVar21 = uVar8;
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    while (-1 < (int)(uVar21 - 1)) {
      if ((int)((uVar5 - param_4) - (uint)(uVar16 < param_3)) < 0 !=
          (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar16 < param_3)))) {
        iVar7 = param_1[2];
        param_1[2] = iVar7 + -1;
        if (iVar7 + -1 < 0) {
          FUN_000874b0(uVar4,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = uVar4;
        }
      }
      uVar5 = uVar5 + (0xfffffffe < uVar16);
      uVar16 = uVar16 + 1;
      uVar21 = uVar21 - 1;
    }
    uVar5 = uVar8 & ~((int)uVar8 >> 0x1f);
    local_88 = local_88 + uVar5;
    uVar8 = (uVar8 - 1) - uVar5;
  }
  iVar7 = (int)local_88 >> 0x1f;
  uVar5 = local_88;
  for (iVar19 = 0; iVar19 < (int)local_84; iVar19 = iVar19 + 1) {
    if ((int)((iVar7 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
        (SBORROW4(iVar7,param_4) != SBORROW4(iVar7 - param_4,(uint)(uVar5 < param_3)))) {
      iVar22 = param_1[2];
      param_1[2] = iVar22 + -1;
      if (iVar22 + -1 < 0) {
        FUN_000874b0(pcVar3[iVar19],param_1);
      }
      else {
        pcVar12 = (char *)*param_1;
        *param_1 = (int)(pcVar12 + 1);
        *pcVar12 = pcVar3[iVar19];
      }
    }
    bVar25 = 0xfffffffe < uVar5;
    uVar5 = uVar5 + 1;
    iVar7 = iVar7 + (uint)bVar25;
  }
  if (-1 < (int)local_84) {
    local_88 = local_88 + local_84;
  }
  if ((uVar23 & 1) != 0) {
    iVar7 = (int)local_88 >> 0x1f;
    uVar5 = local_88;
    uVar23 = uVar8;
    while (uVar23 = uVar23 - 1, -1 < (int)uVar23) {
      if ((int)((iVar7 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
          (SBORROW4(iVar7,param_4) != SBORROW4(iVar7 - param_4,(uint)(uVar5 < param_3)))) {
        iVar19 = param_1[2];
        param_1[2] = iVar19 + -1;
        if (iVar19 + -1 < 0) {
          FUN_000874b0(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar5;
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + (uint)bVar25;
    }
    if (-1 < (int)uVar8) {
      local_88 = local_88 + uVar8;
    }
  }
  goto LAB_00084ec2;
}


// ===== FUN_00085a9c @ 00085a9c (102 bytes)

undefined4
FUN_00085a9c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  thunk_FUN_00087900(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54,extraout_r1,0xffffffff,0x7fffffff,param_2,&uStack_8,
                         &LAB_000872f4_1);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
    FUN_000874b0(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== snprintf @ 00085b08 (114 bytes)

undefined4 snprintf(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 local_5c [4];
  undefined4 *local_58;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_4;
  
  if (param_1 == (undefined1 *)0x0) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    param_2 = 1;
    param_1 = local_5c;
  }
  local_58 = &uStack_4;
  uStack_4 = param_4;
  thunk_FUN_00087900(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54,extraout_r1,param_2 + -1,0,param_3,local_58,&LAB_000872f4_1);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
    FUN_000874b0(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== sprintf @ 00085b80 (88 bytes)

undefined4 sprintf(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 *local_4c [2];
  int local_44;
  undefined4 local_40;
  
  thunk_FUN_00087900(local_4c,0,0x3c);
  local_40 = 10;
  local_44 = 0x7fffffff;
  local_4c[0] = param_1;
  uVar1 = vsnprintf_core(local_4c,extraout_r1,0xffffffff,0x7fffffff,param_2,param_3,&LAB_000872f4_1)
  ;
  local_44 = local_44 + -1;
  if (local_44 < 0) {
    FUN_000874b0(0,local_4c);
  }
  else {
    *local_4c[0] = 0;
  }
  return uVar1;
}


// ===== FUN_00085bdc @ 00085bdc (44 bytes)

int FUN_00085bdc(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_00087d84)[param_1];
  if ((int)(uVar1 << 0x1a) < 0) {
    param_1 = param_1 + -0x30;
  }
  else if ((int)(uVar1 << 0x1c) < 0) {
    param_1 = param_1 + -0x57;
  }
  else if ((int)(uVar1 << 0x1b) < 0) {
    param_1 = param_1 + -0x37;
  }
  else {
    param_1 = -1;
  }
  if (param_2 <= param_1) {
    param_1 = -1;
  }
  return param_1;
}


// ===== FUN_00085c0c @ 00085c0c (172 bytes)

uint FUN_00085c0c(byte *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  pbVar6 = param_1;
  do {
    pbVar5 = pbVar6;
    pbVar6 = pbVar5 + 1;
    uVar3 = (uint)*pbVar5;
    if (uVar3 == 0) goto LAB_00085c30;
  } while ((int)((uint)(byte)(&DAT_00087d84)[uVar3] << 0x1f) < 0);
  if (uVar3 == 0x30) {
    uVar3 = (uint)*pbVar6;
    pbVar6 = pbVar5 + 2;
    if ((uVar3 & 0xdf) == 0x58) {
      if ((param_3 & 0xffffffef) == 0) {
        param_3 = 0x10;
        uVar3 = (uint)pbVar5[2];
        pbVar6 = pbVar5 + 3;
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
      if (param_3 == 0) {
        param_3 = 8;
      }
    }
  }
  else {
LAB_00085c30:
    if (param_3 == 0) {
      param_3 = 10;
      bVar2 = false;
    }
    else {
      bVar2 = false;
    }
  }
  uVar7 = 0;
  uVar8 = 0;
  bVar1 = false;
  while (iVar4 = FUN_00085bdc(uVar3,param_3), -1 < iVar4) {
    uVar7 = uVar7 * param_3 + iVar4;
    uVar8 = uVar8 * param_3 + (uVar7 >> 0x10);
    if (0xffff < uVar8) {
      bVar1 = true;
    }
    bVar2 = true;
    uVar3 = (uint)*pbVar6;
    uVar7 = uVar7 & 0xffff;
    pbVar6 = pbVar6 + 1;
  }
  if (bVar2) {
    param_1 = pbVar6 + -1;
  }
  *param_2 = param_1;
  if (bVar1) {
    uVar7 = 0xffffffff;
    DAT_00088b74 = 0x22;
  }
  else {
    uVar7 = uVar7 | uVar8 << 0x10;
  }
  return uVar7;
}


// ===== FUN_00085cc0 @ 00085cc0 (128 bytes)

int FUN_00085cc0(byte *param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_24;
  undefined4 uStack_20;
  
  iVar1 = DAT_00088b74;
  pbVar5 = param_1;
  do {
    pbVar4 = pbVar5;
    pbVar5 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
    if (uVar3 == 0) {
      uVar6 = 0;
      pbVar5 = pbVar4;
      goto LAB_00085cfa;
    }
    uVar6 = (byte)(&DAT_00087d84)[uVar3] & 1;
  } while (((&DAT_00087d84)[uVar3] & 1) != 0);
  if (uVar3 != 0x2b) {
    if (uVar3 == 0x2d) {
      uVar6 = 0x200;
    }
    else {
      uVar6 = 0;
      pbVar5 = pbVar4;
    }
  }
LAB_00085cfa:
  DAT_00088b74 = 0;
  local_24 = param_2;
  uStack_20 = param_3;
  iVar2 = FUN_00085c0c(pbVar5,&local_24,param_3,0,param_1);
  if (param_2 != (byte *)0x0) {
    if (local_24 != pbVar5) {
      param_1 = local_24;
    }
    *(byte **)param_2 = param_1;
  }
  if ((DAT_00088b74 != 0x22) && (DAT_00088b74 = iVar1, uVar6 != 0)) {
    if (iVar2 < 0) {
      iVar2 = -1;
      DAT_00088b74 = 0x22;
    }
    else {
      iVar2 = -iVar2;
    }
  }
  return iVar2;
}


// ===== FUN_00085d48 @ 00085d48 (48 bytes)

undefined * FUN_00085d48(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (DAT_00088b6c == (undefined *)0x0) {
    DAT_00088b6c = &DAT_000a1ef8;
  }
  puVar3 = DAT_00088b6c;
  puVar2 = DAT_00088b6c + (param_1 + 3U & 0xfffffffc);
  iVar1 = FUN_00085f70(puVar2);
  if (iVar1 != 0) {
    puVar3 = (undefined *)0xffffffff;
    DAT_00088b74 = 0xc;
    puVar2 = DAT_00088b6c;
  }
  DAT_00088b6c = puVar2;
  return puVar3;
}


// ===== FUN_00085d84 @ 00085d84 (102 bytes)

undefined4 FUN_00085d84(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = *(uint *)(param_3 + 0xc);
  uVar4 = *(undefined4 *)(param_3 + 0x14);
  if ((int)(uVar3 << 0xb) < 0) {
    uVar1 = FUN_0008793a(uVar4);
    uVar3 = uVar3 | 0x10;
    *(undefined4 *)(param_3 + 0x18) = uVar1;
  }
  if ((uVar3 & 0x20010) != 0) {
    iVar2 = FUN_0008794c(uVar4,*(undefined4 *)(param_3 + 0x18));
    if (iVar2 < 0) goto LAB_00085db4;
    *(uint *)(param_3 + 0xc) = uVar3 & 0xfffdffef;
  }
  uVar3 = FUN_00087958(uVar4,param_1,param_2);
  *(uint *)(param_3 + 0x18) = (param_2 - (uVar3 & 0x7fffffff)) + *(int *)(param_3 + 0x18);
  if (uVar3 == 0) {
    return 0;
  }
LAB_00085db4:
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x80;
  return 0xffffffff;
}


// ===== FUN_00085df0 @ 00085df0 (50 bytes)

undefined4 FUN_00085df0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (param_1 == 0) {
    puVar4 = &DAT_00088b78;
    uVar3 = 0;
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      iVar1 = FUN_00087716(puVar4);
      if (iVar1 != 0) {
        uVar3 = 0xffffffff;
      }
      puVar4 = puVar4 + 0x3c;
    }
    return uVar3;
  }
  uVar3 = FUN_00087716();
  return uVar3;
}


// ===== FUN_00085e2c @ 00085e2c (252 bytes)

undefined4 FUN_00085e2c(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = param_1[3];
  if ((uVar4 & 0x100003) == 0) {
    return 2;
  }
  uVar5 = param_1[5];
  iVar1 = FUN_00087940(uVar5);
  if (iVar1 != 0) {
    return 2;
  }
  if (param_3 == 1) {
    iVar1 = FUN_00085f2c(param_1);
    param_2 = param_2 + iVar1;
  }
  else if (param_3 == 2) {
    uVar5 = FUN_0008793a(uVar5);
    if ((int)uVar5 < 0) {
      param_1[3] = param_1[3] | 0x80;
      return 1;
    }
    uVar3 = *param_1;
    if (uVar3 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar3 = (param_1[6] + uVar3) - param_1[4];
    if (((int)(param_1[3] << 0x1a) < 0) && ((int)uVar3 < (int)param_1[10])) {
      uVar3 = param_1[10];
    }
    if ((int)uVar3 < (int)uVar5) {
      uVar3 = uVar5;
    }
    param_2 = param_2 + uVar3;
  }
  else if (param_3 != 0) {
    return 2;
  }
  if ((int)param_2 < 0) {
    return 2;
  }
  if ((int)(uVar4 << 0x12) < 0) {
    if (param_1[0xb] < *param_1) {
      param_1[0xb] = *param_1;
    }
  }
  uVar5 = param_1[6];
  if ((int)uVar5 <= (int)param_2) {
    uVar3 = *param_1;
    if (*param_1 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar2 = param_1[4];
    if (((int)param_2 <= (int)((uVar3 + uVar5) - uVar2)) &&
       ((int)param_2 < (int)(uVar5 + param_1[0xc]))) {
      iVar1 = param_2 - uVar5;
      if ((int)(uVar4 << 0x1e) < 0) {
        param_1[2] = iVar1 - param_1[0xc];
      }
      bVar6 = (int)(uVar4 << 0x1f) < 0;
      if (bVar6) {
        uVar3 = iVar1 - (uVar3 - uVar2);
      }
      if (bVar6) {
        param_1[1] = uVar3;
      }
      *param_1 = iVar1 + uVar2;
      uVar4 = uVar4 & 0xffffffdf;
      goto LAB_00085eaa;
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  uVar4 = uVar4 | 0x20;
  param_1[10] = param_2;
LAB_00085eaa:
  param_1[3] = uVar4 & 0xfff7cfbf;
  return 0;
}


// ===== FUN_00085f2c @ 00085f2c (64 bytes)

int FUN_00085f2c(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[3];
  if ((uVar2 & 3) == 0) {
    DAT_00088b74 = 0x21;
    return -1;
  }
  if ((int)(uVar2 << 0xc) < 0) {
    if ((uVar2 & 0x20) == 0) {
      iVar1 = (*param_1 + param_1[6]) - param_1[4];
    }
    else {
      iVar1 = param_1[10];
    }
    return iVar1 + -1;
  }
  if ((uVar2 & 0x20) != 0) {
    return param_1[10];
  }
  return (*param_1 + param_1[6]) - param_1[4];
}


// ===== FUN_00085f70 @ 00085f70 (18 bytes)

/* WARNING: Removing unreachable block (ram,0x00085f7e) */

bool FUN_00085f70(undefined *param_1)

{
  return &DAT_000a2ef8 <= param_1;
}


// ===== console_puts @ 00085fae (20 bytes)

void console_puts(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0008737a();
  uart0_write(param_1,uVar1);
  return;
}


// ===== IpcRecvTask @ 00085fc6 (36 bytes)

void IpcRecvTask(int param_1)

{
  undefined1 auStack_a0 [152];
  
  do {
    do {
      FUN_00084ab0(auStack_a0);
      ipc_print_dsp_reply(auStack_a0);
    } while (*(int *)(param_1 + 4) == 0);
    FUN_00082b34(*(int *)(param_1 + 4),0,2);
  } while( true );
}


// ===== HardFault_Handler @ 00085fea (42 bytes)

void HardFault_Handler(void)

{
  undefined4 *puVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    puVar1 = (undefined4 *)getMainStackPointer();
  }
  else {
    puVar1 = (undefined4 *)getProcessStackPointer();
  }
  if (*(short *)puVar1[6] != -0x4155) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  puVar1[6] = (short *)puVar1[6] + 1;
  *puVar1 = 0x20;
  return;
}


// ===== FUN_00086014 @ 00086014 (48 bytes)

undefined4 FUN_00086014(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = param_1;
  do {
    uVar2 = FUN_0008737a(pbVar3);
    if (uVar2 <= (uint)((int)pbVar3 - (int)param_1)) {
      return 1;
    }
    pbVar4 = pbVar3 + 1;
    bVar1 = *pbVar3;
    pbVar3 = pbVar4;
  } while ((bVar1 - 0x30 < 10) || ((bVar1 & 0xffffffdf) - 0x41 < 6));
  return 0;
}


// ===== FUN_00086044 @ 00086044 (38 bytes)

bool FUN_00086044(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  
  cVar3 = '\0';
  pcVar2 = param_1 + param_2;
  for (; param_1 != pcVar2; param_1 = param_1 + 1) {
    cVar3 = cVar3 + *param_1;
  }
  cVar1 = FUN_00085cc0(param_1,0,0x10);
  return cVar1 == cVar3;
}


// ===== FUN_0008606a @ 0008606a (2 bytes)

void FUN_0008606a(void)

{
  return;
}


// ===== FUN_00086072 @ 00086072 (8 bytes)

void FUN_00086072(int param_1)

{
  if (param_1 != 0) {
    FUN_00081fd4();
    return;
  }
  return;
}


// ===== FUN_00086086 @ 00086086 (6 bytes)

void FUN_00086086(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== FUN_0008608c @ 0008608c (6 bytes)

void FUN_0008608c(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== FUN_00086092 @ 00086092 (6 bytes)

void FUN_00086092(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== FUN_000860a0 @ 000860a0 (32 bytes)

int FUN_000860a0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0xb) {
    iVar1 = FUN_00086952(10);
    *param_1 = iVar1;
    iVar1 = -(uint)(iVar1 == 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// ===== FUN_000860c4 @ 000860c4 (26 bytes)

void FUN_000860c4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00081944();
  if (iVar1 == 0) {
    FUN_00086c14(param_1,0xffffffff);
    return;
  }
  return;
}


// ===== FUN_000860de @ 000860de (28 bytes)

void FUN_000860de(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00081944();
  if (iVar1 == 0) {
    FUN_00086976(param_1,0,0,0);
    return;
  }
  return;
}


// ===== FUN_00086106 @ 00086106 (26 bytes)

int FUN_00086106(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00086916(param_2,param_3,0);
  *param_1 = iVar1;
  return -(uint)(iVar1 == 0);
}


// ===== FUN_00086120 @ 00086120 (78 bytes)

bool FUN_00086120(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  iVar1 = FUN_00081944();
  if (iVar1 == 0) {
    iVar1 = FUN_00086976(param_1,param_2,param_3,0);
    bVar2 = iVar1 == 1;
  }
  else {
    iVar1 = FUN_00086a8a(param_1,param_2,local_14,0);
    if ((iVar1 == 1) && (bVar2 = true, local_14[0] != 0)) {
      DAT_e000ed04 = 0x10000000;
    }
  }
  return bVar2;
}


// ===== FUN_0008616e @ 0008616e (74 bytes)

bool FUN_0008616e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  iVar1 = FUN_00081944();
  if (iVar1 == 0) {
    iVar1 = FUN_00086b1c(param_1,param_2,param_3);
    bVar2 = iVar1 == 1;
  }
  else {
    iVar1 = FUN_00086d48(param_1,param_2,local_14);
    if ((iVar1 == 1) && (bVar2 = true, local_14[0] != 0)) {
      DAT_e000ed04 = 0x10000000;
    }
  }
  return bVar2;
}


// ===== FUN_000861da @ 000861da (38 bytes)

undefined4 FUN_000861da(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  if ((param_1 == (int *)0x0) ||
     (uStack_8 = param_3,
     iVar1 = FUN_00086106(&local_c,*(undefined2 *)(*param_1 + 0x52),0xc,*param_1,param_1),
     iVar1 != 0)) {
    local_c = 0;
  }
  return local_c;
}


// ===== FUN_00086200 @ 00086200 (30 bytes)

void FUN_00086200(int *param_1,int param_2)

{
  if (param_2 != 0) {
    if (*param_1 != 0) {
      *(int *)(param_2 + 8) = *param_1;
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(int *)(*param_1 + 0xc) = param_2;
      *param_1 = param_2;
      return;
    }
    *param_1 = param_2;
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  return;
}


// ===== FUN_00086248 @ 00086248 (16 bytes)

void FUN_00086248(undefined4 *param_1,int param_2)

{
  for (; (param_1 != (undefined4 *)0x0 && (*(int *)*param_1 != param_2));
      param_1 = (undefined4 *)param_1[2]) {
  }
  return;
}


// ===== FUN_00086258 @ 00086258 (86 bytes)

void FUN_00086258(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_18;
  undefined4 local_14;
  
  puVar4 = *(undefined4 **)(param_1 + 100);
  uStack_18 = param_1;
  local_14 = param_2;
  if (puVar4 == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  while (puVar3 = (undefined4 *)(**(code **)(puVar4[8] + 8))(*puVar4,&local_14,(int)&uStack_18 + 2),
        puVar3 != (undefined4 *)0x0) {
    piVar1 = (int *)FUN_00086248(puVar4[2],puVar3[1]);
    if ((piVar1 == (int *)0x0) ||
       (iVar2 = (**(code **)(*piVar1 + 4))
                          (puVar3 + 4,*(undefined2 *)(puVar3 + 3),*puVar3,
                           *(undefined4 *)(*piVar1 + 8)), iVar2 != 1)) {
      (**(code **)(puVar4[8] + 0xc))(*puVar4,puVar3,local_14,uStack_18._2_2_);
    }
    else {
      *(undefined2 *)((int)puVar3 + 10) = uStack_18._2_2_;
    }
  }
  return;
}


// ===== FUN_000862b2 @ 000862b2 (144 bytes)

int * FUN_000862b2(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_r2;
  bool bVar5;
  
  if (param_1 == 0) {
    return (int *)0x0;
  }
  FUN_000860c4(*(undefined4 *)(param_1 + 0xc));
  if (param_2 == -1) {
    uVar4 = *(undefined4 *)(param_1 + 8);
    param_2 = 1;
    do {
      iVar1 = FUN_00086248(uVar4,param_2);
      if (iVar1 == 0) goto LAB_000862fa;
      bVar5 = param_2 != -2;
      uVar4 = extraout_r2;
      param_2 = param_2 + 1;
    } while (bVar5);
  }
  else {
    iVar1 = FUN_00086248(*(undefined4 *)(param_1 + 8),param_2);
    if (iVar1 == 0) {
LAB_000862fa:
      piVar2 = (int *)thunk_FUN_00081ec8(0x10);
      if (piVar2 != (int *)0x0) {
        piVar3 = (int *)thunk_FUN_00081ec8(0x10);
        if (piVar3 == (int *)0x0) {
          FUN_00086072(piVar2);
          goto LAB_000862e0;
        }
        thunk_FUN_00087900(piVar2,0,0x10);
        *piVar2 = param_2;
        piVar2[1] = param_3;
        piVar2[2] = param_4;
        *piVar3 = (int)piVar2;
        FUN_00086200(param_1 + 8,piVar3);
      }
      FUN_000860de(*(undefined4 *)(param_1 + 0xc));
      return piVar2;
    }
  }
LAB_000862e0:
  FUN_000860de(*(undefined4 *)(param_1 + 0xc));
  return (int *)0x0;
}


// ===== FUN_00086342 @ 00086342 (46 bytes)

void FUN_00086342(int param_1,undefined2 param_2)

{
  *(undefined2 *)
   (*(int *)(param_1 + 0x48) +
    (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2)) * 2 + 4) =
       param_2;
  FUN_00086092();
  *(short *)(*(int *)(param_1 + 0x48) + 2) = *(short *)(*(int *)(param_1 + 0x48) + 2) + 1;
  *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + 1;
  return;
}


// ===== FUN_00086370 @ 00086370 (38 bytes)

void FUN_00086370(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c) +
          (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2)) * 8;
  *(undefined4 *)(iVar1 + 4) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_3;
  FUN_00086092();
  *(short *)(*(int *)(param_1 + 0x4c) + 2) = *(short *)(*(int *)(param_1 + 0x4c) + 2) + 1;
  return;
}


// ===== FUN_00086396 @ 00086396 (22 bytes)

undefined4 FUN_00086396(void)

{
  FUN_00086342();
  return 0;
}


// ===== FUN_000863ac @ 000863ac (82 bytes)

undefined4 FUN_000863ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x58);
  iVar5 = *(int *)(param_1 + 0x44);
  uVar2 = thunk_FUN_0008606a(param_2);
  iVar4 = iVar5 + uVar3 * 0x10;
  *(undefined4 *)(iVar5 + uVar3 * 0x10) = uVar2;
  *(undefined2 *)(iVar4 + 0xc) = 2;
  sVar1 = *(short *)(param_1 + 0x58);
  *(undefined4 *)(iVar4 + 4) = 0;
  *(undefined4 *)(iVar4 + 8) = param_3;
  *(short *)(param_1 + 0x58) = sVar1 + 1;
  FUN_00086342(param_1,uVar3);
  return 0;
}


// ===== FUN_000863fe @ 000863fe (94 bytes)

undefined4 FUN_000863fe(int param_1,undefined4 *param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if ((uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2) != (uint)*(ushort *)(param_1 + 0x5a)) {
      iVar2 = *(int *)(param_1 + 0x4c) +
              ((uint)*(ushort *)(param_1 + 0x5a) & *(ushort *)(param_1 + 0x52) - 1) * 8;
      FUN_0008608c();
      uVar1 = *(uint *)(iVar2 + 4);
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(iVar2 + 8);
      }
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = (short)uVar1;
      }
      *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + 1;
      return *(undefined4 *)(*(int *)(param_1 + 0x44) + (uVar1 & 0xffff) * 0x10);
    }
  }
  return 0;
}


// ===== FUN_00086456 @ 00086456 (10 bytes)

undefined4 FUN_00086456(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x44) + param_2 * 0x10 + 8);
}


// ===== FUN_00086460 @ 00086460 (74 bytes)

undefined4 FUN_00086460(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x58);
  uVar2 = uVar3;
  if (param_2 != 0) {
    iVar5 = *(int *)(param_1 + 0x44);
    uVar1 = thunk_FUN_0008606a(param_2);
    iVar4 = iVar5 + uVar3 * 0x10;
    *(undefined4 *)(iVar5 + uVar3 * 0x10) = uVar1;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = param_3;
    *(undefined2 *)(iVar4 + 0xc) = 2;
    uVar2 = uVar3 + 1 & 0xffff;
  }
  *(short *)(param_1 + 0x58) = (short)uVar2;
  FUN_00086370(param_1,uVar3,param_3,uVar2,param_4);
  return 0;
}


// ===== FUN_000864aa @ 000864aa (40 bytes)

void FUN_000864aa(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x48);
  if (*(int *)(param_1 + 0x20) << 0x1e < 0) {
    puVar1[*(int *)(param_1 + 0x40) + 2] =
         (*(short *)(param_1 + 0x5a) + -1) - *(short *)(param_1 + 0x52);
    return;
  }
  *puVar1 = *puVar1 | 1;
  return;
}


// ===== FUN_000864d2 @ 000864d2 (70 bytes)

void FUN_000864d2(int param_1)

{
  FUN_00086086();
  if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
    if ((int)((uint)**(ushort **)(param_1 + 0x4c) << 0x1f) < 0) goto LAB_000864fe;
  }
  else if ((uint)*(ushort *)(param_1 + 0x56) <=
           ((*(ushort *)(*(int *)(param_1 + 0x48) + 2) - 1) -
            *(int *)(*(ushort **)(param_1 + 0x4c) + *(int *)(param_1 + 0x40) * 4 + 2) & 0xffff))
  goto LAB_000864fe;
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(param_1);
  }
LAB_000864fe:
  *(undefined2 *)(param_1 + 0x56) = 0;
  return;
}


// ===== FUN_00086518 @ 00086518 (32 bytes)

void FUN_00086518(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 0x52);
  iVar2 = *(int *)(param_1 + 0x44);
  while (iVar3 = iVar2 + uVar4 * 0x10, uVar4 < uVar1 - 1) {
    uVar4 = uVar4 + 1;
    *(short *)(iVar3 + 0xe) = (short)uVar4;
  }
  *(undefined2 *)(iVar3 + 0xe) = 0x8000;
  return;
}


// ===== FUN_00086542 @ 00086542 (22 bytes)

void FUN_00086542(void)

{
  DAT_e000ed04 = 0x10000000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== SysTick_Handler @ 00086558 (36 bytes)

void SysTick_Handler(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00086596();
  iVar2 = FUN_000824a0();
  if (iVar2 != 0) {
    DAT_e000ed04 = 0x10000000;
  }
  FUN_000865ac(uVar1);
  return;
}


// ===== FUN_0008657c @ 0008657c (56 bytes)

void FUN_0008657c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  
  if (*(char *)(*(int *)(param_1 + 0x18) + -2) == '\x02') {
    puVar3 = (undefined4 *)*DAT_00088800;
    setProcStackPointerLimit(*puVar3);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setThreadModePrivileged(1);
      bVar1 = (bool)isThreadMode();
      if (bVar1) {
        cVar2 = isUsingMainStack();
        setStackMode(cVar2 == '\x01');
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setProcessStackPointer(puVar3 + 10);
    }
    InstructionSynchronizationBarrier(0xf);
                    /* WARNING: Could not recover jumptable at 0x00080a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar3[1])(puVar3 + 10,2,(code *)puVar3[1],param_4);
    return;
  }
  FUN_00086596();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_00086596 @ 00086596 (22 bytes)

undefined8 FUN_00086596(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(0x40,uVar2);
}


// ===== FUN_000865ac @ 000865ac (14 bytes)

void FUN_000865ac(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}

