// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201396ac @ 201396ac (4 bytes)

void FUN_201396ac(void)

{
  return;
}


// ===== FUN_201396b0 @ 201396b0 (488 bytes)

void FUN_201396b0(int param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  iVar1 = param_1 * 0x4d8;
  uVar2 = *(ushort *)(param_2 + 0x40);
  *(ushort *)(param_2 + 0x40) = ~uVar2;
  uVar5 = *(ushort *)(param_2 + 0x30);
  uVar3 = *(ushort *)(param_2 + 0x42);
  *(ushort *)(param_2 + 0x42) = ~uVar3;
  uVar4 = *(ushort *)(param_2 + 0x32);
  uVar6 = 0;
  uVar7 = 0;
  bVar9 = (uVar2 & 0x8000) != 0;
  iVar8 = 0;
  if (bVar9) {
    *(int *)(&DAT_2090bb0c + iVar1) = *(int *)(&DAT_2090bb0c + iVar1) + 1;
  }
  bVar10 = (uVar2 & 0x2000) != 0;
  if (bVar10) {
    *(int *)(&DAT_2090bb10 + iVar1) = *(int *)(&DAT_2090bb10 + iVar1) + 1;
  }
  bVar11 = (uVar2 & 0x400) != 0;
  bVar12 = (uVar5 & 0x400) != 0;
  if (bVar11 && bVar12) {
    uVar5 = uVar5 & 0xfbff;
    uVar6 = 8;
    *(int *)(&DAT_2090bb14 + iVar1) = *(int *)(&DAT_2090bb14 + iVar1) + 1;
  }
  bVar13 = (uVar2 & 0x200) != 0;
  bVar14 = (uVar5 & 0x200) != 0;
  if (bVar13 && bVar14) {
    uVar5 = uVar5 & 0xfdff;
    uVar6 = uVar6 | 0x10;
    *(int *)(&DAT_2090bb18 + iVar1) = *(int *)(&DAT_2090bb18 + iVar1) + 1;
  }
  if ((uVar2 & 0x100) == 0 || (uVar5 & 0x100) == 0) {
    if (((!bVar13 || !bVar14) && ((!bVar11 || !bVar12) && (!bVar10 && !bVar9))) && (uVar2 != 0)) {
      *(int *)(&DAT_2090bb20 + iVar1) = *(int *)(&DAT_2090bb20 + iVar1) + 1;
    }
  }
  else {
    uVar5 = uVar5 & 0xfeff;
    iVar8 = 1;
    *(int *)(&DAT_2090bb1c + iVar1) = *(int *)(&DAT_2090bb1c + iVar1) + 1;
    *(undefined4 *)(&DAT_2090bb04 + iVar1) = 0;
  }
  *(ushort *)(param_2 + 0x30) = uVar5;
  if ((uVar3 & 0x800) != 0 && (uVar4 & 0x800) != 0) {
    uVar6 = uVar6 | 2;
    *(int *)(&DAT_2090bb24 + iVar1) = *(int *)(&DAT_2090bb24 + iVar1) + 1;
  }
  if (((uVar3 & 0x1000) != 0) &&
     (*(int *)(&DAT_2090bb28 + iVar1) = *(int *)(&DAT_2090bb28 + iVar1) + 1, (uVar4 & 0x1000) != 0))
  {
    uVar6 = uVar6 | 1;
    usbh_pipe_mark_done(param_1,0);
    FUN_20139658(param_1,0);
  }
  if ((uVar3 & 0x20) != 0) {
    uVar7 = 2;
    *(int *)(&DAT_2090bb2c + iVar1) = *(int *)(&DAT_2090bb2c + iVar1) + 1;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar7 = uVar7 | 1;
    *(int *)(&DAT_2090bb30 + iVar1) = *(int *)(&DAT_2090bb30 + iVar1) + 1;
  }
  if (uVar6 != 0) {
    itron_set_flg(*(undefined4 *)(&DAT_2090b674 + iVar1),uVar6);
  }
  if (iVar8 != 0) {
    itron_set_flg(*(undefined4 *)(&DAT_2090b680 + iVar1),iVar8);
  }
  if (uVar7 != 0) {
    itron_set_flg(*(undefined4 *)(&DAT_2090b67c + iVar1),uVar7);
    return;
  }
  return;
}


// ===== FUN_201398a0 @ 201398a0 (208 bytes)

undefined4 FUN_201398a0(int param_1,uint param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  do {
    uVar5 = (&DAT_2042019c)[iVar4 * 7];
    if ((param_2 & uVar5) != 0) {
      uVar1 = usbh_loc_cpu();
      *(ushort *)(*(int *)(param_1 + 8) + (&DAT_204201a4)[iVar4 * 7]) =
           *(ushort *)(*(int *)(param_1 + 8) + (&DAT_204201a4)[iVar4 * 7]) & 0xf7ff;
      *(ushort *)(*(int *)(param_1 + 8) + (&DAT_204201a8)[iVar4 * 7]) =
           *(ushort *)(*(int *)(param_1 + 8) + (&DAT_204201a8)[iVar4 * 7]) & 0xf7ff;
      itron_clr_flg(*(undefined4 *)(param_1 + 0x14),~uVar5);
      itron_unl_cpu(uVar1);
      iVar3 = *(int *)(param_1 + 8);
      uVar2 = *(ushort *)(iVar3 + (&DAT_204201b4)[iVar4 * 7]);
      if ((*(ushort *)(iVar3 + (&DAT_204201ac)[iVar4 * 7]) & 2) == 0) {
        uVar2 = uVar2 | 0x80;
      }
      else {
        uVar2 = uVar2 & 0xff7f;
      }
      *(ushort *)(iVar3 + (&DAT_204201b4)[iVar4 * 7]) = uVar2;
      FUN_2013ae40(param_1,0,0,0,iVar4,iVar4,6);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 1);
  return 0;
}


// ===== FUN_20139970 @ 20139970 (224 bytes)

undefined4 FUN_20139970(int param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  do {
    bVar2 = false;
    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x48);
    uVar8 = (uint)uVar1;
    *(ushort *)(*(int *)(param_1 + 8) + 0x48) = ~uVar1;
    iVar7 = 0;
    do {
      if ((uVar8 & 1) != 0) {
        bVar2 = true;
        iVar3 = param_1 + iVar7 * 0x70;
        if ((*(ushort *)(*(int *)(param_1 + 8) + (&DAT_20420144)[iVar7]) & 2) == 0) {
          if ((*(int *)(iVar3 + 0x90) == 0) &&
             (iVar6 = *(int *)(iVar3 + 0x84) + 1, *(int *)(iVar3 + 0x84) = iVar6, iVar6 < 3)) {
            *(undefined2 *)(*(int *)(param_1 + 8) + (&DAT_20420144)[iVar7]) = 1;
            goto LAB_20139a10;
          }
          uVar4 = *(undefined4 *)(iVar3 + 100);
          uVar5 = 0x10;
        }
        else {
          uVar5 = 2;
          *(undefined4 *)(iVar3 + 0x84) = 0xffffffff;
          uVar4 = *(undefined4 *)(iVar3 + 100);
        }
        itron_set_flg(uVar4,uVar5);
      }
LAB_20139a10:
      iVar7 = iVar7 + 1;
      uVar8 = uVar8 >> 1;
    } while (iVar7 < 10);
    if (!bVar2) {
      uVar4 = usbh_loc_cpu();
      *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x200;
      itron_unl_cpu(uVar4);
      return 0;
    }
  } while( true );
}


