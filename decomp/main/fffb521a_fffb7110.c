// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb521a @ fffb521a (98 bytes)

bool FUN_fffb521a(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bStack_9;
  uint uVar3;
  
  pbVar2 = vfo_rec_ptr(1);
  bVar1 = vfo_mode(1);
  uVar3 = (uint)bVar1;
  if (1 < uVar3 - 10) {
    if (uVar3 - 2 < 2) {
      bStack_9 = pbVar2[0x14];
      goto LAB_fffb526d;
    }
    if (uVar3 - 4 < 2) {
      bStack_9 = pbVar2[0x32];
      goto LAB_fffb526d;
    }
    if (1 < uVar3 - 6) {
      if (uVar3 < 2) {
        bStack_9 = pbVar2[10];
      }
      else {
        bStack_9 = 0;
      }
      goto LAB_fffb526d;
    }
  }
  bStack_9 = pbVar2[0x3c];
LAB_fffb526d:
  return (bStack_9 & 2) != 0;
}


// ===== tx_mod_gain @ fffb527c (526 bytes)

/* Current modulation gain: MIC GAIN or per-mode USB/REAR MOD GAIN by MOD SOURCE */

byte tx_mod_gain(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte bStack_b;
  
  bVar2 = vfo_mode(DAT_00020b6b);
  cVar3 = FUN_fffb3d11(bVar2);
  bStack_b = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffb5345:
    if (cVar3 == '\0') {
      bStack_b = DAT_00009bed;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a75;
      }
      else {
        bStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a76;
      }
      else {
        bStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (cVar3 == '\0') {
        return DAT_00009bee;
      }
      if (cVar3 == '\x01') {
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b66;
        }
        return DAT_00009a4d;
      }
      if (cVar3 != '\x02') {
        return 0;
      }
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b67;
      }
      return DAT_00009a4e;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb5345;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          return 0;
        }
        if (cVar3 == '\0') {
          return DAT_00009bec;
        }
        if (cVar3 == '\x01') {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b66;
          }
          return DAT_00009a38;
        }
        if (cVar3 != '\x02') {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b67;
        }
        return DAT_00009a39;
      }
    }
    if (cVar3 == '\0') {
      bStack_b = DAT_00009bef;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a5f;
      }
      else {
        bStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a60;
      }
      else {
        bStack_b = DAT_00020b67;
      }
    }
  }
  return bStack_b;
}


// ===== FUN_fffb548a @ fffb548a (22 bytes)

char FUN_fffb548a(void)

{
  return DAT_00009aa3 * '\x05' + '\x0f';
}


// ===== FUN_fffb54a0 @ fffb54a0 (140 bytes)

uint FUN_fffb54a0(void)

{
  byte bVar1;
  undefined4 uStack_c;
  uint uVar2;
  
  bVar1 = vfo_mode(0);
  uVar2 = (uint)bVar1;
  if (uVar2 - 2 < 2) {
    uStack_c = 0x9c09;
  }
  else if (uVar2 - 4 < 2) {
    uStack_c = 0x9c0e;
  }
  else if (uVar2 - 6 < 2) {
    uStack_c = 0x9c0f;
  }
  else if (uVar2 - 8 < 2) {
    uStack_c = 0x9c0a;
  }
  else if (uVar2 - 10 < 2) {
    uStack_c = 0x9c0c;
  }
  else if (uVar2 - 0xc < 2) {
    uStack_c = 0x9c0b;
  }
  else if (uVar2 == 0xe) {
    uStack_c = 0x9c0d;
  }
  else {
    uStack_c = 0x9c06;
  }
  return uStack_c;
}


// ===== FUN_fffb552c @ fffb552c (140 bytes)

uint FUN_fffb552c(void)

{
  byte bVar1;
  undefined4 uStack_c;
  uint uVar2;
  
  bVar1 = vfo_mode(0);
  uVar2 = (uint)bVar1;
  if (uVar2 - 2 < 2) {
    uStack_c = 0x9c10;
  }
  else if (uVar2 - 4 < 2) {
    uStack_c = 0x9c15;
  }
  else if (uVar2 - 6 < 2) {
    uStack_c = 0x9c16;
  }
  else if (uVar2 - 8 < 2) {
    uStack_c = 0x9c11;
  }
  else if (uVar2 - 10 < 2) {
    uStack_c = 0x9c13;
  }
  else if (uVar2 - 0xc < 2) {
    uStack_c = 0x9c12;
  }
  else if (uVar2 == 0xe) {
    uStack_c = 0x9c14;
  }
  else {
    uStack_c = 0x9c07;
  }
  return uStack_c;
}


