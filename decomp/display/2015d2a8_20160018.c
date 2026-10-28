// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2015d2a8 @ 2015d2a8 (92 bytes)

void FUN_2015d2a8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
    DAT_208084cc = 0xb5bf;
    return;
  case 2:
  case 8:
    DAT_208084cc = 0xffff;
    break;
  case 3:
  case 10:
    DAT_208084cc = 0xfef0;
    break;
  default:
    DAT_208084cc = 0xb5bf;
    break;
  case 5:
    DAT_208084cc = 0xfdb6;
    break;
  case 6:
    DAT_208084cc = 0xe71f;
    break;
  case 7:
    DAT_208084cc = 0xfe1f;
    break;
  case 9:
    DAT_208084cc = 0x6fed;
  }
  return;
}


// ===== FUN_2015d334 @ 2015d334 (128 bytes)

void FUN_2015d334(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  FUN_2015dc90(uVar1,0x145,0x195,0x187,param_1);
  FUN_20120d90();
  FUN_2015da3c(uVar1,0x16d,0x195,0x187,0x27);
  FUN_2015d650(uVar1,0x145,4,0,0x4f,param_1);
  return;
}


// ===== FUN_2015d3b8 @ 2015d3b8 (212 bytes)

void FUN_2015d3b8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 0;
    iVar3 = 100;
  }
  else {
    iVar2 = 3;
    iVar3 = 0x85;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d49c @ 2015d49c (104 bytes)

void FUN_2015d49c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0xba;
    iVar3 = 0xba;
  }
  else {
    uVar2 = 0xf0;
    iVar3 = 0xf0;
  }
  FUN_2015d70c(uVar1,0x192 - iVar3,4,0x317,uVar2,8,param_2,0x1e);
  return;
}


// ===== FUN_2015d508 @ 2015d508 (208 bytes)

void FUN_2015d508(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 6;
    iVar3 = 0x2a;
  }
  else {
    iVar2 = 7;
    iVar3 = 0x4b;
  }
  FUN_2015db80(uVar1,((0x11c - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x11c - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d5e8 @ 2015d5e8 (100 bytes)

void FUN_2015d5e8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0x50;
    iVar3 = 0x50;
  }
  else {
    uVar2 = 0x90;
    iVar3 = 0x90;
  }
  FUN_2015d70c(uVar1,0x11c - iVar3,4,0x317,uVar2,9,param_2,0xf);
  return;
}


// ===== FUN_2015d650 @ 2015d650 (188 bytes)

void FUN_2015d650(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_338 [788];
  
  iVar3 = 0;
  FUN_20120da4(param_6,local_338);
  iVar4 = param_3 + 0x187;
  for (; param_3 < iVar4; param_3 = param_3 + 1) {
    iVar1 = 1;
    if (0 < param_5) {
      iVar2 = param_2 * 800;
      do {
        if ((iVar1 < (int)(uint)local_338[iVar3 * 2 + 1]) ||
           ((int)(uint)local_338[iVar3 * 2] < iVar1)) {
          *(undefined2 *)(param_1 + (param_3 + iVar2) * 2) = 0;
        }
        else {
          *(undefined2 *)(param_1 + (param_3 + iVar2) * 2) = 0x65f;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 800;
      } while (iVar1 <= param_5);
    }
    iVar3 = iVar3 + 1;
  }
  return;
}


// ===== FUN_2015d70c @ 2015d70c (360 bytes)

void FUN_2015d70c(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 ushort *param_7,int param_8)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  byte abStack_708 [800];
  undefined2 local_3e8 [240];
  undefined2 local_208 [242];
  
  iVar2 = FUN_2013437c(param_6,abStack_708);
  iVar3 = FUN_20134398(param_6);
  iVar8 = *(int *)(iVar2 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  iVar3 = (uint)*param_7 - param_3;
  uVar1 = param_7[1];
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar5 = iVar2 * param_8;
      puVar6 = local_3e8 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar8 + iVar5 * 2);
    } while (iVar2 < param_5);
  }
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar8 = iVar2 * param_8;
      puVar6 = local_208 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar4 + iVar8 * 2);
    } while (iVar2 < param_5);
  }
  iVar4 = 0;
  iVar2 = param_3;
  if (0 < param_4) {
    do {
      bVar9 = SBORROW4(iVar3,iVar4);
      iVar8 = iVar3 - iVar4;
      if (iVar3 <= iVar4) {
        bVar9 = SBORROW4(iVar4,(uint)uVar1 + iVar3);
        iVar8 = iVar4 - ((uint)uVar1 + iVar3);
      }
      iVar5 = param_5 - (uint)abStack_708[iVar4 + param_3];
      iVar7 = (param_2 + iVar5) * 800;
      if (iVar8 < 0 == bVar9) {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_3e8[iVar5];
        }
      }
      else {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_208[iVar5];
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar4 < param_4);
  }
  return;
}


// ===== FUN_2015d874 @ 2015d874 (212 bytes)

