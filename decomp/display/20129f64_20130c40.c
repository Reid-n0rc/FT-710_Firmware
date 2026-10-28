// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20129f64 @ 20129f64 (1676 bytes)

void FUN_20129f64(char *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined **unaff_r5;
  uint uVar6;
  uint uVar7;
  undefined **ppuVar8;
  uint uVar9;
  uint uVar10;
  undefined *local_9c [4];
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  byte local_8a;
  byte local_89;
  undefined1 auStack_84 [12];
  undefined1 local_78;
  undefined1 auStack_74 [12];
  undefined1 local_68;
  uint local_64;
  uint local_60;
  byte local_5c [4];
  uint local_58;
  uint local_54;
  undefined1 auStack_50 [8];
  uint local_48;
  uint local_44;
  uint local_40;
  undefined *local_3c;
  undefined *local_38;
  char *pcStack_30;
  int iStack_2c;
  int local_28;
  
  pcStack_30 = param_1;
  iStack_2c = param_2;
  local_28 = param_3;
  local_9c[3] = (undefined *)fb_get_layer_addr(DAT_208085b8);
  local_38 = &DAT_2016dedc;
  local_3c = &DAT_20800800;
  local_60 = (uint)(byte)param_1[0x46];
  local_40 = (uint)*(byte *)(param_2 + 0x46);
  bVar1 = param_1[0x49];
  local_44 = (uint)*(byte *)(param_2 + 0x49);
  local_64 = (uint)bVar1;
  FUN_201636cc(&uStack_8c,param_1 + 0x4a);
  FUN_201636cc(auStack_50,param_2 + 0x4a);
  bVar2 = param_1[3];
  uVar5 = bVar1 & 0xf;
  uVar10 = bVar2 & 0x80;
  local_58 = *(byte *)(param_2 + 3) & 0x80;
  memcpy(auStack_84,param_1 + 0x4f,0xc);
  local_78 = 0;
  memcpy(auStack_74,param_2 + 0x4f,0xc);
  local_68 = 0;
  local_54 = (uint)*(byte *)(param_2 + 0x47);
  uVar6 = (uint)(byte)param_1[0x47];
  bVar1 = param_1[0x48];
  uVar7 = (uint)bVar1;
  ppuVar8 = (undefined **)&DAT_20800690;
  local_48 = (uint)*(byte *)(param_2 + 0x48);
  if (uVar6 == 1) {
    if (((local_28 != 0) || (uVar10 != local_58)) || (local_54 != 1)) {
      fb_copy_rect(local_9c[3],DAT_20800692 + -3,DAT_20800778,*(undefined2 *)PTR_DAT_20802ff4,
                   ((DAT_2080077a + *(short *)(PTR_DAT_20802ff4 + 2)) - DAT_20800692) + 3);
      if ((uVar5 == 4 || uVar5 == 5) || uVar5 == 7) {
        puVar4 = &DAT_2016df1c;
        if ((bVar2 & 0x80) != 0) {
          puVar4 = &DAT_2016defc;
        }
        gui_draw_runs(local_9c[3],DAT_20800692,DAT_20800690,puVar4);
      }
      goto LAB_2012a1b0;
    }
LAB_2012a1bc:
    if (((uVar10 != local_58) || (local_60 != local_40)) ||
       ((uVar6 != local_54 || (uVar7 != local_48)))) goto LAB_2012a1f0;
  }
  else {
    switch(uVar6) {
    case 2:
      if (uVar7 < 99) goto switchD_2012a048_caseD_7;
      ppuVar8 = (undefined **)0x20800694;
      break;
    case 5:
      ppuVar8 = (undefined **)0x2080069c;
      break;
    case 7:
switchD_2012a048_caseD_7:
      ppuVar8 = (undefined **)0x20800698;
      break;
    case 9:
    case 10:
      ppuVar8 = (undefined **)0x208006a0;
    }
    unaff_r5 = ppuVar8;
    if (((local_28 == 0) && (uVar10 == local_58)) &&
       ((uVar6 == local_54 && (uVar7 == *(byte *)(param_2 + 0x48))))) goto LAB_2012a1bc;
    fb_copy_rect(local_9c[3],DAT_20800692 + -3,DAT_20800778,*(undefined2 *)PTR_DAT_20802ff4,
                 ((DAT_2080077a + *(short *)(PTR_DAT_20802ff4 + 2)) - DAT_20800692) + 3);
    gui_draw_runs(local_9c[3],*(ushort *)((int)ppuVar8 + 2),*(ushort *)ppuVar8,
                  *(undefined4 *)(&DAT_2080265c + uVar6 * 4));
LAB_2012a1b0:
    if (local_28 == 0) goto LAB_2012a1bc;
LAB_2012a1f0:
    if ((uVar5 == 4 || uVar5 == 5) || uVar5 == 7) {
      uVar10 = local_60;
      if (0xf < local_60) {
        uVar10 = 0xf;
      }
      fb_copy_rect(local_9c[3],DAT_2080077a,DAT_20800778,*(undefined2 *)(&PTR_DAT_20802ff4)[uVar10],
                   *(undefined2 *)((int)(&PTR_DAT_20802ff4)[uVar10] + 2));
      gui_draw_runs(local_9c[3],DAT_2080077a,DAT_20800778,(&PTR_DAT_20802ff4)[uVar10]);
    }
  }
  if (uVar6 == 2) {
    if ((uVar5 != 4 && uVar5 != 5) && uVar5 != 7) goto LAB_2012a4b4;
    uVar10 = 0;
    if (uVar7 < 99) {
      uVar10 = 2;
      local_9c[0] = *(undefined **)(&DAT_20802338 + ((uint)((short)(uVar7 + 1) * 0xcd) >> 0xb) * 4);
      local_9c[1] = *(undefined **)(&DAT_20802338 + ((uVar7 + 1) % 10) * 4);
    }
    else if (uVar7 < 0x75) {
      uVar10 = 3;
      local_9c[0] = local_38;
      local_9c[1] = (&PTR_DAT_2080233c)[(int)(uVar7 - 99) / 2];
      local_9c[2] = (undefined *)*(undefined4 *)(local_3c + (uVar7 & 1) * 4);
    }
    uVar9 = 0;
    if (uVar10 == 0) goto LAB_2012a4b4;
    do {
      gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                    DAT_2080068c * uVar9 +
                    (uint)*(ushort *)unaff_r5 + (uint)*(ushort *)PTR_DAT_20802664 & 0xffff,
                    local_9c[uVar9]);
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < uVar10);
  }
  if (uVar6 == 7) {
    if ((uVar5 != 5 && uVar5 != 4) && uVar5 != 7) goto LAB_2012a4b4;
    uVar10 = 0;
    iVar3 = (short)(bVar1 - 0x74) * 0xcd;
    local_9c[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
    local_9c[1] = *(undefined **)(&DAT_20802338 + ((int)(uVar7 - 0x74) % 10) * 4);
    do {
      gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                    DAT_2080068c * uVar10 +
                    (uint)*(ushort *)unaff_r5 + (uint)*(ushort *)PTR_DAT_20802678 & 0xffff,
                    local_9c[uVar10]);
      uVar10 = uVar10 + 1 & 0xff;
    } while (uVar10 < 2);
  }
  if ((uVar6 == 5) && ((uVar5 == 5 || uVar5 == 4) || uVar5 == 7)) {
    local_9c[0] = (undefined *)0x0;
    if (9 < (int)(uVar7 - 0x82)) {
      iVar3 = (short)(uVar7 - 0x82) * 0xcd;
      local_9c[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
    }
    uVar6 = 0;
    local_9c[1] = *(undefined **)(&DAT_20802338 + ((int)(uVar7 - 0x82) % 10) * 4);
    do {
      if (local_9c[uVar6] != (undefined *)0x0) {
        gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                      DAT_2080068c * uVar6 +
                      (uint)*(ushort *)PTR_DAT_20802670 + (uint)*(ushort *)unaff_r5 & 0xffff);
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 2);
  }
LAB_2012a4b4:
  if (((((local_28 != 0) || (local_64 != local_44)) ||
       (iVar3 = FUN_2015507c(&uStack_8c,auStack_50,5), iVar3 != 0)) ||
      (iVar3 = FUN_2015507c(auStack_84,auStack_74,0xd), iVar3 != 0)) &&
     ((uVar5 == 5 || uVar5 == 4) || uVar5 == 7)) {
    if (uVar5 == 4) {
      unaff_r5 = &PTR_DAT_20802514;
    }
    else if (uVar5 == 5) {
      unaff_r5 = &PTR_DAT_20802548;
    }
    else if (uVar5 == 7) {
      unaff_r5 = &PTR_DAT_20802360;
    }
    fb_copy_rect(local_9c[3],DAT_20800772,DAT_20801864,
                 (DAT_20801880 + *(short *)*unaff_r5) - DAT_20801864,0x26);
    if ((*param_1 == '0') && (param_1[0x98] == '\a')) {
      uVar5 = 0;
      local_5c[0] = local_8a >> 4;
      local_5c[1] = local_8a & 0xf;
      local_5c[2] = local_89 >> 4;
      do {
        if (local_5c[uVar5] < 0xc) {
          gui_draw_runs(local_9c[3],(&DAT_20801876)[uVar5 * 2],(&DAT_20801874)[uVar5 * 2],
                        unaff_r5[local_5c[uVar5]]);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 3);
    }
    else {
      switch(local_64 & 0xf) {
      case 4:
      case 5:
      case 7:
        FUN_20129e4c(&uStack_8b,local_64,&DAT_20801864,unaff_r5);
        return;
      }
    }
  }
  return;
}


// ===== FUN_2012a6a4 @ 2012a6a4 (636 bytes)

void FUN_2012a6a4(char *param_1,char *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_58 [12];
  undefined1 local_4c;
  undefined1 auStack_48 [12];
  undefined1 local_3c;
  undefined1 uStack_38;
  undefined1 auStack_37 [7];
  undefined4 local_30;
  undefined1 auStack_2c [8];
  
  local_30 = fb_get_layer_addr(DAT_208085b8);
  iVar8 = 0;
  iVar7 = 0;
  bVar1 = param_1[0x30];
  uVar6 = (uint)bVar1;
  bVar5 = param_1[0x49] & 0xf;
  bVar2 = param_2[0x49];
  uVar3 = (uint)(byte)param_2[0x30];
  FUN_201636cc(&uStack_38,param_1 + 0x31);
  FUN_201636cc(auStack_2c,param_2 + 0x31);
  memcpy(auStack_58,param_1 + 0x36,0xd);
  local_4c = 0;
  memcpy(auStack_48,param_2 + 0x36,0xd);
  local_3c = 0;
  if ((((param_3 != 0) || (uVar6 != uVar3)) ||
      (iVar4 = FUN_2015507c(&uStack_38,auStack_2c,5), iVar4 != 0)) ||
     (iVar4 = FUN_2015507c(auStack_58,auStack_48,0xd), iVar4 != 0 || bVar5 != (bVar2 & 0xf))) {
    fb_copy_rect(local_30,10,0x17e,0x1a2,0x32);
    uVar3 = uVar6 & 0xf;
    if ((bVar1 & 0xf) != 0) {
      if (uVar3 == 1) {
        FUN_20135dd4(local_30,auStack_58,DAT_2080076a,DAT_20800768,DAT_2080076c,&DAT_208015bc);
      }
      else if (uVar3 == 4) {
        FUN_20129e4c(auStack_37,uVar6,&DAT_2080183c);
      }
      else if (uVar3 == 6) {
        FUN_20129e4c(auStack_37,uVar6,&DAT_2080183c,&PTR_DAT_208025b0);
      }
    }
  }
  if (bVar5 != (bVar2 & 0xf)) {
    param_3 = 1;
  }
  if ((bVar5 == 4 || bVar5 == 5) || bVar5 == 7) {
    if ((*param_1 == '0') && (param_1[0x98] == '\a')) {
      iVar8 = 1;
    }
    if ((*param_2 == '0') && (param_2[0x98] == '\a')) {
      iVar7 = 1;
    }
    if (iVar8 == iVar7) goto LAB_2012a868;
    param_3 = 1;
  }
  else {
LAB_2012a868:
    if (param_3 == 0) goto LAB_2012a8d8;
  }
  fb_copy_rect(local_30,DAT_20800692 + -3,DAT_20800778,
               ((*(short *)PTR_DAT_20802548 + DAT_20801880) - DAT_20800778) + 1,
               ((*(short *)(PTR_DAT_20802ff4 + 2) + DAT_2080077a) - DAT_20800692) + 3);
LAB_2012a8d8:
  if ((bVar5 == 4 || bVar5 == 5) || bVar5 == 7) {
    FUN_20129f64(param_1,param_2,param_3);
    return;
  }
  if (bVar5 == 9) {
    FUN_20129cf0(param_1,param_2,param_3);
  }
  return;
}


// ===== FUN_2012a920 @ 2012a920 (204 bytes)

void FUN_2012a920(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_r9;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  iVar3 = 0;
  do {
    if (0x20 < *(byte *)(param_1 + iVar3)) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  uVar2 = 8 - iVar3;
  if ((uVar2 & 1) == 0) {
    param_3 = param_3 + 1 & 0xffff;
  }
  if (iVar3 < 8) {
    unaff_r9 = 0x20801bc4;
  }
  uVar2 = (param_3 - ((uVar2 * 0xc & 0xffff) >> 1)) + ((int)uVar2 / 2) * -2;
  for (; iVar3 < 8; iVar3 = iVar3 + 1) {
    gui_draw_runs(uVar1,param_2,uVar2 & 0xffff,
                  *(undefined4 *)(unaff_r9 + (uint)*(byte *)(param_1 + iVar3) * 4 + -0x80));
    uVar2 = (uint)**(ushort **)(unaff_r9 + (uint)*(byte *)(param_1 + iVar3) * 4 + -0x80) +
            (uVar2 & 0xffff) + 2;
  }
  return;
}


// ===== FUN_2012a9ec @ 2012a9ec (908 bytes)

void FUN_2012a9ec(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  undefined **ppuVar9;
  int iVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  
  uVar3 = fb_get_layer_addr(DAT_208085b8);
  local_34 = *(byte *)(param_1 + 0x99) & 0x3f;
  local_28 = *(byte *)(param_1 + 0x9a) & 0x3f;
  bVar1 = *(byte *)(param_1 + 0x98);
  if ((bVar1 & 0x40) == 0) {
    local_38 = 0xfc00;
  }
  else {
    local_38 = 0xffff;
  }
  local_3c = (uint)(bVar1 >> 7);
  local_2c = bVar1 & 0x20;
  if (param_2 != 0) {
    fb_fill_rect(uVar3,0x821,0x6d,0,800,0x173);
  }
  local_30 = 0x21;
  gui_draw_runs(uVar3,DAT_208019d8,DAT_208019d6,&DAT_2016d740);
  gui_draw_runs(uVar3,DAT_20800532 + DAT_208019d8,DAT_208019d6 + DAT_20800530,&DAT_2016d720);
  if ((local_3c != 0) && (local_34 == 0x21)) {
    FUN_20136290(uVar3,DAT_208019d8,DAT_208019d6,0xe1,0x32,3,local_38);
  }
  uVar5 = 0;
  do {
    fb_fill_rect(uVar3,0x4a69,(&DAT_2016d900)[uVar5 * 2],(&DAT_2016d8fe)[uVar5 * 2],0x316,2);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  uVar5 = 0;
  if (0 < local_30) {
    do {
      iVar10 = param_1 + uVar5 * 10;
      uVar8 = (uint)*(byte *)(iVar10 + 0x9c);
      if ((*(byte *)(iVar10 + 0x9b) & 0x80) == 0) {
        ppuVar9 = &PTR_DAT_208019ec;
      }
      else {
        ppuVar9 = (undefined **)&DAT_20801ad8;
      }
      if ((uVar8 < 0x41) && (ppuVar9[uVar8] != (undefined *)0x0)) {
        psVar6 = &DAT_2080188c + uVar5 * 5;
        gui_draw_runs(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,&DAT_2016d710);
        uVar4 = (uint)(ushort)(&DAT_2080188e)[uVar5 * 5];
        sVar2 = *psVar6;
        uVar7 = (DAT_2080053a + uVar4) * 0x10000 | (uint)(ushort)(DAT_20800538 + sVar2);
        if (uVar8 == 0xf) {
switchD_2012abd4_caseD_0:
          local_48 = 0;
          local_44 = 0;
          local_40 = 0;
          FUN_2016372c(&local_48,iVar10 + 0x9d);
          FUN_2012a920(&local_48,DAT_2080053e + (&DAT_2080188e)[uVar5 * 5],*psVar6 + DAT_2080053c);
        }
        else {
          if (uVar8 < 0x10) {
            switch(uVar8) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 7:
            case 8:
            case 9:
            case 10:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
              goto switchD_2012abd4_caseD_0;
            default:
              goto switchD_2012abd4_caseD_6;
            }
          }
          if (uVar8 == 0x24) goto switchD_2012abd4_caseD_0;
          if (uVar8 < 0x25) {
            if (uVar8 - 0x10 < 6) goto switchD_2012abd4_caseD_0;
switchD_2012abd4_caseD_6:
            uVar7 = (uVar4 + DAT_20800536) * 0x10000 | (uint)(ushort)(DAT_20800534 + sVar2);
          }
          else {
            switch(uVar8) {
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
              gui_draw_runs(uVar3,uVar4 + DAT_20800542 & 0xffff,sVar2 + DAT_20800540,&DAT_2016d730);
              break;
            default:
              goto switchD_2012abd4_caseD_6;
            case 0x3a:
              goto switchD_2012abd4_caseD_0;
            }
          }
        }
        gui_draw_runs(uVar3,uVar7 >> 0x10,uVar7 & 0xffff,ppuVar9[uVar8]);
        if ((local_3c == 0) || (uVar5 != local_34)) {
          if ((uVar5 == local_28) && (local_2c != 0)) {
            FUN_20136290(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,0x6e,0x32,3,0x6e0);
          }
        }
        else {
          FUN_20136290(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,0x6e,0x32,3,local_38);
        }
      }
      else {
        fb_fill_rect(uVar3,0x821,(&DAT_2080188e)[uVar5 * 5],(&DAT_2080188c)[uVar5 * 5],0x6e,0x32);
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < local_30);
  }
  return;
}


// ===== FUN_2012ade0 @ 2012ade0 (680 bytes)

void FUN_2012ade0(int param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  uVar3 = (uint)*(byte *)(param_1 + 0x98);
  iVar6 = *(int *)(&DAT_208029e8 + uVar3 * 4);
  psVar5 = *(short **)(&DAT_20802c34 + uVar3 * 4);
  if (psVar5 != (short *)0x0) {
    iVar1 = uVar3 * 4;
    psVar4 = (short *)(&DAT_208026dc + iVar1);
    fb_fill_rect(local_2c,0x821,*(short *)(&DAT_208026de + iVar1) + 2,*psVar4 + 2,*psVar5 + -4,
                 psVar5[1] + -4);
    gui_draw_runs(local_2c,*(undefined2 *)(&DAT_208026de + iVar1),*psVar4,psVar5);
    FUN_20135aa4(local_2c,*(undefined2 *)(&DAT_208026de + iVar1),*psVar4 + 6,*psVar5 + -0xc,2,0x632c
                );
    FUN_20135aa4(local_2c,*(short *)(&DAT_208026de + iVar1) + psVar5[1] + -2,*psVar4 + 6,
                 *psVar5 + -0xc,2,0x632c);
    if (iVar6 == 0) {
      if (*(short *)(&DAT_208027e0 + uVar3 * 4) != 0) {
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        memcpy(&local_38,*(undefined4 *)(&DAT_20802aec + uVar3 * 4),(&DAT_20802bf0)[uVar3]);
        FUN_20135dd4(local_2c,&local_38,
                     *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208027e2 + uVar3 * 4),
                     *psVar4 + *(short *)(&DAT_208027e0 + uVar3 * 4),0x22,&DAT_208015bc);
      }
    }
    else {
      gui_draw_runs(local_2c,*(short *)(&DAT_208027e2 + uVar3 * 4) +
                             *(short *)(&DAT_208026de + iVar1),
                    *psVar4 + *(short *)(&DAT_208027e0 + uVar3 * 4),iVar6);
    }
    iVar6 = uVar3 * 4;
    psVar7 = (short *)(&DAT_208028e4 + iVar6);
    if (*psVar7 != 0) {
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_38,param_1 + 0x99,9);
      local_30._0_2_ = (ushort)(byte)local_30;
      FUN_201354ec(&local_38);
      if (*(short *)(&DAT_208027e0 + uVar3 * 4) == 0) {
        FUN_20135ff0(local_2c,&local_38,
                     *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208028e6 + iVar6),
                     *psVar4 + *psVar7,0x22,&DAT_208015bc);
        return;
      }
      sVar2 = FUN_20155122(&local_38);
      FUN_20135dd4(local_2c,&local_38,
                   *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208028e6 + iVar6),
                   (*psVar4 + *psVar5 + sVar2 * -0x22) - *psVar7,0x22,&DAT_208015bc);
    }
  }
  return;
}