// ===== portctl_init @ fffb55b8 (10 bytes)

/* 0x12042=0 */

void portctl_init(void)

{
  DAT_00012042 = 0;
  return;
}


// ===== rf_ctrl_task @ fffb55c2 (41 bytes)

/* main loop: updates all shift registers and DACs when values change */

void rf_ctrl_task(void)

{
  pa_relay_update();
  rf_bpf_update();
  atu_relay_update();
  main_dac_update();
  pa_dac_update();
  FUN_fffb5d68();
  if (DAT_00012042 != '\0') {
    return;
  }
  DAT_00012042 = 1;
  return;
}


// ===== pa_relay_update @ fffb55eb (186 bytes)

/* /SST4: TX band one-hot + tuner/AM/RX/band-10 bits [inference] */

void pa_relay_update(void)

{
  bool bVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uStack_8;
  
  bVar3 = vfo_mode(1);
  uVar2 = DAT_00020f50;
  bVar4 = FUN_fffb3337(DAT_00020f50);
  uStack_8 = 1 << (bVar4 & 0x1f);
  if (DAT_00020b3f == '\x02') {
    iVar6 = FUN_fffec50f();
    if ((iVar6 == 0) && (iVar6 = FUN_fffec500(), iVar6 == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = uStack_8 | 0x80;
    }
  }
  if (bVar3 == 4) {
    uStack_8 = uStack_8 | 0x100;
  }
  bVar3 = rx_line_get();
  if (bVar3 == 1) {
    uStack_8 = uStack_8 | 0x200;
  }
  cVar5 = FUN_fffb3371(uVar2);
  if (cVar5 == '\n') {
    uStack_8 = uStack_8 | 0x400;
  }
  if ((DAT_00020f98 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  shreg_write24(3,uStack_8);
  DAT_00020f98 = uStack_8;
  return;
}


// ===== rf_bpf_update @ fffb56a5 (225 bytes)

/* /SST3: RX/TX band one-hot + preamp/ATT bits [inference] */

void rf_bpf_update(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uStack_c;
  uint uStack_8;
  
  pbVar5 = vfo_rec_ptr(DAT_00020b6b);
  bVar3 = pbVar5[3] & 3;
  bVar1 = pbVar5[5];
  if (DAT_00020b6b == 1) {
    uStack_8 = DAT_00020f50;
  }
  else {
    uStack_8 = vfo_freq(0,2);
    bVar4 = tx_line_get();
    if (bVar4 != 0) {
      return;
    }
  }
  bVar4 = FUN_fffb32fd(uStack_8);
  uStack_c = 1 << (bVar4 & 0x1f);
  if (bVar3 == 1) {
    uStack_c = uStack_c | 0x8000;
  }
  else if (bVar3 == 2) {
    uStack_c = uStack_c | 0x10000;
  }
  else if (bVar3 != 3) {
    uStack_c = uStack_c | 0x18000;
  }
  if ((bVar1 & 3) == 3) {
    uStack_c = uStack_c | 0x40000;
  }
  else if ((bVar1 & 3) == 0) {
    uStack_c = uStack_c | 0x20000;
  }
  uStack_c = uStack_c | 0x200000;
  if ((DAT_00020f9c == uStack_c) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  shreg_write24(2,uStack_c);
  DAT_00020f9c = uStack_c;
  return;
}


// ===== atu_relay_update @ fffb5786 (238 bytes)

/* /SST6: internal tuner relay bytes, SEND dropped 15 ms while switching [inference] */

void atu_relay_update(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uStack_8;
  
  bVar2 = send_a_get();
  uStack_8 = 0;
  if (DAT_00020b3f == '\x02') {
    iVar3 = FUN_fffec50f();
    uVar4 = FUN_fffec500();
    uStack_8 = FUN_fffec51e();
    uStack_8 = uStack_8 | (uVar4 | iVar3 << 8) << 8;
  }
  if ((DAT_00020fa0 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (bVar2 != 0) {
      send_a_set(0);
      send_b_set(0);
      DAT_0001b4c5 = '\x01';
      swtimer_start(0x30,0xf);
    }
    shreg_write24(5,uStack_8);
    DAT_00020fa0 = uStack_8;
  }
  if ((DAT_0001b4c5 == '\x01') && (bVar2 = swtimer_expired(0x30), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00020b18 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return;
  }
  DAT_0001b4c5 = 0;
  send_a_set(1);
  send_b_set(1);
  return;
}


// ===== main_dac_update @ fffb5874 (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb58a4) */
/* WARNING: Removing unreachable block (ram,0xfffb5934) */
/* Q1005 ch3 (FADJ) and ch5 */

void main_dac_update(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  ushort local_a;
  
  sVar3 = ((ushort)DAT_0000465b - (ushort)DAT_00009ac6 & 0xff) << 2;
  if ((DAT_00020fa4 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,3,sVar3);
    DAT_00020fa4 = sVar3;
  }
  uVar4 = vfo_freq(0,2);
  bVar2 = FUN_fffb33ab(uVar4);
  if (bVar2 < 5) {
    local_a = (ushort)bRam0000466f;
  }
  else if (bVar2 < 7) {
    local_a = (ushort)bRam00004670;
  }
  else if (bVar2 < 9) {
    local_a = (ushort)bRam00004671;
  }
  else if (bVar2 < 0xb) {
    local_a = (ushort)bRam00004672;
  }
  else {
    local_a = (ushort)bRam00004673;
  }
  sVar3 = local_a << 2;
  if ((DAT_00020fa6 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,5,sVar3);
    DAT_00020fa6 = sVar3;
    return;
  }
  return;
}


// ===== pa_dac_update @ fffb5976 (1010 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5b07) */
/* WARNING: Removing unreachable block (ram,0xfffb5a6c) */
/* WARNING: Removing unreachable block (ram,0xfffb5bbc) */
/* WARNING: Removing unreachable block (ram,0xfffb5caf) */
/* WARNING: Removing unreachable block (ram,0xfffb5d26) */
/* WARNING: Removing unreachable block (ram,0xfffb5aaf) */
/* WARNING: Removing unreachable block (ram,0xfffb5bff) */
/* WARNING: Removing unreachable block (ram,0xfffb5c42) */
/* PA BU2505 ch1..7,10: per-band cal, drive level, fan (ch6 from PA_HF_TH) [inference] */

void pa_dac_update(void)

{
  bool bVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  short sVar6;
  ushort uStack_14;
  ushort uStack_12;
  ushort uStack_10;
  ushort uStack_e;
  ushort uStack_c;
  ushort uStack_a;
  
  uVar2 = DAT_00020f50;
  bVar3 = (byte)(DAT_00020b12 >> 4);
  uVar4 = FUN_fffb3371(DAT_00020f50);
  switch(uVar4) {
  case 0:
    uStack_c = (ushort)bRam00004743;
    uStack_e = (ushort)bRam00004693;
    break;
  case 1:
    uStack_c = (ushort)bRam00004744;
    uStack_e = (ushort)bRam00004694;
    break;
  case 2:
    uStack_c = (ushort)bRam00004745;
    uStack_e = (ushort)bRam00004695;
    break;
  case 3:
    uStack_c = (ushort)bRam00004746;
    uStack_e = (ushort)bRam00004696;
    break;
  case 4:
    uStack_c = (ushort)bRam00004747;
    uStack_e = (ushort)bRam00004697;
    break;
  case 5:
    uStack_c = (ushort)bRam00004748;
    uStack_e = (ushort)bRam00004698;
    break;
  case 6:
    uStack_c = (ushort)bRam00004749;
    uStack_e = (ushort)bRam00004699;
    break;
  case 7:
    uStack_c = (ushort)bRam0000474a;
    uStack_e = (ushort)bRam0000469a;
    break;
  case 8:
    uStack_c = (ushort)bRam0000474b;
    uStack_e = (ushort)bRam0000469b;
    break;
  case 9:
    uStack_c = (ushort)bRam0000474c;
    uStack_e = (ushort)bRam0000469c;
    break;
  default:
    uStack_c = (ushort)bRam0000474d;
    uStack_e = (ushort)bRam0000469d;
  }
  sVar6 = uStack_c << 2;
  if ((DAT_00020fa8 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,1,sVar6);
    DAT_00020fa8 = sVar6;
  }
  sVar6 = uStack_e << 2;
  if ((DAT_00020fb6 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,10,sVar6);
    DAT_00020fb6 = sVar6;
  }
  bVar5 = FUN_fffb4062();
  sVar6 = FUN_fffb667a(uVar4,bVar5);
  sVar6 = SUB42(ROUND((float)(((int)sVar6 & 0x3fffU) << 2) *
                      *(float *)(BYTE_ARRAY_fff88a14 + (uint)bVar5 * 4 + 0x54) + 0.5),0);
  if ((DAT_00020faa == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,2,sVar6);
    DAT_00020faa = sVar6;
  }
  bVar5 = FUN_fffb3337(uVar2);
  if (bVar5 == 0) {
    uStack_10 = (ushort)bRam0000468c;
    uStack_12 = (ushort)bRam0000468b;
    uStack_14 = (ushort)bRam0000468a;
  }
  else if (bVar5 < 6) {
    uStack_10 = (ushort)bRam0000468f;
    uStack_12 = (ushort)bRam0000468e;
    uStack_14 = (ushort)bRam0000468d;
  }
  else {
    uStack_10 = (ushort)bRam00004692;
    uStack_12 = (ushort)bRam00004691;
    uStack_14 = (ushort)bRam00004690;
  }
  sVar6 = uStack_10 << 2;
  if ((DAT_00020fac == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,3,sVar6);
    DAT_00020fac = sVar6;
  }
  sVar6 = uStack_12 << 2;
  if ((DAT_00020fae == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,4,sVar6);
    DAT_00020fae = sVar6;
  }
  sVar6 = uStack_14 << 2;
  if ((DAT_00020fb0 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,5,sVar6);
    DAT_00020fb0 = sVar6;
  }
  if (bVar3 < bRam0000465a) {
    uStack_a = 0xad;
  }
  else if (bRam0000465a + 10 < (uint)bVar3) {
    uStack_a = 0;
  }
  else {
    uStack_a = DAT_00020fb2 >> 2;
  }
  uStack_a = uStack_a << 2;
  if ((DAT_00020fb2 == uStack_a) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,6,uStack_a);
    DAT_00020fb2 = uStack_a;
  }
  if (DAT_00020b3c == '\x03') {
    uStack_a = 0xff;
  }
  else if (DAT_00020b3c == '\x02') {
    uStack_a = 0x51;
  }
  else if (DAT_00020b3c == '\x01') {
    uStack_a = 0x60;
  }
  else {
    uStack_a = 0;
  }
  if (DAT_00009ab8 != '\x03') {
    uStack_a = 0;
  }
  sVar6 = uStack_a << 2;
  if ((DAT_00020fb4 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  bu2505_write(4,7,sVar6);
  DAT_00020fb4 = sVar6;
  return;
}


// ===== FUN_fffb5d68 @ fffb5d68 (2322 bytes)

void FUN_fffb5d68(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  byte bStack_f;
  char cStack_e;
  byte bStack_d;
  byte bStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  byte bStack_8;
  byte bStack_7;
  
  uVar8 = audio_route_state();
  bVar3 = vfo_mode(0);
  bVar4 = FUN_fffb2dfe();
  FUN_fffb3d11(bVar3);
  cVar2 = DAT_00020b6b;
  bVar7 = false;
  cStack_e = '\0';
  bStack_d = 0;
  bStack_b = 0;
  uStack_a = 0;
  uStack_9 = 0;
  bStack_8 = 0;
  bStack_f = DAT_00020b31;
  cVar5 = FUN_fffb3d11(bVar3);
  uVar1 = (uint)bVar3;
  if (uVar1 == 0xe) {
LAB_fffb6009:
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a71;
      uStack_a = DAT_00009a72;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar5 == '\0') {
      bStack_b = DAT_00009bed;
    }
    else if (cVar5 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a75;
      }
      else {
        bStack_b = DAT_00020b66;
      }
    }
    else if (cVar5 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a76;
      }
      else {
        bStack_b = DAT_00020b67;
      }
    }
  }
  else if (uVar1 - 2 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a9b;
      uStack_a = DAT_00009a9c;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
  }
  else if (uVar1 - 4 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a49;
      uStack_a = DAT_00009a4a;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar5 == '\0') {
      bStack_b = DAT_00009bee;
    }
    else if (cVar5 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a4d;
      }
      else {
        bStack_b = DAT_00020b66;
      }
    }
    else if (cVar5 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a4e;
      }
      else {
        bStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb6009;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a88;
            uStack_a = DAT_00009a89;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
        }
        else if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a34;
            uStack_a = DAT_00009a35;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
          if (cVar5 == '\0') {
            bStack_b = DAT_00009bec;
          }
          else if (cVar5 == '\x01') {
            if (DAT_00009dc6 == '\0') {
              bStack_b = DAT_00009a38;
            }
            else {
              bStack_b = DAT_00020b66;
            }
          }
          else if (cVar5 == '\x02') {
            if (DAT_00009dc6 == '\0') {
              bStack_b = DAT_00009a39;
            }
            else {
              bStack_b = DAT_00020b67;
            }
          }
        }
        goto LAB_fffb612b;
      }
    }
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a5c;
      uStack_a = DAT_00009a5d;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar5 == '\0') {
      bStack_b = DAT_00009bef;
    }
    else if (cVar5 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a5f;
      }
      else {
        bStack_b = DAT_00020b66;
      }
    }
    else if (cVar5 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        bStack_b = DAT_00009a60;
      }
      else {
        bStack_b = DAT_00020b67;
      }
    }
  }