void FUN_2015d874(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 1;
    iVar3 = 0x3c;
  }
  else {
    iVar2 = 4;
    iVar3 = 0x3f;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015d958 @ 2015d958 (212 bytes)

void FUN_2015d958(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 2;
    iVar3 = 0x8c;
  }
  else {
    iVar2 = 5;
    iVar3 = 0xd5;
  }
  FUN_2015db80(uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
               (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    FUN_20134414(DAT_208084d2);
  }
  FUN_20156260(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  FUN_2015da9c(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== FUN_2015da3c @ 2015da3c (96 bytes)

void FUN_2015da3c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  
  while (param_5 = param_5 + -1, -1 < param_5) {
    uVar1 = FUN_20120d98(param_5);
    fb_blit_raw(param_1,param_2 + param_5 & 0xffff,param_3,uVar1,param_4,1);
  }
  return;
}


// ===== FUN_2015da9c @ 2015da9c (228 bytes)

void FUN_2015da9c(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  
  if ((param_5 & 1) != 0) {
    iVar1 = FUN_20134434(param_5 >> 1);
    fb_blit_raw(param_1,param_2 + (param_5 >> 1) * 2 & 0xffff,param_3,iVar1 + param_3 * 2,param_4,1)
    ;
  }
  param_5 = param_5 >> 1;
  fb_fill_box(param_1,param_2 - 1U & 0xffff,param_3,param_4,1,0);
  while (param_5 = param_5 - 1, -1 < (int)param_5) {
    iVar1 = FUN_20134434(param_5);
    uVar2 = param_2 + param_5 * 2;
    iVar1 = iVar1 + param_3 * 2;
    fb_blit_raw(param_1,uVar2 & 0xffff,param_3,iVar1,param_4,1);
    fb_blit_raw(param_1,uVar2 + 1 & 0xffff,param_3,iVar1,param_4,1);
  }
  return;
}


// ===== FUN_2015db80 @ 2015db80 (268 bytes)

void FUN_2015db80(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 ushort *param_7)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte abStack_348 [800];
  int local_28;
  
  FUN_2013437c(param_6,abStack_348);
  uVar2 = DAT_208084cc;
  param_4 = param_4 + param_3;
  iVar1 = param_3 + -0x348;
  iVar8 = 0;
  iVar7 = (uint)*param_7 - param_3;
  local_28 = (uint)param_7[1] + iVar7;
  if (param_3 < param_4) {
    do {
      if ((iVar8 < iVar7) || (local_28 <= iVar8)) {
        iVar4 = 0;
        iVar3 = param_2 * 800;
        if (0 < param_5) {
          do {
            iVar9 = param_5 - iVar4;
            iVar4 = iVar4 + 1;
            iVar5 = param_3 + iVar3;
            iVar3 = iVar3 + 800;
            puVar6 = (undefined2 *)(param_1 + iVar5 * 2);
            if ((int)(uint)abStack_348[iVar8 + iVar1 + 0x348] < iVar9) {
              *puVar6 = 0;
            }
            else {
              *puVar6 = uVar2;
            }
          } while (iVar4 < param_5);
        }
      }
      else {
        iVar4 = 0;
        iVar3 = param_2 * 800;
        if (0 < param_5) {
          do {
            iVar9 = param_5 - iVar4;
            iVar4 = iVar4 + 1;
            iVar5 = param_3 + iVar3;
            iVar3 = iVar3 + 800;
            puVar6 = (undefined2 *)(param_1 + iVar5 * 2);
            if ((int)(uint)abStack_348[iVar8 + iVar1 + 0x348] < iVar9) {
              *puVar6 = 0;
            }
            else {
              *puVar6 = uVar2;
            }
          } while (iVar4 < param_5);
        }
      }
      param_3 = param_3 + 1;
      iVar8 = iVar8 + 1;
    } while (param_3 < param_4);
  }
  return;
}


// ===== FUN_2015dc90 @ 2015dc90 (156 bytes)

void FUN_2015dc90(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  byte local_1b0 [396];
  
  iVar2 = FUN_20120d60(param_5,local_1b0);
  param_2 = param_2 * 800;
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar4 = 0;
      if (param_3 < param_4 + param_3) {
        iVar3 = param_3;
        do {
          pbVar1 = local_1b0 + iVar4;
          iVar4 = iVar4 + 1;
          iVar6 = iVar3 + param_2;
          iVar3 = iVar3 + 1;
          puVar7 = (undefined2 *)(param_1 + iVar6 * 2);
          if ((int)(uint)*pbVar1 < iVar2 - iVar5) {
            *puVar7 = 0;
          }
          else {
            *puVar7 = 0x529b;
          }
        } while (iVar3 < param_4 + param_3);
      }
      iVar5 = iVar5 + 1;
      param_2 = param_2 + 800;
    } while (iVar5 < iVar2);
  }
  return;
}


// ===== mainlink_valid_7f @ 2015e16c (28 bytes)

/* byte & 0x7F <= 12 or == 0x7F */

