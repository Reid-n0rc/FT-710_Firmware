// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex060418 @ fffec273 (6 bytes)

/* AI change detector for menu item EX060418 (table 0xFFF8E1A0[277]) */

void ai_ex060418(void)

{
  FUN_fffebf4d(4);
  return;
}


// ===== ai_ex060501 @ fffec279 (6 bytes)

/* AI change detector for menu item EX060501 (table 0xFFF8E1A0[278]) */

void ai_ex060501(void)

{
  FUN_fffea63a(5);
  return;
}


// ===== ai_ex060502 @ fffec27f (6 bytes)

/* AI change detector for menu item EX060502 (table 0xFFF8E1A0[279]) */

void ai_ex060502(void)

{
  FUN_fffea88c(5);
  return;
}


// ===== ai_ex060503 @ fffec285 (6 bytes)

/* AI change detector for menu item EX060503 (table 0xFFF8E1A0[280]) */

void ai_ex060503(void)

{
  FUN_fffeaa08(5);
  return;
}


// ===== ai_ex060504 @ fffec28b (6 bytes)

/* AI change detector for menu item EX060504 (table 0xFFF8E1A0[281]) */

void ai_ex060504(void)

{
  FUN_fffeab84(5);
  return;
}


// ===== ai_ex060505 @ fffec291 (6 bytes)

/* AI change detector for menu item EX060505 (table 0xFFF8E1A0[282]) */

void ai_ex060505(void)

{
  FUN_fffead00(5);
  return;
}


// ===== ai_ex060506 @ fffec297 (6 bytes)

/* AI change detector for menu item EX060506 (table 0xFFF8E1A0[283]) */

void ai_ex060506(void)

{
  FUN_fffeae77(5);
  return;
}


// ===== ai_ex060507 @ fffec29d (6 bytes)

/* AI change detector for menu item EX060507 (table 0xFFF8E1A0[284]) */

void ai_ex060507(void)

{
  FUN_fffeafee(5);
  return;
}


// ===== ai_ex060508 @ fffec2a3 (6 bytes)

/* AI change detector for menu item EX060508 (table 0xFFF8E1A0[285]) */

void ai_ex060508(void)

{
  FUN_fffeb165(5);
  return;
}


// ===== ai_ex060509 @ fffec2a9 (6 bytes)

/* AI change detector for menu item EX060509 (table 0xFFF8E1A0[286]) */

void ai_ex060509(void)

{
  FUN_fffeb2b9(5);
  return;
}


// ===== ai_ex060510 @ fffec2af (6 bytes)

/* AI change detector for menu item EX060510 (table 0xFFF8E1A0[287]) */

void ai_ex060510(void)

{
  FUN_fffeb435(5);
  return;
}


// ===== ai_ex060511 @ fffec2b5 (6 bytes)

/* AI change detector for menu item EX060511 (table 0xFFF8E1A0[288]) */

void ai_ex060511(void)

{
  FUN_fffeb589(5);
  return;
}


// ===== ai_ex060512 @ fffec2bb (6 bytes)

/* AI change detector for menu item EX060512 (table 0xFFF8E1A0[289]) */

void ai_ex060512(void)

{
  FUN_fffeb705(5);
  return;
}


// ===== ai_ex060513 @ fffec2c1 (6 bytes)

/* AI change detector for menu item EX060513 (table 0xFFF8E1A0[290]) */

void ai_ex060513(void)

{
  FUN_fffeb859(5);
  return;
}


// ===== ai_ex060514 @ fffec2c7 (6 bytes)

/* AI change detector for menu item EX060514 (table 0xFFF8E1A0[291]) */

void ai_ex060514(void)

{
  FUN_fffeb9ad(5);
  return;
}


// ===== ai_ex060515 @ fffec2cd (6 bytes)

/* AI change detector for menu item EX060515 (table 0xFFF8E1A0[292]) */

void ai_ex060515(void)

{
  FUN_fffebb29(5);
  return;
}


// ===== ai_ex060516 @ fffec2d3 (6 bytes)

/* AI change detector for menu item EX060516 (table 0xFFF8E1A0[293]) */

void ai_ex060516(void)

{
  FUN_fffebca5(5);
  return;
}


// ===== ai_ex060517 @ fffec2d9 (6 bytes)

/* AI change detector for menu item EX060517 (table 0xFFF8E1A0[294]) */

void ai_ex060517(void)

{
  FUN_fffebdf9(5);
  return;
}


// ===== ai_ex060518 @ fffec2df (6 bytes)

/* AI change detector for menu item EX060518 (table 0xFFF8E1A0[295]) */