LAB_fffb612b:
  cVar5 = FUN_fffb418a(cVar2);
  cVar2 = DAT_00020ba8;
  switch(uVar8) {
  case 0:
    bVar7 = ear_det();
    if (bVar7) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bVar7 = true;
    break;
  case 1:
    bVar7 = ear_det();
    if (bVar7) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bVar7 = true;
    break;
  case 2:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar5;
    break;
  case 3:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar5;
    break;
  case 4:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar5;
    break;
  case 5:
    bStack_8 = DAT_00009dc1;
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 6:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x1a);
    cStack_e = cVar5;
    break;
  case 7:
    bStack_8 = FUN_fffb34f9(cVar5);
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x1a);
    break;
  case 8:
    bVar7 = ear_det();
    if (bVar7) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bVar3 = tx_mod_gain();
    bStack_b = FUN_fffb34cf(bVar3);
    bVar7 = true;
    break;
  case 9:
    bVar7 = ear_det();
    if (bVar7) {
      bStack_8 = FUN_fffb354d(cVar2);
      bStack_f = FUN_fffb3564(cVar2);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bVar7 = true;
    break;
  case 10:
    bStack_8 = FUN_fffb34f9(cVar5);
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xb:
  case 0xc:
    bStack_8 = DAT_00009dc1;
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xd:
    bStack_8 = FUN_fffb34f9(cVar5);
    bVar3 = tx_mod_gain();
    bStack_b = FUN_fffb34cf(bVar3);
    break;
  case 0xe:
    bStack_8 = DAT_00009dc1;
    bStack_b = FUN_fffb350e(DAT_00009dc2);
  }
  if ((bVar4 - 1 < 3) || (bVar4 - 5 < 4)) {
    bStack_d = 0;
    cStack_e = DAT_00009ab5;
    if (DAT_00009ab5 != '\0') goto LAB_fffb6432;
  }
  if (DAT_00020ba8 == '\0') {
    if ((uVar8 == 4) || (uVar8 == 7)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
    if (bVar6) {
      iVar9 = FUN_fffb418a(DAT_00020b6b);
      if (iVar9 == 0) {
        FUN_fffb71f5();
      }
    }
    else if (bVar7) {
      FUN_fffb71f5();
    }
  }
LAB_fffb6432:
  if ((DAT_00020b18 < 3) && (bVar3 = swtimer_expired(0xe), bVar3 != 1)) {
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  if ((!bVar7) && (DAT_00020b3d != '\x02')) {
    if ((DAT_00020fbd == bStack_8) && (DAT_00012042 != '\0')) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      sst2_write12('\x01',bStack_8);
      DAT_00020fbd = bStack_8;
    }
    if ((DAT_00020fbc == bStack_8) && (DAT_00012042 != '\0')) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if (bVar7) {
      sst2_write12('\x05',bStack_8);
      DAT_00020fbc = bStack_8;
    }
  }
  bStack_7 = FUN_fffb34f9(uStack_9);
  if (DAT_00020b6b != '\0') {
    bStack_7 = 0;
  }
  if ((DAT_00020fb8 == bStack_7) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\x02',bStack_7);
    DAT_00020fb8 = bStack_7;
  }
  bVar3 = FUN_fffb34f9(uStack_a);
  if ((DAT_00020fb9 == bVar3) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\x03',bVar3);
    DAT_00020fb9 = bVar3;
  }
  if ((DAT_00020fba == bStack_b) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\x04',bStack_b);
    DAT_00020fba = bStack_b;
  }
  if ((DAT_00020fbe == bStack_d) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\x06',bStack_d);
    DAT_00020fbe = bStack_d;
  }
  bVar3 = FUN_fffb34f9(cStack_e);
  if ((DAT_00020fbf == bVar3) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\a',bVar3);
    DAT_00020fbf = bVar3;
  }
  if ((DAT_00020fbb == bStack_f) && (DAT_00012042 != '\0')) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if (bVar7) {
    sst2_write12('\b',bStack_f);
    DAT_00020fbb = bStack_f;
    return;
  }
  return;
}


