// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0022b8ac @ 0022b8ac (188 bytes)

uint FUN_0022b8ac(int param_1,uint param_2)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = param_2 + 0xc8000000;
  if (((int)(param_2 ^ uVar3) < 0) || (uVar4 = uVar3 >> 0x14 & 0x7ff, uVar4 == 0)) {
    uVar3 = 0x381 - (param_2 >> 0x14 & 0x7ff);
    if (0x1f < uVar3) {
      return param_2 & 0x80000000;
    }
    uVar1 = ((CONCAT44(param_2,param_1) | 0x70000000000000) & 0x1fffffffffffff) >> 0x1d;
    uVar5 = uVar3 & 0x1f;
    uVar6 = (uint)((uVar1 << 0x20 | (ulonglong)(uint)(param_1 << 3)) >> uVar5);
    uVar4 = (uint)uVar1 >> uVar5;
    if ((param_1 << 3) << 0x20 - uVar5 != 0) {
      uVar6 = uVar6 | uVar3;
    }
  }
  else {
    if (0xfe < uVar4) {
      iVar2 = 0x7ff00000;
      if (((~param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
        iVar2 = 0x3ff80000;
      }
      return (uint)(CONCAT44(param_2 >> 0x1f,iVar2 << 4) >> 1);
    }
    uVar6 = param_1 << 3;
    uVar4 = (uint)(CONCAT44(uVar3,param_1) >> 0x1d);
  }
  uVar4 = param_2 & 0x80000000 | uVar4;
  if (((int)uVar6 < 0) && (uVar4 = uVar4 + 1, (uVar6 & 0x7fffffff) == 0)) {
    return uVar4 & 0xfffffffe;
  }
  return uVar4;
}


// ===== FUN_0022b96c @ 0022b96c (100 bytes)

longlong FUN_0022b96c(void)

{
  uint in_aed0;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = in_aed0 >> 0x17 & 0xff;
  uVar1 = in_aed0 & 0x80000000;
  iVar3 = in_aed0 << 1;
  if (uVar2 == 0) {
    uVar2 = 0;
    if (iVar3 != 0) {
      uVar2 = iVar3 << 0x20 - (0x20 - (LZCOUNT(iVar3) - 8U & 0x1f));
      return CONCAT44((uVar2 >> 3) + (0x37f - (LZCOUNT(iVar3) - 8U)) * 0x100000 | uVar1,
                      uVar2 << 0x1d);
    }
  }
  else {
    if (uVar2 != 0xff) {
      return CONCAT44(((in_aed0 & 0x7fffffff) >> 3) + 0x38000000 | uVar1,in_aed0 << 0x1d);
    }
    uVar2 = 0x7ff00000;
    if ((in_aed0 & 0x7fffff) != 0) {
      uVar2 = 0x7ff80000;
    }
  }
  return (ulonglong)(uVar2 | uVar1) << 0x20;
}


// ===== FUN_0022b9e0 @ 0022b9e0 (35 bytes)

void FUN_0022b9e0(undefined4 param_1,undefined4 *param_2,undefined *param_3,code *param_4,
                 int param_5)

{
  if (param_2 != (undefined4 *)0x0) {
    DAT_002cd700 = *param_2;
  }
  PTR_DAT_00237ad0 = param_3;
  if (param_4 != (code *)0x0) {
    (*param_4)();
  }
  if (param_5 != 0) {
    FUN_0022e710(param_5);
  }
  return;
}


// ===== FUN_0022ba10 @ 0022ba10 (10 bytes)

undefined * FUN_0022ba10(void)

{
  return PTR_DAT_00237f00;
}


// ===== FUN_0022ba20 @ 0022ba20 (32 bytes)

undefined4 FUN_0022ba20(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_0022e740(param_1,0);
  if (DAT_00237b14 != (code *)0x0) {
    (*DAT_00237b14)();
  }
  FUN_002332a4(param_1);
  uVar1 = FUN_0022ba80(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== FUN_0022ba40 @ 0022ba40 (20 bytes)

undefined4 FUN_0022ba40(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0022ba80(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== FUN_0022ba60 @ 0022ba60 (17 bytes)

void FUN_0022ba60(undefined4 param_1)

{
  FUN_0022fe50(PTR_DAT_00237f00,param_1);
  return;
}


// ===== FUN_0022ba80 @ 0022ba80 (1297 bytes)

undefined4 * FUN_0022ba80(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 *local_50;
  uint uStack_48;
  undefined *puStack_34;
  
  if (param_2 + 0x13 < 0x1f) {
    uVar1 = 0x10;
    if (0x10 < param_2) goto LAB_0022bad6;
  }
  else {
    uVar1 = param_2 + 0x13 & 0xfffffff0;
    if (((int)uVar1 < 0) || (uVar1 < param_2)) {
LAB_0022bad6:
      *param_1 = 0xc;
      return (undefined4 *)0x0;
    }
  }
  FUN_00228dc0(param_1);
  puVar13 = PTR_PTR_00237f30;
  if (uVar1 < 0x1f8) {
    uStack_48 = uVar1 >> 3;
    puVar2 = (&PTR_DAT_00237f2c)[uStack_48 * 2];
    if (&DAT_00237f20 + uStack_48 * 8 != puVar2) {
      uVar1 = *(uint *)(puVar2 + 4);
      iVar6 = *(int *)(puVar2 + 8);
      iVar12 = *(int *)(puVar2 + 0xc);
      uVar4 = *(uint *)(puVar2 + (uVar1 & 0xfffffffc) + 4);
      *(int *)(iVar6 + 0xc) = iVar12;
      *(int *)(iVar12 + 8) = iVar6;
      *(uint *)(puVar2 + (uVar1 & 0xfffffffc) + 4) = uVar4 | 1;
      FUN_00228df0(param_1);
      return (undefined4 *)(puVar2 + 8);
    }
    uStack_48 = uStack_48 + 2;
  }
  else {
    uStack_48 = uVar1 >> 9;
    if (uStack_48 == 0) {
      uStack_48 = uVar1 >> 3;
    }
    else if (uStack_48 < 5) {
      uStack_48 = (uVar1 >> 6) + 0x38;
    }
    else if (uStack_48 < 0x15) {
      uStack_48 = uStack_48 + 0x5b;
    }
    else if (uStack_48 < 0x55) {
      uStack_48 = (uVar1 >> 0xc) + 0x6e;
    }
    else if (uStack_48 < 0x155) {
      uStack_48 = (uVar1 >> 0xf) + 0x77;
    }
    else if (uStack_48 < 0x555) {
      uStack_48 = (uVar1 >> 0x12) + 0x7c;
    }
    else {
      uStack_48 = 0x7e;
    }
    for (puVar2 = (&PTR_DAT_00237f2c)[uStack_48 * 2]; &DAT_00237f20 + uStack_48 * 8 != puVar2;
        puVar2 = *(undefined **)(puVar2 + 0xc)) {
      uVar4 = *(uint *)(puVar2 + 4) & 0xfffffffc;
      if (0xf < (int)(uVar4 - uVar1)) {
        uStack_48 = uStack_48 - 1;
        break;
      }
      if (-1 < (int)(uVar4 - uVar1)) {
        iVar12 = *(int *)(puVar2 + 8);
        iVar6 = *(int *)(puVar2 + 0xc);
        uVar1 = *(uint *)(puVar2 + uVar4 + 4);
        *(int *)(iVar12 + 0xc) = iVar6;
        *(int *)(iVar6 + 8) = iVar12;
        *(uint *)(puVar2 + uVar4 + 4) = uVar1 | 1;
        FUN_00228df0(param_1);
        return (undefined4 *)(puVar2 + 8);
      }
    }
    uStack_48 = uStack_48 + 1;
  }
  if ((undefined **)PTR_PTR_00237f30 != &PTR_DAT_00237f28) {
    uVar4 = *(uint *)(PTR_PTR_00237f30 + 4);
    uVar5 = uVar4 & 0xfffffffc;
    uVar8 = uVar5 - uVar1;
    if (0xf < (int)uVar8) {
      *(uint *)(PTR_PTR_00237f30 + 4) = uVar1 | 1;
      puVar2 = PTR_PTR_00237f30 + uVar1;
      PTR_PTR_00237f30 = puVar2;
      PTR_PTR_00237f34 = puVar2;
      *(uint *)(puVar2 + 4) = uVar8 | 1;
      *(undefined ***)(puVar2 + 8) = &PTR_DAT_00237f28;
      *(undefined ***)(puVar2 + 0xc) = &PTR_DAT_00237f28;
      *(uint *)(puVar2 + uVar8) = uVar8;
      FUN_00228df0(param_1);
      return (undefined4 *)(puVar13 + 8);
    }
    PTR_PTR_00237f34 = (undefined *)&PTR_DAT_00237f28;
    PTR_PTR_00237f30 = (undefined *)&PTR_DAT_00237f28;
    if (-1 < (int)uVar8) {
      *(uint *)(puVar13 + uVar5 + 4) = *(uint *)(puVar13 + uVar5 + 4) | 1;
      FUN_00228df0(param_1);
      return (undefined4 *)(puVar13 + 8);
    }
    if (uVar5 < 0x200) {
      uVar4 = uVar4 >> 3;
      DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar4 >> 2 & 0x1fU));
      *(undefined **)(puVar13 + 0xc) = &DAT_00237f20 + uVar4 * 8;
      puVar2 = (&PTR_DAT_00237f28)[uVar4 * 2];
      *(undefined **)(puVar13 + 8) = puVar2;
      (&PTR_DAT_00237f28)[uVar4 * 2] = puVar13;
      *(undefined **)(puVar2 + 0xc) = puVar13;
    }
    else {
      uVar8 = uVar4 >> 9;
      if (uVar8 == 0) {
        uVar8 = uVar4 >> 3;
      }
      else if (uVar8 < 5) {
        uVar8 = (uVar4 >> 6) + 0x38;
      }
      else if (uVar8 < 0x15) {
        uVar8 = uVar8 + 0x5b;
      }
      else if (uVar8 < 0x55) {
        uVar8 = (uVar4 >> 0xc) + 0x6e;
      }
      else if (uVar8 < 0x155) {
        uVar8 = (uVar4 >> 0xf) + 0x77;
      }
      else if (uVar8 < 0x555) {
        uVar8 = (uVar4 >> 0x12) + 0x7c;
      }
      else {
        uVar8 = 0x7e;
      }
      puVar11 = &DAT_00237f20 + uVar8 * 8;
      puVar2 = (&PTR_DAT_00237f28)[uVar8 * 2];
      if (puVar11 == puVar2) {
        DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar8 >> 2 & 0x1fU));
      }
      else {
        uVar4 = *(uint *)(puVar2 + 4);
        while ((uVar5 < (uVar4 & 0xfffffffc) &&
               (puVar2 = *(undefined **)(puVar2 + 8), puVar11 != puVar2))) {
          uVar4 = *(uint *)(puVar2 + 4);
        }
        puVar11 = *(undefined **)(puVar2 + 0xc);
      }
      *(undefined **)(puVar13 + 0xc) = puVar11;
      *(undefined **)(puVar13 + 8) = puVar2;
      *(undefined **)(puVar11 + 8) = puVar13;
      *(undefined **)(puVar2 + 0xc) = puVar13;
    }
  }
  puVar13 = PTR_DAT_00237f28;
  uVar4 = uStack_48 + 3;
  if (-1 < (int)uStack_48) {
    uVar4 = uStack_48;
  }
  uVar4 = 1 << 0x20 - (0x20 - ((int)uVar4 >> 2 & 0x1fU));
  if (uVar4 <= DAT_00237f24) {
    uVar5 = DAT_00237f24;
    if ((uVar4 & DAT_00237f24) == 0) {
      iVar6 = 0;
      while (uVar4 = uVar4 << 1, (uVar4 & DAT_00237f24) == 0) {
        iVar6 = iVar6 + 1;
      }
      uStack_48 = iVar6 * 4 + (uStack_48 & 0xfffffffc) + 4;
    }
    do {
      uVar8 = uStack_48;
      puVar10 = (undefined4 *)(&DAT_00237f20 + uStack_48 * 8);
      do {
        for (puVar3 = (undefined4 *)puVar10[3]; puVar3 != puVar10; puVar3 = (undefined4 *)puVar3[3])
        {
          uVar7 = puVar3[1] & 0xfffffffc;
          uVar9 = uVar7 - uVar1;
          if (0xf < (int)uVar9) {
            iVar6 = puVar3[2];
            iVar12 = puVar3[3];
            puVar3[1] = uVar1 | 1;
            *(int *)(iVar6 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar6;
            puVar13 = (undefined *)(uVar1 + (int)puVar3);
            PTR_PTR_00237f30 = puVar13;
            PTR_PTR_00237f34 = puVar13;
            *(uint *)(puVar13 + 4) = uVar9 | 1;
            *(undefined ***)(puVar13 + 8) = &PTR_DAT_00237f28;
            *(undefined ***)(puVar13 + 0xc) = &PTR_DAT_00237f28;
            *(uint *)((int)puVar3 + uVar7) = uVar9;
            FUN_00228df0(param_1);
            return puVar3 + 2;
          }
          if (-1 < (int)uVar9) {
            iVar6 = puVar3[2];
            iVar12 = puVar3[3];
            *(uint *)((int)puVar3 + uVar7 + 4) = *(uint *)((int)puVar3 + uVar7 + 4) | 1;
            *(int *)(iVar6 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar6;
            FUN_00228df0(param_1);
            return puVar3 + 2;
          }
        }
        puVar3 = puVar10 + 2;
        if ((int)uVar8 < 0x3f) {
          puVar3 = puVar10 + 4;
          uVar8 = uVar8 + 1;
        }
        uVar8 = uVar8 + 1;
        puVar10 = puVar3;
        local_50 = (undefined4 *)(&DAT_00237f20 + uStack_48 * 8);
      } while ((uVar8 & 3) != 0);
      do {
        uVar7 = uStack_48 & 3;
        puVar10 = local_50 + -2;
        uStack_48 = uStack_48 - 1;
        if (uVar7 == 0) {
          uVar5 = uVar5 & (uVar4 ^ 0xffffffff);
          DAT_00237f24 = uVar5;
          break;
        }
        puVar3 = (undefined4 *)*local_50;
        local_50 = puVar10;
      } while (puVar3 == puVar10);
      uVar4 = uVar4 << 1;
      if ((uVar5 < uVar4) || (uVar4 == 0)) break;
      iVar6 = 0;
      for (; (uVar4 & uVar5) == 0; uVar4 = uVar4 << 1) {
        iVar6 = iVar6 + 1;
      }
      uStack_48 = iVar6 * 4 + uVar8;
    } while( true );
  }
  uVar4 = *(uint *)(PTR_DAT_00237f28 + 4) & 0xfffffffc;
  uVar5 = uVar4 - uVar1;
  if ((uVar1 <= uVar4) && (puStack_34 = PTR_DAT_00237f28, 0xf < (int)uVar5)) goto LAB_0022bdf6;
  puVar11 = PTR_DAT_00237f28 + uVar4;
  uVar5 = DAT_002cd708 + uVar1 + 0x100f & 0xfffff000;
  puStack_34 = (undefined *)FUN_00228e34(param_1);
  puVar2 = DAT_002cd738;
  if ((puStack_34 == (undefined *)0xffffffff) ||
     ((puStack_34 < puVar11 && (puVar13 != &DAT_00237f20)))) {
LAB_0022bdd3:
    DAT_002cd738 = puVar2;
    uVar4 = *(uint *)(PTR_DAT_00237f28 + 4);
    puStack_34 = PTR_DAT_00237f28;
  }
  else {
    DAT_002cd70c = DAT_002cd70c + uVar5;
    if ((puStack_34 == puVar11) && (((uint)puVar11 & 0xfff) == 0)) {
      *(uint *)(PTR_DAT_00237f28 + 4) = uVar4 + uVar5 | 1;
LAB_0022bdc0:
      DAT_002cd734 = (undefined *)
                     ((uint)(DAT_002cd70c < DAT_002cd734) * (int)DAT_002cd734 +
                     (uint)(DAT_002cd70c >= DAT_002cd734) * (int)DAT_002cd70c);
      puVar2 = DAT_002cd70c;
      if (DAT_002cd70c < DAT_002cd738) {
        puVar2 = DAT_002cd738;
      }
      goto LAB_0022bdd3;
    }
    puVar2 = puStack_34;
    if (DAT_00237f10 != (undefined *)0xffffffff) {
      DAT_002cd70c = puStack_34 + ((int)DAT_002cd70c - (int)puVar11);
      puVar2 = DAT_00237f10;
    }
    DAT_00237f10 = puVar2;
    uVar8 = (uint)(puStack_34 + 8) & 0xf;
    if (uVar8 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0x10 - uVar8;
      puStack_34 = puStack_34 + (0x10 - uVar8);
    }
    iVar6 = (iVar6 - ((uint)(puStack_34 + uVar5) & 0xfff)) + 0x1000;
    puVar2 = (undefined *)FUN_00228e34(param_1);
    if (puVar2 == (undefined *)0xffffffff) {
      iVar6 = 0;
      puVar2 = puStack_34;
    }
    DAT_002cd70c = DAT_002cd70c + iVar6;
    PTR_DAT_00237f28 = puStack_34;
    *(uint *)(puStack_34 + 4) = (uint)(puVar2 + (iVar6 - (int)puStack_34)) | 1;
    if (puVar13 == &DAT_00237f20) goto LAB_0022bdc0;
    if (0xf < uVar4) {
      uVar4 = uVar4 - 0xc & 0xfffffff0;
      *(uint *)(puVar13 + 4) = uVar4 | *(uint *)(puVar13 + 4) & 1;
      *(undefined4 *)(puVar13 + uVar4 + 4) = 5;
      *(undefined4 *)(puVar13 + uVar4 + 8) = 5;
      if (0xf < uVar4) {
        FUN_0022fe50(param_1,puVar13 + 8);
      }
      goto LAB_0022bdc0;
    }
    *(undefined4 *)(puStack_34 + 4) = 1;
    uVar4 = 0;
  }
  uVar5 = (uVar4 & 0xfffffffc) - uVar1;
  if (((uVar4 & 0xfffffffc) < uVar1) || ((int)uVar5 < 0x10)) {
    FUN_00228df0(param_1);
    return (undefined4 *)0x0;
  }
LAB_0022bdf6:
  *(uint *)(puStack_34 + 4) = uVar1 | 1;
  PTR_DAT_00237f28 = puStack_34 + uVar1;
  *(uint *)(PTR_DAT_00237f28 + 4) = uVar5 | 1;
  FUN_00228df0(param_1);
  return (undefined4 *)(puStack_34 + 8);
}


// ===== FUN_0022bfb0 @ 0022bfb0 (49 bytes)

undefined4 FUN_0022bfb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0022c5b0(param_1,*(undefined4 *)(param_1 + 8),param_2);
  return uVar1;
}


// ===== FUN_0022bff0 @ 0022bff0 (55 bytes)

undefined4 FUN_0022bff0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0022c5b0(PTR_DAT_00237f00,*(undefined4 *)(PTR_DAT_00237f00 + 8),param_1);
  return uVar1;
}


// ===== FUN_0022c030 @ 0022c030 (20 bytes)

void FUN_0022c030(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_00237f00;
  *(undefined4 *)(PTR_DAT_00237f00 + 0xa8) = param_1;
  *(undefined4 *)(puVar1 + 0xac) = 0;
  return;
}


// ===== FUN_0022c050 @ 0022c050 (75 bytes)

uint FUN_0022c050(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_00237f00;
  uVar2 = *(uint *)(PTR_DAT_00237f00 + 0xa8);
  uVar3 = uVar2 * 0x4c957f2d + 1;
  uVar4 = (int)((ulonglong)uVar2 * 0x4c957f2d >> 0x20) + uVar2 * 0x5851f42d +
          *(int *)(PTR_DAT_00237f00 + 0xac) * 0x4c957f2d;
  if (uVar3 < uVar2 * 0x4c957f2d) {
    *(uint *)(PTR_DAT_00237f00 + 0xa8) = uVar3;
    *(uint *)(puVar1 + 0xac) = uVar4 + 1;
    return uVar4 + 1 & 0x7fffffff;
  }
  *(uint *)(PTR_DAT_00237f00 + 0xa8) = uVar3;
  *(uint *)(puVar1 + 0xac) = uVar4;
  return uVar4 & 0x7fffffff;
}


// ===== FUN_0022c0a0 @ 0022c0a0 (30 bytes)

void FUN_0022c0a0(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    FUN_0022c0a0(param_1);
  }
  FUN_0022fe50(param_1,param_2);
  return;
}


