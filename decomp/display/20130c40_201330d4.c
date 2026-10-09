// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20130c40 @ 20130c40 (12 bytes)

void FUN_20130c40(undefined1 param_1)

{
  DAT_20800492 = param_1;
  return;
}


// ===== FUN_20130c70 @ 20130c70 (32 bytes)

void FUN_20130c70(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_208f4baa;
  FUN_20155274(&DAT_208f4896,0x35e);
  DAT_208f4baa = uVar1;
  return;
}


// ===== FUN_20130c90 @ 20130c90 (1052 bytes)

void FUN_20130c90(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 local_8;
  
  local_8 = 0;
  switch(param_1) {
  case 0:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b91 >> 6;
    }
    else {
      if ((DAT_208f0b91 & 0xc0) == (*(byte *)(param_2 + 0x67) & 0xc0)) {
        return;
      }
      bVar3 = *(byte *)(param_2 + 0x67) >> 6;
    }
    goto LAB_20130eb4;
  case 1:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b91;
      if ((DAT_208f0b91 & 0x30) != 0) goto LAB_20130d5c;
    }
    else {
      if ((DAT_208f0b91 & 0x3f) == (*(byte *)(param_2 + 0x67) & 0x3f)) {
        return;
      }
      if ((*(byte *)(param_2 + 0x67) & 0x30) != 0) {
        bVar3 = *(byte *)(param_2 + 0x67);
LAB_20130d5c:
        local_8 = 0x100000;
        bVar3 = bVar3 & 0xf;
        goto LAB_20130eb4;
      }
    }
    break;
  case 2:
    if (param_3 == 0) {
      local_8 = (uint)(byte)((DAT_208f0b92 & 3) + (DAT_208f0b92 >> 3 & 0x10)) << 8;
    }
    else {
      if (DAT_208f0b92 == *(byte *)(param_2 + 0x68)) {
        return;
      }
      local_8 = (uint)(byte)((*(byte *)(param_2 + 0x68) & 3) +
                            (*(byte *)(param_2 + 0x68) >> 3 & 0x10)) << 8;
    }
    break;
  case 3:
    bVar3 = DAT_208f0b93;
    if ((param_3 != 0) && (bVar3 = *(byte *)(param_2 + 0x69), DAT_208f0b93 == bVar3)) {
      return;
    }
    goto LAB_20130eb4;
  case 4:
    if (param_3 == 0) {
      local_8 = (uint)(byte)((DAT_208f0b95 & 3) + DAT_208f0b94 * '\x10') << 8;
    }
    else {
      if ((DAT_208f0b94 == *(char *)(param_2 + 0x6a)) && (DAT_208f0b95 == *(byte *)(param_2 + 0x6b))
         ) {
        return;
      }
      local_8 = (uint)(byte)((*(byte *)(param_2 + 0x6b) & 3) + *(char *)(param_2 + 0x6a) * '\x10')
                << 8;
    }
    break;
  case 5:
    if (param_3 != 0) {
      bVar3 = *(byte *)(param_2 + 0x6c);
      if (DAT_208f0b96 == bVar3) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6c);
LAB_20130ee8:
      bVar3 = bVar3 >> 3 & 0x10;
      bVar2 = (byte)((bVar2 & 0x1f) >> 4);
      goto LAB_20130f3c;
    }
    bVar3 = (DAT_208f0b96 >> 3 & 0x10) - (char)((int)((uint)DAT_208f0b96 << 0x1b) >> 0x1f);
    goto LAB_20130eb4;
  case 6:
    if (param_3 != 0) {
      bVar3 = *(byte *)(param_2 + 0x6d);
      if (DAT_208f0b97 == bVar3) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6d);
      goto LAB_20130ee8;
    }
    bVar3 = (DAT_208f0b97 >> 3 & 0x10) - (char)((int)((uint)DAT_208f0b97 << 0x1b) >> 0x1f);
    goto LAB_20130eb4;
  case 7:
    bVar2 = DAT_208f0b97;
    bVar3 = DAT_208f0b97;
    if (param_3 != 0) {
      if (DAT_208f0b97 == *(byte *)(param_2 + 0x6d)) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6d);
      bVar3 = *(byte *)(param_2 + 0x6d);
    }
    bVar3 = (bVar3 & 4) << 2;
    bVar2 = bVar2 & 3;
LAB_20130f3c:
    local_8 = 0;
    bVar3 = bVar2 + bVar3;
    goto LAB_20130eb4;
  case 8:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b98 & 3;
    }
    else {
      if (DAT_208f0b98 == *(byte *)(param_2 + 0x6e)) {
        return;
      }
      bVar3 = *(byte *)(param_2 + 0x6e) & 3;
    }
    goto LAB_20130eb4;
  case 9:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b99 & 0x7f;
    }
    else {
      bVar3 = *(byte *)(param_2 + 0x6f) & 0x7f;
      if ((DAT_208f0b99 & 0x7f) == bVar3) {
        return;
      }
    }
LAB_20130eb4:
    local_8 = (uint)CONCAT21(local_8._2_2_,bVar3) << 8;
    break;
  case 10:
    if (param_3 != 0) {
      return;
    }
    local_8 = (uint)(DAT_208f0b9a & 0xff30) << 0x10;
    if ((DAT_208f0b9a & 0x30) != 0) {
      local_8 = (uint)(CONCAT11(DAT_208f0b9a,DAT_208f0b9a) & 0xff300f) << 8;
    }
    DAT_208084d9 = DAT_208f0b9a & 0xf;
    break;
  default:
    goto switchD_20130ca0_caseD_b;
  case 0xd:
    if (param_3 == 0) {
      bVar3 = (byte)(((uint)DAT_208f0b9b << 0x19) >> 0x18);
    }
    else {
      if ((uint)DAT_208f0b9b == (uint)*(byte *)(param_2 + 0x71)) {
        return;
      }
      bVar3 = (byte)(((uint)*(byte *)(param_2 + 0x71) << 0x19) >> 0x18);
    }
    local_8 = (uint)(byte)((bVar3 >> 6) + 0x10) << 0x10;
    break;
  case 0xe:
    if (param_3 == 0) {
      uVar1 = CONCAT11((byte)(((uint)DAT_208f0b9b << 0x1b) >> 0x1e),DAT_208f0b9b);
    }
    else {
      if ((uint)DAT_208f0b9b == (uint)*(byte *)(param_2 + 0x71)) {
        return;
      }
      uVar1 = CONCAT11((byte)(((uint)*(byte *)(param_2 + 0x71) << 0x1b) >> 0x1e),
                       *(undefined1 *)(param_2 + 0x71));
    }
    local_8._0_2_ = (short)(uVar1 & 0xffff07) << 8;
    local_8._2_1_ = (char)((uVar1 & 0xffff07) >> 8);
    local_8._0_3_ = CONCAT12(local_8._2_1_ + '\x10',(short)local_8);
    local_8 = (uint)(uint3)local_8;
    break;
  case 0xf:
    if ((param_3 != 0) && (DAT_208f0b4c == *(byte *)(param_2 + 0x22))) {
      return;
    }
    local_8._0_2_ = (ushort)DAT_208f0b4c << 8;
    local_8._0_3_ = CONCAT12(0x10,(short)local_8);
    local_8 = (uint)(uint3)local_8;
    param_1 = 0x31;
  }
  local_8 = CONCAT31(local_8._1_3_,(char)param_1 + '\x11');
  FUN_20114e88(&local_8,3);
  itron_dly_tsk(1);
