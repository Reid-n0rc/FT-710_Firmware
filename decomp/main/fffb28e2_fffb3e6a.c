// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== beep_task @ fffb28e2 (1220 bytes)

/* main loop: plays beep pattern 0x12041 (880 Hz / 1046.5 Hz) */

void beep_task(void)

{
  int iVar1;
  float fVar2;
  float fStack_4;
  
  if (DAT_00012040 == '\x01') {
    tone_idle();
    DAT_0001b3e2 = 0;
    DAT_00012040 = 2;
    return;
  }
  if (DAT_00012040 == '\x02') {
    iVar1 = swtimer_expired(0x16);
    if (iVar1 == 1) {
      switch(DAT_00012041) {
      case 1:
        if (DAT_0001b3e2 == '\0') {
          tone_set(0x445c0000,100);
          DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        }
        else {
          beep_stop();
        }
        break;
      case 2:
        if (DAT_0001b3e2 == '\x02') {
          tone_set(0x445c0000,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(0x445c0000,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 3:
        if (DAT_0001b3e2 == '\x04') {
          tone_set(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0,100);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(0x4482d010,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 4:
        fVar2 = (float)DAT_00009c04 * 10.0 + 300.0;
        if (DAT_00025d40 == fVar2) {
          swtimer_start(0x16,100);
        }
        else {
          DAT_00025d40 = fVar2;
          tone_set(fVar2,100);
        }
        break;
      case 5:
        if (DAT_0001b3e2 == '\x04') {
          tone_set(0x44c3ff6d,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0,10);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(0x44a4d052,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(0x4482d010,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 6:
        if (DAT_0001b3e2 == '\x02') {
          tone_set(0x4424d052,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(0x4443ff6d,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 7:
        switch(DAT_0001b3e2) {
        case '\0':
          tone_set(0x44a4d052,100);
          break;
        case '\x01':
          tone_set(0,0x28);
          break;
        case '\x02':
          tone_set(0x44a4d052,100);
          break;
        case '\x03':
          tone_set(0,0x14);
          break;
        case '\x04':
          tone_set(0x44a4d052,100);
          break;
        case '\x05':
          tone_set(0,0x14);
          break;
        case '\x06':
          tone_set(0x44a4d052,100);
          break;
        case '\a':
          tone_set(0,0x14);
          break;
        case '\b':
          tone_set(0x44a4d052,100);
          break;
        default:
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 8:
        if (DAT_0001b3e2 == '\x05') {
          tone_idle();
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0,0x46);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0,0x46);
        }
        else if (DAT_0001b3e2 == '\x04') {
          tone_set(0x4482d010,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(0x4482d010,100);
        }
        else {
          beep_stop();
          DAT_00020f4b = 1;
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 9:
        if (DAT_0001b3e3 == '\t') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      case 10:
        if (DAT_0001b3e3 == '\n') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8d == '\x01') {
            fStack_4 = 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = 850.0;
          }
          else {
            fStack_4 = 170.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      case 0xb:
        if (DAT_0001b3e3 == '\v') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          if (DAT_00009a8d == '\x01') {
            fStack_4 = fStack_4 + 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = fStack_4 + 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = fStack_4 + 850.0;
          }
          else {
            fStack_4 = fStack_4 + 170.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      default:
        beep_stop();
      }
      DAT_0001b3e3 = DAT_00012041;
      return;
    }
  }
  else if (DAT_00012040 == '\x03') {
    tone_idle();
    DAT_00012040 = 0;
    DAT_00012041 = 0;
    DAT_00025d40 = 0.0;
    DAT_0001b3e3 = 0;
    return;
  }
  return;
}


// ===== beep_request @ fffb2da6 (78 bytes)

/* (pattern) */

void beep_request(int param_1)

{
  if (param_1 != 8) {
    if (param_1 - 9U < 3) {
      if (DAT_00012041 == '\x04') {
        return;
      }
    }
    else if (DAT_00012041 != '\0') {
      return;
    }
  }
  DAT_00012041 = (char)param_1;
  DAT_00012040 = 1;
  return;
}


// ===== beep_stop @ fffb2df4 (10 bytes)

void beep_stop(void)

{
  DAT_00012040 = 3;
  return;
}


// ===== FUN_fffb2dfe @ fffb2dfe (15 bytes)

undefined1 FUN_fffb2dfe(void)

{
  return DAT_00012041;
}


// ===== tone_idle @ fffb2e0d (17 bytes)

void tone_idle(void)

{
  tone_stop();
  dac0_write(DAT_0001ff1c);
  return;
}


// ===== tone_set @ fffb2e1e (126 bytes)

/* (freq_Hz float, ms): TPU1 TGRA = 60e6/(36*f)-1, 36-sample table 0x1FF1C */

void tone_set(float param_1,undefined2 param_2)

{
  bool bVar1;
  
  if (param_1 - 0.0 != 0.0) {
    if ((param_1 - 30.0 < 0.0) || (20000.0 < param_1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_00088128 = SUB42(ROUND(1.0 / ((param_1 * 36.0) / 6e+07) + -1.0),0);
    tone_play(&DAT_0001ff1c,0x24);
  }
  swtimer_start(0x16,param_2);
  return;
}


// ===== nib2hex @ fffb2e9c (27 bytes)

/* Nibble -> ASCII hex digit */

char nib2hex(byte param_1)

{
  return "@0123456789ABCDEF"[(param_1 & 0xf) + 1];
}


// ===== byte2hex @ fffb2eb7 (48 bytes)

/* Byte -> 2 ASCII hex chars */

void byte2hex(char *param_1,byte param_2)

{
  *param_1 = "@0123456789ABCDEF"[(param_2 >> 4) + 1];
  param_1[1] = "@0123456789ABCDEF"[(param_2 & 0xf) + 1];
  return;
}


// ===== word2hex @ fffb2ee7 (32 bytes)

/* u16 -> 4 ASCII hex chars */

void word2hex(int param_1,undefined4 param_2)

{
  byte2hex(param_1,(char)((uint)param_2 >> 8));
  byte2hex(param_1 + 2,(char)param_2);
  return;
}


// ===== hex2nib @ fffb2f07 (114 bytes)

/* ASCII hex digit -> value (0xFF if invalid) */

char hex2nib(byte param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = -1;
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    local_3 = param_1 - 0x30;
  }
  else {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_3 = param_1 - 0x37;
    }
    else {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_3 = param_1 + 0xa9;
      }
    }
  }
  return local_3;
}


// ===== hex2byte @ fffb2f79 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2f86) */
/* 2 ASCII hex chars -> byte */

byte hex2byte(undefined1 *param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = hex2nib(*param_1);
  bVar2 = hex2nib(param_1[1]);
  return bVar2 | cVar1 << 4;
}


// ===== hex2word @ fffb2f9e (34 bytes)

/* 4 ASCII hex chars -> u16 */

ushort hex2word(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = hex2byte();
  uVar2 = hex2byte(param_1 + 2);
  return uVar2 | sVar1 << 8;
}


// ===== FUN_fffb2fc0 @ fffb2fc0 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2fd4) */

char FUN_fffb2fc0(byte param_1)

{
  return *(char *)((int)&PTR_DAT_fff880c2 + (uint)(param_1 >> 4) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb2fec @ fffb2fec (93 bytes)

short FUN_fffb2fec(ushort param_1)

{
  return *(short *)(&DAT_fff880ea + (uint)(param_1 >> 0xc) * 2) +
         *(short *)(&DAT_fff880d6 + (param_1 >> 8 & 0xf) * 2) +
         *(short *)((int)&PTR_DAT_fff880c2 + (param_1 >> 4 & 0xf) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb30b5 @ fffb30b5 (104 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb30e6) */

byte FUN_fffb30b5(byte *param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte local_6;
  
  local_6 = 0;
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    cVar2 = hex2nib(*param_1);
    local_6 = cVar2 << 4;
  }
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bVar3 = hex2nib(param_1[1]);
    local_6 = bVar3 | local_6;
  }
  return local_6;
}


// ===== FUN_fffb311d @ fffb311d (75 bytes)

void FUN_fffb311d(char *param_1,uint param_2)

{
  byte bVar1;
  
  if ((param_2 >> 4 & 0xff) < 10) {
    *param_1 = "@0123456789ABCDEF"[(param_2 >> 4 & 0xff) + 1];
  }
  else {
    *param_1 = ' ';
  }
  bVar1 = (byte)param_2 & 0xf;
  if (9 < bVar1) {
    param_1[1] = ' ';
    return;
  }
  param_1[1] = "@0123456789ABCDEF"[bVar1 + 1];
  return;
}


// ===== toupper_inplace @ fffb3168 (46 bytes)

/* a-z -> A-Z on one byte in place */

void toupper_inplace(byte *param_1)

{
  bool bVar1;
  
  if ((*param_1 < 0x61) || (0x7a < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *param_1 = *param_1 - 0x20;
    return;
  }
  return;
}


// ===== vfo_mode @ fffb3196 (182 bytes)

/* (which): mode nibble (rec+0) of vfo_rec_ptr(which); forced to 2 during tune cycles */

byte vfo_mode(char param_1)

{
  undefined4 *in_R14;
  char local_a;
  byte local_9;
  
  local_a = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_a = DAT_00009c5e;
  }
  if (local_a == '\0') {
    *in_R14 = 1;
  }
  if (DAT_00009dbd == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      local_9 = DAT_00009d63;
    }
    else {
      local_9 = DAT_00009d09;
    }
  }
  else if (in_R14 == (undefined4 *)0x0) {
    local_9 = DAT_00009d09;
  }
  else {
    local_9 = DAT_00009d63;
  }
  if (DAT_00020f0c == '\x01') {
    local_9 = 2;
  }
  else if (DAT_00020f0c == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b40 == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b41 == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b25 == '\x01') {
    local_9 = 2;
  }
  return local_9 & 0xf;
}


// ===== vfo_rec_ptr @ fffb324c (94 bytes)

/* (which): 0 = active VFO record (0x9DBD), !=0 = TX record (other VFO while split 0x9C5E); returns
   0x9D09/0x9D63 in R1 */

void vfo_rec_ptr(char param_1)

{
  undefined4 *in_R14;
  char local_11;
  
  local_11 = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_11 = DAT_00009c5e;
  }
  if (local_11 == '\0') {
    *in_R14 = 1;
  }
  return;
}


// ===== FUN_fffb32aa @ fffb32aa (83 bytes)

undefined1 FUN_fffb32aa(char param_1)

{
  undefined4 *in_R14;
  undefined1 local_a;
  char local_9;
  
  local_9 = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_9 = DAT_00009c5e;
  }
  if (local_9 == '\0') {
    *in_R14 = 1;
  }
  if (DAT_00009dbd == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      local_a = 1;
    }
    else {
      local_a = 0;
    }
  }
  else if (in_R14 == (undefined4 *)0x0) {
    local_a = 0;
  }
  else {
    local_a = 1;
  }
  return local_a;
}


// ===== FUN_fffb32fd @ fffb32fd (58 bytes)

byte FUN_fffb32fd(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff886b8 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3337 @ fffb3337 (58 bytes)

byte FUN_fffb3337(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (6 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff886f0 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3371 @ fffb3371 (58 bytes)

byte FUN_fffb3371(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (10 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff8870c + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb33ab @ fffb33ab (58 bytes)

byte FUN_fffb33ab(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xc < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff88738 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== band_of_freq @ fffb33e5 (96 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb33f4) */
/* WARNING: Removing unreachable block (ram,0xfffb3403) */
/* Band index 0..11 of a frequency (ranges at 0xFFF8876C), 0xFF if none */

byte band_of_freq(uint param_1)

{
  bool bVar1;
  byte local_11;
  
  local_11 = 0;
  while( true ) {
    if (0xb < local_11) {
      return 0xff;
    }
    if ((param_1 < *(uint *)(&band_table + (uint)local_11 * 8)) ||
       (*(uint *)(&DAT_fff88770 + (uint)local_11 * 8) <= param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) break;
    local_11 = local_11 + 1;
  }
  return local_11;
}


// ===== gen_subband_of_freq @ fffb3445 (59 bytes)

/* GEN sub-slot 0..15 from boundaries at 0xFFF887CC */

byte gen_subband_of_freq(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0x11 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&gen_subband_table + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== freq_range_index @ fffb3480 (58 bytes)

/* Index of f in boundary table 0xFFF88814 */

byte freq_range_index(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&freq_range_table + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb34ba @ fffb34ba (21 bytes)

char FUN_fffb34ba(byte param_1)

{
  return "@0123456789ABCDEF"[param_1 + 0x11];
}


// ===== FUN_fffb34cf @ fffb34cf (21 bytes)

undefined1 FUN_fffb34cf(byte param_1)

{
  return (&DAT_fff81118)[param_1];
}


// ===== FUN_fffb34e4 @ fffb34e4 (21 bytes)

undefined2 FUN_fffb34e4(byte param_1)

{
  return *(undefined2 *)((int)&PTR_DAT_fff88126 + (uint)param_1 * 2);
}


// ===== FUN_fffb34f9 @ fffb34f9 (21 bytes)

undefined1 FUN_fffb34f9(byte param_1)

{
  return (&DAT_fff8117d)[param_1];
}


// ===== FUN_fffb350e @ fffb350e (21 bytes)

undefined2 FUN_fffb350e(byte param_1)

{
  return *(undefined2 *)(&DAT_fff881f0 + (uint)param_1 * 2);
}


// ===== FUN_fffb3523 @ fffb3523 (21 bytes)

undefined1 FUN_fffb3523(byte param_1)

{
  return (&DAT_fff811e2)[param_1];
}


// ===== FUN_fffb3538 @ fffb3538 (21 bytes)

undefined1 FUN_fffb3538(byte param_1)

{
  return (&DAT_fff812e2)[param_1];
}


// ===== FUN_fffb354d @ fffb354d (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3553) */

undefined1 FUN_fffb354d(byte param_1)

{
  return (&DAT_fff81347)[(uint)param_1 * 2];
}


// ===== FUN_fffb3564 @ fffb3564 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb356a) */

undefined1 FUN_fffb3564(byte param_1)

{
  return (&DAT_fff81348)[(uint)param_1 * 2];
}


// ===== vfo_freq @ fffb357c (91 bytes)

/* (which, side): BE u32 at rec+0x4A; side 0=A 1=B 2=vfo_rec_ptr(which) */

void vfo_freq(undefined1 param_1,char param_2)

{
  byte local_15;
  
  if ((param_2 != '\0') && (param_2 != '\x01')) {
    vfo_rec_ptr(param_1);
  }
  for (local_15 = 0; local_15 < 4; local_15 = local_15 + 1) {
  }
  return;
}


// ===== vfo_freq_clar @ fffb35d7 (296 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb36cf) */
/* (which, side): vfo_freq + clar offset rec+0x48 if RX/TX clar bit set in 0x20F29/0x20F2A */

void vfo_freq_clar(char param_1,char param_2)

{
  undefined4 *extraout_R14;
  undefined4 *puVar1;
  char cStack_18;
  
  vfo_freq(param_1,param_2);
  cStack_18 = '\0';
  if ((param_2 != '\0') && (param_2 != '\x01')) {
    vfo_rec_ptr(param_1);
    puVar1 = extraout_R14;
    if (param_1 != '\0') {
      puVar1 = (undefined4 *)&DAT_0000464f;
      cStack_18 = DAT_00009c5e;
    }
    if (cStack_18 == '\0') {
      *puVar1 = 1;
    }
  }
  return;
}


// ===== FUN_fffb36ff @ fffb36ff (118 bytes)

byte FUN_fffb36ff(byte param_1,ushort param_2)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    for (local_6 = 0; local_6 < 0x15; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(&DAT_fff882e8 + (uint)local_6 * 2) & 0xff)) {
        return local_6;
      }
    }
  }
  else if (uVar1 < 2) {
    for (local_6 = 0; local_6 < 0x17; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(&DAT_fff882ba + (uint)local_6 * 2) & 0xff)) {
        return local_6;
      }
    }
  }
  return 0xff;
}


// ===== FUN_fffb3775 @ fffb3775 (88 bytes)

undefined2 FUN_fffb3775(byte param_1,byte param_2)

{
  uint uVar1;
  undefined2 local_6;
  
  local_6 = 0xffff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    if (param_2 < 0x15) {
      local_6 = *(undefined2 *)(&DAT_fff882e8 + (uint)param_2 * 2);
    }
  }
  else if ((uVar1 < 2) && (param_2 < 0x17)) {
    local_6 = *(undefined2 *)(&DAT_fff882ba + (uint)param_2 * 2);
  }
  return local_6;
}


// ===== FUN_fffb37cd @ fffb37cd (49 bytes)

undefined1 FUN_fffb37cd(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  local_3 = 0xff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    local_3 = 0x15;
  }
  else if (uVar1 < 2) {
    local_3 = 0x17;
  }
  return local_3;
}


// ===== tx_freq_allowed @ fffb37fe (675 bytes)

/* (freq): destination-code band table 0xFFF8884C.., inhibit flags */

undefined1 tx_freq_allowed(undefined *param_1)

{
  undefined *puVar1;
  bool bVar2;
  short sVar3;
  undefined **ppuVar4;
  int iVar5;
  byte bStack_1c;
  char cStack_1b;
  undefined1 uStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  undefined **ppuStack_14;
  
  sVar3 = dest_code_get();
  bStack_18 = 0;
  uStack_1a = 0;
  bStack_19 = 0xff;
  if (DAT_00020bbe != '\0') {
    return 1;
  }
  if ((DAT_0000465c == '\0') && (DAT_00009af5 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (DAT_00020b46 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (DAT_00020b47 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (sVar3 == -0x26b0) {
    bStack_18 = 0xc;
    ppuStack_14 = (undefined **)&DAT_fff88a0c;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x1cb9) {
    bStack_18 = 1;
    ppuStack_14 = &PTR_DAT_fff88a6c;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x306f) goto LAB_fffb38f4;
  if (sVar3 == 0x315b) {
    bStack_18 = 0x15;
    ppuStack_14 = (undefined **)&DAT_fff888a4;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x4380) {
LAB_fffb38da:
    bStack_18 = 0xb;
    ppuStack_14 = (undefined **)&DAT_fff8884c;
  }
  else {
    if (sVar3 != 0x50e2) {
      if (sVar3 == 0x60e6) goto LAB_fffb38da;
      if (sVar3 == 0x7753) {
LAB_fffb3901:
        bStack_18 = 10;
        ppuStack_14 = (undefined **)&DAT_fff88964;
        goto LAB_fffb3933;
      }
      if ((sVar3 != -0x6309) && (sVar3 != -0x5b3b)) {
        if (sVar3 == -0x567d) {
          bStack_18 = 0xb;
          ppuStack_14 = (undefined **)&DAT_fff889b4;
          goto LAB_fffb3933;
        }
        if (sVar3 != -0x4a59) {
          if (sVar3 != -0x2cd3) {
            if (sVar3 != 0x20b) goto LAB_fffb3933;
            goto LAB_fffb38da;
          }
          goto LAB_fffb3901;
        }
      }
    }
LAB_fffb38f4:
    bStack_18 = 3;
    ppuStack_14 = (undefined **)&DAT_fff8894c;
  }
LAB_fffb3933:
  bStack_17 = 0;
  do {
    if (bStack_18 <= bStack_17) {
LAB_fffb397e:
      if (bStack_19 != 0xff) {
        if ((sVar3 == 0x315b) && (9 < bStack_19)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          iVar5 = FUN_fffb32aa(1);
          if (iVar5 == 0) {
            cStack_1b = DAT_00009dbe;
            bStack_1c = DAT_000060c9;
          }
          else {
            cStack_1b = DAT_00009dbf;
            bStack_1c = DAT_000060ca;
          }
          if ((cStack_1b == '\x02') && (0x74 < bStack_1c)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if ((bVar2) && (bStack_1c < 0x85)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (!bVar2) {
            uStack_1a = 0;
          }
        }
        if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          uStack_1a = 0;
          DAT_00020b24 = 0;
          DAT_00020b25 = 0;
          DAT_00020b26 = 0;
          DAT_00020b27 = 0;
          DAT_00020b28 = 0;
          DAT_00020b29 = 0;
          DAT_00020b2b = 0;
          DAT_00020b2c = 0;
          DAT_00020b2d = 0;
          DAT_00020b2e = 0;
        }
      }
      return uStack_1a;
    }
    puVar1 = *ppuStack_14;
    ppuVar4 = ppuStack_14 + 1;
    ppuStack_14 = ppuStack_14 + 2;
    if ((param_1 < puVar1) || (*ppuVar4 <= param_1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bStack_19 = bStack_17;
      uStack_1a = 1;
      goto LAB_fffb397e;
    }
    bStack_17 = bStack_17 + 1;
  } while( true );
}


// ===== freq_in_range @ fffb3aa1 (77 bytes)

/* 29999 < f < 75000001 */

undefined1 freq_in_range(undefined *param_1)

{
  undefined1 uVar1;
  
  if ((&DAT_0000752f < param_1) && (param_1 < (undefined *)0x47868c1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffb3aee @ fffb3aee (69 bytes)

void FUN_fffb3aee(void)

{
  return;
}


// ===== dest_code_get @ fffb3b33 (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3b43) */
/* Returns destination code 0x475E:0x475F */

undefined2 dest_code_get(void)

{
  return CONCAT11(DAT_0000475e,DAT_0000475f);
}


// ===== dest_code_set @ fffb3b5d (73 bytes)

/* Sets destination code, writes EEPROM, settings_defaults(0), requests restart (0x20F4B=1,
   0x20B39=0x11) */

void dest_code_set(undefined2 param_1)

{
  undefined1 local_2;
  
  DAT_00009dc5 = 1;
  DAT_0000475e = (undefined1)((ushort)param_1 >> 8);
  local_2 = (undefined1)param_1;
  DAT_0000475f = local_2;
  eeprom_save_dest();
  settings_defaults(0);
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== dest_jumper_apply @ fffb3ba6 (363 bytes)

/* JP_P51 strap: switch destination code between restricted/wide pairs */

void dest_jumper_apply(void)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  
  sVar3 = dest_code_get();
  cVar2 = jp_p51_get();
  if ((sVar3 == 0x315b) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_000050e2);
    return;
  }
  if ((sVar3 == 0x50e2) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000315b);
    return;
  }
  if ((sVar3 == -0x567d) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000b5a7);
    return;
  }
  if ((sVar3 == -0x4a59) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000a983);
    return;
  }
  if ((sVar3 == -0x26b0) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000a4c5);
    return;
  }
  if ((sVar3 == -0x5b3b) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000d950);
    return;
  }
  if ((sVar3 == -0x2cd3) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000306f);
    return;
  }
  if ((sVar3 == 0x306f) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((sVar3 == 0x7753) && (cVar2 == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(&DAT_00009cf7);
      return;
    }
    if ((sVar3 == -0x6309) && (cVar2 != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(&DAT_00007753);
      return;
    }
    return;
  }
  dest_code_set(&DAT_0000d32d);
  return;
}


// ===== FUN_fffb3d11 @ fffb3d11 (324 bytes)

char FUN_fffb3d11(byte param_1)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  char local_3;
  
  local_3 = -1;
  bVar3 = ptt_source_get();
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb3dc1:
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a74;
    }
    else {
      local_3 = DAT_00020b65;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 == '\0') {
        local_3 = DAT_00009a4c;
      }
      else {
        local_3 = DAT_00020b65;
      }
      goto LAB_fffb3de6;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb3dc1;
      if (1 < uVar1 - 10) {
        if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            local_3 = DAT_00009a37;
          }
          else {
            local_3 = DAT_00020b65;
          }
        }
        goto LAB_fffb3de6;
      }
    }
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a5e;
    }
    else {
      local_3 = DAT_00020b65;
    }
  }
LAB_fffb3de6:
  if (local_3 != -1) {
    if (DAT_00020b7c == '\x02') {
      local_3 = '\0';
    }
    else {
      if ((bVar3 == 0) || (bVar3 == 6)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (DAT_00009c5d != '\0') {
          local_3 = DAT_00009af3;
        }
      }
      else if (local_3 == '\x03') {
        if (bVar3 == 1) {
          local_3 = '\x02';
        }
        else if (bVar3 - 3 < 3) {
          local_3 = '\x01';
        }
        else {
          local_3 = '\0';
        }
      }
    }
  }
  return local_3;
}


// ===== sw_reset @ fffb3e55 (21 bytes)

/* PRCR=0xA502, SWRR 0x800C2=0xA501: software reset (end of power-off) [inference] */

void sw_reset(void)

{
  DAT_000803fe = 0xa502;
  DAT_000800c2 = 0xa501;
  return;
}


// ===== wdt_kick @ fffb3e6a (5 bytes)

/* main_loop task 1 / power-off loop: R_IWDT_Restart */

void wdt_kick(void)

{
  iwdt_refresh();
  return;
}

