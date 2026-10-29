// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== backlight_pwm_init @ 2010261c (124 bytes)

/* MTU2 ch3/ch4 reset-synchronised PWM, period 320 counts, TIOC4D out */

void backlight_pwm_init(void)

{
  byte bVar1;
  
  DAT_fcff0200 = 0x40;
  DAT_fcff0210 = 0;
  DAT_fcff0212 = 0;
  DAT_fcff0218 = 0;
  DAT_fcff021a = 0x13f;
  DAT_fcff0224 = 0;
  DAT_fcff0226 = 0x13f;
  DAT_fcff021c = 0;
  DAT_fcff021e = 0;
  DAT_fcff0228 = 0;
  DAT_fcff022a = 0;
  DAT_fcff020e = 0x47;
  DAT_fcff020f = 0x7f;
  DAT_fcff0236 = 0x3f;
  DAT_fcff0202 = 0x38;
  bVar1 = DAT_fcff020a;
  DAT_fcff020a = bVar1 | 0x20;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 0x40;
  return;
}


// ===== backlight_set_pct @ 20102698 (72 bytes)

/* NEW ENTRY; duty = pct*320/100 -> TGRD_4 */

void backlight_set_pct(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== backlight_set @ 201026e0 (8 bytes)

/* thunk: backlight_set_pct */

void backlight_set(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== backlight_init @ 201026e8 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x201026a0) */
/* WARNING: Removing unreachable block (ram,0x201026ac) */
/* backlight_pwm_init + 60 % */

void backlight_init(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  backlight_pwm_init();
  iVar1 = div10_round(0x4b00,0,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== touch_cal_load @ 20102708 (108 bytes)

/* flash 0x183D0000: magic 0xA5C30001, 6 doubles, ~CRC-32 */

void touch_cal_load(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*param_1 != -1) && (*param_1 == -0x5a3cffff)) {
    crc32_make_table();
    uVar1 = crc32_update(0xffffffff,0x30,param_1 + 2);
    if (param_1[0xe] == ~uVar1) {
      iVar2 = param_1[3];
      iVar3 = param_1[4];
      iVar4 = param_1[5];
      *param_2 = param_1[2];
      param_2[1] = iVar2;
      param_2[2] = iVar3;
      param_2[3] = iVar4;
      iVar2 = param_1[7];
      iVar3 = param_1[8];
      iVar4 = param_1[9];
      param_2[4] = param_1[6];
      param_2[5] = iVar2;
      param_2[6] = iVar3;
      param_2[7] = iVar4;
      iVar2 = param_1[0xb];
      iVar3 = param_1[0xc];
      iVar4 = param_1[0xd];
      param_2[8] = param_1[10];
      param_2[9] = iVar2;
      param_2[10] = iVar3;
      param_2[0xb] = iVar4;
    }
  }
  return;
}


// ===== touch_cal_save @ 20102774 (132 bytes)

/* erase + write the 0x40-byte calibration record at flash 0x3D0000 */

void touch_cal_save(undefined4 *param_1)

{
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint local_18;
  
  local_50[0] = 0xa5c30001;
  local_48 = *param_1;
  uStack_44 = param_1[1];
  uStack_40 = param_1[2];
  uStack_3c = param_1[3];
  local_38 = param_1[4];
  uStack_34 = param_1[5];
  uStack_30 = param_1[6];
  uStack_2c = param_1[7];
  local_28 = param_1[8];
  uStack_24 = param_1[9];
  uStack_20 = param_1[10];
  uStack_1c = param_1[0xb];
  crc32_make_table();
  local_18 = crc32_update(0xffffffff,0x30,&local_48);
  local_18 = ~local_18;
  spiflash_erase(0,0x3d0000,0x40);
  spiflash_write(0x3d0000,local_50,0x40);
  return;
}


// ===== touch_cal_fit @ 201027f8 (1836 bytes)

/* least-squares affine fit of 5 measured vs 5 reference points */

void touch_cal_fit(undefined8 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = 0;
  do {
    *(undefined4 *)(&local_e0 + iVar3) = 0;
    *(undefined4 *)((int)&local_e0 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_58 + iVar3) = 0;
    *(undefined4 *)((int)&local_58 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_40 + iVar3) = 0;
    *(undefined4 *)((int)&local_40 + iVar3 * 8 + 4) = 0;
    iVar1 = iVar3 * 8;
    puVar10 = &local_70 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined4 *)puVar10 = 0;
    *(undefined4 *)((int)&local_70 + iVar1 + 4) = 0;
    uVar16 = CONCAT44(local_68._4_4_,(undefined4)local_68);
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    local_68 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bf8)[iVar3 * 2]);
    uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar4 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar4,uVar11,(undefined4)local_d0,local_d0._4_4_);
    local_d0 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bfa)[iVar3 * 2]);
    uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar5,uVar12,(undefined4)local_48,local_48._4_4_);
    local_48 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800060)[iVar3 * 2]);
    uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar6 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar6,uVar13,(undefined4)local_30,local_30._4_4_);
    local_30 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800062)[iVar3 * 2]);
    uVar14 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar7 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar7,uVar14,(undefined4)local_60,local_60._4_4_);
    local_60 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar4,uVar11);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_e0,
                          local_e0._4_4_);
    local_e0 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_d8,
                          local_d8._4_4_);
    local_d8 = uVar16;
    local_58 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_50,
                          local_50._4_4_);
    local_50 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_40,
                          local_40._4_4_);
    local_40 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_38,
                          local_38._4_4_);
    local_38 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_70,
                          local_70._4_4_);
    local_70 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_68,
                          local_68._4_4_);
    uVar5 = local_d0._4_4_;
    uVar4 = (undefined4)local_d0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  local_68 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_e0,local_e0._4_4_);
  uVar7 = local_48._4_4_;
  uVar6 = (undefined4)local_48;
  uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar8 = (undefined4)uVar16;
  local_e0 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_d8,local_d8._4_4_,(undefined4)local_48,local_48._4_4_);
  local_d8 = uVar16;
  local_78 = FUN_201649d8((undefined4)local_58,local_58._4_4_,uVar4,uVar5);
  local_58 = local_78;
  local_88 = FUN_201649d8((undefined4)local_50,local_50._4_4_,uVar6,uVar7);
  local_50 = local_88;
  local_98 = FUN_201649d8((undefined4)local_40,local_40._4_4_,uVar4,uVar5);
  local_40 = local_98;
  uVar17 = FUN_201649d8((undefined4)local_38,local_38._4_4_,uVar6,uVar7);
  local_c8._0_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  local_c0._0_4_ = (undefined4)local_c8;
  local_38 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_70,local_70._4_4_,uVar4,uVar5);
  local_70 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_68,local_68._4_4_,uVar6,uVar7);
  local_68 = uVar17;
  uVar17 = FUN_201649d8(uVar4,uVar5,0,0x40140000);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_d0 = uVar17;
  uVar18 = FUN_201649d8(uVar6,uVar7,0,0x40140000);
  uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
  local_48 = uVar18;
  uVar19 = FUN_201649d8((undefined4)local_30,local_30._4_4_,0,0x40140000);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  local_30 = uVar19;
  uVar20 = FUN_201649d8((undefined4)local_60,local_60._4_4_,0,0x40140000);
  local_60 = uVar20;
  uVar20 = FUN_20164fa4((undefined4)local_78,local_78._4_4_,(int)uVar18,uVar4);
  local_80 = (undefined4)((ulonglong)uVar20 >> 0x20);
  local_7c = (undefined4)uVar20;
  local_78._0_4_ = local_7c;
  local_78._4_4_ = local_80;
  local_b0 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,uVar5);
  uVar16 = FUN_20164da8((int)local_b0,(int)((ulonglong)local_b0 >> 0x20),(undefined4)local_78,
                        local_78._4_4_);
  local_a8 = FUN_20164fa4((undefined4)local_88,local_88._4_4_,(int)uVar18,uVar4);
  uVar2 = (ulonglong)local_a8 >> 0x20;
  uVar4 = (undefined4)local_a8;
  uVar17 = FUN_20164fa4(uVar8,uVar12,(int)uVar17,uVar5);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = FUN_20164da8((int)uVar17,uVar5,uVar4,(int)uVar2);
  uVar16 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar9 = (undefined4)uVar16;
  local_90._4_4_ = local_80;
  local_90._0_4_ = local_7c;
  uVar16 = FUN_20164fa4(uVar11,(undefined4)local_c8,(int)uVar19,uVar6);
  uVar4 = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_90 = FUN_20164da8((int)uVar16,uVar4,(undefined4)local_90,local_90._4_4_);
  local_c8 = local_a8;
  uVar18 = FUN_20164fa4((undefined4)local_98,local_98._4_4_,(int)uVar19,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_20164da8((int)uVar18,uVar6,(undefined4)local_c8,local_c8._4_4_);
  uVar19 = FUN_20164fa4((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(undefined4)local_90,
                        local_90._4_4_);
  uVar19 = FUN_201649d8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar9,uVar15);
  *param_1 = uVar19;
  uVar18 = FUN_20164da8((undefined4)local_b0,local_b0._4_4_,(int)uVar18,uVar6);
  uVar16 = FUN_20164da8((int)uVar17,uVar5,(int)uVar16,uVar4);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                        (int)((ulonglong)uVar18 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[1] = uVar16;
  local_b0._4_4_ = (undefined4)local_c0;
  local_b0._0_4_ = uVar11;
  local_98._0_4_ = uVar12;
  uVar16 = FUN_20164da8(uVar8,uVar12,uVar11);
  uVar5 = local_d8._4_4_;
  uVar4 = (undefined4)local_d8;
  local_c8 = local_40;
  uVar17 = FUN_20164da8((undefined4)local_d8,local_d8._4_4_);
  FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
               (int)((ulonglong)uVar16 >> 0x20));
  local_c0 = local_48;
  uVar16 = FUN_20164da8();
  uVar7 = local_d0._4_4_;
  uVar6 = (undefined4)local_d0;
  uVar17 = FUN_20164da8((undefined4)local_d0,local_d0._4_4_,(undefined4)local_c8,local_c8._4_4_);
  local_90 = local_30;
  uVar18 = FUN_20164da8(uVar8,(undefined4)local_98);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  local_b8 = local_50;
  uVar17 = FUN_20164da8();
  uVar18 = FUN_20164da8(uVar4,uVar5,(undefined4)local_90,local_90._4_4_);
  local_c8 = uVar18;
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_b0,local_b0._4_4_);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(undefined4)local_c8,local_c8._4_4_);
  local_c8 = local_58;
  uVar18 = FUN_20164da8();
  uVar17 = FUN_20164888((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[2] = uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_c8,local_c8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar14 = local_60._4_4_;
  uVar13 = (undefined4)local_60;
  local_90 = local_68;
  uVar17 = FUN_20164fa4();
  local_98._4_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_9c = (undefined4)uVar17;
  local_b0 = FUN_20164da8(local_9c,local_98._4_4_,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164fa4((undefined4)local_b8,local_b8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar12 = local_70._4_4_;
  uVar11 = (undefined4)local_70;
  local_88._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_a0 = (undefined4)uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_70,local_70._4_4_,uVar13,uVar14);
  local_a8 = uVar16;
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_a0,(undefined4)local_88);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[3] = uVar16;
  uVar16 = FUN_20164fa4(uVar4,uVar5,uVar6,uVar7);
  uVar16 = FUN_20164da8((undefined4)local_a8,local_a8._4_4_,(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  local_b0 = uVar16;
  uVar16 = FUN_20164fa4(uVar8,(undefined4)local_98,uVar6,uVar7);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_9c,local_98._4_4_);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[4] = uVar16;
  uVar16 = FUN_20164da8(uVar8,(undefined4)local_98,(undefined4)local_90,local_90._4_4_);
  local_b0 = uVar16;
  uVar16 = FUN_20164da8(uVar4,uVar5,uVar11,uVar12);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_c0,
                        local_c0._4_4_);
  local_c0._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_b0._0_4_ = (undefined4)uVar16;
  uVar16 = FUN_20164da8(uVar6,uVar7,uVar11,uVar12);
  uVar17 = FUN_20164da8(uVar8,(undefined4)local_98,uVar13,uVar14);
  uVar16 = FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b8,
                        local_b8._4_4_);
  uVar17 = FUN_20164da8(uVar4,uVar5,uVar13,uVar14);
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_90,local_90._4_4_);
  uVar17 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = FUN_20164da8((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(undefined4)local_c8,
                        local_c8._4_4_);
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        (undefined4)local_c0);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[5] = uVar16;
  return;
}


