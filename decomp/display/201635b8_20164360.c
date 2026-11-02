// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201635b8 @ 201635b8 (44 bytes)

void FUN_201635b8(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 0xe);
  param_2[1] = *(undefined1 *)(param_1 + 0xf);
  param_2[2] = *(undefined1 *)(param_1 + 0x11);
  param_2[3] = *(undefined1 *)(param_1 + 0x12);
  param_2[4] = 0;
  return;
}


// ===== fwobj_version_text @ 201635e4 (24 bytes)

/* (obj, buf): sprintf "%-8s : V%s " (0x20428286) of the object's name (+4) and version (+0xE);
   fwfile_check_versions, fwfile_status_text and fwupdate_poll use it [fact] */

void fwobj_version_text(int param_1,undefined4 param_2)

{
  sprintf_veneer(param_2,&UNK_20428286,param_1 + 4,param_1 + 0xe);
  return;
}


// ===== fwname_pattern_match @ 20163600 (84 bytes)

/* prefix + 4 chars + ".sfl", case-insensitive, exact length */

uint fwname_pattern_match(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((*param_1 == param_3) && (iVar1 = strncasecmp(param_1[1],param_2,param_1[3]), iVar1 == 0)) &&
     (iVar1 = strncasecmp(param_1[2],param_1[4] + param_2,param_1[5]), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== scif_has_flag @ 20163654 (16 bytes)

/* RX event flag bound? */

byte scif_has_flag(scif_uart *uart)

{
  return uart->rx_flg != 0;
}


// ===== ml_enc_entry_clear @ 20163668 (28 bytes)

/* [fact] mainlink_tx_reset calls it for each 5-byte entry 0x2045F0C5 + 5 j + 0x32 i of the encoder
   queue (7 x 10); Ghidra FUN_20163668 (T24 round 9, app/mainlink.c) */

void ml_enc_entry_clear(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    *(undefined1 *)(param_1 + 2) = 0;
    puVar1 = param_1;
  }
  else {
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_20163684 @ 20163684 (36 bytes)

void FUN_20163684(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    param_1[2] = 0;
    puVar1 = param_1;
  }
  else {
    *(undefined1 *)((int)param_1 + 5) = 0;
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_201636a8 @ 201636a8 (16 bytes)

void FUN_201636a8(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ===== FUN_201636b8 @ 201636b8 (20 bytes)

void FUN_201636b8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


// ===== copy5 @ 201636cc (44 bytes)

/* Copies 5 bytes (encoder events, E1/E2 frames) [fact] */

void copy5(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  return;
}


// ===== ml_settings24_copy @ 201636f8 (52 bytes)

/* [fact] mainlink_get_settings24 passes (out, 0x2045006D), the settings of the last 0x24 frame;
   Ghidra FUN_201636f8 (T24 round 9, app/mainlink.c) */

void ml_settings24_copy(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  return;
}


// ===== FUN_2016372c @ 2016372c (68 bytes)

void FUN_2016372c(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  return;
}


// ===== FUN_20163770 @ 20163770 (28 bytes)

void FUN_20163770(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  return;
}


// ===== FUN_2016378c @ 2016378c (20 bytes)

void FUN_2016378c(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  return;
}


// ===== FUN_201637a0 @ 201637a0 (28 bytes)

void FUN_201637a0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
  return;
}


// ===== FUN_201637bc @ 201637bc (28 bytes)

void FUN_201637bc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
  return;
}


// ===== FUN_201637d8 @ 201637d8 (24 bytes)

void FUN_201637d8(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = param_2 & 0xff | param_2 << 8;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// ===== fill8 @ 201637f0 (24 bytes)

/* (dst, byte): fills 8 bytes with byte; vfo_clar_draw blanks its text buffer with spaces [fact] */

void fill8(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  return;
}


// ===== fp_classify_double @ 20163808 (40 bytes)

/* (lo, hi): class bits of a double for _printf_fp_dec (zero / normal / infinity-NaN from the
   exponent 0 / 0x7FF and the mantissa) [fact for the tests] */

uint fp_classify_double(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    uVar1 = 4;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 == 0x7ff) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 == 1) {
    uVar1 = 5;
  }
  return uVar1;
}


// ===== FUN_2016385a @ 2016385a (10 bytes)

void FUN_2016385a(void)

{
  __cxa_pure_virtual(0);
  return;
}


// ===== is_decimal_digit @ 20163864 (14 bytes)

/* (c): 1 for '0'..'9'; _printf_core uses it for widths [fact] */

undefined4 is_decimal_digit(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}


// ===== FUN_20163874 @ 20163874 (34 bytes)

undefined4 FUN_20163874(undefined4 param_1,uint *param_2)

{
  uint strcmp_ret;
  
  if (((param_2 != (uint *)0x0) && ((char)*param_2 != '\0')) &&
     (strcmp_ret = strcmp((uint *)(BYTE_ARRAY_204286f8 + 4),param_2), strcmp_ret != 0)) {
    return 0;
  }
  return 0x20428704;
}


// ===== FUN_201638a0 @ 201638a0 (34 bytes)

undefined4 FUN_201638a0(undefined4 param_1,uint *param_2)

{
  uint strcmp_ret;
  
  if (((param_2 != (uint *)0x0) && ((char)*param_2 != '\0')) &&
     (strcmp_ret = strcmp((uint *)(BYTE_ARRAY_204286f8 + 0x114),param_2), strcmp_ret != 0)) {
    return 0;
  }
  return 0x20428814;
}


// ===== FUN_201638cc @ 201638cc (12 bytes)

void FUN_201638cc(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_201638d8 @ 201638d8 (40 bytes)

void FUN_201638d8(int param_1,undefined2 param_2)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (i < 0x4b0);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x968) = param_1;
  return;
}


// ===== FUN_20163900 @ 20163900 (56 bytes)

void FUN_20163900(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    iVar2 = i * 2;
    i = i + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (i < 0x4b0);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0x25a] = param_1;
  return;
}