// ===== FUN_fffb667a @ fffb667a (1636 bytes)

char FUN_fffb667a(undefined1 param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 local_e;
  char local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  
  switch(param_1) {
  case 0:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_0000469e;
      local_c = DAT_0000469e;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046a7;
          local_c = DAT_000046aa;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046a4;
          local_c = DAT_000046a7;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046a1;
        local_c = DAT_000046a4;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_0000469e;
      local_c = DAT_000046a1;
    }
    local_e = DAT_0000469f;
    break;
  case 1:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046ad;
      local_c = DAT_000046ad;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046b6;
          local_c = DAT_000046b9;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046b3;
          local_c = DAT_000046b6;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046b0;
        local_c = DAT_000046b3;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046ad;
      local_c = DAT_000046b0;
    }
    local_e = DAT_000046ae;
    break;
  case 2:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046bc;
      local_c = DAT_000046bc;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046c5;
          local_c = DAT_000046c8;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046c2;
          local_c = DAT_000046c5;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046bf;
        local_c = DAT_000046c2;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046bc;
      local_c = DAT_000046bf;
    }
    local_e = DAT_000046bd;
    break;
  case 3:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046cb;
      local_c = DAT_000046cb;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046d4;
          local_c = DAT_000046d7;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046d1;
          local_c = DAT_000046d4;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046ce;
        local_c = DAT_000046d1;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046cb;
      local_c = DAT_000046ce;
    }
    local_e = DAT_000046cc;
    break;
  case 4:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046da;
      local_c = DAT_000046da;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046e3;
          local_c = DAT_000046e6;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046e0;
          local_c = DAT_000046e3;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046dd;
        local_c = DAT_000046e0;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046da;
      local_c = DAT_000046dd;
    }
    local_e = DAT_000046db;
    break;
  case 5:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046e9;
      local_c = DAT_000046e9;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_000046f2;
          local_c = DAT_000046f5;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046ef;
          local_c = DAT_000046f2;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046ec;
        local_c = DAT_000046ef;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046e9;
      local_c = DAT_000046ec;
    }
    local_e = DAT_000046ea;
    break;
  case 6:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_000046f8;
      local_c = DAT_000046f8;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_00004701;
          local_c = DAT_00004704;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_000046fe;
          local_c = DAT_00004701;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_000046fb;
        local_c = DAT_000046fe;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_000046f8;
      local_c = DAT_000046fb;
    }
    local_e = DAT_000046f9;
    break;
  case 7:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_00004707;
      local_c = DAT_00004707;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_00004710;
          local_c = DAT_00004713;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_0000470d;
          local_c = DAT_00004710;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_0000470a;
        local_c = DAT_0000470d;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_00004707;
      local_c = DAT_0000470a;
    }
    local_e = DAT_00004708;
    break;
  case 8:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_00004716;
      local_c = DAT_00004716;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_0000471f;
          local_c = DAT_00004722;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_0000471c;
          local_c = DAT_0000471f;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_00004719;
        local_c = DAT_0000471c;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_00004716;
      local_c = DAT_00004719;
    }
    local_e = DAT_00004717;
    break;
  case 9:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_00004725;
      local_c = DAT_00004725;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_0000472e;
          local_c = DAT_00004731;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_0000472b;
          local_c = DAT_0000472e;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_00004728;
        local_c = DAT_0000472b;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_00004725;
      local_c = DAT_00004728;
    }
    local_e = DAT_00004726;
    break;
  default:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = DAT_0000473d;
          local_c = DAT_00004740;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = DAT_0000473a;
          local_c = DAT_0000473d;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = DAT_00004737;
        local_c = DAT_0000473a;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    local_e = DAT_00004738;
  }
  DAT_00020b1e = local_e;
  if (local_b < local_c) {
    iVar2 = ((uint)local_c - (uint)local_b) * (uint)local_9;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || iVar2 != -1)) {
      iVar2 = iVar2 / (int)uVar1;
    }
    local_d = (char)iVar2;
  }
  else {
    iVar2 = ((uint)local_b - (uint)local_c) * (uint)local_9;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || iVar2 != -1)) {
      iVar2 = iVar2 / (int)uVar1;
    }
    local_d = (char)iVar2;
  }
  local_d = local_d + local_c;
  return local_d;
}