// ===== touch_cal_init @ 20102f34 (88 bytes)

/* boot: measured := reference points, load the record from flash */

void touch_cal_init(void)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  memcpy(&DAT_20808bf8,&DAT_20800060,0x14);
  touch_cal_fit(&local_38);
  touch_cal_load(&DAT_183d0000,&local_38);
  DAT_20808c10 = local_38;
  DAT_20808c14 = uStack_34;
  DAT_20808c18 = uStack_30;
  DAT_20808c1c = uStack_2c;
  DAT_20808c20 = local_28;
  DAT_20808c24 = uStack_24;
  DAT_20808c28 = uStack_20;
  DAT_20808c2c = uStack_1c;
  DAT_20808c30 = local_18;
  DAT_20808c34 = uStack_14;
  DAT_20808c38 = uStack_10;
  DAT_20808c3c = uStack_c;
  return;
}


// ===== touch_cal_set_point @ 20102f8c (68 bytes)

void touch_cal_set_point(int param_1,uint param_2,undefined2 *param_3)

{
  if (param_2 < 5) {
    if (param_1 == 0) {
      (&DAT_20800060)[param_2 * 2] = *param_3;
      (&DAT_20800062)[param_2 * 2] = param_3[1];
      return;
    }
    (&DAT_20808bf8)[param_2 * 2] = *param_3;
    (&DAT_20808bfa)[param_2 * 2] = param_3[1];
  }
  return;
}