// ===== FUN_20139a50 @ 20139a50 (536 bytes)

/* WARNING: Removing unreachable block (ram,0x20139b8c) */

undefined4 FUN_20139a50(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 local_28 [4];
  
  if (param_2 == 0) {
    iVar6 = 2;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x3c);
  }
  uVar1 = *(undefined4 *)(param_1 + iVar6 * 4 + 0x30);
  iVar8 = *(int *)(&DAT_2042016c + iVar6 * 4);
  iVar2 = *(int *)(&DAT_20420178 + iVar6 * 4);
  iVar3 = param_1 + param_2 * 0x70;
  iVar7 = *(int *)(iVar3 + 0x98);
  if (iVar7 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + (&DAT_20420144)[param_2]) = 0;
    return 0xffffffff;
  }
  iVar4 = iVar7 + *(int *)(iVar3 + 0x9c) * 2;
  uVar9 = *(int *)(iVar7 + 8) + (uint)*(ushort *)(iVar4 + 0x24);
  iVar4 = (*(int *)(iVar7 + 8) + (uint)*(ushort *)(iVar4 + 0x26)) - uVar9;
  itron_twai_sem(uVar1,0xffffffff);
  uVar5 = (ushort)param_2;
  if ((uVar9 & 1) == 0) {
    uVar5 = uVar5 | 0x400;
  }
  if (iVar6 != 2 && iVar4 != 0) {
    uVar5 = uVar5 | 0x1000;
  }
  *(ushort *)(*(int *)(param_1 + 8) + iVar8) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar8) & 0x100 | uVar5;
  reg_wait_bits27(param_1,iVar8);
  if (iVar4 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar2) = 0xc000;
  }
  else {
    if (iVar6 == 2) {
      FUN_20138f58(param_1,uVar9,iVar4);
    }
    else {
      FUN_20138f30(iVar6,local_28);
    }
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar2) = 0x8000;
  }
  if (iVar6 != 2 && iVar4 != 0) {
    *(ushort *)(*(int *)(param_1 + 8) + iVar8) = *(ushort *)(*(int *)(param_1 + 8) + iVar8) & 0x100;
  }
  itron_sig_sem(uVar1);
  uVar9 = *(int *)(iVar3 + 0x9c) + 1;
  *(uint *)(iVar3 + 0x9c) = uVar9;
  if (*(uint *)(iVar7 + 0x20) <= uVar9) {
    if (*(code **)(iVar7 + 0x10) != (code *)0x0) {
      (**(code **)(iVar7 + 0x10))(*(undefined4 *)(iVar7 + 0x14),0);
    }
    iVar6 = *(int *)(iVar3 + 0xa4) + 1;
    *(int *)(iVar3 + 0xa4) = iVar6;
    uVar1 = 0;
    if (iVar6 != *(int *)(iVar3 + 0xa0)) {
      *(undefined4 *)(iVar3 + 0x9c) = 0;
      uVar1 = *(undefined4 *)(iVar3 + (*(byte *)(iVar3 + 0xa4) & 1) * 4 + 0xa8);
    }
    *(undefined4 *)(iVar3 + 0x98) = uVar1;
  }
  return 0;
}


// ===== FUN_20139c68 @ 20139c68 (168 bytes)

undefined4 FUN_20139c68(int param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  do {
    bVar2 = false;
    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x4a);
    uVar6 = (uint)uVar1;
    *(ushort *)(*(int *)(param_1 + 8) + 0x4a) = ~uVar1;
    iVar5 = 0;
    do {
      if ((uVar6 & 1) != 0) {
        iVar3 = param_1 + iVar5 * 0x70;
        if (*(int *)(iVar3 + 0x58) == 0) {
          bVar2 = true;
          if (*(int *)(iVar3 + 0x94) == 0) {
            itron_set_flg(*(undefined4 *)(iVar3 + 100),1);
          }
          else {
            FUN_20139a50(param_1,iVar5);
          }
        }
      }
      iVar5 = iVar5 + 1;
      uVar6 = uVar6 >> 1;
    } while (iVar5 < 10);
  } while (bVar2);
  uVar4 = usbh_loc_cpu();
  *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x400;
  itron_unl_cpu(uVar4);
  return 0;
}


// ===== FUN_20139d10 @ 20139d10 (104 bytes)