// ===== trx_init @ fffb6cde (120 bytes)

/* trx_state=4, timer 0x13 2.5 s, AF_MUTE on */

void trx_init(void)

{
  byte bVar1;
  byte bStack_1;
  
  DAT_00020b18 = 4;
  DAT_00020b6b = 0;
  DAT_0001204d = 0;
  swtimer_start(0x13,0x9c4);
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 8;
  DAT_00020b44 = 1;
  for (bStack_1 = 0; bStack_1 < 4; bStack_1 = bStack_1 + 1) {
    DAT_00020f60 = DAT_00020f60 << 8 | (uint)(byte)(&DAT_00009e82)[bStack_1];
  }
  return;
}


// ===== io_task @ fffb6d56 (173 bytes)

/* main loop: AF mute, meters, io_poll, power checks */

void io_task(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  bVar1 = swtimer_expired(0x2a);
  if (((bVar1 != 0) && (bVar2 = af_mute_get(), bVar2 != (bool)DAT_00020b44)) &&
     (DAT_00020b18 == '\b')) {
    af_mute_set(DAT_00020b44);
  }
  meter_task();
  io_poll();
  FUN_fffb8d77();
  FUN_fffb9605();
  cVar3 = supply_undervolt_check();
  if (cVar3 != '\x01') {
    if (DAT_00020b30 == '\x02') {
      DAT_00009dc5 = 0;
      FUN_fffd3d03();
      if (DAT_00020bbe == '\0') {
        eeprom_save_opstate();
      }
      do {
        bVar1 = sci1_tx_end();
      } while (bVar1 == 0);
      sw_reset();
    }
    iVar4 = FUN_fffb267f();
    if (iVar4 == 1) {
      if (DAT_00020b86 == '\0') {
        DAT_00020b87 = 1;
        return;
      }
    }
    else if (DAT_00020b86 != '\0') {
      DAT_00020b87 = 1;
      return;
    }
  }
  return;
}