// ===== touch_cal_store_points @ 20102fd0 (144 bytes)

/* set 4 points (ref set 0 / measured set 1); set 1 -> fit + save */

void touch_cal_store_points(int param_1,int param_2)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  touch_cal_set_point(param_1,2,param_2);
  touch_cal_set_point(param_1,3,param_2 + 4);
  touch_cal_set_point(param_1,0,param_2 + 8);
  touch_cal_set_point(param_1,1,param_2 + 0xc);
  if (param_1 != 0) {
    touch_cal_fit(&local_40);
    touch_cal_save(&local_40);
    DAT_20808c10 = local_40;
    DAT_20808c14 = uStack_3c;
    DAT_20808c18 = uStack_38;
    DAT_20808c1c = uStack_34;
    DAT_20808c20 = local_30;
    DAT_20808c24 = uStack_2c;
    DAT_20808c28 = uStack_28;
    DAT_20808c2c = uStack_24;
    DAT_20808c30 = local_20;
    DAT_20808c34 = uStack_1c;
    DAT_20808c38 = uStack_18;
    DAT_20808c3c = uStack_14;
  }
  return;
}


// ===== touch_cal_apply @ 20103060 (260 bytes)

/* (x, y) -> calibrated pixel, clamp 0..799 / 0..479 */