void FUN_20139d10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x8c) == param_2) {
    itron_set_flg(*(undefined4 *)(param_1 + 0x1c),2);
  }
  iVar2 = 0;
  do {
    iVar1 = param_1 + iVar2 * 0x70;
    if ((*(int *)(iVar1 + 0x50) != 0) && (*(int *)(iVar1 + 0x8c) == param_2)) {
      itron_set_flg(*(undefined4 *)(iVar1 + 100),0x10);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return;
}


// ===== FUN_20139d78 @ 20139d78 (396 bytes)

void FUN_20139d78(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  uint local_c;
  uint local_8;
  
  if (-1 < param_1) {
    param_1 = param_1 * 0x4d8;
    puVar4 = &DAT_2090b660 + param_1;
    local_8 = *(uint *)(&DAT_2090b674 + param_1);
    do {
      while( true ) {
        pvVar1 = itron_twai_flg(local_8,0xffff,1,&local_c,-1);
        if (pvVar1 == (void *)0x0) break;
        itron_dly_tsk(200);
      }
      if ((local_c & 0x101) != 0) {
        iVar3 = 0;
        do {
          if ((((&DAT_204201a0)[iVar3 * 7] & local_c) != 0) &&
             ((*(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[iVar3 * 7]) & 0x1000)
              != 0)) {
            uVar2 = usbh_loc_cpu();
            *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[iVar3 * 7]) =
                 *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[iVar3 * 7]) &
                 0xefff;
            *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201b0)[iVar3 * 7]) =
                 *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201b0)[iVar3 * 7]) &
                 0xffef;
            itron_unl_cpu(uVar2);
            itron_dly_tsk(10);
            uVar2 = usbh_loc_cpu();
            *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[iVar3 * 7]) =
                 *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[iVar3 * 7]) | 0x800
            ;
            itron_unl_cpu(uVar2);
            FUN_2013ae40(puVar4,0,0,0,iVar3,iVar3,7);
            FUN_20139d10(puVar4,iVar3);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 1);
      }
      if ((local_c & 0x202) != 0) {
        FUN_201398a0(puVar4);
      }
      if ((local_c & 8) != 0) {
        FUN_20139c68(puVar4);
      }
      if ((local_c & 0x10) != 0) {
        FUN_20139970(puVar4);
      }
    } while( true );
  }
  do {
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== FUN_20139f04 @ 20139f04 (104 bytes)

undefined4 FUN_20139f04(int param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar3 = param_3;
  if ((~(uint)param_2 & 1) != 0) {
    uVar3 = param_3 & 1;
    for (iVar2 = (int)param_3 / 2; 0 < iVar2; iVar2 = iVar2 + -1) {
      *param_2 = *(undefined2 *)(iVar1 + 0x16);
      param_2 = param_2 + 1;
    }
  }
  for (; 0 < (int)uVar3; uVar3 = uVar3 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)(iVar1 + 0x17);
    param_2 = (undefined2 *)((int)param_2 + 1);
  }
  return 0;
}


// ===== FUN_20139f6c @ 20139f6c (548 bytes)

undefined4 FUN_20139f6c(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  ushort *puVar8;
  undefined4 uVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  uint n;
  int iVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  undefined1 local_2c [8];
  
  if (param_2 == 1 || param_2 == 2) {
    iVar12 = *(int *)(param_1 + 0x3c);
  }
  else {
    iVar12 = 2;
  }
  uVar2 = *(undefined4 *)(param_1 + iVar12 * 4 + 0x30);
  iVar13 = *(int *)(&DAT_2042016c + iVar12 * 4);
  iVar3 = *(int *)(&DAT_20420178 + iVar12 * 4);
  iVar4 = (&DAT_20420144)[param_2];
  iVar11 = param_1 + param_2 * 0x70;
  uVar5 = *(uint *)(iVar11 + 0x70);
  iVar14 = *(int *)(iVar11 + 0x74);
  iVar15 = *(int *)(iVar11 + 0x78);
  itron_twai_sem(uVar2,0xffffffff);
  uVar10 = (ushort)param_2;
  if ((uVar5 & 1) == 0) {
    uVar10 = uVar10 | 0x400;
  }
  if (iVar12 != 2) {
    uVar10 = uVar10 | 0x1000;
  }
  *(ushort *)(*(int *)(param_1 + 8) + iVar13) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar13) & 0x100 | uVar10;
  reg_wait_bits27(param_1,iVar13);
  iVar6 = *(int *)(param_1 + 8);
  uVar10 = *(ushort *)(iVar6 + iVar3);
  n = uVar10 & 0xffff0fff;
  iVar15 = iVar15 + n;
  if (param_2 == 0) {
    if ((((uVar10 & 0xfff) == 0) ||
        (uVar16 = __aeabi_idivmod(n,*(uint *)(param_1 + 0x6c)), (int)(uVar16 >> 0x20) != 0)) ||
       (iVar14 <= iVar15)) goto LAB_2013a090;
LAB_2013a098:
    bVar1 = false;
  }
  else {
    if (((*(uint *)(*(int *)(param_1 + 0x4d4) + param_2 * 4 + -4) <= n) &&
        (uVar16 = __aeabi_idivmod(n,*(uint *)(iVar11 + 0x6c)), (int)(uVar16 >> 0x20) == 0)) &&
       (iVar15 < iVar14)) goto LAB_2013a098;
LAB_2013a090:
    bVar1 = true;
  }
  if (iVar14 < iVar15) {
    uVar7 = *(undefined4 *)(iVar11 + 100);
    uVar9 = 0x10;
  }
  else {
    if (bVar1) {
      puVar8 = (ushort *)(iVar6 + iVar4);
      *puVar8 = *puVar8 & 0xfffc;
    }
    *(uint *)(iVar11 + 0x70) = uVar5 + n;
    if ((uVar10 & 0xfff) == 0) {
      *(undefined2 *)(*(int *)(param_1 + 8) + iVar3) = 0x4000;
    }
    else if (iVar12 == 2) {
      FUN_20139f04(param_1,uVar5,n);
    }
    else {
      FUN_20138f30(iVar12,local_2c);
    }
    *(int *)(iVar11 + 0x78) = iVar15;
    if (!bVar1) goto LAB_2013a160;
    uVar7 = *(undefined4 *)(iVar11 + 100);
    uVar9 = 1;
  }
  itron_set_flg(uVar7,uVar9);