// ===== meter_get_vdd @ fffb6e03 (15 bytes)

byte meter_get_vdd(void)

{
  return DAT_00012043;
}


// ===== meter_get_idd @ fffb6e12 (15 bytes)

byte meter_get_idd(void)

{
  return DAT_00012044;
}


// ===== meter_get_alc @ fffb6e21 (15 bytes)

byte meter_get_alc(void)

{
  return DAT_00012045;
}


// ===== meter_get_swr @ fffb6e30 (15 bytes)

byte meter_get_swr(void)

{
  return DAT_00012046;
}


// ===== meter_get_swr_raw @ fffb6e3f (15 bytes)

byte meter_get_swr_raw(void)

{
  return DAT_00012047;
}


// ===== FUN_fffb6e4e @ fffb6e4e (14 bytes)

void FUN_fffb6e4e(void)

{
  return;
}


// ===== FUN_fffb6e5c @ fffb6e5c (14 bytes)

void FUN_fffb6e5c(void)

{
  return;
}


// ===== meter_get_po @ fffb6e6a (46 bytes)

byte meter_get_po(void)

{
  undefined1 local_3;
  
  if (DAT_00009af6 == '\0') {
    local_3 = DAT_00012048;
  }
  else {
    local_3 = DAT_0001204b;
  }
  return local_3;
}


