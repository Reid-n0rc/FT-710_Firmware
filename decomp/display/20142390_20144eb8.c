// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fs_fgets @ 20142390 (84 bytes)

/* (buf, n, fd): fgets; sfl_stream_gets, sfl_read_header and cli_run_file read text lines with it
   [fact] */

undefined4 fs_fgets(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fgets_work(param_1,param_2,param_3,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
                    /* last error 0x20808BA4 = err, returns ret [doc] */
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}


// ===== file_read_core @ 201423e4 (480 bytes)

/* Sector-wise read body behind fs_fread [inference: chain fs_fread -> 0x20142980 -> 0x201425C4 ->
   here] */

int file_read_core(uint param_1,int param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_40;
  int local_3c;
  uint uStack_34;
  int iStack_30;
  int *piStack_2c;
  undefined4 local_28;
  
  local_3c = param_3[10];
  uStack_34 = param_1;
  iStack_30 = param_2;
  piStack_2c = param_3;
  local_28 = param_4;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar1 = __aeabi_uidivmod(param_3[0x8e],*(undefined4 *)(*param_3 + 0x6c));
  do {
    if (param_1 == 0) goto LAB_20142500;
    if ((uint)param_3[0x8e] <= (uint)param_3[5]) {
      if (param_3[7] != 0) {
        if (param_3[2] != 0) {
          iVar2 = fs_dev_op2(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
          if (iVar2 != 0) goto LAB_201424fc;
          param_3[2] = 0;
          *(undefined1 *)(param_3 + 0x113) = 1;
        }
        iVar2 = fat_sector_is_cluster_first(*param_3,param_3[8]);
        if (iVar2 != 0) {
          param_3[8] = param_3[8] + (uVar1 - 1);
        }
        iVar2 = fat_next_sector(*param_3,param_3[8],&local_40,local_28);
        if (iVar2 != 0) goto LAB_201424fc;
        if (local_40 == 0) goto LAB_20142500;
        iVar2 = fs_dev_op1(*param_3,local_40,param_3[1],uVar1 & 0xffff);
        if (iVar2 != 0) goto LAB_201424fc;
        param_3[8] = local_40;
      }
      param_3[5] = 0;
    }
    if ((uint)param_3[0xb] <= (uint)param_3[10]) break;
    uVar3 = param_3[0x8e] - param_3[5];
    uVar4 = param_1;
    if (uVar3 < param_1) {
      uVar4 = uVar3;
    }
    fs_memcpy(param_2,param_3[1] + param_3[5],uVar4);
    iVar2 = param_3[5];
    param_1 = param_1 - uVar4;
    param_2 = param_2 + uVar4;
    param_3[5] = iVar2 + uVar4;
    param_3[10] = param_3[10] + uVar4;
    if (((uint)param_3[0x8e] <= iVar2 + uVar4) && (param_3[2] != 0)) {
      iVar2 = fs_dev_op2(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
      if (iVar2 != 0) goto LAB_201424fc;
      param_3[2] = 0;
      *(undefined1 *)(param_3 + 0x113) = 1;
    }
  } while ((uint)param_3[10] < (uint)param_3[0xb]);
  iVar2 = -0xe;
LAB_201424fc:
  fs_set_error(iVar2,param_3);
LAB_20142500:
  if ((uint)param_3[0xb] <= (uint)param_3[10]) {
    fs_set_error(0xfffffff2,param_3);
  }
  return param_3[10] - local_3c;
}


// ===== file_read_locked @ 201425c4 (956 bytes)

/* Read under the drive lock [inference: same chain] */

int file_read_locked(int param_1,int param_2,int param_3,int *param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  uint extraout_r1_00;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint i;
  uint local_50;
  int local_4c;
  int local_40;
  uint local_3c;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int *piStack_28;
  
  local_4c = 0;
  iVar7 = *param_4;
  iVar8 = *(int *)(iVar7 + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  iStack_2c = param_3;
  piStack_28 = param_4;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar1 = __aeabi_uidivmod(param_4[0x8e],iVar8);
  uVar9 = (uint)*(ushort *)(iVar7 + 4) * iVar8;
  fs_set_error(0,param_4);
  uVar2 = param_4[0xb] - param_4[10];
  uVar10 = param_2 * param_3;
  if (uVar2 < (uint)(param_2 * param_3)) {
    uVar10 = uVar2;
  }
  if (uVar10 == 0) {
    if ((uint)param_4[0xb] <= (uint)param_4[10]) {
      fs_set_error(0xfffffff2,param_4);
    }
    return 0;
  }
  iVar7 = fs_drive_check_mounted(*param_4);
  if (iVar7 != 0) {
LAB_201426a4:
    fs_set_error(iVar7,param_4);
    return 0;
  }
  if (((param_4[8] != 0) && (*(short *)((int)param_4 + 0x44e) != 0)) &&
     (*(char *)((int)param_4 + 0x442) == '\x01')) {
    iVar7 = fs_dev_op1(*param_4,param_4[8],param_4[1],uVar1 & 0xffff);
    if (iVar7 != 0) goto LAB_201426a4;
    *(undefined2 *)((int)param_4 + 0x44e) = 0;
  }
  iVar7 = param_4[10];
  __aeabi_uidivmod(iVar7,uVar9);
  if (extraout_r1 + uVar10 < uVar9) {
                    /* Sector-wise read body behind fs_fread [doc, inference] */
    uVar3 = file_read_core(uVar10,param_1,param_4,param_5);
    iVar7 = __aeabi_uidivmod(uVar3,local_30);
    return iVar7;
  }
  uVar2 = uVar9 - extraout_r1;
  __aeabi_uidivmod(iVar7 + uVar10,uVar9);
  iVar7 = (uVar10 - uVar2) - extraout_r1_00;
  local_50 = extraout_r1_00;
  if ((iVar7 != 0) && (local_50 = extraout_r1_00, extraout_r1_00 == 0)) {
    iVar7 = (uVar10 - uVar2) - uVar9;
    local_50 = uVar9;
  }
  uVar4 = file_read_core(uVar2,param_1,param_4,param_5);
  if (uVar2 <= uVar4) {
    param_1 = param_1 + uVar4;
    param_4[8] = (uVar1 - 1) + param_4[8];
    iVar8 = __aeabi_uidivmod(uVar2,local_30);
    uVar4 = 0;
    uVar2 = __aeabi_uidivmod(iVar7,uVar9);
    i = 0;
    if (uVar2 != 0) {
      do {
        iVar5 = fat_next_sector(*param_4,param_4[8],&local_40,param_5);
        iVar7 = local_40;
        if (iVar5 != 0) goto LAB_201428cc;
        if (local_40 == 0) {
          return iVar8;
        }
        if (uVar4 == 0) {
          local_4c = local_40;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + local_40 + -1;
        }
        else {
          if (param_4[8] + 1 == local_40) {
            local_3c = (uint)*(ushort *)(*param_4 + 4);
            uVar6 = __aeabi_uidivmod(0x100);
            if (uVar4 < uVar6) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_3c + iVar7 + -1;
              goto LAB_20142890;
            }
          }
          iVar5 = fs_dev_op1(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
          iVar7 = local_40;
          local_4c = local_40;
          if (iVar5 != 0) goto LAB_201428cc;
          param_1 = uVar9 * uVar4 + param_1;
          iVar5 = __aeabi_uidivmod(uVar9 * uVar4,local_30);
          iVar8 = iVar8 + iVar5;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + iVar7 + -1;
        }
LAB_20142890:
        i = i + 1;
      } while (i < uVar2);
      if (uVar4 != 0) {
        iVar5 = fs_dev_op1(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) {
LAB_201428cc:
          fs_set_error(iVar5,param_4);
          return iVar8;
        }
        param_1 = uVar9 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + local_4c + -1;
        iVar7 = __aeabi_uidivmod(uVar9 * uVar4,local_30);
        iVar8 = iVar8 + iVar7;
      }
    }
    param_4[10] = uVar9 * uVar2 + param_4[10];
    if (uVar2 != 0) {
      param_4[8] = (param_4[8] - uVar1) + 1;
    }
    uVar1 = file_read_core(local_50,param_1,param_4,param_5);
    uVar4 = uVar10;
    if (uVar1 < local_50) {
      iVar7 = __aeabi_uidivmod(uVar1,local_30);
      return iVar7 + iVar8;
    }
  }
  iVar7 = __aeabi_uidivmod(uVar4,local_30);
  return iVar7;
}


// ===== fs_fread_work @ 20142980 (216 bytes)

/* fs_fread body: handle checks, then file_read_locked [inference: only caller fs_fread] */

undefined4 fs_fread_work(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = fs_check_ready();
  if ((iVar1 != 0) || (iVar1 = fs_file_check(param_4), iVar1 != 0)) {
    fs_set_error(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)(param_4 + 0x442) == '\x10' || *(char *)(param_4 + 0x442) == ' ') {
      fs_set_error(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      fs_set_error(0,param_4);
      return 0;
    }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    uVar2 = __aeabi_uidivmod(0xffffffff,param_2);
    if (param_3 <= uVar2) {
                    /* Read under the drive lock [doc, inference] */
      uVar3 = file_read_locked(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  fs_set_error(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fread @ 20142a58 (96 bytes)

uint fs_fread(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fread_work(param_1,param_2,param_3,param_4,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
  fs_set_error(0xffffffe1,0);
  return 0;
}


// ===== file_write_core @ 20142ab8 (2496 bytes)

/* Sector-wise write body behind fs_fwrite (allocates clusters, 2496 bytes) [inference: chain
   fs_fwrite -> 0x2014358C -> 0x20143478 -> here] */

int file_write_core(int param_1,int param_2,int param_3,uint *param_4,undefined4 param_5)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r1_01;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint *local_40;
  int local_3c;
  int iStack_34;
  int local_30;
  int local_2c;
  uint *puStack_28;
  
  uVar9 = 0;
  iVar7 = 0;
  uVar8 = 0;
  uVar4 = param_2 * param_3;
  local_5c = *param_4;
  iVar5 = *(int *)(local_5c + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  puStack_28 = param_4;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  local_58 = __aeabi_uidivmod(param_4[0x8e],iVar5);
  uVar6 = (uint)*(ushort *)(local_5c + 4) * iVar5;
  fs_set_error(0,param_4);
  if (uVar4 == 0) {
    return 0;
  }
  if (param_4[10] == 0xffffffff) {
    fs_set_error(0xffffffc5,param_4);
    return 0;
  }
  uVar2 = ~param_4[10];
  if (uVar2 < uVar4) {
    local_2c = __aeabi_uidivmod(uVar2,local_30);
    uVar4 = uVar2;
  }
  iVar5 = fs_drive_check_mounted(*param_4);
  if (iVar5 != 0) {
LAB_20142d60:
    fs_set_error(iVar5,param_4);
    return 0;
  }
  __aeabi_uidivmod(param_4[10],uVar6);
  local_40 = param_4 + 0x100;
  if (extraout_r1 + uVar4 < uVar6) {
    iVar5 = local_58 - 1;
    do {
      if (param_4[0x8e] <= param_4[5]) {
        if (param_4[2] != 0) {
          uVar8 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar8 + 0x6c));
          iVar7 = fs_dev_op2(uVar8,param_4[8],param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
          param_4[2] = 0;
          *(undefined1 *)(param_4 + 0x113) = 1;
        }
        iVar7 = fat_sector_is_cluster_first(*param_4,param_4[8]);
        if (iVar7 != 0) {
          param_4[8] = param_4[8] + iVar5;
        }
        iVar7 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
        uVar8 = local_60;
        if (iVar7 != 0) goto LAB_20142cec;
        if (local_60 == 0) {
          iVar7 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 != 0) goto LAB_20142cec;
          if (local_60 == 0) {
            iVar7 = -0xb;
            goto LAB_20142cec;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = fs_dev_op1(uVar9,uVar8,param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
        }
        param_4[8] = local_60;
        param_4[5] = 0;
      }
      uVar9 = param_4[0x8e] - param_4[5];
      uVar8 = uVar4;
      if (uVar9 < uVar4) {
        uVar8 = uVar9;
      }
      fs_memcpy(param_4[1] + param_4[5],param_1,uVar8);
      uVar4 = uVar4 - uVar8;
      param_1 = param_1 + uVar8;
      param_4[5] = param_4[5] + uVar8;
      uVar8 = param_4[10] + uVar8;
      param_4[10] = uVar8;
      if (param_4[0xb] <= uVar8) {
        param_4[0xb] = uVar8;
      }
      param_4[2] = 1;
      *(undefined2 *)((int)local_40 + 0x4e) = 1;
    } while (uVar4 != 0);
    iVar7 = 0;
LAB_20142cec:
    fs_set_error(iVar7,param_4);
    uVar9 = local_30 * local_2c - uVar4;
    goto LAB_20143008;
  }
                    /* writes the file's dirty sector buffer back [doc] */
  if ((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
     (iVar5 = file_buf_sync(param_4,0,2,param_5), iVar5 != 0)) goto LAB_20142d60;
  local_50 = param_4[10];
  __aeabi_uidivmod(local_50,uVar6);
  local_5c = uVar6 - extraout_r1_00;
  __aeabi_uidivmod(local_50 + uVar4,uVar6);
  local_3c = (uVar4 - local_5c) - extraout_r1_01;
  local_50 = extraout_r1_01;
  if ((local_3c != 0) && (local_50 = extraout_r1_01, extraout_r1_01 == 0)) {
    local_3c = (uVar4 - local_5c) - uVar6;
    local_50 = uVar6;
  }
  param_4[3] = 1;
  local_44 = local_58 - 1;
  uVar4 = local_5c;
  while (uVar4 != 0) {
    if (param_4[0x8e] <= param_4[5]) {
      if (param_4[2] != 0) {
        local_4c = *param_4;
        uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(local_4c + 0x6c));
        iVar5 = fs_dev_op2(local_4c,param_4[8],param_4[1],uVar1);
        if (iVar5 != 0) goto LAB_20142f50;
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
      iVar5 = fat_sector_is_cluster_first(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      iVar5 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
      if (iVar5 != 0) {
LAB_20142f50:
        fs_set_error(iVar5,param_4);
        iVar5 = __aeabi_uidivmod(uVar9,local_30);
        return iVar5;
      }
      local_4c = local_60;
      if (local_60 == 0) {
        iVar5 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
        if (iVar5 != 0) goto LAB_20142f50;
        if (local_60 == 0) {
          fs_set_error(0xfffffff5,param_4);
          goto LAB_20143008;
        }
      }
      else {
        local_48 = *param_4;
        uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(local_48 + 0x6c));
        iVar5 = fs_dev_op1(local_48,local_4c,param_4[1],uVar1);
        if (iVar5 != 0) {
          fs_set_error(iVar5,param_4);
          goto LAB_20143008;
        }
      }
      param_4[8] = local_60;
      param_4[5] = 0;
    }
    uVar2 = param_4[0x8e] - param_4[5];
    uVar9 = uVar4;
    if (uVar2 < uVar4) {
      uVar9 = uVar2;
    }
    fs_memcpy(param_4[1] + param_4[5],param_1,uVar9);
    uVar4 = uVar4 - uVar9;
    param_1 = param_1 + uVar9;
    param_4[5] = param_4[5] + uVar9;
    uVar2 = param_4[10] + uVar9;
    param_4[10] = uVar2;
    if (param_4[0xb] <= uVar2) {
      param_4[0xb] = uVar2;
    }
    param_4[2] = 1;
    *(undefined2 *)((int)local_40 + 0x4e) = 1;
  }
  fs_set_error(0,param_4);
  uVar9 = 0;
  if (local_5c != 0) {
    uVar9 = local_5c;
  }
  if (param_4[2] == 0) {
LAB_20143048:
    uVar4 = 0;
    local_5c = __aeabi_uidivmod(local_3c,uVar6);
    uVar2 = 0;
    if (local_5c != 0) {
      do {
        iVar5 = fat_next_sector(*param_4,param_4[8],&local_54,param_5);
        if (iVar5 != 0) goto LAB_20142e7c;
        if (local_54 == 0) {
          local_58 = fat_next_sector_alloc(*param_4,param_4[8],&local_54,param_5);
          if (local_58 != 0) {
            fs_set_error(local_58,param_4);
          }
          if (local_54 == 0) {
            fs_set_error(0xfffffff5,param_4);
          }
          if ((local_58 != 0) || (local_54 == 0)) {
            if (uVar4 == 0) {
              uVar9 = uVar9 + iVar7;
            }
            else {
              iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
              uVar9 = uVar6 * uVar4 + uVar9 + iVar7;
              uVar4 = uVar6 * uVar4 + param_4[10] + iVar7;
              param_4[10] = uVar4;
              if (param_4[0xb] < uVar4) {
                param_4[0xb] = uVar4;
              }
              if (iVar5 == 0) {
                *(undefined1 *)(param_4 + 0x113) = 1;
                fs_set_error(0xfffffff5,param_4);
              }
              else {
                fs_set_error(iVar5,param_4);
              }
            }
            goto LAB_20143008;
          }
        }
        if (uVar4 == 0) {
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + (local_54 - 1);
          uVar8 = local_54;
        }
        else {
          local_48 = local_54;
          if (param_4[8] + 1 == local_54) {
            local_4c = (uint)*(ushort *)(*param_4 + 4);
            uVar3 = __aeabi_uidivmod(0x100);
            if (uVar4 < uVar3) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_4c + (local_48 - 1);
              goto LAB_20143258;
            }
          }
          iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
          if (iVar5 != 0) {
            uVar9 = uVar9 + iVar7;
            fs_set_error(iVar5,param_4);
            goto LAB_20143008;
          }
          param_1 = uVar6 * uVar4 + param_1;
          iVar7 = uVar6 * uVar4 + iVar7;
          uVar4 = 1;
          param_4[8] = (local_54 - 1) + (uint)*(ushort *)(*param_4 + 4);
          *(undefined1 *)(param_4 + 0x113) = 1;
          uVar8 = local_54;
        }
LAB_20143258:
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_5c);
      if (uVar4 != 0) {
        iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) goto LAB_20142e7c;
        param_1 = uVar6 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + (uVar8 - 1);
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
    }
    uVar4 = 0;
    iVar5 = uVar6 * local_5c + uVar9;
    uVar9 = uVar6 * local_5c + param_4[10];
    param_4[10] = uVar9;
    uVar8 = local_50;
    if (param_4[0xb] < uVar9) {
      param_4[0xb] = uVar9;
    }
    while( true ) {
      if (uVar8 == 0) {
        fs_set_error(0,param_4);
        return local_2c;
      }
      if (param_4[0x8e] <= param_4[5]) break;
LAB_20143400:
      uVar9 = param_4[0x8e] - param_4[5];
      uVar4 = uVar8;
      if (uVar9 < uVar8) {
        uVar4 = uVar9;
      }
      fs_memcpy(param_4[1] + param_4[5],param_1,uVar4);
      param_1 = param_1 + uVar4;
      param_4[5] = param_4[5] + uVar4;
      uVar9 = param_4[10] + uVar4;
      param_4[10] = uVar9;
      if (param_4[0xb] <= uVar9) {
        param_4[0xb] = uVar9;
      }
      param_4[2] = 1;
      uVar8 = uVar8 - uVar4;
    }
    if (param_4[2] == 0) {
LAB_20143364:
      iVar7 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
      if (iVar7 == 0) {
        local_5c = local_60;
        if (local_60 == 0) {
          iVar7 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 == 0) {
            if (local_60 != 0) goto LAB_201433f4;
            fs_set_error(0xfffffff5,param_4);
            uVar9 = uVar4 + iVar5;
            goto LAB_20143008;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = fs_dev_op1(uVar9,local_5c,param_4[1],uVar1);
          if (iVar7 == 0) {
LAB_201433f4:
            param_4[8] = local_60;
            param_4[5] = 0;
            goto LAB_20143400;
          }
        }
      }
    }
    else {
      uVar9 = *param_4;
      uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
      iVar7 = fs_dev_op2(uVar9,param_4[8],param_4[1],uVar1);
      if (iVar7 == 0) {
        param_4[8] = local_44 + param_4[8];
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
        goto LAB_20143364;
      }
    }
    fs_set_error(iVar7,param_4);
    uVar9 = uVar4 + iVar5;
  }
  else {
    iVar5 = fs_dev_op2(*param_4,param_4[8],param_4[1],local_58 & 0xffff);
    if (iVar5 == 0) {
      iVar5 = fat_sector_is_cluster_first(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      param_4[2] = 0;
      *(undefined1 *)(param_4 + 0x113) = 1;
      goto LAB_20143048;
    }
LAB_20142e7c:
    fs_set_error(iVar5,param_4);
  }
LAB_20143008:
  iVar5 = __aeabi_uidivmod(uVar9,local_30);
  return iVar5;
}


// ===== file_write_locked @ 20143478 (276 bytes)

/* Write under the drive lock [inference: same chain] */

undefined4
file_write_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint fs_task_ctx_get_ret;
  int local_1c;
  
                    /* writes the file's dirty sector buffer back [doc] */
  if (((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
      (param_4[10] != param_4[0xb])) && (iVar1 = file_buf_sync(param_4,0,2,param_5), iVar1 != 0)) {
LAB_201434f8:
    fs_set_error(iVar1,param_4);
    return 0;
  }
  if (param_4[0xb] == 0) {
                    /* fat_alloc_cluster under fs_lock_b [doc] */
    iVar1 = fat_alloc_cluster_locked(*param_4,0,&local_1c,param_5);
    if (iVar1 != 0) goto LAB_201434f8;
    param_4[7] = local_1c;
    if (local_1c == 0) {
      fs_set_error(0xfffffff5,param_4);
      return 0;
    }
    iVar1 = fat_clust2sect(*param_4);
    param_4[8] = iVar1;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(param_4[1],0,param_4[0x8e],*(undefined4 *)(*param_4 + 0x6c));
  }
                    /* Sector-wise write body behind fs_fwrite [doc, inference] */
  uVar2 = file_write_core(param_1,param_2,param_3,param_4,param_5);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
  fs_task_ctx_get_ret = fs_task_ctx_get();
  fs_set_error(fs_task_ctx_get_ret,param_4);
  return uVar2;
}


// ===== fs_fwrite_work @ 2014358c (240 bytes)

/* fs_fwrite body: handle checks (fs_file_check, write-protect) then file_write_locked [inference:
   only caller fs_fwrite] */

undefined4
fs_fwrite_work(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = fs_check_ready();
  if ((iVar1 != 0) || (iVar1 = fs_file_check(param_4), iVar1 != 0)) {
    fs_set_error(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)((int)param_4 + 0x442) == '\x01') {
      fs_set_error(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      fs_set_error(0,param_4);
      return 0;
    }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    uVar2 = __aeabi_uidivmod(0xffffffff,param_2);
    if (param_3 <= uVar2) {
      iVar1 = fs_drive_check_writable(*param_4);
      if (iVar1 != 0) {
        fs_set_error(iVar1,param_4);
        return 0;
      }
                    /* Write under the drive lock [doc, inference] */
      uVar3 = file_write_locked(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  fs_set_error(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fwrite @ 2014367c (96 bytes)

uint fs_fwrite(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fwrite_work(param_1,param_2,param_3,param_4,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
  fs_set_error(0xffffffe1,0);
  return 0;
}


// ===== fs_fseek_work @ 201436dc (116 bytes)

/* fs_fseek body with the handle check [inference: only caller fs_fseek] */

void fs_fseek_work(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fs_file_check(param_1), iVar1 == 0)) {
    if (2 < param_3) {
      fs_set_error(0xfffffff3,param_1);
      return;
    }
                    /* writes the file's dirty sector buffer back [doc] */
    uVar2 = file_buf_sync(param_1,param_2,param_3,param_4);
    fs_set_error(uVar2,param_1);
    return;
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_fseek @ 20143750 (84 bytes)

uint fs_fseek(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
                    /* fs_fseek body with the handle check [doc, inference] */
    uVar2 = fs_fseek_work(param_1,param_2,param_3,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== file_remove_core @ 201437a4 (692 bytes)

/* Removes a directory entry and frees its clusters [inference: chain fs_remove -> fs_remove_work ->
   here] */

int file_remove_core(char *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4c;
  undefined1 auStack_48 [11];
  byte local_3d;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  iVar5 = 0;
  local_4c = DAT_20808ba0;
  iVar4 = DAT_20808b90;
  if (0 < DAT_20808b94) {
    do {
      iVar3 = fs_stricmp_sjis_fold(iVar4 + 0x23c,param_1);
      if (iVar3 == 0) {
        return -7;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x450;
    } while (iVar5 < DAT_20808b94);
  }
  uVar2 = fs_toupper((int)*param_1);
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
  iVar4 = fs_find_drive(uVar2,&local_4c);
  if (((iVar4 == 0) && (iVar4 = fs_drive_check_mounted(local_4c), iVar4 == 0)) &&
     (iVar4 = fs_drive_check_writable(local_4c), iVar4 == 0)) {
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(auStack_48,0,0x20,*(undefined4 *)(local_4c + 0x6c));
    param_1 = param_1 + 2;
    iVar4 = *(int *)(local_4c + 0x34);
    if (*(char *)(local_4c + 0x10) != ' ') {
                    /* copies the "\\name" component at p [doc] */
      param_1 = (char *)path_next_component(param_1,param_2);
      if ((param_1 == (char *)0x0) || (*param_2 == '\0')) {
        return -1;
      }
                    /* root_dir_find under fs_lock_a [doc] */
      iVar4 = root_dir_find_locked(local_4c,param_2,auStack_48,0,0,auStack_28,param_2);
      if (iVar4 != 0) {
        if (*param_1 == '\0') {
          return -3;
        }
        return -4;
      }
                    /* First cluster of an entry [doc] */
      iVar4 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
    }
    cVar1 = *param_1;
    iVar5 = 0;
    while (cVar1 != '\0') {
      param_1 = (char *)path_next_component(param_1,param_2);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_2 == '\0') {
        return -1;
      }
                    /* subdir_find under fs_lock_a [doc] */
      iVar5 = subdir_find_locked(local_4c,iVar4,param_2,auStack_48,0,0,auStack_28,auStack_24,param_2
                                );
      if (iVar5 != 0) {
        if (*param_1 != '\0' || iVar5 != -4) {
          return iVar5;
        }
        return -3;
      }
      iVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
      iVar5 = iVar4;
      iVar4 = iVar3;
      cVar1 = *param_1;
    }
    if ((local_3d & 0x10) != 0) {
      return -3;
    }
    if (iVar5 == 0) {
      iVar4 = root_dir_find_locked(local_4c,param_2,auStack_48,2,0,auStack_28,param_2);
    }
    else {
      iVar4 = subdir_find_locked(local_4c,iVar5,param_2,auStack_48,2,0,auStack_28,auStack_24,param_2
                                );
    }
                    /* fat_chain_free under fs_lock_b [doc] */
    if ((iVar4 == 0) &&
       ((iVar4 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10)), iVar4 == 0 ||
        (iVar4 = fat_chain_free_locked(local_4c,iVar4,param_2), iVar4 == 0)))) {
                    /* fat32_fsinfo_write under fs_lock_b [doc] */
      iVar4 = fat32_fsinfo_write_locked(local_4c,param_2);
      return iVar4;
    }
  }
  return iVar4;
}


// ===== fs_remove_work @ 20143a58 (200 bytes)

/* Validates and normalises the path, file_remove_core, fs_flush [fact] */

void fs_remove_work(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 == 0) {
    if (param_1 == 0) {
      uVar4 = 0xffffffff;
LAB_20143b18:
      fs_set_error(uVar4,0);
      return;
    }
    iVar2 = fs_path_validate(param_1);
    if (iVar2 == 0) {
                    /* Byte-wise string length [doc] */
      iVar2 = fs_strlen(param_1);
      iVar3 = param_2 + 0x100c;
      fs_strncpy(iVar3,param_1,iVar2 + 1);
                    /* Rewrites NEC/IBM extension codes in a path [doc, inference] */
      sjis_map_ext_chars(iVar3);
      uVar1 = fs_toupper((int)*(char *)(param_2 + 0x100c));
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
      iVar2 = fs_find_drive(uVar1,&local_10);
                    /* Removes a directory entry and frees its clusters [doc, inference] */
      if ((iVar2 == 0) && (iVar2 = file_remove_core(iVar3,param_2), iVar2 == 0)) {
        uVar4 = fs_flush(local_10);
        goto LAB_20143b18;
      }
    }
  }
  fs_set_error(iVar2,0);
  return;
}


// ===== fs_remove @ 20143b20 (68 bytes)

/* (path): deletes a file; wav_delete, rec_close_abort and rec_open_wav call it on WAV files [fact]
    */

undefined4 fs_remove(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_remove_work(param_1,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== fs_fatcache_setup @ 20143b70 (172 bytes)

/* (drive, buffer, size, sectors per slot): FAT cache in a caller buffer (0x206 bytes per sector
   slot, 4-byte aligned), -24 when too small [fact] */

int fs_fatcache_setup(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fs_check_ready();
  if (iVar1 == 0) {
    if (param_3 < (uint)(param_4 * 0x206)) {
      return -0x18;
    }
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    uVar2 = __aeabi_uidivmod(param_3,param_4 * 0x206);
    if (uVar2 < 0x10000) {
      if (uVar2 == 0) {
        return -0x18;
      }
    }
    else {
      uVar2 = 0xffff;
    }
    *(short *)(param_1 + 0x48) = (short)uVar2;
    *(uint *)(param_1 + 0x44) = param_2;
    *(short *)(param_1 + 0x4a) = (short)param_4;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(param_2,0,uVar2 * param_4 * 0x206,*(undefined4 *)(param_1 + 0x6c));
    iVar1 = 0;
  }
  return iVar1;
}


// ===== fs_fatcache_setup_a @ 20143c1c (24 bytes)

/* fs_fatcache_setup and fs_set_error [fact] */

void fs_fatcache_setup_a(void)

{
  undefined4 uVar1;
  
                    /* FAT cache in a caller buffer [doc] */
  uVar1 = fs_fatcache_setup();
  fs_set_error(uVar1,0);
  return;
}


// ===== fs_fatcache_setup_b @ 20143c34 (20 bytes)

/* Second identical wrapper [fact] */

void fs_fatcache_setup_b(void)

{
  undefined4 uVar1;
  
                    /* FAT cache in a caller buffer [doc] */
  uVar1 = fs_fatcache_setup();
  fs_set_error(uVar1,0);
  return;
}


// ===== fatcache_lookup @ 20143c48 (116 bytes)

/* Slot number (1-based) of the FAT cache slot holding a sector, 0 for a miss [fact] */

uint fatcache_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint i;
  uint *puVar2;
  
  i = 0;
  puVar2 = *(uint **)(param_1 + 0x44);
  if (*(ushort *)(param_1 + 0x48) != 0) {
    do {
      uVar1 = *puVar2 & 0x7fffffff;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < *(ushort *)(param_1 + 0x4a) + uVar1)) {
        return i * *(ushort *)(param_1 + 0x4a) + (param_2 - uVar1) + 1 & 0xffff;
      }
      i = i + 1;
      puVar2 = puVar2 + 1;
    } while (i < *(ushort *)(param_1 + 0x48));
  }
  return 0;
}


// ===== fatcache_load @ 20143cbc (340 bytes)

/* Evicts the oldest FAT cache slot (writes it back when dirty, also to the second FAT when there
   are two and a slot is one sector) and reads the slot's sectors (fs_dev_op1) [fact] */

int fatcache_load(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  
  uVar8 = (uint)*(ushort *)(param_1 + 6);
  uVar7 = (uint)*(ushort *)(param_1 + 0x4a);
  iVar9 = *(int *)(param_1 + 0x44);
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar2 = __aeabi_uidivmod(param_2 - uVar8,uVar7);
  uVar11 = uVar7 * iVar2 + uVar8;
  uVar4 = (uint)*(ushort *)(param_1 + 0x48);
  puVar5 = (ushort *)((*(int *)(param_1 + 0x6c) * uVar7 + 4) * uVar4 + iVar9);
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*puVar5 == uVar4 || *puVar5 == 0) break;
      puVar5 = puVar5 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar4);
  }
  puVar10 = (uint *)(iVar9 + uVar3 * 4);
  iVar2 = uVar3 * uVar7 * *(int *)(param_1 + 0x6c) + iVar9 + uVar4 * 4;
  if ((*puVar10 & 0x80000000) != 0) {
    uVar4 = *puVar10 & 0x7fffffff;
    uVar3 = 0;
    sVar6 = 0;
    if (uVar7 != 0) {
      do {
        if (uVar4 + uVar3 < *(int *)(param_1 + 0xc) + uVar8) {
          sVar6 = sVar6 + 1;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < uVar7);
    }
    iVar9 = fs_dev_op2(param_1,uVar4,iVar2,sVar6);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
       (iVar9 = fs_dev_op2(param_1,*(int *)(param_1 + 0xc) + (*puVar10 & 0x7fffffff),iVar2,1),
       iVar9 != 0)) {
      return iVar9;
    }
  }
  iVar2 = fs_dev_op1(param_1,uVar11,iVar2,*(undefined2 *)(param_1 + 0x4a));
  if (iVar2 == 0) {
    *puVar10 = uVar11;
    uVar1 = fatcache_lookup(param_1,param_2);
    *param_3 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== fatcache_touch @ 20143e10 (156 bytes)

/* Ages the FAT cache slots and makes the given one the newest [fact] */

void fatcache_touch(int param_1,uint param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort unaff_r5;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x48);
  if (uVar5 != 0) {
    unaff_r5 = 1;
  }
  puVar2 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + 4) * uVar5 +
           *(int *)(param_1 + 0x44));
  uVar1 = puVar2[param_2 - 1];
  uVar3 = 1;
  if (uVar5 != 0) {
    do {
      uVar4 = *puVar2;
      if ((uVar4 == 0 || uVar3 == param_2) || ((uVar1 <= uVar4 && (uVar1 != 0)))) {
        if (uVar3 != param_2) goto LAB_20143e80;
        *puVar2 = unaff_r5;
      }
      else {
        uVar4 = uVar4 + 1;
        *puVar2 = uVar4;
LAB_20143e80:
        if (uVar4 == 0) {
          return;
        }
      }
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= *(ushort *)(param_1 + 0x48));
  }
  return;
}


// ===== fs_dircache_setup @ 20143eac (204 bytes)

/* (drive, buffer, size, sectors per slot): directory cache (0x208 bytes per sector, at least 3
   slots), -28 otherwise [fact] */

void fs_dircache_setup(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = fs_check_ready();
  if (iVar1 != 0) {
    fs_set_error(iVar1,0);
    return;
  }
  if ((param_2 != 0 && param_4 != 0) && ((uint)(param_4 * 0x208) <= param_3)) {
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    uVar2 = __aeabi_uidivmod(param_3,param_4 * 0x208);
    bVar3 = 0x7fff < uVar2;
    if (bVar3) {
      uVar2 = 0x7fff;
    }
    if (bVar3 || 2 < uVar2) {
      *(short *)(param_1 + 0x50) = (short)uVar2;
      *(uint *)(param_1 + 0x4c) = param_2;
      *(short *)(param_1 + 0x52) = (short)param_4;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
      fs_memset(param_2,0,uVar2 * param_4 * 0x208,*(undefined4 *)(param_1 + 0x6c));
      fs_set_error(0);
      return;
    }
  }
  fs_set_error(0xffffffe4,0);
  return;
}


// ===== dircache_lookup @ 20143f78 (136 bytes)

/* Slot number of the directory/data cache slot holding a sector, 0 for a miss [fact] */

uint dircache_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint i;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x50);
  puVar2 = *(uint **)(param_1 + 0x4c);
  puVar4 = (uint *)((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 4) * uVar3 +
                   (int)puVar2);
  i = 0;
  if (uVar3 != 0) {
    do {
      uVar1 = *puVar2;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < (ushort)*puVar4 + uVar1)) {
        return i * *(ushort *)(param_1 + 0x52) + (param_2 - uVar1) + 1 & 0xffff;
      }
      i = i + 1;
      puVar2 = puVar2 + 1;
      puVar4 = (uint *)((int)puVar4 + 2);
    } while (i < uVar3);
  }
  return 0;
}


// ===== dircache_load @ 20144000 (616 bytes)

/* Evicts the oldest directory cache slot (write back when dirty) and reads the sectors, clipped to
   the fixed root directory for FAT12/16 [fact] */

int dircache_load(int param_1,uint param_2,undefined2 *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x50);
  iVar12 = *(int *)(param_1 + 0x4c);
  iVar8 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
  puVar7 = (ushort *)((iVar8 + 6) * uVar5 + iVar12);
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      if (uVar5 == (*puVar7 & 0xffff7fff) || (*puVar7 & 0x7fff) == 0) break;
      puVar7 = puVar7 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar5);
  }
  piVar10 = (int *)(iVar12 + uVar3 * 4);
  iVar6 = uVar3 * (uint)*(ushort *)(param_1 + 0x52) * *(int *)(param_1 + 0x6c) + iVar12 + uVar5 * 4;
  puVar9 = (ushort *)((iVar8 + 4) * uVar5 + iVar12 + uVar3 * 2);
  if (((*puVar7 & 0x8000) != 0) && (iVar8 = fs_dev_op2(param_1,*piVar10,iVar6,*puVar9), iVar8 != 0))
  {
    return iVar8;
  }
  if (*(char *)(param_1 + 0x10) != ' ') {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    uVar3 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    iVar8 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
            (uint)*(ushort *)(param_1 + 6);
    if (param_2 < uVar3 + iVar8) {
      uVar5 = uVar3 & 0xffff;
      uVar1 = *(ushort *)(param_1 + 0x52);
      uVar11 = (uint)uVar1;
      if (uVar5 <= uVar11) {
        *puVar9 = (ushort)uVar3;
        iVar12 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                 (uint)*(ushort *)(param_1 + 6);
        iVar8 = fs_dev_op1(param_1,iVar12,iVar6,uVar5);
        if (iVar8 != 0) {
          return iVar8;
        }
        *piVar10 = iVar12;
        uVar2 = dircache_lookup(param_1,iVar12);
        *param_3 = uVar2;
        return 0;
      }
      iVar12 = __aeabi_uidivmod(param_2 - iVar8,uVar11);
      uVar5 = uVar5 - uVar11 * iVar12;
      iVar8 = iVar8 + uVar11 * iVar12;
      if (uVar5 < uVar11) {
        *puVar9 = (ushort)uVar5;
      }
      else {
        *puVar9 = uVar1;
      }
      iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
      if (iVar12 != 0) {
        return iVar12;
      }
      goto LAB_201441cc;
    }
  }
  if (*(ushort *)(param_1 + 0x52) < *(ushort *)(param_1 + 4)) {
                    /* Cluster number of a data sector [doc] */
    uVar4 = fat_sect2clust(param_1,param_2);
    iVar8 = fat_clust2sect(param_1,uVar4);
    uVar1 = *(ushort *)(param_1 + 0x52);
    uVar5 = (uint)uVar1;
    iVar12 = __aeabi_uidivmod(param_2 - iVar8,uVar5);
    iVar8 = iVar8 + uVar5 * iVar12;
    uVar3 = (uint)*(ushort *)(param_1 + 4) - uVar5 * iVar12;
    if (uVar3 < uVar5) {
      *puVar9 = (ushort)uVar3;
    }
    else {
      *puVar9 = uVar1;
    }
    iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
      *piVar10 = iVar8;
      uVar2 = dircache_lookup(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  else {
    *puVar9 = *(ushort *)(param_1 + 4);
    uVar4 = fat_sect2clust(param_1,param_2);
    iVar8 = fat_clust2sect(param_1,uVar4);
    iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
LAB_201441cc:
      *piVar10 = iVar8;
      uVar2 = dircache_lookup(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  return iVar12;
}


// ===== dircache_touch @ 20144268 (420 bytes)

/* Ages the directory cache slots and makes the given one the newest [fact] */

void dircache_touch(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar7 = (uint)*(ushort *)(param_1 + 0x50);
  puVar3 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
           *(int *)(param_1 + 0x4c));
  uVar1 = *(ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
            *(int *)(param_1 + 0x4c) + param_2 * 2 + -2);
  uVar4 = 1;
  if (*(char *)(param_1 + 0x10) == '@') {
    if (uVar7 != 0) {
      do {
        uVar2 = *puVar3;
        if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
           (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
          if (uVar4 == param_2) {
            *puVar3 = uVar2 & 0x8000 | 1;
          }
          if ((uVar2 & 0x7fff) == 0) {
            return;
          }
        }
        else {
          uVar5 = uVar2 + 1;
          uVar6 = uVar2 + 1;
          *puVar3 = uVar5;
          if ((uVar2 & 0x8000) == 0) {
            if (uVar6 < 0x8000) goto LAB_20144364;
            uVar6 = uVar5 & 0x7fff;
          }
          else {
            if (0x7fff < uVar6) {
              uVar6 = uVar5 & 0x7fff;
              *puVar3 = uVar6;
            }
            uVar6 = uVar6 | 0x8000;
          }
          *puVar3 = uVar6;
        }
LAB_20144364:
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1 & 0xffff;
        if (*(ushort *)(param_1 + 0x50) < uVar4) {
          return;
        }
      } while( true );
    }
  }
  else if (uVar7 != 0) {
    do {
      uVar2 = *puVar3;
      if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
         (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
        if (uVar4 == param_2) {
          *puVar3 = uVar2 & 0x8000 | 1;
        }
        if ((uVar2 & 0x7fff) == 0) {
          return;
        }
      }
      else {
        uVar5 = uVar2 + 1;
        uVar6 = uVar2 + 1;
        *puVar3 = uVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar6 < 0x8000) goto LAB_20144300;
          uVar6 = uVar5 & 0x7fff;
        }
        else {
          if (0x7fff < uVar6) {
            uVar6 = uVar5 & 0x7fff;
            *puVar3 = uVar6;
          }
          uVar6 = uVar6 | 0x8000;
        }
        *puVar3 = uVar6;
      }
LAB_20144300:
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 <= *(ushort *)(param_1 + 0x50));
  }
  return;
}


// ===== dircache_flush @ 2014440c (284 bytes)

/* Writes every dirty directory cache slot back (fs_dev_op2) and clears the dirty bit [fact] */

int dircache_flush(int param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar4 = *(undefined4 **)(param_1 + 0x4c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar6 = 0;
    iVar2 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
    uVar1 = (uint)*(ushort *)(param_1 + 0x50);
    puVar3 = (ushort *)((iVar2 + 6) * uVar1 + (int)puVar4);
    puVar5 = (undefined4 *)((iVar2 + 4) * uVar1 + (int)puVar4);
    puVar7 = puVar4 + uVar1;
    if (*(char *)(param_1 + 0x10) == '@') {
      if (uVar1 != 0) {
        do {
          if ((*puVar3 & 0x8000) != 0) {
            iVar2 = fs_dev_op2(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
            if (iVar2 != 0) {
              return iVar2;
            }
            *puVar3 = *puVar3 & 0x7fff;
          }
          iVar6 = iVar6 + 1;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = (undefined4 *)((int)puVar5 + 2);
          puVar7 = (undefined4 *)
                   (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
        } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
      }
    }
    else if (uVar1 != 0) {
      do {
        if ((*puVar3 & 0x8000) != 0) {
          iVar2 = fs_dev_op2(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
          *puVar3 = *puVar3 & 0x7fff;
        }
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 2);
        puVar7 = (undefined4 *)
                 (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
      } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
    }
  }
  return 0;
}


// ===== fatcache_flush @ 2014455c (248 bytes)

/* Writes every dirty FAT cache slot back, also to the second FAT for single-sector slots [fact] */

int fatcache_flush(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  puVar4 = *(uint **)(param_1 + 0x44);
  if (puVar4 != (uint *)0x0) {
    puVar6 = puVar4 + *(ushort *)(param_1 + 0x48);
    puVar7 = puVar6;
    for (; puVar4 != puVar6; puVar4 = puVar4 + 1) {
      if ((*puVar4 & 0x80000000) != 0) {
        uVar5 = *puVar4 & 0x7fffffff;
        uVar1 = 0;
        sVar3 = 0;
        if (*(ushort *)(param_1 + 0x4a) != 0) {
          do {
            if (uVar5 + uVar1 < (uint)*(ushort *)(param_1 + 6) + *(int *)(param_1 + 0xc)) {
              sVar3 = sVar3 + 1;
            }
            uVar1 = uVar1 + 1 & 0xffff;
          } while (uVar1 < *(ushort *)(param_1 + 0x4a));
        }
        iVar2 = fs_dev_op2(param_1,uVar5,puVar7,sVar3);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
           (iVar2 = fs_dev_op2(param_1,*(int *)(param_1 + 0xc) + uVar5,puVar7,1), iVar2 != 0)) {
          return iVar2;
        }
        *puVar4 = *puVar4 & 0x7fffffff;
      }
      puVar7 = (uint *)(*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + (int)puVar7);
    }
  }
  return 0;
}


// ===== fatcache_flush_locked @ 20144654 (52 bytes)

/* fatcache_flush under fs_lock_b [fact] */

undefined4 fatcache_flush_locked(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fatcache_flush(param_1);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fs_flush @ 20144688 (104 bytes)

/* fatcache_flush, then dircache_flush under fs_lock_a; fclose, remove and mkdir end with it [fact]
    */

int fs_flush(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
                    /* fatcache_flush under fs_lock_b [doc] */
  if ((iVar1 == 0) && (iVar1 = fatcache_flush_locked(param_1), iVar1 == 0)) {
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
    iVar1 = fs_lock_a();
    if (iVar1 == 0) {
                    /* Writes every dirty directory cache slot back [doc] */
      iVar1 = dircache_flush(param_1);
      fs_unlock_a(param_1);
    }
    else {
      iVar1 = -0x25;
    }
    return iVar1;
  }
  return iVar1;
}


// ===== fs_sync @ 201446bc (20 bytes)

/* fs_flush with fs_set_error [fact] */

void fs_sync(void)

{
  undefined4 uVar1;
  
  uVar1 = fs_flush();
  fs_set_error(uVar1,0);
  return;
}


// ===== fs_cache_invalidate @ 201446d0 (292 bytes)

/* Clears the FAT cache, the cluster bitmap (clusters 0, 1 and the FAT32 root kept) and the
   directory cache of a drive [fact] */

void fs_cache_invalidate(int param_1)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
  if (iVar1 != 0) {
    fs_set_error(iVar1,0);
    return;
  }
  iVar1 = fs_lock_b(param_1);
  if (iVar1 != 0) {
    fs_set_error(0xffffffde,0);
    return;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(*(int *)(param_1 + 0x44),0,
              (uint)*(ushort *)(param_1 + 0x48) * (uint)*(ushort *)(param_1 + 0x4a) * 0x206,
              *(undefined4 *)(param_1 + 0x6c));
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    fs_memset(*(int *)(param_1 + 0x58),0,*(undefined4 *)(param_1 + 0x5c),
              *(undefined4 *)(param_1 + 0x6c));
                    /* Sets a cluster's bit in the bitmap +0x58 [doc] */
    clmap_set(param_1,0);
    clmap_set(param_1,1);
    if (*(char *)(param_1 + 0x10) == ' ') {
      clmap_set(param_1,*(undefined4 *)(param_1 + 0x34));
    }
  }
  fs_unlock_b(param_1);
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
  iVar1 = fs_lock_a(param_1);
  if (iVar1 != 0) {
    fs_set_error(0xffffffdb,0);
    return;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    fs_memset(*(int *)(param_1 + 0x4c),0,
              (uint)*(ushort *)(param_1 + 0x50) * (uint)*(ushort *)(param_1 + 0x52) * 0x208,
              *(undefined4 *)(param_1 + 0x6c));
  }
  fs_unlock_a(param_1);
  fs_set_error(0);
  return;
}


// ===== FUN_201447f4 @ 201447f4 (12 bytes)

undefined4 FUN_201447f4(void)

{
  return DAT_20808ba4;
}


// ===== fs_set_error @ 20144800 (52 bytes)

/* (err, file): last error 0x20808BA4 = err, FUN_2014d98c(err), file+0x10 = err; returns -1 for err
   < 0 [fact] */

undefined4 fs_set_error(int param_1,int param_2)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  fs_task_err_set(param_1);
  if (param_2 != 0) {
    *(int *)(param_2 + 0x10) = param_1;
  }
  if (param_1 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_set_error_m2 @ 20144834 (40 bytes)

/* Last error 0x20808BA4 and per-task error = err, returns -2 for err < 0 else 0 [fact] */

undefined4 fs_set_error_m2(int param_1)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  fs_task_err_set(param_1);
  if (param_1 < 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_set_error_ret @ 2014485c (28 bytes)

/* (err, ret): last error 0x20808BA4 = err, returns ret [fact] */

undefined4 fs_set_error_ret(undefined4 param_1,undefined4 param_2)

{
  DAT_20808ba4 = param_1;
  fs_task_err_set();
  return param_2;
}


// ===== fs_file_check @ 20144878 (32 bytes)

/* -13 for a null file, -6 when the open flag +0x442 is clear, else 0; used by the file calls
   (fclose, fread, fwrite, fseek, fs_fsize) [fact] */

undefined4 fs_file_check(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 0x442) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_dir_check @ 20144898 (32 bytes)

/* -13 for a null handle, -6 when its open flag +4 is clear (directory handles) [inference: callers
   0x2014C474 / 0x2014CA08] */

undefined4 fs_dir_check(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fat_sector_is_cluster_first @ 201448b8 (96 bytes)

/* 1 when a data sector is the first sector of its cluster (sectors per cluster > 1) [fact] */

undefined4 fat_sector_is_cluster_first(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (1 < uVar1) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    __aeabi_uidivmod((param_2 -
                     (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                              (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 == 1) {
      return 1;
    }
  }
  return 0;
}


// ===== fs_find_drive @ 20144918 (56 bytes)

/* (letter, *drv): walks the drive list 0x20808BA0 for +0x11 == letter; -12 when missing [fact] */

undefined4 fs_find_drive(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = DAT_20808ba0;
  do {
    if (*(char *)((int)piVar1 + 0x11) == param_1) {
      if (param_2 != (int *)0x0) {
        *param_2 = (int)piVar1;
      }
      return 0;
    }
    piVar1 = (int *)*piVar1;
  } while (piVar1 != (int *)0x0);
  return 0xfffffff4;
}


// ===== fs_drive_check_mounted @ 20144950 (32 bytes)

/* -19 for a removable drive (+0x68 bit 0) that is not mounted (bit 7), else 0 [fact] */

undefined4 fs_drive_check_mounted(int param_1)

{
  undefined4 uVar1;
  
  if ((((int)*(char *)(param_1 + 0x68) & 1U) == 0) ||
     (((int)*(char *)(param_1 + 0x68) & 0x80U) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffed;
  }
  return uVar1;
}


// ===== fs_drive_check_writable @ 20144970 (16 bytes)

/* -58 when the drive is write-protected (+0x68 bit 5) [fact] */

uint fs_drive_check_writable(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x68) & 0x20;
  if ((*(byte *)(param_1 + 0x68) & 0x20) != 0) {
    uVar1 = 0xffffffc6;
  }
  return uVar1;
}


// ===== fat_clust2sect @ 20144980 (76 bytes)

/* (vol, cluster): 0 for cluster < 2, else data start + (cluster - 2) * sectors per cluster [fact]
    */

int fat_clust2sect(int param_1,uint param_2)

{
  int iVar1;
  
  if (1 < param_2) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    return *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + iVar1 +
           (param_2 - 2) * (uint)*(ushort *)(param_1 + 4) + (uint)*(ushort *)(param_1 + 6);
  }
  return 0;
}


// ===== fat_sect2clust @ 201449cc (68 bytes)

/* Cluster number of a data sector: (sector - data start) / sectors per cluster + 2 (inverse of
   fat_clust2sect) [fact] */

int fat_sect2clust(int param_1,int param_2)

{
  int iVar1;
  
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar1 = __aeabi_uidivmod(param_2 - (iVar1 + *(int *)(param_1 + 0xc) *
                                              (uint)*(ushort *)(param_1 + 8) +
                                              (uint)*(ushort *)(param_1 + 6)),
                           *(undefined2 *)(param_1 + 4));
  return iVar1 + 2;
}


// ===== fs_dev_op1 @ 20144a10 (176 bytes)

/* (drv, ...): device op +0x18 with command 1 between the device locks of drv+0x70; -46 / -47 on
   lock errors [fact] */

undefined4 fs_dev_op1(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = fs_sem_wait_1s(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      fs_set_error(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,1,param_2,param_3,param_4);
    iVar2 = fs_sem_signal(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      fs_set_error(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      fs_set_error(0);
      return 0;
    }
  }
  fs_set_error(0xfffffff8,0);
  return 0xfffffff8;
}


// ===== fs_dev_op2 @ 20144ac0 (176 bytes)

/* Same with command 2 [fact] */

undefined4 fs_dev_op2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = fs_sem_wait_1s(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      fs_set_error(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,2,param_2,param_3,param_4);
    iVar2 = fs_sem_signal(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      fs_set_error(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      fs_set_error(0);
      return 0;
    }
  }
  fs_set_error(0xfffffff7,0);
  return 0xfffffff7;
}


// ===== dir_sector_dirty @ 20144b74 (144 bytes)

/* Marks a directory/data sector dirty in the directory cache, or writes it (fs_dev_op2) when there
   is none; -0x45 when not cached [fact] */

undefined4 dir_sector_dirty(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong __aeabi_idivmod_ret;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar2 = fs_dev_op2(param_1,param_2,param_3,1);
    return uVar2;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffbb;
  }
  else {
    __aeabi_idivmod_ret = __aeabi_idivmod(iVar1 - 1,(uint)*(ushort *)(param_1 + 0x52));
    uVar3 = (int)__aeabi_idivmod_ret + 1U & 0xffff;
    dircache_touch(param_1,uVar3);
    iVar1 = (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) *
            (uint)*(ushort *)(param_1 + 0x50) + *(int *)(param_1 + 0x4c) + uVar3 * 2;
    *(ushort *)(iVar1 + -2) = *(ushort *)(iVar1 + -2) | 0x8000;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== root_sector_dirty @ 20144c04 (88 bytes)

/* dir_sector_dirty for sector n of the FAT12/16 root directory, -11 past its end [fact] */

undefined4 root_sector_dirty(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = dir_sector_dirty(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== dir_sector_get @ 20144c5c (168 bytes)

/* (vol, sector, *ptr): pointer to a directory/data sector through the directory cache, direct read
   when there is none [fact] */

int dir_sector_get(int param_1,undefined4 param_2,int *param_3,uint param_4)

{
  int iVar1;
  ulonglong __aeabi_idivmod_ret;
  uint local_18;
  
  local_18 = param_4;
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = fs_dev_op1(param_1,param_2,*param_3,1);
    return iVar1;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
                    /* Evicts the oldest directory cache slot [doc] */
    iVar1 = dircache_load(param_1,param_2,&local_18);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    local_18 = CONCAT22(local_18._2_2_,(short)iVar1);
  }
  *param_3 = ((local_18 & 0xffff) - 1) * *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x4c) +
             (uint)*(ushort *)(param_1 + 0x50) * 4;
  __aeabi_idivmod_ret = __aeabi_idivmod((local_18 & 0xffff) - 1,(uint)*(ushort *)(param_1 + 0x52));
  local_18 = CONCAT22(local_18._2_2_,(short)__aeabi_idivmod_ret + 1);
  dircache_touch(param_1);
  return 0;
}


// ===== root_sector_get @ 20144d04 (88 bytes)

/* (vol, n, *ptr): sector n of the fixed FAT12/16 root directory (after reserved + FATs), -11 past
   its end [fact] */

undefined4 root_sector_get(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = dir_sector_get(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== lfn_entry_fill @ 20144d5c (348 bytes)

/* (entry, name part, vol): fills one 32-byte long-name directory entry: zeroed, 0xFF padding in the
   three name fields, then the UCS-2 characters [fact for the fills] */

int lfn_entry_fill(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(param_1,0,0x20,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 1,0xffffffff,10,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 0xe,0xffffffff,0xc,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 0x1c,0xffffffff,4,*(undefined4 *)(param_3 + 0x6c));
  iVar2 = 0;
  pcVar3 = (char *)(param_1 + 1);
  iVar1 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) {
      *pcVar3 = '\0';
      pcVar3[1] = '\0';
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 5);
  pcVar3 = (char *)(param_1 + 0xe);
  iVar2 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) goto LAB_20144eac;
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 6);
  pcVar3 = (char *)(param_1 + 0x1c);
  iVar2 = 0;
  while ((*param_2 != '\0' || (param_2[1] != '\0'))) {
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
    if (1 < iVar2) {
      return iVar1;
    }
  }
LAB_20144eac:
  *pcVar3 = '\0';
  pcVar3[1] = '\0';
  return iVar1;
}


// ===== lfn_checksum @ 20144eb8 (60 bytes)

/* Checksum of an 11-byte 8.3 name (rotate right and add), the value long-name entries carry [fact]
    */

uint lfn_checksum(int param_1)

{
  byte *pbVar1;
  int i;
  uint uVar2;
  
  uVar2 = 0;
  i = 0;
  do {
    pbVar1 = (byte *)(param_1 + i);
    i = i + 1;
    uVar2 = uVar2 + *pbVar1;
    uVar2 = (uVar2 & 1) << 7 | (uVar2 & 0xff) >> 1;
  } while (i < 10);
  return *(byte *)(param_1 + i) + uVar2 & 0xff;
}