undefined4 mainlink_valid_7f(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((0xc < (param_2 & 0x7f)) && ((param_2 & 0x7f) != 0x7f)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== mainlink_status_valid @ 2015e354 (928 bytes)

/* range checks of the 0x97-byte radio status block */

undefined4
mainlink_status_valid(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  if ((((((*param_2 < 2) && (param_2[1] < 0xc)) && ((~param_2[2] & 3) != 0)) &&
       ((((~param_2[6] & 0x30) != 0 && ((~param_2[9] & 0x70) != 0)) &&
        (((param_2[10] & 7) < 6 &&
         (((param_2[0xb] & 0xf) >> 2 != 3 && ((param_2[0xb] & 0x3f) >> 4 != 3)))))))) &&
      (((param_2[0xc] & 7) < 5 &&
       ((((((((~param_2[0xe] & 0x18) != 0 && (~param_2[0xe] & 3) != 0 && ((param_2[0xf] & 7) < 5))
            && ((param_2[0x11] & 0xf) < 0xb)) &&
           ((uVar5 = (uint)param_2[0x19] + (uint)param_2[0x18] * 0x100 & 0xffff7fff, uVar5 != 0 &&
            (uVar5 < 0x141)))) &&
          (uVar2 = (ushort)param_2[0x1b] + (ushort)param_2[0x1a] * 0x100, uVar2 != 0)) &&
         ((uVar2 < 0x141 && (((uint)param_2[0x13] + (uint)param_2[0x12] * 0x100) - 0x32 < 0x3e4f))))
        && ((((uint)param_2[0x1d] + (uint)param_2[0x1c] * 0x100) - 0x32 < 0x3e4f &&
            (((sVar3 = (ushort)param_2[0x1f] + (ushort)param_2[0x1e] * 0x100,
              (int)sVar3 + 0x4b0U < 0x961 && ((int)(char)param_2[0x20] + 0x19U < 0x33)) &&
             (param_2[0x21] - 0x1e < 0x4c)))))))))) &&
     ((param_2[0x23] >> 4 < 3 && ((param_2[0x23] & 0xf) < 5)))) {
    iVar4 = mainlink_valid_7f(param_1,param_2[0x24],(uint)param_2[0x1c],param_4,sVar3);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x25]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x26]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x27]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x28]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_7f(param_1,param_2[0x29]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_code(param_1,param_2[0x2a]);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = mainlink_valid_code(param_1,param_2[0x2b]);
    if (iVar4 == 0) {
      return 0;
    }
    if ((param_2[0x2c] < 0xf) && (bVar1 = param_2[0x2d], bVar1 < 0xb)) {
      if (bVar1 == 2) {
        if (0x74 < param_2[0x2e]) {
          return 0;
        }
      }
      else if (bVar1 == 5) {
        if (9 < param_2[0x2e] - 200) {
          return 0;
        }
      }
      else if (bVar1 == 7) {
        if (0xe < param_2[0x2e] - 0x96) {
          return 0;
        }
      }
      else if ((bVar1 == 8) && (param_2[0x2e] != 199)) {
        return 0;
      }
      if (((((param_2[0x2f] & 0xf) < 0xc) &&
           ((int)(short)((ushort)param_2[0x43] + (ushort)param_2[0x42] * 0x100) + 9999U < 19999)) &&
          (param_2[0x45] < 0xf)) && (bVar1 = param_2[0x46], bVar1 < 0xb)) {
        if (bVar1 == 2) {
          if (0x74 < param_2[0x47]) {
            return 0;
          }
        }
        else if (bVar1 == 5) {
          if (9 < param_2[0x47] - 200) {
            return 0;
          }
        }
        else if (bVar1 == 7) {
          if (0xe < param_2[0x47] - 0x96) {
            return 0;
          }
        }
        else if ((bVar1 == 8) && (param_2[0x47] != 199)) {
          return 0;
        }
        if ((param_2[0x48] & 0xf) < 0xc) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ===== mainlink_rx_validate @ 2015e6f4 (2324 bytes)

/* per-command range checks; 0x7F with the 8-byte key enters maintenance mode */

bool mainlink_rx_validate(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  
  bVar2 = *param_2;
  if (bVar2 == 0x45) {
    return true;
  }
  if (bVar2 < 0x46) {
    if (bVar2 == 0x3f) {
      return param_2[1] < 2;
    }
    if (bVar2 < 0x40) {
      if (bVar2 == 0x1b) {
        return true;
      }
      if (bVar2 == 0x21) {
        return param_2[2] < 8;
      }
      if (bVar2 == 0x23) {
        return (param_2[1] & 0x3f) < 0x33;
      }
      if (bVar2 == 0x33) {
        return true;
      }
    }
    else if ((bVar2 == 0x42 || bVar2 == 0x43) || bVar2 == 0x44) {
      return true;
    }
  }
  else {
    if (bVar2 == 0x7a) {
      return true;
    }
    if (bVar2 < 0x7b) {
      if (bVar2 == 0x60) {
        uVar4 = (uint)param_2[0xe] + (uint)param_2[0xd] * 0x100;
        if (4 < uVar4) {
          if (uVar4 == 0xdb) {
            DAT_20450029 = 1;
            goto LAB_2015dd64;
          }
          if (uVar4 != 0xff) {
            return false;
          }
        }
        DAT_20450029 = 0;
LAB_2015dd64:
        iVar5 = mainlink_status_valid(param_1,param_2 + 0xf);
        return iVar5 != 0;
      }
      if (bVar2 == 100) {
        return param_2[1] < 6;
      }
      if (bVar2 == 0x65) {
        iVar5 = bcd_to_bin(param_2[1]);
        if (((((iVar5 < 100) && (bVar2 = bcd_to_bin(param_2[2]), bVar2 != 0)) && (bVar2 < 0xd)) &&
            ((bVar2 = bcd_to_bin(param_2[3]), bVar2 != 0 && (bVar2 < 0x20)))) &&
           ((bVar2 = bcd_to_bin(param_2[4]), bVar2 < 0x18 &&
            (bVar2 = bcd_to_bin(param_2[5]), bVar2 < 0x3c)))) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        return bVar3;
      }
      if (bVar2 == 0x71) {
        if ((param_2[1] - 3 < 0x7e) || (0x82 < param_2[1])) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        return bVar3;
      }
    }
    else {
      if (bVar2 == 0x7b) {
        return param_2[1] < 2;
      }
      if (bVar2 == 0x7c) {
        return true;
      }
      if (bVar2 == 0x7f) {
        bVar2 = param_2[1];
        if (bVar2 != 0x10) {
          if (bVar2 < 0x11) {
            if (2 < bVar2) {
              return false;
            }
            return true;
          }
          if (bVar2 != 0x11) {
            if (bVar2 != 0x80) {
              return false;
            }
            return true;
          }
        }
        iVar5 = FUN_2015507c(param_2 + 2,&DAT_20450285,8);
        if (iVar5 != 0) {
          return false;
        }
        DAT_2080049c = 1;
        DAT_20800495 = 0;
        mainlink_tx_reset();
        mainlink_set_power_cmd(bVar2);
        return true;
      }
    }
  }
  iVar5 = mainlink_status_valid(param_1,param_2 + 1);
  if (iVar5 == 0) {
    return false;
  }
  bVar2 = *param_2;
  if (bVar2 == 0x39) {
    if ((((param_2[0xb4] < 0xb) && (param_2[0xb5] == 0)) && (param_2[0xb7] < 0x65)) &&
       ((param_2[0xb8] < 0x65 && (iVar5 = be16_load(param_2 + 0xba), iVar5 < 10000)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    return bVar3;
  }
  if (0x39 < bVar2) {
    if (bVar2 == 0x50) {
      if ((param_2[0x98] >> 4 < 5) && ((param_2[0x98] & 0xf) < 3)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      return bVar3;
    }
    if (bVar2 < 0x51) {
      if (bVar2 == 0x3a) {
        switch(param_2[0x98]) {
        case 0:
        case 4:
          break;
        case 1:
          if (4 < (param_2[0x9d] & 0xf)) {
            return false;
          }
          if (4 < (param_2[0x9e] & 0xf)) {
            return false;
          }
          break;
        case 2:
          if (3 < param_2[0x9d]) {
            return false;
          }
          if (5 < param_2[0x9e]) {
            return false;
          }
          break;
        case 3:
          if (3 < param_2[0x9d]) {
            return false;
          }
          break;
        default:
          return false;
        }
        return true;
      }
      if (bVar2 == 0x40) {
        if ((param_2[0x98] < 2) && (param_2[0x99] != 0)) {
          bVar2 = param_2[0x9b] >> 4;
          if ((((bVar2 != 0) && ((bVar2 < 6 && ((param_2[0x9b] & 0xf) < 5)))) &&
              (param_2[0x9c] >> 4 < 8)) && ((param_2[0x9c] & 0xf) < 5)) {
            if (param_2[0x98] == 0) {
              iVar5 = 0;
              do {
                if (0x19 < param_2[iVar5 * 0x2d + 0x11a]) {
                  return false;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < 5);
            }
            return true;
          }
        }
        return false;
      }
      if (bVar2 == 0x41) {
        if ((param_2[0x98] & 0x40) == 0) {
          if ((param_2[0x99] & 0xf) < 4) {
            return true;
          }
        }
        else if (param_2[0x99] >> 4 < 6) {
          return true;
        }
        return false;
      }
    }
    else {
      if (bVar2 == 0x62) {
        return (param_2[0x98] & 0xf) < 9;
      }
      if (bVar2 == 0x70) {
        if (((param_2[0x98] < 4) && (param_2[0x99] < 5)) && (param_2[0x9a] < 2)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        return bVar3;
      }
    }
    return false;
  }
  if (bVar2 == 0x31) {
    switch(param_2[0x98]) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x37:
    case 0x3a:
    case 0x40:
      return true;
    default:
      return false;
    }
  }
  if (0x31 < bVar2) {
    if (bVar2 == 0x34) {
      return param_2[0x99] < 100 && param_2[0x98] < 2;
    }
    if (bVar2 == 0x37) {
      if ((param_2[0x99] < 0x2a) && (param_2[0x9a] < 0x2a)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      return bVar3;
    }
    return false;
  }
  if (bVar2 == 0x20) {
    return true;
  }
  if (bVar2 == 0x24) {
    if (((((param_2[0x99] & 0xf) < 0xb) && ((param_2[0x9a] & 0x1f) < 0x15)) &&
        ((param_2[0x9b] & 0x7f) < 0x65)) &&
       (((param_2[0x9c] & 0x7f) < 0x65 && ((param_2[0x9d] & 0x1f) < 0x15)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    return bVar3;
  }
  if (bVar2 != 0x30) {
    return false;
  }
  uVar4 = (uint)param_2[0x99];
  bVar2 = param_2[0x9b];
  bVar1 = param_2[0x98];
  if (bVar1 != 7) {
    if (bVar1 < 8) {
      switch(bVar1) {
      case 0:
        goto joined_r0x2015e0ec;
      case 1:
        if (3 < uVar4) {
          return false;
        }
        break;
      case 2:
joined_r0x2015e084:
        if (2 < uVar4) {
          return false;
        }
        break;
      case 3:
        if (1 < uVar4) {
          return false;
        }
        break;
      case 4:
        if (4 < uVar4) {
          return false;
        }
        break;
      case 5:
        if (0xf < uVar4) {
          return false;
        }
        break;
      case 6:
        if (9 < uVar4) {
          return false;
        }
        break;
      default:
        goto switchD_2015dfdc_default;
      }
    }
    else if (bVar1 == 0xb) {
      if (10 < (uVar4 & 0xf)) {
        return false;
      }
    }
    else if (bVar1 < 0xc) {
      if (bVar1 != 8) {
        if (bVar1 == 9) goto joined_r0x2015e084;
        if (bVar1 != 10) {
          return false;
        }
        if (2 < param_2[0x99] >> 6) {
          return false;
        }
        if (2 < (uVar4 & 0x3f) >> 4) {
          return false;
        }
        uVar4 = uVar4 & 0xf;
joined_r0x2015e0ec:
        if (5 < uVar4) {
          return false;
        }
      }
    }
    else if (bVar1 == 0xc) {
      if (0xb < uVar4) {
        return false;
      }
    }
    else {
      if (bVar1 == 0xd) goto joined_r0x2015e0ec;
      if (bVar1 != 0xff) {
        return false;
      }
    }
  }
  if ((bVar1 == 1 || bVar1 == 2) || (bVar1 == 3 || bVar1 == 4)) {
    if (1 < param_2[0x9a]) {
      return false;
    }
  }
  else if (param_2[0x9a] != 0) {
    return false;
  }
  if (bVar1 == 5) {
    if (bVar2 < 0x10) {
      return true;
    }
  }
  else if ((bVar1 == 0xb) || (bVar1 == 0xc)) {
    if (bVar2 < 0xc) {
      return true;
    }
  }
  else if (bVar2 == 0) {
    return true;
  }
switchD_2015dfdc_default:
  return false;
}


// ===== mainlink_rx_deliver @ 2015e9b8 (164 bytes)

/* trace, 'D'/'E' block handlers, else post to the dispatcher */

undefined4 mainlink_rx_deliver(int param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uStack_120;
  char cStack_11f;
  char cStack_11e;
  char cStack_11d;
  undefined4 uStack_11c;
  undefined1 auStack_118 [256];
  
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  if (*param_2 != '\x06' && *param_2 != '\x15') {
    mainlink_trace(param_2,param_3);
    *(char *)(param_1 + 0x24) = *param_2;
  }
  if (*param_2 == 'D') {
    uVar1 = be16_load(param_2 + 2);
    uVar1 = uVar1 & 0xffff;
    uVar2 = be16_load(param_2 + 4);
    if (((uVar1 < DAT_208116a2) && (uVar3 = uVar1 + (uVar2 & 0xffff), uVar3 <= DAT_208116a2)) &&
       (DAT_208116a0 == param_2[1])) {
      DAT_208116a4 = (undefined2)uVar3;
      memclr(auStack_118,0xfe);
      _uStack_120 = CONCAT13(param_2[3],CONCAT12(param_2[2],CONCAT11(param_2[1],0xc4)));
      uStack_11c = (uint)*(ushort *)(param_2 + 4);
      memcpy((int)&uStack_11c + 2,&DAT_208116a6 + uVar1,uVar2 & 0xffff);
      mainlink_queue_frame(&uStack_120,0x106);
      return 1;
    }
    return 0;
  }
  if (*param_2 != 'E') {
    iVar4 = mainlink_disp_alloc(*(undefined4 *)(param_1 + 0x18));
    *(undefined2 *)(iVar4 + 4) = 0xaa;
    *(short *)(iVar4 + 6) = (short)param_3;
    memcpy(iVar4 + 8,param_2,param_3);
    uVar5 = FUN_20162d3c(*(int *)(param_1 + 0x18),*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x819c)
                         ,iVar4);
    return uVar5;
  }
  uVar1 = be16_load(param_2 + 2);
  uVar1 = uVar1 & 0xffff;
  uVar2 = be16_load(param_2 + 4);
  if (((uVar1 < DAT_208116a2) && (uVar2 = uVar1 + (uVar2 & 0xffff), uVar2 <= DAT_208116a2)) &&
     (DAT_208116a0 == param_2[1])) {
    DAT_208116a4 = (undefined2)uVar2;
    memcpy(&DAT_208116a6 + uVar1,param_2 + 6);
    mainlink_queue_frame(&stack0xffffffe8,6);
    return 1;
  }
  return 0;
}


// ===== mainlink_valid_code @ 2015eb3c (56 bytes)

/* small code-set check used by mainlink_status_valid */

undefined4 mainlink_valid_code(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_2 - 0x16 < 4) ||
     (((0x21 < param_2 && (param_2 != 0x2d && param_2 != 0x36)) &&
      (param_2 != 0x3a && param_2 != 0xff)))) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== mainlink_rx_bind @ 2015eb74 (12 bytes)

/* (uart, tx, dispatcher) */

void mainlink_rx_bind(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


// ===== mainlink_rx_clear_stats @ 2015eb80 (16 bytes)

void mainlink_rx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== mainlink_rx_parse @ 2015eb90 (168 bytes)

/* first byte: 06/15/1B single byte; else table lookup 0x20450074 */

int mainlink_rx_parse(undefined4 param_1,char *param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *param_2;
  if (cVar1 == '\x06') {
    if (DAT_20450028 == '\0') {
      DAT_20450028 = '\x01';
    }
  }
  else if (cVar1 != '\x15' && cVar1 != '\x1b') {
    uVar2 = 0;
    do {
      if ((&DAT_20450074)[uVar2 * 0xc] == cVar1) {
        iVar3 = mainlink_rx_frame(param_1,&DAT_20450074 + uVar2 * 0xc,param_2,param_3);
        if (iVar3 == 0) {
          *param_4 = &DAT_20450074 + uVar2 * 0xc;
        }
        return iVar3;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x2b);
    return param_3;
  }
  mainlink_rx_deliver(param_1,param_2,1);
  return 1;
}


// ===== task_mainlink_rx @ 2015ec40 (512 bytes)

/* task "uart" pri 3: reads SCIF5, re-assembles frames, NAK after 3 empty reads */

void task_mainlink_rx(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  int local_534;
  undefined1 auStack_530 [1024];
  undefined1 auStack_130 [256];
  uint local_30 [2];
  
  memclr(auStack_130,0x100);
  memclr(auStack_530,0x400);
  uVar3 = 0;
  uVar5 = 0xffffffff;
  local_534 = 0;
  mainlink_rx_clear_stats(param_1);
  uVar4 = 0;
LAB_2015ec90:
  while (iVar1 = itron_twai_flg(*(undefined4 *)(param_1 + 0x34),0xc001,5,local_30,uVar5),
        iVar1 != -0x32) {
    if (iVar1 != 0) {
      return;
    }
    if ((local_30[0] & 0xc000) == 0) goto LAB_2015ed10;
    uVar5 = 0xffffffff;
    uVar3 = 0;
    local_534 = 0;
  }
  goto joined_r0x2015ece4;
LAB_2015ed10:
  if ((local_30[0] & 1) != 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                      (*(int **)(param_1 + 0x10),auStack_130,0x100);
    if (iVar1 == 0) {
joined_r0x2015ece4:
      bVar7 = 2 < (int)uVar4;
      uVar4 = uVar4 + 1;
      if (bVar7) {
        mainlink_send_nak(param_1);
        local_534 = 0;
        uVar3 = 0;
        uVar5 = 0xffffffff;
        uVar4 = 0;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      }
      itron_dly_tsk(1);
    }
    else {
      uVar6 = uVar3 + iVar1;
      if (0x3ff < uVar6) {
        *(uint *)(param_1 + 0x38) = uVar6;
      }
      memcpy(auStack_530 + uVar3,auStack_130);
      if (local_534 == 0) {
        uVar2 = mainlink_rx_parse(param_1,auStack_530,uVar6,&local_534);
        uVar3 = uVar6;
      }
      else {
        uVar2 = mainlink_rx_frame(param_1,local_534,auStack_530,uVar6);
        if (600 < uVar2) {
          mainlink_send_nak(param_1);
          uVar6 = 0;
          local_534 = 0;
          uVar4 = 0;
        }
        for (; uVar3 = uVar6, 0 < (int)uVar2;
            uVar2 = mainlink_rx_parse(param_1,auStack_530 + uVar2,uVar6,&local_534)) {
          if ((int)uVar6 <= (int)uVar2) goto LAB_2015edf4;
          uVar6 = uVar6 - uVar2;
        }
      }
      if (uVar2 == 0) {
        uVar5 = 2;
      }
      else {
LAB_2015edf4:
        bVar7 = uVar2 == uVar3;
        uVar4 = uVar2 - uVar3;
        if (!bVar7) {
          uVar4 = uVar2;
        }
        if ((!bVar7 && uVar2 != 0) && (int)uVar4 < 0 == (bVar7 && SBORROW4(uVar2,uVar3))) {
          mainlink_send_nak(param_1);
        }
        uVar3 = 0;
        uVar5 = 0xffffffff;
        local_534 = 0;
        uVar4 = uVar3;
      }
    }
  }
  goto LAB_2015ec90;
}


// ===== mainlink_send_ack @ 2015ee40 (68 bytes)

/* 1-byte 0x06 frame */

void mainlink_send_ack(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  iVar1 = mainlink_tx_alloc(*(undefined4 *)(param_1 + 0x14));
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 1;
  *(undefined1 *)(iVar1 + 8) = 6;
  mainlink_tx_post(*(undefined4 *)(param_1 + 0x14));
  return;
}


// ===== mainlink_send_nak @ 2015ee84 (68 bytes)

/* 1-byte 0x15 frame */

void mainlink_send_nak(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  iVar1 = mainlink_tx_alloc(*(undefined4 *)(param_1 + 0x14));
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 1;
  *(undefined1 *)(iVar1 + 8) = 0x15;
  mainlink_tx_post(*(undefined4 *)(param_1 + 0x14));
  return;
}


// ===== mainlink_rx_frame @ 2015eec8 (116 bytes)

/* waits for len+2 bytes, validates, ACKs, delivers */

int mainlink_rx_frame(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(ushort *)(param_2 + 2) + 2;
  if (param_4 < iVar2) {
    iVar2 = 0;
  }
  else {
    iVar1 = mainlink_rx_validate(param_1,param_3);
    if (iVar1 == 0) {
      iVar2 = -1;
    }
    else {
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      if (*(char *)(param_2 + 4) == '\0') {
        mainlink_send_ack(param_1);
      }
      mainlink_rx_deliver(param_1,param_3,iVar2);
    }
  }
  return iVar2;
}


// ===== mainlink_rx_ctor @ 2015efe4 (12 bytes)

/* vtbl 0x20427FF8 */

void mainlink_rx_ctor(undefined4 *param_1)

{
  *param_1 = &DAT_20427ff8;
  return;
}


// ===== mouse_cursor_task_create @ 2015eff4 (72 bytes)

void mouse_cursor_task_create(int param_1)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_20165700);
  if (0 < iVar1) {
    mouse_cursor_obj_init(param_1 + 4);
    iVar1 = itron_sta_tsk(iVar1,param_1 + 4);
    if (iVar1 == 0) {
      FUN_201525f8(0xffffffff);
      return;
    }
  }
  return;
}


// ===== FUN_2015f040 @ 2015f040 (24 bytes)

int FUN_2015f040(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428004;
  iVar1 = FUN_2015ff70(param_1 + 1);
  return iVar1 + -4;
}


// ===== FUN_2015f05c @ 2015f05c (60 bytes)

void FUN_2015f05c(int param_1)

{
  uint uVar1;
  
  *(undefined1 *)(param_1 + 0x81) = 0;
  uVar1 = 0;
  do {
    FUN_201645f8(param_1 + 0x88,uVar1 & 0xffff,param_1 + uVar1 * 8);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x10);
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f098 @ 2015f098 (28 bytes)

void FUN_2015f098(int param_1,undefined4 param_2,int param_3)

{
  *(char *)(param_1 + 0x81) = (char)param_3;
  *(undefined4 *)(param_1 + 0x84) = param_2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x80) = 0;
  }
  return;
}


// ===== FUN_2015f0b4 @ 2015f0b4 (16 bytes)

void FUN_2015f0b4(int param_1)

{
  *(undefined1 *)(param_1 + 0x80) = 1;
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f0c4 @ 2015f0c4 (8 bytes)

void FUN_2015f0c4(int param_1)

{
  FUN_201645e4(param_1 + 0x88);
  return;
}


// ===== FUN_2015f0cc @ 2015f0cc (20 bytes)

int FUN_2015f0cc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_20164638(param_1 + 0x88);
  return iVar1 + -0x88;
}


// ===== task_fwdbg @ 2015f0e0 (12 bytes)

/* task entry: loops on update_display_self */

undefined4 task_fwdbg(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined8 uVar4;
  
  uVar4 = update_display_self(param_1);
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  puVar1 = (undefined4 *)uVar4;
  iVar2 = strcmp("fw1up",uVar3);
  if (iVar2 == 0) {
    itron_set_flg(*puVar1,0x1001,*puVar1,extraout_r3,param_1);
    uVar3 = 1;
  }
  else {
    iVar2 = strcmp("fw1chk",uVar3);
    if (iVar2 == 0) {
      itron_set_flg(*puVar1,0x3001,*puVar1,extraout_r3_00,param_1);
      uVar3 = 1;
    }
    else {
      iVar2 = strcmp(&DAT_20428198,uVar3);
      if (iVar2 == 0) {
        itron_set_flg(*puVar1,1,*puVar1,extraout_r3_01,param_1);
        uVar3 = 1;
      }
      else {
        iVar2 = strcmp(&DAT_2042819c,uVar3);
        if (iVar2 == 0) {
          itron_set_flg(*puVar1,2,*puVar1,extraout_r3_02,param_1);
          uVar3 = 1;
        }
        else {
          iVar2 = strcmp(&DAT_204281a0,uVar3);
          if (iVar2 == 0) {
            itron_set_flg(*puVar1,4);
            uVar3 = 1;
          }
          else {
            uVar3 = 0;
          }
        }
      }
    }
  }
  return uVar3;
}


// ===== fwdbg_cmd @ 2015f0ec (240 bytes)

/* fw1up, fw1chk, up0, up1, up2 -> event flags of the self-update task */

undefined4 fwdbg_cmd(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp("fw1up",param_2);
  if (iVar1 == 0) {
    itron_set_flg(*param_1,0x1001);
    uVar2 = 1;
  }
  else {
    iVar1 = strcmp("fw1chk",param_2);
    if (iVar1 == 0) {
      itron_set_flg(*param_1,0x3001);
      uVar2 = 1;
    }
    else {
      iVar1 = strcmp(&DAT_20428198,param_2);
      if (iVar1 == 0) {
        itron_set_flg(*param_1,1);
        uVar2 = 1;
      }
      else {
        iVar1 = strcmp(&DAT_2042819c,param_2);
        if (iVar1 == 0) {
          itron_set_flg(*param_1,2);
          uVar2 = 1;
        }
        else {
          iVar1 = strcmp(&DAT_204281a0,param_2);
          if (iVar1 == 0) {
            itron_set_flg(*param_1,4);
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}


// ===== fwdbg_verify_bank1 @ 2015f1f0 (332 bytes)

/* fw1chk: compares a file with bank 1 (0x18400000), forever (was display_flash_write_bank) */

undefined4 fwdbg_verify_bank1(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int extraout_r1;
  code *pcVar6;
  int iVar7;
  
  iVar1 = DAT_208001c4;
  DAT_208001c0 = DAT_208001c0 + 1;
  iVar2 = fs_fopen(param_2,&DAT_204281a4);
  if (iVar2 == 0) {
    uVar3 = 3;
  }
  else {
    kbd_led_status(3,7);
    itron_dly_tsk(10);
    itron_dly_tsk(10);
    kbd_led_status(4,7);
    pcVar6 = FUN_18400000;
    iVar7 = 0;
    do {
      iVar4 = fs_fread(param_1 + 4,1,0x100,iVar2);
      if (iVar4 == 0) break;
      iVar7 = iVar7 + 1;
      __aeabi_uidivmod(iVar7,100);
      if (extraout_r1 == 0) {
        itron_dly_tsk(10);
      }
      iVar5 = FUN_2015507c(param_1 + 4,pcVar6,iVar4);
      if (iVar5 != 0) {
        DAT_208001c4 = DAT_208001c4 + 1;
      }
      pcVar6 = pcVar6 + 0x100;
    } while (iVar4 != 0);
    FUN_20141ff0(iVar2);
    if (iVar1 == DAT_208001c4) {
      uVar3 = 0;
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}


// ===== fwdbg_write_other_bank @ 2015f348 (512 bytes)

/* fw1up: raw I:\AH076H_DISPLAY.bin to the non-running bank + flag */

undefined4 fwdbg_write_other_bank(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  int iStack_2c;
  undefined4 local_28;
  
  iStack_2c = param_1;
  local_28 = param_2;
  iVar1 = fs_fopen(param_2,&DAT_204281a6);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    thunk_FUN_2014af64(iVar1,&local_30);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    if (DAT_208dbb44 == 1) {
      puVar5 = &DAT_208dbb84;
      puVar6 = &DAT_208dbb64;
    }
    else if (DAT_208dbb44 == 2) {
      puVar5 = &DAT_208dbb64;
      puVar6 = &DAT_208dbb84;
    }
    else {
      puVar5 = &DAT_208dbb64;
      puVar6 = &DAT_208dbb84;
    }
    iVar7 = puVar5[1];
    kbd_led_status(3,7);
    iVar3 = spiflash_erase(0,*puVar5,0x14);
    if (iVar3 == 0) {
      iVar3 = spiflash_erase(0,puVar5[1],local_30);
      if (iVar3 == 0) {
        kbd_led_status(4,7);
        local_48 = 0xffffffff;
        crc32_make_table();
        do {
          iVar3 = fs_fread(param_1 + 4,1,0x100,iVar1);
          if (iVar3 == 0) break;
          iVar4 = spiflash_write(iVar7,param_1 + 4,iVar3);
          if (iVar4 != 0) {
            FUN_20141ff0(iVar1);
            return 3;
          }
          local_48 = crc32_update(local_48,iVar3,param_1 + 4);
          iVar7 = iVar7 + 0x100;
        } while (iVar3 != 0);
        FUN_20141ff0(iVar1);
        local_44 = 0x11111111;
        local_34 = ~local_48;
        local_40 = local_30;
        iVar1 = spiflash_write(*puVar5,&local_44,0x14);
        if (iVar1 == 0) {
          iVar1 = spiflash_erase(0,*puVar6,0x14);
          if (iVar1 == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 3;
        }
      }
      else {
        FUN_20141ff0(iVar1);
        uVar2 = 3;
      }
    }
    else {
      FUN_20141ff0(iVar1);
      uVar2 = 3;
    }
  }
  return uVar2;
}


// ===== fwdbg_task_create @ 2015f55c (200 bytes)

/* event flag + task (entry 0x2015F0E0, pri 5, stack 0x2000) */

undefined4 fwdbg_task_create(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  code *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = task_fwdbg;
  local_20 = 5;
  local_1c = 0x2000;
  local_18 = 0;
  local_14 = 0;
  local_38 = 2;
  local_34 = 0;
  local_30 = 0;
  iVar1 = itron_acre_flg(0,&local_38);
  *param_1 = iVar1;
  if (*param_1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = itron_acre_tsk(0,&local_2c);
    if (iVar1 < 1) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = itron_sta_tsk(iVar1,param_1);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}


// ===== update_display_self @ 2015f62c (1028 bytes)

/* I:\AH076H_DISPLAY.bin, I:\AH068_DISPLAY_Loader.bin */

void update_display_self(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined1 auStack_48 [52];
  int local_14;
  char *local_10;
  undefined4 local_c;
  uint local_8 [2];
  
LAB_2015f638:
  do {
    local_68 = 0xffffffff;
    local_c = itron_twai_flg(*param_1,0xffff,5,local_8);
    iVar8 = 0;
    iVar6 = 0;
    if ((local_8[0] & 1) == 0) {
      if ((local_8[0] & 2) == 0) {
        if ((local_8[0] & 4) != 0) {
          iVar6 = 0xa00000;
          iVar8 = 0x3f0000;
        }
      }
      else {
        iVar6 = 0x400000;
        iVar8 = 0x3e0000;
      }
    }
    else {
      iVar6 = 0;
    }
    kbd_led_status(0,7);
    do {
      do {
        kbd_led_status(0,7);
        itron_dly_tsk(100);
        kbd_led_status(1,7);
        local_10 = "I:\\AH076H_DISPLAY.bin";
        if (local_8[0] == 1) {
          local_10 = "I:\\AH068_DISPLAY_Loader.bin";
        }
        local_4c = FUN_2014aec8(local_10,auStack_48);
      } while ((local_4c != 0) || (iVar2 = fs_fopen(local_10,&DAT_204281da), iVar2 == 0));
      kbd_led_status(2,7);
      iVar7 = 0;
      do {
        iVar3 = fs_fread(param_1 + 1,1,0x100,iVar2);
        iVar7 = iVar7 + iVar3;
      } while (iVar3 != 0);
      if (local_14 != iVar7) goto LAB_2015f638;
      FUN_20141ff0(iVar2);
      if (local_8[0] == 0x1001) {
        local_58 = fwdbg_write_other_bank(param_1,local_10);
        if (local_58 == 0) {
          kbd_led_status(7);
        }
        else {
          kbd_led_status(5,7);
        }
        goto LAB_2015f638;
      }
      if (local_8[0] == 0x3001) {
        do {
          local_58 = fwdbg_verify_bank1(param_1,local_10);
          if (local_58 == 0) {
            kbd_led_status(7);
          }
          else {
            kbd_led_status(5,7);
          }
          itron_dly_tsk(0x32);
        } while( true );
      }
      kbd_led_status(3,7);
      if ((((iVar8 != 0) || ((local_8[0] & 0x1000) != 0)) &&
          ((iVar2 = spiflash_erase(0,0x3e0000,0x14), iVar2 != 0 ||
           (iVar2 = spiflash_erase(0,0x3f0000,0x14), iVar2 != 0)))) ||
         (iVar2 = spiflash_erase(0,iVar6,iVar7), iVar2 != 0)) goto LAB_2015f638;
      kbd_led_status(4,7);
      iVar2 = fs_fopen(local_10,&DAT_204281da);
    } while (iVar2 == 0);
    bVar1 = false;
    local_50 = 0;
    local_54 = 0xffffffff;
    crc32_make_table();
    do {
      uVar4 = fs_fread(param_1 + 1,1,0x100,iVar2);
      if (uVar4 == 0) break;
      for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1) {
        local_50 = (uint)*(byte *)((int)param_1 + uVar5 + 4) + (local_50 & 0xff) & 0xff;
      }
      local_54 = crc32_update(local_54,uVar4,param_1 + 1);
      iVar3 = spiflash_write(iVar6,param_1 + 1,uVar4);
      if (iVar3 != 0) {
        bVar1 = false;
        break;
      }
      iVar6 = iVar6 + 0x100;
      bVar1 = true;
    } while (uVar4 != 0);
    FUN_20141ff0(iVar2);
    if ((bVar1) && (iVar8 != 0)) {
      local_60 = 0;
      local_5c = 0;
      local_68 = 0x11111111;
      local_58 = ~local_54;
      local_64 = iVar7;
      iVar6 = spiflash_write(iVar8,&local_68,0x14);
      if (iVar6 != 0) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      kbd_led_status(7);
    }
    else {
      kbd_led_status(5,7);
    }
  } while( true );
}


// ===== FUN_2015fa40 @ 2015fa40 (68 bytes)

undefined4 FUN_2015fa40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x588),1);
  iVar1 = FUN_201643f0(param_1 + 0x504);
  uVar2 = *(undefined4 *)(param_1 + 0x504 + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== mouse_cursor_move @ 2015fa54 (52 bytes)

void mouse_cursor_move(int param_1,undefined2 param_2,undefined2 param_3)

{
  FUN_20152bb0(*(undefined4 *)(param_1 + 0x598),0xffffffff);
  *(undefined2 *)(param_1 + 0x592) = param_2;
  *(undefined2 *)(param_1 + 0x594) = param_3;
  FUN_201511e8(*(undefined4 *)(param_1 + 0x598));
  return;
}


// ===== mouse_wheel_event @ 2015fac4 (360 bytes)

/* wheel -> encoder id 6/2/3 or list scroll by screen id */

void mouse_wheel_event(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined2 uVar2;
  undefined *puVar3;
  
  DAT_20808534 = *(undefined2 *)(param_2 + 0x22);
  puVar3 = (undefined *)0x0;
  cVar1 = (char)DAT_20808534;
  if (DAT_208f0b2a != 0x3a) {
    if (DAT_208f0b2a < 0x3b) {
      if (DAT_208f0b2a == 0x20) {
        FUN_20113de0(6,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c1e);
        return;
      }
      if (DAT_208f0b2a == 0x30) {
        switch(DAT_208f0bc2) {
        case 0:
          puVar3 = &DAT_20800342;
          param_3 = 6;
          break;
        case 1:
          puVar3 = &DAT_2080033a;
          param_3 = 4;
          break;
        case 2:
          puVar3 = &DAT_20800334;
          param_3 = 3;
          break;
        case 3:
          puVar3 = &DAT_2080032a;
          param_3 = 2;
          break;
        case 4:
          puVar3 = &DAT_2080034e;
          param_3 = 5;
          break;
        case 5:
        case 0xb:
        case 0xc:
          goto switchD_2015fb98_caseD_5;
        }
        if (puVar3 != (undefined *)0x0) {
          uVar2 = FUN_2015fc80(param_1,puVar3,param_3);
          mainlink_send_touch_key(1,uVar2,0);
          mainlink_send_touch_key(0,uVar2);
          return;
        }
      }
      else if (DAT_208f0b2a == 0x34 || DAT_208f0b2a == 0x37) goto switchD_2015fb98_caseD_5;
      return;
    }
    if (DAT_208f0b2a == 0x40) {
      if ((DAT_208f0bc5 & 0xf) == 3) {
        FUN_20113de0(2,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0a);
        return;
      }
    }
    else {
      if (DAT_208f0b2a == 0x41) {
        FUN_20113de0(3,(int)-cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0f);
        return;
      }
      if (DAT_208f0b2a != 0x43 && DAT_208f0b2a != 0x70) {
        return;
      }
    }
  }
switchD_2015fb98_caseD_5:
  FUN_20113de0(2,(int)-cVar1,param_3,param_2);
  mainlink_renc_event(&DAT_208d9c0a);
  return;
}


// ===== FUN_2015fc80 @ 2015fc80 (64 bytes)

undefined2 FUN_2015fc80(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (uint)DAT_208f0bc3 + (int)-*(short *)(param_4 + 0x22);
  if (-*(short *)(param_4 + 0x22) < 0) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else if (param_3 <= iVar1) {
    iVar1 = param_3 + -1;
  }
  return *(undefined2 *)(param_2 + iVar1 * 2);
}


// ===== mouse_cursor_obj_init @ 2015fcc4 (148 bytes)

/* cursor at (400,240), sem "mouse_cursor_sem" */

void mouse_cursor_obj_init(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_201644e4();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x28;
    FUN_201587d0(iVar3 + 4);
    FUN_20164524(param_1 + 0x504,uVar2 & 0xffff,iVar3 + 4);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x58c) = uVar1;
  *(undefined1 *)(param_1 + 0x590) = 0;
  *(undefined2 *)(param_1 + 0x592) = 400;
  *(undefined2 *)(param_1 + 0x594) = 0xf0;
  iVar3 = os_create_sem_named(&DAT_201656d4,"mouse_cursor_sem");
  if (0 < iVar3) {
    *(int *)(param_1 + 0x598) = iVar3;
    FUN_201511e8();
    return;
  }
  return;
}


// ===== mouse_cursor_run @ 2015fd64 (496 bytes)

/* attach/detach/report loop: buttons -> pointer sources, dx/dy * speed */

void mouse_cursor_run(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short *unaff_r9;
  int local_10;
  undefined1 *local_c;
  undefined1 local_8 [8];
  
  do {
    do {
      while( true ) {
        while( true ) {
          FUN_20152434(*(undefined4 *)(param_1 + 0x58c),&local_10,0xffffffff);
          cVar1 = *(char *)(local_10 + 4);
          if (cVar1 != '\0') break;
          *(undefined1 *)(param_1 + 0x590) = 0;
          r_vdc5_stop_process(0,6);
          r_vdc5_stop_process(1,6);
          mouse_set_up();
        }
        if (cVar1 != '\x01') break;
        *(undefined1 *)(param_1 + 0x590) = 1;
        local_8[0] = 3;
        local_c = local_8;
        r_vdc5_start_process(0,6,&local_c);
        r_vdc5_start_process(1,6,&local_c);
        mouse_cursor_move(param_1,400,0xf0);
      }
    } while (cVar1 != '\x02');
    if (DAT_20800496 == '\0' && DAT_20800495 == '\0') {
      if ((*(byte *)(local_10 + 0xe) & 1) == 0) {
        mouse_set_up();
      }
    }
    else {
      FUN_20152bb0(*(undefined4 *)(param_1 + 0x598),0xffffffff);
      iVar2 = (int)*(short *)(local_10 + 0x12) * (*unaff_r9 + 0x96);
      uVar4 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x592));
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      else if (799 < (int)uVar4) {
        uVar4 = 799;
      }
      iVar2 = (int)*(short *)(local_10 + 0x14) * (*unaff_r9 + 0x96);
      uVar3 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x594));
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else if (0x1df < (int)uVar3) {
        uVar3 = 0x1df;
      }
      FUN_201511e8(*(undefined4 *)(param_1 + 0x598));
      mouse_cursor_move(param_1,uVar4 & 0xffff,uVar3 & 0xffff);
      if ((*(byte *)(local_10 + 0xe) & 1) == 0) {
        mouse_set_up();
      }
      else {
        mouse_set_down(uVar4 & 0xffff,uVar3 & 0xffff);
      }
      if ((*(ushort *)(local_10 + 0xe) & 2) == 0) {
        if ((*(ushort *)(local_10 + 0xe) & 4) == 0) {
          mouse_right_up();
          mouse_middle_up();
        }
        else {
          mouse_middle_down();
        }
      }
      else {
        mouse_right_down();
      }
      if (((*(ushort *)(local_10 + 0x10) & 0x100) != 0) && (*(short *)(local_10 + 0x22) != 0)) {
        mouse_wheel_event(param_1);
      }
    }
  } while( true );
}


// ===== FUN_2015ff70 @ 2015ff70 (32 bytes)

int FUN_2015ff70(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428018;
  iVar1 = FUN_20162c20(param_1 + 0x141);
  return iVar1 + -0x504;
}


// ===== FUN_2015ff94 @ 2015ff94 (92 bytes)

void FUN_2015ff94(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_20164414();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    FUN_20158618(iVar3 + 0x14);
    FUN_20164454(param_1 + 0x894,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x8dc) = uVar1;
  return;
}


// ===== task_uart4_dispatch @ 2015fff0 (40 bytes)

/* only counts */

void task_uart4_dispatch(int param_1)

{
  undefined1 auStack_8 [8];
  
  do {
    FUN_20152434(*(undefined4 *)(param_1 + 0x8dc),auStack_8,0xffffffff);
    *(int *)(param_1 + 0x8e0) = *(int *)(param_1 + 0x8e0) + 1;
  } while( true );
}


// ===== FUN_20160018 @ 20160018 (32 bytes)

int FUN_20160018(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428024;
  iVar1 = FUN_20162c10(param_1 + 0x225);
  return iVar1 + -0x894;
}