void touch_cal_apply(undefined4 param_1,undefined4 param_2,short *param_3,short *param_4)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar5 = FUN_20164d54(param_2);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c18,DAT_20808c1c);
  uVar7 = FUN_20164d54(param_1);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar8 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c10,DAT_20808c14);
  uVar6 = FUN_20164888((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
  uVar6 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_20808c20,DAT_20808c24);
  FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
  sVar1 = FUN_20164c90();
  uVar5 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c30,DAT_20808c34);
  uVar6 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c28,DAT_20808c2c);
  uVar5 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  uVar5 = FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_20808c38,DAT_20808c3c);
  FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
  sVar2 = FUN_20164c90();
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  else if (799 < sVar1) {
    sVar1 = 799;
  }
  if (sVar2 < 0) {
    sVar2 = 0;
  }
  else if (0x1df < sVar2) {
    sVar2 = 0x1df;
  }
  *param_3 = sVar1;
  *param_4 = sVar2;
  return;
}


// ===== touch_cal_selftest @ 20103164 (40 bytes)

/* apply to (100,100) after init (result unused) */

void touch_cal_selftest(void)

{
  undefined1 auStack_10 [4];
  undefined1 auStack_c [8];
  
  touch_cal_init();
  touch_cal_apply(100,100,auStack_10,auStack_c);
  return;
}


// ===== tsc2007_write_cmd @ 20103198 (96 bytes)

/* RIIC2 write of one command byte to 0x48 */

undefined4 tsc2007_write_cmd(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  FUN_20120674(2,0);
  iVar1 = FUN_20120750(2,0x90,0);
  if (iVar1 == 0) {
    FUN_2012081c(2,&uStack_10,1);
  }
  FUN_20120674(2);
  FUN_20120bc8(2);
  return 0;
}


// ===== tsc2007_read12 @ 201031f8 (248 bytes)