switchD_20130ca0_caseD_b:
  return;
}


// ===== FUN_201310ec @ 201310ec (68 bytes)

void FUN_201310ec(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_20130c90(bVar1,param_1,param_2);
    do {
      bVar1 = bVar1 + 1;
      if (0xf < bVar1) {
        return;
      }
    } while (bVar1 == 0xb || bVar1 == 0xc);
  } while( true );
}


// ===== FUN_20131130 @ 20131130 (36 bytes)

void FUN_20131130(undefined1 param_1)

{
  (&DAT_208f4bac)[DAT_208f4bec] = param_1;
  DAT_208f4bec = DAT_208f4bec + 1 & 0x3f;
  return;
}


// ===== FUN_20131154 @ 20131154 (512 bytes)

void FUN_20131154(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (0 < param_2) {
    do {
      bVar4 = *param_1;
      if (bVar4 == 0x10) {
LAB_20131230:
        FUN_20131130(bVar4);
LAB_20131238:
        if (bVar4 == 0x20) goto LAB_2013129c;
      }
      else {
        if (bVar4 < 0x11) {
          if (bVar4 == 0) goto LAB_20131238;
          if (bVar4 == 6) goto LAB_20131230;
          if (bVar4 != 10) goto LAB_201311c4;
          goto LAB_2013129c;
        }
        if (bVar4 == 0x1c) goto LAB_20131238;
        if (bVar4 == 0x1d) goto LAB_20131230;
LAB_201311c4:
        if (DAT_208084d9 == '\x01') {
          iVar3 = 8;
LAB_20131244:
          uVar2 = 0;
          do {
            if (iVar3 == 3) {
              if ((&DAT_20801de0)[uVar2] == bVar4) goto LAB_2013129c;
              bVar1 = (&DAT_20801e0f)[uVar2];
            }
            else {
              if ((&DAT_20801ecb)[uVar2] == bVar4) goto LAB_2013129c;
              bVar1 = (&DAT_20801efa)[uVar2];
            }
            if (bVar1 == bVar4) goto LAB_2013129c;
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0x2f);
        }
        else {
          if (DAT_208084d9 == '\x04') {
            iVar3 = 3;
            goto LAB_20131244;
          }
          uVar2 = 0;
          do {
            if ((((&DAT_20801e3e)[uVar2] == bVar4) || ((&DAT_20801e6d)[uVar2] == bVar4)) ||
               ((&DAT_20801e9c)[uVar2] == bVar4)) goto LAB_2013129c;
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0x2f);
        }
        bVar4 = 0x20;
LAB_2013129c:
        (&DAT_208f48c8)[DAT_208f489a] = bVar4;
        if ((bVar4 == 10) || (0x26 < DAT_208f489a)) {
          uVar2 = 0;
          do {
            iVar3 = uVar2 * 0x29;
            FUN_20155274(&DAT_208f48f1 + iVar3,0x29);
            memcpy(&DAT_208f48f1 + iVar3,&DAT_208f491a + iVar3,0x29);
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0xf);
          FUN_20155274(&DAT_208f4b58,0x29);
          memcpy(&DAT_208f4b58,&DAT_208f48c8,DAT_208f489a + 1);
          FUN_20155274(&DAT_208f48c8,0x29);
          if (DAT_208f4899 < 0x10) {
            DAT_208f4899 = DAT_208f4899 + 1;
          }
          DAT_208f489a = 0;
        }
        else {
          DAT_208f489a = DAT_208f489a + 1;
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
      param_1 = param_1 + 1;
    } while ((int)uVar5 < param_2);
  }
  return;
}


// ===== FUN_20131354 @ 20131354 (492 bytes)

void FUN_20131354(int param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar3 = *(byte *)(param_1 + 1) & 0x3f;
  DAT_208084d5 = -((char)*(byte *)(param_1 + 1) >> 7);
  if (DAT_208084d5 == '\0') {
    uVar2 = 0x32;
    do {
      cVar1 = *(char *)(param_1 + uVar2 + 3);
      if (cVar1 != ' ' && cVar1 != -2) break;
      uVar2 = uVar2 - 1 & 0xff;
    } while (uVar2 != 0);
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    FUN_20155274(&DAT_208f489f,0x29);
    memcpy(&local_48,param_1 + 4,uVar2);
    memcpy(&DAT_208f489f,param_1 + 4,uVar2);
    DAT_208f489b = (undefined1)uVar2;
    if ((DAT_208084d9 == '\x01' || DAT_208084d9 == '\x02') || DAT_208084d9 == '\x03') {
      if (DAT_208f4baa == 5) {
        DAT_208f4baa = 6;
      }
      else {
        DAT_208f4baa = 0;
      }
      DAT_208f4bab = 0;
      return;
    }
    if (DAT_208084d9 == '\x04') {
      DAT_208f4baa = 0xf;
      if (0x32 < bVar3) {
        bVar3 = 0x32;
      }
      DAT_208f4bab = bVar3;
      return;
    }
  }
  else {
    DAT_208084d7 = 0;
    if (DAT_208f4baa != 0x65) {
      if (0x65 < DAT_208f4baa) {
        switch(DAT_208f4baa) {
        case 0x66:
          DAT_208f4baa = 0x6f;
          break;
        case 0x67:
        case 0x68:
        case 0x69:
          DAT_208f4baa = 0x6d;
          break;
        case 0x6a:
          DAT_208f4baa = 0x6b;
          break;
        case 0x6b:
        case 0x6c:
        case 0x6d:
        case 0x6e:
        case 0x6f:
        case 0x70:
        case 0x71:
        case 0x72:
          goto switchD_201313b0_caseD_0;
        default:
switchD_201313b0_default:
          DAT_208f4baa = 0;
          return;
        }
        return;
      }
      if (DAT_208f4baa != 10) {
        if (DAT_208f4baa < 0xb) {
          switch(DAT_208f4baa) {
          case 0:
          case 4:
            goto switchD_201313b0_caseD_0;
          case 1:
            DAT_208f4baa = 0xe;
            return;
          case 2:
          case 3:
            if ((DAT_208084d9 != '\x01' && DAT_208084d9 != '\x02') && DAT_208084d9 != '\x03') {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0xe;
              return;
            }
            if (DAT_208084d8 != '\0') {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0xc;
              return;
            }
            DAT_208084d7 = 0;
            DAT_208f4baa = 0xe;
            return;
          case 5:
          case 6:
            DAT_208f4baa = 10;
            return;
          default:
            goto switchD_201313b0_default;
          }
        }
        if (DAT_208f4baa != 0xe) {
          if (DAT_208f4baa < 0xf) {
            if ((DAT_208f4baa != 0xb && DAT_208f4baa != 0xc) && DAT_208f4baa != 0xd) {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0;
              return;
            }
          }
          else if (DAT_208f4baa != 0xf) {
            if (DAT_208f4baa == 100) {
              DAT_208084d7 = 0;
              DAT_208f4baa = 10;
              return;
            }
            DAT_208084d7 = 0;
            DAT_208f4baa = 0;
            return;
          }
        }
      }
    }
  }
switchD_201313b0_caseD_0:
  return;
}


// ===== FUN_201315a4 @ 201315a4 (28 bytes)

void FUN_201315a4(void)

{
  DAT_208f4bed = 0;
  DAT_208f4bec = 0;
  FUN_2015526c(&DAT_208f4bac,0x40);
  return;
}


// ===== FUN_201315c0 @ 201315c0 (120 bytes)

undefined4 FUN_201315c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_208f4bed;
  if (uVar1 == DAT_208f4bec) {
    return 0;
  }
  if ((byte)(&DAT_208f4bac)[uVar1] == param_1) {
    (&DAT_208f4bac)[uVar1] = 0;
    DAT_208f4bed = DAT_208f4bed + 1 & 0x3f;
    return 1;
  }
  if ((byte)(&DAT_208f4bac)[uVar1] != 0) {
    (&DAT_208f4bac)[uVar1] = 0;
    DAT_208f4bed = DAT_208f4bed + 1 & 0x3f;
  }
  return 0;
}


// ===== FUN_20131638 @ 20131638 (1204 bytes)

void FUN_20131638(void)

{
  byte bVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0;
  local_24 = 0xb3;
  DAT_208084d9 = DAT_208f0b9a & 0xf;
  if (((DAT_208f0b31 & 0x80) == 0) || (DAT_208084d5 != '\0')) {
    DAT_208084d6 = '\0';
  }
  else {
    DAT_208084d6 = '\x01';
  }
  bVar1 = DAT_208f0b31 & 0x40;
  if ((((DAT_208f0b31 & 0x80) != 0 && DAT_208084d5 != '\0') && (DAT_208084d7 < 0x15)) &&
     (bVar4 = DAT_208084d7 + 1, bVar5 = DAT_208084d7 + 1, DAT_208084d7 = bVar4, 0x14 < bVar5)) {
    mainlink_queue_frame(&local_24,2);
    DAT_208084d7 = 99;
  }
  if (DAT_208f4baa == 0x65) {
    iVar6 = FUN_201315c0(6);
    goto joined_r0x2013199c;
  }
  uVar2 = local_28._1_3_;
  uVar3 = local_28._3_1_;
  if (DAT_208f4baa < 0x66) {
    if (DAT_208f4baa == 10) {
      local_28 = CONCAT13(local_28._3_1_,0x10);
      FUN_20114e88(&local_28,3);
LAB_20131940:
      FUN_201315a4();
    }
    else {
      if (DAT_208f4baa < 0xb) {
        switch(DAT_208f4baa) {
        case 0:
          if (DAT_208084d6 == '\0') {
            return;
          }
          DAT_208f4baa = 1;
          return;
        case 1:
          if (((DAT_208084d9 == 1 || DAT_208084d9 == 2) || DAT_208084d9 == 3) && (bVar1 != 0)) {
            local_28 = CONCAT31(uVar2,0x1b);
            local_28 = CONCAT13(uVar3,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff;
            if ((DAT_208f0b9a & 0x30) != 0) {
              local_28 = CONCAT22(local_28._2_2_,CONCAT11(DAT_208f0b9a,(undefined1)local_28)) &
                         0xffff0fff;
            }
            FUN_20114e88(&local_28,3);
            FUN_201315a4();
            DAT_208f4baa = DAT_208f4baa + 1;
            DAT_208084d8 = 1;
            return;
          }
          DAT_208f4baa = 3;
          return;
        case 2:
          iVar6 = FUN_201315c0(6);
          break;
        case 3:
          goto switchD_2013170c_caseD_3;
        case 4:
          iVar6 = FUN_201315c0(6);
          break;
        case 5:
          if ((DAT_208084d6 != '\0') && (DAT_208084d5 == '\0')) {
            if (DAT_208084d4 != '\x01') {
              return;
            }
            DAT_208f4baa = 100;
            return;
          }
          DAT_208f4baa = 10;
          return;
        case 6:
          DAT_208f4baa = 100;
          return;
        default:
          goto switchD_2013170c_default;
        }
        goto joined_r0x2013199c;
      }
      if (DAT_208f4baa == 0xe) {
LAB_20131904:
        DAT_208f4baa = 0;
        FUN_201315a4();
        return;
      }
      if (DAT_208f4baa < 0xf) {
        if (DAT_208f4baa == 0xb) {
          iVar6 = FUN_201315c0(0x10);
          if (iVar6 == 0) {
            return;
          }
        }
        else {
          if (DAT_208f4baa == 0xc) {
            if (((DAT_208084d9 != 1 && DAT_208084d9 != 2) && DAT_208084d9 != 3) ||
               (DAT_208084d8 != '\x01')) goto LAB_20131904;
            local_28 = CONCAT13(local_28._3_1_,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff
            ;
            if ((DAT_208f0b9a & 0x30) != 0) {
              local_28 = (uint)(CONCAT21(local_28._2_2_,DAT_208f0b9a) & 0xffff0f) << 8;
            }
            local_28 = CONCAT31(local_28._1_3_,0x1b);
            FUN_20114e88(&local_28,3);
            DAT_208084d8 = '\0';
            goto LAB_20131940;
          }
          if (DAT_208f4baa != 0xd) goto switchD_2013170c_default;
          iVar6 = FUN_201315c0(6);
          if (iVar6 == 0) {
            return;
          }
        }
      }
      else {
        if (DAT_208f4baa == 0xf) {
          return;
        }
        if (DAT_208f4baa != 100) goto switchD_2013170c_default;
        local_28 = CONCAT31(uVar2,0x1b);
        local_28 = CONCAT13(uVar3,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff;
        if ((DAT_208f0b9a & 0x30) != 0) {
          local_28 = CONCAT22(local_28._2_2_,CONCAT11(DAT_208f0b9a,(undefined1)local_28)) &
                     0xffff0fff;
        }
        FUN_20114e88(&local_28,3);
      }
    }
    goto LAB_201319a0;
  }
  switch(DAT_208f4baa) {
  case 0x66:
switchD_2013170c_caseD_3:
    local_28 = CONCAT13(local_28._3_1_,0x110);
    FUN_20114e88(&local_28,3);
    FUN_201315a4();
    goto LAB_201319a0;
  case 0x67:
    iVar6 = FUN_201315c0(6);
    if (iVar6 == 0) {
      return;
    }
    DAT_208084da = 3;
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x68:
    if (DAT_208084da != 0) {
LAB_20131a8c:
      DAT_208084da = DAT_208084da + -1;
      return;
    }
    goto LAB_201319d8;
  case 0x69:
    uVar7 = (uint)DAT_208f4bab;
    DAT_208f4bab = DAT_208f4bab + 1;
    local_28._0_2_ = CONCAT11((&DAT_208f489f)[uVar7],0x1d);
    local_28._0_3_ = (uint3)(ushort)local_28;
    FUN_20114e88(&local_28,3);
    FUN_201315a4();
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x6a:
    iVar6 = FUN_201315c0(0x1d);
    if (iVar6 == 0) {
      return;
    }
    if (DAT_208f489b <= DAT_208f4bab) {
      DAT_208f4baa = DAT_208f4baa + 1;
      return;
    }
LAB_201319d8:
    DAT_208f4baa = 'i';
    break;
  case 0x6b:
    if (DAT_208084d9 == 1) {
      DAT_208084da = 1;
    }
    else {
      DAT_208084da = 0x21;
    }
    DAT_208f4baa = 'l';
    break;
  case 0x6c:
    if (DAT_208084da != 0) goto LAB_20131a8c;
    DAT_208f4baa = 'm';
    break;
  case 0x6d:
    local_28 = CONCAT13(local_28._3_1_,0x10);
    FUN_20114e88(&local_28,3);
    FUN_201315a4();
    goto LAB_201319a0;
  case 0x6e:
    iVar6 = FUN_201315c0(0x10);
    goto joined_r0x2013199c;
  case 0x6f:
    local_28 = CONCAT13(local_28._3_1_,0x1b);
    FUN_20114e88(&local_28,3);
    DAT_208f4baa = DAT_208f4baa + 1;
    goto LAB_20131af4;
  case 0x70:
    iVar6 = FUN_201315c0(6);
joined_r0x2013199c:
    if (iVar6 == 0) {
      return;
    }
LAB_201319a0:
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x71:
    mainlink_queue_frame(&local_24,2);
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x72:
    DAT_208084d4 = '\0';
    DAT_208f4baa = '\x05';
    break;
  default:
switchD_2013170c_default:
    DAT_208f4baa = '\0';
LAB_20131af4:
    FUN_201315a4();
    return;
  }
  return;
}


// ===== FUN_20131f74 @ 20131f74 (768 bytes)

void FUN_20131f74(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,char *param_6)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(0);
  if (*param_6 != '{' && param_5 != 0) {
    FUN_20130c70();
  }
  DAT_2080850e = (undefined2)param_2;
  DAT_2080850c = (undefined2)param_3;
  DAT_208f489c = 5;
  DAT_208f489d = 0x28;
  DAT_20808510 = DAT_208084e8;
  DAT_20808512 = DAT_208084ea;
  DAT_20808514 = DAT_208084f4;
  DAT_20808516 = DAT_208084f6;
  DAT_208f4896 = param_1;
  FUN_20135aa4(uVar1,param_2,param_3,0x31e,3,0x3186);
  FUN_20135ad8(uVar1,DAT_2080850e,DAT_2080850c,0xe8,3,0x3186);
  FUN_20135aa4(uVar1,DAT_208084de,DAT_208084dc,0x31e,3,0x3186);
  FUN_20135ad8(uVar1,DAT_208084e2,DAT_208084e0,0xe8,3,0x3186);
  FUN_20135aa4(uVar1,DAT_208084ea + -3,DAT_208084e8 + -3,0x31e,3,0x3186);
  FUN_20135ad8(uVar1,DAT_208084e6,DAT_208084e4,DAT_208084f2 + DAT_208084fa + 3,3,0x3186);
  FUN_20135aa4(uVar1,DAT_208084f6 + -3,DAT_208084f4 + -3,0x2b6,3,0x3186);
  FUN_20135aa4(uVar1,DAT_20808522,DAT_20808520 + -3,DAT_208084e0 - DAT_20808520,3,0x3186);
  FUN_20135aa4(uVar1,DAT_2080851e,DAT_2080851c + -3,DAT_208084e0 - DAT_20808520,3,0x3186);
  fb_copy_rect(uVar1,DAT_2080851a,DAT_20808518,0x62,0x3c);
  gui_draw_runs(uVar1,DAT_2080851a,DAT_20808518,&DAT_2016dc48);
  gui_draw_runs(uVar1,DAT_2080851a + DAT_20808502,DAT_20808518 + DAT_20808500,&DAT_2016dc58);
  fb_copy_rect(uVar1,DAT_2080851e,DAT_2080851c,0x62,0x3c);
  gui_draw_runs(uVar1,DAT_2080851e,DAT_2080851c,&DAT_2016dc48);
  gui_draw_runs(uVar1,DAT_2080851e + DAT_20808502,DAT_2080851c + DAT_20808500,&DAT_2016dc68);
  FUN_20132f44(0);
  FUN_20136584(uVar1,DAT_20808522,DAT_20808520,DAT_20808504,DAT_20808506,0,0,0);
  return;
}


// ===== FUN_201322ac @ 201322ac (364 bytes)

void FUN_201322ac(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_278 [14];
  char local_26a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_copy_rect(uVar1,0x132,0,800,0xae);
  uVar2 = 0;
  do {
    FUN_20135ff0(uVar1,(&DAT_20808558)[uVar2],uVar2 * 0x20 + 0x132,400,0xf,&DAT_20800b1c);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 3);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_2011500c(auStack_278);
  if ((local_26a != '\x01' && local_26a != '\x02') && (local_26a != '\x03')) {
    local_26a = '\x01';
  }
  sprintf(&local_38,"ERROR CODE : %03d",local_26a);
  FUN_20135ff0(uVar1,&local_38,0x192,400,0xf,&DAT_20800b1c);
  gui_update_layers();
  FUN_20113d10();
  DAT_20808532 = 1;
  FUN_20158fd0();
  if (DAT_20800493 == '\0') {
    FUN_20107e90();
    FUN_2010dfc4();
    uVar1 = fb_get_layer_addr(DAT_208085b8);
    fb_copy_rect(uVar1,0,0,800,0x1e0);
    uVar1 = fb_get_layer_addr(DAT_208085bc);
    fb_copy_rect(uVar1,0,0,800,0x1e0);
    gui_update_layers();
    bootloader_screen(&DAT_208f4bf4,&DAT_208dbb44);
    DAT_20808532 = 0;
  }
  return;
}


// ===== fwupdate_screen @ 201322b4 (1384 bytes)

/* MAIN/DISPLAY FIRMWARE UPDATE, STEP 1 of 2 */

void fwupdate_screen(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_288 [288];
  undefined1 auStack_168 [72];
  char local_120;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = fb_get_layer_addr(DAT_208085bc);
  fb_copy_rect(local_28,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    FUN_20135ff0(local_28,(&DAT_20808564)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,&DAT_20800b1c);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  gui_update_layers();
  FUN_20158fd0();
  FUN_20107e90();
  FUN_2010dfc4();
  do {
    local_28 = fb_get_layer_addr(DAT_208085bc);
    fb_copy_rect(local_28,0x132,0,800,0xae);
    FUN_20135ff0(local_28,DAT_20808538,0x132,400,0xf,&DAT_20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    fwfile_check_versions(&DAT_208f4bfc);
    DAT_208f4c30 = 1;
    DAT_208f4c78 = 1;
    fwfile_status_text(&DAT_208f4bfc,1);
    DAT_208f4c30 = 0;
    DAT_208f4c78 = 0;
    gui_update_layers();
    local_28 = fb_get_layer_addr(DAT_208085bc);
    iVar1 = FUN_20103bb0();
    if (iVar1 != 0) {
      if ((DAT_208f4bfc == '\x01') && (DAT_208f4c44 == '\x01')) break;
      fb_copy_rect(local_28,0x132,0,800,0xae);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      if (DAT_208f4bfc == '\x01') {
        sprintf(&local_48,"[ OK ]");
      }
      else {
        sprintf(&local_48,"[ NG : %s ]",&DAT_208f4c11);
      }
      FUN_20135ec0(local_28,"MAIN FIRMWARE FILE",0x132,0x9d,0xf,&DAT_20800b1c);
      FUN_20135ec0(local_28,&local_48,0x132,0x1a4,0xf,&DAT_20800b1c);
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      if (DAT_208f4c44 == '\x01') {
        sprintf(&local_48,"[ OK ] %s",&DAT_208f4c80);
      }
      else {
        sprintf(&local_48,"[ NG : %s ]",&DAT_208f4c59);
      }
      FUN_20135ec0(local_28,"DISPLAY FIRMWARE FILE",0x152,0x9d,0xf,&DAT_20800b1c);
      FUN_20135ec0(local_28,&local_48,0x152,0x1a4,0xf,&DAT_20800b1c);
      FUN_20135ff0(local_28,DAT_2080853c,0x192,400,0xf,&DAT_20800b1c);
    }
    gui_update_layers();
    local_28 = fb_get_layer_addr(DAT_208085bc);
    iVar1 = FUN_20103ba0();
    while (iVar1 != 0) {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      FUN_201525f8(0xffffffff);
      gui_update_layers();
      local_28 = fb_get_layer_addr(DAT_208085bc);
      iVar1 = FUN_20103ba0();
    }
    fb_copy_rect(local_28,0x132,0,800,0xae);
    FUN_20135ff0(local_28,DAT_2080856c,0x132,400,0xf,&DAT_20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    iVar1 = FUN_20103bb0();
    while (iVar1 == 0) {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      FUN_201525f8(0xffffffff);
      iVar1 = FUN_20103bb0();
    }
  } while( true );
  DAT_208f4c30 = 1;
  DAT_208f4c78 = 1;
  fb_copy_rect(local_28,0x132,0,800,0xae);
  FUN_20135ff0(local_28,"STEP 1 of 2.",0x132,400,0xf,&DAT_20800b1c);
  uVar4 = 0;
  do {
    FUN_20135ff0(local_28,(&DAT_20808548)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,&DAT_20800b1c);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  FUN_20155310(auStack_168,&DAT_208f4bfc,0x120);
  FUN_20155310(auStack_288,&DAT_208f4bfc,0x120);
  iVar1 = 0xff;
  while( true ) {
    iVar2 = FUN_2010e2d4(&DAT_208f4bfc);
    iVar3 = FUN_20103ba0();
    if (iVar3 == 0) break;
    if ((iVar1 != iVar2) ||
       (iVar3 = FUN_2015507c(&DAT_208f4bfc,auStack_288,0x120), iVar1 = iVar2, iVar3 != 0)) {
      FUN_20155310(auStack_288,&DAT_208f4bfc,0x120);
      if (DAT_208f4bfc == '\x04') {
        FUN_201219b8(local_28,0x1a5,0x129,DAT_208f4c34 & 0xffff,DAT_208f4c34);
      }
      else if (DAT_208f4c44 == '\x04') {
        if (local_120 != '\x04') {
          fb_copy_rect(local_28,0x132,0,800,0xae);
          FUN_20135ff0(local_28,"STEP 2 of 2.",0x132,400,0xf,&DAT_20800b1c);
          uVar4 = 0;
          do {
            FUN_20135ff0(local_28,(&DAT_20808550)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,&DAT_20800b1c)
            ;
            uVar4 = uVar4 + 1 & 0xff;
          } while (uVar4 < 2);
        }
        FUN_201219b8(local_28,0x1a5,0x129,DAT_208f4c7c & 0xffff,DAT_208f4c7c);
        gui_update_layers();
        fb_get_layer_addr(DAT_208085bc);
      }
      FUN_20155310(auStack_168,&DAT_208f4bfc,0x120);
      if (iVar2 != 0) goto LAB_20159c44;
      gui_update_layers();
      local_28 = fb_get_layer_addr(DAT_208085bc);
      iVar1 = iVar2;
    }
  }
  iVar2 = 2;
LAB_20159c44:
  FUN_2010e4a0();
  if (iVar2 != 1) {
    FUN_20159158();
  }
  FUN_20114df4();
  return;
}


// ===== FUN_201322bc @ 201322bc (76 bytes)

void FUN_201322bc(int param_1)

{
  DAT_208f4bf4 = FUN_20135470(param_1);
  DAT_208f4bf6 = FUN_20135470(param_1 + 2);
  DAT_208f4bf8 = FUN_20135470(param_1 + 4);
  DAT_208f4bfa = FUN_20135470(param_1 + 10);
  return;
}


// ===== FUN_201322e4 @ 201322e4 (12 bytes)

void FUN_201322e4(undefined4 param_1)

{
  FUN_20159058(&DAT_208f4bf4,param_1);
  return;
}


// ===== FUN_201322f0 @ 201322f0 (12 bytes)

void FUN_201322f0(void)

{
  FUN_20159d98(&DAT_208f4bf4,"YAESU FT-710 FIRMWARE UPDATE");
  return;
}


// ===== FUN_20132320 @ 20132320 (120 bytes)

void FUN_20132320(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_fcfe0438;
  if (param_1 != '\0') {
    DAT_fcfe0438 = bVar1 & 0xfc;
    bVar1 = DAT_fcfe0034;
    DAT_fcfe0034 = bVar1 & 0xef;
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x10) != 0);
    return;
  }
  DAT_fcfe0438 = bVar1 & 0xfd;
  bVar1 = DAT_fcfe0034;
  DAT_fcfe0034 = bVar1 & 0xdf;
  do {
    bVar1 = DAT_fcfe0044;
  } while ((bVar1 & 0x20) != 0);
  return;
}


// ===== FUN_20132398 @ 20132398 (100 bytes)

void FUN_20132398(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_fcfe0034;
  if (param_1 == '\0') {
    bVar1 = bVar1 | 0x20;
  }
  else {
    bVar1 = bVar1 | 0x10;
  }
  DAT_fcfe0034 = bVar1;
  if (param_1 == '\0') {
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x20) == 0);
    bVar1 = DAT_fcfe0438;
    bVar1 = bVar1 | 2;
  }
  else {
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x10) == 0);
    bVar1 = DAT_fcfe0438;
    bVar1 = bVar1 | 1;
  }
  DAT_fcfe0438 = bVar1;
  return;
}


// ===== FUN_201323fc @ 201323fc (68 bytes)

void FUN_201323fc(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = &DAT_203a6fd4;
    param_1[1] = &DAT_203a6fe8;
    param_1[2] = &DAT_203a6fde;
    param_1[3] = &DAT_203a6ff2;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = &DAT_203a6ffc;
  }
  return;
}