// ===== meter_get_comp @ fffb6e98 (15 bytes)

byte meter_get_comp(void)

{
  return DAT_00012049;
}


// ===== meter_get_s @ fffb6ea7 (15 bytes)

byte meter_get_s(void)

{
  return DAT_0001204a;
}


// ===== remote_key_get @ fffb6eb6 (15 bytes)

byte remote_key_get(void)

{
  return DAT_0001204c;
}


// ===== ptt_source_get @ fffb6ec5 (15 bytes)

/* returns 0x1204D (CAT TX read: 0->TX0, 5->TX1, else TX2) */

byte ptt_source_get(void)

{
  return DAT_0001204d;
}


// ===== ckey_det @ fffb6ed4 (31 bytes)

/* P87 */

bool ckey_det(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c048;
  return -1 < cVar1;
}


// ===== ckey_dot @ fffb6ef3 (24 bytes)

/* P16 low */

bool ckey_dot(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c041;
  return (bVar1 & 0x40) == 0;
}


// ===== ckey_dash @ fffb6f0b (31 bytes)

/* P17 low */

bool ckey_dash(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c041;
  return -1 < cVar1;
}


// ===== jp_p51_get @ fffb6f2a (19 bytes)

/* P51 strap */

byte jp_p51_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 1 & 1;
}