// ===== FUN_0022c0c0 @ 0022c0c0 (140 bytes)

void FUN_0022c0c0(undefined *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (PTR_DAT_00237f00 != param_1) {
    iVar3 = *(int *)(param_1 + 0x4c);
    if (iVar3 != 0) {
      iVar2 = 0;
      do {
        piVar1 = *(int **)(iVar3 + iVar2);
        if (*(int **)(iVar3 + iVar2) != (int *)0x0) {
          do {
            piVar4 = (int *)*piVar1;
            FUN_0022fe50(param_1,piVar1);
            piVar1 = piVar4;
          } while (piVar4 != (int *)0x0);
          iVar3 = *(int *)(param_1 + 0x4c);
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 != 0x80);
      FUN_0022fe50(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      FUN_0022fe50(param_1);
    }
    if (*(int *)(param_1 + 0x148) != 0) {
      piVar1 = (int *)*(int *)(param_1 + 0x148);
      while ((int *)(param_1 + 0x14c) != piVar1) {
        iVar3 = *piVar1;
        FUN_0022fe50(param_1,piVar1);
        piVar1 = (int *)iVar3;
      }
    }
    if (*(int *)(param_1 + 0x54) != 0) {
      FUN_0022fe50(param_1);
    }
    if ((*(int *)(param_1 + 0x38) != 0) &&
       ((**(code **)(param_1 + 0x3c))(param_1), *(int *)(param_1 + 0x2e0) != 0)) {
      FUN_0022c0a0(param_1);
    }
  }
  return;
}


// ===== FUN_0022c150 @ 0022c150 (56 bytes)

void FUN_0022c150(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_00237f00;
  }
  for (piVar2 = *(int **)(param_1 + 0x148); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar1 = (int)(piVar2 + piVar2[1]);
    if (0 < piVar2[1]) {
      do {
        (**(code **)(iVar1 + 4))();
        iVar1 = iVar1 + -4;
      } while ((int *)iVar1 != piVar2);
    }
  }
  if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
    (**(code **)(param_1 + 0x3c))(param_1);
  }
  return;
}


// ===== FUN_0022c190 @ 0022c190 (328 bytes)

/* WARNING: Removing unreachable block (ram,0x0022c1e1) */

longlong FUN_0022c190(uint *param_1,uint *param_2)

{
  int unaff_retaddr;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar3 = (uint)(byte)*param_1;
  uVar4 = (uint)(byte)*param_2;
  puVar5 = param_2;
  if (uVar3 != uVar4) {
LAB_0022c1f7:
    return CONCAT44(puVar5,uVar3 - uVar4);
  }
  puVar1 = param_1;
  if ((((uint)param_1 | (uint)param_2) & 3) != 0) {
    if ((((uint)param_1 ^ (uint)param_2) & 3) != 0) {
      uVar3 = (uint)(byte)*param_1;
      uVar4 = (uint)(byte)*param_2;
      if (uVar3 == uVar4) {
        puVar5 = (uint *)((int)param_2 + 1);
      }
      goto LAB_0022c1f7;
    }
    puVar1 = (uint *)((int)param_1 + 1);
    if (uVar3 == 0) goto LAB_0022c28d;
    puVar5 = (uint *)((int)param_2 + 1);
    if (((uint)puVar1 & 3) != 0) {
      uVar3 = (uint)*(byte *)puVar1;
      uVar4 = (uint)*(byte *)puVar5;
      puVar1 = (uint *)((int)param_1 + 2);
      if (uVar3 != uVar4) goto LAB_0022c1f7;
      if (uVar3 == 0) goto LAB_0022c28d;
      puVar5 = (uint *)((int)param_2 + 2);
      if (((uint)puVar1 & 3) != 0) {
        uVar3 = (uint)*(byte *)puVar1;
        uVar4 = (uint)*(byte *)puVar5;
        puVar1 = (uint *)((int)param_1 + 3);
        if (uVar3 != uVar4) goto LAB_0022c1f7;
        if (uVar3 == 0) goto LAB_0022c28d;
        puVar5 = (uint *)((int)param_2 + 3);
      }
    }
  }
  while( true ) {
    if (unaff_retaddr == 1) {
      isync();
    }
    uVar3 = *puVar1;
    uVar4 = *puVar5;
    if (uVar3 != uVar4) goto LAB_0022c291;
    if ((~(uVar3 | uVar3 << 1) & 0x40404040) != 0) goto LAB_0022c24d;
    uVar3 = puVar1[1];
    uVar4 = puVar5[1];
    if (uVar3 != uVar4) goto LAB_0022c291;
    if ((~(uVar3 | uVar3 << 1) & 0x40404040) != 0) break;
    puVar1 = puVar1 + 2;
    puVar5 = puVar5 + 2;
  }
  puVar1 = puVar1 + 1;
  puVar5 = puVar5 + 1;
LAB_0022c24d:
  if ((((uVar3 & 0xff) != 0) && ((uVar3 & (uint)&DAT_0000ff00) != 0)) && ((uVar3 & 0xff0000) != 0))
  {
    while ((uVar3 & 0xff000000) != 0) {
      puVar5 = puVar5 + 1;
      puVar1 = puVar1 + 1;
      if (unaff_retaddr == 1) {
        isync();
      }
      uVar3 = *puVar1;
      uVar4 = *puVar5;
      if (uVar3 != uVar4) goto LAB_0022c291;
      if ((((uVar3 & 0xff) == 0) || ((uVar3 & (uint)&DAT_0000ff00) == 0)) ||
         ((uVar3 & 0xff0000) == 0)) break;
    }
  }
LAB_0022c28d:
  return ZEXT48(puVar5) << 0x20;
LAB_0022c291:
  uVar2 = uVar3 ^ uVar4;
  if ((uVar2 & 0xff) != 0) {
    return CONCAT44(puVar5,(uVar3 & 0xff) - (uVar4 & 0xff));
  }
  if ((uVar3 & 0xff) != 0) {
    if ((uVar2 & (uint)&DAT_0000ff00) != 0) {
      return CONCAT44(puVar5,(uVar3 >> 8 & 0xff) - (uVar4 >> 8 & 0xff));
    }
    if ((uVar3 & (uint)&DAT_0000ff00) != 0) {
      if ((uVar2 & 0xff0000) != 0) {
        return CONCAT44(puVar5,(uVar3 >> 0x10 & 0xff) - (uVar4 >> 0x10 & 0xff));
      }
      if ((uVar3 & 0xff0000) != 0) {
        return CONCAT44(puVar5,(uVar3 >> 0x18) - (uVar4 >> 0x18));
      }
    }
  }
  goto LAB_0022c28d;
}


// ===== FUN_0022c2e0 @ 0022c2e0 (148 bytes)

int FUN_0022c2e0(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  if ((((((uint)param_2 | (uint)param_1) & 3) == 0) && (3 < param_3)) &&
     (uVar1 = *param_1, *param_2 == uVar1)) {
    do {
      param_3 = param_3 - 4;
      if (param_3 == 0) {
        return 0;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if ((uVar1 + 0xfefefeff & (uVar1 ^ 0xffffffff) & 0x80808080) != 0) {
        return 0;
      }
    } while ((3 < param_3) && (uVar1 = *param_1, *param_2 == uVar1));
  }
  uVar1 = (uint)(byte)*param_1;
  uVar2 = (uint)(byte)*param_2;
  if ((param_3 != 0) && (uVar1 == uVar2)) {
    do {
      param_3 = param_3 - 1;
      if (param_3 == 0) {
        return 0;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if (uVar1 == 0) {
        return 0;
      }
      param_2 = (uint *)((int)param_2 + 1);
      if (param_3 == 0) {
        return (uint)*(byte *)param_1 - (uint)*(byte *)param_2;
      }
      uVar1 = (uint)*(byte *)param_1;
      uVar2 = (uint)*(byte *)param_2;
    } while (uVar2 == uVar1);
  }
  return uVar1 - uVar2;
}


// ===== FUN_0022c3bc @ 0022c3bc (175 bytes)

/* WARNING: Possible PIC construction at 0x0022c3db: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c49c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c476: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c3b7: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0022c476) */
/* WARNING: Removing unreachable block (ram,0x0022c49c) */
/* WARNING: Removing unreachable block (ram,0x0022c3db) */
/* WARNING: Removing unreachable block (ram,0x0022c3b7) */
/* WARNING: Removing unreachable block (ram,0x0022c445) */
/* WARNING: Removing unreachable block (ram,0x0022c4a5) */

void FUN_0022c3bc(uint *param_1,uint *param_2,int param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  if (param_3 == 0) {
    return;
  }
  puVar2 = param_1;
  if (((uint)param_2 & 1) != 0) {
    uVar3 = *param_2;
    iVar5 = param_3 + -1;
    *(char *)param_1 = (char)uVar3;
    param_2 = (uint *)((int)param_2 + 1);
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)param_1 + 1);
    param_3 = iVar5;
    puVar2 = puVar4;
    if ((char)uVar3 == '\0') goto SUB_0022c3e0;
  }
  iVar5 = param_3;
  puVar4 = puVar2;
  if (((uint)param_2 & 2) != 0) {
    uVar3 = *param_2;
    iVar5 = param_3 + -1;
    *(char *)puVar2 = (char)uVar3;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar2 + 1);
    if ((char)uVar3 == '\0') goto SUB_0022c3e0;
    cVar1 = *(char *)((int)param_2 + 1);
    iVar5 = param_3 + -2;
    *(char *)puVar4 = cVar1;
    param_2 = (uint *)((int)param_2 + 2);
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar2 + 2);
    if (cVar1 == '\0') goto SUB_0022c3e0;
  }
  if ((((uint)puVar4 & 3) != 0) || (iVar5 < 5)) {
    *(char *)puVar4 = (char)*param_2;
    if (iVar5 != 1) {
      func_0x0022c3e0(param_1,(char *)((int)param_2 + 1));
      return;
    }
    return;
  }
  uVar3 = *param_2;
  if ((uVar3 & 0xff) == 0) {
    *(char *)puVar4 = (char)uVar3;
    iVar5 = iVar5 + -1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  else {
    if ((uVar3 & (uint)&DAT_0000ff00) == 0) {
      *(short *)puVar4 = (short)uVar3;
      func_0x0022c3e0(param_1,param_2 + 1,iVar5 + -2);
      return;
    }
    if ((uVar3 & 0xff0000) == 0) {
      *(short *)puVar4 = (short)uVar3;
      *(char *)((int)puVar4 + 2) = '\0';
      iVar5 = iVar5 + -3;
      puVar4 = (uint *)((int)puVar4 + 3);
    }
    else {
      *puVar4 = uVar3;
      iVar5 = iVar5 + -4;
      puVar4 = puVar4 + 1;
      if ((uVar3 & 0xff000000) != 0) {
        func_0x0022c3e0(param_1,param_2 + 1);
        return;
      }
    }
  }
SUB_0022c3e0:
  if (((uint)puVar4 & 1) != 0) {
    *(char *)puVar4 = '\0';
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  if (((uint)puVar4 & 2) != 0) {
    *(char *)puVar4 = '\0';
    if (iVar5 == 1) {
      return;
    }
    *(char *)((int)puVar4 + 1) = '\0';
    iVar5 = iVar5 + -2;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar4 + 2);
  }
  if (3 < iVar5) {
    if (iVar5 >> 2 == 1) {
      isync();
    }
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + (iVar5 >> 2) * -4;
    if (iVar5 == 0) {
      return;
    }
  }
  do {
    *(char *)puVar4 = '\0';
    iVar5 = iVar5 + -1;
    puVar4 = (uint *)((int)puVar4 + 1);
  } while (iVar5 != 0);
  return;
}


// ===== FUN_0022c4d0 @ 0022c4d0 (175 bytes)