void ai_ex060518(void)

{
  FUN_fffebf4d(5);
  return;
}


// ===== FUN_fffec2e5 @ fffec2e5 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec3f5) */
/* WARNING: Removing unreachable block (ram,0xfffec3af) */
/* WARNING: Removing unreachable block (ram,0xfffec329) */

short FUN_fffec2e5(byte param_1,char param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  short sStack_10;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_5;
  
  local_5 = param_1;
  if (param_3 == 0) {
    if (param_2 == '\0') {
      local_d = 10;
      local_e = 2;
    }
    else if (param_2 == '\x01') {
      local_d = 100;
      local_e = 3;
    }
    for (local_c = 0; local_c < local_e; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23d)[local_c] = cVar1;
    }
    (&DAT_0001b23d)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_0001b23d = 0x2b;
    }
    else {
      DAT_0001b23d = 0x2d;
      local_5 = ~param_1 + 1;
    }
    local_d = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23e)[local_c] = cVar1;
    }
    (&DAT_0001b23e)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== FUN_fffec3f8 @ fffec3f8 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec469) */
/* WARNING: Removing unreachable block (ram,0xfffec422) */

short FUN_fffec3f8(ushort param_1)

{
  char cVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_c;
  byte local_a;
  ushort local_6;
  
  local_c = 1000;
  local_6 = param_1;
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    uVar2 = (uint)local_6;
    if (local_c != 0) {
      uVar2 = uVar2 / local_c;
    }
    uVar3 = local_6;
    if (local_c != 0) {
      uVar3 = local_6 / local_c;
    }
    local_6 = local_6 - uVar3 * local_c;
    local_c = local_c / 10;
    cVar1 = nib2hex((byte)uVar2);
    (&DAT_0001b23d)[local_a] = cVar1;
  }
  (&DAT_0001b23d)[local_a] = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== tuner_init @ fffec46c (7 bytes)

/* tuner_task once + FUN_fffec578 */

void tuner_init(void)

{
  tuner_task();
  FUN_fffec578();
  return;
}


// ===== tuner_task @ fffec473 (32 bytes)

/* main_loop task 16: antenna tuner, dispatch on tuner select 0x9AB8 [inference] */

void tuner_task(void)

{
  if (DAT_00009ab8 == 3) {
    FUN_fffed165();
    return;
  }
  if (1 < DAT_00009ab8) {
    FUN_fffed62a();
    return;
  }
  FUN_fffec62b();
  return;
}


// ===== FUN_fffec493 @ fffec493 (72 bytes)

void FUN_fffec493(void)

{
  DAT_0001b3bc = DAT_00009c5b;
  DAT_00009c5b = 5;
  DAT_0001b3bd = DAT_00009aa1;
  DAT_00009aa1 = 0;
  DAT_00020cc6 = 0x49;
  FUN_fffc8d8c(0);
  return;
}


// ===== FUN_fffec4db @ fffec4db (37 bytes)

void FUN_fffec4db(void)

{
  DAT_00009c5b = DAT_0001b3bc;
  DAT_00009aa1 = DAT_0001b3bd;
  FUN_fffc8beb();
  return;
}


// ===== FUN_fffec500 @ fffec500 (15 bytes)

undefined1 FUN_fffec500(void)

{
  return DAT_0001b3ad;
}


// ===== FUN_fffec50f @ fffec50f (15 bytes)

undefined1 FUN_fffec50f(void)

{
  return DAT_0001b3af;
}


// ===== FUN_fffec51e @ fffec51e (15 bytes)

undefined1 FUN_fffec51e(void)

{
  return DAT_0001b3b1;
}


// ===== FUN_fffec52d @ fffec52d (10 bytes)

void FUN_fffec52d(void)

{
  DAT_0001b3ac = 0x10;
  return;
}


// ===== FUN_fffec537 @ fffec537 (35 bytes)

void FUN_fffec537(char param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  if (param_1 != '\0') {
    pbVar1[1] = pbVar1[1] | 4;
    return;
  }
  pbVar1[1] = pbVar1[1] & 0xfb;
  return;
}


// ===== FUN_fffec55a @ fffec55a (30 bytes)

bool FUN_fffec55a(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return (pbVar1[1] & 4) != 0;
}


// ===== FUN_fffec578 @ fffec578 (179 bytes)