/* command byte, then read 2 bytes -> 12-bit result (-1/-2 on bus error) */

uint tsc2007_read12(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte local_14;
  byte local_13;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  iVar1 = FUN_20120674(2,0);
  if (iVar1 == 0) {
    iVar1 = FUN_20120750(2,0x90,0);
    if ((iVar1 == 0) && (iVar1 = FUN_2012081c(2,&uStack_10,1), iVar1 == 0)) {
      itron_dly_tsk(1);
      FUN_20120674(2,1);
      iVar1 = FUN_20120750(2,0x91,1,0);
      if (iVar1 == 0) {
        iVar1 = FUN_20120a9c(2,&local_14);
      }
    }
    if (iVar1 == -2) {
      FUN_20120674(2);
      FUN_20120bac(2);
      FUN_20120bc8(2);
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = (uint)local_14 << 4 | (int)(uint)local_13 >> 4;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== tsc2007_pressure @ 201032f0 (248 bytes)

/* Rtouch = 400 * X/4096 * (Z2/Z1 - 1) */

undefined4 tsc2007_pressure(short *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (*param_1 == 0xfff) {
    *param_1 = 0;
  }
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    uVar2 = FUN_20164d82(param_1[2]);
    uVar3 = FUN_20164d82(param_1[3]);
    uVar2 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                         (int)((ulonglong)uVar2 >> 0x20));
    uVar2 = FUN_20164fa4((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3ff00000);
    uVar3 = FUN_20164d82(*param_1);
    uVar3 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40b00000);
    uVar3 = FUN_20164da8(0,0x40790000,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    FUN_20164da8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                 (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = FUN_20164cf0();
  }
  return uVar1;
}


// ===== tsc2007_tint_isr @ 201033e8 (124 bytes)

/* IRQ3 (TINT falling): wake task_tsc2007 (was intc_irq_setup) */

void tsc2007_tint_isr(void)

{
  ushort uVar1;
  
  gic_disable_irq(0x23);
  DAT_20808c40 = DAT_20808c40 + 1;
  DAT_20800074 = DAT_20800074 + 1;
  itron_iwup_tsk(DAT_20800088);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 8) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xfff7;
  }
  return;
}


// ===== task_tsc2007 @ 20103464 (904 bytes)

void task_tsc2007(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  iVar2 = FUN_20120454(2);
  if (iVar2 == 0) {
    uVar1 = DAT_fcfef802;
    DAT_fcfef802 = uVar1 & 0xff3f;
    uVar1 = DAT_fcfef802;
    local_28 = (uint)uVar1;
    uVar1 = DAT_fcfef802;
    DAT_fcfef802 = uVar1 | 0x40;
    iVar2 = itron_acre_isr(0,&DAT_20165194);
    if (0 < iVar2) {
      FUN_20150ba0(&DAT_20800088);
      itron_iwup_tsk(DAT_2080008c);
      tsc2007_write_cmd(0xb0);
      itron_dly_tsk(10);
      do {
        while( true ) {
          local_30 = 0;
          local_2c = 0;
          iVar2 = tsc2007_write_cmd();
          if (-1 < iVar2) break;
          itron_dly_tsk(10);
        }
        while( true ) {
          itron_dly_tsk(1);
          uVar1 = DAT_fcfe3204;
          if ((uVar1 & 8) != 0) break;
          DAT_20808c48 = DAT_20808c48 + 1;
        }
        DAT_20808c44 = DAT_20808c44 + 1;
        touch_set_up();
        uVar1 = DAT_fcfef804;
        if ((uVar1 & 8) != 0) {
          uVar1 = DAT_fcfef804;
          DAT_fcfef804 = uVar1 & 0xfff7;
        }
        uVar1 = DAT_fcfef804;
        local_28 = (uint)uVar1;
        gic_enable_irq(0x23);
        FUN_201525f8(0xffffffff);
        iVar2 = 2;
        do {
          iVar2 = iVar2 + -1;
          iVar3 = tsc2007_read12(0xd4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          DAT_2080007c = (undefined2)iVar3;
          local_30._2_2_ = DAT_2080007c;
          iVar3 = tsc2007_read12(0xc4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          DAT_2080007a = (undefined2)iVar3;
          local_30 = CONCAT22(local_30._2_2_,DAT_2080007a);
          iVar3 = tsc2007_read12(0xe4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          local_2c = CONCAT22(local_2c._2_2_,(short)iVar3);
          iVar3 = tsc2007_read12(0xf4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          local_2c = CONCAT22((short)iVar3,(undefined2)local_2c);
          iVar3 = __aeabi_uidivmod(((local_30 & 0xffff) - 0xf3c) * 10000,0xfffff178);
          iVar3 = __aeabi_uidivmod(iVar3 * 800,10000);
          iVar4 = __aeabi_uidivmod(((local_30 >> 0x10) - 0x15e) * 10000,0xcb2);
          iVar4 = __aeabi_uidivmod(iVar4 * -0x1e0 + 4800000,10000);
          if ((((iVar3 < 0) || (799 < iVar3)) || (iVar4 < 0)) ||
             ((0x1df < iVar4 || (DAT_20800080 = tsc2007_pressure(&local_30), DAT_20800080 == 0))))
          break;
          if (DAT_20800080 < 0x514) {
            if (((DAT_20800495 != '\0') || (DAT_20800496 != '\0')) || (DAT_20808532 != '\0')) {
              touch_set_down(iVar3,iVar4);
              DAT_20800076 = (undefined2)iVar3;
              DAT_20800078 = (undefined2)iVar4;
              DAT_20800084 = DAT_20800084 + 1;
            }
            break;
          }
        } while (0 < iVar2);
      } while( true );
    }
  }
  return;
}


// ===== tsc2007_irq_flag @ 201037ec (24 bytes)

/* dly 20 ms, return 0x20800090 */

undefined4 tsc2007_irq_flag(void)

{
  itron_dly_tsk(0x14);
  return DAT_20800090;
}


// ===== task_tsc2007_irq @ 20103804 (84 bytes)

void task_tsc2007_irq(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20150ba0(&DAT_2080008c);
  do {
    do {
      FUN_201525f8(0xffffffff);
      iVar1 = FUN_2012001c();
      itron_dly_tsk(100);
      iVar2 = FUN_2012001c();
    } while (iVar1 != iVar2);
    DAT_20800090 = 1;
    FUN_20151934(DAT_20800088);
  } while( true );
}


// ===== touch_init @ 20103858 (124 bytes)

/* tasks "tsc2007" x2 */

void touch_init(void)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_201651c4);
  if (((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) &&
     (iVar1 = itron_acre_tsk(0,&DAT_201651a8), 0 < iVar1)) {
    itron_sta_tsk(iVar1,0);
  }
  return;
}


// ===== FUN_20103934 @ 20103934 (124 bytes)

void FUN_20103934(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_2014a5dc(param_1,param_2,param_3,0,1,0x200);
  if ((iVar1 == 0) && (iVar1 = FUN_20143c34(param_1,param_4,0x3296,5), iVar1 == 0)) {
    FUN_20143eac(param_1,param_5,0x4100,8);
    return;
  }
  return;
}


// ===== sd_fs_init @ 201039b0 (156 bytes)

/* FAT volume + SDHI driver registration, then sd_task_create */

void sd_fs_init(void)

{
  int iVar1;
  
  iVar1 = FUN_2014a4d0(&DAT_20808c4c,2);
  if (iVar1 == 0) {
    iVar1 = FUN_20103934(&DAT_20809984,0x49,FUN_2013fd98,&DAT_208099f8,&DAT_2080cc8e,0);
    if (iVar1 == 0) {
      sd_task_create();
    }
  }
  return;
}


// ===== FUN_20103a4c @ 20103a4c (52 bytes)

void FUN_20103a4c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_201446bc();
  if (iVar1 == 0) {
    FUN_201446d0(&DAT_20809984 + param_1 * 0x74);
    return;
  }
  return;
}


// ===== FUN_20103a94 @ 20103a94 (72 bytes)

void FUN_20103a94(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_2013faf4(param_2);
    FUN_2014d95c();
    if (((param_1 != 0) && (iVar1 == 1)) || (param_1 == 0 && iVar1 == 0)) break;
    FUN_201525f8(10);
  }
  return;
}


// ===== FUN_20103adc @ 20103adc (112 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_20103adc(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    uVar1 = FUN_2013fc68(param_2,uVar1);
    if (-1 < (int)uVar1) {
      _DAT_20800094 = uVar1;
    }
    FUN_201525f8(10);
    if (DAT_20800098 != 0) {
      uVar1 = 0;
      _DAT_20800094 = _DAT_20800094 & 0xffffff7f;
      FUN_2013fd50(param_2);
      while (DAT_20800098 != 0) {
        FUN_201525f8(10);
      }
    }
  } while( true );
}