int FUN_0022c4d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *apuStack_4b0 [2];
  undefined4 uStack_4a8;
  ushort uStack_4a4;
  undefined2 uStack_4a2;
  undefined1 *puStack_4a0;
  undefined4 uStack_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_48c;
  undefined4 uStack_44c;
  undefined1 auStack_440 [1036];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_4a8 = 0x400;
  uStack_49c = 0x400;
  apuStack_4b0[0] = auStack_440;
  uStack_494 = *(undefined4 *)(param_2 + 0x1c);
  uStack_4a2 = *(undefined2 *)(param_2 + 0xe);
  uStack_4a4 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_48c = *(undefined4 *)(param_2 + 0x24);
  uStack_44c = *(undefined4 *)(param_2 + 100);
  uStack_498 = 0;
  puStack_4a0 = apuStack_4b0[0];
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  iVar1 = FUN_0022c5b0(param_1,apuStack_4b0,param_3,param_4,param_5,param_6);
  if ((-1 < iVar1) && (iVar2 = FUN_0022fb80(param_1,apuStack_4b0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if (((uint)(int)(short)uStack_4a4 >> 6 & 1) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
    return iVar1;
  }
  return iVar1;
}


// ===== FUN_0022c590 @ 0022c590 (31 bytes)

undefined4
FUN_0022c590(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0022c5b0(PTR_DAT_00237f00,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


// ===== FUN_0022c5b0 @ 0022c5b0 (8131 bytes)

/* WARNING: Removing unreachable block (ram,0x0022cf03) */
/* WARNING: Removing unreachable block (ram,0x0022dc42) */
/* WARNING: Removing unreachable block (ram,0x0022d1f8) */
/* WARNING: Removing unreachable block (ram,0x0022d308) */
/* WARNING: Removing unreachable block (ram,0x0022e1d5) */
/* WARNING: Removing unreachable block (ram,0x0022e149) */
/* WARNING: Removing unreachable block (ram,0x0022e104) */
/* WARNING: Removing unreachable block (ram,0x0022cfd6) */
/* WARNING: Removing unreachable block (ram,0x0022dc06) */
/* WARNING: Removing unreachable block (ram,0x0022e222) */
/* WARNING: Removing unreachable block (ram,0x0022e4cf) */
/* WARNING: Removing unreachable block (ram,0x0022e5f7) */
/* WARNING: Removing unreachable block (ram,0x0022e5ef) */
/* WARNING: Removing unreachable block (ram,0x0022dc12) */
/* WARNING: Removing unreachable block (ram,0x0022e233) */
/* WARNING: Removing unreachable block (ram,0x0022e245) */
/* WARNING: Type propagation algorithm not settling */

char * FUN_0022c5b0(int param_1,int param_2,byte *param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char **ppcVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined **ppuVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  int iVar20;
  int iVar21;
  char *pcVar22;
  char *pcVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  char cVar30;
  int *piVar31;
  int iVar32;
  char *pcVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  char *pcVar37;
  uint uVar38;
  int *piVar39;
  byte *pbVar40;
  int iVar41;
  undefined4 uVar42;
  byte bVar43;
  char *pcVar44;
  char *pcVar45;
  uint uVar46;
  char *pcVar47;
  uint uVar48;
  uint uVar49;
  undefined **ppuVar50;
  char *pcVar51;
  char *pcVar52;
  char *pcVar53;
  undefined **ppuVar54;
  int iVar55;
  char *pcVar56;
  char *pcVar57;
  undefined8 uVar58;
  int local_1b0 [16];
  int *piStack_170;
  int iStack_16c;
  int iStack_168;
  undefined1 auStack_160 [39];
  char cStack_139;
  undefined *apuStack_138 [3];
  char cStack_129;
  char acStack_128 [4];
  char acStack_124 [4];
  undefined1 uStack_120;
  undefined1 uStack_11f;
  byte abStack_11e [6];
  undefined4 uStack_118;
  uint uStack_114;
  char *pcStack_110;
  undefined1 auStack_10c [4];
  char *pcStack_108;
  char *pcStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  uint uStack_f0;
  undefined4 uStack_ec;
  char *pcStack_e8;
  uint uStack_e4;
  undefined **ppuStack_e0;
  int iStack_dc;
  char *pcStack_d8;
  char *pcStack_d4;
  char *pcStack_d0;
  char *pcStack_cc;
  undefined **ppuStack_c8;
  int iStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int iStack_b8;
  char *pcStack_b4;
  int iStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  undefined **ppuStack_a0;
  int iStack_9c;
  char *pcStack_98;
  uint uStack_94;
  undefined **ppuStack_90;
  char *pcStack_8c;
  char *pcStack_88;
  char *pcStack_84;
  char *pcStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  char *pcStack_74;
  uint uStack_70;
  int iStack_6c;
  int iStack_68;
  char *pcStack_64;
  char *pcStack_60;
  int iStack_58;
  int iStack_54;
  uint uStack_50;
  byte *pbStack_4c;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iStack_6c = param_1;
  iStack_68 = param_2;
  iStack_34 = param_4;
  iStack_30 = param_5;
  iStack_2c = param_6;
  piVar31 = (int *)FUN_002301e0(param_1);
  iVar34 = *piVar31;
  iStack_b0 = FUN_00230e50(iVar34);
  uStack_a8 = 0;
  uStack_a4 = 0;
  if ((iStack_6c != 0) && (*(int *)(iStack_6c + 0x38) == 0)) {
    FUN_0022fd00(iStack_6c);
  }
  uVar38 = (uint)*(short *)(iStack_68 + 0xc);
  if ((uVar38 >> 0xd & 1) == 0) {
    uVar38 = uVar38 | (uint)&DAT_00002000;
    *(short *)(iStack_68 + 0xc) = (short)uVar38;
    *(uint *)(iStack_68 + 100) = *(uint *)(iStack_68 + 100) & 0xffffdfff;
  }
  if (((uVar38 >> 3 & 1) == 0) || (*(int *)(iStack_68 + 0x10) == 0)) {
    iVar32 = FUN_0022e630(iStack_6c,iStack_68);
    if (iVar32 != 0) {
      return (char *)0xffffffff;
    }
    uVar38 = (uint)*(short *)(iStack_68 + 0xc);
  }
  iStack_f8 = iVar34;
  iStack_fc = param_5;
  iStack_100 = param_4;
  if ((uVar38 & 0x1a) == 10) {
    if (-1 < *(short *)(iStack_68 + 0xe)) {
      pcVar44 = (char *)FUN_0022c4d0(iStack_6c,iStack_68,param_3,iStack_34,iStack_30,iStack_2c);
      return pcVar44;
    }
  }
  iStack_b8 = param_6;
  iStack_168 = 0;
  iStack_16c = 0;
  piVar31 = local_1b0;
  pcStack_78 = (char *)0x0;
  iStack_c4 = 0;
  pcStack_80 = (char *)0xffffffff;
  uStack_bc = 0;
  iStack_9c = 0;
  uStack_c0 = 0;
  ppuStack_a0 = apuStack_138;
  ppuStack_c8 = (undefined **)&cStack_139;
  pcStack_cc = &cStack_129;
  pcStack_d4 = acStack_124;
  pcStack_d0 = acStack_128 + 2;
  piStack_170 = piVar31;
LAB_0022c6a7:
  iVar34 = 0;
  if (*param_3 != 0) {
    if (*param_3 != 0x25) {
      do {
        iVar34 = iVar34 + 1;
        pbVar40 = param_3 + iVar34;
        bVar43 = *pbVar40;
        if (bVar43 == 0) break;
      } while (bVar43 != 0x25);
      if (iVar34 != 0) {
        *piVar31 = (int)param_3;
        piVar31[1] = iVar34;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          pbStack_4c = pbVar40;
          iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar32 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
          pbVar40 = pbStack_4c;
        }
        pcStack_78 = pcStack_78 + iVar34;
        bVar43 = *pbVar40;
      }
      param_3 = pbVar40;
      if (bVar43 == 0) goto LAB_0022cc3b;
    }
    param_3 = param_3 + 1;
    uVar38 = 0;
    abStack_11e[0] = 0;
    pcStack_7c = (char *)0x0;
    pcStack_74 = (char *)0x0;
    pcVar44 = (char *)0xffffffff;
LAB_0022c718:
    uStack_70 = (uint)*param_3;
    param_3 = param_3 + 1;
LAB_0022c721:
    iVar34 = iStack_16c;
    iVar32 = iStack_168;
    switch(uStack_70) {
    case 0x20:
      goto switchD_0022c735_caseD_20;
    default:
      if (uStack_70 == 0) break;
      abStack_11e[0] = 0;
      pcStack_84 = (char *)0x1;
      ppuStack_90 = (undefined **)auStack_160;
      auStack_160[0] = (char)uStack_70;
LAB_0022c755:
      uVar38 = (uint)abStack_11e[0];
LAB_0022c758:
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c763;
    case 0x23:
      pcStack_74 = (char *)((uint)pcStack_74 | 1);
      goto LAB_0022c718;
    case 0x2a:
      iVar32 = iStack_b8 + 4;
      iStack_b8 = iVar32;
      iVar34 = iStack_fc;
      if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
        iStack_b8 = iVar32;
      }
      pcStack_7c = *(char **)(iStack_b8 + iVar34 + -4);
      if (-1 < (int)pcStack_7c) goto LAB_0022c718;
      pcStack_7c = (char *)-(int)pcStack_7c;
    case 0x2d:
      pcStack_74 = (char *)((uint)pcStack_74 | 4);
      goto LAB_0022c718;
    case 0x2b:
      uVar38 = 0x2b;
      abStack_11e[0] = 0x2b;
      goto LAB_0022c718;
    case 0x2e:
      uStack_70 = (uint)*param_3;
      param_3 = param_3 + 1;
      if (uStack_70 == 0x2a) {
        iVar32 = iStack_b8 + 4;
        iStack_b8 = iVar32;
        iVar34 = iStack_fc;
        if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
          iStack_b8 = iVar32;
        }
        iVar34 = *(int *)(iStack_b8 + iVar34 + -4);
        pcVar44 = (char *)((uint)((int)pcStack_80 < iVar34) * iVar34 +
                          (uint)((int)pcStack_80 >= iVar34) * (int)pcStack_80);
        goto LAB_0022c718;
      }
      iVar34 = 0;
      if (uStack_70 - 0x30 < 10) {
        iVar32 = 0;
        do {
          pbVar40 = param_3 + iVar34;
          iVar32 = iVar32 * 10 + uStack_70;
          iVar34 = iVar34 + 1;
          uStack_70 = (uint)*pbVar40;
          iVar32 = iVar32 + -0x30;
        } while (*pbVar40 - 0x30 < 10);
      }
      else {
        iVar32 = 0;
      }
      param_3 = param_3 + iVar34;
      pcVar44 = (char *)((uint)(iVar32 < (int)pcStack_80) * (int)pcStack_80 +
                        (uint)(iVar32 >= (int)pcStack_80) * iVar32);
      goto LAB_0022c721;
    case 0x30:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x80);
      goto LAB_0022c718;
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      goto switchD_0022c735_caseD_31;
    case 0x44:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x10);
      goto switchD_0022c735_caseD_64;
    case 0x45:
    case 0x47:
    case 0x65:
    case 0x66:
    case 0x67:
      uVar38 = iStack_b8 + 7U & 0xfffffff8;
      iVar34 = uVar38 + 8;
      iStack_b8 = iVar34;
      if (((uint)pcStack_74 >> 3 & 1) == 0) {
        iVar32 = iStack_fc;
        if ((0x10 < (int)uVar38) && (iStack_b8 = 0x28, iVar32 = iStack_100, 0x18 < (int)uVar38)) {
          iStack_b8 = iVar34;
        }
        uStack_a8 = *(uint *)(iStack_b8 + iVar32 + -4);
        uStack_a4 = *(undefined4 *)(iStack_b8 + iVar32 + -8);
      }
      else {
        iVar32 = iStack_fc;
        if ((0x10 < (int)uVar38) && (iStack_b8 = 0x28, iVar32 = iStack_100, 0x18 < (int)uVar38)) {
          iStack_b8 = iVar34;
        }
        uStack_a8 = *(uint *)(iStack_b8 + iVar32 + -4);
        uStack_a4 = *(undefined4 *)(iStack_b8 + iVar32 + -8);
      }
      uVar5 = uStack_a4;
      uStack_e4 = uStack_a8;
      pcStack_64 = pcVar44;
      iVar34 = FUN_00230d10();
      if (iVar34 == 1) {
        iVar34 = FUN_0022b838(uVar5,uStack_e4,uStack_bc,uStack_c0);
        uVar38 = (uint)abStack_11e[0];
        if (iVar34 < 0) {
          uVar38 = 0x2d;
        }
        abStack_11e[0] = (byte)uVar38;
        if ((int)uStack_70 < 0x48) {
          ppuStack_90 = &PTR_DAT_00206424;
        }
        else {
          ppuStack_90 = (undefined **)0x206428;
        }
        pcStack_84 = (char *)0x3;
        pcStack_74 = (char *)((uint)pcStack_74 & 0xffffff7f);
        goto LAB_0022c758;
      }
      iVar34 = FUN_00230d10(uVar5,uStack_e4);
      if (iVar34 == 0) {
        if ((int)uStack_70 < 0x48) {
          ppuStack_90 = (undefined **)0x20642c;
        }
        else {
          ppuStack_90 = (undefined **)0x206430;
        }
        pcStack_84 = (char *)0x3;
        pcStack_74 = (char *)((uint)pcStack_74 & 0xffffff7f);
        goto LAB_0022c755;
      }
      pcStack_d8 = pcStack_64;
      if (pcStack_64 == (char *)0xffffffff) {
        pcStack_104 = (char *)0x6;
      }
      else {
        pcStack_104 = pcStack_64;
        if (((uStack_70 == 0x67) || (uStack_70 == 0x47)) && (pcStack_64 == (char *)0x0)) {
          pcStack_104 = (char *)0x1;
        }
      }
      uStack_118 = uVar5;
      uStack_114 = uStack_e4;
      uStack_f0 = uStack_e4;
      pcStack_74 = (char *)((uint)pcStack_74 | 0x100);
      if ((int)uStack_e4 < 0) {
        iStack_f4 = 0x2d;
        uStack_f0 = uStack_e4 ^ 0x80000000;
      }
      else {
        iStack_f4 = 0;
      }
      uStack_ec = uVar5;
      pcStack_e8 = pcStack_104;
      if ((uStack_70 == 0x66) || (uStack_70 == 0x46)) {
        uVar42 = 3;
      }
      else {
        if ((uStack_70 == 0x65) || (uStack_70 == 0x45)) {
          pcStack_e8 = pcStack_104 + 1;
        }
        uVar42 = 2;
      }
      ppuStack_e0 = (undefined **)
                    FUN_0022e990(iStack_6c,pcStack_104,uVar5,uStack_f0,uVar42,pcStack_e8,
                                 &pcStack_110,auStack_10c,&pcStack_108);
      if (((uStack_70 == 0x67) || (uStack_70 == 0x47)) && (((uint)pcStack_74 & 1) == 0)) {
        iStack_9c = (int)pcStack_108 - (int)ppuStack_e0;
        ppuVar54 = ppuStack_e0;
        uVar5 = uStack_118;
        uVar46 = uStack_114;
        pcVar33 = pcStack_108;
        pcVar44 = pcStack_104;
        iVar34 = iStack_100;
        iVar32 = iStack_fc;
        iVar55 = iStack_f8;
        iVar41 = iStack_f4;
        uVar48 = uStack_f0;
        uVar42 = uStack_ec;
        pcVar51 = pcStack_e8;
        uVar49 = uStack_e4;
        iVar6 = iStack_dc;
        pcVar47 = pcStack_d8;
        pcVar52 = pcStack_d4;
        pcVar53 = pcStack_d0;
        pcVar7 = pcStack_cc;
        ppuVar50 = ppuStack_c8;
        uVar8 = uStack_c0;
        uVar9 = uStack_bc;
        iVar10 = iStack_b8;
        iVar11 = iStack_b0;
        uVar12 = uStack_ac;
        uVar13 = uStack_a8;
        uVar14 = uStack_a4;
        ppuVar15 = ppuStack_a0;
        pcVar16 = pcStack_80;
        pcVar17 = pcStack_7c;
        pcVar18 = pcStack_78;
        pcVar19 = pcStack_74;
        iVar20 = iStack_6c;
        iVar21 = iStack_68;
        pcVar22 = pcStack_64;
        pcVar23 = pcStack_60;
        iVar24 = iStack_58;
        iVar25 = iStack_54;
        uVar26 = uStack_50;
        pbVar40 = pbStack_4c;
        iVar27 = iStack_34;
        iVar28 = iStack_30;
        iVar29 = iStack_2c;
      }
      else {
        pcVar44 = (char *)((int)ppuStack_e0 + (int)pcStack_e8);
        if ((uStack_70 == 0x66) || (uStack_70 == 0x46)) {
          pcStack_60 = pcVar44;
          if ((*(char *)ppuStack_e0 == '0') &&
             (iVar34 = FUN_0022b874(uStack_ec,uStack_f0,uStack_bc,uStack_c0), iVar34 != 0)) {
            pcStack_110 = (char *)(1 - (int)pcStack_e8);
          }
          pcVar44 = pcStack_60 + (int)pcStack_110;
        }
        iVar34 = FUN_0022b874(uStack_ec,uStack_f0,uStack_bc,uStack_c0);
        pcVar33 = pcStack_108;
        if (iVar34 == 0) {
          pcVar33 = pcVar44;
        }
        pcStack_108 = pcVar33;
        while (pcVar33 < pcVar44) {
          *pcVar33 = '0';
          pcVar33 = pcVar33 + 1;
          pcStack_108 = pcVar33;
        }
        iStack_9c = (int)pcVar33 - (int)ppuStack_e0;
        ppuVar54 = ppuStack_e0;
        uVar5 = uStack_118;
        uVar46 = uStack_114;
        pcVar44 = pcStack_104;
        iVar34 = iStack_100;
        iVar32 = iStack_fc;
        iVar55 = iStack_f8;
        iVar41 = iStack_f4;
        uVar48 = uStack_f0;
        uVar42 = uStack_ec;
        pcVar51 = pcStack_e8;
        uVar49 = uStack_e4;
        iVar6 = iStack_dc;
        pcVar47 = pcStack_d8;
        pcVar52 = pcStack_d4;
        pcVar53 = pcStack_d0;
        pcVar7 = pcStack_cc;
        ppuVar50 = ppuStack_c8;
        uVar8 = uStack_c0;
        uVar9 = uStack_bc;
        iVar10 = iStack_b8;
        iVar11 = iStack_b0;
        uVar12 = uStack_ac;
        uVar13 = uStack_a8;
        uVar14 = uStack_a4;
        ppuVar15 = ppuStack_a0;
        pcVar16 = pcStack_80;
        pcVar17 = pcStack_7c;
        pcVar18 = pcStack_78;
        pcVar19 = pcStack_74;
        iVar20 = iStack_6c;
        iVar21 = iStack_68;
        pcVar22 = pcStack_64;
        pcVar23 = pcStack_60;
        iVar24 = iStack_58;
        iVar25 = iStack_54;
        uVar26 = uStack_50;
        pbVar40 = pbStack_4c;
        iVar27 = iStack_34;
        iVar28 = iStack_30;
        iVar29 = iStack_2c;
      }
      if ((uStack_70 == 0x67) || (iVar35 = iStack_9c, uStack_70 == 0x47)) {
        if (((int)pcStack_110 < -3) || ((int)pcVar44 < (int)pcStack_110)) {
          uStack_70 = uStack_70 - 2;
          iVar35 = iStack_9c;
          goto joined_r0x0022db91;
        }
        uStack_70 = 0x67;
        if (iStack_9c <= (int)pcStack_110) goto LAB_0022dba6;
LAB_0022dbc3:
        if ((int)pcStack_110 < 1) {
          iVar35 = 2 - (int)pcStack_110;
        }
        else {
          iVar35 = 1;
        }
        pcStack_84 = (char *)(iVar35 + iStack_9c);
LAB_0022dbd0:
        pcStack_b4 = pcStack_110;
      }
      else {
joined_r0x0022db91:
        iStack_9c = iVar35;
        if (0x65 < (int)uStack_70) {
          if (uStack_70 == 0x66) {
            if ((int)pcStack_110 < 1) {
              if ((pcVar44 == (char *)0x0) && (((uint)pcVar19 & 1) == 0)) {
                pcStack_84 = (char *)0x1;
              }
              else {
                pcStack_84 = (char *)((int)pcVar44 + 2);
              }
            }
            else {
              pcStack_84 = pcStack_110;
              if ((pcVar44 != (char *)0x0) || (((uint)pcVar19 & 1) != 0)) {
                pcStack_84 = (char *)((int)pcVar44 + (int)pcStack_110) + 1;
              }
            }
          }
          else {
            if ((int)pcStack_110 < iVar35) goto LAB_0022dbc3;
LAB_0022dba6:
            pcStack_84 = pcStack_110;
            if (((uint)pcVar19 & 1) != 0) {
              pcStack_84 = (char *)((int)pcStack_110 + 1);
            }
          }
          goto LAB_0022dbd0;
        }
        acStack_128[0] = (char)uStack_70;
        pcVar56 = (char *)((int)pcStack_110 + -1);
        pcStack_110 = pcVar56;
        if ((int)pcVar56 < 0) {
          acStack_128[1] = 0x2d;
          pcVar56 = (char *)-(int)pcVar56;
        }
        else {
          acStack_128[1] = 0x2b;
        }
        pcVar57 = pcVar7;
        if ((int)pcVar56 < 10) {
          acStack_128[3] = (char)pcVar56 + '0';
          acStack_128[2] = '0';
          pcVar56 = pcVar52;
        }
        else {
          do {
            pcVar45 = pcVar57;
            iVar36 = (int)pcVar56 % 10;
            pcVar56 = (char *)((int)pcVar56 / 10);
            pcVar57 = pcVar45 + -1;
            *pcVar57 = (char)iVar36 + '0';
          } while (9 < (int)pcVar56);
          pcVar45[-2] = (char)pcVar56 + '0';
          if (pcVar45 + -2 < pcVar7) {
            pcVar37 = acStack_128;
            bVar1 = ((uint)(acStack_128 + -(int)pcVar57) & 7) != 0;
            pcVar56 = pcVar57;
            if (bVar1) {
              pcVar37 = acStack_128 + 1;
              acStack_128[2] = pcVar45[-2];
              pcVar56 = pcVar45;
            }
            uVar38 = (uint)bVar1;
            if ((uint)(acStack_128 + -(int)pcVar57) >> 3 != 0) {
              cVar30 = pcVar56[1];
              cVar2 = pcVar56[2];
              pcVar37[3] = *pcVar56;
              cVar3 = pcVar56[3];
              pcVar37[4] = cVar30;
              cVar30 = pcVar56[4];
              pcVar37[5] = cVar2;
              cVar2 = pcVar56[5];
              pcVar37[6] = cVar3;
              cVar3 = pcVar56[6];
              pcVar37[7] = cVar30;
              uVar38 = uVar38 + 8;
              pcVar37[8] = cVar2;
              cVar30 = pcVar56[-1];
              pcVar37[9] = cVar3;
              pcVar37[2] = cVar30;
            }
          }
          else {
            uVar38 = 0;
          }
          pcVar56 = (char *)((int)pcVar53 + uVar38);
        }
        iStack_c4 = (int)pcVar56 - (int)acStack_128;
        pcStack_84 = (char *)(((int)pcVar56 - (int)acStack_128) + iVar35);
        if ((1 < iVar35) || (((uint)pcVar19 & 1) != 0)) {
          pcStack_84 = pcStack_84 + 1;
        }
        pcStack_b4 = (char *)0x0;
      }
      ppuStack_90 = ppuVar54;
      uVar38 = 0;
      pcStack_8c = (char *)0x0;
      if (iVar41 != 0) {
        uVar38 = 0x2d;
      }
      abStack_11e[0] = (byte)uVar38;
      uStack_118 = uVar5;
      uStack_114 = uVar46;
      pcStack_108 = pcVar33;
      pcStack_104 = pcVar44;
      iStack_100 = iVar34;
      iStack_fc = iVar32;
      iStack_f8 = iVar55;
      iStack_f4 = iVar41;
      uStack_f0 = uVar48;
      uStack_ec = uVar42;
      pcStack_e8 = pcVar51;
      uStack_e4 = uVar49;
      ppuStack_e0 = ppuVar54;
      iStack_dc = iVar6;
      pcStack_d8 = pcVar47;
      pcStack_d4 = pcVar52;
      pcStack_d0 = pcVar53;
      pcStack_cc = pcVar7;
      ppuStack_c8 = ppuVar50;
      uStack_c0 = uVar8;
      uStack_bc = uVar9;
      iStack_b8 = iVar10;
      iStack_b0 = iVar11;
      uStack_ac = uVar12;
      uStack_a8 = uVar13;
      uStack_a4 = uVar14;
      ppuStack_a0 = ppuVar15;
      pcStack_80 = pcVar16;
      pcStack_7c = pcVar17;
      pcStack_78 = pcVar18;
      pcStack_74 = pcVar19;
      iStack_6c = iVar20;
      iStack_68 = iVar21;
      pcStack_64 = pcVar22;
      pcStack_60 = pcVar23;
      iStack_58 = iVar24;
      iStack_54 = iVar25;
      uStack_50 = uVar26;
      pbStack_4c = pbVar40;
      iStack_34 = iVar27;
      iStack_30 = iVar28;
      iStack_2c = iVar29;
      goto LAB_0022c763;
    case 0x4c:
      pcStack_74 = (char *)((uint)pcStack_74 | 8);
      goto LAB_0022c718;
    case 0x4f:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x10);
    case 0x6f:
      pcVar51 = pcStack_74;
      if (((uint)pcStack_74 >> 5 & 1) == 0) {
        if (((uint)pcStack_74 >> 4 & 1) == 0) {
          if (((uint)pcStack_74 >> 6 & 1) == 0) {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            uVar38 = *(uint *)(iStack_b8 + iVar55 + -4);
            uVar46 = 0;
          }
          else {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            uVar38 = (uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            uVar46 = 0;
          }
        }
        else {
          iVar41 = iStack_b8 + 4;
          iStack_b8 = iVar41;
          iVar55 = iStack_fc;
          if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
            iStack_b8 = iVar41;
          }
          uVar38 = *(uint *)(iStack_b8 + iVar55 + -4);
          uVar46 = 0;
        }
      }
      else {
        uVar38 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar38 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar38) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar38)) {
          iStack_b8 = uVar38 + 8;
        }
        uVar46 = *(uint *)(iStack_b8 + iVar55 + -4);
        uVar38 = *(uint *)(iStack_b8 + iVar55 + -8);
      }
      abStack_11e[0] = 0;
      pcStack_88 = (char *)((uint)pcStack_74 & 0xffffff7f);
      pcStack_74 = pcStack_88;
      if (((uVar38 != 0 || uVar46 != 0) || uVar46 != 0) || (pcVar44 != (char *)0x0)) {
        pcStack_8c = pcVar44;
        ppuVar54 = ppuStack_a0;
        do {
          ppuVar50 = ppuVar54;
          uVar48 = uVar38 & 7;
          ppuVar54 = (undefined **)((int)ppuVar50 + -1);
          uVar49 = uVar46 >> 3;
          uVar38 = (uint)(CONCAT44(uVar46,uVar38) >> 3);
          iVar41 = uVar48 + 0x30;
          iVar55 = iVar41;
          if (uVar38 != 0) {
            iVar55 = 1;
          }
          *(char *)ppuVar54 = (char)iVar41;
          uVar46 = uVar49;
        } while (iVar55 != 0 || uVar49 != 0);
        ppuStack_90 = ppuVar54;
        if ((((uint)pcVar51 & 1) != 0) && (iVar41 != 0x30)) {
          ppuStack_90 = (undefined **)((int)ppuVar50 + -2);
          *(char *)ppuStack_90 = '0';
        }
        pcStack_84 = (char *)((int)apuStack_138 - (int)ppuStack_90);
        pcStack_88 = pcStack_84;
        if ((int)pcStack_84 < (int)pcVar44) {
          pcStack_88 = pcVar44;
        }
        uStack_94 = 0;
        pcStack_88 = pcStack_88 + 2;
        pcStack_98 = (char *)((uint)pcVar51 & 4);
        if (((uint)pcVar51 & 4) != 0) {
LAB_0022d210:
          abStack_11e[0] = 0;
          pcStack_b4 = (char *)0x0;
          pcStack_8c = pcVar44;
          goto LAB_0022c821;
        }
joined_r0x0022e1fc:
        pcVar33 = pcStack_7c + -(int)pcStack_88;
      }
      else {
        ppuStack_90 = ppuStack_a0;
        pcStack_98 = (char *)((uint)pcVar51 & 4);
        uStack_94 = 0;
        if (((uint)pcVar51 & 1) == 0) {
          pcStack_84 = (char *)0x0;
          pcStack_8c = pcVar44;
          pcStack_88 = (char *)0x0;
          pcVar33 = pcStack_7c;
          if (((uint)pcVar51 & 4) == 0) goto joined_r0x0022d31d;
          goto LAB_0022d210;
        }
        pcStack_84 = (char *)0x1;
        pcStack_8c = pcVar44;
        cStack_139 = '0';
        ppuStack_90 = ppuStack_c8;
        if (((uint)pcVar51 & 4) != 0) goto LAB_0022d210;
joined_r0x0022d31d:
        uStack_94 = 0;
        pcStack_84 = (char *)0x1;
        pcVar33 = pcStack_7c + -(int)pcStack_88;
        ppuStack_90 = ppuStack_c8;
      }