LAB_2013a160:
  if (iVar12 != 2) {
    *(ushort *)(*(int *)(param_1 + 8) + iVar13) =
         *(ushort *)(*(int *)(param_1 + 8) + iVar13) & 0xeff8;
  }
  itron_sig_sem(uVar2);
  return 0;
}


// ===== FUN_2013a198 @ 2013a198 (508 bytes)

undefined4 FUN_2013a198(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined1 local_28 [4];
  
  if (param_2 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x3c);
  }
  iVar4 = param_1 + param_2 * 0x70;
  uVar1 = *(undefined4 *)(param_1 + iVar7 * 4 + 0x30);
  iVar9 = *(int *)(&DAT_2042016c + iVar7 * 4);
  iVar2 = *(int *)(&DAT_20420178 + iVar7 * 4);
  iVar6 = *(int *)(iVar4 + 0x98);
  if (iVar6 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + (&DAT_20420144)[param_2]) = 0;
    uVar8 = 0;
    uVar10 = 0;
  }
  else {
    uVar10 = *(uint *)(iVar6 + 0x1c);
    uVar8 = *(int *)(iVar6 + 8) + (uint)*(ushort *)(iVar6 + *(int *)(iVar4 + 0x9c) * 2 + 0x24);
  }
  itron_twai_sem(uVar1,0xffffffff);
  uVar5 = (ushort)param_2;
  if ((uVar8 & 1) == 0) {
    uVar5 = uVar5 | 0x400;
  }
  if (iVar7 != 2) {
    uVar5 = uVar5 | 0x1000;
  }
  *(ushort *)(*(int *)(param_1 + 8) + iVar9) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar9) & 0x100 | uVar5;
  reg_wait_bits27(param_1,iVar9);
  uVar11 = *(ushort *)(*(int *)(param_1 + 8) + iVar2) & 0xffff0fff;
  if ((int)uVar10 < (int)uVar11) {
    uVar11 = uVar10;
  }
  if (uVar11 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar2) = 0x4000;
    if (uVar8 == 0) goto LAB_2013a368;
  }
  else {
    if (uVar8 == 0) goto LAB_2013a368;
    if (iVar7 == 2) {
      FUN_20139f04(param_1,uVar8,uVar11);
    }
    else {
      FUN_20138f30(iVar7,local_28);
    }
  }
  *(short *)(iVar6 + *(int *)(iVar4 + 0x9c) * 2 + 0x24) = (short)uVar11;
  uVar8 = *(int *)(iVar4 + 0x9c) + 1;
  *(uint *)(iVar4 + 0x9c) = uVar8;
  if (*(uint *)(iVar6 + 0x20) <= uVar8) {
    if (*(code **)(iVar6 + 0x10) != (code *)0x0) {
      (**(code **)(iVar6 + 0x10))(*(undefined4 *)(iVar6 + 0x14),0);
    }
    iVar2 = *(int *)(iVar4 + 0xa4) + 1;
    *(int *)(iVar4 + 0xa4) = iVar2;
    uVar3 = 0;
    if (iVar2 != *(int *)(iVar4 + 0xa0)) {
      *(undefined4 *)(iVar4 + 0x9c) = 0;
      uVar3 = *(undefined4 *)(iVar4 + (*(byte *)(iVar4 + 0xa4) & 1) * 4 + 0xa8);
    }
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
  }
LAB_2013a368:
  if (iVar7 != 2) {
    *(ushort *)(*(int *)(param_1 + 8) + iVar9) = *(ushort *)(*(int *)(param_1 + 8) + iVar9) & 0x100;
  }
  itron_sig_sem(uVar1);
  return 0;
}


// ===== FUN_2013a394 @ 2013a394 (176 bytes)

undefined4 FUN_2013a394(int param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  do {
    bVar2 = false;
    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x46);
    uVar6 = (uint)uVar1;
    *(ushort *)(*(int *)(param_1 + 8) + 0x46) = ~uVar1;
    iVar5 = 0;
    do {
      if ((uVar6 & 1) != 0) {
        iVar4 = param_1 + iVar5 * 0x70;
        if (*(int *)(iVar4 + 0x58) != 0) {
          bVar2 = true;
          if (*(int *)(iVar4 + 0x94) == 0) {
            *(undefined4 *)(iVar4 + 0x84) = 0;
            FUN_20139f6c(param_1,iVar5);
          }
          else {
            FUN_2013a198(param_1,iVar5);
          }
        }
      }
      iVar5 = iVar5 + 1;
      uVar6 = uVar6 >> 1;
    } while (iVar5 < 10);
  } while (bVar2);
  uVar3 = usbh_loc_cpu();
  *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x100;
  itron_unl_cpu(uVar3);
  return 0;
}


// ===== FUN_2013a444 @ 2013a444 (120 bytes)

void FUN_2013a444(int param_1)

{
  void *pvVar1;
  uint uVar2;
  uint local_4;
  
  if (param_1 < 0) {
    do {
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  uVar2 = *(uint *)(&DAT_2090b680 + param_1 * 0x4d8);
  do {
    while( true ) {
      pvVar1 = itron_twai_flg(uVar2,0xffff,1,&local_4,-1);
      if (pvVar1 == (void *)0x0) break;
      itron_dly_tsk(200);
    }
    if ((local_4 & 1) != 0) {
      FUN_2013a394(&DAT_2090b660 + param_1 * 0x4d8);
    }
  } while( true );
}


// ===== FUN_2013a4bc @ 2013a4bc (384 bytes)

/* WARNING: Removing unreachable block (ram,0x2013a564) */
/* WARNING: Removing unreachable block (ram,0x2013a604) */

undefined4 FUN_2013a4bc(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  param_1 = param_1 * 0x4d8;
  iVar6 = (&DAT_204201b0)[param_2 * 7];
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffef;
  itron_dly_tsk(10);
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) | 0x40;
  itron_dly_tsk(10);
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffbf | 0x10;
  itron_dly_tsk(2);
  uVar2 = fs_get_tick();
  uVar3 = uVar2;
  do {
    while( true ) {
      iVar4 = fs_get_tick(uVar3);
      if (9 < iVar4 - uVar2) {
        usbh_loc_cpu();
        *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
             *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffef;
        *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) =
             *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) | 0x800;
        itron_unl_cpu();
        return 7;
      }
      uVar1 = *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6);
      uVar3 = (uint)uVar1;
      if (((uVar1 & 4) == 0) && (uVar5 = uVar3 & 7, (uVar1 & 7) != 0)) break;
      uVar3 = itron_dly_tsk();
    }
    if (uVar5 == 1) {
      uVar7 = 2;
      goto LAB_2013a5c8;
    }
    if (uVar5 == 2) {
      uVar7 = 1;
      goto LAB_2013a5c8;
    }
  } while (uVar5 != 3);
  uVar7 = 0;
