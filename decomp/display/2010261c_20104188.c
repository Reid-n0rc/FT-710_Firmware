// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== backlight_pwm_init @ 2010261c (124 bytes)

/* MTU2 ch3/ch4 reset-synchronised PWM, period 320 counts, TIOC4D out */

void backlight_pwm_init(void)

{
  byte bVar1;
  
  MTU2_TCR_3 = 0x40;
  MTU2_TCNT_3 = 0;
  MTU2_TCNT_4 = 0;
  MTU2_TGRA_3 = 0;
  MTU2_TGRB_3 = 0x13f;
  MTU2_TGRC_3 = 0;
  MTU2_TGRD_3 = 0x13f;
  MTU2_TGRA_4 = 0;
  MTU2_TGRB_4 = 0;
  MTU2_TGRC_4 = 0;
  MTU2_TGRD_4 = 0;
  MTU2_TOCR1 = 0x47;
  MTU2_TOCR2 = 0x7f;
  MTU2_TOLBR = 0x3f;
  MTU2_TMDR_3 = 0x38;
  bVar1 = MTU2_TOER;
  MTU2_TOER = bVar1 | 0x20;
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 | 0x40;
  return;
}


// ===== backlight_set_pct @ 20102698 (72 bytes)

/* NEW ENTRY; duty = pct*320/100 -> TGRD_4 */