joined_r0x0022d31d:
      abStack_11e[0] = 0;
      if ((int)pcVar33 < 1) goto LAB_0022d210;
LAB_0022d132:
      pcStack_b4 = (char *)0x0;
      pcStack_8c = pcVar44;
      goto joined_r0x0022c79d;
    case 0x55:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x10);
    case 0x75:
      pcVar33 = pcStack_74;
      if (((uint)pcStack_74 >> 5 & 1) == 0) {
        if (((uint)pcStack_74 >> 4 & 1) == 0) {
          if (((uint)pcStack_74 >> 6 & 1) == 0) {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
            pcVar51 = (char *)0x0;
          }
          else {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            uStack_ac = (uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            pcVar51 = (char *)0x0;
          }
        }
        else {
          iVar41 = iStack_b8 + 4;
          iStack_b8 = iVar41;
          iVar55 = iStack_fc;
          if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
            iStack_b8 = iVar41;
          }
          uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
          pcVar51 = (char *)0x0;
        }
      }
      else {
        uVar38 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar38 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar38) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar38)) {
          iStack_b8 = uVar38 + 8;
        }
        pcVar51 = *(char **)(iStack_b8 + iVar55 + -4);
        uStack_ac = *(uint *)(iStack_b8 + iVar55 + -8);
      }
      pcStack_d8 = pcVar44;
      ppuStack_90 = ppuStack_a0;
      ppuVar54 = ppuStack_a0;
      if (pcVar51 != (char *)0x0) {
        ppuVar54 = (undefined **)0x1;
      }
      ppuVar50 = ppuVar54;
      if (uStack_ac != 0) {
        ppuVar50 = (undefined **)0x1;
      }
      pcStack_74 = (char *)((uint)pcStack_74 & 0xffffff7f);
      uVar38 = 0;
      abStack_11e[0] = 0;
      if ((ppuVar50 == (undefined **)0x0 && ppuVar54 == (undefined **)0x0) &&
         (pcVar44 == (char *)0x0)) {
        pcStack_8c = pcVar44;
        pcStack_84 = (char *)0x0;
        uStack_94 = 0;
        pcStack_88 = (char *)0x2;
        pcStack_98 = (char *)((uint)pcVar33 & 4);
        if (((uint)pcVar33 & 4) != 0) goto LAB_0022d210;
        pcVar33 = pcStack_7c + -2;
        goto joined_r0x0022d31d;
      }
      pcStack_8c = pcVar44;
      bVar1 = false;
      if ((pcVar51 == (char *)0x0) && (uStack_ac < 10)) {
        bVar1 = true;
      }
      if (!bVar1) goto LAB_0022d787;
      ppuStack_90 = ppuStack_c8;
      pcStack_84 = (char *)0x1;
      pcStack_88 = (char *)0x1;
      if (1 < (int)pcVar44) {
        pcStack_88 = pcVar44;
      }
      uStack_94 = 0;
      cStack_139 = (char)uStack_ac + '0';
      pcStack_88 = pcStack_88 + 2;
      pcStack_98 = (char *)((uint)pcVar33 & 4);
      if (((uint)pcVar33 & 4) == 0) goto joined_r0x0022d31d;
      goto LAB_0022d210;
    case 0x58:
      pcVar33 = "0123456789ABCDEF";
      goto LAB_0022ce0a;
    case 99:
      iVar41 = iStack_b8 + 4;
      iStack_b8 = iVar41;
      iVar55 = iStack_fc;
      if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
        iStack_b8 = iVar41;
      }
      pcStack_84 = (char *)0x1;
      uStack_94 = 0;
      pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
      pcStack_88 = *(char **)(iStack_b8 + iVar55 + -4);
      auStack_160[0] = SUB41(pcStack_88,0);
      abStack_11e[0] = 0;
      if ((((uint)pcStack_74 & 0x84) == 0) &&
         (pcVar33 = pcStack_7c + -(int)pcStack_88, 0 < (int)pcVar33)) {
        ppuStack_90 = (undefined **)auStack_160;
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      ppuStack_90 = (undefined **)auStack_160;
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c821;
    case 100:
    case 0x69:
      goto switchD_0022c735_caseD_64;
    case 0x68:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x40);
      goto LAB_0022c718;
    case 0x6c:
      if (*param_3 == 0x6c) {
        pcStack_74 = (char *)((uint)pcStack_74 | 0x20);
        param_3 = param_3 + 1;
      }
      else {
        pcStack_74 = (char *)((uint)pcStack_74 | 0x10);
      }
      goto LAB_0022c718;
    case 0x6e:
      if (((uint)pcStack_74 >> 5 & 1) == 0) {
        if (((uint)pcStack_74 >> 4 & 1) == 0) {
          if (((uint)pcStack_74 >> 6 & 1) == 0) {
            iVar32 = iStack_b8 + 4;
            iStack_b8 = iVar32;
            iVar34 = iStack_fc;
            if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
              iStack_b8 = iVar32;
            }
            **(int **)(iStack_b8 + iVar34 + -4) = (int)pcStack_78;
          }
          else {
            iVar32 = iStack_b8 + 4;
            iStack_b8 = iVar32;
            iVar34 = iStack_fc;
            if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
              iStack_b8 = iVar32;
            }
            ae_s16i_n(pcStack_78,*(undefined4 *)(iStack_b8 + iVar34 + -4),0);
          }
        }
        else {
          iVar32 = iStack_b8 + 4;
          iStack_b8 = iVar32;
          iVar34 = iStack_fc;
          if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
            iStack_b8 = iVar32;
          }
          **(int **)(iStack_b8 + iVar34 + -4) = (int)pcStack_78;
        }
      }
      else {
        iVar32 = iStack_b8 + 4;
        iStack_b8 = iVar32;
        iVar34 = iStack_fc;
        if ((0x18 < iVar32) && (iStack_b8 = 0x24, iVar34 = iStack_100, 0x1c < iVar32)) {
          iStack_b8 = iVar32;
        }
        piVar39 = *(int **)(iStack_b8 + iVar34 + -4);
        *piVar39 = (int)pcStack_78;
        piVar39[1] = (int)pcStack_78 >> 0x1f;
      }
      goto LAB_0022c6a7;
    case 0x70:
      iVar41 = iStack_b8 + 4;
      iStack_b8 = iVar41;
      iVar55 = iStack_fc;
      if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
        iStack_b8 = iVar41;
      }
      ppuStack_90 = ppuStack_a0;
      uVar38 = (uint)pcStack_74 | 2;
      pcVar33 = (char *)((uint)pcStack_74 & 0xffffff7f | 2);
      pcVar51 = *(char **)(iStack_b8 + iVar55 + -4);
      uStack_120 = 0x30;
      pcStack_74 = pcVar51;
      if (-1 < (int)pcVar44) {
        pcStack_74 = pcVar33;
      }
      uStack_11f = 0x78;
      if (pcVar51 != (char *)0x0) {
        pcVar33 = (char *)0x1;
      }
      abStack_11e[0] = 0;
      uVar46 = 0;
      if ((pcVar33 != (char *)0x0 || uVar38 != 0) || (pcVar44 != (char *)0x0)) {
        pcVar33 = "0123456789abcdef";
        uStack_70 = 0x78;
        goto LAB_0022d0af;
      }
      pcStack_8c = pcVar44;
      pcStack_84 = (char *)0x0;
      uStack_94 = (uint)pcStack_74 & 2;
      pcStack_88 = (char *)0x2;
      pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
      if ((((uint)pcStack_74 & 0x84) == 0) && (pcVar33 = pcStack_7c + -2, 0 < (int)pcVar33)) {
        uStack_70 = 0x78;
        pcStack_b4 = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      uStack_70 = 0x78;
      pcStack_b4 = (char *)0x0;
      goto LAB_0022c821;
    case 0x71:
      pcStack_74 = (char *)((uint)pcStack_74 | 0x20);
      goto LAB_0022c718;
    case 0x73:
      iVar41 = iStack_b8 + 4;
      iStack_b8 = iVar41;
      iVar55 = iStack_fc;
      if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
        iStack_b8 = iVar41;
      }
      ppuStack_90 = *(undefined ***)(iStack_b8 + iVar55 + -4);
      abStack_11e[0] = 0;
      if (ppuStack_90 != (undefined **)0x0) {
        if ((int)pcVar44 < 0) {
          pcStack_d8 = pcVar44;
          pcStack_84 = (char *)FUN_00230e50(ppuStack_90);
        }
        else {
          pcStack_d8 = pcVar44;
          iVar34 = FUN_00230340(ppuStack_90,0,pcVar44);
          iVar32 = iVar34 - (int)ppuStack_90;
          pcStack_84 = (char *)((uint)((int)pcStack_d8 < iVar32) * (int)pcStack_d8 +
                               (uint)((int)pcStack_d8 >= iVar32) * iVar32);
          if (iVar34 == 0) {
            pcStack_84 = pcStack_d8;
          }
        }
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        uVar38 = (uint)abStack_11e[0];
        goto LAB_0022c763;
      }
      if ((char *)0x6 < pcVar44) {
        pcVar44 = (char *)0x6;
      }
      pcStack_84 = pcVar44;
      uStack_94 = 0;
      pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
      pcStack_88 = pcStack_98;
      if ((((uint)pcStack_74 & 0x84) == 0) &&
         (pcVar33 = pcStack_7c + -(int)pcStack_98, 0 < (int)pcVar33)) {
        ppuStack_90 = (undefined **)0x206448;
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      ppuStack_90 = (undefined **)0x206448;
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c821;
    case 0x78:
      pcVar33 = "0123456789abcdef";
LAB_0022ce0a:
      if (((uint)pcStack_74 >> 5 & 1) == 0) {
        if (((uint)pcStack_74 >> 4 & 1) == 0) {
          if (((uint)pcStack_74 >> 6 & 1) == 0) {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            pcVar51 = *(char **)(iStack_b8 + iVar55 + -4);
            uVar46 = 0;
          }
          else {
            iVar41 = iStack_b8 + 4;
            iStack_b8 = iVar41;
            iVar55 = iStack_fc;
            if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
              iStack_b8 = iVar41;
            }
            pcVar51 = (char *)(uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            uVar46 = 0;
          }
        }
        else {
          iVar41 = iStack_b8 + 4;
          iStack_b8 = iVar41;
          iVar55 = iStack_fc;
          if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
            iStack_b8 = iVar41;
          }
          pcVar51 = *(char **)(iStack_b8 + iVar55 + -4);
          uVar46 = 0;
        }
      }
      else {
        uVar38 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar38 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar38) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar38)) {
          iStack_b8 = uVar38 + 8;
        }
        uVar46 = *(uint *)(iStack_b8 + iVar55 + -4);
        pcVar51 = *(char **)(iStack_b8 + iVar55 + -8);
      }
      if (((uint)pcStack_74 & 1) != 0) {
        pcVar47 = pcVar51;
        if (uVar46 != 0) {
          pcVar47 = (char *)0x1;
        }
        uVar38 = uVar46;
        if (pcVar51 != (char *)0x0) {
          uVar38 = 1;
        }
        if (uVar38 != 0 || pcVar47 != (char *)0x0) {
          uStack_120 = 0x30;
          uStack_11f = (char)uStack_70;
          pcStack_74 = (char *)((uint)pcStack_74 | 2);
        }
      }
      pcVar47 = pcStack_74;
      if (uVar46 != 0) {
        pcVar47 = (char *)0x1;
      }
      pcVar52 = pcVar47;
      if (pcVar51 != (char *)0x0) {
        pcVar52 = (char *)0x1;
      }
      abStack_11e[0] = 0;
      pcVar53 = (char *)((uint)pcStack_74 & 0xffffff7f);
      pcStack_74 = (char *)0x0;
      if (-1 < (int)pcVar44) {
        pcStack_74 = pcVar53;
      }
      ppuStack_90 = ppuStack_a0;
      if ((pcVar52 == (char *)0x0 && pcVar47 == (char *)0x0) && (pcVar44 == (char *)0x0)) {
        pcStack_8c = pcVar44;
        pcStack_84 = (char *)0x0;
        uStack_94 = (uint)pcStack_74 & 2;
        pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
        pcStack_88 = (char *)((uint)pcStack_74 & 0x84);
        if (((uint)pcStack_74 & 2) != 0) {
          pcStack_88 = (char *)0x2;
        }
      }
      else {
LAB_0022d0af:
        abStack_11e[0] = 0;
        ppuVar54 = ppuStack_a0;
        do {
          uVar38 = (uint)pcVar51 & 0xf;
          ppuVar54 = (undefined **)((int)ppuVar54 + -1);
          uVar48 = uVar46 >> 4;
          pcVar51 = (char *)(CONCAT44(uVar46,pcVar51) >> 4);
          pcVar47 = pcVar33 + uVar38;
          cVar30 = *pcVar47;
          if (pcVar51 != (char *)0x0) {
            pcVar47 = (char *)0x1;
          }
          *(char *)ppuVar54 = cVar30;
          uVar46 = uVar48;
        } while (pcVar47 != (char *)0x0 || uVar48 != 0);
        ppuStack_90 = ppuVar54;
        pcStack_8c = pcVar44;
        pcStack_84 = (char *)((int)apuStack_138 - (int)ppuVar54);
        pcStack_88 = pcStack_84;
        if ((int)pcStack_84 < (int)pcVar44) {
          pcStack_88 = pcVar44;
        }
        uStack_94 = (uint)pcStack_74 & 2;
        pcStack_88 = pcStack_88 + 2;
        pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
      }
      if (((uint)pcStack_74 & 0x84) == 0) goto joined_r0x0022e1fc;
      goto LAB_0022d210;
    }
  }
LAB_0022cc3b:
  if (iStack_168 != 0) {
    FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
    ppcVar4 = &pcStack_80;
    if ((*(ushort *)(iStack_68 + 0xc) & 0x40) == 0) {
      ppcVar4 = &pcStack_78;
    }
    return *ppcVar4;
  }
LAB_0022c8a9:
  ppcVar4 = &pcStack_80;
  if ((*(ushort *)(iStack_68 + 0xc) & 0x40) == 0) {
    ppcVar4 = &pcStack_78;
  }
  return *ppcVar4;
switchD_0022c735_caseD_64:
  if (((uint)pcStack_74 >> 5 & 1) == 0) {
    if (((uint)pcStack_74 >> 4 & 1) == 0) {
      if (((uint)pcStack_74 >> 6 & 1) == 0) {
        iVar41 = iStack_b8 + 4;
        iStack_b8 = iVar41;
        iVar55 = iStack_fc;
        if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
          iStack_b8 = iVar41;
        }
        uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
        pcVar51 = (char *)((int)uStack_ac >> 0x1f);
      }
      else {
        iVar41 = iStack_b8 + 4;
        iStack_b8 = iVar41;
        iVar55 = iStack_fc;
        if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
          iStack_b8 = iVar41;
        }
        uStack_ac = (uint)*(short *)(iStack_b8 + iVar55 + -4);
        pcVar51 = (char *)((int)uStack_ac >> 0x1f);
      }
    }
    else {
      iVar41 = iStack_b8 + 4;
      iStack_b8 = iVar41;
      iVar55 = iStack_fc;
      if ((0x18 < iVar41) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar41)) {
        iStack_b8 = iVar41;
      }
      uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
      pcVar51 = (char *)((int)uStack_ac >> 0x1f);
    }
  }
  else {
    uVar46 = iStack_b8 + 7U & 0xfffffff8;
    iStack_b8 = uVar46 + 8;
    iVar55 = iStack_fc;
    if ((0x10 < (int)uVar46) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar46)) {
      iStack_b8 = uVar46 + 8;
    }
    pcVar51 = *(char **)(iStack_b8 + iVar55 + -4);
    uStack_ac = *(uint *)(iStack_b8 + iVar55 + -8);
  }
  pcStack_d8 = pcVar44;
  pcVar33 = pcVar51;
  if (-1 < (int)pcVar44) {
    pcVar33 = (char *)((uint)pcStack_74 & 0xffffff7f);
  }
  if (((int)pcVar51 < 1) && (pcVar51 != (char *)0x0)) {
    pcStack_74 = pcVar33;
    uStack_ac = -uStack_ac;
    pcVar51 = (char *)(((uint)pcVar51 ^ 0xffffffff) + 1);
    pcVar47 = pcVar51;
    if (uStack_ac != 0) {
      pcVar47 = (char *)0x1;
    }
    ppuStack_90 = ppuStack_a0;
    uVar38 = 0x2d;
    abStack_11e[0] = 0x2d;
    if (pcVar47 == (char *)0x0 && pcVar51 == (char *)0x0) {
      if (pcVar44 == (char *)0x0) {
        pcStack_8c = pcVar44;
        pcStack_84 = (char *)0x0;
        uStack_94 = (uint)pcVar33 & 2;
        pcStack_98 = (char *)((uint)pcVar33 & 0x84);
        pcStack_88 = (char *)0x1;
        if (((uint)pcVar33 & 2) != 0) {
          pcStack_88 = (char *)0x3;
        }
      }
      else {
        bVar1 = false;
        if ((pcVar51 == (char *)0x0) && (uStack_ac < 10)) {
          bVar1 = true;
        }
        if (!bVar1) goto LAB_0022d787;
        pcStack_8c = pcVar44;
        ppuStack_90 = ppuStack_c8;
        pcStack_84 = (char *)0x1;
        uStack_94 = (uint)pcVar33 & 2;
        cStack_139 = (char)uStack_ac + '0';
        pcVar51 = (char *)0x1;
        if (1 < (int)pcVar44) {
          pcVar51 = pcVar44;
        }
        pcStack_98 = (char *)((uint)pcVar33 & 0x84);
        pcStack_88 = pcVar51 + 1;
        if (((uint)pcVar33 & 2) != 0) {
          pcStack_88 = pcVar51 + 3;
        }
      }
      pcStack_98 = (char *)((uint)pcVar33 & 0x84);
    }
    else {
      bVar1 = false;
      if ((pcVar51 == (char *)0x0) && (uStack_ac < 10)) {
        bVar1 = true;
      }
      if (!bVar1) goto LAB_0022d787;
      pcStack_8c = pcVar44;
      ppuStack_90 = ppuStack_c8;
      pcStack_84 = (char *)0x1;
      uStack_94 = (uint)pcVar33 & 2;
      cStack_139 = (char)uStack_ac + '0';
      pcVar51 = (char *)0x1;
      if (1 < (int)pcVar44) {
        pcVar51 = pcVar44;
      }
      pcStack_98 = (char *)((uint)pcVar33 & 0x84);
      pcStack_88 = pcVar51 + 1;
      if (((uint)pcVar33 & 2) != 0) {
        pcStack_88 = pcVar51 + 3;
      }
    }
    if ((((uint)pcVar33 & 0x84) == 0) && (pcVar33 = pcStack_7c + -(int)pcStack_88, 0 < (int)pcVar33)
       ) goto LAB_0022d132;
    pcStack_b4 = (char *)0x0;
    pcStack_8c = pcVar44;
    goto LAB_0022c7fa;
  }
  pcStack_74 = pcVar33;
  pcVar33 = pcVar51;
  if (uStack_ac != 0) {
    pcVar33 = (char *)0x1;
  }
  ppuStack_90 = ppuStack_a0;
  if ((((uint)pcVar33 | 1) != 0) || (pcVar44 != (char *)0x0)) {
    bVar1 = false;
    if ((pcVar51 == (char *)0x0) && (uStack_ac < 10)) {
      bVar1 = true;
    }
    if (bVar1) {
      cStack_139 = (char)uStack_ac + '0';
      ppuStack_90 = ppuStack_c8;
    }
    else {
LAB_0022d787:
      ppuStack_90 = ppuStack_a0;
      pcStack_d8 = pcVar44;
      uStack_50 = uVar38;
      do {
        ppuStack_90 = (undefined **)((int)ppuStack_90 + -1);
        cVar30 = FUN_00236540(uStack_ac,pcVar51,10,0);
        *(char *)ppuStack_90 = cVar30 + '0';
        uVar58 = __udivdi3(uStack_ac,pcVar51,10,0);
        pcVar51 = (char *)((ulonglong)uVar58 >> 0x20);
        uStack_ac = (uint)uVar58;
        pcVar44 = pcVar51;
        if ((uint)uVar58 != 0) {
          pcVar44 = (char *)0x1;
        }
        uVar38 = uStack_50;
      } while (((uint)pcVar44 | 1) != 0);
    }
  }
  pcStack_8c = pcStack_d8;
  pcStack_b4 = (char *)0x0;
  pcStack_84 = (char *)((int)apuStack_138 - (int)ppuStack_90);