// ===== FUN_20132440 @ 20132440 (92 bytes)

void FUN_20132440(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = &UNK_203a7006 + param_1 * 10;
    param_2[1] = &UNK_203a702e + param_1 * 10;
    param_2[2] = &UNK_203a701a + param_1 * 10;
    param_2[3] = &UNK_203a7042 + param_1 * 10;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = &UNK_203a7056 + param_1 * 10;
  }
  return;
}


// ===== FUN_2013249c @ 2013249c (104 bytes)

void FUN_2013249c(undefined4 param_1,int param_2)

{
  DAT_208f4d44 = 0;
  DAT_208f4d45 = 0;
  DAT_208f4d46 = 0x10;
  DAT_208f4d48 = 2;
  DAT_208f4d49 = 1;
  if (param_2 != 0) {
    DAT_208f4d4a = 0xcf;
    DAT_208f4d4c = 4;
    DAT_208f4d4e = 2;
    return;
  }
  DAT_208f4d4a = 0xaf;
  DAT_208f4d4c = 4;
  DAT_208f4d4e = 2;
  return;
}


// ===== FUN_20132504 @ 20132504 (228 bytes)

void FUN_20132504(int param_1,int param_2)

{
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  
  if (param_1 == 0) {
    local_1e = 0x20c;
    local_1c = 0x3f7;
    local_18 = 0x20;
    local_14 = 0x58;
    local_16 = 0x1e0;
  }
  else if (param_2 == 0) {
    local_1e = 0x204;
    local_1c = 0x43f;
    local_18 = 0x1f;
    local_14 = 0xe0;
    local_16 = 0x1e0;
  }
  else {
    local_1e = 0x273;
    local_1c = 0x41f;
    local_18 = 0x1b;
    local_16 = 600;
    local_14 = 0xd8;
  }
  local_10 = 0;
  local_12 = 800;
  local_1a = 0;
  local_1f = 0;
  local_20 = 1;
  FUN_20117b0c(param_1,&local_20);
  return;
}