// ===== FUN_2012b0f0 @ 2012b0f0 (204 bytes)

void FUN_2012b0f0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  if (4 < param_1) {
    param_1 = 4;
  }
  uVar3 = param_2 & 0xffff;
  iVar1 = param_1 * 4;
  param_2 = param_2 >> 0x10;
  FUN_2013573c(uVar2,0x821,param_2,uVar3,*(short *)(&DAT_2016e620 + iVar1),
               *(undefined2 *)(&DAT_2016e622 + iVar1),2);
  fb_fill_rect(uVar2,0x4a69,param_2 + 2 & 0xffff,uVar3 + 2 & 0xffff,
               *(short *)(&DAT_2016e620 + iVar1) + -4,*(short *)(&DAT_2016e622 + iVar1) + -4);
  fb_fill_rect(uVar2,0x3186,param_2 + 7 & 0xffff,uVar3 + 7 & 0xffff,0x1d5,0x17);
  return;
}


// ===== FUN_2012c1b4 @ 2012c1b4 (4200 bytes)

void FUN_2012c1b4(int param_1,int param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  ushort uVar9;
  uint uVar10;
  undefined4 unaff_r4;
  int iVar11;
  short *psVar12;
  undefined4 unaff_r5;
  undefined **ppuVar13;
  undefined4 unaff_r6;
  uint uVar14;
  uint uVar15;
  undefined4 unaff_r7;
  uint uVar16;
  undefined4 unaff_r8;
  undefined4 uVar17;
  undefined4 unaff_r9;
  short *psVar18;
  undefined4 unaff_r10;
  undefined4 unaff_lr;
  undefined *in_stack_ffffffc8;
  byte bVar19;
  
  bVar19 = *(byte *)(param_1 + 0x98);
  bVar1 = *(byte *)(param_1 + 0x99);
  uVar14 = (uint)bVar1;
  uVar16 = *(byte *)(param_1 + 0x9a) & 1;
  fb_get_layer_addr(DAT_208085bc);
  if (bVar19 != 7) {
    if (bVar19 < 8) {
      switch(bVar19) {
      case 0:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        FUN_2012b0f0(0,0x6d0000);
        gui_draw_runs(uVar5,0x75,0xc5,&DAT_2016dd04,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                      unaff_r9,unaff_r10);
        if (5 < uVar14) {
          uVar14 = 5;
        }
        uVar16 = 0;
        do {
          iVar11 = (&DAT_2016dd14)[uVar16 * 2];
          if (iVar11 != 0) {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              iVar11 = (&DAT_2016dd18)[uVar16 * 2];
            }
            else {
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016dd46)[uVar16 * 5],(&DAT_2016dd44)[uVar16 * 5],puVar7,
                          unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10);
            gui_draw_runs(uVar5,(&DAT_2016dd46)[uVar16 * 5] + DAT_2080065a,
                          (&DAT_2016dd44)[uVar16 * 5] + DAT_20800658,iVar11);
          }
          uVar16 = uVar16 + 1 & 0xff;
        } while (uVar16 < 6);
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        bVar4 = bVar19 - 1;
        puVar7 = (undefined *)0x0;
        bVar1 = (&DAT_2016d290)[bVar4];
        if ((bVar19 == 1 || bVar19 == 2) || (bVar19 == 3 || bVar19 == 4)) {
          in_stack_ffffffc8 = (&PTR_DAT_208026a8)[bVar4];
          puVar7 = (&PTR_PTR_208026b8)[bVar4];
        }
        uVar15 = 0;
        if (bVar1 != 0) {
          do {
            if (uVar15 == uVar14) {
              if (uVar16 == 0) {
                puVar8 = &UNK_2016e12c;
                uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc + 4);
                goto LAB_2012c03c;
              }
              puVar8 = &DAT_2016e11c;
              psVar12 = &DAT_208006c0;
              uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc + 8);
              sVar2 = DAT_208004c4;
            }
            else {
              puVar8 = &UNK_2016e13c;
              uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc);
LAB_2012c03c:
              psVar12 = (short *)0x208006bc;
              sVar2 = DAT_208004c2;
            }
            psVar18 = (short *)(in_stack_ffffffc8 + uVar15 * 10);
            fb_copy_rect(uVar5,DAT_208004c4,*psVar18,0x6b,0x68);
            gui_draw_runs(uVar5,sVar2,*psVar18,puVar8);
            gui_draw_runs(uVar5,psVar12[1] + sVar2,*psVar18 + *psVar12,uVar17);
            uVar15 = uVar15 + 1 & 0xff;
          } while (uVar15 < bVar1);
        }
        return;
      case 5:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        uVar15 = (uint)*(byte *)(param_1 + 0x9b);
        FUN_2012b0f0(2,0x5b009e);
        gui_draw_runs(uVar5,DAT_20800782,DAT_20800780,&DAT_2016e724);
        uVar16 = 0;
        do {
          if (uVar16 == uVar14) {
            puVar7 = &DAT_2016e5e0;
            uVar17 = (&DAT_2016e7e4)[uVar16 * 2];
          }
          else {
            uVar17 = *(undefined4 *)(&UNK_2016e7e0 + uVar16 * 8);
            puVar7 = &DAT_2016e5f0;
          }
          while( true ) {
            gui_draw_runs(uVar5,(&DAT_2016e736)[uVar16 * 5],(&DAT_2016e734)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016e736)[uVar16 * 5] + DAT_2080077e,
                          (&DAT_2016e734)[uVar16 * 5] + DAT_2080077c,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
            if (0xf < uVar16) {
              FUN_20136290(uVar5,(&DAT_2016e736)[(uVar15 & 0xff) * 5],
                           (&DAT_2016e734)[(uVar15 & 0xff) * 5],0x6e,0x32,3,0xf980);
              return;
            }
            if (uVar16 != 0xf) break;
            if ((*(byte *)(param_1 + 5) & 0x40) == 0) {
              puVar7 = &DAT_20802fe4;
              uVar17 = 0x208084bc;
            }
            else {
              puVar7 = &DAT_2016e5e0;
              uVar17 = 0x20807b38;
            }
          }
        } while( true );
      case 6:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        FUN_2012b0f0(1,0xa1009e);
        gui_draw_runs(uVar5,0xa9,0x163,&DAT_2016e644,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                      unaff_r9,unaff_r10);
        uVar16 = 0;
        do {
          if (uVar16 == uVar14) {
            puVar7 = &DAT_2016e5e0;
            puVar8 = (undefined *)(&DAT_2016e658)[uVar16 * 2];
          }
          else {
            puVar8 = (&PTR_DAT_2016e654)[uVar16 * 2];
            puVar7 = &DAT_2016e5f0;
          }
          gui_draw_runs(uVar5,(&DAT_2016e6a6)[uVar16 * 5],(&DAT_2016e6a4)[uVar16 * 5],puVar7,
                        unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10);
          gui_draw_runs(uVar5,(&DAT_2016e6a6)[uVar16 * 5] + DAT_20800766,
                        (&DAT_2016e6a4)[uVar16 * 5] + DAT_20800764,puVar8);
          uVar16 = uVar16 + 1 & 0xff;
        } while (uVar16 < 10);
        return;
      }
    }
    else {
      if (bVar19 == 0xb) {
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        uVar16 = *(byte *)(param_1 + 0x99) & 0xffffff0f;
        uVar14 = *(byte *)(param_2 + 0x99) & 0xffffff0f;
        bVar19 = *(byte *)(param_1 + 0x9b);
        uVar15 = (uint)*(byte *)(param_2 + 0x9b);
        bVar3 = false;
        if (10 < (byte)uVar16) {
          uVar16 = 10;
        }
        if (0xb < bVar19) {
          bVar19 = 0xb;
        }
        uVar10 = (uint)bVar19;
        if ((param_3 != 0) || (*(char *)(param_1 + 0x98) != *(char *)(param_2 + 0x98))) {
          bVar3 = true;
          FUN_2013573c(uVar5,0x821,0xa1,0x3d,0x2a6,0x128,2);
          fb_fill_rect(uVar5,0x821,0xa1,0x3d,0x2a6,0x128);
          FUN_201359bc(uVar5,0xa1,0x3d,&DAT_2016e600);
          uVar9 = 8;
          do {
            FUN_201359bc(uVar5,0xa1,uVar9 + 0x3d,&DAT_2016e610);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x29e);
          gui_draw_runs(uVar5,DAT_20800762 + 0xa1,DAT_20800760 + 0x3d,&DAT_2016e520);
        }
        if (((uVar14 & 0xff) != (uVar16 & 0xff)) || ((uVar15 & 0xff) != (uVar10 & 0xff) || bVar3)) {
          uVar14 = 0;
          do {
            puVar6 = (undefined2 *)(&DAT_20802f60)[uVar14];
            FUN_20135534(uVar5,(&DAT_2016e532)[uVar14 * 5],(&DAT_2016e530)[uVar14 * 5],
                         *(undefined4 *)(puVar6 + 6),*puVar6,puVar6[1]);
            gui_draw_runs(uVar5,(&DAT_2016e5b4)[uVar14 * 2],(&DAT_2016e5b2)[uVar14 * 2],
                          (&PTR_DAT_20802fb8)[uVar14]);
            uVar14 = uVar14 + 1 & 0xff;
          } while (uVar14 < 0xb);
          fb_fill_rect(uVar5,0x821,(&DAT_2016e532)[(uVar16 & 0xff) * 5] + DAT_2080075e,
                       (&DAT_2016e530)[(uVar16 & 0xff) * 5] + DAT_2080075c,
                       *(undefined2 *)(&PTR_DAT_20802f8c)[uVar16 & 0xff],
                       *(undefined2 *)((&PTR_DAT_20802f8c)[uVar16 & 0xff] + 2));
          gui_draw_runs(uVar5,(&DAT_2016e532)[(uVar16 & 0xff) * 5] + DAT_2080075e,
                        (&DAT_2016e530)[(uVar16 & 0xff) * 5] + DAT_2080075c,
                        (&PTR_DAT_20802f8c)[uVar16 & 0xff]);
          FUN_2013573c(uVar5,0x3186,0x186,0x274,0x68,0x3c,2);
          fb_fill_rect(uVar5,0x821,0x188,0x276,100,0x38);
          gui_draw_runs(uVar5,0x186,0x274,&DAT_2016dc38);
          gui_draw_runs(uVar5,0x19c,0x27c,&DAT_2016db88);
          if ((byte)uVar10 < 0xb) {
            gui_draw_runs(uVar5,(&DAT_2016e532)[(uVar10 & 0xff) * 5],
                          (&DAT_2016e530)[(uVar10 & 0xff) * 5],&DAT_2016e510);
            return;
          }
          FUN_20136398(uVar5,(&DAT_2016e532)[(uVar10 & 0xff) * 5],
                       (&DAT_2016e530)[(uVar10 & 0xff) * 5],0x68,0x3c,3);
        }
        return;
      }
      if (bVar19 < 0xc) {
        if (bVar19 == 8) goto LAB_2012bb34;
        if (bVar19 == 9) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          FUN_2013573c(uVar5,0x821,0xa1,0xda,0x16c,0x65,2,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                       unaff_r8,unaff_r9,unaff_r10);
          fb_fill_rect(uVar5,0x4a69,0xa3,0xdc,0x168,0x61);
          fb_fill_rect(uVar5,0x3186,DAT_208004fe + 0xa1,DAT_208004fc + 0xda,DAT_20800500,
                       DAT_20800502);
          gui_draw_runs(uVar5,DAT_208004fa + 0xa1,DAT_208004f8 + 0xda,&DAT_2016d330);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              puVar8 = (undefined *)(&DAT_2016d344)[uVar16 * 2];
            }
            else {
              puVar8 = (&PTR_DAT_2016d340)[uVar16 * 2];
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016d35a)[uVar16 * 5],(&DAT_2016d358)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016d35a)[uVar16 * 5] + DAT_20800506,
                          (&DAT_2016d358)[uVar16 * 5] + DAT_20800504,puVar8);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 3);
          return;
        }
        if (bVar19 == 10) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          FUN_2013573c(uVar5,0x821,0xa1,0x9e,0x1e4,0xf1,2);
          gui_draw_runs(uVar5,0xa1,0x9e,&DAT_2016df7c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0xa6,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x6d);
          gui_draw_runs(uVar5,0xa1,0x112,&DAT_2016df6c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0x11e,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x6d);
          gui_draw_runs(uVar5,0xa1,0x18a,&DAT_2016df6c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0x196,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0xe5);
          gui_draw_runs(uVar5,0xa1,0x27a,&DAT_2016df8c);
          gui_draw_runs(uVar5,DAT_208006a6 + 0xa1,DAT_208006a4 + 0x9e,&DAT_2016df4c);
          gui_draw_runs(uVar5,DAT_208006aa + 0xa1,DAT_208006a8 + 0x9e,&DAT_2016df3c);
          gui_draw_runs(uVar5,DAT_208006ae + 0xa1,DAT_208006ac + 0x9e,&DAT_2016df2c);
          uVar16 = (uint)(bVar1 >> 6);
          uVar15 = (uVar14 & 0x3f) >> 4;
          if (2 < uVar16) {
            uVar16 = 2;
          }
          uVar14 = uVar14 & 0xf;
          if (2 < uVar15) {
            uVar15 = 2;
          }
          uVar10 = 0;
          if (5 < uVar14) {
            uVar14 = 5;
          }
          do {
            if (uVar10 == uVar16) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = (&DAT_2016dfa0)[uVar10 * 2];
            }
            else {
              uVar17 = (&DAT_2016df9c)[uVar10 * 2];
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016dffe)[uVar10 * 5],(&DAT_2016dffc)[uVar10 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016dffe)[uVar10 * 5] + DAT_20800506,
                          (&DAT_2016dffc)[uVar10 * 5] + DAT_20800504,uVar17);
            if (uVar10 == uVar15) {
              puVar7 = (&PTR_DAT_2016dfb8)[uVar10 * 2];
              puVar8 = &DAT_2016e5e0;
            }
            else {
              puVar7 = (undefined *)(&DAT_2016dfb4)[uVar10 * 2];
              puVar8 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016e01c)[uVar10 * 5],(&DAT_2016e01a)[uVar10 * 5],puVar8);
            gui_draw_runs(uVar5,(&DAT_2016e01c)[uVar10 * 5] + DAT_20800506,
                          (&DAT_2016e01a)[uVar10 * 5] + DAT_20800504,puVar7);
            uVar10 = uVar10 + 1 & 0xff;
          } while (uVar10 < 3);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = *(undefined4 *)(&UNK_2016dfd0 + uVar16 * 8);
            }
            else {
              puVar7 = &DAT_2016e5f0;
              uVar17 = (&DAT_2016dfcc)[uVar16 * 2];
            }
            gui_draw_runs(uVar5,(&DAT_2016e03a)[uVar16 * 5],(&DAT_2016e038)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016e03a)[uVar16 * 5] + DAT_20800506,
                          (&DAT_2016e038)[uVar16 * 5] + DAT_20800504,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 6);
          return;
        }
      }
      else {
        if (bVar19 == 0xc) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          uVar15 = (uint)*(byte *)(param_1 + 0x9b);
          FUN_2012b0f0(1,0xa1009e);
          gui_draw_runs(uVar5,DAT_2080078a,DAT_20800788,&DAT_2016ea28);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = (&DAT_2016eac0)[uVar16 * 2];
            }
            else {
              uVar17 = *(undefined4 *)(&UNK_2016eabc + uVar16 * 8);
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016ea3a)[uVar16 * 5],(&DAT_2016ea38)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016ea3a)[uVar16 * 5] + DAT_20800786,
                          (&DAT_2016ea38)[uVar16 * 5] + DAT_20800784,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 0xc);
          FUN_20136290(uVar5,(&DAT_2016ea3a)[(uVar15 & 0xff) * 5],
                       (&DAT_2016ea38)[(uVar15 & 0xff) * 5],0x6e,0x32,3,0xf980);
          return;
        }
        if (bVar19 == 0xd) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          FUN_2012b0f0(0,0xa1009e);
          gui_draw_runs(uVar5,0xa9,0x163,&DAT_2016ed28,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                        unaff_r9,unaff_r10);
          if ((4 < uVar14) && (uVar14 != 5)) {
            uVar14 = 4;
          }
          uVar16 = 0;
          do {
            iVar11 = (&DAT_2016ed38)[uVar16 * 2];
            if (iVar11 != 0) {
              if (uVar16 == uVar14) {
                iVar11 = *(int *)(&UNK_2016ed3c + uVar16 * 8);
              }
              gui_draw_runs(uVar5,(&DAT_2016ed6a)[uVar16 * 5],(&DAT_2016ed68)[uVar16 * 5]);
              gui_draw_runs(uVar5,(&DAT_2016ed6a)[uVar16 * 5] + DAT_2080065a,
                            (&DAT_2016ed68)[uVar16 * 5] + DAT_20800658,iVar11);
            }
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 6);
          return;
        }
      }
    }
    return;
  }