void FUN_fffec578(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_00009ab8 == 2) {
    iVar2 = FUN_fffed6f5();
    if (iVar2 == 1) {
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        if ((DAT_00020b3f == '\x04') || (DAT_00020b3f == '\x05')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_00020b3f = 6;
          return;
        }
      }
      else if (DAT_00020b3f == '\0') {
        DAT_00020b3f = 4;
        return;
      }
    }
  }
  else if (DAT_00009ab8 < 2) {
    iVar2 = FUN_fffec55a();
    if (iVar2 == 0) {
      if ((DAT_00020b3f == '\x01') || (DAT_00020b3f == '\x02')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b3f = 3;
        return;
      }
    }
    else if (DAT_00020b3f == '\0') {
      DAT_00020b3f = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffec62b @ fffec62b (223 bytes)

void FUN_fffec62b(void)

{
  bool bVar1;
  byte bVar2;
  
  DAT_00020b71 = 0;
  if ((DAT_00020b3f == '\x02') || (DAT_00020b3f == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_00020b71 = 1;
    if ((DAT_00020b41 == '\x02') && (bVar2 = blink_phase(0), bVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b71 = 0;
    }
  }
  switch(DAT_0001b3ac) {
  case 1:
    FUN_fffec728();
    return;
  case 2:
    FUN_fffec7f9();
    return;
  case 3:
    FUN_fffec881();
    return;
  case 4:
    FUN_fffec8a1();
    return;
  case 5:
    FUN_fffec911();
    return;
  case 6:
  case 10:
    FUN_fffec9b4();
    return;
  case 7:
  case 0xb:
    FUN_fffeca48();
    return;
  case 8:
    FUN_fffeca7e();
    return;
  case 9:
    FUN_fffecba2();
    return;
  case 0xc:
    FUN_fffecce7();
    return;
  case 0xd:
    FUN_fffecde6();
    return;
  case 0xe:
    FUN_fffece39();
    return;
  case 0xf:
    FUN_fffece69();
    return;
  case 0x10:
    FUN_fffece79();
    return;
  default:
    FUN_fffec70a();
    return;
  case 0x14:
  case 0x15:
    FUN_fffec9ed();
    return;
  }
}


// ===== FUN_fffec70a @ fffec70a (30 bytes)

void FUN_fffec70a(void)

{
  DAT_00020b41 = 0;
  DAT_00020b3f = 0;
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffec728 @ fffec728 (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec7d5) */
/* WARNING: Removing unreachable block (ram,0xfffec7e2) */

void FUN_fffec728(void)

{
  uint uVar1;
  char cStack_5;
  
  uVar1 = DAT_00020f50;
  if (DAT_00020b41 == '\x01') {
    DAT_0001b3ac = 2;
  }
  else if (DAT_00020b3f == '\x03') {
    DAT_00020b3f = '\0';
  }
  else {
    if (DAT_00020b6b == '\0') {
      return;
    }
    if (DAT_00020b3f == '\x01') {
      cStack_5 = FUN_fffecfac(DAT_00020f50);
      if (cStack_5 == -1) {
        cStack_5 = FUN_fffed0ae(uVar1);
      }
      if (cStack_5 != -1) {
        DAT_00025d00 = uVar1;
        DAT_0001b3bb = FUN_fffb3371(uVar1);
        FUN_fffed12f();
        DAT_00020b3f = '\x02';
      }
    }
  }
  if ((DAT_00020b3f == '\x02') && (DAT_00025d00 / 10000 != uVar1 / 10000)) {
    DAT_00020b3f = 1;
    return;
  }
  return;
}


// ===== FUN_fffec7f9 @ fffec7f9 (136 bytes)

void FUN_fffec7f9(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = DAT_00020f50;
  bVar2 = tx_freq_allowed(DAT_00020f50);
  if (bVar2) {
    DAT_00025d00 = uVar1;
    DAT_0001b3bb = FUN_fffb3371(uVar1);
    FUN_fffec493();
    DAT_00020b41 = 2;
    DAT_00020b2d = 1;
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
    FUN_fffed12f();
    DAT_00020b3f = 0;
    swtimer_start(0x27,100);
    DAT_0001b3ac = 3;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec881 @ fffec881 (32 bytes)

void FUN_fffec881(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  swtimer_start(0x27,0xa0);
  DAT_0001b3ac = 4;
  return;
}


// ===== FUN_fffec8a1 @ fffec8a1 (112 bytes)

void FUN_fffec8a1(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = swtimer_expired(0x27);
  uVar2 = 0;
  if (bVar1 == 0) {
    return;
  }
  DAT_00025d04 = (float)FUN_fffb6e5c();
  if (DAT_00025d04 <= 4.3) {
    if (1.1 < DAT_00025d04 != (bool)((byte)(uVar2 >> 3) & 1)) {
      send_a_set(0);
      send_b_set(0);
      swtimer_start(0x27,5);
      DAT_0001b3ac = 5;
      return;
    }
    atu_mem_store();
    DAT_0001b3ac = 0xe;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec911 @ fffec911 (163 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec925) */
/* WARNING: Removing unreachable block (ram,0xfffec940) */
/* WARNING: Removing unreachable block (ram,0xfffec95b) */

void FUN_fffec911(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 != 0) {
    DAT_0001b3b2 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 10];
    DAT_0001b3ae = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xb];
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xc];
    DAT_00020b3f = 2;
    DAT_0001b3b0 = DAT_0001b3ae;
    DAT_0001b3b3 = DAT_0001b3ae;
    swtimer_start(0x27,5);
    DAT_00025cfc = 0x437f0000;
    DAT_0001b3ac = 6;
    return;
  }
  return;
}


// ===== FUN_fffec9b4 @ fffec9b4 (57 bytes)

void FUN_fffec9b4(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  FUN_fffed12f();
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x06') {
    DAT_0001b3ac = 0x14;
  }
  else {
    DAT_0001b3ac = 0x15;
  }
  return;
}


// ===== FUN_fffec9ed @ fffec9ed (91 bytes)

void FUN_fffec9ed(void)

{
  byte bVar1;
  
  if (DAT_00020b3f == '\x03') {
    DAT_0001b3ac = 0xf;
    return;
  }
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  send_a_set(1);
  send_b_set(1);
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\x14') {
    DAT_0001b3ac = 7;
  }
  else {
    DAT_0001b3ac = 0xb;
  }
  return;
}


// ===== FUN_fffeca48 @ fffeca48 (54 bytes)

void FUN_fffeca48(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x27);
  if (bVar1 == 0) {
    return;
  }
  swtimer_start(0x27,5);
  if (DAT_0001b3ac == '\a') {
    DAT_0001b3ac = 8;
  }
  else {
    DAT_0001b3ac = 0xc;
  }
  return;
}


// ===== FUN_fffeca7e @ fffeca7e (292 bytes)

void FUN_fffeca7e(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00025cfc = fVar3;
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    if ((DAT_00009ab8 == '\x01') && (fVar3 <= 1.5)) {
      DAT_0001b3ac = 9;
      return;
    }
  }
  if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b3;
    if ((ushort)DAT_0001b3b2 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 9;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 6;
  return;
}


// ===== FUN_fffecba2 @ fffecba2 (325 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecbcc) */

void FUN_fffecba2(void)

{
  byte local_1;
  
  if (4.0 < DAT_00025cfc == SBORROW4((int)&stack0x00000000,8)) {
    DAT_00025cfc = 255.0;
    DAT_0001b3b4 = BYTE_ARRAY_fff87bf2[(uint)DAT_0001b3bb * 4 + 0xd];
    if (DAT_0001b3bb < 2) {
      local_1 = 9;
    }
    else {
      local_1 = 3;
    }
    if ((uint)DAT_0001b3b9 + (uint)local_1 < 0x100) {
      DAT_0001b3b5 = DAT_0001b3b9 + local_1;
    }
    else {
      DAT_0001b3b5 = -1;
    }
    if ((uint)DAT_0001b3ba + (uint)local_1 < 0x100) {
      DAT_0001b3b7 = DAT_0001b3ba + local_1;
    }
    else {
      DAT_0001b3b7 = -1;
    }
    if (DAT_0001b3b9 < local_1) {
      DAT_0001b3ae = '\0';
    }
    else {
      DAT_0001b3ae = DAT_0001b3b9 - local_1;
    }
    if (DAT_0001b3ba < local_1) {
      DAT_0001b3b0 = '\0';
    }
    else {
      DAT_0001b3b0 = DAT_0001b3ba - local_1;
    }
    DAT_0001b3b6 = DAT_0001b3ae;
    DAT_0001b3b8 = DAT_0001b3b0;
    send_a_set(0);
    send_b_set(0);
    swtimer_start(0x27,4);
    DAT_0001b3ac = 10;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffecce7 @ fffecce7 (255 bytes)

void FUN_fffecce7(void)

{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  
  bVar2 = swtimer_expired(0x27);
  uVar4 = 0;
  if (bVar2 == 0) {
    return;
  }
  fVar3 = (float)FUN_fffb6e4e();
  if ((fVar3 - 1.0 < 0.0 != (bool)((byte)(uVar4 >> 3) & 1)) || (DAT_00025cfc <= fVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0001b3b9 = DAT_0001b3ad;
    DAT_0001b3ba = DAT_0001b3af;
    DAT_00025cfc = fVar3;
  }
  if ((ushort)DAT_0001b3b7 < (ushort)((ushort)DAT_0001b3b0 + (ushort)DAT_0001b3b4)) {
    DAT_0001b3b0 = DAT_0001b3b8;
    if ((ushort)DAT_0001b3b5 < (ushort)((ushort)DAT_0001b3ae + (ushort)DAT_0001b3b4)) {
      DAT_0001b3ac = 0xd;
      return;
    }
    DAT_0001b3ae = DAT_0001b3ae + DAT_0001b3b4;
  }
  else {
    DAT_0001b3b0 = DAT_0001b3b0 + DAT_0001b3b4;
  }
  send_a_set(0);
  send_b_set(0);
  swtimer_start(0x27,4);
  DAT_0001b3ac = 10;
  return;
}


// ===== FUN_fffecde6 @ fffecde6 (83 bytes)

void FUN_fffecde6(void)

{
  if (DAT_00025cfc < DAT_00025d04) {
    DAT_0001b3ae = DAT_0001b3b9;
    DAT_0001b3b0 = DAT_0001b3ba;
  }
  else {
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
  }
  FUN_fffed12f();
  atu_mem_store();
  DAT_0001b3ac = 0xe;
  return;
}


// ===== FUN_fffece39 @ fffece39 (48 bytes)

void FUN_fffece39(void)

{
  FUN_fffec4db();
  DAT_00020b41 = 0;
  DAT_00020b2d = 0;
  DAT_00020b3f = 2;
  FUN_fffec537(1);
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffece69 @ fffece69 (16 bytes)

void FUN_fffece69(void)

{
  beep_request(3);
  DAT_0001b3ac = 0x10;
  return;
}


// ===== FUN_fffece79 @ fffece79 (44 bytes)

void FUN_fffece79(void)

{
  DAT_00020b2d = 0;
  DAT_0001b3ae = 0;
  DAT_0001b3b0 = 0;
  FUN_fffed12f();
  FUN_fffec4db();
  DAT_0001b3ac = 0;
  return;
}


// ===== atu_mem_store @ fffecea5 (263 bytes)

/* WARNING: Removing unreachable block (ram,0xfffecf52) */
/* WARNING: Removing unreachable block (ram,0xfffecf1b) */
/* WARNING: Removing unreachable block (ram,0xfffecef3) */
/* WARNING: Removing unreachable block (ram,0xfffeceea) */
/* WARNING: Removing unreachable block (ram,0xfffecf0a) */
/* WARNING: Removing unreachable block (ram,0xfffecf47) */
/* WARNING: Removing unreachable block (ram,0xfffecf66) */
/* WARNING: Removing unreachable block (ram,0xfffecf79) */
/* Stores (freq key, 0x1B3AF, 0x1B3AD) in the 100-entry tuner memory 0x9898 ring and saves it */

void atu_mem_store(void)

{
  uint uVar1;
  byte bStack_16;
  byte bStack_15;
  undefined1 uStack_4;
  
  uVar1 = FUN_fffb4135(DAT_00025d00);
  bStack_15 = 0xff;
  bStack_16 = 0;
  do {
    if (DAT_00009899 <= bStack_16) {
LAB_fffecf38:
      if (bStack_15 == 0xff) {
        (&DAT_0000989a)[(uint)DAT_00009898 * 4] = (char)(uVar1 >> 0x18);
        uStack_4 = (undefined1)(uVar1 >> 0x10);
        (&DAT_0000989b)[(uint)DAT_00009898 * 4] = uStack_4;
        (&DAT_0000989c)[(uint)DAT_00009898 * 4] = DAT_0001b3af;
        (&DAT_0000989d)[(uint)DAT_00009898 * 4] = DAT_0001b3ad;
        if (DAT_00009899 < 100) {
          DAT_00009899 = DAT_00009899 + 1;
        }
        if (DAT_00009898 < 99) {
          DAT_00009898 = DAT_00009898 + 1;
        }
        else {
          DAT_00009898 = 0;
        }
      }
      eeprom_save_atu_mem();
      return;
    }
    if (uVar1 >> 0x10 ==
        (uint)CONCAT11((&DAT_0000989a)[(uint)bStack_16 * 4],(&DAT_0000989b)[(uint)bStack_16 * 4])) {
      (&DAT_0000989c)[(uint)bStack_16 * 4] = DAT_0001b3af;
      (&DAT_0000989d)[(uint)bStack_16 * 4] = DAT_0001b3ad;
      bStack_15 = bStack_16;
      goto LAB_fffecf38;
    }
    bStack_16 = bStack_16 + 1;
  } while( true );
}