// ===== FUN_201325e8 @ 201325e8 (152 bytes)

void FUN_201325e8(int param_1,int param_2)

{
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 auStack_3c [32];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined4 local_14;
  
  if (param_1 == 0) {
    local_40 = 0x1fb;
    local_3e = 0;
    FUN_201323fc(auStack_3c);
    local_1a = 1;
  }
  else {
    if (param_2 == 0) {
      local_40 = 0x21f;
    }
    else {
      local_40 = 0x20f;
    }
    local_3e = 0;
    FUN_20132440(param_2,auStack_3c);
    local_1a = 0;
  }
  local_1b = 0;
  local_1c = 0;
  local_18 = 0;
  local_17 = 0;
  local_19 = 0;
  local_16 = 0;
  local_14 = 0;
  FUN_20117ba8(param_1,&local_40);
  return;
}


// ===== FUN_20132680 @ 20132680 (124 bytes)

void FUN_20132680(short *param_1,int param_2,short param_3,short param_4)

{
  short sVar1;
  short sVar2;
  
  sVar1 = (short)DAT_20808574;
  sVar2 = (short)DAT_20808578;
  if (param_2 != 0) {
    sVar1 = (short)DAT_2080857c;
    sVar2 = (short)DAT_20808580;
  }
  *param_1 = sVar2 + param_4;
  param_1[1] = 0x15;
  param_1[2] = sVar1 + param_3;
  param_1[3] = 0xc;
  return;
}