// ===== FUN_20163938 @ 20163938 (264 bytes)

void FUN_20163938(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
                    /* Double to signed int, truncating with saturation [doc] */
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}


// ===== FUN_20163a40 @ 20163a40 (160 bytes)

void FUN_20163a40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int j;
  int i;
  uint uVar1;
  
  i = 0;
  if (*param_5 != 0) {
    do {
      uVar1 = (uint)param_5[1];
      j = 0;
      if (uVar1 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + i * 2 + (uint)*param_5 * j * 2) != 0) {
            FUN_20163938(param_1,j,param_3,param_4,param_5,uVar1 - j,i);
            break;
          }
          j = j + 1;
        } while (j < (int)uVar1);
      }
      i = i + 1;
    } while (i < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163ae0 @ 20163ae0 (44 bytes)

void FUN_20163ae0(int param_1,undefined2 param_2)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (i < 0x870);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x10e8) = param_1;
  return;
}


// ===== FUN_20163b0c @ 20163b0c (12 bytes)

void FUN_20163b0c(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_20163b18 @ 20163b18 (48 bytes)

void FUN_20163b18(int param_1,undefined2 param_2)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (i < 0x15cc);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x2ba0) = param_1;
  return;
}


// ===== FUN_20163b48 @ 20163b48 (12 bytes)

undefined4 FUN_20163b48(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2ba0);
}


// ===== FUN_20163b54 @ 20163b54 (72 bytes)

void FUN_20163b54(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    iVar2 = i * 2;
    i = i + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (i < 0x15cc);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0xae8] = param_1;
  return;
}


// ===== FUN_20163b9c @ 20163b9c (264 bytes)

void FUN_20163b9c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
                    /* Double to signed int, truncating with saturation [doc] */
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}


// ===== FUN_20163ca4 @ 20163ca4 (160 bytes)

void FUN_20163ca4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int j;
  int i;
  uint uVar1;
  
  i = 0;
  if (*param_5 != 0) {
    do {
      uVar1 = (uint)param_5[1];
      j = 0;
      if (uVar1 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + i * 2 + (uint)*param_5 * j * 2) != 0) {
            FUN_20163b9c(param_1,j,param_3,param_4,param_5,uVar1 - j,i);
            break;
          }
          j = j + 1;
        } while (j < (int)uVar1);
      }
      i = i + 1;
    } while (i < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163d44 @ 20163d44 (40 bytes)

void FUN_20163d44(int param_1,undefined2 param_2)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (i < 0x40);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x88) = param_1;
  return;
}


// ===== FUN_20163d6c @ 20163d6c (264 bytes)

void FUN_20163d6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
                    /* Double to signed int, truncating with saturation [doc] */
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}


// ===== FUN_20163e74 @ 20163e74 (160 bytes)

void FUN_20163e74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int j;
  int i;
  uint uVar1;
  
  i = 0;
  if (*param_5 != 0) {
    do {
      uVar1 = (uint)param_5[1];
      j = 0;
      if (uVar1 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + i * 2 + (uint)*param_5 * j * 2) != 0) {
            FUN_20163d6c(param_1,j,param_3,param_4,param_5,uVar1 - j,i);
            break;
          }
          j = j + 1;
        } while (j < (int)uVar1);
      }
      i = i + 1;
    } while (i < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163f14 @ 20163f14 (48 bytes)

void FUN_20163f14(int param_1,undefined2 param_2)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (i < 0x1c20);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x3848) = param_1;
  return;
}