LAB_0022c763:
  pcVar44 = pcStack_84;
  if ((int)pcStack_84 < (int)pcStack_8c) {
    pcVar44 = pcStack_8c;
  }
  pcVar33 = (char *)((uint)pcStack_74 & 0x84);
  if (uVar38 != 0) {
    pcVar33 = pcVar44 + 1;
  }
  uStack_94 = (uint)pcStack_74 & 2;
  pcStack_98 = (char *)((uint)pcStack_74 & 0x84);
  pcStack_88 = pcVar33 + 2;
  if ((((uint)pcStack_74 & 0x84) != 0) ||
     (pcVar33 = pcStack_7c + -(int)(pcVar33 + 2), iVar34 = iStack_16c, iVar32 = iStack_168,
     (int)pcVar33 < 1)) goto LAB_0022c7f8;
joined_r0x0022c79d:
  do {
    if ((int)pcVar33 < 0x11) goto LAB_0022c7d8;
    piVar31[1] = 0x10;
    *piVar31 = (int)&PTR_DAT_00205e90;
    iStack_168 = iVar32 + 0x10;
    iStack_16c = iVar34 + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
    pcVar33 = pcVar33 + -0x10;
    iVar34 = iStack_16c;
    iVar32 = iStack_168;
  } while( true );
switchD_0022c735_caseD_31:
  pcStack_7c = (char *)0x0;
  do {
    bVar43 = *param_3;
    iVar34 = (int)pcStack_7c * 10 + uStack_70;
    uStack_70 = (uint)bVar43;
    pcStack_7c = (char *)(iVar34 - 0x30);
    param_3 = param_3 + 1;
  } while (bVar43 - 0x30 < 10);
  goto LAB_0022c721;
LAB_0022c7d8:
  piVar31[1] = (int)pcVar33;
  *piVar31 = (int)&PTR_DAT_00205e90;
  iStack_168 = iVar32 + (int)pcVar33;
  iStack_16c = iVar34 + 1;
  piVar31 = piVar31 + 2;
  if (7 < iStack_16c) {
    iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
    if (iVar34 != 0) goto LAB_0022c8a9;
    piVar31 = local_1b0;
  }
  uVar38 = (uint)abStack_11e[0];
LAB_0022c7f8:
  if (uVar38 != 0) {
LAB_0022c7fa:
    piVar31[1] = 1;
    *piVar31 = (int)abStack_11e;
    iStack_168 = iStack_168 + 1;
    iStack_16c = iStack_16c + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
  }
LAB_0022c821:
  if (uStack_94 != 0) {
    piVar31[1] = 2;
    *piVar31 = (int)&uStack_120;
    iStack_168 = iStack_168 + 2;
    iStack_16c = iStack_16c + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
  }
  if ((pcStack_98 == (char *)0x80) &&
     (iVar34 = (int)pcStack_7c - (int)pcStack_88, iVar32 = iStack_16c, iVar55 = iStack_168,
     0 < iVar34)) {
    for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
      piVar31[1] = 0x10;
      *piVar31 = (int)&DAT_00205e80;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar32 + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar32 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar32 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar31[1] = iVar34;
    *piVar31 = (int)&DAT_00205e80;
    iStack_168 = iVar55 + iVar34;
    iStack_16c = iVar32 + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
  }
  iVar34 = (int)pcStack_8c - (int)pcStack_84;
  iVar32 = iStack_16c;
  iVar55 = iStack_168;
  if (0 < iVar34) {
    for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
      piVar31[1] = 0x10;
      *piVar31 = (int)&DAT_00205e80;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar32 + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar32 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar32 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar31[1] = iVar34;
    *piVar31 = (int)&DAT_00205e80;
    iStack_168 = iVar55 + iVar34;
    iStack_16c = iVar32 + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
  }
  pcVar44 = pcStack_84;
  if (((uint)pcStack_74 >> 8 & 1) == 0) {
    piVar31[1] = (int)pcStack_84;
    *piVar31 = (int)ppuStack_90;
    iStack_168 = iStack_168 + (int)pcVar44;
    iStack_16c = iStack_16c + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
      goto joined_r0x0022e356;
    }
  }
  else if ((int)uStack_70 < 0x66) {
    if ((iStack_9c < 2) && (((uint)pcStack_74 & 1) == 0)) {
      piVar31[1] = 1;
      *piVar31 = (int)ppuStack_90;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
joined_r0x0022dd7d:
        if (iVar34 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
    }
    else {
      piVar31[1] = 1;
      ppuVar54 = ppuStack_90;
      *piVar31 = (int)ppuStack_90;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar34 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar34 = iStack_b0;
      *piVar31 = iStack_f8;
      piVar31[1] = iVar34;
      iStack_168 = iStack_168 + iVar34;
      iStack_16c = iStack_16c + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar34 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iStack_dc = iStack_9c + -1;
      iVar32 = FUN_0022b874(uStack_a4,uStack_a8,uStack_bc,uStack_c0);
      iVar34 = iStack_9c;
      if (iVar32 == 0) {
        if (1 < iStack_9c) {
          iVar34 = iStack_dc;
          if (0x11 < iStack_9c) {
            do {
              piVar31[1] = 0x10;
              *piVar31 = (int)&DAT_00205e80;
              iStack_168 = iStack_168 + 0x10;
              iStack_16c = iStack_16c + 1;
              piVar31 = piVar31 + 2;
              if (7 < iStack_16c) {
                iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
                if (iVar32 != 0) goto LAB_0022c8a9;
                piVar31 = local_1b0;
              }
              iVar34 = iVar34 + -0x10;
            } while (0x10 < iVar34);
          }
          piVar31[1] = iVar34;
          *piVar31 = (int)&DAT_00205e80;
          iStack_168 = iStack_168 + iVar34;
          iStack_16c = iStack_16c + 1;
          piVar31 = piVar31 + 2;
          if (7 < iStack_16c) {
            iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
            goto joined_r0x0022dd7d;
          }
        }
      }
      else {
        piVar31[1] = iStack_dc;
        *piVar31 = (int)((int)ppuVar54 + 1);
        iStack_16c = iStack_16c + 1;
        iStack_168 = iStack_168 + iVar34 + -1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022dd7d;
        }
      }
    }
    iVar34 = iStack_c4;
    piVar31[1] = iStack_c4;
    *piVar31 = (int)acStack_128;
    iStack_168 = iStack_168 + iVar34;
    iStack_16c = iStack_16c + 1;
    piVar31 = piVar31 + 2;
    if (7 < iStack_16c) {
      iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
joined_r0x0022e356:
      if (iVar34 != 0) goto LAB_0022c8a9;
      piVar31 = local_1b0;
    }
  }
  else {
    iVar34 = FUN_0022b874(uStack_a4,uStack_a8,uStack_bc,uStack_c0);
    if (iVar34 == 0) {
      piVar31[1] = 1;
      *piVar31 = (int)&DAT_00206464;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar34 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar34 = iStack_b0;
      if (((int)pcStack_110 < iStack_9c) || (((uint)pcStack_74 & 1) != 0)) {
        *piVar31 = iStack_f8;
        piVar31[1] = iVar34;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
        }
        iVar34 = iStack_9c + -1;
        if (1 < iStack_9c) {
          if (0x11 < iStack_9c) {
            do {
              piVar31[1] = 0x10;
              *piVar31 = (int)&DAT_00205e80;
              iStack_168 = iStack_168 + 0x10;
              iStack_16c = iStack_16c + 1;
              piVar31 = piVar31 + 2;
              if (7 < iStack_16c) {
                iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
                if (iVar32 != 0) goto LAB_0022c8a9;
                piVar31 = local_1b0;
              }
              iVar34 = iVar34 + -0x10;
            } while (0x10 < iVar34);
          }
          piVar31[1] = iVar34;
          *piVar31 = (int)&DAT_00205e80;
          iStack_168 = iStack_168 + iVar34;
          iStack_16c = iStack_16c + 1;
          piVar31 = piVar31 + 2;
          if (7 < iStack_16c) {
            iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
            goto joined_r0x0022e356;
          }
        }
      }
    }
    else if ((int)pcStack_110 < 1) {
      piVar31[1] = 1;
      *piVar31 = (int)&DAT_00206464;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar34 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar34 = iStack_b0;
      if (((pcStack_110 != (char *)0x0) || (iStack_9c != 0)) || (((uint)pcStack_74 & 1) != 0)) {
        *piVar31 = iStack_f8;
        piVar31[1] = iVar34;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
        }
        iVar34 = -(int)pcStack_110;
        iVar32 = iStack_16c;
        iVar55 = iStack_168;
        if (0 < iVar34) {
          for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
            piVar31[1] = 0x10;
            *piVar31 = (int)&DAT_00205e80;
            iStack_168 = iVar55 + 0x10;
            iStack_16c = iVar32 + 1;
            piVar31 = piVar31 + 2;
            if (7 < iStack_16c) {
              iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
              if (iVar32 != 0) goto LAB_0022c8a9;
              piVar31 = local_1b0;
            }
            iVar32 = iStack_16c;
            iVar55 = iStack_168;
          }
          piVar31[1] = iVar34;
          *piVar31 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + iVar34;
          iStack_16c = iVar32 + 1;
          piVar31 = piVar31 + 2;
          if (7 < iStack_16c) {
            iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
            if (iVar34 != 0) goto LAB_0022c8a9;
            piVar31 = local_1b0;
          }
        }
        iVar34 = iStack_9c;
        piVar31[1] = iStack_9c;
        *piVar31 = (int)ppuStack_90;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022e356;
        }
      }
    }
    else {
      iVar34 = (uint)((int)pcStack_b4 < iStack_9c) * (int)pcStack_b4 +
               (uint)((int)pcStack_b4 >= iStack_9c) * iStack_9c;
      if (0 < iVar34) {
        iStack_54 = iVar34;
        piVar31[1] = iVar34;
        *piVar31 = (int)ppuStack_90;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
          iVar34 = iStack_54;
        }
      }
      iVar34 = (int)pcStack_b4 - (uint)(-1 < iVar34) * iVar34;
      iVar32 = iStack_16c;
      iVar55 = iStack_168;
      if (0 < iVar34) {
        for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
          piVar31[1] = 0x10;
          *piVar31 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + 0x10;
          iStack_16c = iVar32 + 1;
          piVar31 = piVar31 + 2;
          if (7 < iStack_16c) {
            iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
            if (iVar32 != 0) goto LAB_0022c8a9;
            piVar31 = local_1b0;
          }
          iVar32 = iStack_16c;
          iVar55 = iStack_168;
        }
        piVar31[1] = iVar34;
        *piVar31 = (int)&DAT_00205e80;
        iStack_168 = iVar55 + iVar34;
        iStack_16c = iVar32 + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
        }
      }
      ppuVar54 = ppuStack_90;
      iVar34 = iStack_b0;
      ppuStack_90 = (undefined **)((int)ppuStack_90 + (int)pcStack_b4);
      if (((int)pcStack_110 < iStack_9c) || (((uint)pcStack_74 & 1) != 0)) {
        *piVar31 = iStack_f8;
        piVar31[1] = iVar34;
        iStack_168 = iStack_168 + iVar34;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
        }
      }
      iVar34 = iStack_9c - (int)pcStack_110;
      pcVar44 = (char *)((int)ppuVar54 + (iStack_9c - (int)ppuStack_90));
      iVar32 = (uint)(iVar34 < (int)pcVar44) * iVar34 +
               (uint)(iVar34 >= (int)pcVar44) * (int)pcVar44;
      if (0 < iVar32) {
        iStack_58 = iVar32;
        *piVar31 = (int)ppuStack_90;
        piVar31[1] = iVar32;
        iStack_168 = iStack_168 + iVar32;
        iStack_16c = iStack_16c + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          if (iVar34 != 0) goto LAB_0022c8a9;
          piVar31 = local_1b0;
          iVar32 = iStack_58;
        }
        iVar34 = iStack_9c - (int)pcStack_110;
      }
      iVar34 = iVar34 - (uint)(-1 < iVar32) * iVar32;
      iVar32 = iStack_16c;
      iVar55 = iStack_168;
      if (0 < iVar34) {
        for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
          piVar31[1] = 0x10;
          *piVar31 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + 0x10;
          iStack_16c = iVar32 + 1;
          piVar31 = piVar31 + 2;
          if (7 < iStack_16c) {
            iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
            if (iVar32 != 0) goto LAB_0022c8a9;
            piVar31 = local_1b0;
          }
          iVar32 = iStack_16c;
          iVar55 = iStack_168;
        }
        piVar31[1] = iVar34;
        *piVar31 = (int)&DAT_00205e80;
        iStack_168 = iVar55 + iVar34;
        iStack_16c = iVar32 + 1;
        piVar31 = piVar31 + 2;
        if (7 < iStack_16c) {
          iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022e356;
        }
      }
    }
  }
  if ((((uint)pcStack_74 & 4) != 0) &&
     (iVar34 = (int)pcStack_7c - (int)pcStack_88, iVar32 = iStack_16c, iVar55 = iStack_168,
     0 < iVar34)) {
    for (; 0x10 < iVar34; iVar34 = iVar34 + -0x10) {
      piVar31[1] = 0x10;
      *piVar31 = (int)&PTR_DAT_00205e90;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar32 + 1;
      piVar31 = piVar31 + 2;
      if (7 < iStack_16c) {
        iVar32 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170);
        if (iVar32 != 0) goto LAB_0022c8a9;
        piVar31 = local_1b0;
      }
      iVar32 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar31[1] = iVar34;
    *piVar31 = (int)&PTR_DAT_00205e90;
    iStack_168 = iVar55 + iVar34;
    iStack_16c = iVar32 + 1;
    if ((7 < iStack_16c) && (iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170), iVar34 != 0))
    goto LAB_0022c8a9;
  }
  pcVar44 = pcStack_88;
  if ((int)pcStack_88 < (int)pcStack_7c) {
    pcVar44 = pcStack_7c;
  }
  pcStack_78 = pcStack_78 + (int)pcVar44;
  if ((iStack_168 != 0) && (iVar34 = FUN_00230ec0(iStack_6c,iStack_68,&piStack_170), iVar34 != 0))
  goto LAB_0022c8a9;
  iStack_16c = 0;
  piVar31 = local_1b0;
  goto LAB_0022c6a7;
switchD_0022c735_caseD_20:
  if (uVar38 == 0) {
    uVar38 = 0x20;
  }
  abStack_11e[0] = (byte)uVar38;
  goto LAB_0022c718;
}


// ===== FUN_0022e630 @ 0022e630 (214 bytes)

undefined4 FUN_0022e630(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((PTR_DAT_00237f00 != (undefined *)0x0) && (*(int *)(PTR_DAT_00237f00 + 0x38) == 0)) {
    FUN_0022fd00();
  }
  uVar1 = *(ushort *)(param_2 + 3);
  uVar3 = (uint)(short)uVar1;
  iVar4 = param_2[4];
  if ((uVar3 >> 3 & 1) == 0) {
    if ((uVar3 >> 4 & 1) == 0) {
      *param_1 = 9;
      *(ushort *)(param_2 + 3) = uVar1 | 0x40;
      return 0xffffffff;
    }
    if ((uVar3 & 4) == 0) {
      iVar4 = param_2[4];
    }
    else {
      if ((int *)param_2[0xc] != (int *)0x0) {
        if ((int *)param_2[0xc] != param_2 + 0x10) {
          FUN_0022fe50(param_1);
          uVar3 = (uint)(short)param_2[3];
        }
        param_2[0xc] = 0;
      }
      param_2[1] = 0;
      iVar4 = param_2[4];
      *param_2 = iVar4;
      uVar3 = uVar3 & 0xffffffdb;
      *(short *)(param_2 + 3) = (short)uVar3;
    }
    uVar3 = uVar3 | 8;
    *(short *)(param_2 + 3) = (short)uVar3;
  }
  if ((iVar4 == 0) && (((uVar3 & 0x200) == 0 || ((uVar3 & 0x80) != 0)))) {
    FUN_00230230(param_1,param_2);
    uVar3 = (uint)(short)param_2[3];
    iVar4 = param_2[4];
  }
  if ((uVar3 & 1) == 0) {
    iVar2 = 0;
    if ((uVar3 >> 1 & 1) == 0) {
      iVar2 = param_2[5];
    }
    param_2[2] = iVar2;
  }
  else {
    param_2[2] = 0;
    param_2[6] = -param_2[5];
  }
  if ((iVar4 == 0) && ((uVar3 & 0x80) != 0)) {
    *(ushort *)(param_2 + 3) = (ushort)uVar3 | 0x40;
    return 0xffffffff;
  }
  return 0;
}


// ===== FUN_0022e710 @ 0022e710 (48 bytes)