// ===== fb_get_layer_addr @ 201326fc (88 bytes)

/* 800x480 RGB565 frame buffers at 0x60000000 + n*0xBB800 */

undefined * fb_get_layer_addr(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = 0xbb800;
    break;
  case 1:
    return &DAT_605048a0;
  case 2:
    iVar1 = 0x177000;
    break;
  case 3:
    return (undefined *)0x60000000;
  case 4:
    iVar1 = 0x232800;
    break;
  case 5:
    iVar1 = 0x2ee000;
    break;
  default:
    return (undefined *)0x0;
  }
  return (undefined *)(iVar1 + 0x60000000);
}


// ===== FUN_2013276c @ 2013276c (920 bytes)

int FUN_2013276c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined1 local_34 [8];
  int local_2c;
  int iStack_28;
  
  if (param_1 == 0) {
    uVar3 = 0x1e00020;
    uVar4 = 0x3200058;
  }
  else if (param_2 == 0) {
    uVar3 = 0x1e0001f;
    uVar4 = 0x32000e0;
  }
  else {
    uVar3 = 0x1e00057;
    uVar4 = 0x32000d8;
  }
  local_44 = 0;
  local_4c = 0;
  local_48 = 0;
  local_2c = param_1;
  iStack_28 = param_2;
  uVar5 = fb_get_layer_addr(0);
  local_3c = fb_get_layer_addr(1,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
  local_40 = fb_get_layer_addr(3);
  uVar1 = fb_get_layer_addr(5);
  local_68 = 0x100;
  local_60 = 0x640;
  local_58 = 0x6000000;
  local_5c = 0;
  local_54 = uVar3;
  local_50 = uVar4;
  iVar2 = FUN_20117dec(local_2c,3,&local_68);
  if (((iVar2 == 0) && (iVar2 = FUN_20118214(local_2c,3,1,&local_4c), iVar2 == 0)) &&
     (iVar2 = FUN_20133748(local_2c,3), iVar2 == 0)) {
    local_68 = 0x100;
    local_64 = local_3c;
    local_58 = 0x6000000;
    local_5c = 0;
    local_60 = 0x640;
    local_54 = uVar3;
    local_50 = uVar4;
    iVar2 = FUN_20117dec(local_2c,4,&local_68);
    if ((iVar2 == 0) && (iVar2 = FUN_20118214(local_2c,4,1,&local_4c), iVar2 == 0)) {
      iVar2 = FUN_20133748(local_2c,4);
    }
    DAT_208f4d50 = local_64;
    if (iVar2 == 0) {
      local_68 = 0x100;
      local_58 = 0x6000000;
      local_64 = local_40;
      local_5c = 0;
      local_60 = 0x640;
      local_54 = uVar3;
      local_50 = uVar4;
      iVar2 = FUN_20117dec(local_2c,5,&local_68);
      if ((iVar2 == 0) && (iVar2 = FUN_20118214(local_2c,5,1,&local_4c), iVar2 == 0)) {
        iVar2 = FUN_20133748(local_2c,5);
      }
      DAT_208f4d60 = local_64;
      if (iVar2 == 0) {
        local_68 = 0x100;
        local_60 = 0x640;
        local_58 = 0x6000000;
        local_5c = 0;
        local_64 = uVar1;
        local_54 = uVar3;
        local_50 = uVar4;
        FUN_20132680(&local_40,local_2c,400,0xf0);
        DAT_20808584 = (undefined2)local_40;
        DAT_20808586 = local_40._2_2_;
        DAT_20808588 = (undefined2)local_3c;
        DAT_2080858a = local_3c._2_2_;
        local_54 = local_40;
        local_50 = local_3c;
        iVar2 = FUN_20117dec(local_2c,6,&local_68);
        if ((iVar2 == 0) && (iVar2 = FUN_20118214(local_2c,6,1,&local_4c), iVar2 == 0)) {
          iVar2 = FUN_20133748(local_2c,6);
        }
        DAT_208f4d78 = &DAT_20808584;
        DAT_208f4d74 = 0;
        DAT_208f4d7c = 0;
        DAT_208f4d70 = uVar1;
        if ((iVar2 == 0) && (iVar2 = FUN_20133068(local_2c), iVar2 == 0)) {
          local_34[0] = 2;
          local_38 = local_34;
          FUN_20117ebc(local_2c,3,&local_38);
          local_34[0] = 3;
          local_38 = local_34;
          FUN_20117ebc(local_2c,4,&local_38);
          iVar2 = FUN_20117ebc(local_2c,5,&local_38);
          if (iVar2 == 0) {
            local_40 = 0;
            do {
              DataMemoryBarrier(2);
              local_40 = local_40 + 1;
            } while (local_40 < 0x3458);
            FUN_20133090(1);
          }
        }
      }
    }
  }
  return iVar2;
}