// ===== FUN_20163f44 @ 20163f44 (52 bytes)

void FUN_20163f44(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  FUN_20134124(*(undefined1 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x97c),
               *(undefined4 *)(param_1 + 0x10));
  return;
}


// ===== FUN_20163f80 @ 20163f80 (88 bytes)

void FUN_20163f80(undefined1 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 *param_5)

{
  *(short *)(param_1 + 8) = (short)param_3;
  FUN_201638d8(param_1 + 0x14,0);
  FUN_201638cc(param_1 + 0x14,param_3,*param_5);
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined2 **)(param_1 + 0x10) = param_5;
  *param_1 = param_2;
  return;
}


// ===== FUN_20163fd0 @ 20163fd0 (72 bytes)

undefined1 * FUN_20163fd0(undefined1 *param_1,undefined1 *param_2)

{
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  FUN_20163900(param_1 + 0x14,param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  return param_1;
}


// ===== FUN_20164018 @ 20164018 (52 bytes)

void FUN_20164018(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  uVar1 = FUN_20163b48(param_1 + 0x14);
  FUN_20134124(*(undefined1 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 0xc),uVar1,*(undefined4 *)(param_1 + 0x10));
  return;
}


// ===== FUN_20164054 @ 20164054 (88 bytes)

void FUN_20164054(undefined1 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 *param_5)

{
  *(short *)(param_1 + 8) = (short)param_3;
  FUN_20163b18(param_1 + 0x14,0);
  FUN_20163b0c(param_1 + 0x14,param_3,*param_5);
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined2 **)(param_1 + 0x10) = param_5;
  *param_1 = param_2;
  return;
}


// ===== FUN_201640a4 @ 201640a4 (72 bytes)

undefined1 * FUN_201640a4(undefined1 *param_1,undefined1 *param_2)

{
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  FUN_20163b54(param_1 + 0x14,param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  return param_1;
}


// ===== copy10 @ 201640ec (24 bytes)

/* (dst, src): memcpy of 10 bytes, returns dst; firmware-object version fields
   (fwfile_check_versions, fwobj_*) [fact] */

undefined4 copy10(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,10);
  return param_1;
}


// ===== copy32 @ 20164104 (24 bytes)

/* (dst, src): memcpy of 0x20 bytes, returns dst; firmware-object name fields [fact] */

undefined4 copy32(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,0x20);
  return param_1;
}


// ===== copy48 @ 2016411c (24 bytes)

/* (dst, src): memcpy of 0x30 bytes, returns dst; fwobj_base_ctor [fact] */

undefined4 copy48(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_1,param_2,0x30);
  return param_1;
}


// ===== FUN_20164298 @ 20164298 (156 bytes)

void FUN_20164298(int param_1,int param_2,ushort *param_3,ushort *param_4)

{
  ushort uVar1;
  
  uVar1 = *param_3;
  if (uVar1 < 4) {
    *param_4 = 0;
    param_4[1] = 0;
    return;
  }
  if (param_3[1] == 0) {
    *param_4 = uVar1;
    uVar1 = param_3[1];
  }
  else {
    uVar1 = *(short *)(*(int *)(param_1 + 0x3c) + param_2 * 0x62e + (uint)uVar1 * 2 + -8) + 399;
    *param_4 = uVar1;
    uVar1 = (*(short *)(*(int *)(param_1 + 0x3c) + param_2 * 0x62e +
                       ((uint)param_3[1] + (uint)*param_3) * 2 + -10) - uVar1) + 400;
  }
  param_4[1] = uVar1;
  return;
}


// ===== scope3d_widths_init @ 20164334 (44 bytes)

/* (table, ...): fills the 3DSS line width table 0x317 - 10*i (gui.md: line i is 791 - 10i wide)
   [fact] */

void scope3d_widths_init(int param_1,undefined4 param_2)

{
  int iVar1;
  int i;
  short sVar2;
  
  sVar2 = 0x317;
  i = 0;
  do {
    iVar1 = i * 2;
    i = i + 1;
    *(short *)(param_1 + iVar1) = sVar2;
    sVar2 = sVar2 + -10;
  } while (i < 0x1e);
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  return;
}


// ===== ring100_advance @ 20164360 (28 bytes)

/* (idx): returns *idx and advances it with ring100_next; affft_wf_add_row [fact] */

undefined4 ring100_advance(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
                    /* idx + 1, wrapping at 100 [doc] */
  uVar1 = ring100_next();
  *param_1 = uVar1;
  return uVar2;
}