LAB_2013a5c8:
  usbh_loc_cpu();
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a8)[param_2 * 7]) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a8)[param_2 * 7]) & 0xefff;
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) | 0x1000;
  itron_unl_cpu();
  return uVar7;
}


// ===== FUN_2013a63c @ 2013a63c (84 bytes)

void FUN_2013a63c(int param_1,byte *param_2,uint *param_3,byte *param_4,ushort *param_5,
                 undefined1 *param_6)

{
  *param_3 = *(byte *)(param_1 + 2) & 0x80;
  *param_4 = *(byte *)(param_1 + 2) & 0x1f;
  *param_2 = *(byte *)(param_1 + 3) & 3;
  *param_5 = (ushort)*(byte *)(param_1 + 4) + (ushort)*(byte *)(param_1 + 5) * 0x100 & 0x7ff;
  *param_6 = *(undefined1 *)(param_1 + 6);
  return;
}


// ===== FUN_2013a690 @ 2013a690 (264 bytes)

undefined4 FUN_2013a690(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  
  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 8);
    if (iVar7 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar2 = *(int *)(iVar7 + 8);
      uVar1 = *(undefined4 *)(param_1 + 0x14);
      iVar4 = *(int *)(&DAT_20420118 + iVar3 * 4);
      *(short *)(*(int *)(iVar2 + 8) + 100) = (short)iVar3;
      iVar6 = *(int *)(param_1 + 0x1c);
      if (iVar6 == 0) {
        uVar8 = 0x4000;
      }
      else {
        uVar8 = 0x8000;
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar9 = 0x10;
      }
      else {
        uVar9 = 0;
      }
      if (iVar6 != 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x180;
      }
      if ((iVar6 == 0) && (*(int *)(param_1 + 0x18) != 0)) {
        *(ushort *)(*(int *)(iVar2 + 8) + iVar4) = *(ushort *)(*(int *)(iVar2 + 8) + iVar4) | 0x200;
      }
      *(ushort *)(*(int *)(iVar2 + 8) + 0x68) = uVar8 | uVar9 | (ushort)uVar1 | uVar5;
      if (*(int *)(param_1 + 0x1c) != 0) {
        *(ushort *)(*(int *)(iVar2 + 8) + 0x6e) = (ushort)*(byte *)(param_1 + 0x20);
      }
      *(ushort *)(*(int *)(iVar2 + 8) + 0x6c) =
           *(ushort *)(param_1 + 0x2c) | (ushort)*(byte *)(iVar7 + 0xc) << 0xc;
      *(undefined2 *)(*(int *)(iVar2 + 8) + (&DAT_20420144)[iVar3]) = 0x100;
      itron_clr_flg(*(undefined4 *)(param_1 + 0x24),0);
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar7 + 0xc);
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0xffffffff;
}


// ===== FUN_2013a798 @ 2013a798 (300 bytes)

int FUN_2013a798(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort local_30 [2];
  char local_2c [4];
  undefined4 local_28;
  byte local_24 [4];
  byte local_20 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 8);
  FUN_2013a63c(param_2,local_2c,&local_28,local_24,local_30,local_20);
  if (param_3 <= param_4) {
    do {
      iVar2 = iVar4 + param_3 * 0x70;
      if ((*(int *)(iVar2 + 0x50) == 0) && ((int)(uint)local_30[0] <= *(int *)(iVar2 + 0x68))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        *(int *)(iVar2 + 0x48) = param_1;
        *(undefined4 *)(iVar2 + 0x50) = 1;
        *(uint *)(iVar2 + 0x54) = (uint)local_24[0];
        *(undefined4 *)(iVar2 + 0x58) = local_28;
        *(uint *)(iVar2 + 0x6c) = (uint)local_30[0];
        if (local_2c[0] == '\x03') {
          iVar4 = 2;
          iVar3 = 0;
          goto LAB_2013a8a0;
        }
        *(undefined1 *)(iVar2 + 0x60) = 0;
        *(undefined4 *)(iVar2 + 0x5c) = 0;
        goto LAB_2013a85c;
      }
      param_3 = param_3 + 1;
    } while (param_3 <= param_4);
  }
  return 0;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 << 1;
    if (6 < iVar3) break;
LAB_2013a8a0:
    if ((int)(uint)local_20[0] <= iVar4) break;
  }
  *(char *)(iVar2 + 0x60) = (char)iVar3;
  *(undefined4 *)(iVar2 + 0x5c) = 1;
LAB_2013a85c:
  *(undefined4 *)(iVar2 + 0x8c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + 0x90) = 0;
  FUN_20138c84(param_1);
  return iVar2 + 0x40;
}


// ===== FUN_2013a90c @ 2013a90c (120 bytes)

int FUN_2013a90c(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  if (param_1 != 0) {
    bVar2 = *(byte *)(param_2 + 3) & 3;
    if (bVar2 == 2) {
      iVar1 = FUN_2013a798(param_1,param_2,1,4);
      if (iVar1 != 0) {
        FUN_2013a690();
      }
      return iVar1;
    }
    if (bVar2 == 3) {
      iVar1 = FUN_2013a798(param_1,param_2,6,9);
      if (iVar1 != 0) {
        FUN_2013a690();
      }
      return iVar1;
    }
  }
  return 0;
}


// ===== FUN_2013a93c @ 2013a93c (152 bytes)