// ===== FUN_20132b58 @ 20132b58 (136 bytes)

/* WARNING: Removing unreachable block (ram,0x20117f54) */
/* WARNING: Removing unreachable block (ram,0x20117f5c) */
/* WARNING: Removing unreachable block (ram,0x20117f60) */

int FUN_20132b58(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  iVar1 = FUN_2013307c();
  if ((iVar1 == 0) && (iVar1 = FUN_20117f00(param_1,0xffffffff), iVar1 == 0)) {
    FUN_2011ba48(param_1,0xffffffff);
    FUN_2011d7f0(param_1,0xffffffff,0,extraout_r3,unaff_r4);
    return 0;
  }
  return iVar1;
}


// ===== FUN_20132b94 @ 20132b94 (152 bytes)

int FUN_20132b94(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  iVar1 = FUN_20132b58();
  if (iVar1 != 0) {
    return iVar1;
  }
  FUN_2011d1e0();
  FUN_20118364(param_1);
  FUN_201195e8(param_1);
  FUN_2011d7d8(param_1,0,0,extraout_r3,unaff_r4);
  iVar1 = FUN_2011d5a8();
  if (iVar1 == 0) {
    FUN_2011d7d8(param_1,4,0);
  }
  FUN_20132398(param_1);
  return 0;
}