// ===== FUN_20103b4c @ 20103b4c (28 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_20103b4c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  _DAT_20800094 = 0;
  FUN_2013fc10();
  FUN_20103adc(1,0);
  iVar1 = FUN_2014e5b0(&DAT_201651e0,"sdTask");
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_2014e73c(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== sd_task_create @ 20103b68 (40 bytes)

/* "sdTask" */

undefined4 sd_task_create(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e5b0(&DAT_201651e0,"sdTask");
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_2014e73c(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_20103ba0 @ 20103ba0 (16 bytes)

uint FUN_20103ba0(void)

{
  return (DAT_20800094 & 0x7f) >> 6;
}


// ===== FUN_20103bb0 @ 20103bb0 (16 bytes)

byte FUN_20103bb0(void)

{
  return DAT_20800094 >> 7;
}


// ===== FUN_20103bc0 @ 20103bc0 (40 bytes)

uint FUN_20103bc0(void)

{
  uint uVar1;
  
  if (*(int *)(DAT_20808b60 + 0x24) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(byte *)(DAT_20808b60 + 0x68) & 0x3f) >> 5;
  }
  return uVar1;
}


// ===== FUN_20103bc8 @ 20103bc8 (12 bytes)

void FUN_20103bc8(undefined4 param_1)

{
  DAT_20800098 = param_1;
  return;
}


// ===== FUN_20103bd4 @ 20103bd4 (8 bytes)

undefined4 FUN_20103bd4(void)

{
  return 0x88;
}


// ===== FUN_20103bdc @ 20103bdc (56 bytes)

undefined4 FUN_20103bdc(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    if (*(short *)(&UNK_201651fc + iVar1 * 8) == param_1) {
      return *(undefined4 *)(&UNK_20165200 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  return 0x10000;
}


// ===== FUN_20103c14 @ 20103c14 (84 bytes)

uint FUN_20103c14(void)

{
  int iVar1;
  undefined1 local_20;
  undefined1 local_1f;
  uint local_c [2];
  
  local_c[0] = 0xff;
  local_20 = 0x62;
  local_1f = 0x70;
  iVar1 = FUN_20104f34(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    FUN_20104e20(local_c,1);
    local_c[0] = local_c[0] & 0xff;
  }
  return local_c[0];
}


// ===== FUN_20103c70 @ 20103c70 (88 bytes)

uint FUN_20103c70(undefined4 param_1)

{
  int iVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1e;
  uint local_c [2];
  
  local_c[0] = 0xff;
  local_20 = 0x65;
  local_1f = 0x72;
  local_1e = param_1;
  iVar1 = FUN_20104f34(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    FUN_20104e20(local_c,1);
    local_c[0] = local_c[0] & 0xff;
  }
  return local_c[0];
}


// ===== FUN_20103cc8 @ 20103cc8 (52 bytes)

int FUN_20103cc8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = iVar1 + (*(byte *)(param_1 + iVar2) + 1 & 0xff);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return iVar1;
}


// ===== FUN_20103cfc @ 20103cfc (212 bytes)

undefined4 FUN_20103cfc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  iVar4 = 0;
  if (param_1 != 0) {
    progress_scale(param_1,param_2,0,0);
    progress_set();
  }
  FUN_20105060();
  iVar1 = FUN_20103c14();
  if (-1 < iVar1) {
    uVar3 = 0;
    while (iVar1 = FUN_20103c70(iVar4), -1 < iVar1) {
      iVar1 = FUN_20103bdc(uVar3);
      iVar4 = iVar4 + iVar1;
      if (param_1 != 0) {
        uVar5 = FUN_20164d54(0x88);
        uVar6 = FUN_20164d54(uVar3);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
        progress_scale(param_1,uVar2,(int)uVar5,uVar2);
        progress_set();
        if ((uVar3 & 7) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar3 = uVar3 + 1;
      if (0x87 < (int)uVar3) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== spiflash_write @ 20103dd0 (164 bytes)

/* writes, then checks against the XIP window 0x18000000 */

uint spiflash_write(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2e;
  uint local_1c [2];
  
  iVar1 = FUN_20103cc8(param_2,param_3);
  local_1c[0] = 0xff;
  local_30 = 0x70;
  local_2f = 0x72;
  local_2e = param_1;
  iVar2 = FUN_20104f34(&local_30,6);
  if ((-1 < iVar2) && (iVar2 = FUN_20104f34(param_2,param_3), -1 < iVar2)) {
    FUN_20104e20(local_1c,1);
    iVar2 = FUN_20103cc8(param_1 + 0x18000000,param_3);
    if (iVar2 == iVar1) {
      local_1c[0] = local_1c[0] & 0xff;
    }
    else {
      local_1c[0] = 0x16;
    }
    return local_1c[0];
  }
  return 1;
}


// ===== spiflash_erase @ 20103e74 (208 bytes)

/* erases 64 KiB blocks */

undefined4 spiflash_erase(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar1 = param_3 + 0xffffU >> 0x10;
  if (param_1 != 0) {
    progress_scale(param_1,param_2,0,0);
    progress_set();
  }
  FUN_20105060();
  iVar2 = FUN_20103c14();
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = FUN_20103c70(param_2);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x10000;
      if (param_1 != 0) {
        uVar5 = FUN_20164d82(uVar1);
        uVar6 = FUN_20164d54(uVar4);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
        progress_scale(param_1,uVar3,(int)uVar5,uVar3);
        progress_set();
        if ((uVar4 & 0xf) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}


// ===== FUN_20103f44 @ 20103f44 (188 bytes)

undefined4 FUN_20103f44(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  iVar4 = 0;
  if (param_1 != 0) {
    progress_scale();
    progress_set();
  }
  FUN_20105060();
  iVar1 = FUN_20103c14();
  if (-1 < iVar1) {
    uVar3 = 0;
    while (iVar1 = FUN_20103c70(iVar4), -1 < iVar1) {
      iVar4 = iVar4 + 0x10000;
      if (param_1 != 0) {
        uVar5 = FUN_20164d54(0x100);
        uVar6 = FUN_20164d54(uVar3);
        uVar5 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20));
        uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
        progress_scale(param_1,uVar2,(int)uVar5,uVar2);
        progress_set();
        if ((uVar3 & 0xf) == 0) {
          FUN_20150dcc(0);
        }
      }
      uVar3 = uVar3 + 1;
      if (0xff < (int)uVar3) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_20104000 @ 20104000 (80 bytes)

undefined1 FUN_20104000(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_3fefa010;
  uVar2 = DAT_3fefa01c;
  DAT_3fefa010 = 0x9f0000;
  DAT_3fefa01c = 0x4000;
  DAT_3fefa010 = uVar1;
  DAT_3fefa01c = uVar2;
  return DAT_18000000;
}


// ===== FUN_20104050 @ 20104050 (40 bytes)

void FUN_20104050(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_20104000();
  if (iVar1 != 0xbf) {
    FUN_20103f44();
    return;
  }
  FUN_20103cfc(param_1);
  return;
}


// ===== FUN_20104078 @ 20104078 (104 bytes)

undefined4 FUN_20104078(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_28;
  undefined1 local_27;
  undefined4 local_26;
  
  FUN_20105060();
  local_28 = 0x72;
  local_27 = 100;
  local_26 = param_1;
  iVar1 = FUN_20104f34(&local_28,6);
  if (iVar1 < 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_20104e20(param_3,param_2);
  }
  return uVar2;
}


// ===== FUN_20104104 @ 20104104 (20 bytes)

undefined4 FUN_20104104(int *param_1,int param_2)

{
  return *(undefined4 *)(*param_1 + param_2);
}


// ===== FUN_20104110 @ 20104110 (28 bytes)

void FUN_20104110(int *param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_20104124 @ 20104124 (28 bytes)

void FUN_20104124(int *param_1,undefined2 param_2,int param_3)

{
  *(undefined2 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_20104138 @ 20104138 (28 bytes)

void FUN_20104138(int *param_1,undefined1 param_2,int param_3)

{
  *(undefined1 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== FUN_2010414c @ 2010414c (8 bytes)

undefined4 FUN_2010414c(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_20104154 @ 20104154 (48 bytes)

int FUN_20104154(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20104188 @ 20104188 (24 bytes)

uint FUN_20104188(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_20104104(param_1,0x48);
  return ~(uVar1 >> 1) & 1;
}