// ===== FUN_fffb6f3d @ fffb6f3d (19 bytes)

byte FUN_fffb6f3d(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb6f50 @ fffb6f50 (19 bytes)

byte FUN_fffb6f50(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 3 & 1;
}


// ===== FUN_fffb6f63 @ fffb6f63 (19 bytes)

byte FUN_fffb6f63(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 4 & 1;
}


// ===== atas_det @ fffb6f76 (30 bytes)

/* P55 */

bool atas_det(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return (bVar1 >> 5 & 1) == 1;
}


// ===== FUN_fffb6f94 @ fffb6f94 (24 bytes)

void FUN_fffb6f94(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== tx_line_get @ fffb6fac (19 bytes)

/* P73 TX */

byte tx_line_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  return bVar1 >> 3 & 1;
}


// ===== send_a_get @ fffb6fbf (19 bytes)

byte send_a_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02a;
  return bVar1 >> 2 & 1;
}


// ===== send_a_set @ fffb6fd2 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7007) */
/* PA2 SEND_A, forced 0 if ETUN_TXINH_REQ or TX line low */

void send_a_set(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xfb | (local_1 & 1) << 2;
  return;
}


// ===== send_b_set @ fffb7011 (64 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7046) */
/* PB4 SEND_B, same gating */

void send_b_set(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xef | (local_1 & 1) << 4;
  return;
}


// ===== sdr_reset_set @ fffb7051 (22 bytes)

/* P77 */

void sdr_reset_set(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0x7f | param_1 << 7;
  return;
}


// ===== sdr_update_set @ fffb7067 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7075) */
/* P76 */

void sdr_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== dsp_reset_set @ fffb7080 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb708e) */
/* P71 */

void dsp_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfd | (param_1 & 1) << 1;
  return;
}


// ===== dsp_update_set @ fffb7098 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70a6) */
/* P72 */

void dsp_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== af_reset_set @ fffb70b0 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70be) */
/* P74 */

void af_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xef | (param_1 & 1) << 4;
  return;
}


// ===== pa_pon_set @ fffb70c9 (22 bytes)

/* PC0 PA_PON */

void pa_pon_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== tun_lin_sel_set @ fffb70df (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70ed) */
/* P83 */

void tun_lin_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== rem_key_sel_set @ fffb70f7 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7105) */
/* P86 */

void rem_key_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== gpo_a_dir_out @ fffb7110 (12 bytes)

/* PDR P13 */

void gpo_a_dir_out(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 8;
  return;
}