// ===== FUN_20132bc0 @ 20132bc0 (268 bytes)

int FUN_20132bc0(int param_1)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined4 local_14;
  
  iVar1 = FUN_20132b94(1);
  DAT_20808574 = 0x58;
  DAT_20808578 = 0x20;
  if (iVar1 == 0) {
    local_18 = 6;
    local_17 = 0;
    if (param_1 == 0) {
      local_14 = FUN_2013249c(1);
    }
    else {
      local_14 = FUN_2013249c(1,param_1);
    }
    iVar1 = FUN_201179c0(1,&local_18,FUN_20132320);
    if ((iVar1 == 0) && (iVar1 = FUN_20132504(1,param_1), iVar1 == 0)) {
      iVar1 = FUN_201325e8(1,param_1);
      if (param_1 == 0) {
        FUN_20101dc4(0,1);
        DAT_2080857c = 0xe0;
        DAT_20808580 = 0x1f;
      }
      else {
        FUN_20101dc4(0);
        DAT_2080857c = 0xd8;
        DAT_20808580 = 0x57;
      }
      if (iVar1 == 0) {
        iVar1 = FUN_2013276c(1,param_1);
      }
    }
  }
  return iVar1;
}


// ===== FUN_20132ccc @ 20132ccc (428 bytes)