undefined4 FUN_2013a93c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 8;
  iVar5 = *(int *)(param_1 + 0x4d4);
  iVar1 = 0;
  do {
    *(short *)(*(int *)(param_1 + 8) + 100) = (short)(iVar1 + 1);
    iVar2 = *(int *)(iVar5 + iVar1 * 4);
    *(int *)(param_1 + (iVar1 + 1) * 0x70 + 0x68) = iVar2;
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = ((int)(iVar2 + 0x3f + ((uint)(iVar2 + 0x3f >> 0x1f) >> 0x1a)) >> 6) + -1;
    }
    *(ushort *)(*(int *)(param_1 + 8) + 0x6a) = (ushort)iVar4 | (ushort)(iVar3 << 10);
    if (iVar2 != 0) {
      iVar4 = iVar3 + iVar4 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  iVar1 = 6;
  do {
    iVar4 = iVar1 + 1;
    *(undefined4 *)(param_1 + iVar1 * 0x70 + 0x68) = 0x40;
    iVar1 = iVar4;
  } while (iVar4 < 10);
  return 0;
}


// ===== FUN_2013a9d4 @ 2013a9d4 (20 bytes)

undefined * FUN_2013a9d4(int param_1)

{
  return &DAT_2090b660 + param_1 * 0x4d8;
}


// ===== FUN_2013a9e8 @ 2013a9e8 (116 bytes)

undefined4 FUN_2013a9e8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = usbh_loc_cpu();
  *(ushort *)(*(int *)(param_1 + 8) + 0x36) = *(ushort *)(*(int *)(param_1 + 8) + 0x36) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x38) = *(ushort *)(*(int *)(param_1 + 8) + 0x38) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x3a) = *(ushort *)(*(int *)(param_1 + 8) + 0x3a) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x700;
  *(ushort *)(*(int *)(param_1 + 8) + 0x32) = *(ushort *)(*(int *)(param_1 + 8) + 0x32) | 0x830;
  itron_unl_cpu(uVar1);
  return 0;
}


// ===== FUN_2013aa5c @ 2013aa5c (68 bytes)

void FUN_2013aa5c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined2 *)(iVar1 + 0x12) = *(undefined2 *)(iVar1 + 0x12);
  *(ushort *)(iVar1 + 0x20) = *(ushort *)(iVar1 + 0x20) & 0xfeff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x28) = *(ushort *)(*(int *)(param_1 + 8) + 0x28) & 0xfeff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x2c) = *(ushort *)(*(int *)(param_1 + 8) + 0x2c) & 0xfeff;
  return;
}


// ===== FUN_2013aaa0 @ 2013aaa0 (4 bytes)

void FUN_2013aaa0(void)

{
  return;
}


// ===== FUN_2013aaa4 @ 2013aaa4 (16 bytes)

void FUN_2013aaa4(int param_1)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + 2) = 3;
  return;
}


// ===== FUN_2013aab4 @ 2013aab4 (200 bytes)

undefined4 FUN_2013aab4(undefined4 *param_1)

{
  ushort uVar1;
  
  uVar1 = USB_SYSCFG0_0;
  if ((uVar1 & 2) == 0) {
    uVar1 = USB_SYSCFG0_0;
    USB_SYSCFG0_0 = uVar1 | 2;
    itron_dly_tsk(2);
  }
  *(undefined2 *)(param_1[2] + 0x102) = 0x4000;
  FUN_2013aaa4(param_1);
  *(ushort *)param_1[2] = *(ushort *)param_1[2] & 0xfffe;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 1;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x40;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x80;
  FUN_2013aa5c(param_1);
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x20;
  FUN_2013b538(*param_1,0);
  FUN_2013a93c(param_1);
  FUN_2013a9e8(param_1);
  return 0;
}


// ===== FUN_2013ab7c @ 2013ab7c (32 bytes)

undefined4 FUN_2013ab7c(int param_1,uint param_2)

{
  if ((1 < param_2) && (param_2 != 2)) {
    param_2 = 2;
  }
  *(uint *)(param_1 + 0x3c) = param_2;
  return 0;
}


// ===== FUN_2013ab9c @ 2013ab9c (104 bytes)