undefined4 FUN_0022e710(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = *(undefined **)(PTR_DAT_00237f00 + 0x148);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = PTR_DAT_00237f00 + 0x14c;
    *(undefined **)(PTR_DAT_00237f00 + 0x148) = puVar1;
  }
  iVar2 = *(int *)(puVar1 + 4);
  if (0x1f < iVar2) {
    return 0xffffffff;
  }
  *(int *)(puVar1 + 4) = iVar2 + 1;
  *(undefined4 *)(puVar1 + iVar2 * 4 + 8) = param_1;
  return 0;
}


// ===== FUN_0022e740 @ 0022e740 (204 bytes)

void FUN_0022e740(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  
LAB_0022e749:
  puVar4 = DAT_00237c20;
  puVar2 = &DAT_00237c20;
  do {
    puVar1 = puVar2;
    puVar2 = puVar4;
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    uVar3 = puVar2[1] - 1;
    puVar4 = puVar2 + uVar3;
    if (-1 < (int)uVar3) {
      do {
        if ((param_2 == 0) || ((puVar2 != (undefined4 *)0xffffff78 && (puVar4[0x42] == param_2)))) {
          pcVar6 = (code *)puVar4[2];
          if (puVar2[1] - 1 == uVar3) {
            puVar2[1] = puVar2[1] - 1;
          }
          else {
            puVar4[2] = 0;
          }
          if (pcVar6 != (code *)0x0) {
            iVar7 = puVar2[1];
            if ((puVar2 == (undefined4 *)0xffffff78) ||
               (uVar5 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f)), (uVar5 & puVar2[0x62]) == 0)) {
              (*pcVar6)();
            }
            else if ((uVar5 & puVar2[99]) == 0) {
              (*pcVar6)(param_1);
            }
            else {
              (*pcVar6)(puVar4[0x22]);
            }
            if ((puVar2[1] != iVar7) || ((undefined4 *)*puVar1 != puVar2)) goto LAB_0022e749;
          }
        }
        uVar3 = uVar3 - 1;
        puVar4 = puVar4 + -1;
      } while (uVar3 != 0xffffffff);
    }
    puVar4 = (undefined4 *)*puVar2;
    if ((puVar2[1] == 0) && (puVar4 != (undefined4 *)0x0)) {
      *puVar1 = puVar4;
      FUN_0022ba60(puVar2);
      puVar4 = (undefined4 *)*puVar1;
      puVar2 = puVar1;
    }
  } while( true );
}


// ===== FUN_0022e810 @ 0022e810 (372 bytes)

uint FUN_0022e810(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    return 0;
  }
  iVar4 = *(int *)(param_2 + 0x10) + -1;
  iVar3 = iVar4 * 4 + param_2;
  iVar12 = iVar4 * 4 + param_1;
  puVar13 = (uint *)(param_1 + 0x14);
  puVar14 = (uint *)(param_2 + 0x14);
  uVar2 = *(uint *)(iVar12 + 0x14) / (*(int *)(iVar3 + 0x14) + 1U);
  puVar15 = (uint *)(iVar3 + 0x14);
  if (uVar2 != 0) {
    uVar8 = 0;
    iVar3 = 0;
    puVar11 = puVar13;
    puVar9 = puVar14;
    do {
      iVar5 = ae_zext16(*puVar11);
      iVar6 = ae_zext16(*puVar9);
      uVar8 = uVar8 + uVar2 * iVar6;
      iVar6 = ae_zext16(uVar8);
      uVar8 = (uVar8 >> 0x10) + uVar2 * (*puVar9 >> 0x10);
      iVar10 = ae_zext16(uVar8);
      iVar3 = iVar3 + (iVar5 - iVar6);
      uVar7 = ae_zext16(iVar3);
      iVar3 = (iVar3 >> 0x10) + ((*puVar11 >> 0x10) - iVar10);
      puVar9 = puVar9 + 1;
      uVar8 = uVar8 >> 0x10;
      *puVar11 = iVar3 * 0x10000 | uVar7;
      iVar3 = iVar3 >> 0x10;
      puVar11 = puVar11 + 1;
    } while (puVar9 <= puVar15);
    if (*(int *)(iVar12 + 0x14) == 0) {
      iVar3 = 0;
      if ((puVar13 < (uint *)(iVar12 + 0x10U)) && (*(int *)(iVar12 + 0x10) == 0)) {
        puVar11 = (uint *)(iVar12 + 0xc);
        do {
          iVar3 = iVar3 + 1;
          if (puVar11 <= puVar13) break;
          piVar1 = (int *)(iVar12 + 0xc);
          puVar11 = puVar11 + -1;
          iVar12 = iVar12 + -4;
        } while (*piVar1 == 0);
      }
      iVar4 = iVar4 - iVar3;
      *(int *)(param_1 + 0x10) = iVar4;
    }
  }
  iVar12 = FUN_00236170(param_1,param_2);
  if (-1 < iVar12) {
    uVar2 = uVar2 + 1;
    iVar12 = 0;
    uVar8 = 0;
    puVar11 = puVar13;
    do {
      iVar5 = ae_zext16(*puVar14);
      iVar3 = ae_zext16(*puVar11);
      iVar6 = ae_zext16(uVar8 + iVar5);
      uVar8 = (*puVar14 >> 0x10) + (uVar8 + iVar5 >> 0x10);
      iVar5 = ae_zext16(uVar8);
      iVar12 = iVar12 + (iVar3 - iVar6);
      uVar7 = ae_zext16(iVar12);
      iVar12 = (iVar12 >> 0x10) + ((*puVar11 >> 0x10) - iVar5);
      puVar14 = puVar14 + 1;
      uVar8 = uVar8 >> 0x10;
      *puVar11 = iVar12 * 0x10000 | uVar7;
      iVar12 = iVar12 >> 0x10;
      puVar11 = puVar11 + 1;
    } while (puVar14 <= puVar15);
    iVar12 = iVar4 * 4 + param_1;
    if (*(int *)(iVar12 + 0x14) == 0) {
      iVar3 = 0;
      if ((puVar13 < (uint *)(iVar12 + 0x10U)) && (*(int *)(iVar12 + 0x10) == 0)) {
        puVar14 = (uint *)(iVar12 + 0xc);
        do {
          iVar3 = iVar3 + 1;
          if (puVar14 <= puVar13) break;
          piVar1 = (int *)(iVar12 + 0xc);
          puVar14 = puVar14 + -1;
          iVar12 = iVar12 + -4;
        } while (*piVar1 == 0);
      }
      *(int *)(param_1 + 0x10) = iVar4 - iVar3;
      return uVar2;
    }
  }
  return uVar2;
}


// ===== FUN_0022e990 @ 0022e990 (4063 bytes)

char * FUN_0022e990(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
                   uint param_6,int *param_7,undefined4 *param_8,undefined4 *param_9)