void FUN_20132ccc(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1c;
  
  FUN_201340a4();
  FUN_201342b4();
  FUN_20120d38();
  FUN_20133620();
  FUN_201376d0();
  FUN_20133484();
  iVar1 = FUN_201330a8(0);
  if (iVar1 == 0) {
    local_20 = 4;
    local_1f = 1;
    local_1c = 0;
    iVar1 = FUN_201179c0(0,&local_20,FUN_20132320);
    if ((iVar1 == 0) && (iVar1 = FUN_20132504(0), iVar1 == 0)) {
      iVar1 = FUN_201325e8(0);
      DAT_20808574 = 0x58;
      DAT_20808578 = 0x20;
      if (iVar1 == 0) {
        iVar1 = FUN_2013304c(0);
      }
    }
  }
  else {
    iVar1 = 7;
  }
  iVar2 = FUN_201330a8(1);
  if (iVar2 != 0) {
    iVar1 = 7;
  }
  DataMemoryBarrier(2);
  if (iVar1 == 0) {
    local_20 = 6;
    local_1f = 0;
    local_1c = FUN_2013249c(1,0);
    iVar1 = FUN_201179c0(1,&local_20,FUN_20132320);
    if ((iVar1 == 0) && (iVar1 = FUN_20132504(1,0), iVar1 == 0)) {
      iVar1 = FUN_201325e8(1,0);
      FUN_20101dc4(0,1);
      DAT_2080857c = 0x58;
      DAT_20808580 = 0x20;
      if ((iVar1 == 0) &&
         (((iVar1 = FUN_2013304c(1), iVar1 == 0 && (iVar1 = FUN_2013276c(0), iVar1 == 0)) &&
          (iVar1 = FUN_2013276c(1,0), iVar1 == 0)))) {
        FUN_20130188(0);
        FUN_20132b58(0);
        FUN_20132b58(1);
      }
    }
  }
  FUN_20132b94(0);
  FUN_20132b94(1);
  return;
}


// ===== FUN_20132e78 @ 20132e78 (88 bytes)

undefined * FUN_20132e78(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = 0xbb800;
    break;
  case 1:
    iVar1 = 0x177000;
    break;
  case 2:
    return &DAT_605048a0;
  case 3:
    iVar1 = 0x232800;
    break;
  case 4:
    return (undefined *)0x60000000;
  case 5:
    iVar1 = 0x2ee000;
    break;
  default:
    return (undefined *)0x0;
  }
  return (undefined *)(iVar1 + 0x60000000);
}


// ===== FUN_20132f10 @ 20132f10 (8 bytes)

void FUN_20132f10(void)

{
  FUN_20101030(&DAT_600bb800);
  return;
}


// ===== FUN_20132f18 @ 20132f18 (8 bytes)

void FUN_20132f18(void)

{
  FUN_20101030(&DAT_605048a0);
  return;
}


// ===== FUN_20132f20 @ 20132f20 (8 bytes)

void FUN_20132f20(void)

{
  FUN_20101030(&DAT_60177000);
  return;
}


// ===== FUN_20132f28 @ 20132f28 (8 bytes)

void FUN_20132f28(void)

{
  FUN_20101030(0x60000000);
  return;
}


// ===== FUN_20132f30 @ 20132f30 (8 bytes)

void FUN_20132f30(void)

{
  FUN_20101030(&DAT_60232800);
  return;
}


// ===== FUN_20132f38 @ 20132f38 (12 bytes)

void FUN_20132f38(void)

{
  FUN_20101030(&DAT_602ee000,0x11300);
  return;
}


// ===== FUN_20132f44 @ 20132f44 (16 bytes)

void FUN_20132f44(int param_1)

{
  *(undefined4 *)(&DAT_208f4d80 + param_1 * 4) = 1;
  return;
}


// ===== FUN_20132f6c @ 20132f6c (8 bytes)

undefined * FUN_20132f6c(void)

{
  return &DAT_605c0c60;
}


// ===== FUN_20132f74 @ 20132f74 (8 bytes)

undefined * FUN_20132f74(void)

{
  return &DAT_605c00a0;
}


// ===== FUN_20132f7c @ 20132f7c (8 bytes)

undefined * FUN_20132f7c(void)

{
  return &DAT_605c0780;
}


// ===== FUN_20132f84 @ 20132f84 (40 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552e4) */
/* WARNING: Removing unreachable block (ram,0x201552ea) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */

undefined4 * FUN_20132f84(void)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  memclr(0x60000000,0x2ff300);
  puVar1 = (undefined4 *)&DAT_605048a0;
  bVar3 = true;
  uVar2 = 0xdc3a0;
  do {
    if (bVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1 = puVar1 + 8;
      bVar3 = 0x1f < uVar2;
      uVar2 = uVar2 - 0x20;
    }
  } while (bVar3);
  return puVar1;
}


// ===== FUN_20132fe0 @ 20132fe0 (48 bytes)

int FUN_20132fe0(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20133014 @ 20133014 (56 bytes)

void FUN_20133014(void)

{
  thunk_FUN_20132fe0(&DAT_208f4db8);
  DAT_208085a4 = DAT_208085a4 + 1;
  if (DAT_2080859c != 0) {
    DAT_2080859c = DAT_2080859c + -1;
  }
  return;
}


// ===== FUN_2013304c @ 2013304c (108 bytes)

undefined4 FUN_2013304c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f58 = 3;
  DAT_20907f5c = 0;
  DAT_20907f60 = 0;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      FUN_201183b0(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_20133068 @ 20133068 (20 bytes)

undefined4 FUN_20133068(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f5c = FUN_20133014;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      FUN_201183b0(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_2013307c @ 2013307c (20 bytes)

undefined4 FUN_2013307c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f5c = 0;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      FUN_201183b0(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_20133090 @ 20133090 (24 bytes)

void FUN_20133090(int param_1)

{
  DAT_2080859c = param_1;
  do {
  } while (param_1 != 0);
  return;
}


// ===== FUN_201330a8 @ 201330a8 (44 bytes)

int FUN_201330a8(void)

{
  int iVar1;
  
  iVar1 = FUN_2014f1a8(0,&DAT_203a706c);
  if (0 < iVar1) {
    FUN_2011775c(0x4e);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_201330d4 @ 201330d4 (108 bytes)

void FUN_201330d4(void)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)FUN_20132f74();
  thunk_FUN_20132fe0(&DAT_208f4dc0);
  DAT_208085a4 = DAT_208085a4 + 1;
  if ((((byte)DAT_20808a84 & 0x10) != 0) && (cVar1 = *pcVar2, cVar1 != '\0')) {
    pcVar2[0x1a8] = cVar1;
    pcVar2[0x1a9] = cVar1;
  }
  FUN_201342ec(pcVar2);
  FUN_20137d98();
  FUN_2011f1ac(2);
  FUN_2011f7b4(2);
  FUN_20137d84();
  return;
}