LAB_2012bb34:
  uVar5 = fb_get_layer_addr(DAT_208085bc);
  if (bVar19 == 7) {
    ppuVar13 = &PTR_DAT_20802208;
  }
  else {
    ppuVar13 = &PTR_DAT_20802244;
  }
  fb_fill_rect(uVar5,0x4a69,0xb8,0x169,0x1b7,0x128,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
               unaff_r9,unaff_r10,unaff_lr);
  iVar11 = 0;
  do {
    psVar12 = &DAT_2016da0c + iVar11 * 5;
    fb_fill_rect(uVar5,0x821,(&DAT_2016da0e)[iVar11 * 5] + 1,*psVar12 + 1,
                 (&DAT_2016da10)[iVar11 * 5] + -2,(&DAT_2016da12)[iVar11 * 5] + -2,unaff_r4,unaff_r5
                 ,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10,unaff_lr);
    gui_draw_runs(uVar5,(&DAT_2016da0e)[iVar11 * 5],*psVar12,(&PTR_DAT_208021cc)[iVar11]);
    gui_draw_runs(uVar5,(&DAT_2016daae)[iVar11 * 2] + (&DAT_2016da0e)[iVar11 * 5],
                  *psVar12 + (&DAT_2016daac)[iVar11 * 2],ppuVar13[iVar11]);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0xf);
  return;
}


// ===== FUN_2012c2d8 @ 2012c2d8 (328 bytes)

undefined4 FUN_2012c2d8(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *param_1;
  if ((bVar1 != *param_2) || (bVar1 == 0x40)) {
    return 0xffffffff;
  }
  if (bVar1 < 0x41) {
    if (bVar1 == 0x37) {
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x1a7);
    }
    else if (bVar1 < 0x38) {
      if (bVar1 == 0x30) {
        cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,7);
        if (cVar2 != '\0') {
          return 1;
        }
        if (param_1[0x98] == 5) {
          if ((param_1[5] & 0x40) != (param_2[5] & 0x40)) {
            return 1;
          }
          return 0;
        }
        return 0;
      }
      if (bVar1 != 0x31) {
        return 0xffffffff;
      }
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,10);
    }
    else {
      if (bVar1 != 0x39) {
        return 0xffffffff;
      }
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x50);
    }
  }
  else if (bVar1 == 0x41) {
    cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0xad);
  }
  else {
    if (bVar1 == 0x50 || bVar1 == 0x62) {
      return 0xffffffff;
    }
    if (bVar1 != 0x70) {
      return 0xffffffff;
    }
    cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x4a);
  }
  if (cVar2 != '\0') {
    return 1;
  }
  return 0;
}


// ===== FUN_2012c4a0 @ 2012c4a0 (248 bytes)

void FUN_2012c4a0(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_2080048e != '\0' && DAT_2080048e != '\x03') {
    return;
  }
  if (*(byte *)(param_1 + 0x24) >> 4 == 0) {
    iVar2 = FUN_201058c0();
    if (iVar2 == -1) {
      if ((((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
          (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) && (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
        FUN_20124744(0xffffffff);
      }
      FUN_201058cc();
    }
    if (DAT_20800490 == '\0' && DAT_2080048f == '\0') {
      return;
    }
  }
  iVar2 = FUN_20105790();
  if ((((iVar2 == 0) && (iVar2 = FUN_201058c0(), iVar2 == 0)) &&
      ((bVar1 = *(byte *)(param_1 + 0x2d), bVar1 < 2 ||
       ((bVar1 == 4 || bVar1 == 5 || (bVar1 == 6 || bVar1 == 7)))))) &&
     (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
    FUN_20124744(0xffffffff);
    return;
  }
  DAT_2080048e = 3;
  FUN_2012910c(param_1);
  return;
}


// ===== FUN_2012c6c4 @ 2012c6c4 (108 bytes)

void FUN_2012c6c4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if ((param_3 == 0) && ((*(byte *)(param_1 + 0x12) & 0xf0) == (*(byte *)(param_2 + 0x12) & 0xf0)))
  {
    return;
  }
  uVar1 = (uint)(*(byte *)(param_1 + 0x12) >> 4);
  if (5 < uVar1) {
    uVar1 = 5;
  }
  thunk_FUN_2015d1c4(uVar1);
  if (DAT_20800480 != '\0') {
    return;
  }
  DAT_208085b0 = (ushort)(byte)(&UNK_203a70a8)[uVar1];
  return;
}


// ===== FUN_2012c71c @ 2012c71c (912 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2012c71c(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar3;
  uint uVar4;
  uint unaff_r4;
  uint unaff_r5;
  int iVar5;
  int iVar6;
  uint in_stack_ffffffd0;
  undefined2 uVar2;
  
  iVar3 = fb_get_layer_addr(0);
  if (DAT_20800480 == '\0') {
    iVar5 = FUN_20133640();
  }
  else {
    iVar5 = 0;
  }
  if (param_2 == 0) {
    in_stack_ffffffd0 = (uint)DAT_208004d0;
    unaff_r5 = _DAT_20800728;
    uVar1 = DAT_20800736;
    uVar2 = DAT_20800734;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        unaff_r5 = ((uint)DAT_20800726 + (uint)DAT_2080073a) * 0x10000 |
                   (uint)DAT_20800724 + (uint)DAT_20800738 & 0xffff;
        unaff_r4 = _DAT_20800730;
      }
      goto LAB_2012c814;
    }
    unaff_r5 = ((uint)DAT_20800722 + (uint)DAT_2080073a) * 0x10000 |
               (uint)DAT_20800720 + (uint)DAT_20800738 & 0xffff;
    uVar1 = DAT_2080072e;
    uVar2 = DAT_2080072c;
  }
  unaff_r4 = CONCAT22(uVar1,uVar2);
LAB_2012c814:
  iVar6 = iVar3;
  if (iVar5 != 0) {
    iVar6 = iVar5 + (unaff_r5 >> 0x10) * -0x640;
  }
  if (param_2 == 0) {
    if (in_stack_ffffffd0 == 3) {
      fb_fill_rect(iVar6,0x2124,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,
                   unaff_r4 >> 0x10);
      FUN_20132f44(0);
      uVar4 = *(byte *)(param_1 + 3) & 3;
      if (2 < uVar4) {
        uVar4 = 2;
      }
      gui_draw_runs(iVar6,DAT_2080073e,DAT_2080073c,*(undefined4 *)(&DAT_20808524 + uVar4 * 4));
    }
  }
  else if (param_2 == 2) {
    fb_copy_rect(iVar6,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,unaff_r4 >> 0x10);
    FUN_20132f44(0);
    gui_draw_runs(iVar6,DAT_20800722 + DAT_2080073a,DAT_20800720 + DAT_20800738,&DAT_2016e380);
    uVar4 = *(byte *)(param_1 + 0x71) & 7;
    if (5 < uVar4) {
      uVar4 = 5;
    }
    gui_draw_runs(iVar6,DAT_2080074a + DAT_20800722,DAT_20800720 + DAT_20800748,
                  (&PTR_DAT_20802da0)[uVar4]);
    gui_draw_runs(iVar6,DAT_2080074e + DAT_20800722,DAT_20800720 + DAT_2080074c,&DAT_2016e390);
  }
  else if (param_2 == 3) {
    fb_copy_rect(iVar6,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,unaff_r4 >> 0x10);
    FUN_20132f44(0);
    gui_draw_runs(iVar6,DAT_20800726 + DAT_2080073a,DAT_20800724 + DAT_20800738,&DAT_2016e360);
    gui_draw_runs(iVar6,DAT_20800742 + DAT_20800726,DAT_20800724 + DAT_20800740,&DAT_2016e370);
    uVar4 = (*(byte *)(param_1 + 0x71) & 0x7f) >> 5;
    if (2 < uVar4) {
      uVar4 = 2;
    }
    gui_draw_runs(iVar6,DAT_20800746 + DAT_20800726,DAT_20800724 + DAT_20800744,
                  *(undefined4 *)(&DAT_20802d94 + uVar4 * 4));
  }
  if (iVar5 != 0) {
    iVar6 = 0;
    iVar5 = iVar5 + (unaff_r5 & 0xffff) * 2;
    iVar3 = iVar3 + ((unaff_r5 & 0xffff) + (unaff_r5 >> 0x10) * 800) * 2;
    if (unaff_r4 >> 0x10 != 0) {
      do {
        memcpy(iVar3,iVar5,(unaff_r4 & 0xffff) << 1);
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x640;
        iVar3 = iVar3 + 0x640;
      } while (iVar6 < (int)(unaff_r4 >> 0x10));
    }
  }
  return;
}


// ===== FUN_2012caac @ 2012caac (180 bytes)

void FUN_2012caac(int param_1,int param_2,int param_3)