void backlight_set_pct(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  uVar1 = div10_round(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar2 = div10_round(uVar1,(int)uVar1 >> 0x1f);
  if (iVar2 == 0x140) {
    iVar2 = 0x13f;
  }
  MTU2_TGRD_4 = (short)iVar2 + -1;
  return;
}


// ===== backlight_set @ 201026e0 (8 bytes)

/* thunk: backlight_set_pct */

void backlight_set(uint param_1)

{
  backlight_set_pct(param_1,1);
  return;
}


// ===== backlight_init @ 201026e8 (24 bytes)

/* backlight_pwm_init + 60 % */

void backlight_init(void)

{
  backlight_pwm_init();
  backlight_set_pct(0x3c,1);
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
    uVar1 = crc32_update(0xffffffff,0x30,(uint)(param_1 + 2));
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

void touch_cal_save(void *param_1)

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
  local_48 = *(undefined4 *)param_1;
  uStack_44 = *(undefined4 *)((int)param_1 + 4);
  uStack_40 = *(undefined4 *)((int)param_1 + 8);
  uStack_3c = *(undefined4 *)((int)param_1 + 0xc);
  local_38 = *(undefined4 *)((int)param_1 + 0x10);
  uStack_34 = *(undefined4 *)((int)param_1 + 0x14);
  uStack_30 = *(undefined4 *)((int)param_1 + 0x18);
  uStack_2c = *(undefined4 *)((int)param_1 + 0x1c);
  local_28 = *(undefined4 *)((int)param_1 + 0x20);
  uStack_24 = *(undefined4 *)((int)param_1 + 0x24);
  uStack_20 = *(undefined4 *)((int)param_1 + 0x28);
  uStack_1c = *(undefined4 *)((int)param_1 + 0x2c);
  crc32_make_table();
  local_18 = crc32_update(0xffffffff,0x30,(uint)&local_48);
  local_18 = ~local_18;
  spiflash_erase(0,0x3d0000,0x40);
  spiflash_write(0x3d0000,(uint)local_50,0x40);
  return;
}


// ===== touch_cal_fit @ 201027f8 (1836 bytes)

/* least-squares affine fit of 5 measured vs 5 reference points */

void touch_cal_fit(void *param_1)

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
    uVar16 = __aeabi_i2d((int)(short)(&DAT_20808bf8)[iVar3 * 2]);
    uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar4 = (undefined4)uVar16;
    uVar16 = __aeabi_dadd(uVar4,uVar11,(undefined4)local_d0,local_d0._4_4_);
    local_d0 = uVar16;
    uVar16 = __aeabi_i2d((int)(short)(&DAT_20808bfa)[iVar3 * 2]);
    uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = (undefined4)uVar16;
    uVar16 = __aeabi_dadd(uVar5,uVar12,(undefined4)local_48,local_48._4_4_);
    local_48 = uVar16;
    uVar16 = __aeabi_i2d((int)(short)(&DAT_20800060)[iVar3 * 2]);
    uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar6 = (undefined4)uVar16;
    uVar16 = __aeabi_dadd(uVar6,uVar13,(undefined4)local_30,local_30._4_4_);
    local_30 = uVar16;
    uVar16 = __aeabi_i2d((int)(short)(&DAT_20800062)[iVar3 * 2]);
    uVar14 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar7 = (undefined4)uVar16;
    uVar16 = __aeabi_dadd(uVar7,uVar14,(undefined4)local_60,local_60._4_4_);
    local_60 = uVar16;
    uVar16 = __aeabi_dmul(uVar4,uVar11,uVar4,uVar11);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_e0,
                          local_e0._4_4_);
    local_e0 = uVar16;
    uVar16 = __aeabi_dmul(uVar4,uVar11,uVar5,uVar12);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_d8,
                          local_d8._4_4_);
    local_d8 = uVar16;
    local_58 = uVar16;
    uVar16 = __aeabi_dmul(uVar5,uVar12,uVar5,uVar12);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_50,
                          local_50._4_4_);
    local_50 = uVar16;
    uVar16 = __aeabi_dmul(uVar4,uVar11,uVar6,uVar13);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_40,
                          local_40._4_4_);
    local_40 = uVar16;
    uVar16 = __aeabi_dmul(uVar5,uVar12,uVar6,uVar13);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_38,
                          local_38._4_4_);
    local_38 = uVar16;
    uVar16 = __aeabi_dmul(uVar4,uVar11,uVar7,uVar14);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_70,
                          local_70._4_4_);
    local_70 = uVar16;
    uVar16 = __aeabi_dmul(uVar5,uVar12,uVar7,uVar14);
    uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_68,
                          local_68._4_4_);
    uVar5 = local_d0._4_4_;
    uVar4 = (undefined4)local_d0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  local_68 = uVar16;
  uVar16 = __aeabi_ddiv((undefined4)local_e0,local_e0._4_4_);
  uVar7 = local_48._4_4_;
  uVar6 = (undefined4)local_48;
  uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar8 = (undefined4)uVar16;
  local_e0 = uVar16;
  uVar16 = __aeabi_ddiv((undefined4)local_d8,local_d8._4_4_,(undefined4)local_48,local_48._4_4_);
  local_d8 = uVar16;
  local_78 = __aeabi_ddiv((undefined4)local_58,local_58._4_4_,uVar4,uVar5);
  local_58 = local_78;
  local_88 = __aeabi_ddiv((undefined4)local_50,local_50._4_4_,uVar6,uVar7);
  local_50 = local_88;
  local_98 = __aeabi_ddiv((undefined4)local_40,local_40._4_4_,uVar4,uVar5);
  local_40 = local_98;
  uVar17 = __aeabi_ddiv((undefined4)local_38,local_38._4_4_,uVar6,uVar7);
  local_c8._0_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  local_c0._0_4_ = (undefined4)local_c8;
  local_38 = uVar17;
  uVar17 = __aeabi_ddiv((undefined4)local_70,local_70._4_4_,uVar4,uVar5);
  local_70 = uVar17;
  uVar17 = __aeabi_ddiv((undefined4)local_68,local_68._4_4_,uVar6,uVar7);
  local_68 = uVar17;
  uVar17 = __aeabi_ddiv(uVar4,uVar5,0,0x40140000);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_d0 = uVar17;
  uVar18 = __aeabi_ddiv(uVar6,uVar7,0,0x40140000);
  uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
  local_48 = uVar18;
  uVar19 = __aeabi_ddiv((undefined4)local_30,local_30._4_4_,0,0x40140000);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  local_30 = uVar19;
  uVar20 = __aeabi_ddiv((undefined4)local_60,local_60._4_4_,0,0x40140000);
  local_60 = uVar20;
  uVar20 = __aeabi_dsub((undefined4)local_78,local_78._4_4_,(int)uVar18,uVar4);
  local_80 = (undefined4)((ulonglong)uVar20 >> 0x20);
  local_7c = (undefined4)uVar20;
  local_78._0_4_ = local_7c;
  local_78._4_4_ = local_80;
  local_b0 = __aeabi_dsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,uVar5);
  uVar16 = __aeabi_dmul((int)local_b0,(int)((ulonglong)local_b0 >> 0x20),(undefined4)local_78,
                        local_78._4_4_);
  local_a8 = __aeabi_dsub((undefined4)local_88,local_88._4_4_,(int)uVar18,uVar4);
  uVar2 = (ulonglong)local_a8 >> 0x20;
  uVar4 = (undefined4)local_a8;
  uVar17 = __aeabi_dsub(uVar8,uVar12,(int)uVar17,uVar5);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = __aeabi_dmul((int)uVar17,uVar5,uVar4,(int)uVar2);
  uVar16 = __aeabi_dsub((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar9 = (undefined4)uVar16;
  local_90._4_4_ = local_80;
  local_90._0_4_ = local_7c;
  uVar16 = __aeabi_dsub(uVar11,(undefined4)local_c8,(int)uVar19,uVar6);
  uVar4 = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_90 = __aeabi_dmul((int)uVar16,uVar4,(undefined4)local_90,local_90._4_4_);
  local_c8 = local_a8;
  uVar18 = __aeabi_dsub((undefined4)local_98,local_98._4_4_,(int)uVar19,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = __aeabi_dmul((int)uVar18,uVar6,(undefined4)local_c8,local_c8._4_4_);
  uVar19 = __aeabi_dsub((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(undefined4)local_90,
                        local_90._4_4_);
  uVar19 = __aeabi_ddiv((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar9,uVar15);
  *(undefined8 *)param_1 = uVar19;
  uVar18 = __aeabi_dmul((undefined4)local_b0,local_b0._4_4_,(int)uVar18,uVar6);
  uVar16 = __aeabi_dmul((int)uVar17,uVar5,(int)uVar16,uVar4);
  uVar16 = __aeabi_dsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                        (int)((ulonglong)uVar18 >> 0x20));
  uVar16 = __aeabi_ddiv((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  *(undefined8 *)((int)param_1 + 8) = uVar16;
  local_b0._4_4_ = (undefined4)local_c0;
  local_b0._0_4_ = uVar11;
  local_98._0_4_ = uVar12;
  uVar16 = __aeabi_dmul(uVar8,uVar12,uVar11);
  uVar5 = local_d8._4_4_;
  uVar4 = (undefined4)local_d8;
  local_c8 = local_40;
  uVar17 = __aeabi_dmul((undefined4)local_d8,local_d8._4_4_);
  __aeabi_dsub((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
               (int)((ulonglong)uVar16 >> 0x20));
  local_c0 = local_48;
  uVar16 = __aeabi_dmul();
  uVar7 = local_d0._4_4_;
  uVar6 = (undefined4)local_d0;
  uVar17 = __aeabi_dmul((undefined4)local_d0,local_d0._4_4_,(undefined4)local_c8,local_c8._4_4_);
  local_90 = local_30;
  uVar18 = __aeabi_dmul(uVar8,(undefined4)local_98);
  __aeabi_dsub((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  local_b8 = local_50;
  uVar17 = __aeabi_dmul();
  uVar18 = __aeabi_dmul(uVar4,uVar5,(undefined4)local_90,local_90._4_4_);
  local_c8 = uVar18;
  uVar18 = __aeabi_dmul(uVar6,uVar7,(undefined4)local_b0,local_b0._4_4_);
  __aeabi_dsub((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(undefined4)local_c8,local_c8._4_4_);
  local_c8 = local_58;
  uVar18 = __aeabi_dmul();
  uVar17 = __aeabi_dadd((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar16 = __aeabi_dadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __aeabi_ddiv((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  *(undefined8 *)((int)param_1 + 0x10) = uVar16;
  uVar16 = __aeabi_dsub((undefined4)local_c8,local_c8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar14 = local_60._4_4_;
  uVar13 = (undefined4)local_60;
  local_90 = local_68;
  uVar17 = __aeabi_dsub();
  local_98._4_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_9c = (undefined4)uVar17;
  local_b0 = __aeabi_dmul(local_9c,local_98._4_4_,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __aeabi_dsub((undefined4)local_b8,local_b8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar12 = local_70._4_4_;
  uVar11 = (undefined4)local_70;
  local_88._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_a0 = (undefined4)uVar16;
  uVar16 = __aeabi_dsub((undefined4)local_70,local_70._4_4_,uVar13,uVar14);
  local_a8 = uVar16;
  uVar16 = __aeabi_dmul((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_a0,(undefined4)local_88);
  uVar16 = __aeabi_dsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = __aeabi_ddiv((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  *(undefined8 *)((int)param_1 + 0x18) = uVar16;
  uVar16 = __aeabi_dsub(uVar4,uVar5,uVar6,uVar7);
  uVar16 = __aeabi_dmul((undefined4)local_a8,local_a8._4_4_,(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  local_b0 = uVar16;
  uVar16 = __aeabi_dsub(uVar8,(undefined4)local_98,uVar6,uVar7);
  uVar16 = __aeabi_dmul((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_9c,local_98._4_4_);
  uVar16 = __aeabi_dsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = __aeabi_ddiv((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  *(undefined8 *)((int)param_1 + 0x20) = uVar16;
  uVar16 = __aeabi_dmul(uVar8,(undefined4)local_98,(undefined4)local_90,local_90._4_4_);
  local_b0 = uVar16;
  uVar16 = __aeabi_dmul(uVar4,uVar5,uVar11,uVar12);
  uVar16 = __aeabi_dsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = __aeabi_dmul((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_c0,
                        local_c0._4_4_);
  local_c0._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_b0._0_4_ = (undefined4)uVar16;
  uVar16 = __aeabi_dmul(uVar6,uVar7,uVar11,uVar12);
  uVar17 = __aeabi_dmul(uVar8,(undefined4)local_98,uVar13,uVar14);
  uVar16 = __aeabi_dsub((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __aeabi_dmul((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b8,
                        local_b8._4_4_);
  uVar17 = __aeabi_dmul(uVar4,uVar5,uVar13,uVar14);
  uVar18 = __aeabi_dmul(uVar6,uVar7,(undefined4)local_90,local_90._4_4_);
  uVar17 = __aeabi_dsub((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = __aeabi_dmul((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(undefined4)local_c8,
                        local_c8._4_4_);
  uVar16 = __aeabi_dadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __aeabi_dadd((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        (undefined4)local_c0);
  uVar16 = __aeabi_ddiv((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  *(undefined8 *)((int)param_1 + 0x28) = uVar16;
  return;
}


// ===== touch_cal_init @ 20102f34 (88 bytes)

/* boot: measured := reference points, load the record from flash */

void touch_cal_init(void)

{
  int local_38;
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
  touch_cal_load((int *)&DAT_183d0000,&local_38);
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

void touch_cal_set_point(int param_1,uint param_2,void *param_3)

{
  if (param_2 < 5) {
    if (param_1 == 0) {
      (&DAT_20800060)[param_2 * 2] = *(undefined2 *)param_3;
      (&DAT_20800062)[param_2 * 2] = *(undefined2 *)((int)param_3 + 2);
      return;
    }
    (&DAT_20808bf8)[param_2 * 2] = *(undefined2 *)param_3;
    (&DAT_20808bfa)[param_2 * 2] = *(undefined2 *)((int)param_3 + 2);
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
  
  touch_cal_set_point(param_1,2,(void *)param_2);
  touch_cal_set_point(param_1,3,(void *)(param_2 + 4));
  touch_cal_set_point(param_1,0,(void *)(param_2 + 8));
  touch_cal_set_point(param_1,1,(void *)(param_2 + 0xc));
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

void touch_cal_apply(uint param_1,uint param_2,short *param_3,short *param_4)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar5 = __aeabi_i2d(param_2);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar6 = __aeabi_dmul((int)uVar5,uVar3,DAT_20808c18,DAT_20808c1c);
  uVar7 = __aeabi_i2d(param_1);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar8 = __aeabi_dmul((int)uVar7,uVar4,DAT_20808c10,DAT_20808c14);
  uVar6 = __aeabi_dadd((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
  uVar6 = __aeabi_dadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_20808c20,DAT_20808c24);
  __aeabi_dadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
  sVar1 = __aeabi_d2iz();
  uVar5 = __aeabi_dmul((int)uVar5,uVar3,DAT_20808c30,DAT_20808c34);
  uVar6 = __aeabi_dmul((int)uVar7,uVar4,DAT_20808c28,DAT_20808c2c);
  uVar5 = __aeabi_dadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  uVar5 = __aeabi_dadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_20808c38,DAT_20808c3c);
  __aeabi_dadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
  sVar2 = __aeabi_d2iz();
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
  short asStack_10 [2];
  short asStack_c [4];
  
  touch_cal_init();
  touch_cal_apply(100,100,asStack_10,asStack_c);
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
    FUN_2012081c(2,(int)&uStack_10,1);
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
    if ((iVar1 == 0) && (iVar1 = FUN_2012081c(2,(int)&uStack_10,1), iVar1 == 0)) {
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

uint tsc2007_pressure(short *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (*param_1 == 0xfff) {
    *param_1 = 0;
  }
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    uVar2 = __aeabi_ui2d(param_1[2]);
    uVar3 = __aeabi_ui2d(param_1[3]);
    uVar2 = __aeabi_ddiv((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                         (int)((ulonglong)uVar2 >> 0x20));
    uVar2 = __aeabi_dsub((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3ff00000);
    uVar3 = __aeabi_ui2d(*param_1);
    uVar3 = __aeabi_ddiv((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40b00000);
    uVar3 = __aeabi_dmul(0,0x40790000,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    __aeabi_dmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                 (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = __aeabi_d2uiz();
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
  uVar1 = INTC_IRQRR;
  if ((uVar1 & 8) != 0) {
    uVar1 = INTC_IRQRR;
    INTC_IRQRR = uVar1 & 0xfff7;
  }
  return;
}


// ===== task_tsc2007 @ 20103464 (904 bytes)

void task_tsc2007(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *extraout_r1;
  undefined4 *extraout_r1_00;
  undefined4 *extraout_r1_01;
  undefined4 *extraout_r1_02;
  undefined4 *extraout_r1_03;
  undefined4 *extraout_r1_04;
  undefined4 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  iVar2 = FUN_20120454(2);
  if (iVar2 == 0) {
    uVar1 = INTC_ICR1;
    INTC_ICR1 = uVar1 & 0xff3f;
    uVar1 = INTC_ICR1;
    local_28 = (uint)uVar1;
    uVar1 = INTC_ICR1;
    INTC_ICR1 = uVar1 | 0x40;
    uVar3 = itron_acre_isr(0,&cisr_tsc2007_tint_isr);
    if (0 < (int)uVar3) {
      itron_get_tid(&DAT_20800088);
      itron_iwup_tsk(DAT_2080008c);
      tsc2007_write_cmd(0xb0);
      itron_dly_tsk(10);
      puVar6 = extraout_r1;
      do {
        while( true ) {
          local_30 = 0;
          local_2c = 0;
          iVar2 = tsc2007_write_cmd(0,puVar6);
          if (-1 < iVar2) break;
          itron_dly_tsk(10);
          puVar6 = extraout_r1_00;
        }
        while( true ) {
          itron_dly_tsk(1);
          uVar1 = PORT_PPR1;
          if ((uVar1 & 8) != 0) break;
          DAT_20808c48 = DAT_20808c48 + 1;
        }
        DAT_20808c44 = DAT_20808c44 + 1;
        touch_set_up();
        uVar1 = INTC_IRQRR;
        if ((uVar1 & 8) != 0) {
          uVar1 = INTC_IRQRR;
          INTC_IRQRR = uVar1 & 0xfff7;
        }
        uVar1 = INTC_IRQRR;
        local_28 = (uint)uVar1;
        gic_enable_irq(0x23);
        itron_tslp_tsk(0xffffffff);
        iVar2 = 2;
        do {
          iVar2 = iVar2 + -1;
          iVar4 = tsc2007_read12(0xd4);
          if (iVar4 < 0) {
            itron_dly_tsk(10);
            puVar6 = extraout_r1_01;
            break;
          }
          DAT_2080007c = (undefined2)iVar4;
          local_30._2_2_ = DAT_2080007c;
          iVar4 = tsc2007_read12(0xc4);
          if (iVar4 < 0) {
            itron_dly_tsk(10);
            puVar6 = extraout_r1_02;
            break;
          }
          DAT_2080007a = (undefined2)iVar4;
          local_30 = CONCAT22(local_30._2_2_,DAT_2080007a);
          iVar4 = tsc2007_read12(0xe4);
          if (iVar4 < 0) {
            itron_dly_tsk(10);
            puVar6 = extraout_r1_03;
            break;
          }
          local_2c = CONCAT22(local_2c._2_2_,(short)iVar4);
          iVar4 = tsc2007_read12(0xf4);
          if (iVar4 < 0) {
            itron_dly_tsk(10);
            puVar6 = extraout_r1_04;
            break;
          }
          local_2c = CONCAT22((short)iVar4,(undefined2)local_2c);
          uVar7 = __aeabi_idivmod(((local_30 & 0xffff) - 0xf3c) * 10000,0xfffff178);
          uVar7 = __aeabi_idivmod((int)uVar7 * 800,10000);
          uVar3 = (uint)uVar7;
          uVar8 = __aeabi_idivmod(((local_30 >> 0x10) - 0x15e) * 10000,0xcb2);
          uVar8 = __aeabi_idivmod((int)uVar8 * -0x1e0 + 4800000,10000);
          puVar6 = (undefined4 *)(uVar8 >> 0x20);
          uVar5 = (uint)uVar8;
          if (((((int)uVar3 < 0) || (799 < (int)uVar3)) || ((int)uVar5 < 0)) || (0x1df < (int)uVar5)
             ) break;
          DAT_20800080 = tsc2007_pressure((short *)&local_30);
          puVar6 = &DAT_20800080;
          if (DAT_20800080 == 0) break;
          puVar6 = (undefined4 *)0x514;
          if (DAT_20800080 < 0x514) {
            if (((DAT_20800495 != '\0') || (DAT_20800496 != '\0')) || (DAT_20808532 != '\0')) {
              touch_set_down(uVar3,uVar5);
              DAT_20800076 = (undefined2)uVar7;
              DAT_20800078 = (undefined2)uVar8;
              DAT_20800084 = DAT_20800084 + 1;
              puVar6 = (undefined4 *)&DAT_20800084;
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
  
  itron_get_tid(&DAT_2080008c);
  do {
    do {
      itron_tslp_tsk(0xffffffff);
      iVar1 = FUN_2012001c();
      itron_dly_tsk(100);
      iVar2 = FUN_2012001c();
    } while (iVar1 != iVar2);
    DAT_20800090 = 1;
    itron_sus_tsk(DAT_20800088);
  } while( true );
}


// ===== touch_init @ 20103858 (124 bytes)

/* tasks "tsc2007" x2 */

void touch_init(void)

{
  uint uVar1;
  
  uVar1 = itron_acre_tsk(0,&ctsk_tsc2007_51c4);
  if (((0 < (int)uVar1) && (uVar1 = itron_sta_tsk(uVar1,0), uVar1 == 0)) &&
     (uVar1 = itron_acre_tsk(0,&ctsk_tsc2007_51a8), 0 < (int)uVar1)) {
    itron_sta_tsk(uVar1,0);
  }
  return;
}


// ===== FUN_20103934 @ 20103934 (124 bytes)

void FUN_20103934(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = fs_drive_attach(param_1,param_2,param_3,0,1,0x200);
  if ((iVar1 == 0) && (iVar1 = fs_fatcache_setup_b(param_1,param_4,0x3296,5), iVar1 == 0)) {
    fs_dircache_setup(param_1,param_5,0x4100,8);
    return;
  }
  return;
}


// ===== sd_fs_init @ 201039b0 (156 bytes)

/* FAT volume + SDHI driver registration, then sd_task_create */

void sd_fs_init(void)

{
  int iVar1;
  
  iVar1 = fs_init(&DAT_20808c4c,2);
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
  
  iVar1 = fs_sync();
  if (iVar1 == 0) {
    fs_cache_invalidate(&DAT_20809984 + param_1 * 0x74);
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
    fs_task_ctx_get();
    if (((param_1 != 0) && (iVar1 == 1)) || (param_1 == 0 && iVar1 == 0)) break;
    itron_tslp_tsk(10);
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
    itron_tslp_tsk(10);
    if (DAT_20800098 != 0) {
      uVar1 = 0;
      _DAT_20800094 = _DAT_20800094 & 0xffffff7f;
      FUN_2013fd50(param_2);
      while (DAT_20800098 != 0) {
        itron_tslp_tsk(10);
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
  iVar1 = os_create_tsk_named(&DAT_201651e0,"sdTask");
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    itron_act_tsk(iVar1);
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
  
  iVar1 = os_create_tsk_named(&DAT_201651e0,"sdTask");
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    itron_act_tsk(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== sd_state_bit6 @ 20103ba0 (16 bytes)

/* Bit 6 of the SD state 0x20800094; 0 is used as "no SD card" (error -1) [fact for the bit; meaning
   inference] (update.md, display-link.md) */

uint sd_state_bit6(void)

{
  return (DAT_20800094 & 0x7f) >> 6;
}


// ===== sd_state_bit7 @ 20103bb0 (16 bytes)

/* Bit 7 of the SD state 0x20800094 (cleared by the SD task on a card change) [fact]; card ready
   [inference] (update.md) */

byte sd_state_bit7(void)

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
  iVar1 = sflash_dev_write(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    sflash_dev_read(local_c,1);
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
  iVar1 = sflash_dev_write(&local_20,6);
  if (iVar1 < 0) {
    local_c[0] = 1;
  }
  else {
    sflash_dev_read(local_c,1);
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
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  iVar5 = 0;
  if (param_1 != 0) {
    uVar1 = progress_scale(param_1,param_2,0,0);
    progress_set(uVar1);
  }
  sflash_dev_open();
  iVar2 = FUN_20103c14();
  if (-1 < iVar2) {
    uVar1 = 0;
    while (iVar2 = FUN_20103c70(iVar5), -1 < iVar2) {
      iVar2 = FUN_20103bdc(uVar1);
      iVar5 = iVar5 + iVar2;
      if (param_1 != 0) {
        uVar6 = __aeabi_i2d(0x88);
        uVar7 = __aeabi_i2d(uVar1);
        uVar6 = __aeabi_ddiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                             (int)((ulonglong)uVar6 >> 0x20));
        uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar3 = progress_scale(param_1,uVar4,(int)uVar6,uVar4);
        progress_set(uVar3);
        if ((uVar1 & 7) == 0) {
          itron_rot_rdq(0);
        }
      }
      uVar1 = uVar1 + 1;
      if (0x87 < (int)uVar1) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== spiflash_write @ 20103dd0 (164 bytes)

/* writes, then checks against the XIP window 0x18000000 */

uint spiflash_write(int param_1,uint param_2,uint param_3)

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
  iVar2 = sflash_dev_write(&local_30,6);
  if ((-1 < iVar2) && (iVar2 = sflash_dev_write(param_2,param_3), -1 < iVar2)) {
    sflash_dev_read(local_1c,1);
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

uint spiflash_erase(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = param_3 + 0xffffU >> 0x10;
  if (param_1 != 0) {
    uVar2 = progress_scale(param_1,param_2,0,0);
    progress_set(uVar2);
  }
  sflash_dev_open();
  iVar3 = FUN_20103c14();
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      iVar3 = FUN_20103c70(param_2);
      if (iVar3 < 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x10000;
      if (param_1 != 0) {
        uVar6 = __aeabi_ui2d(uVar1);
        uVar7 = __aeabi_i2d(uVar2);
        uVar6 = __aeabi_ddiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                             (int)((ulonglong)uVar6 >> 0x20));
        uVar5 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar4 = progress_scale(param_1,uVar5,(int)uVar6,uVar5);
        progress_set(uVar4);
        if ((uVar2 & 0xf) == 0) {
          itron_rot_rdq(0);
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return 0;
}


// ===== FUN_20103f44 @ 20103f44 (188 bytes)

undefined4 FUN_20103f44(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  iVar5 = 0;
  if (param_1 != 0) {
    uVar1 = progress_scale();
    progress_set(uVar1);
  }
  sflash_dev_open();
  iVar2 = FUN_20103c14();
  if (-1 < iVar2) {
    uVar1 = 0;
    while (iVar2 = FUN_20103c70(iVar5), -1 < iVar2) {
      iVar5 = iVar5 + 0x10000;
      if (param_1 != 0) {
        uVar6 = __aeabi_i2d(0x100);
        uVar7 = __aeabi_i2d(uVar1);
        uVar6 = __aeabi_ddiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                             (int)((ulonglong)uVar6 >> 0x20));
        uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar3 = progress_scale(param_1,uVar4,(int)uVar6,uVar4);
        progress_set(uVar3);
        if ((uVar1 & 0xf) == 0) {
          itron_rot_rdq(0);
        }
      }
      uVar1 = uVar1 + 1;
      if (0xff < (int)uVar1) {
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
  
  uVar1 = SPIBSC_DRCMR_0;
  uVar2 = SPIBSC_DRENR_0;
  SPIBSC_DRCMR_0 = 0x9f0000;
  SPIBSC_DRENR_0 = 0x4000;
  SPIBSC_DRCMR_0 = uVar1;
  SPIBSC_DRENR_0 = uVar2;
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
  
  sflash_dev_open();
  local_28 = 0x72;
  local_27 = 100;
  local_26 = param_1;
  iVar1 = sflash_dev_write(&local_28,6);
  if (iVar1 < 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = sflash_dev_read(param_3,param_2);
  }
  return uVar2;
}


// ===== spibsc_reg_read32 @ 20104104 (20 bytes)

/* *(base + off) for a register object {base, ...} [fact] */

undefined4 spibsc_reg_read32(int *param_1,int param_2)

{
  return *(undefined4 *)(*param_1 + param_2);
}


// ===== spibsc_reg_write32 @ 20104110 (28 bytes)

/* *(base + off) = value [fact] */

void spibsc_reg_write32(int *param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== spibsc_reg_write16 @ 20104124 (28 bytes)

/* 16-bit register store [fact] */

void spibsc_reg_write16(int *param_1,undefined2 param_2,int param_3)

{
  *(undefined2 *)(*param_1 + param_3) = param_2;
  return;
}


// ===== spibsc_reg_write8 @ 20104138 (28 bytes)

/* 8-bit register store [fact] */

void spibsc_reg_write8(int *param_1,undefined1 param_2,int param_3)

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


// ===== spibsc_ssl_negated @ 20104188 (24 bytes)

/* 1 when CMNSR bit 1 (SSLF) is clear [fact] */

uint spibsc_ssl_negated(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = spibsc_reg_read32(param_1,0x48);
  return ~(uVar1 >> 1) & 1;
}