{
  char *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  bool bVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  int iStack_118;
  int iStack_114;
  uint uStack_110;
  uint uStack_10c;
  undefined4 uStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  uint uStack_ec;
  int iStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  int iStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  uint uStack_68;
  char *pcStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  char *pcStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar14 = *(int *)(param_1 + 0x40);
  uStack_48 = param_6;
  if (iVar14 != 0) {
    uVar10 = *(uint *)(param_1 + 0x44);
    *(uint *)(iVar14 + 4) = uVar10;
    *(int *)(iVar14 + 8) = 1 << 0x20 - (0x20 - (uVar10 & 0x1f));
    FUN_00236060(param_1);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if ((int)param_4 < 0) {
    *param_8 = 1;
    param_4 = param_4 & 0x7fffffff;
  }
  else {
    *param_8 = 0;
  }
  if ((~param_4 & 0x7ff00000) == 0) {
    *param_7 = (int)&DAT_0000270f;
    if ((param_3 == 0) && ((param_4 & (uint)&DAT_000fffff) == 0)) {
      pcVar3 = "Infinity";
    }
    else {
      pcVar3 = "NaN";
    }
    if (param_9 != (undefined4 *)0x0) {
      iVar14 = 3;
      if (pcVar3[3] != '\0') {
        iVar14 = 8;
      }
      *param_9 = pcVar3 + iVar14;
      return pcVar3;
    }
    return pcVar3;
  }
  piStack_e0 = param_7;
  uStack_60 = 0;
  uStack_5c = 0;
  uVar10 = param_3;
  uVar7 = param_4;
  uStack_58 = param_4;
  uStack_54 = param_3;
  uVar19 = FUN_0022b874(param_3,param_4);
  if ((int)uVar19 == 0) {
    *piStack_e0 = 1;
    if (param_9 != (undefined4 *)0x0) {
      *param_9 = &DAT_00206465;
      return "0";
    }
    return "0";
  }
  uStack_94 = param_4;
  uStack_f0 = FUN_00230b70(param_1,(int)((ulonglong)uVar19 >> 0x20),uStack_54,uStack_58,&iStack_118,
                           &iStack_114);
  iStack_70 = iStack_114;
  uVar15 = param_4 >> 0x14 & 0x7ff;
  uStack_44 = uStack_f0;
  if (uVar15 == 0) {
    iVar14 = iStack_118 + iStack_114;
    if (iVar14 < -0x411) {
      uVar15 = uVar10 << 0x20 - (0x20 - (-iVar14 - 0x412U & 0x1f));
    }
    else {
      uVar15 = uVar10 >> (iVar14 + 0x412U & 0x1f) |
               param_4 << 0x20 - (0x20 - (-iVar14 - 0x3f2U & 0x1f));
    }
    uVar19 = FUN_002364f4(uVar15);
    uStack_110 = (uint)uVar19;
    uVar15 = iVar14 - 1;
    uStack_10c = (int)((ulonglong)uVar19 >> 0x20) + 0xfe100000;
    iStack_e8 = 1;
  }
  else {
    uStack_110 = uStack_54;
    iStack_e8 = 0;
    uStack_10c = uStack_58 & (uint)&DAT_000fffff | 0x3ff00000;
    uVar15 = uVar15 - 0x3ff;
  }
  uVar19 = FUN_00236500(uVar15);
  uVar19 = FUN_00235630((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x509f79fb,0x3fd34413);
  uStack_88 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = FUN_00235510(0,0xbff80000,uStack_110,uStack_10c);
  uVar20 = FUN_00235630((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0x636f4361,0x3fd287a7);
  uVar20 = FUN_00235510((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0x8b60c8b3,0x3fc68a28);
  uVar19 = FUN_00235510((int)uVar19,uStack_88,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
  uStack_84 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uStack_3c = FUN_00233600();
  iVar14 = FUN_0022b838((int)uVar19,uStack_84,uStack_5c,uStack_60);
  if (iVar14 < 0) {
    uVar20 = FUN_00236500(uStack_3c);
    iVar14 = FUN_0022b874((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uStack_84);
    if (iVar14 != 0) {
      uStack_3c = uStack_3c - 1;
    }
  }
  if (((int)uStack_3c < 0) || (0x16 < (int)uStack_3c)) {
    iStack_8c = 1;
  }
  else {
    iVar14 = FUN_0022b838(uStack_54,uStack_58,*(undefined4 *)(&DAT_00206010 + uStack_3c * 8),
                          *(undefined4 *)(&DAT_00206014 + uStack_3c * 8));
    uVar13 = uStack_3c - 1;
    iStack_8c = 0;
    uStack_3c = 0;
    if (iVar14 < 0) {
      uStack_3c = uVar13;
    }
  }
  if ((int)(iStack_70 - uVar15) < 1) {
    iStack_90 = (uVar15 - iStack_70) + 1;
    iVar14 = 0;
  }
  else {
    iVar14 = (iStack_70 - uVar15) + -1;
    iStack_90 = 0;
  }
  if ((int)uStack_3c < 0) {
    iStack_74 = -uStack_3c;
    uStack_78 = 0;
    iStack_90 = iStack_90 - uStack_3c;
  }
  else {
    uStack_78 = uStack_3c;
    iStack_74 = 0;
    iVar14 = uStack_3c + iVar14;
  }
  if ((param_5 < 0) || (9 < param_5)) {
    uStack_9c = 1;
    param_5 = 0;
LAB_0022eb80:
    *(undefined4 *)(param_1 + 0x44) = 0;
    iStack_6c = 1;
    uStack_a0 = 0xffffffff;
    uStack_50 = 0xffffffff;
    uStack_48 = 0;
    iVar17 = 0;
  }
  else {
    bVar18 = param_5 < 6;
    if (!bVar18) {
      param_5 = param_5 + -4;
    }
    uStack_9c = (uint)bVar18;
    if ((param_5 == 0) || (param_5 == 1)) goto LAB_0022eb80;
    if (param_5 == 2) {
      iStack_6c = 0;
LAB_0022f7c0:
      uStack_a0 = (1 < (int)uStack_48) * uStack_48 + (uint)(1 >= (int)uStack_48);
      uVar15 = uStack_a0;
      uStack_50 = uStack_a0;
      uStack_48 = uStack_a0;
    }
    else {
      if (param_5 == 4) {
        iStack_6c = 1;
        goto LAB_0022f7c0;
      }
      if (param_5 == 3) {
        iStack_6c = 0;
LAB_0022f81b:
        uStack_a0 = uStack_3c + uStack_48;
        uStack_50 = uStack_a0 + 1;
        uVar15 = 1;
        if (1 < (int)uStack_50) {
          uVar15 = uStack_50;
        }
      }
      else {
        if (param_5 == 5) {
          iStack_6c = 1;
          goto LAB_0022f81b;
        }
        iStack_6c = 1;
        uStack_a0 = 0xffffffff;
        uStack_50 = 0xffffffff;
      }
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
    iVar17 = 0;
    iStack_2c = iVar14;
    if (0x17 < uVar15) {
      iVar4 = 4;
      iVar17 = 0;
      do {
        iVar17 = iVar17 + 1;
        iVar4 = iVar4 * 2;
        *(int *)(param_1 + 0x44) = iVar17;
      } while (iVar4 + 0x14U <= uVar15);
    }
  }
  uStack_a4 = uStack_3c;
  pcStack_64 = (char *)FUN_002303d0(param_1,iVar17);
  uVar19 = CONCAT44(uStack_94,param_3);
  uVar20 = CONCAT44(uStack_94,param_3);
  *(char **)(param_1 + 0x40) = pcStack_64;
  uStack_4c = uStack_50;
  uStack_80 = 0x40240000;
  uStack_7c = 0;
  if ((((int)uStack_50 < 0) || (0xe < (int)uStack_50)) || (uStack_9c == 0)) {
LAB_0022eca8:
    pcStack_38 = pcStack_64;
    uStack_50 = uStack_4c;
    if ((-1 < iStack_118) && (uStack_40 = param_3, (int)uStack_a4 < 0xf)) {
      uVar8 = *(undefined4 *)(&DAT_00206014 + uStack_a4 * 8);
      uVar16 = *(undefined4 *)(&DAT_00206010 + uStack_a4 * 8);
      if ((-1 < (int)uStack_48) || (0 < (int)uStack_4c)) {
        uVar7 = 1;
        uVar10 = uStack_94;
        do {
          FUN_002357c0(uStack_40,uVar10,uVar16,uVar8);
          uStack_68 = FUN_00233600();
          uVar19 = FUN_00236500();
          uVar19 = FUN_00235630((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar16,uVar8);
          uVar19 = FUN_00235570(uStack_40,uVar10,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
          uStack_40 = (uint)uVar19;
          *pcStack_38 = (char)uStack_68 + '0';
          pcStack_38 = pcStack_38 + 1;
          if (uStack_4c == uVar7) {
            uVar19 = FUN_00235630(uStack_40,uVar5,0,&DAT_40000000);
            uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
            iVar14 = FUN_0022b838(uVar16,uVar8,(int)uVar19,uVar5);
            if ((iVar14 < 0) ||
               ((iVar14 = FUN_0022b874(uVar16,uVar8,(int)uVar19,uVar5), iVar14 == 0 &&
                ((uStack_68 & 1) != 0)))) goto LAB_0022f415;
            break;
          }
          uVar19 = FUN_00235630(uStack_40,uVar5,uStack_7c,uStack_80);
          uVar10 = (uint)((ulonglong)uVar19 >> 0x20);
          uStack_40 = (uint)uVar19;
          iVar14 = FUN_0022b874(uStack_40,uVar10,uStack_5c,uStack_60);
          uVar7 = uVar7 + 1;
        } while (iVar14 != 0);
        goto LAB_0022f134;
      }
      if (-1 < (int)uStack_4c) {
        uVar19 = FUN_00235630(0,&DAT_40140000,uVar16,uVar8);
        iVar14 = FUN_0022b848(uStack_54,uStack_58,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        if (0 < iVar14) goto LAB_0022f5fa;
      }
LAB_0022f771:
      iVar4 = 0;
      iVar14 = 0;
LAB_0022f777:
      pcStack_38 = pcStack_64;
      uStack_3c = -uStack_48 - 1;
      goto LAB_0022f789;
    }
    iStack_ac = iStack_74;
    if (iStack_6c == 0) {
      iVar4 = 0;
      iVar17 = iStack_90;
    }
    else {
      if (param_5 < 2) {
        if (iStack_e8 == 0) {
          uVar15 = 0x36 - iStack_114;
        }
        else {
          uVar15 = iStack_118 + 0x433;
        }
        iStack_d0 = iStack_90;
      }
      else {
        if (iStack_74 < (int)(uStack_4c - 1)) {
          uStack_78 = uStack_78 + (uStack_4c - iStack_74) + -1;
          iStack_ac = 0;
          iStack_74 = uStack_4c - 1;
        }
        else {
          iStack_ac = (iStack_74 - uStack_4c) + 1;
        }
        iStack_d0 = iStack_90;
        uVar15 = uStack_4c;
        if ((int)uStack_4c < 0) {
          iStack_d0 = iStack_90 - uStack_4c;
          uVar15 = 0;
        }
      }
      iVar14 = iVar14 + uVar15;
      iStack_90 = iStack_90 + uVar15;
      iVar4 = FUN_002305a0(param_1,1);
      iVar17 = iStack_d0;
    }
    if ((0 < iVar17) && (0 < iVar14)) {
      iVar11 = (uint)(iVar14 < iVar17) * iVar14 + (uint)(iVar14 >= iVar17) * iVar17;
      iVar17 = iVar17 - iVar11;
      iStack_90 = iStack_90 - iVar11;
      iVar14 = iVar14 - iVar11;
    }
    if (0 < iStack_74) {
      if (iStack_6c == 0) {
        uStack_44 = FUN_00230750(param_1,uStack_f0,iStack_74);
      }
      else {
        if (0 < iStack_ac) {
          iVar4 = FUN_00230750(param_1,iVar4,iStack_ac);
          uStack_c8 = FUN_002305c0(param_1,iVar4,uStack_f0);
          FUN_00236060(param_1,uStack_f0);
          uStack_44 = uStack_c8;
        }
        if (iStack_74 != iStack_ac) {
          uStack_44 = FUN_00230750(param_1,uStack_44);
        }
      }
    }
    iStack_bc = FUN_002305a0(param_1,1);
    if (0 < (int)uStack_78) {
      iStack_bc = FUN_00230750(param_1,iStack_bc,uStack_78);
    }
    if ((((param_5 < 2) && (uVar10 == 0)) && ((uVar7 & (uint)&DAT_000fffff) == 0)) &&
       ((uVar7 & 0x7ff00000) != 0)) {
      iStack_b8 = 1;
      iStack_90 = iStack_90 + 1;
      iVar11 = iVar14 + 1;
    }
    else {
      iStack_b8 = 0;
      iVar11 = iVar14;
    }
    iStack_2c = iVar14;
    if (uStack_78 == 0) {
      iVar14 = 1;
    }
    else {
      iVar14 = FUN_00236080(*(undefined4 *)(*(int *)(iStack_bc + 0x10) * 4 + iStack_bc + 0x10));
      iVar14 = 0x20 - iVar14;
    }
    uVar7 = iVar14 + iVar11 & 0x1f;
    iVar14 = 0;
    if (uVar7 != 0) {
      iVar14 = 0x20 - uVar7;
    }
    if (iVar14 < 5) {
      iStack_d0 = iVar17;
      if (iVar14 < 4) {
        iVar14 = iVar14 + 0x1c;
        iStack_90 = iStack_90 + iVar14;
        iStack_d0 = iVar17 + iVar14;
        iVar11 = iVar11 + iVar14;
      }
    }
    else {
      iVar14 = iVar14 + -4;
      iStack_90 = iStack_90 + iVar14;
      iVar11 = iVar11 + iVar14;
      iStack_d0 = iVar17 + iVar14;
    }
    if (0 < iStack_90) {
      uStack_44 = FUN_00230800(param_1,uStack_44,iStack_90);
    }
    if (0 < iVar11) {
      iStack_bc = FUN_00230800(param_1,iStack_bc,iVar11);
    }
    iVar14 = iStack_bc;
    if ((iStack_8c != 0) && (iVar17 = FUN_00236170(uStack_44,iStack_bc), iVar17 < 0)) {
      uStack_3c = uStack_a4 - 1;
      uStack_44 = FUN_00230440(param_1,uStack_44,10,0);
      if (iStack_6c != 0) {
        iVar4 = FUN_00230440(param_1,iVar4,10,0);
      }
      uStack_50 = uStack_a0;
    }
    if (((int)uStack_50 < 1) && (2 < param_5)) {
      if (-1 < (int)uStack_50) {
        iVar14 = FUN_00230440(param_1,iVar14,5,0);
        iVar17 = FUN_00236170(uStack_44,iVar14);
        if (0 < iVar17) goto LAB_0022f5aa;
      }
      goto LAB_0022f777;
    }
    if (iStack_6c != 0) {
      if (0 < iStack_d0) {
        iVar4 = FUN_00230800(param_1,iVar4,iStack_d0);
      }
      iStack_b0 = iVar4;
      if (iStack_b8 != 0) {
        iVar17 = FUN_002303d0(param_1,*(undefined4 *)(iVar4 + 4));
        memcpy(iVar17 + 0xc,iVar4 + 0xc,*(int *)(iVar4 + 0x10) * 4 + 8);
        iVar4 = FUN_00230800(param_1,iVar17,1);
      }
      uStack_cc = uVar10 & 1;
      uVar10 = 1;
      do {
        iVar17 = FUN_0022e810(uStack_44,iVar14);
        uStack_ec = iVar17 + 0x30;
        uStack_c4 = uStack_ec;
        iStack_f4 = FUN_00236170(uStack_44,iStack_b0);
        iVar17 = FUN_002308e0(param_1,iVar14,iVar4);
        if (*(int *)(iVar17 + 0xc) == 0) {
          iStack_f8 = iVar17;
          iStack_fc = FUN_00236170(uStack_44,iVar17);
          iVar17 = iStack_f8;
        }
        else {
          iStack_fc = 1;
        }
        FUN_00236060(param_1,iVar17);
        iVar17 = iStack_b0;
        cVar12 = (char)uStack_ec;
        if (((iStack_fc == 0) && (param_5 == 0)) && (uStack_cc == 0)) {
          if (uStack_ec != 0x39) {
            cVar9 = cVar12 + '\x01';
            if (iStack_f4 < 1) {
              cVar9 = cVar12;
            }
            *pcStack_38 = cVar9;
            pcStack_38 = pcStack_38 + 1;
            goto LAB_0022f112;
          }
LAB_0022f7fd:
          *pcStack_38 = '9';
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f739;
        }
        if ((iStack_f4 < 0) || (((iStack_f4 == 0 && (param_5 == 0)) && (uStack_cc == 0)))) {
          if (0 < iStack_fc) {
            uStack_44 = FUN_00230800(param_1,uStack_44,1);
            iVar11 = FUN_00236170(uStack_44,iVar14);
            if (((0 < iVar11) || ((iVar11 == 0 && ((uStack_ec & 1) != 0)))) &&
               (uStack_c4 = uStack_ec + 1, uStack_c4 == 0x3a)) goto LAB_0022f7fd;
          }
          *pcStack_38 = (char)uStack_c4;
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f112;
        }
        if (0 < iStack_fc) {
          if (uStack_ec == 0x39) goto LAB_0022f7fd;
          *pcStack_38 = cVar12 + '\x01';
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f112;
        }
        *pcStack_38 = cVar12;
        pcStack_38 = pcStack_38 + 1;
        if (uStack_50 == uVar10) goto LAB_0022f715;
        uStack_44 = FUN_00230440(param_1,uStack_44,10,0);
        if (iVar4 == iStack_b0) {
          iVar4 = FUN_00230440(param_1,iVar4,10,0);
          iStack_b0 = iVar4;
        }
        else {
          iStack_b0 = FUN_00230440(param_1,iStack_b0,10,0);
          iVar4 = FUN_00230440(param_1,iVar4,10,0);
        }
        uVar10 = uVar10 + 1;
      } while( true );
    }
    iVar17 = 1;
    while( true ) {
      iVar11 = FUN_0022e810(uStack_44,iVar14);
      uStack_c4 = iVar11 + 0x30;
      *pcStack_38 = (char)uStack_c4;
      pcStack_38 = pcStack_38 + 1;
      if ((int)uStack_50 <= iVar17) break;
      uStack_44 = FUN_00230440(param_1,uStack_44,10,0);
      iVar17 = iVar17 + 1;
    }
    iStack_b0 = 0;
LAB_0022f715:
    uStack_44 = FUN_00230800(param_1,uStack_44,1);
    iVar17 = iStack_b0;
    iVar11 = FUN_00236170(uStack_44,iVar14);
    if ((iVar11 < 1) && ((iVar11 != 0 || ((uStack_c4 & 1) == 0)))) {
      pcVar3 = pcStack_38 + -0x80;
      cVar12 = pcStack_38[-1];
      while (cVar12 == '0') {
        pcVar1 = pcVar3 + 0x7e;
        pcStack_38 = pcStack_38 + -1;
        pcVar3 = pcVar3 + -1;
        cVar12 = *pcVar1;
      }
    }
    else {
LAB_0022f739:
      cVar12 = pcStack_38[-1];
      pcStack_38 = pcStack_38 + -1;
      while (cVar12 == '9') {
        if (pcStack_64 == pcStack_38) {
          *pcStack_38 = '1';
          pcStack_38 = pcStack_38 + 1;
          uStack_3c = uStack_3c + 1;
          goto LAB_0022f112;
        }
        cVar12 = pcStack_38[-1];
        pcStack_38 = pcStack_38 + -1;
      }
      *pcStack_38 = cVar12 + '\x01';
      pcStack_38 = pcStack_38 + 1;
    }
  }
  else {
    uStack_40 = param_3;
    pcStack_38 = pcStack_64;
    iStack_28 = param_5;
    if ((int)uStack_a4 < 1) {
      uVar10 = -uStack_a4;
      iStack_2c = iVar14;
      if (uVar10 != 0) {
        iVar17 = (uVar10 & 0xf) * 8;
        uVar19 = FUN_00235630(*(undefined4 *)(&DAT_00206010 + iVar17),
                              *(undefined4 *)(&DAT_00206014 + iVar17),uStack_54,uStack_58);
        uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
        uVar10 = (int)uVar10 >> 4;
        if (uVar10 != 0) {
          puVar6 = &DAT_00206110;
          iStack_34 = 2;
          do {
            if ((uVar10 & 1) != 0) {
              uVar19 = FUN_00235630(*puVar6,puVar6[1],(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              iStack_34 = iStack_34 + 1;
            }
            uVar10 = (int)uVar10 >> 1;
            puVar6 = puVar6 + 2;
            iVar14 = iStack_2c;
          } while (uVar10 != 0);
          goto LAB_0022f184;
        }
      }
      iStack_34 = 2;
      iVar14 = iStack_2c;
    }
    else {
      uVar10 = (int)uStack_a4 >> 4;
      uVar2 = *(undefined8 *)(&DAT_00206010 + (uStack_a4 & 0xf) * 8);
      uVar19 = *(undefined8 *)(&DAT_00206010 + (uStack_a4 & 0xf) * 8);
      if ((uStack_a4 >> 8 & 1) == 0) {
        iStack_34 = 2;
        iStack_2c = iVar14;
      }
      else {
        uVar10 = uStack_a4 >> 4 & 0xf;
        iStack_2c = iVar14;
        uVar20 = FUN_002357c0(uStack_54,uStack_58,0x7f73bf3c,0x75154fdd);
        iStack_34 = 3;
      }
      if (uVar10 != 0) {
        puVar6 = &DAT_00206110;
        do {
          uStack_94 = (uint)((ulonglong)uVar20 >> 0x20);
          uStack_40 = (uint)uVar20;
          if ((uVar10 & 1) != 0) {
            uVar19 = FUN_00235630(*puVar6,puVar6[1],(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
            uVar20 = CONCAT44(uStack_94,uStack_40);
            iStack_34 = iStack_34 + 1;
          }
          uVar10 = (int)uVar10 >> 1;
          puVar6 = puVar6 + 2;
          uVar2 = uVar19;
        } while (uVar10 != 0);
      }
      iVar14 = iStack_2c;
      uStack_94 = (uint)((ulonglong)uVar20 >> 0x20);
      uStack_40 = (uint)uVar20;
      uVar19 = FUN_002357c0(uStack_40,uStack_94,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
      param_5 = iStack_28;
    }
LAB_0022f184:
    uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
    uVar8 = (undefined4)uVar19;
    uStack_b4 = 0x3ff00000;
    if (iStack_8c != 0) {
      iVar17 = FUN_0022b838(uVar8,uStack_94,0,0x3ff00000);
      uVar19 = CONCAT44(uStack_94,uVar8);
      if ((-1 < iVar17) || (uVar19 = CONCAT44(uStack_94,uVar8), (int)uStack_4c < 1))
      goto LAB_0022f201;
      iVar17 = 1;
      uVar19 = CONCAT44(uStack_94,uVar8);
      if (0 < (int)uStack_a0) {
        iStack_30 = 0;
        iVar17 = 0;
        uVar19 = CONCAT44(uStack_94,uVar8);
        if (0 < (int)uStack_a0) {
          uStack_50 = uStack_a0;
          uVar19 = FUN_00235630(uVar8,uStack_94,uStack_7c,uStack_80);
          iStack_34 = iStack_34 + 1;
          uStack_3c = uStack_a4 - 1;
          iVar17 = iStack_30;
        }
      }
      if (iVar17 == 0) goto LAB_0022f201;
LAB_0022ec8d:
      uStack_3c = uStack_a4;
      uStack_94 = uStack_58;
      param_3 = uStack_54;
      uVar10 = uStack_54;
      uVar7 = uStack_58;
      goto LAB_0022eca8;
    }
LAB_0022f201:
    uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
    uVar16 = (undefined4)uVar19;
    uVar19 = FUN_00236500(iStack_34);
    uVar19 = FUN_00235630((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar16,uStack_94);
    uStack_e4 = 0;
    uVar19 = FUN_00235510((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,0x401c0000);
    uVar8 = (undefined4)uVar19;
    uStack_104 = (int)((ulonglong)uVar19 >> 0x20) + 0xfcc00000;
    uStack_108 = uVar8;
    uStack_98 = uStack_104;
    if (uStack_50 != 0) {
      if (iStack_6c != 0) {
        uVar19 = FUN_002357c0(0,0x3fe00000);
        uVar19 = FUN_00235570((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar8,uStack_98);
        uVar20 = CONCAT44(uStack_94,uVar16);
        iVar17 = 0;
        while( true ) {
          uStack_94 = (uint)((ulonglong)uVar20 >> 0x20);
          uStack_98 = (uint)((ulonglong)uVar19 >> 0x20);
          uStack_a8 = (undefined4)uVar19;
          iStack_c0 = FUN_00233600((int)uVar20,uStack_94);
          uVar19 = FUN_00236500();
          uVar19 = FUN_00235570((int)uVar20,uStack_94,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
          uVar8 = (undefined4)uVar19;
          *pcStack_38 = (char)(iStack_c0 + 0x30);
          pcStack_38 = pcStack_38 + 1;
          iVar4 = FUN_0022b838(uVar8,uStack_94,uStack_a8,uStack_98,pcStack_38,iStack_c0 + 0x30,
                               uVar19);
          if (iVar4 < 0) break;
          uVar19 = FUN_00235570(uStack_e4,uStack_b4,uVar8,uStack_94);
          iVar4 = FUN_0022b858(uStack_a8,uStack_98,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          if (0 < iVar4) goto LAB_0022f415;
          iVar17 = iVar17 + 1;
          if ((int)uStack_50 <= iVar17) goto LAB_0022ec8d;
          uVar19 = FUN_00235630(uStack_a8,uStack_98,uStack_7c,uStack_80);
          uStack_98 = (uint)((ulonglong)uVar19 >> 0x20);
          uStack_a8 = (undefined4)uVar19;
          uVar20 = FUN_00235630(uVar8,uStack_94,uStack_7c,uStack_80);
          uVar19 = CONCAT44(uStack_98,uStack_a8);
        }
        goto LAB_0022f134;
      }
      uStack_d8 = 0x3fe00000;
      uStack_dc = 0;
      uVar20 = FUN_00235630(*(undefined4 *)(&UNK_00206008 + uStack_50 * 8),
                            *(undefined4 *)(&UNK_0020600c + uStack_50 * 8),uVar8,uStack_104);
      uVar19 = CONCAT44(uStack_94,uVar16);
      uVar10 = 1;
      while( true ) {
        uStack_98 = (uint)((ulonglong)uVar20 >> 0x20);
        uStack_a8 = (undefined4)uVar20;
        uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
        uStack_d4 = FUN_00233600((int)uVar19,uStack_94);
        uVar20 = FUN_00236500();
        uVar19 = FUN_00235570((int)uVar19,uStack_94,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
        uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
        uStack_40 = (uint)uVar19;
        *pcStack_38 = (char)uStack_d4 + '0';
        pcStack_38 = pcStack_38 + 1;
        if (uStack_50 == uVar10) break;
        uVar19 = FUN_00235630(uStack_40,uStack_94,uStack_7c,uStack_80);
        uVar20 = CONCAT44(uStack_98,uStack_a8);
        uVar10 = uVar10 + 1;
      }
      uVar19 = FUN_00235510(uStack_a8,uStack_98,uStack_dc,uStack_d8);
      iVar17 = FUN_0022b858(uStack_40,uStack_94,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (0 < iVar17) {
LAB_0022f415:
        cVar12 = pcStack_38[-1];
        pcStack_38 = pcStack_38 + -1;
        while (cVar12 == '9') {
          if (pcStack_64 == pcStack_38) {
            *pcStack_38 = '0';
            uStack_3c = uStack_3c + 1;
            cVar12 = '0';
            break;
          }
          cVar12 = pcStack_38[-1];
          pcStack_38 = pcStack_38 + -1;
        }
        *pcStack_38 = cVar12 + '\x01';
        pcStack_38 = pcStack_38 + 1;
        goto LAB_0022f134;
      }
      uVar19 = FUN_00235570(uStack_dc,uStack_d8,uStack_a8,uStack_98);
      iVar17 = FUN_0022b838(uStack_40,uStack_94,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (iVar17 < 0) {
        pcVar3 = pcStack_38 + -0x80;
        cVar12 = pcStack_38[-1];
        while (cVar12 == '0') {
          pcVar1 = pcVar3 + 0x7e;
          pcStack_38 = pcStack_38 + -1;
          pcVar3 = pcVar3 + -1;
          cVar12 = *pcVar1;
        }
        goto LAB_0022f134;
      }
      goto LAB_0022ec8d;
    }
    uVar19 = FUN_00235510(uVar16,uStack_94,0,0xc0140000);
    uStack_100 = (undefined4)((ulonglong)uVar19 >> 0x20);
    iVar17 = FUN_0022b838(uVar8,uStack_98,(int)uVar19,uStack_100);
    if (-1 < iVar17) {
      iVar17 = FUN_0022b838((int)uVar19,uStack_100,uVar8,uStack_98 ^ 0x80000000);
      if (-1 < iVar17) goto LAB_0022ec8d;
      goto LAB_0022f771;
    }
LAB_0022f5fa:
    iVar14 = 0;
    iVar4 = 0;
LAB_0022f5aa:
    *pcStack_64 = '1';
    uStack_3c = uStack_3c + 1;
    pcStack_38 = pcStack_64 + 1;
LAB_0022f789:
    iVar17 = 0;
  }
LAB_0022f112:
  FUN_00236060(param_1,iVar14);
  if (iVar4 != 0) {
    if ((iVar17 != 0) && (iVar4 != iVar17)) {
      FUN_00236060(param_1,iVar17);
    }
    FUN_00236060(param_1,iVar4);
  }
LAB_0022f134:
  FUN_00236060(param_1,uStack_44);
  *pcStack_38 = '\0';
  *piStack_e0 = uStack_3c + 1;
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = pcStack_38;
    return pcStack_64;
  }
  return pcStack_64;
}


// ===== FUN_0022fa00 @ 0022fa00 (373 bytes)

undefined4 FUN_0022fa00(int *param_1,int *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar1 = *(ushort *)(param_2 + 3);
  iVar5 = param_2[4];
  iVar6 = *param_2;
  if (((uint)(int)(short)uVar1 >> 3 & 1) == 0) {
    *(ushort *)(param_2 + 3) = uVar1 | 0x800;
    if (((0 < param_2[1]) || (0 < param_2[0xf])) &&
       (pcVar4 = (code *)param_2[10], pcVar4 != (code *)0x0)) {
      uVar2 = (uint)(short)param_2[3];
      iVar5 = *param_1;
      *param_1 = 0;
      if ((uVar2 >> 0xc & 1) == 0) {
        iVar6 = (*pcVar4)(param_1,param_2[7],0,1);
        if ((iVar6 == -1) && (iVar3 = *param_1, iVar3 != 0)) {
          if ((iVar3 != 0x1d) && (iVar3 != 0x16)) {
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
            return 0xffffffff;
          }
          *param_1 = iVar5;
          return 0;
        }
        uVar2 = (uint)(short)param_2[3];
      }
      else {
        iVar6 = param_2[0x14];
      }
      if ((uVar2 & 4) != 0) {
        iVar6 = iVar6 - param_2[1];
        if (param_2[0xc] != 0) {
          iVar6 = iVar6 - param_2[0xf];
        }
      }
      iVar6 = (*(code *)param_2[10])(param_1,param_2[7],iVar6,0);
      if (((iVar6 == -1) && (iVar3 = *param_1, iVar3 != 0)) && ((iVar3 != 0x1d && (iVar3 != 0x16))))
      {
LAB_0022fb05:
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
        return 0xffffffff;
      }
      uVar1 = *(ushort *)(param_2 + 3);
      param_2[1] = 0;
      *param_2 = param_2[4];
      *(ushort *)(param_2 + 3) = uVar1 & 0xf7ff;
      piVar7 = (int *)param_2[0xc];
      if ((((uint)(int)(short)uVar1 >> 0xc & 1) != 0) && ((iVar6 != -1 || (*param_1 == 0)))) {
        param_2[0x14] = iVar6;
      }
      *param_1 = iVar5;
      if (piVar7 != (int *)0x0) {
        if (piVar7 == param_2 + 0x10) {
          param_2[0xc] = 0;
          return 0;
        }
        FUN_0022fe50(param_1);
        param_2[0xc] = 0;
        return 0;
      }
    }
  }
  else if (iVar5 != 0) {
    *param_2 = iVar5;
    iVar6 = iVar6 - iVar5;
    iVar3 = 0;
    if (((int)(short)uVar1 & 3U) == 0) {
      iVar3 = param_2[5];
    }
    param_2[2] = iVar3;
    while (0 < iVar6) {
      iVar3 = (*(code *)param_2[9])(param_1,param_2[7],iVar5,iVar6);
      iVar6 = iVar6 - iVar3;
      if (iVar3 < 1) goto LAB_0022fb05;
      iVar5 = iVar5 + iVar3;
    }
  }
  return 0;
}


// ===== FUN_0022fb80 @ 0022fb80 (39 bytes)

undefined4 FUN_0022fb80(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    FUN_0022fd00(param_1);
  }
  if (*(short *)(param_2 + 0xc) == 0) {
    return 0;
  }
  uVar1 = FUN_0022fa00(param_1,param_2);
  return uVar1;
}


// ===== FUN_0022fbb0 @ 0022fbb0 (40 bytes)

undefined4 FUN_0022fbb0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_00236000(&DAT_00237ad8,FUN_0022fb80);
    return uVar1;
  }
  uVar1 = FUN_0022fb80(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== FUN_0022fbe0 @ 0022fbe0 (51 bytes)

undefined4 * FUN_0022fbe0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0022ba80(param_1,param_2 * 0x68 + 0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1[1] = param_2;
  *puVar1 = 0;
  puVar1[2] = puVar1 + 3;
  memset(puVar1 + 3,0,param_2 * 0x68);
  return puVar1;
}


// ===== FUN_0022fc20 @ 0022fc20 (170 bytes)

undefined4 * FUN_0022fc20(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00235f40();
  if (DAT_00237b10 == 0) {
    FUN_0022fd00();
  }
  puVar3 = &DAT_00237db8;
  do {
    puVar1 = puVar3;
    iVar2 = puVar1[1];
    puVar3 = (undefined4 *)puVar1[2];
    if (-1 < iVar2 + -1) {
      if (iVar2 == 1) {
        isync();
      }
      if ((0 < iVar2) && (*(short *)(puVar3 + 3) == 0)) {
        *(undefined2 *)((int)puVar3 + 0xe) = 0xffff;
        *(undefined2 *)(puVar3 + 3) = 1;
        puVar3[0x19] = 0;
        FUN_00235f50();
        *puVar3 = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        memset(puVar3 + 0x17,0,8);
        puVar3[0xc] = 0;
        puVar3[0xd] = 0;
        puVar3[0x11] = 0;
        puVar3[0x12] = 0;
        return puVar3;
      }
    }
    puVar3 = (undefined4 *)*puVar1;
    if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)FUN_0022fbe0(param_1,4);
      *puVar1 = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        FUN_00235f50();
        *param_1 = 0xc;
        return (undefined4 *)0x0;
      }
    }
  } while( true );
}


// ===== FUN_0022fce0 @ 0022fce0 (14 bytes)

void FUN_0022fce0(undefined4 param_1)

{
  FUN_00235fa0(param_1,&LAB_002325d0);
  return;
}


// ===== FUN_0022fcf0 @ 0022fcf0 (13 bytes)

void FUN_0022fcf0(void)

{
  FUN_0022fce0(&DAT_00237ad8);
  return;
}


// ===== FUN_0022fd00 @ 0022fd00 (263 bytes)

void FUN_0022fd00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_00235f60();
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_00235f70();
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(code **)(param_1 + 0x3c) = FUN_0022fce0;
  *(undefined4 *)(param_1 + 0x2e4) = 3;
  *(int *)(param_1 + 0x2e8) = param_1 + 0x2ec;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[0x19] = 0;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  *(undefined2 *)(puVar1 + 3) = 4;
  puVar1[6] = 0;
  memset(puVar1 + 0x17,0,8);
  puVar1[7] = puVar1;
  puVar1[8] = FUN_00230d80;
  puVar1[9] = FUN_00230dc0;
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar1[10] = FUN_00230e00;
  puVar1[0xb] = FUN_00230e40;
  *(undefined2 *)((int)puVar2 + 0xe) = 1;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[0x19] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  *(undefined2 *)(puVar2 + 3) = 9;
  puVar2[6] = 0;
  memset(puVar2 + 0x17,0,8);
  puVar2[7] = puVar2;
  puVar2[9] = FUN_00230dc0;
  puVar2[8] = FUN_00230d80;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  puVar2[10] = FUN_00230e00;
  puVar2[0xb] = FUN_00230e40;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[0x19] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  *(undefined2 *)(puVar1 + 3) = 10;
  *(undefined2 *)((int)puVar1 + 0xe) = 2;
  memset(puVar1 + 0x17,0,8);
  puVar1[0xb] = FUN_00230e40;
  puVar1[10] = FUN_00230e00;
  puVar1[9] = FUN_00230dc0;
  puVar1[7] = puVar1;
  puVar1[8] = FUN_00230d80;
  *(undefined4 *)(param_1 + 0x38) = 1;
  FUN_00235f70();
  return;
}


// ===== FUN_0022fe10 @ 0022fe10 (19 bytes)

void FUN_0022fe10(void)

{
  FUN_00235f40();
  FUN_00235fa0(PTR_DAT_00237f00,&LAB_00235f80);
  return;
}


// ===== FUN_0022fe30 @ 0022fe30 (19 bytes)

void FUN_0022fe30(void)

{
  FUN_00235fa0(PTR_DAT_00237f00,&LAB_00235f90);
  FUN_00235f50();
  return;
}


// ===== FUN_0022fe50 @ 0022fe50 (564 bytes)

void FUN_0022fe50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined **ppuVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  
  if (param_2 == 0) {
    return;
  }
  FUN_00228dc0(param_1);
  uVar5 = *(uint *)(param_2 + -4);
  uVar9 = uVar5 & 0xfffffffe;
  piVar7 = (int *)(uVar9 + param_2);
  piVar8 = (int *)(param_2 + -8);
  uVar10 = piVar7[-1] & 0xfffffffc;
  if ((int *)PTR_DAT_00237f28 == piVar7 + -2) {
    puVar11 = (undefined *)(uVar9 + uVar10);
    if ((uVar5 & 1) == 0) {
      iVar1 = *piVar8;
      piVar8 = (int *)((int)piVar8 - iVar1);
      iVar2 = piVar8[2];
      iVar3 = piVar8[3];
      *(int *)(iVar2 + 0xc) = iVar3;
      *(int *)(iVar3 + 8) = iVar2;
      puVar11 = puVar11 + iVar1;
    }
    piVar8[1] = (uint)puVar11 | 1;
    PTR_DAT_00237f28 = (undefined *)piVar8;
    if (PTR_DAT_00237f14 <= puVar11) {
      FUN_00230090(param_1,DAT_002cd708);
    }
    FUN_00228df0(param_1);
    return;
  }
  piVar7[-1] = uVar10;
  if ((uVar5 & 1) == 0) {
    iVar1 = *piVar8;
    piVar8 = (int *)((int)piVar8 - iVar1);
    ppuVar6 = (undefined **)piVar8[2];
    uVar9 = uVar9 + iVar1;
    puVar11 = (undefined *)piVar8[3];
    if (ppuVar6 == &PTR_DAT_00237f28) {
      if ((*(uint *)((int)piVar7 + (uVar10 - 4)) & 1) == 0) {
        iVar2 = *piVar7;
        iVar1 = piVar7[1];
        *(int *)(iVar2 + 0xc) = iVar1;
        uVar9 = uVar9 + uVar10;
        *(int *)(iVar1 + 8) = iVar2;
        piVar8[1] = uVar9 | 1;
        *(uint *)(uVar9 + (int)piVar8) = uVar9;
      }
      else {
        piVar8[1] = uVar9 | 1;
        *(uint *)((int)piVar8 + uVar9) = uVar9;
      }
      goto LAB_0022feea;
    }
    uVar5 = *(uint *)((int)piVar7 + (uVar10 - 4));
    ppuVar6[3] = puVar11;
    *(undefined ***)(puVar11 + 8) = ppuVar6;
    if ((uVar5 & 1) == 0) {
      ppuVar6 = (undefined **)*piVar7;
      uVar9 = uVar9 + uVar10;
      if (ppuVar6 == &PTR_DAT_00237f28) goto LAB_00230050;
      puVar11 = (undefined *)piVar7[1];
      ppuVar6[3] = puVar11;
      *(undefined ***)(puVar11 + 8) = ppuVar6;
      piVar8[1] = uVar9 | 1;
      *(uint *)(uVar9 + (int)piVar8) = uVar9;
    }
    else {
      piVar8[1] = uVar9 | 1;
      *(uint *)((int)piVar8 + uVar9) = uVar9;
    }
  }
  else if ((*(uint *)((int)piVar7 + (uVar10 - 4)) & 1) == 0) {
    ppuVar6 = (undefined **)*piVar7;
    uVar9 = uVar9 + uVar10;
    if (ppuVar6 == &PTR_DAT_00237f28) {
LAB_00230050:
      PTR_PTR_00237f30 = (undefined *)piVar8;
      PTR_PTR_00237f34 = (undefined *)piVar8;
      piVar8[3] = (int)&PTR_DAT_00237f28;
      piVar8[2] = (int)&PTR_DAT_00237f28;
      piVar8[1] = uVar9 | 1;
      *(uint *)((int)piVar8 + uVar9) = uVar9;
      goto LAB_0022feea;
    }
    puVar11 = (undefined *)piVar7[1];
    ppuVar6[3] = puVar11;
    *(undefined ***)(puVar11 + 8) = ppuVar6;
    *(uint *)(param_2 + -4) = uVar9 | 1;
    *(uint *)(uVar9 + (int)piVar8) = uVar9;
  }
  else {
    *(uint *)(param_2 + -4) = uVar9 | 1;
    *(uint *)(uVar9 + (int)piVar8) = uVar9;
  }
  uVar5 = uVar9 >> 9;
  if (uVar9 < 0x200) {
    uVar9 = uVar9 >> 3;
    DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar9 >> 2 & 0x1fU));
    piVar8[3] = (int)(&DAT_00237f20 + uVar9 * 8);
    puVar11 = (&PTR_DAT_00237f28)[uVar9 * 2];
    piVar8[2] = (int)puVar11;
    (&PTR_DAT_00237f28)[uVar9 * 2] = (undefined *)piVar8;
    *(int **)(puVar11 + 0xc) = piVar8;
  }
  else {
    if (uVar5 == 0) {
      uVar5 = uVar9 >> 3;
    }
    else if (uVar5 < 5) {
      uVar5 = (uVar9 >> 6) + 0x38;
    }
    else if (uVar5 < 0x15) {
      uVar5 = uVar5 + 0x5b;
    }
    else if (uVar5 < 0x55) {
      uVar5 = (uVar9 >> 0xc) + 0x6e;
    }
    else if (uVar5 < 0x155) {
      uVar5 = (uVar9 >> 0xf) + 0x77;
    }
    else if (uVar5 < 0x555) {
      uVar5 = (uVar9 >> 0x12) + 0x7c;
    }
    else {
      uVar5 = 0x7e;
    }
    puVar4 = &DAT_00237f20 + uVar5 * 8;
    puVar11 = (&PTR_DAT_00237f28)[uVar5 * 2];
    if (puVar4 == puVar11) {
      DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar5 >> 2 & 0x1fU));
    }
    else {
      uVar5 = *(uint *)(puVar11 + 4);
      while ((uVar9 < (uVar5 & 0xfffffffc) &&
             (puVar11 = *(undefined **)(puVar11 + 8), puVar4 != puVar11))) {
        uVar5 = *(uint *)(puVar11 + 4);
      }
      puVar4 = *(undefined **)(puVar11 + 0xc);
    }
    piVar8[2] = (int)puVar11;
    piVar8[3] = (int)puVar4;
    *(int **)(puVar4 + 8) = piVar8;
    *(int **)(puVar11 + 0xc) = piVar8;
  }
LAB_0022feea:
  FUN_00228df0(param_1);
  return;
}


// ===== FUN_00230090 @ 00230090 (197 bytes)

undefined4 FUN_00230090(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_00228dc0(param_1);
  uVar4 = *(uint *)(PTR_DAT_00237f28 + 4) & 0xfffffffc;
  uVar3 = (uVar4 - param_2) + 0xfef & 0xfffff000;
  if ((int)(uVar3 - 0x1000) < 0x1000) {
    FUN_00228df0(param_1);
    return 0;
  }
  puVar1 = (undefined *)FUN_00228e34(param_1,0);
  if (puVar1 != PTR_DAT_00237f28 + uVar4) {
    FUN_00228df0(param_1);
    return 0;
  }
  iVar2 = FUN_00228e34(param_1,(int)&DAT_00001000 - uVar3);
  if (iVar2 == -1) {
    iVar2 = FUN_00228e34(param_1,0);
    if (0xf < iVar2 - (int)PTR_DAT_00237f28) {
      DAT_002cd70c = iVar2 - DAT_00237f10;
      *(uint *)(PTR_DAT_00237f28 + 4) = iVar2 - (int)PTR_DAT_00237f28 | 1;
    }
    FUN_00228df0(param_1);
    return 0;
  }
  *(uint *)(PTR_DAT_00237f28 + 4) = uVar4 - (uVar3 - 0x1000) | 1;
  DAT_002cd70c = (DAT_002cd70c - uVar3) + 0x1000;
  FUN_00228df0(param_1);
  return 1;
}


// ===== FUN_00230160 @ 00230160 (52 bytes)

undefined * FUN_00230160(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (((param_3 != 0) && (iVar1 = FUN_0022c190(param_3,"POSIX"), iVar1 != 0)) &&
     (iVar1 = FUN_0022c190(param_3,&DAT_00206410), iVar1 != 0)) {
    iVar1 = FUN_0022c190(param_3,"");
    if (iVar1 != 0) {
      return (undefined *)0x0;
    }
  }
  return &DAT_00206410;
}


// ===== FUN_002301a0 @ 002301a0 (8 bytes)

char * FUN_002301a0(void)

{
  return s_ASCII_00238370;
}


// ===== FUN_002301b0 @ 002301b0 (10 bytes)

undefined4 FUN_002301b0(void)

{
  return DAT_00238330;
}


// ===== FUN_002301c0 @ 002301c0 (8 bytes)

char * FUN_002301c0(void)

{
  return s_ASCII_00238390;
}


// ===== FUN_002301d0 @ 002301d0 (10 bytes)

undefined4 FUN_002301d0(void)

{
  return DAT_002cd73c;
}


// ===== FUN_002301e0 @ 002301e0 (8 bytes)

undefined ** FUN_002301e0(void)

{
  return &PTR_DAT_00238334;
}


// ===== FUN_002301f0 @ 002301f0 (24 bytes)

undefined4 FUN_002301f0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00230160(PTR_DAT_00237f00,param_1,param_2);
  return uVar1;
}


// ===== FUN_00230210 @ 00230210 (18 bytes)

undefined4 FUN_00230210(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_002301e0(PTR_DAT_00237f00);
  return uVar1;
}


// ===== FUN_00230230 @ 00230230 (260 bytes)

void FUN_00230230(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  undefined1 auStack_60 [4];
  uint uStack_5c;
  
  uVar4 = (uint)(short)param_2[3];
  if ((uVar4 >> 1 & 1) != 0) {
    param_2[5] = 1;
    *param_2 = (int)param_2 + 0x43;
    param_2[4] = (int)param_2 + 0x43;
    return;
  }
  if (-1 < *(short *)((int)param_2 + 0xe)) {
    iVar1 = FUN_00233200(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_60);
    if (-1 < iVar1) {
      iVar1 = (uStack_5c & (uint)&DAT_0000f000) - 0x8000;
      bVar5 = iVar1 == 0;
      if ((uStack_5c & (uint)&DAT_0000f000) == 0x2000) {
        iVar1 = 1;
      }
      if ((bVar5) && ((code *)param_2[10] == FUN_00230e00)) {
        param_2[0x13] = 0x400;
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x400;
      }
      else {
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x800;
      }
      iVar3 = 0x400;
      goto LAB_00230290;
    }
    uVar4 = (uint)(short)param_2[3];
  }
  iVar1 = 0;
  *(ushort *)(param_2 + 3) = (ushort)uVar4 | 0x800;
  iVar3 = 0;
  if ((uVar4 & 0x80) != 0) {
    iVar3 = 0x40;
  }
LAB_00230290:
  iVar2 = FUN_0022ba80(param_1,iVar3);
  if (iVar2 == 0) {
    if (((uint)(int)(short)*(ushort *)(param_2 + 3) >> 9 & 1) == 0) {
      param_2[5] = 1;
      *param_2 = (int)param_2 + 0x43;
      param_2[4] = (int)param_2 + 0x43;
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 2;
      return;
    }
  }
  else {
    *(code **)(param_1 + 0x3c) = FUN_0022fce0;
    *param_2 = iVar2;
    param_2[4] = iVar2;
    param_2[5] = iVar3;
    *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x80;
    if ((iVar1 != 0) &&
       (iVar1 = FUN_00232470(param_1,(int)*(short *)((int)param_2 + 0xe)), iVar1 != 0)) {
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 1;
      return;
    }
  }
  return;
}


// ===== FUN_00230340 @ 00230340 (139 bytes)

uint * FUN_00230340(uint *param_1,char param_2,uint param_3)

{
  uint uVar1;
  
  while( true ) {
    if (((uint)param_1 & 3) == 0) {
      if (3 < param_3) {
        if (param_3 >> 2 == 1) {
          isync();
        }
        if ((param_3 >> 2 != 0) &&
           (uVar1 = *param_1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2)),
           (uVar1 + 0xfefefeff & (uVar1 ^ 0xffffffff) & 0x80808080) == 0)) {
          param_1 = param_1 + 1;
          param_3 = param_3 - 4;
        }
      }
      if (param_3 == 0) {
        return (uint *)0x0;
      }
      if (param_3 == 1) {
        isync();
      }
      if ((param_3 != 0) && ((char)*param_1 == param_2)) {
        return param_1;
      }
      return (uint *)0x0;
    }
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return (uint *)0x0;
    }
    if ((char)*param_1 == param_2) break;
    param_1 = (uint *)((int)param_1 + 1);
  }
  return param_1;
}


// ===== FUN_002303d0 @ 002303d0 (98 bytes)

int * FUN_002303d0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  if (iVar3 == 0) {
    iVar3 = FUN_002324a0(param_1,4,0x21);
    *(int *)(param_1 + 0x4c) = iVar3;
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  }
  piVar2 = (int *)(param_2 * 4 + iVar3);
  piVar1 = (int *)*piVar2;
  if (piVar1 == (int *)0x0) {
    iVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
    piVar1 = (int *)FUN_002324a0(param_1,1,iVar3 * 4 + 0x14);
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar1[1] = param_2;
    piVar1[2] = iVar3;
    piVar1[4] = 0;
    piVar1[3] = 0;
    return piVar1;
  }
  *piVar2 = *piVar1;
  piVar1[4] = 0;
  piVar1[3] = 0;
  return piVar1;
}


// ===== FUN_00230440 @ 00230440 (159 bytes)

int FUN_00230440(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 0x10);
  iVar3 = iVar1;
  if (iVar1 < 1) {
    iVar3 = 1;
  }
  if ((0 < iVar3) && ((iVar3 == 1 || (0 < iVar3)))) {
    iVar3 = ae_zext16(*(uint *)(param_2 + 0x14));
    param_4 = param_4 + param_3 * iVar3;
    iVar3 = ae_zext16(param_4);
    uVar2 = (param_4 >> 0x10) + param_3 * (*(uint *)(param_2 + 0x14) >> 0x10);
    param_4 = uVar2 >> 0x10;
    *(uint *)(param_2 + 0x14) = iVar3 + uVar2 * 0x10000;
  }
  if (param_4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar1) {
      iVar3 = FUN_002303d0(param_1,*(int *)(param_2 + 4) + 1);
      memcpy(iVar3 + 0xc,param_2 + 0xc,*(int *)(param_2 + 0x10) * 4 + 8);
      FUN_00236060(param_1,param_2);
      *(uint *)(iVar3 + iVar1 * 4 + 0x14) = param_4;
      *(int *)(iVar3 + 0x10) = iVar1 + 1;
      return iVar3;
    }
    *(uint *)(iVar1 * 4 + param_2 + 0x14) = param_4;
    *(int *)(param_2 + 0x10) = iVar1 + 1;
    return param_2;
  }
  return param_2;
}