undefined4 FUN_2013ab9c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  if (param_1 < 2) {
    iVar1 = param_1 * 0x4d8;
    puVar3 = (uint *)(&DAT_2090b660 + iVar1);
    if (*(int *)(&DAT_2090b664 + iVar1) == 0) {
      *(undefined4 *)(&DAT_2090b668 + iVar1) = param_2;
      *puVar3 = param_1;
      FUN_2013ab7c(puVar3,param_3);
      *(undefined4 *)(&DAT_2090b664 + iVar1) = 1;
      *(undefined4 *)(iVar1 + 0x2090bb34) = param_4;
      FUN_2013aab4(puVar3);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_2013ad24 @ 2013ad24 (44 bytes)

void FUN_2013ad24(int param_1)

{
  if (param_1 != 0) {
    itron_set_flg(*(undefined4 *)(param_1 + 0x24),8);
    *(undefined4 *)(param_1 + 0x10) = 0;
    return;
  }
  return;
}


// ===== FUN_2013ad50 @ 2013ad50 (8 bytes)

undefined4 FUN_2013ad50(undefined4 param_1,int param_2)

{
  *(undefined2 *)(*(int *)(*(int *)(param_2 + 4) + 8) + (&DAT_20420144)[*(int *)(param_2 + 0xc)]) =
       0x100;
  return 0;
}


// ===== FUN_2013ad58 @ 2013ad58 (60 bytes)

void FUN_2013ad58(uint param_1,int param_2,int param_3)

{
  ushort uVar1;
  
  if ((param_1 < 3) && (param_2 == 0)) {
    uVar1 = *(ushort *)(*(int *)(&DAT_2090b668 + param_1 * 0x4d8) + 8);
    if (param_3 == 0) {
      uVar1 = uVar1 | 0x200;
    }
    else {
      uVar1 = uVar1 & 0xfdff;
    }
    *(ushort *)(*(int *)(&DAT_2090b668 + param_1 * 0x4d8) + 8) = uVar1;
  }
  return;
}


// ===== FUN_2013ad94 @ 2013ad94 (88 bytes)

undefined4 FUN_2013ad94(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    uVar1 = 7;
  }
  else {
    uVar1 = 6;
  }
  FUN_2013ae40(&DAT_2090b660 + *(int *)(param_1 + 8) * 0x4d8,0,0,param_2,param_3,
               *(undefined1 *)(*(int *)(param_1 + 0x8d8) + 0x19),uVar1);
  return 0;
}


// ===== FUN_2013adec @ 2013adec (84 bytes)

undefined4 FUN_2013adec(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_2013ae40(&DAT_2090b660 + *(int *)(param_1 + 8) * 0x4d8,0,0,param_2,param_3,
               *(undefined1 *)(*(int *)(param_1 + 0x8d8) + 0x19),8);
  return 0;
}


// ===== FUN_2013ae40 @ 2013ae40 (100 bytes)

undefined4
FUN_2013ae40(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            uint param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = itron_tsnd_dtq(*(undefined4 *)(&DAT_2091c214 + *param_1 * 8),
                         *param_1 << 0x18 | (param_2 & 0xf) << 0x14 | (param_3 & 0xf) << 0x10 |
                         (param_4 & 0xf) << 0xc | (param_5 & 0xf) << 8 | (param_6 & 0xf) << 4 |
                         param_7 & 0xf,0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== FUN_2013aea4 @ 2013aea4 (140 bytes)

undefined4 FUN_2013aea4(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while (((iVar2 = *param_1 * 0x34 + 0x2091c220 + iVar1 * 0x34, *(byte *)(iVar2 + 0x16) != param_2
          || (*(byte *)(iVar2 + 0x17) != param_3)) || (*(int *)(iVar2 + 4) == 0))) {
    iVar1 = iVar1 + 1;
    if (0 < iVar1) {
      return 0xffffffff;
    }
  }
  if (*(code **)(iVar2 + 0x28) != (code *)0x0) {
    (**(code **)(iVar2 + 0x28))(**(undefined4 **)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),iVar2);
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return 0;
}


// ===== FUN_2013af30 @ 2013af30 (116 bytes)

int FUN_2013af30(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = *param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = 1;
      *(int **)(iVar1 + 8) = param_1;
      *(undefined4 *)(iVar1 + 0x2c) = param_2;
      *(undefined4 *)(iVar1 + 0x28) = 0;
      *(undefined4 *)(iVar1 + 0x30) = 0;
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return 0;
}


// ===== FUN_2013afa4 @ 2013afa4 (660 bytes)

undefined4 FUN_2013afa4(undefined4 param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte local_130 [2];
  byte local_12e;
  byte local_12d;
  undefined1 local_12c;
  undefined1 local_12b;
  undefined1 local_12a;
  byte local_129;
  byte local_128;
  byte local_127;
  byte local_126;
  byte local_125;
  byte local_124;
  byte local_123;
  uint local_30;
  uint local_2c;
  
  local_30 = param_2 >> 0x18;
  pbVar6 = local_130;
  uVar12 = (param_2 & 0xffff) >> 0xc;
  uVar11 = (param_2 & 0xfff) >> 8;
  uVar9 = (param_2 & 0xff) >> 4;
  uVar4 = FUN_2013a9d4();
  iVar7 = 0;
  do {
    iVar8 = local_30 * 0x34 + 0x2091c220 + iVar7 * 0x34;
    if (((*(int *)(iVar8 + 4) != 0) && (*(byte *)(iVar8 + 0x16) == uVar12)) &&
       (*(byte *)(iVar8 + 0x17) == uVar11)) {
      FUN_2013aea4(uVar4,uVar12,uVar11);
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 1);
  iVar7 = FUN_2013af30(uVar4,uVar9);
  if (iVar7 != 0) {
    iVar8 = 0;
    local_2c = uVar9;
LAB_2013b058:
    iVar10 = iVar8 + 1;
    if (iVar8 < 4) {
      itron_dly_tsk(10);
      uVar9 = FUN_2013a4bc(local_30,uVar11);
      iVar8 = iVar10;
      if (uVar9 < 3) {
        *(char *)(iVar7 + 0x19) = (char)local_2c;
        uVar4 = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(iVar7 + 0xc) = 0;
        *(byte *)(iVar7 + 0x14) = (byte)(param_2 >> 0x10) >> 4;
        *(byte *)(iVar7 + 0x15) = (byte)((param_2 << 0xc) >> 0x1c);
        *(byte *)(iVar7 + 0x16) = (byte)(param_2 >> 8) >> 4;
        *(byte *)(iVar7 + 0x17) = (byte)((param_2 << 0x14) >> 0x1c);
        *(char *)(iVar7 + 0x18) = (char)uVar9;
        *(undefined4 *)(iVar7 + 0x10) = 8;
        iVar10 = usbh_get_device_descriptor(iVar7,local_130,8);
        if (iVar10 < 0) {
LAB_2013b114:
          *(undefined4 *)(iVar7 + 0xc) = uVar4;
        }
        else {
          *(uint *)(iVar7 + 0x10) = (uint)local_129;
          iVar10 = usbh_set_address(iVar7,uVar4);
          if (iVar10 < 0) goto LAB_2013b114;
          *(undefined4 *)(iVar7 + 0xc) = uVar4;
          itron_dly_tsk(10);
          iVar10 = 0;
          while (iVar5 = usbh_get_device_descriptor(iVar7,local_130,0x12), iVar5 < 0) {
            iVar10 = iVar10 + 1;
            if (3 < iVar10) goto LAB_2013b058;
          }
          iVar10 = 0;
          *(undefined1 *)(iVar7 + 0x1a) = local_12c;
          *(undefined1 *)(iVar7 + 0x1b) = local_12b;
          *(undefined1 *)(iVar7 + 0x1c) = local_12a;
          *(ushort *)(iVar7 + 0x1e) = (ushort)local_128 + (ushort)local_127 * 0x100;
          *(ushort *)(iVar7 + 0x20) = (ushort)local_126 + (ushort)local_125 * 0x100;
          *(ushort *)(iVar7 + 0x22) = (ushort)local_124 + (ushort)local_123 * 0x100;
          do {
            iVar5 = usbh_get_config_descriptor(iVar7,local_130,0xff);
            if (-1 < iVar5) {
              iVar8 = (uint)local_12e + (uint)local_12d * 0x100;
              do {
                bVar1 = *pbVar6;
                if (pbVar6[1] == 4) {
                  bVar2 = pbVar6[6];
                  bVar3 = pbVar6[7];
                  *(byte *)(iVar7 + 0x24) = pbVar6[5];
                  *(byte *)(iVar7 + 0x25) = bVar2;
                  *(byte *)(iVar7 + 0x26) = bVar3;
                }
                iVar8 = iVar8 - (uint)bVar1;
                pbVar6 = pbVar6 + bVar1;
              } while (0 < iVar8);
              iVar8 = FUN_20137fac(local_30,uVar4,iVar7);
              if (iVar8 == 0) {
                *(code **)(iVar7 + 0x28) = FUN_20138410;
              }
              return 0;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 4);
        }
      }
      else if (uVar9 == 7) {
        iVar8 = 4;
      }
      goto LAB_2013b058;
    }
    *(undefined4 *)(iVar7 + 4) = 0;
    *(undefined4 *)(iVar7 + 0x28) = 0;
  }
  return 0xffffffff;
}


// ===== FUN_2013b238 @ 2013b238 (124 bytes)

void FUN_2013b238(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint auStack_8 [2];
  
  uVar7 = *(undefined4 *)(&DAT_2091c214 + param_1 * 8);
  do {
    while (iVar4 = itron_trcv_dtq(uVar7,auStack_8,0xffffffff), uVar3 = auStack_8[0], iVar4 != 0) {
      itron_dly_tsk(500);
    }
    uVar1 = auStack_8[0] & 0xffff;
    uVar2 = auStack_8[0] & 0xfff;
    uVar6 = auStack_8[0] & 0xf;
    uVar5 = FUN_2013a9d4(auStack_8[0] >> 0x18);
    if (uVar6 == 6) {
      FUN_2013afa4(param_1 * 8 + 0x2091c210,uVar3);
    }
    else if (uVar6 == 7) {
      FUN_2013aea4(uVar5,uVar1 >> 0xc,uVar2 >> 8);
    }
  } while( true );
}


// ===== FUN_2013b2b4 @ 2013b2b4 (68 bytes)

undefined4 FUN_2013b2b4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    iVar1 = param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(int *)(iVar1 + 0xc) = iVar2 + 1;
    iVar2 = iVar3;
  } while (iVar3 < 1);
  return 0;
}


// ===== usbh_pipe_mark_done @ 2013b2f8 (84 bytes)

/* Sets +0x30 = 1 in the pipe slot (0x2091C220, 0x34 each) whose +0x2C matches [fact] */

void usbh_pipe_mark_done(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    if ((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + 0x2c) == param_2)) {
      *(undefined4 *)(iVar1 + 0x30) = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return;
}


// ===== FUN_2013b34c @ 2013b34c (4 bytes)

void FUN_2013b34c(void)

{
  return;
}


// ===== usbh_get_device_descriptor @ 2013b35c (76 bytes)

/* SETUP 0x80, 6 (GET_DESCRIPTOR), wValue 0x0100 (device), length n [fact] */

void usbh_get_device_descriptor(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0x80;
  local_f = 6;
  local_e = 0x100;
  local_c = 0;
  local_a = (undefined2)param_3;
  usbh_control_req(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== usbh_get_config_descriptor @ 2013b3a8 (76 bytes)

/* SETUP 0x80, 6, wValue 0x0200 (configuration) [fact] */

void usbh_get_config_descriptor(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0x80;
  local_f = 6;
  local_e = 0x200;
  local_c = 0;
  local_a = (undefined2)param_3;
  usbh_control_req(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== usbh_set_address @ 2013b3f4 (72 bytes)

/* SETUP 0x00, 5 (SET_ADDRESS), wValue = address [fact] */

void usbh_set_address(undefined4 param_1,undefined2 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0;
  local_f = 5;
  local_c = 0;
  local_a = 0;
  local_e = param_2;
  usbh_control_req(0,param_1,&local_10,0,0);
  return;
}


// ===== usbh_set_configuration @ 2013b43c (72 bytes)

/* SETUP 0x00, 9 (SET_CONFIGURATION), wValue = configuration [fact] */

void usbh_set_configuration(undefined4 param_1,undefined2 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0;
  local_f = 9;
  local_c = 0;
  local_a = 0;
  local_e = param_2;
  usbh_control_req(0,param_1,&local_10,0,0);
  return;
}


// ===== usbh_get_hub_descriptor @ 2013b484 (72 bytes)

/* SETUP 0xA0 (class, device), 6 (GET_DESCRIPTOR) [fact for the packet; hub class by the request
   type] */

void usbh_get_hub_descriptor(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0xa0;
  local_f = 6;
  local_c = 0;
  local_e = 0;
  local_a = (undefined2)param_3;
  usbh_control_req(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== FUN_2013b4cc @ 2013b4cc (88 bytes)

void FUN_2013b4cc(void)

{
  gic_def_inh(0x49,0x204201b8);
  gic_enable_irq(0x49);
  FUN_2013ab9c(0,&USB_SYSCFG0_0,2,&DAT_20808ac0);
  gic_def_inh(0x4a,0x204201c4);
  gic_enable_irq(0x4a);
  FUN_2013ab9c(1,&USB_SYSCFG0_1,2,&DAT_20808ac0);
  return;
}


// ===== usbh_loc_cpu @ 2013b524 (16 bytes)

/* itron_loc_cpu, returns 0 (critical section of the USB host stack) [fact] */

undefined4 usbh_loc_cpu(void)

{
  itron_loc_cpu();
  return 0;
}


// ===== FUN_2013b538 @ 2013b538 (8 bytes)

void FUN_2013b538(undefined4 param_1)

{
  gpio_usb0_en(param_1,1);
  return;
}


// ===== FUN_2013b540 @ 2013b540 (4 bytes)

void FUN_2013b540(void)

{
  return;
}


// ===== FUN_2013b544 @ 2013b544 (8 bytes)

undefined4 FUN_2013b544(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}