{
  if (((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
     (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) {
    if ((((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7)) &&
        ((byte)(*(byte *)(param_1 + 3) * '@') == (byte)(*(byte *)(param_2 + 3) * '@'))) &&
       (*(char *)(param_1 + 0x71) == *(char *)(param_2 + 0x71))) {
      return;
    }
  }
  if (DAT_208004d0 == '\x03') {
    FUN_2012c71c(param_1,0);
    return;
  }
  if (DAT_20800482 != '\x01') {
    return;
  }
  FUN_2012c71c(param_1,2);
  FUN_2012c71c(param_1,3);
  return;
}


// ===== FUN_2012cb60 @ 2012cb60 (168 bytes)

void FUN_2012cb60(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = 0;
    if (param_4 != 0) {
      iVar1 = iVar2 + -8;
    }
    if (iVar1 < 0 == (param_4 != 0 && SBORROW4(iVar2,8))) break;
    if (iVar2 == 6 || iVar2 == 3) {
      uVar3 = param_3 + 4 & 0xffff;
      gui_draw_runs(param_1,param_2,uVar3,DAT_20800924);
      param_3 = uVar3 - 8 & 0xffff;
    }
    gui_draw_runs(param_1,param_2,param_3,(&PTR_DAT_2080092c)[param_4 % 10]);
    FUN_20132f44(0);
    iVar2 = iVar2 + 1;
    param_3 = param_3 - 8 & 0xffff;
    param_4 = param_4 / 10;
  }
  return;
}


// ===== FUN_2012cf30 @ 2012cf30 (900 bytes)

void FUN_2012cf30(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  int iVar13;
  int local_40;
  byte local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if ((((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
      (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) &&
     ((((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7) &&
       (*(char *)(param_1 + 0x11) == *(char *)(param_2 + 0x11))) &&
      (iVar8 = FUN_2015507c(param_1 + 0x75,param_2 + 0x75,0x10), iVar8 == 0)))) {
    return;
  }
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar9 = false;
  }
  else {
    if (DAT_20800482 != '\x01') {
      return;
    }
    if (1 < DAT_208004d0) {
      return;
    }
    bVar9 = true;
  }
  local_30 = fb_get_layer_addr(0);
  if (DAT_20800480 == '\0') {
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  cVar1 = DAT_208004d1;
  if (bVar9) {
    if (!bVar9) {
      return;
    }
    psVar11 = &DAT_20800754;
  }
  else {
    psVar11 = (short *)0x20800750;
  }
  uVar12 = *(byte *)(param_1 + 0x11) & 0x1f;
  uVar3 = (uint)(ushort)psVar11[1];
  if (9 < uVar12) {
    uVar12 = 9;
  }
  local_34 = 800;
  local_40 = local_30;
  if (iVar8 != 0) {
    local_40 = iVar8 + uVar3 * -0x640;
  }
  fb_copy_rect(local_40,uVar3,0,800,9);
  FUN_20132f44(0);
  if (cVar1 == '\0') {
    local_3b = *(undefined1 *)(param_1 + 0x7e);
    local_3a = *(undefined1 *)(param_1 + 0x7f);
    local_3c = *(byte *)(param_1 + 0x7d) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x80);
    uVar6 = FUN_20135498(&local_3c);
    FUN_2012cb60(local_40,psVar11[1],*psVar11 + DAT_20800758,uVar6);
    iVar5 = 0;
    local_2c = uVar12 * 0x10 + 0x20802dd0;
    iVar4 = uVar12 * 0x18 + 0x20802e70;
    do {
      uVar12 = 0;
      sVar2 = *(short *)(local_2c + iVar5 * 4) + *psVar11;
      local_38 = (uint)(ushort)psVar11[1];
      iVar13 = iVar4 + iVar5 * 6;
      iVar10 = FUN_20155122(iVar13);
      if (iVar10 != 0) {
        do {
          gui_draw_runs(local_40,local_38,sVar2,
                        *(undefined4 *)(&DAT_2080086c + (uint)*(byte *)(iVar13 + uVar12) * 4));
          sVar2 = sVar2 + 8;
          uVar12 = uVar12 + 1;
          uVar7 = FUN_20155122(iVar13);
        } while (uVar12 < uVar7);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  else {
    local_3b = *(undefined1 *)(param_1 + 0x82);
    local_3a = *(undefined1 *)(param_1 + 0x83);
    local_3c = *(byte *)(param_1 + 0x81) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x84);
    iVar4 = FUN_20135498(&local_3c);
    iVar5 = FUN_20156260((*(int *)(&UNK_2016d6e8 + uVar12 * 4) + iVar4) - iVar4,5);
    iVar10 = 0;
    do {
      FUN_2012cb60(local_40,psVar11[1],*psVar11 + (&DAT_20802db8)[iVar10 * 2],iVar5 * iVar10 + iVar4
                  );
      iVar10 = iVar10 + 1;
    } while (iVar10 < 6);
  }
  if (iVar8 != 0) {
    iVar5 = 0;
    iVar10 = local_30 + uVar3 * 0x640;
    iVar4 = local_34 << 1;
    do {
      memcpy(iVar10,iVar8,iVar4);
      iVar5 = iVar5 + 1;
      iVar10 = iVar10 + 0x640;
      iVar8 = iVar8 + 0x640;
    } while (iVar5 < 9);
  }
  return;
}


// ===== FUN_2012d000 @ 2012d000 (412 bytes)

void FUN_2012d000(int param_1,short param_2,short param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  short *psVar3;
  ushort uVar4;
  
  uVar1 = fb_get_layer_addr(0);
  uVar2 = 0;
  FUN_20132f44(0);
  if (param_1 == 0) {
    if (((param_4 != 0) && (uVar2 = (uint)(param_4 == 1), param_4 != 1)) && (param_4 == 2)) {
      uVar2 = 2;
    }
  }
  else if (param_1 == 1) {
    uVar2 = 3;
  }
  else if (param_1 == 2) {
    uVar2 = 4;
  }
  else if (param_1 == 3) {
    uVar2 = 5;
  }
  uVar4 = 0;
  psVar3 = (short *)(&DAT_2016e420 + uVar2 * 0x14 + param_5 * 0x78);
  if (psVar3[3] != 0) {
    do {
      FUN_20135ad8(uVar1,psVar3[1] + param_2,psVar3[4] * uVar4 + *psVar3 + param_3,psVar3[2],1,
                   0x3186);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[3]);
  }
  uVar4 = 0;
  if (psVar3[8] != 0) {
    do {
      FUN_20135aa4(uVar1,psVar3[9] * uVar4 + psVar3[6] + param_2,psVar3[5] + param_3,psVar3[7],1,
                   0x632c);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[8]);
  }
  if (param_1 == 3) {
    return;
  }
  FUN_20135aa4(uVar1,psVar3[9] * uVar4 + psVar3[6] + param_2,psVar3[5] + param_3,psVar3[7],1,0xffff)
  ;
  FUN_20132f44(0);
  return;
}


// ===== FUN_2012d19c @ 2012d19c (380 bytes)

void FUN_2012d19c(uint param_1)

{
  byte *pbVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  ushort uVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  uVar3 = fb_get_layer_addr(0);
  FUN_20132f44(0);
  if (param_1 < 3) {
    FUN_20135aa4(uVar3,*(undefined2 *)(&DAT_2016e342 + param_1 * 4),
                 *(undefined2 *)(&DAT_2016e340 + param_1 * 4),
                 *(undefined2 *)(&DAT_2016d2a6 + param_1 * 2),1,0xffff);
    uVar8 = 0;
    if ((&DAT_2016d294)[param_1] != '\0') {
      do {
        FUN_20135ad8(uVar3,*(undefined2 *)(&DAT_2016e352 + param_1 * 4),
                     *(short *)(&DAT_2016d2ae + param_1 * 2) * uVar8 +
                     *(short *)(&DAT_2016e350 + param_1 * 4),2,1,0xffff);
        uVar8 = uVar8 + 1;
      } while (uVar8 < (byte)(&DAT_2016d294)[param_1]);
    }
    if (param_1 == 2) {
      uVar10 = 0;
      do {
        uVar7 = 0;
        sVar6 = DAT_208004f4 + (&DAT_2080084c)[uVar10 * 2];
        sVar2 = (&DAT_2080084e)[uVar10 * 2] + DAT_208004f6;
        puVar9 = &DAT_20800860 + uVar10 * 6;
        iVar4 = FUN_20155122(puVar9);
        if (iVar4 != 0) {
          do {
            gui_draw_runs(uVar3,sVar2,sVar6,
                          *(undefined4 *)(&DAT_2080086c + (uint)(byte)puVar9[uVar7] * 4));
            pbVar1 = puVar9 + uVar7;
            uVar7 = uVar7 + 1;
            sVar6 = **(short **)(&DAT_2080086c + (uint)*pbVar1 * 4) + sVar6 + 1;
            uVar5 = FUN_20155122(puVar9);
          } while (uVar7 < uVar5);
        }
        uVar10 = uVar10 + 1 & 0xffff;
      } while (uVar10 < 5);
    }
  }
  return;
}


// ===== FUN_2012d318 @ 2012d318 (132 bytes)

undefined4 FUN_2012d318(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 100;
  if (DAT_208004d0 == '\x01') {
    if (DAT_20800482 == '\0') {
      if (DAT_208004d2 == '\0') {
        if (param_1 != 0) {
          return 0xd2;
        }
      }
      else {
        if (DAT_208004d2 != '\x01') {
          if (DAT_208004d2 == '\x02') {
            uVar1 = 0x3c;
          }
          return uVar1;
        }
        if (param_1 == 0) {
          return 100;
        }
      }
      return 0x8c;
    }
    if (DAT_20800482 == '\x01') {
      if (param_1 == 0) {
        uVar1 = 0x28;
      }
      else {
        uVar1 = 0x50;
      }
    }
  }
  return uVar1;
}


// ===== FUN_2012d3b8 @ 2012d3b8 (40 bytes)

undefined4 FUN_2012d3b8(undefined4 param_1)

{
  switch(param_1) {
  case 3:
  case 6:
  case 9:
    return 0;
  default:
    return 1;
  case 5:
  case 8:
  case 0xb:
    return 2;
  }
}


// ===== FUN_2012d404 @ 2012d404 (36 bytes)

undefined4 FUN_2012d404(undefined4 param_1)

{
  switch(param_1) {
  default:
    return 0;
  case 1:
  case 6:
  case 7:
  case 8:
    return 1;
  case 2:
  case 9:
  case 10:
  case 0xb:
    return 2;
  }
}


// ===== FUN_2012d458 @ 2012d458 (28 bytes)

undefined4 FUN_2012d458(undefined4 param_1)

{
  switch(param_1) {
  default:
    return 0;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    return 1;
  }
}


// ===== FUN_2012d4a4 @ 2012d4a4 (164 bytes)

void FUN_2012d4a4(int param_1)

{
  if ((*(char *)(param_1 + 1) == '\0') || (*(char *)(param_1 + 1) != '\x01')) {
    DAT_20800482 = 0;
    DAT_208004d0 = FUN_2012d458(*(undefined1 *)(param_1 + 2));
    DAT_208004d1 = FUN_2012d404(*(undefined1 *)(param_1 + 2));
    DAT_208004d2 = FUN_2012d3b8(*(undefined1 *)(param_1 + 2));
  }
  else {
    DAT_20800482 = 1;
    DAT_208004d0 = FUN_2012d458(*(undefined1 *)(param_1 + 2));
    DAT_208004d1 = FUN_2012d404(*(undefined1 *)(param_1 + 2));
    DAT_208004d2 = 1;
  }
  if ((*(byte *)(param_1 + 3) & 4) != 0) {
    DAT_208004d0 = 3;
  }
  return;
}


// ===== FUN_2012d52c @ 2012d52c (864 bytes)

void FUN_2012d52c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  undefined *local_2c;
  
  uVar2 = fb_get_layer_addr(0);
  uVar3 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = *(byte *)(param_1 + 6) & 0x80;
  iVar6 = -((int)((uint)*(byte *)(param_1 + 5) << 0x1a) >> 0x1f);
  bVar1 = DAT_208f463a | DAT_208f463d;
  if ((((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
      (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) &&
     ((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7))) {
    return;
  }
  FUN_2012d4a4(param_1);
  if (iVar6 == 0) {
    local_2c = &DAT_2016d2d0;
    if (DAT_208004d0 == 0) {
      sVar8 = 0xb4;
      iVar7 = 0xf0;
    }
    else {
      sVar8 = 0xc9;
      iVar7 = 0xdb;
    }
  }
  else {
    sVar8 = 0x80;
    iVar7 = 0x124;
    local_2c = &DAT_2016d2f0;
  }
  fb_copy_rect(uVar2,sVar8,0,800,iVar7);
  FUN_20132f44(0);
  if (DAT_20800483 == '\0') {
    if ((iVar6 == 0) && (DAT_208004d0 == 0)) {
      fb_copy_rect(uVar3,199,0,800,0xdd);
    }
    else {
      fb_copy_rect(uVar3,sVar8 + -2,0,800,iVar7 + 2);
    }
  }
  DAT_20800489 = 3;
  FUN_20134304(1);
  if ((*(byte *)(param_1 + 7) & 0x80) != 0) {
    FUN_201342d0(0);
  }
  FUN_20120d58();
  if (DAT_20800480 == '\0') {
    FUN_20133618();
  }
  DAT_208007c8 = 0;
  if (DAT_20800482 == '\0') {
    if (DAT_208004d0 == 0) {
      FUN_2012d19c(0);
      FUN_201359bc(uVar2,sVar8,4,local_2c);
      return;
    }
    if (DAT_208004d0 != 1) {
      if (DAT_208004d0 != 3) {
        DAT_208007c8 = 0;
        return;
      }
      FUN_20131f74(0,0xb8,1,iVar6,bVar1,param_2);
      return;
    }
    uVar2 = FUN_2012d318(iVar6);
    FUN_20134444(uVar2,uVar4);
    FUN_2012d19c(0);
    uVar3 = 1;
    uVar2 = 0;
    uVar5 = DAT_208004d2;
  }
  else {
    if (DAT_20800482 != '\x01') {
      DAT_208007c8 = 0;
      return;
    }
    if (DAT_208004d0 == 0) {
      FUN_2012d19c(1);
      FUN_201359bc(uVar2,sVar8,4,local_2c + 0x10);
    }
    else if (DAT_208004d0 == 1) {
      uVar3 = FUN_2012d318(iVar6);
      FUN_20134444(uVar3,uVar4);
      FUN_2012d19c(1);
      FUN_2012d000(1,sVar8,1,1,iVar6);
    }
    else {
      if (DAT_208004d0 != 3) {
        DAT_208007c8 = 0;
        return;
      }
      FUN_20131f74(0,0xb8,1,iVar6,bVar1,param_2);
    }
    if (1 < DAT_208004d0) {
      return;
    }
    gui_draw_runs(uVar2,0x12e,1,&DAT_2016d320);
    FUN_2012d19c(3);
    FUN_2012d000(3,0x12e,1,1,iVar6);
    gui_draw_runs(uVar2,0x12e,0x192,&DAT_2016d320);
    FUN_2012d19c(2);
    uVar3 = 0x192;
    sVar8 = 0x12e;
    uVar2 = 2;
    uVar5 = 1;
  }
  FUN_2012d000(uVar2,sVar8,uVar3,uVar5,iVar6);
  return;
}


// ===== FUN_2012d8bc @ 2012d8bc (828 bytes)

void FUN_2012d8bc(char *param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  byte local_38 [8];
  undefined4 local_30;
  undefined2 *local_2c;
  
  local_30 = fb_get_layer_addr(0);
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if (*param_1 != '7') {
    if (*param_2 == '7') {
      param_3 = 1;
    }
    if (-1 < (int)((uint)(byte)param_1[5] << 0x1a)) {
      bVar7 = (param_2[5] & 0x20U) != 0;
      if (bVar7) {
        param_3 = 1;
      }
      if (bVar7 || param_3 != 0) {
        uVar3 = 3;
        do {
          uVar3 = uVar3 + 1;
          FUN_20135534(local_30,0x6d,uVar3,&DAT_2016e090,1,0x45);
        } while (uVar3 < 0x1b5);
        gui_draw_runs(local_30,0x6d,1,&DAT_2016e080);
        uVar4 = 1;
        do {
          FUN_20135ad8(local_30,DAT_208004c0,(&DAT_2016e15c)[uVar4 * 5],DAT_208006ba,DAT_208006b8,0)
          ;
          uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 4);
        FUN_20132f44(0);
      }
      uVar4 = (uint)(byte)param_1[0xc];
      uVar5 = 0;
      local_38[0] = (byte)(uVar4 & 3);
      if (3 < (uVar4 & 3)) {
        local_38[0] = 3;
      }
      uVar2 = (uint)(byte)param_2[0xc];
      local_38[4] = (byte)(uVar2 & 3);
      if (3 < (uVar2 & 3)) {
        local_38[4] = 3;
      }
      uVar1 = (uVar4 & 0xf) >> 2;
      local_38[1] = (byte)uVar1;
      if (2 < uVar1) {
        local_38[1] = 2;
      }
      uVar1 = (uVar2 & 0xf) >> 2;
      local_38[5] = (byte)uVar1;
      if (2 < uVar1) {
        local_38[5] = 2;
      }
      uVar4 = (uVar4 & 0x3f) >> 4;
      local_38[2] = (byte)uVar4;
      if (2 < uVar4) {
        local_38[2] = 2;
      }
      uVar4 = (uVar2 & 0x3f) >> 4;
      local_38[6] = (byte)uVar4;
      if (2 < uVar4) {
        local_38[6] = 2;
      }
      local_38[3] = param_1[0xd] & 7;
      if (4 < local_38[3]) {
        local_38[3] = 4;
      }
      local_38[7] = param_2[0xd] & 7;
      if (4 < local_38[7]) {
        local_38[7] = 4;
      }
      local_2c = &DAT_2016e170;
      do {
        if ((param_3 != 0) || (local_38[uVar5] != local_38[uVar5 + 4])) {
          uVar3 = 0;
          iVar6 = (&DAT_20802698)[uVar5];
          if (**(short **)(iVar6 + (uint)local_38[uVar5] * 4) != 0) {
            do {
              FUN_20135534(local_30,(&DAT_2016e15e)[uVar5 * 5],
                           DAT_208006b4 + (&DAT_2016e15c)[uVar5 * 5] + uVar3,&DAT_2016e090,1,0x45);
              uVar3 = uVar3 + 1;
            } while (uVar3 < **(ushort **)(iVar6 + (uint)local_38[uVar5] * 4));
          }
          if ((uVar5 == 2) && (local_38[2] == '\x02')) {
            gui_draw_runs(local_30,DAT_208006b2 + local_2c[1],DAT_208006b0 + 0xdd,&DAT_2016e14c);
          }
          else {
            gui_draw_runs(local_30,DAT_208006b2 + (&DAT_2016e15e)[uVar5 * 5],
                          (&DAT_2016e15c)[uVar5 * 5] + DAT_208006b0,(&DAT_20802688)[uVar5]);
            gui_draw_runs(local_30,DAT_208006b6 + (&DAT_2016e15e)[uVar5 * 5],
                          (&DAT_2016e15c)[uVar5 * 5] + DAT_208006b4,
                          *(undefined4 *)(iVar6 + (uint)local_38[uVar5] * 4));
          }
          FUN_20132f44(0);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 4);
    }
  }
  return;
}


// ===== FUN_2012dbf8 @ 2012dbf8 (460 bytes)

void FUN_2012dbf8(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  undefined *puVar6;
  
  uVar1 = fb_get_layer_addr(0);
  if (param_3 != 0) {
    uVar4 = 3;
    do {
      FUN_20135534(uVar1,0x1a4,uVar4,&DAT_2016e28c,1,0x3c);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x31d);
    gui_draw_runs(uVar1,0x1a4,0,&DAT_2016e27c);
    uVar5 = 1;
    do {
      FUN_20135ad8(uVar1,DAT_20800706,(&DAT_2016e304)[uVar5 * 5],DAT_2080070a,DAT_20800708,0);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 6);
    FUN_20132f44(0);
  }
  uVar5 = 0;
  do {
    uVar3 = (uint)*(byte *)(param_1 + uVar5 + 0x25);
    uVar2 = uVar3 & 0x7f;
    if ((param_3 != 0) || (uVar3 != *(byte *)(param_2 + uVar5 + 0x25))) {
      puVar6 = (undefined *)0x0;
      if ((uVar2 != 0x7f) && (uVar2 < 0xd)) {
        puVar6 = (&PTR_DAT_20802d38)[uVar2];
      }
      uVar4 = 0;
      if (*(short *)PTR_DAT_20802d38 != 0) {
        do {
          FUN_20135534(uVar1,(&DAT_2016e306)[uVar5 * 5],
                       DAT_2080070c + (&DAT_2016e304)[uVar5 * 5] + uVar4,&DAT_2016e28c,1,0x3c);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(ushort *)PTR_DAT_20802d38);
      }
      if (puVar6 != (undefined *)0x0) {
        gui_draw_runs(uVar1,(&DAT_2016e306)[uVar5 * 5] + DAT_2080070e,
                      DAT_2080070c + (&DAT_2016e304)[uVar5 * 5],puVar6);
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 6);
  return;
}


// ===== FUN_2012ddc4 @ 2012ddc4 (828 bytes)

void FUN_2012ddc4(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  ushort *unaff_r4;
  int iVar2;
  int iVar3;
  undefined *local_38 [5];
  
  local_38[3] = (undefined *)fb_get_layer_addr(DAT_208085b8);
  iVar3 = 0;
  switch(param_1) {
  case 1:
  case 3:
  case 4:
  case 8:
    unaff_r4 = &DAT_20800674;
    break;
  case 2:
    if (param_2 < 99) {
      unaff_r4 = &DAT_20800678;
    }
    else {
      unaff_r4 = (ushort *)0x2080067c;
    }
    break;
  case 5:
    unaff_r4 = &DAT_20800684;
    break;
  case 7:
    unaff_r4 = &DAT_20800680;
    break;
  case 9:
  case 10:
    unaff_r4 = &DAT_20800688;
  }
  if (*(int *)(&DAT_20802630 + param_1 * 4) != 0) {
    gui_draw_runs(local_38[3],unaff_r4[1] + 10,*unaff_r4 + 0x11a);
  }
  if (param_1 == 1) {
    puVar1 = &DAT_2016deec;
    if (param_3 != 0) {
      puVar1 = &DAT_2016df0c;
    }
    gui_draw_runs(local_38[3],unaff_r4[1] + 10,*unaff_r4 + 0x11a,puVar1);
  }
  else {
    if (param_1 == 2) {
      if (param_2 < 99) {
        iVar3 = 2;
        local_38[0] = *(undefined **)
                       (&DAT_20802310 + ((uint)((short)(param_2 + 1) * 0xcd) >> 0xb) * 4);
        local_38[1] = *(undefined **)(&DAT_20802310 + ((param_2 + 1) % 10) * 4);
      }
      else if (param_2 < 0x75) {
        iVar3 = 3;
        local_38[0] = &DAT_2016decc;
        local_38[1] = (&PTR_DAT_20802314)[(int)(param_2 - 99) / 2];
        local_38[2] = (undefined *)*(undefined4 *)(&DAT_208007f8 + (param_2 & 1) * 4);
      }
      iVar2 = 0;
      if (iVar3 == 0) {
        return;
      }
      do {
        gui_draw_runs(local_38[3],unaff_r4[1] + 10,
                      (uint)DAT_2080068c * iVar2 + 0x11a +
                      (uint)*(ushort *)PTR_DAT_20802638 + (uint)*unaff_r4 & 0xffff,local_38[iVar2]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
    if (param_1 == 7) {
      iVar2 = 0;
      iVar3 = (short)((short)param_2 + -0x95) * 0xcd;
      local_38[0] = *(undefined **)(&DAT_20802310 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
      local_38[1] = (undefined *)*(undefined4 *)(&DAT_20802310 + ((int)(param_2 - 0x95) % 10) * 4);
      do {
        gui_draw_runs(local_38[3],unaff_r4[1] + 10,
                      (uint)DAT_2080068c * iVar2 + 0x11a +
                      (uint)*(ushort *)PTR_DAT_2080264c + (uint)*unaff_r4 & 0xffff,local_38[iVar2]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
    }
    if (param_1 == 5) {
      local_38[0] = (undefined *)0x0;
      if (9 < (int)(param_2 - 199)) {
        iVar3 = (short)(param_2 - 199) * 0xcd;
        local_38[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
      }
      iVar3 = 0;
      local_38[1] = (undefined *)*(undefined4 *)(&DAT_20802338 + ((int)(param_2 - 199) % 10) * 4);
      do {
        if (local_38[iVar3] != (undefined *)0x0) {
          gui_draw_runs(local_38[3],unaff_r4[1] + 10,
                        (uint)*unaff_r4 + (uint)*(ushort *)PTR_DAT_20802644 +
                        (uint)DAT_2080068c * iVar3 + 0x11a & 0xffff);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
      return;
    }
  }
  return;
}


// ===== FUN_2012e1a4 @ 2012e1a4 (216 bytes)

void FUN_2012e1a4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  uVar3 = (uint)*(byte *)(param_1 + 0x2d);
  bVar5 = *(byte *)(param_1 + 0x2e);
  bVar4 = *(byte *)(param_1 + 0x2f);
  bVar2 = *(byte *)(param_1 + 3) & 0x80;
  if ((param_3 == 0 && uVar3 == *(byte *)(param_2 + 0x2d)) &&
     ((bVar5 == *(byte *)(param_2 + 0x2e) && bVar4 == *(byte *)(param_2 + 0x2f)) &&
      bVar2 == (*(byte *)(param_2 + 3) & 0x80))) {
    return;
  }
  if (0xf < uVar3) {
    uVar3 = 0xf;
  }
  if (10 < bVar5) {
    bVar5 = 10;
  }
  if (0xd1 < bVar4) {
    bVar4 = 0xd1;
  }
  gui_draw_runs(uVar1,10,0x11a,&DAT_2016e714);
  FUN_2012ddc4(bVar5,bVar4,bVar2);
  gui_draw_runs(uVar1,DAT_20800776 + 10,DAT_20800774 + 0x11a,(&PTR_DAT_20802ff4)[uVar3]);
  return;
}


// ===== FUN_2012e27c @ 2012e27c (332 bytes)

void FUN_2012e27c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (((param_3 != 0) || ((*(byte *)(param_1 + 0xd) & 0x80) != (*(byte *)(param_2 + 0xd) & 0x80)))
     || (iVar2 = FUN_2015507c(param_1 + 0x15,param_2 + 0x15,4), iVar2 != 0)) {
    fb_copy_rect(uVar1,DAT_2080050a,DAT_20800508,0xa3,0xe);
    if ((*(byte *)(param_1 + 0xd) & 0x80) != 0) {
      gui_draw_runs(uVar1,DAT_2080050a,DAT_20800508,&DAT_2016d5dc);
      uVar3 = 0;
      do {
        if (((uint)*(byte *)(param_1 + (uVar3 >> 3) + 0x15) & 1 << (uVar3 & 7)) != 0) {
          fb_fill_rect(uVar1,0xffff,DAT_2080050a + DAT_20800512,
                       DAT_20800514 * uVar3 + (uint)DAT_20800508 + (uint)DAT_20800510 & 0xffff,
                       DAT_20800518,DAT_2080051a);
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 0x19);
    }
    if (param_3 != 0) {
      fb_copy_rect(uVar1,DAT_2080050e,DAT_2080050c,0xa3,0xe);
    }
  }
  return;
}


// ===== FUN_2012e3c8 @ 2012e3c8 (24 bytes)

void FUN_2012e3c8(byte param_1,byte *param_2,byte *param_3)

{
  param_1 = param_1 & 0xf;
  if (10 < param_1) {
    param_1 = 10;
  }
  *param_2 = param_1;
  *param_3 = param_1;
  return;
}


// ===== FUN_2012e3e0 @ 2012e3e0 (964 bytes)

void FUN_2012e3e0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  uint local_40;
  undefined1 local_3c [4];
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = fb_get_layer_addr(0);
  local_2c = fb_get_layer_addr(DAT_208085b8);
  local_30 = fb_get_layer_addr(DAT_208085bc);
  bVar2 = false;
  bVar1 = false;
  bVar6 = DAT_208f4638 != '\0';
  local_38 = *(byte *)(param_1 + 0x12) & 0xf;
  local_34 = *(byte *)(param_2 + 0x12) & 0xf;
  bVar3 = *(byte *)(param_1 + 0x10) >> 4;
  FUN_2012616c(2);
  if (param_3 != 0 || bVar6) {
    FUN_20134480((*(byte *)(param_1 + 5) & 0x3f) >> 5);
  }
  uVar5 = *(byte *)(param_1 + 6) & 0x80;
  local_40 = *(byte *)(param_1 + 6) & 0x40;
  if ((param_3 != 0 || bVar6) || ((*(byte *)(param_2 + 6) & 0x80) != uVar5)) {
    FUN_20134468(uVar5);
    bVar2 = true;
    if (param_3 == 0 && !bVar6) goto LAB_2012e4b4;
  }
  else {
LAB_2012e4b4:
    if ((*(byte *)(param_2 + 6) & 0x40) == local_40) goto LAB_2012e4d4;
  }
  FUN_20134474(local_40);
  bVar2 = true;
LAB_2012e4d4:
  if (bVar3 != 0) {
    DAT_208004a0 = bVar3 * '\x03';
  }
  if ((param_3 != 0 || bVar6) ||
     ((*(byte *)(param_1 + 0x10) & 7) != (*(byte *)(param_2 + 0x10) & 7))) {
    bVar3 = *(byte *)(param_1 + 0x10) & 7;
    if (4 < bVar3) {
      bVar3 = 4;
    }
    FUN_20133dec(bVar3);
    bVar1 = true;
  }
  if ((bVar6) || ((local_38 != local_34 || bVar1) || bVar2)) {
    FUN_2012e3c8(local_38,local_3c,&local_40);
    FUN_201342dc(local_3c[0],local_40 & 0xff);
    thunk_FUN_2015d2a8(local_3c[0]);
  }
  FUN_20134d24(param_1,param_2,param_3);
  FUN_2012e27c(param_1,param_2,param_3);
  FUN_2012e1a4(param_1,param_2,param_3);
  FUN_2012a6a4(param_1,param_2,param_3);
  FUN_2012dbf8(param_1,param_2,param_3);
  if (bVar6) {
    local_40 = 0x137;
    fb_copy_rect(local_28,0x6d,0,800);
    FUN_20132f44(0);
    local_40 = 0x137;
    fb_copy_rect(local_2c,0x6d,0,800);
    local_40 = 0x137;
    fb_copy_rect(local_30,0x6d,0,800);
    param_3 = 1;
  }
  FUN_2012d8bc(param_1,param_2,param_3);
  FUN_2012d52c(param_1,param_2,param_3);
  FUN_2012cf30(param_1,param_2,param_3);
  FUN_2012caac(param_1,param_2,param_3);
  FUN_2012c6c4(param_1,param_2,param_3);
  uVar4 = fb_get_layer_addr(DAT_208085b8);
  uVar5 = (uint)*(byte *)(param_1 + 0x2c);
  bVar3 = *(byte *)(param_2 + 0x2c);
  if (param_3 != 0) {
    fb_fill_rect(uVar4,0x821,DAT_208007be,DAT_208007bc);
    gui_draw_runs(uVar4,DAT_208007be,DAT_208007bc,&DAT_2016ed18);
  }
  if (uVar5 != 0xe) {
    if (uVar5 < 0xf) {
      if (0xd < uVar5) {
        return;
      }
    }
    else if (uVar5 != 0x15) {
      if (uVar5 < 0x16) {
        if (5 < uVar5 - 0xf) {
          return;
        }
      }
      else if (uVar5 != 0x2d) {
        if (uVar5 < 0x2e) {
          if ((uVar5 != 0x1a && uVar5 != 0x1b) && uVar5 != 0x1c) {
            return;
          }
        }
        else if (uVar5 != 0x36 && uVar5 != 0x3a) {
          return;
        }
      }
    }
  }
  if (param_3 == 0 && uVar5 == bVar3) {
    return;
  }
  fb_fill_rect(uVar4,0x821,DAT_208007c6,DAT_208007c4);
  gui_draw_runs(uVar4,DAT_208007c6,DAT_208007c4,*(undefined4 *)(&DAT_20803644 + uVar5 * 4));
  return;
}


// ===== FUN_2012e678 @ 2012e678 (80 bytes)

void FUN_2012e678(int param_1,int param_2)

{
  FUN_20101f5c(1);
  if (((*(byte *)(param_1 + 3) & 4) != 0) ||
     ((*(byte *)(param_1 + 3) & 3) != (*(byte *)(param_2 + 3) & 3))) {
    DAT_208f4897 = 0;
  }
  FUN_201310ec(param_1,1);
  return;
}


// ===== FUN_2012e6c8 @ 2012e6c8 (124 bytes)

void FUN_2012e6c8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  FUN_2013396c(5,0);
  FUN_201337f8(5);
  FUN_20155274(uVar1,0xbb800);
  FUN_20133a0c(6);
  itron_dly_tsk(0xf);
  iVar2 = FUN_20113f50();
  if (iVar2 != 0) {
    FUN_20133a38(6);
  }
  DAT_208004ca = 0;
  DAT_208004cc = 0;
  FUN_20133a38(3);
  FUN_20133a38(4);
  return;
}


// ===== FUN_2012e744 @ 2012e744 (352 bytes)

void FUN_2012e744(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_5c [4];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (DAT_2080048e < 2) {
    DAT_2080048e = 1;
    cVar1 = *(char *)(param_1 + 1);
    iVar2 = FUN_20103ba0();
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
LAB_2012e7f0:
      FUN_20124744(uVar3);
      return;
    }
    if (cVar1 == '\x01') {
      iVar2 = FUN_20103bc0(iVar2);
      if (iVar2 != 0) {
        uVar3 = 0xfffffffd;
        goto LAB_2012e7f0;
      }
      iVar2 = FUN_20124848(2,1);
      if (iVar2 != 0) {
        FUN_20114528(local_5c,local_18,local_1c);
        FUN_2011459c(local_20,local_24,local_28);
        FUN_20154a30(&local_58,0x20,"20%02x%02x%02x_%02x%02x%02x",local_5c[0],local_18[0],
                     local_1c[0],local_20[0],local_24[0],local_28[0]);
        uVar3 = FUN_20135498(&DAT_208f0b9f);
        FUN_20154a30(&local_38,0x10,&DAT_2012e8ec,uVar3);
        FUN_201058dc(&local_58,&local_38,DAT_208f0b57,1);
        DAT_20800491 = 1;
        return;
      }
    }
    else if (cVar1 == '\0') {
      iVar2 = FUN_20124848(0);
      if (iVar2 != 0) {
        FUN_20105a20();
      }
      DAT_20800491 = 0;
    }
  }
  return;
}


// ===== FUN_2012e8f4 @ 2012e8f4 (180 bytes)

void FUN_2012e8f4(int param_1)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
  cVar2 = *(char *)(param_1 + 1);
  uVar3 = *(undefined1 *)(param_1 + 2);
  uVar4 = *(undefined1 *)(param_1 + 3);
  uVar5 = *(undefined1 *)(param_1 + 4);
  uVar6 = *(undefined1 *)(param_1 + 5);
  iVar1 = FUN_20135458(cVar2);
  if (99 < iVar1) {
    cVar2 = 'c';
  }
  iVar1 = FUN_20135458(uVar3);
  if (0xc < iVar1) {
    uVar3 = 0xc;
  }
  iVar1 = FUN_20135458(uVar3);
  if (iVar1 < 1) {
    uVar3 = 1;
  }
  iVar1 = FUN_20135458(uVar4);
  if (0x1f < iVar1) {
    uVar4 = 0x1f;
  }
  iVar1 = FUN_20135458(uVar4);
  if (iVar1 < 1) {
    uVar4 = 1;
  }
  iVar1 = FUN_20135458(uVar5);
  if (0x17 < iVar1) {
    uVar5 = 0x17;
  }
  iVar1 = FUN_20135458(uVar6);
  if (0x3b < iVar1) {
    uVar6 = 0x3b;
  }
  FUN_20114608((int)cVar2,uVar3,uVar4,uVar5,uVar6);
  return;
}


// ===== FUN_2012e9a8 @ 2012e9a8 (204 bytes)

void FUN_2012e9a8(int param_1,int param_2)

{
  DAT_208f4638 = 0;
  DAT_208f4639 = 0;
  DAT_208f463a = 0;
  DAT_208f463b = 0;
  DAT_208f4634 = 0;
  DAT_208f463c = 0;
  DAT_208f463d = 0;
  if (DAT_208f0b18 == '\0') {
    return;
  }
  DAT_208f4638 = (*(byte *)(param_1 + 5) & 0x20) != (*(byte *)(param_2 + 5) & 0x20);
  DAT_208f4639 = DAT_208f4632 != DAT_208f0b1e;
  DAT_208f463a = DAT_208f4631 != DAT_208f0b1d;
  if ((DAT_208f4633 == '\0') && (DAT_208f0b1f == '\x01')) {
    DAT_208f463b = 1;
  }
  DAT_208f4634 = (DAT_208f462c == '@' || DAT_208f462c == 'C') || DAT_208f462c == ':';
  if ((DAT_208f462c == '0') && (*(char *)(param_1 + 0x98) == -1)) {
    DAT_208f463c = 1;
  }
  DAT_208f463d = DAT_208f4635 != DAT_208f0b21;
  return;
}


// ===== FUN_2012ea74 @ 2012ea74 (324 bytes)

void FUN_2012ea74(char *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (((cVar1 == '#' || cVar1 == '?') || (cVar1 == 'd' || cVar1 == 'e')) ||
     ((cVar1 == 'z' || cVar1 == '{') || cVar1 == '|')) {
    return;
  }
  if (cVar1 == 'C') {
    memcpy(&DAT_208f0fcb,param_1,0x240);
    return;
  }
  memcpy(&DAT_208f0fcb,param_1,0x240);
  if (cVar1 != DAT_208f0b18) {
    DAT_208f462d = 0;
  }
  DAT_208f462e = param_1[1];
  DAT_208f462f = param_1[2];
  DAT_208f4630 = (byte)(((uint)(byte)param_1[5] << 0x1a) >> 0x1f);
  DAT_208f4631 = (byte)(((uint)(byte)param_1[3] << 0x1d) >> 0x1f);
  DAT_208f4635 = param_1[3] & 3;
  DAT_208f4632 = (byte)(((uint)(byte)param_1[4] << 0x1a) >> 0x1f);
  DAT_208f4633 = (byte)param_1[0x23] >> 7;
  if (cVar1 == '@') {
    DAT_208f4636 = 1;
LAB_2012eb64:
    DAT_208f4633 = 0;
LAB_2012eb68:
    if (cVar1 == ':') {
      DAT_208f4637 = 1;
    }
    if (cVar1 == ':' || cVar1 == '1') goto LAB_2012eb7c;
  }
  else if (cVar1 == 'p') {
    if ((-1 < (int)((uint)(byte)param_1[4] << 0x1a)) && (DAT_208f0b1e == '\x01')) {
      DAT_208f4632 = 1;
    }
  }
  else if (cVar1 != 'P') {
    DAT_208f4636 = 0;
    if (cVar1 == '7' || cVar1 == '@') goto LAB_2012eb64;
    goto LAB_2012eb68;
  }
  DAT_208f4637 = 0;
LAB_2012eb7c:
  DAT_208f462c = cVar1;
  FUN_2012e9a8(param_1,param_2);
  FUN_20155310(&DAT_208f0b18,&DAT_208f462c,0x12);
  return;
}


// ===== FUN_2012ebb8 @ 2012ebb8 (2912 bytes)

void FUN_2012ebb8(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  bool bVar7;
  byte local_270;
  undefined1 local_26f;
  undefined1 local_26e;
  byte local_269;
  undefined1 local_268;
  byte local_260;
  undefined2 local_1d8;
  undefined2 local_1d6;
  undefined2 local_1d4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = fb_get_layer_addr(0);
  local_30 = fb_get_layer_addr(DAT_208085b8);
  local_2c = fb_get_layer_addr(DAT_208085bc);
  puVar6 = (undefined1 *)0x0;
  uVar5 = 0;
  if (DAT_20800488 == '\x01') {
    mainlink_send_cmd(&DAT_208f0fcb);
    DAT_20800488 = '\0';
  }
  FUN_20115000(&local_270);
  FUN_2012ea74(&local_270,&DAT_208f0b2a);
  iVar2 = FUN_2015507c(&local_270,&DAT_208f0b2a,0x240);
  if (iVar2 == 0) goto LAB_2012f698;
  if ((local_270 == 0x39 || local_270 == 0x3a) || local_270 == 0x3f) {
LAB_2012ec7c:
    DAT_2080049f = 0;
  }
  else {
    if ((DAT_20800490 == '\0' && DAT_2080048f == '\0') && DAT_20800491 == '\0') {
      if (DAT_2080048e != '\x03') {
        FUN_201058cc();
      }
      DAT_2080048e = '\0';
      DAT_208007d8 = 0;
    }
    if (local_270 != 0x7c) goto LAB_2012ec7c;
  }
  if (DAT_208f0b2a == 100) {
    if (local_270 != 100) {
      FUN_20133a38(6);
      if (DAT_208f0b2a != 100) goto LAB_2012ecc8;
      goto LAB_2012ecdc;
    }
  }
  else {
LAB_2012ecc8:
    if (local_270 == 100) {
      FUN_20133a0c(6);
    }
LAB_2012ecdc:
    if (local_270 == 0x65) {
      FUN_2012e8f4(&local_270);
      return;
    }
    if (local_270 == 0x23) {
      FUN_20131354(&local_270);
      return;
    }
    if ((((((DAT_208f0b2a == 0x40) && (local_270 != 0x40 && local_270 != 0x20)) &&
          (local_270 != 0x30 && local_270 != 0x31)) &&
         ((local_270 != 0x37 && local_270 != 0x24 && (local_270 != 0x43 && local_270 != 0x70)))) &&
        ((local_270 != 0x7b && local_270 != 0x7c &&
         ((local_270 != 0x7a && local_270 != 0x41 && (local_270 != 0x62 && local_270 != 0x21))))))
       && (local_270 != 0x34 && local_270 != 0x50)) {
      return;
    }
  }
  if (DAT_208f4633 != '\0') {
    if (DAT_208f4638 == '\0') {
      if (((local_270 == 0x3a || local_270 == 0x39) || local_270 == 0x31) || (DAT_208f0b2a == 0x70))
      {
        if (DAT_208f4630 != '\0') {
          DAT_20800483 = '\x01';
        }
        return;
      }
    }
    else {
      FUN_20155274(local_2c,0xbb800);
    }
  }
  if ((DAT_208f463c != '\0') && (DAT_208f0b2a == 0x31 || DAT_208f0b2a == 0x3a)) {
    return;
  }
  if ((DAT_208f0b2a == 0x70) && (local_270 == 0x30)) {
    if ((byte)local_1d8 == -1) {
      return;
    }
  }
  else {
    if (local_270 == 0x3f) {
      FUN_2012e744(&local_270);
      DAT_2080049e = DAT_208f0b2a;
      memcpy(&DAT_208f0b2a,&local_270,0x240);
      return;
    }
    if (((DAT_208f0b2a == 0x7b) && (local_270 != 0x7b)) &&
       ((FUN_2012e6c8(&local_270), DAT_208f4636 != '\0' || (local_270 == 0x3a)))) {
      FUN_2012616c(0);
    }
  }
  if ((DAT_208f463b != '\0') && (FUN_20155274(local_2c,0xbb800), DAT_208f4630 != '\0')) {
    if (local_270 == 0x41) {
      fb_fill_rect(local_30,0x821,0x6d,0x1bb,0x164,0x45);
    }
    else {
      fb_copy_rect(local_30,0x6d,0x1bb,0x164,0x45);
    }
  }
  if (DAT_208f463a != '\0') {
    if (DAT_208f4630 == '\0') {
      uVar3 = 0xb4;
    }
    else {
      uVar3 = 0x6d;
    }
    fb_copy_rect(local_28,uVar3,1,0x31e,0x15);
    fb_copy_rect(local_30,uVar3,1,0x31e,0x15);
  }
  uVar4 = (uint)local_270;
  if (uVar4 - 0x20 < 0x22) {
    if (uVar4 != 0x21) {
LAB_2012efbc:
      FUN_201120fc(&local_26f);
      DAT_2080048b = DAT_2080048a;
      bVar7 = (local_269 & 0x80) != 0;
      bVar1 = ~DAT_2080048a;
      DAT_2080048a = bVar7;
      if ((bVar7 & bVar1) != 0) {
        FUN_2013448c();
        FUN_20120db4();
      }
      if ((DAT_2080048b & ~DAT_2080048a) != 0) {
        FUN_20134498();
        FUN_20120dc0();
      }
      if ((local_260 & 0xf0) != (DAT_208f0b3a & 0xf0)) {
        bVar7 = (local_260 & 0xf0) == 0;
        if (bVar7) {
          FUN_201342f8(0);
        }
        else {
          FUN_201342f8(1);
        }
        FUN_20120d4c(!bVar7);
      }
      FUN_2012e678(&local_270,&DAT_208f0b2a,DAT_20800485);
      if (local_270 != 0x3a) {
        if ((DAT_208f4632 == '\0') && (DAT_208f4636 == '\0')) {
          if (((DAT_20800483 != '\0') || ((local_270 == 0x39 && (DAT_208f0b2a != 0x39)))) ||
             ((DAT_208f463c != '\0' && (DAT_208f0b2a == 0x39)))) {
            DAT_20800483 = '\0';
            DAT_20800484 = 0;
            fb_copy_rect(local_30,0x6d,0,800,0x173);
            if ((local_270 == 0x39) || (DAT_208f0b2a == 0x39)) {
              DAT_20800485 = 0;
            }
            else {
              DAT_20800485 = 1;
            }
            goto LAB_2012f188;
          }
        }
        else {
          DAT_20800483 = '\x01';
          if (local_270 == 0x37) {
LAB_2012f0ac:
            DAT_20800484 = 1;
          }
          else {
            if (local_270 == 0x70) {
              if (((DAT_208f0b2a != 0x3f && DAT_208f0b2a != 0x37) && (DAT_208f4632 == '\0')) &&
                 (DAT_208f0b2a != 0x70)) goto LAB_2012f09c;
              goto LAB_2012f0ac;
            }
            if (local_270 == 0x24) goto LAB_2012f0ac;
LAB_2012f09c:
            if (DAT_208f4636 != '\0') goto LAB_2012f0ac;
            DAT_20800484 = 0;
          }
          if ((DAT_208f0b2a == 0x37) &&
             ((local_270 != 0x37 && local_270 != 0x70) && local_270 != 0x24)) {
            fb_copy_rect(local_30,0x6d,0,800,0x173);
            DAT_20800485 = 1;
          }
LAB_2012f188:
          if ((DAT_208f4636 != '\0') || (local_270 == 0x3a)) goto LAB_2012f1c0;
        }
        FUN_2012e3e0(&local_270,&DAT_208f0b2a,DAT_20800485);
        DAT_20800485 = 0;
      }
LAB_2012f1c0:
      if (local_270 == DAT_208f0b2a) {
        if ((local_270 == 0x30) || (local_270 == 0x31)) {
          if ((byte)local_1d8 != DAT_208f0bc2) {
LAB_2012f2d8:
            FUN_20155274(local_2c,0xbb800);
            goto LAB_2012f2f8;
          }
        }
        else if (local_270 == 0x70) {
          puVar6 = &DAT_208f0b2a;
          uVar5 = 1;
          goto LAB_2012f320;
        }
        puVar6 = &DAT_208f0b2a;
LAB_2012f2f8:
        if (((local_270 == 0x20 || local_270 == 0x39) || local_270 == 0x37) &&
           (DAT_208f0b2a != 0x70)) {
          FUN_2012c4a0(&local_270);
        }
      }
      else {
        if (((local_270 == 0x40 || local_270 == 0x43) || (local_270 == 0x70 || local_270 == 0x31))
           && ((DAT_208f0b2a == 0x40 || DAT_208f0b2a == 0x43 ||
               ((DAT_208f0b2a == 0x70 || DAT_208f0b2a == 0x7c ||
                ((DAT_208f0b2a == 0x31 || DAT_208f0b2a == 0x7a) || local_270 == 0x70)))))) {
          uVar5 = 1;
          goto LAB_2012f2f8;
        }
        uVar5 = 1;
        if ((DAT_208f0b2a != 0) && (FUN_201337f8(5), DAT_208f0b2a == 0x7b || DAT_208f0b2a == 0x7a))
        {
          if (DAT_208f4636 != '\0') goto LAB_2012f2f8;
          if (local_270 == 0x3a) goto LAB_2012f320;
        }
        if (local_270 == 0x30) {
          if ((byte)local_1d8 != -1) {
LAB_2012f26c:
            if (DAT_20800497 == '\0') {
              return;
            }
            if (DAT_208f0b2a != 0) goto LAB_2012f2d8;
            goto LAB_2012f2f8;
          }
        }
        else if (local_270 != 0x24) goto LAB_2012f26c;
      }
LAB_2012f320:
      iVar2 = FUN_2012c2d8(&local_270,puVar6);
      if (iVar2 != 0) {
        if (local_270 == 0x39) {
          FUN_2012a6a4(&local_270,puVar6,uVar5);
          FUN_201293f8(&local_270,uVar5);
        }
        else if (local_270 < 0x3a) {
          if (local_270 == 0x31) {
            FUN_2012ade0(&local_270);
          }
          else if (local_270 < 0x32) {
            if (local_270 != 0x20) {
              if (local_270 == 0x24) {
                if ((local_1d6._1_1_ & 0x7f) != (DAT_208007ea._1_1_ & 0x7f)) {
                  FUN_201026e0(local_1d6._1_1_ & 0x7f);
                }
                if (((byte)local_1d4 & 0x7f) != ((byte)DAT_208007ec & 0x7f)) {
                  FUN_20113db8((byte)local_1d4 & 0x7f);
                }
                FUN_2012194c(&local_270,&DAT_208f0b2a,0);
                if (((byte)local_1d8 & 3) == ((byte)DAT_208007e8 & 3)) {
                  if ((local_1d4._1_1_ & 0x1f) != (DAT_208007ec._1_1_ & 0x1f)) goto LAB_2012f534;
                }
                else {
LAB_2012f534:
                  FUN_201266ec(&local_1d8,&DAT_208007e8,0);
                }
                if (((byte)local_1d8 & 4) != ((byte)DAT_208007e8 & 4)) {
                  FUN_20101f8c((byte)local_1d8 & 4);
                }
                DAT_208007e8 = local_1d8;
                DAT_208007ea = local_1d6;
                DAT_208007ec = local_1d4;
              }
              else if (local_270 == 0x30) {
                FUN_2012c1b4(&local_270,puVar6,uVar5);
              }
            }
          }
          else if (local_270 == 0x34) {
            FUN_201263e8(&local_270);
          }
          else if (local_270 == 0x37) {
            FUN_2012a9ec(&local_270,uVar5);
          }
        }
        else if (local_270 == 0x50) {
          if (DAT_208f463b != '\0') {
            uVar5 = 1;
          }
          FUN_201275e8(&local_270,puVar6,uVar5);
        }
        else if (local_270 < 0x51) {
          if (local_270 == 0x3a) {
            FUN_20124c24(&local_270,&DAT_208f0b2a);
            FUN_2012616c(1);
          }
          else if (local_270 == 0x40) {
            FUN_20129054(&local_270,puVar6,uVar5);
          }
          else if (local_270 == 0x41) {
            FUN_20127b24(&local_270,uVar5);
          }
        }
        else if (local_270 == 0x62) {
          if (DAT_208f463b != '\0') {
            uVar5 = 1;
          }
          FUN_20126f28(&local_270,puVar6,uVar5);
          FUN_201147b4();
        }
        else if ((local_270 == 0x70) && (FUN_20126ebc(&local_270,uVar5), DAT_208f4636 != '\0')) {
          FUN_2012616c(1);
        }
      }
      FUN_20102040(local_268);
      DAT_2080049e = DAT_208f0b2a;
      memcpy(&DAT_208f0b2a,&local_270,0x240);
      goto LAB_2012f698;
    }
  }
  else if ((uVar4 == 0x50 || uVar4 == 0x62) || uVar4 == 0x70) goto LAB_2012efbc;
  if (uVar4 == 0x7a) {
    screen_capture_bmp();
    DAT_208f0b2a = local_270;
    DAT_20800488 = '\x01';
    if (DAT_208f0fcb == ':') {
      FUN_2012616c(0);
    }
    goto LAB_2012f698;
  }
  if (uVar4 < 0x7b) {
    if (uVar4 == 0x21) {
      FUN_20101fa4(local_26f,local_26e);
      goto LAB_2012f698;
    }
    if (uVar4 != 0x43) {
      if (uVar4 == 100) {
        FUN_20125f6c(&local_270);
        DAT_208f0b2a = local_270;
      }
      goto LAB_2012f698;
    }
    if ((DAT_208f0b2a != 0x43) || (iVar2 = FUN_2015507c(&DAT_208f0d6a,&local_26f,0x21), iVar2 != 0))
    {
      FUN_201261e0(&local_270);
      memcpy(&DAT_208f0d6a,&local_26f,0x21);
    }
  }
  else {
    if (uVar4 == 0x7b) {
      if (DAT_208f0b2a != 0x7b) {
        DAT_20800487 = 0;
        DAT_20800485 = 1;
        DAT_208f0b2a = local_270;
        DAT_208f0b2b = local_26f;
      }
      goto LAB_2012f698;
    }
    if (uVar4 != 0x7c) goto LAB_2012f698;
    if (DAT_208f0b2a != 0x7c) {
      DAT_2080049f = 1;
      touch_calibration(1);
    }
  }
  DAT_208f0b2a = local_270;
LAB_2012f698:
  iVar2 = FUN_20125d8c();
  if (iVar2 != 0) {
    FUN_20124c24(&local_270,&DAT_208f0b2a);
    DAT_2080049e = DAT_208f0b2a;
    memcpy(&DAT_208f0b2a,&local_270,0x240);
  }
  FUN_201248f8();
  if (DAT_20800491 != '\0') {
    iVar2 = FUN_20105790();
    if (iVar2 == 0) {
      FUN_20124848(0);
      DAT_20800491 = '\0';
    }
    iVar2 = FUN_20103ba0();
    if (iVar2 == 0) {
      FUN_20105a20();
      FUN_20124744(0xffffffff);
      DAT_20800491 = 0;
      return;
    }
  }
  return;
}


// ===== FUN_2012f734 @ 2012f734 (416 bytes)

undefined4 FUN_2012f734(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_260;
  byte local_25f [14];
  undefined1 auStack_251 [4];
  byte local_24d;
  byte local_24c;
  byte local_24b;
  byte local_242;
  undefined1 local_240;
  byte local_1ba;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  
  uVar3 = 0;
  fb_get_layer_addr(DAT_208085b8);
  FUN_2011500c(&local_260);
  if (local_260 == '`') {
    if ((~local_25f[0] & 0xf0) == 0) {
      iVar2 = 0;
      FUN_201026e0(100);
      do {
        itron_dly_tsk(3);
        iVar2 = iVar2 + 1;
      } while (iVar2 * 0x21 < 0x9c5);
      uVar1 = fb_get_layer_addr(DAT_208085b8);
      FUN_20155274(uVar1,0xbb800);
      gui_update_layers();
      FUN_201322f0();
      while (DAT_20800493 == '\0') {
        gui_update_layers();
        FUN_201525f8(0xffffffff);
      }
    }
    else {
      local_242 = local_242 & 7;
      if (4 < local_242) {
        local_242 = 4;
      }
      FUN_20133dec(local_242);
      DAT_2080048a = (local_24b & 0x80) != 0;
      if ((DAT_2080048a & ~DAT_2080048b) != 0) {
        FUN_2013448c();
        FUN_20120db4();
      }
      if ((DAT_2080048b & ~DAT_2080048a) != 0) {
        FUN_20134498();
        FUN_20120dc0();
      }
      FUN_20134480((local_24d & 0x3f) >> 5);
      uVar3 = FUN_2012d318(local_24d & 0x20);
      FUN_20134444(uVar3,local_24c & 0x80);
      FUN_20134474(local_24c & 0x40);
      FUN_2012e3c8(local_240,local_20,local_1c);
      FUN_201342dc(local_20[0],local_1c[0]);
      thunk_FUN_2015d2a8(local_20[0]);
      FUN_201322bc(local_25f);
      DAT_20800481 = local_1ba & 0xf;
      DAT_208f0b2a = 0x20;
      memcpy(&DAT_208f0b2b,auStack_251,0x97);
      FUN_201310ec(&local_260,0);
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ===== FUN_2012f8d4 @ 2012f8d4 (1216 bytes)

void FUN_2012f8d4(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined2 local_4e0;
  undefined1 local_4de;
  undefined1 local_4dd;
  undefined1 local_4dc;
  undefined2 local_4d8;
  undefined2 local_4d6;
  undefined2 local_4d4;
  short local_4d0;
  short local_4ce;
  undefined2 local_4cc;
  undefined2 local_4ca;
  undefined1 uStack_4c8;
  undefined1 auStack_4c7 [575];
  char local_288 [14];
  char local_27a;
  undefined1 auStack_1e1 [409];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  short *local_34;
  undefined2 *local_30;
  undefined4 local_2c;
  
  uVar4 = fb_get_layer_addr(0);
  uVar5 = fb_get_layer_addr(DAT_208085bc);
  local_38 = fb_get_layer_addr(DAT_208085b8);
  iVar7 = 0;
  memclr(&uStack_4c8,0x240);
  fb_copy_rect(uVar4,0,0,800,0x1e0);
  fb_copy_rect(local_38,0,0,800,0x1e0);
  fb_copy_rect(uVar5,0,0,800,0x1e0);
  gui_update_layers();
  fb_copy_rect(uVar4,0,0,800,0x1e0);
  fb_copy_rect(local_38,0,0,800,0x1e0);
  fb_copy_rect(uVar5,0,0,800,0x1e0);
  gui_update_layers();
  FUN_201337f8(3);
  FUN_201337f8(5);
  local_4cc = DAT_208004d4;
  local_4d0 = DAT_208004d6;
  local_4ca = 0x1e6;
  local_4e0 = 0;
  local_4de = 0;
  local_4ce = (DAT_208004da - DAT_208004d6) + 0x18;
  local_34 = &local_4d0;
  local_4dd = 0;
  local_30 = &local_4e0;
  local_4dc = 0;
  local_2c = 0;
  FUN_20101c10(1);
  local_4e0 = 0;
  FUN_20133658(0,4,1,&local_34);
  FUN_20133658(1,4,1,&local_34);
  FUN_20133090(1);
  itron_dly_tsk(0x14);
  gui_draw_runs(local_38,DAT_208004d6,DAT_208004d4,&DAT_2016d2c0);
  gui_update_layers();
  local_4e0 = 2;
  FUN_20133658(0,4,1,&local_34);
  FUN_20133658(1,4,1,&local_34);
  FUN_20101b60(1);
  FUN_20101fa4(1,0);
  DAT_208004a2 = key_scan_first();
  if (DAT_2080049a == '\0') {
    FUN_20116660();
    FUN_201165f4();
  }
  gui_update_layers();
  iVar6 = FUN_2012f734();
  while (iVar6 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    iVar6 = FUN_20115060();
    if (iVar6 != 0) {
      for (; iVar7 * 0x21 < 0x9c5; iVar7 = iVar7 + 1) {
        itron_dly_tsk(3);
      }
      fwupdate_screen();
    }
    itron_dly_tsk(3);
    iVar7 = iVar7 + 1;
    if (4999 < iVar7 * 0x21) goto LAB_2012fb90;
    iVar6 = FUN_2012f734();
  }
  iVar6 = FUN_20115024(&local_4d8);
  while( true ) {
    uVar1 = local_4d8;
    uVar2 = local_4d6;
    uVar3 = local_4d4;
    if (iVar6 != 0) {
      for (; DAT_208007ec = uVar3, DAT_208007ea = uVar2, DAT_208007e8 = uVar1, iVar7 * 0x21 < 0x9c5;
          iVar7 = iVar7 + 1) {
        itron_dly_tsk(3);
        uVar1 = DAT_208007e8;
        uVar2 = DAT_208007ea;
        uVar3 = DAT_208007ec;
      }
      FUN_2011500c(local_288);
      if ((DAT_20800481 != 0) && (local_27a == '\0' || local_27a == -0x25)) {
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        memcpy(&local_48,auStack_1e1,0xc);
        FUN_201354ec(&local_48);
        FUN_20135ff0(local_38,&local_48,DAT_208004da,DAT_208004d8,0x10,&DAT_20800b1c);
        gui_update_layers();
        iVar7 = 0;
        if (DAT_20800481 != 0) {
          do {
            iVar7 = iVar7 + 1;
            itron_dly_tsk(100);
          } while (iVar7 < (int)(uint)DAT_20800481);
        }
      }
      FUN_2011500c(local_288);
      if ((local_288[0] == '`') &&
         ((local_27a == '\x01' || local_27a == '\x02') || local_27a == '\x03')) {
        FUN_201322ac();
      }
      FUN_20113d10();
      DAT_20800495 = 1;
      FUN_20112cc4();
      FUN_20133658(0,4,0,&local_34);
      FUN_20133658(1,4,0,&local_34);
      gui_update_layers();
      uVar4 = fb_get_layer_addr(DAT_208085b8);
      FUN_20155274(uVar4,0xbb800);
      gui_update_layers();
      FUN_201026e0(local_4d6._1_1_ & 0x7f);
      FUN_20113db8((byte)local_4d4 & 0x7f);
      memcpy(auStack_4c7,&DAT_208f0b2b,0x97);
      FUN_201120fc(&DAT_208f0b2b);
      FUN_2012e678(&uStack_4c8,0,1);
      FUN_201266ec(&local_4d8,&local_4d8,1);
      FUN_20101f8c((byte)local_4d8 & 4);
      FUN_2012e3e0(&DAT_208f0b2a,0,1);
      gui_update_layers();
      return;
    }
    itron_dly_tsk(3);
    iVar7 = iVar7 + 1;
    if (4999 < iVar7 * 0x21) break;
    iVar6 = FUN_20115024(&local_4d8);
  }
LAB_2012fb90:
  FUN_201322ac();
  return;
}


// ===== FUN_2012fd94 @ 2012fd94 (568 bytes)

void FUN_2012fd94(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 local_27c;
  undefined1 local_27a;
  undefined1 local_279;
  undefined1 local_278;
  short local_270;
  short local_26e;
  undefined2 local_26c;
  undefined2 local_26a;
  undefined1 auStack_268 [576];
  short *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  
  uVar1 = fb_get_layer_addr(0);
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar3 = fb_get_layer_addr(DAT_208085b8);
  iVar4 = 0;
  memclr(auStack_268,0x240);
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  fb_copy_rect(uVar3,0,0,800,0x1e0);
  fb_copy_rect(uVar2,0,0,800,0x1e0);
  gui_update_layers();
  fb_copy_rect(uVar1,0,0,800,0x1e0);
  fb_copy_rect(uVar3,0,0,800,0x1e0);
  fb_copy_rect(uVar2,0,0,800,0x1e0);
  gui_update_layers();
  FUN_201337f8(3);
  FUN_201337f8(5);
  local_26c = DAT_208004d4;
  local_270 = DAT_208004d6;
  local_26a = 0x1e6;
  local_27c = 0;
  local_26e = (DAT_208004da - DAT_208004d6) + 0x18;
  local_27a = 0;
  local_28 = &local_270;
  local_279 = 0;
  local_24 = &local_27c;
  local_278 = 0;
  local_20 = 0;
  FUN_20101c10(1);
  FUN_20133658(0,4,1,&local_28);
  FUN_20133658(1,4,1,&local_28);
  FUN_20133090(1);
  itron_dly_tsk(0x14);
  gui_draw_runs(uVar3,DAT_208004d6,DAT_208004d4,&DAT_2016d2c0);
  gui_update_layers();
  local_27c = 2;
  FUN_20133658(0,4,1,&local_28);
  FUN_20133658(1,4,1,&local_28);
  FUN_20101b60(1);
  FUN_20101fa4(1,0);
  FUN_2011668c();
  do {
    itron_dly_tsk(3);
    iVar4 = iVar4 + 1;
  } while (iVar4 * 0x21 < 0x9c5);
  FUN_20133658(0,4,0,&local_28);
  FUN_20133658(1,4,0,&local_28);
  gui_update_layers();
  return;
}


// ===== power_on_request @ 2012ffcc (88 bytes)

/* calls power_on_full_init [inference] */

void power_on_request(void)

{
  int iVar1;
  
  power_on_full_init();
  FUN_201026e0(100);
  iVar1 = key_scan_first();
  if (iVar1 != 6) {
    FUN_2012f8d4();
    DAT_20800486 = 0;
    DAT_208004c8 = 0;
    DAT_208004c6 = 0;
    DAT_2080049c = 0;
    return;
  }
  DAT_208dbb4c = 2;
  FUN_2012fd94();
  FUN_201322e4(&DAT_208dbb44);
  return;
}


// ===== FUN_20130024 @ 20130024 (324 bytes)

bool FUN_20130024(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_260;
  undefined4 local_25c;
  char local_258 [14];
  char local_24a;
  char local_1a5;
  
  iVar2 = 0;
  local_260 = 0;
  local_25c = 0;
  memclr(local_258,0x240);
  FUN_2011500c(local_258);
  DAT_2080049b = 1;
  itron_dly_tsk(0x14);
  FUN_201165f4();
  DAT_2080049b = 0;
  FUN_20113d10();
  iVar1 = FUN_2012f734();
  while (iVar1 == 0) {
    itron_dly_tsk(3);
    iVar2 = iVar2 + 1;
    if (4999 < iVar2 * 0x21) {
      return false;
    }
    iVar1 = FUN_2012f734();
  }
  FUN_2011500c(local_258);
  if (local_1a5 == '\x01') {
    DAT_2080049a = 1;
    return true;
  }
  iVar1 = FUN_20115024(&local_260);
  while (iVar1 == 0) {
    itron_dly_tsk(3);
    iVar2 = iVar2 + 1;
    if (4999 < iVar2 * 0x21) {
      return false;
    }
    iVar1 = FUN_20115024(&local_260);
  }
  DAT_208007e8 = (undefined2)local_260;
  local_260._2_2_ = (undefined2)((uint)local_260 >> 0x10);
  DAT_208007ea = local_260._2_2_;
  DAT_208007ec = (undefined2)local_25c;
  FUN_2011500c(local_258);
  if ((local_258[0] == '`') && ((local_24a == '\x01' || local_24a == '\x02') || local_24a == '\x03')
     ) {
    return false;
  }
  iVar2 = FUN_2011727c();
  return iVar2 != 0;
}


// ===== FUN_20130188 @ 20130188 (1044 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_20130188(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_8 [8];
  
  uVar1 = fb_get_layer_addr(5);
  iVar3 = 0;
  DAT_208004a2 = key_scan_first();
  iVar2 = key_scan_first();
  if (iVar2 == 6) {
    DAT_208dbb4c = 2;
    FUN_2012fd94();
    FUN_201322e4(&DAT_208dbb44);
    do {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      gui_update_layers();
      FUN_201525f8(0xffffffff);
    } while( true );
  }
  iVar2 = FUN_2011727c();
  if (iVar2 == 0) {
    iVar2 = FUN_20130024();
    if (iVar2 == 0) {
      DAT_20800493 = '\x01';
      goto LAB_20130238;
    }
    iVar2 = key_scan_first();
    if (iVar2 == 6) {
      FUN_201322ac();
      goto LAB_20130238;
    }
    if (DAT_2080049a != '\0') {
      power_on_request();
      goto LAB_20130238;
    }
  }
  FUN_2012f8d4();
LAB_20130238:
  iVar2 = FUN_20113f50();
  if (iVar2 != 0) {
    FUN_20133a38(6);
  }
  FUN_20135534(uVar1,0,0,&DAT_2016e860,0xc,0x13);
  while( true ) {
    if (DAT_20800494 != '\0') {
      iVar2 = FUN_20103bb0();
      if (iVar2 != 0) {
        DAT_20800495 = 0;
        FUN_201322f0();
        FUN_20155274(&DAT_208f0b2a,0x240);
        if (DAT_20800493 == '\0') {
          DAT_20800495 = 1;
          FUN_20120e9c(1,0x166,0);
          itron_dly_tsk(1);
          FUN_20120e9c(0,0x166);
        }
      }
      DAT_20800496 = 0;
      DAT_20800494 = '\0';
      DAT_20450027 = 0;
    }
    if (DAT_20800492 != '\x10') break;
    DAT_20800492 = -1;
    DAT_20800493 = '\x01';
LAB_201303a8:
    if (DAT_208000b1 == '\x01') {
      FUN_2010579c();
      DAT_20800490 = 0;
    }
    if (DAT_208000b2 == '\x01') {
      FUN_20105a20();
      DAT_2080048f = 0;
    }
    DAT_20800495 = 0;
    DAT_20800493 = '\0';
    DAT_20450027 = 0;
    DAT_2080049a = '\0';
    FUN_20117030();
    FUN_201121a8(0);
    iVar2 = FUN_20115024(auStack_8);
    if (iVar2 != 0) {
      DAT_208007e8._0_1_ = (byte)DAT_208007e8 & 0xfe;
      FUN_201266ec(&DAT_208007e8,auStack_8,0);
    }
    iVar2 = FUN_2011727c();
    while (iVar2 == 0) {
      FUN_201525f8(0xffffffff);
      iVar2 = FUN_2011727c();
    }
    DAT_20800496 = 0;
    power_on_request();
    if (DAT_20800493 == '\0') {
LAB_20130450:
      FUN_2012ebb8();
      if (DAT_208004d0 == '\x03') {
        if (DAT_208f4632 == '\0') {
          FUN_2012470c();
        }
      }
      else if ((DAT_20800483 == '\0') && (DAT_208f0b2a != 'z')) {
        FUN_20124528();
        FUN_201244d8();
      }
      if (DAT_20800484 == '\0') {
        if (DAT_208f4633 == '\0') {
          FUN_201233d4();
        }
        else {
          FUN_20123c04();
        }
      }
      if (DAT_208004a0 != '\0') {
        DAT_208004a0 = DAT_208004a0 + -1;
      }
      FUN_20121e88();
      FUN_20134abc();
      FUN_20121d90();
      FUN_20121d00();
      FUN_201217b0();
      if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
        FUN_20121c3c();
      }
      else {
        FUN_201218a4();
      }
      FUN_20131638();
      FUN_20121988(&DAT_20800838);
      iVar3 = iVar3 + DAT_20800838;
      if (DAT_208004a2 == '\x04') {
        FUN_201121a8(1);
      }
      fb_get_layer_addr(DAT_208085bc);
      sdr_spi_stats_print();
      FUN_201367b4(iVar3);
      FUN_20121988(&DAT_20800838);
      gui_update_layers();
      FUN_20121988(&DAT_20800838);
      iVar3 = DAT_20800838;
      FUN_201525f8(0xffffffff);
      FUN_20121988(&DAT_20800838);
      _DAT_208f4bf0 = _DAT_208f4bf0 + 1;
    }
  }
  if (DAT_20800492 == '\x11') {
    DAT_20800492 = -1;
    if (DAT_208000b1 == '\x01') {
      FUN_2010579c();
      DAT_20800490 = 0;
    }
    if (DAT_208000b2 == '\x01') {
      FUN_20105a20();
      DAT_2080048f = 0;
    }
    DAT_20800495 = 0;
    FUN_20116da0(0);
    FUN_20101fa4(0);
    FUN_20102040(0);
    FUN_20101b60(0);
    FUN_20101c10(0);
    FUN_201121a8(0);
    DAT_2080049a = '\0';
    itron_dly_tsk(200);
    DAT_2080049c = 0;
    DAT_20800497 = 1;
    power_on_request();
  }
  if (DAT_20800493 != '\0') goto LAB_201303a8;
  goto LAB_20130450;
}


// ===== screen_shot_menu @ 2013059c (384 bytes)

void screen_shot_menu(void)

{
  short *psVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  psVar1 = DAT_20802ce4;
  if (DAT_20802ce4 != (short *)0x0) {
    fb_fill_rect(uVar2,0x821,DAT_2080278e + 2,DAT_2080278c + 2,*DAT_20802ce4 + -4,
                 DAT_20802ce4[1] + -4);
    gui_draw_runs(uVar2,DAT_2080278e,DAT_2080278c,psVar1);
    FUN_20135aa4(uVar2,DAT_2080278e,DAT_2080278c + 6,*psVar1 + -0xc,2,0x632c);
    FUN_20135aa4(uVar2,DAT_2080278e + psVar1[1] + -2,DAT_2080278c + 6,*psVar1 + -0xc,2,0x632c);
    if (DAT_20802890 != 0) {
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      memcpy(&local_28,DAT_20802b9c,DAT_20802c1c);
      FUN_20135dd4(uVar2,&local_28,DAT_2080278e + DAT_20802892,DAT_2080278c + DAT_20802890,0x22,
                   &DAT_208015bc);
    }
  }
  return;
}


// ===== FUN_2013071c @ 2013071c (76 bytes)

undefined4 FUN_2013071c(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (((((int)param_2 < (int)(*(ushort *)(&DAT_2016d61c + param_1 * 4) - 10)) ||
       (*(ushort *)(&DAT_2016d61c + param_1 * 4) + 0x3c <= param_2)) ||
      ((int)param_3 < (int)(*(ushort *)(&DAT_2016d61e + param_1 * 4) - 10))) ||
     (*(ushort *)(&DAT_2016d61e + param_1 * 4) + 0x3c <= param_3)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_20130768 @ 20130768 (420 bytes)

void FUN_20130768(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_2c [20];
  undefined4 local_18;
  undefined2 uVar2;
  
  local_18 = 0xe5;
  uVar1 = (undefined2)param_1;
  uVar2 = (undefined2)param_2;
  switch(DAT_2080049f) {
  case '\x01':
    iVar3 = FUN_2013071c(DAT_2080049f,param_1,param_2);
    if (iVar3 != 0) {
      DAT_2080049f = DAT_2080049f + '\x01';
      DAT_208f120c = uVar1;
      DAT_208f120e = uVar2;
      touch_calibration();
    }
    break;
  case '\x02':
    iVar3 = FUN_2013071c(DAT_2080049f,param_1,param_2);
    if (iVar3 != 0) {
      DAT_2080049f = DAT_2080049f + '\x01';
      DAT_208f1210 = uVar1;
      DAT_208f1212 = uVar2;
      touch_calibration();
      return;
    }
    break;
  case '\x03':
    iVar3 = FUN_2013071c(DAT_2080049f,param_1,param_2);
    if (iVar3 != 0) {
      DAT_2080049f = DAT_2080049f + '\x01';
      DAT_208f1214 = uVar1;
      DAT_208f1216 = uVar2;
      touch_calibration();
      return;
    }
    break;
  case '\x04':
    iVar3 = FUN_2013071c(DAT_2080049f,param_1,param_2);
    if (iVar3 != 0) {
      DAT_2080049f = DAT_2080049f + '\x01';
      DAT_208f1218 = uVar1;
      DAT_208f121a = uVar2;
      touch_calibration();
      return;
    }
    break;
  case '\x05':
    iVar3 = FUN_2013071c(DAT_2080049f,param_1,param_2);
    if (iVar3 != 0) {
      FUN_20133870(5);
      uVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_copy_rect(uVar4,0,0,800,0x1e0);
      gui_update_layers();
      DAT_208f121c = uVar1;
      DAT_208f121e = uVar2;
      memcpy(auStack_2c,&DAT_2016d638,0x14);
      FUN_20102fd0(0,auStack_2c);
      FUN_20102fd0(1,&DAT_208f120c);
      mainlink_queue_frame(&local_18,4);
      DAT_2080049f = 0;
      return;
    }
  }
  return;
}


// ===== FUN_20130968 @ 20130968 (48 bytes)

void FUN_20130968(void)

{
  if (DAT_208f1220 != '\0') {
    if (DAT_208f1220 == '\x01' || DAT_208f1220 == -1) {
      DAT_208f1221 = DAT_208f1220;
    }
    return;
  }
  DAT_208f1221 = 0;
  return;
}


// ===== FUN_20130998 @ 20130998 (12 bytes)

undefined1 FUN_20130998(void)

{
  return DAT_208f4637;
}


// ===== FUN_201309b4 @ 201309b4 (12 bytes)

undefined1 FUN_201309b4(void)

{
  return DAT_20800493;
}


// ===== FUN_201309c0 @ 201309c0 (604 bytes)

void FUN_201309c0(undefined4 param_1,uint param_2)

{
  short sVar1;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_40 = fb_get_layer_addr(DAT_208085bc);
  local_38 = 0x33323130;
  uStack_34 = 0x37363534;
  uStack_30 = 0x42413938;
  uStack_2c = 0x46454443;
  DAT_20800497 = 0;
  fb_fill_rect(local_40,0x821,DAT_208027de + 2,DAT_208027dc + 2,0x1e8,0x54);
  gui_draw_runs(local_40,DAT_208027de,DAT_208027dc,&DAT_2016e248);
  FUN_20135aa4(local_40,DAT_208027de,DAT_208027dc + 6,0x1e0,2,0x632c);
  FUN_20135aa4(local_40,DAT_208027de + 0x56,DAT_208027dc + 6,0x1e0,2,0x632c);
  if (DAT_208028e0 != 0) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    memcpy(&local_50,DAT_20802bec,DAT_20802c30);
    FUN_20135dd4(local_40,&local_50,DAT_208027de + DAT_208028e2,DAT_208027dc + DAT_208028e0,0x22,
                 &DAT_208015bc);
  }
  sVar1 = DAT_208029e4;
  if (DAT_208029e4 != 0) {
    FUN_2015525c(&local_50,0xd,0x20);
    local_48 = CONCAT13(*(undefined1 *)((int)&local_38 + (param_2 & 0xf)),
                        CONCAT12(*(undefined1 *)((int)&local_38 + (param_2 >> 4)),
                                 CONCAT11(0x20,(undefined1)local_48)));
    local_44 = CONCAT31(local_44._1_3_,0x68);
    if (DAT_208028e0 == 0) {
      FUN_20135ff0(local_40,&local_50,DAT_208027de + DAT_208029e6,DAT_208027dc + sVar1,0x22,
                   &DAT_208015bc);
      return;
    }
    sVar1 = FUN_20155122(&local_50);
    FUN_20135dd4(local_40,&local_50,DAT_208027de + DAT_208029e6,
                 (DAT_208027dc + 0x1ec + sVar1 * -0x22) - DAT_208029e4,0x22,&DAT_208015bc);
  }
  return;
}


// ===== FUN_20130c40 @ 20130c40 (12 bytes)

void FUN_20130c40(undefined1 param_1)

{
  DAT_20800492 = param_1;
  return;
}

